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
     tHole = 354,
     tAlias = 355,
     tAliasWithOptions = 356,
     tQuadTriDbl = 357,
     tQuadTriSngl = 358,
     tRecombLaterals = 359,
     tTransfQuadTri = 360,
     tText2D = 361,
     tText3D = 362,
     tInterpolationScheme = 363,
     tTime = 364,
     tCombine = 365,
     tBSpline = 366,
     tBezier = 367,
     tNurbs = 368,
     tNurbsOrder = 369,
     tNurbsKnots = 370,
     tColor = 371,
     tColorTable = 372,
     tFor = 373,
     tIn = 374,
     tEndFor = 375,
     tIf = 376,
     tEndIf = 377,
     tExit = 378,
     tAbort = 379,
     tField = 380,
     tReturn = 381,
     tCall = 382,
     tFunction = 383,
     tShow = 384,
     tHide = 385,
     tGetValue = 386,
     tGetEnv = 387,
     tGetString = 388,
     tHomology = 389,
     tCohomology = 390,
     tBetti = 391,
     tSetOrder = 392,
     tGMSH_MAJOR_VERSION = 393,
     tGMSH_MINOR_VERSION = 394,
     tGMSH_PATCH_VERSION = 395,
     tAFFECTDIVIDE = 396,
     tAFFECTTIMES = 397,
     tAFFECTMINUS = 398,
     tAFFECTPLUS = 399,
     tOR = 400,
     tAND = 401,
     tNOTEQUAL = 402,
     tEQUAL = 403,
     tGREATEROREQUAL = 404,
     tLESSOREQUAL = 405,
     UNARYPREC = 406,
     tMINUSMINUS = 407,
     tPLUSPLUS = 408
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
#define tHole 354
#define tAlias 355
#define tAliasWithOptions 356
#define tQuadTriDbl 357
#define tQuadTriSngl 358
#define tRecombLaterals 359
#define tTransfQuadTri 360
#define tText2D 361
#define tText3D 362
#define tInterpolationScheme 363
#define tTime 364
#define tCombine 365
#define tBSpline 366
#define tBezier 367
#define tNurbs 368
#define tNurbsOrder 369
#define tNurbsKnots 370
#define tColor 371
#define tColorTable 372
#define tFor 373
#define tIn 374
#define tEndFor 375
#define tIf 376
#define tEndIf 377
#define tExit 378
#define tAbort 379
#define tField 380
#define tReturn 381
#define tCall 382
#define tFunction 383
#define tShow 384
#define tHide 385
#define tGetValue 386
#define tGetEnv 387
#define tGetString 388
#define tHomology 389
#define tCohomology 390
#define tBetti 391
#define tSetOrder 392
#define tGMSH_MAJOR_VERSION 393
#define tGMSH_MINOR_VERSION 394
#define tGMSH_PATCH_VERSION 395
#define tAFFECTDIVIDE 396
#define tAFFECTTIMES 397
#define tAFFECTMINUS 398
#define tAFFECTPLUS 399
#define tOR 400
#define tAND 401
#define tNOTEQUAL 402
#define tEQUAL 403
#define tGREATEROREQUAL 404
#define tLESSOREQUAL 405
#define UNARYPREC 406
#define tMINUSMINUS 407
#define tPLUSPLUS 408




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
#line 512 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 525 "Gmsh.tab.cpp"

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
#define YYLAST   8505

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  174
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  462
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1612

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   408

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   159,     2,   169,     2,   158,     2,     2,
     164,   165,   156,   154,   170,   155,   168,   157,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     150,     2,   151,   145,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   166,     2,   167,   163,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   171,     2,   172,   173,     2,     2,     2,
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
     146,   147,   148,   149,   152,   153,   160,   161,   162
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
    1628,  1631,  1637,  1645,  1655,  1658,  1661,  1665,  1668,  1672,
    1682,  1689,  1690,  1694,  1695,  1697,  1698,  1701,  1702,  1705,
    1713,  1720,  1729,  1735,  1739,  1747,  1753,  1758,  1765,  1772,
    1785,  1796,  1807,  1818,  1829,  1840,  1845,  1850,  1853,  1857,
    1864,  1866,  1868,  1870,  1873,  1879,  1887,  1898,  1900,  1904,
    1907,  1910,  1913,  1917,  1921,  1925,  1929,  1933,  1937,  1941,
    1945,  1949,  1953,  1957,  1961,  1965,  1969,  1975,  1980,  1985,
    1990,  1995,  2000,  2005,  2010,  2015,  2020,  2025,  2032,  2037,
    2042,  2047,  2052,  2057,  2062,  2069,  2076,  2083,  2088,  2093,
    2098,  2103,  2108,  2113,  2118,  2123,  2128,  2133,  2138,  2145,
    2150,  2155,  2160,  2165,  2170,  2175,  2182,  2189,  2196,  2201,
    2203,  2205,  2207,  2209,  2211,  2213,  2215,  2217,  2219,  2221,
    2227,  2232,  2237,  2240,  2246,  2250,  2257,  2262,  2270,  2277,
    2284,  2291,  2296,  2298,  2301,  2304,  2308,  2312,  2324,  2334,
    2342,  2350,  2352,  2356,  2358,  2360,  2363,  2367,  2372,  2378,
    2380,  2382,  2385,  2389,  2393,  2399,  2404,  2407,  2410,  2413,
    2416,  2422,  2428,  2434,  2440,  2442,  2444,  2448,  2452,  2457,
    2464,  2471,  2473,  2475,  2479,  2483,  2493,  2501,  2503,  2509,
    2513,  2520,  2522,  2526,  2528,  2530,  2534,  2541,  2543,  2545,
    2550,  2557,  2564,  2569,  2574,  2583,  2588,  2593,  2598,  2603,
    2610,  2617,  2619
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     175,     0,    -1,   176,    -1,     1,     6,    -1,    -1,   176,
     177,    -1,   180,    -1,   179,    -1,   198,    -1,   212,    -1,
     217,    -1,   221,    -1,   222,    -1,   223,    -1,   226,    -1,
     246,    -1,   247,    -1,   225,    -1,   224,    -1,   220,    -1,
     249,    -1,   151,    -1,   151,   151,    -1,    36,   164,   262,
     165,     6,    -1,    37,   164,   262,   165,     6,    -1,    36,
     164,   262,   165,   178,   262,     6,    -1,    36,   164,   262,
     170,   258,   165,     6,    -1,    37,   164,   262,   170,   258,
     165,     6,    -1,    36,   164,   262,   170,   258,   165,   178,
     262,     6,    -1,     4,   262,   171,   181,   172,     6,    -1,
     100,     4,   166,   250,   167,     6,    -1,   101,     4,   166,
     250,   167,     6,    -1,    -1,   181,   184,    -1,   181,   188,
      -1,   181,   191,    -1,   181,   193,    -1,   181,   194,    -1,
     250,    -1,   182,   170,   250,    -1,   250,    -1,   183,   170,
     250,    -1,    -1,    -1,     4,   185,   164,   182,   165,   186,
     171,   183,   172,     6,    -1,   262,    -1,   187,   170,   262,
      -1,    -1,   106,   164,   250,   170,   250,   170,   250,   165,
     189,   171,   187,   172,     6,    -1,   262,    -1,   190,   170,
     262,    -1,    -1,   107,   164,   250,   170,   250,   170,   250,
     170,   250,   165,   192,   171,   190,   172,     6,    -1,   108,
     171,   254,   172,   171,   254,   172,     6,    -1,   108,   171,
     254,   172,   171,   254,   172,   171,   254,   172,   171,   254,
     172,     6,    -1,    -1,   109,   195,   171,   183,   172,     6,
      -1,     7,    -1,   144,    -1,   143,    -1,   142,    -1,   141,
      -1,   162,    -1,   161,    -1,    56,   166,   200,   167,     6,
      -1,    57,   166,   203,   167,     6,    -1,     4,   196,   255,
       6,    -1,     4,   166,   167,   196,   255,     6,    -1,     4,
     166,   250,   167,   196,   250,     6,    -1,     4,   164,   250,
     165,   196,   250,     6,    -1,     4,   166,   171,   258,   172,
     167,   196,   255,     6,    -1,     4,   164,   171,   258,   172,
     165,   196,   255,     6,    -1,     4,   197,     6,    -1,     4,
     166,   250,   167,   197,     6,    -1,     4,     7,   263,     6,
      -1,     4,   168,     4,     7,   263,     6,    -1,     4,   166,
     250,   167,   168,     4,     7,   263,     6,    -1,     4,   168,
       4,   196,   250,     6,    -1,     4,   166,   250,   167,   168,
       4,   196,   250,     6,    -1,     4,   168,     4,   197,     6,
      -1,     4,   166,   250,   167,   168,     4,   197,     6,    -1,
       4,   168,   116,   168,     4,     7,   259,     6,    -1,     4,
     166,   250,   167,   168,   116,   168,     4,     7,   259,     6,
      -1,     4,   168,   117,     7,   260,     6,    -1,     4,   166,
     250,   167,   168,   117,     7,   260,     6,    -1,     4,   125,
       7,   250,     6,    -1,   125,   166,   250,   167,     7,     4,
       6,    -1,   125,   166,   250,   167,   168,     4,     7,   250,
       6,    -1,   125,   166,   250,   167,   168,     4,     7,   263,
       6,    -1,   125,   166,   250,   167,   168,     4,     7,   171,
     258,   172,     6,    -1,   125,   166,   250,   167,   168,     4,
       6,    -1,    81,   164,     4,   165,   168,     4,     7,   250,
       6,    -1,    81,   164,     4,   165,   168,     4,     7,   263,
       6,    -1,    -1,   170,    -1,    -1,   200,   199,     4,    -1,
     200,   199,     4,     7,   250,    -1,    -1,   200,   199,     4,
       7,   171,   250,   201,   205,   172,    -1,   200,   199,     4,
       7,   263,    -1,    -1,   200,   199,     4,     7,   171,   263,
     202,   207,   172,    -1,    -1,   203,   199,   262,    -1,   250,
       7,   263,    -1,   204,   170,   250,     7,   263,    -1,    -1,
     205,   206,    -1,   170,     4,   255,    -1,   170,     4,   171,
     204,   172,    -1,   170,     4,   263,    -1,    -1,   207,   208,
      -1,   170,     4,   250,    -1,   170,     4,   263,    -1,   170,
       4,   171,   264,   172,    -1,   250,    -1,   263,    -1,    -1,
     119,    62,   171,   250,   172,    -1,    -1,    73,   252,    -1,
      58,   164,   250,   165,     7,   252,     6,    -1,    -1,    77,
      58,   213,   164,   209,   165,     7,   255,     6,    -1,    67,
      68,   255,     7,   250,     6,    -1,    61,   164,   250,   165,
       7,   255,     6,    -1,    82,    61,   255,     6,    -1,    65,
     164,   250,   165,     7,   255,     6,    -1,    59,   164,   250,
     165,     7,   255,   211,     6,    -1,    60,   164,   250,   165,
       7,   255,   211,     6,    -1,   111,   164,   250,   165,     7,
     255,     6,    -1,   112,   164,   250,   165,     7,   255,     6,
      -1,   113,   164,   250,   165,     7,   255,   115,   255,   114,
     250,     6,    -1,    61,     4,   164,   250,   165,     7,   255,
       6,    -1,    78,    61,   164,   250,   165,     7,   255,     6,
      -1,    -1,    77,    61,   214,   164,   209,   165,     7,   255,
       6,    -1,    73,    64,   164,   250,   165,     7,   255,     6,
      -1,    74,    64,   164,   250,   165,     7,   255,   210,     6,
      -1,    12,    13,     6,    -1,    13,    64,   250,     6,    -1,
      69,    64,   164,   250,   165,     7,     5,     5,     5,     6,
      -1,    62,   164,   250,   165,     7,   255,     6,    -1,    63,
     164,   250,   165,     7,   255,     6,    -1,    64,     4,   164,
     250,   165,     7,   255,     6,    -1,    78,    64,   164,   250,
     165,     7,   255,     6,    -1,    78,    64,   164,   250,   165,
       7,   255,     4,   171,   254,   172,     6,    -1,    -1,    77,
      64,   215,   164,   209,   165,     7,   255,     6,    -1,    76,
      66,   164,   250,   165,     7,   255,     6,    -1,    66,   164,
     250,   165,     7,   255,     6,    -1,    78,    66,   164,   250,
     165,     7,   255,     6,    -1,    -1,    77,    66,   216,   164,
     209,   165,     7,   255,     6,    -1,    85,   252,   171,   218,
     172,    -1,    84,   171,   252,   170,   252,   170,   250,   172,
     171,   218,   172,    -1,    86,   252,   171,   218,   172,    -1,
      87,   171,   252,   170,   250,   172,   171,   218,   172,    -1,
      87,   171,   252,   170,   252,   172,   171,   218,   172,    -1,
       4,   171,   218,   172,    -1,    95,    61,   171,   258,   172,
      64,   171,   250,   172,    -1,    92,    61,   164,   250,   165,
     171,   258,   172,     6,    -1,   219,    -1,   217,    -1,    -1,
     219,   212,    -1,   219,    58,   171,   258,   172,     6,    -1,
     219,    61,   171,   258,   172,     6,    -1,   219,    64,   171,
     258,   172,     6,    -1,   219,    66,   171,   258,   172,     6,
      -1,    89,    73,   164,   250,   165,     7,   255,     6,    -1,
      89,    58,   164,   250,   165,     7,   171,   254,   172,     6,
      -1,    89,    73,   164,   250,   165,     7,   171,   252,   170,
     252,   170,   258,   172,     6,    -1,    89,    73,   164,   250,
     165,     7,   171,   252,   170,   252,   170,   252,   170,   258,
     172,     6,    -1,    89,    62,   164,   250,   165,     7,   171,
     252,   170,   258,   172,     6,    -1,    89,     4,   164,   250,
     165,     7,   255,     6,    -1,    89,     4,   164,   250,   165,
       7,     5,     6,    -1,    89,     4,   171,   250,   172,     6,
      -1,    89,     4,   164,   250,   165,     7,   171,   252,   170,
     252,   170,   258,   172,     6,    -1,    93,   171,   219,   172,
      -1,    93,   125,   166,   250,   167,     6,    -1,    93,     4,
     166,   250,   167,     6,    -1,    93,     4,     6,    -1,    93,
       4,     4,     6,    -1,   116,   259,   171,   219,   172,    -1,
      83,   116,   259,   171,   219,   172,    -1,   129,     5,     6,
      -1,   130,     5,     6,    -1,   129,   171,   219,   172,    -1,
      83,   129,   171,   219,   172,    -1,   130,   171,   219,   172,
      -1,    83,   130,   171,   219,   172,    -1,     4,   263,     6,
      -1,     4,     4,   166,   250,   167,   262,     6,    -1,     4,
       4,     4,   166,   250,   167,     6,    -1,     4,   250,     6,
      -1,    81,   164,     4,   165,   168,     4,     6,    -1,   110,
       4,     6,    -1,   123,     6,    -1,   124,     6,    -1,    52,
       6,    -1,    47,     6,    -1,    47,   171,   250,   170,   250,
     170,   250,   170,   250,   170,   250,   170,   250,   172,     6,
      -1,    48,     6,    -1,    53,     6,    -1,    54,     6,    -1,
      71,     6,    -1,    72,   171,   258,   172,   171,   258,   172,
     171,   254,   172,   171,   250,   170,   250,   172,     6,    -1,
     137,   250,     6,    -1,   118,   164,   250,     8,   250,   165,
      -1,   118,   164,   250,     8,   250,     8,   250,   165,    -1,
     118,     4,   119,   171,   250,     8,   250,   172,    -1,   118,
       4,   119,   171,   250,     8,   250,     8,   250,   172,    -1,
     120,    -1,   128,     4,    -1,   126,    -1,   127,     4,     6,
      -1,   121,   164,   250,   165,    -1,   122,    -1,    88,   252,
     171,   219,   172,    -1,    88,   171,   252,   170,   252,   170,
     250,   172,   171,   219,   172,    -1,    88,   171,   252,   170,
     252,   170,   252,   170,   250,   172,   171,   219,   172,    -1,
      -1,    88,   252,   171,   219,   227,   240,   172,    -1,    -1,
      88,   171,   252,   170,   252,   170,   250,   172,   171,   219,
     228,   240,   172,    -1,    -1,    88,   171,   252,   170,   252,
     170,   252,   170,   250,   172,   171,   219,   229,   240,   172,
      -1,    -1,    88,   171,   219,   230,   240,   172,    -1,    88,
      58,   171,   250,   170,   252,   172,     6,    -1,    88,    61,
     171,   250,   170,   252,   172,     6,    -1,    88,    64,   171,
     250,   170,   252,   172,     6,    -1,    88,    58,   171,   250,
     170,   252,   170,   252,   170,   250,   172,     6,    -1,    88,
      61,   171,   250,   170,   252,   170,   252,   170,   250,   172,
       6,    -1,    88,    64,   171,   250,   170,   252,   170,   252,
     170,   250,   172,     6,    -1,    88,    58,   171,   250,   170,
     252,   170,   252,   170,   252,   170,   250,   172,     6,    -1,
      88,    61,   171,   250,   170,   252,   170,   252,   170,   252,
     170,   250,   172,     6,    -1,    88,    64,   171,   250,   170,
     252,   170,   252,   170,   252,   170,   250,   172,     6,    -1,
      -1,    88,    58,   171,   250,   170,   252,   172,   231,   171,
     240,   172,     6,    -1,    -1,    88,    61,   171,   250,   170,
     252,   172,   232,   171,   240,   172,     6,    -1,    -1,    88,
      64,   171,   250,   170,   252,   172,   233,   171,   240,   172,
       6,    -1,    -1,    88,    58,   171,   250,   170,   252,   170,
     252,   170,   250,   172,   234,   171,   240,   172,     6,    -1,
      -1,    88,    61,   171,   250,   170,   252,   170,   252,   170,
     250,   172,   235,   171,   240,   172,     6,    -1,    -1,    88,
      64,   171,   250,   170,   252,   170,   252,   170,   250,   172,
     236,   171,   240,   172,     6,    -1,    -1,    88,    58,   171,
     250,   170,   252,   170,   252,   170,   252,   170,   250,   172,
     237,   171,   240,   172,     6,    -1,    -1,    88,    61,   171,
     250,   170,   252,   170,   252,   170,   252,   170,   250,   172,
     238,   171,   240,   172,     6,    -1,    -1,    88,    64,   171,
     250,   170,   252,   170,   252,   170,   252,   170,   250,   172,
     239,   171,   240,   172,     6,    -1,   241,    -1,   240,   241,
      -1,    98,   171,   250,   172,     6,    -1,    98,   171,   255,
     170,   255,   172,     6,    -1,    98,   171,   255,   170,   255,
     170,   255,   172,     6,    -1,    90,     6,    -1,   102,     6,
      -1,   102,   104,     6,    -1,   103,     6,    -1,   103,   104,
       6,    -1,    99,   164,   250,   165,     7,   255,    80,   250,
       6,    -1,    80,     4,   166,   250,   167,     6,    -1,    -1,
      80,     4,   250,    -1,    -1,     4,    -1,    -1,     7,   255,
      -1,    -1,     7,   250,    -1,    75,    61,   256,     7,   250,
     242,     6,    -1,    75,    64,   256,   244,   243,     6,    -1,
      70,    64,   171,   250,   172,     7,   255,     6,    -1,    75,
      66,   256,   244,     6,    -1,   105,   256,     6,    -1,    96,
      64,   171,   258,   172,   250,     6,    -1,    90,    64,   256,
     245,     6,    -1,    90,    66,   256,     6,    -1,    91,    64,
     255,     7,   250,     6,    -1,    79,    61,   255,     7,   255,
       6,    -1,    79,    64,   250,   171,   258,   172,     7,   250,
     171,   258,   172,     6,    -1,    58,   171,   258,   172,   119,
      64,   171,   250,   172,     6,    -1,    61,   171,   258,   172,
     119,    64,   171,   250,   172,     6,    -1,    58,   171,   258,
     172,   119,    66,   171,   250,   172,     6,    -1,    61,   171,
     258,   172,   119,    66,   171,   250,   172,     6,    -1,    64,
     171,   258,   172,   119,    66,   171,   250,   172,     6,    -1,
      97,    64,   256,     6,    -1,    97,    61,   256,     6,    -1,
      94,     6,    -1,    94,     4,     6,    -1,    94,    58,   171,
     258,   172,     6,    -1,   134,    -1,   135,    -1,   136,    -1,
     248,     6,    -1,   248,   171,   255,   172,     6,    -1,   248,
     171,   255,   170,   255,   172,     6,    -1,   248,   164,   255,
     165,   171,   255,   170,   255,   172,     6,    -1,   251,    -1,
     164,   250,   165,    -1,   155,   250,    -1,   154,   250,    -1,
     159,   250,    -1,   250,   155,   250,    -1,   250,   154,   250,
      -1,   250,   156,   250,    -1,   250,   157,   250,    -1,   250,
     158,   250,    -1,   250,   163,   250,    -1,   250,   150,   250,
      -1,   250,   151,   250,    -1,   250,   153,   250,    -1,   250,
     152,   250,    -1,   250,   149,   250,    -1,   250,   148,   250,
      -1,   250,   147,   250,    -1,   250,   146,   250,    -1,   250,
     145,   250,     8,   250,    -1,    14,   164,   250,   165,    -1,
      15,   164,   250,   165,    -1,    16,   164,   250,   165,    -1,
      17,   164,   250,   165,    -1,    18,   164,   250,   165,    -1,
      19,   164,   250,   165,    -1,    20,   164,   250,   165,    -1,
      21,   164,   250,   165,    -1,    22,   164,   250,   165,    -1,
      24,   164,   250,   165,    -1,    25,   164,   250,   170,   250,
     165,    -1,    26,   164,   250,   165,    -1,    27,   164,   250,
     165,    -1,    28,   164,   250,   165,    -1,    29,   164,   250,
     165,    -1,    30,   164,   250,   165,    -1,    31,   164,   250,
     165,    -1,    32,   164,   250,   170,   250,   165,    -1,    33,
     164,   250,   170,   250,   165,    -1,    34,   164,   250,   170,
     250,   165,    -1,    23,   164,   250,   165,    -1,    14,   166,
     250,   167,    -1,    15,   166,   250,   167,    -1,    16,   166,
     250,   167,    -1,    17,   166,   250,   167,    -1,    18,   166,
     250,   167,    -1,    19,   166,   250,   167,    -1,    20,   166,
     250,   167,    -1,    21,   166,   250,   167,    -1,    22,   166,
     250,   167,    -1,    24,   166,   250,   167,    -1,    25,   166,
     250,   170,   250,   167,    -1,    26,   166,   250,   167,    -1,
      27,   166,   250,   167,    -1,    28,   166,   250,   167,    -1,
      29,   166,   250,   167,    -1,    30,   166,   250,   167,    -1,
      31,   166,   250,   167,    -1,    32,   166,   250,   170,   250,
     167,    -1,    33,   166,   250,   170,   250,   167,    -1,    34,
     166,   250,   170,   250,   167,    -1,    23,   166,   250,   167,
      -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,   138,
      -1,   139,    -1,   140,    -1,    50,    -1,    51,    -1,     4,
      -1,     4,   173,   171,   250,   172,    -1,     4,   166,   250,
     167,    -1,   169,     4,   166,   167,    -1,     4,   197,    -1,
       4,   166,   250,   167,   197,    -1,     4,   168,     4,    -1,
       4,   166,   250,   167,   168,     4,    -1,     4,   168,     4,
     197,    -1,     4,   166,   250,   167,   168,     4,   197,    -1,
     131,   164,   262,   170,   250,   165,    -1,    44,   164,   262,
     170,   262,   165,    -1,    45,   164,   262,   170,   262,   165,
      -1,    46,   164,   264,   165,    -1,   253,    -1,   155,   252,
      -1,   154,   252,    -1,   252,   155,   252,    -1,   252,   154,
     252,    -1,   171,   250,   170,   250,   170,   250,   170,   250,
     170,   250,   172,    -1,   171,   250,   170,   250,   170,   250,
     170,   250,   172,    -1,   171,   250,   170,   250,   170,   250,
     172,    -1,   164,   250,   170,   250,   170,   250,   165,    -1,
     255,    -1,   254,   170,   255,    -1,   250,    -1,   257,    -1,
     171,   172,    -1,   171,   258,   172,    -1,   155,   171,   258,
     172,    -1,   250,   156,   171,   258,   172,    -1,   255,    -1,
       5,    -1,   155,   257,    -1,   250,   156,   257,    -1,   250,
       8,   250,    -1,   250,     8,   250,     8,   250,    -1,    58,
     171,   250,   172,    -1,    58,     5,    -1,    61,     5,    -1,
      64,     5,    -1,    66,     5,    -1,    77,    58,   171,   258,
     172,    -1,    77,    61,   171,   258,   172,    -1,    77,    64,
     171,   258,   172,    -1,    77,    66,   171,   258,   172,    -1,
     217,    -1,   226,    -1,     4,   166,   167,    -1,     4,   164,
     165,    -1,    35,   166,     4,   167,    -1,     4,   166,   171,
     258,   172,   167,    -1,     4,   164,   171,   258,   172,   165,
      -1,   250,    -1,   257,    -1,   258,   170,   250,    -1,   258,
     170,   257,    -1,   171,   250,   170,   250,   170,   250,   170,
     250,   172,    -1,   171,   250,   170,   250,   170,   250,   172,
      -1,     4,    -1,     4,   168,   116,   168,     4,    -1,   171,
     261,   172,    -1,     4,   166,   250,   167,   168,   117,    -1,
     259,    -1,   261,   170,   259,    -1,   263,    -1,     4,    -1,
       4,   168,     4,    -1,     4,   166,   250,   167,   168,     4,
      -1,     5,    -1,    49,    -1,   132,   164,   262,   165,    -1,
     133,   164,   262,   170,   262,   165,    -1,    40,   164,   262,
     170,   262,   165,    -1,    41,   164,   262,   165,    -1,    42,
     164,   262,   165,    -1,    43,   164,   262,   170,   262,   170,
     262,   165,    -1,    38,   164,   264,   165,    -1,    38,   166,
     264,   167,    -1,    39,   164,   262,   165,    -1,    39,   166,
     262,   167,    -1,    39,   164,   262,   170,   258,   165,    -1,
      39,   166,   262,   170,   258,   167,    -1,   262,    -1,   264,
     170,   262,    -1
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
    1713,  1752,  1758,  1764,  1771,  1796,  1821,  1838,  1855,  1887,
    1886,  1910,  1928,  1945,  1962,  1961,  1987,  1992,  1997,  2002,
    2007,  2012,  2035,  2041,  2052,  2053,  2058,  2061,  2065,  2088,
    2111,  2134,  2162,  2183,  2209,  2230,  2252,  2272,  2384,  2403,
    2441,  2550,  2559,  2565,  2580,  2608,  2625,  2634,  2648,  2654,
    2660,  2669,  2678,  2687,  2701,  2746,  2763,  2778,  2797,  2809,
    2833,  2837,  2842,  2849,  2855,  2860,  2866,  2870,  2874,  2879,
    2934,  2947,  2964,  2981,  3002,  3023,  3058,  3066,  3072,  3079,
    3083,  3092,  3100,  3108,  3117,  3116,  3130,  3129,  3143,  3142,
    3156,  3155,  3168,  3175,  3182,  3189,  3196,  3203,  3210,  3217,
    3224,  3232,  3231,  3244,  3243,  3256,  3255,  3268,  3267,  3280,
    3279,  3292,  3291,  3304,  3303,  3316,  3315,  3328,  3327,  3343,
    3346,  3352,  3364,  3384,  3407,  3411,  3415,  3419,  3423,  3427,
    3446,  3459,  3462,  3478,  3481,  3498,  3501,  3507,  3510,  3517,
    3573,  3643,  3648,  3715,  3751,  3759,  3802,  3841,  3861,  3888,
    3928,  3951,  3974,  3978,  3982,  4005,  4044,  4089,  4093,  4103,
    4138,  4139,  4140,  4144,  4150,  4162,  4180,  4208,  4209,  4210,
    4211,  4212,  4213,  4214,  4215,  4216,  4223,  4224,  4225,  4226,
    4227,  4228,  4229,  4230,  4231,  4232,  4233,  4234,  4235,  4236,
    4237,  4238,  4239,  4240,  4241,  4242,  4243,  4244,  4245,  4246,
    4247,  4248,  4249,  4250,  4251,  4252,  4253,  4254,  4257,  4258,
    4259,  4260,  4261,  4262,  4263,  4264,  4265,  4266,  4267,  4268,
    4269,  4270,  4271,  4272,  4273,  4274,  4275,  4276,  4277,  4286,
    4287,  4288,  4289,  4290,  4291,  4292,  4293,  4294,  4298,  4319,
    4338,  4356,  4368,  4385,  4406,  4411,  4416,  4426,  4436,  4441,
    4450,  4455,  4482,  4486,  4490,  4494,  4498,  4505,  4509,  4513,
    4517,  4524,  4529,  4536,  4541,  4545,  4550,  4554,  4562,  4573,
    4577,  4589,  4597,  4605,  4612,  4622,  4642,  4646,  4650,  4654,
    4658,  4687,  4716,  4745,  4774,  4784,  4794,  4807,  4819,  4831,
    4850,  4871,  4876,  4880,  4884,  4896,  4900,  4912,  4919,  4929,
    4933,  4948,  4953,  4960,  4964,  4977,  4985,  4996,  5000,  5008,
    5016,  5024,  5032,  5046,  5060,  5072,  5089,  5105,  5110,  5114,
    5134,  5156,  5161
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
  "tIntersect", "tMeshAlgorithm", "tReverse", "tLayers", "tHole", "tAlias",
  "tAliasWithOptions", "tQuadTriDbl", "tQuadTriSngl", "tRecombLaterals",
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
     395,   396,   397,   398,   399,    63,   400,   401,   402,   403,
      60,    62,   404,   405,    43,    45,    42,    47,    37,    33,
     406,   407,   408,    94,    40,    41,    91,    93,    46,    35,
      44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   174,   175,   175,   176,   176,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   178,   178,   179,   179,   179,   179,   179,   179,   180,
     180,   180,   181,   181,   181,   181,   181,   181,   182,   182,
     183,   183,   185,   186,   184,   187,   187,   189,   188,   190,
     190,   192,   191,   193,   193,   195,   194,   196,   196,   196,
     196,   196,   197,   197,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   199,   199,   200,   200,   200,   201,   200,
     200,   202,   200,   203,   203,   204,   204,   205,   205,   206,
     206,   206,   207,   207,   208,   208,   208,   209,   209,   210,
     210,   211,   211,   212,   213,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   214,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   215,
     212,   212,   212,   212,   216,   212,   217,   217,   217,   217,
     217,   217,   217,   217,   218,   218,   219,   219,   219,   219,
     219,   219,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   221,   221,   221,   221,   221,   222,   222,   223,   223,
     223,   223,   223,   223,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   226,   226,   226,   227,   226,   228,   226,   229,   226,
     230,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   231,   226,   232,   226,   233,   226,   234,   226,   235,
     226,   236,   226,   237,   226,   238,   226,   239,   226,   240,
     240,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   242,   242,   243,   243,   244,   244,   245,   245,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   247,   247,   247,
     248,   248,   248,   249,   249,   249,   249,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   252,   252,   252,   252,   252,   253,   253,   253,
     253,   254,   254,   255,   255,   255,   255,   255,   255,   256,
     256,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   258,   258,   258,   258,   259,   259,   259,   259,   260,
     260,   261,   261,   262,   262,   262,   262,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   264,   264
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
       2,     5,     7,     9,     2,     2,     3,     2,     3,     9,
       6,     0,     3,     0,     1,     0,     2,     0,     2,     7,
       6,     8,     5,     3,     7,     5,     4,     6,     6,    12,
      10,    10,    10,    10,    10,     4,     4,     2,     3,     6,
       1,     1,     1,     2,     5,     7,    10,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     6,     6,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     4,     2,     5,     3,     6,     4,     7,     6,     6,
       6,     4,     1,     2,     2,     3,     3,    11,     9,     7,
       7,     1,     3,     1,     1,     2,     3,     4,     5,     1,
       1,     2,     3,     3,     5,     4,     2,     2,     2,     2,
       5,     5,     5,     5,     1,     1,     3,     3,     4,     6,
       6,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     1,     3,     6,     1,     1,     4,
       6,     6,     4,     4,     8,     4,     4,     4,     4,     6,
       6,     1,     3
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
       0,   217,     0,     0,     0,     0,   300,   301,   302,     0,
       5,     7,     6,     8,     9,    10,    19,    11,    12,    13,
      18,    17,    14,    15,    16,     0,    20,   369,   378,   447,
      57,   370,   371,   372,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   448,   376,   377,     0,     0,     0,
       0,   373,   374,   375,    61,    60,    59,    58,     0,     0,
       0,    63,    62,     0,     0,     0,     0,   166,     0,     0,
       0,   307,     0,   443,     0,     0,     0,     0,   203,     0,
     205,   202,   206,   207,    95,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   208,     0,     0,     0,     0,     0,     0,     0,
     124,   137,   149,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     392,     0,     0,     0,     0,     0,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,     0,
     297,     0,     0,     0,     0,     0,     0,     0,   378,   410,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   424,
     425,   403,   409,     0,   404,     0,     0,     0,     0,   437,
       0,     0,     0,     0,     0,   200,   201,     0,     0,   216,
       0,   166,     0,   166,   378,     0,   303,     0,     0,     0,
       0,     0,     0,   382,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   310,   309,   311,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,   164,     0,    72,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,   194,   141,     0,
     444,     0,   443,     0,     0,    93,    93,     0,     0,   431,
     432,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     275,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   166,   166,     0,   394,   393,
       0,     0,     0,     0,   166,   166,     0,     0,     0,     0,
       0,     0,     0,   230,     0,   166,     0,     0,     0,     0,
       0,   277,     0,     0,     0,     0,   184,     0,     0,     0,
     298,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   416,     0,   417,   418,   419,     0,     0,     0,
       0,     0,   309,   411,     0,   405,     0,     0,     0,   283,
     199,     0,     0,     0,     0,     0,   166,     0,     0,     0,
       0,   218,   188,     0,   189,     0,     0,   210,     0,     0,
       0,     0,   384,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   308,    57,     0,     0,     0,    57,
       0,     0,     0,     0,     0,   161,     0,     0,     0,     0,
     167,    66,     0,   325,   324,   323,   322,   318,   319,   321,
     320,   313,   312,   314,   315,   316,   317,     0,   142,     0,
       0,     0,     0,     0,     0,     0,     0,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,   166,     0,
       0,     0,     0,     0,   396,   395,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,   286,     0,     0,   185,     0,     0,   181,
       0,     0,     0,   296,   295,     0,     0,   427,     0,   426,
       0,     0,   384,     0,     0,     0,     0,     0,     0,     0,
     308,   406,   413,     0,   314,   412,     0,     0,     0,     0,
       0,     0,     0,     0,   219,     0,   190,   192,     0,     0,
       0,     0,   380,   386,     0,   327,   348,   328,   349,   329,
     350,   330,   351,   331,   352,   332,   353,   333,   354,   334,
     355,   335,   356,   347,   368,   336,   357,     0,     0,   338,
     359,   339,   360,   340,   361,   341,   362,   342,   363,   343,
     364,     0,     0,     0,     0,     0,     0,   455,     0,   456,
     457,     0,   458,     0,     0,   452,   453,     0,     0,     0,
     391,    85,     0,   449,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,     0,     0,     0,   381,
       0,     0,     0,     0,     0,    42,     0,     0,     0,    55,
       0,    33,    34,    35,    36,    37,     0,   445,    23,    21,
       0,     0,    24,     0,     0,    64,    96,    65,   104,     0,
     433,   434,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,   276,   274,     0,   282,     0,     0,   117,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
     193,     0,     0,     0,   156,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   259,     0,
     221,     0,     0,     0,     0,     0,     0,   278,   285,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     380,   428,   415,     0,     0,     0,     0,   407,     0,     0,
       0,     0,     0,     0,     0,   186,     0,     0,     0,     0,
       0,     0,   304,     0,     0,   383,     0,   379,     0,     0,
       0,     0,     0,     0,     0,     0,   462,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,     0,
       0,     0,     0,    73,    75,    77,     0,     0,   441,     0,
      83,     0,     0,     0,     0,   326,     0,     0,     0,     0,
       0,    29,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     0,   121,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,     0,     0,     0,     0,     0,
       0,     0,   280,     0,     0,     0,     0,     0,     0,     0,
       0,   288,     0,     0,   187,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,     0,     0,   265,     0,   267,
       0,   231,   260,     0,     0,     0,   179,     0,     0,     0,
     287,     0,   183,   182,   299,     0,     0,    30,    31,     0,
       0,     0,   420,   421,   422,   423,   414,   408,     0,     0,
       0,   438,     0,     0,     0,   211,     0,     0,     0,     0,
     196,   385,   195,   337,   358,   344,   365,   345,   366,   346,
     367,   459,   460,   451,     0,   389,   390,   388,   450,     0,
      69,     0,    57,     0,     0,     0,     0,    68,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
     401,     0,     0,    25,    26,     0,    27,     0,     0,    97,
     100,   123,     0,     0,     0,     0,     0,     0,   127,     0,
       0,   144,   145,     0,     0,   129,   152,     0,     0,     0,
       0,   119,     0,   279,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   198,     0,     0,     0,     0,   166,   166,
       0,   241,     0,   243,     0,   245,     0,   403,     0,     0,
     266,   268,     0,     0,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   284,   430,   429,   385,   132,   133,
       0,     0,     0,     0,    86,    90,     0,     0,   305,   387,
       0,     0,     0,     0,     0,    80,     0,     0,    81,     0,
     442,   168,   169,   170,   171,     0,    38,     0,     0,     0,
       0,     0,    40,   446,     0,     0,    98,   101,     0,     0,
     122,   130,   131,   135,     0,     0,   146,     0,     0,   281,
       0,   139,     0,     0,   272,   151,     0,     0,     0,     0,
     136,     0,   147,   153,     0,     0,     0,     0,   400,     0,
     399,     0,     0,     0,   232,     0,     0,   233,     0,     0,
     234,     0,     0,     0,     0,     0,     0,     0,   178,     0,
       0,   177,     0,     0,     0,   172,     0,     0,     0,     0,
     436,     0,   213,   212,     0,     0,     0,     0,   454,    71,
      70,    76,    78,     0,    84,     0,    43,     0,     0,     0,
     402,     0,     0,     0,    28,     0,   107,   112,     0,     0,
       0,     0,     0,     0,     0,     0,   140,   125,   138,   150,
     155,     0,     0,    91,    92,   166,     0,   159,   160,     0,
       0,     0,     0,     0,     0,     0,   261,     0,     0,   166,
       0,     0,     0,     0,     0,   163,   162,     0,     0,     0,
       0,    87,    88,     0,     0,   440,     0,    39,     0,     0,
       0,    41,    56,     0,     0,     0,   290,   292,   291,   293,
     294,   143,     0,     0,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,     0,
       0,     0,   226,     0,     0,   173,     0,     0,     0,   435,
     214,     0,   306,    82,     0,     0,     0,     0,     0,     0,
      99,   108,     0,   102,   113,     0,     0,     0,     0,   157,
       0,   247,     0,     0,   249,     0,     0,   251,     0,     0,
       0,   262,     0,   222,     0,   166,     0,     0,     0,   134,
      89,     0,    47,     0,    53,     0,     0,     0,     0,     0,
     120,   148,   289,   397,   235,     0,     0,   242,   236,     0,
       0,   244,   237,     0,     0,   246,     0,     0,     0,   228,
       0,   176,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   111,     0,   114,   115,     0,     0,   253,     0,   255,
       0,   257,   263,   269,   227,   223,     0,     0,     0,     0,
      44,     0,    51,     0,     0,     0,   431,     0,     0,     0,
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
      -1,     2,     3,    80,   840,    81,    82,   617,  1245,  1251,
     831,   996,  1396,  1562,   832,  1515,  1596,   833,  1564,   834,
     835,  1000,   158,   293,    83,   628,   395,  1346,  1347,   396,
    1545,  1404,  1451,  1405,  1454,   876,  1273,  1155,   600,   423,
     424,   425,   426,   259,   366,   367,    86,    87,    88,    89,
      90,    91,   260,   911,  1474,  1536,   683,  1295,  1298,  1301,
    1495,  1499,  1503,  1551,  1554,  1557,   907,   908,  1031,   873,
     654,   692,    93,    94,    95,    96,   261,   161,   439,   220,
    1139,   262,   263,   264,   496,   271,   818,   989,   567,   392,
     568
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1204
static const yytype_int16 yypact[] =
{
    4748,    20,    62,  4843, -1204, -1204,  2459,   124,   -17,  -130,
      -9,    -3,   143,   160,   198,   228,   100,   109,   -82,    51,
      95,     9,   117,   137,    21,   149,   167,   239,   299,   308,
     373,   238,   350,   360,   244,   379,   548,   472,   210,   274,
     388,   -16,   315,    82,    82,   341,   297,    34,   -21,   456,
     406,    19,    40,   478,   465,   432,   559,   569,  2659,   594,
     392,   440,   463,    23,    37, -1204,   473, -1204,   607,   613,
     491, -1204,   659,   665,    13,    27, -1204, -1204, -1204,  1418,
   -1204, -1204, -1204, -1204, -1204, -1204, -1204, -1204, -1204, -1204,
   -1204, -1204, -1204, -1204, -1204,    36, -1204, -1204,     8, -1204,
     662, -1204, -1204, -1204,   190,   296,   309,   403,   430,   457,
     467,   508,   528,   551,   552,   571,   593,   617,   623,   636,
     637,   640,   641,   646,   647,   650,   672,   512,   529,   543,
     570,   612,   616,   622, -1204, -1204, -1204,   751,   626,   651,
     654, -1204, -1204, -1204, -1204, -1204, -1204, -1204,  1418,  1418,
    1418, -1204, -1204,  4240,  2405,    47,   767,   355,  3000,   840,
    1015, -1204,   684,   850,   870,  1418,   475,   475, -1204,  1418,
   -1204, -1204, -1204, -1204, -1204, -1204,  1418,  4447,  1418,  1418,
     669,  1418,  4447,  1418,  1418,   713,  4447,  1418,  1418,  3000,
     716,   714, -1204,  4447,   773,   789,  2659,  2659,  2659,   794,
   -1204, -1204, -1204, -1204,   795,   813,   814,  3000,  1418,   927,
    3000,    23,   757,   819,    82,    82,    82,  1418,  1418,  -115,
   -1204,   -97,    82,   820,   833,   836,  4284,   -78,   -62,   834,
     837,   848,  2659,  2659,  3000,   868,    25,   778, -1204,  1011,
   -1204,   845,   851,   874,  2659,  2659,   880,   888,   138, -1204,
     894,    28,  1031,  1067,  1075,   600,  3163,  1418,   371, -1204,
   -1204,   169, -1204,  1055, -1204,  1059,  1418,  1418,  1418,   898,
    1418,   928,   984,  1418,  1418, -1204, -1204,  1418,  1080, -1204,
    1103, -1204,  1104, -1204,   303,  1184, -1204,  3000,  3000,   947,
    1418,  1116,   950, -1204,  1127,  1418,  1418,  1418,  1418,  1418,
    1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,
    1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,
    1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,
    1418,  1418,  1418,  1418,  1418,  1418,  1418,   475,   475,   475,
     475,   475,   475,   475,   475,   475,   475,   475,  1418,   475,
     475,   475,   977,   977,   977,  4447,  7187,   136,  4447,  6428,
     209,   976,  1145,   987,  1004, -1204,  1023,  3899,  1170, -1204,
   -1204,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,
    1418,  1418,  1418,  1418,  1418,  1418, -1204, -1204, -1204,  1348,
     673,   -71, -1204,    41,  5700,   468,   479,  7208,  4447,   575,
   -1204,   670,  7229,  7250,  1418,  7271,   680,  7292,  7313,  1418,
     681,  7334,  7355,  1192,  1418,  1418,   699,  1418,  1418,  1195,
    1212,  1212,  1418,  1058,  1062,  1071,  1078,  1418,  1418,  1418,
    1232,  5620,  1081,  1241,  1090, -1204, -1204,    88, -1204, -1204,
    5726,  5752,    82,    82,   355,   355,   113,  1418,  1418,  1418,
    4284,  4284,  1418,  3899,   187, -1204,  1418,  1418,  1418,  1418,
    1418,  1245,  1256,  1276,  1418,  1278, -1204,  1418,  1418,   488,
   -1204,  4447,  4447,  4447,  1297,  1298,  1418,  1418,    80,  4071,
    1301,  1306, -1204,  1418, -1204, -1204, -1204,  1142,  1144,  1146,
    1147,  4447,   977, -1204,  7376, -1204,   702,  1418,  3326, -1204,
   -1204,  7397,  7418,  7439,  1196,  5778, -1204,  1148,  4511,  7460,
    6451, -1204, -1204,  2035, -1204,  2119,  1418, -1204,  1157,   703,
    1418,  6474,   265,  1418, -1204,  7481,  6497,  7502,  6520,  7523,
    6543,  7544,  6566,  7565,  6589,  7586,  6612,  7607,  6635,  7628,
    6658,  7649,  6681,  7670,  6704,  7691,  6727,  5804,  5830,  7712,
    6750,  7733,  6773,  7754,  6796,  7775,  6819,  7796,  6842,  7817,
    6865,  5856,  5882,  5908,  5934,  5960,  5986, -1204,   213,   480,
     255,   481,  1155,  1161,  1163,  1173,  1174,  1175,   263,  1518,
    1176,  1183,  1179,   771,   136, -1204,  3000,   775,   205,   662,
    1418,  1344,  1347,    24,  1185, -1204,    67,    11,    26,    83,
   -1204, -1204,  4530,  1123,  1139,   830,   830,   592,   592,   592,
     592,   106,   106,   977,   977,   977,   977,    33, -1204,  1418,
    1349,     3,  4447,  1350,  4447,  1418,  1351, -1204,  1356,  1355,
     475,  1358,  4447,  4447,  1236,  1359,  1360,  7838,  1361,  1243,
    1362,  1363,  7859,  1244,  1364,  1371,  1418,  7880,  4892,  1208,
    7901,  7922,  1418,  3000,  1376,  1375,  7943,  4604,  4604,  4604,
    4604,  7964,  7985,  8006,  3000,  4447,  1215, -1204, -1204,  2887,
    3040,    82,  1418,  1418, -1204, -1204,  1213,  1214,  4284,  6012,
    6038,  6064,  5674,   -30,    82,  3203,  8027,  4920,  8048,  8069,
    8090,  1418,  1381, -1204,  1418,  8111, -1204,  6888,  6911, -1204,
     824,   827,   853, -1204, -1204,  6934,  6957, -1204,  4447, -1204,
    4447,  6980,   -91,  1221,  4948,  4447,  4447,  4447,  4447,   856,
   -1204, -1204,  4551,  4447,   977, -1204,  1382,  1384,  1387,  1227,
    1418,  3366,  1418,  1418, -1204,    15, -1204, -1204,  1225,  3000,
    1392,  7003,   449, -1204,  4976, -1204, -1204, -1204, -1204, -1204,
   -1204, -1204, -1204, -1204, -1204, -1204, -1204, -1204, -1204, -1204,
   -1204, -1204, -1204, -1204, -1204, -1204, -1204,  1418,  1418, -1204,
   -1204, -1204, -1204, -1204, -1204, -1204, -1204, -1204, -1204, -1204,
   -1204,  1418,  1418,  1418,  1418,  1418,  1418, -1204,   475, -1204,
   -1204,  4447, -1204,  4447,   475, -1204, -1204,   475,   475,   475,
   -1204, -1204,  1418, -1204,   475,  1234,  1418,  1394,  1235,    93,
    1418,  1397,  1399,  1736, -1204,  1400,  1251,    23,  1403, -1204,
    4447,  4447,  4447,  4447,  1418, -1204,  1246,  1254,  1249, -1204,
    1417, -1204, -1204, -1204, -1204, -1204,  7026, -1204, -1204,  1273,
     475,   362, -1204,   372,  6090, -1204,  1419, -1204, -1204,    82,
     575, -1204,   779,  3000,  3000,  1423,  3000,   963,  3000,  3000,
    1424,  1388,  3000,  3000,  1789,  1446,  1448,  4447,  1449,  1450,
     674, -1204, -1204,  1453, -1204,  1454,  1260,  8342, -1204,  1295,
    1300,  1302,  1459,  1463,  1464,  1466,   861,  1469,  3529, -1204,
   -1204,   214,  6116,  6142, -1204, -1204,  5004,  -119,    82,    82,
      82,  1470,  1471,  1304,  1312,    46,    49,   -15, -1204,   253,
   -1204,   -30,  1472,  1474,  1477,  1478,  1479,  8342, -1204,  2202,
    1307,  1475,  1481,  1482,  1426,  1418,  1485,  1501,   865,   899,
     424, -1204, -1204,   903,   906,   907,   911, -1204,  1418,   915,
    3000,  3000,  3000,  1504,  6168, -1204,  4571,   533,  1505,  1506,
    3000,  1340, -1204,  1508,  1513, -1204,  1509, -1204,  8132,  7049,
    8153,  7072,  8174,  7095,  8195,  7118, -1204,   455,   501,  1353,
    1352,  1354,  1365,  8216,  1366,   136,  2488, -1204,   136,   269,
    1357,  1514,  2610, -1204, -1204, -1204,    23,  1418, -1204,   920,
   -1204,   921,   924,   925,   930,  8342,  1369,  1418,  1418,  3000,
    1367, -1204,  1368, -1204,  1517,    57,  1520,  1418,  3815,    48,
    1370,  1372,  1447,  1447,  3000,  1521,  1373,  1374,  1522,  1528,
    3000,  1377,  1531,  1533, -1204,  1535,  3000,   934,  3000,  3000,
    1538,  1540, -1204,  3000,  1543,  1544,  1545,  1547,  3000,  3000,
    3000, -1204,  1548,   745, -1204,  1418,  1418,  1418,  1389,  1390,
    -106,   -69,   -64,  1393, -1204,  3000,  1418, -1204,  1541, -1204,
    1556, -1204, -1204,  4284,   542,  2837, -1204,  1395,  1396,  3489,
   -1204,  4447, -1204, -1204, -1204,  1398,  3603, -1204, -1204,  1405,
    1401,  1559, -1204, -1204, -1204, -1204,  8342, -1204,  1565,  1569,
    1465, -1204,  1418,  1418,  1418, -1204,  1573,   790,  1411,  1577,
   -1204,   397, -1204, -1204, -1204, -1204, -1204, -1204, -1204, -1204,
   -1204, -1204, -1204, -1204,   475, -1204, -1204, -1204, -1204,  3000,
   -1204,  3000,   662,  1418,  1578,  1561,    24, -1204,  1579,  7141,
      23, -1204,  1580,  1584,  1585,  1586,  1418,  6194,  6220,   946,
   -1204,  1418,  1589, -1204, -1204,   475, -1204,  6246,  4604,  8342,
   -1204, -1204,  1418,  1418,    82,  1590,  1594,  1595, -1204,  1418,
    1418, -1204, -1204,  1596,  1418, -1204, -1204,  1598,  1602,  1433,
    1603,  1476,  1418, -1204,  1604,  3000,  3000,  3000,  3000,  1605,
    1141,  1606,  1418, -1204,  4604,  5032,  8237,  2630,   355,   355,
      82,  1607,    82,  1608,    82,  1609,  1418,    72,  1451,  8258,
   -1204, -1204,  5060,   264, -1204,  1610,   101,  1611,  3000,    82,
     101,  1612,   978,  1418, -1204, -1204, -1204,   -91, -1204, -1204,
    3000,  4836,   140,  8279, -1204, -1204,  3864,  3000, -1204, -1204,
    1457,  1613,  1617,  1618,  3624, -1204,  1619,  1621, -1204,  1460,
   -1204, -1204, -1204, -1204, -1204,   464,  8342,  1418,  1418,  3000,
    1458,   979,  8342, -1204,  1624,  1418,  8342, -1204,  5088,  5116,
     340, -1204, -1204, -1204,  5144,  5172, -1204,  5200,  1628, -1204,
    3000, -1204,  1572,  1629,  8342, -1204,  1633,  1634,  1635,  1636,
   -1204,  1473, -1204, -1204,  5647,  3778,  1637,  1480, -1204,  1418,
   -1204,  1483,  1484,   327, -1204,  1486,   329, -1204,  1487,   349,
   -1204,  1488,  7164,  1639,  3000,  1641,  1489,  1418, -1204,  3652,
     351, -1204,  1010,   353,   390, -1204,  1643,  5228,  1536,  1418,
   -1204,  1418, -1204, -1204,  4447,  3981,  1646,  1507, -1204, -1204,
   -1204, -1204, -1204,    23, -1204,  1560, -1204,  1418,  6272,  6298,
   -1204,  3000,  1418,  1647, -1204,  6324, -1204, -1204,  1655,  1672,
    1674,  1676,  1680,  1681,  1013,  1519, -1204, -1204, -1204, -1204,
   -1204,  3000,  4447, -1204, -1204,   355,  4864, -1204, -1204,  4284,
     -30,  4284,   -30,  4284,   -30,  1683, -1204,  1014,  3000, -1204,
    5256,    82,  1685,  4447,    82, -1204, -1204,  1418,  5284,  5312,
    1021, -1204, -1204,  1686,  1688, -1204,  1524,  8342,  1418,  1418,
    1024,  8342, -1204,  1418,  1028,  1033, -1204, -1204, -1204, -1204,
   -1204, -1204,  1525,  1418,  1036,  1037,  1526,  1418, -1204,  5340,
     417,   663,  5368,   421,   764,  5396,   423,   780, -1204,  3000,
    1693,  1620,  4111,  1530,   425, -1204,  1042,   435,  4193, -1204,
   -1204,  1696, -1204, -1204,  1418,  8300,  6350,     1,  6376,  1699,
   -1204, -1204,  1701, -1204, -1204,  1418,  5424,  1702,  1703, -1204,
    5452,  1704,  1418,  1705,  1706,  1418,  1707,  1709,  1418,  1710,
    1546, -1204,  1418, -1204,   -30, -1204,  4447,  1711,  3652, -1204,
   -1204,  1048, -1204,  1418, -1204,  3000,  1418,  2235,  4027,  6402,
   -1204, -1204, -1204, -1204, -1204,  1549,  5480, -1204, -1204,  1550,
    5508, -1204, -1204,  1551,  5536, -1204,  1713,  4212,   852,  4324,
    1060, -1204,   448,  1061,  1717,  1553,  8321,  1064,  5564,   371,
   -1204, -1204,   475,  8342, -1204,  1418,   -30,  1719,   -30,  1720,
     -30,  1722, -1204, -1204, -1204, -1204,   -30,  1723,  4447,  1724,
   -1204,   475, -1204,  1562,  1725,  1068,  4400,  1087,  5592,   858,
   -1204,  1563,   912, -1204,  1564,   954, -1204,  1566,  1025, -1204,
    1088, -1204,  1095, -1204,  1567,  3000, -1204,  1418, -1204,   662,
   -1204,  1730,  1734,   -30,  1735,   -30,  1739,   -30, -1204,  1740,
     475,  1741,   475,  1096,  4419, -1204, -1204, -1204,  1032, -1204,
    1039, -1204,  1056, -1204, -1204, -1204,  1128, -1204,  1742,   662,
    1743,  1746,  1747,   475,  1748, -1204, -1204, -1204, -1204, -1204,
   -1204, -1204
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1204, -1204, -1204, -1204,   752, -1204, -1204, -1204, -1204,   316,
   -1204, -1204, -1204, -1204, -1204, -1204, -1204, -1204, -1204, -1204,
   -1204, -1204,  -336,     0, -1204,  1311, -1204, -1204, -1204, -1204,
   -1204, -1204, -1204, -1204, -1204,    50, -1204,   746,  1758, -1204,
   -1204, -1204, -1204,    -1,  -425,  -222, -1204, -1204, -1204, -1204,
   -1204, -1204,  1759, -1204, -1204, -1204, -1204, -1204, -1204, -1204,
   -1204, -1204, -1204, -1204, -1204, -1204,  -900,  -893, -1204, -1204,
    1343, -1204, -1204, -1204, -1204, -1204,   591, -1204,    35, -1204,
   -1203,   967,   132,  1134,  1511,  -201,   639, -1204,    -6,    -5,
    -330
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -447
static const yytype_int16 yytable[] =
{
     162,   163,    85,   168,   453,  1312,   159,  1484,   569,   838,
     434,  1064,   289,   180,  1062,   180,   469,   578,   280,   676,
     677,   586,   948,   236,   590,   185,     4,   269,   816,   465,
     185,   466,   282,   482,   166,   442,   443,   825,   228,   442,
     443,   272,   286,   232,   239,   233,   240,   165,   442,   443,
     901,   360,  1057,  1049,  1151,  1059,   444,   442,   443,   513,
     902,   515,     5,  1144,  1190,   901,  1191,  1354,   903,   904,
     151,   152,   905,   906,   445,   902,   442,   443,   219,   221,
     497,   227,   176,   903,   904,   442,   443,   905,   906,   177,
     442,   443,   229,   455,   621,   294,   230,   979,   241,   622,
     211,  1192,   456,  1193,    97,   248,  1194,   231,  1195,   457,
     101,   102,   103,   212,   213,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   250,   164,  1400,   826,
     827,   828,   829,   585,   237,   131,   132,   133,  1321,   170,
    1058,   135,   136,  1060,   839,   167,   365,  1061,  1414,   251,
     391,   393,   252,   361,   362,   253,   171,   254,   169,   151,
     152,  1062,  1485,   181,   290,   181,   291,   497,   255,  -444,
     182,   292,   821,   949,   281,    42,    43,    44,    45,    46,
     238,   467,   186,    50,   270,   817,    53,   822,   283,   483,
     287,   273,   442,   443,   172,   830,   623,   288,   839,   980,
     981,   624,   585,   669,   670,   178,   589,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   498,   383,
     384,   176,   138,   685,   173,   385,   215,   216,   820,   141,
     142,   143,   442,   443,  1303,   707,   217,   188,   806,   437,
     438,   708,   810,   218,   823,   450,  1309,   446,   671,   179,
     150,   454,   382,   383,   384,   452,   174,   442,   443,   385,
     156,   207,   218,   495,   208,   175,  1122,   144,   145,   146,
     147,   183,  1517,   678,   731,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   151,
     152,   184,   478,   385,   479,   196,   480,   189,   197,   157,
     198,   292,  1322,   187,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   498,   383,   384,   419,   420,
     421,   188,   385,   570,   571,   572,   573,   574,   575,   576,
     577,   442,   443,   580,   581,   582,   144,   145,   146,   147,
     144,   145,   146,   147,   295,   223,   296,   684,   224,   364,
     591,   225,  1583,   190,   461,   462,   151,   152,   442,   443,
     151,   152,   191,   809,    97,   248,   474,   475,   787,   192,
     101,   102,   103,   788,  1045,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   250,   442,   443,   193,
     144,   145,   146,   147,   194,   131,   132,   133,   442,   443,
     790,   135,   136,  1063,   195,   791,   151,   152,   800,   251,
     151,   152,   252,   788,  1307,   253,  -445,   254,   209,    42,
      43,    44,    45,   365,   365,   199,   888,    50,   255,   210,
      53,   215,   216,   390,    99,    42,    43,    44,    45,    46,
     297,   217,   298,    50,   151,   152,    53,   235,   226,   516,
    1421,   480,  1424,   299,  1427,   300,   292,   674,   675,   390,
      99,   442,   443,   442,   443,   438,   214,   125,   126,   127,
     128,   129,   130,   244,   442,   443,   245,  1369,   134,  1371,
       7,     8,   138,   442,   443,   442,   443,   442,   443,   141,
     142,   143,   222,   125,   126,   127,   128,   129,   130,  1373,
     234,  1381,   743,  1383,   134,   148,   398,  1005,  1062,   243,
     150,  1062,   633,   204,  1062,   257,   205,  1006,   206,   242,
     156,  1094,   633,   495,   442,   443,   596,    19,    20,   597,
      22,    23,   598,    25,   599,    27,   266,    28,   151,   152,
    1384,    32,    33,   246,    35,    36,    37,   301,  -446,   302,
      40,   442,   443,   247,  1508,   442,   443,   442,   443,   442,
     443,   139,   140,   497,   812,   151,   152,  1462,   811,   442,
     443,  1465,  1081,  1468,   303,  1476,   304,   160,   265,    60,
      61,    62,   442,   443,   267,  1478,   200,   139,   140,   201,
     151,   152,   202,   275,   203,  1062,   988,   954,  1538,   276,
    1111,   305,   901,   306,   848,   633,  1549,   268,  1552,  1336,
    1555,   307,   902,   308,  1337,   626,  1558,   274,   627,  1119,
     903,   904,  1121,  1123,   905,   906,   629,   789,   792,   627,
     788,   793,   878,   878,   878,   878,  1062,   277,   487,  1062,
     699,   488,  1062,   278,   489,  1062,   490,    99,  1112,   279,
     285,   633,   309,  1588,   310,  1590,   341,  1592,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   311,   342,   312,  1062,   385,  1062,  1095,  1062,
     125,   126,   127,   128,   129,   130,   891,   343,   879,   880,
     881,   134,   743,   897,  1204,   313,   315,   314,   316,   909,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   632,   383,   384,   344,   317,   956,   318,   385,   352,
     353,   354,   955,   901,   356,   359,   380,   381,   382,   383,
     384,  1183,  1184,   902,  1030,   385,   389,   319,   348,   320,
     394,   903,   904,  1291,  1292,   905,   906,   397,   399,   402,
     403,   363,   405,   399,   407,   408,   345,   399,   411,   412,
     346,   321,   966,   322,   399,  1128,   347,   323,   969,   324,
     349,   970,   971,   972,   139,   140,  1225,  1226,   974,   431,
     325,   327,   326,   328,   329,   331,   330,   332,   440,   441,
     333,   335,   334,   336,   337,   350,   338,   441,   351,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   404,  1004,  1463,   339,   385,   340,   619,
     633,   620,   634,  1010,   901,  1011,   369,   492,   494,   399,
     633,   633,   639,   643,   902,   386,   387,   501,   502,   503,
     901,   505,   903,   904,   508,   509,   905,   906,   510,   633,
     902,   649,   633,   739,   721,   740,   388,   409,   903,   904,
     414,   521,   905,   906,  1009,   415,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   435,  1240,
     955,   432,   901,  1050,  1051,  1052,  1466,   417,   901,   579,
    1416,   633,   902,   805,   468,   633,   399,   808,   902,   399,
     903,   904,  1469,   418,   905,   906,   903,   904,   422,   427,
     905,   906,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   428,   429,  1124,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   492,
     436,   447,   901,   385,   633,   637,   923,   633,   458,   924,
     642,   459,   902,  1150,   448,   647,   648,   449,   650,   651,
     903,   904,   460,   656,   905,   906,   471,   470,   661,   662,
     663,   370,   472,   633,  1534,   925,   633,  1016,   937,  1017,
    1572,   633,   464,  1042,   901,   633,   484,  1079,   679,   680,
     681,   352,   353,   682,   902,   473,   476,   686,   687,   688,
     689,   690,   903,   904,   477,   695,   905,   906,   697,   698,
     481,   499,   399,   399,   399,   500,   504,   705,   706,   633,
     711,  1080,   485,   633,   714,  1082,   633,   633,  1083,  1084,
     486,   633,   399,  1085,  1574,   633,   511,  1087,   722,   724,
    1130,   633,  1131,  1132,   633,   633,  1133,  1134,  1203,   506,
     633,  1229,  1135,   507,   633,   901,  1169,   711,  1230,   512,
     514,   741,   901,   520,   744,   902,  1249,  1233,  1250,   901,
     522,   523,   902,   903,   904,   368,  1576,   905,   906,   902,
     903,   904,  1394,   524,   905,   906,   901,   903,   904,  1254,
     385,   905,   906,  1257,   592,  1281,   902,  1282,   633,  1342,
    1316,  1343,   593,   594,   903,   904,   413,  1432,   905,   906,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   430,   157,   601,   433,   385,  1286,
    1249,   813,  1382,  1249,  1429,  1412,  1430,   365,   365,  1260,
     517,   633,  1547,  1441,  1249,   595,  1447,  1578,  1449,   646,
    1450,   463,   652,  1452,  1600,  1453,  1249,   633,  1457,  1458,
     836,  1601,   633,   399,  1477,   399,   844,  1229,  1342,   653,
    1514,  1326,   657,   724,   850,  1293,   658,  1296,  1602,  1299,
     633,   633,  1537,  1539,  1249,   659,  1543,   864,  1567,   664,
    1568,  1310,   660,   870,  1313,  1314,   666,   667,   877,   877,
     877,   877,   691,  1509,   518,   519,   399,   788,   633,  1570,
    1579,   668,   693,   892,   893,  1580,  1249,  1581,  1598,   896,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   917,   694,   696,   919,   385,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,  1603,   399,
    1604,   399,   385,   703,   704,   712,   399,   399,   399,   399,
     713,   400,   729,   715,   399,   716,   400,   717,   718,   732,
     400,   944,   738,   946,   947,   794,   795,   400,   796,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   797,   798,   799,   802,   385,   803,   804,
     814,   815,   819,   837,   618,   852,   842,   845,   958,   959,
     846,   847,   857,   861,   365,   849,   853,   854,   856,   858,
     859,   862,   960,   961,   962,   963,   964,   965,   863,   867,
     872,   874,   399,   887,   399,   894,   895,   918,   931,   940,
     493,   941,   400,   973,   942,   943,   950,   976,   952,   975,
     977,   982,   978,   983,  1420,   984,  1423,   986,  1426,   990,
     997,   399,   399,   399,   399,   995,  1434,   987,   998,  1437,
     999,    97,   284,  1001,  1003,  1034,  1008,   101,   102,   103,
    1014,  1020,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,  1025,  1021,  1026,  1028,  1029,   399,  1032,
    1035,  1033,   131,   132,   133,  1036,  1038,  1037,   135,   136,
    1039,  1040,  1041,  1043,  1053,  1055,  1056,  1054,  1071,  1065,
    1066,  1072,  1521,  1524,  1067,  1068,  1069,  1073,  1074,   400,
    1075,  1077,   400,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,  1078,  1091,  1096,
    1097,   385,  1099,  1512,  1100,  1102,  1076,  1101,  1113,  1115,
    1154,  1126,  1114,  1143,   801,  1125,  1146,  1158,  1161,  1086,
    1116,  1118,   493,  1136,  1162,  1563,  1142,  1165,  1141,  1166,
    1167,  1152,  1172,  1153,  1159,  1160,  1173,  1200,  1164,   138,
    1175,  1176,  1177,   807,  1178,  1182,   141,   142,   143,  1196,
    1188,  1189,  1201,  1217,  1585,  1236,  1208,  1209,  1216,  1213,
    1215,  1218,   148,   149,  1594,  1219,  1597,   150,  1129,  1224,
    1220,  1227,   257,  1228,  1235,  1238,  1241,   156,  1137,  1138,
    1242,  1243,  1244,  1253,  1606,  1272,  1261,  1610,  1147,  1149,
    1262,  1263,  1266,  1268,  1270,   400,   400,   400,  1269,  1271,
    1275,  1280,  1283,  1294,  1297,  1300,  1308,  1311,  1315,  1329,
     871,  1304,  1328,  1330,  1331,   400,  1333,  1334,  1335,  1341,
    1344,   885,   725,  1353,  1355,  1356,  1185,  1186,  1187,  1357,
    1358,  1359,  1360,  1364,  1361,  1376,  1197,  1199,  1378,  1385,
    1387,  1365,  1392,  1402,  1202,  1367,  1368,  1370,  1372,  1374,
    1379,  1406,   399,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,  1395,  1407,  1393,
    1408,   385,  1409,  1221,  1222,  1223,  1410,  1411,   401,  1428,
    1413,  1435,  1442,   406,  1443,  1444,  1455,   410,  1459,  1471,
    1472,  1475,  1480,  1487,   416,  1488,   951,   630,  1491,  1492,
    1494,  1497,  1498,  1501,  1234,  1502,  1505,  1511,  1506,  1532,
    1526,  1528,  1530,  1540,  1541,  1550,  1553,  1246,  1556,  1559,
    1561,  1566,  1252,  1565,  1573,  1575,  1586,  1577,  1582,  1256,
    1587,  1589,   985,  1258,  1259,  1591,  1593,  1595,  1605,  1607,
    1264,  1265,  1608,  1609,  1611,  1267,   400,  1145,   400,  1156,
    1481,    84,    92,  1274,   655,  1237,   725,   851,     0,     0,
       0,     0,     0,  1284,     0,  1285,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1302,     0,     0,
       0,     0,     0,     0,     0,  1024,     0,   399,     0,   400,
       0,   399,     0,     0,  1317,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1325,     0,     0,
    1012,  1013,     0,  1015,     0,  1018,  1019,     0,     0,  1022,
    1023,     0,     0,     0,     0,     0,     0,     0,  1338,  1339,
       0,     0,   400,     0,   400,     0,  1345,     0,     0,   400,
     400,   400,   400,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,     0,     0,   583,     0,     0,   587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1366,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,  1380,   385,
     492,     0,     0,     0,     0,     0,     0,  1088,  1089,  1090,
    1388,     0,  1389,     0,     0,   399,     0,  1098,     0,     0,
       0,     0,     0,     0,     0,   400,     0,   400,  1397,     0,
       0,     0,     0,  1401,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,   399,   400,   400,   400,   400,     0,     0,
    1419,     0,  1422,     0,  1425,     0,  1140,     0,     0,     0,
       0,     0,     0,     0,   399,     0,     0,     0,  1438,     0,
       0,  1157,   700,   701,   702,     0,     0,  1163,     0,  1445,
    1446,     0,     0,  1168,  1448,  1170,  1171,     0,     0,     0,
    1174,   400,   719,     0,  1456,  1179,  1180,  1181,  1460,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1198,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1207,     0,     0,  1252,  1211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1489,     7,     8,     0,
       0,     0,     0,  1496,     0,     0,  1500,     0,     0,  1504,
       0,     0,     0,  1507,     0,     0,     0,   399,     0,   399,
       0,     0,     0,     0,  1516,     0,     0,  1518,     0,  1523,
       0,     0,     0,     0,     0,     0,  1231,     0,  1232,     0,
       0,     0,     0,   596,    19,    20,   597,    22,    23,   598,
      25,   599,    27,     0,    28,     0,     0,     0,    32,    33,
    1546,    35,    36,    37,     0,     0,  1548,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   399,
       0,     7,     8,   841,     0,   843,     0,     0,     0,     0,
       0,     0,  1276,  1277,  1278,  1279,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1584,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1140,   886,   596,    19,    20,
     597,    22,    23,   598,    25,   599,    27,  1318,    28,     0,
       0,     0,    32,    33,  1327,    35,    36,    37,     0,     0,
       0,    40,     0,     0,     0,   400,     0,   736,  1070,     0,
       0,     0,     0,     0,     0,     0,  1340,     0,     0,   928,
       0,   929,     0,     0,     0,     0,   933,   934,   935,   936,
      60,    61,    62,     0,   939,     0,     0,  1140,    97,   248,
      99,     0,     0,     0,   101,   102,   103,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     250,  1377,     0,   125,   126,   127,   128,   129,   130,   131,
     132,   133,     0,     0,   134,   135,   136,     0,     0,     0,
       0,   737,     0,   251,     0,     0,   252,     0,     0,   253,
       0,   254,   967,     0,   968,     0,     0,     0,  1140,     0,
       0,     0,   255,     0,     0,     0,     0,     0,     0,    42,
      43,    44,    45,    46,     0,     0,     0,    50,  1140,     0,
      53,   991,   992,   993,   994,     0,     0,     0,     0,     0,
     400,     0,     0,     0,   400,  1431,     0,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,   138,   139,   140,     0,
       0,     0,     0,   141,   142,   143,     0,     0,  1027,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
     256,     0,     0,     0,   150,     0,  1470,     0,     0,   257,
       0,     0,     0,     0,   156,     0,  1519,     0,    97,   284,
       0,     0,     0,     0,   101,   102,   103,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,   493,     0,     0,     0,     0,     0,   131,
     132,   133,  1140,     0,  1520,   135,   136,     0,   400,     0,
       0,     0,    97,    98,    99,     0,   100,     0,   101,   102,
     103,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,  1120,     0,   400,   125,   126,   127,
     128,   129,   130,   131,   132,   133,     0,     0,   134,   135,
     136,     0,     0,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1140,     0,     0,     0,   138,     0,     0,     0,
       0,     0,     0,   141,   142,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
     149,     0,     0,     0,   150,     0,     0,     0,     0,   257,
       0,     0,   357,     0,   156,     0,   358,     0,     0,     0,
       0,     0,  1212,     0,   137,     0,     0,     0,     0,     0,
     138,   139,   140,     0,     0,     0,     0,   141,   142,   143,
     144,   145,   146,   147,     0,     0,     0,     0,     0,     0,
     400,     0,   400,   148,   149,     0,  1127,     0,   150,     0,
     151,   152,     0,   153,     0,   154,     0,   155,   156,     0,
     157,     0,     0,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,   400,     0,     0,     0,     0,     0,     0,
       0,     0,    97,   248,   249,     0,     0,     0,   101,   102,
     103,     0,   400,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   250,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   133,     0,     0,     0,   135,
     136,     0,     0,     0,     0,     0,     0,   251,     0,     0,
     252,     0,     0,   253,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,     0,     0,     0,
       0,     0,     0,    42,    43,    44,    45,    46,     0,     0,
       0,    50,     0,     0,    53,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
     138,     0,     0,   385,     0,     0,     0,   141,   142,   143,
    1289,     0,  1290,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,   256,     0,     0,     0,   150,     0,
       0,     0,     0,   257,     0,     0,     0,     0,   156,     0,
     258,     0,     0,     0,     0,  1390,     0,     0,     0,     0,
      97,   248,  1205,     0,     0,     0,   101,   102,   103,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   250,  1415,     0,     0,     0,     0,     0,     0,
       0,   131,   132,   133,     0,     0,     0,   135,   136,     0,
       0,     0,     0,     0,  1436,   251,     0,     0,   252,     7,
       8,   253,     0,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,     0,     0,     0,     0,
       0,    42,    43,    44,    45,    46,     0,     0,     0,    50,
       0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   596,    19,    20,   597,    22,
      23,   598,    25,   599,    27,     0,    28,     0,     0,     0,
      32,    33,     0,    35,    36,    37,     0,     0,   138,    40,
       0,     0,     0,     0,     0,   141,   142,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1510,     0,  1513,
       0,   148,   256,     0,     0,     0,   150,     0,    60,    61,
      62,   257,     0,    97,   248,     0,   156,     0,  1206,   101,
     102,   103,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   250,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,     0,     0,  1560,
     135,   136,     7,     8,     0,     0,     0,     0,   251,   889,
       0,   252,     0,     0,   253,     0,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,     0,     0,     0,    42,    43,    44,    45,    46,     0,
       0,     0,    50,     0,     0,    53,     0,     0,   596,    19,
      20,   597,    22,    23,   598,    25,   599,    27,     0,    28,
       0,     0,     0,    32,    33,     0,    35,    36,    37,     0,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,     0,     0,     0,     0,   141,   142,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    61,    62,   148,   256,     0,     0,     0,   150,
       0,     0,     0,     0,   257,     0,    97,   248,     0,   156,
       0,   258,   101,   102,   103,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   132,   133,
       0,     0,   890,   135,   136,     7,     8,     0,     0,     0,
       0,   251,     0,     0,   252,     0,     0,   253,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,     0,     0,     0,     0,     0,     0,    42,    43,    44,
      45,    46,     0,     0,     0,    50,     0,     0,    53,     0,
       0,   596,    19,    20,   597,    22,    23,   598,    25,   599,
      27,     0,    28,     0,     0,     0,    32,    33,     0,    35,
      36,    37,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,     0,
       0,   141,   142,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,   148,   398,     0,
       0,     0,   150,     0,     0,     0,     0,   257,     0,    97,
     248,     0,   156,     0,   491,   101,   102,   103,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   250,     0,     0,     0,     0,     0,     0,     0,     0,
     131,   132,   133,     0,     0,   910,   135,   136,     7,     8,
       0,     0,     0,     0,   251,     0,     0,   252,     0,     0,
     253,     0,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,     0,     0,     0,     0,     0,     0,
      42,    43,    44,    45,    46,     0,     0,     0,    50,     0,
       0,    53,     0,     0,   596,    19,    20,   597,    22,    23,
     598,    25,   599,    27,     0,    28,     0,     0,     0,    32,
      33,     0,    35,    36,    37,     0,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
       0,     0,     0,     0,   141,   142,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    61,    62,
     148,   398,     0,     0,     0,   150,     0,     0,     0,     0,
     257,     0,    97,   248,     0,   156,     0,   723,   101,   102,
     103,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   250,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   133,     0,     0,   945,   135,
     136,     7,     8,     0,     0,     0,     0,   251,     0,     0,
     252,     0,     0,   253,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,     0,     0,     0,
       0,     0,     0,    42,    43,    44,    45,    46,     0,     0,
       0,    50,     0,     0,    53,     0,     0,   596,    19,    20,
     597,    22,    23,   598,    25,   599,    27,     0,    28,     0,
       0,     0,    32,    33,     0,    35,    36,    37,     0,  1214,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,     0,   141,   142,   143,
    1332,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    62,   148,   256,     0,     0,     0,   150,     0,
       0,     0,     0,   257,     0,    97,   248,     0,   156,     0,
    1210,   101,   102,   103,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   250,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   132,   133,     0,
       0,  1044,   135,   136,     0,     0,     0,     0,     0,     0,
     251,     0,     0,   252,     0,     0,   253,     0,   254,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
       0,     0,     0,     0,     0,     0,    42,    43,    44,    45,
      46,     0,     0,     0,    50,     0,     0,    53,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   138,  1363,     0,     0,   385,     0,     0,
     141,   142,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   450,  1309,     0,     0,
       0,   150,     0,     0,     0,     0,   452,     0,    97,   284,
      99,   156,     0,   218,   101,   102,   103,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,   125,   126,   127,   128,   129,   130,   131,
     132,   133,     0,     0,   134,   135,   136,    97,   284,    99,
       0,     0,     0,   101,   102,   103,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,   125,   126,   127,   128,   129,   130,   131,   132,
     133,     7,     8,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,     0,   138,   139,   140,     0,
       0,     0,     0,   141,   142,   143,     0,   596,    19,    20,
     597,    22,    23,   598,    25,   599,    27,     0,    28,   148,
     149,     0,    32,    33,   150,    35,    36,    37,     0,   257,
       0,    40,     0,     0,   156,     0,  1148,  1391,     0,     0,
       0,     0,     0,     0,     0,   138,   139,   140,     0,     0,
       0,     0,   141,   142,   143,     0,     0,     0,     0,     0,
      60,    61,    62,     0,     0,     0,     0,     0,   148,   149,
       0,     0,     0,   150,     0,     0,     0,     0,   257,     0,
      97,   284,    99,   156,     0,  1324,   101,   102,   103,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,     0,     0,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    97,   284,   134,   135,   136,     0,
     101,   102,   103,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,   132,   133,     0,     0,
       0,   135,   136,     7,     8,     0,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
     140,     0,     0,     0,     0,   141,   142,   143,     0,   596,
      19,    20,   597,    22,    23,   598,    25,   599,    27,     0,
      28,   148,   149,     0,    32,    33,   150,    35,    36,    37,
       0,   257,     0,    40,     0,     0,   156,     0,  1522,  1479,
       0,     0,   138,     0,     0,     0,     0,     0,     0,   141,
     142,   143,     0,     0,     0,     0,     0,     0,  1533,     0,
       0,     0,    60,    61,    62,   148,   149,     0,     0,     0,
     150,     0,     0,     0,     0,   257,     0,     0,   709,     0,
     156,     0,   710,    97,   284,     0,     0,     0,     0,   101,
     102,   103,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,     0,     0,     0,     0,
       0,     0,     0,  1473,   131,   132,   133,    97,   284,     0,
     135,   136,     0,   101,   102,   103,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,   132,
     133,     0,     0,     0,   135,   136,     7,     8,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   138,     0,     0,     0,   385,     0,     0,   141,   142,
     143,     0,   596,    19,    20,   597,    22,    23,   598,    25,
     599,    27,     0,    28,   148,   149,     0,    32,    33,   150,
      35,    36,    37,     0,   257,     0,    40,  1569,   497,   156,
       0,   355,     0,     0,     0,   138,     0,     0,     0,     0,
       0,     0,   141,   142,   143,     0,  1599,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,   450,   451,
       0,     0,     0,   150,     0,     0,     0,     0,   452,     0,
      97,   248,     0,   156,     0,   218,   101,   102,   103,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   250,     0,     0,     0,     0,     0,     0,     0,
       0,   131,   132,   133,     0,     0,  1535,   135,   136,     0,
       0,     0,     0,     0,     0,   251,     0,     0,   252,     0,
       0,   253,     0,   254,     0,     0,     0,     0,     0,   733,
       0,     0,     0,     0,   255,     0,     0,     0,     0,     0,
       0,    42,    43,    44,    45,    46,     0,     0,   824,    50,
       0,     0,    53,     0,     0,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   632,   383,   384,   938,
       0,     0,     0,   385,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   138,  1093,
       0,     0,   385,     0,     0,   141,   142,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,   398,     0,     0,     0,   150,    97,   284,    99,
       0,   257,     0,   101,   102,   103,   156,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,   125,   126,   127,   128,   129,   130,   131,   132,
     133,     0,     0,   134,   135,   136,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,   138,   139,   140,     0,     0,
       0,     0,   141,   142,   143,     0,     0,     0,    -4,     1,
       0,     0,    -4,     0,     0,     0,     0,     0,   148,   149,
      -4,    -4,     0,   150,     0,     0,     0,     0,   257,     0,
       0,     0,     0,   156,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,     0,     0,     0,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     6,    -4,    -4,
       0,     0,     0,    -4,     0,     7,     8,     0,    -4,    -4,
      -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     9,
      10,     0,    -4,    -4,    -4,    -4,     0,     0,     0,     0,
      11,    12,     0,     0,     0,    13,    14,    15,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,     0,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     0,     0,    56,    57,     0,     0,     0,    58,     0,
       0,     0,     0,    59,    60,    61,    62,     0,     0,    63,
       0,    64,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,     0,    76,    77,    78,
      79,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,     0,     0,     0,  1319,     0,  1320,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,     0,     0,     0,  1417,     0,  1418,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,     0,
       0,     0,     0,     0,   866,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,     0,     0,     0,
       0,     0,   913,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,     0,     0,     0,     0,     0,
     932,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,     0,     0,     0,     0,     0,   957,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,     0,     0,     0,     0,     0,  1048,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,     0,
       0,     0,     0,     0,  1287,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,     0,     0,     0,
       0,     0,  1306,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,     0,     0,     0,     0,     0,
    1348,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,     0,     0,     0,     0,     0,  1349,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,     0,     0,     0,     0,     0,  1350,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,     0,
       0,     0,     0,     0,  1351,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,     0,     0,     0,
       0,     0,  1352,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,     0,     0,     0,     0,     0,
    1386,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,     0,     0,     0,     0,     0,  1433,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,     0,     0,     0,     0,     0,  1439,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,     0,
       0,     0,     0,     0,  1440,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,     0,     0,     0,
       0,     0,  1461,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,     0,     0,     0,     0,     0,
    1464,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,     0,     0,     0,     0,     0,  1467,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,     0,     0,     0,     0,     0,  1490,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,     0,
       0,     0,     0,     0,  1493,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,     0,     0,     0,
       0,     0,  1527,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,     0,     0,     0,     0,     0,
    1529,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,     0,     0,     0,     0,     0,  1531,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,     0,     0,     0,     0,     0,  1544,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,     0,
       0,     0,     0,     0,  1571,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,     0,     0,     0,
       0,   665,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,     0,  1362,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,   720,
       0,     0,     0,     0,   672,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,     0,     0,     0,
     625,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,     0,     0,     0,   672,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,     0,
       0,     0,   673,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,     0,     0,     0,   730,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,     0,     0,     0,   767,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,     0,     0,     0,
     768,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,     0,     0,     0,   781,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,     0,
       0,     0,   782,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,     0,     0,     0,   783,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,     0,     0,     0,   784,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,     0,     0,     0,
     785,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,     0,     0,     0,   786,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,     0,
       0,     0,   898,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,     0,     0,     0,   899,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,     0,     0,     0,   900,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,     0,     0,     0,
    1007,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,     0,     0,     0,  1046,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,     0,
       0,     0,  1047,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,     0,     0,     0,  1092,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,     0,     0,     0,  1247,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,     0,     0,     0,
    1248,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,     0,     0,     0,  1255,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,     0,
       0,     0,  1398,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,     0,     0,     0,  1399,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,     0,     0,     0,  1403,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,     0,     0,     0,
    1483,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,     0,     0,     0,  1486,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,     0,
       0,     0,  1525,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,   588,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,   735,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,   742,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,   746,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,   748,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
     750,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,   752,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,   754,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,   756,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,   758,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,   760,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,   762,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,   764,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,   766,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,   770,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
     772,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,   774,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,   776,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,   778,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,   780,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,   921,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,   922,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,   926,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,     0,     0,   927,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,     0,     0,   930,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,     0,     0,
     953,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,     0,     0,  1002,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,     0,     0,  1104,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,     0,     0,  1106,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
       0,     0,  1108,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,     0,     0,  1110,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,     0,     0,  1239,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,     0,
       0,  1375,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,   584,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,   631,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,   635,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,   636,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,   638,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,   640,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,   641,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,   644,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
     645,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,   720,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,   726,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,   727,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,   728,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,   734,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,   745,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,   747,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,   749,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,   751,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
     753,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,   755,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,   757,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,   759,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,   761,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,   763,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,   765,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,   769,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,   771,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,   773,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
     775,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,   777,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,   779,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,   855,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,   860,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,   865,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,   868,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,   869,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,   875,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,   882,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
     883,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,   884,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,   912,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,   914,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,   915,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,   916,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,   920,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385,     0,  1103,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,     0,     0,     0,     0,   385,     0,  1105,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,     0,     0,     0,     0,   385,     0,  1107,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   385,     0,
    1109,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,     0,   385,
       0,  1117,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,     0,     0,     0,     0,
     385,     0,  1288,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,     0,     0,     0,
       0,   385,     0,  1305,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,     0,     0,
       0,     0,   385,     0,  1323,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,     0,
       0,     0,     0,   385,     0,  1482,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
       0,     0,     0,     0,   385,     0,  1542,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   385
};

static const yytype_int16 yycheck[] =
{
       6,     6,     3,     6,   226,  1208,     6,     6,   338,     6,
     211,   911,     4,     4,   907,     4,   238,   347,     5,   444,
     445,   357,     7,     4,   360,     4,     6,     4,     4,     4,
       4,     6,     5,     5,   164,   154,   155,     4,     4,   154,
     155,     4,     6,    64,     4,    66,     6,    64,   154,   155,
      80,     4,     6,   172,     6,     6,   171,   154,   155,   281,
      90,   283,     0,     6,   170,    80,   172,  1270,    98,    99,
     161,   162,   102,   103,   171,    90,   154,   155,    43,    44,
       8,    46,   164,    98,    99,   154,   155,   102,   103,   171,
     154,   155,    58,   171,   165,   100,    62,     4,    58,   170,
     116,   170,   164,   172,     3,     4,   170,    73,   172,   171,
       9,    10,    11,   129,   130,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    13,  1341,   106,
     107,   108,   109,     7,   125,    44,    45,    46,     8,     6,
     104,    50,    51,   104,   151,   164,   157,   172,  1361,    58,
     166,   167,    61,   116,   117,    64,     6,    66,   171,   161,
     162,  1064,   171,   164,   166,   164,   168,     8,    77,   171,
     171,   173,   171,   168,   171,    84,    85,    86,    87,    88,
     171,   166,   171,    92,   171,   171,    95,   171,   171,   171,
     164,   164,   154,   155,     6,   172,   165,   171,   151,   116,
     117,   170,     7,   435,   436,   164,     7,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   164,   131,   455,     6,   163,   154,   155,   171,   138,
     139,   140,   154,   155,   172,   165,   164,   164,   584,   214,
     215,   171,   588,   171,   171,   154,   155,   222,   170,   164,
     159,   226,   156,   157,   158,   164,   166,   154,   155,   163,
     169,    61,   171,   172,    64,   166,     7,   141,   142,   143,
     144,   164,  1485,   170,   506,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   161,
     162,   164,   164,   163,   166,    61,   168,    68,    64,   171,
      66,   173,   172,   164,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   196,   197,
     198,   164,   163,   339,   340,   341,   342,   343,   344,   345,
     346,   154,   155,   349,   350,   351,   141,   142,   143,   144,
     141,   142,   143,   144,   164,    58,   166,   170,    61,     4,
     360,    64,  1565,    64,   232,   233,   161,   162,   154,   155,
     161,   162,    64,   168,     3,     4,   244,   245,   165,     6,
       9,    10,    11,   170,   170,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   154,   155,   171,
     141,   142,   143,   144,    64,    44,    45,    46,   154,   155,
     165,    50,    51,   170,    64,   170,   161,   162,   165,    58,
     161,   162,    61,   170,   170,    64,   171,    66,   164,    84,
      85,    86,    87,   444,   445,    66,   668,    92,    77,    61,
      95,   154,   155,     4,     5,    84,    85,    86,    87,    88,
     164,   164,   166,    92,   161,   162,    95,    61,   171,   166,
    1370,   168,  1372,   164,  1374,   166,   173,   442,   443,     4,
       5,   154,   155,   154,   155,   450,   171,    38,    39,    40,
      41,    42,    43,    61,   154,   155,    64,   170,    49,   170,
      12,    13,   131,   154,   155,   154,   155,   154,   155,   138,
     139,   140,   171,    38,    39,    40,    41,    42,    43,   170,
      64,   170,   522,   170,    49,   154,   155,   165,  1421,    64,
     159,  1424,   170,    61,  1427,   164,    64,   165,    66,    61,
     169,     8,   170,   172,   154,   155,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,   164,    69,   161,   162,
     170,    73,    74,     4,    76,    77,    78,   164,   171,   166,
      82,   154,   155,     4,  1474,   154,   155,   154,   155,   154,
     155,   132,   133,     8,   589,   161,   162,   170,   588,   154,
     155,   170,   168,   170,   164,   170,   166,     6,     4,   111,
     112,   113,   154,   155,   164,   170,    58,   132,   133,    61,
     161,   162,    64,     6,    66,  1508,   817,   168,   170,     6,
     165,   164,    80,   166,   630,   170,  1526,   164,  1528,   165,
    1530,   164,    90,   166,   170,   167,  1536,   164,   170,   975,
      98,    99,   978,   979,   102,   103,   167,   167,   167,   170,
     170,   170,   657,   658,   659,   660,  1549,   166,    58,  1552,
     172,    61,  1555,     4,    64,  1558,    66,     5,   167,     4,
      79,   170,   164,  1573,   166,  1575,   164,  1577,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   164,   164,   166,  1588,   163,  1590,   165,  1592,
      38,    39,    40,    41,    42,    43,   671,   164,   658,   659,
     660,    49,   712,   678,   172,   164,   164,   166,   166,   684,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   164,   164,   742,   166,   163,   148,
     149,   150,   742,    80,   153,   154,   154,   155,   156,   157,
     158,     6,     7,    90,    80,   163,   165,   164,     7,   166,
     169,    98,    99,  1188,  1189,   102,   103,   176,   177,   178,
     179,     4,   181,   182,   183,   184,   164,   186,   187,   188,
     164,   164,   788,   166,   193,   986,   164,   164,   794,   166,
     164,   797,   798,   799,   132,   133,     6,     7,   804,   208,
     164,   164,   166,   166,   164,   164,   166,   166,   217,   218,
     164,   164,   166,   166,   164,   164,   166,   226,   164,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   164,   840,   172,   164,   163,   166,   166,
     170,   168,   172,    64,    80,    66,     6,   256,   257,   258,
     170,   170,   172,   172,    90,   171,     6,   266,   267,   268,
      80,   270,    98,    99,   273,   274,   102,   103,   277,   170,
      90,   172,   170,   170,   172,   172,     6,   164,    98,    99,
     164,   290,   102,   103,   849,   171,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   171,  1130,
     930,     4,    80,   898,   899,   900,   172,   164,    80,   348,
    1365,   170,    90,   172,   166,   170,   355,   172,    90,   358,
      98,    99,   172,   164,   102,   103,    98,    99,   164,   164,
     102,   103,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   164,   164,   979,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   398,
     171,   171,    80,   163,   170,   404,   172,   170,   164,   172,
     409,   164,    90,  1008,   171,   414,   415,   171,   417,   418,
      98,    99,   164,   422,   102,   103,   171,     6,   427,   428,
     429,     6,   171,   170,   172,   172,   170,    64,   172,    66,
     172,   170,   164,   172,    80,   170,     5,   172,   447,   448,
     449,   450,   451,   452,    90,   171,   166,   456,   457,   458,
     459,   460,    98,    99,   166,   464,   102,   103,   467,   468,
     166,     6,   471,   472,   473,     6,   168,   476,   477,   170,
     479,   172,     5,   170,   483,   172,   170,   170,   172,   172,
       5,   170,   491,   172,   172,   170,     6,   172,   497,   498,
     170,   170,   172,   172,   170,   170,   172,   172,  1063,   171,
     170,  1101,   172,   119,   170,    80,   172,   516,  1114,     6,
       6,   520,    80,   166,   523,    90,   170,  1122,   172,    80,
       4,   171,    90,    98,    99,   158,   172,   102,   103,    90,
      98,    99,  1333,     6,   102,   103,    80,    98,    99,  1145,
     163,   102,   103,  1148,   168,     4,    90,     6,   170,   170,
     172,   172,     7,   166,    98,    99,   189,  1379,   102,   103,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   207,   171,     6,   210,   163,  1184,
     170,   590,   172,   170,   170,   172,   172,  1188,  1189,  1154,
       6,   170,  1522,   172,   170,   172,   172,   172,   170,     7,
     172,   234,     7,   170,   172,   172,   170,   170,   172,   172,
     619,   172,   170,   622,   172,   624,   625,  1217,   170,     7,
     172,  1226,   164,   632,   633,  1190,   164,  1192,   172,  1194,
     170,   170,   172,   172,   170,   164,   172,   646,   170,     7,
     172,  1206,   164,   652,  1209,  1210,   165,     6,   657,   658,
     659,   660,     7,  1475,   287,   288,   665,   170,   170,   172,
     172,   171,     6,   672,   673,   170,   170,   172,   172,   678,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   691,     7,     6,   694,   163,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   170,   708,
     172,   710,   163,     6,     6,     4,   715,   716,   717,   718,
       4,   177,   116,   171,   723,   171,   182,   171,   171,   171,
     186,   730,   165,   732,   733,   170,   165,   193,   165,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   170,   170,   170,   170,   163,   165,   170,
       6,     4,   167,     4,     6,   119,     6,     6,   767,   768,
       4,     6,   119,   119,  1365,     7,     7,     7,     7,     7,
       7,     7,   781,   782,   783,   784,   785,   786,     7,   171,
       4,     6,   791,   168,   793,   172,   172,     6,   167,     7,
     256,     7,   258,   802,     7,   168,   171,   806,     6,   165,
       6,   810,   167,     6,  1369,     6,  1371,     7,  1373,     6,
     164,   820,   821,   822,   823,   824,  1381,   166,   164,  1384,
     171,     3,     4,     6,   151,   165,     7,     9,    10,    11,
       7,     7,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     7,    66,     7,     7,     7,   867,     6,
     165,     7,    44,    45,    46,   165,     7,   165,    50,    51,
       7,     7,     6,     4,     4,   171,   164,     6,   171,     7,
       6,     6,  1487,  1488,     7,     7,     7,     6,     6,   355,
      64,     6,   358,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     6,     4,     4,
       4,   163,   172,  1478,     6,     6,   925,     4,   165,   165,
      73,     7,   170,     6,     6,   168,     6,     6,     6,   938,
     165,   165,   398,   164,     6,  1541,   168,     6,   171,     6,
       5,   171,     4,   171,   171,   171,     6,     6,   171,   131,
       7,     7,     7,   586,     7,     7,   138,   139,   140,   166,
     171,   171,     6,     4,  1569,     4,   171,   171,   167,   171,
     165,     6,   154,   155,  1580,     6,  1582,   159,   987,     6,
     115,   170,   164,     6,     6,     6,     6,   169,   997,   998,
       6,     6,     6,     4,  1599,   119,     6,  1603,  1007,  1008,
       6,     6,     6,     5,   171,   471,   472,   473,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
     653,   170,   165,     6,     6,   491,     7,     6,   168,   171,
       6,   664,   498,     5,    62,     6,  1045,  1046,  1047,     6,
       6,     6,     6,     6,   171,     6,  1055,  1056,     7,     6,
     114,   171,     6,     6,  1063,   172,   172,   171,   171,   171,
     171,     6,  1071,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   117,     6,   172,
       6,   163,     6,  1092,  1093,  1094,     6,     6,   177,     6,
     171,     6,     6,   182,     6,   171,   171,   186,   172,     6,
      80,   171,     6,     4,   193,     4,   739,   396,     6,     6,
       6,     6,     6,     6,  1123,     6,     6,     6,   172,     6,
     171,   171,   171,     6,   171,     6,     6,  1136,     6,     6,
       6,     6,  1141,   171,   171,   171,     6,   171,   171,  1148,
       6,     6,     6,  1152,  1153,     6,     6,     6,     6,     6,
    1159,  1160,     6,     6,     6,  1164,   622,  1005,   624,  1013,
    1444,     3,     3,  1172,   421,  1126,   632,   633,    -1,    -1,
      -1,    -1,    -1,  1182,    -1,  1184,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,  1206,    -1,   665,
      -1,  1210,    -1,    -1,  1213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1226,    -1,    -1,
     853,   854,    -1,   856,    -1,   858,   859,    -1,    -1,   862,
     863,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1247,  1248,
      -1,    -1,   708,    -1,   710,    -1,  1255,    -1,    -1,   715,
     716,   717,   718,    -1,    -1,    -1,    -1,   723,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,   358,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1289,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,  1307,   163,
    1309,    -1,    -1,    -1,    -1,    -1,    -1,   940,   941,   942,
    1319,    -1,  1321,    -1,    -1,  1324,    -1,   950,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   791,    -1,   793,  1337,    -1,
      -1,    -1,    -1,  1342,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,  1362,   820,   821,   822,   823,    -1,    -1,
    1369,    -1,  1371,    -1,  1373,    -1,   999,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1383,    -1,    -1,    -1,  1387,    -1,
      -1,  1014,   471,   472,   473,    -1,    -1,  1020,    -1,  1398,
    1399,    -1,    -1,  1026,  1403,  1028,  1029,    -1,    -1,    -1,
    1033,   867,   491,    -1,  1413,  1038,  1039,  1040,  1417,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1055,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1065,    -1,    -1,  1444,  1069,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1455,    12,    13,    -1,
      -1,    -1,    -1,  1462,    -1,    -1,  1465,    -1,    -1,  1468,
      -1,    -1,    -1,  1472,    -1,    -1,    -1,  1476,    -1,  1478,
      -1,    -1,    -1,    -1,  1483,    -1,    -1,  1486,    -1,  1488,
      -1,    -1,    -1,    -1,    -1,    -1,  1119,    -1,  1121,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    -1,    -1,    -1,    73,    74,
    1519,    76,    77,    78,    -1,    -1,  1525,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1538,
      -1,    12,    13,   622,    -1,   624,    -1,    -1,    -1,    -1,
      -1,    -1,  1175,  1176,  1177,  1178,   111,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1567,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1208,   665,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,  1220,    69,    -1,
      -1,    -1,    73,    74,  1227,    76,    77,    78,    -1,    -1,
      -1,    82,    -1,    -1,    -1,  1071,    -1,   172,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1249,    -1,    -1,   708,
      -1,   710,    -1,    -1,    -1,    -1,   715,   716,   717,   718,
     111,   112,   113,    -1,   723,    -1,    -1,  1270,     3,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,  1304,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    49,    50,    51,    -1,    -1,    -1,
      -1,   172,    -1,    58,    -1,    -1,    61,    -1,    -1,    64,
      -1,    66,   791,    -1,   793,    -1,    -1,    -1,  1341,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    -1,    -1,    -1,    92,  1361,    -1,
      95,   820,   821,   822,   823,    -1,    -1,    -1,    -1,    -1,
    1206,    -1,    -1,    -1,  1210,  1378,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,   139,   140,    -1,    -1,   867,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     155,    -1,    -1,    -1,   159,    -1,  1429,    -1,    -1,   164,
      -1,    -1,    -1,    -1,   169,    -1,   171,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,  1309,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,  1485,    -1,  1487,    50,    51,    -1,  1324,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     6,    -1,  1362,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,  1383,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1565,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     155,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,   164,
      -1,    -1,   167,    -1,   169,    -1,   171,    -1,    -1,    -1,
      -1,    -1,  1071,    -1,   125,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
    1476,    -1,  1478,   154,   155,    -1,     6,    -1,   159,    -1,
     161,   162,    -1,   164,    -1,   166,    -1,   168,   169,    -1,
     171,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,  1519,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,  1538,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    -1,    -1,
      -1,    92,    -1,    -1,    95,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
     131,    -1,    -1,   163,    -1,    -1,    -1,   138,   139,   140,
     170,    -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   155,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,   169,    -1,
     171,    -1,    -1,    -1,    -1,  1324,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,  1362,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,  1383,    58,    -1,    -1,    61,    12,
      13,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    -1,    -1,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    -1,    -1,    -1,
      73,    74,    -1,    76,    77,    78,    -1,    -1,   131,    82,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1476,    -1,  1478,
      -1,   154,   155,    -1,    -1,    -1,   159,    -1,   111,   112,
     113,   164,    -1,     3,     4,    -1,   169,    -1,   171,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,  1538,
      50,    51,    12,    13,    -1,    -1,    -1,    -1,    58,   172,
      -1,    61,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    -1,
      -1,    -1,    92,    -1,    -1,    95,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      -1,    -1,    -1,    73,    74,    -1,    76,    77,    78,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   154,   155,    -1,    -1,    -1,   159,
      -1,    -1,    -1,    -1,   164,    -1,     3,     4,    -1,   169,
      -1,   171,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      -1,    -1,   172,    50,    51,    12,    13,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    61,    -1,    -1,    64,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    -1,    -1,    -1,    73,    74,    -1,    76,
      77,    78,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   154,   155,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,   164,    -1,     3,
       4,    -1,   169,    -1,   171,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    -1,    -1,   172,    50,    51,    12,    13,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    -1,    -1,
      64,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    -1,    -1,    -1,    92,    -1,
      -1,    95,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    -1,    -1,    -1,    73,
      74,    -1,    76,    77,    78,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     154,   155,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,
     164,    -1,     3,     4,    -1,   169,    -1,   171,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    -1,    -1,   172,    50,
      51,    12,    13,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    -1,    -1,
      -1,    92,    -1,    -1,    95,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    -1,
      -1,    -1,    73,    74,    -1,    76,    77,    78,    -1,     6,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   154,   155,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,   164,    -1,     3,     4,    -1,   169,    -1,
     171,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,   172,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    61,    -1,    -1,    64,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    -1,    -1,    -1,    92,    -1,    -1,    95,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   131,     6,    -1,    -1,   163,    -1,    -1,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,   155,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,   164,    -1,     3,     4,
       5,   169,    -1,   171,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    49,    50,    51,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    12,    13,    49,    50,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,   139,   140,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,   154,
     155,    -1,    73,    74,   159,    76,    77,    78,    -1,   164,
      -1,    82,    -1,    -1,   169,    -1,   171,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,   154,   155,
      -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,   164,    -1,
       3,     4,     5,   169,    -1,   171,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     3,     4,    49,    50,    51,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    50,    51,    12,    13,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,   154,   155,    -1,    73,    74,   159,    76,    77,    78,
      -1,   164,    -1,    82,    -1,    -1,   169,    -1,   171,     6,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,   111,   112,   113,   154,   155,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,   164,    -1,    -1,   167,    -1,
     169,    -1,   171,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,    44,    45,    46,     3,     4,    -1,
      50,    51,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    50,    51,    12,    13,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   131,    -1,    -1,    -1,   163,    -1,    -1,   138,   139,
     140,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,   154,   155,    -1,    73,    74,   159,
      76,    77,    78,    -1,   164,    -1,    82,     7,     8,   169,
      -1,   171,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   154,   155,
      -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,   164,    -1,
       3,     4,    -1,   169,    -1,   171,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    -1,    -1,   172,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    -1,
      -1,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    -1,    -1,     8,    92,
      -1,    -1,    95,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     8,
      -1,    -1,    -1,   163,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   131,     8,
      -1,    -1,   163,    -1,    -1,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   155,    -1,    -1,    -1,   159,     3,     4,     5,
      -1,   164,    -1,     9,    10,    11,   169,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    49,    50,    51,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,   139,   140,    -1,    -1,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,   154,   155,
      12,    13,    -1,   159,    -1,    -1,    -1,    -1,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,     4,   100,   101,
      -1,    -1,    -1,   105,    -1,    12,    13,    -1,   110,   111,
     112,   113,    -1,    -1,   116,    -1,   118,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    36,
      37,    -1,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    -1,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    -1,    -1,   100,   101,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,    -1,    -1,   116,
      -1,   118,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,   172,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,   170,    -1,   172,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   172,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   172,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   172,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   172,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   172,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,   165,
      -1,    -1,    -1,    -1,   170,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,   170,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,   170,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,   170,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,   170,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,   170,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,   170,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,   170,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,   170,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,   170,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,   170,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,   170,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,   170,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,   170,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,   170,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,   170,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,   170,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,   170,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,   170,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,   170,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,   170,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,   170,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,   170,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,   167,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,   167,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,    -1,    -1,    -1,   167,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,   167,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,
     167,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,   167,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,    -1,    -1,    -1,   167,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,
      -1,    -1,   167,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,   167,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,   167,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,    -1,    -1,    -1,   167,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,   167,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,
     167,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,   167,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,    -1,    -1,    -1,   167,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,
      -1,    -1,   167,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,   167,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,   167,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,    -1,    -1,    -1,   167,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,   167,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,
     167,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,   167,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,    -1,    -1,    -1,   167,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,
      -1,    -1,   167,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,   167,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,   167,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,    -1,   165,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,   165,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,    -1,   165,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,   165,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,    -1,   165,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,   165,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,    -1,   165,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,   165,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,
     165,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,   165,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,    -1,   165,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,   165,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,    -1,   165,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,   165,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,    -1,   165,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,   165,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,    -1,   165,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,   165,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,
     165,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,   165,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,    -1,   165,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,   165,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,    -1,   165,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,   165,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,    -1,   165,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,   165,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,    -1,   165,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,   165,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,
     165,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,   165,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,    -1,   165,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,   165,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,    -1,   165,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,   165,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,    -1,   165,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,   165,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,    -1,   165,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,   165,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,
     165,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,   165,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,    -1,   165,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,   165,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,    -1,   165,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,   165,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,    -1,   165,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,   165,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,    -1,   165,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,   165,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,
     165,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
      -1,   165,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,    -1,   165,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,    -1,   165,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,    -1,   165,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,    -1,   165,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,    -1,   165,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   175,   176,     6,     0,     4,    12,    13,    36,
      37,    47,    48,    52,    53,    54,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   100,   101,   105,   110,
     111,   112,   113,   116,   118,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   134,   135,   136,   137,
     177,   179,   180,   198,   212,   217,   220,   221,   222,   223,
     224,   225,   226,   246,   247,   248,   249,     3,     4,     5,
       7,     9,    10,    11,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    49,    50,    51,   125,   131,   132,
     133,   138,   139,   140,   141,   142,   143,   144,   154,   155,
     159,   161,   162,   164,   166,   168,   169,   171,   196,   197,
     250,   251,   262,   263,    13,    64,   164,   164,     6,   171,
       6,     6,     6,     6,   166,   166,   164,   171,   164,   164,
       4,   164,   171,   164,   164,     4,   171,   164,   164,    68,
      64,    64,     6,   171,    64,    64,    61,    64,    66,    66,
      58,    61,    64,    66,    61,    64,    66,    61,    64,   164,
      61,   116,   129,   130,   171,   154,   155,   164,   171,   252,
     253,   252,   171,    58,    61,    64,   171,   252,     4,    58,
      62,    73,    64,    66,    64,    61,     4,   125,   171,     4,
       6,    58,    61,    64,    61,    64,     4,     4,     4,     5,
      35,    58,    61,    64,    66,    77,   155,   164,   171,   217,
     226,   250,   255,   256,   257,     4,   164,   164,   164,     4,
     171,   259,     4,   164,   164,     6,     6,   166,     4,     4,
       5,   171,     5,   171,     4,   250,     6,   164,   171,     4,
     166,   168,   173,   197,   263,   164,   166,   164,   166,   164,
     166,   164,   166,   164,   166,   164,   166,   164,   166,   164,
     166,   164,   166,   164,   166,   164,   166,   164,   166,   164,
     166,   164,   166,   164,   166,   164,   166,   164,   166,   164,
     166,   164,   166,   164,   166,   164,   166,   164,   166,   164,
     166,   164,   164,   164,   164,   164,   164,   164,     7,   164,
     164,   164,   250,   250,   250,   171,   250,   167,   171,   250,
       4,   116,   117,     4,     4,   217,   218,   219,   255,     6,
       6,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   163,   171,     6,     6,   250,
       4,   262,   263,   262,   250,   200,   203,   250,   155,   250,
     257,   258,   250,   250,   164,   250,   258,   250,   250,   164,
     258,   250,   250,   255,   164,   171,   258,   164,   164,   256,
     256,   256,   164,   213,   214,   215,   216,   164,   164,   164,
     255,   250,     4,   255,   259,   171,   171,   252,   252,   252,
     250,   250,   154,   155,   171,   171,   252,   171,   171,   171,
     154,   155,   164,   219,   252,   171,   164,   171,   164,   164,
     164,   256,   256,   255,   164,     4,     6,   166,   166,   219,
       6,   171,   171,   171,   256,   256,   166,   166,   164,   166,
     168,   166,     5,   171,     5,     5,     5,    58,    61,    64,
      66,   171,   250,   257,   250,   172,   258,     8,   156,     6,
       6,   250,   250,   250,   168,   250,   171,   119,   250,   250,
     250,     6,     6,   219,     6,   219,   166,     6,   255,   255,
     166,   250,     4,   171,     6,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   262,   264,   264,
     262,   262,   262,   262,   262,   262,   262,   262,   264,   250,
     262,   262,   262,   258,   165,     7,   196,   258,   167,     7,
     196,   197,   168,     7,   166,   172,    58,    61,    64,    66,
     212,     6,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   181,     6,   166,
     168,   165,   170,   165,   170,   170,   167,   170,   199,   167,
     199,   165,   156,   170,   172,   165,   165,   250,   165,   172,
     165,   165,   250,   172,   165,   165,     7,   250,   250,   172,
     250,   250,     7,     7,   244,   244,   250,   164,   164,   164,
     164,   250,   250,   250,     7,   171,   165,     6,   171,   219,
     219,   170,   170,   170,   252,   252,   218,   218,   170,   250,
     250,   250,   250,   230,   170,   219,   250,   250,   250,   250,
     250,     7,   245,     6,     7,   250,     6,   250,   250,   172,
     258,   258,   258,     6,     6,   250,   250,   165,   171,   167,
     171,   250,     4,     4,   250,   171,   171,   171,   171,   258,
     165,   172,   250,   171,   250,   257,   165,   165,   165,   116,
     170,   219,   171,     8,   165,   167,   172,   172,   165,   170,
     172,   250,   167,   197,   250,   165,   167,   165,   167,   165,
     167,   165,   167,   165,   167,   165,   167,   165,   167,   165,
     167,   165,   167,   165,   167,   165,   167,   170,   170,   165,
     167,   165,   167,   165,   167,   165,   167,   165,   167,   165,
     167,   170,   170,   170,   170,   170,   170,   165,   170,   167,
     165,   170,   167,   170,   170,   165,   165,   170,   170,   170,
     165,     6,   170,   165,   170,   172,   196,   255,   172,   168,
     196,   197,   263,   250,     6,     4,     4,   171,   260,   167,
     171,   171,   171,   171,     8,     4,   106,   107,   108,   109,
     172,   184,   188,   191,   193,   194,   250,     4,     6,   151,
     178,   258,     6,   258,   250,     6,     4,     6,   262,     7,
     250,   257,   119,     7,     7,   165,     7,   119,     7,     7,
     165,   119,     7,     7,   250,   165,   172,   171,   165,   165,
     250,   255,     4,   243,     6,   165,   209,   250,   263,   209,
     209,   209,   165,   165,   165,   255,   258,   168,   219,   172,
     172,   252,   250,   250,   172,   172,   250,   252,   170,   170,
     170,    80,    90,    98,    99,   102,   103,   240,   241,   252,
     172,   227,   165,   172,   165,   165,   165,   250,     6,   250,
     165,   167,   167,   172,   172,   172,   167,   167,   258,   258,
     167,   167,   172,   258,   258,   258,   258,   172,     8,   258,
       7,     7,     7,   168,   250,   172,   250,   250,     7,   168,
     171,   255,     6,   167,   168,   197,   262,   172,   250,   250,
     250,   250,   250,   250,   250,   250,   262,   258,   258,   262,
     262,   262,   262,   250,   262,   165,   250,     6,   167,     4,
     116,   117,   250,     6,     6,     6,     7,   166,   259,   261,
       6,   258,   258,   258,   258,   250,   185,   164,   164,   171,
     195,     6,   167,   151,   262,   165,   165,   170,     7,   252,
      64,    66,   255,   255,     7,   255,    64,    66,   255,   255,
       7,    66,   255,   255,     6,     7,     7,   258,     7,     7,
      80,   242,     6,     7,   165,   165,   165,   165,     7,     7,
       7,     6,   172,     4,   172,   170,   170,   170,   172,   172,
     252,   252,   252,     4,     6,   171,   164,     6,   104,     6,
     104,   172,   241,   170,   240,     7,     6,     7,     7,     7,
       6,   171,     6,     6,     6,    64,   250,     6,     6,   172,
     172,   168,   172,   172,   172,   172,   250,   172,   255,   255,
     255,     4,   170,     8,     8,   165,     4,     4,   255,   172,
       6,     4,     6,   165,   167,   165,   167,   165,   167,   165,
     167,   165,   167,   165,   170,   165,   165,   165,   165,   196,
       6,   196,     7,   196,   197,   168,     7,     6,   259,   250,
     170,   172,   172,   172,   172,   172,   164,   250,   250,   254,
     255,   171,   168,     6,     6,   178,     6,   250,   171,   250,
     263,     6,   171,   171,    73,   211,   211,   255,     6,   171,
     171,     6,     6,   255,   171,     6,     6,     5,   255,   172,
     255,   255,     4,     6,   255,     7,     7,     7,     7,   255,
     255,   255,     7,     6,     7,   250,   250,   250,   171,   171,
     170,   172,   170,   172,   170,   172,   166,   250,   255,   250,
       6,     6,   250,   252,   172,     5,   171,   255,   171,   171,
     171,   255,   258,   171,     6,   165,   167,     4,     6,     6,
     115,   250,   250,   250,     6,     6,     7,   170,     6,   197,
     262,   255,   255,   263,   250,     6,     4,   260,     6,   167,
     259,     6,     6,     6,     6,   182,   250,   170,   170,   170,
     172,   183,   250,     4,   262,   170,   250,   263,   250,   250,
     252,     6,     6,     6,   250,   250,     6,   250,     5,     6,
     171,     6,   119,   210,   250,     6,   255,   255,   255,   255,
       6,     4,     6,     6,   250,   250,   263,   172,   165,   170,
     172,   218,   218,   252,     6,   231,   252,     6,   232,   252,
       6,   233,   250,   172,   170,   165,   172,   170,     6,   155,
     252,     6,   254,   252,   252,     6,   172,   250,   255,   170,
     172,     8,   172,   165,   171,   250,   263,   255,   165,     6,
       6,     6,     6,     7,     6,   168,   165,   170,   250,   250,
     255,   171,   170,   172,     6,   250,   201,   202,   172,   172,
     172,   172,   172,     5,   254,    62,     6,     6,     6,     6,
       6,   171,   171,     6,     6,   171,   250,   172,   172,   170,
     171,   170,   171,   170,   171,   167,     6,   255,     7,   171,
     250,   170,   172,   170,   170,     6,   172,   114,   250,   250,
     258,     6,     6,   172,   259,   117,   186,   250,   170,   170,
     254,   250,     6,   170,   205,   207,     6,     6,     6,     6,
       6,     6,   172,   171,   254,   258,   218,   170,   172,   250,
     252,   240,   250,   252,   240,   250,   252,   240,     6,   170,
     172,   255,   219,   172,   252,     6,   258,   252,   250,   172,
     172,   172,     6,     6,   171,   250,   250,   172,   250,   170,
     172,   206,   170,   172,   208,   171,   250,   172,   172,   172,
     250,   172,   170,   172,   172,   170,   172,   172,   170,   172,
     255,     6,    80,   172,   228,   171,   170,   172,   170,     6,
       6,   183,   165,   170,     6,   171,   170,     4,     4,   250,
     172,     6,     6,   172,     6,   234,   250,     6,     6,   235,
     250,     6,     6,   236,   250,     6,   172,   250,   240,   219,
     258,     6,   252,   258,   172,   189,   250,   254,   250,   171,
     255,   263,   171,   250,   263,   170,   171,   172,   171,   172,
     171,   172,     6,     6,   172,   172,   229,   172,   170,   172,
       6,   171,   165,   172,   172,   204,   250,   264,   250,   240,
       6,   237,   240,     6,   238,   240,     6,   239,   240,     6,
     258,     6,   187,   262,   192,   171,     6,   170,   172,     7,
     172,   172,   172,   171,   172,   171,   172,   171,   172,   172,
     170,   172,   171,   254,   250,   263,     6,     6,   240,     6,
     240,     6,   240,     6,   262,     6,   190,   262,   172,     7,
     172,   172,   172,   170,   172,     6,   263,     6,     6,     6,
     262,     6
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
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 148:
#line 1857 "Gmsh.y"
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
#line 1887 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 150:
#line 1891 "Gmsh.y"
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
#line 1911 "Gmsh.y"
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
#line 1929 "Gmsh.y"
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
#line 1946 "Gmsh.y"
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
#line 1962 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 155:
#line 1966 "Gmsh.y"
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
#line 1988 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 157:
#line 1993 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 158:
#line 1998 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 159:
#line 2003 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 160:
#line 2008 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 161:
#line 2013 "Gmsh.y"
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
#line 2036 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 163:
#line 2042 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 164:
#line 2052 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 165:
#line 2053 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 166:
#line 2058 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 167:
#line 2062 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 168:
#line 2066 "Gmsh.y"
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
#line 2089 "Gmsh.y"
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
#line 2112 "Gmsh.y"
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
#line 2135 "Gmsh.y"
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
#line 2163 "Gmsh.y"
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
#line 2184 "Gmsh.y"
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
#line 2211 "Gmsh.y"
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
#line 2232 "Gmsh.y"
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
#line 2253 "Gmsh.y"
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
#line 2273 "Gmsh.y"
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
#line 2385 "Gmsh.y"
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
#line 2404 "Gmsh.y"
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
#line 2443 "Gmsh.y"
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
#line 2551 "Gmsh.y"
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
#line 2560 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 183:
#line 2566 "Gmsh.y"
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
#line 2581 "Gmsh.y"
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
#line 2609 "Gmsh.y"
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
#line 2626 "Gmsh.y"
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
#line 2635 "Gmsh.y"
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
#line 2649 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 189:
#line 2655 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 190:
#line 2661 "Gmsh.y"
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
#line 2670 "Gmsh.y"
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
#line 2679 "Gmsh.y"
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
#line 2688 "Gmsh.y"
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
#line 2702 "Gmsh.y"
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
#line 2747 "Gmsh.y"
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
#line 2764 "Gmsh.y"
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
#line 2779 "Gmsh.y"
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
#line 2798 "Gmsh.y"
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
#line 2810 "Gmsh.y"
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
#line 2834 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 201:
#line 2838 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 202:
#line 2843 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 203:
#line 2850 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 204:
#line 2856 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 205:
#line 2861 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 206:
#line 2867 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 207:
#line 2871 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 208:
#line 2875 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 209:
#line 2881 "Gmsh.y"
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
#line 2935 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    ;}
    break;

  case 211:
#line 2948 "Gmsh.y"
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
#line 2965 "Gmsh.y"
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
#line 2982 "Gmsh.y"
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
#line 3003 "Gmsh.y"
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
#line 3024 "Gmsh.y"
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
#line 3059 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 217:
#line 3067 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 218:
#line 3073 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 219:
#line 3080 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 220:
#line 3084 "Gmsh.y"
    {
    ;}
    break;

  case 221:
#line 3093 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 222:
#line 3101 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 223:
#line 3109 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 224:
#line 3117 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 225:
#line 3122 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 226:
#line 3130 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 227:
#line 3135 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 228:
#line 3143 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 229:
#line 3148 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 230:
#line 3156 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 231:
#line 3161 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 232:
#line 3169 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 233:
#line 3176 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 234:
#line 3183 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 235:
#line 3190 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 236:
#line 3197 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 237:
#line 3204 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 238:
#line 3211 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 239:
#line 3218 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 240:
#line 3225 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 241:
#line 3232 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 242:
#line 3237 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 243:
#line 3244 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 244:
#line 3249 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 245:
#line 3256 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 246:
#line 3261 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 247:
#line 3268 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 248:
#line 3273 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 249:
#line 3280 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 250:
#line 3285 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 251:
#line 3292 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 252:
#line 3297 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 253:
#line 3304 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 254:
#line 3309 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 255:
#line 3316 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 256:
#line 3321 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 257:
#line 3328 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 258:
#line 3333 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 259:
#line 3344 "Gmsh.y"
    {
    ;}
    break;

  case 260:
#line 3347 "Gmsh.y"
    {
    ;}
    break;

  case 261:
#line 3353 "Gmsh.y"
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
#line 3365 "Gmsh.y"
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
#line 3385 "Gmsh.y"
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
#line 3408 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 265:
#line 3412 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 266:
#line 3416 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 267:
#line 3420 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 268:
#line 3424 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 269:
#line 3428 "Gmsh.y"
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

  case 270:
#line 3447 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 271:
#line 3459 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 272:
#line 3463 "Gmsh.y"
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

  case 273:
#line 3478 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 274:
#line 3482 "Gmsh.y"
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

  case 275:
#line 3498 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 276:
#line 3502 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 277:
#line 3507 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 278:
#line 3511 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 279:
#line 3518 "Gmsh.y"
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

  case 280:
#line 3574 "Gmsh.y"
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

  case 281:
#line 3644 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 282:
#line 3649 "Gmsh.y"
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

  case 283:
#line 3716 "Gmsh.y"
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

  case 284:
#line 3752 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 285:
#line 3760 "Gmsh.y"
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

  case 286:
#line 3803 "Gmsh.y"
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

  case 287:
#line 3842 "Gmsh.y"
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

  case 288:
#line 3862 "Gmsh.y"
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

  case 289:
#line 3890 "Gmsh.y"
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

  case 290:
#line 3929 "Gmsh.y"
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

  case 291:
#line 3952 "Gmsh.y"
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

  case 292:
#line 3975 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    ;}
    break;

  case 293:
#line 3979 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 294:
#line 3983 "Gmsh.y"
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

  case 295:
#line 4006 "Gmsh.y"
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

  case 296:
#line 4045 "Gmsh.y"
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

  case 297:
#line 4090 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 298:
#line 4094 "Gmsh.y"
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

  case 299:
#line 4104 "Gmsh.y"
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

  case 300:
#line 4138 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 301:
#line 4139 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 302:
#line 4140 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 303:
#line 4145 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 304:
#line 4151 "Gmsh.y"
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

  case 305:
#line 4163 "Gmsh.y"
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

  case 306:
#line 4181 "Gmsh.y"
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

  case 307:
#line 4208 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 308:
#line 4209 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 309:
#line 4210 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 310:
#line 4211 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 311:
#line 4212 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 312:
#line 4213 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 313:
#line 4214 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 314:
#line 4215 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 315:
#line 4217 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 316:
#line 4223 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 317:
#line 4224 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 318:
#line 4225 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 319:
#line 4226 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 320:
#line 4227 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 321:
#line 4228 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 322:
#line 4229 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 323:
#line 4230 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 324:
#line 4231 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 325:
#line 4232 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 326:
#line 4233 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 327:
#line 4234 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 328:
#line 4235 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 329:
#line 4236 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 330:
#line 4237 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 331:
#line 4238 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 332:
#line 4239 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 333:
#line 4240 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 334:
#line 4241 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 335:
#line 4242 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 336:
#line 4243 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 337:
#line 4244 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 338:
#line 4245 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 339:
#line 4246 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 340:
#line 4247 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 341:
#line 4248 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 342:
#line 4249 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 343:
#line 4250 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 344:
#line 4251 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 345:
#line 4252 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 346:
#line 4253 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 347:
#line 4254 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 348:
#line 4257 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 349:
#line 4258 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 350:
#line 4259 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 351:
#line 4260 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 352:
#line 4261 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 353:
#line 4262 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 354:
#line 4263 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 355:
#line 4264 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 356:
#line 4265 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 357:
#line 4266 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 358:
#line 4267 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 359:
#line 4268 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 360:
#line 4269 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 361:
#line 4270 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 362:
#line 4271 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 363:
#line 4272 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 364:
#line 4273 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 365:
#line 4274 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 366:
#line 4275 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 367:
#line 4276 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 368:
#line 4277 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 369:
#line 4286 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 370:
#line 4287 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 371:
#line 4288 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 372:
#line 4289 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 373:
#line 4290 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 374:
#line 4291 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 375:
#line 4292 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 376:
#line 4293 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 377:
#line 4294 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 378:
#line 4299 "Gmsh.y"
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

  case 379:
#line 4320 "Gmsh.y"
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

  case 380:
#line 4339 "Gmsh.y"
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

  case 381:
#line 4357 "Gmsh.y"
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

  case 382:
#line 4369 "Gmsh.y"
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

  case 383:
#line 4386 "Gmsh.y"
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

  case 384:
#line 4407 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 385:
#line 4412 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 386:
#line 4417 "Gmsh.y"
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

  case 387:
#line 4427 "Gmsh.y"
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

  case 388:
#line 4437 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 389:
#line 4442 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 390:
#line 4451 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 391:
#line 4456 "Gmsh.y"
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

  case 392:
#line 4483 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 393:
#line 4487 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 394:
#line 4491 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 395:
#line 4495 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 396:
#line 4499 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 397:
#line 4506 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 398:
#line 4510 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 399:
#line 4514 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 400:
#line 4518 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 401:
#line 4525 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 402:
#line 4530 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 403:
#line 4537 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 404:
#line 4542 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 405:
#line 4546 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 406:
#line 4551 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 407:
#line 4555 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 408:
#line 4563 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 409:
#line 4574 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 410:
#line 4578 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 411:
#line 4590 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 412:
#line 4598 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 413:
#line 4606 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 414:
#line 4613 "Gmsh.y"
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

  case 415:
#line 4623 "Gmsh.y"
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

  case 416:
#line 4643 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 417:
#line 4647 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 418:
#line 4651 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 419:
#line 4655 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 420:
#line 4659 "Gmsh.y"
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

  case 421:
#line 4688 "Gmsh.y"
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

  case 422:
#line 4717 "Gmsh.y"
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

  case 423:
#line 4746 "Gmsh.y"
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

  case 424:
#line 4775 "Gmsh.y"
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

  case 425:
#line 4785 "Gmsh.y"
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

  case 426:
#line 4795 "Gmsh.y"
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

  case 427:
#line 4808 "Gmsh.y"
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

  case 428:
#line 4820 "Gmsh.y"
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

  case 429:
#line 4832 "Gmsh.y"
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

  case 430:
#line 4851 "Gmsh.y"
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

  case 431:
#line 4872 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 432:
#line 4877 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 433:
#line 4881 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 434:
#line 4885 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 435:
#line 4897 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 436:
#line 4901 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 437:
#line 4913 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 438:
#line 4920 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 439:
#line 4930 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 440:
#line 4934 "Gmsh.y"
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

  case 441:
#line 4949 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 442:
#line 4954 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 443:
#line 4961 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 444:
#line 4965 "Gmsh.y"
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

  case 445:
#line 4978 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 446:
#line 4986 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 447:
#line 4997 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 448:
#line 5001 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 449:
#line 5009 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 450:
#line 5017 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 451:
#line 5025 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 452:
#line 5033 "Gmsh.y"
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

  case 453:
#line 5047 "Gmsh.y"
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

  case 454:
#line 5061 "Gmsh.y"
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

  case 455:
#line 5073 "Gmsh.y"
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

  case 456:
#line 5090 "Gmsh.y"
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

  case 457:
#line 5106 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 458:
#line 5111 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 459:
#line 5115 "Gmsh.y"
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

  case 460:
#line 5135 "Gmsh.y"
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

  case 461:
#line 5157 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 462:
#line 5162 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 10525 "Gmsh.tab.cpp"
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


#line 5165 "Gmsh.y"


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

