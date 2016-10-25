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
     tFind = 303,
     tStrFind = 304,
     tStrCmp = 305,
     tStrChoice = 306,
     tUpperCase = 307,
     tLowerCase = 308,
     tLowerCaseIn = 309,
     tTextAttributes = 310,
     tBoundingBox = 311,
     tDraw = 312,
     tSetChanged = 313,
     tToday = 314,
     tFixRelativePath = 315,
     tCurrentDirectory = 316,
     tSyncModel = 317,
     tNewModel = 318,
     tOnelabAction = 319,
     tOnelabRun = 320,
     tCpu = 321,
     tMemory = 322,
     tTotalMemory = 323,
     tCreateTopology = 324,
     tCreateTopologyNoHoles = 325,
     tDistanceFunction = 326,
     tDefineConstant = 327,
     tUndefineConstant = 328,
     tDefineNumber = 329,
     tDefineString = 330,
     tSetNumber = 331,
     tSetString = 332,
     tPoint = 333,
     tCircle = 334,
     tEllipse = 335,
     tLine = 336,
     tSphere = 337,
     tPolarSphere = 338,
     tSurface = 339,
     tSpline = 340,
     tVolume = 341,
     tCharacteristic = 342,
     tLength = 343,
     tParametric = 344,
     tElliptic = 345,
     tRefineMesh = 346,
     tAdaptMesh = 347,
     tRelocateMesh = 348,
     tPlane = 349,
     tRuled = 350,
     tTransfinite = 351,
     tComplex = 352,
     tPhysical = 353,
     tCompound = 354,
     tPeriodic = 355,
     tUsing = 356,
     tPlugin = 357,
     tDegenerated = 358,
     tRecursive = 359,
     tRotate = 360,
     tTranslate = 361,
     tSymmetry = 362,
     tDilate = 363,
     tExtrude = 364,
     tLevelset = 365,
     tAffine = 366,
     tRecombine = 367,
     tSmoother = 368,
     tSplit = 369,
     tDelete = 370,
     tCoherence = 371,
     tIntersect = 372,
     tMeshAlgorithm = 373,
     tReverse = 374,
     tLayers = 375,
     tScaleLast = 376,
     tHole = 377,
     tAlias = 378,
     tAliasWithOptions = 379,
     tCopyOptions = 380,
     tQuadTriAddVerts = 381,
     tQuadTriNoNewVerts = 382,
     tQuadTriSngl = 383,
     tQuadTriDbl = 384,
     tRecombLaterals = 385,
     tTransfQuadTri = 386,
     tText2D = 387,
     tText3D = 388,
     tInterpolationScheme = 389,
     tTime = 390,
     tCombine = 391,
     tBSpline = 392,
     tBezier = 393,
     tNurbs = 394,
     tNurbsOrder = 395,
     tNurbsKnots = 396,
     tColor = 397,
     tColorTable = 398,
     tFor = 399,
     tIn = 400,
     tEndFor = 401,
     tIf = 402,
     tElseIf = 403,
     tElse = 404,
     tEndIf = 405,
     tExit = 406,
     tAbort = 407,
     tField = 408,
     tReturn = 409,
     tCall = 410,
     tSlide = 411,
     tMacro = 412,
     tShow = 413,
     tHide = 414,
     tGetValue = 415,
     tGetStringValue = 416,
     tGetEnv = 417,
     tGetString = 418,
     tGetNumber = 419,
     tHomology = 420,
     tCohomology = 421,
     tBetti = 422,
     tExists = 423,
     tFileExists = 424,
     tGMSH_MAJOR_VERSION = 425,
     tGMSH_MINOR_VERSION = 426,
     tGMSH_PATCH_VERSION = 427,
     tGmshExecutableName = 428,
     tSetPartition = 429,
     tNameToString = 430,
     tStringToName = 431,
     tAFFECTDIVIDE = 432,
     tAFFECTTIMES = 433,
     tAFFECTMINUS = 434,
     tAFFECTPLUS = 435,
     tOR = 436,
     tAND = 437,
     tNOTEQUAL = 438,
     tEQUAL = 439,
     tGREATEROREQUAL = 440,
     tLESSOREQUAL = 441,
     UNARYPREC = 442,
     tMINUSMINUS = 443,
     tPLUSPLUS = 444
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
#define tFind 303
#define tStrFind 304
#define tStrCmp 305
#define tStrChoice 306
#define tUpperCase 307
#define tLowerCase 308
#define tLowerCaseIn 309
#define tTextAttributes 310
#define tBoundingBox 311
#define tDraw 312
#define tSetChanged 313
#define tToday 314
#define tFixRelativePath 315
#define tCurrentDirectory 316
#define tSyncModel 317
#define tNewModel 318
#define tOnelabAction 319
#define tOnelabRun 320
#define tCpu 321
#define tMemory 322
#define tTotalMemory 323
#define tCreateTopology 324
#define tCreateTopologyNoHoles 325
#define tDistanceFunction 326
#define tDefineConstant 327
#define tUndefineConstant 328
#define tDefineNumber 329
#define tDefineString 330
#define tSetNumber 331
#define tSetString 332
#define tPoint 333
#define tCircle 334
#define tEllipse 335
#define tLine 336
#define tSphere 337
#define tPolarSphere 338
#define tSurface 339
#define tSpline 340
#define tVolume 341
#define tCharacteristic 342
#define tLength 343
#define tParametric 344
#define tElliptic 345
#define tRefineMesh 346
#define tAdaptMesh 347
#define tRelocateMesh 348
#define tPlane 349
#define tRuled 350
#define tTransfinite 351
#define tComplex 352
#define tPhysical 353
#define tCompound 354
#define tPeriodic 355
#define tUsing 356
#define tPlugin 357
#define tDegenerated 358
#define tRecursive 359
#define tRotate 360
#define tTranslate 361
#define tSymmetry 362
#define tDilate 363
#define tExtrude 364
#define tLevelset 365
#define tAffine 366
#define tRecombine 367
#define tSmoother 368
#define tSplit 369
#define tDelete 370
#define tCoherence 371
#define tIntersect 372
#define tMeshAlgorithm 373
#define tReverse 374
#define tLayers 375
#define tScaleLast 376
#define tHole 377
#define tAlias 378
#define tAliasWithOptions 379
#define tCopyOptions 380
#define tQuadTriAddVerts 381
#define tQuadTriNoNewVerts 382
#define tQuadTriSngl 383
#define tQuadTriDbl 384
#define tRecombLaterals 385
#define tTransfQuadTri 386
#define tText2D 387
#define tText3D 388
#define tInterpolationScheme 389
#define tTime 390
#define tCombine 391
#define tBSpline 392
#define tBezier 393
#define tNurbs 394
#define tNurbsOrder 395
#define tNurbsKnots 396
#define tColor 397
#define tColorTable 398
#define tFor 399
#define tIn 400
#define tEndFor 401
#define tIf 402
#define tElseIf 403
#define tElse 404
#define tEndIf 405
#define tExit 406
#define tAbort 407
#define tField 408
#define tReturn 409
#define tCall 410
#define tSlide 411
#define tMacro 412
#define tShow 413
#define tHide 414
#define tGetValue 415
#define tGetStringValue 416
#define tGetEnv 417
#define tGetString 418
#define tGetNumber 419
#define tHomology 420
#define tCohomology 421
#define tBetti 422
#define tExists 423
#define tFileExists 424
#define tGMSH_MAJOR_VERSION 425
#define tGMSH_MINOR_VERSION 426
#define tGMSH_PATCH_VERSION 427
#define tGmshExecutableName 428
#define tSetPartition 429
#define tNameToString 430
#define tStringToName 431
#define tAFFECTDIVIDE 432
#define tAFFECTTIMES 433
#define tAFFECTMINUS 434
#define tAFFECTPLUS 435
#define tOR 436
#define tAND 437
#define tNOTEQUAL 438
#define tEQUAL 439
#define tGREATEROREQUAL 440
#define tLESSOREQUAL 441
#define UNARYPREC 442
#define tMINUSMINUS 443
#define tPLUSPLUS 444




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
#line 606 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 619 "Gmsh.tab.cpp"

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
#define YYLAST   12519

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  210
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  557
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1996

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   444

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   195,     2,   205,     2,   194,     2,     2,
     200,   201,   192,   190,   206,   191,   204,   193,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     186,     2,   187,   181,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   202,     2,   203,   199,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   207,     2,   208,   209,     2,     2,     2,
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
     175,   176,   177,   178,   179,   180,   182,   183,   184,   185,
     188,   189,   196,   197,   198
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
    2674,  2681,  2688,  2695,  2700,  2702,  2705,  2708,  2712,  2716,
    2728,  2738,  2746,  2754,  2756,  2760,  2762,  2764,  2767,  2771,
    2776,  2782,  2784,  2786,  2789,  2793,  2797,  2803,  2808,  2811,
    2814,  2817,  2820,  2824,  2828,  2832,  2836,  2842,  2848,  2854,
    2860,  2877,  2894,  2911,  2928,  2930,  2932,  2936,  2940,  2945,
    2950,  2955,  2962,  2969,  2976,  2983,  2985,  2987,  2991,  2995,
    3005,  3013,  3015,  3021,  3025,  3032,  3034,  3038,  3040,  3042,
    3047,  3052,  3057,  3062,  3066,  3073,  3075,  3080,  3082,  3084,
    3086,  3091,  3098,  3103,  3110,  3115,  3120,  3125,  3134,  3139,
    3144,  3149,  3154,  3163,  3168,  3175,  3180,  3182,  3187,  3192,
    3193,  3200,  3202,  3206,  3212,  3218,  3220,  3222
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     211,     0,    -1,   212,    -1,     1,     6,    -1,    -1,   212,
     213,    -1,   216,    -1,   215,    -1,   236,    -1,   255,    -1,
     256,    -1,   260,    -1,   261,    -1,   262,    -1,   263,    -1,
     267,    -1,   288,    -1,   289,    -1,   266,    -1,   265,    -1,
     264,    -1,   259,    -1,   291,    -1,   187,    -1,   187,   187,
      -1,    38,   200,   305,   201,     6,    -1,    39,   200,   305,
     201,     6,    -1,    38,   200,   305,   201,   214,   305,     6,
      -1,    38,   200,   305,   206,   301,   201,     6,    -1,    39,
     200,   305,   206,   301,   201,     6,    -1,    38,   200,   305,
     206,   301,   201,   214,   305,     6,    -1,     4,   305,   207,
     217,   208,     6,    -1,   123,     4,   202,   292,   203,     6,
      -1,   124,     4,   202,   292,   203,     6,    -1,   125,     4,
     202,   292,   206,   292,   203,     6,    -1,    -1,   217,   220,
      -1,   217,   224,    -1,   217,   227,    -1,   217,   229,    -1,
     217,   230,    -1,   292,    -1,   218,   206,   292,    -1,   292,
      -1,   219,   206,   292,    -1,    -1,    -1,     4,   221,   200,
     218,   201,   222,   207,   219,   208,     6,    -1,   305,    -1,
     223,   206,   305,    -1,    -1,   132,   200,   292,   206,   292,
     206,   292,   201,   225,   207,   223,   208,     6,    -1,   305,
      -1,   226,   206,   305,    -1,    -1,   133,   200,   292,   206,
     292,   206,   292,   206,   292,   201,   228,   207,   226,   208,
       6,    -1,   134,   207,   297,   208,   207,   297,   208,     6,
      -1,   134,   207,   297,   208,   207,   297,   208,   207,   297,
     208,   207,   297,   208,     6,    -1,    -1,   135,   231,   207,
     219,   208,     6,    -1,     7,    -1,   180,    -1,   179,    -1,
     178,    -1,   177,    -1,   198,    -1,   197,    -1,   200,    -1,
     202,    -1,   201,    -1,   203,    -1,    72,   202,   238,   203,
       6,    -1,    73,   202,   243,   203,     6,    -1,    76,   234,
     306,   206,   292,   235,     6,    -1,    77,   234,   310,   206,
     306,   235,     6,    -1,   310,   232,   298,     6,    -1,   310,
     233,     6,    -1,     4,   202,   203,   232,   298,     6,    -1,
     309,   202,   203,   232,   298,     6,    -1,     4,   202,   292,
     203,   232,   292,     6,    -1,   309,   202,   292,   203,   232,
     292,     6,    -1,     4,   202,   292,   203,   233,     6,    -1,
     309,   202,   292,   203,   233,     6,    -1,     4,   234,   207,
     301,   208,   235,   232,   298,     6,    -1,   309,   234,   207,
     301,   208,   235,   232,   298,     6,    -1,     4,   200,   201,
     232,   298,     6,    -1,   309,   200,   201,   232,   298,     6,
      -1,     4,   200,   292,   201,   232,   292,     6,    -1,   309,
     200,   292,   201,   232,   292,     6,    -1,     4,   200,   292,
     201,   233,     6,    -1,   309,   200,   292,   201,   233,     6,
      -1,   310,     7,   306,     6,    -1,     4,   202,   203,     7,
      40,   234,   235,     6,    -1,   309,   202,   203,     7,    40,
     234,   235,     6,    -1,     4,   202,   203,     7,    40,   234,
     308,   235,     6,    -1,   309,   202,   203,     7,    40,   234,
     308,   235,     6,    -1,     4,   202,   203,   180,    40,   234,
     308,   235,     6,    -1,   309,   202,   203,   180,    40,   234,
     308,   235,     6,    -1,     4,   200,   201,     7,    40,   234,
     235,     6,    -1,   309,   200,   201,     7,    40,   234,   235,
       6,    -1,     4,   200,   201,     7,    40,   234,   308,   235,
       6,    -1,   309,   200,   201,     7,    40,   234,   308,   235,
       6,    -1,     4,   200,   201,   180,    40,   234,   308,   235,
       6,    -1,   309,   200,   201,   180,    40,   234,   308,   235,
       6,    -1,     4,   204,     4,     7,   306,     6,    -1,     4,
     202,   292,   203,   204,     4,     7,   306,     6,    -1,     4,
     204,     4,   232,   292,     6,    -1,     4,   202,   292,   203,
     204,     4,   232,   292,     6,    -1,     4,   204,     4,   233,
       6,    -1,     4,   202,   292,   203,   204,     4,   233,     6,
      -1,     4,   204,   142,   204,     4,     7,   302,     6,    -1,
       4,   202,   292,   203,   204,   142,   204,     4,     7,   302,
       6,    -1,     4,   204,   143,     7,   303,     6,    -1,     4,
     202,   292,   203,   204,   143,     7,   303,     6,    -1,     4,
     153,     7,   292,     6,    -1,   153,   202,   292,   203,     7,
       4,     6,    -1,   153,   202,   292,   203,   204,     4,     7,
     292,     6,    -1,   153,   202,   292,   203,   204,     4,     7,
     306,     6,    -1,   153,   202,   292,   203,   204,     4,     7,
     207,   301,   208,     6,    -1,   153,   202,   292,   203,   204,
       4,     6,    -1,   102,   200,     4,   201,   204,     4,     7,
     292,     6,    -1,   102,   200,     4,   201,   204,     4,     7,
     306,     6,    -1,    -1,   206,    -1,    -1,   238,   237,   310,
      -1,   238,   237,   310,     7,   292,    -1,    -1,   238,   237,
     310,     7,   207,   298,   239,   245,   208,    -1,    -1,   238,
     237,   310,   202,   203,     7,   207,   298,   240,   245,   208,
      -1,    -1,   238,   237,   310,   200,   201,     7,   207,   298,
     241,   245,   208,    -1,   238,   237,   310,     7,   306,    -1,
      -1,   238,   237,   310,     7,   207,   306,   242,   247,   208,
      -1,    -1,   243,   237,   305,    -1,   292,     7,   306,    -1,
     244,   206,   292,     7,   306,    -1,   300,     7,   310,   200,
     201,    -1,    -1,   245,   246,    -1,   206,     4,   298,    -1,
     206,     4,   207,   244,   208,    -1,   206,     4,   306,    -1,
      -1,   247,   248,    -1,   206,     4,   292,    -1,   206,     4,
     306,    -1,   206,   157,   306,    -1,   206,     4,   207,   308,
     208,    -1,   292,    -1,   306,    -1,   306,   206,   292,    -1,
     292,    -1,   306,    -1,   306,   206,   292,    -1,   292,    -1,
     306,    -1,   306,   206,   292,    -1,   292,    -1,   306,    -1,
     306,   206,   292,    -1,    -1,   145,    82,   207,   292,   208,
      -1,    -1,    94,   295,    -1,    78,   200,   292,   201,     7,
     295,     6,    -1,    98,    78,   200,   249,   201,   232,   298,
       6,    -1,    87,    88,   298,     7,   292,     6,    -1,    81,
     200,   292,   201,     7,   298,     6,    -1,   103,    81,   298,
       6,    -1,    85,   200,   292,   201,     7,   298,     6,    -1,
      79,   200,   292,   201,     7,   298,   254,     6,    -1,    80,
     200,   292,   201,     7,   298,   254,     6,    -1,   137,   200,
     292,   201,     7,   298,     6,    -1,   138,   200,   292,   201,
       7,   298,     6,    -1,   139,   200,   292,   201,     7,   298,
     141,   298,   140,   292,     6,    -1,    81,     4,   200,   292,
     201,     7,   298,     6,    -1,    99,    81,   298,     6,    -1,
      99,    81,   200,   292,   201,     7,   298,     6,    -1,    98,
      81,   200,   250,   201,   232,   298,     6,    -1,    94,    84,
     200,   292,   201,     7,   298,     6,    -1,    95,    84,   200,
     292,   201,     7,   298,   253,     6,    -1,    12,    13,     6,
      -1,    13,    84,   292,     6,    -1,    89,    84,   200,   292,
     201,     7,     5,     5,     5,     6,    -1,    82,   200,   292,
     201,     7,   298,     6,    -1,    83,   200,   292,   201,     7,
     298,     6,    -1,    84,     4,   200,   292,   201,     7,   298,
       6,    -1,    99,    84,   298,     6,    -1,    99,    84,   200,
     292,   201,     7,   298,     6,    -1,    99,    84,   200,   292,
     201,     7,   298,     4,   207,   297,   208,     6,    -1,    98,
      84,   200,   251,   201,   232,   298,     6,    -1,    97,    86,
     200,   292,   201,     7,   298,     6,    -1,    86,   200,   292,
     201,     7,   298,     6,    -1,    99,    86,   298,     6,    -1,
      99,    86,   200,   292,   201,     7,   298,     6,    -1,    98,
      86,   200,   252,   201,   232,   298,     6,    -1,   106,   295,
     207,   257,   208,    -1,   105,   207,   295,   206,   295,   206,
     292,   208,   207,   257,   208,    -1,   107,   295,   207,   257,
     208,    -1,   108,   207,   295,   206,   292,   208,   207,   257,
     208,    -1,   108,   207,   295,   206,   295,   208,   207,   257,
     208,    -1,     4,   207,   257,   208,    -1,   117,    81,   207,
     301,   208,    84,   207,   292,   208,    -1,   114,    81,   200,
     292,   201,   207,   301,   208,     6,    -1,   258,    -1,   256,
      -1,    -1,   258,   255,    -1,   258,    78,   207,   301,   208,
       6,    -1,   258,    81,   207,   301,   208,     6,    -1,   258,
      84,   207,   301,   208,     6,    -1,   258,    86,   207,   301,
     208,     6,    -1,   110,    94,   200,   292,   201,     7,   298,
       6,    -1,   110,    78,   200,   292,   201,     7,   207,   297,
     208,     6,    -1,   110,    94,   200,   292,   201,     7,   207,
     295,   206,   295,   206,   301,   208,     6,    -1,   110,    94,
     200,   292,   201,     7,   207,   295,   206,   295,   206,   295,
     206,   301,   208,     6,    -1,   110,    82,   200,   292,   201,
       7,   207,   295,   206,   301,   208,     6,    -1,   110,     4,
     200,   292,   201,     7,   298,     6,    -1,   110,     4,   200,
     292,   201,     7,     5,     6,    -1,   110,     4,   207,   292,
     208,     6,    -1,   110,     4,   200,   292,   201,     7,   207,
     295,   206,   295,   206,   301,   208,     6,    -1,   115,   207,
     258,   208,    -1,   115,   153,   202,   292,   203,     6,    -1,
     115,     4,   202,   292,   203,     6,    -1,   115,   310,     6,
      -1,   115,     4,     4,     6,    -1,   142,   302,   207,   258,
     208,    -1,   104,   142,   302,   207,   258,   208,    -1,   174,
     292,   207,   258,   208,    -1,   158,     5,     6,    -1,   159,
       5,     6,    -1,   158,   207,   258,   208,    -1,   104,   158,
     207,   258,   208,    -1,   159,   207,   258,   208,    -1,   104,
     159,   207,   258,   208,    -1,     4,   306,     6,    -1,    65,
     200,   308,   201,     6,    -1,     4,     4,   202,   292,   203,
     305,     6,    -1,     4,     4,     4,   202,   292,   203,     6,
      -1,     4,   292,     6,    -1,   102,   200,     4,   201,   204,
       4,     6,    -1,   136,     4,     6,    -1,   151,     6,    -1,
     152,     6,    -1,    62,     6,    -1,    63,     6,    -1,    56,
       6,    -1,    56,   207,   292,   206,   292,   206,   292,   206,
     292,   206,   292,   206,   292,   208,     6,    -1,    57,     6,
      -1,    58,     6,    -1,    69,     6,    -1,    70,     6,    -1,
      91,     6,    -1,    92,   207,   301,   208,   207,   301,   208,
     207,   297,   208,   207,   292,   206,   292,   208,     6,    -1,
     156,   200,   207,   301,   208,   206,   306,   206,   306,   201,
       6,    -1,   144,   200,   292,     8,   292,   201,    -1,   144,
     200,   292,     8,   292,     8,   292,   201,    -1,   144,     4,
     145,   207,   292,     8,   292,   208,    -1,   144,     4,   145,
     207,   292,     8,   292,     8,   292,   208,    -1,   146,    -1,
     157,     4,    -1,   157,   306,    -1,   154,    -1,   155,   310,
       6,    -1,   155,   306,     6,    -1,   147,   200,   292,   201,
      -1,   148,   200,   292,   201,    -1,   149,    -1,   150,    -1,
     109,   295,   207,   258,   208,    -1,   109,   207,   295,   206,
     295,   206,   292,   208,   207,   258,   208,    -1,   109,   207,
     295,   206,   295,   206,   295,   206,   292,   208,   207,   258,
     208,    -1,    -1,   109,   295,   207,   258,   268,   281,   208,
      -1,    -1,   109,   207,   295,   206,   295,   206,   292,   208,
     207,   258,   269,   281,   208,    -1,    -1,   109,   207,   295,
     206,   295,   206,   295,   206,   292,   208,   207,   258,   270,
     281,   208,    -1,    -1,   109,   207,   258,   271,   281,   208,
      -1,   109,    78,   207,   292,   206,   295,   208,     6,    -1,
     109,    81,   207,   292,   206,   295,   208,     6,    -1,   109,
      84,   207,   292,   206,   295,   208,     6,    -1,   109,    78,
     207,   292,   206,   295,   206,   295,   206,   292,   208,     6,
      -1,   109,    81,   207,   292,   206,   295,   206,   295,   206,
     292,   208,     6,    -1,   109,    84,   207,   292,   206,   295,
     206,   295,   206,   292,   208,     6,    -1,   109,    78,   207,
     292,   206,   295,   206,   295,   206,   295,   206,   292,   208,
       6,    -1,   109,    81,   207,   292,   206,   295,   206,   295,
     206,   295,   206,   292,   208,     6,    -1,   109,    84,   207,
     292,   206,   295,   206,   295,   206,   295,   206,   292,   208,
       6,    -1,    -1,   109,    78,   207,   292,   206,   295,   208,
     272,   207,   281,   208,     6,    -1,    -1,   109,    81,   207,
     292,   206,   295,   208,   273,   207,   281,   208,     6,    -1,
      -1,   109,    84,   207,   292,   206,   295,   208,   274,   207,
     281,   208,     6,    -1,    -1,   109,    78,   207,   292,   206,
     295,   206,   295,   206,   292,   208,   275,   207,   281,   208,
       6,    -1,    -1,   109,    81,   207,   292,   206,   295,   206,
     295,   206,   292,   208,   276,   207,   281,   208,     6,    -1,
      -1,   109,    84,   207,   292,   206,   295,   206,   295,   206,
     292,   208,   277,   207,   281,   208,     6,    -1,    -1,   109,
      78,   207,   292,   206,   295,   206,   295,   206,   295,   206,
     292,   208,   278,   207,   281,   208,     6,    -1,    -1,   109,
      81,   207,   292,   206,   295,   206,   295,   206,   295,   206,
     292,   208,   279,   207,   281,   208,     6,    -1,    -1,   109,
      84,   207,   292,   206,   295,   206,   295,   206,   295,   206,
     292,   208,   280,   207,   281,   208,     6,    -1,   282,    -1,
     281,   282,    -1,   120,   207,   292,   208,     6,    -1,   120,
     207,   298,   206,   298,   208,     6,    -1,   120,   207,   298,
     206,   298,   206,   298,   208,     6,    -1,   121,     6,    -1,
     112,     6,    -1,   112,   292,     6,    -1,   128,     6,    -1,
     128,   130,     6,    -1,   129,     6,    -1,   129,   130,     6,
      -1,   126,     6,    -1,   126,   130,     6,    -1,   127,     6,
      -1,   127,   130,     6,    -1,   122,   200,   292,   201,     7,
     298,   101,   292,     6,    -1,   101,     4,   202,   292,   203,
       6,    -1,    -1,   101,     4,   292,    -1,    -1,     4,    -1,
      -1,     7,   298,    -1,    -1,     7,   292,    -1,    -1,   111,
     298,    -1,    96,    81,   299,     7,   292,   283,     6,    -1,
      96,    84,   299,   285,   284,     6,    -1,    90,    84,   207,
     292,   208,     7,   298,     6,    -1,    96,    86,   299,   285,
       6,    -1,   131,   299,     6,    -1,   118,    84,   207,   301,
     208,     7,   292,     6,    -1,   112,    84,   299,   286,     6,
      -1,   112,    86,   299,     6,    -1,   113,    84,   298,     7,
     292,     6,    -1,   100,    81,   207,   301,   208,     7,   207,
     301,   208,   287,     6,    -1,   100,    84,   207,   301,   208,
       7,   207,   301,   208,   287,     6,    -1,   100,    81,   207,
     301,   208,     7,   207,   301,   208,   105,   207,   295,   206,
     295,   206,   292,   208,     6,    -1,   100,    84,   207,   301,
     208,     7,   207,   301,   208,   105,   207,   295,   206,   295,
     206,   292,   208,     6,    -1,   100,    81,   207,   301,   208,
       7,   207,   301,   208,   106,   295,     6,    -1,   100,    84,
     207,   301,   208,     7,   207,   301,   208,   106,   295,     6,
      -1,   100,    84,   292,   207,   301,   208,     7,   292,   207,
     301,   208,     6,    -1,    78,   207,   301,   208,   145,    84,
     207,   292,   208,     6,    -1,    81,   207,   301,   208,   145,
      84,   207,   292,   208,     6,    -1,    78,   207,   301,   208,
     145,    86,   207,   292,   208,     6,    -1,    81,   207,   301,
     208,   145,    86,   207,   292,   208,     6,    -1,    84,   207,
     301,   208,   145,    86,   207,   292,   208,     6,    -1,   119,
      84,   299,     6,    -1,   119,    81,   299,     6,    -1,    93,
      78,   299,     6,    -1,    93,    81,   299,     6,    -1,    93,
      84,   299,     6,    -1,   116,     6,    -1,   116,     4,     6,
      -1,   116,    78,   207,   301,   208,     6,    -1,   165,    -1,
     166,    -1,   167,    -1,   290,     6,    -1,   290,   207,   298,
     208,     6,    -1,   290,   207,   298,   206,   298,   208,     6,
      -1,   290,   200,   298,   201,   207,   298,   206,   298,   208,
       6,    -1,   293,    -1,   200,   292,   201,    -1,   191,   292,
      -1,   190,   292,    -1,   195,   292,    -1,   292,   191,   292,
      -1,   292,   190,   292,    -1,   292,   192,   292,    -1,   292,
     193,   292,    -1,   292,   194,   292,    -1,   292,   199,   292,
      -1,   292,   186,   292,    -1,   292,   187,   292,    -1,   292,
     189,   292,    -1,   292,   188,   292,    -1,   292,   185,   292,
      -1,   292,   184,   292,    -1,   292,   183,   292,    -1,   292,
     182,   292,    -1,   292,   181,   292,     8,   292,    -1,    15,
     234,   292,   235,    -1,    16,   234,   292,   235,    -1,    17,
     234,   292,   235,    -1,    18,   234,   292,   235,    -1,    19,
     234,   292,   235,    -1,    20,   234,   292,   235,    -1,    21,
     234,   292,   235,    -1,    22,   234,   292,   235,    -1,    23,
     234,   292,   235,    -1,    25,   234,   292,   235,    -1,    26,
     234,   292,   206,   292,   235,    -1,    27,   234,   292,   235,
      -1,    28,   234,   292,   235,    -1,    29,   234,   292,   235,
      -1,    30,   234,   292,   235,    -1,    31,   234,   292,   235,
      -1,    32,   234,   292,   235,    -1,    33,   234,   292,   235,
      -1,    34,   234,   292,   206,   292,   235,    -1,    35,   234,
     292,   206,   292,   235,    -1,    36,   234,   292,   206,   292,
     235,    -1,    24,   234,   292,   235,    -1,     3,    -1,     9,
      -1,    14,    -1,    10,    -1,    11,    -1,   170,    -1,   171,
      -1,   172,    -1,    66,    -1,    67,    -1,    68,    -1,    -1,
      74,   234,   292,   294,   245,   235,    -1,   164,   234,   305,
     235,    -1,   164,   234,   305,   206,   292,   235,    -1,   310,
      -1,     4,   202,   292,   203,    -1,     4,   200,   292,   201,
      -1,   309,   202,   292,   203,    -1,   309,   200,   292,   201,
      -1,   168,   200,   310,   201,    -1,   169,   200,   306,   201,
      -1,   205,   310,   234,   235,    -1,   310,   233,    -1,     4,
     202,   292,   203,   233,    -1,     4,   200,   292,   201,   233,
      -1,   309,   202,   292,   203,   233,    -1,   309,   200,   292,
     201,   233,    -1,     4,   204,     4,    -1,     4,   202,   292,
     203,   204,     4,    -1,     4,   204,     4,   233,    -1,     4,
     202,   292,   203,   204,     4,   233,    -1,   160,   200,   305,
     206,   292,   201,    -1,    48,   200,   298,   206,   298,   201,
      -1,    49,   200,   305,   206,   305,   201,    -1,    50,   200,
     305,   206,   305,   201,    -1,    55,   200,   308,   201,    -1,
     296,    -1,   191,   295,    -1,   190,   295,    -1,   295,   191,
     295,    -1,   295,   190,   295,    -1,   207,   292,   206,   292,
     206,   292,   206,   292,   206,   292,   208,    -1,   207,   292,
     206,   292,   206,   292,   206,   292,   208,    -1,   207,   292,
     206,   292,   206,   292,   208,    -1,   200,   292,   206,   292,
     206,   292,   201,    -1,   298,    -1,   297,   206,   298,    -1,
     292,    -1,   300,    -1,   207,   208,    -1,   207,   301,   208,
      -1,   191,   207,   301,   208,    -1,   292,   192,   207,   301,
     208,    -1,   298,    -1,     5,    -1,   191,   300,    -1,   292,
     192,   300,    -1,   292,     8,   292,    -1,   292,     8,   292,
       8,   292,    -1,    78,   207,   292,   208,    -1,    78,     5,
      -1,    81,     5,    -1,    84,     5,    -1,    86,     5,    -1,
      98,    78,     5,    -1,    98,    81,     5,    -1,    98,    84,
       5,    -1,    98,    86,     5,    -1,    98,    78,   207,   301,
     208,    -1,    98,    81,   207,   301,   208,    -1,    98,    84,
     207,   301,   208,    -1,    98,    86,   207,   301,   208,    -1,
      78,   145,    56,   207,   292,   206,   292,   206,   292,   206,
     292,   206,   292,   206,   292,   208,    -1,    81,   145,    56,
     207,   292,   206,   292,   206,   292,   206,   292,   206,   292,
     206,   292,   208,    -1,    84,   145,    56,   207,   292,   206,
     292,   206,   292,   206,   292,   206,   292,   206,   292,   208,
      -1,    86,   145,    56,   207,   292,   206,   292,   206,   292,
     206,   292,   206,   292,   206,   292,   208,    -1,   256,    -1,
     267,    -1,     4,   234,   235,    -1,   309,   234,   235,    -1,
      37,   202,   310,   203,    -1,    37,   202,   300,   203,    -1,
      37,   200,   300,   201,    -1,    37,   202,   207,   301,   208,
     203,    -1,    37,   200,   207,   301,   208,   201,    -1,     4,
     234,   207,   301,   208,   235,    -1,   309,   234,   207,   301,
     208,   235,    -1,   292,    -1,   300,    -1,   301,   206,   292,
      -1,   301,   206,   300,    -1,   207,   292,   206,   292,   206,
     292,   206,   292,   208,    -1,   207,   292,   206,   292,   206,
     292,   208,    -1,   310,    -1,     4,   204,   142,   204,     4,
      -1,   207,   304,   208,    -1,     4,   202,   292,   203,   204,
     143,    -1,   302,    -1,   304,   206,   302,    -1,   306,    -1,
     310,    -1,     4,   202,   292,   203,    -1,   309,   202,   292,
     203,    -1,     4,   200,   292,   201,    -1,   309,   200,   292,
     201,    -1,     4,   204,     4,    -1,     4,   202,   292,   203,
     204,     4,    -1,     5,    -1,   175,   202,   310,   203,    -1,
      59,    -1,   173,    -1,    64,    -1,   162,   200,   305,   201,
      -1,   161,   200,   305,   206,   305,   201,    -1,   163,   234,
     305,   235,    -1,   163,   234,   305,   206,   305,   235,    -1,
      42,   234,   308,   235,    -1,    43,   200,   305,   201,    -1,
      44,   200,   305,   201,    -1,    45,   200,   305,   206,   305,
     206,   305,   201,    -1,    40,   234,   308,   235,    -1,    52,
     234,   305,   235,    -1,    53,   234,   305,   235,    -1,    54,
     234,   305,   235,    -1,    51,   234,   292,   206,   306,   206,
     306,   235,    -1,    41,   234,   305,   235,    -1,    41,   234,
     305,   206,   301,   235,    -1,    60,   234,   305,   235,    -1,
      61,    -1,    47,   234,   305,   235,    -1,    46,   234,   305,
     235,    -1,    -1,    75,   234,   306,   307,   247,   235,    -1,
     305,    -1,   308,   206,   305,    -1,     4,   209,   207,   292,
     208,    -1,   309,   209,   207,   292,   208,    -1,     4,    -1,
     309,    -1,   176,   202,   305,   203,    -1
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
    1167,  1172,  1180,  1200,  1223,  1234,  1242,  1264,  1287,  1313,
    1334,  1346,  1360,  1360,  1362,  1364,  1373,  1383,  1382,  1403,
    1402,  1421,  1420,  1438,  1448,  1447,  1461,  1463,  1471,  1477,
    1482,  1508,  1509,  1513,  1524,  1539,  1549,  1550,  1555,  1563,
    1572,  1580,  1598,  1602,  1608,  1616,  1620,  1626,  1634,  1638,
    1644,  1652,  1656,  1662,  1671,  1674,  1687,  1690,  1700,  1723,
    1766,  1789,  1807,  1828,  1846,  1876,  1906,  1924,  1942,  1969,
    1988,  1993,  2011,  2057,  2075,  2114,  2120,  2126,  2133,  2158,
    2183,  2200,  2204,  2223,  2257,  2304,  2322,  2339,  2343,  2359,
    2407,  2412,  2417,  2422,  2427,  2432,  2455,  2461,  2472,  2473,
    2478,  2481,  2485,  2508,  2531,  2554,  2582,  2603,  2629,  2650,
    2672,  2692,  2804,  2823,  2861,  2970,  2979,  2985,  3000,  3028,
    3045,  3054,  3068,  3082,  3088,  3094,  3103,  3112,  3121,  3135,
    3197,  3215,  3232,  3247,  3276,  3288,  3312,  3316,  3321,  3328,
    3333,  3339,  3344,  3350,  3358,  3362,  3366,  3371,  3431,  3447,
    3464,  3481,  3503,  3525,  3560,  3568,  3576,  3582,  3589,  3596,
    3616,  3642,  3654,  3666,  3674,  3682,  3691,  3690,  3705,  3704,
    3719,  3718,  3733,  3732,  3746,  3753,  3760,  3767,  3774,  3781,
    3788,  3795,  3802,  3810,  3809,  3823,  3822,  3836,  3835,  3849,
    3848,  3862,  3861,  3875,  3874,  3888,  3887,  3901,  3900,  3914,
    3913,  3930,  3933,  3939,  3951,  3971,  3995,  3999,  4003,  4007,
    4011,  4015,  4021,  4027,  4031,  4035,  4039,  4043,  4062,  4075,
    4078,  4094,  4097,  4114,  4117,  4123,  4126,  4133,  4136,  4143,
    4199,  4269,  4274,  4341,  4377,  4385,  4428,  4467,  4487,  4519,
    4546,  4572,  4598,  4624,  4650,  4672,  4700,  4728,  4756,  4784,
    4812,  4851,  4890,  4911,  4932,  4959,  4963,  4973,  5008,  5009,
    5010,  5014,  5020,  5032,  5050,  5078,  5079,  5080,  5081,  5082,
    5083,  5084,  5085,  5086,  5093,  5094,  5095,  5096,  5097,  5098,
    5099,  5100,  5101,  5102,  5103,  5104,  5105,  5106,  5107,  5108,
    5109,  5110,  5111,  5112,  5113,  5114,  5115,  5116,  5117,  5118,
    5119,  5120,  5121,  5122,  5123,  5124,  5125,  5134,  5135,  5136,
    5137,  5138,  5139,  5140,  5141,  5142,  5143,  5144,  5149,  5148,
    5156,  5161,  5166,  5183,  5201,  5219,  5237,  5255,  5260,  5266,
    5281,  5300,  5320,  5340,  5360,  5383,  5388,  5393,  5403,  5413,
    5418,  5429,  5438,  5443,  5470,  5474,  5478,  5482,  5486,  5493,
    5497,  5501,  5505,  5512,  5517,  5524,  5529,  5533,  5538,  5542,
    5550,  5561,  5565,  5577,  5585,  5593,  5600,  5610,  5639,  5643,
    5647,  5651,  5655,  5659,  5663,  5667,  5671,  5700,  5729,  5758,
    5787,  5800,  5813,  5826,  5839,  5849,  5859,  5871,  5884,  5896,
    5900,  5904,  5908,  5912,  5930,  5951,  5956,  5960,  5964,  5976,
    5980,  5992,  6009,  6019,  6023,  6038,  6043,  6050,  6054,  6067,
    6081,  6095,  6109,  6123,  6131,  6142,  6146,  6150,  6158,  6164,
    6170,  6178,  6186,  6193,  6201,  6216,  6230,  6244,  6256,  6272,
    6281,  6290,  6300,  6311,  6315,  6334,  6341,  6347,  6354,  6362,
    6361,  6374,  6379,  6385,  6394,  6407,  6410,  6414
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
  "tDirName", "tFind", "tStrFind", "tStrCmp", "tStrChoice", "tUpperCase",
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
     435,    63,   436,   437,   438,   439,    60,    62,   440,   441,
      43,    45,    42,    47,    37,    33,   442,   443,   444,    94,
      40,    41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   210,   211,   211,   212,   212,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   214,   214,   215,   215,   215,   215,   215,
     215,   216,   216,   216,   216,   217,   217,   217,   217,   217,
     217,   218,   218,   219,   219,   221,   222,   220,   223,   223,
     225,   224,   226,   226,   228,   227,   229,   229,   231,   230,
     232,   232,   232,   232,   232,   233,   233,   234,   234,   235,
     235,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   237,   237,   238,   238,   238,   239,   238,   240,
     238,   241,   238,   238,   242,   238,   243,   243,   244,   244,
     244,   245,   245,   246,   246,   246,   247,   247,   248,   248,
     248,   248,   249,   249,   249,   250,   250,   250,   251,   251,
     251,   252,   252,   252,   253,   253,   254,   254,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     256,   256,   256,   256,   256,   256,   256,   256,   257,   257,
     258,   258,   258,   258,   258,   258,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   260,   260,   260,   260,   260,
     261,   261,   262,   263,   263,   263,   263,   263,   263,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   265,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   267,   267,   267,   268,   267,   269,   267,
     270,   267,   271,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   272,   267,   273,   267,   274,   267,   275,
     267,   276,   267,   277,   267,   278,   267,   279,   267,   280,
     267,   281,   281,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   283,
     283,   284,   284,   285,   285,   286,   286,   287,   287,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   289,   289,   289,   290,   290,
     290,   291,   291,   291,   291,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   294,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   295,   295,   295,   295,   295,   296,
     296,   296,   296,   297,   297,   298,   298,   298,   298,   298,
     298,   299,   299,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   301,   301,   301,   301,   302,
     302,   302,   302,   303,   303,   304,   304,   305,   305,   305,
     305,   305,   305,   305,   305,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   307,
     306,   308,   308,   309,   309,   310,   310,   310
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
       6,     6,     6,     4,     1,     2,     2,     3,     3,    11,
       9,     7,     7,     1,     3,     1,     1,     2,     3,     4,
       5,     1,     1,     2,     3,     3,     5,     4,     2,     2,
       2,     2,     3,     3,     3,     3,     5,     5,     5,     5,
      16,    16,    16,    16,     1,     1,     3,     3,     4,     4,
       4,     6,     6,     6,     6,     1,     1,     3,     3,     9,
       7,     1,     5,     3,     6,     1,     3,     1,     1,     4,
       4,     4,     4,     3,     6,     1,     4,     1,     1,     1,
       4,     6,     4,     6,     4,     4,     4,     8,     4,     4,
       4,     4,     8,     4,     6,     4,     1,     4,     4,     0,
       6,     1,     3,     5,     5,     1,     1,     4
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,     0,     0,   271,   272,     0,     0,     0,
     266,     0,     0,     0,     0,     0,   368,   369,   370,     0,
       0,     5,     7,     6,     8,     9,    10,    21,    11,    12,
      13,    14,    20,    19,    18,    15,    16,    17,     0,    22,
     556,     0,   417,   555,   525,   418,   420,   421,   419,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   527,     0,   546,
     529,   425,   426,   427,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   422,   423,   424,   528,     0,     0,
       0,     0,    67,    68,     0,     0,   210,     0,     0,     0,
     375,     0,   517,   556,   432,     0,     0,     0,     0,   250,
       0,   252,   253,   248,   249,     0,   254,   255,   124,   136,
      67,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   454,     0,     0,     0,     0,     0,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   555,     0,   210,
     556,     0,     0,   365,     0,     0,     0,     0,     0,     0,
       0,     0,   555,   472,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   494,   495,   465,   471,     0,   466,   556,
     432,     0,     0,     0,     0,   555,     0,     0,   511,     0,
       0,     0,     0,   246,   247,     0,   555,     0,     0,     0,
     264,   265,     0,   210,     0,   210,   555,     0,   556,     0,
     371,     0,     0,    67,    68,     0,     0,    60,    64,    63,
      62,    61,    66,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     378,   377,   379,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   209,     0,   208,     0,     0,   243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,   239,     0,     0,   440,   185,     0,
     555,     0,   517,   556,   518,     0,     0,   551,     0,   122,
     122,     0,     0,     0,     0,   505,   506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   333,
     333,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   210,   210,
       0,   456,   455,     0,     0,     0,     0,   210,   210,     0,
       0,     0,     0,     0,     0,     0,   282,     0,   210,     0,
       0,     0,     0,     0,   335,     0,     0,     0,     0,     0,
       0,     0,   228,   366,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,     0,     0,     0,     0,   478,     0,
       0,   479,     0,   480,     0,   481,     0,     0,     0,     0,
       0,     0,   377,   473,     0,   467,     0,     0,     0,   343,
      67,    68,     0,   245,     0,     0,     0,     0,     0,   210,
       0,     0,     0,     0,     0,   268,   267,     0,   233,     0,
     234,     0,     0,     0,   210,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       0,     0,   445,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   428,   549,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,    61,     0,   376,    60,    61,     0,
       0,    60,     0,     0,     0,     0,     0,   205,     0,     0,
       0,     0,   211,     0,     0,     0,   393,   392,   391,   390,
     386,   387,   389,   388,   381,   380,   382,   383,   384,   385,
       0,     0,     0,   186,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   362,   363,   364,     0,     0,     0,     0,   331,
       0,     0,     0,   152,   153,     0,   155,   156,     0,   158,
     159,     0,   161,   162,     0,   180,     0,   191,     0,   197,
       0,     0,     0,     0,   172,   210,     0,     0,     0,     0,
       0,   458,   457,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   276,     0,     0,     0,     0,     0,     0,     0,
     346,     0,     0,   229,     0,     0,   225,     0,     0,     0,
     361,   360,     0,     0,     0,     0,     0,   445,    69,    70,
       0,   496,     0,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,   482,     0,   483,     0,   484,     0,   485,
       0,     0,   376,   468,   475,     0,   382,   474,     0,     0,
       0,   497,     0,     0,     0,     0,     0,     0,     0,     0,
     269,   270,     0,     0,   235,   237,     0,   557,     0,     0,
       0,    60,    61,     0,     0,    60,    61,     0,     0,     0,
       0,    91,    75,     0,   434,   433,   447,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   416,   404,     0,   406,
     407,   408,   409,   410,   411,   412,     0,     0,     0,   538,
       0,   543,   534,   535,   536,     0,   548,   547,     0,     0,
       0,     0,   539,   540,   541,   453,   545,   141,   146,   114,
       0,     0,   530,     0,   532,     0,   430,   437,   438,   526,
       0,     0,     0,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,   439,
       0,     0,     0,     0,   553,     0,     0,    45,     0,     0,
       0,    58,     0,    36,    37,    38,    39,    40,   436,   435,
       0,     0,   523,    25,    23,     0,     0,     0,     0,    26,
       0,     0,   240,   552,    71,   125,    72,   137,     0,     0,
       0,   507,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   329,   334,   332,     0,   342,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   376,   376,     0,     0,
       0,     0,     0,   236,   238,     0,     0,     0,   200,   202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   311,     0,   273,     0,     0,
       0,     0,     0,     0,   336,   345,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   434,   433,     0,     0,
     500,     0,   499,   498,     0,   477,     0,     0,     0,     0,
       0,     0,     0,   469,     0,     0,   436,   435,     0,     0,
       0,     0,     0,     0,   230,     0,     0,     0,     0,     0,
     232,     0,     0,   372,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   554,     0,     0,   442,     0,   441,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
       0,    89,     0,     0,    77,     0,     0,     0,     0,    81,
     104,   106,     0,     0,   515,     0,   112,     0,     0,     0,
       0,     0,   394,     0,     0,     0,     0,     0,    31,   444,
     443,   521,   519,    24,     0,     0,   522,   520,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,     0,     0,     0,     0,     0,     0,     0,   340,     0,
       0,   154,     0,   157,     0,   160,     0,   163,     0,     0,
       0,     0,     0,     0,     0,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   317,     0,     0,   316,     0,
     323,     0,   325,     0,   319,     0,   321,     0,   283,   312,
       0,     0,     0,   223,     0,     0,     0,   347,     0,   227,
     226,   367,     0,     0,    32,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   486,   487,   488,   489,   476,
     470,     0,     0,     0,     0,   512,     0,     0,     0,   259,
       0,     0,     0,     0,     0,     0,     0,    86,     0,    90,
       0,     0,    78,     0,    82,     0,   242,   446,   241,   405,
     413,   414,   415,   544,     0,   450,   451,   452,     0,     0,
     429,   142,     0,   550,   147,   449,   531,   533,   431,     0,
       0,     0,    87,     0,     0,     0,    60,     0,     0,     0,
       0,    79,     0,     0,     0,   513,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   463,     0,     0,    27,    28,
       0,    29,     0,     0,   126,   133,     0,     0,    73,    74,
     168,     0,     0,     0,     0,     0,     0,   171,     0,     0,
     188,   189,     0,     0,   173,   196,     0,     0,     0,     0,
     164,     0,   339,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,     0,     0,     0,     0,   210,
     210,     0,   293,     0,   295,     0,   297,     0,   318,   465,
       0,     0,   324,   326,   320,   322,     0,     0,   277,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     446,   503,   502,   501,     0,     0,     0,     0,   504,   176,
     177,     0,     0,     0,     0,   115,   119,     0,     0,     0,
     373,     0,     0,     0,    88,     0,     0,     0,    80,     0,
     448,     0,     0,     0,     0,     0,    98,     0,     0,    92,
       0,     0,     0,     0,   109,     0,     0,   110,     0,   516,
     212,   213,   214,   215,     0,     0,    41,     0,     0,     0,
       0,     0,    43,   524,     0,     0,   127,   134,     0,     0,
       0,     0,   167,   174,   175,   179,     0,     0,   190,     0,
       0,   341,     0,   183,     0,     0,   330,   195,   169,   182,
     194,   199,   181,     0,   192,   198,     0,     0,     0,     0,
       0,     0,   462,     0,   461,     0,     0,     0,   284,     0,
       0,   285,     0,     0,   286,     0,     0,     0,     0,     0,
       0,     0,   222,     0,     0,   221,     0,     0,     0,   216,
       0,     0,   344,    34,     0,     0,     0,     0,     0,     0,
     510,     0,   261,   260,     0,     0,     0,     0,     0,    99,
       0,     0,    93,     0,     0,     0,   537,   542,     0,   143,
     145,     0,   148,   149,   150,   100,   102,    94,    96,   105,
     107,     0,   113,     0,    83,    46,     0,     0,     0,   464,
       0,     0,     0,    30,     0,   141,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,     0,   337,
     337,     0,   120,   121,   210,     0,   203,   204,     0,     0,
       0,     0,     0,     0,     0,   313,     0,     0,   210,     0,
       0,     0,     0,     0,   207,   206,     0,     0,     0,     0,
       0,     0,     0,     0,   116,   117,     0,     0,   101,   103,
      95,    97,    84,     0,   505,   506,     0,     0,   514,     0,
      42,     0,     0,     0,    44,    59,     0,     0,     0,   131,
     129,   355,   357,   356,   358,   359,   187,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     460,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     328,     0,     0,     0,   278,     0,     0,   217,     0,     0,
       0,     0,     0,     0,     0,   509,   262,     0,     0,   374,
       0,   144,     0,     0,   151,   111,     0,     0,     0,     0,
       0,   128,   135,   141,   141,     0,     0,     0,     0,     0,
     338,   348,     0,     0,   349,     0,   201,     0,   299,     0,
       0,   301,     0,     0,   303,     0,     0,     0,   314,     0,
     274,     0,   210,     0,     0,     0,     0,     0,     0,     0,
     178,   118,   258,     0,   138,     0,     0,    50,     0,    56,
       0,     0,     0,     0,     0,   165,   193,     0,   352,     0,
     353,   354,   459,   287,     0,     0,   294,   288,     0,     0,
     296,   289,     0,     0,   298,     0,     0,     0,   280,     0,
     220,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,   130,     0,     0,     0,     0,
     305,     0,   307,     0,   309,   315,   327,   279,   275,     0,
       0,     0,     0,     0,     0,     0,     0,   139,   140,    47,
       0,    54,     0,     0,     0,     0,     0,     0,   290,     0,
       0,   291,     0,     0,   292,     0,     0,   224,     0,   218,
       0,     0,     0,     0,     0,    48,     0,     0,   251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   281,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   257,     0,
       0,   300,     0,   302,     0,   304,     0,   219,     0,     0,
       0,     0,    49,    51,     0,    52,     0,     0,     0,     0,
       0,     0,   490,   491,   492,   493,     0,     0,    57,   350,
     351,   306,   308,   310,    53,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    91,   995,    92,    93,   710,  1525,  1531,
     983,  1193,  1719,  1934,   984,  1880,  1974,   985,  1936,   986,
     987,  1197,   354,   447,   188,   831,    94,   728,   459,  1655,
    1794,  1793,  1656,   460,  1713,  1161,  1351,  1162,  1354,   762,
     765,   768,   771,  1555,  1404,   692,   303,   423,   424,    97,
      98,    99,   100,   101,   102,   103,   104,   304,  1078,  1821,
    1899,   800,  1579,  1582,  1585,  1854,  1858,  1862,  1919,  1922,
    1925,  1074,  1075,  1237,  1034,   759,   809,  1743,   106,   107,
     108,   109,   305,   190,   937,   512,   261,  1384,   306,   307,
     308,   576,   317,   968,  1185,   457,   452,   938,   458,   338,
     310
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1405
static const yytype_int16 yypact[] =
{
    9306,    85,    56,  9428, -1405, -1405,  4042,     2,    93,   -19,
      60,    12,   210,   260,   305,   313,   132,   352,   384,   173,
     196,  -127,  -127,  -170,   207,   216,    32,   259,   273,    38,
     287,   304,   322,   371,   383,   508,   272,    15,   437,   441,
     422,   454,   376,   642,   208,   367,   496,   -99,   425,   -69,
     -69,   426,   281,   333,    58,   570,   580,    20,    23,   586,
     590,   231,   683,   696,   700,  5746,   706,   516,   529,   533,
      31,    65, -1405,   549,   550, -1405, -1405,   747,   750,   558,
   -1405,  5624,   577,  6023,    34,    45, -1405, -1405, -1405,  9165,
     581, -1405, -1405, -1405, -1405, -1405, -1405, -1405, -1405, -1405,
   -1405, -1405, -1405, -1405, -1405, -1405, -1405, -1405,    -1, -1405,
    -121,     7, -1405,     9, -1405, -1405, -1405, -1405, -1405,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,   608,   611,   630,  -127,  -127,   637,
     663,   670,  -127,  -127,  -127,  -127,   671, -1405,  -127, -1405,
   -1405, -1405, -1405, -1405,  -127,  -127,   853,   674,   698,   712,
    -127,  -127,   716,   720, -1405, -1405, -1405, -1405,   734,  9165,
    9165,  9165,  8586,  8647,   277,    24,   452,   717,   741,   951,
   -1405,   759,   946,   -85,   128,   970,  9165,  5829,  5829, -1405,
    9165, -1405, -1405, -1405, -1405,  5829, -1405, -1405, -1405, -1405,
   -1405, -1405,  6222,    24,  9165,  8393,  9165,  9165,   784,  9165,
    8393,  9165,  9165,   802,  8393,  9165,  9165,  6144,   803,   772,
   -1405,  8393,  5746,  5746,  5746,   810,   818,  5746,  5746,  5746,
     823,   830,   848,   852,   880,  6343,  6542,  6741,   844,  1284,
    1065,  6144,    31,   881,   893,   -69,   -69,   -69,  9165,  9165,
     -82, -1405,   -64,   -69,   908,   939,   956,  8134,   -62,   -60,
     884,   926,   976,  5746,  5746,  6144,   980,    13,   964, -1405,
     972,  1185,  1186, -1405,   991,   995,  1011,  5746,  5746,  1017,
    1028,  1033,   631, -1405,   -48,    -4,    26,    27,    35,   780,
    6940,  9165,  4677, -1405, -1405,  3278, -1405,  1228, -1405,   -63,
     -34,  1236,  9165,  9165,  9165,   141,  9165,  1049, -1405,  1112,
    9165,  9165,  9165, -1405, -1405,  9165,  1053,  1260,  1262,  1062,
   -1405, -1405,  1264, -1405,  1265, -1405,   619,  3842,   228,  5829,
   -1405,  6144,  6144,  8845,  8906,  1066,  1067,  6222, -1405, -1405,
   -1405, -1405, -1405, -1405,  6144,  1266,  1073,  9165,  9165,  1272,
    9165,  9165,  9165,  9165,  9165,  9165,  9165,  9165,  9165,  9165,
    9165,  9165,  9165,  9165,  9165,  9165,  9165,  9165,  9165,  9165,
    9165,  9165,  5829,  5829,  5829,  5829,  5829,  5829,  5829,  5829,
    6144,  5829,  5829,  9165,  5829,  5829,  5829,  5829,  5829,  9165,
    6222,  9165,  5829,  5829,  5829,  5829,  5829,    24,  6222,    24,
    1078,  1078,  1078,   129, 11438,   190,  8611,   163,  1074,  1274,
    -127,  1075, -1405,  1076,  4506,  9165,  8393, -1405,  9165,  9165,
    9165,  9165,  9165,  9165,  9165,  9165,  9165,  9165,  9165,  9165,
    9165,  9165,  9165, -1405, -1405,  9165,  9165, -1405, -1405,  1022,
     644,   151, -1405,   480, -1405,   225,  9897, -1405,   288,   127,
     143,  1080,  1083, 11459,  8393,  3981, -1405,   158, 11480, 11501,
    9165, 11522,   170, 11543, 11564,  9165,   328, 11585, 11606,  1283,
    9165,  9165,   342,  1285,  1286,  1290,  9165,  9165,  1314,  1317,
    1317,  9165,  8200,  8200,  8200,  8200,  9165,  1291,  9165,  1319,
    9165,  1320,  8393,  8393,  5308,  1128,  1324,  1124, -1405, -1405,
    -157, -1405, -1405,  9923,  9949,   -69,   -69,   452,   452,   -41,
    9165,  9165,  9165,  8134,  8134,  9165,  4506,   138, -1405,  9165,
    9165,  9165,  9165,  9165,  1329,  1331,  1335,  9165,  1332,  9165,
    9165,   992, -1405, -1405,  8393,  8393,  8393,  1337,  1338,  9165,
    9165,  9165,  9165,  9165,  1341,   369,  7139,  7338, -1405,  1292,
    9165, -1405,  1293, -1405,  1301, -1405,  1303,    46,    47,    48,
      50,  8393,  1078, -1405, 11627, -1405,   343,  9165,  7537, -1405,
    9165,  9165,   563, -1405, 11648, 11669, 11690,  1205,  9975, -1405,
    1157,  4071, 11711, 11732,  8870, -1405, -1405,  8393, -1405,  1729,
   -1405,  1890,  9165,  9165, -1405,  9165,  9165,  1162,  1165,   387,
     262, 11753,   267, 11093,  9165,  8393,  1361,  1362, -1405,  9165,
   11774, 11116,   211,  8096,  8096,  8096,  8096,  8096,  8096,  8096,
    8096,  8096,  8096,  8096, 10001,  8096,  8096,  8096,  8096,  8096,
    8096,  8096, 10027, 10053, 10079,   633,   666,   633,  1168,  1169,
    1166,   597,   597,  1170,  1173,  1174, 10105,   597,   597,   597,
     490,   597, 12320, -1405,  1347,  1175,  1176,  1182,   676,   687,
    1183,  1184,  1171,  1346,  1348,  6144,   176,  1353,  1354,  6144,
     116,  6222,  9165,  1369,  1391,    43,   597, -1405,    98,    40,
      44,   117, -1405,  4000,   593,  4111,   968,   851,   869,   869,
     613,   613,   613,   613,   415,   415,  1078,  1078,  1078,  1078,
       0, 11795, 11139, -1405,  9165,  9165,  1392,     1,  8393,  9165,
    9165,  1395,  8393,  9165,  1396,  5829,  1401, -1405,    24,  1402,
    5829,  9165,  6222,  1403,  8393,  8393,  1267,  1407,  1409, 11816,
    1410,  1278,  1412,  1415, 11837,  1279,  1420,  1424,  9165, 11858,
    4626,  1202, -1405, -1405, -1405, 11879, 11900,  9165,  6144,  1428,
    1431, 11921,  1237, 12320,  1233,  1239, 12320,  1235,  1242, 12320,
    1243,  1249, 12320,  1245, 11942, -1405, 11963, -1405, 11984, -1405,
     681,   691,  8393,  1254, -1405, -1405,  2238,  2266,   -69,  9165,
    9165, -1405, -1405,  1256,  1257,  8134, 10131, 10157, 10183,  9871,
     660,   -69,  2416, 12005,  4820, 12026, 12047, 12068,  9165,  1456,
   -1405,  9165, 12089, -1405, 11162, 11185, -1405,   707,   715,   722,
   -1405, -1405, 11208, 11231, 10209, 12110, 11254,   -34, -1405, -1405,
    8393, -1405,  8393,  3981,  1268,  8393,  1263,   174,  1269,  5019,
    1270,  1273,  1276, -1405,  8393, -1405,  8393, -1405,  8393, -1405,
    8393,   723, -1405, -1405,  4351,  8393,  1078, -1405, 12131, 11277,
    8393, -1405,  1460,  1463,  1464,  1288,  9165,  2496,  9165,  9165,
   -1405, -1405,    16,   736, -1405, -1405,  2669, -1405,  1280,  6144,
    1466,  1433,  1441,  6144,   176,  1448,  1450,  6144,   176,  5449,
     739, -1405, -1405, 11300,   340,  1562, -1405, -1405, -1405, -1405,
   -1405, -1405, -1405, -1405, -1405, -1405, -1405, -1405,  9165, -1405,
   -1405, -1405, -1405, -1405, -1405, -1405,  9165,  9165,  9165, -1405,
    8393, -1405, -1405, -1405, -1405,  5829, -1405, -1405,  6144,  5829,
    5829,  6222, -1405, -1405, -1405, -1405, -1405, -1405, -1405, -1405,
    9165,  5829, -1405,  5829, -1405,  9165, -1405, -1405, -1405, -1405,
    -127,  -127,  1488, -1405,  9165,  1489,  -127,  -127,  1491,   279,
    9165,  1492,  1493,  1563, -1405,  1497,  1304,    31,  1505, -1405,
    8393,  8393,  8393,  8393, -1405,   597,  9165, -1405,  1312,  1313,
    1308, -1405,  1510, -1405, -1405, -1405, -1405, -1405,   404,   523,
   12152, 11323, -1405, -1405,  1330,  5829,   589, 12173, 11346, -1405,
     614, 10235, -1405, -1405, -1405,    73, -1405, -1405,  8096,   597,
     -69,  3981, -1405,   867,  6144,  6144,  1511,  6144,   872,  6144,
    6144,  1512,  1434,  6144,  6144,  2198,  1514,  1515,  8393,  1516,
    1517,  2834, -1405, -1405,  1519, -1405,  1520,   297,  9165,   297,
    9165,   297,  9165,   297,  9165,  1535,  1536,  1537,  1538,  1540,
     753,  1544,  2764, -1405, -1405,   206, 10261, 10287, -1405, -1405,
    6280,  -106,   -69,   -69,   -69,  1546,  9104,  1344,  1547,  1352,
      59,    68,    71,    84,   -15, -1405,   223, -1405,   660,  1548,
    1550,  1551,  1552,  1553, 12320, -1405,  2276,  1355,  1555,  1557,
    1558,  1470,  1561,  1559,  1564,  9165,   -34,   -94,   754,   757,
   -1405,   765, -1405, -1405,  9165, -1405,  9165,  9165,  9165,   766,
     769,   779,   782, -1405,  9165,   783,   -34,   -34,   787,  6144,
    6144,  6144,  1567, 10313, -1405,  4382,   553,  1568,  1572,  1371,
   -1405,  6144,  1372, -1405,  -127,  -127,  1576,  9165,  1580,  -127,
    -127,  1581,  9165,  1582, -1405,   597,  1585, -1405,  1588, -1405,
    1587,  8096,  8096,  8096,  8096,   704,  1388,  1394,  1397,  1398,
    1390,   708,   740, 12194,  1399,   597,  8096,   115,  5829, -1405,
    2524, -1405,   115,  5829, -1405,   255,  1406,  1594,  2809, -1405,
   -1405, -1405,    31,  9165, -1405,   788, -1405,   791,   792,   800,
     801,   297, 12320,  1417,  9165,  9165,  6144,  1405, -1405, -1405,
   -1405, -1405,  1414, -1405,  1613,     4, -1405, -1405,  1614,  9165,
    5281,  1423,  1426,  1624,  1625,    89,  1425,  1427,  1539,  1539,
    6144,  1629,  1429,  1432,  1634,  1635,  6144,  1435,  1638,  1639,
   -1405,  1641,  6144,   807,  6144,  6144,  1645,  1647, -1405,  6144,
    6144, 12320,  6144, 12320,  6144, 12320,  6144, 12320,  6144,  6144,
    6144,  1444,  1449,  1650,   442, -1405,  9165,  9165,  9165,  1451,
    1452,  -145,  -119,  -108,  1459, -1405,  3089,  6144, -1405,  9165,
   -1405,  1656, -1405,  1660, -1405,  1661, -1405,  1663, -1405, -1405,
    8134,   585,  5945, -1405,  1465,  1467,  7736, -1405,  8393, -1405,
   -1405, -1405,  1468,  9165, -1405, -1405, 11369,  1666,   597,  1472,
    1473, 10339, 10365, 10391, 10417, -1405, -1405, -1405, -1405, 12320,
   -1405,   597,  1671,  1672,  1542, -1405,  9165,  9165,  9165, -1405,
    1673,   567,  6222,  1475,  1679,   115,  5829, -1405,  3367, -1405,
     115,  5829, -1405,  3426, -1405,   297, -1405,   587, -1405, -1405,
   -1405, -1405, -1405, -1405,  5829, -1405, -1405, -1405,  6222,  1682,
   -1405, -1405,    21, -1405, -1405, -1405, -1405, -1405, -1405,  1688,
     633,   633, -1405,  1689,   633,   633,  6222,  9165,  1694,  1684,
      43, -1405,  1695, 11392,    31, -1405,  1697,  1699,  1700,  1701,
    6144,  9165, 10443, 10469,   816, -1405,  9165,  1704, -1405, -1405,
    5829, -1405, 10495,  4883, 12320, -1405,  1702,  1703, -1405, -1405,
   -1405,  9165,  9165,   -69,  1710,  1711,  1716, -1405,  9165,  9165,
   -1405, -1405,  1720,  9165, -1405, -1405,  1722,  1723,  1521,  1724,
    1586,  9165, -1405,  1726,  1727,  1728,  1730,  1734,  1737,  1025,
    1755,  8393,  8393,  9165, -1405,  8200,  6479, 12215,  1962,   452,
     452,   -69,  1758,   -69,  1759,   -69,  1761,  9165, -1405,   397,
    1565, 12236, -1405, -1405, -1405, -1405,  6678,   274, -1405,  1764,
    4321,  1767,  6144,   -69,  4321,  1769,   858,  9165,  3600,  1770,
     -34, -1405, -1405, -1405,  9165,  9165,  9165,  9165, -1405, -1405,
   -1405,  6144,  3716,   435, 12257, -1405, -1405,  5348,  1571,  6144,
   -1405,  1773,   633,   633, -1405,  1775,   633,   633, -1405,  6144,
   -1405,  1591,   597,  5082,  5547,  6222, -1405,  1780,  1781, -1405,
    1787,  1788,  1790,  3620, -1405,  1791,  1793, -1405,  1593, -1405,
   -1405, -1405, -1405, -1405,  1795,   672, 12320,  9165,  9165,  6144,
    1595,   877, 12320, -1405,  1797,  9165, -1405, -1405,  1597,  1598,
    6877,  7076,   413, -1405, -1405, -1405,  7275,  7474, -1405,  7673,
    1801, -1405,  6144, -1405,  1735,  1813, 12320, -1405, -1405, -1405,
   -1405, -1405, -1405,  1618, -1405, -1405,   886,   890,  9844,  3659,
    1815,  1622, -1405,  9165, -1405,  1623,  1626,   278, -1405,  1628,
     292, -1405,  1646,   311, -1405,  1648, 11415,  1824,  6144,  1826,
    1652,  9165, -1405,  7935,   365, -1405,   891,   407,   409, -1405,
    1830,  7872, -1405, -1405, 10521, 10547, 10573, 10599,  1714,  9165,
   -1405,  9165, -1405, -1405,  8393,  3678,  1854,  6222,  1653, -1405,
    1856,  1857, -1405,  1858,  1859,  1863, -1405, -1405,  4677, -1405,
   -1405,  5829, 12320, -1405, -1405, -1405, -1405, -1405, -1405, -1405,
   -1405,    31, -1405,  1731, -1405, -1405,  9165, 10625, 10651, -1405,
    6144,  9165,  1865, -1405, 10677, -1405, -1405,  6144,  6144,  1866,
    1867,  1874,  1875,  1876,  1877,   898,  1678, -1405,  6144,   711,
     745,  8393, -1405, -1405,   452,  4467, -1405, -1405,  8134,   660,
    8134,   660,  8134,   660,  1880, -1405,   905,  6144, -1405,  8330,
     -69,  1881,  8393,   -69, -1405, -1405,  9165,  9165,  9165,  9165,
    9165,  8541,  8800,   906, -1405, -1405,  1687,  1883, -1405, -1405,
   -1405, -1405, -1405,   914,  3950,  1884,   915,  1887, -1405,  1683,
   12320,  9165,  9165,   919, 12320, -1405,  9165,   941,   965, -1405,
   -1405, -1405, -1405, -1405, -1405, -1405, -1405,  1690,  9165,   966,
    1692,   -69,  6144,  1889,  1693,   -69,  1895,   969,  1698,  9165,
   -1405,  9059,   440,   647,  9424,   462,   774,  9452,   473,   981,
   -1405,  6144,  1898,  1804,  2843,  1707,   475, -1405,   978,   479,
   10703, 10729, 10755, 10781,  3794, -1405, -1405,  1902,  1903, -1405,
    9165, -1405,  6222,    24, -1405, -1405,  9165, 12278, 10807,    51,
   10833, -1405, -1405, -1405, -1405,  9165,  9480,  1913,   -69,   110,
   -1405, -1405,   -69,   112, -1405,  1917, -1405,  9508,  1918,  9165,
    1919,  1920,  9165,  1922,  1923,  9165,  1924,  1725, -1405,  9165,
   -1405,   660, -1405,  8393,  1925,  7935,  9165,  9165,  9165,  9165,
   -1405, -1405, -1405,  1657, -1405,  1732,   979, -1405,  9165, -1405,
    6144,  9165,   982,   989, 10859, -1405, -1405,   487, -1405,   493,
   -1405, -1405, -1405, -1405,  1733,  9536, -1405, -1405,  1736,  9564,
   -1405, -1405,  1739,  9592, -1405,  1929,  3814,  1132,  3233,   993,
   -1405,   512,  1016, 10885, 10911, 10937, 10963,  6222,  1740,  1930,
    1741, 12299,  1019,  9620, -1405, -1405,  9165,   -69,   -69,   660,
    1932,   660,  1936,   660,  1938, -1405, -1405, -1405, -1405,   660,
    1943,  8393,  1946,  9165,  9165,  9165,  9165, -1405, -1405, -1405,
    5829, -1405,  1749,  1951,  9648,   518,   572,  1234, -1405,  1754,
    1277, -1405,  1771,  1381, -1405,  1774,  1570, -1405,  1020, -1405,
   10989, 11015, 11041, 11067,  1032, -1405,  1779,  6144, -1405,  1956,
    9165,  9165,  1974,   660,  1976,   660,  1984,   660, -1405,  1985,
    9165,  9165,  9165,  9165,  5829,  1986,  5829,  1043, -1405,  9676,
    9704, -1405,  1592, -1405,  1662, -1405,  1838, -1405,  9732,  9760,
    9788,  9816, -1405, -1405,  1057, -1405,  1988,  1989,  1993,  1994,
    1995,  1996, -1405, -1405, -1405, -1405,  5829,  1997, -1405, -1405,
   -1405, -1405, -1405, -1405, -1405, -1405
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1405, -1405, -1405, -1405,   799, -1405, -1405, -1405, -1405,   219,
   -1405, -1405, -1405, -1405, -1405, -1405, -1405, -1405, -1405, -1405,
   -1405, -1405,  -349,   -70,  3602,  3304, -1405,  1554, -1405, -1405,
   -1405, -1405, -1405, -1405, -1405, -1369, -1405,   350, -1405, -1405,
   -1405, -1405, -1405, -1405,   794,  2004,     6,  -506,  -241, -1405,
   -1405, -1405, -1405, -1405, -1405, -1405, -1405,  2008, -1405, -1405,
   -1405, -1405, -1405, -1405, -1405, -1405, -1405, -1405, -1405, -1405,
   -1405, -1008, -1058, -1405, -1405,  1525, -1405,   349, -1405, -1405,
   -1405, -1405,  1696, -1405, -1405,   -30, -1405, -1404,  2017,   258,
    2859,  2225,  -250,   650, -1405,   124,    70, -1405,  -376,    -3,
     253
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -525
static const yytype_int16 yytable[] =
{
     110,   558,   507,   193,   977,   340,   645,   993,   647,    96,
    1389,   793,   794,   356,   347,   195,  1279,   538,   199,   260,
     262,   660,   268,  1127,   277,  1504,   526,   282,   326,   283,
     214,   561,   563,   515,   516,   315,   218,   215,   541,   332,
     565,   355,   223,   252,   218,   515,   516,   966,   223,   788,
     334,   843,   845,   847,   280,   849,     5,  1839,  1596,   253,
     254,  1441,   309,  1442,   675,  1270,   679,   280,   682,   319,
    1281,   515,   516,   210,  1272,   211,   192,  1274,   280,   343,
    1210,   344,   515,   516,   515,   516,  1065,  1443,   345,  1444,
    1276,     4,   599,   232,   601,  1400,   233,  1066,  1445,   234,
    1446,   284,  1260,   352,   353,  1067,  1068,  1069,   515,   516,
    1297,  1070,  1071,  1072,  1073,   445,  1848,   446,  1850,   450,
     114,   256,   257,   953,   345,   517,   515,   516,   515,   516,
     191,   258,   978,   979,   980,   981,   673,   580,   259,   581,
     529,   559,   273,   518,   274,   528,   345,   530,  1665,   515,
     516,   327,   556,   331,   557,   141,   142,   143,   144,   145,
     146,   147,   148,   352,   353,   795,   152,   153,   154,   155,
     681,   562,   564,   278,   157,   158,   159,   196,  1505,   160,
     566,   197,   280,   953,   348,   349,   350,   351,   994,  1271,
     165,   994,   422,  1278,   453,   453,    90,   677,  1273,   341,
      90,  1275,   453,   560,   352,   353,   342,    90,   982,   357,
     280,   358,   309,   359,  1277,   539,   201,   309,   187,   200,
    1128,   309,   187,  1279,   309,   510,   511,   279,   309,   309,
     309,   309,   219,   519,   309,   309,   309,   527,   316,   220,
     219,   333,   309,   309,   309,   224,  1723,   971,   309,   280,
     967,   972,   335,   844,   846,   848,   111,   850,  1840,   194,
     198,   883,  1366,   887,  1739,   320,   202,   786,   787,   881,
     309,   309,   309,  1211,   885,  1212,   168,   169,   170,   515,
     516,   417,   461,  1175,   309,   309,  1727,   802,   177,   248,
     178,    90,   249,   348,   349,   350,   351,   309,   214,   309,
     515,   516,   515,   516,   953,   970,   348,   349,   350,   674,
     281,   203,   287,   352,   353,   288,   828,   226,   829,   204,
     959,   451,   455,   318,   973,   352,   353,   954,   515,   516,
     726,   960,   205,   727,   328,  -518,   453,   269,   309,   309,
     348,   349,   350,   351,   801,   587,   729,   683,   867,   727,
     187,   309,   717,   348,   349,   350,   351,   718,   206,   264,
     352,   353,   265,   876,   735,   266,   736,   348,   349,   350,
     678,   352,   353,   352,   353,   208,   735,  1103,   741,   453,
     453,   453,   453,   453,   453,   453,   453,   309,   453,   453,
     207,   453,   453,   453,   453,   453,   515,   516,   209,   453,
     453,   453,   453,   453,   280,   577,   280,   216,   352,   353,
     227,   270,  1256,   515,   516,   271,   217,   616,  -523,   418,
     419,  1176,  1177,   309,  1842,  1843,   721,   272,   605,  1280,
     606,   722,   348,   349,   350,   351,  1882,   345,   420,   348,
     349,   350,   882,  1611,   348,   349,   350,   886,  1434,  1435,
     454,   454,   352,   353,   241,   228,   421,   242,   454,   221,
     243,   309,   244,   607,   515,   516,   462,   229,   515,   516,
     663,   256,   257,   222,   348,   349,   350,   351,   671,   231,
    1591,   258,   515,   516,  1678,   791,   792,   225,   267,   724,
     483,   484,   485,   511,   725,   488,   489,   490,  1680,   309,
     309,   515,   516,   237,   226,   318,   238,   646,   239,   648,
     649,   650,   651,   652,   230,   654,   655,  1682,   657,   658,
     659,   235,   661,   422,   422,   236,   665,   666,   667,   668,
     669,   534,   535,  1957,   735,  1137,   745,   352,   353,  1142,
     240,   309,   309,   309,  1052,   547,   548,  -521,   735,   735,
     751,   853,   896,   309,   309,   515,   516,    48,    49,    50,
      51,  1318,   764,   767,   770,   773,    56,   250,   309,    59,
     828,  1690,   829,  1486,  1487,   309,   830,   251,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   578,
     440,   441,   454,   879,   309,   880,   442,   515,   516,   515,
     516,   352,   353,   515,   516,  1587,   955,   439,   440,   441,
     961,  -522,   309,  1692,   442,  1693,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     515,   516,   255,   263,   442,   454,   454,   454,   454,   454,
     454,   454,   454,  1612,   454,   454,  1809,   454,   454,   454,
     454,   454,   515,   516,   275,   454,   454,   454,   454,   454,
     670,   276,   672,   515,   516,   515,   516,   285,  1812,   515,
     516,  1753,   309,  1756,   286,  1759,   309,   515,   516,  1815,
     719,  1823,   720,   515,   516,  1825,  1065,   289,  1240,   345,
    1242,   935,  1244,  1887,  1246,  1279,   725,  1066,  1279,  1888,
     290,  1279,   515,   516,   291,  1067,  1068,  1069,   515,   516,
     311,  1070,  1071,  1072,  1073,   309,   312,  1184,  1901,   309,
     352,   353,   453,   245,  1940,   280,   246,   453,   247,   313,
    -520,   309,   309,   314,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,  1065,   321,
     322,   962,   442,   323,  1319,   309,   324,   896,  1055,  1066,
     325,  1065,   515,   516,   828,  1061,   829,  1067,  1068,  1069,
     860,  1076,  1066,  1070,  1071,  1072,  1073,   329,  1941,   309,
    1067,  1068,  1069,   339,   352,   353,  1070,  1071,  1072,  1073,
    1205,  1360,  1361,  1458,  -524,   735,  1364,  1365,   828,   735,
     829,   975,  1009,   437,   438,   439,   440,   441,   385,  1279,
     837,   386,   442,  1867,  1138,  1208,  1740,  1741,  1143,   602,
     735,   603,  1742,   554,  1147,  1149,  1367,   309,   187,   309,
     387,   552,   309,   553,   828,   554,   829,   390,   186,   725,
     187,   309,  1380,   309,   714,   309,   715,   309,   716,  1003,
    1744,  1745,   309,   187,  1007,  1810,  1742,   309,   567,  1279,
     401,   568,  1279,   391,   569,  1279,   570,   828,  1279,   829,
     392,   397,   920,  1645,   402,  1065,   309,   828,  1646,   829,
     309,  1917,   943,  1920,   309,  1923,  1066,   735,   828,  1048,
     829,  1926,   453,   945,  1067,  1068,  1069,   735,   403,  1049,
    1070,  1071,  1072,  1073,  1279,   828,  1279,   829,  1279,   828,
     735,   829,   404,   735,  1349,  1090,   407,   309,  1199,  1200,
     408,   735,   453,  1091,   425,   309,   453,   453,   735,   735,
    1092,  1113,  1372,  1575,  1576,  1962,   409,  1964,   453,  1966,
     453,   828,   735,   829,  1129,   735,  1352,  1145,   426,  1492,
    1493,  1216,   444,  1217,  1496,  1497,  1222,   427,  1223,   735,
     735,  1253,  1298,   735,   280,  1299,   443,   309,   309,   309,
     309,   735,   735,  1300,  1305,   735,   448,  1306,   454,   481,
    1215,  1005,  1813,   454,   470,   735,  1499,  1307,   735,   735,
    1308,  1310,   453,   735,  1374,  1311,  1375,   735,   735,  1376,
    1377,  1160,   475,   480,     7,     8,   735,   735,  1378,  1379,
     486,   309,   309,   735,   309,  1418,   309,   309,   487,  1150,
     309,   309,  1529,   491,  1530,   309,  1147,  1149,   713,  1563,
     492,  1564,  1261,  1262,  1263,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,  1199,  1200,   493,  1156,
     442,   502,   494,  1158,  1159,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   735,  1164,  1600,  1165,   442,   505,
     688,    24,    25,   689,    27,    28,   690,    30,   691,    32,
     495,    33,  1065,  1651,   531,  1652,    38,    39,   508,    41,
      42,    43,   735,  1066,  1669,    46,   735,  1529,  1670,  1691,
     509,  1067,  1068,  1069,  1529,  1368,  1737,  1070,  1071,  1072,
    1073,  1761,   735,  1762,  1777,   520,   309,   309,   309,  1204,
    1780,   725,  1781,  1784,  1519,  1529,   532,  1789,   309,    67,
      68,    69,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   521,  1349,   454,  1791,
     442,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   522,   453,   453,   540,   442,  1748,   453,
     453,  1352,  1529,  1792,  1797,   735,   533,  1805,   454,   280,
     537,   345,   454,   454,   735,  1651,  1824,  1879,  1349,  1816,
    1884,   542,   543,   309,   454,  1349,   454,  1885,   544,   735,
     816,  1900,   545,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   309,   546,   549,
     318,   442,   735,   309,  1902,  1529,   735,  1912,  1949,   309,
     550,   309,   309,  1065,   579,   551,   309,   309,  1954,   309,
    1955,   309,   583,   309,  1066,   309,   309,   309,   454,  1529,
    1457,  1976,  1067,  1068,  1069,  1716,   589,   590,  1070,  1071,
    1072,  1073,   187,  1986,   309,  1987,   595,  1500,   596,   597,
     598,   600,   618,   614,   615,   619,   622,   442,   684,   309,
    1395,   685,   186,   309,   687,   309,   731,   112,   336,   732,
     748,   752,   753,   115,   116,   117,   754,   775,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   757,   453,   453,   758,   777,   779,   453,   453,   783,
     784,   785,   149,   150,   151,  1065,   808,   810,   813,   156,
    1897,   453,   811,   820,   821,   827,  1066,   865,   838,   840,
     161,   162,   163,   939,  1067,  1068,  1069,   841,   164,   842,
    1070,  1071,  1072,  1073,   868,   877,   878,   891,   892,   923,
     924,   280,   925,  1542,   949,   964,   928,   309,  1065,   929,
     930,   940,   941,   942,   947,   948,   950,   453,   951,  1066,
     309,  1717,  1488,   956,   957,   965,   992,  1067,  1068,  1069,
    1500,   999,  1002,  1070,  1071,  1072,  1073,  1004,  1006,  1028,
    1010,  1577,  1013,  1580,  1014,  1583,  1015,  1017,  1502,  1019,
     454,   454,  1020,  1018,  1022,   454,   454,  1023,   309,   309,
    1594,  1024,  1033,  1597,  1598,   318,  1512,  1035,  1037,  1038,
    1039,  1040,  1942,  1041,   167,   422,   422,  1764,   171,  1042,
    1043,  1044,   172,   173,   174,   175,   176,   309,  1051,   309,
      90,   309,  1085,  1537,  1058,  1059,  1102,  1119,  1501,  1100,
    1120,  1121,  1133,  1134,   179,   180,  1104,  1106,   309,   181,
    1107,  1135,  1065,  1108,   301,  1944,   309,  1131,  1139,   185,
    1140,   503,  1122,  1066,  1169,  1171,   309,  1174,  1179,  1180,
     309,  1067,  1068,  1069,  1182,  1570,  1183,  1070,  1071,  1072,
    1073,  1186,  1194,  1195,  1534,  1196,  1198,  1203,  1220,  1226,
    1227,  1231,  1232,  1234,  1235,  1238,   309,  1239,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,  1248,  1249,  1250,  1251,   442,  1252,  1254,   309,
    1264,  1267,  1269,  1268,  1292,  1282,  1283,  1616,  1284,  1285,
    1286,  1289,  1288,  1290,  1291,  1294,   450,   114,  1293,  1181,
    1295,  1315,  1320,  1630,  1633,  1634,  1321,  1322,   454,   454,
    1324,  1868,  1327,   454,   454,   309,  1329,  1332,  1334,  1946,
     309,  1336,  1337,  1338,  1344,  1345,  1348,   454,  1346,  1347,
    1356,  1370,   141,   142,   143,   144,   145,   146,   147,   148,
    1369,   309,  1386,   152,   153,   154,   155,  1381,  1387,  1388,
    1391,   157,   158,   159,  1396,   309,   160,   318,   453,  1397,
    1398,  1399,  1401,  1403,  1402,  1407,  1408,   165,   280,  1409,
    1410,  1411,  1413,   454,  1414,  1415,  1416,   309,  1752,  1421,
    1755,  1431,  1758,  1422,   309,   309,  1432,  1433,  1439,  1440,
    1766,  1447,  1452,  1769,  1877,   309,  1453,  1454,   309,  1455,
    1470,  1065,  1462,  1472,  1463,  1467,  1473,  1479,  1480,  1485,
     422,  1489,  1066,  1481,   309,  1490,  1503,  1706,  1515,   309,
    1067,  1068,  1069,  1065,  1506,  1509,  1070,  1071,  1072,  1073,
    1514,  1517,   189,  1520,  1066,  1521,  1522,  1523,  1533,  1538,
    1539,  1799,  1067,  1068,  1069,  1803,  1543,  1544,  1070,  1071,
    1072,  1073,  1545,   168,   169,   170,  1548,  1550,  1552,  1551,
    1553,  1554,  1557,  1558,  1559,   177,  1560,   178,    90,   309,
    1561,     7,     8,  1562,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   309,   352,
     353,  1565,   442,  1065,  1578,  1581,  1148,  1584,  1847,  -519,
    1592,  1588,  1849,  1595,  1066,  1599,  1603,  1617,  1948,  1619,
     280,  1622,  1067,  1068,  1069,   337,  1635,  1636,  1070,  1071,
    1072,  1073,  1626,  1637,  1638,  1871,  1639,  1643,  1641,  1642,
    1979,  1644,  1650,  1653,  1657,  1658,  1664,   688,    24,    25,
     689,    27,    28,   690,    30,   691,    32,  1666,    33,  1667,
     309,  1673,   309,    38,    39,  1668,    41,    42,    43,  1674,
    1685,  1676,    46,  1687,  1677,  1679,  1694,   309,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,  1834,  1681,  1700,  1683,   442,  1915,  1916,  1688,
    1705,  1707,  1708,  1709,  1710,  1711,    67,    68,    69,  1712,
    1980,  1725,  1731,  1732,  1718,   410,   411,   412,   414,   416,
    1733,  1734,  1735,  1736,   454,  1738,  1760,  1767,  1778,  1779,
    1786,  1783,   449,  1785,   318,  1801,   456,  1795,   309,  1798,
    1802,  1804,     7,     8,  1818,  1819,  1806,   453,  1831,  1832,
     463,   465,   468,   469,  1822,   471,   465,   473,   474,  1846,
     465,   477,   478,  1851,  1853,  1856,  1857,   465,  1860,  1861,
    1864,  1870,  1878,  1865,   309,  1895,  1909,   874,  1918,  1065,
    1889,  1908,  1921,  1891,  1924,   504,  1893,  1907,  1910,  1927,
    1066,   453,  1929,   453,   513,   514,  1937,  1938,  1067,  1068,
    1069,  1943,  1958,   514,  1070,  1071,  1072,  1073,   688,    24,
      25,   689,    27,    28,   690,    30,   691,    32,  1945,    33,
    1961,  1947,  1963,   453,    38,    39,  1956,    41,    42,    43,
    1965,  1967,  1973,    46,  1988,  1989,   572,   574,   465,  1990,
    1991,  1992,  1993,  1995,  1390,  1836,  1728,    95,   584,   585,
     586,   105,   588,  1405,   730,   760,   591,   592,   593,  1746,
    1516,   594,     0,     0,     0,     0,     0,    67,    68,    69,
       0,     0,     0,     0,  1935,     0,  1835,     0,     0,   611,
     613,     0,     0,     0,     0,     0,  1981,     0,     0,     0,
       0,     0,     0,   620,   621,     0,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,  1972,     0,
    1975,     0,     0,     0,     0,     0,     0,     0,     0,   656,
       0,     0,     0,     0,     0,   662,     0,   664,   875,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1994,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   693,   465,     0,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   704,   705,   706,   707,   708,   709,     0,
       0,   711,   712,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,     0,     0,     0,
     572,   442,     0,   454,     0,     0,   739,     0,  1573,     0,
    1574,   744,     0,     0,     0,     0,   749,   750,     0,     0,
       0,     0,   755,   756,     0,     0,     0,   761,   763,   766,
     769,   772,   774,     0,   776,     0,   778,     0,   465,   465,
       0,     0,     0,     0,  1230,     0,     0,   454,     0,   454,
       0,     0,     0,     0,     0,     0,   796,   797,   798,   410,
     411,   799,     0,     0,     0,   803,   804,   805,   806,   807,
       0,     0,     0,   812,     0,   814,   815,     0,     0,   454,
     465,   465,   465,     0,   479,   822,   823,   824,   825,   826,
       7,     8,   833,   833,     0,     0,   839,     0,     0,     0,
       0,     0,   497,   499,   501,     0,     0,   465,   506,     0,
       0,     0,     0,   854,   856,     0,   858,   859,     7,     8,
       0,     0,  1287,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   536,   465,     0,     0,     0,     0,   825,   826,
       0,   858,   859,     0,     0,     0,     0,     0,     0,     0,
     889,   465,     0,     0,     0,   893,   688,    24,    25,   689,
      27,    28,   690,    30,   691,    32,     0,    33,     0,     0,
       0,     0,    38,    39,     0,    41,    42,    43,     0,     0,
       0,    46,     0,     0,   688,    24,    25,   689,    27,    28,
     690,    30,   691,    32,     0,    33,     0,     0,   608,   609,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
       0,   617,     0,     0,     0,    67,    68,    69,   963,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,     0,     0,     0,     0,   442,     0,     0,
       0,     0,     0,    67,    68,    69,     0,   653,     0,     0,
     990,   991,     0,     0,   465,   997,   998,     0,   465,  1001,
       0,     0,     0,     0,     0,     0,     0,  1008,     7,     8,
     856,  1011,     0,     0,     0,     0,     0,     0,     0,     0,
     467,     0,     0,     0,  1025,   472,  1053,     0,     0,   476,
       0,     0,     0,  1031,     0,     0,   482,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,     0,     0,     0,  1054,   442,     0,     0,   465,     0,
       0,     0,     0,     0,     0,  1056,  1057,     0,     0,     0,
       0,  1060,     0,     0,   688,    24,    25,   689,    27,    28,
     690,    30,   691,    32,  1084,    33,     0,  1086,     7,     8,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,   465,     0,   465,     0,
    1362,   465,     0,     0,     0,     0,     0,     0,     0,     0,
     465,     0,   465,     0,   465,     0,   465,     0,     0,     0,
       0,   465,     0,    67,    68,    69,   465,     0,     0,     0,
       0,     0,  1123,     0,  1125,  1126,     0,     0,     0,     0,
       0,     0,     0,     0,   688,    24,    25,   689,    27,    28,
     690,    30,   691,    32,     0,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
       0,     0,     0,     0,  1151,     0,     0,     0,     0,     0,
       0,     0,  1152,  1153,  1154,     0,   465,     0,     0,     0,
       0,     0,     0,     0,  1077,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    68,    69,  1163,     0,     0,     0,
       0,  1166,     0,     0,     0,     0,     0,     0,     0,     0,
    1170,   694,     0,     0,     0,     0,  1178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   465,   465,   465,   465,
       0,     0,  1192,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   952,     0,     0,     0,   958,     0,     0,     0,
       0,     0,     0,     0,  1124,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,     0,
       0,     0,     0,   442,   465,     0,     0,   780,   781,     0,
       0,     0,     0,     0,  1241,     0,  1243,     0,  1245,     0,
    1247,     0,     0,     0,     0,     0,     0,   688,    24,    25,
     689,    27,    28,   690,    30,   691,    32,     0,    33,     0,
       0,     0,  1266,    38,    39,     0,    41,    42,    43,   817,
     818,   819,    46,     0,     0,  1032,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1296,     0,     0,     0,     0,   851,     0,     0,     0,
    1301,     0,  1302,  1303,  1304,     0,    67,    68,    69,     0,
    1309,     0,     0,     0,     0,  1371,     0,     0,     0,     0,
       0,     0,   873,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1328,     0,     0,     0,     0,  1333,     0,
     890,     0,   688,    24,    25,   689,    27,    28,   690,    30,
     691,    32,     0,    33,     0,     7,     8,     0,    38,    39,
       0,    41,    42,    43,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1130,     0,  1373,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1382,  1383,     0,     0,     0,     0,  1132,     0,     0,     0,
    1136,    67,    68,    69,  1141,  1392,  1394,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   688,    24,    25,   689,    27,    28,   690,    30,   691,
      32,     0,    33,     0,     0,  1236,     0,    38,    39,     0,
      41,    42,    43,   996,     0,  1157,    46,  1000,     0,     0,
       0,     0,  1436,  1437,  1438,     0,     0,     0,     0,     0,
       0,     0,     0,  1449,     0,  1451,     0,     0,     0,     0,
       0,     0,  1255,     0,     0,     0,  1456,     0,     0,     0,
      67,    68,    69,     0,   465,     0,     0,     0,     0,  1468,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,  1050,   442,     0,
       0,     0,  1482,  1483,  1484,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,     0,
       0,  1218,  1219,   442,  1221,     0,  1224,  1225,     0,     0,
    1228,  1229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1820,     0,     0,     0,  1098,     0,  1099,     0,     0,
    1101,     0,     0,  1513,     0,     0,     0,     0,     0,  1109,
       0,  1110,     0,  1111,   466,  1112,     0,  1526,     0,   466,
    1115,     0,  1532,   466,     0,  1118,     0,     0,     0,     0,
     466,     0,     0,     0,     0,  1448,     0,  1540,  1541,     0,
       0,     0,     0,     0,  1546,  1547,     0,     0,     0,  1549,
       0,     0,     0,     0,     0,     0,     0,  1556,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   465,   465,  1568,
       0,  1569,     0,     0,     0,     0,  1312,  1313,  1314,     0,
       0,     0,     0,  1586,     0,  1155,     0,     0,  1323,     0,
       0,     0,     0,     0,     0,     0,   465,     0,     0,   573,
     465,   466,     0,  1601,     0,     0,     0,     0,     0,     0,
    1604,  1605,  1606,  1607,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1615,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1187,  1188,  1189,  1190,     0,
    1632,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1385,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1647,  1648,     0,     0,     0,     0,     0,
       0,  1654,     0,     0,     0,     0,     0,  1406,     0,     0,
       0,     0,     0,  1412,     0,     7,     8,     0,     0,  1417,
       0,  1419,  1420,  1233,     0,     0,  1423,  1424,     0,  1425,
       0,  1426,     0,  1427,     0,  1428,  1429,  1430,     0,  1675,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,  1450,   466,   577,  1689,   442,   572,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1461,
       0,     0,     0,  1465,     0,  1701,     0,  1702,     0,     0,
     465,   688,    24,    25,   689,    27,    28,   690,    30,   691,
      32,     0,    33,   573,  1714,     0,     0,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,     0,     0,
       0,     0,  1720,     0,     0,     0,     0,  1724,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   466,   466,     0,     0,     0,     0,   465,     0,     0,
      67,    68,    69,  1494,  1751,     0,  1754,     0,  1757,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   465,     0,
       0,     0,  1770,  1771,  1772,  1773,  1774,  1524,     0,     0,
       0,     0,     0,   466,   466,   466,     0,     0,     0,     0,
    1536,     0,     0,     0,     0,   834,   836,  1787,  1788,     0,
       0,     0,  1790,     0,     0,     0,     0,     0,     0,     0,
     466,     0,  1498,     0,  1796,     0,     0,   857,     0,     0,
       0,  1898,     0,     0,     0,  1807,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   466,     0,     0,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     578,   440,   441,     0,   466,     0,  1833,   442,     0,  1385,
       0,     0,  1532,     0,     0,     0,     0,     0,     0,     0,
       0,  1844,     0,     0,     0,     0,     0,     0,  1608,     0,
       0,     0,     0,     0,     0,  1855,  1618,     0,  1859,     0,
       0,  1863,     0,  1466,     0,  1866,  1625,     0,     0,   465,
    1629,   465,  1873,  1874,  1875,  1876,     0,     0,     0,     0,
       0,     0,     0,     0,  1881,     0,     0,  1883,     0,     0,
       0,     0,     0,     0,     0,     0,  1649,     0,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,     0,  1385,
       0,     0,     0,     0,     0,     0,     0,   466,     0,     0,
       0,   466,  1914,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   857,  1012,     0,     0,   465,     0,  1930,
    1931,  1932,  1933,     0,     0,  1686,  1602,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,     0,     0,   212,   213,   442,  1640,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1959,  1960,     0,     0,
       0,   466,     0,     0,     0,     0,  1968,  1969,  1970,  1971,
       0,     0,     0,     0,     0,     0,  1566,  1567,     0,     0,
       0,     0,     0,     0,     0,  1672,     0,  1385,     0,     0,
       0,     0,     0,     0,  1729,  1730,     0,     0,     0,     0,
       0,     0,     0,     0,  1704,  1385,     0,     0,     0,   466,
       0,   466,     0,     0,   466,     0,     0,     0,     0,     0,
       0,     0,     0,   466,  1763,   466,     0,   466,     0,   466,
       0,     0,   346,     0,   466,     0,     0,     0,     0,   466,
       0,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,   388,
     389,     0,     0,     0,   393,   394,   395,   396,     0,  1800,
     398,     0,     0,     0,     0,     0,   399,   400,     0,     0,
       0,     0,   405,   406,     0,     0,     0,     0,  1817,   466,
       0,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442,
    1830,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442,
    1896,     0,     0,     0,     0,     0,     0,     0,     0,   466,
     466,   466,   466,     0,     0,     0,     0,     0,     0,  1703,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,  1385,   442,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,     0,     0,     0,     0,   442,     0,     0,
       0,     0,     0,     0,     0,     0,   861,   466,     0,     0,
       0,     0,     0,     0,   555,     0,  1747,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   582,     0,     0,     0,   442,     0,  1768,     0,     0,
       0,     0,  1609,     0,  1610,     0,     0,   897,   898,   899,
     900,   901,   902,   903,   904,   905,   906,   907,     0,   909,
     910,   911,   912,   913,   914,   915,     0,     0,     0,   919,
     921,   922,     0,     0,  1385,   926,   927,  1782,   577,     0,
       0,   932,   933,   934,     0,   936,     0,     0,     0,     0,
       0,     0,   944,   946,     0,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   577,
     969,     0,     0,   442,     0,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,     0,
       0,     0,     0,   442,     0,     0,     0,     0,     0,     0,
       0,     0,   686,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,     0,     0,     0,
       0,   442,     0,     0,     0,   112,   113,   114,  1869,   604,
    1872,   115,   116,   117,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   869,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,     0,     0,
       0,   157,   158,   159,     0,     0,   160,     0,   161,   162,
     163,     0,     0,     0,     0,     0,   164,   165,     0,   976,
       0,     0,     0,     0,     0,     0,  1928,     0,     0,     0,
       0,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   734,   440,   441,     0,     0,   466,     0,   442,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   734,   440,   441,     0,     0,     0,     0,
     442,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   166,     0,     0,     0,   442,
       0,     0,   167,   168,   169,   170,   171,     0,   974,     0,
     172,   173,   174,   175,   176,   177,     0,   178,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   179,   180,     0,     0,     0,   181,     0,     0,
       0,     0,   182,     0,   183,     0,   184,   185,     0,   186,
       0,   187,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,     0,     0,     0,     0,     0,     0,     0,  1191,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     466,   466,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,  1213,  1214,     0,     0,     0,     0,     0,   466,
       0,     0,     0,   466,   112,   292,     0,     0,     0,     0,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   294,  1114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   149,
     150,   151,     0,     0,     0,     0,   156,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,   162,   163,
    1317,     0,     0,     0,     0,   164,     0,     0,     0,   295,
       0,     0,   296,     0,     0,   297,     0,   298,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   299,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1335,
       0,     0,   573,     0,     0,  1339,  1340,  1341,  1342,  1343,
       0,     0,     0,     0,     0,  1350,  1353,     0,     0,  1357,
    1358,  1359,     0,   466,     0,     0,  1363,     0,     0,     0,
       0,   167,     0,     0,     0,   171,     0,  1715,     0,   172,
     173,   174,   175,   176,     0,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   523,  1593,     0,     0,     0,   181,     0,     7,     8,
       0,   525,     0,     0,     0,     0,   185,     0,   259,   575,
     466,     0,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,   466,  1167,  1168,     0,     0,     0,     0,  1172,  1173,
       0,     0,     0,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,     0,     0,     0,
       0,   442,     0,     0,   688,    24,    25,   689,    27,    28,
     690,    30,   691,    32,     0,    33,     0,     0,     0,     0,
      38,    39,  1471,    41,    42,    43,     0,     0,     0,    46,
       0,     0,     0,     0,     0,  1478,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1491,
       0,     0,     0,     0,  1495,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    68,    69,     0,     0,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,  1507,  1508,   442,     0,  1510,  1511,
       0,     0,     0,  1749,     0,  1750,     0,     0,     0,     0,
     112,   292,   466,     0,   466,     0,   115,   116,   117,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   294,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,   150,   151,     0,     0,
       0,     0,   156,     0,     0,     0,  1325,  1326,     0,     0,
       0,  1330,  1331,   161,   162,   163,     0,     0,     0,     0,
       0,   164,     0,     0,     0,   295,     0,     0,   296,     0,
     466,   297,     0,   298,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,     0,  1620,  1621,     0,     0,
    1623,  1624,     0,     0,     0,     0,  1627,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,     0,     0,     0,     0,   442,     0,     0,     0,     0,
       0,     0,     0,     0,  1027,     0,     0,   167,     0,     0,
       0,   171,     0,     0,     0,   172,   173,   174,   175,   176,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   179,   464,     0,
       0,     0,   181,     0,     0,     0,     0,   301,     0,     0,
       0,     0,   185,     0,     0,   575,   112,   292,   114,     0,
       0,     0,   115,   116,   117,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     294,     0,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,     0,
       0,     0,   157,   158,   159,     0,     0,   160,     0,   161,
     162,   163,     0,     0,     0,     0,     0,   164,   165,     0,
       0,   295,     0,     0,   296,     0,     0,   297,     0,   298,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442,
       0,     0,     0,     0,     0,     0,     0,     0,  1080,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,   171,     0,     0,
       0,   172,   173,   174,   175,   176,   177,     0,   178,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,   300,     0,     0,     0,   181,     0,
       0,     0,     0,   301,     0,   112,   292,   114,   185,     0,
     302,   115,   116,   117,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   294,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,     0,     0,
       0,   157,   158,   159,     0,     0,   160,     0,   161,   162,
     163,     0,     0,     0,     0,     0,   164,   165,     0,     0,
     295,     0,     0,   296,     0,     0,   297,     0,   298,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,     0,     0,     0,     0,     0,  1105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,   168,   169,   170,   171,     0,     0,     0,
     172,   173,   174,   175,   176,   177,     0,   178,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   179,   300,     0,     0,     0,   181,     0,     0,
       0,     0,   301,     0,   112,   336,   114,   185,     0,  1628,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     0,     0,     0,
     157,   158,   159,     0,     0,   160,     0,   161,   162,   163,
       0,   112,   336,   114,     0,   164,   165,   115,   116,   117,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,     0,     0,   157,   158,   159,
       0,     0,   160,     0,   161,   162,   163,     0,     0,     0,
       0,     0,   164,   165,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,   171,     0,     0,     0,   172,
     173,   174,   175,   176,   177,     0,   178,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,   180,     0,     0,     0,   181,     0,     0,     0,
       0,   301,     0,     0,     0,     0,   185,     0,  1393,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,     0,     0,     0,     0,   442,   167,   168,
     169,   170,   171,     0,     0,   782,   172,   173,   174,   175,
     176,   177,     0,   178,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,   180,
       0,     0,     0,   181,     0,     0,     0,     0,   301,     0,
     112,   336,   114,   185,     0,  1614,   115,   116,   117,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     0,     0,     0,   157,   158,   159,     0,
       0,   160,     0,   161,   162,   163,     0,     0,     0,     0,
       0,   164,   165,     0,     0,     0,     0,     0,   326,   114,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,     0,     0,     0,     0,     0,  1144,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,     0,     0,     0,   152,   153,   154,   155,     0,
       0,     0,     0,   157,   158,   159,     0,     0,   160,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,     0,     0,     0,   172,   173,   174,   175,   176,
     177,     0,   178,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   179,   180,     0,
       0,     0,   181,     0,     0,     0,     0,   301,     0,   112,
     292,   293,   185,     0,  1631,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   294,     0,   168,   169,   170,     0,     0,
       0,     0,     0,     0,   149,   150,   151,   177,     0,   178,
      90,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   161,   162,   163,     0,     0,     0,     0,     0,
     164,     0,     0,     0,   295,     0,     0,   296,     0,     0,
     297,     0,   298,   450,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,     0,     0,     0,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,     0,     0,     0,
     152,   153,   154,   155,     0,     0,     0,     0,   157,   158,
     159,     0,     0,   160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,     0,   167,     0,     0,     0,
     171,     0,     0,     0,   172,   173,   174,   175,   176,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   179,   300,     0,     0,
       0,   181,     0,     0,     0,     0,   301,     0,   112,   292,
    1459,   185,     0,   302,   115,   116,   117,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   294,     0,     0,     0,     0,     0,     0,     0,
     168,   169,   170,   149,   150,   151,     0,     0,     0,     0,
     156,     0,   177,     0,   178,    90,     0,     0,     0,     0,
       0,   161,   162,   163,     0,     0,     0,     0,     0,   164,
       0,     0,     0,   295,     0,     0,   296,   330,   114,   297,
       0,   298,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   299,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   141,   142,   143,   144,   145,   146,   147,
     148,     0,     0,     0,   152,   153,   154,   155,     0,     0,
       0,     0,   157,   158,   159,     0,     0,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,     0,
       0,     0,     0,     0,     0,   167,     0,     0,     0,   171,
       0,     0,     0,   172,   173,   174,   175,   176,     0,     0,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   179,   300,     0,     0,     0,
     181,     0,     0,     0,     0,   301,     0,   112,   292,     0,
     185,     0,  1460,   115,   116,   117,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   294,     0,     0,   168,   169,   170,     0,     0,     0,
       0,     0,   149,   150,   151,     0,   177,     0,   178,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,   162,   163,     0,     0,     0,     0,     0,   164,     0,
       0,     0,   295,     0,     0,   296,     0,   114,   297,     0,
     298,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   299,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,     0,   152,   153,   154,   155,     0,     0,     0,
       0,   157,   158,   159,     0,     0,   160,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,     0,     0,
       0,     0,     0,     0,   167,     0,     0,     0,   171,     0,
       0,     0,   172,   173,   174,   175,   176,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   179,   300,     0,     0,     0,   181,
       0,     0,     0,     0,   301,     0,   112,   292,     0,   185,
       0,   302,   115,   116,   117,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     294,     0,     0,   168,   169,   170,     0,     0,     0,     0,
       0,   149,   150,   151,     0,   177,     0,   178,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
     162,   163,     0,     0,     0,     0,     0,   164,     0,     0,
       0,   295,     0,     0,   296,     0,     0,   297,     0,   298,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442,
       0,     0,     0,     0,     0,     0,     0,     0,  1259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,     0,     0,     0,   171,     0,     0,
       0,   172,   173,   174,   175,   176,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,   300,     0,     0,     0,   181,     0,
       0,     0,     0,   496,     0,   112,   292,     0,   185,     0,
     302,   115,   116,   117,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   294,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     149,   150,   151,     0,     0,     0,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   161,   162,
     163,     0,     0,     0,     0,     0,   164,     0,     0,     0,
     295,     0,     0,   296,     0,     0,   297,     0,   298,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,     0,     0,     0,     0,     0,  1571,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,     0,     0,     0,   171,     0,     0,     0,
     172,   173,   174,   175,   176,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   179,   300,     0,     0,     0,   181,     0,     0,
       0,     0,   498,     0,   112,   292,     0,   185,     0,   302,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   149,
     150,   151,     0,     0,     0,     0,   156,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,   162,   163,
       0,     0,     0,     0,     0,   164,     0,     0,     0,   295,
       0,     0,   296,     0,     0,   297,     0,   298,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   299,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,     0,     0,     0,     0,   442,     0,     0,
       0,     0,     0,     0,     0,     0,  1590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,     0,     0,     0,   171,     0,     0,     0,   172,
     173,   174,   175,   176,     0,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,   300,     0,     0,     0,   181,     0,     0,     0,
       0,   500,     0,   112,   292,     0,   185,     0,   302,   115,
     116,   117,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   149,   150,
     151,     0,     0,     0,     0,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   161,   162,   163,     0,
       0,     0,     0,     0,   164,     0,     0,     0,   295,     0,
       0,   296,     0,     0,   297,     0,   298,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,     0,     0,
       0,     0,     0,     0,     0,  1659,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,     0,     0,     0,   171,     0,     0,     0,   172,   173,
     174,   175,   176,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     179,   464,     0,     0,     0,   181,     0,     0,     0,     0,
     301,     0,   112,   292,     0,   185,     0,   571,   115,   116,
     117,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   149,   150,   151,
       0,     0,     0,     0,   156,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,   162,   163,     0,     0,
       0,     0,     0,   164,     0,     0,     0,   295,     0,     0,
     296,     0,     0,   297,     0,   298,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   299,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,     0,     0,     0,     0,   442,     0,     0,     0,     0,
       0,     0,     0,     0,  1660,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
       0,     0,     0,   171,     0,     0,     0,   172,   173,   174,
     175,   176,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   179,
     464,     0,     0,     0,   181,     0,     0,     0,     0,   301,
       0,   112,   292,     0,   185,     0,   832,   115,   116,   117,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,   150,   151,     0,
       0,     0,     0,   156,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   161,   162,   163,     0,     0,     0,
       0,     0,   164,     0,     0,     0,   295,     0,     0,   296,
       0,     0,   297,     0,   298,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,     0,     0,     0,     0,
       0,     0,     0,  1661,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,     0,
       0,     0,   171,     0,     0,     0,   172,   173,   174,   175,
     176,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,   464,
       0,     0,     0,   181,     0,     0,     0,     0,   301,     0,
     112,   292,     0,   185,     0,   835,   115,   116,   117,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   294,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,   150,   151,     0,     0,
       0,     0,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   161,   162,   163,     0,     0,     0,     0,
       0,   164,     0,     0,     0,   295,     0,     0,   296,     0,
       0,   297,     0,   298,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,     0,
       0,     0,     0,   442,     0,     0,     0,     0,     0,     0,
       0,     0,  1662,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,     0,     0,
       0,   171,     0,     0,     0,   172,   173,   174,   175,   176,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   179,   464,     0,
       0,     0,   181,     0,     0,     0,     0,   301,     0,   112,
     292,     0,   185,     0,   855,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   294,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   149,   150,   151,     0,     0,     0,
       0,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   161,   162,   163,     0,     0,     0,     0,     0,
     164,     0,     0,     0,   295,     0,     0,   296,     0,     0,
     297,     0,   298,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,     0,     0,     0,     0,     0,     0,
       0,  1663,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,     0,     0,     0,
     171,     0,     0,     0,   172,   173,   174,   175,   176,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   179,   300,     0,     0,
       0,   181,     0,     0,     0,     0,   301,     0,   112,   292,
       0,   185,     0,  1464,   115,   116,   117,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   294,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   149,   150,   151,     0,     0,     0,     0,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,   162,   163,     0,     0,     0,     0,     0,   164,
       0,     0,     0,   295,     0,     0,   296,     0,     0,   297,
       0,   298,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   299,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,     0,     0,     0,
       0,   442,     0,     0,     0,     0,     0,     0,     0,     0,
    1695,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,     0,     0,     0,   171,
       0,     0,     0,   172,   173,   174,   175,   176,     0,     0,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   523,  1593,     0,     0,     0,
     181,     0,     0,     0,     0,   525,     0,   112,   336,     0,
     185,     0,   259,   115,   116,   117,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,   150,   151,     0,     0,     0,     0,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,   162,   163,   112,   336,   114,     0,     0,   164,   115,
     116,   117,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,     0,     0,     0,   157,
     158,   159,     0,     0,   160,     0,   161,   162,   163,     0,
       0,     0,     0,     0,   164,   165,     0,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,     0,     0,     0,   167,   442,     0,   828,   171,   829,
       0,     0,   172,   173,   174,   175,   176,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   523,   524,     0,     0,     0,   181,
       0,     0,     0,     0,   525,     0,     0,     0,     0,   185,
       0,   259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   168,   169,   170,   171,     0,     0,     0,   172,   173,
     174,   175,   176,   177,     0,   178,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     179,   180,     0,     0,     0,   181,   112,   292,     0,     0,
     301,     0,   115,   116,   117,   185,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     294,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   149,   150,   151,     0,     0,     0,     0,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
     162,   163,     0,     0,     0,     0,     0,   164,     0,     0,
       0,   295,     0,     0,   296,     0,     0,   297,     0,   298,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442,
       0,     0,     0,     0,     0,     0,     0,     0,  1765,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,     0,     0,     0,   171,     0,     0,
       0,   172,   173,   174,   175,   176,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,   464,     0,     0,     0,   181,   112,
     336,     0,     0,   301,     0,   115,   116,   117,   185,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   149,   150,   151,     0,     0,     0,
       0,   156,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   336,   161,   162,   163,     0,   115,   116,   117,     0,
     164,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,   150,   151,     0,     0,
       0,     0,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   161,   162,   163,     0,     0,     0,     0,
       0,   164,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,     0,     0,     0,     0,   167,     0,     0,  1775,
     171,     0,     0,     0,   172,   173,   174,   175,   176,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   179,   180,     0,     0,
       0,   181,     0,     0,     0,     0,   301,   413,     0,     0,
       0,   185,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,   167,     0,     0,
     442,   171,     0,     0,   680,   172,   173,   174,   175,   176,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   179,   180,     0,
       0,     0,   181,     0,     0,     0,     0,   301,   112,   336,
     415,     0,   185,     0,   115,   116,   117,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   149,   150,   151,     0,     0,     0,     0,
     156,     0,     0,     0,     0,     0,     0,     0,     0,   112,
     336,   161,   162,   163,     0,   115,   116,   117,     0,   164,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   149,   150,   151,     0,     0,     0,
       0,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   161,   162,   163,     0,     0,     0,     0,     0,
     164,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442,
       0,     0,     0,     0,     0,   167,     0,     0,  1776,   171,
       0,     0,     0,   172,   173,   174,   175,   176,     0,     0,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   179,   180,     0,     0,     0,
     181,     0,     0,     0,     0,   301,   610,     0,     0,     0,
     185,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,   167,     0,     0,   442,
     171,     0,     0,   872,   172,   173,   174,   175,   176,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   179,   180,     0,     0,
       0,   181,     0,     0,     0,     0,   301,   112,   336,   612,
    1265,   185,     0,   115,   116,   117,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,   150,   151,     0,     0,     0,     0,   156,
       0,     0,     0,     0,     0,     0,     0,     0,   112,   336,
     161,   162,   163,     0,   115,   116,   117,     0,   164,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   149,   150,   151,     0,     0,     0,     0,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,   162,   163,     0,     0,     0,     0,     0,   164,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,     0,     0,   167,     0,     0,  1808,   171,     0,
       0,     0,   172,   173,   174,   175,   176,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   179,   180,     0,     0,     0,   181,
       0,     0,     0,     0,   301,     0,    -4,     1,     0,   185,
      -4,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,     0,     0,   167,     0,     0,     0,   171,
       0,     0,     0,   172,   173,   174,   175,   176,     0,     0,
       0,    90,     0,     0,    -4,    -4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   179,   180,     0,     0,     0,
     181,     0,    -4,    -4,    -4,   301,     0,     0,    -4,    -4,
     185,    -4,     0,     0,     0,    -4,    -4,     0,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,    -4,     6,     0,     0,     0,     0,    -4,     0,     0,
       7,     8,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     9,    10,     0,     0,
       0,    -4,    -4,    -4,     0,     0,     0,     0,     0,     0,
      -4,     0,    -4,     0,    11,    12,    13,     0,     0,     0,
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
       0,     0,    89,     0,    90,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,     0,
       0,     0,     0,   442,     0,     0,     0,     0,     0,     0,
       0,     0,  1811,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,     0,     0,     0,
       0,   442,     0,     0,     0,     0,     0,     0,     0,     0,
    1814,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442,
       0,     0,     0,     0,     0,     0,     0,     0,  1845,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,     0,     0,     0,     0,   442,     0,     0,
       0,     0,     0,     0,     0,     0,  1852,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,     0,     0,     0,     0,   442,     0,     0,     0,     0,
       0,     0,     0,     0,  1890,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,     0,
       0,     0,     0,   442,     0,     0,     0,     0,     0,     0,
       0,     0,  1892,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,     0,     0,     0,
       0,   442,     0,     0,     0,     0,     0,     0,     0,     0,
    1894,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442,
       0,     0,     0,     0,     0,     0,     0,     0,  1913,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,     0,     0,     0,     0,   442,     0,     0,
       0,     0,     0,     0,     0,     0,  1939,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,     0,     0,     0,     0,   442,     0,     0,     0,     0,
       0,     0,     0,     0,  1977,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,     0,
       0,     0,     0,   442,     0,     0,     0,     0,     0,     0,
       0,     0,  1978,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,     0,     0,     0,
       0,   442,     0,     0,     0,     0,     0,     0,     0,     0,
    1982,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442,
       0,     0,     0,     0,     0,     0,     0,     0,  1983,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,     0,     0,     0,     0,   442,     0,     0,
       0,     0,     0,     0,     0,     0,  1984,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,     0,     0,     0,     0,   442,     0,     0,     0,     0,
       0,     0,     0,     0,  1985,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,     0,
       0,     0,     0,   442,     0,     0,     0,     0,     0,     0,
       0,  1671,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,   852,     0,     0,     0,     0,   789,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,     0,     0,
       0,     0,     0,   723,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,     0,     0,     0,     0,     0,   789,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,     0,     0,     0,   790,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,     0,     0,     0,     0,
       0,   866,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,     0,     0,     0,     0,     0,   908,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,     0,     0,
       0,     0,     0,   916,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,     0,     0,     0,     0,     0,   917,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,     0,     0,     0,   918,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,     0,     0,     0,     0,
       0,   931,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,     0,     0,     0,     0,     0,  1062,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,     0,     0,
       0,     0,     0,  1063,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,     0,     0,     0,     0,     0,  1064,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,     0,     0,     0,  1095,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,     0,     0,     0,     0,
       0,  1209,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,     0,     0,     0,     0,     0,  1257,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,     0,     0,
       0,     0,     0,  1258,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,     0,     0,     0,     0,     0,  1316,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,     0,     0,     0,  1474,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,     0,     0,     0,     0,
       0,  1475,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,     0,     0,     0,     0,     0,  1476,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,     0,     0,
       0,     0,     0,  1477,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,     0,     0,     0,     0,     0,  1527,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,     0,     0,     0,  1528,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,     0,     0,     0,     0,
       0,  1535,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,     0,     0,     0,     0,     0,  1696,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,     0,     0,
       0,     0,     0,  1697,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,     0,     0,     0,     0,     0,  1698,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,     0,     0,     0,  1699,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,     0,     0,     0,     0,
       0,  1721,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,     0,     0,     0,     0,     0,  1722,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,     0,     0,
       0,     0,     0,  1726,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,     0,     0,     0,     0,     0,  1826,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,     0,     0,     0,  1827,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,     0,     0,     0,     0,
       0,  1828,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,     0,     0,     0,     0,     0,  1829,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,     0,     0,
       0,     0,     0,  1838,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,     0,     0,     0,     0,     0,  1841,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,     0,     0,     0,  1886,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,     0,     0,     0,     0,
       0,  1903,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,     0,     0,     0,     0,     0,  1904,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,     0,     0,
       0,     0,     0,  1905,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,     0,     0,     0,     0,     0,  1906,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,     0,     0,     0,  1950,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,     0,     0,     0,     0,
       0,  1951,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,     0,     0,     0,     0,     0,  1952,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,     0,     0,
       0,     0,     0,  1953,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,     0,     0,   888,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,     0,     0,     0,     0,   442,     0,     0,     0,   895,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,   989,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,     0,     0,     0,
       0,   442,     0,     0,     0,  1088,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,     0,     0,  1089,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,     0,     0,     0,     0,   442,     0,     0,
       0,  1093,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,     0,     0,  1094,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,     0,
       0,     0,     0,   442,     0,     0,     0,  1097,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,     0,     0,
    1117,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442,
       0,     0,     0,  1146,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,     0,     0,  1202,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,     0,     0,     0,     0,   442,     0,     0,     0,  1207,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
       0,     0,  1469,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,     0,     0,     0,
       0,   442,     0,     0,     0,  1518,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,     0,     0,  1684,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,     0,     0,     0,     0,   442,     0,   676,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
     733,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442,
       0,   737,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,   738,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,     0,     0,     0,
       0,   442,     0,   740,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,   742,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,     0,
       0,     0,     0,   442,     0,   743,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,   746,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,     0,     0,     0,     0,   442,     0,   747,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,   852,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,     0,     0,     0,     0,   442,     0,   862,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
     863,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442,
       0,   864,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,   870,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,     0,     0,     0,
       0,   442,     0,   871,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,   884,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,     0,
       0,     0,     0,   442,     0,   894,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,   988,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,     0,     0,     0,     0,   442,     0,  1016,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,  1021,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,     0,     0,     0,     0,   442,     0,  1026,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
    1029,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442,
       0,  1030,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,  1036,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,     0,     0,     0,
       0,   442,     0,  1045,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,  1046,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,     0,
       0,     0,     0,   442,     0,  1047,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,  1079,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,     0,     0,     0,     0,   442,     0,  1081,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,  1082,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,     0,     0,     0,     0,   442,     0,  1083,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
    1087,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442,
       0,  1096,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     442,     0,  1116,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,     0,     0,     0,
       0,   442,     0,  1201,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,     0,     0,
       0,     0,   442,     0,  1206,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,     0,
       0,     0,     0,   442,     0,  1355,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
       0,     0,     0,     0,   442,     0,  1572,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,     0,     0,     0,     0,   442,     0,  1589,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,     0,     0,     0,     0,   442,     0,  1613,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,     0,     0,     0,     0,   442,     0,  1837,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,     0,     0,     0,     0,   442,     0,
    1911,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,     0,     0,     0,   442
};

static const yytype_int16 yycheck[] =
{
       3,     5,   252,     6,     4,     6,   382,     6,   384,     3,
       6,   517,   518,     4,     7,    13,  1074,     4,     6,    49,
      50,   397,    52,     7,     4,     4,   267,     4,     4,     6,
     200,     5,     5,   190,   191,     4,     4,   207,   279,     5,
       5,   111,     4,   142,     4,   190,   191,     4,     4,   206,
       5,     5,     5,     5,    57,     5,     0,     6,  1462,   158,
     159,   206,    65,   208,   413,     6,   415,    70,   417,     4,
    1078,   190,   191,   200,     6,   202,     6,     6,    81,   200,
       7,   202,   190,   191,   190,   191,   101,   206,   209,   208,
       6,     6,   333,    78,   335,     6,    81,   112,   206,    84,
     208,    78,   208,   197,   198,   120,   121,   122,   190,   191,
     204,   126,   127,   128,   129,   200,     6,   202,     6,     4,
       5,   190,   191,     7,   209,   207,   190,   191,   190,   191,
       6,   200,   132,   133,   134,   135,     7,   200,   207,   202,
     200,   145,    84,   207,    86,   207,   209,   207,  1552,   190,
     191,    81,   200,    83,   202,    40,    41,    42,    43,    44,
      45,    46,    47,   197,   198,   206,    51,    52,    53,    54,
       7,   145,   145,   153,    59,    60,    61,    84,   157,    64,
     145,   200,   185,     7,   177,   178,   179,   180,   187,   130,
      75,   187,   186,   208,   197,   198,   176,     7,   130,   200,
     176,   130,   205,   207,   197,   198,   207,   176,   208,   200,
     213,   202,   215,   204,   130,   202,     6,   220,   209,   207,
     204,   224,   209,  1281,   227,   255,   256,   207,   231,   232,
     233,   234,   200,   263,   237,   238,   239,   267,   207,   207,
     200,   207,   245,   246,   247,   207,  1650,   207,   251,   252,
     207,   207,   207,   207,   207,   207,     3,   207,   207,     6,
     200,   610,     7,   612,  1668,   200,     6,   508,   509,     7,
     273,   274,   275,   200,     7,   202,   161,   162,   163,   190,
     191,     4,   212,     4,   287,   288,  1655,   528,   173,    81,
     175,   176,    84,   177,   178,   179,   180,   300,   200,   302,
     190,   191,   190,   191,     7,   207,   177,   178,   179,   180,
      57,     6,    81,   197,   198,    84,   201,   200,   203,     6,
     204,   197,   198,    70,   207,   197,   198,   676,   190,   191,
     203,   680,   200,   206,    81,   207,   339,     4,   341,   342,
     177,   178,   179,   180,   206,   204,   203,   417,   589,   206,
     209,   354,   201,   177,   178,   179,   180,   206,     6,    78,
     197,   198,    81,   604,   206,    84,   208,   177,   178,   179,
     180,   197,   198,   197,   198,   202,   206,   203,   208,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       6,   394,   395,   396,   397,   398,   190,   191,   202,   402,
     403,   404,   405,   406,   407,     8,   409,   200,   197,   198,
      88,    78,   206,   190,   191,    82,   200,   347,   207,   142,
     143,   142,   143,   426,  1793,  1794,   201,    94,   200,   206,
     202,   206,   177,   178,   179,   180,  1840,   209,   185,   177,
     178,   179,   180,     8,   177,   178,   179,   180,     6,     7,
     197,   198,   197,   198,    78,    84,     4,    81,   205,   200,
      84,   464,    86,   339,   190,   191,   213,    84,   190,   191,
     400,   190,   191,   200,   177,   178,   179,   180,   408,   207,
     206,   200,   190,   191,   206,   515,   516,   200,   207,   201,
     232,   233,   234,   523,   206,   237,   238,   239,   206,   502,
     503,   190,   191,    81,   200,   252,    84,   383,    86,   385,
     386,   387,   388,   389,     6,   391,   392,   206,   394,   395,
     396,    84,   398,   517,   518,    84,   402,   403,   404,   405,
     406,   273,   274,  1937,   206,   884,   208,   197,   198,   888,
      86,   544,   545,   546,   785,   287,   288,   207,   206,   206,
     208,   208,   622,   556,   557,   190,   191,   105,   106,   107,
     108,     8,   492,   493,   494,   495,   114,   200,   571,   117,
     201,   206,   203,     6,     7,   578,   207,    81,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   339,   206,   597,   208,   199,   190,   191,   190,
     191,   197,   198,   190,   191,   208,   676,   192,   193,   194,
     680,   207,   615,   206,   199,   206,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     190,   191,   207,   207,   199,   382,   383,   384,   385,   386,
     387,   388,   389,   208,   391,   392,   206,   394,   395,   396,
     397,   398,   190,   191,    84,   402,   403,   404,   405,   406,
     407,    81,   409,   190,   191,   190,   191,    81,   206,   190,
     191,  1679,   675,  1681,    84,  1683,   679,   190,   191,   206,
     200,   206,   202,   190,   191,   206,   101,     4,  1037,   209,
    1039,   201,  1041,   206,  1043,  1753,   206,   112,  1756,   206,
       4,  1759,   190,   191,     4,   120,   121,   122,   190,   191,
       4,   126,   127,   128,   129,   718,   200,   967,   206,   722,
     197,   198,   725,    81,   206,   728,    84,   730,    86,   200,
     207,   734,   735,   200,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   101,   200,
     200,   681,   199,     6,   201,   758,     6,   827,   788,   112,
     202,   101,   190,   191,   201,   795,   203,   120,   121,   122,
     207,   801,   112,   126,   127,   128,   129,   200,   206,   782,
     120,   121,   122,   202,   197,   198,   126,   127,   128,   129,
     201,  1167,  1168,   208,   207,   206,  1172,  1173,   201,   206,
     203,   208,   732,   190,   191,   192,   193,   194,   200,  1867,
     557,   200,   199,  1821,   884,   201,   105,   106,   888,   200,
     206,   202,   111,   204,   894,   895,  1175,   830,   209,   832,
     200,   200,   835,   202,   201,   204,   203,   200,   207,   206,
     209,   844,  1191,   846,   200,   848,   202,   850,   204,   725,
     105,   106,   855,   209,   730,   208,   111,   860,    78,  1917,
       7,    81,  1920,   200,    84,  1923,    86,   201,  1926,   203,
     200,   200,   206,   201,   200,   101,   879,   201,   206,   203,
     883,  1889,   206,  1891,   887,  1893,   112,   206,   201,   208,
     203,  1899,   895,   206,   120,   121,   122,   206,   200,   208,
     126,   127,   128,   129,  1962,   201,  1964,   203,  1966,   201,
     206,   203,   200,   206,   206,   208,   200,   920,   988,   989,
     200,   206,   925,   208,   207,   928,   929,   930,   206,   206,
     208,   208,  1182,  1439,  1440,  1943,   202,  1945,   941,  1947,
     943,   201,   206,   203,   208,   206,   206,   208,   207,  1325,
    1326,    84,     6,    86,  1330,  1331,    84,     6,    86,   206,
     206,   208,   208,   206,   967,   208,   207,   970,   971,   972,
     973,   206,   206,   208,   208,   206,     6,   208,   725,   207,
    1010,   728,   208,   730,   200,   206,  1335,   208,   206,   206,
     208,   208,   995,   206,   206,   208,   208,   206,   206,   208,
     208,   931,   200,   200,    12,    13,   206,   206,   208,   208,
     200,  1014,  1015,   206,  1017,   208,  1019,  1020,   200,   895,
    1023,  1024,   206,   200,   208,  1028,  1096,  1097,     6,     4,
     200,     6,  1062,  1063,  1064,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,  1116,  1117,   200,   925,
     199,   207,   200,   929,   930,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   206,   941,   208,   943,   199,     4,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
     200,    89,   101,   206,   200,   208,    94,    95,   207,    97,
      98,    99,   206,   112,   208,   103,   206,   206,   208,   208,
     207,   120,   121,   122,   206,  1175,   208,   126,   127,   128,
     129,   206,   206,   208,   208,   207,  1119,  1120,  1121,   995,
     206,   206,   208,   208,  1374,   206,   200,   208,  1131,   137,
     138,   139,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   207,   206,   895,   208,
     199,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   207,  1167,  1168,   202,   199,  1674,  1172,
    1173,   206,   206,   208,   208,   206,   200,   208,   925,  1182,
     200,   209,   929,   930,   206,   206,   208,   208,   206,   208,
     208,     6,     6,  1196,   941,   206,   943,   208,   207,   206,
     208,   208,   207,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,  1220,   207,   202,
     967,   199,   206,  1226,   208,   206,   206,   208,   208,  1232,
     202,  1234,  1235,   101,     6,   202,  1239,  1240,   206,  1242,
     208,  1244,     6,  1246,   112,  1248,  1249,  1250,   995,   206,
    1280,   208,   120,   121,   122,  1631,   207,   145,   126,   127,
     128,   129,   209,   206,  1267,   208,     6,  1337,     6,   207,
       6,     6,     6,   207,   207,   202,     4,   199,   204,  1282,
    1210,     7,   207,  1286,   208,  1288,   206,     3,     4,   206,
       7,     6,     6,     9,    10,    11,     6,     6,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     7,  1325,  1326,     7,     6,     6,  1330,  1331,   201,
       6,   207,    48,    49,    50,   101,     7,     6,     6,    55,
     208,  1344,     7,     6,     6,     4,   112,   142,    56,    56,
      66,    67,    68,     6,   120,   121,   122,    56,    74,    56,
     126,   127,   128,   129,   207,   203,   201,     6,     6,   201,
     201,  1374,   206,  1403,   203,     6,   206,  1380,   101,   206,
     206,   206,   206,   201,   201,   201,    40,  1390,    40,   112,
    1393,  1641,  1322,    40,    40,     4,     4,   120,   121,   122,
    1470,     6,     6,   126,   127,   128,   129,     6,     6,   207,
       7,  1441,   145,  1443,     7,  1445,     7,     7,  1348,     7,
    1167,  1168,     7,   145,   145,  1172,  1173,     7,  1431,  1432,
    1460,     7,     4,  1463,  1464,  1182,  1366,     6,   201,   206,
     201,   206,   208,   201,   160,  1439,  1440,  1688,   164,   206,
     201,   206,   168,   169,   170,   171,   172,  1460,   204,  1462,
     176,  1464,     6,  1393,   208,   208,   203,     7,  1344,   201,
       7,     7,     6,    40,   190,   191,   207,   207,  1481,   195,
     207,    40,   101,   207,   200,   208,  1489,   207,    40,   205,
      40,   207,   204,   112,     6,     6,  1499,     6,     6,     6,
    1503,   120,   121,   122,     7,  1435,   202,   126,   127,   128,
     129,     6,   200,   200,  1390,   207,     6,   187,     7,     7,
      86,     7,     7,     7,     7,     6,  1529,     7,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     7,     7,     7,     7,   199,     7,     4,  1552,
       4,   207,   200,     6,    84,     7,     6,  1487,     7,     7,
       7,     6,   207,     6,     6,     6,     4,     5,     7,     6,
       6,     4,     4,  1503,  1504,  1505,     4,   206,  1325,  1326,
     208,  1822,     6,  1330,  1331,  1588,     6,     6,     6,   208,
    1593,     6,     4,     6,   206,   201,   206,  1344,   201,   201,
     201,     7,    40,    41,    42,    43,    44,    45,    46,    47,
     204,  1614,   207,    51,    52,    53,    54,   200,   204,     6,
       6,    59,    60,    61,   201,  1628,    64,  1374,  1631,   203,
       6,     6,   207,    94,   207,     6,   207,    75,  1641,   207,
       6,     6,   207,  1390,     6,     6,     5,  1650,  1678,     4,
    1680,   207,  1682,     6,  1657,  1658,   207,     7,   207,   207,
    1690,   202,     6,  1693,     7,  1668,     6,     6,  1671,     6,
       4,   101,   207,   201,   207,   207,   203,     6,     6,     6,
    1674,   206,   112,   141,  1687,     6,     4,  1617,     4,  1692,
     120,   121,   122,   101,     6,     6,   126,   127,   128,   129,
       6,     6,     6,     6,   112,     6,     6,     6,     4,     7,
       7,  1741,   120,   121,   122,  1745,     6,     6,   126,   127,
     128,   129,     6,   161,   162,   163,     6,     5,   207,     6,
       6,   145,     6,     6,     6,   173,     6,   175,   176,  1742,
       6,    12,    13,     6,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,  1761,   197,
     198,     6,   199,   101,     6,     6,   204,     6,  1798,   207,
       6,   206,  1802,     6,   112,     6,     6,   206,   208,     6,
    1783,     6,   120,   121,   122,    89,     6,     6,   126,   127,
     128,   129,   201,     6,     6,  1825,     6,   204,     7,     6,
     208,     6,   207,     6,   207,   207,     5,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    82,    89,     6,
    1823,     6,  1825,    94,    95,   207,    97,    98,    99,   207,
       6,   208,   103,     7,   208,   207,     6,  1840,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,  1782,   207,   140,   207,   199,  1887,  1888,   207,
       6,   208,     6,     6,     6,     6,   137,   138,   139,     6,
     208,     6,     6,     6,   143,   179,   180,   181,   182,   183,
       6,     6,     6,     6,  1631,   207,     6,     6,   201,     6,
     207,     7,   196,     6,  1641,     6,   200,   207,  1901,   207,
     207,     6,    12,    13,     6,   101,   208,  1910,     6,     6,
     214,   215,   216,   217,   207,   219,   220,   221,   222,     6,
     224,   225,   226,     6,     6,     6,     6,   231,     6,     6,
       6,     6,   200,   208,  1937,     6,     6,   208,     6,   101,
     207,   201,     6,   207,     6,   249,   207,  1877,   207,     6,
     112,  1954,     6,  1956,   258,   259,   207,     6,   120,   121,
     122,   207,     6,   267,   126,   127,   128,   129,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,   207,    89,
       6,   207,     6,  1986,    94,    95,   207,    97,    98,    99,
       6,     6,     6,   103,     6,     6,   300,   301,   302,     6,
       6,     6,     6,     6,  1205,  1786,  1656,     3,   312,   313,
     314,     3,   316,  1219,   460,   490,   320,   321,   322,  1670,
    1370,   325,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,
      -1,    -1,    -1,    -1,  1910,    -1,  1783,    -1,    -1,   343,
     344,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,
      -1,    -1,    -1,   357,   358,    -1,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,  1954,    -1,
    1956,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,
      -1,    -1,    -1,    -1,    -1,   399,    -1,   401,   208,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1986,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   425,   426,    -1,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,    -1,
      -1,   445,   446,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
     464,   199,    -1,  1910,    -1,    -1,   470,    -1,   206,    -1,
     208,   475,    -1,    -1,    -1,    -1,   480,   481,    -1,    -1,
      -1,    -1,   486,   487,    -1,    -1,    -1,   491,   492,   493,
     494,   495,   496,    -1,   498,    -1,   500,    -1,   502,   503,
      -1,    -1,    -1,    -1,     6,    -1,    -1,  1954,    -1,  1956,
      -1,    -1,    -1,    -1,    -1,    -1,   520,   521,   522,   523,
     524,   525,    -1,    -1,    -1,   529,   530,   531,   532,   533,
      -1,    -1,    -1,   537,    -1,   539,   540,    -1,    -1,  1986,
     544,   545,   546,    -1,   227,   549,   550,   551,   552,   553,
      12,    13,   556,   557,    -1,    -1,   560,    -1,    -1,    -1,
      -1,    -1,   245,   246,   247,    -1,    -1,   571,   251,    -1,
      -1,    -1,    -1,   577,   578,    -1,   580,   581,    12,    13,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,   597,    -1,    -1,    -1,    -1,   602,   603,
      -1,   605,   606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     614,   615,    -1,    -1,    -1,   619,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    -1,    -1,
      -1,    -1,    94,    95,    -1,    97,    98,    99,    -1,    -1,
      -1,   103,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    -1,    -1,   341,   342,
      94,    95,    -1,    97,    98,    99,    -1,    -1,    -1,   103,
      -1,   354,    -1,    -1,    -1,   137,   138,   139,   682,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,    -1,   390,    -1,    -1,
     714,   715,    -1,    -1,   718,   719,   720,    -1,   722,   723,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   731,    12,    13,
     734,   735,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     215,    -1,    -1,    -1,   748,   220,   208,    -1,    -1,   224,
      -1,    -1,    -1,   757,    -1,    -1,   231,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,   208,   199,    -1,    -1,   782,    -1,
      -1,    -1,    -1,    -1,    -1,   789,   790,    -1,    -1,    -1,
      -1,   795,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   808,    89,    -1,   811,    12,    13,
      94,    95,    -1,    97,    98,    99,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,   830,    -1,   832,    -1,
       6,   835,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     844,    -1,   846,    -1,   848,    -1,   850,    -1,    -1,    -1,
      -1,   855,    -1,   137,   138,   139,   860,    -1,    -1,    -1,
      -1,    -1,   866,    -1,   868,   869,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    98,    99,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,   908,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   916,   917,   918,    -1,   920,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,   940,    -1,    -1,    -1,
      -1,   945,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     954,   426,    -1,    -1,    -1,    -1,   960,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   970,   971,   972,   973,
      -1,    -1,   976,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   675,    -1,    -1,    -1,   679,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,  1028,    -1,    -1,   502,   503,    -1,
      -1,    -1,    -1,    -1,  1038,    -1,  1040,    -1,  1042,    -1,
    1044,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    -1,  1066,    94,    95,    -1,    97,    98,    99,   544,
     545,   546,   103,    -1,    -1,   758,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1095,    -1,    -1,    -1,    -1,   571,    -1,    -1,    -1,
    1104,    -1,  1106,  1107,  1108,    -1,   137,   138,   139,    -1,
    1114,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,   597,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1137,    -1,    -1,    -1,    -1,  1142,    -1,
     615,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    12,    13,    -1,    94,    95,
      -1,    97,    98,    99,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,  1183,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1194,  1195,    -1,    -1,    -1,    -1,   879,    -1,    -1,    -1,
     883,   137,   138,   139,   887,  1209,  1210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    -1,    -1,   101,    -1,    94,    95,    -1,
      97,    98,    99,   718,    -1,   928,   103,   722,    -1,    -1,
      -1,    -1,  1256,  1257,  1258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1267,    -1,  1269,    -1,    -1,    -1,    -1,
      -1,    -1,   208,    -1,    -1,    -1,  1280,    -1,    -1,    -1,
     137,   138,   139,    -1,  1288,    -1,    -1,    -1,    -1,  1293,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,   782,   199,    -1,
      -1,    -1,  1316,  1317,  1318,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,  1014,  1015,   199,  1017,    -1,  1019,  1020,    -1,    -1,
    1023,  1024,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   208,    -1,    -1,    -1,   830,    -1,   832,    -1,    -1,
     835,    -1,    -1,  1367,    -1,    -1,    -1,    -1,    -1,   844,
      -1,   846,    -1,   848,   215,   850,    -1,  1381,    -1,   220,
     855,    -1,  1386,   224,    -1,   860,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,     6,    -1,  1401,  1402,    -1,
      -1,    -1,    -1,    -1,  1408,  1409,    -1,    -1,    -1,  1413,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1421,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1431,  1432,  1433,
      -1,  1435,    -1,    -1,    -1,    -1,  1119,  1120,  1121,    -1,
      -1,    -1,    -1,  1447,    -1,   920,    -1,    -1,  1131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1460,    -1,    -1,   300,
    1464,   302,    -1,  1467,    -1,    -1,    -1,    -1,    -1,    -1,
    1474,  1475,  1476,  1477,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1487,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   970,   971,   972,   973,    -1,
    1504,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1527,  1528,    -1,    -1,    -1,    -1,    -1,
      -1,  1535,    -1,    -1,    -1,    -1,    -1,  1220,    -1,    -1,
      -1,    -1,    -1,  1226,    -1,    12,    13,    -1,    -1,  1232,
      -1,  1234,  1235,  1028,    -1,    -1,  1239,  1240,    -1,  1242,
      -1,  1244,    -1,  1246,    -1,  1248,  1249,  1250,    -1,  1573,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,  1267,   426,     8,  1591,   199,  1593,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1282,
      -1,    -1,    -1,  1286,    -1,  1609,    -1,  1611,    -1,    -1,
    1614,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,   464,  1628,    -1,    -1,    94,    95,    -1,
      97,    98,    99,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,  1646,    -1,    -1,    -1,    -1,  1651,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   502,   503,    -1,    -1,    -1,    -1,  1671,    -1,    -1,
     137,   138,   139,     6,  1678,    -1,  1680,    -1,  1682,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1692,    -1,
      -1,    -1,  1696,  1697,  1698,  1699,  1700,  1380,    -1,    -1,
      -1,    -1,    -1,   544,   545,   546,    -1,    -1,    -1,    -1,
    1393,    -1,    -1,    -1,    -1,   556,   557,  1721,  1722,    -1,
      -1,    -1,  1726,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     571,    -1,     6,    -1,  1738,    -1,    -1,   578,    -1,    -1,
      -1,   208,    -1,    -1,    -1,  1749,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   597,    -1,    -1,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,   615,    -1,  1780,   199,    -1,  1462,
      -1,    -1,  1786,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1795,    -1,    -1,    -1,    -1,    -1,    -1,  1481,    -1,
      -1,    -1,    -1,    -1,    -1,  1809,  1489,    -1,  1812,    -1,
      -1,  1815,    -1,  1288,    -1,  1819,  1499,    -1,    -1,  1823,
    1503,  1825,  1826,  1827,  1828,  1829,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1838,    -1,    -1,  1841,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1529,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,  1552,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   718,    -1,    -1,
      -1,   722,  1886,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   734,   735,    -1,    -1,  1901,    -1,  1903,
    1904,  1905,  1906,    -1,    -1,  1588,     6,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    21,    22,   199,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1940,  1941,    -1,    -1,
      -1,   782,    -1,    -1,    -1,    -1,  1950,  1951,  1952,  1953,
      -1,    -1,    -1,    -1,    -1,    -1,  1431,  1432,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,  1650,    -1,    -1,
      -1,    -1,    -1,    -1,  1657,  1658,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,  1668,    -1,    -1,    -1,   830,
      -1,   832,    -1,    -1,   835,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   844,  1687,   846,    -1,   848,    -1,   850,
      -1,    -1,   110,    -1,   855,    -1,    -1,    -1,    -1,   860,
      -1,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,    -1,    -1,    -1,   152,   153,   154,   155,    -1,  1742,
     158,    -1,    -1,    -1,    -1,    -1,   164,   165,    -1,    -1,
      -1,    -1,   170,   171,    -1,    -1,    -1,    -1,  1761,   920,
      -1,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
       6,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   970,
     971,   972,   973,    -1,    -1,    -1,    -1,    -1,    -1,  1614,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,  1840,   199,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   582,  1028,    -1,    -1,
      -1,    -1,    -1,    -1,   292,    -1,  1671,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   309,    -1,    -1,    -1,   199,    -1,  1692,    -1,    -1,
      -1,    -1,   206,    -1,   208,    -1,    -1,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,    -1,   635,
     636,   637,   638,   639,   640,   641,    -1,    -1,    -1,   645,
     646,   647,    -1,    -1,  1937,   651,   652,     7,     8,    -1,
      -1,   657,   658,   659,    -1,   661,    -1,    -1,    -1,    -1,
      -1,    -1,   668,   669,    -1,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     8,
     686,    -1,    -1,   199,    -1,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   420,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,    -1,    -1,    -1,     3,     4,     5,  1823,   207,
    1825,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     8,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    64,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,  1901,    -1,    -1,    -1,
      -1,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,  1288,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   153,    -1,    -1,    -1,   199,
      -1,    -1,   160,   161,   162,   163,   164,    -1,   208,    -1,
     168,   169,   170,   171,   172,   173,    -1,   175,   176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   191,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,   200,    -1,   202,    -1,   204,   205,    -1,   207,
      -1,   209,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   975,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1431,  1432,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,  1008,  1009,    -1,    -1,    -1,    -1,    -1,  1460,
      -1,    -1,    -1,  1464,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
       8,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,
      -1,    -1,    81,    -1,    -1,    84,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1145,
      -1,    -1,  1593,    -1,    -1,  1151,  1152,  1153,  1154,  1155,
      -1,    -1,    -1,    -1,    -1,  1161,  1162,    -1,    -1,  1165,
    1166,  1167,    -1,  1614,    -1,    -1,  1172,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,   164,    -1,  1628,    -1,   168,
     169,   170,   171,   172,    -1,    -1,    -1,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,   191,    -1,    -1,    -1,   195,    -1,    12,    13,
      -1,   200,    -1,    -1,    -1,    -1,   205,    -1,   207,   208,
    1671,    -1,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,  1692,   950,   951,    -1,    -1,    -1,    -1,   956,   957,
      -1,    -1,    -1,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    -1,    -1,    -1,    -1,
      94,    95,  1298,    97,    98,    99,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,  1311,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1325,
      -1,    -1,    -1,    -1,  1330,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,    -1,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,  1360,  1361,   199,    -1,  1364,  1365,
      -1,    -1,    -1,   206,    -1,   208,    -1,    -1,    -1,    -1,
       3,     4,  1823,    -1,  1825,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,  1134,  1135,    -1,    -1,
      -1,  1139,  1140,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,
    1901,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,
      -1,   114,    -1,    -1,   117,    -1,  1492,  1493,    -1,    -1,
    1496,  1497,    -1,    -1,    -1,    -1,  1502,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,    -1,    -1,   160,    -1,    -1,
      -1,   164,    -1,    -1,    -1,   168,   169,   170,   171,   172,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,   205,    -1,    -1,   208,     3,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,
      -1,    78,    -1,    -1,    81,    -1,    -1,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,    -1,    -1,    -1,    -1,   114,    -1,    -1,
     117,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,    -1,    -1,
      -1,   168,   169,   170,   171,   172,   173,    -1,   175,   176,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,   200,    -1,     3,     4,     5,   205,    -1,
     207,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    64,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      78,    -1,    -1,    81,    -1,    -1,    84,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,    -1,    -1,    -1,
     168,   169,   170,   171,   172,   173,    -1,   175,   176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   191,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,   200,    -1,     3,     4,     5,   205,    -1,   207,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    64,    -1,    66,    67,    68,
      -1,     3,     4,     5,    -1,    74,    75,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    59,    60,    61,
      -1,    -1,    64,    -1,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,    -1,   175,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,   191,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,   200,    -1,    -1,    -1,    -1,   205,    -1,   207,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,   199,   160,   161,
     162,   163,   164,    -1,    -1,   207,   168,   169,   170,   171,
     172,   173,    -1,   175,   176,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,   200,    -1,
       3,     4,     5,   205,    -1,   207,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    64,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,     4,     5,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,    -1,    -1,    -1,   168,   169,   170,   171,   172,
     173,    -1,   175,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,   200,    -1,     3,
       4,     5,   205,    -1,   207,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,   161,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,   173,    -1,   175,
     176,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,
      84,    -1,    86,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,
     114,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,   160,    -1,    -1,    -1,
     164,    -1,    -1,    -1,   168,   169,   170,   171,   172,    -1,
      -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,   200,    -1,     3,     4,
       5,   205,    -1,   207,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   163,    48,    49,    50,    -1,    -1,    -1,    -1,
      55,    -1,   173,    -1,   175,   176,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,     4,     5,    84,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,
      -1,    -1,   117,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,   164,
      -1,    -1,    -1,   168,   169,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,   200,    -1,     3,     4,    -1,
     205,    -1,   207,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,   173,    -1,   175,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    78,    -1,    -1,    81,    -1,     5,    84,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,    -1,
      -1,   117,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,   164,    -1,
      -1,    -1,   168,   169,   170,   171,   172,    -1,    -1,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,   200,    -1,     3,     4,    -1,   205,
      -1,   207,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,   161,   162,   163,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,   173,    -1,   175,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    78,    -1,    -1,    81,    -1,    -1,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,    -1,    -1,    -1,    -1,   114,    -1,    -1,
     117,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,   164,    -1,    -1,
      -1,   168,   169,   170,   171,   172,    -1,    -1,    -1,   176,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,   200,    -1,     3,     4,    -1,   205,    -1,
     207,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      78,    -1,    -1,    81,    -1,    -1,    84,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,    -1,    -1,    -1,   164,    -1,    -1,    -1,
     168,   169,   170,   171,   172,    -1,    -1,    -1,   176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   191,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,   200,    -1,     3,     4,    -1,   205,    -1,   207,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,
      -1,    -1,    81,    -1,    -1,    84,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,   164,    -1,    -1,    -1,   168,
     169,   170,   171,   172,    -1,    -1,    -1,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,   191,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,   200,    -1,     3,     4,    -1,   205,    -1,   207,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,
      -1,    81,    -1,    -1,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,
      -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,    -1,    -1,    -1,   164,    -1,    -1,    -1,   168,   169,
     170,   171,   172,    -1,    -1,    -1,   176,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   191,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
     200,    -1,     3,     4,    -1,   205,    -1,   207,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,
      81,    -1,    -1,    84,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,    -1,
      -1,    -1,    -1,   114,    -1,    -1,   117,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,   164,    -1,    -1,    -1,   168,   169,   170,
     171,   172,    -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
     191,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,   200,
      -1,     3,     4,    -1,   205,    -1,   207,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,   114,    -1,    -1,   117,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,
      -1,    -1,   164,    -1,    -1,    -1,   168,   169,   170,   171,
     172,    -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,   200,    -1,
       3,     4,    -1,   205,    -1,   207,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,
      -1,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,
      -1,   114,    -1,    -1,   117,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,   164,    -1,    -1,    -1,   168,   169,   170,   171,   172,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,   200,    -1,     3,
       4,    -1,   205,    -1,   207,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,
      84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,
     114,    -1,    -1,   117,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,
     164,    -1,    -1,    -1,   168,   169,   170,   171,   172,    -1,
      -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,   200,    -1,     3,     4,
      -1,   205,    -1,   207,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,
      -1,    -1,   117,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,   164,
      -1,    -1,    -1,   168,   169,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,   200,    -1,     3,     4,    -1,
     205,    -1,   207,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,     3,     4,     5,    -1,    -1,    74,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    59,
      60,    61,    -1,    -1,    64,    -1,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    74,    75,    -1,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,   160,   199,    -1,   201,   164,   203,
      -1,    -1,   168,   169,   170,   171,   172,    -1,    -1,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,   205,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,    -1,   175,   176,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   191,    -1,    -1,    -1,   195,     3,     4,    -1,    -1,
     200,    -1,     9,    10,    11,   205,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    78,    -1,    -1,    81,    -1,    -1,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,    -1,    -1,    -1,    -1,   114,    -1,    -1,
     117,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,   164,    -1,    -1,
      -1,   168,   169,   170,   171,   172,    -1,    -1,    -1,   176,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,     3,
       4,    -1,    -1,   200,    -1,     9,    10,    11,   205,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    66,    67,    68,    -1,     9,    10,    11,    -1,
      74,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    74,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,   208,
     164,    -1,    -1,    -1,   168,   169,   170,   171,   172,    -1,
      -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,   200,   201,    -1,    -1,
      -1,   205,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,   160,    -1,    -1,
     199,   164,    -1,    -1,   203,   168,   169,   170,   171,   172,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,   200,     3,     4,
     203,    -1,   205,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    66,    67,    68,    -1,     9,    10,    11,    -1,    74,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,   208,   164,
      -1,    -1,    -1,   168,   169,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,   200,   201,    -1,    -1,    -1,
     205,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,   160,    -1,    -1,   199,
     164,    -1,    -1,   203,   168,   169,   170,   171,   172,    -1,
      -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,   200,     3,     4,   203,
       6,   205,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      66,    67,    68,    -1,     9,    10,    11,    -1,    74,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,   160,    -1,    -1,   208,   164,    -1,
      -1,    -1,   168,   169,   170,   171,   172,    -1,    -1,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,   200,    -1,     0,     1,    -1,   205,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,   164,
      -1,    -1,    -1,   168,   169,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,
     195,    -1,    56,    57,    58,   200,    -1,    -1,    62,    63,
     205,    65,    -1,    -1,    -1,    69,    70,    -1,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
     124,   125,     4,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      12,    13,   136,   137,   138,   139,    -1,    -1,   142,    -1,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    38,    39,    -1,    -1,
      -1,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,
     174,    -1,   176,    -1,    56,    57,    58,    -1,    -1,    -1,
      62,    63,    -1,    65,    -1,    -1,    -1,    69,    70,    -1,
      72,    73,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,   136,   137,   138,   139,    -1,    -1,
     142,    -1,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,    -1,   174,    -1,   176,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,   201,    -1,    -1,    -1,    -1,   206,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,   206,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,   206,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,   206,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,   206,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,   206,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,   206,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,   206,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,   206,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,   206,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,   206,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,   206,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,   206,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,   206,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,   206,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,   206,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,   206,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,   206,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,   206,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,   203,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,   203,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,   203,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,    -1,    -1,    -1,   203,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,   203,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,
      -1,   203,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,   203,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,    -1,    -1,    -1,   203,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
     203,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
      -1,    -1,    -1,   203,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,   203,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,   203,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,   203,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,    -1,    -1,    -1,   203,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,   203,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,   201,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
     201,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
      -1,   201,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,   201,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,    -1,   201,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,   201,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,    -1,   201,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,   201,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,    -1,   201,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,   201,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,   201,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
     201,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
      -1,   201,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,   201,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,    -1,   201,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,   201,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,    -1,   201,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,   201,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,    -1,   201,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,   201,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,   201,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
     201,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
      -1,   201,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,   201,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,    -1,   201,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,   201,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,    -1,   201,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,   201,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,    -1,   201,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,   201,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,   201,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
     201,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,
      -1,   201,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,    -1,   201,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,   199,    -1,   201,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,    -1,   201,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,    -1,   201,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,   199,    -1,   201,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,   199,    -1,   201,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,    -1,   201,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,   201,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,    -1,
     201,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,   199
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   211,   212,     6,     0,     4,    12,    13,    38,
      39,    56,    57,    58,    62,    63,    65,    69,    70,    72,
      73,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   112,   113,   114,   115,   116,   117,
     118,   119,   123,   124,   125,   131,   136,   137,   138,   139,
     142,   144,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   165,   166,   167,   174,
     176,   213,   215,   216,   236,   255,   256,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   288,   289,   290,   291,
     309,   310,     3,     4,     5,     9,    10,    11,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    59,    60,    61,
      64,    66,    67,    68,    74,    75,   153,   160,   161,   162,
     163,   164,   168,   169,   170,   171,   172,   173,   175,   190,
     191,   195,   200,   202,   204,   205,   207,   209,   234,   292,
     293,   305,   306,   309,   310,    13,    84,   200,   200,     6,
     207,     6,     6,     6,     6,   200,     6,     6,   202,   202,
     200,   202,   234,   234,   200,   207,   200,   200,     4,   200,
     207,   200,   200,     4,   207,   200,   200,    88,    84,    84,
       6,   207,    78,    81,    84,    84,    84,    81,    84,    86,
      86,    78,    81,    84,    86,    81,    84,    86,    81,    84,
     200,    81,   142,   158,   159,   207,   190,   191,   200,   207,
     295,   296,   295,   207,    78,    81,    84,   207,   295,     4,
      78,    82,    94,    84,    86,    84,    81,     4,   153,   207,
     309,   310,     4,     6,    78,    81,    84,    81,    84,     4,
       4,     4,     4,     5,    37,    78,    81,    84,    86,    98,
     191,   200,   207,   256,   267,   292,   298,   299,   300,   309,
     310,     4,   200,   200,   200,     4,   207,   302,   310,     4,
     200,   200,   200,     6,     6,   202,     4,   306,   310,   200,
       4,   306,     5,   207,     5,   207,     4,   292,   309,   202,
       6,   200,   207,   200,   202,   209,   234,     7,   177,   178,
     179,   180,   197,   198,   232,   233,     4,   200,   202,   204,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   200,   200,   200,   234,   234,
     200,   200,   200,   234,   234,   234,   234,   200,   234,   234,
     234,     7,   200,   200,   200,   234,   234,   200,   200,   202,
     292,   292,   292,   201,   292,   203,   292,     4,   142,   143,
     310,     4,   256,   257,   258,   207,   207,     6,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   199,   207,     6,   200,   202,   233,     6,   292,
       4,   305,   306,   309,   310,   305,   292,   305,   308,   238,
     243,   306,   310,   292,   191,   292,   300,   301,   292,   292,
     200,   292,   301,   292,   292,   200,   301,   292,   292,   298,
     200,   207,   301,   299,   299,   299,   200,   200,   299,   299,
     299,   200,   200,   200,   200,   200,   200,   298,   200,   298,
     200,   298,   207,   207,   292,     4,   298,   302,   207,   207,
     295,   295,   295,   292,   292,   190,   191,   207,   207,   295,
     207,   207,   207,   190,   191,   200,   258,   295,   207,   200,
     207,   200,   200,   200,   299,   299,   298,   200,     4,   202,
     202,   258,     6,     6,   207,   207,   207,   299,   299,   202,
     202,   202,   200,   202,   204,   234,   200,   202,     5,   145,
     207,     5,   145,     5,   145,     5,   145,    78,    81,    84,
      86,   207,   292,   300,   292,   208,   301,     8,   192,     6,
     200,   202,   234,     6,   292,   292,   292,   204,   292,   207,
     145,   292,   292,   292,   292,     6,     6,   207,     6,   258,
       6,   258,   200,   202,   207,   200,   202,   305,   298,   298,
     201,   292,   203,   292,   207,   207,   306,   298,     6,   202,
     292,   292,     4,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   308,   305,   308,   305,   305,
     305,   305,   305,   298,   305,   305,   292,   305,   305,   305,
     308,   305,   292,   306,   292,   305,   305,   305,   305,   305,
     310,   306,   310,     7,   180,   232,   201,     7,   180,   232,
     203,     7,   232,   233,   204,     7,   234,   208,    78,    81,
      84,    86,   255,   292,   301,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     217,   292,   292,     6,   200,   202,   204,   201,   206,   200,
     202,   201,   206,   206,   201,   206,   203,   206,   237,   203,
     237,   206,   206,   201,   192,   206,   208,   201,   201,   292,
     201,   208,   201,   201,   292,   208,   201,   201,     7,   292,
     292,   208,     6,     6,     6,   292,   292,     7,     7,   285,
     285,   292,   249,   292,   306,   250,   292,   306,   251,   292,
     306,   252,   292,   306,   292,     6,   292,     6,   292,     6,
     301,   301,   207,   201,     6,   207,   258,   258,   206,   206,
     206,   295,   295,   257,   257,   206,   292,   292,   292,   292,
     271,   206,   258,   292,   292,   292,   292,   292,     7,   286,
       6,     7,   292,     6,   292,   292,   208,   301,   301,   301,
       6,     6,   292,   292,   292,   292,   292,     4,   201,   203,
     207,   235,   207,   292,   300,   207,   300,   310,    56,   292,
      56,    56,    56,     5,   207,     5,   207,     5,   207,     5,
     207,   301,   201,   208,   292,   207,   292,   300,   292,   292,
     207,   235,   201,   201,   201,   142,   206,   258,   207,     8,
     201,   201,   203,   301,   208,   208,   258,   203,   201,   206,
     208,     7,   180,   232,   201,     7,   180,   232,   203,   292,
     301,     6,     6,   292,   201,   203,   233,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   206,   235,
     235,   235,   235,   235,   235,   235,   206,   206,   206,   235,
     206,   235,   235,   201,   201,   206,   235,   235,   206,   206,
     206,   206,   235,   235,   235,   201,   235,   294,   307,     6,
     206,   206,   201,   206,   235,   206,   235,   201,   201,   203,
      40,    40,   298,     7,   232,   233,    40,    40,   298,   204,
     232,   233,   306,   292,     6,     4,     4,   207,   303,   235,
     207,   207,   207,   207,   208,   208,     8,     4,   132,   133,
     134,   135,   208,   220,   224,   227,   229,   230,   201,   203,
     292,   292,     4,     6,   187,   214,   301,   292,   292,     6,
     301,   292,     6,   305,     6,   310,     6,   305,   292,   306,
       7,   292,   300,   145,     7,     7,   201,     7,   145,     7,
       7,   201,   145,     7,     7,   292,   201,   208,   207,   201,
     201,   292,   298,     4,   284,     6,   201,   201,   206,   201,
     206,   201,   206,   201,   206,   201,   201,   201,   208,   208,
     301,   204,   258,   208,   208,   295,   292,   292,   208,   208,
     292,   295,   206,   206,   206,   101,   112,   120,   121,   122,
     126,   127,   128,   129,   281,   282,   295,   208,   268,   201,
     208,   201,   201,   201,   292,     6,   292,   201,   203,   203,
     208,   208,   208,   203,   203,   206,   201,   203,   301,   301,
     201,   301,   203,   203,   207,   208,   207,   207,   207,   301,
     301,   301,   301,   208,     8,   301,   201,   203,   301,     7,
       7,     7,   204,   292,   208,   292,   292,     7,   204,   208,
     208,   207,   298,     6,    40,    40,   298,   232,   233,    40,
      40,   298,   232,   233,   208,   208,   203,   233,   204,   233,
     305,   292,   292,   292,   292,   301,   305,   298,   305,   305,
     306,   245,   247,   292,   305,   305,   292,   234,   234,     6,
     292,     6,   234,   234,     6,     4,   142,   143,   292,     6,
       6,     6,     7,   202,   302,   304,     6,   301,   301,   301,
     301,   235,   292,   221,   200,   200,   207,   231,     6,   233,
     233,   201,   203,   187,   305,   201,   201,   203,   201,   206,
       7,   200,   202,   235,   235,   295,    84,    86,   298,   298,
       7,   298,    84,    86,   298,   298,     7,    86,   298,   298,
       6,     7,     7,   301,     7,     7,   101,   283,     6,     7,
     232,   292,   232,   292,   232,   292,   232,   292,     7,     7,
       7,     7,     7,   208,     4,   208,   206,   206,   206,   208,
     208,   295,   295,   295,     4,     6,   292,   207,     6,   200,
       6,   130,     6,   130,     6,   130,     6,   130,   208,   282,
     206,   281,     7,     6,     7,     7,     7,     6,   207,     6,
       6,     6,    84,     7,     6,     6,   292,   204,   208,   208,
     208,   292,   292,   292,   292,   208,   208,   208,   208,   292,
     208,   208,   298,   298,   298,     4,   206,     8,     8,   201,
       4,     4,   206,   298,   208,   234,   234,     6,   292,     6,
     234,   234,     6,   292,     6,   235,     6,     4,     6,   235,
     235,   235,   235,   235,   206,   201,   201,   201,   206,   206,
     235,   246,   206,   235,   248,   201,   201,   235,   235,   235,
     308,   308,     6,   235,   308,   308,     7,   232,   233,   204,
       7,     6,   302,   292,   206,   208,   208,   208,   208,   208,
     232,   200,   292,   292,   297,   298,   207,   204,     6,     6,
     214,     6,   292,   207,   292,   306,   201,   203,     6,     6,
       6,   207,   207,    94,   254,   254,   298,     6,   207,   207,
       6,     6,   298,   207,     6,     6,     5,   298,   208,   298,
     298,     4,     6,   298,   298,   298,   298,   298,   298,   298,
     298,   207,   207,     7,     6,     7,   292,   292,   292,   207,
     207,   206,   208,   206,   208,   206,   208,   202,     6,   292,
     298,   292,     6,     6,     6,     6,   292,   295,   208,     5,
     207,   298,   207,   207,   207,   298,   301,   207,   292,   203,
       4,   235,   201,   203,   206,   206,   206,   206,   235,     6,
       6,   141,   292,   292,   292,     6,     6,     7,   306,   206,
       6,   235,   308,   308,     6,   235,   308,   308,     6,   232,
     233,   305,   306,     4,     4,   157,     6,   235,   235,     6,
     235,   235,   306,   292,     6,     4,   303,     6,   203,   302,
       6,     6,     6,     6,   298,   218,   292,   206,   206,   206,
     208,   219,   292,     4,   305,   206,   298,   306,     7,     7,
     292,   292,   295,     6,     6,     6,   292,   292,     6,   292,
       5,     6,   207,     6,   145,   253,   292,     6,     6,     6,
       6,     6,     6,     4,     6,     6,   301,   301,   292,   292,
     306,   208,   201,   206,   208,   257,   257,   295,     6,   272,
     295,     6,   273,   295,     6,   274,   292,   208,   206,   201,
     208,   206,     6,   191,   295,     6,   297,   295,   295,     6,
     208,   292,     6,     6,   292,   292,   292,   292,   298,   206,
     208,     8,   208,   201,   207,   292,   306,   206,   298,     6,
     235,   235,     6,   235,   235,   298,   201,   235,   207,   298,
     306,   207,   292,   306,   306,     6,     6,     6,     6,     6,
       6,     7,     6,   204,     6,   201,   206,   292,   292,   298,
     207,   206,   208,     6,   292,   239,   242,   207,   207,   208,
     208,   208,   208,   208,     5,   297,    82,     6,   207,   208,
     208,   207,     6,     6,   207,   292,   208,   208,   206,   207,
     206,   207,   206,   207,   203,     6,   298,     7,   207,   292,
     206,   208,   206,   206,     6,   208,   206,   206,   206,   206,
     140,   292,   292,   301,     6,     6,   306,   208,     6,     6,
       6,     6,     6,   244,   292,   300,   308,   302,   143,   222,
     292,   206,   206,   297,   292,     6,   206,   245,   247,   298,
     298,     6,     6,     6,     6,     6,     6,   208,   207,   297,
     105,   106,   111,   287,   105,   106,   287,   301,   257,   206,
     208,   292,   295,   281,   292,   295,   281,   292,   295,   281,
       6,   206,   208,   298,   258,   208,   295,     6,   301,   295,
     292,   292,   292,   292,   292,   208,   208,   208,   201,     6,
     206,   208,     7,     7,   208,     6,   207,   292,   292,   208,
     292,   208,   208,   241,   240,   207,   292,   208,   207,   295,
     298,     6,   207,   295,     6,   208,   208,   292,   208,   206,
     208,   208,   206,   208,   208,   206,   208,   298,     6,   101,
     208,   269,   207,   206,   208,   206,   206,   206,   206,   206,
       6,     6,     6,   292,   306,   310,   219,   201,   206,     6,
     207,   206,   245,   245,   292,   208,     6,   295,     6,   295,
       6,     6,   208,     6,   275,   292,     6,     6,   276,   292,
       6,     6,   277,   292,     6,   208,   292,   281,   258,   301,
       6,   295,   301,   292,   292,   292,   292,     7,   200,   208,
     225,   292,   297,   292,   208,   208,   206,   206,   206,   207,
     208,   207,   208,   207,   208,     6,     6,   208,   208,   270,
     208,   206,   208,   206,   206,   206,   206,   306,   201,     6,
     207,   201,   208,   208,   292,   295,   295,   281,     6,   278,
     281,     6,   279,   281,     6,   280,   281,     6,   301,     6,
     292,   292,   292,   292,   223,   305,   228,   207,     6,   208,
     206,   206,   208,   207,   208,   207,   208,   207,   208,   208,
     206,   206,   206,   206,   206,   208,   207,   297,     6,   292,
     292,     6,   281,     6,   281,     6,   281,     6,   292,   292,
     292,   292,   305,     6,   226,   305,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   206,   208,     6,     6,
       6,     6,     6,     6,   305,     6
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
	  std::list<int> vl = option->list();
	  vl.clear();
	  for(int i = 0; i < List_Nbr((yyvsp[(9) - (11)].l)); i++){
	    double id;
	    List_Read((yyvsp[(9) - (11)].l), i, &id);
	    vl.push_back((int)id);
	  }
          option->list(vl);
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
#line 1314 "Gmsh.y"
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
#line 1335 "Gmsh.y"
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
#line 1347 "Gmsh.y"
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
#line 1365 "Gmsh.y"
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
#line 1374 "Gmsh.y"
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
#line 1383 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 128:
#line 1385 "Gmsh.y"
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
#line 1403 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 130:
#line 1405 "Gmsh.y"
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
#line 1421 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 132:
#line 1423 "Gmsh.y"
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
#line 1439 "Gmsh.y"
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
#line 1448 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 135:
#line 1450 "Gmsh.y"
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
#line 1464 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 138:
#line 1472 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 139:
#line 1478 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 140:
#line 1483 "Gmsh.y"
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
#line 1514 "Gmsh.y"
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
#line 1525 "Gmsh.y"
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
#line 1540 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 148:
#line 1556 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 149:
#line 1564 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 150:
#line 1573 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 151:
#line 1581 "Gmsh.y"
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
#line 1599 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 153:
#line 1603 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 154:
#line 1609 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 155:
#line 1617 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 156:
#line 1621 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 157:
#line 1627 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 158:
#line 1635 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 159:
#line 1639 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 160:
#line 1645 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 161:
#line 1653 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 162:
#line 1657 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 163:
#line 1663 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 164:
#line 1671 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 165:
#line 1675 "Gmsh.y"
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
#line 1687 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 167:
#line 1691 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 168:
#line 1701 "Gmsh.y"
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
#line 1724 "Gmsh.y"
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
#line 1767 "Gmsh.y"
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
#line 1790 "Gmsh.y"
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
#line 1808 "Gmsh.y"
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
#line 1829 "Gmsh.y"
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
#line 1847 "Gmsh.y"
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
#line 1877 "Gmsh.y"
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
#line 1907 "Gmsh.y"
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
#line 1925 "Gmsh.y"
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
#line 1944 "Gmsh.y"
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
#line 1970 "Gmsh.y"
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
#line 1989 "Gmsh.y"
    {
     GModel::current()->getGEOInternals()->addCompoundMesh ( 1 , (yyvsp[(3) - (4)].l) );
   ;}
    break;

  case 181:
#line 1994 "Gmsh.y"
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
#line 2012 "Gmsh.y"
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
#line 2058 "Gmsh.y"
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
#line 2076 "Gmsh.y"
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
#line 2115 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 186:
#line 2121 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 187:
#line 2127 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 188:
#line 2134 "Gmsh.y"
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
#line 2159 "Gmsh.y"
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
#line 2184 "Gmsh.y"
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
#line 2201 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 2 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 192:
#line 2205 "Gmsh.y"
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
#line 2225 "Gmsh.y"
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
#line 2258 "Gmsh.y"
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
#line 2305 "Gmsh.y"
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
#line 2323 "Gmsh.y"
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
#line 2340 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 3 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 198:
#line 2344 "Gmsh.y"
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
#line 2360 "Gmsh.y"
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
#line 2408 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 201:
#line 2413 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 202:
#line 2418 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 203:
#line 2423 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 204:
#line 2428 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 205:
#line 2433 "Gmsh.y"
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
#line 2456 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 207:
#line 2462 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 208:
#line 2472 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 209:
#line 2473 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 210:
#line 2478 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 211:
#line 2482 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 212:
#line 2486 "Gmsh.y"
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
#line 2509 "Gmsh.y"
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
#line 2532 "Gmsh.y"
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
#line 2555 "Gmsh.y"
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
#line 2583 "Gmsh.y"
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
#line 2604 "Gmsh.y"
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
#line 2631 "Gmsh.y"
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
#line 2652 "Gmsh.y"
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
#line 2673 "Gmsh.y"
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
#line 2693 "Gmsh.y"
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
#line 2805 "Gmsh.y"
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
#line 2824 "Gmsh.y"
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
#line 2863 "Gmsh.y"
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
#line 2971 "Gmsh.y"
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
#line 2980 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 227:
#line 2986 "Gmsh.y"
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
#line 3001 "Gmsh.y"
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
#line 3029 "Gmsh.y"
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
#line 3046 "Gmsh.y"
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
#line 3055 "Gmsh.y"
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
#line 3069 "Gmsh.y"
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
#line 3083 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 234:
#line 3089 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 235:
#line 3095 "Gmsh.y"
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
#line 3104 "Gmsh.y"
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
#line 3113 "Gmsh.y"
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
#line 3122 "Gmsh.y"
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
#line 3136 "Gmsh.y"
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
#line 3198 "Gmsh.y"
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
#line 3216 "Gmsh.y"
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
#line 3233 "Gmsh.y"
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
#line 3248 "Gmsh.y"
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
#line 3277 "Gmsh.y"
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
#line 3289 "Gmsh.y"
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
#line 3313 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 247:
#line 3317 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 248:
#line 3322 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 249:
#line 3329 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 250:
#line 3334 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 251:
#line 3340 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 252:
#line 3345 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 253:
#line 3351 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 254:
#line 3359 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 255:
#line 3363 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 256:
#line 3367 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 257:
#line 3373 "Gmsh.y"
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
#line 3432 "Gmsh.y"
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
#line 3448 "Gmsh.y"
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
#line 3465 "Gmsh.y"
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
#line 3482 "Gmsh.y"
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
#line 3504 "Gmsh.y"
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
#line 3526 "Gmsh.y"
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
#line 3561 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 265:
#line 3569 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 266:
#line 3577 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 267:
#line 3583 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 268:
#line 3590 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 269:
#line 3597 "Gmsh.y"
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
#line 3617 "Gmsh.y"
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
#line 3643 "Gmsh.y"
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
#line 3655 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 273:
#line 3667 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 274:
#line 3675 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 275:
#line 3683 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 276:
#line 3691 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 277:
#line 3697 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 278:
#line 3705 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 279:
#line 3711 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 280:
#line 3719 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 281:
#line 3725 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 282:
#line 3733 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 283:
#line 3739 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 284:
#line 3747 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 285:
#line 3754 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 286:
#line 3761 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 287:
#line 3768 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 288:
#line 3775 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 289:
#line 3782 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 290:
#line 3789 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 291:
#line 3796 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 292:
#line 3803 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 293:
#line 3810 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 294:
#line 3816 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 295:
#line 3823 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 296:
#line 3829 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 297:
#line 3836 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 298:
#line 3842 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 299:
#line 3849 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 300:
#line 3855 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 301:
#line 3862 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 302:
#line 3868 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 303:
#line 3875 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 304:
#line 3881 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 305:
#line 3888 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 306:
#line 3894 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 307:
#line 3901 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 308:
#line 3907 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 309:
#line 3914 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 310:
#line 3920 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 311:
#line 3931 "Gmsh.y"
    {
    ;}
    break;

  case 312:
#line 3934 "Gmsh.y"
    {
    ;}
    break;

  case 313:
#line 3940 "Gmsh.y"
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
#line 3952 "Gmsh.y"
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
#line 3972 "Gmsh.y"
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
#line 3996 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 317:
#line 4000 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 318:
#line 4004 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 319:
#line 4008 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 320:
#line 4012 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 321:
#line 4016 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 322:
#line 4022 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 323:
#line 4028 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 324:
#line 4032 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 325:
#line 4036 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 326:
#line 4040 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 327:
#line 4044 "Gmsh.y"
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
#line 4063 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 329:
#line 4075 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 330:
#line 4079 "Gmsh.y"
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
#line 4094 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 332:
#line 4098 "Gmsh.y"
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
#line 4114 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 334:
#line 4118 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 335:
#line 4123 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 336:
#line 4127 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 337:
#line 4133 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 338:
#line 4137 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 339:
#line 4144 "Gmsh.y"
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
#line 4200 "Gmsh.y"
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
#line 4270 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 342:
#line 4275 "Gmsh.y"
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
#line 4342 "Gmsh.y"
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
#line 4378 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 345:
#line 4386 "Gmsh.y"
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
#line 4429 "Gmsh.y"
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
#line 4468 "Gmsh.y"
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
#line 4489 "Gmsh.y"
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
#line 4521 "Gmsh.y"
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
#line 4548 "Gmsh.y"
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
#line 4574 "Gmsh.y"
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
#line 4600 "Gmsh.y"
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
#line 4626 "Gmsh.y"
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
#line 4652 "Gmsh.y"
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
#line 4673 "Gmsh.y"
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
#line 4701 "Gmsh.y"
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
#line 4729 "Gmsh.y"
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
#line 4757 "Gmsh.y"
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
#line 4785 "Gmsh.y"
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
#line 4813 "Gmsh.y"
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
#line 4852 "Gmsh.y"
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
#line 4891 "Gmsh.y"
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
#line 4912 "Gmsh.y"
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
#line 4933 "Gmsh.y"
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
#line 4960 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 366:
#line 4964 "Gmsh.y"
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
#line 4974 "Gmsh.y"
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
#line 5008 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 369:
#line 5009 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 370:
#line 5010 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 371:
#line 5015 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 372:
#line 5021 "Gmsh.y"
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
#line 5033 "Gmsh.y"
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
#line 5051 "Gmsh.y"
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
#line 5078 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 376:
#line 5079 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 377:
#line 5080 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 378:
#line 5081 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 379:
#line 5082 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 380:
#line 5083 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 381:
#line 5084 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 382:
#line 5085 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 383:
#line 5087 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 384:
#line 5093 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 385:
#line 5094 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 386:
#line 5095 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 387:
#line 5096 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 388:
#line 5097 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 389:
#line 5098 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 390:
#line 5099 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 391:
#line 5100 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 392:
#line 5101 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 393:
#line 5102 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 394:
#line 5103 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 395:
#line 5104 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 396:
#line 5105 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 397:
#line 5106 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 398:
#line 5107 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 399:
#line 5108 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 400:
#line 5109 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 401:
#line 5110 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 402:
#line 5111 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 403:
#line 5112 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 404:
#line 5113 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 405:
#line 5114 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 406:
#line 5115 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 407:
#line 5116 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 408:
#line 5117 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 409:
#line 5118 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 410:
#line 5119 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 411:
#line 5120 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 412:
#line 5121 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 413:
#line 5122 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 414:
#line 5123 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 415:
#line 5124 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 416:
#line 5125 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 417:
#line 5134 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 418:
#line 5135 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 419:
#line 5136 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 420:
#line 5137 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 421:
#line 5138 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 422:
#line 5139 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 423:
#line 5140 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 424:
#line 5141 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 425:
#line 5142 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 426:
#line 5143 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 427:
#line 5144 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 428:
#line 5149 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 429:
#line 5151 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 430:
#line 5157 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 431:
#line 5162 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 432:
#line 5167 "Gmsh.y"
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
#line 5184 "Gmsh.y"
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
#line 5202 "Gmsh.y"
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
#line 5220 "Gmsh.y"
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
#line 5238 "Gmsh.y"
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
#line 5256 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 438:
#line 5261 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 439:
#line 5267 "Gmsh.y"
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
#line 5282 "Gmsh.y"
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
#line 5301 "Gmsh.y"
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
#line 5321 "Gmsh.y"
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
#line 5341 "Gmsh.y"
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
#line 5361 "Gmsh.y"
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
#line 5384 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 446:
#line 5389 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 447:
#line 5394 "Gmsh.y"
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
#line 5404 "Gmsh.y"
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
#line 5414 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 450:
#line 5419 "Gmsh.y"
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
#line 5430 "Gmsh.y"
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
#line 5439 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 453:
#line 5444 "Gmsh.y"
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

  case 454:
#line 5471 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 455:
#line 5475 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 456:
#line 5479 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 457:
#line 5483 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 458:
#line 5487 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 459:
#line 5494 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 460:
#line 5498 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 461:
#line 5502 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 462:
#line 5506 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 463:
#line 5513 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 464:
#line 5518 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 465:
#line 5525 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 466:
#line 5530 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 467:
#line 5534 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 468:
#line 5539 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 469:
#line 5543 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 470:
#line 5551 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 471:
#line 5562 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 472:
#line 5566 "Gmsh.y"
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
#line 5578 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 474:
#line 5586 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 475:
#line 5594 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 476:
#line 5601 "Gmsh.y"
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
#line 5611 "Gmsh.y"
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

  case 478:
#line 5640 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 479:
#line 5644 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 480:
#line 5648 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 481:
#line 5652 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 482:
#line 5656 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 483:
#line 5660 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 484:
#line 5664 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 485:
#line 5668 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 486:
#line 5672 "Gmsh.y"
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

  case 487:
#line 5701 "Gmsh.y"
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

  case 488:
#line 5730 "Gmsh.y"
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

  case 489:
#line 5759 "Gmsh.y"
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

  case 490:
#line 5789 "Gmsh.y"
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

  case 491:
#line 5802 "Gmsh.y"
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

  case 492:
#line 5815 "Gmsh.y"
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

  case 493:
#line 5828 "Gmsh.y"
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

  case 494:
#line 5840 "Gmsh.y"
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
#line 5850 "Gmsh.y"
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
#line 5860 "Gmsh.y"
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
#line 5872 "Gmsh.y"
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
#line 5885 "Gmsh.y"
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

  case 499:
#line 5897 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 500:
#line 5901 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 501:
#line 5905 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 502:
#line 5909 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 503:
#line 5913 "Gmsh.y"
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

  case 504:
#line 5931 "Gmsh.y"
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
#line 5952 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 506:
#line 5957 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 507:
#line 5961 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 508:
#line 5965 "Gmsh.y"
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
#line 5977 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 510:
#line 5981 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 511:
#line 5993 "Gmsh.y"
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
#line 6010 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 513:
#line 6020 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 514:
#line 6024 "Gmsh.y"
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
#line 6039 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 516:
#line 6044 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 517:
#line 6051 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 518:
#line 6055 "Gmsh.y"
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
#line 6068 "Gmsh.y"
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
#line 6082 "Gmsh.y"
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
#line 6096 "Gmsh.y"
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
#line 6110 "Gmsh.y"
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
#line 6124 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 524:
#line 6132 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 525:
#line 6143 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 526:
#line 6147 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 527:
#line 6151 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 528:
#line 6159 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 529:
#line 6165 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 530:
#line 6171 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 531:
#line 6179 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 532:
#line 6187 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 533:
#line 6194 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 534:
#line 6202 "Gmsh.y"
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

  case 535:
#line 6217 "Gmsh.y"
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

  case 536:
#line 6231 "Gmsh.y"
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

  case 537:
#line 6245 "Gmsh.y"
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

  case 538:
#line 6257 "Gmsh.y"
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

  case 539:
#line 6273 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 540:
#line 6282 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 541:
#line 6291 "Gmsh.y"
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

  case 542:
#line 6301 "Gmsh.y"
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

  case 543:
#line 6312 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 544:
#line 6316 "Gmsh.y"
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

  case 545:
#line 6335 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 546:
#line 6342 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 547:
#line 6348 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 548:
#line 6355 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 549:
#line 6362 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 550:
#line 6364 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 551:
#line 6375 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 552:
#line 6380 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 553:
#line 6386 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 554:
#line 6395 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 555:
#line 6408 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 556:
#line 6411 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 557:
#line 6415 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13087 "Gmsh.tab.cpp"
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


#line 6418 "Gmsh.y"


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

