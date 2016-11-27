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
     tPrintf = 293,
     tError = 294,
     tStr = 295,
     tSprintf = 296,
     tStrCat = 297,
     tStrPrefix = 298,
     tStrRelative = 299,
     tStrReplace = 300,
     tAbsolutePath = 301,
     tDirName = 302,
     tStrSub = 303,
     tStrLen = 304,
     tFind = 305,
     tStrFind = 306,
     tStrCmp = 307,
     tStrChoice = 308,
     tUpperCase = 309,
     tLowerCase = 310,
     tLowerCaseIn = 311,
     tTextAttributes = 312,
     tBoundingBox = 313,
     tDraw = 314,
     tSetChanged = 315,
     tToday = 316,
     tFixRelativePath = 317,
     tCurrentDirectory = 318,
     tSyncModel = 319,
     tNewModel = 320,
     tOnelabAction = 321,
     tOnelabRun = 322,
     tCpu = 323,
     tMemory = 324,
     tTotalMemory = 325,
     tCreateTopology = 326,
     tCreateTopologyNoHoles = 327,
     tDistanceFunction = 328,
     tDefineConstant = 329,
     tUndefineConstant = 330,
     tDefineNumber = 331,
     tDefineString = 332,
     tSetNumber = 333,
     tSetString = 334,
     tPoint = 335,
     tCircle = 336,
     tEllipse = 337,
     tLine = 338,
     tSphere = 339,
     tPolarSphere = 340,
     tSurface = 341,
     tSpline = 342,
     tVolume = 343,
     tCharacteristic = 344,
     tLength = 345,
     tParametric = 346,
     tElliptic = 347,
     tRefineMesh = 348,
     tAdaptMesh = 349,
     tRelocateMesh = 350,
     tPlane = 351,
     tRuled = 352,
     tTransfinite = 353,
     tComplex = 354,
     tPhysical = 355,
     tCompound = 356,
     tPeriodic = 357,
     tUsing = 358,
     tPlugin = 359,
     tDegenerated = 360,
     tRecursive = 361,
     tRotate = 362,
     tTranslate = 363,
     tSymmetry = 364,
     tDilate = 365,
     tExtrude = 366,
     tLevelset = 367,
     tAffine = 368,
     tRecombine = 369,
     tSmoother = 370,
     tSplit = 371,
     tDelete = 372,
     tCoherence = 373,
     tIntersect = 374,
     tMeshAlgorithm = 375,
     tReverse = 376,
     tLayers = 377,
     tScaleLast = 378,
     tHole = 379,
     tAlias = 380,
     tAliasWithOptions = 381,
     tCopyOptions = 382,
     tQuadTriAddVerts = 383,
     tQuadTriNoNewVerts = 384,
     tQuadTriSngl = 385,
     tQuadTriDbl = 386,
     tRecombLaterals = 387,
     tTransfQuadTri = 388,
     tText2D = 389,
     tText3D = 390,
     tInterpolationScheme = 391,
     tTime = 392,
     tCombine = 393,
     tBSpline = 394,
     tBezier = 395,
     tNurbs = 396,
     tNurbsOrder = 397,
     tNurbsKnots = 398,
     tColor = 399,
     tColorTable = 400,
     tFor = 401,
     tIn = 402,
     tEndFor = 403,
     tIf = 404,
     tElseIf = 405,
     tElse = 406,
     tEndIf = 407,
     tExit = 408,
     tAbort = 409,
     tField = 410,
     tReturn = 411,
     tCall = 412,
     tSlide = 413,
     tMacro = 414,
     tShow = 415,
     tHide = 416,
     tGetValue = 417,
     tGetStringValue = 418,
     tGetEnv = 419,
     tGetString = 420,
     tGetNumber = 421,
     tHomology = 422,
     tCohomology = 423,
     tBetti = 424,
     tExists = 425,
     tFileExists = 426,
     tGMSH_MAJOR_VERSION = 427,
     tGMSH_MINOR_VERSION = 428,
     tGMSH_PATCH_VERSION = 429,
     tGmshExecutableName = 430,
     tSetPartition = 431,
     tNameToString = 432,
     tStringToName = 433,
     tAFFECTDIVIDE = 434,
     tAFFECTTIMES = 435,
     tAFFECTMINUS = 436,
     tAFFECTPLUS = 437,
     tOR = 438,
     tAND = 439,
     tNOTEQUAL = 440,
     tEQUAL = 441,
     tGREATEROREQUAL = 442,
     tLESSOREQUAL = 443,
     UNARYPREC = 444,
     tMINUSMINUS = 445,
     tPLUSPLUS = 446
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
#define tPrintf 293
#define tError 294
#define tStr 295
#define tSprintf 296
#define tStrCat 297
#define tStrPrefix 298
#define tStrRelative 299
#define tStrReplace 300
#define tAbsolutePath 301
#define tDirName 302
#define tStrSub 303
#define tStrLen 304
#define tFind 305
#define tStrFind 306
#define tStrCmp 307
#define tStrChoice 308
#define tUpperCase 309
#define tLowerCase 310
#define tLowerCaseIn 311
#define tTextAttributes 312
#define tBoundingBox 313
#define tDraw 314
#define tSetChanged 315
#define tToday 316
#define tFixRelativePath 317
#define tCurrentDirectory 318
#define tSyncModel 319
#define tNewModel 320
#define tOnelabAction 321
#define tOnelabRun 322
#define tCpu 323
#define tMemory 324
#define tTotalMemory 325
#define tCreateTopology 326
#define tCreateTopologyNoHoles 327
#define tDistanceFunction 328
#define tDefineConstant 329
#define tUndefineConstant 330
#define tDefineNumber 331
#define tDefineString 332
#define tSetNumber 333
#define tSetString 334
#define tPoint 335
#define tCircle 336
#define tEllipse 337
#define tLine 338
#define tSphere 339
#define tPolarSphere 340
#define tSurface 341
#define tSpline 342
#define tVolume 343
#define tCharacteristic 344
#define tLength 345
#define tParametric 346
#define tElliptic 347
#define tRefineMesh 348
#define tAdaptMesh 349
#define tRelocateMesh 350
#define tPlane 351
#define tRuled 352
#define tTransfinite 353
#define tComplex 354
#define tPhysical 355
#define tCompound 356
#define tPeriodic 357
#define tUsing 358
#define tPlugin 359
#define tDegenerated 360
#define tRecursive 361
#define tRotate 362
#define tTranslate 363
#define tSymmetry 364
#define tDilate 365
#define tExtrude 366
#define tLevelset 367
#define tAffine 368
#define tRecombine 369
#define tSmoother 370
#define tSplit 371
#define tDelete 372
#define tCoherence 373
#define tIntersect 374
#define tMeshAlgorithm 375
#define tReverse 376
#define tLayers 377
#define tScaleLast 378
#define tHole 379
#define tAlias 380
#define tAliasWithOptions 381
#define tCopyOptions 382
#define tQuadTriAddVerts 383
#define tQuadTriNoNewVerts 384
#define tQuadTriSngl 385
#define tQuadTriDbl 386
#define tRecombLaterals 387
#define tTransfQuadTri 388
#define tText2D 389
#define tText3D 390
#define tInterpolationScheme 391
#define tTime 392
#define tCombine 393
#define tBSpline 394
#define tBezier 395
#define tNurbs 396
#define tNurbsOrder 397
#define tNurbsKnots 398
#define tColor 399
#define tColorTable 400
#define tFor 401
#define tIn 402
#define tEndFor 403
#define tIf 404
#define tElseIf 405
#define tElse 406
#define tEndIf 407
#define tExit 408
#define tAbort 409
#define tField 410
#define tReturn 411
#define tCall 412
#define tSlide 413
#define tMacro 414
#define tShow 415
#define tHide 416
#define tGetValue 417
#define tGetStringValue 418
#define tGetEnv 419
#define tGetString 420
#define tGetNumber 421
#define tHomology 422
#define tCohomology 423
#define tBetti 424
#define tExists 425
#define tFileExists 426
#define tGMSH_MAJOR_VERSION 427
#define tGMSH_MINOR_VERSION 428
#define tGMSH_PATCH_VERSION 429
#define tGmshExecutableName 430
#define tSetPartition 431
#define tNameToString 432
#define tStringToName 433
#define tAFFECTDIVIDE 434
#define tAFFECTTIMES 435
#define tAFFECTMINUS 436
#define tAFFECTPLUS 437
#define tOR 438
#define tAND 439
#define tNOTEQUAL 440
#define tEQUAL 441
#define tGREATEROREQUAL 442
#define tLESSOREQUAL 443
#define UNARYPREC 444
#define tMINUSMINUS 445
#define tPLUSPLUS 446




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
#line 610 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 623 "Gmsh.tab.cpp"

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
#define YYLAST   12525

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  212
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  560
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2009

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   446

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   197,     2,   207,     2,   196,     2,     2,
     202,   203,   194,   192,   208,   193,   206,   195,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     188,     2,   189,   183,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   204,     2,   205,   201,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   209,     2,   210,   211,     2,     2,     2,
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
     175,   176,   177,   178,   179,   180,   181,   182,   184,   185,
     186,   187,   190,   191,   198,   199,   200
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
    2950,  2955,  2960,  2967,  2974,  2981,  2988,  2990,  2992,  2996,
    3000,  3010,  3018,  3020,  3026,  3030,  3037,  3039,  3043,  3045,
    3047,  3052,  3057,  3062,  3067,  3071,  3078,  3080,  3085,  3087,
    3089,  3091,  3096,  3103,  3108,  3115,  3120,  3125,  3130,  3139,
    3144,  3149,  3154,  3159,  3168,  3177,  3184,  3189,  3196,  3201,
    3203,  3208,  3213,  3214,  3221,  3223,  3227,  3233,  3239,  3241,
    3243
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     213,     0,    -1,   214,    -1,     1,     6,    -1,    -1,   214,
     215,    -1,   218,    -1,   217,    -1,   238,    -1,   257,    -1,
     258,    -1,   262,    -1,   263,    -1,   264,    -1,   265,    -1,
     269,    -1,   290,    -1,   291,    -1,   268,    -1,   267,    -1,
     266,    -1,   261,    -1,   293,    -1,   189,    -1,   189,   189,
      -1,    38,   202,   307,   203,     6,    -1,    39,   202,   307,
     203,     6,    -1,    38,   202,   307,   203,   216,   307,     6,
      -1,    38,   202,   307,   208,   303,   203,     6,    -1,    39,
     202,   307,   208,   303,   203,     6,    -1,    38,   202,   307,
     208,   303,   203,   216,   307,     6,    -1,     4,   307,   209,
     219,   210,     6,    -1,   125,     4,   204,   294,   205,     6,
      -1,   126,     4,   204,   294,   205,     6,    -1,   127,     4,
     204,   294,   208,   294,   205,     6,    -1,    -1,   219,   222,
      -1,   219,   226,    -1,   219,   229,    -1,   219,   231,    -1,
     219,   232,    -1,   294,    -1,   220,   208,   294,    -1,   294,
      -1,   221,   208,   294,    -1,    -1,    -1,     4,   223,   202,
     220,   203,   224,   209,   221,   210,     6,    -1,   307,    -1,
     225,   208,   307,    -1,    -1,   134,   202,   294,   208,   294,
     208,   294,   203,   227,   209,   225,   210,     6,    -1,   307,
      -1,   228,   208,   307,    -1,    -1,   135,   202,   294,   208,
     294,   208,   294,   208,   294,   203,   230,   209,   228,   210,
       6,    -1,   136,   209,   299,   210,   209,   299,   210,     6,
      -1,   136,   209,   299,   210,   209,   299,   210,   209,   299,
     210,   209,   299,   210,     6,    -1,    -1,   137,   233,   209,
     221,   210,     6,    -1,     7,    -1,   182,    -1,   181,    -1,
     180,    -1,   179,    -1,   200,    -1,   199,    -1,   202,    -1,
     204,    -1,   203,    -1,   205,    -1,    74,   204,   240,   205,
       6,    -1,    75,   204,   245,   205,     6,    -1,    78,   236,
     308,   208,   294,   237,     6,    -1,    79,   236,   312,   208,
     308,   237,     6,    -1,   312,   234,   300,     6,    -1,   312,
     235,     6,    -1,     4,   204,   205,   234,   300,     6,    -1,
     311,   204,   205,   234,   300,     6,    -1,     4,   204,   294,
     205,   234,   294,     6,    -1,   311,   204,   294,   205,   234,
     294,     6,    -1,     4,   204,   294,   205,   235,     6,    -1,
     311,   204,   294,   205,   235,     6,    -1,     4,   236,   209,
     303,   210,   237,   234,   300,     6,    -1,   311,   236,   209,
     303,   210,   237,   234,   300,     6,    -1,     4,   202,   203,
     234,   300,     6,    -1,   311,   202,   203,   234,   300,     6,
      -1,     4,   202,   294,   203,   234,   294,     6,    -1,   311,
     202,   294,   203,   234,   294,     6,    -1,     4,   202,   294,
     203,   235,     6,    -1,   311,   202,   294,   203,   235,     6,
      -1,   312,     7,   308,     6,    -1,     4,   204,   205,     7,
      40,   236,   237,     6,    -1,   311,   204,   205,     7,    40,
     236,   237,     6,    -1,     4,   204,   205,     7,    40,   236,
     310,   237,     6,    -1,   311,   204,   205,     7,    40,   236,
     310,   237,     6,    -1,     4,   204,   205,   182,    40,   236,
     310,   237,     6,    -1,   311,   204,   205,   182,    40,   236,
     310,   237,     6,    -1,     4,   202,   203,     7,    40,   236,
     237,     6,    -1,   311,   202,   203,     7,    40,   236,   237,
       6,    -1,     4,   202,   203,     7,    40,   236,   310,   237,
       6,    -1,   311,   202,   203,     7,    40,   236,   310,   237,
       6,    -1,     4,   202,   203,   182,    40,   236,   310,   237,
       6,    -1,   311,   202,   203,   182,    40,   236,   310,   237,
       6,    -1,     4,   206,     4,     7,   308,     6,    -1,     4,
     204,   294,   205,   206,     4,     7,   308,     6,    -1,     4,
     206,     4,   234,   294,     6,    -1,     4,   204,   294,   205,
     206,     4,   234,   294,     6,    -1,     4,   206,     4,   235,
       6,    -1,     4,   204,   294,   205,   206,     4,   235,     6,
      -1,     4,   206,   144,   206,     4,     7,   304,     6,    -1,
       4,   204,   294,   205,   206,   144,   206,     4,     7,   304,
       6,    -1,     4,   206,   145,     7,   305,     6,    -1,     4,
     204,   294,   205,   206,   145,     7,   305,     6,    -1,     4,
     155,     7,   294,     6,    -1,   155,   204,   294,   205,     7,
       4,     6,    -1,   155,   204,   294,   205,   206,     4,     7,
     294,     6,    -1,   155,   204,   294,   205,   206,     4,     7,
     308,     6,    -1,   155,   204,   294,   205,   206,     4,     7,
     209,   303,   210,     6,    -1,   155,   204,   294,   205,   206,
       4,     6,    -1,   104,   202,     4,   203,   206,     4,     7,
     294,     6,    -1,   104,   202,     4,   203,   206,     4,     7,
     308,     6,    -1,    -1,   208,    -1,    -1,   240,   239,   312,
      -1,   240,   239,   312,     7,   294,    -1,    -1,   240,   239,
     312,     7,   209,   300,   241,   247,   210,    -1,    -1,   240,
     239,   312,   204,   205,     7,   209,   300,   242,   247,   210,
      -1,    -1,   240,   239,   312,   202,   203,     7,   209,   300,
     243,   247,   210,    -1,   240,   239,   312,     7,   308,    -1,
      -1,   240,   239,   312,     7,   209,   308,   244,   249,   210,
      -1,    -1,   245,   239,   307,    -1,   294,     7,   308,    -1,
     246,   208,   294,     7,   308,    -1,   302,     7,   312,   202,
     203,    -1,    -1,   247,   248,    -1,   208,     4,   300,    -1,
     208,     4,   209,   246,   210,    -1,   208,     4,   308,    -1,
      -1,   249,   250,    -1,   208,     4,   294,    -1,   208,     4,
     308,    -1,   208,   159,   308,    -1,   208,     4,   209,   310,
     210,    -1,   294,    -1,   308,    -1,   308,   208,   294,    -1,
     294,    -1,   308,    -1,   308,   208,   294,    -1,   294,    -1,
     308,    -1,   308,   208,   294,    -1,   294,    -1,   308,    -1,
     308,   208,   294,    -1,    -1,   147,    84,   209,   294,   210,
      -1,    -1,    96,   297,    -1,    80,   202,   294,   203,     7,
     297,     6,    -1,   100,    80,   202,   251,   203,   234,   300,
       6,    -1,    89,    90,   300,     7,   294,     6,    -1,    83,
     202,   294,   203,     7,   300,     6,    -1,   105,    83,   300,
       6,    -1,    87,   202,   294,   203,     7,   300,     6,    -1,
      81,   202,   294,   203,     7,   300,   256,     6,    -1,    82,
     202,   294,   203,     7,   300,   256,     6,    -1,   139,   202,
     294,   203,     7,   300,     6,    -1,   140,   202,   294,   203,
       7,   300,     6,    -1,   141,   202,   294,   203,     7,   300,
     143,   300,   142,   294,     6,    -1,    83,     4,   202,   294,
     203,     7,   300,     6,    -1,   101,    83,   300,     6,    -1,
     101,    83,   202,   294,   203,     7,   300,     6,    -1,   100,
      83,   202,   252,   203,   234,   300,     6,    -1,    96,    86,
     202,   294,   203,     7,   300,     6,    -1,    97,    86,   202,
     294,   203,     7,   300,   255,     6,    -1,    12,    13,     6,
      -1,    13,    86,   294,     6,    -1,    91,    86,   202,   294,
     203,     7,     5,     5,     5,     6,    -1,    84,   202,   294,
     203,     7,   300,     6,    -1,    85,   202,   294,   203,     7,
     300,     6,    -1,    86,     4,   202,   294,   203,     7,   300,
       6,    -1,   101,    86,   300,     6,    -1,   101,    86,   202,
     294,   203,     7,   300,     6,    -1,   101,    86,   202,   294,
     203,     7,   300,     4,   209,   299,   210,     6,    -1,   100,
      86,   202,   253,   203,   234,   300,     6,    -1,    99,    88,
     202,   294,   203,     7,   300,     6,    -1,    88,   202,   294,
     203,     7,   300,     6,    -1,   101,    88,   300,     6,    -1,
     101,    88,   202,   294,   203,     7,   300,     6,    -1,   100,
      88,   202,   254,   203,   234,   300,     6,    -1,   108,   297,
     209,   259,   210,    -1,   107,   209,   297,   208,   297,   208,
     294,   210,   209,   259,   210,    -1,   109,   297,   209,   259,
     210,    -1,   110,   209,   297,   208,   294,   210,   209,   259,
     210,    -1,   110,   209,   297,   208,   297,   210,   209,   259,
     210,    -1,     4,   209,   259,   210,    -1,   119,    83,   209,
     303,   210,    86,   209,   294,   210,    -1,   116,    83,   202,
     294,   203,   209,   303,   210,     6,    -1,   260,    -1,   258,
      -1,    -1,   260,   257,    -1,   260,    80,   209,   303,   210,
       6,    -1,   260,    83,   209,   303,   210,     6,    -1,   260,
      86,   209,   303,   210,     6,    -1,   260,    88,   209,   303,
     210,     6,    -1,   112,    96,   202,   294,   203,     7,   300,
       6,    -1,   112,    80,   202,   294,   203,     7,   209,   299,
     210,     6,    -1,   112,    96,   202,   294,   203,     7,   209,
     297,   208,   297,   208,   303,   210,     6,    -1,   112,    96,
     202,   294,   203,     7,   209,   297,   208,   297,   208,   297,
     208,   303,   210,     6,    -1,   112,    84,   202,   294,   203,
       7,   209,   297,   208,   303,   210,     6,    -1,   112,     4,
     202,   294,   203,     7,   300,     6,    -1,   112,     4,   202,
     294,   203,     7,     5,     6,    -1,   112,     4,   209,   294,
     210,     6,    -1,   112,     4,   202,   294,   203,     7,   209,
     297,   208,   297,   208,   303,   210,     6,    -1,   117,   209,
     260,   210,    -1,   117,   155,   204,   294,   205,     6,    -1,
     117,     4,   204,   294,   205,     6,    -1,   117,   312,     6,
      -1,   117,     4,     4,     6,    -1,   144,   304,   209,   260,
     210,    -1,   106,   144,   304,   209,   260,   210,    -1,   176,
     294,   209,   260,   210,    -1,   160,     5,     6,    -1,   161,
       5,     6,    -1,   160,   209,   260,   210,    -1,   106,   160,
     209,   260,   210,    -1,   161,   209,   260,   210,    -1,   106,
     161,   209,   260,   210,    -1,     4,   308,     6,    -1,    67,
     202,   310,   203,     6,    -1,     4,     4,   204,   294,   205,
     307,     6,    -1,     4,     4,     4,   204,   294,   205,     6,
      -1,     4,   294,     6,    -1,   104,   202,     4,   203,   206,
       4,     6,    -1,   138,     4,     6,    -1,   153,     6,    -1,
     154,     6,    -1,    64,     6,    -1,    65,     6,    -1,    58,
       6,    -1,    58,   209,   294,   208,   294,   208,   294,   208,
     294,   208,   294,   208,   294,   210,     6,    -1,    59,     6,
      -1,    60,     6,    -1,    71,     6,    -1,    72,     6,    -1,
      93,     6,    -1,    94,   209,   303,   210,   209,   303,   210,
     209,   299,   210,   209,   294,   208,   294,   210,     6,    -1,
     158,   202,   209,   303,   210,   208,   308,   208,   308,   203,
       6,    -1,   146,   202,   294,     8,   294,   203,    -1,   146,
     202,   294,     8,   294,     8,   294,   203,    -1,   146,     4,
     147,   209,   294,     8,   294,   210,    -1,   146,     4,   147,
     209,   294,     8,   294,     8,   294,   210,    -1,   148,    -1,
     159,     4,    -1,   159,   308,    -1,   156,    -1,   157,   312,
       6,    -1,   157,   308,     6,    -1,   149,   202,   294,   203,
      -1,   150,   202,   294,   203,    -1,   151,    -1,   152,    -1,
     111,   297,   209,   260,   210,    -1,   111,   209,   297,   208,
     297,   208,   294,   210,   209,   260,   210,    -1,   111,   209,
     297,   208,   297,   208,   297,   208,   294,   210,   209,   260,
     210,    -1,    -1,   111,   297,   209,   260,   270,   283,   210,
      -1,    -1,   111,   209,   297,   208,   297,   208,   294,   210,
     209,   260,   271,   283,   210,    -1,    -1,   111,   209,   297,
     208,   297,   208,   297,   208,   294,   210,   209,   260,   272,
     283,   210,    -1,    -1,   111,   209,   260,   273,   283,   210,
      -1,   111,    80,   209,   294,   208,   297,   210,     6,    -1,
     111,    83,   209,   294,   208,   297,   210,     6,    -1,   111,
      86,   209,   294,   208,   297,   210,     6,    -1,   111,    80,
     209,   294,   208,   297,   208,   297,   208,   294,   210,     6,
      -1,   111,    83,   209,   294,   208,   297,   208,   297,   208,
     294,   210,     6,    -1,   111,    86,   209,   294,   208,   297,
     208,   297,   208,   294,   210,     6,    -1,   111,    80,   209,
     294,   208,   297,   208,   297,   208,   297,   208,   294,   210,
       6,    -1,   111,    83,   209,   294,   208,   297,   208,   297,
     208,   297,   208,   294,   210,     6,    -1,   111,    86,   209,
     294,   208,   297,   208,   297,   208,   297,   208,   294,   210,
       6,    -1,    -1,   111,    80,   209,   294,   208,   297,   210,
     274,   209,   283,   210,     6,    -1,    -1,   111,    83,   209,
     294,   208,   297,   210,   275,   209,   283,   210,     6,    -1,
      -1,   111,    86,   209,   294,   208,   297,   210,   276,   209,
     283,   210,     6,    -1,    -1,   111,    80,   209,   294,   208,
     297,   208,   297,   208,   294,   210,   277,   209,   283,   210,
       6,    -1,    -1,   111,    83,   209,   294,   208,   297,   208,
     297,   208,   294,   210,   278,   209,   283,   210,     6,    -1,
      -1,   111,    86,   209,   294,   208,   297,   208,   297,   208,
     294,   210,   279,   209,   283,   210,     6,    -1,    -1,   111,
      80,   209,   294,   208,   297,   208,   297,   208,   297,   208,
     294,   210,   280,   209,   283,   210,     6,    -1,    -1,   111,
      83,   209,   294,   208,   297,   208,   297,   208,   297,   208,
     294,   210,   281,   209,   283,   210,     6,    -1,    -1,   111,
      86,   209,   294,   208,   297,   208,   297,   208,   297,   208,
     294,   210,   282,   209,   283,   210,     6,    -1,   284,    -1,
     283,   284,    -1,   122,   209,   294,   210,     6,    -1,   122,
     209,   300,   208,   300,   210,     6,    -1,   122,   209,   300,
     208,   300,   208,   300,   210,     6,    -1,   123,     6,    -1,
     114,     6,    -1,   114,   294,     6,    -1,   130,     6,    -1,
     130,   132,     6,    -1,   131,     6,    -1,   131,   132,     6,
      -1,   128,     6,    -1,   128,   132,     6,    -1,   129,     6,
      -1,   129,   132,     6,    -1,   124,   202,   294,   203,     7,
     300,   103,   294,     6,    -1,   103,     4,   204,   294,   205,
       6,    -1,    -1,   103,     4,   294,    -1,    -1,     4,    -1,
      -1,     7,   300,    -1,    -1,     7,   294,    -1,    -1,   113,
     300,    -1,    98,    83,   301,     7,   294,   285,     6,    -1,
      98,    86,   301,   287,   286,     6,    -1,    92,    86,   209,
     294,   210,     7,   300,     6,    -1,    98,    88,   301,   287,
       6,    -1,   133,   301,     6,    -1,   120,    86,   209,   303,
     210,     7,   294,     6,    -1,   114,    86,   301,   288,     6,
      -1,   114,    88,   301,     6,    -1,   115,    86,   300,     7,
     294,     6,    -1,   102,    83,   209,   303,   210,     7,   209,
     303,   210,   289,     6,    -1,   102,    86,   209,   303,   210,
       7,   209,   303,   210,   289,     6,    -1,   102,    83,   209,
     303,   210,     7,   209,   303,   210,   107,   209,   297,   208,
     297,   208,   294,   210,     6,    -1,   102,    86,   209,   303,
     210,     7,   209,   303,   210,   107,   209,   297,   208,   297,
     208,   294,   210,     6,    -1,   102,    83,   209,   303,   210,
       7,   209,   303,   210,   108,   297,     6,    -1,   102,    86,
     209,   303,   210,     7,   209,   303,   210,   108,   297,     6,
      -1,   102,    86,   294,   209,   303,   210,     7,   294,   209,
     303,   210,     6,    -1,    80,   209,   303,   210,   147,    86,
     209,   294,   210,     6,    -1,    83,   209,   303,   210,   147,
      86,   209,   294,   210,     6,    -1,    80,   209,   303,   210,
     147,    88,   209,   294,   210,     6,    -1,    83,   209,   303,
     210,   147,    88,   209,   294,   210,     6,    -1,    86,   209,
     303,   210,   147,    88,   209,   294,   210,     6,    -1,   121,
      86,   301,     6,    -1,   121,    83,   301,     6,    -1,    95,
      80,   301,     6,    -1,    95,    83,   301,     6,    -1,    95,
      86,   301,     6,    -1,   118,     6,    -1,   118,     4,     6,
      -1,   118,    80,   209,   303,   210,     6,    -1,   167,    -1,
     168,    -1,   169,    -1,   292,     6,    -1,   292,   209,   300,
     210,     6,    -1,   292,   209,   300,   208,   300,   210,     6,
      -1,   292,   202,   300,   203,   209,   300,   208,   300,   210,
       6,    -1,   295,    -1,   202,   294,   203,    -1,   193,   294,
      -1,   192,   294,    -1,   197,   294,    -1,   294,   193,   294,
      -1,   294,   192,   294,    -1,   294,   194,   294,    -1,   294,
     195,   294,    -1,   294,   196,   294,    -1,   294,   201,   294,
      -1,   294,   188,   294,    -1,   294,   189,   294,    -1,   294,
     191,   294,    -1,   294,   190,   294,    -1,   294,   187,   294,
      -1,   294,   186,   294,    -1,   294,   185,   294,    -1,   294,
     184,   294,    -1,   294,   183,   294,     8,   294,    -1,    15,
     236,   294,   237,    -1,    16,   236,   294,   237,    -1,    17,
     236,   294,   237,    -1,    18,   236,   294,   237,    -1,    19,
     236,   294,   237,    -1,    20,   236,   294,   237,    -1,    21,
     236,   294,   237,    -1,    22,   236,   294,   237,    -1,    23,
     236,   294,   237,    -1,    25,   236,   294,   237,    -1,    26,
     236,   294,   208,   294,   237,    -1,    27,   236,   294,   237,
      -1,    28,   236,   294,   237,    -1,    29,   236,   294,   237,
      -1,    30,   236,   294,   237,    -1,    31,   236,   294,   237,
      -1,    32,   236,   294,   237,    -1,    33,   236,   294,   237,
      -1,    34,   236,   294,   208,   294,   237,    -1,    35,   236,
     294,   208,   294,   237,    -1,    36,   236,   294,   208,   294,
     237,    -1,    24,   236,   294,   237,    -1,     3,    -1,     9,
      -1,    14,    -1,    10,    -1,    11,    -1,   172,    -1,   173,
      -1,   174,    -1,    68,    -1,    69,    -1,    70,    -1,    -1,
      76,   236,   294,   296,   247,   237,    -1,   166,   236,   307,
     237,    -1,   166,   236,   307,   208,   294,   237,    -1,   312,
      -1,     4,   204,   294,   205,    -1,     4,   202,   294,   203,
      -1,   311,   204,   294,   205,    -1,   311,   202,   294,   203,
      -1,   170,   202,   312,   203,    -1,   171,   202,   308,   203,
      -1,   207,   312,   236,   237,    -1,   312,   235,    -1,     4,
     204,   294,   205,   235,    -1,     4,   202,   294,   203,   235,
      -1,   311,   204,   294,   205,   235,    -1,   311,   202,   294,
     203,   235,    -1,     4,   206,     4,    -1,     4,   204,   294,
     205,   206,     4,    -1,     4,   206,     4,   235,    -1,     4,
     204,   294,   205,   206,     4,   235,    -1,   162,   202,   307,
     208,   294,   203,    -1,    50,   202,   300,   208,   300,   203,
      -1,    51,   236,   307,   208,   307,   237,    -1,    49,   236,
     307,   237,    -1,    52,   236,   307,   208,   307,   237,    -1,
      57,   202,   310,   203,    -1,   298,    -1,   193,   297,    -1,
     192,   297,    -1,   297,   193,   297,    -1,   297,   192,   297,
      -1,   209,   294,   208,   294,   208,   294,   208,   294,   208,
     294,   210,    -1,   209,   294,   208,   294,   208,   294,   208,
     294,   210,    -1,   209,   294,   208,   294,   208,   294,   210,
      -1,   202,   294,   208,   294,   208,   294,   203,    -1,   300,
      -1,   299,   208,   300,    -1,   294,    -1,   302,    -1,   209,
     210,    -1,   209,   303,   210,    -1,   193,   209,   303,   210,
      -1,   294,   194,   209,   303,   210,    -1,   300,    -1,     5,
      -1,   193,   302,    -1,   294,   194,   302,    -1,   294,     8,
     294,    -1,   294,     8,   294,     8,   294,    -1,    80,   209,
     294,   210,    -1,    80,     5,    -1,    83,     5,    -1,    86,
       5,    -1,    88,     5,    -1,   100,    80,     5,    -1,   100,
      83,     5,    -1,   100,    86,     5,    -1,   100,    88,     5,
      -1,   100,    80,   209,   303,   210,    -1,   100,    83,   209,
     303,   210,    -1,   100,    86,   209,   303,   210,    -1,   100,
      88,   209,   303,   210,    -1,    80,   147,    58,   209,   294,
     208,   294,   208,   294,   208,   294,   208,   294,   208,   294,
     210,    -1,    83,   147,    58,   209,   294,   208,   294,   208,
     294,   208,   294,   208,   294,   208,   294,   210,    -1,    86,
     147,    58,   209,   294,   208,   294,   208,   294,   208,   294,
     208,   294,   208,   294,   210,    -1,    88,   147,    58,   209,
     294,   208,   294,   208,   294,   208,   294,   208,   294,   208,
     294,   210,    -1,   258,    -1,   269,    -1,     4,   236,   237,
      -1,   311,   236,   237,    -1,    37,   204,   312,   205,    -1,
      37,   204,   302,   205,    -1,    37,   202,   302,   203,    -1,
      37,   204,   209,   303,   210,   205,    -1,    37,   202,   209,
     303,   210,   203,    -1,     4,   236,   209,   303,   210,   237,
      -1,   311,   236,   209,   303,   210,   237,    -1,   294,    -1,
     302,    -1,   303,   208,   294,    -1,   303,   208,   302,    -1,
     209,   294,   208,   294,   208,   294,   208,   294,   210,    -1,
     209,   294,   208,   294,   208,   294,   210,    -1,   312,    -1,
       4,   206,   144,   206,     4,    -1,   209,   306,   210,    -1,
       4,   204,   294,   205,   206,   145,    -1,   304,    -1,   306,
     208,   304,    -1,   308,    -1,   312,    -1,     4,   204,   294,
     205,    -1,   311,   204,   294,   205,    -1,     4,   202,   294,
     203,    -1,   311,   202,   294,   203,    -1,     4,   206,     4,
      -1,     4,   204,   294,   205,   206,     4,    -1,     5,    -1,
     177,   204,   312,   205,    -1,    61,    -1,   175,    -1,    66,
      -1,   164,   202,   307,   203,    -1,   163,   202,   307,   208,
     307,   203,    -1,   165,   236,   307,   237,    -1,   165,   236,
     307,   208,   307,   237,    -1,    42,   236,   310,   237,    -1,
      43,   202,   307,   203,    -1,    44,   202,   307,   203,    -1,
      45,   202,   307,   208,   307,   208,   307,   203,    -1,    40,
     236,   310,   237,    -1,    54,   236,   307,   237,    -1,    55,
     236,   307,   237,    -1,    56,   236,   307,   237,    -1,    53,
     236,   294,   208,   307,   208,   307,   237,    -1,    48,   236,
     307,   208,   294,   208,   294,   237,    -1,    48,   236,   307,
     208,   294,   237,    -1,    41,   236,   307,   237,    -1,    41,
     236,   307,   208,   303,   237,    -1,    62,   236,   307,   237,
      -1,    63,    -1,    47,   236,   307,   237,    -1,    46,   236,
     307,   237,    -1,    -1,    77,   236,   308,   309,   249,   237,
      -1,   307,    -1,   310,   208,   307,    -1,     4,   211,   209,
     294,   210,    -1,   311,   211,   209,   294,   210,    -1,     4,
      -1,   311,    -1,   178,   204,   307,   205,    -1
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
    5913,  5917,  5921,  5925,  5929,  5947,  5968,  5973,  5977,  5981,
    5993,  5997,  6009,  6026,  6036,  6040,  6055,  6060,  6067,  6071,
    6084,  6098,  6112,  6126,  6140,  6148,  6159,  6163,  6167,  6175,
    6181,  6187,  6195,  6203,  6210,  6218,  6233,  6247,  6261,  6273,
    6289,  6298,  6307,  6317,  6328,  6336,  6344,  6348,  6367,  6374,
    6380,  6387,  6395,  6394,  6407,  6412,  6418,  6427,  6440,  6443,
    6447
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
  "tModulo", "tHypot", "tList", "tPrintf", "tError", "tStr", "tSprintf",
  "tStrCat", "tStrPrefix", "tStrRelative", "tStrReplace", "tAbsolutePath",
  "tDirName", "tStrSub", "tStrLen", "tFind", "tStrFind", "tStrCmp",
  "tStrChoice", "tUpperCase", "tLowerCase", "tLowerCaseIn",
  "tTextAttributes", "tBoundingBox", "tDraw", "tSetChanged", "tToday",
  "tFixRelativePath", "tCurrentDirectory", "tSyncModel", "tNewModel",
  "tOnelabAction", "tOnelabRun", "tCpu", "tMemory", "tTotalMemory",
  "tCreateTopology", "tCreateTopologyNoHoles", "tDistanceFunction",
  "tDefineConstant", "tUndefineConstant", "tDefineNumber", "tDefineString",
  "tSetNumber", "tSetString", "tPoint", "tCircle", "tEllipse", "tLine",
  "tSphere", "tPolarSphere", "tSurface", "tSpline", "tVolume",
  "tCharacteristic", "tLength", "tParametric", "tElliptic", "tRefineMesh",
  "tAdaptMesh", "tRelocateMesh", "tPlane", "tRuled", "tTransfinite",
  "tComplex", "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
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
     435,   436,   437,    63,   438,   439,   440,   441,    60,    62,
     442,   443,    43,    45,    42,    47,    37,    33,   444,   445,
     446,    94,    40,    41,    91,    93,    46,    35,    44,   123,
     125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   212,   213,   213,   214,   214,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   216,   216,   217,   217,   217,   217,   217,
     217,   218,   218,   218,   218,   219,   219,   219,   219,   219,
     219,   220,   220,   221,   221,   223,   224,   222,   225,   225,
     227,   226,   228,   228,   230,   229,   231,   231,   233,   232,
     234,   234,   234,   234,   234,   235,   235,   236,   236,   237,
     237,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   239,   239,   240,   240,   240,   241,   240,   242,
     240,   243,   240,   240,   244,   240,   245,   245,   246,   246,
     246,   247,   247,   248,   248,   248,   249,   249,   250,   250,
     250,   250,   251,   251,   251,   252,   252,   252,   253,   253,
     253,   254,   254,   254,   255,   255,   256,   256,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     258,   258,   258,   258,   258,   258,   258,   258,   259,   259,
     260,   260,   260,   260,   260,   260,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   262,   262,   262,   262,   262,
     263,   263,   264,   265,   265,   265,   265,   265,   265,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   267,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   269,   269,   269,   270,   269,   271,   269,
     272,   269,   273,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   274,   269,   275,   269,   276,   269,   277,
     269,   278,   269,   279,   269,   280,   269,   281,   269,   282,
     269,   283,   283,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   285,
     285,   286,   286,   287,   287,   288,   288,   289,   289,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   291,   291,   291,   292,   292,
     292,   293,   293,   293,   293,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   296,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   297,   297,   297,   297,   297,
     298,   298,   298,   298,   299,   299,   300,   300,   300,   300,
     300,   300,   301,   301,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   303,   303,   303,   303,
     304,   304,   304,   304,   305,   305,   306,   306,   307,   307,
     307,   307,   307,   307,   307,   307,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   309,   308,   310,   310,   311,   311,   312,   312,
     312
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
       4,     4,     6,     6,     6,     6,     1,     1,     3,     3,
       9,     7,     1,     5,     3,     6,     1,     3,     1,     1,
       4,     4,     4,     4,     3,     6,     1,     4,     1,     1,
       1,     4,     6,     4,     6,     4,     4,     4,     8,     4,
       4,     4,     4,     8,     8,     6,     4,     6,     4,     1,
       4,     4,     0,     6,     1,     3,     5,     5,     1,     1,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   558,     0,     0,     0,
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
     559,     0,   417,   558,   526,   418,   420,   421,   419,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,   549,   530,   425,   426,   427,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   422,   423,   424,   529,
       0,     0,     0,     0,    67,    68,     0,     0,   210,     0,
       0,     0,   375,     0,   518,   559,   432,     0,     0,     0,
       0,   250,     0,   252,   253,   248,   249,     0,   254,   255,
     124,   136,    67,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   455,     0,     0,     0,     0,     0,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   558,
       0,   210,   559,     0,     0,   365,     0,     0,     0,     0,
       0,     0,     0,     0,   558,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   495,   496,   466,   472,     0,
     467,   559,   432,     0,     0,     0,     0,   558,     0,     0,
     512,     0,     0,     0,     0,   246,   247,     0,   558,     0,
       0,     0,   264,   265,     0,   210,     0,   210,   558,     0,
     559,     0,   371,     0,     0,    67,    68,     0,     0,    60,
      64,    63,    62,    61,    66,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   378,   377,   379,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   209,     0,   208,     0,
       0,   243,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    35,   239,     0,
       0,   440,   185,     0,   558,     0,   518,   559,   519,     0,
       0,   554,     0,   122,   122,     0,     0,     0,     0,   506,
     507,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   333,   333,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   210,   210,     0,   457,   456,     0,     0,     0,
       0,   210,   210,     0,     0,     0,     0,     0,     0,     0,
     282,     0,   210,     0,     0,     0,     0,     0,   335,     0,
       0,     0,     0,     0,     0,     0,   228,   366,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,     0,     0,
       0,     0,   479,     0,     0,   480,     0,   481,     0,   482,
       0,     0,     0,     0,     0,     0,   377,   474,     0,   468,
       0,     0,     0,   343,    67,    68,     0,   245,     0,     0,
       0,     0,     0,   210,     0,     0,     0,     0,     0,   268,
     267,     0,   233,     0,   234,     0,     0,     0,   210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,   445,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   428,   552,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      61,     0,   376,    60,    61,     0,     0,    60,     0,     0,
       0,     0,     0,   205,     0,     0,     0,     0,   211,     0,
       0,     0,   393,   392,   391,   390,   386,   387,   389,   388,
     381,   380,   382,   383,   384,   385,     0,     0,     0,   186,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   362,   363,
     364,     0,     0,     0,     0,   331,     0,     0,     0,   152,
     153,     0,   155,   156,     0,   158,   159,     0,   161,   162,
       0,   180,     0,   191,     0,   197,     0,     0,     0,     0,
     172,   210,     0,     0,     0,     0,     0,   459,   458,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   276,     0,
       0,     0,     0,     0,     0,     0,   346,     0,     0,   229,
       0,     0,   225,     0,     0,     0,   361,   360,     0,     0,
       0,     0,     0,   445,    69,    70,     0,   497,     0,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,   483,
       0,   484,     0,   485,     0,   486,     0,     0,   376,   469,
     476,     0,   382,   475,     0,     0,     0,   498,     0,     0,
       0,     0,     0,     0,     0,     0,   269,   270,     0,     0,
     235,   237,     0,   560,     0,     0,     0,    60,    61,     0,
       0,    60,    61,     0,     0,     0,     0,    91,    75,     0,
     434,   433,   447,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   416,   404,     0,   406,   407,   408,   409,   410,
     411,   412,     0,     0,     0,   539,     0,   546,   535,   536,
     537,     0,   551,   550,     0,   452,     0,     0,     0,     0,
     540,   541,   542,   454,   548,   141,   146,   114,     0,     0,
     531,     0,   533,     0,   430,   437,   438,   527,     0,     0,
       0,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,     0,     0,   439,     0,     0,
       0,     0,   556,     0,     0,    45,     0,     0,     0,    58,
       0,    36,    37,    38,    39,    40,   436,   435,     0,     0,
     524,    25,    23,     0,     0,     0,     0,    26,     0,     0,
     240,   555,    71,   125,    72,   137,     0,     0,     0,   508,
     509,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   329,
     334,   332,     0,   342,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   376,   376,   376,     0,     0,     0,     0,
       0,   236,   238,     0,     0,     0,   200,   202,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   311,     0,   273,     0,     0,     0,     0,
       0,     0,   336,   345,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   434,   433,     0,     0,   501,     0,
     500,   499,     0,   478,     0,     0,     0,     0,     0,     0,
       0,   470,     0,     0,   436,   435,     0,     0,     0,     0,
       0,     0,   230,     0,     0,     0,     0,     0,   232,     0,
       0,   372,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   557,     0,     0,   442,     0,   441,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,     0,
      89,     0,     0,    77,     0,     0,     0,     0,    81,   104,
     106,     0,     0,   516,     0,   112,     0,     0,     0,     0,
       0,   394,     0,     0,     0,     0,     0,    31,   444,   443,
     522,   520,    24,     0,     0,   523,   521,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   166,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   170,
       0,     0,     0,     0,     0,     0,     0,   340,     0,     0,
     154,     0,   157,     0,   160,     0,   163,     0,     0,     0,
       0,     0,     0,     0,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   317,     0,     0,   316,     0,   323,
       0,   325,     0,   319,     0,   321,     0,   283,   312,     0,
       0,     0,   223,     0,     0,     0,   347,     0,   227,   226,
     367,     0,     0,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   487,   488,   489,   490,   477,   471,
       0,     0,     0,     0,   513,     0,     0,     0,   259,     0,
       0,     0,     0,     0,     0,     0,    86,     0,    90,     0,
       0,    78,     0,    82,     0,   242,   446,   241,   405,   413,
     414,   415,   547,     0,     0,   545,   450,   451,   453,     0,
       0,   429,   142,     0,   553,   147,   449,   532,   534,   431,
       0,     0,     0,    87,     0,     0,     0,    60,     0,     0,
       0,     0,    79,     0,     0,     0,   514,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   464,     0,     0,    27,
      28,     0,    29,     0,     0,   126,   133,     0,     0,    73,
      74,   168,     0,     0,     0,     0,     0,     0,   171,     0,
       0,   188,   189,     0,     0,   173,   196,     0,     0,     0,
       0,   164,     0,   339,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,     0,     0,     0,     0,
     210,   210,     0,   293,     0,   295,     0,   297,     0,   318,
     466,     0,     0,   324,   326,   320,   322,     0,     0,   277,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   446,   504,   503,   502,     0,     0,     0,     0,   505,
     176,   177,     0,     0,     0,     0,   115,   119,     0,     0,
       0,   373,     0,     0,     0,    88,     0,     0,     0,    80,
       0,   448,     0,     0,     0,     0,     0,     0,    98,     0,
       0,    92,     0,     0,     0,     0,   109,     0,     0,   110,
       0,   517,   212,   213,   214,   215,     0,     0,    41,     0,
       0,     0,     0,     0,    43,   525,     0,     0,   127,   134,
       0,     0,     0,     0,   167,   174,   175,   179,     0,     0,
     190,     0,     0,   341,     0,   183,     0,     0,   330,   195,
     169,   182,   194,   199,   181,     0,   192,   198,     0,     0,
       0,     0,     0,     0,   463,     0,   462,     0,     0,     0,
     284,     0,     0,   285,     0,     0,   286,     0,     0,     0,
       0,     0,     0,     0,   222,     0,     0,   221,     0,     0,
       0,   216,     0,     0,   344,    34,     0,     0,     0,     0,
       0,     0,   511,     0,   261,   260,     0,     0,     0,     0,
       0,    99,     0,     0,    93,     0,     0,     0,   538,   544,
     543,     0,   143,   145,     0,   148,   149,   150,   100,   102,
      94,    96,   105,   107,     0,   113,     0,    83,    46,     0,
       0,     0,   465,     0,     0,     0,    30,     0,   141,   146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,     0,   337,   337,     0,   120,   121,   210,     0,   203,
     204,     0,     0,     0,     0,     0,     0,     0,   313,     0,
       0,   210,     0,     0,     0,     0,     0,   207,   206,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   117,     0,
       0,   101,   103,    95,    97,    84,     0,   506,   507,     0,
       0,   515,     0,    42,     0,     0,     0,    44,    59,     0,
       0,     0,   131,   129,   355,   357,   356,   358,   359,   187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   328,     0,     0,     0,   278,     0,     0,
     217,     0,     0,     0,     0,     0,     0,     0,   510,   262,
       0,     0,   374,     0,   144,     0,     0,   151,   111,     0,
       0,     0,     0,     0,   128,   135,   141,   141,     0,     0,
       0,     0,     0,   338,   348,     0,     0,   349,     0,   201,
       0,   299,     0,     0,   301,     0,     0,   303,     0,     0,
       0,   314,     0,   274,     0,   210,     0,     0,     0,     0,
       0,     0,     0,   178,   118,   258,     0,   138,     0,     0,
      50,     0,    56,     0,     0,     0,     0,     0,   165,   193,
       0,   352,     0,   353,   354,   460,   287,     0,     0,   294,
     288,     0,     0,   296,   289,     0,     0,   298,     0,     0,
       0,   280,     0,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   132,   130,     0,
       0,     0,     0,   305,     0,   307,     0,   309,   315,   327,
     279,   275,     0,     0,     0,     0,     0,     0,     0,     0,
     139,   140,    47,     0,    54,     0,     0,     0,     0,     0,
       0,   290,     0,     0,   291,     0,     0,   292,     0,     0,
     224,     0,   218,     0,     0,     0,     0,     0,    48,     0,
       0,   251,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   281,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,     0,   300,     0,   302,     0,   304,     0,
     219,     0,     0,     0,     0,    49,    51,     0,    52,     0,
       0,     0,     0,     0,     0,   491,   492,   493,   494,     0,
       0,    57,   350,   351,   306,   308,   310,    53,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    91,  1003,    92,    93,   716,  1537,  1543,
     991,  1202,  1732,  1947,   992,  1893,  1987,   993,  1949,   994,
     995,  1206,   356,   451,   190,   837,    94,   734,   463,  1668,
    1807,  1806,  1669,   464,  1726,  1170,  1362,  1171,  1365,   768,
     771,   774,   777,  1567,  1415,   698,   305,   427,   428,    97,
      98,    99,   100,   101,   102,   103,   104,   306,  1086,  1834,
    1912,   806,  1591,  1594,  1597,  1867,  1871,  1875,  1932,  1935,
    1938,  1082,  1083,  1246,  1042,   765,   815,  1756,   106,   107,
     108,   109,   307,   192,   945,   516,   263,  1395,   308,   309,
     310,   580,   319,   976,  1194,   461,   456,   946,   462,   340,
     312
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1644
static const yytype_int16 yypact[] =
{
    9242,    86,    55,  9366, -1644, -1644,  4136,    97,   -48,  -106,
     -59,    43,   143,   166,   184,   216,    65,   279,   291,   190,
     210,  -100,  -100,    79,   146,   244,    18,   272,   299,    30,
     328,   341,   361,   481,   502,   602,   412,   597,   542,   550,
     708,   549,   656,   722,   -22,   456,   583,   -84,   489,   -93,
     -93,   510,   -14,    37,   103,   640,   651,    20,    67,   652,
     644,   437,   736,   743,   746,  3929,   751,   590,   599,   605,
      25,    64, -1644,   611,   623, -1644, -1644,   810,   830,   633,
   -1644,  5813,   642,  6197,    -1,    16, -1644, -1644, -1644,  9101,
     661, -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644,
   -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644,    52, -1644,
     -49,   113, -1644,     5, -1644, -1644, -1644, -1644, -1644,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,   677,   678,   682,  -100,  -100,  -100,
    -100,   698,  -100,  -100,  -100,  -100,  -100,  -100,   702, -1644,
    -100, -1644, -1644, -1644, -1644, -1644,  -100,  -100,   853,   709,
     724,   728,  -100,  -100,   729,   730, -1644, -1644, -1644, -1644,
     684,  9101,  9101,  9101,  2339,  8580,    42,    14,   316,   639,
     738,   521, -1644,   745,   910,   294,  -167,   931,  9101,  6014,
    6014, -1644,  9101, -1644, -1644, -1644, -1644,  6014, -1644, -1644,
   -1644, -1644, -1644, -1644,  6398,    14,  9101,  8385,  9101,  9101,
     749,  9101,  8385,  9101,  9101,   753,  8385,  9101,  9101,  5916,
     781,   765, -1644,  8385,  3929,  3929,  3929,   800,   815,  3929,
    3929,  3929,   816,   821,   824,   829,   852,  6117,  6318,  6519,
     844,  7926,   934,  5916,    25,   869,   886,   -93,   -93,   -93,
    9101,  9101,  -118, -1644,  -104,   -93,   914,   922,   932,  7989,
     -68,   207,   857,   860,   905,  3929,  3929,  5916,   937,    13,
     754, -1644,   933,  1065,  1136, -1644,   945,   947,   948,  3929,
    3929,   939,   958,   961,   591, -1644,    94,     9,    21,    26,
      35,   726,  6720,  9101,  4634, -1644, -1644,  1686, -1644,  1163,
   -1644,   340,   123,  1164,  9101,  9101,  9101,    -5,  9101,   963,
   -1644,  1028,  9101,  9101,  9101, -1644, -1644,  9101,   965,  1174,
    1175,   977, -1644, -1644,  1181, -1644,  1183, -1644,   140,  9810,
     379,  6014, -1644,  5916,  5916,  8643,  8838,   981,   985,  6398,
   -1644, -1644, -1644, -1644, -1644, -1644,  5916,  1189,   992,  9101,
    9101,  1193,  9101,  9101,  9101,  9101,  9101,  9101,  9101,  9101,
    9101,  9101,  9101,  9101,  9101,  9101,  9101,  9101,  9101,  9101,
    9101,  9101,  9101,  9101,  6014,  6014,  6014,  6014,  6014,  6014,
    6014,  6014,  6014,  6014,  5916,  6014,  6014,  9101,  6014,  6014,
    6014,  6014,  6014,  9101,  6398,  9101,  6014,  6014,  6014,  6014,
    6014,    14,  6398,    14,   997,   997,   997,   124, 11461,   198,
    7953,   128,   993,  1194,  -100,   991, -1644,   994,  4453,  9101,
    8385, -1644,  9101,  9101,  9101,  9101,  9101,  9101,  9101,  9101,
    9101,  9101,  9101,  9101,  9101,  9101,  9101, -1644, -1644,  9101,
    9101, -1644, -1644,   896,   418,   144, -1644,   392, -1644,   230,
    9943, -1644,   304,   443,   494,   998,   999, 11482,  8385,  2922,
   -1644,   164, 11503, 11524,  9101, 11545,   321, 11566, 11587,  9101,
     389, 11608, 11629,  1201,  9101,  9101,   449,  1217,  1218,  1219,
    9101,  9101,  1221,  1223,  1223,  9101,  8190,  8190,  8190,  8190,
    9101,  1225,  9101,  1227,  9101,  1228,  8385,  8385,  9837,  1032,
    1230,  1030, -1644, -1644,   -74, -1644, -1644,  9969,  9995,   -93,
     -93,   316,   316,   -66,  9101,  9101,  9101,  7989,  7989,  9101,
    4453,   -63, -1644,  9101,  9101,  9101,  9101,  9101,  1235,  1231,
    1237,  9101,  1241,  9101,  9101,  1604, -1644, -1644,  8385,  8385,
    8385,  1243,  1245,  9101,  9101,  9101,  9101,  9101,  1249,   263,
    6921,  7122, -1644,  1200,  9101, -1644,  1202, -1644,  1203, -1644,
    1204,    34,    38,    39,    40,  8385,   997, -1644, 11650, -1644,
     519,  9101,  7323, -1644,  9101,  9101,   515, -1644, 11671, 11692,
   11713,  1115, 10021, -1644,  1054,  3614, 11734, 11755,  8605, -1644,
   -1644,  8385, -1644,  1650, -1644,  1901,  9101,  9101, -1644,  9101,
    9101,  1059,  1062,   538,   249, 11776,   268,  8800,  9101,  8385,
    1261,  1266, -1644,  9101, 11797, 11139,    91,  3463,  3463,  3463,
    3463,  3463,  3463,  3463,  3463,  3463,  3463,  3463, 10047,  3463,
    3463,  3463,  3463,  3463,  3463,  3463, 10073, 10099, 10125,   615,
     626,   615,  1071,  1072,  1068,   551,   551,  1069,   551,  1070,
    1073,  1076, 10151,   551,   551,   551,   347,   551,  5437, -1644,
    1026,  1077,  1078,  1084,   637,   638,  1086,  1087,  1074,  1251,
    1253,  5916,   137,  1255,  1256,  5916,    83,  6398,  9101,  1291,
    1294,    31,   551, -1644,   297,    33,    32,   300, -1644,  5409,
     560,  4440,   926,   500,   480,   480,   571,   571,   571,   571,
     175,   175,   997,   997,   997,   997,     3, 11818, 11162, -1644,
    9101,  9101,  1296,     4,  8385,  9101,  9101,  1297,  8385,  9101,
    1300,  6014,  1302, -1644,    14,  1306,  6014,  9101,  6398,  1308,
    8385,  8385,  1169,  1310,  1314, 11839,  1321,  1182,  1323,  1326,
   11860,  1187,  1328,  1331,  9101, 11881,  6456,  1130, -1644, -1644,
   -1644, 11902, 11923,  9101,  5916,  1336,  1335, 11944,  1139,  5437,
    1135,  1141,  5437,  1137,  1143,  5437,  1140,  1144,  5437,  1145,
   11965, -1644, 11986, -1644, 12007, -1644,   561,   569,  8385,  1146,
   -1644, -1644,  2623,  2686,   -93,  9101,  9101, -1644, -1644,  1147,
    1158,  7989, 10177, 10203, 10229,  9917,   503,   -93,  2788, 12028,
    6657, 12049, 12070, 12091,  9101,  1343, -1644,  9101, 12112, -1644,
   11185, 11208, -1644,   576,   614,   622, -1644, -1644, 11231, 11254,
   10255, 12133, 11277,   123, -1644, -1644,  8385, -1644,  8385,  2922,
    1148,  8385,  1149,   -77,  1160,  6858,  1161,  1166,  1167, -1644,
    8385, -1644,  8385, -1644,  8385, -1644,  8385,   646, -1644, -1644,
    4577,  8385,   997, -1644, 12154, 11300,  8385, -1644,  1348,  1370,
    1371,  1177,  9101,  2957,  9101,  9101, -1644, -1644,    49,   658,
   -1644, -1644,  3218, -1644,  1176,  5916,  1380,  1347,  1349,  5916,
     137,  1350,  1351,  5916,   137,  7059,   675, -1644, -1644, 11323,
     213,  1105, -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644,
   -1644, -1644, -1644, -1644,  9101, -1644, -1644, -1644, -1644, -1644,
   -1644, -1644,  9101,  9101,  9101, -1644,  8385, -1644, -1644, -1644,
   -1644,  6014, -1644, -1644,  9101, -1644,  5916,  6014,  6014,  6014,
   -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644,  9101,  6014,
   -1644,  6014, -1644,  9101, -1644, -1644, -1644, -1644,  -100,  -100,
    1386, -1644,  9101,  1387,  -100,  -100,  1388,   132,  9101,  1391,
    1393,  1265, -1644,  1396,  1205,    25,  1394, -1644,  8385,  8385,
    8385,  8385, -1644,   551,  9101, -1644,  1206,  1208,  1195, -1644,
    1405, -1644, -1644, -1644, -1644, -1644,   243,   371, 12175, 11346,
   -1644, -1644,  1224,  6014,   374, 12196, 11369, -1644,   427, 10281,
   -1644, -1644, -1644,    -2, -1644, -1644,  3463,   551,   -93,  2922,
   -1644,   801,  5916,  5916,  1407,  5916,   805,  5916,  5916,  1411,
    1324,  5916,  5916,  1361,  1413,  1418,  8385,  1419,  1420,  2296,
   -1644, -1644,  1422, -1644,  1425,   277,  9101,   277,  9101,   277,
    9101,   277,  9101,  1426,  1427,  1430,  1431,  1434,   686,  1438,
    3504, -1644, -1644,   -41, 10307, 10333, -1644, -1644,  7260,  -140,
     -93,   -93,   -93,  1439,  8906,  1220,  1440,  1242,    22,    45,
      51,    53,   -16, -1644,   -32, -1644,   503,  1455,  1457,  1460,
    1462,  1464,  5437, -1644,  1573,  1264,  1458,  1468,  1469,  1390,
    1473,  1478,  1480,  9101,   123,   115,   687,   691, -1644,   695,
   -1644, -1644,  9101, -1644,  9101,  9101,  9101,   699,   704,   707,
     710, -1644,  9101,   711,   123,   123,   714,  5916,  5916,  5916,
    1483, 10359, -1644,  4596,   172,  1484,  1486,  1283, -1644,  5916,
    1284, -1644,  -100,  -100,  1492,  9101,  1493,  -100,  -100,  1494,
    9101,  1495, -1644,   551,  1496, -1644,  1500, -1644,  1502,  3463,
    3463,  3463,  3463,   647,  1298,  9891,  1307,   551,   551,  1301,
     669,   673, 12217,  1311,   551,  3463,  1318,  6014, -1644,  1614,
   -1644,  1318,  6014, -1644,   150,  1305,  1506,  1636, -1644, -1644,
   -1644,    25,  9101, -1644,   717, -1644,   734,   735,   742,   755,
     277,  5437,  1313,  9101,  9101,  5916,  1309, -1644, -1644, -1644,
   -1644,  1316, -1644,  1511,    10, -1644, -1644,  1513,  9101,  5244,
    1317,  1330,  1522,  1523,    76,  1327,  1332,  1441,  1441,  5916,
    1533,  1333,  1334,  1552,  1553,  5916,  1356,  1554,  1560, -1644,
    1562,  5916,   756,  5916,  5916,  1564,  1563, -1644,  5916,  5916,
    5437,  5916,  5437,  5916,  5437,  5916,  5437,  5916,  5916,  5916,
    1363,  1364,  1567,   152, -1644,  9101,  9101,  9101,  1366,  1367,
    -145,  -113,  -107,  1373, -1644,  2111,  5916, -1644,  9101, -1644,
    1572, -1644,  1574, -1644,  1576, -1644,  1577, -1644, -1644,  7989,
     359,  5715, -1644,  1375,  1376,  7524, -1644,  8385, -1644, -1644,
   -1644,  1378,  9101, -1644, -1644, 11392,  1566,   551,  1389,  1385,
   10385, 10411, 10437, 10463, -1644, -1644, -1644, -1644,  5437, -1644,
     551,  1585,  1589,  1453, -1644,  9101,  9101,  9101, -1644,  1592,
     327,  6398,  1392,  1593,  1318,  6014, -1644,  2400, -1644,  1318,
    6014, -1644,  2419, -1644,   277, -1644,   393, -1644, -1644, -1644,
   -1644, -1644, -1644,  6014,  9101, -1644, -1644, -1644, -1644,  6014,
    1597, -1644, -1644,    15, -1644, -1644, -1644, -1644, -1644, -1644,
    1600,   615,   615, -1644,  1603,   615,   615,  6398,  9101,  1605,
    1606,    31, -1644,  1608, 11415,    25, -1644,  1609,  1612,  1615,
    1616,  5916,  9101, 10489, 10515,   759, -1644,  9101,  1620, -1644,
   -1644,  6014, -1644, 10541,  4842,  5437, -1644,  1618,  1619, -1644,
   -1644, -1644,  9101,  9101,   -93,  1624,  1625,  1626, -1644,  9101,
    9101, -1644, -1644,  1631,  9101, -1644, -1644,  1635,  1637,  1435,
    1639,  1499,  9101, -1644,  1641,  1642,  1643,  1644,  1646,  1647,
     964,  1648,  8385,  8385,  9101, -1644,  8190,  7461, 12238,  4779,
     316,   316,   -93,  1651,   -93,  1652,   -93,  1653,  9101, -1644,
     820,  1448, 12259, -1644, -1644, -1644, -1644,  7662,   -27, -1644,
    1655,  4410,  1658,  5916,   -93,  4410,  1659,   763,  9101,  2652,
    1660,   123, -1644, -1644, -1644,  9101,  9101,  9101,  9101, -1644,
   -1644, -1644,  5916,  4980,   851, 12280, -1644, -1644,  5313,  1461,
    5916, -1644,  1664,   615,   615, -1644,  1665,   615,   615, -1644,
    5916, -1644,  1470,  3463,   551,  5043,  5514,  6398, -1644,  1666,
    1668, -1644,  1669,  1670,  1671,  2770, -1644,  1672,  1674, -1644,
    1476, -1644, -1644, -1644, -1644, -1644,  1677,   476,  5437,  9101,
    9101,  5916,  1487,   771,  5437, -1644,  1692,  9101, -1644, -1644,
    1490,  1497,  7883,  8085,   292, -1644, -1644, -1644,  8113,  8141,
   -1644,  8322,  1702, -1644,  5916, -1644,  1627,  1704,  5437, -1644,
   -1644, -1644, -1644, -1644, -1644,  1503, -1644, -1644,   772,   776,
    9864,  2880,  1710,  1509, -1644,  9101, -1644,  1498,  1510,   209,
   -1644,  1512,   226, -1644,  1514,   228, -1644,  1515, 11438,  1713,
    5916,  1715,  1516,  9101, -1644,  7725,   247, -1644,   779,   252,
     271, -1644,  1720,  8537, -1644, -1644, 10567, 10593, 10619, 10645,
    1586,  9101, -1644,  9101, -1644, -1644,  8385,  3287,  1721,  6398,
    1519, -1644,  1734,  1736, -1644,  1742,  1747,  1748, -1644, -1644,
   -1644,  4634, -1644, -1644,  6014,  5437, -1644, -1644, -1644, -1644,
   -1644, -1644, -1644, -1644,    25, -1644,  1628, -1644, -1644,  9101,
   10671, 10697, -1644,  5916,  9101,  1764, -1644, 10723, -1644, -1644,
    5916,  5916,  1766,  1769,  1770,  1771,  1772,  1773,   783,  1571,
   -1644,  5916,   497,   505,  8385, -1644, -1644,   316,  5272, -1644,
   -1644,  7989,   503,  7989,   503,  7989,   503,  1775, -1644,   784,
    5916, -1644,  8863,   -93,  1776,  8385,   -93, -1644, -1644,  9101,
    9101,  9101,  9101,  9101,  8995,  9023,   787, -1644, -1644,  1580,
    1778, -1644, -1644, -1644, -1644, -1644,   788,  4034,  1779,   791,
    1781, -1644,  1579,  5437,  9101,  9101,   840,  5437, -1644,  9101,
     841,   850, -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644,
    1583,  9101,   858,  1602,   -93,  5916,  1788,  1607,   -93,  1789,
     859,  1575,  9101, -1644,  9362,   278,   629,  9390,   283,   659,
    9418,   285,  1196, -1644,  5916,  1806,  1714,  4271,  1630,   302,
   -1644,   862,   346, 10749, 10775, 10801, 10827,  3491, -1644, -1644,
    1807,  1812, -1644,  9101, -1644,  6398,    14, -1644, -1644,  9101,
   12301, 10853,    44, 10879, -1644, -1644, -1644, -1644,  9101,  9446,
    1828,   -93,    78, -1644, -1644,   -93,    87, -1644,  1834, -1644,
    9474,  1835,  9101,  1836,  1837,  9101,  1838,  1840,  9101,  1842,
    1649, -1644,  9101, -1644,   503, -1644,  8385,  1843,  7725,  9101,
    9101,  9101,  9101, -1644, -1644, -1644,  4060, -1644,  1656,   866,
   -1644,  9101, -1644,  5916,  9101,   890,   891, 10905, -1644, -1644,
     348, -1644,   360, -1644, -1644, -1644, -1644,  1645,  9502, -1644,
   -1644,  1657,  9530, -1644, -1644,  1675,  9558, -1644,  1846,  3516,
    1293,  5560,   894, -1644,   370,   895, 10931, 10957, 10983, 11009,
    6398,  1662,  1847,  1676, 12322,   898,  9586, -1644, -1644,  9101,
     -93,   -93,   503,  1861,   503,  1862,   503,  1880, -1644, -1644,
   -1644, -1644,   503,  1887,  8385,  1888,  9101,  9101,  9101,  9101,
   -1644, -1644, -1644,  6014, -1644,  1687,  1889,  9614,   381,   383,
    1402, -1644,  1688,  1505, -1644,  1690,  1733, -1644,  1691,  2065,
   -1644,   920, -1644, 11035, 11061, 11087, 11113,   924, -1644,  1693,
    5916, -1644,  1895,  9101,  9101,  1897,   503,  1898,   503,  1900,
     503, -1644,  1904,  9101,  9101,  9101,  9101,  6014,  1906,  6014,
     927, -1644,  9642,  9670, -1644,  2289, -1644,  2343, -1644,  2685,
   -1644,  9698,  9726,  9754,  9782, -1644, -1644,   930, -1644,  1909,
    1910,  1911,  1912,  1913,  1915, -1644, -1644, -1644, -1644,  6014,
    1916, -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1644, -1644, -1644, -1644,   693, -1644, -1644, -1644, -1644,   133,
   -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644,
   -1644, -1644,  -271,    59,  3609,  3225, -1644,  1463, -1644, -1644,
   -1644, -1644, -1644, -1644, -1644, -1643, -1644,   267, -1644, -1644,
   -1644, -1644, -1644, -1644,   713,  1934,    27,  -510,  -254, -1644,
   -1644, -1644, -1644, -1644, -1644, -1644, -1644,  1935, -1644, -1644,
   -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644,
   -1644, -1085, -1069, -1644, -1644,  1445, -1644,   259, -1644, -1644,
   -1644, -1644,  1707, -1644, -1644,  1044, -1644, -1453,  2322,   325,
    2430,  2401,  -252,   563, -1644,   126,    88, -1644,  -378,    -3,
     254
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -526
static const yytype_int16 yytable[] =
{
     110,  1290,   511,   195,   334,  1219,   649,   985,   651,   358,
    1001,   799,   800,  1288,   562,   530,  1400,   542,   328,  1516,
    1608,   336,   220,   666,   279,  1740,   565,   545,  1279,   317,
      96,   567,   354,   355,   225,   974,   225,   220,   198,   849,
     569,   271,  -519,   851,   853,   855,   421,   519,   520,   201,
    1852,  1281,   519,   520,   282,     5,  1135,  1283,   342,  1285,
     254,   250,   311,  1452,   251,  1453,   266,   282,   321,   267,
    1269,   284,   268,   285,   519,   520,   255,   256,   282,   519,
     520,   603,  1411,   605,  1861,   519,   520,  1073,   519,   520,
     961,   521,     4,  1863,   194,  1454,   199,  1455,  1074,   258,
     259,  1456,   212,  1457,   213,   522,  1075,  1076,  1077,   260,
     197,  1678,  1078,  1079,  1080,  1081,   261,   272,   519,   520,
     349,   273,   354,   355,   519,   520,   519,   520,  1111,   519,
     520,   679,   193,   274,   794,   687,  1184,   986,   987,   988,
     989,   532,   801,   200,   961,   807,   681,   286,   685,   203,
     688,   519,   520,   345,  1280,   346,   563,  1377,  1445,  1446,
     519,   520,   347,  1855,  1856,   519,   520,  1265,   566,   329,
     357,   333,   204,   568,  1517,   280,  1289,  1282,   258,   259,
    1327,  1603,   570,  1284,   282,  1286,   422,   423,   260,   275,
     205,   276,    90,  1002,  1287,   269,   457,   457,    90,  1002,
    1220,   591,  1221,    90,   457,   683,   189,   359,   335,   360,
    1736,   361,   282,   990,   311,   426,   189,   543,   564,   311,
     221,  1288,   206,   311,   189,   337,   311,   222,  1752,   281,
     311,   311,   311,   311,   318,   221,   311,   311,   311,   226,
     975,   980,   979,   850,   311,   311,   311,   852,   854,   856,
     311,   282,   202,  1853,   343,  1136,   887,   111,   792,   793,
     196,   344,   350,   351,   352,   353,   322,   207,   519,   520,
     519,   520,   311,   311,   311,   891,  1185,  1186,   808,   519,
     520,   216,   354,   355,   961,   208,   311,   311,   217,   967,
     354,   355,   350,   351,   352,   353,   560,   209,   561,   311,
    -524,   311,   465,   350,   351,   352,   680,   350,   351,   352,
     353,   283,   354,   355,   354,   355,   350,   351,   352,   353,
     425,  1306,   354,   355,   320,   455,   459,   354,   355,   350,
     351,   352,   353,  1497,  1498,   330,   354,   355,   457,   873,
     311,   311,   606,   889,   607,   893,   558,   723,   218,   354,
     355,   189,   724,   311,   882,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   443,
     444,   445,   741,   446,   742,  1328,   446,   350,   351,   352,
     684,   457,   457,   457,   457,   457,   457,   457,   457,   457,
     457,   311,   457,   457,   210,   457,   457,   457,   457,   457,
    1895,   519,   520,   457,   457,   457,   457,   457,   282,   533,
     282,   962,   354,   355,   211,   968,   534,  1691,   519,   520,
     519,   520,  -522,    48,    49,    50,    51,   311,   350,   351,
     352,   888,    56,   727,  1693,    59,  1695,   620,   728,   519,
     520,   424,   354,   355,   519,   520,   219,   350,   351,   352,
     892,   229,  -523,   458,   458,  1703,   350,   351,   352,   353,
    1705,   458,  1073,   519,   520,   311,   834,   611,   835,   466,
     519,   520,   836,  1074,   223,   519,   520,   519,   520,  1706,
     689,  1075,  1076,  1077,   519,   520,  1822,  1078,  1079,  1080,
    1081,  1825,   669,  1828,   519,   520,   449,  1970,   450,   216,
     677,   224,   228,   311,   311,   347,   978,   730,   320,   981,
    1836,   650,   731,   652,   653,   654,   655,   656,   657,   658,
     289,   660,   661,   290,   663,   664,   665,   431,   667,   741,
     227,   747,   671,   672,   673,   674,   675,  1060,   519,   520,
     519,   520,   584,   228,   585,   311,   311,   311,   426,   426,
     943,   347,   519,   520,  1838,   731,  1900,   311,   311,   487,
     488,   489,   519,   520,   492,   493,   494,   230,  1901,  1469,
     354,   355,   311,   519,   520,   519,   520,  1214,  1914,   311,
    -521,   609,   741,   610,   770,   773,   776,   779,   231,  1953,
     347,  1954,   354,   355,   725,   458,   726,   741,   311,   751,
     538,   539,  -525,   347,  1753,  1754,  1073,  1766,   232,  1769,
    1755,  1772,  1757,  1758,   551,   552,   311,  1074,  1755,  1145,
     720,   233,   721,  1150,   722,  1075,  1076,  1077,   237,   189,
    1217,  1078,  1079,  1080,  1081,   741,   238,   242,   458,   458,
     458,   458,   458,   458,   458,   458,   458,   458,   732,   458,
     458,   733,   458,   458,   458,   458,   458,   741,   252,   757,
     458,   458,   458,   458,   458,   676,   253,   678,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   234,   311,  1658,
     235,   446,   311,   236,  1659,   902,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,  1288,   257,   735,
    1288,   446,   733,  1288,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   834,   265,
     835,   311,   446,  1193,   866,   311,   277,   741,   457,   859,
     288,   282,  1073,   457,   278,   287,   243,   311,   311,   244,
     291,   963,   245,  1074,   246,   969,   885,   292,   886,  1880,
     293,  1075,  1076,  1077,   834,   313,   835,  1078,  1079,  1080,
    1081,   311,  1073,   441,   442,   443,   444,   445,   741,   741,
     983,  1056,   446,  1074,  1249,   970,  1251,   741,  1253,  1057,
    1255,  1075,  1076,  1077,   741,   311,  1098,  1078,  1079,  1080,
    1081,   239,   314,   556,   240,   557,   241,   558,  1371,  1372,
     188,   315,   189,  1375,  1376,   247,   571,   316,   248,   572,
     249,  1288,   573,   323,   574,   843,   325,  1930,   834,  1933,
     835,  1936,   741,   731,  1099,   324,  1017,  1939,   581,   834,
     741,   835,  1100,   311,   926,   311,   326,   327,   311,  1823,
     834,   834,   835,   835,   331,   951,   953,   311,   429,   311,
     834,   311,   835,   311,   741,   741,  1121,  1011,   311,  1623,
     405,  1288,  1015,   311,  1288,   341,   741,  1288,  1137,  1826,
    1288,  1975,   834,  1977,   835,  1979,   834,  1360,   835,   387,
     388,  1363,   311,   741,   389,  1153,   311,  1225,   413,  1226,
     311,  1231,   902,  1232,   741,   741,  1262,  1307,   457,   741,
     394,  1308,   719,   741,   401,  1309,  1288,   741,  1288,  1314,
    1288,   406,   741,  1378,  1315,   741,   448,  1316,   741,   741,
    1317,  1319,   741,   311,  1320,  1385,   407,  1386,   457,  1391,
     408,   411,   412,   311,   457,   457,   457,   452,   509,  1383,
    1587,  1588,   741,   741,  1387,  1388,   457,   430,   457,  1146,
     741,   474,  1389,  1151,   447,   479,  1503,  1504,   544,  1155,
    1157,  1507,  1508,   741,   741,  1390,  1429,  1541,  1575,  1542,
    1576,   741,   282,  1612,   485,   311,   311,   311,   311,  1664,
     741,  1665,  1682,   484,   741,   458,  1683,  1541,  1013,  1704,
     458,  1541,  1774,  1750,  1775,   741,  1793,  1790,  1794,   731,
     457,  1797,   490,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   582,   444,   445,   491,   495,   311,
     311,   446,   311,   496,   311,   311,   497,  1158,   311,   311,
    1599,   498,   947,   311,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,  1541,  1360,
    1802,  1804,   446,   506,   499,  1208,  1209,  1164,  1363,   535,
    1805,  1624,   536,  1167,  1168,  1169,  1541,   741,  1810,  1818,
     741,   546,  1837,  1510,  1664,  1173,  1892,  1174,   512,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   262,   264,   513,   270,   446,  1360,  1360,
    1897,  1898,   741,   741,  1913,  1915,  1541,   537,  1925,   454,
     114,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   524,   311,   311,   311,   446,   741,  1213,
    1962,   525,  1967,  1531,  1968,  1541,   311,  1989,  1999,   541,
    2000,   526,   547,   553,   347,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   548,   458,   549,   550,   154,   155,
     156,   157,   554,  1155,  1157,   555,   159,   160,   161,   583,
     587,   162,   593,   457,   457,   594,   189,  1761,   457,   457,
     599,   600,   167,  1208,  1209,   458,   601,   602,   282,   604,
     618,   458,   458,   458,   619,   622,   623,   626,   446,   690,
     188,   691,   311,   458,   693,   458,   737,   738,   754,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   758,   759,   760,   311,   446,   763,   320,
     764,   781,   311,   783,   785,   789,   790,   816,   311,   791,
     311,   311,   814,  1379,   817,   311,   311,   819,   311,   826,
     311,   827,   311,   833,   311,   311,   311,   458,   844,   871,
     846,   847,   848,   874,   883,   884,  1729,   897,   170,   171,
     172,  1190,   898,   311,   929,   930,   931,   934,   936,   957,
     179,   937,   180,    90,   938,   948,   949,   950,   311,   955,
     956,   958,   311,   959,   311,   964,   965,   972,   973,  1073,
    1000,   514,   515,  1007,   354,   355,  1010,  1406,  1012,   523,
    1074,  1156,  1014,   531,  -520,  1018,  1021,  1022,  1075,  1076,
    1077,  1023,   454,   114,  1078,  1079,  1080,  1081,  1025,  1026,
    1027,   457,   457,  1028,  1030,  1031,   457,   457,  1032,  1036,
    1041,  1043,  1045,  1046,  1047,  1048,  1049,  1051,  1050,  1093,
     457,  1108,  1059,  1052,  1110,  1127,   457,  1066,   141,   142,
     143,   144,   145,   146,   147,   148,   149,  1239,  1067,  1112,
    1114,   154,   155,   156,   157,  1115,  1116,  1128,  1129,   159,
     160,   161,   282,  1130,   162,  1139,  1141,  1142,   311,  1143,
    1147,  1148,  1178,  1180,  1183,   167,  1073,  1188,   457,  1189,
    1195,   311,  1730,  1191,  1205,  1511,  1829,  1074,  1203,  1192,
    1204,  1207,  1236,  1212,  1229,  1075,  1076,  1077,  1235,  1499,
    1240,  1078,  1079,  1080,  1081,  1241,  1243,  1244,  1247,  1276,
     458,   458,  1248,  1257,  1258,   458,   458,  1259,  1260,   311,
     311,  1261,  1263,  1273,  1278,   320,  1277,  1777,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,  1291,  1292,  1298,  1524,   446,  1293,   311,  1294,
     311,  1295,   311,  1297,  1299,  1300,  1301,   426,   426,  1512,
    1302,   170,   171,   172,  1303,  1514,  1304,  1324,  1329,   311,
    1330,  1331,  1549,   179,  1333,   180,    90,   311,  1336,  1338,
    1341,  1343,  1345,  1910,  1346,  1073,  1353,   311,  1347,  1359,
    1356,  1380,   311,  1381,  1367,  1392,  1074,  1399,  1397,  1402,
    1407,   834,  1398,   835,  1075,  1076,  1077,  1546,  1409,  1410,
    1078,  1079,  1080,  1081,  1582,  1408,  1412,  1414,   311,  1418,
    1511,  1413,  1419,  1420,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,  1421,  1422,
    1425,   311,   446,   797,   798,  1424,  1426,  1427,  1432,  1433,
    1481,   515,  1442,  1443,  1444,  1450,  1451,  1458,  1463,  1296,
    1464,  1881,  1465,  1466,  1473,  1474,  1628,  1478,   458,   458,
    1484,  1490,  1483,   458,   458,  1491,  1492,   311,  1496,  1501,
    1500,  1515,   311,  1643,  1646,  1647,  1518,   458,  1073,  1521,
    1527,  1526,  1955,   458,  1529,  1532,     7,     8,  1533,  1074,
    1373,  1534,  1535,   311,  1545,  1550,  1551,  1075,  1076,  1077,
    1555,  1556,  1557,  1078,  1079,  1080,  1081,  1560,   311,   320,
    1562,   457,  1382,  1563,  1564,  1565,  1566,  1569,  1570,  1571,
    1572,   282,  1573,  1574,  1577,   458,  1600,  1590,  1593,  1596,
     311,  1604,     7,     8,  1607,  1611,  1615,   311,   311,  1629,
    1631,  1634,  1648,  1638,  1649,  1650,  1651,  1652,   311,  1654,
    1655,   311,  1656,  1657,   694,    24,    25,   695,    27,    28,
     696,    30,   697,    32,   581,    33,  1663,   311,  1666,  1670,
      38,    39,   311,    41,    42,    43,  1671,  1677,  1689,    46,
    1680,  1679,  1681,   191,   426,  1957,  1686,  1719,  1687,  1698,
    1690,  1692,  1700,  1694,  1696,  1701,  1707,  1718,  1713,  1720,
     694,    24,    25,   695,    27,    28,   696,    30,   697,    32,
    1721,    33,  1722,    67,    68,    69,    38,    39,  1723,    41,
      42,    43,   311,  1724,  1725,    46,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
    1738,   311,  1744,  1731,   446,  1745,  1746,  1747,  1748,  1749,
    1751,  1773,  1780,  1791,  1792,  1819,  1796,  1798,  1799,    67,
      68,    69,  1808,   282,  1814,  1817,   339,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,  1811,  1831,  1844,   822,   446,  1815,  1832,  1845,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   311,  1859,   311,  1073,   446,  1063,  1835,
    1864,  1866,  1869,  1870,  1873,  1069,  1874,  1074,  1877,  1883,
     311,  1084,  1908,  1922,  1902,  1075,  1076,  1077,  1891,  1878,
     880,  1078,  1079,  1080,  1081,  1921,  1904,  1931,  1934,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     582,   444,   445,  1847,  1906,  1923,  1937,   446,   414,   415,
     416,   418,   420,  1940,  1942,  1951,  1950,  1956,   458,  1958,
    1960,  1971,  1969,  1974,  1976,   453,  1978,  1401,   320,   460,
    1980,   311,  1986,     7,     8,  2001,  2002,  2003,  2004,  2005,
     457,  2006,  2008,   467,   469,   472,   473,   736,   475,   469,
     477,   478,  1849,   469,   481,   482,  1741,    95,   105,   766,
     469,  1416,  1759,  1959,  1528,     0,     0,   311,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   508,     0,
       0,     0,     0,     0,   457,     0,   457,   517,   518,     0,
       0,     0,     0,     0,     0,     0,   518,     0,  1920,     0,
       0,   694,    24,    25,   695,    27,    28,   696,    30,   697,
      32,     0,    33,     0,     0,     0,   457,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,     0,   576,
     578,   469,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   588,   589,   590,     0,   592,     0,     0,     0,   595,
     596,   597,     0,     0,   598,     0,     0,     0,     0,     0,
      67,    68,    69,     0,     0,     0,     0,     0,     0,  1948,
    1848,     0,   615,   617,     0,     0,     0,     0,     0,     0,
       0,     0,  1224,     0,     0,     0,   624,   625,     0,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,     0,     0,  1985,     0,  1988,     0,     0,     0,     0,
       0,     0,     0,     0,   662,     0,     0,     0,     0,     0,
     668,   881,   670,     0,  1270,  1271,  1272,  1459,     0,     0,
       0,     0,     0,     0,     0,  2007,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   699,   469,     0,   701,
     702,   703,   704,   705,   706,   707,   708,   709,   710,   711,
     712,   713,   714,   715,     0,     0,   717,   718,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1073,     0,
       0,     0,     0,     0,     0,   576,     0,   458,     0,  1074,
       0,   745,     0,     0,     0,     0,   750,  1075,  1076,  1077,
       0,   755,   756,  1078,  1079,  1080,  1081,   761,   762,     0,
       0,     0,   767,   769,   772,   775,   778,   780,     0,   782,
       0,   784,     0,   469,   469,     0,     0,     0,     0,     0,
       0,   458,     0,   458,     0,     0,     0,     0,     0,     0,
       0,   802,   803,   804,   414,   415,   805,     0,     0,     0,
     809,   810,   811,   812,   813,     0,     0,     0,   818,     0,
     820,   821,     0,   458,     0,   469,   469,   469,     0,     0,
     828,   829,   830,   831,   832,     0,     0,   839,   839,     0,
       0,   845,     0,     0,     0,  1961,     0,     0,     0,     0,
       0,     0,   469,     0,     0,     0,     0,     0,   860,   862,
       0,   864,   865,     0,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   469,     0,
       0,     0,   446,   831,   832,     0,   864,   865,     0,     0,
       0,     0,     0,     0,     0,   895,   469,     0,     0,     0,
     899,     0,     0,  1468,     0,     0,     0,     0,     0,     0,
       0,     0,   112,   338,     0,     0,     0,     0,   115,   116,
     117,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   151,
     152,   153,  1073,     0,     0,   971,   158,     0,     0,  1245,
       0,     0,     0,  1074,     0,     0,  1505,   163,   164,   165,
       0,  1075,  1076,  1077,     0,   166,     0,  1078,  1079,  1080,
    1081,     0,     0,     0,     0,  1509,     0,   998,   999,     0,
       0,   469,  1005,  1006,     0,   469,  1009,     0,     0,     0,
       0,     0,     0,     0,  1016,     0,  1073,   862,  1019,     0,
       0,     0,     0,     0,     0,     0,     0,  1074,  1554,     0,
       0,  1033,     0,     0,     0,  1075,  1076,  1077,     0,     0,
    1039,  1078,  1079,  1080,  1081,     0,     0,     0,     0,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,     0,     0,   469,  1589,   446,  1592,  1992,
    1595,   169,  1064,  1065,     0,   173,     0,     0,  1068,   174,
     175,   176,   177,   178,     0,  1606,     0,    90,  1609,  1610,
       0,  1092,     0,     0,  1094,     0,     0,     0,     0,     0,
       0,   181,   182,     0,     0,     0,   183,     0,     0,     0,
       0,   303,   417,   469,     0,   469,   187,     0,   469,     0,
       0,   483,     0,  1993,     0,     0,     0,   469,     0,   469,
       0,   469,     0,   469,     0,     0,     0,     0,   469,   501,
     503,   505,     0,   469,     0,   510,     0,     0,     0,  1131,
       0,  1133,  1134,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,   540,
       0,   446,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,   471,     0,
     446,  1159,     0,   476,     0,     0,     0,   480,     0,  1160,
    1161,  1162,     0,   469,   486,     7,     8,     0,     0,     0,
       0,  1165,     0,     0,     0,     0,     0,   470,     0,     0,
       0,     0,   470,     0,     0,  1172,   470,     0,  1614,     0,
    1175,     0,     0,   470,     0,   612,   613,     0,     0,  1179,
       0,     0,     0,     0,     0,  1187,     0,     0,   621,     0,
       0,     0,     0,     0,     0,   469,   469,   469,   469,     0,
       0,  1201,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,   694,    24,    25,   695,    27,    28,   696,
      30,   697,    32,     0,    33,     0,   659,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,     0,
       0,     0,   577,     0,   470,  1765,     0,  1768,     0,  1771,
       0,     0,     0,   469,     0,     0,     0,  1779,     0,     0,
    1782,     0,     0,  1250,     0,  1252,     0,  1254,     0,  1256,
       0,     0,    67,    68,    69,     0,   694,    24,    25,   695,
      27,    28,   696,    30,   697,    32,  1653,    33,     0,     0,
       0,  1275,    38,    39,     0,    41,    42,    43,  1073,     0,
       0,    46,     0,     0,     0,     0,     0,     0,  1812,  1074,
       7,     8,  1816,     0,     0,     0,     0,  1075,  1076,  1077,
    1305,     0,     0,  1078,  1079,  1080,  1081,     0,     0,  1310,
       0,  1311,  1312,  1313,     0,    67,    68,    69,     0,  1318,
       0,   700,     0,  1061,     0,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,  1337,   446,     0,  1860,     0,  1342,     0,  1862,
     470,     0,     0,     0,     0,     0,     0,     0,   694,    24,
      25,   695,    27,    28,   696,    30,   697,    32,     0,    33,
       0,     0,  1884,     0,    38,    39,  1685,    41,    42,    43,
       0,     0,     0,    46,     0,  1994,  1062,     0,   577,  1384,
       0,     0,     0,     0,     0,     0,     0,   786,   787,     0,
    1393,  1394,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1403,  1405,    67,    68,    69,
     581,     0,     0,     0,     0,     0,   470,   470,     0,     0,
       0,     0,     0,     0,  1928,  1929,     0,     0,     0,   823,
     824,   825,     0,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     7,
       8,   446,  1447,  1448,  1449,     0,   857,     0,   470,   470,
     470,     0,     0,  1460,     0,  1462,     0,     0,     0,     0,
     840,   842,     0,     0,     0,     0,  1467,     0,  1085,     0,
       0,     0,   879,   960,   469,   470,     0,   966,     0,  1479,
       0,     0,   863,     0,     0,     0,     0,     0,     0,     0,
     896,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   470,  1493,  1494,  1495,     0,     0,   694,    24,    25,
     695,    27,    28,   696,    30,   697,    32,     0,    33,   470,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,  1513,    46,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     0,
       0,   446,     0,     0,     0,  1525,  1040,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,  1538,
       0,     0,     0,     0,  1544,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   740,   444,   445,  1552,
    1553,     0,     0,   446,     0,  1004,  1558,  1559,     0,  1008,
       0,  1561,     0,     0,     0,     0,     0,     0,     0,  1568,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   469,
     469,  1580,     0,  1581,   470,     0,     0,     0,   470,     0,
       0,     0,     0,     0,     0,  1598,     0,  1132,     0,     0,
     863,  1020,     0,     0,     0,     0,     0,     0,   469,     0,
       0,     0,   469,     0,     0,  1613,     0,     0,     0,  1058,
       0,     0,  1616,  1617,  1618,  1619,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1627,     0,  1140,     0,     0,
       0,  1144,     0,     0,     0,  1149,     0,     0,   470,     0,
       0,     0,     0,  1645,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,  1106,     0,  1107,
       0,     0,  1109,     0,     0,     0,  1660,  1661,     0,     0,
       0,  1117,     0,  1118,  1667,  1119,     0,  1120,  1166,     0,
       0,     0,  1123,     0,     0,     0,   470,  1126,   470,     0,
       0,   470,     0,     0,     0,     0,     0,     0,     0,     0,
     470,     0,   470,     0,   470,     0,   470,     0,     0,     0,
       0,   470,  1688,  1717,     0,     0,   470,     0,   694,    24,
      25,   695,    27,    28,   696,    30,   697,    32,     0,    33,
    1702,     0,   576,     0,    38,    39,     0,    41,    42,    43,
       0,     0,     0,    46,     0,     0,     0,  1163,  1714,     0,
    1715,     0,     0,   469,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1227,  1228,     0,  1230,  1727,  1233,
    1234,     0,     0,  1237,  1238,     0,   470,    67,    68,    69,
       0,     0,     0,     0,     0,     0,  1733,     0,     0,     0,
       0,  1737,     0,     0,     0,     0,     0,     0,     0,  1196,
    1197,  1198,  1199,     0,     0,     0,     0,     0,     0,     0,
       0,   469,     0,     0,     0,     0,     0,     0,  1764,     0,
    1767,     0,  1770,     0,     0,     0,     0,     0,   470,   470,
     470,   470,   469,     0,     0,     0,  1783,  1784,  1785,  1786,
    1787,     0,     0,     0,     0,     0,     0,     0,  1138,     0,
       0,     0,     0,     0,     0,     0,     0,  1242,     0,     0,
       0,  1800,  1801,     0,     0,     0,  1803,     0,     0,  1321,
    1322,  1323,     0,     0,     0,     0,     0,     0,  1809,     0,
       0,  1332,     0,     0,     0,     0,   470,     0,     0,  1820,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
       0,     0,     0,     0,     0,     0,     0,  1843,     0,     0,
    1846,     0,     0,     0,     0,     0,  1544,     0,     0,     0,
       0,     0,     0,     0,     0,  1857,     7,     8,     0,     0,
       0,     0,  1909,     0,     0,     0,     0,  1396,     0,  1868,
       0,     0,  1872,     0,     0,  1876,     0,     0,     0,  1879,
       0,     0,     0,   469,     0,   469,  1886,  1887,  1888,  1889,
       0,  1417,     0,     0,     0,     0,     0,  1423,  1894,     0,
       0,  1896,     0,  1428,     0,  1430,  1431,     0,     0,     0,
    1434,  1435,     0,  1436,     0,  1437,     0,  1438,     0,  1439,
    1440,  1441,     0,     0,   694,    24,    25,   695,    27,    28,
     696,    30,   697,    32,     0,    33,     0,     0,  1461,     0,
      38,    39,     0,    41,    42,    43,  1927,     0,     0,    46,
       0,     0,     0,  1472,     0,     0,     0,  1476,     0,     0,
       0,   469,   875,  1943,  1944,  1945,  1946,     0,     0,     0,
     214,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    68,    69,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
    1972,  1973,     0,     0,   446,     0,   834,     0,   835,     0,
    1981,  1982,  1983,  1984,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,  1477,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,  1536,  1264,     0,     0,   446,     0,   348,
       0,     0,     0,     0,     0,     0,  1548,   470,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,     0,     0,     0,   390,   391,   392,   393,
       0,   395,   396,   397,   398,   399,   400,     0,     0,   402,
       0,     0,     0,     0,     0,   403,   404,     0,     0,     0,
       0,   409,   410,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1396,     0,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   867,     0,     0,  1620,   446,     0,     0,     0,     0,
       0,     0,  1630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1637,     0,     0,     0,     0,  1642,     0,     0,
       0,     0,     0,  1578,  1579,     0,     0,     0,     0,     0,
       0,     0,   903,   904,   905,   906,   907,   908,   909,   910,
     911,   912,   913,  1662,   915,   916,   917,   918,   919,   920,
     921,     0,   470,   470,   925,   927,   928,     0,     0,     0,
     932,   933,     0,   935,     0,     0,  1396,     0,   940,   941,
     942,     0,   944,     0,     0,     0,     0,     0,     0,   952,
     954,   470,     0,   559,     0,   470,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   977,     0,     0,
     586,     0,  1699,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,   294,   295,     0,     0,     0,   115,   116,
     117,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   296,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   151,
     152,   153,     0,     0,     0,  1396,   158,     0,     0,     0,
       0,     0,  1742,  1743,     0,     0,     0,   163,   164,   165,
       0,     0,     0,  1396,     0,   166,     0,     0,     0,   297,
       0,     0,   298,     0,     0,   299,     0,   300,     0,     0,
       0,     0,  1776,     0,     0,     0,     0,  1716,     0,   301,
       0,     0,     0,   692,     0,   577,    48,    49,    50,    51,
      52,  1795,   581,     0,     0,    56,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,   470,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1890,     0,     0,
       0,  1728,     0,     0,     0,     0,     0,  1813,     0,     0,
       0,     0,     0,     0,     0,  1760,     0,     0,     0,     0,
       0,   169,     0,     0,     0,   173,  1830,     0,     0,   174,
     175,   176,   177,   178,     0,     0,  1781,    90,     0,     0,
       0,     0,     0,     0,   470,     0,     0,     0,     0,     0,
       0,   181,   302,     0,     0,     0,   183,     0,     0,     0,
       0,   303,     0,     0,     0,   470,   187,     0,   304,   112,
     113,   114,     0,     0,     0,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,  1396,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,     0,     0,   159,   160,   161,
       0,     0,   162,     0,   163,   164,   165,     0,  1200,     0,
       0,     0,   166,   167,     0,     0,     0,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   740,   444,
     445,     0,     0,     0,     0,   446,     0,  1882,     0,  1885,
       0,  1222,  1223,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     0,
       0,   446,     0,     0,     0,     0,   470,     0,   470,     0,
       0,     0,  1396,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,   168,     0,     0,     0,     0,     0,     0,   169,   170,
     171,   172,   173,     0,     0,     0,   174,   175,   176,   177,
     178,   179,     0,   180,    90,  1941,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   182,
       0,     0,     0,   183,     0,     0,     0,     0,   184,     0,
     185,     0,   186,   187,   470,   188,     0,   189,     0,     0,
       0,   694,    24,    25,   695,    27,    28,   696,    30,   697,
      32,     0,    33,     0,     0,     0,     0,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,  1344,     0,
       0,     0,     0,     0,  1348,  1349,  1350,  1351,  1352,     0,
    1355,     0,  1357,  1358,     0,  1361,  1364,     0,     0,  1368,
    1369,  1370,     0,     0,     0,     0,  1374,     0,     0,     0,
      67,    68,    69,   112,   294,     0,     0,     0,     0,   115,
     116,   117,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   296,   984,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,   152,   153,     0,     0,     7,     8,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,   164,
     165,  1833,     0,     0,     0,     0,   166,     0,     0,     0,
     297,     0,     0,   298,     0,     0,   299,     0,   300,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
       0,     0,  1482,   694,    24,    25,   695,    27,    28,   696,
      30,   697,    32,     0,    33,  1489,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,  1502,
       0,     0,     0,     0,  1506,     0,     0,  1176,  1177,     0,
       0,     0,   169,  1181,  1182,     0,   173,     0,     0,     0,
     174,   175,   176,   177,   178,  1122,     0,     0,    90,     0,
       0,     0,    67,    68,    69,     0,  1519,  1520,     0,     0,
    1522,  1523,   527,  1605,  1326,     0,     0,   183,     0,     0,
       0,     0,   529,     0,     0,     0,     0,   187,     0,   261,
     579,     0,     0,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   112,   294,     0,
       0,   446,     0,   115,   116,   117,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,   151,   152,   153,     0,     0,     0,
       0,   158,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,   164,   165,     0,     0,     0,     0,     0,
     166,     0,     0,     0,   297,     0,     0,   298,     0,     0,
     299,     0,   300,     0,     0,     0,     0,     0,  1632,  1633,
       0,     0,  1635,  1636,   301,     0,     0,     0,  1639,  1640,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,  1334,  1335,    59,     0,     0,  1339,  1340,     0,     0,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,     0,     0,     0,   169,   446,     0,     0,
     173,     0,     0,     0,   174,   175,   176,   177,   178,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   468,     0,     0,
       0,   183,     0,     0,     0,     0,   303,     0,     0,     0,
       0,   187,     0,     0,   579,   112,   294,   114,     0,     0,
       0,   115,   116,   117,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   296,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,     0,     0,   159,   160,   161,     0,     0,   162,     0,
     163,   164,   165,     0,     0,     0,     0,     0,   166,   167,
       0,     0,   297,     0,     0,   298,     0,     0,   299,     0,
     300,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,  1585,     0,  1586,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   170,   171,   172,   173,     0,
       0,     0,   174,   175,   176,   177,   178,   179,     0,   180,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   302,     0,     0,     0,   183,
       0,     0,     0,     0,   303,     0,   112,   294,   114,   187,
       0,   304,   115,   116,   117,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     296,     0,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,     0,     0,   159,   160,   161,     0,     0,   162,
       0,   163,   164,   165,     0,     0,     0,     0,     0,   166,
     167,     0,     0,   297,     0,     0,   298,     0,     0,   299,
       0,   300,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   301,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     0,
       0,   446,     0,     0,     0,     0,     0,     0,  1621,     0,
    1622,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,   173,
       0,     0,     0,   174,   175,   176,   177,   178,   179,     0,
     180,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   302,     0,     0,     0,
     183,     0,     0,     0,     0,   303,     0,   112,   338,   114,
     187,     0,  1641,   115,   116,   117,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,     0,     0,   159,   160,   161,     0,     0,
     162,     0,   163,   164,   165,     0,   112,   338,   114,     0,
     166,   167,   115,   116,   117,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,     0,     0,   159,   160,   161,     0,     0,   162,
       0,   163,   164,   165,     0,     0,     0,     0,     0,   166,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,   171,   172,
     173,     0,     0,     0,   174,   175,   176,   177,   178,   179,
       0,   180,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   182,     0,     0,
       0,   183,     0,     0,     0,     0,   303,     0,     0,     0,
       0,   187,     0,  1404,     0,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,     0,   446,     0,   169,   170,   171,   172,   173,
    1762,     0,  1763,   174,   175,   176,   177,   178,   179,     0,
     180,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
     183,     0,     0,     0,     0,   303,     0,   112,   338,   114,
     187,     0,  1626,   115,   116,   117,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     7,     8,     0,   159,   160,   161,     0,     0,
     162,     0,   163,   164,   165,     0,     0,     0,     0,     0,
     166,   167,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,     0,     0,   982,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
     694,    24,    25,   695,    27,    28,   696,    30,   697,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,   171,   172,
     173,     0,     0,     0,   174,   175,   176,   177,   178,   179,
       0,   180,    90,     0,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,     0,   181,   182,     0,     0,
       0,   183,     0,     0,     0,     0,   303,     0,   112,   294,
    1470,   187,     0,  1644,   115,   116,   117,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   151,   152,   153,     0,     0,
    1911,     0,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,   164,   165,     0,     0,     0,     0,
       0,   166,     0,     0,     0,   297,     0,     0,   298,     0,
       0,   299,     0,   300,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   301,     0,   328,   114,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,     0,     0,     0,   154,   155,   156,   157,
       0,     0,     0,     0,   159,   160,   161,   169,     0,   162,
       0,   173,     0,     0,     0,   174,   175,   176,   177,   178,
     167,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   302,     0,
       0,     0,   183,     0,     0,     0,     0,   303,     0,   112,
     294,     0,   187,     0,  1471,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   296,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,   151,   152,   153,     0,
       0,     0,     0,   158,     0,     0,   170,   171,   172,     0,
       0,     0,     0,     0,   163,   164,   165,     0,   179,     0,
     180,    90,   166,     0,     0,     0,   297,     0,     0,   298,
       0,     0,   299,     0,   300,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   301,     0,   454,   114,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,     0,     0,   154,   155,   156,
     157,     0,     0,     0,     0,   159,   160,   161,   169,     0,
     162,     0,   173,     0,     0,     0,   174,   175,   176,   177,
     178,   167,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   302,
       0,     0,     0,   183,     0,     0,     0,     0,   303,     0,
     112,   294,     0,   187,     0,   304,   115,   116,   117,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,   151,   152,   153,
       0,     0,     0,     0,   158,     0,     0,   170,   171,   172,
       0,     0,     0,     0,     0,   163,   164,   165,     0,   179,
       0,   180,    90,   166,     0,     0,     0,   297,     0,     0,
     298,   332,   114,   299,     0,   300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   301,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     0,     0,     0,     0,
     154,   155,   156,   157,     0,     0,     0,     0,   159,   160,
     161,     0,     0,   162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,     0,     0,     0,     0,   169,
       0,     0,     0,   173,     0,     0,     0,   174,   175,   176,
     177,   178,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     302,     0,     0,     0,   183,     0,     0,     0,     0,   500,
       0,   112,   294,     0,   187,     0,   304,   115,   116,   117,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   296,     0,     0,     0,     0,
     170,   171,   172,     0,     0,     0,     0,   150,   151,   152,
     153,     0,   179,     0,   180,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,     0,
       0,     0,     0,     0,   166,     0,     0,     0,   297,     0,
       0,   298,     0,   114,   299,     0,   300,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   301,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,     0,
       0,   154,   155,   156,   157,     0,     0,     0,     0,   159,
     160,   161,     0,     0,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,     0,     0,     0,     0,
     169,     0,     0,     0,   173,     0,     0,     0,   174,   175,
     176,   177,   178,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   302,     0,     0,     0,   183,     0,     0,     0,     0,
     502,     0,   112,   294,     0,   187,     0,   304,   115,   116,
     117,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   296,     0,     0,     0,
       0,   170,   171,   172,     0,     0,     0,     0,   150,   151,
     152,   153,     0,   179,     0,   180,   158,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,   164,   165,
       0,     0,     0,     0,     0,   166,     0,     0,     0,   297,
       0,     0,   298,     0,     0,   299,     0,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   301,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,     0,     0,     0,     0,   446,     0,     0,
       0,     0,     0,     0,     0,     0,  1035,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,     0,     0,     0,   173,     0,     0,     0,   174,
     175,   176,   177,   178,     0,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   302,     0,     0,     0,   183,     0,     0,     0,
       0,   504,     0,   112,   294,     0,   187,     0,   304,   115,
     116,   117,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   296,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,   152,   153,     0,     0,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,   164,
     165,     0,     0,     0,     0,     0,   166,     0,     0,     0,
     297,     0,     0,   298,     0,     0,   299,     0,   300,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
       0,     0,     0,     0,     0,     0,     0,  1088,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,     0,     0,     0,   173,     0,     0,     0,
     174,   175,   176,   177,   178,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   468,     0,     0,     0,   183,     0,     0,
       0,     0,   303,     0,   112,   294,     0,   187,     0,   575,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,   151,   152,   153,     0,     0,     0,     0,   158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
     164,   165,     0,     0,     0,     0,     0,   166,     0,     0,
       0,   297,     0,     0,   298,     0,     0,   299,     0,   300,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   301,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,     0,     0,     0,     0,   446,
       0,     0,     0,     0,     0,     0,     0,     0,  1113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,     0,     0,     0,   173,     0,     0,
       0,   174,   175,   176,   177,   178,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   468,     0,     0,     0,   183,     0,
       0,     0,     0,   303,     0,   112,   294,     0,   187,     0,
     838,   115,   116,   117,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,   151,   152,   153,     0,     0,     0,     0,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,   164,   165,     0,     0,     0,     0,     0,   166,     0,
       0,     0,   297,     0,     0,   298,     0,     0,   299,     0,
     300,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,     0,     0,  1152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,     0,     0,     0,   173,     0,
       0,     0,   174,   175,   176,   177,   178,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   468,     0,     0,     0,   183,
       0,     0,     0,     0,   303,     0,   112,   294,     0,   187,
       0,   841,   115,   116,   117,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,   151,   152,   153,     0,     0,     0,     0,
     158,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,   164,   165,     0,     0,     0,     0,     0,   166,
       0,     0,     0,   297,     0,     0,   298,     0,     0,   299,
       0,   300,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   301,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     0,
       0,   446,     0,     0,     0,     0,     0,     0,     0,     0,
    1268,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,     0,     0,     0,   173,
       0,     0,     0,   174,   175,   176,   177,   178,     0,     0,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   468,     0,     0,     0,
     183,     0,     0,     0,     0,   303,     0,   112,   294,     0,
     187,     0,   861,   115,   116,   117,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,   151,   152,   153,     0,     0,     0,
       0,   158,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,   164,   165,     0,     0,     0,     0,     0,
     166,     0,     0,     0,   297,     0,     0,   298,     0,     0,
     299,     0,   300,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   301,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,     0,
       0,  1583,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,     0,     0,     0,
     173,     0,     0,     0,   174,   175,   176,   177,   178,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   302,     0,     0,
       0,   183,     0,     0,     0,     0,   303,     0,   112,   294,
       0,   187,     0,  1475,   115,   116,   117,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   151,   152,   153,     0,     0,
       0,     0,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,   164,   165,     0,     0,     0,     0,
       0,   166,     0,     0,     0,   297,     0,     0,   298,     0,
       0,   299,     0,   300,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   301,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,     0,   446,     0,     0,     0,     0,     0,     0,
       0,     0,  1602,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
       0,   173,     0,     0,     0,   174,   175,   176,   177,   178,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   527,  1605,     0,
       0,     0,   183,     0,     0,     0,     0,   529,     0,   112,
     338,     0,   187,     0,   261,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,   151,   152,   153,     0,
       0,     0,     0,   158,     0,     0,     0,     0,     0,     0,
       0,     0,   112,   338,   163,   164,   165,     0,   115,   116,
     117,     0,   166,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   151,
     152,   153,     0,     0,     0,     0,   158,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,   164,   165,
       0,     0,     0,     0,     0,   166,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,   169,     0,
       0,     0,   173,  1672,     0,     0,   174,   175,   176,   177,
     178,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   182,
       0,     0,     0,   183,     0,     0,     0,     0,   303,     0,
       0,     0,     0,   187,     0,   507,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,   169,     0,     0,   446,   173,     0,     0,   686,   174,
     175,   176,   177,   178,     0,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   527,   528,     0,     0,     0,   183,     0,     0,     0,
       0,   529,     0,   112,   338,   114,   187,     0,   261,   115,
     116,   117,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,     0,
       0,   159,   160,   161,     0,     0,   162,     0,   163,   164,
     165,     0,     0,     0,     0,     0,   166,   167,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,     0,     0,  1673,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,     0,     0,  1674,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,     0,
       0,  1675,   169,   170,   171,   172,   173,     0,     0,     0,
     174,   175,   176,   177,   178,   179,     0,   180,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   182,     0,     0,     0,   183,   112,   294,
       0,     0,   303,     0,   115,   116,   117,   187,     0,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   151,   152,   153,     0,     0,
       0,     0,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,   164,   165,     0,     0,     0,     0,
       0,   166,     0,     0,     0,   297,     0,     0,   298,     0,
       0,   299,     0,   300,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   301,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,     0,   446,     0,     0,     0,     0,     0,     0,
       0,     0,  1676,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
       0,   173,     0,     0,     0,   174,   175,   176,   177,   178,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   468,     0,
       0,     0,   183,   112,   338,     0,     0,   303,     0,   115,
     116,   117,   187,     0,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,   152,   153,     0,     0,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,   112,   338,   163,   164,
     165,     0,   115,   116,   117,     0,   166,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,   151,   152,   153,     0,     0,     0,     0,
     158,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,   164,   165,     0,     0,     0,     0,     0,   166,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
       0,     0,   169,     0,     0,     0,   173,  1708,     0,     0,
     174,   175,   176,   177,   178,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   182,     0,     0,     0,   183,     0,     0,
       0,     0,   303,     0,     0,   419,     0,   187,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,   169,   446,     0,     0,   173,
     878,     0,     0,   174,   175,   176,   177,   178,     0,     0,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
     183,   112,   338,     0,     0,   303,   614,   115,   116,   117,
     187,     0,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,   151,   152,
     153,     0,     0,     0,     0,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,   112,
     338,     0,  1274,     0,   166,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,   151,   152,   153,     0,
       0,     0,     0,   158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,   164,   165,     0,     0,     0,
       0,     0,   166,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     0,
     169,   446,     0,     0,   173,   894,     0,     0,   174,   175,
     176,   177,   178,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   182,     0,     0,     0,   183,     0,     0,     0,     0,
     303,     0,     0,   616,     0,   187,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,   169,     0,
       0,     0,   173,  1778,     0,     0,   174,   175,   176,   177,
     178,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   182,
       0,     0,     0,   183,   112,   338,     0,     0,   303,     0,
     115,   116,   117,   187,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,   151,   152,   153,     0,     0,     0,     0,   158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
     164,   165,     0,     0,     0,     0,     0,   166,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,     0,     0,  1788,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,     0,     0,  1789,     0,     0,     0,     0,     0,     0,
       0,     0,    -4,     1,     0,     0,    -4,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,     0,     0,     0,     0,
       0,     0,     0,   169,     0,     0,     0,   173,     0,     0,
       0,   174,   175,   176,   177,   178,     0,     0,     0,    90,
      -4,    -4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,     0,     0,     0,   183,     0,
      -4,    -4,    -4,   303,     0,     0,    -4,    -4,   187,    -4,
       0,     0,     0,    -4,    -4,     0,    -4,    -4,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,
       6,     0,     0,     0,     0,    -4,     0,     0,     7,     8,
      -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     9,    10,     0,     0,     0,    -4,
      -4,    -4,     0,     0,     0,     0,     0,     0,    -4,     0,
      -4,     0,     0,     0,    11,    12,    13,     0,     0,     0,
      14,    15,     0,    16,     0,     0,     0,    17,    18,     0,
      19,    20,     0,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     0,
       0,    62,    63,    64,     0,     0,     0,     0,     0,    65,
       0,     0,     0,     0,    66,    67,    68,    69,     0,     0,
      70,     0,    71,     0,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,     0,    86,    87,    88,     0,     0,     0,     0,
       0,     0,    89,     0,    90,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,     0,   446,     0,     0,     0,     0,     0,     0,
       0,     0,  1821,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     0,
       0,   446,     0,     0,     0,     0,     0,     0,     0,     0,
    1824,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,     0,     0,     0,     0,   446,
       0,     0,     0,     0,     0,     0,     0,     0,  1827,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,     0,     0,     0,     0,   446,     0,     0,
       0,     0,     0,     0,     0,     0,  1858,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,     0,     0,     0,     0,   446,     0,     0,     0,     0,
       0,     0,     0,     0,  1865,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,     0,   446,     0,     0,     0,     0,     0,     0,
       0,     0,  1903,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     0,
       0,   446,     0,     0,     0,     0,     0,     0,     0,     0,
    1905,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,     0,     0,     0,     0,   446,
       0,     0,     0,     0,     0,     0,     0,     0,  1907,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,     0,     0,     0,     0,   446,     0,     0,
       0,     0,     0,     0,     0,     0,  1926,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,     0,     0,     0,     0,   446,     0,     0,     0,     0,
       0,     0,     0,     0,  1952,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,     0,   446,     0,     0,     0,     0,     0,     0,
       0,     0,  1990,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     0,
       0,   446,     0,     0,     0,     0,     0,     0,     0,     0,
    1991,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,     0,     0,     0,     0,   446,
       0,     0,     0,     0,     0,     0,     0,     0,  1995,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,     0,     0,     0,     0,   446,     0,     0,
       0,     0,     0,     0,     0,     0,  1996,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,     0,     0,     0,     0,   446,     0,     0,     0,     0,
       0,     0,     0,     0,  1997,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,     0,   446,     0,     0,     0,     0,     0,     0,
       0,     0,  1998,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     0,
       0,   446,     0,     0,     0,     0,     0,     0,     0,   608,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
       0,     0,     0,     0,     0,     0,   788,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,     0,     0,     0,     0,   446,     0,     0,     0,     0,
       0,     0,     0,  1684,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,   834,     0,   835,     0,     0,  1354,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
     858,     0,     0,     0,     0,   795,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,   729,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,   795,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,   796,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,   872,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
       0,     0,     0,     0,     0,   914,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,   922,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,   923,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,   924,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,   939,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
       0,     0,     0,     0,     0,  1070,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,  1071,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,  1072,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,  1103,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,  1218,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
       0,     0,     0,     0,     0,  1266,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,  1267,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,  1325,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,  1485,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,  1486,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
       0,     0,     0,     0,     0,  1487,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,  1488,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,  1539,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,  1540,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,  1547,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
       0,     0,     0,     0,     0,  1709,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,  1710,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,  1711,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,  1712,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,  1734,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
       0,     0,     0,     0,     0,  1735,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,  1739,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,  1839,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,  1840,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,  1841,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
       0,     0,     0,     0,     0,  1842,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,  1851,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,  1854,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,  1899,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,  1916,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
       0,     0,     0,     0,     0,  1917,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,  1918,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,  1919,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,  1963,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,  1964,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
       0,     0,     0,     0,     0,  1965,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,  1966,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,     0,     0,   901,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,     0,   446,     0,     0,     0,   997,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,     0,     0,
    1096,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,     0,     0,     0,     0,   446,
       0,     0,     0,  1097,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,     0,     0,  1101,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,     0,     0,     0,     0,   446,     0,     0,     0,  1102,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
       0,     0,  1105,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     0,
       0,   446,     0,     0,     0,  1125,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,     0,     0,  1154,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,     0,     0,     0,     0,   446,     0,     0,
       0,  1211,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,     0,     0,  1216,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,     0,   446,     0,     0,     0,  1480,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,     0,     0,
    1530,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,     0,     0,     0,     0,   446,
       0,     0,     0,  1697,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,   682,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,     0,   446,     0,   739,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,   743,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,     0,     0,     0,     0,   446,     0,   744,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,   746,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,     0,     0,     0,     0,   446,     0,   748,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
     749,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,     0,     0,     0,     0,   446,
       0,   752,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,   753,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     0,
       0,   446,     0,   858,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,   868,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,     0,   446,     0,   869,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,   870,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,     0,     0,     0,     0,   446,     0,   876,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,   877,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,     0,     0,     0,     0,   446,     0,   890,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
     900,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,     0,     0,     0,     0,   446,
       0,   996,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,  1024,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     0,
       0,   446,     0,  1029,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,  1034,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,     0,   446,     0,  1037,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,  1038,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,     0,     0,     0,     0,   446,     0,  1044,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,  1053,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,     0,     0,     0,     0,   446,     0,  1054,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
    1055,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,     0,     0,     0,     0,   446,
       0,  1087,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,  1089,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     0,
       0,   446,     0,  1090,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,  1091,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,     0,   446,     0,  1095,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
       0,     0,     0,     0,   446,     0,  1104,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,     0,     0,     0,     0,   446,     0,  1124,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,     0,     0,     0,     0,   446,     0,  1210,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,     0,     0,     0,     0,   446,     0,  1215,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,     0,     0,     0,     0,   446,     0,
    1366,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,     0,     0,     0,     0,   446,
       0,  1584,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,     0,     0,     0,     0,
     446,     0,  1601,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,     0,     0,     0,
       0,   446,     0,  1625,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,     0,     0,
       0,     0,   446,     0,  1850,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     0,
       0,     0,     0,   446,     0,  1924
};

static const yytype_int16 yycheck[] =
{
       3,  1086,   254,     6,     5,     7,   384,     4,   386,     4,
       6,   521,   522,  1082,     5,   269,     6,     4,     4,     4,
    1473,     5,     4,   401,     4,  1668,     5,   281,     6,     4,
       3,     5,   199,   200,     4,     4,     4,     4,    86,     5,
       5,     4,   209,     5,     5,     5,     4,   192,   193,     6,
       6,     6,   192,   193,    57,     0,     7,     6,     6,     6,
     144,    83,    65,   208,    86,   210,    80,    70,     4,    83,
     210,     4,    86,     6,   192,   193,   160,   161,    81,   192,
     193,   335,     6,   337,     6,   192,   193,   103,   192,   193,
       7,   209,     6,     6,     6,   208,   202,   210,   114,   192,
     193,   208,   202,   210,   204,   209,   122,   123,   124,   202,
      13,  1564,   128,   129,   130,   131,   209,    80,   192,   193,
       7,    84,   199,   200,   192,   193,   192,   193,   205,   192,
     193,     7,     6,    96,   208,     7,     4,   134,   135,   136,
     137,   209,   208,   202,     7,   208,   417,    80,   419,     6,
     421,   192,   193,   202,   132,   204,   147,     7,     6,     7,
     192,   193,   211,  1806,  1807,   192,   193,   208,   147,    81,
     111,    83,     6,   147,   159,   155,   208,   132,   192,   193,
       8,   208,   147,   132,   187,   132,   144,   145,   202,    86,
       6,    88,   178,   189,   210,   209,   199,   200,   178,   189,
     202,   206,   204,   178,   207,     7,   211,   202,   209,   204,
    1663,   206,   215,   210,   217,   188,   211,   204,   209,   222,
     202,  1290,     6,   226,   211,   209,   229,   209,  1681,   209,
     233,   234,   235,   236,   209,   202,   239,   240,   241,   209,
     209,   209,   209,   209,   247,   248,   249,   209,   209,   209,
     253,   254,   209,   209,   202,   206,     7,     3,   512,   513,
       6,   209,   179,   180,   181,   182,   202,   202,   192,   193,
     192,   193,   275,   276,   277,     7,   144,   145,   532,   192,
     193,   202,   199,   200,     7,     6,   289,   290,   209,   206,
     199,   200,   179,   180,   181,   182,   202,     6,   204,   302,
     209,   304,   214,   179,   180,   181,   182,   179,   180,   181,
     182,    57,   199,   200,   199,   200,   179,   180,   181,   182,
       4,   206,   199,   200,    70,   199,   200,   199,   200,   179,
     180,   181,   182,     6,     7,    81,   199,   200,   341,   593,
     343,   344,   202,   614,   204,   616,   206,   203,   202,   199,
     200,   211,   208,   356,   608,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   194,
     195,   196,   208,   201,   210,   203,   201,   179,   180,   181,
     182,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   204,   398,   399,   400,   401,   402,
    1853,   192,   193,   406,   407,   408,   409,   410,   411,   202,
     413,   682,   199,   200,   204,   686,   209,   208,   192,   193,
     192,   193,   209,   107,   108,   109,   110,   430,   179,   180,
     181,   182,   116,   203,   208,   119,   208,   349,   208,   192,
     193,   187,   199,   200,   192,   193,   202,   179,   180,   181,
     182,    90,   209,   199,   200,   208,   179,   180,   181,   182,
     208,   207,   103,   192,   193,   468,   203,   341,   205,   215,
     192,   193,   209,   114,   202,   192,   193,   192,   193,   208,
     421,   122,   123,   124,   192,   193,   208,   128,   129,   130,
     131,   208,   404,   208,   192,   193,   202,  1950,   204,   202,
     412,   202,   202,   506,   507,   211,   209,   203,   254,   209,
     208,   385,   208,   387,   388,   389,   390,   391,   392,   393,
      83,   395,   396,    86,   398,   399,   400,     6,   402,   208,
     202,   210,   406,   407,   408,   409,   410,   791,   192,   193,
     192,   193,   202,   202,   204,   548,   549,   550,   521,   522,
     203,   211,   192,   193,   208,   208,   208,   560,   561,   234,
     235,   236,   192,   193,   239,   240,   241,    86,   208,   210,
     199,   200,   575,   192,   193,   192,   193,   203,   208,   582,
     209,   202,   208,   204,   496,   497,   498,   499,    86,   208,
     211,   208,   199,   200,   202,   341,   204,   208,   601,   210,
     275,   276,   209,   211,   107,   108,   103,  1692,     6,  1694,
     113,  1696,   107,   108,   289,   290,   619,   114,   113,   890,
     202,   209,   204,   894,   206,   122,   123,   124,    86,   211,
     203,   128,   129,   130,   131,   208,    86,    88,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   205,   395,
     396,   208,   398,   399,   400,   401,   402,   208,   202,   210,
     406,   407,   408,   409,   410,   411,    83,   413,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    80,   681,   203,
      83,   201,   685,    86,   208,   626,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,  1766,   209,   205,
    1769,   201,   208,  1772,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   203,   209,
     205,   724,   201,   975,   209,   728,    86,   208,   731,   210,
      86,   734,   103,   736,    83,    83,    80,   740,   741,    83,
       4,   682,    86,   114,    88,   686,   208,     4,   210,  1834,
       4,   122,   123,   124,   203,     4,   205,   128,   129,   130,
     131,   764,   103,   192,   193,   194,   195,   196,   208,   208,
     210,   210,   201,   114,  1045,   687,  1047,   208,  1049,   210,
    1051,   122,   123,   124,   208,   788,   210,   128,   129,   130,
     131,    83,   202,   202,    86,   204,    88,   206,  1176,  1177,
     209,   202,   211,  1181,  1182,    83,    80,   202,    86,    83,
      88,  1880,    86,   202,    88,   561,     6,  1902,   203,  1904,
     205,  1906,   208,   208,   210,   202,   738,  1912,     8,   203,
     208,   205,   210,   836,   208,   838,     6,   204,   841,   210,
     203,   203,   205,   205,   202,   208,   208,   850,   209,   852,
     203,   854,   205,   856,   208,   208,   210,   731,   861,     8,
       7,  1930,   736,   866,  1933,   204,   208,  1936,   210,   210,
    1939,  1956,   203,  1958,   205,  1960,   203,   208,   205,   202,
     202,   208,   885,   208,   202,   210,   889,    86,   204,    88,
     893,    86,   833,    88,   208,   208,   210,   210,   901,   208,
     202,   210,     6,   208,   202,   210,  1975,   208,  1977,   210,
    1979,   202,   208,  1184,   210,   208,     6,   210,   208,   208,
     210,   210,   208,   926,   210,   208,   202,   210,   931,  1200,
     202,   202,   202,   936,   937,   938,   939,     6,     4,  1191,
    1450,  1451,   208,   208,   210,   210,   949,   209,   951,   890,
     208,   202,   210,   894,   209,   202,  1334,  1335,   204,   900,
     901,  1339,  1340,   208,   208,   210,   210,   208,     4,   210,
       6,   208,   975,   210,   209,   978,   979,   980,   981,   208,
     208,   210,   210,   202,   208,   731,   210,   208,   734,   210,
     736,   208,   208,   210,   210,   208,   208,   210,   210,   208,
    1003,   210,   202,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   202,   202,  1022,
    1023,   201,  1025,   202,  1027,  1028,   202,   901,  1031,  1032,
     210,   202,     6,  1036,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   208,   208,
     210,   210,   201,   209,   202,   996,   997,   931,   208,   202,
     210,   210,   202,   937,   938,   939,   208,   208,   210,   210,
     208,     6,   210,  1344,   208,   949,   210,   951,   209,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    49,    50,   209,    52,   201,   208,   208,
     210,   210,   208,   208,   210,   210,   208,   202,   210,     4,
       5,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   209,  1127,  1128,  1129,   201,   208,  1003,
     210,   209,   208,  1385,   210,   208,  1139,   210,   208,   202,
     210,   209,     6,   204,   211,    40,    41,    42,    43,    44,
      45,    46,    47,    48,   209,   901,   209,   209,    53,    54,
      55,    56,   204,  1104,  1105,   204,    61,    62,    63,     6,
       6,    66,   209,  1176,  1177,   147,   211,  1687,  1181,  1182,
       6,     6,    77,  1124,  1125,   931,   209,     6,  1191,     6,
     209,   937,   938,   939,   209,     6,   204,     4,   201,   206,
     209,     7,  1205,   949,   210,   951,   208,   208,     7,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     6,     6,     6,  1229,   201,     7,   975,
       7,     6,  1235,     6,     6,   203,     6,     6,  1241,   209,
    1243,  1244,     7,  1184,     7,  1248,  1249,     6,  1251,     6,
    1253,     6,  1255,     4,  1257,  1258,  1259,  1003,    58,   144,
      58,    58,    58,   209,   205,   203,  1644,     6,   163,   164,
     165,     6,     6,  1276,   203,   203,   208,   208,   208,   205,
     175,   208,   177,   178,   208,   208,   208,   203,  1291,   203,
     203,    40,  1295,    40,  1297,    40,    40,     6,     4,   103,
       4,   257,   258,     6,   199,   200,     6,  1219,     6,   265,
     114,   206,     6,   269,   209,     7,   147,     7,   122,   123,
     124,     7,     4,     5,   128,   129,   130,   131,     7,   147,
       7,  1334,  1335,     7,   147,     7,  1339,  1340,     7,   209,
       4,     6,   203,   208,   203,   208,   203,   203,   208,     6,
    1353,   203,   206,   208,   205,     7,  1359,   210,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     6,   210,   209,
     209,    53,    54,    55,    56,   209,   209,     7,     7,    61,
      62,    63,  1385,   206,    66,   209,     6,    40,  1391,    40,
      40,    40,     6,     6,     6,    77,   103,     6,  1401,     6,
       6,  1404,  1654,     7,   209,  1346,   210,   114,   202,   204,
     202,     6,    88,   189,     7,   122,   123,   124,     7,  1331,
       7,   128,   129,   130,   131,     7,     7,     7,     6,   209,
    1176,  1177,     7,     7,     7,  1181,  1182,     7,     7,  1442,
    1443,     7,     4,     4,   202,  1191,     6,  1701,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     7,     6,     6,  1377,   201,     7,  1471,     7,
    1473,     7,  1475,   209,     6,     6,    86,  1450,  1451,  1353,
       7,   163,   164,   165,     6,  1359,     6,     4,     4,  1492,
       4,   208,  1404,   175,   210,   177,   178,  1500,     6,     6,
       6,     6,     6,   210,     4,   103,   208,  1510,     6,   208,
     203,   206,  1515,     7,   203,   202,   114,     6,   209,     6,
     203,   203,   206,   205,   122,   123,   124,  1401,     6,     6,
     128,   129,   130,   131,  1446,   205,   209,    96,  1541,     6,
    1481,   209,   209,   209,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     6,     6,
       6,  1564,   201,   519,   520,   209,     6,     5,     4,     6,
       4,   527,   209,   209,     7,   209,   209,   204,     6,     6,
       6,  1835,     6,     6,   209,   209,  1498,   209,  1334,  1335,
     205,     6,   203,  1339,  1340,     6,   143,  1600,     6,     6,
     208,     4,  1605,  1515,  1516,  1517,     6,  1353,   103,     6,
       4,     6,   210,  1359,     6,     6,    12,    13,     6,   114,
       6,     6,     6,  1626,     4,     7,     7,   122,   123,   124,
       6,     6,     6,   128,   129,   130,   131,     6,  1641,  1385,
       5,  1644,     6,     6,   209,     6,   147,     6,     6,     6,
       6,  1654,     6,     6,     6,  1401,   208,     6,     6,     6,
    1663,     6,    12,    13,     6,     6,     6,  1670,  1671,   208,
       6,     6,     6,   203,     6,     6,     6,     6,  1681,     7,
       6,  1684,   206,     6,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     8,    91,   209,  1700,     6,   209,
      96,    97,  1705,    99,   100,   101,   209,     5,   210,   105,
       6,    84,   209,     6,  1687,   210,     6,  1629,   209,     6,
     210,   209,     7,   209,   209,   209,     6,     6,   142,   210,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       6,    91,     6,   139,   140,   141,    96,    97,     6,    99,
     100,   101,  1755,     6,     6,   105,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       6,  1774,     6,   145,   201,     6,     6,     6,     6,     6,
     209,     6,     6,   203,     6,   210,     7,     6,   209,   139,
     140,   141,   209,  1796,     6,     6,    89,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   209,     6,     6,   210,   201,   209,   103,     6,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,  1836,     6,  1838,   103,   201,   794,   209,
       6,     6,     6,     6,     6,   801,     6,   114,     6,     6,
    1853,   807,     6,     6,   209,   122,   123,   124,   202,   210,
     210,   128,   129,   130,   131,   203,   209,     6,     6,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,  1795,   209,   209,     6,   201,   181,   182,
     183,   184,   185,     6,     6,     6,   209,   209,  1644,   209,
     209,     6,   209,     6,     6,   198,     6,  1214,  1654,   202,
       6,  1914,     6,    12,    13,     6,     6,     6,     6,     6,
    1923,     6,     6,   216,   217,   218,   219,   464,   221,   222,
     223,   224,  1799,   226,   227,   228,  1669,     3,     3,   494,
     233,  1228,  1683,   210,  1381,    -1,    -1,  1950,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,    -1,
      -1,    -1,    -1,    -1,  1967,    -1,  1969,   260,   261,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,  1890,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    91,    -1,    -1,    -1,  1999,    96,    97,    -1,
      99,   100,   101,    -1,    -1,    -1,   105,    -1,    -1,   302,
     303,   304,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   314,   315,   316,    -1,   318,    -1,    -1,    -1,   322,
     323,   324,    -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,  1923,
    1796,    -1,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1018,    -1,    -1,    -1,   359,   360,    -1,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,    -1,    -1,  1967,    -1,  1969,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   397,    -1,    -1,    -1,    -1,    -1,
     403,   210,   405,    -1,  1070,  1071,  1072,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1999,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   429,   430,    -1,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,    -1,    -1,   449,   450,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,   468,    -1,  1923,    -1,   114,
      -1,   474,    -1,    -1,    -1,    -1,   479,   122,   123,   124,
      -1,   484,   485,   128,   129,   130,   131,   490,   491,    -1,
      -1,    -1,   495,   496,   497,   498,   499,   500,    -1,   502,
      -1,   504,    -1,   506,   507,    -1,    -1,    -1,    -1,    -1,
      -1,  1967,    -1,  1969,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   524,   525,   526,   527,   528,   529,    -1,    -1,    -1,
     533,   534,   535,   536,   537,    -1,    -1,    -1,   541,    -1,
     543,   544,    -1,  1999,    -1,   548,   549,   550,    -1,    -1,
     553,   554,   555,   556,   557,    -1,    -1,   560,   561,    -1,
      -1,   564,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   575,    -1,    -1,    -1,    -1,    -1,   581,   582,
      -1,   584,   585,    -1,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   601,    -1,
      -1,    -1,   201,   606,   607,    -1,   609,   610,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   618,   619,    -1,    -1,    -1,
     623,    -1,    -1,  1289,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,   103,    -1,    -1,   688,    57,    -1,    -1,   103,
      -1,    -1,    -1,   114,    -1,    -1,     6,    68,    69,    70,
      -1,   122,   123,   124,    -1,    76,    -1,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,     6,    -1,   720,   721,    -1,
      -1,   724,   725,   726,    -1,   728,   729,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   737,    -1,   103,   740,   741,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,  1414,    -1,
      -1,   754,    -1,    -1,    -1,   122,   123,   124,    -1,    -1,
     763,   128,   129,   130,   131,    -1,    -1,    -1,    -1,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   788,  1452,   201,  1454,   210,
    1456,   162,   795,   796,    -1,   166,    -1,    -1,   801,   170,
     171,   172,   173,   174,    -1,  1471,    -1,   178,  1474,  1475,
      -1,   814,    -1,    -1,   817,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   193,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,   202,   203,   836,    -1,   838,   207,    -1,   841,    -1,
      -1,   229,    -1,   210,    -1,    -1,    -1,   850,    -1,   852,
      -1,   854,    -1,   856,    -1,    -1,    -1,    -1,   861,   247,
     248,   249,    -1,   866,    -1,   253,    -1,    -1,    -1,   872,
      -1,   874,   875,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,   277,
      -1,   201,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,   217,    -1,
     201,   914,    -1,   222,    -1,    -1,    -1,   226,    -1,   922,
     923,   924,    -1,   926,   233,    12,    13,    -1,    -1,    -1,
      -1,   934,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,   948,   226,    -1,     6,    -1,
     953,    -1,    -1,   233,    -1,   343,   344,    -1,    -1,   962,
      -1,    -1,    -1,    -1,    -1,   968,    -1,    -1,   356,    -1,
      -1,    -1,    -1,    -1,    -1,   978,   979,   980,   981,    -1,
      -1,   984,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    91,    -1,   394,    -1,    -1,    96,
      97,    -1,    99,   100,   101,    -1,    -1,    -1,   105,    -1,
      -1,    -1,   302,    -1,   304,  1691,    -1,  1693,    -1,  1695,
      -1,    -1,    -1,  1036,    -1,    -1,    -1,  1703,    -1,    -1,
    1706,    -1,    -1,  1046,    -1,  1048,    -1,  1050,    -1,  1052,
      -1,    -1,   139,   140,   141,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     6,    91,    -1,    -1,
      -1,  1074,    96,    97,    -1,    99,   100,   101,   103,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,  1754,   114,
      12,    13,  1758,    -1,    -1,    -1,    -1,   122,   123,   124,
    1103,    -1,    -1,   128,   129,   130,   131,    -1,    -1,  1112,
      -1,  1114,  1115,  1116,    -1,   139,   140,   141,    -1,  1122,
      -1,   430,    -1,   210,    -1,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,  1145,   201,    -1,  1811,    -1,  1150,    -1,  1815,
     430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      -1,    -1,  1838,    -1,    96,    97,     6,    99,   100,   101,
      -1,    -1,    -1,   105,    -1,   210,   210,    -1,   468,  1192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   506,   507,    -1,
    1203,  1204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1218,  1219,   139,   140,   141,
       8,    -1,    -1,    -1,    -1,    -1,   506,   507,    -1,    -1,
      -1,    -1,    -1,    -1,  1900,  1901,    -1,    -1,    -1,   548,
     549,   550,    -1,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    12,
      13,   201,  1265,  1266,  1267,    -1,   575,    -1,   548,   549,
     550,    -1,    -1,  1276,    -1,  1278,    -1,    -1,    -1,    -1,
     560,   561,    -1,    -1,    -1,    -1,  1289,    -1,   210,    -1,
      -1,    -1,   601,   681,  1297,   575,    -1,   685,    -1,  1302,
      -1,    -1,   582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   601,  1325,  1326,  1327,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,   619,
      -1,    -1,    -1,    96,    97,    -1,    99,   100,   101,    -1,
      -1,  1354,   105,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,  1378,   764,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,  1392,
      -1,    -1,    -1,    -1,  1397,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,  1412,
    1413,    -1,    -1,   201,    -1,   724,  1419,  1420,    -1,   728,
      -1,  1424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1432,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1442,
    1443,  1444,    -1,  1446,   724,    -1,    -1,    -1,   728,    -1,
      -1,    -1,    -1,    -1,    -1,  1458,    -1,   210,    -1,    -1,
     740,   741,    -1,    -1,    -1,    -1,    -1,    -1,  1471,    -1,
      -1,    -1,  1475,    -1,    -1,  1478,    -1,    -1,    -1,   788,
      -1,    -1,  1485,  1486,  1487,  1488,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1498,    -1,   885,    -1,    -1,
      -1,   889,    -1,    -1,    -1,   893,    -1,    -1,   788,    -1,
      -1,    -1,    -1,  1516,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,   836,    -1,   838,
      -1,    -1,   841,    -1,    -1,    -1,  1539,  1540,    -1,    -1,
      -1,   850,    -1,   852,  1547,   854,    -1,   856,   936,    -1,
      -1,    -1,   861,    -1,    -1,    -1,   836,   866,   838,    -1,
      -1,   841,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     850,    -1,   852,    -1,   854,    -1,   856,    -1,    -1,    -1,
      -1,   861,  1585,     6,    -1,    -1,   866,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
    1603,    -1,  1605,    -1,    96,    97,    -1,    99,   100,   101,
      -1,    -1,    -1,   105,    -1,    -1,    -1,   926,  1621,    -1,
    1623,    -1,    -1,  1626,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1022,  1023,    -1,  1025,  1641,  1027,
    1028,    -1,    -1,  1031,  1032,    -1,   926,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,  1659,    -1,    -1,    -1,
      -1,  1664,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   978,
     979,   980,   981,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1684,    -1,    -1,    -1,    -1,    -1,    -1,  1691,    -1,
    1693,    -1,  1695,    -1,    -1,    -1,    -1,    -1,   978,   979,
     980,   981,  1705,    -1,    -1,    -1,  1709,  1710,  1711,  1712,
    1713,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1036,    -1,    -1,
      -1,  1734,  1735,    -1,    -1,    -1,  1739,    -1,    -1,  1127,
    1128,  1129,    -1,    -1,    -1,    -1,    -1,    -1,  1751,    -1,
      -1,  1139,    -1,    -1,    -1,    -1,  1036,    -1,    -1,  1762,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
    1793,    -1,    -1,    -1,    -1,    -1,  1799,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1808,    12,    13,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,  1205,    -1,  1822,
      -1,    -1,  1825,    -1,    -1,  1828,    -1,    -1,    -1,  1832,
      -1,    -1,    -1,  1836,    -1,  1838,  1839,  1840,  1841,  1842,
      -1,  1229,    -1,    -1,    -1,    -1,    -1,  1235,  1851,    -1,
      -1,  1854,    -1,  1241,    -1,  1243,  1244,    -1,    -1,    -1,
    1248,  1249,    -1,  1251,    -1,  1253,    -1,  1255,    -1,  1257,
    1258,  1259,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    91,    -1,    -1,  1276,    -1,
      96,    97,    -1,    99,   100,   101,  1899,    -1,    -1,   105,
      -1,    -1,    -1,  1291,    -1,    -1,    -1,  1295,    -1,    -1,
      -1,  1914,     8,  1916,  1917,  1918,  1919,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
    1953,  1954,    -1,    -1,   201,    -1,   203,    -1,   205,    -1,
    1963,  1964,  1965,  1966,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,  1297,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,  1391,   210,    -1,    -1,   201,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,  1404,  1297,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,   147,   148,   149,   150,
      -1,   152,   153,   154,   155,   156,   157,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,   166,   167,    -1,    -1,    -1,
      -1,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1473,    -1,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   586,    -1,    -1,  1492,   201,    -1,    -1,    -1,    -1,
      -1,    -1,  1500,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1510,    -1,    -1,    -1,    -1,  1515,    -1,    -1,
      -1,    -1,    -1,  1442,  1443,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,  1541,   639,   640,   641,   642,   643,   644,
     645,    -1,  1442,  1443,   649,   650,   651,    -1,    -1,    -1,
     655,   656,    -1,   658,    -1,    -1,  1564,    -1,   663,   664,
     665,    -1,   667,    -1,    -1,    -1,    -1,    -1,    -1,   674,
     675,  1471,    -1,   294,    -1,  1475,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   692,    -1,    -1,
     311,    -1,  1600,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    -1,    -1,    -1,  1663,    57,    -1,    -1,    -1,
      -1,    -1,  1670,  1671,    -1,    -1,    -1,    68,    69,    70,
      -1,    -1,    -1,  1681,    -1,    76,    -1,    -1,    -1,    80,
      -1,    -1,    83,    -1,    -1,    86,    -1,    88,    -1,    -1,
      -1,    -1,  1700,    -1,    -1,    -1,    -1,  1626,    -1,   100,
      -1,    -1,    -1,   424,    -1,  1605,   107,   108,   109,   110,
     111,     7,     8,    -1,    -1,   116,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1626,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      -1,  1641,    -1,    -1,    -1,    -1,    -1,  1755,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1684,    -1,    -1,    -1,    -1,
      -1,   162,    -1,    -1,    -1,   166,  1774,    -1,    -1,   170,
     171,   172,   173,   174,    -1,    -1,  1705,   178,    -1,    -1,
      -1,    -1,    -1,    -1,  1684,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   193,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,   202,    -1,    -1,    -1,  1705,   207,    -1,   209,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,  1853,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    61,    62,    63,
      -1,    -1,    66,    -1,    68,    69,    70,    -1,   983,    -1,
      -1,    -1,    76,    77,    -1,    -1,    -1,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,   201,    -1,  1836,    -1,  1838,
      -1,  1016,  1017,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,  1836,    -1,  1838,    -1,
      -1,    -1,  1950,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,   166,    -1,    -1,    -1,   170,   171,   172,   173,
     174,   175,    -1,   177,   178,  1914,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
      -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,   202,    -1,
     204,    -1,   206,   207,  1914,   209,    -1,   211,    -1,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    91,    -1,    -1,    -1,    -1,    96,    97,    -1,
      99,   100,   101,    -1,    -1,    -1,   105,    -1,  1153,    -1,
      -1,    -1,    -1,    -1,  1159,  1160,  1161,  1162,  1163,    -1,
    1165,    -1,  1167,  1168,    -1,  1170,  1171,    -1,    -1,  1174,
    1175,  1176,    -1,    -1,    -1,    -1,  1181,    -1,    -1,    -1,
     139,   140,   141,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    -1,    -1,    12,    13,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,   210,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    -1,    83,    -1,    -1,    86,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,   116,    -1,    -1,   119,
      -1,    -1,  1307,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    91,  1320,    -1,    -1,    -1,    96,
      97,    -1,    99,   100,   101,    -1,    -1,    -1,   105,  1334,
      -1,    -1,    -1,    -1,  1339,    -1,    -1,   958,   959,    -1,
      -1,    -1,   162,   964,   965,    -1,   166,    -1,    -1,    -1,
     170,   171,   172,   173,   174,     8,    -1,    -1,   178,    -1,
      -1,    -1,   139,   140,   141,    -1,  1371,  1372,    -1,    -1,
    1375,  1376,   192,   193,     8,    -1,    -1,   197,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    -1,    -1,   207,    -1,   209,
     210,    -1,    -1,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,     3,     4,    -1,
      -1,   201,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    80,    -1,    -1,    83,    -1,    -1,
      86,    -1,    88,    -1,    -1,    -1,    -1,    -1,  1503,  1504,
      -1,    -1,  1507,  1508,   100,    -1,    -1,    -1,  1513,  1514,
      -1,   107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,  1142,  1143,   119,    -1,    -1,  1147,  1148,    -1,    -1,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,    -1,   162,   201,    -1,    -1,
     166,    -1,    -1,    -1,   170,   171,   172,   173,   174,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,
      -1,   207,    -1,    -1,   210,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    61,    62,    63,    -1,    -1,    66,    -1,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,
      -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,    -1,
      -1,   119,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,    -1,
      -1,    -1,   170,   171,   172,   173,   174,   175,    -1,   177,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,   197,
      -1,    -1,    -1,    -1,   202,    -1,     3,     4,     5,   207,
      -1,   209,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,    66,
      -1,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    76,
      77,    -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    86,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
      -1,    -1,   119,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,
     210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
      -1,    -1,    -1,   170,   171,   172,   173,   174,   175,    -1,
     177,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,   202,    -1,     3,     4,     5,
     207,    -1,   209,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,
      66,    -1,    68,    69,    70,    -1,     3,     4,     5,    -1,
      76,    77,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,    66,
      -1,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
     166,    -1,    -1,    -1,   170,   171,   172,   173,   174,   175,
      -1,   177,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,
      -1,   207,    -1,   209,    -1,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,   162,   163,   164,   165,   166,
     208,    -1,   210,   170,   171,   172,   173,   174,   175,    -1,
     177,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,   202,    -1,     3,     4,     5,
     207,    -1,   209,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    12,    13,    -1,    61,    62,    63,    -1,    -1,
      66,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      76,    77,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    91,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
     100,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
     166,    -1,    -1,    -1,   170,   171,   172,   173,   174,   175,
      -1,   177,   178,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,   202,    -1,     3,     4,
       5,   207,    -1,   209,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    -1,    -1,
     210,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    83,    -1,
      -1,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    -1,     4,     5,    -1,
      -1,    -1,   107,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    62,    63,   162,    -1,    66,
      -1,   166,    -1,    -1,    -1,   170,   171,   172,   173,   174,
      77,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,    -1,
      -1,    -1,   197,    -1,    -1,    -1,    -1,   202,    -1,     3,
       4,    -1,   207,    -1,   209,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    57,    -1,    -1,   163,   164,   165,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    -1,   175,    -1,
     177,   178,    76,    -1,    -1,    -1,    80,    -1,    -1,    83,
      -1,    -1,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,     4,     5,
      -1,    -1,    -1,   107,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,   116,    -1,    -1,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    62,    63,   162,    -1,
      66,    -1,   166,    -1,    -1,    -1,   170,   171,   172,   173,
     174,    77,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
      -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,   202,    -1,
       3,     4,    -1,   207,    -1,   209,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    57,    -1,    -1,   163,   164,   165,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,   175,
      -1,   177,   178,    76,    -1,    -1,    -1,    80,    -1,    -1,
      83,     4,     5,    86,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,   116,    -1,    -1,   119,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    62,
      63,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,   162,
      -1,    -1,    -1,   166,    -1,    -1,    -1,   170,   171,   172,
     173,   174,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     193,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,   202,
      -1,     3,     4,    -1,   207,    -1,   209,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
     163,   164,   165,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    -1,   175,    -1,   177,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,
      -1,    83,    -1,     5,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,   116,    -1,    -1,   119,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,   166,    -1,    -1,    -1,   170,   171,
     172,   173,   174,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,
     202,    -1,     3,     4,    -1,   207,    -1,   209,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,   163,   164,   165,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    -1,   175,    -1,   177,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,
      -1,    -1,    83,    -1,    -1,    86,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,    -1,    -1,   119,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,   170,
     171,   172,   173,   174,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   193,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,   202,    -1,     3,     4,    -1,   207,    -1,   209,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    -1,    83,    -1,    -1,    86,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,   116,    -1,    -1,   119,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   171,   172,   173,   174,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   192,   193,    -1,    -1,    -1,   197,    -1,    -1,
      -1,    -1,   202,    -1,     3,     4,    -1,   207,    -1,   209,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,   110,   111,    -1,    -1,    -1,    -1,   116,    -1,    -1,
     119,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,    -1,    -1,    -1,   166,    -1,    -1,
      -1,   170,   171,   172,   173,   174,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   193,    -1,    -1,    -1,   197,    -1,
      -1,    -1,    -1,   202,    -1,     3,     4,    -1,   207,    -1,
     209,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,    -1,
      -1,   119,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,   166,    -1,
      -1,    -1,   170,   171,   172,   173,   174,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,   197,
      -1,    -1,    -1,    -1,   202,    -1,     3,     4,    -1,   207,
      -1,   209,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    86,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
      -1,    -1,   119,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,   166,
      -1,    -1,    -1,   170,   171,   172,   173,   174,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,   202,    -1,     3,     4,    -1,
     207,    -1,   209,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    80,    -1,    -1,    83,    -1,    -1,
      86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,    -1,    -1,   119,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,
     166,    -1,    -1,    -1,   170,   171,   172,   173,   174,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,   202,    -1,     3,     4,
      -1,   207,    -1,   209,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    83,    -1,
      -1,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,    -1,    -1,   119,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,
      -1,   166,    -1,    -1,    -1,   170,   171,   172,   173,   174,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,    -1,
      -1,    -1,   197,    -1,    -1,    -1,    -1,   202,    -1,     3,
       4,    -1,   207,    -1,   209,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    68,    69,    70,    -1,     9,    10,
      11,    -1,    76,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    76,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,   162,    -1,
      -1,    -1,   166,   210,    -1,    -1,   170,   171,   172,   173,
     174,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
      -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,   202,    -1,
      -1,    -1,    -1,   207,    -1,   209,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,   162,    -1,    -1,   201,   166,    -1,    -1,   205,   170,
     171,   172,   173,   174,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   193,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,   202,    -1,     3,     4,     5,   207,    -1,   209,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    61,    62,    63,    -1,    -1,    66,    -1,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    76,    77,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   210,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   210,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   210,   162,   163,   164,   165,   166,    -1,    -1,    -1,
     170,   171,   172,   173,   174,   175,    -1,   177,   178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   192,   193,    -1,    -1,    -1,   197,     3,     4,
      -1,    -1,   202,    -1,     9,    10,    11,   207,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    83,    -1,
      -1,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,    -1,    -1,   119,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,
      -1,   166,    -1,    -1,    -1,   170,   171,   172,   173,   174,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,    -1,
      -1,    -1,   197,     3,     4,    -1,    -1,   202,    -1,     9,
      10,    11,   207,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    68,    69,
      70,    -1,     9,    10,    11,    -1,    76,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    76,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,   162,    -1,    -1,    -1,   166,   210,    -1,    -1,
     170,   171,   172,   173,   174,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   192,   193,    -1,    -1,    -1,   197,    -1,    -1,
      -1,    -1,   202,    -1,    -1,   205,    -1,   207,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,   162,   201,    -1,    -1,   166,
     205,    -1,    -1,   170,   171,   172,   173,   174,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,
     197,     3,     4,    -1,    -1,   202,   203,     9,    10,    11,
     207,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,     3,
       4,    -1,     6,    -1,    76,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    76,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
     162,   201,    -1,    -1,   166,   205,    -1,    -1,   170,   171,
     172,   173,   174,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,
     202,    -1,    -1,   205,    -1,   207,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,   162,    -1,
      -1,    -1,   166,   210,    -1,    -1,   170,   171,   172,   173,
     174,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
      -1,    -1,    -1,   197,     3,     4,    -1,    -1,   202,    -1,
       9,    10,    11,   207,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    76,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   210,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,    -1,    -1,    -1,   166,    -1,    -1,
      -1,   170,   171,   172,   173,   174,    -1,    -1,    -1,   178,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   193,    -1,    -1,    -1,   197,    -1,
      58,    59,    60,   202,    -1,    -1,    64,    65,   207,    67,
      -1,    -1,    -1,    71,    72,    -1,    74,    75,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,    -1,    -1,   125,   126,   127,
       4,    -1,    -1,    -1,    -1,   133,    -1,    -1,    12,    13,
     138,   139,   140,   141,    -1,    -1,   144,    -1,   146,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    38,    39,    -1,    -1,    -1,   167,
     168,   169,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
     178,    -1,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,
      64,    65,    -1,    67,    -1,    -1,    -1,    71,    72,    -1,
      74,    75,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,   133,
      -1,    -1,    -1,    -1,   138,   139,   140,   141,    -1,    -1,
     144,    -1,   146,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,    -1,   167,   168,   169,    -1,    -1,    -1,    -1,
      -1,    -1,   176,    -1,   178,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     210,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     210,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     210,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   209,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   209,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,   203,    -1,   205,    -1,    -1,   208,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
     203,    -1,    -1,    -1,    -1,   208,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,   208,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,   208,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,   208,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,   208,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,   208,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,   208,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,   208,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,   208,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,   208,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,   205,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,   205,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
     205,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,   205,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,   205,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,   205,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,   205,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,   205,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,   205,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      -1,   205,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,   205,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,   205,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
     205,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,   205,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,   203,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,   203,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,   203,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,   201,    -1,   203,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,   203,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,   203,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
     203,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,
      -1,   203,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,   203,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,   203,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,   203,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,   203,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,   203,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,   201,    -1,   203,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,   203,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,   203,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
     203,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,
      -1,   203,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,   203,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,   203,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,   203,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,   203,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,   203,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,   201,    -1,   203,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,   203,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,   203,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
     203,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,
      -1,   203,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,   203,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,   203,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,   203,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,   203,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,    -1,   203,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,   201,    -1,   203,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,   203,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,   203,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
     203,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,
      -1,   203,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,   203,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,   203,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,   203,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,   203
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   213,   214,     6,     0,     4,    12,    13,    38,
      39,    58,    59,    60,    64,    65,    67,    71,    72,    74,
      75,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   114,   115,   116,   117,   118,   119,
     120,   121,   125,   126,   127,   133,   138,   139,   140,   141,
     144,   146,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   167,   168,   169,   176,
     178,   215,   217,   218,   238,   257,   258,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   290,   291,   292,   293,
     311,   312,     3,     4,     5,     9,    10,    11,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    61,
      62,    63,    66,    68,    69,    70,    76,    77,   155,   162,
     163,   164,   165,   166,   170,   171,   172,   173,   174,   175,
     177,   192,   193,   197,   202,   204,   206,   207,   209,   211,
     236,   294,   295,   307,   308,   311,   312,    13,    86,   202,
     202,     6,   209,     6,     6,     6,     6,   202,     6,     6,
     204,   204,   202,   204,   236,   236,   202,   209,   202,   202,
       4,   202,   209,   202,   202,     4,   209,   202,   202,    90,
      86,    86,     6,   209,    80,    83,    86,    86,    86,    83,
      86,    88,    88,    80,    83,    86,    88,    83,    86,    88,
      83,    86,   202,    83,   144,   160,   161,   209,   192,   193,
     202,   209,   297,   298,   297,   209,    80,    83,    86,   209,
     297,     4,    80,    84,    96,    86,    88,    86,    83,     4,
     155,   209,   311,   312,     4,     6,    80,    83,    86,    83,
      86,     4,     4,     4,     4,     5,    37,    80,    83,    86,
      88,   100,   193,   202,   209,   258,   269,   294,   300,   301,
     302,   311,   312,     4,   202,   202,   202,     4,   209,   304,
     312,     4,   202,   202,   202,     6,     6,   204,     4,   308,
     312,   202,     4,   308,     5,   209,     5,   209,     4,   294,
     311,   204,     6,   202,   209,   202,   204,   211,   236,     7,
     179,   180,   181,   182,   199,   200,   234,   235,     4,   202,
     204,   206,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   202,   202,   202,
     236,   236,   236,   236,   202,   236,   236,   236,   236,   236,
     236,   202,   236,   236,   236,     7,   202,   202,   202,   236,
     236,   202,   202,   204,   294,   294,   294,   203,   294,   205,
     294,     4,   144,   145,   312,     4,   258,   259,   260,   209,
     209,     6,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   201,   209,     6,   202,
     204,   235,     6,   294,     4,   307,   308,   311,   312,   307,
     294,   307,   310,   240,   245,   308,   312,   294,   193,   294,
     302,   303,   294,   294,   202,   294,   303,   294,   294,   202,
     303,   294,   294,   300,   202,   209,   303,   301,   301,   301,
     202,   202,   301,   301,   301,   202,   202,   202,   202,   202,
     202,   300,   202,   300,   202,   300,   209,   209,   294,     4,
     300,   304,   209,   209,   297,   297,   297,   294,   294,   192,
     193,   209,   209,   297,   209,   209,   209,   192,   193,   202,
     260,   297,   209,   202,   209,   202,   202,   202,   301,   301,
     300,   202,     4,   204,   204,   260,     6,     6,   209,   209,
     209,   301,   301,   204,   204,   204,   202,   204,   206,   236,
     202,   204,     5,   147,   209,     5,   147,     5,   147,     5,
     147,    80,    83,    86,    88,   209,   294,   302,   294,   210,
     303,     8,   194,     6,   202,   204,   236,     6,   294,   294,
     294,   206,   294,   209,   147,   294,   294,   294,   294,     6,
       6,   209,     6,   260,     6,   260,   202,   204,   209,   202,
     204,   307,   300,   300,   203,   294,   205,   294,   209,   209,
     308,   300,     6,   204,   294,   294,     4,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   310,
     307,   310,   307,   307,   307,   307,   307,   307,   307,   300,
     307,   307,   294,   307,   307,   307,   310,   307,   294,   308,
     294,   307,   307,   307,   307,   307,   312,   308,   312,     7,
     182,   234,   203,     7,   182,   234,   205,     7,   234,   235,
     206,     7,   236,   210,    80,    83,    86,    88,   257,   294,
     303,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   219,   294,   294,     6,
     202,   204,   206,   203,   208,   202,   204,   203,   208,   208,
     203,   208,   205,   208,   239,   205,   239,   208,   208,   203,
     194,   208,   210,   203,   203,   294,   203,   210,   203,   203,
     294,   210,   203,   203,     7,   294,   294,   210,     6,     6,
       6,   294,   294,     7,     7,   287,   287,   294,   251,   294,
     308,   252,   294,   308,   253,   294,   308,   254,   294,   308,
     294,     6,   294,     6,   294,     6,   303,   303,   209,   203,
       6,   209,   260,   260,   208,   208,   208,   297,   297,   259,
     259,   208,   294,   294,   294,   294,   273,   208,   260,   294,
     294,   294,   294,   294,     7,   288,     6,     7,   294,     6,
     294,   294,   210,   303,   303,   303,     6,     6,   294,   294,
     294,   294,   294,     4,   203,   205,   209,   237,   209,   294,
     302,   209,   302,   312,    58,   294,    58,    58,    58,     5,
     209,     5,   209,     5,   209,     5,   209,   303,   203,   210,
     294,   209,   294,   302,   294,   294,   209,   237,   203,   203,
     203,   144,   208,   260,   209,     8,   203,   203,   205,   303,
     210,   210,   260,   205,   203,   208,   210,     7,   182,   234,
     203,     7,   182,   234,   205,   294,   303,     6,     6,   294,
     203,   205,   235,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   208,   237,   237,   237,   237,   237,
     237,   237,   208,   208,   208,   237,   208,   237,   237,   203,
     203,   208,   237,   237,   208,   237,   208,   208,   208,   208,
     237,   237,   237,   203,   237,   296,   309,     6,   208,   208,
     203,   208,   237,   208,   237,   203,   203,   205,    40,    40,
     300,     7,   234,   235,    40,    40,   300,   206,   234,   235,
     308,   294,     6,     4,     4,   209,   305,   237,   209,   209,
     209,   209,   210,   210,     8,     4,   134,   135,   136,   137,
     210,   222,   226,   229,   231,   232,   203,   205,   294,   294,
       4,     6,   189,   216,   303,   294,   294,     6,   303,   294,
       6,   307,     6,   312,     6,   307,   294,   308,     7,   294,
     302,   147,     7,     7,   203,     7,   147,     7,     7,   203,
     147,     7,     7,   294,   203,   210,   209,   203,   203,   294,
     300,     4,   286,     6,   203,   203,   208,   203,   208,   203,
     208,   203,   208,   203,   203,   203,   210,   210,   303,   206,
     260,   210,   210,   297,   294,   294,   210,   210,   294,   297,
     208,   208,   208,   103,   114,   122,   123,   124,   128,   129,
     130,   131,   283,   284,   297,   210,   270,   203,   210,   203,
     203,   203,   294,     6,   294,   203,   205,   205,   210,   210,
     210,   205,   205,   208,   203,   205,   303,   303,   203,   303,
     205,   205,   209,   210,   209,   209,   209,   303,   303,   303,
     303,   210,     8,   303,   203,   205,   303,     7,     7,     7,
     206,   294,   210,   294,   294,     7,   206,   210,   210,   209,
     300,     6,    40,    40,   300,   234,   235,    40,    40,   300,
     234,   235,   210,   210,   205,   235,   206,   235,   307,   294,
     294,   294,   294,   303,   307,   294,   300,   307,   307,   307,
     247,   249,   294,   307,   307,   294,   236,   236,     6,   294,
       6,   236,   236,     6,     4,   144,   145,   294,     6,     6,
       6,     7,   204,   304,   306,     6,   303,   303,   303,   303,
     237,   294,   223,   202,   202,   209,   233,     6,   235,   235,
     203,   205,   189,   307,   203,   203,   205,   203,   208,     7,
     202,   204,   237,   237,   297,    86,    88,   300,   300,     7,
     300,    86,    88,   300,   300,     7,    88,   300,   300,     6,
       7,     7,   303,     7,     7,   103,   285,     6,     7,   234,
     294,   234,   294,   234,   294,   234,   294,     7,     7,     7,
       7,     7,   210,     4,   210,   208,   208,   208,   210,   210,
     297,   297,   297,     4,     6,   294,   209,     6,   202,     6,
     132,     6,   132,     6,   132,     6,   132,   210,   284,   208,
     283,     7,     6,     7,     7,     7,     6,   209,     6,     6,
       6,    86,     7,     6,     6,   294,   206,   210,   210,   210,
     294,   294,   294,   294,   210,   210,   210,   210,   294,   210,
     210,   300,   300,   300,     4,   208,     8,     8,   203,     4,
       4,   208,   300,   210,   236,   236,     6,   294,     6,   236,
     236,     6,   294,     6,   237,     6,     4,     6,   237,   237,
     237,   237,   237,   208,   208,   237,   203,   237,   237,   208,
     208,   237,   248,   208,   237,   250,   203,   203,   237,   237,
     237,   310,   310,     6,   237,   310,   310,     7,   234,   235,
     206,     7,     6,   304,   294,   208,   210,   210,   210,   210,
     210,   234,   202,   294,   294,   299,   300,   209,   206,     6,
       6,   216,     6,   294,   209,   294,   308,   203,   205,     6,
       6,     6,   209,   209,    96,   256,   256,   300,     6,   209,
     209,     6,     6,   300,   209,     6,     6,     5,   300,   210,
     300,   300,     4,     6,   300,   300,   300,   300,   300,   300,
     300,   300,   209,   209,     7,     6,     7,   294,   294,   294,
     209,   209,   208,   210,   208,   210,   208,   210,   204,     6,
     294,   300,   294,     6,     6,     6,     6,   294,   297,   210,
       5,   209,   300,   209,   209,   209,   300,   303,   209,   294,
     205,     4,   237,   203,   205,   208,   208,   208,   208,   237,
       6,     6,   143,   294,   294,   294,     6,     6,     7,   308,
     208,     6,   237,   310,   310,     6,   237,   310,   310,     6,
     234,   235,   307,   294,   307,     4,     4,   159,     6,   237,
     237,     6,   237,   237,   308,   294,     6,     4,   305,     6,
     205,   304,     6,     6,     6,     6,   300,   220,   294,   208,
     208,   208,   210,   221,   294,     4,   307,   208,   300,   308,
       7,     7,   294,   294,   297,     6,     6,     6,   294,   294,
       6,   294,     5,     6,   209,     6,   147,   255,   294,     6,
       6,     6,     6,     6,     6,     4,     6,     6,   303,   303,
     294,   294,   308,   210,   203,   208,   210,   259,   259,   297,
       6,   274,   297,     6,   275,   297,     6,   276,   294,   210,
     208,   203,   210,   208,     6,   193,   297,     6,   299,   297,
     297,     6,   210,   294,     6,     6,   294,   294,   294,   294,
     300,   208,   210,     8,   210,   203,   209,   294,   308,   208,
     300,     6,   237,   237,     6,   237,   237,   300,   203,   237,
     237,   209,   300,   308,   209,   294,   308,   308,     6,     6,
       6,     6,     6,     6,     7,     6,   206,     6,   203,   208,
     294,   294,   300,   209,   208,   210,     6,   294,   241,   244,
     209,   209,   210,   210,   210,   210,   210,     5,   299,    84,
       6,   209,   210,   210,   209,     6,     6,   209,   294,   210,
     210,   208,   209,   208,   209,   208,   209,   205,     6,   300,
       7,   209,   294,   208,   210,   208,   208,     6,   210,   208,
     208,   208,   208,   142,   294,   294,   303,     6,     6,   308,
     210,     6,     6,     6,     6,     6,   246,   294,   302,   310,
     304,   145,   224,   294,   208,   208,   299,   294,     6,   208,
     247,   249,   300,   300,     6,     6,     6,     6,     6,     6,
     210,   209,   299,   107,   108,   113,   289,   107,   108,   289,
     303,   259,   208,   210,   294,   297,   283,   294,   297,   283,
     294,   297,   283,     6,   208,   210,   300,   260,   210,   297,
       6,   303,   297,   294,   294,   294,   294,   294,   210,   210,
     210,   203,     6,   208,   210,     7,     7,   210,     6,   209,
     294,   294,   210,   294,   210,   210,   243,   242,   209,   294,
     210,   209,   297,   300,     6,   209,   297,     6,   210,   210,
     294,   210,   208,   210,   210,   208,   210,   210,   208,   210,
     300,     6,   103,   210,   271,   209,   208,   210,   208,   208,
     208,   208,   208,     6,     6,     6,   294,   308,   312,   221,
     203,   208,     6,   209,   208,   247,   247,   294,   210,     6,
     297,     6,   297,     6,     6,   210,     6,   277,   294,     6,
       6,   278,   294,     6,     6,   279,   294,     6,   210,   294,
     283,   260,   303,     6,   297,   303,   294,   294,   294,   294,
       7,   202,   210,   227,   294,   299,   294,   210,   210,   208,
     208,   208,   209,   210,   209,   210,   209,   210,     6,     6,
     210,   210,   272,   210,   208,   210,   208,   208,   208,   208,
     308,   203,     6,   209,   203,   210,   210,   294,   297,   297,
     283,     6,   280,   283,     6,   281,   283,     6,   282,   283,
       6,   303,     6,   294,   294,   294,   294,   225,   307,   230,
     209,     6,   210,   208,   208,   210,   209,   210,   209,   210,
     209,   210,   210,   208,   208,   208,   208,   208,   210,   209,
     299,     6,   294,   294,     6,   283,     6,   283,     6,   283,
       6,   294,   294,   294,   294,   307,     6,   228,   307,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   208,
     210,     6,     6,     6,     6,     6,     6,   307,     6
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
#line 5969 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 507:
#line 5974 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 508:
#line 5978 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 509:
#line 5982 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 510:
#line 5994 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 511:
#line 5998 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 512:
#line 6010 "Gmsh.y"
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

  case 513:
#line 6027 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 514:
#line 6037 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 515:
#line 6041 "Gmsh.y"
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

  case 516:
#line 6056 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 517:
#line 6061 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 518:
#line 6068 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 519:
#line 6072 "Gmsh.y"
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

  case 520:
#line 6085 "Gmsh.y"
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
#line 6099 "Gmsh.y"
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

  case 522:
#line 6113 "Gmsh.y"
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
#line 6127 "Gmsh.y"
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
#line 6141 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 525:
#line 6149 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 526:
#line 6160 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 527:
#line 6164 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 528:
#line 6168 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 529:
#line 6176 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 530:
#line 6182 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 531:
#line 6188 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 532:
#line 6196 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 533:
#line 6204 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 534:
#line 6211 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 535:
#line 6219 "Gmsh.y"
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

  case 536:
#line 6234 "Gmsh.y"
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

  case 537:
#line 6248 "Gmsh.y"
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

  case 538:
#line 6262 "Gmsh.y"
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
        if(i != List_Nbr((yyvsp[(3) - (4)].l)) - 1) strcat((yyval.c), "\n");
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 540:
#line 6290 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 541:
#line 6299 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 542:
#line 6308 "Gmsh.y"
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

  case 543:
#line 6318 "Gmsh.y"
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

  case 544:
#line 6329 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 545:
#line 6337 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 546:
#line 6345 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 547:
#line 6349 "Gmsh.y"
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

  case 548:
#line 6368 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 549:
#line 6375 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 550:
#line 6381 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 551:
#line 6388 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 552:
#line 6395 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 553:
#line 6397 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 554:
#line 6408 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 555:
#line 6413 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 556:
#line 6419 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 557:
#line 6428 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 558:
#line 6441 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 559:
#line 6444 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 560:
#line 6448 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13146 "Gmsh.tab.cpp"
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


#line 6451 "Gmsh.y"


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

