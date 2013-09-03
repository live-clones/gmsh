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
     tFmod = 287,
     tModulo = 288,
     tHypot = 289,
     tList = 290,
     tPrintf = 291,
     tError = 292,
     tStr = 293,
     tSprintf = 294,
     tStrCat = 295,
     tStrPrefix = 296,
     tStrRelative = 297,
     tStrReplace = 298,
     tStrFind = 299,
     tStrCmp = 300,
     tTextAttributes = 301,
     tBoundingBox = 302,
     tDraw = 303,
     tToday = 304,
     tCpu = 305,
     tMemory = 306,
     tSyncModel = 307,
     tCreateTopology = 308,
     tCreateTopologyNoHoles = 309,
     tDistanceFunction = 310,
     tDefineConstant = 311,
     tUndefineConstant = 312,
     tPoint = 313,
     tCircle = 314,
     tEllipse = 315,
     tLine = 316,
     tSphere = 317,
     tPolarSphere = 318,
     tSurface = 319,
     tSpline = 320,
     tVolume = 321,
     tCharacteristic = 322,
     tLength = 323,
     tParametric = 324,
     tElliptic = 325,
     tRefineMesh = 326,
     tAdaptMesh = 327,
     tPlane = 328,
     tRuled = 329,
     tTransfinite = 330,
     tComplex = 331,
     tPhysical = 332,
     tCompound = 333,
     tPeriodic = 334,
     tUsing = 335,
     tPlugin = 336,
     tDegenerated = 337,
     tRecursive = 338,
     tRotate = 339,
     tTranslate = 340,
     tSymmetry = 341,
     tDilate = 342,
     tExtrude = 343,
     tLevelset = 344,
     tRecombine = 345,
     tSmoother = 346,
     tSplit = 347,
     tDelete = 348,
     tCoherence = 349,
     tIntersect = 350,
     tMeshAlgorithm = 351,
     tReverse = 352,
     tLayers = 353,
     tScaleLast = 354,
     tHole = 355,
     tAlias = 356,
     tAliasWithOptions = 357,
     tQuadTriAddVerts = 358,
     tQuadTriNoNewVerts = 359,
     tQuadTriSngl = 360,
     tQuadTriDbl = 361,
     tRecombLaterals = 362,
     tTransfQuadTri = 363,
     tText2D = 364,
     tText3D = 365,
     tInterpolationScheme = 366,
     tTime = 367,
     tCombine = 368,
     tBSpline = 369,
     tBezier = 370,
     tNurbs = 371,
     tNurbsOrder = 372,
     tNurbsKnots = 373,
     tColor = 374,
     tColorTable = 375,
     tFor = 376,
     tIn = 377,
     tEndFor = 378,
     tIf = 379,
     tEndIf = 380,
     tExit = 381,
     tAbort = 382,
     tField = 383,
     tReturn = 384,
     tCall = 385,
     tFunction = 386,
     tShow = 387,
     tHide = 388,
     tGetValue = 389,
     tGetEnv = 390,
     tGetString = 391,
     tHomology = 392,
     tCohomology = 393,
     tBetti = 394,
     tSetOrder = 395,
     tGMSH_MAJOR_VERSION = 396,
     tGMSH_MINOR_VERSION = 397,
     tGMSH_PATCH_VERSION = 398,
     tAFFECTDIVIDE = 399,
     tAFFECTTIMES = 400,
     tAFFECTMINUS = 401,
     tAFFECTPLUS = 402,
     tOR = 403,
     tAND = 404,
     tNOTEQUAL = 405,
     tEQUAL = 406,
     tGREATEROREQUAL = 407,
     tLESSOREQUAL = 408,
     UNARYPREC = 409,
     tMINUSMINUS = 410,
     tPLUSPLUS = 411
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
#define tFmod 287
#define tModulo 288
#define tHypot 289
#define tList 290
#define tPrintf 291
#define tError 292
#define tStr 293
#define tSprintf 294
#define tStrCat 295
#define tStrPrefix 296
#define tStrRelative 297
#define tStrReplace 298
#define tStrFind 299
#define tStrCmp 300
#define tTextAttributes 301
#define tBoundingBox 302
#define tDraw 303
#define tToday 304
#define tCpu 305
#define tMemory 306
#define tSyncModel 307
#define tCreateTopology 308
#define tCreateTopologyNoHoles 309
#define tDistanceFunction 310
#define tDefineConstant 311
#define tUndefineConstant 312
#define tPoint 313
#define tCircle 314
#define tEllipse 315
#define tLine 316
#define tSphere 317
#define tPolarSphere 318
#define tSurface 319
#define tSpline 320
#define tVolume 321
#define tCharacteristic 322
#define tLength 323
#define tParametric 324
#define tElliptic 325
#define tRefineMesh 326
#define tAdaptMesh 327
#define tPlane 328
#define tRuled 329
#define tTransfinite 330
#define tComplex 331
#define tPhysical 332
#define tCompound 333
#define tPeriodic 334
#define tUsing 335
#define tPlugin 336
#define tDegenerated 337
#define tRecursive 338
#define tRotate 339
#define tTranslate 340
#define tSymmetry 341
#define tDilate 342
#define tExtrude 343
#define tLevelset 344
#define tRecombine 345
#define tSmoother 346
#define tSplit 347
#define tDelete 348
#define tCoherence 349
#define tIntersect 350
#define tMeshAlgorithm 351
#define tReverse 352
#define tLayers 353
#define tScaleLast 354
#define tHole 355
#define tAlias 356
#define tAliasWithOptions 357
#define tQuadTriAddVerts 358
#define tQuadTriNoNewVerts 359
#define tQuadTriSngl 360
#define tQuadTriDbl 361
#define tRecombLaterals 362
#define tTransfQuadTri 363
#define tText2D 364
#define tText3D 365
#define tInterpolationScheme 366
#define tTime 367
#define tCombine 368
#define tBSpline 369
#define tBezier 370
#define tNurbs 371
#define tNurbsOrder 372
#define tNurbsKnots 373
#define tColor 374
#define tColorTable 375
#define tFor 376
#define tIn 377
#define tEndFor 378
#define tIf 379
#define tEndIf 380
#define tExit 381
#define tAbort 382
#define tField 383
#define tReturn 384
#define tCall 385
#define tFunction 386
#define tShow 387
#define tHide 388
#define tGetValue 389
#define tGetEnv 390
#define tGetString 391
#define tHomology 392
#define tCohomology 393
#define tBetti 394
#define tSetOrder 395
#define tGMSH_MAJOR_VERSION 396
#define tGMSH_MINOR_VERSION 397
#define tGMSH_PATCH_VERSION 398
#define tAFFECTDIVIDE 399
#define tAFFECTTIMES 400
#define tAFFECTMINUS 401
#define tAFFECTPLUS 402
#define tOR 403
#define tAND 404
#define tNOTEQUAL 405
#define tEQUAL 406
#define tGREATEROREQUAL 407
#define tLESSOREQUAL 408
#define UNARYPREC 409
#define tMINUSMINUS 410
#define tPLUSPLUS 411




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
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

// Static parser variables (accessible only in this file)
static std::map<std::string, std::string> gmsh_yystringsymbols;
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
#line 518 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 531 "Gmsh.tab.cpp"

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
#define YYLAST   8716

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  177
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  467
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1622

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   411

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   162,     2,   172,     2,   161,     2,     2,
     167,   168,   159,   157,   173,   158,   171,   160,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     153,     2,   154,   148,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   169,     2,   170,   166,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   174,     2,   175,   176,     2,     2,     2,
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
     145,   146,   147,   149,   150,   151,   152,   155,   156,   163,
     164,   165
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    47,    53,    59,    67,    75,    83,    93,
     100,   107,   114,   115,   118,   121,   124,   127,   130,   132,
     136,   138,   142,   143,   144,   155,   157,   161,   162,   176,
     178,   182,   183,   199,   208,   223,   224,   231,   233,   235,
     237,   239,   241,   243,   245,   251,   257,   262,   269,   277,
     285,   295,   305,   309,   316,   321,   328,   338,   345,   355,
     361,   370,   379,   391,   398,   408,   414,   422,   432,   442,
     454,   462,   472,   482,   483,   485,   486,   490,   496,   497,
     507,   513,   514,   524,   525,   529,   533,   539,   540,   543,
     547,   553,   557,   558,   561,   565,   569,   575,   577,   579,
     580,   586,   587,   590,   598,   599,   609,   616,   624,   629,
     637,   646,   655,   663,   671,   683,   692,   701,   702,   712,
     721,   731,   735,   740,   751,   759,   767,   776,   785,   798,
     799,   809,   818,   826,   835,   836,   846,   852,   864,   870,
     880,   890,   895,   905,   915,   917,   919,   920,   923,   930,
     937,   944,   951,   960,   971,   986,  1003,  1016,  1025,  1034,
    1041,  1056,  1061,  1068,  1075,  1079,  1084,  1090,  1097,  1101,
    1105,  1110,  1116,  1121,  1127,  1131,  1139,  1147,  1151,  1159,
    1163,  1166,  1169,  1172,  1175,  1191,  1194,  1197,  1200,  1203,
    1220,  1224,  1231,  1240,  1249,  1260,  1262,  1265,  1267,  1271,
    1276,  1278,  1284,  1296,  1310,  1311,  1319,  1320,  1334,  1335,
    1351,  1352,  1359,  1368,  1377,  1386,  1399,  1412,  1425,  1440,
    1455,  1470,  1471,  1484,  1485,  1498,  1499,  1512,  1513,  1530,
    1531,  1548,  1549,  1566,  1567,  1586,  1587,  1606,  1607,  1626,
    1628,  1631,  1637,  1645,  1655,  1658,  1661,  1664,  1668,  1671,
    1675,  1678,  1682,  1685,  1689,  1699,  1706,  1707,  1711,  1712,
    1714,  1715,  1718,  1719,  1722,  1730,  1737,  1746,  1752,  1756,
    1764,  1770,  1775,  1782,  1789,  1802,  1813,  1824,  1835,  1846,
    1857,  1862,  1867,  1870,  1874,  1881,  1883,  1885,  1887,  1890,
    1896,  1904,  1915,  1917,  1921,  1924,  1927,  1930,  1934,  1938,
    1942,  1946,  1950,  1954,  1958,  1962,  1966,  1970,  1974,  1978,
    1982,  1986,  1992,  1997,  2002,  2007,  2012,  2017,  2022,  2027,
    2032,  2037,  2042,  2049,  2054,  2059,  2064,  2069,  2074,  2079,
    2086,  2093,  2100,  2105,  2110,  2115,  2120,  2125,  2130,  2135,
    2140,  2145,  2150,  2155,  2162,  2167,  2172,  2177,  2182,  2187,
    2192,  2199,  2206,  2213,  2218,  2220,  2222,  2224,  2226,  2228,
    2230,  2232,  2234,  2236,  2238,  2244,  2249,  2254,  2257,  2263,
    2267,  2274,  2279,  2287,  2294,  2301,  2308,  2313,  2315,  2318,
    2321,  2325,  2329,  2341,  2351,  2359,  2367,  2369,  2373,  2375,
    2377,  2380,  2384,  2389,  2395,  2397,  2399,  2402,  2406,  2410,
    2416,  2421,  2424,  2427,  2430,  2433,  2439,  2445,  2451,  2457,
    2459,  2461,  2465,  2469,  2474,  2481,  2488,  2490,  2492,  2496,
    2500,  2510,  2518,  2520,  2526,  2530,  2537,  2539,  2543,  2545,
    2547,  2551,  2558,  2560,  2562,  2567,  2574,  2581,  2586,  2591,
    2600,  2605,  2610,  2615,  2620,  2627,  2634,  2636
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     178,     0,    -1,   179,    -1,     1,     6,    -1,    -1,   179,
     180,    -1,   183,    -1,   182,    -1,   201,    -1,   215,    -1,
     220,    -1,   224,    -1,   225,    -1,   226,    -1,   229,    -1,
     249,    -1,   250,    -1,   228,    -1,   227,    -1,   223,    -1,
     252,    -1,   154,    -1,   154,   154,    -1,    36,   167,   265,
     168,     6,    -1,    37,   167,   265,   168,     6,    -1,    36,
     167,   265,   168,   181,   265,     6,    -1,    36,   167,   265,
     173,   261,   168,     6,    -1,    37,   167,   265,   173,   261,
     168,     6,    -1,    36,   167,   265,   173,   261,   168,   181,
     265,     6,    -1,     4,   265,   174,   184,   175,     6,    -1,
     101,     4,   169,   253,   170,     6,    -1,   102,     4,   169,
     253,   170,     6,    -1,    -1,   184,   187,    -1,   184,   191,
      -1,   184,   194,    -1,   184,   196,    -1,   184,   197,    -1,
     253,    -1,   185,   173,   253,    -1,   253,    -1,   186,   173,
     253,    -1,    -1,    -1,     4,   188,   167,   185,   168,   189,
     174,   186,   175,     6,    -1,   265,    -1,   190,   173,   265,
      -1,    -1,   109,   167,   253,   173,   253,   173,   253,   168,
     192,   174,   190,   175,     6,    -1,   265,    -1,   193,   173,
     265,    -1,    -1,   110,   167,   253,   173,   253,   173,   253,
     173,   253,   168,   195,   174,   193,   175,     6,    -1,   111,
     174,   257,   175,   174,   257,   175,     6,    -1,   111,   174,
     257,   175,   174,   257,   175,   174,   257,   175,   174,   257,
     175,     6,    -1,    -1,   112,   198,   174,   186,   175,     6,
      -1,     7,    -1,   147,    -1,   146,    -1,   145,    -1,   144,
      -1,   165,    -1,   164,    -1,    56,   169,   203,   170,     6,
      -1,    57,   169,   206,   170,     6,    -1,     4,   199,   258,
       6,    -1,     4,   169,   170,   199,   258,     6,    -1,     4,
     169,   253,   170,   199,   253,     6,    -1,     4,   167,   253,
     168,   199,   253,     6,    -1,     4,   169,   174,   261,   175,
     170,   199,   258,     6,    -1,     4,   167,   174,   261,   175,
     168,   199,   258,     6,    -1,     4,   200,     6,    -1,     4,
     169,   253,   170,   200,     6,    -1,     4,     7,   266,     6,
      -1,     4,   171,     4,     7,   266,     6,    -1,     4,   169,
     253,   170,   171,     4,     7,   266,     6,    -1,     4,   171,
       4,   199,   253,     6,    -1,     4,   169,   253,   170,   171,
       4,   199,   253,     6,    -1,     4,   171,     4,   200,     6,
      -1,     4,   169,   253,   170,   171,     4,   200,     6,    -1,
       4,   171,   119,   171,     4,     7,   262,     6,    -1,     4,
     169,   253,   170,   171,   119,   171,     4,     7,   262,     6,
      -1,     4,   171,   120,     7,   263,     6,    -1,     4,   169,
     253,   170,   171,   120,     7,   263,     6,    -1,     4,   128,
       7,   253,     6,    -1,   128,   169,   253,   170,     7,     4,
       6,    -1,   128,   169,   253,   170,   171,     4,     7,   253,
       6,    -1,   128,   169,   253,   170,   171,     4,     7,   266,
       6,    -1,   128,   169,   253,   170,   171,     4,     7,   174,
     261,   175,     6,    -1,   128,   169,   253,   170,   171,     4,
       6,    -1,    81,   167,     4,   168,   171,     4,     7,   253,
       6,    -1,    81,   167,     4,   168,   171,     4,     7,   266,
       6,    -1,    -1,   173,    -1,    -1,   203,   202,     4,    -1,
     203,   202,     4,     7,   253,    -1,    -1,   203,   202,     4,
       7,   174,   253,   204,   208,   175,    -1,   203,   202,     4,
       7,   266,    -1,    -1,   203,   202,     4,     7,   174,   266,
     205,   210,   175,    -1,    -1,   206,   202,   265,    -1,   253,
       7,   266,    -1,   207,   173,   253,     7,   266,    -1,    -1,
     208,   209,    -1,   173,     4,   258,    -1,   173,     4,   174,
     207,   175,    -1,   173,     4,   266,    -1,    -1,   210,   211,
      -1,   173,     4,   253,    -1,   173,     4,   266,    -1,   173,
       4,   174,   267,   175,    -1,   253,    -1,   266,    -1,    -1,
     122,    62,   174,   253,   175,    -1,    -1,    73,   255,    -1,
      58,   167,   253,   168,     7,   255,     6,    -1,    -1,    77,
      58,   216,   167,   212,   168,     7,   258,     6,    -1,    67,
      68,   258,     7,   253,     6,    -1,    61,   167,   253,   168,
       7,   258,     6,    -1,    82,    61,   258,     6,    -1,    65,
     167,   253,   168,     7,   258,     6,    -1,    59,   167,   253,
     168,     7,   258,   214,     6,    -1,    60,   167,   253,   168,
       7,   258,   214,     6,    -1,   114,   167,   253,   168,     7,
     258,     6,    -1,   115,   167,   253,   168,     7,   258,     6,
      -1,   116,   167,   253,   168,     7,   258,   118,   258,   117,
     253,     6,    -1,    61,     4,   167,   253,   168,     7,   258,
       6,    -1,    78,    61,   167,   253,   168,     7,   258,     6,
      -1,    -1,    77,    61,   217,   167,   212,   168,     7,   258,
       6,    -1,    73,    64,   167,   253,   168,     7,   258,     6,
      -1,    74,    64,   167,   253,   168,     7,   258,   213,     6,
      -1,    12,    13,     6,    -1,    13,    64,   253,     6,    -1,
      69,    64,   167,   253,   168,     7,     5,     5,     5,     6,
      -1,    62,   167,   253,   168,     7,   258,     6,    -1,    63,
     167,   253,   168,     7,   258,     6,    -1,    64,     4,   167,
     253,   168,     7,   258,     6,    -1,    78,    64,   167,   253,
     168,     7,   258,     6,    -1,    78,    64,   167,   253,   168,
       7,   258,     4,   174,   257,   175,     6,    -1,    -1,    77,
      64,   218,   167,   212,   168,     7,   258,     6,    -1,    76,
      66,   167,   253,   168,     7,   258,     6,    -1,    66,   167,
     253,   168,     7,   258,     6,    -1,    78,    66,   167,   253,
     168,     7,   258,     6,    -1,    -1,    77,    66,   219,   167,
     212,   168,     7,   258,     6,    -1,    85,   255,   174,   221,
     175,    -1,    84,   174,   255,   173,   255,   173,   253,   175,
     174,   221,   175,    -1,    86,   255,   174,   221,   175,    -1,
      87,   174,   255,   173,   253,   175,   174,   221,   175,    -1,
      87,   174,   255,   173,   255,   175,   174,   221,   175,    -1,
       4,   174,   221,   175,    -1,    95,    61,   174,   261,   175,
      64,   174,   253,   175,    -1,    92,    61,   167,   253,   168,
     174,   261,   175,     6,    -1,   222,    -1,   220,    -1,    -1,
     222,   215,    -1,   222,    58,   174,   261,   175,     6,    -1,
     222,    61,   174,   261,   175,     6,    -1,   222,    64,   174,
     261,   175,     6,    -1,   222,    66,   174,   261,   175,     6,
      -1,    89,    73,   167,   253,   168,     7,   258,     6,    -1,
      89,    58,   167,   253,   168,     7,   174,   257,   175,     6,
      -1,    89,    73,   167,   253,   168,     7,   174,   255,   173,
     255,   173,   261,   175,     6,    -1,    89,    73,   167,   253,
     168,     7,   174,   255,   173,   255,   173,   255,   173,   261,
     175,     6,    -1,    89,    62,   167,   253,   168,     7,   174,
     255,   173,   261,   175,     6,    -1,    89,     4,   167,   253,
     168,     7,   258,     6,    -1,    89,     4,   167,   253,   168,
       7,     5,     6,    -1,    89,     4,   174,   253,   175,     6,
      -1,    89,     4,   167,   253,   168,     7,   174,   255,   173,
     255,   173,   261,   175,     6,    -1,    93,   174,   222,   175,
      -1,    93,   128,   169,   253,   170,     6,    -1,    93,     4,
     169,   253,   170,     6,    -1,    93,     4,     6,    -1,    93,
       4,     4,     6,    -1,   119,   262,   174,   222,   175,    -1,
      83,   119,   262,   174,   222,   175,    -1,   132,     5,     6,
      -1,   133,     5,     6,    -1,   132,   174,   222,   175,    -1,
      83,   132,   174,   222,   175,    -1,   133,   174,   222,   175,
      -1,    83,   133,   174,   222,   175,    -1,     4,   266,     6,
      -1,     4,     4,   169,   253,   170,   265,     6,    -1,     4,
       4,     4,   169,   253,   170,     6,    -1,     4,   253,     6,
      -1,    81,   167,     4,   168,   171,     4,     6,    -1,   113,
       4,     6,    -1,   126,     6,    -1,   127,     6,    -1,    52,
       6,    -1,    47,     6,    -1,    47,   174,   253,   173,   253,
     173,   253,   173,   253,   173,   253,   173,   253,   175,     6,
      -1,    48,     6,    -1,    53,     6,    -1,    54,     6,    -1,
      71,     6,    -1,    72,   174,   261,   175,   174,   261,   175,
     174,   257,   175,   174,   253,   173,   253,   175,     6,    -1,
     140,   253,     6,    -1,   121,   167,   253,     8,   253,   168,
      -1,   121,   167,   253,     8,   253,     8,   253,   168,    -1,
     121,     4,   122,   174,   253,     8,   253,   175,    -1,   121,
       4,   122,   174,   253,     8,   253,     8,   253,   175,    -1,
     123,    -1,   131,     4,    -1,   129,    -1,   130,     4,     6,
      -1,   124,   167,   253,   168,    -1,   125,    -1,    88,   255,
     174,   222,   175,    -1,    88,   174,   255,   173,   255,   173,
     253,   175,   174,   222,   175,    -1,    88,   174,   255,   173,
     255,   173,   255,   173,   253,   175,   174,   222,   175,    -1,
      -1,    88,   255,   174,   222,   230,   243,   175,    -1,    -1,
      88,   174,   255,   173,   255,   173,   253,   175,   174,   222,
     231,   243,   175,    -1,    -1,    88,   174,   255,   173,   255,
     173,   255,   173,   253,   175,   174,   222,   232,   243,   175,
      -1,    -1,    88,   174,   222,   233,   243,   175,    -1,    88,
      58,   174,   253,   173,   255,   175,     6,    -1,    88,    61,
     174,   253,   173,   255,   175,     6,    -1,    88,    64,   174,
     253,   173,   255,   175,     6,    -1,    88,    58,   174,   253,
     173,   255,   173,   255,   173,   253,   175,     6,    -1,    88,
      61,   174,   253,   173,   255,   173,   255,   173,   253,   175,
       6,    -1,    88,    64,   174,   253,   173,   255,   173,   255,
     173,   253,   175,     6,    -1,    88,    58,   174,   253,   173,
     255,   173,   255,   173,   255,   173,   253,   175,     6,    -1,
      88,    61,   174,   253,   173,   255,   173,   255,   173,   255,
     173,   253,   175,     6,    -1,    88,    64,   174,   253,   173,
     255,   173,   255,   173,   255,   173,   253,   175,     6,    -1,
      -1,    88,    58,   174,   253,   173,   255,   175,   234,   174,
     243,   175,     6,    -1,    -1,    88,    61,   174,   253,   173,
     255,   175,   235,   174,   243,   175,     6,    -1,    -1,    88,
      64,   174,   253,   173,   255,   175,   236,   174,   243,   175,
       6,    -1,    -1,    88,    58,   174,   253,   173,   255,   173,
     255,   173,   253,   175,   237,   174,   243,   175,     6,    -1,
      -1,    88,    61,   174,   253,   173,   255,   173,   255,   173,
     253,   175,   238,   174,   243,   175,     6,    -1,    -1,    88,
      64,   174,   253,   173,   255,   173,   255,   173,   253,   175,
     239,   174,   243,   175,     6,    -1,    -1,    88,    58,   174,
     253,   173,   255,   173,   255,   173,   255,   173,   253,   175,
     240,   174,   243,   175,     6,    -1,    -1,    88,    61,   174,
     253,   173,   255,   173,   255,   173,   255,   173,   253,   175,
     241,   174,   243,   175,     6,    -1,    -1,    88,    64,   174,
     253,   173,   255,   173,   255,   173,   255,   173,   253,   175,
     242,   174,   243,   175,     6,    -1,   244,    -1,   243,   244,
      -1,    98,   174,   253,   175,     6,    -1,    98,   174,   258,
     173,   258,   175,     6,    -1,    98,   174,   258,   173,   258,
     173,   258,   175,     6,    -1,    99,     6,    -1,    90,     6,
      -1,   105,     6,    -1,   105,   107,     6,    -1,   106,     6,
      -1,   106,   107,     6,    -1,   103,     6,    -1,   103,   107,
       6,    -1,   104,     6,    -1,   104,   107,     6,    -1,   100,
     167,   253,   168,     7,   258,    80,   253,     6,    -1,    80,
       4,   169,   253,   170,     6,    -1,    -1,    80,     4,   253,
      -1,    -1,     4,    -1,    -1,     7,   258,    -1,    -1,     7,
     253,    -1,    75,    61,   259,     7,   253,   245,     6,    -1,
      75,    64,   259,   247,   246,     6,    -1,    70,    64,   174,
     253,   175,     7,   258,     6,    -1,    75,    66,   259,   247,
       6,    -1,   108,   259,     6,    -1,    96,    64,   174,   261,
     175,   253,     6,    -1,    90,    64,   259,   248,     6,    -1,
      90,    66,   259,     6,    -1,    91,    64,   258,     7,   253,
       6,    -1,    79,    61,   258,     7,   258,     6,    -1,    79,
      64,   253,   174,   261,   175,     7,   253,   174,   261,   175,
       6,    -1,    58,   174,   261,   175,   122,    64,   174,   253,
     175,     6,    -1,    61,   174,   261,   175,   122,    64,   174,
     253,   175,     6,    -1,    58,   174,   261,   175,   122,    66,
     174,   253,   175,     6,    -1,    61,   174,   261,   175,   122,
      66,   174,   253,   175,     6,    -1,    64,   174,   261,   175,
     122,    66,   174,   253,   175,     6,    -1,    97,    64,   259,
       6,    -1,    97,    61,   259,     6,    -1,    94,     6,    -1,
      94,     4,     6,    -1,    94,    58,   174,   261,   175,     6,
      -1,   137,    -1,   138,    -1,   139,    -1,   251,     6,    -1,
     251,   174,   258,   175,     6,    -1,   251,   174,   258,   173,
     258,   175,     6,    -1,   251,   167,   258,   168,   174,   258,
     173,   258,   175,     6,    -1,   254,    -1,   167,   253,   168,
      -1,   158,   253,    -1,   157,   253,    -1,   162,   253,    -1,
     253,   158,   253,    -1,   253,   157,   253,    -1,   253,   159,
     253,    -1,   253,   160,   253,    -1,   253,   161,   253,    -1,
     253,   166,   253,    -1,   253,   153,   253,    -1,   253,   154,
     253,    -1,   253,   156,   253,    -1,   253,   155,   253,    -1,
     253,   152,   253,    -1,   253,   151,   253,    -1,   253,   150,
     253,    -1,   253,   149,   253,    -1,   253,   148,   253,     8,
     253,    -1,    14,   167,   253,   168,    -1,    15,   167,   253,
     168,    -1,    16,   167,   253,   168,    -1,    17,   167,   253,
     168,    -1,    18,   167,   253,   168,    -1,    19,   167,   253,
     168,    -1,    20,   167,   253,   168,    -1,    21,   167,   253,
     168,    -1,    22,   167,   253,   168,    -1,    24,   167,   253,
     168,    -1,    25,   167,   253,   173,   253,   168,    -1,    26,
     167,   253,   168,    -1,    27,   167,   253,   168,    -1,    28,
     167,   253,   168,    -1,    29,   167,   253,   168,    -1,    30,
     167,   253,   168,    -1,    31,   167,   253,   168,    -1,    32,
     167,   253,   173,   253,   168,    -1,    33,   167,   253,   173,
     253,   168,    -1,    34,   167,   253,   173,   253,   168,    -1,
      23,   167,   253,   168,    -1,    14,   169,   253,   170,    -1,
      15,   169,   253,   170,    -1,    16,   169,   253,   170,    -1,
      17,   169,   253,   170,    -1,    18,   169,   253,   170,    -1,
      19,   169,   253,   170,    -1,    20,   169,   253,   170,    -1,
      21,   169,   253,   170,    -1,    22,   169,   253,   170,    -1,
      24,   169,   253,   170,    -1,    25,   169,   253,   173,   253,
     170,    -1,    26,   169,   253,   170,    -1,    27,   169,   253,
     170,    -1,    28,   169,   253,   170,    -1,    29,   169,   253,
     170,    -1,    30,   169,   253,   170,    -1,    31,   169,   253,
     170,    -1,    32,   169,   253,   173,   253,   170,    -1,    33,
     169,   253,   173,   253,   170,    -1,    34,   169,   253,   173,
     253,   170,    -1,    23,   169,   253,   170,    -1,     3,    -1,
       9,    -1,    10,    -1,    11,    -1,   141,    -1,   142,    -1,
     143,    -1,    50,    -1,    51,    -1,     4,    -1,     4,   176,
     174,   253,   175,    -1,     4,   169,   253,   170,    -1,   172,
       4,   169,   170,    -1,     4,   200,    -1,     4,   169,   253,
     170,   200,    -1,     4,   171,     4,    -1,     4,   169,   253,
     170,   171,     4,    -1,     4,   171,     4,   200,    -1,     4,
     169,   253,   170,   171,     4,   200,    -1,   134,   167,   265,
     173,   253,   168,    -1,    44,   167,   265,   173,   265,   168,
      -1,    45,   167,   265,   173,   265,   168,    -1,    46,   167,
     267,   168,    -1,   256,    -1,   158,   255,    -1,   157,   255,
      -1,   255,   158,   255,    -1,   255,   157,   255,    -1,   174,
     253,   173,   253,   173,   253,   173,   253,   173,   253,   175,
      -1,   174,   253,   173,   253,   173,   253,   173,   253,   175,
      -1,   174,   253,   173,   253,   173,   253,   175,    -1,   167,
     253,   173,   253,   173,   253,   168,    -1,   258,    -1,   257,
     173,   258,    -1,   253,    -1,   260,    -1,   174,   175,    -1,
     174,   261,   175,    -1,   158,   174,   261,   175,    -1,   253,
     159,   174,   261,   175,    -1,   258,    -1,     5,    -1,   158,
     260,    -1,   253,   159,   260,    -1,   253,     8,   253,    -1,
     253,     8,   253,     8,   253,    -1,    58,   174,   253,   175,
      -1,    58,     5,    -1,    61,     5,    -1,    64,     5,    -1,
      66,     5,    -1,    77,    58,   174,   261,   175,    -1,    77,
      61,   174,   261,   175,    -1,    77,    64,   174,   261,   175,
      -1,    77,    66,   174,   261,   175,    -1,   220,    -1,   229,
      -1,     4,   169,   170,    -1,     4,   167,   168,    -1,    35,
     169,     4,   170,    -1,     4,   169,   174,   261,   175,   170,
      -1,     4,   167,   174,   261,   175,   168,    -1,   253,    -1,
     260,    -1,   261,   173,   253,    -1,   261,   173,   260,    -1,
     174,   253,   173,   253,   173,   253,   173,   253,   175,    -1,
     174,   253,   173,   253,   173,   253,   175,    -1,     4,    -1,
       4,   171,   119,   171,     4,    -1,   174,   264,   175,    -1,
       4,   169,   253,   170,   171,   120,    -1,   262,    -1,   264,
     173,   262,    -1,   266,    -1,     4,    -1,     4,   171,     4,
      -1,     4,   169,   253,   170,   171,     4,    -1,     5,    -1,
      49,    -1,   135,   167,   265,   168,    -1,   136,   167,   265,
     173,   265,   168,    -1,    40,   167,   265,   173,   265,   168,
      -1,    41,   167,   265,   168,    -1,    42,   167,   265,   168,
      -1,    43,   167,   265,   173,   265,   173,   265,   168,    -1,
      38,   167,   267,   168,    -1,    38,   169,   267,   170,    -1,
      39,   167,   265,   168,    -1,    39,   169,   265,   170,    -1,
      39,   167,   265,   173,   261,   168,    -1,    39,   169,   265,
     173,   261,   170,    -1,   265,    -1,   267,   173,   265,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   169,   169,   170,   175,   177,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   199,   203,   210,   215,   220,   234,   247,   260,   288,
     302,   313,   328,   333,   334,   335,   336,   337,   341,   343,
     348,   350,   356,   460,   355,   478,   485,   496,   495,   513,
     520,   531,   530,   547,   564,   587,   586,   600,   601,   602,
     603,   604,   608,   609,   615,   617,   619,   681,   711,   746,
     780,   828,   875,   890,   906,   915,   921,   930,   948,   966,
     975,   987,   992,  1000,  1020,  1043,  1054,  1062,  1084,  1107,
    1133,  1154,  1166,  1180,  1180,  1182,  1184,  1195,  1207,  1206,
    1218,  1230,  1229,  1243,  1245,  1253,  1259,  1266,  1267,  1271,
    1282,  1297,  1307,  1308,  1313,  1321,  1330,  1348,  1352,  1363,
    1366,  1379,  1382,  1392,  1416,  1415,  1435,  1457,  1475,  1496,
    1514,  1544,  1574,  1592,  1610,  1636,  1654,  1673,  1672,  1695,
    1713,  1752,  1758,  1764,  1771,  1796,  1821,  1838,  1857,  1892,
    1891,  1915,  1933,  1950,  1967,  1966,  1992,  1997,  2002,  2007,
    2012,  2017,  2040,  2046,  2057,  2058,  2063,  2066,  2070,  2093,
    2116,  2139,  2167,  2188,  2214,  2235,  2257,  2277,  2389,  2408,
    2446,  2555,  2564,  2570,  2585,  2613,  2630,  2639,  2653,  2659,
    2665,  2674,  2683,  2692,  2706,  2751,  2768,  2783,  2802,  2814,
    2838,  2842,  2847,  2854,  2860,  2865,  2871,  2875,  2879,  2884,
    2939,  2952,  2969,  2986,  3007,  3028,  3063,  3071,  3077,  3084,
    3088,  3097,  3105,  3113,  3122,  3121,  3136,  3135,  3150,  3149,
    3164,  3163,  3177,  3184,  3191,  3198,  3205,  3212,  3219,  3226,
    3233,  3241,  3240,  3254,  3253,  3267,  3266,  3280,  3279,  3293,
    3292,  3306,  3305,  3319,  3318,  3332,  3331,  3345,  3344,  3361,
    3364,  3370,  3382,  3402,  3426,  3431,  3435,  3439,  3443,  3447,
    3451,  3455,  3459,  3463,  3467,  3486,  3499,  3502,  3518,  3521,
    3538,  3541,  3547,  3550,  3557,  3613,  3683,  3688,  3755,  3791,
    3799,  3842,  3881,  3901,  3928,  3968,  3991,  4014,  4018,  4022,
    4045,  4084,  4129,  4133,  4143,  4178,  4179,  4180,  4184,  4190,
    4202,  4220,  4248,  4249,  4250,  4251,  4252,  4253,  4254,  4255,
    4256,  4263,  4264,  4265,  4266,  4267,  4268,  4269,  4270,  4271,
    4272,  4273,  4274,  4275,  4276,  4277,  4278,  4279,  4280,  4281,
    4282,  4283,  4284,  4285,  4286,  4287,  4288,  4289,  4290,  4291,
    4292,  4293,  4294,  4297,  4298,  4299,  4300,  4301,  4302,  4303,
    4304,  4305,  4306,  4307,  4308,  4309,  4310,  4311,  4312,  4313,
    4314,  4315,  4316,  4317,  4326,  4327,  4328,  4329,  4330,  4331,
    4332,  4333,  4334,  4338,  4359,  4378,  4396,  4408,  4425,  4446,
    4451,  4456,  4466,  4476,  4481,  4490,  4495,  4522,  4526,  4530,
    4534,  4538,  4545,  4549,  4553,  4557,  4564,  4569,  4576,  4581,
    4585,  4590,  4594,  4602,  4613,  4617,  4629,  4637,  4645,  4652,
    4662,  4682,  4686,  4690,  4694,  4698,  4727,  4756,  4785,  4814,
    4824,  4834,  4847,  4859,  4871,  4890,  4911,  4916,  4920,  4924,
    4936,  4940,  4952,  4959,  4969,  4973,  4988,  4993,  5000,  5004,
    5017,  5025,  5036,  5040,  5048,  5056,  5064,  5072,  5086,  5100,
    5112,  5129,  5145,  5150,  5154,  5174,  5196,  5201
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
  "tTanh", "tFabs", "tFloor", "tCeil", "tFmod", "tModulo", "tHypot",
  "tList", "tPrintf", "tError", "tStr", "tSprintf", "tStrCat",
  "tStrPrefix", "tStrRelative", "tStrReplace", "tStrFind", "tStrCmp",
  "tTextAttributes", "tBoundingBox", "tDraw", "tToday", "tCpu", "tMemory",
  "tSyncModel", "tCreateTopology", "tCreateTopologyNoHoles",
  "tDistanceFunction", "tDefineConstant", "tUndefineConstant", "tPoint",
  "tCircle", "tEllipse", "tLine", "tSphere", "tPolarSphere", "tSurface",
  "tSpline", "tVolume", "tCharacteristic", "tLength", "tParametric",
  "tElliptic", "tRefineMesh", "tAdaptMesh", "tPlane", "tRuled",
  "tTransfinite", "tComplex", "tPhysical", "tCompound", "tPeriodic",
  "tUsing", "tPlugin", "tDegenerated", "tRecursive", "tRotate",
  "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset",
  "tRecombine", "tSmoother", "tSplit", "tDelete", "tCoherence",
  "tIntersect", "tMeshAlgorithm", "tReverse", "tLayers", "tScaleLast",
  "tHole", "tAlias", "tAliasWithOptions", "tQuadTriAddVerts",
  "tQuadTriNoNewVerts", "tQuadTriSngl", "tQuadTriDbl", "tRecombLaterals",
  "tTransfQuadTri", "tText2D", "tText3D", "tInterpolationScheme", "tTime",
  "tCombine", "tBSpline", "tBezier", "tNurbs", "tNurbsOrder",
  "tNurbsKnots", "tColor", "tColorTable", "tFor", "tIn", "tEndFor", "tIf",
  "tEndIf", "tExit", "tAbort", "tField", "tReturn", "tCall", "tFunction",
  "tShow", "tHide", "tGetValue", "tGetEnv", "tGetString", "tHomology",
  "tCohomology", "tBetti", "tSetOrder", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tAFFECTDIVIDE",
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND",
  "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC", "tMINUSMINUS",
  "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'", "'#'", "','",
  "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems", "GeoFormatItem",
  "SendToFile", "Printf", "View", "Views", "ElementCoords",
  "ElementValues", "Element", "@1", "@2", "Text2DValues", "Text2D", "@3",
  "Text3DValues", "Text3D", "@4", "InterpolationMatrix", "Time", "@5",
  "NumericAffectation", "NumericIncrement", "Affectation", "Comma",
  "DefineConstants", "@6", "@7", "UndefineConstants", "Enumeration",
  "FloatParameterOptions", "FloatParameterOption", "CharParameterOptions",
  "CharParameterOption", "PhysicalId", "InSphereCenter", "CircleOptions",
  "Shape", "@8", "@9", "@10", "@11", "Transform", "MultipleShape",
  "ListOfShapes", "LevelSet", "Delete", "Colorify", "Visibility",
  "Command", "Loop", "Extrude", "@12", "@13", "@14", "@15", "@16", "@17",
  "@18", "@19", "@20", "@21", "@22", "@23", "@24", "ExtrudeParameters",
  "ExtrudeParameter", "TransfiniteType", "TransfiniteArrangement",
  "TransfiniteCorners", "RecombineAngle", "Constraints", "Coherence",
  "HomologyCommand", "Homology", "FExpr", "FExpr_Single", "VExpr",
  "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
  "ListOfDoubleOrAll", "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr",
  "ListOfColor", "RecursiveListOfColor", "StringExprVar", "StringExpr",
  "RecursiveListOfStringExprVar", 0
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
     395,   396,   397,   398,   399,   400,   401,   402,    63,   403,
     404,   405,   406,    60,    62,   407,   408,    43,    45,    42,
      47,    37,    33,   409,   410,   411,    94,    40,    41,    91,
      93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   177,   178,   178,   179,   179,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   181,   181,   182,   182,   182,   182,   182,   182,   183,
     183,   183,   184,   184,   184,   184,   184,   184,   185,   185,
     186,   186,   188,   189,   187,   190,   190,   192,   191,   193,
     193,   195,   194,   196,   196,   198,   197,   199,   199,   199,
     199,   199,   200,   200,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   202,   202,   203,   203,   203,   204,   203,
     203,   205,   203,   206,   206,   207,   207,   208,   208,   209,
     209,   209,   210,   210,   211,   211,   211,   212,   212,   213,
     213,   214,   214,   215,   216,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   217,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   218,
     215,   215,   215,   215,   219,   215,   220,   220,   220,   220,
     220,   220,   220,   220,   221,   221,   222,   222,   222,   222,
     222,   222,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   224,   224,   224,   224,   224,   225,   225,   226,   226,
     226,   226,   226,   226,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   229,   229,   229,   230,   229,   231,   229,   232,   229,
     233,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   234,   229,   235,   229,   236,   229,   237,   229,   238,
     229,   239,   229,   240,   229,   241,   229,   242,   229,   243,
     243,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   245,   245,   246,   246,
     247,   247,   248,   248,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   250,   250,   250,   251,   251,   251,   252,   252,
     252,   252,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   255,   255,   255,
     255,   255,   256,   256,   256,   256,   257,   257,   258,   258,
     258,   258,   258,   258,   259,   259,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   261,   261,   261,   261,
     262,   262,   262,   262,   263,   263,   264,   264,   265,   265,
     265,   265,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   267,   267
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     5,     7,     7,     7,     9,     6,
       6,     6,     0,     2,     2,     2,     2,     2,     1,     3,
       1,     3,     0,     0,    10,     1,     3,     0,    13,     1,
       3,     0,    15,     8,    14,     0,     6,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     4,     6,     7,     7,
       9,     9,     3,     6,     4,     6,     9,     6,     9,     5,
       8,     8,    11,     6,     9,     5,     7,     9,     9,    11,
       7,     9,     9,     0,     1,     0,     3,     5,     0,     9,
       5,     0,     9,     0,     3,     3,     5,     0,     2,     3,
       5,     3,     0,     2,     3,     3,     5,     1,     1,     0,
       5,     0,     2,     7,     0,     9,     6,     7,     4,     7,
       8,     8,     7,     7,    11,     8,     8,     0,     9,     8,
       9,     3,     4,    10,     7,     7,     8,     8,    12,     0,
       9,     8,     7,     8,     0,     9,     5,    11,     5,     9,
       9,     4,     9,     9,     1,     1,     0,     2,     6,     6,
       6,     6,     8,    10,    14,    16,    12,     8,     8,     6,
      14,     4,     6,     6,     3,     4,     5,     6,     3,     3,
       4,     5,     4,     5,     3,     7,     7,     3,     7,     3,
       2,     2,     2,     2,    15,     2,     2,     2,     2,    16,
       3,     6,     8,     8,    10,     1,     2,     1,     3,     4,
       1,     5,    11,    13,     0,     7,     0,    13,     0,    15,
       0,     6,     8,     8,     8,    12,    12,    12,    14,    14,
      14,     0,    12,     0,    12,     0,    12,     0,    16,     0,
      16,     0,    16,     0,    18,     0,    18,     0,    18,     1,
       2,     5,     7,     9,     2,     2,     2,     3,     2,     3,
       2,     3,     2,     3,     9,     6,     0,     3,     0,     1,
       0,     2,     0,     2,     7,     6,     8,     5,     3,     7,
       5,     4,     6,     6,    12,    10,    10,    10,    10,    10,
       4,     4,     2,     3,     6,     1,     1,     1,     2,     5,
       7,    10,     1,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     4,     2,     5,     3,
       6,     4,     7,     6,     6,     6,     4,     1,     2,     2,
       3,     3,    11,     9,     7,     7,     1,     3,     1,     1,
       2,     3,     4,     5,     1,     1,     2,     3,     3,     5,
       4,     2,     2,     2,     2,     5,     5,     5,     5,     1,
       1,     3,     3,     4,     6,     6,     1,     1,     3,     3,
       9,     7,     1,     5,     3,     6,     1,     3,     1,     1,
       3,     6,     1,     1,     4,     6,     6,     4,     4,     8,
       4,     4,     4,     4,     6,     6,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,     0,   220,     0,     0,
       0,   217,     0,     0,     0,     0,   305,   306,   307,     0,
       5,     7,     6,     8,     9,    10,    19,    11,    12,    13,
      18,    17,    14,    15,    16,     0,    20,   374,   383,   452,
      57,   375,   376,   377,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   453,   381,   382,     0,     0,     0,
       0,   378,   379,   380,    61,    60,    59,    58,     0,     0,
       0,    63,    62,     0,     0,     0,     0,   166,     0,     0,
       0,   312,     0,   448,     0,     0,     0,     0,   203,     0,
     205,   202,   206,   207,    95,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   208,     0,     0,     0,     0,     0,     0,     0,
     124,   137,   149,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     397,     0,     0,     0,     0,     0,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,     0,
     302,     0,     0,     0,     0,     0,     0,     0,   383,   415,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   429,
     430,   408,   414,     0,   409,     0,     0,     0,     0,   442,
       0,     0,     0,     0,     0,   200,   201,     0,     0,   216,
       0,   166,     0,   166,   383,     0,   308,     0,     0,     0,
       0,     0,     0,   387,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   315,   314,   316,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,   164,     0,    72,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,   194,   141,     0,
     449,     0,   448,     0,     0,    93,    93,     0,     0,   436,
     437,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     280,   280,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   166,   166,     0,   399,   398,
       0,     0,     0,     0,   166,   166,     0,     0,     0,     0,
       0,     0,     0,   230,     0,   166,     0,     0,     0,     0,
       0,   282,     0,     0,     0,     0,   184,     0,     0,     0,
     303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   421,     0,   422,   423,   424,     0,     0,     0,
       0,     0,   314,   416,     0,   410,     0,     0,     0,   288,
     199,     0,     0,     0,     0,     0,   166,     0,     0,     0,
       0,   218,   188,     0,   189,     0,     0,   210,     0,     0,
       0,     0,   389,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   466,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   313,    57,     0,     0,     0,    57,
       0,     0,     0,     0,     0,   161,     0,     0,     0,     0,
     167,    66,     0,   330,   329,   328,   327,   323,   324,   326,
     325,   318,   317,   319,   320,   321,   322,     0,   142,     0,
       0,     0,     0,     0,     0,     0,     0,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,   166,     0,
       0,     0,     0,     0,   401,   400,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,   291,     0,     0,   185,     0,     0,   181,
       0,     0,     0,   301,   300,     0,     0,   432,     0,   431,
       0,     0,   389,     0,     0,     0,     0,     0,     0,     0,
     313,   411,   418,     0,   319,   417,     0,     0,     0,     0,
       0,     0,     0,     0,   219,     0,   190,   192,     0,     0,
       0,     0,   385,   391,     0,   332,   353,   333,   354,   334,
     355,   335,   356,   336,   357,   337,   358,   338,   359,   339,
     360,   340,   361,   352,   373,   341,   362,     0,     0,   343,
     364,   344,   365,   345,   366,   346,   367,   347,   368,   348,
     369,     0,     0,     0,     0,     0,     0,   460,     0,   461,
     462,     0,   463,     0,     0,   457,   458,     0,     0,     0,
     396,    85,     0,   454,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,     0,     0,     0,   386,
       0,     0,     0,     0,     0,    42,     0,     0,     0,    55,
       0,    33,    34,    35,    36,    37,     0,   450,    23,    21,
       0,     0,    24,     0,     0,    64,    96,    65,   104,     0,
     438,   439,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,   281,   279,     0,   287,     0,     0,   117,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
     193,     0,     0,     0,   156,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,     0,   221,     0,     0,     0,     0,     0,     0,
     283,   290,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   385,   433,   420,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,     0,   186,     0,
       0,     0,     0,     0,     0,   309,     0,     0,   388,     0,
     384,     0,     0,     0,     0,     0,     0,     0,     0,   467,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,     0,     0,     0,     0,    73,    75,    77,     0,
       0,   446,     0,    83,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,    29,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,     0,     0,
       0,     0,     0,     0,     0,   285,     0,     0,     0,     0,
       0,     0,     0,     0,   293,     0,     0,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,     0,   264,
       0,   270,     0,   272,     0,   266,     0,   268,     0,   231,
     260,     0,     0,     0,   179,     0,     0,     0,   292,     0,
     183,   182,   304,     0,     0,    30,    31,     0,     0,     0,
     425,   426,   427,   428,   419,   413,     0,     0,     0,   443,
       0,     0,     0,   211,     0,     0,     0,     0,   196,   390,
     195,   342,   363,   349,   370,   350,   371,   351,   372,   464,
     465,   456,     0,   394,   395,   393,   455,     0,    69,     0,
      57,     0,     0,     0,     0,    68,     0,     0,     0,   444,
       0,     0,     0,     0,     0,     0,     0,     0,   406,     0,
       0,    25,    26,     0,    27,     0,     0,    97,   100,   123,
       0,     0,     0,     0,     0,     0,   127,     0,     0,   144,
     145,     0,     0,   129,   152,     0,     0,     0,     0,   119,
       0,   284,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   198,     0,     0,     0,     0,   166,   166,     0,   241,
       0,   243,     0,   245,     0,   408,     0,     0,   271,   273,
     267,   269,     0,     0,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   289,   435,   434,   390,   132,   133,
       0,     0,     0,     0,    86,    90,     0,     0,   310,   392,
       0,     0,     0,     0,     0,    80,     0,     0,    81,     0,
     447,   168,   169,   170,   171,     0,    38,     0,     0,     0,
       0,     0,    40,   451,     0,     0,    98,   101,     0,     0,
     122,   130,   131,   135,     0,     0,   146,     0,     0,   286,
       0,   139,     0,     0,   277,   151,     0,     0,     0,     0,
     136,     0,   147,   153,     0,     0,     0,     0,   405,     0,
     404,     0,     0,     0,   232,     0,     0,   233,     0,     0,
     234,     0,     0,     0,     0,     0,     0,     0,   178,     0,
       0,   177,     0,     0,     0,   172,     0,     0,     0,     0,
     441,     0,   213,   212,     0,     0,     0,     0,   459,    71,
      70,    76,    78,     0,    84,     0,    43,     0,     0,     0,
     407,     0,     0,     0,    28,     0,   107,   112,     0,     0,
       0,     0,     0,     0,     0,     0,   140,   125,   138,   150,
     155,     0,     0,    91,    92,   166,     0,   159,   160,     0,
       0,     0,     0,     0,     0,     0,   261,     0,     0,   166,
       0,     0,     0,     0,     0,   163,   162,     0,     0,     0,
       0,    87,    88,     0,     0,   445,     0,    39,     0,     0,
       0,    41,    56,     0,     0,     0,   295,   297,   296,   298,
     299,   143,     0,     0,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   275,     0,
       0,     0,   226,     0,     0,   173,     0,     0,     0,   440,
     214,     0,   311,    82,     0,     0,     0,     0,     0,     0,
      99,   108,     0,   102,   113,     0,     0,     0,     0,   157,
       0,   247,     0,     0,   249,     0,     0,   251,     0,     0,
       0,   262,     0,   222,     0,   166,     0,     0,     0,   134,
      89,     0,    47,     0,    53,     0,     0,     0,     0,     0,
     120,   148,   294,   402,   235,     0,     0,   242,   236,     0,
       0,   244,   237,     0,     0,   246,     0,     0,     0,   228,
       0,   176,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   111,     0,   114,   115,     0,     0,   253,     0,   255,
       0,   257,   263,   274,   227,   223,     0,     0,     0,     0,
      44,     0,    51,     0,     0,     0,   436,     0,     0,     0,
     238,     0,     0,   239,     0,     0,   240,     0,     0,   180,
       0,   174,     0,    45,     0,     0,   204,     0,   110,     0,
     116,     0,     0,     0,     0,     0,     0,     0,   229,     0,
       0,     0,     0,     0,     0,   105,   209,   248,     0,   250,
       0,   252,     0,   175,    46,    48,     0,    49,     0,     0,
       0,     0,     0,     0,     0,    54,   106,   254,   256,   258,
      50,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    80,   840,    81,    82,   617,  1255,  1261,
     831,   999,  1406,  1572,   832,  1525,  1606,   833,  1574,   834,
     835,  1003,   158,   293,    83,   628,   395,  1356,  1357,   396,
    1555,  1414,  1461,  1415,  1464,   876,  1283,  1163,   600,   423,
     424,   425,   426,   259,   366,   367,    86,    87,    88,    89,
      90,    91,   260,   914,  1484,  1546,   683,  1305,  1308,  1311,
    1505,  1509,  1513,  1561,  1564,  1567,   910,   911,  1034,   873,
     654,   692,    93,    94,    95,    96,   261,   161,   439,   220,
    1147,   262,   263,   264,   496,   271,   818,   992,   567,   392,
     568
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1208
static const yytype_int16 yypact[] =
{
    4862,     4,    76,  4961, -1208, -1208,  2615,     7,   -22,   -82,
     -78,    22,   205,   212,   240,   250,   -59,   118,  -129,    99,
     103,     5,   124,   130,     9,   161,   165,   252,   327,   355,
     407,   248,   366,   378,   265,   372,   214,   308,    95,   302,
     416,   -70,   312,    63,    63,   315,   218,    36,   143,   435,
     439,     8,    33,   444,   442,   101,   567,   579,  2787,   582,
     452,   458,   466,    11,    30, -1208,   470, -1208,   600,   603,
     471, -1208,   652,   667,    16,    17, -1208, -1208, -1208,  4672,
   -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208,
   -1208, -1208, -1208, -1208, -1208,    19, -1208, -1208,     2, -1208,
     762, -1208, -1208, -1208,   259,   436,   453,   461,   469,   474,
     490,   493,   494,   503,   511,   534,   543,   544,   575,   587,
     594,   595,   601,   605,   609,   610,   614,   512,   515,   516,
     519,   520,   528,   539, -1208, -1208, -1208,   700,   563,   564,
     572, -1208, -1208, -1208, -1208, -1208, -1208, -1208,  4672,  4672,
    4672, -1208, -1208,  4258,    97,    20,   739,   472,  3119,   752,
     568, -1208,   573,   759,   763,  4672,   419,   419, -1208,  4672,
   -1208, -1208, -1208, -1208, -1208, -1208,  4672,  4468,  4672,  4672,
     623,  4672,  4468,  4672,  4672,   627,  4468,  4672,  4672,  3119,
     632,   648, -1208,  4468,   642,   647,  2787,  2787,  2787,   656,
   -1208, -1208, -1208, -1208,   680,   681,   684,  3119,  4672,   785,
    3119,    11,   653,   663,    63,    63,    63,  4672,  4672,    84,
   -1208,    91,    63,   678,   694,   713,  4424,    94,     3,   721,
     729,   732,  2787,  2787,  3119,   733,    26,   650, -1208,   866,
   -1208,   736,   743,   756,  2787,  2787,   696,   734,   581, -1208,
     754,    18,   913,   926,   931,   502,  3285,  4672,  2233, -1208,
   -1208,  1675, -1208,   965, -1208,   969,  4672,  4672,  4672,   809,
    4672,   814,   861,  4672,  4672, -1208, -1208,  4672,   985, -1208,
     998, -1208,  1006, -1208,   533,  1020, -1208,  3119,  3119,   827,
    4672,  1013,   847, -1208,  1019,  4672,  4672,  4672,  4672,  4672,
    4672,  4672,  4672,  4672,  4672,  4672,  4672,  4672,  4672,  4672,
    4672,  4672,  4672,  4672,  4672,  4672,  4672,  4672,  4672,  4672,
    4672,  4672,  4672,  4672,  4672,  4672,  4672,  4672,  4672,  4672,
    4672,  4672,  4672,  4672,  4672,  4672,  4672,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,  4672,   419,
     419,   419,   898,   898,   898,  4468,  7395,    80,  4468,  6636,
     177,   897,  1058,   917,   935, -1208,   907,  5047,  1067, -1208,
   -1208,  4672,  4672,  4672,  4672,  4672,  4672,  4672,  4672,  4672,
    4672,  4672,  4672,  4672,  4672,  4672, -1208, -1208, -1208,  1154,
     615,  -102, -1208,   113,  5908,   -71,    49,  7416,  4468,  3904,
   -1208,   612,  7437,  7458,  4672,  7479,   622,  7500,  7521,  4672,
     640,  7542,  7563,  1084,  4672,  4672,   645,  4672,  4672,  1098,
    1103,  1103,  4672,   944,   945,   947,   948,  4672,  4672,  4672,
    1110,  5828,   950,  1113,   946, -1208, -1208,   -83, -1208, -1208,
    5934,  5960,    63,    63,   472,   472,    71,  4672,  4672,  4672,
    4424,  4424,  4672,  5047,   104, -1208,  4672,  4672,  4672,  4672,
    4672,  1114,  1116,  1117,  4672,  1121, -1208,  4672,  4672,   900,
   -1208,  4468,  4468,  4468,  1122,  1123,  4672,  4672,  -127,  4208,
    1131,  1137, -1208,  4672, -1208, -1208, -1208,   968,   970,   972,
     978,  4468,   898, -1208,  7584, -1208,   660,  4672,  3451, -1208,
   -1208,  7605,  7626,  7647,  1024,  5986, -1208,   983,  4576,  7668,
    6659, -1208, -1208,  1603, -1208,  1805,  4672, -1208,   991,   665,
    4672,  6682,   153,  4672, -1208,  7689,  6705,  7710,  6728,  7731,
    6751,  7752,  6774,  7773,  6797,  7794,  6820,  7815,  6843,  7836,
    6866,  7857,  6889,  7878,  6912,  7899,  6935,  6012,  6038,  7920,
    6958,  7941,  6981,  7962,  7004,  7983,  7027,  8004,  7050,  8025,
    7073,  6064,  6090,  6116,  6142,  6168,  6194, -1208,   117,    90,
     210,   190,   989,   993,   996,  1009,  1011,  1012,   211,  1774,
    1017,  1023,  1021,   670,    80, -1208,  3119,   671,   148,   762,
    4672,  1160,  1188,    14,  1025, -1208,    38,    13,    15,    41,
   -1208, -1208,  4595,  2046,  1866,   701,   701,   421,   421,   421,
     421,   457,   457,   898,   898,   898,   898,    23, -1208,  4672,
    1189,    27,  4468,  1192,  4468,  4672,  1194, -1208,  1197,  1196,
     419,  1198,  4468,  4468,  1081,  1199,  1202,  8046,  1203,  1082,
    1204,  1205,  8067,  1091,  1207,  1208,  4672,  8088,  5100,  1042,
    8109,  8130,  4672,  3119,  1216,  1218,  8151,  4628,  4628,  4628,
    4628,  8172,  8193,  8214,  3119,  4468,  1051, -1208, -1208,  1836,
    1926,    63,  4672,  4672, -1208, -1208,  1054,  1055,  4424,  6220,
    6246,  6272,  5882,   349,    63,  2650,  8235,  5128,  8256,  8277,
    8298,  4672,  1220, -1208,  4672,  8319, -1208,  7096,  7119, -1208,
     691,   698,   705, -1208, -1208,  7142,  7165, -1208,  4468, -1208,
    4468,  7188,   -27,  1062,  5156,  4468,  4468,  4468,  4468,   706,
   -1208, -1208,  4699,  4468,   898, -1208,  1226,  1227,  1228,  1065,
    4672,  2827,  4672,  4672, -1208,    29, -1208, -1208,  1064,  3119,
    1233,  7211,    39, -1208,  5184, -1208, -1208, -1208, -1208, -1208,
   -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208,
   -1208, -1208, -1208, -1208, -1208, -1208, -1208,  4672,  4672, -1208,
   -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208,
   -1208,  4672,  4672,  4672,  4672,  4672,  4672, -1208,   419, -1208,
   -1208,  4468, -1208,  4468,   419, -1208, -1208,   419,   419,   419,
   -1208, -1208,  4672, -1208,   419,  1074,  4672,  1237,  1075,    31,
    4672,  1238,  1241,  2004, -1208,  1242,  1079,    11,  1244, -1208,
    4468,  4468,  4468,  4468,  4672, -1208,  1085,  1086,  1080, -1208,
    1250, -1208, -1208, -1208, -1208, -1208,  7234, -1208, -1208,  1104,
     419,   229, -1208,   264,  6298, -1208,  1254, -1208, -1208,    63,
    3904, -1208,   744,  3119,  3119,  1257,  3119,   819,  3119,  3119,
    1261,  1206,  3119,  3119,  2181,  1262,  1266,  4468,  1267,  1269,
    4984, -1208, -1208,  1265, -1208,  1275,  1119,  8550, -1208,  1124,
    1125,  1126,  1282,  1283,  1284,  1289,   711,  1293,  2993, -1208,
   -1208,   116,  6324,  6350, -1208, -1208,  5212,   -12,    63,    63,
      63,  1294,  1295,  1142,  1315,  1132,    42,    45,    46,    47,
     398, -1208,   157, -1208,   349,  1316,  1318,  1319,  1321,  1339,
    8550, -1208,  2263,  1148,  1343,  1350,  1351,  1296,  4672,  1353,
    1365,   718,   719,   -68, -1208, -1208,   731,   741,   749,   753,
   -1208,  4672,   766,  3119,  3119,  3119,  1368,  6376, -1208,  4730,
     894,  1370,  1376,  3119,  1201, -1208,  1375,  1378, -1208,  1377,
   -1208,  8340,  7257,  8361,  7280,  8382,  7303,  8403,  7326, -1208,
     297,   236,  1219,  1213,  1222,  1223,  8424,  1224,    80,  2420,
   -1208,    80,   243,  1217,  1386,  2519, -1208, -1208, -1208,    11,
    4672, -1208,   769, -1208,   770,   773,   778,   782,  8550,  1229,
    4672,  4672,  3119,  1221, -1208,  1230, -1208,  1388,    40,  1392,
    4672,  3949,    44,  1225,  1231,  1330,  1330,  3119,  1400,  1234,
    1236,  1405,  1407,  3119,  1240,  1410,  1411, -1208,  1413,  3119,
     797,  3119,  3119,  1415,  1414, -1208,  3119,  1416,  1418,  1422,
    1423,  3119,  3119,  3119, -1208,  1424,   162, -1208,  4672,  4672,
    4672,  1248,  1260,  -103,   -89,    59,  1272, -1208,  3119, -1208,
    4672, -1208,  1429, -1208,  1430, -1208,  1432, -1208,  1436, -1208,
   -1208,  4424,   726,  2953, -1208,  1270,  1271,  3617, -1208,  4468,
   -1208, -1208, -1208,  1273,  2539, -1208, -1208,  1278,  1279,  1444,
   -1208, -1208, -1208, -1208,  8550, -1208,  1445,  1446,  1332, -1208,
    4672,  4672,  4672, -1208,  1448,   374,  1286,  1455, -1208,   484,
   -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208,
   -1208, -1208,   419, -1208, -1208, -1208, -1208,  3119, -1208,  3119,
     762,  4672,  1456,  1459,    14, -1208,  1458,  7349,    11, -1208,
    1460,  1462,  1463,  1466,  4672,  6402,  6428,   806, -1208,  4672,
    1461, -1208, -1208,   419, -1208,  6454,  4628,  8550, -1208, -1208,
    4672,  4672,    63,  1467,  1470,  1471, -1208,  4672,  4672, -1208,
   -1208,  1481,  4672, -1208, -1208,  1494,  1495,  1326,  1497,  1382,
    4672, -1208,  1499,  3119,  3119,  3119,  3119,  1504,   988,  1509,
    4672, -1208,  4628,  5240,  8445,  5016,   472,   472,    63,  1511,
      63,  1513,    63,  1529,  4672,   150,  1364,  8466, -1208, -1208,
   -1208, -1208,  5268,   204, -1208,  1533,  2052,  1537,  3119,    63,
    2052,  1538,   822,  4672, -1208, -1208, -1208,   -27, -1208, -1208,
    3119,  5044,   198,  8487, -1208, -1208,  3998,  3119, -1208, -1208,
    1379,  1543,  1544,  1547,  3399, -1208,  1549,  1548, -1208,  1387,
   -1208, -1208, -1208, -1208, -1208,   299,  8550,  4672,  4672,  3119,
    1383,   832,  8550, -1208,  1553,  4672,  8550, -1208,  5296,  5324,
     324, -1208, -1208, -1208,  5352,  5380, -1208,  5408,  1556, -1208,
    3119, -1208,  1501,  1559,  8550, -1208,  1562,  1567,  1573,  1574,
   -1208,  1417, -1208, -1208,  5855,  3418,  1575,  1419, -1208,  4672,
   -1208,  1412,  1420,   254, -1208,  1425,   258, -1208,  1427,   260,
   -1208,  1428,  7372,  1576,  3119,  1578,  1431,  4672, -1208,  3783,
     263, -1208,   836,   283,   293, -1208,  1582,  5436,  1473,  4672,
   -1208,  4672, -1208, -1208,  4468,  3574,  1586,  1433, -1208, -1208,
   -1208, -1208, -1208,    11, -1208,  1474, -1208,  4672,  6480,  6506,
   -1208,  3119,  4672,  1591, -1208,  6532, -1208, -1208,  1597,  1600,
    1605,  1606,  1607,  1611,   845,  1435, -1208, -1208, -1208, -1208,
   -1208,  3119,  4468, -1208, -1208,   472,  5072, -1208, -1208,  4424,
     349,  4424,   349,  4424,   349,  1612, -1208,   849,  3119, -1208,
    5464,    63,  1613,  4468,    63, -1208, -1208,  4672,  5492,  5520,
     855, -1208, -1208,  1614,  1615, -1208,  1449,  8550,  4672,  4672,
     856,  8550, -1208,  4672,   859,   860, -1208, -1208, -1208, -1208,
   -1208, -1208,  1450,  4672,   883,   884,  1447,  4672, -1208,  5548,
     322,   990,  5576,   335,  1033,  5604,   404,  1050, -1208,  3119,
    1621,  1551,  3159,  1454,   412, -1208,   888,   454,  3731, -1208,
   -1208,  1623, -1208, -1208,  4672,  8508,  6558,    25,  6584,  1630,
   -1208, -1208,  1632, -1208, -1208,  4672,  5632,  1633,  1637, -1208,
    5660,  1639,  4672,  1640,  1642,  4672,  1643,  1644,  4672,  1645,
    1477, -1208,  4672, -1208,   349, -1208,  4468,  1647,  3783, -1208,
   -1208,   896, -1208,  4672, -1208,  3119,  4672,  2449,  4164,  6610,
   -1208, -1208, -1208, -1208, -1208,  1480,  5688, -1208, -1208,  1482,
    5716, -1208, -1208,  1483,  5744, -1208,  1649,  3750,  1180,  3325,
     899, -1208,   456,   903,  1652,  1485,  8529,   904,  5772,  2233,
   -1208, -1208,   419,  8550, -1208,  4672,   349,  1654,   349,  1667,
     349,  1668, -1208, -1208, -1208, -1208,   349,  1669,  4468,  1672,
   -1208,   419, -1208,  1510,  1680,   908,  1181,   912,  5800,  1264,
   -1208,  1514,  1380, -1208,  1516,  1391, -1208,  1520,  1408, -1208,
     924, -1208,   925, -1208,  1522,  3119, -1208,  4672, -1208,   762,
   -1208,  1681,  1691,   349,  1692,   349,  1694,   349, -1208,  1698,
     419,  1700,   419,   928,  1372, -1208, -1208, -1208,  1472, -1208,
    1663, -1208,  1868, -1208, -1208, -1208,   929, -1208,  1701,   762,
    1702,  1703,  1705,   419,  1706, -1208, -1208, -1208, -1208, -1208,
   -1208, -1208
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1208, -1208, -1208, -1208,   708, -1208, -1208, -1208, -1208,   266,
   -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208, -1208,
   -1208, -1208,  -331,    54, -1208,  1325, -1208, -1208, -1208, -1208,
   -1208, -1208, -1208, -1208, -1208,  -149, -1208,   709,  1723, -1208,
   -1208, -1208, -1208,     0,  -437,  -222, -1208, -1208, -1208, -1208,
   -1208, -1208,  1724, -1208, -1208, -1208, -1208, -1208, -1208, -1208,
   -1208, -1208, -1208, -1208, -1208, -1208,  -631,  -827, -1208, -1208,
    1307, -1208, -1208, -1208, -1208, -1208,   217, -1208,    21, -1208,
   -1207,   779,  -140,  1069,   635,  -209,   596, -1208,    -6,    -5,
    -333
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -452
static const yytype_int16 yytable[] =
{
     162,   163,   434,    85,   453,   569,   289,   676,   677,   180,
       4,  1322,   236,   185,   578,   269,   469,   180,   816,   185,
     164,   280,   282,   482,   360,   286,   586,   825,   168,   590,
     465,  1494,   466,   838,   272,   982,   951,   239,   176,   240,
     228,   707,   165,   390,    99,   177,  1152,   708,  1061,   211,
    1159,  1063,  1065,  1067,   442,   443,   419,   420,   421,   513,
     159,   515,   212,   213,   219,   221,   621,   227,   442,   443,
    1198,   622,  1199,  1364,   442,   443,     5,   125,   126,   127,
     128,   129,   130,  1070,  1200,   166,  1201,   585,   134,   167,
     671,   241,   461,   462,   229,   294,   151,   152,   230,   626,
      97,   284,   627,  1089,   474,   475,   101,   102,   103,   231,
     174,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   826,   827,   828,   829,   237,   151,   152,   361,
     362,   131,   132,   133,  1410,   442,   443,   135,   136,  1062,
     983,   984,  1064,  1066,  1068,   585,   207,   365,   497,   208,
     391,   393,   244,  1052,  1424,   245,   151,   152,  1191,  1192,
     456,   290,   181,   291,   139,   140,  -449,   457,   292,   182,
     181,   839,   238,   186,   589,   270,   287,   821,   817,   822,
     281,   283,   483,   288,   839,   467,   169,   273,   830,  1495,
     952,   442,   443,   151,   152,   176,  1331,   232,   188,   233,
     957,   170,   820,   669,   670,   823,   442,   443,   171,   629,
     215,   216,   627,   160,   144,   145,   146,   147,   442,   443,
     217,   138,  1202,   685,  1203,   437,   438,   218,   141,   142,
     143,   442,   443,   446,   678,  1070,   172,   454,   442,   443,
    1130,   442,   443,   806,   148,   149,   173,   810,   444,   150,
     789,   442,   443,   788,   257,   445,   178,   357,   455,   156,
     179,   358,   200,   442,   443,   201,   223,   684,   202,   224,
     203,   623,   225,  1072,   731,   787,   624,   175,  1527,  1048,
     788,   183,   144,   145,   146,   147,   285,   184,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   498,
     383,   384,   151,   152,   442,   443,   385,   151,   152,   809,
     189,   144,   145,   146,   147,  1313,   196,  -450,   187,   197,
    1071,   198,   188,   570,   571,   572,   573,   574,   575,   576,
     577,   151,   152,   580,   581,   582,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     792,   442,   443,   793,   385,   352,   353,   354,  1593,   204,
     356,   359,   205,  1332,   206,   215,   216,  1317,   790,   800,
    1235,  1236,   389,   791,   788,   217,   394,   144,   145,   146,
     147,   190,   226,   397,   399,   402,   403,  1008,   405,   399,
     407,   408,   633,   399,   411,   412,  1120,   151,   152,   633,
     399,   442,   443,   192,   591,   442,   443,   442,   443,   191,
     442,   443,   193,   390,    99,   431,   295,  1379,   296,   901,
     194,  1381,  1009,  1383,   440,   441,  1391,   633,   199,   902,
     442,   443,   195,   441,   365,   365,   888,   903,   904,   905,
     442,   443,   906,   907,   908,   909,  1393,   125,   126,   127,
     128,   129,   130,   674,   675,  1119,  1394,  1346,   134,   209,
     633,   438,  1347,   492,   494,   399,   364,   210,   901,   442,
     443,   442,   443,   501,   502,   503,   214,   505,   902,   222,
     508,   509,   442,   443,   510,  1472,   903,   904,   905,   234,
     235,   906,   907,   908,   909,   242,   243,   521,  1475,   879,
     880,   881,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   139,   140,    42,    43,    44,    45,
     487,   442,   443,   488,    50,   579,   489,    53,   490,   442,
     443,   246,   399,  1069,   370,   399,   743,  1478,   380,   381,
     382,   383,   384,   247,   812,  1486,   265,   385,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   297,  1070,   298,   275,  1070,   991,   276,
    1070,   442,   443,   442,   443,   492,   382,   383,   384,   266,
     299,   637,   300,   385,   848,   267,   642,  1488,   301,  1548,
     302,   647,   648,   268,   650,   651,   303,   274,   304,   656,
     277,   305,   811,   306,   661,   662,   663,  1127,   151,   152,
    1129,  1131,   878,   878,   878,   878,   278,   307,  -451,   308,
     309,   311,   310,   312,   679,   680,   681,   352,   353,   682,
     313,   279,   314,   686,   687,   688,   689,   690,   315,   341,
     316,   695,   342,   343,   697,   698,   344,   345,   399,   399,
     399,  1070,   891,   705,   706,   346,   711,   151,   152,   897,
     714,   317,   516,   318,   480,   912,   347,   348,   399,   292,
     319,   321,   320,   322,   722,   724,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     349,   350,  1070,   711,   385,  1070,   959,   741,  1070,   351,
     744,  1070,   323,   363,   324,   151,   152,   386,   478,  1431,
     479,  1434,   480,  1437,   325,   157,   326,   292,   369,  1301,
    1302,   327,   329,   328,   330,   387,   743,    99,   331,   388,
     332,  1070,   333,  1070,   334,  1070,   335,   337,   336,   338,
    1136,   339,   969,   340,   619,   633,   620,   634,   972,   432,
     404,   973,   974,   975,   409,   633,   958,   639,   977,   414,
     125,   126,   127,   128,   129,   130,   901,   813,  1013,   417,
    1014,   134,   401,   633,   418,   643,   902,   406,   633,   468,
     649,   410,   415,   422,   903,   904,   905,   435,   416,   906,
     907,   908,   909,   633,  1007,   721,   836,   436,   739,   399,
     740,   399,   844,   633,   633,   805,   808,   427,   428,   724,
     850,   429,   447,  1518,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   864,   633,   476,   926,   385,   448,   870,
    1012,   633,   470,   927,   877,   877,   877,   877,   633,   633,
     928,   940,   399,  1019,   633,  1020,  1045,   449,   458,   892,
     893,   633,   633,  1087,  1088,   896,   459,   139,   140,   460,
     464,  1214,  1102,   477,   633,  1559,  1090,  1562,   920,  1565,
     471,   922,     7,     8,   633,  1568,  1091,   472,   484,  1053,
    1054,  1055,   633,   481,  1092,   399,   633,   399,  1093,  1250,
     473,   485,   399,   399,   399,   399,   486,   368,  1426,   633,
     399,  1095,  1138,   633,  1139,  1140,   633,   947,  1141,   949,
     950,   633,  1598,  1142,  1600,   633,  1602,  1143,   596,    19,
      20,   597,    22,    23,   598,    25,   599,    27,   413,    28,
     633,   499,  1177,    32,    33,   500,    35,    36,    37,  1259,
     504,  1260,    40,   507,   961,   962,   430,   958,   506,   433,
     583,   511,  1291,   587,  1292,   633,   520,  1326,   963,   964,
     965,   966,   967,   968,   512,  1352,  1158,  1353,   399,  1259,
     399,  1392,   514,   463,    60,    61,    62,   522,  1259,   976,
    1422,   523,  1439,   979,  1440,   524,   517,   985,   633,  1259,
    1451,  1457,  1459,  1462,  1460,  1463,  1132,   399,   399,   399,
     399,   998,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,  1259,   633,  1467,  1468,
     385,   633,  1103,  1487,   385,   593,   518,   519,   592,  1352,
     901,  1524,   633,   601,  1547,   699,   633,  1259,  1549,  1553,
     902,  1577,   595,  1578,   399,   788,   594,  1580,   903,   904,
     905,   646,  1213,   906,   907,   908,   909,   633,  1590,  1589,
    1591,  1259,  1613,  1608,  1614,   652,   700,   701,   702,   157,
     653,   657,   658,   901,   659,   660,  1240,   664,   666,   667,
     668,   691,   693,   902,   694,  1243,   719,   696,   703,   704,
     901,   903,   904,   905,  1404,   712,   906,   907,   908,   909,
     902,   713,   715,   729,   716,  1084,   717,  1264,   903,   904,
     905,  1267,   718,   906,   907,   908,   909,   732,  1094,   738,
     618,   795,   794,  1239,   796,  1473,   814,  1442,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   797,  1270,   798,   799,   385,  1296,  1579,   497,
     802,   803,   815,   837,   804,   819,   365,   365,   842,  1557,
     845,   846,   847,   852,   857,   849,   853,  1137,  1476,   854,
     856,   858,   859,   861,   862,   863,   867,  1145,  1146,  1303,
     872,  1306,   887,  1309,   874,  1479,   921,  1155,  1157,   894,
     895,  1336,   934,   943,   944,   945,   946,  1320,   953,   955,
    1323,  1324,   978,   980,   986,   981,   400,   987,   990,   989,
     993,   400,  1000,  1001,  1002,   400,  1004,   841,  1006,   843,
     901,  1011,   400,  1519,  1017,  1193,  1194,  1195,  1023,  1028,
     902,  1035,  1024,  1029,  1031,  1205,  1032,  1207,   903,   904,
     905,  1239,  1036,   906,   907,   908,   909,  1037,  1212,  1041,
    1042,  1043,  1038,  1039,  1040,  1044,   399,  1046,  1056,  1060,
     886,  1057,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,  1058,  1231,  1232,  1233,
     385,  1059,  1079,  1073,  1074,   493,  1075,   400,  1076,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     632,   383,   384,   931,   901,   932,  1077,   385,  1244,  1080,
     936,   937,   938,   939,   902,  1544,  1081,  1082,   942,  1085,
    1083,  1256,   903,   904,   905,   807,  1262,   906,   907,   908,
     909,  1086,  1099,  1266,  1104,   365,  1107,  1268,  1269,  1609,
    1105,  1108,  1109,  1110,  1274,  1275,  1122,  1121,  1133,  1277,
    1123,  1124,  1126,  1134,  1151,  1149,  1144,  1284,  1154,  1160,
    1430,  1150,  1433,  1162,  1436,  1161,  1166,  1294,  1167,  1295,
    1168,  1169,  1444,  1170,  1172,  1447,  1173,  1174,  1175,  1180,
    1181,  1312,  1196,  1183,   400,  1184,   970,   400,   971,  1185,
    1186,  1190,   871,   399,  1197,  1208,  1209,   399,  1210,  1582,
    1327,  1204,  1211,   885,  1218,  1219,  1225,  1223,  1227,  1226,
    1230,  1228,  1229,  1335,  1234,   994,   995,   996,   997,  1237,
     901,  1238,  1245,  1246,  1248,  1263,  1251,   493,  1252,  1253,
     902,   901,  1254,  1271,  1348,  1349,  1272,  1273,   903,   904,
     905,   902,  1355,   906,   907,   908,   909,  1276,   901,   903,
     904,   905,  1531,  1534,   906,   907,   908,   909,   902,  1278,
    1280,  1279,  1030,  1281,  1282,  1285,   903,   904,   905,  1522,
    1290,   906,   907,   908,   909,  1293,  1376,  1304,   954,  1307,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,  1390,  1310,   492,  1314,   385,  1318,
     400,   400,   400,  1321,  1325,  1573,  1398,  1338,  1399,  1339,
    1340,   399,   901,  1341,  1344,  1584,  1343,  1351,  1345,  1354,
     400,  1363,   902,  1365,  1407,  1366,  1586,   725,  1367,  1411,
     903,   904,   905,  1368,  1595,   906,   907,   908,   909,  1369,
    1370,  1374,  1386,  1588,  1604,  1388,  1607,  1377,  1395,   399,
    1397,  1371,  1402,  1375,  1405,  1378,  1429,  1412,  1432,  1380,
    1435,  1382,  1384,  1416,  1616,  1389,  1417,  1620,  1403,  1423,
     399,  1418,  1419,  1420,  1448,     7,     8,  1421,  1438,  1445,
    1452,  1453,  1469,  1454,  1465,  1455,  1456,  1481,  1485,  1490,
    1458,  1482,  1015,  1016,  1497,  1018,  1498,  1021,  1022,  1501,
    1466,  1025,  1026,  1502,  1470,  1504,  1507,  1610,  1508,  1511,
    1512,  1515,  1516,  1521,  1536,  1542,  1538,  1540,  1550,  1551,
    1560,   596,    19,    20,   597,    22,    23,   598,    25,   599,
      27,  1262,    28,  1563,  1566,  1569,    32,    33,  1571,    35,
      36,    37,  1499,   497,  1575,    40,  1576,  1596,  1583,  1506,
    1585,   400,  1510,   400,  1587,  1514,  1592,  1597,  1599,  1517,
    1601,   725,   851,   399,  1603,   399,  1605,  1615,  1617,  1618,
    1526,  1619,  1621,  1528,  1222,  1533,  1153,    60,    61,    62,
    1491,   630,  1096,  1097,  1098,  1164,    84,    92,   655,     0,
    1247,     0,  1106,     0,   400,     0,     0,     0,     0,     0,
       0,     0,     0,   901,     0,     0,  1556,     0,     0,     0,
       0,     0,  1558,   902,     0,     0,     0,     0,     0,     0,
       0,   903,   904,   905,     0,   399,   906,   907,   908,   909,
       0,     0,     0,     0,     0,     0,     0,   400,   736,   400,
     801,  1148,     0,     0,   400,   400,   400,   400,     0,     0,
       0,     0,   400,     0,  1594,     0,  1165,     0,     0,     0,
       0,     0,  1171,     0,     0,     0,     0,     0,  1176,     0,
    1178,  1179,     0,     0,     0,  1182,     0,     7,     8,     0,
    1187,  1188,  1189,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   498,   383,   384,  1206,  1611,     0,
       0,   385,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,  1217,     0,     0,     0,  1221,     0,     0,     0,
     400,     0,   400,   596,    19,    20,   597,    22,    23,   598,
      25,   599,    27,     0,    28,     0,     0,     0,    32,    33,
       0,    35,    36,    37,     0,     0,     0,    40,     0,   400,
     400,   400,   400,     0,   596,    19,    20,   597,    22,    23,
     598,    25,   599,    27,     0,    28,  1241,     0,  1242,    32,
      33,     0,    35,    36,    37,     0,     0,     0,    40,    60,
      61,    62,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   400,     0,     7,     8,
     385,     0,     0,     0,     0,     0,     0,     0,   901,     0,
      60,    61,    62,     0,     0,     0,     0,     0,   902,     0,
       0,     0,  1286,  1287,  1288,  1289,   903,   904,   905,  1400,
       0,   906,   907,   908,   909,     0,     0,     0,     0,     0,
     737,     0,     0,     0,   596,    19,    20,   597,    22,    23,
     598,    25,   599,    27,     0,    28,     0,  1148,     0,    32,
      33,     0,    35,    36,    37,     0,     0,  1425,    40,  1328,
     988,   889,     0,     0,     0,     0,  1337,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,  1446,     0,
       0,     0,   385,     0,     0,     0,     0,     0,  1350,     0,
      60,    61,    62,  1612,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,   248,     0,     0,  1148,
       0,   101,   102,   103,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   250,     0,     0,
       0,     0,     0,  1387,     0,     0,   131,   132,   133,     0,
       0,   890,   135,   136,     0,     0,     0,     0,     0,     0,
     251,     0,     0,   252,     0,     0,   253,     0,   254,     0,
       0,  1520,     0,  1523,     0,     0,     0,     0,     0,   255,
    1148,     0,     0,     0,     0,     0,    42,    43,    44,    45,
      46,     0,     0,     0,    50,     0,     0,    53,   400,     0,
    1148,     0,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,  1441,     0,     0,
     385,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1570,     0,     0,   138,  1027,     0,     0,
       0,     0,     0,   141,   142,   143,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,   450,
    1319,     0,   385,     0,   150,     0,     0,     0,  1480,   452,
       0,     0,     0,     0,   156,     0,   218,   495,     0,     0,
       0,     0,     0,     0,     0,     0,    97,   248,     0,     0,
       0,     0,   101,   102,   103,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   250,  1078,
       0,     0,     0,     0,  1148,     0,  1530,   131,   132,   133,
       0,     0,     0,   135,   136,   400,     0,     0,     0,   400,
       0,   251,     0,     0,   252,     0,     0,   253,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,     0,     0,     0,     0,     0,     0,    42,    43,    44,
      45,    46,     0,     0,     0,    50,     0,     0,    53,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,     0,     0,     0,  1148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
       0,     0,     0,     0,   141,   142,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   493,     0,
     148,   398,     0,     0,     0,   150,     0,     0,     0,     0,
     257,     0,     0,   400,     0,   156,     0,     0,   495,     0,
       0,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,  1128,     0,     0,   385,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,   248,    99,     0,     0,     0,   101,   102,
     103,     0,   400,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   250,     0,     0,   125,   126,   127,
     128,   129,   130,   131,   132,   133,     0,     0,   134,   135,
     136,     0,     0,     0,     0,     0,     0,   251,     0,     0,
     252,     0,     0,   253,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1135,   255,     0,     0,     0,
       0,     0,     0,    42,    43,    44,    45,    46,     0,     0,
       0,    50,     0,     0,    53,  1224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   400,     0,   400,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,   138,   139,   140,   385,     0,     0,     0,
     141,   142,   143,     0,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,     0,   148,   256,     0,     0,
       0,   150,     0,     0,     0,     0,   257,   400,    97,    98,
      99,   156,   100,  1529,   101,   102,   103,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,   125,   126,   127,   128,   129,   130,   131,
     132,   133,     7,     8,   134,   135,   136,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,   596,    19,
      20,   597,    22,    23,   598,    25,   599,    27,     0,    28,
       0,     0,     0,    32,    33,     0,    35,    36,    37,     0,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,     0,     0,     0,     0,   138,
     139,   140,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,     0,    60,    61,    62,     0,     0,     0,
       0,     0,   148,   149,     0,     0,     0,   150,     0,   151,
     152,     0,   153,     0,   154,     0,   155,   156,     0,   157,
      97,   248,   249,     0,     0,     0,   101,   102,   103,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   250,     0,     0,   913,     0,     0,     0,     0,
       0,   131,   132,   133,     0,     0,     0,   135,   136,     7,
       8,     0,     0,     0,     0,   251,     0,     0,   252,     0,
       0,   253,     0,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,     0,     0,     0,     0,
       0,    42,    43,    44,    45,    46,     0,     0,     0,    50,
       0,     0,    53,     0,     0,   596,    19,    20,   597,    22,
      23,   598,    25,   599,    27,     0,    28,     0,     0,     0,
      32,    33,     0,    35,    36,    37,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,     0,     0,     0,     0,   141,   142,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    61,    62,   148,   256,     0,     0,     0,   150,
       0,     0,     0,     0,   257,     0,    97,   248,  1215,   156,
       0,   258,   101,   102,   103,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   132,   133,
       0,     0,   948,   135,   136,     7,     8,     0,     0,     0,
       0,   251,     0,     0,   252,     0,     0,   253,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,     0,     0,     0,     0,     0,     0,    42,    43,    44,
      45,    46,     0,     0,     0,    50,     0,     0,    53,     0,
       0,   596,    19,    20,   597,    22,    23,   598,    25,   599,
      27,     0,    28,     0,     0,     0,    32,    33,     0,    35,
      36,    37,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
       0,     0,     0,     0,   141,   142,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    61,    62,
     148,   256,     0,     0,     0,   150,     0,     0,     0,     0,
     257,     0,    97,   248,     0,   156,     0,  1216,   101,   102,
     103,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   250,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   133,     0,     0,  1047,   135,
     136,     7,     8,     0,     0,     0,     0,   251,     0,     0,
     252,     0,     0,   253,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,     0,     0,     0,
       0,     0,     0,    42,    43,    44,    45,    46,     0,     0,
       0,    50,     0,     0,    53,     0,     0,   596,    19,    20,
     597,    22,    23,   598,    25,   599,    27,     0,    28,     0,
       0,     0,    32,    33,     0,    35,    36,    37,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,     0,     0,     0,     0,     0,     0,
     141,   142,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,    61,    62,   148,   256,     0,     0,
       0,   150,     0,     0,     0,     0,   257,     0,    97,   248,
       0,   156,     0,   258,   101,   102,   103,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     250,     0,     0,     0,     0,     0,     0,     0,     0,   131,
     132,   133,     0,     0,  1483,   135,   136,     7,     8,     0,
       0,     0,     0,   251,     0,     0,   252,     0,     0,   253,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,     0,     0,     0,     0,     0,     0,    42,
      43,    44,    45,    46,     0,     0,     0,    50,     0,     0,
      53,     0,     0,   596,    19,    20,   597,    22,    23,   598,
      25,   599,    27,     0,    28,     0,     0,     0,    32,    33,
       0,    35,    36,    37,     0,  1342,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,  1373,     0,   141,   142,   143,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      61,    62,   148,   398,     0,     0,     0,   150,     0,     0,
       0,     0,   257,     0,    97,   248,     0,   156,     0,   491,
     101,   102,   103,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   250,     0,     0,     0,
       0,     0,     0,     0,     0,   131,   132,   133,     0,     0,
    1545,   135,   136,     0,     0,     0,     0,     0,     0,   251,
       0,     0,   252,     0,     0,   253,     0,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,     0,
       0,     0,     0,     0,     0,    42,    43,    44,    45,    46,
       0,     0,     0,    50,     0,     0,    53,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
    1401,     0,     0,     0,   385,   138,     0,     0,     0,     0,
       0,     0,   141,   142,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   398,
       0,     0,     0,   150,     0,     0,     0,     0,   257,     0,
      97,   248,     0,   156,     0,   723,   101,   102,   103,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   250,     0,     0,     0,     0,     0,     0,     0,
       0,   131,   132,   133,     0,     0,     0,   135,   136,     0,
       0,     0,     0,     0,     0,   251,     0,     0,   252,     0,
       0,   253,     0,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,     0,     0,     0,     0,
       0,    42,    43,    44,    45,    46,     0,     0,     0,    50,
       0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,  1489,     0,     0,
     385,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,     0,     0,  1543,     0,   141,   142,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   256,     0,     0,     0,   150,
       0,     0,     0,     0,   257,     0,    97,   248,     0,   156,
       0,  1220,   101,   102,   103,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   132,   133,
       0,     0,     0,   135,   136,     0,     0,     0,     0,     0,
       0,   251,     0,     0,   252,     0,     0,   253,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,     0,     0,     0,     0,     0,     0,    42,    43,    44,
      45,    46,     0,     0,     0,    50,     0,     0,    53,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   497,     0,     0,     0,   385,   138,     0,     0,
       0,     0,     0,     0,   141,   142,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     450,  1319,     0,     0,     0,   150,     0,     0,     0,     0,
     452,     0,    97,   284,    99,   156,     0,   218,   101,   102,
     103,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     0,     0,     0,   125,   126,   127,
     128,   129,   130,   131,   132,   133,     0,     0,   134,   135,
     136,    97,   284,    99,     0,     0,     0,   101,   102,   103,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,   125,   126,   127,   128,
     129,   130,   131,   132,   133,     0,     0,   134,   135,   136,
       0,     0,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   632,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   139,   140,     0,     0,     0,     0,
     141,   142,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,     0,     0,
       0,   150,     0,     0,     0,     0,   257,     0,     0,     0,
       0,   156,     0,  1156,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   140,     0,     0,     0,     0,   141,
     142,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   149,     0,     0,     0,
     150,     0,     0,     0,     0,   257,     0,    97,   284,    99,
     156,     0,  1334,   101,   102,   103,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    97,   284,   134,   135,   136,     0,   101,   102,   103,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,   132,   133,     0,     0,     0,   135,   136,
       0,    97,   284,     0,     0,     0,     0,   101,   102,   103,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,     0,   138,   139,
     140,     0,   131,   132,   133,   141,   142,   143,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,   149,     0,     0,     0,   150,     0,     0,     0,
       0,   257,     0,     0,     0,     0,   156,     0,  1532,     0,
       0,     0,   138,     0,     0,     0,     0,     0,     0,   141,
     142,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   149,     0,     0,     0,
     150,     0,     0,     0,     0,   257,     0,     0,   709,     0,
     156,     0,   710,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,     0,     0,   141,
     142,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   149,     0,     0,     0,
     150,     0,     0,     0,     0,   257,     0,    97,   284,     0,
     156,     0,   355,   101,   102,   103,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,   132,
     133,    97,   248,     0,   135,   136,     0,   101,   102,   103,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   250,     0,     0,     0,     0,     0,     0,
       0,     0,   131,   132,   133,     0,     0,     0,   135,   136,
       0,     0,     0,     0,     0,     0,   251,     0,     0,   252,
       0,     0,   253,     0,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,     0,     0,     0,
       0,     0,    42,    43,    44,    45,    46,     0,   138,     0,
      50,     0,     0,    53,     0,   141,   142,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   450,   451,     0,   733,     0,   150,     0,     0,     0,
       0,   452,     0,     0,     0,     0,   156,     0,   218,     0,
       0,     0,   138,   824,     0,     0,     0,     0,     0,   141,
     142,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   398,     0,     0,     0,
     150,    97,   284,    99,     0,   257,     0,   101,   102,   103,
     156,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    97,   284,   134,   135,   136,
       0,   101,   102,   103,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   941,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   132,   133,     0,
       0,     0,   135,   136,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,  1101,     0,
       0,     0,   385,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,   138,   139,   140,     0,     0,     0,     0,   141,
     142,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   149,     0,     0,     0,
     150,     0,     0,     0,     0,   257,     0,     0,     0,     0,
     156,     0,     0,     0,     0,     0,   138,     0,     0,     0,
       0,     0,     0,   141,   142,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
     149,     0,     0,     0,   150,     0,     0,     0,     0,   257,
       0,     0,     0,     0,   156,     0,     0,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,    -4,     1,     0,   385,    -4,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,     0,     0,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,    -4,    -4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,     0,     0,     0,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,     0,    -4,    -4,     6,     0,     0,     0,     0,
      -4,     0,     0,     7,     8,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     9,    10,    -4,
      -4,    -4,    -4,     0,     0,     0,     0,     0,    11,    12,
       0,     0,     0,    13,    14,    15,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,     0,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     7,
       8,     0,    56,    57,  1033,     0,     0,     0,     0,    58,
       0,     0,     0,     0,    59,    60,    61,    62,     0,     0,
      63,     0,    64,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,     0,    76,    77,
      78,    79,     0,     0,     0,   596,    19,    20,   597,    22,
      23,   598,    25,   599,    27,     0,    28,     0,     0,     0,
      32,    33,     0,    35,    36,    37,     0,     0,     0,    40,
       0,     0,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    61,    62,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,     0,     0,     0,  1299,
       0,  1300,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,  1329,     0,  1330,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,  1427,     0,  1428,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
       0,     0,     0,     0,     0,   866,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,     0,     0,   916,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,     0,     0,     0,     0,
       0,   935,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,     0,     0,   960,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,     0,     0,  1051,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
       0,     0,     0,     0,     0,  1297,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,     0,     0,  1316,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,     0,     0,     0,     0,
       0,  1358,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,     0,     0,  1359,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,     0,     0,  1360,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
       0,     0,     0,     0,     0,  1361,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,     0,     0,  1362,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,     0,     0,     0,     0,
       0,  1396,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,     0,     0,  1443,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,     0,     0,  1449,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
       0,     0,     0,     0,     0,  1450,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,     0,     0,  1471,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,     0,     0,     0,     0,
       0,  1474,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,     0,     0,  1477,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,     0,     0,  1500,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
       0,     0,     0,     0,     0,  1503,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,     0,     0,  1537,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,     0,     0,     0,     0,
       0,  1539,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,     0,     0,  1541,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,     0,     0,  1554,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
       0,     0,     0,     0,     0,  1581,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,     0,   665,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,     0,     0,     0,     0,  1372,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
     720,     0,     0,     0,     0,   672,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,   625,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,   672,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
       0,     0,     0,   673,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,     0,     0,     0,   730,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,   767,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,   768,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,   781,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
       0,     0,     0,   782,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,     0,     0,     0,   783,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,   784,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,   785,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,   786,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
       0,     0,     0,   898,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,     0,     0,     0,   899,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,   900,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,  1010,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,  1049,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
       0,     0,     0,  1050,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,     0,     0,     0,  1100,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,  1257,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,  1258,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,  1265,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
       0,     0,     0,  1408,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,     0,     0,     0,  1409,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,  1413,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,  1493,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,  1496,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
       0,     0,     0,  1535,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,   588,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,   735,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,   742,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,   746,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,   748,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,   750,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,   752,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,   754,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
     756,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,   758,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,   760,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,   762,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,   764,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,   766,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,   770,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,   772,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,   774,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,   776,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
     778,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,   780,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,   924,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,   925,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,   929,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,   930,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,   933,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,   956,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,  1005,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,  1112,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
    1114,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,  1116,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,  1118,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,  1249,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,  1385,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,   584,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,   631,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,   635,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,   636,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,   638,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,   640,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,   641,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
     644,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,   645,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,   720,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,   726,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,   727,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,   728,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,   734,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,   745,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,   747,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,   749,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
     751,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,   753,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,   755,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,   757,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,   759,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,   761,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,   763,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,   765,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,   769,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,   771,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
     773,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,   775,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,   777,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,   779,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,   855,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,   860,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,   865,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,   868,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,   869,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,   875,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
     882,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,   883,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,   884,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,   915,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,   917,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,   918,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,   919,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,   923,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,  1111,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,  1113,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
    1115,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,  1117,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,  1125,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,  1298,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,  1315,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,  1333,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,  1492,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,  1552,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385
};

static const yytype_int16 yycheck[] =
{
       6,     6,   211,     3,   226,   338,     4,   444,   445,     4,
       6,  1218,     4,     4,   347,     4,   238,     4,     4,     4,
      13,     5,     5,     5,     4,     6,   357,     4,     6,   360,
       4,     6,     6,     6,     4,     4,     7,     4,   167,     6,
       4,   168,    64,     4,     5,   174,     6,   174,     6,   119,
       6,     6,     6,     6,   157,   158,   196,   197,   198,   281,
       6,   283,   132,   133,    43,    44,   168,    46,   157,   158,
     173,   173,   175,  1280,   157,   158,     0,    38,    39,    40,
      41,    42,    43,   910,   173,   167,   175,     7,    49,   167,
     173,    58,   232,   233,    58,   100,   164,   165,    62,   170,
       3,     4,   173,   171,   244,   245,     9,    10,    11,    73,
     169,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,   109,   110,   111,   112,   128,   164,   165,   119,
     120,    44,    45,    46,  1351,   157,   158,    50,    51,   107,
     119,   120,   107,   107,   107,     7,    61,   157,     8,    64,
     166,   167,    61,   175,  1371,    64,   164,   165,     6,     7,
     167,   169,   167,   171,   135,   136,   174,   174,   176,   174,
     167,   154,   174,   174,     7,   174,   167,   174,   174,   174,
     174,   174,   174,   174,   154,   169,   174,   167,   175,   174,
     171,   157,   158,   164,   165,   167,     8,    64,   167,    66,
     171,     6,   174,   435,   436,   174,   157,   158,     6,   170,
     157,   158,   173,     6,   144,   145,   146,   147,   157,   158,
     167,   134,   173,   455,   175,   214,   215,   174,   141,   142,
     143,   157,   158,   222,   173,  1072,     6,   226,   157,   158,
       7,   157,   158,   584,   157,   158,     6,   588,   174,   162,
     170,   157,   158,   173,   167,   174,   167,   170,   174,   172,
     167,   174,    58,   157,   158,    61,    58,   173,    64,    61,
      66,   168,    64,   914,   506,   168,   173,   169,  1495,   173,
     173,   167,   144,   145,   146,   147,    79,   167,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   164,   165,   157,   158,   166,   164,   165,   171,
      68,   144,   145,   146,   147,   175,    61,   174,   167,    64,
     173,    66,   167,   339,   340,   341,   342,   343,   344,   345,
     346,   164,   165,   349,   350,   351,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     170,   157,   158,   173,   166,   148,   149,   150,  1575,    61,
     153,   154,    64,   175,    66,   157,   158,   173,   168,   168,
       6,     7,   165,   173,   173,   167,   169,   144,   145,   146,
     147,    64,   174,   176,   177,   178,   179,   168,   181,   182,
     183,   184,   173,   186,   187,   188,   170,   164,   165,   173,
     193,   157,   158,     6,   360,   157,   158,   157,   158,    64,
     157,   158,   174,     4,     5,   208,   167,   173,   169,    80,
      64,   173,   168,   173,   217,   218,   173,   173,    66,    90,
     157,   158,    64,   226,   444,   445,   668,    98,    99,   100,
     157,   158,   103,   104,   105,   106,   173,    38,    39,    40,
      41,    42,    43,   442,   443,   168,   173,   168,    49,   167,
     173,   450,   173,   256,   257,   258,     4,    61,    80,   157,
     158,   157,   158,   266,   267,   268,   174,   270,    90,   174,
     273,   274,   157,   158,   277,   173,    98,    99,   100,    64,
      61,   103,   104,   105,   106,    61,    64,   290,   173,   658,
     659,   660,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   135,   136,    84,    85,    86,    87,
      58,   157,   158,    61,    92,   348,    64,    95,    66,   157,
     158,     4,   355,   175,     6,   358,   522,   173,   157,   158,
     159,   160,   161,     4,   589,   173,     4,   166,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   167,  1431,   169,     6,  1434,   817,     6,
    1437,   157,   158,   157,   158,   398,   159,   160,   161,   167,
     167,   404,   169,   166,   630,   167,   409,   173,   167,   173,
     169,   414,   415,   167,   417,   418,   167,   167,   169,   422,
     169,   167,   588,   169,   427,   428,   429,   978,   164,   165,
     981,   982,   657,   658,   659,   660,     4,   167,   174,   169,
     167,   167,   169,   169,   447,   448,   449,   450,   451,   452,
     167,     4,   169,   456,   457,   458,   459,   460,   167,   167,
     169,   464,   167,   167,   467,   468,   167,   167,   471,   472,
     473,  1518,   671,   476,   477,   167,   479,   164,   165,   678,
     483,   167,   169,   169,   171,   684,   167,     7,   491,   176,
     167,   167,   169,   169,   497,   498,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     167,   167,  1559,   516,   166,  1562,   742,   520,  1565,   167,
     523,  1568,   167,     4,   169,   164,   165,   174,   167,  1380,
     169,  1382,   171,  1384,   167,   174,   169,   176,     6,  1196,
    1197,   167,   167,   169,   169,     6,   712,     5,   167,     6,
     169,  1598,   167,  1600,   169,  1602,   167,   167,   169,   169,
     989,   167,   788,   169,   169,   173,   171,   175,   794,     4,
     167,   797,   798,   799,   167,   173,   742,   175,   804,   167,
      38,    39,    40,    41,    42,    43,    80,   590,    64,   167,
      66,    49,   177,   173,   167,   175,    90,   182,   173,   169,
     175,   186,   174,   167,    98,    99,   100,   174,   193,   103,
     104,   105,   106,   173,   840,   175,   619,   174,   173,   622,
     175,   624,   625,   173,   173,   175,   175,   167,   167,   632,
     633,   167,   174,  1484,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   646,   173,   169,   175,   166,   174,   652,
     849,   173,     6,   175,   657,   658,   659,   660,   173,   173,
     175,   175,   665,    64,   173,    66,   175,   174,   167,   672,
     673,   173,   173,   175,   175,   678,   167,   135,   136,   167,
     167,   175,     8,   169,   173,  1536,   175,  1538,   691,  1540,
     174,   694,    12,    13,   173,  1546,   175,   174,     5,   898,
     899,   900,   173,   169,   175,   708,   173,   710,   175,  1138,
     174,     5,   715,   716,   717,   718,     5,   158,  1375,   173,
     723,   175,   173,   173,   175,   175,   173,   730,   175,   732,
     733,   173,  1583,   175,  1585,   173,  1587,   175,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   189,    69,
     173,     6,   175,    73,    74,     6,    76,    77,    78,   173,
     171,   175,    82,   122,   767,   768,   207,   933,   174,   210,
     355,     6,     4,   358,     6,   173,   169,   175,   781,   782,
     783,   784,   785,   786,     6,   173,  1011,   175,   791,   173,
     793,   175,     6,   234,   114,   115,   116,     4,   173,   802,
     175,   174,   173,   806,   175,     6,     6,   810,   173,   173,
     175,   175,   173,   173,   175,   175,   982,   820,   821,   822,
     823,   824,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   173,   173,   175,   175,
     166,   173,   168,   175,   166,     7,   287,   288,   171,   173,
      80,   175,   173,     6,   175,   175,   173,   173,   175,   175,
      90,   173,   175,   175,   867,   173,   169,   175,    98,    99,
     100,     7,  1071,   103,   104,   105,   106,   173,   173,   175,
     175,   173,   173,   175,   175,     7,   471,   472,   473,   174,
       7,   167,   167,    80,   167,   167,  1122,     7,   168,     6,
     174,     7,     6,    90,     7,  1130,   491,     6,     6,     6,
      80,    98,    99,   100,  1343,     4,   103,   104,   105,   106,
      90,     4,   174,   119,   174,   928,   174,  1153,    98,    99,
     100,  1156,   174,   103,   104,   105,   106,   174,   941,   168,
       6,   168,   173,  1109,   168,   175,     6,  1389,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   173,  1162,   173,   173,   166,  1192,     7,     8,
     173,   168,     4,     4,   173,   170,  1196,  1197,     6,  1532,
       6,     4,     6,   122,   122,     7,     7,   990,   175,     7,
       7,     7,     7,   122,     7,     7,   174,  1000,  1001,  1198,
       4,  1200,   171,  1202,     6,   175,     6,  1010,  1011,   175,
     175,  1236,   170,     7,     7,     7,   171,  1216,   174,     6,
    1219,  1220,   168,     6,     6,   170,   177,     6,   169,     7,
       6,   182,   167,   167,   174,   186,     6,   622,   154,   624,
      80,     7,   193,  1485,     7,  1048,  1049,  1050,     7,     7,
      90,     6,    66,     7,     7,  1058,     7,  1060,    98,    99,
     100,  1227,     7,   103,   104,   105,   106,   168,  1071,     7,
       7,     7,   168,   168,   168,     6,  1079,     4,     4,   167,
     665,     6,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   174,  1100,  1101,  1102,
     166,     6,   174,     7,     6,   256,     7,   258,     7,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   708,    80,   710,     7,   166,  1131,     6,
     715,   716,   717,   718,    90,   175,     6,     6,   723,     6,
      64,  1144,    98,    99,   100,   586,  1149,   103,   104,   105,
     106,     6,     4,  1156,     4,  1375,   175,  1160,  1161,     7,
       4,     6,     4,     6,  1167,  1168,   173,   168,   171,  1172,
     168,   168,   168,     7,     6,   174,   167,  1180,     6,   174,
    1379,   171,  1381,    73,  1383,   174,     6,  1190,   174,  1192,
     174,     6,  1391,     6,   174,  1394,     6,     6,     5,     4,
       6,  1204,   174,     7,   355,     7,   791,   358,   793,     7,
       7,     7,   653,  1216,   174,     6,     6,  1220,     6,   175,
    1223,   169,     6,   664,   174,   174,   168,   174,     4,   170,
     118,     6,     6,  1236,     6,   820,   821,   822,   823,   173,
      80,     6,     6,     4,     6,     4,     6,   398,     6,     6,
      90,    80,     6,     6,  1257,  1258,     6,     6,    98,    99,
     100,    90,  1265,   103,   104,   105,   106,     6,    80,    98,
      99,   100,  1497,  1498,   103,   104,   105,   106,    90,     5,
     174,     6,   867,     6,   122,     6,    98,    99,   100,  1488,
       6,   103,   104,   105,   106,     6,  1299,     6,   739,     6,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,  1317,     6,  1319,   173,   166,     6,
     471,   472,   473,     6,     6,  1551,  1329,   168,  1331,     6,
       6,  1334,    80,     6,     6,   175,     7,   174,   171,     6,
     491,     5,    90,    62,  1347,     6,   175,   498,     6,  1352,
      98,    99,   100,     6,  1579,   103,   104,   105,   106,     6,
       6,     6,     6,   175,  1590,     7,  1592,   175,     6,  1372,
     117,   174,     6,   174,   120,   175,  1379,     6,  1381,   174,
    1383,   174,   174,     6,  1609,   174,     6,  1613,   175,   174,
    1393,     6,     6,     6,  1397,    12,    13,     6,     6,     6,
       6,     6,   175,   174,   174,  1408,  1409,     6,   174,     6,
    1413,    80,   853,   854,     4,   856,     4,   858,   859,     6,
    1423,   862,   863,     6,  1427,     6,     6,   175,     6,     6,
       6,     6,   175,     6,   174,     6,   174,   174,     6,   174,
       6,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,  1454,    69,     6,     6,     6,    73,    74,     6,    76,
      77,    78,  1465,     8,   174,    82,     6,     6,   174,  1472,
     174,   622,  1475,   624,   174,  1478,   174,     6,     6,  1482,
       6,   632,   633,  1486,     6,  1488,     6,     6,     6,     6,
    1493,     6,     6,  1496,  1079,  1498,  1008,   114,   115,   116,
    1454,   396,   943,   944,   945,  1016,     3,     3,   421,    -1,
    1134,    -1,   953,    -1,   665,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,  1529,    -1,    -1,    -1,
      -1,    -1,  1535,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    99,   100,    -1,  1548,   103,   104,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   708,   175,   710,
       6,  1002,    -1,    -1,   715,   716,   717,   718,    -1,    -1,
      -1,    -1,   723,    -1,  1577,    -1,  1017,    -1,    -1,    -1,
      -1,    -1,  1023,    -1,    -1,    -1,    -1,    -1,  1029,    -1,
    1031,  1032,    -1,    -1,    -1,  1036,    -1,    12,    13,    -1,
    1041,  1042,  1043,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,  1058,   175,    -1,
      -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,  1073,    -1,    -1,    -1,  1077,    -1,    -1,    -1,
     791,    -1,   793,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    -1,    -1,    -1,    73,    74,
      -1,    76,    77,    78,    -1,    -1,    -1,    82,    -1,   820,
     821,   822,   823,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,  1127,    -1,  1129,    73,
      74,    -1,    76,    77,    78,    -1,    -1,    -1,    82,   114,
     115,   116,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   867,    -1,    12,    13,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
     114,   115,   116,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    -1,  1183,  1184,  1185,  1186,    98,    99,   100,  1334,
      -1,   103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,
     175,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    -1,  1218,    -1,    73,
      74,    -1,    76,    77,    78,    -1,    -1,  1372,    82,  1230,
       6,   175,    -1,    -1,    -1,    -1,  1237,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,  1393,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,  1259,    -1,
     114,   115,   116,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,  1280,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,  1314,    -1,    -1,    44,    45,    46,    -1,
      -1,   175,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    61,    -1,    -1,    64,    -1,    66,    -1,
      -1,  1486,    -1,  1488,    -1,    -1,    -1,    -1,    -1,    77,
    1351,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    -1,    -1,    -1,    92,    -1,    -1,    95,  1079,    -1,
    1371,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,  1388,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1548,    -1,    -1,   134,     6,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,   157,
     158,    -1,   166,    -1,   162,    -1,    -1,    -1,  1439,   167,
      -1,    -1,    -1,    -1,   172,    -1,   174,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     6,
      -1,    -1,    -1,    -1,  1495,    -1,  1497,    44,    45,    46,
      -1,    -1,    -1,    50,    51,  1216,    -1,    -1,    -1,  1220,
      -1,    58,    -1,    -1,    61,    -1,    -1,    64,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    92,    -1,    -1,    95,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,
      -1,    -1,    -1,    -1,  1575,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   142,   143,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1319,    -1,
     157,   158,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,
     167,    -1,    -1,  1334,    -1,   172,    -1,    -1,   175,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,    -1,     6,    -1,    -1,   166,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,  1393,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    -1,    -1,
      -1,    92,    -1,    -1,    95,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1486,    -1,  1488,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   134,   135,   136,   166,    -1,    -1,    -1,
     141,   142,   143,    -1,    -1,    -1,    -1,    -1,  1529,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,    -1,    -1,
      -1,   162,    -1,    -1,    -1,    -1,   167,  1548,     3,     4,
       5,   172,     7,   174,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    12,    13,    49,    50,    51,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      -1,    -1,    -1,    73,    74,    -1,    76,    77,    78,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,    -1,    -1,    -1,    -1,   141,   142,   143,   144,
     145,   146,   147,    -1,   114,   115,   116,    -1,    -1,    -1,
      -1,    -1,   157,   158,    -1,    -1,    -1,   162,    -1,   164,
     165,    -1,   167,    -1,   169,    -1,   171,   172,    -1,   174,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,   175,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    -1,    -1,    -1,    50,    51,    12,
      13,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    -1,
      -1,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    -1,    -1,    -1,    92,
      -1,    -1,    95,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    -1,    -1,    -1,
      73,    74,    -1,    76,    77,    78,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,   115,   116,   157,   158,    -1,    -1,    -1,   162,
      -1,    -1,    -1,    -1,   167,    -1,     3,     4,     5,   172,
      -1,   174,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      -1,    -1,   175,    50,    51,    12,    13,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    61,    -1,    -1,    64,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    -1,    -1,    -1,    73,    74,    -1,    76,
      77,    78,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   142,   143,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,
     157,   158,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,
     167,    -1,     3,     4,    -1,   172,    -1,   174,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    -1,    -1,   175,    50,
      51,    12,    13,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    -1,    -1,
      -1,    92,    -1,    -1,    95,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    -1,
      -1,    -1,    73,    74,    -1,    76,    77,    78,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,   116,   157,   158,    -1,    -1,
      -1,   162,    -1,    -1,    -1,    -1,   167,    -1,     3,     4,
      -1,   172,    -1,   174,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    -1,    -1,   175,    50,    51,    12,    13,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    -1,    -1,    64,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    -1,    -1,    -1,    92,    -1,    -1,
      95,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    -1,    -1,    -1,    73,    74,
      -1,    76,    77,    78,    -1,     6,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,
      -1,    -1,    -1,    -1,     6,    -1,   141,   142,   143,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,   116,   157,   158,    -1,    -1,    -1,   162,    -1,    -1,
      -1,    -1,   167,    -1,     3,     4,    -1,   172,    -1,   174,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
     175,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    -1,    -1,    64,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      -1,    -1,    -1,    92,    -1,    -1,    95,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
       6,    -1,    -1,    -1,   166,   134,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   142,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,
      -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,   167,    -1,
       3,     4,    -1,   172,    -1,   174,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    -1,
      -1,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    -1,    -1,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,     6,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   134,    -1,    -1,    -1,    -1,     6,    -1,   141,   142,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,   162,
      -1,    -1,    -1,    -1,   167,    -1,     3,     4,    -1,   172,
      -1,   174,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    61,    -1,    -1,    64,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    92,    -1,    -1,    95,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,     8,    -1,    -1,    -1,   166,   134,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   142,   143,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,
     167,    -1,     3,     4,     5,   172,    -1,   174,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    49,    50,
      51,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    49,    50,    51,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,
     141,   142,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,    -1,    -1,
      -1,   162,    -1,    -1,    -1,    -1,   167,    -1,    -1,    -1,
      -1,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,
     162,    -1,    -1,    -1,    -1,   167,    -1,     3,     4,     5,
     172,    -1,   174,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     3,     4,    49,    50,    51,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    -1,    -1,    -1,    50,    51,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,   134,   135,
     136,    -1,    44,    45,    46,   141,   142,   143,    50,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,    -1,    -1,    -1,   162,    -1,    -1,    -1,
      -1,   167,    -1,    -1,    -1,    -1,   172,    -1,   174,    -1,
      -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,
     162,    -1,    -1,    -1,    -1,   167,    -1,    -1,   170,    -1,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,
     162,    -1,    -1,    -1,    -1,   167,    -1,     3,     4,    -1,
     172,    -1,   174,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,     3,     4,    -1,    50,    51,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    -1,    -1,    -1,    50,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,
      -1,    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    -1,   134,    -1,
      92,    -1,    -1,    95,    -1,   141,   142,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,    -1,     8,    -1,   162,    -1,    -1,    -1,
      -1,   167,    -1,    -1,    -1,    -1,   172,    -1,   174,    -1,
      -1,    -1,   134,     8,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,
     162,     3,     4,     5,    -1,   167,    -1,     9,    10,    11,
     172,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     3,     4,    49,    50,    51,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    50,    51,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,     8,    -1,
      -1,    -1,   166,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,   134,   135,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,
     162,    -1,    -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     158,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,   167,
      -1,    -1,    -1,    -1,   172,    -1,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,     0,     1,    -1,   166,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    -1,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    -1,    -1,   101,   102,     4,    -1,    -1,    -1,    -1,
     108,    -1,    -1,    12,    13,   113,   114,   115,   116,    -1,
      -1,   119,    -1,   121,    -1,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    36,    37,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    12,
      13,    -1,   101,   102,    80,    -1,    -1,    -1,    -1,   108,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,    -1,    -1,
     119,    -1,   121,    -1,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,   137,   138,
     139,   140,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    -1,    -1,    -1,
      73,    74,    -1,    76,    77,    78,    -1,    -1,    -1,    82,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,   115,   116,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,   173,
      -1,   175,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   175,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   175,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   175,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   175,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   175,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
     168,    -1,    -1,    -1,    -1,   173,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   173,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,   173,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   173,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,   173,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   173,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,   173,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   173,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,   173,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   173,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,   173,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   173,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,   173,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,   170,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,   170,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,   170,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,   170,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,   170,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,
      -1,   170,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,   170,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,   170,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
      -1,    -1,    -1,   170,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,   170,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,   170,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,   170,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,   170,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,   170,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,
      -1,   170,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,   170,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,   170,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
      -1,    -1,    -1,   170,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,   170,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,   170,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,   170,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,   170,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,   170,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,
      -1,   170,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,   170,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,   170,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
      -1,    -1,    -1,   170,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,   170,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,   170,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,   170,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,   168,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,   168,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,   168,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,   168,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,   168,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,   168,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,   168,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
     168,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
      -1,   168,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,   168,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,   168,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,   168,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,   168,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,   168,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,   168,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,   168,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,   168,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
     168,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
      -1,   168,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,   168,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,   168,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,   168,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,   168,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,   168,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,   168,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,   168,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,   168,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
     168,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
      -1,   168,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,   168,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,   168,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,   168,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,   168,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,   168,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,   168,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,   168,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,   168,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
     168,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
      -1,   168,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,   168,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,   168,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,   168,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,   168,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,   168,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,   168,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,   168,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,   168,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
     168,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
      -1,   168,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,   168,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,   168,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,   168,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,   168,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,   168,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,   168,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   178,   179,     6,     0,     4,    12,    13,    36,
      37,    47,    48,    52,    53,    54,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   101,   102,   108,   113,
     114,   115,   116,   119,   121,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   137,   138,   139,   140,
     180,   182,   183,   201,   215,   220,   223,   224,   225,   226,
     227,   228,   229,   249,   250,   251,   252,     3,     4,     5,
       7,     9,    10,    11,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    49,    50,    51,   128,   134,   135,
     136,   141,   142,   143,   144,   145,   146,   147,   157,   158,
     162,   164,   165,   167,   169,   171,   172,   174,   199,   200,
     253,   254,   265,   266,    13,    64,   167,   167,     6,   174,
       6,     6,     6,     6,   169,   169,   167,   174,   167,   167,
       4,   167,   174,   167,   167,     4,   174,   167,   167,    68,
      64,    64,     6,   174,    64,    64,    61,    64,    66,    66,
      58,    61,    64,    66,    61,    64,    66,    61,    64,   167,
      61,   119,   132,   133,   174,   157,   158,   167,   174,   255,
     256,   255,   174,    58,    61,    64,   174,   255,     4,    58,
      62,    73,    64,    66,    64,    61,     4,   128,   174,     4,
       6,    58,    61,    64,    61,    64,     4,     4,     4,     5,
      35,    58,    61,    64,    66,    77,   158,   167,   174,   220,
     229,   253,   258,   259,   260,     4,   167,   167,   167,     4,
     174,   262,     4,   167,   167,     6,     6,   169,     4,     4,
       5,   174,     5,   174,     4,   253,     6,   167,   174,     4,
     169,   171,   176,   200,   266,   167,   169,   167,   169,   167,
     169,   167,   169,   167,   169,   167,   169,   167,   169,   167,
     169,   167,   169,   167,   169,   167,   169,   167,   169,   167,
     169,   167,   169,   167,   169,   167,   169,   167,   169,   167,
     169,   167,   169,   167,   169,   167,   169,   167,   169,   167,
     169,   167,   167,   167,   167,   167,   167,   167,     7,   167,
     167,   167,   253,   253,   253,   174,   253,   170,   174,   253,
       4,   119,   120,     4,     4,   220,   221,   222,   258,     6,
       6,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   166,   174,     6,     6,   253,
       4,   265,   266,   265,   253,   203,   206,   253,   158,   253,
     260,   261,   253,   253,   167,   253,   261,   253,   253,   167,
     261,   253,   253,   258,   167,   174,   261,   167,   167,   259,
     259,   259,   167,   216,   217,   218,   219,   167,   167,   167,
     258,   253,     4,   258,   262,   174,   174,   255,   255,   255,
     253,   253,   157,   158,   174,   174,   255,   174,   174,   174,
     157,   158,   167,   222,   255,   174,   167,   174,   167,   167,
     167,   259,   259,   258,   167,     4,     6,   169,   169,   222,
       6,   174,   174,   174,   259,   259,   169,   169,   167,   169,
     171,   169,     5,   174,     5,     5,     5,    58,    61,    64,
      66,   174,   253,   260,   253,   175,   261,     8,   159,     6,
       6,   253,   253,   253,   171,   253,   174,   122,   253,   253,
     253,     6,     6,   222,     6,   222,   169,     6,   258,   258,
     169,   253,     4,   174,     6,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   265,   267,   267,
     265,   265,   265,   265,   265,   265,   265,   265,   267,   253,
     265,   265,   265,   261,   168,     7,   199,   261,   170,     7,
     199,   200,   171,     7,   169,   175,    58,    61,    64,    66,
     215,     6,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   184,     6,   169,
     171,   168,   173,   168,   173,   173,   170,   173,   202,   170,
     202,   168,   159,   173,   175,   168,   168,   253,   168,   175,
     168,   168,   253,   175,   168,   168,     7,   253,   253,   175,
     253,   253,     7,     7,   247,   247,   253,   167,   167,   167,
     167,   253,   253,   253,     7,   174,   168,     6,   174,   222,
     222,   173,   173,   173,   255,   255,   221,   221,   173,   253,
     253,   253,   253,   233,   173,   222,   253,   253,   253,   253,
     253,     7,   248,     6,     7,   253,     6,   253,   253,   175,
     261,   261,   261,     6,     6,   253,   253,   168,   174,   170,
     174,   253,     4,     4,   253,   174,   174,   174,   174,   261,
     168,   175,   253,   174,   253,   260,   168,   168,   168,   119,
     173,   222,   174,     8,   168,   170,   175,   175,   168,   173,
     175,   253,   170,   200,   253,   168,   170,   168,   170,   168,
     170,   168,   170,   168,   170,   168,   170,   168,   170,   168,
     170,   168,   170,   168,   170,   168,   170,   173,   173,   168,
     170,   168,   170,   168,   170,   168,   170,   168,   170,   168,
     170,   173,   173,   173,   173,   173,   173,   168,   173,   170,
     168,   173,   170,   173,   173,   168,   168,   173,   173,   173,
     168,     6,   173,   168,   173,   175,   199,   258,   175,   171,
     199,   200,   266,   253,     6,     4,     4,   174,   263,   170,
     174,   174,   174,   174,     8,     4,   109,   110,   111,   112,
     175,   187,   191,   194,   196,   197,   253,     4,     6,   154,
     181,   261,     6,   261,   253,     6,     4,     6,   265,     7,
     253,   260,   122,     7,     7,   168,     7,   122,     7,     7,
     168,   122,     7,     7,   253,   168,   175,   174,   168,   168,
     253,   258,     4,   246,     6,   168,   212,   253,   266,   212,
     212,   212,   168,   168,   168,   258,   261,   171,   222,   175,
     175,   255,   253,   253,   175,   175,   253,   255,   173,   173,
     173,    80,    90,    98,    99,   100,   103,   104,   105,   106,
     243,   244,   255,   175,   230,   168,   175,   168,   168,   168,
     253,     6,   253,   168,   170,   170,   175,   175,   175,   170,
     170,   261,   261,   170,   170,   175,   261,   261,   261,   261,
     175,     8,   261,     7,     7,     7,   171,   253,   175,   253,
     253,     7,   171,   174,   258,     6,   170,   171,   200,   265,
     175,   253,   253,   253,   253,   253,   253,   253,   253,   265,
     261,   261,   265,   265,   265,   265,   253,   265,   168,   253,
       6,   170,     4,   119,   120,   253,     6,     6,     6,     7,
     169,   262,   264,     6,   261,   261,   261,   261,   253,   188,
     167,   167,   174,   198,     6,   170,   154,   265,   168,   168,
     173,     7,   255,    64,    66,   258,   258,     7,   258,    64,
      66,   258,   258,     7,    66,   258,   258,     6,     7,     7,
     261,     7,     7,    80,   245,     6,     7,   168,   168,   168,
     168,     7,     7,     7,     6,   175,     4,   175,   173,   173,
     173,   175,   175,   255,   255,   255,     4,     6,   174,     6,
     167,     6,   107,     6,   107,     6,   107,     6,   107,   175,
     244,   173,   243,     7,     6,     7,     7,     7,     6,   174,
       6,     6,     6,    64,   253,     6,     6,   175,   175,   171,
     175,   175,   175,   175,   253,   175,   258,   258,   258,     4,
     173,     8,     8,   168,     4,     4,   258,   175,     6,     4,
       6,   168,   170,   168,   170,   168,   170,   168,   170,   168,
     170,   168,   173,   168,   168,   168,   168,   199,     6,   199,
       7,   199,   200,   171,     7,     6,   262,   253,   173,   175,
     175,   175,   175,   175,   167,   253,   253,   257,   258,   174,
     171,     6,     6,   181,     6,   253,   174,   253,   266,     6,
     174,   174,    73,   214,   214,   258,     6,   174,   174,     6,
       6,   258,   174,     6,     6,     5,   258,   175,   258,   258,
       4,     6,   258,     7,     7,     7,     7,   258,   258,   258,
       7,     6,     7,   253,   253,   253,   174,   174,   173,   175,
     173,   175,   173,   175,   169,   253,   258,   253,     6,     6,
       6,     6,   253,   255,   175,     5,   174,   258,   174,   174,
     174,   258,   261,   174,     6,   168,   170,     4,     6,     6,
     118,   253,   253,   253,     6,     6,     7,   173,     6,   200,
     265,   258,   258,   266,   253,     6,     4,   263,     6,   170,
     262,     6,     6,     6,     6,   185,   253,   173,   173,   173,
     175,   186,   253,     4,   265,   173,   253,   266,   253,   253,
     255,     6,     6,     6,   253,   253,     6,   253,     5,     6,
     174,     6,   122,   213,   253,     6,   258,   258,   258,   258,
       6,     4,     6,     6,   253,   253,   266,   175,   168,   173,
     175,   221,   221,   255,     6,   234,   255,     6,   235,   255,
       6,   236,   253,   175,   173,   168,   175,   173,     6,   158,
     255,     6,   257,   255,   255,     6,   175,   253,   258,   173,
     175,     8,   175,   168,   174,   253,   266,   258,   168,     6,
       6,     6,     6,     7,     6,   171,   168,   173,   253,   253,
     258,   174,   173,   175,     6,   253,   204,   205,   175,   175,
     175,   175,   175,     5,   257,    62,     6,     6,     6,     6,
       6,   174,   174,     6,     6,   174,   253,   175,   175,   173,
     174,   173,   174,   173,   174,   170,     6,   258,     7,   174,
     253,   173,   175,   173,   173,     6,   175,   117,   253,   253,
     261,     6,     6,   175,   262,   120,   189,   253,   173,   173,
     257,   253,     6,   173,   208,   210,     6,     6,     6,     6,
       6,     6,   175,   174,   257,   261,   221,   173,   175,   253,
     255,   243,   253,   255,   243,   253,   255,   243,     6,   173,
     175,   258,   222,   175,   255,     6,   261,   255,   253,   175,
     175,   175,     6,     6,   174,   253,   253,   175,   253,   173,
     175,   209,   173,   175,   211,   174,   253,   175,   175,   175,
     253,   175,   173,   175,   175,   173,   175,   175,   173,   175,
     258,     6,    80,   175,   231,   174,   173,   175,   173,     6,
       6,   186,   168,   173,     6,   174,   173,     4,     4,   253,
     175,     6,     6,   175,     6,   237,   253,     6,     6,   238,
     253,     6,     6,   239,   253,     6,   175,   253,   243,   222,
     261,     6,   255,   261,   175,   192,   253,   257,   253,   174,
     258,   266,   174,   253,   266,   173,   174,   175,   174,   175,
     174,   175,     6,     6,   175,   175,   232,   175,   173,   175,
       6,   174,   168,   175,   175,   207,   253,   267,   253,   243,
       6,   240,   243,     6,   241,   243,     6,   242,   243,     6,
     261,     6,   190,   265,   195,   174,     6,   173,   175,     7,
     175,   175,   175,   174,   175,   174,   175,   174,   175,   175,
     173,   175,   174,   257,   253,   266,     6,     6,   243,     6,
     243,     6,   243,     6,   265,     6,   193,   265,   175,     7,
     175,   175,   175,   173,   175,     6,   266,     6,     6,     6,
     265,     6
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
#line 170 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 181 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 182 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 183 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 184 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 185 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 186 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 187 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 188 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 189 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 190 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 191 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 192 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 193 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 194 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 195 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 200 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 22:
#line 204 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 23:
#line 211 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 24:
#line 216 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 25:
#line 221 "Gmsh.y"
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
#line 235 "Gmsh.y"
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
#line 248 "Gmsh.y"
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
#line 261 "Gmsh.y"
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
#line 289 "Gmsh.y"
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
#line 303 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], false);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 31:
#line 314 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], true);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 32:
#line 328 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 38:
#line 342 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 39:
#line 344 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 40:
#line 349 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:
#line 351 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:
#line 356 "Gmsh.y"
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

  case 43:
#line 460 "Gmsh.y"
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

  case 44:
#line 470 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 45:
#line 479 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 46:
#line 486 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 47:
#line 496 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    ;}
    break;

  case 48:
#line 505 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 49:
#line 514 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 50:
#line 521 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 51:
#line 531 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 52:
#line 539 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 53:
#line 549 "Gmsh.y"
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

  case 54:
#line 568 "Gmsh.y"
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

  case 55:
#line 587 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 56:
#line 593 "Gmsh.y"
    {
    ;}
    break;

  case 57:
#line 600 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 58:
#line 601 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 59:
#line 602 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 60:
#line 603 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 61:
#line 604 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 62:
#line 608 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 63:
#line 609 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 66:
#line 620 "Gmsh.y"
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

  case 67:
#line 682 "Gmsh.y"
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

  case 68:
#line 712 "Gmsh.y"
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

  case 69:
#line 747 "Gmsh.y"
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
#line 781 "Gmsh.y"
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

  case 71:
#line 829 "Gmsh.y"
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
#line 876 "Gmsh.y"
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

  case 73:
#line 891 "Gmsh.y"
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

  case 74:
#line 907 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 75:
#line 916 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 76:
#line 922 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 77:
#line 931 "Gmsh.y"
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

  case 78:
#line 949 "Gmsh.y"
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

  case 79:
#line 967 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 80:
#line 976 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 81:
#line 988 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 82:
#line 993 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 83:
#line 1001 "Gmsh.y"
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

  case 84:
#line 1021 "Gmsh.y"
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

  case 85:
#line 1044 "Gmsh.y"
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

  case 86:
#line 1055 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 87:
#line 1063 "Gmsh.y"
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

  case 88:
#line 1085 "Gmsh.y"
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

  case 89:
#line 1108 "Gmsh.y"
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

  case 90:
#line 1134 "Gmsh.y"
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

  case 91:
#line 1155 "Gmsh.y"
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

  case 92:
#line 1167 "Gmsh.y"
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

  case 96:
#line 1185 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      floatOptions.clear(); charOptions.clear();
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 97:
#line 1196 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      floatOptions.clear(); charOptions.clear();
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 98:
#line 1207 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 99:
#line 1209 "Gmsh.y"
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

  case 100:
#line 1219 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      floatOptions.clear(); charOptions.clear();
      if(!gmsh_yystringsymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 101:
#line 1230 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 102:
#line 1232 "Gmsh.y"
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

  case 104:
#line 1246 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 105:
#line 1254 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 106:
#line 1260 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 109:
#line 1272 "Gmsh.y"
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

  case 110:
#line 1283 "Gmsh.y"
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

  case 111:
#line 1298 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 114:
#line 1314 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 115:
#line 1322 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 116:
#line 1331 "Gmsh.y"
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

  case 117:
#line 1349 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 118:
#line 1353 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 119:
#line 1363 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 120:
#line 1367 "Gmsh.y"
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

  case 121:
#line 1379 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 122:
#line 1383 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 123:
#line 1393 "Gmsh.y"
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

  case 124:
#line 1416 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 125:
#line 1420 "Gmsh.y"
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

  case 126:
#line 1436 "Gmsh.y"
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

  case 127:
#line 1458 "Gmsh.y"
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

  case 128:
#line 1476 "Gmsh.y"
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

  case 129:
#line 1497 "Gmsh.y"
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

  case 130:
#line 1515 "Gmsh.y"
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

  case 131:
#line 1545 "Gmsh.y"
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

  case 132:
#line 1575 "Gmsh.y"
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

  case 133:
#line 1593 "Gmsh.y"
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

  case 134:
#line 1611 "Gmsh.y"
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

  case 135:
#line 1637 "Gmsh.y"
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

  case 136:
#line 1655 "Gmsh.y"
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

  case 137:
#line 1673 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 138:
#line 1677 "Gmsh.y"
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

  case 139:
#line 1696 "Gmsh.y"
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

  case 140:
#line 1714 "Gmsh.y"
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

  case 141:
#line 1753 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 142:
#line 1759 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 143:
#line 1765 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 144:
#line 1772 "Gmsh.y"
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

  case 145:
#line 1797 "Gmsh.y"
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

  case 146:
#line 1822 "Gmsh.y"
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

  case 147:
#line 1839 "Gmsh.y"
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

  case 148:
#line 1859 "Gmsh.y"
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

  case 149:
#line 1892 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 150:
#line 1896 "Gmsh.y"
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

  case 151:
#line 1916 "Gmsh.y"
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

  case 152:
#line 1934 "Gmsh.y"
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

  case 153:
#line 1951 "Gmsh.y"
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

  case 154:
#line 1967 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 155:
#line 1971 "Gmsh.y"
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

  case 156:
#line 1993 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 157:
#line 1998 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 158:
#line 2003 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 159:
#line 2008 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 160:
#line 2013 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 161:
#line 2018 "Gmsh.y"
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

  case 162:
#line 2041 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 163:
#line 2047 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 164:
#line 2057 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 165:
#line 2058 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 166:
#line 2063 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 167:
#line 2067 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 168:
#line 2071 "Gmsh.y"
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

  case 169:
#line 2094 "Gmsh.y"
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

  case 170:
#line 2117 "Gmsh.y"
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

  case 171:
#line 2140 "Gmsh.y"
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

  case 172:
#line 2168 "Gmsh.y"
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

  case 173:
#line 2189 "Gmsh.y"
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

  case 174:
#line 2216 "Gmsh.y"
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

  case 175:
#line 2237 "Gmsh.y"
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

  case 176:
#line 2258 "Gmsh.y"
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

  case 177:
#line 2278 "Gmsh.y"
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

  case 178:
#line 2390 "Gmsh.y"
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

  case 179:
#line 2409 "Gmsh.y"
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

  case 180:
#line 2448 "Gmsh.y"
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

  case 181:
#line 2556 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 182:
#line 2565 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 183:
#line 2571 "Gmsh.y"
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

  case 184:
#line 2586 "Gmsh.y"
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

  case 185:
#line 2614 "Gmsh.y"
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

  case 186:
#line 2631 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 187:
#line 2640 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 188:
#line 2654 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 189:
#line 2660 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 190:
#line 2666 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 191:
#line 2675 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 192:
#line 2684 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 193:
#line 2693 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 194:
#line 2707 "Gmsh.y"
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "NonBlockingSystemCall"))
	SystemCall((yyvsp[(2) - (3)].c));
      else if(!strcmp((yyvsp[(1) - (3)].c), "System") || !strcmp((yyvsp[(1) - (3)].c), "SystemCall"))
	SystemCall((yyvsp[(2) - (3)].c), true);
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetName"))
	GModel::current()->setName((yyvsp[(2) - (3)].c));
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 195:
#line 2752 "Gmsh.y"
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

  case 196:
#line 2769 "Gmsh.y"
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

  case 197:
#line 2784 "Gmsh.y"
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

  case 198:
#line 2803 "Gmsh.y"
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

  case 199:
#line 2815 "Gmsh.y"
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

  case 200:
#line 2839 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 201:
#line 2843 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 202:
#line 2848 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 203:
#line 2855 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 204:
#line 2861 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 205:
#line 2866 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 206:
#line 2872 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 207:
#line 2876 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 208:
#line 2880 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 209:
#line 2886 "Gmsh.y"
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

  case 210:
#line 2940 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    ;}
    break;

  case 211:
#line 2953 "Gmsh.y"
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

  case 212:
#line 2970 "Gmsh.y"
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

  case 213:
#line 2987 "Gmsh.y"
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

  case 214:
#line 3008 "Gmsh.y"
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

  case 215:
#line 3029 "Gmsh.y"
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

  case 216:
#line 3064 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 217:
#line 3072 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 218:
#line 3078 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 219:
#line 3085 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 220:
#line 3089 "Gmsh.y"
    {
    ;}
    break;

  case 221:
#line 3098 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 222:
#line 3106 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 223:
#line 3114 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 224:
#line 3122 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 225:
#line 3128 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 226:
#line 3136 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 227:
#line 3142 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 228:
#line 3150 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 229:
#line 3156 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 230:
#line 3164 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 231:
#line 3170 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 232:
#line 3178 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 233:
#line 3185 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 234:
#line 3192 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 235:
#line 3199 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 236:
#line 3206 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 237:
#line 3213 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 238:
#line 3220 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 239:
#line 3227 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 240:
#line 3234 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 241:
#line 3241 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 242:
#line 3247 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 243:
#line 3254 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 244:
#line 3260 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 245:
#line 3267 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 246:
#line 3273 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 247:
#line 3280 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 248:
#line 3286 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 249:
#line 3293 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 250:
#line 3299 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 251:
#line 3306 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 252:
#line 3312 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 253:
#line 3319 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 254:
#line 3325 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 255:
#line 3332 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 256:
#line 3338 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 257:
#line 3345 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 258:
#line 3351 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 259:
#line 3362 "Gmsh.y"
    {
    ;}
    break;

  case 260:
#line 3365 "Gmsh.y"
    {
    ;}
    break;

  case 261:
#line 3371 "Gmsh.y"
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

  case 262:
#line 3383 "Gmsh.y"
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

  case 263:
#line 3403 "Gmsh.y"
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

  case 264:
#line 3427 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 265:
#line 3432 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 266:
#line 3436 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 267:
#line 3440 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 268:
#line 3444 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, which has no requirement for the number of extrusion layers and meshes with body-centered vertices.");
    ;}
    break;

  case 269:
#line 3448 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, which has no requirement for the number of extrusion layers and meshes with body-centered vertices.");
    ;}
    break;

  case 270:
#line 3452 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 271:
#line 3456 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 272:
#line 3460 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 273:
#line 3464 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 274:
#line 3468 "Gmsh.y"
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

  case 275:
#line 3487 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 276:
#line 3499 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 277:
#line 3503 "Gmsh.y"
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

  case 278:
#line 3518 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 279:
#line 3522 "Gmsh.y"
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

  case 280:
#line 3538 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 281:
#line 3542 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 282:
#line 3547 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 283:
#line 3551 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 284:
#line 3558 "Gmsh.y"
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

  case 285:
#line 3614 "Gmsh.y"
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

  case 286:
#line 3684 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 287:
#line 3689 "Gmsh.y"
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

  case 288:
#line 3756 "Gmsh.y"
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

  case 289:
#line 3792 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 290:
#line 3800 "Gmsh.y"
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

  case 291:
#line 3843 "Gmsh.y"
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

  case 292:
#line 3882 "Gmsh.y"
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

  case 293:
#line 3902 "Gmsh.y"
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

  case 294:
#line 3930 "Gmsh.y"
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

  case 295:
#line 3969 "Gmsh.y"
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

  case 296:
#line 3992 "Gmsh.y"
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

  case 297:
#line 4015 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    ;}
    break;

  case 298:
#line 4019 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 299:
#line 4023 "Gmsh.y"
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

  case 300:
#line 4046 "Gmsh.y"
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

  case 301:
#line 4085 "Gmsh.y"
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
              yymsg(1, "Unknown surface %d", (int)d);
          }
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 302:
#line 4130 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 303:
#line 4134 "Gmsh.y"
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

  case 304:
#line 4144 "Gmsh.y"
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

  case 305:
#line 4178 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 306:
#line 4179 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 307:
#line 4180 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 308:
#line 4185 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 309:
#line 4191 "Gmsh.y"
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

  case 310:
#line 4203 "Gmsh.y"
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

  case 311:
#line 4221 "Gmsh.y"
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

  case 312:
#line 4248 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 313:
#line 4249 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 314:
#line 4250 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 315:
#line 4251 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 316:
#line 4252 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 317:
#line 4253 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 318:
#line 4254 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 319:
#line 4255 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 320:
#line 4257 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 321:
#line 4263 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 322:
#line 4264 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 323:
#line 4265 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 324:
#line 4266 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 325:
#line 4267 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 326:
#line 4268 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 327:
#line 4269 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 328:
#line 4270 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 329:
#line 4271 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 330:
#line 4272 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 331:
#line 4273 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 332:
#line 4274 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 333:
#line 4275 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 334:
#line 4276 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 335:
#line 4277 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 336:
#line 4278 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 337:
#line 4279 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 338:
#line 4280 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 339:
#line 4281 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 340:
#line 4282 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 341:
#line 4283 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 342:
#line 4284 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 343:
#line 4285 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 344:
#line 4286 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 345:
#line 4287 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 346:
#line 4288 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 347:
#line 4289 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 348:
#line 4290 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 349:
#line 4291 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 350:
#line 4292 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 351:
#line 4293 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 352:
#line 4294 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 353:
#line 4297 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 354:
#line 4298 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 355:
#line 4299 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 356:
#line 4300 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 357:
#line 4301 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 358:
#line 4302 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 359:
#line 4303 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 360:
#line 4304 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 361:
#line 4305 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 362:
#line 4306 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 363:
#line 4307 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 364:
#line 4308 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 365:
#line 4309 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 366:
#line 4310 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 367:
#line 4311 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 368:
#line 4312 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 369:
#line 4313 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 370:
#line 4314 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 371:
#line 4315 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 372:
#line 4316 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 373:
#line 4317 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 374:
#line 4326 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 375:
#line 4327 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 376:
#line 4328 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 377:
#line 4329 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 378:
#line 4330 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 379:
#line 4331 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 380:
#line 4332 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 381:
#line 4333 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 382:
#line 4334 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 383:
#line 4339 "Gmsh.y"
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

  case 384:
#line 4360 "Gmsh.y"
    {
      char tmpstring[1024];
      sprintf(tmpstring, "%s_%d", (yyvsp[(1) - (5)].c), (int)(yyvsp[(4) - (5)].d)) ;
      if(!gmsh_yysymbols.count(tmpstring)){
	yymsg(0, "Unknown variable '%s'", tmpstring);
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[tmpstring]);
        if(s.value.empty()){
          yymsg(0, "Uninitialized variable '%s'", tmpstring);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[0];
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 385:
#line 4379 "Gmsh.y"
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

  case 386:
#line 4397 "Gmsh.y"
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

  case 387:
#line 4409 "Gmsh.y"
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

  case 388:
#line 4426 "Gmsh.y"
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

  case 389:
#line 4447 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 390:
#line 4452 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 391:
#line 4457 "Gmsh.y"
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

  case 392:
#line 4467 "Gmsh.y"
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

  case 393:
#line 4477 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 394:
#line 4482 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 395:
#line 4491 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 396:
#line 4496 "Gmsh.y"
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

  case 397:
#line 4523 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 398:
#line 4527 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 399:
#line 4531 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 400:
#line 4535 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 401:
#line 4539 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 402:
#line 4546 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 403:
#line 4550 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 404:
#line 4554 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 405:
#line 4558 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 406:
#line 4565 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 407:
#line 4570 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 408:
#line 4577 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 409:
#line 4582 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 410:
#line 4586 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 411:
#line 4591 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 412:
#line 4595 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 413:
#line 4603 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 414:
#line 4614 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 415:
#line 4618 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 416:
#line 4630 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 417:
#line 4638 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 418:
#line 4646 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 419:
#line 4653 "Gmsh.y"
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

  case 420:
#line 4663 "Gmsh.y"
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

  case 421:
#line 4683 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 422:
#line 4687 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 423:
#line 4691 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 424:
#line 4695 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 425:
#line 4699 "Gmsh.y"
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

  case 426:
#line 4728 "Gmsh.y"
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

  case 427:
#line 4757 "Gmsh.y"
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

  case 428:
#line 4786 "Gmsh.y"
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

  case 429:
#line 4815 "Gmsh.y"
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

  case 430:
#line 4825 "Gmsh.y"
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

  case 431:
#line 4835 "Gmsh.y"
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

  case 432:
#line 4848 "Gmsh.y"
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

  case 433:
#line 4860 "Gmsh.y"
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

  case 434:
#line 4872 "Gmsh.y"
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

  case 435:
#line 4891 "Gmsh.y"
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

  case 436:
#line 4912 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 437:
#line 4917 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 438:
#line 4921 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 439:
#line 4925 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 440:
#line 4937 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 441:
#line 4941 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 442:
#line 4953 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 443:
#line 4960 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 444:
#line 4970 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 445:
#line 4974 "Gmsh.y"
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

  case 446:
#line 4989 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 447:
#line 4994 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 448:
#line 5001 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 449:
#line 5005 "Gmsh.y"
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

  case 450:
#line 5018 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 451:
#line 5026 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 452:
#line 5037 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 453:
#line 5041 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 454:
#line 5049 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 455:
#line 5057 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 456:
#line 5065 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 457:
#line 5073 "Gmsh.y"
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

  case 458:
#line 5087 "Gmsh.y"
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

  case 459:
#line 5101 "Gmsh.y"
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

  case 460:
#line 5113 "Gmsh.y"
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

  case 461:
#line 5130 "Gmsh.y"
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

  case 462:
#line 5146 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 463:
#line 5151 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 464:
#line 5155 "Gmsh.y"
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

  case 465:
#line 5175 "Gmsh.y"
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

  case 466:
#line 5197 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 467:
#line 5202 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 10632 "Gmsh.tab.cpp"
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


#line 5205 "Gmsh.y"


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

