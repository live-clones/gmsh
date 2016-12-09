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
     tCatenary = 295,
     tPrintf = 296,
     tError = 297,
     tStr = 298,
     tSprintf = 299,
     tStrCat = 300,
     tStrPrefix = 301,
     tStrRelative = 302,
     tStrReplace = 303,
     tAbsolutePath = 304,
     tDirName = 305,
     tStrSub = 306,
     tStrLen = 307,
     tFind = 308,
     tStrFind = 309,
     tStrCmp = 310,
     tStrChoice = 311,
     tUpperCase = 312,
     tLowerCase = 313,
     tLowerCaseIn = 314,
     tTextAttributes = 315,
     tBoundingBox = 316,
     tDraw = 317,
     tSetChanged = 318,
     tToday = 319,
     tFixRelativePath = 320,
     tCurrentDirectory = 321,
     tSyncModel = 322,
     tNewModel = 323,
     tOnelabAction = 324,
     tOnelabRun = 325,
     tCpu = 326,
     tMemory = 327,
     tTotalMemory = 328,
     tCreateTopology = 329,
     tCreateTopologyNoHoles = 330,
     tDistanceFunction = 331,
     tDefineConstant = 332,
     tUndefineConstant = 333,
     tDefineNumber = 334,
     tDefineString = 335,
     tSetNumber = 336,
     tSetString = 337,
     tPoint = 338,
     tCircle = 339,
     tEllipse = 340,
     tLine = 341,
     tSphere = 342,
     tPolarSphere = 343,
     tSurface = 344,
     tSpline = 345,
     tVolume = 346,
     tCharacteristic = 347,
     tLength = 348,
     tParametric = 349,
     tElliptic = 350,
     tRefineMesh = 351,
     tAdaptMesh = 352,
     tRelocateMesh = 353,
     tPlane = 354,
     tRuled = 355,
     tTransfinite = 356,
     tComplex = 357,
     tPhysical = 358,
     tCompound = 359,
     tPeriodic = 360,
     tUsing = 361,
     tPlugin = 362,
     tDegenerated = 363,
     tRecursive = 364,
     tRotate = 365,
     tTranslate = 366,
     tSymmetry = 367,
     tDilate = 368,
     tExtrude = 369,
     tLevelset = 370,
     tAffine = 371,
     tRecombine = 372,
     tSmoother = 373,
     tSplit = 374,
     tDelete = 375,
     tCoherence = 376,
     tIntersect = 377,
     tMeshAlgorithm = 378,
     tReverse = 379,
     tLayers = 380,
     tScaleLast = 381,
     tHole = 382,
     tAlias = 383,
     tAliasWithOptions = 384,
     tCopyOptions = 385,
     tQuadTriAddVerts = 386,
     tQuadTriNoNewVerts = 387,
     tQuadTriSngl = 388,
     tQuadTriDbl = 389,
     tRecombLaterals = 390,
     tTransfQuadTri = 391,
     tText2D = 392,
     tText3D = 393,
     tInterpolationScheme = 394,
     tTime = 395,
     tCombine = 396,
     tBSpline = 397,
     tBezier = 398,
     tNurbs = 399,
     tNurbsOrder = 400,
     tNurbsKnots = 401,
     tColor = 402,
     tColorTable = 403,
     tFor = 404,
     tIn = 405,
     tEndFor = 406,
     tIf = 407,
     tElseIf = 408,
     tElse = 409,
     tEndIf = 410,
     tExit = 411,
     tAbort = 412,
     tField = 413,
     tReturn = 414,
     tCall = 415,
     tSlide = 416,
     tMacro = 417,
     tShow = 418,
     tHide = 419,
     tGetValue = 420,
     tGetStringValue = 421,
     tGetEnv = 422,
     tGetString = 423,
     tGetNumber = 424,
     tHomology = 425,
     tCohomology = 426,
     tBetti = 427,
     tExists = 428,
     tFileExists = 429,
     tGMSH_MAJOR_VERSION = 430,
     tGMSH_MINOR_VERSION = 431,
     tGMSH_PATCH_VERSION = 432,
     tGmshExecutableName = 433,
     tSetPartition = 434,
     tNameToString = 435,
     tStringToName = 436,
     tAFFECTDIVIDE = 437,
     tAFFECTTIMES = 438,
     tAFFECTMINUS = 439,
     tAFFECTPLUS = 440,
     tOR = 441,
     tAND = 442,
     tNOTEQUAL = 443,
     tEQUAL = 444,
     tGREATEROREQUAL = 445,
     tLESSOREQUAL = 446,
     UNARYPREC = 447,
     tMINUSMINUS = 448,
     tPLUSPLUS = 449
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
#define tCatenary 295
#define tPrintf 296
#define tError 297
#define tStr 298
#define tSprintf 299
#define tStrCat 300
#define tStrPrefix 301
#define tStrRelative 302
#define tStrReplace 303
#define tAbsolutePath 304
#define tDirName 305
#define tStrSub 306
#define tStrLen 307
#define tFind 308
#define tStrFind 309
#define tStrCmp 310
#define tStrChoice 311
#define tUpperCase 312
#define tLowerCase 313
#define tLowerCaseIn 314
#define tTextAttributes 315
#define tBoundingBox 316
#define tDraw 317
#define tSetChanged 318
#define tToday 319
#define tFixRelativePath 320
#define tCurrentDirectory 321
#define tSyncModel 322
#define tNewModel 323
#define tOnelabAction 324
#define tOnelabRun 325
#define tCpu 326
#define tMemory 327
#define tTotalMemory 328
#define tCreateTopology 329
#define tCreateTopologyNoHoles 330
#define tDistanceFunction 331
#define tDefineConstant 332
#define tUndefineConstant 333
#define tDefineNumber 334
#define tDefineString 335
#define tSetNumber 336
#define tSetString 337
#define tPoint 338
#define tCircle 339
#define tEllipse 340
#define tLine 341
#define tSphere 342
#define tPolarSphere 343
#define tSurface 344
#define tSpline 345
#define tVolume 346
#define tCharacteristic 347
#define tLength 348
#define tParametric 349
#define tElliptic 350
#define tRefineMesh 351
#define tAdaptMesh 352
#define tRelocateMesh 353
#define tPlane 354
#define tRuled 355
#define tTransfinite 356
#define tComplex 357
#define tPhysical 358
#define tCompound 359
#define tPeriodic 360
#define tUsing 361
#define tPlugin 362
#define tDegenerated 363
#define tRecursive 364
#define tRotate 365
#define tTranslate 366
#define tSymmetry 367
#define tDilate 368
#define tExtrude 369
#define tLevelset 370
#define tAffine 371
#define tRecombine 372
#define tSmoother 373
#define tSplit 374
#define tDelete 375
#define tCoherence 376
#define tIntersect 377
#define tMeshAlgorithm 378
#define tReverse 379
#define tLayers 380
#define tScaleLast 381
#define tHole 382
#define tAlias 383
#define tAliasWithOptions 384
#define tCopyOptions 385
#define tQuadTriAddVerts 386
#define tQuadTriNoNewVerts 387
#define tQuadTriSngl 388
#define tQuadTriDbl 389
#define tRecombLaterals 390
#define tTransfQuadTri 391
#define tText2D 392
#define tText3D 393
#define tInterpolationScheme 394
#define tTime 395
#define tCombine 396
#define tBSpline 397
#define tBezier 398
#define tNurbs 399
#define tNurbsOrder 400
#define tNurbsKnots 401
#define tColor 402
#define tColorTable 403
#define tFor 404
#define tIn 405
#define tEndFor 406
#define tIf 407
#define tElseIf 408
#define tElse 409
#define tEndIf 410
#define tExit 411
#define tAbort 412
#define tField 413
#define tReturn 414
#define tCall 415
#define tSlide 416
#define tMacro 417
#define tShow 418
#define tHide 419
#define tGetValue 420
#define tGetStringValue 421
#define tGetEnv 422
#define tGetString 423
#define tGetNumber 424
#define tHomology 425
#define tCohomology 426
#define tBetti 427
#define tExists 428
#define tFileExists 429
#define tGMSH_MAJOR_VERSION 430
#define tGMSH_MINOR_VERSION 431
#define tGMSH_PATCH_VERSION 432
#define tGmshExecutableName 433
#define tSetPartition 434
#define tNameToString 435
#define tStringToName 436
#define tAFFECTDIVIDE 437
#define tAFFECTTIMES 438
#define tAFFECTMINUS 439
#define tAFFECTPLUS 440
#define tOR 441
#define tAND 442
#define tNOTEQUAL 443
#define tEQUAL 444
#define tGREATEROREQUAL 445
#define tLESSOREQUAL 446
#define UNARYPREC 447
#define tMINUSMINUS 448
#define tPLUSPLUS 449




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
#line 616 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 629 "Gmsh.tab.cpp"

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
#define YYLAST   12868

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  215
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  563
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2039

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   449

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   200,     2,   210,     2,   199,     2,     2,
     205,   206,   197,   195,   211,   196,   209,   198,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     191,     2,   192,   186,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   207,     2,   208,   204,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   212,     2,   213,   214,     2,     2,     2,
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
     185,   187,   188,   189,   190,   193,   194,   201,   202,   203
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
    2950,  2955,  2960,  2967,  2974,  2981,  2988,  2997,  3006,  3021,
    3023,  3025,  3029,  3033,  3043,  3051,  3053,  3059,  3063,  3070,
    3072,  3076,  3078,  3080,  3085,  3090,  3095,  3100,  3104,  3111,
    3113,  3118,  3120,  3122,  3124,  3129,  3136,  3141,  3148,  3153,
    3158,  3163,  3172,  3177,  3182,  3187,  3192,  3201,  3210,  3217,
    3222,  3229,  3234,  3236,  3241,  3246,  3247,  3254,  3256,  3260,
    3266,  3272,  3274,  3276
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     216,     0,    -1,   217,    -1,     1,     6,    -1,    -1,   217,
     218,    -1,   221,    -1,   220,    -1,   241,    -1,   260,    -1,
     261,    -1,   265,    -1,   266,    -1,   267,    -1,   268,    -1,
     272,    -1,   293,    -1,   294,    -1,   271,    -1,   270,    -1,
     269,    -1,   264,    -1,   296,    -1,   192,    -1,   192,   192,
      -1,    41,   205,   310,   206,     6,    -1,    42,   205,   310,
     206,     6,    -1,    41,   205,   310,   206,   219,   310,     6,
      -1,    41,   205,   310,   211,   306,   206,     6,    -1,    42,
     205,   310,   211,   306,   206,     6,    -1,    41,   205,   310,
     211,   306,   206,   219,   310,     6,    -1,     4,   310,   212,
     222,   213,     6,    -1,   128,     4,   207,   297,   208,     6,
      -1,   129,     4,   207,   297,   208,     6,    -1,   130,     4,
     207,   297,   211,   297,   208,     6,    -1,    -1,   222,   225,
      -1,   222,   229,    -1,   222,   232,    -1,   222,   234,    -1,
     222,   235,    -1,   297,    -1,   223,   211,   297,    -1,   297,
      -1,   224,   211,   297,    -1,    -1,    -1,     4,   226,   205,
     223,   206,   227,   212,   224,   213,     6,    -1,   310,    -1,
     228,   211,   310,    -1,    -1,   137,   205,   297,   211,   297,
     211,   297,   206,   230,   212,   228,   213,     6,    -1,   310,
      -1,   231,   211,   310,    -1,    -1,   138,   205,   297,   211,
     297,   211,   297,   211,   297,   206,   233,   212,   231,   213,
       6,    -1,   139,   212,   302,   213,   212,   302,   213,     6,
      -1,   139,   212,   302,   213,   212,   302,   213,   212,   302,
     213,   212,   302,   213,     6,    -1,    -1,   140,   236,   212,
     224,   213,     6,    -1,     7,    -1,   185,    -1,   184,    -1,
     183,    -1,   182,    -1,   203,    -1,   202,    -1,   205,    -1,
     207,    -1,   206,    -1,   208,    -1,    77,   207,   243,   208,
       6,    -1,    78,   207,   248,   208,     6,    -1,    81,   239,
     311,   211,   297,   240,     6,    -1,    82,   239,   315,   211,
     311,   240,     6,    -1,   315,   237,   303,     6,    -1,   315,
     238,     6,    -1,     4,   207,   208,   237,   303,     6,    -1,
     314,   207,   208,   237,   303,     6,    -1,     4,   207,   297,
     208,   237,   297,     6,    -1,   314,   207,   297,   208,   237,
     297,     6,    -1,     4,   207,   297,   208,   238,     6,    -1,
     314,   207,   297,   208,   238,     6,    -1,     4,   239,   212,
     306,   213,   240,   237,   303,     6,    -1,   314,   239,   212,
     306,   213,   240,   237,   303,     6,    -1,     4,   205,   206,
     237,   303,     6,    -1,   314,   205,   206,   237,   303,     6,
      -1,     4,   205,   297,   206,   237,   297,     6,    -1,   314,
     205,   297,   206,   237,   297,     6,    -1,     4,   205,   297,
     206,   238,     6,    -1,   314,   205,   297,   206,   238,     6,
      -1,   315,     7,   311,     6,    -1,     4,   207,   208,     7,
      43,   239,   240,     6,    -1,   314,   207,   208,     7,    43,
     239,   240,     6,    -1,     4,   207,   208,     7,    43,   239,
     313,   240,     6,    -1,   314,   207,   208,     7,    43,   239,
     313,   240,     6,    -1,     4,   207,   208,   185,    43,   239,
     313,   240,     6,    -1,   314,   207,   208,   185,    43,   239,
     313,   240,     6,    -1,     4,   205,   206,     7,    43,   239,
     240,     6,    -1,   314,   205,   206,     7,    43,   239,   240,
       6,    -1,     4,   205,   206,     7,    43,   239,   313,   240,
       6,    -1,   314,   205,   206,     7,    43,   239,   313,   240,
       6,    -1,     4,   205,   206,   185,    43,   239,   313,   240,
       6,    -1,   314,   205,   206,   185,    43,   239,   313,   240,
       6,    -1,     4,   209,     4,     7,   311,     6,    -1,     4,
     207,   297,   208,   209,     4,     7,   311,     6,    -1,     4,
     209,     4,   237,   297,     6,    -1,     4,   207,   297,   208,
     209,     4,   237,   297,     6,    -1,     4,   209,     4,   238,
       6,    -1,     4,   207,   297,   208,   209,     4,   238,     6,
      -1,     4,   209,   147,   209,     4,     7,   307,     6,    -1,
       4,   207,   297,   208,   209,   147,   209,     4,     7,   307,
       6,    -1,     4,   209,   148,     7,   308,     6,    -1,     4,
     207,   297,   208,   209,   148,     7,   308,     6,    -1,     4,
     158,     7,   297,     6,    -1,   158,   207,   297,   208,     7,
       4,     6,    -1,   158,   207,   297,   208,   209,     4,     7,
     297,     6,    -1,   158,   207,   297,   208,   209,     4,     7,
     311,     6,    -1,   158,   207,   297,   208,   209,     4,     7,
     212,   306,   213,     6,    -1,   158,   207,   297,   208,   209,
       4,     6,    -1,   107,   205,     4,   206,   209,     4,     7,
     297,     6,    -1,   107,   205,     4,   206,   209,     4,     7,
     311,     6,    -1,    -1,   211,    -1,    -1,   243,   242,   315,
      -1,   243,   242,   315,     7,   297,    -1,    -1,   243,   242,
     315,     7,   212,   303,   244,   250,   213,    -1,    -1,   243,
     242,   315,   207,   208,     7,   212,   303,   245,   250,   213,
      -1,    -1,   243,   242,   315,   205,   206,     7,   212,   303,
     246,   250,   213,    -1,   243,   242,   315,     7,   311,    -1,
      -1,   243,   242,   315,     7,   212,   311,   247,   252,   213,
      -1,    -1,   248,   242,   310,    -1,   297,     7,   311,    -1,
     249,   211,   297,     7,   311,    -1,   305,     7,   315,   205,
     206,    -1,    -1,   250,   251,    -1,   211,     4,   303,    -1,
     211,     4,   212,   249,   213,    -1,   211,     4,   311,    -1,
      -1,   252,   253,    -1,   211,     4,   297,    -1,   211,     4,
     311,    -1,   211,   162,   311,    -1,   211,     4,   212,   313,
     213,    -1,   297,    -1,   311,    -1,   311,   211,   297,    -1,
     297,    -1,   311,    -1,   311,   211,   297,    -1,   297,    -1,
     311,    -1,   311,   211,   297,    -1,   297,    -1,   311,    -1,
     311,   211,   297,    -1,    -1,   150,    87,   212,   297,   213,
      -1,    -1,    99,   300,    -1,    83,   205,   297,   206,     7,
     300,     6,    -1,   103,    83,   205,   254,   206,   237,   303,
       6,    -1,    92,    93,   303,     7,   297,     6,    -1,    86,
     205,   297,   206,     7,   303,     6,    -1,   108,    86,   303,
       6,    -1,    90,   205,   297,   206,     7,   303,     6,    -1,
      84,   205,   297,   206,     7,   303,   259,     6,    -1,    85,
     205,   297,   206,     7,   303,   259,     6,    -1,   142,   205,
     297,   206,     7,   303,     6,    -1,   143,   205,   297,   206,
       7,   303,     6,    -1,   144,   205,   297,   206,     7,   303,
     146,   303,   145,   297,     6,    -1,    86,     4,   205,   297,
     206,     7,   303,     6,    -1,   104,    86,   303,     6,    -1,
     104,    86,   205,   297,   206,     7,   303,     6,    -1,   103,
      86,   205,   255,   206,   237,   303,     6,    -1,    99,    89,
     205,   297,   206,     7,   303,     6,    -1,   100,    89,   205,
     297,   206,     7,   303,   258,     6,    -1,    12,    13,     6,
      -1,    13,    89,   297,     6,    -1,    94,    89,   205,   297,
     206,     7,     5,     5,     5,     6,    -1,    87,   205,   297,
     206,     7,   303,     6,    -1,    88,   205,   297,   206,     7,
     303,     6,    -1,    89,     4,   205,   297,   206,     7,   303,
       6,    -1,   104,    89,   303,     6,    -1,   104,    89,   205,
     297,   206,     7,   303,     6,    -1,   104,    89,   205,   297,
     206,     7,   303,     4,   212,   302,   213,     6,    -1,   103,
      89,   205,   256,   206,   237,   303,     6,    -1,   102,    91,
     205,   297,   206,     7,   303,     6,    -1,    91,   205,   297,
     206,     7,   303,     6,    -1,   104,    91,   303,     6,    -1,
     104,    91,   205,   297,   206,     7,   303,     6,    -1,   103,
      91,   205,   257,   206,   237,   303,     6,    -1,   111,   300,
     212,   262,   213,    -1,   110,   212,   300,   211,   300,   211,
     297,   213,   212,   262,   213,    -1,   112,   300,   212,   262,
     213,    -1,   113,   212,   300,   211,   297,   213,   212,   262,
     213,    -1,   113,   212,   300,   211,   300,   213,   212,   262,
     213,    -1,     4,   212,   262,   213,    -1,   122,    86,   212,
     306,   213,    89,   212,   297,   213,    -1,   119,    86,   205,
     297,   206,   212,   306,   213,     6,    -1,   263,    -1,   261,
      -1,    -1,   263,   260,    -1,   263,    83,   212,   306,   213,
       6,    -1,   263,    86,   212,   306,   213,     6,    -1,   263,
      89,   212,   306,   213,     6,    -1,   263,    91,   212,   306,
     213,     6,    -1,   115,    99,   205,   297,   206,     7,   303,
       6,    -1,   115,    83,   205,   297,   206,     7,   212,   302,
     213,     6,    -1,   115,    99,   205,   297,   206,     7,   212,
     300,   211,   300,   211,   306,   213,     6,    -1,   115,    99,
     205,   297,   206,     7,   212,   300,   211,   300,   211,   300,
     211,   306,   213,     6,    -1,   115,    87,   205,   297,   206,
       7,   212,   300,   211,   306,   213,     6,    -1,   115,     4,
     205,   297,   206,     7,   303,     6,    -1,   115,     4,   205,
     297,   206,     7,     5,     6,    -1,   115,     4,   212,   297,
     213,     6,    -1,   115,     4,   205,   297,   206,     7,   212,
     300,   211,   300,   211,   306,   213,     6,    -1,   120,   212,
     263,   213,    -1,   120,   158,   207,   297,   208,     6,    -1,
     120,     4,   207,   297,   208,     6,    -1,   120,   315,     6,
      -1,   120,     4,     4,     6,    -1,   147,   307,   212,   263,
     213,    -1,   109,   147,   307,   212,   263,   213,    -1,   179,
     297,   212,   263,   213,    -1,   163,     5,     6,    -1,   164,
       5,     6,    -1,   163,   212,   263,   213,    -1,   109,   163,
     212,   263,   213,    -1,   164,   212,   263,   213,    -1,   109,
     164,   212,   263,   213,    -1,     4,   311,     6,    -1,    70,
     205,   313,   206,     6,    -1,     4,     4,   207,   297,   208,
     310,     6,    -1,     4,     4,     4,   207,   297,   208,     6,
      -1,     4,   297,     6,    -1,   107,   205,     4,   206,   209,
       4,     6,    -1,   141,     4,     6,    -1,   156,     6,    -1,
     157,     6,    -1,    67,     6,    -1,    68,     6,    -1,    61,
       6,    -1,    61,   212,   297,   211,   297,   211,   297,   211,
     297,   211,   297,   211,   297,   213,     6,    -1,    62,     6,
      -1,    63,     6,    -1,    74,     6,    -1,    75,     6,    -1,
      96,     6,    -1,    97,   212,   306,   213,   212,   306,   213,
     212,   302,   213,   212,   297,   211,   297,   213,     6,    -1,
     161,   205,   212,   306,   213,   211,   311,   211,   311,   206,
       6,    -1,   149,   205,   297,     8,   297,   206,    -1,   149,
     205,   297,     8,   297,     8,   297,   206,    -1,   149,     4,
     150,   212,   297,     8,   297,   213,    -1,   149,     4,   150,
     212,   297,     8,   297,     8,   297,   213,    -1,   151,    -1,
     162,     4,    -1,   162,   311,    -1,   159,    -1,   160,   315,
       6,    -1,   160,   311,     6,    -1,   152,   205,   297,   206,
      -1,   153,   205,   297,   206,    -1,   154,    -1,   155,    -1,
     114,   300,   212,   263,   213,    -1,   114,   212,   300,   211,
     300,   211,   297,   213,   212,   263,   213,    -1,   114,   212,
     300,   211,   300,   211,   300,   211,   297,   213,   212,   263,
     213,    -1,    -1,   114,   300,   212,   263,   273,   286,   213,
      -1,    -1,   114,   212,   300,   211,   300,   211,   297,   213,
     212,   263,   274,   286,   213,    -1,    -1,   114,   212,   300,
     211,   300,   211,   300,   211,   297,   213,   212,   263,   275,
     286,   213,    -1,    -1,   114,   212,   263,   276,   286,   213,
      -1,   114,    83,   212,   297,   211,   300,   213,     6,    -1,
     114,    86,   212,   297,   211,   300,   213,     6,    -1,   114,
      89,   212,   297,   211,   300,   213,     6,    -1,   114,    83,
     212,   297,   211,   300,   211,   300,   211,   297,   213,     6,
      -1,   114,    86,   212,   297,   211,   300,   211,   300,   211,
     297,   213,     6,    -1,   114,    89,   212,   297,   211,   300,
     211,   300,   211,   297,   213,     6,    -1,   114,    83,   212,
     297,   211,   300,   211,   300,   211,   300,   211,   297,   213,
       6,    -1,   114,    86,   212,   297,   211,   300,   211,   300,
     211,   300,   211,   297,   213,     6,    -1,   114,    89,   212,
     297,   211,   300,   211,   300,   211,   300,   211,   297,   213,
       6,    -1,    -1,   114,    83,   212,   297,   211,   300,   213,
     277,   212,   286,   213,     6,    -1,    -1,   114,    86,   212,
     297,   211,   300,   213,   278,   212,   286,   213,     6,    -1,
      -1,   114,    89,   212,   297,   211,   300,   213,   279,   212,
     286,   213,     6,    -1,    -1,   114,    83,   212,   297,   211,
     300,   211,   300,   211,   297,   213,   280,   212,   286,   213,
       6,    -1,    -1,   114,    86,   212,   297,   211,   300,   211,
     300,   211,   297,   213,   281,   212,   286,   213,     6,    -1,
      -1,   114,    89,   212,   297,   211,   300,   211,   300,   211,
     297,   213,   282,   212,   286,   213,     6,    -1,    -1,   114,
      83,   212,   297,   211,   300,   211,   300,   211,   300,   211,
     297,   213,   283,   212,   286,   213,     6,    -1,    -1,   114,
      86,   212,   297,   211,   300,   211,   300,   211,   300,   211,
     297,   213,   284,   212,   286,   213,     6,    -1,    -1,   114,
      89,   212,   297,   211,   300,   211,   300,   211,   300,   211,
     297,   213,   285,   212,   286,   213,     6,    -1,   287,    -1,
     286,   287,    -1,   125,   212,   297,   213,     6,    -1,   125,
     212,   303,   211,   303,   213,     6,    -1,   125,   212,   303,
     211,   303,   211,   303,   213,     6,    -1,   126,     6,    -1,
     117,     6,    -1,   117,   297,     6,    -1,   133,     6,    -1,
     133,   135,     6,    -1,   134,     6,    -1,   134,   135,     6,
      -1,   131,     6,    -1,   131,   135,     6,    -1,   132,     6,
      -1,   132,   135,     6,    -1,   127,   205,   297,   206,     7,
     303,   106,   297,     6,    -1,   106,     4,   207,   297,   208,
       6,    -1,    -1,   106,     4,   297,    -1,    -1,     4,    -1,
      -1,     7,   303,    -1,    -1,     7,   297,    -1,    -1,   116,
     303,    -1,   101,    86,   304,     7,   297,   288,     6,    -1,
     101,    89,   304,   290,   289,     6,    -1,    95,    89,   212,
     297,   213,     7,   303,     6,    -1,   101,    91,   304,   290,
       6,    -1,   136,   304,     6,    -1,   123,    89,   212,   306,
     213,     7,   297,     6,    -1,   117,    89,   304,   291,     6,
      -1,   117,    91,   304,     6,    -1,   118,    89,   303,     7,
     297,     6,    -1,   105,    86,   212,   306,   213,     7,   212,
     306,   213,   292,     6,    -1,   105,    89,   212,   306,   213,
       7,   212,   306,   213,   292,     6,    -1,   105,    86,   212,
     306,   213,     7,   212,   306,   213,   110,   212,   300,   211,
     300,   211,   297,   213,     6,    -1,   105,    89,   212,   306,
     213,     7,   212,   306,   213,   110,   212,   300,   211,   300,
     211,   297,   213,     6,    -1,   105,    86,   212,   306,   213,
       7,   212,   306,   213,   111,   300,     6,    -1,   105,    89,
     212,   306,   213,     7,   212,   306,   213,   111,   300,     6,
      -1,   105,    89,   297,   212,   306,   213,     7,   297,   212,
     306,   213,     6,    -1,    83,   212,   306,   213,   150,    89,
     212,   297,   213,     6,    -1,    86,   212,   306,   213,   150,
      89,   212,   297,   213,     6,    -1,    83,   212,   306,   213,
     150,    91,   212,   297,   213,     6,    -1,    86,   212,   306,
     213,   150,    91,   212,   297,   213,     6,    -1,    89,   212,
     306,   213,   150,    91,   212,   297,   213,     6,    -1,   124,
      89,   304,     6,    -1,   124,    86,   304,     6,    -1,    98,
      83,   304,     6,    -1,    98,    86,   304,     6,    -1,    98,
      89,   304,     6,    -1,   121,     6,    -1,   121,     4,     6,
      -1,   121,    83,   212,   306,   213,     6,    -1,   170,    -1,
     171,    -1,   172,    -1,   295,     6,    -1,   295,   212,   303,
     213,     6,    -1,   295,   212,   303,   211,   303,   213,     6,
      -1,   295,   205,   303,   206,   212,   303,   211,   303,   213,
       6,    -1,   298,    -1,   205,   297,   206,    -1,   196,   297,
      -1,   195,   297,    -1,   200,   297,    -1,   297,   196,   297,
      -1,   297,   195,   297,    -1,   297,   197,   297,    -1,   297,
     198,   297,    -1,   297,   199,   297,    -1,   297,   204,   297,
      -1,   297,   191,   297,    -1,   297,   192,   297,    -1,   297,
     194,   297,    -1,   297,   193,   297,    -1,   297,   190,   297,
      -1,   297,   189,   297,    -1,   297,   188,   297,    -1,   297,
     187,   297,    -1,   297,   186,   297,     8,   297,    -1,    15,
     239,   297,   240,    -1,    16,   239,   297,   240,    -1,    17,
     239,   297,   240,    -1,    18,   239,   297,   240,    -1,    19,
     239,   297,   240,    -1,    20,   239,   297,   240,    -1,    21,
     239,   297,   240,    -1,    22,   239,   297,   240,    -1,    23,
     239,   297,   240,    -1,    25,   239,   297,   240,    -1,    26,
     239,   297,   211,   297,   240,    -1,    27,   239,   297,   240,
      -1,    28,   239,   297,   240,    -1,    29,   239,   297,   240,
      -1,    30,   239,   297,   240,    -1,    31,   239,   297,   240,
      -1,    32,   239,   297,   240,    -1,    33,   239,   297,   240,
      -1,    34,   239,   297,   211,   297,   240,    -1,    35,   239,
     297,   211,   297,   240,    -1,    36,   239,   297,   211,   297,
     240,    -1,    24,   239,   297,   240,    -1,     3,    -1,     9,
      -1,    14,    -1,    10,    -1,    11,    -1,   175,    -1,   176,
      -1,   177,    -1,    71,    -1,    72,    -1,    73,    -1,    -1,
      79,   239,   297,   299,   250,   240,    -1,   169,   239,   310,
     240,    -1,   169,   239,   310,   211,   297,   240,    -1,   315,
      -1,     4,   207,   297,   208,    -1,     4,   205,   297,   206,
      -1,   314,   207,   297,   208,    -1,   314,   205,   297,   206,
      -1,   173,   205,   315,   206,    -1,   174,   205,   311,   206,
      -1,   210,   315,   239,   240,    -1,   315,   238,    -1,     4,
     207,   297,   208,   238,    -1,     4,   205,   297,   206,   238,
      -1,   314,   207,   297,   208,   238,    -1,   314,   205,   297,
     206,   238,    -1,     4,   209,     4,    -1,     4,   207,   297,
     208,   209,     4,    -1,     4,   209,     4,   238,    -1,     4,
     207,   297,   208,   209,     4,   238,    -1,   165,   205,   310,
     211,   297,   206,    -1,    53,   205,   303,   211,   303,   206,
      -1,    54,   239,   310,   211,   310,   240,    -1,    52,   239,
     310,   240,    -1,    55,   239,   310,   211,   310,   240,    -1,
      60,   205,   313,   206,    -1,   301,    -1,   196,   300,    -1,
     195,   300,    -1,   300,   196,   300,    -1,   300,   195,   300,
      -1,   212,   297,   211,   297,   211,   297,   211,   297,   211,
     297,   213,    -1,   212,   297,   211,   297,   211,   297,   211,
     297,   213,    -1,   212,   297,   211,   297,   211,   297,   213,
      -1,   205,   297,   211,   297,   211,   297,   206,    -1,   303,
      -1,   302,   211,   303,    -1,   297,    -1,   305,    -1,   212,
     213,    -1,   212,   306,   213,    -1,   196,   212,   306,   213,
      -1,   297,   197,   212,   306,   213,    -1,   303,    -1,     5,
      -1,   196,   305,    -1,   297,   197,   305,    -1,   297,     8,
     297,    -1,   297,     8,   297,     8,   297,    -1,    83,   212,
     297,   213,    -1,    83,     5,    -1,    86,     5,    -1,    89,
       5,    -1,    91,     5,    -1,   103,    83,     5,    -1,   103,
      86,     5,    -1,   103,    89,     5,    -1,   103,    91,     5,
      -1,   103,    83,   212,   306,   213,    -1,   103,    86,   212,
     306,   213,    -1,   103,    89,   212,   306,   213,    -1,   103,
      91,   212,   306,   213,    -1,    83,   150,    61,   212,   297,
     211,   297,   211,   297,   211,   297,   211,   297,   211,   297,
     213,    -1,    86,   150,    61,   212,   297,   211,   297,   211,
     297,   211,   297,   211,   297,   211,   297,   213,    -1,    89,
     150,    61,   212,   297,   211,   297,   211,   297,   211,   297,
     211,   297,   211,   297,   213,    -1,    91,   150,    61,   212,
     297,   211,   297,   211,   297,   211,   297,   211,   297,   211,
     297,   213,    -1,   261,    -1,   272,    -1,     4,   239,   240,
      -1,   314,   239,   240,    -1,    37,   207,   315,   208,    -1,
      37,   207,   305,   208,    -1,    37,   205,   305,   206,    -1,
      37,   207,   212,   306,   213,   208,    -1,    37,   205,   212,
     306,   213,   206,    -1,     4,   239,   212,   306,   213,   240,
      -1,   314,   239,   212,   306,   213,   240,    -1,    38,   239,
     297,   211,   297,   211,   297,   240,    -1,    39,   239,   297,
     211,   297,   211,   297,   240,    -1,    40,   239,   297,   211,
     297,   211,   297,   211,   297,   211,   297,   211,   297,   240,
      -1,   297,    -1,   305,    -1,   306,   211,   297,    -1,   306,
     211,   305,    -1,   212,   297,   211,   297,   211,   297,   211,
     297,   213,    -1,   212,   297,   211,   297,   211,   297,   213,
      -1,   315,    -1,     4,   209,   147,   209,     4,    -1,   212,
     309,   213,    -1,     4,   207,   297,   208,   209,   148,    -1,
     307,    -1,   309,   211,   307,    -1,   311,    -1,   315,    -1,
       4,   207,   297,   208,    -1,   314,   207,   297,   208,    -1,
       4,   205,   297,   206,    -1,   314,   205,   297,   206,    -1,
       4,   209,     4,    -1,     4,   207,   297,   208,   209,     4,
      -1,     5,    -1,   180,   207,   315,   208,    -1,    64,    -1,
     178,    -1,    69,    -1,   167,   205,   310,   206,    -1,   166,
     205,   310,   211,   310,   206,    -1,   168,   239,   310,   240,
      -1,   168,   239,   310,   211,   310,   240,    -1,    45,   239,
     313,   240,    -1,    46,   205,   310,   206,    -1,    47,   205,
     310,   206,    -1,    48,   205,   310,   211,   310,   211,   310,
     206,    -1,    43,   239,   313,   240,    -1,    57,   239,   310,
     240,    -1,    58,   239,   310,   240,    -1,    59,   239,   310,
     240,    -1,    56,   239,   297,   211,   310,   211,   310,   240,
      -1,    51,   239,   310,   211,   297,   211,   297,   240,    -1,
      51,   239,   310,   211,   297,   240,    -1,    44,   239,   310,
     240,    -1,    44,   239,   310,   211,   306,   240,    -1,    65,
     239,   310,   240,    -1,    66,    -1,    50,   239,   310,   240,
      -1,    49,   239,   310,   240,    -1,    -1,    80,   239,   311,
     312,   252,   240,    -1,   310,    -1,   313,   211,   310,    -1,
       4,   214,   212,   297,   213,    -1,   314,   214,   212,   297,
     213,    -1,     4,    -1,   314,    -1,   181,   207,   310,   208,
      -1
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
    5913,  5917,  5921,  5925,  5929,  5947,  5965,  5973,  5981,  5994,
    5999,  6003,  6007,  6019,  6023,  6035,  6052,  6062,  6066,  6081,
    6086,  6093,  6097,  6110,  6124,  6138,  6152,  6166,  6174,  6185,
    6189,  6193,  6201,  6207,  6213,  6221,  6229,  6236,  6244,  6259,
    6273,  6287,  6299,  6315,  6324,  6333,  6343,  6354,  6362,  6370,
    6374,  6393,  6400,  6406,  6413,  6421,  6420,  6433,  6438,  6444,
    6453,  6466,  6469,  6473
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
  "tModulo", "tHypot", "tList", "tLinSpace", "tLogSpace", "tCatenary",
  "tPrintf", "tError", "tStr", "tSprintf", "tStrCat", "tStrPrefix",
  "tStrRelative", "tStrReplace", "tAbsolutePath", "tDirName", "tStrSub",
  "tStrLen", "tFind", "tStrFind", "tStrCmp", "tStrChoice", "tUpperCase",
  "tLowerCase", "tLowerCaseIn", "tTextAttributes", "tBoundingBox", "tDraw",
  "tSetChanged", "tToday", "tFixRelativePath", "tCurrentDirectory",
  "tSyncModel", "tNewModel", "tOnelabAction", "tOnelabRun", "tCpu",
  "tMemory", "tTotalMemory", "tCreateTopology", "tCreateTopologyNoHoles",
  "tDistanceFunction", "tDefineConstant", "tUndefineConstant",
  "tDefineNumber", "tDefineString", "tSetNumber", "tSetString", "tPoint",
  "tCircle", "tEllipse", "tLine", "tSphere", "tPolarSphere", "tSurface",
  "tSpline", "tVolume", "tCharacteristic", "tLength", "tParametric",
  "tElliptic", "tRefineMesh", "tAdaptMesh", "tRelocateMesh", "tPlane",
  "tRuled", "tTransfinite", "tComplex", "tPhysical", "tCompound",
  "tPeriodic", "tUsing", "tPlugin", "tDegenerated", "tRecursive",
  "tRotate", "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset",
  "tAffine", "tRecombine", "tSmoother", "tSplit", "tDelete", "tCoherence",
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
     435,   436,   437,   438,   439,   440,    63,   441,   442,   443,
     444,    60,    62,   445,   446,    43,    45,    42,    47,    37,
      33,   447,   448,   449,    94,    40,    41,    91,    93,    46,
      35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   215,   216,   216,   217,   217,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   219,   219,   220,   220,   220,   220,   220,
     220,   221,   221,   221,   221,   222,   222,   222,   222,   222,
     222,   223,   223,   224,   224,   226,   227,   225,   228,   228,
     230,   229,   231,   231,   233,   232,   234,   234,   236,   235,
     237,   237,   237,   237,   237,   238,   238,   239,   239,   240,
     240,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   242,   242,   243,   243,   243,   244,   243,   245,
     243,   246,   243,   243,   247,   243,   248,   248,   249,   249,
     249,   250,   250,   251,   251,   251,   252,   252,   253,   253,
     253,   253,   254,   254,   254,   255,   255,   255,   256,   256,
     256,   257,   257,   257,   258,   258,   259,   259,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     261,   261,   261,   261,   261,   261,   261,   261,   262,   262,
     263,   263,   263,   263,   263,   263,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   265,   265,   265,   265,   265,
     266,   266,   267,   268,   268,   268,   268,   268,   268,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   270,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   272,   272,   272,   273,   272,   274,   272,
     275,   272,   276,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   277,   272,   278,   272,   279,   272,   280,
     272,   281,   272,   282,   272,   283,   272,   284,   272,   285,
     272,   286,   286,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   288,
     288,   289,   289,   290,   290,   291,   291,   292,   292,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   294,   294,   294,   295,   295,
     295,   296,   296,   296,   296,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   299,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   300,   300,   300,   300,   300,
     301,   301,   301,   301,   302,   302,   303,   303,   303,   303,
     303,   303,   304,   304,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   306,
     306,   306,   306,   307,   307,   307,   307,   308,   308,   309,
     309,   310,   310,   310,   310,   310,   310,   310,   310,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   312,   311,   313,   313,   314,
     314,   315,   315,   315
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
       4,     4,     6,     6,     6,     6,     8,     8,    14,     1,
       1,     3,     3,     9,     7,     1,     5,     3,     6,     1,
       3,     1,     1,     4,     4,     4,     4,     3,     6,     1,
       4,     1,     1,     1,     4,     6,     4,     6,     4,     4,
       4,     8,     4,     4,     4,     4,     8,     8,     6,     4,
       6,     4,     1,     4,     4,     0,     6,     1,     3,     5,
       5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   561,     0,     0,     0,
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
     562,     0,   417,   561,   529,   418,   420,   421,   419,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   531,
       0,   552,   533,   425,   426,   427,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   422,   423,   424,   532,
       0,     0,     0,     0,    67,    68,     0,     0,   210,     0,
       0,     0,   375,     0,   521,   562,   432,     0,     0,     0,
       0,   250,     0,   252,   253,   248,   249,     0,   254,   255,
     124,   136,    67,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   455,     0,     0,     0,     0,     0,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   561,
       0,   210,   562,     0,     0,   365,     0,     0,     0,     0,
       0,     0,     0,     0,   561,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   496,
     466,   472,     0,   467,   562,   432,     0,     0,     0,     0,
     561,     0,     0,   515,     0,     0,     0,     0,   246,   247,
       0,   561,     0,     0,     0,   264,   265,     0,   210,     0,
     210,   561,     0,   562,     0,   371,     0,     0,    67,    68,
       0,     0,    60,    64,    63,    62,    61,    66,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   378,   377,   379,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
       0,   208,     0,     0,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,   239,     0,     0,   440,   185,     0,   561,     0,   521,
     562,   522,     0,     0,   557,     0,   122,   122,     0,     0,
       0,     0,   509,   510,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   333,   333,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   210,   210,     0,   457,   456,
       0,     0,     0,     0,   210,   210,     0,     0,     0,     0,
       0,     0,     0,   282,     0,   210,     0,     0,     0,     0,
       0,   335,     0,     0,     0,     0,     0,     0,     0,   228,
     366,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,   479,     0,
       0,   480,     0,   481,     0,   482,     0,     0,     0,     0,
       0,     0,   377,   474,     0,   468,     0,     0,     0,   343,
      67,    68,     0,   245,     0,     0,     0,     0,     0,   210,
       0,     0,     0,     0,     0,   268,   267,     0,   233,     0,
     234,     0,     0,     0,   210,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       0,     0,   445,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   428,   555,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    61,     0,   376,    60,
      61,     0,     0,    60,     0,     0,     0,     0,     0,   205,
       0,     0,     0,     0,   211,     0,     0,     0,   393,   392,
     391,   390,   386,   387,   389,   388,   381,   380,   382,   383,
     384,   385,     0,     0,     0,   186,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   362,   363,   364,     0,     0,     0,
       0,   331,     0,     0,     0,   152,   153,     0,   155,   156,
       0,   158,   159,     0,   161,   162,     0,   180,     0,   191,
       0,   197,     0,     0,     0,     0,   172,   210,     0,     0,
       0,     0,     0,   459,   458,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   276,     0,     0,     0,     0,     0,
       0,     0,   346,     0,     0,   229,     0,     0,   225,     0,
       0,     0,   361,   360,     0,     0,     0,     0,     0,   445,
      69,    70,     0,   497,     0,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,     0,     0,   483,     0,
     484,     0,   485,     0,   486,     0,     0,   376,   469,   476,
       0,   382,   475,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,   269,   270,     0,     0,   235,
     237,     0,   563,     0,     0,     0,    60,    61,     0,     0,
      60,    61,     0,     0,     0,     0,    91,    75,     0,   434,
     433,   447,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   416,   404,     0,   406,   407,   408,   409,   410,   411,
     412,     0,     0,     0,   542,     0,   549,   538,   539,   540,
       0,   554,   553,     0,   452,     0,     0,     0,     0,   543,
     544,   545,   454,   551,   141,   146,   114,     0,     0,   534,
       0,   536,     0,   430,   437,   438,   530,     0,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,     0,     0,   439,     0,     0,     0,
       0,   559,     0,     0,    45,     0,     0,     0,    58,     0,
      36,    37,    38,    39,    40,   436,   435,     0,     0,   527,
      25,    23,     0,     0,     0,     0,    26,     0,     0,   240,
     558,    71,   125,    72,   137,     0,     0,     0,   511,   512,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   329,   334,
     332,     0,   342,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   376,   376,   376,     0,     0,     0,     0,     0,
     236,   238,     0,     0,     0,   200,   202,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   311,     0,   273,     0,     0,     0,     0,     0,
       0,   336,   345,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   434,   433,     0,     0,   501,     0,   500,
     499,     0,     0,     0,     0,   478,     0,     0,     0,     0,
       0,     0,     0,   470,     0,     0,   436,   435,     0,     0,
       0,     0,     0,     0,   230,     0,     0,     0,     0,     0,
     232,     0,     0,   372,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   560,     0,     0,   442,     0,   441,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,     0,    89,     0,     0,    77,     0,     0,     0,     0,
      81,   104,   106,     0,     0,   519,     0,   112,     0,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,    31,
     444,   443,   525,   523,    24,     0,     0,   526,   524,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   166,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   170,     0,     0,     0,     0,     0,     0,     0,   340,
       0,     0,   154,     0,   157,     0,   160,     0,   163,     0,
       0,     0,     0,     0,     0,     0,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   317,     0,     0,   316,
       0,   323,     0,   325,     0,   319,     0,   321,     0,   283,
     312,     0,     0,     0,   223,     0,     0,     0,   347,     0,
     227,   226,   367,     0,     0,    32,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
     488,   489,   490,   477,   471,     0,     0,     0,     0,   516,
       0,     0,     0,   259,     0,     0,     0,     0,     0,     0,
       0,    86,     0,    90,     0,     0,    78,     0,    82,     0,
     242,   446,   241,   405,   413,   414,   415,   550,     0,     0,
     548,   450,   451,   453,     0,     0,   429,   142,     0,   556,
     147,   449,   535,   537,   431,     0,     0,     0,    87,     0,
       0,     0,    60,     0,     0,     0,     0,    79,     0,     0,
       0,   517,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,     0,     0,    27,    28,     0,    29,     0,     0,
     126,   133,     0,     0,    73,    74,   168,     0,     0,     0,
       0,     0,     0,   171,     0,     0,   188,   189,     0,     0,
     173,   196,     0,     0,     0,     0,   164,     0,   339,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,     0,     0,     0,     0,   210,   210,     0,   293,     0,
     295,     0,   297,     0,   318,   466,     0,     0,   324,   326,
     320,   322,     0,     0,   277,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   446,   504,   503,   502,
       0,     0,     0,     0,     0,     0,     0,   505,   176,   177,
       0,     0,     0,     0,   115,   119,     0,     0,     0,   373,
       0,     0,     0,    88,     0,     0,     0,    80,     0,   448,
       0,     0,     0,     0,     0,     0,    98,     0,     0,    92,
       0,     0,     0,     0,   109,     0,     0,   110,     0,   520,
     212,   213,   214,   215,     0,     0,    41,     0,     0,     0,
       0,     0,    43,   528,     0,     0,   127,   134,     0,     0,
       0,     0,   167,   174,   175,   179,     0,     0,   190,     0,
       0,   341,     0,   183,     0,     0,   330,   195,   169,   182,
     194,   199,   181,     0,   192,   198,     0,     0,     0,     0,
       0,     0,   463,     0,   462,     0,     0,     0,   284,     0,
       0,   285,     0,     0,   286,     0,     0,     0,     0,     0,
       0,     0,   222,     0,     0,   221,     0,     0,     0,   216,
       0,     0,   344,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   514,     0,   261,   260,     0,     0,     0,
       0,     0,    99,     0,     0,    93,     0,     0,     0,   541,
     547,   546,     0,   143,   145,     0,   148,   149,   150,   100,
     102,    94,    96,   105,   107,     0,   113,     0,    83,    46,
       0,     0,     0,   465,     0,     0,     0,    30,     0,   141,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,     0,   337,   337,     0,   120,   121,   210,     0,
     203,   204,     0,     0,     0,     0,     0,     0,     0,   313,
       0,     0,   210,     0,     0,     0,     0,     0,   207,   206,
     506,   507,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   117,     0,     0,   101,   103,    95,    97,    84,
       0,   509,   510,     0,     0,   518,     0,    42,     0,     0,
       0,    44,    59,     0,     0,     0,   131,   129,   355,   357,
     356,   358,   359,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   328,     0,     0,
       0,   278,     0,     0,   217,     0,     0,     0,     0,     0,
       0,     0,     0,   513,   262,     0,     0,   374,     0,   144,
       0,     0,   151,   111,     0,     0,     0,     0,     0,   128,
     135,   141,   141,     0,     0,     0,     0,     0,   338,   348,
       0,     0,   349,     0,   201,     0,   299,     0,     0,   301,
       0,     0,   303,     0,     0,     0,   314,     0,   274,     0,
     210,     0,     0,     0,     0,     0,     0,     0,     0,   178,
     118,   258,     0,   138,     0,     0,    50,     0,    56,     0,
       0,     0,     0,     0,   165,   193,     0,   352,     0,   353,
     354,   460,   287,     0,     0,   294,   288,     0,     0,   296,
     289,     0,     0,   298,     0,     0,     0,   280,     0,   220,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,   130,     0,     0,     0,     0,
     305,     0,   307,     0,   309,   315,   327,   279,   275,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,   140,
      47,     0,    54,     0,     0,     0,     0,     0,     0,   290,
       0,     0,   291,     0,     0,   292,     0,     0,   224,     0,
     218,     0,     0,     0,     0,     0,     0,    48,     0,     0,
     251,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     281,     0,   508,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,     0,   300,     0,   302,     0,   304,     0,
     219,     0,     0,     0,     0,    49,    51,     0,    52,     0,
       0,     0,     0,     0,     0,   491,   492,   493,   494,     0,
       0,    57,   350,   351,   306,   308,   310,    53,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    91,  1012,    92,    93,   722,  1555,  1561,
    1000,  1214,  1756,  1976,  1001,  1920,  2017,  1002,  1978,  1003,
    1004,  1218,   359,   454,   190,   843,    94,   740,   466,  1689,
    1832,  1831,  1690,   467,  1750,  1182,  1377,  1183,  1380,   774,
     777,   780,   783,  1585,  1430,   704,   308,   430,   431,    97,
      98,    99,   100,   101,   102,   103,   104,   309,  1095,  1859,
    1939,   812,  1609,  1612,  1615,  1893,  1897,  1901,  1960,  1963,
    1966,  1091,  1092,  1258,  1051,   771,   821,  1780,   106,   107,
     108,   109,   310,   192,   954,   519,   263,  1410,   311,   312,
     313,   586,   322,   985,  1206,   464,   459,   955,   465,   343,
     315
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1671
static const yytype_int16 yypact[] =
{
    9864,    16,    55,  9991, -1671, -1671,  4466,    72,     3,  -103,
     -93,    47,   115,   125,   143,   173,   -10,   185,   197,    41,
      59,     2,     2,   -62,    71,    83,    22,   113,   131,    13,
     134,   149,   219,   259,   323,   368,   168,   768,   373,   382,
     189,   386,   607,   246,   -51,   284,   418,   -65,   296,   -78,
     -78,   314,   374,    33,   353,   470,   487,     6,    57,   498,
     523,    74,   615,   629,   640,  6005,   653,   458,   471,   477,
      12,     0, -1671,   481,   520, -1671, -1671,   663,   723,   543,
   -1671,  3821,   552,  6088,    -4,    31, -1671, -1671, -1671,  9723,
     558, -1671, -1671, -1671, -1671, -1671, -1671, -1671, -1671, -1671,
   -1671, -1671, -1671, -1671, -1671, -1671, -1671, -1671,    53, -1671,
    -137,   112, -1671,     8, -1671, -1671, -1671, -1671, -1671,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   593,   625,   638,     2,     2,     2,
       2,   642,     2,     2,     2,     2,     2,     2,   647, -1671,
       2, -1671, -1671, -1671, -1671, -1671,     2,     2,   871,   676,
     684,   688,     2,     2,   692,   700, -1671, -1671, -1671, -1671,
     703,  9723,  9723,  9723,  9119,  9185,    19,    25,   315,   718,
     747,   630, -1671,   767,   921,  -118,   -73,   934,  9723,  5883,
    5883, -1671,  9723, -1671, -1671, -1671, -1671,  5883, -1671, -1671,
   -1671, -1671, -1671, -1671,  4787,    25,  9723,  8921,  9723,  9723,
     730,  9723,  8921,  9723,  9723,   802,  8921,  9723,  9723,  6413,
     810,   771, -1671,  8921,  6005,  6005,  6005,   821,   825,  6005,
    6005,  6005,   830,   831,   835,   843,   853,  6617,  6821,  7025,
     859,  8453,   948,  6413,    12,   886,   891,   -78,   -78,   -78,
    9723,  9723,  -152, -1671,   -40,   -78,   892,   920,   923,  8519,
     128,   -58,   878,   924,   939,  6005,  6005,  6413,   945,    14,
     857, -1671,   935,  1150,  1153, -1671,   949,   957,   958,  6005,
    6005,   953,   964,   970,   641, -1671,   298,     2,     2,     2,
      23,    15,    20,    26,   701,  7229,  9723,  4906, -1671, -1671,
    3605, -1671,  1172, -1671,   -81,   583,  1173,  9723,  9723,  9723,
    -108,  9723,   968, -1671,  1031,  9723,  9723,  9723, -1671, -1671,
    9723,   973,  1182,  1183,   981, -1671, -1671,  1191, -1671,  1192,
   -1671,    94,  4496,   215,  5883, -1671,  6413,  6413,  9388,  9454,
     987,   989,  4787, -1671, -1671, -1671, -1671, -1671, -1671,  6413,
    1196,  1005,  9723,  9723,  1209,  9723,  9723,  9723,  9723,  9723,
    9723,  9723,  9723,  9723,  9723,  9723,  9723,  9723,  9723,  9723,
    9723,  9723,  9723,  9723,  9723,  9723,  9723,  5883,  5883,  5883,
    5883,  5883,  5883,  5883,  5883,  5883,  5883,  6413,  5883,  5883,
    9723,  5883,  5883,  5883,  5883,  5883,  9723,  4787,  9723,  5883,
    5883,  5883,  5883,  5883,    25,  4787,    25,  1011,  1011,  1011,
     100, 11782,   183, 11391,   144,  1012,  1215,     2,  1015, -1671,
    1010,  3589,  9723,  8921, -1671,  9723,  9723,  9723,  9723,  9723,
    9723,  9723,  9723,  9723,  9723,  9723,  9723,  9723,  9723,  9723,
   -1671, -1671,  9723,  9723, -1671, -1671,   898,   601,   -12, -1671,
     251, -1671,   114,  9617, -1671,   253,   239,   389,  1017,  1019,
   11803,  8921,  3936, -1671,   340, 11824, 11845,  9723, 11866,   454,
   11887, 11908,  9723,   515, 11929, 11950,  1224,  9723,  9723,   529,
    1226,  1227,  1228,  9723,  9723,  1229,  1230,  1230,  9723,  8723,
    8723,  8723,  8723,  9723,  1233,  9723,  1235,  9723,  1236,  8921,
    8921,  8413,  1029,  1237,  1033, -1671, -1671,   -54, -1671, -1671,
    9987, 10013,   -78,   -78,   315,   315,   -43,  9723,  9723,  9723,
    8519,  8519,  9723,  3589,   162, -1671,  9723,  9723,  9723,  9723,
    9723,  1239,  1241,  1242,  9723,  1245,  9723,  9723,  1736, -1671,
   -1671,  8921,  8921,  8921,  1249,  1250,  9723,  9723,  9723,  9723,
    9723,  1255,   147,  7433,  7637,  9723,  9723,  9723, -1671,  1200,
    9723, -1671,  1202, -1671,  1204, -1671,  1208,    37,    40,    43,
      44,  8921,  1011, -1671, 11971, -1671,   535,  9723,  7841, -1671,
    9723,  9723,   381, -1671, 11992, 12013, 12034,  1126, 10039, -1671,
    1060,  3985, 12055, 12076, 11414, -1671, -1671,  8921, -1671,  1869,
   -1671,  2213,  9723,  9723, -1671,  9723,  9723,  1066,  1069,   555,
     256, 12097,   270, 11437,  9723,  8921,  1270,  1271, -1671,  9723,
   12118, 11460,   -14,  8481,  8481,  8481,  8481,  8481,  8481,  8481,
    8481,  8481,  8481,  8481, 10065,  8481,  8481,  8481,  8481,  8481,
    8481,  8481, 10091, 10117, 10143,   210,   273,   210,  1072,  1073,
    1075,   634,   634,  1076,   634,  1077,  1078,  1079, 10169,   634,
     634,   634,   285,   634, 12664, -1671,   919,  1080,  1081,  1074,
     513,   596,  1089,  1091,  1090,  1240,  1256,  6413,   167,  1258,
    1259,  6413,   107,  4787,  9723,  1278,  1299,    17,   634, -1671,
     -30,    35,    29,    95, -1671,  4183,   650,  4004,  2457,  2478,
    1576,  1576,   557,   557,   557,   557,   565,   565,  1011,  1011,
    1011,  1011,    -2, 12139, 11483, -1671,  9723,  9723,  1301,    18,
    8921,  9723,  9723,  1303,  8921,  9723,  1304,  5883,  1319, -1671,
      25,  1324,  5883,  9723,  4787,  1300,  8921,  8921,  1181,  1325,
    1326, 12160,  1327,  1185,  1329,  1330, 12181,  1193,  1332,  1335,
    9723, 12202,  4211,  1132, -1671, -1671, -1671, 12223, 12244,  9723,
    6413,  1341,  1342, 12265,  1143, 12664,  1139,  1148, 12664,  1144,
    1151, 12664,  1145,  1152, 12664,  1149, 12286, -1671, 12307, -1671,
   12328, -1671,   657,   664,  8921,  1155, -1671, -1671,  2386,  2451,
     -78,  9723,  9723, -1671, -1671,  1146,  1154,  8519, 10195, 10221,
   10247,  9575,   413,   -78,  2653, 12349,  4361, 12370, 12391, 12412,
    9723,  1355, -1671,  9723, 12433, -1671, 11506, 11529, -1671,   671,
     679,   683, -1671, -1671, 11552, 11575, 10273, 12454, 11598,   583,
   -1671, -1671,  8921, -1671,  8921,  3936,  1162,  8921,  1158,   489,
   10299, 10325, 10351,  1161,  4403,  1177,  1178,  1179, -1671,  8921,
   -1671,  8921, -1671,  8921, -1671,  8921,   687, -1671, -1671,  4056,
    8921,  1011, -1671, 12475, 11621,  8921, -1671,  1363,  1385,  1387,
    1186,  9723,  2889,  9723,  9723, -1671, -1671,     7,   695, -1671,
   -1671,  2917, -1671,  1184,  6413,  1392,  1356,  1357,  6413,   167,
    1358,  1359,  6413,   167,  4843,   715, -1671, -1671, 11644,   212,
    1160, -1671, -1671, -1671, -1671, -1671, -1671, -1671, -1671, -1671,
   -1671, -1671, -1671,  9723, -1671, -1671, -1671, -1671, -1671, -1671,
   -1671,  9723,  9723,  9723, -1671,  8921, -1671, -1671, -1671, -1671,
    5883, -1671, -1671,  9723, -1671,  6413,  5883,  5883,  5883, -1671,
   -1671, -1671, -1671, -1671, -1671, -1671, -1671,  9723,  5883, -1671,
    5883, -1671,  9723, -1671, -1671, -1671, -1671,     2,     2,  1398,
   -1671,  9723,  1399,     2,     2,  1400,    30,  9723,  1401,  1402,
    1125, -1671,  1403,  1205,    12,  1408, -1671,  8921,  8921,  8921,
    8921, -1671,   634,  9723, -1671,  1210,  1213,  1197, -1671,  1413,
   -1671, -1671, -1671, -1671, -1671,   297,   299, 12496, 11667, -1671,
   -1671,  1231,  5883,   366, 12517, 11690, -1671,   445, 10377, -1671,
   -1671, -1671,    62, -1671, -1671,  8481,   634,   -78,  3936, -1671,
     842,  6413,  6413,  1414,  6413,   845,  6413,  6413,  1415,  1336,
    6413,  6413,  1189,  1424,  1425,  8921,  1426,  1427,  2244, -1671,
   -1671,  1429, -1671,  1433,   291,  9723,   291,  9723,   291,  9723,
     291,  9723,  1439,  1440,  1442,  1443,  1444,   728,  1416,  3099,
   -1671, -1671,   208, 10403, 10429, -1671, -1671,  5055,  -130,   -78,
     -78,   -78,  1448,  9657,  1244,  1452,  1243,    34,    45,    46,
      50,   361, -1671,   237, -1671,   413,  1453,  1455,  1456,  1458,
    1459, 12664, -1671,  1435,  1247,  1461,  1469,  1470,  1373,  1475,
    1471,  1480,  9723,   583,   169,   735,   740, -1671,   745, -1671,
   -1671,  9723,  9723,  9723,  9723, -1671,  9723,  9723,  9723,   749,
     752,   758,   761, -1671,  9723,   764,   583,   583,   769,  6413,
    6413,  6413,  1484, 10455, -1671,  4128,   514,  1485,  1487,  1281,
   -1671,  6413,  1280, -1671,     2,     2,  1488,  9723,  1489,     2,
       2,  1491,  9723,  1492, -1671,   634,  1493, -1671,  1496, -1671,
    1495,  8481,  8481,  8481,  8481,   627,  1292,  9348,  1298,   634,
     634,  1294,   668,   677, 12538,  1302,   634,  8481,  1686,  5883,
   -1671,  1936, -1671,  1686,  5883, -1671,   179,  1297,  1502,  1984,
   -1671, -1671, -1671,    12,  9723, -1671,   777, -1671,   778,   788,
     789,   792,   291, 12664,  1305,  9723,  9723,  6413,  1307, -1671,
   -1671, -1671, -1671,  1308, -1671,  1505,    68, -1671, -1671,  1506,
    9723,  5525,  1310,  1306,  1507,  1514,     5,  1309,  1315,  1423,
    1423,  6413,  1517,  1316,  1320,  1525,  1527,  6413,  1322,  1529,
    1530, -1671,  1532,  6413,   793,  6413,  6413,  1535,  1537, -1671,
    6413,  6413, 12664,  6413, 12664,  6413, 12664,  6413, 12664,  6413,
    6413,  6413,  1333,  1334,  1534,   895, -1671,  9723,  9723,  9723,
    1337,  1339,  -123,  -120,  -116,  1345, -1671,  2060,  6413, -1671,
    9723, -1671,  1542, -1671,  1547, -1671,  1548, -1671,  1549, -1671,
   -1671,  8519,   482,  6209, -1671,  1349,  1352,  8045, -1671,  8921,
   -1671, -1671, -1671,  1353,  9723, -1671, -1671, 11713,  1553,   634,
    1364,  1361, 10481, 10507, 10533, 10559, 10585, 10611, 10637, -1671,
   -1671, -1671, -1671, 12664, -1671,   634,  1565,  1570,  1431, -1671,
    9723,  9723,  9723, -1671,  1572,   988,  4787,  1369,  1577,  1686,
    5883, -1671,  2312, -1671,  1686,  5883, -1671,  2423, -1671,   291,
   -1671,   408, -1671, -1671, -1671, -1671, -1671, -1671,  5883,  9723,
   -1671, -1671, -1671, -1671,  5883,  1578, -1671, -1671,     9, -1671,
   -1671, -1671, -1671, -1671, -1671,  1581,   210,   210, -1671,  1582,
     210,   210,  4787,  9723,  1583,  1580,    17, -1671,  1586, 11736,
      12, -1671,  1587,  1588,  1589,  1590,  6413,  9723, 10663, 10689,
     800, -1671,  9723,  1593, -1671, -1671,  5883, -1671, 10715,  5117,
   12664, -1671,  1595,  1596, -1671, -1671, -1671,  9723,  9723,   -78,
    1599,  1601,  1602, -1671,  9723,  9723, -1671, -1671,  1603,  9723,
   -1671, -1671,  1606,  1607,  1389,  1608,  1462,  9723, -1671,  1610,
    1611,  1612,  1613,  1629,  1631,   962,  1632,  8921,  8921,  9723,
   -1671,  8723,  5258, 12559,  3787,   315,   315,   -78,  1634,   -78,
    1635,   -78,  1636,  9723, -1671,   584,  1432, 12580, -1671, -1671,
   -1671, -1671,  5554,   250, -1671,  1639,  4695,  1640,  6413,   -78,
    4695,  1641,   803,  9723,  2681,  1642,   583, -1671, -1671, -1671,
    9723,  9723,  9723,  9723,  9723,  9723,  9723, -1671, -1671, -1671,
    6413,  4027,   725, 12601, -1671, -1671,  5597,  1445,  6413, -1671,
    1644,   210,   210, -1671,  1645,   210,   210, -1671,  6413, -1671,
    1449,  8481,   634,  5321,  5801,  4787, -1671,  1651,  1652, -1671,
    1655,  1657,  1658,  2883, -1671,  1659,  1661, -1671,  1464, -1671,
   -1671, -1671, -1671, -1671,  1665,   530, 12664,  9723,  9723,  6413,
    1466,   807, 12664, -1671,  1673,  9723, -1671, -1671,  1468,  1472,
    5703,  6146,   599, -1671, -1671, -1671,  6350,  6554, -1671,  6758,
    1660, -1671,  6413, -1671,  1605,  1676, 12664, -1671, -1671, -1671,
   -1671, -1671, -1671,  1474, -1671, -1671,   811,   812,  9079,  3022,
    1687,  1482, -1671,  9723, -1671,  1483,  1490,   274, -1671,  1486,
     287, -1671,  1494,   341, -1671,  1497, 11759,  1689,  6413,  1690,
    1498,  9723, -1671,  8249,   346, -1671,   828,   360,   380, -1671,
    1695,  6962, -1671, -1671,  8481,  8481, 10741, 10767, 10793, 10819,
   10845,  1538,  9723, -1671,  9723, -1671, -1671,  8921,  3255,  1698,
    4787,  1500, -1671,  1699,  1701, -1671,  1702,  1708,  1710, -1671,
   -1671, -1671,  4906, -1671, -1671,  5883, 12664, -1671, -1671, -1671,
   -1671, -1671, -1671, -1671, -1671,    12, -1671,  1569, -1671, -1671,
    9723, 10871, 10897, -1671,  6413,  9723,  1716, -1671, 10923, -1671,
   -1671,  6413,  6413,  1718,  1732,  1733,  1734,  1735,  1740,   832,
    1541, -1671,  6413,   452,   755,  8921, -1671, -1671,   315,  4155,
   -1671, -1671,  8519,   413,  8519,   413,  8519,   413,  1741, -1671,
     833,  6413, -1671,  7166,   -78,  1748,  8921,   -78, -1671, -1671,
   -1671, -1671,  9723,  9723,  9723,  9723,  9723,  9723,  7370,  7574,
     836, -1671, -1671,  1551,  1752, -1671, -1671, -1671, -1671, -1671,
     840,  3317,  1753,   841,  1755, -1671,  1550, 12664,  9723,  9723,
     844, 12664, -1671,  9723,   848,   852, -1671, -1671, -1671, -1671,
   -1671, -1671, -1671, -1671,  1552,  9723,   861,  1566,   -78,  6413,
    1757,  1567,   -78,  1775,   865,  1546,  9723, -1671,  7778,   387,
     547,  7982,   406,  1041,  8186,   410,  1311, -1671,  6413,  1776,
    1671,  3289,  1574,   447, -1671,   868,   459, 10949, 10975, 11001,
   11027, 11053,  3390, -1671, -1671,  1778,  1782, -1671,  9723, -1671,
    4787,    25, -1671, -1671,  9723, 12622, 11079,    52, 11105, -1671,
   -1671, -1671, -1671,  9723,  8305,  1784,   -78,    58, -1671, -1671,
     -78,    75, -1671,  1785, -1671,  8371,  1786,  9723,  1787,  1790,
    9723,  1792,  1793,  9723,  1795,  1592, -1671,  9723, -1671,   413,
   -1671,  8921,  1800,  8249,  9723,  9723,  9723,  9723,  9723, -1671,
   -1671, -1671,  3555, -1671,  1609,   888, -1671,  9723, -1671,  6413,
    9723,   908,   909, 11131, -1671, -1671,   464, -1671,   466, -1671,
   -1671, -1671, -1671,  1600,  8618, -1671, -1671,  1604,  8646, -1671,
   -1671,  1617,  8674, -1671,  1807,  3449,  1347,  3321,   913, -1671,
     519,   914, 11157, 11183, 11209, 11235, 11261,  4787,  1625,  1809,
    1620, 12643,   917,  8858, -1671, -1671,  9723,   -78,   -78,   413,
    1811,   413,  1827,   413,  1828, -1671, -1671, -1671, -1671,   413,
    1831,  8921,  1835,  9723,  9723,  9723,  9723,  9723, -1671, -1671,
   -1671,  5883, -1671,  1630,  1839,  8971,   521,   527,  1441, -1671,
    1637,  1543, -1671,  1638,  1594, -1671,  1647,  1677, -1671,   928,
   -1671,  8481, 11287, 11313, 11339, 11365,   929, -1671,  1649,  6413,
   -1671,  1840,  9723,  9723,  1841,   413,  1842,   413,  1850,   413,
   -1671,  1851, -1671,  9723,  9723,  9723,  9723,  5883,  1856,  5883,
     932, -1671,  9037,  9144, -1671,  1771, -1671,  1789, -1671,  1872,
   -1671,  9240,  9306,  9413,  9509, -1671, -1671,   944, -1671,  1857,
    1859,  1862,  1863,  1864,  1865, -1671, -1671, -1671, -1671,  5883,
    1866, -1671, -1671, -1671, -1671, -1671, -1671, -1671, -1671
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1671, -1671, -1671, -1671,   648, -1671, -1671, -1671, -1671,    49,
   -1671, -1671, -1671, -1671, -1671, -1671, -1671, -1671, -1671, -1671,
   -1671, -1671,  -309,   157,  3913,  3269, -1671,  1417, -1671, -1671,
   -1671, -1671, -1671, -1671, -1671, -1670, -1671,   193, -1671, -1671,
   -1671, -1671, -1671, -1671,   635,  1883,     4,  -516,  -254, -1671,
   -1671, -1671, -1671, -1671, -1671, -1671, -1671,  1884, -1671, -1671,
   -1671, -1671, -1671, -1671, -1671, -1671, -1671, -1671, -1671, -1671,
   -1671,  -912,  -997, -1671, -1671,  1394, -1671,   195, -1671, -1671,
   -1671, -1671,  1837, -1671, -1671,    73, -1671, -1482,  2588,  -131,
    2300,  -176,  -249,   493, -1671,   122,    65, -1671,  -357,    -3,
     236
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -529
static const yytype_int16 yytable[] =
{
     110,   337,   994,   195,   324,   514,  1626,    96,   805,   806,
     279,  1426,   361,  1534,  1147,   533,   320,   225,   545,  1764,
     571,   983,     4,   424,  1010,   573,   220,   548,   568,   331,
     655,   575,   657,   225,  1196,   250,   339,   271,   251,   220,
    1291,   474,   858,   522,   523,   860,   479,   672,   862,   864,
     483,  1293,  1295,   201,   282,     5,  1297,   489,  1878,   345,
     524,   284,   314,   285,  1887,   522,   523,   282,   348,  1231,
     349,   194,   522,   523,  1415,   522,   523,   350,   282,   522,
     523,  1889,   254,  1281,   609,   197,   611,   452,  1467,   453,
    1468,  1469,   198,  1470,  1300,  1471,   350,  1472,   255,   256,
    1699,   597,   199,   490,   491,   492,   189,   685,   495,   496,
     497,   687,   200,   691,   970,   694,   272,   258,   259,   352,
     273,   203,   262,   264,   590,   270,   591,   260,   193,   357,
     358,   204,   274,   350,   261,   995,   996,   997,   998,  -522,
     286,   522,   523,   216,   541,   542,   332,   536,   336,   205,
     217,   693,   522,   523,   537,   522,   523,   800,   554,   555,
     289,  1881,  1882,   290,   280,   572,   425,   426,   807,  1292,
     574,  1535,   525,   569,   970,   216,   576,  1197,  1198,   206,
    1294,  1296,   987,  1302,   282,  1298,  1392,    90,   357,   358,
     689,   208,   429,    90,   729,   207,   460,   460,  -527,   730,
     522,   523,  1760,   209,   460,   325,    90,   212,   338,   213,
    1011,   999,   282,   362,   314,   363,  1148,   364,   281,   314,
    1776,   546,   189,   314,   321,   226,   314,   221,   189,   984,
     314,   314,   314,   314,   222,   570,   314,   314,   314,   111,
     221,   989,   196,   340,   314,   314,   314,   988,   210,   859,
     314,   282,   861,   522,   523,   863,   865,   706,   346,   202,
    1011,   798,   799,   896,  1879,   347,   211,  1232,   360,  1233,
     522,   523,   314,   314,   314,   239,   218,   900,   240,   468,
     241,   814,   353,   354,   355,   686,   314,   314,   219,   353,
     354,   355,   356,   283,   353,   354,   355,   356,   970,   612,
     228,   613,   314,   561,   314,  1300,   323,   990,   189,   357,
     358,   898,   229,   902,   357,   358,   976,   333,   223,   428,
     733,   458,   462,   522,   523,   734,   353,   354,   355,   356,
     517,   518,   247,   792,   793,   248,   224,   249,   526,   227,
     535,   460,   534,   314,   314,   882,   357,   358,   230,   353,
     354,   355,   356,   840,   228,   841,   314,   522,   523,   842,
     891,   353,   354,   355,   356,   353,   354,   355,   690,   357,
     358,   357,   358,   813,   232,   829,   830,   831,  1318,   971,
     233,   357,   358,   977,   460,   460,   460,   460,   460,   460,
     460,   460,   460,   460,   314,   460,   460,  1922,   460,   460,
     460,   460,   460,   522,   523,   866,   460,   460,   460,   460,
     460,   282,   231,   282,   357,   358,   840,   626,   841,  1277,
     615,   737,   616,   427,  -525,    48,    49,    50,    51,   350,
     314,   888,   522,   523,    56,   461,   461,    59,   353,   354,
     355,   897,   275,   461,   276,   522,   523,   738,  1301,   905,
     739,   469,   353,   354,   355,   901,   731,   266,   732,   736,
     267,  1621,   237,   268,   737,   350,   617,  1082,   314,   522,
     523,   238,   675,   353,   354,   355,   356,   242,  1083,   840,
     683,   841,   522,   523,   935,  1712,  1084,  1085,  1086,   252,
     323,   952,  1087,  1088,  1089,  1090,   737,  2000,  1714,   357,
     358,   357,   358,   563,   253,   564,   314,   314,   257,  -526,
     656,  -524,   658,   659,   660,   661,   662,   663,   664,  1082,
     666,   667,  1342,   669,   670,   671,   265,   673,   429,   429,
    1083,   677,   678,   679,   680,   681,   522,   523,  1084,  1085,
    1086,   522,   523,  1069,  1087,  1088,  1089,  1090,   314,   314,
     314,   747,  1716,   748,  1013,   522,   523,  1724,  1017,   277,
     314,   314,  1777,  1778,   776,   779,   782,   785,  1779,   258,
     259,  1726,  1226,   278,  1299,   522,   523,   747,   314,   260,
     461,   695,   522,   523,   287,   314,   269,   840,  1082,   841,
    1157,  1727,   587,   875,  1162,   803,   804,   741,  1847,  1083,
     739,   522,   523,   518,   314,   522,   523,  1084,  1085,  1086,
     357,   358,   288,  1087,  1088,  1089,  1090,  1850,  1067,   291,
    -528,  1853,   314,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   292,   461,   461,   434,   461,   461,   461,
     461,   461,   522,   523,   293,   461,   461,   461,   461,   461,
     682,  1229,   684,  1082,   522,   523,   747,   316,  1861,   522,
     523,   522,   523,   317,  1083,   747,  1115,   753,  1116,   328,
    1863,  1118,  1084,  1085,  1086,  1927,   318,  1928,  1087,  1088,
    1089,  1090,   319,  1129,   314,  1130,   326,  1131,   314,  1132,
     243,   357,   358,   244,  1135,  1484,   245,  1120,   246,  1138,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   522,   523,   522,   523,   449,   840,
    1343,   841,   522,   523,   960,   327,   747,   314,   757,   329,
    1941,   314,  1982,  1644,   460,  1205,  1679,   282,  1983,   460,
     747,  1680,   763,   314,   314,  1261,   747,  1263,   868,  1265,
     330,  1267,   444,   445,   446,   447,   448,   334,   979,  1175,
    1848,   449,   446,   447,   448,   344,   894,   314,   895,   449,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   588,   447,   448,   577,   357,   358,   578,   449,   911,
     579,   314,   580,  1300,   522,   523,  1300,  1617,   390,  1300,
     849,  1790,   840,  1793,   841,  1796,   726,   962,   727,  1026,
     728,  1208,  1209,  1210,  1211,   189,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     391,  1386,  1387,   840,   449,   841,  1390,  1391,   747,   314,
     840,   314,   841,   392,   314,   972,   559,   397,   560,   978,
     561,   234,   404,   188,   235,   189,   314,   236,   314,  1020,
     314,   747,   314,   992,  1024,  1781,  1782,   314,   747,  1254,
    1065,  1779,   314,  1072,   840,   747,   841,  1066,   408,  1375,
    1078,   409,   747,   840,  1107,   841,  1093,  1393,  1378,   410,
     747,   314,  1108,   411,   747,   314,  1109,   414,   747,   314,
    1133,  1460,  1461,  1406,   725,   415,   747,   460,  1149,  1300,
     416,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   956,   747,   451,  1165,   449,
     432,  1237,   314,  1238,  1243,   477,  1244,   460,  1645,   747,
     455,  1274,   314,   460,   460,   460,   747,  1906,  1319,  1605,
    1606,   747,   512,  1320,  1398,   460,   747,   460,  1321,   433,
     747,  1300,  1329,   747,  1300,  1330,  1593,  1300,  1594,   747,
    1300,  1331,   747,   461,  1332,   747,  1022,  1334,   461,   450,
     747,   282,  1335,   488,   314,   314,   314,   314,  1400,   747,
    1401,  1402,  1521,  1522,  1515,  1516,   911,  1525,  1526,   747,
     747,  1403,  1404,   747,   747,  1405,  1444,   482,  1300,   460,
    1300,  1559,  1300,  1560,   747,   487,  1630,  1958,  1685,  1961,
    1686,  1964,   747,   747,  1703,  1704,   493,  1967,   314,   314,
     494,   314,  1170,   314,   314,   498,   499,   314,   314,  1559,
     500,  1725,   314,  1559,  1798,  1774,  1799,   747,   501,  1815,
    1528,  1818,   737,  1819,  1822,  1559,  1158,  1827,   502,  1375,
    1163,  1829,  1176,  1378,   547,  1830,  1167,  1169,  1179,  1180,
    1181,   509,  1559,  2005,  1835,  2007,   747,  2009,  1843,   747,
    1185,  1862,  1186,   538,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   515,  1685,
    1236,  1919,   449,   516,   527,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,  1375,
    1375,  1924,  1925,   449,   747,   747,  1940,  1942,  1559,   539,
    1953,  1202,   528,  1492,  1225,   529,   314,   314,   314,   747,
    1997,  1991,  1998,  1559,   540,  2019,   461,  1082,   314,   350,
     544,  1549,  1282,  1283,  1284,  2029,   549,  2030,  1083,   550,
     556,   551,  1220,  1221,   457,   114,  1084,  1085,  1086,   552,
     553,   557,  1087,  1088,  1089,  1090,   461,   558,   589,   593,
     599,   600,   461,   461,   461,   460,   460,   189,   605,   606,
     460,   460,  1785,   607,   461,  1251,   461,   608,   610,   624,
     282,   625,   628,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   629,   632,   314,   449,   154,   155,   156,   157,
     323,   696,   697,   699,   159,   160,   161,   188,   743,   162,
     744,   760,   764,   765,   766,   795,   769,   770,   314,   787,
     167,   789,   791,   796,   314,   797,   820,   822,   461,   823,
     314,   825,   314,   314,  1851,   832,   833,   314,   314,   839,
     314,   853,   314,   855,   314,   856,   314,   314,   314,   857,
    1167,  1169,   883,   880,   892,   893,   906,   907,   938,   939,
     959,  1596,  1597,   967,   981,   314,   940,   943,   945,   946,
     947,   957,   958,  1220,  1221,   964,  1421,   965,   966,   968,
     314,   973,   974,   982,   314,  1009,   314,  1027,  1753,  1016,
    1019,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,  1021,   170,   171,   172,   449,
    1023,  1030,  1031,  1032,  1034,  1035,  1036,  1037,   179,  1040,
     180,    90,  1041,  1039,  1045,  1050,   460,   460,  1052,  1054,
    1055,   460,   460,  1394,  1056,  1057,  1059,  1058,  1060,  1075,
    1061,  1102,   357,   358,  1068,   460,  1119,  1076,  1117,  1168,
    1139,   460,  -523,  1124,  1483,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,  1126,
    1127,  1128,  1140,   449,  1141,  1142,  1151,   282,  1153,  1154,
    1155,  1159,  1160,   314,  1190,  1192,  1195,  1200,  1201,  1217,
    1203,  1517,  1204,   460,  1207,  1215,   314,  1082,  1216,  1219,
    1275,  1241,  1247,  1224,   461,   461,  1754,  1248,  1083,   461,
     461,  1252,  1253,  1255,  1256,  1259,  1084,  1085,  1086,   323,
    1260,  1308,  1087,  1088,  1089,  1090,  1269,  1270,  1290,  1271,
    1272,  1273,  1285,  1082,   314,   314,  1288,  1542,  1289,  1309,
    1303,  1304,  1313,  1305,  1083,  1306,  1307,  1310,  1801,   429,
     429,  1740,  1084,  1085,  1086,  1311,  1312,  1315,  1087,  1088,
    1089,  1090,  1314,   314,  1567,   314,  1316,   314,  1339,  1344,
    1530,  1345,  1346,  1348,  1351,  1353,  1532,  1356,  1358,  1360,
    1361,  1362,  1572,  1368,  1371,  1374,  1395,   314,  1382,  1396,
    1407,  1414,  1417,  1424,  1423,   314,  1422,  1413,  1529,  1412,
    1425,  1427,  1429,  1433,  1854,   314,  1600,  1428,  1434,  1784,
     314,  1436,  1435,  1437,  1439,  1440,  1441,  1442,  1564,  1447,
    1607,  1459,  1610,  1448,  1613,  1457,  1458,  1082,  1478,  1465,
    1805,  1466,  1473,  1479,  1480,  1481,   314,  1496,  1083,  1624,
    1937,  1488,  1627,  1628,  1489,  1493,  1084,  1085,  1086,  1499,
    1498,  1508,  1087,  1088,  1089,  1090,  1509,  1510,  1514,   314,
    1518,  1649,  1533,  1519,  1545,   461,   461,  1536,  1539,  1544,
     461,   461,  1547,  1550,  1551,  1552,  1553,  1563,  1664,  1667,
    1668,  1582,  1568,  1569,   461,  1573,  1907,  1574,  1575,  1578,
     461,  1580,  1584,  1581,  1583,   314,  1587,  1588,  1589,  1590,
     314,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,  1591,   323,  1592,  1595,   449,
    1608,  1611,  1614,  1618,   314,  1622,  1625,  1629,  1633,  1082,
    1652,  1655,   461,  1529,  1984,  1659,  1650,  1669,  1670,   314,
    1083,  1671,   460,  1672,  1673,  1698,  1675,  1676,  1084,  1085,
    1086,  1678,   282,  1677,  1087,  1088,  1089,  1090,  1684,  1687,
    1691,   314,  1701,  1737,  1692,  1908,  1702,  1911,   314,   314,
     457,   114,  1700,  1707,  1708,  1719,  1710,  1721,  1713,   314,
    1082,  1728,   314,  1711,  1742,  1745,  1715,  1746,  1747,  1717,
    1722,  1083,   429,  1744,  1748,  1743,  1749,  1755,   314,  1084,
    1085,  1086,  1762,   314,  1768,  1087,  1088,  1089,  1090,   141,
     142,   143,   144,   145,   146,   147,   148,   149,  1769,  1770,
    1771,  1772,   154,   155,   156,   157,  1773,  1797,     7,     8,
     159,   160,   161,  1775,  1804,   162,  1986,  1816,  1817,  1844,
    1821,  1823,  1824,  1839,  1833,  1969,   167,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   314,  1857,  1836,  1840,
     449,  1842,  1856,  1082,  1870,  1789,  1860,  1792,  1871,  1795,
    1885,  1890,  1892,  1895,  1083,   314,  1896,  1803,  1899,  1900,
    1806,  1903,  1084,  1085,  1086,  1904,  1909,  1988,  1087,  1088,
    1089,  1090,  1929,  1935,  1918,  1950,  1931,  1959,   282,   700,
      24,    25,   701,    27,    28,   702,    30,   703,    32,  1933,
      33,  1949,  1951,  1962,  1965,    38,    39,  1968,    41,    42,
      43,  1970,  1979,   191,    46,  1980,  2001,  2004,  2006,  1985,
    1987,  1837,   170,   171,   172,  1841,  2008,  2010,   314,  1989,
     314,  1999,  2016,  2031,   179,  2032,   180,    90,  2033,  2034,
    2035,  2036,  2038,  1875,  1416,  1431,   314,  1082,    67,    68,
      69,     7,     8,  1765,   742,  1873,    95,   105,  1083,  1546,
    1990,   772,   840,     0,   841,  1082,  1084,  1085,  1086,  1783,
       0,   461,  1087,  1088,  1089,  1090,  1083,     0,     0,  1886,
       0,   323,     0,  1888,  1084,  1085,  1086,     0,     0,     0,
    1087,  1088,  1089,  1090,     0,     0,   342,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1910,     0,   314,     0,
       0,     0,  1388,     0,     0,     0,     0,     0,   460,   828,
       0,     0,   700,    24,    25,   701,    27,    28,   702,    30,
     703,    32,     0,    33,     0,     0,     0,     0,    38,    39,
       0,    41,    42,    43,     0,     0,   314,    46,  1082,     0,
       0,     0,  1948,     0,  2022,     0,     0,     0,     0,  1083,
    1397,     0,     0,     0,   460,     0,   460,  1084,  1085,  1086,
    1956,  1957,  2023,  1087,  1088,  1089,  1090,     0,     0,     0,
       0,    67,    68,    69,     0,     0,     0,     0,   417,   418,
     419,   421,   423,     0,     0,     0,   460,     0,     0,     0,
       0,     0,     0,     0,     0,   456,     0,     0,     0,   463,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   470,   472,   475,   476,  1874,   478,   472,
     480,   481,     0,   472,   484,   485,  1474,     0,     0,     0,
     472,     0,     0,  1977,     0,     0,     0,     0,     0,     0,
       0,     0,   889,     0,     0,  2024,     0,     0,   511,     0,
       0,     0,     0,     0,     0,     0,     0,   520,   521,     0,
       0,     0,     0,     0,     0,     0,   521,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2015,
       0,  2018,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     0,     0,     0,     0,
     449,     0,   582,   584,   472,     0,     0,     0,     0,     0,
       0,  2037,     0,     0,   594,   595,   596,     0,   598,     0,
       0,     0,   601,   602,   603,     0,     0,   604,     0,     0,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,     0,   621,   623,   461,   449,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   630,
     631,     0,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,   653,   654,     0,     7,     8,     0,     0,     0,
       0,     0,     0,   461,     0,   461,     0,   668,     0,     0,
       0,     0,     0,   674,     0,   676,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
       0,     0,     0,     0,   449,   461,     0,     0,     0,   705,
     472,     0,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,     0,     0,   723,
     724,     0,     0,     0,     0,     0,   700,    24,    25,   701,
      27,    28,   702,    30,   703,    32,     0,    33,   582,     0,
       0,     0,    38,    39,   751,    41,    42,    43,  1523,   756,
       0,    46,     0,     0,   761,   762,     0,     0,     0,     0,
     767,   768,     0,     0,     0,   773,   775,   778,   781,   784,
     786,     0,   788,     0,   790,     0,   472,   472,     0,     0,
    1257,     0,     0,     0,     0,    67,    68,    69,     0,     0,
       0,     0,     0,     0,   808,   809,   810,   417,   418,   811,
       0,     0,     0,   815,   816,   817,   818,   819,     0,     0,
       0,   824,     0,   826,   827,     0,     0,     0,   472,   472,
     472,     0,     0,   834,   835,   836,   837,   838,     7,     8,
     845,   845,   850,   851,   852,     0,     0,   854,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   472,     0,
       0,     0,     0,     0,   869,   871,   890,   873,   874,  1527,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   472,     0,     0,     0,   449,   837,
     838,     0,   873,   874,     0,     0,     0,     0,     0,     0,
       0,   904,   472,     7,     8,     0,   908,     0,     0,   700,
      24,    25,   701,    27,    28,   702,    30,   703,    32,     0,
      33,     0,     0,     0,     0,    38,    39,     0,    41,    42,
      43,     0,     0,     0,    46,     0,     0,     0,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,     0,     0,     0,     0,   449,   473,     0,     0,
       0,     0,   473,     0,     0,     0,   473,     0,    67,    68,
      69,   980,     0,   473,   700,    24,    25,   701,    27,    28,
     702,    30,   703,    32,     0,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
       0,     0,     0,  1007,  1008,     0,     0,   472,  1014,  1015,
       0,   472,  1018,     0,     0,     0,     0,     0,     0,     0,
    1025,     0,     0,   871,  1028,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    68,    69,     0,  1042,     0,  1070,
       0,     0,     0,     0,     0,   583,  1048,   473,     0,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,   472,     0,     0,     0,     0,     0,     0,  1073,  1074,
       0,     0,     0,     0,  1077,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,  1101,     0,     0,
    1103,   449,     0,     0,  1071,     7,     8,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,     0,   472,
       0,   472,   449,     0,   472,     0,     0,  1632,     0,     0,
       0,     0,     0,     0,     0,     0,   472,     0,   472,     0,
     472,     0,   472,     0,     0,     0,     0,   472,     0,     0,
       0,     0,   472,     0,     0,     0,     0,     0,  1143,     0,
    1145,  1146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   473,     0,     0,   700,    24,    25,   701,
      27,    28,   702,    30,   703,    32,     0,    33,     0,     0,
       0,     0,    38,    39,     0,    41,    42,    43,     0,     0,
    1171,    46,     0,     0,     0,     0,     0,     0,  1172,  1173,
    1174,   583,   472,     0,     0,     0,     0,     0,     0,     0,
    1177,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1184,    67,    68,    69,     0,  1187,
       0,     0,     0,     0,     0,     0,     0,     0,  1191,   473,
     473,     0,     0,     0,  1199,     0,     0,   486,     0,     0,
       0,     0,     0,     0,   472,   472,   472,   472,     0,     0,
    1213,     0,     0,     0,     0,   504,   506,   508,     0,     0,
       0,   513,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   473,   473,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   846,   848,   543,  1094,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   473,   472,     0,     0,   449,     0,     0,   872,  1674,
       0,     0,  1262,     0,  1264,     0,  1266,     0,  1268,     0,
       0,     7,     8,     0,     0,     0,     0,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1287,     0,     0,     0,     0,   473,     0,     0,     0,     7,
       8,     0,     0,     0,   618,   619,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   627,     0,  1317,
       0,     0,     0,     0,     0,     0,     0,     0,  1322,  1323,
    1324,  1325,     0,  1326,  1327,  1328,     0,     0,     0,     0,
       0,  1333,   700,    24,    25,   701,    27,    28,   702,    30,
     703,    32,     0,    33,     0,   665,     0,     0,    38,    39,
       0,    41,    42,    43,  1352,     0,     0,    46,     0,  1357,
     700,    24,    25,   701,    27,    28,   702,    30,   703,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,     0,     0,  1706,     0,
     473,    67,    68,    69,   473,     0,     0,     0,     0,     0,
       0,  1399,     0,     0,     0,     0,   872,  1029,     0,     0,
       0,     0,  1408,  1409,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,     0,     0,  1418,  1420,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,   473,     0,     0,     0,     0,     0,
       0,     0,  1144,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,  1462,  1463,  1464,     0,     0,     0,
       0,     0,     0,     0,     0,  1475,     0,  1477,     0,     0,
    1150,     0,     0,     0,     0,     0,     0,     0,  1482,     0,
       0,     0,   473,     0,   473,     0,   472,   473,     0,     0,
       0,  1494,     0,     0,     0,     0,     0,     0,     0,   473,
       0,   473,     0,   473,     0,   473,     0,     0,     0,     0,
     473,     0,     0,     0,     0,   473,     0,  1511,  1512,  1513,
       0,     0,   700,    24,    25,   701,    27,    28,   702,    30,
     703,    32,     0,    33,     0,     0,     0,     0,    38,    39,
       0,    41,    42,    43,     0,     0,  1531,    46,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,     0,     0,     0,     0,   449,     0,     0,     0,
    1543,     0,     0,     0,     0,   473,     0,     0,     0,     0,
       0,    67,    68,    69,  1556,     0,     0,     0,     0,  1562,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1741,     0,     0,  1570,  1571,     0,     0,     0,     0,
       0,  1576,  1577,     0,     0,   969,  1579,     0,     0,   975,
       0,     0,     0,     0,  1586,     0,     0,   473,   473,   473,
     473,     0,     0,     0,   472,   472,  1598,     0,  1599,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
    1616,     0,  1276,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   472,  1820,   587,     0,   472,     0,     0,
    1631,     0,     0,     7,     8,     0,     0,  1634,  1635,  1636,
    1637,  1638,  1639,  1640,     0,   473,     0,     0,     0,     0,
       0,     0,     0,  1648,     0,     0,     0,     0,  1049,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1666,   700,    24,    25,   701,    27,    28,   702,    30,
     703,    32,     0,    33,     0,     0,     0,     0,    38,    39,
       0,    41,    42,    43,  1681,  1682,  1869,    46,     0,     0,
       0,     0,  1688,     0,   700,    24,    25,   701,    27,    28,
     702,    30,   703,    32,     0,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
       0,    67,    68,    69,     0,     0,     0,     0,     0,     0,
    1709,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,  1936,     0,     0,  1723,   449,
     582,     0,     0,    67,    68,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1738,
       0,  1739,  1152,     0,   472,     0,  1156,     0,     0,     0,
    1161,     0,     0,     0,     0,     0,     0,     0,     0,  1751,
       0,     0,  1858,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   746,   447,   448,  1757,     0,     0,
       0,   449,  1761,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1178,  1938,     0,     0,     0,     0,     0,
       0,     0,   472,     0,     0,     0,     0,     0,     0,  1788,
       0,  1791,     0,  1794,     0,     0,     0,     0,     0,     0,
       0,     0,  1917,   472,     0,     0,     0,     0,     0,  1807,
    1808,  1809,  1810,  1811,  1812,     0,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
       0,     0,     0,     0,   449,  1825,  1826,     0,     0,     0,
    1828,     7,     8,     0,     0,     0,     0,     0,     0,   473,
       0,     0,  1834,   587,     0,     0,     0,     0,     0,  1239,
    1240,     0,  1242,  1845,  1245,  1246,     0,     0,  1249,  1250,
       0,     0,     0,     0,     0,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,  1872,     0,     0,     0,     0,
       0,  1562,     0,     0,     0,     0,     0,     0,     0,     0,
    1883,     0,   700,    24,    25,   701,    27,    28,   702,    30,
     703,    32,     0,    33,  1894,     0,     0,  1898,    38,    39,
    1902,    41,    42,    43,  1905,     0,     0,    46,   472,     0,
     472,  1912,  1913,  1914,  1915,  1916,     0,     0,     0,     0,
       0,     0,     0,     0,  1921,     0,     0,  1923,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1336,  1337,  1338,
       0,    67,    68,    69,     0,     0,     0,     0,     0,  1347,
       0,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,   473,   473,   449,
       0,     0,     0,  1955,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   472,     0,
    1971,  1972,  1973,  1974,  1975,     0,   473,     0,     0,     0,
     473,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   588,   447,   448,  1411,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2002,
    2003,     0,     0,     0,     0,   331,   114,     0,     0,  1432,
    2011,  2012,  2013,  2014,     0,  1438,     0,     0,     0,     0,
       0,  1443,     0,  1445,  1446,     0,     0,     0,  1449,  1450,
       0,  1451,     0,  1452,     0,  1453,     0,  1454,  1455,  1456,
       0,   876,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,     0,  1476,   154,   155,   156,
     157,     0,     0,     0,     0,   159,   160,   161,     0,     0,
     162,  1487,     0,     0,     0,  1491,     0,     0,     0,     0,
       0,   167,   912,   913,   914,   915,   916,   917,   918,   919,
     920,   921,   922,     0,   924,   925,   926,   927,   928,   929,
     930,     0,     0,   583,   934,   936,   937,     0,     0,     0,
     941,   942,     0,   944,   214,   215,     0,     0,   949,   950,
     951,     0,   953,     0,   587,     0,     0,   473,     0,   961,
     963,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1752,     0,     0,     0,     0,   986,     0,     0,
       0,     0,     0,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   170,   171,   172,
       0,   449,     0,   884,  1554,     0,     0,     0,  1603,   179,
    1604,   180,    90,     0,     0,   473,     0,  1566,     0,     0,
       0,     0,   993,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   351,     0,     0,   473,     0,     0,     0,
       0,     0,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,     0,     0,     0,
     393,   394,   395,   396,  1134,   398,   399,   400,   401,   402,
     403,     0,     0,   405,     0,     0,  1411,     0,     0,   406,
     407,     0,     0,     0,     0,   412,   413,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1641,     0,
       0,     0,     0,     0,     0,     0,  1651,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1658,     0,     0,     0,
       0,  1663,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   746,   447,   448,  1341,     0,     0,     0,
     449,     0,     0,     0,     0,     0,     0,  1683,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   473,     0,   473,     0,     0,     0,     0,     0,     0,
    1411,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,     0,     0,  1720,   562,   449,     0,
     565,   566,   567,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   592,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,  1642,     0,
    1643,   473,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     0,     0,     0,     0,
     449,  1212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1411,     0,     0,     0,     0,     0,     0,  1766,
    1767,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1411,     0,     0,     0,  1234,  1235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1800,
       0,     0,     0,     0,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,     0,     0,
       0,     0,   449,     0,     0,     0,     0,     0,     0,     0,
     698,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,  1786,  1838,  1787,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,  1855,   449,     0,     0,
       0,     0,     0,     0,     0,     0,   991,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,     0,     0,     0,
       0,     0,     0,     0,  1044,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1359,     0,     0,     0,     0,     0,
    1363,  1364,  1365,  1366,  1367,     0,  1370,     0,  1372,  1373,
       0,  1376,  1379,     0,     0,  1383,  1384,  1385,     0,     0,
       0,     0,  1389,     0,     0,     0,     0,  1411,     0,   112,
     113,   114,     0,     0,     0,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,     0,     0,
     159,   160,   161,     0,     0,   162,     0,   163,   164,   165,
       0,     0,     0,     0,     0,   166,   167,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,  1411,     0,     0,
       0,     0,     0,     0,  1097,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1497,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,  1507,     0,     0,   449,     0,     0,
       0,     0,     0,     0,     0,     0,  1125,     0,  1520,     0,
       0,     0,     0,  1524,   168,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,   173,     0,     0,     0,   174,
     175,   176,   177,   178,   179,     0,   180,    90,     0,     0,
       0,     0,     0,     0,     0,  1537,  1538,     0,     0,  1540,
    1541,   181,   182,     0,     0,     0,   183,     0,     0,     0,
       0,   184,     0,   185,     0,   186,   187,     0,   188,     0,
     189,     0,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     0,     0,   112,   294,
     449,     0,     0,     0,   115,   116,   117,     0,   614,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   296,   297,   298,   299,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,   151,   152,
     153,     0,     0,     0,     0,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,     0,
       0,     0,     0,     0,   166,     0,     0,     0,   300,     0,
       0,   301,     0,     0,   302,     0,   303,     0,     0,     0,
    1653,  1654,   114,     0,  1656,  1657,     0,     0,   304,     0,
    1660,  1661,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,     0,     0,   154,   155,   156,   157,     0,     0,     0,
       0,   159,   160,   161,     0,     0,   162,     0,     0,     0,
     169,     0,     0,     0,   173,     0,     0,   167,   174,   175,
     176,   177,   178,     0,     0,     0,    90,     0,     0,     0,
    1188,  1189,     0,     0,     0,     0,  1193,  1194,     0,     0,
     530,  1623,     0,     0,     0,   183,     0,     0,     0,     0,
     532,     0,     0,  1730,  1731,   187,     0,   261,   585,   112,
     294,     0,     0,     0,     0,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   296,   297,   298,   299,     0,     0,     0,
       0,     0,     0,   170,   171,   172,     0,     0,   150,   151,
     152,   153,     0,     0,     0,   179,   158,   180,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,   164,   165,
       0,     0,     0,     0,     0,   166,     0,     0,     0,   300,
       0,     0,   301,     0,     0,   302,     0,   303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   304,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,     0,     0,  1164,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1349,  1350,     0,
       0,   169,  1354,  1355,     0,   173,     0,     0,     0,   174,
     175,   176,   177,   178,     0,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   471,     0,     0,     0,   183,     0,     0,     0,
       0,   306,     0,     0,     0,     0,   187,     0,     0,   585,
     112,   294,   114,     0,     0,     0,   115,   116,   117,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   296,   297,   298,   299,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,     0,
       0,   159,   160,   161,     0,     0,   162,     0,   163,   164,
     165,     0,     0,     0,     0,     0,   166,   167,     0,     0,
     300,     0,     0,   301,     0,     0,   302,     0,   303,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     304,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
    1992,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,     0,     0,  1280,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,   171,   172,   173,     0,     0,     0,
     174,   175,   176,   177,   178,   179,     0,   180,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   305,     0,     0,     0,   183,     0,     0,
       0,     0,   306,     0,   112,   294,   114,   187,     0,   307,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   296,   297,
     298,   299,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,     0,     0,   159,   160,   161,     0,     0,
     162,     0,   163,   164,   165,     0,     0,     0,     0,     0,
     166,   167,     0,     0,   300,     0,     0,   301,     0,     0,
     302,     0,   303,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   304,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,     0,     0,
       0,     0,   449,     0,     0,     0,     0,     0,     0,     0,
       0,  1601,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,   171,   172,
     173,     0,     0,     0,   174,   175,   176,   177,   178,   179,
       0,   180,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   305,     0,     0,
       0,   183,     0,     0,     0,     0,   306,     0,   112,   341,
     114,   187,     0,  1662,   115,   116,   117,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,     0,     0,     0,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,     0,     0,   159,
     160,   161,     0,     0,   162,     0,   163,   164,   165,     0,
     112,   341,   114,     0,   166,   167,   115,   116,   117,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,     0,
       0,   159,   160,   161,     0,     0,   162,     0,   163,   164,
     165,     0,     0,     0,     0,     0,   166,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   170,   171,   172,   173,     0,     0,     0,   174,   175,
     176,   177,   178,   179,     0,   180,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   182,     0,     0,     0,   183,     0,     0,     0,     0,
     306,     0,     0,     0,     0,   187,     0,  1419,     0,     0,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,     0,     0,     0,     0,   449,     0,
       0,     0,   169,   170,   171,   172,   173,  1620,     0,     0,
     174,   175,   176,   177,   178,   179,     0,   180,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   182,     0,     0,     0,   183,     0,     0,
       0,     0,   306,     0,   112,   341,   114,   187,     0,  1647,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,     0,     0,   159,   160,   161,     0,     0,
     162,     0,   163,   164,   165,     0,     0,     0,     0,     0,
     166,   167,     0,     0,     0,     0,     0,   457,   114,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,     0,     0,  1693,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,     0,     0,   154,
     155,   156,   157,     0,     0,     0,     0,   159,   160,   161,
       0,     0,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,     0,     0,   169,   170,   171,   172,
     173,     0,     0,     0,   174,   175,   176,   177,   178,   179,
       0,   180,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   182,     0,     0,
       0,   183,     0,     0,     0,     0,   306,     0,   112,   294,
     295,   187,     0,  1665,   115,   116,   117,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   296,   297,   298,   299,     0,     0,     0,   170,
     171,   172,     0,     0,     0,     0,     0,   150,   151,   152,
     153,   179,     0,   180,    90,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,     0,
       0,     0,     0,     0,   166,     0,     0,     0,   300,     0,
       0,   301,   335,   114,   302,     0,   303,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   304,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,     0,     0,   154,   155,   156,   157,     0,     0,
       0,     0,   159,   160,   161,     0,     0,   162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,     0,
     169,     0,     0,     0,   173,     0,     0,     0,   174,   175,
     176,   177,   178,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   305,     0,     0,     0,   183,     0,     0,     0,     0,
     306,     0,   112,   294,  1485,   187,     0,   307,   115,   116,
     117,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   296,   297,   298,   299,
       0,     0,     0,     0,   170,   171,   172,     0,     0,     0,
       0,   150,   151,   152,   153,     0,   179,     0,   180,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,   164,   165,     0,     0,     0,     0,     0,   166,     0,
       0,     0,   300,     0,     0,   301,     0,     0,   302,     0,
     303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   304,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     0,     0,     0,     0,
     449,     0,     0,     0,     0,     0,     0,     0,     0,  1694,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,     0,     0,     0,   173,     0,
       0,     0,   174,   175,   176,   177,   178,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   305,     0,     0,     0,   183,
       0,     0,     0,     0,   306,     0,   112,   294,     0,   187,
       0,  1486,   115,   116,   117,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     296,   297,   298,   299,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,   151,   152,   153,     0,
       0,     0,     0,   158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,   164,   165,     0,     0,     0,
       0,     0,   166,     0,     0,     0,   300,     0,     0,   301,
       0,     0,   302,     0,   303,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   304,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
       0,     0,     0,     0,   449,     0,     0,     0,     0,     0,
       0,     0,     0,  1695,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,     0,
       0,     0,   173,     0,     0,     0,   174,   175,   176,   177,
     178,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   305,
       0,     0,     0,   183,     0,     0,     0,     0,   306,     0,
     112,   294,     0,   187,     0,   307,   115,   116,   117,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   296,   297,   298,   299,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,   152,   153,     0,     0,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,   164,
     165,     0,     0,     0,     0,     0,   166,     0,     0,     0,
     300,     0,     0,   301,     0,     0,   302,     0,   303,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     304,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,     0,     0,     0,     0,   449,     0,
       0,     0,     0,     0,     0,     0,     0,  1696,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,     0,     0,     0,   173,     0,     0,     0,
     174,   175,   176,   177,   178,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   305,     0,     0,     0,   183,     0,     0,
       0,     0,   503,     0,   112,   294,     0,   187,     0,   307,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   296,   297,
     298,   299,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,   151,   152,   153,     0,     0,     0,
       0,   158,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,   164,   165,     0,     0,     0,     0,     0,
     166,     0,     0,     0,   300,     0,     0,   301,     0,     0,
     302,     0,   303,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   304,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,     0,     0,
       0,     0,   449,     0,     0,     0,     0,     0,     0,     0,
       0,  1697,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,     0,     0,     0,
     173,     0,     0,     0,   174,   175,   176,   177,   178,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   305,     0,     0,
       0,   183,     0,     0,     0,     0,   505,     0,   112,   294,
       0,   187,     0,   307,   115,   116,   117,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   296,   297,   298,   299,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,   151,   152,
     153,     0,     0,     0,     0,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,     0,
       0,     0,     0,     0,   166,     0,     0,     0,   300,     0,
       0,   301,     0,     0,   302,     0,   303,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   304,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,     0,     0,     0,     0,   449,     0,     0,     0,
       0,     0,     0,     0,     0,  1729,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     169,     0,     0,     0,   173,     0,     0,     0,   174,   175,
     176,   177,   178,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   305,     0,     0,     0,   183,     0,     0,     0,     0,
     507,     0,   112,   294,     0,   187,     0,   307,   115,   116,
     117,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   296,   297,   298,   299,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,   151,   152,   153,     0,     0,     0,     0,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,   164,   165,     0,     0,     0,     0,     0,   166,     0,
       0,     0,   300,     0,     0,   301,     0,     0,   302,     0,
     303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   304,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     0,     0,     0,     0,
     449,     0,     0,     0,     0,     0,     0,     0,     0,  1802,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,     0,     0,     0,   173,     0,
       0,     0,   174,   175,   176,   177,   178,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   471,     0,     0,     0,   183,
       0,     0,     0,     0,   306,     0,   112,   294,     0,   187,
       0,   581,   115,   116,   117,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     296,   297,   298,   299,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,   151,   152,   153,     0,
       0,     0,     0,   158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,   164,   165,     0,     0,     0,
       0,     0,   166,     0,     0,     0,   300,     0,     0,   301,
       0,     0,   302,     0,   303,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   304,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
       0,     0,     0,     0,   449,     0,     0,     0,     0,     0,
       0,     0,     0,  1813,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,     0,
       0,     0,   173,     0,     0,     0,   174,   175,   176,   177,
     178,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   471,
       0,     0,     0,   183,     0,     0,     0,     0,   306,     0,
     112,   294,     0,   187,     0,   844,   115,   116,   117,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   296,   297,   298,   299,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,   152,   153,     0,     0,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,   164,
     165,     0,     0,     0,     0,     0,   166,     0,     0,     0,
     300,     0,     0,   301,     0,     0,   302,     0,   303,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     304,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,     0,     0,     0,     0,   449,     0,
       0,     0,     0,     0,     0,     0,     0,  1814,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,     0,     0,     0,   173,     0,     0,     0,
     174,   175,   176,   177,   178,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   471,     0,     0,     0,   183,     0,     0,
       0,     0,   306,     0,   112,   294,     0,   187,     0,   847,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   296,   297,
     298,   299,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,   151,   152,   153,     0,     0,     0,
       0,   158,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,   164,   165,     0,     0,     0,     0,     0,
     166,     0,     0,     0,   300,     0,     0,   301,     0,     0,
     302,     0,   303,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   304,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,     0,     0,
       0,     0,   449,     0,     0,     0,     0,     0,     0,     0,
       0,  1846,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,     0,     0,     0,
     173,     0,     0,     0,   174,   175,   176,   177,   178,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   471,     0,     0,
       0,   183,     0,     0,     0,     0,   306,     0,   112,   294,
       0,   187,     0,   870,   115,   116,   117,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   296,   297,   298,   299,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,   151,   152,
     153,     0,     0,     0,     0,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,     0,
       0,     0,     0,     0,   166,     0,     0,     0,   300,     0,
       0,   301,     0,     0,   302,     0,   303,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   304,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,     0,     0,     0,     0,   449,     0,     0,     0,
       0,     0,     0,     0,     0,  1849,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     169,     0,     0,     0,   173,     0,     0,     0,   174,   175,
     176,   177,   178,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   305,     0,     0,     0,   183,     0,     0,     0,     0,
     306,     0,   112,   294,     0,   187,     0,  1490,   115,   116,
     117,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   296,   297,   298,   299,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,   151,   152,   153,     0,     0,     0,     0,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,   164,   165,     0,     0,     0,     0,     0,   166,     0,
       0,     0,   300,     0,     0,   301,     0,     0,   302,     0,
     303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   304,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     0,     0,     0,     0,
     449,     0,     0,     0,     0,     0,     0,     0,     0,  1852,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,     0,     0,     0,   173,     0,
       0,     0,   174,   175,   176,   177,   178,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   530,  1623,     0,     0,     0,   183,
       0,     0,     0,     0,   532,     0,   112,   341,     0,   187,
       0,   261,   115,   116,   117,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   150,   151,   152,   153,   449,
       0,     0,     0,   158,     0,     0,     0,     0,  1884,     0,
       0,     0,   112,   341,   163,   164,   165,     0,   115,   116,
     117,     0,   166,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   150,   151,   152,   153,   449,     0,     0,     0,   158,
       0,     0,     0,     0,  1891,     0,     0,     0,     0,     0,
     163,   164,   165,     0,     0,     0,     0,     0,   166,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,   169,     0,
       0,     0,   173,     0,     0,   794,   174,   175,   176,   177,
     178,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   182,
       0,     0,     0,   183,     0,     0,     0,     0,   306,     0,
       0,     0,     0,   187,     0,   510,     0,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,   169,   449,     0,   840,   173,   841,
       0,     0,   174,   175,   176,   177,   178,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   530,   531,     0,     0,     0,   183,
       0,     0,     0,     0,   532,     0,   112,   341,   114,   187,
       0,   261,   115,   116,   117,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,     0,     0,   159,   160,   161,
       0,     0,   162,     0,   163,   164,   165,     0,     0,     0,
       0,     0,   166,   167,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,     0,     0,
       0,     0,   449,     0,     0,     0,     0,     0,     0,     0,
       0,  1930,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     0,     0,     0,     0,
     449,     0,     0,     0,     0,     0,     0,     0,     0,  1932,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,     0,     0,     0,     0,   449,     0,
       0,     0,     0,     0,     0,     0,     0,  1934,   169,   170,
     171,   172,   173,     0,     0,     0,   174,   175,   176,   177,
     178,   179,     0,   180,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   182,
       0,     0,     0,   183,   112,   294,     0,     0,   306,     0,
     115,   116,   117,   187,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   296,   297,
     298,   299,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,   151,   152,   153,     0,     0,     0,
       0,   158,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,   164,   165,     0,     0,     0,     0,     0,
     166,     0,     0,     0,   300,     0,     0,   301,     0,     0,
     302,     0,   303,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   304,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,     0,     0,
       0,     0,   449,     0,     0,     0,     0,     0,     0,     0,
       0,  1954,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,     0,     0,     0,
     173,     0,     0,     0,   174,   175,   176,   177,   178,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   471,     0,     0,
       0,   183,   112,   341,     0,     0,   306,     0,   115,   116,
     117,   187,     0,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   150,   151,   152,   153,   449,     0,     0,     0,   158,
       0,     0,     0,     0,  1981,     0,     0,     0,   112,   341,
     163,   164,   165,     0,   115,   116,   117,     0,   166,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   150,   151,   152,
     153,   449,     0,     0,     0,   158,     0,     0,     0,     0,
    2020,     0,     0,     0,     0,     0,   163,   164,   165,     0,
       0,     0,     0,     0,   166,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,   169,     0,     0,     0,   173,     0,
       0,  1705,   174,   175,   176,   177,   178,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   182,     0,     0,     0,   183,
       0,     0,     0,     0,   306,   420,     0,     0,     0,   187,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,     0,     0,     0,     0,   449,     0,
     169,     0,     0,     0,   173,     0,     0,  2021,   174,   175,
     176,   177,   178,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   182,     0,     0,     0,   183,     0,     0,     0,     0,
     306,   112,   341,   422,     0,   187,     0,   115,   116,   117,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     150,   151,   152,   153,   449,     0,     0,     0,   158,     0,
       0,     0,     0,  2025,     0,     0,     0,   112,   341,   163,
     164,   165,     0,   115,   116,   117,     0,   166,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   150,   151,   152,   153,
     449,     0,     0,     0,   158,     0,     0,     0,     0,  2026,
       0,     0,     0,     0,     0,   163,   164,   165,     0,     0,
       0,     0,     0,   166,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,     0,     0,
       0,     0,   449,   169,   840,     0,   841,   173,     0,  1369,
       0,   174,   175,   176,   177,   178,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,     0,     0,     0,   183,     0,
       0,     0,     0,   306,   620,     0,     0,     0,   187,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,   169,
       0,     0,     0,   173,     0,     0,  2027,   174,   175,   176,
     177,   178,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,     0,     0,     0,   183,     0,     0,     0,     0,   306,
     112,   341,   622,  1286,   187,     0,   115,   116,   117,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   150,
     151,   152,   153,   449,     0,     0,     0,   158,     0,     0,
       0,     0,  2028,     0,     0,     0,   112,   341,   163,   164,
     165,     0,   115,   116,   117,     0,   166,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   150,   151,   152,   153,   449,
       0,   867,     0,   158,     0,     0,   801,     0,     0,     0,
       0,     0,     0,     0,   163,   164,   165,     0,     0,     0,
       0,     0,   166,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,   169,     0,     0,     0,   173,     0,   735,     0,
     174,   175,   176,   177,   178,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   182,     0,     0,     0,   183,     0,     0,
       0,     0,   306,     0,    -4,     1,     0,   187,    -4,     0,
       0,     0,     0,     0,     0,     0,    -4,    -4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,     0,
       0,     0,   173,     0,     0,     0,   174,   175,   176,   177,
     178,     0,     0,     0,    90,    -4,    -4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   182,
       0,     0,     0,   183,     0,    -4,    -4,    -4,   306,     0,
       0,    -4,    -4,   187,    -4,     0,     0,     0,    -4,    -4,
       0,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     0,    -4,    -4,    -4,     6,     0,     0,     0,     0,
      -4,     0,     0,     7,     8,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     0,     9,    10,    -4,    -4,    -4,     0,     0,     0,
       0,     0,     0,    -4,     0,    -4,     0,     0,     0,     0,
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
      89,     0,    90,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,   801,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,   802,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,     0,     0,     0,     0,     0,
     881,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,   923,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,     0,     0,     0,
       0,     0,   931,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,   932,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,   933,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,     0,     0,     0,     0,     0,
     948,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,  1079,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,     0,     0,     0,
       0,     0,  1080,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,  1081,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,  1112,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,     0,     0,     0,     0,     0,
    1121,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,  1122,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,     0,     0,     0,
       0,     0,  1123,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,  1230,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,  1278,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,     0,     0,     0,     0,     0,
    1279,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,  1340,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,     0,     0,     0,
       0,     0,  1500,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,  1501,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,  1502,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,     0,     0,     0,     0,     0,
    1503,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,  1504,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,     0,     0,     0,
       0,     0,  1505,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,  1506,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,  1557,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,     0,     0,     0,     0,     0,
    1558,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,  1565,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,     0,     0,     0,
       0,     0,  1732,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,  1733,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,  1734,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,     0,     0,     0,     0,     0,
    1735,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,  1736,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,     0,     0,     0,
       0,     0,  1758,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,  1759,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,  1763,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,     0,     0,     0,     0,     0,
    1864,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,  1865,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,     0,     0,     0,
       0,     0,  1866,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,  1867,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,  1868,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,     0,     0,     0,     0,     0,
    1877,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,  1880,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,     0,     0,     0,
       0,     0,  1926,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,  1943,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,  1944,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,     0,     0,     0,     0,     0,
    1945,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,  1946,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,     0,     0,     0,
       0,     0,  1947,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,  1993,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,  1994,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,     0,     0,     0,     0,     0,
    1995,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,  1996,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,     0,     0,   692,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,     0,     0,     0,     0,   449,     0,
       0,     0,   887,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,     0,     0,   903,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
       0,     0,     0,     0,   449,     0,     0,     0,   910,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,  1006,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     0,     0,     0,     0,
     449,     0,     0,     0,  1105,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,     0,     0,  1106,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,     0,     0,     0,     0,   449,     0,     0,     0,
    1110,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,     0,     0,  1111,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,     0,     0,
       0,     0,   449,     0,     0,     0,  1114,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,     0,     0,  1137,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,     0,     0,     0,     0,   449,     0,
       0,     0,  1166,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,     0,     0,  1223,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
       0,     0,     0,     0,   449,     0,     0,     0,  1228,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,     0,
       0,  1495,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     0,     0,     0,     0,
     449,     0,     0,     0,  1548,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,     0,     0,  1718,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,     0,     0,     0,     0,   449,     0,   688,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,   745,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,     0,     0,     0,     0,   449,     0,
     749,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,   750,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     0,     0,     0,     0,
     449,     0,   752,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,   754,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,     0,     0,
       0,     0,   449,     0,   755,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,   758,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
       0,     0,     0,     0,   449,     0,   759,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,   867,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,     0,     0,     0,     0,   449,     0,   877,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,   878,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,     0,     0,     0,     0,   449,     0,
     879,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,   885,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     0,     0,     0,     0,
     449,     0,   886,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,   899,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,     0,     0,
       0,     0,   449,     0,   909,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,  1005,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
       0,     0,     0,     0,   449,     0,  1033,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,  1038,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,     0,     0,     0,     0,   449,     0,  1043,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,  1046,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,     0,     0,     0,     0,   449,     0,
    1047,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,  1053,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     0,     0,     0,     0,
     449,     0,  1062,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,  1063,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,     0,     0,
       0,     0,   449,     0,  1064,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,  1096,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
       0,     0,     0,     0,   449,     0,  1098,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,  1099,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,     0,     0,     0,     0,   449,     0,  1100,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,  1104,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,     0,     0,     0,     0,   449,     0,
    1113,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,     0,     0,     0,     0,   449,
       0,  1136,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     0,     0,     0,     0,
     449,     0,  1222,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,     0,     0,     0,
       0,   449,     0,  1227,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,     0,     0,
       0,     0,   449,     0,  1381,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,     0,
       0,     0,     0,   449,     0,  1602,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
       0,     0,     0,     0,   449,     0,  1619,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,     0,     0,     0,     0,   449,     0,  1646,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,     0,     0,     0,     0,   449,     0,  1876,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,     0,     0,     0,     0,   449,     0,  1952,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,     0,     0,     0,     0,   449
};

static const yytype_int16 yycheck[] =
{
       3,     5,     4,     6,     4,   254,  1488,     3,   524,   525,
       4,     6,     4,     4,     7,   269,     4,     4,     4,  1689,
       5,     4,     6,     4,     6,     5,     4,   281,     5,     4,
     387,     5,   389,     4,     4,    86,     5,     4,    89,     4,
       6,   217,     5,   195,   196,     5,   222,   404,     5,     5,
     226,     6,     6,     6,    57,     0,     6,   233,     6,     6,
     212,     4,    65,     6,     6,   195,   196,    70,   205,     7,
     207,     6,   195,   196,     6,   195,   196,   214,    81,   195,
     196,     6,   147,   213,   338,    13,   340,   205,   211,   207,
     213,   211,    89,   213,  1091,   211,   214,   213,   163,   164,
    1582,   209,   205,   234,   235,   236,   214,     7,   239,   240,
     241,   420,   205,   422,     7,   424,    83,   195,   196,     7,
      87,     6,    49,    50,   205,    52,   207,   205,     6,   202,
     203,     6,    99,   214,   212,   137,   138,   139,   140,   212,
      83,   195,   196,   205,   275,   276,    81,   205,    83,     6,
     212,     7,   195,   196,   212,   195,   196,   211,   289,   290,
      86,  1831,  1832,    89,   158,   150,   147,   148,   211,   135,
     150,   162,   212,   150,     7,   205,   150,   147,   148,     6,
     135,   135,   212,  1095,   187,   135,     7,   181,   202,   203,
       7,     6,   188,   181,   206,   205,   199,   200,   212,   211,
     195,   196,  1684,     6,   207,   205,   181,   205,   212,   207,
     192,   213,   215,   205,   217,   207,   209,   209,   212,   222,
    1702,   207,   214,   226,   212,   212,   229,   205,   214,   212,
     233,   234,   235,   236,   212,   212,   239,   240,   241,     3,
     205,   212,     6,   212,   247,   248,   249,   212,   207,   212,
     253,   254,   212,   195,   196,   212,   212,   433,   205,   212,
     192,   515,   516,     7,   212,   212,   207,   205,   111,   207,
     195,   196,   275,   276,   277,    86,   205,     7,    89,   214,
      91,   535,   182,   183,   184,   185,   289,   290,   205,   182,
     183,   184,   185,    57,   182,   183,   184,   185,     7,   205,
     205,   207,   305,   209,   307,  1302,    70,   212,   214,   202,
     203,   620,    93,   622,   202,   203,   209,    81,   205,     4,
     206,   199,   200,   195,   196,   211,   182,   183,   184,   185,
     257,   258,    86,   509,   510,    89,   205,    91,   265,   205,
     212,   344,   269,   346,   347,   599,   202,   203,    89,   182,
     183,   184,   185,   206,   205,   208,   359,   195,   196,   212,
     614,   182,   183,   184,   185,   182,   183,   184,   185,   202,
     203,   202,   203,   211,     6,   551,   552,   553,   209,   688,
     212,   202,   203,   692,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,  1879,   401,   402,
     403,   404,   405,   195,   196,   581,   409,   410,   411,   412,
     413,   414,    89,   416,   202,   203,   206,   352,   208,   211,
     205,   211,   207,   187,   212,   110,   111,   112,   113,   214,
     433,   607,   195,   196,   119,   199,   200,   122,   182,   183,
     184,   185,    89,   207,    91,   195,   196,   208,   211,   625,
     211,   215,   182,   183,   184,   185,   205,    83,   207,   206,
      86,   211,    89,    89,   211,   214,   344,   106,   471,   195,
     196,    89,   407,   182,   183,   184,   185,    91,   117,   206,
     415,   208,   195,   196,   211,   211,   125,   126,   127,   205,
     254,   206,   131,   132,   133,   134,   211,  1979,   211,   202,
     203,   202,   203,   205,    86,   207,   509,   510,   212,   212,
     388,   212,   390,   391,   392,   393,   394,   395,   396,   106,
     398,   399,     8,   401,   402,   403,   212,   405,   524,   525,
     117,   409,   410,   411,   412,   413,   195,   196,   125,   126,
     127,   195,   196,   797,   131,   132,   133,   134,   551,   552,
     553,   211,   211,   213,   730,   195,   196,   211,   734,    89,
     563,   564,   110,   111,   499,   500,   501,   502,   116,   195,
     196,   211,   206,    86,   213,   195,   196,   211,   581,   205,
     344,   424,   195,   196,    86,   588,   212,   206,   106,   208,
     899,   211,     8,   212,   903,   522,   523,   208,   211,   117,
     211,   195,   196,   530,   607,   195,   196,   125,   126,   127,
     202,   203,    89,   131,   132,   133,   134,   211,   794,     4,
     212,   211,   625,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,     4,   398,   399,     6,   401,   402,   403,
     404,   405,   195,   196,     4,   409,   410,   411,   412,   413,
     414,   206,   416,   106,   195,   196,   211,     4,   211,   195,
     196,   195,   196,   205,   117,   211,   842,   213,   844,     6,
     211,   847,   125,   126,   127,   211,   205,   211,   131,   132,
     133,   134,   205,   859,   687,   861,   205,   863,   691,   865,
      83,   202,   203,    86,   870,   213,    89,   208,    91,   875,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   195,   196,   195,   196,   204,   206,
     206,   208,   195,   196,   211,   205,   211,   730,   213,     6,
     211,   734,   211,     8,   737,   984,   206,   740,   211,   742,
     211,   211,   213,   746,   747,  1054,   211,  1056,   213,  1058,
     207,  1060,   195,   196,   197,   198,   199,   205,   693,   935,
     213,   204,   197,   198,   199,   207,   211,   770,   213,   204,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    83,   202,   203,    86,   204,   632,
      89,   794,    91,  1790,   195,   196,  1793,   213,   205,  1796,
     564,  1713,   206,  1715,   208,  1717,   205,   211,   207,   744,
     209,   987,   988,   989,   990,   214,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     205,  1188,  1189,   206,   204,   208,  1193,  1194,   211,   842,
     206,   844,   208,   205,   847,   688,   205,   205,   207,   692,
     209,    83,   205,   212,    86,   214,   859,    89,   861,   737,
     863,   211,   865,   213,   742,   110,   111,   870,   211,  1045,
     213,   116,   875,   800,   206,   211,   208,   213,     7,   211,
     807,   205,   211,   206,   213,   208,   813,  1196,   211,   205,
     211,   894,   213,   205,   211,   898,   213,   205,   211,   902,
     213,     6,     7,  1212,     6,   205,   211,   910,   213,  1906,
     207,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     6,   211,     6,   213,   204,
     212,    89,   935,    91,    89,   205,    91,   940,   213,   211,
       6,   213,   945,   946,   947,   948,   211,  1859,   213,  1465,
    1466,   211,     4,   213,  1203,   958,   211,   960,   213,   212,
     211,  1958,   213,   211,  1961,   213,     4,  1964,     6,   211,
    1967,   213,   211,   737,   213,   211,   740,   213,   742,   212,
     211,   984,   213,   212,   987,   988,   989,   990,   211,   211,
     213,   213,  1349,  1350,     6,     7,   839,  1354,  1355,   211,
     211,   213,   213,   211,   211,   213,   213,   205,  2005,  1012,
    2007,   211,  2009,   213,   211,   205,   213,  1929,   211,  1931,
     213,  1933,   211,   211,   213,   213,   205,  1939,  1031,  1032,
     205,  1034,   910,  1036,  1037,   205,   205,  1040,  1041,   211,
     205,   213,  1045,   211,   211,   213,   213,   211,   205,   213,
    1359,   211,   211,   213,   213,   211,   899,   213,   205,   211,
     903,   213,   940,   211,   207,   213,   909,   910,   946,   947,
     948,   212,   211,  1985,   213,  1987,   211,  1989,   213,   211,
     958,   213,   960,   205,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   212,   211,
    1027,   213,   204,   212,   212,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   211,
     211,   213,   213,   204,   211,   211,   213,   213,   211,   205,
     213,     6,   212,  1309,  1012,   212,  1139,  1140,  1141,   211,
     211,   213,   213,   211,   205,   213,   910,   106,  1151,   214,
     205,  1400,  1079,  1080,  1081,   211,     6,   213,   117,     6,
     207,   212,  1005,  1006,     4,     5,   125,   126,   127,   212,
     212,   207,   131,   132,   133,   134,   940,   207,     6,     6,
     212,   150,   946,   947,   948,  1188,  1189,   214,     6,     6,
    1193,  1194,  1708,   212,   958,     6,   960,     6,     6,   212,
    1203,   212,     6,    43,    44,    45,    46,    47,    48,    49,
      50,    51,   207,     4,  1217,   204,    56,    57,    58,    59,
     984,   209,     7,   213,    64,    65,    66,   212,   211,    69,
     211,     7,     6,     6,     6,   206,     7,     7,  1241,     6,
      80,     6,     6,     6,  1247,   212,     7,     6,  1012,     7,
    1253,     6,  1255,  1256,   213,     6,     6,  1260,  1261,     4,
    1263,    61,  1265,    61,  1267,    61,  1269,  1270,  1271,    61,
    1113,  1114,   212,   147,   208,   206,     6,     6,   206,   206,
     206,  1457,  1458,    43,     6,  1288,   211,   211,   211,   211,
     211,   211,   211,  1136,  1137,   206,  1231,   206,   208,    43,
    1303,    43,    43,     4,  1307,     4,  1309,     7,  1665,     6,
       6,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     6,   166,   167,   168,   204,
       6,   150,     7,     7,     7,   150,     7,     7,   178,     7,
     180,   181,     7,   150,   212,     4,  1349,  1350,     6,   206,
     211,  1354,  1355,  1196,   206,   211,   211,   206,   206,   213,
     211,     6,   202,   203,   209,  1368,   208,   213,   206,   209,
       7,  1374,   212,   212,  1301,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   212,
     212,   212,     7,   204,     7,   209,   212,  1400,     6,    43,
      43,    43,    43,  1406,     6,     6,     6,     6,     6,   212,
       7,  1346,   207,  1416,     6,   205,  1419,   106,   205,     6,
       4,     7,     7,   192,  1188,  1189,  1675,    91,   117,  1193,
    1194,     7,     7,     7,     7,     6,   125,   126,   127,  1203,
       7,     6,   131,   132,   133,   134,     7,     7,   205,     7,
       7,     7,     4,   106,  1457,  1458,   212,  1392,     6,   212,
       7,     6,    89,     7,   117,     7,     7,     6,  1722,  1465,
    1466,  1647,   125,   126,   127,     6,     6,     6,   131,   132,
     133,   134,     7,  1486,  1419,  1488,     6,  1490,     4,     4,
    1368,     4,   211,   213,     6,     6,  1374,     6,     6,     6,
       4,     6,  1429,   211,   206,   211,   209,  1510,   206,     7,
     205,     6,     6,     6,   208,  1518,   206,   209,  1361,   212,
       6,   212,    99,     6,   213,  1528,  1461,   212,   212,  1705,
    1533,     6,   212,     6,   212,     6,     6,     5,  1416,     4,
    1467,     7,  1469,     6,  1471,   212,   212,   106,     6,   212,
    1726,   212,   207,     6,     6,     6,  1559,     4,   117,  1486,
     213,   212,  1489,  1490,   212,   212,   125,   126,   127,   208,
     206,     6,   131,   132,   133,   134,     6,   146,     6,  1582,
     211,  1516,     4,     6,     4,  1349,  1350,     6,     6,     6,
    1354,  1355,     6,     6,     6,     6,     6,     4,  1533,  1534,
    1535,   212,     7,     7,  1368,     6,  1860,     6,     6,     6,
    1374,     5,   150,     6,     6,  1618,     6,     6,     6,     6,
    1623,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     6,  1400,     6,     6,   204,
       6,     6,     6,   211,  1647,     6,     6,     6,     6,   106,
       6,     6,  1416,  1496,   213,   206,   211,     6,     6,  1662,
     117,     6,  1665,     6,     6,     5,     7,     6,   125,   126,
     127,     6,  1675,   209,   131,   132,   133,   134,   212,     6,
     212,  1684,     6,   145,   212,  1861,   212,  1863,  1691,  1692,
       4,     5,    87,     6,   212,     6,   213,     7,   212,  1702,
     106,     6,  1705,   213,     6,     6,   212,     6,     6,   212,
     212,   117,  1708,   213,     6,  1650,     6,   148,  1721,   125,
     126,   127,     6,  1726,     6,   131,   132,   133,   134,    43,
      44,    45,    46,    47,    48,    49,    50,    51,     6,     6,
       6,     6,    56,    57,    58,    59,     6,     6,    12,    13,
      64,    65,    66,   212,     6,    69,   213,   206,     6,   213,
       7,     6,   212,     6,   212,  1941,    80,   191,   192,   193,
     194,   195,   196,   197,   198,   199,  1779,   106,   212,   212,
     204,     6,     6,   106,     6,  1712,   212,  1714,     6,  1716,
       6,     6,     6,     6,   117,  1798,     6,  1724,     6,     6,
    1727,     6,   125,   126,   127,   213,     6,   213,   131,   132,
     133,   134,   212,     6,   205,     6,   212,     6,  1821,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,   212,
      94,   206,   212,     6,     6,    99,   100,     6,   102,   103,
     104,     6,   212,     6,   108,     6,     6,     6,     6,   212,
     212,  1778,   166,   167,   168,  1782,     6,     6,  1861,   212,
    1863,   212,     6,     6,   178,     6,   180,   181,     6,     6,
       6,     6,     6,  1824,  1226,  1240,  1879,   106,   142,   143,
     144,    12,    13,  1690,   467,  1820,     3,     3,   117,  1396,
     213,   497,   206,    -1,   208,   106,   125,   126,   127,  1704,
      -1,  1665,   131,   132,   133,   134,   117,    -1,    -1,  1836,
      -1,  1675,    -1,  1840,   125,   126,   127,    -1,    -1,    -1,
     131,   132,   133,   134,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1863,    -1,  1941,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,  1951,   213,
      -1,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    -1,    -1,    -1,    -1,    99,   100,
      -1,   102,   103,   104,    -1,    -1,  1979,   108,   106,    -1,
      -1,    -1,  1917,    -1,   213,    -1,    -1,    -1,    -1,   117,
       6,    -1,    -1,    -1,  1997,    -1,  1999,   125,   126,   127,
    1927,  1928,   213,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   142,   143,   144,    -1,    -1,    -1,    -1,   181,   182,
     183,   184,   185,    -1,    -1,    -1,  2029,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   216,   217,   218,   219,  1821,   221,   222,
     223,   224,    -1,   226,   227,   228,     6,    -1,    -1,    -1,
     233,    -1,    -1,  1951,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,    -1,    -1,   213,    -1,    -1,   251,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   261,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1997,
      -1,  1999,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,
     204,    -1,   305,   306,   307,    -1,    -1,    -1,    -1,    -1,
      -1,  2029,    -1,    -1,   317,   318,   319,    -1,   321,    -1,
      -1,    -1,   325,   326,   327,    -1,    -1,   330,    -1,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,   348,   349,  1951,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   362,
     363,    -1,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,  1997,    -1,  1999,    -1,   400,    -1,    -1,
      -1,    -1,    -1,   406,    -1,   408,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      -1,    -1,    -1,    -1,   204,  2029,    -1,    -1,    -1,   432,
     433,    -1,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,    -1,    -1,   452,
     453,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,   471,    -1,
      -1,    -1,    99,   100,   477,   102,   103,   104,     6,   482,
      -1,   108,    -1,    -1,   487,   488,    -1,    -1,    -1,    -1,
     493,   494,    -1,    -1,    -1,   498,   499,   500,   501,   502,
     503,    -1,   505,    -1,   507,    -1,   509,   510,    -1,    -1,
     106,    -1,    -1,    -1,    -1,   142,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,   527,   528,   529,   530,   531,   532,
      -1,    -1,    -1,   536,   537,   538,   539,   540,    -1,    -1,
      -1,   544,    -1,   546,   547,    -1,    -1,    -1,   551,   552,
     553,    -1,    -1,   556,   557,   558,   559,   560,    12,    13,
     563,   564,   565,   566,   567,    -1,    -1,   570,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,
      -1,    -1,    -1,    -1,   587,   588,   213,   590,   591,     6,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   607,    -1,    -1,    -1,   204,   612,
     613,    -1,   615,   616,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   624,   625,    12,    13,    -1,   629,    -1,    -1,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    -1,    -1,    -1,    -1,    99,   100,    -1,   102,   103,
     104,    -1,    -1,    -1,   108,    -1,    -1,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,    -1,    -1,   204,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,   226,    -1,   142,   143,
     144,   694,    -1,   233,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    -1,    -1,    -1,    -1,
      99,   100,    -1,   102,   103,   104,    -1,    -1,    -1,   108,
      -1,    -1,    -1,   726,   727,    -1,    -1,   730,   731,   732,
      -1,   734,   735,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     743,    -1,    -1,   746,   747,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,    -1,   760,    -1,   213,
      -1,    -1,    -1,    -1,    -1,   305,   769,   307,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,   794,    -1,    -1,    -1,    -1,    -1,    -1,   801,   802,
      -1,    -1,    -1,    -1,   807,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   820,    -1,    -1,
     823,   204,    -1,    -1,   213,    12,    13,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,   842,
      -1,   844,   204,    -1,   847,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   859,    -1,   861,    -1,
     863,    -1,   865,    -1,    -1,    -1,    -1,   870,    -1,    -1,
      -1,    -1,   875,    -1,    -1,    -1,    -1,    -1,   881,    -1,
     883,   884,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   433,    -1,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    -1,    -1,
      -1,    -1,    99,   100,    -1,   102,   103,   104,    -1,    -1,
     923,   108,    -1,    -1,    -1,    -1,    -1,    -1,   931,   932,
     933,   471,   935,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     943,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   957,   142,   143,   144,    -1,   962,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   971,   509,
     510,    -1,    -1,    -1,   977,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,   987,   988,   989,   990,    -1,    -1,
     993,    -1,    -1,    -1,    -1,   247,   248,   249,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   551,   552,   553,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   563,   564,   277,   213,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   581,  1045,    -1,    -1,   204,    -1,    -1,   588,     6,
      -1,    -1,  1055,    -1,  1057,    -1,  1059,    -1,  1061,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,   607,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1083,    -1,    -1,    -1,    -1,   625,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,   346,   347,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   359,    -1,  1112,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1121,  1122,
    1123,  1124,    -1,  1126,  1127,  1128,    -1,    -1,    -1,    -1,
      -1,  1134,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    -1,   397,    -1,    -1,    99,   100,
      -1,   102,   103,   104,  1157,    -1,    -1,   108,    -1,  1162,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    -1,    -1,    -1,    -1,    99,   100,    -1,   102,
     103,   104,    -1,    -1,    -1,   108,    -1,    -1,     6,    -1,
     730,   142,   143,   144,   734,    -1,    -1,    -1,    -1,    -1,
      -1,  1204,    -1,    -1,    -1,    -1,   746,   747,    -1,    -1,
      -1,    -1,  1215,  1216,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,  1230,  1231,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,   794,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,  1277,  1278,  1279,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1288,    -1,  1290,    -1,    -1,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1301,    -1,
      -1,    -1,   842,    -1,   844,    -1,  1309,   847,    -1,    -1,
      -1,  1314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   859,
      -1,   861,    -1,   863,    -1,   865,    -1,    -1,    -1,    -1,
     870,    -1,    -1,    -1,    -1,   875,    -1,  1340,  1341,  1342,
      -1,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    -1,    -1,    -1,    -1,    99,   100,
      -1,   102,   103,   104,    -1,    -1,  1369,   108,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,
    1393,    -1,    -1,    -1,    -1,   935,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,  1407,    -1,    -1,    -1,    -1,  1412,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,  1427,  1428,    -1,    -1,    -1,    -1,
      -1,  1434,  1435,    -1,    -1,   687,  1439,    -1,    -1,   691,
      -1,    -1,    -1,    -1,  1447,    -1,    -1,   987,   988,   989,
     990,    -1,    -1,    -1,  1457,  1458,  1459,    -1,  1461,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1473,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1486,     7,     8,    -1,  1490,    -1,    -1,
    1493,    -1,    -1,    12,    13,    -1,    -1,  1500,  1501,  1502,
    1503,  1504,  1505,  1506,    -1,  1045,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1516,    -1,    -1,    -1,    -1,   770,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1534,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    -1,    -1,    -1,    -1,    99,   100,
      -1,   102,   103,   104,  1557,  1558,     6,   108,    -1,    -1,
      -1,    -1,  1565,    -1,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    -1,    -1,    -1,    -1,
      99,   100,    -1,   102,   103,   104,    -1,    -1,    -1,   108,
      -1,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
    1603,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     6,    -1,    -1,  1621,   204,
    1623,    -1,    -1,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1642,
      -1,  1644,   894,    -1,  1647,    -1,   898,    -1,    -1,    -1,
     902,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1662,
      -1,    -1,   213,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,  1680,    -1,    -1,
      -1,   204,  1685,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   945,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1705,    -1,    -1,    -1,    -1,    -1,    -1,  1712,
      -1,  1714,    -1,  1716,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,  1726,    -1,    -1,    -1,    -1,    -1,  1732,
    1733,  1734,  1735,  1736,  1737,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      -1,    -1,    -1,    -1,   204,  1758,  1759,    -1,    -1,    -1,
    1763,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,  1309,
      -1,    -1,  1775,     8,    -1,    -1,    -1,    -1,    -1,  1031,
    1032,    -1,  1034,  1786,  1036,  1037,    -1,    -1,  1040,  1041,
      -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,  1818,    -1,    -1,    -1,    -1,
      -1,  1824,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1833,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,  1847,    -1,    -1,  1850,    99,   100,
    1853,   102,   103,   104,  1857,    -1,    -1,   108,  1861,    -1,
    1863,  1864,  1865,  1866,  1867,  1868,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1877,    -1,    -1,  1880,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1139,  1140,  1141,
      -1,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,  1151,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,  1457,  1458,   204,
      -1,    -1,    -1,  1926,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1941,    -1,
    1943,  1944,  1945,  1946,  1947,    -1,  1486,    -1,    -1,    -1,
    1490,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,  1217,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1982,
    1983,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,  1241,
    1993,  1994,  1995,  1996,    -1,  1247,    -1,    -1,    -1,    -1,
      -1,  1253,    -1,  1255,  1256,    -1,    -1,    -1,  1260,  1261,
      -1,  1263,    -1,  1265,    -1,  1267,    -1,  1269,  1270,  1271,
      -1,   592,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,  1288,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      69,  1303,    -1,    -1,    -1,  1307,    -1,    -1,    -1,    -1,
      -1,    80,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,    -1,   645,   646,   647,   648,   649,   650,
     651,    -1,    -1,  1623,   655,   656,   657,    -1,    -1,    -1,
     661,   662,    -1,   664,    21,    22,    -1,    -1,   669,   670,
     671,    -1,   673,    -1,     8,    -1,    -1,  1647,    -1,   680,
     681,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1662,    -1,    -1,    -1,    -1,   698,    -1,    -1,
      -1,    -1,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   166,   167,   168,
      -1,   204,    -1,     8,  1406,    -1,    -1,    -1,   211,   178,
     213,   180,   181,    -1,    -1,  1705,    -1,  1419,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,    -1,    -1,  1726,    -1,    -1,    -1,
      -1,    -1,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     147,   148,   149,   150,     8,   152,   153,   154,   155,   156,
     157,    -1,    -1,   160,    -1,    -1,  1488,    -1,    -1,   166,
     167,    -1,    -1,    -1,    -1,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1510,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1518,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1528,    -1,    -1,    -1,
      -1,  1533,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,     8,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,  1559,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1861,    -1,  1863,    -1,    -1,    -1,    -1,    -1,    -1,
    1582,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,  1618,   294,   204,    -1,
     297,   298,   299,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   314,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,
     213,  1941,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,
     204,   992,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1684,    -1,    -1,    -1,    -1,    -1,    -1,  1691,
    1692,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1702,    -1,    -1,    -1,  1025,  1026,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1721,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     427,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,  1779,   213,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,  1798,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   213,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1165,    -1,    -1,    -1,    -1,    -1,
    1171,  1172,  1173,  1174,  1175,    -1,  1177,    -1,  1179,  1180,
      -1,  1182,  1183,    -1,    -1,  1186,  1187,  1188,    -1,    -1,
      -1,    -1,  1193,    -1,    -1,    -1,    -1,  1879,    -1,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    -1,    -1,    69,    -1,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    79,    80,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,  1979,    -1,    -1,
      -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1319,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,  1335,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,  1349,    -1,
      -1,    -1,    -1,  1354,   158,    -1,    -1,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,    -1,    -1,    -1,   173,
     174,   175,   176,   177,   178,    -1,   180,   181,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1386,  1387,    -1,    -1,  1390,
    1391,   195,   196,    -1,    -1,    -1,   200,    -1,    -1,    -1,
      -1,   205,    -1,   207,    -1,   209,   210,    -1,   212,    -1,
     214,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,     3,     4,
     204,    -1,    -1,    -1,     9,    10,    11,    -1,   212,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,
      -1,    86,    -1,    -1,    89,    -1,    91,    -1,    -1,    -1,
    1521,  1522,     5,    -1,  1525,  1526,    -1,    -1,   103,    -1,
    1531,  1532,    -1,    -1,    -1,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,   119,    -1,    -1,   122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    69,    -1,    -1,    -1,
     165,    -1,    -1,    -1,   169,    -1,    -1,    80,   173,   174,
     175,   176,   177,    -1,    -1,    -1,   181,    -1,    -1,    -1,
     967,   968,    -1,    -1,    -1,    -1,   973,   974,    -1,    -1,
     195,   196,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,
     205,    -1,    -1,  1634,  1635,   210,    -1,   212,   213,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   167,   168,    -1,    -1,    52,    53,
      54,    55,    -1,    -1,    -1,   178,    60,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,
      -1,    -1,    86,    -1,    -1,    89,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,    -1,    -1,    -1,    -1,   119,    -1,    -1,   122,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1154,  1155,    -1,
      -1,   165,  1159,  1160,    -1,   169,    -1,    -1,    -1,   173,
     174,   175,   176,   177,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   196,    -1,    -1,    -1,   200,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,   213,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    69,    -1,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    79,    80,    -1,    -1,
      83,    -1,    -1,    86,    -1,    -1,    89,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,   119,    -1,    -1,   122,
    1971,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,    -1,
     173,   174,   175,   176,   177,   178,    -1,   180,   181,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   196,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,   205,    -1,     3,     4,     5,   210,    -1,   212,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      69,    -1,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      79,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,
      89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
     119,    -1,    -1,   122,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,    -1,    -1,    -1,   173,   174,   175,   176,   177,   178,
      -1,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   196,    -1,    -1,
      -1,   200,    -1,    -1,    -1,    -1,   205,    -1,     3,     4,
       5,   210,    -1,   212,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    69,    -1,    71,    72,    73,    -1,
       3,     4,     5,    -1,    79,    80,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    69,    -1,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,    -1,    -1,    -1,   173,   174,
     175,   176,   177,   178,    -1,   180,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,
     205,    -1,    -1,    -1,    -1,   210,    -1,   212,    -1,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   213,    -1,    -1,
     173,   174,   175,   176,   177,   178,    -1,   180,   181,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   196,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,   205,    -1,     3,     4,     5,   210,    -1,   212,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      69,    -1,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      79,    80,    -1,    -1,    -1,    -1,    -1,     4,     5,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    64,    65,    66,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,   165,   166,   167,   168,
     169,    -1,    -1,    -1,   173,   174,   175,   176,   177,   178,
      -1,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   196,    -1,    -1,
      -1,   200,    -1,    -1,    -1,    -1,   205,    -1,     3,     4,
       5,   210,    -1,   212,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,
      55,   178,    -1,   180,   181,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,
      -1,    86,     4,     5,    89,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,   119,    -1,    -1,   122,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
     165,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   174,
     175,   176,   177,    -1,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,
     205,    -1,     3,     4,     5,   210,    -1,   212,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    -1,   178,    -1,   180,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    89,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,    -1,    -1,    -1,    -1,   119,    -1,
      -1,   122,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,   169,    -1,
      -1,    -1,   173,   174,   175,   176,   177,    -1,    -1,    -1,
     181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   196,    -1,    -1,    -1,   200,
      -1,    -1,    -1,    -1,   205,    -1,     3,     4,    -1,   210,
      -1,   212,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    83,    -1,    -1,    86,
      -1,    -1,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,   119,    -1,    -1,   122,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,
      -1,    -1,   169,    -1,    -1,    -1,   173,   174,   175,   176,
     177,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,
      -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,   205,    -1,
       3,     4,    -1,   210,    -1,   212,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      83,    -1,    -1,    86,    -1,    -1,    89,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,   119,    -1,    -1,   122,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,    -1,    -1,    -1,   169,    -1,    -1,    -1,
     173,   174,   175,   176,   177,    -1,    -1,    -1,   181,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   196,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,   205,    -1,     3,     4,    -1,   210,    -1,   212,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,
      89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
     119,    -1,    -1,   122,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,
     169,    -1,    -1,    -1,   173,   174,   175,   176,   177,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   196,    -1,    -1,
      -1,   200,    -1,    -1,    -1,    -1,   205,    -1,     3,     4,
      -1,   210,    -1,   212,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,
      -1,    86,    -1,    -1,    89,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,   119,    -1,    -1,   122,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   174,
     175,   176,   177,    -1,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,
     205,    -1,     3,     4,    -1,   210,    -1,   212,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    89,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,    -1,    -1,    -1,    -1,   119,    -1,
      -1,   122,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,   169,    -1,
      -1,    -1,   173,   174,   175,   176,   177,    -1,    -1,    -1,
     181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   196,    -1,    -1,    -1,   200,
      -1,    -1,    -1,    -1,   205,    -1,     3,     4,    -1,   210,
      -1,   212,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    83,    -1,    -1,    86,
      -1,    -1,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,   119,    -1,    -1,   122,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,
      -1,    -1,   169,    -1,    -1,    -1,   173,   174,   175,   176,
     177,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,
      -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,   205,    -1,
       3,     4,    -1,   210,    -1,   212,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      83,    -1,    -1,    86,    -1,    -1,    89,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,   119,    -1,    -1,   122,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,    -1,    -1,    -1,   169,    -1,    -1,    -1,
     173,   174,   175,   176,   177,    -1,    -1,    -1,   181,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   196,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,   205,    -1,     3,     4,    -1,   210,    -1,   212,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,
      89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
     119,    -1,    -1,   122,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,
     169,    -1,    -1,    -1,   173,   174,   175,   176,   177,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   196,    -1,    -1,
      -1,   200,    -1,    -1,    -1,    -1,   205,    -1,     3,     4,
      -1,   210,    -1,   212,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,
      -1,    86,    -1,    -1,    89,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,   119,    -1,    -1,   122,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   174,
     175,   176,   177,    -1,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,
     205,    -1,     3,     4,    -1,   210,    -1,   212,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    89,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,    -1,    -1,    -1,    -1,   119,    -1,
      -1,   122,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,   169,    -1,
      -1,    -1,   173,   174,   175,   176,   177,    -1,    -1,    -1,
     181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   196,    -1,    -1,    -1,   200,
      -1,    -1,    -1,    -1,   205,    -1,     3,     4,    -1,   210,
      -1,   212,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    52,    53,    54,    55,   204,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,   213,    -1,
      -1,    -1,     3,     4,    71,    72,    73,    -1,     9,    10,
      11,    -1,    79,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    52,    53,    54,    55,   204,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,   165,    -1,
      -1,    -1,   169,    -1,    -1,   212,   173,   174,   175,   176,
     177,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,
      -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,   205,    -1,
      -1,    -1,    -1,   210,    -1,   212,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,   165,   204,    -1,   206,   169,   208,
      -1,    -1,   173,   174,   175,   176,   177,    -1,    -1,    -1,
     181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   196,    -1,    -1,    -1,   200,
      -1,    -1,    -1,    -1,   205,    -1,     3,     4,     5,   210,
      -1,   212,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      -1,    -1,    69,    -1,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    80,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,   165,   166,
     167,   168,   169,    -1,    -1,    -1,   173,   174,   175,   176,
     177,   178,    -1,   180,   181,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,
      -1,    -1,    -1,   200,     3,     4,    -1,    -1,   205,    -1,
       9,    10,    11,   210,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,
      89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
     119,    -1,    -1,   122,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,
     169,    -1,    -1,    -1,   173,   174,   175,   176,   177,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   196,    -1,    -1,
      -1,   200,     3,     4,    -1,    -1,   205,    -1,     9,    10,
      11,   210,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    52,    53,    54,    55,   204,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,     3,     4,
      71,    72,    73,    -1,     9,    10,    11,    -1,    79,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    52,    53,    54,
      55,   204,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
     213,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    79,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,   165,    -1,    -1,    -1,   169,    -1,
      -1,   212,   173,   174,   175,   176,   177,    -1,    -1,    -1,
     181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   196,    -1,    -1,    -1,   200,
      -1,    -1,    -1,    -1,   205,   206,    -1,    -1,    -1,   210,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,
     165,    -1,    -1,    -1,   169,    -1,    -1,   213,   173,   174,
     175,   176,   177,    -1,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,
     205,     3,     4,   208,    -1,   210,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      52,    53,    54,    55,   204,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,     3,     4,    71,
      72,    73,    -1,     9,    10,    11,    -1,    79,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    52,    53,    54,    55,
     204,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,   213,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    79,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,   165,   206,    -1,   208,   169,    -1,   211,
      -1,   173,   174,   175,   176,   177,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   196,    -1,    -1,    -1,   200,    -1,
      -1,    -1,    -1,   205,   206,    -1,    -1,    -1,   210,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,   165,
      -1,    -1,    -1,   169,    -1,    -1,   213,   173,   174,   175,
     176,   177,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     196,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,   205,
       3,     4,   208,     6,   210,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    52,
      53,    54,    55,   204,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,   213,    -1,    -1,    -1,     3,     4,    71,    72,
      73,    -1,     9,    10,    11,    -1,    79,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    52,    53,    54,    55,   204,
      -1,   206,    -1,    60,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,   165,    -1,    -1,    -1,   169,    -1,   211,    -1,
     173,   174,   175,   176,   177,    -1,    -1,    -1,   181,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   196,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,   205,    -1,     0,     1,    -1,   210,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,
      -1,    -1,   169,    -1,    -1,    -1,   173,   174,   175,   176,
     177,    -1,    -1,    -1,   181,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,
      -1,    -1,    -1,   200,    -1,    61,    62,    63,   205,    -1,
      -1,    67,    68,   210,    70,    -1,    -1,    -1,    74,    75,
      -1,    77,    78,    -1,    -1,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      -1,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,   128,   129,   130,     4,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    12,    13,   141,   142,   143,   144,    -1,
      -1,   147,    -1,   149,    -1,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    41,    42,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,   179,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    -1,    -1,    -1,    67,    68,
      -1,    70,    -1,    -1,    -1,    74,    75,    -1,    77,    78,
      -1,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    -1,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,
      -1,    -1,   141,   142,   143,   144,    -1,    -1,   147,    -1,
     149,    -1,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
     179,    -1,   181,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,   211,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,   211,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,   211,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,   211,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,   211,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,   211,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,   211,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,   211,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,   211,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,   211,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,   211,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,   211,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,   211,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,   211,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,   211,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,   211,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,   211,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,   211,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,   211,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,   211,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,   211,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,   208,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,
      -1,    -1,   208,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,   208,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,   208,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,   208,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,   208,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,   208,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,
     208,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,   208,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,   208,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,   208,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,
      -1,    -1,   208,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,   208,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,   208,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,   208,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,   208,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,   208,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,    -1,    -1,   204,    -1,   206,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,   206,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,
     206,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,   206,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,
     204,    -1,   206,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,   206,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,    -1,   206,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,   206,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      -1,    -1,    -1,    -1,   204,    -1,   206,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,   206,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,    -1,    -1,   204,    -1,   206,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,   206,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,
     206,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,   206,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,
     204,    -1,   206,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,   206,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,    -1,   206,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,   206,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      -1,    -1,    -1,    -1,   204,    -1,   206,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,   206,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,    -1,    -1,   204,    -1,   206,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,   206,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,
     206,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,   206,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,
     204,    -1,   206,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,   206,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,    -1,   206,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,   206,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      -1,    -1,    -1,    -1,   204,    -1,   206,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,   206,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,    -1,    -1,   204,    -1,   206,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,   206,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,
     206,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
      -1,   206,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,
     204,    -1,   206,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,   204,    -1,   206,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,    -1,   206,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,    -1,   206,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      -1,    -1,    -1,    -1,   204,    -1,   206,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,    -1,   206,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,    -1,    -1,   204,    -1,   206,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,    -1,   206,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,   204
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   216,   217,     6,     0,     4,    12,    13,    41,
      42,    61,    62,    63,    67,    68,    70,    74,    75,    77,
      78,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   117,   118,   119,   120,   121,   122,
     123,   124,   128,   129,   130,   136,   141,   142,   143,   144,
     147,   149,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   170,   171,   172,   179,
     181,   218,   220,   221,   241,   260,   261,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   293,   294,   295,   296,
     314,   315,     3,     4,     5,     9,    10,    11,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    64,
      65,    66,    69,    71,    72,    73,    79,    80,   158,   165,
     166,   167,   168,   169,   173,   174,   175,   176,   177,   178,
     180,   195,   196,   200,   205,   207,   209,   210,   212,   214,
     239,   297,   298,   310,   311,   314,   315,    13,    89,   205,
     205,     6,   212,     6,     6,     6,     6,   205,     6,     6,
     207,   207,   205,   207,   239,   239,   205,   212,   205,   205,
       4,   205,   212,   205,   205,     4,   212,   205,   205,    93,
      89,    89,     6,   212,    83,    86,    89,    89,    89,    86,
      89,    91,    91,    83,    86,    89,    91,    86,    89,    91,
      86,    89,   205,    86,   147,   163,   164,   212,   195,   196,
     205,   212,   300,   301,   300,   212,    83,    86,    89,   212,
     300,     4,    83,    87,    99,    89,    91,    89,    86,     4,
     158,   212,   314,   315,     4,     6,    83,    86,    89,    86,
      89,     4,     4,     4,     4,     5,    37,    38,    39,    40,
      83,    86,    89,    91,   103,   196,   205,   212,   261,   272,
     297,   303,   304,   305,   314,   315,     4,   205,   205,   205,
       4,   212,   307,   315,     4,   205,   205,   205,     6,     6,
     207,     4,   311,   315,   205,     4,   311,     5,   212,     5,
     212,     4,   297,   314,   207,     6,   205,   212,   205,   207,
     214,   239,     7,   182,   183,   184,   185,   202,   203,   237,
     238,     4,   205,   207,   209,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     205,   205,   205,   239,   239,   239,   239,   205,   239,   239,
     239,   239,   239,   239,   205,   239,   239,   239,     7,   205,
     205,   205,   239,   239,   205,   205,   207,   297,   297,   297,
     206,   297,   208,   297,     4,   147,   148,   315,     4,   261,
     262,   263,   212,   212,     6,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   204,
     212,     6,   205,   207,   238,     6,   297,     4,   310,   311,
     314,   315,   310,   297,   310,   313,   243,   248,   311,   315,
     297,   196,   297,   305,   306,   297,   297,   205,   297,   306,
     297,   297,   205,   306,   297,   297,   303,   205,   212,   306,
     304,   304,   304,   205,   205,   304,   304,   304,   205,   205,
     205,   205,   205,   205,   303,   205,   303,   205,   303,   212,
     212,   297,     4,   303,   307,   212,   212,   300,   300,   300,
     297,   297,   195,   196,   212,   212,   300,   212,   212,   212,
     195,   196,   205,   263,   300,   212,   205,   212,   205,   205,
     205,   304,   304,   303,   205,     4,   207,   207,   263,     6,
       6,   212,   212,   212,   304,   304,   207,   207,   207,   205,
     207,   209,   239,   205,   207,   239,   239,   239,     5,   150,
     212,     5,   150,     5,   150,     5,   150,    83,    86,    89,
      91,   212,   297,   305,   297,   213,   306,     8,   197,     6,
     205,   207,   239,     6,   297,   297,   297,   209,   297,   212,
     150,   297,   297,   297,   297,     6,     6,   212,     6,   263,
       6,   263,   205,   207,   212,   205,   207,   310,   303,   303,
     206,   297,   208,   297,   212,   212,   311,   303,     6,   207,
     297,   297,     4,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   313,   310,   313,   310,   310,
     310,   310,   310,   310,   310,   303,   310,   310,   297,   310,
     310,   310,   313,   310,   297,   311,   297,   310,   310,   310,
     310,   310,   315,   311,   315,     7,   185,   237,   206,     7,
     185,   237,   208,     7,   237,   238,   209,     7,   239,   213,
      83,    86,    89,    91,   260,   297,   306,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   222,   297,   297,     6,   205,   207,   209,   206,
     211,   205,   207,   206,   211,   211,   206,   211,   208,   211,
     242,   208,   242,   211,   211,   206,   197,   211,   213,   206,
     206,   297,   206,   213,   206,   206,   297,   213,   206,   206,
       7,   297,   297,   213,     6,     6,     6,   297,   297,     7,
       7,   290,   290,   297,   254,   297,   311,   255,   297,   311,
     256,   297,   311,   257,   297,   311,   297,     6,   297,     6,
     297,     6,   306,   306,   212,   206,     6,   212,   263,   263,
     211,   211,   211,   300,   300,   262,   262,   211,   297,   297,
     297,   297,   276,   211,   263,   297,   297,   297,   297,   297,
       7,   291,     6,     7,   297,     6,   297,   297,   213,   306,
     306,   306,     6,     6,   297,   297,   297,   297,   297,     4,
     206,   208,   212,   240,   212,   297,   305,   212,   305,   315,
     297,   297,   297,    61,   297,    61,    61,    61,     5,   212,
       5,   212,     5,   212,     5,   212,   306,   206,   213,   297,
     212,   297,   305,   297,   297,   212,   240,   206,   206,   206,
     147,   211,   263,   212,     8,   206,   206,   208,   306,   213,
     213,   263,   208,   206,   211,   213,     7,   185,   237,   206,
       7,   185,   237,   208,   297,   306,     6,     6,   297,   206,
     208,   238,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   211,   240,   240,   240,   240,   240,   240,
     240,   211,   211,   211,   240,   211,   240,   240,   206,   206,
     211,   240,   240,   211,   240,   211,   211,   211,   211,   240,
     240,   240,   206,   240,   299,   312,     6,   211,   211,   206,
     211,   240,   211,   240,   206,   206,   208,    43,    43,   303,
       7,   237,   238,    43,    43,   303,   209,   237,   238,   311,
     297,     6,     4,     4,   212,   308,   240,   212,   212,   212,
     212,   213,   213,     8,     4,   137,   138,   139,   140,   213,
     225,   229,   232,   234,   235,   206,   208,   297,   297,     4,
       6,   192,   219,   306,   297,   297,     6,   306,   297,     6,
     310,     6,   315,     6,   310,   297,   311,     7,   297,   305,
     150,     7,     7,   206,     7,   150,     7,     7,   206,   150,
       7,     7,   297,   206,   213,   212,   206,   206,   297,   303,
       4,   289,     6,   206,   206,   211,   206,   211,   206,   211,
     206,   211,   206,   206,   206,   213,   213,   306,   209,   263,
     213,   213,   300,   297,   297,   213,   213,   297,   300,   211,
     211,   211,   106,   117,   125,   126,   127,   131,   132,   133,
     134,   286,   287,   300,   213,   273,   206,   213,   206,   206,
     206,   297,     6,   297,   206,   208,   208,   213,   213,   213,
     208,   208,   211,   206,   208,   306,   306,   206,   306,   208,
     208,   211,   211,   211,   212,   213,   212,   212,   212,   306,
     306,   306,   306,   213,     8,   306,   206,   208,   306,     7,
       7,     7,   209,   297,   213,   297,   297,     7,   209,   213,
     213,   212,   303,     6,    43,    43,   303,   237,   238,    43,
      43,   303,   237,   238,   213,   213,   208,   238,   209,   238,
     310,   297,   297,   297,   297,   306,   310,   297,   303,   310,
     310,   310,   250,   252,   297,   310,   310,   297,   239,   239,
       6,   297,     6,   239,   239,     6,     4,   147,   148,   297,
       6,     6,     6,     7,   207,   307,   309,     6,   306,   306,
     306,   306,   240,   297,   226,   205,   205,   212,   236,     6,
     238,   238,   206,   208,   192,   310,   206,   206,   208,   206,
     211,     7,   205,   207,   240,   240,   300,    89,    91,   303,
     303,     7,   303,    89,    91,   303,   303,     7,    91,   303,
     303,     6,     7,     7,   306,     7,     7,   106,   288,     6,
       7,   237,   297,   237,   297,   237,   297,   237,   297,     7,
       7,     7,     7,     7,   213,     4,   213,   211,   211,   211,
     213,   213,   300,   300,   300,     4,     6,   297,   212,     6,
     205,     6,   135,     6,   135,     6,   135,     6,   135,   213,
     287,   211,   286,     7,     6,     7,     7,     7,     6,   212,
       6,     6,     6,    89,     7,     6,     6,   297,   209,   213,
     213,   213,   297,   297,   297,   297,   297,   297,   297,   213,
     213,   213,   213,   297,   213,   213,   303,   303,   303,     4,
     211,     8,     8,   206,     4,     4,   211,   303,   213,   239,
     239,     6,   297,     6,   239,   239,     6,   297,     6,   240,
       6,     4,     6,   240,   240,   240,   240,   240,   211,   211,
     240,   206,   240,   240,   211,   211,   240,   251,   211,   240,
     253,   206,   206,   240,   240,   240,   313,   313,     6,   240,
     313,   313,     7,   237,   238,   209,     7,     6,   307,   297,
     211,   213,   213,   213,   213,   213,   237,   205,   297,   297,
     302,   303,   212,   209,     6,     6,   219,     6,   297,   212,
     297,   311,   206,   208,     6,     6,     6,   212,   212,    99,
     259,   259,   303,     6,   212,   212,     6,     6,   303,   212,
       6,     6,     5,   303,   213,   303,   303,     4,     6,   303,
     303,   303,   303,   303,   303,   303,   303,   212,   212,     7,
       6,     7,   297,   297,   297,   212,   212,   211,   213,   211,
     213,   211,   213,   207,     6,   297,   303,   297,     6,     6,
       6,     6,   297,   300,   213,     5,   212,   303,   212,   212,
     212,   303,   306,   212,   297,   208,     4,   240,   206,   208,
     211,   211,   211,   211,   211,   211,   211,   240,     6,     6,
     146,   297,   297,   297,     6,     6,     7,   311,   211,     6,
     240,   313,   313,     6,   240,   313,   313,     6,   237,   238,
     310,   297,   310,     4,     4,   162,     6,   240,   240,     6,
     240,   240,   311,   297,     6,     4,   308,     6,   208,   307,
       6,     6,     6,     6,   303,   223,   297,   211,   211,   211,
     213,   224,   297,     4,   310,   211,   303,   311,     7,     7,
     297,   297,   300,     6,     6,     6,   297,   297,     6,   297,
       5,     6,   212,     6,   150,   258,   297,     6,     6,     6,
       6,     6,     6,     4,     6,     6,   306,   306,   297,   297,
     311,   213,   206,   211,   213,   262,   262,   300,     6,   277,
     300,     6,   278,   300,     6,   279,   297,   213,   211,   206,
     213,   211,     6,   196,   300,     6,   302,   300,   300,     6,
     213,   297,     6,     6,   297,   297,   297,   297,   297,   297,
     297,   303,   211,   213,     8,   213,   206,   212,   297,   311,
     211,   303,     6,   240,   240,     6,   240,   240,   303,   206,
     240,   240,   212,   303,   311,   212,   297,   311,   311,     6,
       6,     6,     6,     6,     6,     7,     6,   209,     6,   206,
     211,   297,   297,   303,   212,   211,   213,     6,   297,   244,
     247,   212,   212,   213,   213,   213,   213,   213,     5,   302,
      87,     6,   212,   213,   213,   212,     6,     6,   212,   297,
     213,   213,   211,   212,   211,   212,   211,   212,   208,     6,
     303,     7,   212,   297,   211,   213,   211,   211,     6,   213,
     240,   240,   211,   211,   211,   211,   211,   145,   297,   297,
     306,     6,     6,   311,   213,     6,     6,     6,     6,     6,
     249,   297,   305,   313,   307,   148,   227,   297,   211,   211,
     302,   297,     6,   211,   250,   252,   303,   303,     6,     6,
       6,     6,     6,     6,   213,   212,   302,   110,   111,   116,
     292,   110,   111,   292,   306,   262,   211,   213,   297,   300,
     286,   297,   300,   286,   297,   300,   286,     6,   211,   213,
     303,   263,   213,   300,     6,   306,   300,   297,   297,   297,
     297,   297,   297,   213,   213,   213,   206,     6,   211,   213,
       7,     7,   213,     6,   212,   297,   297,   213,   297,   213,
     213,   246,   245,   212,   297,   213,   212,   300,   303,     6,
     212,   300,     6,   213,   213,   297,   213,   211,   213,   213,
     211,   213,   213,   211,   213,   303,     6,   106,   213,   274,
     212,   211,   213,   211,   211,   211,   211,   211,   211,     6,
       6,     6,   297,   311,   315,   224,   206,   211,     6,   212,
     211,   250,   250,   297,   213,     6,   300,     6,   300,     6,
       6,   213,     6,   280,   297,     6,     6,   281,   297,     6,
       6,   282,   297,     6,   213,   297,   286,   263,   306,     6,
     300,   306,   297,   297,   297,   297,   297,     7,   205,   213,
     230,   297,   302,   297,   213,   213,   211,   211,   211,   212,
     213,   212,   213,   212,   213,     6,     6,   213,   213,   275,
     213,   211,   213,   211,   211,   211,   211,   211,   311,   206,
       6,   212,   206,   213,   213,   297,   300,   300,   286,     6,
     283,   286,     6,   284,   286,     6,   285,   286,     6,   306,
       6,   297,   297,   297,   297,   297,   228,   310,   233,   212,
       6,   213,   211,   211,   213,   212,   213,   212,   213,   212,
     213,   213,   240,   211,   211,   211,   211,   211,   213,   212,
     302,     6,   297,   297,     6,   286,     6,   286,     6,   286,
       6,   297,   297,   297,   297,   310,     6,   231,   310,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   211,
     213,     6,     6,     6,     6,     6,     6,   310,     6
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
      double x0 = (yyvsp[(3) - (14)].d), x1 = (yyvsp[(5) - (14)].d), y0 = (yyvsp[(7) - (14)].d), y1 = (yyvsp[(9) - (14)].d), ys = (yyvsp[(11) - (14)].d);
      int N = (int)(yyvsp[(13) - (14)].d);
      std::vector<double> y(N);
      if(!catenary(x0, x1, y0, y1, ys, N, &y[0]))
        Msg::Warning("Catenary did not converge, using linear interpolation");
      (yyval.l) = List_Create(N,10,sizeof(double));
      for(int i = 0; i < N; i++) List_Add((yyval.l), &y[i]);
    ;}
    break;

  case 509:
#line 5995 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 510:
#line 6000 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 511:
#line 6004 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 512:
#line 6008 "Gmsh.y"
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
#line 6020 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 514:
#line 6024 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 515:
#line 6036 "Gmsh.y"
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
#line 6053 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 517:
#line 6063 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 518:
#line 6067 "Gmsh.y"
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
#line 6082 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 520:
#line 6087 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 521:
#line 6094 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 522:
#line 6098 "Gmsh.y"
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
#line 6111 "Gmsh.y"
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
#line 6125 "Gmsh.y"
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
#line 6139 "Gmsh.y"
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
#line 6153 "Gmsh.y"
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
#line 6167 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 528:
#line 6175 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 529:
#line 6186 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 530:
#line 6190 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 531:
#line 6194 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 532:
#line 6202 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 533:
#line 6208 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 534:
#line 6214 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 535:
#line 6222 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 536:
#line 6230 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 537:
#line 6237 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 538:
#line 6245 "Gmsh.y"
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

  case 539:
#line 6260 "Gmsh.y"
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

  case 540:
#line 6274 "Gmsh.y"
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

  case 541:
#line 6288 "Gmsh.y"
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

  case 542:
#line 6300 "Gmsh.y"
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

  case 543:
#line 6316 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 544:
#line 6325 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 545:
#line 6334 "Gmsh.y"
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

  case 546:
#line 6344 "Gmsh.y"
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

  case 547:
#line 6355 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 548:
#line 6363 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 549:
#line 6371 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 550:
#line 6375 "Gmsh.y"
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

  case 551:
#line 6394 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 552:
#line 6401 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 553:
#line 6407 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 554:
#line 6414 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 555:
#line 6421 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 556:
#line 6423 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 557:
#line 6434 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 558:
#line 6439 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 559:
#line 6445 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 560:
#line 6454 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 561:
#line 6467 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 562:
#line 6470 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 563:
#line 6474 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13268 "Gmsh.tab.cpp"
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


#line 6477 "Gmsh.y"


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

