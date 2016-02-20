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
     tElseIf = 401,
     tElse = 402,
     tEndIf = 403,
     tExit = 404,
     tAbort = 405,
     tField = 406,
     tReturn = 407,
     tCall = 408,
     tMacro = 409,
     tShow = 410,
     tHide = 411,
     tGetValue = 412,
     tGetStringValue = 413,
     tGetEnv = 414,
     tGetString = 415,
     tGetNumber = 416,
     tHomology = 417,
     tCohomology = 418,
     tBetti = 419,
     tExists = 420,
     tFileExists = 421,
     tGMSH_MAJOR_VERSION = 422,
     tGMSH_MINOR_VERSION = 423,
     tGMSH_PATCH_VERSION = 424,
     tGmshExecutableName = 425,
     tSetPartition = 426,
     tNameToString = 427,
     tStringToName = 428,
     tAFFECTDIVIDE = 429,
     tAFFECTTIMES = 430,
     tAFFECTMINUS = 431,
     tAFFECTPLUS = 432,
     tOR = 433,
     tAND = 434,
     tNOTEQUAL = 435,
     tEQUAL = 436,
     tGREATEROREQUAL = 437,
     tLESSOREQUAL = 438,
     UNARYPREC = 439,
     tMINUSMINUS = 440,
     tPLUSPLUS = 441
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
#define tElseIf 401
#define tElse 402
#define tEndIf 403
#define tExit 404
#define tAbort 405
#define tField 406
#define tReturn 407
#define tCall 408
#define tMacro 409
#define tShow 410
#define tHide 411
#define tGetValue 412
#define tGetStringValue 413
#define tGetEnv 414
#define tGetString 415
#define tGetNumber 416
#define tHomology 417
#define tCohomology 418
#define tBetti 419
#define tExists 420
#define tFileExists 421
#define tGMSH_MAJOR_VERSION 422
#define tGMSH_MINOR_VERSION 423
#define tGMSH_PATCH_VERSION 424
#define tGmshExecutableName 425
#define tSetPartition 426
#define tNameToString 427
#define tStringToName 428
#define tAFFECTDIVIDE 429
#define tAFFECTTIMES 430
#define tAFFECTMINUS 431
#define tAFFECTPLUS 432
#define tOR 433
#define tAND 434
#define tNOTEQUAL 435
#define tEQUAL 436
#define tGREATEROREQUAL 437
#define tLESSOREQUAL 438
#define UNARYPREC 439
#define tMINUSMINUS 440
#define tPLUSPLUS 441




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
#line 594 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 607 "Gmsh.tab.cpp"

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
#define YYLAST   10639

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  207
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  522
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1849

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   441

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   192,     2,   202,     2,   191,     2,     2,
     197,   198,   189,   187,   203,   188,   201,   190,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     183,     2,   184,   178,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   199,     2,   200,   196,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   204,     2,   205,   206,     2,     2,     2,
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
     175,   176,   177,   179,   180,   181,   182,   185,   186,   193,
     194,   195
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
    1312,  1315,  1318,  1321,  1324,  1341,  1348,  1357,  1366,  1377,
    1379,  1382,  1385,  1387,  1391,  1395,  1400,  1405,  1407,  1409,
    1415,  1427,  1441,  1442,  1450,  1451,  1465,  1466,  1482,  1483,
    1490,  1499,  1508,  1517,  1530,  1543,  1556,  1571,  1586,  1601,
    1602,  1615,  1616,  1629,  1630,  1643,  1644,  1661,  1662,  1679,
    1680,  1697,  1698,  1717,  1718,  1737,  1738,  1757,  1759,  1762,
    1768,  1776,  1786,  1789,  1792,  1795,  1799,  1802,  1806,  1809,
    1813,  1816,  1820,  1830,  1837,  1838,  1842,  1843,  1845,  1846,
    1849,  1850,  1853,  1854,  1857,  1865,  1872,  1881,  1887,  1891,
    1900,  1906,  1911,  1918,  1930,  1942,  1961,  1980,  1993,  2006,
    2019,  2030,  2041,  2052,  2063,  2074,  2079,  2084,  2089,  2094,
    2099,  2102,  2106,  2113,  2115,  2117,  2119,  2122,  2128,  2136,
    2147,  2149,  2153,  2156,  2159,  2162,  2166,  2170,  2174,  2178,
    2182,  2186,  2190,  2194,  2198,  2202,  2206,  2210,  2214,  2218,
    2224,  2229,  2234,  2239,  2244,  2249,  2254,  2259,  2264,  2269,
    2274,  2281,  2286,  2291,  2296,  2301,  2306,  2311,  2316,  2323,
    2330,  2337,  2342,  2344,  2346,  2348,  2350,  2352,  2354,  2356,
    2358,  2360,  2362,  2364,  2365,  2372,  2377,  2384,  2386,  2391,
    2396,  2401,  2406,  2411,  2416,  2421,  2424,  2430,  2436,  2442,
    2448,  2452,  2459,  2464,  2472,  2479,  2486,  2493,  2500,  2505,
    2507,  2510,  2513,  2517,  2521,  2533,  2543,  2551,  2559,  2561,
    2565,  2567,  2569,  2572,  2576,  2581,  2587,  2589,  2591,  2594,
    2598,  2602,  2608,  2613,  2616,  2619,  2622,  2625,  2629,  2633,
    2637,  2641,  2647,  2653,  2659,  2665,  2682,  2699,  2716,  2733,
    2735,  2737,  2741,  2745,  2750,  2757,  2764,  2766,  2768,  2772,
    2776,  2786,  2794,  2796,  2802,  2806,  2813,  2815,  2819,  2821,
    2823,  2827,  2834,  2836,  2841,  2843,  2845,  2847,  2852,  2859,
    2864,  2871,  2876,  2881,  2886,  2895,  2900,  2905,  2910,  2915,
    2924,  2929,  2936,  2941,  2943,  2944,  2951,  2953,  2957,  2963,
    2969,  2971,  2973
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     208,     0,    -1,   209,    -1,     1,     6,    -1,    -1,   209,
     210,    -1,   213,    -1,   212,    -1,   233,    -1,   250,    -1,
     251,    -1,   255,    -1,   256,    -1,   257,    -1,   258,    -1,
     261,    -1,   282,    -1,   283,    -1,   260,    -1,   259,    -1,
     254,    -1,   285,    -1,   184,    -1,   184,   184,    -1,    38,
     197,   299,   198,     6,    -1,    39,   197,   299,   198,     6,
      -1,    38,   197,   299,   198,   211,   299,     6,    -1,    38,
     197,   299,   203,   295,   198,     6,    -1,    39,   197,   299,
     203,   295,   198,     6,    -1,    38,   197,   299,   203,   295,
     198,   211,   299,     6,    -1,     4,   299,   204,   214,   205,
       6,    -1,   121,     4,   199,   286,   200,     6,    -1,   122,
       4,   199,   286,   200,     6,    -1,   123,     4,   199,   286,
     203,   286,   200,     6,    -1,    -1,   214,   217,    -1,   214,
     221,    -1,   214,   224,    -1,   214,   226,    -1,   214,   227,
      -1,   286,    -1,   215,   203,   286,    -1,   286,    -1,   216,
     203,   286,    -1,    -1,    -1,     4,   218,   197,   215,   198,
     219,   204,   216,   205,     6,    -1,   299,    -1,   220,   203,
     299,    -1,    -1,   130,   197,   286,   203,   286,   203,   286,
     198,   222,   204,   220,   205,     6,    -1,   299,    -1,   223,
     203,   299,    -1,    -1,   131,   197,   286,   203,   286,   203,
     286,   203,   286,   198,   225,   204,   223,   205,     6,    -1,
     132,   204,   291,   205,   204,   291,   205,     6,    -1,   132,
     204,   291,   205,   204,   291,   205,   204,   291,   205,   204,
     291,   205,     6,    -1,    -1,   133,   228,   204,   216,   205,
       6,    -1,     7,    -1,   177,    -1,   176,    -1,   175,    -1,
     174,    -1,   195,    -1,   194,    -1,   197,    -1,   199,    -1,
     198,    -1,   200,    -1,    70,   199,   235,   200,     6,    -1,
      71,   199,   238,   200,     6,    -1,    74,   231,   300,   203,
     286,   232,     6,    -1,    75,   231,   304,   203,   300,   232,
       6,    -1,   304,   229,   292,     6,    -1,     4,   231,   232,
     229,   292,     6,    -1,   303,   231,   232,   229,   292,     6,
      -1,     4,   199,   286,   200,   229,   286,     6,    -1,     4,
     197,   286,   198,   229,   286,     6,    -1,   303,   199,   286,
     200,   229,   286,     6,    -1,   303,   197,   286,   198,   229,
     286,     6,    -1,     4,   231,   204,   295,   205,   232,   229,
     292,     6,    -1,   303,   231,   204,   295,   205,   232,   229,
     292,     6,    -1,   304,   230,     6,    -1,     4,   199,   286,
     200,   230,     6,    -1,     4,   197,   286,   198,   230,     6,
      -1,   303,   199,   286,   200,   230,     6,    -1,   303,   197,
     286,   198,   230,     6,    -1,   304,     7,   300,     6,    -1,
       4,   201,     4,     7,   300,     6,    -1,     4,   199,   286,
     200,   201,     4,     7,   300,     6,    -1,     4,   201,     4,
     229,   286,     6,    -1,     4,   199,   286,   200,   201,     4,
     229,   286,     6,    -1,     4,   201,     4,   230,     6,    -1,
       4,   199,   286,   200,   201,     4,   230,     6,    -1,     4,
     201,   140,   201,     4,     7,   296,     6,    -1,     4,   199,
     286,   200,   201,   140,   201,     4,     7,   296,     6,    -1,
       4,   201,   141,     7,   297,     6,    -1,     4,   199,   286,
     200,   201,   141,     7,   297,     6,    -1,     4,   151,     7,
     286,     6,    -1,   151,   199,   286,   200,     7,     4,     6,
      -1,   151,   199,   286,   200,   201,     4,     7,   286,     6,
      -1,   151,   199,   286,   200,   201,     4,     7,   300,     6,
      -1,   151,   199,   286,   200,   201,     4,     7,   204,   295,
     205,     6,    -1,   151,   199,   286,   200,   201,     4,     6,
      -1,   100,   197,     4,   198,   201,     4,     7,   286,     6,
      -1,   100,   197,     4,   198,   201,     4,     7,   300,     6,
      -1,    -1,   203,    -1,    -1,   235,   234,   304,    -1,   235,
     234,   304,     7,   286,    -1,    -1,   235,   234,   304,     7,
     204,   292,   236,   240,   205,    -1,   235,   234,   304,     7,
     300,    -1,    -1,   235,   234,   304,     7,   204,   300,   237,
     242,   205,    -1,    -1,   238,   234,   299,    -1,   286,     7,
     300,    -1,   239,   203,   286,     7,   300,    -1,    -1,   240,
     241,    -1,   203,     4,   292,    -1,   203,     4,   204,   239,
     205,    -1,   203,     4,   300,    -1,    -1,   242,   243,    -1,
     203,     4,   286,    -1,   203,     4,   300,    -1,   203,   154,
     300,    -1,   203,     4,   204,   302,   205,    -1,   286,    -1,
     300,    -1,   300,   203,   286,    -1,   286,    -1,   300,    -1,
     300,   203,   286,    -1,   286,    -1,   300,    -1,   300,   203,
     286,    -1,   286,    -1,   300,    -1,   300,   203,   286,    -1,
      -1,   143,    80,   204,   286,   205,    -1,    -1,    92,   289,
      -1,    76,   197,   286,   198,     7,   289,     6,    -1,    96,
      76,   197,   244,   198,   229,   292,     6,    -1,    85,    86,
     292,     7,   286,     6,    -1,    79,   197,   286,   198,     7,
     292,     6,    -1,   101,    79,   292,     6,    -1,    83,   197,
     286,   198,     7,   292,     6,    -1,    77,   197,   286,   198,
       7,   292,   249,     6,    -1,    78,   197,   286,   198,     7,
     292,   249,     6,    -1,   135,   197,   286,   198,     7,   292,
       6,    -1,   136,   197,   286,   198,     7,   292,     6,    -1,
     137,   197,   286,   198,     7,   292,   139,   292,   138,   286,
       6,    -1,    79,     4,   197,   286,   198,     7,   292,     6,
      -1,    97,    79,   197,   286,   198,     7,   292,     6,    -1,
      96,    79,   197,   245,   198,   229,   292,     6,    -1,    92,
      82,   197,   286,   198,     7,   292,     6,    -1,    93,    82,
     197,   286,   198,     7,   292,   248,     6,    -1,    12,    13,
       6,    -1,    13,    82,   286,     6,    -1,    87,    82,   197,
     286,   198,     7,     5,     5,     5,     6,    -1,    80,   197,
     286,   198,     7,   292,     6,    -1,    81,   197,   286,   198,
       7,   292,     6,    -1,    82,     4,   197,   286,   198,     7,
     292,     6,    -1,    97,    82,   197,   286,   198,     7,   292,
       6,    -1,    97,    82,   197,   286,   198,     7,   292,     4,
     204,   291,   205,     6,    -1,    96,    82,   197,   246,   198,
     229,   292,     6,    -1,    95,    84,   197,   286,   198,     7,
     292,     6,    -1,    84,   197,   286,   198,     7,   292,     6,
      -1,    97,    84,   197,   286,   198,     7,   292,     6,    -1,
      96,    84,   197,   247,   198,   229,   292,     6,    -1,   104,
     289,   204,   252,   205,    -1,   103,   204,   289,   203,   289,
     203,   286,   205,   204,   252,   205,    -1,   105,   289,   204,
     252,   205,    -1,   106,   204,   289,   203,   286,   205,   204,
     252,   205,    -1,   106,   204,   289,   203,   289,   205,   204,
     252,   205,    -1,     4,   204,   252,   205,    -1,   115,    79,
     204,   295,   205,    82,   204,   286,   205,    -1,   112,    79,
     197,   286,   198,   204,   295,   205,     6,    -1,   253,    -1,
     251,    -1,    -1,   253,   250,    -1,   253,    76,   204,   295,
     205,     6,    -1,   253,    79,   204,   295,   205,     6,    -1,
     253,    82,   204,   295,   205,     6,    -1,   253,    84,   204,
     295,   205,     6,    -1,   108,    92,   197,   286,   198,     7,
     292,     6,    -1,   108,    76,   197,   286,   198,     7,   204,
     291,   205,     6,    -1,   108,    92,   197,   286,   198,     7,
     204,   289,   203,   289,   203,   295,   205,     6,    -1,   108,
      92,   197,   286,   198,     7,   204,   289,   203,   289,   203,
     289,   203,   295,   205,     6,    -1,   108,    80,   197,   286,
     198,     7,   204,   289,   203,   295,   205,     6,    -1,   108,
       4,   197,   286,   198,     7,   292,     6,    -1,   108,     4,
     197,   286,   198,     7,     5,     6,    -1,   108,     4,   204,
     286,   205,     6,    -1,   108,     4,   197,   286,   198,     7,
     204,   289,   203,   289,   203,   295,   205,     6,    -1,   113,
     204,   253,   205,    -1,   113,   151,   199,   286,   200,     6,
      -1,   113,     4,   199,   286,   200,     6,    -1,   113,   304,
       6,    -1,   113,     4,     4,     6,    -1,   140,   296,   204,
     253,   205,    -1,   102,   140,   296,   204,   253,   205,    -1,
     171,   286,   204,   253,   205,    -1,   155,     5,     6,    -1,
     156,     5,     6,    -1,   155,   204,   253,   205,    -1,   102,
     155,   204,   253,   205,    -1,   156,   204,   253,   205,    -1,
     102,   156,   204,   253,   205,    -1,     4,   300,     6,    -1,
      63,   197,   302,   198,     6,    -1,     4,     4,   199,   286,
     200,   299,     6,    -1,     4,     4,     4,   199,   286,   200,
       6,    -1,     4,   286,     6,    -1,   100,   197,     4,   198,
     201,     4,     6,    -1,   134,     4,     6,    -1,   149,     6,
      -1,   150,     6,    -1,    60,     6,    -1,    61,     6,    -1,
      54,     6,    -1,    54,   204,   286,   203,   286,   203,   286,
     203,   286,   203,   286,   203,   286,   205,     6,    -1,    55,
       6,    -1,    56,     6,    -1,    67,     6,    -1,    68,     6,
      -1,    89,     6,    -1,    90,   204,   295,   205,   204,   295,
     205,   204,   291,   205,   204,   286,   203,   286,   205,     6,
      -1,   142,   197,   286,     8,   286,   198,    -1,   142,   197,
     286,     8,   286,     8,   286,   198,    -1,   142,     4,   143,
     204,   286,     8,   286,   205,    -1,   142,     4,   143,   204,
     286,     8,   286,     8,   286,   205,    -1,   144,    -1,   154,
       4,    -1,   154,   300,    -1,   152,    -1,   153,   304,     6,
      -1,   153,   300,     6,    -1,   145,   197,   286,   198,    -1,
     146,   197,   286,   198,    -1,   147,    -1,   148,    -1,   107,
     289,   204,   253,   205,    -1,   107,   204,   289,   203,   289,
     203,   286,   205,   204,   253,   205,    -1,   107,   204,   289,
     203,   289,   203,   289,   203,   286,   205,   204,   253,   205,
      -1,    -1,   107,   289,   204,   253,   262,   275,   205,    -1,
      -1,   107,   204,   289,   203,   289,   203,   286,   205,   204,
     253,   263,   275,   205,    -1,    -1,   107,   204,   289,   203,
     289,   203,   289,   203,   286,   205,   204,   253,   264,   275,
     205,    -1,    -1,   107,   204,   253,   265,   275,   205,    -1,
     107,    76,   204,   286,   203,   289,   205,     6,    -1,   107,
      79,   204,   286,   203,   289,   205,     6,    -1,   107,    82,
     204,   286,   203,   289,   205,     6,    -1,   107,    76,   204,
     286,   203,   289,   203,   289,   203,   286,   205,     6,    -1,
     107,    79,   204,   286,   203,   289,   203,   289,   203,   286,
     205,     6,    -1,   107,    82,   204,   286,   203,   289,   203,
     289,   203,   286,   205,     6,    -1,   107,    76,   204,   286,
     203,   289,   203,   289,   203,   289,   203,   286,   205,     6,
      -1,   107,    79,   204,   286,   203,   289,   203,   289,   203,
     289,   203,   286,   205,     6,    -1,   107,    82,   204,   286,
     203,   289,   203,   289,   203,   289,   203,   286,   205,     6,
      -1,    -1,   107,    76,   204,   286,   203,   289,   205,   266,
     204,   275,   205,     6,    -1,    -1,   107,    79,   204,   286,
     203,   289,   205,   267,   204,   275,   205,     6,    -1,    -1,
     107,    82,   204,   286,   203,   289,   205,   268,   204,   275,
     205,     6,    -1,    -1,   107,    76,   204,   286,   203,   289,
     203,   289,   203,   286,   205,   269,   204,   275,   205,     6,
      -1,    -1,   107,    79,   204,   286,   203,   289,   203,   289,
     203,   286,   205,   270,   204,   275,   205,     6,    -1,    -1,
     107,    82,   204,   286,   203,   289,   203,   289,   203,   286,
     205,   271,   204,   275,   205,     6,    -1,    -1,   107,    76,
     204,   286,   203,   289,   203,   289,   203,   289,   203,   286,
     205,   272,   204,   275,   205,     6,    -1,    -1,   107,    79,
     204,   286,   203,   289,   203,   289,   203,   289,   203,   286,
     205,   273,   204,   275,   205,     6,    -1,    -1,   107,    82,
     204,   286,   203,   289,   203,   289,   203,   289,   203,   286,
     205,   274,   204,   275,   205,     6,    -1,   276,    -1,   275,
     276,    -1,   118,   204,   286,   205,     6,    -1,   118,   204,
     292,   203,   292,   205,     6,    -1,   118,   204,   292,   203,
     292,   203,   292,   205,     6,    -1,   119,     6,    -1,   110,
       6,    -1,   126,     6,    -1,   126,   128,     6,    -1,   127,
       6,    -1,   127,   128,     6,    -1,   124,     6,    -1,   124,
     128,     6,    -1,   125,     6,    -1,   125,   128,     6,    -1,
     120,   197,   286,   198,     7,   292,    99,   286,     6,    -1,
      99,     4,   199,   286,   200,     6,    -1,    -1,    99,     4,
     286,    -1,    -1,     4,    -1,    -1,     7,   292,    -1,    -1,
       7,   286,    -1,    -1,   109,   292,    -1,    94,    79,   293,
       7,   286,   277,     6,    -1,    94,    82,   293,   279,   278,
       6,    -1,    88,    82,   204,   286,   205,     7,   292,     6,
      -1,    94,    84,   293,   279,     6,    -1,   129,   293,     6,
      -1,   116,    82,   204,   295,   205,     7,   286,     6,    -1,
     110,    82,   293,   280,     6,    -1,   110,    84,   293,     6,
      -1,   111,    82,   292,     7,   286,     6,    -1,    98,    79,
     204,   295,   205,     7,   204,   295,   205,   281,     6,    -1,
      98,    82,   204,   295,   205,     7,   204,   295,   205,   281,
       6,    -1,    98,    79,   204,   295,   205,     7,   204,   295,
     205,   103,   204,   289,   203,   289,   203,   286,   205,     6,
      -1,    98,    82,   204,   295,   205,     7,   204,   295,   205,
     103,   204,   289,   203,   289,   203,   286,   205,     6,    -1,
      98,    79,   204,   295,   205,     7,   204,   295,   205,   104,
     289,     6,    -1,    98,    82,   204,   295,   205,     7,   204,
     295,   205,   104,   289,     6,    -1,    98,    82,   286,   204,
     295,   205,     7,   286,   204,   295,   205,     6,    -1,    76,
     204,   295,   205,   143,    82,   204,   286,   205,     6,    -1,
      79,   204,   295,   205,   143,    82,   204,   286,   205,     6,
      -1,    76,   204,   295,   205,   143,    84,   204,   286,   205,
       6,    -1,    79,   204,   295,   205,   143,    84,   204,   286,
     205,     6,    -1,    82,   204,   295,   205,   143,    84,   204,
     286,   205,     6,    -1,   117,    82,   293,     6,    -1,   117,
      79,   293,     6,    -1,    91,    76,   293,     6,    -1,    91,
      79,   293,     6,    -1,    91,    82,   293,     6,    -1,   114,
       6,    -1,   114,     4,     6,    -1,   114,    76,   204,   295,
     205,     6,    -1,   162,    -1,   163,    -1,   164,    -1,   284,
       6,    -1,   284,   204,   292,   205,     6,    -1,   284,   204,
     292,   203,   292,   205,     6,    -1,   284,   197,   292,   198,
     204,   292,   203,   292,   205,     6,    -1,   287,    -1,   197,
     286,   198,    -1,   188,   286,    -1,   187,   286,    -1,   192,
     286,    -1,   286,   188,   286,    -1,   286,   187,   286,    -1,
     286,   189,   286,    -1,   286,   190,   286,    -1,   286,   191,
     286,    -1,   286,   196,   286,    -1,   286,   183,   286,    -1,
     286,   184,   286,    -1,   286,   186,   286,    -1,   286,   185,
     286,    -1,   286,   182,   286,    -1,   286,   181,   286,    -1,
     286,   180,   286,    -1,   286,   179,   286,    -1,   286,   178,
     286,     8,   286,    -1,    15,   231,   286,   232,    -1,    16,
     231,   286,   232,    -1,    17,   231,   286,   232,    -1,    18,
     231,   286,   232,    -1,    19,   231,   286,   232,    -1,    20,
     231,   286,   232,    -1,    21,   231,   286,   232,    -1,    22,
     231,   286,   232,    -1,    23,   231,   286,   232,    -1,    25,
     231,   286,   232,    -1,    26,   231,   286,   203,   286,   232,
      -1,    27,   231,   286,   232,    -1,    28,   231,   286,   232,
      -1,    29,   231,   286,   232,    -1,    30,   231,   286,   232,
      -1,    31,   231,   286,   232,    -1,    32,   231,   286,   232,
      -1,    33,   231,   286,   232,    -1,    34,   231,   286,   203,
     286,   232,    -1,    35,   231,   286,   203,   286,   232,    -1,
      36,   231,   286,   203,   286,   232,    -1,    24,   231,   286,
     232,    -1,     3,    -1,     9,    -1,    14,    -1,    10,    -1,
      11,    -1,   167,    -1,   168,    -1,   169,    -1,    64,    -1,
      65,    -1,    66,    -1,    -1,    72,   231,   286,   288,   240,
     232,    -1,   161,   231,   299,   232,    -1,   161,   231,   299,
     203,   286,   232,    -1,   304,    -1,     4,   199,   286,   200,
      -1,     4,   197,   286,   198,    -1,   303,   199,   286,   200,
      -1,   303,   197,   286,   198,    -1,   165,   197,   304,   198,
      -1,   166,   197,   300,   198,    -1,   202,   304,   231,   232,
      -1,   304,   230,    -1,     4,   199,   286,   200,   230,    -1,
       4,   197,   286,   198,   230,    -1,   303,   199,   286,   200,
     230,    -1,   303,   197,   286,   198,   230,    -1,     4,   201,
       4,    -1,     4,   199,   286,   200,   201,     4,    -1,     4,
     201,     4,   230,    -1,     4,   199,   286,   200,   201,     4,
     230,    -1,   157,   197,   299,   203,   286,   198,    -1,    46,
     197,   292,   203,   292,   198,    -1,    47,   197,   299,   203,
     299,   198,    -1,    48,   197,   299,   203,   299,   198,    -1,
      53,   197,   302,   198,    -1,   290,    -1,   188,   289,    -1,
     187,   289,    -1,   289,   188,   289,    -1,   289,   187,   289,
      -1,   204,   286,   203,   286,   203,   286,   203,   286,   203,
     286,   205,    -1,   204,   286,   203,   286,   203,   286,   203,
     286,   205,    -1,   204,   286,   203,   286,   203,   286,   205,
      -1,   197,   286,   203,   286,   203,   286,   198,    -1,   292,
      -1,   291,   203,   292,    -1,   286,    -1,   294,    -1,   204,
     205,    -1,   204,   295,   205,    -1,   188,   204,   295,   205,
      -1,   286,   189,   204,   295,   205,    -1,   292,    -1,     5,
      -1,   188,   294,    -1,   286,   189,   294,    -1,   286,     8,
     286,    -1,   286,     8,   286,     8,   286,    -1,    76,   204,
     286,   205,    -1,    76,     5,    -1,    79,     5,    -1,    82,
       5,    -1,    84,     5,    -1,    96,    76,     5,    -1,    96,
      79,     5,    -1,    96,    82,     5,    -1,    96,    84,     5,
      -1,    96,    76,   204,   295,   205,    -1,    96,    79,   204,
     295,   205,    -1,    96,    82,   204,   295,   205,    -1,    96,
      84,   204,   295,   205,    -1,    76,   143,    54,   204,   286,
     203,   286,   203,   286,   203,   286,   203,   286,   203,   286,
     205,    -1,    79,   143,    54,   204,   286,   203,   286,   203,
     286,   203,   286,   203,   286,   203,   286,   205,    -1,    82,
     143,    54,   204,   286,   203,   286,   203,   286,   203,   286,
     203,   286,   203,   286,   205,    -1,    84,   143,    54,   204,
     286,   203,   286,   203,   286,   203,   286,   203,   286,   203,
     286,   205,    -1,   251,    -1,   261,    -1,     4,   231,   232,
      -1,   303,   231,   232,    -1,    37,   199,   304,   200,    -1,
       4,   231,   204,   295,   205,   232,    -1,   303,   231,   204,
     295,   205,   232,    -1,   286,    -1,   294,    -1,   295,   203,
     286,    -1,   295,   203,   294,    -1,   204,   286,   203,   286,
     203,   286,   203,   286,   205,    -1,   204,   286,   203,   286,
     203,   286,   205,    -1,   304,    -1,     4,   201,   140,   201,
       4,    -1,   204,   298,   205,    -1,     4,   199,   286,   200,
     201,   141,    -1,   296,    -1,   298,   203,   296,    -1,   300,
      -1,   304,    -1,     4,   201,     4,    -1,     4,   199,   286,
     200,   201,     4,    -1,     5,    -1,   172,   199,   304,   200,
      -1,    57,    -1,   170,    -1,    62,    -1,   159,   197,   299,
     198,    -1,   158,   197,   299,   203,   299,   198,    -1,   160,
     231,   299,   232,    -1,   160,   231,   299,   203,   299,   232,
      -1,    42,   231,   302,   232,    -1,    43,   197,   299,   198,
      -1,    44,   197,   299,   198,    -1,    45,   197,   299,   203,
     299,   203,   299,   198,    -1,    40,   231,   302,   232,    -1,
      50,   231,   299,   232,    -1,    51,   231,   299,   232,    -1,
      52,   231,   299,   232,    -1,    49,   231,   286,   203,   300,
     203,   300,   232,    -1,    41,   231,   299,   232,    -1,    41,
     231,   299,   203,   295,   232,    -1,    58,   231,   299,   232,
      -1,    59,    -1,    -1,    73,   231,   300,   301,   242,   232,
      -1,   299,    -1,   302,   203,   299,    -1,     4,   206,   204,
     286,   205,    -1,   303,   206,   204,   286,   205,    -1,     4,
      -1,   303,    -1,   173,   199,   299,   200,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   197,   197,   198,   203,   205,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   228,   232,   239,   244,   249,   263,   276,   289,
     317,   331,   344,   357,   376,   381,   382,   383,   384,   385,
     389,   391,   396,   398,   404,   508,   403,   526,   533,   544,
     543,   561,   568,   579,   578,   595,   612,   635,   634,   648,
     649,   650,   651,   652,   656,   657,   663,   663,   664,   664,
     670,   671,   672,   677,   683,   743,   772,   801,   806,   811,
     816,   821,   828,   835,   850,   855,   860,   865,   870,   879,
     885,   894,   912,   930,   939,   951,   956,   964,   984,  1007,
    1018,  1026,  1048,  1071,  1097,  1118,  1130,  1144,  1144,  1146,
    1148,  1157,  1167,  1166,  1184,  1194,  1193,  1207,  1209,  1217,
    1223,  1230,  1231,  1235,  1246,  1261,  1271,  1272,  1277,  1285,
    1294,  1302,  1320,  1324,  1330,  1338,  1342,  1348,  1356,  1360,
    1366,  1374,  1378,  1384,  1393,  1396,  1409,  1412,  1422,  1445,
    1485,  1508,  1526,  1547,  1565,  1595,  1625,  1643,  1661,  1688,
    1706,  1724,  1767,  1785,  1824,  1830,  1836,  1843,  1868,  1893,
    1910,  1929,  1963,  2007,  2025,  2042,  2058,  2103,  2108,  2113,
    2118,  2123,  2128,  2151,  2157,  2168,  2169,  2174,  2177,  2181,
    2204,  2227,  2250,  2278,  2299,  2325,  2346,  2368,  2388,  2500,
    2519,  2557,  2666,  2675,  2681,  2696,  2724,  2741,  2750,  2764,
    2778,  2784,  2790,  2799,  2808,  2817,  2831,  2890,  2908,  2925,
    2940,  2966,  2978,  3002,  3006,  3011,  3018,  3023,  3029,  3034,
    3040,  3048,  3052,  3056,  3061,  3121,  3138,  3155,  3177,  3199,
    3234,  3242,  3250,  3256,  3263,  3270,  3290,  3316,  3328,  3340,
    3348,  3356,  3365,  3364,  3379,  3378,  3393,  3392,  3407,  3406,
    3420,  3427,  3434,  3441,  3448,  3455,  3462,  3469,  3476,  3484,
    3483,  3497,  3496,  3510,  3509,  3523,  3522,  3536,  3535,  3549,
    3548,  3562,  3561,  3575,  3574,  3588,  3587,  3604,  3607,  3613,
    3625,  3645,  3669,  3673,  3677,  3681,  3685,  3691,  3697,  3701,
    3705,  3709,  3713,  3732,  3745,  3748,  3764,  3767,  3784,  3787,
    3793,  3796,  3803,  3806,  3813,  3869,  3939,  3944,  4011,  4047,
    4055,  4098,  4137,  4157,  4189,  4216,  4242,  4268,  4294,  4320,
    4342,  4370,  4398,  4402,  4406,  4434,  4473,  4512,  4533,  4554,
    4581,  4585,  4595,  4630,  4631,  4632,  4636,  4642,  4654,  4672,
    4700,  4701,  4702,  4703,  4704,  4705,  4706,  4707,  4708,  4715,
    4716,  4717,  4718,  4719,  4720,  4721,  4722,  4723,  4724,  4725,
    4726,  4727,  4728,  4729,  4730,  4731,  4732,  4733,  4734,  4735,
    4736,  4737,  4738,  4739,  4740,  4741,  4742,  4743,  4744,  4745,
    4746,  4747,  4756,  4757,  4758,  4759,  4760,  4761,  4762,  4763,
    4764,  4765,  4766,  4771,  4770,  4778,  4783,  4788,  4805,  4823,
    4841,  4859,  4877,  4882,  4888,  4900,  4917,  4935,  4953,  4971,
    4992,  4997,  5002,  5012,  5022,  5027,  5038,  5047,  5052,  5079,
    5083,  5087,  5091,  5095,  5102,  5106,  5110,  5114,  5121,  5126,
    5133,  5138,  5142,  5147,  5151,  5159,  5170,  5174,  5186,  5194,
    5202,  5209,  5219,  5248,  5252,  5256,  5260,  5264,  5268,  5272,
    5276,  5280,  5309,  5338,  5367,  5396,  5409,  5422,  5435,  5448,
    5458,  5468,  5480,  5493,  5505,  5523,  5544,  5549,  5553,  5557,
    5569,  5573,  5585,  5595,  5605,  5609,  5624,  5629,  5636,  5640,
    5653,  5661,  5672,  5676,  5680,  5688,  5694,  5700,  5708,  5716,
    5723,  5731,  5746,  5760,  5774,  5786,  5802,  5811,  5820,  5830,
    5841,  5845,  5864,  5871,  5878,  5877,  5890,  5895,  5901,  5910,
    5923,  5926,  5930
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
  "tIn", "tEndFor", "tIf", "tElseIf", "tElse", "tEndIf", "tExit", "tAbort",
  "tField", "tReturn", "tCall", "tMacro", "tShow", "tHide", "tGetValue",
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
     425,   426,   427,   428,   429,   430,   431,   432,    63,   433,
     434,   435,   436,    60,    62,   437,   438,    43,    45,    42,
      47,    37,    33,   439,   440,   441,    94,    40,    41,    91,
      93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   207,   208,   208,   209,   209,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   211,   211,   212,   212,   212,   212,   212,   212,
     213,   213,   213,   213,   214,   214,   214,   214,   214,   214,
     215,   215,   216,   216,   218,   219,   217,   220,   220,   222,
     221,   223,   223,   225,   224,   226,   226,   228,   227,   229,
     229,   229,   229,   229,   230,   230,   231,   231,   232,   232,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   234,   234,   235,
     235,   235,   236,   235,   235,   237,   235,   238,   238,   239,
     239,   240,   240,   241,   241,   241,   242,   242,   243,   243,
     243,   243,   244,   244,   244,   245,   245,   245,   246,   246,
     246,   247,   247,   247,   248,   248,   249,   249,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   251,   251,   251,
     251,   251,   251,   251,   251,   252,   252,   253,   253,   253,
     253,   253,   253,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   255,   255,   255,   255,   255,   256,   256,   257,
     258,   258,   258,   258,   258,   258,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   261,
     261,   261,   262,   261,   263,   261,   264,   261,   265,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   266,
     261,   267,   261,   268,   261,   269,   261,   270,   261,   271,
     261,   272,   261,   273,   261,   274,   261,   275,   275,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   277,   277,   278,   278,   279,   279,
     280,   280,   281,   281,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     283,   283,   283,   284,   284,   284,   285,   285,   285,   285,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   288,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   289,
     289,   289,   289,   289,   290,   290,   290,   290,   291,   291,
     292,   292,   292,   292,   292,   292,   293,   293,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   295,   295,   295,   295,
     296,   296,   296,   296,   297,   297,   298,   298,   299,   299,
     299,   299,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   301,   300,   302,   302,   303,   303,
     304,   304,   304
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
       2,     2,     2,     2,    16,     6,     8,     8,    10,     1,
       2,     2,     1,     3,     3,     4,     4,     1,     1,     5,
      11,    13,     0,     7,     0,    13,     0,    15,     0,     6,
       8,     8,     8,    12,    12,    12,    14,    14,    14,     0,
      12,     0,    12,     0,    12,     0,    16,     0,    16,     0,
      16,     0,    18,     0,    18,     0,    18,     1,     2,     5,
       7,     9,     2,     2,     2,     3,     2,     3,     2,     3,
       2,     3,     9,     6,     0,     3,     0,     1,     0,     2,
       0,     2,     0,     2,     7,     6,     8,     5,     3,     8,
       5,     4,     6,    11,    11,    18,    18,    12,    12,    12,
      10,    10,    10,    10,    10,     4,     4,     4,     4,     4,
       2,     3,     6,     1,     1,     1,     2,     5,     7,    10,
       1,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     4,     6,     6,
       6,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     4,     6,     1,     4,     4,
       4,     4,     4,     4,     4,     2,     5,     5,     5,     5,
       3,     6,     4,     7,     6,     6,     6,     6,     4,     1,
       2,     2,     3,     3,    11,     9,     7,     7,     1,     3,
       1,     1,     2,     3,     4,     5,     1,     1,     2,     3,
       3,     5,     4,     2,     2,     2,     2,     3,     3,     3,
       3,     5,     5,     5,     5,    16,    16,    16,    16,     1,
       1,     3,     3,     4,     6,     6,     1,     1,     3,     3,
       9,     7,     1,     5,     3,     6,     1,     3,     1,     1,
       3,     6,     1,     4,     1,     1,     1,     4,     6,     4,
       6,     4,     4,     4,     8,     4,     4,     4,     4,     8,
       4,     6,     4,     1,     0,     6,     1,     3,     5,     5,
       1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   520,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,     0,     0,   247,   248,     0,     0,     0,
     242,     0,     0,     0,     0,   343,   344,   345,     0,     0,
       5,     7,     6,     8,     9,    10,    20,    11,    12,    13,
      14,    19,    18,    15,    16,    17,     0,    21,   521,     0,
     392,   520,   492,   393,   395,   396,   394,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   494,     0,   513,   496,   400,   401,   402,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     397,   398,   399,   495,     0,     0,     0,     0,    66,    67,
       0,     0,   187,     0,     0,     0,   350,     0,   488,   521,
     407,     0,     0,     0,     0,   227,     0,   229,   230,   225,
     226,     0,   231,   232,   109,   117,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   429,     0,     0,
       0,     0,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   520,     0,   187,   521,     0,     0,   340,
       0,     0,     0,     0,     0,     0,     0,     0,   520,   447,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   469,
     470,   440,   446,     0,   441,   521,   407,     0,     0,     0,
       0,   520,     0,     0,   482,     0,     0,     0,     0,   223,
     224,     0,   520,     0,     0,   240,   241,     0,   187,     0,
     187,   520,     0,     0,   346,     0,     0,    66,    67,     0,
       0,    59,    63,    62,    61,    60,    65,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   353,   352,   354,     0,     0,     0,     0,     0,
       0,     0,   186,     0,   185,     0,    68,    69,     0,     0,
     220,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,   216,     0,     0,
     415,   164,     0,   520,     0,   488,   489,     0,     0,   516,
       0,   107,   107,     0,     0,     0,     0,   476,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   308,   308,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   187,   187,     0,
     431,   430,     0,     0,     0,     0,   187,   187,     0,     0,
       0,     0,     0,     0,     0,   258,     0,   187,     0,     0,
       0,     0,     0,   310,     0,     0,     0,     0,     0,     0,
       0,   205,   341,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,     0,     0,     0,   453,     0,     0,   454,
       0,   455,     0,   456,     0,     0,     0,     0,     0,     0,
     352,   448,     0,   442,     0,     0,     0,   318,    66,    67,
       0,   222,     0,     0,     0,     0,     0,   187,     0,     0,
       0,     0,     0,   244,   243,   210,     0,   211,     0,     0,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   403,   514,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   351,     0,    59,     0,     0,     0,
       0,     0,   182,     0,     0,     0,     0,   188,     0,     0,
      59,     0,     0,   368,   367,   366,   365,   361,   362,   364,
     363,   356,   355,   357,   358,   359,   360,     0,     0,     0,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   337,   338,   339,     0,
       0,     0,     0,   306,     0,     0,     0,   132,   133,     0,
     135,   136,     0,   138,   139,     0,   141,   142,     0,     0,
       0,     0,     0,     0,     0,   152,   187,     0,     0,     0,
       0,     0,   433,   432,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,     0,     0,     0,     0,     0,     0,
       0,   321,     0,     0,   206,     0,     0,   202,     0,     0,
       0,   336,   335,     0,     0,     0,     0,   420,     0,   471,
       0,     0,     0,     0,     0,     0,   457,     0,   458,     0,
     459,     0,   460,     0,     0,   351,   443,   450,     0,   357,
     449,     0,   472,     0,     0,     0,     0,     0,     0,     0,
       0,   245,   246,     0,   212,   214,     0,   522,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    74,     0,   409,
     408,   422,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   391,   379,     0,   381,   382,   383,   384,   385,   386,
     387,     0,     0,     0,   505,     0,   510,   501,   502,   503,
       0,     0,     0,     0,     0,   506,   507,   508,   428,   512,
     121,   126,    99,     0,     0,   497,     0,   499,     0,   405,
     412,   413,   493,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     0,   414,     0,     0,     0,     0,
     518,     0,     0,     0,    44,     0,     0,     0,    57,     0,
      35,    36,    37,    38,    39,   411,   410,     0,   490,    24,
      22,     0,     0,    25,     0,     0,   217,   517,    70,   110,
      71,   118,     0,     0,     0,   478,   479,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   304,   309,   307,     0,   317,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,   215,     0,
       0,     0,   177,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   287,
       0,   249,     0,     0,     0,     0,     0,     0,   311,   320,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     408,     0,   473,     0,   452,     0,     0,     0,     0,     0,
       0,     0,   444,     0,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,     0,     0,   209,     0,     0,   347,
       0,     0,     0,     0,   519,     0,     0,     0,   417,     0,
     416,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,    84,    89,    91,     0,     0,   486,
       0,    97,     0,     0,     0,     0,     0,    75,   369,     0,
       0,     0,     0,     0,    30,   419,   418,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,   315,
       0,     0,   134,     0,   137,     0,   140,     0,   143,     0,
       0,     0,     0,     0,     0,     0,   208,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,     0,   292,     0,
     298,     0,   300,     0,   294,     0,   296,     0,   259,   288,
       0,     0,     0,   200,     0,     0,     0,   322,     0,   204,
     203,   342,     0,     0,    31,    32,     0,     0,     0,     0,
       0,     0,     0,   461,   462,   463,   464,   451,   445,     0,
       0,     0,     0,   483,     0,     0,     0,   235,     0,     0,
       0,     0,     0,    87,     0,    86,     0,    76,   219,   421,
     218,   380,   388,   389,   390,   511,     0,   425,   426,   427,
       0,     0,   404,   122,     0,   515,   127,   424,   498,   500,
     406,    78,    59,     0,     0,     0,     0,    77,     0,     0,
       0,   484,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,     0,     0,    26,    27,     0,    28,     0,     0,
     111,   114,    72,    73,   148,     0,     0,     0,     0,     0,
       0,   151,     0,     0,   167,   168,     0,     0,   153,   174,
       0,     0,     0,     0,   144,     0,   314,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   221,     0,
       0,     0,     0,   187,   187,     0,   269,     0,   271,     0,
     273,     0,   440,     0,     0,   299,   301,   295,   297,     0,
       0,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   421,   474,     0,     0,     0,     0,   475,
     156,   157,     0,     0,     0,     0,   100,   104,     0,     0,
     348,    80,    79,     0,   423,     0,     0,     0,     0,     0,
       0,     0,    94,     0,     0,    95,     0,   487,   189,   190,
     191,   192,     0,     0,    40,     0,     0,     0,     0,     0,
      42,   491,     0,     0,   112,   115,     0,     0,   147,   154,
     155,   159,     0,     0,   169,     0,     0,   316,     0,   162,
       0,     0,   305,   173,   149,   161,   172,   176,   160,     0,
     170,   175,     0,     0,     0,     0,     0,     0,   437,     0,
     436,     0,     0,     0,   260,     0,     0,   261,     0,     0,
     262,     0,     0,     0,     0,     0,     0,     0,   199,     0,
       0,   198,     0,     0,     0,   193,     0,     0,   319,    33,
       0,     0,     0,     0,     0,     0,   481,     0,   237,   236,
       0,     0,     0,     0,     0,   504,   509,     0,   123,   125,
       0,   128,   129,   130,    90,    92,     0,    98,     0,    81,
      45,     0,     0,     0,   439,     0,     0,     0,    29,     0,
     121,   126,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,   312,   312,     0,   105,   106,   187,     0,   180,
     181,     0,     0,     0,     0,     0,     0,     0,   289,     0,
       0,   187,     0,     0,     0,     0,     0,   184,   183,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   102,     0,
      82,     0,   476,     0,     0,   485,     0,    41,     0,     0,
       0,    43,    58,     0,     0,     0,   330,   332,   331,   333,
     334,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   303,     0,     0,     0,   254,
       0,     0,   194,     0,     0,     0,     0,     0,     0,     0,
     480,   238,     0,   349,     0,   124,     0,   131,    96,     0,
       0,     0,     0,     0,   113,   116,     0,     0,     0,     0,
       0,   313,   323,     0,     0,   324,     0,   178,     0,   275,
       0,     0,   277,     0,     0,   279,     0,     0,     0,   290,
       0,   250,     0,   187,     0,     0,     0,     0,     0,     0,
       0,   158,   103,     0,   119,     0,    49,     0,    55,     0,
       0,     0,   145,   171,     0,   327,     0,   328,   329,   434,
     263,     0,     0,   270,   264,     0,     0,   272,   265,     0,
       0,   274,     0,     0,     0,   256,     0,   197,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   281,     0,   283,     0,   285,   291,
     302,   255,   251,     0,     0,     0,     0,     0,     0,     0,
       0,   120,    46,     0,    53,     0,     0,     0,     0,     0,
       0,   266,     0,     0,   267,     0,     0,   268,     0,     0,
     201,     0,   195,     0,     0,     0,     0,     0,    47,     0,
       0,   228,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,     0,     0,   276,     0,   278,     0,   280,     0,
     196,     0,     0,     0,     0,    48,    50,     0,    51,     0,
       0,     0,     0,     0,     0,   465,   466,   467,   468,     0,
       0,    56,   325,   326,   282,   284,   286,    52,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,   941,    91,    92,   687,  1413,  1419,
     930,  1119,  1586,  1787,   931,  1736,  1827,   932,  1789,   933,
     934,  1123,   348,   440,   184,   419,    93,   702,   451,  1530,
    1531,   452,  1581,  1092,  1263,  1093,  1266,   736,   739,   742,
     745,  1441,  1308,   667,   299,   413,   414,    96,    97,    98,
      99,   100,   101,   102,   300,  1022,  1682,  1753,   771,  1465,
    1468,  1471,  1711,  1715,  1719,  1772,  1775,  1778,  1018,  1019,
    1158,   978,   733,   780,  1608,   104,   105,   106,   107,   301,
     186,   890,   501,   257,  1290,   302,   303,   304,   564,   313,
     914,  1110,   449,   445,   891,   450,   189,   306
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1343
static const yytype_int16 yypact[] =
{
    7148,    96,   112,  7268, -1343, -1343,  3752,   119,   -32,   -13,
      62,    36,   154,   199,   263,   296,    94,   308,   318,   169,
     191,  -167,  -167,  -151,   145,   200,    18,   206,   210,    17,
     227,   234,   327,   359,   390,   475,   300,   465,   425,   433,
     598,   452,   511,   691,   256,   354,   513,   -80,   395,   -77,
     -77,   398,   283,    39,   -11,   551,   576,    24,    53,   590,
     583,   290,   688,   696,   709,  5256,   773,   585,   591,   596,
      29,    41, -1343,   604,   623, -1343, -1343,   827,   828,   624,
   -1343,  5337,  5724,    19,    32, -1343, -1343, -1343,  7008,   628,
   -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343,
   -1343, -1343, -1343, -1343, -1343, -1343,    50, -1343,  -125,   123,
   -1343,    13, -1343, -1343, -1343, -1343, -1343,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,   641,   644,   648,   649,   655,   666,  -167,  -167,
    -167,  -167,   678, -1343,  -167, -1343, -1343, -1343, -1343, -1343,
    -167,  -167,   846,   708,   715,   721,  -167,  -167,   733,   736,
   -1343, -1343, -1343, -1343,   686,  7008,  7008,  7008,  7008,  7008,
      21,     9,   207,   690,    79,  1131, -1343,   707,   935,  -102,
     -18,   944,  7008,  5533,  5533, -1343,  7008, -1343, -1343, -1343,
   -1343,  5533, -1343, -1343, -1343, -1343, -1343, -1343,  5920,     9,
    7008,  6818,  7008,  7008,   756,  7008,  6818,  7008,  7008,   757,
    6818,  7008,  7008,  5648,   765,   759, -1343,  6818,  5256,  5256,
    5256,   769,   770,  5256,  5256,  5256,   774,   791,   799,   803,
     813,   824,   831,   835,   785,  3428,   999,  5648,    29,   836,
     841,   -77,   -77,   -77,  7008,  7008,  -104, -1343,   -41,   -77,
     861,   868,   876,  3662,   -37,  -136,   893,   897,   900,  5256,
    5256,  5648,   905,     1,   906, -1343,   907,  1114,  1115, -1343,
     918,   922,   923,  5256,  5256,   931,   932,   934,   536, -1343,
     936,    14,    15,    22,    26,   702,  5844,  7008,  4171, -1343,
   -1343,  2819, -1343,  1126, -1343,   243,   360,  1128,  7008,  7008,
    7008,   -88,  7008,   938, -1343,   997,  7008,  7008,  7008, -1343,
   -1343,  7008,   937,  1139,  1140, -1343, -1343,  1142, -1343,  1143,
   -1343,   285,  8020,  5533, -1343,  5648,  5648,  7008,  7008,   947,
     216,  5920, -1343, -1343, -1343, -1343, -1343, -1343,  5648,  1148,
     956,  7008,  7008,  1152,  7008,  7008,  7008,  7008,  7008,  7008,
    7008,  7008,  7008,  7008,  7008,  7008,  7008,  7008,  7008,  7008,
    7008,  7008,  7008,  7008,  7008,  7008,  5533,  5533,  5533,  5533,
    5533,  5533,  5648,  5533,  5533,  7008,  5533,  5533,  5533,  5533,
    5533,  7008,  5920,  7008,  5533,  5533,  5533,  5533,  5533,     9,
    5920,     9,   963,   963,   963,  9645,  6002,   131,   960,  1156,
    -167,   961, -1343,   977,  5102,  7008, -1343, -1343,  6818,    -4,
   -1343,  7008,  7008,  7008,  7008,  7008,  7008,  7008,  7008,  7008,
    7008,  7008,  7008,  7008,  7008,  7008, -1343, -1343,  7008,  7008,
   -1343, -1343,  1242,   165,   -44, -1343, -1343,    -2,  8127, -1343,
     287,   101,   251,   982,   983,  9666,  6818,  4346, -1343,   -82,
    9687,  9708,  7008,  9729,   -60,  9750,  9771,  7008,   143,  9792,
    9813,  1180,  7008,  7008,   247,  1185,  1192,  1204,  7008,  7008,
    1208,  1209,  1209,  7008,  6628,  6628,  6628,  6628,  7008,  7008,
    7008,  6818,  6818,  8047,  1013,  1216,  1019, -1343, -1343,   -48,
   -1343, -1343,  8153,  8179,   -77,   -77,   207,   207,   -39,  7008,
    7008,  7008,  3662,  3662,  7008,  5102,   -35, -1343,  7008,  7008,
    7008,  7008,  7008,  1220,  1224,  1225,  7008,  1227,  7008,  7008,
    1452, -1343, -1343,  6818,  6818,  6818,  1228,  1229,  7008,  7008,
    7008,  7008,  7008,  1233,   364,     9, -1343,  1186,  7008, -1343,
    1187, -1343,  1189, -1343,  1190,    33,    35,    42,    44,  6818,
     963, -1343,  9834, -1343,   270,  7008,  6040, -1343,  7008,  7008,
     426, -1343,  9855,  9876,  9897,  1105,  8205, -1343,  1042,  4366,
    9918,  9939,  9323, -1343, -1343, -1343,  1489, -1343,  1583,  7008,
   -1343,  1047,  1051,   319,  9960,  9346,  7008,  6818,    -4,  1248,
    1249, -1343,  7008,  9981,  9369,    70,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  8231,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  8257,  8283,  8309,    89,   587,
      89,  1064,  1065,  1061,  1062,  1063,  1067,  8335,   367,   367,
     367,   400,   367, 10443, -1343,  1300,  1068,  1069,  1075,   602,
     609,  1076,  1078,  1079,   302,    81,  5920,  7008,  1272,  1277,
      25,   367, -1343,    -9,    37,    31,   150, -1343,  6524,   386,
   -1343,  5648,  4550,  2083,   534,   987,   987,   370,   370,   370,
     370,   138,   138,   963,   963,   963,   963,     4, 10002,  9392,
   -1343,  7008,  1278,     3,  6818,  1279,  6818,  7008,  1280,  5533,
    1282, -1343,     9,  1283,  5533,  7008,  5920,  1284,  6818,  6818,
    1141,  1287,  1288, 10023,  1290,  1147,  1291,  1293, 10044,  1158,
    1295,  1297,  7008, 10065,  6552,  1104, -1343, -1343, -1343, 10086,
   10107,  7008,  5648,  1319,  1318, 10128,  1127, 10443,  1123,  1130,
   10443,  1133,  1137, 10443,  1135,  1144, 10443,  1136, 10149, 10170,
   10191,   481,   504,  6818,  1129, -1343, -1343,  1745,  1921,   -77,
    7008,  7008, -1343, -1343,  1124,  1138,  3662,  8361,  8387,  8413,
    8101,   -33,   -77,  2141, 10212,  6585, 10233, 10254, 10275,  7008,
    1325, -1343,  7008, 10296, -1343,  9415,  9438, -1343,   523,   529,
     533, -1343, -1343,  9461,  9484,  8439,  9507,   360,  6818, -1343,
    1149,  1150,  6756,  1151,  1154,  1155, -1343,  6818, -1343,  6818,
   -1343,  6818, -1343,  6818,   586, -1343, -1343,  4962,  6818,   963,
   -1343,  6818, -1343,  1333,  1334,  1337,  1160,  7008,  2317,  7008,
    7008, -1343, -1343,    51, -1343, -1343,  2407, -1343,  1159,  5648,
    1342,   302,   302,  6903,   594,  5648, -1343, -1343,  9530,   360,
    1066, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343,
   -1343, -1343, -1343,  7008, -1343, -1343, -1343, -1343, -1343, -1343,
   -1343,  7008,  7008,  7008, -1343,  6818, -1343, -1343, -1343, -1343,
    5533,  5648,  5533,  5533,  5920, -1343, -1343, -1343, -1343, -1343,
   -1343, -1343, -1343,  7008,  5533, -1343,  5533, -1343,  7008, -1343,
   -1343, -1343, -1343,  7008,  1346,    40,  7008,  1347,  1350,  1949,
   -1343,  1361,  1170,    29,  1364, -1343,  6818,  6818,  6818,  6818,
   -1343,   367,  1369,  7008, -1343,  1179,  1183,  1173, -1343,  1375,
   -1343, -1343, -1343, -1343, -1343,   360,   360,  9553, -1343, -1343,
    1198,  5533,   456, -1343,   548,  8465, -1343, -1343, -1343,  1376,
   -1343, -1343,  1525,   367,   -77,  4346, -1343,   735,  5648,  5648,
    1377,  5648,   755,  5648,  5648,  1378,  1303,  5648,  5648,  2107,
    1381,  1382,  6818,  1384,  1385,  5982, -1343, -1343,  1387, -1343,
    1390,    -4,  7008,    -4,  7008,    -4,  7008,    -4,  7008,  1391,
    1393,  1394,  1396,  1397,   656,  1404,  2485, -1343, -1343,    75,
    8491,  8517, -1343, -1343,  6931,   -79,   -77,   -77,   -77,  1405,
    1406,  1206,  1407,  1214,     5,    28,    46,    57,   526, -1343,
      85, -1343,   -33,  1408,  1410,  1412,  1427,  1429, 10443, -1343,
    2251,  1213,  1434,  1436,  1437,  1362,  1438,  1440,  1441,  7008,
     166,   665, -1343,  7008, -1343,  7008,  7008,  7008,   671,   681,
     693,   698, -1343,  7008,   699,   703,  5648,  5648,  5648,  1444,
    8543, -1343,  4981,   795,  1445,  1446, -1343,  5648,  1246, -1343,
    7008,  1447,  7008,  1448, -1343,   367,  1451,  1454, -1343,  1457,
   -1343,  1456,  1525,  1525,  1525,  1525,   613,  1260,  1268,  1269,
    1270,  1266,   632,   697, 10317,  1274,   367,  1525,  2522, -1343,
     351,  1273,  1463,  2800, -1343, -1343, -1343,    29,  7008, -1343,
     704, -1343,   714,   718,   719,   722,    -4, -1343, 10443,  1276,
    7008,  7008,  5648,  1271, -1343, -1343, -1343,  1292, -1343,  1471,
      20,  1486,  7008,  4799,  1488,  1494,     6,  1294,  1299,  1403,
    1403,  5648,  1499,  1302,  1304,  1503,  1505,  5648,  1308,  1508,
    1509, -1343,  1511,  5648,   723,  5648,  5648,  1513,  1515, -1343,
    5648,  5648, 10443,  5648, 10443,  5648, 10443,  5648, 10443,  5648,
    5648,  5648,  1336,  1338,  1516,   636, -1343,  7008,  7008,  7008,
    1339,  1348,  -123,   -89,   -81,  1351, -1343,  5648, -1343,  7008,
   -1343,  1540, -1343,  1545, -1343,  1549, -1343,  1550, -1343, -1343,
    3662,   730,  5452, -1343,  1354,  1356,  6236, -1343,  6818, -1343,
   -1343, -1343,  1357,  7008, -1343, -1343,  9576,  1559,   367,  8569,
    8595,  8621,  8647, -1343, -1343, -1343, -1343, 10443, -1343,   367,
    1558,  1569,  1439, -1343,  7008,  7008,  7008, -1343,  1571,   738,
    1380,  1573,  2855, -1343,  3149, -1343,    -4, -1343, -1343,    90,
   -1343, -1343, -1343, -1343, -1343, -1343,  5533, -1343, -1343, -1343,
    5920,  1576, -1343, -1343,    12, -1343, -1343, -1343, -1343, -1343,
   -1343, -1343,  5920,  7008,  1586,  1589,    25, -1343,  1588,  9599,
      29, -1343,  1591,  1592,  1593,  1594,  5648,  7008,  8673,  8699,
     731, -1343,  7008,  1597, -1343, -1343,  5533, -1343,  8725,  4407,
   10443, -1343, -1343, -1343, -1343,  7008,  7008,   -77,  1600,  1601,
    1602, -1343,  7008,  7008, -1343, -1343,  1603,  7008, -1343, -1343,
    1598,  1607,  1411,  1608,  1477,  7008, -1343,  1615,  1616,  1621,
    1622,  1623,  1624,   933,  1625,  6818,  6818,  7008, -1343,  6628,
    7264, 10338,  3375,   207,   207,   -77,  1627,   -77,  1628,   -77,
    1629,  7008,   278,  1433, 10359, -1343, -1343, -1343, -1343,  7292,
     133, -1343,  1631,  3963,  1633,  5648,   -77,  3963,  1634,   737,
    7008,  3182,  1636,   360, -1343,  7008,  7008,  7008,  7008, -1343,
   -1343, -1343,  5648,  6174,   578, 10380, -1343, -1343,  4864,  5648,
   -1343, -1343, -1343,  5648, -1343,  1450,   367,  4603,  5060,  5920,
    1638,  3201, -1343,  1639,  1643, -1343,  1449, -1343, -1343, -1343,
   -1343, -1343,  1645,   549, 10443,  7008,  7008,  5648,  1465,   743,
   10443, -1343,  1646,  7008, -1343, -1343,  7320,  7348,   567, -1343,
   -1343, -1343,  7376,  7404, -1343,  7432,  1648, -1343,  5648, -1343,
    1605,  1650, 10443, -1343, -1343, -1343, -1343, -1343, -1343,  1467,
   -1343, -1343,   744,   754,  8074,  3563,  1666,  1469, -1343,  7008,
   -1343,  1472,  1481,   153, -1343,  1470,   201, -1343,  1478,   214,
   -1343,  1483,  9622,  1682,  5648,  1683,  1485,  7008, -1343,  6432,
     218, -1343,   789,   222,   224, -1343,  1685,  7460, -1343, -1343,
    8751,  8777,  8803,  8829,  1554,  7008, -1343,  7008, -1343, -1343,
    6818,  3693,  1687,  1490,  1693, -1343, -1343,  4171, -1343, -1343,
    5533, 10443, -1343, -1343, -1343, -1343,    29, -1343,  1560, -1343,
   -1343,  7008,  8855,  8881, -1343,  5648,  7008,  1694, -1343,  8907,
   -1343, -1343,  1711,  1716,  1718,  1720,  1721,  1727,   792,  1530,
   -1343,  5648,   531,   599,  6818, -1343, -1343,   207,  6370, -1343,
   -1343,  3662,   -33,  3662,   -33,  3662,   -33,  1729, -1343,   796,
    5648, -1343,  7488,   -77,  1730,  6818,   -77, -1343, -1343,  7008,
    7008,  7008,  7008,  7008,  7516,  7544,   806, -1343, -1343,  1731,
   -1343,   814,  4202,   817,  1732, -1343,  1535, 10443,  7008,  7008,
     821, 10443, -1343,  7008,   822,   826, -1343, -1343, -1343, -1343,
   -1343, -1343,  1536,  7008,   833,  1537,   -77,  5648,  1737,  1542,
     -77,  1738,   834,  1543,  7008, -1343,  7572,   231,   763,  7600,
     235,   888,  7628,   346,   924, -1343,  5648,  1741,  1651,  2562,
    1552,   350, -1343,   853,   413,  8933,  8959,  8985,  9011,  3901,
   -1343, -1343,  1747, -1343,  7008, -1343,  5920, -1343, -1343,  7008,
   10401,  9037,    45,  9063, -1343, -1343,  7008,  7656,  1748,   -77,
      63, -1343, -1343,   -77,    73, -1343,  1753, -1343,  7684,  1755,
    7008,  1756,  1761,  7008,  1766,  1770,  7008,  1771,  1574, -1343,
    7008, -1343,   -33, -1343,  6818,  1775,  6432,  7008,  7008,  7008,
    7008, -1343, -1343,   392, -1343,   854, -1343,  7008, -1343,  5648,
    7008,  9089, -1343, -1343,   444, -1343,   484, -1343, -1343, -1343,
   -1343,  1578,  7712, -1343, -1343,  1579,  7740, -1343, -1343,  1580,
    7768, -1343,  1779,  4117,   942,  2667,   870, -1343,   487,   873,
    9115,  9141,  9167,  9193,  5920,  1780,  1585, 10422,   874,  7796,
    7008,   -77,   -77,   -33,  1784,   -33,  1785,   -33,  1786, -1343,
   -1343, -1343, -1343,   -33,  1787,  6818,  1788,  7008,  7008,  7008,
    7008, -1343, -1343,  5533, -1343,  1595,  1789,  7824,   501,   507,
    1070, -1343,  1596,  1082, -1343,  1599,  1094, -1343,  1606,  1132,
   -1343,   883, -1343,  9219,  9245,  9271,  9297,   884, -1343,  1609,
    5648, -1343,  1790,  7008,  7008,  1791,   -33,  1795,   -33,  1796,
     -33, -1343,  1799,  7008,  7008,  7008,  7008,  5533,  1803,  5533,
     898, -1343,  7852,  7880, -1343,  1247, -1343,  1400, -1343,  1492,
   -1343,  7908,  7936,  7964,  7992, -1343, -1343,   909, -1343,  1805,
    1808,  1809,  1811,  1812,  1813, -1343, -1343, -1343, -1343,  5533,
    1814, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1343, -1343, -1343, -1343,   701, -1343, -1343, -1343, -1343,   186,
   -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343,
   -1343, -1343,  -302,   -70,  2048,    -1, -1343,  1392, -1343, -1343,
   -1343, -1343, -1343,   309, -1343,   312, -1343, -1343, -1343, -1343,
   -1343, -1343,   705,  1844,     7,  -500,  -227, -1343, -1343, -1343,
   -1343, -1343, -1343, -1343,  1845, -1343, -1343, -1343, -1343, -1343,
   -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1004,  -948,
   -1343, -1343,  1370, -1343,   310, -1343, -1343, -1343, -1343,  1553,
   -1343, -1343,    92, -1343, -1342,  2114,   428,  2598,  2729,  -247,
     579, -1343,    49,     8, -1343,  -374,    -3,   122
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -492
static const yytype_int16 yytable[] =
{
     108,   496,   628,   670,   630,   527,   764,   765,   924,   939,
      95,  1190,  1304,   322,   188,   641,  1398,   350,  1201,   546,
     549,   219,   214,  1482,   327,   407,  1295,   551,   273,   912,
     206,   553,   207,   311,  1192,   219,   515,   329,   806,   349,
     808,   214,   195,   265,  1100,   315,   210,   810,   530,   812,
     192,  1698,  1194,   211,   276,   187,   334,   278,  1064,   279,
     248,   518,   305,  1196,   504,   505,  1009,   276,   519,  1705,
    1199,   269,   337,   270,   338,   249,   250,  1010,   276,  1707,
    1345,   339,  1346,   504,   505,  1011,  1012,  1013,   670,   323,
     326,  1014,  1015,  1016,  1017,   438,  1538,   439,   504,   505,
     506,   586,     4,   588,   339,   657,   504,   505,   504,   505,
     252,   253,     5,   575,  1347,   266,  1348,   671,   183,   267,
     254,   709,  1349,   710,  1350,   109,  1181,   255,   190,   280,
     341,   268,   191,  1191,   925,   926,   927,   928,   656,   504,
     505,   256,   258,   709,   264,   715,   504,   505,   504,   505,
     504,   505,   504,   505,   693,   759,  1193,   547,   550,   694,
     197,   408,   409,   507,   766,   552,  1399,   517,   772,   554,
     342,   343,   344,   345,  1195,   274,   346,   347,   276,   277,
    1101,  1102,    89,  1590,   193,  1197,  -489,   940,   210,   412,
     276,   276,   314,   504,   505,   916,   695,    89,   276,  1604,
     528,   696,    89,   324,   940,   198,   276,   183,   305,   929,
     351,   411,   352,   305,   353,   215,   453,   305,   548,   183,
     305,   220,   216,   328,   305,   305,   305,   305,   275,   913,
     305,   305,   305,   312,   215,   918,   330,   807,   316,   809,
     196,   917,   444,   447,   305,   276,   811,   335,   813,  1699,
     504,   505,  1065,  1199,   336,   342,   343,   344,   345,   194,
     504,   505,   504,   505,   346,   347,   305,   305,   305,   199,
     757,   758,   504,   505,  -490,   346,   347,   416,  1177,   417,
     305,   305,   905,   418,   346,   347,   565,   416,  1200,   417,
     773,   201,   699,   305,  -491,   305,   845,   342,   343,   344,
     345,   700,   200,   410,   701,   342,   343,   344,   345,   670,
      48,    49,    50,    51,   202,   446,   446,   346,   347,    56,
     504,   505,    59,   446,   203,   346,   347,   432,   433,   434,
     276,   454,   305,   305,   435,   244,  1477,   658,   245,   598,
     504,   505,   212,   499,   500,   305,   709,   222,   719,   599,
     828,   508,   903,   906,   919,   516,  1551,  1738,  1272,   260,
     346,   347,   261,   836,   691,   262,   692,  1217,   204,   283,
     314,   183,   284,   276,   276,   276,   276,   276,   276,   305,
     276,   276,   591,   276,   276,   276,   276,   276,   504,   505,
     205,   276,   276,   276,   276,   276,   276,   213,   276,  1734,
     644,   504,   505,   217,  1553,   504,   505,   218,   652,   504,
     505,   504,   505,   223,   416,   305,   417,  1555,   504,   505,
     597,  1563,   504,   505,   221,  1565,   629,  1566,   631,   632,
     633,   222,   635,   636,  1670,   638,   639,   640,  1673,   642,
     568,   224,   569,   646,   647,   648,   649,   650,  1810,   339,
     709,   703,   725,   305,   701,   446,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   566,   433,   434,
     252,   253,   225,   709,   435,   816,   342,   343,   344,   345,
     254,   226,   351,  1473,   589,   698,   543,   263,   305,   305,
     699,   183,   738,   741,   744,   747,   346,   347,   446,   446,
     446,   446,   446,   446,   227,   446,   446,   231,   446,   446,
     446,   446,   446,   412,   412,   232,   446,   446,   446,   446,
     446,   651,   839,   653,   840,   342,   343,   344,   345,   996,
     305,   305,   305,   504,   505,   851,   236,   504,   505,  1070,
    1072,   228,   276,   799,   229,   346,   347,   230,  1618,  1676,
    1621,   246,  1624,  1684,   346,   347,   305,   430,   431,   432,
     433,   434,   416,   305,   417,   416,   435,   417,   798,   822,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   904,   907,  1497,   237,   435,   709,
     238,   921,   247,   239,   305,   240,   762,   763,   888,   251,
     504,   505,   259,   699,   500,   852,   853,   854,   855,   856,
     857,   858,   859,   860,   861,   862,  1686,   864,   865,   866,
     867,   868,   869,   870,   416,  1009,   417,   874,   876,   877,
     821,   504,   505,   271,  1605,  1606,  1010,   885,   886,   887,
    1607,   889,  1338,  1339,  1011,  1012,  1013,  1741,   897,   899,
    1014,  1015,  1016,  1017,  1130,   272,   475,   476,   477,   709,
     915,   480,   481,   482,   908,   282,  1109,   800,   305,   281,
    1199,   504,   505,  1199,   504,   505,  1199,   233,  1724,  1161,
     234,  1163,   235,  1165,   709,  1167,   992,  1742,   504,   505,
    1755,   305,   285,   305,   504,   505,   276,   523,   524,   276,
     286,   276,  1609,  1610,  1793,   305,   305,   709,  1607,   993,
    1794,   536,   537,   287,   953,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   709,   851,  1034,   305,
     435,  1198,   709,   541,  1035,   542,   709,   543,  1036,  1770,
     182,  1773,   183,  1776,  1387,  1388,  1131,  1520,   947,  1779,
     305,   709,  1521,   951,   504,   505,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     241,  1071,  1073,   242,   435,   243,  1199,   307,   555,  1078,
    1080,   556,   308,  1498,   557,   416,   558,   417,   309,   709,
     875,  1052,  1815,   310,  1817,   305,  1819,   709,  1273,  1075,
     416,   317,   417,  1236,   305,   896,   305,   416,   305,   417,
     305,   416,   898,   417,  1286,   305,   709,  1137,   305,  1138,
     318,   446,  1199,   321,   949,  1199,   446,   333,  1199,  1009,
     416,  1199,   417,   319,   320,  1261,   305,  1143,   379,  1144,
    1010,   380,   305,  1461,  1462,   381,   382,   276,  1011,  1012,
    1013,   999,   383,   393,  1014,  1015,  1016,  1017,  1005,   709,
    1278,  1174,  1009,   384,  1020,  1125,  1126,  1199,   709,  1199,
    1218,  1199,   305,  1010,   709,   389,  1223,   276,   305,   276,
     276,  1011,  1012,  1013,   709,   401,  1224,  1014,  1015,  1016,
    1017,   276,  1091,   276,   415,   416,   709,   417,  1225,  1081,
    1264,   709,   709,  1226,  1228,   394,   709,  1280,  1229,  1281,
     276,   436,   395,   305,   305,   305,   305,   709,   396,  1282,
    1116,   709,   709,  1283,  1284,   709,   709,  1285,  1322,  1087,
     399,  1089,  1090,   400,  1417,  1361,  1418,  1449,   276,  1450,
     709,   437,  1486,  1095,  1393,  1096,  1526,   709,  1527,  1542,
     441,  1134,  1135,   462,   467,   305,   305,   709,   305,  1543,
     305,   305,   472,   473,   305,   305,   478,   479,  1671,   305,
    1080,   483,   446,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,  1009,   484,   491,
    1129,   435,  1417,  1237,  1564,  1417,   485,  1602,  1010,  1626,
     486,  1627,   446,   494,   446,   446,  1011,  1012,  1013,   709,
     487,  1642,  1014,  1015,  1016,  1017,   446,  1644,   446,  1645,
     699,   488,  1647,  1009,  1417,  1261,  1652,  1654,   489,  1264,
    1274,  1655,   490,  1407,  1010,   314,  1417,   709,  1658,  1666,
     497,  1009,  1011,  1012,  1013,   498,  1136,  1613,  1014,  1015,
    1016,  1017,  1010,   305,   305,   305,   709,  1526,  1685,  1735,
    1011,  1012,  1013,   446,   305,   509,  1014,  1015,  1016,  1017,
     443,   112,   510,   709,  1246,  1754,   709,  1417,  1756,  1765,
     511,  1251,  1252,  1253,  1254,  1255,   709,  1807,  1802,  1808,
     520,  1262,  1265,  1674,   521,  1269,  1270,   522,  1182,  1183,
    1184,  1417,   526,  1829,   276,   529,   139,   140,   141,   142,
     143,   144,  1839,   339,  1840,   148,   149,   150,   151,   305,
     531,   532,   533,   153,   154,   155,   534,   535,   156,  1677,
     538,   539,   567,   540,   571,   545,  1583,   420,   305,   161,
     578,  1301,   577,   183,   305,   583,   584,  1751,   585,   587,
     305,   596,   305,   305,   601,   602,   605,   305,   305,   435,
     305,   659,   305,   660,   305,   182,   305,   305,   305,  1009,
     426,   427,   428,   429,   430,   431,   432,   433,   434,  1394,
    1010,  1009,   662,   435,   305,   705,   706,   722,  1011,  1012,
    1013,   726,  1010,  1009,  1014,  1015,  1016,  1017,   727,   305,
    1011,  1012,  1013,   305,  1010,   305,  1014,  1015,  1016,  1017,
     728,   754,  1011,  1012,  1013,   731,   732,  1374,  1014,  1015,
    1016,  1017,   755,   756,   164,   165,   166,   779,  1379,   314,
     781,  1009,   782,   784,   791,   792,   173,   797,   174,    89,
     801,   803,  1010,   804,   805,   826,   829,   837,   690,   838,
    1011,  1012,  1013,   276,   846,   847,  1014,  1015,  1016,  1017,
     346,   347,   878,   879,   880,   881,   882,  1079,  1396,  1584,
     883,   893,   894,   895,   900,  1795,   901,   276,   910,   902,
    1400,   911,   938,   305,   957,   943,   946,  1797,   948,   950,
     962,   954,  1360,   276,   958,   959,   305,   961,   963,  1799,
     964,   966,   967,  1394,   968,  1395,   892,  1425,   972,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   977,   979,   981,   982,   435,   983,  1002,
     995,  1029,   305,   305,  1629,   985,   984,  1801,   986,   988,
    1056,  1057,   987,  1003,  1058,  1422,  1009,  1456,  1069,  1042,
     412,   412,  1099,  1104,  1043,  1045,  1105,  1010,  1046,  1047,
     305,  1059,   305,  1067,   305,  1011,  1012,  1013,  1107,  1108,
    1111,  1014,  1015,  1016,  1017,  1117,  1120,  1122,   446,   305,
    1121,  1124,  1128,  1133,  1141,  1147,   305,  1148,  1152,  1153,
     305,  1155,  1156,  1159,   305,  1506,  1502,  1160,  1169,  1428,
    1170,  1171,   314,  1172,  1173,  1509,  1512,  1513,  1175,  1185,
    1187,  1189,  1186,  1188,   305,  1202,  1203,  1208,   446,  1204,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,  1205,   305,  1206,  1463,   435,  1466,
    1209,  1469,  1210,  1211,  1212,  1213,  1214,  1215,  1233,  1238,
    1239,  1241,  1832,  1243,  1245,  1480,  1725,  1247,  1483,  1484,
    1248,  1249,  1250,  1256,     7,     8,  1257,  1258,  1259,  1260,
    1276,   305,  1268,  1287,  1275,  1292,   305,  1294,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,  1297,  1293,  1302,  1307,   435,   305,  1305,  1009,
    1303,     7,     8,  1306,   305,  1311,  1312,   276,  1313,  1314,
    1010,  1315,  1317,   276,  1318,  1319,  1320,  1325,  1011,  1012,
    1013,  1326,   305,  1337,  1014,  1015,  1016,  1017,   663,    24,
      25,   664,    27,    28,   665,    30,   666,    32,   305,    33,
    1335,   305,  1336,  1343,    38,    39,  1355,    41,    42,    43,
    1351,  1356,  1344,    46,   412,  1357,  1358,   305,  1365,   185,
    1366,  1370,   305,  1373,  1380,   663,    24,    25,   664,    27,
      28,   665,    30,   666,    32,  1381,    33,  1386,  1382,  1390,
    1397,    38,    39,  1389,    41,    42,    43,    67,    68,    69,
      46,  1009,  1402,  1403,  1405,     7,     8,  1408,  1409,  1410,
    1411,  1421,  1010,  1436,   305,  1833,  1429,  1430,  1431,  1434,
    1011,  1012,  1013,  1437,  1439,  1438,  1014,  1015,  1016,  1017,
    1440,  1443,  1444,   305,    67,    68,    69,  1445,  1446,  1447,
    1448,  1451,   446,  1464,  1467,  1470,  1474,  1478,   314,  1481,
    1485,   332,  1489,  1617,  1514,  1620,  1516,  1623,  1505,  1517,
    1518,  1519,  1528,  1537,  1694,  1631,  1540,   787,  1634,   663,
      24,    25,   664,    27,    28,   665,    30,   666,    32,  1525,
      33,  1541,  1546,  1547,  1552,    38,    39,  1549,    41,    42,
      43,   305,  1554,   305,    46,  1539,  1550,  1556,  1558,  1561,
    1560,  1567,  1573,  1578,   834,  1579,   305,  1834,  1660,  1580,
    1592,  1585,  1664,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,  1596,    67,    68,
      69,   435,  1597,   416,  1598,   417,  1599,  1600,   402,   403,
     404,   405,   406,  1601,  1603,  1625,  1632,  1643,  1648,  1649,
    1656,  1659,  1761,  1662,  1665,   442,  1663,  1679,  1667,   448,
    1680,  1704,   305,  1692,  1703,  1706,  1683,     7,     8,  1708,
     276,  1710,  1713,   455,   457,   460,   461,  1714,   463,   457,
     465,   466,  1717,   457,   469,   470,  1718,  1721,  1728,  1722,
     457,  1727,  1743,  1745,  1747,  1749,  1762,   305,   835,  1763,
    1771,  1774,  1777,  1780,  1782,  1791,  1811,  1814,   493,  1790,
    1796,  1816,  1818,  1798,   276,  1820,   276,   502,   503,  1826,
    1800,  1841,  1788,  1809,  1842,  1843,   503,  1844,  1845,  1846,
    1848,   663,    24,    25,   664,    27,    28,   665,    30,   666,
      32,  1296,    33,  1768,  1769,  1695,   276,    38,    39,  1594,
      41,    42,    43,  1595,   704,  1309,    46,    94,   103,   560,
     562,   457,   734,  1611,     0,  1404,  1825,     0,  1828,     0,
       0,   572,   573,   574,     0,   576,     0,     0,     0,   579,
     580,   581,     0,     0,   582,     0,     0,     0,     0,     0,
      67,    68,    69,     0,     0,   446,     0,     0,  1847,     0,
     594,   595,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   603,   604,     0,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   446,
       0,   446,     0,     7,     8,     0,     0,     0,   637,     0,
       0,     0,     0,     0,   643,     0,   645,     0,     0,     0,
     997,     0,     0,     0,     0,  1106,     0,     0,     0,     0,
       0,   446,     0,     0,     0,     0,     0,     0,   668,     0,
       0,   457,     0,     0,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,   682,   683,   684,   685,   686,     0,
       0,   688,   689,     0,     0,     0,     0,   663,    24,    25,
     664,    27,    28,   665,    30,   666,    32,     0,    33,   560,
       0,     0,     0,    38,    39,   713,    41,    42,    43,     0,
     718,     0,    46,     0,     0,   723,   724,     0,     0,     0,
       0,   729,   730,     0,     0,     0,   735,   737,   740,   743,
     746,   748,   749,   750,   457,   457,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,   767,   768,   769,   402,   403,   770,     0,   208,
     209,   774,   775,   776,   777,   778,     0,     0,     0,   783,
       0,   785,   786,     0,     0,     0,   457,   457,   457,     0,
       0,   793,   794,   795,   603,   796,     0,     0,     0,     0,
       0,   802,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   457,  1151,     0,     0,     0,     0,   817,   819,
       0,   688,   689,     0,     0,     0,   998,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,   796,     0,     0,   435,     0,     0,     0,   843,
     457,     0,     0,     7,     8,   848,   340,     0,     0,     0,
       0,     0,     0,     0,     0,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,     0,     0,     0,     0,   385,   386,   387,   388,
       0,     0,   390,     0,     0,     0,     0,     0,   391,   392,
     909,     0,     0,     0,   397,   398,     0,   663,    24,    25,
     664,    27,    28,   665,    30,   666,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,   937,     0,     0,   457,     0,   457,
     945,     0,     0,     0,     0,     0,     0,  1207,   952,     0,
       0,   819,   955,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   969,    67,    68,    69,   435,
       0,     0,     0,     0,   975,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,   457,     0,     0,     0,
       0,     0,     0,  1000,  1001,     0,     0,     0,     0,  1004,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,  1028,     0,     0,  1030,   544,   471,     0,     0,
       0,     0,     0,     0,     0,     0,  1021,     0,     0,     0,
       0,   457,     0,   570,     0,     0,     0,     0,     0,     0,
     457,   495,   457,     0,   457,     0,   457,     0,     0,     0,
       0,   457,     0,     0,   457,     0,     0,     0,     0,     0,
    1060,     0,  1062,  1063,     0,   525,     0,     0,     0,     0,
       0,     0,     0,   663,    24,    25,   664,    27,    28,   665,
      30,   666,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,  1082,     0,    46,     7,
       8,     0,     0,     0,  1083,  1084,  1085,     0,   457,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,  1094,   435,     0,   592,
     593,  1097,    67,    68,    69,     0,  1098,     0,   661,  1103,
       0,     0,   600,     0,     0,     0,     0,     0,     0,   457,
     457,   457,   457,     0,     0,     0,  1118,     0,     0,     0,
       0,     0,     0,   663,    24,    25,   664,    27,    28,   665,
      30,   666,    32,     0,    33,     0,   634,     7,     8,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1061,     0,     0,   457,     0,     0,  1271,     0,
       0,     0,     0,     0,     0,  1162,     0,  1164,     0,  1166,
       0,  1168,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   663,    24,    25,   664,    27,    28,   665,    30,   666,
      32,     0,    33,     0,     7,     8,     0,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,     0,     0,
       0,     0,  1216,     0,     0,     0,  1219,     0,  1220,  1221,
    1222,     0,     0,     0,     0,     0,  1227,     0,     0,     0,
       0,     0,  1066,     0,     0,     0,     0,     0,     0,     0,
      67,    68,    69,  1242,     0,  1244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   663,    24,
      25,   664,    27,    28,   665,    30,   666,    32,     0,    33,
       0,     0,     0,     0,    38,    39,     0,    41,    42,    43,
       0,  1279,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1288,  1289,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,  1298,  1300,     0,     0,     0,
    1176,     0,     0,     0,     0,     0,     0,    67,    68,    69,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1340,  1341,  1342,     0,     0,     0,     0,     0,     0,     0,
    1352,     0,  1354,   663,    24,    25,   664,    27,    28,   665,
      30,   666,    32,  1359,    33,     0,     0,     0,     0,    38,
      39,   457,    41,    42,    43,     0,  1371,  1681,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   922,     0,  1383,  1384,  1385,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,  1277,     0,     0,   458,
       0,     0,     0,     0,   458,     0,     0,     0,   458,     0,
       0,     0,     0,     0,     0,   458,  1401,   565,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1414,     0,     0,     0,     0,  1420,   976,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1426,  1427,
       0,  1391,     0,     0,     0,  1432,  1433,     0,     0,     0,
    1435,     0,  1752,     0,     0,     0,     0,     0,  1442,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   457,   457,
    1454,     0,  1455,     0,   561,     0,   458,     0,     0,     0,
       0,     0,     0,     0,  1472,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   457,     0,     0,     0,
     457,     0,     0,  1487,     0,     0,     0,     0,  1490,  1491,
    1492,  1493,     0,     0,     0,     0,     0,     0,     0,     0,
     459,  1501,     0,     0,     0,   464,     0,     0,     0,   468,
       0,  1511,     0,  1068,     0,     0,   474,     0,     0,  1076,
       0,     0,     0,     0,     0,     0,     0,     0,  1522,  1523,
       0,     0,     0,     0,     0,     0,  1529,     0,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,  1088,   435,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   566,   433,
     434,     0,  1548,     0,     0,   435,   458,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1562,     0,   560,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,  1574,     0,
    1575,   435,     0,   457,   561,     0,     0,     0,     0,     0,
    1582,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1139,  1140,  1587,  1142,     0,  1145,  1146,  1591,
       0,  1149,  1150,     0,     0,     0,     0,     0,     0,   458,
     458,     0,     0,     0,     0,     0,     0,   457,     0,     0,
       0,     0,     0,     0,  1616,     0,  1619,     0,  1622,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   457,     0,
       0,     0,  1635,  1636,  1637,  1638,  1639,     0,     0,     0,
       0,   458,   458,   458,     0,     0,     0,     0,     0,     0,
       0,  1650,  1651,     0,     0,     0,  1653,   669,     0,     0,
       0,     0,     0,     0,     0,  1392,  1657,   458,     0,     0,
       0,     0,     0,     0,   820,     0,     0,  1668,     0,     0,
    1230,  1231,  1232,     0,     0,     0,     0,     0,     0,     0,
       0,  1240,     0,     0,     0,     0,     0,     0,  1488,     0,
       0,     0,     0,     0,     0,   458,     0,  1693,     0,     0,
       0,     0,  1420,     0,     0,     0,     0,  1515,     0,  1701,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     751,   752,     0,  1712,     0,     0,  1716,     0,     0,  1720,
       0,     0,     0,  1723,     0,     0,  1291,   457,     0,   457,
    1730,  1731,  1732,  1733,     0,     0,     0,     0,     0,     0,
    1737,     0,     0,  1739,     0,  1310,     0,     0,     0,     0,
       0,  1316,   788,   789,   790,     0,     0,  1321,     0,  1323,
    1324,     0,     0,     0,  1327,  1328,     0,  1329,     0,  1330,
       0,  1331,     0,  1332,  1333,  1334,     0,     0,   814,     0,
       0,     0,   458,  1767,   458,     0,     0,     0,     0,     0,
       0,  1353,     0,     0,     0,     0,   820,   956,   457,     0,
    1783,  1784,  1785,  1786,     0,     0,  1364,     0,     0,     0,
    1368,     0,     0,     0,     0,     0,   844,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,  1812,  1813,     0,     0,
       0,   458,     0,     0,     0,     0,  1821,  1822,  1823,  1824,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,   458,   435,     0,     0,
    1412,     0,     0,     0,     0,   458,     0,   458,     0,   458,
       0,   458,     0,  1424,     0,     0,   458,     0,     0,   458,
       0,     0,     0,   942,     0,   944,     0,     0,     0,     0,
       0,   110,   331,     0,     0,     0,     0,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,     0,     0,
       0,     0,     0,   458,   145,   146,   147,     0,     0,  1291,
       0,   152,   994,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,     0,  1494,     0,     0,     0,
     160,     0,     0,  1503,     0,     0,     0,  1504,     0,     0,
       0,  1508,     0,     0,   458,   458,   458,   458,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1041,     0,     0,
       0,  1524,     0,     0,     0,     0,  1048,     0,  1049,     0,
    1050,     0,  1051,     0,     0,     0,     0,  1054,     0,     0,
    1055,     0,  1291,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,  1545,
     458,   435,     0,     0,     0,     0,     0,     0,  1459,     0,
    1460,     0,     0,     0,     0,   163,     0,     0,  1559,   167,
       0,     0,     0,   168,   169,   170,   171,   172,     0,     0,
       0,    89,     0,     0,  1086,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,   176,     0,     0,     0,
     177,     0,     0,     0,     0,   297,     0,     0,     0,     0,
     181,     0,   492,     0,     0,     0,     0,     0,     0,  1291,
       0,     0,     0,     0,     0,  1112,  1113,  1114,  1115,     0,
       0,     0,     0,     0,     0,  1291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   331,     0,     0,     0,
       0,   113,   114,   115,  1628,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,  1577,
       0,  1154,     0,     0,     0,     0,     0,     0,   145,   146,
     147,     0,     0,     0,     0,   152,     0,     0,     0,     0,
       0,  1661,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,     0,     0,     0,     0,     0,
    1678,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   110,   111,   112,     0,   435,
       0,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   458,     0,     0,   153,
     154,   155,     0,  1291,   156,     0,   157,   158,   159,   163,
       0,     0,     0,   167,   160,   161,     0,   168,   169,   170,
     171,   172,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   512,
     513,     0,     0,     0,   177,     0,     0,     0,     0,   514,
       0,     0,     0,     0,   181,     0,   255,     0,     0,     0,
       0,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,  1291,     0,     0,  1691,     0,   163,
     164,   165,   166,   167,     0,     0,     0,   168,   169,   170,
     171,   172,   173,     0,   174,    89,     0,     0,     0,     0,
       0,     0,     0,   458,   458,     0,     0,  1369,     0,   175,
     176,     0,     0,     0,   177,     0,     0,     0,     0,   178,
       0,   179,     0,   180,   181,     0,   182,     0,   183,     0,
       0,   458,     0,     0,     0,   458,   110,   288,     0,     0,
       0,     0,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     290,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,   152,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,   158,   159,
       0,     0,     0,     0,     0,   160,     0,     0,     0,   291,
       0,     0,   292,     0,     0,   293,     0,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,  1452,  1453,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,   561,    59,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,   458,     0,
       0,     0,     0,     0,     0,   458,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,     0,  1750,   167,     0,     0,     0,   168,   169,
     170,   171,   172,     0,     0,     0,    89,     0,     0,     0,
       0,     0,   458,     0,     0,     0,     0,     0,     0,     0,
     512,  1479,     0,     0,     0,   177,     0,     0,     0,     0,
     514,     0,     0,   458,     0,   181,     0,   255,   563,     0,
       0,     0,     0,     0,   110,   288,     0,     0,     0,     0,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   290,  1646,
     565,     0,     0,     0,     0,     0,     0,   145,   146,   147,
       0,     0,     0,     0,   152,     0,     0,     0,     0,  1576,
       0,     0,     0,     0,     0,   157,   158,   159,     0,     0,
       0,     0,     0,   160,     0,     0,     0,   291,     0,     0,
     292,     0,     0,   293,     0,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,  1612,    48,    49,    50,    51,    52,     0,
       0,     0,   458,    56,   458,     0,    59,     0,     0,     0,
       0,     0,     0,     0,  1633,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,     0,
       0,     0,   167,     0,     0,     0,   168,   169,   170,   171,
     172,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,   458,   565,     0,     0,     0,   175,   456,
       0,     0,     0,   177,     0,     0,     0,     0,   297,     0,
       0,     0,     0,   181,   830,     0,   563,     0,     0,     0,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   708,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   288,   112,  1726,     0,  1729,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   290,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,   153,   154,   155,     0,     0,   156,
       0,   157,   158,   159,     0,     0,     0,     0,     0,   160,
     161,     0,     0,   291,  1781,     0,   292,     0,     0,   293,
       0,   294,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   708,   433,   434,     0,     0,
       0,     0,   435,     0,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   923,     0,
       0,     0,   435,     0,   163,   164,   165,   166,   167,     0,
       0,     0,   168,   169,   170,   171,   172,   173,     0,   174,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   175,   296,     0,     0,     0,   177,
       0,     0,     0,     0,   297,     0,   110,   288,   112,   181,
       0,   298,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     290,     0,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
     153,   154,   155,     0,     0,   156,     0,   157,   158,   159,
       0,     0,     0,     0,     0,   160,   161,     0,     0,   291,
       0,     0,   292,     0,     0,   293,     0,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,   164,   165,   166,   167,     0,     0,     0,   168,   169,
     170,   171,   172,   173,     0,   174,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,   296,     0,     0,     0,   177,     0,     0,     0,     0,
     297,     0,   110,   331,   112,   181,     0,  1507,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,   153,   154,   155,     0,
       0,   156,     0,   157,   158,   159,     0,   110,   331,   112,
       0,   160,   161,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     0,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,   153,   154,   155,     0,     0,   156,     0,   157,   158,
     159,     0,     0,     0,     0,     0,   160,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,   166,
     167,     0,     0,     0,   168,   169,   170,   171,   172,   173,
    1053,   174,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   175,   176,     0,  1235,
       0,   177,     0,     0,     0,     0,   297,     0,     0,     0,
       0,   181,     0,  1299,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,   164,   165,   166,   167,     0,     0,     0,   168,
     169,   170,   171,   172,   173,     0,   174,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,   176,     0,     0,     0,   177,     0,     0,     0,
       0,   297,     0,   110,   331,   112,   181,     0,  1500,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     7,     8,     0,   153,   154,   155,
       0,     0,   156,     0,   157,   158,   159,     0,     0,     0,
       0,     0,   160,   161,     0,     0,     0,     0,     0,     0,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,   663,    24,
      25,   664,    27,    28,   665,    30,   666,    32,     0,    33,
       0,     0,     0,     0,    38,    39,     0,    41,    42,    43,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,   164,   165,
     166,   167,     0,     0,     0,   168,   169,   170,   171,   172,
     173,     0,   174,    89,     0,     0,     0,    67,    68,    69,
       0,     0,     0,     0,     0,     0,     0,   175,   176,     0,
       0,     0,   177,     0,     0,     0,     0,   297,     0,   110,
     288,   289,   181,     0,  1510,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   290,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   146,   147,     0,     0,     0,     0,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,   158,   159,     0,     0,     0,     0,     0,   160,     0,
       0,     0,   291,     0,     0,   292,     0,     0,   293,     0,
     294,   322,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,     0,     0,     0,     0,     0,   139,   140,   141,
     142,   143,   144,     0,     0,     0,   148,   149,   150,   151,
       0,     0,     0,     0,   153,   154,   155,     0,     0,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,     0,     0,   163,     0,     0,     0,   167,     0,     0,
       0,   168,   169,   170,   171,   172,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,   296,     0,     0,     0,   177,     0,
       0,     0,     0,   297,     0,   110,   288,  1362,   181,     0,
     298,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   290,
       0,     0,     0,     0,     0,   164,   165,   166,   145,   146,
     147,     0,     0,     0,     0,   152,     0,   173,     0,   174,
      89,     0,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,     0,     0,     0,   291,     0,
       0,   292,     0,     0,   293,     0,   294,   443,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,     0,
       0,     0,     0,   139,   140,   141,   142,   143,   144,     0,
       0,     0,   148,   149,   150,   151,     0,     0,     0,     0,
     153,   154,   155,     0,     0,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   161,     0,     0,   163,
       0,     0,     0,   167,     0,     0,     0,   168,   169,   170,
     171,   172,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   175,
     296,     0,     0,     0,   177,     0,     0,     0,     0,   297,
       0,   110,   288,     0,   181,     0,  1363,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   290,     0,     0,     0,     0,
       0,   164,   165,   166,   145,   146,   147,     0,     0,     0,
       0,   152,     0,   173,     0,   174,    89,     0,     0,     0,
       0,     0,   157,   158,   159,     0,     0,     0,     0,     0,
     160,     0,     0,     0,   291,     0,     0,   292,   325,   112,
     293,     0,   294,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,   139,   140,   141,   142,   143,   144,
       0,     0,     0,   148,   149,   150,   151,     0,     0,     0,
       0,   153,   154,   155,     0,     0,   156,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,   167,
       0,     0,     0,   168,   169,   170,   171,   172,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,   296,     0,     0,     0,
     177,     0,     0,     0,     0,   297,     0,   110,   288,     0,
     181,     0,   298,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   290,   164,   165,   166,     0,     0,     0,     0,     0,
     145,   146,   147,     0,   173,     0,   174,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   158,
     159,     0,     0,     0,     0,     0,   160,     0,     0,     0,
     291,     0,     0,   292,     0,   112,   293,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     139,   140,   141,   142,   143,   144,     0,     0,     0,   148,
     149,   150,   151,     0,     0,     0,     0,   153,   154,   155,
       0,     0,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,   163,     0,     0,     0,   167,     0,     0,     0,   168,
     169,   170,   171,   172,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,   456,     0,     0,     0,   177,     0,     0,     0,
       0,   297,     0,   110,   288,     0,   181,     0,   559,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   290,   164,   165,
     166,  1157,     0,     0,     0,     0,   145,   146,   147,     0,
     173,     0,   174,   152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   158,   159,     0,     0,     0,
       0,     0,   160,     0,     0,     0,   291,     0,     0,   292,
       0,     0,   293,     0,   294,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,     0,     0,     0,     0,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,   163,   435,     0,
       0,   167,   655,     0,     0,   168,   169,   170,   171,   172,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   175,   456,     0,
       0,     0,   177,     0,     0,     0,     0,   297,     0,   110,
     288,     0,   181,     0,   818,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   290,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   146,   147,     0,     0,     0,     0,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,   158,   159,     0,     0,     0,     0,     0,   160,     0,
       0,     0,   291,     0,     0,   292,     0,     0,   293,     0,
     294,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,  1495,     0,  1496,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,   167,     0,     0,
       0,   168,   169,   170,   171,   172,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,   296,     0,     0,     0,   177,     0,
       0,     0,     0,   297,     0,   110,   288,     0,   181,     0,
    1367,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   290,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   146,
     147,     0,     0,     0,     0,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,     0,     0,     0,   291,     0,
       0,   292,     0,     0,   293,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,  1614,     0,  1615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
       0,     0,     0,   167,     0,     0,     0,   168,   169,   170,
     171,   172,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   512,
    1479,     0,     0,     0,   177,     0,     0,     0,     0,   514,
       0,   110,   331,   112,   181,     0,   255,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,   153,   154,   155,     0,     0,
     156,     0,   157,   158,   159,     0,     0,     0,     0,     0,
     160,   161,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,   920,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,   971,     0,     0,
       0,     0,     0,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,   163,   164,   165,   166,   167,
    1024,     0,     0,   168,   169,   170,   171,   172,   173,     0,
     174,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,   176,     0,     0,     0,
     177,   110,   288,     0,     0,   297,     0,   113,   114,   115,
     181,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   290,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   146,   147,     0,     0,     0,
       0,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,     0,     0,     0,     0,     0,
     160,     0,     0,     0,   291,     0,     0,   292,     0,     0,
     293,     0,   294,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1044,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,   167,
       0,     0,     0,   168,   169,   170,   171,   172,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,   456,     0,     0,     0,
     177,   110,   331,     0,     0,   297,     0,   113,   114,   115,
     181,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   146,   147,     0,     0,     0,
       0,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,     0,     0,     0,     0,     0,
     160,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,     0,     0,  1074,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,     0,     0,  1180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,     1,
       0,     0,    -4,     0,     0,     0,     0,     0,     0,     0,
      -4,    -4,     0,     0,     0,   163,     0,     0,     0,   167,
       0,     0,     0,   168,   169,   170,   171,   172,     0,     0,
       0,    89,     0,     0,     0,     0,    -4,    -4,     0,     0,
       0,     0,     0,     0,     0,   175,   176,     0,     0,     0,
     177,     0,    -4,    -4,    -4,   297,     0,     0,    -4,    -4,
     181,    -4,     0,     0,     0,    -4,    -4,     0,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,    -4,     6,     0,     0,     0,     0,    -4,     0,     0,
       7,     8,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     9,    10,     0,     0,
      -4,    -4,    -4,     0,     0,     0,     0,     0,     0,    -4,
       0,    -4,    11,    12,    13,     0,     0,     0,    14,    15,
       0,    16,     0,     0,     0,    17,    18,     0,    19,    20,
       0,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,     0,    62,
      63,    64,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,    66,    67,    68,    69,     0,     0,    70,     0,
      71,     0,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
      85,    86,    87,     0,     0,     0,     0,     0,     0,    88,
       0,    89,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1457,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1476,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1532,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1533,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1534,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1535,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1536,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1568,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1630,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1640,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1641,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1669,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1672,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1675,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1702,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1709,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1744,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1746,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1748,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1766,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1792,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1830,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1831,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1835,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1836,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1837,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1838,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,   590,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
       0,   753,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,  1544,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,   815,
       0,     0,     0,     0,   760,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
     697,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,   760,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,   761,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,   827,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,   863,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
     871,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,   872,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,   873,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,   884,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1006,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1007,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1008,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1039,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1132,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1178,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1179,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1234,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1375,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1376,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1377,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1378,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1415,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1416,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1423,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1569,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1570,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1571,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1572,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1588,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1589,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1593,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1687,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1688,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1689,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1690,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1697,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1700,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1740,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1757,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1758,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1759,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1760,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1803,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1804,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1805,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1806,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,   833,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,   842,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,   850,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,   936,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,  1032,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,  1033,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,  1037,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,  1038,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,  1040,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
    1077,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,  1127,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,  1372,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,  1406,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,  1557,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,   654,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,   707,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,   711,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,   712,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,   714,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,   716,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,   717,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
     720,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,   721,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,   815,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,   823,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,   824,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,   825,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,   831,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,   832,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,   841,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,   849,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
     935,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,   960,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,   965,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,   970,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,   973,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,   974,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,   980,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,   989,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,   990,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,   991,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
    1023,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,  1025,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,  1026,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,  1027,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,  1031,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,  1267,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,  1458,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,  1475,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,  1499,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,  1696,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
    1764,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435
};

static const yytype_int16 yycheck[] =
{
       3,   248,   376,     7,   378,     4,   506,   507,     4,     6,
       3,     6,     6,     4,     6,   389,     4,     4,  1022,     5,
       5,     4,     4,  1365,     5,     4,     6,     5,     4,     4,
     197,     5,   199,     4,     6,     4,   263,     5,     5,   109,
       5,     4,     6,     4,     4,     4,   197,     5,   275,     5,
      82,     6,     6,   204,    57,     6,     6,     4,     7,     6,
     140,   197,    65,     6,   187,   188,    99,    70,   204,     6,
    1018,    82,   197,    84,   199,   155,   156,   110,    81,     6,
     203,   206,   205,   187,   188,   118,   119,   120,     7,    81,
      82,   124,   125,   126,   127,   197,  1438,   199,   187,   188,
     204,   328,     6,   330,   206,   407,   187,   188,   187,   188,
     187,   188,     0,   201,   203,    76,   205,   419,   206,    80,
     197,   203,   203,   205,   205,     3,   205,   204,     6,    76,
       7,    92,    13,   128,   130,   131,   132,   133,     7,   187,
     188,    49,    50,   203,    52,   205,   187,   188,   187,   188,
     187,   188,   187,   188,   198,   203,   128,   143,   143,   203,
       6,   140,   141,   204,   203,   143,   154,   204,   203,   143,
     174,   175,   176,   177,   128,   151,   194,   195,   181,    57,
     140,   141,   173,  1525,   197,   128,   204,   184,   197,   182,
     193,   194,    70,   187,   188,   204,   198,   173,   201,  1541,
     199,   203,   173,    81,   184,     6,   209,   206,   211,   205,
     197,     4,   199,   216,   201,   197,   208,   220,   204,   206,
     223,   204,   204,   204,   227,   228,   229,   230,   204,   204,
     233,   234,   235,   204,   197,   204,   204,   204,   197,   204,
     204,   204,   193,   194,   247,   248,   204,   197,   204,   204,
     187,   188,   201,  1201,   204,   174,   175,   176,   177,   197,
     187,   188,   187,   188,   194,   195,   269,   270,   271,     6,
     497,   498,   187,   188,   204,   194,   195,   198,   203,   200,
     283,   284,   201,   204,   194,   195,     8,   198,   203,   200,
     517,   197,   203,   296,   204,   298,   598,   174,   175,   176,
     177,   200,     6,   181,   203,   174,   175,   176,   177,     7,
     103,   104,   105,   106,     6,   193,   194,   194,   195,   112,
     187,   188,   115,   201,     6,   194,   195,   189,   190,   191,
     333,   209,   335,   336,   196,    79,   203,   407,    82,   340,
     187,   188,   197,   251,   252,   348,   203,   197,   205,   341,
     577,   259,   654,   655,   204,   263,   203,  1699,     7,    76,
     194,   195,    79,   590,   199,    82,   201,   201,   199,    79,
     248,   206,    82,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   333,   386,   387,   388,   389,   390,   187,   188,
     199,   394,   395,   396,   397,   398,   399,   197,   401,     7,
     392,   187,   188,   197,   203,   187,   188,   197,   400,   187,
     188,   187,   188,    86,   198,   418,   200,   203,   187,   188,
     204,   203,   187,   188,   197,   203,   377,   203,   379,   380,
     381,   197,   383,   384,   203,   386,   387,   388,   203,   390,
     197,    82,   199,   394,   395,   396,   397,   398,  1790,   206,
     203,   200,   205,   456,   203,   333,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     187,   188,    82,   203,   196,   205,   174,   175,   176,   177,
     197,     6,   197,   205,   199,   198,   201,   204,   491,   492,
     203,   206,   484,   485,   486,   487,   194,   195,   376,   377,
     378,   379,   380,   381,   204,   383,   384,    82,   386,   387,
     388,   389,   390,   506,   507,    82,   394,   395,   396,   397,
     398,   399,   203,   401,   205,   174,   175,   176,   177,   756,
     533,   534,   535,   187,   188,   605,    84,   187,   188,   841,
     842,    76,   545,   544,    79,   194,   195,    82,  1552,   203,
    1554,   197,  1556,   203,   194,   195,   559,   187,   188,   189,
     190,   191,   198,   566,   200,   198,   196,   200,   204,   570,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   654,   655,     8,    76,   196,   203,
      79,   205,    79,    82,   597,    84,   504,   505,   198,   204,
     187,   188,   204,   203,   512,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   203,   618,   619,   620,
     621,   622,   623,   624,   198,    99,   200,   628,   629,   630,
     204,   187,   188,    82,   103,   104,   110,   638,   639,   640,
     109,   642,     6,     7,   118,   119,   120,   203,   649,   650,
     124,   125,   126,   127,   198,    79,   228,   229,   230,   203,
     661,   233,   234,   235,   656,    82,   913,   545,   671,    79,
    1618,   187,   188,  1621,   187,   188,  1624,    79,  1682,   981,
      82,   983,    84,   985,   203,   987,   205,   203,   187,   188,
     203,   694,     4,   696,   187,   188,   699,   269,   270,   702,
       4,   704,   103,   104,   203,   708,   709,   203,   109,   205,
     203,   283,   284,     4,   706,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   203,   797,   205,   732,
     196,   205,   203,   197,   205,   199,   203,   201,   205,  1743,
     204,  1745,   206,  1747,     6,     7,   198,   198,   699,  1753,
     753,   203,   203,   704,   187,   188,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      79,   841,   842,    82,   196,    84,  1724,     4,    76,   849,
     850,    79,   197,   205,    82,   198,    84,   200,   197,   203,
     203,   205,  1796,   197,  1798,   798,  1800,   203,  1100,   205,
     198,   197,   200,     8,   807,   203,   809,   198,   811,   200,
     813,   198,   203,   200,  1116,   818,   203,    82,   821,    84,
     197,   699,  1770,   199,   702,  1773,   704,   199,  1776,    99,
     198,  1779,   200,     6,     6,   203,   839,    82,   197,    84,
     110,   197,   845,  1343,  1344,   197,   197,   850,   118,   119,
     120,   759,   197,     7,   124,   125,   126,   127,   766,   203,
    1107,   205,    99,   197,   772,   935,   936,  1815,   203,  1817,
     205,  1819,   875,   110,   203,   197,   205,   880,   881,   882,
     883,   118,   119,   120,   203,   199,   205,   124,   125,   126,
     127,   894,   884,   896,   204,   198,   203,   200,   205,   850,
     203,   203,   203,   205,   205,   197,   203,   203,   205,   205,
     913,   204,   197,   916,   917,   918,   919,   203,   197,   205,
     921,   203,   203,   205,   205,   203,   203,   205,   205,   880,
     197,   882,   883,   197,   203,   205,   205,     4,   941,     6,
     203,     6,   205,   894,  1246,   896,   203,   203,   205,   205,
       6,   952,   953,   197,   197,   958,   959,   203,   961,   205,
     963,   964,   197,   204,   967,   968,   197,   197,   205,   972,
    1040,   197,   850,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    99,   197,   204,
     941,   196,   203,   198,   205,   203,   197,   205,   110,   203,
     197,   205,   880,     4,   882,   883,   118,   119,   120,   203,
     197,   205,   124,   125,   126,   127,   894,   203,   896,   205,
     203,   197,   205,    99,   203,   203,   205,   205,   197,   203,
    1100,   205,   197,  1280,   110,   913,   203,   203,   205,   205,
     204,    99,   118,   119,   120,   204,   954,  1547,   124,   125,
     126,   127,   110,  1056,  1057,  1058,   203,   203,   205,   205,
     118,   119,   120,   941,  1067,   204,   124,   125,   126,   127,
       4,     5,   204,   203,  1075,   205,   203,   203,   205,   205,
     204,  1082,  1083,  1084,  1085,  1086,   203,   203,   205,   205,
     197,  1092,  1093,   205,   197,  1096,  1097,   197,  1006,  1007,
    1008,   203,   197,   205,  1107,   199,    40,    41,    42,    43,
      44,    45,   203,   206,   205,    49,    50,    51,    52,  1122,
       6,     6,   204,    57,    58,    59,   204,   204,    62,   205,
     199,   199,     6,   199,     6,   199,  1510,     6,  1141,    73,
     143,  1133,   204,   206,  1147,     6,     6,   205,     6,     6,
    1153,   204,  1155,  1156,     6,   199,     4,  1160,  1161,   196,
    1163,   201,  1165,     7,  1167,   204,  1169,  1170,  1171,    99,
     183,   184,   185,   186,   187,   188,   189,   190,   191,  1249,
     110,    99,   205,   196,  1187,   203,   203,     7,   118,   119,
     120,     6,   110,    99,   124,   125,   126,   127,     6,  1202,
     118,   119,   120,  1206,   110,  1208,   124,   125,   126,   127,
       6,   198,   118,   119,   120,     7,     7,  1218,   124,   125,
     126,   127,     6,   204,   158,   159,   160,     7,  1229,  1107,
       6,    99,     7,     6,     6,     6,   170,     4,   172,   173,
      54,    54,   110,    54,    54,   140,   204,   200,     6,   198,
     118,   119,   120,  1256,     6,     6,   124,   125,   126,   127,
     194,   195,   198,   198,   203,   203,   203,   201,  1260,  1516,
     203,   203,   203,   198,   198,   205,   198,  1280,     6,   200,
    1272,     4,     4,  1286,   143,     6,     6,   205,     6,     6,
     143,     7,  1200,  1296,     7,     7,  1299,     7,     7,   205,
       7,   143,     7,  1373,     7,  1256,     6,  1299,   204,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     4,     6,   198,   203,   196,   198,   205,
     201,     6,  1335,  1336,  1561,   198,   203,   205,   203,   203,
       7,     7,   198,   205,     7,  1296,    99,  1339,     6,   200,
    1343,  1344,     6,     6,   204,   204,     6,   110,   204,   204,
    1363,   201,  1365,   204,  1367,   118,   119,   120,     7,   199,
       6,   124,   125,   126,   127,     6,   197,   204,  1256,  1382,
     197,     6,   184,     7,     7,     7,  1389,    84,     7,     7,
    1393,     7,     7,     6,  1397,  1396,  1388,     7,     7,  1307,
       7,     7,  1280,     7,     7,  1397,  1398,  1399,     4,     4,
     204,   197,     6,     6,  1417,     7,     6,   204,  1296,     7,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     7,  1438,     7,  1345,   196,  1347,
       6,  1349,     6,     6,    82,     7,     6,     6,     4,     4,
       4,   205,   205,     6,     6,  1363,  1683,     6,  1366,  1367,
       6,     4,     6,   203,    12,    13,   198,   198,   198,   203,
       7,  1474,   198,   197,   201,   204,  1479,     6,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     6,   201,     6,    92,   196,  1500,   204,    99,
       6,    12,    13,   204,  1507,     6,   204,  1510,   204,     6,
     110,     6,   204,  1516,     6,     6,     5,     4,   118,   119,
     120,     6,  1525,     7,   124,   125,   126,   127,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,  1541,    87,
     204,  1544,   204,   204,    92,    93,     6,    95,    96,    97,
     199,     6,   204,   101,  1547,     6,     6,  1560,   204,     6,
     204,   204,  1565,     4,     6,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     6,    87,     6,   139,     6,
       4,    92,    93,   203,    95,    96,    97,   135,   136,   137,
     101,    99,     6,     4,     6,    12,    13,     6,     6,     6,
       6,     4,   110,     5,  1607,   205,     6,     6,     6,     6,
     118,   119,   120,     6,     6,   204,   124,   125,   126,   127,
     143,     6,     6,  1626,   135,   136,   137,     6,     6,     6,
       6,     6,  1510,     6,     6,     6,   203,     6,  1516,     6,
       6,    88,     6,  1551,     6,  1553,     7,  1555,   198,     6,
     201,     6,     6,     5,  1646,  1563,     6,   205,  1566,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   204,
      87,   204,     6,   204,   204,    92,    93,   205,    95,    96,
      97,  1684,   204,  1686,   101,    80,   205,   204,     6,   204,
       7,     6,   138,     6,   205,   205,  1699,   205,  1606,     6,
       6,   141,  1610,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     6,   135,   136,
     137,   196,     6,   198,     6,   200,     6,     6,   175,   176,
     177,   178,   179,     6,   204,     6,     6,     6,     6,   204,
     204,   204,  1734,     6,     6,   192,   204,     6,   205,   196,
      99,  1659,  1755,     6,     6,  1663,   204,    12,    13,     6,
    1763,     6,     6,   210,   211,   212,   213,     6,   215,   216,
     217,   218,     6,   220,   221,   222,     6,     6,  1686,   205,
     227,     6,   204,   204,   204,     6,     6,  1790,   205,   204,
       6,     6,     6,     6,     6,     6,     6,     6,   245,   204,
     204,     6,     6,   204,  1807,     6,  1809,   254,   255,     6,
     204,     6,  1763,   204,     6,     6,   263,     6,     6,     6,
       6,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,  1130,    87,  1741,  1742,  1649,  1839,    92,    93,  1530,
      95,    96,    97,  1531,   452,  1140,   101,     3,     3,   296,
     297,   298,   482,  1543,    -1,  1276,  1807,    -1,  1809,    -1,
      -1,   308,   309,   310,    -1,   312,    -1,    -1,    -1,   316,
     317,   318,    -1,    -1,   321,    -1,    -1,    -1,    -1,    -1,
     135,   136,   137,    -1,    -1,  1763,    -1,    -1,  1839,    -1,
     337,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   351,   352,    -1,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,  1807,
      -1,  1809,    -1,    12,    13,    -1,    -1,    -1,   385,    -1,
      -1,    -1,    -1,    -1,   391,    -1,   393,    -1,    -1,    -1,
     205,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,  1839,    -1,    -1,    -1,    -1,    -1,    -1,   415,    -1,
      -1,   418,    -1,    -1,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,    -1,
      -1,   438,   439,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,   456,
      -1,    -1,    -1,    92,    93,   462,    95,    96,    97,    -1,
     467,    -1,   101,    -1,    -1,   472,   473,    -1,    -1,    -1,
      -1,   478,   479,    -1,    -1,    -1,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,    -1,
      -1,    -1,   509,   510,   511,   512,   513,   514,    -1,    21,
      22,   518,   519,   520,   521,   522,    -1,    -1,    -1,   526,
      -1,   528,   529,    -1,    -1,    -1,   533,   534,   535,    -1,
      -1,   538,   539,   540,   541,   542,    -1,    -1,    -1,    -1,
      -1,   548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   559,     6,    -1,    -1,    -1,    -1,   565,   566,
      -1,   568,   569,    -1,    -1,    -1,   205,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,   589,    -1,    -1,   196,    -1,    -1,    -1,   596,
     597,    -1,    -1,    12,    13,   602,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,   160,   161,
     657,    -1,    -1,    -1,   166,   167,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    -1,
      -1,    -1,    -1,    92,    93,    -1,    95,    96,    97,    -1,
      -1,    -1,   101,    -1,   691,    -1,    -1,   694,    -1,   696,
     697,    -1,    -1,    -1,    -1,    -1,    -1,     6,   705,    -1,
      -1,   708,   709,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   722,   135,   136,   137,   196,
      -1,    -1,    -1,    -1,   731,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,   753,    -1,    -1,    -1,
      -1,    -1,    -1,   760,   761,    -1,    -1,    -1,    -1,   766,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,   779,    -1,    -1,   782,   288,   223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,   798,    -1,   305,    -1,    -1,    -1,    -1,    -1,    -1,
     807,   247,   809,    -1,   811,    -1,   813,    -1,    -1,    -1,
      -1,   818,    -1,    -1,   821,    -1,    -1,    -1,    -1,    -1,
     827,    -1,   829,   830,    -1,   271,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,    92,
      93,    -1,    95,    96,    97,    -1,   863,    -1,   101,    12,
      13,    -1,    -1,    -1,   871,   872,   873,    -1,   875,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,   893,   196,    -1,   335,
     336,   898,   135,   136,   137,    -1,   903,    -1,   410,   906,
      -1,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,   916,
     917,   918,   919,    -1,    -1,    -1,   923,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    -1,   382,    12,    13,    92,
      93,    -1,    95,    96,    97,    -1,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,    -1,    -1,   972,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,   982,    -1,   984,    -1,   986,
      -1,   988,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    -1,    12,    13,    -1,    92,    93,    -1,
      95,    96,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,  1039,    -1,    -1,    -1,  1043,    -1,  1045,  1046,
    1047,    -1,    -1,    -1,    -1,    -1,  1053,    -1,    -1,    -1,
      -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     135,   136,   137,  1070,    -1,  1072,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      -1,    -1,    -1,    -1,    92,    93,    -1,    95,    96,    97,
      -1,  1108,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1120,  1121,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,  1132,  1133,    -1,    -1,    -1,
     205,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1177,  1178,  1179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1187,    -1,  1189,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,  1200,    87,    -1,    -1,    -1,    -1,    92,
      93,  1208,    95,    96,    97,    -1,  1213,   205,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   671,    -1,  1234,  1235,  1236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,    -1,     6,    -1,    -1,   211,
      -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,  1273,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1287,    -1,    -1,    -1,    -1,  1292,   732,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1305,  1306,
      -1,     6,    -1,    -1,    -1,  1312,  1313,    -1,    -1,    -1,
    1317,    -1,   205,    -1,    -1,    -1,    -1,    -1,  1325,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1335,  1336,
    1337,    -1,  1339,    -1,   296,    -1,   298,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1351,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1363,    -1,    -1,    -1,
    1367,    -1,    -1,  1370,    -1,    -1,    -1,    -1,  1375,  1376,
    1377,  1378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,  1388,    -1,    -1,    -1,   216,    -1,    -1,    -1,   220,
      -1,  1398,    -1,   839,    -1,    -1,   227,    -1,    -1,   845,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1415,  1416,
      -1,    -1,    -1,    -1,    -1,    -1,  1423,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,   881,   196,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,  1459,    -1,    -1,   196,   418,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1477,    -1,  1479,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,  1495,    -1,
    1497,   196,    -1,  1500,   456,    -1,    -1,    -1,    -1,    -1,
    1507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   958,   959,  1521,   961,    -1,   963,   964,  1526,
      -1,   967,   968,    -1,    -1,    -1,    -1,    -1,    -1,   491,
     492,    -1,    -1,    -1,    -1,    -1,    -1,  1544,    -1,    -1,
      -1,    -1,    -1,    -1,  1551,    -1,  1553,    -1,  1555,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1565,    -1,
      -1,    -1,  1569,  1570,  1571,  1572,  1573,    -1,    -1,    -1,
      -1,   533,   534,   535,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1588,  1589,    -1,    -1,    -1,  1593,   418,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,  1603,   559,    -1,    -1,
      -1,    -1,    -1,    -1,   566,    -1,    -1,  1614,    -1,    -1,
    1056,  1057,  1058,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1067,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,   597,    -1,  1644,    -1,    -1,
      -1,    -1,  1649,    -1,    -1,    -1,    -1,     6,    -1,  1656,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     491,   492,    -1,  1670,    -1,    -1,  1673,    -1,    -1,  1676,
      -1,    -1,    -1,  1680,    -1,    -1,  1122,  1684,    -1,  1686,
    1687,  1688,  1689,  1690,    -1,    -1,    -1,    -1,    -1,    -1,
    1697,    -1,    -1,  1700,    -1,  1141,    -1,    -1,    -1,    -1,
      -1,  1147,   533,   534,   535,    -1,    -1,  1153,    -1,  1155,
    1156,    -1,    -1,    -1,  1160,  1161,    -1,  1163,    -1,  1165,
      -1,  1167,    -1,  1169,  1170,  1171,    -1,    -1,   559,    -1,
      -1,    -1,   694,  1740,   696,    -1,    -1,    -1,    -1,    -1,
      -1,  1187,    -1,    -1,    -1,    -1,   708,   709,  1755,    -1,
    1757,  1758,  1759,  1760,    -1,    -1,  1202,    -1,    -1,    -1,
    1206,    -1,    -1,    -1,    -1,    -1,   597,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,  1793,  1794,    -1,    -1,
      -1,   753,    -1,    -1,    -1,    -1,  1803,  1804,  1805,  1806,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,   798,   196,    -1,    -1,
    1286,    -1,    -1,    -1,    -1,   807,    -1,   809,    -1,   811,
      -1,   813,    -1,  1299,    -1,    -1,   818,    -1,    -1,   821,
      -1,    -1,    -1,   694,    -1,   696,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   875,    46,    47,    48,    -1,    -1,  1365,
      -1,    53,   753,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,  1382,    -1,    -1,    -1,
      72,    -1,    -1,  1389,    -1,    -1,    -1,  1393,    -1,    -1,
      -1,  1397,    -1,    -1,   916,   917,   918,   919,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   798,    -1,    -1,
      -1,  1417,    -1,    -1,    -1,    -1,   807,    -1,   809,    -1,
     811,    -1,   813,    -1,    -1,    -1,    -1,   818,    -1,    -1,
     821,    -1,  1438,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,     6,
     972,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,
     205,    -1,    -1,    -1,    -1,   157,    -1,    -1,  1474,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,
      -1,   173,    -1,    -1,   875,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,
     202,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,  1525,
      -1,    -1,    -1,    -1,    -1,   916,   917,   918,   919,    -1,
      -1,    -1,    -1,    -1,    -1,  1541,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,  1560,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     6,
      -1,   972,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,  1607,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
    1626,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     3,     4,     5,    -1,   196,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,  1208,    -1,    -1,    57,
      58,    59,    -1,  1699,    62,    -1,    64,    65,    66,   157,
      -1,    -1,    -1,   161,    72,    73,    -1,   165,   166,   167,
     168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,    -1,   202,    -1,   204,    -1,    -1,    -1,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,  1790,    -1,    -1,     6,    -1,   157,
     158,   159,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,    -1,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1335,  1336,    -1,    -1,  1208,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
      -1,   199,    -1,   201,   202,    -1,   204,    -1,   206,    -1,
      -1,  1363,    -1,    -1,    -1,  1367,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,  1335,  1336,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,   112,    -1,  1479,   115,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,  1500,    -1,
      -1,    -1,    -1,    -1,    -1,  1507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,     6,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,  1544,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,
     197,    -1,    -1,  1565,    -1,   202,    -1,   204,   205,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,  1500,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,  1544,   103,   104,   105,   106,   107,    -1,
      -1,    -1,  1684,   112,  1686,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1565,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1755,     8,    -1,    -1,    -1,   187,   188,
      -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,    -1,
      -1,    -1,    -1,   202,     8,    -1,   205,    -1,    -1,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,  1684,    -1,  1686,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    62,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    76,  1755,    -1,    79,    -1,    -1,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   115,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     8,    -1,
      -1,    -1,   196,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,    -1,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,   197,    -1,     3,     4,     5,   202,
      -1,   204,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    62,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,    -1,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,
     197,    -1,     3,     4,     5,   202,    -1,   204,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    62,    -1,    64,    65,    66,    -1,     3,     4,     5,
      -1,    72,    73,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    57,    58,    59,    -1,    -1,    62,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
       8,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,    -1,     8,
      -1,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,   202,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,    -1,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,
      -1,   197,    -1,     3,     4,     5,   202,    -1,   204,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    12,    13,    -1,    57,    58,    59,
      -1,    -1,    62,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      -1,    -1,    -1,    -1,    92,    93,    -1,    95,    96,    97,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,    -1,   172,   173,    -1,    -1,    -1,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,    -1,
      -1,    -1,   192,    -1,    -1,    -1,    -1,   197,    -1,     3,
       4,     5,   202,    -1,   204,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,    -1,
      84,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,   197,    -1,     3,     4,     5,   202,    -1,
     204,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,   170,    -1,   172,
     173,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    82,    -1,    84,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    -1,    -1,    -1,   112,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,   157,
      -1,    -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
      -1,     3,     4,    -1,   202,    -1,   204,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,   170,    -1,   172,   173,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    79,     4,     5,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,
     112,    -1,    -1,   115,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    57,    58,    59,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,   197,    -1,     3,     4,    -1,
     202,    -1,   204,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    -1,   170,    -1,   172,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,     5,    82,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    57,    58,    59,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,
      -1,   197,    -1,     3,     4,    -1,   202,    -1,   204,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,   158,   159,
     160,    99,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
     170,    -1,   172,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,    -1,    -1,    -1,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,   157,   196,    -1,
      -1,   161,   200,    -1,    -1,   165,   166,   167,   168,   169,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,    -1,
      -1,    -1,   192,    -1,    -1,    -1,    -1,   197,    -1,     3,
       4,    -1,   202,    -1,   204,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,    -1,
      -1,   115,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,   197,    -1,     3,     4,    -1,   202,    -1,
     204,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    -1,    -1,    -1,   112,    -1,    -1,   115,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,   203,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
      -1,     3,     4,     5,   202,    -1,   204,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,
      62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    73,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     205,    -1,    -1,   165,   166,   167,   168,   169,   170,    -1,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,     3,     4,    -1,    -1,   197,    -1,     9,    10,    11,
     202,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,
     112,    -1,    -1,   115,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,     3,     4,    -1,    -1,   197,    -1,     9,    10,    11,
     202,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,    54,    55,    56,   197,    -1,    -1,    60,    61,
     202,    63,    -1,    -1,    -1,    67,    68,    -1,    70,    71,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
     122,   123,     4,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      12,    13,   134,   135,   136,   137,    -1,    -1,   140,    -1,
     142,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,    38,    39,    -1,    -1,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
      -1,   173,    54,    55,    56,    -1,    -1,    -1,    60,    61,
      -1,    63,    -1,    -1,    -1,    67,    68,    -1,    70,    71,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,    -1,    -1,   140,    -1,
     142,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
      -1,   173,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     198,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,   198,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     198,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,   198,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     198,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,   198,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     198,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   208,   209,     6,     0,     4,    12,    13,    38,
      39,    54,    55,    56,    60,    61,    63,    67,    68,    70,
      71,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   110,   111,   112,   113,   114,   115,
     116,   117,   121,   122,   123,   129,   134,   135,   136,   137,
     140,   142,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   162,   163,   164,   171,   173,
     210,   212,   213,   233,   250,   251,   254,   255,   256,   257,
     258,   259,   260,   261,   282,   283,   284,   285,   303,   304,
       3,     4,     5,     9,    10,    11,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    57,    58,    59,    62,    64,    65,    66,
      72,    73,   151,   157,   158,   159,   160,   161,   165,   166,
     167,   168,   169,   170,   172,   187,   188,   192,   197,   199,
     201,   202,   204,   206,   231,   286,   287,   299,   300,   303,
     304,    13,    82,   197,   197,     6,   204,     6,     6,     6,
       6,   197,     6,     6,   199,   199,   197,   199,   231,   231,
     197,   204,   197,   197,     4,   197,   204,   197,   197,     4,
     204,   197,   197,    86,    82,    82,     6,   204,    76,    79,
      82,    82,    82,    79,    82,    84,    84,    76,    79,    82,
      84,    79,    82,    84,    79,    82,   197,    79,   140,   155,
     156,   204,   187,   188,   197,   204,   289,   290,   289,   204,
      76,    79,    82,   204,   289,     4,    76,    80,    92,    82,
      84,    82,    79,     4,   151,   204,   303,   304,     4,     6,
      76,    79,    82,    79,    82,     4,     4,     4,     4,     5,
      37,    76,    79,    82,    84,    96,   188,   197,   204,   251,
     261,   286,   292,   293,   294,   303,   304,     4,   197,   197,
     197,     4,   204,   296,   304,     4,   197,   197,   197,     6,
       6,   199,     4,   300,   304,     4,   300,     5,   204,     5,
     204,     4,   286,   199,     6,   197,   204,   197,   199,   206,
     231,     7,   174,   175,   176,   177,   194,   195,   229,   230,
       4,   197,   199,   201,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   197,
     197,   197,   197,   197,   197,   231,   231,   231,   231,   197,
     231,   231,   231,     7,   197,   197,   197,   231,   231,   197,
     197,   199,   286,   286,   286,   286,   286,     4,   140,   141,
     304,     4,   251,   252,   253,   204,   198,   200,   204,   232,
       6,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   196,   204,     6,   197,   199,
     230,     6,   286,     4,   299,   300,   304,   299,   286,   299,
     302,   235,   238,   300,   304,   286,   188,   286,   294,   295,
     286,   286,   197,   286,   295,   286,   286,   197,   295,   286,
     286,   292,   197,   204,   295,   293,   293,   293,   197,   197,
     293,   293,   293,   197,   197,   197,   197,   197,   197,   197,
     197,   204,   204,   286,     4,   292,   296,   204,   204,   289,
     289,   289,   286,   286,   187,   188,   204,   204,   289,   204,
     204,   204,   187,   188,   197,   253,   289,   204,   197,   204,
     197,   197,   197,   293,   293,   292,   197,     4,   199,   199,
     253,     6,     6,   204,   204,   204,   293,   293,   199,   199,
     199,   197,   199,   201,   231,   199,     5,   143,   204,     5,
     143,     5,   143,     5,   143,    76,    79,    82,    84,   204,
     286,   294,   286,   205,   295,     8,   189,     6,   197,   199,
     231,     6,   286,   286,   286,   201,   286,   204,   143,   286,
     286,   286,   286,     6,     6,     6,   253,     6,   253,   199,
     204,   299,   292,   292,   286,   286,   204,   204,   232,   300,
     292,     6,   199,   286,   286,     4,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   302,   299,
     302,   299,   299,   299,   292,   299,   299,   286,   299,   299,
     299,   302,   299,   286,   300,   286,   299,   299,   299,   299,
     299,   304,   300,   304,   198,   200,     7,   229,   230,   201,
       7,   231,   205,    76,    79,    82,    84,   250,   286,   295,
       7,   229,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   214,   286,   286,
       6,   199,   201,   198,   203,   198,   203,   203,   198,   203,
     200,   203,   234,   200,   234,   203,   203,   198,   189,   203,
     205,   198,   198,   286,   198,   205,   198,   198,   286,   205,
     198,   198,     7,   286,   286,   205,     6,     6,     6,   286,
     286,     7,     7,   279,   279,   286,   244,   286,   300,   245,
     286,   300,   246,   286,   300,   247,   286,   300,   286,   286,
     286,   295,   295,   204,   198,     6,   204,   253,   253,   203,
     203,   203,   289,   289,   252,   252,   203,   286,   286,   286,
     286,   265,   203,   253,   286,   286,   286,   286,   286,     7,
     280,     6,     7,   286,     6,   286,   286,   205,   295,   295,
     295,     6,     6,   286,   286,   286,   286,     4,   204,   232,
     304,    54,   286,    54,    54,    54,     5,   204,     5,   204,
       5,   204,     5,   204,   295,   198,   205,   286,   204,   286,
     294,   204,   232,   198,   198,   198,   140,   203,   253,   204,
       8,   198,   198,   200,   205,   205,   253,   200,   198,   203,
     205,   198,   200,   286,   295,   229,     6,     6,   286,   198,
     200,   230,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   203,   232,   232,   232,   232,   232,   232,
     232,   203,   203,   203,   232,   203,   232,   232,   198,   198,
     203,   203,   203,   203,   203,   232,   232,   232,   198,   232,
     288,   301,     6,   203,   203,   198,   203,   232,   203,   232,
     198,   198,   200,   229,   230,   201,   229,   230,   300,   286,
       6,     4,     4,   204,   297,   232,   204,   204,   204,   204,
     205,   205,   292,     8,     4,   130,   131,   132,   133,   205,
     217,   221,   224,   226,   227,   198,   200,   286,     4,     6,
     184,   211,   295,     6,   295,   286,     6,   299,     6,   304,
       6,   299,   286,   300,     7,   286,   294,   143,     7,     7,
     198,     7,   143,     7,     7,   198,   143,     7,     7,   286,
     198,   205,   204,   198,   198,   286,   292,     4,   278,     6,
     198,   198,   203,   198,   203,   198,   203,   198,   203,   198,
     198,   198,   205,   205,   295,   201,   253,   205,   205,   289,
     286,   286,   205,   205,   286,   289,   203,   203,   203,    99,
     110,   118,   119,   120,   124,   125,   126,   127,   275,   276,
     289,   205,   262,   198,   205,   198,   198,   198,   286,     6,
     286,   198,   200,   200,   205,   205,   205,   200,   200,   203,
     200,   295,   200,   204,   205,   204,   204,   204,   295,   295,
     295,   295,   205,     8,   295,   295,     7,     7,     7,   201,
     286,   205,   286,   286,     7,   201,   205,   204,   292,     6,
     229,   230,   229,   230,   205,   205,   292,   200,   230,   201,
     230,   299,   286,   286,   286,   286,   295,   299,   292,   299,
     299,   300,   240,   242,   286,   299,   299,   286,   286,     6,
       4,   140,   141,   286,     6,     6,     6,     7,   199,   296,
     298,     6,   295,   295,   295,   295,   232,     6,   286,   218,
     197,   197,   204,   228,     6,   230,   230,   200,   184,   299,
     198,   198,   203,     7,   232,   232,   289,    82,    84,   292,
     292,     7,   292,    82,    84,   292,   292,     7,    84,   292,
     292,     6,     7,     7,   295,     7,     7,    99,   277,     6,
       7,   229,   286,   229,   286,   229,   286,   229,   286,     7,
       7,     7,     7,     7,   205,     4,   205,   203,   203,   203,
     205,   205,   289,   289,   289,     4,     6,   204,     6,   197,
       6,   128,     6,   128,     6,   128,     6,   128,   205,   276,
     203,   275,     7,     6,     7,     7,     7,     6,   204,     6,
       6,     6,    82,     7,     6,     6,   286,   201,   205,   286,
     286,   286,   286,   205,   205,   205,   205,   286,   205,   205,
     292,   292,   292,     4,   203,     8,     8,   198,     4,     4,
     292,   205,   286,     6,   286,     6,   232,     6,     6,     4,
       6,   232,   232,   232,   232,   232,   203,   198,   198,   198,
     203,   203,   232,   241,   203,   232,   243,   198,   198,   232,
     232,     6,     7,   229,   230,   201,     7,     6,   296,   286,
     203,   205,   205,   205,   205,   205,   229,   197,   286,   286,
     291,   292,   204,   201,     6,     6,   211,     6,   286,   204,
     286,   300,     6,     6,     6,   204,   204,    92,   249,   249,
     292,     6,   204,   204,     6,     6,   292,   204,     6,     6,
       5,   292,   205,   292,   292,     4,     6,   292,   292,   292,
     292,   292,   292,   292,   292,   204,   204,     7,     6,     7,
     286,   286,   286,   204,   204,   203,   205,   203,   205,   203,
     205,   199,   286,   292,   286,     6,     6,     6,     6,   286,
     289,   205,     5,   204,   292,   204,   204,   204,   292,   295,
     204,   286,   200,     4,   232,   203,   203,   203,   203,   232,
       6,     6,   139,   286,   286,   286,     6,     6,     7,   203,
       6,     6,     6,   229,   230,   299,   300,     4,     4,   154,
     300,   286,     6,     4,   297,     6,   200,   296,     6,     6,
       6,     6,   292,   215,   286,   203,   203,   203,   205,   216,
     286,     4,   299,   203,   292,   300,   286,   286,   289,     6,
       6,     6,   286,   286,     6,   286,     5,     6,   204,     6,
     143,   248,   286,     6,     6,     6,     6,     6,     6,     4,
       6,     6,   295,   295,   286,   286,   300,   205,   198,   203,
     205,   252,   252,   289,     6,   266,   289,     6,   267,   289,
       6,   268,   286,   205,   203,   198,   205,   203,     6,   188,
     289,     6,   291,   289,   289,     6,   205,   286,     6,     6,
     286,   286,   286,   286,   292,   203,   205,     8,   205,   198,
     204,   286,   300,   292,   292,   198,   232,   204,   292,   300,
     204,   286,   300,   300,     6,     6,     7,     6,   201,     6,
     198,   203,   286,   286,   292,   204,   203,   205,     6,   286,
     236,   237,   205,   205,   205,   205,   205,     5,   291,    80,
       6,   204,   205,   205,   204,     6,     6,   204,   286,   205,
     205,   203,   204,   203,   204,   203,   204,   200,     6,   292,
       7,   204,   286,   203,   205,   203,   203,     6,   205,   203,
     203,   203,   203,   138,   286,   286,   295,     6,     6,   205,
       6,   239,   286,   302,   296,   141,   219,   286,   203,   203,
     291,   286,     6,   203,   240,   242,     6,     6,     6,     6,
       6,     6,   205,   204,   291,   103,   104,   109,   281,   103,
     104,   281,   295,   252,   203,   205,   286,   289,   275,   286,
     289,   275,   286,   289,   275,     6,   203,   205,   292,   253,
     205,   289,     6,   295,   289,   286,   286,   286,   286,   286,
     205,   205,   205,     6,   203,   205,     7,   205,     6,   204,
     286,   286,   205,   286,   205,   205,   204,   286,   205,   204,
     289,   292,     6,   204,   289,     6,   205,   205,   286,   205,
     203,   205,   205,   203,   205,   205,   203,   205,   292,     6,
      99,   205,   263,   204,   203,   205,   203,   203,   203,   203,
     203,     6,     6,   286,   300,   216,   198,   203,     6,   204,
     203,   286,   205,     6,   289,     6,   289,     6,     6,   205,
       6,   269,   286,     6,     6,   270,   286,     6,     6,   271,
     286,     6,   205,   286,   275,   253,   295,     6,   289,   295,
     286,   286,   286,   286,     7,   205,   222,   286,   291,   286,
     203,   203,   203,   204,   205,   204,   205,   204,   205,     6,
       6,   205,   205,   264,   205,   203,   205,   203,   203,   203,
     203,   300,     6,   204,   198,   205,   205,   286,   289,   289,
     275,     6,   272,   275,     6,   273,   275,     6,   274,   275,
       6,   295,     6,   286,   286,   286,   286,   220,   299,   225,
     204,     6,   205,   203,   203,   205,   204,   205,   204,   205,
     204,   205,   205,   203,   203,   203,   203,   203,   205,   204,
     291,     6,   286,   286,     6,   275,     6,   275,     6,   275,
       6,   286,   286,   286,   286,   299,     6,   223,   299,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   203,
     205,     6,     6,     6,     6,     6,     6,   299,     6
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
#line 198 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 209 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 210 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 211 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 212 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 213 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 214 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 215 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 216 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 217 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 218 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 16:
#line 219 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 220 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 221 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 222 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 223 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 224 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 229 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 23:
#line 233 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 24:
#line 240 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 25:
#line 245 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 26:
#line 250 "Gmsh.y"
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
#line 264 "Gmsh.y"
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
#line 277 "Gmsh.y"
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
#line 290 "Gmsh.y"
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
#line 318 "Gmsh.y"
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
#line 332 "Gmsh.y"
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
#line 345 "Gmsh.y"
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
#line 358 "Gmsh.y"
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
#line 376 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 40:
#line 390 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:
#line 392 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:
#line 397 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 43:
#line 399 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 44:
#line 404 "Gmsh.y"
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
#line 508 "Gmsh.y"
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
#line 518 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 47:
#line 527 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 48:
#line 534 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 49:
#line 544 "Gmsh.y"
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
#line 553 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 51:
#line 562 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 569 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 579 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 54:
#line 587 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 55:
#line 597 "Gmsh.y"
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
#line 616 "Gmsh.y"
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
#line 635 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 58:
#line 641 "Gmsh.y"
    {
    ;}
    break;

  case 59:
#line 648 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 60:
#line 649 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 61:
#line 650 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 62:
#line 651 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 63:
#line 652 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 64:
#line 656 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 657 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 66:
#line 663 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 67:
#line 663 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 68:
#line 664 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 69:
#line 664 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 72:
#line 673 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 73:
#line 678 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 74:
#line 684 "Gmsh.y"
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
#line 744 "Gmsh.y"
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
#line 773 "Gmsh.y"
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
#line 802 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 78:
#line 807 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 79:
#line 812 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 80:
#line 817 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 81:
#line 822 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 82:
#line 829 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 83:
#line 836 "Gmsh.y"
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
#line 851 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 856 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 86:
#line 861 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 866 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 88:
#line 871 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 89:
#line 880 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 90:
#line 886 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 91:
#line 895 "Gmsh.y"
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
#line 913 "Gmsh.y"
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
#line 931 "Gmsh.y"
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
#line 940 "Gmsh.y"
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
#line 952 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 96:
#line 957 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 97:
#line 965 "Gmsh.y"
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
#line 985 "Gmsh.y"
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
#line 1008 "Gmsh.y"
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
#line 1019 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 101:
#line 1027 "Gmsh.y"
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
#line 1049 "Gmsh.y"
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
#line 1072 "Gmsh.y"
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
#line 1098 "Gmsh.y"
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
#line 1119 "Gmsh.y"
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
#line 1131 "Gmsh.y"
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
#line 1149 "Gmsh.y"
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
#line 1158 "Gmsh.y"
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
#line 1167 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 113:
#line 1169 "Gmsh.y"
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
#line 1185 "Gmsh.y"
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
#line 1194 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 116:
#line 1196 "Gmsh.y"
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
#line 1210 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 119:
#line 1218 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 120:
#line 1224 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 123:
#line 1236 "Gmsh.y"
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
#line 1247 "Gmsh.y"
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
#line 1262 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 128:
#line 1278 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 129:
#line 1286 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 130:
#line 1295 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 131:
#line 1303 "Gmsh.y"
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
#line 1321 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 133:
#line 1325 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 134:
#line 1331 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 135:
#line 1339 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 136:
#line 1343 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 137:
#line 1349 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 138:
#line 1357 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 139:
#line 1361 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 140:
#line 1367 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 141:
#line 1375 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 142:
#line 1379 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 143:
#line 1385 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 144:
#line 1393 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 145:
#line 1397 "Gmsh.y"
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
#line 1409 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 147:
#line 1413 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 148:
#line 1423 "Gmsh.y"
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
#line 1446 "Gmsh.y"
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
#line 1486 "Gmsh.y"
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
#line 1509 "Gmsh.y"
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
#line 1527 "Gmsh.y"
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
#line 1548 "Gmsh.y"
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
#line 1566 "Gmsh.y"
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
#line 1596 "Gmsh.y"
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
#line 1626 "Gmsh.y"
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
#line 1644 "Gmsh.y"
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
#line 1663 "Gmsh.y"
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
#line 1689 "Gmsh.y"
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
#line 1707 "Gmsh.y"
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
#line 1725 "Gmsh.y"
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
#line 1768 "Gmsh.y"
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
#line 1786 "Gmsh.y"
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
#line 1825 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 165:
#line 1831 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 166:
#line 1837 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 167:
#line 1844 "Gmsh.y"
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
#line 1869 "Gmsh.y"
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
#line 1894 "Gmsh.y"
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
#line 1911 "Gmsh.y"
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
#line 1931 "Gmsh.y"
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
#line 1964 "Gmsh.y"
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
#line 2008 "Gmsh.y"
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
#line 2026 "Gmsh.y"
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
#line 2043 "Gmsh.y"
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
#line 2059 "Gmsh.y"
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
#line 2104 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 178:
#line 2109 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 179:
#line 2114 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 180:
#line 2119 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 181:
#line 2124 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 182:
#line 2129 "Gmsh.y"
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
#line 2152 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 184:
#line 2158 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 185:
#line 2168 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 186:
#line 2169 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 187:
#line 2174 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 188:
#line 2178 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 189:
#line 2182 "Gmsh.y"
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
#line 2205 "Gmsh.y"
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
#line 2228 "Gmsh.y"
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
#line 2251 "Gmsh.y"
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
#line 2279 "Gmsh.y"
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
#line 2300 "Gmsh.y"
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
#line 2327 "Gmsh.y"
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
#line 2348 "Gmsh.y"
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
#line 2369 "Gmsh.y"
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
#line 2389 "Gmsh.y"
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
#line 2501 "Gmsh.y"
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
#line 2520 "Gmsh.y"
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
#line 2559 "Gmsh.y"
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
#line 2667 "Gmsh.y"
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
#line 2676 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 204:
#line 2682 "Gmsh.y"
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
#line 2697 "Gmsh.y"
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
#line 2725 "Gmsh.y"
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
#line 2742 "Gmsh.y"
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
#line 2751 "Gmsh.y"
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
#line 2765 "Gmsh.y"
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
#line 2779 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 211:
#line 2785 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 212:
#line 2791 "Gmsh.y"
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
#line 2800 "Gmsh.y"
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
#line 2809 "Gmsh.y"
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
#line 2818 "Gmsh.y"
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
#line 2832 "Gmsh.y"
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "OptimizeMesh")){
        GModel::current()->optimizeMesh((yyvsp[(2) - (3)].c));
      }
      else{
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 217:
#line 2891 "Gmsh.y"
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
#line 2909 "Gmsh.y"
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
#line 2926 "Gmsh.y"
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
#line 2941 "Gmsh.y"
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
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 221:
#line 2967 "Gmsh.y"
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
#line 2979 "Gmsh.y"
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
#line 3003 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 224:
#line 3007 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 225:
#line 3012 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 226:
#line 3019 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 227:
#line 3024 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 228:
#line 3030 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 229:
#line 3035 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 230:
#line 3041 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 231:
#line 3049 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 232:
#line 3053 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 233:
#line 3057 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 234:
#line 3063 "Gmsh.y"
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
#line 3122 "Gmsh.y"
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

  case 236:
#line 3139 "Gmsh.y"
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

  case 237:
#line 3156 "Gmsh.y"
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

  case 238:
#line 3178 "Gmsh.y"
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

  case 239:
#line 3200 "Gmsh.y"
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

  case 240:
#line 3235 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 241:
#line 3243 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 242:
#line 3251 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 243:
#line 3257 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 244:
#line 3264 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 245:
#line 3271 "Gmsh.y"
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

  case 246:
#line 3291 "Gmsh.y"
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

  case 247:
#line 3317 "Gmsh.y"
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

  case 248:
#line 3329 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 249:
#line 3341 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 250:
#line 3349 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 251:
#line 3357 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 252:
#line 3365 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 253:
#line 3371 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 254:
#line 3379 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 255:
#line 3385 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 256:
#line 3393 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 257:
#line 3399 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 258:
#line 3407 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 259:
#line 3413 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 260:
#line 3421 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 261:
#line 3428 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 262:
#line 3435 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 263:
#line 3442 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 264:
#line 3449 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 265:
#line 3456 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 266:
#line 3463 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 267:
#line 3470 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 268:
#line 3477 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 269:
#line 3484 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 270:
#line 3490 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 271:
#line 3497 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 272:
#line 3503 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 273:
#line 3510 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 274:
#line 3516 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 275:
#line 3523 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 276:
#line 3529 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 277:
#line 3536 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 278:
#line 3542 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 279:
#line 3549 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 280:
#line 3555 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 281:
#line 3562 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 282:
#line 3568 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 283:
#line 3575 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 284:
#line 3581 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 285:
#line 3588 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 286:
#line 3594 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 287:
#line 3605 "Gmsh.y"
    {
    ;}
    break;

  case 288:
#line 3608 "Gmsh.y"
    {
    ;}
    break;

  case 289:
#line 3614 "Gmsh.y"
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
#line 3626 "Gmsh.y"
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
#line 3646 "Gmsh.y"
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
#line 3670 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 293:
#line 3674 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 294:
#line 3678 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 295:
#line 3682 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 296:
#line 3686 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 297:
#line 3692 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 298:
#line 3698 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 299:
#line 3702 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 300:
#line 3706 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 301:
#line 3710 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 302:
#line 3714 "Gmsh.y"
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
#line 3733 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 304:
#line 3745 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 305:
#line 3749 "Gmsh.y"
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
#line 3764 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 307:
#line 3768 "Gmsh.y"
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
#line 3784 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 309:
#line 3788 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 310:
#line 3793 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 311:
#line 3797 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 312:
#line 3803 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 313:
#line 3807 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 314:
#line 3814 "Gmsh.y"
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
#line 3870 "Gmsh.y"
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
#line 3940 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 317:
#line 3945 "Gmsh.y"
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
#line 4012 "Gmsh.y"
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
#line 4048 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 320:
#line 4056 "Gmsh.y"
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
#line 4099 "Gmsh.y"
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
#line 4138 "Gmsh.y"
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
#line 4159 "Gmsh.y"
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
#line 4191 "Gmsh.y"
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
#line 4218 "Gmsh.y"
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
#line 4244 "Gmsh.y"
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
#line 4270 "Gmsh.y"
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
#line 4296 "Gmsh.y"
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
#line 4322 "Gmsh.y"
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
#line 4343 "Gmsh.y"
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
#line 4371 "Gmsh.y"
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
#line 4399 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    ;}
    break;

  case 333:
#line 4403 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 334:
#line 4407 "Gmsh.y"
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
#line 4435 "Gmsh.y"
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
#line 4474 "Gmsh.y"
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
#line 4513 "Gmsh.y"
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
#line 4534 "Gmsh.y"
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
#line 4555 "Gmsh.y"
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
#line 4582 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 341:
#line 4586 "Gmsh.y"
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
#line 4596 "Gmsh.y"
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
#line 4630 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 344:
#line 4631 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 345:
#line 4632 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 346:
#line 4637 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 347:
#line 4643 "Gmsh.y"
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
#line 4655 "Gmsh.y"
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
#line 4673 "Gmsh.y"
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
#line 4700 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 351:
#line 4701 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 352:
#line 4702 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 353:
#line 4703 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 354:
#line 4704 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 355:
#line 4705 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 356:
#line 4706 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 357:
#line 4707 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 358:
#line 4709 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 359:
#line 4715 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 360:
#line 4716 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 361:
#line 4717 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 362:
#line 4718 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 363:
#line 4719 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 364:
#line 4720 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 365:
#line 4721 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 366:
#line 4722 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 367:
#line 4723 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 368:
#line 4724 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 369:
#line 4725 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 370:
#line 4726 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 371:
#line 4727 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 372:
#line 4728 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 373:
#line 4729 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 374:
#line 4730 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 375:
#line 4731 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 376:
#line 4732 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 377:
#line 4733 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 378:
#line 4734 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 379:
#line 4735 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 380:
#line 4736 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 381:
#line 4737 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 382:
#line 4738 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 383:
#line 4739 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 384:
#line 4740 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 385:
#line 4741 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 386:
#line 4742 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 387:
#line 4743 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 388:
#line 4744 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 389:
#line 4745 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 390:
#line 4746 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 391:
#line 4747 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 392:
#line 4756 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 393:
#line 4757 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 394:
#line 4758 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 395:
#line 4759 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 396:
#line 4760 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 397:
#line 4761 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 398:
#line 4762 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 399:
#line 4763 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 400:
#line 4764 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 401:
#line 4765 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 402:
#line 4766 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 403:
#line 4771 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 404:
#line 4773 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 405:
#line 4779 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 406:
#line 4784 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 407:
#line 4789 "Gmsh.y"
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

  case 408:
#line 4806 "Gmsh.y"
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
#line 4824 "Gmsh.y"
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
#line 4842 "Gmsh.y"
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
#line 4860 "Gmsh.y"
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

  case 412:
#line 4878 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 413:
#line 4883 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 414:
#line 4889 "Gmsh.y"
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

  case 415:
#line 4901 "Gmsh.y"
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

  case 416:
#line 4918 "Gmsh.y"
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
#line 4936 "Gmsh.y"
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
#line 4954 "Gmsh.y"
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
#line 4972 "Gmsh.y"
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

  case 420:
#line 4993 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 421:
#line 4998 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 422:
#line 5003 "Gmsh.y"
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

  case 423:
#line 5013 "Gmsh.y"
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

  case 424:
#line 5023 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 425:
#line 5028 "Gmsh.y"
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

  case 426:
#line 5039 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 427:
#line 5048 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 428:
#line 5053 "Gmsh.y"
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

  case 429:
#line 5080 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 430:
#line 5084 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 431:
#line 5088 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 432:
#line 5092 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 433:
#line 5096 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 434:
#line 5103 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 435:
#line 5107 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 436:
#line 5111 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 437:
#line 5115 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 438:
#line 5122 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 439:
#line 5127 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 440:
#line 5134 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 441:
#line 5139 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 442:
#line 5143 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 443:
#line 5148 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 444:
#line 5152 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 445:
#line 5160 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 446:
#line 5171 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 447:
#line 5175 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 448:
#line 5187 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 449:
#line 5195 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 450:
#line 5203 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 451:
#line 5210 "Gmsh.y"
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

  case 452:
#line 5220 "Gmsh.y"
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

  case 453:
#line 5249 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 454:
#line 5253 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 455:
#line 5257 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 456:
#line 5261 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 457:
#line 5265 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 458:
#line 5269 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 459:
#line 5273 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 460:
#line 5277 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 461:
#line 5281 "Gmsh.y"
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

  case 462:
#line 5310 "Gmsh.y"
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

  case 463:
#line 5339 "Gmsh.y"
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

  case 464:
#line 5368 "Gmsh.y"
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

  case 465:
#line 5398 "Gmsh.y"
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

  case 466:
#line 5411 "Gmsh.y"
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

  case 467:
#line 5424 "Gmsh.y"
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

  case 468:
#line 5437 "Gmsh.y"
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

  case 469:
#line 5449 "Gmsh.y"
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
#line 5459 "Gmsh.y"
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

  case 471:
#line 5469 "Gmsh.y"
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
#line 5481 "Gmsh.y"
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

  case 473:
#line 5494 "Gmsh.y"
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

  case 474:
#line 5506 "Gmsh.y"
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
#line 5524 "Gmsh.y"
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

  case 476:
#line 5545 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 477:
#line 5550 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 478:
#line 5554 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 479:
#line 5558 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 480:
#line 5570 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 481:
#line 5574 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 482:
#line 5586 "Gmsh.y"
    {
      int flag;
      if(gmsh_yystringsymbols.count((yyvsp[(1) - (1)].c)))
        (yyval.u) = GetColorForString(-1, gmsh_yystringsymbols[(yyvsp[(1) - (1)].c)].c_str(), &flag);
      else
        (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 483:
#line 5596 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 484:
#line 5606 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 485:
#line 5610 "Gmsh.y"
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

  case 486:
#line 5625 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 487:
#line 5630 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 488:
#line 5637 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 489:
#line 5641 "Gmsh.y"
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

  case 490:
#line 5654 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 491:
#line 5662 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 492:
#line 5673 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 493:
#line 5677 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 494:
#line 5681 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 495:
#line 5689 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 496:
#line 5695 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 497:
#line 5701 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 498:
#line 5709 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 499:
#line 5717 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 500:
#line 5724 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 501:
#line 5732 "Gmsh.y"
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

  case 502:
#line 5747 "Gmsh.y"
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

  case 503:
#line 5761 "Gmsh.y"
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

  case 504:
#line 5775 "Gmsh.y"
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

  case 505:
#line 5787 "Gmsh.y"
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

  case 506:
#line 5803 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 507:
#line 5812 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 508:
#line 5821 "Gmsh.y"
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

  case 509:
#line 5831 "Gmsh.y"
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

  case 510:
#line 5842 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 511:
#line 5846 "Gmsh.y"
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

  case 512:
#line 5865 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 513:
#line 5872 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 514:
#line 5878 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 515:
#line 5880 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 516:
#line 5891 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 517:
#line 5896 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 518:
#line 5902 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 519:
#line 5911 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 520:
#line 5924 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 521:
#line 5927 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 522:
#line 5931 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 12062 "Gmsh.tab.cpp"
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


#line 5934 "Gmsh.y"


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

