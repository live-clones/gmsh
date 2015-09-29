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
     tExp = 269,
     tLog = 270,
     tLog10 = 271,
     tSqrt = 272,
     tSin = 273,
     tAsin = 274,
     tCos = 275,
     tAcos = 276,
     tTan = 277,
     tRand = 278,
     tAtan = 279,
     tAtan2 = 280,
     tSinh = 281,
     tCosh = 282,
     tTanh = 283,
     tFabs = 284,
     tFloor = 285,
     tCeil = 286,
     tRound = 287,
     tFmod = 288,
     tModulo = 289,
     tHypot = 290,
     tList = 291,
     tPrintf = 292,
     tError = 293,
     tStr = 294,
     tSprintf = 295,
     tStrCat = 296,
     tStrPrefix = 297,
     tStrRelative = 298,
     tStrReplace = 299,
     tFind = 300,
     tStrFind = 301,
     tStrCmp = 302,
     tStrChoice = 303,
     tUpperCase = 304,
     tLowerCase = 305,
     tLowerCaseIn = 306,
     tTextAttributes = 307,
     tBoundingBox = 308,
     tDraw = 309,
     tSetChanged = 310,
     tToday = 311,
     tFixRelativePath = 312,
     tCurrentDirectory = 313,
     tSyncModel = 314,
     tNewModel = 315,
     tOnelabAction = 316,
     tOnelabRun = 317,
     tCpu = 318,
     tMemory = 319,
     tTotalMemory = 320,
     tCreateTopology = 321,
     tCreateTopologyNoHoles = 322,
     tDistanceFunction = 323,
     tDefineConstant = 324,
     tUndefineConstant = 325,
     tDefineNumber = 326,
     tDefineString = 327,
     tSetNumber = 328,
     tSetString = 329,
     tPoint = 330,
     tCircle = 331,
     tEllipse = 332,
     tLine = 333,
     tSphere = 334,
     tPolarSphere = 335,
     tSurface = 336,
     tSpline = 337,
     tVolume = 338,
     tCharacteristic = 339,
     tLength = 340,
     tParametric = 341,
     tElliptic = 342,
     tRefineMesh = 343,
     tAdaptMesh = 344,
     tRelocateMesh = 345,
     tPlane = 346,
     tRuled = 347,
     tTransfinite = 348,
     tComplex = 349,
     tPhysical = 350,
     tCompound = 351,
     tPeriodic = 352,
     tUsing = 353,
     tPlugin = 354,
     tDegenerated = 355,
     tRecursive = 356,
     tRotate = 357,
     tTranslate = 358,
     tSymmetry = 359,
     tDilate = 360,
     tExtrude = 361,
     tLevelset = 362,
     tAffine = 363,
     tRecombine = 364,
     tSmoother = 365,
     tSplit = 366,
     tDelete = 367,
     tCoherence = 368,
     tIntersect = 369,
     tMeshAlgorithm = 370,
     tReverse = 371,
     tLayers = 372,
     tScaleLast = 373,
     tHole = 374,
     tAlias = 375,
     tAliasWithOptions = 376,
     tCopyOptions = 377,
     tQuadTriAddVerts = 378,
     tQuadTriNoNewVerts = 379,
     tQuadTriSngl = 380,
     tQuadTriDbl = 381,
     tRecombLaterals = 382,
     tTransfQuadTri = 383,
     tText2D = 384,
     tText3D = 385,
     tInterpolationScheme = 386,
     tTime = 387,
     tCombine = 388,
     tBSpline = 389,
     tBezier = 390,
     tNurbs = 391,
     tNurbsOrder = 392,
     tNurbsKnots = 393,
     tColor = 394,
     tColorTable = 395,
     tFor = 396,
     tIn = 397,
     tEndFor = 398,
     tIf = 399,
     tEndIf = 400,
     tExit = 401,
     tAbort = 402,
     tField = 403,
     tReturn = 404,
     tCall = 405,
     tMacro = 406,
     tShow = 407,
     tHide = 408,
     tGetValue = 409,
     tGetEnv = 410,
     tGetString = 411,
     tGetNumber = 412,
     tHomology = 413,
     tCohomology = 414,
     tBetti = 415,
     tSetOrder = 416,
     tExists = 417,
     tFileExists = 418,
     tGMSH_MAJOR_VERSION = 419,
     tGMSH_MINOR_VERSION = 420,
     tGMSH_PATCH_VERSION = 421,
     tGmshExecutableName = 422,
     tSetPartition = 423,
     tNameFromString = 424,
     tStringFromName = 425,
     tAFFECTDIVIDE = 426,
     tAFFECTTIMES = 427,
     tAFFECTMINUS = 428,
     tAFFECTPLUS = 429,
     tOR = 430,
     tAND = 431,
     tNOTEQUAL = 432,
     tEQUAL = 433,
     tGREATEROREQUAL = 434,
     tLESSOREQUAL = 435,
     UNARYPREC = 436,
     tMINUSMINUS = 437,
     tPLUSPLUS = 438
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
#define tExp 269
#define tLog 270
#define tLog10 271
#define tSqrt 272
#define tSin 273
#define tAsin 274
#define tCos 275
#define tAcos 276
#define tTan 277
#define tRand 278
#define tAtan 279
#define tAtan2 280
#define tSinh 281
#define tCosh 282
#define tTanh 283
#define tFabs 284
#define tFloor 285
#define tCeil 286
#define tRound 287
#define tFmod 288
#define tModulo 289
#define tHypot 290
#define tList 291
#define tPrintf 292
#define tError 293
#define tStr 294
#define tSprintf 295
#define tStrCat 296
#define tStrPrefix 297
#define tStrRelative 298
#define tStrReplace 299
#define tFind 300
#define tStrFind 301
#define tStrCmp 302
#define tStrChoice 303
#define tUpperCase 304
#define tLowerCase 305
#define tLowerCaseIn 306
#define tTextAttributes 307
#define tBoundingBox 308
#define tDraw 309
#define tSetChanged 310
#define tToday 311
#define tFixRelativePath 312
#define tCurrentDirectory 313
#define tSyncModel 314
#define tNewModel 315
#define tOnelabAction 316
#define tOnelabRun 317
#define tCpu 318
#define tMemory 319
#define tTotalMemory 320
#define tCreateTopology 321
#define tCreateTopologyNoHoles 322
#define tDistanceFunction 323
#define tDefineConstant 324
#define tUndefineConstant 325
#define tDefineNumber 326
#define tDefineString 327
#define tSetNumber 328
#define tSetString 329
#define tPoint 330
#define tCircle 331
#define tEllipse 332
#define tLine 333
#define tSphere 334
#define tPolarSphere 335
#define tSurface 336
#define tSpline 337
#define tVolume 338
#define tCharacteristic 339
#define tLength 340
#define tParametric 341
#define tElliptic 342
#define tRefineMesh 343
#define tAdaptMesh 344
#define tRelocateMesh 345
#define tPlane 346
#define tRuled 347
#define tTransfinite 348
#define tComplex 349
#define tPhysical 350
#define tCompound 351
#define tPeriodic 352
#define tUsing 353
#define tPlugin 354
#define tDegenerated 355
#define tRecursive 356
#define tRotate 357
#define tTranslate 358
#define tSymmetry 359
#define tDilate 360
#define tExtrude 361
#define tLevelset 362
#define tAffine 363
#define tRecombine 364
#define tSmoother 365
#define tSplit 366
#define tDelete 367
#define tCoherence 368
#define tIntersect 369
#define tMeshAlgorithm 370
#define tReverse 371
#define tLayers 372
#define tScaleLast 373
#define tHole 374
#define tAlias 375
#define tAliasWithOptions 376
#define tCopyOptions 377
#define tQuadTriAddVerts 378
#define tQuadTriNoNewVerts 379
#define tQuadTriSngl 380
#define tQuadTriDbl 381
#define tRecombLaterals 382
#define tTransfQuadTri 383
#define tText2D 384
#define tText3D 385
#define tInterpolationScheme 386
#define tTime 387
#define tCombine 388
#define tBSpline 389
#define tBezier 390
#define tNurbs 391
#define tNurbsOrder 392
#define tNurbsKnots 393
#define tColor 394
#define tColorTable 395
#define tFor 396
#define tIn 397
#define tEndFor 398
#define tIf 399
#define tEndIf 400
#define tExit 401
#define tAbort 402
#define tField 403
#define tReturn 404
#define tCall 405
#define tMacro 406
#define tShow 407
#define tHide 408
#define tGetValue 409
#define tGetEnv 410
#define tGetString 411
#define tGetNumber 412
#define tHomology 413
#define tCohomology 414
#define tBetti 415
#define tSetOrder 416
#define tExists 417
#define tFileExists 418
#define tGMSH_MAJOR_VERSION 419
#define tGMSH_MINOR_VERSION 420
#define tGMSH_PATCH_VERSION 421
#define tGmshExecutableName 422
#define tSetPartition 423
#define tNameFromString 424
#define tStringFromName 425
#define tAFFECTDIVIDE 426
#define tAFFECTTIMES 427
#define tAFFECTMINUS 428
#define tAFFECTPLUS 429
#define tOR 430
#define tAND 431
#define tNOTEQUAL 432
#define tEQUAL 433
#define tGREATEROREQUAL 434
#define tLESSOREQUAL 435
#define UNARYPREC 436
#define tMINUSMINUS 437
#define tPLUSPLUS 438




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
#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0;
static gmshfpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static std::string LoopControlVariablesNameTab[MAX_RECUR_LOOPS];
static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;

void yyerror(const char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
void assignVariable(const std::string &name, int index, int assignType,
                    double value);
void assignVariables(const std::string &name, List_T *indices, int assignType,
                     List_T *values);
void incrementVariable(const std::string &name, int index, double value);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
void PrintParserSymbols(std::vector<std::string> &vec);
fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list);

void addPeriodicEdge(int,int,const std::vector<double>&);
void addPeriodicFace(int,int,const std::map<int,int>&);
void addPeriodicFace(int,int,const std::vector<double>&);
void computeAffineTransformation(SPoint3&,SPoint3&,double,SPoint3&,std::vector<double>&);

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
#line 105 "Gmsh.y"
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
#line 584 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 597 "Gmsh.tab.cpp"

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
#define YYLAST   10157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  204
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  518
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1835

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   438

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   189,     2,   199,     2,   188,     2,     2,
     194,   195,   186,   184,   200,   185,   198,   187,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     180,     2,   181,   175,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   196,     2,   197,   193,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   201,     2,   202,   203,     2,     2,     2,
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
     176,   177,   178,   179,   182,   183,   190,   191,   192
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
    1381,  1383,  1386,  1389,  1391,  1395,  1399,  1404,  1406,  1412,
    1424,  1438,  1439,  1447,  1448,  1462,  1463,  1479,  1480,  1487,
    1496,  1505,  1514,  1527,  1540,  1553,  1568,  1583,  1598,  1599,
    1612,  1613,  1626,  1627,  1640,  1641,  1658,  1659,  1676,  1677,
    1694,  1695,  1714,  1715,  1734,  1735,  1754,  1756,  1759,  1765,
    1773,  1783,  1786,  1789,  1792,  1796,  1799,  1803,  1806,  1810,
    1813,  1817,  1827,  1834,  1835,  1839,  1840,  1842,  1843,  1846,
    1847,  1850,  1851,  1854,  1862,  1869,  1878,  1884,  1888,  1896,
    1902,  1907,  1914,  1926,  1938,  1957,  1976,  1989,  2002,  2015,
    2026,  2037,  2048,  2059,  2070,  2075,  2080,  2085,  2090,  2095,
    2098,  2102,  2109,  2111,  2113,  2115,  2118,  2124,  2132,  2143,
    2145,  2149,  2152,  2155,  2158,  2162,  2166,  2170,  2174,  2178,
    2182,  2186,  2190,  2194,  2198,  2202,  2206,  2210,  2214,  2220,
    2225,  2230,  2235,  2240,  2245,  2250,  2255,  2260,  2265,  2270,
    2277,  2282,  2287,  2292,  2297,  2302,  2307,  2312,  2319,  2326,
    2333,  2338,  2340,  2342,  2344,  2346,  2348,  2350,  2352,  2354,
    2356,  2358,  2359,  2366,  2371,  2373,  2378,  2383,  2388,  2393,
    2398,  2403,  2408,  2411,  2417,  2423,  2429,  2435,  2439,  2446,
    2451,  2459,  2466,  2473,  2480,  2487,  2492,  2494,  2497,  2500,
    2504,  2508,  2520,  2530,  2538,  2546,  2548,  2552,  2554,  2556,
    2559,  2563,  2568,  2574,  2576,  2578,  2581,  2585,  2589,  2595,
    2600,  2603,  2606,  2609,  2612,  2616,  2620,  2624,  2628,  2634,
    2640,  2646,  2652,  2669,  2686,  2703,  2720,  2722,  2724,  2728,
    2732,  2737,  2744,  2751,  2753,  2755,  2759,  2763,  2773,  2781,
    2783,  2789,  2793,  2800,  2802,  2806,  2808,  2810,  2814,  2821,
    2823,  2828,  2830,  2832,  2834,  2839,  2846,  2851,  2856,  2861,
    2866,  2875,  2880,  2885,  2890,  2895,  2904,  2909,  2916,  2921,
    2923,  2924,  2931,  2933,  2937,  2943,  2949,  2951,  2953
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     205,     0,    -1,   206,    -1,     1,     6,    -1,    -1,   206,
     207,    -1,   210,    -1,   209,    -1,   230,    -1,   247,    -1,
     248,    -1,   252,    -1,   253,    -1,   254,    -1,   255,    -1,
     258,    -1,   279,    -1,   280,    -1,   257,    -1,   256,    -1,
     251,    -1,   282,    -1,   181,    -1,   181,   181,    -1,    37,
     194,   296,   195,     6,    -1,    38,   194,   296,   195,     6,
      -1,    37,   194,   296,   195,   208,   296,     6,    -1,    37,
     194,   296,   200,   292,   195,     6,    -1,    38,   194,   296,
     200,   292,   195,     6,    -1,    37,   194,   296,   200,   292,
     195,   208,   296,     6,    -1,     4,   296,   201,   211,   202,
       6,    -1,   120,     4,   196,   283,   197,     6,    -1,   121,
       4,   196,   283,   197,     6,    -1,   122,     4,   196,   283,
     200,   283,   197,     6,    -1,    -1,   211,   214,    -1,   211,
     218,    -1,   211,   221,    -1,   211,   223,    -1,   211,   224,
      -1,   283,    -1,   212,   200,   283,    -1,   283,    -1,   213,
     200,   283,    -1,    -1,    -1,     4,   215,   194,   212,   195,
     216,   201,   213,   202,     6,    -1,   296,    -1,   217,   200,
     296,    -1,    -1,   129,   194,   283,   200,   283,   200,   283,
     195,   219,   201,   217,   202,     6,    -1,   296,    -1,   220,
     200,   296,    -1,    -1,   130,   194,   283,   200,   283,   200,
     283,   200,   283,   195,   222,   201,   220,   202,     6,    -1,
     131,   201,   288,   202,   201,   288,   202,     6,    -1,   131,
     201,   288,   202,   201,   288,   202,   201,   288,   202,   201,
     288,   202,     6,    -1,    -1,   132,   225,   201,   213,   202,
       6,    -1,     7,    -1,   174,    -1,   173,    -1,   172,    -1,
     171,    -1,   192,    -1,   191,    -1,   194,    -1,   196,    -1,
     195,    -1,   197,    -1,    69,   196,   232,   197,     6,    -1,
      70,   196,   235,   197,     6,    -1,    73,   228,   297,   200,
     283,   229,     6,    -1,    74,   228,   301,   200,   297,   229,
       6,    -1,   301,   226,   289,     6,    -1,     4,   228,   229,
     226,   289,     6,    -1,   300,   228,   229,   226,   289,     6,
      -1,     4,   196,   283,   197,   226,   283,     6,    -1,     4,
     194,   283,   195,   226,   283,     6,    -1,   300,   196,   283,
     197,   226,   283,     6,    -1,   300,   194,   283,   195,   226,
     283,     6,    -1,     4,   228,   201,   292,   202,   229,   226,
     289,     6,    -1,   300,   228,   201,   292,   202,   229,   226,
     289,     6,    -1,   301,   227,     6,    -1,     4,   196,   283,
     197,   227,     6,    -1,     4,   194,   283,   195,   227,     6,
      -1,   300,   196,   283,   197,   227,     6,    -1,   300,   194,
     283,   195,   227,     6,    -1,   301,     7,   297,     6,    -1,
       4,   198,     4,     7,   297,     6,    -1,     4,   196,   283,
     197,   198,     4,     7,   297,     6,    -1,     4,   198,     4,
     226,   283,     6,    -1,     4,   196,   283,   197,   198,     4,
     226,   283,     6,    -1,     4,   198,     4,   227,     6,    -1,
       4,   196,   283,   197,   198,     4,   227,     6,    -1,     4,
     198,   139,   198,     4,     7,   293,     6,    -1,     4,   196,
     283,   197,   198,   139,   198,     4,     7,   293,     6,    -1,
       4,   198,   140,     7,   294,     6,    -1,     4,   196,   283,
     197,   198,   140,     7,   294,     6,    -1,     4,   148,     7,
     283,     6,    -1,   148,   196,   283,   197,     7,     4,     6,
      -1,   148,   196,   283,   197,   198,     4,     7,   283,     6,
      -1,   148,   196,   283,   197,   198,     4,     7,   297,     6,
      -1,   148,   196,   283,   197,   198,     4,     7,   201,   292,
     202,     6,    -1,   148,   196,   283,   197,   198,     4,     6,
      -1,    99,   194,     4,   195,   198,     4,     7,   283,     6,
      -1,    99,   194,     4,   195,   198,     4,     7,   297,     6,
      -1,    -1,   200,    -1,    -1,   232,   231,   301,    -1,   232,
     231,   301,     7,   283,    -1,    -1,   232,   231,   301,     7,
     201,   289,   233,   237,   202,    -1,   232,   231,   301,     7,
     297,    -1,    -1,   232,   231,   301,     7,   201,   297,   234,
     239,   202,    -1,    -1,   235,   231,   296,    -1,   283,     7,
     297,    -1,   236,   200,   283,     7,   297,    -1,    -1,   237,
     238,    -1,   200,     4,   289,    -1,   200,     4,   201,   236,
     202,    -1,   200,     4,   297,    -1,    -1,   239,   240,    -1,
     200,     4,   283,    -1,   200,     4,   297,    -1,   200,   151,
     297,    -1,   200,     4,   201,   299,   202,    -1,   283,    -1,
     297,    -1,   297,   200,   283,    -1,   283,    -1,   297,    -1,
     297,   200,   283,    -1,   283,    -1,   297,    -1,   297,   200,
     283,    -1,   283,    -1,   297,    -1,   297,   200,   283,    -1,
      -1,   142,    79,   201,   283,   202,    -1,    -1,    91,   286,
      -1,    75,   194,   283,   195,     7,   286,     6,    -1,    95,
      75,   194,   241,   195,   226,   289,     6,    -1,    84,    85,
     289,     7,   283,     6,    -1,    78,   194,   283,   195,     7,
     289,     6,    -1,   100,    78,   289,     6,    -1,    82,   194,
     283,   195,     7,   289,     6,    -1,    76,   194,   283,   195,
       7,   289,   246,     6,    -1,    77,   194,   283,   195,     7,
     289,   246,     6,    -1,   134,   194,   283,   195,     7,   289,
       6,    -1,   135,   194,   283,   195,     7,   289,     6,    -1,
     136,   194,   283,   195,     7,   289,   138,   289,   137,   283,
       6,    -1,    78,     4,   194,   283,   195,     7,   289,     6,
      -1,    96,    78,   194,   283,   195,     7,   289,     6,    -1,
      95,    78,   194,   242,   195,   226,   289,     6,    -1,    91,
      81,   194,   283,   195,     7,   289,     6,    -1,    92,    81,
     194,   283,   195,     7,   289,   245,     6,    -1,    12,    13,
       6,    -1,    13,    81,   283,     6,    -1,    86,    81,   194,
     283,   195,     7,     5,     5,     5,     6,    -1,    79,   194,
     283,   195,     7,   289,     6,    -1,    80,   194,   283,   195,
       7,   289,     6,    -1,    81,     4,   194,   283,   195,     7,
     289,     6,    -1,    96,    81,   194,   283,   195,     7,   289,
       6,    -1,    96,    81,   194,   283,   195,     7,   289,     4,
     201,   288,   202,     6,    -1,    95,    81,   194,   243,   195,
     226,   289,     6,    -1,    94,    83,   194,   283,   195,     7,
     289,     6,    -1,    83,   194,   283,   195,     7,   289,     6,
      -1,    96,    83,   194,   283,   195,     7,   289,     6,    -1,
      95,    83,   194,   244,   195,   226,   289,     6,    -1,   103,
     286,   201,   249,   202,    -1,   102,   201,   286,   200,   286,
     200,   283,   202,   201,   249,   202,    -1,   104,   286,   201,
     249,   202,    -1,   105,   201,   286,   200,   283,   202,   201,
     249,   202,    -1,   105,   201,   286,   200,   286,   202,   201,
     249,   202,    -1,     4,   201,   249,   202,    -1,   114,    78,
     201,   292,   202,    81,   201,   283,   202,    -1,   111,    78,
     194,   283,   195,   201,   292,   202,     6,    -1,   250,    -1,
     248,    -1,    -1,   250,   247,    -1,   250,    75,   201,   292,
     202,     6,    -1,   250,    78,   201,   292,   202,     6,    -1,
     250,    81,   201,   292,   202,     6,    -1,   250,    83,   201,
     292,   202,     6,    -1,   107,    91,   194,   283,   195,     7,
     289,     6,    -1,   107,    75,   194,   283,   195,     7,   201,
     288,   202,     6,    -1,   107,    91,   194,   283,   195,     7,
     201,   286,   200,   286,   200,   292,   202,     6,    -1,   107,
      91,   194,   283,   195,     7,   201,   286,   200,   286,   200,
     286,   200,   292,   202,     6,    -1,   107,    79,   194,   283,
     195,     7,   201,   286,   200,   292,   202,     6,    -1,   107,
       4,   194,   283,   195,     7,   289,     6,    -1,   107,     4,
     194,   283,   195,     7,     5,     6,    -1,   107,     4,   201,
     283,   202,     6,    -1,   107,     4,   194,   283,   195,     7,
     201,   286,   200,   286,   200,   292,   202,     6,    -1,   112,
     201,   250,   202,    -1,   112,   148,   196,   283,   197,     6,
      -1,   112,     4,   196,   283,   197,     6,    -1,   112,   301,
       6,    -1,   112,     4,     4,     6,    -1,   139,   293,   201,
     250,   202,    -1,   101,   139,   293,   201,   250,   202,    -1,
     168,   283,   201,   250,   202,    -1,   152,     5,     6,    -1,
     153,     5,     6,    -1,   152,   201,   250,   202,    -1,   101,
     152,   201,   250,   202,    -1,   153,   201,   250,   202,    -1,
     101,   153,   201,   250,   202,    -1,     4,   297,     6,    -1,
      62,   194,   299,   195,     6,    -1,     4,     4,   196,   283,
     197,   296,     6,    -1,     4,     4,     4,   196,   283,   197,
       6,    -1,     4,   283,     6,    -1,    99,   194,     4,   195,
     198,     4,     6,    -1,   133,     4,     6,    -1,   146,     6,
      -1,   147,     6,    -1,    59,     6,    -1,    60,     6,    -1,
      53,     6,    -1,    53,   201,   283,   200,   283,   200,   283,
     200,   283,   200,   283,   200,   283,   202,     6,    -1,    54,
       6,    -1,    55,     6,    -1,    66,     6,    -1,    67,     6,
      -1,    88,     6,    -1,    89,   201,   292,   202,   201,   292,
     202,   201,   288,   202,   201,   283,   200,   283,   202,     6,
      -1,   161,   283,     6,    -1,   141,   194,   283,     8,   283,
     195,    -1,   141,   194,   283,     8,   283,     8,   283,   195,
      -1,   141,     4,   142,   201,   283,     8,   283,   202,    -1,
     141,     4,   142,   201,   283,     8,   283,     8,   283,   202,
      -1,   143,    -1,   151,     4,    -1,   151,   297,    -1,   149,
      -1,   150,   301,     6,    -1,   150,   297,     6,    -1,   144,
     194,   283,   195,    -1,   145,    -1,   106,   286,   201,   250,
     202,    -1,   106,   201,   286,   200,   286,   200,   283,   202,
     201,   250,   202,    -1,   106,   201,   286,   200,   286,   200,
     286,   200,   283,   202,   201,   250,   202,    -1,    -1,   106,
     286,   201,   250,   259,   272,   202,    -1,    -1,   106,   201,
     286,   200,   286,   200,   283,   202,   201,   250,   260,   272,
     202,    -1,    -1,   106,   201,   286,   200,   286,   200,   286,
     200,   283,   202,   201,   250,   261,   272,   202,    -1,    -1,
     106,   201,   250,   262,   272,   202,    -1,   106,    75,   201,
     283,   200,   286,   202,     6,    -1,   106,    78,   201,   283,
     200,   286,   202,     6,    -1,   106,    81,   201,   283,   200,
     286,   202,     6,    -1,   106,    75,   201,   283,   200,   286,
     200,   286,   200,   283,   202,     6,    -1,   106,    78,   201,
     283,   200,   286,   200,   286,   200,   283,   202,     6,    -1,
     106,    81,   201,   283,   200,   286,   200,   286,   200,   283,
     202,     6,    -1,   106,    75,   201,   283,   200,   286,   200,
     286,   200,   286,   200,   283,   202,     6,    -1,   106,    78,
     201,   283,   200,   286,   200,   286,   200,   286,   200,   283,
     202,     6,    -1,   106,    81,   201,   283,   200,   286,   200,
     286,   200,   286,   200,   283,   202,     6,    -1,    -1,   106,
      75,   201,   283,   200,   286,   202,   263,   201,   272,   202,
       6,    -1,    -1,   106,    78,   201,   283,   200,   286,   202,
     264,   201,   272,   202,     6,    -1,    -1,   106,    81,   201,
     283,   200,   286,   202,   265,   201,   272,   202,     6,    -1,
      -1,   106,    75,   201,   283,   200,   286,   200,   286,   200,
     283,   202,   266,   201,   272,   202,     6,    -1,    -1,   106,
      78,   201,   283,   200,   286,   200,   286,   200,   283,   202,
     267,   201,   272,   202,     6,    -1,    -1,   106,    81,   201,
     283,   200,   286,   200,   286,   200,   283,   202,   268,   201,
     272,   202,     6,    -1,    -1,   106,    75,   201,   283,   200,
     286,   200,   286,   200,   286,   200,   283,   202,   269,   201,
     272,   202,     6,    -1,    -1,   106,    78,   201,   283,   200,
     286,   200,   286,   200,   286,   200,   283,   202,   270,   201,
     272,   202,     6,    -1,    -1,   106,    81,   201,   283,   200,
     286,   200,   286,   200,   286,   200,   283,   202,   271,   201,
     272,   202,     6,    -1,   273,    -1,   272,   273,    -1,   117,
     201,   283,   202,     6,    -1,   117,   201,   289,   200,   289,
     202,     6,    -1,   117,   201,   289,   200,   289,   200,   289,
     202,     6,    -1,   118,     6,    -1,   109,     6,    -1,   125,
       6,    -1,   125,   127,     6,    -1,   126,     6,    -1,   126,
     127,     6,    -1,   123,     6,    -1,   123,   127,     6,    -1,
     124,     6,    -1,   124,   127,     6,    -1,   119,   194,   283,
     195,     7,   289,    98,   283,     6,    -1,    98,     4,   196,
     283,   197,     6,    -1,    -1,    98,     4,   283,    -1,    -1,
       4,    -1,    -1,     7,   289,    -1,    -1,     7,   283,    -1,
      -1,   108,   289,    -1,    93,    78,   290,     7,   283,   274,
       6,    -1,    93,    81,   290,   276,   275,     6,    -1,    87,
      81,   201,   283,   202,     7,   289,     6,    -1,    93,    83,
     290,   276,     6,    -1,   128,   290,     6,    -1,   115,    81,
     201,   292,   202,   283,     6,    -1,   109,    81,   290,   277,
       6,    -1,   109,    83,   290,     6,    -1,   110,    81,   289,
       7,   283,     6,    -1,    97,    78,   201,   292,   202,     7,
     201,   292,   202,   278,     6,    -1,    97,    81,   201,   292,
     202,     7,   201,   292,   202,   278,     6,    -1,    97,    78,
     201,   292,   202,     7,   201,   292,   202,   102,   201,   286,
     200,   286,   200,   283,   202,     6,    -1,    97,    81,   201,
     292,   202,     7,   201,   292,   202,   102,   201,   286,   200,
     286,   200,   283,   202,     6,    -1,    97,    78,   201,   292,
     202,     7,   201,   292,   202,   103,   286,     6,    -1,    97,
      81,   201,   292,   202,     7,   201,   292,   202,   103,   286,
       6,    -1,    97,    81,   283,   201,   292,   202,     7,   283,
     201,   292,   202,     6,    -1,    75,   201,   292,   202,   142,
      81,   201,   283,   202,     6,    -1,    78,   201,   292,   202,
     142,    81,   201,   283,   202,     6,    -1,    75,   201,   292,
     202,   142,    83,   201,   283,   202,     6,    -1,    78,   201,
     292,   202,   142,    83,   201,   283,   202,     6,    -1,    81,
     201,   292,   202,   142,    83,   201,   283,   202,     6,    -1,
     116,    81,   290,     6,    -1,   116,    78,   290,     6,    -1,
      90,    75,   290,     6,    -1,    90,    78,   290,     6,    -1,
      90,    81,   290,     6,    -1,   113,     6,    -1,   113,     4,
       6,    -1,   113,    75,   201,   292,   202,     6,    -1,   158,
      -1,   159,    -1,   160,    -1,   281,     6,    -1,   281,   201,
     289,   202,     6,    -1,   281,   201,   289,   200,   289,   202,
       6,    -1,   281,   194,   289,   195,   201,   289,   200,   289,
     202,     6,    -1,   284,    -1,   194,   283,   195,    -1,   185,
     283,    -1,   184,   283,    -1,   189,   283,    -1,   283,   185,
     283,    -1,   283,   184,   283,    -1,   283,   186,   283,    -1,
     283,   187,   283,    -1,   283,   188,   283,    -1,   283,   193,
     283,    -1,   283,   180,   283,    -1,   283,   181,   283,    -1,
     283,   183,   283,    -1,   283,   182,   283,    -1,   283,   179,
     283,    -1,   283,   178,   283,    -1,   283,   177,   283,    -1,
     283,   176,   283,    -1,   283,   175,   283,     8,   283,    -1,
      14,   228,   283,   229,    -1,    15,   228,   283,   229,    -1,
      16,   228,   283,   229,    -1,    17,   228,   283,   229,    -1,
      18,   228,   283,   229,    -1,    19,   228,   283,   229,    -1,
      20,   228,   283,   229,    -1,    21,   228,   283,   229,    -1,
      22,   228,   283,   229,    -1,    24,   228,   283,   229,    -1,
      25,   228,   283,   200,   283,   229,    -1,    26,   228,   283,
     229,    -1,    27,   228,   283,   229,    -1,    28,   228,   283,
     229,    -1,    29,   228,   283,   229,    -1,    30,   228,   283,
     229,    -1,    31,   228,   283,   229,    -1,    32,   228,   283,
     229,    -1,    33,   228,   283,   200,   283,   229,    -1,    34,
     228,   283,   200,   283,   229,    -1,    35,   228,   283,   200,
     283,   229,    -1,    23,   228,   283,   229,    -1,     3,    -1,
       9,    -1,    10,    -1,    11,    -1,   164,    -1,   165,    -1,
     166,    -1,    63,    -1,    64,    -1,    65,    -1,    -1,    71,
     228,   283,   285,   237,   229,    -1,   157,   228,   296,   229,
      -1,   301,    -1,     4,   196,   283,   197,    -1,     4,   194,
     283,   195,    -1,   300,   196,   283,   197,    -1,   300,   194,
     283,   195,    -1,   162,   194,   301,   195,    -1,   163,   194,
     297,   195,    -1,   199,   301,   228,   229,    -1,   301,   227,
      -1,     4,   196,   283,   197,   227,    -1,     4,   194,   283,
     195,   227,    -1,   300,   196,   283,   197,   227,    -1,   300,
     194,   283,   195,   227,    -1,     4,   198,     4,    -1,     4,
     196,   283,   197,   198,     4,    -1,     4,   198,     4,   227,
      -1,     4,   196,   283,   197,   198,     4,   227,    -1,   154,
     194,   296,   200,   283,   195,    -1,    45,   194,   289,   200,
     289,   195,    -1,    46,   194,   296,   200,   296,   195,    -1,
      47,   194,   296,   200,   296,   195,    -1,    52,   194,   299,
     195,    -1,   287,    -1,   185,   286,    -1,   184,   286,    -1,
     286,   185,   286,    -1,   286,   184,   286,    -1,   201,   283,
     200,   283,   200,   283,   200,   283,   200,   283,   202,    -1,
     201,   283,   200,   283,   200,   283,   200,   283,   202,    -1,
     201,   283,   200,   283,   200,   283,   202,    -1,   194,   283,
     200,   283,   200,   283,   195,    -1,   289,    -1,   288,   200,
     289,    -1,   283,    -1,   291,    -1,   201,   202,    -1,   201,
     292,   202,    -1,   185,   201,   292,   202,    -1,   283,   186,
     201,   292,   202,    -1,   289,    -1,     5,    -1,   185,   291,
      -1,   283,   186,   291,    -1,   283,     8,   283,    -1,   283,
       8,   283,     8,   283,    -1,    75,   201,   283,   202,    -1,
      75,     5,    -1,    78,     5,    -1,    81,     5,    -1,    83,
       5,    -1,    95,    75,     5,    -1,    95,    78,     5,    -1,
      95,    81,     5,    -1,    95,    83,     5,    -1,    95,    75,
     201,   292,   202,    -1,    95,    78,   201,   292,   202,    -1,
      95,    81,   201,   292,   202,    -1,    95,    83,   201,   292,
     202,    -1,    75,   142,    53,   201,   283,   200,   283,   200,
     283,   200,   283,   200,   283,   200,   283,   202,    -1,    78,
     142,    53,   201,   283,   200,   283,   200,   283,   200,   283,
     200,   283,   200,   283,   202,    -1,    81,   142,    53,   201,
     283,   200,   283,   200,   283,   200,   283,   200,   283,   200,
     283,   202,    -1,    83,   142,    53,   201,   283,   200,   283,
     200,   283,   200,   283,   200,   283,   200,   283,   202,    -1,
     248,    -1,   258,    -1,     4,   228,   229,    -1,   300,   228,
     229,    -1,    36,   196,   301,   197,    -1,     4,   228,   201,
     292,   202,   229,    -1,   300,   228,   201,   292,   202,   229,
      -1,   283,    -1,   291,    -1,   292,   200,   283,    -1,   292,
     200,   291,    -1,   201,   283,   200,   283,   200,   283,   200,
     283,   202,    -1,   201,   283,   200,   283,   200,   283,   202,
      -1,     4,    -1,     4,   198,   139,   198,     4,    -1,   201,
     295,   202,    -1,     4,   196,   283,   197,   198,   140,    -1,
     293,    -1,   295,   200,   293,    -1,   297,    -1,   301,    -1,
       4,   198,     4,    -1,     4,   196,   283,   197,   198,     4,
      -1,     5,    -1,   170,   196,   301,   197,    -1,    56,    -1,
     167,    -1,    61,    -1,   155,   194,   296,   195,    -1,   156,
     194,   296,   200,   296,   195,    -1,   156,   194,   296,   195,
      -1,    41,   228,   299,   229,    -1,    42,   194,   296,   195,
      -1,    43,   194,   296,   195,    -1,    44,   194,   296,   200,
     296,   200,   296,   195,    -1,    39,   228,   299,   229,    -1,
      49,   228,   296,   229,    -1,    50,   228,   296,   229,    -1,
      51,   228,   296,   229,    -1,    48,   228,   283,   200,   297,
     200,   297,   229,    -1,    40,   228,   296,   229,    -1,    40,
     228,   296,   200,   292,   229,    -1,    57,   228,   296,   229,
      -1,    58,    -1,    -1,    72,   228,   297,   298,   239,   229,
      -1,   296,    -1,   299,   200,   296,    -1,     4,   203,   201,
     283,   202,    -1,   300,   203,   201,   283,   202,    -1,     4,
      -1,   300,    -1,   169,   196,   296,   197,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   192,   192,   193,   198,   200,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   223,   227,   234,   239,   244,   258,   271,   284,
     312,   326,   339,   352,   371,   376,   377,   378,   379,   380,
     384,   386,   391,   393,   399,   503,   398,   521,   528,   539,
     538,   556,   563,   574,   573,   590,   607,   630,   629,   643,
     644,   645,   646,   647,   651,   652,   658,   658,   659,   659,
     665,   666,   667,   672,   678,   738,   767,   796,   801,   806,
     811,   816,   823,   830,   845,   850,   855,   860,   865,   874,
     880,   889,   907,   925,   934,   946,   951,   959,   979,  1002,
    1013,  1021,  1043,  1066,  1092,  1113,  1125,  1139,  1139,  1141,
    1143,  1152,  1162,  1161,  1179,  1189,  1188,  1202,  1204,  1212,
    1218,  1225,  1226,  1230,  1241,  1256,  1266,  1267,  1272,  1280,
    1289,  1297,  1315,  1319,  1325,  1333,  1337,  1343,  1351,  1355,
    1361,  1369,  1373,  1379,  1388,  1391,  1404,  1407,  1417,  1440,
    1472,  1495,  1513,  1534,  1552,  1582,  1612,  1630,  1648,  1675,
    1693,  1711,  1746,  1764,  1803,  1809,  1815,  1822,  1847,  1872,
    1889,  1908,  1942,  1978,  1996,  2013,  2029,  2066,  2071,  2076,
    2081,  2086,  2091,  2114,  2120,  2131,  2132,  2137,  2140,  2144,
    2167,  2190,  2213,  2241,  2262,  2288,  2309,  2331,  2351,  2463,
    2482,  2520,  2629,  2638,  2644,  2659,  2687,  2704,  2713,  2727,
    2741,  2747,  2753,  2762,  2771,  2780,  2794,  2850,  2868,  2885,
    2900,  2919,  2931,  2955,  2959,  2964,  2971,  2976,  2982,  2987,
    2993,  3001,  3005,  3009,  3014,  3069,  3082,  3099,  3116,  3138,
    3160,  3195,  3203,  3211,  3217,  3224,  3231,  3235,  3244,  3252,
    3260,  3269,  3268,  3283,  3282,  3297,  3296,  3311,  3310,  3324,
    3331,  3338,  3345,  3352,  3359,  3366,  3373,  3380,  3388,  3387,
    3401,  3400,  3414,  3413,  3427,  3426,  3440,  3439,  3453,  3452,
    3466,  3465,  3479,  3478,  3492,  3491,  3508,  3511,  3517,  3529,
    3549,  3573,  3577,  3581,  3585,  3589,  3595,  3601,  3605,  3609,
    3613,  3617,  3636,  3649,  3652,  3668,  3671,  3688,  3691,  3697,
    3700,  3707,  3710,  3717,  3773,  3843,  3848,  3915,  3951,  3959,
    4002,  4041,  4061,  4093,  4120,  4146,  4172,  4198,  4224,  4246,
    4274,  4302,  4306,  4310,  4338,  4377,  4416,  4437,  4458,  4485,
    4489,  4499,  4534,  4535,  4536,  4540,  4546,  4558,  4576,  4604,
    4605,  4606,  4607,  4608,  4609,  4610,  4611,  4612,  4619,  4620,
    4621,  4622,  4623,  4624,  4625,  4626,  4627,  4628,  4629,  4630,
    4631,  4632,  4633,  4634,  4635,  4636,  4637,  4638,  4639,  4640,
    4641,  4642,  4643,  4644,  4645,  4646,  4647,  4648,  4649,  4650,
    4651,  4660,  4661,  4662,  4663,  4664,  4665,  4666,  4667,  4668,
    4669,  4674,  4673,  4681,  4686,  4703,  4721,  4739,  4757,  4775,
    4780,  4786,  4798,  4815,  4833,  4851,  4869,  4890,  4895,  4900,
    4910,  4920,  4925,  4936,  4945,  4950,  4977,  4981,  4985,  4989,
    4993,  5000,  5004,  5008,  5012,  5019,  5024,  5031,  5036,  5040,
    5045,  5049,  5057,  5068,  5072,  5084,  5092,  5100,  5107,  5117,
    5146,  5150,  5154,  5158,  5162,  5166,  5170,  5174,  5178,  5207,
    5236,  5265,  5294,  5307,  5320,  5333,  5346,  5356,  5366,  5378,
    5391,  5403,  5421,  5442,  5447,  5451,  5455,  5467,  5471,  5483,
    5490,  5500,  5504,  5519,  5524,  5531,  5535,  5548,  5556,  5567,
    5571,  5575,  5583,  5589,  5595,  5603,  5611,  5618,  5633,  5647,
    5661,  5673,  5689,  5698,  5707,  5717,  5728,  5732,  5751,  5758,
    5765,  5764,  5777,  5782,  5788,  5797,  5810,  5813,  5817
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tDOUBLE", "tSTRING", "tBIGSTR", "tEND",
  "tAFFECT", "tDOTS", "tPi", "tMPI_Rank", "tMPI_Size", "tEuclidian",
  "tCoordinates", "tExp", "tLog", "tLog10", "tSqrt", "tSin", "tAsin",
  "tCos", "tAcos", "tTan", "tRand", "tAtan", "tAtan2", "tSinh", "tCosh",
  "tTanh", "tFabs", "tFloor", "tCeil", "tRound", "tFmod", "tModulo",
  "tHypot", "tList", "tPrintf", "tError", "tStr", "tSprintf", "tStrCat",
  "tStrPrefix", "tStrRelative", "tStrReplace", "tFind", "tStrFind",
  "tStrCmp", "tStrChoice", "tUpperCase", "tLowerCase", "tLowerCaseIn",
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
  "tEndIf", "tExit", "tAbort", "tField", "tReturn", "tCall", "tMacro",
  "tShow", "tHide", "tGetValue", "tGetEnv", "tGetString", "tGetNumber",
  "tHomology", "tCohomology", "tBetti", "tSetOrder", "tExists",
  "tFileExists", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION",
  "tGMSH_PATCH_VERSION", "tGmshExecutableName", "tSetPartition",
  "tNameFromString", "tStringFromName", "tAFFECTDIVIDE", "tAFFECTTIMES",
  "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND", "tNOTEQUAL",
  "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS",
  "'^'", "'('", "')'", "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'",
  "'~'", "$accept", "All", "GeoFormatItems", "GeoFormatItem", "SendToFile",
  "Printf", "View", "Views", "ElementCoords", "ElementValues", "Element",
  "@1", "@2", "Text2DValues", "Text2D", "@3", "Text3DValues", "Text3D",
  "@4", "InterpolationMatrix", "Time", "@5", "NumericAffectation",
  "NumericIncrement", "LP", "RP", "Affectation", "Comma",
  "DefineConstants", "@6", "@7", "UndefineConstants", "Enumeration",
  "FloatParameterOptions", "FloatParameterOption", "CharParameterOptions",
  "CharParameterOption", "PhysicalId0", "PhysicalId1", "PhysicalId2",
  "PhysicalId3", "InSphereCenter", "CircleOptions", "Shape", "Transform",
  "MultipleShape", "ListOfShapes", "LevelSet", "Delete", "Colorify",
  "SetPartition", "Visibility", "Command", "Loop", "Extrude", "@8", "@9",
  "@10", "@11", "@12", "@13", "@14", "@15", "@16", "@17", "@18", "@19",
  "@20", "ExtrudeParameters", "ExtrudeParameter", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "PeriodicTransform", "Constraints", "Coherence", "HomologyCommand",
  "Homology", "FExpr", "FExpr_Single", "@21", "VExpr", "VExpr_Single",
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
     425,   426,   427,   428,   429,    63,   430,   431,   432,   433,
      60,    62,   434,   435,    43,    45,    42,    47,    37,    33,
     436,   437,   438,    94,    40,    41,    91,    93,    46,    35,
      44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   204,   205,   205,   206,   206,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   208,   208,   209,   209,   209,   209,   209,   209,
     210,   210,   210,   210,   211,   211,   211,   211,   211,   211,
     212,   212,   213,   213,   215,   216,   214,   217,   217,   219,
     218,   220,   220,   222,   221,   223,   223,   225,   224,   226,
     226,   226,   226,   226,   227,   227,   228,   228,   229,   229,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   231,   231,   232,
     232,   232,   233,   232,   232,   234,   232,   235,   235,   236,
     236,   237,   237,   238,   238,   238,   239,   239,   240,   240,
     240,   240,   241,   241,   241,   242,   242,   242,   243,   243,
     243,   244,   244,   244,   245,   245,   246,   246,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   248,   248,   248,
     248,   248,   248,   248,   248,   249,   249,   250,   250,   250,
     250,   250,   250,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   252,   252,   252,   252,   252,   253,   253,   254,
     255,   255,   255,   255,   255,   255,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   258,   258,
     258,   259,   258,   260,   258,   261,   258,   262,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   263,   258,
     264,   258,   265,   258,   266,   258,   267,   258,   268,   258,
     269,   258,   270,   258,   271,   258,   272,   272,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   274,   274,   275,   275,   276,   276,   277,
     277,   278,   278,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   280,
     280,   280,   281,   281,   281,   282,   282,   282,   282,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   285,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   286,   286,   286,   286,
     286,   287,   287,   287,   287,   288,   288,   289,   289,   289,
     289,   289,   289,   290,   290,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   292,   292,   292,   292,   293,   293,   293,
     293,   294,   294,   295,   295,   296,   296,   296,   296,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     298,   297,   299,   299,   300,   300,   301,   301,   301
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
       1,     2,     2,     1,     3,     3,     4,     1,     5,    11,
      13,     0,     7,     0,    13,     0,    15,     0,     6,     8,
       8,     8,    12,    12,    12,    14,    14,    14,     0,    12,
       0,    12,     0,    12,     0,    16,     0,    16,     0,    16,
       0,    18,     0,    18,     0,    18,     1,     2,     5,     7,
       9,     2,     2,     2,     3,     2,     3,     2,     3,     2,
       3,     9,     6,     0,     3,     0,     1,     0,     2,     0,
       2,     0,     2,     7,     6,     8,     5,     3,     7,     5,
       4,     6,    11,    11,    18,    18,    12,    12,    12,    10,
      10,    10,    10,    10,     4,     4,     4,     4,     4,     2,
       3,     6,     1,     1,     1,     2,     5,     7,    10,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     4,     1,     4,     4,     4,     4,     4,
       4,     4,     2,     5,     5,     5,     5,     3,     6,     4,
       7,     6,     6,     6,     6,     4,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     1,     3,     1,     1,     2,
       3,     4,     5,     1,     1,     2,     3,     3,     5,     4,
       2,     2,     2,     2,     3,     3,     3,     3,     5,     5,
       5,     5,    16,    16,    16,    16,     1,     1,     3,     3,
       4,     6,     6,     1,     1,     3,     3,     9,     7,     1,
       5,     3,     6,     1,     3,     1,     1,     3,     6,     1,
       4,     1,     1,     1,     4,     6,     4,     4,     4,     4,
       8,     4,     4,     4,     4,     8,     4,     6,     4,     1,
       0,     6,     1,     3,     5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   516,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,   247,     0,     0,     0,   243,     0,
       0,     0,     0,   342,   343,   344,     0,     0,     0,     5,
       7,     6,     8,     9,    10,    20,    11,    12,    13,    14,
      19,    18,    15,    16,    17,     0,    21,   517,     0,   391,
     516,   489,   392,   393,   394,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   491,     0,   509,   493,   398,   399,   400,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   395,   396,   397,
     492,     0,     0,     0,     0,    66,    67,     0,     0,   187,
       0,     0,     0,   349,     0,   485,   517,   404,     0,     0,
       0,     0,   227,     0,   229,   230,   225,   226,     0,   231,
     232,   109,   117,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   426,     0,     0,     0,     0,     0,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     516,     0,   187,   517,     0,     0,   339,     0,     0,     0,
       0,     0,     0,     0,     0,   516,   444,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   466,   467,   437,   443,
       0,   438,   517,   404,     0,     0,     0,     0,   479,     0,
       0,     0,     0,     0,   223,   224,     0,   516,     0,     0,
     241,   242,     0,   187,     0,   187,   516,     0,     0,     0,
     345,     0,     0,    66,    67,     0,     0,    59,    63,    62,
      61,    60,    65,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   352,   351,   353,
       0,     0,     0,     0,     0,     0,     0,   186,     0,   185,
       0,    68,    69,     0,     0,   220,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,   216,     0,     0,   412,   164,     0,   516,     0,
     485,   486,     0,     0,   512,     0,   107,   107,     0,     0,
       0,     0,   473,   474,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   307,   307,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,   187,     0,   428,   427,     0,     0,     0,
       0,   187,   187,     0,     0,     0,     0,     0,     0,     0,
     257,     0,   187,     0,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,     0,   205,   340,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    67,     0,     0,
       0,   450,     0,     0,   451,     0,   452,     0,   453,     0,
       0,     0,     0,     0,     0,   351,   445,     0,   439,     0,
       0,     0,   317,    66,    67,     0,   222,     0,     0,     0,
       0,     0,   187,     0,     0,     0,     0,   245,   244,   210,
       0,   211,     0,     0,   235,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
     417,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   401,   510,
       0,     0,     0,     0,     0,     0,     0,     0,   350,     0,
      59,     0,     0,     0,     0,     0,   182,     0,     0,     0,
       0,   188,     0,     0,    59,     0,     0,   367,   366,   365,
     364,   360,   361,   363,   362,   355,   354,   356,   357,   358,
     359,     0,     0,     0,   165,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,   337,   338,     0,     0,     0,     0,   305,     0,     0,
       0,   132,   133,     0,   135,   136,     0,   138,   139,     0,
     141,   142,     0,     0,     0,     0,     0,     0,     0,   152,
     187,     0,     0,     0,     0,     0,   430,   429,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   251,     0,     0,
       0,     0,     0,     0,     0,   320,     0,     0,   206,     0,
       0,   202,     0,     0,     0,   335,   334,     0,     0,     0,
       0,   417,     0,   468,     0,     0,     0,     0,     0,     0,
     454,     0,   455,     0,   456,     0,   457,     0,     0,   350,
     440,   447,     0,   356,   446,     0,   469,     0,     0,     0,
       0,     0,     0,     0,     0,   246,     0,   212,   214,     0,
     518,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      74,     0,   406,   405,   419,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   390,   378,     0,   380,   381,   382,
     383,   384,   385,   386,     0,     0,     0,   501,     0,   506,
     497,   498,   499,     0,     0,     0,     0,     0,   502,   503,
     504,   425,   508,   121,   126,    99,     0,   494,   496,     0,
     403,   409,   410,   490,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,     0,   411,     0,     0,     0,
       0,   514,     0,     0,     0,    44,     0,     0,     0,    57,
       0,    35,    36,    37,    38,    39,   408,   407,     0,   487,
      24,    22,     0,     0,    25,     0,     0,   217,   513,    70,
     110,    71,   118,     0,     0,     0,   475,   476,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   303,   308,   306,     0,
     316,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   215,
       0,     0,     0,   177,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,     0,   248,     0,     0,     0,     0,     0,     0,   310,
     319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   405,     0,   470,     0,   449,     0,     0,     0,     0,
       0,     0,     0,   441,     0,     0,     0,     0,     0,     0,
       0,     0,   207,     0,     0,     0,     0,   209,     0,     0,
     346,     0,     0,     0,     0,   515,     0,     0,     0,   414,
       0,   413,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,     0,
       0,     0,     0,    84,    89,    91,     0,     0,   483,     0,
      97,     0,     0,     0,     0,     0,    75,   368,     0,     0,
       0,     0,     0,    30,   416,   415,     0,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,     0,     0,     0,     0,     0,     0,     0,   314,     0,
       0,   134,     0,   137,     0,   140,     0,   143,     0,     0,
       0,     0,     0,     0,     0,   208,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   292,     0,   291,     0,   297,
       0,   299,     0,   293,     0,   295,     0,   258,   287,     0,
       0,     0,   200,     0,     0,     0,   321,     0,   204,   203,
     341,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,   458,   459,   460,   461,   448,   442,     0,     0,
       0,     0,   480,     0,     0,     0,   236,     0,     0,     0,
       0,     0,    87,     0,    86,     0,    76,   219,   418,   218,
     379,   387,   388,   389,   507,     0,   422,   423,   424,     0,
       0,   402,   122,     0,   511,   127,   421,   495,    78,    59,
       0,     0,     0,     0,    77,     0,     0,     0,   481,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   435,     0,
       0,    26,    27,     0,    28,     0,     0,   111,   114,    72,
      73,   148,     0,     0,     0,     0,     0,     0,   151,     0,
       0,   167,   168,     0,     0,   153,   174,     0,     0,     0,
       0,   144,     0,   313,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   221,     0,     0,     0,     0,
     187,   187,     0,   268,     0,   270,     0,   272,     0,   437,
       0,     0,   298,   300,   294,   296,     0,     0,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   318,     0,
     418,   471,     0,     0,     0,     0,   472,   156,   157,     0,
       0,     0,     0,   100,   104,     0,     0,   347,    80,    79,
       0,   420,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,    95,     0,   484,   189,   190,   191,   192,     0,
       0,    40,     0,     0,     0,     0,     0,    42,   488,     0,
       0,   112,   115,     0,     0,   147,   154,   155,   159,     0,
       0,   169,     0,     0,   315,     0,   162,     0,     0,   304,
     173,   149,   161,   172,   176,   160,     0,   170,   175,     0,
       0,     0,     0,     0,     0,   434,     0,   433,     0,     0,
       0,   259,     0,     0,   260,     0,     0,   261,     0,     0,
       0,     0,     0,     0,     0,   199,     0,     0,   198,     0,
       0,     0,   193,     0,     0,    33,     0,     0,     0,     0,
       0,     0,   478,     0,   238,   237,     0,     0,     0,     0,
       0,   500,   505,     0,   123,   125,     0,   128,   129,   130,
      90,    92,     0,    98,     0,    81,    45,     0,     0,     0,
     436,     0,     0,     0,    29,     0,   121,   126,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,   311,   311,
       0,   105,   106,   187,     0,   180,   181,     0,     0,     0,
       0,     0,     0,     0,   288,     0,     0,   187,     0,     0,
       0,     0,     0,   184,   183,     0,     0,     0,     0,     0,
       0,     0,     0,   101,   102,     0,    82,     0,   473,     0,
       0,   482,     0,    41,     0,     0,     0,    43,    58,     0,
       0,     0,   329,   331,   330,   332,   333,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,     0,     0,     0,   253,     0,     0,   194,     0,
       0,     0,     0,     0,     0,     0,   477,   239,     0,   348,
       0,   124,     0,   131,    96,     0,     0,     0,     0,     0,
     113,   116,     0,     0,     0,     0,     0,   312,   322,     0,
       0,   323,     0,   178,     0,   274,     0,     0,   276,     0,
       0,   278,     0,     0,     0,   289,     0,   249,     0,   187,
       0,     0,     0,     0,     0,     0,     0,   158,   103,     0,
     119,     0,    49,     0,    55,     0,     0,     0,   145,   171,
       0,   326,     0,   327,   328,   431,   262,     0,     0,   269,
     263,     0,     0,   271,   264,     0,     0,   273,     0,     0,
       0,   255,     0,   197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     280,     0,   282,     0,   284,   290,   301,   254,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   120,    46,     0,
      53,     0,     0,     0,     0,     0,     0,   265,     0,     0,
     266,     0,     0,   267,     0,     0,   201,     0,   195,     0,
       0,     0,     0,     0,    47,     0,     0,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,     0,     0,
     275,     0,   277,     0,   279,     0,   196,     0,     0,     0,
       0,    48,    50,     0,    51,     0,     0,     0,     0,     0,
       0,   462,   463,   464,   465,     0,     0,    56,   324,   325,
     281,   283,   285,    52,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    89,   932,    90,    91,   681,  1400,  1406,
     921,  1108,  1572,  1773,   922,  1722,  1813,   923,  1775,   924,
     925,  1112,   344,   435,   181,   414,    92,   696,   446,  1516,
    1517,   447,  1567,  1083,  1252,  1084,  1255,   730,   733,   736,
     739,  1428,  1295,   661,   296,   408,   409,    95,    96,    97,
      98,    99,   100,   101,   297,  1013,  1668,  1739,   765,  1452,
    1455,  1458,  1697,  1701,  1705,  1758,  1761,  1764,  1009,  1010,
    1147,   969,   727,   774,  1594,   103,   104,   105,   106,   298,
     183,   883,   496,   254,  1277,   299,   300,   301,   559,   310,
     905,  1099,   444,   440,   884,   445,   186,   303
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1344
static const yytype_int16 yypact[] =
{
    6580,    93,   116,  6699, -1344, -1344,  3508,   168,   150,  -181,
     -86,    45,   131,   179,   200,   264,    67,   268,   278,    98,
     134,  -163,  -163,   -80,   118,   142,    32,   190,   198,    31,
     215,   224,   274,   286,   401,   424,   289,   101,   443,   469,
     230,   422,   479,   585,   -22,   362,   542,   -66,   384,  -104,
    -104,   410,   454,    59,   -38,   514,   559,     8,    68,   568,
     588,   181,   682,   693,   702,  4841,   717,   530,   544,   557,
      35,    56, -1344,   558, -1344,   731,   780,   596, -1344,  1257,
    5886,     6,    39, -1344, -1344, -1344,  3709,  3709,   612, -1344,
   -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344,
   -1344, -1344, -1344, -1344, -1344,    51, -1344,   212,   132, -1344,
      22, -1344, -1344, -1344, -1344,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
     617,   623,   627,   644,   645,   660,  -163,  -163,  -163,  -163,
     669, -1344,  -163, -1344, -1344, -1344, -1344, -1344,  -163,  -163,
     807,   672,   680,   681,  -163,   686,   701, -1344, -1344, -1344,
   -1344,   622,  3709,  3709,  3709,  3709,  3709,    24,    14,   317,
     652,   228,   825, -1344,   707,   886,   270,   157,   896,  3709,
    2081,  2081, -1344,  3709, -1344, -1344, -1344, -1344,  2081, -1344,
   -1344, -1344, -1344, -1344, -1344,  6076,    14,  3709,  6442,  3709,
    3709,   709,  3709,  6442,  3709,  3709,   715,  6442,  3709,  3709,
    5227,   718,   726, -1344,  6442,  4841,  4841,  4841,   743,   747,
    4841,  4841,  4841,   750,   764,   769,   772,   778,   801,   802,
     827,   823,  3432,   973,  5227,    35,   824,   831,  -104,  -104,
    -104,  3709,  3709,  -101, -1344,   -57,  -104,   832,   836,   837,
    6192,   -23,   -69,   853,   854,   862,  4841,  4841,  5227,   887,
      12,   855, -1344,   888,  1065,  1093, -1344,   899,   912,   920,
    4841,  4841,   926,   930,   941,   255, -1344,   962,    -2,    15,
      18,    27,   690,  5420,  3709,  3998, -1344, -1344,   394, -1344,
    1138, -1344,   299,    10,  1153,  3709,  3709,  3709,   976,  3709,
     974,  1036,  3709,  3709, -1344, -1344,  3709,   979,  1177,  1180,
   -1344, -1344,  1181, -1344,  1184, -1344,   300,  1047,  7662,  2081,
   -1344,  5227,  5227,  3709,  3709,   994,   364,  6076, -1344, -1344,
   -1344, -1344, -1344, -1344,  5227,  1190,  1001,  3709,  3709,  1194,
    3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,
    3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,
    3709,  3709,  2081,  2081,  2081,  2081,  2081,  2081,  5227,  2081,
    2081,  3709,  2081,  2081,  2081,  2081,  2081,  3709,  6076,  3709,
    2081,  2081,  2081,  2081,    14,  6076,    14,  1009,  1009,  1009,
    4549,  8884,   146,  1005,  1192,  -163,  1003, -1344,  1007,  6804,
    3709, -1344, -1344,  6442,   108, -1344,  3709,  3709,  3709,  3709,
    3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,
    3709, -1344, -1344,  3709,  3709, -1344, -1344,  1289,   104,    88,
   -1344, -1344,   306,  5608, -1344,   336,   262,   430,  1010,  1011,
    6220,  6442,  4339, -1344,   263,  9229,  9250,  3709,  9271,   419,
    9292,  9313,  3709,   494,  9334,  9355,  1198,  3709,  3709,   534,
    1201,  1207,  1210,  3709,  3709,  1211,  1231,  1231,  3709,  6255,
    6255,  6255,  6255,  3709,  3709,  3709,  6442,  6442,  7689,  1044,
    1235,  1043, -1344, -1344,  -147, -1344, -1344,  5801,  5994,  -104,
    -104,   317,   317,   -55,  3709,  3709,  3709,  6192,  6192,  3709,
    6804,   -49, -1344,  3709,  3709,  3709,  3709,  3709,  1238,  1240,
    1242,  3709,  1241,  3709,  3709,  1085, -1344, -1344,  6442,  6442,
    6442,  1244,  1245,  3709,  3709,  3709,  3709,  3709,  1248,   396,
      14, -1344,  1200,  3709, -1344,  1202, -1344,  1203, -1344,  1218,
      41,    42,    43,    50,  6442,  1009, -1344,  9376, -1344,   572,
    3709,  5613, -1344,  3709,  3709,   452, -1344,  9397,  9418,  9439,
    1115,  7743, -1344,  1059,  4613,  9460,  8907, -1344, -1344, -1344,
    1419, -1344,  1522,  3709, -1344, -1344,  1066,  1069,   576,  9481,
    8930,  3709,  6442,   108,  1259,  1266, -1344,  3709,  9502,  8953,
     165,  8861,  8861,  8861,  8861,  8861,  8861,  8861,  8861,  8861,
    8861,  8861,  7769,  8861,  8861,  8861,  8861,  8861,  8861,  8861,
    7795,  7821,  7847,   518,   564,   518,  1082,  1083,  1079,  1081,
    1084,  1086,  7873,   600,   600,   600,   445,   600,  9964, -1344,
    1381,  1088,  1087,   470,   600,  1090,  1095,  1094,   160,   124,
    6076,  3709,  1286,  1298,    37,   600, -1344,   -68,    36,    38,
     167, -1344,  6157,   580, -1344,  5227,  5361,  1212,   663,  1269,
    1269,   570,   570,   570,   570,   597,   597,  1009,  1009,  1009,
    1009,    17,  9523,  8976, -1344,  3709,  1299,    19,  6442,  1287,
    6442,  3709,  1303,  2081,  1304, -1344,    14,  1306,  2081,  3709,
    6076,  1309,  6442,  6442,  1175,  1315,  1317,  9544,  1318,  1185,
    1319,  1321,  9565,  1188,  1324,  1326,  3709,  9586,  6766,  1122,
   -1344, -1344, -1344,  9607,  9628,  3709,  5227,  1331,  1333,  9649,
    1146,  9964,  1142,  1148,  9964,  1145,  1151,  9964,  1156,  1162,
    9964,  1158,  9670,  9691,  9712,   625,   659,  6442,  1161, -1344,
   -1344,  2468,  2596,  -104,  3709,  3709, -1344, -1344,  1159,  1160,
    6192,  7899,  7925,  7951,  5415,  1246,  -104,  2695,  9733,  6794,
    9754,  9775,  9796,  3709,  1354, -1344,  3709,  9817, -1344,  8999,
    9022, -1344,   679,   687,   688, -1344, -1344,  9045,  9068,  7977,
    9091,    10,  6442, -1344,  1170,  1167,  6822,  1173,  1174,  1178,
   -1344,  6442, -1344,  6442, -1344,  6442, -1344,  6442,   691, -1344,
   -1344,  5380,  6442,  1009, -1344,  6442, -1344,  1369,  1373,  1376,
    1186,  3709,  3077,  3709,  3709, -1344,    57, -1344, -1344,  3222,
   -1344,  1206,  5227,  1379,   160,   160,  6850,   698,  5227, -1344,
   -1344,  9114,    10,  1045, -1344, -1344, -1344, -1344, -1344, -1344,
   -1344, -1344, -1344, -1344, -1344, -1344,  3709, -1344, -1344, -1344,
   -1344, -1344, -1344, -1344,  3709,  3709,  3709, -1344,  6442, -1344,
   -1344, -1344, -1344,  2081,  5227,  2081,  2081,  6076, -1344, -1344,
   -1344, -1344, -1344, -1344, -1344, -1344,  3709, -1344, -1344,  2081,
   -1344, -1344, -1344, -1344,  3709,  1380,    26,  3709,  1396,  1397,
    1400, -1344,  1401,  1208,    35,  1403, -1344,  6442,  6442,  6442,
    6442, -1344,   600,  1404,  3709, -1344,  1221,  1222,  1216, -1344,
    1412, -1344, -1344, -1344, -1344, -1344,    10,    10,  9137, -1344,
   -1344,  1239,  2081,   508, -1344,   620,  8003, -1344, -1344, -1344,
    1414, -1344, -1344,  8861,   600,  -104,  4339, -1344,   786,  5227,
    5227,  1416,  5227,   818,  5227,  5227,  1421,  1336,  5227,  5227,
    1520,  1422,  1423,  6442,  1429,  1431,  2307, -1344, -1344,  1437,
   -1344,  1438,   108,  3709,   108,  3709,   108,  3709,   108,  3709,
    1452,  1453,  1454,  1471,  1472,   730,  1440,  4882, -1344, -1344,
     -30,  8029,  8055, -1344, -1344,  6878,   -82,  -104,  -104,  -104,
    1476,  1475,  1283,  1479,  1292,    63,    64,    65,    69,   -13,
   -1344,    91, -1344,  1246,  1480,  1482,  1484,  1485,  1497,  9964,
   -1344,  1648,  1288,  1500,  1501,  1503,  1435,  3709,  1506,  1511,
    3709,   162,   733, -1344,  3709, -1344,  3709,  3709,  3709,   734,
     748,   757,   762, -1344,  3709,   767,   776,  5227,  5227,  5227,
    1516,  8081, -1344,  5561,   335,  1517,  1518, -1344,  5227,  1323,
   -1344,  3709,  1523,  3709,  1524, -1344,   600,  1525,  1526, -1344,
    1519, -1344,  1527,  8861,  8861,  8861,  8861,   599,  1328,  1341,
    1343,  1347,  1344,   606,   610,  9838,  1350,  1686, -1344,   173,
    1348,  1540,  1759, -1344, -1344, -1344,    35,  3709, -1344,   783,
   -1344,   787,   788,   791,   792,   108, -1344,  9964,  1357,  3709,
    3709,  5227,  1370, -1344, -1344, -1344,  1372, -1344,  1566,    23,
    1567,  3709,  2159,  1583,  1588,     9,  1394,  1406,  1521,  1521,
    5227,  1604,  1410,  1418,  1609,  1614,  5227,  1424,  1618,  1620,
   -1344,  1622,  5227,   814,  5227,  5227,  1619,  1623, -1344,  5227,
    5227,  9964,  5227,  9964,  5227,  9964,  5227,  9964,  5227,  5227,
    5227,  1427,  1432,  1625,   420, -1344,  3709,  3709,  3709,  1433,
    1434,  -107,   -93,    87,  1441, -1344,  5227, -1344,  3709, -1344,
    1630, -1344,  1632, -1344,  1633, -1344,  1634, -1344, -1344,  6192,
     533,  5034, -1344,  1442,  1443,  5806, -1344,  6442, -1344, -1344,
   -1344,  1445,  1804, -1344, -1344,  9160,  1637,   600,  8107,  8133,
    8159,  8185, -1344, -1344, -1344, -1344,  9964, -1344,   600,  1636,
    1641,  1510, -1344,  3709,  3709,  3709, -1344,  1644,   560,  1451,
    1646,  2440, -1344,  2757, -1344,   108, -1344, -1344,   194, -1344,
   -1344, -1344, -1344, -1344, -1344,  2081, -1344, -1344, -1344,  6076,
    1649, -1344, -1344,    20, -1344, -1344, -1344, -1344, -1344,  6076,
    3709,  1653,  1651,    37, -1344,  1655,  9183,    35, -1344,  1656,
    1657,  1658,  1659,  5227,  3709,  8211,  8237,   817, -1344,  3709,
    1662, -1344, -1344,  2081, -1344,  8263,  4198,  9964, -1344, -1344,
   -1344, -1344,  3709,  3709,  -104,  1664,  1667,  1668, -1344,  3709,
    3709, -1344, -1344,  1669,  3709, -1344, -1344,  1663,  1670,  1477,
    1671,  1541,  3709, -1344,  1678,  1683,  1684,  1685,  1687,  1703,
    1016,  1704,  6442,  6442,  3709, -1344,  6255,  6906,  9859,  6187,
     317,   317,  -104,  1705,  -104,  1706,  -104,  1708,  3709,   496,
    1529,  9880, -1344, -1344, -1344, -1344,  6934,   125, -1344,  1715,
    3786,  1716,  5227,  -104,  3786,  1717,   828,  3709, -1344,  1719,
      10, -1344,  3709,  3709,  3709,  3709, -1344, -1344, -1344,  5227,
    6383,   738,  9901, -1344, -1344,  4584,  5227, -1344, -1344, -1344,
    5227, -1344,  1535,   600,  4391,  4648,  6076,  1725,  2800, -1344,
    1732,  1726, -1344,  1546, -1344, -1344, -1344, -1344, -1344,  1739,
     633,  9964,  3709,  3709,  5227,  1547,   829,  9964, -1344,  1741,
    3709, -1344, -1344,  6962,  6990,   543, -1344, -1344, -1344,  7018,
    7046, -1344,  7074,  1744, -1344,  5227, -1344,  1676,  1754,  9964,
   -1344, -1344, -1344, -1344, -1344, -1344,  1549, -1344, -1344,   852,
     857,  7716,  2836,  1760,  1568, -1344,  3709, -1344,  1565,  1569,
     155, -1344,  1571,   178, -1344,  1573,   232, -1344,  1574,  9206,
    1770,  5227,  1771,  1576,  3709, -1344,  5999,   276, -1344,   860,
     349,   355, -1344,  1773,  7102, -1344,  8289,  8315,  8341,  8367,
    1647,  3709, -1344,  3709, -1344, -1344,  6442,  3947,  1775,  1581,
    1779, -1344, -1344,  3998, -1344, -1344,  2081,  9964, -1344, -1344,
   -1344, -1344,    35, -1344,  1654, -1344, -1344,  3709,  8393,  8419,
   -1344,  5227,  3709,  1781, -1344,  8445, -1344, -1344,  1782,  1783,
    1787,  1791,  1792,  1796,   861,  1602, -1344,  5227,   -14,   667,
    6442, -1344, -1344,   317,  6730, -1344, -1344,  6192,  1246,  6192,
    1246,  6192,  1246,  1803, -1344,   864,  5227, -1344,  7130,  -104,
    1805,  6442,  -104, -1344, -1344,  3709,  3709,  3709,  3709,  3709,
    7158,  7186,   867, -1344, -1344,  1806, -1344,   868,  4158,   877,
    1807, -1344,  1616,  9964,  3709,  3709,   878,  9964, -1344,  3709,
     890,   905, -1344, -1344, -1344, -1344, -1344, -1344,  1639,  3709,
     909,  1642,  -104,  5227,  1809,  1674,  -104,  1812,   910,  1640,
    3709, -1344,  7214,   363,   624,  7242,   368,   759,  7270,   399,
     856, -1344,  5227,  1814,  1723,  5075,  1675,   441, -1344,   914,
     444,  8471,  8497,  8523,  8549,  3993, -1344, -1344,  1839, -1344,
    3709, -1344,  6076, -1344, -1344,  3709,  9922,  8575,    52,  8601,
   -1344, -1344,  3709,  7298,  1841,  -104,    13, -1344, -1344,  -104,
      73, -1344,  1842, -1344,  7326,  1846,  3709,  1848,  1849,  3709,
    1852,  1853,  3709,  1874,  1679, -1344,  3709, -1344,  1246, -1344,
    6442,  1876,  5999,  3709,  3709,  3709,  3709, -1344, -1344,   259,
   -1344,   918, -1344,  3709, -1344,  5227,  3709,  8627, -1344, -1344,
     507, -1344,   517, -1344, -1344, -1344, -1344,  1688,  7354, -1344,
   -1344,  1692,  7382, -1344, -1344,  1718,  7410, -1344,  1877,  4138,
     917,  5268,   934, -1344,   520,   938,  8653,  8679,  8705,  8731,
    6076,  1879,  1720,  9943,   943,  7438,  3709,  -104,  -104,  1246,
    1880,  1246,  1881,  1246,  1910, -1344, -1344, -1344, -1344,  1246,
    1911,  6442,  1912,  3709,  3709,  3709,  3709, -1344, -1344,  2081,
   -1344,  1721,  1917,  7466,   526,   545,  1006, -1344,  1727,  1150,
   -1344,  1728,  1316, -1344,  1729,  1562, -1344,   948, -1344,  8757,
    8783,  8809,  8835,   952, -1344,  1731,  5227, -1344,  1918,  3709,
    3709,  1920,  1246,  1921,  1246,  1943,  1246, -1344,  1944,  3709,
    3709,  3709,  3709,  2081,  1945,  2081,   970, -1344,  7494,  7522,
   -1344,  1617, -1344,  1682, -1344,  2140, -1344,  7550,  7578,  7606,
    7634, -1344, -1344,   991, -1344,  1947,  1949,  1950,  1952,  1953,
    1969, -1344, -1344, -1344, -1344,  2081,  1970, -1344, -1344, -1344,
   -1344, -1344, -1344, -1344, -1344
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1344, -1344, -1344, -1344,   874, -1344, -1344, -1344, -1344,   313,
   -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344,
   -1344, -1344,  -380,  -103,  2255,    -1, -1344,  1551, -1344, -1344,
   -1344, -1344, -1344,   478, -1344,   482, -1344, -1344, -1344, -1344,
   -1344, -1344,   871,  1993,     7,  -494,  -258, -1344, -1344, -1344,
   -1344, -1344, -1344, -1344,  1999, -1344, -1344, -1344, -1344, -1344,
   -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344,  -952,  -943,
   -1344, -1344,  1528, -1344,   474, -1344, -1344, -1344, -1344,  1544,
   -1344, -1344,     0, -1344, -1343,  2235,  -108,  2444,  1942,  -244,
     741, -1344,    21,    62, -1344,  -368,    -3,    95
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -489
static const yytype_int16 yytable[] =
{
     107,   491,   510,   541,   623,   345,   625,   758,   759,  1469,
      94,   322,   270,   190,   525,  1291,   522,   636,   317,  1691,
     544,   915,   651,   546,  1385,   930,   346,   184,   402,  1282,
    1089,   203,   548,   204,   665,   216,   211,   499,   500,   308,
     211,   903,   216,   266,   324,   267,   800,   802,   804,   253,
     255,   192,   261,   753,   273,   806,   241,   330,  1684,   242,
     311,  1190,   302,   262,  1055,   580,  1188,   582,   185,  1179,
    1181,  1183,   275,   245,   276,  1185,   273,   499,   500,  1693,
     249,   250,  1524,   499,   500,  1000,   246,   247,  1591,  1592,
     251,   499,   500,  1332,  1593,  1333,  1001,   252,   108,     4,
     501,   187,   499,   500,  1002,  1003,  1004,  1334,   191,  1335,
    1005,  1006,  1007,  1008,   207,   664,     5,   470,   471,   472,
    1170,   208,   475,   476,   477,   513,   207,   499,   500,   499,
     500,   664,   514,   907,   263,   499,   500,   194,   264,   337,
     542,   318,   321,   277,   502,   760,   916,   917,   918,   919,
     265,   766,   274,   650,   499,   500,   271,   545,   518,   519,
     547,   499,   500,   403,   404,  1090,  1091,   664,  1576,   549,
    1166,  1386,   531,   532,   319,   273,   225,    88,   512,   226,
    1259,   188,   227,    88,  1590,   195,   407,   273,   273,  1187,
    1180,  1182,  1184,   499,   500,   273,  1186,   499,   500,   543,
     931,   342,   343,   273,   931,   302,   196,   323,   523,   272,
     302,   439,   442,   838,   302,   180,   347,   302,   348,   920,
     349,   302,   302,   302,   302,   180,   212,   302,   302,   302,
     212,   189,   217,   213,   751,   752,   309,   908,   904,   909,
     325,   302,   801,   803,   805,   331,   193,  1188,   494,   495,
     312,   807,   332,  1685,   767,  1056,   503,   499,   500,   280,
     511,   198,   281,   302,   302,   302,  1720,   448,   894,   897,
     197,   499,   500,   405,   199,   499,   500,   302,   302,   338,
     339,   340,   341,   687,   200,   441,   441,  1336,   688,  1337,
     302,  1189,   302,   441,   201,   338,   339,   340,   341,   652,
     685,   449,   686,   338,   339,   340,   341,   180,   230,   499,
     500,   231,   209,   232,   822,   342,   343,   338,   339,   340,
     341,   406,   896,   342,   343,  1464,   273,   829,   302,   302,
     202,   338,   339,   340,   341,   593,   210,   342,   343,   499,
     500,   302,  1724,  1225,   338,   339,   340,   341,   342,   343,
     586,   342,   343,   342,   343,  1537,   342,   343,  -486,   220,
    1206,   219,   499,   500,   342,   343,  -487,   221,   910,   273,
     273,   273,   273,   273,   273,   302,   273,   273,  1539,   273,
     273,   273,   273,   273,   214,   342,   343,   273,   273,   273,
     273,   273,   215,   273,   624,  -488,   626,   627,   628,   594,
     630,   631,   560,   633,   634,   635,   333,   637,   334,   218,
     302,   641,   642,   643,   644,   335,   499,   500,   219,    48,
      49,    50,    51,   411,   441,   412,  1325,  1326,    56,   413,
     223,    59,  1541,  1796,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   302,   536,
     639,   537,   430,   538,  1061,  1063,   179,   646,   180,   694,
     499,   500,   695,   703,   433,   704,   434,   441,   441,   441,
     441,   441,   441,   335,   441,   441,  1549,   441,   441,   441,
     441,   441,   222,   302,   302,   441,   441,   441,   441,   645,
     224,   647,   987,   563,   347,   564,   583,   844,   538,   756,
     757,   689,   335,   180,   560,   233,   690,   495,   407,   407,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   228,   302,   302,   302,   430,   257,
    1226,   692,   258,   499,   500,   259,   693,   273,   793,   499,
     500,   732,   735,   738,   741,   895,   898,   499,   500,  1551,
     229,   302,   499,   500,   234,  1552,   243,   235,   302,   411,
     236,   412,   237,  1656,   816,   592,  1374,  1375,  1659,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     561,   428,   429,   499,   500,   248,  1604,   430,  1607,   302,
    1610,   411,  1150,   412,  1152,   268,  1154,   792,  1156,  1662,
     845,   846,   847,   848,   849,   850,   851,   852,   853,   854,
     855,   256,   857,   858,   859,   860,   861,   862,   863,   703,
     244,   709,   867,   869,   870,   499,   500,   697,   499,   500,
     695,  1000,   878,   879,   880,   794,   882,   269,   249,   250,
     881,  1670,  1001,   890,  1672,   693,   278,   411,   251,   412,
    1002,  1003,  1004,   815,   906,   260,  1005,  1006,  1007,  1008,
    1098,  1188,   302,   238,  1188,   888,   239,  1188,   240,   279,
     889,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   561,   428,   429,   302,   282,   302,   844,   430,
     273,   499,   500,   273,   703,   273,   713,   283,  1460,   302,
     302,   499,   500,  1119,   499,   500,   284,  1727,   703,  1260,
     499,   500,   899,   411,   938,   412,  1710,  1728,   693,   942,
    1741,   304,  1000,   302,   305,  1273,  1779,   499,   500,   499,
     500,  1062,  1064,  1001,   703,  1348,   719,   314,   306,  1069,
    1071,  1002,  1003,  1004,   302,  1780,  1483,  1005,  1006,  1007,
    1008,   307,   313,   990,   425,   426,   427,   428,   429,   411,
     996,   412,   944,   430,   868,   550,  1011,  1188,   551,  1595,
    1596,   552,   703,   553,   810,  1593,   832,  1756,   833,  1759,
     703,  1762,   912,   427,   428,   429,   315,  1765,   441,   302,
     430,   940,   316,   441,   411,   411,   412,   412,   302,   703,
     302,   411,   302,   412,   302,   411,  1250,   412,   329,   302,
    1253,   375,   302,  1188,   389,  1120,  1188,   376,   396,  1188,
     703,   377,  1188,  1114,  1115,   703,  1657,   983,  1506,   302,
    1801,   415,  1803,  1507,  1805,   302,  1448,  1449,   378,   379,
     273,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,  1265,   410,   380,  1380,   430,  1000,  1188,   703,
    1188,   984,  1188,   385,  1072,   302,   390,  1126,  1001,  1127,
     273,   302,   273,   273,   391,   392,  1002,  1003,  1004,   703,
     394,  1025,  1005,  1006,  1007,  1008,   273,   703,   703,  1026,
    1027,   703,   432,  1043,  1078,   395,  1080,  1081,   703,  1132,
    1066,  1133,   436,   457,   302,   302,   302,   302,   431,   462,
    1086,  1105,   467,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   468,  1071,   273,
     703,   430,  1163,   703,   703,  1207,  1212,   473,   441,  1082,
    1484,   474,  1123,  1124,   478,  1125,   302,   302,   703,   302,
    1213,   302,   302,  1118,  1000,   302,   302,   703,   479,  1214,
     302,  1660,   703,   480,  1215,  1001,   481,   703,   441,  1217,
     441,   441,   482,  1002,  1003,  1004,   703,   489,  1218,  1005,
    1006,  1007,  1008,  1267,   441,  1268,  1261,   703,   703,  1269,
    1270,   703,   703,  1271,  1272,   483,   484,  1171,  1172,  1173,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   703,  1000,  1309,  1404,   430,  1405,
    1436,   485,  1437,  1394,   486,   492,  1001,   441,   703,  1512,
    1473,  1513,   493,   504,  1002,  1003,  1004,   505,   506,  1599,
    1005,  1006,  1007,  1008,   302,   302,   302,   515,   516,   438,
     111,   524,   703,   584,  1528,   302,   517,   703,  1663,  1529,
    1404,  1404,  1550,  1588,  1612,  1235,  1613,   703,  1630,  1628,
    1631,   526,  1240,  1241,  1242,  1243,  1244,   693,  1404,  1633,
    1638,   521,  1251,  1254,   137,   138,   139,   140,   141,   142,
    1250,   335,  1640,   146,   147,   148,   149,     7,     8,   527,
     528,   151,   152,   153,  1000,  1253,   154,  1641,   302,  1404,
     703,  1644,  1652,   529,   703,  1001,  1671,   159,  1512,  1737,
    1721,   530,   533,  1002,  1003,  1004,   534,   302,  1569,  1005,
    1006,  1007,  1008,   302,   703,  1381,  1740,   535,   703,   302,
    1742,   302,   302,  1404,   562,  1751,   302,   302,   703,   302,
    1788,   302,  1793,   302,  1794,   302,   302,   302,   540,   566,
     657,    24,    25,   658,    27,    28,   659,    30,   660,    32,
    1404,    33,  1815,   302,   570,   572,    38,    39,   573,    41,
      42,    43,   180,   577,  1288,    46,   578,   579,   302,  1347,
     581,  1825,   302,  1826,   302,   591,   596,   597,   600,   654,
     162,   163,   430,   653,   179,   716,  1361,   720,  1781,   656,
     699,   700,   170,   721,    88,   171,   722,  1366,   725,    67,
      68,    69,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   342,   343,   726,   748,
     430,   749,   273,  1070,   750,   773,   775,   778,  1000,   776,
     785,   786,   791,   795,   820,   797,   798,  1381,  1570,  1001,
     823,   317,   111,   830,   831,   839,  1382,  1002,  1003,  1004,
     302,   799,   840,  1005,  1006,  1007,  1008,   871,   872,   873,
     273,   874,   887,   302,   875,   891,   876,   781,   886,  1615,
     892,   893,   901,   934,  1415,   684,   137,   138,   139,   140,
     141,   142,   902,   929,  1409,   146,   147,   148,   149,   937,
     939,  1383,   941,   151,   152,   153,   945,   948,   154,   302,
     302,  1387,   949,   963,   950,   952,   954,   953,   955,   159,
     957,   958,  1450,   959,  1453,   968,  1456,   407,   407,   970,
     441,   972,   973,   974,  1000,   975,   976,   302,  1412,   302,
    1467,   302,  1783,  1470,  1471,  1001,   977,   978,   979,   986,
    1020,   993,   994,  1002,  1003,  1004,   302,  1033,  1034,  1005,
    1006,  1007,  1008,   302,  1036,  1037,  1047,   302,   441,  1038,
    1048,   302,  1492,  1049,  1050,  1060,  1088,   885,  1443,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   302,  1093,  1094,  1097,   430,  1095,  1058,  1096,  1100,
    1106,  1711,   162,   163,  1000,  1109,  1110,  1111,  1113,  1137,
    1117,  1122,   302,  1130,   170,  1001,    88,   171,  1136,  1141,
    1142,     7,     8,  1002,  1003,  1004,  1144,  1488,  1145,  1005,
    1006,  1007,  1008,  1148,  1164,  1149,  1495,  1498,  1499,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   302,  1158,
    1159,  1160,   430,   302,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,  1161,  1162,
    1174,  1175,   430,   302,  1176,  1177,  1178,  1191,  1192,  1197,
     302,  1193,  1194,   273,   657,    24,    25,   658,    27,    28,
     659,    30,   660,    32,  1195,    33,  1198,  1199,   302,  1200,
      38,    39,  1203,    41,    42,    43,  1201,  1204,  1785,    46,
    1222,  1227,  1228,  1238,   302,  1230,  1140,   302,  1245,  1232,
    1234,  1236,  1237,  1239,     7,     8,  1246,  1603,  1247,  1606,
     407,  1609,  1248,   302,  1249,  1257,  1262,  1263,   302,  1617,
     182,  1274,  1620,    67,    68,    69,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
    1280,  1279,  1281,  1284,   430,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,  1289,
     302,   441,  1646,   430,  1290,  1292,  1650,   657,    24,    25,
     658,    27,    28,   659,    30,   660,    32,  1293,    33,   302,
    1298,  1299,  1294,    38,    39,  1301,    41,    42,    43,  1300,
    1302,   827,    46,  1312,  1305,  1304,  1306,  1307,  1322,  1313,
     327,   328,  1324,  1323,  1330,  1331,  1342,  1338,  1343,  1344,
    1345,  1360,  1367,  1352,  1353,  1690,  1357,  1368,  1369,  1692,
    1373,  1376,  1377,  1384,  1196,  1390,    67,    68,    69,  1389,
    1000,  1392,  1395,  1396,  1397,  1398,  1408,   302,  1423,   302,
    1416,  1001,  1714,  1417,  1418,  1421,  1424,  1426,  1425,  1002,
    1003,  1004,   302,  1427,  1430,  1005,  1006,  1007,  1008,  1431,
    1432,  1433,  1258,  1434,  1680,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,  1435,
    1438,  1451,  1454,   430,  1457,  1000,   397,   398,   399,   400,
     401,  1465,  1468,  1472,   828,  1475,  1001,  1754,  1755,  1461,
    1491,  1500,  1503,   437,  1002,  1003,  1004,   443,   302,  1502,
    1005,  1006,  1007,  1008,  1504,  1505,   273,  1514,  1511,  1523,
    1527,   450,   452,   455,   456,  1525,   458,   452,   460,   461,
    1526,   452,   464,   465,  1787,  1264,  1532,  1535,   452,  1533,
    1774,  1536,  1538,   302,  1540,  1542,  1544,  1547,  1546,  1553,
    1000,  1564,  1747,  1565,  1559,  1566,   488,  1578,  1582,  1583,
     273,  1001,   273,  1584,  1571,   497,   498,  1585,  1586,  1002,
    1003,  1004,  1587,  1589,   498,  1005,  1006,  1007,  1008,  1611,
    1358,  1618,  1629,  1634,  1811,  1648,  1814,  1635,  1651,  1818,
    1665,  1666,   273,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   555,   557,   452,
    1642,   430,  1653,  1645,   441,  1678,  1833,  1689,  1694,   567,
     568,   569,  1696,   571,  1699,  1700,   574,   575,  1703,  1704,
     576,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,  1649,  1669,   589,   590,   430,
    1707,  1708,  1713,  1735,  1819,  1748,  1757,  1760,   441,  1729,
     441,   598,   599,  1731,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,  1763,  1766,  1768,  1733,
     441,  1749,  1776,  1777,  1797,   632,  1800,  1802,  1782,  1784,
    1786,   638,  1795,   640,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,  1681,  1804,
    1806,  1812,   430,  1827,   662,  1828,  1829,   452,  1830,  1831,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,  1832,  1834,   682,   683,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,  1283,  1580,   555,    93,   430,   698,  1581,
    1296,   707,   102,  1597,  1391,   728,   712,     0,     0,     0,
       0,   717,   718,     0,     0,     0,     0,   723,   724,     0,
       0,     0,   729,   731,   734,   737,   740,   742,   743,   744,
     452,   452,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   761,   762,
     763,   397,   398,   764,     0,     0,     0,   768,   769,   770,
     771,   772,     0,     0,     0,   777,     0,   779,   780,     0,
       0,     0,   452,   452,   452,     0,     0,   787,   788,   789,
     598,   790,     0,     0,     0,   438,   111,   796,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   452,     0,
       0,     0,     0,     0,   811,   813,     0,   682,   683,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,   140,   141,   142,     0,   790,     0,   146,
     147,   148,   149,     0,     0,   836,   452,   151,   152,   153,
       0,   841,   154,     0,     0,     0,     0,     0,     0,     0,
     454,     0,     0,   159,     0,   459,     0,     0,     0,   463,
       0,     0,   109,   326,   111,     0,   469,     0,   112,   113,
     114,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   900,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     0,     0,     0,   151,   152,   153,     0,     0,
     154,     0,   155,   156,   157,     0,     0,     0,     0,   928,
     158,   159,   452,     0,   452,   936,   162,   163,  1000,     0,
       0,     0,     0,   943,     0,     0,   813,   946,   170,  1001,
      88,   171,     0,     0,     0,     0,     0,  1002,  1003,  1004,
     960,     0,     0,  1005,  1006,  1007,  1008,     0,     0,   966,
       0,     0,     0,     0,     0,     0,   205,   206,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   452,     0,     0,     0,     0,     0,     0,   991,   992,
       0,     0,     0,     0,   995,     0,     0,     0,     0,     0,
       0,     0,     0,   161,   162,   163,   164,  1019,     0,     0,
    1021,   165,   166,   167,   168,   169,   170,     0,    88,   171,
       0,     0,     0,     0,     0,     0,   452,     0,     0,     0,
       0,     0,  1820,   172,   173,   452,     0,   452,   174,   452,
       0,   452,     0,   294,     0,   663,   452,     0,   178,   452,
    1286,     0,   336,     0,     0,  1051,     0,  1053,  1054,     0,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,     0,
    1073,   381,   382,   383,   384,  1146,     0,   386,  1074,  1075,
    1076,     0,   452,   387,   388,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,   745,   746,
    1085,     0,     0,     0,     0,     0,     0,     0,  1087,     0,
       0,  1092,     0,     0,     0,     0,  1378,     0,     0,     0,
       0,   452,   452,   452,   452,   466,     0,     0,  1107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     782,   783,   784,     0,     0,     0,     0,     0,     0,   490,
       7,     8,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   808,     0,     0,     0,
     430,     0,     0,   520,     0,     0,     0,   452,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1151,     0,  1153,
       0,  1155,     0,  1157,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   837,     0,     0,     0,     0,     0,
     539,     0,     0,   657,    24,    25,   658,    27,    28,   659,
      30,   660,    32,     0,    33,     0,     0,   565,     0,    38,
      39,     0,    41,    42,    43,     0,   587,   588,    46,     0,
       0,  1202,     0,     0,  1205,     0,     0,     0,  1208,   595,
    1209,  1210,  1211,     0,     0,     0,     0,     0,  1216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,  1231,     0,  1233,     7,     8,
       0,     0,     0,   629,     0,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
     933,     0,   935,   430,     0,     0,     0,     0,     0,     0,
       0,  1266,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   453,  1275,  1276,     0,     0,   453,     0,     0,
     655,   453,     0,     0,     0,  1285,  1287,     0,   453,     0,
     988,   657,    24,    25,   658,    27,    28,   659,    30,   660,
      32,     0,    33,     0,     0,     0,     0,    38,    39,   985,
      41,    42,    43,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
    1327,  1328,  1329,     0,     0,     0,     0,     0,     0,     0,
    1339,     0,  1341,     0,     0,     0,     0,     0,     0,     0,
      67,    68,    69,  1346,  1032,     0,     0,   556,     0,   453,
       0,   452,     0,  1039,     0,  1040,     0,  1041,     0,  1042,
       0,     0,     0,     0,  1045,     0,     0,  1046,     0,     0,
       0,     0,     0,  1379,     0,     0,     0,  1370,  1371,  1372,
     657,    24,    25,   658,    27,    28,   659,    30,   660,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,     0,     0,   989,     0,
       0,     0,     0,     0,  1388,     0,  1501,     0,     0,     0,
    1077,     0,     0,     0,     0,     0,     0,     0,  1401,     0,
       0,     0,     0,  1407,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,     0,  1413,  1414,     0,     0,
       0,     0,  1531,  1419,  1420,     0,     0,     0,  1422,  1101,
    1102,  1103,  1104,     0,     0,     0,  1429,   453,     0,     0,
       0,     0,     0,     0,     0,     0,   452,   452,  1441,     0,
    1442,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1459,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   452,   556,     0,  1012,   452,     0,
     913,  1474,     0,     0,     0,  1143,  1476,  1477,  1478,  1479,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1487,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1497,
     453,   453,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,  1508,  1509,     0,     0,
     430,     0,     0,     0,  1515,     0,     0,     0,     0,     0,
       0,   967,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   453,   453,   453,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
    1534,     0,     0,   430,     0,     0,     0,     0,   453,     0,
       0,     0,     0,     0,     0,   814,     0,     0,  1548,     0,
     555,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,  1560,     0,  1561,     0,   430,
     452,     0,     0,     0,     0,     0,   453,  1568,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1573,     0,     0,     0,     0,  1577,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1059,     0,     0,
       0,     0,     0,  1067,   452,     0,     0,     0,     0,     0,
       0,  1602,     0,  1605,     0,  1608,     0,     0,     0,     7,
       8,     0,     0,     0,     0,   452,     0,     0,     0,  1621,
    1622,  1623,  1624,  1625,     0,     0,     0,     0,     0,  1079,
       0,     0,     0,     0,     0,     0,     0,     0,  1636,  1637,
       0,     0,     0,  1639,     0,     0,     0,     0,     0,     0,
       0,     0,   453,  1643,   453,     0,     0,     0,     0,  1356,
       0,     0,     0,     0,  1654,     0,   814,   947,     0,     0,
       0,     0,   657,    24,    25,   658,    27,    28,   659,    30,
     660,    32,     0,    33,     0,     0,     0,     0,    38,    39,
       0,    41,    42,    43,  1679,     0,     0,    46,     0,  1407,
       0,     0,     0,     0,  1128,  1129,  1687,  1131,     0,  1134,
    1135,   453,     0,  1138,  1139,     0,     0,     0,     0,     0,
    1698,     0,     0,  1702,     0,     0,  1706,     0,     0,     0,
    1709,    67,    68,    69,   452,     0,   452,  1716,  1717,  1718,
    1719,     0,     0,     0,     0,     0,     0,  1723,     0,     0,
    1725,     0,     0,     0,     7,     8,   453,     0,     0,     0,
       0,     0,     0,     0,     0,   453,     0,   453,     0,   453,
       0,   453,     0,     0,     0,     0,   453,     0,     0,   453,
       0,     0,     0,     0,  1439,  1440,     0,     0,     0,     0,
    1753,     0,     0,     0,     0,     0,     0,     0,     0,  1052,
       0,     0,  1219,  1220,  1221,   452,     0,  1769,  1770,  1771,
    1772,     0,     0,  1229,     0,     0,     0,   657,    24,    25,
     658,    27,    28,   659,    30,   660,    32,     0,    33,     0,
       0,     0,   453,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,  1798,  1799,     0,     0,     0,     0,     0,
       0,     0,     0,  1807,  1808,  1809,  1810,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1278,     0,     0,     0,
       0,   453,   453,   453,   453,     0,    67,    68,    69,     0,
       0,     0,     0,     0,     0,  1297,     0,     0,     0,     0,
       0,  1303,     0,     0,     0,     0,     0,  1308,     0,  1310,
    1311,     0,     0,     0,  1314,  1315,     0,  1316,     0,  1317,
       0,  1318,     0,  1319,  1320,  1321,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   453,     0,     0,
       0,  1340,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1057,     0,  1351,     0,  1562,     0,
    1355,     0,     0,     0,     0,   109,   326,     0,     0,     0,
       0,   112,   113,   114,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,  1598,     0,     0,     0,     0,   143,   144,   145,
       0,     0,     0,     0,   150,     0,     0,     0,     0,     0,
       0,     0,     0,  1619,     0,   155,   156,   157,     0,     0,
       0,     0,     0,   158,     0,     0,     0,     0,  1399,     0,
       0,   109,   110,   111,     0,     0,     0,   112,   113,   114,
       0,  1411,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,     0,   151,   152,   153,     0,     0,   154,
       0,   155,   156,   157,     0,     0,     0,     0,     0,   158,
     159,     0,     0,     0,     0,     0,   161,  1278,     0,   164,
       0,     0,     0,     0,   165,   166,   167,   168,   169,     0,
       0,    88,     0,     0,  1480,     0,     0,     0,     0,     0,
       0,  1489,  1712,     0,  1715,  1490,   172,   173,     0,  1494,
       0,   174,     0,     0,     0,     0,   294,     0,     0,     0,
       0,   178,     0,   487,     0,     0,     0,     0,     0,  1510,
       0,   453,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,     0,     0,     0,
    1278,     0,   161,   162,   163,   164,     0,     0,     0,     0,
     165,   166,   167,   168,   169,   170,     0,    88,   171,     0,
       0,     0,     0,  1767,     0,     0,     0,     0,     0,     0,
       0,     0,   172,   173,     0,     0,  1545,   174,     0,     0,
       0,     0,   175,     0,   176,     0,   177,   178,     0,   179,
       0,   180,   109,   326,     0,     0,     0,     0,   112,   113,
     114,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,     0,  1278,     0,     0,     0,
       0,     0,     0,     0,   143,   144,   145,     0,     0,     0,
       0,   150,  1278,     0,     0,     0,   453,   453,     0,     0,
       0,     0,   155,   156,   157,     0,     0,     0,     0,     0,
     158,  1614,     0,     0,     0,     0,     0,     0,     0,   109,
     285,     0,     0,     0,   453,   112,   113,   114,   453,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   287,     0,     0,     0,     0,     0,  1647,     0,
       0,   143,   144,   145,     0,     0,     0,     0,   150,     0,
       0,     0,     0,     0,     0,     0,     0,  1664,     0,   155,
     156,   157,     0,     0,     0,     0,     0,   158,     0,     0,
       0,   288,     0,   161,   289,     0,   164,   290,     0,   291,
       0,   165,   166,   167,   168,   169,     0,     0,    88,     0,
       0,   292,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,   172,   173,     0,     0,    56,   174,     0,
      59,     0,     0,   294,     0,     0,     0,     0,   178,     0,
     556,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1278,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     453,     0,     0,     0,     0,     0,     0,   453,     0,     0,
     161,     0,     0,   164,     0,     0,     0,     0,   165,   166,
     167,   168,   169,  1563,     0,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     507,  1466,     0,     0,   453,   174,     0,     0,     0,     0,
     509,     0,     0,     0,     0,   178,     0,   252,   558,     0,
       0,     0,     0,     0,     0,   453,     0,     0,     0,  1677,
       0,   109,   285,     0,     0,     0,     0,   112,   113,   114,
       0,  1278,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   287,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   144,   145,     0,     0,     0,     0,
     150,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   155,   156,   157,     0,     0,     0,     0,     0,   158,
       0,     0,     0,   288,     0,     0,   289,     0,     0,   290,
       0,   291,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   292,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,   453,     0,   453,     0,     0,     0,
       0,     0,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,  1736,     0,     0,     0,     0,     0,
       0,     0,   161,     0,     0,   164,     0,     0,     0,     0,
     165,   166,   167,   168,   169,  1632,   560,    88,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   172,   451,     0,   453,   430,   174,     0,     0,
       0,     0,   294,     0,     0,     0,     0,   178,     0,     0,
     558,   109,   285,   111,     0,     0,     0,   112,   113,   114,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   287,     0,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,     0,   151,   152,   153,     0,     0,   154,
       0,   155,   156,   157,     0,     0,     0,     0,     0,   158,
     159,     0,     0,   288,     0,     0,   289,     0,     0,   290,
       0,   291,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   292,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   702,   428,   429,   560,     0,     0,
       0,   430,   161,   162,   163,   164,     0,     0,     0,     0,
     165,   166,   167,   168,   169,   170,     0,    88,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   172,   293,     0,     0,     0,   174,     0,     0,
       0,     0,   294,     0,   109,   285,   111,   178,     0,   295,
     112,   113,   114,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   287,     0,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,     0,   151,   152,   153,
       0,     0,   154,     0,   155,   156,   157,     0,     0,     0,
       0,     0,   158,   159,     0,     0,   288,     0,     0,   289,
       0,     0,   290,     0,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   702,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,   162,   163,   164,     0,
       0,     0,     0,   165,   166,   167,   168,   169,   170,     0,
      88,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   172,   293,     0,     0,     0,
     174,     0,     0,     0,     0,   294,     0,   109,   326,   111,
     178,     0,  1493,   112,   113,   114,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
       0,   824,     0,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,     0,     0,     0,
     151,   152,   153,     0,     0,   154,     0,   155,   156,   157,
       0,   109,   326,   111,     0,   158,   159,   112,   113,   114,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,     0,   151,   152,   153,     0,     0,   154,
       0,   155,   156,   157,     0,     0,     0,     0,     0,   158,
     159,     0,     0,     0,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   161,   162,
     163,   164,   430,     0,   648,     0,   165,   166,   167,   168,
     169,   170,     0,    88,   171,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172,   173,
       0,     0,     0,   174,     0,     0,     0,     0,   294,     0,
       0,     0,     0,   178,     0,  1486,     0,     0,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   161,   162,   163,   164,   430,     0,     0,     0,
     165,   166,   167,   168,   169,   170,     0,    88,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   172,   173,     0,     0,     0,   174,     0,     0,
       0,     0,   294,     0,   109,   285,   286,   178,     0,  1496,
     112,   113,   114,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   287,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,   145,     0,
       0,     0,     0,   150,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,   155,   156,   157,     0,     0,     0,
       0,     0,   158,     0,     0,     0,   288,     0,     0,   289,
       0,     0,   290,     0,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,     0,   657,    24,    25,
     658,    27,    28,   659,    30,   660,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,     0,     0,   164,     0,
       0,     0,     0,   165,   166,   167,   168,   169,     0,     0,
      88,     0,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,     0,     0,     0,   172,   293,     0,     0,     0,
     174,     0,     0,     0,     0,   294,     0,   109,   285,  1349,
     178,     0,   295,   112,   113,   114,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     287,     0,     0,     0,     0,     0,     0,     0,     0,   143,
     144,   145,     0,     0,  1165,     0,   150,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,   155,   156,   157,
       0,     0,     0,     0,     0,   158,     0,     0,     0,   288,
       0,     0,   289,     0,     0,   290,     0,   291,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   292,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,     0,
     657,    24,    25,   658,    27,    28,   659,    30,   660,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   161,     0,
       0,   164,     0,     0,     0,     0,   165,   166,   167,   168,
     169,     0,     0,    88,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,     0,     0,     0,   172,   293,
       0,     0,     0,   174,     0,     0,     0,     0,   294,     0,
     109,   285,     0,   178,     0,  1350,   112,   113,   114,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   287,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   145,     0,     0,  1667,     0,   150,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
     155,   156,   157,     0,     0,     0,     0,     0,   158,     0,
       0,     0,   288,     0,     0,   289,     0,     0,   290,     0,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,     0,   657,    24,    25,   658,    27,    28,   659,
      30,   660,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,   914,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,   164,     0,     0,     0,  1044,   165,
     166,   167,   168,   169,     0,     0,    88,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,   172,   293,     0,     0,     0,   174,     0,     0,     0,
       0,   294,     0,   109,   285,     0,   178,     0,   295,   112,
     113,   114,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   287,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   144,   145,     0,     0,
    1738,     0,   150,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,   156,   157,     0,     0,     0,     0,
       0,   158,     0,     0,     0,   288,     0,     0,   289,     0,
       0,   290,     0,   291,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   292,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,     0,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,  1224,
       0,     0,     0,   430,   161,     0,     0,   164,     0,     0,
       0,     0,   165,   166,   167,   168,   169,     0,     0,    88,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   172,   451,     0,     0,   430,   174,
     809,     0,     0,     0,   294,   754,   109,   285,     0,   178,
       0,   554,   112,   113,   114,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   287,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
     145,     0,     0,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   155,   156,   157,     0,
       0,     0,     0,     0,   158,     0,     0,     0,   288,     0,
       0,   289,     0,     0,   290,     0,   291,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   292,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
     164,     0,     0,     0,     0,   165,   166,   167,   168,   169,
       0,     0,    88,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   172,   451,     0,
       0,   430,   174,     0,     0,     0,     0,   294,   691,   109,
     285,     0,   178,     0,   812,   112,   113,   114,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   287,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   145,     0,     0,     0,     0,   150,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   155,
     156,   157,     0,     0,     0,     0,     0,   158,     0,     0,
       0,   288,     0,     0,   289,     0,     0,   290,     0,   291,
     320,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   292,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,     0,     0,     0,     0,   137,   138,   139,   140,   141,
     142,     0,     0,     0,   146,   147,   148,   149,     0,     0,
       0,     0,   151,   152,   153,     0,     0,   154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   159,     0,
     161,     0,     0,   164,     0,     0,     0,     0,   165,   166,
     167,   168,   169,     0,     0,    88,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     172,   293,     0,     0,   430,   174,     0,     0,     0,     0,
     294,   754,   109,   285,     0,   178,     0,  1354,   112,   113,
     114,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   287,     0,     0,     0,     0,
       0,   162,   163,     0,   143,   144,   145,     0,     0,     0,
       0,   150,     0,   170,     0,     0,   171,     0,     0,     0,
       0,     0,   155,   156,   157,     0,     0,     0,     0,     0,
     158,     0,     0,     0,   288,     0,     0,   289,     0,     0,
     290,   111,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,     0,   137,   138,   139,   140,   141,
     142,     0,     0,     0,   146,   147,   148,   149,     0,     0,
       0,     0,   151,   152,   153,     0,     0,   154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   159,     0,
       0,     0,     0,   161,     0,     0,   164,     0,     0,     0,
       0,   165,   166,   167,   168,   169,     0,     0,    88,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   507,  1466,     0,     0,   430,   174,     0,
       0,     0,     0,   509,   755,   109,   326,     0,   178,     0,
     252,   112,   113,   114,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,   162,   163,     0,     0,     0,     0,   143,   144,   145,
       0,     0,     0,   170,   150,     0,   171,     0,     0,     0,
       0,     0,     0,     0,     0,   155,   156,   157,   109,   326,
     111,     0,     0,   158,   112,   113,   114,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,     0,
       0,   151,   152,   153,     0,     0,   154,     0,   155,   156,
     157,     0,     0,     0,     0,     0,   158,   159,     0,     0,
       0,     0,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   161,     0,     0,   164,
     430,     0,     0,     0,   165,   166,   167,   168,   169,   911,
       0,    88,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   507,   508,     0,     0,
     430,   174,     0,     0,     0,     0,   509,  1446,     0,  1447,
       0,   178,     0,   252,     0,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   161,
     162,   163,   164,   430,     0,   701,     0,   165,   166,   167,
     168,   169,   170,     0,    88,   171,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   172,
     173,     0,     0,     0,   174,   109,   285,     0,     0,   294,
       0,   112,   113,   114,   178,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   287,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   144,   145,
       0,     0,     0,     0,   150,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   155,   156,   157,     0,     0,
       0,     0,     0,   158,     0,     0,     0,   288,     0,     0,
     289,     0,     0,   290,     0,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   292,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,     0,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
      -4,     1,     0,  1481,    -4,  1482,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,     0,   161,     0,     0,   164,
       0,     0,     0,     0,   165,   166,   167,   168,   169,     0,
       0,    88,     0,     0,     0,     0,     0,    -4,    -4,     0,
       0,     0,     0,     0,     0,     0,   172,   451,     0,     0,
       0,   174,     0,    -4,    -4,    -4,   294,     0,     0,    -4,
      -4,   178,    -4,     0,     0,     0,    -4,    -4,     0,    -4,
      -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,
      -4,    -4,    -4,     6,     0,     0,     0,     0,    -4,     0,
       0,     7,     8,    -4,    -4,    -4,    -4,     0,     0,    -4,
       0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     9,    10,    -4,    -4,
      -4,    -4,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,    11,    12,    13,     0,     0,     0,    14,    15,
       0,    16,     0,     0,     0,    17,    18,     0,    19,    20,
       0,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,    54,    55,
      56,    57,    58,    59,    60,    61,     7,     8,     0,    62,
      63,    64,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,    66,    67,    68,    69,     0,     0,    70,     0,
      71,     0,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,     0,     0,     0,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   657,
      24,    25,   658,    27,    28,   659,    30,   660,    32,     0,
      33,     0,     0,     0,     0,    38,    39,     0,    41,    42,
      43,     0,     0,     0,    46,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
    1600,     0,  1601,     0,     0,     0,     0,     0,    67,    68,
      69,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,   962,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,     0,     0,  1015,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,     0,     0,  1035,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
       0,     0,  1065,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,     0,     0,
    1169,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,  1444,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,     0,     0,  1463,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,     0,     0,  1518,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
       0,     0,  1519,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,     0,     0,
    1520,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,  1521,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,     0,     0,  1522,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,     0,     0,  1554,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
       0,     0,  1616,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,     0,     0,
    1626,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,  1627,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,     0,     0,  1655,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,     0,     0,  1658,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
       0,     0,  1661,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,     0,     0,
    1688,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,  1695,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,     0,     0,  1730,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,     0,     0,  1732,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
       0,     0,  1734,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,     0,     0,
    1752,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,  1778,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,     0,     0,  1816,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,     0,     0,  1817,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
       0,     0,  1821,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,     0,     0,
    1822,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,  1823,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,     0,     0,  1824,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,     0,   585,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,     0,
     747,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,  1530,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,   821,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,   856,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,   864,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,   865,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,   866,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,   877,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,   997,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,   998,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,   999,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,  1030,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,  1121,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,  1167,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,  1168,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,  1223,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,  1362,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,  1363,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,  1364,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,  1365,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,  1402,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,  1403,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,  1410,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,  1555,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,  1556,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,  1557,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,  1558,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,  1574,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,  1575,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,  1579,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,  1673,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,  1674,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,  1675,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,  1676,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,  1683,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,  1686,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,  1726,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,  1743,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,  1744,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,  1745,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,  1746,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,  1789,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,  1790,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,  1791,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,  1792,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,   411,     0,   412,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,   649,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,   826,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,   835,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
     843,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,   927,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,  1023,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,  1024,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,  1028,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,  1029,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,  1031,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,  1068,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,  1116,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,  1359,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
    1393,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,  1543,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,   705,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,   706,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,   708,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,   710,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,   711,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,   714,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
     715,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,   809,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,   817,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,   818,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,   819,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,   825,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,   834,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,   842,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,   926,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,   951,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
     956,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,   961,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,   964,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,   965,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,   971,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,   980,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,   981,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,   982,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,  1014,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,  1016,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
    1017,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,  1018,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,  1022,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,  1256,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,  1445,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,  1462,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,  1485,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,  1682,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,  1750,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430
};

static const yytype_int16 yycheck[] =
{
       3,   245,   260,     5,   372,   108,   374,   501,   502,  1352,
       3,     5,     4,   194,   272,     6,     4,   385,     4,     6,
       5,     4,   402,     5,     4,     6,     4,     6,     4,     6,
       4,   194,     5,   196,   414,     4,     4,   184,   185,     4,
       4,     4,     4,    81,     5,    83,     5,     5,     5,    49,
      50,     6,    52,   200,    57,     5,    78,     6,     6,    81,
       4,  1013,    65,     4,     7,   323,  1009,   325,     6,     6,
       6,     6,     4,   139,     6,     6,    79,   184,   185,     6,
     184,   185,  1425,   184,   185,    98,   152,   153,   102,   103,
     194,   184,   185,   200,   108,   202,   109,   201,     3,     6,
     201,     6,   184,   185,   117,   118,   119,   200,   194,   202,
     123,   124,   125,   126,   194,     7,     0,   225,   226,   227,
     202,   201,   230,   231,   232,   194,   194,   184,   185,   184,
     185,     7,   201,   201,    75,   184,   185,     6,    79,     7,
     142,    79,    80,    75,   201,   200,   129,   130,   131,   132,
      91,   200,    57,     7,   184,   185,   148,   142,   266,   267,
     142,   184,   185,   139,   140,   139,   140,     7,  1511,   142,
     200,   151,   280,   281,    79,   178,    75,   169,   201,    78,
       7,    13,    81,   169,  1527,     6,   179,   190,   191,   202,
     127,   127,   127,   184,   185,   198,   127,   184,   185,   201,
     181,   191,   192,   206,   181,   208,     6,   201,   196,   201,
     213,   190,   191,   593,   217,   203,   194,   220,   196,   202,
     198,   224,   225,   226,   227,   203,   194,   230,   231,   232,
     194,    81,   201,   201,   492,   493,   201,   201,   201,   201,
     201,   244,   201,   201,   201,   194,   201,  1190,   248,   249,
     194,   201,   201,   201,   512,   198,   256,   184,   185,    78,
     260,   194,    81,   266,   267,   268,     7,   205,   648,   649,
       6,   184,   185,   178,     6,   184,   185,   280,   281,   171,
     172,   173,   174,   195,     6,   190,   191,   200,   200,   202,
     293,   200,   295,   198,   196,   171,   172,   173,   174,   402,
     196,   206,   198,   171,   172,   173,   174,   203,    78,   184,
     185,    81,   194,    83,   572,   191,   192,   171,   172,   173,
     174,     4,   198,   191,   192,   200,   329,   585,   331,   332,
     196,   171,   172,   173,   174,   336,   194,   191,   192,   184,
     185,   344,  1685,     8,   171,   172,   173,   174,   191,   192,
     329,   191,   192,   191,   192,   200,   191,   192,   201,    85,
     198,   194,   184,   185,   191,   192,   201,    81,   201,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   200,   382,
     383,   384,   385,   386,   194,   191,   192,   390,   391,   392,
     393,   394,   194,   396,   373,   201,   375,   376,   377,   337,
     379,   380,     8,   382,   383,   384,   194,   386,   196,   194,
     413,   390,   391,   392,   393,   203,   184,   185,   194,   102,
     103,   104,   105,   195,   329,   197,     6,     7,   111,   201,
       6,   114,   200,  1776,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   451,   194,
     388,   196,   193,   198,   834,   835,   201,   395,   203,   197,
     184,   185,   200,   200,   194,   202,   196,   372,   373,   374,
     375,   376,   377,   203,   379,   380,   200,   382,   383,   384,
     385,   386,    81,   486,   487,   390,   391,   392,   393,   394,
     201,   396,   750,   194,   194,   196,   196,   600,   198,   499,
     500,   195,   203,   203,     8,    83,   200,   507,   501,   502,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    81,   528,   529,   530,   193,    75,
     195,   195,    78,   184,   185,    81,   200,   540,   539,   184,
     185,   479,   480,   481,   482,   648,   649,   184,   185,   200,
      81,   554,   184,   185,    75,   200,   194,    78,   561,   195,
      81,   197,    83,   200,   565,   201,     6,     7,   200,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   184,   185,   201,  1538,   193,  1540,   592,
    1542,   195,   972,   197,   974,    81,   976,   201,   978,   200,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   201,   613,   614,   615,   616,   617,   618,   619,   200,
      78,   202,   623,   624,   625,   184,   185,   197,   184,   185,
     200,    98,   633,   634,   635,   540,   637,    78,   184,   185,
     195,   200,   109,   644,   200,   200,    78,   195,   194,   197,
     117,   118,   119,   201,   655,   201,   123,   124,   125,   126,
     904,  1604,   665,    78,  1607,   195,    81,  1610,    83,    81,
     200,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   688,     4,   690,   791,   193,
     693,   184,   185,   696,   200,   698,   202,     4,   202,   702,
     703,   184,   185,   195,   184,   185,     4,   200,   200,  1089,
     184,   185,   650,   195,   693,   197,  1668,   200,   200,   698,
     200,     4,    98,   726,   194,  1105,   200,   184,   185,   184,
     185,   834,   835,   109,   200,   202,   202,     6,   194,   842,
     843,   117,   118,   119,   747,   200,     8,   123,   124,   125,
     126,   194,   194,   753,   184,   185,   186,   187,   188,   195,
     760,   197,   700,   193,   200,    75,   766,  1710,    78,   102,
     103,    81,   200,    83,   202,   108,   200,  1729,   202,  1731,
     200,  1733,   202,   186,   187,   188,     6,  1739,   693,   792,
     193,   696,   196,   698,   195,   195,   197,   197,   801,   200,
     803,   195,   805,   197,   807,   195,   200,   197,   196,   812,
     200,   194,   815,  1756,     7,   195,  1759,   194,   196,  1762,
     200,   194,  1765,   926,   927,   200,   202,   202,   195,   832,
    1782,     6,  1784,   200,  1786,   838,  1330,  1331,   194,   194,
     843,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,  1096,   201,   194,  1235,   193,    98,  1801,   200,
    1803,   202,  1805,   194,   843,   868,   194,    81,   109,    83,
     873,   874,   875,   876,   194,   194,   117,   118,   119,   200,
     194,   202,   123,   124,   125,   126,   889,   200,   200,   202,
     202,   200,     6,   202,   873,   194,   875,   876,   200,    81,
     202,    83,     6,   194,   907,   908,   909,   910,   201,   194,
     889,   912,   194,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   201,  1031,   932,
     200,   193,   202,   200,   200,   202,   202,   194,   843,   877,
     202,   194,   943,   944,   194,   945,   949,   950,   200,   952,
     202,   954,   955,   932,    98,   958,   959,   200,   194,   202,
     963,   202,   200,   194,   202,   109,   194,   200,   873,   202,
     875,   876,   194,   117,   118,   119,   200,     4,   202,   123,
     124,   125,   126,   200,   889,   202,  1089,   200,   200,   202,
     202,   200,   200,   202,   202,   194,   194,   997,   998,   999,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   200,    98,   202,   200,   193,   202,
       4,   194,     6,  1267,   201,   201,   109,   932,   200,   200,
     202,   202,   201,   201,   117,   118,   119,   201,   201,  1533,
     123,   124,   125,   126,  1047,  1048,  1049,   194,   194,     4,
       5,   196,   200,     6,   202,  1058,   194,   200,   202,   202,
     200,   200,   202,   202,   200,  1066,   202,   200,   200,   202,
     202,     6,  1073,  1074,  1075,  1076,  1077,   200,   200,   202,
     202,   194,  1083,  1084,    39,    40,    41,    42,    43,    44,
     200,   203,   202,    48,    49,    50,    51,    12,    13,     6,
     201,    56,    57,    58,    98,   200,    61,   202,  1111,   200,
     200,   202,   202,   201,   200,   109,   202,    72,   200,   202,
     202,   201,   196,   117,   118,   119,   196,  1130,  1496,   123,
     124,   125,   126,  1136,   200,  1238,   202,   196,   200,  1142,
     202,  1144,  1145,   200,     6,   202,  1149,  1150,   200,  1152,
     202,  1154,   200,  1156,   202,  1158,  1159,  1160,   196,     6,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
     200,    86,   202,  1176,   198,   201,    91,    92,   142,    94,
      95,    96,   203,     6,  1122,   100,     6,     6,  1191,  1189,
       6,   200,  1195,   202,  1197,   201,     6,   196,     4,     7,
     155,   156,   193,   198,   201,     7,  1207,     6,   202,   202,
     200,   200,   167,     6,   169,   170,     6,  1218,     7,   134,
     135,   136,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   191,   192,     7,   195,
     193,     6,  1245,   198,   201,     7,     6,     6,    98,     7,
       6,     6,     4,    53,   139,    53,    53,  1360,  1502,   109,
     201,     4,     5,   197,   195,     6,  1245,   117,   118,   119,
    1273,    53,     6,   123,   124,   125,   126,   195,   195,   200,
    1283,   200,   195,  1286,   200,   195,   200,   202,   200,  1547,
     195,   197,     6,     6,  1294,     6,    39,    40,    41,    42,
      43,    44,     4,     4,  1283,    48,    49,    50,    51,     6,
       6,  1249,     6,    56,    57,    58,     7,   142,    61,  1322,
    1323,  1259,     7,   201,     7,     7,     7,   142,     7,    72,
     142,     7,  1332,     7,  1334,     4,  1336,  1330,  1331,     6,
    1245,   195,   200,   195,    98,   200,   195,  1350,  1286,  1352,
    1350,  1354,   202,  1353,  1354,   109,   200,   195,   200,   198,
       6,   202,   202,   117,   118,   119,  1369,   197,   201,   123,
     124,   125,   126,  1376,   201,   201,     7,  1380,  1283,   201,
       7,  1384,  1383,     7,   198,     6,     6,     6,  1326,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,  1404,     6,     6,   196,   193,     6,   201,     7,     6,
       6,  1669,   155,   156,    98,   194,   194,   201,     6,    83,
     181,     7,  1425,     7,   167,   109,   169,   170,     7,     7,
       7,    12,    13,   117,   118,   119,     7,  1375,     7,   123,
     124,   125,   126,     6,     4,     7,  1384,  1385,  1386,   180,
     181,   182,   183,   184,   185,   186,   187,   188,  1461,     7,
       7,     7,   193,  1466,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     7,     7,
       4,     6,   193,  1486,   201,     6,   194,     7,     6,   201,
    1493,     7,     7,  1496,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     7,    86,     6,     6,  1511,     6,
      91,    92,     6,    94,    95,    96,    81,     6,   202,   100,
       4,     4,     4,     4,  1527,   202,     6,  1530,   200,     6,
       6,     6,     6,     6,    12,    13,   195,  1537,   195,  1539,
    1533,  1541,   195,  1546,   200,   195,   198,     7,  1551,  1549,
       6,   194,  1552,   134,   135,   136,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     198,   201,     6,     6,   193,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     6,
    1593,  1496,  1592,   193,     6,   201,  1596,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,   201,    86,  1612,
       6,   201,    91,    91,    92,     6,    94,    95,    96,   201,
       6,   202,   100,     4,     6,   201,     6,     5,   201,     6,
      86,    87,     7,   201,   201,   201,     6,   196,     6,     6,
       6,     4,     6,   201,   201,  1645,   201,     6,   138,  1649,
       6,   200,     6,     4,     6,     4,   134,   135,   136,     6,
      98,     6,     6,     6,     6,     6,     4,  1670,     5,  1672,
       6,   109,  1672,     6,     6,     6,     6,     6,   201,   117,
     118,   119,  1685,   142,     6,   123,   124,   125,   126,     6,
       6,     6,     6,     6,  1632,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     6,
       6,     6,     6,   193,     6,    98,   172,   173,   174,   175,
     176,     6,     6,     6,   202,     6,   109,  1727,  1728,   200,
     195,     6,     6,   189,   117,   118,   119,   193,  1741,     7,
     123,   124,   125,   126,   198,     6,  1749,     6,   201,     5,
     201,   207,   208,   209,   210,    79,   212,   213,   214,   215,
       6,   217,   218,   219,   202,     6,     6,   202,   224,   201,
    1749,   202,   201,  1776,   201,   201,     6,   201,     7,     6,
      98,     6,  1720,   202,   137,     6,   242,     6,     6,     6,
    1793,   109,  1795,     6,   140,   251,   252,     6,     6,   117,
     118,   119,     6,   201,   260,   123,   124,   125,   126,     6,
       6,     6,     6,     6,  1793,     6,  1795,   201,     6,   202,
       6,    98,  1825,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   293,   294,   295,
     201,   193,   202,   201,  1749,     6,  1825,     6,     6,   305,
     306,   307,     6,   309,     6,     6,   312,   313,     6,     6,
     316,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   201,   201,   333,   334,   193,
       6,   202,     6,     6,   202,     6,     6,     6,  1793,   201,
    1795,   347,   348,   201,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,     6,     6,     6,   201,
    1825,   201,   201,     6,     6,   381,     6,     6,   201,   201,
     201,   387,   201,   389,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,  1635,     6,
       6,     6,   193,     6,   410,     6,     6,   413,     6,     6,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,     6,     6,   433,   434,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,  1119,  1516,   451,     3,   193,   447,  1517,
    1129,   457,     3,  1529,  1263,   477,   462,    -1,    -1,    -1,
      -1,   467,   468,    -1,    -1,    -1,    -1,   473,   474,    -1,
      -1,    -1,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,   505,
     506,   507,   508,   509,    -1,    -1,    -1,   513,   514,   515,
     516,   517,    -1,    -1,    -1,   521,    -1,   523,   524,    -1,
      -1,    -1,   528,   529,   530,    -1,    -1,   533,   534,   535,
     536,   537,    -1,    -1,    -1,     4,     5,   543,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,
      -1,    -1,    -1,    -1,   560,   561,    -1,   563,   564,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    -1,   583,    -1,    48,
      49,    50,    51,    -1,    -1,   591,   592,    56,    57,    58,
      -1,   597,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    72,    -1,   213,    -1,    -1,    -1,   217,
      -1,    -1,     3,     4,     5,    -1,   224,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   651,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      61,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,   685,
      71,    72,   688,    -1,   690,   691,   155,   156,    98,    -1,
      -1,    -1,    -1,   699,    -1,    -1,   702,   703,   167,   109,
     169,   170,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     716,    -1,    -1,   123,   124,   125,   126,    -1,    -1,   725,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   747,    -1,    -1,    -1,    -1,    -1,    -1,   754,   755,
      -1,    -1,    -1,    -1,   760,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   773,    -1,    -1,
     776,   162,   163,   164,   165,   166,   167,    -1,   169,   170,
      -1,    -1,    -1,    -1,    -1,    -1,   792,    -1,    -1,    -1,
      -1,    -1,   202,   184,   185,   801,    -1,   803,   189,   805,
      -1,   807,    -1,   194,    -1,   413,   812,    -1,   199,   815,
     201,    -1,   107,    -1,    -1,   821,    -1,   823,   824,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
     856,   146,   147,   148,   149,    98,    -1,   152,   864,   865,
     866,    -1,   868,   158,   159,    -1,    -1,    -1,    -1,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,   487,
     886,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   894,    -1,
      -1,   897,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,   907,   908,   909,   910,   220,    -1,    -1,   914,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     528,   529,   530,    -1,    -1,    -1,    -1,    -1,    -1,   244,
      12,    13,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   554,    -1,    -1,    -1,
     193,    -1,    -1,   268,    -1,    -1,    -1,   963,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   973,    -1,   975,
      -1,   977,    -1,   979,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,
     285,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    -1,    -1,   302,    -1,    91,
      92,    -1,    94,    95,    96,    -1,   331,   332,   100,    -1,
      -1,  1027,    -1,    -1,  1030,    -1,    -1,    -1,  1034,   344,
    1036,  1037,  1038,    -1,    -1,    -1,    -1,    -1,  1044,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,  1061,    -1,  1063,    12,    13,
      -1,    -1,    -1,   378,    -1,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
     688,    -1,   690,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1097,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,  1109,  1110,    -1,    -1,   213,    -1,    -1,
     405,   217,    -1,    -1,    -1,  1121,  1122,    -1,   224,    -1,
     202,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    -1,    -1,    -1,    -1,    91,    92,   747,
      94,    95,    96,    -1,    -1,    -1,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
    1166,  1167,  1168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1176,    -1,  1178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,  1189,   792,    -1,    -1,   293,    -1,   295,
      -1,  1197,    -1,   801,    -1,   803,    -1,   805,    -1,   807,
      -1,    -1,    -1,    -1,   812,    -1,    -1,   815,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,  1223,  1224,  1225,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    91,    92,    -1,    94,
      95,    96,    -1,    -1,    -1,   100,    -1,    -1,   202,    -1,
      -1,    -1,    -1,    -1,  1260,    -1,     6,    -1,    -1,    -1,
     868,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1274,    -1,
      -1,    -1,    -1,  1279,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,    -1,    -1,    -1,    -1,  1292,  1293,    -1,    -1,
      -1,    -1,     6,  1299,  1300,    -1,    -1,    -1,  1304,   907,
     908,   909,   910,    -1,    -1,    -1,  1312,   413,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1322,  1323,  1324,    -1,
    1326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1350,   451,    -1,   202,  1354,    -1,
     665,  1357,    -1,    -1,    -1,   963,  1362,  1363,  1364,  1365,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1375,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1385,
     486,   487,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,  1402,  1403,    -1,    -1,
     193,    -1,    -1,    -1,  1410,    -1,    -1,    -1,    -1,    -1,
      -1,   726,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   528,   529,   530,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
    1446,    -1,    -1,   193,    -1,    -1,    -1,    -1,   554,    -1,
      -1,    -1,    -1,    -1,    -1,   561,    -1,    -1,  1464,    -1,
    1466,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,  1481,    -1,  1483,    -1,   193,
    1486,    -1,    -1,    -1,    -1,    -1,   592,  1493,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1507,    -1,    -1,    -1,    -1,  1512,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   832,    -1,    -1,
      -1,    -1,    -1,   838,  1530,    -1,    -1,    -1,    -1,    -1,
      -1,  1537,    -1,  1539,    -1,  1541,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,  1551,    -1,    -1,    -1,  1555,
    1556,  1557,  1558,  1559,    -1,    -1,    -1,    -1,    -1,   874,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1574,  1575,
      -1,    -1,    -1,  1579,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   688,  1589,   690,    -1,    -1,    -1,    -1,  1197,
      -1,    -1,    -1,    -1,  1600,    -1,   702,   703,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,    92,
      -1,    94,    95,    96,  1630,    -1,    -1,   100,    -1,  1635,
      -1,    -1,    -1,    -1,   949,   950,  1642,   952,    -1,   954,
     955,   747,    -1,   958,   959,    -1,    -1,    -1,    -1,    -1,
    1656,    -1,    -1,  1659,    -1,    -1,  1662,    -1,    -1,    -1,
    1666,   134,   135,   136,  1670,    -1,  1672,  1673,  1674,  1675,
    1676,    -1,    -1,    -1,    -1,    -1,    -1,  1683,    -1,    -1,
    1686,    -1,    -1,    -1,    12,    13,   792,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   801,    -1,   803,    -1,   805,
      -1,   807,    -1,    -1,    -1,    -1,   812,    -1,    -1,   815,
      -1,    -1,    -1,    -1,  1322,  1323,    -1,    -1,    -1,    -1,
    1726,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
      -1,    -1,  1047,  1048,  1049,  1741,    -1,  1743,  1744,  1745,
    1746,    -1,    -1,  1058,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    -1,
      -1,    -1,   868,    91,    92,    -1,    94,    95,    96,    -1,
      -1,    -1,   100,  1779,  1780,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1789,  1790,  1791,  1792,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1111,    -1,    -1,    -1,
      -1,   907,   908,   909,   910,    -1,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,  1130,    -1,    -1,    -1,    -1,
      -1,  1136,    -1,    -1,    -1,    -1,    -1,  1142,    -1,  1144,
    1145,    -1,    -1,    -1,  1149,  1150,    -1,  1152,    -1,  1154,
      -1,  1156,    -1,  1158,  1159,  1160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   963,    -1,    -1,
      -1,  1176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,    -1,  1191,    -1,  1486,    -1,
    1195,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,  1530,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1551,    -1,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,  1273,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,  1286,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,
      -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    -1,    -1,    -1,   154,  1352,    -1,   157,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,    -1,
      -1,   169,    -1,    -1,  1369,    -1,    -1,    -1,    -1,    -1,
      -1,  1376,  1670,    -1,  1672,  1380,   184,   185,    -1,  1384,
      -1,   189,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,   199,    -1,   201,    -1,    -1,    -1,    -1,    -1,  1404,
      -1,  1197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
    1425,    -1,   154,   155,   156,   157,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,    -1,   169,   170,    -1,
      -1,    -1,    -1,  1741,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,    -1,    -1,  1461,   189,    -1,    -1,
      -1,    -1,   194,    -1,   196,    -1,   198,   199,    -1,   201,
      -1,   203,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,  1511,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    52,  1527,    -1,    -1,    -1,  1322,  1323,    -1,    -1,
      -1,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      71,  1546,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,  1350,     9,    10,    11,  1354,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,  1593,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1612,    -1,    63,
      64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,    75,    -1,   154,    78,    -1,   157,    81,    -1,    83,
      -1,   162,   163,   164,   165,   166,    -1,    -1,   169,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   184,   185,    -1,    -1,   111,   189,    -1,
     114,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,
    1466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1685,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1486,    -1,    -1,    -1,    -1,    -1,    -1,  1493,    -1,    -1,
     154,    -1,    -1,   157,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,   166,     6,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,   185,    -1,    -1,  1530,   189,    -1,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,    -1,
      -1,    -1,    -1,    -1,    -1,  1551,    -1,    -1,    -1,     6,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,  1776,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    81,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,   111,
      -1,    -1,   114,    -1,  1670,    -1,  1672,    -1,    -1,    -1,
      -1,    -1,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   154,    -1,    -1,   157,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,   166,     7,     8,   169,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   184,   185,    -1,  1741,   193,   189,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,
     202,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,
      -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    81,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,   111,
      -1,    -1,   114,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     8,    -1,    -1,
      -1,   193,   154,   155,   156,   157,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,    -1,   169,   170,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,    -1,    -1,    -1,   189,    -1,    -1,
      -1,    -1,   194,    -1,     3,     4,     5,   199,    -1,   201,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    61,    -1,    63,    64,    65,    -1,    -1,    -1,
      -1,    -1,    71,    72,    -1,    -1,    75,    -1,    -1,    78,
      -1,    -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,    -1,    -1,
      -1,    -1,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,    -1,
     169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   185,    -1,    -1,    -1,
     189,    -1,    -1,    -1,    -1,   194,    -1,     3,     4,     5,
     199,    -1,   201,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,     8,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    61,    -1,    63,    64,    65,
      -1,     3,     4,     5,    -1,    71,    72,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,
      -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    -1,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   154,   155,
     156,   157,   193,    -1,   195,    -1,   162,   163,   164,   165,
     166,   167,    -1,   169,   170,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,   185,
      -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,   199,    -1,   201,    -1,    -1,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   154,   155,   156,   157,   193,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,    -1,   169,   170,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,    -1,    -1,    -1,   189,    -1,    -1,
      -1,    -1,   194,    -1,     3,     4,     5,   199,    -1,   201,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    52,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,
      -1,    -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,    -1,    -1,
      -1,    -1,   111,    -1,    -1,   114,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    -1,
      -1,    -1,    -1,    91,    92,    -1,    94,    95,    96,    -1,
      -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,    -1,    -1,
     169,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   185,    -1,    -1,    -1,
     189,    -1,    -1,    -1,    -1,   194,    -1,     3,     4,     5,
     199,    -1,   201,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,   202,    -1,    52,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    75,
      -1,    -1,    78,    -1,    -1,    81,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,
     106,    -1,    -1,    -1,    -1,   111,    -1,    -1,   114,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    91,    92,    -1,    94,
      95,    96,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
      -1,   157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
     166,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   184,   185,
      -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,   194,    -1,
       3,     4,    -1,   199,    -1,   201,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,   202,    -1,    52,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    81,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,    -1,    -1,    -1,    -1,   111,    -1,
      -1,   114,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,
      92,    -1,    94,    95,    96,    -1,    -1,    -1,   100,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,    -1,   157,    -1,    -1,    -1,     8,   162,
     163,   164,   165,   166,    -1,    -1,   169,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   184,   185,    -1,    -1,    -1,   189,    -1,    -1,    -1,
      -1,   194,    -1,     3,     4,    -1,   199,    -1,   201,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
     202,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,
      -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,   104,   105,   106,    -1,    -1,    -1,
      -1,   111,    -1,    -1,   114,    -1,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     8,
      -1,    -1,    -1,   193,   154,    -1,    -1,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,   166,    -1,    -1,   169,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   184,   185,    -1,    -1,   193,   189,
     195,    -1,    -1,    -1,   194,   200,     3,     4,    -1,   199,
      -1,   201,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    81,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,
      -1,    -1,    -1,    -1,   111,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
      -1,    -1,   169,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   184,   185,    -1,
      -1,   193,   189,    -1,    -1,    -1,    -1,   194,   200,     3,
       4,    -1,   199,    -1,   201,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,    75,    -1,    -1,    78,    -1,    -1,    81,    -1,    83,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,    -1,    -1,    -1,    -1,   111,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
     154,    -1,    -1,   157,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,   166,    -1,    -1,   169,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     184,   185,    -1,    -1,   193,   189,    -1,    -1,    -1,    -1,
     194,   200,     3,     4,    -1,   199,    -1,   201,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,   155,   156,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    52,    -1,   167,    -1,    -1,   170,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
      81,     5,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,
     111,    -1,    -1,   114,    -1,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,   154,    -1,    -1,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,    -1,    -1,   169,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   184,   185,    -1,    -1,   193,   189,    -1,
      -1,    -1,    -1,   194,   200,     3,     4,    -1,   199,    -1,
     201,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,   155,   156,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,   167,    52,    -1,   170,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,     3,     4,
       5,    -1,    -1,    71,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    61,    -1,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,
      -1,    -1,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   154,    -1,    -1,   157,
     193,    -1,    -1,    -1,   162,   163,   164,   165,   166,   202,
      -1,   169,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   184,   185,    -1,    -1,
     193,   189,    -1,    -1,    -1,    -1,   194,   200,    -1,   202,
      -1,   199,    -1,   201,    -1,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   154,
     155,   156,   157,   193,    -1,   195,    -1,   162,   163,   164,
     165,   166,   167,    -1,   169,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,
     185,    -1,    -1,    -1,   189,     3,     4,    -1,    -1,   194,
      -1,     9,    10,    11,   199,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,
      78,    -1,    -1,    81,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,    -1,
      -1,    -1,    -1,   111,    -1,    -1,   114,    -1,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
       0,     1,    -1,   200,     4,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,   154,    -1,    -1,   157,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   185,    -1,    -1,
      -1,   189,    -1,    53,    54,    55,   194,    -1,    -1,    59,
      60,   199,    62,    -1,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,    -1,
     120,   121,   122,     4,    -1,    -1,    -1,    -1,   128,    -1,
      -1,    12,    13,   133,   134,   135,   136,    -1,    -1,   139,
      -1,   141,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    37,    38,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,
      -1,    -1,    53,    54,    55,    -1,    -1,    -1,    59,    60,
      -1,    62,    -1,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    -1,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,    12,    13,    -1,   120,
     121,   122,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,
      -1,    -1,   133,   134,   135,   136,    -1,    -1,   139,    -1,
     141,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    -1,    -1,    -1,    -1,    91,    92,    -1,    94,    95,
      96,    -1,    -1,    -1,   100,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,    -1,   202,    -1,    -1,    -1,    -1,    -1,   134,   135,
     136,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   201,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,   200,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,   200,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,   200,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,   200,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,   200,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,   200,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,   200,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,   200,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,   195,    -1,   197,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,   197,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,   197,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,   197,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
     197,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,   197,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,   197,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,   197,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,   197,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,   197,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,   197,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,   197,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,   197,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,   197,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
     197,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,   197,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,   195,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,   195,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,   195,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,   195,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,   195,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,   195,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
     195,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,   195,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,   195,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,   195,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,   195,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,   195,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,   195,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,   195,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,   195,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,   195,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
     195,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,   195,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,   195,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,   195,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,   195,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,   195,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,   195,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,   195,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,   195,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,   195,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
     195,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,   195,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,   195,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,   195,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,   195,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,   195,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,   195,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,   195,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,   195,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   205,   206,     6,     0,     4,    12,    13,    37,
      38,    53,    54,    55,    59,    60,    62,    66,    67,    69,
      70,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   109,   110,   111,   112,   113,   114,
     115,   116,   120,   121,   122,   128,   133,   134,   135,   136,
     139,   141,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   158,   159,   160,   161,   168,   169,   207,
     209,   210,   230,   247,   248,   251,   252,   253,   254,   255,
     256,   257,   258,   279,   280,   281,   282,   300,   301,     3,
       4,     5,     9,    10,    11,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    56,    57,    58,    61,    63,    64,    65,    71,    72,
     148,   154,   155,   156,   157,   162,   163,   164,   165,   166,
     167,   170,   184,   185,   189,   194,   196,   198,   199,   201,
     203,   228,   283,   284,   296,   297,   300,   301,    13,    81,
     194,   194,     6,   201,     6,     6,     6,     6,   194,     6,
       6,   196,   196,   194,   196,   228,   228,   194,   201,   194,
     194,     4,   194,   201,   194,   194,     4,   201,   194,   194,
      85,    81,    81,     6,   201,    75,    78,    81,    81,    81,
      78,    81,    83,    83,    75,    78,    81,    83,    78,    81,
      83,    78,    81,   194,    78,   139,   152,   153,   201,   184,
     185,   194,   201,   286,   287,   286,   201,    75,    78,    81,
     201,   286,     4,    75,    79,    91,    81,    83,    81,    78,
       4,   148,   201,   300,   301,     4,     6,    75,    78,    81,
      78,    81,     4,     4,     4,     4,     5,    36,    75,    78,
      81,    83,    95,   185,   194,   201,   248,   258,   283,   289,
     290,   291,   300,   301,     4,   194,   194,   194,     4,   201,
     293,     4,   194,   194,     6,     6,   196,     4,   297,   301,
       4,   297,     5,   201,     5,   201,     4,   283,   283,   196,
       6,   194,   201,   194,   196,   203,   228,     7,   171,   172,
     173,   174,   191,   192,   226,   227,     4,   194,   196,   198,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   194,   194,   194,   194,   194,
     194,   228,   228,   228,   228,   194,   228,   228,   228,     7,
     194,   194,   194,   228,   194,   194,   196,   283,   283,   283,
     283,   283,     4,   139,   140,   301,     4,   248,   249,   250,
     201,   195,   197,   201,   229,     6,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     193,   201,     6,   194,   196,   227,     6,   283,     4,   296,
     297,   301,   296,   283,   296,   299,   232,   235,   297,   301,
     283,   185,   283,   291,   292,   283,   283,   194,   283,   292,
     283,   283,   194,   292,   283,   283,   289,   194,   201,   292,
     290,   290,   290,   194,   194,   290,   290,   290,   194,   194,
     194,   194,   194,   194,   194,   194,   201,   201,   283,     4,
     289,   293,   201,   201,   286,   286,   286,   283,   283,   184,
     185,   201,   201,   286,   201,   201,   201,   184,   185,   194,
     250,   286,   201,   194,   201,   194,   194,   194,   290,   290,
     289,   194,     4,   196,   196,   250,     6,     6,   201,   201,
     201,   290,   290,   196,   196,   196,   194,   196,   198,   228,
     196,     5,   142,   201,     5,   142,     5,   142,     5,   142,
      75,    78,    81,    83,   201,   283,   291,   283,   202,   292,
       8,   186,     6,   194,   196,   228,     6,   283,   283,   283,
     198,   283,   201,   142,   283,   283,   283,     6,     6,     6,
     250,     6,   250,   196,     6,   201,   296,   289,   289,   283,
     283,   201,   201,   229,   297,   289,     6,   196,   283,   283,
       4,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   299,   296,   299,   296,   296,   296,   289,
     296,   296,   283,   296,   296,   296,   299,   296,   283,   297,
     283,   296,   296,   296,   296,   301,   297,   301,   195,   197,
       7,   226,   227,   198,     7,   228,   202,    75,    78,    81,
      83,   247,   283,   292,     7,   226,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   211,   283,   283,     6,   196,   198,   195,   200,   195,
     200,   200,   195,   200,   197,   200,   231,   197,   231,   200,
     200,   195,   186,   200,   202,   195,   195,   283,   195,   202,
     195,   195,   283,   202,   195,   195,     7,   283,   283,   202,
       6,     6,     6,   283,   283,     7,     7,   276,   276,   283,
     241,   283,   297,   242,   283,   297,   243,   283,   297,   244,
     283,   297,   283,   283,   283,   292,   292,   201,   195,     6,
     201,   250,   250,   200,   200,   200,   286,   286,   249,   249,
     200,   283,   283,   283,   283,   262,   200,   250,   283,   283,
     283,   283,   283,     7,   277,     6,     7,   283,     6,   283,
     283,   202,   292,   292,   292,     6,     6,   283,   283,   283,
     283,     4,   201,   229,   301,    53,   283,    53,    53,    53,
       5,   201,     5,   201,     5,   201,     5,   201,   292,   195,
     202,   283,   201,   283,   291,   201,   229,   195,   195,   195,
     139,   200,   250,   201,     8,   195,   197,   202,   202,   250,
     197,   195,   200,   202,   195,   197,   283,   292,   226,     6,
       6,   283,   195,   197,   227,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   200,   229,   229,   229,
     229,   229,   229,   229,   200,   200,   200,   229,   200,   229,
     229,   195,   195,   200,   200,   200,   200,   200,   229,   229,
     229,   195,   229,   285,   298,     6,   200,   195,   195,   200,
     229,   195,   195,   197,   226,   227,   198,   226,   227,   297,
     283,     6,     4,     4,   201,   294,   229,   201,   201,   201,
     201,   202,   202,   289,     8,     4,   129,   130,   131,   132,
     202,   214,   218,   221,   223,   224,   195,   197,   283,     4,
       6,   181,   208,   292,     6,   292,   283,     6,   296,     6,
     301,     6,   296,   283,   297,     7,   283,   291,   142,     7,
       7,   195,     7,   142,     7,     7,   195,   142,     7,     7,
     283,   195,   202,   201,   195,   195,   283,   289,     4,   275,
       6,   195,   195,   200,   195,   200,   195,   200,   195,   200,
     195,   195,   195,   202,   202,   292,   198,   250,   202,   202,
     286,   283,   283,   202,   202,   283,   286,   200,   200,   200,
      98,   109,   117,   118,   119,   123,   124,   125,   126,   272,
     273,   286,   202,   259,   195,   202,   195,   195,   195,   283,
       6,   283,   195,   197,   197,   202,   202,   202,   197,   197,
     200,   197,   292,   197,   201,   202,   201,   201,   201,   292,
     292,   292,   292,   202,     8,   292,   292,     7,     7,     7,
     198,   283,   202,   283,   283,     7,   198,   202,   201,   289,
       6,   226,   227,   226,   227,   202,   202,   289,   197,   227,
     198,   227,   296,   283,   283,   283,   283,   292,   296,   289,
     296,   296,   297,   237,   239,   283,   296,   283,     6,     4,
     139,   140,   283,     6,     6,     6,     7,   196,   293,   295,
       6,   292,   292,   292,   292,   229,     6,   283,   215,   194,
     194,   201,   225,     6,   227,   227,   197,   181,   296,   195,
     195,   200,     7,   229,   229,   286,    81,    83,   289,   289,
       7,   289,    81,    83,   289,   289,     7,    83,   289,   289,
       6,     7,     7,   292,     7,     7,    98,   274,     6,     7,
     226,   283,   226,   283,   226,   283,   226,   283,     7,     7,
       7,     7,     7,   202,     4,   202,   200,   200,   200,   202,
     202,   286,   286,   286,     4,     6,   201,     6,   194,     6,
     127,     6,   127,     6,   127,     6,   127,   202,   273,   200,
     272,     7,     6,     7,     7,     7,     6,   201,     6,     6,
       6,    81,   283,     6,     6,   283,   198,   202,   283,   283,
     283,   283,   202,   202,   202,   202,   283,   202,   202,   289,
     289,   289,     4,   200,     8,     8,   195,     4,     4,   289,
     202,   283,     6,   283,     6,   229,     6,     6,     4,     6,
     229,   229,   229,   229,   229,   200,   195,   195,   195,   200,
     200,   229,   238,   200,   229,   240,   195,   195,     6,     7,
     226,   227,   198,     7,     6,   293,   283,   200,   202,   202,
     202,   202,   202,   226,   194,   283,   283,   288,   289,   201,
     198,     6,     6,   208,     6,   283,   201,   283,   297,     6,
       6,     6,   201,   201,    91,   246,   246,   289,     6,   201,
     201,     6,     6,   289,   201,     6,     6,     5,   289,   202,
     289,   289,     4,     6,   289,   289,   289,   289,   289,   289,
     289,   289,   201,   201,     7,     6,     7,   283,   283,   283,
     201,   201,   200,   202,   200,   202,   200,   202,   196,   283,
     289,   283,     6,     6,     6,     6,   283,   286,   202,     5,
     201,   289,   201,   201,   201,   289,   292,   201,     6,   197,
       4,   229,   200,   200,   200,   200,   229,     6,     6,   138,
     283,   283,   283,     6,     6,     7,   200,     6,     6,     6,
     226,   227,   296,   297,     4,     4,   151,   297,   283,     6,
       4,   294,     6,   197,   293,     6,     6,     6,     6,   289,
     212,   283,   200,   200,   200,   202,   213,   283,     4,   296,
     200,   289,   297,   283,   283,   286,     6,     6,     6,   283,
     283,     6,   283,     5,     6,   201,     6,   142,   245,   283,
       6,     6,     6,     6,     6,     6,     4,     6,     6,   292,
     292,   283,   283,   297,   202,   195,   200,   202,   249,   249,
     286,     6,   263,   286,     6,   264,   286,     6,   265,   283,
     202,   200,   195,   202,   200,     6,   185,   286,     6,   288,
     286,   286,     6,   202,   283,     6,   283,   283,   283,   283,
     289,   200,   202,     8,   202,   195,   201,   283,   297,   289,
     289,   195,   229,   201,   289,   297,   201,   283,   297,   297,
       6,     6,     7,     6,   198,     6,   195,   200,   283,   283,
     289,   201,   200,   202,     6,   283,   233,   234,   202,   202,
     202,   202,   202,     5,   288,    79,     6,   201,   202,   202,
     201,     6,     6,   201,   283,   202,   202,   200,   201,   200,
     201,   200,   201,   197,     6,   289,     7,   201,   283,   200,
     202,   200,   200,     6,   202,   200,   200,   200,   200,   137,
     283,   283,   292,     6,     6,   202,     6,   236,   283,   299,
     293,   140,   216,   283,   200,   200,   288,   283,     6,   200,
     237,   239,     6,     6,     6,     6,     6,     6,   202,   201,
     288,   102,   103,   108,   278,   102,   103,   278,   292,   249,
     200,   202,   283,   286,   272,   283,   286,   272,   283,   286,
     272,     6,   200,   202,   289,   250,   202,   286,     6,   292,
     286,   283,   283,   283,   283,   283,   202,   202,   202,     6,
     200,   202,     7,   202,     6,   201,   283,   283,   202,   283,
     202,   202,   201,   283,   202,   201,   286,   289,     6,   201,
     286,     6,   202,   202,   283,   202,   200,   202,   202,   200,
     202,   202,   200,   202,   289,     6,    98,   202,   260,   201,
     200,   202,   200,   200,   200,   200,   200,     6,     6,   283,
     297,   213,   195,   200,     6,   201,   200,   283,   202,     6,
     286,     6,   286,     6,     6,   202,     6,   266,   283,     6,
       6,   267,   283,     6,     6,   268,   283,     6,   202,   283,
     272,   250,   292,     6,   286,   292,   283,   283,   283,   283,
       7,   202,   219,   283,   288,   283,   200,   200,   200,   201,
     202,   201,   202,   201,   202,     6,     6,   202,   202,   261,
     202,   200,   202,   200,   200,   200,   200,   297,     6,   201,
     195,   202,   202,   283,   286,   286,   272,     6,   269,   272,
       6,   270,   272,     6,   271,   272,     6,   292,     6,   283,
     283,   283,   283,   217,   296,   222,   201,     6,   202,   200,
     200,   202,   201,   202,   201,   202,   201,   202,   202,   200,
     200,   200,   200,   200,   202,   201,   288,     6,   283,   283,
       6,   272,     6,   272,     6,   272,     6,   283,   283,   283,
     283,   296,     6,   220,   296,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   200,   202,     6,     6,     6,
       6,     6,     6,   296,     6
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
#line 193 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 204 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 205 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 206 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 207 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 208 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 209 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 210 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 211 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 212 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 213 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 16:
#line 214 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 215 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 216 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 217 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 218 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 219 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 224 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 23:
#line 228 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 24:
#line 235 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 25:
#line 240 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 26:
#line 245 "Gmsh.y"
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
#line 259 "Gmsh.y"
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
#line 272 "Gmsh.y"
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
#line 285 "Gmsh.y"
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
#line 313 "Gmsh.y"
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
#line 327 "Gmsh.y"
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
#line 340 "Gmsh.y"
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
#line 353 "Gmsh.y"
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
#line 371 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 40:
#line 385 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:
#line 387 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:
#line 392 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 43:
#line 394 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 44:
#line 399 "Gmsh.y"
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
#line 503 "Gmsh.y"
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
#line 513 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 47:
#line 522 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 48:
#line 529 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 49:
#line 539 "Gmsh.y"
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
#line 548 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 51:
#line 557 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 564 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 574 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 54:
#line 582 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 55:
#line 592 "Gmsh.y"
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
#line 611 "Gmsh.y"
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
#line 630 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 58:
#line 636 "Gmsh.y"
    {
    ;}
    break;

  case 59:
#line 643 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 60:
#line 644 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 61:
#line 645 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 62:
#line 646 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 63:
#line 647 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 64:
#line 651 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 652 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 66:
#line 658 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 67:
#line 658 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 68:
#line 659 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 69:
#line 659 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 72:
#line 668 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 73:
#line 673 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 74:
#line 679 "Gmsh.y"
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
#line 739 "Gmsh.y"
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
#line 768 "Gmsh.y"
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
#line 797 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 78:
#line 802 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 79:
#line 807 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 80:
#line 812 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 81:
#line 817 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 82:
#line 824 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 83:
#line 831 "Gmsh.y"
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
#line 846 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 851 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 86:
#line 856 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 861 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 88:
#line 866 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 89:
#line 875 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 90:
#line 881 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 91:
#line 890 "Gmsh.y"
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
#line 908 "Gmsh.y"
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
#line 926 "Gmsh.y"
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
#line 935 "Gmsh.y"
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
#line 947 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 96:
#line 952 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 97:
#line 960 "Gmsh.y"
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
#line 980 "Gmsh.y"
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
#line 1003 "Gmsh.y"
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
#line 1014 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 101:
#line 1022 "Gmsh.y"
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
#line 1044 "Gmsh.y"
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
#line 1067 "Gmsh.y"
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
#line 1093 "Gmsh.y"
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
#line 1114 "Gmsh.y"
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
#line 1126 "Gmsh.y"
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
#line 1144 "Gmsh.y"
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
#line 1153 "Gmsh.y"
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
#line 1162 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 113:
#line 1164 "Gmsh.y"
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
#line 1180 "Gmsh.y"
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
#line 1189 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 116:
#line 1191 "Gmsh.y"
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
#line 1205 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 119:
#line 1213 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 120:
#line 1219 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 123:
#line 1231 "Gmsh.y"
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
#line 1242 "Gmsh.y"
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
#line 1257 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 128:
#line 1273 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 129:
#line 1281 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 130:
#line 1290 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 131:
#line 1298 "Gmsh.y"
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
#line 1316 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 133:
#line 1320 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 134:
#line 1326 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 135:
#line 1334 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 136:
#line 1338 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 137:
#line 1344 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 138:
#line 1352 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 139:
#line 1356 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 140:
#line 1362 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 141:
#line 1370 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 142:
#line 1374 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 143:
#line 1380 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 144:
#line 1388 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 145:
#line 1392 "Gmsh.y"
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
#line 1404 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 147:
#line 1408 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 148:
#line 1418 "Gmsh.y"
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
#line 1441 "Gmsh.y"
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
#line 1473 "Gmsh.y"
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
#line 1496 "Gmsh.y"
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
#line 1514 "Gmsh.y"
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
#line 1535 "Gmsh.y"
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
#line 1553 "Gmsh.y"
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
#line 1583 "Gmsh.y"
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
#line 1613 "Gmsh.y"
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
#line 1631 "Gmsh.y"
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
#line 1650 "Gmsh.y"
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
#line 1676 "Gmsh.y"
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
#line 1694 "Gmsh.y"
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
#line 1712 "Gmsh.y"
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
#line 1747 "Gmsh.y"
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
#line 1765 "Gmsh.y"
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
#line 1804 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 165:
#line 1810 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 166:
#line 1816 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 167:
#line 1823 "Gmsh.y"
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
#line 1848 "Gmsh.y"
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
#line 1873 "Gmsh.y"
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
#line 1890 "Gmsh.y"
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
#line 1910 "Gmsh.y"
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
#line 1943 "Gmsh.y"
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
#line 1979 "Gmsh.y"
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
#line 1997 "Gmsh.y"
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
#line 2014 "Gmsh.y"
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
#line 2030 "Gmsh.y"
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
#line 2067 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 178:
#line 2072 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 179:
#line 2077 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 180:
#line 2082 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 181:
#line 2087 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 182:
#line 2092 "Gmsh.y"
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
#line 2115 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 184:
#line 2121 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 185:
#line 2131 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 186:
#line 2132 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 187:
#line 2137 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 188:
#line 2141 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 189:
#line 2145 "Gmsh.y"
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
#line 2168 "Gmsh.y"
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
#line 2191 "Gmsh.y"
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
#line 2214 "Gmsh.y"
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
#line 2242 "Gmsh.y"
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
#line 2263 "Gmsh.y"
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
#line 2290 "Gmsh.y"
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
#line 2311 "Gmsh.y"
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
#line 2332 "Gmsh.y"
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
#line 2352 "Gmsh.y"
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
#line 2464 "Gmsh.y"
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
#line 2483 "Gmsh.y"
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
#line 2522 "Gmsh.y"
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
#line 2630 "Gmsh.y"
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
#line 2639 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 204:
#line 2645 "Gmsh.y"
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
#line 2660 "Gmsh.y"
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
#line 2688 "Gmsh.y"
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
#line 2705 "Gmsh.y"
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
#line 2714 "Gmsh.y"
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
#line 2728 "Gmsh.y"
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
#line 2742 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 211:
#line 2748 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 212:
#line 2754 "Gmsh.y"
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
#line 2763 "Gmsh.y"
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
#line 2772 "Gmsh.y"
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
#line 2781 "Gmsh.y"
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
#line 2795 "Gmsh.y"
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
#line 2851 "Gmsh.y"
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
#line 2869 "Gmsh.y"
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
#line 2886 "Gmsh.y"
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
#line 2901 "Gmsh.y"
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
#line 2920 "Gmsh.y"
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
#line 2932 "Gmsh.y"
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
#line 2956 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 224:
#line 2960 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 225:
#line 2965 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 226:
#line 2972 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 227:
#line 2977 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 228:
#line 2983 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 229:
#line 2988 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 230:
#line 2994 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 231:
#line 3002 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 232:
#line 3006 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 233:
#line 3010 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 234:
#line 3016 "Gmsh.y"
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
#line 3070 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    ;}
    break;

  case 236:
#line 3083 "Gmsh.y"
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
#line 3100 "Gmsh.y"
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
#line 3117 "Gmsh.y"
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
#line 3139 "Gmsh.y"
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
#line 3161 "Gmsh.y"
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
#line 3196 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 242:
#line 3204 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 243:
#line 3212 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 244:
#line 3218 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 245:
#line 3225 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 246:
#line 3232 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 247:
#line 3236 "Gmsh.y"
    {
    ;}
    break;

  case 248:
#line 3245 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 249:
#line 3253 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 250:
#line 3261 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 251:
#line 3269 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 252:
#line 3275 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 253:
#line 3283 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 254:
#line 3289 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 255:
#line 3297 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 256:
#line 3303 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 257:
#line 3311 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 258:
#line 3317 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 259:
#line 3325 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 260:
#line 3332 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 261:
#line 3339 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 262:
#line 3346 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 263:
#line 3353 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 264:
#line 3360 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 265:
#line 3367 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 266:
#line 3374 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 267:
#line 3381 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 268:
#line 3388 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 269:
#line 3394 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 270:
#line 3401 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 271:
#line 3407 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 272:
#line 3414 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 273:
#line 3420 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 274:
#line 3427 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 275:
#line 3433 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 276:
#line 3440 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 277:
#line 3446 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 278:
#line 3453 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 279:
#line 3459 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 280:
#line 3466 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 281:
#line 3472 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 282:
#line 3479 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 283:
#line 3485 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 284:
#line 3492 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 285:
#line 3498 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 286:
#line 3509 "Gmsh.y"
    {
    ;}
    break;

  case 287:
#line 3512 "Gmsh.y"
    {
    ;}
    break;

  case 288:
#line 3518 "Gmsh.y"
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

  case 289:
#line 3530 "Gmsh.y"
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

  case 290:
#line 3550 "Gmsh.y"
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

  case 291:
#line 3574 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 292:
#line 3578 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 293:
#line 3582 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 294:
#line 3586 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 295:
#line 3590 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 296:
#line 3596 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 297:
#line 3602 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 298:
#line 3606 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 299:
#line 3610 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 300:
#line 3614 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 301:
#line 3618 "Gmsh.y"
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

  case 302:
#line 3637 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 303:
#line 3649 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 304:
#line 3653 "Gmsh.y"
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

  case 305:
#line 3668 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 306:
#line 3672 "Gmsh.y"
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

  case 307:
#line 3688 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 308:
#line 3692 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 309:
#line 3697 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 310:
#line 3701 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 311:
#line 3707 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 312:
#line 3711 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 313:
#line 3718 "Gmsh.y"
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

  case 314:
#line 3774 "Gmsh.y"
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

  case 315:
#line 3844 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 316:
#line 3849 "Gmsh.y"
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

  case 317:
#line 3916 "Gmsh.y"
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

  case 318:
#line 3952 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 319:
#line 3960 "Gmsh.y"
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

  case 320:
#line 4003 "Gmsh.y"
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

  case 321:
#line 4042 "Gmsh.y"
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

  case 322:
#line 4063 "Gmsh.y"
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

  case 323:
#line 4095 "Gmsh.y"
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
            addPeriodicFace(d_slave,d_master,transfo);
          }
        }
      }
      List_Delete((yyvsp[(4) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
    ;}
    break;

  case 324:
#line 4122 "Gmsh.y"
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

  case 325:
#line 4148 "Gmsh.y"
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
          addPeriodicFace(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[(4) - (18)].l));
      List_Delete((yyvsp[(8) - (18)].l));
    ;}
    break;

  case 326:
#line 4174 "Gmsh.y"
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

  case 327:
#line 4200 "Gmsh.y"
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
          addPeriodicFace(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[(4) - (12)].l));
      List_Delete((yyvsp[(8) - (12)].l));
    ;}
    break;

  case 328:
#line 4226 "Gmsh.y"
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
        addPeriodicFace(j_slave,j_master,edgeCounterParts);
      }
      List_Delete((yyvsp[(5) - (12)].l));
      List_Delete((yyvsp[(10) - (12)].l));
    ;}
    break;

  case 329:
#line 4247 "Gmsh.y"
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

  case 330:
#line 4275 "Gmsh.y"
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

  case 331:
#line 4303 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    ;}
    break;

  case 332:
#line 4307 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 333:
#line 4311 "Gmsh.y"
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

  case 334:
#line 4339 "Gmsh.y"
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

  case 335:
#line 4378 "Gmsh.y"
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

  case 336:
#line 4417 "Gmsh.y"
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

  case 337:
#line 4438 "Gmsh.y"
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

  case 338:
#line 4459 "Gmsh.y"
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

  case 339:
#line 4486 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 340:
#line 4490 "Gmsh.y"
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

  case 341:
#line 4500 "Gmsh.y"
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

  case 342:
#line 4534 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 343:
#line 4535 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 344:
#line 4536 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 345:
#line 4541 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 346:
#line 4547 "Gmsh.y"
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

  case 347:
#line 4559 "Gmsh.y"
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

  case 348:
#line 4577 "Gmsh.y"
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

  case 349:
#line 4604 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 350:
#line 4605 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 351:
#line 4606 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 352:
#line 4607 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 353:
#line 4608 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 354:
#line 4609 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 355:
#line 4610 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 356:
#line 4611 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 357:
#line 4613 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 358:
#line 4619 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 359:
#line 4620 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 360:
#line 4621 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 361:
#line 4622 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 362:
#line 4623 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 363:
#line 4624 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 364:
#line 4625 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 365:
#line 4626 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 366:
#line 4627 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 367:
#line 4628 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 368:
#line 4629 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 369:
#line 4630 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 370:
#line 4631 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 371:
#line 4632 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 372:
#line 4633 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 373:
#line 4634 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 374:
#line 4635 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 375:
#line 4636 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 376:
#line 4637 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 377:
#line 4638 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 378:
#line 4639 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 379:
#line 4640 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 380:
#line 4641 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 381:
#line 4642 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 382:
#line 4643 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 383:
#line 4644 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 384:
#line 4645 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 385:
#line 4646 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 386:
#line 4647 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 387:
#line 4648 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 388:
#line 4649 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 389:
#line 4650 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 390:
#line 4651 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 391:
#line 4660 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 392:
#line 4661 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 393:
#line 4662 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 394:
#line 4663 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 395:
#line 4664 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 396:
#line 4665 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 397:
#line 4666 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 398:
#line 4667 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 399:
#line 4668 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 400:
#line 4669 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 401:
#line 4674 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 402:
#line 4676 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 403:
#line 4682 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 404:
#line 4687 "Gmsh.y"
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

  case 405:
#line 4704 "Gmsh.y"
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

  case 406:
#line 4722 "Gmsh.y"
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

  case 407:
#line 4740 "Gmsh.y"
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
#line 4758 "Gmsh.y"
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
#line 4776 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 410:
#line 4781 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 411:
#line 4787 "Gmsh.y"
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

  case 412:
#line 4799 "Gmsh.y"
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

  case 413:
#line 4816 "Gmsh.y"
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

  case 414:
#line 4834 "Gmsh.y"
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

  case 415:
#line 4852 "Gmsh.y"
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
#line 4870 "Gmsh.y"
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
#line 4891 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 418:
#line 4896 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 419:
#line 4901 "Gmsh.y"
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

  case 420:
#line 4911 "Gmsh.y"
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

  case 421:
#line 4921 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 422:
#line 4926 "Gmsh.y"
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

  case 423:
#line 4937 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 424:
#line 4946 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 425:
#line 4951 "Gmsh.y"
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

  case 426:
#line 4978 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 427:
#line 4982 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 428:
#line 4986 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 429:
#line 4990 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 430:
#line 4994 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 431:
#line 5001 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 432:
#line 5005 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 433:
#line 5009 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 434:
#line 5013 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 435:
#line 5020 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 436:
#line 5025 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 437:
#line 5032 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 438:
#line 5037 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 439:
#line 5041 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 440:
#line 5046 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 441:
#line 5050 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 442:
#line 5058 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 443:
#line 5069 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 444:
#line 5073 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 445:
#line 5085 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 446:
#line 5093 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 447:
#line 5101 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 448:
#line 5108 "Gmsh.y"
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

  case 449:
#line 5118 "Gmsh.y"
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

  case 450:
#line 5147 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 451:
#line 5151 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 452:
#line 5155 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 453:
#line 5159 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 454:
#line 5163 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 455:
#line 5167 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 456:
#line 5171 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 457:
#line 5175 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 458:
#line 5179 "Gmsh.y"
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

  case 459:
#line 5208 "Gmsh.y"
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

  case 460:
#line 5237 "Gmsh.y"
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

  case 461:
#line 5266 "Gmsh.y"
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

  case 462:
#line 5296 "Gmsh.y"
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

  case 463:
#line 5309 "Gmsh.y"
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

  case 464:
#line 5322 "Gmsh.y"
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

  case 465:
#line 5335 "Gmsh.y"
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

  case 466:
#line 5347 "Gmsh.y"
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

  case 467:
#line 5357 "Gmsh.y"
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

  case 468:
#line 5367 "Gmsh.y"
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

  case 469:
#line 5379 "Gmsh.y"
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

  case 470:
#line 5392 "Gmsh.y"
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

  case 471:
#line 5404 "Gmsh.y"
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

  case 472:
#line 5422 "Gmsh.y"
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

  case 473:
#line 5443 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 474:
#line 5448 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 475:
#line 5452 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 476:
#line 5456 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 477:
#line 5468 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 478:
#line 5472 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 479:
#line 5484 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 480:
#line 5491 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 481:
#line 5501 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 482:
#line 5505 "Gmsh.y"
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

  case 483:
#line 5520 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 484:
#line 5525 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 485:
#line 5532 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 486:
#line 5536 "Gmsh.y"
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

  case 487:
#line 5549 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 488:
#line 5557 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 489:
#line 5568 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 490:
#line 5572 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 491:
#line 5576 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 492:
#line 5584 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 493:
#line 5590 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 494:
#line 5596 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 495:
#line 5604 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 496:
#line 5612 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 497:
#line 5619 "Gmsh.y"
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

  case 498:
#line 5634 "Gmsh.y"
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

  case 499:
#line 5648 "Gmsh.y"
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

  case 500:
#line 5662 "Gmsh.y"
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

  case 501:
#line 5674 "Gmsh.y"
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

  case 502:
#line 5690 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 503:
#line 5699 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 504:
#line 5708 "Gmsh.y"
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

  case 505:
#line 5718 "Gmsh.y"
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

  case 506:
#line 5729 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 507:
#line 5733 "Gmsh.y"
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

  case 508:
#line 5752 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 509:
#line 5759 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 510:
#line 5765 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 511:
#line 5767 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 512:
#line 5778 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 513:
#line 5783 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 514:
#line 5789 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 515:
#line 5798 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 516:
#line 5811 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 517:
#line 5814 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 518:
#line 5818 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 11824 "Gmsh.tab.cpp"
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


#line 5821 "Gmsh.y"


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

void addPeriodicFace(int iTarget,int iSource,
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
    target->setMeshMaster(source,affineTransform);
  }
}

void addPeriodicFace(int iTarget,int iSource,
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
    target->setMeshMaster(source,edgeCounterparts);
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
      target->setMeshMaster(source,affineTransform);
    }
    else {
      target->setMeshMaster(source,iSource*iTarget < 0 ? -1:1);
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

