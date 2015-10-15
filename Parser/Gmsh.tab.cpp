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
     tFind = 301,
     tStrFind = 302,
     tStrCmp = 303,
     tStrChoice = 304,
     tUpperCase = 305,
     tLowerCase = 306,
     tLowerCaseIn = 307,
     tTextAttributes = 308,
     tBoundingBox = 309,
     tDraw = 310,
     tSetChanged = 311,
     tToday = 312,
     tFixRelativePath = 313,
     tCurrentDirectory = 314,
     tSyncModel = 315,
     tNewModel = 316,
     tOnelabAction = 317,
     tOnelabRun = 318,
     tCpu = 319,
     tMemory = 320,
     tTotalMemory = 321,
     tCreateTopology = 322,
     tCreateTopologyNoHoles = 323,
     tDistanceFunction = 324,
     tDefineConstant = 325,
     tUndefineConstant = 326,
     tDefineNumber = 327,
     tDefineString = 328,
     tSetNumber = 329,
     tSetString = 330,
     tPoint = 331,
     tCircle = 332,
     tEllipse = 333,
     tLine = 334,
     tSphere = 335,
     tPolarSphere = 336,
     tSurface = 337,
     tSpline = 338,
     tVolume = 339,
     tCharacteristic = 340,
     tLength = 341,
     tParametric = 342,
     tElliptic = 343,
     tRefineMesh = 344,
     tAdaptMesh = 345,
     tRelocateMesh = 346,
     tPlane = 347,
     tRuled = 348,
     tTransfinite = 349,
     tComplex = 350,
     tPhysical = 351,
     tCompound = 352,
     tPeriodic = 353,
     tUsing = 354,
     tPlugin = 355,
     tDegenerated = 356,
     tRecursive = 357,
     tRotate = 358,
     tTranslate = 359,
     tSymmetry = 360,
     tDilate = 361,
     tExtrude = 362,
     tLevelset = 363,
     tAffine = 364,
     tRecombine = 365,
     tSmoother = 366,
     tSplit = 367,
     tDelete = 368,
     tCoherence = 369,
     tIntersect = 370,
     tMeshAlgorithm = 371,
     tReverse = 372,
     tLayers = 373,
     tScaleLast = 374,
     tHole = 375,
     tAlias = 376,
     tAliasWithOptions = 377,
     tCopyOptions = 378,
     tQuadTriAddVerts = 379,
     tQuadTriNoNewVerts = 380,
     tQuadTriSngl = 381,
     tQuadTriDbl = 382,
     tRecombLaterals = 383,
     tTransfQuadTri = 384,
     tText2D = 385,
     tText3D = 386,
     tInterpolationScheme = 387,
     tTime = 388,
     tCombine = 389,
     tBSpline = 390,
     tBezier = 391,
     tNurbs = 392,
     tNurbsOrder = 393,
     tNurbsKnots = 394,
     tColor = 395,
     tColorTable = 396,
     tFor = 397,
     tIn = 398,
     tEndFor = 399,
     tIf = 400,
     tElse = 401,
     tEndIf = 402,
     tExit = 403,
     tAbort = 404,
     tField = 405,
     tReturn = 406,
     tCall = 407,
     tMacro = 408,
     tShow = 409,
     tHide = 410,
     tGetValue = 411,
     tGetEnv = 412,
     tGetString = 413,
     tGetNumber = 414,
     tHomology = 415,
     tCohomology = 416,
     tBetti = 417,
     tSetOrder = 418,
     tExists = 419,
     tFileExists = 420,
     tGMSH_MAJOR_VERSION = 421,
     tGMSH_MINOR_VERSION = 422,
     tGMSH_PATCH_VERSION = 423,
     tGmshExecutableName = 424,
     tSetPartition = 425,
     tNameFromString = 426,
     tStringFromName = 427,
     tAFFECTDIVIDE = 428,
     tAFFECTTIMES = 429,
     tAFFECTMINUS = 430,
     tAFFECTPLUS = 431,
     tOR = 432,
     tAND = 433,
     tNOTEQUAL = 434,
     tEQUAL = 435,
     tGREATEROREQUAL = 436,
     tLESSOREQUAL = 437,
     UNARYPREC = 438,
     tMINUSMINUS = 439,
     tPLUSPLUS = 440
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
#define tFind 301
#define tStrFind 302
#define tStrCmp 303
#define tStrChoice 304
#define tUpperCase 305
#define tLowerCase 306
#define tLowerCaseIn 307
#define tTextAttributes 308
#define tBoundingBox 309
#define tDraw 310
#define tSetChanged 311
#define tToday 312
#define tFixRelativePath 313
#define tCurrentDirectory 314
#define tSyncModel 315
#define tNewModel 316
#define tOnelabAction 317
#define tOnelabRun 318
#define tCpu 319
#define tMemory 320
#define tTotalMemory 321
#define tCreateTopology 322
#define tCreateTopologyNoHoles 323
#define tDistanceFunction 324
#define tDefineConstant 325
#define tUndefineConstant 326
#define tDefineNumber 327
#define tDefineString 328
#define tSetNumber 329
#define tSetString 330
#define tPoint 331
#define tCircle 332
#define tEllipse 333
#define tLine 334
#define tSphere 335
#define tPolarSphere 336
#define tSurface 337
#define tSpline 338
#define tVolume 339
#define tCharacteristic 340
#define tLength 341
#define tParametric 342
#define tElliptic 343
#define tRefineMesh 344
#define tAdaptMesh 345
#define tRelocateMesh 346
#define tPlane 347
#define tRuled 348
#define tTransfinite 349
#define tComplex 350
#define tPhysical 351
#define tCompound 352
#define tPeriodic 353
#define tUsing 354
#define tPlugin 355
#define tDegenerated 356
#define tRecursive 357
#define tRotate 358
#define tTranslate 359
#define tSymmetry 360
#define tDilate 361
#define tExtrude 362
#define tLevelset 363
#define tAffine 364
#define tRecombine 365
#define tSmoother 366
#define tSplit 367
#define tDelete 368
#define tCoherence 369
#define tIntersect 370
#define tMeshAlgorithm 371
#define tReverse 372
#define tLayers 373
#define tScaleLast 374
#define tHole 375
#define tAlias 376
#define tAliasWithOptions 377
#define tCopyOptions 378
#define tQuadTriAddVerts 379
#define tQuadTriNoNewVerts 380
#define tQuadTriSngl 381
#define tQuadTriDbl 382
#define tRecombLaterals 383
#define tTransfQuadTri 384
#define tText2D 385
#define tText3D 386
#define tInterpolationScheme 387
#define tTime 388
#define tCombine 389
#define tBSpline 390
#define tBezier 391
#define tNurbs 392
#define tNurbsOrder 393
#define tNurbsKnots 394
#define tColor 395
#define tColorTable 396
#define tFor 397
#define tIn 398
#define tEndFor 399
#define tIf 400
#define tElse 401
#define tEndIf 402
#define tExit 403
#define tAbort 404
#define tField 405
#define tReturn 406
#define tCall 407
#define tMacro 408
#define tShow 409
#define tHide 410
#define tGetValue 411
#define tGetEnv 412
#define tGetString 413
#define tGetNumber 414
#define tHomology 415
#define tCohomology 416
#define tBetti 417
#define tSetOrder 418
#define tExists 419
#define tFileExists 420
#define tGMSH_MAJOR_VERSION 421
#define tGMSH_MINOR_VERSION 422
#define tGMSH_PATCH_VERSION 423
#define tGmshExecutableName 424
#define tSetPartition 425
#define tNameFromString 426
#define tStringFromName 427
#define tAFFECTDIVIDE 428
#define tAFFECTTIMES 429
#define tAFFECTMINUS 430
#define tAFFECTPLUS 431
#define tOR 432
#define tAND 433
#define tNOTEQUAL 434
#define tEQUAL 435
#define tGREATEROREQUAL 436
#define tLESSOREQUAL 437
#define UNARYPREC 438
#define tMINUSMINUS 439
#define tPLUSPLUS 440




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

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

// Global parser variables
std::string gmsh_yyname;
int gmsh_yyerrorstate = 0;
int gmsh_yyviewindex = 0;
std::map<std::string, gmsh_yysymbol> gmsh_yysymbols;
std::map<std::string, std::string> gmsh_yystringsymbols;

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
bool is_alpha(const int c);
void skip_until(const char *skip, const char *until);
void skip_until_test(const char *skip, const char *until, const char *until2, int *flag_until2);
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
#line 109 "Gmsh.y"
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
#line 592 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 605 "Gmsh.tab.cpp"

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
#define YYLAST   10262

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  206
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  520
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1837

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   440

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   191,     2,   201,     2,   190,     2,     2,
     196,   197,   188,   186,   202,   187,   200,   189,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     182,     2,   183,   177,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   198,     2,   199,   195,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   203,     2,   204,   205,     2,     2,     2,
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
     175,   176,   178,   179,   180,   181,   184,   185,   192,   193,
     194
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    49,    55,    61,    69,    77,    85,
      95,   102,   109,   116,   125,   126,   129,   132,   135,   138,
     141,   143,   147,   149,   153,   154,   155,   166,   168,   172,
     173,   187,   189,   193,   194,   210,   219,   234,   235,   242,
     244,   246,   248,   250,   252,   254,   256,   258,   260,   262,
     264,   270,   276,   284,   292,   297,   304,   311,   319,   327,
     335,   343,   353,   363,   367,   374,   381,   388,   395,   400,
     407,   417,   424,   434,   440,   449,   458,   470,   477,   487,
     493,   501,   511,   521,   533,   541,   551,   561,   562,   564,
     565,   569,   575,   576,   586,   592,   593,   603,   604,   608,
     612,   618,   619,   622,   626,   632,   636,   637,   640,   644,
     648,   652,   658,   660,   662,   666,   668,   670,   674,   676,
     678,   682,   684,   686,   690,   691,   697,   698,   701,   709,
     718,   725,   733,   738,   746,   755,   764,   772,   780,   792,
     801,   810,   819,   828,   838,   842,   847,   858,   866,   874,
     883,   892,   905,   914,   923,   931,   940,   949,   955,   967,
     973,   983,   993,   998,  1008,  1018,  1020,  1022,  1023,  1026,
    1033,  1040,  1047,  1054,  1063,  1074,  1089,  1106,  1119,  1128,
    1137,  1144,  1159,  1164,  1171,  1178,  1182,  1187,  1193,  1200,
    1206,  1210,  1214,  1219,  1225,  1230,  1236,  1240,  1246,  1254,
    1262,  1266,  1274,  1278,  1281,  1284,  1287,  1290,  1293,  1309,
    1312,  1315,  1318,  1321,  1324,  1341,  1345,  1352,  1361,  1370,
    1381,  1383,  1386,  1389,  1391,  1395,  1399,  1404,  1406,  1408,
    1414,  1426,  1440,  1441,  1449,  1450,  1464,  1465,  1481,  1482,
    1489,  1498,  1507,  1516,  1529,  1542,  1555,  1570,  1585,  1600,
    1601,  1614,  1615,  1628,  1629,  1642,  1643,  1660,  1661,  1678,
    1679,  1696,  1697,  1716,  1717,  1736,  1737,  1756,  1758,  1761,
    1767,  1775,  1785,  1788,  1791,  1794,  1798,  1801,  1805,  1808,
    1812,  1815,  1819,  1829,  1836,  1837,  1841,  1842,  1844,  1845,
    1848,  1849,  1852,  1853,  1856,  1864,  1871,  1880,  1886,  1890,
    1898,  1904,  1909,  1916,  1928,  1940,  1959,  1978,  1991,  2004,
    2017,  2028,  2039,  2050,  2061,  2072,  2077,  2082,  2087,  2092,
    2097,  2100,  2104,  2111,  2113,  2115,  2117,  2120,  2126,  2134,
    2145,  2147,  2151,  2154,  2157,  2160,  2164,  2168,  2172,  2176,
    2180,  2184,  2188,  2192,  2196,  2200,  2204,  2208,  2212,  2216,
    2222,  2227,  2232,  2237,  2242,  2247,  2252,  2257,  2262,  2267,
    2272,  2279,  2284,  2289,  2294,  2299,  2304,  2309,  2314,  2321,
    2328,  2335,  2340,  2342,  2344,  2346,  2348,  2350,  2352,  2354,
    2356,  2358,  2360,  2362,  2363,  2370,  2375,  2377,  2382,  2387,
    2392,  2397,  2402,  2407,  2412,  2415,  2421,  2427,  2433,  2439,
    2443,  2450,  2455,  2463,  2470,  2477,  2484,  2491,  2496,  2498,
    2501,  2504,  2508,  2512,  2524,  2534,  2542,  2550,  2552,  2556,
    2558,  2560,  2563,  2567,  2572,  2578,  2580,  2582,  2585,  2589,
    2593,  2599,  2604,  2607,  2610,  2613,  2616,  2620,  2624,  2628,
    2632,  2638,  2644,  2650,  2656,  2673,  2690,  2707,  2724,  2726,
    2728,  2732,  2736,  2741,  2748,  2755,  2757,  2759,  2763,  2767,
    2777,  2785,  2787,  2793,  2797,  2804,  2806,  2810,  2812,  2814,
    2818,  2825,  2827,  2832,  2834,  2836,  2838,  2843,  2850,  2855,
    2860,  2865,  2870,  2879,  2884,  2889,  2894,  2899,  2908,  2913,
    2920,  2925,  2927,  2928,  2935,  2937,  2941,  2947,  2953,  2955,
    2957
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     207,     0,    -1,   208,    -1,     1,     6,    -1,    -1,   208,
     209,    -1,   212,    -1,   211,    -1,   232,    -1,   249,    -1,
     250,    -1,   254,    -1,   255,    -1,   256,    -1,   257,    -1,
     260,    -1,   281,    -1,   282,    -1,   259,    -1,   258,    -1,
     253,    -1,   284,    -1,   183,    -1,   183,   183,    -1,    38,
     196,   298,   197,     6,    -1,    39,   196,   298,   197,     6,
      -1,    38,   196,   298,   197,   210,   298,     6,    -1,    38,
     196,   298,   202,   294,   197,     6,    -1,    39,   196,   298,
     202,   294,   197,     6,    -1,    38,   196,   298,   202,   294,
     197,   210,   298,     6,    -1,     4,   298,   203,   213,   204,
       6,    -1,   121,     4,   198,   285,   199,     6,    -1,   122,
       4,   198,   285,   199,     6,    -1,   123,     4,   198,   285,
     202,   285,   199,     6,    -1,    -1,   213,   216,    -1,   213,
     220,    -1,   213,   223,    -1,   213,   225,    -1,   213,   226,
      -1,   285,    -1,   214,   202,   285,    -1,   285,    -1,   215,
     202,   285,    -1,    -1,    -1,     4,   217,   196,   214,   197,
     218,   203,   215,   204,     6,    -1,   298,    -1,   219,   202,
     298,    -1,    -1,   130,   196,   285,   202,   285,   202,   285,
     197,   221,   203,   219,   204,     6,    -1,   298,    -1,   222,
     202,   298,    -1,    -1,   131,   196,   285,   202,   285,   202,
     285,   202,   285,   197,   224,   203,   222,   204,     6,    -1,
     132,   203,   290,   204,   203,   290,   204,     6,    -1,   132,
     203,   290,   204,   203,   290,   204,   203,   290,   204,   203,
     290,   204,     6,    -1,    -1,   133,   227,   203,   215,   204,
       6,    -1,     7,    -1,   176,    -1,   175,    -1,   174,    -1,
     173,    -1,   194,    -1,   193,    -1,   196,    -1,   198,    -1,
     197,    -1,   199,    -1,    70,   198,   234,   199,     6,    -1,
      71,   198,   237,   199,     6,    -1,    74,   230,   299,   202,
     285,   231,     6,    -1,    75,   230,   303,   202,   299,   231,
       6,    -1,   303,   228,   291,     6,    -1,     4,   230,   231,
     228,   291,     6,    -1,   302,   230,   231,   228,   291,     6,
      -1,     4,   198,   285,   199,   228,   285,     6,    -1,     4,
     196,   285,   197,   228,   285,     6,    -1,   302,   198,   285,
     199,   228,   285,     6,    -1,   302,   196,   285,   197,   228,
     285,     6,    -1,     4,   230,   203,   294,   204,   231,   228,
     291,     6,    -1,   302,   230,   203,   294,   204,   231,   228,
     291,     6,    -1,   303,   229,     6,    -1,     4,   198,   285,
     199,   229,     6,    -1,     4,   196,   285,   197,   229,     6,
      -1,   302,   198,   285,   199,   229,     6,    -1,   302,   196,
     285,   197,   229,     6,    -1,   303,     7,   299,     6,    -1,
       4,   200,     4,     7,   299,     6,    -1,     4,   198,   285,
     199,   200,     4,     7,   299,     6,    -1,     4,   200,     4,
     228,   285,     6,    -1,     4,   198,   285,   199,   200,     4,
     228,   285,     6,    -1,     4,   200,     4,   229,     6,    -1,
       4,   198,   285,   199,   200,     4,   229,     6,    -1,     4,
     200,   140,   200,     4,     7,   295,     6,    -1,     4,   198,
     285,   199,   200,   140,   200,     4,     7,   295,     6,    -1,
       4,   200,   141,     7,   296,     6,    -1,     4,   198,   285,
     199,   200,   141,     7,   296,     6,    -1,     4,   150,     7,
     285,     6,    -1,   150,   198,   285,   199,     7,     4,     6,
      -1,   150,   198,   285,   199,   200,     4,     7,   285,     6,
      -1,   150,   198,   285,   199,   200,     4,     7,   299,     6,
      -1,   150,   198,   285,   199,   200,     4,     7,   203,   294,
     204,     6,    -1,   150,   198,   285,   199,   200,     4,     6,
      -1,   100,   196,     4,   197,   200,     4,     7,   285,     6,
      -1,   100,   196,     4,   197,   200,     4,     7,   299,     6,
      -1,    -1,   202,    -1,    -1,   234,   233,   303,    -1,   234,
     233,   303,     7,   285,    -1,    -1,   234,   233,   303,     7,
     203,   291,   235,   239,   204,    -1,   234,   233,   303,     7,
     299,    -1,    -1,   234,   233,   303,     7,   203,   299,   236,
     241,   204,    -1,    -1,   237,   233,   298,    -1,   285,     7,
     299,    -1,   238,   202,   285,     7,   299,    -1,    -1,   239,
     240,    -1,   202,     4,   291,    -1,   202,     4,   203,   238,
     204,    -1,   202,     4,   299,    -1,    -1,   241,   242,    -1,
     202,     4,   285,    -1,   202,     4,   299,    -1,   202,   153,
     299,    -1,   202,     4,   203,   301,   204,    -1,   285,    -1,
     299,    -1,   299,   202,   285,    -1,   285,    -1,   299,    -1,
     299,   202,   285,    -1,   285,    -1,   299,    -1,   299,   202,
     285,    -1,   285,    -1,   299,    -1,   299,   202,   285,    -1,
      -1,   143,    80,   203,   285,   204,    -1,    -1,    92,   288,
      -1,    76,   196,   285,   197,     7,   288,     6,    -1,    96,
      76,   196,   243,   197,   228,   291,     6,    -1,    85,    86,
     291,     7,   285,     6,    -1,    79,   196,   285,   197,     7,
     291,     6,    -1,   101,    79,   291,     6,    -1,    83,   196,
     285,   197,     7,   291,     6,    -1,    77,   196,   285,   197,
       7,   291,   248,     6,    -1,    78,   196,   285,   197,     7,
     291,   248,     6,    -1,   135,   196,   285,   197,     7,   291,
       6,    -1,   136,   196,   285,   197,     7,   291,     6,    -1,
     137,   196,   285,   197,     7,   291,   139,   291,   138,   285,
       6,    -1,    79,     4,   196,   285,   197,     7,   291,     6,
      -1,    97,    79,   196,   285,   197,     7,   291,     6,    -1,
      96,    79,   196,   244,   197,   228,   291,     6,    -1,    92,
      82,   196,   285,   197,     7,   291,     6,    -1,    93,    82,
     196,   285,   197,     7,   291,   247,     6,    -1,    12,    13,
       6,    -1,    13,    82,   285,     6,    -1,    87,    82,   196,
     285,   197,     7,     5,     5,     5,     6,    -1,    80,   196,
     285,   197,     7,   291,     6,    -1,    81,   196,   285,   197,
       7,   291,     6,    -1,    82,     4,   196,   285,   197,     7,
     291,     6,    -1,    97,    82,   196,   285,   197,     7,   291,
       6,    -1,    97,    82,   196,   285,   197,     7,   291,     4,
     203,   290,   204,     6,    -1,    96,    82,   196,   245,   197,
     228,   291,     6,    -1,    95,    84,   196,   285,   197,     7,
     291,     6,    -1,    84,   196,   285,   197,     7,   291,     6,
      -1,    97,    84,   196,   285,   197,     7,   291,     6,    -1,
      96,    84,   196,   246,   197,   228,   291,     6,    -1,   104,
     288,   203,   251,   204,    -1,   103,   203,   288,   202,   288,
     202,   285,   204,   203,   251,   204,    -1,   105,   288,   203,
     251,   204,    -1,   106,   203,   288,   202,   285,   204,   203,
     251,   204,    -1,   106,   203,   288,   202,   288,   204,   203,
     251,   204,    -1,     4,   203,   251,   204,    -1,   115,    79,
     203,   294,   204,    82,   203,   285,   204,    -1,   112,    79,
     196,   285,   197,   203,   294,   204,     6,    -1,   252,    -1,
     250,    -1,    -1,   252,   249,    -1,   252,    76,   203,   294,
     204,     6,    -1,   252,    79,   203,   294,   204,     6,    -1,
     252,    82,   203,   294,   204,     6,    -1,   252,    84,   203,
     294,   204,     6,    -1,   108,    92,   196,   285,   197,     7,
     291,     6,    -1,   108,    76,   196,   285,   197,     7,   203,
     290,   204,     6,    -1,   108,    92,   196,   285,   197,     7,
     203,   288,   202,   288,   202,   294,   204,     6,    -1,   108,
      92,   196,   285,   197,     7,   203,   288,   202,   288,   202,
     288,   202,   294,   204,     6,    -1,   108,    80,   196,   285,
     197,     7,   203,   288,   202,   294,   204,     6,    -1,   108,
       4,   196,   285,   197,     7,   291,     6,    -1,   108,     4,
     196,   285,   197,     7,     5,     6,    -1,   108,     4,   203,
     285,   204,     6,    -1,   108,     4,   196,   285,   197,     7,
     203,   288,   202,   288,   202,   294,   204,     6,    -1,   113,
     203,   252,   204,    -1,   113,   150,   198,   285,   199,     6,
      -1,   113,     4,   198,   285,   199,     6,    -1,   113,   303,
       6,    -1,   113,     4,     4,     6,    -1,   140,   295,   203,
     252,   204,    -1,   102,   140,   295,   203,   252,   204,    -1,
     170,   285,   203,   252,   204,    -1,   154,     5,     6,    -1,
     155,     5,     6,    -1,   154,   203,   252,   204,    -1,   102,
     154,   203,   252,   204,    -1,   155,   203,   252,   204,    -1,
     102,   155,   203,   252,   204,    -1,     4,   299,     6,    -1,
      63,   196,   301,   197,     6,    -1,     4,     4,   198,   285,
     199,   298,     6,    -1,     4,     4,     4,   198,   285,   199,
       6,    -1,     4,   285,     6,    -1,   100,   196,     4,   197,
     200,     4,     6,    -1,   134,     4,     6,    -1,   148,     6,
      -1,   149,     6,    -1,    60,     6,    -1,    61,     6,    -1,
      54,     6,    -1,    54,   203,   285,   202,   285,   202,   285,
     202,   285,   202,   285,   202,   285,   204,     6,    -1,    55,
       6,    -1,    56,     6,    -1,    67,     6,    -1,    68,     6,
      -1,    89,     6,    -1,    90,   203,   294,   204,   203,   294,
     204,   203,   290,   204,   203,   285,   202,   285,   204,     6,
      -1,   163,   285,     6,    -1,   142,   196,   285,     8,   285,
     197,    -1,   142,   196,   285,     8,   285,     8,   285,   197,
      -1,   142,     4,   143,   203,   285,     8,   285,   204,    -1,
     142,     4,   143,   203,   285,     8,   285,     8,   285,   204,
      -1,   144,    -1,   153,     4,    -1,   153,   299,    -1,   151,
      -1,   152,   303,     6,    -1,   152,   299,     6,    -1,   145,
     196,   285,   197,    -1,   146,    -1,   147,    -1,   107,   288,
     203,   252,   204,    -1,   107,   203,   288,   202,   288,   202,
     285,   204,   203,   252,   204,    -1,   107,   203,   288,   202,
     288,   202,   288,   202,   285,   204,   203,   252,   204,    -1,
      -1,   107,   288,   203,   252,   261,   274,   204,    -1,    -1,
     107,   203,   288,   202,   288,   202,   285,   204,   203,   252,
     262,   274,   204,    -1,    -1,   107,   203,   288,   202,   288,
     202,   288,   202,   285,   204,   203,   252,   263,   274,   204,
      -1,    -1,   107,   203,   252,   264,   274,   204,    -1,   107,
      76,   203,   285,   202,   288,   204,     6,    -1,   107,    79,
     203,   285,   202,   288,   204,     6,    -1,   107,    82,   203,
     285,   202,   288,   204,     6,    -1,   107,    76,   203,   285,
     202,   288,   202,   288,   202,   285,   204,     6,    -1,   107,
      79,   203,   285,   202,   288,   202,   288,   202,   285,   204,
       6,    -1,   107,    82,   203,   285,   202,   288,   202,   288,
     202,   285,   204,     6,    -1,   107,    76,   203,   285,   202,
     288,   202,   288,   202,   288,   202,   285,   204,     6,    -1,
     107,    79,   203,   285,   202,   288,   202,   288,   202,   288,
     202,   285,   204,     6,    -1,   107,    82,   203,   285,   202,
     288,   202,   288,   202,   288,   202,   285,   204,     6,    -1,
      -1,   107,    76,   203,   285,   202,   288,   204,   265,   203,
     274,   204,     6,    -1,    -1,   107,    79,   203,   285,   202,
     288,   204,   266,   203,   274,   204,     6,    -1,    -1,   107,
      82,   203,   285,   202,   288,   204,   267,   203,   274,   204,
       6,    -1,    -1,   107,    76,   203,   285,   202,   288,   202,
     288,   202,   285,   204,   268,   203,   274,   204,     6,    -1,
      -1,   107,    79,   203,   285,   202,   288,   202,   288,   202,
     285,   204,   269,   203,   274,   204,     6,    -1,    -1,   107,
      82,   203,   285,   202,   288,   202,   288,   202,   285,   204,
     270,   203,   274,   204,     6,    -1,    -1,   107,    76,   203,
     285,   202,   288,   202,   288,   202,   288,   202,   285,   204,
     271,   203,   274,   204,     6,    -1,    -1,   107,    79,   203,
     285,   202,   288,   202,   288,   202,   288,   202,   285,   204,
     272,   203,   274,   204,     6,    -1,    -1,   107,    82,   203,
     285,   202,   288,   202,   288,   202,   288,   202,   285,   204,
     273,   203,   274,   204,     6,    -1,   275,    -1,   274,   275,
      -1,   118,   203,   285,   204,     6,    -1,   118,   203,   291,
     202,   291,   204,     6,    -1,   118,   203,   291,   202,   291,
     202,   291,   204,     6,    -1,   119,     6,    -1,   110,     6,
      -1,   126,     6,    -1,   126,   128,     6,    -1,   127,     6,
      -1,   127,   128,     6,    -1,   124,     6,    -1,   124,   128,
       6,    -1,   125,     6,    -1,   125,   128,     6,    -1,   120,
     196,   285,   197,     7,   291,    99,   285,     6,    -1,    99,
       4,   198,   285,   199,     6,    -1,    -1,    99,     4,   285,
      -1,    -1,     4,    -1,    -1,     7,   291,    -1,    -1,     7,
     285,    -1,    -1,   109,   291,    -1,    94,    79,   292,     7,
     285,   276,     6,    -1,    94,    82,   292,   278,   277,     6,
      -1,    88,    82,   203,   285,   204,     7,   291,     6,    -1,
      94,    84,   292,   278,     6,    -1,   129,   292,     6,    -1,
     116,    82,   203,   294,   204,   285,     6,    -1,   110,    82,
     292,   279,     6,    -1,   110,    84,   292,     6,    -1,   111,
      82,   291,     7,   285,     6,    -1,    98,    79,   203,   294,
     204,     7,   203,   294,   204,   280,     6,    -1,    98,    82,
     203,   294,   204,     7,   203,   294,   204,   280,     6,    -1,
      98,    79,   203,   294,   204,     7,   203,   294,   204,   103,
     203,   288,   202,   288,   202,   285,   204,     6,    -1,    98,
      82,   203,   294,   204,     7,   203,   294,   204,   103,   203,
     288,   202,   288,   202,   285,   204,     6,    -1,    98,    79,
     203,   294,   204,     7,   203,   294,   204,   104,   288,     6,
      -1,    98,    82,   203,   294,   204,     7,   203,   294,   204,
     104,   288,     6,    -1,    98,    82,   285,   203,   294,   204,
       7,   285,   203,   294,   204,     6,    -1,    76,   203,   294,
     204,   143,    82,   203,   285,   204,     6,    -1,    79,   203,
     294,   204,   143,    82,   203,   285,   204,     6,    -1,    76,
     203,   294,   204,   143,    84,   203,   285,   204,     6,    -1,
      79,   203,   294,   204,   143,    84,   203,   285,   204,     6,
      -1,    82,   203,   294,   204,   143,    84,   203,   285,   204,
       6,    -1,   117,    82,   292,     6,    -1,   117,    79,   292,
       6,    -1,    91,    76,   292,     6,    -1,    91,    79,   292,
       6,    -1,    91,    82,   292,     6,    -1,   114,     6,    -1,
     114,     4,     6,    -1,   114,    76,   203,   294,   204,     6,
      -1,   160,    -1,   161,    -1,   162,    -1,   283,     6,    -1,
     283,   203,   291,   204,     6,    -1,   283,   203,   291,   202,
     291,   204,     6,    -1,   283,   196,   291,   197,   203,   291,
     202,   291,   204,     6,    -1,   286,    -1,   196,   285,   197,
      -1,   187,   285,    -1,   186,   285,    -1,   191,   285,    -1,
     285,   187,   285,    -1,   285,   186,   285,    -1,   285,   188,
     285,    -1,   285,   189,   285,    -1,   285,   190,   285,    -1,
     285,   195,   285,    -1,   285,   182,   285,    -1,   285,   183,
     285,    -1,   285,   185,   285,    -1,   285,   184,   285,    -1,
     285,   181,   285,    -1,   285,   180,   285,    -1,   285,   179,
     285,    -1,   285,   178,   285,    -1,   285,   177,   285,     8,
     285,    -1,    15,   230,   285,   231,    -1,    16,   230,   285,
     231,    -1,    17,   230,   285,   231,    -1,    18,   230,   285,
     231,    -1,    19,   230,   285,   231,    -1,    20,   230,   285,
     231,    -1,    21,   230,   285,   231,    -1,    22,   230,   285,
     231,    -1,    23,   230,   285,   231,    -1,    25,   230,   285,
     231,    -1,    26,   230,   285,   202,   285,   231,    -1,    27,
     230,   285,   231,    -1,    28,   230,   285,   231,    -1,    29,
     230,   285,   231,    -1,    30,   230,   285,   231,    -1,    31,
     230,   285,   231,    -1,    32,   230,   285,   231,    -1,    33,
     230,   285,   231,    -1,    34,   230,   285,   202,   285,   231,
      -1,    35,   230,   285,   202,   285,   231,    -1,    36,   230,
     285,   202,   285,   231,    -1,    24,   230,   285,   231,    -1,
       3,    -1,     9,    -1,    14,    -1,    10,    -1,    11,    -1,
     166,    -1,   167,    -1,   168,    -1,    64,    -1,    65,    -1,
      66,    -1,    -1,    72,   230,   285,   287,   239,   231,    -1,
     159,   230,   298,   231,    -1,   303,    -1,     4,   198,   285,
     199,    -1,     4,   196,   285,   197,    -1,   302,   198,   285,
     199,    -1,   302,   196,   285,   197,    -1,   164,   196,   303,
     197,    -1,   165,   196,   299,   197,    -1,   201,   303,   230,
     231,    -1,   303,   229,    -1,     4,   198,   285,   199,   229,
      -1,     4,   196,   285,   197,   229,    -1,   302,   198,   285,
     199,   229,    -1,   302,   196,   285,   197,   229,    -1,     4,
     200,     4,    -1,     4,   198,   285,   199,   200,     4,    -1,
       4,   200,     4,   229,    -1,     4,   198,   285,   199,   200,
       4,   229,    -1,   156,   196,   298,   202,   285,   197,    -1,
      46,   196,   291,   202,   291,   197,    -1,    47,   196,   298,
     202,   298,   197,    -1,    48,   196,   298,   202,   298,   197,
      -1,    53,   196,   301,   197,    -1,   289,    -1,   187,   288,
      -1,   186,   288,    -1,   288,   187,   288,    -1,   288,   186,
     288,    -1,   203,   285,   202,   285,   202,   285,   202,   285,
     202,   285,   204,    -1,   203,   285,   202,   285,   202,   285,
     202,   285,   204,    -1,   203,   285,   202,   285,   202,   285,
     204,    -1,   196,   285,   202,   285,   202,   285,   197,    -1,
     291,    -1,   290,   202,   291,    -1,   285,    -1,   293,    -1,
     203,   204,    -1,   203,   294,   204,    -1,   187,   203,   294,
     204,    -1,   285,   188,   203,   294,   204,    -1,   291,    -1,
       5,    -1,   187,   293,    -1,   285,   188,   293,    -1,   285,
       8,   285,    -1,   285,     8,   285,     8,   285,    -1,    76,
     203,   285,   204,    -1,    76,     5,    -1,    79,     5,    -1,
      82,     5,    -1,    84,     5,    -1,    96,    76,     5,    -1,
      96,    79,     5,    -1,    96,    82,     5,    -1,    96,    84,
       5,    -1,    96,    76,   203,   294,   204,    -1,    96,    79,
     203,   294,   204,    -1,    96,    82,   203,   294,   204,    -1,
      96,    84,   203,   294,   204,    -1,    76,   143,    54,   203,
     285,   202,   285,   202,   285,   202,   285,   202,   285,   202,
     285,   204,    -1,    79,   143,    54,   203,   285,   202,   285,
     202,   285,   202,   285,   202,   285,   202,   285,   204,    -1,
      82,   143,    54,   203,   285,   202,   285,   202,   285,   202,
     285,   202,   285,   202,   285,   204,    -1,    84,   143,    54,
     203,   285,   202,   285,   202,   285,   202,   285,   202,   285,
     202,   285,   204,    -1,   250,    -1,   260,    -1,     4,   230,
     231,    -1,   302,   230,   231,    -1,    37,   198,   303,   199,
      -1,     4,   230,   203,   294,   204,   231,    -1,   302,   230,
     203,   294,   204,   231,    -1,   285,    -1,   293,    -1,   294,
     202,   285,    -1,   294,   202,   293,    -1,   203,   285,   202,
     285,   202,   285,   202,   285,   204,    -1,   203,   285,   202,
     285,   202,   285,   204,    -1,     4,    -1,     4,   200,   140,
     200,     4,    -1,   203,   297,   204,    -1,     4,   198,   285,
     199,   200,   141,    -1,   295,    -1,   297,   202,   295,    -1,
     299,    -1,   303,    -1,     4,   200,     4,    -1,     4,   198,
     285,   199,   200,     4,    -1,     5,    -1,   172,   198,   303,
     199,    -1,    57,    -1,   169,    -1,    62,    -1,   157,   196,
     298,   197,    -1,   158,   196,   298,   202,   298,   197,    -1,
     158,   196,   298,   197,    -1,    42,   230,   301,   231,    -1,
      43,   196,   298,   197,    -1,    44,   196,   298,   197,    -1,
      45,   196,   298,   202,   298,   202,   298,   197,    -1,    40,
     230,   301,   231,    -1,    50,   230,   298,   231,    -1,    51,
     230,   298,   231,    -1,    52,   230,   298,   231,    -1,    49,
     230,   285,   202,   299,   202,   299,   231,    -1,    41,   230,
     298,   231,    -1,    41,   230,   298,   202,   294,   231,    -1,
      58,   230,   298,   231,    -1,    59,    -1,    -1,    73,   230,
     299,   300,   241,   231,    -1,   298,    -1,   301,   202,   298,
      -1,     4,   205,   203,   285,   204,    -1,   302,   205,   203,
     285,   204,    -1,     4,    -1,   302,    -1,   171,   198,   298,
     199,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   196,   196,   197,   202,   204,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   227,   231,   238,   243,   248,   262,   275,   288,
     316,   330,   343,   356,   375,   380,   381,   382,   383,   384,
     388,   390,   395,   397,   403,   507,   402,   525,   532,   543,
     542,   560,   567,   578,   577,   594,   611,   634,   633,   647,
     648,   649,   650,   651,   655,   656,   662,   662,   663,   663,
     669,   670,   671,   676,   682,   742,   771,   800,   805,   810,
     815,   820,   827,   834,   849,   854,   859,   864,   869,   878,
     884,   893,   911,   929,   938,   950,   955,   963,   983,  1006,
    1017,  1025,  1047,  1070,  1096,  1117,  1129,  1143,  1143,  1145,
    1147,  1156,  1166,  1165,  1183,  1193,  1192,  1206,  1208,  1216,
    1222,  1229,  1230,  1234,  1245,  1260,  1270,  1271,  1276,  1284,
    1293,  1301,  1319,  1323,  1329,  1337,  1341,  1347,  1355,  1359,
    1365,  1373,  1377,  1383,  1392,  1395,  1408,  1411,  1421,  1444,
    1476,  1499,  1517,  1538,  1556,  1586,  1616,  1634,  1652,  1679,
    1697,  1715,  1750,  1768,  1807,  1813,  1819,  1826,  1851,  1876,
    1893,  1912,  1946,  1982,  2000,  2017,  2033,  2070,  2075,  2080,
    2085,  2090,  2095,  2118,  2124,  2135,  2136,  2141,  2144,  2148,
    2171,  2194,  2217,  2245,  2266,  2292,  2313,  2335,  2355,  2467,
    2486,  2524,  2633,  2642,  2648,  2663,  2691,  2708,  2717,  2731,
    2745,  2751,  2757,  2766,  2775,  2784,  2798,  2854,  2872,  2889,
    2904,  2923,  2935,  2959,  2963,  2968,  2975,  2980,  2986,  2991,
    2997,  3005,  3009,  3013,  3018,  3073,  3086,  3103,  3120,  3142,
    3164,  3199,  3207,  3215,  3221,  3228,  3235,  3255,  3262,  3274,
    3282,  3290,  3299,  3298,  3313,  3312,  3327,  3326,  3341,  3340,
    3354,  3361,  3368,  3375,  3382,  3389,  3396,  3403,  3410,  3418,
    3417,  3431,  3430,  3444,  3443,  3457,  3456,  3470,  3469,  3483,
    3482,  3496,  3495,  3509,  3508,  3522,  3521,  3538,  3541,  3547,
    3559,  3579,  3603,  3607,  3611,  3615,  3619,  3625,  3631,  3635,
    3639,  3643,  3647,  3666,  3679,  3682,  3698,  3701,  3718,  3721,
    3727,  3730,  3737,  3740,  3747,  3803,  3873,  3878,  3945,  3981,
    3989,  4032,  4071,  4091,  4123,  4150,  4176,  4202,  4228,  4254,
    4276,  4304,  4332,  4336,  4340,  4368,  4407,  4446,  4467,  4488,
    4515,  4519,  4529,  4564,  4565,  4566,  4570,  4576,  4588,  4606,
    4634,  4635,  4636,  4637,  4638,  4639,  4640,  4641,  4642,  4649,
    4650,  4651,  4652,  4653,  4654,  4655,  4656,  4657,  4658,  4659,
    4660,  4661,  4662,  4663,  4664,  4665,  4666,  4667,  4668,  4669,
    4670,  4671,  4672,  4673,  4674,  4675,  4676,  4677,  4678,  4679,
    4680,  4681,  4690,  4691,  4692,  4693,  4694,  4695,  4696,  4697,
    4698,  4699,  4700,  4705,  4704,  4712,  4717,  4734,  4752,  4770,
    4788,  4806,  4811,  4817,  4829,  4846,  4864,  4882,  4900,  4921,
    4926,  4931,  4941,  4951,  4956,  4967,  4976,  4981,  5008,  5012,
    5016,  5020,  5024,  5031,  5035,  5039,  5043,  5050,  5055,  5062,
    5067,  5071,  5076,  5080,  5088,  5099,  5103,  5115,  5123,  5131,
    5138,  5148,  5177,  5181,  5185,  5189,  5193,  5197,  5201,  5205,
    5209,  5238,  5267,  5296,  5325,  5338,  5351,  5364,  5377,  5387,
    5397,  5409,  5422,  5434,  5452,  5473,  5478,  5482,  5486,  5498,
    5502,  5514,  5521,  5531,  5535,  5550,  5555,  5562,  5566,  5579,
    5587,  5598,  5602,  5606,  5614,  5620,  5626,  5634,  5642,  5649,
    5664,  5678,  5692,  5704,  5720,  5729,  5738,  5748,  5759,  5763,
    5782,  5789,  5796,  5795,  5808,  5813,  5819,  5828,  5841,  5844,
    5848
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
  "tStrCat", "tStrPrefix", "tStrRelative", "tStrReplace", "tFind",
  "tStrFind", "tStrCmp", "tStrChoice", "tUpperCase", "tLowerCase",
  "tLowerCaseIn", "tTextAttributes", "tBoundingBox", "tDraw",
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
  "tIn", "tEndFor", "tIf", "tElse", "tEndIf", "tExit", "tAbort", "tField",
  "tReturn", "tCall", "tMacro", "tShow", "tHide", "tGetValue", "tGetEnv",
  "tGetString", "tGetNumber", "tHomology", "tCohomology", "tBetti",
  "tSetOrder", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tGmshExecutableName",
  "tSetPartition", "tNameFromString", "tStringFromName", "tAFFECTDIVIDE",
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND",
  "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC", "tMINUSMINUS",
  "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'", "'#'", "','",
  "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems", "GeoFormatItem",
  "SendToFile", "Printf", "View", "Views", "ElementCoords",
  "ElementValues", "Element", "@1", "@2", "Text2DValues", "Text2D", "@3",
  "Text3DValues", "Text3D", "@4", "InterpolationMatrix", "Time", "@5",
  "NumericAffectation", "NumericIncrement", "LP", "RP", "Affectation",
  "Comma", "DefineConstants", "@6", "@7", "UndefineConstants",
  "Enumeration", "FloatParameterOptions", "FloatParameterOption",
  "CharParameterOptions", "CharParameterOption", "PhysicalId0",
  "PhysicalId1", "PhysicalId2", "PhysicalId3", "InSphereCenter",
  "CircleOptions", "Shape", "Transform", "MultipleShape", "ListOfShapes",
  "LevelSet", "Delete", "Colorify", "SetPartition", "Visibility",
  "Command", "Loop", "Extrude", "@8", "@9", "@10", "@11", "@12", "@13",
  "@14", "@15", "@16", "@17", "@18", "@19", "@20", "ExtrudeParameters",
  "ExtrudeParameter", "TransfiniteType", "TransfiniteArrangement",
  "TransfiniteCorners", "RecombineAngle", "PeriodicTransform",
  "Constraints", "Coherence", "HomologyCommand", "Homology", "FExpr",
  "FExpr_Single", "@21", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "@22",
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
     425,   426,   427,   428,   429,   430,   431,    63,   432,   433,
     434,   435,    60,    62,   436,   437,    43,    45,    42,    47,
      37,    33,   438,   439,   440,    94,    40,    41,    91,    93,
      46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   206,   207,   207,   208,   208,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   210,   210,   211,   211,   211,   211,   211,   211,
     212,   212,   212,   212,   213,   213,   213,   213,   213,   213,
     214,   214,   215,   215,   217,   218,   216,   219,   219,   221,
     220,   222,   222,   224,   223,   225,   225,   227,   226,   228,
     228,   228,   228,   228,   229,   229,   230,   230,   231,   231,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   233,   233,   234,
     234,   234,   235,   234,   234,   236,   234,   237,   237,   238,
     238,   239,   239,   240,   240,   240,   241,   241,   242,   242,
     242,   242,   243,   243,   243,   244,   244,   244,   245,   245,
     245,   246,   246,   246,   247,   247,   248,   248,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   250,   250,   250,
     250,   250,   250,   250,   250,   251,   251,   252,   252,   252,
     252,   252,   252,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   254,   254,   254,   254,   254,   255,   255,   256,
     257,   257,   257,   257,   257,   257,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   260,
     260,   260,   261,   260,   262,   260,   263,   260,   264,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   265,
     260,   266,   260,   267,   260,   268,   260,   269,   260,   270,
     260,   271,   260,   272,   260,   273,   260,   274,   274,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   276,   276,   277,   277,   278,   278,
     279,   279,   280,   280,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     282,   282,   282,   283,   283,   283,   284,   284,   284,   284,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   287,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   288,   288,
     288,   288,   288,   289,   289,   289,   289,   290,   290,   291,
     291,   291,   291,   291,   291,   292,   292,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   294,   294,   294,   294,   295,
     295,   295,   295,   296,   296,   297,   297,   298,   298,   298,
     298,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   300,   299,   301,   301,   302,   302,   303,   303,
     303
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     5,     5,     7,     7,     7,     9,
       6,     6,     6,     8,     0,     2,     2,     2,     2,     2,
       1,     3,     1,     3,     0,     0,    10,     1,     3,     0,
      13,     1,     3,     0,    15,     8,    14,     0,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     7,     7,     4,     6,     6,     7,     7,     7,
       7,     9,     9,     3,     6,     6,     6,     6,     4,     6,
       9,     6,     9,     5,     8,     8,    11,     6,     9,     5,
       7,     9,     9,    11,     7,     9,     9,     0,     1,     0,
       3,     5,     0,     9,     5,     0,     9,     0,     3,     3,
       5,     0,     2,     3,     5,     3,     0,     2,     3,     3,
       3,     5,     1,     1,     3,     1,     1,     3,     1,     1,
       3,     1,     1,     3,     0,     5,     0,     2,     7,     8,
       6,     7,     4,     7,     8,     8,     7,     7,    11,     8,
       8,     8,     8,     9,     3,     4,    10,     7,     7,     8,
       8,    12,     8,     8,     7,     8,     8,     5,    11,     5,
       9,     9,     4,     9,     9,     1,     1,     0,     2,     6,
       6,     6,     6,     8,    10,    14,    16,    12,     8,     8,
       6,    14,     4,     6,     6,     3,     4,     5,     6,     5,
       3,     3,     4,     5,     4,     5,     3,     5,     7,     7,
       3,     7,     3,     2,     2,     2,     2,     2,    15,     2,
       2,     2,     2,     2,    16,     3,     6,     8,     8,    10,
       1,     2,     2,     1,     3,     3,     4,     1,     1,     5,
      11,    13,     0,     7,     0,    13,     0,    15,     0,     6,
       8,     8,     8,    12,    12,    12,    14,    14,    14,     0,
      12,     0,    12,     0,    12,     0,    16,     0,    16,     0,
      16,     0,    18,     0,    18,     0,    18,     1,     2,     5,
       7,     9,     2,     2,     2,     3,     2,     3,     2,     3,
       2,     3,     9,     6,     0,     3,     0,     1,     0,     2,
       0,     2,     0,     2,     7,     6,     8,     5,     3,     7,
       5,     4,     6,    11,    11,    18,    18,    12,    12,    12,
      10,    10,    10,    10,    10,     4,     4,     4,     4,     4,
       2,     3,     6,     1,     1,     1,     2,     5,     7,    10,
       1,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     4,     6,     6,
       6,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     4,     1,     4,     4,     4,
       4,     4,     4,     4,     2,     5,     5,     5,     5,     3,
       6,     4,     7,     6,     6,     6,     6,     4,     1,     2,
       2,     3,     3,    11,     9,     7,     7,     1,     3,     1,
       1,     2,     3,     4,     5,     1,     1,     2,     3,     3,
       5,     4,     2,     2,     2,     2,     3,     3,     3,     3,
       5,     5,     5,     5,    16,    16,    16,    16,     1,     1,
       3,     3,     4,     6,     6,     1,     1,     3,     3,     9,
       7,     1,     5,     3,     6,     1,     3,     1,     1,     3,
       6,     1,     4,     1,     1,     1,     4,     6,     4,     4,
       4,     4,     8,     4,     4,     4,     4,     8,     4,     6,
       4,     1,     0,     6,     1,     3,     5,     5,     1,     1,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   518,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,   247,   248,     0,     0,     0,   243,
       0,     0,     0,     0,   343,   344,   345,     0,     0,     0,
       5,     7,     6,     8,     9,    10,    20,    11,    12,    13,
      14,    19,    18,    15,    16,    17,     0,    21,   519,     0,
     392,   518,   491,   393,   395,   396,   394,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   493,     0,   511,   495,   400,   401,   402,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   397,
     398,   399,   494,     0,     0,     0,     0,    66,    67,     0,
       0,   187,     0,     0,     0,   350,     0,   487,   519,   406,
       0,     0,     0,     0,   227,     0,   229,   230,   225,   226,
       0,   231,   232,   109,   117,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   428,     0,     0,     0,
       0,     0,   187,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   518,     0,   187,   519,     0,     0,   340,     0,
       0,     0,     0,     0,     0,     0,     0,   518,   446,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   468,   469,
     439,   445,     0,   440,   519,   406,     0,     0,     0,     0,
     481,     0,     0,     0,     0,     0,   223,   224,     0,   518,
       0,     0,   241,   242,     0,   187,     0,   187,   518,     0,
       0,     0,   346,     0,     0,    66,    67,     0,     0,    59,
      63,    62,    61,    60,    65,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   353,
     352,   354,     0,     0,     0,     0,     0,     0,     0,   186,
       0,   185,     0,    68,    69,     0,     0,   220,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,   216,     0,     0,   414,   164,     0,
     518,     0,   487,   488,     0,     0,   514,     0,   107,   107,
       0,     0,     0,     0,   475,   476,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   308,   308,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,   187,     0,   430,   429,     0,
       0,     0,     0,   187,   187,     0,     0,     0,     0,     0,
       0,     0,   258,     0,   187,     0,     0,     0,     0,     0,
     310,     0,     0,     0,     0,     0,     0,     0,   205,   341,
       0,     0,     0,     0,     0,     0,     0,     0,    66,    67,
       0,     0,     0,   452,     0,     0,   453,     0,   454,     0,
     455,     0,     0,     0,     0,     0,     0,   352,   447,     0,
     441,     0,     0,     0,   318,    66,    67,     0,   222,     0,
       0,     0,     0,     0,   187,     0,     0,     0,     0,   245,
     244,   210,     0,   211,     0,     0,   235,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       0,     0,   419,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     403,   512,     0,     0,     0,     0,     0,     0,     0,     0,
     351,     0,    59,     0,     0,     0,     0,     0,   182,     0,
       0,     0,     0,   188,     0,     0,    59,     0,     0,   368,
     367,   366,   365,   361,   362,   364,   363,   356,   355,   357,
     358,   359,   360,     0,     0,     0,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   337,   338,   339,     0,     0,     0,     0,   306,
       0,     0,     0,   132,   133,     0,   135,   136,     0,   138,
     139,     0,   141,   142,     0,     0,     0,     0,     0,     0,
       0,   152,   187,     0,     0,     0,     0,     0,   432,   431,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   252,
       0,     0,     0,     0,     0,     0,     0,   321,     0,     0,
     206,     0,     0,   202,     0,     0,     0,   336,   335,     0,
       0,     0,     0,   419,     0,   470,     0,     0,     0,     0,
       0,     0,   456,     0,   457,     0,   458,     0,   459,     0,
       0,   351,   442,   449,     0,   357,   448,     0,   471,     0,
       0,     0,     0,     0,     0,     0,     0,   246,     0,   212,
     214,     0,   520,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    74,     0,   408,   407,   421,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   391,   379,     0,   381,
     382,   383,   384,   385,   386,   387,     0,     0,     0,   503,
       0,   508,   499,   500,   501,     0,     0,     0,     0,     0,
     504,   505,   506,   427,   510,   121,   126,    99,     0,   496,
     498,     0,   405,   411,   412,   492,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,     0,   413,     0,
       0,     0,     0,   516,     0,     0,     0,    44,     0,     0,
       0,    57,     0,    35,    36,    37,    38,    39,   410,   409,
       0,   489,    24,    22,     0,     0,    25,     0,     0,   217,
     515,    70,   110,    71,   118,     0,     0,     0,   477,   478,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   304,   309,
     307,     0,   317,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     213,   215,     0,     0,     0,   177,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   287,     0,   249,     0,     0,     0,     0,     0,
       0,   311,   320,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   407,     0,   472,     0,   451,     0,     0,
       0,     0,     0,     0,     0,   443,     0,     0,     0,     0,
       0,     0,     0,     0,   207,     0,     0,     0,     0,   209,
       0,     0,   347,     0,     0,     0,     0,   517,     0,     0,
       0,   416,     0,   415,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,     0,     0,     0,     0,    84,    89,    91,     0,     0,
     485,     0,    97,     0,     0,     0,     0,     0,    75,   369,
       0,     0,     0,     0,     0,    30,   418,   417,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,     0,     0,     0,     0,     0,     0,     0,
     315,     0,     0,   134,     0,   137,     0,   140,     0,   143,
       0,     0,     0,     0,     0,     0,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,     0,   292,
       0,   298,     0,   300,     0,   294,     0,   296,     0,   259,
     288,     0,     0,     0,   200,     0,     0,     0,   322,     0,
     204,   203,   342,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,   460,   461,   462,   463,   450,   444,
       0,     0,     0,     0,   482,     0,     0,     0,   236,     0,
       0,     0,     0,     0,    87,     0,    86,     0,    76,   219,
     420,   218,   380,   388,   389,   390,   509,     0,   424,   425,
     426,     0,     0,   404,   122,     0,   513,   127,   423,   497,
      78,    59,     0,     0,     0,     0,    77,     0,     0,     0,
     483,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     437,     0,     0,    26,    27,     0,    28,     0,     0,   111,
     114,    72,    73,   148,     0,     0,     0,     0,     0,     0,
     151,     0,     0,   167,   168,     0,     0,   153,   174,     0,
       0,     0,     0,   144,     0,   314,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   221,     0,     0,
       0,     0,   187,   187,     0,   269,     0,   271,     0,   273,
       0,   439,     0,     0,   299,   301,   295,   297,     0,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     319,     0,   420,   473,     0,     0,     0,     0,   474,   156,
     157,     0,     0,     0,     0,   100,   104,     0,     0,   348,
      80,    79,     0,   422,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,    95,     0,   486,   189,   190,   191,
     192,     0,     0,    40,     0,     0,     0,     0,     0,    42,
     490,     0,     0,   112,   115,     0,     0,   147,   154,   155,
     159,     0,     0,   169,     0,     0,   316,     0,   162,     0,
       0,   305,   173,   149,   161,   172,   176,   160,     0,   170,
     175,     0,     0,     0,     0,     0,     0,   436,     0,   435,
       0,     0,     0,   260,     0,     0,   261,     0,     0,   262,
       0,     0,     0,     0,     0,     0,     0,   199,     0,     0,
     198,     0,     0,     0,   193,     0,     0,    33,     0,     0,
       0,     0,     0,     0,   480,     0,   238,   237,     0,     0,
       0,     0,     0,   502,   507,     0,   123,   125,     0,   128,
     129,   130,    90,    92,     0,    98,     0,    81,    45,     0,
       0,     0,   438,     0,     0,     0,    29,     0,   121,   126,
       0,     0,     0,     0,     0,     0,     0,     0,   163,     0,
     312,   312,     0,   105,   106,   187,     0,   180,   181,     0,
       0,     0,     0,     0,     0,     0,   289,     0,     0,   187,
       0,     0,     0,     0,     0,   184,   183,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   102,     0,    82,     0,
     475,     0,     0,   484,     0,    41,     0,     0,     0,    43,
      58,     0,     0,     0,   330,   332,   331,   333,   334,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   303,     0,     0,     0,   254,     0,     0,
     194,     0,     0,     0,     0,     0,     0,     0,   479,   239,
       0,   349,     0,   124,     0,   131,    96,     0,     0,     0,
       0,     0,   113,   116,     0,     0,     0,     0,     0,   313,
     323,     0,     0,   324,     0,   178,     0,   275,     0,     0,
     277,     0,     0,   279,     0,     0,     0,   290,     0,   250,
       0,   187,     0,     0,     0,     0,     0,     0,     0,   158,
     103,     0,   119,     0,    49,     0,    55,     0,     0,     0,
     145,   171,     0,   327,     0,   328,   329,   433,   263,     0,
       0,   270,   264,     0,     0,   272,   265,     0,     0,   274,
       0,     0,     0,   256,     0,   197,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,   283,     0,   285,   291,   302,   255,
     251,     0,     0,     0,     0,     0,     0,     0,     0,   120,
      46,     0,    53,     0,     0,     0,     0,     0,     0,   266,
       0,     0,   267,     0,     0,   268,     0,     0,   201,     0,
     195,     0,     0,     0,     0,     0,    47,     0,     0,   228,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
       0,     0,   276,     0,   278,     0,   280,     0,   196,     0,
       0,     0,     0,    48,    50,     0,    51,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,    56,
     325,   326,   282,   284,   286,    52,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,   934,    91,    92,   683,  1402,  1408,
     923,  1110,  1574,  1775,   924,  1724,  1815,   925,  1777,   926,
     927,  1114,   346,   437,   183,   416,    93,   698,   448,  1518,
    1519,   449,  1569,  1085,  1254,  1086,  1257,   732,   735,   738,
     741,  1430,  1297,   663,   298,   410,   411,    96,    97,    98,
      99,   100,   101,   102,   299,  1015,  1670,  1741,   767,  1454,
    1457,  1460,  1699,  1703,  1707,  1760,  1763,  1766,  1011,  1012,
    1149,   971,   729,   776,  1596,   104,   105,   106,   107,   300,
     185,   885,   498,   256,  1279,   301,   302,   303,   561,   312,
     907,  1101,   446,   442,   886,   447,   188,   305
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1348
static const yytype_int16 yypact[] =
{
    6996,    78,    96,  7116, -1348, -1348,  3513,    77,    49,   -96,
     -75,    35,   144,   158,   202,   211,    61,   243,   257,    70,
      76,   190,   190,     3,    82,   106,    25,   133,   154,    17,
     198,   225,   283,   340,   383,   478,   291,   288,   413,   422,
     687,   423,   483,   694,   -49,   338,   475,     1,   339,   -94,
     -94,   361,   456,   328,   237,   500,   506,    24,    53,   534,
     559,   -34,   643,   650,   657,  4860,   684,   466,   498,   514,
      19,    51, -1348,   530, -1348, -1348,   723,   724,   538, -1348,
    5136,  5526,    34,    37, -1348, -1348, -1348,  6857,  6857,   541,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348,    -2, -1348,   153,   131,
   -1348,     4, -1348, -1348, -1348, -1348, -1348,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   544,   552,   558,   564,   571,   589,   190,   190,
     190,   190,   602, -1348,   190, -1348, -1348, -1348, -1348, -1348,
     190,   190,   812,   624,   631,   632,   190,   642,   672, -1348,
   -1348, -1348, -1348,   641,  6857,  6857,  6857,  6857,  6857,   132,
      16,    22,   673,   -64,   391, -1348,   674,   876,   227,    88,
     884,  6857,  5331,  5331, -1348,  6857, -1348, -1348, -1348, -1348,
    5331, -1348, -1348, -1348, -1348, -1348, -1348,  5718,    16,  6857,
    6668,  6857,  6857,   698,  6857,  6668,  6857,  6857,   714,  6668,
    6857,  6857,  5250,   715,   729, -1348,  6668,  4860,  4860,  4860,
     719,   739,  4860,  4860,  4860,   743,   747,   750,   775,   779,
     801,   802,   806,   753,  6225,   956,  5250,    19,   771,   780,
     -94,   -94,   -94,  6857,  6857,   -83, -1348,   -71,   -94,   800,
     846,   849,  6284,   -38,    87,   848,   883,   897,  4860,  4860,
    5250,   906,     5,   786, -1348,   868,  1066,  1095, -1348,   903,
     925,   927,  4860,  4860,   933,   934,   935,   300, -1348,   936,
       8,    20,    26,    27,   813,  5445,  6857,  4008, -1348, -1348,
    3952, -1348,  1119, -1348,   270,   -40,  1130,  6857,  6857,  6857,
     938,  6857,   937,   996,  6857,  6857, -1348, -1348,  6857,   940,
    1136,  1140, -1348, -1348,  1141, -1348,  1144, -1348,   565,   827,
    7867,  5331, -1348,  5250,  5250,  6857,  6857,   949,   309,  5718,
   -1348, -1348, -1348, -1348, -1348, -1348,  5250,  1148,   958,  6857,
    6857,  1156,  6857,  6857,  6857,  6857,  6857,  6857,  6857,  6857,
    6857,  6857,  6857,  6857,  6857,  6857,  6857,  6857,  6857,  6857,
    6857,  6857,  6857,  6857,  5331,  5331,  5331,  5331,  5331,  5331,
    5250,  5331,  5331,  6857,  5331,  5331,  5331,  5331,  5331,  6857,
    5718,  6857,  5331,  5331,  5331,  5331,    16,  5718,    16,   966,
     966,   966,  4565,  8985,   160,   962,  1166,   190,   973, -1348,
     974,  5879,  6857, -1348, -1348,  6668,    10, -1348,  6857,  6857,
    6857,  6857,  6857,  6857,  6857,  6857,  6857,  6857,  6857,  6857,
    6857,  6857,  6857, -1348, -1348,  6857,  6857, -1348, -1348,  1048,
    -134,  -114, -1348, -1348,   -21,  5050, -1348,    -4,   259,   265,
     975,   979,  9330,  6668,  4149, -1348,   251,  9351,  9372,  6857,
    9393,   359,  9414,  9435,  6857,   419,  9456,  9477,  1178,  6857,
    6857,   449,  1181,  1183,  1186,  6857,  6857,  1188,  1190,  1190,
    6857,  6479,  6479,  6479,  6479,  6857,  6857,  6857,  6668,  6668,
    7894,  1001,  1187,   997, -1348, -1348,   -92, -1348, -1348,  5245,
    5440,   -94,   -94,    22,    22,    98,  6857,  6857,  6857,  6284,
    6284,  6857,  5879,   124, -1348,  6857,  6857,  6857,  6857,  6857,
    1192,  1195,  1198,  6857,  1196,  6857,  6857,   841, -1348, -1348,
    6668,  6668,  6668,  1200,  1201,  6857,  6857,  6857,  6857,  6857,
    1205,   390,    16, -1348,  1157,  6857, -1348,  1158, -1348,  1159,
   -1348,  1160,    38,    39,    41,    42,  6668,   966, -1348,  9498,
   -1348,   584,  6857,  5640, -1348,  6857,  6857,   398, -1348,  9519,
    9540,  9561,  1070,  5635, -1348,  1013,  4169,  9582,  9008, -1348,
   -1348, -1348,  1087, -1348,  1317,  6857, -1348, -1348,  1021,  1024,
     597,  9603,  9031,  6857,  6668,    10,  1235,  1236, -1348,  6857,
    9624,  9054,   115,  8962,  8962,  8962,  8962,  8962,  8962,  8962,
    8962,  8962,  8962,  8962,  6025,  8962,  8962,  8962,  8962,  8962,
    8962,  8962,  6279,  6663,  7948,   520,   578,   520,  1050,  1051,
    1043,  1047,  1049,  1053,  7974,   613,   613,   613,   118,   613,
    4799, -1348,  1248,  1054,  1055,   252,   613,  1056,  1060,  1061,
     172,   123,  5718,  6857,  1244,  1257,    30,   613, -1348,    90,
      36,    33,   184, -1348,  6376,   658, -1348,  5250,  4352,  1420,
    1316,   661,   661,   173,   173,   173,   173,   229,   229,   966,
     966,   966,   966,    14,  9645,  9077, -1348,  6857,  1258,     9,
    6668,  1259,  6668,  6857,  1260,  5331,  1261, -1348,    16,  1263,
    5331,  6857,  5718,  1256,  6668,  6668,  1121,  1264,  1267,  9666,
    1268,  1127,  1269,  1270,  9687,  1135,  1272,  1273,  6857,  9708,
    6404,  1078, -1348, -1348, -1348,  9729,  9750,  6857,  5250,  1279,
    1280,  9771,  1090,  4799,  1086,  1093,  4799,  1100,  1106,  4799,
    1102,  1108,  4799,  1105,  9792,  9813,  9834,   667,   679,  6668,
    1097, -1348, -1348,  1481,  1610,   -94,  6857,  6857, -1348, -1348,
    1104,  1107,  6284,  8000,  8026,  8052,  4855,   431,   -94,  1792,
    9855,  6435,  9876,  9897,  9918,  6857,  1303, -1348,  6857,  9939,
   -1348,  9100,  9123, -1348,   689,   701,   712, -1348, -1348,  9146,
    9169,  8078,  9192,   -40,  6668, -1348,  1111,  1109,  6607,  1112,
    1113,  1114, -1348,  6668, -1348,  6668, -1348,  6668, -1348,  6668,
     725, -1348, -1348,  4630,  6668,   966, -1348,  6668, -1348,  1307,
    1311,  1312,  1120,  6857,  2077,  6857,  6857, -1348,    46, -1348,
   -1348,  2398, -1348,  1122,  5250,  1318,   172,   172,  6753,   748,
    5250, -1348, -1348,  9215,   -40,  1046, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,  6857, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348,  6857,  6857,  6857, -1348,
    6668, -1348, -1348, -1348, -1348,  5331,  5250,  5331,  5331,  5718,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,  6857, -1348,
   -1348,  5331, -1348, -1348, -1348, -1348,  6857,  1320,   136,  6857,
    1321,  1322,  1289, -1348,  1324,  1134,    19,  1327, -1348,  6668,
    6668,  6668,  6668, -1348,   613,  1329,  6857, -1348,  1145,  1147,
    1142, -1348,  1331, -1348, -1348, -1348, -1348, -1348,   -40,   -40,
    9238, -1348, -1348,  1161,  5331,   425, -1348,   616,  8104, -1348,
   -1348, -1348,  1340, -1348, -1348,  8962,   613,   -94,  4149, -1348,
     781,  5250,  5250,  1341,  5250,   877,  5250,  5250,  1347,  1274,
    5250,  5250,  1475,  1352,  1353,  6668,  1354,  1355,  2105, -1348,
   -1348,  1357, -1348,  1362,    10,  6857,    10,  6857,    10,  6857,
      10,  6857,  1363,  1369,  1370,  1374,  1375,   761,  1360,  2547,
   -1348, -1348,   155,  8130,  8156, -1348, -1348,  6781,  -105,   -94,
     -94,   -94,  1381,  1380,  1184,  1382,  1193,    29,    32,    50,
      52,   -13, -1348,   276, -1348,   431,  1384,  1386,  1398,  1399,
    1400,  4799, -1348,  1763,  1212,  1402,  1410,  1411,  1337,  6857,
    1414,  1415,  6857,   -32,   764, -1348,  6857, -1348,  6857,  6857,
    6857,   765,   777,   778,   783, -1348,  6857,   787,   788,  5250,
    5250,  5250,  1418,  8182, -1348,  4818,   336,  1419,  1436, -1348,
    5250,  1237, -1348,  6857,  1438,  6857,  1439, -1348,   613,  1440,
    1441, -1348,  1451, -1348,  1450,  8962,  8962,  8962,  8962,   585,
    1240,  1262,  1265,  1266,  1255,   595,   606,  9960,  1283,  2002,
   -1348,   254,  1282,  1454,  2038, -1348, -1348, -1348,    19,  6857,
   -1348,   791, -1348,   792,   816,   817,   822,    10, -1348,  4799,
    1287,  6857,  6857,  5250,  1284, -1348, -1348, -1348,  1286, -1348,
    1452,    13,  1458,  6857,  3439,  1482,  1483,    66,  1288,  1305,
    1417,  1417,  5250,  1484,  1310,  1314,  1508,  1509,  5250,  1315,
    1513,  1514, -1348,  1517,  5250,   823,  5250,  5250,  1520,  1519,
   -1348,  5250,  5250,  4799,  5250,  4799,  5250,  4799,  5250,  4799,
    5250,  5250,  5250,  1325,  1328,  1523,   332, -1348,  6857,  6857,
    6857,  1330,  1332,  -126,  -117,  -113,  1334, -1348,  5250, -1348,
    6857, -1348,  1521, -1348,  1528, -1348,  1530, -1348,  1531, -1348,
   -1348,  6284,   625,  5055, -1348,  1335,  1343,  5835, -1348,  6668,
   -1348, -1348, -1348,  1344,  2508, -1348, -1348,  9261,  1536,   613,
    8208,  8234,  8260,  8286, -1348, -1348, -1348, -1348,  4799, -1348,
     613,  1538,  1542,  1413, -1348,  6857,  6857,  6857, -1348,  1543,
     349,  1365,  1549,  2575, -1348,  2760, -1348,    10, -1348, -1348,
     119, -1348, -1348, -1348, -1348, -1348, -1348,  5331, -1348, -1348,
   -1348,  5718,  1552, -1348, -1348,    18, -1348, -1348, -1348, -1348,
   -1348,  5718,  6857,  1563,  1566,    30, -1348,  1565,  9284,    19,
   -1348,  1569,  1573,  1574,  1575,  5250,  6857,  8312,  8338,   826,
   -1348,  6857,  1568, -1348, -1348,  5331, -1348,  8364,  4210,  4799,
   -1348, -1348, -1348, -1348,  6857,  6857,   -94,  1577,  1578,  1579,
   -1348,  6857,  6857, -1348, -1348,  1580,  6857, -1348, -1348,  1582,
    1583,  1385,  1584,  1448,  6857, -1348,  1589,  1590,  1591,  1606,
    1607,  1608,  1027,  1613,  6668,  6668,  6857, -1348,  6479,  7111,
    9981,  5969,    22,    22,   -94,  1614,   -94,  1615,   -94,  1618,
    6857,   256,  1423, 10002, -1348, -1348, -1348, -1348,  7139,   350,
   -1348,  1620,  3791,  1621,  5250,   -94,  3791,  1622,   830,  6857,
   -1348,  1623,   -40, -1348,  6857,  6857,  6857,  6857, -1348, -1348,
   -1348,  5250,  6181,   489, 10023, -1348, -1348,  4600,  5250, -1348,
   -1348, -1348,  5250, -1348,  1433,   613,  4405,  4665,  5718,  1625,
    2804, -1348,  1626,  1630, -1348,  1432, -1348, -1348, -1348, -1348,
   -1348,  1631,   633,  4799,  6857,  6857,  5250,  1435,   833,  4799,
   -1348,  1633,  6857, -1348, -1348,  7167,  7195,   224, -1348, -1348,
   -1348,  7223,  7251, -1348,  7279,  1635, -1348,  5250, -1348,  1561,
    1636,  4799, -1348, -1348, -1348, -1348, -1348, -1348,  1442, -1348,
   -1348,   834,   837,  7921,  2839,  1637,  1443, -1348,  6857, -1348,
    1444,  1445,   397, -1348,  1447,   442, -1348,  1463,   444, -1348,
    1464,  9307,  1638,  5250,  1661,  1469,  6857, -1348,  6030,   446,
   -1348,   838,   453,   463, -1348,  1667,  7307, -1348,  8390,  8416,
    8442,  8468,  1537,  6857, -1348,  6857, -1348, -1348,  6668,  3123,
    1670,  1473,  1672, -1348, -1348,  4008, -1348, -1348,  5331,  4799,
   -1348, -1348, -1348, -1348,    19, -1348,  1539, -1348, -1348,  6857,
    8494,  8520, -1348,  5250,  6857,  1673, -1348,  8546, -1348, -1348,
    1675,  1676,  1677,  1692,  1693,  1694,   851,  1498, -1348,  5250,
     554,   582,  6668, -1348, -1348,    22,  6220, -1348, -1348,  6284,
     431,  6284,   431,  6284,   431,  1698, -1348,   854,  5250, -1348,
    7335,   -94,  1702,  6668,   -94, -1348, -1348,  6857,  6857,  6857,
    6857,  6857,  7363,  7391,   857, -1348, -1348,  1703, -1348,   858,
    3575,   861,  1704, -1348,  1510,  4799,  6857,  6857,   862,  4799,
   -1348,  6857,   866,   867, -1348, -1348, -1348, -1348, -1348, -1348,
    1511,  6857,   878,  1512,   -94,  5250,  1710,  1515,   -94,  1711,
     879,  1516,  6857, -1348,  7419,   494,   697,  7447,   496,   760,
    7475,   513,  1174, -1348,  5250,  1713,  1627,  2719,  1524,   518,
   -1348,   890,   521,  8572,  8598,  8624,  8650,  3471, -1348, -1348,
    1722, -1348,  6857, -1348,  5718, -1348, -1348,  6857, 10044,  8676,
      45,  8702, -1348, -1348,  6857,  7503,  1725,   -94,    69, -1348,
   -1348,   -94,    73, -1348,  1726, -1348,  7531,  1727,  6857,  1728,
    1729,  6857,  1730,  1731,  6857,  1733,  1540, -1348,  6857, -1348,
     431, -1348,  6668,  1735,  6030,  6857,  6857,  6857,  6857, -1348,
   -1348,  3786, -1348,   905, -1348,  6857, -1348,  5250,  6857,  8728,
   -1348, -1348,   526, -1348,   545, -1348, -1348, -1348, -1348,  1546,
    7559, -1348, -1348,  1548,  7587, -1348, -1348,  1550,  7615, -1348,
    1737,  3544,  1247,  3081,   909, -1348,   551,   910,  8754,  8780,
    8806,  8832,  5718,  1744,  1551, 10065,   913,  7643,  6857,   -94,
     -94,   431,  1746,   431,  1749,   431,  1754, -1348, -1348, -1348,
   -1348,   431,  1759,  6668,  1764,  6857,  6857,  6857,  6857, -1348,
   -1348,  5331, -1348,  1571,  1765,  7671,   570,   572,  1894, -1348,
    1576,  1997, -1348,  1585,  2151, -1348,  1586,  2218, -1348,   914,
   -1348,  8858,  8884,  8910,  8936,   918, -1348,  1587,  5250, -1348,
    1770,  6857,  6857,  1771,   431,  1772,   431,  1774,   431, -1348,
    1775,  6857,  6857,  6857,  6857,  5331,  1776,  5331,   919, -1348,
    7699,  7727, -1348,  2431, -1348,  2470, -1348,  2758, -1348,  7755,
    7783,  7811,  7839, -1348, -1348,   922, -1348,  1777,  1781,  1787,
    1789,  1790,  1791, -1348, -1348, -1348, -1348,  5331,  1793, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1348, -1348, -1348, -1348,   677, -1348, -1348, -1348, -1348,   165,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348,  -380,  -103,  2258,    -1, -1348,  1358, -1348, -1348,
   -1348, -1348, -1348,   285, -1348,   287, -1348, -1348, -1348, -1348,
   -1348, -1348,   680,  1805,     7,  -492,  -260, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348,  1807, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,  -952,  -903,
   -1348, -1348,  1333, -1348,   282, -1348, -1348, -1348, -1348,  1547,
   -1348, -1348,     0, -1348, -1347,  2238,  -110,  2447,  1297,  -246,
     550, -1348,    21,    62, -1348,  -371,    -3,    95
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -491
static const yytype_int16 yytable[] =
{
     108,   493,   512,   625,   332,   627,   347,  1471,   348,   524,
      95,   760,   761,   543,   527,   932,   638,   666,   917,  1284,
     319,   218,  1387,   310,   653,   546,   408,   186,   272,   213,
     243,   548,   550,   244,   905,  1181,   667,   218,  1183,   324,
     213,   194,   326,   802,   804,   282,   806,   808,   283,   255,
     257,  1686,   263,  1057,   275,   313,  1185,   277,  1187,   278,
     501,   502,   304,  1192,   687,   582,   688,   584,   187,   501,
     502,   182,  1293,   501,   502,  1693,  1334,   275,  1335,  1695,
    1526,   501,   502,   689,     4,  1336,  1002,  1337,   690,  1338,
     190,  1339,   251,   252,   501,   502,     5,  1003,   109,  1172,
     192,   189,   253,   501,   502,  1004,  1005,  1006,  1190,   254,
     755,  1007,  1008,  1009,  1010,   501,   502,   472,   473,   474,
     503,   193,   477,   478,   479,    48,    49,    50,    51,   279,
     666,   191,   504,   413,    56,   414,   404,    59,   339,   415,
    1091,   247,   320,   323,   918,   919,   920,   921,   501,   502,
     196,   544,   276,   344,   345,   248,   249,  1182,   520,   521,
    1184,   344,   345,   547,   197,   514,  1578,   652,  1208,   549,
     551,  1388,   533,   534,   273,   321,   691,   275,  1186,   666,
    1188,   692,  1592,   340,   341,   342,   343,    89,   409,   275,
     275,  1189,   933,   694,   333,    89,   933,   275,   695,   209,
     349,   334,   350,   525,   351,   275,   210,   304,   198,   182,
     182,   545,   304,   441,   444,   840,   304,   199,   922,   304,
     219,   214,   311,   304,   304,   304,   304,   274,   215,   304,
     304,   304,   214,   906,   753,   754,   911,   325,   195,   910,
     327,   803,   805,   304,   807,   809,  1058,   314,  1687,   201,
     496,   497,   501,   502,   769,   501,   502,   200,   505,   501,
     502,  1261,   513,   202,   562,   304,   304,   304,   203,   450,
     896,   899,   405,   406,   204,   407,  1092,  1093,   211,   304,
     304,   344,   345,   515,   501,   502,   209,   443,   443,  1190,
     516,  -488,   304,   909,   304,   443,   340,   341,   342,   343,
     762,   654,   212,   451,   340,   341,   342,   343,   344,   345,
     501,   502,   344,   345,   824,   883,   344,   345,  -489,   268,
     695,   269,  -490,   898,   344,   345,   768,   831,   275,   216,
     304,   304,   264,   340,   341,   342,   343,   595,  1327,  1328,
    1726,   501,   502,   304,  1227,   340,   341,   342,   343,   335,
     217,   336,   588,   344,   345,  1376,  1377,  1168,   337,   427,
     428,   429,   430,   431,   227,   344,   345,   228,   432,   222,
     229,   275,   275,   275,   275,   275,   275,   304,   275,   275,
     221,   275,   275,   275,   275,   275,   205,   912,   206,   275,
     275,   275,   275,   275,   220,   275,   626,   417,   628,   629,
     630,   596,   632,   633,   265,   635,   636,   637,   266,   639,
     501,   502,   304,   643,   644,   645,   646,   429,   430,   431,
     267,   221,   223,   435,   432,   436,   443,   340,   341,   342,
     343,  1798,   337,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   563,   430,   431,   344,   345,   890,
     304,   432,   641,   705,   891,   706,  1063,  1065,   696,   648,
    1462,   697,   501,   502,   699,   224,   565,   697,   566,   443,
     443,   443,   443,   443,   443,   337,   443,   443,  1191,   443,
     443,   443,   443,   443,   225,   304,   304,   443,   443,   443,
     443,   647,   989,   649,   226,   230,   538,  1485,   539,   846,
     540,   758,   759,   181,   231,   182,   413,   235,   414,   497,
     409,   409,   594,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   304,   304,   304,
    1002,   432,   259,  1228,   245,   260,   501,   502,   261,   275,
     795,  1003,   250,   734,   737,   740,   743,   897,   900,  1004,
    1005,  1006,  1466,   304,   246,  1007,  1008,  1009,  1010,   236,
     304,   705,   237,   711,   258,   238,   818,   239,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   270,   501,   502,   271,   432,   413,  1606,   414,
    1609,   304,  1612,   794,  1152,   413,  1154,   414,  1156,  1539,
    1158,   817,   847,   848,   849,   850,   851,   852,   853,   854,
     855,   856,   857,   280,   859,   860,   861,   862,   863,   864,
     865,   705,  1121,   715,   869,   871,   872,   705,   501,   502,
     501,   502,   501,   502,   880,   881,   882,   796,   884,   501,
     502,   281,   251,   252,  1541,   892,  1543,   284,  1551,   501,
     502,   705,   253,   721,   285,  1553,   908,  1593,  1594,   262,
    1100,   286,   307,  1595,   304,  1554,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     501,   502,   501,   502,   432,  1597,  1598,   304,   306,   304,
     846,  1595,   275,  1486,   308,   275,  1658,   275,  1661,   501,
     502,   304,   304,  1190,   501,   502,  1190,   501,   502,  1190,
     309,  1262,   501,   502,   901,  1664,   940,   413,  1712,   414,
    1672,   944,   695,  1674,  1002,   304,   315,  1275,  1729,   316,
     317,   501,   502,  1064,  1066,  1003,   318,   501,   502,   331,
     377,  1071,  1073,  1004,  1005,  1006,   304,  1730,   378,  1007,
    1008,  1009,  1010,  1743,   379,   992,   501,   502,   501,   502,
     380,   349,   998,   585,   946,   540,   232,   381,  1013,   233,
     182,   234,  1781,   240,  1782,   413,   241,   414,   242,  1758,
     870,  1761,   413,  1764,   414,   382,   705,   705,   812,  1767,
     443,   304,   413,   942,   414,   443,  1002,  1252,   387,   834,
     304,   835,   304,   413,   304,   414,   304,  1003,  1255,  1190,
     413,   304,   414,  1122,   304,  1004,  1005,  1006,   705,   391,
     392,  1007,  1008,  1009,  1010,  1116,  1117,   393,   394,  1350,
    1508,   304,  1803,   586,  1805,  1509,  1807,   304,   396,   398,
    1450,  1451,   275,   423,   424,   425,   426,   427,   428,   429,
     430,   431,  1267,     7,     8,  1190,   432,  1382,  1190,  1002,
     705,  1190,   914,  1128,  1190,  1129,  1074,   304,   397,   705,
    1003,   985,   275,   304,   275,   275,   412,   433,  1004,  1005,
    1006,   705,   434,   986,  1007,  1008,  1009,  1010,   275,   552,
     438,   705,   553,  1027,   459,   554,  1080,   555,  1082,  1083,
    1190,  1659,  1190,   705,  1190,  1028,   304,   304,   304,   304,
     464,   469,  1088,  1107,   705,   475,  1029,   659,    24,    25,
     660,    27,    28,   661,    30,   662,    32,   705,    33,  1045,
    1073,   275,   470,    38,    39,   476,    41,    42,    43,   480,
     443,  1084,    46,   481,  1125,  1126,   482,  1127,   304,   304,
     705,   304,  1068,   304,   304,  1120,   488,   304,   304,  1134,
     491,  1135,   304,   705,  1662,  1165,   705,   705,  1209,  1214,
     443,   483,   443,   443,   494,   484,    67,    68,    69,   705,
     705,  1215,  1216,   495,   526,   705,   443,  1217,  1263,   705,
     705,  1219,  1220,  1269,   705,  1270,  1271,   485,   486,  1173,
    1174,  1175,   487,   506,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   705,   705,
    1272,  1273,   432,  1396,   705,   705,  1274,  1311,  1406,   443,
    1407,  1438,   705,  1439,  1475,  1514,   705,  1515,  1530,   705,
    1406,  1531,  1552,  1601,   517,   783,   304,   304,   304,   507,
     440,   112,   508,  1406,   686,  1590,  1614,   304,  1615,   705,
    1632,  1630,  1633,   695,  1406,  1635,  1640,  1237,  1252,  1255,
    1642,  1643,   528,   337,  1242,  1243,  1244,  1245,  1246,   518,
    1406,   705,  1646,  1654,  1253,  1256,   139,   140,   141,   142,
     143,   144,   705,   519,  1673,   148,   149,   150,   151,     7,
       8,   529,   523,   153,   154,   155,   530,  1514,   156,  1723,
     304,   705,   705,  1742,  1744,  1406,   705,  1753,  1790,   161,
    1795,  1406,  1796,  1817,  1827,   564,  1828,  1571,   531,   304,
     532,   535,   536,   537,   542,   304,   568,  1383,   572,   575,
     574,   304,   579,   304,   304,   182,   580,   581,   304,   304,
     583,   304,   593,   304,   598,   304,   599,   304,   304,   304,
     602,   432,   655,   659,    24,    25,   660,    27,    28,   661,
      30,   662,    32,   656,    33,   304,   181,   701,   658,    38,
      39,   702,    41,    42,    43,   718,  1290,   722,    46,   723,
     304,  1349,   724,   751,   304,   727,   304,   728,   750,   775,
     752,   777,   780,   164,   165,   778,   787,   788,  1363,   793,
     822,   797,   799,   800,   801,   172,   825,    89,   173,  1368,
     832,   833,    67,    68,    69,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   344,
     345,   841,   842,   432,   275,   875,  1072,   873,   874,   876,
     903,   877,   889,   893,   887,   878,   888,   894,  1572,  1383,
     895,   904,   931,   947,   950,   936,   939,   941,  1384,   943,
     955,   951,   304,  1002,   952,   954,   956,   957,   959,   960,
     961,   965,   275,   970,  1003,   304,   972,   974,   975,  1617,
     976,   829,  1004,  1005,  1006,  1097,  1417,   988,  1007,  1008,
    1009,  1010,   977,   978,   979,   980,  1411,   981,   995,  1022,
    1035,   996,  1036,  1385,  1049,  1038,  1039,  1040,  1050,  1051,
    1052,   304,   304,  1389,  1062,  1060,  1090,  1095,  1096,     7,
       8,  1098,  1099,  1102,  1452,  1108,  1455,  1115,  1458,   409,
     409,  1111,   443,  1112,  1119,  1113,  1002,  1124,  1132,   304,
    1414,   304,  1469,   304,  1138,  1472,  1473,  1003,  1139,  1143,
    1144,  1146,  1147,  1150,  1166,  1004,  1005,  1006,   304,  1151,
    1160,  1007,  1008,  1009,  1010,   304,  1161,  1162,  1665,   304,
     443,  1163,  1164,   304,  1494,  1176,  1177,  1178,  1179,  1180,
    1445,  1193,  1194,   659,    24,    25,   660,    27,    28,   661,
      30,   662,    32,   304,    33,  1195,  1196,  1197,  1200,    38,
      39,  1713,    41,    42,    43,  1199,  1201,  1202,    46,  1203,
    1205,  1206,  1224,  1229,   304,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,  1490,
    1230,  1232,  1247,   432,  1234,  1236,  1238,  1239,  1497,  1500,
    1501,  1739,    67,    68,    69,  1240,  1241,  1251,  1283,  1248,
     304,  1265,  1249,  1250,  1286,   304,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
    1259,  1142,  1264,  1276,   432,   304,  1282,  1281,  1291,  1292,
    1300,  1294,   304,     7,     8,   275,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   456,  1295,  1296,
     304,   432,   461,  1301,  1303,  1304,   465,  1302,  1306,  1307,
    1308,   830,  1309,   471,  1314,  1315,   304,  1344,  1324,   304,
    1326,  1325,  1340,  1332,  1345,  1333,  1346,  1347,  1354,  1605,
    1362,  1608,   409,  1611,  1369,   304,  1355,  1359,  1370,  1375,
     304,  1619,  1371,   184,  1622,  1379,  1386,   659,    24,    25,
     660,    27,    28,   661,    30,   662,    32,  1378,    33,  1391,
    1392,  1394,  1410,    38,    39,  1397,    41,    42,    43,  1398,
    1399,  1400,    46,  1418,  1419,  1420,  1423,  1425,  1427,  1426,
    1428,  1429,   304,   443,  1648,  1432,  1433,  1434,  1652,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   304,  1435,  1436,  1437,   432,    67,    68,    69,  1440,
    1453,  1456,     7,     8,  1459,  1463,  1467,  1470,  1474,  1477,
    1493,  1502,  1506,  1504,   329,   330,  1505,  1507,  1513,  1516,
    1525,  1527,  1528,  1534,  1546,  1529,  1535,  1692,  1537,  1538,
    1540,  1694,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,  1542,  1544,  1548,   304,
     432,   304,  1549,  1555,  1716,  1561,  1566,  1567,  1568,  1580,
    1573,  1584,  1585,  1586,   304,   990,   659,    24,    25,   660,
      27,    28,   661,    30,   662,    32,  1682,    33,  1587,  1588,
    1589,  1591,    38,    39,  1613,    41,    42,    43,  1620,  1631,
    1636,    46,   665,  1637,  1644,  1647,  1650,  1653,  1651,  1667,
    1655,   399,   400,   401,   402,   403,  1668,  1671,  1680,  1756,
    1757,  1691,  1696,  1698,  1701,  1702,  1705,  1706,   439,  1709,
     304,  1715,   445,  1737,  1710,    67,    68,    69,   275,  1731,
    1750,  1733,  1759,  1735,  1751,  1762,   452,   454,   457,   458,
    1765,   460,   454,   462,   463,  1768,   454,   466,   467,  1198,
    1770,  1779,  1776,   454,  1778,   304,  1799,  1802,  1804,  1784,
    1806,  1808,  1814,  1829,  1749,   747,   748,  1830,  1786,  1788,
    1797,   490,   275,  1831,   275,  1832,  1833,  1834,  1285,  1836,
     499,   500,  1683,  1582,     7,     8,  1583,   700,    94,   500,
     103,  1298,   730,  1599,   991,  1393,  1813,     0,  1816,     0,
       0,     0,     0,     0,   275,     0,     0,   784,   785,   786,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   557,   559,   454,     0,   443,     0,  1835,     0,
       0,     0,     0,   810,   569,   570,   571,     0,   573,     0,
       0,   576,   577,     0,     0,   578,     0,     0,   659,    24,
      25,   660,    27,    28,   661,    30,   662,    32,     0,    33,
       0,     0,   591,   592,    38,    39,     0,    41,    42,    43,
     443,   839,   443,    46,     0,     0,   600,   601,     0,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,     0,   443,     0,     0,     0,     0,    67,    68,    69,
     634,     0,     0,     0,     0,     0,   640,     0,   642,     0,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,   664,
       0,     0,   454,     0,     0,   668,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   681,   682,
       0,     0,   684,   685,     0,     0,     0,   935,     0,   937,
       0,     0,     0,  1002,     0,     0,  1014,     0,     0,     0,
     557,     0,     0,     0,  1003,     0,   709,     0,  1260,     0,
       0,   714,  1004,  1005,  1006,     0,   719,   720,  1007,  1008,
    1009,  1010,   725,   726,     0,     0,     0,   731,   733,   736,
     739,   742,   744,   745,   746,   454,   454,     0,     0,     0,
       0,     0,     0,     0,  1266,     0,   987,     0,     0,     0,
       0,     0,     0,   763,   764,   765,   399,   400,   766,     0,
       0,     0,   770,   771,   772,   773,   774,     0,     0,     0,
     779,     0,   781,   782,     0,     0,     0,   454,   454,   454,
       0,     0,   789,   790,   791,   600,   792,     0,     0,     7,
       8,  1034,   798,     0,     0,     0,  1002,     0,  1783,     0,
    1041,     0,  1042,   454,  1043,     0,  1044,  1003,     0,   813,
     815,  1047,   684,   685,  1048,  1004,  1005,  1006,     0,     0,
       0,  1007,  1008,  1009,  1010,     0,     0,     0,     0,     0,
       0,     0,   792,     0,     0,     0,     0,     0,     0,     0,
     838,   454,     0,     0,     0,     0,   843,     0,     0,     0,
       0,     0,     0,   659,    24,    25,   660,    27,    28,   661,
      30,   662,    32,     0,    33,     0,     0,  1079,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
     902,  1785,     0,     0,  1148,     0,  1103,  1104,  1105,  1106,
       0,     0,    67,    68,    69,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,   930,     0,     0,   454,     0,   454,
     938,     0,     0,     0,     0,     0,     0,     0,   945,     0,
    1002,   815,   948,     0,     0,     0,     0,     0,     0,     0,
       0,  1003,  1145,     0,     0,   962,     0,     0,     0,  1004,
    1005,  1006,     0,     0,   968,  1007,  1008,  1009,  1010,   207,
     208,  1054,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   454,     0,     0,     0,
     432,     0,     0,   993,   994,     0,     0,     0,     0,   997,
       0,     0,     0,     0,     0,     0,     0,  1002,     0,     0,
       0,     0,  1021,     0,     0,  1023,     0,     0,  1003,     0,
       0,     0,     0,     0,     0,     0,  1004,  1005,  1006,     0,
       0,   454,  1007,  1008,  1009,  1010,     0,     0,     0,     0,
     454,     0,   454,     0,   454,  1787,   454,     0,     0,     0,
       0,   454,     0,     0,   454,     0,   338,     0,     0,     0,
    1053,     0,  1055,  1056,     0,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,     0,  1075,   383,   384,   385,   386,
       7,     8,   388,  1076,  1077,  1078,     0,   454,   389,   390,
       0,     0,  1789,     0,   395,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1087,     0,     0,     0,     0,
       0,     0,     0,  1089,     0,     0,  1094,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   454,   454,   454,   454,
     468,     0,     0,  1109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   659,    24,    25,   660,    27,    28,
     661,    30,   662,    32,   492,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,  1358,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,   522,     0,
       0,     0,   454,     0,  1360,     0,     0,     0,     0,     0,
       0,     0,  1153,     0,  1155,     0,  1157,     0,  1159,     0,
    1002,     0,     0,    67,    68,    69,     0,     0,     0,     0,
       0,  1003,     0,     0,     0,   541,     0,     0,     0,  1004,
    1005,  1006,     0,     0,     0,  1007,  1008,  1009,  1010,     7,
       8,     0,   567,     0,     0,     0,     0,     0,     0,  1002,
       0,   589,   590,     0,     0,     0,  1204,     0,     0,  1207,
    1003,  1380,     0,  1210,   597,  1211,  1212,  1213,  1004,  1005,
    1006,     0,     0,  1218,  1007,  1008,  1009,  1010,     0,     0,
       0,     0,  1059,     0,     0,     0,     0,     0,     0,     0,
    1233,     0,  1235,     0,     0,     0,     0,     0,   631,     0,
       0,  1441,  1442,   659,    24,    25,   660,    27,    28,   661,
      30,   662,    32,     0,    33,  1820,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,  1268,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,   455,  1277,  1278,
       0,     0,   455,     0,     0,   657,   455,     0,     0,     0,
    1287,  1289,     0,   455,  1821,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1329,  1330,  1331,     0,     0,
       0,     0,     0,     0,     0,  1341,     0,  1343,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,  1348,     0,
       0,     0,   558,     0,   455,     0,   454,     0,     0,     0,
       0,  1167,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,  1381,     0,     0,     0,
     432,     0,  1372,  1373,  1374,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1564,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   659,    24,    25,   660,    27,
      28,   661,    30,   662,    32,     0,    33,     0,     0,  1390,
    1503,    38,    39,     0,    41,    42,    43,     0,     0,     0,
      46,     0,     0,  1403,     0,     0,     0,     0,  1409,  1600,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1415,  1416,     0,     0,  1533,     0,     0,  1421,  1422,
    1621,     0,     0,  1424,    67,    68,    69,  1002,     0,     0,
       0,  1431,   455,     0,     0,     0,     0,     0,  1003,     0,
       0,   454,   454,  1443,     0,  1444,  1004,  1005,  1006,     0,
       0,     0,  1007,  1008,  1009,  1010,     0,  1461,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   454,
     558,     0,     0,   454,     0,   915,  1476,     0,     0,     0,
       0,  1478,  1479,  1480,  1481,     0,     0,     0,     0,     0,
       0,     0,     0,  1669,  1489,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1499,   455,   455,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,  1510,  1511,     0,     0,   432,     0,     0,     0,  1517,
       0,     0,  1822,     0,     0,     0,   969,     0,     0,  1714,
       0,  1717,     0,     0,     0,     0,     0,   455,   455,   455,
       0,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,  1536,     0,     0,     0,   432,
       0,     0,     0,   455,     0,     0,     0,     0,     0,     0,
     816,     0,     0,  1550,     0,   557,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
    1562,     0,  1563,     0,   432,   454,     0,     0,     0,     0,
    1769,   455,  1570,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1575,     0,     0,     0,
       0,  1579,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1061,     0,     0,     0,     0,     0,  1069,   454,
       0,     0,     0,     0,     0,     0,  1604,     0,  1607,     0,
    1610,     0,     0,     7,     8,     0,     0,     0,     0,     0,
     454,     0,     0,     0,  1623,  1624,  1625,  1626,  1627,     0,
       0,     0,     0,     0,  1081,     0,     0,     0,     0,     0,
       0,     0,     0,  1638,  1639,     0,     0,     0,  1641,  1565,
       0,     0,     0,     0,     0,     0,     0,   455,  1645,   455,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1656,
       0,   816,   949,     0,     0,     0,     0,   659,    24,    25,
     660,    27,    28,   661,    30,   662,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,  1681,
       0,     0,    46,     0,  1409,     0,     0,     0,     0,  1130,
    1131,  1689,  1133,     0,  1136,  1137,   455,     0,  1140,  1141,
       0,     0,     0,     0,     0,  1700,     0,     0,  1704,     0,
       0,  1708,     0,     0,     0,  1711,    67,    68,    69,   454,
       0,   454,  1718,  1719,  1720,  1721,     0,     0,     0,     0,
       0,     0,  1725,     0,     0,  1727,     0,     0,     0,     0,
       0,   455,     0,     0,     0,     0,     0,     0,     0,     0,
     455,     0,   455,     0,   455,     0,   455,     0,     0,     0,
       0,   455,     0,     0,   455,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1755,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1740,     0,  1221,  1222,  1223,
     454,     0,  1771,  1772,  1773,  1774,     0,     0,  1231,     0,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,   455,   432,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1800,  1801,
       0,     0,     0,     0,     0,     0,     0,     0,  1809,  1810,
    1811,  1812,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1280,     0,     0,     0,     0,   455,   455,   455,   455,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1299,     0,     0,     0,     0,     0,  1305,     0,     0,     0,
       0,     0,  1310,     0,  1312,  1313,     0,     0,     0,  1316,
    1317,     0,  1318,     0,  1319,     0,  1320,     0,  1321,  1322,
    1323,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   455,     0,     0,     0,  1342,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1353,     0,     0,     0,  1357,     0,     0,     0,     0,
       0,     0,   110,   328,   112,     0,     0,     0,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,  1679,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,   153,   154,   155,     0,
       0,   156,     0,   157,   158,   159,     0,     0,     0,     0,
       0,   160,   161,  1401,     0,     0,   110,   111,   112,     0,
       0,     0,   113,   114,   115,     0,  1413,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
    1738,     0,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
     153,   154,   155,     0,     0,   156,     0,   157,   158,   159,
       0,     0,  1634,   562,     0,   160,   161,     0,     0,     0,
       0,     0,  1280,     0,     0,   163,   164,   165,   166,     0,
       0,     0,     0,   167,   168,   169,   170,   171,   172,  1482,
      89,   173,     0,     0,     0,     0,  1491,     0,     0,     0,
    1492,     0,     0,     0,  1496,   174,   175,     0,     0,     0,
     176,     0,     0,     0,     0,   296,     0,     0,     0,     0,
     180,     0,  1288,     0,  1512,     0,   455,     0,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,   162,     0,  1280,   432,     0,     0,   163,
     164,   165,   166,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,     0,    89,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
     175,  1547,     0,     0,   176,     0,     0,     0,     0,   177,
       0,   178,     0,   179,   180,     0,   181,     0,   182,     0,
       0,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1280,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   704,   430,   431,     0,  1280,     0,     0,
     432,   455,   455,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1616,     0,     0,     0,
       0,     0,     0,  1722,   110,   287,     0,     0,     0,   455,
     113,   114,   115,   455,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   289,     0,
       0,     0,     0,  1649,     0,     0,     0,   145,   146,   147,
       0,     0,     0,     0,   152,     0,     0,     0,     0,     0,
       0,     0,  1666,     0,     0,   157,   158,   159,     0,     0,
       0,     0,     0,   160,     0,     0,     0,   290,     0,     0,
     291,     0,     0,   292,     0,   293,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   294,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,   558,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1280,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,     0,     0,     0,     0,
       0,     0,   455,     0,     0,     0,     0,   163,     0,     0,
     166,     0,     0,     0,     0,   167,   168,   169,   170,   171,
     562,     0,    89,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   509,  1468,   455,
       0,   432,   176,     0,     0,     0,     0,   511,     0,     0,
       0,     0,   180,     0,   254,   560,     0,     0,     0,     0,
     455,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,   287,     0,     0,     0,  1280,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   289,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   146,   147,     0,     0,     0,
       0,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,     0,     0,     0,     0,     0,
     160,     0,     0,     0,   290,     0,     0,   291,     0,     0,
     292,     0,   293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   294,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,   455,
      56,   455,     0,    59,     0,     0,     0,     0,     0,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     563,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   562,     0,     0,
       0,     0,     0,     0,   163,     0,     0,   166,     0,     0,
       0,     0,   167,   168,   169,   170,   171,   826,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     455,     0,     0,     0,   174,   453,     0,     0,     0,   176,
       0,     0,     0,     0,   296,     0,     0,     0,     0,   180,
       0,     0,   560,   110,   287,   112,     0,     0,     0,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   289,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,   153,   154,   155,
       0,     0,   156,     0,   157,   158,   159,     0,     0,     0,
       0,     0,   160,   161,     0,     0,   290,     0,     0,   291,
       0,     0,   292,     0,   293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   704,   430,   431,
       0,     0,     0,     0,   432,     0,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     916,     0,     0,     0,   432,     0,   163,   164,   165,   166,
       0,     0,     0,     0,   167,   168,   169,   170,   171,   172,
       0,    89,   173,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   174,   295,     0,     0,
       0,   176,     0,     0,     0,     0,   296,     0,   110,   287,
     112,   180,     0,   297,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   289,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,   153,   154,   155,     0,     0,   156,     0,   157,
     158,   159,     0,     0,     0,     0,     0,   160,   161,     0,
       0,   290,     0,     0,   291,     0,     0,   292,     0,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   294,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,   164,   165,   166,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,     0,    89,   173,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   295,     0,     0,     0,   176,     0,     0,     0,
       0,   296,     0,   110,   328,   112,   180,     0,  1495,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,  1046,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,   153,   154,   155,
       0,     0,   156,     0,   157,   158,   159,     0,   110,   328,
     112,     0,   160,   161,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     0,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,   153,   154,   155,     0,     0,   156,     0,   157,
     158,   159,     0,     0,     0,     0,     0,   160,   161,     0,
       0,     0,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   163,   164,   165,   166,
     432,     0,   650,     0,   167,   168,   169,   170,   171,   172,
       0,    89,   173,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   174,   175,     0,     0,
       0,   176,     0,     0,     0,     0,   296,     0,     0,     0,
       0,   180,     0,  1488,     0,     0,     0,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   163,   164,   165,   166,   432,  1226,     0,     0,   167,
     168,   169,   170,   171,   172,     0,    89,   173,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   175,     0,     0,     0,   176,     0,     0,     0,
       0,   296,     0,   110,   287,   288,   180,     0,  1498,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   289,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   146,   147,     0,
       0,     0,     0,   152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   158,   159,     0,     0,     0,
       0,     0,   160,     0,     0,     0,   290,     0,     0,   291,
       0,     0,   292,     0,   293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,   163,     0,     0,   166,
       0,     0,     0,     0,   167,   168,   169,   170,   171,     0,
       0,    89,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   174,   295,     0,     0,
     432,   176,   811,     0,     0,     0,   296,   756,   110,   287,
    1351,   180,     0,   297,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   289,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   146,   147,     0,     0,     0,     0,   152,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     158,   159,     0,     0,     0,     0,     0,   160,     0,     0,
       0,   290,     0,     0,   291,     0,     0,   292,     0,   293,
     319,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   294,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,     0,     0,     0,     0,     0,   139,   140,   141,   142,
     143,   144,     0,     0,     0,   148,   149,   150,   151,     0,
       0,     0,     0,   153,   154,   155,     0,     0,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
       0,   163,     0,     0,   166,     0,     0,     0,     0,   167,
     168,   169,   170,   171,     0,     0,    89,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   174,   295,     0,     0,   432,   176,     0,     0,     0,
       0,   296,   693,   110,   287,     0,   180,     0,  1352,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   289,     0,     0,
       0,     0,     0,   164,   165,     0,   145,   146,   147,     0,
       0,     0,     0,   152,     0,   172,     0,    89,   173,     0,
       0,     0,     0,     0,   157,   158,   159,     0,     0,     0,
       0,     0,   160,     0,     0,     0,   290,     0,     0,   291,
       0,     0,   292,     0,   293,   440,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,     0,     0,     0,     0,
       0,   139,   140,   141,   142,   143,   144,     0,     0,     0,
     148,   149,   150,   151,     0,     0,     0,     0,   153,   154,
     155,     0,     0,   156,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   161,     0,   163,     0,     0,   166,
       0,     0,     0,     0,   167,   168,   169,   170,   171,     0,
       0,    89,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   174,   295,     0,     0,
     432,   176,     0,     0,     0,     0,   296,   756,   110,   287,
       0,   180,     0,   297,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   289,     0,     0,     0,     0,     0,   164,   165,
       0,   145,   146,   147,     0,     0,     0,     0,   152,     0,
     172,     0,    89,   173,     0,     0,     0,     0,     0,   157,
     158,   159,     0,     0,     0,     0,     0,   160,     0,     0,
       0,   290,     0,     0,   291,     0,     0,   292,     0,   293,
     322,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   294,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,     0,     0,     0,     0,     0,   139,   140,   141,   142,
     143,   144,     0,     0,     0,   148,   149,   150,   151,     0,
       0,     0,     0,   153,   154,   155,     0,     0,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
       0,   163,     0,     0,   166,     0,     0,     0,     0,   167,
     168,   169,   170,   171,     0,     0,    89,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   174,   453,     0,     0,   432,   176,     0,     0,     0,
       0,   296,   757,   110,   287,     0,   180,     0,   556,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   289,     0,     0,
       0,     0,     0,   164,   165,     0,   145,   146,   147,     0,
       0,     0,     0,   152,     0,   172,     0,     0,   173,     0,
       0,     0,     0,     0,   157,   158,   159,     0,     0,     0,
       0,     0,   160,     0,     0,     0,   290,     0,     0,   291,
       0,     0,   292,   112,   293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,     0,     0,   139,   140,
     141,   142,   143,   144,     0,     0,     0,   148,   149,   150,
     151,     0,     0,     0,     0,   153,   154,   155,     0,     0,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,   163,     0,     0,   166,
       0,     0,     0,     0,   167,   168,   169,   170,   171,     0,
       0,    89,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   174,   453,     0,     0,
     432,   176,     0,     0,     0,     0,   296,   823,   110,   287,
       0,   180,     0,   814,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   289,     0,     0,   164,   165,     0,     0,     0,
       0,   145,   146,   147,     0,     0,     0,   172,   152,     0,
     173,     7,     8,     0,     0,     0,     0,     0,     0,   157,
     158,   159,     0,     0,     0,     0,     0,   160,     0,     0,
       0,   290,     0,     0,   291,     0,     0,   292,     0,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   294,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,     0,     0,     0,     0,   659,    24,    25,   660,    27,
      28,   661,    30,   662,    32,     0,    33,     0,     0,     0,
       0,    38,    39,     0,    41,    42,    43,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,     0,     0,   166,     0,     0,     0,     0,   167,
     168,   169,   170,   171,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,    67,    68,    69,     0,     0,     0,
       0,   174,   295,     0,     0,     0,   176,     0,     0,     0,
       0,   296,     0,   110,   287,     0,   180,     0,  1356,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   289,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   146,   147,     0,
       0,     0,     0,   152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   158,   159,     0,     0,     0,
       0,     0,   160,     0,     0,     0,   290,     0,     0,   291,
       0,     0,   292,     0,   293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,  1448,     0,  1449,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,     0,   166,
       0,     0,     0,     0,   167,   168,   169,   170,   171,     0,
       0,    89,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   509,  1468,     0,     0,
     432,   176,     0,     0,     0,     0,   511,   858,   110,   328,
       0,   180,     0,   254,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   146,   147,     0,     0,     0,     0,   152,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   328,   157,
     158,   159,     0,   113,   114,   115,     0,   160,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   146,   147,     0,     0,     0,     0,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   158,
     159,     0,     0,     0,     0,     0,   160,     0,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,   163,     0,  1483,   166,  1484,     0,     0,     0,   167,
     168,   169,   170,   171,     0,     0,    89,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   174,   175,     0,     0,   432,   176,     0,     0,     0,
       0,   296,  1602,     0,  1603,     0,   180,     0,   489,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,     0,   166,     0,     0,     0,     0,   167,   168,
     169,   170,   171,     0,     0,    89,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     509,   510,     0,     0,   432,   176,     0,     0,     0,     0,
     511,   866,   110,   328,   112,   180,     0,   254,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,   153,   154,   155,     0,
       0,   156,     0,   157,   158,   159,     0,     0,     0,     0,
       0,   160,   161,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,     0,     0,
     913,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,     0,     0,   964,     0,
       0,     0,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,     0,   163,   164,   165,   166,  1017,
       0,     0,     0,   167,   168,   169,   170,   171,   172,     0,
      89,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   174,   175,     0,     0,     0,
     176,   110,   287,     0,     0,   296,     0,   113,   114,   115,
     180,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   289,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   146,   147,     0,     0,     0,
       0,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,     0,     0,     0,     0,     0,
     160,     0,     0,     0,   290,     0,     0,   291,     0,     0,
     292,     0,   293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   294,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,     0,     0,     0,     0,
       0,  1037,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,     0,     0,   166,     0,     0,
       0,     0,   167,   168,   169,   170,   171,     0,     0,    89,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   174,   453,     0,     0,   432,   176,
     110,   328,     0,     0,   296,   867,   113,   114,   115,   180,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   146,   147,     0,     0,     0,     0,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   158,   159,     0,     0,     0,     0,     0,   160,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,  1067,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,  1171,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    -4,     1,     0,     0,
      -4,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,   163,     0,     0,   166,     0,     0,     0,
       0,   167,   168,   169,   170,   171,     0,     0,    89,     0,
       0,     0,     0,     0,    -4,    -4,     0,     0,     0,     0,
       0,     0,     0,   174,   175,     0,     0,     0,   176,     0,
      -4,    -4,    -4,   296,     0,     0,    -4,    -4,   180,    -4,
       0,     0,     0,    -4,    -4,     0,    -4,    -4,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,
       6,     0,     0,     0,     0,    -4,     0,     0,     7,     8,
      -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     9,    10,    -4,    -4,    -4,    -4,
       0,     0,     0,     0,     0,     0,    -4,    -4,     0,     0,
      11,    12,    13,     0,     0,     0,    14,    15,     0,    16,
       0,     0,     0,    17,    18,     0,    19,    20,     0,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,    54,    55,    56,    57,
      58,    59,    60,    61,     0,     0,     0,    62,    63,    64,
       0,     0,     0,     0,     0,    65,     0,     0,     0,     0,
      66,    67,    68,    69,     0,     0,    70,     0,    71,     0,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,     0,     0,     0,    84,    85,    86,    87,
       0,     0,     0,     0,     0,     0,    88,    89,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,  1446,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,     0,  1465,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,     0,     0,     0,     0,
       0,  1520,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,     0,     0,     0,     0,     0,  1521,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,  1522,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,  1523,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,     0,  1524,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,     0,     0,     0,     0,
       0,  1556,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,     0,     0,     0,     0,     0,  1618,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,  1628,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,  1629,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,     0,  1657,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,     0,     0,     0,     0,
       0,  1660,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,     0,     0,     0,     0,     0,  1663,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,  1690,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,  1697,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,     0,  1732,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,     0,     0,     0,     0,
       0,  1734,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,     0,     0,     0,     0,     0,  1736,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,  1754,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,  1780,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,     0,  1818,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,     0,     0,     0,     0,
       0,  1819,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,     0,     0,     0,     0,     0,  1823,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,  1824,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,  1825,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,     0,  1826,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,     0,     0,     0,     0,
     587,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,     0,   749,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,     0,  1532,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
     868,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,   879,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,   999,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1000,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1001,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1032,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,  1123,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,  1169,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1170,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1225,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1364,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,  1365,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,  1366,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1367,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1404,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1405,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,  1412,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,  1557,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1558,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1559,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1560,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,  1576,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,  1577,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1581,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1675,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1676,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,  1677,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,  1678,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1685,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1688,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1728,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,  1745,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,  1746,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1747,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1748,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1791,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,  1792,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,  1793,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1794,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,   413,
       0,   414,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,   651,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,   828,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
     837,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,   845,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,   929,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,  1025,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,  1026,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,  1030,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,  1031,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,  1033,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,  1070,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,  1118,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
    1361,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,  1395,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,  1545,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,   703,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,   707,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,   708,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
     710,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,   712,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,   713,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,   716,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,   717,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,   811,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,   819,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,   820,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,   821,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,   827,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
     836,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,   844,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,   928,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,   953,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,   958,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,   963,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,   966,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,   967,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,   973,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,   982,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
     983,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,   984,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,  1016,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,  1018,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,  1019,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,  1020,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,  1024,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,  1258,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,  1447,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,  1464,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
    1487,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,  1684,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,  1752
};

static const yytype_int16 yycheck[] =
{
       3,   247,   262,   374,     6,   376,   109,  1354,     4,     4,
       3,   503,   504,     5,   274,     6,   387,     7,     4,     6,
       4,     4,     4,     4,   404,     5,     4,     6,     4,     4,
      79,     5,     5,    82,     4,     6,   416,     4,     6,     5,
       4,     6,     5,     5,     5,    79,     5,     5,    82,    49,
      50,     6,    52,     7,    57,     4,     6,     4,     6,     6,
     186,   187,    65,  1015,   198,   325,   200,   327,     6,   186,
     187,   205,     6,   186,   187,     6,   202,    80,   204,     6,
    1427,   186,   187,   197,     6,   202,    99,   204,   202,   202,
      13,   204,   186,   187,   186,   187,     0,   110,     3,   204,
     196,     6,   196,   186,   187,   118,   119,   120,  1011,   203,
     202,   124,   125,   126,   127,   186,   187,   227,   228,   229,
     203,   196,   232,   233,   234,   103,   104,   105,   106,    76,
       7,    82,   203,   197,   112,   199,     4,   115,     7,   203,
       4,   140,    80,    81,   130,   131,   132,   133,   186,   187,
       6,   143,    57,   193,   194,   154,   155,   128,   268,   269,
     128,   193,   194,   143,     6,   203,  1513,     7,   200,   143,
     143,   153,   282,   283,   150,    80,   197,   180,   128,     7,
     128,   202,  1529,   173,   174,   175,   176,   171,   181,   192,
     193,   204,   183,   197,   196,   171,   183,   200,   202,   196,
     196,   203,   198,   198,   200,   208,   203,   210,     6,   205,
     205,   203,   215,   192,   193,   595,   219,     6,   204,   222,
     203,   196,   203,   226,   227,   228,   229,   203,   203,   232,
     233,   234,   196,   203,   494,   495,   203,   203,   203,   203,
     203,   203,   203,   246,   203,   203,   200,   196,   203,     6,
     250,   251,   186,   187,   514,   186,   187,   196,   258,   186,
     187,     7,   262,     6,     8,   268,   269,   270,   198,   207,
     650,   651,   140,   141,   198,   180,   140,   141,   196,   282,
     283,   193,   194,   196,   186,   187,   196,   192,   193,  1192,
     203,   203,   295,   203,   297,   200,   173,   174,   175,   176,
     202,   404,   196,   208,   173,   174,   175,   176,   193,   194,
     186,   187,   193,   194,   574,   197,   193,   194,   203,    82,
     202,    84,   203,   200,   193,   194,   202,   587,   331,   196,
     333,   334,     4,   173,   174,   175,   176,   338,     6,     7,
    1687,   186,   187,   346,     8,   173,   174,   175,   176,   196,
     196,   198,   331,   193,   194,     6,     7,   202,   205,   186,
     187,   188,   189,   190,    76,   193,   194,    79,   195,    86,
      82,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     196,   384,   385,   386,   387,   388,   196,   203,   198,   392,
     393,   394,   395,   396,   196,   398,   375,     6,   377,   378,
     379,   339,   381,   382,    76,   384,   385,   386,    80,   388,
     186,   187,   415,   392,   393,   394,   395,   188,   189,   190,
      92,   196,    82,   196,   195,   198,   331,   173,   174,   175,
     176,  1778,   205,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   193,   194,   197,
     453,   195,   390,   202,   202,   204,   836,   837,   199,   397,
     204,   202,   186,   187,   199,    82,   196,   202,   198,   374,
     375,   376,   377,   378,   379,   205,   381,   382,   202,   384,
     385,   386,   387,   388,     6,   488,   489,   392,   393,   394,
     395,   396,   752,   398,   203,    82,   196,     8,   198,   602,
     200,   501,   502,   203,    82,   205,   197,    84,   199,   509,
     503,   504,   203,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   530,   531,   532,
      99,   195,    76,   197,   196,    79,   186,   187,    82,   542,
     541,   110,   203,   481,   482,   483,   484,   650,   651,   118,
     119,   120,   202,   556,    79,   124,   125,   126,   127,    76,
     563,   202,    79,   204,   203,    82,   567,    84,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    82,   186,   187,    79,   195,   197,  1540,   199,
    1542,   594,  1544,   203,   974,   197,   976,   199,   978,   202,
     980,   203,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,    79,   615,   616,   617,   618,   619,   620,
     621,   202,   197,   204,   625,   626,   627,   202,   186,   187,
     186,   187,   186,   187,   635,   636,   637,   542,   639,   186,
     187,    82,   186,   187,   202,   646,   202,     4,   202,   186,
     187,   202,   196,   204,     4,   202,   657,   103,   104,   203,
     906,     4,   196,   109,   667,   202,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     186,   187,   186,   187,   195,   103,   104,   690,     4,   692,
     793,   109,   695,   204,   196,   698,   202,   700,   202,   186,
     187,   704,   705,  1606,   186,   187,  1609,   186,   187,  1612,
     196,  1091,   186,   187,   652,   202,   695,   197,  1670,   199,
     202,   700,   202,   202,    99,   728,   196,  1107,   202,     6,
       6,   186,   187,   836,   837,   110,   198,   186,   187,   198,
     196,   844,   845,   118,   119,   120,   749,   202,   196,   124,
     125,   126,   127,   202,   196,   755,   186,   187,   186,   187,
     196,   196,   762,   198,   702,   200,    79,   196,   768,    82,
     205,    84,   202,    79,   202,   197,    82,   199,    84,  1731,
     202,  1733,   197,  1735,   199,   196,   202,   202,   204,  1741,
     695,   794,   197,   698,   199,   700,    99,   202,   196,   202,
     803,   204,   805,   197,   807,   199,   809,   110,   202,  1712,
     197,   814,   199,   197,   817,   118,   119,   120,   202,     7,
     196,   124,   125,   126,   127,   928,   929,   196,   196,   204,
     197,   834,  1784,     6,  1786,   202,  1788,   840,   196,   198,
    1332,  1333,   845,   182,   183,   184,   185,   186,   187,   188,
     189,   190,  1098,    12,    13,  1758,   195,  1237,  1761,    99,
     202,  1764,   204,    82,  1767,    84,   845,   870,   196,   202,
     110,   204,   875,   876,   877,   878,   203,   203,   118,   119,
     120,   202,     6,   204,   124,   125,   126,   127,   891,    76,
       6,   202,    79,   204,   196,    82,   875,    84,   877,   878,
    1803,   204,  1805,   202,  1807,   204,   909,   910,   911,   912,
     196,   196,   891,   914,   202,   196,   204,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,   202,    87,   204,
    1033,   934,   203,    92,    93,   196,    95,    96,    97,   196,
     845,   879,   101,   196,   945,   946,   196,   947,   951,   952,
     202,   954,   204,   956,   957,   934,   203,   960,   961,    82,
       4,    84,   965,   202,   204,   204,   202,   202,   204,   204,
     875,   196,   877,   878,   203,   196,   135,   136,   137,   202,
     202,   204,   204,   203,   198,   202,   891,   204,  1091,   202,
     202,   204,   204,   202,   202,   204,   204,   196,   196,   999,
    1000,  1001,   196,   203,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   202,   202,
     204,   204,   195,  1269,   202,   202,   204,   204,   202,   934,
     204,     4,   202,     6,   204,   202,   202,   204,   204,   202,
     202,   204,   204,  1535,   196,   204,  1049,  1050,  1051,   203,
       4,     5,   203,   202,     6,   204,   202,  1060,   204,   202,
     202,   204,   204,   202,   202,   204,   204,  1068,   202,   202,
     204,   204,     6,   205,  1075,  1076,  1077,  1078,  1079,   196,
     202,   202,   204,   204,  1085,  1086,    40,    41,    42,    43,
      44,    45,   202,   196,   204,    49,    50,    51,    52,    12,
      13,     6,   196,    57,    58,    59,   203,   202,    62,   204,
    1113,   202,   202,   204,   204,   202,   202,   204,   204,    73,
     202,   202,   204,   204,   202,     6,   204,  1498,   203,  1132,
     203,   198,   198,   198,   198,  1138,     6,  1240,   200,   143,
     203,  1144,     6,  1146,  1147,   205,     6,     6,  1151,  1152,
       6,  1154,   203,  1156,     6,  1158,   198,  1160,  1161,  1162,
       4,   195,   200,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     7,    87,  1178,   203,   202,   204,    92,
      93,   202,    95,    96,    97,     7,  1124,     6,   101,     6,
    1193,  1191,     6,     6,  1197,     7,  1199,     7,   197,     7,
     203,     6,     6,   157,   158,     7,     6,     6,  1209,     4,
     140,    54,    54,    54,    54,   169,   203,   171,   172,  1220,
     199,   197,   135,   136,   137,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   193,
     194,     6,     6,   195,  1247,   202,   200,   197,   197,   202,
       6,   202,   197,   197,     6,   202,   202,   197,  1504,  1362,
     199,     4,     4,     7,   143,     6,     6,     6,  1247,     6,
     143,     7,  1275,    99,     7,     7,     7,     7,   143,     7,
       7,   203,  1285,     4,   110,  1288,     6,   197,   202,  1549,
     197,   204,   118,   119,   120,     6,  1296,   200,   124,   125,
     126,   127,   202,   197,   202,   197,  1285,   202,   204,     6,
     199,   204,   203,  1251,     7,   203,   203,   203,     7,     7,
     200,  1324,  1325,  1261,     6,   203,     6,     6,     6,    12,
      13,     7,   198,     6,  1334,     6,  1336,     6,  1338,  1332,
    1333,   196,  1247,   196,   183,   203,    99,     7,     7,  1352,
    1288,  1354,  1352,  1356,     7,  1355,  1356,   110,    84,     7,
       7,     7,     7,     6,     4,   118,   119,   120,  1371,     7,
       7,   124,   125,   126,   127,  1378,     7,     7,   204,  1382,
    1285,     7,     7,  1386,  1385,     4,     6,   203,     6,   196,
    1328,     7,     6,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,  1406,    87,     7,     7,     7,     6,    92,
      93,  1671,    95,    96,    97,   203,     6,     6,   101,    82,
       6,     6,     4,     4,  1427,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,  1377,
       4,   204,   202,   195,     6,     6,     6,     6,  1386,  1387,
    1388,   204,   135,   136,   137,     4,     6,   202,     6,   197,
    1463,     7,   197,   197,     6,  1468,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     197,     6,   200,   196,   195,  1488,   200,   203,     6,     6,
       6,   203,  1495,    12,    13,  1498,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   210,   203,    92,
    1513,   195,   215,   203,     6,     6,   219,   203,   203,     6,
       6,   204,     5,   226,     4,     6,  1529,     6,   203,  1532,
       7,   203,   198,   203,     6,   203,     6,     6,   203,  1539,
       4,  1541,  1535,  1543,     6,  1548,   203,   203,     6,     6,
    1553,  1551,   139,     6,  1554,     6,     4,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,   202,    87,     6,
       4,     6,     4,    92,    93,     6,    95,    96,    97,     6,
       6,     6,   101,     6,     6,     6,     6,     5,   203,     6,
       6,   143,  1595,  1498,  1594,     6,     6,     6,  1598,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,  1614,     6,     6,     6,   195,   135,   136,   137,     6,
       6,     6,    12,    13,     6,   202,     6,     6,     6,     6,
     197,     6,   200,     7,    87,    88,     6,     6,   203,     6,
       5,    80,     6,     6,     6,   203,   203,  1647,   204,   204,
     203,  1651,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   203,   203,     7,  1672,
     195,  1674,   203,     6,  1674,   138,     6,   204,     6,     6,
     141,     6,     6,     6,  1687,   204,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,  1634,    87,     6,     6,
       6,   203,    92,    93,     6,    95,    96,    97,     6,     6,
       6,   101,   415,   203,   203,   203,     6,     6,   203,     6,
     204,   174,   175,   176,   177,   178,    99,   203,     6,  1729,
    1730,     6,     6,     6,     6,     6,     6,     6,   191,     6,
    1743,     6,   195,     6,   204,   135,   136,   137,  1751,   203,
       6,   203,     6,   203,   203,     6,   209,   210,   211,   212,
       6,   214,   215,   216,   217,     6,   219,   220,   221,     6,
       6,     6,  1751,   226,   203,  1778,     6,     6,     6,   203,
       6,     6,     6,     6,  1722,   488,   489,     6,   203,   203,
     203,   244,  1795,     6,  1797,     6,     6,     6,  1121,     6,
     253,   254,  1637,  1518,    12,    13,  1519,   449,     3,   262,
       3,  1131,   479,  1531,   204,  1265,  1795,    -1,  1797,    -1,
      -1,    -1,    -1,    -1,  1827,    -1,    -1,   530,   531,   532,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   295,   296,   297,    -1,  1751,    -1,  1827,    -1,
      -1,    -1,    -1,   556,   307,   308,   309,    -1,   311,    -1,
      -1,   314,   315,    -1,    -1,   318,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      -1,    -1,   335,   336,    92,    93,    -1,    95,    96,    97,
    1795,   594,  1797,   101,    -1,    -1,   349,   350,    -1,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,    -1,  1827,    -1,    -1,    -1,    -1,   135,   136,   137,
     383,    -1,    -1,    -1,    -1,    -1,   389,    -1,   391,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,   412,
      -1,    -1,   415,    -1,    -1,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
      -1,    -1,   435,   436,    -1,    -1,    -1,   690,    -1,   692,
      -1,    -1,    -1,    99,    -1,    -1,   204,    -1,    -1,    -1,
     453,    -1,    -1,    -1,   110,    -1,   459,    -1,     6,    -1,
      -1,   464,   118,   119,   120,    -1,   469,   470,   124,   125,
     126,   127,   475,   476,    -1,    -1,    -1,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,   749,    -1,    -1,    -1,
      -1,    -1,    -1,   506,   507,   508,   509,   510,   511,    -1,
      -1,    -1,   515,   516,   517,   518,   519,    -1,    -1,    -1,
     523,    -1,   525,   526,    -1,    -1,    -1,   530,   531,   532,
      -1,    -1,   535,   536,   537,   538,   539,    -1,    -1,    12,
      13,   794,   545,    -1,    -1,    -1,    99,    -1,   204,    -1,
     803,    -1,   805,   556,   807,    -1,   809,   110,    -1,   562,
     563,   814,   565,   566,   817,   118,   119,   120,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   585,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     593,   594,    -1,    -1,    -1,    -1,   599,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    -1,    -1,   870,    -1,    92,
      93,    -1,    95,    96,    97,    -1,    -1,    -1,   101,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
     653,   204,    -1,    -1,    99,    -1,   909,   910,   911,   912,
      -1,    -1,   135,   136,   137,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,   687,    -1,    -1,   690,    -1,   692,
     693,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   701,    -1,
      99,   704,   705,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   965,    -1,    -1,   718,    -1,    -1,    -1,   118,
     119,   120,    -1,    -1,   727,   124,   125,   126,   127,    21,
      22,   204,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   749,    -1,    -1,    -1,
     195,    -1,    -1,   756,   757,    -1,    -1,    -1,    -1,   762,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,   775,    -1,    -1,   778,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,    -1,
      -1,   794,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     803,    -1,   805,    -1,   807,   204,   809,    -1,    -1,    -1,
      -1,   814,    -1,    -1,   817,    -1,   108,    -1,    -1,    -1,
     823,    -1,   825,   826,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,   858,   148,   149,   150,   151,
      12,    13,   154,   866,   867,   868,    -1,   870,   160,   161,
      -1,    -1,   204,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   888,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   896,    -1,    -1,   899,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   909,   910,   911,   912,
     222,    -1,    -1,   916,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,   246,    87,    -1,    -1,    -1,    -1,
      92,    93,    -1,    95,    96,    97,  1199,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,
      -1,    -1,   965,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   975,    -1,   977,    -1,   979,    -1,   981,    -1,
      99,    -1,    -1,   135,   136,   137,    -1,    -1,    -1,    -1,
      -1,   110,    -1,    -1,    -1,   287,    -1,    -1,    -1,   118,
     119,   120,    -1,    -1,    -1,   124,   125,   126,   127,    12,
      13,    -1,   304,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   333,   334,    -1,    -1,    -1,  1029,    -1,    -1,  1032,
     110,     6,    -1,  1036,   346,  1038,  1039,  1040,   118,   119,
     120,    -1,    -1,  1046,   124,   125,   126,   127,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1063,    -1,  1065,    -1,    -1,    -1,    -1,    -1,   380,    -1,
      -1,  1324,  1325,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,   204,    -1,    -1,    -1,    92,
      93,    -1,    95,    96,    97,    -1,  1099,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,  1111,  1112,
      -1,    -1,   215,    -1,    -1,   407,   219,    -1,    -1,    -1,
    1123,  1124,    -1,   226,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1168,  1169,  1170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1178,    -1,  1180,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,  1191,    -1,
      -1,    -1,   295,    -1,   297,    -1,  1199,    -1,    -1,    -1,
      -1,   204,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     6,    -1,    -1,    -1,
     195,    -1,  1225,  1226,  1227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1488,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    87,    -1,    -1,  1262,
       6,    92,    93,    -1,    95,    96,    97,    -1,    -1,    -1,
     101,    -1,    -1,  1276,    -1,    -1,    -1,    -1,  1281,  1532,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1294,  1295,    -1,    -1,     6,    -1,    -1,  1301,  1302,
    1553,    -1,    -1,  1306,   135,   136,   137,    99,    -1,    -1,
      -1,  1314,   415,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,  1324,  1325,  1326,    -1,  1328,   118,   119,   120,    -1,
      -1,    -1,   124,   125,   126,   127,    -1,  1340,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1352,
     453,    -1,    -1,  1356,    -1,   667,  1359,    -1,    -1,    -1,
      -1,  1364,  1365,  1366,  1367,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,  1377,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1387,   488,   489,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,  1404,  1405,    -1,    -1,   195,    -1,    -1,    -1,  1412,
      -1,    -1,   204,    -1,    -1,    -1,   728,    -1,    -1,  1672,
      -1,  1674,    -1,    -1,    -1,    -1,    -1,   530,   531,   532,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,  1448,    -1,    -1,    -1,   195,
      -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,
     563,    -1,    -1,  1466,    -1,  1468,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
    1483,    -1,  1485,    -1,   195,  1488,    -1,    -1,    -1,    -1,
    1743,   594,  1495,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1509,    -1,    -1,    -1,
      -1,  1514,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   834,    -1,    -1,    -1,    -1,    -1,   840,  1532,
      -1,    -1,    -1,    -1,    -1,    -1,  1539,    -1,  1541,    -1,
    1543,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
    1553,    -1,    -1,    -1,  1557,  1558,  1559,  1560,  1561,    -1,
      -1,    -1,    -1,    -1,   876,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1576,  1577,    -1,    -1,    -1,  1581,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   690,  1591,   692,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1602,
      -1,   704,   705,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    -1,
      -1,    -1,    -1,    92,    93,    -1,    95,    96,    97,  1632,
      -1,    -1,   101,    -1,  1637,    -1,    -1,    -1,    -1,   951,
     952,  1644,   954,    -1,   956,   957,   749,    -1,   960,   961,
      -1,    -1,    -1,    -1,    -1,  1658,    -1,    -1,  1661,    -1,
      -1,  1664,    -1,    -1,    -1,  1668,   135,   136,   137,  1672,
      -1,  1674,  1675,  1676,  1677,  1678,    -1,    -1,    -1,    -1,
      -1,    -1,  1685,    -1,    -1,  1688,    -1,    -1,    -1,    -1,
      -1,   794,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     803,    -1,   805,    -1,   807,    -1,   809,    -1,    -1,    -1,
      -1,   814,    -1,    -1,   817,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1728,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,    -1,  1049,  1050,  1051,
    1743,    -1,  1745,  1746,  1747,  1748,    -1,    -1,  1060,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,   870,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1781,  1782,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1791,  1792,
    1793,  1794,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1113,    -1,    -1,    -1,    -1,   909,   910,   911,   912,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1132,    -1,    -1,    -1,    -1,    -1,  1138,    -1,    -1,    -1,
      -1,    -1,  1144,    -1,  1146,  1147,    -1,    -1,    -1,  1151,
    1152,    -1,  1154,    -1,  1156,    -1,  1158,    -1,  1160,  1161,
    1162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   965,    -1,    -1,    -1,  1178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1193,    -1,    -1,    -1,  1197,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,     6,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    72,    73,  1275,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,  1288,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       6,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    62,    -1,    64,    65,    66,
      -1,    -1,     7,     8,    -1,    72,    73,    -1,    -1,    -1,
      -1,    -1,  1354,    -1,    -1,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,  1371,
     171,   172,    -1,    -1,    -1,    -1,  1378,    -1,    -1,    -1,
    1382,    -1,    -1,    -1,  1386,   186,   187,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
     201,    -1,   203,    -1,  1406,    -1,  1199,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,   150,    -1,  1427,   195,    -1,    -1,   156,
     157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,   168,   169,    -1,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     187,  1463,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,
      -1,   198,    -1,   200,   201,    -1,   203,    -1,   205,    -1,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1513,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,  1529,    -1,    -1,
     195,  1324,  1325,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1548,    -1,    -1,    -1,
      -1,    -1,    -1,     7,     3,     4,    -1,    -1,    -1,  1352,
       9,    10,    11,  1356,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,  1595,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1614,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,   112,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1468,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1687,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1488,    -1,    -1,    -1,    -1,
      -1,    -1,  1495,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
       8,    -1,   171,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   186,   187,  1532,
      -1,   195,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,   201,    -1,   203,   204,    -1,    -1,    -1,    -1,
    1553,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,  1778,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,    -1,    -1,    -1,  1672,
     112,  1674,    -1,   115,    -1,    -1,    -1,    -1,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,     8,    -1,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1743,    -1,    -1,    -1,   186,   187,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   201,
      -1,    -1,   204,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    -1,    -1,    57,    58,    59,
      -1,    -1,    62,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       8,    -1,    -1,    -1,   195,    -1,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
      -1,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,    -1,     3,     4,
       5,   201,    -1,   203,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    57,    58,    59,    -1,    -1,    62,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    82,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,   169,    -1,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   187,    -1,    -1,    -1,   191,    -1,    -1,    -1,
      -1,   196,    -1,     3,     4,     5,   201,    -1,   203,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,     8,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    -1,    -1,    57,    58,    59,
      -1,    -1,    62,    -1,    64,    65,    66,    -1,     3,     4,
       5,    -1,    72,    73,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    57,    58,    59,    -1,    -1,    62,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   156,   157,   158,   159,
     195,    -1,   197,    -1,   164,   165,   166,   167,   168,   169,
      -1,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,   201,    -1,   203,    -1,    -1,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   156,   157,   158,   159,   195,     8,    -1,    -1,   164,
     165,   166,   167,   168,   169,    -1,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   187,    -1,    -1,    -1,   191,    -1,    -1,    -1,
      -1,   196,    -1,     3,     4,     5,   201,    -1,   203,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,    -1,
      -1,   171,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   186,   187,    -1,    -1,
     195,   191,   197,    -1,    -1,    -1,   196,   202,     3,     4,
       5,   201,    -1,   203,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    82,    -1,    84,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    57,    58,    59,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,   156,    -1,    -1,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,    -1,    -1,   171,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   186,   187,    -1,    -1,   195,   191,    -1,    -1,    -1,
      -1,   196,   202,     3,     4,    -1,   201,    -1,   203,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,   157,   158,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    53,    -1,   169,    -1,   171,   172,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,    58,
      59,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,   156,    -1,    -1,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,    -1,
      -1,   171,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   186,   187,    -1,    -1,
     195,   191,    -1,    -1,    -1,    -1,   196,   202,     3,     4,
      -1,   201,    -1,   203,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,   157,   158,
      -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,
     169,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    82,    -1,    84,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    57,    58,    59,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,   156,    -1,    -1,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,    -1,    -1,   171,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   186,   187,    -1,    -1,   195,   191,    -1,    -1,    -1,
      -1,   196,   202,     3,     4,    -1,   201,    -1,   203,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,   157,   158,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    53,    -1,   169,    -1,    -1,   172,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,     5,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,    -1,
      -1,   171,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   186,   187,    -1,    -1,
     195,   191,    -1,    -1,    -1,    -1,   196,   202,     3,     4,
      -1,   201,    -1,   203,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,   157,   158,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    -1,   169,    53,    -1,
     172,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    82,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    87,    -1,    -1,    -1,
      -1,    92,    93,    -1,    95,    96,    97,    -1,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,   136,   137,    -1,    -1,    -1,
      -1,   186,   187,    -1,    -1,    -1,   191,    -1,    -1,    -1,
      -1,   196,    -1,     3,     4,    -1,   201,    -1,   203,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,   202,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,    -1,
      -1,   171,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   186,   187,    -1,    -1,
     195,   191,    -1,    -1,    -1,    -1,   196,   202,     3,     4,
      -1,   201,    -1,   203,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    64,
      65,    66,    -1,     9,    10,    11,    -1,    72,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,   156,    -1,   202,   159,   204,    -1,    -1,    -1,   164,
     165,   166,   167,   168,    -1,    -1,   171,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   186,   187,    -1,    -1,   195,   191,    -1,    -1,    -1,
      -1,   196,   202,    -1,   204,    -1,   201,    -1,   203,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,    -1,    -1,   171,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     186,   187,    -1,    -1,   195,   191,    -1,    -1,    -1,    -1,
     196,   202,     3,     4,     5,   201,    -1,   203,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    72,    73,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,
      -1,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   204,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,    -1,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   187,    -1,    -1,    -1,
     191,     3,     4,    -1,    -1,   196,    -1,     9,    10,    11,
     201,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,
     112,    -1,    -1,   115,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,    -1,    -1,   171,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   186,   187,    -1,    -1,   195,   191,
       3,     4,    -1,    -1,   196,   202,     9,    10,    11,   201,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,    -1,    -1,    -1,   191,    -1,
      54,    55,    56,   196,    -1,    -1,    60,    61,   201,    63,
      -1,    -1,    -1,    67,    68,    -1,    70,    71,    -1,    -1,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,   121,   122,   123,
       4,    -1,    -1,    -1,    -1,   129,    -1,    -1,    12,    13,
     134,   135,   136,   137,    -1,    -1,   140,    -1,   142,    -1,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    38,    39,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,   170,   171,    -1,    -1,
      54,    55,    56,    -1,    -1,    -1,    60,    61,    -1,    63,
      -1,    -1,    -1,    67,    68,    -1,    70,    71,    -1,    -1,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,   121,   122,   123,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,    -1,    -1,   140,    -1,   142,    -1,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,   170,   171,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,
      -1,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
     197,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,   197,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,   197,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,   197,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,   197,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,   197,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
     197,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,   197,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,   197,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,   197,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,   197,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,   197,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
     197,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,   197,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,   197,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,   197,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,   197,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,   197,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
     197,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,   197,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,   197
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   207,   208,     6,     0,     4,    12,    13,    38,
      39,    54,    55,    56,    60,    61,    63,    67,    68,    70,
      71,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   110,   111,   112,   113,   114,   115,
     116,   117,   121,   122,   123,   129,   134,   135,   136,   137,
     140,   142,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   160,   161,   162,   163,   170,   171,
     209,   211,   212,   232,   249,   250,   253,   254,   255,   256,
     257,   258,   259,   260,   281,   282,   283,   284,   302,   303,
       3,     4,     5,     9,    10,    11,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    57,    58,    59,    62,    64,    65,    66,
      72,    73,   150,   156,   157,   158,   159,   164,   165,   166,
     167,   168,   169,   172,   186,   187,   191,   196,   198,   200,
     201,   203,   205,   230,   285,   286,   298,   299,   302,   303,
      13,    82,   196,   196,     6,   203,     6,     6,     6,     6,
     196,     6,     6,   198,   198,   196,   198,   230,   230,   196,
     203,   196,   196,     4,   196,   203,   196,   196,     4,   203,
     196,   196,    86,    82,    82,     6,   203,    76,    79,    82,
      82,    82,    79,    82,    84,    84,    76,    79,    82,    84,
      79,    82,    84,    79,    82,   196,    79,   140,   154,   155,
     203,   186,   187,   196,   203,   288,   289,   288,   203,    76,
      79,    82,   203,   288,     4,    76,    80,    92,    82,    84,
      82,    79,     4,   150,   203,   302,   303,     4,     6,    76,
      79,    82,    79,    82,     4,     4,     4,     4,     5,    37,
      76,    79,    82,    84,    96,   187,   196,   203,   250,   260,
     285,   291,   292,   293,   302,   303,     4,   196,   196,   196,
       4,   203,   295,     4,   196,   196,     6,     6,   198,     4,
     299,   303,     4,   299,     5,   203,     5,   203,     4,   285,
     285,   198,     6,   196,   203,   196,   198,   205,   230,     7,
     173,   174,   175,   176,   193,   194,   228,   229,     4,   196,
     198,   200,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   196,   196,   196,
     196,   196,   196,   230,   230,   230,   230,   196,   230,   230,
     230,     7,   196,   196,   196,   230,   196,   196,   198,   285,
     285,   285,   285,   285,     4,   140,   141,   303,     4,   250,
     251,   252,   203,   197,   199,   203,   231,     6,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   195,   203,     6,   196,   198,   229,     6,   285,
       4,   298,   299,   303,   298,   285,   298,   301,   234,   237,
     299,   303,   285,   187,   285,   293,   294,   285,   285,   196,
     285,   294,   285,   285,   196,   294,   285,   285,   291,   196,
     203,   294,   292,   292,   292,   196,   196,   292,   292,   292,
     196,   196,   196,   196,   196,   196,   196,   196,   203,   203,
     285,     4,   291,   295,   203,   203,   288,   288,   288,   285,
     285,   186,   187,   203,   203,   288,   203,   203,   203,   186,
     187,   196,   252,   288,   203,   196,   203,   196,   196,   196,
     292,   292,   291,   196,     4,   198,   198,   252,     6,     6,
     203,   203,   203,   292,   292,   198,   198,   198,   196,   198,
     200,   230,   198,     5,   143,   203,     5,   143,     5,   143,
       5,   143,    76,    79,    82,    84,   203,   285,   293,   285,
     204,   294,     8,   188,     6,   196,   198,   230,     6,   285,
     285,   285,   200,   285,   203,   143,   285,   285,   285,     6,
       6,     6,   252,     6,   252,   198,     6,   203,   298,   291,
     291,   285,   285,   203,   203,   231,   299,   291,     6,   198,
     285,   285,     4,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   301,   298,   301,   298,   298,
     298,   291,   298,   298,   285,   298,   298,   298,   301,   298,
     285,   299,   285,   298,   298,   298,   298,   303,   299,   303,
     197,   199,     7,   228,   229,   200,     7,   230,   204,    76,
      79,    82,    84,   249,   285,   294,     7,   228,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   213,   285,   285,     6,   198,   200,   197,
     202,   197,   202,   202,   197,   202,   199,   202,   233,   199,
     233,   202,   202,   197,   188,   202,   204,   197,   197,   285,
     197,   204,   197,   197,   285,   204,   197,   197,     7,   285,
     285,   204,     6,     6,     6,   285,   285,     7,     7,   278,
     278,   285,   243,   285,   299,   244,   285,   299,   245,   285,
     299,   246,   285,   299,   285,   285,   285,   294,   294,   203,
     197,     6,   203,   252,   252,   202,   202,   202,   288,   288,
     251,   251,   202,   285,   285,   285,   285,   264,   202,   252,
     285,   285,   285,   285,   285,     7,   279,     6,     7,   285,
       6,   285,   285,   204,   294,   294,   294,     6,     6,   285,
     285,   285,   285,     4,   203,   231,   303,    54,   285,    54,
      54,    54,     5,   203,     5,   203,     5,   203,     5,   203,
     294,   197,   204,   285,   203,   285,   293,   203,   231,   197,
     197,   197,   140,   202,   252,   203,     8,   197,   199,   204,
     204,   252,   199,   197,   202,   204,   197,   199,   285,   294,
     228,     6,     6,   285,   197,   199,   229,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   202,   231,
     231,   231,   231,   231,   231,   231,   202,   202,   202,   231,
     202,   231,   231,   197,   197,   202,   202,   202,   202,   202,
     231,   231,   231,   197,   231,   287,   300,     6,   202,   197,
     197,   202,   231,   197,   197,   199,   228,   229,   200,   228,
     229,   299,   285,     6,     4,     4,   203,   296,   231,   203,
     203,   203,   203,   204,   204,   291,     8,     4,   130,   131,
     132,   133,   204,   216,   220,   223,   225,   226,   197,   199,
     285,     4,     6,   183,   210,   294,     6,   294,   285,     6,
     298,     6,   303,     6,   298,   285,   299,     7,   285,   293,
     143,     7,     7,   197,     7,   143,     7,     7,   197,   143,
       7,     7,   285,   197,   204,   203,   197,   197,   285,   291,
       4,   277,     6,   197,   197,   202,   197,   202,   197,   202,
     197,   202,   197,   197,   197,   204,   204,   294,   200,   252,
     204,   204,   288,   285,   285,   204,   204,   285,   288,   202,
     202,   202,    99,   110,   118,   119,   120,   124,   125,   126,
     127,   274,   275,   288,   204,   261,   197,   204,   197,   197,
     197,   285,     6,   285,   197,   199,   199,   204,   204,   204,
     199,   199,   202,   199,   294,   199,   203,   204,   203,   203,
     203,   294,   294,   294,   294,   204,     8,   294,   294,     7,
       7,     7,   200,   285,   204,   285,   285,     7,   200,   204,
     203,   291,     6,   228,   229,   228,   229,   204,   204,   291,
     199,   229,   200,   229,   298,   285,   285,   285,   285,   294,
     298,   291,   298,   298,   299,   239,   241,   285,   298,   285,
       6,     4,   140,   141,   285,     6,     6,     6,     7,   198,
     295,   297,     6,   294,   294,   294,   294,   231,     6,   285,
     217,   196,   196,   203,   227,     6,   229,   229,   199,   183,
     298,   197,   197,   202,     7,   231,   231,   288,    82,    84,
     291,   291,     7,   291,    82,    84,   291,   291,     7,    84,
     291,   291,     6,     7,     7,   294,     7,     7,    99,   276,
       6,     7,   228,   285,   228,   285,   228,   285,   228,   285,
       7,     7,     7,     7,     7,   204,     4,   204,   202,   202,
     202,   204,   204,   288,   288,   288,     4,     6,   203,     6,
     196,     6,   128,     6,   128,     6,   128,     6,   128,   204,
     275,   202,   274,     7,     6,     7,     7,     7,     6,   203,
       6,     6,     6,    82,   285,     6,     6,   285,   200,   204,
     285,   285,   285,   285,   204,   204,   204,   204,   285,   204,
     204,   291,   291,   291,     4,   202,     8,     8,   197,     4,
       4,   291,   204,   285,     6,   285,     6,   231,     6,     6,
       4,     6,   231,   231,   231,   231,   231,   202,   197,   197,
     197,   202,   202,   231,   240,   202,   231,   242,   197,   197,
       6,     7,   228,   229,   200,     7,     6,   295,   285,   202,
     204,   204,   204,   204,   204,   228,   196,   285,   285,   290,
     291,   203,   200,     6,     6,   210,     6,   285,   203,   285,
     299,     6,     6,     6,   203,   203,    92,   248,   248,   291,
       6,   203,   203,     6,     6,   291,   203,     6,     6,     5,
     291,   204,   291,   291,     4,     6,   291,   291,   291,   291,
     291,   291,   291,   291,   203,   203,     7,     6,     7,   285,
     285,   285,   203,   203,   202,   204,   202,   204,   202,   204,
     198,   285,   291,   285,     6,     6,     6,     6,   285,   288,
     204,     5,   203,   291,   203,   203,   203,   291,   294,   203,
       6,   199,     4,   231,   202,   202,   202,   202,   231,     6,
       6,   139,   285,   285,   285,     6,     6,     7,   202,     6,
       6,     6,   228,   229,   298,   299,     4,     4,   153,   299,
     285,     6,     4,   296,     6,   199,   295,     6,     6,     6,
       6,   291,   214,   285,   202,   202,   202,   204,   215,   285,
       4,   298,   202,   291,   299,   285,   285,   288,     6,     6,
       6,   285,   285,     6,   285,     5,     6,   203,     6,   143,
     247,   285,     6,     6,     6,     6,     6,     6,     4,     6,
       6,   294,   294,   285,   285,   299,   204,   197,   202,   204,
     251,   251,   288,     6,   265,   288,     6,   266,   288,     6,
     267,   285,   204,   202,   197,   204,   202,     6,   187,   288,
       6,   290,   288,   288,     6,   204,   285,     6,   285,   285,
     285,   285,   291,   202,   204,     8,   204,   197,   203,   285,
     299,   291,   291,   197,   231,   203,   291,   299,   203,   285,
     299,   299,     6,     6,     7,     6,   200,     6,   197,   202,
     285,   285,   291,   203,   202,   204,     6,   285,   235,   236,
     204,   204,   204,   204,   204,     5,   290,    80,     6,   203,
     204,   204,   203,     6,     6,   203,   285,   204,   204,   202,
     203,   202,   203,   202,   203,   199,     6,   291,     7,   203,
     285,   202,   204,   202,   202,     6,   204,   202,   202,   202,
     202,   138,   285,   285,   294,     6,     6,   204,     6,   238,
     285,   301,   295,   141,   218,   285,   202,   202,   290,   285,
       6,   202,   239,   241,     6,     6,     6,     6,     6,     6,
     204,   203,   290,   103,   104,   109,   280,   103,   104,   280,
     294,   251,   202,   204,   285,   288,   274,   285,   288,   274,
     285,   288,   274,     6,   202,   204,   291,   252,   204,   288,
       6,   294,   288,   285,   285,   285,   285,   285,   204,   204,
     204,     6,   202,   204,     7,   204,     6,   203,   285,   285,
     204,   285,   204,   204,   203,   285,   204,   203,   288,   291,
       6,   203,   288,     6,   204,   204,   285,   204,   202,   204,
     204,   202,   204,   204,   202,   204,   291,     6,    99,   204,
     262,   203,   202,   204,   202,   202,   202,   202,   202,     6,
       6,   285,   299,   215,   197,   202,     6,   203,   202,   285,
     204,     6,   288,     6,   288,     6,     6,   204,     6,   268,
     285,     6,     6,   269,   285,     6,     6,   270,   285,     6,
     204,   285,   274,   252,   294,     6,   288,   294,   285,   285,
     285,   285,     7,   204,   221,   285,   290,   285,   202,   202,
     202,   203,   204,   203,   204,   203,   204,     6,     6,   204,
     204,   263,   204,   202,   204,   202,   202,   202,   202,   299,
       6,   203,   197,   204,   204,   285,   288,   288,   274,     6,
     271,   274,     6,   272,   274,     6,   273,   274,     6,   294,
       6,   285,   285,   285,   285,   219,   298,   224,   203,     6,
     204,   202,   202,   204,   203,   204,   203,   204,   203,   204,
     204,   202,   202,   202,   202,   202,   204,   203,   290,     6,
     285,   285,     6,   274,     6,   274,     6,   274,     6,   285,
     285,   285,   285,   298,     6,   222,   298,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   202,   204,     6,
       6,     6,     6,     6,     6,   298,     6
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
#line 197 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 208 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 209 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 210 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 211 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 212 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 213 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 214 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 215 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 216 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 217 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 16:
#line 218 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 219 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 220 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 221 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 222 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 223 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 228 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 23:
#line 232 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 24:
#line 239 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 25:
#line 244 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 26:
#line 249 "Gmsh.y"
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

  case 27:
#line 263 "Gmsh.y"
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

  case 28:
#line 276 "Gmsh.y"
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

  case 29:
#line 289 "Gmsh.y"
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

  case 30:
#line 317 "Gmsh.y"
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

  case 31:
#line 331 "Gmsh.y"
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

  case 32:
#line 344 "Gmsh.y"
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

  case 33:
#line 357 "Gmsh.y"
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

  case 34:
#line 375 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 40:
#line 389 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:
#line 391 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:
#line 396 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 43:
#line 398 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 44:
#line 403 "Gmsh.y"
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

  case 45:
#line 507 "Gmsh.y"
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

  case 46:
#line 517 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 47:
#line 526 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 48:
#line 533 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 49:
#line 543 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    ;}
    break;

  case 50:
#line 552 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 51:
#line 561 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 568 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 578 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 54:
#line 586 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 55:
#line 596 "Gmsh.y"
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

  case 56:
#line 615 "Gmsh.y"
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

  case 57:
#line 634 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 58:
#line 640 "Gmsh.y"
    {
    ;}
    break;

  case 59:
#line 647 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 60:
#line 648 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 61:
#line 649 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 62:
#line 650 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 63:
#line 651 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 64:
#line 655 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 656 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 66:
#line 662 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 67:
#line 662 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 68:
#line 663 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 69:
#line 663 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 72:
#line 672 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 73:
#line 677 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 74:
#line 683 "Gmsh.y"
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
        else{ // list of expressions
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

  case 75:
#line 743 "Gmsh.y"
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

  case 76:
#line 772 "Gmsh.y"
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

  case 77:
#line 801 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 78:
#line 806 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 79:
#line 811 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 80:
#line 816 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 81:
#line 821 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 82:
#line 828 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 83:
#line 835 "Gmsh.y"
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

  case 84:
#line 850 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 855 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 86:
#line 860 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 865 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 88:
#line 870 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 89:
#line 879 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 90:
#line 885 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 91:
#line 894 "Gmsh.y"
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

  case 92:
#line 912 "Gmsh.y"
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

  case 93:
#line 930 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 94:
#line 939 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 95:
#line 951 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 96:
#line 956 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 97:
#line 964 "Gmsh.y"
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

  case 98:
#line 984 "Gmsh.y"
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

  case 99:
#line 1007 "Gmsh.y"
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

  case 100:
#line 1018 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 101:
#line 1026 "Gmsh.y"
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

  case 102:
#line 1048 "Gmsh.y"
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

  case 103:
#line 1071 "Gmsh.y"
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

  case 104:
#line 1097 "Gmsh.y"
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

  case 105:
#line 1118 "Gmsh.y"
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

  case 106:
#line 1130 "Gmsh.y"
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

  case 110:
#line 1148 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 111:
#line 1157 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 112:
#line 1166 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 113:
#line 1168 "Gmsh.y"
    {
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

  case 114:
#line 1184 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 115:
#line 1193 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 116:
#line 1195 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c)), val((yyvsp[(6) - (9)].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 118:
#line 1209 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 119:
#line 1217 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 120:
#line 1223 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 123:
#line 1235 "Gmsh.y"
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

  case 124:
#line 1246 "Gmsh.y"
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

  case 125:
#line 1261 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 128:
#line 1277 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 129:
#line 1285 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 130:
#line 1294 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 131:
#line 1302 "Gmsh.y"
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

  case 132:
#line 1320 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 133:
#line 1324 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 134:
#line 1330 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 135:
#line 1338 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 136:
#line 1342 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 137:
#line 1348 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 138:
#line 1356 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 139:
#line 1360 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 140:
#line 1366 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 141:
#line 1374 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 142:
#line 1378 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 143:
#line 1384 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 144:
#line 1392 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 145:
#line 1396 "Gmsh.y"
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

  case 146:
#line 1408 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 147:
#line 1412 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 148:
#line 1422 "Gmsh.y"
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

  case 149:
#line 1445 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_POINT);
      if(p && op == 0){
	yymsg(0, "Physical point %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical point %d does not exists", num);
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
      else{
	yymsg(0, "Unsupported operation on physical point %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 150:
#line 1477 "Gmsh.y"
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

  case 151:
#line 1500 "Gmsh.y"
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

  case 152:
#line 1518 "Gmsh.y"
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

  case 153:
#line 1539 "Gmsh.y"
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

  case 154:
#line 1557 "Gmsh.y"
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

  case 155:
#line 1587 "Gmsh.y"
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

  case 156:
#line 1617 "Gmsh.y"
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

  case 157:
#line 1635 "Gmsh.y"
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

  case 158:
#line 1654 "Gmsh.y"
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

  case 159:
#line 1680 "Gmsh.y"
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

  case 160:
#line 1698 "Gmsh.y"
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

  case 161:
#line 1716 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_LINE);
      if(p && op == 0){
	yymsg(0, "Physical line %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical line %d does not exists", num);
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
      else{
	yymsg(0, "Unsupported operation on physical line %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 162:
#line 1751 "Gmsh.y"
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

  case 163:
#line 1769 "Gmsh.y"
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

  case 164:
#line 1808 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 165:
#line 1814 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 166:
#line 1820 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 167:
#line 1827 "Gmsh.y"
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

  case 168:
#line 1852 "Gmsh.y"
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

  case 169:
#line 1877 "Gmsh.y"
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

  case 170:
#line 1894 "Gmsh.y"
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
	setSurfaceGeneratrices(s, (List_T*) 0 );
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 171:
#line 1914 "Gmsh.y"
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

  case 172:
#line 1947 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE);
      if(p && op == 0){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical surface %d does not exists", num);
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
      else{
	yymsg(0, "Unsupported operation on physical surface %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    ;}
    break;

  case 173:
#line 1983 "Gmsh.y"
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

  case 174:
#line 2001 "Gmsh.y"
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

  case 175:
#line 2018 "Gmsh.y"
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

  case 176:
#line 2034 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME);
      if(p && op == 0){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical volume %d does not exists", num);
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
      else{
	yymsg(0, "Unsupported operation on physical volume %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 177:
#line 2071 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 178:
#line 2076 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 179:
#line 2081 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 180:
#line 2086 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 181:
#line 2091 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 182:
#line 2096 "Gmsh.y"
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

  case 183:
#line 2119 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 184:
#line 2125 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 185:
#line 2135 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 186:
#line 2136 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 187:
#line 2141 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 188:
#line 2145 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 189:
#line 2149 "Gmsh.y"
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

  case 190:
#line 2172 "Gmsh.y"
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

  case 191:
#line 2195 "Gmsh.y"
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

  case 192:
#line 2218 "Gmsh.y"
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

  case 193:
#line 2246 "Gmsh.y"
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

  case 194:
#line 2267 "Gmsh.y"
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

  case 195:
#line 2294 "Gmsh.y"
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

  case 196:
#line 2315 "Gmsh.y"
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

  case 197:
#line 2336 "Gmsh.y"
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

  case 198:
#line 2356 "Gmsh.y"
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

  case 199:
#line 2468 "Gmsh.y"
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

  case 200:
#line 2487 "Gmsh.y"
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

  case 201:
#line 2526 "Gmsh.y"
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

  case 202:
#line 2634 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 203:
#line 2643 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 204:
#line 2649 "Gmsh.y"
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

  case 205:
#line 2664 "Gmsh.y"
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

  case 206:
#line 2692 "Gmsh.y"
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

  case 207:
#line 2709 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 208:
#line 2718 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 209:
#line 2732 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 210:
#line 2746 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 211:
#line 2752 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 212:
#line 2758 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 213:
#line 2767 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 214:
#line 2776 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 215:
#line 2785 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 216:
#line 2799 "Gmsh.y"
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
      else{
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 217:
#line 2855 "Gmsh.y"
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

  case 218:
#line 2873 "Gmsh.y"
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

  case 219:
#line 2890 "Gmsh.y"
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

  case 220:
#line 2905 "Gmsh.y"
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
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 221:
#line 2924 "Gmsh.y"
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

  case 222:
#line 2936 "Gmsh.y"
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

  case 223:
#line 2960 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 224:
#line 2964 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 225:
#line 2969 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 226:
#line 2976 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 227:
#line 2981 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 228:
#line 2987 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 229:
#line 2992 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 230:
#line 2998 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 231:
#line 3006 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 232:
#line 3010 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 233:
#line 3014 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 234:
#line 3020 "Gmsh.y"
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

  case 235:
#line 3074 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    ;}
    break;

  case 236:
#line 3087 "Gmsh.y"
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

  case 237:
#line 3104 "Gmsh.y"
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

  case 238:
#line 3121 "Gmsh.y"
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

  case 239:
#line 3143 "Gmsh.y"
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

  case 240:
#line 3165 "Gmsh.y"
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

  case 241:
#line 3200 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 242:
#line 3208 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 243:
#line 3216 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 244:
#line 3222 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 245:
#line 3229 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 246:
#line 3236 "Gmsh.y"
    {
      ImbricatedTest++;
      if(ImbricatedTest > MAX_RECUR_TESTS-1){
	yymsg(0, "Reached maximum number of imbricated tests");
        ImbricatedTest = MAX_RECUR_TESTS-1;
      }

      if(!(yyvsp[(3) - (4)].d)){
        statusImbricatedTests[ImbricatedTest] = 0; // Will be useful later for ElseIf
        int flag_until2 = 0;
        skip_until_test("If", "EndIf", "Else", &flag_until2);
        if(!flag_until2)
          ImbricatedTest--;
      }
      else{
        statusImbricatedTests[ImbricatedTest] = 1;
      }

    ;}
    break;

  case 247:
#line 3256 "Gmsh.y"
    {
      if (ImbricatedTest > 0 && statusImbricatedTests[ImbricatedTest]){
        skip_until("If", "EndIf");
        ImbricatedTest--;
      }
    ;}
    break;

  case 248:
#line 3263 "Gmsh.y"
    {
      ImbricatedTest--;
      if (ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 249:
#line 3275 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 250:
#line 3283 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 251:
#line 3291 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 252:
#line 3299 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 253:
#line 3305 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 254:
#line 3313 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 255:
#line 3319 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 256:
#line 3327 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 257:
#line 3333 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 258:
#line 3341 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 259:
#line 3347 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 260:
#line 3355 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 261:
#line 3362 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 262:
#line 3369 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 263:
#line 3376 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 264:
#line 3383 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 265:
#line 3390 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 266:
#line 3397 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 267:
#line 3404 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 268:
#line 3411 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 269:
#line 3418 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 270:
#line 3424 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 271:
#line 3431 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 272:
#line 3437 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 273:
#line 3444 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 274:
#line 3450 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 275:
#line 3457 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 276:
#line 3463 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 277:
#line 3470 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 278:
#line 3476 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 279:
#line 3483 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 280:
#line 3489 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 281:
#line 3496 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 282:
#line 3502 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 283:
#line 3509 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 284:
#line 3515 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 285:
#line 3522 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 286:
#line 3528 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 287:
#line 3539 "Gmsh.y"
    {
    ;}
    break;

  case 288:
#line 3542 "Gmsh.y"
    {
    ;}
    break;

  case 289:
#line 3548 "Gmsh.y"
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

  case 290:
#line 3560 "Gmsh.y"
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

  case 291:
#line 3580 "Gmsh.y"
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

  case 292:
#line 3604 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 293:
#line 3608 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 294:
#line 3612 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 295:
#line 3616 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 296:
#line 3620 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 297:
#line 3626 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 298:
#line 3632 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 299:
#line 3636 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 300:
#line 3640 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 301:
#line 3644 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 302:
#line 3648 "Gmsh.y"
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

  case 303:
#line 3667 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 304:
#line 3679 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 305:
#line 3683 "Gmsh.y"
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

  case 306:
#line 3698 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 307:
#line 3702 "Gmsh.y"
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

  case 308:
#line 3718 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 309:
#line 3722 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 310:
#line 3727 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 311:
#line 3731 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 312:
#line 3737 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 313:
#line 3741 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 314:
#line 3748 "Gmsh.y"
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
          for(int sign = -1; sign <= 1; sign += 2){
            Curve *c = FindCurve(sign * j);
            if(c){
              c->Method = MESH_TRANSFINITE;
              c->nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
              c->typeTransfinite = type * sign(d);
              c->coeffTransfinite = coef;
            }
            else{
              GEdge *ge = GModel::current()->getEdgeByTag(sign * j);
              if(ge){
                ge->meshAttributes.method = MESH_TRANSFINITE;
                ge->meshAttributes.nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
                ge->meshAttributes.typeTransfinite = type * sign(d);
                ge->meshAttributes.coeffTransfinite = coef;
              }
              else if(sign > 0)
                yymsg(0, "Unknown line %d", j);
            }
          }
        }
        List_Delete((yyvsp[(3) - (7)].l));
      }
    ;}
    break;

  case 315:
#line 3804 "Gmsh.y"
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

  case 316:
#line 3874 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 317:
#line 3879 "Gmsh.y"
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

  case 318:
#line 3946 "Gmsh.y"
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

  case 319:
#line 3982 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 320:
#line 3990 "Gmsh.y"
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

  case 321:
#line 4033 "Gmsh.y"
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

  case 322:
#line 4072 "Gmsh.y"
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

  case 323:
#line 4093 "Gmsh.y"
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

  case 324:
#line 4125 "Gmsh.y"
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

  case 325:
#line 4152 "Gmsh.y"
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

  case 326:
#line 4178 "Gmsh.y"
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

  case 327:
#line 4204 "Gmsh.y"
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

  case 328:
#line 4230 "Gmsh.y"
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

  case 329:
#line 4256 "Gmsh.y"
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

  case 330:
#line 4277 "Gmsh.y"
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

  case 331:
#line 4305 "Gmsh.y"
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

  case 332:
#line 4333 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    ;}
    break;

  case 333:
#line 4337 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 334:
#line 4341 "Gmsh.y"
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

  case 335:
#line 4369 "Gmsh.y"
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

  case 336:
#line 4408 "Gmsh.y"
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

  case 337:
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

  case 338:
#line 4468 "Gmsh.y"
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

  case 339:
#line 4489 "Gmsh.y"
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

  case 340:
#line 4516 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 341:
#line 4520 "Gmsh.y"
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

  case 342:
#line 4530 "Gmsh.y"
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

  case 343:
#line 4564 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 344:
#line 4565 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 345:
#line 4566 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 346:
#line 4571 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 347:
#line 4577 "Gmsh.y"
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

  case 348:
#line 4589 "Gmsh.y"
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

  case 349:
#line 4607 "Gmsh.y"
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

  case 350:
#line 4634 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 351:
#line 4635 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 352:
#line 4636 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 353:
#line 4637 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 354:
#line 4638 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 355:
#line 4639 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 356:
#line 4640 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 357:
#line 4641 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 358:
#line 4643 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 359:
#line 4649 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 360:
#line 4650 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 361:
#line 4651 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 362:
#line 4652 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 363:
#line 4653 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 364:
#line 4654 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 365:
#line 4655 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 366:
#line 4656 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 367:
#line 4657 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 368:
#line 4658 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 369:
#line 4659 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 370:
#line 4660 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 371:
#line 4661 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 372:
#line 4662 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 373:
#line 4663 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 374:
#line 4664 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 375:
#line 4665 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 376:
#line 4666 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 377:
#line 4667 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 378:
#line 4668 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 379:
#line 4669 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 380:
#line 4670 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 381:
#line 4671 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 382:
#line 4672 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 383:
#line 4673 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 384:
#line 4674 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 385:
#line 4675 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 386:
#line 4676 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 387:
#line 4677 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 388:
#line 4678 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 389:
#line 4679 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 390:
#line 4680 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 391:
#line 4681 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 392:
#line 4690 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 393:
#line 4691 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 394:
#line 4692 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 395:
#line 4693 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 396:
#line 4694 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 397:
#line 4695 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 398:
#line 4696 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 399:
#line 4697 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 400:
#line 4698 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 401:
#line 4699 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 402:
#line 4700 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 403:
#line 4705 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 404:
#line 4707 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 405:
#line 4713 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 406:
#line 4718 "Gmsh.y"
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

  case 407:
#line 4735 "Gmsh.y"
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

  case 408:
#line 4753 "Gmsh.y"
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

  case 409:
#line 4771 "Gmsh.y"
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

  case 410:
#line 4789 "Gmsh.y"
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

  case 411:
#line 4807 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 412:
#line 4812 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 413:
#line 4818 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(2) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(2) - (4)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (4)].c)]);
	(yyval.d) = s.value.size();
      }
      Free((yyvsp[(2) - (4)].c));
    ;}
    break;

  case 414:
#line 4830 "Gmsh.y"
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
        else
          (yyval.d) = (s.value[0] += (yyvsp[(2) - (2)].i));
      }
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 415:
#line 4847 "Gmsh.y"
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
        else
          (yyval.d) = (s.value[index] += (yyvsp[(5) - (5)].i));
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 416:
#line 4865 "Gmsh.y"
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
        else
          (yyval.d) = (s.value[index] += (yyvsp[(5) - (5)].i));
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 417:
#line 4883 "Gmsh.y"
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
        else
          (yyval.d) = (s.value[index] += (yyvsp[(5) - (5)].i));
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 418:
#line 4901 "Gmsh.y"
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
        else
          (yyval.d) = (s.value[index] += (yyvsp[(5) - (5)].i));
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 419:
#line 4922 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 420:
#line 4927 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 421:
#line 4932 "Gmsh.y"
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

  case 422:
#line 4942 "Gmsh.y"
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

  case 423:
#line 4952 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 424:
#line 4957 "Gmsh.y"
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

  case 425:
#line 4968 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 426:
#line 4977 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 427:
#line 4982 "Gmsh.y"
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

  case 428:
#line 5009 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 429:
#line 5013 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 430:
#line 5017 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 431:
#line 5021 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 432:
#line 5025 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 433:
#line 5032 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 434:
#line 5036 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 435:
#line 5040 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 436:
#line 5044 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 437:
#line 5051 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 438:
#line 5056 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 439:
#line 5063 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 440:
#line 5068 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 441:
#line 5072 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 442:
#line 5077 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 443:
#line 5081 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 444:
#line 5089 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 445:
#line 5100 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 446:
#line 5104 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 447:
#line 5116 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 448:
#line 5124 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 449:
#line 5132 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 450:
#line 5139 "Gmsh.y"
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

  case 451:
#line 5149 "Gmsh.y"
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

  case 452:
#line 5178 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 453:
#line 5182 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 454:
#line 5186 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 455:
#line 5190 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 456:
#line 5194 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 457:
#line 5198 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 458:
#line 5202 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 459:
#line 5206 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 460:
#line 5210 "Gmsh.y"
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

  case 461:
#line 5239 "Gmsh.y"
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

  case 462:
#line 5268 "Gmsh.y"
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

  case 463:
#line 5297 "Gmsh.y"
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

  case 464:
#line 5327 "Gmsh.y"
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

  case 465:
#line 5340 "Gmsh.y"
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

  case 466:
#line 5353 "Gmsh.y"
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

  case 467:
#line 5366 "Gmsh.y"
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

  case 468:
#line 5378 "Gmsh.y"
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

  case 469:
#line 5388 "Gmsh.y"
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

  case 470:
#line 5398 "Gmsh.y"
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

  case 471:
#line 5410 "Gmsh.y"
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

  case 472:
#line 5423 "Gmsh.y"
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

  case 473:
#line 5435 "Gmsh.y"
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

  case 474:
#line 5453 "Gmsh.y"
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

  case 475:
#line 5474 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 476:
#line 5479 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 477:
#line 5483 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 478:
#line 5487 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 479:
#line 5499 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 480:
#line 5503 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 481:
#line 5515 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 482:
#line 5522 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 483:
#line 5532 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 484:
#line 5536 "Gmsh.y"
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

  case 485:
#line 5551 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 486:
#line 5556 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 487:
#line 5563 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 488:
#line 5567 "Gmsh.y"
    {
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (1)].c))){
	yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (1)].c));
	(yyval.c) = (yyvsp[(1) - (1)].c);
      }
      else{
	std::string val = gmsh_yystringsymbols[(yyvsp[(1) - (1)].c)];
	(yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
	strcpy((yyval.c), val.c_str());
	Free((yyvsp[(1) - (1)].c));
      }
    ;}
    break;

  case 489:
#line 5580 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 490:
#line 5588 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 491:
#line 5599 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 492:
#line 5603 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 493:
#line 5607 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 494:
#line 5615 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 495:
#line 5621 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 496:
#line 5627 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 497:
#line 5635 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 498:
#line 5643 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 499:
#line 5650 "Gmsh.y"
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

  case 500:
#line 5665 "Gmsh.y"
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

  case 501:
#line 5679 "Gmsh.y"
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

  case 502:
#line 5693 "Gmsh.y"
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

  case 503:
#line 5705 "Gmsh.y"
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

  case 504:
#line 5721 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 505:
#line 5730 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 506:
#line 5739 "Gmsh.y"
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

  case 507:
#line 5749 "Gmsh.y"
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

  case 508:
#line 5760 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 509:
#line 5764 "Gmsh.y"
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

  case 510:
#line 5783 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 511:
#line 5790 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 512:
#line 5796 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 513:
#line 5798 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 514:
#line 5809 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 515:
#line 5814 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 516:
#line 5820 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 517:
#line 5829 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 518:
#line 5842 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 519:
#line 5845 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 520:
#line 5849 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 11895 "Gmsh.tab.cpp"
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


#line 5852 "Gmsh.y"


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
  for(std::map<std::string, std::string>::iterator it = gmsh_yystringsymbols.begin();
      it != gmsh_yystringsymbols.end(); it++){
    vec.push_back(it->first + " = \"" + it->second + "\";");
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
    if (!target)  Msg::Error("Could not find edge %d for periodic copy from %d",
                             iTarget,iSource);
    target->setMeshMaster(source, affineTransform);
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
    if (!target || !source)
      Msg::Error("Could not find surface %d or %d for periodic copy",
                 iTarget,iSource);
    target->setMeshMaster(source, edgeCounterparts);
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

