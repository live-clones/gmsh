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
     tGetEnv = 413,
     tGetString = 414,
     tGetNumber = 415,
     tHomology = 416,
     tCohomology = 417,
     tBetti = 418,
     tSetOrder = 419,
     tExists = 420,
     tFileExists = 421,
     tGMSH_MAJOR_VERSION = 422,
     tGMSH_MINOR_VERSION = 423,
     tGMSH_PATCH_VERSION = 424,
     tGmshExecutableName = 425,
     tSetPartition = 426,
     tNameFromString = 427,
     tStringFromName = 428,
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
#define tGetEnv 413
#define tGetString 414
#define tGetNumber 415
#define tHomology 416
#define tCohomology 417
#define tBetti 418
#define tSetOrder 419
#define tExists 420
#define tFileExists 421
#define tGMSH_MAJOR_VERSION 422
#define tGMSH_MINOR_VERSION 423
#define tGMSH_PATCH_VERSION 424
#define tGmshExecutableName 425
#define tSetPartition 426
#define tNameFromString 427
#define tStringFromName 428
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
#line 110 "Gmsh.y"
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
#line 595 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 608 "Gmsh.tab.cpp"

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
#define YYLAST   10257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  207
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  521
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1841

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
    1312,  1315,  1318,  1321,  1324,  1341,  1345,  1352,  1361,  1370,
    1381,  1383,  1386,  1389,  1391,  1395,  1399,  1404,  1409,  1411,
    1413,  1419,  1431,  1445,  1446,  1454,  1455,  1469,  1470,  1486,
    1487,  1494,  1503,  1512,  1521,  1534,  1547,  1560,  1575,  1590,
    1605,  1606,  1619,  1620,  1633,  1634,  1647,  1648,  1665,  1666,
    1683,  1684,  1701,  1702,  1721,  1722,  1741,  1742,  1761,  1763,
    1766,  1772,  1780,  1790,  1793,  1796,  1799,  1803,  1806,  1810,
    1813,  1817,  1820,  1824,  1834,  1841,  1842,  1846,  1847,  1849,
    1850,  1853,  1854,  1857,  1858,  1861,  1869,  1876,  1885,  1891,
    1895,  1903,  1909,  1914,  1921,  1933,  1945,  1964,  1983,  1996,
    2009,  2022,  2033,  2044,  2055,  2066,  2077,  2082,  2087,  2092,
    2097,  2102,  2105,  2109,  2116,  2118,  2120,  2122,  2125,  2131,
    2139,  2150,  2152,  2156,  2159,  2162,  2165,  2169,  2173,  2177,
    2181,  2185,  2189,  2193,  2197,  2201,  2205,  2209,  2213,  2217,
    2221,  2227,  2232,  2237,  2242,  2247,  2252,  2257,  2262,  2267,
    2272,  2277,  2284,  2289,  2294,  2299,  2304,  2309,  2314,  2319,
    2326,  2333,  2340,  2345,  2347,  2349,  2351,  2353,  2355,  2357,
    2359,  2361,  2363,  2365,  2367,  2368,  2375,  2380,  2382,  2387,
    2392,  2397,  2402,  2407,  2412,  2417,  2420,  2426,  2432,  2438,
    2444,  2448,  2455,  2460,  2468,  2475,  2482,  2489,  2496,  2501,
    2503,  2506,  2509,  2513,  2517,  2529,  2539,  2547,  2555,  2557,
    2561,  2563,  2565,  2568,  2572,  2577,  2583,  2585,  2587,  2590,
    2594,  2598,  2604,  2609,  2612,  2615,  2618,  2621,  2625,  2629,
    2633,  2637,  2643,  2649,  2655,  2661,  2678,  2695,  2712,  2729,
    2731,  2733,  2737,  2741,  2746,  2753,  2760,  2762,  2764,  2768,
    2772,  2782,  2790,  2792,  2798,  2802,  2809,  2811,  2815,  2817,
    2819,  2823,  2830,  2832,  2837,  2839,  2841,  2843,  2848,  2855,
    2860,  2865,  2870,  2875,  2884,  2889,  2894,  2899,  2904,  2913,
    2918,  2925,  2930,  2932,  2933,  2940,  2942,  2946,  2952,  2958,
    2960,  2962
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
      -1,   164,   286,     6,    -1,   142,   197,   286,     8,   286,
     198,    -1,   142,   197,   286,     8,   286,     8,   286,   198,
      -1,   142,     4,   143,   204,   286,     8,   286,   205,    -1,
     142,     4,   143,   204,   286,     8,   286,     8,   286,   205,
      -1,   144,    -1,   154,     4,    -1,   154,   300,    -1,   152,
      -1,   153,   304,     6,    -1,   153,   300,     6,    -1,   145,
     197,   286,   198,    -1,   146,   197,   286,   198,    -1,   147,
      -1,   148,    -1,   107,   289,   204,   253,   205,    -1,   107,
     204,   289,   203,   289,   203,   286,   205,   204,   253,   205,
      -1,   107,   204,   289,   203,   289,   203,   289,   203,   286,
     205,   204,   253,   205,    -1,    -1,   107,   289,   204,   253,
     262,   275,   205,    -1,    -1,   107,   204,   289,   203,   289,
     203,   286,   205,   204,   253,   263,   275,   205,    -1,    -1,
     107,   204,   289,   203,   289,   203,   289,   203,   286,   205,
     204,   253,   264,   275,   205,    -1,    -1,   107,   204,   253,
     265,   275,   205,    -1,   107,    76,   204,   286,   203,   289,
     205,     6,    -1,   107,    79,   204,   286,   203,   289,   205,
       6,    -1,   107,    82,   204,   286,   203,   289,   205,     6,
      -1,   107,    76,   204,   286,   203,   289,   203,   289,   203,
     286,   205,     6,    -1,   107,    79,   204,   286,   203,   289,
     203,   289,   203,   286,   205,     6,    -1,   107,    82,   204,
     286,   203,   289,   203,   289,   203,   286,   205,     6,    -1,
     107,    76,   204,   286,   203,   289,   203,   289,   203,   289,
     203,   286,   205,     6,    -1,   107,    79,   204,   286,   203,
     289,   203,   289,   203,   289,   203,   286,   205,     6,    -1,
     107,    82,   204,   286,   203,   289,   203,   289,   203,   289,
     203,   286,   205,     6,    -1,    -1,   107,    76,   204,   286,
     203,   289,   205,   266,   204,   275,   205,     6,    -1,    -1,
     107,    79,   204,   286,   203,   289,   205,   267,   204,   275,
     205,     6,    -1,    -1,   107,    82,   204,   286,   203,   289,
     205,   268,   204,   275,   205,     6,    -1,    -1,   107,    76,
     204,   286,   203,   289,   203,   289,   203,   286,   205,   269,
     204,   275,   205,     6,    -1,    -1,   107,    79,   204,   286,
     203,   289,   203,   289,   203,   286,   205,   270,   204,   275,
     205,     6,    -1,    -1,   107,    82,   204,   286,   203,   289,
     203,   289,   203,   286,   205,   271,   204,   275,   205,     6,
      -1,    -1,   107,    76,   204,   286,   203,   289,   203,   289,
     203,   289,   203,   286,   205,   272,   204,   275,   205,     6,
      -1,    -1,   107,    79,   204,   286,   203,   289,   203,   289,
     203,   289,   203,   286,   205,   273,   204,   275,   205,     6,
      -1,    -1,   107,    82,   204,   286,   203,   289,   203,   289,
     203,   289,   203,   286,   205,   274,   204,   275,   205,     6,
      -1,   276,    -1,   275,   276,    -1,   118,   204,   286,   205,
       6,    -1,   118,   204,   292,   203,   292,   205,     6,    -1,
     118,   204,   292,   203,   292,   203,   292,   205,     6,    -1,
     119,     6,    -1,   110,     6,    -1,   126,     6,    -1,   126,
     128,     6,    -1,   127,     6,    -1,   127,   128,     6,    -1,
     124,     6,    -1,   124,   128,     6,    -1,   125,     6,    -1,
     125,   128,     6,    -1,   120,   197,   286,   198,     7,   292,
      99,   286,     6,    -1,    99,     4,   199,   286,   200,     6,
      -1,    -1,    99,     4,   286,    -1,    -1,     4,    -1,    -1,
       7,   292,    -1,    -1,     7,   286,    -1,    -1,   109,   292,
      -1,    94,    79,   293,     7,   286,   277,     6,    -1,    94,
      82,   293,   279,   278,     6,    -1,    88,    82,   204,   286,
     205,     7,   292,     6,    -1,    94,    84,   293,   279,     6,
      -1,   129,   293,     6,    -1,   116,    82,   204,   295,   205,
     286,     6,    -1,   110,    82,   293,   280,     6,    -1,   110,
      84,   293,     6,    -1,   111,    82,   292,     7,   286,     6,
      -1,    98,    79,   204,   295,   205,     7,   204,   295,   205,
     281,     6,    -1,    98,    82,   204,   295,   205,     7,   204,
     295,   205,   281,     6,    -1,    98,    79,   204,   295,   205,
       7,   204,   295,   205,   103,   204,   289,   203,   289,   203,
     286,   205,     6,    -1,    98,    82,   204,   295,   205,     7,
     204,   295,   205,   103,   204,   289,   203,   289,   203,   286,
     205,     6,    -1,    98,    79,   204,   295,   205,     7,   204,
     295,   205,   104,   289,     6,    -1,    98,    82,   204,   295,
     205,     7,   204,   295,   205,   104,   289,     6,    -1,    98,
      82,   286,   204,   295,   205,     7,   286,   204,   295,   205,
       6,    -1,    76,   204,   295,   205,   143,    82,   204,   286,
     205,     6,    -1,    79,   204,   295,   205,   143,    82,   204,
     286,   205,     6,    -1,    76,   204,   295,   205,   143,    84,
     204,   286,   205,     6,    -1,    79,   204,   295,   205,   143,
      84,   204,   286,   205,     6,    -1,    82,   204,   295,   205,
     143,    84,   204,   286,   205,     6,    -1,   117,    82,   293,
       6,    -1,   117,    79,   293,     6,    -1,    91,    76,   293,
       6,    -1,    91,    79,   293,     6,    -1,    91,    82,   293,
       6,    -1,   114,     6,    -1,   114,     4,     6,    -1,   114,
      76,   204,   295,   205,     6,    -1,   161,    -1,   162,    -1,
     163,    -1,   284,     6,    -1,   284,   204,   292,   205,     6,
      -1,   284,   204,   292,   203,   292,   205,     6,    -1,   284,
     197,   292,   198,   204,   292,   203,   292,   205,     6,    -1,
     287,    -1,   197,   286,   198,    -1,   188,   286,    -1,   187,
     286,    -1,   192,   286,    -1,   286,   188,   286,    -1,   286,
     187,   286,    -1,   286,   189,   286,    -1,   286,   190,   286,
      -1,   286,   191,   286,    -1,   286,   196,   286,    -1,   286,
     183,   286,    -1,   286,   184,   286,    -1,   286,   186,   286,
      -1,   286,   185,   286,    -1,   286,   182,   286,    -1,   286,
     181,   286,    -1,   286,   180,   286,    -1,   286,   179,   286,
      -1,   286,   178,   286,     8,   286,    -1,    15,   231,   286,
     232,    -1,    16,   231,   286,   232,    -1,    17,   231,   286,
     232,    -1,    18,   231,   286,   232,    -1,    19,   231,   286,
     232,    -1,    20,   231,   286,   232,    -1,    21,   231,   286,
     232,    -1,    22,   231,   286,   232,    -1,    23,   231,   286,
     232,    -1,    25,   231,   286,   232,    -1,    26,   231,   286,
     203,   286,   232,    -1,    27,   231,   286,   232,    -1,    28,
     231,   286,   232,    -1,    29,   231,   286,   232,    -1,    30,
     231,   286,   232,    -1,    31,   231,   286,   232,    -1,    32,
     231,   286,   232,    -1,    33,   231,   286,   232,    -1,    34,
     231,   286,   203,   286,   232,    -1,    35,   231,   286,   203,
     286,   232,    -1,    36,   231,   286,   203,   286,   232,    -1,
      24,   231,   286,   232,    -1,     3,    -1,     9,    -1,    14,
      -1,    10,    -1,    11,    -1,   167,    -1,   168,    -1,   169,
      -1,    64,    -1,    65,    -1,    66,    -1,    -1,    72,   231,
     286,   288,   240,   232,    -1,   160,   231,   299,   232,    -1,
     304,    -1,     4,   199,   286,   200,    -1,     4,   197,   286,
     198,    -1,   303,   199,   286,   200,    -1,   303,   197,   286,
     198,    -1,   165,   197,   304,   198,    -1,   166,   197,   300,
     198,    -1,   202,   304,   231,   232,    -1,   304,   230,    -1,
       4,   199,   286,   200,   230,    -1,     4,   197,   286,   198,
     230,    -1,   303,   199,   286,   200,   230,    -1,   303,   197,
     286,   198,   230,    -1,     4,   201,     4,    -1,     4,   199,
     286,   200,   201,     4,    -1,     4,   201,     4,   230,    -1,
       4,   199,   286,   200,   201,     4,   230,    -1,   157,   197,
     299,   203,   286,   198,    -1,    46,   197,   292,   203,   292,
     198,    -1,    47,   197,   299,   203,   299,   198,    -1,    48,
     197,   299,   203,   299,   198,    -1,    53,   197,   302,   198,
      -1,   290,    -1,   188,   289,    -1,   187,   289,    -1,   289,
     188,   289,    -1,   289,   187,   289,    -1,   204,   286,   203,
     286,   203,   286,   203,   286,   203,   286,   205,    -1,   204,
     286,   203,   286,   203,   286,   203,   286,   205,    -1,   204,
     286,   203,   286,   203,   286,   205,    -1,   197,   286,   203,
     286,   203,   286,   198,    -1,   292,    -1,   291,   203,   292,
      -1,   286,    -1,   294,    -1,   204,   205,    -1,   204,   295,
     205,    -1,   188,   204,   295,   205,    -1,   286,   189,   204,
     295,   205,    -1,   292,    -1,     5,    -1,   188,   294,    -1,
     286,   189,   294,    -1,   286,     8,   286,    -1,   286,     8,
     286,     8,   286,    -1,    76,   204,   286,   205,    -1,    76,
       5,    -1,    79,     5,    -1,    82,     5,    -1,    84,     5,
      -1,    96,    76,     5,    -1,    96,    79,     5,    -1,    96,
      82,     5,    -1,    96,    84,     5,    -1,    96,    76,   204,
     295,   205,    -1,    96,    79,   204,   295,   205,    -1,    96,
      82,   204,   295,   205,    -1,    96,    84,   204,   295,   205,
      -1,    76,   143,    54,   204,   286,   203,   286,   203,   286,
     203,   286,   203,   286,   203,   286,   205,    -1,    79,   143,
      54,   204,   286,   203,   286,   203,   286,   203,   286,   203,
     286,   203,   286,   205,    -1,    82,   143,    54,   204,   286,
     203,   286,   203,   286,   203,   286,   203,   286,   203,   286,
     205,    -1,    84,   143,    54,   204,   286,   203,   286,   203,
     286,   203,   286,   203,   286,   203,   286,   205,    -1,   251,
      -1,   261,    -1,     4,   231,   232,    -1,   303,   231,   232,
      -1,    37,   199,   304,   200,    -1,     4,   231,   204,   295,
     205,   232,    -1,   303,   231,   204,   295,   205,   232,    -1,
     286,    -1,   294,    -1,   295,   203,   286,    -1,   295,   203,
     294,    -1,   204,   286,   203,   286,   203,   286,   203,   286,
     205,    -1,   204,   286,   203,   286,   203,   286,   205,    -1,
       4,    -1,     4,   201,   140,   201,     4,    -1,   204,   298,
     205,    -1,     4,   199,   286,   200,   201,   141,    -1,   296,
      -1,   298,   203,   296,    -1,   300,    -1,   304,    -1,     4,
     201,     4,    -1,     4,   199,   286,   200,   201,     4,    -1,
       5,    -1,   173,   199,   304,   200,    -1,    57,    -1,   170,
      -1,    62,    -1,   158,   197,   299,   198,    -1,   159,   197,
     299,   203,   299,   198,    -1,   159,   197,   299,   198,    -1,
      42,   231,   302,   232,    -1,    43,   197,   299,   198,    -1,
      44,   197,   299,   198,    -1,    45,   197,   299,   203,   299,
     203,   299,   198,    -1,    40,   231,   302,   232,    -1,    50,
     231,   299,   232,    -1,    51,   231,   299,   232,    -1,    52,
     231,   299,   232,    -1,    49,   231,   286,   203,   300,   203,
     300,   232,    -1,    41,   231,   299,   232,    -1,    41,   231,
     299,   203,   295,   232,    -1,    58,   231,   299,   232,    -1,
      59,    -1,    -1,    73,   231,   300,   301,   242,   232,    -1,
     299,    -1,   302,   203,   299,    -1,     4,   206,   204,   286,
     205,    -1,   303,   206,   204,   286,   205,    -1,     4,    -1,
     303,    -1,   172,   199,   299,   200,    -1
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
    1477,  1500,  1518,  1539,  1557,  1587,  1617,  1635,  1653,  1680,
    1698,  1716,  1751,  1769,  1808,  1814,  1820,  1827,  1852,  1877,
    1894,  1913,  1947,  1983,  2001,  2018,  2034,  2071,  2076,  2081,
    2086,  2091,  2096,  2119,  2125,  2136,  2137,  2142,  2145,  2149,
    2172,  2195,  2218,  2246,  2267,  2293,  2314,  2336,  2356,  2468,
    2487,  2525,  2634,  2643,  2649,  2664,  2692,  2709,  2718,  2732,
    2746,  2752,  2758,  2767,  2776,  2785,  2799,  2855,  2873,  2890,
    2905,  2924,  2936,  2960,  2964,  2969,  2976,  2981,  2987,  2992,
    2998,  3006,  3010,  3014,  3019,  3074,  3087,  3104,  3121,  3143,
    3165,  3200,  3208,  3216,  3222,  3229,  3236,  3256,  3282,  3294,
    3306,  3314,  3322,  3331,  3330,  3345,  3344,  3359,  3358,  3373,
    3372,  3386,  3393,  3400,  3407,  3414,  3421,  3428,  3435,  3442,
    3450,  3449,  3463,  3462,  3476,  3475,  3489,  3488,  3502,  3501,
    3515,  3514,  3528,  3527,  3541,  3540,  3554,  3553,  3570,  3573,
    3579,  3591,  3611,  3635,  3639,  3643,  3647,  3651,  3657,  3663,
    3667,  3671,  3675,  3679,  3698,  3711,  3714,  3730,  3733,  3750,
    3753,  3759,  3762,  3769,  3772,  3779,  3835,  3905,  3910,  3977,
    4013,  4021,  4064,  4103,  4123,  4155,  4182,  4208,  4234,  4260,
    4286,  4308,  4336,  4364,  4368,  4372,  4400,  4439,  4478,  4499,
    4520,  4547,  4551,  4561,  4596,  4597,  4598,  4602,  4608,  4620,
    4638,  4666,  4667,  4668,  4669,  4670,  4671,  4672,  4673,  4674,
    4681,  4682,  4683,  4684,  4685,  4686,  4687,  4688,  4689,  4690,
    4691,  4692,  4693,  4694,  4695,  4696,  4697,  4698,  4699,  4700,
    4701,  4702,  4703,  4704,  4705,  4706,  4707,  4708,  4709,  4710,
    4711,  4712,  4713,  4722,  4723,  4724,  4725,  4726,  4727,  4728,
    4729,  4730,  4731,  4732,  4737,  4736,  4744,  4749,  4766,  4784,
    4802,  4820,  4838,  4843,  4849,  4861,  4878,  4896,  4914,  4932,
    4953,  4958,  4963,  4973,  4983,  4988,  4999,  5008,  5013,  5040,
    5044,  5048,  5052,  5056,  5063,  5067,  5071,  5075,  5082,  5087,
    5094,  5099,  5103,  5108,  5112,  5120,  5131,  5135,  5147,  5155,
    5163,  5170,  5180,  5209,  5213,  5217,  5221,  5225,  5229,  5233,
    5237,  5241,  5270,  5299,  5328,  5357,  5370,  5383,  5396,  5409,
    5419,  5429,  5441,  5454,  5466,  5484,  5505,  5510,  5514,  5518,
    5530,  5534,  5546,  5553,  5563,  5567,  5582,  5587,  5594,  5598,
    5611,  5619,  5630,  5634,  5638,  5646,  5652,  5658,  5666,  5674,
    5681,  5696,  5710,  5724,  5736,  5752,  5761,  5770,  5780,  5791,
    5795,  5814,  5821,  5828,  5827,  5840,  5845,  5851,  5860,  5873,
    5876,  5880
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
  "tGetEnv", "tGetString", "tGetNumber", "tHomology", "tCohomology",
  "tBetti", "tSetOrder", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
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
     259,   259,   259,   259,   259,   259,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     261,   261,   261,   262,   261,   263,   261,   264,   261,   265,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     266,   261,   267,   261,   268,   261,   269,   261,   270,   261,
     271,   261,   272,   261,   273,   261,   274,   261,   275,   275,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   277,   277,   278,   278,   279,
     279,   280,   280,   281,   281,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   283,   283,   283,   284,   284,   284,   285,   285,   285,
     285,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   288,   287,   287,   287,   287,   287,
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
     300,   300,   300,   301,   300,   302,   302,   303,   303,   304,
     304,   304
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
       1,     2,     2,     1,     3,     3,     4,     4,     1,     1,
       5,    11,    13,     0,     7,     0,    13,     0,    15,     0,
       6,     8,     8,     8,    12,    12,    12,    14,    14,    14,
       0,    12,     0,    12,     0,    12,     0,    16,     0,    16,
       0,    16,     0,    18,     0,    18,     0,    18,     1,     2,
       5,     7,     9,     2,     2,     2,     3,     2,     3,     2,
       3,     2,     3,     9,     6,     0,     3,     0,     1,     0,
       2,     0,     2,     0,     2,     7,     6,     8,     5,     3,
       7,     5,     4,     6,    11,    11,    18,    18,    12,    12,
      12,    10,    10,    10,    10,    10,     4,     4,     4,     4,
       4,     2,     3,     6,     1,     1,     1,     2,     5,     7,
      10,     1,     3,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     4,     1,     4,     4,
       4,     4,     4,     4,     4,     2,     5,     5,     5,     5,
       3,     6,     4,     7,     6,     6,     6,     6,     4,     1,
       2,     2,     3,     3,    11,     9,     7,     7,     1,     3,
       1,     1,     2,     3,     4,     5,     1,     1,     2,     3,
       3,     5,     4,     2,     2,     2,     2,     3,     3,     3,
       3,     5,     5,     5,     5,    16,    16,    16,    16,     1,
       1,     3,     3,     4,     6,     6,     1,     1,     3,     3,
       9,     7,     1,     5,     3,     6,     1,     3,     1,     1,
       3,     6,     1,     4,     1,     1,     1,     4,     6,     4,
       4,     4,     4,     8,     4,     4,     4,     4,     8,     4,
       6,     4,     1,     0,     6,     1,     3,     5,     5,     1,
       1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   519,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,     0,   248,   249,     0,     0,     0,
     243,     0,     0,     0,     0,   344,   345,   346,     0,     0,
       0,     5,     7,     6,     8,     9,    10,    20,    11,    12,
      13,    14,    19,    18,    15,    16,    17,     0,    21,   520,
       0,   393,   519,   492,   394,   396,   397,   395,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   494,     0,   512,   496,   401,   402,
     403,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     398,   399,   400,   495,     0,     0,     0,     0,    66,    67,
       0,     0,   187,     0,     0,     0,   351,     0,   488,   520,
     407,     0,     0,     0,     0,   227,     0,   229,   230,   225,
     226,     0,   231,   232,   109,   117,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   429,     0,     0,
       0,     0,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   519,     0,   187,   520,     0,     0,   341,
       0,     0,     0,     0,     0,     0,     0,     0,   519,   447,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   469,
     470,   440,   446,     0,   441,   520,   407,     0,     0,     0,
       0,   482,     0,     0,     0,     0,     0,     0,   223,   224,
       0,   519,     0,     0,   241,   242,     0,   187,     0,   187,
     519,     0,     0,     0,   347,     0,     0,    66,    67,     0,
       0,    59,    63,    62,    61,    60,    65,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   354,   353,   355,     0,     0,     0,     0,     0,     0,
       0,   186,     0,   185,     0,    68,    69,     0,     0,   220,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,   216,     0,     0,   415,
     164,     0,   519,     0,   488,   489,     0,     0,   515,     0,
     107,   107,     0,     0,     0,     0,   476,   477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     309,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,   187,     0,   431,
     430,     0,     0,     0,     0,   187,   187,     0,     0,     0,
       0,     0,     0,     0,   259,     0,   187,     0,     0,     0,
       0,     0,   311,     0,     0,     0,     0,     0,     0,     0,
     205,   342,     0,     0,     0,     0,     0,     0,     0,     0,
      66,    67,     0,     0,     0,   453,     0,     0,   454,     0,
     455,     0,   456,     0,     0,     0,     0,     0,     0,   353,
     448,     0,   442,     0,     0,     0,   319,    66,    67,     0,
     222,     0,     0,     0,     0,     0,   187,     0,     0,     0,
       0,     0,   245,   244,   210,     0,   211,     0,     0,   235,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   404,   513,     0,     0,     0,     0,     0,
       0,     0,     0,   352,     0,    59,     0,     0,     0,     0,
       0,   182,     0,     0,     0,     0,   188,     0,     0,    59,
       0,     0,   369,   368,   367,   366,   362,   363,   365,   364,
     357,   356,   358,   359,   360,   361,     0,     0,     0,   165,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   338,   339,   340,     0,     0,
       0,     0,   307,     0,     0,     0,   132,   133,     0,   135,
     136,     0,   138,   139,     0,   141,   142,     0,     0,     0,
       0,     0,     0,     0,   152,   187,     0,     0,     0,     0,
       0,   433,   432,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,     0,     0,     0,     0,     0,     0,     0,
     322,     0,     0,   206,     0,     0,   202,     0,     0,     0,
     337,   336,     0,     0,     0,     0,   420,     0,   471,     0,
       0,     0,     0,     0,     0,   457,     0,   458,     0,   459,
       0,   460,     0,     0,   352,   443,   450,     0,   358,   449,
       0,   472,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   247,     0,   212,   214,     0,   521,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    74,     0,   409,   408,
     422,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     392,   380,     0,   382,   383,   384,   385,   386,   387,   388,
       0,     0,     0,   504,     0,   509,   500,   501,   502,     0,
       0,     0,     0,     0,   505,   506,   507,   428,   511,   121,
     126,    99,     0,   497,   499,     0,   406,   412,   413,   493,
       0,     0,     0,     0,     0,     0,     0,    93,     0,     0,
       0,     0,   414,     0,     0,     0,     0,   517,     0,     0,
       0,    44,     0,     0,     0,    57,     0,    35,    36,    37,
      38,    39,   411,   410,     0,   490,    24,    22,     0,     0,
      25,     0,     0,   217,   516,    70,   110,    71,   118,     0,
       0,     0,   478,   479,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   305,   310,   308,     0,   318,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,   215,     0,     0,     0,   177,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   288,     0,   250,     0,
       0,     0,     0,     0,     0,   312,   321,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   408,     0,   473,
       0,   452,     0,     0,     0,     0,     0,     0,     0,   444,
       0,     0,     0,     0,     0,     0,     0,     0,   207,     0,
       0,     0,     0,   209,     0,     0,   348,     0,     0,     0,
       0,   518,     0,     0,     0,   417,     0,   416,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,     0,     0,     0,     0,    84,
      89,    91,     0,     0,   486,     0,    97,     0,     0,     0,
       0,     0,    75,   370,     0,     0,     0,     0,     0,    30,
     419,   418,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,     0,     0,     0,
       0,     0,     0,     0,   316,     0,     0,   134,     0,   137,
       0,   140,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   294,     0,   293,     0,   299,     0,   301,     0,   295,
       0,   297,     0,   260,   289,     0,     0,     0,   200,     0,
       0,     0,   323,     0,   204,   203,   343,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,   461,   462,
     463,   464,   451,   445,     0,     0,     0,     0,   483,     0,
       0,     0,   236,     0,     0,     0,     0,     0,    87,     0,
      86,     0,    76,   219,   421,   218,   381,   389,   390,   391,
     510,     0,   425,   426,   427,     0,     0,   405,   122,     0,
     514,   127,   424,   498,    78,    59,     0,     0,     0,     0,
      77,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   438,     0,     0,    26,    27,     0,
      28,     0,     0,   111,   114,    72,    73,   148,     0,     0,
       0,     0,     0,     0,   151,     0,     0,   167,   168,     0,
       0,   153,   174,     0,     0,     0,     0,   144,     0,   315,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   221,     0,     0,     0,     0,   187,   187,     0,   270,
       0,   272,     0,   274,     0,   440,     0,     0,   300,   302,
     296,   298,     0,     0,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   320,     0,   421,   474,     0,     0,
       0,     0,   475,   156,   157,     0,     0,     0,     0,   100,
     104,     0,     0,   349,    80,    79,     0,   423,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,    95,     0,
     487,   189,   190,   191,   192,     0,     0,    40,     0,     0,
       0,     0,     0,    42,   491,     0,     0,   112,   115,     0,
       0,   147,   154,   155,   159,     0,     0,   169,     0,     0,
     317,     0,   162,     0,     0,   306,   173,   149,   161,   172,
     176,   160,     0,   170,   175,     0,     0,     0,     0,     0,
       0,   437,     0,   436,     0,     0,     0,   261,     0,     0,
     262,     0,     0,   263,     0,     0,     0,     0,     0,     0,
       0,   199,     0,     0,   198,     0,     0,     0,   193,     0,
       0,    33,     0,     0,     0,     0,     0,     0,   481,     0,
     238,   237,     0,     0,     0,     0,     0,   503,   508,     0,
     123,   125,     0,   128,   129,   130,    90,    92,     0,    98,
       0,    81,    45,     0,     0,     0,   439,     0,     0,     0,
      29,     0,   121,   126,     0,     0,     0,     0,     0,     0,
       0,     0,   163,     0,   313,   313,     0,   105,   106,   187,
       0,   180,   181,     0,     0,     0,     0,     0,     0,     0,
     290,     0,     0,   187,     0,     0,     0,     0,     0,   184,
     183,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     102,     0,    82,     0,   476,     0,     0,   485,     0,    41,
       0,     0,     0,    43,    58,     0,     0,     0,   331,   333,
     332,   334,   335,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   304,     0,     0,
       0,   255,     0,     0,   194,     0,     0,     0,     0,     0,
       0,     0,   480,   239,     0,   350,     0,   124,     0,   131,
      96,     0,     0,     0,     0,     0,   113,   116,     0,     0,
       0,     0,     0,   314,   324,     0,     0,   325,     0,   178,
       0,   276,     0,     0,   278,     0,     0,   280,     0,     0,
       0,   291,     0,   251,     0,   187,     0,     0,     0,     0,
       0,     0,     0,   158,   103,     0,   119,     0,    49,     0,
      55,     0,     0,     0,   145,   171,     0,   328,     0,   329,
     330,   434,   264,     0,     0,   271,   265,     0,     0,   273,
     266,     0,     0,   275,     0,     0,     0,   257,     0,   197,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   282,     0,   284,     0,
     286,   292,   303,   256,   252,     0,     0,     0,     0,     0,
       0,     0,     0,   120,    46,     0,    53,     0,     0,     0,
       0,     0,     0,   267,     0,     0,   268,     0,     0,   269,
       0,     0,   201,     0,   195,     0,     0,     0,     0,     0,
      47,     0,     0,   228,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,     0,     0,   277,     0,   279,     0,
     281,     0,   196,     0,     0,     0,     0,    48,    50,     0,
      51,     0,     0,     0,     0,     0,     0,   465,   466,   467,
     468,     0,     0,    56,   326,   327,   283,   285,   287,    52,
      54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    91,   938,    92,    93,   686,  1406,  1412,
     927,  1114,  1578,  1779,   928,  1728,  1819,   929,  1781,   930,
     931,  1118,   348,   439,   184,   418,    94,   701,   450,  1522,
    1523,   451,  1573,  1089,  1258,  1090,  1261,   735,   738,   741,
     744,  1434,  1301,   666,   299,   412,   413,    97,    98,    99,
     100,   101,   102,   103,   300,  1019,  1674,  1745,   770,  1458,
    1461,  1464,  1703,  1707,  1711,  1764,  1767,  1770,  1015,  1016,
    1153,   975,   732,   779,  1600,   105,   106,   107,   108,   301,
     186,   889,   500,   257,  1283,   302,   303,   304,   563,   313,
     911,  1105,   448,   444,   890,   449,   189,   306
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1353
static const yytype_int16 yypact[] =
{
    6971,    71,    83,  7091, -1353, -1353,  3482,    20,   -40,   -89,
      -4,    15,   125,   129,   252,   269,    82,   280,   343,   111,
     171,   -15,   -15,  -159,   185,   202,    25,   209,   215,     1,
     258,   272,   374,   395,   458,   480,   339,   481,   482,   498,
     460,   472,   544,   584,   208,   386,   510,   -66,   391,   -94,
     -94,   408,   418,    61,   120,   508,   520,     8,    60,   525,
     536,   237,   615,   621,   633,  4824,   634,   436,   457,   478,
      19,    56, -1353,   506,   511, -1353, -1353,   649,   653,   512,
   -1353,  5297,  5689,     6,    34, -1353, -1353, -1353,  6831,  6831,
     513, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353,    51, -1353,   151,
     123, -1353,    36, -1353, -1353, -1353, -1353, -1353,   -15,   -15,
     -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,
     -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,
     -15,   -15,   -15,   523,   533,   534,   540,   541,   547,   -15,
     -15,   -15,   -15,   555, -1353,   -15, -1353, -1353, -1353, -1353,
   -1353,   -15,   -15,   749,   567,   573,   577,   -15,   590,   604,
   -1353, -1353, -1353, -1353,   582,  6831,  6831,  6831,  6831,  6831,
      31,    14,    52,   611,   410,   462, -1353,   650,   813,   299,
      -7,   827,  6831,  5493,  5493, -1353,  6831, -1353, -1353, -1353,
   -1353,  5493, -1353, -1353, -1353, -1353, -1353, -1353,  1262,    14,
    6831,  6641,  6831,  6831,   671,  6831,  6641,  6831,  6831,   677,
    6641,  6831,  6831,  5216,   687,   686, -1353,  6641,  4824,  4824,
    4824,   711,   717,  4824,  4824,  4824,   721,   736,   753,   763,
     767,   771,   772,   782,   694,  6196,   905,  5216,    19,   734,
     768,   -94,   -94,   -94,  6831,  6831,    90, -1353,   165,   -94,
     784,   797,   798,  6255,   184,  -109,   843,   847,   848,  4824,
    4824,  5216,   899,    12,   807, -1353,   891,  1103,  1106, -1353,
     920,   921,   922,  4824,  4824,   923,   930,   931,   517, -1353,
     932,    -1,    17,    26,    27,   693,  5412,  6831,  3968, -1353,
   -1353,  3555, -1353,  1122, -1353,   355,  -136,  1126,  6831,  6831,
    6831,   934,  6831,   933,   993,  6831,  6831,  6831, -1353, -1353,
    6831,   935,  1132,  1134, -1353, -1353,  1137, -1353,  1140, -1353,
     -97,   741,  7814,  5493, -1353,  5216,  5216,  6831,  6831,   946,
     588,  1262, -1353, -1353, -1353, -1353, -1353, -1353,  5216,  1145,
     955,  6831,  6831,  1152,  6831,  6831,  6831,  6831,  6831,  6831,
    6831,  6831,  6831,  6831,  6831,  6831,  6831,  6831,  6831,  6831,
    6831,  6831,  6831,  6831,  6831,  6831,  5493,  5493,  5493,  5493,
    5493,  5493,  5216,  5493,  5493,  6831,  5493,  5493,  5493,  5493,
    5493,  6831,  1262,  6831,  5493,  5493,  5493,  5493,    14,  1262,
      14,   962,   962,   962,  4528,  8958,   131,   959,  1157,   -15,
     961, -1353,   971,  5848,  6831, -1353, -1353,  6641,   138, -1353,
    6831,  6831,  6831,  6831,  6831,  6831,  6831,  6831,  6831,  6831,
    6831,  6831,  6831,  6831,  6831, -1353, -1353,  6831,  6831, -1353,
   -1353,   830,    -5,  -173, -1353, -1353,  -131,  5211, -1353,  -107,
     210,   267,   975,   977,  9303,  6641,  4130, -1353,   126,  9324,
    9345,  6831,  9366,   226,  9387,  9408,  6831,   488,  9429,  9450,
    1174,  6831,  6831,   494,  1178,  1182,  1183,  6831,  6831,  1185,
    1186,  1186,  6831,  6451,  6451,  6451,  6451,  6831,  6831,  6831,
    6641,  6641,  7841,   998,  1191,   995, -1353, -1353,   140, -1353,
   -1353,  5407,  5603,   -94,   -94,    52,    52,   246,  6831,  6831,
    6831,  6255,  6255,  6831,  5848,   263, -1353,  6831,  6831,  6831,
    6831,  6831,  1209,  1211,  1212,  6831,  1215,  6831,  6831,  1090,
   -1353, -1353,  6641,  6641,  6641,  1216,  1217,  6831,  6831,  6831,
    6831,  6831,  1214,   591,    14, -1353,  1175,  6831, -1353,  1176,
   -1353,  1177, -1353,  1179,    41,    42,    43,    46,  6641,   962,
   -1353,  9471, -1353,   552,  6831,  5608, -1353,  6831,  6831,   608,
   -1353,  9492,  9513,  9534,  1088,  5995, -1353,  1028,  4314,  9555,
    9576,  8981, -1353, -1353, -1353,  1488, -1353,  2134,  6831, -1353,
   -1353,  1034,  1038,   575,  9597,  9004,  6831,  6641,   138,  1232,
    1233, -1353,  6831,  9618,  9027,     5,  8935,  8935,  8935,  8935,
    8935,  8935,  8935,  8935,  8935,  8935,  8935,  6250,  8935,  8935,
    8935,  8935,  8935,  8935,  8935,  6636,  7895,  7921,   613,   627,
     613,  1042,  1043,  1039,  1044,  1050,  1053,  7947,   599,   599,
     599,    66,   599,   -62, -1353,  1024,  1055,  1062,   160,   599,
    1065,  1066,  1068,   147,   108,  1262,  6831,  1259,  1266,    24,
     599, -1353,   -65,    39,    30,   -64, -1353,  6191,   629, -1353,
    5216,  4593,  1649,  1857,   236,   236,   572,   572,   572,   572,
     594,   594,   962,   962,   962,   962,    16,  9639,  9050, -1353,
    6831,  1269,    11,  6641,  1268,  6641,  6831,  1271,  5493,  1272,
   -1353,    14,  1273,  5493,  6831,  1262,  1274,  6641,  6641,  1139,
    1276,  1277,  9660,  1278,  1144,  1281,  1283,  9681,  1148,  1285,
    1287,  6831,  9702,  6347,  1071, -1353, -1353, -1353,  9723,  9744,
    6831,  5216,  1289,  1290,  9765,  1082,   -62,  1095,  1101,   -62,
    1098,  1110,   -62,  1112,  1111,   -62,  1113,  9786,  9807,  9828,
     646,   647,  6641,  1117, -1353, -1353,  2300,  2347,   -94,  6831,
    6831, -1353, -1353,  1123,  1124,  6255,  7973,  7999,  8025,  5015,
     241,   -94,  2630,  9849,  6375,  9870,  9891,  9912,  6831,  1316,
   -1353,  6831,  9933, -1353,  9073,  9096, -1353,   655,   659,   660,
   -1353, -1353,  9119,  9142,  8051,  9165,  -136,  6641, -1353,  1131,
    1128,  6407,  1129,  1130,  1133, -1353,  6641, -1353,  6641, -1353,
    6641, -1353,  6641,   664, -1353, -1353,  4958,  6641,   962, -1353,
    6641, -1353,  1329,  1332,  1334,  1146,  6831,  2723,  6831,  6831,
   -1353, -1353,    48, -1353, -1353,  2887, -1353,  1141,  5216,  1342,
     147,   147,  6579,   670,  5216, -1353, -1353,  9188,  -136,  1435,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353,  6831, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
    6831,  6831,  6831, -1353,  6641, -1353, -1353, -1353, -1353,  5493,
    5216,  5493,  5493,  1262, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353,  6831, -1353, -1353,  5493, -1353, -1353, -1353, -1353,
    6831,  1343,    33,  6831,  1345,  1346,  1523, -1353,  1359,  1168,
      19,  1362, -1353,  6641,  6641,  6641,  6641, -1353,   599,  1367,
    6831, -1353,  1184,  1189,  1170, -1353,  1374, -1353, -1353, -1353,
   -1353, -1353,  -136,  -136,  9211, -1353, -1353,  1198,  5493,   303,
   -1353,   304,  8077, -1353, -1353, -1353,  1381, -1353, -1353,  8935,
     599,   -94,  4130, -1353,   801,  5216,  5216,  1382,  5216,   809,
    5216,  5216,  1383,  1307,  5216,  5216,  1689,  1385,  1386,  6641,
    1388,  1390,  3692, -1353, -1353,  1392, -1353,  1393,   138,  6831,
     138,  6831,   138,  6831,   138,  6831,  1394,  1395,  1396,  1401,
    1402,   691,  1410,  3037, -1353, -1353,   277,  8103,  8129, -1353,
   -1353,  6726,  -106,   -94,   -94,   -94,  1411,  1416,  1195,  1417,
    1219,    38,    47,    55,    57,   -13, -1353,   348, -1353,   241,
    1418,  1420,  1422,  1423,  1424,   -62, -1353,  1765,  1213,  1421,
    1427,  1428,  1354,  6831,  1431,  1432,  6831,   262,   692, -1353,
    6831, -1353,  6831,  6831,  6831,   696,   701,   702,   712, -1353,
    6831,   731,   738,  5216,  5216,  5216,  1437,  8155, -1353,  4977,
     336,  1438,  1440, -1353,  5216,  1240, -1353,  6831,  1441,  6831,
    1442, -1353,   599,  1443,  1444, -1353,  1447, -1353,  1449,  8935,
    8935,  8935,  8935,   628,  1221,  1248,  1260,  1261,  1254,   644,
     645,  9954,  1263,  1808, -1353,   161,  1264,  1453,  2099, -1353,
   -1353, -1353,    19,  6831, -1353,   743, -1353,   744,   751,   760,
     770,   138, -1353,   -62,  1265,  6831,  6831,  5216,  1267, -1353,
   -1353, -1353,  1280, -1353,  1457,    70,  1460,  6831,  3402,  1461,
    1462,    69,  1270,  1279,  1378,  1378,  5216,  1466,  1291,  1298,
    1467,  1476,  5216,  1299,  1484,  1498, -1353,  1500,  5216,   775,
    5216,  5216,  1502,  1501, -1353,  5216,  5216,   -62,  5216,   -62,
    5216,   -62,  5216,   -62,  5216,  5216,  5216,  1306,  1308,  1504,
     144, -1353,  6831,  6831,  6831,  1309,  1311,  -118,   -26,   159,
    1317, -1353,  5216, -1353,  6831, -1353,  1514, -1353,  1515, -1353,
    1516, -1353,  1521, -1353, -1353,  6255,   616,  5020, -1353,  1324,
    1327,  5804, -1353,  6641, -1353, -1353, -1353,  1328,  2380, -1353,
   -1353,  9234,  1530,   599,  8181,  8207,  8233,  8259, -1353, -1353,
   -1353, -1353,   -62, -1353,   599,  1529,  1531,  1397, -1353,  6831,
    6831,  6831, -1353,  1532,   383,  1336,  1534,  2600, -1353,  2821,
   -1353,   138, -1353, -1353,    97, -1353, -1353, -1353, -1353, -1353,
   -1353,  5493, -1353, -1353, -1353,  1262,  1537, -1353, -1353,     9,
   -1353, -1353, -1353, -1353, -1353,  1262,  6831,  1536,  1540,    24,
   -1353,  1542,  9257,    19, -1353,  1544,  1545,  1547,  1550,  5216,
    6831,  8285,  8311,   781, -1353,  6831,  1553, -1353, -1353,  5493,
   -1353,  8337,  4171,   -62, -1353, -1353, -1353, -1353,  6831,  6831,
     -94,  1554,  1555,  1556, -1353,  6831,  6831, -1353, -1353,  1557,
    6831, -1353, -1353,  1569,  1570,  1355,  1571,  1436,  6831, -1353,
    1572,  1576,  1580,  1581,  1582,  1584,   981,  1585,  6641,  6641,
    6831, -1353,  6451,  6754,  9975,  3963,    52,    52,   -94,  1589,
     -94,  1593,   -94,  1594,  6831,   257,  1398,  9996, -1353, -1353,
   -1353, -1353,  7086,   350, -1353,  1600,  3753,  1603,  5216,   -94,
    3753,  1604,   786,  6831, -1353,  1608,  -136, -1353,  6831,  6831,
    6831,  6831, -1353, -1353, -1353,  5216,  5938,   388, 10017, -1353,
   -1353,  4563,  5216, -1353, -1353, -1353,  5216, -1353,  1429,   599,
    4367,  4628,  1262,  1610,  3139, -1353,  1615,  1620, -1353,  1430,
   -1353, -1353, -1353, -1353, -1353,  1622,   330,   -62,  6831,  6831,
    5216,  1433,   789,   -62, -1353,  1627,  6831, -1353, -1353,  7114,
    7142,   321, -1353, -1353, -1353,  7170,  7198, -1353,  7226,  1633,
   -1353,  5216, -1353,  1559,  1637,   -62, -1353, -1353, -1353, -1353,
   -1353, -1353,  1446, -1353, -1353,   790,   793,  7868,  3187,  1638,
    1450, -1353,  6831, -1353,  1448,  1451,   362, -1353,  1454,   394,
   -1353,  1470,   398, -1353,  1472,  9280,  1639,  5216,  1650,  1475,
    6831, -1353,  6000,   400, -1353,   794,   404,   429, -1353,  1674,
    7254, -1353,  8363,  8389,  8415,  8441,  1543,  6831, -1353,  6831,
   -1353, -1353,  6641,  3434,  1676,  1478,  1678, -1353, -1353,  3968,
   -1353, -1353,  5493,   -62, -1353, -1353, -1353, -1353,    19, -1353,
    1548, -1353, -1353,  6831,  8467,  8493, -1353,  5216,  6831,  1679,
   -1353,  8519, -1353, -1353,  1680,  1681,  1684,  1685,  1686,  1688,
     819,  1492, -1353,  5216,   579,   720,  6641, -1353, -1353,    52,
    6152, -1353, -1353,  6255,   241,  6255,   241,  6255,   241,  1691,
   -1353,   820,  5216, -1353,  7282,   -94,  1693,  6641,   -94, -1353,
   -1353,  6831,  6831,  6831,  6831,  6831,  7310,  7338,   826, -1353,
   -1353,  1709, -1353,   829,  4109,   832,  1710, -1353,  1513,   -62,
    6831,  6831,   833,   -62, -1353,  6831,   838,   854, -1353, -1353,
   -1353, -1353, -1353, -1353,  1524,  6831,   857,  1525,   -94,  5216,
    1712,  1526,   -94,  1720,   860,  1527,  6831, -1353,  7366,   469,
     762,  7394,   474,   929,  7422,   486,  1125, -1353,  5216,  1729,
    1644,  4026,  1533,   491, -1353,   861,   493,  8545,  8571,  8597,
    8623,  3513, -1353, -1353,  1730, -1353,  6831, -1353,  1262, -1353,
   -1353,  6831, 10038,  8649,    35,  8675, -1353, -1353,  6831,  7450,
    1743,   -94,    74, -1353, -1353,   -94,    86, -1353,  1744, -1353,
    7478,  1745,  6831,  1747,  1748,  6831,  1749,  1754,  6831,  1759,
    1564, -1353,  6831, -1353,   241, -1353,  6641,  1764,  6000,  6831,
    6831,  6831,  6831, -1353, -1353,  1481, -1353,   889, -1353,  6831,
   -1353,  5216,  6831,  8701, -1353, -1353,   499, -1353,   519, -1353,
   -1353, -1353, -1353,  1568,  7506, -1353, -1353,  1577,  7534, -1353,
   -1353,  1578,  7562, -1353,  1768,  3716,  1251,  4866,   890, -1353,
     522,   902,  8727,  8753,  8779,  8805,  1262,  1769,  1579, 10059,
     903,  7590,  6831,   -94,   -94,   241,  1774,   241,  1778,   241,
    1779, -1353, -1353, -1353, -1353,   241,  1780,  6641,  1781,  6831,
    6831,  6831,  6831, -1353, -1353,  5493, -1353,  1586,  1783,  7618,
     545,   563,  1286, -1353,  1588,  1399, -1353,  1590,  1493, -1353,
    1591,  1522, -1353,   910, -1353,  8831,  8857,  8883,  8909,   914,
   -1353,  1595,  5216, -1353,  1787,  6831,  6831,  1791,   241,  1796,
     241,  1797,   241, -1353,  1798,  6831,  6831,  6831,  6831,  5493,
    1799,  5493,   915, -1353,  7646,  7674, -1353,  1621, -1353,  1971,
   -1353,  2139, -1353,  7702,  7730,  7758,  7786, -1353, -1353,   918,
   -1353,  1800,  1801,  1802,  1804,  1805,  1806, -1353, -1353, -1353,
   -1353,  5493,  1807, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1353, -1353, -1353, -1353,   690, -1353, -1353, -1353, -1353,   175,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353,  -382,   -95,   949,  1549, -1353,  1366, -1353, -1353,
   -1353, -1353, -1353,   296, -1353,   298, -1353, -1353, -1353, -1353,
   -1353, -1353,   684,  1820,     7,  -497,  -256, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353,  1821, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,  -935,  -989,
   -1353, -1353,  1344, -1353,   292, -1353, -1353, -1353, -1353,  1546,
   -1353, -1353,     0, -1353, -1352,  2198,   401,  2392,   449,  -246,
     578, -1353,    21,    62, -1353,  -375,    -3,    95
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -492
static const yytype_int16 yytable[] =
{
     109,   628,   495,   630,   545,   219,  1475,   514,   763,   764,
      96,   326,   273,  1391,   641,   349,   526,   936,   321,   529,
     921,   195,   548,   311,   656,   692,  1194,   187,   909,   214,
     693,   550,   552,   191,   219,   406,   670,  1095,   210,   328,
     350,  1690,   192,   214,  1185,   211,   805,   807,   809,   256,
     258,   811,   264,  1187,   276,  1061,   410,   334,   346,   347,
     314,  1189,   305,  1191,   278,   265,   279,   694,   188,   503,
     504,   585,   695,   587,   248,  1297,  1288,     4,   276,  1530,
    1697,   503,   504,     5,  1196,  1338,  1006,  1339,   517,   249,
     250,   697,  1699,   252,   253,   518,   698,  1007,   110,  1176,
     351,   190,   588,   254,   542,  1008,  1009,  1010,   193,   183,
     255,  1011,  1012,  1013,  1014,   669,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     341,   197,   210,   222,   434,   198,   280,   266,   655,   913,
     916,   267,   546,   322,   325,   669,   922,   923,   924,   925,
    1331,  1332,   277,   268,   669,    48,    49,    50,    51,   274,
     549,   503,   504,  1392,    56,  1582,  1186,    59,  1265,   551,
     553,   407,   408,  1096,  1097,  1188,   323,  1340,   276,  1341,
      90,  1596,   206,  1190,   207,  1192,    90,   346,   347,   411,
     276,   276,  1193,   194,   690,   937,   691,  -489,   276,   346,
     347,   183,   269,   547,   270,   220,   276,  1194,   305,  -490,
     327,   527,   275,   305,   443,   446,   844,   305,   183,   196,
     305,   926,   215,   312,   305,   305,   305,   305,   910,   216,
     305,   305,   305,   351,   915,   352,   215,   353,   329,  1691,
     756,   757,   183,   914,   305,   806,   808,   810,   335,  1062,
     812,   498,   499,   315,   937,   336,   503,   504,   199,   507,
     772,   503,   504,   515,   887,   564,   305,   305,   305,   698,
     452,   900,   903,   503,   504,   200,   409,   503,   504,   201,
     305,   305,   342,   343,   344,   345,   202,   244,   445,   445,
     245,   346,   347,   305,   505,   305,   445,   342,   343,   344,
     345,  -491,   346,   347,   453,   342,   343,   344,   345,   902,
     204,   657,   342,   343,   344,   345,   283,   346,   347,   284,
     827,   342,   343,   344,   345,   346,   347,   503,   504,   708,
     276,   709,   305,   305,   835,   342,   343,   344,   345,  1730,
    1006,   346,   347,   758,  1231,   305,   503,   504,   337,   203,
     338,  1007,   503,   504,   591,   346,   347,   339,   894,  1008,
    1009,  1010,  1342,   895,  1343,  1011,  1012,  1013,  1014,   506,
     205,   503,   504,   276,   276,   276,   276,   276,   276,   305,
     276,   276,   212,   276,   276,   276,   276,   276,   516,  1380,
    1381,   276,   276,   276,   276,   276,  1489,   276,   629,   213,
     631,   632,   633,   599,   635,   636,   217,   638,   639,   640,
     699,   642,   218,   700,   305,   646,   647,   648,   649,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   445,   708,
    1802,   714,   434,   503,   504,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   565,   432,   433,   765,
     503,   504,   305,   434,   644,   221,   346,   347,  1067,  1069,
     223,   651,  1466,  1212,   503,   504,   771,   702,   419,   222,
     700,   445,   445,   445,   445,   445,   445,   224,   445,   445,
    1172,   445,   445,   445,   445,   445,   226,   305,   305,   445,
     445,   445,   445,   650,   260,   652,   437,   261,   438,   993,
     262,  1125,  1126,   761,   762,   339,   708,   708,   503,   504,
     850,   499,   411,   411,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,  1512,   305,
     305,   305,   434,  1513,  1232,   503,   504,   503,   504,   233,
     225,   276,   234,   227,   235,   737,   740,   743,   746,   503,
     504,  1195,   567,  1470,   568,   305,   236,   228,   901,   904,
     229,   339,   305,   230,   231,  1543,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     232,   503,   504,   246,   434,   503,   504,   503,   504,   247,
     271,   503,   504,  1490,   305,   251,  1156,  1545,  1158,   272,
    1160,  1547,  1162,  1555,   281,   252,   253,  1557,   415,  1610,
     416,  1613,   259,  1616,   417,   254,   503,   504,   282,   285,
     237,  1194,   263,   238,  1194,   286,   239,  1194,   240,   474,
     475,   476,  1558,   308,   479,   480,   481,   287,   307,   799,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   309,   318,   503,   504,   434,   319,
     458,   503,   504,   241,  1104,   463,   242,   305,   243,   467,
     522,   523,  1662,   503,   504,   310,   473,  1665,   503,   504,
     503,   504,  1597,  1598,   535,   536,   503,   504,  1599,  1668,
     305,   708,   305,   718,  1676,   276,  1678,   708,   276,   724,
     276,   850,  1733,   316,   305,   305,   503,   504,   317,   503,
     504,   320,   333,  1266,   540,  1006,   541,   905,   542,   944,
     379,   182,  1734,   183,   948,  1747,  1007,  1194,   305,  1279,
     380,   381,   503,   504,  1008,  1009,  1010,   382,   383,  1716,
    1011,  1012,  1013,  1014,   384,  1068,  1070,   589,  1785,   305,
     503,   504,   389,  1075,  1077,   708,   393,   815,   996,   429,
     430,   431,   432,   433,   394,  1002,  1786,   950,   434,   554,
     395,  1017,   555,  1194,   396,   556,  1194,   557,   838,  1194,
     839,   400,  1194,   431,   432,   433,   415,   398,   416,   415,
     434,   416,   597,   445,   305,   797,   946,   415,   445,   416,
    1762,   399,  1765,   305,  1768,   305,   415,   305,   416,   305,
    1771,   415,   820,   416,   305,   414,   698,   305,  1194,   436,
    1194,  1354,  1194,  1601,  1602,   415,   415,   416,   416,  1599,
     874,   708,   708,   440,   918,   305,   689,  1120,  1121,  1454,
    1455,   305,   415,   415,   416,   416,   276,  1256,  1259,   708,
     708,   989,   990,  1807,   435,  1809,  1271,  1811,   708,  1386,
    1031,  1006,   708,   708,  1032,  1033,   668,   708,   461,  1049,
    1078,   305,  1007,   708,   466,  1072,   276,   305,   276,   276,
    1008,  1009,  1010,  1132,   471,  1133,  1011,  1012,  1013,  1014,
     472,  1138,   276,  1139,   708,   708,  1169,  1213,   490,   708,
    1084,  1218,  1086,  1087,   708,   708,  1219,  1220,   477,   493,
     305,   305,   305,   305,   478,   708,  1092,  1221,   482,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   483,   708,   276,  1223,   434,   496,   750,
     751,   708,  1077,  1224,   445,  1088,  1273,   708,  1274,  1275,
     484,  1131,   305,   305,   708,   305,  1276,   305,   305,  1124,
     485,   305,   305,   708,   486,  1277,   305,  1663,   487,   488,
     208,   209,   497,   708,   445,  1278,   445,   445,   708,   489,
    1315,   787,   788,   789,  1410,  1442,  1411,  1443,   508,   708,
     445,  1479,  1518,   708,  1519,  1534,   708,  1410,  1535,  1556,
    1267,   509,   510,  1177,  1178,  1179,   528,   813,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,  1410,  1618,  1594,  1619,   434,  1400,  1006,   708,
     891,  1634,  1636,   445,  1637,   698,  1410,  1639,  1644,  1007,
     519,  1256,  1605,  1646,   520,   521,   843,  1008,  1009,  1010,
     305,   305,   305,  1011,  1012,  1013,  1014,  1259,   340,  1647,
    1410,   305,  1650,   708,   708,  1658,  1677,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,  1518,   708,  1727,  1746,   525,   339,   385,   386,
     387,   388,     7,     8,   390,   708,  1410,  1748,  1757,   530,
     391,   392,   531,   708,   305,  1794,   397,  1799,  1410,  1800,
    1821,  1831,   537,  1832,   532,   533,   534,  1575,   566,   538,
     539,   544,   570,   305,  1666,   574,   577,   576,   582,   305,
     583,   183,   939,   584,   941,   305,   586,   305,   305,  1387,
     596,   601,   305,   305,   602,   305,   605,   305,   434,   305,
     658,   305,   305,   305,   659,   182,   662,    24,    25,   663,
      27,    28,   664,    30,   665,    32,   661,    33,   704,   305,
     705,   721,    38,    39,   725,    41,    42,    43,   726,   727,
    1294,    46,   730,   731,   305,  1353,   753,   754,   305,   755,
     305,   991,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   778,   780,   796,   781,
     434,   783,   790,   791,  1006,    67,    68,    69,   825,   800,
     802,   803,   828,   804,   836,  1007,   837,   543,   845,   846,
     877,   878,   879,  1008,  1009,  1010,  1038,   880,   276,  1011,
    1012,  1013,  1014,   881,   569,  1045,   882,  1046,   892,  1047,
     893,  1048,  1576,   897,   898,   907,  1051,   113,   899,  1052,
     908,  1387,  1388,   935,   940,   969,   305,   943,   945,   947,
     978,   951,   954,   955,   956,   958,   276,   959,   960,   305,
     961,   963,   964,   974,   965,   786,   976,  1621,   979,   980,
    1421,   981,   140,   141,   142,   143,   144,   145,   982,   984,
    1415,   149,   150,   151,   152,   983,   985,  1389,   992,   154,
     155,   156,  1026,  1083,   157,   305,   305,  1393,   999,  1000,
    1669,  1039,  1040,  1042,  1043,   162,  1053,  1044,  1456,  1054,
    1459,  1055,  1462,   411,   411,  1064,   445,  1056,  1066,  1094,
    1006,  1099,  1100,   305,  1418,   305,  1473,   305,   660,  1476,
    1477,  1007,  1107,  1108,  1109,  1110,  1102,  1103,  1106,  1008,
    1009,  1010,   305,  1112,  1117,  1011,  1012,  1013,  1014,   305,
    1119,  1115,  1123,   305,   445,  1006,  1116,   305,  1128,  1136,
    1142,  1143,  1147,  1148,  1449,  1150,  1007,  1151,  1154,  1182,
    1155,  1164,  1165,  1166,  1008,  1009,  1010,   305,  1167,  1168,
    1011,  1012,  1013,  1014,  1170,  1180,  1184,  1203,  1149,  1717,
     165,   166,  1181,  1183,  1251,  1197,  1198,  1204,   305,  1199,
    1200,  1201,   173,  1205,  1206,   174,  1207,  1209,  1210,   442,
     113,  1228,  1233,  1494,  1234,  1236,  1252,  1238,  1240,  1242,
    1243,  1244,  1501,  1504,  1505,  1245,  1743,  1255,  1253,  1254,
    1269,  1263,  1280,  1287,   305,  1268,  1290,  1295,  1296,   305,
    1300,  1285,  1304,  1307,  1298,   140,   141,   142,   143,   144,
     145,  1286,  1308,  1299,   149,   150,   151,   152,  1726,   305,
    1311,  1787,   154,   155,   156,  1305,   305,   157,  1006,   276,
       7,     8,  1306,  1310,  1312,  1313,  1318,  1319,   162,  1007,
    1328,  1330,  1329,  1336,   305,  1337,  1344,  1008,  1009,  1010,
    1348,  1349,  1350,  1011,  1012,  1013,  1014,  1351,  1358,  1101,
     305,  1359,  1363,   305,  1366,  1373,  1375,  1374,  1379,  1382,
    1383,  1390,  1395,  1609,  1396,  1612,   411,  1615,  1398,   305,
    1401,  1402,   185,  1403,   305,  1623,  1404,  1414,  1626,  1431,
    1422,  1423,  1424,  1427,   662,    24,    25,   663,    27,    28,
     664,    30,   665,    32,  1429,    33,  1430,  1432,  1436,  1433,
      38,    39,  1437,    41,    42,    43,  1438,  1439,  1440,    46,
    1441,  1444,  1006,   165,   166,  1457,   305,   445,  1652,  1460,
    1463,  1467,  1656,  1007,  1789,   173,  1471,    90,   174,  1474,
    1478,  1008,  1009,  1010,  1481,   305,  1506,  1011,  1012,  1013,
    1014,  1006,  1508,    67,    68,    69,  1509,  1497,  1511,   346,
     347,  1510,  1007,  1520,   331,   332,  1076,  1517,  1529,  1531,
    1008,  1009,  1010,  1532,  1538,  1550,  1011,  1012,  1013,  1014,
    1533,  1696,  1362,  1541,  1539,  1698,  1542,  1552,  1544,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   305,  1546,   305,  1548,   434,  1720,  1553,
    1559,  1565,  1570,  1571,  1572,  1584,  1588,  1589,   305,  1577,
    1590,  1591,  1592,   833,  1593,  1146,  1595,  1617,  1791,  1624,
    1686,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,  1635,  1640,  1641,  1654,   434,
    1006,   401,   402,   403,   404,   405,  1657,  1793,  1648,  1651,
    1655,  1007,  1659,  1760,  1761,  1671,  1684,  1675,   441,  1008,
    1009,  1010,   447,  1672,   305,  1011,  1012,  1013,  1014,  1695,
    1700,  1702,   276,  1705,  1706,  1709,   454,   456,   459,   460,
    1710,   462,   456,   464,   465,  1713,   456,   468,   469,  1714,
    1719,  1202,  1735,   456,  1741,  1754,  1780,  1445,  1446,   305,
    1763,  1737,  1739,  1755,  1766,  1769,  1772,  1774,  1753,  1783,
    1782,   492,  1788,  1803,  1790,  1792,   276,  1806,   276,  1801,
     501,   502,  1808,  1810,  1812,  1818,  1833,  1834,  1835,   502,
    1836,  1837,  1838,  1840,  1264,  1289,  1687,   703,  1586,  1302,
    1817,  1587,  1820,    95,   104,   733,  1824,  1603,   276,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,   559,   561,   456,   434,     0,  1397,     0,     0,
     445,     0,  1839,     0,   571,   572,   573,     0,   575,     0,
       0,   578,   579,   580,     0,     0,   581,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,   594,   595,   434,     0,     0,     0,   598,
       0,     0,     0,     0,   445,     0,   445,   603,   604,     0,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,     0,     0,     0,     0,   445,     0,     0,     0,
       0,   637,     0,     0,     0,     0,     0,   643,     0,   645,
       0,  1568,     0,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
     667,   434,     0,   456,     0,     0,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,     0,     0,   687,   688,  1604,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,   559,     0,     0,   434,     0,  1625,   712,     0,     0,
       0,     0,   717,     0,     0,     0,     0,   722,   723,     0,
       0,     0,     0,   728,   729,     0,     0,     0,   734,   736,
     739,   742,   745,   747,   748,   749,   456,   456,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,   766,   767,   768,   401,   402,   769,
       0,     0,     0,   773,   774,   775,   776,   777,     0,     0,
    1006,   782,     0,   784,   785,     0,     0,     0,   456,   456,
     456,  1007,     0,   792,   793,   794,   603,   795,     0,  1008,
    1009,  1010,   798,   801,     0,  1011,  1012,  1013,  1014,     0,
       0,     0,     0,     0,   456,  1270,     0,     0,     0,     0,
     816,   818,     0,   687,   688,     0,     0,     0,   821,     0,
       0,     0,     0,     0,     0,  1718,     0,  1721,     0,     0,
       0,     0,     0,     0,   795,     0,     0,     0,     0,     0,
       0,     0,   842,   456,     0,     0,     7,     8,   847,     0,
       0,     0,     0,     0,     0,   851,   852,   853,   854,   855,
     856,   857,   858,   859,   860,   861,     0,   863,   864,   865,
     866,   867,   868,   869,     0,     0,  1825,   873,   875,   876,
       0,     0,     0,     0,     0,     0,     0,   884,   885,   886,
       0,   888,     0,     0,     0,     0,  1773,     0,   896,     0,
       0,     0,   906,     0,     0,     0,     0,     0,     0,   912,
     662,    24,    25,   663,    27,    28,   664,    30,   665,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,   934,     0,  1006,   456,
       0,   456,   942,     0,     0,     0,     0,     0,     0,  1007,
     949,     0,     0,   818,   952,     0,     0,  1008,  1009,  1010,
       0,     0,     0,  1011,  1012,  1013,  1014,   966,     0,    67,
      68,    69,     0,     0,     0,     0,   972,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,   456,     0,
       0,     0,     0,     0,     0,   997,   998,     0,     0,     0,
       0,  1001,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1025,     0,     0,  1027,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   834,
       0,     0,     0,   456,  1826,     0,     0,     0,     0,     0,
       0,     0,   456,     0,   456,     0,   456,     0,   456,     7,
       8,     0,     0,   456,     0,     0,   456,     0,     0,     0,
       0,     0,  1057,     0,  1059,  1060,   662,    24,    25,   663,
      27,    28,   664,    30,   665,    32,  1364,    33,     0,     0,
       0,     0,    38,    39,     0,    41,    42,    43,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,  1079,     0,
       0,     0,     0,     0,     0,     0,  1080,  1081,  1082,     0,
     456,   470,     0,   662,    24,    25,   663,    27,    28,   664,
      30,   665,    32,     0,    33,    67,    68,    69,  1091,    38,
      39,     0,    41,    42,    43,   494,  1093,     0,    46,  1098,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   456,
     456,   456,   456,     0,     0,     0,  1113,  1111,     0,   524,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1129,  1130,
       0,     0,     0,     0,     0,   994,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   456,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1157,     0,  1159,     0,  1161,
       0,  1163,     0,   592,   593,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   600,     0,     0,     0,
       0,     0,   995,     0,     0,     0,     0,     0,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,  1208,
     634,     0,  1211,     0,     0,     0,  1214,     0,  1215,  1216,
    1217,     0,     0,     0,     0,     0,  1222,     0,     0,     0,
       0,     0,     0,   457,     0,     0,  1384,     0,   457,     0,
       0,     0,   457,  1237,     0,  1239,     0,     0,     0,   457,
       0,  1241,     0,     0,     0,     0,     0,     0,  1246,  1247,
    1248,  1249,  1250,     0,     0,     0,     0,     0,  1257,  1260,
       0,     0,     7,     8,     0,     0,     0,     0,     0,  1272,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1281,  1282,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1291,  1293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   560,     0,
     457,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   662,    24,    25,   663,
      27,    28,   664,    30,   665,    32,     0,    33,  1333,  1334,
    1335,     0,    38,    39,     0,    41,    42,    43,  1345,     0,
    1347,    46,     0,     0,     0,     7,     8,     0,     0,     0,
       0,  1352,     0,     0,     0,     0,     0,     0,     0,   456,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1367,     0,     0,    67,    68,    69,     0,     0,
       0,     0,     0,  1372,     0,  1376,  1377,  1378,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,   662,
      24,    25,   663,    27,    28,   664,    30,   665,    32,   457,
      33,     0,  1394,     0,     0,    38,    39,     0,    41,    42,
      43,     0,     0,     0,    46,     0,  1407,  1385,     0,     0,
       0,  1413,     0,     0,     0,  1018,     0,     0,     0,     0,
       0,     0,     0,     0,  1419,  1420,     0,   560,     0,     0,
       0,  1425,  1426,     0,     0,     0,  1428,     0,    67,    68,
      69,     0,     0,     0,  1435,     0,     0,     0,   919,     0,
       0,     0,     0,     0,   456,   456,  1447,     0,  1448,     0,
       0,     0,   457,   457,     0,     0,     0,     0,     0,     0,
    1465,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,   456,     0,     0,     0,   456,     0,     0,  1480,
       0,     0,     0,     0,  1482,  1483,  1484,  1485,     0,     0,
       0,     0,     0,     0,   457,   457,   457,  1493,  1058,   973,
       0,     0,     0,     0,     0,     0,     0,  1503,  1498,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     457,     0,     0,     0,  1514,  1515,     0,   819,     0,     0,
       0,     0,  1521,   662,    24,    25,   663,    27,    28,   664,
      30,   665,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,   457,
       0,     0,     0,     0,     0,     0,     0,     0,  1540,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,  1554,   434,   559,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,  1566,     0,  1567,  1065,     0,   456,     0,
       0,     0,  1073,     0,     0,  1574,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,  1579,
       0,     0,     0,     0,  1583,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1085,     0,
       0,     0,   456,     0,     0,   457,     0,   457,     0,  1608,
       0,  1611,  1063,  1614,     0,     0,     0,     0,     0,   819,
     953,     0,     0,   456,     0,     0,     0,  1627,  1628,  1629,
    1630,  1631,     0,   662,    24,    25,   663,    27,    28,   664,
      30,   665,    32,     0,    33,     0,  1642,  1643,     0,    38,
      39,  1645,    41,    42,    43,     0,     0,     0,    46,     0,
       0,  1649,     0,     0,   457,  1507,     0,     0,     0,     0,
       0,     0,  1660,  1134,  1135,     0,  1137,     0,  1140,  1141,
       0,     0,  1144,  1145,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,  1685,     0,     0,     0,     0,  1413,     0,   457,
       0,     0,     0,  1537,  1693,     0,     0,     0,   457,     0,
     457,     0,   457,     0,   457,     0,     0,     0,  1704,   457,
       0,  1708,   457,     0,  1712,     0,     0,     0,  1715,     0,
       0,     0,   456,     0,   456,  1722,  1723,  1724,  1725,     0,
       0,     0,     0,     0,     0,  1729,     0,     0,  1731,     0,
       0,     0,  1171,     0,     0,     0,     0,     0,     0,     0,
       0,  1225,  1226,  1227,     0,     0,     0,     0,     0,     0,
       0,     0,  1235,     0,     0,     0,   457,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1759,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   456,     0,  1775,  1776,  1777,  1778,     0,
       0,     0,     0,     0,     0,   457,   457,   457,   457,     0,
       0,     0,     0,     0,     0,  1284,     0,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,  1804,  1805,     0,  1303,   434,     0,     0,     0,     0,
    1309,  1813,  1814,  1815,  1816,     0,  1314,     0,  1316,  1317,
       0,     0,     0,  1320,  1321,     0,  1322,     0,  1323,     0,
    1324,   457,  1325,  1326,  1327,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
    1346,     0,     0,   434,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1357,     0,     0,     0,  1361,
       0,     0,     0,     0,     0,   111,   330,   113,     0,     0,
       0,   114,   115,   116,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
    1569,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,     0,     0,     0,   154,
     155,   156,     0,     0,   157,     0,   158,   159,   160,     0,
       0,     0,     0,     0,   161,   162,     0,  1405,     0,     0,
       0,     0,     0,     0,     0,   111,   112,   113,     0,     0,
    1417,   114,   115,   116,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,  1683,
       0,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,     0,     0,     0,   154,
     155,   156,     0,     0,   157,     0,   158,   159,   160,     0,
       0,     0,     0,     0,   161,   162,  1284,     0,     0,   164,
     165,   166,   167,   564,     0,     0,     0,   168,   169,   170,
     171,   172,   173,  1486,    90,   174,     0,     0,     0,     0,
    1495,     0,     0,     0,  1496,     0,     0,     0,  1500,   175,
     176,     0,     0,     0,   177,   457,     0,     0,     0,   297,
       0,     0,     0,     0,   181,     0,  1292,     0,  1516,     0,
       0,     0,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,  1284,
     434,     0,     0,   163,     0,     0,     0,     0,     0,   164,
     165,   166,   167,     0,     0,     0,     0,   168,   169,   170,
     171,   172,   173,     0,    90,   174,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1551,     0,     0,     0,   175,
     176,     0,     0,     0,   177,     0,     0,     0,     0,   178,
       0,   179,     0,   180,   181,     0,   182,     0,   183,     0,
       0,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,  1284,     0,     0,     0,     0,
     457,   457,  1742,     0,     0,     0,     0,     0,     0,     0,
       0,  1284,     0,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   565,   432,   433,     0,   457,     0,
    1620,   434,   457,     0,     0,     0,   111,   288,     0,     0,
       0,     0,   114,   115,   116,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     290,  1152,     0,     0,     0,     0,     0,  1653,     0,   146,
     147,   148,     0,     0,     0,     0,   153,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1670,   158,   159,   160,
       0,     0,     0,     0,     0,   161,     0,     0,     0,   291,
       0,     0,   292,     0,     0,   293,     0,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,   560,    56,     0,     0,    59,     0,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   457,     0,     0,     0,   434,  1284,
       0,   457,     0,     0,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
     164,     0,   434,   167,     0,     0,     0,     0,   168,   169,
     170,   171,   172,     0,     0,    90,     0,     0,   457,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     511,  1472,     0,     0,     0,   177,     0,     0,     0,   457,
     513,     0,     0,     0,     0,   181,     0,   255,   562,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,   288,     0,     0,     0,     0,   114,   115,   116,
    1284,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   290,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,   148,     0,     0,     0,
       0,   153,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   158,   159,   160,     0,     0,     0,     7,     8,
     161,     0,     0,     0,   291,     0,     0,   292,     0,     0,
     293,     0,   294,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,     0,     0,     0,   457,     0,
     457,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   662,    24,    25,   663,    27,    28,   664,    30,
     665,    32,     0,    33,     0,     0,  1638,   564,    38,    39,
       0,    41,    42,    43,     0,   164,     0,    46,   167,     0,
       0,     0,     0,   168,   169,   170,   171,   172,   564,   457,
      90,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   175,   455,     0,     0,   434,
     177,    67,    68,    69,     0,   297,  1452,     0,  1453,     0,
     181,     0,     0,   562,   111,   288,   113,     0,     0,     0,
     114,   115,   116,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   290,     0,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,     0,     0,   154,   155,
     156,  1673,     0,   157,     0,   158,   159,   160,     0,     0,
       0,     0,     0,   161,   162,     0,     0,   291,     0,     0,
     292,     0,     0,   293,     0,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   707,   432,
     433,     0,     0,     0,     0,   434,     0,     0,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   707,
     432,   433,   829,     0,     0,     0,   434,     0,   164,   165,
     166,   167,     0,     0,     0,     0,   168,   169,   170,   171,
     172,   173,     0,    90,   174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   175,   296,
       0,     0,     0,   177,     0,     0,     0,     0,   297,     0,
     111,   288,   113,   181,     0,   298,   114,   115,   116,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   290,     0,     0,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,     0,   154,   155,   156,     0,     0,   157,
       0,   158,   159,   160,     0,     0,     0,     0,     0,   161,
     162,     0,     0,   291,     0,     0,   292,     0,     0,   293,
       0,   294,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   164,   165,   166,   167,     0,     0,
       0,     0,   168,   169,   170,   171,   172,   173,     0,    90,
     174,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   175,   296,     0,     0,     0,   177,
       0,     0,     0,     0,   297,     0,   111,   330,   113,   181,
       0,  1499,   114,   115,   116,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,   920,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,     0,     0,
     154,   155,   156,     0,     0,   157,     0,   158,   159,   160,
       0,   111,   330,   113,     0,   161,   162,   114,   115,   116,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,     0,     0,     0,   154,   155,   156,     0,     0,
     157,     0,   158,   159,   160,     0,     0,     0,     0,     0,
     161,   162,     0,     0,     0,     0,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     164,   165,   166,   167,   434,     0,   653,     0,   168,   169,
     170,   171,   172,   173,     0,    90,   174,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,   176,     0,     0,     0,   177,     0,     0,     0,     0,
     297,     0,     0,     0,     0,   181,     0,  1492,     0,     0,
       0,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   164,   165,   166,   167,   434,
       0,     0,     0,   168,   169,   170,   171,   172,   173,     0,
      90,   174,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,   176,     0,     0,     0,
     177,     0,     0,     0,     0,   297,     0,   111,   288,   289,
     181,     0,  1502,   114,   115,   116,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   290,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,     0,     0,     0,     0,   153,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,   158,   159,
     160,     0,     0,     0,     0,     0,   161,     0,     0,     0,
     291,     0,     0,   292,     0,     0,   293,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
       0,     0,   662,    24,    25,   663,    27,    28,   664,    30,
     665,    32,     0,    33,     0,     0,     0,     0,    38,    39,
       0,    41,    42,    43,     0,     0,  1050,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   164,     0,     0,   167,  1230,     0,     0,     0,   168,
     169,   170,   171,   172,     0,     0,    90,     0,     0,     0,
       0,    67,    68,    69,     0,     0,     0,     0,     0,     0,
       0,   175,   296,     0,     0,     0,   177,     0,     0,     0,
       0,   297,     0,   111,   288,  1355,   181,     0,   298,   114,
     115,   116,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   290,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,     0,
       0,  1744,     0,   153,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   158,   159,   160,     0,     0,     0,
       0,     0,   161,     0,     0,     0,   291,     0,     0,   292,
       0,     0,   293,     0,   294,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,   164,     0,     0,
     167,     0,     0,     0,     0,   168,   169,   170,   171,   172,
       0,     0,    90,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   175,   296,     0,
       0,   434,   177,   814,     0,     0,     0,   297,   759,   111,
     288,     0,   181,     0,  1356,   114,   115,   116,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   290,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   148,     0,     0,     0,     0,   153,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     158,   159,   160,     0,     0,     0,     0,     0,   161,     0,
       0,     0,   291,     0,     0,   292,     0,     0,   293,     0,
     294,   321,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,     0,     0,     0,     0,     0,   140,   141,   142,
     143,   144,   145,     0,     0,     0,   149,   150,   151,   152,
       0,     0,     0,     0,   154,   155,   156,     0,     0,   157,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,     0,     0,   164,     0,     0,   167,     0,     0,     0,
       0,   168,   169,   170,   171,   172,     0,     0,    90,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   175,   296,     0,     0,   434,   177,     0,
       0,     0,     0,   297,   696,   111,   288,     0,   181,     0,
     298,   114,   115,   116,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   290,
       0,     0,     0,     0,     0,   165,   166,     0,   146,   147,
     148,     0,     0,     0,     0,   153,     0,   173,     0,    90,
     174,     0,     0,     0,     0,     0,   158,   159,   160,     0,
       0,     0,     0,     0,   161,     0,     0,     0,   291,     0,
       0,   292,     0,     0,   293,     0,   294,   442,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,     0,
       0,     0,     0,   140,   141,   142,   143,   144,   145,     0,
       0,     0,   149,   150,   151,   152,     0,     0,     0,     0,
     154,   155,   156,     0,     0,   157,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   162,     0,     0,   164,
       0,     0,   167,     0,     0,     0,     0,   168,   169,   170,
     171,   172,     0,     0,    90,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   175,
     455,     0,     0,   434,   177,     0,     0,     0,     0,   297,
     759,   111,   288,     0,   181,     0,   558,   114,   115,   116,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   290,     0,     0,     0,     0,
       0,   165,   166,     0,   146,   147,   148,     0,     0,     0,
       0,   153,     0,   173,     0,    90,   174,     0,     0,     0,
       0,     0,   158,   159,   160,     0,     0,     0,     0,     0,
     161,     0,     0,     0,   291,     0,     0,   292,     0,     0,
     293,     0,   294,   324,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,     0,     0,     0,     0,     0,   140,
     141,   142,   143,   144,   145,     0,     0,     0,   149,   150,
     151,   152,     0,     0,     0,     0,   154,   155,   156,     0,
       0,   157,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,     0,     0,   164,     0,     0,   167,     0,
       0,     0,     0,   168,   169,   170,   171,   172,     0,     0,
      90,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   175,   455,     0,     0,   434,
     177,     0,     0,     0,     0,   297,   760,   111,   288,     0,
     181,     0,   817,   114,   115,   116,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   290,     0,     0,     0,     0,     0,   165,   166,     0,
     146,   147,   148,     0,     0,     0,     0,   153,     0,   173,
       7,     8,   174,     0,     0,     0,     0,     0,   158,   159,
     160,     0,     0,     0,     0,     0,   161,     0,     0,     0,
     291,     0,     0,   292,     0,     0,   293,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
       0,     0,     0,     0,   662,    24,    25,   663,    27,    28,
     664,    30,   665,    32,     0,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   164,     0,     0,   167,     0,     0,     0,     0,   168,
     169,   170,   171,   172,     0,     0,    90,     0,     0,     0,
       0,     0,     0,    67,    68,    69,     0,     0,     0,     0,
       0,   175,   296,     0,     0,     0,   177,     0,     0,     0,
       0,   297,     0,   111,   288,     0,   181,     0,  1360,   114,
     115,   116,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   290,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,     0,
       0,     0,     0,   153,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   158,   159,   160,     0,     0,     0,
       0,     0,   161,     0,     0,     0,   291,     0,     0,   292,
       0,     0,   293,     0,   294,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,  1487,     0,  1488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   164,     0,     0,
     167,     0,     0,     0,     0,   168,   169,   170,   171,   172,
       0,     0,    90,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   511,  1472,     0,
       0,   434,   177,     0,     0,     0,     0,   513,   826,   111,
     330,     0,   181,     0,   255,   114,   115,   116,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   148,     0,     0,     0,     0,   153,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   330,
     158,   159,   160,     0,   114,   115,   116,     0,   161,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   147,   148,     0,     0,     0,     0,   153,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   158,
     159,   160,     0,     0,     0,     0,     0,   161,     0,     0,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,     0,     0,   164,     0,  1606,   167,  1607,     0,     0,
       0,   168,   169,   170,   171,   172,     0,     0,    90,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   175,   176,     0,     0,   434,   177,     0,
       0,     0,     0,   297,     0,     0,   917,     0,   181,     0,
     491,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,     0,     0,   167,     0,     0,     0,     0,
     168,   169,   170,   171,   172,     0,     0,    90,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   511,   512,     0,     0,   434,   177,     0,     0,
       0,     0,   513,   862,   111,   330,   113,   181,     0,   255,
     114,   115,   116,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,     0,     0,   154,   155,
     156,     0,     0,   157,     0,   158,   159,   160,     0,     0,
       0,     0,     0,   161,   162,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
       0,     0,   968,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,     0,     0,
    1021,     0,     0,     0,     0,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,   164,   165,
     166,   167,  1041,     0,     0,     0,   168,   169,   170,   171,
     172,   173,     0,    90,   174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   175,   176,
       0,     0,     0,   177,   111,   288,     0,     0,   297,     0,
     114,   115,   116,   181,     0,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   290,     0,
       0,     0,     0,     0,     0,     0,     0,   146,   147,   148,
       0,     0,     0,     0,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   158,   159,   160,     0,     0,
       0,     0,     0,   161,     0,     0,     0,   291,     0,     0,
     292,     0,     0,   293,     0,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,     0,     0,  1071,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,     0,
       0,   167,     0,     0,     0,     0,   168,   169,   170,   171,
     172,     0,     0,    90,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   175,   455,
       0,     0,   434,   177,   111,   330,     0,     0,   297,   870,
     114,   115,   116,   181,     0,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   146,   147,   148,
       0,     0,     0,     0,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   158,   159,   160,     0,     0,
       0,     0,     0,   161,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,  1175,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,  1450,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,     1,     0,     0,    -4,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,     0,     0,     0,   164,     0,
       0,   167,     0,     0,     0,     0,   168,   169,   170,   171,
     172,     0,     0,    90,     0,     0,     0,     0,     0,    -4,
      -4,     0,     0,     0,     0,     0,     0,     0,   175,   176,
       0,     0,     0,   177,     0,    -4,    -4,    -4,   297,     0,
       0,    -4,    -4,   181,    -4,     0,     0,     0,    -4,    -4,
       0,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     0,    -4,    -4,    -4,     6,     0,     0,     0,     0,
      -4,     0,     0,     7,     8,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     9,
      10,     0,    -4,    -4,    -4,    -4,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,    11,    12,    13,     0,     0,
       0,    14,    15,     0,    16,     0,     0,     0,    17,    18,
       0,    19,    20,     0,     0,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     0,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,    54,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,    62,    63,    64,     0,     0,     0,     0,     0,
      65,     0,     0,     0,     0,    66,    67,    68,    69,     0,
       0,    70,     0,    71,     0,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,    85,    86,    87,    88,     0,     0,     0,     0,
       0,     0,    89,    90,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,  1469,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,  1524,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,     0,     0,     0,     0,     0,     0,  1525,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,  1526,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,  1527,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,  1528,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,  1560,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,     0,     0,     0,     0,     0,     0,  1622,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,  1632,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,  1633,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,  1661,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,  1664,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,     0,     0,     0,     0,     0,     0,  1667,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,  1694,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,  1701,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,  1736,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,  1738,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,     0,     0,     0,     0,     0,     0,  1740,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,  1758,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,  1784,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,  1822,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,  1823,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,     0,     0,     0,     0,     0,     0,  1827,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,  1828,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,  1829,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,  1830,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,   590,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,     0,   752,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,  1536,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,   871,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,   872,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
     883,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1003,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1004,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1005,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,  1036,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
    1127,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1173,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1174,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1229,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,  1368,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
    1369,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1370,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1371,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1408,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,  1409,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
    1416,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1561,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1562,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1563,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,  1564,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
    1580,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1581,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1585,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1679,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,  1680,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
    1681,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1682,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1689,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1692,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,  1732,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
    1749,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1750,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1751,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1752,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,  1795,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
    1796,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1797,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1798,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,   415,     0,   416,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,   654,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,   832,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,   841,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,   849,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
     933,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,  1029,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,  1030,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,  1034,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,     0,  1035,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,  1037,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,  1074,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,  1122,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,  1365,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,  1399,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
    1549,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,   706,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,   710,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,   711,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,   713,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,   715,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,   716,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,   719,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,   720,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,   814,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
     822,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,   823,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,   824,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,   830,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,   831,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,   840,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,   848,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,   932,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,   957,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,   962,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
     967,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,   970,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,   971,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,   977,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,   986,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,   987,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,   988,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,  1020,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,  1022,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,  1023,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
    1024,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,  1028,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,  1262,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,  1451,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,  1468,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,  1491,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,  1688,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,  1756
};

static const yytype_int16 yycheck[] =
{
       3,   376,   248,   378,     5,     4,  1358,   263,   505,   506,
       3,     5,     4,     4,   389,   110,     4,     6,     4,   275,
       4,     6,     5,     4,   406,   198,  1015,     6,     4,     4,
     203,     5,     5,    13,     4,     4,   418,     4,   197,     5,
       4,     6,    82,     4,     6,   204,     5,     5,     5,    49,
      50,     5,    52,     6,    57,     7,     4,     6,   194,   195,
       4,     6,    65,     6,     4,     4,     6,   198,     6,   187,
     188,   327,   203,   329,   140,     6,     6,     6,    81,  1431,
       6,   187,   188,     0,  1019,   203,    99,   205,   197,   155,
     156,   198,     6,   187,   188,   204,   203,   110,     3,   205,
     197,     6,   199,   197,   201,   118,   119,   120,   197,   206,
     204,   124,   125,   126,   127,     7,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       7,     6,   197,   197,   196,     6,    76,    76,     7,   204,
     204,    80,   143,    81,    82,     7,   130,   131,   132,   133,
       6,     7,    57,    92,     7,   103,   104,   105,   106,   151,
     143,   187,   188,   154,   112,  1517,   128,   115,     7,   143,
     143,   140,   141,   140,   141,   128,    81,   203,   181,   205,
     172,  1533,   197,   128,   199,   128,   172,   194,   195,   182,
     193,   194,   205,   197,   199,   184,   201,   204,   201,   194,
     195,   206,    82,   204,    84,   204,   209,  1196,   211,   204,
     204,   199,   204,   216,   193,   194,   598,   220,   206,   204,
     223,   205,   197,   204,   227,   228,   229,   230,   204,   204,
     233,   234,   235,   197,   204,   199,   197,   201,   204,   204,
     496,   497,   206,   204,   247,   204,   204,   204,   197,   201,
     204,   251,   252,   197,   184,   204,   187,   188,     6,   259,
     516,   187,   188,   263,   198,     8,   269,   270,   271,   203,
     208,   653,   654,   187,   188,     6,   181,   187,   188,   197,
     283,   284,   174,   175,   176,   177,     6,    79,   193,   194,
      82,   194,   195,   296,   204,   298,   201,   174,   175,   176,
     177,   204,   194,   195,   209,   174,   175,   176,   177,   201,
     199,   406,   174,   175,   176,   177,    79,   194,   195,    82,
     576,   174,   175,   176,   177,   194,   195,   187,   188,   203,
     333,   205,   335,   336,   590,   174,   175,   176,   177,  1691,
      99,   194,   195,   203,     8,   348,   187,   188,   197,     6,
     199,   110,   187,   188,   333,   194,   195,   206,   198,   118,
     119,   120,   203,   203,   205,   124,   125,   126,   127,   204,
     199,   187,   188,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   197,   386,   387,   388,   389,   390,   204,     6,
       7,   394,   395,   396,   397,   398,     8,   400,   377,   197,
     379,   380,   381,   341,   383,   384,   197,   386,   387,   388,
     200,   390,   197,   203,   417,   394,   395,   396,   397,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   333,   203,
    1782,   205,   196,   187,   188,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   203,
     187,   188,   455,   196,   392,   197,   194,   195,   840,   841,
      86,   399,   205,   201,   187,   188,   203,   200,     6,   197,
     203,   376,   377,   378,   379,   380,   381,    82,   383,   384,
     203,   386,   387,   388,   389,   390,     6,   490,   491,   394,
     395,   396,   397,   398,    76,   400,   197,    79,   199,   755,
      82,   198,   198,   503,   504,   206,   203,   203,   187,   188,
     605,   511,   505,   506,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   198,   532,
     533,   534,   196,   203,   198,   187,   188,   187,   188,    79,
      82,   544,    82,   204,    84,   483,   484,   485,   486,   187,
     188,   203,   197,   203,   199,   558,    84,    76,   653,   654,
      79,   206,   565,    82,    82,   203,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      82,   187,   188,   197,   196,   187,   188,   187,   188,    79,
      82,   187,   188,   205,   597,   204,   978,   203,   980,    79,
     982,   203,   984,   203,    79,   187,   188,   203,   198,  1544,
     200,  1546,   204,  1548,   204,   197,   187,   188,    82,     4,
      76,  1610,   204,    79,  1613,     4,    82,  1616,    84,   228,
     229,   230,   203,   197,   233,   234,   235,     4,     4,   544,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   197,     6,   187,   188,   196,     6,
     211,   187,   188,    79,   910,   216,    82,   670,    84,   220,
     269,   270,   203,   187,   188,   197,   227,   203,   187,   188,
     187,   188,   103,   104,   283,   284,   187,   188,   109,   203,
     693,   203,   695,   205,   203,   698,   203,   203,   701,   205,
     703,   796,   203,   197,   707,   708,   187,   188,   197,   187,
     188,   199,   199,  1095,   197,    99,   199,   655,   201,   698,
     197,   204,   203,   206,   703,   203,   110,  1716,   731,  1111,
     197,   197,   187,   188,   118,   119,   120,   197,   197,  1674,
     124,   125,   126,   127,   197,   840,   841,     6,   203,   752,
     187,   188,   197,   848,   849,   203,     7,   205,   758,   187,
     188,   189,   190,   191,   197,   765,   203,   705,   196,    76,
     197,   771,    79,  1762,   197,    82,  1765,    84,   203,  1768,
     205,   199,  1771,   189,   190,   191,   198,   197,   200,   198,
     196,   200,   204,   698,   797,   204,   701,   198,   703,   200,
    1735,   197,  1737,   806,  1739,   808,   198,   810,   200,   812,
    1745,   198,   204,   200,   817,   204,   203,   820,  1807,     6,
    1809,   205,  1811,   103,   104,   198,   198,   200,   200,   109,
     203,   203,   203,     6,   205,   838,     6,   932,   933,  1336,
    1337,   844,   198,   198,   200,   200,   849,   203,   203,   203,
     203,   205,   205,  1788,   204,  1790,  1102,  1792,   203,  1241,
     205,    99,   203,   203,   205,   205,   417,   203,   197,   205,
     849,   874,   110,   203,   197,   205,   879,   880,   881,   882,
     118,   119,   120,    82,   197,    84,   124,   125,   126,   127,
     204,    82,   895,    84,   203,   203,   205,   205,   204,   203,
     879,   205,   881,   882,   203,   203,   205,   205,   197,     4,
     913,   914,   915,   916,   197,   203,   895,   205,   197,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   197,   203,   938,   205,   196,   204,   490,
     491,   203,  1037,   205,   849,   883,   203,   203,   205,   205,
     197,   951,   955,   956,   203,   958,   205,   960,   961,   938,
     197,   964,   965,   203,   197,   205,   969,   205,   197,   197,
      21,    22,   204,   203,   879,   205,   881,   882,   203,   197,
     205,   532,   533,   534,   203,     4,   205,     6,   204,   203,
     895,   205,   203,   203,   205,   205,   203,   203,   205,   205,
    1095,   204,   204,  1003,  1004,  1005,   199,   558,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   203,   203,   205,   205,   196,  1273,    99,   203,
       6,   205,   203,   938,   205,   203,   203,   205,   205,   110,
     197,   203,  1539,   205,   197,   197,   597,   118,   119,   120,
    1053,  1054,  1055,   124,   125,   126,   127,   203,   109,   205,
     203,  1064,   205,   203,   203,   205,   205,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   203,   203,   205,   205,   197,   206,   149,   150,
     151,   152,    12,    13,   155,   203,   203,   205,   205,     6,
     161,   162,     6,   203,  1117,   205,   167,   203,   203,   205,
     205,   203,   199,   205,   204,   204,   204,  1502,     6,   199,
     199,   199,     6,  1136,   205,   201,   143,   204,     6,  1142,
       6,   206,   693,     6,   695,  1148,     6,  1150,  1151,  1244,
     204,     6,  1155,  1156,   199,  1158,     4,  1160,   196,  1162,
     201,  1164,  1165,  1166,     7,   204,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,   205,    87,   203,  1182,
     203,     7,    92,    93,     6,    95,    96,    97,     6,     6,
    1128,   101,     7,     7,  1197,  1195,   198,     6,  1201,   204,
    1203,   752,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     7,     6,     4,     7,
     196,     6,     6,     6,    99,   135,   136,   137,   140,    54,
      54,    54,   204,    54,   200,   110,   198,   288,     6,     6,
     198,   198,   203,   118,   119,   120,   797,   203,  1251,   124,
     125,   126,   127,   203,   305,   806,   203,   808,   203,   810,
     198,   812,  1508,   198,   198,     6,   817,     5,   200,   820,
       4,  1366,  1251,     4,     6,   204,  1279,     6,     6,     6,
     198,     7,   143,     7,     7,     7,  1289,   143,     7,  1292,
       7,   143,     7,     4,     7,   205,     6,  1553,   203,   198,
    1300,   203,    40,    41,    42,    43,    44,    45,   198,   198,
    1289,    49,    50,    51,    52,   203,   203,  1255,   201,    57,
      58,    59,     6,   874,    62,  1328,  1329,  1265,   205,   205,
     205,   200,   204,   204,   204,    73,     7,   204,  1338,     7,
    1340,     7,  1342,  1336,  1337,   204,  1251,   201,     6,     6,
      99,     6,     6,  1356,  1292,  1358,  1356,  1360,   409,  1359,
    1360,   110,   913,   914,   915,   916,     7,   199,     6,   118,
     119,   120,  1375,     6,   204,   124,   125,   126,   127,  1382,
       6,   197,   184,  1386,  1289,    99,   197,  1390,     7,     7,
       7,    84,     7,     7,  1332,     7,   110,     7,     6,   204,
       7,     7,     7,     7,   118,   119,   120,  1410,     7,     7,
     124,   125,   126,   127,     4,     4,   197,   204,   969,  1675,
     158,   159,     6,     6,   203,     7,     6,     6,  1431,     7,
       7,     7,   170,     6,     6,   173,    82,     6,     6,     4,
       5,     4,     4,  1381,     4,   205,   198,     6,     6,     6,
       6,     4,  1390,  1391,  1392,     6,   205,   203,   198,   198,
       7,   198,   197,     6,  1467,   201,     6,     6,     6,  1472,
      92,   204,     6,     6,   204,    40,    41,    42,    43,    44,
      45,   201,     6,   204,    49,    50,    51,    52,     7,  1492,
       6,   205,    57,    58,    59,   204,  1499,    62,    99,  1502,
      12,    13,   204,   204,     6,     5,     4,     6,    73,   110,
     204,     7,   204,   204,  1517,   204,   199,   118,   119,   120,
       6,     6,     6,   124,   125,   126,   127,     6,   204,     6,
    1533,   204,   204,  1536,     4,     6,   139,     6,     6,   203,
       6,     4,     6,  1543,     4,  1545,  1539,  1547,     6,  1552,
       6,     6,     6,     6,  1557,  1555,     6,     4,  1558,   204,
       6,     6,     6,     6,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     5,    87,     6,     6,     6,   143,
      92,    93,     6,    95,    96,    97,     6,     6,     6,   101,
       6,     6,    99,   158,   159,     6,  1599,  1502,  1598,     6,
       6,   203,  1602,   110,   205,   170,     6,   172,   173,     6,
       6,   118,   119,   120,     6,  1618,     6,   124,   125,   126,
     127,    99,     7,   135,   136,   137,     6,   198,     6,   194,
     195,   201,   110,     6,    88,    89,   201,   204,     5,    80,
     118,   119,   120,     6,     6,     6,   124,   125,   126,   127,
     204,  1651,  1203,   205,   204,  1655,   205,     7,   204,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,  1676,   204,  1678,   204,   196,  1678,   204,
       6,   138,     6,   205,     6,     6,     6,     6,  1691,   141,
       6,     6,     6,   205,     6,     6,   204,     6,   205,     6,
    1638,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     6,     6,   204,     6,   196,
      99,   175,   176,   177,   178,   179,     6,   205,   204,   204,
     204,   110,   205,  1733,  1734,     6,     6,   204,   192,   118,
     119,   120,   196,    99,  1747,   124,   125,   126,   127,     6,
       6,     6,  1755,     6,     6,     6,   210,   211,   212,   213,
       6,   215,   216,   217,   218,     6,   220,   221,   222,   205,
       6,     6,   204,   227,     6,     6,  1755,  1328,  1329,  1782,
       6,   204,   204,   204,     6,     6,     6,     6,  1726,     6,
     204,   245,   204,     6,   204,   204,  1799,     6,  1801,   204,
     254,   255,     6,     6,     6,     6,     6,     6,     6,   263,
       6,     6,     6,     6,     6,  1125,  1641,   451,  1522,  1135,
    1799,  1523,  1801,     3,     3,   481,   205,  1535,  1831,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,   296,   297,   298,   196,    -1,  1269,    -1,    -1,
    1755,    -1,  1831,    -1,   308,   309,   310,    -1,   312,    -1,
      -1,   315,   316,   317,    -1,    -1,   320,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,   337,   338,   196,    -1,    -1,    -1,   340,
      -1,    -1,    -1,    -1,  1799,    -1,  1801,   351,   352,    -1,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,    -1,    -1,    -1,    -1,  1831,    -1,    -1,    -1,
      -1,   385,    -1,    -1,    -1,    -1,    -1,   391,    -1,   393,
      -1,  1492,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
     414,   196,    -1,   417,    -1,    -1,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,    -1,    -1,   437,   438,  1536,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,   455,    -1,    -1,   196,    -1,  1557,   461,    -1,    -1,
      -1,    -1,   466,    -1,    -1,    -1,    -1,   471,   472,    -1,
      -1,    -1,    -1,   477,   478,    -1,    -1,    -1,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,   508,   509,   510,   511,   512,   513,
      -1,    -1,    -1,   517,   518,   519,   520,   521,    -1,    -1,
      99,   525,    -1,   527,   528,    -1,    -1,    -1,   532,   533,
     534,   110,    -1,   537,   538,   539,   540,   541,    -1,   118,
     119,   120,   543,   547,    -1,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,   558,     6,    -1,    -1,    -1,    -1,
     564,   565,    -1,   567,   568,    -1,    -1,    -1,   569,    -1,
      -1,    -1,    -1,    -1,    -1,  1676,    -1,  1678,    -1,    -1,
      -1,    -1,    -1,    -1,   588,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   596,   597,    -1,    -1,    12,    13,   602,    -1,
      -1,    -1,    -1,    -1,    -1,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,    -1,   618,   619,   620,
     621,   622,   623,   624,    -1,    -1,   205,   628,   629,   630,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   638,   639,   640,
      -1,   642,    -1,    -1,    -1,    -1,  1747,    -1,   649,    -1,
      -1,    -1,   656,    -1,    -1,    -1,    -1,    -1,    -1,   660,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
      96,    97,    -1,    -1,    -1,   101,   690,    -1,    99,   693,
      -1,   695,   696,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     704,    -1,    -1,   707,   708,    -1,    -1,   118,   119,   120,
      -1,    -1,    -1,   124,   125,   126,   127,   721,    -1,   135,
     136,   137,    -1,    -1,    -1,    -1,   730,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,   752,    -1,
      -1,    -1,    -1,    -1,    -1,   759,   760,    -1,    -1,    -1,
      -1,   765,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   778,    -1,    -1,   781,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,   797,   205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   806,    -1,   808,    -1,   810,    -1,   812,    12,
      13,    -1,    -1,   817,    -1,    -1,   820,    -1,    -1,    -1,
      -1,    -1,   826,    -1,   828,   829,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     6,    87,    -1,    -1,
      -1,    -1,    92,    93,    -1,    95,    96,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,   862,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   870,   871,   872,    -1,
     874,   223,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,   135,   136,   137,   892,    92,
      93,    -1,    95,    96,    97,   247,   900,    -1,   101,   903,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   913,
     914,   915,   916,    -1,    -1,    -1,   920,   918,    -1,   271,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   949,   950,
      -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   969,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   979,    -1,   981,    -1,   983,
      -1,   985,    -1,   335,   336,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,    -1,    -1,
      -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,  1033,
     382,    -1,  1036,    -1,    -1,    -1,  1040,    -1,  1042,  1043,
    1044,    -1,    -1,    -1,    -1,    -1,  1050,    -1,    -1,    -1,
      -1,    -1,    -1,   211,    -1,    -1,     6,    -1,   216,    -1,
      -1,    -1,   220,  1067,    -1,  1069,    -1,    -1,    -1,   227,
      -1,  1072,    -1,    -1,    -1,    -1,    -1,    -1,  1079,  1080,
    1081,  1082,  1083,    -1,    -1,    -1,    -1,    -1,  1089,  1090,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,  1103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1115,  1116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1127,  1128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   296,    -1,
     298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    87,  1172,  1173,
    1174,    -1,    92,    93,    -1,    95,    96,    97,  1182,    -1,
    1184,   101,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,  1195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1203,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1213,    -1,    -1,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,  1224,    -1,  1229,  1230,  1231,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   417,
      87,    -1,  1266,    -1,    -1,    92,    93,    -1,    95,    96,
      97,    -1,    -1,    -1,   101,    -1,  1280,     6,    -1,    -1,
      -1,  1285,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1298,  1299,    -1,   455,    -1,    -1,
      -1,  1305,  1306,    -1,    -1,    -1,  1310,    -1,   135,   136,
     137,    -1,    -1,    -1,  1318,    -1,    -1,    -1,   670,    -1,
      -1,    -1,    -1,    -1,  1328,  1329,  1330,    -1,  1332,    -1,
      -1,    -1,   490,   491,    -1,    -1,    -1,    -1,    -1,    -1,
    1344,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,  1356,    -1,    -1,    -1,  1360,    -1,    -1,  1363,
      -1,    -1,    -1,    -1,  1368,  1369,  1370,  1371,    -1,    -1,
      -1,    -1,    -1,    -1,   532,   533,   534,  1381,   205,   731,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1391,  1389,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     558,    -1,    -1,    -1,  1408,  1409,    -1,   565,    -1,    -1,
      -1,    -1,  1416,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,    92,
      93,    -1,    95,    96,    97,    -1,    -1,    -1,   101,   597,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1452,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,  1470,   196,  1472,    -1,
      -1,    -1,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1487,    -1,  1489,   838,    -1,  1492,    -1,
      -1,    -1,   844,    -1,    -1,  1499,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1513,
      -1,    -1,    -1,    -1,  1518,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   880,    -1,
      -1,    -1,  1536,    -1,    -1,   693,    -1,   695,    -1,  1543,
      -1,  1545,   205,  1547,    -1,    -1,    -1,    -1,    -1,   707,
     708,    -1,    -1,  1557,    -1,    -1,    -1,  1561,  1562,  1563,
    1564,  1565,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    -1,  1580,  1581,    -1,    92,
      93,  1585,    95,    96,    97,    -1,    -1,    -1,   101,    -1,
      -1,  1595,    -1,    -1,   752,     6,    -1,    -1,    -1,    -1,
      -1,    -1,  1606,   955,   956,    -1,   958,    -1,   960,   961,
      -1,    -1,   964,   965,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1636,    -1,    -1,    -1,    -1,  1641,    -1,   797,
      -1,    -1,    -1,     6,  1648,    -1,    -1,    -1,   806,    -1,
     808,    -1,   810,    -1,   812,    -1,    -1,    -1,  1662,   817,
      -1,  1665,   820,    -1,  1668,    -1,    -1,    -1,  1672,    -1,
      -1,    -1,  1676,    -1,  1678,  1679,  1680,  1681,  1682,    -1,
      -1,    -1,    -1,    -1,    -1,  1689,    -1,    -1,  1692,    -1,
      -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1053,  1054,  1055,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1064,    -1,    -1,    -1,   874,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1732,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1747,    -1,  1749,  1750,  1751,  1752,    -1,
      -1,    -1,    -1,    -1,    -1,   913,   914,   915,   916,    -1,
      -1,    -1,    -1,    -1,    -1,  1117,    -1,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,  1785,  1786,    -1,  1136,   196,    -1,    -1,    -1,    -1,
    1142,  1795,  1796,  1797,  1798,    -1,  1148,    -1,  1150,  1151,
      -1,    -1,    -1,  1155,  1156,    -1,  1158,    -1,  1160,    -1,
    1162,   969,  1164,  1165,  1166,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
    1182,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1197,    -1,    -1,    -1,  1201,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
       6,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,    -1,  1279,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
    1292,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     6,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,  1358,    -1,    -1,   157,
     158,   159,   160,     8,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,  1375,   172,   173,    -1,    -1,    -1,    -1,
    1382,    -1,    -1,    -1,  1386,    -1,    -1,    -1,  1390,   187,
     188,    -1,    -1,    -1,   192,  1203,    -1,    -1,    -1,   197,
      -1,    -1,    -1,    -1,   202,    -1,   204,    -1,  1410,    -1,
      -1,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,  1431,
     196,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,    -1,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1467,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
      -1,   199,    -1,   201,   202,    -1,   204,    -1,   206,    -1,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,  1517,    -1,    -1,    -1,    -1,
    1328,  1329,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1533,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,  1356,    -1,
    1552,   196,  1360,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    99,    -1,    -1,    -1,    -1,    -1,  1599,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1618,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
     107,    -1,    -1,    -1,  1472,   112,    -1,    -1,   115,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,  1492,    -1,    -1,    -1,   196,  1691,
      -1,  1499,    -1,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
     157,    -1,   196,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,    -1,    -1,   172,    -1,    -1,  1536,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,  1557,
     197,    -1,    -1,    -1,    -1,   202,    -1,   204,   205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
    1782,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    12,    13,
      72,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,  1676,    -1,
    1678,   103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,
     112,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,    -1,    -1,     7,     8,    92,    93,
      -1,    95,    96,    97,    -1,   157,    -1,   101,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,     8,  1747,
     172,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   187,   188,    -1,    -1,   196,
     192,   135,   136,   137,    -1,   197,   203,    -1,   205,    -1,
     202,    -1,    -1,   205,     3,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      59,   205,    -1,    62,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,   112,    -1,    -1,   115,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     8,    -1,    -1,    -1,   196,    -1,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,    -1,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
      -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,    -1,
       3,     4,     5,   202,    -1,   204,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    62,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,    -1,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,   197,    -1,     3,     4,     5,   202,
      -1,   204,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,     8,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    62,    -1,    64,    65,    66,
      -1,     3,     4,     5,    -1,    72,    73,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,
      62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    73,    -1,    -1,    -1,    -1,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     157,   158,   159,   160,   196,    -1,   198,    -1,   165,   166,
     167,   168,   169,   170,    -1,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,   202,    -1,   204,    -1,    -1,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   157,   158,   159,   160,   196,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,    -1,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,   197,    -1,     3,     4,     5,
     202,    -1,   204,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    -1,    -1,    -1,    -1,    53,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,    -1,    -1,    -1,    -1,    92,    93,
      -1,    95,    96,    97,    -1,    -1,     8,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,   160,     8,    -1,    -1,    -1,   165,
     166,   167,   168,   169,    -1,    -1,   172,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,
      -1,   197,    -1,     3,     4,     5,   202,    -1,   204,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,   205,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,   157,    -1,    -1,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
      -1,    -1,   172,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   187,   188,    -1,
      -1,   196,   192,   198,    -1,    -1,    -1,   197,   203,     3,
       4,    -1,   202,    -1,   204,     9,    10,    11,    -1,    -1,
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
      73,    -1,    -1,   157,    -1,    -1,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,    -1,    -1,   172,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   187,   188,    -1,    -1,   196,   192,    -1,
      -1,    -1,    -1,   197,   203,     3,     4,    -1,   202,    -1,
     204,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,   158,   159,    -1,    46,    47,
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
      -1,    -1,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,    -1,    -1,   172,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   187,
     188,    -1,    -1,   196,   192,    -1,    -1,    -1,    -1,   197,
     203,     3,     4,    -1,   202,    -1,   204,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,   158,   159,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,   170,    -1,   172,   173,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      82,    -1,    84,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,
     112,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,   157,    -1,    -1,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,
     172,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   187,   188,    -1,    -1,   196,
     192,    -1,    -1,    -1,    -1,   197,   203,     3,     4,    -1,
     202,    -1,   204,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,
      46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,   170,
      12,    13,   173,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,
      92,    93,    -1,    95,    96,    97,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,    -1,    -1,   172,    -1,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,    -1,    -1,    -1,    -1,
      -1,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,
      -1,   197,    -1,     3,     4,    -1,   202,    -1,   204,     9,
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
      -1,    -1,   112,    -1,    -1,   115,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,   203,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
      -1,    -1,   172,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   187,   188,    -1,
      -1,   196,   192,    -1,    -1,    -1,    -1,   197,   203,     3,
       4,    -1,   202,    -1,   204,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      64,    65,    66,    -1,     9,    10,    11,    -1,    72,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,   157,    -1,   203,   160,   205,    -1,    -1,
      -1,   165,   166,   167,   168,   169,    -1,    -1,   172,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   187,   188,    -1,    -1,   196,   192,    -1,
      -1,    -1,    -1,   197,    -1,    -1,   205,    -1,   202,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,    -1,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,    -1,    -1,   172,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   187,   188,    -1,    -1,   196,   192,    -1,    -1,
      -1,    -1,   197,   203,     3,     4,     5,   202,    -1,   204,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      59,    -1,    -1,    62,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,    -1,    -1,    -1,    -1,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   205,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,    -1,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
      -1,    -1,    -1,   192,     3,     4,    -1,    -1,   197,    -1,
       9,    10,    11,   202,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,   112,    -1,    -1,   115,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,    -1,    -1,   172,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   187,   188,
      -1,    -1,   196,   192,     3,     4,    -1,    -1,   197,   203,
       9,    10,    11,   202,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,   157,    -1,
      -1,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,    -1,    -1,   172,    -1,    -1,    -1,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
      -1,    -1,    -1,   192,    -1,    54,    55,    56,   197,    -1,
      -1,    60,    61,   202,    63,    -1,    -1,    -1,    67,    68,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,   122,   123,     4,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    12,    13,   134,   135,   136,   137,    -1,
      -1,   140,    -1,   142,    -1,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,    38,
      39,    -1,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,    -1,    54,    55,    56,    -1,    -1,
      -1,    60,    61,    -1,    63,    -1,    -1,    -1,    67,    68,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,   134,   135,   136,   137,    -1,
      -1,   140,    -1,   142,    -1,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,   178,   179,   180,   181,   182,   183,
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
      -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,   178,   179,   180,   181,   182,   183,   184,
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
      -1,   196,    -1,   198,    -1,   200,   178,   179,   180,   181,
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
     191,    -1,    -1,    -1,    -1,   196,    -1,   198
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
     152,   153,   154,   155,   156,   161,   162,   163,   164,   171,
     172,   210,   212,   213,   233,   250,   251,   254,   255,   256,
     257,   258,   259,   260,   261,   282,   283,   284,   285,   303,
     304,     3,     4,     5,     9,    10,    11,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    57,    58,    59,    62,    64,    65,
      66,    72,    73,   151,   157,   158,   159,   160,   165,   166,
     167,   168,   169,   170,   173,   187,   188,   192,   197,   199,
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
     197,     4,   204,   296,     4,   197,   197,   197,     6,     6,
     199,     4,   300,   304,     4,   300,     5,   204,     5,   204,
       4,   286,   286,   199,     6,   197,   204,   197,   199,   206,
     231,     7,   174,   175,   176,   177,   194,   195,   229,   230,
       4,   197,   199,   201,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   197,
     197,   197,   197,   197,   197,   231,   231,   231,   231,   197,
     231,   231,   231,     7,   197,   197,   197,   231,   197,   197,
     199,   286,   286,   286,   286,   286,     4,   140,   141,   304,
       4,   251,   252,   253,   204,   198,   200,   204,   232,     6,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   196,   204,     6,   197,   199,   230,
       6,   286,     4,   299,   300,   304,   299,   286,   299,   302,
     235,   238,   300,   304,   286,   188,   286,   294,   295,   286,
     286,   197,   286,   295,   286,   286,   197,   295,   286,   286,
     292,   197,   204,   295,   293,   293,   293,   197,   197,   293,
     293,   293,   197,   197,   197,   197,   197,   197,   197,   197,
     204,   204,   286,     4,   292,   296,   204,   204,   289,   289,
     289,   286,   286,   187,   188,   204,   204,   289,   204,   204,
     204,   187,   188,   197,   253,   289,   204,   197,   204,   197,
     197,   197,   293,   293,   292,   197,     4,   199,   199,   253,
       6,     6,   204,   204,   204,   293,   293,   199,   199,   199,
     197,   199,   201,   231,   199,     5,   143,   204,     5,   143,
       5,   143,     5,   143,    76,    79,    82,    84,   204,   286,
     294,   286,   205,   295,     8,   189,     6,   197,   199,   231,
       6,   286,   286,   286,   201,   286,   204,   143,   286,   286,
     286,   286,     6,     6,     6,   253,     6,   253,   199,     6,
     204,   299,   292,   292,   286,   286,   204,   204,   232,   300,
     292,     6,   199,   286,   286,     4,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   302,   299,
     302,   299,   299,   299,   292,   299,   299,   286,   299,   299,
     299,   302,   299,   286,   300,   286,   299,   299,   299,   299,
     304,   300,   304,   198,   200,     7,   229,   230,   201,     7,
     231,   205,    76,    79,    82,    84,   250,   286,   295,     7,
     229,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   214,   286,   286,     6,
     199,   201,   198,   203,   198,   203,   203,   198,   203,   200,
     203,   234,   200,   234,   203,   203,   198,   189,   203,   205,
     198,   198,   286,   198,   205,   198,   198,   286,   205,   198,
     198,     7,   286,   286,   205,     6,     6,     6,   286,   286,
       7,     7,   279,   279,   286,   244,   286,   300,   245,   286,
     300,   246,   286,   300,   247,   286,   300,   286,   286,   286,
     295,   295,   204,   198,     6,   204,   253,   253,   203,   203,
     203,   289,   289,   252,   252,   203,   286,   286,   286,   286,
     265,   203,   253,   286,   286,   286,   286,   286,     7,   280,
       6,     7,   286,     6,   286,   286,   205,   295,   295,   295,
       6,     6,   286,   286,   286,   286,     4,   204,   232,   304,
      54,   286,    54,    54,    54,     5,   204,     5,   204,     5,
     204,     5,   204,   295,   198,   205,   286,   204,   286,   294,
     204,   232,   198,   198,   198,   140,   203,   253,   204,     8,
     198,   198,   200,   205,   205,   253,   200,   198,   203,   205,
     198,   200,   286,   295,   229,     6,     6,   286,   198,   200,
     230,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   203,   232,   232,   232,   232,   232,   232,   232,
     203,   203,   203,   232,   203,   232,   232,   198,   198,   203,
     203,   203,   203,   203,   232,   232,   232,   198,   232,   288,
     301,     6,   203,   198,   198,   203,   232,   198,   198,   200,
     229,   230,   201,   229,   230,   300,   286,     6,     4,     4,
     204,   297,   232,   204,   204,   204,   204,   205,   205,   292,
       8,     4,   130,   131,   132,   133,   205,   217,   221,   224,
     226,   227,   198,   200,   286,     4,     6,   184,   211,   295,
       6,   295,   286,     6,   299,     6,   304,     6,   299,   286,
     300,     7,   286,   294,   143,     7,     7,   198,     7,   143,
       7,     7,   198,   143,     7,     7,   286,   198,   205,   204,
     198,   198,   286,   292,     4,   278,     6,   198,   198,   203,
     198,   203,   198,   203,   198,   203,   198,   198,   198,   205,
     205,   295,   201,   253,   205,   205,   289,   286,   286,   205,
     205,   286,   289,   203,   203,   203,    99,   110,   118,   119,
     120,   124,   125,   126,   127,   275,   276,   289,   205,   262,
     198,   205,   198,   198,   198,   286,     6,   286,   198,   200,
     200,   205,   205,   205,   200,   200,   203,   200,   295,   200,
     204,   205,   204,   204,   204,   295,   295,   295,   295,   205,
       8,   295,   295,     7,     7,     7,   201,   286,   205,   286,
     286,     7,   201,   205,   204,   292,     6,   229,   230,   229,
     230,   205,   205,   292,   200,   230,   201,   230,   299,   286,
     286,   286,   286,   295,   299,   292,   299,   299,   300,   240,
     242,   286,   299,   286,     6,     4,   140,   141,   286,     6,
       6,     6,     7,   199,   296,   298,     6,   295,   295,   295,
     295,   232,     6,   286,   218,   197,   197,   204,   228,     6,
     230,   230,   200,   184,   299,   198,   198,   203,     7,   232,
     232,   289,    82,    84,   292,   292,     7,   292,    82,    84,
     292,   292,     7,    84,   292,   292,     6,     7,     7,   295,
       7,     7,    99,   277,     6,     7,   229,   286,   229,   286,
     229,   286,   229,   286,     7,     7,     7,     7,     7,   205,
       4,   205,   203,   203,   203,   205,   205,   289,   289,   289,
       4,     6,   204,     6,   197,     6,   128,     6,   128,     6,
     128,     6,   128,   205,   276,   203,   275,     7,     6,     7,
       7,     7,     6,   204,     6,     6,     6,    82,   286,     6,
       6,   286,   201,   205,   286,   286,   286,   286,   205,   205,
     205,   205,   286,   205,   205,   292,   292,   292,     4,   203,
       8,     8,   198,     4,     4,   292,   205,   286,     6,   286,
       6,   232,     6,     6,     4,     6,   232,   232,   232,   232,
     232,   203,   198,   198,   198,   203,   203,   232,   241,   203,
     232,   243,   198,   198,     6,     7,   229,   230,   201,     7,
       6,   296,   286,   203,   205,   205,   205,   205,   205,   229,
     197,   286,   286,   291,   292,   204,   201,     6,     6,   211,
       6,   286,   204,   286,   300,     6,     6,     6,   204,   204,
      92,   249,   249,   292,     6,   204,   204,     6,     6,   292,
     204,     6,     6,     5,   292,   205,   292,   292,     4,     6,
     292,   292,   292,   292,   292,   292,   292,   292,   204,   204,
       7,     6,     7,   286,   286,   286,   204,   204,   203,   205,
     203,   205,   203,   205,   199,   286,   292,   286,     6,     6,
       6,     6,   286,   289,   205,     5,   204,   292,   204,   204,
     204,   292,   295,   204,     6,   200,     4,   232,   203,   203,
     203,   203,   232,     6,     6,   139,   286,   286,   286,     6,
       6,     7,   203,     6,     6,     6,   229,   230,   299,   300,
       4,     4,   154,   300,   286,     6,     4,   297,     6,   200,
     296,     6,     6,     6,     6,   292,   215,   286,   203,   203,
     203,   205,   216,   286,     4,   299,   203,   292,   300,   286,
     286,   289,     6,     6,     6,   286,   286,     6,   286,     5,
       6,   204,     6,   143,   248,   286,     6,     6,     6,     6,
       6,     6,     4,     6,     6,   295,   295,   286,   286,   300,
     205,   198,   203,   205,   252,   252,   289,     6,   266,   289,
       6,   267,   289,     6,   268,   286,   205,   203,   198,   205,
     203,     6,   188,   289,     6,   291,   289,   289,     6,   205,
     286,     6,   286,   286,   286,   286,   292,   203,   205,     8,
     205,   198,   204,   286,   300,   292,   292,   198,   232,   204,
     292,   300,   204,   286,   300,   300,     6,     6,     7,     6,
     201,     6,   198,   203,   286,   286,   292,   204,   203,   205,
       6,   286,   236,   237,   205,   205,   205,   205,   205,     5,
     291,    80,     6,   204,   205,   205,   204,     6,     6,   204,
     286,   205,   205,   203,   204,   203,   204,   203,   204,   200,
       6,   292,     7,   204,   286,   203,   205,   203,   203,     6,
     205,   203,   203,   203,   203,   138,   286,   286,   295,     6,
       6,   205,     6,   239,   286,   302,   296,   141,   219,   286,
     203,   203,   291,   286,     6,   203,   240,   242,     6,     6,
       6,     6,     6,     6,   205,   204,   291,   103,   104,   109,
     281,   103,   104,   281,   295,   252,   203,   205,   286,   289,
     275,   286,   289,   275,   286,   289,   275,     6,   203,   205,
     292,   253,   205,   289,     6,   295,   289,   286,   286,   286,
     286,   286,   205,   205,   205,     6,   203,   205,     7,   205,
       6,   204,   286,   286,   205,   286,   205,   205,   204,   286,
     205,   204,   289,   292,     6,   204,   289,     6,   205,   205,
     286,   205,   203,   205,   205,   203,   205,   205,   203,   205,
     292,     6,    99,   205,   263,   204,   203,   205,   203,   203,
     203,   203,   203,     6,     6,   286,   300,   216,   198,   203,
       6,   204,   203,   286,   205,     6,   289,     6,   289,     6,
       6,   205,     6,   269,   286,     6,     6,   270,   286,     6,
       6,   271,   286,     6,   205,   286,   275,   253,   295,     6,
     289,   295,   286,   286,   286,   286,     7,   205,   222,   286,
     291,   286,   203,   203,   203,   204,   205,   204,   205,   204,
     205,     6,     6,   205,   205,   264,   205,   203,   205,   203,
     203,   203,   203,   300,     6,   204,   198,   205,   205,   286,
     289,   289,   275,     6,   272,   275,     6,   273,   275,     6,
     274,   275,     6,   295,     6,   286,   286,   286,   286,   220,
     299,   225,   204,     6,   205,   203,   203,   205,   204,   205,
     204,   205,   204,   205,   205,   203,   203,   203,   203,   203,
     205,   204,   291,     6,   286,   286,     6,   275,     6,   275,
       6,   275,     6,   286,   286,   286,   286,   299,     6,   223,
     299,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   203,   205,     6,     6,     6,     6,     6,     6,   299,
       6
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
#line 1478 "Gmsh.y"
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
#line 1501 "Gmsh.y"
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
#line 1519 "Gmsh.y"
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
#line 1540 "Gmsh.y"
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
#line 1558 "Gmsh.y"
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
#line 1588 "Gmsh.y"
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
#line 1618 "Gmsh.y"
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
#line 1636 "Gmsh.y"
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
#line 1655 "Gmsh.y"
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
#line 1681 "Gmsh.y"
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
#line 1699 "Gmsh.y"
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
#line 1717 "Gmsh.y"
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
#line 1752 "Gmsh.y"
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
#line 1770 "Gmsh.y"
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
#line 1809 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 165:
#line 1815 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 166:
#line 1821 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 167:
#line 1828 "Gmsh.y"
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
#line 1853 "Gmsh.y"
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
#line 1878 "Gmsh.y"
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
#line 1895 "Gmsh.y"
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
#line 1915 "Gmsh.y"
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
#line 1948 "Gmsh.y"
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
#line 1984 "Gmsh.y"
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
#line 2002 "Gmsh.y"
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
#line 2019 "Gmsh.y"
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
#line 2035 "Gmsh.y"
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
#line 2072 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 178:
#line 2077 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 179:
#line 2082 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 180:
#line 2087 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 181:
#line 2092 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 182:
#line 2097 "Gmsh.y"
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
#line 2120 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 184:
#line 2126 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 185:
#line 2136 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 186:
#line 2137 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 187:
#line 2142 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 188:
#line 2146 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 189:
#line 2150 "Gmsh.y"
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
#line 2173 "Gmsh.y"
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
#line 2196 "Gmsh.y"
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
#line 2219 "Gmsh.y"
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
#line 2247 "Gmsh.y"
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
#line 2268 "Gmsh.y"
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
#line 2295 "Gmsh.y"
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
#line 2316 "Gmsh.y"
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
#line 2337 "Gmsh.y"
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
#line 2357 "Gmsh.y"
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
#line 2469 "Gmsh.y"
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
#line 2488 "Gmsh.y"
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
#line 2527 "Gmsh.y"
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
#line 2635 "Gmsh.y"
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
#line 2644 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 204:
#line 2650 "Gmsh.y"
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
#line 2665 "Gmsh.y"
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
#line 2693 "Gmsh.y"
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
#line 2710 "Gmsh.y"
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
#line 2719 "Gmsh.y"
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
#line 2733 "Gmsh.y"
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
#line 2747 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 211:
#line 2753 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 212:
#line 2759 "Gmsh.y"
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
#line 2768 "Gmsh.y"
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
#line 2777 "Gmsh.y"
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
#line 2786 "Gmsh.y"
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
#line 2800 "Gmsh.y"
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
#line 2856 "Gmsh.y"
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
#line 2874 "Gmsh.y"
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
#line 2891 "Gmsh.y"
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
#line 2906 "Gmsh.y"
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
#line 2925 "Gmsh.y"
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
#line 2937 "Gmsh.y"
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
#line 2961 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 224:
#line 2965 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 225:
#line 2970 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 226:
#line 2977 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 227:
#line 2982 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 228:
#line 2988 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 229:
#line 2993 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 230:
#line 2999 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 231:
#line 3007 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 232:
#line 3011 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 233:
#line 3015 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 234:
#line 3021 "Gmsh.y"
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
#line 3075 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    ;}
    break;

  case 236:
#line 3088 "Gmsh.y"
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
#line 3105 "Gmsh.y"
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
#line 3122 "Gmsh.y"
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
#line 3144 "Gmsh.y"
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
#line 3166 "Gmsh.y"
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
#line 3201 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 242:
#line 3209 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 243:
#line 3217 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 244:
#line 3223 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 245:
#line 3230 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 246:
#line 3237 "Gmsh.y"
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
        if(!type_until2) ImbricatedTest--;
      }
    ;}
    break;

  case 247:
#line 3257 "Gmsh.y"
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

  case 248:
#line 3283 "Gmsh.y"
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

  case 249:
#line 3295 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 250:
#line 3307 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 251:
#line 3315 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 252:
#line 3323 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 253:
#line 3331 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 254:
#line 3337 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 255:
#line 3345 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 256:
#line 3351 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 257:
#line 3359 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 258:
#line 3365 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 259:
#line 3373 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 260:
#line 3379 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 261:
#line 3387 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 262:
#line 3394 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 263:
#line 3401 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 264:
#line 3408 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 265:
#line 3415 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 266:
#line 3422 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 267:
#line 3429 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 268:
#line 3436 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 269:
#line 3443 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 270:
#line 3450 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 271:
#line 3456 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 272:
#line 3463 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 273:
#line 3469 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 274:
#line 3476 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 275:
#line 3482 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 276:
#line 3489 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 277:
#line 3495 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 278:
#line 3502 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 279:
#line 3508 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 280:
#line 3515 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 281:
#line 3521 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 282:
#line 3528 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 283:
#line 3534 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 284:
#line 3541 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 285:
#line 3547 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 286:
#line 3554 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 287:
#line 3560 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 288:
#line 3571 "Gmsh.y"
    {
    ;}
    break;

  case 289:
#line 3574 "Gmsh.y"
    {
    ;}
    break;

  case 290:
#line 3580 "Gmsh.y"
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

  case 291:
#line 3592 "Gmsh.y"
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

  case 292:
#line 3612 "Gmsh.y"
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

  case 293:
#line 3636 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 294:
#line 3640 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 295:
#line 3644 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 296:
#line 3648 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 297:
#line 3652 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 298:
#line 3658 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 299:
#line 3664 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 300:
#line 3668 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 301:
#line 3672 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 302:
#line 3676 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 303:
#line 3680 "Gmsh.y"
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

  case 304:
#line 3699 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 305:
#line 3711 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 306:
#line 3715 "Gmsh.y"
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

  case 307:
#line 3730 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 308:
#line 3734 "Gmsh.y"
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

  case 309:
#line 3750 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 310:
#line 3754 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 311:
#line 3759 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 312:
#line 3763 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 313:
#line 3769 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 314:
#line 3773 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 315:
#line 3780 "Gmsh.y"
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

  case 316:
#line 3836 "Gmsh.y"
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

  case 317:
#line 3906 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 318:
#line 3911 "Gmsh.y"
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

  case 319:
#line 3978 "Gmsh.y"
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

  case 320:
#line 4014 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 321:
#line 4022 "Gmsh.y"
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

  case 322:
#line 4065 "Gmsh.y"
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

  case 323:
#line 4104 "Gmsh.y"
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

  case 324:
#line 4125 "Gmsh.y"
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

  case 325:
#line 4157 "Gmsh.y"
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

  case 326:
#line 4184 "Gmsh.y"
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

  case 327:
#line 4210 "Gmsh.y"
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

  case 328:
#line 4236 "Gmsh.y"
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

  case 329:
#line 4262 "Gmsh.y"
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

  case 330:
#line 4288 "Gmsh.y"
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

  case 331:
#line 4309 "Gmsh.y"
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

  case 332:
#line 4337 "Gmsh.y"
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

  case 333:
#line 4365 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    ;}
    break;

  case 334:
#line 4369 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 335:
#line 4373 "Gmsh.y"
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

  case 336:
#line 4401 "Gmsh.y"
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

  case 337:
#line 4440 "Gmsh.y"
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

  case 338:
#line 4479 "Gmsh.y"
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

  case 339:
#line 4500 "Gmsh.y"
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

  case 340:
#line 4521 "Gmsh.y"
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

  case 341:
#line 4548 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 342:
#line 4552 "Gmsh.y"
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

  case 343:
#line 4562 "Gmsh.y"
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

  case 344:
#line 4596 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 345:
#line 4597 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 346:
#line 4598 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 347:
#line 4603 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 348:
#line 4609 "Gmsh.y"
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

  case 349:
#line 4621 "Gmsh.y"
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

  case 350:
#line 4639 "Gmsh.y"
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

  case 351:
#line 4666 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 352:
#line 4667 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 353:
#line 4668 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 354:
#line 4669 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 355:
#line 4670 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 356:
#line 4671 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 357:
#line 4672 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 358:
#line 4673 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 359:
#line 4675 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 360:
#line 4681 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 361:
#line 4682 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 362:
#line 4683 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 363:
#line 4684 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 364:
#line 4685 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 365:
#line 4686 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 366:
#line 4687 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 367:
#line 4688 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 368:
#line 4689 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 369:
#line 4690 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 370:
#line 4691 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 371:
#line 4692 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 372:
#line 4693 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 373:
#line 4694 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 374:
#line 4695 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 375:
#line 4696 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 376:
#line 4697 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 377:
#line 4698 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 378:
#line 4699 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 379:
#line 4700 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 380:
#line 4701 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 381:
#line 4702 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 382:
#line 4703 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 383:
#line 4704 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 384:
#line 4705 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 385:
#line 4706 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 386:
#line 4707 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 387:
#line 4708 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 388:
#line 4709 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 389:
#line 4710 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 390:
#line 4711 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 391:
#line 4712 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 392:
#line 4713 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 393:
#line 4722 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 394:
#line 4723 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 395:
#line 4724 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 396:
#line 4725 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 397:
#line 4726 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 398:
#line 4727 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 399:
#line 4728 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 400:
#line 4729 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 401:
#line 4730 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 402:
#line 4731 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 403:
#line 4732 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 404:
#line 4737 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 405:
#line 4739 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 406:
#line 4745 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 407:
#line 4750 "Gmsh.y"
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
#line 4767 "Gmsh.y"
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
#line 4785 "Gmsh.y"
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
#line 4803 "Gmsh.y"
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
#line 4821 "Gmsh.y"
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
#line 4839 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 413:
#line 4844 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 414:
#line 4850 "Gmsh.y"
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
#line 4862 "Gmsh.y"
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
#line 4879 "Gmsh.y"
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
#line 4897 "Gmsh.y"
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
#line 4915 "Gmsh.y"
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
#line 4933 "Gmsh.y"
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
#line 4954 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 421:
#line 4959 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 422:
#line 4964 "Gmsh.y"
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
#line 4974 "Gmsh.y"
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
#line 4984 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 425:
#line 4989 "Gmsh.y"
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
#line 5000 "Gmsh.y"
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
#line 5009 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 428:
#line 5014 "Gmsh.y"
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
#line 5041 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 430:
#line 5045 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 431:
#line 5049 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 432:
#line 5053 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 433:
#line 5057 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 434:
#line 5064 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 435:
#line 5068 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 436:
#line 5072 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 437:
#line 5076 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 438:
#line 5083 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 439:
#line 5088 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 440:
#line 5095 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 441:
#line 5100 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 442:
#line 5104 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 443:
#line 5109 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 444:
#line 5113 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 445:
#line 5121 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 446:
#line 5132 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 447:
#line 5136 "Gmsh.y"
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
#line 5148 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 449:
#line 5156 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 450:
#line 5164 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 451:
#line 5171 "Gmsh.y"
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
#line 5181 "Gmsh.y"
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
#line 5210 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 454:
#line 5214 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 455:
#line 5218 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 456:
#line 5222 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 457:
#line 5226 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 458:
#line 5230 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 459:
#line 5234 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 460:
#line 5238 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 461:
#line 5242 "Gmsh.y"
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
#line 5271 "Gmsh.y"
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
#line 5300 "Gmsh.y"
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
#line 5329 "Gmsh.y"
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
#line 5359 "Gmsh.y"
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
#line 5372 "Gmsh.y"
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
#line 5385 "Gmsh.y"
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
#line 5398 "Gmsh.y"
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
#line 5410 "Gmsh.y"
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
#line 5420 "Gmsh.y"
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
#line 5430 "Gmsh.y"
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
#line 5442 "Gmsh.y"
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
#line 5455 "Gmsh.y"
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
#line 5467 "Gmsh.y"
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
#line 5485 "Gmsh.y"
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
#line 5506 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 477:
#line 5511 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 478:
#line 5515 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 479:
#line 5519 "Gmsh.y"
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
#line 5531 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 481:
#line 5535 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 482:
#line 5547 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 483:
#line 5554 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 484:
#line 5564 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 485:
#line 5568 "Gmsh.y"
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
#line 5583 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 487:
#line 5588 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 488:
#line 5595 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 489:
#line 5599 "Gmsh.y"
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
#line 5612 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 491:
#line 5620 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 492:
#line 5631 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 493:
#line 5635 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 494:
#line 5639 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 495:
#line 5647 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 496:
#line 5653 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 497:
#line 5659 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 498:
#line 5667 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 499:
#line 5675 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 500:
#line 5682 "Gmsh.y"
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

  case 501:
#line 5697 "Gmsh.y"
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

  case 502:
#line 5711 "Gmsh.y"
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

  case 503:
#line 5725 "Gmsh.y"
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

  case 504:
#line 5737 "Gmsh.y"
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

  case 505:
#line 5753 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 506:
#line 5762 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 507:
#line 5771 "Gmsh.y"
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

  case 508:
#line 5781 "Gmsh.y"
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

  case 509:
#line 5792 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 510:
#line 5796 "Gmsh.y"
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

  case 511:
#line 5815 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 512:
#line 5822 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 513:
#line 5828 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 514:
#line 5830 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 515:
#line 5841 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 516:
#line 5846 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 517:
#line 5852 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 518:
#line 5861 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 519:
#line 5874 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 520:
#line 5877 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 521:
#line 5881 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 11933 "Gmsh.tab.cpp"
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


#line 5884 "Gmsh.y"


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

