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
     tStrFind = 300,
     tStrCmp = 301,
     tTextAttributes = 302,
     tBoundingBox = 303,
     tDraw = 304,
     tSetChanged = 305,
     tToday = 306,
     tOnelabAction = 307,
     tSyncModel = 308,
     tCpu = 309,
     tMemory = 310,
     tTotalMemory = 311,
     tCreateTopology = 312,
     tCreateTopologyNoHoles = 313,
     tDistanceFunction = 314,
     tDefineConstant = 315,
     tUndefineConstant = 316,
     tPoint = 317,
     tCircle = 318,
     tEllipse = 319,
     tLine = 320,
     tSphere = 321,
     tPolarSphere = 322,
     tSurface = 323,
     tSpline = 324,
     tVolume = 325,
     tCharacteristic = 326,
     tLength = 327,
     tParametric = 328,
     tElliptic = 329,
     tRefineMesh = 330,
     tAdaptMesh = 331,
     tRelocateMesh = 332,
     tPlane = 333,
     tRuled = 334,
     tTransfinite = 335,
     tComplex = 336,
     tPhysical = 337,
     tCompound = 338,
     tPeriodic = 339,
     tUsing = 340,
     tPlugin = 341,
     tDegenerated = 342,
     tRecursive = 343,
     tRotate = 344,
     tTranslate = 345,
     tSymmetry = 346,
     tDilate = 347,
     tExtrude = 348,
     tLevelset = 349,
     tRecombine = 350,
     tSmoother = 351,
     tSplit = 352,
     tDelete = 353,
     tCoherence = 354,
     tIntersect = 355,
     tMeshAlgorithm = 356,
     tReverse = 357,
     tLayers = 358,
     tScaleLast = 359,
     tHole = 360,
     tAlias = 361,
     tAliasWithOptions = 362,
     tCopyOptions = 363,
     tQuadTriAddVerts = 364,
     tQuadTriNoNewVerts = 365,
     tQuadTriSngl = 366,
     tQuadTriDbl = 367,
     tRecombLaterals = 368,
     tTransfQuadTri = 369,
     tText2D = 370,
     tText3D = 371,
     tInterpolationScheme = 372,
     tTime = 373,
     tCombine = 374,
     tBSpline = 375,
     tBezier = 376,
     tNurbs = 377,
     tNurbsOrder = 378,
     tNurbsKnots = 379,
     tColor = 380,
     tColorTable = 381,
     tFor = 382,
     tIn = 383,
     tEndFor = 384,
     tIf = 385,
     tEndIf = 386,
     tExit = 387,
     tAbort = 388,
     tField = 389,
     tReturn = 390,
     tCall = 391,
     tFunction = 392,
     tShow = 393,
     tHide = 394,
     tGetValue = 395,
     tGetEnv = 396,
     tGetString = 397,
     tHomology = 398,
     tCohomology = 399,
     tBetti = 400,
     tSetOrder = 401,
     tExists = 402,
     tGMSH_MAJOR_VERSION = 403,
     tGMSH_MINOR_VERSION = 404,
     tGMSH_PATCH_VERSION = 405,
     tAFFECTDIVIDE = 406,
     tAFFECTTIMES = 407,
     tAFFECTMINUS = 408,
     tAFFECTPLUS = 409,
     tOR = 410,
     tAND = 411,
     tNOTEQUAL = 412,
     tEQUAL = 413,
     tGREATEROREQUAL = 414,
     tLESSOREQUAL = 415,
     UNARYPREC = 416,
     tMINUSMINUS = 417,
     tPLUSPLUS = 418
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
#define tStrFind 300
#define tStrCmp 301
#define tTextAttributes 302
#define tBoundingBox 303
#define tDraw 304
#define tSetChanged 305
#define tToday 306
#define tOnelabAction 307
#define tSyncModel 308
#define tCpu 309
#define tMemory 310
#define tTotalMemory 311
#define tCreateTopology 312
#define tCreateTopologyNoHoles 313
#define tDistanceFunction 314
#define tDefineConstant 315
#define tUndefineConstant 316
#define tPoint 317
#define tCircle 318
#define tEllipse 319
#define tLine 320
#define tSphere 321
#define tPolarSphere 322
#define tSurface 323
#define tSpline 324
#define tVolume 325
#define tCharacteristic 326
#define tLength 327
#define tParametric 328
#define tElliptic 329
#define tRefineMesh 330
#define tAdaptMesh 331
#define tRelocateMesh 332
#define tPlane 333
#define tRuled 334
#define tTransfinite 335
#define tComplex 336
#define tPhysical 337
#define tCompound 338
#define tPeriodic 339
#define tUsing 340
#define tPlugin 341
#define tDegenerated 342
#define tRecursive 343
#define tRotate 344
#define tTranslate 345
#define tSymmetry 346
#define tDilate 347
#define tExtrude 348
#define tLevelset 349
#define tRecombine 350
#define tSmoother 351
#define tSplit 352
#define tDelete 353
#define tCoherence 354
#define tIntersect 355
#define tMeshAlgorithm 356
#define tReverse 357
#define tLayers 358
#define tScaleLast 359
#define tHole 360
#define tAlias 361
#define tAliasWithOptions 362
#define tCopyOptions 363
#define tQuadTriAddVerts 364
#define tQuadTriNoNewVerts 365
#define tQuadTriSngl 366
#define tQuadTriDbl 367
#define tRecombLaterals 368
#define tTransfQuadTri 369
#define tText2D 370
#define tText3D 371
#define tInterpolationScheme 372
#define tTime 373
#define tCombine 374
#define tBSpline 375
#define tBezier 376
#define tNurbs 377
#define tNurbsOrder 378
#define tNurbsKnots 379
#define tColor 380
#define tColorTable 381
#define tFor 382
#define tIn 383
#define tEndFor 384
#define tIf 385
#define tEndIf 386
#define tExit 387
#define tAbort 388
#define tField 389
#define tReturn 390
#define tCall 391
#define tFunction 392
#define tShow 393
#define tHide 394
#define tGetValue 395
#define tGetEnv 396
#define tGetString 397
#define tHomology 398
#define tCohomology 399
#define tBetti 400
#define tSetOrder 401
#define tExists 402
#define tGMSH_MAJOR_VERSION 403
#define tGMSH_MINOR_VERSION 404
#define tGMSH_PATCH_VERSION 405
#define tAFFECTDIVIDE 406
#define tAFFECTTIMES 407
#define tAFFECTMINUS 408
#define tAFFECTPLUS 409
#define tOR 410
#define tAND 411
#define tNOTEQUAL 412
#define tEQUAL 413
#define tGREATEROREQUAL 414
#define tLESSOREQUAL 415
#define UNARYPREC 416
#define tMINUSMINUS 417
#define tPLUSPLUS 418




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

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
static int curPhysDim = 0;
static gmshSurface *myGmshSurface = 0;
#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0;
static fpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static const char *LoopControlVariablesNameTab[MAX_RECUR_LOOPS];
static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;

void yyerror(const char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list);

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
#line 93 "Gmsh.y"
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
#line 532 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 545 "Gmsh.tab.cpp"

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
#define YYLAST   8801

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  184
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  481
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1670

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   418

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   169,     2,   179,     2,   168,     2,     2,
     174,   175,   166,   164,   180,   165,   178,   167,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     160,     2,   161,   155,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   176,     2,   177,   173,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   181,     2,   182,   183,     2,     2,     2,
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
     156,   157,   158,   159,   162,   163,   170,   171,   172
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    47,    53,    59,    67,    75,    83,    93,
     100,   107,   114,   123,   124,   127,   130,   133,   136,   139,
     141,   145,   147,   151,   152,   153,   164,   166,   170,   171,
     185,   187,   191,   192,   208,   217,   232,   233,   240,   242,
     244,   246,   248,   250,   252,   254,   260,   266,   271,   278,
     286,   294,   304,   314,   318,   325,   330,   337,   347,   354,
     364,   370,   379,   388,   400,   407,   417,   423,   431,   441,
     451,   463,   471,   481,   491,   492,   494,   495,   499,   505,
     506,   516,   522,   523,   533,   534,   538,   542,   548,   549,
     552,   556,   562,   566,   567,   570,   574,   578,   584,   586,
     588,   589,   595,   596,   599,   607,   608,   618,   625,   633,
     638,   646,   655,   664,   672,   680,   692,   701,   710,   711,
     721,   730,   740,   744,   749,   760,   768,   776,   785,   794,
     807,   808,   818,   827,   835,   844,   845,   855,   861,   873,
     879,   889,   899,   904,   914,   924,   926,   928,   929,   932,
     939,   946,   953,   960,   969,   980,   995,  1012,  1025,  1034,
    1043,  1050,  1065,  1070,  1077,  1084,  1088,  1093,  1099,  1106,
    1110,  1114,  1119,  1125,  1130,  1136,  1140,  1148,  1156,  1160,
    1168,  1172,  1175,  1178,  1181,  1184,  1200,  1203,  1206,  1209,
    1212,  1215,  1232,  1236,  1243,  1252,  1261,  1272,  1274,  1277,
    1279,  1283,  1288,  1290,  1296,  1308,  1322,  1323,  1331,  1332,
    1346,  1347,  1363,  1364,  1371,  1380,  1389,  1398,  1411,  1424,
    1437,  1452,  1467,  1482,  1483,  1496,  1497,  1510,  1511,  1524,
    1525,  1542,  1543,  1560,  1561,  1578,  1579,  1598,  1599,  1618,
    1619,  1638,  1640,  1643,  1649,  1657,  1667,  1670,  1673,  1676,
    1680,  1683,  1687,  1690,  1694,  1697,  1701,  1711,  1718,  1719,
    1723,  1724,  1726,  1727,  1730,  1731,  1734,  1742,  1749,  1758,
    1764,  1768,  1776,  1782,  1787,  1794,  1801,  1814,  1825,  1836,
    1847,  1858,  1869,  1874,  1879,  1884,  1889,  1894,  1897,  1901,
    1908,  1910,  1912,  1914,  1917,  1923,  1931,  1942,  1944,  1948,
    1951,  1954,  1957,  1961,  1965,  1969,  1973,  1977,  1981,  1985,
    1989,  1993,  1997,  2001,  2005,  2009,  2013,  2019,  2024,  2029,
    2034,  2039,  2044,  2049,  2054,  2059,  2064,  2069,  2076,  2081,
    2086,  2091,  2096,  2101,  2106,  2111,  2118,  2125,  2132,  2137,
    2142,  2147,  2152,  2157,  2162,  2167,  2172,  2177,  2182,  2187,
    2194,  2199,  2204,  2209,  2214,  2219,  2224,  2229,  2236,  2243,
    2250,  2255,  2257,  2259,  2261,  2263,  2265,  2267,  2269,  2271,
    2273,  2275,  2277,  2282,  2287,  2292,  2295,  2301,  2305,  2312,
    2317,  2325,  2332,  2339,  2346,  2351,  2353,  2356,  2359,  2363,
    2367,  2379,  2389,  2397,  2405,  2407,  2411,  2413,  2415,  2418,
    2422,  2427,  2433,  2435,  2437,  2440,  2444,  2448,  2454,  2459,
    2462,  2465,  2468,  2471,  2477,  2483,  2489,  2495,  2497,  2499,
    2503,  2507,  2512,  2519,  2526,  2528,  2530,  2534,  2538,  2548,
    2556,  2558,  2564,  2568,  2575,  2577,  2581,  2583,  2585,  2589,
    2596,  2598,  2600,  2602,  2607,  2614,  2621,  2628,  2633,  2638,
    2647,  2652,  2657,  2662,  2667,  2674,  2681,  2683,  2687,  2693,
    2699,  2701
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     185,     0,    -1,   186,    -1,     1,     6,    -1,    -1,   186,
     187,    -1,   190,    -1,   189,    -1,   208,    -1,   222,    -1,
     227,    -1,   231,    -1,   232,    -1,   233,    -1,   236,    -1,
     256,    -1,   257,    -1,   235,    -1,   234,    -1,   230,    -1,
     259,    -1,   161,    -1,   161,   161,    -1,    37,   174,   272,
     175,     6,    -1,    38,   174,   272,   175,     6,    -1,    37,
     174,   272,   175,   188,   272,     6,    -1,    37,   174,   272,
     180,   268,   175,     6,    -1,    38,   174,   272,   180,   268,
     175,     6,    -1,    37,   174,   272,   180,   268,   175,   188,
     272,     6,    -1,     4,   272,   181,   191,   182,     6,    -1,
     106,     4,   176,   260,   177,     6,    -1,   107,     4,   176,
     260,   177,     6,    -1,   108,     4,   176,   260,   180,   260,
     177,     6,    -1,    -1,   191,   194,    -1,   191,   198,    -1,
     191,   201,    -1,   191,   203,    -1,   191,   204,    -1,   260,
      -1,   192,   180,   260,    -1,   260,    -1,   193,   180,   260,
      -1,    -1,    -1,     4,   195,   174,   192,   175,   196,   181,
     193,   182,     6,    -1,   272,    -1,   197,   180,   272,    -1,
      -1,   115,   174,   260,   180,   260,   180,   260,   175,   199,
     181,   197,   182,     6,    -1,   272,    -1,   200,   180,   272,
      -1,    -1,   116,   174,   260,   180,   260,   180,   260,   180,
     260,   175,   202,   181,   200,   182,     6,    -1,   117,   181,
     264,   182,   181,   264,   182,     6,    -1,   117,   181,   264,
     182,   181,   264,   182,   181,   264,   182,   181,   264,   182,
       6,    -1,    -1,   118,   205,   181,   193,   182,     6,    -1,
       7,    -1,   154,    -1,   153,    -1,   152,    -1,   151,    -1,
     172,    -1,   171,    -1,    60,   176,   210,   177,     6,    -1,
      61,   176,   213,   177,     6,    -1,   276,   206,   265,     6,
      -1,     4,   176,   177,   206,   265,     6,    -1,     4,   176,
     260,   177,   206,   260,     6,    -1,     4,   174,   260,   175,
     206,   260,     6,    -1,     4,   176,   181,   268,   182,   177,
     206,   265,     6,    -1,     4,   174,   181,   268,   182,   175,
     206,   265,     6,    -1,   276,   207,     6,    -1,     4,   176,
     260,   177,   207,     6,    -1,   276,     7,   273,     6,    -1,
       4,   178,     4,     7,   273,     6,    -1,     4,   176,   260,
     177,   178,     4,     7,   273,     6,    -1,     4,   178,     4,
     206,   260,     6,    -1,     4,   176,   260,   177,   178,     4,
     206,   260,     6,    -1,     4,   178,     4,   207,     6,    -1,
       4,   176,   260,   177,   178,     4,   207,     6,    -1,     4,
     178,   125,   178,     4,     7,   269,     6,    -1,     4,   176,
     260,   177,   178,   125,   178,     4,     7,   269,     6,    -1,
       4,   178,   126,     7,   270,     6,    -1,     4,   176,   260,
     177,   178,   126,     7,   270,     6,    -1,     4,   134,     7,
     260,     6,    -1,   134,   176,   260,   177,     7,     4,     6,
      -1,   134,   176,   260,   177,   178,     4,     7,   260,     6,
      -1,   134,   176,   260,   177,   178,     4,     7,   273,     6,
      -1,   134,   176,   260,   177,   178,     4,     7,   181,   268,
     182,     6,    -1,   134,   176,   260,   177,   178,     4,     6,
      -1,    86,   174,     4,   175,   178,     4,     7,   260,     6,
      -1,    86,   174,     4,   175,   178,     4,     7,   273,     6,
      -1,    -1,   180,    -1,    -1,   210,   209,   276,    -1,   210,
     209,   276,     7,   260,    -1,    -1,   210,   209,   276,     7,
     181,   260,   211,   215,   182,    -1,   210,   209,   276,     7,
     273,    -1,    -1,   210,   209,   276,     7,   181,   273,   212,
     217,   182,    -1,    -1,   213,   209,   272,    -1,   260,     7,
     273,    -1,   214,   180,   260,     7,   273,    -1,    -1,   215,
     216,    -1,   180,     4,   265,    -1,   180,     4,   181,   214,
     182,    -1,   180,     4,   273,    -1,    -1,   217,   218,    -1,
     180,     4,   260,    -1,   180,     4,   273,    -1,   180,     4,
     181,   274,   182,    -1,   260,    -1,   273,    -1,    -1,   128,
      66,   181,   260,   182,    -1,    -1,    78,   262,    -1,    62,
     174,   260,   175,     7,   262,     6,    -1,    -1,    82,    62,
     223,   174,   219,   175,     7,   265,     6,    -1,    71,    72,
     265,     7,   260,     6,    -1,    65,   174,   260,   175,     7,
     265,     6,    -1,    87,    65,   265,     6,    -1,    69,   174,
     260,   175,     7,   265,     6,    -1,    63,   174,   260,   175,
       7,   265,   221,     6,    -1,    64,   174,   260,   175,     7,
     265,   221,     6,    -1,   120,   174,   260,   175,     7,   265,
       6,    -1,   121,   174,   260,   175,     7,   265,     6,    -1,
     122,   174,   260,   175,     7,   265,   124,   265,   123,   260,
       6,    -1,    65,     4,   174,   260,   175,     7,   265,     6,
      -1,    83,    65,   174,   260,   175,     7,   265,     6,    -1,
      -1,    82,    65,   224,   174,   219,   175,     7,   265,     6,
      -1,    78,    68,   174,   260,   175,     7,   265,     6,    -1,
      79,    68,   174,   260,   175,     7,   265,   220,     6,    -1,
      12,    13,     6,    -1,    13,    68,   260,     6,    -1,    73,
      68,   174,   260,   175,     7,     5,     5,     5,     6,    -1,
      66,   174,   260,   175,     7,   265,     6,    -1,    67,   174,
     260,   175,     7,   265,     6,    -1,    68,     4,   174,   260,
     175,     7,   265,     6,    -1,    83,    68,   174,   260,   175,
       7,   265,     6,    -1,    83,    68,   174,   260,   175,     7,
     265,     4,   181,   264,   182,     6,    -1,    -1,    82,    68,
     225,   174,   219,   175,     7,   265,     6,    -1,    81,    70,
     174,   260,   175,     7,   265,     6,    -1,    70,   174,   260,
     175,     7,   265,     6,    -1,    83,    70,   174,   260,   175,
       7,   265,     6,    -1,    -1,    82,    70,   226,   174,   219,
     175,     7,   265,     6,    -1,    90,   262,   181,   228,   182,
      -1,    89,   181,   262,   180,   262,   180,   260,   182,   181,
     228,   182,    -1,    91,   262,   181,   228,   182,    -1,    92,
     181,   262,   180,   260,   182,   181,   228,   182,    -1,    92,
     181,   262,   180,   262,   182,   181,   228,   182,    -1,     4,
     181,   228,   182,    -1,   100,    65,   181,   268,   182,    68,
     181,   260,   182,    -1,    97,    65,   174,   260,   175,   181,
     268,   182,     6,    -1,   229,    -1,   227,    -1,    -1,   229,
     222,    -1,   229,    62,   181,   268,   182,     6,    -1,   229,
      65,   181,   268,   182,     6,    -1,   229,    68,   181,   268,
     182,     6,    -1,   229,    70,   181,   268,   182,     6,    -1,
      94,    78,   174,   260,   175,     7,   265,     6,    -1,    94,
      62,   174,   260,   175,     7,   181,   264,   182,     6,    -1,
      94,    78,   174,   260,   175,     7,   181,   262,   180,   262,
     180,   268,   182,     6,    -1,    94,    78,   174,   260,   175,
       7,   181,   262,   180,   262,   180,   262,   180,   268,   182,
       6,    -1,    94,    66,   174,   260,   175,     7,   181,   262,
     180,   268,   182,     6,    -1,    94,     4,   174,   260,   175,
       7,   265,     6,    -1,    94,     4,   174,   260,   175,     7,
       5,     6,    -1,    94,     4,   181,   260,   182,     6,    -1,
      94,     4,   174,   260,   175,     7,   181,   262,   180,   262,
     180,   268,   182,     6,    -1,    98,   181,   229,   182,    -1,
      98,   134,   176,   260,   177,     6,    -1,    98,     4,   176,
     260,   177,     6,    -1,    98,     4,     6,    -1,    98,     4,
       4,     6,    -1,   125,   269,   181,   229,   182,    -1,    88,
     125,   269,   181,   229,   182,    -1,   138,     5,     6,    -1,
     139,     5,     6,    -1,   138,   181,   229,   182,    -1,    88,
     138,   181,   229,   182,    -1,   139,   181,   229,   182,    -1,
      88,   139,   181,   229,   182,    -1,     4,   273,     6,    -1,
       4,     4,   176,   260,   177,   272,     6,    -1,     4,     4,
       4,   176,   260,   177,     6,    -1,     4,   260,     6,    -1,
      86,   174,     4,   175,   178,     4,     6,    -1,   119,     4,
       6,    -1,   132,     6,    -1,   133,     6,    -1,    53,     6,
      -1,    48,     6,    -1,    48,   181,   260,   180,   260,   180,
     260,   180,   260,   180,   260,   180,   260,   182,     6,    -1,
      49,     6,    -1,    50,     6,    -1,    57,     6,    -1,    58,
       6,    -1,    75,     6,    -1,    76,   181,   268,   182,   181,
     268,   182,   181,   264,   182,   181,   260,   180,   260,   182,
       6,    -1,   146,   260,     6,    -1,   127,   174,   260,     8,
     260,   175,    -1,   127,   174,   260,     8,   260,     8,   260,
     175,    -1,   127,     4,   128,   181,   260,     8,   260,   182,
      -1,   127,     4,   128,   181,   260,     8,   260,     8,   260,
     182,    -1,   129,    -1,   137,     4,    -1,   135,    -1,   136,
       4,     6,    -1,   130,   174,   260,   175,    -1,   131,    -1,
      93,   262,   181,   229,   182,    -1,    93,   181,   262,   180,
     262,   180,   260,   182,   181,   229,   182,    -1,    93,   181,
     262,   180,   262,   180,   262,   180,   260,   182,   181,   229,
     182,    -1,    -1,    93,   262,   181,   229,   237,   250,   182,
      -1,    -1,    93,   181,   262,   180,   262,   180,   260,   182,
     181,   229,   238,   250,   182,    -1,    -1,    93,   181,   262,
     180,   262,   180,   262,   180,   260,   182,   181,   229,   239,
     250,   182,    -1,    -1,    93,   181,   229,   240,   250,   182,
      -1,    93,    62,   181,   260,   180,   262,   182,     6,    -1,
      93,    65,   181,   260,   180,   262,   182,     6,    -1,    93,
      68,   181,   260,   180,   262,   182,     6,    -1,    93,    62,
     181,   260,   180,   262,   180,   262,   180,   260,   182,     6,
      -1,    93,    65,   181,   260,   180,   262,   180,   262,   180,
     260,   182,     6,    -1,    93,    68,   181,   260,   180,   262,
     180,   262,   180,   260,   182,     6,    -1,    93,    62,   181,
     260,   180,   262,   180,   262,   180,   262,   180,   260,   182,
       6,    -1,    93,    65,   181,   260,   180,   262,   180,   262,
     180,   262,   180,   260,   182,     6,    -1,    93,    68,   181,
     260,   180,   262,   180,   262,   180,   262,   180,   260,   182,
       6,    -1,    -1,    93,    62,   181,   260,   180,   262,   182,
     241,   181,   250,   182,     6,    -1,    -1,    93,    65,   181,
     260,   180,   262,   182,   242,   181,   250,   182,     6,    -1,
      -1,    93,    68,   181,   260,   180,   262,   182,   243,   181,
     250,   182,     6,    -1,    -1,    93,    62,   181,   260,   180,
     262,   180,   262,   180,   260,   182,   244,   181,   250,   182,
       6,    -1,    -1,    93,    65,   181,   260,   180,   262,   180,
     262,   180,   260,   182,   245,   181,   250,   182,     6,    -1,
      -1,    93,    68,   181,   260,   180,   262,   180,   262,   180,
     260,   182,   246,   181,   250,   182,     6,    -1,    -1,    93,
      62,   181,   260,   180,   262,   180,   262,   180,   262,   180,
     260,   182,   247,   181,   250,   182,     6,    -1,    -1,    93,
      65,   181,   260,   180,   262,   180,   262,   180,   262,   180,
     260,   182,   248,   181,   250,   182,     6,    -1,    -1,    93,
      68,   181,   260,   180,   262,   180,   262,   180,   262,   180,
     260,   182,   249,   181,   250,   182,     6,    -1,   251,    -1,
     250,   251,    -1,   103,   181,   260,   182,     6,    -1,   103,
     181,   265,   180,   265,   182,     6,    -1,   103,   181,   265,
     180,   265,   180,   265,   182,     6,    -1,   104,     6,    -1,
      95,     6,    -1,   111,     6,    -1,   111,   113,     6,    -1,
     112,     6,    -1,   112,   113,     6,    -1,   109,     6,    -1,
     109,   113,     6,    -1,   110,     6,    -1,   110,   113,     6,
      -1,   105,   174,   260,   175,     7,   265,    85,   260,     6,
      -1,    85,     4,   176,   260,   177,     6,    -1,    -1,    85,
       4,   260,    -1,    -1,     4,    -1,    -1,     7,   265,    -1,
      -1,     7,   260,    -1,    80,    65,   266,     7,   260,   252,
       6,    -1,    80,    68,   266,   254,   253,     6,    -1,    74,
      68,   181,   260,   182,     7,   265,     6,    -1,    80,    70,
     266,   254,     6,    -1,   114,   266,     6,    -1,   101,    68,
     181,   268,   182,   260,     6,    -1,    95,    68,   266,   255,
       6,    -1,    95,    70,   266,     6,    -1,    96,    68,   265,
       7,   260,     6,    -1,    84,    65,   265,     7,   265,     6,
      -1,    84,    68,   260,   181,   268,   182,     7,   260,   181,
     268,   182,     6,    -1,    62,   181,   268,   182,   128,    68,
     181,   260,   182,     6,    -1,    65,   181,   268,   182,   128,
      68,   181,   260,   182,     6,    -1,    62,   181,   268,   182,
     128,    70,   181,   260,   182,     6,    -1,    65,   181,   268,
     182,   128,    70,   181,   260,   182,     6,    -1,    68,   181,
     268,   182,   128,    70,   181,   260,   182,     6,    -1,   102,
      68,   266,     6,    -1,   102,    65,   266,     6,    -1,    77,
      62,   266,     6,    -1,    77,    65,   266,     6,    -1,    77,
      68,   266,     6,    -1,    99,     6,    -1,    99,     4,     6,
      -1,    99,    62,   181,   268,   182,     6,    -1,   143,    -1,
     144,    -1,   145,    -1,   258,     6,    -1,   258,   181,   265,
     182,     6,    -1,   258,   181,   265,   180,   265,   182,     6,
      -1,   258,   174,   265,   175,   181,   265,   180,   265,   182,
       6,    -1,   261,    -1,   174,   260,   175,    -1,   165,   260,
      -1,   164,   260,    -1,   169,   260,    -1,   260,   165,   260,
      -1,   260,   164,   260,    -1,   260,   166,   260,    -1,   260,
     167,   260,    -1,   260,   168,   260,    -1,   260,   173,   260,
      -1,   260,   160,   260,    -1,   260,   161,   260,    -1,   260,
     163,   260,    -1,   260,   162,   260,    -1,   260,   159,   260,
      -1,   260,   158,   260,    -1,   260,   157,   260,    -1,   260,
     156,   260,    -1,   260,   155,   260,     8,   260,    -1,    14,
     174,   260,   175,    -1,    15,   174,   260,   175,    -1,    16,
     174,   260,   175,    -1,    17,   174,   260,   175,    -1,    18,
     174,   260,   175,    -1,    19,   174,   260,   175,    -1,    20,
     174,   260,   175,    -1,    21,   174,   260,   175,    -1,    22,
     174,   260,   175,    -1,    24,   174,   260,   175,    -1,    25,
     174,   260,   180,   260,   175,    -1,    26,   174,   260,   175,
      -1,    27,   174,   260,   175,    -1,    28,   174,   260,   175,
      -1,    29,   174,   260,   175,    -1,    30,   174,   260,   175,
      -1,    31,   174,   260,   175,    -1,    32,   174,   260,   175,
      -1,    33,   174,   260,   180,   260,   175,    -1,    34,   174,
     260,   180,   260,   175,    -1,    35,   174,   260,   180,   260,
     175,    -1,    23,   174,   260,   175,    -1,    14,   176,   260,
     177,    -1,    15,   176,   260,   177,    -1,    16,   176,   260,
     177,    -1,    17,   176,   260,   177,    -1,    18,   176,   260,
     177,    -1,    19,   176,   260,   177,    -1,    20,   176,   260,
     177,    -1,    21,   176,   260,   177,    -1,    22,   176,   260,
     177,    -1,    24,   176,   260,   177,    -1,    25,   176,   260,
     180,   260,   177,    -1,    26,   176,   260,   177,    -1,    27,
     176,   260,   177,    -1,    28,   176,   260,   177,    -1,    29,
     176,   260,   177,    -1,    30,   176,   260,   177,    -1,    31,
     176,   260,   177,    -1,    32,   176,   260,   177,    -1,    33,
     176,   260,   180,   260,   177,    -1,    34,   176,   260,   180,
     260,   177,    -1,    35,   176,   260,   180,   260,   177,    -1,
      23,   176,   260,   177,    -1,     3,    -1,     9,    -1,    10,
      -1,    11,    -1,   148,    -1,   149,    -1,   150,    -1,    54,
      -1,    55,    -1,    56,    -1,   276,    -1,     4,   176,   260,
     177,    -1,   147,   174,   276,   175,    -1,   179,     4,   176,
     177,    -1,   276,   207,    -1,     4,   176,   260,   177,   207,
      -1,     4,   178,     4,    -1,     4,   176,   260,   177,   178,
       4,    -1,     4,   178,     4,   207,    -1,     4,   176,   260,
     177,   178,     4,   207,    -1,   140,   174,   272,   180,   260,
     175,    -1,    45,   174,   272,   180,   272,   175,    -1,    46,
     174,   272,   180,   272,   175,    -1,    47,   174,   274,   175,
      -1,   263,    -1,   165,   262,    -1,   164,   262,    -1,   262,
     165,   262,    -1,   262,   164,   262,    -1,   181,   260,   180,
     260,   180,   260,   180,   260,   180,   260,   182,    -1,   181,
     260,   180,   260,   180,   260,   180,   260,   182,    -1,   181,
     260,   180,   260,   180,   260,   182,    -1,   174,   260,   180,
     260,   180,   260,   175,    -1,   265,    -1,   264,   180,   265,
      -1,   260,    -1,   267,    -1,   181,   182,    -1,   181,   268,
     182,    -1,   165,   181,   268,   182,    -1,   260,   166,   181,
     268,   182,    -1,   265,    -1,     5,    -1,   165,   267,    -1,
     260,   166,   267,    -1,   260,     8,   260,    -1,   260,     8,
     260,     8,   260,    -1,    62,   181,   260,   182,    -1,    62,
       5,    -1,    65,     5,    -1,    68,     5,    -1,    70,     5,
      -1,    82,    62,   181,   268,   182,    -1,    82,    65,   181,
     268,   182,    -1,    82,    68,   181,   268,   182,    -1,    82,
      70,   181,   268,   182,    -1,   227,    -1,   236,    -1,     4,
     176,   177,    -1,     4,   174,   175,    -1,    36,   176,     4,
     177,    -1,     4,   176,   181,   268,   182,   177,    -1,     4,
     174,   181,   268,   182,   175,    -1,   260,    -1,   267,    -1,
     268,   180,   260,    -1,   268,   180,   267,    -1,   181,   260,
     180,   260,   180,   260,   180,   260,   182,    -1,   181,   260,
     180,   260,   180,   260,   182,    -1,     4,    -1,     4,   178,
     125,   178,     4,    -1,   181,   271,   182,    -1,     4,   176,
     260,   177,   178,   126,    -1,   269,    -1,   271,   180,   269,
      -1,   273,    -1,   276,    -1,     4,   178,     4,    -1,     4,
     176,   260,   177,   178,     4,    -1,     5,    -1,    51,    -1,
      52,    -1,   141,   174,   272,   175,    -1,   142,   174,   272,
     180,   272,   175,    -1,    41,   174,   272,   180,   272,   175,
      -1,    41,   176,   272,   180,   272,   177,    -1,    42,   174,
     272,   175,    -1,    43,   174,   272,   175,    -1,    44,   174,
     272,   180,   272,   180,   272,   175,    -1,    39,   174,   274,
     175,    -1,    39,   176,   274,   177,    -1,    40,   174,   272,
     175,    -1,    40,   176,   272,   177,    -1,    40,   174,   272,
     180,   268,   175,    -1,    40,   176,   272,   180,   268,   177,
      -1,   272,    -1,   274,   180,   272,    -1,     4,   183,   181,
     260,   182,    -1,   275,   183,   181,   260,   182,    -1,     4,
      -1,   275,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   173,   173,   174,   179,   181,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   203,   207,   214,   219,   224,   238,   251,   264,   292,
     306,   319,   332,   351,   356,   357,   358,   359,   360,   364,
     366,   371,   373,   379,   483,   378,   501,   508,   519,   518,
     536,   543,   554,   553,   570,   587,   610,   609,   623,   624,
     625,   626,   627,   631,   632,   638,   640,   642,   704,   734,
     769,   803,   851,   898,   913,   929,   938,   944,   953,   971,
     989,   998,  1010,  1015,  1023,  1043,  1066,  1077,  1085,  1107,
    1130,  1156,  1177,  1189,  1203,  1203,  1205,  1207,  1216,  1226,
    1225,  1237,  1247,  1246,  1260,  1262,  1270,  1276,  1283,  1284,
    1288,  1299,  1314,  1324,  1325,  1330,  1338,  1347,  1365,  1369,
    1380,  1383,  1396,  1399,  1409,  1433,  1432,  1452,  1474,  1492,
    1513,  1531,  1561,  1591,  1609,  1627,  1653,  1671,  1690,  1689,
    1712,  1730,  1769,  1775,  1781,  1788,  1813,  1838,  1855,  1874,
    1909,  1908,  1932,  1950,  1967,  1984,  1983,  2009,  2014,  2019,
    2024,  2029,  2034,  2057,  2063,  2074,  2075,  2080,  2083,  2087,
    2110,  2133,  2156,  2184,  2205,  2231,  2252,  2274,  2294,  2406,
    2425,  2463,  2572,  2581,  2587,  2602,  2630,  2647,  2656,  2670,
    2676,  2682,  2691,  2700,  2709,  2723,  2776,  2793,  2808,  2827,
    2839,  2863,  2867,  2872,  2879,  2885,  2890,  2896,  2904,  2908,
    2912,  2917,  2972,  2985,  3002,  3019,  3040,  3061,  3096,  3104,
    3110,  3117,  3121,  3130,  3138,  3146,  3155,  3154,  3169,  3168,
    3183,  3182,  3197,  3196,  3210,  3217,  3224,  3231,  3238,  3245,
    3252,  3259,  3266,  3274,  3273,  3287,  3286,  3300,  3299,  3313,
    3312,  3326,  3325,  3339,  3338,  3352,  3351,  3365,  3364,  3378,
    3377,  3394,  3397,  3403,  3415,  3435,  3459,  3464,  3468,  3472,
    3476,  3480,  3484,  3488,  3492,  3496,  3500,  3519,  3532,  3535,
    3551,  3554,  3571,  3574,  3580,  3583,  3590,  3646,  3716,  3721,
    3788,  3824,  3832,  3875,  3914,  3934,  3961,  4001,  4024,  4047,
    4051,  4055,  4078,  4117,  4156,  4177,  4198,  4225,  4229,  4239,
    4274,  4275,  4276,  4280,  4286,  4298,  4316,  4344,  4345,  4346,
    4347,  4348,  4349,  4350,  4351,  4352,  4359,  4360,  4361,  4362,
    4363,  4364,  4365,  4366,  4367,  4368,  4369,  4370,  4371,  4372,
    4373,  4374,  4375,  4376,  4377,  4378,  4379,  4380,  4381,  4382,
    4383,  4384,  4385,  4386,  4387,  4388,  4389,  4390,  4391,  4394,
    4395,  4396,  4397,  4398,  4399,  4400,  4401,  4402,  4403,  4404,
    4405,  4406,  4407,  4408,  4409,  4410,  4411,  4412,  4413,  4414,
    4415,  4424,  4425,  4426,  4427,  4428,  4429,  4430,  4431,  4432,
    4433,  4437,  4454,  4472,  4477,  4489,  4506,  4527,  4532,  4537,
    4547,  4557,  4562,  4571,  4576,  4603,  4607,  4611,  4615,  4619,
    4626,  4630,  4634,  4638,  4645,  4650,  4657,  4662,  4666,  4671,
    4675,  4683,  4694,  4698,  4710,  4718,  4726,  4733,  4743,  4763,
    4767,  4771,  4775,  4779,  4808,  4837,  4866,  4895,  4905,  4915,
    4928,  4940,  4952,  4971,  4992,  4997,  5001,  5005,  5017,  5021,
    5033,  5040,  5050,  5054,  5069,  5074,  5081,  5085,  5098,  5106,
    5117,  5121,  5129,  5135,  5143,  5151,  5160,  5168,  5182,  5196,
    5208,  5225,  5241,  5246,  5250,  5270,  5292,  5297,  5303,  5312,
    5325,  5328
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
  "tStrPrefix", "tStrRelative", "tStrReplace", "tStrFind", "tStrCmp",
  "tTextAttributes", "tBoundingBox", "tDraw", "tSetChanged", "tToday",
  "tOnelabAction", "tSyncModel", "tCpu", "tMemory", "tTotalMemory",
  "tCreateTopology", "tCreateTopologyNoHoles", "tDistanceFunction",
  "tDefineConstant", "tUndefineConstant", "tPoint", "tCircle", "tEllipse",
  "tLine", "tSphere", "tPolarSphere", "tSurface", "tSpline", "tVolume",
  "tCharacteristic", "tLength", "tParametric", "tElliptic", "tRefineMesh",
  "tAdaptMesh", "tRelocateMesh", "tPlane", "tRuled", "tTransfinite",
  "tComplex", "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
  "tDegenerated", "tRecursive", "tRotate", "tTranslate", "tSymmetry",
  "tDilate", "tExtrude", "tLevelset", "tRecombine", "tSmoother", "tSplit",
  "tDelete", "tCoherence", "tIntersect", "tMeshAlgorithm", "tReverse",
  "tLayers", "tScaleLast", "tHole", "tAlias", "tAliasWithOptions",
  "tCopyOptions", "tQuadTriAddVerts", "tQuadTriNoNewVerts", "tQuadTriSngl",
  "tQuadTriDbl", "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tEndIf", "tExit", "tAbort", "tField",
  "tReturn", "tCall", "tFunction", "tShow", "tHide", "tGetValue",
  "tGetEnv", "tGetString", "tHomology", "tCohomology", "tBetti",
  "tSetOrder", "tExists", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION",
  "tGMSH_PATCH_VERSION", "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS",
  "tAFFECTPLUS", "'?'", "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'",
  "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'",
  "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All",
  "GeoFormatItems", "GeoFormatItem", "SendToFile", "Printf", "View",
  "Views", "ElementCoords", "ElementValues", "Element", "@1", "@2",
  "Text2DValues", "Text2D", "@3", "Text3DValues", "Text3D", "@4",
  "InterpolationMatrix", "Time", "@5", "NumericAffectation",
  "NumericIncrement", "Affectation", "Comma", "DefineConstants", "@6",
  "@7", "UndefineConstants", "Enumeration", "FloatParameterOptions",
  "FloatParameterOption", "CharParameterOptions", "CharParameterOption",
  "PhysicalId", "InSphereCenter", "CircleOptions", "Shape", "@8", "@9",
  "@10", "@11", "Transform", "MultipleShape", "ListOfShapes", "LevelSet",
  "Delete", "Colorify", "Visibility", "Command", "Loop", "Extrude", "@12",
  "@13", "@14", "@15", "@16", "@17", "@18", "@19", "@20", "@21", "@22",
  "@23", "@24", "ExtrudeParameters", "ExtrudeParameter", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "Constraints", "Coherence", "HomologyCommand", "Homology", "FExpr",
  "FExpr_Single", "VExpr", "VExpr_Single", "RecursiveListOfListOfDouble",
  "ListOfDouble", "ListOfDoubleOrAll", "FExpr_Multi",
  "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr",
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
     405,   406,   407,   408,   409,    63,   410,   411,   412,   413,
      60,    62,   414,   415,    43,    45,    42,    47,    37,    33,
     416,   417,   418,    94,    40,    41,    91,    93,    46,    35,
      44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   184,   185,   185,   186,   186,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   188,   188,   189,   189,   189,   189,   189,   189,   190,
     190,   190,   190,   191,   191,   191,   191,   191,   191,   192,
     192,   193,   193,   195,   196,   194,   197,   197,   199,   198,
     200,   200,   202,   201,   203,   203,   205,   204,   206,   206,
     206,   206,   206,   207,   207,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   209,   209,   210,   210,   210,   211,
     210,   210,   212,   210,   213,   213,   214,   214,   215,   215,
     216,   216,   216,   217,   217,   218,   218,   218,   219,   219,
     220,   220,   221,   221,   222,   223,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   224,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     225,   222,   222,   222,   222,   226,   222,   227,   227,   227,
     227,   227,   227,   227,   227,   228,   228,   229,   229,   229,
     229,   229,   229,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   231,   231,   231,   231,   231,   232,   232,   233,
     233,   233,   233,   233,   233,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   236,   236,   236,   237,   236,   238,   236,
     239,   236,   240,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   241,   236,   242,   236,   243,   236,   244,
     236,   245,   236,   246,   236,   247,   236,   248,   236,   249,
     236,   250,   250,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   252,   252,
     253,   253,   254,   254,   255,   255,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   257,   257,   257,
     258,   258,   258,   259,   259,   259,   259,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   262,   262,   262,   262,   262,
     263,   263,   263,   263,   264,   264,   265,   265,   265,   265,
     265,   265,   266,   266,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   268,   268,   268,   268,   269,   269,
     269,   269,   270,   270,   271,   271,   272,   272,   272,   272,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   274,   274,   275,   275,
     276,   276
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     5,     7,     7,     7,     9,     6,
       6,     6,     8,     0,     2,     2,     2,     2,     2,     1,
       3,     1,     3,     0,     0,    10,     1,     3,     0,    13,
       1,     3,     0,    15,     8,    14,     0,     6,     1,     1,
       1,     1,     1,     1,     1,     5,     5,     4,     6,     7,
       7,     9,     9,     3,     6,     4,     6,     9,     6,     9,
       5,     8,     8,    11,     6,     9,     5,     7,     9,     9,
      11,     7,     9,     9,     0,     1,     0,     3,     5,     0,
       9,     5,     0,     9,     0,     3,     3,     5,     0,     2,
       3,     5,     3,     0,     2,     3,     3,     5,     1,     1,
       0,     5,     0,     2,     7,     0,     9,     6,     7,     4,
       7,     8,     8,     7,     7,    11,     8,     8,     0,     9,
       8,     9,     3,     4,    10,     7,     7,     8,     8,    12,
       0,     9,     8,     7,     8,     0,     9,     5,    11,     5,
       9,     9,     4,     9,     9,     1,     1,     0,     2,     6,
       6,     6,     6,     8,    10,    14,    16,    12,     8,     8,
       6,    14,     4,     6,     6,     3,     4,     5,     6,     3,
       3,     4,     5,     4,     5,     3,     7,     7,     3,     7,
       3,     2,     2,     2,     2,    15,     2,     2,     2,     2,
       2,    16,     3,     6,     8,     8,    10,     1,     2,     1,
       3,     4,     1,     5,    11,    13,     0,     7,     0,    13,
       0,    15,     0,     6,     8,     8,     8,    12,    12,    12,
      14,    14,    14,     0,    12,     0,    12,     0,    12,     0,
      16,     0,    16,     0,    16,     0,    18,     0,    18,     0,
      18,     1,     2,     5,     7,     9,     2,     2,     2,     3,
       2,     3,     2,     3,     2,     3,     9,     6,     0,     3,
       0,     1,     0,     2,     0,     2,     7,     6,     8,     5,
       3,     7,     5,     4,     6,     6,    12,    10,    10,    10,
      10,    10,     4,     4,     4,     4,     4,     2,     3,     6,
       1,     1,     1,     2,     5,     7,    10,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     2,     5,     3,     6,     4,
       7,     6,     6,     6,     4,     1,     2,     2,     3,     3,
      11,     9,     7,     7,     1,     3,     1,     1,     2,     3,
       4,     5,     1,     1,     2,     3,     3,     5,     4,     2,
       2,     2,     2,     5,     5,     5,     5,     1,     1,     3,
       3,     4,     6,     6,     1,     1,     3,     3,     9,     7,
       1,     5,     3,     6,     1,     3,     1,     1,     3,     6,
       1,     1,     1,     4,     6,     6,     6,     4,     4,     8,
       4,     4,     4,     4,     6,     6,     1,     3,     5,     5,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   217,     0,
     222,     0,     0,     0,   219,     0,     0,     0,     0,   310,
     311,   312,     0,     5,     7,     6,     8,     9,    10,    19,
      11,    12,    13,    18,    17,    14,    15,    16,     0,    20,
     481,     0,   381,   480,   460,   382,   383,   384,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   461,
     462,   388,   389,   390,     0,     0,     0,     0,     0,   385,
     386,   387,     0,     0,     0,     0,     0,     0,     0,   167,
       0,     0,   317,     0,   456,   391,     0,     0,     0,     0,
     204,     0,   206,   207,   203,   208,   209,    96,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   210,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,   138,   150,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   405,     0,     0,     0,
       0,     0,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,     0,   307,     0,     0,     0,
       0,     0,     0,     0,     0,   480,   423,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   437,   438,   416,   422,
       0,   417,   391,     0,     0,     0,     0,   450,     0,     0,
       0,     0,     0,   201,   202,     0,     0,   218,     0,   167,
       0,   167,   480,     0,   313,     0,     0,     0,    58,    62,
      61,    60,    59,    64,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   320,   319,   321,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   166,     0,   165,     0,   198,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,   195,   395,   142,     0,   480,
       0,   456,   457,     0,     0,    94,    94,     0,     0,   444,
     445,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   282,   282,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   167,
       0,   407,   406,     0,     0,     0,     0,   167,   167,     0,
       0,     0,     0,     0,     0,     0,   232,     0,   167,     0,
       0,     0,     0,     0,   284,     0,     0,     0,     0,   185,
       0,     0,     0,   308,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   429,     0,   430,   431,
     432,     0,     0,     0,     0,     0,   319,   424,     0,   418,
       0,     0,     0,   290,   200,     0,     0,     0,     0,     0,
     167,     0,     0,     0,     0,   220,   189,     0,   190,     0,
       0,   212,     0,     0,     0,     0,     0,    73,     0,     0,
     397,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,     0,     0,   318,    58,     0,     0,     0,
      58,     0,     0,     0,     0,     0,   162,     0,     0,     0,
       0,   168,     0,     0,   335,   334,   333,   332,   328,   329,
     331,   330,   323,   322,   324,   325,   326,   327,     0,   143,
       0,     0,     0,     0,     0,     0,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   304,   305,   306,     0,     0,     0,     0,   280,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   167,     0,     0,     0,     0,     0,   409,   408,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   226,
       0,     0,     0,     0,     0,     0,     0,   293,     0,     0,
     186,     0,     0,   182,     0,     0,     0,   303,   302,     0,
       0,     0,   440,     0,   439,     0,     0,   397,     0,     0,
       0,     0,     0,     0,     0,   318,   419,   426,     0,   324,
     425,     0,     0,     0,     0,     0,     0,     0,     0,   221,
       0,   191,   193,     0,     0,     0,     0,    75,    67,     0,
     392,   399,   337,   359,   338,   360,   339,   361,   340,   362,
     341,   363,   342,   364,   343,   365,   344,   366,   345,   367,
     358,   380,   346,   368,     0,     0,   348,   370,   349,   371,
     350,   372,   351,   373,   352,   374,   353,   375,   354,   376,
       0,     0,     0,     0,     0,     0,   470,     0,   471,   472,
       0,   473,     0,     0,     0,   467,   468,     0,     0,     0,
     404,    86,     0,   463,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
     394,     0,     0,     0,     0,   478,     0,    43,     0,     0,
       0,    56,     0,    34,    35,    36,    37,    38,     0,   458,
      23,    21,     0,     0,    24,     0,     0,    65,    97,    66,
     105,     0,   446,   447,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,   283,   281,     0,   289,     0,     0,   118,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   192,   194,     0,     0,     0,   157,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   261,     0,   223,     0,     0,     0,     0,
       0,     0,   285,   292,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   392,   441,   428,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
       0,   187,     0,     0,     0,     0,     0,     0,   314,   479,
       0,     0,   396,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   477,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,     0,     0,     0,     0,     0,
      74,    76,    78,     0,     0,   454,     0,    84,     0,     0,
       0,     0,   336,     0,     0,     0,     0,     0,    29,     0,
      22,     0,     0,     0,     0,     0,     0,     0,     0,   122,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,   287,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,   188,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   267,     0,   266,     0,   272,     0,   274,     0,   268,
       0,   270,     0,   233,   262,     0,     0,     0,   180,     0,
       0,     0,   294,     0,   184,   183,   309,     0,     0,    30,
      31,     0,     0,     0,     0,   433,   434,   435,   436,   427,
     421,     0,     0,     0,   451,     0,     0,     0,   213,     0,
       0,     0,     0,   197,   398,   196,   347,   369,   355,   377,
     356,   378,   357,   379,   474,   475,   465,   466,     0,   402,
     403,   401,   464,     0,    70,     0,    58,     0,     0,     0,
       0,    69,     0,     0,     0,   452,     0,     0,     0,     0,
       0,     0,     0,     0,   414,     0,     0,    25,    26,     0,
      27,     0,     0,    98,   101,   124,     0,     0,     0,     0,
       0,     0,   128,     0,     0,   145,   146,     0,     0,   130,
     153,     0,     0,     0,     0,   120,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   199,     0,     0,
       0,     0,   167,   167,     0,   243,     0,   245,     0,   247,
       0,   416,     0,     0,   273,   275,   269,   271,     0,     0,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,     0,   443,   442,   398,   133,   134,     0,     0,     0,
       0,    87,    91,     0,     0,   315,   400,     0,     0,     0,
       0,     0,    81,     0,     0,    82,     0,   455,   169,   170,
     171,   172,     0,    39,     0,     0,     0,     0,     0,    41,
     459,     0,     0,    99,   102,     0,     0,   123,   131,   132,
     136,     0,     0,   147,     0,     0,   288,     0,   140,     0,
       0,   279,   152,     0,     0,     0,     0,   137,     0,   148,
     154,     0,     0,     0,     0,   413,     0,   412,     0,     0,
       0,   234,     0,     0,   235,     0,     0,   236,     0,     0,
       0,     0,     0,     0,     0,   179,     0,     0,   178,     0,
       0,     0,   173,     0,     0,    32,     0,     0,   449,     0,
     215,   214,     0,     0,     0,     0,   469,    72,    71,    77,
      79,     0,    85,     0,    44,     0,     0,     0,   415,     0,
       0,     0,    28,     0,   108,   113,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   126,   139,   151,   156,     0,
       0,    92,    93,   167,     0,   160,   161,     0,     0,     0,
       0,     0,     0,     0,   263,     0,     0,   167,     0,     0,
       0,     0,     0,   164,   163,     0,     0,     0,     0,    88,
      89,     0,     0,   453,     0,    40,     0,     0,     0,    42,
      57,     0,     0,     0,   297,   299,   298,   300,   301,   144,
       0,     0,     0,     0,     0,     0,   411,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   277,     0,     0,     0,
     228,     0,     0,   174,     0,     0,     0,   448,   216,     0,
     316,    83,     0,     0,     0,     0,     0,     0,   100,   109,
       0,   103,   114,     0,     0,     0,     0,   158,     0,   249,
       0,     0,   251,     0,     0,   253,     0,     0,     0,   264,
       0,   224,     0,   167,     0,     0,     0,   135,    90,     0,
      48,     0,    54,     0,     0,     0,     0,     0,   121,   149,
     296,   410,   237,     0,     0,   244,   238,     0,     0,   246,
     239,     0,     0,   248,     0,     0,     0,   230,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   112,
       0,   115,   116,     0,     0,   255,     0,   257,     0,   259,
     265,   276,   229,   225,     0,     0,     0,     0,    45,     0,
      52,     0,     0,     0,   444,     0,     0,     0,   240,     0,
       0,   241,     0,     0,   242,     0,     0,   181,     0,   175,
       0,    46,     0,     0,   205,     0,   111,     0,   117,     0,
       0,     0,     0,     0,     0,     0,   231,     0,     0,     0,
       0,     0,     0,   106,   211,   250,     0,   252,     0,   254,
       0,   176,    47,    49,     0,    50,     0,     0,     0,     0,
       0,     0,     0,    55,   107,   256,   258,   260,    51,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    83,   882,    84,    85,   648,  1302,  1308,
     873,  1043,  1454,  1620,   874,  1573,  1654,   875,  1622,   876,
     877,  1047,   305,   406,    86,   659,   415,  1404,  1405,   416,
    1603,  1462,  1509,  1463,  1512,   918,  1330,  1209,   631,   446,
     447,   448,   449,   266,   385,   386,    89,    90,    91,    92,
      93,    94,   267,   956,  1532,  1594,   717,  1352,  1355,  1358,
    1553,  1557,  1561,  1609,  1612,  1615,   952,   953,  1078,   915,
     688,   726,    96,    97,    98,    99,   268,   162,   462,   226,
    1193,   269,   270,   271,   520,   279,   859,  1036,   595,   411,
     596,   100,   272
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1242
static const yytype_int16 yypact[] =
{
    4870,    43,     9,  4981, -1242, -1242,  2170,    16,    66,   -95,
     -79,    28,   151,   171,   184,   191,   220,    -5,    57,  -141,
      74,   103,     8,   121,   130,     7,   138,   163,   305,   187,
     344,   413,   273,   274,   453,   460,   408,   411,   241,   412,
     133,   448,   558,   -37,   450,   -75,   -75,   458,   281,    15,
       3,   587,   599,    11,    70,   618,   616,   470,   674,   690,
     696,  2829,   703,   538,   546,   554,    18,    42, -1242,   562,
   -1242,   733,   734,   567, -1242,   740,   744,    25,    26, -1242,
   -1242, -1242,  1970, -1242, -1242, -1242, -1242, -1242, -1242, -1242,
   -1242, -1242, -1242, -1242, -1242, -1242, -1242, -1242,    36, -1242,
     566,    78, -1242,    17, -1242, -1242, -1242, -1242,   382,   432,
     519,   523,   539,   542,   543,   553,   561,   593,   594,   600,
     609,   610,   613,   633,   637,   646,   647,   664,   668,   679,
     700,   704,   707,   582,   585,   590,   601,   619,   620, -1242,
   -1242, -1242, -1242, -1242,   783,   626,   627,   632,   651, -1242,
   -1242, -1242,  1970,  1970,  1970,  4098,  3871,    21,   824,   420,
     648,   229, -1242,   652,   831,   126,   837,  1970,   409,   409,
   -1242,  1970, -1242, -1242, -1242, -1242, -1242, -1242, -1242,  1970,
    4320,  1970,  1970,   673,  1970,  4320,  1970,  1970,   680,  4320,
    1970,  1970,  3025,   699,   667, -1242,  4320,  2829,  2829,  2829,
     708,   711,  2829,  2829,  2829,   718, -1242, -1242, -1242, -1242,
     722,   738,   739,  3025,  1970,   873,  3025,    18,   716,   742,
     -75,   -75,   -75,  1970,  1970,   -81, -1242,    59,   -75,   751,
     767,   774,  4147,    81,  -122,   766,   782,   790,  2829,  2829,
    3025,   811,    39,   732, -1242,   975, -1242,   805,   814,   818,
    2829,  2829,   859,   891,   894,   579, -1242,   906,    27,  1048,
    1081,  1086,   565,  3123,  1970,  2351, -1242, -1242,   702, -1242,
    1094, -1242,   -29,  1104,  1970,  1970,  1970,   933,  1970,   955,
    1004,  1970,  1970, -1242, -1242,  1970,  1164, -1242,  1168, -1242,
    1169, -1242,    91,   865, -1242,  3025,  3025,  1010,   847, -1242,
   -1242, -1242, -1242, -1242, -1242,  3025,  1186,  1017,  1970,  1190,
    1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,
    1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,
    1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,
    1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,
    1970,  1970,  1970,  1970,   409,   409,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   409,  1970,   409,   409,   409,
    1193,  1022,  1022,  1022,  4320,  7452,    85,  4320,  6647,   100,
    1021,  1195,  1024,  1023, -1242,  1025,  2499,  1970, -1242,  1970,
    1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,  1970,
    1970,  1970,  1970,  1970, -1242, -1242, -1242, -1242,  1110,   494,
     -84, -1242, -1242,    86,  5893,   221,   375,  7473,  4320,  4605,
   -1242,   243,  7494,  7515,  1970,  7536,   713,  7557,  7578,  1970,
     720,  7599,  7620,  1196,  1970,  1970,   723,  1199,  1203,  1204,
    1970,  1970,  1206,  1207,  1207,  1970,  1038,  1041,  1042,  1043,
    1970,  1970,  1970,  1211,  5813,  1044,  1214,  1045, -1242, -1242,
     128, -1242, -1242,  5919,  5945,   -75,   -75,   420,   420,   164,
    1970,  1970,  1970,  4147,  4147,  1970,  2499,   170, -1242,  1970,
    1970,  1970,  1970,  1970,  1215,  1217,  1218,  1970,  1221, -1242,
    1970,  1970,  1056, -1242,  4320,  4320,  4320,  1222,  1224,  1970,
    1970,  1970,  -106,  4050,  1227,  1228, -1242,  1970, -1242, -1242,
   -1242,  1052,  1055,  1059,  1061,  4320,  1022, -1242,  7641, -1242,
     729,  1970,  3221, -1242, -1242,  7662,  7683,  7704,  1118,  5971,
   -1242,  1065,  4630,  7725,  6670, -1242, -1242,  1248, -1242,  1742,
    1970, -1242,  1072,   756,  1970,  1242,  1243, -1242,  1970,  6693,
     129,  7746,  6716,  7767,  6739,  7788,  6762,  7809,  6785,  7830,
    6808,  7851,  6831,  7872,  6854,  7893,  6877,  7914,  6900,  7935,
    6923,  7956,  6946,  5997,  6023,  7977,  6969,  7998,  6992,  8019,
    7015,  8040,  7038,  8061,  7061,  8082,  7084,  8103,  7107,  6049,
    6075,  6101,  6127,  6153,  6179, -1242,    90,   435,   165,   482,
    1070,  1071,  1077,  1078,  1074,  1082,  1083,   203,  1250,  1084,
    1105,  1101,  1103,  1107,   759,    85, -1242,  3025,   769,     1,
     847,  1970,  1251,  1280,    23,  1111, -1242,   -87,    22,    24,
      -6, -1242,  5057,  4649,  2476,   881,   807,   807,   754,   754,
     754,   754,   381,   381,  1022,  1022,  1022,  1022,    20, -1242,
    1970,  1283,    51,  4320,  1284,  4320,  1970,  1285, -1242,  1193,
    1286,   409,  1282,  4320,  4320,  1165,  1287,  1290,  8124,  1291,
    1171,  1293,  1294,  8145,  1175,  1297,  1300,  1970,  8166,  5085,
    1127, -1242, -1242, -1242,  8187,  8208,  1970,  3025,  1305,  1314,
    8229,  4487,  4487,  4487,  4487,  8250,  8271,  8292,  3025,  4320,
    1145, -1242, -1242,  2220,  2472,   -75,  1970,  1970, -1242, -1242,
    1142,  1143,  4147,  6205,  6231,  6257,  5867,   693,   -75,  2535,
    8313,  5113,  8334,  8355,  8376,  1970,  1322, -1242,  1970,  8397,
   -1242,  7130,  7153, -1242,   772,   779,   802, -1242, -1242,  7176,
    7199,  6283, -1242,  4320, -1242,  4320,  7222,   -29,  1156,  5141,
    4320,  4320,  4320,  4320,   810, -1242, -1242,  4680,  4320,  1022,
   -1242,  1327,  1329,  1330,  1160,  1970,  2707,  1970,  1970, -1242,
      40, -1242, -1242,  1158,  3025,  1344,  5169, -1242, -1242,  7245,
     775, -1242, -1242, -1242, -1242, -1242, -1242, -1242, -1242, -1242,
   -1242, -1242, -1242, -1242, -1242, -1242, -1242, -1242, -1242, -1242,
   -1242, -1242, -1242, -1242,  1970,  1970, -1242, -1242, -1242, -1242,
   -1242, -1242, -1242, -1242, -1242, -1242, -1242, -1242, -1242, -1242,
    1970,  1970,  1970,  1970,  1970,  1970, -1242,   409, -1242, -1242,
    4320, -1242,  4320,   409,   409, -1242, -1242,   409,   409,   409,
   -1242, -1242,  1970, -1242,   409, -1242,  1176,  1970,  1346,  1177,
      44,  1970,  1350,  1351,  1883, -1242,  1352,  1182,    18,  1354,
   -1242,  4320,  4320,  4320,  4320, -1242,  1970, -1242,  1187,  1188,
    1183, -1242,  1357, -1242, -1242, -1242, -1242, -1242,  7268, -1242,
   -1242,  1212,   409,   259, -1242,   324,  6309, -1242,  1358, -1242,
   -1242,   -75,  4605, -1242,   923,  3025,  3025,  1360,  3025,   930,
    3025,  3025,  1365,  1307,  3025,  3025,  1923,  1368,  1371,  4320,
    1372,  1374,  4733, -1242, -1242,  1376, -1242,  1377,  1208,  8628,
   -1242,  1213,  1216,  1220,  1379,  1382,  1385,  1393,   828,  1389,
    3468, -1242, -1242,   183,  6335,  6361, -1242, -1242,  5197,  -100,
     -75,   -75,   -75,  1396,  1397,  1223,  1415,  1252,    31,    38,
      47,    50,   902, -1242,   235, -1242,   693,  1395,  1421,  1422,
    1424,  1426,  8628, -1242,  2003,  1253,  1430,  1431,  1432,  1375,
    1970,  1433,  1434,  1970,   835,   854,   249, -1242, -1242,   870,
     877,   880,   883, -1242,  1970,   884,  3025,  3025,  3025,  1438,
    6387, -1242,  4700,   330,  1440,  1441,  3025,  1265, -1242, -1242,
    1443,  1444, -1242,  1445,  8418,  7291,  8439,  7314,  8460,  7337,
    8481,  7360, -1242,   333,   502,  1275,  1278,  1272,  1288,  1292,
    8502,  1295,    85,  2092, -1242,    85,   257,  1281,  1453,  2315,
   -1242, -1242, -1242,    18,  1970, -1242,   897, -1242,   898,   907,
     910,   914,  8628,  1299,  1970,  1970,  3025,  1298, -1242,  1296,
   -1242,  1455,    61,  1460,  1970,  3590,    55,  1302,  1304,  1390,
    1390,  3025,  1465,  1312,  1319,  1469,  1470,  3025,  1324,  1472,
    1474, -1242,  1476,  3025,   915,  3025,  3025,  1482,  1489, -1242,
    3025,  1499,  1500,  1505,  1507,  3025,  3025,  3025, -1242,  1508,
     437, -1242,  1970,  1970,  1970,  1335,  1337,  -114,  -110,  -102,
    1343, -1242,  3025, -1242,  1970, -1242,  1515, -1242,  1516, -1242,
    1517, -1242,  1518, -1242, -1242,  4147,  1237,  2927, -1242,  1345,
    1347,  3319, -1242,  4320, -1242, -1242, -1242,  1349,  3546, -1242,
   -1242,  7383,  1313,  1348,  1527, -1242, -1242, -1242, -1242,  8628,
   -1242,  1529,  1530,  1409, -1242,  1970,  1970,  1970, -1242,  1532,
     461,  1359,  1534, -1242,   245, -1242, -1242, -1242, -1242, -1242,
   -1242, -1242, -1242, -1242, -1242, -1242, -1242, -1242,   409, -1242,
   -1242, -1242, -1242,  3025, -1242,  3025,   847,  1970,  1538,  1544,
      23, -1242,  1543,  7406,    18, -1242,  1551,  1552,  1553,  1554,
    1970,  6413,  6439,   919, -1242,  1970,  1546, -1242, -1242,   409,
   -1242,  6465,  4487,  8628, -1242, -1242,  1970,  1970,   -75,  1555,
    1556,  1558, -1242,  1970,  1970, -1242, -1242,  1561,  1970, -1242,
   -1242,  1565,  1566,  1392,  1568,  1447,  1970, -1242,  1572,  3025,
    3025,  3025,  3025,  1574,  1099,  1577,  1970, -1242,  4487,  5225,
    8523,  4973,   420,   420,   -75,  1581,   -75,  1582,   -75,  1583,
    1970,   123,  1391,  8544, -1242, -1242, -1242, -1242,  5253,   292,
   -1242,  1588,    94,  1589,  3025,   -75,    94,  1592,   924,  1970,
   -1242,  1593, -1242, -1242,   -29, -1242, -1242,  3025,  5001,   159,
    8565, -1242, -1242,  3644,  3025, -1242, -1242,  1425,  1595,  1596,
    1597,  3773, -1242,  1598,  1600, -1242,  1429, -1242, -1242, -1242,
   -1242, -1242,   457,  8628,  1970,  1970,  3025,  1423,   927,  8628,
   -1242,  1602,  1970,  8628, -1242,  5281,  5309,   166, -1242, -1242,
   -1242,  5337,  5365, -1242,  5393,  1605, -1242,  3025, -1242,  1547,
    1606,  8628, -1242,  1608,  1610,  1612,  1614, -1242,  1446, -1242,
   -1242,  5840,  4394,  1615,  1448, -1242,  1970, -1242,  1449,  1450,
     299, -1242,  1457,   342, -1242,  1458,   354, -1242,  1459,  7429,
    1616,  3025,  1618,  1461,  1970, -1242,  3417,   359, -1242,   948,
     366,   377, -1242,  1628,  5421, -1242,  1503,  1970, -1242,  1970,
   -1242, -1242,  4320,  4444,  1630,  1462, -1242, -1242, -1242, -1242,
   -1242,    18, -1242,  1519, -1242,  1970,  6491,  6517, -1242,  3025,
    1970,  1635, -1242,  6543, -1242, -1242,  1637,  1641,  1642,  1643,
    1648,  1649,   951,  1475, -1242, -1242, -1242, -1242, -1242,  3025,
    4320, -1242, -1242,   420,  5029, -1242, -1242,  4147,   693,  4147,
     693,  4147,   693,  1651, -1242,   962,  3025, -1242,  5449,   -75,
    1653,  4320,   -75, -1242, -1242,  1970,  5477,  5505,   965, -1242,
   -1242,  1654,  1655, -1242,  1483,  8628,  1970,  1970,   966,  8628,
   -1242,  1970,   969,   972, -1242, -1242, -1242, -1242, -1242, -1242,
    1484,  1970,   973,   976,  1480,  1970, -1242,  5533,   380,  1387,
    5561,   446,  1399,  5589,   449,  1442, -1242,  3025,  1660,  1584,
    4366,  1486,   454, -1242,   977,   456,  4519, -1242, -1242,  1662,
   -1242, -1242,  1970,  8586,  6569,    30,  6595,  1666, -1242, -1242,
    1668, -1242, -1242,  1970,  5617,  1669,  1670, -1242,  5645,  1671,
    1970,  1673,  1675,  1970,  1677,  1678,  1970,  1682,  1492, -1242,
    1970, -1242,   693, -1242,  4320,  1683,  3417, -1242, -1242,   981,
   -1242,  1970, -1242,  3025,  1970,  2656,  3817,  6621, -1242, -1242,
   -1242, -1242, -1242,  1509,  5673, -1242, -1242,  1510,  5701, -1242,
   -1242,  1512,  5729, -1242,  1688,  4539,  1481,  4511,   982, -1242,
     496,   986,  1689,  1521,  8607,   987,  5757,  2351, -1242, -1242,
     409,  8628, -1242,  1970,   693,  1691,   693,  1692,   693,  1697,
   -1242, -1242, -1242, -1242,   693,  1698,  4320,  1703, -1242,   409,
   -1242,  1533,  1704,   991,  4558,   999,  5785,  1620, -1242,  1535,
    1657, -1242,  1536,  1783, -1242,  1537,  2325, -1242,  1002, -1242,
    1003, -1242,  1540,  3025, -1242,  1970, -1242,   847, -1242,  1705,
    1713,   693,  1721,   693,  1722,   693, -1242,  1727,   409,  1728,
     409,  1006,  4578, -1242, -1242, -1242,  2803, -1242,  3671, -1242,
    3865, -1242, -1242, -1242,  1007, -1242,  1729,   847,  1730,  1731,
    1732,   409,  1733, -1242, -1242, -1242, -1242, -1242, -1242, -1242
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1242, -1242, -1242, -1242,   692, -1242, -1242, -1242, -1242,   246,
   -1242, -1242, -1242, -1242, -1242, -1242, -1242, -1242, -1242, -1242,
   -1242, -1242,  -359,   -66, -1242,  1331, -1242, -1242, -1242, -1242,
   -1242, -1242, -1242, -1242, -1242,  -192, -1242,   691,  1753, -1242,
   -1242, -1242, -1242,     2,  -461,  -231, -1242, -1242, -1242, -1242,
   -1242, -1242,  1754, -1242, -1242, -1242, -1242, -1242, -1242, -1242,
   -1242, -1242, -1242, -1242, -1242, -1242,  -823,  -942, -1242, -1242,
    1315, -1242, -1242, -1242, -1242, -1242,   251, -1242,    -7, -1242,
   -1241,   845,   727,  1191,  1205,  -201,   578, -1242,    12,    -4,
    -351, -1242,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -460
static const yytype_int16 yytable[] =
{
     101,   476,   164,   165,   597,    88,   710,   711,   616,     5,
    1114,   188,   183,   492,   607,   242,   457,   617,   163,   234,
     621,   307,   277,  1369,   867,   379,   183,   857,   188,   166,
     288,   290,   506,   179,   170,   306,  1542,  1105,   225,   227,
     180,   233,   294,   488,  1107,   489,   280,   994,  1026,     4,
     465,   466,   479,  1109,   465,   466,  1111,   880,   537,   480,
     539,  1205,   465,   466,   465,   466,  1244,  1198,  1245,   742,
    1246,   238,  1247,   239,   245,   743,   246,   235,  1248,   168,
    1249,   236,  1096,   465,   466,   298,  1412,   179,   217,   221,
     222,   652,   616,   237,   861,   169,   653,   102,   255,   223,
     467,   218,   219,   105,   106,   107,   224,   620,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     257,   521,   247,  1116,   167,   868,   869,   870,   871,   136,
     137,   138,   303,   304,  1106,   243,   380,   381,   141,   142,
     143,  1108,   299,   300,   301,   302,   258,   172,  1458,   259,
    1110,   384,   260,  1112,   261,   412,   412,  1379,   191,  1027,
    1028,   177,   303,   304,  1114,   864,   262,   173,  1472,   850,
     410,   413,   184,    44,    45,    46,    47,    48,   189,   185,
     174,    52,   244,   308,    55,   309,   184,   175,   213,   278,
     160,   214,   872,   862,   858,   863,   289,   291,   507,   171,
     295,  1543,   881,   460,   461,   490,   281,   296,   995,   465,
     466,   469,   881,   465,   466,   477,   176,   703,   704,   299,
     300,   301,   302,   178,   145,   388,   299,   300,   301,   302,
     468,   148,   149,   150,   151,   465,   466,   719,   181,   303,
     304,   299,   300,   301,   302,   193,   847,   161,   473,  1366,
     851,   654,   478,   154,  1176,   826,   655,   540,   475,   504,
     827,   303,   304,   158,   160,   224,   519,   182,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   522,
     401,   402,   465,   466,   545,   186,   403,   303,   304,   766,
     303,   304,  1575,   206,   187,  1360,   207,  -457,   705,   208,
    -458,   209,   190,   622,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   465,   466,
     465,   466,   403,   293,   465,   466,   197,   191,  1147,   198,
     829,  1380,   199,   229,   712,   830,   230,   465,   466,   231,
     718,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,  1092,   412,   412,   412,   613,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   192,   840,   609,
     610,   611,  1641,   827,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   657,   465,
     466,   658,   403,   371,   372,   373,   375,   378,   299,   300,
     301,   302,   194,   409,   104,  1115,   303,   304,   408,   195,
     303,   304,   414,   664,   383,   665,  -459,  1134,   303,   304,
     417,   419,   422,   423,  1052,   425,   419,   427,   428,   664,
     419,   431,   432,  1237,  1238,   221,   222,   419,   130,   131,
     132,   133,   134,   135,   196,   223,   465,   466,   708,   709,
     139,   140,   232,   465,   466,   454,   461,  1282,  1283,   384,
     384,   930,  1364,   202,   463,   464,   203,   210,   204,  1427,
     211,   205,   212,   464,   781,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,  1053,
     921,   922,   923,   403,   664,  1148,   465,   466,  1164,    44,
      45,    46,    47,   664,   516,   518,   419,    52,   465,   466,
      55,   200,  1429,   465,   466,   525,   526,   527,   201,   529,
     465,   466,   532,   533,  1431,   250,   534,  1114,   251,  1439,
    1114,   465,   466,  1114,   465,   466,  1441,   400,   401,   402,
     146,   147,   660,   852,   403,   658,   310,  1442,   311,   549,
    1520,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,  1479,   312,  1482,   313,  1485,
     465,   466,   828,   465,   466,   827,   853,   608,   465,   466,
     465,   466,   215,   216,  1114,   419,  1523,   511,   419,  1526,
     512,   220,  1394,   513,  1534,   514,  1536,  1395,   632,   228,
     633,   634,   635,   636,   637,   638,   639,   640,   641,   642,
     643,   644,   645,   646,   647,   240,   888,  1035,   412,   831,
     465,   466,   832,  1173,   241,  1114,  1175,  1177,  1114,   516,
     650,  1114,   651,   890,  1114,   668,  1596,   160,   252,  1165,
     673,   781,   664,   248,   249,   678,   679,   920,   920,   920,
     920,   684,   685,   314,   253,   315,   690,   316,   933,   317,
     254,   695,   696,   697,  1114,   939,  1114,   273,  1114,  1566,
     521,   954,   274,   318,  1002,   319,   320,   322,   321,   323,
     275,   713,   714,   715,   371,   372,   716,   324,   276,   325,
     720,   721,   722,   723,   724,   326,   282,   327,   729,   283,
     284,   731,   732,   285,   286,   419,   419,   419,   287,   297,
     739,   740,   741,   502,   746,   503,   360,   504,   749,   361,
     159,  1607,   160,  1610,   362,  1613,   419,   328,   330,   329,
     331,  1616,   757,   759,   332,   363,   333,   412,   943,   409,
     104,  1348,  1349,   334,   336,   335,   337,   338,   944,   339,
     366,   746,  1003,   364,   365,   776,   945,   946,   947,   779,
     367,   368,   948,   949,   950,   951,   369,   340,  1646,   341,
    1648,   342,  1650,   343,   130,   131,   132,   133,   134,   135,
     344,   346,   345,   347,   412,   370,   139,   140,   382,   387,
     412,   412,  1182,   404,   412,   412,   412,   405,   348,  1012,
     349,   412,   350,   407,   351,  1015,  1016,   424,   435,  1017,
    1018,  1019,   104,   352,   429,   353,  1021,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   522,   401,
     402,   541,   854,   434,   354,   403,   355,   455,   356,   412,
     357,   358,   440,   359,  1056,   441,   130,   131,   132,   133,
     134,   135,   445,   664,  1051,   670,   450,   458,   139,   140,
     664,   878,   674,   664,   419,   680,   419,   886,   491,   664,
    1002,   756,   451,   452,   759,   892,   146,   147,   398,   399,
     400,   401,   402,   459,   437,   438,   439,   403,   906,   442,
     443,   444,   470,  1097,  1098,  1099,   774,   912,   775,   664,
     481,   846,   919,   919,   919,   919,   303,   304,   471,   664,
     419,   849,   664,  1001,   968,   472,   482,   934,   935,   664,
    1178,   969,  1474,   938,   483,   484,   485,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   962,   497,   498,   964,
     403,   493,   664,  1297,   970,   487,   494,   943,   146,   147,
     664,  1057,   983,  1058,   419,   495,   419,   944,  1063,   496,
    1064,   419,   419,   419,   419,   945,   946,   947,   664,   419,
    1089,   948,   949,   950,   951,   664,   990,  1132,   992,   993,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   664,   499,  1133,   433,   403,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     664,  1204,  1135,   508,   403,  1004,  1005,   664,   453,  1136,
     664,   456,  1137,   664,   664,  1138,  1140,   500,     7,     8,
     501,  1006,  1007,  1008,  1009,  1010,  1011,  1184,   664,  1185,
    1186,   419,   505,   419,  1113,   486,   509,   664,  1286,  1187,
     664,   510,  1188,  1020,   664,   664,  1189,  1223,  1023,  1306,
     523,  1307,  1029,  1338,   664,  1339,  1373,  1400,  1259,  1401,
     524,   528,   419,   419,   419,   419,   649,  1042,   627,    20,
      21,   628,    23,    24,   629,    26,   630,    28,  1306,    29,
    1440,  1306,   531,  1470,    34,    35,   530,    37,    38,    39,
     542,   543,  1487,    42,  1488,   664,  1306,  1499,  1505,  1507,
     546,  1508,  1510,  1306,  1511,  1515,   664,   664,  1516,  1535,
     419,  1400,   664,  1572,  1595,   412,   664,  1306,  1597,  1601,
     535,  1625,  1290,  1626,   536,   538,    63,    64,    65,   827,
    1287,  1628,   664,  1638,  1637,  1639,  1306,  1661,  1656,  1662,
    1452,   544,   547,   548,   550,   403,   412,   612,  1314,   623,
     625,  1317,   624,   677,   159,   681,  1490,   626,  1286,   682,
     683,  1311,   691,   686,   687,   692,   693,   694,   698,   700,
     701,  1128,   725,   727,  1131,   728,   702,   730,   737,  1605,
     738,   747,   748,   750,  1343,  1139,   751,  1350,   733,  1353,
     752,  1356,   753,   764,   384,   384,   767,   773,   777,   778,
     833,   834,   835,   836,   837,  1367,   841,   855,  1370,  1371,
       7,     8,   838,   839,   842,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,  1384,
     843,   844,   845,   403,   856,  1183,   160,   879,   860,   891,
     884,   887,   889,   894,   895,  1191,  1192,   896,   898,   899,
     900,   901,  1567,   903,   904,  1201,  1203,   905,   909,   914,
     627,    20,    21,   628,    23,    24,   629,    26,   630,    28,
     916,    29,   943,   929,   936,   937,    34,    35,   963,    37,
      38,    39,   944,   977,   986,    42,   987,   988,   989,   996,
     945,   946,   947,  1239,  1240,  1241,   948,   949,   950,   951,
     998,  1022,  1024,  1251,  1025,  1253,  1030,  1031,  1034,  1033,
    1037,  1044,  1045,  1048,  1046,  1055,  1258,  1061,    63,    64,
      65,   420,  1067,  1050,   419,  1072,   420,  1068,  1073,  1075,
     420,  1076,  1079,  1081,  1080,   421,  1085,   420,  1082,  1086,
     426,  1083,  1087,  1090,   430,  1084,  1278,  1279,  1280,  1088,
    1100,   436,  1117,  1101,  1102,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,  1260,
    1478,  1103,  1481,   403,  1484,   384,  1104,  1118,  1291,  1119,
     771,  1120,  1492,  1121,  1123,  1495,  1124,  1125,  1126,  1129,
    1130,  1303,  1144,  1127,  1149,  1150,  1309,  1152,  1154,  1153,
    1166,  1155,  1168,  1313,   517,  1167,   420,  1315,  1316,  1179,
    1180,  1197,   848,  1169,  1321,  1322,  1200,  1170,  1208,  1324,
    1172,  1212,   943,  1190,  1196,  1215,  1216,  1331,  1219,  1195,
    1220,  1221,   944,  1206,   943,  1207,  1226,  1341,  1272,  1342,
     945,   946,   947,  1213,   944,  1227,   948,   949,   950,   951,
    1214,  1359,   945,   946,   947,  1218,  1229,  1230,   948,   949,
     950,   951,  1231,   419,  1232,  1236,  1242,   419,  1243,  1250,
    1374,  1254,  1255,  1256,  1257,  1273,  1264,   943,  1265,  1570,
    1269,  1274,   913,  1277,  1383,  1275,  1276,   944,  1281,  1284,
    1285,  1579,  1582,   927,  1292,   945,   946,   947,  1293,  1295,
    1310,   948,   949,   950,   951,  1396,  1397,  1298,  1299,  1300,
    1301,  1318,  1319,  1403,  1320,   420,   943,  1323,   420,  1521,
    1325,  1361,  1326,  1327,  1328,  1329,   944,   412,  1332,   614,
    1337,  1524,   618,  1340,   945,   946,   947,  1351,  1354,  1357,
     948,   949,   950,   951,  1365,  1368,   412,  1424,  1372,  1375,
    1386,  1387,  1388,  1389,  1399,  1391,  1392,  1393,  1402,   517,
    1411,  1621,  1414,  1413,  1415,  1438,  1416,   516,  1417,   997,
    1418,  1422,  1434,  1643,  1527,  1436,  1445,  1419,  1446,  1423,
    1447,  1425,  1426,   419,  1443,   412,  1450,   412,  1428,  1430,
    1432,  1460,  1437,  1464,  1451,  1453,  1455,  1465,  1466,  1467,
    1652,  1459,  1655,  1664,  1468,  1469,  1471,  1486,   412,  1493,
    1500,  1501,  1517,  1592,  1502,  1513,  1529,  1533,  1538,  1530,
    1545,   419,  1546,  1668,  1564,  1549,  1550,  1552,  1477,  1555,
    1480,  1556,  1483,  1559,  1560,   420,   420,   420,  1563,  1569,
    1584,  1586,   419,  1588,  1590,  1598,  1496,  1608,  1611,   734,
     735,   736,  1599,  1614,  1617,   943,   420,  1503,  1504,  1619,
    1624,  1644,  1506,   760,  1623,   944,  1631,  1633,  1635,  1645,
     754,  1640,  1514,   945,   946,   947,  1518,  1647,  1649,   948,
     949,   950,   951,  1651,  1653,  1663,  1665,  1666,  1667,  1669,
    1059,  1060,   943,  1062,  1199,  1065,  1066,   661,  1539,  1069,
    1070,  1210,   944,  1309,     7,     8,    87,    95,  1294,   689,
     945,   946,   947,     0,  1547,     0,   948,   949,   950,   951,
       0,  1554,     0,     0,  1558,     0,     0,  1562,     0,     0,
       0,  1565,     0,     0,     0,   419,     0,   419,     0,     0,
       0,     0,  1574,     0,     0,  1576,     0,  1581,     0,     0,
       0,     0,  1630,     0,   627,    20,    21,   628,    23,    24,
     629,    26,   630,    28,     0,    29,     0,     0,     0,     0,
      34,    35,     0,    37,    38,    39,     0,     0,  1604,    42,
       0,  1141,  1142,  1143,  1606,     0,     0,     0,     0,  1632,
       0,  1151,     0,     0,   420,     0,   420,   419,     0,     0,
       0,     0,     0,     0,   760,   893,     0,     0,   883,     0,
     885,     0,    63,    64,    65,     0,     0,     0,   943,     0,
       0,     0,     0,     0,     0,     0,  1642,     0,   944,     0,
       0,     0,     0,     0,     0,     0,   945,   946,   947,  1032,
     420,  1194,   948,   949,   950,   951,     0,     0,     0,     0,
       0,     0,     0,     0,   928,     0,  1211,     0,     0,     0,
       0,     0,  1217,     0,     0,     0,     0,     0,  1222,     0,
    1224,  1225,     0,     0,   772,  1228,     0,     0,     0,  1071,
    1233,  1234,  1235,     0,   420,     0,   420,     0,     0,     0,
       0,   420,   420,   420,   420,     0,     0,  1252,   974,   420,
     975,     0,     0,     0,     0,   979,   980,   981,   982,     0,
       0,     0,  1263,   985,     0,  1634,  1267,     0,     0,     0,
       0,     0,     0,   102,   292,     0,     0,     0,     0,   105,
     106,   107,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,     0,  1122,
       0,     0,     0,     0,     0,   136,   137,   138,  1288,     0,
    1289,   420,     0,   420,   141,   142,   143,     0,     0,     0,
       0,     0,     0,     0,     0,  1013,     0,  1014,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   420,   420,   420,   420,   403,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1038,  1039,  1040,  1041,
       0,     0,     0,     0,  1333,  1334,  1335,  1336,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,  1174,     0,
     420,     0,     0,     0,     0,     0,     0,     0,     0,  1194,
     145,     0,     0,     0,  1074,     0,     0,   148,   149,   150,
     151,     0,  1376,     0,     0,     0,     0,     0,     0,  1385,
       0,     0,     0,     0,   152,   153,     0,     0,     0,   154,
       0,     0,     0,     0,   264,     0,     0,     0,     0,   158,
       0,  1398,     0,     0,     0,     0,     0,     0,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,  1194,   102,   103,   104,   403,     0,     0,   105,
     106,   107,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,  1435,     0,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,   139,   140,     0,   141,   142,   143,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1194,     0,     0,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,     0,     0,     0,  1194,   403,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1489,   627,    20,    21,   628,    23,    24,   629,    26,
     630,    28,     0,    29,     0,     0,     0,     0,    34,    35,
       0,    37,    38,    39,   144,     0,     0,    42,     0,     0,
     145,   146,   147,     0,   420,     0,     0,   148,   149,   150,
     151,  1181,     0,     0,     0,     0,     0,     0,  1268,     0,
       0,     0,  1528,     0,   152,   153,     0,     0,     0,   154,
      63,    64,    65,     0,   155,     0,   156,     0,   157,   158,
       0,   159,     0,   160,   102,   255,     0,     0,     0,     0,
     105,   106,   107,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   257,  1194,     0,
    1578,     0,     0,     0,     0,     0,   136,   137,   138,     0,
       0,     0,   931,     0,     0,   141,   142,   143,     0,     0,
     943,     0,     0,   258,     0,     0,   259,     0,     0,   260,
     944,   261,     0,     0,     0,     0,     0,     0,   945,   946,
     947,     0,     0,   262,   948,   949,   950,   951,     0,     0,
      44,    45,    46,    47,    48,     0,     0,     0,    52,     0,
       0,    55,     0,   420,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1194,     0,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     7,     8,     0,     0,   403,     0,
       0,   145,     0,     0,     0,     0,     0,     0,   148,   149,
     150,   151,     0,     0,     0,     0,     0,  1636,     0,     0,
       0,     7,     8,     0,     0,   152,   418,     0,     0,     0,
     154,     0,     0,     0,     0,   264,     0,     0,     0,     0,
     158,     0,     0,   519,   627,    20,    21,   628,    23,    24,
     629,    26,   630,    28,     0,    29,     0,     7,     8,     0,
      34,    35,     0,    37,    38,    39,     0,   517,     0,    42,
       0,   627,    20,    21,   628,    23,    24,   629,    26,   630,
      28,     0,    29,   420,     0,     0,     0,    34,    35,     0,
      37,    38,    39,     0,     0,     0,    42,  1448,     0,     0,
       0,     0,    63,    64,    65,     0,     0,   627,    20,    21,
     628,    23,    24,   629,    26,   630,    28,     0,    29,     0,
       0,   420,     0,    34,    35,     0,    37,    38,    39,    63,
      64,    65,    42,     0,     0,  1473,     0,     0,     0,     0,
       0,     0,   420,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,     0,  1494,     0,     0,   403,
       0,     0,     0,     0,   932,    63,    64,    65,     0,   102,
     255,   104,     0,     0,     0,   105,   106,   107,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   257,     0,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,   139,   140,     0,
     141,   142,   143,     0,     0,     0,     0,   955,   258,     7,
       8,   259,     0,     0,   260,   420,   261,   420,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,  1568,
       0,  1571,     0,     0,     0,    44,    45,    46,    47,    48,
       0,     0,     0,    52,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   420,   627,
      20,    21,   628,    23,    24,   629,    26,   630,    28,     0,
      29,     0,     0,     0,     0,    34,    35,   420,    37,    38,
      39,     0,     0,     0,    42,     0,   145,   146,   147,     0,
       0,  1618,     0,   148,   149,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     152,   263,     0,     0,     0,   154,     0,    63,    64,    65,
     264,     0,   102,   255,   256,   158,     0,  1577,   105,   106,
     107,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   257,     0,     0,     0,     0,
       0,     0,     0,     0,   136,   137,   138,     0,     0,     0,
       0,     0,     0,   141,   142,   143,     0,     0,   943,   991,
       0,   258,     0,     0,   259,     0,     0,   260,   944,   261,
       0,     0,     0,     0,     0,     0,   945,   946,   947,     0,
       0,   262,   948,   949,   950,   951,     0,     0,    44,    45,
      46,    47,    48,     0,     0,     0,    52,     0,     0,    55,
     102,   255,  1261,     0,     0,     0,   105,   106,   107,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   257,     0,     0,     0,     0,     0,   145,
       0,     0,   136,   137,   138,     0,   148,   149,   150,   151,
       0,   141,   142,   143,     0,  1658,     0,     0,     0,   258,
       0,     0,   259,   152,   263,   260,     0,   261,   154,     0,
       0,     0,     0,   264,     0,     0,     0,     0,   158,   262,
     265,     0,     0,     0,     0,     0,    44,    45,    46,    47,
      48,     0,     0,     0,    52,     0,     0,    55,   102,   255,
       0,     0,     0,     0,   105,   106,   107,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   257,     0,     0,     0,     0,     0,   145,     0,     0,
     136,   137,   138,     0,   148,   149,   150,   151,     0,   141,
     142,   143,     0,     0,     0,     0,     0,   258,     0,     0,
     259,   152,   263,   260,     0,   261,   154,     0,     0,     0,
       0,   264,     0,     0,     0,     0,   158,   262,  1262,     0,
       0,     0,     0,     0,    44,    45,    46,    47,    48,     0,
       0,     0,    52,     0,     0,    55,   102,   255,     0,     0,
       0,     0,   105,   106,   107,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   257,
       0,     0,     0,     0,     0,   145,     0,     0,   136,   137,
     138,     0,   148,   149,   150,   151,     0,   141,   142,   143,
       0,     0,     0,     0,     0,   258,     0,     0,   259,   152,
     263,   260,     0,   261,   154,     0,     0,     0,     0,   264,
       0,     0,     0,     0,   158,   262,   265,     0,     0,     0,
       0,     0,    44,    45,    46,    47,    48,     0,     0,     0,
      52,     0,     0,    55,   102,   255,     0,     0,     0,     0,
     105,   106,   107,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   257,     0,     0,
       0,     0,     0,   145,     0,     0,   136,   137,   138,     0,
     148,   149,   150,   151,     0,   141,   142,   143,     0,     0,
       0,     0,     0,   258,     0,     0,   259,   152,   418,   260,
       0,   261,   154,     0,     0,     0,     0,   264,     0,     0,
       0,     0,   158,   262,   515,     0,     0,     0,     0,     0,
      44,    45,    46,    47,    48,     0,     0,     0,    52,     0,
       0,    55,   102,   255,     0,     0,     0,     0,   105,   106,
     107,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   257,     0,     0,     0,     0,
       0,   145,     0,     0,   136,   137,   138,     0,   148,   149,
     150,   151,     0,   141,   142,   143,     0,     0,     0,     0,
       0,   258,     0,     0,   259,   152,   418,   260,     0,   261,
     154,     0,     0,     0,     0,   264,     0,     0,     0,     0,
     158,   262,   758,     0,     0,     0,     0,     0,    44,    45,
      46,    47,    48,     0,     0,     0,    52,     0,     0,    55,
     102,   255,     0,     0,     0,     0,   105,   106,   107,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   257,     0,     0,     0,     0,     0,   145,
       0,     0,   136,   137,   138,     0,   148,   149,   150,   151,
       0,   141,   142,   143,     0,     0,     0,     0,     0,   258,
       7,     8,   259,   152,   263,   260,     0,   261,   154,     0,
       0,     0,     0,   264,     0,     0,     0,     0,   158,   262,
    1266,     0,     0,     0,     0,     0,    44,    45,    46,    47,
      48,     0,     0,     0,    52,     0,     0,    55,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     627,    20,    21,   628,    23,    24,   629,    26,   630,    28,
       0,    29,     0,     0,     0,     0,    34,    35,     0,    37,
      38,    39,  1270,     0,     0,    42,     0,   145,     0,     0,
       0,     0,     0,     0,   148,   149,   150,   151,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   473,  1366,     0,     0,     0,   154,     0,    63,    64,
      65,   475,     0,   102,   292,   104,   158,     0,   224,   105,
     106,   107,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,   139,   140,     0,   141,   142,   143,   102,   292,   104,
    1091,     0,     0,   105,   106,   107,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     0,     0,     0,   139,   140,     0,   141,   142,
     143,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,     0,     0,     0,     0,   403,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   146,   147,     0,     0,     0,     0,   148,   149,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   152,   153,   943,     0,     0,   154,
       0,     0,     0,     0,   264,     0,   944,     0,     0,   158,
       0,  1202,     0,     0,   945,   946,   947,     0,     0,  1390,
     948,   949,   950,   951,   145,   146,   147,     0,     0,     0,
       0,   148,   149,   150,   151,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   153,
       0,     0,     0,   154,     0,     0,     0,     0,   264,     0,
     102,   292,   104,   158,     0,  1382,   105,   106,   107,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,  1659,     0,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,   139,   140,
       0,   141,   142,   143,   102,   292,     0,     0,     0,     0,
     105,   106,   107,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,   137,   138,     0,
       0,     0,     0,     0,     0,   141,   142,   143,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
     943,     0,     0,     0,     0,     0,     0,   145,   146,   147,
     944,     0,     0,     0,   148,   149,   150,   151,   945,   946,
     947,     0,     0,     0,   948,   949,   950,   951,     0,     0,
       0,   152,   153,     0,     0,     0,   154,     0,     0,     0,
       0,   264,     0,     0,     0,     0,   158,     0,  1580,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,     0,     0,     0,     0,     0,     0,   148,   149,
     150,   151,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   152,   153,     0,     0,     0,
     154,     0,     0,     0,     0,   264,     0,  1660,   376,     0,
     158,     0,   377,   102,   292,     0,     0,     0,     0,   105,
     106,   107,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   136,   137,   138,     0,     0,
       0,   102,   292,     0,   141,   142,   143,   105,   106,   107,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   136,   137,   138,     0,     0,     0,     0,
     102,   292,   141,   142,   143,     0,   105,   106,   107,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,     0,     0,     0,     0,     0,
     145,     0,   136,   137,   138,     0,     0,   148,   149,   150,
     151,   141,   142,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   152,   153,     0,     0,     0,   154,
       0,     0,     0,     0,   264,     0,     0,   744,     0,   158,
       0,   745,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,     0,     0,     0,   148,   149,   150,   151,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,   153,     0,     0,     0,   154,     0,     0,
       0,     0,   264,     0,     0,     0,     0,   158,     0,   374,
       0,     0,     0,     0,     0,     0,     0,   145,     0,     0,
       0,     0,     0,     0,   148,   149,   150,   151,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   473,   474,     0,     0,     0,   154,     0,     0,     0,
       0,   475,     0,   102,   255,     0,   158,     0,   224,   105,
     106,   107,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   257,     0,     0,     0,
       0,     0,     0,     0,     0,   136,   137,   138,     0,     0,
       0,     0,     0,     0,   141,   142,   143,     0,     7,     8,
       0,     0,   258,     0,     0,   259,     0,     0,   260,     0,
     261,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1421,     0,   262,     0,     0,     0,     0,     0,     0,    44,
      45,    46,    47,    48,     0,     0,     0,    52,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,   627,    20,
      21,   628,    23,    24,   629,    26,   630,    28,     0,    29,
       0,     0,     0,     0,    34,    35,     0,    37,    38,    39,
    1449,     0,     0,    42,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,     0,     0,     0,   148,   149,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   152,   418,    63,    64,    65,   154,
     102,   292,   104,     0,   264,     0,   105,   106,   107,   158,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     7,     8,  1537,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,   139,   140,
       0,   141,   142,   143,     0,  1591,     0,     0,  1531,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,     0,     0,  1627,   521,   403,     0,     0,
       0,     0,     0,   627,    20,    21,   628,    23,    24,   629,
      26,   630,    28,     0,    29,  1657,     0,     0,     0,    34,
      35,     0,    37,    38,    39,     0,     0,     0,    42,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   521,     0,     0,     0,   403,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,   146,   147,
       0,    63,    64,    65,   148,   149,   150,   151,   768,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   152,   153,     0,     0,     0,   154,   866,     0,     0,
       0,   264,     0,     0,     0,     0,   158,     0,     0,     0,
       0,     0,     0,     0,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   984,     0,
       0,     0,   403,  1593,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,  1146,     0,
       0,     0,   403,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   663,   401,   402,     0,     0,     0,
       0,   403,     0,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,     0,     0,     0,
       0,   403,     0,     0,     0,     0,     0,     0,     0,     0,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   663,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,     0,     0,   403,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,  1077,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,     0,     0,   403,     0,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
      -4,     1,     0,   403,    -4,     0,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,     0,     0,     0,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,    -4,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
      -4,     0,     0,    -4,     0,     0,     0,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,     0,
       0,     0,     0,     0,    -4,     6,     0,     0,     0,    -4,
      -4,    -4,    -4,     7,     8,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,     0,    -4,    -4,    -4,    -4,     0,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,    13,     0,     0,    14,     0,     0,     0,    15,    16,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     0,     0,     0,    58,    59,    60,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
      62,    63,    64,    65,     0,     0,    66,     0,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    79,    80,    81,    82,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,  1346,     0,  1347,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,     0,     0,
       0,  1377,     0,  1378,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,  1475,
       0,  1476,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,     0,     0,     0,     0,     0,   865,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,     0,     0,   908,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,     0,     0,   958,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,     0,     0,
       0,     0,     0,   978,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,     0,
       0,   999,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,     0,     0,     0,     0,     0,  1095,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,     0,     0,  1344,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,     0,     0,  1363,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,     0,     0,
       0,     0,     0,  1406,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,     0,
       0,  1407,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,     0,     0,     0,     0,     0,  1408,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,     0,     0,  1409,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,     0,     0,  1410,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,     0,     0,
       0,     0,     0,  1444,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,     0,
       0,  1491,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,     0,     0,     0,     0,     0,  1497,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,     0,     0,  1498,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,     0,     0,  1519,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,     0,     0,
       0,     0,     0,  1522,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,     0,
       0,  1525,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,     0,     0,     0,     0,     0,  1548,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,     0,     0,  1551,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,     0,     0,  1585,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,     0,     0,
       0,     0,     0,  1587,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,     0,
       0,  1589,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,     0,     0,     0,     0,     0,  1602,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,     0,     0,  1629,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,     0,   699,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,     0,     0,   403,     0,     0,     0,     0,     0,     0,
       0,  1420,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,   755,     0,     0,     0,     0,   706,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,   656,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,   706,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,   707,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,     0,     0,
       0,   765,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,     0,     0,     0,   804,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,   805,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,   820,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,   821,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,     0,     0,
       0,   822,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,     0,     0,     0,   823,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,   824,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,   825,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,   940,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,     0,     0,
       0,   941,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,     0,     0,     0,   942,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,   973,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,  1054,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,  1093,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,     0,     0,
       0,  1094,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,     0,     0,     0,  1145,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,  1304,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,  1305,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,  1312,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,     0,     0,
       0,  1456,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,     0,     0,     0,  1457,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,  1461,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,  1541,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,  1544,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,     0,     0,
       0,  1583,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,   619,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,     0,     0,   403,     0,     0,     0,   770,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
     780,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,     0,     0,     0,     0,   403,
       0,     0,     0,   783,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,   785,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,     0,     0,     0,     0,   403,     0,     0,     0,   787,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,   789,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,     0,     0,     0,
       0,   403,     0,     0,     0,   791,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,   793,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,     0,     0,     0,     0,   403,     0,     0,
       0,   795,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,   797,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,     0,     0,   403,     0,     0,     0,   799,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
     801,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,     0,     0,     0,     0,   403,
       0,     0,     0,   803,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,   807,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,     0,     0,     0,     0,   403,     0,     0,     0,   809,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,   811,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,     0,     0,     0,
       0,   403,     0,     0,     0,   813,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,   815,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,     0,     0,     0,     0,   403,     0,     0,
       0,   817,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,   819,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,     0,     0,   403,     0,     0,     0,   966,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
     967,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,     0,     0,     0,     0,   403,
       0,     0,     0,   971,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,   972,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,     0,     0,     0,     0,   403,     0,     0,     0,   976,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
       0,     0,  1000,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,     0,     0,     0,
       0,   403,     0,     0,     0,  1049,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,     0,     0,  1157,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,     0,     0,     0,     0,   403,     0,     0,
       0,  1159,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,     0,     0,  1161,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,     0,     0,   403,     0,     0,     0,  1163,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,     0,     0,
    1271,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,     0,     0,     0,     0,   403,
       0,     0,     0,  1296,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,     0,     0,  1433,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,     0,     0,     0,     0,   403,     0,   615,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,   662,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,     0,     0,     0,     0,   403,     0,   666,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
     667,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,     0,     0,     0,     0,   403,
       0,   669,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,   671,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,     0,     0,     0,
       0,   403,     0,   672,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,   675,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,     0,     0,   403,     0,   676,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,   755,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,     0,     0,     0,     0,   403,     0,   761,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,   762,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,     0,     0,     0,     0,   403,     0,   763,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
     769,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,     0,     0,     0,     0,   403,
       0,   782,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,   784,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,     0,     0,     0,
       0,   403,     0,   786,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,   788,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,     0,     0,   403,     0,   790,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,   792,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,     0,     0,     0,     0,   403,     0,   794,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,   796,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,     0,     0,     0,     0,   403,     0,   798,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
     800,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,     0,     0,     0,     0,   403,
       0,   802,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,   806,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,     0,     0,     0,
       0,   403,     0,   808,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,   810,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,     0,     0,   403,     0,   812,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,   814,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,     0,     0,     0,     0,   403,     0,   816,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,   818,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,     0,     0,     0,     0,   403,     0,   897,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
     902,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,     0,     0,     0,     0,   403,
       0,   907,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,   910,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,     0,     0,     0,
       0,   403,     0,   911,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,   917,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,     0,     0,   403,     0,   924,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,   925,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,     0,     0,     0,     0,   403,     0,   926,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,   957,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,     0,     0,     0,     0,   403,     0,   959,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
     960,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,     0,     0,     0,     0,   403,
       0,   961,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,   965,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,     0,     0,     0,
       0,   403,     0,  1156,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,  1158,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,     0,     0,   403,     0,  1160,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,  1162,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,     0,     0,     0,     0,   403,     0,  1171,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,     0,  1345,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,     0,     0,     0,     0,   403,     0,  1362,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
    1381,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,     0,     0,     0,     0,   403,
       0,  1540,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,  1600,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,     0,     0,     0,
       0,   403
};

static const yytype_int16 yycheck[] =
{
       3,   232,     6,     6,   355,     3,   467,   468,     7,     0,
     952,     4,     4,   244,   365,     4,   217,   376,     6,     4,
     379,     4,     4,  1264,     4,     4,     4,     4,     4,    13,
       5,     5,     5,   174,     6,   101,     6,     6,    45,    46,
     181,    48,     6,     4,     6,     6,     4,     7,     4,     6,
     164,   165,   174,     6,   164,   165,     6,     6,   289,   181,
     291,     6,   164,   165,   164,   165,   180,     6,   182,   175,
     180,    68,   182,    70,     4,   181,     6,    62,   180,   174,
     182,    66,   182,   164,   165,     7,  1327,   174,   125,   164,
     165,   175,     7,    78,   181,   174,   180,     3,     4,   174,
     181,   138,   139,     9,    10,    11,   181,     7,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     8,    62,   956,    68,   115,   116,   117,   118,    45,
      46,    47,   171,   172,   113,   134,   125,   126,    54,    55,
      56,   113,   151,   152,   153,   154,    62,     6,  1399,    65,
     113,   159,    68,   113,    70,   168,   169,     8,   174,   125,
     126,   176,   171,   172,  1116,   181,    82,     6,  1419,   178,
     168,   169,   174,    89,    90,    91,    92,    93,   181,   181,
       6,    97,   181,   176,   100,   178,   174,     6,    65,   181,
     183,    68,   182,   181,   181,   181,   181,   181,   181,   181,
     174,   181,   161,   220,   221,   176,   174,   181,   178,   164,
     165,   228,   161,   164,   165,   232,     6,   458,   459,   151,
     152,   153,   154,   176,   140,     6,   151,   152,   153,   154,
     181,   147,   148,   149,   150,   164,   165,   478,   174,   171,
     172,   151,   152,   153,   154,    68,   615,     6,   164,   165,
     619,   175,   181,   169,     7,   175,   180,   176,   174,   178,
     180,   171,   172,   179,   183,   181,   182,   174,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   164,   165,   298,   174,   173,   171,   172,   530,
     171,   172,  1543,    62,   174,   182,    65,   181,   180,    68,
     181,    70,   174,   379,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   164,   165,
     164,   165,   173,    82,   164,   165,    62,   174,     8,    65,
     175,   182,    68,    62,   180,   180,    65,   164,   165,    68,
     180,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   180,   367,   368,   369,   370,   356,   357,
     358,   359,   360,   361,   362,   363,   364,    72,   175,   367,
     368,   369,  1623,   180,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   177,   164,
     165,   180,   173,   152,   153,   154,   155,   156,   151,   152,
     153,   154,    68,     4,     5,   180,   171,   172,   167,     6,
     171,   172,   171,   180,     4,   182,   181,   178,   171,   172,
     179,   180,   181,   182,   175,   184,   185,   186,   187,   180,
     189,   190,   191,     6,     7,   164,   165,   196,    39,    40,
      41,    42,    43,    44,   181,   174,   164,   165,   465,   466,
      51,    52,   181,   164,   165,   214,   473,     6,     7,   467,
     468,   702,   180,    65,   223,   224,    68,    65,    70,   180,
      68,    70,    70,   232,   550,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   175,
     692,   693,   694,   173,   180,   175,   164,   165,   175,    89,
      90,    91,    92,   180,   263,   264,   265,    97,   164,   165,
     100,    68,   180,   164,   165,   274,   275,   276,    68,   278,
     164,   165,   281,   282,   180,    65,   285,  1479,    68,   180,
    1482,   164,   165,  1485,   164,   165,   180,   166,   167,   168,
     141,   142,   177,   619,   173,   180,   174,   180,   176,   308,
     180,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,  1428,   174,  1430,   176,  1432,
     164,   165,   177,   164,   165,   180,   620,   366,   164,   165,
     164,   165,   174,    65,  1566,   374,   180,    62,   377,   180,
      65,   181,   175,    68,   180,    70,   180,   180,   387,   181,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,    68,   659,   858,   661,   177,
     164,   165,   180,  1022,    65,  1607,  1025,  1026,  1610,   418,
     176,  1613,   178,   661,  1616,   424,   180,   183,     4,   177,
     429,   747,   180,    65,    68,   434,   435,   691,   692,   693,
     694,   440,   441,   174,     4,   176,   445,   174,   705,   176,
       4,   450,   451,   452,  1646,   712,  1648,     4,  1650,  1532,
       8,   718,   174,   174,   780,   176,   174,   174,   176,   176,
     174,   470,   471,   472,   473,   474,   475,   174,   174,   176,
     479,   480,   481,   482,   483,   174,   174,   176,   487,     6,
       6,   490,   491,   176,     4,   494,   495,   496,     4,   183,
     499,   500,   501,   174,   503,   176,   174,   178,   507,   174,
     181,  1584,   183,  1586,   174,  1588,   515,   174,   174,   176,
     176,  1594,   521,   522,   174,   174,   176,   780,    85,     4,
       5,  1242,  1243,   174,   174,   176,   176,   174,    95,   176,
       7,   540,   780,   174,   174,   544,   103,   104,   105,   548,
     174,   174,   109,   110,   111,   112,   174,   174,  1631,   176,
    1633,   174,  1635,   176,    39,    40,    41,    42,    43,    44,
     174,   174,   176,   176,   827,   174,    51,    52,     4,   181,
     833,   834,  1033,   181,   837,   838,   839,     6,   174,   827,
     176,   844,   174,     6,   176,   833,   834,   174,   181,   837,
     838,   839,     5,   174,   174,   176,   844,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,     6,   621,   174,   174,   173,   176,     4,   174,   882,
     176,   174,   174,   176,   891,   174,    39,    40,    41,    42,
      43,    44,   174,   180,   882,   182,   174,   181,    51,    52,
     180,   650,   182,   180,   653,   182,   655,   656,   176,   180,
     976,   182,   174,   174,   663,   664,   141,   142,   164,   165,
     166,   167,   168,   181,   197,   198,   199,   173,   677,   202,
     203,   204,   181,   940,   941,   942,   180,   686,   182,   180,
     174,   182,   691,   692,   693,   694,   171,   172,   181,   180,
     699,   182,   180,   178,   182,   181,   174,   706,   707,   180,
    1026,   182,  1423,   712,   174,   238,   239,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   725,   250,   251,   728,
     173,     6,   180,  1184,   182,   174,   181,    85,   141,   142,
     180,    68,   182,    70,   743,   181,   745,    95,    68,   181,
      70,   750,   751,   752,   753,   103,   104,   105,   180,   758,
     182,   109,   110,   111,   112,   180,   765,   182,   767,   768,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   180,   176,   182,   192,   173,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     180,  1055,   182,     5,   173,   804,   805,   180,   213,   182,
     180,   216,   182,   180,   180,   182,   182,   176,    12,    13,
     176,   820,   821,   822,   823,   824,   825,   180,   180,   182,
     182,   830,   176,   832,   182,   240,     5,   180,  1154,   182,
     180,     5,   182,   842,   180,   180,   182,   182,   847,   180,
       6,   182,   851,     4,   180,     6,   182,   180,  1115,   182,
       6,   178,   861,   862,   863,   864,     6,   866,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,   180,    73,
     182,   180,   128,   182,    78,    79,   181,    81,    82,    83,
     295,   296,   180,    87,   182,   180,   180,   182,   182,   180,
     305,   182,   180,   180,   182,   182,   180,   180,   182,   182,
     909,   180,   180,   182,   182,  1168,   180,   180,   182,   182,
       6,   180,  1176,   182,     6,     6,   120,   121,   122,   180,
    1168,   182,   180,   180,   182,   182,   180,   180,   182,   182,
    1391,   181,     6,   176,     4,   173,  1199,     4,  1202,   178,
     176,  1208,     7,     7,   181,     6,  1437,   182,  1274,     6,
       6,  1199,   174,     7,     7,   174,   174,   174,     7,   175,
       6,   970,     7,     6,   973,     7,   181,     6,     6,  1580,
       6,     4,     4,   181,  1238,   984,   181,  1244,   182,  1246,
     181,  1248,   181,   125,  1242,  1243,   181,   175,     6,     6,
     180,   180,   175,   175,   180,  1262,     6,     6,  1265,  1266,
      12,    13,   180,   180,   180,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,  1283,
     175,   180,   175,   173,     4,  1034,   183,     4,   177,     7,
       6,     6,     6,   128,     7,  1044,  1045,     7,     7,   128,
       7,     7,  1533,   128,     7,  1054,  1055,     7,   181,     4,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       6,    73,    85,   178,   182,   182,    78,    79,     6,    81,
      82,    83,    95,   177,     7,    87,     7,     7,   178,   181,
     103,   104,   105,  1092,  1093,  1094,   109,   110,   111,   112,
       6,   175,     6,  1102,   177,  1104,     6,     6,   176,     7,
       6,   174,   174,     6,   181,     7,  1115,     7,   120,   121,
     122,   180,     7,   161,  1123,     7,   185,    70,     7,     7,
     189,     7,     6,   175,     7,   180,     7,   196,   175,     7,
     185,   175,     7,     4,   189,   175,  1145,  1146,  1147,     6,
       4,   196,     7,     6,   181,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   182,
    1427,     6,  1429,   173,  1431,  1423,   174,     6,  1177,     7,
     182,     7,  1439,     7,   181,  1442,     6,     6,     6,     6,
       6,  1190,     4,    68,     4,     4,  1195,   182,     4,     6,
     175,     6,   180,  1202,   263,   177,   265,  1206,  1207,   178,
       7,     6,   617,   175,  1213,  1214,     6,   175,    78,  1218,
     175,     6,    85,   174,   178,     6,     6,  1226,     6,   181,
       6,     5,    95,   181,    85,   181,     4,  1236,   175,  1238,
     103,   104,   105,   181,    95,     6,   109,   110,   111,   112,
     181,  1250,   103,   104,   105,   181,     7,     7,   109,   110,
     111,   112,     7,  1262,     7,     7,   181,  1266,   181,   176,
    1269,     6,     6,     6,     6,   177,   181,    85,   181,  1536,
     181,     4,   687,   124,  1283,     6,     6,    95,     6,   180,
       6,  1545,  1546,   698,     6,   103,   104,   105,     4,     6,
       4,   109,   110,   111,   112,  1304,  1305,     6,     6,     6,
       6,     6,     6,  1312,     6,   374,    85,     6,   377,   182,
       5,   180,     6,   181,     6,   128,    95,  1580,     6,   374,
       6,   182,   377,     6,   103,   104,   105,     6,     6,     6,
     109,   110,   111,   112,     6,     6,  1599,  1346,     6,     6,
     175,     6,     6,     6,   181,     7,     6,   178,     6,   418,
       5,  1599,     6,    66,     6,  1364,     6,  1366,     6,   774,
       6,     6,     6,  1627,   182,     7,   123,   181,  1377,   181,
    1379,   182,   182,  1382,     6,  1638,     6,  1640,   181,   181,
     181,     6,   181,     6,   182,   126,  1395,     6,     6,     6,
    1638,  1400,  1640,  1657,     6,     6,   181,     6,  1661,     6,
       6,     6,   182,   182,   181,   181,     6,   181,     6,    85,
       4,  1420,     4,  1661,   182,     6,     6,     6,  1427,     6,
    1429,     6,  1431,     6,     6,   494,   495,   496,     6,     6,
     181,   181,  1441,   181,     6,     6,  1445,     6,     6,   494,
     495,   496,   181,     6,     6,    85,   515,  1456,  1457,     6,
       6,     6,  1461,   522,   181,    95,   181,   181,   181,     6,
     515,   181,  1471,   103,   104,   105,  1475,     6,     6,   109,
     110,   111,   112,     6,     6,     6,     6,     6,     6,     6,
     895,   896,    85,   898,  1052,   900,   901,   416,  1502,   904,
     905,  1060,    95,  1502,    12,    13,     3,     3,  1180,   444,
     103,   104,   105,    -1,  1513,    -1,   109,   110,   111,   112,
      -1,  1520,    -1,    -1,  1523,    -1,    -1,  1526,    -1,    -1,
      -1,  1530,    -1,    -1,    -1,  1534,    -1,  1536,    -1,    -1,
      -1,    -1,  1541,    -1,    -1,  1544,    -1,  1546,    -1,    -1,
      -1,    -1,   182,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    -1,    73,    -1,    -1,    -1,    -1,
      78,    79,    -1,    81,    82,    83,    -1,    -1,  1577,    87,
      -1,   986,   987,   988,  1583,    -1,    -1,    -1,    -1,   182,
      -1,   996,    -1,    -1,   653,    -1,   655,  1596,    -1,    -1,
      -1,    -1,    -1,    -1,   663,   664,    -1,    -1,   653,    -1,
     655,    -1,   120,   121,   122,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1625,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,     6,
     699,  1046,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   699,    -1,  1061,    -1,    -1,    -1,
      -1,    -1,  1067,    -1,    -1,    -1,    -1,    -1,  1073,    -1,
    1075,  1076,    -1,    -1,   182,  1080,    -1,    -1,    -1,     6,
    1085,  1086,  1087,    -1,   743,    -1,   745,    -1,    -1,    -1,
      -1,   750,   751,   752,   753,    -1,    -1,  1102,   743,   758,
     745,    -1,    -1,    -1,    -1,   750,   751,   752,   753,    -1,
      -1,    -1,  1117,   758,    -1,   182,  1121,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,  1173,    -1,
    1175,   830,    -1,   832,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   830,    -1,   832,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   861,   862,   863,   864,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   861,   862,   863,   864,
      -1,    -1,    -1,    -1,  1229,  1230,  1231,  1232,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,     6,    -1,
     909,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1264,
     140,    -1,    -1,    -1,   909,    -1,    -1,   147,   148,   149,
     150,    -1,  1277,    -1,    -1,    -1,    -1,    -1,    -1,  1284,
      -1,    -1,    -1,    -1,   164,   165,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,   179,
      -1,  1306,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,  1327,     3,     4,     5,   173,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,  1361,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    51,    52,    -1,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1399,    -1,    -1,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    -1,  1419,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1436,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    -1,    73,    -1,    -1,    -1,    -1,    78,    79,
      -1,    81,    82,    83,   134,    -1,    -1,    87,    -1,    -1,
     140,   141,   142,    -1,  1123,    -1,    -1,   147,   148,   149,
     150,     6,    -1,    -1,    -1,    -1,    -1,    -1,  1123,    -1,
      -1,    -1,  1487,    -1,   164,   165,    -1,    -1,    -1,   169,
     120,   121,   122,    -1,   174,    -1,   176,    -1,   178,   179,
      -1,   181,    -1,   183,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,  1543,    -1,
    1545,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,   182,    -1,    -1,    54,    55,    56,    -1,    -1,
      85,    -1,    -1,    62,    -1,    -1,    65,    -1,    -1,    68,
      95,    70,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,    -1,    -1,    82,   109,   110,   111,   112,    -1,    -1,
      89,    90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,
      -1,   100,    -1,  1262,    -1,    -1,    -1,  1266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1623,    -1,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    12,    13,    -1,    -1,   173,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,   182,    -1,    -1,
      -1,    12,    13,    -1,    -1,   164,   165,    -1,    -1,    -1,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,   182,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    -1,    73,    -1,    12,    13,    -1,
      78,    79,    -1,    81,    82,    83,    -1,  1366,    -1,    87,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    -1,    73,  1382,    -1,    -1,    -1,    78,    79,    -1,
      81,    82,    83,    -1,    -1,    -1,    87,  1382,    -1,    -1,
      -1,    -1,   120,   121,   122,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    -1,    73,    -1,
      -1,  1420,    -1,    78,    79,    -1,    81,    82,    83,   120,
     121,   122,    87,    -1,    -1,  1420,    -1,    -1,    -1,    -1,
      -1,    -1,  1441,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,  1441,    -1,    -1,   173,
      -1,    -1,    -1,    -1,   182,   120,   121,   122,    -1,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    51,    52,    -1,
      54,    55,    56,    -1,    -1,    -1,    -1,   182,    62,    12,
      13,    65,    -1,    -1,    68,  1534,    70,  1536,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,  1534,
      -1,  1536,    -1,    -1,    -1,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    97,    -1,    -1,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1577,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    -1,
      73,    -1,    -1,    -1,    -1,    78,    79,  1596,    81,    82,
      83,    -1,    -1,    -1,    87,    -1,   140,   141,   142,    -1,
      -1,  1596,    -1,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     164,   165,    -1,    -1,    -1,   169,    -1,   120,   121,   122,
     174,    -1,     3,     4,     5,   179,    -1,   181,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    -1,    -1,    85,   182,
      -1,    62,    -1,    -1,    65,    -1,    -1,    68,    95,    70,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,    -1,
      -1,    82,   109,   110,   111,   112,    -1,    -1,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    45,    46,    47,    -1,   147,   148,   149,   150,
      -1,    54,    55,    56,    -1,   182,    -1,    -1,    -1,    62,
      -1,    -1,    65,   164,   165,    68,    -1,    70,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,   179,    82,
     181,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    -1,    -1,    -1,    97,    -1,    -1,   100,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      45,    46,    47,    -1,   147,   148,   149,   150,    -1,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      65,   164,   165,    68,    -1,    70,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,   179,    82,   181,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    -1,    -1,   100,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,    45,    46,
      47,    -1,   147,   148,   149,   150,    -1,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    65,   164,
     165,    68,    -1,    70,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,   179,    82,   181,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    -1,    -1,    -1,
      97,    -1,    -1,   100,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    45,    46,    47,    -1,
     147,   148,   149,   150,    -1,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    65,   164,   165,    68,
      -1,    70,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,   179,    82,   181,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,
      -1,   100,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    45,    46,    47,    -1,   147,   148,
     149,   150,    -1,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    65,   164,   165,    68,    -1,    70,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
     179,    82,   181,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    45,    46,    47,    -1,   147,   148,   149,   150,
      -1,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    62,
      12,    13,    65,   164,   165,    68,    -1,    70,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,   179,    82,
     181,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      -1,    73,    -1,    -1,    -1,    -1,    78,    79,    -1,    81,
      82,    83,     6,    -1,    -1,    87,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   165,    -1,    -1,    -1,   169,    -1,   120,   121,
     122,   174,    -1,     3,     4,     5,   179,    -1,   181,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    51,    52,    -1,    54,    55,    56,     3,     4,     5,
     182,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    51,    52,    -1,    54,    55,
      56,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,   141,   142,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,   165,    85,    -1,    -1,   169,
      -1,    -1,    -1,    -1,   174,    -1,    95,    -1,    -1,   179,
      -1,   181,    -1,    -1,   103,   104,   105,    -1,    -1,     6,
     109,   110,   111,   112,   140,   141,   142,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,   165,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,   174,    -1,
       3,     4,     5,   179,    -1,   181,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   182,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    51,    52,
      -1,    54,    55,    56,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,
      95,    -1,    -1,    -1,   147,   148,   149,   150,   103,   104,
     105,    -1,    -1,    -1,   109,   110,   111,   112,    -1,    -1,
      -1,   164,   165,    -1,    -1,    -1,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,   179,    -1,   181,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   165,    -1,    -1,    -1,
     169,    -1,    -1,    -1,    -1,   174,    -1,   182,   177,    -1,
     179,    -1,   181,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,     3,     4,    -1,    54,    55,    56,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,
       3,     4,    54,    55,    56,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,    45,    46,    47,    -1,    -1,   147,   148,   149,
     150,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,   165,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,   174,    -1,    -1,   177,    -1,   179,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   164,   165,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,   174,    -1,    -1,    -1,    -1,   179,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   165,    -1,    -1,    -1,   169,    -1,    -1,    -1,
      -1,   174,    -1,     3,     4,    -1,   179,    -1,   181,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    56,    -1,    12,    13,
      -1,    -1,    62,    -1,    -1,    65,    -1,    -1,    68,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    -1,    73,
      -1,    -1,    -1,    -1,    78,    79,    -1,    81,    82,    83,
       6,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,   165,   120,   121,   122,   169,
       3,     4,     5,    -1,   174,    -1,     9,    10,    11,   179,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    12,    13,     6,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    51,    52,
      -1,    54,    55,    56,    -1,     6,    -1,    -1,   182,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,     7,     8,   173,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    -1,    73,     7,    -1,    -1,    -1,    78,
      79,    -1,    81,    82,    83,    -1,    -1,    -1,    87,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,     8,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,
      -1,   120,   121,   122,   147,   148,   149,   150,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   165,    -1,    -1,    -1,   169,     8,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,     8,    -1,
      -1,    -1,   173,   182,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,     8,    -1,
      -1,    -1,   173,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173,    -1,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    85,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
       0,     1,    -1,   173,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,    -1,    53,    -1,    -1,    -1,    57,    58,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,   114,     4,    -1,    -1,    -1,   119,
     120,   121,   122,    12,    13,   125,    -1,   127,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      -1,    -1,    -1,   143,   144,   145,   146,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    53,    -1,    -1,    -1,    57,    58,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,    -1,    -1,   125,    -1,   127,    -1,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,    -1,    -1,    -1,   143,   144,   145,   146,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,   180,    -1,   182,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,   180,    -1,   182,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,   180,
      -1,   182,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,   175,    -1,    -1,    -1,    -1,   180,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,   180,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,   180,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,   180,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,   180,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,   180,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   177,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   177,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     177,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   177,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   177,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,   177,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   177,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   177,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   177,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   177,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   177,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     177,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   177,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   177,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,   177,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   177,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   177,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   177,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   177,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   177,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     177,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   177,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   177,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,   177,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   177,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   177,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   177,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   177,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   177,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     177,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   177,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    -1,    -1,   173,    -1,   175,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,   175,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,   175,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
     175,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,   175,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,   175,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173,    -1,   175,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,   175,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,   175,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,   175,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    -1,    -1,   173,    -1,   175,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,   175,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,   175,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
     175,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,   175,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,   175,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173,    -1,   175,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,   175,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,   175,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,   175,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    -1,    -1,   173,    -1,   175,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,   175,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,   175,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
     175,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,   175,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,   175,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173,    -1,   175,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,   175,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,   175,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,   175,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    -1,    -1,   173,    -1,   175,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,   175,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,   175,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
     175,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,   175,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,   175,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173,    -1,   175,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,   175,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,   175,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,   175,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    -1,    -1,   173,    -1,   175,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,   175,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,   175,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
     175,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,   175,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,   175,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173,    -1,   175,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,   175,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,   175,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,   175,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    -1,    -1,   173,    -1,   175,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,   175,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,   175,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
     175,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,   175,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,   175,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   185,   186,     6,     0,     4,    12,    13,    37,
      38,    48,    49,    50,    53,    57,    58,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   106,   107,
     108,   114,   119,   120,   121,   122,   125,   127,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   143,
     144,   145,   146,   187,   189,   190,   208,   222,   227,   230,
     231,   232,   233,   234,   235,   236,   256,   257,   258,   259,
     275,   276,     3,     4,     5,     9,    10,    11,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    51,
      52,    54,    55,    56,   134,   140,   141,   142,   147,   148,
     149,   150,   164,   165,   169,   174,   176,   178,   179,   181,
     183,   260,   261,   272,   273,   276,    13,    68,   174,   174,
       6,   181,     6,     6,     6,     6,     6,   176,   176,   174,
     181,   174,   174,     4,   174,   181,   174,   174,     4,   181,
     174,   174,    72,    68,    68,     6,   181,    62,    65,    68,
      68,    68,    65,    68,    70,    70,    62,    65,    68,    70,
      65,    68,    70,    65,    68,   174,    65,   125,   138,   139,
     181,   164,   165,   174,   181,   262,   263,   262,   181,    62,
      65,    68,   181,   262,     4,    62,    66,    78,    68,    70,
      68,    65,     4,   134,   181,     4,     6,    62,    65,    68,
      65,    68,     4,     4,     4,     4,     5,    36,    62,    65,
      68,    70,    82,   165,   174,   181,   227,   236,   260,   265,
     266,   267,   276,     4,   174,   174,   174,     4,   181,   269,
       4,   174,   174,     6,     6,   176,     4,     4,     5,   181,
       5,   181,     4,   260,     6,   174,   181,   183,     7,   151,
     152,   153,   154,   171,   172,   206,   207,     4,   176,   178,
     174,   176,   174,   176,   174,   176,   174,   176,   174,   176,
     174,   176,   174,   176,   174,   176,   174,   176,   174,   176,
     174,   176,   174,   176,   174,   176,   174,   176,   174,   176,
     174,   176,   174,   176,   174,   176,   174,   176,   174,   176,
     174,   176,   174,   176,   174,   176,   174,   176,   174,   176,
     174,   174,   174,   174,   174,   174,     7,   174,   174,   174,
     174,   260,   260,   260,   181,   260,   177,   181,   260,     4,
     125,   126,     4,     4,   227,   228,   229,   181,     6,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   173,   181,     6,   207,     6,   260,     4,
     272,   273,   276,   272,   260,   210,   213,   260,   165,   260,
     267,   268,   260,   260,   174,   260,   268,   260,   260,   174,
     268,   260,   260,   265,   174,   181,   268,   266,   266,   266,
     174,   174,   266,   266,   266,   174,   223,   224,   225,   226,
     174,   174,   174,   265,   260,     4,   265,   269,   181,   181,
     262,   262,   262,   260,   260,   164,   165,   181,   181,   262,
     181,   181,   181,   164,   165,   174,   229,   262,   181,   174,
     181,   174,   174,   174,   266,   266,   265,   174,     4,     6,
     176,   176,   229,     6,   181,   181,   181,   266,   266,   176,
     176,   176,   174,   176,   178,   176,     5,   181,     5,     5,
       5,    62,    65,    68,    70,   181,   260,   267,   260,   182,
     268,     8,   166,     6,     6,   260,   260,   260,   178,   260,
     181,   128,   260,   260,   260,     6,     6,   229,     6,   229,
     176,     6,   265,   265,   181,   273,   265,     6,   176,   260,
       4,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   272,   274,   274,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   274,   260,   272,
     272,   272,     4,   276,   268,   175,     7,   206,   268,   177,
       7,   206,   207,   178,     7,   176,   182,    62,    65,    68,
      70,   222,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   191,     6,
     176,   178,   175,   180,   175,   180,   180,   177,   180,   209,
     177,   209,   175,   166,   180,   182,   175,   175,   260,   175,
     182,   175,   175,   260,   182,   175,   175,     7,   260,   260,
     182,     6,     6,     6,   260,   260,     7,     7,   254,   254,
     260,   174,   174,   174,   174,   260,   260,   260,     7,   181,
     175,     6,   181,   229,   229,   180,   180,   180,   262,   262,
     228,   228,   180,   260,   260,   260,   260,   240,   180,   229,
     260,   260,   260,   260,   260,     7,   255,     6,     7,   260,
       6,   260,   260,   182,   268,   268,   268,     6,     6,   260,
     260,   260,   175,   181,   177,   181,   260,     4,     4,   260,
     181,   181,   181,   181,   268,   175,   182,   260,   181,   260,
     267,   175,   175,   175,   125,   180,   229,   181,     8,   175,
     177,   182,   182,   175,   180,   182,   260,     6,     6,   260,
     177,   207,   175,   177,   175,   177,   175,   177,   175,   177,
     175,   177,   175,   177,   175,   177,   175,   177,   175,   177,
     175,   177,   175,   177,   180,   180,   175,   177,   175,   177,
     175,   177,   175,   177,   175,   177,   175,   177,   175,   177,
     180,   180,   180,   180,   180,   180,   175,   180,   177,   175,
     180,   177,   180,   180,   180,   175,   175,   180,   180,   180,
     175,     6,   180,   175,   180,   175,   182,   206,   265,   182,
     178,   206,   207,   273,   260,     6,     4,     4,   181,   270,
     177,   181,   181,   181,   181,   182,     8,     4,   115,   116,
     117,   118,   182,   194,   198,   201,   203,   204,   260,     4,
       6,   161,   188,   268,     6,   268,   260,     6,   276,     6,
     272,     7,   260,   267,   128,     7,     7,   175,     7,   128,
       7,     7,   175,   128,     7,     7,   260,   175,   182,   181,
     175,   175,   260,   265,     4,   253,     6,   175,   219,   260,
     273,   219,   219,   219,   175,   175,   175,   265,   268,   178,
     229,   182,   182,   262,   260,   260,   182,   182,   260,   262,
     180,   180,   180,    85,    95,   103,   104,   105,   109,   110,
     111,   112,   250,   251,   262,   182,   237,   175,   182,   175,
     175,   175,   260,     6,   260,   175,   177,   177,   182,   182,
     182,   177,   177,   180,   268,   268,   177,   177,   182,   268,
     268,   268,   268,   182,     8,   268,     7,     7,     7,   178,
     260,   182,   260,   260,     7,   178,   181,   265,     6,   182,
     177,   178,   207,   272,   260,   260,   260,   260,   260,   260,
     260,   260,   272,   268,   268,   272,   272,   272,   272,   272,
     260,   272,   175,   260,     6,   177,     4,   125,   126,   260,
       6,     6,     6,     7,   176,   269,   271,     6,   268,   268,
     268,   268,   260,   195,   174,   174,   181,   205,     6,   177,
     161,   272,   175,   175,   180,     7,   262,    68,    70,   265,
     265,     7,   265,    68,    70,   265,   265,     7,    70,   265,
     265,     6,     7,     7,   268,     7,     7,    85,   252,     6,
       7,   175,   175,   175,   175,     7,     7,     7,     6,   182,
       4,   182,   180,   180,   180,   182,   182,   262,   262,   262,
       4,     6,   181,     6,   174,     6,   113,     6,   113,     6,
     113,     6,   113,   182,   251,   180,   250,     7,     6,     7,
       7,     7,     6,   181,     6,     6,     6,    68,   260,     6,
       6,   260,   182,   182,   178,   182,   182,   182,   182,   260,
     182,   265,   265,   265,     4,   180,     8,     8,   175,     4,
       4,   265,   182,     6,     4,     6,   175,   177,   175,   177,
     175,   177,   175,   177,   175,   177,   175,   177,   180,   175,
     175,   175,   175,   206,     6,   206,     7,   206,   207,   178,
       7,     6,   269,   260,   180,   182,   182,   182,   182,   182,
     174,   260,   260,   264,   265,   181,   178,     6,     6,   188,
       6,   260,   181,   260,   273,     6,   181,   181,    78,   221,
     221,   265,     6,   181,   181,     6,     6,   265,   181,     6,
       6,     5,   265,   182,   265,   265,     4,     6,   265,     7,
       7,     7,     7,   265,   265,   265,     7,     6,     7,   260,
     260,   260,   181,   181,   180,   182,   180,   182,   180,   182,
     176,   260,   265,   260,     6,     6,     6,     6,   260,   262,
     182,     5,   181,   265,   181,   181,   181,   265,   268,   181,
       6,   177,   175,   177,     4,     6,     6,   124,   260,   260,
     260,     6,     6,     7,   180,     6,   207,   272,   265,   265,
     273,   260,     6,     4,   270,     6,   177,   269,     6,     6,
       6,     6,   192,   260,   180,   180,   180,   182,   193,   260,
       4,   272,   180,   260,   273,   260,   260,   262,     6,     6,
       6,   260,   260,     6,   260,     5,     6,   181,     6,   128,
     220,   260,     6,   265,   265,   265,   265,     6,     4,     6,
       6,   260,   260,   273,   182,   175,   180,   182,   228,   228,
     262,     6,   241,   262,     6,   242,   262,     6,   243,   260,
     182,   180,   175,   182,   180,     6,   165,   262,     6,   264,
     262,   262,     6,   182,   260,     6,   265,   180,   182,     8,
     182,   175,   181,   260,   273,   265,   175,     6,     6,     6,
       6,     7,     6,   178,   175,   180,   260,   260,   265,   181,
     180,   182,     6,   260,   211,   212,   182,   182,   182,   182,
     182,     5,   264,    66,     6,     6,     6,     6,     6,   181,
     181,     6,     6,   181,   260,   182,   182,   180,   181,   180,
     181,   180,   181,   177,     6,   265,     7,   181,   260,   180,
     182,   180,   180,     6,   182,   123,   260,   260,   268,     6,
       6,   182,   269,   126,   196,   260,   180,   180,   264,   260,
       6,   180,   215,   217,     6,     6,     6,     6,     6,     6,
     182,   181,   264,   268,   228,   180,   182,   260,   262,   250,
     260,   262,   250,   260,   262,   250,     6,   180,   182,   265,
     229,   182,   262,     6,   268,   262,   260,   182,   182,   182,
       6,     6,   181,   260,   260,   182,   260,   180,   182,   216,
     180,   182,   218,   181,   260,   182,   182,   182,   260,   182,
     180,   182,   182,   180,   182,   182,   180,   182,   265,     6,
      85,   182,   238,   181,   180,   182,   180,     6,     6,   193,
     175,   180,     6,   181,   180,     4,     4,   260,   182,     6,
       6,   182,     6,   244,   260,     6,     6,   245,   260,     6,
       6,   246,   260,     6,   182,   260,   250,   229,   268,     6,
     262,   268,   182,   199,   260,   264,   260,   181,   265,   273,
     181,   260,   273,   180,   181,   182,   181,   182,   181,   182,
       6,     6,   182,   182,   239,   182,   180,   182,     6,   181,
     175,   182,   182,   214,   260,   274,   260,   250,     6,   247,
     250,     6,   248,   250,     6,   249,   250,     6,   268,     6,
     197,   272,   202,   181,     6,   180,   182,     7,   182,   182,
     182,   181,   182,   181,   182,   181,   182,   182,   180,   182,
     181,   264,   260,   273,     6,     6,   250,     6,   250,     6,
     250,     6,   272,     6,   200,   272,   182,     7,   182,   182,
     182,   180,   182,     6,   273,     6,     6,     6,   272,     6
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
#line 174 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 185 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 186 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 187 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 188 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 189 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 190 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 191 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 192 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 193 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 194 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 195 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 196 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 197 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 198 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 199 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 204 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 22:
#line 208 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 23:
#line 215 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 24:
#line 220 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 25:
#line 225 "Gmsh.y"
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

  case 26:
#line 239 "Gmsh.y"
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

  case 27:
#line 252 "Gmsh.y"
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

  case 28:
#line 265 "Gmsh.y"
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

  case 29:
#line 293 "Gmsh.y"
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

  case 30:
#line 307 "Gmsh.y"
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

  case 31:
#line 320 "Gmsh.y"
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

  case 32:
#line 333 "Gmsh.y"
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

  case 33:
#line 351 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 39:
#line 365 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 40:
#line 367 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 41:
#line 372 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 42:
#line 374 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 43:
#line 379 "Gmsh.y"
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

  case 44:
#line 483 "Gmsh.y"
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

  case 45:
#line 493 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 46:
#line 502 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 47:
#line 509 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 48:
#line 519 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    ;}
    break;

  case 49:
#line 528 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 50:
#line 537 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 51:
#line 544 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 52:
#line 554 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 53:
#line 562 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 54:
#line 572 "Gmsh.y"
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

  case 55:
#line 591 "Gmsh.y"
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

  case 56:
#line 610 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 57:
#line 616 "Gmsh.y"
    {
    ;}
    break;

  case 58:
#line 623 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 59:
#line 624 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 60:
#line 625 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 61:
#line 626 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 62:
#line 627 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 63:
#line 631 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 64:
#line 632 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 67:
#line 643 "Gmsh.y"
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

  case 68:
#line 705 "Gmsh.y"
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

  case 69:
#line 735 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (7)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (7)].c))){
	if(!(yyvsp[(5) - (7)].i)){
          gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (7)].c)]);
          s.list = true;
	  s.value.resize(index + 1, 0.);
	  s.value[index] = (yyvsp[(6) - (7)].d);
	}
	else
	  yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (7)].c));
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (7)].c)]);
        if(s.list){
          if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
          switch((yyvsp[(5) - (7)].i)){
          case 0 : s.value[index] = (yyvsp[(6) - (7)].d); break;
          case 1 : s.value[index] += (yyvsp[(6) - (7)].d); break;
          case 2 : s.value[index] -= (yyvsp[(6) - (7)].d); break;
          case 3 : s.value[index] *= (yyvsp[(6) - (7)].d); break;
          case 4 :
            if((yyvsp[(6) - (7)].d)) s.value[index] /= (yyvsp[(6) - (7)].d);
            else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (7)].c), index, (yyvsp[(6) - (7)].d));
            break;
          }
        }
        else
          yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (7)].c));
      }
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 70:
#line 770 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (7)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (7)].c))){
	if(!(yyvsp[(5) - (7)].i)){
          gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (7)].c)]);
          s.list = true;
	  s.value.resize(index + 1, 0.);
	  s.value[index] = (yyvsp[(6) - (7)].d);
	}
	else
	  yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (7)].c));
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (7)].c)]);
        if(s.list){
          if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
          switch((yyvsp[(5) - (7)].i)){
          case 0 : s.value[index] = (yyvsp[(6) - (7)].d); break;
          case 1 : s.value[index] += (yyvsp[(6) - (7)].d); break;
          case 2 : s.value[index] -= (yyvsp[(6) - (7)].d); break;
          case 3 : s.value[index] *= (yyvsp[(6) - (7)].d); break;
          case 4 :
            if((yyvsp[(6) - (7)].d)) s.value[index] /= (yyvsp[(6) - (7)].d);
            else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (7)].c), index, (yyvsp[(6) - (7)].d));
            break;
          }
        }
        else
          yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (7)].c));
      }
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 71:
#line 804 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (9)].l)) != List_Nbr((yyvsp[(8) - (9)].l))){
	yymsg(0, "Incompatible array dimensions in affectation");
      }
      else{
	if(!gmsh_yysymbols.count((yyvsp[(1) - (9)].c))){
	  if(!(yyvsp[(7) - (9)].i)){
            gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (9)].c)]);
            s.list = true;
	    for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
	      int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
	      s.value.resize(index + 1, 0.);
	      s.value[index] = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
	    }
	  }
	  else
	    yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (9)].c));
	}
	else{
          gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (9)].c)]);
          if(s.list){
            for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
              int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
              double d = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
              if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
              switch((yyvsp[(7) - (9)].i)){
              case 0 : s.value[index] = d; break;
              case 1 : s.value[index] += d; break;
              case 2 : s.value[index] -= d; break;
              case 3 : s.value[index] *= d; break;
              case 4 :
                if((yyvsp[(8) - (9)].l)) s.value[index] /= d;
                else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (9)].c), index, d);
                break;
              }
            }
          }
          else
            yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (9)].c));
        }
      }
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 72:
#line 852 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (9)].l)) != List_Nbr((yyvsp[(8) - (9)].l))){
	yymsg(0, "Incompatible array dimensions in affectation");
      }
      else{
	if(!gmsh_yysymbols.count((yyvsp[(1) - (9)].c))){
	  if(!(yyvsp[(7) - (9)].i)){
            gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (9)].c)]);
            s.list = true;
	    for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
	      int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
	      s.value.resize(index + 1, 0.);
	      s.value[index] = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
	    }
	  }
	  else
	    yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (9)].c));
	}
	else{
          gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (9)].c)]);
          if(s.list){
            for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
              int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
              double d = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
              if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
              switch((yyvsp[(7) - (9)].i)){
              case 0 : s.value[index] = d; break;
              case 1 : s.value[index] += d; break;
              case 2 : s.value[index] -= d; break;
              case 3 : s.value[index] *= d; break;
              case 4 :
                if((yyvsp[(8) - (9)].l)) s.value[index] /= d;
                else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (9)].c), index, d);
                break;
              }
            }
          }
          else
            yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (9)].c));
        }
      }
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 73:
#line 899 "Gmsh.y"
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

  case 74:
#line 914 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (6)].c)]);
        if(s.list){
          int index = (int)(yyvsp[(3) - (6)].d);
          if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
          s.value[index] += (yyvsp[(5) - (6)].i);
        }
        else
          yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (6)].c));
      }
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 75:
#line 930 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 76:
#line 939 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 77:
#line 945 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 78:
#line 954 "Gmsh.y"
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

  case 79:
#line 972 "Gmsh.y"
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

  case 80:
#line 990 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 81:
#line 999 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 82:
#line 1011 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 83:
#line 1016 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 84:
#line 1024 "Gmsh.y"
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

  case 85:
#line 1044 "Gmsh.y"
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

  case 86:
#line 1067 "Gmsh.y"
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

  case 87:
#line 1078 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 88:
#line 1086 "Gmsh.y"
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

  case 89:
#line 1108 "Gmsh.y"
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

  case 90:
#line 1131 "Gmsh.y"
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

  case 91:
#line 1157 "Gmsh.y"
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

  case 92:
#line 1178 "Gmsh.y"
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

  case 93:
#line 1190 "Gmsh.y"
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

  case 97:
#line 1208 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 98:
#line 1217 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 99:
#line 1226 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 100:
#line 1228 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c));
      std::vector<double> val(1, (yyvsp[(6) - (9)].d));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (9)].c));
    ;}
    break;

  case 101:
#line 1238 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 102:
#line 1247 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 103:
#line 1249 "Gmsh.y"
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

  case 105:
#line 1263 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 106:
#line 1271 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 107:
#line 1277 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 110:
#line 1289 "Gmsh.y"
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

  case 111:
#line 1300 "Gmsh.y"
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

  case 112:
#line 1315 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 115:
#line 1331 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 116:
#line 1339 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 117:
#line 1348 "Gmsh.y"
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

  case 118:
#line 1366 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 119:
#line 1370 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 120:
#line 1380 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 121:
#line 1384 "Gmsh.y"
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

  case 122:
#line 1396 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 123:
#line 1400 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 124:
#line 1410 "Gmsh.y"
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

  case 125:
#line 1433 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 126:
#line 1437 "Gmsh.y"
    {
      int num = (int)(yyvsp[(5) - (9)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT)){
	yymsg(0, "Physical point %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(8) - (9)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(8) - (9)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 127:
#line 1453 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	Vertex *v = FindPoint((int)d);
	if(v)
	  v->lc = (yyvsp[(5) - (6)].d);
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

  case 128:
#line 1475 "Gmsh.y"
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

  case 129:
#line 1493 "Gmsh.y"
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

  case 130:
#line 1514 "Gmsh.y"
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

  case 131:
#line 1532 "Gmsh.y"
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

  case 132:
#line 1562 "Gmsh.y"
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

  case 133:
#line 1592 "Gmsh.y"
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

  case 134:
#line 1610 "Gmsh.y"
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

  case 135:
#line 1628 "Gmsh.y"
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

  case 136:
#line 1654 "Gmsh.y"
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

  case 137:
#line 1672 "Gmsh.y"
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

  case 138:
#line 1690 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 139:
#line 1694 "Gmsh.y"
    {
      int num = (int)(yyvsp[(5) - (9)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE)){
	yymsg(0, "Physical line %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(8) - (9)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(8) - (9)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 140:
#line 1713 "Gmsh.y"
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

  case 141:
#line 1731 "Gmsh.y"
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

  case 142:
#line 1770 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 143:
#line 1776 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 144:
#line 1782 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 145:
#line 1789 "Gmsh.y"
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

  case 146:
#line 1814 "Gmsh.y"
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

  case 147:
#line 1839 "Gmsh.y"
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

  case 148:
#line 1856 "Gmsh.y"
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

  case 149:
#line 1876 "Gmsh.y"
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

  case 150:
#line 1909 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 151:
#line 1913 "Gmsh.y"
    {
      int num = (int)(yyvsp[(5) - (9)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(8) - (9)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(8) - (9)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    ;}
    break;

  case 152:
#line 1933 "Gmsh.y"
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

  case 153:
#line 1951 "Gmsh.y"
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

  case 154:
#line 1968 "Gmsh.y"
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

  case 155:
#line 1984 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 156:
#line 1988 "Gmsh.y"
    {
      int num = (int)(yyvsp[(5) - (9)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME)){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(8) - (9)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(8) - (9)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 157:
#line 2010 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 158:
#line 2015 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 159:
#line 2020 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 160:
#line 2025 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 161:
#line 2030 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 162:
#line 2035 "Gmsh.y"
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

  case 163:
#line 2058 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 164:
#line 2064 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 165:
#line 2074 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 166:
#line 2075 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 167:
#line 2080 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 168:
#line 2084 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 169:
#line 2088 "Gmsh.y"
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

  case 170:
#line 2111 "Gmsh.y"
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

  case 171:
#line 2134 "Gmsh.y"
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

  case 172:
#line 2157 "Gmsh.y"
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

  case 173:
#line 2185 "Gmsh.y"
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

  case 174:
#line 2206 "Gmsh.y"
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

  case 175:
#line 2233 "Gmsh.y"
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

  case 176:
#line 2254 "Gmsh.y"
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

  case 177:
#line 2275 "Gmsh.y"
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

  case 178:
#line 2295 "Gmsh.y"
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

  case 179:
#line 2407 "Gmsh.y"
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

  case 180:
#line 2426 "Gmsh.y"
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

  case 181:
#line 2465 "Gmsh.y"
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

  case 182:
#line 2573 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 183:
#line 2582 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 184:
#line 2588 "Gmsh.y"
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

  case 185:
#line 2603 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Meshes") || !strcmp((yyvsp[(2) - (3)].c), "All")){
        ClearProject();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Model")){
	GModel::current()->destroy();
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

  case 186:
#line 2631 "Gmsh.y"
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

  case 187:
#line 2648 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 188:
#line 2657 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 189:
#line 2671 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 190:
#line 2677 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 191:
#line 2683 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 192:
#line 2692 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 193:
#line 2701 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 194:
#line 2710 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 195:
#line 2724 "Gmsh.y"
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
      else{
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 196:
#line 2777 "Gmsh.y"
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

  case 197:
#line 2794 "Gmsh.y"
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

  case 198:
#line 2809 "Gmsh.y"
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

  case 199:
#line 2828 "Gmsh.y"
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

  case 200:
#line 2840 "Gmsh.y"
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

  case 201:
#line 2864 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 202:
#line 2868 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 203:
#line 2873 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 204:
#line 2880 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 205:
#line 2886 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 206:
#line 2891 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 207:
#line 2897 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 208:
#line 2905 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 209:
#line 2909 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 210:
#line 2913 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 211:
#line 2919 "Gmsh.y"
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
          if(List_Nbr((yyvsp[(9) - (16)].l)) != f.size()){
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

  case 212:
#line 2973 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    ;}
    break;

  case 213:
#line 2986 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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

  case 214:
#line 3003 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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

  case 215:
#line 3020 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (8)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (8)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (8)].d);
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[(5) - (8)].d) > (yyvsp[(7) - (8)].d))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    ;}
    break;

  case 216:
#line 3041 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(9) - (10)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (10)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (10)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (10)].d);
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[(9) - (10)].d) > 0. && (yyvsp[(5) - (10)].d) > (yyvsp[(7) - (10)].d)) || ((yyvsp[(9) - (10)].d) < 0. && (yyvsp[(5) - (10)].d) < (yyvsp[(7) - (10)].d)))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    ;}
    break;

  case 217:
#line 3062 "Gmsh.y"
    {
      if(ImbricatedLoop <= 0){
	yymsg(0, "Invalid For/EndFor loop");
	ImbricatedLoop = 0;
      }
      else{
	double step = LoopControlVariablesTab[ImbricatedLoop - 1][2];
        const char *name = LoopControlVariablesNameTab[ImbricatedLoop - 1];
        if(name){
          if(!gmsh_yysymbols.count(name))
            yymsg(0, "Unknown loop variable '%s'", name);
          else{
            gmsh_yysymbol &s(gmsh_yysymbols[name]);
            if(!s.list && s.value.size()){
              s.value[0] += step;
              LoopControlVariablesTab[ImbricatedLoop - 1][0] = s.value[0];
            }
            else
              yymsg(0, "Bad loop variable %s", name);
          }
        }
        else{
          LoopControlVariablesTab[ImbricatedLoop - 1][0] += step;
        }
	double x0 = LoopControlVariablesTab[ImbricatedLoop - 1][0];
	double x1 = LoopControlVariablesTab[ImbricatedLoop - 1][1];
        if((step > 0. && x0 <= x1) || (step < 0. && x0 >= x1)){
	  fsetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop - 1]);
	  gmsh_yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop - 1];
	}
	else
	  ImbricatedLoop--;
      }
    ;}
    break;

  case 218:
#line 3097 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 219:
#line 3105 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 220:
#line 3111 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 221:
#line 3118 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 222:
#line 3122 "Gmsh.y"
    {
    ;}
    break;

  case 223:
#line 3131 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 224:
#line 3139 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 225:
#line 3147 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 226:
#line 3155 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 227:
#line 3161 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 228:
#line 3169 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 229:
#line 3175 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 230:
#line 3183 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 231:
#line 3189 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 232:
#line 3197 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 233:
#line 3203 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 234:
#line 3211 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 235:
#line 3218 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 236:
#line 3225 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 237:
#line 3232 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 238:
#line 3239 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 239:
#line 3246 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 240:
#line 3253 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 241:
#line 3260 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 242:
#line 3267 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 243:
#line 3274 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 244:
#line 3280 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 245:
#line 3287 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 246:
#line 3293 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 247:
#line 3300 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 248:
#line 3306 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 249:
#line 3313 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 250:
#line 3319 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 251:
#line 3326 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 252:
#line 3332 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 253:
#line 3339 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 254:
#line 3345 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 255:
#line 3352 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 256:
#line 3358 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 257:
#line 3365 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 258:
#line 3371 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 259:
#line 3378 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 260:
#line 3384 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 261:
#line 3395 "Gmsh.y"
    {
    ;}
    break;

  case 262:
#line 3398 "Gmsh.y"
    {
    ;}
    break;

  case 263:
#line 3404 "Gmsh.y"
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

  case 264:
#line 3416 "Gmsh.y"
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

  case 265:
#line 3436 "Gmsh.y"
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

  case 266:
#line 3460 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 267:
#line 3465 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 268:
#line 3469 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 269:
#line 3473 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 270:
#line 3477 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, which has no requirement for the number of extrusion layers and meshes with body-centered vertices.");
    ;}
    break;

  case 271:
#line 3481 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, which has no requirement for the number of extrusion layers and meshes with body-centered vertices.");
    ;}
    break;

  case 272:
#line 3485 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 273:
#line 3489 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 274:
#line 3493 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 275:
#line 3497 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 276:
#line 3501 "Gmsh.y"
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

  case 277:
#line 3520 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 278:
#line 3532 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 279:
#line 3536 "Gmsh.y"
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

  case 280:
#line 3551 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 281:
#line 3555 "Gmsh.y"
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

  case 282:
#line 3571 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 283:
#line 3575 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 284:
#line 3580 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 285:
#line 3584 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 286:
#line 3591 "Gmsh.y"
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

  case 287:
#line 3647 "Gmsh.y"
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

  case 288:
#line 3717 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 289:
#line 3722 "Gmsh.y"
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

  case 290:
#line 3789 "Gmsh.y"
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
              yymsg(1, "Unknown region %d", (int)d);
          }
        }
        List_Delete((yyvsp[(2) - (3)].l));
      }
    ;}
    break;

  case 291:
#line 3825 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 292:
#line 3833 "Gmsh.y"
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

  case 293:
#line 3876 "Gmsh.y"
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

  case 294:
#line 3915 "Gmsh.y"
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

  case 295:
#line 3935 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(5) - (6)].l)) != List_Nbr((yyvsp[(3) - (6)].l))){
	yymsg(0, "Number of master (%d) different from number of slave (%d) lines",
              List_Nbr((yyvsp[(5) - (6)].l)), List_Nbr((yyvsp[(3) - (6)].l)));
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(5) - (6)].l), i, &d_master);
          List_Read((yyvsp[(3) - (6)].l), i, &d_slave);
          int j_master = (int)d_master;
          int j_slave  = (int)d_slave;
          Curve *c_slave = FindCurve(abs(j_slave));
          if(c_slave){
	    GModel::current()->getGEOInternals()->periodicEdges[j_slave] = j_master;
          }
          else{
            GEdge *ge = GModel::current()->getEdgeByTag(abs(j_slave));
            if(ge) ge->setMeshMaster(j_master);
            else yymsg(0, "Unknown line %d", j_slave);
          }
        }
      }
      List_Delete((yyvsp[(3) - (6)].l));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 296:
#line 3963 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(5) - (12)].l)) != List_Nbr((yyvsp[(10) - (12)].l))){
	yymsg(0, "Number of master surface edges (%d) different from number of "
              "slave (%d) edges", List_Nbr((yyvsp[(10) - (12)].l)), List_Nbr((yyvsp[(5) - (12)].l)));
      }
      else{
        int j_master = (int)(yyvsp[(8) - (12)].d);
        int j_slave = (int)(yyvsp[(3) - (12)].d);
        Surface *s_slave = FindSurface(abs(j_slave));
        if(s_slave){
	  GModel::current()->getGEOInternals()->periodicFaces[j_slave] = j_master;
          for (int i = 0; i < List_Nbr((yyvsp[(5) - (12)].l)); i++){
            double dm, ds;
            List_Read((yyvsp[(5) - (12)].l), i, &ds);
            List_Read((yyvsp[(10) - (12)].l), i, &dm);
	    GModel::current()->getGEOInternals()->periodicEdges[(int)ds] = (int)dm;
            s_slave->edgeCounterparts[(int)ds] = (int)dm;
          }
        }
        else{
          GFace *gf = GModel::current()->getFaceByTag(abs(j_slave));
          if(gf){
            gf->setMeshMaster(j_master);
            for (int i = 0; i < List_Nbr((yyvsp[(5) - (12)].l)); i++){
              double dm, ds;
              List_Read((yyvsp[(5) - (12)].l), i, &ds);
              List_Read((yyvsp[(10) - (12)].l), i, &dm);
              gf->edgeCounterparts[(int)ds] = (int)dm;
	      GEdge *ges = GModel::current()->getEdgeByTag(abs((int)ds));
	      ges->setMeshMaster((int)dm);
            }
          }
          else yymsg(0, "Unknown surface %d", j_slave);
        }
      }
      List_Delete((yyvsp[(5) - (12)].l));
      List_Delete((yyvsp[(10) - (12)].l));
    ;}
    break;

  case 297:
#line 4002 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s){
	setSurfaceEmbeddedPoints(s, (yyvsp[(3) - (10)].l));
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[(8) - (10)].d));
        if(gf){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            int iPoint;
            List_Read((yyvsp[(3) - (10)].l), i, &iPoint);
            GVertex *gv = GModel::current()->getVertexByTag(iPoint);
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

  case 298:
#line 4025 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s){
	setSurfaceEmbeddedCurves(s, (yyvsp[(3) - (10)].l));
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[(8) - (10)].d));
        if(gf){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            int iCurve;
            List_Read((yyvsp[(3) - (10)].l), i, &iCurve);
            GEdge *ge = GModel::current()->getEdgeByTag(iCurve);
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

  case 299:
#line 4048 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    ;}
    break;

  case 300:
#line 4052 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 301:
#line 4056 "Gmsh.y"
    {
      Volume *v = FindVolume((int)(yyvsp[(8) - (10)].d));
      if(v){
	setVolumeEmbeddedSurfaces(v, (yyvsp[(3) - (10)].l));
      }
      else{
        GRegion *gr = GModel::current()->getRegionByTag((int)(yyvsp[(8) - (10)].d));
        if(gr){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            int iSurface;
            List_Read((yyvsp[(3) - (10)].l), i, &iSurface);
            GFace *gf = GModel::current()->getFaceByTag(iSurface);
            if(gf)
              gr->addEmbeddedFace(gf);
            else
              yymsg(0, "Unknown surface %d", iSurface);
          }
        }
        else
          yymsg(0, "Unknown region %d", (int)(yyvsp[(8) - (10)].d));
      }
    ;}
    break;

  case 302:
#line 4079 "Gmsh.y"
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

  case 303:
#line 4118 "Gmsh.y"
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

  case 304:
#line 4157 "Gmsh.y"
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

  case 305:
#line 4178 "Gmsh.y"
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

  case 306:
#line 4199 "Gmsh.y"
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

  case 307:
#line 4226 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 308:
#line 4230 "Gmsh.y"
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

  case 309:
#line 4240 "Gmsh.y"
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

  case 310:
#line 4274 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 311:
#line 4275 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 312:
#line 4276 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 313:
#line 4281 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 314:
#line 4287 "Gmsh.y"
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

  case 315:
#line 4299 "Gmsh.y"
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

  case 316:
#line 4317 "Gmsh.y"
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

  case 317:
#line 4344 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 318:
#line 4345 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 319:
#line 4346 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 320:
#line 4347 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 321:
#line 4348 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 322:
#line 4349 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 323:
#line 4350 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 324:
#line 4351 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 325:
#line 4353 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 326:
#line 4359 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 327:
#line 4360 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 328:
#line 4361 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 329:
#line 4362 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 330:
#line 4363 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 331:
#line 4364 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 332:
#line 4365 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 333:
#line 4366 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 334:
#line 4367 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 335:
#line 4368 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 336:
#line 4369 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 337:
#line 4370 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 338:
#line 4371 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 339:
#line 4372 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 340:
#line 4373 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 341:
#line 4374 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 342:
#line 4375 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 343:
#line 4376 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 344:
#line 4377 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 345:
#line 4378 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 346:
#line 4379 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 347:
#line 4380 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 348:
#line 4381 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 349:
#line 4382 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 350:
#line 4383 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 351:
#line 4384 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 352:
#line 4385 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 353:
#line 4386 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 354:
#line 4387 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 355:
#line 4388 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 356:
#line 4389 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 357:
#line 4390 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 358:
#line 4391 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 359:
#line 4394 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 360:
#line 4395 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 361:
#line 4396 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 362:
#line 4397 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 363:
#line 4398 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 364:
#line 4399 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 365:
#line 4400 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 366:
#line 4401 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 367:
#line 4402 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 368:
#line 4403 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 369:
#line 4404 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 370:
#line 4405 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 371:
#line 4406 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 372:
#line 4407 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 373:
#line 4408 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 374:
#line 4409 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 375:
#line 4410 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 376:
#line 4411 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5);    ;}
    break;

  case 377:
#line 4412 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 378:
#line 4413 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 379:
#line 4414 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 380:
#line 4415 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 381:
#line 4424 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 382:
#line 4425 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 383:
#line 4426 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 384:
#line 4427 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 385:
#line 4428 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 386:
#line 4429 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 387:
#line 4430 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 388:
#line 4431 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 389:
#line 4432 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 390:
#line 4433 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 391:
#line 4438 "Gmsh.y"
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

  case 392:
#line 4455 "Gmsh.y"
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

  case 393:
#line 4473 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 394:
#line 4478 "Gmsh.y"
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

  case 395:
#line 4490 "Gmsh.y"
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

  case 396:
#line 4507 "Gmsh.y"
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

  case 397:
#line 4528 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 398:
#line 4533 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 399:
#line 4538 "Gmsh.y"
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

  case 400:
#line 4548 "Gmsh.y"
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

  case 401:
#line 4558 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 402:
#line 4563 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 403:
#line 4572 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 404:
#line 4577 "Gmsh.y"
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

  case 405:
#line 4604 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 406:
#line 4608 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 407:
#line 4612 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 408:
#line 4616 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 409:
#line 4620 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 410:
#line 4627 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 411:
#line 4631 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 412:
#line 4635 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 413:
#line 4639 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 414:
#line 4646 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 415:
#line 4651 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 416:
#line 4658 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 417:
#line 4663 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 418:
#line 4667 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 419:
#line 4672 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 420:
#line 4676 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 421:
#line 4684 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 422:
#line 4695 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 423:
#line 4699 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 424:
#line 4711 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 425:
#line 4719 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 426:
#line 4727 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 427:
#line 4734 "Gmsh.y"
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

  case 428:
#line 4744 "Gmsh.y"
    {
      // Returns the coordinates of a point and fills a list with it.
      // This allows to ensure e.g. that relative point positions are
      // always conserved
      Vertex *v = FindPoint((int)(yyvsp[(3) - (4)].d));
      (yyval.l) = List_Create(3, 1, sizeof(double));
      if(!v) {
	yymsg(0, "Unknown point '%d'", (int)(yyvsp[(3) - (4)].d));
	double d = 0.0;
	List_Add((yyval.l), &d);
	List_Add((yyval.l), &d);
	List_Add((yyval.l), &d);
      }
      else{
	List_Add((yyval.l), &v->Pos.X);
	List_Add((yyval.l), &v->Pos.Y);
	List_Add((yyval.l), &v->Pos.Z);
      }
    ;}
    break;

  case 429:
#line 4764 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 430:
#line 4768 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 431:
#line 4772 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 432:
#line 4776 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 433:
#line 4780 "Gmsh.y"
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
          std::map<int, std::vector<GEntity*> > groups[4];
          GModel::current()->getPhysicalGroups(groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups[0].find((int)num);
          if(it != groups[0].end()){
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

  case 434:
#line 4809 "Gmsh.y"
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
          std::map<int, std::vector<GEntity*> > groups[4];
          GModel::current()->getPhysicalGroups(groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups[1].find((int)num);
          if(it != groups[1].end()){
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

  case 435:
#line 4838 "Gmsh.y"
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
          std::map<int, std::vector<GEntity*> > groups[4];
          GModel::current()->getPhysicalGroups(groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups[2].find((int)num);
          if(it != groups[2].end()){
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

  case 436:
#line 4867 "Gmsh.y"
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
          std::map<int, std::vector<GEntity*> > groups[4];
          GModel::current()->getPhysicalGroups(groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups[3].find((int)num);
          if(it != groups[3].end()){
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

  case 437:
#line 4896 "Gmsh.y"
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

  case 438:
#line 4906 "Gmsh.y"
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

  case 439:
#line 4916 "Gmsh.y"
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

  case 440:
#line 4929 "Gmsh.y"
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

  case 441:
#line 4941 "Gmsh.y"
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

  case 442:
#line 4953 "Gmsh.y"
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

  case 443:
#line 4972 "Gmsh.y"
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

  case 444:
#line 4993 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 445:
#line 4998 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 446:
#line 5002 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 447:
#line 5006 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 448:
#line 5018 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 449:
#line 5022 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 450:
#line 5034 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 451:
#line 5041 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 452:
#line 5051 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 453:
#line 5055 "Gmsh.y"
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

  case 454:
#line 5070 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 455:
#line 5075 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 456:
#line 5082 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 457:
#line 5086 "Gmsh.y"
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

  case 458:
#line 5099 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 459:
#line 5107 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 460:
#line 5118 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 461:
#line 5122 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 462:
#line 5130 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 463:
#line 5136 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 464:
#line 5144 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 465:
#line 5152 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 466:
#line 5161 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 467:
#line 5169 "Gmsh.y"
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

  case 468:
#line 5183 "Gmsh.y"
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

  case 469:
#line 5197 "Gmsh.y"
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

  case 470:
#line 5209 "Gmsh.y"
    {
      int size = 0;
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

  case 471:
#line 5226 "Gmsh.y"
    {
      int size = 0;
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

  case 472:
#line 5242 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 473:
#line 5247 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 474:
#line 5251 "Gmsh.y"
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

  case 475:
#line 5271 "Gmsh.y"
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

  case 476:
#line 5293 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 477:
#line 5298 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 478:
#line 5304 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 479:
#line 5313 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 480:
#line 5326 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 481:
#line 5329 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 10853 "Gmsh.tab.cpp"
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


#line 5333 "Gmsh.y"


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
  else
    Msg::Warning("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
}

