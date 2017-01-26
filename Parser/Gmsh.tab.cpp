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
     tPi = 264,
     tMPI_Rank = 265,
     tMPI_Size = 266,
     tEuclidian = 267,
     tCoordinates = 268,
     tTestLevel = 269,
     tExp = 270,
     tLog = 271,
     tLog10 = 272,
     tSqrt = 273,
     tSin = 274,
     tAsin = 275,
     tCos = 276,
     tAcos = 277,
     tTan = 278,
     tRand = 279,
     tAtan = 280,
     tAtan2 = 281,
     tSinh = 282,
     tCosh = 283,
     tTanh = 284,
     tFabs = 285,
     tFloor = 286,
     tCeil = 287,
     tRound = 288,
     tFmod = 289,
     tModulo = 290,
     tHypot = 291,
     tList = 292,
     tLinSpace = 293,
     tLogSpace = 294,
     tListFromFile = 295,
     tCatenary = 296,
     tPrintf = 297,
     tError = 298,
     tStr = 299,
     tSprintf = 300,
     tStrCat = 301,
     tStrPrefix = 302,
     tStrRelative = 303,
     tStrReplace = 304,
     tAbsolutePath = 305,
     tDirName = 306,
     tStrSub = 307,
     tStrLen = 308,
     tFind = 309,
     tStrFind = 310,
     tStrCmp = 311,
     tStrChoice = 312,
     tUpperCase = 313,
     tLowerCase = 314,
     tLowerCaseIn = 315,
     tTextAttributes = 316,
     tBoundingBox = 317,
     tDraw = 318,
     tSetChanged = 319,
     tToday = 320,
     tFixRelativePath = 321,
     tCurrentDirectory = 322,
     tSyncModel = 323,
     tNewModel = 324,
     tOnelabAction = 325,
     tOnelabRun = 326,
     tCpu = 327,
     tMemory = 328,
     tTotalMemory = 329,
     tCreateTopology = 330,
     tCreateTopologyNoHoles = 331,
     tDistanceFunction = 332,
     tDefineConstant = 333,
     tUndefineConstant = 334,
     tDefineNumber = 335,
     tDefineString = 336,
     tSetNumber = 337,
     tSetString = 338,
     tPoint = 339,
     tCircle = 340,
     tEllipse = 341,
     tLine = 342,
     tSphere = 343,
     tPolarSphere = 344,
     tSurface = 345,
     tSpline = 346,
     tVolume = 347,
     tCharacteristic = 348,
     tLength = 349,
     tParametric = 350,
     tElliptic = 351,
     tRefineMesh = 352,
     tAdaptMesh = 353,
     tRelocateMesh = 354,
     tSetFactory = 355,
     tThruSections = 356,
     tPlane = 357,
     tRuled = 358,
     tTransfinite = 359,
     tComplex = 360,
     tPhysical = 361,
     tCompound = 362,
     tPeriodic = 363,
     tUsing = 364,
     tPlugin = 365,
     tDegenerated = 366,
     tRecursive = 367,
     tRotate = 368,
     tTranslate = 369,
     tSymmetry = 370,
     tDilate = 371,
     tExtrude = 372,
     tLevelset = 373,
     tAffine = 374,
     tBooleanUnion = 375,
     tBooleanIntersection = 376,
     tBooleanSubtraction = 377,
     tRecombine = 378,
     tSmoother = 379,
     tSplit = 380,
     tDelete = 381,
     tCoherence = 382,
     tIntersect = 383,
     tMeshAlgorithm = 384,
     tReverse = 385,
     tLayers = 386,
     tScaleLast = 387,
     tHole = 388,
     tAlias = 389,
     tAliasWithOptions = 390,
     tCopyOptions = 391,
     tQuadTriAddVerts = 392,
     tQuadTriNoNewVerts = 393,
     tQuadTriSngl = 394,
     tQuadTriDbl = 395,
     tRecombLaterals = 396,
     tTransfQuadTri = 397,
     tText2D = 398,
     tText3D = 399,
     tInterpolationScheme = 400,
     tTime = 401,
     tCombine = 402,
     tBSpline = 403,
     tBezier = 404,
     tNurbs = 405,
     tNurbsOrder = 406,
     tNurbsKnots = 407,
     tColor = 408,
     tColorTable = 409,
     tFor = 410,
     tIn = 411,
     tEndFor = 412,
     tIf = 413,
     tElseIf = 414,
     tElse = 415,
     tEndIf = 416,
     tExit = 417,
     tAbort = 418,
     tField = 419,
     tReturn = 420,
     tCall = 421,
     tSlide = 422,
     tMacro = 423,
     tShow = 424,
     tHide = 425,
     tGetValue = 426,
     tGetStringValue = 427,
     tGetEnv = 428,
     tGetString = 429,
     tGetNumber = 430,
     tHomology = 431,
     tCohomology = 432,
     tBetti = 433,
     tExists = 434,
     tFileExists = 435,
     tGMSH_MAJOR_VERSION = 436,
     tGMSH_MINOR_VERSION = 437,
     tGMSH_PATCH_VERSION = 438,
     tGmshExecutableName = 439,
     tSetPartition = 440,
     tNameToString = 441,
     tStringToName = 442,
     tAFFECTDIVIDE = 443,
     tAFFECTTIMES = 444,
     tAFFECTMINUS = 445,
     tAFFECTPLUS = 446,
     tOR = 447,
     tAND = 448,
     tNOTEQUAL = 449,
     tEQUAL = 450,
     tGREATEROREQUAL = 451,
     tLESSOREQUAL = 452,
     UNARYPREC = 453,
     tMINUSMINUS = 454,
     tPLUSPLUS = 455
   };
#endif
/* Tokens.  */
#define tDOUBLE 258
#define tSTRING 259
#define tBIGSTR 260
#define tEND 261
#define tAFFECT 262
#define tDOTS 263
#define tPi 264
#define tMPI_Rank 265
#define tMPI_Size 266
#define tEuclidian 267
#define tCoordinates 268
#define tTestLevel 269
#define tExp 270
#define tLog 271
#define tLog10 272
#define tSqrt 273
#define tSin 274
#define tAsin 275
#define tCos 276
#define tAcos 277
#define tTan 278
#define tRand 279
#define tAtan 280
#define tAtan2 281
#define tSinh 282
#define tCosh 283
#define tTanh 284
#define tFabs 285
#define tFloor 286
#define tCeil 287
#define tRound 288
#define tFmod 289
#define tModulo 290
#define tHypot 291
#define tList 292
#define tLinSpace 293
#define tLogSpace 294
#define tListFromFile 295
#define tCatenary 296
#define tPrintf 297
#define tError 298
#define tStr 299
#define tSprintf 300
#define tStrCat 301
#define tStrPrefix 302
#define tStrRelative 303
#define tStrReplace 304
#define tAbsolutePath 305
#define tDirName 306
#define tStrSub 307
#define tStrLen 308
#define tFind 309
#define tStrFind 310
#define tStrCmp 311
#define tStrChoice 312
#define tUpperCase 313
#define tLowerCase 314
#define tLowerCaseIn 315
#define tTextAttributes 316
#define tBoundingBox 317
#define tDraw 318
#define tSetChanged 319
#define tToday 320
#define tFixRelativePath 321
#define tCurrentDirectory 322
#define tSyncModel 323
#define tNewModel 324
#define tOnelabAction 325
#define tOnelabRun 326
#define tCpu 327
#define tMemory 328
#define tTotalMemory 329
#define tCreateTopology 330
#define tCreateTopologyNoHoles 331
#define tDistanceFunction 332
#define tDefineConstant 333
#define tUndefineConstant 334
#define tDefineNumber 335
#define tDefineString 336
#define tSetNumber 337
#define tSetString 338
#define tPoint 339
#define tCircle 340
#define tEllipse 341
#define tLine 342
#define tSphere 343
#define tPolarSphere 344
#define tSurface 345
#define tSpline 346
#define tVolume 347
#define tCharacteristic 348
#define tLength 349
#define tParametric 350
#define tElliptic 351
#define tRefineMesh 352
#define tAdaptMesh 353
#define tRelocateMesh 354
#define tSetFactory 355
#define tThruSections 356
#define tPlane 357
#define tRuled 358
#define tTransfinite 359
#define tComplex 360
#define tPhysical 361
#define tCompound 362
#define tPeriodic 363
#define tUsing 364
#define tPlugin 365
#define tDegenerated 366
#define tRecursive 367
#define tRotate 368
#define tTranslate 369
#define tSymmetry 370
#define tDilate 371
#define tExtrude 372
#define tLevelset 373
#define tAffine 374
#define tBooleanUnion 375
#define tBooleanIntersection 376
#define tBooleanSubtraction 377
#define tRecombine 378
#define tSmoother 379
#define tSplit 380
#define tDelete 381
#define tCoherence 382
#define tIntersect 383
#define tMeshAlgorithm 384
#define tReverse 385
#define tLayers 386
#define tScaleLast 387
#define tHole 388
#define tAlias 389
#define tAliasWithOptions 390
#define tCopyOptions 391
#define tQuadTriAddVerts 392
#define tQuadTriNoNewVerts 393
#define tQuadTriSngl 394
#define tQuadTriDbl 395
#define tRecombLaterals 396
#define tTransfQuadTri 397
#define tText2D 398
#define tText3D 399
#define tInterpolationScheme 400
#define tTime 401
#define tCombine 402
#define tBSpline 403
#define tBezier 404
#define tNurbs 405
#define tNurbsOrder 406
#define tNurbsKnots 407
#define tColor 408
#define tColorTable 409
#define tFor 410
#define tIn 411
#define tEndFor 412
#define tIf 413
#define tElseIf 414
#define tElse 415
#define tEndIf 416
#define tExit 417
#define tAbort 418
#define tField 419
#define tReturn 420
#define tCall 421
#define tSlide 422
#define tMacro 423
#define tShow 424
#define tHide 425
#define tGetValue 426
#define tGetStringValue 427
#define tGetEnv 428
#define tGetString 429
#define tGetNumber 430
#define tHomology 431
#define tCohomology 432
#define tBetti 433
#define tExists 434
#define tFileExists 435
#define tGMSH_MAJOR_VERSION 436
#define tGMSH_MINOR_VERSION 437
#define tGMSH_PATCH_VERSION 438
#define tGmshExecutableName 439
#define tSetPartition 440
#define tNameToString 441
#define tStringToName 442
#define tAFFECTDIVIDE 443
#define tAFFECTTIMES 444
#define tAFFECTMINUS 445
#define tAFFECTPLUS 446
#define tOR 447
#define tAND 448
#define tNOTEQUAL 449
#define tEQUAL 450
#define tGREATEROREQUAL 451
#define tLESSOREQUAL 452
#define UNARYPREC 453
#define tMINUSMINUS 454
#define tPLUSPLUS 455




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
#include "GModelIO_OCC.h"
#include "Geo.h"
#include "GeoInterpolation.h"
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


// Global parser variables
std::string gmsh_yyname;
int gmsh_yyerrorstate = 0;
int gmsh_yyviewindex = 0;
std::map<std::string, gmsh_yysymbol> gmsh_yysymbols;
std::map<std::string, std::vector<std::string> > gmsh_yystringsymbols;

// Static parser variables (accessible only in this file)
#if defined(HAVE_POST)
static PViewDataList *ViewData;
#endif
static std::vector<double> ViewCoord;
static std::vector<double> *ViewValueList = 0;
static int *ViewNumList = 0;
static ExtrudeParams extr;
static gmshSurface *myGmshSurface = 0;
#define MAX_RECUR_TESTS 100
static int statusImbricatedTests[MAX_RECUR_TESTS];
#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0, ImbricatedTest = 0;
static gmshfpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static std::string LoopControlVariablesNameTab[MAX_RECUR_LOOPS];
static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;
static std::string factory;

void yyerror(const char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
void skip_until_test(const char *skip, const char *until,
                     const char *until2, int l_until2_sub, int *type_until2);
void assignVariable(const std::string &name, int index, int assignType,
                    double value);
void assignVariables(const std::string &name, List_T *indices, int assignType,
                     List_T *values);
void incrementVariable(const std::string &name, int index, double value);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
void PrintParserSymbols(std::vector<std::string> &vec);
fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list);

void addPeriodicEdge(int, int, const std::vector<double>&);
void addPeriodicFace(int, int, const std::map<int,int>&);
void addPeriodicFace(int, int, const std::vector<double>&);
void computeAffineTransformation(SPoint3&, SPoint3&, double, SPoint3&, std::vector<double>&);
char  *strsave(char *ptr);

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
#line 117 "Gmsh.y"
{
  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
}
/* Line 193 of yacc.c.  */
#line 630 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 643 "Gmsh.tab.cpp"

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
#define YYLAST   13306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  221
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  104
/* YYNRULES -- Number of rules.  */
#define YYNRULES  575
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2075

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   455

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   206,     2,   216,     2,   205,     2,     2,
     211,   212,   203,   201,   217,   202,   215,   204,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     197,     2,   198,   192,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   213,     2,   214,   210,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   218,     2,   219,   220,     2,     2,     2,
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
     185,   186,   187,   188,   189,   190,   191,   193,   194,   195,
     196,   199,   200,   207,   208,   209
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    48,    50,    53,    59,    65,    73,
      81,    89,    99,   106,   113,   120,   129,   130,   133,   136,
     139,   142,   145,   147,   151,   153,   157,   158,   159,   170,
     172,   176,   177,   191,   193,   197,   198,   214,   223,   238,
     239,   246,   248,   250,   252,   254,   256,   258,   260,   262,
     264,   266,   268,   274,   280,   288,   296,   301,   305,   312,
     319,   327,   335,   342,   349,   359,   369,   376,   383,   391,
     399,   406,   413,   418,   427,   436,   446,   456,   466,   476,
     485,   494,   504,   514,   524,   534,   541,   551,   558,   568,
     574,   583,   592,   604,   611,   621,   627,   635,   645,   655,
     667,   675,   685,   695,   696,   698,   699,   703,   709,   710,
     720,   721,   733,   734,   746,   752,   753,   763,   764,   768,
     772,   778,   784,   785,   788,   792,   798,   802,   803,   806,
     810,   814,   818,   824,   826,   828,   832,   834,   836,   840,
     842,   844,   848,   850,   852,   856,   857,   863,   864,   867,
     873,   881,   890,   897,   905,   910,   918,   927,   936,   944,
     952,   964,   973,   978,   987,   996,  1005,  1015,  1019,  1024,
    1035,  1043,  1051,  1060,  1065,  1074,  1087,  1096,  1105,  1113,
    1123,  1128,  1137,  1146,  1152,  1164,  1170,  1180,  1190,  1195,
    1205,  1215,  1217,  1219,  1220,  1223,  1230,  1237,  1244,  1251,
    1260,  1271,  1286,  1303,  1316,  1325,  1334,  1341,  1356,  1361,
    1368,  1375,  1379,  1384,  1390,  1397,  1403,  1407,  1411,  1416,
    1422,  1427,  1433,  1437,  1443,  1451,  1459,  1463,  1471,  1475,
    1478,  1481,  1484,  1487,  1490,  1506,  1509,  1512,  1515,  1518,
    1521,  1538,  1550,  1557,  1566,  1575,  1586,  1588,  1591,  1594,
    1596,  1600,  1604,  1609,  1614,  1616,  1618,  1624,  1636,  1650,
    1651,  1659,  1660,  1674,  1675,  1691,  1692,  1699,  1708,  1717,
    1726,  1739,  1752,  1765,  1780,  1795,  1810,  1811,  1824,  1825,
    1838,  1839,  1852,  1853,  1870,  1871,  1888,  1889,  1906,  1907,
    1926,  1927,  1946,  1947,  1966,  1968,  1971,  1977,  1985,  1995,
    1998,  2001,  2005,  2008,  2012,  2015,  2019,  2022,  2026,  2029,
    2033,  2043,  2050,  2052,  2054,  2056,  2057,  2060,  2064,  2074,
    2075,  2079,  2080,  2082,  2083,  2086,  2087,  2090,  2091,  2094,
    2102,  2109,  2118,  2124,  2128,  2137,  2143,  2148,  2155,  2167,
    2179,  2198,  2217,  2230,  2243,  2256,  2267,  2278,  2289,  2300,
    2311,  2316,  2321,  2326,  2331,  2336,  2339,  2343,  2350,  2352,
    2354,  2356,  2359,  2365,  2373,  2384,  2386,  2390,  2393,  2396,
    2399,  2403,  2407,  2411,  2415,  2419,  2423,  2427,  2431,  2435,
    2439,  2443,  2447,  2451,  2455,  2461,  2466,  2471,  2476,  2481,
    2486,  2491,  2496,  2501,  2506,  2511,  2518,  2523,  2528,  2533,
    2538,  2543,  2548,  2553,  2560,  2567,  2574,  2579,  2581,  2583,
    2585,  2587,  2589,  2591,  2593,  2595,  2597,  2599,  2601,  2602,
    2609,  2614,  2621,  2623,  2628,  2633,  2638,  2643,  2648,  2653,
    2658,  2661,  2667,  2673,  2679,  2685,  2689,  2696,  2701,  2709,
    2716,  2723,  2730,  2735,  2742,  2747,  2749,  2752,  2755,  2759,
    2763,  2775,  2785,  2793,  2801,  2803,  2807,  2809,  2811,  2814,
    2818,  2823,  2829,  2831,  2833,  2836,  2840,  2844,  2850,  2855,
    2858,  2861,  2864,  2867,  2871,  2875,  2879,  2883,  2889,  2895,
    2901,  2907,  2924,  2941,  2958,  2975,  2977,  2979,  2981,  2985,
    2989,  2994,  2999,  3004,  3011,  3018,  3025,  3032,  3041,  3050,
    3055,  3070,  3072,  3074,  3078,  3082,  3092,  3100,  3102,  3108,
    3112,  3119,  3121,  3125,  3127,  3129,  3134,  3139,  3144,  3149,
    3153,  3160,  3162,  3167,  3169,  3171,  3173,  3178,  3185,  3190,
    3197,  3202,  3207,  3212,  3221,  3226,  3231,  3236,  3241,  3250,
    3259,  3266,  3271,  3278,  3283,  3285,  3290,  3295,  3296,  3303,
    3305,  3309,  3315,  3321,  3323,  3325
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     222,     0,    -1,   223,    -1,     1,     6,    -1,    -1,   223,
     224,    -1,   227,    -1,   226,    -1,   247,    -1,   266,    -1,
     267,    -1,   271,    -1,   272,    -1,   273,    -1,   274,    -1,
     278,    -1,   296,    -1,   302,    -1,   303,    -1,   277,    -1,
     276,    -1,   275,    -1,   270,    -1,   305,    -1,   198,    -1,
     198,   198,    -1,    42,   211,   319,   212,     6,    -1,    43,
     211,   319,   212,     6,    -1,    42,   211,   319,   212,   225,
     319,     6,    -1,    42,   211,   319,   217,   315,   212,     6,
      -1,    43,   211,   319,   217,   315,   212,     6,    -1,    42,
     211,   319,   217,   315,   212,   225,   319,     6,    -1,     4,
     319,   218,   228,   219,     6,    -1,   134,     4,   213,   306,
     214,     6,    -1,   135,     4,   213,   306,   214,     6,    -1,
     136,     4,   213,   306,   217,   306,   214,     6,    -1,    -1,
     228,   231,    -1,   228,   235,    -1,   228,   238,    -1,   228,
     240,    -1,   228,   241,    -1,   306,    -1,   229,   217,   306,
      -1,   306,    -1,   230,   217,   306,    -1,    -1,    -1,     4,
     232,   211,   229,   212,   233,   218,   230,   219,     6,    -1,
     319,    -1,   234,   217,   319,    -1,    -1,   143,   211,   306,
     217,   306,   217,   306,   212,   236,   218,   234,   219,     6,
      -1,   319,    -1,   237,   217,   319,    -1,    -1,   144,   211,
     306,   217,   306,   217,   306,   217,   306,   212,   239,   218,
     237,   219,     6,    -1,   145,   218,   311,   219,   218,   311,
     219,     6,    -1,   145,   218,   311,   219,   218,   311,   219,
     218,   311,   219,   218,   311,   219,     6,    -1,    -1,   146,
     242,   218,   230,   219,     6,    -1,     7,    -1,   191,    -1,
     190,    -1,   189,    -1,   188,    -1,   209,    -1,   208,    -1,
     211,    -1,   213,    -1,   212,    -1,   214,    -1,    78,   213,
     249,   214,     6,    -1,    79,   213,   254,   214,     6,    -1,
      82,   245,   320,   217,   306,   246,     6,    -1,    83,   245,
     324,   217,   320,   246,     6,    -1,   324,   243,   312,     6,
      -1,   324,   244,     6,    -1,     4,   213,   214,   243,   312,
       6,    -1,   323,   213,   214,   243,   312,     6,    -1,     4,
     213,   306,   214,   243,   306,     6,    -1,   323,   213,   306,
     214,   243,   306,     6,    -1,     4,   213,   306,   214,   244,
       6,    -1,   323,   213,   306,   214,   244,     6,    -1,     4,
     245,   218,   315,   219,   246,   243,   312,     6,    -1,   323,
     245,   218,   315,   219,   246,   243,   312,     6,    -1,     4,
     211,   212,   243,   312,     6,    -1,   323,   211,   212,   243,
     312,     6,    -1,     4,   211,   306,   212,   243,   306,     6,
      -1,   323,   211,   306,   212,   243,   306,     6,    -1,     4,
     211,   306,   212,   244,     6,    -1,   323,   211,   306,   212,
     244,     6,    -1,   324,     7,   320,     6,    -1,     4,   213,
     214,     7,    44,   245,   246,     6,    -1,   323,   213,   214,
       7,    44,   245,   246,     6,    -1,     4,   213,   214,     7,
      44,   245,   322,   246,     6,    -1,   323,   213,   214,     7,
      44,   245,   322,   246,     6,    -1,     4,   213,   214,   191,
      44,   245,   322,   246,     6,    -1,   323,   213,   214,   191,
      44,   245,   322,   246,     6,    -1,     4,   211,   212,     7,
      44,   245,   246,     6,    -1,   323,   211,   212,     7,    44,
     245,   246,     6,    -1,     4,   211,   212,     7,    44,   245,
     322,   246,     6,    -1,   323,   211,   212,     7,    44,   245,
     322,   246,     6,    -1,     4,   211,   212,   191,    44,   245,
     322,   246,     6,    -1,   323,   211,   212,   191,    44,   245,
     322,   246,     6,    -1,     4,   215,     4,     7,   320,     6,
      -1,     4,   213,   306,   214,   215,     4,     7,   320,     6,
      -1,     4,   215,     4,   243,   306,     6,    -1,     4,   213,
     306,   214,   215,     4,   243,   306,     6,    -1,     4,   215,
       4,   244,     6,    -1,     4,   213,   306,   214,   215,     4,
     244,     6,    -1,     4,   215,   153,   215,     4,     7,   316,
       6,    -1,     4,   213,   306,   214,   215,   153,   215,     4,
       7,   316,     6,    -1,     4,   215,   154,     7,   317,     6,
      -1,     4,   213,   306,   214,   215,   154,     7,   317,     6,
      -1,     4,   164,     7,   306,     6,    -1,   164,   213,   306,
     214,     7,     4,     6,    -1,   164,   213,   306,   214,   215,
       4,     7,   306,     6,    -1,   164,   213,   306,   214,   215,
       4,     7,   320,     6,    -1,   164,   213,   306,   214,   215,
       4,     7,   218,   315,   219,     6,    -1,   164,   213,   306,
     214,   215,     4,     6,    -1,   110,   211,     4,   212,   215,
       4,     7,   306,     6,    -1,   110,   211,     4,   212,   215,
       4,     7,   320,     6,    -1,    -1,   217,    -1,    -1,   249,
     248,   324,    -1,   249,   248,   324,     7,   306,    -1,    -1,
     249,   248,   324,     7,   218,   312,   250,   256,   219,    -1,
      -1,   249,   248,   324,   213,   214,     7,   218,   312,   251,
     256,   219,    -1,    -1,   249,   248,   324,   211,   212,     7,
     218,   312,   252,   256,   219,    -1,   249,   248,   324,     7,
     320,    -1,    -1,   249,   248,   324,     7,   218,   320,   253,
     258,   219,    -1,    -1,   254,   248,   319,    -1,   306,     7,
     320,    -1,   255,   217,   306,     7,   320,    -1,   314,     7,
     324,   211,   212,    -1,    -1,   256,   257,    -1,   217,     4,
     312,    -1,   217,     4,   218,   255,   219,    -1,   217,     4,
     320,    -1,    -1,   258,   259,    -1,   217,     4,   306,    -1,
     217,     4,   320,    -1,   217,   168,   320,    -1,   217,     4,
     218,   322,   219,    -1,   306,    -1,   320,    -1,   320,   217,
     306,    -1,   306,    -1,   320,    -1,   320,   217,   306,    -1,
     306,    -1,   320,    -1,   320,   217,   306,    -1,   306,    -1,
     320,    -1,   320,   217,   306,    -1,    -1,   156,    88,   218,
     306,   219,    -1,    -1,   102,   309,    -1,   100,   211,   319,
     212,     6,    -1,    84,   211,   306,   212,     7,   309,     6,
      -1,   106,    84,   211,   260,   212,   243,   312,     6,    -1,
      93,    94,   312,     7,   306,     6,    -1,    87,   211,   306,
     212,     7,   312,     6,    -1,   111,    87,   312,     6,    -1,
      91,   211,   306,   212,     7,   312,     6,    -1,    85,   211,
     306,   212,     7,   312,   265,     6,    -1,    86,   211,   306,
     212,     7,   312,   265,     6,    -1,   148,   211,   306,   212,
       7,   312,     6,    -1,   149,   211,   306,   212,     7,   312,
       6,    -1,   150,   211,   306,   212,     7,   312,   152,   312,
     151,   306,     6,    -1,    87,     4,   211,   306,   212,     7,
     312,     6,    -1,   107,    87,   312,     6,    -1,   107,    87,
     211,   306,   212,     7,   312,     6,    -1,   106,    87,   211,
     261,   212,   243,   312,     6,    -1,   102,    90,   211,   306,
     212,     7,   312,     6,    -1,   103,    90,   211,   306,   212,
       7,   312,   264,     6,    -1,    12,    13,     6,    -1,    13,
      90,   306,     6,    -1,    95,    90,   211,   306,   212,     7,
       5,     5,     5,     6,    -1,    88,   211,   306,   212,     7,
     312,     6,    -1,    89,   211,   306,   212,     7,   312,     6,
      -1,    90,     4,   211,   306,   212,     7,   312,     6,    -1,
     107,    90,   312,     6,    -1,   107,    90,   211,   306,   212,
       7,   312,     6,    -1,   107,    90,   211,   306,   212,     7,
     312,     4,   218,   311,   219,     6,    -1,   106,    90,   211,
     262,   212,   243,   312,     6,    -1,   105,    92,   211,   306,
     212,     7,   312,     6,    -1,    92,   211,   306,   212,     7,
     312,     6,    -1,   101,   211,   306,   212,     7,   218,   311,
     219,     6,    -1,   107,    92,   312,     6,    -1,   107,    92,
     211,   306,   212,     7,   312,     6,    -1,   106,    92,   211,
     263,   212,   243,   312,     6,    -1,   114,   309,   218,   268,
     219,    -1,   113,   218,   309,   217,   309,   217,   306,   219,
     218,   268,   219,    -1,   115,   309,   218,   268,   219,    -1,
     116,   218,   309,   217,   306,   219,   218,   268,   219,    -1,
     116,   218,   309,   217,   309,   219,   218,   268,   219,    -1,
       4,   218,   268,   219,    -1,   128,    87,   218,   315,   219,
      90,   218,   306,   219,    -1,   125,    87,   211,   306,   212,
     218,   315,   219,     6,    -1,   269,    -1,   267,    -1,    -1,
     269,   266,    -1,   269,    84,   218,   315,   219,     6,    -1,
     269,    87,   218,   315,   219,     6,    -1,   269,    90,   218,
     315,   219,     6,    -1,   269,    92,   218,   315,   219,     6,
      -1,   118,   102,   211,   306,   212,     7,   312,     6,    -1,
     118,    84,   211,   306,   212,     7,   218,   311,   219,     6,
      -1,   118,   102,   211,   306,   212,     7,   218,   309,   217,
     309,   217,   315,   219,     6,    -1,   118,   102,   211,   306,
     212,     7,   218,   309,   217,   309,   217,   309,   217,   315,
     219,     6,    -1,   118,    88,   211,   306,   212,     7,   218,
     309,   217,   315,   219,     6,    -1,   118,     4,   211,   306,
     212,     7,   312,     6,    -1,   118,     4,   211,   306,   212,
       7,     5,     6,    -1,   118,     4,   218,   306,   219,     6,
      -1,   118,     4,   211,   306,   212,     7,   218,   309,   217,
     309,   217,   315,   219,     6,    -1,   126,   218,   269,   219,
      -1,   126,   164,   213,   306,   214,     6,    -1,   126,     4,
     213,   306,   214,     6,    -1,   126,   324,     6,    -1,   126,
       4,     4,     6,    -1,   153,   316,   218,   269,   219,    -1,
     112,   153,   316,   218,   269,   219,    -1,   185,   306,   218,
     269,   219,    -1,   169,     5,     6,    -1,   170,     5,     6,
      -1,   169,   218,   269,   219,    -1,   112,   169,   218,   269,
     219,    -1,   170,   218,   269,   219,    -1,   112,   170,   218,
     269,   219,    -1,     4,   320,     6,    -1,    71,   211,   322,
     212,     6,    -1,     4,     4,   213,   306,   214,   319,     6,
      -1,     4,     4,     4,   213,   306,   214,     6,    -1,     4,
     306,     6,    -1,   110,   211,     4,   212,   215,     4,     6,
      -1,   147,     4,     6,    -1,   162,     6,    -1,   163,     6,
      -1,    68,     6,    -1,    69,     6,    -1,    62,     6,    -1,
      62,   218,   306,   217,   306,   217,   306,   217,   306,   217,
     306,   217,   306,   219,     6,    -1,    63,     6,    -1,    64,
       6,    -1,    75,     6,    -1,    76,     6,    -1,    97,     6,
      -1,    98,   218,   315,   219,   218,   315,   219,   218,   311,
     219,   218,   306,   217,   306,   219,     6,    -1,   167,   211,
     218,   315,   219,   217,   320,   217,   320,   212,     6,    -1,
     155,   211,   306,     8,   306,   212,    -1,   155,   211,   306,
       8,   306,     8,   306,   212,    -1,   155,     4,   156,   218,
     306,     8,   306,   219,    -1,   155,     4,   156,   218,   306,
       8,   306,     8,   306,   219,    -1,   157,    -1,   168,     4,
      -1,   168,   320,    -1,   165,    -1,   166,   324,     6,    -1,
     166,   320,     6,    -1,   158,   211,   306,   212,    -1,   159,
     211,   306,   212,    -1,   160,    -1,   161,    -1,   117,   309,
     218,   269,   219,    -1,   117,   218,   309,   217,   309,   217,
     306,   219,   218,   269,   219,    -1,   117,   218,   309,   217,
     309,   217,   309,   217,   306,   219,   218,   269,   219,    -1,
      -1,   117,   309,   218,   269,   279,   292,   219,    -1,    -1,
     117,   218,   309,   217,   309,   217,   306,   219,   218,   269,
     280,   292,   219,    -1,    -1,   117,   218,   309,   217,   309,
     217,   309,   217,   306,   219,   218,   269,   281,   292,   219,
      -1,    -1,   117,   218,   269,   282,   292,   219,    -1,   117,
      84,   218,   306,   217,   309,   219,     6,    -1,   117,    87,
     218,   306,   217,   309,   219,     6,    -1,   117,    90,   218,
     306,   217,   309,   219,     6,    -1,   117,    84,   218,   306,
     217,   309,   217,   309,   217,   306,   219,     6,    -1,   117,
      87,   218,   306,   217,   309,   217,   309,   217,   306,   219,
       6,    -1,   117,    90,   218,   306,   217,   309,   217,   309,
     217,   306,   219,     6,    -1,   117,    84,   218,   306,   217,
     309,   217,   309,   217,   309,   217,   306,   219,     6,    -1,
     117,    87,   218,   306,   217,   309,   217,   309,   217,   309,
     217,   306,   219,     6,    -1,   117,    90,   218,   306,   217,
     309,   217,   309,   217,   309,   217,   306,   219,     6,    -1,
      -1,   117,    84,   218,   306,   217,   309,   219,   283,   218,
     292,   219,     6,    -1,    -1,   117,    87,   218,   306,   217,
     309,   219,   284,   218,   292,   219,     6,    -1,    -1,   117,
      90,   218,   306,   217,   309,   219,   285,   218,   292,   219,
       6,    -1,    -1,   117,    84,   218,   306,   217,   309,   217,
     309,   217,   306,   219,   286,   218,   292,   219,     6,    -1,
      -1,   117,    87,   218,   306,   217,   309,   217,   309,   217,
     306,   219,   287,   218,   292,   219,     6,    -1,    -1,   117,
      90,   218,   306,   217,   309,   217,   309,   217,   306,   219,
     288,   218,   292,   219,     6,    -1,    -1,   117,    84,   218,
     306,   217,   309,   217,   309,   217,   309,   217,   306,   219,
     289,   218,   292,   219,     6,    -1,    -1,   117,    87,   218,
     306,   217,   309,   217,   309,   217,   309,   217,   306,   219,
     290,   218,   292,   219,     6,    -1,    -1,   117,    90,   218,
     306,   217,   309,   217,   309,   217,   309,   217,   306,   219,
     291,   218,   292,   219,     6,    -1,   293,    -1,   292,   293,
      -1,   131,   218,   306,   219,     6,    -1,   131,   218,   312,
     217,   312,   219,     6,    -1,   131,   218,   312,   217,   312,
     217,   312,   219,     6,    -1,   132,     6,    -1,   123,     6,
      -1,   123,   306,     6,    -1,   139,     6,    -1,   139,   141,
       6,    -1,   140,     6,    -1,   140,   141,     6,    -1,   137,
       6,    -1,   137,   141,     6,    -1,   138,     6,    -1,   138,
     141,     6,    -1,   133,   211,   306,   212,     7,   312,   109,
     306,     6,    -1,   109,     4,   213,   306,   214,     6,    -1,
     120,    -1,   121,    -1,   122,    -1,    -1,   126,     6,    -1,
     126,   306,     6,    -1,   294,   218,   269,   295,   219,   218,
     269,   295,   219,    -1,    -1,   109,     4,   306,    -1,    -1,
       4,    -1,    -1,     7,   312,    -1,    -1,     7,   306,    -1,
      -1,   119,   312,    -1,   104,    87,   313,     7,   306,   297,
       6,    -1,   104,    90,   313,   299,   298,     6,    -1,    96,
      90,   218,   306,   219,     7,   312,     6,    -1,   104,    92,
     313,   299,     6,    -1,   142,   313,     6,    -1,   129,    90,
     218,   315,   219,     7,   306,     6,    -1,   123,    90,   313,
     300,     6,    -1,   123,    92,   313,     6,    -1,   124,    90,
     312,     7,   306,     6,    -1,   108,    87,   218,   315,   219,
       7,   218,   315,   219,   301,     6,    -1,   108,    90,   218,
     315,   219,     7,   218,   315,   219,   301,     6,    -1,   108,
      87,   218,   315,   219,     7,   218,   315,   219,   113,   218,
     309,   217,   309,   217,   306,   219,     6,    -1,   108,    90,
     218,   315,   219,     7,   218,   315,   219,   113,   218,   309,
     217,   309,   217,   306,   219,     6,    -1,   108,    87,   218,
     315,   219,     7,   218,   315,   219,   114,   309,     6,    -1,
     108,    90,   218,   315,   219,     7,   218,   315,   219,   114,
     309,     6,    -1,   108,    90,   306,   218,   315,   219,     7,
     306,   218,   315,   219,     6,    -1,    84,   218,   315,   219,
     156,    90,   218,   306,   219,     6,    -1,    87,   218,   315,
     219,   156,    90,   218,   306,   219,     6,    -1,    84,   218,
     315,   219,   156,    92,   218,   306,   219,     6,    -1,    87,
     218,   315,   219,   156,    92,   218,   306,   219,     6,    -1,
      90,   218,   315,   219,   156,    92,   218,   306,   219,     6,
      -1,   130,    90,   313,     6,    -1,   130,    87,   313,     6,
      -1,    99,    84,   313,     6,    -1,    99,    87,   313,     6,
      -1,    99,    90,   313,     6,    -1,   127,     6,    -1,   127,
       4,     6,    -1,   127,    84,   218,   315,   219,     6,    -1,
     176,    -1,   177,    -1,   178,    -1,   304,     6,    -1,   304,
     218,   312,   219,     6,    -1,   304,   218,   312,   217,   312,
     219,     6,    -1,   304,   211,   312,   212,   218,   312,   217,
     312,   219,     6,    -1,   307,    -1,   211,   306,   212,    -1,
     202,   306,    -1,   201,   306,    -1,   206,   306,    -1,   306,
     202,   306,    -1,   306,   201,   306,    -1,   306,   203,   306,
      -1,   306,   204,   306,    -1,   306,   205,   306,    -1,   306,
     210,   306,    -1,   306,   197,   306,    -1,   306,   198,   306,
      -1,   306,   200,   306,    -1,   306,   199,   306,    -1,   306,
     196,   306,    -1,   306,   195,   306,    -1,   306,   194,   306,
      -1,   306,   193,   306,    -1,   306,   192,   306,     8,   306,
      -1,    15,   245,   306,   246,    -1,    16,   245,   306,   246,
      -1,    17,   245,   306,   246,    -1,    18,   245,   306,   246,
      -1,    19,   245,   306,   246,    -1,    20,   245,   306,   246,
      -1,    21,   245,   306,   246,    -1,    22,   245,   306,   246,
      -1,    23,   245,   306,   246,    -1,    25,   245,   306,   246,
      -1,    26,   245,   306,   217,   306,   246,    -1,    27,   245,
     306,   246,    -1,    28,   245,   306,   246,    -1,    29,   245,
     306,   246,    -1,    30,   245,   306,   246,    -1,    31,   245,
     306,   246,    -1,    32,   245,   306,   246,    -1,    33,   245,
     306,   246,    -1,    34,   245,   306,   217,   306,   246,    -1,
      35,   245,   306,   217,   306,   246,    -1,    36,   245,   306,
     217,   306,   246,    -1,    24,   245,   306,   246,    -1,     3,
      -1,     9,    -1,    14,    -1,    10,    -1,    11,    -1,   181,
      -1,   182,    -1,   183,    -1,    72,    -1,    73,    -1,    74,
      -1,    -1,    80,   245,   306,   308,   256,   246,    -1,   175,
     245,   319,   246,    -1,   175,   245,   319,   217,   306,   246,
      -1,   324,    -1,     4,   213,   306,   214,    -1,     4,   211,
     306,   212,    -1,   323,   213,   306,   214,    -1,   323,   211,
     306,   212,    -1,   179,   211,   324,   212,    -1,   180,   211,
     320,   212,    -1,   216,   324,   245,   246,    -1,   324,   244,
      -1,     4,   213,   306,   214,   244,    -1,     4,   211,   306,
     212,   244,    -1,   323,   213,   306,   214,   244,    -1,   323,
     211,   306,   212,   244,    -1,     4,   215,     4,    -1,     4,
     213,   306,   214,   215,     4,    -1,     4,   215,     4,   244,
      -1,     4,   213,   306,   214,   215,     4,   244,    -1,   171,
     211,   319,   217,   306,   212,    -1,    54,   211,   312,   217,
     312,   212,    -1,    55,   245,   319,   217,   319,   246,    -1,
      53,   245,   319,   246,    -1,    56,   245,   319,   217,   319,
     246,    -1,    61,   211,   322,   212,    -1,   310,    -1,   202,
     309,    -1,   201,   309,    -1,   309,   202,   309,    -1,   309,
     201,   309,    -1,   218,   306,   217,   306,   217,   306,   217,
     306,   217,   306,   219,    -1,   218,   306,   217,   306,   217,
     306,   217,   306,   219,    -1,   218,   306,   217,   306,   217,
     306,   219,    -1,   211,   306,   217,   306,   217,   306,   212,
      -1,   312,    -1,   311,   217,   312,    -1,   306,    -1,   314,
      -1,   218,   219,    -1,   218,   315,   219,    -1,   202,   218,
     315,   219,    -1,   306,   203,   218,   315,   219,    -1,   312,
      -1,     5,    -1,   202,   314,    -1,   306,   203,   314,    -1,
     306,     8,   306,    -1,   306,     8,   306,     8,   306,    -1,
      84,   218,   306,   219,    -1,    84,     5,    -1,    87,     5,
      -1,    90,     5,    -1,    92,     5,    -1,   106,    84,     5,
      -1,   106,    87,     5,    -1,   106,    90,     5,    -1,   106,
      92,     5,    -1,   106,    84,   218,   315,   219,    -1,   106,
      87,   218,   315,   219,    -1,   106,    90,   218,   315,   219,
      -1,   106,    92,   218,   315,   219,    -1,    84,   156,    62,
     218,   306,   217,   306,   217,   306,   217,   306,   217,   306,
     217,   306,   219,    -1,    87,   156,    62,   218,   306,   217,
     306,   217,   306,   217,   306,   217,   306,   217,   306,   219,
      -1,    90,   156,    62,   218,   306,   217,   306,   217,   306,
     217,   306,   217,   306,   217,   306,   219,    -1,    92,   156,
      62,   218,   306,   217,   306,   217,   306,   217,   306,   217,
     306,   217,   306,   219,    -1,   267,    -1,   278,    -1,   296,
      -1,     4,   245,   246,    -1,   323,   245,   246,    -1,    37,
     213,   324,   214,    -1,    37,   213,   314,   214,    -1,    37,
     211,   314,   212,    -1,    37,   213,   218,   315,   219,   214,
      -1,    37,   211,   218,   315,   219,   212,    -1,     4,   245,
     218,   315,   219,   246,    -1,   323,   245,   218,   315,   219,
     246,    -1,    38,   245,   306,   217,   306,   217,   306,   246,
      -1,    39,   245,   306,   217,   306,   217,   306,   246,    -1,
      40,   245,   319,   246,    -1,    41,   245,   306,   217,   306,
     217,   306,   217,   306,   217,   306,   217,   306,   246,    -1,
     306,    -1,   314,    -1,   315,   217,   306,    -1,   315,   217,
     314,    -1,   218,   306,   217,   306,   217,   306,   217,   306,
     219,    -1,   218,   306,   217,   306,   217,   306,   219,    -1,
     324,    -1,     4,   215,   153,   215,     4,    -1,   218,   318,
     219,    -1,     4,   213,   306,   214,   215,   154,    -1,   316,
      -1,   318,   217,   316,    -1,   320,    -1,   324,    -1,     4,
     213,   306,   214,    -1,   323,   213,   306,   214,    -1,     4,
     211,   306,   212,    -1,   323,   211,   306,   212,    -1,     4,
     215,     4,    -1,     4,   213,   306,   214,   215,     4,    -1,
       5,    -1,   186,   213,   324,   214,    -1,    65,    -1,   184,
      -1,    70,    -1,   173,   211,   319,   212,    -1,   172,   211,
     319,   217,   319,   212,    -1,   174,   245,   319,   246,    -1,
     174,   245,   319,   217,   319,   246,    -1,    46,   245,   322,
     246,    -1,    47,   211,   319,   212,    -1,    48,   211,   319,
     212,    -1,    49,   211,   319,   217,   319,   217,   319,   212,
      -1,    44,   245,   322,   246,    -1,    58,   245,   319,   246,
      -1,    59,   245,   319,   246,    -1,    60,   245,   319,   246,
      -1,    57,   245,   306,   217,   319,   217,   319,   246,    -1,
      52,   245,   319,   217,   306,   217,   306,   246,    -1,    52,
     245,   319,   217,   306,   246,    -1,    45,   245,   319,   246,
      -1,    45,   245,   319,   217,   315,   246,    -1,    66,   245,
     319,   246,    -1,    67,    -1,    51,   245,   319,   246,    -1,
      50,   245,   319,   246,    -1,    -1,    81,   245,   320,   321,
     258,   246,    -1,   319,    -1,   322,   217,   319,    -1,     4,
     220,   218,   306,   219,    -1,   323,   220,   218,   306,   219,
      -1,     4,    -1,   323,    -1,   187,   213,   319,   214,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   207,   207,   208,   213,   215,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   240,   244,   251,   256,   261,   275,
     288,   301,   329,   343,   356,   369,   388,   393,   394,   395,
     396,   397,   401,   403,   408,   410,   416,   520,   415,   538,
     545,   556,   555,   573,   580,   591,   590,   607,   624,   647,
     646,   660,   661,   662,   663,   664,   668,   669,   675,   675,
     676,   676,   682,   683,   684,   689,   695,   757,   774,   803,
     832,   837,   842,   847,   852,   859,   869,   898,   927,   932,
     937,   942,   950,   959,   965,   971,   984,   997,  1012,  1029,
    1035,  1041,  1054,  1067,  1082,  1099,  1105,  1114,  1132,  1150,
    1159,  1171,  1176,  1184,  1204,  1227,  1238,  1246,  1268,  1291,
    1329,  1350,  1362,  1376,  1376,  1378,  1380,  1389,  1399,  1398,
    1419,  1418,  1437,  1436,  1454,  1464,  1463,  1477,  1479,  1487,
    1493,  1498,  1524,  1525,  1529,  1540,  1555,  1565,  1566,  1571,
    1579,  1588,  1596,  1614,  1618,  1624,  1632,  1636,  1642,  1650,
    1654,  1660,  1668,  1672,  1678,  1687,  1690,  1703,  1706,  1714,
    1722,  1750,  1793,  1816,  1834,  1855,  1873,  1913,  1943,  1961,
    1979,  2006,  2025,  2030,  2048,  2094,  2112,  2151,  2157,  2163,
    2170,  2211,  2237,  2254,  2258,  2277,  2311,  2358,  2376,  2393,
    2422,  2426,  2442,  2490,  2495,  2500,  2505,  2510,  2515,  2538,
    2544,  2555,  2556,  2561,  2564,  2568,  2597,  2626,  2655,  2689,
    2710,  2736,  2757,  2779,  2799,  2911,  2930,  2968,  3077,  3086,
    3092,  3107,  3135,  3152,  3161,  3175,  3189,  3195,  3201,  3210,
    3219,  3228,  3242,  3304,  3322,  3339,  3354,  3383,  3395,  3419,
    3423,  3428,  3436,  3441,  3447,  3452,  3458,  3466,  3470,  3474,
    3479,  3539,  3555,  3572,  3589,  3611,  3633,  3668,  3676,  3684,
    3690,  3697,  3704,  3724,  3750,  3762,  3774,  3782,  3790,  3799,
    3798,  3813,  3812,  3827,  3826,  3841,  3840,  3854,  3861,  3868,
    3875,  3882,  3889,  3896,  3903,  3910,  3918,  3917,  3931,  3930,
    3944,  3943,  3957,  3956,  3970,  3969,  3983,  3982,  3996,  3995,
    4009,  4008,  4022,  4021,  4038,  4041,  4047,  4059,  4079,  4103,
    4107,  4111,  4115,  4119,  4123,  4129,  4135,  4139,  4143,  4147,
    4151,  4170,  4183,  4184,  4185,  4189,  4190,  4191,  4194,  4216,
    4219,  4235,  4238,  4255,  4258,  4264,  4267,  4274,  4277,  4284,
    4340,  4410,  4415,  4482,  4518,  4526,  4569,  4608,  4628,  4660,
    4687,  4713,  4739,  4765,  4791,  4813,  4841,  4869,  4897,  4925,
    4953,  4992,  5031,  5052,  5073,  5100,  5104,  5114,  5149,  5150,
    5151,  5155,  5161,  5173,  5191,  5219,  5220,  5221,  5222,  5223,
    5224,  5225,  5226,  5227,  5234,  5235,  5236,  5237,  5238,  5239,
    5240,  5241,  5242,  5243,  5244,  5245,  5246,  5247,  5248,  5249,
    5250,  5251,  5252,  5253,  5254,  5255,  5256,  5257,  5258,  5259,
    5260,  5261,  5262,  5263,  5264,  5265,  5266,  5275,  5276,  5277,
    5278,  5279,  5280,  5281,  5282,  5283,  5284,  5285,  5290,  5289,
    5297,  5302,  5307,  5324,  5342,  5360,  5378,  5396,  5401,  5407,
    5422,  5441,  5461,  5481,  5501,  5524,  5529,  5534,  5544,  5554,
    5559,  5570,  5579,  5584,  5589,  5616,  5620,  5624,  5628,  5632,
    5639,  5643,  5647,  5651,  5658,  5663,  5670,  5675,  5679,  5684,
    5688,  5696,  5707,  5711,  5723,  5731,  5739,  5746,  5756,  5785,
    5789,  5793,  5797,  5801,  5805,  5809,  5813,  5817,  5846,  5875,
    5904,  5933,  5946,  5959,  5972,  5985,  5995,  6005,  6015,  6027,
    6040,  6052,  6056,  6060,  6064,  6068,  6086,  6104,  6112,  6120,
    6149,  6162,  6167,  6171,  6175,  6187,  6191,  6203,  6220,  6230,
    6234,  6249,  6254,  6261,  6265,  6278,  6292,  6306,  6320,  6334,
    6342,  6353,  6357,  6361,  6369,  6375,  6381,  6389,  6397,  6404,
    6412,  6427,  6441,  6455,  6467,  6483,  6492,  6501,  6511,  6522,
    6530,  6538,  6542,  6561,  6568,  6574,  6581,  6589,  6588,  6601,
    6606,  6612,  6621,  6634,  6637,  6641
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tDOUBLE", "tSTRING", "tBIGSTR", "tEND",
  "tAFFECT", "tDOTS", "tPi", "tMPI_Rank", "tMPI_Size", "tEuclidian",
  "tCoordinates", "tTestLevel", "tExp", "tLog", "tLog10", "tSqrt", "tSin",
  "tAsin", "tCos", "tAcos", "tTan", "tRand", "tAtan", "tAtan2", "tSinh",
  "tCosh", "tTanh", "tFabs", "tFloor", "tCeil", "tRound", "tFmod",
  "tModulo", "tHypot", "tList", "tLinSpace", "tLogSpace", "tListFromFile",
  "tCatenary", "tPrintf", "tError", "tStr", "tSprintf", "tStrCat",
  "tStrPrefix", "tStrRelative", "tStrReplace", "tAbsolutePath", "tDirName",
  "tStrSub", "tStrLen", "tFind", "tStrFind", "tStrCmp", "tStrChoice",
  "tUpperCase", "tLowerCase", "tLowerCaseIn", "tTextAttributes",
  "tBoundingBox", "tDraw", "tSetChanged", "tToday", "tFixRelativePath",
  "tCurrentDirectory", "tSyncModel", "tNewModel", "tOnelabAction",
  "tOnelabRun", "tCpu", "tMemory", "tTotalMemory", "tCreateTopology",
  "tCreateTopologyNoHoles", "tDistanceFunction", "tDefineConstant",
  "tUndefineConstant", "tDefineNumber", "tDefineString", "tSetNumber",
  "tSetString", "tPoint", "tCircle", "tEllipse", "tLine", "tSphere",
  "tPolarSphere", "tSurface", "tSpline", "tVolume", "tCharacteristic",
  "tLength", "tParametric", "tElliptic", "tRefineMesh", "tAdaptMesh",
  "tRelocateMesh", "tSetFactory", "tThruSections", "tPlane", "tRuled",
  "tTransfinite", "tComplex", "tPhysical", "tCompound", "tPeriodic",
  "tUsing", "tPlugin", "tDegenerated", "tRecursive", "tRotate",
  "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tAffine",
  "tBooleanUnion", "tBooleanIntersection", "tBooleanSubtraction",
  "tRecombine", "tSmoother", "tSplit", "tDelete", "tCoherence",
  "tIntersect", "tMeshAlgorithm", "tReverse", "tLayers", "tScaleLast",
  "tHole", "tAlias", "tAliasWithOptions", "tCopyOptions",
  "tQuadTriAddVerts", "tQuadTriNoNewVerts", "tQuadTriSngl", "tQuadTriDbl",
  "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tElseIf", "tElse", "tEndIf", "tExit", "tAbort",
  "tField", "tReturn", "tCall", "tSlide", "tMacro", "tShow", "tHide",
  "tGetValue", "tGetStringValue", "tGetEnv", "tGetString", "tGetNumber",
  "tHomology", "tCohomology", "tBetti", "tExists", "tFileExists",
  "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION",
  "tGmshExecutableName", "tSetPartition", "tNameToString", "tStringToName",
  "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'",
  "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL",
  "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC",
  "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'",
  "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems",
  "GeoFormatItem", "SendToFile", "Printf", "View", "Views",
  "ElementCoords", "ElementValues", "Element", "@1", "@2", "Text2DValues",
  "Text2D", "@3", "Text3DValues", "Text3D", "@4", "InterpolationMatrix",
  "Time", "@5", "NumericAffectation", "NumericIncrement", "LP", "RP",
  "Affectation", "Comma", "DefineConstants", "@6", "@7", "@8", "@9",
  "UndefineConstants", "Enumeration", "FloatParameterOptions",
  "FloatParameterOption", "CharParameterOptions", "CharParameterOption",
  "PhysicalId0", "PhysicalId1", "PhysicalId2", "PhysicalId3",
  "InSphereCenter", "CircleOptions", "Shape", "Transform", "MultipleShape",
  "ListOfShapes", "LevelSet", "Delete", "Colorify", "SetPartition",
  "Visibility", "Command", "Slide", "Loop", "Extrude", "@10", "@11", "@12",
  "@13", "@14", "@15", "@16", "@17", "@18", "@19", "@20", "@21", "@22",
  "ExtrudeParameters", "ExtrudeParameter", "BooleanOperator",
  "BooleanOption", "Boolean", "TransfiniteType", "TransfiniteArrangement",
  "TransfiniteCorners", "RecombineAngle", "PeriodicTransform",
  "Constraints", "Coherence", "HomologyCommand", "Homology", "FExpr",
  "FExpr_Single", "@23", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "@24",
  "RecursiveListOfStringExprVar", "StringIndex", "String__Index", 0
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
     445,   446,    63,   447,   448,   449,   450,    60,    62,   451,
     452,    43,    45,    42,    47,    37,    33,   453,   454,   455,
      94,    40,    41,    91,    93,    46,    35,    44,   123,   125,
     126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   221,   222,   222,   223,   223,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   225,   225,   226,   226,   226,   226,
     226,   226,   227,   227,   227,   227,   228,   228,   228,   228,
     228,   228,   229,   229,   230,   230,   232,   233,   231,   234,
     234,   236,   235,   237,   237,   239,   238,   240,   240,   242,
     241,   243,   243,   243,   243,   243,   244,   244,   245,   245,
     246,   246,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   248,   248,   249,   249,   249,   250,   249,
     251,   249,   252,   249,   249,   253,   249,   254,   254,   255,
     255,   255,   256,   256,   257,   257,   257,   258,   258,   259,
     259,   259,   259,   260,   260,   260,   261,   261,   261,   262,
     262,   262,   263,   263,   263,   264,   264,   265,   265,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   267,   267,   267,   267,   267,   267,   267,
     267,   268,   268,   269,   269,   269,   269,   269,   269,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   271,   271,
     271,   271,   271,   272,   272,   273,   274,   274,   274,   274,
     274,   274,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   276,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   278,   278,   278,   279,
     278,   280,   278,   281,   278,   282,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   283,   278,   284,   278,
     285,   278,   286,   278,   287,   278,   288,   278,   289,   278,
     290,   278,   291,   278,   292,   292,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   294,   294,   294,   295,   295,   295,   296,   297,
     297,   298,   298,   299,   299,   300,   300,   301,   301,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   303,   303,   303,   304,   304,
     304,   305,   305,   305,   305,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   308,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   309,   309,   309,   309,   309,
     310,   310,   310,   310,   311,   311,   312,   312,   312,   312,
     312,   312,   313,   313,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   315,   315,   315,   315,   316,   316,   316,   316,   317,
     317,   318,   318,   319,   319,   319,   319,   319,   319,   319,
     319,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   321,   320,   322,
     322,   323,   323,   324,   324,   324
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     5,     5,     7,     7,
       7,     9,     6,     6,     6,     8,     0,     2,     2,     2,
       2,     2,     1,     3,     1,     3,     0,     0,    10,     1,
       3,     0,    13,     1,     3,     0,    15,     8,    14,     0,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     5,     7,     7,     4,     3,     6,     6,
       7,     7,     6,     6,     9,     9,     6,     6,     7,     7,
       6,     6,     4,     8,     8,     9,     9,     9,     9,     8,
       8,     9,     9,     9,     9,     6,     9,     6,     9,     5,
       8,     8,    11,     6,     9,     5,     7,     9,     9,    11,
       7,     9,     9,     0,     1,     0,     3,     5,     0,     9,
       0,    11,     0,    11,     5,     0,     9,     0,     3,     3,
       5,     5,     0,     2,     3,     5,     3,     0,     2,     3,
       3,     3,     5,     1,     1,     3,     1,     1,     3,     1,
       1,     3,     1,     1,     3,     0,     5,     0,     2,     5,
       7,     8,     6,     7,     4,     7,     8,     8,     7,     7,
      11,     8,     4,     8,     8,     8,     9,     3,     4,    10,
       7,     7,     8,     4,     8,    12,     8,     8,     7,     9,
       4,     8,     8,     5,    11,     5,     9,     9,     4,     9,
       9,     1,     1,     0,     2,     6,     6,     6,     6,     8,
      10,    14,    16,    12,     8,     8,     6,    14,     4,     6,
       6,     3,     4,     5,     6,     5,     3,     3,     4,     5,
       4,     5,     3,     5,     7,     7,     3,     7,     3,     2,
       2,     2,     2,     2,    15,     2,     2,     2,     2,     2,
      16,    11,     6,     8,     8,    10,     1,     2,     2,     1,
       3,     3,     4,     4,     1,     1,     5,    11,    13,     0,
       7,     0,    13,     0,    15,     0,     6,     8,     8,     8,
      12,    12,    12,    14,    14,    14,     0,    12,     0,    12,
       0,    12,     0,    16,     0,    16,     0,    16,     0,    18,
       0,    18,     0,    18,     1,     2,     5,     7,     9,     2,
       2,     3,     2,     3,     2,     3,     2,     3,     2,     3,
       9,     6,     1,     1,     1,     0,     2,     3,     9,     0,
       3,     0,     1,     0,     2,     0,     2,     0,     2,     7,
       6,     8,     5,     3,     8,     5,     4,     6,    11,    11,
      18,    18,    12,    12,    12,    10,    10,    10,    10,    10,
       4,     4,     4,     4,     4,     2,     3,     6,     1,     1,
       1,     2,     5,     7,    10,     1,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       4,     6,     1,     4,     4,     4,     4,     4,     4,     4,
       2,     5,     5,     5,     5,     3,     6,     4,     7,     6,
       6,     6,     4,     6,     4,     1,     2,     2,     3,     3,
      11,     9,     7,     7,     1,     3,     1,     1,     2,     3,
       4,     5,     1,     1,     2,     3,     3,     5,     4,     2,
       2,     2,     2,     3,     3,     3,     3,     5,     5,     5,
       5,    16,    16,    16,    16,     1,     1,     1,     3,     3,
       4,     4,     4,     6,     6,     6,     6,     8,     8,     4,
      14,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     1,     4,     4,     4,     4,     3,
       6,     1,     4,     1,     1,     1,     4,     6,     4,     6,
       4,     4,     4,     8,     4,     4,     4,     4,     8,     8,
       6,     4,     6,     4,     1,     4,     4,     0,     6,     1,
       3,     5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   573,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   332,   333,   334,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,     0,     0,
     274,   275,     0,     0,     0,   269,     0,     0,     0,     0,
       0,   378,   379,   380,     0,     0,     5,     7,     6,     8,
       9,    10,    22,    11,    12,    13,    14,    21,    20,    19,
      15,     0,    16,    17,    18,     0,    23,   574,     0,   427,
     573,   541,   428,   430,   431,   429,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   543,     0,   564,   545,
     435,   436,   437,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   432,   433,   434,   544,     0,     0,     0,
       0,    68,    69,     0,     0,   213,     0,     0,     0,   385,
       0,   533,   574,   442,     0,     0,     0,     0,   253,     0,
     255,   256,   251,   252,     0,   257,   258,   125,   137,    68,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   465,     0,     0,     0,     0,     0,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   573,     0,
     213,   574,     0,     0,   375,     0,     0,     0,     0,     0,
       0,     0,     0,   573,   483,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   505,   506,
     507,   476,   482,     0,   477,   574,   442,     0,     0,     0,
       0,   573,     0,     0,   527,     0,     0,     0,     0,   249,
     250,     0,   573,     0,     0,     0,   267,   268,     0,   213,
       0,   213,   573,     0,   574,     0,   213,   381,     0,     0,
      68,    69,     0,     0,    61,    65,    64,    63,    62,    67,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   388,
     387,   389,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   212,     0,   211,     0,     0,   246,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,   242,     0,     0,   450,   187,     0,   573,
       0,   533,   574,   534,     0,     0,   569,     0,   123,   123,
       0,     0,     0,     0,   521,   522,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     343,   343,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   213,
     213,     0,   467,   466,     0,     0,     0,     0,   213,   213,
       0,     0,     0,     0,     0,     0,     0,   285,     0,   213,
       0,     0,     0,     0,     0,   345,     0,     0,     0,     0,
       0,     0,     0,   231,   376,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,   489,     0,     0,   490,     0,   491,     0,
     492,     0,     0,     0,     0,     0,     0,   387,   484,     0,
     478,     0,     0,     0,   353,    68,    69,     0,   248,     0,
       0,     0,     0,     0,   213,     0,     0,     0,     0,     0,
     271,   270,     0,   236,     0,   237,     0,     0,     0,   213,
       0,     0,     0,   335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,   455,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     438,   567,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    62,     0,   386,    61,    62,     0,     0,    61,
       0,     0,     0,     0,     0,   208,     0,     0,     0,     0,
     214,     0,     0,     0,   403,   402,   401,   400,   396,   397,
     399,   398,   391,   390,   392,   393,   394,   395,     0,     0,
       0,   188,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     372,   373,   374,     0,     0,     0,     0,     0,     0,   341,
       0,     0,     0,   153,   154,     0,   156,   157,     0,   159,
     160,     0,   162,   163,     0,   182,     0,   193,     0,   200,
       0,     0,     0,     0,   174,   213,     0,     0,     0,     0,
       0,   469,   468,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   279,     0,     0,     0,     0,     0,     0,     0,
     356,     0,     0,   232,     0,     0,   228,     0,     0,     0,
     371,   370,     0,     0,     0,     0,     0,   455,    70,    71,
       0,   508,     0,     0,     0,     0,     0,   442,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   493,     0,   494,
       0,   495,     0,   496,     0,     0,   386,   479,   486,     0,
     392,   485,     0,     0,     0,   509,     0,     0,     0,     0,
       0,     0,     0,     0,   272,   273,     0,     0,   238,   240,
       0,   575,     0,     0,     0,     0,     0,    61,    62,     0,
       0,    61,    62,     0,     0,     0,     0,    92,    76,     0,
     444,   443,   457,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   426,   414,     0,   416,   417,   418,   419,   420,
     421,   422,     0,     0,     0,   554,     0,   561,   550,   551,
     552,     0,   566,   565,     0,   462,     0,     0,     0,     0,
     555,   556,   557,   464,   563,   142,   147,   115,     0,     0,
     546,     0,   548,     0,   440,   447,   448,   542,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,     0,     0,     0,   449,     0,     0,
       0,     0,   571,     0,     0,    46,     0,     0,     0,    59,
       0,    37,    38,    39,    40,    41,   446,   445,     0,     0,
     539,    26,    24,     0,     0,     0,     0,    27,     0,     0,
     243,   570,    72,   126,    73,   138,     0,     0,     0,   523,
     524,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
       0,   339,   344,   342,     0,   352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   386,   386,   386,     0,     0,
       0,     0,     0,   239,   241,     0,     0,     0,   203,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   314,     0,   276,     0,     0,
       0,     0,     0,     0,   346,   355,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   444,   443,     0,     0,
     512,     0,   511,   510,     0,     0,   519,     0,     0,   488,
       0,     0,     0,     0,     0,     0,     0,   480,     0,     0,
     446,   445,     0,     0,     0,     0,     0,     0,   233,     0,
       0,     0,     0,     0,   235,   336,     0,     0,     0,     0,
     382,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   572,     0,     0,   452,     0,   451,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,    90,
       0,     0,    78,     0,     0,     0,     0,    82,   105,   107,
       0,     0,   531,     0,   113,     0,     0,     0,     0,     0,
     404,     0,     0,     0,     0,     0,    32,   454,   453,   537,
     535,    25,     0,     0,   538,   536,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172,     0,
       0,     0,     0,     0,     0,     0,     0,   350,     0,     0,
     155,     0,   158,     0,   161,     0,   164,     0,     0,     0,
       0,     0,     0,     0,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   320,     0,     0,   319,     0,   326,
       0,   328,     0,   322,     0,   324,     0,   286,   315,     0,
       0,     0,   226,     0,     0,     0,   357,     0,   230,   229,
     377,     0,     0,    33,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   497,   498,   499,
     500,   487,   481,     0,     0,     0,     0,   528,     0,     0,
       0,   262,     0,     0,     0,   337,   213,     0,     0,     0,
       0,    87,     0,    91,     0,     0,    79,     0,    83,     0,
     245,   456,   244,   415,   423,   424,   425,   562,     0,     0,
     560,   460,   461,   463,     0,     0,   439,   143,     0,   568,
     148,   459,   547,   549,   441,     0,     0,     0,    88,     0,
       0,     0,    61,     0,     0,     0,     0,    80,     0,     0,
       0,   529,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,     0,     0,    28,    29,     0,    30,     0,     0,
     127,   134,     0,     0,    74,    75,   170,     0,     0,     0,
       0,     0,     0,   173,     0,     0,   190,   191,     0,     0,
     175,   198,     0,     0,     0,     0,     0,   165,     0,   349,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   247,     0,     0,     0,     0,   213,   213,     0,   296,
       0,   298,     0,   300,     0,   321,   476,     0,     0,   327,
     329,   323,   325,     0,     0,   280,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   456,   515,   514,
     513,     0,     0,     0,     0,     0,     0,     0,   516,   178,
     179,     0,     0,     0,     0,   116,   120,     0,     0,   335,
       0,   383,     0,     0,     0,    89,     0,     0,     0,    81,
       0,   458,     0,     0,     0,     0,     0,     0,    99,     0,
       0,    93,     0,     0,     0,     0,   110,     0,     0,   111,
       0,   532,   215,   216,   217,   218,     0,     0,    42,     0,
       0,     0,     0,     0,    44,   540,     0,     0,   128,   135,
       0,     0,     0,     0,   168,   176,   177,   181,     0,     0,
     192,     0,     0,   351,     0,     0,   185,     0,     0,   340,
     197,   171,   184,   196,   202,   183,     0,   194,   201,     0,
       0,     0,     0,     0,     0,   473,     0,   472,     0,     0,
       0,   287,     0,     0,   288,     0,     0,   289,     0,     0,
       0,     0,     0,     0,     0,   225,     0,     0,   224,     0,
       0,     0,   219,     0,     0,   354,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   526,     0,   264,   263,
       0,     0,     0,     0,     0,     0,   100,     0,     0,    94,
       0,     0,     0,   553,   559,   558,     0,   144,   146,     0,
     149,   150,   151,   101,   103,    95,    97,   106,   108,     0,
     114,     0,    84,    47,     0,     0,     0,   475,     0,     0,
       0,    31,     0,   142,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,     0,   186,     0,   347,   347,
       0,   121,   122,   213,     0,   206,   207,     0,     0,     0,
       0,     0,     0,     0,   316,     0,     0,   213,     0,     0,
       0,     0,     0,   210,   209,   517,   518,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,   118,     0,   338,
       0,   102,   104,    96,    98,    85,     0,   521,   522,     0,
       0,   530,     0,    43,     0,     0,     0,    45,    60,     0,
       0,     0,   132,   130,   365,   367,   366,   368,   369,   189,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   471,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,     0,     0,     0,   281,     0,     0,
     220,     0,     0,     0,     0,     0,     0,     0,     0,   525,
     265,     0,     0,   384,     0,   145,     0,     0,   152,   112,
       0,     0,     0,     0,     0,   129,   136,   142,   142,     0,
       0,     0,     0,     0,   348,   358,     0,     0,   359,     0,
     204,     0,   302,     0,     0,   304,     0,     0,   306,     0,
       0,     0,   317,     0,   277,     0,   213,     0,     0,     0,
       0,     0,     0,     0,     0,   180,   119,   261,     0,   139,
       0,     0,    51,     0,    57,     0,     0,     0,     0,     0,
     166,   195,     0,   362,     0,   363,   364,   470,   290,     0,
       0,   297,   291,     0,     0,   299,   292,     0,     0,   301,
       0,     0,     0,   283,     0,   223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,   131,     0,     0,     0,     0,   308,     0,   310,     0,
     312,   318,   330,   282,   278,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   140,   141,    48,     0,    55,     0,
       0,     0,     0,     0,     0,   293,     0,     0,   294,     0,
       0,   295,     0,     0,   227,     0,   221,     0,     0,     0,
       0,     0,     0,    49,     0,     0,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   284,     0,   520,     0,
       0,     0,     0,     0,     0,     0,     0,   260,     0,     0,
     303,     0,   305,     0,   307,     0,   222,     0,     0,     0,
       0,    50,    52,     0,    53,     0,     0,     0,     0,     0,
       0,   501,   502,   503,   504,     0,     0,    58,   360,   361,
     309,   311,   313,    54,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    96,  1033,    97,    98,   738,  1587,  1593,
    1021,  1241,  1792,  2012,  1022,  1956,  2053,  1023,  2014,  1024,
    1025,  1245,   371,   466,   197,   861,    99,   756,   478,  1723,
    1868,  1867,  1724,   479,  1786,  1209,  1407,  1210,  1410,   792,
     795,   798,   801,  1618,  1460,   720,   318,   442,   443,   102,
     103,   104,   105,   106,   107,   108,   109,   319,  1118,  1895,
    1975,   830,  1642,  1645,  1648,  1929,  1933,  1937,  1996,  1999,
    2002,  1114,  1115,   111,   913,   320,  1286,  1074,   789,   839,
    1816,   113,   114,   115,   116,   321,   199,   975,   533,   272,
    1440,   322,   323,   324,   601,   333,  1006,  1233,   476,   471,
     976,   477,   354,   326
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1697
static const yytype_int16 yypact[] =
{
    9922,   102,    42, 10061, -1697, -1697,  4431,    51,   -59,  -159,
     -94,    47,   137,   147,   162,   168,   -79,   181,   204,    10,
      55,   113,   113,  -142,    61,    65,    18,    79,    92,    30,
     123,   155,   228,   290,   327,   342,   206,   435,   219,   303,
     374,   450,   700,   451,   404,   721,   110,   336,   464,   -69,
     339,   -76,   -76,   347,   395,    36, -1697, -1697, -1697,   298,
     504,   512,    14,    62,   528,   542,   302,   608,   631,   635,
    6020,   643,   425,   441,   446,    25,    56, -1697,   452,   453,
   -1697, -1697,   670,   679,   466, -1697,  8620,   483,  6115,    38,
      39, -1697, -1697, -1697,  9776,   486, -1697, -1697, -1697, -1697,
   -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697,
   -1697,   488, -1697, -1697, -1697,    17, -1697,  -109,   111, -1697,
       7, -1697, -1697, -1697, -1697, -1697,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   524,   531,   537,   113,   113,   113,   113,   538,   113,
     113,   113,   113,   113,   113,   541, -1697,   113, -1697, -1697,
   -1697, -1697, -1697,   113,   113,   725,   546,   551,   561,   113,
     113,   573,   577, -1697, -1697, -1697, -1697,   597,  9776,  9776,
    9776,  8948,  9015,    16,     9,   473,   604,   605,   521, -1697,
     620,   826,   431,   136,   833,  9776, 10208, 10208, -1697,  9776,
   -1697, -1697, -1697, -1697, 10208, -1697, -1697, -1697, -1697, -1697,
   -1697,  6316,     9,  9776,  8744,  9776,  9776,   636,  9776,  8744,
    9776,  9776,   644,  8744,  9776,  9776,  6440,   645,   653, -1697,
    8744,  6020,  6020,  6020, 10208,  9776,   649,   665,  6020,  6020,
    6020,   671,   677,   682,   685,   692,  6650,  6860,  7070,   681,
    2061,   910,  6440,    25,   704,   733,   -76,   -76,   -76,  9776,
    9776,  -145, -1697,  -140,   -76,   756,   765,   782,  4203,   -96,
     -82,   706,   723,   745,  6020,  6020,  6440,   750,     4,   790,
   -1697,   792,  1007,  1020, -1697,   817,   821,   830,  6020,  6020,
     843,   844,   852,   543, -1697,   226,   113,   113,   113,   113,
      -4,    19,    20,    21,   699,  7280,  9776,  4884, -1697, -1697,
   -1697,  4094, -1697,  1054, -1697,   445,   132,  1055,  9776,  9776,
    9776,  -174,  9776,   886, -1697,   912,  9776,  9776,  9776, -1697,
   -1697,  9776,   858,  1084,  1102,   914, -1697, -1697,  1137, -1697,
    1138, -1697,   616, 10288,   525, 10208, -1697, -1697,  6440,  6440,
    9224,  9291,   941,   952,  6316, -1697, -1697, -1697, -1697, -1697,
   -1697,  6440,  1161,   963,  9776,  9776,  1173,  9776,  9776,  9776,
    9776,  9776,  9776,  9776,  9776,  9776,  9776,  9776,  9776,  9776,
    9776,  9776,  9776,  9776,  9776,  9776,  9776,  9776,  9776, 10208,
   10208, 10208, 10208, 10208, 10208, 10208, 10208, 10208, 10208,  6440,
   10208, 10208,  9776, 10208, 10208, 10208, 10208, 10208,  9776,  6316,
    9776, 10208, 10208, 10208, 10208, 10208,     9,  6316,     9,   996,
     996,   996,   103, 12193,   120,  9462,   127,   992,  1204,   113,
    1011, -1697,  1018,  5367,  9776,  8744, -1697,  9776,  9776,  9776,
    9776,  9776,  9776,  9776,  9776,  9776,  9776,  9776,  9776,  9776,
    9776,  9776, -1697, -1697,  9776,  9776, -1697, -1697,   926,   622,
    -137, -1697,   526, -1697,  -122,  4680, -1697,  -114,   224,   312,
    1025,  1026, 12214,  8744,  4129, -1697,   130, 12235, 12256,  9776,
   12277,   259, 12298, 12319,  9776,   273, 12340, 12361,  1252,  9776,
    9776,   552,  1254,  1258,  1272,  1071, 12382,  9776,  9776,  1290,
    1291,  1291,  9776,  8540,  8540,  8540,  8540,  9776,  1293,  9776,
    1296,  9776,  1297,  8744,  8744, 10315,  1097,  1299,  1092, -1697,
   -1697,   -62, -1697, -1697, 10421, 10447,   -76,   -76,   473,   473,
     -51,  9776,  9776,  9776,  4203,  4203,  9776,  5367,   -38, -1697,
    9776,  9776,  9776,  9776,  9776,  1304,  1308,  1309,  9776,  1311,
    9776,  9776,  1318, -1697, -1697,  8744,  8744,  8744,  1313,  1316,
    9776,  9776,  9776,  9776,  9776,  1319,   491,  7490,  7700,  9776,
    9776, 10208,  9776, -1697,  1253,  9776, -1697,  1262, -1697,  1263,
   -1697,  1265,    40,    44,    45,    46,  8744,   996, -1697, 12403,
   -1697,   559,  9776,  7910, -1697,  9776,  9776,   632, -1697, 12424,
   12445, 12466,  1176, 10473, -1697,  1115,  4155, 12487, 12508, 11825,
   -1697, -1697,  8744, -1697,  1479, -1697,  1732,  9776,  9776, -1697,
    9776,  9776,  1133,  5151,  1153,   651,   188, 12529,   195, 11848,
    9776,  8744,  1360,  1361, -1697,  9776, 12550, 11871,   218,  5728,
    5728,  5728,  5728,  5728,  5728,  5728,  5728,  5728,  5728,  5728,
   10499,  5728,  5728,  5728,  5728,  5728,  5728,  5728, 10525, 10551,
   10577,   637,   652,   637,  1156,  1158,  1154,   409,   409,  1155,
     409,  1157,  1162,  1163, 10603,   409,   409,   409,   -55,   409,
   13096, -1697,   953,  1179,  1180,  1166,   666,   673,  1186,  1188,
    1198,  1329,  1331,  6440,   142,  1370,  1371,  6440,    89,  6316,
    9776,  1410,  1413,    33,   409, -1697,   -70,    31,    34,   -13,
   -1697,  2574,   655,  4327,  1189,  1140,   794,   794,   614,   614,
     614,   614,   230,   230,   996,   996,   996,   996,    15, 12571,
   11894, -1697,  9776,  9776,  1422,    27,  8744,  9776,  9776,  1424,
    8744,  9776,  1425, 10208,  1426, -1697,     9,  1428, 10208,  9776,
    6316,  1421,  8744,  8744,  1279,  1429,  1431, 12592,  1432,  1284,
    1434,  1437, 12613,  1289,  1440,  1442,  9776, 12634,  6377,  1232,
   -1697, -1697, -1697,  1445,  1462, 12655, 12676,  9776,  6440,  1467,
    1468, 12697,  1261, 13096,  1255,  1264, 13096,  1267,  1266, 13096,
    1276,  1268, 13096,  1277, 12718, -1697, 12739, -1697, 12760, -1697,
     689,   690,  8744,  1274, -1697, -1697,  2599,  2994,   -76,  9776,
    9776, -1697, -1697,  1256,  1280,  4203, 10629, 10655, 10681, 10395,
     905,   -76,  3045, 12781,  6587, 12802, 12823, 12844,  9776,  1471,
   -1697,  9776, 12865, -1697, 11917, 11940, -1697,   696,   712,   716,
   -1697, -1697, 11963, 11986, 10707, 12886, 12009,   132, -1697, -1697,
    8744, -1697,  8744,  4129,  1269,  8744,  1281,   257, 10733, 10759,
     409, 10785,  1278,  6797,  1282,  1283,  1285, -1697,  8744, -1697,
    8744, -1697,  8744, -1697,  8744,   722, -1697, -1697,  4353,  8744,
     996, -1697, 12907, 12032,  8744, -1697,  1472,  1491,  1495,  1294,
    9776,  3241,  9776,  9776, -1697, -1697,    -2,   726, -1697, -1697,
    3462, -1697,  9500,  1286,  1288,  6440,  1498,  1469,  1475,  6440,
     142,  1477,  1478,  6440,   142,  7007,   730, -1697, -1697, 12055,
     275,  1036, -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697,
   -1697, -1697, -1697, -1697,  9776, -1697, -1697, -1697, -1697, -1697,
   -1697, -1697,  9776,  9776,  9776, -1697,  8744, -1697, -1697, -1697,
   -1697, 10208, -1697, -1697,  9776, -1697,  6440, 10208, 10208, 10208,
   -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697,  9776, 10208,
   -1697, 10208, -1697,  9776, -1697, -1697, -1697, -1697,   113,   113,
    1504, -1697,  9776,  1505,   113,   113,  1506,    35,  9776,  1517,
    1518,  1159, -1697,  1519,  1312,    25,  1521, -1697,  8744,  8744,
    8744,  8744, -1697,   409,  9776, -1697,  1317,  1320,  1314, -1697,
    1524, -1697, -1697, -1697, -1697, -1697,   478,   489, 12928, 12078,
   -1697, -1697,  1335, 10208,   153, 12949, 12101, -1697,   157, 10811,
   -1697, -1697, -1697,    58, -1697, -1697,  5728,   409,   -76,  4129,
   -1697,   618,  6440,  6440,  1529,  6440,   848,  6440,  6440,  1532,
    1448,  6440,  6440,  1260,  1534,  1538,  8744, -1697,  1328,  1546,
    1547,  4587, -1697, -1697,  1549, -1697,  1551,   279,  9776,   279,
    9776,   279,  9776,   279,  9776,  1552,  1554,  1566,  1569,  1571,
     731,  1579,  3529, -1697, -1697,   -18, 10837, 10863, -1697, -1697,
    7217,  -131,   -76,   -76,   -76,  1583,  9572,  1338,  1586,  1385,
      24,    26,    41,    49,   -46, -1697,    -8, -1697,   905,  1593,
    1595,  1600,  1602,  1605, 13096, -1697,  1664,  1384,  1613,  1614,
    1615,  1541,  1619,  1626,  1630,  9776,   132,   -23,   735,   738,
   -1697,   743, -1697, -1697,  9776,  9776, -1697,  9776,  9776, -1697,
    9776,  9776,  9776,   753,   754,   758,   762, -1697,  9776,   763,
     132,   132,   769,  6440,  6440,  6440,  1633, 10889, -1697,  4839,
     602,  1634,  1636,  1427, -1697, -1697,  1801,  1423,  6440,  1420,
   -1697,   113,   113,  1637,  9776,  1643,   113,   113,  1644,  9776,
    1649, -1697,   409,  1652, -1697,  1638, -1697,  1654,  5728,  5728,
    5728,  5728,   680,  1444, 10369,  1450,   409,   409,  1446,   688,
     713, 12970,  1452,   409,  5728,  1134, 10208, -1697,  1841, -1697,
    1134, 10208, -1697,   173,  1451,  1665,  2023, -1697, -1697, -1697,
      25,  9776, -1697,   802, -1697,   805,   810,   814,   815,   279,
   13096,  1470,  9776,  9776,  6440,  1460, -1697, -1697, -1697, -1697,
    1464, -1697,  1674,    52, -1697, -1697,  1676,  9776,  5527,  1474,
    1473,  1677,  1678,     6,  1476,  1481,  1587,  1587,  6440,  1682,
    1482,  1483,  1684,  1685,  6440,  1484,  1686,  1689, -1697,  1698,
    6440,   834,  6440,  6440,  6440,  1701,  1702, -1697,  6440,  6440,
   13096,  6440, 13096,  6440, 13096,  6440, 13096,  6440,  6440,  6440,
    1489,  1492,  1704,   209, -1697,  9776,  9776,  9776,  1494,  1496,
    -120,   -89,   -86,  1503, -1697,  2121,  6440, -1697,  9776, -1697,
    1703, -1697,  1711, -1697,  1713, -1697,  1714, -1697, -1697,  4203,
     522,  6230, -1697,  1507,  1508,  8120, -1697,  8744, -1697, -1697,
   -1697,  1509,  9776, -1697, -1697, 12124,  1717,   409,  1512,  1514,
   10915, 10941, 10967, 10993, 11019, 11045, 11071, -1697, -1697, -1697,
   -1697, 13096, -1697,   409,  1723,  1724,  1581, -1697,  9776,  9776,
    9776, -1697,  1725,   565,  6316, -1697, -1697,  1522,  1729,  1134,
   10208, -1697,  2199, -1697,  1134, 10208, -1697,  2243, -1697,   279,
   -1697,   493, -1697, -1697, -1697, -1697, -1697, -1697, 10208,  9776,
   -1697, -1697, -1697, -1697, 10208,  1734, -1697, -1697,    13, -1697,
   -1697, -1697, -1697, -1697, -1697,  1730,   637,   637, -1697,  1737,
     637,   637,  6316,  9776,  1744,  1752,    33, -1697,  1751, 12147,
      25, -1697,  1753,  1754,  1780,  1781,  6440,  9776, 11097, 11123,
     847, -1697,  9776,  1784, -1697, -1697, 10208, -1697, 11149,  5101,
   13096, -1697,  1786,  1793, -1697, -1697, -1697,  9776,  9776,   -76,
    1795,  1797,  1798, -1697,  9776,  9776, -1697, -1697,  1799,  9776,
   -1697, -1697,  1805,  1800,  1608,   850,  1807,  1655,  9776, -1697,
    1823,  1824,  1830,  1835,  1839,  1842,  1068,  1843,  8744,  8744,
    9776, -1697,  8540,  7427, 12991,  2439,   473,   473,   -76,  1844,
     -76,  1845,   -76,  1847,  9776, -1697,   253,  1629, 13012, -1697,
   -1697, -1697, -1697,  7637,   104, -1697,  1864,  4650,  1865,  6440,
     -76,  4650,  1866,   856,  9776,  2384,  1867,   132, -1697, -1697,
   -1697,  9776,  9776,  9776,  9776,  9776,  9776,  9776, -1697, -1697,
   -1697,  6440,  5559,   305, 13033, -1697, -1697,  5600,  1659,  5151,
    6440, -1697,  1871,   637,   637, -1697,  1872,   637,   637, -1697,
    6440, -1697,  1667,  5728,   409,  5317,  5810,  6316, -1697,  1877,
    1878, -1697,  1879,  1880,  1881,  2472, -1697,  1883,  1882, -1697,
    1680, -1697, -1697, -1697, -1697, -1697,  1885,   306, 13096,  9776,
    9776,  6440,  1675,   860, 13096, -1697,  1886,  9776, -1697, -1697,
    1683,  1690,  7847,  8057,   389, -1697, -1697, -1697,  8267,  8434,
   -1697,  8681,  1895, -1697,  6440,  1896, -1697,  1821,  1904, 13096,
   -1697, -1697, -1697, -1697, -1697, -1697,  1695, -1697, -1697,   872,
     888, 10342,  3046,  1908,  1697, -1697,  9776, -1697,  1699,  1700,
     126, -1697,  1705,   156, -1697,  1707,   192, -1697,  1708, 12170,
    1910,  6440,  1913,  1709,  9776, -1697,  8330,   214, -1697,   892,
     227,   258, -1697,  1911,  8795, -1697, -1697,  5728,  5728, 11175,
   11201, 11227, 11253, 11279,  1770,  9776, -1697,  9776, -1697, -1697,
    8744,  3329,  1916,  6316,  1710,  1712, -1697,  1922,  1924, -1697,
    1926,  1927,  1928, -1697, -1697, -1697,  4884, -1697, -1697, 10208,
   13096, -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697,    25,
   -1697,  1782, -1697, -1697,  9776, 11305, 11331, -1697,  6440,  9776,
    1929, -1697, 11357, -1697, -1697,  6440,  6440,  1931,  1933,  1934,
    1939,  1940,  1941,   896, -1697,  1735, -1697,  6440,   615,   739,
    8744, -1697, -1697,   473,  5700, -1697, -1697,  4203,   905,  4203,
     905,  4203,   905,  1942, -1697,   897,  6440, -1697,  8862,   -76,
    1944,  8744,   -76, -1697, -1697, -1697, -1697,  9776,  9776,  9776,
    9776,  9776,  9776,  8905,  8973,   918, -1697, -1697,  1740, -1697,
    1948, -1697, -1697, -1697, -1697, -1697,   923,  3952,  1949,   949,
    1951, -1697,  1741, 13096,  9776,  9776,   954, 13096, -1697,  9776,
     955,   970, -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697,
    1743,  9776,   971,  1746,   -76,  6440,  1952,  1749,   -76,  1956,
     986,  1736,  9776, -1697,  9071,   311,   642,  9138,   315,   878,
    9181,   368,  1093, -1697,  6440,  1962,  1861,  3834,  1763,   375,
   -1697,  1002,   378, 11383, 11409, 11435, 11461, 11487,  3694, -1697,
   -1697,  1976,  1977, -1697,  9776, -1697,  6316,     9, -1697, -1697,
    9776, 13054, 11513,    48, 11539, -1697, -1697, -1697, -1697,  9776,
    9249,  1980,   -76,    73, -1697, -1697,   -76,    83, -1697,  1981,
   -1697,  9347,  1982,  9776,  1983,  1984,  9776,  1985,  2001,  9776,
    2002,  1790, -1697,  9776, -1697,   905, -1697,  8744,  2004,  8330,
    9776,  9776,  9776,  9776,  9776, -1697, -1697, -1697,  3973, -1697,
    1802,  1021, -1697,  9776, -1697,  6440,  9776,  1030,  1033, 11565,
   -1697, -1697,   403, -1697,   407, -1697, -1697, -1697, -1697,  1796,
    9419, -1697, -1697,  1804,  9525, -1697, -1697,  1806,  9623, -1697,
    2009,  3911,  1130,  5860,  1038, -1697,   424,  1039, 11591, 11617,
   11643, 11669, 11695,  6316,  1808,  2010,  1809, 13075,  1056,  9665,
   -1697, -1697,  9776,   -76,   -76,   905,  2011,   905,  2012,   905,
    2013, -1697, -1697, -1697, -1697,   905,  2017,  8744,  2019,  9776,
    9776,  9776,  9776,  9776, -1697, -1697, -1697, 10208, -1697,  1810,
    2020,  9693,   426,   432,  1411, -1697,  1813,  1466, -1697,  1829,
    1485, -1697,  1831,  1536, -1697,  1057, -1697,  5728, 11721, 11747,
   11773, 11799,  1065, -1697,  1832,  6440, -1697,  2042,  9776,  9776,
    2046,   905,  2047,   905,  2048,   905, -1697,  2049, -1697,  9776,
    9776,  9776,  9776, 10208,  2052, 10208,  1070, -1697, 10098, 10126,
   -1697,  1609, -1697,  1766, -1697,  1840, -1697, 10154, 10204, 10232,
   10260, -1697, -1697,  1074, -1697,  2054,  2055,  2060,  2062,  2063,
    2067, -1697, -1697, -1697, -1697, 10208,  2092, -1697, -1697, -1697,
   -1697, -1697, -1697, -1697, -1697
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1697, -1697, -1697, -1697,   846, -1697, -1697, -1697, -1697,   207,
   -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697,
   -1697, -1697,  -313,   -90,  1635,  3378, -1697,  1621, -1697, -1697,
   -1697, -1697, -1697, -1697, -1697, -1696, -1697,   377, -1697, -1697,
   -1697, -1697, -1697, -1697,   835,  2100,    11,  -529,  -242, -1697,
   -1697, -1697, -1697, -1697, -1697, -1697, -1697,  2101, -1697, -1697,
   -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697, -1697,
   -1697, -1102, -1099, -1697,   556,  2103, -1697, -1697,  1596, -1697,
     369, -1697, -1697, -1697, -1697,  1969, -1697, -1697,    93, -1697,
   -1275,  2529,   318,  2421,  3131,  -261,   683, -1697,   131,    68,
   -1697,  -395,    -3,   267
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -541
static const yytype_int16 yytable[] =
{
     117,   583,   528,   202,   671,  1171,   673,  1475,   559,   823,
     824,   373,  1456,   342,   101,  1328,  1330,  1566,   288,  1015,
     436,   688,   227,   357,   586,   588,   590,  1800,   372,   331,
    1319,   205,  1321,  1031,   232,   227,   547,  1004,   232,  1223,
     280,   612,     5,   348,   350,   877,   196,  1323,   562,   879,
     881,   883,   206,   208,  1914,  1325,   536,   537,  1445,   291,
     335,   536,   537,  1105,   204,  1258,   293,   325,   294,   223,
     536,   537,   291,   538,   201,   745,   224,  1106,   539,  1923,
     746,   536,   537,   291,   263,  1107,  1108,  1109,  1309,  1925,
     749,  1110,  1111,  1112,  1113,   750,   991,  1498,   752,  1499,
     264,   265,   360,   753,   361,   536,   537,   624,     4,   626,
     701,   362,   536,   537,   633,   536,   537,   207,   364,   703,
     281,   707,   549,   710,   282,   267,   268,   705,  1500,   550,
    1501,  1502,   214,  1503,   709,   269,   551,   200,   283,   536,
     537,   223,   270,   210,   271,   273,   295,   279,  1008,   991,
     536,   537,   584,   211,   343,   818,   347,   973,  1016,  1017,
    1018,  1019,   753,   536,   537,  1320,   825,  1322,   212,   437,
     438,  1917,  1918,  1327,   213,   587,   589,   591,   289,   831,
    1422,  1567,  1324,   536,   537,   369,   370,   215,  1224,  1225,
    1326,   291,  1346,   536,   537,   917,    95,   259,   235,  1305,
     260,    95,   921,   472,   472,  1011,   441,   536,   537,  1329,
     216,   472,    95,  1172,   585,  1491,  1492,   560,   374,   291,
     375,   325,   376,   217,   196,  1032,   325,   196,   358,   228,
     325,  1328,   290,   325,  1020,   359,   229,   325,   325,   325,
     325,   472,   228,   332,  1659,   325,   325,   325,   233,  1009,
    1032,  1005,  1010,   325,   325,   325,   349,   351,   878,   325,
     291,   602,   880,   882,   884,   209,  1915,   336,   218,  1259,
     118,  1260,   225,   203,   536,   537,   226,   365,   366,   367,
     368,   325,   325,   325,   536,   537,   991,   816,   817,   480,
     230,   365,   366,   367,   702,   325,   325,   369,   370,   365,
     366,   367,   368,   231,   997,   536,   537,   832,   365,   366,
     367,   706,   325,  1677,   325,   365,   366,   367,   368,   369,
     370,  1654,   236,   919,   219,   923,   220,   536,   537,   292,
     365,   366,   367,   368,   234,   369,   370,   470,   474,  1733,
     369,   370,   334,  1747,   369,   370,   711,   763,   239,   764,
     369,   370,   472,   344,  -534,   325,   325,   536,   537,   531,
     532,   365,   366,   367,   368,  1253,   235,   540,   325,  1256,
     763,   548,   901,  1749,   763,   505,   365,   366,   367,   918,
     237,   369,   370,   365,   366,   367,   922,   910,   284,   298,
     285,   992,   299,   536,   537,   998,   472,   472,   472,   472,
     472,   472,   472,   472,   472,   472,   325,   472,   472,  1751,
     472,   472,   472,   472,   472,   536,   537,   238,   472,   472,
     472,   472,   472,   291,   240,   291,   369,   370,   536,   537,
     244,  1759,   642,   458,   459,   460,  -539,   577,   754,   578,
     461,   755,   325,  1796,  1761,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   603,   459,   460,   536,
     537,   439,  1812,   461,   246,   369,   370,   365,   366,   367,
     368,  1143,  1650,   473,   473,  1762,   763,   440,   769,   275,
     325,   473,   276,   369,   370,   277,   632,   691,   252,   481,
     763,   253,   773,  -537,   254,   699,   255,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   473,   536,   537,   245,   461,   536,   537,  1713,   241,
     325,   325,   242,  1714,  1678,   243,   757,   446,  1883,   755,
     334,   672,  1886,   674,   675,   676,   677,   678,   679,   680,
     247,   682,   683,   251,   685,   686,   687,   261,   689,   441,
     441,   262,   693,   694,   695,   696,   697,   266,   932,   502,
     503,   504,   325,   325,   325,   274,   509,   510,   511,   536,
     537,  1546,  1547,  1092,   325,   325,   536,   537,   472,   536,
     537,   794,   797,   800,   803,  1889,    50,    51,    52,    53,
     536,   537,  1897,   325,   286,  1899,   267,   268,    61,   287,
     325,    64,   555,   556,   536,   537,   269,  1184,   536,   537,
    1370,  1189,   300,   278,   993,   296,   568,   569,   999,   325,
    1963,   858,   473,   859,  1964,   536,   537,   536,   537,   821,
     822,  1105,   297,   536,   537,   301,   328,   532,   325,   302,
    1958,  1977,   464,  2018,   465,  1106,  1826,   327,  1829,  2019,
    1832,   362,   329,  1107,  1108,  1109,   605,   330,   606,  1110,
    1111,  1112,  1113,   337,   338,   362,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   339,   473,   473,   341,
     473,   473,   473,   473,   473,   340,   369,   370,   473,   473,
     473,   473,   473,   698,   345,   700,  -538,   369,   370,   355,
     325,   369,   370,   858,   325,   859,   356,  -536,  1264,   860,
    1265,  -540,   870,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,  1328,  1813,  1814,
    1328,   461,   420,  1328,  1815,   402,   630,   747,   631,   748,
    2036,  1515,   403,   325,  1232,   362,   362,   325,   404,   409,
     472,  1105,   416,   291,   573,   472,   574,   421,   575,   325,
     325,   195,   422,   196,  1289,  1106,  1291,   932,  1293,   763,
    1295,   779,   423,  1107,  1108,  1109,   763,  1000,   887,  1110,
    1111,  1112,  1113,   592,   426,   325,   593,   248,   427,   594,
     249,   595,   250,  1942,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   256,   325,
     428,   257,   461,   258,  1371,   456,   457,   458,   459,   460,
    1416,  1417,   444,   445,   461,  1420,  1421,   627,  1047,   628,
    1185,   575,   463,   742,  1190,   743,   196,   744,   462,   467,
    1194,  1196,   196,  1328,   858,   867,   859,   489,   473,   858,
     894,   859,  1817,  1818,   753,   494,   499,   325,  1815,   325,
     507,  1884,   325,  1994,   858,  1997,   859,  2000,   915,   956,
     916,   500,   763,  2003,  1013,   325,   508,   325,   858,   325,
     859,   325,   512,   981,  1041,   858,   325,   859,   513,  1045,
     983,   325,   858,   514,   859,  1328,   515,   763,  1328,   523,
     858,  1328,   859,   516,  1328,  1405,   763,   763,  1088,  1089,
    1423,  1095,   325,   763,   526,  1130,   325,   552,  1101,  2041,
     325,  2043,   529,  2045,  1116,   858,  1436,   859,   472,   763,
    1408,  1131,   741,   763,   553,  1132,  1247,  1248,  1270,   763,
    1271,  1157,  1328,   763,  1328,  1173,  1328,   763,   763,  1192,
    1302,   530,   763,   325,  1347,   763,   554,  1348,   472,   977,
     763,   558,  1349,   325,   472,   472,   472,  1638,  1639,  1428,
     763,   763,  1357,  1358,   541,   763,   472,  1359,   472,   763,
     763,  1360,  1362,   542,  1553,  1554,   763,  1105,  1363,  1557,
    1558,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     543,  1106,   291,   561,   461,   325,   325,   325,   325,  1107,
    1108,  1109,   362,   563,  1105,  1110,  1111,  1112,  1113,  1430,
     473,  1431,   763,  1043,  1432,   473,   564,   763,  1106,  1433,
     472,   763,   763,  1434,  1435,   565,  1107,  1108,  1109,   566,
     469,   121,  1110,  1111,  1112,  1113,  1194,  1196,   567,   325,
     325,   763,   325,  1474,   325,   325,   570,   571,   325,   325,
     604,   608,  1197,   325,  1591,   572,  1592,  1591,   615,  1615,
    1247,  1248,  1626,   763,  1627,  1663,  1560,  1719,   196,  1720,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   763,
     620,  1738,  1203,   161,   162,   163,   164,  1887,  1206,  1207,
    1208,   166,   167,   168,   614,   763,   169,  1739,   621,  1591,
    1212,  1760,  1213,  1591,  1834,  1810,  1835,   174,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   622,  1424,  1549,   763,   461,  1851,   469,   121,
    1854,  1263,  1855,   623,   625,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   640,
     325,   325,   325,   461,  1252,  1229,   753,   644,  1858,  1581,
     641,  1591,  1405,  1863,  1865,   325,   645,   648,   148,   149,
     150,   151,   152,   153,   154,   155,   156,  1408,  1591,  1866,
    1871,   161,   162,   163,   164,  1310,  1311,  1312,   473,   166,
     167,   168,  1105,   763,   169,  1879,   461,   712,   177,   178,
     179,   713,   472,   472,  1821,   174,  1106,   472,   472,   763,
     186,  1898,   187,    95,  1107,  1108,  1109,   291,   473,   195,
    1110,  1111,  1112,  1113,   473,   473,   473,   715,  1719,  1105,
    1955,   325,   759,   760,   369,   370,   473,  1405,   473,  1960,
    1405,  1195,  1961,  1106,  -535,   763,   763,  1976,  1978,   776,
     780,  1107,  1108,  1109,   781,   325,  1278,  1110,  1111,  1112,
    1113,   325,   334,  1591,   763,  1989,  2027,   325,   782,   325,
     325,   325,  2033,   783,  2034,   325,   325,  1591,   325,  2055,
     325,  2065,   325,  2066,   325,   325,   325,   787,   788,   805,
     473,  1561,   807,   809,  1789,   814,   177,   178,   179,   813,
     815,   838,  1890,   325,   840,   872,   841,   843,   186,   850,
     187,    95,   851,   857,   874,   875,  1451,   876,   325,   899,
       7,     8,   325,   902,   325,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   858,   911,   859,  1973,
     461,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   914,   927,   928,   959,   461,
     960,   961,   964,   988,   966,   989,   472,   472,   980,   967,
     968,   472,   472,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   472,   978,   979,   985,   461,
     986,   472,   716,    24,    25,   717,    27,    28,   718,    30,
     719,    32,   987,    33,   994,   995,  1002,  1003,    38,    39,
      40,    41,  1514,    43,    44,    45,  1030,   291,  1048,    48,
    1037,  1040,  1042,   325,  1044,  1051,  1052,  1561,  1053,  1055,
    1056,  1057,  1548,   472,  1058,  1060,   325,  1061,  1790,  1062,
    1066,  1067,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,    72,    73,    74,  1068,
     461,  1073,  1078,  1077,  1075,  1098,  1079,  1125,  1081,  1163,
    1083,  1140,   473,   473,  1080,   325,   325,   473,   473,  1091,
    1574,     7,     8,  1082,  1084,  1142,  1148,   334,  1164,  1099,
    1150,  1151,  1165,  1152,  1180,  1177,  1178,   441,   441,  1166,
    1217,  1219,  1222,  1181,   325,  1837,   325,  1599,   325,  1182,
    1105,  1186,  1187,  1227,  1228,  1231,  1230,  1234,  1242,  1562,
    1246,  1243,  1244,  1251,  1106,  1564,  1268,   846,   325,  1274,
    1275,  1279,  1107,  1108,  1109,  1280,  1282,   325,  1110,  1111,
    1112,  1113,  1604,  1283,  1284,  1287,  1316,   325,  1288,  1297,
    1633,  1298,   325,   716,    24,    25,   717,    27,    28,   718,
      30,   719,    32,  1299,    33,  1105,  1300,  1596,  1301,    38,
      39,    40,    41,  1303,    43,    44,    45,  1313,   325,  1106,
      48,  1640,  1317,  1643,  1105,  1646,  1318,  1107,  1108,  1109,
    1331,  1332,  1337,  1110,  1111,  1112,  1113,  1333,  1106,  1334,
    1657,   325,  1335,  1660,  1661,  1682,  1107,  1108,  1109,  1338,
    1339,  1340,  1110,  1111,  1112,  1113,  1342,    72,    73,    74,
    2020,  1341,  1343,  1698,  1701,  1702,  1344,  1367,  1372,  1378,
    1373,  1376,  1391,  1381,  1374,  1105,   473,   473,   325,  1383,
    1386,   473,   473,   325,  1943,  1388,   221,   222,  1390,  1106,
    1392,  1398,  1401,  1404,  1412,   473,  1425,  1107,  1108,  1109,
    1336,   473,  1426,  1110,  1111,  1112,  1113,   325,  1442,  1443,
    1444,  1437,  1447,  1454,  1455,  2022,  1452,  1453,  1463,  1459,
    1466,  1467,  1470,   325,  1457,  1471,   472,   334,   908,  1458,
    1464,  1465,  1469,  1472,  2024,  1478,   291,  1488,  1479,  1509,
    1489,  1490,  1496,   473,  1497,   325,  1504,  1510,  1105,  1511,
    1512,  1527,   325,   325,  1529,  1519,  1520,  1524,  1530,  1539,
    1540,  1545,  1106,  1541,   325,  1551,  1568,   325,  1565,  1550,
    1107,  1108,  1109,  1571,     7,     8,  1110,  1111,  1112,  1113,
    1576,  1778,   363,   325,   441,  2026,  1577,  1579,   325,  1582,
    1583,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,  1584,  1585,  1595,   405,
     406,   407,   408,  1600,   410,   411,   412,   413,   414,   415,
    1601,  1605,   417,  1606,  1607,  1610,  1613,  1375,   418,   419,
    1612,  1617,   325,  1616,   424,   425,   716,    24,    25,   717,
      27,    28,   718,    30,   719,    32,  1614,    33,  2058,  1620,
    1621,   325,    38,    39,    40,    41,  1622,    43,    44,    45,
    1825,  1623,  1828,    48,  1831,  1624,  1651,  1418,  1625,  1628,
    1641,  1644,  1839,  1647,   291,  1842,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
    1655,  1658,  1662,  1666,   461,  1105,  1683,  1686,  1689,  1693,
      72,    73,    74,  1703,  1704,  1705,  1706,  1707,  1710,  1106,
    1709,  1712,  1721,  1718,   325,  1711,   325,  1107,  1108,  1109,
    1732,  1725,  1734,  1110,  1111,  1112,  1113,  1873,  1726,  1735,
    1736,  1877,   325,  1737,  1742,  1743,  1754,  1763,  1745,  1746,
    1756,  1772,  1777,  1748,  1909,  1750,  1752,  1757,  1781,  1779,
    1782,  1780,  1783,  1784,  1785,  1798,  1791,  1804,   576,  1805,
    1806,   579,   580,   581,   582,  1807,  1808,  1809,  1833,  1105,
    1840,   909,  1852,  1811,  1853,  1880,  1857,  1859,  1875,  1860,
     607,  1869,  1878,  1106,  1872,  1922,   473,  1876,  1892,  1924,
    1893,  1107,  1108,  1109,   325,   198,   334,  1110,  1111,  1112,
    1113,  1896,  1906,  1907,   472,  2059,  1921,  1926,  1928,  1931,
    1932,  1935,  1946,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,  1936,  1939,  1940,
    1945,   461,   325,  1954,  1965,  1971,  1986,  1995,  1998,  2001,
    1985,  1984,  1967,  2004,  1969,  2006,  2016,  1987,  2015,  1427,
     472,  2021,   472,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,  2023,  2037,  2025,
    2035,   461,  2040,  2042,  2044,  2046,  1992,  1993,  2052,  2060,
    2067,  2068,   472,   353,   119,   352,  2069,  1911,  2070,  2071,
     122,   123,   124,  2072,   714,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,  2074,  1446,
     758,  1801,  1461,   100,   110,  1684,   112,   790,  1819,  1578,
       0,     0,     0,     0,   157,   158,   159,   160,  2013,     0,
       0,     0,   165,     0,  1910,     0,     0,  1505,     0,     0,
       0,     0,     0,   170,   171,   172,     0,     0,     0,     0,
       0,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   429,   430,   431,
     433,   435,     0,     0,  2051,     0,  2054,     0,     0,     0,
       0,     0,     0,     0,   468,     0,     0,     0,   475,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,   484,   487,   488,  2073,   490,   484,   492,
     493,     0,   484,   496,   497,  1555,     0,     0,     0,   484,
       0,     0,     0,     0,   506,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   525,
       0,     0,   176,   461,     0,     0,   180,     0,   534,   535,
     181,   182,   183,   184,   185,     0,     0,   535,    95,  1559,
       0,     0,     0,     0,   473,     0,     0,     0,     0,     0,
       0,     0,   188,   189,     0,     0,     0,   190,     0,     0,
       0,     0,   316,     0,     0,     0,     0,   194,     0,   524,
       0,     0,     0,     0,   597,   599,   484,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   609,   610,   611,
     473,   613,   473,     0,     0,   616,   617,   618,     0,     0,
     619,     0,     0,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,   637,
     639,   461,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   646,   647,     0,   649,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   660,   661,   662,
     663,   664,   665,   666,   667,   668,   669,   670,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   684,     0,     0,     0,     0,     0,   690,     0,   692,
    1665,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,     0,     0,   721,   484,     0,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   734,   735,   736,
     737,     0,     0,   739,   740,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,   597,   461,     0,     0,     0,     0,   767,     0,
       0,     0,     0,   772,     0,     0,     0,     0,   777,   778,
       0,     0,     0,     0,     0,     0,   785,   786,  1708,     0,
       0,   791,   793,   796,   799,   802,   804,     0,   806,     0,
     808,     0,   484,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     826,   827,   828,   429,   430,   829,     0,     0,     0,   833,
     834,   835,   836,   837,     0,     0,     0,   842,     0,   844,
     845,     0,     0,     0,   484,   484,   484,     0,     0,   852,
     853,   854,   855,   856,     0,     0,   863,   863,   868,   869,
       0,   871,     0,     0,   873,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   484,     0,     0,     0,     0,
       0,   888,   890,     0,   892,   893,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
       0,   484,     0,     0,   461,     0,   855,   856,     0,   892,
     893,     0,     0,     0,     0,     0,     0,     0,     0,   925,
     484,     7,     8,     0,   929,     0,     0,     0,     0,     0,
       0,     0,     0,  1215,  1216,     0,     0,     0,     0,  1220,
    1221,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   485,     0,     0,     0,   461,
     485,     0,     0,     0,   485,     0,  1636,     0,  1637,     0,
       0,   485,     0,     0,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,     0,  1001,
       0,     0,   461,   716,    24,    25,   717,    27,    28,   718,
      30,   719,    32,     0,    33,     0,     0,     0,     0,    38,
      39,    40,    41,     0,    43,    44,    45,     0,     0,     0,
      48,  1028,  1029,     0,     0,   484,  1035,  1036,     0,   484,
    1039,     0,     0,     0,     0,     0,     0,     0,  1046,     0,
       0,   890,  1049,     0,     0,     0,   598,     0,   485,     0,
       0,     0,     0,     0,     0,  1063,     0,    72,    73,    74,
       0,     0,     0,     0,     0,     0,  1071,     0,     0,     0,
       0,     0,     0,     0,     0,   498,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
       0,   484,     0,     0,   461,   518,   520,   522,  1096,  1097,
       0,   527,     0,  1012,  1100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1124,     0,     0,
    1126,     0,     0,     0,     0,   557,  1379,  1380,  1093,     0,
       0,  1384,  1385,     0,     0,     0,     0,     0,     0,   484,
       0,   484,     0,     0,   484,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,     0,   484,
       0,   484,     0,   484,     0,     0,     0,     0,   484,     0,
       0,     0,     0,   484,     0,     0,   485,     0,     0,  1167,
       0,  1169,  1170,     0,     0,     0,     0,     0,     0,     0,
       0,  1176,     0,     0,     0,     0,     0,   634,   635,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     643,     0,     0,     0,   598,     0,     0,     0,     0,     0,
       0,     0,     0,  1198,     0,     0,     0,     0,     0,     0,
       0,  1199,  1200,  1201,     0,   484,     0,     0,     0,     0,
       0,     0,     0,  1204,     0,     0,     0,     0,   681,     0,
       0,     0,     0,     0,   485,   485,     0,  1211,     0,     0,
       0,     0,  1214,     0,     0,     0,     0,     0,     0,     0,
       0,  1218,     0,     0,     0,     0,     0,  1226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,   484,   484,
     484,     0,     0,  1240,     0,     0,   485,   485,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   864,   866,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   485,     0,     0,
       0,     0,     0,     0,   891,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   484,     0,     0,     0,     0,
       0,     0,     0,   485,     0,     0,     0,  1290,     0,  1292,
       0,  1294,  1741,  1296,     0,     0,     0,     7,     8,     0,
       0,     0,   485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1315,     0,     0,   716,    24,
      25,   717,    27,    28,   718,    30,   719,    32,     0,    33,
       0,     0,     0,     0,    38,    39,    40,    41,     0,    43,
      44,    45,     0,     0,  1345,    48,     0,     0,     0,     0,
       0,     0,     0,  1350,  1351,     0,  1352,  1353,     0,  1354,
    1355,  1356,     0,     0,     0,     0,     0,  1361,     0,   716,
      24,    25,   717,    27,    28,   718,    30,   719,    32,     0,
      33,     0,    72,    73,    74,    38,    39,    40,    41,     0,
      43,    44,    45,  1382,     0,     0,    48,     0,  1387,     0,
       0,     0,     0,     0,     0,     0,     0,   485,     0,     0,
       0,   485,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   891,  1050,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    73,    74,     0,     0,     0,     0,
    1429,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1438,  1439,  1094,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1448,  1450,     0,     0,
       0,     0,   990,   485,     0,     0,   996,     0,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,     0,     7,     8,     0,   461,     0,     0,     0,
       0,     0,     0,     0,  1117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1493,  1494,  1495,     0,     0,     0,
       0,   485,     0,   485,     0,  1506,   485,  1508,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1513,   485,
       0,   485,     0,   485,     0,   485,   484,     0,     0,     0,
     485,  1525,     0,     0,     0,   485,     0,  1072,     0,     0,
       0,     0,     0,     0,     0,   716,    24,    25,   717,    27,
      28,   718,    30,   719,    32,  1776,    33,  1542,  1543,  1544,
       0,    38,    39,    40,    41,     0,    43,    44,    45,     0,
       0,     0,    48,     0,     0,   486,     0,     0,     0,     0,
     491,     0,     0,     0,   495,     0,     0,     0,  1563,     0,
       0,   501,     0,     0,     0,     0,     0,   485,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,    74,  1575,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1588,     0,     0,     0,
       0,  1594,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1602,  1603,     0,   485,
     485,   485,   485,  1608,  1609,     0,     0,     0,  1611,     0,
       0,     0,     0,     0,  1179,     0,     0,  1619,  1183,     0,
       0,     0,  1188,     0,     0,     0,     0,   484,   484,  1631,
    1168,  1632,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1649,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   484,   485,     0,     0,
     484,     0,     0,  1664,     0,  1205,     0,     0,     0,     0,
    1667,  1668,  1669,  1670,  1671,  1672,  1673,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1681,     0,     0,     0,
       0,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,  1700,     0,     0,     0,   461,
       0,     7,     8,     0,     0,     0,   716,    24,    25,   717,
      27,    28,   718,    30,   719,    32,     0,    33,  1715,  1716,
       0,     0,    38,    39,    40,    41,  1722,    43,    44,    45,
       0,     0,     0,    48,     0,     0,   722,     0,     0,     0,
       0,  1266,  1267,     0,  1269,     0,  1272,  1273,     0,     0,
    1276,  1277,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1744,     0,     0,     0,     0,
      72,    73,    74,   716,    24,    25,   717,    27,    28,   718,
      30,   719,    32,  1758,    33,   597,     0,     0,     0,    38,
      39,    40,    41,     0,    43,    44,    45,     0,     0,     0,
      48,     0,     0,     0,  1773,     0,  1774,     0,     0,   484,
       0,     0,     0,     0,   810,   811,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1787,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    73,    74,
       0,  1174,     0,  1793,     0,     0,     0,     0,  1797,     0,
       0,     0,  1364,  1365,  1366,     0,   847,   848,   849,     0,
    1905,     0,     0,     0,     0,     0,     0,  1377,     0,   484,
       0,     0,     0,     0,     0,     0,  1824,     0,  1827,     0,
    1830,     0,     0,     0,     0,     0,     0,   885,     0,     0,
     484,     0,     0,     0,     0,     0,  1843,  1844,  1845,  1846,
    1847,  1848,     0,     0,     0,     0,     0,     0,  1304,     0,
       0,     0,     0,   907,     0,     0,     0,     0,   485,     0,
       0,     0,     0,  1861,  1862,     0,     0,     0,  1864,     0,
       0,     0,   926,  1441,     0,     0,     0,     0,     0,     0,
    1870,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1881,     0,     0,     0,     0,     0,  1462,     0,     0,
       0,     0,     0,  1468,     0,     0,     0,     0,     0,  1473,
       0,  1441,  1476,  1477,     0,     0,     0,  1480,  1481,     0,
    1482,     0,  1483,  1908,  1484,     0,  1485,  1486,  1487,  1594,
       0,     0,     0,     0,     0,     0,     0,     0,  1919,     0,
       0,     0,     0,     0,     0,  1507,     7,     8,     0,     0,
       0,     0,  1930,     0,     0,  1934,     0,     0,  1938,     0,
    1518,     0,  1941,     0,  1522,     0,   484,     0,   484,  1948,
    1949,  1950,  1951,  1952,     0,     0,     0,  1034,     0,     0,
       0,  1038,  1957,     0,     0,  1959,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
       0,     0,     0,     0,   461,     0,     0,     0,     0,   485,
     485,     0,     0,     0,     0,     0,     0,  1972,   716,    24,
      25,   717,    27,    28,   718,    30,   719,    32,     0,    33,
       0,  1991,     0,     0,    38,    39,    40,    41,   485,    43,
      44,    45,   485,  1090,     0,    48,   484,     0,  2007,  2008,
    2009,  2010,  2011,     0,     0,     0,     0,     0,     0,  1856,
     602,     0,     0,     0,     0,  1586,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1598,     0,
    1953,     0,    72,    73,    74,   895,     0,  2038,  2039,     0,
       0,  1138,     0,  1139,     0,     0,  1141,     0,  2047,  2048,
    2049,  2050,     0,     0,     0,     0,     0,     0,     0,  1153,
       0,  1154,     0,  1155,     0,  1156,     0,     0,     0,     0,
    1159,     0,     0,     0,     0,  1162,     0,   933,   934,   935,
     936,   937,   938,   939,   940,   941,   942,   943,     0,   945,
     946,   947,   948,   949,   950,   951,     0,     0,  1441,   955,
     957,   958,     0,  1894,     0,   962,   963,     0,   965,     0,
       0,     0,     0,   970,   971,   972,     0,   974,     0,     0,
    1674,     0,     0,     0,   982,   984,     0,   598,     0,  1685,
       0,     0,     0,     0,     0,     0,     0,  1202,     0,  1692,
       0,     0,  1007,     0,  1697,     0,     0,     0,     0,     0,
       0,   485,   602,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,  1788,     0,     0,
    1717,   461,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   602,     0,  1235,
    1236,  1237,  1238,  1441,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   762,   459,   460,     0,     0,
       0,   485,   461,   903,     0,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
    1755,     0,   485,   461,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1281,     0,     0,
       0,     0,     0,     0,     0,     0,   119,   352,     0,     0,
       0,     0,   122,   123,   124,     0,     0,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
       0,     0,     0,     0,     0,     0,     0,  1441,  1146,     0,
       0,     0,     0,     0,  1802,  1803,   157,   158,   159,   160,
       0,     0,     0,     0,   165,     0,  1441,     0,     0,     0,
       0,     0,     0,     0,     0,   170,   171,   172,     0,     0,
       0,     0,     0,   173,     0,  1836,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   603,   459,   460,
       0,     0,     0,     0,   461,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   485,     0,
     485,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   762,   459,   460,  1014,     0,     0,     0,   461,
       0,     0,     0,     0,  1874,     0,     0,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,  1158,     0,  1891,     0,   461,     0,     0,     0,     0,
       0,     0,     0,     0,   176,     0,     0,     0,   180,     0,
       0,     0,   181,   182,   183,   184,   185,     0,     0,     0,
      95,  1239,     0,     0,     0,     0,     0,     0,   485,     0,
       0,     0,     0,     0,   544,   545,     0,     0,     0,   190,
       0,     0,     0,     0,   546,     0,     0,     0,     0,   194,
       0,   270,     0,     0,  1261,  1262,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   120,   121,     0,     0,     0,
     122,   123,   124,     0,  1441,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,  1523,     0,
       0,     0,     0,     0,     0,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,     0,     0,     0,   166,   167,   168,     0,
       0,   169,     0,   170,   171,   172,     0,     0,     0,     0,
       0,   173,   174,     0,     0,     0,     0,     0,     0,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,  1441,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
    1389,     0,     0,     0,     0,     0,  1393,  1394,  1395,  1396,
    1397,     0,  1400,     0,  1402,  1403,     0,  1406,  1409,     0,
       0,  1413,  1414,  1415,     0,   175,     0,     0,  1419,     0,
       0,     0,   176,   177,   178,   179,   180,     0,     0,     0,
     181,   182,   183,   184,   185,   186,     0,   187,    95,  1629,
    1630,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   188,   189,     0,     0,     0,   190,     0,     0,
       0,     0,   191,     0,   192,     0,   193,   194,     0,   195,
       0,   196,     0,   119,   303,     0,     0,     0,     0,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   305,   306,   307,
     308,   309,     0,     0,     0,     0,  1285,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,     0,     0,     0,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,  1528,     0,     0,     0,     0,
     173,     0,     0,     0,   310,     0,     0,   311,     0,     0,
     312,  1538,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,  1552,     0,     0,
       0,     0,  1556,    50,    51,    52,    53,    54,     0,     0,
      56,    57,    58,     0,     0,    61,     0,     0,    64,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,  1569,  1570,     0,   461,  1572,  1573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1775,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,     0,     0,   180,     0,     0,     0,   181,
     182,   183,   184,   185,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1369,     0,     0,
       0,   544,  1656,     0,     0,     0,   190,     0,     0,     0,
       0,   546,     0,     0,     0,     0,   194,     0,   270,   600,
       0,  1820,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,     0,   119,   303,     0,
     461,     0,  1841,   122,   123,   124,     0,   751,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   305,   306,   307,   308,   309,     0,     0,     0,     0,
       0,  1687,  1688,     0,     0,  1690,  1691,   157,   158,   159,
     160,  1694,  1695,     0,     0,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   170,   171,   172,     0,
       0,     0,     0,     0,   173,     0,     0,     0,   310,     0,
       0,   311,     0,     0,   312,     0,   313,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     314,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,    54,     0,     0,    56,    57,    58,     0,     0,    61,
       0,     0,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1944,     0,
    1947,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,  1765,  1766,     0,     0,   461,
       0,     0,     0,     0,     0,   176,     0,     0,     0,   180,
       0,     0,     0,   181,   182,   183,   184,   185,     0,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   188,   483,     0,     0,     0,
     190,     0,     0,     0,     0,   316,     0,     0,     0,     0,
     194,     0,     0,   600,   119,   303,   121,     0,  2005,     0,
     122,   123,   124,     0,     0,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   305,   306,
     307,   308,   309,     0,     0,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,     7,     8,     0,   166,   167,   168,     0,
       0,   169,     0,   170,   171,   172,     0,     0,     0,     0,
       0,   173,   174,     0,     0,   310,     0,     0,   311,     0,
       0,   312,     0,   313,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   314,     0,     0,
       0,     0,     0,     0,    50,    51,    52,    53,    54,     0,
       0,    56,    57,    58,     0,     0,    61,     0,     0,    64,
       0,     0,     0,     0,     0,   716,    24,    25,   717,    27,
      28,   718,    30,   719,    32,     0,    33,     0,     0,     0,
       0,    38,    39,    40,    41,     0,    43,    44,    45,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,   177,   178,   179,   180,   912,     0,     0,
     181,   182,   183,   184,   185,   186,     0,   187,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,    74,   188,   315,     0,     0,     0,   190,     0,     0,
       0,     0,   316,     0,     0,     0,     0,   194,     0,   317,
     119,   303,   121,     0,     0,     0,   122,   123,   124,     0,
       0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   305,   306,   307,   308,   309,     0,
       0,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     7,
       8,     0,   166,   167,   168,  2028,     0,   169,     0,   170,
     171,   172,     0,     0,     0,     0,     0,   173,   174,     0,
       0,   310,     0,     0,   311,     0,     0,   312,     0,   313,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   314,     0,     0,     0,     0,     0,     0,
      50,    51,    52,    53,    54,     0,     0,    56,    57,    58,
       0,     0,    61,     0,     0,    64,     0,     0,     0,     0,
       0,   716,    24,    25,   717,    27,    28,   718,    30,   719,
      32,     0,    33,     0,     0,     0,     0,    38,    39,    40,
      41,     0,    43,    44,    45,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   176,   177,
     178,   179,   180,     0,     0,     0,   181,   182,   183,   184,
     185,   186,     0,   187,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,    73,    74,   188,   315,
       0,     0,     0,   190,     0,     0,     0,     0,   316,     0,
     119,   352,   121,   194,     0,  1696,   122,   123,   124,     0,
       0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,     0,     0,     0,     0,     0,     0,
       0,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     0,
       0,     0,   166,   167,   168,     0,     0,   169,     0,   170,
     171,   172,     0,   119,   352,   121,     0,   173,   174,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,     0,     0,     0,
       0,     0,     0,     0,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     0,     0,     0,   166,   167,   168,     0,     0,
     169,     0,   170,   171,   172,     0,     0,     0,     0,     0,
     173,   174,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   176,   177,
     178,   179,   180,     0,     0,     0,   181,   182,   183,   184,
     185,   186,     0,   187,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   188,   189,
       0,     0,     0,   190,     0,     0,     0,     0,   316,     0,
       0,     0,     0,   194,     0,  1449,     0,     0,     0,     0,
       0,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,   176,   177,   178,   179,   180,  1675,     0,  1676,   181,
     182,   183,   184,   185,   186,     0,   187,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   189,     0,     0,     0,   190,     0,     0,     0,
       0,   316,     0,   119,   352,   121,   194,     0,  1680,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,     0,     0,     0,
       0,     0,     0,     0,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     7,     8,     0,   166,   167,   168,     0,     0,
     169,     0,   170,   171,   172,     0,     0,     0,     0,     0,
     173,   174,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,     0,     0,     0,     0,
     461,     0,     0,     0,     0,     0,     0,  1822,     0,  1823,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,     0,     0,     0,     0,   461,     0,
     858,     0,   859,     0,   716,    24,    25,   717,    27,    28,
     718,    30,   719,    32,     0,    33,     0,     0,     0,     0,
      38,    39,    40,    41,     0,    43,    44,    45,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,   177,   178,   179,   180,     0,     0,     0,   181,
     182,   183,   184,   185,   186,     0,   187,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
      74,   188,   189,     0,     0,     0,   190,     0,     0,     0,
       0,   316,     0,   119,   303,   304,   194,     0,  1699,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   305,   306,   307,
     308,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,     0,     0,  1974,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,     0,     0,     0,     0,     0,
     173,     0,     0,     0,   310,     0,     0,   311,     0,     0,
     312,     0,   313,     0,     0,     0,     0,     0,     0,   346,
     121,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
      56,    57,    58,     0,     0,    61,     0,     0,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
     149,   150,   151,   152,   153,   154,   155,   156,     0,     0,
       0,     0,   161,   162,   163,   164,     0,     0,     0,     0,
     166,   167,   168,     0,     0,   169,     0,     0,     0,     0,
       0,   176,     0,     0,     0,   180,   174,     0,     0,   181,
     182,   183,   184,   185,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   315,     0,     0,     0,   190,     0,     0,     0,
       0,   316,     0,   119,   303,  1516,   194,     0,   317,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   305,   306,   307,
     308,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,   177,   178,   179,
       0,   165,     0,     0,     0,     0,     0,     0,     0,   186,
       0,   187,   170,   171,   172,     0,     0,     0,     0,     0,
     173,     0,     0,     0,   310,     0,     0,   311,     0,     0,
     312,   121,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
      56,    57,    58,     0,     0,    61,     0,     0,    64,     0,
     148,   149,   150,   151,   152,   153,   154,   155,   156,     0,
       0,     0,     0,   161,   162,   163,   164,     0,     0,     0,
       0,   166,   167,   168,     0,     0,   169,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,     0,     0,
       0,   176,     0,     0,     0,   180,     0,     0,     0,   181,
     182,   183,   184,   185,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   315,     0,     0,     0,   190,     0,     0,     0,
       0,   316,     0,   119,   303,     0,   194,     0,  1517,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   305,   306,   307,
     308,   309,     0,     0,     0,     0,     0,     0,   177,   178,
     179,     0,     0,   157,   158,   159,   160,     0,     0,     0,
     186,   165,   187,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,     0,     0,     0,     0,     0,
     173,     0,     0,     0,   310,     0,     0,   311,     0,     0,
     312,     0,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
      56,    57,    58,     0,     0,    61,     0,     0,    64,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,  1065,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,     0,     0,   180,     0,     0,     0,   181,
     182,   183,   184,   185,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   315,     0,     0,     0,   190,     0,     0,     0,
       0,   316,     0,   119,   303,     0,   194,     0,   317,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   305,   306,   307,
     308,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,     0,     0,     0,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,     0,     0,     0,     0,     0,
     173,     0,     0,     0,   310,     0,     0,   311,     0,     0,
     312,     0,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
      56,    57,    58,     0,     0,    61,     0,     0,    64,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,  1120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,     0,     0,   180,     0,     0,     0,   181,
     182,   183,   184,   185,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   315,     0,     0,     0,   190,     0,     0,     0,
       0,   517,     0,   119,   303,     0,   194,     0,   317,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   305,   306,   307,
     308,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,     0,     0,     0,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,     0,     0,     0,     0,     0,
     173,     0,     0,     0,   310,     0,     0,   311,     0,     0,
     312,     0,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
      56,    57,    58,     0,     0,    61,     0,     0,    64,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,  1149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,     0,     0,   180,     0,     0,     0,   181,
     182,   183,   184,   185,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   315,     0,     0,     0,   190,     0,     0,     0,
       0,   519,     0,   119,   303,     0,   194,     0,   317,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   305,   306,   307,
     308,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,     0,     0,     0,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,     0,     0,     0,     0,     0,
     173,     0,     0,     0,   310,     0,     0,   311,     0,     0,
     312,     0,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
      56,    57,    58,     0,     0,    61,     0,     0,    64,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,  1191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,     0,     0,   180,     0,     0,     0,   181,
     182,   183,   184,   185,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   315,     0,     0,     0,   190,     0,     0,     0,
       0,   521,     0,   119,   303,     0,   194,     0,   317,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   305,   306,   307,
     308,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,     0,     0,     0,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,     0,     0,     0,     0,     0,
     173,     0,     0,     0,   310,     0,     0,   311,     0,     0,
     312,     0,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
      56,    57,    58,     0,     0,    61,     0,     0,    64,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,  1308,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,     0,     0,   180,     0,     0,     0,   181,
     182,   183,   184,   185,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   483,     0,     0,     0,   190,     0,     0,     0,
       0,   316,     0,   119,   303,     0,   194,     0,   596,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   305,   306,   307,
     308,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,     0,     0,     0,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,     0,     0,     0,     0,     0,
     173,     0,     0,     0,   310,     0,     0,   311,     0,     0,
     312,     0,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
      56,    57,    58,     0,     0,    61,     0,     0,    64,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,  1634,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,     0,     0,   180,     0,     0,     0,   181,
     182,   183,   184,   185,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   483,     0,     0,     0,   190,     0,     0,     0,
       0,   316,     0,   119,   303,     0,   194,     0,   862,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   305,   306,   307,
     308,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,     0,     0,     0,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,     0,     0,     0,     0,     0,
     173,     0,     0,     0,   310,     0,     0,   311,     0,     0,
     312,     0,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
      56,    57,    58,     0,     0,    61,     0,     0,    64,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,  1653,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,     0,     0,   180,     0,     0,     0,   181,
     182,   183,   184,   185,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   483,     0,     0,     0,   190,     0,     0,     0,
       0,   316,     0,   119,   303,     0,   194,     0,   865,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   305,   306,   307,
     308,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,     0,     0,     0,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,     0,     0,     0,     0,     0,
     173,     0,     0,     0,   310,     0,     0,   311,     0,     0,
     312,     0,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
      56,    57,    58,     0,     0,    61,     0,     0,    64,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,  1727,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,     0,     0,   180,     0,     0,     0,   181,
     182,   183,   184,   185,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   483,     0,     0,     0,   190,     0,     0,     0,
       0,   316,     0,   119,   303,     0,   194,     0,   889,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   305,   306,   307,
     308,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,     0,     0,     0,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,     0,     0,     0,     0,     0,
     173,     0,     0,     0,   310,     0,     0,   311,     0,     0,
     312,     0,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
      56,    57,    58,     0,     0,    61,     0,     0,    64,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,  1728,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,     0,     0,   180,     0,     0,     0,   181,
     182,   183,   184,   185,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   315,     0,     0,     0,   190,     0,     0,     0,
       0,   316,     0,   119,   303,     0,   194,     0,  1521,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   305,   306,   307,
     308,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,     0,     0,     0,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,     0,     0,     0,     0,     0,
     173,     0,     0,     0,   310,     0,     0,   311,     0,     0,
     312,     0,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
      56,    57,    58,     0,     0,    61,     0,     0,    64,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,  1729,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,     0,     0,   180,     0,     0,     0,   181,
     182,   183,   184,   185,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   544,  1656,     0,     0,     0,   190,     0,     0,     0,
       0,   546,     0,   119,   352,   121,   194,     0,   270,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,     0,     0,     0,
       0,     0,     0,     0,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     0,     0,     0,   166,   167,   168,     0,     0,
     169,     0,   170,   171,   172,     0,     0,     0,     0,     0,
     173,   174,     0,     0,   342,   121,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
       0,     0,     0,     0,   461,     0,     0,     0,     0,     0,
       0,     0,     0,  1730,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     0,     0,     0,     0,   161,   162,   163,
     164,     0,     0,     0,     0,   166,   167,   168,     0,     0,
     169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,   177,   178,   179,   180,     0,     0,     0,   181,
     182,   183,   184,   185,   186,     0,   187,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   189,     0,     0,     0,   190,   119,   303,     0,
       0,   316,     0,   122,   123,   124,   194,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   305,   306,   307,   308,   309,     0,     0,     0,     0,
       0,     0,   177,   178,   179,     0,     0,   157,   158,   159,
     160,     0,     0,     0,   186,   165,   187,    95,     0,     0,
       0,     0,     0,     0,     0,     0,   170,   171,   172,     0,
       0,     0,     0,     0,   173,     0,     0,     0,   310,     0,
       0,   311,     0,     0,   312,     0,   313,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     314,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,    54,     0,     0,    56,    57,    58,     0,     0,    61,
       0,     0,    64,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,     0,     0,
    1731,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   176,     0,     0,     0,   180,
       0,     0,     0,   181,   182,   183,   184,   185,     0,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   188,   483,     0,     0,     0,
     190,   119,   352,     0,     0,   316,     0,   122,   123,   124,
     194,     0,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,     0,     0,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   157,   158,   159,   160,   461,     0,     0,     0,   165,
       0,     0,     0,     0,  1764,     0,     0,     0,   119,   352,
     170,   171,   172,     0,   122,   123,   124,     0,   173,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,     0,     0,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   157,   158,
     159,   160,   461,     0,     0,     0,   165,     0,     0,     0,
       0,  1838,     0,     0,     0,     0,     0,   170,   171,   172,
       0,     0,     0,     0,     0,   173,     0,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,   176,
       0,     0,     0,   180,  1849,     0,     0,   181,   182,   183,
     184,   185,     0,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   188,
     189,     0,     0,     0,   190,     0,     0,     0,     0,   316,
     432,     0,     0,     0,   194,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,   176,     0,     0,     0,
     180,     0,  1850,     0,   181,   182,   183,   184,   185,     0,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   188,   189,     0,     0,
       0,   190,     0,     0,     0,     0,   316,   119,   352,   434,
       0,   194,     0,   122,   123,   124,     0,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,     0,     0,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   157,   158,   159,
     160,   461,     0,     0,     0,   165,     0,     0,     0,     0,
    1882,     0,     0,     0,   119,   352,   170,   171,   172,     0,
     122,   123,   124,     0,   173,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,     0,     0,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   157,   158,   159,   160,   461,     0,
       0,     0,   165,     0,     0,     0,     0,  1885,     0,     0,
       0,     0,     0,   170,   171,   172,     0,     0,     0,     0,
       0,   173,     0,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,   176,     0,     0,     0,   180,
    1888,     0,     0,   181,   182,   183,   184,   185,     0,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   188,   189,     0,     0,     0,
     190,     0,     0,     0,     0,   316,   636,     0,     0,     0,
     194,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,     0,   176,     0,     0,     0,   180,     0,  1920,     0,
     181,   182,   183,   184,   185,     0,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   188,   189,     0,     0,     0,   190,     0,     0,
       0,     0,   316,   119,   352,   638,  1175,   194,     0,   122,
     123,   124,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,     0,     0,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   157,   158,   159,   160,   461,     0,     0,
       0,   165,     0,     0,     0,     0,  1927,     0,     0,     0,
       0,     0,   170,   171,   172,   119,   352,     0,  1314,     0,
     173,   122,   123,   124,     0,     0,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,     0,
       0,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   157,   158,   159,   160,   461,
       0,     0,     0,   165,     0,     0,     0,     0,  1966,     0,
       0,     0,     0,     0,   170,   171,   172,     0,     0,     0,
       0,     0,   173,     0,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,     0,     0,
       0,   176,   461,     0,     0,   180,   708,     0,     0,   181,
     182,   183,   184,   185,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   189,     0,     0,     0,   190,     0,     0,     0,
       0,   316,     0,     0,     0,     0,   194,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,     0,   176,  1968,     0,     0,   180,     0,     0,
       0,   181,   182,   183,   184,   185,     0,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   188,   189,     0,     0,     0,   190,   119,
     352,     0,     0,   316,     0,   122,   123,   124,   194,     0,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,     0,     0,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   157,
     158,   159,   160,   461,     0,     0,     0,   165,     0,     0,
       0,     0,  1970,     0,     0,     0,     0,     0,   170,   171,
     172,     0,     0,     0,     0,     0,   173,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,     0,     0,  1990,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
       0,     0,  2017,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    -4,     1,     0,     0,    -4,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   176,     0,     0,
       0,   180,     0,     0,     0,   181,   182,   183,   184,   185,
       0,     0,     0,    95,    -4,    -4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   188,   189,     0,
       0,     0,   190,     0,    -4,    -4,    -4,   316,     0,     0,
      -4,    -4,   194,    -4,     0,     0,     0,    -4,    -4,     0,
      -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,     0,
       0,     0,     0,     0,    -4,     6,     0,     0,     0,    -4,
      -4,    -4,    -4,     7,     8,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     9,    10,     0,     0,    -4,     0,    -4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,    13,     0,     0,     0,    14,
      15,     0,    16,     0,     0,     0,    17,    18,     0,    19,
      20,     0,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,     0,     0,    67,    68,    69,     0,     0,
       0,     0,     0,    70,     0,     0,     0,     0,    71,    72,
      73,    74,   469,   121,    75,     0,    76,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,    92,    93,
       0,     0,     0,     0,     0,     0,    94,     0,    95,     0,
       0,     0,   148,   149,   150,   151,   152,   153,   154,   155,
     156,     0,     0,     0,     0,   161,   162,   163,   164,     0,
       0,     0,     0,   166,   167,   168,     0,     0,   169,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,     0,     0,     0,     0,   461,     0,
       0,     0,     0,     0,     0,     0,     0,  2056,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,     0,     0,     0,     0,   461,     0,     0,     0,
       0,     0,     0,     0,     0,  2057,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
       0,     0,     0,     0,   461,     0,     0,     0,     0,     0,
       0,     0,     0,  2061,     0,     0,     0,     0,     0,     0,
     177,   178,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   186,     0,   187,    95,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
       0,     0,     0,     0,   461,     0,     0,     0,     0,     0,
       0,     0,     0,  2062,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,     0,     0,
       0,     0,   461,     0,     0,     0,     0,     0,     0,     0,
       0,  2063,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,     0,     0,     0,     0,
     461,     0,     0,     0,     0,     0,     0,     0,     0,  2064,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,     0,     0,     0,     0,   461,     0,
       0,     0,     0,     0,     0,     0,   629,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,     0,   812,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,     0,     0,
       0,     0,   461,     0,     0,     0,     0,     0,     0,     0,
    1740,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,   858,     0,   859,     0,     0,  1399,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,   886,     0,     0,
       0,     0,   819,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,   819,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,   820,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
     900,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,     0,     0,     0,     0,     0,   944,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,   952,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,   953,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,   954,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
     969,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,     0,     0,     0,     0,     0,  1102,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,  1103,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,  1104,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,  1135,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
    1144,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,     0,     0,     0,     0,     0,  1145,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,  1147,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,  1257,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,  1306,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
    1307,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,     0,     0,     0,     0,     0,  1368,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,  1531,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,  1532,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,  1533,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
    1534,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,     0,     0,     0,     0,     0,  1535,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,  1536,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,  1537,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,  1589,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
    1590,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,     0,     0,     0,     0,     0,  1597,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,  1767,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,  1768,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,  1769,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
    1770,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,     0,     0,     0,     0,     0,  1771,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,  1794,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,  1795,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,  1799,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
    1900,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,     0,     0,     0,     0,     0,  1901,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,  1902,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,  1903,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,  1904,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
    1913,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,     0,     0,     0,     0,     0,  1916,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,  1962,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,  1979,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,  1980,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
    1981,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,     0,     0,     0,     0,     0,  1982,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,  1983,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,  2029,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,  2030,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
    2031,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,     0,     0,     0,     0,     0,  2032,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,   906,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,     0,     0,     0,     0,   461,     0,
       0,     0,   924,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,   931,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
       0,     0,     0,     0,   461,     0,     0,     0,  1027,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,  1128,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,     0,     0,     0,     0,
     461,     0,     0,     0,  1129,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,     0,     0,  1133,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,     0,     0,     0,     0,   461,     0,     0,     0,
    1134,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,     0,     0,  1137,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,     0,     0,
       0,     0,   461,     0,     0,     0,  1161,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,     0,     0,  1193,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,     0,     0,     0,     0,   461,     0,
       0,     0,  1250,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,     0,     0,  1255,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
       0,     0,     0,     0,   461,     0,     0,     0,  1526,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,     0,
       0,  1580,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,     0,     0,     0,     0,
     461,     0,     0,     0,  1753,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,   704,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
       0,     0,     0,     0,   461,     0,   761,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,   765,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,     0,     0,     0,     0,   461,     0,   766,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,   768,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,     0,     0,     0,     0,   461,     0,
     770,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,   771,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,     0,     0,     0,     0,
     461,     0,   774,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,   775,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,     0,     0,
       0,     0,   461,     0,   784,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,   886,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
       0,     0,     0,     0,   461,     0,   896,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,   897,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,     0,     0,     0,     0,   461,     0,   898,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,   904,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,     0,     0,     0,     0,   461,     0,
     905,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,   920,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,     0,     0,     0,     0,
     461,     0,   930,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,  1026,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,     0,     0,
       0,     0,   461,     0,  1054,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,  1059,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
       0,     0,     0,     0,   461,     0,  1064,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,  1069,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,     0,     0,     0,     0,   461,     0,  1070,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,  1076,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,     0,     0,     0,     0,   461,     0,
    1085,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,  1086,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,     0,     0,     0,     0,
     461,     0,  1087,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,  1119,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,     0,     0,
       0,     0,   461,     0,  1121,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,  1122,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
       0,     0,     0,     0,   461,     0,  1123,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,  1127,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,     0,     0,     0,     0,   461,     0,  1136,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,   461,     0,  1160,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,     0,     0,     0,     0,   461,     0,
    1249,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,     0,     0,     0,     0,   461,
       0,  1254,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,     0,     0,     0,     0,
     461,     0,  1411,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,     0,     0,     0,
       0,   461,     0,  1635,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,     0,     0,
       0,     0,   461,     0,  1652,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,     0,
       0,     0,     0,   461,     0,  1679,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
       0,     0,     0,     0,   461,     0,  1912,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,     0,     0,     0,     0,   461,     0,  1988,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,     0,     0,     0,     0,   461
};

static const yytype_int16 yycheck[] =
{
       3,     5,   263,     6,   399,     7,   401,  1282,     4,   538,
     539,     4,     6,     4,     3,  1114,  1118,     4,     4,     4,
       4,   416,     4,     6,     5,     5,     5,  1723,   118,     4,
       6,    90,     6,     6,     4,     4,   278,     4,     4,     4,
       4,   215,     0,     5,     5,     5,   220,     6,   290,     5,
       5,     5,   211,     6,     6,     6,   201,   202,     6,    62,
       4,   201,   202,   109,    13,     7,     4,    70,     6,   211,
     201,   202,    75,   218,     6,   212,   218,   123,   218,     6,
     217,   201,   202,    86,   153,   131,   132,   133,   219,     6,
     212,   137,   138,   139,   140,   217,     7,   217,   212,   219,
     169,   170,   211,   217,   213,   201,   202,   349,     6,   351,
       7,   220,   201,   202,   356,   201,   202,   211,     7,   432,
      84,   434,   218,   436,    88,   201,   202,     7,   217,   211,
     219,   217,   211,   219,     7,   211,   218,     6,   102,   201,
     202,   211,   218,     6,    51,    52,    84,    54,   218,     7,
     201,   202,   156,     6,    86,   217,    88,   212,   143,   144,
     145,   146,   217,   201,   202,   141,   217,   141,     6,   153,
     154,  1867,  1868,   219,     6,   156,   156,   156,   164,   217,
       7,   168,   141,   201,   202,   208,   209,     6,   153,   154,
     141,   194,   215,   201,   202,     7,   187,    87,   211,   217,
      90,   187,     7,   206,   207,   218,   195,   201,   202,   217,
       6,   214,   187,   215,   218,     6,     7,   213,   211,   222,
     213,   224,   215,   213,   220,   198,   229,   220,   211,   211,
     233,  1330,   218,   236,   219,   218,   218,   240,   241,   242,
     243,   244,   211,   218,  1519,   248,   249,   250,   218,   218,
     198,   218,   218,   256,   257,   258,   218,   218,   218,   262,
     263,     8,   218,   218,   218,   218,   218,   211,   213,   211,
       3,   213,   211,     6,   201,   202,   211,   188,   189,   190,
     191,   284,   285,   286,   201,   202,     7,   529,   530,   221,
     211,   188,   189,   190,   191,   298,   299,   208,   209,   188,
     189,   190,   191,   211,   215,   201,   202,   549,   188,   189,
     190,   191,   315,     8,   317,   188,   189,   190,   191,   208,
     209,   217,    94,   636,   211,   638,   213,   201,   202,    62,
     188,   189,   190,   191,   211,   208,   209,   206,   207,  1614,
     208,   209,    75,   217,   208,   209,   436,   217,     6,   219,
     208,   209,   355,    86,   218,   358,   359,   201,   202,   266,
     267,   188,   189,   190,   191,   212,   211,   274,   371,   212,
     217,   278,   614,   217,   217,   244,   188,   189,   190,   191,
      90,   208,   209,   188,   189,   190,   191,   629,    90,    87,
      92,   704,    90,   201,   202,   708,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   217,
     413,   414,   415,   416,   417,   201,   202,    90,   421,   422,
     423,   424,   425,   426,   218,   428,   208,   209,   201,   202,
     211,   217,   364,   203,   204,   205,   218,   211,   214,   213,
     210,   217,   445,  1718,   217,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   201,
     202,   194,  1737,   210,    90,   208,   209,   188,   189,   190,
     191,   214,   219,   206,   207,   217,   217,     4,   219,    84,
     483,   214,    87,   208,   209,    90,   355,   419,    84,   222,
     217,    87,   219,   218,    90,   427,    92,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   244,   201,   202,   211,   210,   201,   202,   212,    84,
     523,   524,    87,   217,   219,    90,   214,     6,   217,   217,
     263,   400,   217,   402,   403,   404,   405,   406,   407,   408,
      90,   410,   411,    92,   413,   414,   415,   211,   417,   538,
     539,    87,   421,   422,   423,   424,   425,   218,   648,   241,
     242,   243,   565,   566,   567,   218,   248,   249,   250,   201,
     202,     6,     7,   815,   577,   578,   201,   202,   581,   201,
     202,   513,   514,   515,   516,   217,   113,   114,   115,   116,
     201,   202,   217,   596,    90,   217,   201,   202,   125,    87,
     603,   128,   284,   285,   201,   202,   211,   920,   201,   202,
       8,   924,     4,   218,   704,    87,   298,   299,   708,   622,
     217,   212,   355,   214,   217,   201,   202,   201,   202,   536,
     537,   109,    90,   201,   202,     4,   211,   544,   641,     4,
    1915,   217,   211,   217,   213,   123,  1748,     4,  1750,   217,
    1752,   220,   211,   131,   132,   133,   211,   211,   213,   137,
     138,   139,   140,   211,   211,   220,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     6,   410,   411,   213,
     413,   414,   415,   416,   417,     6,   208,   209,   421,   422,
     423,   424,   425,   426,   211,   428,   218,   208,   209,   213,
     703,   208,   209,   212,   707,   214,   218,   218,    90,   218,
      92,   218,   581,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,  1826,   113,   114,
    1829,   210,     7,  1832,   119,   211,   211,   211,   213,   213,
    2015,   219,   211,   746,  1005,   220,   220,   750,   211,   211,
     753,   109,   211,   756,   211,   758,   213,   211,   215,   762,
     763,   218,   211,   220,  1077,   123,  1079,   857,  1081,   217,
    1083,   219,   211,   131,   132,   133,   217,   709,   219,   137,
     138,   139,   140,    84,   211,   788,    87,    87,   211,    90,
      90,    92,    92,  1895,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    87,   812,
     213,    90,   210,    92,   212,   201,   202,   203,   204,   205,
    1215,  1216,   218,   218,   210,  1220,  1221,   211,   760,   213,
     920,   215,     6,   211,   924,   213,   220,   215,   218,     6,
     930,   931,   220,  1942,   212,   578,   214,   211,   581,   212,
     218,   214,   113,   114,   217,   211,   211,   860,   119,   862,
     211,   219,   865,  1965,   212,  1967,   214,  1969,   217,   217,
     219,   218,   217,  1975,   219,   878,   211,   880,   212,   882,
     214,   884,   211,   217,   753,   212,   889,   214,   211,   758,
     217,   894,   212,   211,   214,  1994,   211,   217,  1997,   218,
     212,  2000,   214,   211,  2003,   217,   217,   217,   219,   219,
    1223,   818,   915,   217,     4,   219,   919,   211,   825,  2021,
     923,  2023,   218,  2025,   831,   212,  1239,   214,   931,   217,
     217,   219,     6,   217,   211,   219,  1026,  1027,    90,   217,
      92,   219,  2041,   217,  2043,   219,  2045,   217,   217,   219,
     219,   218,   217,   956,   219,   217,   211,   219,   961,     6,
     217,   211,   219,   966,   967,   968,   969,  1496,  1497,  1230,
     217,   217,   219,   219,   218,   217,   979,   219,   981,   217,
     217,   219,   219,   218,  1379,  1380,   217,   109,   219,  1384,
    1385,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     218,   123,  1005,   213,   210,  1008,  1009,  1010,  1011,   131,
     132,   133,   220,     6,   109,   137,   138,   139,   140,   217,
     753,   219,   217,   756,   219,   758,     6,   217,   123,   219,
    1033,   217,   217,   219,   219,   218,   131,   132,   133,   218,
       4,     5,   137,   138,   139,   140,  1136,  1137,   218,  1052,
    1053,   217,  1055,   219,  1057,  1058,   213,   213,  1061,  1062,
       6,     6,   931,  1066,   217,   213,   219,   217,   156,   219,
    1160,  1161,     4,   217,     6,   219,  1389,   217,   220,   219,
      44,    45,    46,    47,    48,    49,    50,    51,    52,   217,
       6,   219,   961,    57,    58,    59,    60,   219,   967,   968,
     969,    65,    66,    67,   218,   217,    70,   219,     6,   217,
     979,   219,   981,   217,   217,   219,   219,    81,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   218,  1223,  1376,   217,   210,   219,     4,     5,
     217,  1048,   219,     6,     6,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   218,
    1163,  1164,  1165,   210,  1033,     6,   217,     6,   219,  1430,
     218,   217,   217,   219,   219,  1178,   213,     4,    44,    45,
      46,    47,    48,    49,    50,    51,    52,   217,   217,   219,
     219,    57,    58,    59,    60,  1102,  1103,  1104,   931,    65,
      66,    67,   109,   217,    70,   219,   210,   215,   172,   173,
     174,     7,  1215,  1216,  1743,    81,   123,  1220,  1221,   217,
     184,   219,   186,   187,   131,   132,   133,  1230,   961,   218,
     137,   138,   139,   140,   967,   968,   969,   219,   217,   109,
     219,  1244,   217,   217,   208,   209,   979,   217,   981,   219,
     217,   215,   219,   123,   218,   217,   217,   219,   219,     7,
       6,   131,   132,   133,     6,  1268,     6,   137,   138,   139,
     140,  1274,  1005,   217,   217,   219,   219,  1280,     6,  1282,
    1283,  1284,   217,   212,   219,  1288,  1289,   217,  1291,   219,
    1293,   217,  1295,   219,  1297,  1298,  1299,     7,     7,     6,
    1033,  1391,     6,     6,  1699,     6,   172,   173,   174,   212,
     218,     7,   219,  1316,     6,    62,     7,     6,   184,     6,
     186,   187,     6,     4,    62,    62,  1258,    62,  1331,   153,
      12,    13,  1335,   218,  1337,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   212,   214,   214,   219,
     210,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   212,     6,     6,   212,   210,
     212,   217,   217,    44,   217,    44,  1379,  1380,   212,   217,
     217,  1384,  1385,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,  1398,   217,   217,   212,   210,
     212,  1404,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   214,    95,    44,    44,     6,     4,   100,   101,
     102,   103,  1329,   105,   106,   107,     4,  1430,     7,   111,
       6,     6,     6,  1436,     6,   156,     7,  1527,     7,     7,
     156,     7,  1374,  1446,     7,   156,  1449,     7,  1709,     7,
     218,     6,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   148,   149,   150,     7,
     210,     4,   217,   212,     6,   219,   212,     6,   212,     7,
     212,   212,  1215,  1216,   217,  1488,  1489,  1220,  1221,   215,
    1422,    12,    13,   217,   217,   214,   218,  1230,     7,   219,
     218,   218,     7,   218,     6,   219,   218,  1496,  1497,   215,
       6,     6,     6,    44,  1517,  1757,  1519,  1449,  1521,    44,
     109,    44,    44,     6,     6,   213,     7,     6,   211,  1398,
       6,   211,   218,   198,   123,  1404,     7,   219,  1541,     7,
      92,     7,   131,   132,   133,     7,   218,  1550,   137,   138,
     139,   140,  1459,     7,     7,     6,   218,  1560,     7,     7,
    1492,     7,  1565,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     7,    95,   109,     7,  1446,     7,   100,
     101,   102,   103,     4,   105,   106,   107,     4,  1591,   123,
     111,  1498,     6,  1500,   109,  1502,   211,   131,   132,   133,
       7,     6,   218,   137,   138,   139,   140,     7,   123,     7,
    1517,  1614,     7,  1520,  1521,  1547,   131,   132,   133,     6,
       6,     6,   137,   138,   139,   140,     7,   148,   149,   150,
     219,    90,     6,  1565,  1566,  1567,     6,     4,     4,   219,
       4,   218,     4,     6,   217,   109,  1379,  1380,  1651,     6,
       6,  1384,  1385,  1656,  1896,     6,    21,    22,     6,   123,
       6,   217,   212,   217,   212,  1398,   215,   131,   132,   133,
       6,  1404,     7,   137,   138,   139,   140,  1680,   218,   215,
       6,   211,     6,     6,     6,   219,   212,   214,     6,   102,
       6,     6,     6,  1696,   218,     6,  1699,  1430,   219,   218,
     218,   218,   218,     5,   219,     4,  1709,   218,     6,     6,
     218,     7,   218,  1446,   218,  1718,   213,     6,   109,     6,
       6,     4,  1725,  1726,   212,   218,   218,   218,   214,     6,
       6,     6,   123,   152,  1737,     6,     6,  1740,     4,   217,
     131,   132,   133,     6,    12,    13,   137,   138,   139,   140,
       6,  1683,   117,  1756,  1743,   219,     4,     6,  1761,     6,
       6,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     6,     6,     4,   154,
     155,   156,   157,     7,   159,   160,   161,   162,   163,   164,
       7,     6,   167,     6,     6,     6,     6,     6,   173,   174,
       5,   156,  1815,     6,   179,   180,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,   218,    95,   219,     6,
       6,  1834,   100,   101,   102,   103,     6,   105,   106,   107,
    1747,     6,  1749,   111,  1751,     6,   217,     6,     6,     6,
       6,     6,  1759,     6,  1857,  1762,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
       6,     6,     6,     6,   210,   109,   217,     6,     6,   212,
     148,   149,   150,     6,     6,     6,     6,     6,     6,   123,
       7,     6,     6,   218,  1897,   215,  1899,   131,   132,   133,
       5,   218,     6,   137,   138,   139,   140,  1814,   218,    88,
       6,  1818,  1915,   218,     6,   218,     6,     6,   219,   219,
       7,   151,     6,   218,  1856,   218,   218,   218,     6,   219,
       6,   219,     6,     6,     6,     6,   154,     6,   303,     6,
       6,   306,   307,   308,   309,     6,     6,     6,     6,   109,
       6,   219,   212,   218,     6,   219,     7,     6,     6,   218,
     325,   218,     6,   123,   218,  1872,  1699,   218,     6,  1876,
     109,   131,   132,   133,  1977,     6,  1709,   137,   138,   139,
     140,   218,     6,     6,  1987,   219,     6,     6,     6,     6,
       6,     6,  1899,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,     6,     6,   219,
       6,   210,  2015,   211,   218,     6,     6,     6,     6,     6,
     212,  1953,   218,     6,   218,     6,     6,   218,   218,     6,
    2033,   218,  2035,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   218,     6,   218,
     218,   210,     6,     6,     6,     6,  1963,  1964,     6,   219,
       6,     6,  2065,    94,     3,     4,     6,  1860,     6,     6,
       9,    10,    11,     6,   439,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     6,  1253,
     479,  1724,  1267,     3,     3,  1549,     3,   511,  1739,  1426,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,  1987,    -1,
      -1,    -1,    61,    -1,  1857,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,
     191,   192,    -1,    -1,  2033,    -1,  2035,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   224,   225,   226,  2065,   228,   229,   230,
     231,    -1,   233,   234,   235,     6,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,   245,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   260,
      -1,    -1,   171,   210,    -1,    -1,   175,    -1,   269,   270,
     179,   180,   181,   182,   183,    -1,    -1,   278,   187,     6,
      -1,    -1,    -1,    -1,  1987,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,   211,    -1,    -1,    -1,    -1,   216,    -1,   218,
      -1,    -1,    -1,    -1,   315,   316,   317,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   328,   329,   330,
    2033,   332,  2035,    -1,    -1,   336,   337,   338,    -1,    -1,
     341,    -1,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,   360,
     361,   210,  2065,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   374,   375,    -1,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   412,    -1,    -1,    -1,    -1,    -1,   418,    -1,   420,
       6,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,   444,   445,    -1,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,    -1,    -1,   464,   465,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,   483,   210,    -1,    -1,    -1,    -1,   489,    -1,
      -1,    -1,    -1,   494,    -1,    -1,    -1,    -1,   499,   500,
      -1,    -1,    -1,    -1,    -1,    -1,   507,   508,     6,    -1,
      -1,   512,   513,   514,   515,   516,   517,    -1,   519,    -1,
     521,    -1,   523,   524,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     541,   542,   543,   544,   545,   546,    -1,    -1,    -1,   550,
     551,   552,   553,   554,    -1,    -1,    -1,   558,    -1,   560,
     561,    -1,    -1,    -1,   565,   566,   567,    -1,    -1,   570,
     571,   572,   573,   574,    -1,    -1,   577,   578,   579,   580,
      -1,   582,    -1,    -1,   585,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   596,    -1,    -1,    -1,    -1,
      -1,   602,   603,    -1,   605,   606,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,   622,    -1,    -1,   210,    -1,   627,   628,    -1,   630,
     631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   640,
     641,    12,    13,    -1,   645,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   988,   989,    -1,    -1,    -1,    -1,   994,
     995,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   224,    -1,    -1,    -1,   210,
     229,    -1,    -1,    -1,   233,    -1,   217,    -1,   219,    -1,
      -1,   240,    -1,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,   710,
      -1,    -1,   210,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,   100,
     101,   102,   103,    -1,   105,   106,   107,    -1,    -1,    -1,
     111,   742,   743,    -1,    -1,   746,   747,   748,    -1,   750,
     751,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   759,    -1,
      -1,   762,   763,    -1,    -1,    -1,   315,    -1,   317,    -1,
      -1,    -1,    -1,    -1,    -1,   776,    -1,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,   787,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,   812,    -1,    -1,   210,   256,   257,   258,   819,   820,
      -1,   262,    -1,   219,   825,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   838,    -1,    -1,
     841,    -1,    -1,    -1,    -1,   286,  1181,  1182,   219,    -1,
      -1,  1186,  1187,    -1,    -1,    -1,    -1,    -1,    -1,   860,
      -1,   862,    -1,    -1,   865,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   878,    -1,   880,
      -1,   882,    -1,   884,    -1,    -1,    -1,    -1,   889,    -1,
      -1,    -1,    -1,   894,    -1,    -1,   445,    -1,    -1,   900,
      -1,   902,   903,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   912,    -1,    -1,    -1,    -1,    -1,   358,   359,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     371,    -1,    -1,    -1,   483,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   944,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   952,   953,   954,    -1,   956,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   964,    -1,    -1,    -1,    -1,   409,    -1,
      -1,    -1,    -1,    -1,   523,   524,    -1,   978,    -1,    -1,
      -1,    -1,   983,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   992,    -1,    -1,    -1,    -1,    -1,   998,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1008,  1009,  1010,
    1011,    -1,    -1,  1014,    -1,    -1,   565,   566,   567,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   577,   578,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   596,    -1,    -1,
      -1,    -1,    -1,    -1,   603,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1066,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   622,    -1,    -1,    -1,  1078,    -1,  1080,
      -1,  1082,     6,  1084,    -1,    -1,    -1,    12,    13,    -1,
      -1,    -1,   641,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1106,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      -1,    -1,    -1,    -1,   100,   101,   102,   103,    -1,   105,
     106,   107,    -1,    -1,  1135,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1144,  1145,    -1,  1147,  1148,    -1,  1150,
    1151,  1152,    -1,    -1,    -1,    -1,    -1,  1158,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    -1,   148,   149,   150,   100,   101,   102,   103,    -1,
     105,   106,   107,  1184,    -1,    -1,   111,    -1,  1189,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   746,    -1,    -1,
      -1,   750,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   762,   763,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,    -1,    -1,    -1,    -1,
    1231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1242,  1243,   219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1257,  1258,    -1,    -1,
      -1,    -1,   703,   812,    -1,    -1,   707,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    12,    13,    -1,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1305,  1306,  1307,    -1,    -1,    -1,
      -1,   860,    -1,   862,    -1,  1316,   865,  1318,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1329,   878,
      -1,   880,    -1,   882,    -1,   884,  1337,    -1,    -1,    -1,
     889,  1342,    -1,    -1,    -1,   894,    -1,   788,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,     6,    95,  1368,  1369,  1370,
      -1,   100,   101,   102,   103,    -1,   105,   106,   107,    -1,
      -1,    -1,   111,    -1,    -1,   224,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,   233,    -1,    -1,    -1,  1399,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,   956,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,  1423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1437,    -1,    -1,    -1,
      -1,  1442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1457,  1458,    -1,  1008,
    1009,  1010,  1011,  1464,  1465,    -1,    -1,    -1,  1469,    -1,
      -1,    -1,    -1,    -1,   915,    -1,    -1,  1478,   919,    -1,
      -1,    -1,   923,    -1,    -1,    -1,    -1,  1488,  1489,  1490,
     219,  1492,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1504,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1517,  1066,    -1,    -1,
    1521,    -1,    -1,  1524,    -1,   966,    -1,    -1,    -1,    -1,
    1531,  1532,  1533,  1534,  1535,  1536,  1537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1547,    -1,    -1,    -1,
      -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,  1566,    -1,    -1,    -1,   210,
      -1,    12,    13,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,  1589,  1590,
      -1,    -1,   100,   101,   102,   103,  1597,   105,   106,   107,
      -1,    -1,    -1,   111,    -1,    -1,   445,    -1,    -1,    -1,
      -1,  1052,  1053,    -1,  1055,    -1,  1057,  1058,    -1,    -1,
    1061,  1062,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1636,    -1,    -1,    -1,    -1,
     148,   149,   150,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,  1654,    95,  1656,    -1,    -1,    -1,   100,
     101,   102,   103,    -1,   105,   106,   107,    -1,    -1,    -1,
     111,    -1,    -1,    -1,  1675,    -1,  1677,    -1,    -1,  1680,
      -1,    -1,    -1,    -1,   523,   524,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1696,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,   219,    -1,  1714,    -1,    -1,    -1,    -1,  1719,    -1,
      -1,    -1,  1163,  1164,  1165,    -1,   565,   566,   567,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,  1178,    -1,  1740,
      -1,    -1,    -1,    -1,    -1,    -1,  1747,    -1,  1749,    -1,
    1751,    -1,    -1,    -1,    -1,    -1,    -1,   596,    -1,    -1,
    1761,    -1,    -1,    -1,    -1,    -1,  1767,  1768,  1769,  1770,
    1771,  1772,    -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,
      -1,    -1,    -1,   622,    -1,    -1,    -1,    -1,  1337,    -1,
      -1,    -1,    -1,  1794,  1795,    -1,    -1,    -1,  1799,    -1,
      -1,    -1,   641,  1244,    -1,    -1,    -1,    -1,    -1,    -1,
    1811,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1822,    -1,    -1,    -1,    -1,    -1,  1268,    -1,    -1,
      -1,    -1,    -1,  1274,    -1,    -1,    -1,    -1,    -1,  1280,
      -1,  1282,  1283,  1284,    -1,    -1,    -1,  1288,  1289,    -1,
    1291,    -1,  1293,  1854,  1295,    -1,  1297,  1298,  1299,  1860,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1869,    -1,
      -1,    -1,    -1,    -1,    -1,  1316,    12,    13,    -1,    -1,
      -1,    -1,  1883,    -1,    -1,  1886,    -1,    -1,  1889,    -1,
    1331,    -1,  1893,    -1,  1335,    -1,  1897,    -1,  1899,  1900,
    1901,  1902,  1903,  1904,    -1,    -1,    -1,   746,    -1,    -1,
      -1,   750,  1913,    -1,    -1,  1916,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,  1488,
    1489,    -1,    -1,    -1,    -1,    -1,    -1,     6,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      -1,  1962,    -1,    -1,   100,   101,   102,   103,  1517,   105,
     106,   107,  1521,   812,    -1,   111,  1977,    -1,  1979,  1980,
    1981,  1982,  1983,    -1,    -1,    -1,    -1,    -1,    -1,     7,
       8,    -1,    -1,    -1,    -1,  1436,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1449,    -1,
       7,    -1,   148,   149,   150,   607,    -1,  2018,  2019,    -1,
      -1,   860,    -1,   862,    -1,    -1,   865,    -1,  2029,  2030,
    2031,  2032,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   878,
      -1,   880,    -1,   882,    -1,   884,    -1,    -1,    -1,    -1,
     889,    -1,    -1,    -1,    -1,   894,    -1,   649,   650,   651,
     652,   653,   654,   655,   656,   657,   658,   659,    -1,   661,
     662,   663,   664,   665,   666,   667,    -1,    -1,  1519,   671,
     672,   673,    -1,   219,    -1,   677,   678,    -1,   680,    -1,
      -1,    -1,    -1,   685,   686,   687,    -1,   689,    -1,    -1,
    1541,    -1,    -1,    -1,   696,   697,    -1,  1656,    -1,  1550,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   956,    -1,  1560,
      -1,    -1,   714,    -1,  1565,    -1,    -1,    -1,    -1,    -1,
      -1,  1680,     8,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,  1696,    -1,    -1,
    1591,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,  1008,
    1009,  1010,  1011,  1614,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
      -1,  1740,   210,     8,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
    1651,    -1,  1761,   210,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1066,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1718,   870,    -1,
      -1,    -1,    -1,    -1,  1725,  1726,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,  1737,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,  1756,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1897,    -1,
    1899,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,     8,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,  1815,    -1,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,     8,    -1,  1834,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,    -1,
      -1,    -1,   179,   180,   181,   182,   183,    -1,    -1,    -1,
     187,  1013,    -1,    -1,    -1,    -1,    -1,    -1,  1977,    -1,
      -1,    -1,    -1,    -1,   201,   202,    -1,    -1,    -1,   206,
      -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,   216,
      -1,   218,    -1,    -1,  1046,  1047,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,  1915,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,  1337,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,
      -1,    70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,  2015,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
    1192,    -1,    -1,    -1,    -1,    -1,  1198,  1199,  1200,  1201,
    1202,    -1,  1204,    -1,  1206,  1207,    -1,  1209,  1210,    -1,
      -1,  1213,  1214,  1215,    -1,   164,    -1,    -1,  1220,    -1,
      -1,    -1,   171,   172,   173,   174,   175,    -1,    -1,    -1,
     179,   180,   181,   182,   183,   184,    -1,   186,   187,  1488,
    1489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,   211,    -1,   213,    -1,   215,   216,    -1,   218,
      -1,   220,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,  1347,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,  1363,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,  1379,    -1,    -1,
      -1,    -1,  1384,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,    -1,    -1,   125,    -1,    -1,   128,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,  1416,  1417,    -1,   210,  1420,  1421,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1680,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,    -1,    -1,    -1,   216,    -1,   218,   219,
      -1,  1740,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,     3,     4,    -1,
     210,    -1,  1761,     9,    10,    11,    -1,   217,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,  1553,  1554,    -1,    -1,  1557,  1558,    53,    54,    55,
      56,  1563,  1564,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,    -1,    -1,   120,   121,   122,    -1,    -1,   125,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1897,    -1,
    1899,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,  1667,  1668,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,
      -1,    -1,    -1,   179,   180,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   201,   202,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,
     216,    -1,    -1,   219,     3,     4,     5,    -1,  1977,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    12,    13,    -1,    65,    66,    67,    -1,
      -1,    70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,
      -1,   120,   121,   122,    -1,    -1,   125,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    -1,    -1,    -1,
      -1,   100,   101,   102,   103,    -1,   105,   106,   107,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,   173,   174,   175,   126,    -1,    -1,
     179,   180,   181,   182,   183,   184,    -1,   186,   187,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,   211,    -1,    -1,    -1,    -1,   216,    -1,   218,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    12,
      13,    -1,    65,    66,    67,  2007,    -1,    70,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,   117,    -1,    -1,   120,   121,   122,
      -1,    -1,   125,    -1,    -1,   128,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    -1,    -1,    -1,    -1,   100,   101,   102,
     103,    -1,   105,   106,   107,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,   174,   175,    -1,    -1,    -1,   179,   180,   181,   182,
     183,   184,    -1,   186,   187,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   201,   202,
      -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,   211,    -1,
       3,     4,     5,   216,    -1,   218,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,
      73,    74,    -1,     3,     4,     5,    -1,    80,    81,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,   174,   175,    -1,    -1,    -1,   179,   180,   181,   182,
     183,   184,    -1,   186,   187,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   202,
      -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,   211,    -1,
      -1,    -1,    -1,   216,    -1,   218,    -1,    -1,    -1,    -1,
      -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,   171,   172,   173,   174,   175,   217,    -1,   219,   179,
     180,   181,   182,   183,   184,    -1,   186,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,     3,     4,     5,   216,    -1,   218,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    12,    13,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,   219,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,
     212,    -1,   214,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,
     100,   101,   102,   103,    -1,   105,   106,   107,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,   172,   173,   174,   175,    -1,    -1,    -1,   179,
     180,   181,   182,   183,   184,    -1,   186,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,     3,     4,     5,   216,    -1,   218,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,   219,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,    -1,    -1,   125,    -1,    -1,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    81,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,     3,     4,     5,   216,    -1,   218,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,   172,   173,   174,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,
      -1,   186,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,     5,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,    -1,    -1,   125,    -1,    -1,   128,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,     3,     4,    -1,   216,    -1,   218,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
     174,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
     184,    61,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,    -1,    -1,   125,    -1,    -1,   128,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,     3,     4,    -1,   216,    -1,   218,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,    -1,    -1,   125,    -1,    -1,   128,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,     3,     4,    -1,   216,    -1,   218,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,    -1,    -1,   125,    -1,    -1,   128,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,     3,     4,    -1,   216,    -1,   218,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,    -1,    -1,   125,    -1,    -1,   128,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,     3,     4,    -1,   216,    -1,   218,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,    -1,    -1,   125,    -1,    -1,   128,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,     3,     4,    -1,   216,    -1,   218,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,    -1,    -1,   125,    -1,    -1,   128,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,     3,     4,    -1,   216,    -1,   218,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,    -1,    -1,   125,    -1,    -1,   128,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,     3,     4,    -1,   216,    -1,   218,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,    -1,    -1,   125,    -1,    -1,   128,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,     3,     4,    -1,   216,    -1,   218,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,    -1,    -1,   125,    -1,    -1,   128,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,     3,     4,    -1,   216,    -1,   218,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,    -1,    -1,   125,    -1,    -1,   128,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,     3,     4,     5,   216,    -1,   218,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,     4,     5,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,   172,   173,   174,   175,    -1,    -1,    -1,   179,
     180,   181,   182,   183,   184,    -1,   186,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,     3,     4,    -1,
      -1,   211,    -1,     9,    10,    11,   216,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,   172,   173,   174,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,   184,    61,   186,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,    -1,    -1,   120,   121,   122,    -1,    -1,   125,
      -1,    -1,   128,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,
      -1,    -1,    -1,   179,   180,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   201,   202,    -1,    -1,    -1,
     206,     3,     4,    -1,    -1,   211,    -1,     9,    10,    11,
     216,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    53,    54,    55,    56,   210,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,     3,     4,
      72,    73,    74,    -1,     9,    10,    11,    -1,    80,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    53,    54,
      55,    56,   210,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,   219,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   171,
      -1,    -1,    -1,   175,   219,    -1,    -1,   179,   180,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,   211,
     212,    -1,    -1,    -1,   216,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,   171,    -1,    -1,    -1,
     175,    -1,   219,    -1,   179,   180,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   201,   202,    -1,    -1,
      -1,   206,    -1,    -1,    -1,    -1,   211,     3,     4,   214,
      -1,   216,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    53,    54,    55,
      56,   210,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
     219,    -1,    -1,    -1,     3,     4,    72,    73,    74,    -1,
       9,    10,    11,    -1,    80,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    53,    54,    55,    56,   210,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,
     219,    -1,    -1,   179,   180,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   201,   202,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,
     216,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,   171,    -1,    -1,    -1,   175,    -1,   219,    -1,
     179,   180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,   211,     3,     4,   214,     6,   216,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    53,    54,    55,    56,   210,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,     3,     4,    -1,     6,    -1,
      80,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    53,    54,    55,    56,   210,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   219,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
      -1,   171,   210,    -1,    -1,   175,   214,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,    -1,    -1,    -1,   216,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   219,    -1,    -1,   175,    -1,    -1,
      -1,   179,   180,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   201,   202,    -1,    -1,    -1,   206,     3,
       4,    -1,    -1,   211,    -1,     9,    10,    11,   216,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    53,
      54,    55,    56,   210,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,
      -1,   175,    -1,    -1,    -1,   179,   180,   181,   182,   183,
      -1,    -1,    -1,   187,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   202,    -1,
      -1,    -1,   206,    -1,    62,    63,    64,   211,    -1,    -1,
      68,    69,   216,    71,    -1,    -1,    -1,    75,    76,    -1,
      78,    79,    -1,    -1,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,   142,     4,    -1,    -1,    -1,   147,
     148,   149,   150,    12,    13,   153,    -1,   155,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,    -1,    -1,    -1,    -1,   176,   177,
     178,    -1,    -1,    42,    43,    -1,    -1,   185,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    -1,    -1,    -1,    68,
      69,    -1,    71,    -1,    -1,    -1,    75,    76,    -1,    78,
      79,    -1,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,     4,     5,   153,    -1,   155,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,    -1,    -1,    -1,    -1,   176,   177,   178,
      -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,   187,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   219,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,    -1,   186,   187,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   218,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   218,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     218,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,   212,    -1,   214,    -1,    -1,   217,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,   212,    -1,    -1,
      -1,    -1,   217,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,   214,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,   214,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,   214,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,    -1,    -1,    -1,   214,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,   214,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,
     214,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,   214,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    -1,   214,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,   214,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,   214,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,   214,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,    -1,    -1,    -1,   214,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,   212,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,   212,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,   212,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,   210,    -1,   212,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,   212,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,
     212,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,   212,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,    -1,   212,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,   212,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
      -1,    -1,   210,    -1,   212,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,   212,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,   212,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,   212,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,   210,    -1,   212,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,   212,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,
     212,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,   212,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,    -1,   212,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,   212,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
      -1,    -1,   210,    -1,   212,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,   212,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,   212,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,   212,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,   210,    -1,   212,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,   212,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,
     212,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,   212,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,    -1,   212,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,   212,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
      -1,    -1,   210,    -1,   212,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,   212,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,   212,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,   212,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,   210,    -1,   212,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,   212,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,
     212,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,   212,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,    -1,   212,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,   212,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
      -1,    -1,   210,    -1,   212,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,   212,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,   212,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,   212,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,   210
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   222,   223,     6,     0,     4,    12,    13,    42,
      43,    62,    63,    64,    68,    69,    71,    75,    76,    78,
      79,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   134,   135,   136,
     142,   147,   148,   149,   150,   153,   155,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   176,   177,   178,   185,   187,   224,   226,   227,   247,
     266,   267,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   294,   296,   302,   303,   304,   305,   323,   324,     3,
       4,     5,     9,    10,    11,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    65,    66,    67,    70,
      72,    73,    74,    80,    81,   164,   171,   172,   173,   174,
     175,   179,   180,   181,   182,   183,   184,   186,   201,   202,
     206,   211,   213,   215,   216,   218,   220,   245,   306,   307,
     319,   320,   323,   324,    13,    90,   211,   211,     6,   218,
       6,     6,     6,     6,   211,     6,     6,   213,   213,   211,
     213,   245,   245,   211,   218,   211,   211,     4,   211,   218,
     211,   211,     4,   218,   211,   211,    94,    90,    90,     6,
     218,    84,    87,    90,   211,   211,    90,    90,    87,    90,
      92,    92,    84,    87,    90,    92,    87,    90,    92,    87,
      90,   211,    87,   153,   169,   170,   218,   201,   202,   211,
     218,   309,   310,   309,   218,    84,    87,    90,   218,   309,
       4,    84,    88,   102,    90,    92,    90,    87,     4,   164,
     218,   323,   324,     4,     6,    84,    87,    90,    87,    90,
       4,     4,     4,     4,     5,    37,    38,    39,    40,    41,
      84,    87,    90,    92,   106,   202,   211,   218,   267,   278,
     296,   306,   312,   313,   314,   323,   324,     4,   211,   211,
     211,     4,   218,   316,   324,     4,   211,   211,   211,     6,
       6,   213,     4,   320,   324,   211,     4,   320,     5,   218,
       5,   218,     4,   306,   323,   213,   218,     6,   211,   218,
     211,   213,   220,   245,     7,   188,   189,   190,   191,   208,
     209,   243,   244,     4,   211,   213,   215,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   211,   211,   211,   245,   245,   245,   245,   211,
     245,   245,   245,   245,   245,   245,   211,   245,   245,   245,
       7,   211,   211,   211,   245,   245,   211,   211,   213,   306,
     306,   306,   212,   306,   214,   306,     4,   153,   154,   324,
       4,   267,   268,   269,   218,   218,     6,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   210,   218,     6,   211,   213,   244,     6,   306,     4,
     319,   320,   323,   324,   319,   306,   319,   322,   249,   254,
     320,   324,   306,   202,   306,   314,   315,   306,   306,   211,
     306,   315,   306,   306,   211,   315,   306,   306,   312,   211,
     218,   315,   313,   313,   313,   319,   306,   211,   211,   313,
     313,   313,   211,   211,   211,   211,   211,   211,   312,   211,
     312,   211,   312,   218,   218,   306,     4,   312,   316,   218,
     218,   309,   309,   309,   306,   306,   201,   202,   218,   218,
     309,   218,   218,   218,   201,   202,   211,   269,   309,   218,
     211,   218,   211,   211,   211,   313,   313,   312,   211,     4,
     213,   213,   269,     6,     6,   218,   218,   218,   313,   313,
     213,   213,   213,   211,   213,   215,   245,   211,   213,   245,
     245,   245,   245,     5,   156,   218,     5,   156,     5,   156,
       5,   156,    84,    87,    90,    92,   218,   306,   314,   306,
     219,   315,     8,   203,     6,   211,   213,   245,     6,   306,
     306,   306,   215,   306,   218,   156,   306,   306,   306,   306,
       6,     6,   218,     6,   269,     6,   269,   211,   213,   218,
     211,   213,   319,   269,   312,   312,   212,   306,   214,   306,
     218,   218,   320,   312,     6,   213,   306,   306,     4,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   322,   319,   322,   319,   319,   319,   319,   319,   319,
     319,   312,   319,   319,   306,   319,   319,   319,   322,   319,
     306,   320,   306,   319,   319,   319,   319,   319,   324,   320,
     324,     7,   191,   243,   212,     7,   191,   243,   214,     7,
     243,   244,   215,     7,   245,   219,    84,    87,    90,    92,
     266,   306,   315,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   228,   306,
     306,     6,   211,   213,   215,   212,   217,   211,   213,   212,
     217,   217,   212,   217,   214,   217,   248,   214,   248,   217,
     217,   212,   203,   217,   219,   212,   212,   306,   212,   219,
     212,   212,   306,   219,   212,   212,     7,   306,   306,   219,
       6,     6,     6,   212,   212,   306,   306,     7,     7,   299,
     299,   306,   260,   306,   320,   261,   306,   320,   262,   306,
     320,   263,   306,   320,   306,     6,   306,     6,   306,     6,
     315,   315,   218,   212,     6,   218,   269,   269,   217,   217,
     217,   309,   309,   268,   268,   217,   306,   306,   306,   306,
     282,   217,   269,   306,   306,   306,   306,   306,     7,   300,
       6,     7,   306,     6,   306,   306,   219,   315,   315,   315,
       6,     6,   306,   306,   306,   306,   306,     4,   212,   214,
     218,   246,   218,   306,   314,   218,   314,   324,   306,   306,
     319,   306,    62,   306,    62,    62,    62,     5,   218,     5,
     218,     5,   218,     5,   218,   315,   212,   219,   306,   218,
     306,   314,   306,   306,   218,   246,   212,   212,   212,   153,
     217,   269,   218,     8,   212,   212,   214,   315,   219,   219,
     269,   214,   126,   295,   212,   217,   219,     7,   191,   243,
     212,     7,   191,   243,   214,   306,   315,     6,     6,   306,
     212,   214,   244,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   217,   246,   246,   246,   246,   246,
     246,   246,   217,   217,   217,   246,   217,   246,   246,   212,
     212,   217,   246,   246,   217,   246,   217,   217,   217,   217,
     246,   246,   246,   212,   246,   308,   321,     6,   217,   217,
     212,   217,   246,   217,   246,   212,   212,   214,    44,    44,
     312,     7,   243,   244,    44,    44,   312,   215,   243,   244,
     320,   306,     6,     4,     4,   218,   317,   246,   218,   218,
     218,   218,   219,   219,     8,     4,   143,   144,   145,   146,
     219,   231,   235,   238,   240,   241,   212,   214,   306,   306,
       4,     6,   198,   225,   315,   306,   306,     6,   315,   306,
       6,   319,     6,   324,     6,   319,   306,   320,     7,   306,
     314,   156,     7,     7,   212,     7,   156,     7,     7,   212,
     156,     7,     7,   306,   212,   219,   218,     6,     7,   212,
     212,   306,   312,     4,   298,     6,   212,   212,   217,   212,
     217,   212,   217,   212,   217,   212,   212,   212,   219,   219,
     315,   215,   269,   219,   219,   309,   306,   306,   219,   219,
     306,   309,   217,   217,   217,   109,   123,   131,   132,   133,
     137,   138,   139,   140,   292,   293,   309,   219,   279,   212,
     219,   212,   212,   212,   306,     6,   306,   212,   214,   214,
     219,   219,   219,   214,   214,   217,   212,   214,   315,   315,
     212,   315,   214,   214,   217,   217,   246,   217,   218,   219,
     218,   218,   218,   315,   315,   315,   315,   219,     8,   315,
     212,   214,   315,     7,     7,     7,   215,   306,   219,   306,
     306,     7,   215,   219,   219,     6,   306,   219,   218,   312,
       6,    44,    44,   312,   243,   244,    44,    44,   312,   243,
     244,   219,   219,   214,   244,   215,   244,   319,   306,   306,
     306,   306,   315,   319,   306,   312,   319,   319,   319,   256,
     258,   306,   319,   319,   306,   245,   245,     6,   306,     6,
     245,   245,     6,     4,   153,   154,   306,     6,     6,     6,
       7,   213,   316,   318,     6,   315,   315,   315,   315,   246,
     306,   232,   211,   211,   218,   242,     6,   244,   244,   212,
     214,   198,   319,   212,   212,   214,   212,   217,     7,   211,
     213,   246,   246,   309,    90,    92,   312,   312,     7,   312,
      90,    92,   312,   312,     7,    92,   312,   312,     6,     7,
       7,   315,   218,     7,     7,   109,   297,     6,     7,   243,
     306,   243,   306,   243,   306,   243,   306,     7,     7,     7,
       7,     7,   219,     4,   219,   217,   217,   217,   219,   219,
     309,   309,   309,     4,     6,   306,   218,     6,   211,     6,
     141,     6,   141,     6,   141,     6,   141,   219,   293,   217,
     292,     7,     6,     7,     7,     7,     6,   218,     6,     6,
       6,    90,     7,     6,     6,   306,   215,   219,   219,   219,
     306,   306,   306,   306,   306,   306,   306,   219,   219,   219,
     219,   306,   219,   219,   312,   312,   312,     4,   217,     8,
       8,   212,     4,     4,   217,     6,   218,   312,   219,   245,
     245,     6,   306,     6,   245,   245,     6,   306,     6,   246,
       6,     4,     6,   246,   246,   246,   246,   246,   217,   217,
     246,   212,   246,   246,   217,   217,   246,   257,   217,   246,
     259,   212,   212,   246,   246,   246,   322,   322,     6,   246,
     322,   322,     7,   243,   244,   215,     7,     6,   316,   306,
     217,   219,   219,   219,   219,   219,   243,   211,   306,   306,
     311,   312,   218,   215,     6,     6,   225,     6,   306,   218,
     306,   320,   212,   214,     6,     6,     6,   218,   218,   102,
     265,   265,   312,     6,   218,   218,     6,     6,   312,   218,
       6,     6,     5,   312,   219,   311,   312,   312,     4,     6,
     312,   312,   312,   312,   312,   312,   312,   312,   218,   218,
       7,     6,     7,   306,   306,   306,   218,   218,   217,   219,
     217,   219,   217,   219,   213,     6,   306,   312,   306,     6,
       6,     6,     6,   306,   309,   219,     5,   218,   312,   218,
     218,   218,   312,   315,   218,   306,   214,     4,   246,   212,
     214,   217,   217,   217,   217,   217,   217,   217,   246,     6,
       6,   152,   306,   306,   306,     6,     6,     7,   320,   269,
     217,     6,   246,   322,   322,     6,   246,   322,   322,     6,
     243,   244,   319,   306,   319,     4,     4,   168,     6,   246,
     246,     6,   246,   246,   320,   306,     6,     4,   317,     6,
     214,   316,     6,     6,     6,     6,   312,   229,   306,   217,
     217,   217,   219,   230,   306,     4,   319,   217,   312,   320,
       7,     7,   306,   306,   309,     6,     6,     6,   306,   306,
       6,   306,     5,     6,   218,   219,     6,   156,   264,   306,
       6,     6,     6,     6,     6,     6,     4,     6,     6,   315,
     315,   306,   306,   320,   219,   212,   217,   219,   268,   268,
     309,     6,   283,   309,     6,   284,   309,     6,   285,   306,
     219,   217,   212,   219,   217,     6,   202,   309,     6,   311,
     309,   309,     6,   219,   306,     6,     6,   306,   306,   306,
     306,   306,   306,   306,   312,   217,   219,     8,   219,   212,
     218,   306,   320,   217,   295,   312,     6,   246,   246,     6,
     246,   246,   312,   212,   246,   246,   218,   312,   320,   218,
     306,   320,   320,     6,     6,     6,     6,     6,     6,     7,
       6,   215,     6,   212,   217,   306,   306,   312,   218,   217,
     219,     6,   306,   250,   253,   218,   218,   219,   219,   219,
     219,   219,     5,   311,     6,    88,     6,   218,   219,   219,
     218,     6,     6,   218,   306,   219,   219,   217,   218,   217,
     218,   217,   218,   214,     6,   312,     7,   218,   306,   217,
     219,   217,   217,     6,   219,   246,   246,   217,   217,   217,
     217,   217,   151,   306,   306,   315,     6,     6,   320,   219,
     219,     6,     6,     6,     6,     6,   255,   306,   314,   322,
     316,   154,   233,   306,   217,   217,   311,   306,     6,   217,
     256,   258,   312,   312,     6,     6,     6,     6,     6,     6,
     219,   218,   311,   113,   114,   119,   301,   113,   114,   301,
     315,   268,   217,   219,   306,   309,   292,   306,   309,   292,
     306,   309,   292,     6,   217,   219,   312,   269,   219,   309,
       6,   315,   309,   306,   306,   306,   306,   306,   306,   219,
     219,   219,   212,     6,   217,   219,     7,     7,   219,     6,
     218,   306,   306,   219,   306,   219,   219,   252,   251,   218,
     306,   219,   218,   309,   312,     6,   218,   309,     6,   219,
     219,   306,   219,   217,   219,   219,   217,   219,   219,   217,
     219,   312,     6,   109,   219,   280,   218,   217,   219,   217,
     217,   217,   217,   217,   217,     6,     6,     6,   306,   320,
     324,   230,   212,   217,     6,   218,   217,   256,   256,   306,
     219,     6,   309,     6,   309,     6,     6,   219,     6,   286,
     306,     6,     6,   287,   306,     6,     6,   288,   306,     6,
     219,   306,   292,   269,   315,     6,   309,   315,   306,   306,
     306,   306,   306,     7,   211,   219,   236,   306,   311,   306,
     219,   219,   217,   217,   217,   218,   219,   218,   219,   218,
     219,     6,     6,   219,   219,   281,   219,   217,   219,   217,
     217,   217,   217,   217,   320,   212,     6,   218,   212,   219,
     219,   306,   309,   309,   292,     6,   289,   292,     6,   290,
     292,     6,   291,   292,     6,   315,     6,   306,   306,   306,
     306,   306,   234,   319,   239,   218,     6,   219,   217,   217,
     219,   218,   219,   218,   219,   218,   219,   219,   246,   217,
     217,   217,   217,   217,   219,   218,   311,     6,   306,   306,
       6,   292,     6,   292,     6,   292,     6,   306,   306,   306,
     306,   319,     6,   237,   319,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   217,   219,     6,     6,     6,
       6,     6,     6,   319,     6
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
#line 208 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 219 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 220 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 221 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 222 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 223 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 224 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 225 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 226 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 227 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 228 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 16:
#line 229 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 230 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 231 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 232 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 233 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 234 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 235 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 236 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 241 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 25:
#line 245 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 26:
#line 252 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 27:
#line 257 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 28:
#line 262 "Gmsh.y"
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

  case 29:
#line 276 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
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

  case 30:
#line 289 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
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

  case 31:
#line 302 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[(3) - (9)].c), (yyvsp[(5) - (9)].l), tmpstring);
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

  case 32:
#line 330 "Gmsh.y"
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

  case 33:
#line 344 "Gmsh.y"
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

  case 34:
#line 357 "Gmsh.y"
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

  case 35:
#line 370 "Gmsh.y"
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

  case 36:
#line 388 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 42:
#line 402 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 43:
#line 404 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 44:
#line 409 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 411 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 416 "Gmsh.y"
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

  case 47:
#line 520 "Gmsh.y"
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

  case 48:
#line 530 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 49:
#line 539 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 50:
#line 546 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 51:
#line 556 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    ;}
    break;

  case 52:
#line 565 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 53:
#line 574 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 54:
#line 581 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 55:
#line 591 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 56:
#line 599 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 57:
#line 609 "Gmsh.y"
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

  case 58:
#line 628 "Gmsh.y"
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

  case 59:
#line 647 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 60:
#line 653 "Gmsh.y"
    {
    ;}
    break;

  case 61:
#line 660 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 62:
#line 661 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 63:
#line 662 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 64:
#line 663 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 65:
#line 664 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 66:
#line 668 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 67:
#line 669 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 68:
#line 675 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 69:
#line 675 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 70:
#line 676 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 71:
#line 676 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 74:
#line 685 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 75:
#line 690 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 76:
#line 696 "Gmsh.y"
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

  case 77:
#line 758 "Gmsh.y"
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

  case 78:
#line 775 "Gmsh.y"
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

  case 79:
#line 804 "Gmsh.y"
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

  case 80:
#line 833 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 81:
#line 838 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 82:
#line 843 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 83:
#line 848 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 84:
#line 853 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 85:
#line 860 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 86:
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

  case 87:
#line 899 "Gmsh.y"
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

  case 88:
#line 928 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 89:
#line 933 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 90:
#line 938 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 91:
#line 943 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 92:
#line 951 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 93:
#line 960 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 94:
#line 966 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 95:
#line 972 "Gmsh.y"
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

  case 96:
#line 985 "Gmsh.y"
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

  case 97:
#line 998 "Gmsh.y"
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

  case 98:
#line 1013 "Gmsh.y"
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

  case 99:
#line 1030 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 100:
#line 1036 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 101:
#line 1042 "Gmsh.y"
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

  case 102:
#line 1055 "Gmsh.y"
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

  case 103:
#line 1068 "Gmsh.y"
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

  case 104:
#line 1083 "Gmsh.y"
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

  case 105:
#line 1100 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 106:
#line 1106 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 107:
#line 1115 "Gmsh.y"
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

  case 108:
#line 1133 "Gmsh.y"
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

  case 109:
#line 1151 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 110:
#line 1160 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 111:
#line 1172 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 112:
#line 1177 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 113:
#line 1185 "Gmsh.y"
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

  case 114:
#line 1205 "Gmsh.y"
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

  case 115:
#line 1228 "Gmsh.y"
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

  case 116:
#line 1239 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 117:
#line 1247 "Gmsh.y"
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

  case 118:
#line 1269 "Gmsh.y"
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

  case 119:
#line 1292 "Gmsh.y"
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

  case 120:
#line 1330 "Gmsh.y"
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

  case 121:
#line 1351 "Gmsh.y"
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

  case 122:
#line 1363 "Gmsh.y"
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

  case 126:
#line 1381 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 127:
#line 1390 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 128:
#line 1399 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 129:
#line 1401 "Gmsh.y"
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

  case 130:
#line 1419 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 131:
#line 1421 "Gmsh.y"
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

  case 132:
#line 1437 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 133:
#line 1439 "Gmsh.y"
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

  case 134:
#line 1455 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 135:
#line 1464 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 136:
#line 1466 "Gmsh.y"
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

  case 138:
#line 1480 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 139:
#line 1488 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 140:
#line 1494 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 141:
#line 1499 "Gmsh.y"
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

  case 144:
#line 1530 "Gmsh.y"
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

  case 145:
#line 1541 "Gmsh.y"
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

  case 146:
#line 1556 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 149:
#line 1572 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 150:
#line 1580 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 151:
#line 1589 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 152:
#line 1597 "Gmsh.y"
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

  case 153:
#line 1615 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 154:
#line 1619 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 155:
#line 1625 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 156:
#line 1633 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 157:
#line 1637 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 158:
#line 1643 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 159:
#line 1651 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 160:
#line 1655 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 161:
#line 1661 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 162:
#line 1669 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 163:
#line 1673 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 164:
#line 1679 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 165:
#line 1687 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 166:
#line 1691 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)(yyvsp[(4) - (5)].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[(4) - (5)].d));
      else{
	List_Add((yyval.l), &v);
      }
    ;}
    break;

  case 167:
#line 1703 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 168:
#line 1707 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 169:
#line 1715 "Gmsh.y"
    {
      factory = (yyvsp[(3) - (5)].c);
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 170:
#line 1723 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindPoint(num)){
        yymsg(0, "Point %d already exists", num);
      }
      else{
        double x = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[0];
        double y = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[1];
        double z = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[2];
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          GModel::current()->getOCCInternals()->addVertex(num, x, y, z);
        }
        else{
          double lc = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[3];
          if(lc == 0.) lc = MAX_LC; // no mesh size given at the point
          Vertex *v;
          if(!myGmshSurface)
            v = Create_Vertex(num, x, y, z, lc, 1.0);
          else
            v = Create_Vertex(num, x, y, myGmshSurface, lc);
          Tree_Add(GModel::current()->getGEOInternals()->Points, &v);
          AddToTemporaryBoundingBox(v->Pos.X, v->Pos.Y, v->Pos.Z);
        }
      }
      (yyval.s).Type = MSH_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 171:
#line 1751 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_POINT);
      if(p && op == 0){
	yymsg(0, "Physical point %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical point %d does not exist", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else if(op == 2){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
        if(!List_Nbr(p->Entities)){
          DeletePhysicalPoint(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical point %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 172:
#line 1794 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	Vertex *v = FindPoint((int)d);
	if(v){
	  v->lc = (yyvsp[(5) - (6)].d);
        }
	else{
	  GVertex *gv = GModel::current()->getVertexByTag((int)d);
	  if(gv)
	    gv->setPrescribedMeshSizeAtVertex((yyvsp[(5) - (6)].d));
	}
      }
      List_Delete((yyvsp[(3) - (6)].l));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 173:
#line 1817 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 174:
#line 1835 "Gmsh.y"
    {
      for (int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	double dnum;
	List_Read((yyvsp[(3) - (4)].l), i, &dnum);
	int num = (int) fabs(dnum);
	Curve *c = FindCurve(num);
	if (c){
	  c->degenerated = true;
	}
	else{
	  GEdge *ge = GModel::current()->getEdgeByTag(num);
	  if (!ge){
	    yymsg(0, "Curve %d does not exist", num);
	  }
	  else{
	    ge->setTooSmall(true);
	  }
	}
      }
    ;}
    break;

  case 175:
#line 1856 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_SPLN, 3, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_SPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 176:
#line 1874 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          if(List_Nbr((yyvsp[(6) - (8)].l)) == 3){
            double d[3];
            List_Read((yyvsp[(6) - (8)].l), 0, &d[0]); List_Read((yyvsp[(6) - (8)].l), 1, &d[1]); List_Read((yyvsp[(6) - (8)].l), 2, &d[2]);
            GModel::current()->getOCCInternals()->addCircleArc
              (num, (int)d[0], (int)d[1], (int)d[2]);
          }
        }
        else{
          List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (8)].l));
          Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
                                  -1, -1, 0., 1.);
          if((yyvsp[(7) - (8)].v)[0] || (yyvsp[(7) - (8)].v)[1] || (yyvsp[(7) - (8)].v)[2]){
            c->Circle.n[0] = (yyvsp[(7) - (8)].v)[0];
            c->Circle.n[1] = (yyvsp[(7) - (8)].v)[1];
            c->Circle.n[2] = (yyvsp[(7) - (8)].v)[2];
            End_Curve(c);
          }
          Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
          Curve *rc = CreateReversedCurve(c);
          if((yyvsp[(7) - (8)].v)[0] || (yyvsp[(7) - (8)].v)[1] || (yyvsp[(7) - (8)].v)[2]){
            rc->Circle.n[0] = (yyvsp[(7) - (8)].v)[0];
            rc->Circle.n[1] = (yyvsp[(7) - (8)].v)[1];
            rc->Circle.n[2] = (yyvsp[(7) - (8)].v)[2];
            End_Curve(rc);
          }
          List_Delete(temp);
        }
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    ;}
    break;

  case 177:
#line 1914 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (8)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
        if((yyvsp[(7) - (8)].v)[0] || (yyvsp[(7) - (8)].v)[1] || (yyvsp[(7) - (8)].v)[2]){
          c->Circle.n[0] = (yyvsp[(7) - (8)].v)[0];
          c->Circle.n[1] = (yyvsp[(7) - (8)].v)[1];
          c->Circle.n[2] = (yyvsp[(7) - (8)].v)[2];
          End_Curve(c);
        }
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	Curve *rc = CreateReversedCurve(c);
        if((yyvsp[(7) - (8)].v)[0] || (yyvsp[(7) - (8)].v)[1] || (yyvsp[(7) - (8)].v)[2]){
          rc->Circle.n[0] = (yyvsp[(7) - (8)].v)[0];
          rc->Circle.n[1] = (yyvsp[(7) - (8)].v)[1];
          rc->Circle.n[2] = (yyvsp[(7) - (8)].v)[2];
          End_Curve(rc);
        }
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    ;}
    break;

  case 178:
#line 1944 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_BSPLN, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 179:
#line 1962 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_BEZIER, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BEZIER;
      (yyval.s).Num = num;
    ;}
    break;

  case 180:
#line 1981 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (11)].d);
      if(List_Nbr((yyvsp[(6) - (11)].l)) + (int)(yyvsp[(10) - (11)].d) + 1 != List_Nbr((yyvsp[(8) - (11)].l))){
	yymsg(0, "Wrong definition of Nurbs Curve %d: "
	      "got %d knots, need N + D + 1 = %d + %d + 1 = %d",
	      (int)(yyvsp[(3) - (11)].d), List_Nbr((yyvsp[(8) - (11)].l)), List_Nbr((yyvsp[(6) - (11)].l)), (int)(yyvsp[(10) - (11)].d), List_Nbr((yyvsp[(6) - (11)].l)) + (int)(yyvsp[(10) - (11)].d) + 1);
      }
      else{
	if(FindCurve(num)){
	  yymsg(0, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (11)].l));
	  Curve *c = Create_Curve(num, MSH_SEGM_NURBS, (int)(yyvsp[(10) - (11)].d), temp, (yyvsp[(8) - (11)].l),
				  -1, -1, 0., 1.);
	  Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	  CreateReversedCurve(c);
	  List_Delete(temp);
	}
      }
      List_Delete((yyvsp[(6) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
      (yyval.s).Type = MSH_SEGM_NURBS;
      (yyval.s).Num = num;
    ;}
    break;

  case 181:
#line 2007 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindEdgeLoop(num)){
	yymsg(0, "Line loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	sortEdgesInLoop(num, temp);
	EdgeLoop *l = Create_EdgeLoop(num, temp);
	Tree_Add(GModel::current()->getGEOInternals()->EdgeLoops, &l);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 182:
#line 2026 "Gmsh.y"
    {
     GModel::current()->getGEOInternals()->addCompoundMesh ( 1 , (yyvsp[(3) - (4)].l) );
   ;}
    break;

  case 183:
#line 2031 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
        Curve *c = Create_Curve(num, MSH_SEGM_COMPOUND, 1, NULL, NULL, -1, -1, 0., 1.);
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++)
          c->compound.push_back((int)*(double*)List_Pointer((yyvsp[(7) - (8)].l), i));
	End_Curve(c);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SEGM_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 184:
#line 2049 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_LINE);
      if(p && op == 0){
	yymsg(0, "Physical line %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical line %d does not exist", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else if(op == 2){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
        if(!List_Nbr(p->Entities)){
          DeletePhysicalLine(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical line %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 185:
#line 2095 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_PLAN);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	setSurfaceGeneratrices(s, temp);
	List_Delete(temp);
	End_Surface(s);
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 186:
#line 2113 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (9)].d), type = 0;
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	double d;
	List_Read((yyvsp[(7) - (9)].l), 0, &d);
	EdgeLoop *el = FindEdgeLoop((int)fabs(d));
	if(!el){
	  yymsg(0, "Unknown line loop %d", (int)d);
	}
	else{
	  int j = List_Nbr(el->Curves);
	  if(j == 4){
	    type = MSH_SURF_REGL;
	  }
	  else if(j == 3){
	    type = MSH_SURF_TRIC;
	  }
	  else{
	    yymsg(0, "Wrong definition of Ruled Surface %d: "
		  "%d borders instead of 3 or 4", num, j);
	    type = MSH_SURF_PLAN;
	  }
	  Surface *s = Create_Surface(num, type);
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
	  setSurfaceGeneratrices(s, temp);
	  List_Delete(temp);
	  End_Surface(s);
	  s->InSphereCenter = (yyvsp[(8) - (9)].l);
	  Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
	}
      }
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type = type;
      (yyval.s).Num = num;
    ;}
    break;

  case 187:
#line 2152 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 188:
#line 2158 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 189:
#line 2164 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 190:
#line 2171 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(List_Nbr((yyvsp[(6) - (7)].l)) == 4){ // solid sphere (volume)
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          double x; List_Read((yyvsp[(6) - (7)].l), 0, &x);
          double y; List_Read((yyvsp[(6) - (7)].l), 1, &y);
          double z; List_Read((yyvsp[(6) - (7)].l), 2, &z);
          double r; List_Read((yyvsp[(6) - (7)].l), 3, &r);
          GModel::current()->getOCCInternals()->addSphere(num, x, y, z, r);
        }
        else{
          yymsg(0, "Sphere only available in OpenCASCADE factory");
        }
        (yyval.s).Type = MSH_VOLUME;
      }
      else{
        if (List_Nbr((yyvsp[(6) - (7)].l)) != 2){
          yymsg(0, "Sphere %d has to be defined using 2 points (center + "
                "any point) and not %d", num, List_Nbr((yyvsp[(6) - (7)].l)));
        }
        else{
          double p1,p2;
          List_Read((yyvsp[(6) - (7)].l), 0, &p1);
          List_Read((yyvsp[(6) - (7)].l), 1, &p2);
          Vertex *v1 = FindPoint((int)p1);
          Vertex *v2 = FindPoint((int)p2);
          if(!v1) yymsg(0, "Sphere %d : unknown point %d", num, (int)p1);
          if(!v2) yymsg(0, "Sphere %d : unknown point %d", num, (int)p2);
          if(v1 && v2)
            myGmshSurface = gmshSphere::NewSphere
              (num, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
               sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
                    (v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
                    (v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
        }
        (yyval.s).Type = 0;
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Num = num;
    ;}
    break;

  case 191:
#line 2212 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if (List_Nbr((yyvsp[(6) - (7)].l)) != 2){
	yymsg(0, "PolarSphere %d has to be defined using 2 points (center + "
	      "any point) and not %d", num, List_Nbr((yyvsp[(6) - (7)].l)));
      }
      else{
	double p1,p2;
	List_Read((yyvsp[(6) - (7)].l), 0, &p1);
	List_Read((yyvsp[(6) - (7)].l), 1, &p2);
	Vertex *v1 = FindPoint((int)p1);
	Vertex *v2 = FindPoint((int)p2);
	if(!v1) yymsg(0, "PolarSphere %d : unknown point %d", num, (int)p1);
	if(!v2) yymsg(0, "PolarSphere %d : unknown point %d", num, (int)p2);
	if(v1 && v2)
	  myGmshSurface = gmshPolarSphere::NewPolarSphere
	    (num, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
	     sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
		  (v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
		  (v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 192:
#line 2238 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurfaceLoop(num)){
	yymsg(0, "Surface loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	SurfaceLoop *l = Create_SurfaceLoop(num, temp);
	Tree_Add(GModel::current()->getGEOInternals()->SurfaceLoops, &l);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 193:
#line 2255 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 2 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 194:
#line 2259 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_COMPOUND);
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          s->compound.push_back((int)*(double*)List_Pointer((yyvsp[(7) - (8)].l), i));
	}
        // Added by Trevor Strickler
	setSurfaceGeneratrices(s, (List_T*) 0);
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 195:
#line 2279 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (12)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
        Surface *s = Create_Surface(num, MSH_SURF_COMPOUND);
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (12)].l)); i++)
          s->compound.push_back((int)*(double*)List_Pointer((yyvsp[(7) - (12)].l), i));
	for (int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++){
          if(i > 3){
            yymsg(0, "Too many boundary specifiers in compound surface");
            break;
          }
	  List_T *l = *(List_T**)List_Pointer((yyvsp[(10) - (12)].l), i);
          for (int j = 0; j < List_Nbr(l); j++){
            s->compoundBoundary[i].push_back((int)*(double*)List_Pointer(l, j));
	  }
	}
        // Added by Trevor Strickler
        setSurfaceGeneratrices(s, (List_T*) 0 );

	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (12)].l));
      for (int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(10) - (12)].l), i));
      List_Delete((yyvsp[(10) - (12)].l));
      Free((yyvsp[(8) - (12)].c));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 196:
#line 2312 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE);
      if(p && op == 0){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical surface %d does not exist", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else if(op == 2){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
        if(!List_Nbr(p->Entities)){
          DeletePhysicalSurface(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical surface %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    ;}
    break;

  case 197:
#line 2359 "Gmsh.y"
    {
      yymsg(0, "'Complex Volume' command is deprecated: use 'Volume' instead");
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 198:
#line 2377 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 199:
#line 2394 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (9)].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          std::vector<std::vector<int> > edges;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
            List_T *l; List_Read((yyvsp[(7) - (9)].l), i, &l);
            std::vector<int> v;
            for(int j = 0; j < List_Nbr(l); j++){
              double d = 0; List_Read(l, j, &d); v.push_back(d);
            }
            edges.push_back(v);
          }
          GModel::current()->getOCCInternals()->addThruSections(num, edges);
        }
        else{
          yymsg(0, "ThruSections only available in OpenCASCADE factory");
        }
      }
      for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(7) - (9)].l), i));
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 200:
#line 2423 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 3 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 201:
#line 2427 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME_COMPOUND);
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++)
          v->compound.push_back((int)*(double*)List_Pointer((yyvsp[(7) - (8)].l), i));
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 202:
#line 2443 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME);
      if(p && op == 0){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical volume %d does not exist", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else if(op == 2){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
        if(!List_Nbr(p->Entities)){
          DeletePhysicalVolume(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical volume %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 203:
#line 2491 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 204:
#line 2496 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 205:
#line 2501 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 206:
#line 2506 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 207:
#line 2511 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 208:
#line 2516 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
      if(!strcmp((yyvsp[(1) - (4)].c), "Duplicata")){
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          Shape TheShape;
          List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
          CopyShape(TheShape.Type, TheShape.Num, &TheShape.Num);
          List_Add((yyval.l), &TheShape);
        }
      }
      else if(!strcmp((yyvsp[(1) - (4)].c), "Boundary")){
        BoundaryShapes((yyvsp[(3) - (4)].l), (yyval.l), false);
      }
      else if(!strcmp((yyvsp[(1) - (4)].c), "CombinedBoundary")){
        BoundaryShapes((yyvsp[(3) - (4)].l), (yyval.l), true);
      }
      else{
        yymsg(0, "Unknown command on multiple shapes: '%s'", (yyvsp[(1) - (4)].c));
      }
      Free((yyvsp[(1) - (4)].c));
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 209:
#line 2539 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 210:
#line 2545 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 211:
#line 2555 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 212:
#line 2556 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 213:
#line 2561 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 214:
#line 2565 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 215:
#line 2569 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Vertex *v = FindPoint(std::abs(TheShape.Num));
	if(v){
	  TheShape.Type = MSH_POINT;
	  List_Add((yyval.l), &TheShape);
	}
	else{
	  GVertex *gv = GModel::current()->getVertexByTag(std::abs(TheShape.Num));
	  if(gv){
	    TheShape.Type = MSH_POINT_FROM_GMODEL;
	    List_Add((yyval.l), &TheShape);
	  }
	  else{
            if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
              TheShape.Type = MSH_UNKNOWN;
              List_Add((yyval.l), &TheShape);
            }
            else
              yymsg(1, "Unknown point %d", TheShape.Num);
          }
	}
      }
    ;}
    break;

  case 216:
#line 2598 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Curve *c = FindCurve(std::abs(TheShape.Num));
	if(c){
	  TheShape.Type = c->Typ;
	  List_Add((yyval.l), &TheShape);
	}
	else{
	  GEdge *ge = GModel::current()->getEdgeByTag(std::abs(TheShape.Num));
	  if(ge){
	    TheShape.Type = MSH_SEGM_FROM_GMODEL;
	    List_Add((yyval.l), &TheShape);
	  }
	  else{
            if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
              TheShape.Type = MSH_UNKNOWN;
              List_Add((yyval.l), &TheShape);
            }
            else
              yymsg(1, "Unknown curve %d", TheShape.Num);
          }
	}
      }
    ;}
    break;

  case 217:
#line 2627 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Surface *s = FindSurface(std::abs(TheShape.Num));
	if(s){
	  TheShape.Type = s->Typ;
	  List_Add((yyval.l), &TheShape);
	}
	else{
	  GFace *gf = GModel::current()->getFaceByTag(std::abs(TheShape.Num));
	  if(gf){
	    TheShape.Type = MSH_SURF_FROM_GMODEL;
	    List_Add((yyval.l), &TheShape);
	  }
	  else{
            if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
              TheShape.Type = MSH_UNKNOWN;
              List_Add((yyval.l), &TheShape);
            }
            else
              yymsg(1, "Unknown surface %d", TheShape.Num);
          }
	}
      }
    ;}
    break;

  case 218:
#line 2656 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Volume *v = FindVolume(std::abs(TheShape.Num));
	if(v){
	  TheShape.Type = v->Typ;
	  List_Add((yyval.l), &TheShape);
	}
	else{
	  GRegion *gr = GModel::current()->getRegionByTag(std::abs(TheShape.Num));
	  if(gr){
	    TheShape.Type = MSH_VOLUME_FROM_GMODEL;
	    List_Add((yyval.l), &TheShape);
	  }
	  else{
            if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
              TheShape.Type = MSH_UNKNOWN;
              List_Add((yyval.l), &TheShape);
            }
            else
              yymsg(1, "Unknown volume %d", TheShape.Num);
          }
	}
      }
    ;}
    break;

  case 219:
#line 2690 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(7) - (8)].l)) == 4){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[4];
          for(int i = 0; i < 4; i++)
            List_Read((yyvsp[(7) - (8)].l), i, &d[i]);
          gLevelset *ls = new gLevelsetPlane(d[0], d[1], d[2], d[3], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (8)].d));
#endif
    ;}
    break;

  case 220:
#line 2711 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      int t = (int)(yyvsp[(4) - (10)].d);
      if(FindLevelSet(t)){
	yymsg(0, "Levelset %d already exists", t);
      }
      else {
	//Msg::Info("nb = %d \n",List_Nbr($8) );
	fullMatrix<double> centers(List_Nbr((yyvsp[(8) - (10)].l)),3);
	for (int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++){
	  List_T *l = *(List_T**)List_Pointer((yyvsp[(8) - (10)].l), i);
	  for (int j = 0; j < List_Nbr(l); j++){
	    //Msg::Info("nb j = %d \n",List_Nbr(l) );
	    centers(i,j) = (double)(*(double*)List_Pointer(l, j));
	  }
	}
        gLevelset *ls = new gLevelsetPoints(centers, t);
        LevelSet *l = Create_LevelSet(ls->getTag(), ls);
        Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(8) - (10)].l), i));
      List_Delete((yyvsp[(8) - (10)].l));
#endif
    ;}
    break;

  case 221:
#line 2738 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 0){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double n[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetPlane(pt, n, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (14)].d));
#endif
    ;}
    break;

  case 222:
#line 2759 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(14) - (16)].l)) == 0){
        int t = (int)(yyvsp[(4) - (16)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double pt1[3] = {(yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2]};
          double pt2[3] = {(yyvsp[(10) - (16)].v)[0], (yyvsp[(10) - (16)].v)[1], (yyvsp[(10) - (16)].v)[2]};
          double pt3[3] = {(yyvsp[(12) - (16)].v)[0], (yyvsp[(12) - (16)].v)[1], (yyvsp[(12) - (16)].v)[2]};
          gLevelset *ls = new gLevelsetPlane(pt1, pt2, pt3, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (16)].d));
#endif
    ;}
    break;

  case 223:
#line 2780 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(10) - (12)].l)) == 1){
        int t = (int)(yyvsp[(4) - (12)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(10) - (12)].l), 0, &d);
          gLevelset *ls = new gLevelsetSphere((yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (12)].d));
#endif
    ;}
    break;

  case 224:
#line 2800 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (8)].c), "Union")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Union %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetUnion(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Intersection")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Intersection %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetIntersection(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Cut")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Cut %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetCut(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Crack")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Crack %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetCrack(vl);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Reverse")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(7) - (8)].l), 0, &d);
          LevelSet *pl = FindLevelSet((int)d);
          gLevelset *ls = NULL;
          if(!pl) yymsg(0, "Levelset Reverse %d : unknown levelset %d", t, (int)d);
          else ls = new gLevelsetReverse(pl->ls);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
#if defined(HAVE_POST)
      else if(!strcmp((yyvsp[(2) - (8)].c), "PostView")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          if(List_Nbr((yyvsp[(7) - (8)].l)) > 0){
            double d; List_Read((yyvsp[(7) - (8)].l), 0, &d);
            gLevelset *ls = new gLevelsetPostView((int)d, t);
            LevelSet *l = Create_LevelSet(ls->getTag(), ls);
            Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
          }
        }
      }
#endif
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (8)].d));
      Free((yyvsp[(2) - (8)].c));
#endif
    ;}
    break;

  case 225:
#line 2912 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (8)].c), "MathEval")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          gLevelset *ls = new gLevelsetMathEval((yyvsp[(7) - (8)].c), t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition");
      Free((yyvsp[(2) - (8)].c)); Free((yyvsp[(7) - (8)].c));
#endif
    ;}
    break;

  case 226:
#line 2931 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (6)].c), "CutMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        if(FindLevelSet(t)){
          GM->buildCutGModel(FindLevelSet(t)->ls, true, false);
          GM->setVisibility(0);
        }
        else
          yymsg(0, "Unknown levelset (%d)", t);
      }
      else if(!strcmp((yyvsp[(2) - (6)].c), "CutMeshTri")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        if(FindLevelSet(t)){
          GM->buildCutGModel(FindLevelSet(t)->ls, true, true);
          GM->setVisibility(0);
        }
        else
          yymsg(0, "Unknown levelset (%d)", t);
      }
      else if(!strcmp((yyvsp[(2) - (6)].c), "SplitMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        if(FindLevelSet(t)){
          GM->buildCutGModel(FindLevelSet(t)->ls, false, true);
          GM->setVisibility(0);
        }
        else
          yymsg(0, "Unknown levelset (%d)", t);
      }
      else
        yymsg(0, "Wrong levelset definition");
      Free((yyvsp[(2) - (6)].c));
#endif
    ;}
    break;

  case 227:
#line 2970 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (14)].c), "Cylinder") && List_Nbr((yyvsp[(12) - (14)].l)) == 1){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(12) - (14)].l), 0, &d);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetGenCylinder(pt, dir, d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Cone") && List_Nbr((yyvsp[(12) - (14)].l)) == 1){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(12) - (14)].l), 0, &d);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCone(pt, dir, d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Cylinder") && List_Nbr((yyvsp[(12) - (14)].l)) == 2){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[2];
          for(int i = 0; i < 2; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Cylinder") && List_Nbr((yyvsp[(12) - (14)].l)) == 3){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], d[2], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Ellipsoid") && List_Nbr((yyvsp[(12) - (14)].l)) == 3){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetEllipsoid(pt, dir, d[0], d[1], d[2], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Quadric") && List_Nbr((yyvsp[(12) - (14)].l)) == 5){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
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
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (14)].d));
      Free((yyvsp[(2) - (14)].c));
#endif
    ;}
    break;

  case 228:
#line 3078 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 229:
#line 3087 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 230:
#line 3093 "Gmsh.y"
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

  case 231:
#line 3108 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Meshes") || !strcmp((yyvsp[(2) - (3)].c), "All")){
        ClearProject();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Model")){
	GModel::current()->destroy(true); // destroy, but keep name/filename
	GModel::current()->getGEOInternals()->destroy();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Physicals")){
	GModel::current()->getGEOInternals()->reset_physicals();
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

  case 232:
#line 3136 "Gmsh.y"
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

  case 233:
#line 3153 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 234:
#line 3162 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 235:
#line 3176 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 236:
#line 3190 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 237:
#line 3196 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 238:
#line 3202 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 239:
#line 3211 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 240:
#line 3220 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 241:
#line 3229 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 242:
#line 3243 "Gmsh.y"
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
	// make sure we have the latest data from GEO_Internals in GModel
	// (fixes bug where we would have no geometry in the picture if
	// the print command is in the same file as the geometry)
	GModel::current()->importGEOInternals();
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->print.fileFormat);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Save")){
	GModel::current()->importGEOInternals();
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->mesh.fileFormat);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Merge") || !strcmp((yyvsp[(1) - (3)].c), "MergeWithBoundingBox")){
	// MergeWithBoundingBox is deprecated
        // sync model with new DB here, so that if we e.g. import a STEP file,
        // we have the correct entity tags and the numberings don't clash
	GModel::current()->importGEOInternals();
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
#line 3305 "Gmsh.y"
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
#line 3323 "Gmsh.y"
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
#line 3340 "Gmsh.y"
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
#line 3355 "Gmsh.y"
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
	GModel::current()->importGEOInternals();
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
#line 3384 "Gmsh.y"
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
#line 3396 "Gmsh.y"
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
#line 3420 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 250:
#line 3424 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 251:
#line 3429 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
      GModel::current()->importOCCInternals();
    ;}
    break;

  case 252:
#line 3437 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 253:
#line 3442 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 254:
#line 3448 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 255:
#line 3453 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 256:
#line 3459 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 257:
#line 3467 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 258:
#line 3471 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 259:
#line 3475 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 260:
#line 3481 "Gmsh.y"
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
          LevelSet *l = FindLevelSet((int)d);
          if(l) f.push_back(l->ls);
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
            GModel::current()->importGEOInternals();
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
#line 3540 "Gmsh.y"
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
#line 3556 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[(3) - (6)].d) > (yyvsp[(5) - (6)].d))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    ;}
    break;

  case 263:
#line 3573 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[(7) - (8)].d) > 0. && (yyvsp[(3) - (8)].d) > (yyvsp[(5) - (8)].d)) || ((yyvsp[(7) - (8)].d) < 0. && (yyvsp[(3) - (8)].d) < (yyvsp[(5) - (8)].d)))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    ;}
    break;

  case 264:
#line 3590 "Gmsh.y"
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
	skip_until("For", "EndFor");
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
#line 3612 "Gmsh.y"
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
	skip_until("For", "EndFor");
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
#line 3634 "Gmsh.y"
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
#line 3669 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 268:
#line 3677 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 269:
#line 3685 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 270:
#line 3691 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 271:
#line 3698 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 272:
#line 3705 "Gmsh.y"
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
        skip_until_test("If", "EndIf", "ElseIf", 4, &type_until2);
        if(!type_until2) ImbricatedTest--; // EndIf reached
      }
    ;}
    break;

  case 273:
#line 3725 "Gmsh.y"
    {
      if(ImbricatedTest > 0){
        if (statusImbricatedTests[ImbricatedTest]){
          // Last test (If or ElseIf) was true, thus go after EndIf (out of If EndIf)
          skip_until("If", "EndIf");
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
            skip_until_test("If", "EndIf", "ElseIf", 4, &type_until2);
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
#line 3751 "Gmsh.y"
    {
      if(ImbricatedTest > 0){
        if(statusImbricatedTests[ImbricatedTest]){
          skip_until("If", "EndIf");
          ImbricatedTest--;
        }
      }
      else{
	yymsg(0, "Orphan Else");
      }
    ;}
    break;

  case 275:
#line 3763 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 276:
#line 3775 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 277:
#line 3783 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 278:
#line 3791 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 279:
#line 3799 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 280:
#line 3805 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 281:
#line 3813 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 282:
#line 3819 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 283:
#line 3827 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 284:
#line 3833 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 285:
#line 3841 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 286:
#line 3847 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 287:
#line 3855 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 288:
#line 3862 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 289:
#line 3869 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 290:
#line 3876 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 291:
#line 3883 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 292:
#line 3890 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 293:
#line 3897 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 294:
#line 3904 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 295:
#line 3911 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 296:
#line 3918 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 297:
#line 3924 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 298:
#line 3931 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 299:
#line 3937 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 300:
#line 3944 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 301:
#line 3950 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 302:
#line 3957 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 303:
#line 3963 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 304:
#line 3970 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 305:
#line 3976 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 306:
#line 3983 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 307:
#line 3989 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 308:
#line 3996 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 309:
#line 4002 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 310:
#line 4009 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 311:
#line 4015 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 312:
#line 4022 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 313:
#line 4028 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 314:
#line 4039 "Gmsh.y"
    {
    ;}
    break;

  case 315:
#line 4042 "Gmsh.y"
    {
    ;}
    break;

  case 316:
#line 4048 "Gmsh.y"
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

  case 317:
#line 4060 "Gmsh.y"
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

  case 318:
#line 4080 "Gmsh.y"
    {
      yymsg(0, "Explicit region numbers in layers are deprecated");
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[(3) - (9)].l));
      if(List_Nbr((yyvsp[(3) - (9)].l)) == List_Nbr((yyvsp[(5) - (9)].l)) && List_Nbr((yyvsp[(3) - (9)].l)) == List_Nbr((yyvsp[(7) - (9)].l))){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
	  double d;
	  List_Read((yyvsp[(3) - (9)].l), i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read((yyvsp[(7) - (9)].l), i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else
	yymsg(0, "Wrong layer definition {%d, %d, %d}", List_Nbr((yyvsp[(3) - (9)].l)),
	      List_Nbr((yyvsp[(5) - (9)].l)), List_Nbr((yyvsp[(7) - (9)].l)));
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(5) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 319:
#line 4104 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 320:
#line 4108 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 321:
#line 4112 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 322:
#line 4116 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 323:
#line 4120 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 324:
#line 4124 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 325:
#line 4130 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 326:
#line 4136 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 327:
#line 4140 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 328:
#line 4144 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 329:
#line 4148 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 330:
#line 4152 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (9)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
	extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
	extr.mesh.Holes[num].second.clear();
	for(int i = 0; i < List_Nbr((yyvsp[(6) - (9)].l)); i++){
	  double d;
	  List_Read((yyvsp[(6) - (9)].l), i, &d);
	  extr.mesh.Holes[num].second.push_back((int)d);
	}
      }
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 331:
#line 4171 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 332:
#line 4183 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fuse; ;}
    break;

  case 333:
#line 4184 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 334:
#line 4185 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Cut; ;}
    break;

  case 335:
#line 4189 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 336:
#line 4190 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 337:
#line 4191 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 338:
#line 4195 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> shape[4], tool[4];
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
          Shape s; List_Read((yyvsp[(3) - (9)].l), i, &s); shape[3].push_back(s.Num);
        }
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
          Shape s; List_Read((yyvsp[(7) - (9)].l), i, &s); tool[3].push_back(s.Num);
        }
        GModel::current()->getOCCInternals()->applyBooleanOperator
          (-1, shape, tool, (OCC_Internals::BooleanOperator)(yyvsp[(1) - (9)].i), (yyvsp[(4) - (9)].i), (yyvsp[(8) - (9)].i));
        // FIXME add to returned list of shapes
      }
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 339:
#line 4216 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 340:
#line 4220 "Gmsh.y"
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

  case 341:
#line 4235 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 342:
#line 4239 "Gmsh.y"
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

  case 343:
#line 4255 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 344:
#line 4259 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 345:
#line 4264 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 346:
#line 4268 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 347:
#line 4274 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 348:
#line 4278 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 349:
#line 4285 "Gmsh.y"
    {
      int type = (int)(yyvsp[(6) - (7)].v)[0];
      double coef = fabs((yyvsp[(6) - (7)].v)[1]);
      if(!(yyvsp[(3) - (7)].l)){
        List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Curves);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Curve *c;
            List_Read(tmp, i, &c);
            c->Method = MESH_TRANSFINITE;
            c->nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
            c->typeTransfinite = type;
            c->coeffTransfinite = coef;
          }
        }
        else{
          for(GModel::eiter it = GModel::current()->firstEdge();
              it != GModel::current()->lastEdge(); it++){
            (*it)->meshAttributes.method = MESH_TRANSFINITE;
            (*it)->meshAttributes.nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
            (*it)->meshAttributes.typeTransfinite = type;
            (*it)->meshAttributes.coeffTransfinite = coef;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (7)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (7)].l), i, &d);
          int j = (int)fabs(d);
          for(int sig = -1; sig <= 1; sig += 2){
            Curve *c = FindCurve(sig * j);
            if(c){
              c->Method = MESH_TRANSFINITE;
              c->nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
              c->typeTransfinite = type * gmsh_sign(d);
              c->coeffTransfinite = coef;
            }
            else{
              GEdge *ge = GModel::current()->getEdgeByTag(sig * j);
              if(ge){
                ge->meshAttributes.method = MESH_TRANSFINITE;
                ge->meshAttributes.nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
                ge->meshAttributes.typeTransfinite = type * gmsh_sign(d);
                ge->meshAttributes.coeffTransfinite = coef;
              }
              else if(sig > 0)
                yymsg(0, "Unknown line %d", j);
            }
          }
        }
        List_Delete((yyvsp[(3) - (7)].l));
      }
    ;}
    break;

  case 350:
#line 4341 "Gmsh.y"
    {
      int k = List_Nbr((yyvsp[(4) - (6)].l));
      if(k != 0 && k != 3 && k != 4){
        yymsg(0, "Wrong definition of Transfinite Surface: 0, 3 or 4 points needed");
      }
      else{
        if(!(yyvsp[(3) - (6)].l)){
          List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
          if(List_Nbr(tmp)){
            for(int i = 0; i < List_Nbr(tmp); i++){
              Surface *s;
              List_Read(tmp, i, &s);
              s->Method = MESH_TRANSFINITE;
              s->Recombine_Dir = (yyvsp[(5) - (6)].i);
              List_Reset(s->TrsfPoints);
            }
          }
          else{
            for(GModel::fiter it = GModel::current()->firstFace();
                it != GModel::current()->lastFace(); it++){
              (*it)->meshAttributes.method = MESH_TRANSFINITE;
              (*it)->meshAttributes.transfiniteArrangement = (yyvsp[(5) - (6)].i);
            }
          }
          List_Delete(tmp);
        }
        else{
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (6)].l), i, &d);
            Surface *s = FindSurface((int)d);
            if(s){
              s->Method = MESH_TRANSFINITE;
              s->Recombine_Dir = (yyvsp[(5) - (6)].i);
              List_Reset(s->TrsfPoints);
              for(int j = 0; j < k; j++){
                double p;
                List_Read((yyvsp[(4) - (6)].l), j, &p);
                Vertex *v = FindPoint((int)fabs(p));
                if(v)
                  List_Add(s->TrsfPoints, &v);
                else
                  yymsg(0, "Unknown point %d", (int)fabs(p));
              }
            }
            else{
              GFace *gf = GModel::current()->getFaceByTag((int)d);
              if(gf){
                gf->meshAttributes.method = MESH_TRANSFINITE;
                gf->meshAttributes.transfiniteArrangement = (yyvsp[(5) - (6)].i);
                for(int j = 0; j < k; j++){
                  double p;
                  List_Read((yyvsp[(4) - (6)].l), j, &p);
                  GVertex *gv = GModel::current()->getVertexByTag((int)fabs(p));
                  if(gv)
                    gf->meshAttributes.corners.push_back(gv);
                  else
                    yymsg(0, "Unknown point %d", (int)fabs(p));
                }
              }
              else
                yymsg(0, "Unknown surface %d", (int)d);
            }
          }
          List_Delete((yyvsp[(3) - (6)].l));
        }
      }
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 351:
#line 4411 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 352:
#line 4416 "Gmsh.y"
    {
      int k = List_Nbr((yyvsp[(4) - (5)].l));
      if(k != 0 && k != 6 && k != 8){
        yymsg(0, "Wrong definition of Transfinite Volume: "
              "%d points instead of 6 or 8", k);
      }
      else{
        if(!(yyvsp[(3) - (5)].l)){
          List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Volumes);
          if(List_Nbr(tmp)){
            for(int i = 0; i < List_Nbr(tmp); i++){
              Volume *v;
              List_Read(tmp, i, &v);
              v->Method = MESH_TRANSFINITE;
              List_Reset(v->TrsfPoints);
            }
          }
          else{
            for(GModel::riter it = GModel::current()->firstRegion();
                it != GModel::current()->lastRegion(); it++){
              (*it)->meshAttributes.method = MESH_TRANSFINITE;
            }
          }
          List_Delete(tmp);
        }
        else{
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (5)].l), i, &d);
            Volume *v = FindVolume((int)d);
            if(v){
              v->Method = MESH_TRANSFINITE;
              List_Reset(v->TrsfPoints);
              for(int i = 0; i < k; i++){
                double p;
                List_Read((yyvsp[(4) - (5)].l), i, &p);
                Vertex *vert = FindPoint((int)fabs(p));
                if(vert)
                  List_Add(v->TrsfPoints, &vert);
                else
                  yymsg(0, "Unknown point %d", (int)fabs(p));
              }
            }
            else{
              GRegion *gr = GModel::current()->getRegionByTag((int)d);
              if(gr){
                gr->meshAttributes.method = MESH_TRANSFINITE;
                for(int i = 0; i < k; i++){
                  double p;
                  List_Read((yyvsp[(4) - (5)].l), i, &p);
                  GVertex *gv = GModel::current()->getVertexByTag((int)fabs(p));
                  if(gv)
                    gr->meshAttributes.corners.push_back(gv);
                  else
                    yymsg(0, "Unknown point %d", (int)fabs(p));
                }
              }
              else
                yymsg(0, "Unknown volume %d", (int)d);
            }
          }
          List_Delete((yyvsp[(3) - (5)].l));
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 353:
#line 4483 "Gmsh.y"
    {
      if(!(yyvsp[(2) - (3)].l)){
  	  List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Volumes);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Volume *v;
            List_Read(tmp, i, &v);
            v->QuadTri = TRANSFINITE_QUADTRI_1;
          }
        }
        else{
          for(GModel::riter it = GModel::current()->firstRegion();
              it != GModel::current()->lastRegion(); it++)
            (*it)->meshAttributes.QuadTri = TRANSFINITE_QUADTRI_1;
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(2) - (3)].l)); i++){
          double d;
          List_Read((yyvsp[(2) - (3)].l), i, &d);
          Volume *v = FindVolume((int)d);
          if(v)
            v->QuadTri = TRANSFINITE_QUADTRI_1;
          else{
            GRegion *gr = GModel::current()->getRegionByTag((int)d);
            if(gr)
              gr->meshAttributes.QuadTri = TRANSFINITE_QUADTRI_1;
            else
              yymsg(1, "Unknown volume %d", (int)d);
          }
        }
        List_Delete((yyvsp[(2) - (3)].l));
      }
    ;}
    break;

  case 354:
#line 4519 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 355:
#line 4527 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (5)].l)){
	List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Surface *s;
            List_Read(tmp, i, &s);
            s->Recombine = 1;
            s->RecombineAngle = (yyvsp[(4) - (5)].i);
          }
        }
        else{
          for(GModel::fiter it = GModel::current()->firstFace();
              it != GModel::current()->lastFace(); it++){
            (*it)->meshAttributes.recombine = 1;
            (*it)->meshAttributes.recombineAngle = (yyvsp[(4) - (5)].i);
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (5)].l), i, &d);
          Surface *s = FindSurface((int)d);
          if(s){
            s->Recombine = 1;
            s->RecombineAngle = (yyvsp[(4) - (5)].i);
          }
          else{
            GFace *gf = GModel::current()->getFaceByTag((int)d);
            if(gf){
              gf->meshAttributes.recombine = 1;
              gf->meshAttributes.recombineAngle = (yyvsp[(4) - (5)].i);
            }
            else
              yymsg(1, "Unknown surface %d", (int)d);
          }
        }
        List_Delete((yyvsp[(3) - (5)].l));
      }
    ;}
    break;

  case 356:
#line 4570 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
	List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Volumes);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Volume *v;
            List_Read(tmp, i, &v);
            v->Recombine3D = 1;
          }
        }
        else{
          for(GModel::riter it = GModel::current()->firstRegion();
              it != GModel::current()->lastRegion(); it++){
            (*it)->meshAttributes.recombine3D = 1;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          Volume *v = FindVolume((int)d);
          if(v){
            v->Recombine3D = 1;
          }
          else{
            GRegion *gr = GModel::current()->getRegionByTag((int)d);
            if(gr){
              gr->meshAttributes.recombine3D = 1;
            }
            else
              yymsg(1, "Unknown volume %d", (int)d);
          }
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 357:
#line 4609 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (6)].l), i, &d);
        int j = (int)d;
        Surface *s = FindSurface(j);
        if(s){
          s->TransfiniteSmoothing = (int)(yyvsp[(5) - (6)].d);
        }
        else{
          GFace *gf = GModel::current()->getFaceByTag(j);
          if(gf)
            gf->meshAttributes.transfiniteSmoothing = (int)(yyvsp[(5) - (6)].d);
          else
            yymsg(1, "Unknown surface %d", (int)(yyvsp[(5) - (6)].d));
        }
      }
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 358:
#line 4630 "Gmsh.y"
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

  case 359:
#line 4662 "Gmsh.y"
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

  case 360:
#line 4689 "Gmsh.y"
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

  case 361:
#line 4715 "Gmsh.y"
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

  case 362:
#line 4741 "Gmsh.y"
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

  case 363:
#line 4767 "Gmsh.y"
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

  case 364:
#line 4793 "Gmsh.y"
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

  case 365:
#line 4814 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s){
	setSurfaceEmbeddedPoints(s, (yyvsp[(3) - (10)].l));
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[(8) - (10)].d));
        if(gf){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (10)].l), i, &d);
            int iPoint = (int)d;
            GVertex *gv = GModel::current()->getVertexByTag(iPoint);
            if(!gv){ // sync model in case the embedded point is a .geo point
              GModel::current()->importGEOInternals();
              gv = GModel::current()->getVertexByTag(iPoint);
            }
            if(gv)
              gf->addEmbeddedVertex(gv);
            else
              yymsg(0, "Unknown point %d", iPoint);
          }
        }
        else
          yymsg(0, "Unknown surface %d", (int)(yyvsp[(8) - (10)].d));
      }
    ;}
    break;

  case 366:
#line 4842 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s){
	setSurfaceEmbeddedCurves(s, (yyvsp[(3) - (10)].l));
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[(8) - (10)].d));
        if(gf){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (10)].l), i, &d);
            int iCurve = (int)d;
            GEdge *ge = GModel::current()->getEdgeByTag(iCurve);
            if(!ge){ // sync model in case the embedded line is a .geo line
              GModel::current()->importGEOInternals();
              ge = GModel::current()->getEdgeByTag(iCurve);
            }
            if(ge)
              gf->addEmbeddedEdge(ge);
            else
              yymsg(0, "Unknown line %d", iCurve);
          }
        }
        else
          yymsg(0, "Unknown surface %d", (int)(yyvsp[(8) - (10)].d));
      }
    ;}
    break;

  case 367:
#line 4870 "Gmsh.y"
    {
      Volume *v = FindVolume((int)(yyvsp[(8) - (10)].d));
      if(v){
	setVolumeEmbeddedPoints(v, (yyvsp[(3) - (10)].l));
      }
      else{
        GRegion *gr = GModel::current()->getRegionByTag((int)(yyvsp[(8) - (10)].d));
        if(gr){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (10)].l), i, &d);
            int iPoint = (int)d;
            GVertex *gv = GModel::current()->getVertexByTag(iPoint);
            if(!gv){ // sync model in case the embedded face is a .geo face
              GModel::current()->importGEOInternals();
              gv = GModel::current()->getVertexByTag(iPoint);
            }
            if(gv)
              gr->addEmbeddedVertex(gv);
            else
              yymsg(0, "Unknown Point %d", iPoint);
          }
        }
        else
          yymsg(0, "Unknown volume %d", (int)(yyvsp[(8) - (10)].d));
      }
    ;}
    break;

  case 368:
#line 4898 "Gmsh.y"
    {
      Volume *v = FindVolume((int)(yyvsp[(8) - (10)].d));
      if(v){
	setVolumeEmbeddedCurves(v, (yyvsp[(3) - (10)].l));
      }
      else{
        GRegion *gr = GModel::current()->getRegionByTag((int)(yyvsp[(8) - (10)].d));
        if(gr){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (10)].l), i, &d);
            int iLine = (int)d;
            GEdge *ge = GModel::current()->getEdgeByTag(iLine);
            if(!ge){ // sync model in case the embedded face is a .geo face
              GModel::current()->importGEOInternals();
              ge = GModel::current()->getEdgeByTag(iLine);
            }
            if(ge)
              gr->addEmbeddedEdge(ge);
            else
              yymsg(0, "Unknown Curve %d", iLine);
          }
        }
        else
          yymsg(0, "Unknown volume %d", (int)(yyvsp[(8) - (10)].d));
      }
    ;}
    break;

  case 369:
#line 4926 "Gmsh.y"
    {
      Volume *v = FindVolume((int)(yyvsp[(8) - (10)].d));
      if(v){
	setVolumeEmbeddedSurfaces(v, (yyvsp[(3) - (10)].l));
      }
      else{
        GRegion *gr = GModel::current()->getRegionByTag((int)(yyvsp[(8) - (10)].d));
        if(gr){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (10)].l), i, &d);
            int iSurface = (int)d;
            GFace *gf = GModel::current()->getFaceByTag(iSurface);
            if(!gf){ // sync model in case the embedded face is a .geo face
              GModel::current()->importGEOInternals();
              gf = GModel::current()->getFaceByTag(iSurface);
            }
            if(gf)
              gr->addEmbeddedFace(gf);
            else
              yymsg(0, "Unknown surface %d", iSurface);
          }
        }
        else
          yymsg(0, "Unknown volume %d", (int)(yyvsp[(8) - (10)].d));
      }
    ;}
    break;

  case 370:
#line 4954 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
	List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Surface *s;
            List_Read(tmp, i, &s);
            s->ReverseMesh = 1;
          }
        }
        else{
          for(GModel::fiter it = GModel::current()->firstFace();
              it != GModel::current()->lastFace(); it++){
            (*it)->meshAttributes.reverseMesh = 1;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          Surface *s = FindSurface((int)d);
          if(s){
            s->ReverseMesh = 1;
          }
          else{
            GFace *gf = GModel::current()->getFaceByTag((int)d);
            if(gf){
              gf->meshAttributes.reverseMesh = 1;
            }
            else
              yymsg(1, "Unknown surface %d", (int)d);
          }
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 371:
#line 4993 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
	List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Curves);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Curve *c;
            List_Read(tmp, i, &c);
            c->ReverseMesh = 1;
          }
        }
        else{
          for(GModel::eiter it = GModel::current()->firstEdge();
              it != GModel::current()->lastEdge(); it++){
            (*it)->meshAttributes.reverseMesh = 1;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          Curve *c = FindCurve((int)d);
          if(c){
            c->ReverseMesh = 1;
          }
          else{
            GEdge *ge = GModel::current()->getEdgeByTag((int)d);
            if(ge){
              ge->meshAttributes.reverseMesh = 1;
            }
            else
              yymsg(1, "Unknown line %d", (int)d);
          }
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 372:
#line 5032 "Gmsh.y"
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
          if(gv){
            gv->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown point %d", (int)d);
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 373:
#line 5053 "Gmsh.y"
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
          if(ge){
            ge->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown line %d", (int)d);
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 374:
#line 5074 "Gmsh.y"
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
          if(gf){
            gf->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown surface %d", (int)d);
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 375:
#line 5101 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 376:
#line 5105 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[(2) - (3)].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 377:
#line 5115 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (6)].l)) >= 2){
        double d;
        List_Read((yyvsp[(4) - (6)].l), 0, &d);
        Vertex *target = FindPoint((int)d);
        if(!target)
          yymsg(0, "Could not find Point %d", (int)d);
        else{
          double x = target->Pos.X, y = target->Pos.Y, z = target->Pos.Z;
          for(int i = 1; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
            List_Read((yyvsp[(4) - (6)].l), i, &d);
            Vertex *source = FindPoint((int)d);
            if(!source) yymsg(0, "Could not find Point %d", (int)d);
            if(target && source){
              source->Typ = target->Typ;
              source->Pos.X = x;
              source->Pos.Y = y;
              source->Pos.Z = z;
              source->boundaryLayerIndex = target->boundaryLayerIndex;
            }
          }
          ExtrudeParams::normalsCoherence.push_back(SPoint3(x, y, z));
        }
      }
      else
        yymsg(0, "Need at least two points to merge");
      ReplaceAllDuplicates();
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 378:
#line 5149 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 379:
#line 5150 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 380:
#line 5151 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 381:
#line 5156 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 382:
#line 5162 "Gmsh.y"
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

  case 383:
#line 5174 "Gmsh.y"
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

  case 384:
#line 5192 "Gmsh.y"
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

  case 385:
#line 5219 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 386:
#line 5220 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 387:
#line 5221 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 388:
#line 5222 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 389:
#line 5223 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 390:
#line 5224 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 391:
#line 5225 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 392:
#line 5226 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 393:
#line 5228 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 394:
#line 5234 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 395:
#line 5235 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 396:
#line 5236 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 397:
#line 5237 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 398:
#line 5238 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 399:
#line 5239 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 400:
#line 5240 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 401:
#line 5241 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 402:
#line 5242 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 403:
#line 5243 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 404:
#line 5244 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 405:
#line 5245 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 406:
#line 5246 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 407:
#line 5247 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 408:
#line 5248 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 409:
#line 5249 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 410:
#line 5250 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 411:
#line 5251 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 412:
#line 5252 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 413:
#line 5253 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 414:
#line 5254 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 415:
#line 5255 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 416:
#line 5256 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 417:
#line 5257 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 418:
#line 5258 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 419:
#line 5259 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 420:
#line 5260 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 421:
#line 5261 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 422:
#line 5262 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 423:
#line 5263 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 424:
#line 5264 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 425:
#line 5265 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 426:
#line 5266 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 427:
#line 5275 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 428:
#line 5276 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 429:
#line 5277 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 430:
#line 5278 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 431:
#line 5279 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 432:
#line 5280 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 433:
#line 5281 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 434:
#line 5282 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 435:
#line 5283 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 436:
#line 5284 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 437:
#line 5285 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 438:
#line 5290 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 439:
#line 5292 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 440:
#line 5298 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 441:
#line 5303 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 442:
#line 5308 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (1)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (1)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (1)].c)]);
        if(s.value.empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (1)].c));
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[0];
      }
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 443:
#line 5325 "Gmsh.y"
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

  case 444:
#line 5343 "Gmsh.y"
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

  case 445:
#line 5361 "Gmsh.y"
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

  case 446:
#line 5379 "Gmsh.y"
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

  case 447:
#line 5397 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 448:
#line 5402 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 449:
#line 5408 "Gmsh.y"
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

  case 450:
#line 5423 "Gmsh.y"
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

  case 451:
#line 5442 "Gmsh.y"
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

  case 452:
#line 5462 "Gmsh.y"
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

  case 453:
#line 5482 "Gmsh.y"
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

  case 454:
#line 5502 "Gmsh.y"
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

  case 455:
#line 5525 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 456:
#line 5530 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 457:
#line 5535 "Gmsh.y"
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

  case 458:
#line 5545 "Gmsh.y"
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

  case 459:
#line 5555 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 460:
#line 5560 "Gmsh.y"
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

  case 461:
#line 5571 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 462:
#line 5580 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 463:
#line 5585 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 464:
#line 5590 "Gmsh.y"
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

  case 465:
#line 5617 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 466:
#line 5621 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 467:
#line 5625 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 468:
#line 5629 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 469:
#line 5633 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 470:
#line 5640 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 471:
#line 5644 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 472:
#line 5648 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 473:
#line 5652 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 474:
#line 5659 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 475:
#line 5664 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 476:
#line 5671 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 477:
#line 5676 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 478:
#line 5680 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 479:
#line 5685 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 480:
#line 5689 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 481:
#line 5697 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 482:
#line 5708 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 483:
#line 5712 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 484:
#line 5724 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 485:
#line 5732 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 486:
#line 5740 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 487:
#line 5747 "Gmsh.y"
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

  case 488:
#line 5757 "Gmsh.y"
    {
      // Returns the coordinates of a point and fills a list with it.
      // This allows to ensure e.g. that relative point positions are
      // always conserved
      Vertex *v = FindPoint((int)(yyvsp[(3) - (4)].d));
      (yyval.l) = List_Create(3, 1, sizeof(double));
      if(!v) {
        GVertex *gv = GModel::current()->getVertexByTag((int)(yyvsp[(3) - (4)].d));
        if(gv){
          double x = gv->x(), y = gv->y(), z = gv->z();
          List_Add((yyval.l), &x);
          List_Add((yyval.l), &y);
          List_Add((yyval.l), &z);
        }
        else{
          yymsg(0, "Unknown point '%d'", (int)(yyvsp[(3) - (4)].d));
          double d = 0.0;
          List_Add((yyval.l), &d);
          List_Add((yyval.l), &d);
          List_Add((yyval.l), &d);
        }
      }
      else{
	List_Add((yyval.l), &v->Pos.X);
	List_Add((yyval.l), &v->Pos.Y);
	List_Add((yyval.l), &v->Pos.Z);
      }
    ;}
    break;

  case 489:
#line 5786 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 490:
#line 5790 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 491:
#line 5794 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 492:
#line 5798 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 493:
#line 5802 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 494:
#line 5806 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 495:
#line 5810 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 496:
#line 5814 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 497:
#line 5818 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        double num;
        List_Read((yyvsp[(4) - (5)].l), i, &num);
        PhysicalGroup *p = FindPhysicalGroup((int)num, MSH_PHYSICAL_POINT);
        if(p){
          for(int j = 0; j < List_Nbr(p->Entities); j++){
            int nume;
            List_Read(p->Entities, j, &nume);
            double d = nume;
            List_Add((yyval.l), &d);
          }
        }
        else{
          std::map<int, std::vector<GEntity*> > groups;
          GModel::current()->getPhysicalGroups(0, groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups.find((int)num);
          if(it != groups.end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add((yyval.l), &d);
            }
          }
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 498:
#line 5847 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        double num;
        List_Read((yyvsp[(4) - (5)].l), i, &num);
        PhysicalGroup *p = FindPhysicalGroup((int)num, MSH_PHYSICAL_LINE);
        if(p){
          for(int j = 0; j < List_Nbr(p->Entities); j++){
            int nume;
            List_Read(p->Entities, j, &nume);
            double d = nume;
            List_Add((yyval.l), &d);
          }
        }
        else{
          std::map<int, std::vector<GEntity*> > groups;
          GModel::current()->getPhysicalGroups(1, groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups.find((int)num);
          if(it != groups.end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add((yyval.l), &d);
            }
          }
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 499:
#line 5876 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        double num;
        List_Read((yyvsp[(4) - (5)].l), i, &num);
        PhysicalGroup *p = FindPhysicalGroup((int)num, MSH_PHYSICAL_SURFACE);
        if(p){
          for(int j = 0; j < List_Nbr(p->Entities); j++){
            int nume;
            List_Read(p->Entities, j, &nume);
            double d = nume;
            List_Add((yyval.l), &d);
          }
        }
        else{
          std::map<int, std::vector<GEntity*> > groups;
          GModel::current()->getPhysicalGroups(2, groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups.find((int)num);
          if(it != groups.end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add((yyval.l), &d);
            }
          }
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 500:
#line 5905 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        double num;
        List_Read((yyvsp[(4) - (5)].l), i, &num);
        PhysicalGroup *p = FindPhysicalGroup((int)num, MSH_PHYSICAL_VOLUME);
        if(p){
          for(int j = 0; j < List_Nbr(p->Entities); j++){
            int nume;
            List_Read(p->Entities, j, &nume);
            double d = nume;
            List_Add((yyval.l), &d);
          }
        }
        else{
          std::map<int, std::vector<GEntity*> > groups;
          GModel::current()->getPhysicalGroups(3, groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups.find((int)num);
          if(it != groups.end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add((yyval.l), &d);
            }
          }
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 501:
#line 5935 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 0);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 502:
#line 5948 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 1);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 503:
#line 5961 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 2);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 504:
#line 5974 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 3);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 505:
#line 5986 "Gmsh.y"
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
#line 5996 "Gmsh.y"
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
#line 6006 "Gmsh.y"
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

  case 508:
#line 6016 "Gmsh.y"
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

  case 509:
#line 6028 "Gmsh.y"
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

  case 510:
#line 6041 "Gmsh.y"
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

  case 511:
#line 6053 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 512:
#line 6057 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 513:
#line 6061 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 514:
#line 6065 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 515:
#line 6069 "Gmsh.y"
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

  case 516:
#line 6087 "Gmsh.y"
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

  case 517:
#line 6105 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 518:
#line 6113 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 519:
#line 6121 "Gmsh.y"
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

  case 520:
#line 6150 "Gmsh.y"
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

  case 521:
#line 6163 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 522:
#line 6168 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 523:
#line 6172 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 524:
#line 6176 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 525:
#line 6188 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 526:
#line 6192 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 527:
#line 6204 "Gmsh.y"
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

  case 528:
#line 6221 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 529:
#line 6231 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 530:
#line 6235 "Gmsh.y"
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

  case 531:
#line 6250 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 532:
#line 6255 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 533:
#line 6262 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 534:
#line 6266 "Gmsh.y"
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

  case 535:
#line 6279 "Gmsh.y"
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

  case 536:
#line 6293 "Gmsh.y"
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

  case 537:
#line 6307 "Gmsh.y"
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

  case 538:
#line 6321 "Gmsh.y"
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

  case 539:
#line 6335 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 540:
#line 6343 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 541:
#line 6354 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 542:
#line 6358 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 543:
#line 6362 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 544:
#line 6370 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 545:
#line 6376 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 546:
#line 6382 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 547:
#line 6390 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 548:
#line 6398 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 549:
#line 6405 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 550:
#line 6413 "Gmsh.y"
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

  case 551:
#line 6428 "Gmsh.y"
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

  case 552:
#line 6442 "Gmsh.y"
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

  case 553:
#line 6456 "Gmsh.y"
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

  case 554:
#line 6468 "Gmsh.y"
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

  case 555:
#line 6484 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 556:
#line 6493 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 557:
#line 6502 "Gmsh.y"
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

  case 558:
#line 6512 "Gmsh.y"
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

  case 559:
#line 6523 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 560:
#line 6531 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 561:
#line 6539 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 562:
#line 6543 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].l), tmpstring);
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

  case 563:
#line 6562 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 564:
#line 6569 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 565:
#line 6575 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 566:
#line 6582 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 567:
#line 6589 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 568:
#line 6591 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 569:
#line 6602 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 570:
#line 6607 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 571:
#line 6613 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 572:
#line 6622 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 573:
#line 6635 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 574:
#line 6638 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 575:
#line 6642 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13593 "Gmsh.tab.cpp"
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


#line 6645 "Gmsh.y"


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

int PrintListOfDouble(char *format, List_T *list, char *buffer)
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
  else{
    Msg::Warning("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
  }
}

void addPeriodicFace(int iTarget, int iSource,
                     const std::vector<double>& affineTransform)
{
  Surface *target = FindSurface(abs(iTarget));

  if (target) {
    GEO_Internals::MasterFace& mf =
      GModel::current()->getGEOInternals()->periodicFaces[iTarget];
    mf.tag = iSource;
    mf.edgeCounterparts.clear();
    mf.affineTransform = affineTransform;
  }
  else{
    GFace *target = GModel::current()->getFaceByTag(abs(iTarget));
    GFace *source = GModel::current()->getFaceByTag(abs(iSource));
    if (!target || !source) {
      Msg::Error("Could not find edge slave %d or master %d for periodic copy",
                 iTarget, iSource);
    }
    else target->setMeshMaster(source, affineTransform);
  }
}

void addPeriodicFace(int iTarget, int iSource,
                     const std::map<int,int>& edgeCounterparts)
{
  Surface *target = FindSurface(abs(iTarget));

  Msg::Info("Encoding periodic connection between %d and %d", iTarget, iSource);
  std::map<int,int>::const_iterator sIter = edgeCounterparts.begin();
  for (; sIter != edgeCounterparts.end(); ++sIter) {
    Msg::Info("%d - %d", sIter->first, sIter->second);
  }

  if (target) {
    GEO_Internals::MasterFace& mf =
      GModel::current()->getGEOInternals()->periodicFaces[iTarget];
    mf.tag = iSource;
    mf.edgeCounterparts = edgeCounterparts;
    mf.affineTransform.clear();
  }
  else{
    GFace *target = GModel::current()->getFaceByTag(abs(iTarget));
    GFace *source = GModel::current()->getFaceByTag(abs(iSource));
    if (!target || !source) {
      Msg::Error("Could not find surface slave %d or master %d for periodic copy",
                 iTarget,iSource);
		}
		else target->setMeshMaster(source, edgeCounterparts);
  }
}

void addPeriodicEdge(int iTarget,int iSource,
                     const std::vector<double>& affineTransform)
{
  Curve *target = FindCurve(abs(iTarget));
  if (target) {
    GEO_Internals::MasterEdge& me =
      GModel::current()->getGEOInternals()->periodicEdges[iTarget];
    me.tag = iSource;
    me.affineTransform = affineTransform;
  }
  else{
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

