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
     tPlane = 355,
     tRuled = 356,
     tTransfinite = 357,
     tComplex = 358,
     tPhysical = 359,
     tCompound = 360,
     tPeriodic = 361,
     tUsing = 362,
     tPlugin = 363,
     tDegenerated = 364,
     tRecursive = 365,
     tRotate = 366,
     tTranslate = 367,
     tSymmetry = 368,
     tDilate = 369,
     tExtrude = 370,
     tLevelset = 371,
     tAffine = 372,
     tRecombine = 373,
     tSmoother = 374,
     tSplit = 375,
     tDelete = 376,
     tCoherence = 377,
     tIntersect = 378,
     tMeshAlgorithm = 379,
     tReverse = 380,
     tLayers = 381,
     tScaleLast = 382,
     tHole = 383,
     tAlias = 384,
     tAliasWithOptions = 385,
     tCopyOptions = 386,
     tQuadTriAddVerts = 387,
     tQuadTriNoNewVerts = 388,
     tQuadTriSngl = 389,
     tQuadTriDbl = 390,
     tRecombLaterals = 391,
     tTransfQuadTri = 392,
     tText2D = 393,
     tText3D = 394,
     tInterpolationScheme = 395,
     tTime = 396,
     tCombine = 397,
     tBSpline = 398,
     tBezier = 399,
     tNurbs = 400,
     tNurbsOrder = 401,
     tNurbsKnots = 402,
     tColor = 403,
     tColorTable = 404,
     tFor = 405,
     tIn = 406,
     tEndFor = 407,
     tIf = 408,
     tElseIf = 409,
     tElse = 410,
     tEndIf = 411,
     tExit = 412,
     tAbort = 413,
     tField = 414,
     tReturn = 415,
     tCall = 416,
     tSlide = 417,
     tMacro = 418,
     tShow = 419,
     tHide = 420,
     tGetValue = 421,
     tGetStringValue = 422,
     tGetEnv = 423,
     tGetString = 424,
     tGetNumber = 425,
     tHomology = 426,
     tCohomology = 427,
     tBetti = 428,
     tExists = 429,
     tFileExists = 430,
     tGMSH_MAJOR_VERSION = 431,
     tGMSH_MINOR_VERSION = 432,
     tGMSH_PATCH_VERSION = 433,
     tGmshExecutableName = 434,
     tSetPartition = 435,
     tNameToString = 436,
     tStringToName = 437,
     tAFFECTDIVIDE = 438,
     tAFFECTTIMES = 439,
     tAFFECTMINUS = 440,
     tAFFECTPLUS = 441,
     tOR = 442,
     tAND = 443,
     tNOTEQUAL = 444,
     tEQUAL = 445,
     tGREATEROREQUAL = 446,
     tLESSOREQUAL = 447,
     UNARYPREC = 448,
     tMINUSMINUS = 449,
     tPLUSPLUS = 450
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
#define tPlane 355
#define tRuled 356
#define tTransfinite 357
#define tComplex 358
#define tPhysical 359
#define tCompound 360
#define tPeriodic 361
#define tUsing 362
#define tPlugin 363
#define tDegenerated 364
#define tRecursive 365
#define tRotate 366
#define tTranslate 367
#define tSymmetry 368
#define tDilate 369
#define tExtrude 370
#define tLevelset 371
#define tAffine 372
#define tRecombine 373
#define tSmoother 374
#define tSplit 375
#define tDelete 376
#define tCoherence 377
#define tIntersect 378
#define tMeshAlgorithm 379
#define tReverse 380
#define tLayers 381
#define tScaleLast 382
#define tHole 383
#define tAlias 384
#define tAliasWithOptions 385
#define tCopyOptions 386
#define tQuadTriAddVerts 387
#define tQuadTriNoNewVerts 388
#define tQuadTriSngl 389
#define tQuadTriDbl 390
#define tRecombLaterals 391
#define tTransfQuadTri 392
#define tText2D 393
#define tText3D 394
#define tInterpolationScheme 395
#define tTime 396
#define tCombine 397
#define tBSpline 398
#define tBezier 399
#define tNurbs 400
#define tNurbsOrder 401
#define tNurbsKnots 402
#define tColor 403
#define tColorTable 404
#define tFor 405
#define tIn 406
#define tEndFor 407
#define tIf 408
#define tElseIf 409
#define tElse 410
#define tEndIf 411
#define tExit 412
#define tAbort 413
#define tField 414
#define tReturn 415
#define tCall 416
#define tSlide 417
#define tMacro 418
#define tShow 419
#define tHide 420
#define tGetValue 421
#define tGetStringValue 422
#define tGetEnv 423
#define tGetString 424
#define tGetNumber 425
#define tHomology 426
#define tCohomology 427
#define tBetti 428
#define tExists 429
#define tFileExists 430
#define tGMSH_MAJOR_VERSION 431
#define tGMSH_MINOR_VERSION 432
#define tGMSH_PATCH_VERSION 433
#define tGmshExecutableName 434
#define tSetPartition 435
#define tNameToString 436
#define tStringToName 437
#define tAFFECTDIVIDE 438
#define tAFFECTTIMES 439
#define tAFFECTMINUS 440
#define tAFFECTPLUS 441
#define tOR 442
#define tAND 443
#define tNOTEQUAL 444
#define tEQUAL 445
#define tGREATEROREQUAL 446
#define tLESSOREQUAL 447
#define UNARYPREC 448
#define tMINUSMINUS 449
#define tPLUSPLUS 450




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
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
#line 115 "Gmsh.y"
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
#line 618 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 631 "Gmsh.tab.cpp"

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
#define YYLAST   12943

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  216
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  564
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2043

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   450

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   201,     2,   211,     2,   200,     2,     2,
     206,   207,   198,   196,   212,   197,   210,   199,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     192,     2,   193,   187,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   208,     2,   209,   205,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   213,     2,   214,   215,     2,     2,     2,
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
     185,   186,   188,   189,   190,   191,   194,   195,   202,   203,
     204
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    48,    51,    57,    63,    71,    79,
      87,    97,   104,   111,   118,   127,   128,   131,   134,   137,
     140,   143,   145,   149,   151,   155,   156,   157,   168,   170,
     174,   175,   189,   191,   195,   196,   212,   221,   236,   237,
     244,   246,   248,   250,   252,   254,   256,   258,   260,   262,
     264,   266,   272,   278,   286,   294,   299,   303,   310,   317,
     325,   333,   340,   347,   357,   367,   374,   381,   389,   397,
     404,   411,   416,   425,   434,   444,   454,   464,   474,   483,
     492,   502,   512,   522,   532,   539,   549,   556,   566,   572,
     581,   590,   602,   609,   619,   625,   633,   643,   653,   665,
     673,   683,   693,   694,   696,   697,   701,   707,   708,   718,
     719,   731,   732,   744,   750,   751,   761,   762,   766,   770,
     776,   782,   783,   786,   790,   796,   800,   801,   804,   808,
     812,   816,   822,   824,   826,   830,   832,   834,   838,   840,
     842,   846,   848,   850,   854,   855,   861,   862,   865,   873,
     882,   889,   897,   902,   910,   919,   928,   936,   944,   956,
     965,   970,   979,   988,   997,  1007,  1011,  1016,  1027,  1035,
    1043,  1052,  1057,  1066,  1079,  1088,  1097,  1105,  1110,  1119,
    1128,  1134,  1146,  1152,  1162,  1172,  1177,  1187,  1197,  1199,
    1201,  1202,  1205,  1212,  1219,  1226,  1233,  1242,  1253,  1268,
    1285,  1298,  1307,  1316,  1323,  1338,  1343,  1350,  1357,  1361,
    1366,  1372,  1379,  1385,  1389,  1393,  1398,  1404,  1409,  1415,
    1419,  1425,  1433,  1441,  1445,  1453,  1457,  1460,  1463,  1466,
    1469,  1472,  1488,  1491,  1494,  1497,  1500,  1503,  1520,  1532,
    1539,  1548,  1557,  1568,  1570,  1573,  1576,  1578,  1582,  1586,
    1591,  1596,  1598,  1600,  1606,  1618,  1632,  1633,  1641,  1642,
    1656,  1657,  1673,  1674,  1681,  1690,  1699,  1708,  1721,  1734,
    1747,  1762,  1777,  1792,  1793,  1806,  1807,  1820,  1821,  1834,
    1835,  1852,  1853,  1870,  1871,  1888,  1889,  1908,  1909,  1928,
    1929,  1948,  1950,  1953,  1959,  1967,  1977,  1980,  1983,  1987,
    1990,  1994,  1997,  2001,  2004,  2008,  2011,  2015,  2025,  2032,
    2033,  2037,  2038,  2040,  2041,  2044,  2045,  2048,  2049,  2052,
    2060,  2067,  2076,  2082,  2086,  2095,  2101,  2106,  2113,  2125,
    2137,  2156,  2175,  2188,  2201,  2214,  2225,  2236,  2247,  2258,
    2269,  2274,  2279,  2284,  2289,  2294,  2297,  2301,  2308,  2310,
    2312,  2314,  2317,  2323,  2331,  2342,  2344,  2348,  2351,  2354,
    2357,  2361,  2365,  2369,  2373,  2377,  2381,  2385,  2389,  2393,
    2397,  2401,  2405,  2409,  2413,  2419,  2424,  2429,  2434,  2439,
    2444,  2449,  2454,  2459,  2464,  2469,  2476,  2481,  2486,  2491,
    2496,  2501,  2506,  2511,  2518,  2525,  2532,  2537,  2539,  2541,
    2543,  2545,  2547,  2549,  2551,  2553,  2555,  2557,  2559,  2560,
    2567,  2572,  2579,  2581,  2586,  2591,  2596,  2601,  2606,  2611,
    2616,  2619,  2625,  2631,  2637,  2643,  2647,  2654,  2659,  2667,
    2674,  2681,  2688,  2693,  2700,  2705,  2707,  2710,  2713,  2717,
    2721,  2733,  2743,  2751,  2759,  2761,  2765,  2767,  2769,  2772,
    2776,  2781,  2787,  2789,  2791,  2794,  2798,  2802,  2808,  2813,
    2816,  2819,  2822,  2825,  2829,  2833,  2837,  2841,  2847,  2853,
    2859,  2865,  2882,  2899,  2916,  2933,  2935,  2937,  2941,  2945,
    2950,  2955,  2960,  2967,  2974,  2981,  2988,  2997,  3006,  3011,
    3026,  3028,  3030,  3034,  3038,  3048,  3056,  3058,  3064,  3068,
    3075,  3077,  3081,  3083,  3085,  3090,  3095,  3100,  3105,  3109,
    3116,  3118,  3123,  3125,  3127,  3129,  3134,  3141,  3146,  3153,
    3158,  3163,  3168,  3177,  3182,  3187,  3192,  3197,  3206,  3215,
    3222,  3227,  3234,  3239,  3241,  3246,  3251,  3252,  3259,  3261,
    3265,  3271,  3277,  3279,  3281
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     217,     0,    -1,   218,    -1,     1,     6,    -1,    -1,   218,
     219,    -1,   222,    -1,   221,    -1,   242,    -1,   261,    -1,
     262,    -1,   266,    -1,   267,    -1,   268,    -1,   269,    -1,
     273,    -1,   294,    -1,   295,    -1,   272,    -1,   271,    -1,
     270,    -1,   265,    -1,   297,    -1,   193,    -1,   193,   193,
      -1,    42,   206,   311,   207,     6,    -1,    43,   206,   311,
     207,     6,    -1,    42,   206,   311,   207,   220,   311,     6,
      -1,    42,   206,   311,   212,   307,   207,     6,    -1,    43,
     206,   311,   212,   307,   207,     6,    -1,    42,   206,   311,
     212,   307,   207,   220,   311,     6,    -1,     4,   311,   213,
     223,   214,     6,    -1,   129,     4,   208,   298,   209,     6,
      -1,   130,     4,   208,   298,   209,     6,    -1,   131,     4,
     208,   298,   212,   298,   209,     6,    -1,    -1,   223,   226,
      -1,   223,   230,    -1,   223,   233,    -1,   223,   235,    -1,
     223,   236,    -1,   298,    -1,   224,   212,   298,    -1,   298,
      -1,   225,   212,   298,    -1,    -1,    -1,     4,   227,   206,
     224,   207,   228,   213,   225,   214,     6,    -1,   311,    -1,
     229,   212,   311,    -1,    -1,   138,   206,   298,   212,   298,
     212,   298,   207,   231,   213,   229,   214,     6,    -1,   311,
      -1,   232,   212,   311,    -1,    -1,   139,   206,   298,   212,
     298,   212,   298,   212,   298,   207,   234,   213,   232,   214,
       6,    -1,   140,   213,   303,   214,   213,   303,   214,     6,
      -1,   140,   213,   303,   214,   213,   303,   214,   213,   303,
     214,   213,   303,   214,     6,    -1,    -1,   141,   237,   213,
     225,   214,     6,    -1,     7,    -1,   186,    -1,   185,    -1,
     184,    -1,   183,    -1,   204,    -1,   203,    -1,   206,    -1,
     208,    -1,   207,    -1,   209,    -1,    78,   208,   244,   209,
       6,    -1,    79,   208,   249,   209,     6,    -1,    82,   240,
     312,   212,   298,   241,     6,    -1,    83,   240,   316,   212,
     312,   241,     6,    -1,   316,   238,   304,     6,    -1,   316,
     239,     6,    -1,     4,   208,   209,   238,   304,     6,    -1,
     315,   208,   209,   238,   304,     6,    -1,     4,   208,   298,
     209,   238,   298,     6,    -1,   315,   208,   298,   209,   238,
     298,     6,    -1,     4,   208,   298,   209,   239,     6,    -1,
     315,   208,   298,   209,   239,     6,    -1,     4,   240,   213,
     307,   214,   241,   238,   304,     6,    -1,   315,   240,   213,
     307,   214,   241,   238,   304,     6,    -1,     4,   206,   207,
     238,   304,     6,    -1,   315,   206,   207,   238,   304,     6,
      -1,     4,   206,   298,   207,   238,   298,     6,    -1,   315,
     206,   298,   207,   238,   298,     6,    -1,     4,   206,   298,
     207,   239,     6,    -1,   315,   206,   298,   207,   239,     6,
      -1,   316,     7,   312,     6,    -1,     4,   208,   209,     7,
      44,   240,   241,     6,    -1,   315,   208,   209,     7,    44,
     240,   241,     6,    -1,     4,   208,   209,     7,    44,   240,
     314,   241,     6,    -1,   315,   208,   209,     7,    44,   240,
     314,   241,     6,    -1,     4,   208,   209,   186,    44,   240,
     314,   241,     6,    -1,   315,   208,   209,   186,    44,   240,
     314,   241,     6,    -1,     4,   206,   207,     7,    44,   240,
     241,     6,    -1,   315,   206,   207,     7,    44,   240,   241,
       6,    -1,     4,   206,   207,     7,    44,   240,   314,   241,
       6,    -1,   315,   206,   207,     7,    44,   240,   314,   241,
       6,    -1,     4,   206,   207,   186,    44,   240,   314,   241,
       6,    -1,   315,   206,   207,   186,    44,   240,   314,   241,
       6,    -1,     4,   210,     4,     7,   312,     6,    -1,     4,
     208,   298,   209,   210,     4,     7,   312,     6,    -1,     4,
     210,     4,   238,   298,     6,    -1,     4,   208,   298,   209,
     210,     4,   238,   298,     6,    -1,     4,   210,     4,   239,
       6,    -1,     4,   208,   298,   209,   210,     4,   239,     6,
      -1,     4,   210,   148,   210,     4,     7,   308,     6,    -1,
       4,   208,   298,   209,   210,   148,   210,     4,     7,   308,
       6,    -1,     4,   210,   149,     7,   309,     6,    -1,     4,
     208,   298,   209,   210,   149,     7,   309,     6,    -1,     4,
     159,     7,   298,     6,    -1,   159,   208,   298,   209,     7,
       4,     6,    -1,   159,   208,   298,   209,   210,     4,     7,
     298,     6,    -1,   159,   208,   298,   209,   210,     4,     7,
     312,     6,    -1,   159,   208,   298,   209,   210,     4,     7,
     213,   307,   214,     6,    -1,   159,   208,   298,   209,   210,
       4,     6,    -1,   108,   206,     4,   207,   210,     4,     7,
     298,     6,    -1,   108,   206,     4,   207,   210,     4,     7,
     312,     6,    -1,    -1,   212,    -1,    -1,   244,   243,   316,
      -1,   244,   243,   316,     7,   298,    -1,    -1,   244,   243,
     316,     7,   213,   304,   245,   251,   214,    -1,    -1,   244,
     243,   316,   208,   209,     7,   213,   304,   246,   251,   214,
      -1,    -1,   244,   243,   316,   206,   207,     7,   213,   304,
     247,   251,   214,    -1,   244,   243,   316,     7,   312,    -1,
      -1,   244,   243,   316,     7,   213,   312,   248,   253,   214,
      -1,    -1,   249,   243,   311,    -1,   298,     7,   312,    -1,
     250,   212,   298,     7,   312,    -1,   306,     7,   316,   206,
     207,    -1,    -1,   251,   252,    -1,   212,     4,   304,    -1,
     212,     4,   213,   250,   214,    -1,   212,     4,   312,    -1,
      -1,   253,   254,    -1,   212,     4,   298,    -1,   212,     4,
     312,    -1,   212,   163,   312,    -1,   212,     4,   213,   314,
     214,    -1,   298,    -1,   312,    -1,   312,   212,   298,    -1,
     298,    -1,   312,    -1,   312,   212,   298,    -1,   298,    -1,
     312,    -1,   312,   212,   298,    -1,   298,    -1,   312,    -1,
     312,   212,   298,    -1,    -1,   151,    88,   213,   298,   214,
      -1,    -1,   100,   301,    -1,    84,   206,   298,   207,     7,
     301,     6,    -1,   104,    84,   206,   255,   207,   238,   304,
       6,    -1,    93,    94,   304,     7,   298,     6,    -1,    87,
     206,   298,   207,     7,   304,     6,    -1,   109,    87,   304,
       6,    -1,    91,   206,   298,   207,     7,   304,     6,    -1,
      85,   206,   298,   207,     7,   304,   260,     6,    -1,    86,
     206,   298,   207,     7,   304,   260,     6,    -1,   143,   206,
     298,   207,     7,   304,     6,    -1,   144,   206,   298,   207,
       7,   304,     6,    -1,   145,   206,   298,   207,     7,   304,
     147,   304,   146,   298,     6,    -1,    87,     4,   206,   298,
     207,     7,   304,     6,    -1,   105,    87,   304,     6,    -1,
     105,    87,   206,   298,   207,     7,   304,     6,    -1,   104,
      87,   206,   256,   207,   238,   304,     6,    -1,   100,    90,
     206,   298,   207,     7,   304,     6,    -1,   101,    90,   206,
     298,   207,     7,   304,   259,     6,    -1,    12,    13,     6,
      -1,    13,    90,   298,     6,    -1,    95,    90,   206,   298,
     207,     7,     5,     5,     5,     6,    -1,    88,   206,   298,
     207,     7,   304,     6,    -1,    89,   206,   298,   207,     7,
     304,     6,    -1,    90,     4,   206,   298,   207,     7,   304,
       6,    -1,   105,    90,   304,     6,    -1,   105,    90,   206,
     298,   207,     7,   304,     6,    -1,   105,    90,   206,   298,
     207,     7,   304,     4,   213,   303,   214,     6,    -1,   104,
      90,   206,   257,   207,   238,   304,     6,    -1,   103,    92,
     206,   298,   207,     7,   304,     6,    -1,    92,   206,   298,
     207,     7,   304,     6,    -1,   105,    92,   304,     6,    -1,
     105,    92,   206,   298,   207,     7,   304,     6,    -1,   104,
      92,   206,   258,   207,   238,   304,     6,    -1,   112,   301,
     213,   263,   214,    -1,   111,   213,   301,   212,   301,   212,
     298,   214,   213,   263,   214,    -1,   113,   301,   213,   263,
     214,    -1,   114,   213,   301,   212,   298,   214,   213,   263,
     214,    -1,   114,   213,   301,   212,   301,   214,   213,   263,
     214,    -1,     4,   213,   263,   214,    -1,   123,    87,   213,
     307,   214,    90,   213,   298,   214,    -1,   120,    87,   206,
     298,   207,   213,   307,   214,     6,    -1,   264,    -1,   262,
      -1,    -1,   264,   261,    -1,   264,    84,   213,   307,   214,
       6,    -1,   264,    87,   213,   307,   214,     6,    -1,   264,
      90,   213,   307,   214,     6,    -1,   264,    92,   213,   307,
     214,     6,    -1,   116,   100,   206,   298,   207,     7,   304,
       6,    -1,   116,    84,   206,   298,   207,     7,   213,   303,
     214,     6,    -1,   116,   100,   206,   298,   207,     7,   213,
     301,   212,   301,   212,   307,   214,     6,    -1,   116,   100,
     206,   298,   207,     7,   213,   301,   212,   301,   212,   301,
     212,   307,   214,     6,    -1,   116,    88,   206,   298,   207,
       7,   213,   301,   212,   307,   214,     6,    -1,   116,     4,
     206,   298,   207,     7,   304,     6,    -1,   116,     4,   206,
     298,   207,     7,     5,     6,    -1,   116,     4,   213,   298,
     214,     6,    -1,   116,     4,   206,   298,   207,     7,   213,
     301,   212,   301,   212,   307,   214,     6,    -1,   121,   213,
     264,   214,    -1,   121,   159,   208,   298,   209,     6,    -1,
     121,     4,   208,   298,   209,     6,    -1,   121,   316,     6,
      -1,   121,     4,     4,     6,    -1,   148,   308,   213,   264,
     214,    -1,   110,   148,   308,   213,   264,   214,    -1,   180,
     298,   213,   264,   214,    -1,   164,     5,     6,    -1,   165,
       5,     6,    -1,   164,   213,   264,   214,    -1,   110,   164,
     213,   264,   214,    -1,   165,   213,   264,   214,    -1,   110,
     165,   213,   264,   214,    -1,     4,   312,     6,    -1,    71,
     206,   314,   207,     6,    -1,     4,     4,   208,   298,   209,
     311,     6,    -1,     4,     4,     4,   208,   298,   209,     6,
      -1,     4,   298,     6,    -1,   108,   206,     4,   207,   210,
       4,     6,    -1,   142,     4,     6,    -1,   157,     6,    -1,
     158,     6,    -1,    68,     6,    -1,    69,     6,    -1,    62,
       6,    -1,    62,   213,   298,   212,   298,   212,   298,   212,
     298,   212,   298,   212,   298,   214,     6,    -1,    63,     6,
      -1,    64,     6,    -1,    75,     6,    -1,    76,     6,    -1,
      97,     6,    -1,    98,   213,   307,   214,   213,   307,   214,
     213,   303,   214,   213,   298,   212,   298,   214,     6,    -1,
     162,   206,   213,   307,   214,   212,   312,   212,   312,   207,
       6,    -1,   150,   206,   298,     8,   298,   207,    -1,   150,
     206,   298,     8,   298,     8,   298,   207,    -1,   150,     4,
     151,   213,   298,     8,   298,   214,    -1,   150,     4,   151,
     213,   298,     8,   298,     8,   298,   214,    -1,   152,    -1,
     163,     4,    -1,   163,   312,    -1,   160,    -1,   161,   316,
       6,    -1,   161,   312,     6,    -1,   153,   206,   298,   207,
      -1,   154,   206,   298,   207,    -1,   155,    -1,   156,    -1,
     115,   301,   213,   264,   214,    -1,   115,   213,   301,   212,
     301,   212,   298,   214,   213,   264,   214,    -1,   115,   213,
     301,   212,   301,   212,   301,   212,   298,   214,   213,   264,
     214,    -1,    -1,   115,   301,   213,   264,   274,   287,   214,
      -1,    -1,   115,   213,   301,   212,   301,   212,   298,   214,
     213,   264,   275,   287,   214,    -1,    -1,   115,   213,   301,
     212,   301,   212,   301,   212,   298,   214,   213,   264,   276,
     287,   214,    -1,    -1,   115,   213,   264,   277,   287,   214,
      -1,   115,    84,   213,   298,   212,   301,   214,     6,    -1,
     115,    87,   213,   298,   212,   301,   214,     6,    -1,   115,
      90,   213,   298,   212,   301,   214,     6,    -1,   115,    84,
     213,   298,   212,   301,   212,   301,   212,   298,   214,     6,
      -1,   115,    87,   213,   298,   212,   301,   212,   301,   212,
     298,   214,     6,    -1,   115,    90,   213,   298,   212,   301,
     212,   301,   212,   298,   214,     6,    -1,   115,    84,   213,
     298,   212,   301,   212,   301,   212,   301,   212,   298,   214,
       6,    -1,   115,    87,   213,   298,   212,   301,   212,   301,
     212,   301,   212,   298,   214,     6,    -1,   115,    90,   213,
     298,   212,   301,   212,   301,   212,   301,   212,   298,   214,
       6,    -1,    -1,   115,    84,   213,   298,   212,   301,   214,
     278,   213,   287,   214,     6,    -1,    -1,   115,    87,   213,
     298,   212,   301,   214,   279,   213,   287,   214,     6,    -1,
      -1,   115,    90,   213,   298,   212,   301,   214,   280,   213,
     287,   214,     6,    -1,    -1,   115,    84,   213,   298,   212,
     301,   212,   301,   212,   298,   214,   281,   213,   287,   214,
       6,    -1,    -1,   115,    87,   213,   298,   212,   301,   212,
     301,   212,   298,   214,   282,   213,   287,   214,     6,    -1,
      -1,   115,    90,   213,   298,   212,   301,   212,   301,   212,
     298,   214,   283,   213,   287,   214,     6,    -1,    -1,   115,
      84,   213,   298,   212,   301,   212,   301,   212,   301,   212,
     298,   214,   284,   213,   287,   214,     6,    -1,    -1,   115,
      87,   213,   298,   212,   301,   212,   301,   212,   301,   212,
     298,   214,   285,   213,   287,   214,     6,    -1,    -1,   115,
      90,   213,   298,   212,   301,   212,   301,   212,   301,   212,
     298,   214,   286,   213,   287,   214,     6,    -1,   288,    -1,
     287,   288,    -1,   126,   213,   298,   214,     6,    -1,   126,
     213,   304,   212,   304,   214,     6,    -1,   126,   213,   304,
     212,   304,   212,   304,   214,     6,    -1,   127,     6,    -1,
     118,     6,    -1,   118,   298,     6,    -1,   134,     6,    -1,
     134,   136,     6,    -1,   135,     6,    -1,   135,   136,     6,
      -1,   132,     6,    -1,   132,   136,     6,    -1,   133,     6,
      -1,   133,   136,     6,    -1,   128,   206,   298,   207,     7,
     304,   107,   298,     6,    -1,   107,     4,   208,   298,   209,
       6,    -1,    -1,   107,     4,   298,    -1,    -1,     4,    -1,
      -1,     7,   304,    -1,    -1,     7,   298,    -1,    -1,   117,
     304,    -1,   102,    87,   305,     7,   298,   289,     6,    -1,
     102,    90,   305,   291,   290,     6,    -1,    96,    90,   213,
     298,   214,     7,   304,     6,    -1,   102,    92,   305,   291,
       6,    -1,   137,   305,     6,    -1,   124,    90,   213,   307,
     214,     7,   298,     6,    -1,   118,    90,   305,   292,     6,
      -1,   118,    92,   305,     6,    -1,   119,    90,   304,     7,
     298,     6,    -1,   106,    87,   213,   307,   214,     7,   213,
     307,   214,   293,     6,    -1,   106,    90,   213,   307,   214,
       7,   213,   307,   214,   293,     6,    -1,   106,    87,   213,
     307,   214,     7,   213,   307,   214,   111,   213,   301,   212,
     301,   212,   298,   214,     6,    -1,   106,    90,   213,   307,
     214,     7,   213,   307,   214,   111,   213,   301,   212,   301,
     212,   298,   214,     6,    -1,   106,    87,   213,   307,   214,
       7,   213,   307,   214,   112,   301,     6,    -1,   106,    90,
     213,   307,   214,     7,   213,   307,   214,   112,   301,     6,
      -1,   106,    90,   298,   213,   307,   214,     7,   298,   213,
     307,   214,     6,    -1,    84,   213,   307,   214,   151,    90,
     213,   298,   214,     6,    -1,    87,   213,   307,   214,   151,
      90,   213,   298,   214,     6,    -1,    84,   213,   307,   214,
     151,    92,   213,   298,   214,     6,    -1,    87,   213,   307,
     214,   151,    92,   213,   298,   214,     6,    -1,    90,   213,
     307,   214,   151,    92,   213,   298,   214,     6,    -1,   125,
      90,   305,     6,    -1,   125,    87,   305,     6,    -1,    99,
      84,   305,     6,    -1,    99,    87,   305,     6,    -1,    99,
      90,   305,     6,    -1,   122,     6,    -1,   122,     4,     6,
      -1,   122,    84,   213,   307,   214,     6,    -1,   171,    -1,
     172,    -1,   173,    -1,   296,     6,    -1,   296,   213,   304,
     214,     6,    -1,   296,   213,   304,   212,   304,   214,     6,
      -1,   296,   206,   304,   207,   213,   304,   212,   304,   214,
       6,    -1,   299,    -1,   206,   298,   207,    -1,   197,   298,
      -1,   196,   298,    -1,   201,   298,    -1,   298,   197,   298,
      -1,   298,   196,   298,    -1,   298,   198,   298,    -1,   298,
     199,   298,    -1,   298,   200,   298,    -1,   298,   205,   298,
      -1,   298,   192,   298,    -1,   298,   193,   298,    -1,   298,
     195,   298,    -1,   298,   194,   298,    -1,   298,   191,   298,
      -1,   298,   190,   298,    -1,   298,   189,   298,    -1,   298,
     188,   298,    -1,   298,   187,   298,     8,   298,    -1,    15,
     240,   298,   241,    -1,    16,   240,   298,   241,    -1,    17,
     240,   298,   241,    -1,    18,   240,   298,   241,    -1,    19,
     240,   298,   241,    -1,    20,   240,   298,   241,    -1,    21,
     240,   298,   241,    -1,    22,   240,   298,   241,    -1,    23,
     240,   298,   241,    -1,    25,   240,   298,   241,    -1,    26,
     240,   298,   212,   298,   241,    -1,    27,   240,   298,   241,
      -1,    28,   240,   298,   241,    -1,    29,   240,   298,   241,
      -1,    30,   240,   298,   241,    -1,    31,   240,   298,   241,
      -1,    32,   240,   298,   241,    -1,    33,   240,   298,   241,
      -1,    34,   240,   298,   212,   298,   241,    -1,    35,   240,
     298,   212,   298,   241,    -1,    36,   240,   298,   212,   298,
     241,    -1,    24,   240,   298,   241,    -1,     3,    -1,     9,
      -1,    14,    -1,    10,    -1,    11,    -1,   176,    -1,   177,
      -1,   178,    -1,    72,    -1,    73,    -1,    74,    -1,    -1,
      80,   240,   298,   300,   251,   241,    -1,   170,   240,   311,
     241,    -1,   170,   240,   311,   212,   298,   241,    -1,   316,
      -1,     4,   208,   298,   209,    -1,     4,   206,   298,   207,
      -1,   315,   208,   298,   209,    -1,   315,   206,   298,   207,
      -1,   174,   206,   316,   207,    -1,   175,   206,   312,   207,
      -1,   211,   316,   240,   241,    -1,   316,   239,    -1,     4,
     208,   298,   209,   239,    -1,     4,   206,   298,   207,   239,
      -1,   315,   208,   298,   209,   239,    -1,   315,   206,   298,
     207,   239,    -1,     4,   210,     4,    -1,     4,   208,   298,
     209,   210,     4,    -1,     4,   210,     4,   239,    -1,     4,
     208,   298,   209,   210,     4,   239,    -1,   166,   206,   311,
     212,   298,   207,    -1,    54,   206,   304,   212,   304,   207,
      -1,    55,   240,   311,   212,   311,   241,    -1,    53,   240,
     311,   241,    -1,    56,   240,   311,   212,   311,   241,    -1,
      61,   206,   314,   207,    -1,   302,    -1,   197,   301,    -1,
     196,   301,    -1,   301,   197,   301,    -1,   301,   196,   301,
      -1,   213,   298,   212,   298,   212,   298,   212,   298,   212,
     298,   214,    -1,   213,   298,   212,   298,   212,   298,   212,
     298,   214,    -1,   213,   298,   212,   298,   212,   298,   214,
      -1,   206,   298,   212,   298,   212,   298,   207,    -1,   304,
      -1,   303,   212,   304,    -1,   298,    -1,   306,    -1,   213,
     214,    -1,   213,   307,   214,    -1,   197,   213,   307,   214,
      -1,   298,   198,   213,   307,   214,    -1,   304,    -1,     5,
      -1,   197,   306,    -1,   298,   198,   306,    -1,   298,     8,
     298,    -1,   298,     8,   298,     8,   298,    -1,    84,   213,
     298,   214,    -1,    84,     5,    -1,    87,     5,    -1,    90,
       5,    -1,    92,     5,    -1,   104,    84,     5,    -1,   104,
      87,     5,    -1,   104,    90,     5,    -1,   104,    92,     5,
      -1,   104,    84,   213,   307,   214,    -1,   104,    87,   213,
     307,   214,    -1,   104,    90,   213,   307,   214,    -1,   104,
      92,   213,   307,   214,    -1,    84,   151,    62,   213,   298,
     212,   298,   212,   298,   212,   298,   212,   298,   212,   298,
     214,    -1,    87,   151,    62,   213,   298,   212,   298,   212,
     298,   212,   298,   212,   298,   212,   298,   214,    -1,    90,
     151,    62,   213,   298,   212,   298,   212,   298,   212,   298,
     212,   298,   212,   298,   214,    -1,    92,   151,    62,   213,
     298,   212,   298,   212,   298,   212,   298,   212,   298,   212,
     298,   214,    -1,   262,    -1,   273,    -1,     4,   240,   241,
      -1,   315,   240,   241,    -1,    37,   208,   316,   209,    -1,
      37,   208,   306,   209,    -1,    37,   206,   306,   207,    -1,
      37,   208,   213,   307,   214,   209,    -1,    37,   206,   213,
     307,   214,   207,    -1,     4,   240,   213,   307,   214,   241,
      -1,   315,   240,   213,   307,   214,   241,    -1,    38,   240,
     298,   212,   298,   212,   298,   241,    -1,    39,   240,   298,
     212,   298,   212,   298,   241,    -1,    40,   240,   311,   241,
      -1,    41,   240,   298,   212,   298,   212,   298,   212,   298,
     212,   298,   212,   298,   241,    -1,   298,    -1,   306,    -1,
     307,   212,   298,    -1,   307,   212,   306,    -1,   213,   298,
     212,   298,   212,   298,   212,   298,   214,    -1,   213,   298,
     212,   298,   212,   298,   214,    -1,   316,    -1,     4,   210,
     148,   210,     4,    -1,   213,   310,   214,    -1,     4,   208,
     298,   209,   210,   149,    -1,   308,    -1,   310,   212,   308,
      -1,   312,    -1,   316,    -1,     4,   208,   298,   209,    -1,
     315,   208,   298,   209,    -1,     4,   206,   298,   207,    -1,
     315,   206,   298,   207,    -1,     4,   210,     4,    -1,     4,
     208,   298,   209,   210,     4,    -1,     5,    -1,   181,   208,
     316,   209,    -1,    65,    -1,   179,    -1,    70,    -1,   168,
     206,   311,   207,    -1,   167,   206,   311,   212,   311,   207,
      -1,   169,   240,   311,   241,    -1,   169,   240,   311,   212,
     311,   241,    -1,    46,   240,   314,   241,    -1,    47,   206,
     311,   207,    -1,    48,   206,   311,   207,    -1,    49,   206,
     311,   212,   311,   212,   311,   207,    -1,    44,   240,   314,
     241,    -1,    58,   240,   311,   241,    -1,    59,   240,   311,
     241,    -1,    60,   240,   311,   241,    -1,    57,   240,   298,
     212,   311,   212,   311,   241,    -1,    52,   240,   311,   212,
     298,   212,   298,   241,    -1,    52,   240,   311,   212,   298,
     241,    -1,    45,   240,   311,   241,    -1,    45,   240,   311,
     212,   307,   241,    -1,    66,   240,   311,   241,    -1,    67,
      -1,    51,   240,   311,   241,    -1,    50,   240,   311,   241,
      -1,    -1,    81,   240,   312,   313,   253,   241,    -1,   311,
      -1,   314,   212,   311,    -1,     4,   215,   213,   298,   214,
      -1,   315,   215,   213,   298,   214,    -1,     4,    -1,   315,
      -1,   182,   208,   311,   209,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   204,   204,   205,   210,   212,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   236,   240,   247,   252,   257,   271,   284,
     297,   325,   339,   352,   365,   384,   389,   390,   391,   392,
     393,   397,   399,   404,   406,   412,   516,   411,   534,   541,
     552,   551,   569,   576,   587,   586,   603,   620,   643,   642,
     656,   657,   658,   659,   660,   664,   665,   671,   671,   672,
     672,   678,   679,   680,   685,   691,   753,   770,   799,   828,
     833,   838,   843,   848,   855,   865,   894,   923,   928,   933,
     938,   946,   955,   961,   967,   980,   993,  1008,  1025,  1031,
    1037,  1050,  1063,  1078,  1095,  1101,  1110,  1128,  1146,  1155,
    1167,  1172,  1180,  1200,  1223,  1234,  1242,  1264,  1287,  1325,
    1346,  1358,  1372,  1372,  1374,  1376,  1385,  1395,  1394,  1415,
    1414,  1433,  1432,  1450,  1460,  1459,  1473,  1475,  1483,  1489,
    1494,  1520,  1521,  1525,  1536,  1551,  1561,  1562,  1567,  1575,
    1584,  1592,  1610,  1614,  1620,  1628,  1632,  1638,  1646,  1650,
    1656,  1664,  1668,  1674,  1683,  1686,  1699,  1702,  1712,  1735,
    1778,  1801,  1819,  1840,  1858,  1888,  1918,  1936,  1954,  1981,
    2000,  2005,  2023,  2069,  2087,  2126,  2132,  2138,  2145,  2170,
    2195,  2212,  2216,  2235,  2269,  2316,  2334,  2351,  2355,  2371,
    2419,  2424,  2429,  2434,  2439,  2444,  2467,  2473,  2484,  2485,
    2490,  2493,  2497,  2520,  2543,  2566,  2594,  2615,  2641,  2662,
    2684,  2704,  2816,  2835,  2873,  2982,  2991,  2997,  3012,  3040,
    3057,  3066,  3080,  3094,  3100,  3106,  3115,  3124,  3133,  3147,
    3209,  3227,  3244,  3259,  3288,  3300,  3324,  3328,  3333,  3340,
    3345,  3351,  3356,  3362,  3370,  3374,  3378,  3383,  3443,  3459,
    3476,  3493,  3515,  3537,  3572,  3580,  3588,  3594,  3601,  3608,
    3628,  3654,  3666,  3678,  3686,  3694,  3703,  3702,  3717,  3716,
    3731,  3730,  3745,  3744,  3758,  3765,  3772,  3779,  3786,  3793,
    3800,  3807,  3814,  3822,  3821,  3835,  3834,  3848,  3847,  3861,
    3860,  3874,  3873,  3887,  3886,  3900,  3899,  3913,  3912,  3926,
    3925,  3942,  3945,  3951,  3963,  3983,  4007,  4011,  4015,  4019,
    4023,  4027,  4033,  4039,  4043,  4047,  4051,  4055,  4074,  4087,
    4090,  4106,  4109,  4126,  4129,  4135,  4138,  4145,  4148,  4155,
    4211,  4281,  4286,  4353,  4389,  4397,  4440,  4479,  4499,  4531,
    4558,  4584,  4610,  4636,  4662,  4684,  4712,  4740,  4768,  4796,
    4824,  4863,  4902,  4923,  4944,  4971,  4975,  4985,  5020,  5021,
    5022,  5026,  5032,  5044,  5062,  5090,  5091,  5092,  5093,  5094,
    5095,  5096,  5097,  5098,  5105,  5106,  5107,  5108,  5109,  5110,
    5111,  5112,  5113,  5114,  5115,  5116,  5117,  5118,  5119,  5120,
    5121,  5122,  5123,  5124,  5125,  5126,  5127,  5128,  5129,  5130,
    5131,  5132,  5133,  5134,  5135,  5136,  5137,  5146,  5147,  5148,
    5149,  5150,  5151,  5152,  5153,  5154,  5155,  5156,  5161,  5160,
    5168,  5173,  5178,  5195,  5213,  5231,  5249,  5267,  5272,  5278,
    5293,  5312,  5332,  5352,  5372,  5395,  5400,  5405,  5415,  5425,
    5430,  5441,  5450,  5455,  5460,  5487,  5491,  5495,  5499,  5503,
    5510,  5514,  5518,  5522,  5529,  5534,  5541,  5546,  5550,  5555,
    5559,  5567,  5578,  5582,  5594,  5602,  5610,  5617,  5627,  5656,
    5660,  5664,  5668,  5672,  5676,  5680,  5684,  5688,  5717,  5746,
    5775,  5804,  5817,  5830,  5843,  5856,  5866,  5876,  5888,  5901,
    5913,  5917,  5921,  5925,  5929,  5947,  5965,  5973,  5981,  6010,
    6023,  6028,  6032,  6036,  6048,  6052,  6064,  6081,  6091,  6095,
    6110,  6115,  6122,  6126,  6139,  6153,  6167,  6181,  6195,  6203,
    6214,  6218,  6222,  6230,  6236,  6242,  6250,  6258,  6265,  6273,
    6288,  6302,  6316,  6328,  6344,  6353,  6362,  6372,  6383,  6391,
    6399,  6403,  6422,  6429,  6435,  6442,  6450,  6449,  6462,  6467,
    6473,  6482,  6495,  6498,  6502
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
  "tRelocateMesh", "tPlane", "tRuled", "tTransfinite", "tComplex",
  "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
  "tDegenerated", "tRecursive", "tRotate", "tTranslate", "tSymmetry",
  "tDilate", "tExtrude", "tLevelset", "tAffine", "tRecombine", "tSmoother",
  "tSplit", "tDelete", "tCoherence", "tIntersect", "tMeshAlgorithm",
  "tReverse", "tLayers", "tScaleLast", "tHole", "tAlias",
  "tAliasWithOptions", "tCopyOptions", "tQuadTriAddVerts",
  "tQuadTriNoNewVerts", "tQuadTriSngl", "tQuadTriDbl", "tRecombLaterals",
  "tTransfQuadTri", "tText2D", "tText3D", "tInterpolationScheme", "tTime",
  "tCombine", "tBSpline", "tBezier", "tNurbs", "tNurbsOrder",
  "tNurbsKnots", "tColor", "tColorTable", "tFor", "tIn", "tEndFor", "tIf",
  "tElseIf", "tElse", "tEndIf", "tExit", "tAbort", "tField", "tReturn",
  "tCall", "tSlide", "tMacro", "tShow", "tHide", "tGetValue",
  "tGetStringValue", "tGetEnv", "tGetString", "tGetNumber", "tHomology",
  "tCohomology", "tBetti", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tGmshExecutableName",
  "tSetPartition", "tNameToString", "tStringToName", "tAFFECTDIVIDE",
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND",
  "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC", "tMINUSMINUS",
  "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'", "'#'", "','",
  "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems", "GeoFormatItem",
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
  "Command", "Slide", "Loop", "Extrude", "@10", "@11", "@12", "@13", "@14",
  "@15", "@16", "@17", "@18", "@19", "@20", "@21", "@22",
  "ExtrudeParameters", "ExtrudeParameter", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "PeriodicTransform", "Constraints", "Coherence", "HomologyCommand",
  "Homology", "FExpr", "FExpr_Single", "@23", "VExpr", "VExpr_Single",
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
     435,   436,   437,   438,   439,   440,   441,    63,   442,   443,
     444,   445,    60,    62,   446,   447,    43,    45,    42,    47,
      37,    33,   448,   449,   450,    94,    40,    41,    91,    93,
      46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   216,   217,   217,   218,   218,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   220,   220,   221,   221,   221,   221,   221,
     221,   222,   222,   222,   222,   223,   223,   223,   223,   223,
     223,   224,   224,   225,   225,   227,   228,   226,   229,   229,
     231,   230,   232,   232,   234,   233,   235,   235,   237,   236,
     238,   238,   238,   238,   238,   239,   239,   240,   240,   241,
     241,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   243,   243,   244,   244,   244,   245,   244,   246,
     244,   247,   244,   244,   248,   244,   249,   249,   250,   250,
     250,   251,   251,   252,   252,   252,   253,   253,   254,   254,
     254,   254,   255,   255,   255,   256,   256,   256,   257,   257,
     257,   258,   258,   258,   259,   259,   260,   260,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     262,   262,   262,   262,   262,   262,   262,   262,   263,   263,
     264,   264,   264,   264,   264,   264,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   266,   266,   266,   266,   266,
     267,   267,   268,   269,   269,   269,   269,   269,   269,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   271,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   273,   273,   273,   274,   273,   275,   273,
     276,   273,   277,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   278,   273,   279,   273,   280,   273,   281,
     273,   282,   273,   283,   273,   284,   273,   285,   273,   286,
     273,   287,   287,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   289,
     289,   290,   290,   291,   291,   292,   292,   293,   293,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   295,   295,   295,   296,   296,
     296,   297,   297,   297,   297,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   300,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   301,   301,   301,   301,   301,
     302,   302,   302,   302,   303,   303,   304,   304,   304,   304,
     304,   304,   305,   305,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     307,   307,   307,   307,   308,   308,   308,   308,   309,   309,
     310,   310,   311,   311,   311,   311,   311,   311,   311,   311,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   313,   312,   314,   314,
     315,   315,   316,   316,   316
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     5,     7,     7,     7,
       9,     6,     6,     6,     8,     0,     2,     2,     2,     2,
       2,     1,     3,     1,     3,     0,     0,    10,     1,     3,
       0,    13,     1,     3,     0,    15,     8,    14,     0,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     7,     7,     4,     3,     6,     6,     7,
       7,     6,     6,     9,     9,     6,     6,     7,     7,     6,
       6,     4,     8,     8,     9,     9,     9,     9,     8,     8,
       9,     9,     9,     9,     6,     9,     6,     9,     5,     8,
       8,    11,     6,     9,     5,     7,     9,     9,    11,     7,
       9,     9,     0,     1,     0,     3,     5,     0,     9,     0,
      11,     0,    11,     5,     0,     9,     0,     3,     3,     5,
       5,     0,     2,     3,     5,     3,     0,     2,     3,     3,
       3,     5,     1,     1,     3,     1,     1,     3,     1,     1,
       3,     1,     1,     3,     0,     5,     0,     2,     7,     8,
       6,     7,     4,     7,     8,     8,     7,     7,    11,     8,
       4,     8,     8,     8,     9,     3,     4,    10,     7,     7,
       8,     4,     8,    12,     8,     8,     7,     4,     8,     8,
       5,    11,     5,     9,     9,     4,     9,     9,     1,     1,
       0,     2,     6,     6,     6,     6,     8,    10,    14,    16,
      12,     8,     8,     6,    14,     4,     6,     6,     3,     4,
       5,     6,     5,     3,     3,     4,     5,     4,     5,     3,
       5,     7,     7,     3,     7,     3,     2,     2,     2,     2,
       2,    15,     2,     2,     2,     2,     2,    16,    11,     6,
       8,     8,    10,     1,     2,     2,     1,     3,     3,     4,
       4,     1,     1,     5,    11,    13,     0,     7,     0,    13,
       0,    15,     0,     6,     8,     8,     8,    12,    12,    12,
      14,    14,    14,     0,    12,     0,    12,     0,    12,     0,
      16,     0,    16,     0,    16,     0,    18,     0,    18,     0,
      18,     1,     2,     5,     7,     9,     2,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     9,     6,     0,
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
       5,    16,    16,    16,    16,     1,     1,     3,     3,     4,
       4,     4,     6,     6,     6,     6,     8,     8,     4,    14,
       1,     1,     3,     3,     9,     7,     1,     5,     3,     6,
       1,     3,     1,     1,     4,     4,     4,     4,     3,     6,
       1,     4,     1,     1,     1,     4,     6,     4,     6,     4,
       4,     4,     8,     4,     4,     4,     4,     8,     8,     6,
       4,     6,     4,     1,     4,     4,     0,     6,     1,     3,
       5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   562,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,     0,     0,   271,   272,     0,     0,     0,
     266,     0,     0,     0,     0,     0,   368,   369,   370,     0,
       0,     5,     7,     6,     8,     9,    10,    21,    11,    12,
      13,    14,    20,    19,    18,    15,    16,    17,     0,    22,
     563,     0,   417,   562,   530,   418,   420,   421,   419,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   532,
       0,   553,   534,   425,   426,   427,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   422,   423,   424,   533,
       0,     0,     0,     0,    67,    68,     0,     0,   210,     0,
       0,     0,   375,     0,   522,   563,   432,     0,     0,     0,
       0,   250,     0,   252,   253,   248,   249,     0,   254,   255,
     124,   136,    67,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   455,     0,     0,     0,     0,     0,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   562,
       0,   210,   563,     0,     0,   365,     0,     0,     0,     0,
       0,     0,     0,     0,   562,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   495,
     496,   466,   472,     0,   467,   563,   432,     0,     0,     0,
       0,   562,     0,     0,   516,     0,     0,     0,     0,   246,
     247,     0,   562,     0,     0,     0,   264,   265,     0,   210,
       0,   210,   562,     0,   563,     0,   371,     0,     0,    67,
      68,     0,     0,    60,    64,    63,    62,    61,    66,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   378,   377,
     379,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,     0,   208,     0,     0,   243,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,   239,     0,     0,   440,   185,     0,   562,     0,
     522,   563,   523,     0,     0,   558,     0,   122,   122,     0,
       0,     0,     0,   510,   511,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   333,   333,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   210,   210,     0,   457,
     456,     0,     0,     0,     0,   210,   210,     0,     0,     0,
       0,     0,     0,     0,   282,     0,   210,     0,     0,     0,
       0,     0,   335,     0,     0,     0,     0,     0,     0,     0,
     228,   366,     0,     0,     0,     0,     0,     0,     0,     0,
      67,    68,     0,     0,     0,     0,     0,     0,     0,     0,
     479,     0,     0,   480,     0,   481,     0,   482,     0,     0,
       0,     0,     0,     0,   377,   474,     0,   468,     0,     0,
       0,   343,    67,    68,     0,   245,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,     0,   268,   267,     0,
     233,     0,   234,     0,     0,     0,   210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,   445,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   428,   556,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    61,     0,
     376,    60,    61,     0,     0,    60,     0,     0,     0,     0,
       0,   205,     0,     0,     0,     0,   211,     0,     0,     0,
     393,   392,   391,   390,   386,   387,   389,   388,   381,   380,
     382,   383,   384,   385,     0,     0,     0,   186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   362,   363,   364,     0,
       0,     0,     0,   331,     0,     0,     0,   152,   153,     0,
     155,   156,     0,   158,   159,     0,   161,   162,     0,   180,
       0,   191,     0,   197,     0,     0,     0,     0,   172,   210,
       0,     0,     0,     0,     0,   459,   458,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   276,     0,     0,     0,
       0,     0,     0,     0,   346,     0,     0,   229,     0,     0,
     225,     0,     0,     0,   361,   360,     0,     0,     0,     0,
       0,   445,    69,    70,     0,   497,     0,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   483,     0,   484,     0,   485,     0,   486,     0,     0,
     376,   469,   476,     0,   382,   475,     0,     0,     0,   498,
       0,     0,     0,     0,     0,     0,     0,     0,   269,   270,
       0,     0,   235,   237,     0,   564,     0,     0,     0,    60,
      61,     0,     0,    60,    61,     0,     0,     0,     0,    91,
      75,     0,   434,   433,   447,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   416,   404,     0,   406,   407,   408,
     409,   410,   411,   412,     0,     0,     0,   543,     0,   550,
     539,   540,   541,     0,   555,   554,     0,   452,     0,     0,
       0,     0,   544,   545,   546,   454,   552,   141,   146,   114,
       0,     0,   535,     0,   537,     0,   430,   437,   438,   531,
       0,     0,     0,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,   439,
       0,     0,     0,     0,   560,     0,     0,    45,     0,     0,
       0,    58,     0,    36,    37,    38,    39,    40,   436,   435,
       0,     0,   528,    25,    23,     0,     0,     0,     0,    26,
       0,     0,   240,   559,    71,   125,    72,   137,     0,     0,
       0,   512,   513,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   329,   334,   332,     0,   342,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   376,   376,     0,     0,
       0,     0,     0,   236,   238,     0,     0,     0,   200,   202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   311,     0,   273,     0,     0,
       0,     0,     0,     0,   336,   345,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   434,   433,     0,     0,
     501,     0,   500,   499,     0,     0,   508,     0,     0,   478,
       0,     0,     0,     0,     0,     0,     0,   470,     0,     0,
     436,   435,     0,     0,     0,     0,     0,     0,   230,     0,
       0,     0,     0,     0,   232,     0,     0,   372,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   561,     0,
       0,   442,     0,   441,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,     0,    89,     0,     0,    77,
       0,     0,     0,     0,    81,   104,   106,     0,     0,   520,
       0,   112,     0,     0,     0,     0,     0,   394,     0,     0,
       0,     0,     0,    31,   444,   443,   526,   524,    24,     0,
       0,   527,   525,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   170,     0,     0,     0,     0,
       0,     0,     0,   340,     0,     0,   154,     0,   157,     0,
     160,     0,   163,     0,     0,     0,     0,     0,     0,     0,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     317,     0,     0,   316,     0,   323,     0,   325,     0,   319,
       0,   321,     0,   283,   312,     0,     0,     0,   223,     0,
       0,     0,   347,     0,   227,   226,   367,     0,     0,    32,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   487,   488,   489,   490,   477,   471,     0,
       0,     0,     0,   517,     0,     0,     0,   259,     0,     0,
       0,     0,     0,     0,     0,    86,     0,    90,     0,     0,
      78,     0,    82,     0,   242,   446,   241,   405,   413,   414,
     415,   551,     0,     0,   549,   450,   451,   453,     0,     0,
     429,   142,     0,   557,   147,   449,   536,   538,   431,     0,
       0,     0,    87,     0,     0,     0,    60,     0,     0,     0,
       0,    79,     0,     0,     0,   518,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   464,     0,     0,    27,    28,
       0,    29,     0,     0,   126,   133,     0,     0,    73,    74,
     168,     0,     0,     0,     0,     0,     0,   171,     0,     0,
     188,   189,     0,     0,   173,   196,     0,     0,     0,     0,
     164,     0,   339,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,     0,     0,     0,     0,   210,
     210,     0,   293,     0,   295,     0,   297,     0,   318,   466,
       0,     0,   324,   326,   320,   322,     0,     0,   277,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     446,   504,   503,   502,     0,     0,     0,     0,     0,     0,
       0,   505,   176,   177,     0,     0,     0,     0,   115,   119,
       0,     0,     0,   373,     0,     0,     0,    88,     0,     0,
       0,    80,     0,   448,     0,     0,     0,     0,     0,     0,
      98,     0,     0,    92,     0,     0,     0,     0,   109,     0,
       0,   110,     0,   521,   212,   213,   214,   215,     0,     0,
      41,     0,     0,     0,     0,     0,    43,   529,     0,     0,
     127,   134,     0,     0,     0,     0,   167,   174,   175,   179,
       0,     0,   190,     0,     0,   341,     0,   183,     0,     0,
     330,   195,   169,   182,   194,   199,   181,     0,   192,   198,
       0,     0,     0,     0,     0,     0,   463,     0,   462,     0,
       0,     0,   284,     0,     0,   285,     0,     0,   286,     0,
       0,     0,     0,     0,     0,     0,   222,     0,     0,   221,
       0,     0,     0,   216,     0,     0,   344,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   515,     0,   261,
     260,     0,     0,     0,     0,     0,    99,     0,     0,    93,
       0,     0,     0,   542,   548,   547,     0,   143,   145,     0,
     148,   149,   150,   100,   102,    94,    96,   105,   107,     0,
     113,     0,    83,    46,     0,     0,     0,   465,     0,     0,
       0,    30,     0,   141,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,     0,   337,   337,     0,
     120,   121,   210,     0,   203,   204,     0,     0,     0,     0,
       0,     0,     0,   313,     0,     0,   210,     0,     0,     0,
       0,     0,   207,   206,   506,   507,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   116,   117,     0,     0,   101,
     103,    95,    97,    84,     0,   510,   511,     0,     0,   519,
       0,    42,     0,     0,     0,    44,    59,     0,     0,     0,
     131,   129,   355,   357,   356,   358,   359,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   328,     0,     0,     0,   278,     0,     0,   217,     0,
       0,     0,     0,     0,     0,     0,     0,   514,   262,     0,
       0,   374,     0,   144,     0,     0,   151,   111,     0,     0,
       0,     0,     0,   128,   135,   141,   141,     0,     0,     0,
       0,     0,   338,   348,     0,     0,   349,     0,   201,     0,
     299,     0,     0,   301,     0,     0,   303,     0,     0,     0,
     314,     0,   274,     0,   210,     0,     0,     0,     0,     0,
       0,     0,     0,   178,   118,   258,     0,   138,     0,     0,
      50,     0,    56,     0,     0,     0,     0,     0,   165,   193,
       0,   352,     0,   353,   354,   460,   287,     0,     0,   294,
     288,     0,     0,   296,   289,     0,     0,   298,     0,     0,
       0,   280,     0,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,   130,
       0,     0,     0,     0,   305,     0,   307,     0,   309,   315,
     327,   279,   275,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   139,   140,    47,     0,    54,     0,     0,     0,
       0,     0,     0,   290,     0,     0,   291,     0,     0,   292,
       0,     0,   224,     0,   218,     0,     0,     0,     0,     0,
       0,    48,     0,     0,   251,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   281,     0,   509,     0,     0,     0,
       0,     0,     0,     0,     0,   257,     0,     0,   300,     0,
     302,     0,   304,     0,   219,     0,     0,     0,     0,    49,
      51,     0,    52,     0,     0,     0,     0,     0,     0,   491,
     492,   493,   494,     0,     0,    57,   350,   351,   306,   308,
     310,    53,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    91,  1015,    92,    93,   724,  1559,  1565,
    1003,  1218,  1760,  1980,  1004,  1924,  2021,  1005,  1982,  1006,
    1007,  1222,   360,   455,   190,   845,    94,   742,   467,  1693,
    1836,  1835,  1694,   468,  1754,  1186,  1381,  1187,  1384,   776,
     779,   782,   785,  1589,  1434,   706,   309,   431,   432,    97,
      98,    99,   100,   101,   102,   103,   104,   310,  1098,  1863,
    1943,   814,  1613,  1616,  1619,  1897,  1901,  1905,  1964,  1967,
    1970,  1094,  1095,  1262,  1054,   773,   823,  1784,   106,   107,
     108,   109,   311,   192,   957,   520,   263,  1414,   312,   313,
     314,   588,   323,   988,  1210,   465,   460,   958,   466,   344,
     316
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1658
static const yytype_int16 yypact[] =
{
    9616,    99,    95,  9750, -1658, -1658,  4196,    52,    64,  -164,
     -97,    41,   158,   189,   195,   201,   -64,   207,   247,    74,
     107,   -56,   -56,  -103,   137,   168,    22,   199,   215,    28,
     228,   235,   287,   323,   413,   465,   306,   623,   437,   440,
     650,   442,   705,   795,   -13,   332,   494,   -95,   350,  -138,
    -138,   360,   482,    53,   343,   499,   508,     4,    60,   514,
     533,   227,   640,   649,   669,  5736,   673,   429,   432,   478,
      26,    59, -1658,   525,   537, -1658, -1658,   762,   767,   569,
   -1658,  6248,   594,  6640,    12,    39, -1658, -1658, -1658,  9475,
     580, -1658, -1658, -1658, -1658, -1658, -1658, -1658, -1658, -1658,
   -1658, -1658, -1658, -1658, -1658, -1658, -1658, -1658,    55, -1658,
    -104,   136, -1658,    14, -1658, -1658, -1658, -1658, -1658,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   597,   603,   616,   -56,   -56,   -56,
     -56,   617,   -56,   -56,   -56,   -56,   -56,   -56,   638, -1658,
     -56, -1658, -1658, -1658, -1658, -1658,   -56,   -56,   830,   644,
     647,   651,   -56,   -56,   663,   686, -1658, -1658, -1658, -1658,
     698,  9475,  9475,  9475,  8866,  8933,    18,    16,   305,   683,
     703,   932, -1658,   706,   916,   -75,   -10,   927,  9475,  6453,
    6453, -1658,  9475, -1658, -1658, -1658, -1658,  6453, -1658, -1658,
   -1658, -1658, -1658, -1658,  6844,    16,  9475,  8667,  9475,  9475,
     750,  9475,  8667,  9475,  9475,   756,  8667,  9475,  9475,  6146,
     760,   723, -1658,  8667,  5736,  5736,  5736,   764,   779,  5736,
    5736,  5736,   785,   823,   832,   833,   837,  6351,  6556,  6761,
     761,  8196,  1006,  6146,    26,   858,   864,  -138,  -138,  -138,
    9475,  9475,  -116, -1658,   -51,  -138,   878,   905,   925,  8263,
     -48,   -77,   840,   855,   859,  5736,  5736,  6146,   880,     3,
     926, -1658,   924,  1156,  1157, -1658,   965,  1000,  1001,  5736,
    5736,   976,  1007,  1008,   641, -1658,   269,   -56,   -56,   -56,
     -56,    36,    30,    32,    38,   768,  6966,  9475,  4620, -1658,
   -1658,  2992, -1658,  1196, -1658,   264,    89,  1213,  9475,  9475,
    9475,   117,  9475,  1009, -1658,  1072,  9475,  9475,  9475, -1658,
   -1658,  9475,  1026,  1238,  1239,  1033, -1658, -1658,  1241, -1658,
    1243, -1658,   -38,  8223,   339,  6453, -1658,  6146,  6146,  9137,
    9204,  1037,  1040,  6844, -1658, -1658, -1658, -1658, -1658, -1658,
    6146,  1245,  1050,  9475,  9475,  1251,  9475,  9475,  9475,  9475,
    9475,  9475,  9475,  9475,  9475,  9475,  9475,  9475,  9475,  9475,
    9475,  9475,  9475,  9475,  9475,  9475,  9475,  9475,  6453,  6453,
    6453,  6453,  6453,  6453,  6453,  6453,  6453,  6453,  6146,  6453,
    6453,  9475,  6453,  6453,  6453,  6453,  6453,  9475,  6844,  9475,
    6453,  6453,  6453,  6453,  6453,    16,  6844,    16,  1054,  1054,
    1054,   140,  6083,   181,  8158,   167,  1053,  1253,   -56,  1052,
   -1658,  1055,  2176,  9475,  8667, -1658,  9475,  9475,  9475,  9475,
    9475,  9475,  9475,  9475,  9475,  9475,  9475,  9475,  9475,  9475,
    9475, -1658, -1658,  9475,  9475, -1658, -1658,   977,    91,   142,
   -1658,   352, -1658,   208, 10188, -1658,   276,   171,   242,  1061,
    1062,  6288,  8667,  3779, -1658,   393, 11917, 11938,  9475, 11959,
     486, 11980, 12001,  9475,   516, 12022, 12043,  1268,  9475,  9475,
     587,  1270,  1271,  1273,  9475,  9475,  1274,  1275,  1275,  9475,
    8468,  8468,  8468,  8468,  9475,  1284,  9475,  1285,  9475,  1290,
    8667,  8667, 10082,  1090,  1292,  1086, -1658, -1658,    84, -1658,
   -1658, 10214, 10240,  -138,  -138,   305,   305,    88,  9475,  9475,
    9475,  8263,  8263,  9475,  2176,   150, -1658,  9475,  9475,  9475,
    9475,  9475,  1293,  1295,  1296,  9475,  1299,  9475,  9475,  1227,
   -1658, -1658,  8667,  8667,  8667,  1300,  1301,  9475,  9475,  9475,
    9475,  9475,  1298,   577,  7171,  7376,  9475,  9475,  6453,  9475,
   -1658,  1247,  9475, -1658,  1259, -1658,  1261, -1658,  1262,    43,
      45,    46,    47,  8667,  1054, -1658, 12064, -1658,   596,  9475,
    7581, -1658,  9475,  9475,   611, -1658, 12085, 12106, 12127,  1178,
   10266, -1658,  1116,  4099, 12148, 12169,  8828, -1658, -1658,  8667,
   -1658,  2471, -1658,  2785,  9475,  9475, -1658,  9475,  9475,  1124,
    1127,   607,   301, 12190,   331,  9099,  9475,  8667,  1329,  1331,
   -1658,  9475, 12211,  9370,   169,  5454,  5454,  5454,  5454,  5454,
    5454,  5454,  5454,  5454,  5454,  5454, 10292,  5454,  5454,  5454,
    5454,  5454,  5454,  5454, 10318, 10344, 10370,   456,   681,   456,
    1145,  1146,  1147,   302,   302,  1148,   302,  1150,  1151,  1152,
   10396,   302,   302,   302,   290,   302,  4557, -1658,  1038,  1153,
    1154,  1161,   688,   692,  1166,  1169,  1158,  1313,  1314,  6146,
     175,  1317,  1333,  6146,   127,  6844,  9475,  1372,  1375,    29,
     302, -1658,   -21,    42,    34,    65, -1658,  5426,   626,  4121,
     527,  1149,   634,   634,   506,   506,   506,   506,   248,   248,
    1054,  1054,  1054,  1054,    20, 12232, 11618, -1658,  9475,  9475,
    1390,    17,  8667,  9475,  9475,  1389,  8667,  9475,  1391,  6453,
    1393, -1658,    16,  1394,  6453,  9475,  6844,  1395,  8667,  8667,
    1252,  1397,  1398, 12253,  1399,  1257,  1402,  1403, 12274,  1260,
    1405,  1406,  9475, 12295,  6903,  1183, -1658, -1658, -1658, 12316,
   12337,  9475,  6146,  1410,  1409, 12358,  1209,  4557,  1206,  1212,
    4557,  1210,  1214,  4557,  1211,  1217,  4557,  1215, 12379, -1658,
   12400, -1658, 12421, -1658,   667,   677,  8667,  1216, -1658, -1658,
    2853,  3769,  -138,  9475,  9475, -1658, -1658,  1218,  1219,  8263,
   10422, 10448, 10474, 10162,   476,  -138,  3969, 12442,  7108, 12463,
   12484, 12505,  9475,  1419, -1658,  9475, 12526, -1658, 11641, 11664,
   -1658,   713,   717,   725, -1658, -1658, 11687, 11710, 10500, 12547,
   11733,    89, -1658, -1658,  8667, -1658,  8667,  3779,  1224,  8667,
    1228,   132, 10526, 10552,   302, 10578,  1225,  7313,  1229,  1230,
    1233, -1658,  8667, -1658,  8667, -1658,  8667, -1658,  8667,   729,
   -1658, -1658,  4141,  8667,  1054, -1658, 12568, 11756,  8667, -1658,
    1444,  1445,  1450,  1250,  9475,  4053,  9475,  9475, -1658, -1658,
       5,   730, -1658, -1658,  4464, -1658,  1249,  6146,  1457,  1420,
    1421,  6146,   175,  1423,  1424,  6146,   175,  7518,   739, -1658,
   -1658, 11779,   236,  1743, -1658, -1658, -1658, -1658, -1658, -1658,
   -1658, -1658, -1658, -1658, -1658, -1658,  9475, -1658, -1658, -1658,
   -1658, -1658, -1658, -1658,  9475,  9475,  9475, -1658,  8667, -1658,
   -1658, -1658, -1658,  6453, -1658, -1658,  9475, -1658,  6146,  6453,
    6453,  6453, -1658, -1658, -1658, -1658, -1658, -1658, -1658, -1658,
    9475,  6453, -1658,  6453, -1658,  9475, -1658, -1658, -1658, -1658,
     -56,   -56,  1473, -1658,  9475,  1476,   -56,   -56,  1477,    27,
    9475,  1478,  1479,  1193, -1658,  1465,  1280,    26,  1484, -1658,
    8667,  8667,  8667,  8667, -1658,   302,  9475, -1658,  1286,  1287,
    1281, -1658,  1489, -1658, -1658, -1658, -1658, -1658,   286,   297,
   12589, 11802, -1658, -1658,  1303,  6453,   406, 12610, 11825, -1658,
     452, 10604, -1658, -1658, -1658,    -6, -1658, -1658,  5454,   302,
    -138,  3779, -1658,   772,  6146,  6146,  1490,  6146,   862,  6146,
    6146,  1491,  1407,  6146,  6146,  1541,  1493,  1495,  8667,  1496,
    1498,   -73, -1658, -1658,  1503, -1658,  1505,   391,  9475,   391,
    9475,   391,  9475,   391,  9475,  1507,  1508,  1509,  1510,  1511,
     743,  1506,  5581, -1658, -1658,   172, 10630, 10656, -1658, -1658,
    7723,   -58,  -138,  -138,  -138,  1516,  9408,  1308,  1518,  1316,
      15,    19,    21,    54,   -34, -1658,   226, -1658,   476,  1523,
    1519,  1524,  1526,  1529,  4557, -1658,  1638,  1324,  1532,  1533,
    1534,  1451,  1535,  1538,  1539,  9475,    89,    85,   747,   751,
   -1658,   757, -1658, -1658,  9475,  9475, -1658,  9475,  9475, -1658,
    9475,  9475,  9475,   763,   766,   799,   803, -1658,  9475,   804,
      89,    89,   807,  6146,  6146,  6146,  1542, 10682, -1658,  4577,
     906,  1544,  1546,  1339, -1658,  6146,  1338, -1658,   -56,   -56,
    1550,  9475,  1552,   -56,   -56,  1553,  9475,  1555, -1658,   302,
    1559, -1658,  1562, -1658,  1561,  5454,  5454,  5454,  5454,   696,
    1360, 10136,  1367,   302,   302,  1363,   700,   711, 12631,  1369,
     302,  5454,  1800,  6453, -1658,  1696, -1658,  1800,  6453, -1658,
     309,  1368,  1570,  1898, -1658, -1658, -1658,    26,  9475, -1658,
     808, -1658,   812,   813,   816,   821,   391,  4557,  1373,  9475,
    9475,  6146,  1374, -1658, -1658, -1658, -1658,  1371, -1658,  1576,
      23, -1658, -1658,  1579,  9475,  5253,  1379,  1380,  1582,  1591,
       9,  1392,  1400,  1502,  1502,  6146,  1597,  1401,  1404,  1598,
    1600,  6146,  1408,  1601,  1602, -1658,  1607,  6146,   835,  6146,
    6146,  1612,  1614, -1658,  6146,  6146,  4557,  6146,  4557,  6146,
    4557,  6146,  4557,  6146,  6146,  6146,  1412,  1413,  1611,   349,
   -1658,  9475,  9475,  9475,  1417,  1418,  -125,  -106,   -84,  1414,
   -1658,  1948,  6146, -1658,  9475, -1658,  1617, -1658,  1626, -1658,
    1627, -1658,  1628, -1658, -1658,  8263,   548,  5941, -1658,  1422,
    1425,  7786, -1658,  8667, -1658, -1658, -1658,  1426,  9475, -1658,
   -1658, 11848,  1632,   302,  1430,  1431, 10708, 10734, 10760, 10786,
   10812, 10838, 10864, -1658, -1658, -1658, -1658,  4557, -1658,   302,
    1636,  1637,  1499, -1658,  9475,  9475,  9475, -1658,  1639,   748,
    6844,  1435,  1643,  1800,  6453, -1658,  2118, -1658,  1800,  6453,
   -1658,  2663, -1658,   391, -1658,   375, -1658, -1658, -1658, -1658,
   -1658, -1658,  6453,  9475, -1658, -1658, -1658, -1658,  6453,  1647,
   -1658, -1658,     6, -1658, -1658, -1658, -1658, -1658, -1658,  1646,
     456,   456, -1658,  1648,   456,   456,  6844,  9475,  1650,  1651,
      29, -1658,  1652, 11871,    26, -1658,  1653,  1654,  1655,  1656,
    6146,  9475, 10890, 10916,   838, -1658,  9475,  1660, -1658, -1658,
    6453, -1658, 10942,  4843,  4557, -1658,  1658,  1661, -1658, -1658,
   -1658,  9475,  9475,  -138,  1663,  1664,  1665, -1658,  9475,  9475,
   -1658, -1658,  1666,  9475, -1658, -1658,  1662,  1667,  1440,  1668,
    1527,  9475, -1658,  1669,  1671,  1673,  1675,  1676,  1677,  1047,
    1678,  8667,  8667,  9475, -1658,  8468,  7928, 12652,  4780,   305,
     305,  -138,  1680,  -138,  1681,  -138,  1683,  9475, -1658,   268,
    1482, 12673, -1658, -1658, -1658, -1658,  8048,   230, -1658,  1685,
    4414,  1689,  6146,  -138,  4414,  1690,   843,  9475,  2909,  1691,
      89, -1658, -1658, -1658,  9475,  9475,  9475,  9475,  9475,  9475,
    9475, -1658, -1658, -1658,  6146,  4985,   809, 12694, -1658, -1658,
    5326,  1486,  6146, -1658,  1693,   456,   456, -1658,  1694,   456,
     456, -1658,  6146, -1658,  1494,  5454,   302,  5048,  5531,  6844,
   -1658,  1698,  1699, -1658,  1701,  1718,  1719,  3037, -1658,  1735,
    1737, -1658,  1540, -1658, -1658, -1658, -1658, -1658,  1739,   487,
    4557,  9475,  9475,  6146,  1545,   844,  4557, -1658,  1746,  9475,
   -1658, -1658,  1547,  1549,  8115,  8363,   798, -1658, -1658, -1658,
    8391,  8419, -1658,  8604,  1749, -1658,  6146, -1658,  1682,  1751,
    4557, -1658, -1658, -1658, -1658, -1658, -1658,  1556, -1658, -1658,
     848,   852, 10109,  3080,  1753,  1558, -1658,  9475, -1658,  1551,
    1560,   233, -1658,  1565,   284, -1658,  1566,   356, -1658,  1572,
   11894,  1757,  6146,  1748,  1573,  9475, -1658,  7991,   374, -1658,
     869,   388,   400, -1658,  1760,  8718, -1658, -1658,  5454,  5454,
   10968, 10994, 11020, 11046, 11072,  1670,  9475, -1658,  9475, -1658,
   -1658,  8667,  3204,  1766,  6844,  1583, -1658,  1767,  1790, -1658,
    1792,  1805,  1806, -1658, -1658, -1658,  4620, -1658, -1658,  6453,
    4557, -1658, -1658, -1658, -1658, -1658, -1658, -1658, -1658,    26,
   -1658,  1657, -1658, -1658,  9475, 11098, 11124, -1658,  6146,  9475,
    1808, -1658, 11150, -1658, -1658,  6146,  6146,  1811,  1812,  1814,
    1815,  1817,  1833,   870,  1594, -1658,  6146,   636,   755,  8667,
   -1658, -1658,   305,  5285, -1658, -1658,  8263,   476,  8263,   476,
    8263,   476,  1834, -1658,   873,  6146, -1658,  8785,  -138,  1835,
    8667,  -138, -1658, -1658, -1658, -1658,  9475,  9475,  9475,  9475,
    9475,  9475,  8891,  8989,   895, -1658, -1658,  1635,  1847, -1658,
   -1658, -1658, -1658, -1658,   896,  3758,  1848,   900,  1855, -1658,
    1641,  4557,  9475,  9475,   921,  4557, -1658,  9475,   931,   934,
   -1658, -1658, -1658, -1658, -1658, -1658, -1658, -1658,  1659,  9475,
     935,  1684,  -138,  6146,  1862,  1686,  -138,  1863,   939,  1688,
    9475, -1658,  9056,   402,   631,  9162,   449,   941,  9260,   496,
    1160, -1658,  6146,  1865,  1768,  5786,  1692,   538, -1658,   942,
     555, 11176, 11202, 11228, 11254, 11280,  3233, -1658, -1658,  1868,
    1870, -1658,  9475, -1658,  6844,    16, -1658, -1658,  9475, 12715,
   11306,    49, 11332, -1658, -1658, -1658, -1658,  9475,  9327,  1872,
    -138,    70, -1658, -1658,  -138,    73, -1658,  1873, -1658,  9746,
    1876,  9475,  1892,  1897,  9475,  1901,  1903,  9475,  1907,  1703,
   -1658,  9475, -1658,   476, -1658,  8667,  1909,  7991,  9475,  9475,
    9475,  9475,  9475, -1658, -1658, -1658,  1521, -1658,  1712,   945,
   -1658,  9475, -1658,  6146,  9475,   946,   967, 11358, -1658, -1658,
     575, -1658,   579, -1658, -1658, -1658, -1658,  1707,  9774, -1658,
   -1658,  1708,  9802, -1658, -1658,  1710,  9830, -1658,  1920,  3409,
    1321,  5991,   971, -1658,   582,   979, 11384, 11410, 11436, 11462,
   11488,  6844,  1723,  1925,  1724, 12736,   989,  9858, -1658, -1658,
    9475,  -138,  -138,   476,  1926,   476,  1932,   476,  1934, -1658,
   -1658, -1658, -1658,   476,  1935,  8667,  1937,  9475,  9475,  9475,
    9475,  9475, -1658, -1658, -1658,  6453, -1658,  1731,  1939,  9886,
     584,   586,  1343, -1658,  1736,  1436, -1658,  1738,  1466, -1658,
    1742,  1649, -1658,   993, -1658,  5454, 11514, 11540, 11566, 11592,
     994, -1658,  1744,  6146, -1658,  1942,  9475,  9475,  1944,   476,
    1952,   476,  1953,   476, -1658,  1954, -1658,  9475,  9475,  9475,
    9475,  6453,  1955,  6453,   997, -1658,  9914,  9942, -1658,  1801,
   -1658,  1886, -1658,  2239, -1658,  9970,  9998, 10026, 10054, -1658,
   -1658,   998, -1658,  1956,  1957,  1960,  1964,  1965,  1966, -1658,
   -1658, -1658, -1658,  6453,  1967, -1658, -1658, -1658, -1658, -1658,
   -1658, -1658, -1658
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1658, -1658, -1658, -1658,   744, -1658, -1658, -1658, -1658,   147,
   -1658, -1658, -1658, -1658, -1658, -1658, -1658, -1658, -1658, -1658,
   -1658, -1658,  -146,    80,  3879,  1854, -1658,  1515, -1658, -1658,
   -1658, -1658, -1658, -1658, -1658, -1657, -1658,   282, -1658, -1658,
   -1658, -1658, -1658, -1658,   733,  1975,    11,  -520,  -253, -1658,
   -1658, -1658, -1658, -1658, -1658, -1658, -1658,  1981, -1658, -1658,
   -1658, -1658, -1658, -1658, -1658, -1658, -1658, -1658, -1658, -1658,
   -1658, -1059, -1085, -1658, -1658,  1487, -1658,   278, -1658, -1658,
   -1658, -1658,  1850, -1658, -1658,    33, -1658, -1479,  2402,   381,
    2896,  -177,  -243,   588, -1658,   129,    90, -1658,  -386,    -3,
     237
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -530
static const yytype_int16 yytable[] =
{
     110,  1235,   657,   195,   659,   807,   808,   546,   279,  1304,
    1538,   515,  1151,  1630,    96,  1430,   534,   338,   362,   674,
     332,  1295,   425,  1013,   997,  1297,   220,  1299,   549,  1419,
     321,  1200,   225,   986,  1261,   573,  1768,   575,   225,  1306,
     475,   570,   199,   577,   340,   480,   220,   201,   861,   484,
     863,   865,   867,   254,   282,  1882,   490,   271,   258,   259,
    1301,   346,   315,   325,   284,   197,   285,   282,   260,   255,
     256,   523,   524,  1085,   250,   261,  1891,   251,   282,  1893,
     523,   524,   262,   264,  1086,   270,   611,  1471,   613,  1472,
     523,   524,  1087,  1088,  1089,     5,   194,   525,  1090,  1091,
    1092,  1093,   349,   216,   350,     4,  1473,  1703,  1474,   200,
     217,   351,   523,   524,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,  1475,   537,
    1476,   453,   450,   454,   973,   193,   538,   272,   523,   524,
     351,   273,   207,   353,   286,   523,   524,   687,   523,   524,
     212,  1296,   213,   274,   198,  1298,  1285,  1300,   998,   999,
    1000,  1001,   526,   280,   203,   536,   426,   427,   614,  1539,
     615,   333,   562,   337,   695,  1201,  1202,   189,  1885,  1886,
    1303,   574,   973,   576,   282,   216,    90,   571,   691,   578,
    1302,   361,   990,   358,   359,   204,   461,   461,    90,   430,
    1236,   205,  1237,  -523,   461,   523,   524,   206,    90,  1764,
    1014,   547,   282,   208,   315,  1152,  1014,   281,   189,   315,
     363,  1304,   364,   315,   365,   339,   315,  1780,   221,   189,
     315,   315,   315,   315,  1002,   222,   315,   315,   315,   322,
     111,   226,   987,   196,   315,   315,   315,   992,   221,   572,
     315,   282,   341,   209,   202,   991,   862,   708,   864,   866,
     868,   347,  1883,   800,   801,   326,   523,   524,   348,   523,
     524,   228,   315,   315,   315,   689,   589,   693,   993,   696,
     523,   524,   210,   816,   523,   524,   315,   315,   358,   359,
     518,   519,   358,   359,   283,  1322,   802,   728,   527,   729,
     809,   730,   535,   315,   469,   315,   189,   324,   899,   429,
     354,   355,   356,   357,   289,   211,  1396,   290,   334,   354,
     355,   356,   357,   354,   355,   356,   688,   599,   459,   463,
     358,   359,   189,   794,   795,   358,   359,   979,   903,   358,
     359,  1123,   461,   218,   315,   315,   523,   524,   885,   731,
     354,   355,   356,   357,   732,  1464,  1465,   315,   354,   355,
     356,   357,   815,   894,   354,   355,   356,   692,   523,   524,
     358,   359,   358,   359,   219,   831,   832,   833,   358,   359,
     740,   229,  -528,   741,  1281,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   315,   461,   461,   973,   461,
     461,   461,   461,   461,  1926,   223,   869,   461,   461,   461,
     461,   461,   282,   230,   282,   735,    48,    49,    50,    51,
     736,   224,   523,   524,   428,    56,   523,   524,    59,   523,
     524,   315,   891,   275,   227,   276,   462,   462,  1305,   358,
     359,   228,  1625,   628,   462,  1716,   447,   448,   449,  -526,
     908,   743,   470,   450,   741,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   590,   448,   449,   315,
     592,   232,   593,   450,   619,   564,   901,   565,   905,   351,
     523,   524,  1621,   738,   354,   355,   356,   900,   739,   358,
     359,   324,   354,   355,   356,   357,  1718,   955,   677,  -527,
     358,   359,   739,   231,  2004,   697,   685,   315,   315,   842,
    -525,   843,   358,   359,   354,   355,   356,   904,   658,   233,
     660,   661,   662,   663,   664,   665,   666,   237,   668,   669,
     238,   671,   672,   673,   242,   675,   430,   430,   252,   679,
     680,   681,   682,   683,   974,   617,  1072,   618,   980,   315,
     315,   315,   523,   524,   351,  1016,   805,   806,   733,  1020,
     734,   315,   315,   257,   519,   461,   266,   351,  1720,   267,
     523,   524,   268,   265,   354,   355,   356,   357,   358,   359,
     315,   253,   462,  1085,   523,   524,  1728,   315,  -529,   277,
     778,   781,   784,   787,  1086,   278,   523,   524,   523,   524,
    1730,   287,  1087,  1088,  1089,   749,   315,   750,  1090,  1091,
    1092,  1093,  1731,  1230,  1851,   491,   492,   493,   749,  1070,
     496,   497,   498,   288,   315,   462,   462,   462,   462,   462,
     462,   462,   462,   462,   462,   318,   462,   462,   319,   462,
     462,   462,   462,   462,   291,   523,   524,   462,   462,   462,
     462,   462,   684,   292,   686,  1085,   542,   543,  1794,  1233,
    1797,  1854,  1800,   842,   749,   843,  1086,  1118,   739,  1119,
     555,   556,  1121,   293,  1087,  1088,  1089,   317,   258,   259,
    1090,  1091,  1092,  1093,   320,  1133,   315,  1134,   260,  1135,
     315,  1136,   523,   524,  1683,   269,  1139,   854,   749,  1684,
     755,  1142,   445,   446,   447,   448,   449,   234,  1857,  1304,
     235,   450,  1304,   236,   914,  1304,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   749,   315,
     759,   327,   450,   315,   523,   524,   461,   239,  1085,   282,
     240,   461,   241,   328,  1209,   315,   315,  1781,  1782,  1086,
    1865,   523,   524,  1783,  1519,  1520,  1161,  1087,  1088,  1089,
    1166,  1179,  1488,  1090,  1091,  1092,  1093,  1867,   329,   315,
     975,   523,   524,   330,   981,   523,   524,   331,   523,   524,
     523,   524,   523,   524,   842,   982,   843,  1931,   345,   243,
     844,  1932,   244,   315,  1945,   245,  1986,   246,  1987,   749,
     335,   765,   851,   391,  1910,   462,  1390,  1391,   749,   392,
     871,  1394,  1395,  1212,  1213,  1214,  1215,  1648,   842,   897,
     843,   898,   393,   398,   878,  1304,   441,   442,   443,   444,
     445,   446,   447,   448,   449,  1075,  1029,   409,   749,   450,
     995,   315,  1081,   315,   405,  1852,   315,   560,  1096,   561,
     410,   562,   579,   411,   188,   580,   189,   412,   581,   315,
     582,   315,  1241,   315,  1242,   315,  1785,  1786,  1023,   415,
     315,  1258,  1783,  1027,  1962,   315,  1965,  1304,  1968,   749,
    1304,  1068,   247,  1304,  1971,   248,  1304,   249,   842,   749,
     843,  1069,   416,   938,   315,   842,   433,   843,   315,   842,
     963,   843,   315,   842,   965,   843,   417,   842,   749,   843,
     461,  1265,  1379,  1267,  1346,  1269,   434,  1271,   842,   451,
     843,   914,   452,  1382,  1304,   749,  1304,  1110,  1304,   749,
    2009,  1111,  2011,   456,  2013,   315,   489,   749,   435,  1112,
     461,   749,   749,  1137,  1153,   315,   461,   461,   461,  1609,
    1610,   749,  1247,  1169,  1248,   749,   478,  1278,   461,   749,
     461,  1323,   483,   749,  1402,  1324,   488,  1525,  1526,   749,
     494,  1325,  1529,  1530,   510,   749,   462,  1333,   749,  1025,
    1334,   462,  1162,   727,   282,   495,  1167,   315,   315,   315,
     315,   499,  1171,  1173,   523,   524,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     513,   749,   461,  1335,   450,   749,   749,  1336,  1338,   749,
    1404,  1339,  1405,  1649,   749,   749,  1406,  1407,   749,   500,
    1408,   315,   315,   749,   315,  1409,   315,   315,   501,   502,
     315,   315,  1174,   503,   959,   315,   539,   749,  1085,  1448,
    1563,  1597,  1564,  1598,  1397,   749,  1689,  1634,  1690,  1086,
     749,   540,  1707,  1240,   749,   541,  1708,  1087,  1088,  1089,
    1410,   516,  1180,  1090,  1091,  1092,  1093,   517,  1183,  1184,
    1185,  1563,  1563,  1729,  1778,  1802,   545,  1803,  1224,  1225,
    1189,   528,  1190,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   749,  1822,  1819,
    1823,   450,   739,  1347,  1826,  1286,  1287,  1288,   529,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,  1563,   548,  1831,  1496,   450,   530,   351,
     315,   315,   315,  1379,  1229,  1833,  1382,  1563,  1834,  1839,
     462,   749,   315,  1847,   749,  1855,  1866,  1689,  1379,  1923,
    1928,  1553,   550,   551,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   552,  1379,
     462,  1929,   450,   749,   557,  1944,   462,   462,   462,   461,
     461,   749,  1789,  1946,   461,   461,  1171,  1173,   462,  1206,
     462,  1563,   591,  1957,   282,   749,  2001,  1995,  2002,  1563,
    2033,  2023,  2034,   553,   554,   558,   559,  1532,   315,   595,
    1224,  1225,   601,   602,   324,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     7,
       8,   189,   315,   450,   607,   608,   609,   610,   315,   612,
     626,   630,   462,   627,   315,   634,   315,   315,   631,   450,
     699,   315,   315,   698,   315,   188,   315,  1085,   315,   701,
     315,   315,   315,   745,   746,   762,   766,   767,  1086,   768,
    1398,   771,   772,  1757,  1600,  1601,  1087,  1088,  1089,   315,
     789,   791,  1090,  1091,  1092,  1093,   793,   797,   798,   799,
     822,   824,   841,   825,   315,   827,   834,   835,   315,   856,
     315,   702,    24,    25,   703,    27,    28,   704,    30,   705,
      32,   858,    33,   859,   860,  1425,   883,    38,    39,   886,
      41,    42,    43,   895,   896,   909,    46,   910,  1487,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     461,   461,   941,   942,   450,   461,   461,   970,   971,   943,
     946,   976,   948,   949,   950,   960,   961,   969,   962,   461,
      67,    68,    69,   967,  1858,   461,   968,   977,   984,   985,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,  1012,  1019,  1048,  1022,   450,  1024,
    1026,   282,  1030,  1033,  1034,  1035,  1037,   315,  1038,  1039,
    1040,  1042,  1043,  1044,  1053,  1055,  1057,   461,  1058,  1059,
     315,  1061,  1060,  1062,  1063,  1105,  1071,  1064,  1085,   462,
     462,  1120,  1078,  1079,   462,   462,  1758,  1122,  1128,  1086,
    1521,   830,  1130,  1131,   324,  1533,  1132,  1087,  1088,  1089,
    1085,  1143,  1144,  1090,  1091,  1092,  1093,  1145,   315,   315,
    1146,  1086,  1155,  1157,  1158,  1159,  1576,  1163,  1164,  1087,
    1088,  1089,  1207,  1805,  1744,  1090,  1091,  1092,  1093,  1194,
     430,   430,  1196,  1199,  1204,  1205,  1546,   315,  1208,   315,
    1211,   315,  1219,  1220,  1221,  1223,  1228,  1245,  1251,  1252,
    1256,  1534,  1257,  1259,  1611,  1260,  1614,  1536,  1617,  1263,
    1279,   315,  1264,  1571,  1273,  1274,  1275,  1276,  1277,   315,
    1289,  1292,  1294,  1628,  1293,  1308,  1631,  1632,  1921,   315,
    1307,  1309,  1788,  1310,   315,  1941,  1311,  1313,  1314,  1315,
    1316,  1317,  1318,  1085,  1319,  1320,  1343,  1255,  1348,  1568,
    1349,  1350,  1352,  1809,  1086,  1604,  1355,  1988,  1357,  1360,
     315,  1362,  1087,  1088,  1089,  1364,  1365,  1366,  1090,  1091,
    1092,  1093,  1372,  1085,  1375,  1378,  1386,  1400,  1399,  1411,
    1533,  1417,  1418,   315,  1086,  1421,  1426,  1416,  1428,  1427,
     462,   462,  1087,  1088,  1089,   462,   462,  1429,  1090,  1091,
    1092,  1093,  1433,  1437,  1440,  1431,  1441,  1444,  1445,   462,
    1653,  1911,  1446,  1432,  1438,   462,  1451,  1439,  1463,   315,
    1452,  1443,  1477,  1482,   315,  1461,  1462,  1668,  1671,  1672,
    1469,  1470,  1483,  1484,  1485,  1492,  1500,  1502,  1493,  1497,
    1503,   324,  1512,  1513,  1312,  1518,  1514,  1522,   315,  1523,
    1990,  1537,  1540,  1586,  1543,  1549,  1548,   462,  1551,  1554,
    1555,  1556,  1557,   315,  1567,  1572,   461,  1584,  1573,  1577,
    1578,  1579,  1582,  1585,  1587,  1591,   282,  1592,  1588,  1593,
    1992,  1594,  1595,  1596,  1599,   315,  1612,  1615,  1912,  1618,
    1915,  1626,   315,   315,  1622,  1629,  1633,  1637,  1654,  1656,
    1659,  1663,  1392,   315,  1673,  1674,   315,  1675,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   315,   430,  1676,  1677,   450,   315,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,  1679,  1680,  1747,  1682,   450,   458,   114,  1793,
    1681,  1796,  1691,  1799,  1702,  1725,  1085,  1705,  1688,  1711,
    1695,  1807,  1696,  1723,  1810,  1714,  1732,  1086,  1973,  1706,
    1704,  1712,  1746,  1749,  1715,  1087,  1088,  1089,  1717,  1719,
     315,  1090,  1091,  1092,  1093,  1721,  1726,   141,   142,   143,
     144,   145,   146,   147,   148,   149,  1750,  1748,  1751,   315,
     154,   155,   156,   157,   458,   114,  1759,  1779,   159,   160,
     161,  1752,  1753,   162,  1766,  1841,  1741,  1772,  1773,  1845,
    1774,  1775,   282,  1776,   167,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,  1777,
    1801,  1808,  1820,   450,   141,   142,   143,   144,   145,   146,
     147,   148,   149,  1821,  1828,  1825,   191,   154,   155,   156,
     157,  1827,   315,  1994,   315,   159,   160,   161,  1843,  1846,
     162,  1860,  1837,  1890,  1874,  1861,  1875,  1892,  1889,  1894,
     315,   167,  1896,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,  1840,  1899,  1844,
    1914,   450,  1848,  1900,  1401,  1864,   462,  1903,  1085,  1904,
     170,   171,   172,  1907,  1877,  1913,   324,  1908,  1922,  1086,
    1933,  1935,   179,  1937,   180,    90,  1939,  1087,  1088,  1089,
    1953,  1954,  1963,  1090,  1091,  1092,  1093,  1955,  1966,   343,
    1969,  1972,   315,  1974,  1983,  1984,   358,   359,  2005,  1989,
    2008,  1991,   461,  1172,  1478,  1993,  -524,  2003,  2010,  2012,
    2014,  2020,  2035,  2036,  1960,  1961,  2037,   170,   171,   172,
    2038,  2039,  2040,  2042,  1420,  1879,  1769,  1435,    95,   179,
     315,   180,    90,   744,   105,   774,  1787,     0,  1550,     0,
       0,     0,     0,  1085,     0,     0,     0,     0,   461,     0,
     461,     0,     0,     0,  1086,     0,     0,   842,     0,   843,
       0,  1952,  1087,  1088,  1089,  2026,     0,     0,  1090,  1091,
    1092,  1093,     0,     0,     0,     0,     0,     0,     0,     0,
     461,   418,   419,   420,   422,   424,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   457,     0,
       0,     0,   464,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1878,     0,     0,     0,   471,   473,   476,   477,
       0,   479,   473,   481,   482,     0,   473,   485,   486,     0,
       0,     0,     0,   473,  1981,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
    2027,   512,     0,   450,     0,     0,     0,     0,     0,     0,
     521,   522,     0,     0,     0,     0,     0,     0,     0,   522,
       0,     0,     0,     0,  1527,     0,     0,     0,     0,     0,
    2019,     0,  2022,     0,     0,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,   584,   586,   473,     0,
       0,     0,  2041,     0,     0,     0,     0,     0,   596,   597,
     598,     0,   600,     0,     0,     0,   603,   604,   605,     0,
       0,   606,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,   462,     0,     0,     0,     0,     0,     0,   623,
     625,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   632,   633,     0,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   654,   655,   656,   462,     0,
     462,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   670,     0,     0,     0,     0,     0,   676,     0,   678,
     702,    24,    25,   703,    27,    28,   704,    30,   705,    32,
     462,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,   707,   473,    46,   709,   710,   711,   712,
     713,   714,   715,   716,   717,   718,   719,   720,   721,   722,
     723,     0,     0,   725,   726,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,    67,
      68,    69,   584,   450,     0,     0,     0,     0,   753,     0,
       0,     0,     0,   758,     0,     0,     0,     0,   763,   764,
       0,     0,     0,     0,   769,   770,  1085,     0,     0,   775,
     777,   780,   783,   786,   788,     0,   790,  1086,   792,     0,
     473,   473,     0,     0,     0,  1087,  1088,  1089,     0,     0,
       0,  1090,  1091,  1092,  1093,     0,     0,     0,   810,   811,
     812,   418,   419,   813,     0,     0,     0,   817,   818,   819,
     820,   821,     0,     0,     0,   826,     0,   828,   829,     0,
       0,     0,   473,   473,   473,     0,     0,   836,   837,   838,
     839,   840,     0,     0,   847,   847,   852,   853,     0,   855,
       0,     0,   857,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   473,     0,     0,     0,     0,     0,   872,
     874,     0,   876,   877,     0,     0,     0,     0,   879,     0,
       0,     0,     0,  2028,     0,     0,     0,     0,     0,   473,
       0,     0,     0,     0,   839,   840,     0,   876,   877,     0,
       0,     0,     0,     0,     0,     0,   907,   473,     0,     0,
       0,   911,     0,     7,     8,     0,     0,     0,     0,   915,
     916,   917,   918,   919,   920,   921,   922,   923,   924,   925,
       0,   927,   928,   929,   930,   931,   932,   933,     0,     0,
       0,   937,   939,   940,     0,     0,     0,   944,   945,     0,
     947,     0,     0,     0,     0,   952,   953,   954,     0,   956,
       0,     0,     0,     0,     0,     0,   964,   966,     0,     0,
       0,     0,     0,     0,     0,     0,   983,     0,     0,     0,
       0,     0,     0,     0,   989,   702,    24,    25,   703,    27,
      28,   704,    30,   705,    32,     0,    33,     0,     0,     0,
       0,    38,    39,     0,    41,    42,    43,     0,  1010,  1011,
      46,     0,   473,  1017,  1018,     0,   473,  1021,     0,     0,
       0,     0,     0,     0,     0,  1028,     0,     0,   874,  1031,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1045,     0,    67,    68,    69,     0,     0,     0,
       0,  1051,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   487,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   473,     0,     0,   505,
     507,   509,     0,  1076,  1077,   514,     0,     0,     0,  1080,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1531,
       0,     0,  1104,     0,     0,  1106,     0,     0,     0,   544,
       0,     0,     0,     0,     0,   892,     0,     0,     0,     0,
       0,     0,     0,     0,   473,     0,   473,     0,     0,   473,
       0,     0,     0,     0,     0,     0,     0,     0,  1126,     0,
       0,     0,   473,     0,   473,     0,   473,     0,   473,     0,
       0,     0,     0,   473,     0,     0,     0,     0,   473,     0,
       0,     0,     0,     0,  1147,     0,  1149,  1150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   620,
     621,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1175,     0,     0,     0,
       0,     0,     0,     0,  1176,  1177,  1178,     0,   473,     0,
       0,     0,     0,     0,     0,     0,  1181,     7,     8,     0,
     667,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1188,     0,     0,     0,     0,  1191,     0,     0,     0,     0,
       0,     0,     0,     0,  1195,     0,     0,     0,     0,     0,
    1203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     473,   473,   473,   473,     0,     0,  1217,     0,     0,  1216,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,     0,     7,     8,     0,   450,   702,
      24,    25,   703,    27,    28,   704,    30,   705,    32,     0,
      33,     0,  1238,  1239,     0,    38,    39,     0,    41,    42,
      43,     0,     0,     0,    46,     0,     0,     0,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1266,     0,
    1268,     0,  1270,     0,  1272,  1636,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,    68,
      69,     0,     0,     0,     0,     0,  1291,   702,    24,    25,
     703,    27,    28,   704,    30,   705,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,     0,  1321,     0,     0,     0,     0,
       0,     0,     0,     0,  1326,  1327,     0,  1328,  1329,     0,
    1330,  1331,  1332,     0,     0,     0,     0,     0,  1337,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,   893,
     589,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1356,     0,     0,     0,     0,  1361,     0,     0,     0,
       0,     0,     0,  1363,     0,     0,     0,     0,     0,  1367,
    1368,  1369,  1370,  1371,     0,  1374,     0,  1376,  1377,     0,
    1380,  1383,     0,  1678,  1387,  1388,  1389,     0,     0,     0,
       0,  1393,     0,     0,     0,     0,     0,     0,  1403,     0,
       0,     0,     0,     0,     0,     0,     0,  1073,     0,  1412,
    1413,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1422,  1424,  1710,     0,     0,     0,
       0,   972,     0,     0,     0,   978,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
       0,     0,     0,   474,   450,     0,     0,     0,   474,     0,
       0,     0,   474,     0,     0,     0,     0,     0,     0,   474,
       0,  1466,  1467,  1468,     0,     0,     0,     0,     0,     0,
       0,     0,  1479,     0,  1481,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1486,     0,     0,     0,     0,
       0,     0,     0,   473,     0,     0,     0,     0,  1498,     0,
       0,     0,     0,     0,  1052,     0,     0,  1501,     0,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     590,   448,   449,  1511,  1515,  1516,  1517,   450,     0,     0,
       0,     0,   585,     0,   474,     0,     0,  1524,     0,     0,
    1745,     0,  1528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1535,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,     0,  1873,
       0,     0,   450,     0,  1541,  1542,     0,  1547,  1544,  1545,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1560,     0,     0,     0,     0,  1566,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,  1574,  1575,     0,     0,   450,     0,     0,  1580,  1581,
       0,     0,     0,  1583,     0,     0,     0,     0,     0,  1156,
       0,  1590,     0,  1160,     0,     0,     0,  1165,     0,     0,
       0,   473,   473,  1602,     0,  1603,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1620,     0,     0,
     474,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     473,     0,     0,     0,   473,     0,     0,  1635,     0,     0,
    1182,     0,     0,     0,  1638,  1639,  1640,  1641,  1642,  1643,
    1644,     0,     0,     0,     0,     0,     0,     0,   585,     0,
    1652,     0,     0,     0,     0,     0,     0,     0,     0,  1657,
    1658,     0,     0,  1660,  1661,     0,     0,     0,  1670,  1664,
    1665,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,   474,   474,     0,   450,
       0,  1685,  1686,     0,     0,  1940,     0,     0,     0,  1692,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,     0,     0,  1243,  1244,   450,  1246,
       0,  1249,  1250,     0,     0,  1253,  1254,     0,   474,   474,
     474,     0,     0,     0,     0,     0,     0,  1713,     0,     0,
     848,   850,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1727,     0,   584,     0,   474,
       0,     0,     0,     0,     0,     0,   875,     0,     0,     0,
       0,     0,  1734,  1735,     0,     0,  1742,     0,  1743,     0,
       0,   473,     0,     0,     0,   474,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1755,     0,     0,     0,
       0,     0,     0,   474,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1761,     0,     0,     0,     0,  1765,
       0,     0,     0,     0,     0,  1340,  1341,  1342,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1351,     0,   473,
       0,     0,     0,     0,     0,     0,  1792,     0,  1795,     0,
    1798,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     473,     0,     0,     0,     0,     0,  1811,  1812,  1813,  1814,
    1815,  1816,     0,     0,     0,     0,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
       0,     0,  1829,  1830,   450,     0,     0,  1832,     0,     0,
       0,     0,     0,  1415,     0,     0,     0,     0,   474,  1838,
       0,     0,   474,     0,     0,     0,     0,     0,     0,     0,
    1849,     0,     0,     0,   875,  1032,     0,  1436,     0,     0,
       0,     0,     0,  1442,     0,     0,     0,     0,     0,  1447,
       0,  1449,  1450,     0,     0,     0,  1453,  1454,     0,  1455,
       0,  1456,  1876,  1457,     0,  1458,  1459,  1460,  1566,     0,
       0,     0,     0,     0,     0,     0,     0,  1887,     0,     0,
       0,     0,   474,     0,  1480,     0,     0,     0,     0,     0,
       0,  1898,     0,     0,  1902,     0,     0,  1906,     0,  1491,
       0,  1909,     0,  1495,     0,   473,     0,   473,  1916,  1917,
    1918,  1919,  1920,     0,     0,     0,     0,     0,     0,     0,
       0,  1925,     0,     0,  1927,     0,     0,     0,     0,     0,
     474,     0,   474,     0,     0,   474,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,     0,
     474,     0,   474,     0,   474,  1824,   589,     0,     0,   474,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
    1959,     7,     8,     0,     0,     0,     0,   589,     0,     0,
       0,     0,     0,     0,     0,   473,     0,  1975,  1976,  1977,
    1978,  1979,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1558,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1570,     0,     0,     0,  1996,
       0,     0,     0,     0,   474,     0,  2006,  2007,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2015,  2016,  2017,
    2018,     0,     0,   702,    24,    25,   703,    27,    28,   704,
      30,   705,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,   474,   474,   474,   474,
       0,     0,     0,     0,  1415,     0,     0,     0,     0,     0,
     214,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,  1645,     0,     0,     0,
       0,     0,     0,     0,  1655,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1662,     0,     0,     0,     0,  1667,
       0,     0,     0,     0,   474,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   748,   448,   449,     0,
       0,     0,     0,   450,     0,  1687,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   748,   448,   449,
       0,     7,     8,  1074,   450,     0,     0,     0,  1415,   352,
       0,     0,     0,     0,     0,     0,     0,     0,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,     0,  1724,     0,   394,   395,   396,   397,
       0,   399,   400,   401,   402,   403,   404,     0,     0,   406,
       0,     0,     0,     0,     0,   407,   408,     0,     0,     0,
       0,   413,   414,   702,    24,    25,   703,    27,    28,   704,
      30,   705,    32,     0,    33,     7,     8,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1415,     0,     0,     0,     0,     0,     0,  1770,  1771,     0,
       0,     0,     0,     0,     0,     0,     0,   887,  1415,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1804,     0,   996,
       0,     0,     0,     0,     0,     0,     0,   702,    24,    25,
     703,    27,    28,   704,    30,   705,    32,     0,    33,  1138,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   563,     0,     0,   566,   567,   568,   569,
       0,     0,     0,  1097,     0,  1842,     0,     0,     0,     0,
       0,     0,     0,     0,   594,     0,    67,    68,    69,   112,
     113,   114,     0,     0,  1859,   115,   116,   117,     0,   474,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,     0,
       0,   159,   160,   161,     0,     0,   162,  1148,   163,   164,
     165,     0,     0,     0,     0,     0,   166,   167,     0,     0,
       0,     0,     0,     0,     0,  1415,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
       0,     0,     0,     0,   450,     0,     0,   700,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,     0,     0,     0,     0,   450,     0,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,     0,     0,     0,     0,   450,     0,     0,     0,
       0,     0,     0,     0,     0,   168,     0,   474,   474,     0,
       0,     0,   169,   170,   171,   172,   173,     0,     0,     0,
     174,   175,   176,   177,   178,   179,     0,   180,    90,     0,
       0,     0,     0,     0,     0,  1415,   474,     0,     0,     0,
     474,     0,   181,   182,     0,     0,     0,   183,     0,     0,
       0,     0,   184,     0,   185,     0,   186,   187,     0,   188,
       0,   189,     0,     0,     0,     0,     0,   112,   294,     0,
       0,     0,     0,   115,   116,   117,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   296,   297,   298,   299,   300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,   151,   152,
     153,     0,     0,     0,     0,   158,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,     0,
       0,     0,     0,     0,   166,     0,     0,     0,   301,     0,
       0,   302,     0,     0,   303,     0,   304,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   305,     0,
       0,     0,     0,   585,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   702,    24,
      25,   703,    27,    28,   704,    30,   705,    32,     0,    33,
       0,     0,  1756,     0,    38,    39,     0,    41,    42,    43,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
     169,     0,     0,     0,   173,  1345,     0,     0,   174,   175,
     176,   177,   178,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,   474,     0,    67,    68,    69,
     531,  1627,     0,     0,     0,   183,     0,     0,     0,     0,
     533,     0,     0,   112,   294,   187,   474,   261,   587,   115,
     116,   117,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   296,   297,   298,
     299,   300,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,   151,   152,   153,     0,  1154,     0,
       0,   158,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,   164,   165,     0,     0,     0,     0,     0,
     166,     0,     0,     0,   301,     0,     0,   302,     0,     0,
     303,     0,   304,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   305,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,     0,     0,
       0,   474,   450,   474,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,     0,     0,
       0,     0,   450,     0,     0,     0,   169,     0,     0,     0,
     173,     0,     0,     0,   174,   175,   176,   177,   178,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   472,     0,     0,
       0,   183,     0,     0,     0,     0,   307,     0,     0,     0,
       0,   187,     0,     0,   587,     0,     0,     0,     0,     0,
       0,   474,     0,     0,     0,     0,   112,   294,   114,  1192,
    1193,     0,   115,   116,   117,  1197,  1198,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     296,   297,   298,   299,   300,     0,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,     0,     0,   159,   160,
     161,     0,     0,   162,     0,   163,   164,   165,     0,     0,
       0,     0,     0,   166,   167,     0,     0,   301,     0,     0,
     302,     0,     0,   303,     0,   304,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,  1607,     0,  1608,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,   171,   172,   173,     0,     0,     0,   174,   175,   176,
     177,   178,   179,     0,   180,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1353,  1354,   181,
     306,     0,  1358,  1359,   183,     0,     0,     0,     0,   307,
       0,   112,   294,   114,   187,     0,   308,   115,   116,   117,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   296,   297,   298,   299,   300,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,     0,     0,   159,   160,   161,     0,     0,   162,     0,
     163,   164,   165,     0,     0,     0,     0,     0,   166,   167,
       0,     0,   301,     0,     0,   302,     0,     0,   303,     0,
     304,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   305,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,     0,     0,     0,     0,
     450,     0,     0,     0,     0,     0,     0,  1646,     0,  1647,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   170,   171,   172,   173,     0,
       0,     0,   174,   175,   176,   177,   178,   179,     0,   180,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   306,     0,     0,     0,   183,
       0,     0,     0,     0,   307,     0,   112,   342,   114,   187,
       0,  1666,   115,   116,   117,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,     0,     0,     0,     0,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,     0,     0,   159,   160,
     161,     0,     0,   162,     0,   163,   164,   165,     0,   112,
     342,   114,     0,   166,   167,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,     0,
       0,   159,   160,   161,     0,     0,   162,     0,   163,   164,
     165,     0,     0,     0,     0,     0,   166,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,   171,   172,   173,     0,     0,     0,   174,   175,   176,
     177,   178,   179,     0,   180,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,     0,     0,     0,   183,     0,     0,     0,     0,   307,
       0,     0,     0,     0,   187,     0,  1423,     0,     0,     0,
       0,     0,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,     0,     0,     0,     0,
     450,     0,   169,   170,   171,   172,   173,  1790,     0,  1791,
     174,   175,   176,   177,   178,   179,     0,   180,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   182,     0,     0,     0,   183,     0,     0,
       0,     0,   307,     0,   112,   342,   114,   187,     0,  1651,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     7,     8,     0,   159,   160,   161,     0,
       0,   162,     0,   163,   164,   165,     0,     0,     0,     0,
       0,   166,   167,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,     0,     0,
     994,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,   842,     0,   843,     0,   702,    24,    25,   703,    27,
      28,   704,    30,   705,    32,     0,    33,     0,     0,     0,
       0,    38,    39,     0,    41,    42,    43,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     172,   173,     0,     0,     0,   174,   175,   176,   177,   178,
     179,     0,   180,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,    69,   181,   182,     0,
       0,     0,   183,     0,     0,     0,     0,   307,     0,   112,
     294,   295,   187,     0,  1669,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   296,   297,   298,   299,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,   152,   153,     0,     0,  1280,     0,   158,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,   163,   164,
     165,     0,     0,     0,     0,     0,   166,     0,     0,     0,
     301,     0,     0,   302,     0,     0,   303,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     305,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     702,    24,    25,   703,    27,    28,   704,    30,   705,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,   169,     0,     0,     0,   173,     0,     0,     0,
     174,   175,   176,   177,   178,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,    69,   181,   306,     0,     0,     0,   183,     0,     0,
       0,     0,   307,     0,   112,   294,  1489,   187,     0,   308,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   296,   297,
     298,   299,   300,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   151,   152,   153,     0,     0,
    1862,     0,   158,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,   163,   164,   165,     0,     0,     0,     0,
       0,   166,     0,     0,     0,   301,     0,     0,   302,     0,
       0,   303,     0,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   702,    24,    25,   703,    27,
      28,   704,    30,   705,    32,     0,    33,     0,     0,     0,
       0,    38,    39,     0,    41,    42,    43,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,   169,     0,     0,
       0,   173,     0,     0,     0,   174,   175,   176,   177,   178,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,    69,   181,   306,     0,
       0,     0,   183,     0,     0,     0,     0,   307,     0,   112,
     294,     0,   187,     0,  1490,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   296,   297,   298,   299,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,   152,   153,     0,     0,  1942,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,   164,
     165,     0,     0,     0,     0,     0,   166,     0,     0,     0,
     301,     0,     0,   302,     0,     0,   303,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     305,     0,   332,   114,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,     0,     0,     0,     0,   450,     0,
     690,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     0,     0,     0,     0,   154,   155,   156,   157,     0,
       0,     0,   169,   159,   160,   161,   173,     0,   162,     0,
     174,   175,   176,   177,   178,     0,     0,     0,    90,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   306,     0,     0,     0,   183,     0,     0,
       0,     0,   307,     0,   112,   294,     0,   187,     0,   308,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   296,   297,
     298,   299,   300,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   151,   152,   153,     0,     0,
       0,     0,   158,     0,     0,   170,   171,   172,     0,     0,
       0,     0,     0,   163,   164,   165,     0,   179,     0,   180,
      90,   166,     0,     0,     0,   301,     0,     0,   302,     0,
       0,   303,     0,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   305,     0,   458,   114,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,   747,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     0,     0,     0,     0,
     154,   155,   156,   157,     0,     0,     0,   169,   159,   160,
     161,   173,     0,   162,     0,   174,   175,   176,   177,   178,
       0,     0,     0,    90,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   306,     0,
       0,     0,   183,     0,     0,     0,     0,   504,     0,   112,
     294,     0,   187,     0,   308,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   296,   297,   298,   299,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,   152,   153,     0,     0,     0,     0,   158,     0,     0,
     170,   171,   172,     0,     0,     0,     0,     0,   163,   164,
     165,     0,   179,     0,   180,    90,   166,     0,     0,     0,
     301,     0,     0,   302,   336,   114,   303,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     305,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
       0,     0,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,     0,     0,   154,   155,   156,
     157,     0,     0,     0,     0,   159,   160,   161,     0,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   169,     0,     0,     0,   173,     0,     0,     0,
     174,   175,   176,   177,   178,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   306,     0,     0,     0,   183,     0,     0,
       0,     0,   506,     0,   112,   294,     0,   187,     0,   308,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   170,   171,   172,
       0,     0,     0,     0,   150,   151,   152,   153,     0,   179,
       0,   180,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,   164,   165,     0,     0,     0,     0,
       0,   166,     0,     0,     0,   301,     0,     0,   302,   114,
       0,   303,     0,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,     0,     0,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,     0,
       0,   154,   155,   156,   157,     0,     0,     0,     0,   159,
     160,   161,     0,     0,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,     0,   169,     0,     0,
       0,   173,     0,     0,     0,   174,   175,   176,   177,   178,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   306,     0,
       0,     0,   183,     0,     0,     0,     0,   508,     0,   112,
     294,     0,   187,     0,   308,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   296,   297,   298,   299,   300,     0,     0,
       0,   170,   171,   172,     0,     0,     0,     0,     0,   150,
     151,   152,   153,   179,     0,   180,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,   164,
     165,     0,     0,     0,     0,     0,   166,     0,     0,     0,
     301,     0,     0,   302,     0,     0,   303,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     305,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,     0,     0,     0,     0,   450,     0,
       0,     0,     0,     0,     0,     0,     0,  1047,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,     0,     0,     0,   173,     0,     0,     0,
     174,   175,   176,   177,   178,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   472,     0,     0,     0,   183,     0,     0,
       0,     0,   307,     0,   112,   294,     0,   187,     0,   583,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   296,   297,
     298,   299,   300,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   151,   152,   153,     0,     0,
       0,     0,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,   164,   165,     0,     0,     0,     0,
       0,   166,     0,     0,     0,   301,     0,     0,   302,     0,
       0,   303,     0,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
       0,     0,  1100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
       0,   173,     0,     0,     0,   174,   175,   176,   177,   178,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   472,     0,
       0,     0,   183,     0,     0,     0,     0,   307,     0,   112,
     294,     0,   187,     0,   846,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   296,   297,   298,   299,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,   152,   153,     0,     0,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,   164,
     165,     0,     0,     0,     0,     0,   166,     0,     0,     0,
     301,     0,     0,   302,     0,     0,   303,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     305,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,     0,     0,     0,     0,   450,     0,
       0,     0,     0,     0,     0,     0,     0,  1129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,     0,     0,     0,   173,     0,     0,     0,
     174,   175,   176,   177,   178,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   472,     0,     0,     0,   183,     0,     0,
       0,     0,   307,     0,   112,   294,     0,   187,     0,   849,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   296,   297,
     298,   299,   300,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   151,   152,   153,     0,     0,
       0,     0,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,   164,   165,     0,     0,     0,     0,
       0,   166,     0,     0,     0,   301,     0,     0,   302,     0,
       0,   303,     0,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
       0,     0,  1168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
       0,   173,     0,     0,     0,   174,   175,   176,   177,   178,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   472,     0,
       0,     0,   183,     0,     0,     0,     0,   307,     0,   112,
     294,     0,   187,     0,   873,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   296,   297,   298,   299,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,   152,   153,     0,     0,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,   164,
     165,     0,     0,     0,     0,     0,   166,     0,     0,     0,
     301,     0,     0,   302,     0,     0,   303,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     305,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,     0,     0,     0,     0,   450,     0,
       0,     0,     0,     0,     0,     0,     0,  1284,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,     0,     0,     0,   173,     0,     0,     0,
     174,   175,   176,   177,   178,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   306,     0,     0,     0,   183,     0,     0,
       0,     0,   307,     0,   112,   294,     0,   187,     0,  1494,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   296,   297,
     298,   299,   300,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   151,   152,   153,     0,     0,
       0,     0,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,   164,   165,     0,     0,     0,     0,
       0,   166,     0,     0,     0,   301,     0,     0,   302,     0,
       0,   303,     0,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
       0,     0,  1605,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
       0,   173,     0,     0,     0,   174,   175,   176,   177,   178,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   531,  1627,     0,
       0,     0,   183,     0,     0,     0,     0,   533,     0,   112,
     342,     0,   187,     0,   261,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   150,
     151,   152,   153,   450,     0,     0,     0,   158,     0,     0,
       0,     0,  1624,     0,     0,     0,   112,   342,   163,   164,
     165,     0,   115,   116,   117,     0,   166,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   150,   151,   152,   153,
     450,     0,     0,     0,   158,     0,     0,     0,     0,  1697,
       0,     0,     0,     0,     0,   163,   164,   165,     0,     0,
       0,     0,     0,   166,     0,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,   169,   450,     0,     0,   173,   694,     0,     0,
     174,   175,   176,   177,   178,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   182,     0,     0,     0,   183,     0,     0,
       0,     0,   307,     0,     0,     0,     0,   187,     0,   511,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,     0,     0,     0,     0,   450,   169,
       0,     0,     0,   173,     0,     0,   616,   174,   175,   176,
     177,   178,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   531,
     532,     0,     0,     0,   183,     0,     0,     0,     0,   533,
       0,   112,   342,   114,   187,     0,   261,   115,   116,   117,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,     0,     0,   159,   160,   161,     0,     0,   162,     0,
     163,   164,   165,     0,     0,     0,     0,     0,   166,   167,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,     0,     0,     0,     0,   450,     0,
       0,     0,     0,     0,     0,     0,     0,  1698,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,     0,     0,     0,     0,   450,     0,     0,     0,
       0,     0,     0,     0,     0,  1699,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
       0,     0,     0,     0,   450,     0,     0,     0,     0,     0,
       0,     0,     0,  1700,   169,   170,   171,   172,   173,     0,
       0,     0,   174,   175,   176,   177,   178,   179,     0,   180,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   182,     0,     0,     0,   183,
     112,   294,     0,     0,   307,     0,   115,   116,   117,   187,
       0,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   296,   297,   298,   299,   300,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,   151,   152,   153,     0,     0,     0,     0,   158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
     164,   165,     0,     0,     0,     0,     0,   166,     0,     0,
       0,   301,     0,     0,   302,     0,     0,   303,     0,   304,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,     0,     0,  1701,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,     0,     0,     0,   173,     0,     0,
       0,   174,   175,   176,   177,   178,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   472,     0,     0,     0,   183,   112,
     342,     0,     0,   307,     0,   115,   116,   117,   187,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   150,
     151,   152,   153,   450,     0,     0,     0,   158,     0,     0,
       0,     0,  1733,     0,     0,     0,   112,   342,   163,   164,
     165,     0,   115,   116,   117,     0,   166,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   150,   151,   152,   153,
     450,     0,     0,     0,   158,     0,     0,     0,     0,  1806,
       0,     0,     0,     0,     0,   163,   164,   165,     0,     0,
       0,     0,     0,   166,     0,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,   169,   450,     0,     0,   173,   890,     0,     0,
     174,   175,   176,   177,   178,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   182,     0,     0,     0,   183,     0,     0,
       0,     0,   307,   421,     0,     0,     0,   187,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,     0,     0,     0,     0,   450,     0,     0,   169,
       0,     0,     0,   173,     0,  1817,     0,   174,   175,   176,
     177,   178,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,     0,     0,     0,   183,     0,     0,     0,     0,   307,
     112,   342,   423,     0,   187,     0,   115,   116,   117,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     150,   151,   152,   153,   450,     0,     0,     0,   158,     0,
       0,     0,     0,  1818,     0,     0,     0,   112,   342,   163,
     164,   165,     0,   115,   116,   117,     0,   166,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   150,   151,   152,
     153,   450,     0,     0,     0,   158,     0,     0,     0,     0,
    1850,     0,     0,     0,     0,     0,   163,   164,   165,     0,
       0,     0,     0,     0,   166,     0,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
       0,     0,     0,   169,   450,     0,     0,   173,   906,     0,
       0,   174,   175,   176,   177,   178,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,     0,     0,     0,   183,     0,
       0,     0,     0,   307,   622,     0,     0,     0,   187,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
     169,     0,     0,     0,   173,     0,  1853,     0,   174,   175,
     176,   177,   178,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   182,     0,     0,     0,   183,     0,     0,     0,     0,
     307,   112,   342,   624,  1290,   187,     0,   115,   116,   117,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   150,   151,   152,   153,   450,     0,     0,     0,   158,
       0,     0,     0,     0,  1856,     0,     0,     0,   112,   342,
     163,   164,   165,     0,   115,   116,   117,     0,   166,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   150,   151,
     152,   153,   450,     0,     0,     0,   158,     0,     0,     0,
       0,  1888,     0,     0,     0,     0,     0,   163,   164,   165,
       0,     0,     0,     0,     0,   166,     0,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,   169,   450,     0,     0,   173,   913,
       0,     0,   174,   175,   176,   177,   178,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   182,     0,     0,     0,   183,
       0,     0,     0,     0,   307,     0,    -4,     1,     0,   187,
      -4,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,     0,     0,     0,   173,     0,     0,     0,   174,
     175,   176,   177,   178,     0,     0,     0,    90,    -4,    -4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   182,     0,     0,     0,   183,     0,    -4,    -4,
      -4,   307,     0,     0,    -4,    -4,   187,    -4,     0,     0,
       0,    -4,    -4,     0,    -4,    -4,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,    -4,    -4,    -4,     0,     0,
       0,     0,     0,    -4,     6,     0,     0,     0,    -4,    -4,
      -4,    -4,     7,     8,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,     0,     0,    -4,    -4,    -4,
       0,     0,     9,    10,     0,     0,    -4,     0,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    12,    13,     0,     0,     0,    14,    15,
       0,    16,     0,     0,     0,    17,    18,     0,    19,    20,
       0,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,     0,    62,
      63,    64,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,    66,    67,    68,    69,     0,     0,    70,     0,
      71,     0,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
       0,    86,    87,    88,     0,     0,     0,     0,     0,     0,
      89,     0,    90,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,     0,     0,
    1895,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,     0,     0,  1934,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,     0,     0,  1936,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,     0,     0,  1938,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
       0,     0,  1958,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,     0,     0,
    1985,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,     0,     0,  2024,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,     0,     0,  2025,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,     0,     0,  2029,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
       0,     0,  2030,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,     0,     0,
    2031,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,     0,     0,  2032,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,     0,   796,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
       0,     0,     0,     0,   450,     0,     0,     0,     0,     0,
       0,     0,  1709,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,   842,     0,   843,     0,     0,  1373,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,   870,
       0,     0,     0,     0,   803,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
     737,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,   803,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,   804,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,   884,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,   926,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
     934,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,   935,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,   936,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,   951,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,  1082,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
    1083,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,  1084,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,  1115,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,  1124,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,  1125,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
    1127,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,  1234,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,  1282,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,  1283,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,  1344,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
    1504,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,  1505,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,  1506,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,  1507,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,  1508,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
    1509,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,  1510,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,  1561,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,  1562,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,  1569,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
    1736,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,  1737,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,  1738,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,  1739,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,  1740,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
    1762,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,  1763,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,  1767,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,  1868,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,  1869,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
    1870,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,  1871,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,  1872,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,  1881,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,  1884,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
    1930,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,  1947,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,  1948,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,  1949,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,  1950,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,     0,     0,     0,
    1951,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,  1997,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,  1998,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,  1999,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,     0,  2000,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,  1009,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,     0,     0,     0,     0,   450,     0,     0,     0,
    1108,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,  1109,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,     0,     0,
       0,     0,   450,     0,     0,     0,  1113,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,     0,     0,  1114,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,     0,     0,     0,     0,   450,     0,
       0,     0,  1117,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,     0,     0,  1141,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
       0,     0,     0,     0,   450,     0,     0,     0,  1170,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,     0,
       0,  1227,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,     0,     0,     0,     0,
     450,     0,     0,     0,  1232,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,     0,     0,  1499,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,     0,     0,     0,     0,   450,     0,     0,     0,
    1552,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,     0,     0,  1722,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,     0,     0,
       0,     0,   450,     0,   751,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,   752,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
       0,     0,     0,     0,   450,     0,   754,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,   756,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,     0,     0,     0,     0,   450,     0,   757,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,   760,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,     0,     0,     0,     0,   450,     0,
     761,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,   870,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,     0,     0,     0,     0,
     450,     0,   880,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,   881,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,     0,     0,
       0,     0,   450,     0,   882,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,   888,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
       0,     0,     0,     0,   450,     0,   889,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,   902,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,     0,     0,     0,     0,   450,     0,   912,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,  1008,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,     0,     0,     0,     0,   450,     0,
    1036,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,  1041,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,     0,     0,     0,     0,
     450,     0,  1046,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,  1049,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,     0,     0,
       0,     0,   450,     0,  1050,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,  1056,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
       0,     0,     0,     0,   450,     0,  1065,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,  1066,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,     0,     0,     0,     0,   450,     0,  1067,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,  1099,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,     0,     0,     0,     0,   450,     0,
    1101,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,  1102,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,     0,     0,     0,     0,
     450,     0,  1103,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,  1107,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,     0,     0,
       0,     0,   450,     0,  1116,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,     0,
       0,     0,     0,   450,     0,  1140,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
       0,     0,     0,     0,   450,     0,  1226,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,     0,     0,     0,     0,   450,     0,  1231,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,     0,     0,     0,     0,   450,     0,  1385,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,     0,     0,     0,     0,   450,     0,  1606,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,     0,     0,     0,     0,   450,     0,
    1623,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,     0,     0,     0,     0,   450,
       0,  1650,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,     0,     0,     0,     0,
     450,     0,  1880,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,     0,     0,     0,
       0,   450,     0,  1956
};

static const yytype_int16 yycheck[] =
{
       3,     7,   388,     6,   390,   525,   526,     4,     4,  1094,
       4,   254,     7,  1492,     3,     6,   269,     5,     4,   405,
       4,     6,     4,     6,     4,     6,     4,     6,   281,     6,
       4,     4,     4,     4,   107,     5,  1693,     5,     4,  1098,
     217,     5,   206,     5,     5,   222,     4,     6,     5,   226,
       5,     5,     5,   148,    57,     6,   233,     4,   196,   197,
       6,     6,    65,     4,     4,    13,     6,    70,   206,   164,
     165,   196,   197,   107,    87,   213,     6,    90,    81,     6,
     196,   197,    49,    50,   118,    52,   339,   212,   341,   214,
     196,   197,   126,   127,   128,     0,     6,   213,   132,   133,
     134,   135,   206,   206,   208,     6,   212,  1586,   214,   206,
     213,   215,   196,   197,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   212,   206,
     214,   206,   205,   208,     7,     6,   213,    84,   196,   197,
     215,    88,   206,     7,    84,   196,   197,     7,   196,   197,
     206,   136,   208,   100,    90,   136,   214,   136,   138,   139,
     140,   141,   213,   159,     6,   213,   148,   149,   206,   163,
     208,    81,   210,    83,     7,   148,   149,   215,  1835,  1836,
     214,   151,     7,   151,   187,   206,   182,   151,     7,   151,
     136,   111,   213,   203,   204,     6,   199,   200,   182,   188,
     206,     6,   208,   213,   207,   196,   197,     6,   182,  1688,
     193,   208,   215,     6,   217,   210,   193,   213,   215,   222,
     206,  1306,   208,   226,   210,   213,   229,  1706,   206,   215,
     233,   234,   235,   236,   214,   213,   239,   240,   241,   213,
       3,   213,   213,     6,   247,   248,   249,   213,   206,   213,
     253,   254,   213,     6,   213,   213,   213,   434,   213,   213,
     213,   206,   213,   516,   517,   206,   196,   197,   213,   196,
     197,   206,   275,   276,   277,   421,     8,   423,   213,   425,
     196,   197,   208,   536,   196,   197,   289,   290,   203,   204,
     257,   258,   203,   204,    57,   210,   212,   206,   265,   208,
     212,   210,   269,   306,   214,   308,   215,    70,     7,     4,
     183,   184,   185,   186,    87,   208,     7,    90,    81,   183,
     184,   185,   186,   183,   184,   185,   186,   210,   199,   200,
     203,   204,   215,   510,   511,   203,   204,   210,     7,   203,
     204,   209,   345,   206,   347,   348,   196,   197,   601,   207,
     183,   184,   185,   186,   212,     6,     7,   360,   183,   184,
     185,   186,   212,   616,   183,   184,   185,   186,   196,   197,
     203,   204,   203,   204,   206,   552,   553,   554,   203,   204,
     209,    94,   213,   212,   212,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,     7,   402,
     403,   404,   405,   406,  1883,   206,   583,   410,   411,   412,
     413,   414,   415,    90,   417,   207,   111,   112,   113,   114,
     212,   206,   196,   197,   187,   120,   196,   197,   123,   196,
     197,   434,   609,    90,   206,    92,   199,   200,   212,   203,
     204,   206,   212,   353,   207,   212,   198,   199,   200,   213,
     627,   209,   215,   205,   212,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   472,
     206,     6,   208,   205,   345,   206,   622,   208,   624,   215,
     196,   197,   214,   207,   183,   184,   185,   186,   212,   203,
     204,   254,   183,   184,   185,   186,   212,   207,   408,   213,
     203,   204,   212,    90,  1983,   425,   416,   510,   511,   207,
     213,   209,   203,   204,   183,   184,   185,   186,   389,   213,
     391,   392,   393,   394,   395,   396,   397,    90,   399,   400,
      90,   402,   403,   404,    92,   406,   525,   526,   206,   410,
     411,   412,   413,   414,   690,   206,   799,   208,   694,   552,
     553,   554,   196,   197,   215,   732,   523,   524,   206,   736,
     208,   564,   565,   213,   531,   568,    84,   215,   212,    87,
     196,   197,    90,   213,   183,   184,   185,   186,   203,   204,
     583,    87,   345,   107,   196,   197,   212,   590,   213,    90,
     500,   501,   502,   503,   118,    87,   196,   197,   196,   197,
     212,    87,   126,   127,   128,   212,   609,   214,   132,   133,
     134,   135,   212,   207,   212,   234,   235,   236,   212,   796,
     239,   240,   241,    90,   627,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   206,   399,   400,   206,   402,
     403,   404,   405,   406,     4,   196,   197,   410,   411,   412,
     413,   414,   415,     4,   417,   107,   275,   276,  1717,   207,
    1719,   212,  1721,   207,   212,   209,   118,   844,   212,   846,
     289,   290,   849,     4,   126,   127,   128,     4,   196,   197,
     132,   133,   134,   135,   206,   862,   689,   864,   206,   866,
     693,   868,   196,   197,   207,   213,   873,   568,   212,   212,
     214,   878,   196,   197,   198,   199,   200,    84,   212,  1794,
      87,   205,  1797,    90,   634,  1800,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   212,   732,
     214,   206,   205,   736,   196,   197,   739,    87,   107,   742,
      90,   744,    92,   206,   987,   748,   749,   111,   112,   118,
     212,   196,   197,   117,     6,     7,   902,   126,   127,   128,
     906,   938,   214,   132,   133,   134,   135,   212,     6,   772,
     690,   196,   197,     6,   694,   196,   197,   208,   196,   197,
     196,   197,   196,   197,   207,   695,   209,   212,   208,    84,
     213,   212,    87,   796,   212,    90,   212,    92,   212,   212,
     206,   214,   565,   206,  1863,   568,  1192,  1193,   212,   206,
     214,  1197,  1198,   990,   991,   992,   993,     8,   207,   212,
     209,   214,   206,   206,   213,  1910,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   802,   746,     7,   212,   205,
     214,   844,   809,   846,   206,   214,   849,   206,   815,   208,
     206,   210,    84,   206,   213,    87,   215,   206,    90,   862,
      92,   864,    90,   866,    92,   868,   111,   112,   739,   206,
     873,  1048,   117,   744,  1933,   878,  1935,  1962,  1937,   212,
    1965,   214,    87,  1968,  1943,    90,  1971,    92,   207,   212,
     209,   214,   206,   212,   897,   207,   213,   209,   901,   207,
     212,   209,   905,   207,   212,   209,   208,   207,   212,   209,
     913,  1057,   212,  1059,     8,  1061,   213,  1063,   207,   213,
     209,   841,     6,   212,  2009,   212,  2011,   214,  2013,   212,
    1989,   214,  1991,     6,  1993,   938,   213,   212,     6,   214,
     943,   212,   212,   214,   214,   948,   949,   950,   951,  1469,
    1470,   212,    90,   214,    92,   212,   206,   214,   961,   212,
     963,   214,   206,   212,  1207,   214,   206,  1353,  1354,   212,
     206,   214,  1358,  1359,   213,   212,   739,   214,   212,   742,
     214,   744,   902,     6,   987,   206,   906,   990,   991,   992,
     993,   206,   912,   913,   196,   197,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
       4,   212,  1015,   214,   205,   212,   212,   214,   214,   212,
     212,   214,   214,   214,   212,   212,   214,   214,   212,   206,
     214,  1034,  1035,   212,  1037,   214,  1039,  1040,   206,   206,
    1043,  1044,   913,   206,     6,  1048,   206,   212,   107,   214,
     212,     4,   214,     6,  1200,   212,   212,   214,   214,   118,
     212,   206,   214,  1030,   212,   206,   214,   126,   127,   128,
    1216,   213,   943,   132,   133,   134,   135,   213,   949,   950,
     951,   212,   212,   214,   214,   212,   206,   214,  1008,  1009,
     961,   213,   963,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   212,   212,   214,
     214,   205,   212,   207,   214,  1082,  1083,  1084,   213,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   212,   208,   214,  1313,   205,   213,   215,
    1143,  1144,  1145,   212,  1015,   214,   212,   212,   214,   214,
     913,   212,  1155,   214,   212,   214,   214,   212,   212,   214,
     214,  1404,     6,     6,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   213,   212,
     943,   214,   205,   212,   208,   214,   949,   950,   951,  1192,
    1193,   212,  1712,   214,  1197,  1198,  1116,  1117,   961,     6,
     963,   212,     6,   214,  1207,   212,   212,   214,   214,   212,
     212,   214,   214,   213,   213,   208,   208,  1363,  1221,     6,
    1140,  1141,   213,   151,   987,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    12,
      13,   215,  1245,   205,     6,     6,   213,     6,  1251,     6,
     213,     6,  1015,   213,  1257,     4,  1259,  1260,   208,   205,
       7,  1264,  1265,   210,  1267,   213,  1269,   107,  1271,   214,
    1273,  1274,  1275,   212,   212,     7,     6,     6,   118,     6,
    1200,     7,     7,  1669,  1461,  1462,   126,   127,   128,  1292,
       6,     6,   132,   133,   134,   135,     6,   207,     6,   213,
       7,     6,     4,     7,  1307,     6,     6,     6,  1311,    62,
    1313,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    62,    95,    62,    62,  1235,   148,   100,   101,   213,
     103,   104,   105,   209,   207,     6,   109,     6,  1305,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
    1353,  1354,   207,   207,   205,  1358,  1359,    44,    44,   212,
     212,    44,   212,   212,   212,   212,   212,   209,   207,  1372,
     143,   144,   145,   207,   214,  1378,   207,    44,     6,     4,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     4,     6,   213,     6,   205,     6,
       6,  1404,     7,   151,     7,     7,     7,  1410,   151,     7,
       7,   151,     7,     7,     4,     6,   207,  1420,   212,   207,
    1423,   207,   212,   212,   207,     6,   210,   212,   107,  1192,
    1193,   207,   214,   214,  1197,  1198,  1679,   209,   213,   118,
    1350,   214,   213,   213,  1207,  1365,   213,   126,   127,   128,
     107,     7,     7,   132,   133,   134,   135,     7,  1461,  1462,
     210,   118,   213,     6,    44,    44,  1433,    44,    44,   126,
     127,   128,     7,  1726,  1651,   132,   133,   134,   135,     6,
    1469,  1470,     6,     6,     6,     6,  1396,  1490,   208,  1492,
       6,  1494,   206,   206,   213,     6,   193,     7,     7,    92,
       7,  1372,     7,     7,  1471,     7,  1473,  1378,  1475,     6,
       4,  1514,     7,  1423,     7,     7,     7,     7,     7,  1522,
       4,   213,   206,  1490,     6,     6,  1493,  1494,     7,  1532,
       7,     7,  1709,     7,  1537,   214,     7,   213,     6,     6,
       6,    90,     7,   107,     6,     6,     4,     6,     4,  1420,
       4,   212,   214,  1730,   118,  1465,     6,   214,     6,     6,
    1563,     6,   126,   127,   128,     6,     4,     6,   132,   133,
     134,   135,   212,   107,   207,   212,   207,     7,   210,   206,
    1500,   210,     6,  1586,   118,     6,   207,   213,     6,   209,
    1353,  1354,   126,   127,   128,  1358,  1359,     6,   132,   133,
     134,   135,   100,     6,     6,   213,     6,     6,     6,  1372,
    1520,  1864,     5,   213,   213,  1378,     4,   213,     7,  1622,
       6,   213,   208,     6,  1627,   213,   213,  1537,  1538,  1539,
     213,   213,     6,     6,     6,   213,     4,   207,   213,   213,
     209,  1404,     6,     6,     6,     6,   147,   212,  1651,     6,
     214,     4,     6,   213,     6,     4,     6,  1420,     6,     6,
       6,     6,     6,  1666,     4,     7,  1669,     5,     7,     6,
       6,     6,     6,     6,     6,     6,  1679,     6,   151,     6,
     214,     6,     6,     6,     6,  1688,     6,     6,  1865,     6,
    1867,     6,  1695,  1696,   212,     6,     6,     6,   212,     6,
       6,   207,     6,  1706,     6,     6,  1709,     6,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,  1725,  1712,     6,     6,   205,  1730,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,     7,     6,  1654,     6,   205,     4,     5,  1716,
     210,  1718,     6,  1720,     5,     7,   107,     6,   213,     6,
     213,  1728,   213,     6,  1731,   214,     6,   118,  1945,   213,
      88,   213,     6,     6,   214,   126,   127,   128,   213,   213,
    1783,   132,   133,   134,   135,   213,   213,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     6,   214,     6,  1802,
      57,    58,    59,    60,     4,     5,   149,   213,    65,    66,
      67,     6,     6,    70,     6,  1782,   146,     6,     6,  1786,
       6,     6,  1825,     6,    81,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     6,
       6,     6,   207,   205,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     6,   213,     7,     6,    57,    58,    59,
      60,     6,  1865,   214,  1867,    65,    66,    67,     6,     6,
      70,     6,   213,  1840,     6,   107,     6,  1844,     6,     6,
    1883,    81,     6,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   213,     6,   213,
    1867,   205,   214,     6,     6,   213,  1669,     6,   107,     6,
     167,   168,   169,     6,  1824,     6,  1679,   214,   206,   118,
     213,   213,   179,   213,   181,   182,     6,   126,   127,   128,
     207,     6,     6,   132,   133,   134,   135,   213,     6,    89,
       6,     6,  1945,     6,   213,     6,   203,   204,     6,   213,
       6,   213,  1955,   210,     6,   213,   213,   213,     6,     6,
       6,     6,     6,     6,  1931,  1932,     6,   167,   168,   169,
       6,     6,     6,     6,  1230,  1828,  1694,  1244,     3,   179,
    1983,   181,   182,   468,     3,   498,  1708,    -1,  1400,    -1,
      -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,  2001,    -1,
    2003,    -1,    -1,    -1,   118,    -1,    -1,   207,    -1,   209,
      -1,  1921,   126,   127,   128,   214,    -1,    -1,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2033,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1825,    -1,    -1,    -1,   216,   217,   218,   219,
      -1,   221,   222,   223,   224,    -1,   226,   227,   228,    -1,
      -1,    -1,    -1,   233,  1955,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
     214,   251,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
     260,   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
    2001,    -1,  2003,    -1,    -1,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,   306,   307,   308,    -1,
      -1,    -1,  2033,    -1,    -1,    -1,    -1,    -1,   318,   319,
     320,    -1,   322,    -1,    -1,    -1,   326,   327,   328,    -1,
      -1,   331,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,  1955,    -1,    -1,    -1,    -1,    -1,    -1,   349,
     350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   363,   364,    -1,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,  2001,    -1,
    2003,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   401,    -1,    -1,    -1,    -1,    -1,   407,    -1,   409,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    2033,    95,    -1,    -1,    -1,    -1,   100,   101,    -1,   103,
     104,   105,    -1,   433,   434,   109,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,    -1,    -1,   453,   454,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   143,
     144,   145,   472,   205,    -1,    -1,    -1,    -1,   478,    -1,
      -1,    -1,    -1,   483,    -1,    -1,    -1,    -1,   488,   489,
      -1,    -1,    -1,    -1,   494,   495,   107,    -1,    -1,   499,
     500,   501,   502,   503,   504,    -1,   506,   118,   508,    -1,
     510,   511,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,   135,    -1,    -1,    -1,   528,   529,
     530,   531,   532,   533,    -1,    -1,    -1,   537,   538,   539,
     540,   541,    -1,    -1,    -1,   545,    -1,   547,   548,    -1,
      -1,    -1,   552,   553,   554,    -1,    -1,   557,   558,   559,
     560,   561,    -1,    -1,   564,   565,   566,   567,    -1,   569,
      -1,    -1,   572,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,   589,
     590,    -1,   592,   593,    -1,    -1,    -1,    -1,   594,    -1,
      -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,   609,
      -1,    -1,    -1,    -1,   614,   615,    -1,   617,   618,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   626,   627,    -1,    -1,
      -1,   631,    -1,    12,    13,    -1,    -1,    -1,    -1,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
      -1,   647,   648,   649,   650,   651,   652,   653,    -1,    -1,
      -1,   657,   658,   659,    -1,    -1,    -1,   663,   664,    -1,
     666,    -1,    -1,    -1,    -1,   671,   672,   673,    -1,   675,
      -1,    -1,    -1,    -1,    -1,    -1,   682,   683,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   696,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   700,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    -1,    -1,    -1,
      -1,   100,   101,    -1,   103,   104,   105,    -1,   728,   729,
     109,    -1,   732,   733,   734,    -1,   736,   737,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   745,    -1,    -1,   748,   749,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   762,    -1,   143,   144,   145,    -1,    -1,    -1,
      -1,   771,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   796,    -1,    -1,   247,
     248,   249,    -1,   803,   804,   253,    -1,    -1,    -1,   809,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,   822,    -1,    -1,   825,    -1,    -1,    -1,   277,
      -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   844,    -1,   846,    -1,    -1,   849,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   854,    -1,
      -1,    -1,   862,    -1,   864,    -1,   866,    -1,   868,    -1,
      -1,    -1,    -1,   873,    -1,    -1,    -1,    -1,   878,    -1,
      -1,    -1,    -1,    -1,   884,    -1,   886,   887,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,
     348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   926,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   934,   935,   936,    -1,   938,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   946,    12,    13,    -1,
     398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     960,    -1,    -1,    -1,    -1,   965,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   974,    -1,    -1,    -1,    -1,    -1,
     980,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     990,   991,   992,   993,    -1,    -1,   996,    -1,    -1,   995,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    12,    13,    -1,   205,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    -1,  1028,  1029,    -1,   100,   101,    -1,   103,   104,
     105,    -1,    -1,    -1,   109,    -1,    -1,    -1,  1048,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1058,    -1,
    1060,    -1,  1062,    -1,  1064,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,    -1,  1086,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    -1,
      -1,    -1,    -1,   100,   101,    -1,   103,   104,   105,    -1,
      -1,    -1,   109,    -1,    -1,  1115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1124,  1125,    -1,  1127,  1128,    -1,
    1130,  1131,  1132,    -1,    -1,    -1,    -1,    -1,  1138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   214,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1161,    -1,    -1,    -1,    -1,  1166,    -1,    -1,    -1,
      -1,    -1,    -1,  1169,    -1,    -1,    -1,    -1,    -1,  1175,
    1176,  1177,  1178,  1179,    -1,  1181,    -1,  1183,  1184,    -1,
    1186,  1187,    -1,     6,  1190,  1191,  1192,    -1,    -1,    -1,
      -1,  1197,    -1,    -1,    -1,    -1,    -1,    -1,  1208,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,  1219,
    1220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1234,  1235,     6,    -1,    -1,    -1,
      -1,   689,    -1,    -1,    -1,   693,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,    -1,   217,   205,    -1,    -1,    -1,   222,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,
      -1,  1281,  1282,  1283,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1292,    -1,  1294,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1305,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1313,    -1,    -1,    -1,    -1,  1318,    -1,
      -1,    -1,    -1,    -1,   772,    -1,    -1,  1323,    -1,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,  1339,  1344,  1345,  1346,   205,    -1,    -1,
      -1,    -1,   306,    -1,   308,    -1,    -1,  1353,    -1,    -1,
       6,    -1,  1358,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1373,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,     6,
      -1,    -1,   205,    -1,  1390,  1391,    -1,  1397,  1394,  1395,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1411,    -1,    -1,    -1,    -1,  1416,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,  1431,  1432,    -1,    -1,   205,    -1,    -1,  1438,  1439,
      -1,    -1,    -1,  1443,    -1,    -1,    -1,    -1,    -1,   897,
      -1,  1451,    -1,   901,    -1,    -1,    -1,   905,    -1,    -1,
      -1,  1461,  1462,  1463,    -1,  1465,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1477,    -1,    -1,
     434,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1490,    -1,    -1,    -1,  1494,    -1,    -1,  1497,    -1,    -1,
     948,    -1,    -1,    -1,  1504,  1505,  1506,  1507,  1508,  1509,
    1510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,    -1,
    1520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1525,
    1526,    -1,    -1,  1529,  1530,    -1,    -1,    -1,  1538,  1535,
    1536,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,   510,   511,    -1,   205,
      -1,  1561,  1562,    -1,    -1,     6,    -1,    -1,    -1,  1569,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,  1034,  1035,   205,  1037,
      -1,  1039,  1040,    -1,    -1,  1043,  1044,    -1,   552,   553,
     554,    -1,    -1,    -1,    -1,    -1,    -1,  1607,    -1,    -1,
     564,   565,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1625,    -1,  1627,    -1,   583,
      -1,    -1,    -1,    -1,    -1,    -1,   590,    -1,    -1,    -1,
      -1,    -1,  1638,  1639,    -1,    -1,  1646,    -1,  1648,    -1,
      -1,  1651,    -1,    -1,    -1,   609,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1666,    -1,    -1,    -1,
      -1,    -1,    -1,   627,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1684,    -1,    -1,    -1,    -1,  1689,
      -1,    -1,    -1,    -1,    -1,  1143,  1144,  1145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1155,    -1,  1709,
      -1,    -1,    -1,    -1,    -1,    -1,  1716,    -1,  1718,    -1,
    1720,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1730,    -1,    -1,    -1,    -1,    -1,  1736,  1737,  1738,  1739,
    1740,  1741,    -1,    -1,    -1,    -1,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,  1762,  1763,   205,    -1,    -1,  1767,    -1,    -1,
      -1,    -1,    -1,  1221,    -1,    -1,    -1,    -1,   732,  1779,
      -1,    -1,   736,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1790,    -1,    -1,    -1,   748,   749,    -1,  1245,    -1,    -1,
      -1,    -1,    -1,  1251,    -1,    -1,    -1,    -1,    -1,  1257,
      -1,  1259,  1260,    -1,    -1,    -1,  1264,  1265,    -1,  1267,
      -1,  1269,  1822,  1271,    -1,  1273,  1274,  1275,  1828,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1837,    -1,    -1,
      -1,    -1,   796,    -1,  1292,    -1,    -1,    -1,    -1,    -1,
      -1,  1851,    -1,    -1,  1854,    -1,    -1,  1857,    -1,  1307,
      -1,  1861,    -1,  1311,    -1,  1865,    -1,  1867,  1868,  1869,
    1870,  1871,  1872,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1881,    -1,    -1,  1884,    -1,    -1,    -1,    -1,    -1,
     844,    -1,   846,    -1,    -1,   849,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   862,    -1,
     864,    -1,   866,    -1,   868,     7,     8,    -1,    -1,   873,
      -1,    -1,    -1,    -1,   878,    -1,    -1,    -1,    -1,    -1,
    1930,    12,    13,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1945,    -1,  1947,  1948,  1949,
    1950,  1951,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1423,    -1,    -1,    -1,  1975,
      -1,    -1,    -1,    -1,   938,    -1,  1986,  1987,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1997,  1998,  1999,
    2000,    -1,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,   100,
     101,    -1,   103,   104,   105,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   990,   991,   992,   993,
      -1,    -1,    -1,    -1,  1492,    -1,    -1,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,    -1,  1514,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1522,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1532,    -1,    -1,    -1,    -1,  1537,
      -1,    -1,    -1,    -1,  1048,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,  1563,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    12,    13,   214,   205,    -1,    -1,    -1,  1586,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,  1622,    -1,   147,   148,   149,   150,
      -1,   152,   153,   154,   155,   156,   157,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,   166,   167,    -1,    -1,    -1,
      -1,   172,   173,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    12,    13,    -1,    -1,   100,
     101,    -1,   103,   104,   105,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1688,    -1,    -1,    -1,    -1,    -1,    -1,  1695,  1696,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,  1706,    -1,
      -1,    -1,   143,   144,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1725,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,     8,
      -1,    -1,    -1,   100,   101,    -1,   103,   104,   105,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   294,    -1,    -1,   297,   298,   299,   300,
      -1,    -1,    -1,   214,    -1,  1783,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   315,    -1,   143,   144,   145,     3,
       4,     5,    -1,    -1,  1802,     9,    10,    11,    -1,  1313,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    65,    66,    67,    -1,    -1,    70,   214,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1883,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,    -1,    -1,   205,    -1,    -1,   428,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,    -1,    -1,    -1,   205,    -1,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,  1461,  1462,    -1,
      -1,    -1,   166,   167,   168,   169,   170,    -1,    -1,    -1,
     174,   175,   176,   177,   178,   179,    -1,   181,   182,    -1,
      -1,    -1,    -1,    -1,    -1,  1983,  1490,    -1,    -1,    -1,
    1494,    -1,   196,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,   206,    -1,   208,    -1,   210,   211,    -1,   213,
      -1,   215,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,  1627,    -1,   111,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,   120,    -1,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1651,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      -1,    -1,  1666,    -1,   100,   101,    -1,   103,   104,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,   170,     8,    -1,    -1,   174,   175,
     176,   177,   178,    -1,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1709,    -1,   143,   144,   145,
     196,   197,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
     206,    -1,    -1,     3,     4,   211,  1730,   213,   214,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,   214,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
     120,    -1,    -1,   123,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,    -1,
      -1,  1865,   205,  1867,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,    -1,
      -1,    -1,   205,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,    -1,    -1,    -1,   174,   175,   176,   177,   178,    -1,
      -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,   197,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,
      -1,  1945,    -1,    -1,    -1,    -1,     3,     4,     5,   970,
     971,    -1,     9,    10,    11,   976,   977,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    81,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,   120,    -1,    -1,   123,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,   212,    -1,   214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     167,   168,   169,   170,    -1,    -1,    -1,   174,   175,   176,
     177,   178,   179,    -1,   181,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1158,  1159,   196,
     197,    -1,  1163,  1164,   201,    -1,    -1,    -1,    -1,   206,
      -1,     3,     4,     5,   211,    -1,   213,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,   120,    -1,
      -1,   123,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,
     205,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,   214,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,    -1,
      -1,    -1,   174,   175,   176,   177,   178,   179,    -1,   181,
     182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   197,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,   206,    -1,     3,     4,     5,   211,
      -1,   213,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,     3,
       4,     5,    -1,    80,    81,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     167,   168,   169,   170,    -1,    -1,    -1,   174,   175,   176,
     177,   178,   179,    -1,   181,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
     197,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,   206,
      -1,    -1,    -1,    -1,   211,    -1,   213,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,
     205,    -1,   166,   167,   168,   169,   170,   212,    -1,   214,
     174,   175,   176,   177,   178,   179,    -1,   181,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,   206,    -1,     3,     4,     5,   211,    -1,   213,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    12,    13,    -1,    65,    66,    67,    -1,
      -1,    70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    81,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,   207,    -1,   209,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    -1,    -1,    -1,
      -1,   100,   101,    -1,   103,   104,   105,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,
     169,   170,    -1,    -1,    -1,   174,   175,   176,   177,   178,
     179,    -1,   181,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   196,   197,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,   206,    -1,     3,
       4,     5,   211,    -1,   213,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,   214,    -1,    61,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,   120,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    -1,    -1,    -1,    -1,   100,   101,    -1,   103,
     104,   105,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   175,   176,   177,   178,    -1,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,   196,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,   206,    -1,     3,     4,     5,   211,    -1,   213,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
     214,    -1,    61,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    -1,    -1,    -1,
      -1,   100,   101,    -1,   103,   104,   105,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,
      -1,   170,    -1,    -1,    -1,   174,   175,   176,   177,   178,
      -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   196,   197,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,   206,    -1,     3,
       4,    -1,   211,    -1,   213,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,   214,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,     4,     5,    -1,    -1,    -1,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,   120,    -1,    -1,   123,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,
     207,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      -1,    -1,   166,    65,    66,    67,   170,    -1,    70,    -1,
     174,   175,   176,   177,   178,    -1,    -1,    -1,   182,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,   206,    -1,     3,     4,    -1,   211,    -1,   213,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,   167,   168,   169,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,   179,    -1,   181,
     182,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,     4,     5,    -1,
      -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,   120,    -1,    -1,   123,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,   207,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    -1,    -1,    -1,   166,    65,    66,
      67,   170,    -1,    70,    -1,   174,   175,   176,   177,   178,
      -1,    -1,    -1,   182,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,   206,    -1,     3,
       4,    -1,   211,    -1,   213,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
     167,   168,   169,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,   179,    -1,   181,   182,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,     4,     5,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,   120,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   175,   176,   177,   178,    -1,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,   206,    -1,     3,     4,    -1,   211,    -1,   213,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,   167,   168,   169,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,   179,
      -1,   181,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,     5,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,   120,    -1,    -1,   123,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,   166,    -1,    -1,
      -1,   170,    -1,    -1,    -1,   174,   175,   176,   177,   178,
      -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,   206,    -1,     3,
       4,    -1,   211,    -1,   213,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,   179,    -1,   181,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,   120,    -1,    -1,   123,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   175,   176,   177,   178,    -1,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,   206,    -1,     3,     4,    -1,   211,    -1,   213,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,   120,    -1,    -1,   123,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,
      -1,   170,    -1,    -1,    -1,   174,   175,   176,   177,   178,
      -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,   206,    -1,     3,
       4,    -1,   211,    -1,   213,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,   120,    -1,    -1,   123,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   175,   176,   177,   178,    -1,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,   206,    -1,     3,     4,    -1,   211,    -1,   213,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,   120,    -1,    -1,   123,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,
      -1,   170,    -1,    -1,    -1,   174,   175,   176,   177,   178,
      -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,   206,    -1,     3,
       4,    -1,   211,    -1,   213,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,   120,    -1,    -1,   123,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   175,   176,   177,   178,    -1,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,   206,    -1,     3,     4,    -1,   211,    -1,   213,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,   120,    -1,    -1,   123,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,
      -1,   170,    -1,    -1,    -1,   174,   175,   176,   177,   178,
      -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,   206,    -1,     3,
       4,    -1,   211,    -1,   213,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    53,
      54,    55,    56,   205,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,   214,    -1,    -1,    -1,     3,     4,    72,    73,
      74,    -1,     9,    10,    11,    -1,    80,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    53,    54,    55,    56,
     205,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   214,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,   166,   205,    -1,    -1,   170,   209,    -1,    -1,
     174,   175,   176,   177,   178,    -1,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,   206,    -1,    -1,    -1,    -1,   211,    -1,   213,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,   166,
      -1,    -1,    -1,   170,    -1,    -1,   213,   174,   175,   176,
     177,   178,    -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
     197,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,   206,
      -1,     3,     4,     5,   211,    -1,   213,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,   166,   167,   168,   169,   170,    -1,
      -1,    -1,   174,   175,   176,   177,   178,   179,    -1,   181,
     182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   197,    -1,    -1,    -1,   201,
       3,     4,    -1,    -1,   206,    -1,     9,    10,    11,   211,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,   120,    -1,    -1,
     123,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,   170,    -1,    -1,
      -1,   174,   175,   176,   177,   178,    -1,    -1,    -1,   182,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,   197,    -1,    -1,    -1,   201,     3,
       4,    -1,    -1,   206,    -1,     9,    10,    11,   211,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    53,
      54,    55,    56,   205,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,   214,    -1,    -1,    -1,     3,     4,    72,    73,
      74,    -1,     9,    10,    11,    -1,    80,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    53,    54,    55,    56,
     205,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   214,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,   166,   205,    -1,    -1,   170,   209,    -1,    -1,
     174,   175,   176,   177,   178,    -1,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,   206,   207,    -1,    -1,    -1,   211,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,   166,
      -1,    -1,    -1,   170,    -1,   214,    -1,   174,   175,   176,
     177,   178,    -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
     197,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,   206,
       3,     4,   209,    -1,   211,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      53,    54,    55,    56,   205,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,   214,    -1,    -1,    -1,     3,     4,    72,
      73,    74,    -1,     9,    10,    11,    -1,    80,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    53,    54,    55,
      56,   205,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
     214,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,    -1,   166,   205,    -1,    -1,   170,   209,    -1,
      -1,   174,   175,   176,   177,   178,    -1,    -1,    -1,   182,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,   197,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,   206,   207,    -1,    -1,    -1,   211,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
     166,    -1,    -1,    -1,   170,    -1,   214,    -1,   174,   175,
     176,   177,   178,    -1,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   197,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
     206,     3,     4,   209,     6,   211,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    53,    54,    55,    56,   205,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,     3,     4,
      72,    73,    74,    -1,     9,    10,    11,    -1,    80,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    53,    54,
      55,    56,   205,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,   214,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,   166,   205,    -1,    -1,   170,   209,
      -1,    -1,   174,   175,   176,   177,   178,    -1,    -1,    -1,
     182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   197,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,   206,    -1,     0,     1,    -1,   211,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,
     175,   176,   177,   178,    -1,    -1,    -1,   182,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,   197,    -1,    -1,    -1,   201,    -1,    62,    63,
      64,   206,    -1,    -1,    68,    69,   211,    71,    -1,    -1,
      -1,    75,    76,    -1,    78,    79,    -1,    -1,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,   129,   130,   131,    -1,    -1,
      -1,    -1,    -1,   137,     4,    -1,    -1,    -1,   142,   143,
     144,   145,    12,    13,   148,    -1,   150,    -1,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,
      -1,    -1,    42,    43,    -1,    -1,   180,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    -1,    -1,    -1,    68,    69,
      -1,    71,    -1,    -1,    -1,    75,    76,    -1,    78,    79,
      -1,    -1,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,   129,
     130,   131,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,   142,   143,   144,   145,    -1,    -1,   148,    -1,
     150,    -1,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
      -1,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
     180,    -1,   182,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   214,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   214,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,   207,    -1,   209,    -1,    -1,   212,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,   207,
      -1,    -1,    -1,    -1,   212,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,   212,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,   212,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,   212,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,   212,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,   212,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,   212,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,   212,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,   212,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,   212,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,   212,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,   212,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,   209,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,
     209,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,   209,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,    -1,
      -1,    -1,   205,    -1,    -1,    -1,   209,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,   209,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,
      -1,    -1,   209,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,   209,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,   209,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,   209,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,
     205,    -1,    -1,    -1,   209,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,   209,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,
     209,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,   209,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,    -1,
      -1,    -1,   205,    -1,   207,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,   207,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,    -1,    -1,   205,    -1,   207,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,   207,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,    -1,    -1,    -1,   205,    -1,   207,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,   207,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,
     207,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,   207,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,
     205,    -1,   207,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,   207,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,    -1,
      -1,    -1,   205,    -1,   207,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,   207,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,    -1,    -1,   205,    -1,   207,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,   207,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,    -1,    -1,    -1,   205,    -1,   207,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,   207,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,
     207,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,   207,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,
     205,    -1,   207,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,   207,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,    -1,
      -1,    -1,   205,    -1,   207,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,   207,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,    -1,    -1,   205,    -1,   207,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,   207,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,    -1,    -1,    -1,   205,    -1,   207,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,   207,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,
     207,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,   207,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,
     205,    -1,   207,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,   207,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,    -1,
      -1,    -1,   205,    -1,   207,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,    -1,   207,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,    -1,    -1,   205,    -1,   207,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,    -1,   207,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,    -1,    -1,    -1,   205,    -1,   207,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,   207,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,
     207,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
      -1,   207,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,
     205,    -1,   207,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,    -1,   207
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   217,   218,     6,     0,     4,    12,    13,    42,
      43,    62,    63,    64,    68,    69,    71,    75,    76,    78,
      79,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   118,   119,   120,   121,   122,   123,
     124,   125,   129,   130,   131,   137,   142,   143,   144,   145,
     148,   150,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   171,   172,   173,   180,
     182,   219,   221,   222,   242,   261,   262,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   294,   295,   296,   297,
     315,   316,     3,     4,     5,     9,    10,    11,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    65,
      66,    67,    70,    72,    73,    74,    80,    81,   159,   166,
     167,   168,   169,   170,   174,   175,   176,   177,   178,   179,
     181,   196,   197,   201,   206,   208,   210,   211,   213,   215,
     240,   298,   299,   311,   312,   315,   316,    13,    90,   206,
     206,     6,   213,     6,     6,     6,     6,   206,     6,     6,
     208,   208,   206,   208,   240,   240,   206,   213,   206,   206,
       4,   206,   213,   206,   206,     4,   213,   206,   206,    94,
      90,    90,     6,   213,    84,    87,    90,    90,    90,    87,
      90,    92,    92,    84,    87,    90,    92,    87,    90,    92,
      87,    90,   206,    87,   148,   164,   165,   213,   196,   197,
     206,   213,   301,   302,   301,   213,    84,    87,    90,   213,
     301,     4,    84,    88,   100,    90,    92,    90,    87,     4,
     159,   213,   315,   316,     4,     6,    84,    87,    90,    87,
      90,     4,     4,     4,     4,     5,    37,    38,    39,    40,
      41,    84,    87,    90,    92,   104,   197,   206,   213,   262,
     273,   298,   304,   305,   306,   315,   316,     4,   206,   206,
     206,     4,   213,   308,   316,     4,   206,   206,   206,     6,
       6,   208,     4,   312,   316,   206,     4,   312,     5,   213,
       5,   213,     4,   298,   315,   208,     6,   206,   213,   206,
     208,   215,   240,     7,   183,   184,   185,   186,   203,   204,
     238,   239,     4,   206,   208,   210,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   206,   206,   206,   240,   240,   240,   240,   206,   240,
     240,   240,   240,   240,   240,   206,   240,   240,   240,     7,
     206,   206,   206,   240,   240,   206,   206,   208,   298,   298,
     298,   207,   298,   209,   298,     4,   148,   149,   316,     4,
     262,   263,   264,   213,   213,     6,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     205,   213,     6,   206,   208,   239,     6,   298,     4,   311,
     312,   315,   316,   311,   298,   311,   314,   244,   249,   312,
     316,   298,   197,   298,   306,   307,   298,   298,   206,   298,
     307,   298,   298,   206,   307,   298,   298,   304,   206,   213,
     307,   305,   305,   305,   206,   206,   305,   305,   305,   206,
     206,   206,   206,   206,   206,   304,   206,   304,   206,   304,
     213,   213,   298,     4,   304,   308,   213,   213,   301,   301,
     301,   298,   298,   196,   197,   213,   213,   301,   213,   213,
     213,   196,   197,   206,   264,   301,   213,   206,   213,   206,
     206,   206,   305,   305,   304,   206,     4,   208,   208,   264,
       6,     6,   213,   213,   213,   305,   305,   208,   208,   208,
     206,   208,   210,   240,   206,   208,   240,   240,   240,   240,
       5,   151,   213,     5,   151,     5,   151,     5,   151,    84,
      87,    90,    92,   213,   298,   306,   298,   214,   307,     8,
     198,     6,   206,   208,   240,     6,   298,   298,   298,   210,
     298,   213,   151,   298,   298,   298,   298,     6,     6,   213,
       6,   264,     6,   264,   206,   208,   213,   206,   208,   311,
     304,   304,   207,   298,   209,   298,   213,   213,   312,   304,
       6,   208,   298,   298,     4,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   314,   311,   314,
     311,   311,   311,   311,   311,   311,   311,   304,   311,   311,
     298,   311,   311,   311,   314,   311,   298,   312,   298,   311,
     311,   311,   311,   311,   316,   312,   316,     7,   186,   238,
     207,     7,   186,   238,   209,     7,   238,   239,   210,     7,
     240,   214,    84,    87,    90,    92,   261,   298,   307,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   223,   298,   298,     6,   206,   208,
     210,   207,   212,   206,   208,   207,   212,   212,   207,   212,
     209,   212,   243,   209,   243,   212,   212,   207,   198,   212,
     214,   207,   207,   298,   207,   214,   207,   207,   298,   214,
     207,   207,     7,   298,   298,   214,     6,     6,     6,   298,
     298,     7,     7,   291,   291,   298,   255,   298,   312,   256,
     298,   312,   257,   298,   312,   258,   298,   312,   298,     6,
     298,     6,   298,     6,   307,   307,   213,   207,     6,   213,
     264,   264,   212,   212,   212,   301,   301,   263,   263,   212,
     298,   298,   298,   298,   277,   212,   264,   298,   298,   298,
     298,   298,     7,   292,     6,     7,   298,     6,   298,   298,
     214,   307,   307,   307,     6,     6,   298,   298,   298,   298,
     298,     4,   207,   209,   213,   241,   213,   298,   306,   213,
     306,   316,   298,   298,   311,   298,    62,   298,    62,    62,
      62,     5,   213,     5,   213,     5,   213,     5,   213,   307,
     207,   214,   298,   213,   298,   306,   298,   298,   213,   241,
     207,   207,   207,   148,   212,   264,   213,     8,   207,   207,
     209,   307,   214,   214,   264,   209,   207,   212,   214,     7,
     186,   238,   207,     7,   186,   238,   209,   298,   307,     6,
       6,   298,   207,   209,   239,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   212,   241,   241,   241,
     241,   241,   241,   241,   212,   212,   212,   241,   212,   241,
     241,   207,   207,   212,   241,   241,   212,   241,   212,   212,
     212,   212,   241,   241,   241,   207,   241,   300,   313,     6,
     212,   212,   207,   212,   241,   212,   241,   207,   207,   209,
      44,    44,   304,     7,   238,   239,    44,    44,   304,   210,
     238,   239,   312,   298,     6,     4,     4,   213,   309,   241,
     213,   213,   213,   213,   214,   214,     8,     4,   138,   139,
     140,   141,   214,   226,   230,   233,   235,   236,   207,   209,
     298,   298,     4,     6,   193,   220,   307,   298,   298,     6,
     307,   298,     6,   311,     6,   316,     6,   311,   298,   312,
       7,   298,   306,   151,     7,     7,   207,     7,   151,     7,
       7,   207,   151,     7,     7,   298,   207,   214,   213,   207,
     207,   298,   304,     4,   290,     6,   207,   207,   212,   207,
     212,   207,   212,   207,   212,   207,   207,   207,   214,   214,
     307,   210,   264,   214,   214,   301,   298,   298,   214,   214,
     298,   301,   212,   212,   212,   107,   118,   126,   127,   128,
     132,   133,   134,   135,   287,   288,   301,   214,   274,   207,
     214,   207,   207,   207,   298,     6,   298,   207,   209,   209,
     214,   214,   214,   209,   209,   212,   207,   209,   307,   307,
     207,   307,   209,   209,   212,   212,   241,   212,   213,   214,
     213,   213,   213,   307,   307,   307,   307,   214,     8,   307,
     207,   209,   307,     7,     7,     7,   210,   298,   214,   298,
     298,     7,   210,   214,   214,   213,   304,     6,    44,    44,
     304,   238,   239,    44,    44,   304,   238,   239,   214,   214,
     209,   239,   210,   239,   311,   298,   298,   298,   298,   307,
     311,   298,   304,   311,   311,   311,   251,   253,   298,   311,
     311,   298,   240,   240,     6,   298,     6,   240,   240,     6,
       4,   148,   149,   298,     6,     6,     6,     7,   208,   308,
     310,     6,   307,   307,   307,   307,   241,   298,   227,   206,
     206,   213,   237,     6,   239,   239,   207,   209,   193,   311,
     207,   207,   209,   207,   212,     7,   206,   208,   241,   241,
     301,    90,    92,   304,   304,     7,   304,    90,    92,   304,
     304,     7,    92,   304,   304,     6,     7,     7,   307,     7,
       7,   107,   289,     6,     7,   238,   298,   238,   298,   238,
     298,   238,   298,     7,     7,     7,     7,     7,   214,     4,
     214,   212,   212,   212,   214,   214,   301,   301,   301,     4,
       6,   298,   213,     6,   206,     6,   136,     6,   136,     6,
     136,     6,   136,   214,   288,   212,   287,     7,     6,     7,
       7,     7,     6,   213,     6,     6,     6,    90,     7,     6,
       6,   298,   210,   214,   214,   214,   298,   298,   298,   298,
     298,   298,   298,   214,   214,   214,   214,   298,   214,   214,
     304,   304,   304,     4,   212,     8,     8,   207,     4,     4,
     212,   304,   214,   240,   240,     6,   298,     6,   240,   240,
       6,   298,     6,   241,     6,     4,     6,   241,   241,   241,
     241,   241,   212,   212,   241,   207,   241,   241,   212,   212,
     241,   252,   212,   241,   254,   207,   207,   241,   241,   241,
     314,   314,     6,   241,   314,   314,     7,   238,   239,   210,
       7,     6,   308,   298,   212,   214,   214,   214,   214,   214,
     238,   206,   298,   298,   303,   304,   213,   210,     6,     6,
     220,     6,   298,   213,   298,   312,   207,   209,     6,     6,
       6,   213,   213,   100,   260,   260,   304,     6,   213,   213,
       6,     6,   304,   213,     6,     6,     5,   304,   214,   304,
     304,     4,     6,   304,   304,   304,   304,   304,   304,   304,
     304,   213,   213,     7,     6,     7,   298,   298,   298,   213,
     213,   212,   214,   212,   214,   212,   214,   208,     6,   298,
     304,   298,     6,     6,     6,     6,   298,   301,   214,     5,
     213,   304,   213,   213,   213,   304,   307,   213,   298,   209,
       4,   241,   207,   209,   212,   212,   212,   212,   212,   212,
     212,   241,     6,     6,   147,   298,   298,   298,     6,     6,
       7,   312,   212,     6,   241,   314,   314,     6,   241,   314,
     314,     6,   238,   239,   311,   298,   311,     4,     4,   163,
       6,   241,   241,     6,   241,   241,   312,   298,     6,     4,
     309,     6,   209,   308,     6,     6,     6,     6,   304,   224,
     298,   212,   212,   212,   214,   225,   298,     4,   311,   212,
     304,   312,     7,     7,   298,   298,   301,     6,     6,     6,
     298,   298,     6,   298,     5,     6,   213,     6,   151,   259,
     298,     6,     6,     6,     6,     6,     6,     4,     6,     6,
     307,   307,   298,   298,   312,   214,   207,   212,   214,   263,
     263,   301,     6,   278,   301,     6,   279,   301,     6,   280,
     298,   214,   212,   207,   214,   212,     6,   197,   301,     6,
     303,   301,   301,     6,   214,   298,     6,     6,   298,   298,
     298,   298,   298,   298,   298,   304,   212,   214,     8,   214,
     207,   213,   298,   312,   212,   304,     6,   241,   241,     6,
     241,   241,   304,   207,   241,   241,   213,   304,   312,   213,
     298,   312,   312,     6,     6,     6,     6,     6,     6,     7,
       6,   210,     6,   207,   212,   298,   298,   304,   213,   212,
     214,     6,   298,   245,   248,   213,   213,   214,   214,   214,
     214,   214,     5,   303,    88,     6,   213,   214,   214,   213,
       6,     6,   213,   298,   214,   214,   212,   213,   212,   213,
     212,   213,   209,     6,   304,     7,   213,   298,   212,   214,
     212,   212,     6,   214,   241,   241,   212,   212,   212,   212,
     212,   146,   298,   298,   307,     6,     6,   312,   214,     6,
       6,     6,     6,     6,   250,   298,   306,   314,   308,   149,
     228,   298,   212,   212,   303,   298,     6,   212,   251,   253,
     304,   304,     6,     6,     6,     6,     6,     6,   214,   213,
     303,   111,   112,   117,   293,   111,   112,   293,   307,   263,
     212,   214,   298,   301,   287,   298,   301,   287,   298,   301,
     287,     6,   212,   214,   304,   264,   214,   301,     6,   307,
     301,   298,   298,   298,   298,   298,   298,   214,   214,   214,
     207,     6,   212,   214,     7,     7,   214,     6,   213,   298,
     298,   214,   298,   214,   214,   247,   246,   213,   298,   214,
     213,   301,   304,     6,   213,   301,     6,   214,   214,   298,
     214,   212,   214,   214,   212,   214,   214,   212,   214,   304,
       6,   107,   214,   275,   213,   212,   214,   212,   212,   212,
     212,   212,   212,     6,     6,     6,   298,   312,   316,   225,
     207,   212,     6,   213,   212,   251,   251,   298,   214,     6,
     301,     6,   301,     6,     6,   214,     6,   281,   298,     6,
       6,   282,   298,     6,     6,   283,   298,     6,   214,   298,
     287,   264,   307,     6,   301,   307,   298,   298,   298,   298,
     298,     7,   206,   214,   231,   298,   303,   298,   214,   214,
     212,   212,   212,   213,   214,   213,   214,   213,   214,     6,
       6,   214,   214,   276,   214,   212,   214,   212,   212,   212,
     212,   212,   312,   207,     6,   213,   207,   214,   214,   298,
     301,   301,   287,     6,   284,   287,     6,   285,   287,     6,
     286,   287,     6,   307,     6,   298,   298,   298,   298,   298,
     229,   311,   234,   213,     6,   214,   212,   212,   214,   213,
     214,   213,   214,   213,   214,   214,   241,   212,   212,   212,
     212,   212,   214,   213,   303,     6,   298,   298,     6,   287,
       6,   287,     6,   287,     6,   298,   298,   298,   298,   311,
       6,   232,   311,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   212,   214,     6,     6,     6,     6,     6,
       6,   311,     6
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
#line 205 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 216 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 217 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 218 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 219 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 220 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 221 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 222 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 223 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 224 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 225 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 16:
#line 226 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 227 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 228 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 229 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 230 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 231 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 232 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 237 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 24:
#line 241 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 25:
#line 248 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 26:
#line 253 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 27:
#line 258 "Gmsh.y"
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

  case 28:
#line 272 "Gmsh.y"
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

  case 29:
#line 285 "Gmsh.y"
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

  case 30:
#line 298 "Gmsh.y"
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

  case 31:
#line 326 "Gmsh.y"
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

  case 32:
#line 340 "Gmsh.y"
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

  case 33:
#line 353 "Gmsh.y"
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

  case 34:
#line 366 "Gmsh.y"
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

  case 35:
#line 384 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 41:
#line 398 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 42:
#line 400 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 43:
#line 405 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 44:
#line 407 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 45:
#line 412 "Gmsh.y"
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

  case 46:
#line 516 "Gmsh.y"
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

  case 47:
#line 526 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 48:
#line 535 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 49:
#line 542 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 50:
#line 552 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    ;}
    break;

  case 51:
#line 561 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 52:
#line 570 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 53:
#line 577 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 54:
#line 587 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 55:
#line 595 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 56:
#line 605 "Gmsh.y"
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

  case 57:
#line 624 "Gmsh.y"
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

  case 58:
#line 643 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 59:
#line 649 "Gmsh.y"
    {
    ;}
    break;

  case 60:
#line 656 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 61:
#line 657 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 62:
#line 658 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 63:
#line 659 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 64:
#line 660 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 65:
#line 664 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 66:
#line 665 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 67:
#line 671 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 68:
#line 671 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 69:
#line 672 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 70:
#line 672 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 73:
#line 681 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 74:
#line 686 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 75:
#line 692 "Gmsh.y"
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

  case 76:
#line 754 "Gmsh.y"
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

  case 77:
#line 771 "Gmsh.y"
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

  case 78:
#line 800 "Gmsh.y"
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
#line 829 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 80:
#line 834 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 81:
#line 839 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 82:
#line 844 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 83:
#line 849 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 84:
#line 856 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 85:
#line 866 "Gmsh.y"
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
#line 895 "Gmsh.y"
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
#line 924 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 88:
#line 929 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 89:
#line 934 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 90:
#line 939 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 91:
#line 947 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 92:
#line 956 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 93:
#line 962 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 94:
#line 968 "Gmsh.y"
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

  case 95:
#line 981 "Gmsh.y"
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
#line 994 "Gmsh.y"
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

  case 97:
#line 1009 "Gmsh.y"
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
#line 1026 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 99:
#line 1032 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 100:
#line 1038 "Gmsh.y"
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

  case 101:
#line 1051 "Gmsh.y"
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
#line 1064 "Gmsh.y"
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

  case 103:
#line 1079 "Gmsh.y"
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
#line 1096 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 105:
#line 1102 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 106:
#line 1111 "Gmsh.y"
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

  case 107:
#line 1129 "Gmsh.y"
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

  case 108:
#line 1147 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 109:
#line 1156 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 110:
#line 1168 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 111:
#line 1173 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 112:
#line 1181 "Gmsh.y"
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

  case 113:
#line 1201 "Gmsh.y"
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

  case 114:
#line 1224 "Gmsh.y"
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

  case 115:
#line 1235 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 116:
#line 1243 "Gmsh.y"
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

  case 117:
#line 1265 "Gmsh.y"
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

  case 118:
#line 1288 "Gmsh.y"
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

  case 119:
#line 1326 "Gmsh.y"
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

  case 120:
#line 1347 "Gmsh.y"
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

  case 121:
#line 1359 "Gmsh.y"
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

  case 125:
#line 1377 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 126:
#line 1386 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 127:
#line 1395 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 128:
#line 1397 "Gmsh.y"
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

  case 129:
#line 1415 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 130:
#line 1417 "Gmsh.y"
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

  case 131:
#line 1433 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 132:
#line 1435 "Gmsh.y"
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

  case 133:
#line 1451 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 134:
#line 1460 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 135:
#line 1462 "Gmsh.y"
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

  case 137:
#line 1476 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 138:
#line 1484 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 139:
#line 1490 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 140:
#line 1495 "Gmsh.y"
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

  case 143:
#line 1526 "Gmsh.y"
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

  case 144:
#line 1537 "Gmsh.y"
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

  case 145:
#line 1552 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 148:
#line 1568 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 149:
#line 1576 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 150:
#line 1585 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 151:
#line 1593 "Gmsh.y"
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

  case 152:
#line 1611 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 153:
#line 1615 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 154:
#line 1621 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 155:
#line 1629 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 156:
#line 1633 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 157:
#line 1639 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 158:
#line 1647 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 159:
#line 1651 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 160:
#line 1657 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 161:
#line 1665 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 162:
#line 1669 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 163:
#line 1675 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 164:
#line 1683 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 165:
#line 1687 "Gmsh.y"
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

  case 166:
#line 1699 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 167:
#line 1703 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 168:
#line 1713 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindPoint(num)){
	yymsg(0, "Point %d already exists", num);
      }
      else{
	double x = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[0];
	double y = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[1];
	double z = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[2];
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
      (yyval.s).Type = MSH_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 169:
#line 1736 "Gmsh.y"
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

  case 170:
#line 1779 "Gmsh.y"
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

  case 171:
#line 1802 "Gmsh.y"
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

  case 172:
#line 1820 "Gmsh.y"
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

  case 173:
#line 1841 "Gmsh.y"
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

  case 174:
#line 1859 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
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
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    ;}
    break;

  case 175:
#line 1889 "Gmsh.y"
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

  case 176:
#line 1919 "Gmsh.y"
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

  case 177:
#line 1937 "Gmsh.y"
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

  case 178:
#line 1956 "Gmsh.y"
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

  case 179:
#line 1982 "Gmsh.y"
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

  case 180:
#line 2001 "Gmsh.y"
    {
     GModel::current()->getGEOInternals()->addCompoundMesh ( 1 , (yyvsp[(3) - (4)].l) );
   ;}
    break;

  case 181:
#line 2006 "Gmsh.y"
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

  case 182:
#line 2024 "Gmsh.y"
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

  case 183:
#line 2070 "Gmsh.y"
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

  case 184:
#line 2088 "Gmsh.y"
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

  case 185:
#line 2127 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 186:
#line 2133 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 187:
#line 2139 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 188:
#line 2146 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
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
      (yyval.s).Num = num;
    ;}
    break;

  case 189:
#line 2171 "Gmsh.y"
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
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 190:
#line 2196 "Gmsh.y"
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

  case 191:
#line 2213 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 2 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 192:
#line 2217 "Gmsh.y"
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

  case 193:
#line 2237 "Gmsh.y"
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

  case 194:
#line 2270 "Gmsh.y"
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

  case 195:
#line 2317 "Gmsh.y"
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

  case 196:
#line 2335 "Gmsh.y"
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

  case 197:
#line 2352 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 3 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 198:
#line 2356 "Gmsh.y"
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

  case 199:
#line 2372 "Gmsh.y"
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

  case 200:
#line 2420 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 201:
#line 2425 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 202:
#line 2430 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 203:
#line 2435 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 204:
#line 2440 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 205:
#line 2445 "Gmsh.y"
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

  case 206:
#line 2468 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 207:
#line 2474 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 208:
#line 2484 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 209:
#line 2485 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 210:
#line 2490 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 211:
#line 2494 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 212:
#line 2498 "Gmsh.y"
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
	  else
	    yymsg(1, "Unknown point %d", TheShape.Num);
	}
      }
    ;}
    break;

  case 213:
#line 2521 "Gmsh.y"
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
	  else
	    yymsg(1, "Unknown curve %d", TheShape.Num);
	}
      }
    ;}
    break;

  case 214:
#line 2544 "Gmsh.y"
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
	  else
	    yymsg(1, "Unknown surface %d", TheShape.Num);
	}
      }
    ;}
    break;

  case 215:
#line 2567 "Gmsh.y"
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
	  else
	    yymsg(1, "Unknown volume %d", TheShape.Num);
	}
      }
    ;}
    break;

  case 216:
#line 2595 "Gmsh.y"
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

  case 217:
#line 2616 "Gmsh.y"
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

  case 218:
#line 2643 "Gmsh.y"
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

  case 219:
#line 2664 "Gmsh.y"
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

  case 220:
#line 2685 "Gmsh.y"
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

  case 221:
#line 2705 "Gmsh.y"
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

  case 222:
#line 2817 "Gmsh.y"
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

  case 223:
#line 2836 "Gmsh.y"
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

  case 224:
#line 2875 "Gmsh.y"
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

  case 225:
#line 2983 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 226:
#line 2992 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 227:
#line 2998 "Gmsh.y"
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

  case 228:
#line 3013 "Gmsh.y"
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

  case 229:
#line 3041 "Gmsh.y"
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

  case 230:
#line 3058 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 231:
#line 3067 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 232:
#line 3081 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 233:
#line 3095 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 234:
#line 3101 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 235:
#line 3107 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 236:
#line 3116 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 237:
#line 3125 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 238:
#line 3134 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 239:
#line 3148 "Gmsh.y"
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

  case 240:
#line 3210 "Gmsh.y"
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

  case 241:
#line 3228 "Gmsh.y"
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

  case 242:
#line 3245 "Gmsh.y"
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

  case 243:
#line 3260 "Gmsh.y"
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

  case 244:
#line 3289 "Gmsh.y"
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

  case 245:
#line 3301 "Gmsh.y"
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

  case 246:
#line 3325 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 247:
#line 3329 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 248:
#line 3334 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 249:
#line 3341 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 250:
#line 3346 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 251:
#line 3352 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 252:
#line 3357 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 253:
#line 3363 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 254:
#line 3371 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 255:
#line 3375 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 256:
#line 3379 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 257:
#line 3385 "Gmsh.y"
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

  case 258:
#line 3444 "Gmsh.y"
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

  case 259:
#line 3460 "Gmsh.y"
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

  case 260:
#line 3477 "Gmsh.y"
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

  case 261:
#line 3494 "Gmsh.y"
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

  case 262:
#line 3516 "Gmsh.y"
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

  case 263:
#line 3538 "Gmsh.y"
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

  case 264:
#line 3573 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 265:
#line 3581 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 266:
#line 3589 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 267:
#line 3595 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 268:
#line 3602 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 269:
#line 3609 "Gmsh.y"
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

  case 270:
#line 3629 "Gmsh.y"
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

  case 271:
#line 3655 "Gmsh.y"
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

  case 272:
#line 3667 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 273:
#line 3679 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 274:
#line 3687 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 275:
#line 3695 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 276:
#line 3703 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 277:
#line 3709 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 278:
#line 3717 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 279:
#line 3723 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 280:
#line 3731 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 281:
#line 3737 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 282:
#line 3745 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 283:
#line 3751 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 284:
#line 3759 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 285:
#line 3766 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 286:
#line 3773 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 287:
#line 3780 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 288:
#line 3787 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 289:
#line 3794 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 290:
#line 3801 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 291:
#line 3808 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 292:
#line 3815 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 293:
#line 3822 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 294:
#line 3828 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 295:
#line 3835 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 296:
#line 3841 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 297:
#line 3848 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 298:
#line 3854 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 299:
#line 3861 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 300:
#line 3867 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 301:
#line 3874 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 302:
#line 3880 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 303:
#line 3887 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 304:
#line 3893 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 305:
#line 3900 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 306:
#line 3906 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 307:
#line 3913 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 308:
#line 3919 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 309:
#line 3926 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 310:
#line 3932 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 311:
#line 3943 "Gmsh.y"
    {
    ;}
    break;

  case 312:
#line 3946 "Gmsh.y"
    {
    ;}
    break;

  case 313:
#line 3952 "Gmsh.y"
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

  case 314:
#line 3964 "Gmsh.y"
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

  case 315:
#line 3984 "Gmsh.y"
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

  case 316:
#line 4008 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 317:
#line 4012 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 318:
#line 4016 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 319:
#line 4020 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 320:
#line 4024 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 321:
#line 4028 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 322:
#line 4034 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 323:
#line 4040 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 324:
#line 4044 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 325:
#line 4048 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 326:
#line 4052 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 327:
#line 4056 "Gmsh.y"
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

  case 328:
#line 4075 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 329:
#line 4087 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 330:
#line 4091 "Gmsh.y"
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

  case 331:
#line 4106 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 332:
#line 4110 "Gmsh.y"
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

  case 333:
#line 4126 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 334:
#line 4130 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 335:
#line 4135 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 336:
#line 4139 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 337:
#line 4145 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 338:
#line 4149 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 339:
#line 4156 "Gmsh.y"
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

  case 340:
#line 4212 "Gmsh.y"
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

  case 341:
#line 4282 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 342:
#line 4287 "Gmsh.y"
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

  case 343:
#line 4354 "Gmsh.y"
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

  case 344:
#line 4390 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 345:
#line 4398 "Gmsh.y"
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

  case 346:
#line 4441 "Gmsh.y"
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

  case 347:
#line 4480 "Gmsh.y"
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

  case 348:
#line 4501 "Gmsh.y"
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

  case 349:
#line 4533 "Gmsh.y"
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

  case 350:
#line 4560 "Gmsh.y"
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

  case 351:
#line 4586 "Gmsh.y"
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

  case 352:
#line 4612 "Gmsh.y"
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

  case 353:
#line 4638 "Gmsh.y"
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

  case 354:
#line 4664 "Gmsh.y"
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

  case 355:
#line 4685 "Gmsh.y"
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

  case 356:
#line 4713 "Gmsh.y"
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

  case 357:
#line 4741 "Gmsh.y"
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

  case 358:
#line 4769 "Gmsh.y"
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

  case 359:
#line 4797 "Gmsh.y"
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

  case 360:
#line 4825 "Gmsh.y"
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

  case 361:
#line 4864 "Gmsh.y"
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

  case 362:
#line 4903 "Gmsh.y"
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

  case 363:
#line 4924 "Gmsh.y"
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

  case 364:
#line 4945 "Gmsh.y"
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

  case 365:
#line 4972 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 366:
#line 4976 "Gmsh.y"
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

  case 367:
#line 4986 "Gmsh.y"
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

  case 368:
#line 5020 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 369:
#line 5021 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 370:
#line 5022 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 371:
#line 5027 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 372:
#line 5033 "Gmsh.y"
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

  case 373:
#line 5045 "Gmsh.y"
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

  case 374:
#line 5063 "Gmsh.y"
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

  case 375:
#line 5090 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 376:
#line 5091 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 377:
#line 5092 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 378:
#line 5093 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 379:
#line 5094 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 380:
#line 5095 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 381:
#line 5096 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 382:
#line 5097 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 383:
#line 5099 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 384:
#line 5105 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 385:
#line 5106 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 386:
#line 5107 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 387:
#line 5108 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 388:
#line 5109 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 389:
#line 5110 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 390:
#line 5111 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 391:
#line 5112 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 392:
#line 5113 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 393:
#line 5114 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 394:
#line 5115 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 395:
#line 5116 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 396:
#line 5117 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 397:
#line 5118 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 398:
#line 5119 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 399:
#line 5120 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 400:
#line 5121 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 401:
#line 5122 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 402:
#line 5123 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 403:
#line 5124 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 404:
#line 5125 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 405:
#line 5126 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 406:
#line 5127 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 407:
#line 5128 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 408:
#line 5129 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 409:
#line 5130 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 410:
#line 5131 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 411:
#line 5132 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 412:
#line 5133 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 413:
#line 5134 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 414:
#line 5135 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 415:
#line 5136 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 416:
#line 5137 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 417:
#line 5146 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 418:
#line 5147 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 419:
#line 5148 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 420:
#line 5149 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 421:
#line 5150 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 422:
#line 5151 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 423:
#line 5152 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 424:
#line 5153 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 425:
#line 5154 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 426:
#line 5155 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 427:
#line 5156 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 428:
#line 5161 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 429:
#line 5163 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 430:
#line 5169 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 431:
#line 5174 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 432:
#line 5179 "Gmsh.y"
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

  case 433:
#line 5196 "Gmsh.y"
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

  case 434:
#line 5214 "Gmsh.y"
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

  case 435:
#line 5232 "Gmsh.y"
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

  case 436:
#line 5250 "Gmsh.y"
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

  case 437:
#line 5268 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 438:
#line 5273 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 439:
#line 5279 "Gmsh.y"
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

  case 440:
#line 5294 "Gmsh.y"
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

  case 441:
#line 5313 "Gmsh.y"
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

  case 442:
#line 5333 "Gmsh.y"
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
#line 5353 "Gmsh.y"
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
#line 5373 "Gmsh.y"
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

  case 445:
#line 5396 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 446:
#line 5401 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 447:
#line 5406 "Gmsh.y"
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
#line 5416 "Gmsh.y"
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
#line 5426 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 450:
#line 5431 "Gmsh.y"
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
#line 5442 "Gmsh.y"
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
#line 5451 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 453:
#line 5456 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 454:
#line 5461 "Gmsh.y"
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

  case 455:
#line 5488 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 456:
#line 5492 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 457:
#line 5496 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 458:
#line 5500 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 459:
#line 5504 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 460:
#line 5511 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 461:
#line 5515 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 462:
#line 5519 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 463:
#line 5523 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 464:
#line 5530 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 465:
#line 5535 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 466:
#line 5542 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 467:
#line 5547 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 468:
#line 5551 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 469:
#line 5556 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 470:
#line 5560 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 471:
#line 5568 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 472:
#line 5579 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 473:
#line 5583 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 474:
#line 5595 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 475:
#line 5603 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 476:
#line 5611 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 477:
#line 5618 "Gmsh.y"
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

  case 478:
#line 5628 "Gmsh.y"
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

  case 479:
#line 5657 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 480:
#line 5661 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 481:
#line 5665 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 482:
#line 5669 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 483:
#line 5673 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 484:
#line 5677 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 485:
#line 5681 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 486:
#line 5685 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 487:
#line 5689 "Gmsh.y"
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

  case 488:
#line 5718 "Gmsh.y"
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

  case 489:
#line 5747 "Gmsh.y"
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

  case 490:
#line 5776 "Gmsh.y"
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

  case 491:
#line 5806 "Gmsh.y"
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

  case 492:
#line 5819 "Gmsh.y"
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

  case 493:
#line 5832 "Gmsh.y"
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

  case 494:
#line 5845 "Gmsh.y"
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

  case 495:
#line 5857 "Gmsh.y"
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
#line 5867 "Gmsh.y"
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
#line 5877 "Gmsh.y"
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
#line 5889 "Gmsh.y"
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

  case 499:
#line 5902 "Gmsh.y"
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

  case 500:
#line 5914 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 501:
#line 5918 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 502:
#line 5922 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 503:
#line 5926 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 504:
#line 5930 "Gmsh.y"
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

  case 505:
#line 5948 "Gmsh.y"
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

  case 506:
#line 5966 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 507:
#line 5974 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 508:
#line 5982 "Gmsh.y"
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

  case 509:
#line 6011 "Gmsh.y"
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

  case 510:
#line 6024 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 511:
#line 6029 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 512:
#line 6033 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 513:
#line 6037 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 514:
#line 6049 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 515:
#line 6053 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 516:
#line 6065 "Gmsh.y"
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

  case 517:
#line 6082 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 518:
#line 6092 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 519:
#line 6096 "Gmsh.y"
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

  case 520:
#line 6111 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 521:
#line 6116 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 522:
#line 6123 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 523:
#line 6127 "Gmsh.y"
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

  case 524:
#line 6140 "Gmsh.y"
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
#line 6154 "Gmsh.y"
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

  case 526:
#line 6168 "Gmsh.y"
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

  case 527:
#line 6182 "Gmsh.y"
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

  case 528:
#line 6196 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 529:
#line 6204 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 530:
#line 6215 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 531:
#line 6219 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 532:
#line 6223 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 533:
#line 6231 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 534:
#line 6237 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 535:
#line 6243 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 536:
#line 6251 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 537:
#line 6259 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 538:
#line 6266 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 539:
#line 6274 "Gmsh.y"
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

  case 540:
#line 6289 "Gmsh.y"
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

  case 541:
#line 6303 "Gmsh.y"
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

  case 542:
#line 6317 "Gmsh.y"
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

  case 543:
#line 6329 "Gmsh.y"
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

  case 544:
#line 6345 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 545:
#line 6354 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 546:
#line 6363 "Gmsh.y"
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

  case 547:
#line 6373 "Gmsh.y"
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

  case 548:
#line 6384 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 549:
#line 6392 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 550:
#line 6400 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 551:
#line 6404 "Gmsh.y"
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

  case 552:
#line 6423 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 553:
#line 6430 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 554:
#line 6436 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 555:
#line 6443 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 556:
#line 6450 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 557:
#line 6452 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 558:
#line 6463 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 559:
#line 6468 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 560:
#line 6474 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 561:
#line 6483 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 562:
#line 6496 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 563:
#line 6499 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 564:
#line 6503 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13323 "Gmsh.tab.cpp"
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


#line 6506 "Gmsh.y"


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

