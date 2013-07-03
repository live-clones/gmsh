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
     tSyncModel = 305,
     tCreateTopology = 306,
     tCreateTopologyNoHoles = 307,
     tDistanceFunction = 308,
     tDefineConstant = 309,
     tUndefineConstant = 310,
     tPoint = 311,
     tCircle = 312,
     tEllipse = 313,
     tLine = 314,
     tSphere = 315,
     tPolarSphere = 316,
     tSurface = 317,
     tSpline = 318,
     tVolume = 319,
     tCharacteristic = 320,
     tLength = 321,
     tParametric = 322,
     tElliptic = 323,
     tRefineMesh = 324,
     tAdaptMesh = 325,
     tPlane = 326,
     tRuled = 327,
     tTransfinite = 328,
     tComplex = 329,
     tPhysical = 330,
     tCompound = 331,
     tPeriodic = 332,
     tUsing = 333,
     tPlugin = 334,
     tDegenerated = 335,
     tRotate = 336,
     tTranslate = 337,
     tSymmetry = 338,
     tDilate = 339,
     tExtrude = 340,
     tLevelset = 341,
     tRecombine = 342,
     tSmoother = 343,
     tSplit = 344,
     tDelete = 345,
     tCoherence = 346,
     tIntersect = 347,
     tMeshAlgorithm = 348,
     tReverse = 349,
     tLayers = 350,
     tHole = 351,
     tAlias = 352,
     tAliasWithOptions = 353,
     tQuadTriDbl = 354,
     tQuadTriSngl = 355,
     tRecombLaterals = 356,
     tTransfQuadTri = 357,
     tText2D = 358,
     tText3D = 359,
     tInterpolationScheme = 360,
     tTime = 361,
     tCombine = 362,
     tBSpline = 363,
     tBezier = 364,
     tNurbs = 365,
     tNurbsOrder = 366,
     tNurbsKnots = 367,
     tColor = 368,
     tColorTable = 369,
     tFor = 370,
     tIn = 371,
     tEndFor = 372,
     tIf = 373,
     tEndIf = 374,
     tExit = 375,
     tAbort = 376,
     tField = 377,
     tReturn = 378,
     tCall = 379,
     tFunction = 380,
     tShow = 381,
     tHide = 382,
     tGetValue = 383,
     tGetEnv = 384,
     tGetString = 385,
     tHomology = 386,
     tCohomology = 387,
     tBetti = 388,
     tSetOrder = 389,
     tGMSH_MAJOR_VERSION = 390,
     tGMSH_MINOR_VERSION = 391,
     tGMSH_PATCH_VERSION = 392,
     tAFFECTDIVIDE = 393,
     tAFFECTTIMES = 394,
     tAFFECTMINUS = 395,
     tAFFECTPLUS = 396,
     tOR = 397,
     tAND = 398,
     tNOTEQUAL = 399,
     tEQUAL = 400,
     tGREATEROREQUAL = 401,
     tLESSOREQUAL = 402,
     UNARYPREC = 403,
     tMINUSMINUS = 404,
     tPLUSPLUS = 405
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
#define tSyncModel 305
#define tCreateTopology 306
#define tCreateTopologyNoHoles 307
#define tDistanceFunction 308
#define tDefineConstant 309
#define tUndefineConstant 310
#define tPoint 311
#define tCircle 312
#define tEllipse 313
#define tLine 314
#define tSphere 315
#define tPolarSphere 316
#define tSurface 317
#define tSpline 318
#define tVolume 319
#define tCharacteristic 320
#define tLength 321
#define tParametric 322
#define tElliptic 323
#define tRefineMesh 324
#define tAdaptMesh 325
#define tPlane 326
#define tRuled 327
#define tTransfinite 328
#define tComplex 329
#define tPhysical 330
#define tCompound 331
#define tPeriodic 332
#define tUsing 333
#define tPlugin 334
#define tDegenerated 335
#define tRotate 336
#define tTranslate 337
#define tSymmetry 338
#define tDilate 339
#define tExtrude 340
#define tLevelset 341
#define tRecombine 342
#define tSmoother 343
#define tSplit 344
#define tDelete 345
#define tCoherence 346
#define tIntersect 347
#define tMeshAlgorithm 348
#define tReverse 349
#define tLayers 350
#define tHole 351
#define tAlias 352
#define tAliasWithOptions 353
#define tQuadTriDbl 354
#define tQuadTriSngl 355
#define tRecombLaterals 356
#define tTransfQuadTri 357
#define tText2D 358
#define tText3D 359
#define tInterpolationScheme 360
#define tTime 361
#define tCombine 362
#define tBSpline 363
#define tBezier 364
#define tNurbs 365
#define tNurbsOrder 366
#define tNurbsKnots 367
#define tColor 368
#define tColorTable 369
#define tFor 370
#define tIn 371
#define tEndFor 372
#define tIf 373
#define tEndIf 374
#define tExit 375
#define tAbort 376
#define tField 377
#define tReturn 378
#define tCall 379
#define tFunction 380
#define tShow 381
#define tHide 382
#define tGetValue 383
#define tGetEnv 384
#define tGetString 385
#define tHomology 386
#define tCohomology 387
#define tBetti 388
#define tSetOrder 389
#define tGMSH_MAJOR_VERSION 390
#define tGMSH_MINOR_VERSION 391
#define tGMSH_PATCH_VERSION 392
#define tAFFECTDIVIDE 393
#define tAFFECTTIMES 394
#define tAFFECTMINUS 395
#define tAFFECTPLUS 396
#define tOR 397
#define tAND 398
#define tNOTEQUAL 399
#define tEQUAL 400
#define tGREATEROREQUAL 401
#define tLESSOREQUAL 402
#define UNARYPREC 403
#define tMINUSMINUS 404
#define tPLUSPLUS 405




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
#line 506 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 519 "Gmsh.tab.cpp"

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
#define YYLAST   8397

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  171
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  455
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1584

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   405

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   156,     2,   166,     2,   155,     2,     2,
     161,   162,   153,   151,   167,   152,   165,   154,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     147,     2,   148,   142,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   163,     2,   164,   160,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   168,     2,   169,   170,     2,     2,     2,
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
     135,   136,   137,   138,   139,   140,   141,   143,   144,   145,
     146,   149,   150,   157,   158,   159
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
    1041,  1056,  1061,  1068,  1075,  1079,  1084,  1090,  1094,  1098,
    1103,  1108,  1112,  1120,  1128,  1132,  1140,  1144,  1147,  1150,
    1153,  1156,  1172,  1175,  1178,  1181,  1184,  1201,  1205,  1212,
    1221,  1230,  1241,  1243,  1246,  1248,  1252,  1257,  1259,  1265,
    1277,  1291,  1292,  1300,  1301,  1315,  1316,  1332,  1333,  1340,
    1349,  1358,  1367,  1380,  1393,  1406,  1421,  1436,  1451,  1452,
    1465,  1466,  1479,  1480,  1493,  1494,  1511,  1512,  1529,  1530,
    1547,  1548,  1567,  1568,  1587,  1588,  1607,  1609,  1612,  1618,
    1626,  1636,  1639,  1642,  1646,  1649,  1653,  1663,  1670,  1671,
    1675,  1676,  1678,  1679,  1682,  1683,  1686,  1694,  1701,  1710,
    1716,  1720,  1728,  1734,  1739,  1746,  1753,  1766,  1777,  1788,
    1799,  1810,  1815,  1820,  1823,  1827,  1834,  1836,  1838,  1840,
    1843,  1849,  1857,  1868,  1870,  1874,  1877,  1880,  1883,  1887,
    1891,  1895,  1899,  1903,  1907,  1911,  1915,  1919,  1923,  1927,
    1931,  1935,  1939,  1945,  1950,  1955,  1960,  1965,  1970,  1975,
    1980,  1985,  1990,  1995,  2002,  2007,  2012,  2017,  2022,  2027,
    2032,  2039,  2046,  2053,  2058,  2063,  2068,  2073,  2078,  2083,
    2088,  2093,  2098,  2103,  2108,  2115,  2120,  2125,  2130,  2135,
    2140,  2145,  2152,  2159,  2166,  2171,  2173,  2175,  2177,  2179,
    2181,  2183,  2185,  2187,  2193,  2198,  2203,  2206,  2212,  2216,
    2223,  2228,  2236,  2243,  2250,  2257,  2262,  2264,  2267,  2270,
    2274,  2278,  2290,  2300,  2308,  2316,  2318,  2322,  2324,  2326,
    2329,  2333,  2338,  2344,  2346,  2348,  2351,  2355,  2359,  2365,
    2370,  2373,  2376,  2379,  2382,  2388,  2394,  2400,  2406,  2408,
    2410,  2414,  2418,  2423,  2430,  2437,  2439,  2441,  2445,  2449,
    2459,  2467,  2469,  2475,  2479,  2486,  2488,  2492,  2494,  2496,
    2500,  2507,  2509,  2511,  2516,  2523,  2530,  2535,  2540,  2549,
    2554,  2559,  2564,  2571,  2578,  2580
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     172,     0,    -1,   173,    -1,     1,     6,    -1,    -1,   173,
     174,    -1,   177,    -1,   176,    -1,   195,    -1,   209,    -1,
     214,    -1,   218,    -1,   219,    -1,   220,    -1,   223,    -1,
     243,    -1,   244,    -1,   222,    -1,   221,    -1,   217,    -1,
     246,    -1,   148,    -1,   148,   148,    -1,    36,   161,     5,
     162,     6,    -1,    37,   161,     5,   162,     6,    -1,    36,
     161,     5,   162,   175,   259,     6,    -1,    36,   161,     5,
     167,   255,   162,     6,    -1,    37,   161,     5,   167,   255,
     162,     6,    -1,    36,   161,     5,   167,   255,   162,   175,
     259,     6,    -1,     4,     5,   168,   178,   169,     6,    -1,
      97,     4,   163,   247,   164,     6,    -1,    98,     4,   163,
     247,   164,     6,    -1,    -1,   178,   181,    -1,   178,   185,
      -1,   178,   188,    -1,   178,   190,    -1,   178,   191,    -1,
     247,    -1,   179,   167,   247,    -1,   247,    -1,   180,   167,
     247,    -1,    -1,    -1,     4,   182,   161,   179,   162,   183,
     168,   180,   169,     6,    -1,   259,    -1,   184,   167,   259,
      -1,    -1,   103,   161,   247,   167,   247,   167,   247,   162,
     186,   168,   184,   169,     6,    -1,   259,    -1,   187,   167,
     259,    -1,    -1,   104,   161,   247,   167,   247,   167,   247,
     167,   247,   162,   189,   168,   187,   169,     6,    -1,   105,
     168,   251,   169,   168,   251,   169,     6,    -1,   105,   168,
     251,   169,   168,   251,   169,   168,   251,   169,   168,   251,
     169,     6,    -1,    -1,   106,   192,   168,   180,   169,     6,
      -1,     7,    -1,   141,    -1,   140,    -1,   139,    -1,   138,
      -1,   159,    -1,   158,    -1,    54,   163,   197,   164,     6,
      -1,    55,   163,   200,   164,     6,    -1,     4,   193,   252,
       6,    -1,     4,   163,   164,   193,   252,     6,    -1,     4,
     163,   247,   164,   193,   247,     6,    -1,     4,   161,   247,
     162,   193,   247,     6,    -1,     4,   163,   168,   255,   169,
     164,   193,   252,     6,    -1,     4,   161,   168,   255,   169,
     162,   193,   252,     6,    -1,     4,   194,     6,    -1,     4,
     163,   247,   164,   194,     6,    -1,     4,     7,   260,     6,
      -1,     4,   165,     4,     7,   260,     6,    -1,     4,   163,
     247,   164,   165,     4,     7,   260,     6,    -1,     4,   165,
       4,   193,   247,     6,    -1,     4,   163,   247,   164,   165,
       4,   193,   247,     6,    -1,     4,   165,     4,   194,     6,
      -1,     4,   163,   247,   164,   165,     4,   194,     6,    -1,
       4,   165,   113,   165,     4,     7,   256,     6,    -1,     4,
     163,   247,   164,   165,   113,   165,     4,     7,   256,     6,
      -1,     4,   165,   114,     7,   257,     6,    -1,     4,   163,
     247,   164,   165,   114,     7,   257,     6,    -1,     4,   122,
       7,   247,     6,    -1,   122,   163,   247,   164,     7,     4,
       6,    -1,   122,   163,   247,   164,   165,     4,     7,   247,
       6,    -1,   122,   163,   247,   164,   165,     4,     7,   260,
       6,    -1,   122,   163,   247,   164,   165,     4,     7,   168,
     255,   169,     6,    -1,   122,   163,   247,   164,   165,     4,
       6,    -1,    79,   161,     4,   162,   165,     4,     7,   247,
       6,    -1,    79,   161,     4,   162,   165,     4,     7,   260,
       6,    -1,    -1,   167,    -1,    -1,   197,   196,     4,    -1,
     197,   196,     4,     7,   247,    -1,    -1,   197,   196,     4,
       7,   168,   247,   198,   202,   169,    -1,   197,   196,     4,
       7,   260,    -1,    -1,   197,   196,     4,     7,   168,   260,
     199,   204,   169,    -1,    -1,   200,   196,   259,    -1,   247,
       7,   260,    -1,   201,   167,   247,     7,   260,    -1,    -1,
     202,   203,    -1,   167,     4,   252,    -1,   167,     4,   168,
     201,   169,    -1,   167,     4,   260,    -1,    -1,   204,   205,
      -1,   167,     4,   247,    -1,   167,     4,   260,    -1,   167,
       4,   168,   261,   169,    -1,   247,    -1,   260,    -1,    -1,
     116,    60,   168,   247,   169,    -1,    -1,    71,   249,    -1,
      56,   161,   247,   162,     7,   249,     6,    -1,    -1,    75,
      56,   210,   161,   206,   162,     7,   252,     6,    -1,    65,
      66,   252,     7,   247,     6,    -1,    59,   161,   247,   162,
       7,   252,     6,    -1,    80,    59,   252,     6,    -1,    63,
     161,   247,   162,     7,   252,     6,    -1,    57,   161,   247,
     162,     7,   252,   208,     6,    -1,    58,   161,   247,   162,
       7,   252,   208,     6,    -1,   108,   161,   247,   162,     7,
     252,     6,    -1,   109,   161,   247,   162,     7,   252,     6,
      -1,   110,   161,   247,   162,     7,   252,   112,   252,   111,
     247,     6,    -1,    59,     4,   161,   247,   162,     7,   252,
       6,    -1,    76,    59,   161,   247,   162,     7,   252,     6,
      -1,    -1,    75,    59,   211,   161,   206,   162,     7,   252,
       6,    -1,    71,    62,   161,   247,   162,     7,   252,     6,
      -1,    72,    62,   161,   247,   162,     7,   252,   207,     6,
      -1,    12,    13,     6,    -1,    13,    62,   247,     6,    -1,
      67,    62,   161,   247,   162,     7,     5,     5,     5,     6,
      -1,    60,   161,   247,   162,     7,   252,     6,    -1,    61,
     161,   247,   162,     7,   252,     6,    -1,    62,     4,   161,
     247,   162,     7,   252,     6,    -1,    76,    62,   161,   247,
     162,     7,   252,     6,    -1,    76,    62,   161,   247,   162,
       7,   252,     4,   168,   251,   169,     6,    -1,    -1,    75,
      62,   212,   161,   206,   162,     7,   252,     6,    -1,    74,
      64,   161,   247,   162,     7,   252,     6,    -1,    64,   161,
     247,   162,     7,   252,     6,    -1,    76,    64,   161,   247,
     162,     7,   252,     6,    -1,    -1,    75,    64,   213,   161,
     206,   162,     7,   252,     6,    -1,    82,   249,   168,   215,
     169,    -1,    81,   168,   249,   167,   249,   167,   247,   169,
     168,   215,   169,    -1,    83,   249,   168,   215,   169,    -1,
      84,   168,   249,   167,   247,   169,   168,   215,   169,    -1,
      84,   168,   249,   167,   249,   169,   168,   215,   169,    -1,
       4,   168,   215,   169,    -1,    92,    59,   168,   255,   169,
      62,   168,   247,   169,    -1,    89,    59,   161,   247,   162,
     168,   255,   169,     6,    -1,   216,    -1,   214,    -1,    -1,
     216,   209,    -1,   216,    56,   168,   255,   169,     6,    -1,
     216,    59,   168,   255,   169,     6,    -1,   216,    62,   168,
     255,   169,     6,    -1,   216,    64,   168,   255,   169,     6,
      -1,    86,    71,   161,   247,   162,     7,   252,     6,    -1,
      86,    56,   161,   247,   162,     7,   168,   251,   169,     6,
      -1,    86,    71,   161,   247,   162,     7,   168,   249,   167,
     249,   167,   255,   169,     6,    -1,    86,    71,   161,   247,
     162,     7,   168,   249,   167,   249,   167,   249,   167,   255,
     169,     6,    -1,    86,    60,   161,   247,   162,     7,   168,
     249,   167,   255,   169,     6,    -1,    86,     4,   161,   247,
     162,     7,   252,     6,    -1,    86,     4,   161,   247,   162,
       7,     5,     6,    -1,    86,     4,   168,   247,   169,     6,
      -1,    86,     4,   161,   247,   162,     7,   168,   249,   167,
     249,   167,   255,   169,     6,    -1,    90,   168,   216,   169,
      -1,    90,   122,   163,   247,   164,     6,    -1,    90,     4,
     163,   247,   164,     6,    -1,    90,     4,     6,    -1,    90,
       4,     4,     6,    -1,   113,   256,   168,   216,   169,    -1,
     126,     5,     6,    -1,   127,     5,     6,    -1,   126,   168,
     216,   169,    -1,   127,   168,   216,   169,    -1,     4,   260,
       6,    -1,     4,     4,   163,   247,   164,   259,     6,    -1,
       4,     4,     4,   163,   247,   164,     6,    -1,     4,   247,
       6,    -1,    79,   161,     4,   162,   165,     4,     6,    -1,
     107,     4,     6,    -1,   120,     6,    -1,   121,     6,    -1,
      50,     6,    -1,    47,     6,    -1,    47,   168,   247,   167,
     247,   167,   247,   167,   247,   167,   247,   167,   247,   169,
       6,    -1,    48,     6,    -1,    51,     6,    -1,    52,     6,
      -1,    69,     6,    -1,    70,   168,   255,   169,   168,   255,
     169,   168,   251,   169,   168,   247,   167,   247,   169,     6,
      -1,   134,   247,     6,    -1,   115,   161,   247,     8,   247,
     162,    -1,   115,   161,   247,     8,   247,     8,   247,   162,
      -1,   115,     4,   116,   168,   247,     8,   247,   169,    -1,
     115,     4,   116,   168,   247,     8,   247,     8,   247,   169,
      -1,   117,    -1,   125,     4,    -1,   123,    -1,   124,     4,
       6,    -1,   118,   161,   247,   162,    -1,   119,    -1,    85,
     249,   168,   216,   169,    -1,    85,   168,   249,   167,   249,
     167,   247,   169,   168,   216,   169,    -1,    85,   168,   249,
     167,   249,   167,   249,   167,   247,   169,   168,   216,   169,
      -1,    -1,    85,   249,   168,   216,   224,   237,   169,    -1,
      -1,    85,   168,   249,   167,   249,   167,   247,   169,   168,
     216,   225,   237,   169,    -1,    -1,    85,   168,   249,   167,
     249,   167,   249,   167,   247,   169,   168,   216,   226,   237,
     169,    -1,    -1,    85,   168,   216,   227,   237,   169,    -1,
      85,    56,   168,   247,   167,   249,   169,     6,    -1,    85,
      59,   168,   247,   167,   249,   169,     6,    -1,    85,    62,
     168,   247,   167,   249,   169,     6,    -1,    85,    56,   168,
     247,   167,   249,   167,   249,   167,   247,   169,     6,    -1,
      85,    59,   168,   247,   167,   249,   167,   249,   167,   247,
     169,     6,    -1,    85,    62,   168,   247,   167,   249,   167,
     249,   167,   247,   169,     6,    -1,    85,    56,   168,   247,
     167,   249,   167,   249,   167,   249,   167,   247,   169,     6,
      -1,    85,    59,   168,   247,   167,   249,   167,   249,   167,
     249,   167,   247,   169,     6,    -1,    85,    62,   168,   247,
     167,   249,   167,   249,   167,   249,   167,   247,   169,     6,
      -1,    -1,    85,    56,   168,   247,   167,   249,   169,   228,
     168,   237,   169,     6,    -1,    -1,    85,    59,   168,   247,
     167,   249,   169,   229,   168,   237,   169,     6,    -1,    -1,
      85,    62,   168,   247,   167,   249,   169,   230,   168,   237,
     169,     6,    -1,    -1,    85,    56,   168,   247,   167,   249,
     167,   249,   167,   247,   169,   231,   168,   237,   169,     6,
      -1,    -1,    85,    59,   168,   247,   167,   249,   167,   249,
     167,   247,   169,   232,   168,   237,   169,     6,    -1,    -1,
      85,    62,   168,   247,   167,   249,   167,   249,   167,   247,
     169,   233,   168,   237,   169,     6,    -1,    -1,    85,    56,
     168,   247,   167,   249,   167,   249,   167,   249,   167,   247,
     169,   234,   168,   237,   169,     6,    -1,    -1,    85,    59,
     168,   247,   167,   249,   167,   249,   167,   249,   167,   247,
     169,   235,   168,   237,   169,     6,    -1,    -1,    85,    62,
     168,   247,   167,   249,   167,   249,   167,   249,   167,   247,
     169,   236,   168,   237,   169,     6,    -1,   238,    -1,   237,
     238,    -1,    95,   168,   247,   169,     6,    -1,    95,   168,
     252,   167,   252,   169,     6,    -1,    95,   168,   252,   167,
     252,   167,   252,   169,     6,    -1,    87,     6,    -1,    99,
       6,    -1,    99,   101,     6,    -1,   100,     6,    -1,   100,
     101,     6,    -1,    96,   161,   247,   162,     7,   252,    78,
     247,     6,    -1,    78,     4,   163,   247,   164,     6,    -1,
      -1,    78,     4,   247,    -1,    -1,     4,    -1,    -1,     7,
     252,    -1,    -1,     7,   247,    -1,    73,    59,   253,     7,
     247,   239,     6,    -1,    73,    62,   253,   241,   240,     6,
      -1,    68,    62,   168,   247,   169,     7,   252,     6,    -1,
      73,    64,   253,   241,     6,    -1,   102,   253,     6,    -1,
      93,    62,   168,   255,   169,   247,     6,    -1,    87,    62,
     253,   242,     6,    -1,    87,    64,   253,     6,    -1,    88,
      62,   252,     7,   247,     6,    -1,    77,    59,   252,     7,
     252,     6,    -1,    77,    62,   247,   168,   255,   169,     7,
     247,   168,   255,   169,     6,    -1,    56,   168,   255,   169,
     116,    62,   168,   247,   169,     6,    -1,    59,   168,   255,
     169,   116,    62,   168,   247,   169,     6,    -1,    59,   168,
     255,   169,   116,    64,   168,   247,   169,     6,    -1,    62,
     168,   255,   169,   116,    64,   168,   247,   169,     6,    -1,
      94,    62,   253,     6,    -1,    94,    59,   253,     6,    -1,
      91,     6,    -1,    91,     4,     6,    -1,    91,    56,   168,
     255,   169,     6,    -1,   131,    -1,   132,    -1,   133,    -1,
     245,     6,    -1,   245,   168,   252,   169,     6,    -1,   245,
     168,   252,   167,   252,   169,     6,    -1,   245,   161,   252,
     162,   168,   252,   167,   252,   169,     6,    -1,   248,    -1,
     161,   247,   162,    -1,   152,   247,    -1,   151,   247,    -1,
     156,   247,    -1,   247,   152,   247,    -1,   247,   151,   247,
      -1,   247,   153,   247,    -1,   247,   154,   247,    -1,   247,
     155,   247,    -1,   247,   160,   247,    -1,   247,   147,   247,
      -1,   247,   148,   247,    -1,   247,   150,   247,    -1,   247,
     149,   247,    -1,   247,   146,   247,    -1,   247,   145,   247,
      -1,   247,   144,   247,    -1,   247,   143,   247,    -1,   247,
     142,   247,     8,   247,    -1,    14,   161,   247,   162,    -1,
      15,   161,   247,   162,    -1,    16,   161,   247,   162,    -1,
      17,   161,   247,   162,    -1,    18,   161,   247,   162,    -1,
      19,   161,   247,   162,    -1,    20,   161,   247,   162,    -1,
      21,   161,   247,   162,    -1,    22,   161,   247,   162,    -1,
      24,   161,   247,   162,    -1,    25,   161,   247,   167,   247,
     162,    -1,    26,   161,   247,   162,    -1,    27,   161,   247,
     162,    -1,    28,   161,   247,   162,    -1,    29,   161,   247,
     162,    -1,    30,   161,   247,   162,    -1,    31,   161,   247,
     162,    -1,    32,   161,   247,   167,   247,   162,    -1,    33,
     161,   247,   167,   247,   162,    -1,    34,   161,   247,   167,
     247,   162,    -1,    23,   161,   247,   162,    -1,    14,   163,
     247,   164,    -1,    15,   163,   247,   164,    -1,    16,   163,
     247,   164,    -1,    17,   163,   247,   164,    -1,    18,   163,
     247,   164,    -1,    19,   163,   247,   164,    -1,    20,   163,
     247,   164,    -1,    21,   163,   247,   164,    -1,    22,   163,
     247,   164,    -1,    24,   163,   247,   164,    -1,    25,   163,
     247,   167,   247,   164,    -1,    26,   163,   247,   164,    -1,
      27,   163,   247,   164,    -1,    28,   163,   247,   164,    -1,
      29,   163,   247,   164,    -1,    30,   163,   247,   164,    -1,
      31,   163,   247,   164,    -1,    32,   163,   247,   167,   247,
     164,    -1,    33,   163,   247,   167,   247,   164,    -1,    34,
     163,   247,   167,   247,   164,    -1,    23,   163,   247,   164,
      -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,   135,
      -1,   136,    -1,   137,    -1,     4,    -1,     4,   170,   168,
     247,   169,    -1,     4,   163,   247,   164,    -1,   166,     4,
     163,   164,    -1,     4,   194,    -1,     4,   163,   247,   164,
     194,    -1,     4,   165,     4,    -1,     4,   163,   247,   164,
     165,     4,    -1,     4,   165,     4,   194,    -1,     4,   163,
     247,   164,   165,     4,   194,    -1,   128,   161,   259,   167,
     247,   162,    -1,    44,   161,   259,   167,   259,   162,    -1,
      45,   161,   259,   167,   259,   162,    -1,    46,   161,   261,
     162,    -1,   250,    -1,   152,   249,    -1,   151,   249,    -1,
     249,   152,   249,    -1,   249,   151,   249,    -1,   168,   247,
     167,   247,   167,   247,   167,   247,   167,   247,   169,    -1,
     168,   247,   167,   247,   167,   247,   167,   247,   169,    -1,
     168,   247,   167,   247,   167,   247,   169,    -1,   161,   247,
     167,   247,   167,   247,   162,    -1,   252,    -1,   251,   167,
     252,    -1,   247,    -1,   254,    -1,   168,   169,    -1,   168,
     255,   169,    -1,   152,   168,   255,   169,    -1,   247,   153,
     168,   255,   169,    -1,   252,    -1,     5,    -1,   152,   254,
      -1,   247,   153,   254,    -1,   247,     8,   247,    -1,   247,
       8,   247,     8,   247,    -1,    56,   168,   247,   169,    -1,
      56,     5,    -1,    59,     5,    -1,    62,     5,    -1,    64,
       5,    -1,    75,    56,   168,   255,   169,    -1,    75,    59,
     168,   255,   169,    -1,    75,    62,   168,   255,   169,    -1,
      75,    64,   168,   255,   169,    -1,   214,    -1,   223,    -1,
       4,   163,   164,    -1,     4,   161,   162,    -1,    35,   163,
       4,   164,    -1,     4,   163,   168,   255,   169,   164,    -1,
       4,   161,   168,   255,   169,   162,    -1,   247,    -1,   254,
      -1,   255,   167,   247,    -1,   255,   167,   254,    -1,   168,
     247,   167,   247,   167,   247,   167,   247,   169,    -1,   168,
     247,   167,   247,   167,   247,   169,    -1,     4,    -1,     4,
     165,   113,   165,     4,    -1,   168,   258,   169,    -1,     4,
     163,   247,   164,   165,   114,    -1,   256,    -1,   258,   167,
     256,    -1,   260,    -1,     4,    -1,     4,   165,     4,    -1,
       4,   163,   247,   164,   165,     4,    -1,     5,    -1,    49,
      -1,   129,   161,   259,   162,    -1,   130,   161,   259,   167,
     259,   162,    -1,    40,   161,   259,   167,   259,   162,    -1,
      41,   161,   259,   162,    -1,    42,   161,   259,   162,    -1,
      43,   161,   259,   167,   259,   167,   259,   162,    -1,    38,
     163,   261,   164,    -1,    39,   161,   259,   162,    -1,    39,
     163,   259,   164,    -1,    39,   161,   259,   167,   255,   162,
      -1,    39,   163,   259,   167,   255,   164,    -1,   259,    -1,
     261,   167,   259,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   168,   168,   169,   174,   176,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   198,   202,   209,   214,   219,   233,   246,   259,   287,
     301,   312,   327,   332,   333,   334,   335,   336,   340,   342,
     347,   349,   355,   459,   354,   477,   484,   495,   494,   512,
     519,   530,   529,   546,   563,   586,   585,   599,   600,   601,
     602,   603,   607,   608,   614,   616,   618,   680,   710,   745,
     779,   827,   874,   889,   905,   914,   920,   929,   947,   965,
     974,   986,   991,   999,  1019,  1042,  1053,  1061,  1083,  1106,
    1132,  1153,  1165,  1179,  1179,  1181,  1183,  1194,  1206,  1205,
    1217,  1229,  1228,  1242,  1244,  1252,  1258,  1265,  1266,  1270,
    1281,  1296,  1306,  1307,  1312,  1320,  1329,  1347,  1351,  1362,
    1365,  1378,  1381,  1391,  1415,  1414,  1434,  1456,  1474,  1495,
    1513,  1543,  1573,  1591,  1609,  1635,  1653,  1672,  1671,  1694,
    1712,  1751,  1757,  1763,  1770,  1795,  1820,  1837,  1854,  1886,
    1885,  1909,  1927,  1944,  1961,  1960,  1986,  1991,  1996,  2001,
    2006,  2011,  2034,  2040,  2051,  2052,  2057,  2060,  2064,  2087,
    2110,  2133,  2161,  2182,  2208,  2229,  2251,  2271,  2383,  2402,
    2440,  2549,  2558,  2564,  2579,  2607,  2624,  2638,  2644,  2650,
    2659,  2673,  2718,  2735,  2750,  2769,  2781,  2805,  2809,  2814,
    2821,  2827,  2832,  2838,  2842,  2846,  2851,  2906,  2919,  2936,
    2953,  2974,  2995,  3030,  3038,  3044,  3051,  3055,  3064,  3072,
    3080,  3089,  3088,  3102,  3101,  3115,  3114,  3128,  3127,  3140,
    3147,  3154,  3161,  3168,  3175,  3182,  3189,  3196,  3204,  3203,
    3216,  3215,  3228,  3227,  3240,  3239,  3252,  3251,  3264,  3263,
    3276,  3275,  3288,  3287,  3300,  3299,  3315,  3318,  3324,  3336,
    3356,  3379,  3383,  3387,  3391,  3395,  3399,  3418,  3431,  3434,
    3450,  3453,  3466,  3469,  3475,  3478,  3485,  3541,  3611,  3616,
    3683,  3719,  3727,  3770,  3809,  3829,  3856,  3896,  3919,  3942,
    3946,  3969,  4008,  4053,  4057,  4067,  4102,  4103,  4104,  4108,
    4114,  4126,  4144,  4172,  4173,  4174,  4175,  4176,  4177,  4178,
    4179,  4180,  4187,  4188,  4189,  4190,  4191,  4192,  4193,  4194,
    4195,  4196,  4197,  4198,  4199,  4200,  4201,  4202,  4203,  4204,
    4205,  4206,  4207,  4208,  4209,  4210,  4211,  4212,  4213,  4214,
    4215,  4216,  4217,  4218,  4221,  4222,  4223,  4224,  4225,  4226,
    4227,  4228,  4229,  4230,  4231,  4232,  4233,  4234,  4235,  4236,
    4237,  4238,  4239,  4240,  4241,  4250,  4251,  4252,  4253,  4254,
    4255,  4256,  4260,  4281,  4300,  4318,  4330,  4347,  4368,  4373,
    4378,  4388,  4398,  4403,  4412,  4417,  4444,  4448,  4452,  4456,
    4460,  4467,  4471,  4475,  4479,  4486,  4491,  4498,  4503,  4507,
    4512,  4516,  4524,  4535,  4539,  4551,  4559,  4567,  4574,  4584,
    4604,  4608,  4612,  4616,  4620,  4649,  4678,  4707,  4736,  4746,
    4756,  4769,  4781,  4793,  4812,  4833,  4838,  4842,  4846,  4858,
    4862,  4874,  4881,  4891,  4895,  4910,  4915,  4922,  4926,  4939,
    4947,  4958,  4962,  4970,  4978,  4986,  4994,  5008,  5022,  5034,
    5050,  5055,  5059,  5079,  5101,  5106
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
  "tTextAttributes", "tBoundingBox", "tDraw", "tToday", "tSyncModel",
  "tCreateTopology", "tCreateTopologyNoHoles", "tDistanceFunction",
  "tDefineConstant", "tUndefineConstant", "tPoint", "tCircle", "tEllipse",
  "tLine", "tSphere", "tPolarSphere", "tSurface", "tSpline", "tVolume",
  "tCharacteristic", "tLength", "tParametric", "tElliptic", "tRefineMesh",
  "tAdaptMesh", "tPlane", "tRuled", "tTransfinite", "tComplex",
  "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
  "tDegenerated", "tRotate", "tTranslate", "tSymmetry", "tDilate",
  "tExtrude", "tLevelset", "tRecombine", "tSmoother", "tSplit", "tDelete",
  "tCoherence", "tIntersect", "tMeshAlgorithm", "tReverse", "tLayers",
  "tHole", "tAlias", "tAliasWithOptions", "tQuadTriDbl", "tQuadTriSngl",
  "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tEndIf", "tExit", "tAbort", "tField",
  "tReturn", "tCall", "tFunction", "tShow", "tHide", "tGetValue",
  "tGetEnv", "tGetString", "tHomology", "tCohomology", "tBetti",
  "tSetOrder", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION",
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
     395,   396,    63,   397,   398,   399,   400,    60,    62,   401,
     402,    43,    45,    42,    47,    37,    33,   403,   404,   405,
      94,    40,    41,    91,    93,    46,    35,    44,   123,   125,
     126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   171,   172,   172,   173,   173,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   175,   175,   176,   176,   176,   176,   176,   176,   177,
     177,   177,   178,   178,   178,   178,   178,   178,   179,   179,
     180,   180,   182,   183,   181,   184,   184,   186,   185,   187,
     187,   189,   188,   190,   190,   192,   191,   193,   193,   193,
     193,   193,   194,   194,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   196,   196,   197,   197,   197,   198,   197,
     197,   199,   197,   200,   200,   201,   201,   202,   202,   203,
     203,   203,   204,   204,   205,   205,   205,   206,   206,   207,
     207,   208,   208,   209,   210,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   211,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   212,
     209,   209,   209,   209,   213,   209,   214,   214,   214,   214,
     214,   214,   214,   214,   215,   215,   216,   216,   216,   216,
     216,   216,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   218,   218,   218,   218,   218,   219,   220,   220,   220,
     220,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   223,   223,
     223,   224,   223,   225,   223,   226,   223,   227,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   228,   223,
     229,   223,   230,   223,   231,   223,   232,   223,   233,   223,
     234,   223,   235,   223,   236,   223,   237,   237,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   239,   239,
     240,   240,   241,   241,   242,   242,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   244,   244,   244,   245,   245,   245,   246,
     246,   246,   246,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   249,   249,   249,   249,
     249,   250,   250,   250,   250,   251,   251,   252,   252,   252,
     252,   252,   252,   253,   253,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   255,   255,   255,   255,   256,
     256,   256,   256,   257,   257,   258,   258,   259,   259,   259,
     259,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   261,   261
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
      14,     4,     6,     6,     3,     4,     5,     3,     3,     4,
       4,     3,     7,     7,     3,     7,     3,     2,     2,     2,
       2,    15,     2,     2,     2,     2,    16,     3,     6,     8,
       8,    10,     1,     2,     1,     3,     4,     1,     5,    11,
      13,     0,     7,     0,    13,     0,    15,     0,     6,     8,
       8,     8,    12,    12,    12,    14,    14,    14,     0,    12,
       0,    12,     0,    12,     0,    16,     0,    16,     0,    16,
       0,    18,     0,    18,     0,    18,     1,     2,     5,     7,
       9,     2,     2,     3,     2,     3,     9,     6,     0,     3,
       0,     1,     0,     2,     0,     2,     7,     6,     8,     5,
       3,     7,     5,     4,     6,     6,    12,    10,    10,    10,
      10,     4,     4,     2,     3,     6,     1,     1,     1,     2,
       5,     7,    10,     1,     3,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4,     4,     2,     5,     3,     6,
       4,     7,     6,     6,     6,     4,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     1,     3,     1,     1,     2,
       3,     4,     5,     1,     1,     2,     3,     3,     5,     4,
       2,     2,     2,     2,     5,     5,     5,     5,     1,     1,
       3,     3,     4,     6,     6,     1,     1,     3,     3,     9,
       7,     1,     5,     3,     6,     1,     3,     1,     1,     3,
       6,     1,     1,     4,     6,     6,     4,     4,     8,     4,
       4,     4,     6,     6,     1,     3
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
       0,     0,     0,     0,   212,     0,   217,     0,     0,     0,
     214,     0,     0,     0,     0,   296,   297,   298,     0,     5,
       7,     6,     8,     9,    10,    19,    11,    12,    13,    18,
      17,    14,    15,    16,     0,    20,   365,   372,   441,    57,
     366,   367,   368,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   442,     0,     0,     0,     0,   369,   370,
     371,    61,    60,    59,    58,     0,     0,     0,    63,    62,
       0,     0,     0,     0,   166,     0,     0,     0,   303,     0,
       0,     0,     0,     0,   200,     0,   202,   199,   203,   204,
      95,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   205,     0,
       0,     0,     0,     0,     0,     0,   124,   137,   149,   154,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   386,     0,     0,     0,     0,     0,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   166,     0,   293,     0,     0,     0,     0,     0,     0,
       0,   372,   404,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   418,   419,   397,   403,     0,   398,     0,     0,
       0,     0,   431,     0,     0,     0,     0,     0,   197,   198,
       0,     0,   213,     0,   166,     0,   166,   372,     0,   299,
       0,     0,     0,     0,     0,     0,   376,    32,   441,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,   305,   307,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
       0,   164,     0,    72,   194,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     191,   141,     0,     0,     0,     0,    93,    93,     0,     0,
     425,   426,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   272,   272,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   388,   387,     0,     0,
       0,     0,   166,   166,     0,     0,     0,     0,     0,     0,
       0,   227,     0,   166,     0,     0,     0,     0,     0,   274,
       0,     0,     0,     0,   184,     0,     0,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   410,
       0,   411,   412,   413,     0,     0,     0,     0,     0,   305,
     405,     0,   399,     0,     0,     0,   280,   196,     0,     0,
       0,     0,     0,   166,     0,     0,     0,     0,   215,   187,
       0,   188,     0,     0,   207,     0,     0,     0,     0,   378,
       0,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   438,   454,   437,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   304,    57,     0,     0,     0,    57,     0,
       0,     0,     0,     0,   161,     0,     0,     0,     0,   167,
      66,     0,   321,   320,   319,   318,   314,   315,   317,   316,
     309,   308,   310,   311,   312,   313,   142,     0,     0,     0,
       0,     0,     0,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,   390,   389,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   221,     0,
       0,     0,     0,     0,     0,     0,   283,     0,     0,   185,
       0,     0,   181,     0,     0,     0,   292,   291,     0,     0,
     421,     0,   420,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   304,   400,   407,     0,   310,   406,     0,     0,
       0,     0,     0,     0,     0,     0,   216,     0,   189,   190,
       0,     0,     0,     0,   374,   380,     0,    42,     0,     0,
       0,    55,     0,    33,    34,    35,    36,    37,   323,   344,
     324,   345,   325,   346,   326,   347,   327,   348,   328,   349,
     329,   350,   330,   351,   331,   352,   343,   364,   332,   353,
       0,     0,   334,   355,   335,   356,   336,   357,   337,   358,
     338,   359,   339,   360,     0,     0,     0,     0,     0,     0,
       0,     0,   449,     0,   450,     0,   451,     0,     0,   446,
     447,     0,     0,     0,   385,    85,     0,   443,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       0,     0,     0,   375,     0,     0,     0,     0,     0,    23,
      21,     0,     0,    24,     0,     0,    64,    96,    65,   104,
       0,   427,   428,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,   273,   271,     0,   279,     0,     0,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,     0,   218,     0,
       0,     0,     0,     0,     0,   275,   282,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   374,   422,
     409,     0,     0,     0,     0,   401,     0,     0,     0,     0,
       0,     0,     0,   186,     0,     0,     0,     0,     0,     0,
     300,     0,     0,   377,     0,   373,     0,     0,     0,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   439,   455,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,     0,     0,     0,     0,     0,    73,
      75,    77,     0,     0,   435,     0,    83,     0,     0,     0,
       0,   322,    22,     0,     0,     0,     0,     0,     0,     0,
     121,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,     0,     0,     0,     0,     0,     0,     0,
     277,     0,     0,     0,     0,     0,     0,     0,     0,   285,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   261,     0,     0,   262,     0,   264,     0,   228,   257,
       0,     0,     0,   179,     0,     0,     0,   284,     0,   183,
     182,   295,     0,     0,    30,    31,     0,     0,   414,   415,
     416,   417,   408,   402,     0,     0,     0,   432,     0,     0,
       0,   208,     0,     0,     0,     0,   193,   379,   192,     0,
       0,     0,     0,   395,     0,   333,   354,   340,   361,   341,
     362,   342,   363,     0,   452,   453,   445,     0,   383,   384,
     382,   444,     0,    69,     0,    57,     0,     0,     0,     0,
      68,     0,     0,     0,   433,     0,     0,     0,     0,    25,
      26,     0,    27,     0,     0,    97,   100,   123,     0,     0,
       0,     0,     0,   127,     0,     0,   144,   145,     0,     0,
     129,   152,     0,     0,     0,     0,   119,     0,   276,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   195,     0,
       0,     0,     0,   166,   166,     0,   238,     0,   240,     0,
     242,     0,   397,     0,     0,   263,   265,     0,     0,   222,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   281,
     424,   423,   132,   133,     0,     0,     0,     0,    86,    90,
       0,     0,   301,   381,     0,    38,     0,     0,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,    80,     0,
       0,    81,     0,   436,   168,   169,   170,   171,     0,     0,
      98,   101,     0,   122,   130,   131,   135,     0,     0,   146,
       0,     0,   278,     0,   139,     0,     0,   269,   151,     0,
       0,     0,     0,   136,     0,   147,   153,     0,     0,     0,
       0,   394,     0,   393,     0,     0,     0,   229,     0,     0,
     230,     0,     0,   231,     0,     0,     0,     0,     0,     0,
       0,   178,     0,     0,   177,     0,     0,     0,   172,     0,
       0,     0,     0,   430,     0,   210,   209,     0,     0,     0,
       0,    43,     0,     0,     0,   396,     0,     0,     0,   440,
     448,    71,    70,    76,    78,     0,    84,     0,    28,     0,
     107,   112,     0,     0,     0,     0,     0,     0,     0,   140,
     125,   138,   150,   155,     0,     0,    91,    92,   166,     0,
     159,   160,     0,     0,     0,     0,     0,     0,     0,   258,
       0,     0,   166,     0,     0,     0,     0,     0,   163,   162,
       0,     0,     0,     0,    87,    88,     0,     0,    39,     0,
       0,     0,    41,    56,     0,   434,     0,     0,     0,   287,
     288,   289,   290,   143,     0,     0,     0,     0,     0,     0,
     392,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     267,     0,     0,     0,   223,     0,     0,   173,     0,     0,
       0,   429,   211,     0,   302,     0,     0,     0,     0,    82,
       0,     0,    99,   108,     0,   102,   113,     0,     0,     0,
       0,   157,     0,   244,     0,     0,   246,     0,     0,   248,
       0,     0,     0,   259,     0,   219,     0,   166,     0,     0,
       0,   134,    89,     0,    47,     0,    53,     0,     0,     0,
       0,     0,   120,   148,   286,   391,   232,     0,     0,   239,
     233,     0,     0,   241,   234,     0,     0,   243,     0,     0,
       0,   225,     0,   176,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   111,     0,   114,   115,     0,     0,   250,
       0,   252,     0,   254,   260,   266,   224,   220,     0,     0,
       0,     0,    44,     0,    51,     0,     0,     0,   425,     0,
       0,     0,   235,     0,     0,   236,     0,     0,   237,     0,
       0,   180,     0,   174,     0,    45,     0,     0,   201,     0,
     110,     0,   116,     0,     0,     0,     0,     0,     0,     0,
     226,     0,     0,     0,     0,     0,     0,   105,   206,   245,
       0,   247,     0,   249,     0,   175,    46,    48,     0,    49,
       0,     0,     0,     0,     0,     0,     0,    54,   106,   251,
     253,   255,    50,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    79,   821,    80,    81,   511,  1204,  1210,
     733,   936,  1367,  1534,   734,  1487,  1568,   735,  1536,   736,
     737,   940,   155,   286,    82,   614,   386,  1320,  1321,   387,
    1517,  1377,  1423,  1378,  1426,   857,  1246,  1130,   589,   414,
     415,   416,   417,   252,   360,   361,    85,    86,    87,    88,
      89,    90,   253,   889,  1446,  1508,   666,  1268,  1271,  1274,
    1467,  1471,  1475,  1523,  1526,  1529,   885,   886,  1009,   854,
     640,   675,    92,    93,    94,    95,   254,   158,   427,   213,
    1082,   255,   256,   257,   483,   264,   812,   975,   556,   557,
     558
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1166
static const yytype_int16 yypact[] =
{
    4646,    46,    12,  4738, -1166, -1166,  2325,    45,   -37,   -66,
     -47,     9,   112,   120,   147,   173,   -33,   -25,  -124,   -19,
      48,     2,    73,    94,    10,   115,   135,   137,   286,   311,
     338,   235,   361,   365,   501,   372,   295,   543,    42,   283,
     393,   305,   194,   194,   320,   -17,    36,    90,   441,   435,
       7,    43,   461,   468,   161,   563,   584,  2491,   599,   410,
     443,   448,    24,     6, -1166,   449, -1166,   527,   611,   457,
   -1166,   632,   637,    14,    30, -1166, -1166, -1166,  4313, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166,    40, -1166, -1166,     1,   456,   356,
   -1166, -1166, -1166,    81,   136,   282,   395,   407,   428,   455,
     471,   483,   487,   530,   531,   542,   567,   568,   577,   602,
     603,   617,   620,   621,   472,   631,   486,   492,   497,   504,
     507,   510,   514, -1166,   683,   535,   539,   545, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166,  4313,  4313,  4313, -1166, -1166,
    3906,   851,    23,   714,   206,  2811,   726,   692, -1166,   731,
     735,  4313,   742,   764, -1166,  4313, -1166, -1166, -1166, -1166,
   -1166, -1166,  4313,  4115,  4313,  4313,   612,  4313,  4115,  4313,
    4313,   613,  4115,  4313,  4313,  2811,   648,   625, -1166,  4115,
     653,   659,  2491,  2491,  2491,   660, -1166, -1166, -1166, -1166,
     670,   702,   703,  2811,  4313,   820,  2811,   194,   194,   194,
    4313,  4313,   101, -1166,   223,   194,   685,   734,   737,  4066,
     250,   -49,   727,   738,   745,  2491,  2491,  2811,   752,    18,
     757, -1166,   918, -1166,   753,   760,   763,  2491,  2491,   777,
     783,   554, -1166,   784,    31,   972,   975,   978,   569,  2971,
    4313,  1985, -1166, -1166,  4388, -1166,   962, -1166,   984,  4313,
    4313,  4313,   835,  4313,   833,   889,  4313,  4313, -1166, -1166,
    4313,  1007, -1166,  1012, -1166,  1016, -1166,   800,  1444, -1166,
    2811,  2811,   868,  4313,  1028,   872, -1166, -1166, -1166,  1030,
    4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,
    4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,
    4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,
    4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,
    4313,  4313,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,  4313,   557,   557,   557,   886,   886,   886,  4115,
    7082,   110,  4115,  6323,    87,   890,  1051,   938,   896, -1166,
     928,  3901,  1059, -1166, -1166,  4313,  4313,  4313,  4313,  4313,
    4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,  4313,
   -1166, -1166,  1542,  -133,    71,  5595,  -100,   240,  7103,  4115,
    4407, -1166,   266,  7124,  7145,  4313,  7166,   374,  7187,  7208,
    4313,   601,  7229,  7250,  1102,  4313,  4313,   630,  4313,  4313,
    1103,  1107,  1107,  4313,   959,   964,   965,   968,  4313,  4313,
    4313,  1117,  5515,   966,  1126,   -61, -1166, -1166,  5621,  5647,
     194,   194,   206,   206,    62,  4313,  4313,  4313,  4066,  4066,
    4313,  3901,   106, -1166,  4313,  4313,  4313,  4313,  4313,  1127,
    1131,  1133,  4313,  1136, -1166,  4313,  4313,  1600, -1166,  4115,
    4115,  4115,  1137,  1138,  4313,  4313,  -114,  3862,  1129, -1166,
    4313, -1166, -1166, -1166,   979,   980,   981,   983,  4115,   886,
   -1166,  7271, -1166,   633,  4313,  3131, -1166, -1166,  7292,  7313,
    7334,  1039,  5673, -1166,   987,  4426,  7355,  6346, -1166, -1166,
    1829, -1166,  2025,  4313, -1166,   994,   636,  4313,  6369,   234,
    4313,     5, -1166,  7376,  6392,  7397,  6415,  7418,  6438,  7439,
    6461,  7460,  6484,  7481,  6507,  7502,  6530,  7523,  6553,  7544,
    6576,  7565,  6599,  7586,  6622,  5699,  5725,  7607,  6645,  7628,
    6668,  7649,  6691,  7670,  6714,  7691,  6737,  7712,  6760,  5751,
    5777,  5803,  5829,  5855,  5881,   643, -1166, -1166,   337,    92,
     349,   990,   997,   998,   995,   996,  1006,   118,  1819,  1010,
     999,  1011,   663,   110, -1166,  2811,   681,    78,   356,  4313,
    1158,  1161,    28,  1015, -1166,    63,    19,    29,   132, -1166,
   -1166,  4445,  1626,  1055,   529,   529,    -5,    -5,    -5,    -5,
     -98,   -98,   886,   886,   886,   886, -1166,    20,  4115,  1168,
    4115,  4313,  1174, -1166,  1177,  1178,   557,  1179,  4115,  4115,
    1071,  1181,  1183,  7733,  1184,  1077,  1188,  1190,  7754,  1082,
    1205,  1209,  4313,  7775,  4815,  1052,  7796,  7817,  4313,  2811,
    1215,  1216,  7838,  4269,  4269,  4269,  4269,  7859,  7880,  7901,
    2811,  4115,  1056, -1166,   194,  4313,  4313, -1166, -1166,  1054,
    1057,  4066,  5907,  5933,  5959,  5569,   271,   194,  2529,  7922,
    4843,  7943,  7964,  7985,  4313,  1218, -1166,  4313,  8006, -1166,
    6783,  6806, -1166,   682,   689,   720, -1166, -1166,  6829,  6852,
   -1166,  4115, -1166,  4115,  6875,  1064,  4871,  4115,  4115,  4115,
    4115,   724, -1166, -1166,  4464,  4115,   886, -1166,  1223,  1224,
    1225,  1068,  4313,  2689,  4313,  4313, -1166,     0, -1166, -1166,
    1066,  2811,  1229,  6898,    82, -1166,  4899, -1166,  1076,  1078,
    1070, -1166,  1236, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
    4313,  4313, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166,  4313,  4313,  4313,  4313,  4313,  4313,
    4313,  1239, -1166,   557, -1166,  4115, -1166,  4115,   557, -1166,
   -1166,   557,   557,   557, -1166, -1166,  4313, -1166,   557,  1084,
    4313,  1241,  1089,    26,  4313,  1242,  1248,  2110, -1166,  1249,
    1092,    24,  1251, -1166,  4115,  4115,  4115,  4115,  4313, -1166,
    1110,   557,   124, -1166,   272,  5985, -1166,  1252, -1166, -1166,
     194,  4407, -1166,  1199,  2811,  2811,  1255,  2811,   836,  2811,
    2811,  1256,  1200,  2811,  2811,  2260,  1258,  1259,  4115,  1260,
    1261,  4524, -1166, -1166,  1263, -1166,  1265,  1108,  8237, -1166,
    1112,  1113,  1114,  1270,  1271,  1272,  1274,   765,  1277,   261,
    6011,  6037, -1166, -1166,  4927,   -92,   194,   194,   194,  1278,
    1279,  1116,  1128,    15,    32,   269, -1166,   270, -1166,   271,
    1280,  1286,  1287,  1288,  1289,  8237, -1166,  2285,  1132,  1291,
    1293,  1296,  1244,  4313,  1298,  1301,   772,   776,   267, -1166,
   -1166,   793,   797,   805,   806, -1166,  4313,   809,  2811,  2811,
    2811,  1305,  6063, -1166,  4489,  1344,  1306,  1308,  2811,  1145,
   -1166,  1309,  1312, -1166,  1311, -1166,  1159,  4313,  4313,  2811,
    1151, -1166,  8027,  6921,  8048,  6944,  8069,  6967,  8090,  6990,
    7013, -1166, -1166,   312,   359,  1160,  1154,  1163,  1164,  8111,
    1165,   110,  3082, -1166,   110,   125,  1166,  1321,  3103, -1166,
   -1166, -1166,    24,  4313, -1166,   822, -1166,   826,   827,   837,
     841,  8237, -1166,  1323,    25,  1326,  4313,  3611,    55,  1167,
    1262,  1262,  2811,  1328,  1169,  1172,  1335,  1336,  2811,  1176,
    1339,  1341, -1166,  1346,  2811,   842,  2811,  2811,  1350,  1352,
   -1166,  2811,  1349,  1353,  1354,  1355,  2811,  2811,  2811, -1166,
    1356,   408,  4313,  4313,  4313,  1191,  1197,  -101,   -54,   -24,
    1203, -1166,  2811,  4313, -1166,  1362, -1166,  1363, -1166, -1166,
    4066,   564,  2651, -1166,  1202,  1204,  3291, -1166,  4115, -1166,
   -1166, -1166,  1207,  3254, -1166, -1166,  1211,  1212, -1166, -1166,
   -1166, -1166,  8237, -1166,  1371,  1373,  1273, -1166,  4313,  4313,
    4313, -1166,  1376,   505,  1217,  1377, -1166,   234, -1166,  4313,
    6089,  6115,   847, -1166,  4313, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166,  1221, -1166, -1166, -1166,   557, -1166, -1166,
   -1166, -1166,  2811, -1166,  2811,   356,  4313,  1383,  1386,    28,
   -1166,  1385,  7036,    24, -1166,  1391,  1392,  1393,  1395, -1166,
   -1166,   557, -1166,  6141,  4269,  8237, -1166, -1166,  4313,   194,
    1397,  1399,  1401, -1166,  4313,  4313, -1166, -1166,  1405,  4313,
   -1166, -1166,  1387,  1407,  1247,  1410,  1302,  4313, -1166,  1414,
    2811,  2811,  2811,  2811,  1415,   963,  1416,  4313, -1166,  4269,
    4955,  8132,  4731,   206,   206,   194,  1417,   194,  1418,   194,
    1419,  4313,   432,  1264,  8153, -1166, -1166,  4983,   310, -1166,
    1422,  1789,  1423,  2811,   194,  1789,  1424,   854,  4313, -1166,
   -1166, -1166, -1166, -1166,  2811,  4759,   607,  8174, -1166, -1166,
    3658,  2811, -1166, -1166,   335,  8237,  4313,  4313,  2811,  1267,
     858,  8237,  1428,  1275,  1427,  1433,  1434,  3404, -1166,  1435,
    1437, -1166,  1276, -1166, -1166, -1166, -1166, -1166,  1438,  4313,
    8237, -1166,  5011,   442, -1166, -1166, -1166,  5039,  5067, -1166,
    5095,  1441, -1166,  2811, -1166,  1389,  1446,  8237, -1166,  1450,
    1451,  1452,  1454, -1166,  1294, -1166, -1166,  5542,  3423,  1457,
    1297, -1166,  4313, -1166,  1295,  1299,   313, -1166,  1304,   317,
   -1166,  1307,   341, -1166,  1310,  7059,  1461,  2811,  1440,  1313,
    4313, -1166,  3451,   348, -1166,   861,   355,   358, -1166,  1464,
    5123,  1365,  4313, -1166,  4313, -1166, -1166,  4115,  3574,  1467,
    1331, -1166,  4313,  6167,  6193, -1166,  2811,  4313,  1468, -1166,
   -1166, -1166, -1166, -1166, -1166,    24, -1166,  1366, -1166,  6219,
   -1166, -1166,  1471,  1473,  1495,  1497,  1499,   880,  1343, -1166,
   -1166, -1166, -1166, -1166,  2811,  4115, -1166, -1166,   206,  4787,
   -1166, -1166,  4066,   271,  4066,   271,  4066,   271,  1501, -1166,
     883,  2811, -1166,  5151,   194,  1503,  4115,   194, -1166, -1166,
    4313,  5179,  5207,   901, -1166, -1166,  1506,  1345,  8237,  4313,
    4313,   902,  8237, -1166,  1508, -1166,  4313,   905,   908, -1166,
   -1166, -1166, -1166, -1166,  1348,  4313,   909,   915,  1351,  4313,
   -1166,  5235,   380,   574,  5263,   385,   717,  5291,   388,   723,
   -1166,  2811,  1511,  1445,  2849,  1357,   397, -1166,   916,   399,
    4218, -1166, -1166,  1512, -1166,  4313,  8195,  6245,    37, -1166,
    6271,  1515, -1166, -1166,  1518, -1166, -1166,  4313,  5319,  1521,
    1522, -1166,  5347,  1523,  4313,  1524,  1525,  4313,  1526,  1528,
    4313,  1530,  1368, -1166,  4313, -1166,   271, -1166,  4115,  1532,
    3451, -1166, -1166,   919, -1166,  4313, -1166,  2811,  4313,  2158,
    3818,  6297, -1166, -1166, -1166, -1166, -1166,  1375,  5375, -1166,
   -1166,  1378,  5403, -1166, -1166,  1379,  5431, -1166,  1533,  4240,
     816,  3009,   920, -1166,   402,   924,  1535,  1381,  8216,   925,
    5459,  1985, -1166, -1166,   557,  8237, -1166,  4313,   271,  1539,
     271,  1545,   271,  1548, -1166, -1166, -1166, -1166,   271,  1549,
    4115,  1550, -1166,   557, -1166,  1390,  1554,   929,  4341,   935,
    5487,   823, -1166,  1394,   830, -1166,  1396,   855, -1166,  1398,
     857, -1166,   936, -1166,   939, -1166,  1400,  2811, -1166,  4313,
   -1166,   356, -1166,  1555,  1557,   271,  1561,   271,  1563,   271,
   -1166,  1564,   557,  1565,   557,   946,  4367, -1166, -1166, -1166,
     942, -1166,   961, -1166,   967, -1166, -1166, -1166,   952, -1166,
    1566,   356,  1567,  1568,  1570,   557,  1571, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1166, -1166, -1166, -1166,   540, -1166, -1166, -1166, -1166,   163,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166,  -338,    -4, -1166,  1192, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166,  -562, -1166,   589,  1578, -1166,
   -1166, -1166, -1166,    50,  -429,  -211, -1166, -1166, -1166, -1166,
   -1166, -1166,  1579, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166,  -801,  -785, -1166, -1166,
    1171, -1166, -1166, -1166, -1166, -1166,    11, -1166,    60, -1166,
   -1165,   332,   216,   934,   949,  -770,   475, -1166,  -264,    -6,
    -340
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     159,   567,   156,   659,   660,   282,   176,   926,   441,   727,
     265,   229,     5,   575,   181,   164,   579,   157,  1285,   273,
     457,  1034,   453,   176,   454,   161,   819,   354,   262,   607,
     965,  1120,   810,   181,   608,   275,   469,   172,  1036,   216,
     221,   974,   217,  1456,   173,   218,   279,   232,   690,   233,
     430,   431,     4,    84,   691,   376,   377,   378,   160,   430,
     431,  1127,   379,   500,   612,   502,  1165,   613,  1166,   559,
     560,   561,   562,   563,   564,   565,   566,  1026,  1327,   569,
     570,   571,   860,   861,   862,   574,   555,   288,  1041,   278,
     430,   431,   222,   289,   578,   162,   223,   430,   431,   234,
    1039,   203,   212,   214,   204,   220,   654,   224,   728,   729,
     730,   731,   444,  1167,   163,  1168,  1035,   574,   166,   445,
     124,   125,   126,   127,   128,   129,   167,   430,   431,   230,
     170,   133,  1105,  1037,   208,   209,   355,   356,   171,   966,
     967,  1371,   174,  1169,   210,  1170,   374,   375,   376,   377,
     378,   219,   225,   168,   226,   379,   346,   347,   348,   148,
     149,   350,   353,   177,   283,   927,   284,   266,   820,  1386,
     178,   285,   382,   820,   732,   231,   385,   165,   182,   169,
     177,   455,   274,   388,   390,   393,   394,   815,   396,   390,
     398,   399,   263,   390,   402,   403,   811,   816,   276,   470,
     390,   280,  1111,   185,   359,  1457,   430,   431,   281,   175,
     358,   136,   137,   430,   431,   422,   141,   142,   143,   144,
     237,   428,   429,   238,   172,   141,   142,   143,   144,   661,
     429,   814,   668,   609,   179,   800,   148,   149,   610,   804,
     148,   149,   290,   803,   291,   148,   149,   932,   141,   142,
     143,   144,   430,   431,   784,   180,  1039,   430,   431,   785,
     479,   481,   390,   141,   142,   143,   144,   425,   426,   432,
     488,   489,   490,   667,   492,   434,   183,   495,   496,   442,
     794,   497,   713,   148,   149,   783,   984,    41,    42,    43,
      44,   619,  1489,   184,   508,    49,   184,   292,    52,   293,
     817,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,  1223,   188,   208,   209,   879,   186,   879,
     580,   196,   829,   568,   197,   210,   880,   198,   880,   199,
     390,   288,   211,   390,   881,   882,   881,   882,   883,   884,
     883,   884,  1555,   187,   430,   431,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   433,   148,   149,   124,   125,   126,   127,   128,   129,
     479,   430,   431,   189,   615,   133,   623,   613,   410,   411,
     412,   628,   430,   431,  1158,  1159,   633,   634,   443,   636,
     637,   430,   431,   190,   642,   148,   149,   191,  1022,   647,
     648,   649,   932,   619,   985,   620,   195,  1040,  1038,   619,
     484,   449,   450,   294,   205,   295,   662,   663,   664,   346,
     347,   665,   206,   462,   463,   669,   670,   671,   672,   673,
     934,   430,   431,   678,   430,   431,   680,   681,   430,   431,
     390,   390,   390,   207,  1094,   688,   689,  1280,   694,   619,
    1342,   696,   359,   359,  1344,   136,   137,   362,   215,   390,
     657,   658,   430,   431,   228,   704,   706,  1301,   426,   430,
     431,   782,  1302,   227,   783,   725,   430,   431,  1346,   430,
     431,  1199,  1200,   786,   694,  1354,   787,   404,   723,   952,
     235,   726,  1356,  1095,   955,  1357,   619,   956,   957,   958,
     236,   430,   431,   268,   960,   421,   430,   431,   424,   430,
     431,   619,  1393,   625,  1396,  1374,  1399,  1434,   430,   431,
     430,   431,  1437,   430,   431,  1440,   296,   983,   297,   451,
     192,   555,   288,   193,  1448,   194,  1450,   239,   298,  1510,
     299,   259,   806,   805,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   485,   377,   378,   240,   300,
     807,   301,   379,   430,   431,   124,   125,   126,   127,   128,
     129,  1276,   200,   258,   260,   201,   133,   202,  1039,   261,
     267,  1039,   505,   506,  1039,  1294,   302,   269,   303,   390,
     270,   390,   825,  1102,   287,   474,  1104,  1106,   475,   706,
     831,   476,   304,   477,   305,   332,   271,   859,   859,   859,
     859,   272,   879,   845,   306,  1480,   307,   335,   308,   851,
     309,   880,   879,   336,   858,   858,   858,   858,   337,   881,
     882,   880,   390,   883,   884,   338,   870,   871,   339,   881,
     882,   340,   874,   883,   884,   341,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   895,   136,   137,   897,   379,
     342,   310,   312,   311,   313,  1039,   343,  1521,   364,  1524,
     344,  1527,   390,   314,   390,   315,   345,  1530,   390,   390,
     390,   390,   148,   149,   869,   466,   390,   467,   357,   284,
     933,   875,   154,   922,   285,   924,   925,   887,   316,   318,
     317,   319,   363,  1179,  1264,  1265,  1039,   380,   320,  1039,
     321,   381,  1039,  1435,  1560,  1039,  1562,   383,  1564,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   322,   324,   323,   325,   379,   619,   384,
     629,   942,   943,   395,   400,  1039,  1295,  1039,   326,  1039,
     327,   328,   330,   329,   331,   944,   945,   946,   947,   948,
     949,   950,   333,   406,   334,   879,   390,   619,   390,   635,
     619,   879,   703,   721,   880,   722,   780,   959,   781,   405,
     880,   962,   881,   882,   408,   968,   883,   884,   881,   882,
     409,   413,   883,   884,   423,   390,   390,   390,   390,   981,
     619,   418,   799,  1213,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   619,   619,
     802,   901,   379,   435,    96,   277,   619,  1228,   902,   390,
     100,   101,   102,   419,   420,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,  1438,   619,   446,   903,
     988,   619,  1441,   915,   879,   130,   131,   132,   994,   447,
     995,   879,   436,   880,   933,   437,   448,   801,   879,  1388,
     880,   881,   882,   452,  1053,   883,   884,   880,   881,   882,
     456,   459,   883,   884,   458,   881,   882,  1062,   460,   883,
     884,   461,   619,   879,  1020,   879,  1027,  1028,  1029,   619,
     464,  1056,   880,   619,   880,  1057,   465,   468,  1080,  1081,
     881,   882,   881,   882,   883,   884,   883,   884,   148,   149,
     619,  1107,  1058,   503,   619,   284,  1059,  1254,   486,  1255,
     285,   852,   619,   619,  1060,  1061,   619,   471,  1063,   135,
     472,  1126,   866,   473,  1112,  1506,   138,   139,   140,  1113,
     487,  1114,  1544,   619,   619,  1115,  1116,  1123,  1125,  1546,
     491,   493,   145,   146,   619,   494,  1117,   147,   619,   619,
    1118,  1144,   250,   498,  1208,   351,  1209,   153,   499,   352,
     879,   619,   501,  1289,  1548,  1307,  1550,  1308,  1208,   880,
    1355,   507,   509,  1160,  1161,  1162,   512,   881,   882,   879,
     510,   883,   884,  1172,  1174,   879,   379,  1208,   880,  1384,
    1401,  1177,  1402,   929,   880,   581,   881,   882,   582,   390,
     883,   884,   881,   882,   154,   590,   883,   884,   619,  1208,
    1413,  1418,  1421,  1203,  1422,  1424,  1208,  1425,  1429,  1195,
    1196,  1197,   619,   619,  1430,  1449,  1307,   619,  1486,  1509,
    1205,   619,  1208,  1511,  1515,  1211,  1539,   584,  1540,  1216,
    1178,   583,   783,   619,  1542,  1551,  1552,   391,  1553,   632,
     638,  1572,   391,  1208,   639,  1570,   391,  1217,  1231,  1575,
     643,  1576,   392,   391,   650,   644,   645,   397,   652,   646,
    1573,   401,   653,   695,   674,  1230,  1574,   676,   407,  1232,
     677,  1404,   679,   686,   687,  1237,  1238,   697,   698,   699,
    1240,   700,   711,  1259,  1519,   714,   720,   788,  1247,   789,
     790,   797,   791,   792,   808,   809,   990,   991,  1257,   993,
    1258,   996,   997,   793,   823,  1000,  1001,   796,   798,   813,
     826,   827,  1275,   480,   828,   391,   830,   833,   834,  1233,
     835,   837,   390,   838,  1299,   839,   390,   840,   842,  1290,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,  1298,   843,   359,   359,   379,   844,  1303,  1304,   853,
     848,   868,   855,   872,   896,  1266,   873,  1269,   909,  1272,
     918,   919,   920,   921,   928,   930,  1481,   937,   939,   938,
    1319,  1283,   941,   951,  1286,  1287,   961,   963,   969,  1535,
    1064,  1065,  1066,   964,   970,   973,   972,   976,   982,   987,
    1074,   989,   992,   998,   999,  1003,  1004,  1006,  1007,  1010,
    1012,  1083,  1011,  1339,  1013,  1014,  1015,  1016,  1017,  1018,
    1019,  1021,  1030,   391,  1032,  1031,   391,  1042,  1566,  1033,
    1569,  1353,  1043,   479,  1044,  1045,  1046,  1049,   572,  1050,
    1048,   576,  1051,  1361,  1054,  1362,  1052,  1055,   390,  1067,
    1072,  1582,  1073,  1368,  1075,  1076,  1077,  1078,  1372,  1084,
    1079,  1097,  1096,   480,  1132,  1098,  1099,  1101,  1109,  1119,
    1138,  1108,  1122,  1129,  1133,  1128,  1143,  1134,  1145,  1146,
    1135,  1136,  1137,  1149,  1139,  1140,   390,  1141,  1154,  1155,
    1156,  1142,  1070,  1391,  1147,  1394,  1150,  1397,  1148,  1163,
    1151,  1152,  1153,  1157,  1173,  1164,  1171,   390,  1175,  1176,
    1183,  1410,  1184,  1190,  1182,  1188,  1191,  1192,  1186,  1193,
    1416,  1417,  1198,  1202,  1201,  1194,  1212,  1420,   359,  1218,
    1219,  1221,  1241,   391,   391,   391,  1428,  1224,  1225,  1226,
    1432,  1227,  1392,  1234,  1395,  1235,  1398,  1236,   683,   684,
     685,  1239,   391,  1242,  1406,  1243,  1244,  1409,  1245,   707,
    1248,  1253,  1256,  1267,  1270,  1273,  1211,   701,  1281,  1284,
    1288,  1277,  1309,  1311,  1214,  1306,  1215,  1310,  1461,  1312,
    1313,  1317,  1315,  1316,  1318,  1468,  1326,  1351,  1472,  1328,
     504,  1476,  1329,  1493,  1496,  1479,  1330,  1331,  1332,   390,
    1333,   390,  1334,  1337,  1340,  1338,  1488,  1349,  1341,  1490,
    1358,  1495,  1343,  1365,  1373,  1345,  1360,  1379,  1347,  1380,
    1375,  1352,  1249,  1250,  1251,  1252,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
    1366,  1381,  1518,  1382,   379,  1383,  1071,  1400,  1520,  1407,
    1484,  1385,  1414,  1415,  1419,  1083,  1427,  1443,  1452,  1459,
    1431,   390,  1460,  1444,  1121,  1447,  1291,  1463,  1464,  1466,
    1469,  1470,  1473,  1300,  1474,  1557,  1477,  1478,  1483,  1504,
    1305,  1512,   391,  1498,   391,  1522,  1500,  1502,   606,  1513,
    1556,  1525,   707,   832,  1528,  1531,  1533,   822,  1537,   824,
    1538,  1558,  1545,  1559,  1547,  1578,  1549,  1561,  1554,  1563,
    1565,  1567,  1577,  1579,  1580,  1083,  1581,  1583,  1453,   616,
    1131,    83,    91,   641,  1220,   391,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     867,     0,     0,     0,   379,     0,     0,     0,     0,  1350,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   391,     0,   391,     0,     0,
       0,   391,   391,   391,   391,     0,     0,     0,  1083,   391,
     906,     0,   907,     0,     0,     0,   911,   912,   913,   914,
       0,     0,     0,     0,   917,     0,   585,    19,    20,   586,
      22,    23,   587,    25,   588,    27,  1083,    28,     0,     0,
       0,    32,    33,     0,    35,    36,    37,     0,     0,     0,
      40,     0,     0,  1403,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,     0,     0,
       0,     0,   379,     0,     0,     0,     0,     0,    59,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     0,   391,
       0,   391,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1442,   953,     0,   954,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   391,   391,
     391,   391,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   977,   978,   979,   980,     0,     0,   682,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   391,     0,     0,     0,   379,     0,     0,  1083,
       0,  1492,    96,   241,     0,     0,     0,  1005,   100,   101,
     102,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   243,   795,     0,     0,     0,     0,
       0,     0,     0,   130,   131,   132,     0,     0,     0,     0,
       0,     7,     8,     0,     0,   244,     0,     0,   245,     0,
       0,   246,     0,   247,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,     0,     0,     0,     0,  1083,
      41,    42,    43,    44,    45,     0,     0,     0,    49,     0,
       0,    52,     0,     0,     0,   585,    19,    20,   586,    22,
      23,   587,    25,   588,    27,     0,    28,     0,     0,     0,
      32,    33,     0,    35,    36,    37,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,   135,     0,     0,
       0,     0,     0,     0,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,    60,    61,
     438,  1282,     0,     0,     0,   147,     0,     0,     0,     0,
     440,     0,     0,     0,     0,   153,     0,   211,   482,     0,
       0,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,   391,     0,     0,     0,     0,     0,    96,   241,
       0,     0,     0,     0,   100,   101,   102,  1187,   718,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     243,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,     0,     0,     0,     0,     0,     7,     8,     0,
       0,   244,     0,     0,   245,     0,     0,   246,     0,   247,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,     0,     0,     0,     0,     0,    41,    42,    43,    44,
      45,     0,     0,     0,    49,     0,     0,    52,     0,     0,
       0,   585,    19,    20,   586,    22,    23,   587,    25,   588,
      27,     0,    28,     0,     0,     0,    32,    33,     0,    35,
      36,    37,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,   135,     0,   391,   971,     0,     0,   391,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,    60,    61,   145,   389,     0,     0,
       0,   147,     0,     0,     0,     0,   250,     0,     0,     0,
       0,   153,     0,     0,   482,     0,     0,     0,     0,     0,
       0,    96,   241,   288,     0,     0,     0,   100,   101,   102,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   243,   719,     0,   124,   125,   126,   127,
     128,   129,   130,   131,   132,     0,     0,   133,     0,     0,
       0,     0,     0,     0,   244,     0,   480,   245,     0,     0,
     246,     0,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   391,     0,   248,     0,     0,     0,     0,     0,    41,
      42,    43,    44,    45,     0,     0,  1363,    49,     0,     0,
      52,     0,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,  1002,     0,     0,   391,
     379,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1387,     0,   135,   136,   137,     0,
     391,  1047,     0,   138,   139,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1408,     0,     0,     0,   145,
     249,     0,     0,     0,   147,     0,     0,     0,     0,   250,
       0,     0,     0,     0,   153,     0,  1491,     0,    96,    97,
      98,     0,    99,     0,   100,   101,   102,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
       0,     0,     0,   124,   125,   126,   127,   128,   129,   130,
     131,   132,     0,     0,   133,     0,     0,     0,     0,     0,
       0,     0,   391,     0,   391,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1482,     0,  1485,
       0,     0,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,     0,     0,     0,     0,
     379,     0,     0,     0,     0,   391,     0,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,   391,   379,     0,   134,     0,     0,
       0,     0,     0,   135,   136,   137,     0,     0,     0,  1532,
     138,   139,   140,   141,   142,   143,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   146,     0,     0,
       0,   147,     0,   148,   149,     0,   150,     0,   151,     0,
     152,   153,     0,   154,    96,   241,   242,     0,     0,     0,
     100,   101,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   243,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,     0,     0,
       0,     7,     8,     0,     0,     0,     0,   244,     0,     0,
     245,     0,     0,   246,     0,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,     0,     0,     0,
       0,     0,    41,    42,    43,    44,    45,     0,     0,     0,
      49,     0,     0,    52,     0,   585,    19,    20,   586,    22,
      23,   587,    25,   588,    27,     0,    28,     0,     0,     0,
      32,    33,     0,    35,    36,    37,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
       0,     0,     0,     0,     0,     0,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,    59,    60,    61,
       0,     0,   145,   249,     0,     0,     0,   147,     0,     0,
       0,     0,   250,     0,    96,   241,  1180,   153,     0,   251,
     100,   101,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   243,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,   888,     0,
       0,     7,     8,     0,     0,     0,     0,   244,     0,     0,
     245,     0,     0,   246,     0,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,     0,     0,     0,
       0,     0,    41,    42,    43,    44,    45,     0,     0,     0,
      49,     0,     0,    52,     0,   585,    19,    20,   586,    22,
      23,   587,    25,   588,    27,     0,    28,     0,     0,     0,
      32,    33,     0,    35,    36,    37,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
       0,     0,     0,     0,     0,     0,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,    59,    60,    61,
       0,     0,   145,   249,     0,     0,     0,   147,     0,     0,
       0,     0,   250,     0,    96,   241,     0,   153,     0,  1181,
     100,   101,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   243,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,   923,     0,
       0,     7,     8,     0,     0,     0,     0,   244,     0,     0,
     245,     0,     0,   246,     0,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,     0,     0,     0,
       0,     0,    41,    42,    43,    44,    45,     0,     0,     0,
      49,     0,     0,    52,     0,   585,    19,    20,   586,    22,
      23,   587,    25,   588,    27,     0,    28,     0,     0,     0,
      32,    33,     0,    35,    36,    37,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
       0,     0,     0,     0,     0,     0,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,    59,    60,    61,
       0,     0,   145,   249,     0,     0,     0,   147,     0,     0,
       0,     0,   250,     0,    96,   241,     0,   153,     0,   251,
     100,   101,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   243,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,  1445,     0,
       0,     7,     8,     0,     0,     0,     0,   244,     0,     0,
     245,     0,     0,   246,     0,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,     0,     0,     0,
       0,     0,    41,    42,    43,    44,    45,     0,     0,     0,
      49,     0,     0,    52,     0,   585,    19,    20,   586,    22,
      23,   587,    25,   588,    27,     0,    28,     0,     0,     0,
      32,    33,     0,    35,    36,    37,     0,     0,  1103,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
       0,     0,     0,     0,     0,     0,   138,   139,   140,  1110,
       0,     0,     0,     0,     0,     0,     0,    59,    60,    61,
       0,     0,   145,   389,     0,     0,     0,   147,     0,     0,
       0,     0,   250,     0,    96,   241,     0,   153,     0,   478,
     100,   101,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   243,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,  1507,     0,
       0,     0,     0,     0,     0,     0,     0,   244,     0,     0,
     245,     0,     0,   246,     0,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,     0,     0,     0,
       0,     0,    41,    42,    43,    44,    45,     0,     0,     0,
      49,     0,     0,    52,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,     0,     0,
       0,     0,   379,     0,     0,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   135,
    1189,     0,     0,   379,     0,     0,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   389,     0,     0,     0,   147,     0,     0,
       0,     0,   250,     0,    96,   241,     0,   153,     0,   705,
     100,   101,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   243,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,     0,     0,
     245,     0,     0,   246,     0,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,     0,     0,     0,
       0,     0,    41,    42,    43,    44,    45,     0,     0,     0,
      49,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
    1314,     0,     0,     0,   379,     0,     0,     0,     0,   135,
       0,     0,     0,     0,     0,     0,   138,   139,   140,  1336,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   249,     0,     0,     0,   147,     0,     0,
       0,     0,   250,     0,    96,   241,     0,   153,     0,  1185,
     100,   101,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   243,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,     0,     0,
     245,     0,     0,   246,     0,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,     0,     0,     0,
       0,     0,    41,    42,    43,    44,    45,     0,     0,     0,
      49,     0,     0,    52,     0,     0,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,     0,     0,   379,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   135,
    1364,     0,     0,   379,     0,     0,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   438,  1282,     0,     0,     0,   147,     0,     0,
       0,     0,   440,     0,    96,   277,   288,   153,     0,   211,
     100,   101,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,     0,     0,     0,   124,
     125,   126,   127,   128,   129,   130,   131,   132,     0,     0,
     133,    96,   277,   288,     0,     0,     0,   100,   101,   102,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     0,     0,     0,   124,   125,   126,   127,
     128,   129,   130,   131,   132,     0,     0,   133,     0,     0,
       0,     0,     0,     0,     0,     0,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,     0,     0,   379,     0,     0,     0,     0,   135,
     136,   137,     0,     0,     0,     0,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   146,     0,     0,     0,   147,     0,     0,
       0,     0,   250,     0,     0,     0,     0,   153,     0,  1124,
       0,     0,     0,     0,     0,     0,   135,   136,   137,     0,
       0,     0,     0,   138,   139,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,     0,     0,     0,   147,     0,     0,     0,     0,   250,
       0,    96,   277,   288,   153,     0,  1297,   100,   101,   102,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     0,     0,     0,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    96,   277,   133,     0,     0,
       0,   100,   101,   102,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   131,   132,    96,
     277,     0,     0,     7,     8,   100,   101,   102,     0,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,   135,   136,   137,     0,
     130,   131,   132,   138,   139,   140,     0,   585,    19,    20,
     586,    22,    23,   587,    25,   588,    27,     0,    28,   145,
     146,     0,    32,    33,   147,    35,    36,    37,     0,   250,
       0,    40,     0,     0,   153,     0,  1494,     0,     0,     0,
     135,     0,     0,     0,     0,     0,     0,   138,   139,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
      60,    61,     0,   145,   146,     0,     0,     0,   147,     0,
       0,     0,     0,   250,     0,     0,   692,     0,   153,     0,
     693,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,   146,     0,
       0,     0,   147,     0,     0,     0,     0,   250,     0,    96,
     277,     0,   153,     0,   349,   100,   101,   102,     0,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,   132,     0,     0,     0,     0,     0,    96,   241,
       0,     0,     0,     0,   100,   101,   102,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     243,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,     0,     0,   245,     0,     0,   246,     0,   247,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,     0,     0,     0,   135,     0,    41,    42,    43,    44,
      45,   138,   139,   140,    49,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   438,   439,     0,
       0,     0,   147,     0,  1451,     0,     0,   440,     0,     0,
       0,     0,   153,     0,   211,     0,     0,     0,     0,     0,
       0,     0,     0,   135,     0,     0,  1505,     0,     0,     0,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   389,     0,     0,
       0,   147,    96,   277,   288,     0,   250,     0,   100,   101,
     102,   153,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,     0,     0,     0,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    96,   277,   133,     0,
       0,     0,   100,   101,   102,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,  1541,   484,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,  1571,     0,     0,     0,   379,     0,
       0,     0,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   484,   135,   136,   137,
     379,     0,     0,     0,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,   484,     0,     0,     0,     0,
     145,   146,     0,     0,     0,   147,     0,     0,     0,     0,
     250,     0,     0,     0,   715,   153,     0,     0,     0,     0,
       0,   135,     0,     0,     0,     0,     0,     0,   138,   139,
     140,     0,     0,   818,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   146,     0,     0,     0,   147,
       0,     0,   916,     0,   250,     0,     0,     0,     0,   153,
       0,     0,     0,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   618,   377,   378,  1069,     0,     0,
       0,   379,     0,     0,     0,     0,     0,     0,     0,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   485,   377,   378,     0,     0,     0,     0,   379,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     618,   377,   378,     0,     0,     0,     0,   379,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,     0,     0,     0,     0,   379,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,  1008,     0,     0,   379,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,     0,     0,   379,     0,     0,     0,     0,     0,
       0,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,    -4,     1,     0,   379,
      -4,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,     0,     0,     0,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,    -4,    -4,   379,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,     0,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     6,    -4,    -4,     0,     0,     0,    -4,     0,
       7,     8,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,
       0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     9,    10,     0,    -4,    -4,    -4,
      -4,     0,     0,     0,     0,    11,    12,     0,    13,    14,
      15,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     0,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,     0,     0,    55,    56,     0,     0,     0,
      57,     0,     0,     0,     0,    58,    59,    60,    61,     0,
       0,    62,     0,    63,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,     0,    75,
      76,    77,    78,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,     0,     0,     0,  1262,     0,
    1263,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,  1292,     0,  1293,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,  1389,     0,  1390,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,     0,
       0,     0,     0,     0,   847,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,     0,     0,     0,     0,     0,
       0,     0,   891,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,     0,     0,     0,     0,     0,
     910,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,     0,     0,   935,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,     0,     0,  1025,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,     0,
       0,     0,     0,     0,  1260,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,     0,     0,     0,     0,     0,
       0,     0,  1279,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,     0,     0,     0,     0,     0,
    1322,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,     0,     0,  1323,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,     0,     0,  1324,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,     0,
       0,     0,     0,     0,  1325,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,     0,     0,     0,     0,     0,
       0,     0,  1359,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,     0,     0,     0,     0,     0,
    1405,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,     0,     0,  1411,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,     0,     0,  1412,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,     0,
       0,     0,     0,     0,  1433,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,     0,     0,     0,     0,     0,
       0,     0,  1436,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,     0,     0,     0,     0,     0,
    1439,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,     0,     0,  1462,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,     0,     0,  1465,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,     0,
       0,     0,     0,     0,  1499,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,     0,     0,     0,     0,     0,
       0,     0,  1501,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,     0,     0,     0,     0,     0,
    1503,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,     0,     0,  1516,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,     0,     0,  1543,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,     0,
       0,     0,     0,   651,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,     0,     0,
       0,     0,   379,     0,     0,     0,     0,     0,     0,     0,
    1335,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,   702,     0,     0,     0,     0,   655,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,     0,
       0,     0,   611,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,     0,     0,     0,   655,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,   656,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,     0,     0,     0,     0,     0,
     712,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,   760,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,     0,
       0,     0,   761,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,     0,     0,     0,   774,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,   775,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,     0,     0,     0,     0,     0,
     776,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,   777,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,     0,
       0,     0,   778,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,     0,     0,     0,   779,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,   876,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,     0,     0,     0,     0,     0,
     877,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,   878,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,     0,
       0,     0,   986,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,     0,     0,     0,  1023,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,  1024,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,     0,     0,     0,     0,     0,
    1068,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,  1206,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,     0,
       0,     0,  1207,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,     0,     0,     0,  1229,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,  1369,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,     0,     0,     0,     0,     0,
    1370,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,  1376,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,     0,
       0,     0,  1455,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,     0,     0,     0,  1458,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,  1497,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,     0,     0,   577,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,     0,     0,     0,     0,   379,     0,     0,     0,
     717,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,   724,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,     0,     0,
       0,     0,   379,     0,     0,     0,   739,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,   741,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,     0,     0,     0,     0,   379,     0,
       0,     0,   743,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,   745,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,     0,     0,   379,     0,     0,     0,   747,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,   749,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,     0,     0,     0,     0,
     379,     0,     0,     0,   751,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,     0,     0,   753,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,     0,     0,     0,     0,   379,     0,     0,     0,
     755,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,   757,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,     0,     0,
       0,     0,   379,     0,     0,     0,   759,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,   763,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,     0,     0,     0,     0,   379,     0,
       0,     0,   765,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,   767,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,     0,     0,   379,     0,     0,     0,   769,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,   771,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,     0,     0,     0,     0,
     379,     0,     0,     0,   773,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,     0,     0,   899,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,     0,     0,     0,     0,   379,     0,     0,     0,
     900,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,   904,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,     0,     0,
       0,     0,   379,     0,     0,     0,   905,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,     0,     0,   908,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,     0,     0,     0,     0,   379,     0,
       0,     0,   931,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,     0,     0,  1086,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,     0,     0,   379,     0,     0,     0,  1088,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,     0,
       0,  1090,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,     0,     0,     0,     0,
     379,     0,     0,     0,  1092,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,     0,     0,  1093,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,     0,     0,     0,     0,   379,     0,     0,     0,
    1222,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,     0,     0,  1348,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,     0,     0,
       0,     0,   379,     0,   573,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,   617,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,     0,     0,   379,     0,   621,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,   622,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,     0,     0,     0,     0,   379,     0,   624,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,   626,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,     0,     0,     0,     0,   379,     0,
     627,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,   630,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,     0,     0,     0,     0,
     379,     0,   631,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,   702,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,     0,     0,
       0,     0,   379,     0,   708,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,   709,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,     0,     0,   379,     0,   710,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,   716,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,     0,     0,     0,     0,   379,     0,   738,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,   740,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,     0,     0,     0,     0,   379,     0,
     742,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,   744,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,     0,     0,     0,     0,
     379,     0,   746,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,   748,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,     0,     0,
       0,     0,   379,     0,   750,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,   752,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,     0,     0,   379,     0,   754,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,   756,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,     0,     0,     0,     0,   379,     0,   758,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,   762,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,     0,     0,     0,     0,   379,     0,
     764,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,   766,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,     0,     0,     0,     0,
     379,     0,   768,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,   770,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,     0,     0,
       0,     0,   379,     0,   772,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,   836,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,     0,     0,   379,     0,   841,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,   846,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,     0,     0,     0,     0,   379,     0,   849,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,   850,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,     0,     0,     0,     0,   379,     0,
     856,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,   863,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,     0,     0,     0,     0,
     379,     0,   864,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,   865,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,     0,     0,
       0,     0,   379,     0,   890,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,   892,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,     0,     0,   379,     0,   893,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,   894,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,     0,     0,     0,     0,   379,     0,   898,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379,     0,  1085,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,     0,     0,     0,     0,   379,     0,
    1087,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,     0,     0,     0,     0,   379,
       0,  1089,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,     0,     0,     0,     0,
     379,     0,  1091,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,     0,     0,     0,
       0,   379,     0,  1100,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,     0,     0,
       0,     0,   379,     0,  1261,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,     0,
       0,     0,     0,   379,     0,  1278,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,     0,     0,   379,     0,  1296,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,     0,     0,     0,     0,   379,     0,  1454,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,     0,     0,     0,     0,   379,     0,  1514,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,     0,     0,     0,     0,   379
};

static const yytype_int16 yycheck[] =
{
       6,   341,     6,   432,   433,     4,     4,     7,   219,     4,
       4,     4,     0,   351,     4,     6,   354,     6,  1183,     5,
     231,     6,     4,     4,     6,    62,     6,     4,     4,   162,
       4,     6,     4,     4,   167,     5,     5,   161,     6,    56,
       4,   811,    59,     6,   168,    62,     6,     4,   162,     6,
     151,   152,     6,     3,   168,   153,   154,   155,    13,   151,
     152,     6,   160,   274,   164,   276,   167,   167,   169,   333,
     334,   335,   336,   337,   338,   339,   340,   169,  1243,   343,
     344,   345,   644,   645,   646,     7,     4,     5,   889,    78,
     151,   152,    56,    99,     7,   161,    60,   151,   152,    56,
     885,    59,    42,    43,    62,    45,   167,    71,   103,   104,
     105,   106,   161,   167,   161,   169,   101,     7,     6,   168,
      38,    39,    40,    41,    42,    43,     6,   151,   152,   122,
     163,    49,     7,   101,   151,   152,   113,   114,   163,   113,
     114,  1306,   161,   167,   161,   169,   151,   152,   153,   154,
     155,   168,    62,     6,    64,   160,   145,   146,   147,   158,
     159,   150,   151,   161,   163,   165,   165,   161,   148,  1334,
     168,   170,   161,   148,   169,   168,   165,   168,   168,     6,
     161,   163,   168,   172,   173,   174,   175,   168,   177,   178,
     179,   180,   168,   182,   183,   184,   168,   168,   168,   168,
     189,   161,   972,    66,   154,   168,   151,   152,   168,   161,
       4,   129,   130,   151,   152,   204,   138,   139,   140,   141,
      59,   210,   211,    62,   161,   138,   139,   140,   141,   167,
     219,   168,   443,   162,   161,   573,   158,   159,   167,   577,
     158,   159,   161,   165,   163,   158,   159,   165,   138,   139,
     140,   141,   151,   152,   162,   161,  1041,   151,   152,   167,
     249,   250,   251,   138,   139,   140,   141,   207,   208,   168,
     259,   260,   261,   167,   263,   215,   161,   266,   267,   219,
     162,   270,   493,   158,   159,   167,   162,    81,    82,    83,
      84,   167,  1457,   161,   283,    89,   161,   161,    92,   163,
     168,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,  1113,     6,   151,   152,    78,    62,    78,
     354,    56,   616,   342,    59,   161,    87,    62,    87,    64,
     349,     5,   168,   352,    95,    96,    95,    96,    99,   100,
      99,   100,  1537,    62,   151,   152,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   168,   158,   159,    38,    39,    40,    41,    42,    43,
     389,   151,   152,   168,   164,    49,   395,   167,   192,   193,
     194,   400,   151,   152,     6,     7,   405,   406,   168,   408,
     409,   151,   152,    62,   413,   158,   159,    62,   167,   418,
     419,   420,   165,   167,   162,   169,    64,   167,   169,   167,
       8,   225,   226,   161,   161,   163,   435,   436,   437,   438,
     439,   440,    59,   237,   238,   444,   445,   446,   447,   448,
     724,   151,   152,   452,   151,   152,   455,   456,   151,   152,
     459,   460,   461,   168,   162,   464,   465,   167,   467,   167,
     167,   470,   432,   433,   167,   129,   130,   155,   168,   478,
     430,   431,   151,   152,    59,   484,   485,   162,   438,   151,
     152,   164,   167,    62,   167,   509,   151,   152,   167,   151,
     152,     6,     7,   164,   503,   167,   167,   185,   507,   783,
      59,   510,   167,   164,   788,   167,   167,   791,   792,   793,
      62,   151,   152,     6,   798,   203,   151,   152,   206,   151,
     152,   167,  1343,   169,  1345,  1315,  1347,   167,   151,   152,
     151,   152,   167,   151,   152,   167,   161,   821,   163,   227,
      59,     4,     5,    62,   167,    64,   167,     4,   161,   167,
     163,   161,   578,   577,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,     4,   161,
     579,   163,   160,   151,   152,    38,    39,    40,    41,    42,
      43,   169,    59,     4,   161,    62,    49,    64,  1393,   161,
     161,  1396,   280,   281,  1399,     8,   161,     6,   163,   608,
     163,   610,   611,   961,   168,    56,   964,   965,    59,   618,
     619,    62,   161,    64,   163,   163,     4,   643,   644,   645,
     646,     4,    78,   632,   161,  1446,   163,   161,   161,   638,
     163,    87,    78,   161,   643,   644,   645,   646,   161,    95,
      96,    87,   651,    99,   100,   161,   655,   656,   161,    95,
      96,   161,   661,    99,   100,   161,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   674,   129,   130,   677,   160,
       7,   161,   161,   163,   163,  1480,   161,  1498,     6,  1500,
     161,  1502,   691,   161,   693,   163,   161,  1508,   697,   698,
     699,   700,   158,   159,   654,   161,   705,   163,     4,   165,
     724,   661,   168,   712,   170,   714,   715,   667,   161,   161,
     163,   163,     6,   169,  1163,  1164,  1521,     6,   161,  1524,
     163,     6,  1527,   169,  1545,  1530,  1547,     5,  1549,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   161,   161,   163,   163,   160,   167,     5,
     169,   760,   761,   161,   161,  1560,   169,  1562,   161,  1564,
     163,   161,   161,   163,   163,   774,   775,   776,   777,   778,
     779,   780,   161,   168,   163,    78,   785,   167,   787,   169,
     167,    78,   169,   167,    87,   169,   163,   796,   165,   161,
      87,   800,    95,    96,   161,   804,    99,   100,    95,    96,
     161,   161,    99,   100,     4,   814,   815,   816,   817,   818,
     167,   161,   169,  1097,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   167,   167,
     169,   169,   160,   168,     3,     4,   167,  1121,   169,   848,
       9,    10,    11,   161,   161,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,   169,   167,   161,   169,
     830,   167,   169,   169,    78,    44,    45,    46,    62,   161,
      64,    78,   168,    87,   908,   168,   161,   575,    78,  1338,
      87,    95,    96,   161,   903,    99,   100,    87,    95,    96,
     163,   168,    99,   100,     6,    95,    96,   916,   168,    99,
     100,   168,   167,    78,   169,    78,   876,   877,   878,   167,
     163,   169,    87,   167,    87,   169,   163,   163,   937,   938,
      95,    96,    95,    96,    99,   100,    99,   100,   158,   159,
     167,   965,   169,   163,   167,   165,   169,     4,     6,     6,
     170,   639,   167,   167,   169,   169,   167,     5,   169,   128,
       5,   987,   650,     5,   973,   169,   135,   136,   137,   167,
       6,   169,   169,   167,   167,   169,   169,   986,   987,   169,
     165,   168,   151,   152,   167,   116,   169,   156,   167,   167,
     169,   169,   161,     6,   167,   164,   169,   166,     6,   168,
      78,   167,     6,   169,   169,   167,   169,   169,   167,    87,
     169,   163,     4,  1022,  1023,  1024,     6,    95,    96,    78,
     168,    99,   100,  1032,  1033,    78,   160,   167,    87,   169,
     167,  1040,   169,   721,    87,   165,    95,    96,     7,  1048,
      99,   100,    95,    96,   168,     6,    99,   100,   167,   167,
     169,   169,   167,  1077,   169,   167,   167,   169,   169,  1068,
    1069,  1070,   167,   167,   169,   169,   167,   167,   169,   169,
    1079,   167,   167,   169,   169,  1084,   167,   169,   169,  1105,
    1040,   163,   167,   167,   169,   169,   167,   173,   169,     7,
       7,   169,   178,   167,     7,   169,   182,  1106,  1124,   167,
     161,   169,   173,   189,     7,   161,   161,   178,   162,   161,
     169,   182,     6,     4,     7,  1124,   169,     6,   189,  1128,
       7,  1352,     6,     6,     6,  1134,  1135,   168,   168,   168,
    1139,   168,   113,  1159,  1494,   168,   162,   167,  1147,   162,
     162,   162,   167,   167,     6,     4,   834,   835,  1157,   837,
    1159,   839,   840,   167,     6,   843,   844,   167,   167,   164,
       6,     4,  1171,   249,     6,   251,     7,   116,     7,  1129,
       7,     7,  1181,   116,  1200,     7,  1185,     7,   116,  1188,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,  1200,     7,  1163,  1164,   160,     7,  1206,  1207,     4,
     168,   165,     6,   169,     6,  1165,   169,  1167,   164,  1169,
       7,     7,     7,   165,   168,     6,  1447,   161,   168,   161,
    1229,  1181,     6,     4,  1184,  1185,   162,     6,     6,  1513,
     918,   919,   920,   164,     6,   163,     7,     6,   148,     7,
     928,    62,     7,     7,    64,     7,     7,     7,     7,     6,
     162,   939,     7,  1262,   162,   162,   162,     7,     7,     7,
       6,     4,     4,   349,   168,     6,   352,     7,  1552,   161,
    1554,  1280,     6,  1282,     7,     7,     7,     6,   349,     6,
     168,   352,     6,  1292,     6,  1294,    62,     6,  1297,     4,
       4,  1575,     4,  1302,   169,     6,     4,     6,  1307,   168,
     161,   167,   162,   389,   992,   162,   162,   162,     7,     6,
     998,   165,     6,    71,     6,   168,  1004,   168,  1006,  1007,
     168,     6,     6,  1011,   168,     6,  1335,     6,  1016,  1017,
    1018,     5,     8,  1342,     4,  1344,     7,  1346,     6,   168,
       7,     7,     7,     7,  1032,   168,   163,  1356,     6,     6,
     168,  1360,   168,   162,  1042,   168,   164,     6,  1046,     6,
    1369,  1370,     6,     6,   167,   112,   165,  1376,  1338,     6,
       4,     6,     5,   459,   460,   461,  1385,     6,     6,     6,
    1389,     6,  1342,     6,  1344,     6,  1346,     6,   459,   460,
     461,     6,   478,     6,  1354,   168,     6,  1357,   116,   485,
       6,     6,     6,     6,     6,     6,  1415,   478,     6,     6,
       6,   167,     4,     6,  1102,   168,  1104,   162,  1427,     6,
       6,   165,     7,     6,     6,  1434,     5,     7,  1437,    60,
       6,  1440,     6,  1459,  1460,  1444,     6,     6,     6,  1448,
       6,  1450,   168,     6,   169,   168,  1455,     6,   169,  1458,
       6,  1460,   168,     6,     6,   168,   111,     6,   168,     6,
     114,   168,  1150,  1151,  1152,  1153,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     169,     6,  1491,     6,   160,     6,   162,     6,  1497,     6,
    1450,   168,     6,   168,     6,  1183,   168,     6,     6,     4,
     169,  1510,     4,    78,   984,   168,  1194,     6,     6,     6,
       6,     6,     6,  1201,     6,  1541,     6,   169,     6,     6,
    1208,     6,   608,   168,   610,     6,   168,   168,     6,   168,
    1539,     6,   618,   619,     6,     6,     6,   608,   168,   610,
       6,     6,   168,     6,   168,  1571,   168,     6,   168,     6,
       6,     6,     6,     6,     6,  1243,     6,     6,  1415,   387,
     991,     3,     3,   412,  1109,   651,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     651,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,  1277,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   691,    -1,   693,    -1,    -1,
      -1,   697,   698,   699,   700,    -1,    -1,    -1,  1306,   705,
     691,    -1,   693,    -1,    -1,    -1,   697,   698,   699,   700,
      -1,    -1,    -1,    -1,   705,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,  1334,    67,    -1,    -1,
      -1,    71,    72,    -1,    74,    75,    76,    -1,    -1,    -1,
      80,    -1,    -1,  1351,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   785,
      -1,   787,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1401,   785,    -1,   787,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   814,   815,
     816,   817,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   814,   815,   816,   817,    -1,    -1,   169,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   848,    -1,    -1,    -1,   160,    -1,    -1,  1457,
      -1,  1459,     3,     4,    -1,    -1,    -1,   848,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,    -1,    56,    -1,    -1,    59,    -1,
      -1,    62,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,  1537,
      81,    82,    83,    84,    85,    -1,    -1,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,
      71,    72,    -1,    74,    75,    76,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,
      -1,    -1,    -1,    -1,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     151,   152,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
     161,    -1,    -1,    -1,    -1,   166,    -1,   168,   169,    -1,
      -1,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,  1048,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,  1048,   169,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
      -1,    56,    -1,    -1,    59,    -1,    -1,    62,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    -1,    -1,    89,    -1,    -1,    92,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    67,    -1,    -1,    -1,    71,    72,    -1,    74,
      75,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,  1181,     6,    -1,    -1,  1185,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   151,   152,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,
      -1,   166,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   169,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,  1282,    59,    -1,    -1,
      62,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1297,    -1,    75,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    -1,  1297,    89,    -1,    -1,
      92,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,     6,    -1,    -1,  1335,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1335,    -1,   128,   129,   130,    -1,
    1356,     6,    -1,   135,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1356,    -1,    -1,    -1,   151,
     152,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,   161,
      -1,    -1,    -1,    -1,   166,    -1,   168,    -1,     3,     4,
       5,    -1,     7,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1448,    -1,  1450,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1448,    -1,  1450,
      -1,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,    -1,    -1,    -1,    -1,  1491,    -1,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,  1510,   160,    -1,   122,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,    -1,    -1,    -1,  1510,
     135,   136,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,   152,    -1,    -1,
      -1,   156,    -1,   158,   159,    -1,   161,    -1,   163,    -1,
     165,   166,    -1,   168,     3,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,
      89,    -1,    -1,    92,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,
      71,    72,    -1,    74,    75,    76,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,   161,    -1,     3,     4,     5,   166,    -1,   168,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,   169,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,
      89,    -1,    -1,    92,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,
      71,    72,    -1,    74,    75,    76,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,   161,    -1,     3,     4,    -1,   166,    -1,   168,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,   169,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,
      89,    -1,    -1,    92,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,
      71,    72,    -1,    74,    75,    76,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,   161,    -1,     3,     4,    -1,   166,    -1,   168,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,   169,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,
      89,    -1,    -1,    92,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,
      71,    72,    -1,    74,    75,    76,    -1,    -1,     6,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,   161,    -1,     3,     4,    -1,   166,    -1,   168,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,   169,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,
      89,    -1,    -1,    92,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,    -1,    -1,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   128,
       6,    -1,    -1,   160,    -1,    -1,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,   161,    -1,     3,     4,    -1,   166,    -1,   168,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,
      89,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       6,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,   161,    -1,     3,     4,    -1,   166,    -1,   168,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,
      89,    -1,    -1,    92,    -1,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   128,
       6,    -1,    -1,   160,    -1,    -1,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,   161,    -1,     3,     4,     5,   166,    -1,   168,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      49,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,   161,    -1,    -1,    -1,    -1,   166,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,   161,
      -1,     3,     4,     5,   166,    -1,   168,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     3,     4,    49,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,     3,
       4,    -1,    -1,    12,    13,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,    -1,
      44,    45,    46,   135,   136,   137,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,   151,
     152,    -1,    71,    72,   156,    74,    75,    76,    -1,   161,
      -1,    80,    -1,    -1,   166,    -1,   168,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,    -1,   151,   152,    -1,    -1,    -1,   156,    -1,
      -1,    -1,    -1,   161,    -1,    -1,   164,    -1,   166,    -1,
     168,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,    -1,
      -1,    -1,   156,    -1,    -1,    -1,    -1,   161,    -1,     3,
       4,    -1,   166,    -1,   168,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    -1,    62,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,   128,    -1,    81,    82,    83,    84,
      85,   135,   136,   137,    89,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,    -1,
      -1,    -1,   156,    -1,     6,    -1,    -1,   161,    -1,    -1,
      -1,    -1,   166,    -1,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,    -1,     6,    -1,    -1,    -1,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,   152,    -1,    -1,
      -1,   156,     3,     4,     5,    -1,   161,    -1,     9,    10,
      11,   166,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     3,     4,    49,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,     7,    -1,    -1,    -1,   160,    -1,
      -1,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,     8,   128,   129,   130,
     160,    -1,    -1,    -1,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
     151,   152,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
     161,    -1,    -1,    -1,     8,   166,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,
     137,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   151,   152,    -1,    -1,    -1,   156,
      -1,    -1,     8,    -1,   161,    -1,    -1,    -1,    -1,   166,
      -1,    -1,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,     8,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    78,    -1,    -1,   160,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,     0,     1,    -1,   160,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    36,    37,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,     4,    97,    98,    -1,    -1,    -1,   102,    -1,
      12,    13,    -1,   107,   108,   109,   110,    -1,    -1,   113,
      -1,   115,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    36,    37,    -1,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,    47,    48,    -1,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,
     102,    -1,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,   113,    -1,   115,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,    -1,    -1,   131,
     132,   133,   134,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,
     169,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,   169,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   167,    -1,   169,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   169,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   169,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   169,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   169,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   169,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   169,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   169,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   169,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   169,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   169,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   168,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,   162,    -1,    -1,    -1,    -1,   167,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,   167,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,   167,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,   167,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,   167,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,   167,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,   167,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,   164,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,
     164,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,   164,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,    -1,    -1,    -1,   164,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,   164,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,
      -1,    -1,   164,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,   164,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,   164,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,   164,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,    -1,    -1,    -1,   164,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,   164,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,
     164,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,   164,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,    -1,    -1,    -1,   164,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,   164,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,
      -1,    -1,   164,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,   164,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,   164,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,   164,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,    -1,    -1,    -1,   164,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,   164,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,
     164,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,   164,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,    -1,    -1,    -1,   164,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,   164,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,
      -1,    -1,   164,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,   164,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,   164,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,   164,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,    -1,    -1,    -1,   164,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,   164,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,
     164,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,   164,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,    -1,   162,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,   162,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,    -1,   162,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,   162,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,    -1,   162,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,   162,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,
     162,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,   162,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,    -1,   162,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,   162,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,    -1,   162,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,   162,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,    -1,   162,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,   162,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,    -1,   162,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,   162,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,
     162,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,   162,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,    -1,   162,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,   162,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,    -1,   162,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,   162,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,    -1,   162,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,   162,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,    -1,   162,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,   162,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,
     162,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,   162,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,    -1,   162,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,   162,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,    -1,   162,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,   162,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,    -1,   162,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,   162,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,    -1,   162,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,   162,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,
     162,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,   162,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,    -1,   162,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,   162,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,    -1,   162,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,   162,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,    -1,   162,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,   162,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,    -1,   162,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,   162,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,    -1,
     162,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
      -1,   162,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,    -1,   162,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,    -1,   162,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,    -1,   162,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,    -1,   162,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,    -1,   162,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,    -1,   162,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,    -1,   162,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   172,   173,     6,     0,     4,    12,    13,    36,
      37,    47,    48,    50,    51,    52,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    97,    98,   102,   107,   108,
     109,   110,   113,   115,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   131,   132,   133,   134,   174,
     176,   177,   195,   209,   214,   217,   218,   219,   220,   221,
     222,   223,   243,   244,   245,   246,     3,     4,     5,     7,
       9,    10,    11,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    49,   122,   128,   129,   130,   135,   136,
     137,   138,   139,   140,   141,   151,   152,   156,   158,   159,
     161,   163,   165,   166,   168,   193,   194,   247,   248,   260,
      13,    62,   161,   161,     6,   168,     6,     6,     6,     6,
     163,   163,   161,   168,   161,   161,     4,   161,   168,   161,
     161,     4,   168,   161,   161,    66,    62,    62,     6,   168,
      62,    62,    59,    62,    64,    64,    56,    59,    62,    64,
      59,    62,    64,    59,    62,   161,    59,   168,   151,   152,
     161,   168,   249,   250,   249,   168,    56,    59,    62,   168,
     249,     4,    56,    60,    71,    62,    64,    62,    59,     4,
     122,   168,     4,     6,    56,    59,    62,    59,    62,     4,
       4,     4,     5,    35,    56,    59,    62,    64,    75,   152,
     161,   168,   214,   223,   247,   252,   253,   254,     4,   161,
     161,   161,     4,   168,   256,     4,   161,   161,     6,     6,
     163,     4,     4,     5,   168,     5,   168,     4,   247,     6,
     161,   168,     4,   163,   165,   170,   194,   168,     5,   260,
     161,   163,   161,   163,   161,   163,   161,   163,   161,   163,
     161,   163,   161,   163,   161,   163,   161,   163,   161,   163,
     161,   163,   161,   163,   161,   163,   161,   163,   161,   163,
     161,   163,   161,   163,   161,   163,   161,   163,   161,   163,
     161,   163,   163,   161,   163,   161,   161,   161,   161,   161,
     161,   161,     7,   161,   161,   161,   247,   247,   247,   168,
     247,   164,   168,   247,     4,   113,   114,     4,     4,   214,
     215,   216,   252,     6,     6,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   160,
       6,     6,   247,     5,     5,   247,   197,   200,   247,   152,
     247,   254,   255,   247,   247,   161,   247,   255,   247,   247,
     161,   255,   247,   247,   252,   161,   168,   255,   161,   161,
     253,   253,   253,   161,   210,   211,   212,   213,   161,   161,
     161,   252,   247,     4,   252,   249,   249,   249,   247,   247,
     151,   152,   168,   168,   249,   168,   168,   168,   151,   152,
     161,   216,   249,   168,   161,   168,   161,   161,   161,   253,
     253,   252,   161,     4,     6,   163,   163,   216,     6,   168,
     168,   168,   253,   253,   163,   163,   161,   163,   163,     5,
     168,     5,     5,     5,    56,    59,    62,    64,   168,   247,
     254,   247,   169,   255,     8,   153,     6,     6,   247,   247,
     247,   165,   247,   168,   116,   247,   247,   247,     6,     6,
     216,     6,   216,   163,     6,   252,   252,   163,   247,     4,
     168,   178,     6,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,     4,   259,   260,   261,   259,
     259,   259,   259,   259,   259,   259,   259,   261,   247,   259,
     259,   259,   255,   162,     7,   193,   255,   164,     7,   193,
     194,   165,     7,   163,   169,    56,    59,    62,    64,   209,
       6,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,     6,   162,   167,   162,
     167,   167,   164,   167,   196,   164,   196,   162,   153,   167,
     169,   162,   162,   247,   162,   169,   162,   162,   247,   169,
     162,   162,     7,   247,   247,   169,   247,   247,     7,     7,
     241,   241,   247,   161,   161,   161,   161,   247,   247,   247,
       7,   168,   162,     6,   167,   167,   167,   249,   249,   215,
     215,   167,   247,   247,   247,   247,   227,   167,   216,   247,
     247,   247,   247,   247,     7,   242,     6,     7,   247,     6,
     247,   247,   169,   255,   255,   255,     6,     6,   247,   247,
     162,   168,   164,   168,   247,     4,   247,   168,   168,   168,
     168,   255,   162,   169,   247,   168,   247,   254,   162,   162,
     162,   113,   167,   216,   168,     8,   162,   164,   169,   169,
     162,   167,   169,   247,   164,   194,   247,     4,   103,   104,
     105,   106,   169,   181,   185,   188,   190,   191,   162,   164,
     162,   164,   162,   164,   162,   164,   162,   164,   162,   164,
     162,   164,   162,   164,   162,   164,   162,   164,   162,   164,
     167,   167,   162,   164,   162,   164,   162,   164,   162,   164,
     162,   164,   162,   164,   167,   167,   167,   167,   167,   167,
     163,   165,   164,   167,   162,   167,   164,   167,   167,   162,
     162,   167,   167,   167,   162,     6,   167,   162,   167,   169,
     193,   252,   169,   165,   193,   194,   260,   247,     6,     4,
       4,   168,   257,   164,   168,   168,   168,   168,     8,     6,
     148,   175,   255,     6,   255,   247,     6,     4,     6,   259,
       7,   247,   254,   116,     7,     7,   162,     7,   116,     7,
       7,   162,   116,     7,     7,   247,   162,   169,   168,   162,
     162,   247,   252,     4,   240,     6,   162,   206,   247,   260,
     206,   206,   206,   162,   162,   162,   252,   255,   165,   249,
     247,   247,   169,   169,   247,   249,   167,   167,   167,    78,
      87,    95,    96,    99,   100,   237,   238,   249,   169,   224,
     162,   169,   162,   162,   162,   247,     6,   247,   162,   164,
     164,   169,   169,   169,   164,   164,   255,   255,   164,   164,
     169,   255,   255,   255,   255,   169,     8,   255,     7,     7,
       7,   165,   247,   169,   247,   247,     7,   165,   168,   252,
       6,   164,   165,   194,   259,   169,   182,   161,   161,   168,
     192,     6,   247,   247,   247,   247,   247,   247,   247,   247,
     247,     4,   259,   255,   255,   259,   259,   259,   259,   247,
     259,   162,   247,     6,   164,     4,   113,   114,   247,     6,
       6,     6,     7,   163,   256,   258,     6,   255,   255,   255,
     255,   247,   148,   259,   162,   162,   167,     7,   249,    62,
     252,   252,     7,   252,    62,    64,   252,   252,     7,    64,
     252,   252,     6,     7,     7,   255,     7,     7,    78,   239,
       6,     7,   162,   162,   162,   162,     7,     7,     7,     6,
     169,     4,   167,   167,   167,   169,   169,   249,   249,   249,
       4,     6,   168,   161,     6,   101,     6,   101,   169,   238,
     167,   237,     7,     6,     7,     7,     7,     6,   168,     6,
       6,     6,    62,   247,     6,     6,   169,   169,   169,   169,
     169,   169,   247,   169,   252,   252,   252,     4,   167,     8,
       8,   162,     4,     4,   252,   169,     6,     4,     6,   161,
     247,   247,   251,   252,   168,   162,   164,   162,   164,   162,
     164,   162,   164,   164,   162,   164,   162,   167,   162,   162,
     162,   162,   193,     6,   193,     7,   193,   194,   165,     7,
       6,   256,   247,   167,   169,   169,   169,   169,   169,     6,
       6,   175,     6,   247,   168,   247,   260,     6,   168,    71,
     208,   208,   252,     6,   168,   168,     6,     6,   252,   168,
       6,     6,     5,   252,   169,   252,   252,     4,     6,   252,
       7,     7,     7,     7,   252,   252,   252,     7,     6,     7,
     247,   247,   247,   168,   168,   167,   169,   167,   169,   167,
     169,   163,   247,   252,   247,     6,     6,   247,   249,   169,
       5,   168,   252,   168,   168,   168,   252,   255,   168,     6,
     162,   164,     6,     6,   112,   247,   247,   247,     6,     6,
       7,   167,     6,   194,   179,   247,   167,   167,   167,   169,
     180,   247,   165,   259,   252,   252,   260,   247,     6,     4,
     257,     6,   164,   256,     6,     6,     6,     6,   259,   167,
     247,   260,   247,   249,     6,     6,     6,   247,   247,     6,
     247,     5,     6,   168,     6,   116,   207,   247,     6,   252,
     252,   252,   252,     6,     4,     6,     6,   247,   247,   260,
     169,   162,   167,   169,   215,   215,   249,     6,   228,   249,
       6,   229,   249,     6,   230,   247,   169,   167,   162,   169,
     167,     6,   152,   249,     6,   251,   249,   249,     6,   169,
     247,   252,   167,   169,     8,   169,   162,   168,   247,   260,
     252,   162,   167,   247,   247,   252,   168,   167,   169,     4,
     162,     6,     6,     6,     6,     7,     6,   165,     6,   247,
     198,   199,   169,   169,   169,   169,     5,   251,    60,     6,
       6,     6,     6,     6,   168,   168,     6,     6,   168,   247,
     169,   169,   167,   168,   167,   168,   167,   168,   164,     6,
     252,     7,   168,   247,   167,   169,   167,   167,     6,   169,
     111,   247,   247,   255,     6,     6,   169,   183,   247,   167,
     167,   251,   247,     6,   256,   114,   167,   202,   204,     6,
       6,     6,     6,     6,   169,   168,   251,   255,   215,   167,
     169,   247,   249,   237,   247,   249,   237,   247,   249,   237,
       6,   167,   169,   252,   216,   169,   249,     6,   255,   249,
     247,   169,   169,   169,     6,   168,   247,   247,   169,     6,
     247,   167,   169,   203,   167,   169,   205,   168,   247,   169,
     169,   169,   247,   169,   167,   169,   169,   167,   169,   169,
     167,   169,   252,     6,    78,   169,   225,   168,   167,   169,
     167,     6,     6,   180,   162,   167,     6,   168,   167,     4,
       4,   247,   169,     6,     6,   169,     6,   231,   247,     6,
       6,   232,   247,     6,     6,   233,   247,     6,   169,   247,
     237,   216,   255,     6,   249,   255,   169,   186,   247,   251,
     247,   168,   252,   260,   168,   247,   260,   167,   168,   169,
     168,   169,   168,   169,     6,     6,   169,   169,   226,   169,
     167,   169,     6,   168,   162,   169,   169,   201,   247,   261,
     247,   237,     6,   234,   237,     6,   235,   237,     6,   236,
     237,     6,   255,     6,   184,   259,   189,   168,     6,   167,
     169,     7,   169,   169,   169,   168,   169,   168,   169,   168,
     169,   169,   167,   169,   168,   251,   247,   260,     6,     6,
     237,     6,   237,     6,   237,     6,   259,     6,   187,   259,
     169,     7,   169,   169,   169,   167,   169,     6,   260,     6,
       6,     6,   259,     6
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
#line 169 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 180 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 181 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 182 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 183 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 184 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 185 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 186 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 187 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 188 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 189 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 190 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 191 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 192 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 193 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 194 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 199 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 22:
#line 203 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 23:
#line 210 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 24:
#line 215 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 25:
#line 220 "Gmsh.y"
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
#line 234 "Gmsh.y"
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
#line 247 "Gmsh.y"
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
#line 260 "Gmsh.y"
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
#line 288 "Gmsh.y"
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
#line 302 "Gmsh.y"
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
#line 313 "Gmsh.y"
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
#line 327 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 38:
#line 341 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 39:
#line 343 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 40:
#line 348 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:
#line 350 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:
#line 355 "Gmsh.y"
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
#line 459 "Gmsh.y"
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
#line 469 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 45:
#line 478 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 46:
#line 485 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 47:
#line 495 "Gmsh.y"
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
#line 504 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 49:
#line 513 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 50:
#line 520 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 51:
#line 530 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 52:
#line 538 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 53:
#line 548 "Gmsh.y"
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
#line 567 "Gmsh.y"
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
#line 586 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 56:
#line 592 "Gmsh.y"
    {
    ;}
    break;

  case 57:
#line 599 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 58:
#line 600 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 59:
#line 601 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 60:
#line 602 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 61:
#line 603 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 62:
#line 607 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 63:
#line 608 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 66:
#line 619 "Gmsh.y"
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
#line 681 "Gmsh.y"
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
#line 711 "Gmsh.y"
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
#line 746 "Gmsh.y"
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
#line 780 "Gmsh.y"
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
#line 828 "Gmsh.y"
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
#line 875 "Gmsh.y"
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
#line 890 "Gmsh.y"
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
#line 906 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 75:
#line 915 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 76:
#line 921 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 77:
#line 930 "Gmsh.y"
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
#line 948 "Gmsh.y"
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
#line 966 "Gmsh.y"
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
#line 975 "Gmsh.y"
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
#line 987 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 82:
#line 992 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 83:
#line 1000 "Gmsh.y"
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
#line 1020 "Gmsh.y"
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
#line 1043 "Gmsh.y"
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
#line 1054 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 87:
#line 1062 "Gmsh.y"
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
#line 1084 "Gmsh.y"
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
#line 1107 "Gmsh.y"
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
#line 1133 "Gmsh.y"
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
#line 1154 "Gmsh.y"
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
#line 1166 "Gmsh.y"
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
#line 1184 "Gmsh.y"
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
#line 1195 "Gmsh.y"
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
#line 1206 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 99:
#line 1208 "Gmsh.y"
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
#line 1218 "Gmsh.y"
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
#line 1229 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 102:
#line 1231 "Gmsh.y"
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
#line 1245 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 105:
#line 1253 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 106:
#line 1259 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 109:
#line 1271 "Gmsh.y"
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
#line 1282 "Gmsh.y"
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
#line 1297 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 114:
#line 1313 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 115:
#line 1321 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 116:
#line 1330 "Gmsh.y"
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
#line 1348 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 118:
#line 1352 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 119:
#line 1362 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 120:
#line 1366 "Gmsh.y"
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
#line 1378 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 122:
#line 1382 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 123:
#line 1392 "Gmsh.y"
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
#line 1415 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 125:
#line 1419 "Gmsh.y"
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
#line 1435 "Gmsh.y"
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
#line 1457 "Gmsh.y"
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
#line 1475 "Gmsh.y"
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
#line 1496 "Gmsh.y"
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
#line 1514 "Gmsh.y"
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
#line 1544 "Gmsh.y"
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
#line 1574 "Gmsh.y"
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
#line 1592 "Gmsh.y"
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
#line 1610 "Gmsh.y"
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
#line 1636 "Gmsh.y"
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
#line 1654 "Gmsh.y"
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
#line 1672 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 138:
#line 1676 "Gmsh.y"
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
#line 1695 "Gmsh.y"
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
#line 1713 "Gmsh.y"
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
#line 1752 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 142:
#line 1758 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 143:
#line 1764 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 144:
#line 1771 "Gmsh.y"
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
#line 1796 "Gmsh.y"
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
#line 1821 "Gmsh.y"
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
#line 1838 "Gmsh.y"
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
#line 1856 "Gmsh.y"
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
#line 1886 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 150:
#line 1890 "Gmsh.y"
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
#line 1910 "Gmsh.y"
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
#line 1928 "Gmsh.y"
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
#line 1945 "Gmsh.y"
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
#line 1961 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 155:
#line 1965 "Gmsh.y"
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
#line 1987 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 157:
#line 1992 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 158:
#line 1997 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 159:
#line 2002 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 160:
#line 2007 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 161:
#line 2012 "Gmsh.y"
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
#line 2035 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 163:
#line 2041 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 164:
#line 2051 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 165:
#line 2052 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 166:
#line 2057 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 167:
#line 2061 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 168:
#line 2065 "Gmsh.y"
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
#line 2088 "Gmsh.y"
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
#line 2111 "Gmsh.y"
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
#line 2134 "Gmsh.y"
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
#line 2162 "Gmsh.y"
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
#line 2183 "Gmsh.y"
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
#line 2210 "Gmsh.y"
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
#line 2231 "Gmsh.y"
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
#line 2252 "Gmsh.y"
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
#line 2272 "Gmsh.y"
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
#line 2384 "Gmsh.y"
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
#line 2403 "Gmsh.y"
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
#line 2442 "Gmsh.y"
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
#line 2550 "Gmsh.y"
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
#line 2559 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 183:
#line 2565 "Gmsh.y"
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
#line 2580 "Gmsh.y"
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
#line 2608 "Gmsh.y"
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
#line 2625 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 187:
#line 2639 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 188:
#line 2645 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 189:
#line 2651 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 190:
#line 2660 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 191:
#line 2674 "Gmsh.y"
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

  case 192:
#line 2719 "Gmsh.y"
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

  case 193:
#line 2736 "Gmsh.y"
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

  case 194:
#line 2751 "Gmsh.y"
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

  case 195:
#line 2770 "Gmsh.y"
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

  case 196:
#line 2782 "Gmsh.y"
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

  case 197:
#line 2806 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 198:
#line 2810 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 199:
#line 2815 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 200:
#line 2822 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 201:
#line 2828 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 202:
#line 2833 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 203:
#line 2839 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 204:
#line 2843 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 205:
#line 2847 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 206:
#line 2853 "Gmsh.y"
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

  case 207:
#line 2907 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    ;}
    break;

  case 208:
#line 2920 "Gmsh.y"
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

  case 209:
#line 2937 "Gmsh.y"
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

  case 210:
#line 2954 "Gmsh.y"
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

  case 211:
#line 2975 "Gmsh.y"
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

  case 212:
#line 2996 "Gmsh.y"
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

  case 213:
#line 3031 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 214:
#line 3039 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 215:
#line 3045 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 216:
#line 3052 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 217:
#line 3056 "Gmsh.y"
    {
    ;}
    break;

  case 218:
#line 3065 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 219:
#line 3073 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 220:
#line 3081 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 221:
#line 3089 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 222:
#line 3094 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 223:
#line 3102 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 224:
#line 3107 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 225:
#line 3115 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 226:
#line 3120 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 227:
#line 3128 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 228:
#line 3133 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 229:
#line 3141 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 230:
#line 3148 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 231:
#line 3155 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 232:
#line 3162 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 233:
#line 3169 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 234:
#line 3176 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 235:
#line 3183 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 236:
#line 3190 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 237:
#line 3197 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 238:
#line 3204 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 239:
#line 3209 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 240:
#line 3216 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 241:
#line 3221 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 242:
#line 3228 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 243:
#line 3233 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 244:
#line 3240 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 245:
#line 3245 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 246:
#line 3252 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 247:
#line 3257 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 248:
#line 3264 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 249:
#line 3269 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 250:
#line 3276 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 251:
#line 3281 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 252:
#line 3288 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 253:
#line 3293 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 254:
#line 3300 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 255:
#line 3305 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 256:
#line 3316 "Gmsh.y"
    {
    ;}
    break;

  case 257:
#line 3319 "Gmsh.y"
    {
    ;}
    break;

  case 258:
#line 3325 "Gmsh.y"
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

  case 259:
#line 3337 "Gmsh.y"
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

  case 260:
#line 3357 "Gmsh.y"
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

  case 261:
#line 3380 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 262:
#line 3384 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 263:
#line 3388 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 264:
#line 3392 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 265:
#line 3396 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 266:
#line 3400 "Gmsh.y"
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

  case 267:
#line 3419 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 268:
#line 3431 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 269:
#line 3435 "Gmsh.y"
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

  case 270:
#line 3450 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 271:
#line 3454 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "Right"))
        (yyval.i) = 1;
      else if(!strcmp((yyvsp[(1) - (1)].c), "Left"))
        (yyval.i) = -1;
      else // alternated
        (yyval.i) = 0;
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 272:
#line 3466 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 273:
#line 3470 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 274:
#line 3475 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 275:
#line 3479 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 276:
#line 3486 "Gmsh.y"
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

  case 277:
#line 3542 "Gmsh.y"
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

  case 278:
#line 3612 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 279:
#line 3617 "Gmsh.y"
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

  case 280:
#line 3684 "Gmsh.y"
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

  case 281:
#line 3720 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 282:
#line 3728 "Gmsh.y"
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

  case 283:
#line 3771 "Gmsh.y"
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

  case 284:
#line 3810 "Gmsh.y"
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

  case 285:
#line 3830 "Gmsh.y"
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

  case 286:
#line 3858 "Gmsh.y"
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

  case 287:
#line 3897 "Gmsh.y"
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

  case 288:
#line 3920 "Gmsh.y"
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

  case 289:
#line 3943 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 290:
#line 3947 "Gmsh.y"
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

  case 291:
#line 3970 "Gmsh.y"
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

  case 292:
#line 4009 "Gmsh.y"
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

  case 293:
#line 4054 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 294:
#line 4058 "Gmsh.y"
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

  case 295:
#line 4068 "Gmsh.y"
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

  case 296:
#line 4102 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 297:
#line 4103 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 298:
#line 4104 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 299:
#line 4109 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 300:
#line 4115 "Gmsh.y"
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

  case 301:
#line 4127 "Gmsh.y"
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

  case 302:
#line 4145 "Gmsh.y"
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

  case 303:
#line 4172 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 304:
#line 4173 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 305:
#line 4174 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 306:
#line 4175 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 307:
#line 4176 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 308:
#line 4177 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 309:
#line 4178 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 310:
#line 4179 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 311:
#line 4181 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 312:
#line 4187 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 313:
#line 4188 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 314:
#line 4189 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 315:
#line 4190 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 316:
#line 4191 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 317:
#line 4192 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 318:
#line 4193 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 319:
#line 4194 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 320:
#line 4195 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 321:
#line 4196 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 322:
#line 4197 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 323:
#line 4198 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 324:
#line 4199 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 325:
#line 4200 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 326:
#line 4201 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 327:
#line 4202 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 328:
#line 4203 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 329:
#line 4204 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 330:
#line 4205 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 331:
#line 4206 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 332:
#line 4207 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 333:
#line 4208 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 334:
#line 4209 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 335:
#line 4210 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 336:
#line 4211 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 337:
#line 4212 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 338:
#line 4213 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 339:
#line 4214 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 340:
#line 4215 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 341:
#line 4216 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 342:
#line 4217 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 343:
#line 4218 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 344:
#line 4221 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 345:
#line 4222 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 346:
#line 4223 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 347:
#line 4224 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 348:
#line 4225 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 349:
#line 4226 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 350:
#line 4227 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 351:
#line 4228 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 352:
#line 4229 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 353:
#line 4230 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 354:
#line 4231 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 355:
#line 4232 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 356:
#line 4233 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 357:
#line 4234 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 358:
#line 4235 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 359:
#line 4236 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 360:
#line 4237 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 361:
#line 4238 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 362:
#line 4239 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 363:
#line 4240 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 364:
#line 4241 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 365:
#line 4250 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 366:
#line 4251 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 367:
#line 4252 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 368:
#line 4253 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 369:
#line 4254 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 370:
#line 4255 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 371:
#line 4256 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 372:
#line 4261 "Gmsh.y"
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

  case 373:
#line 4282 "Gmsh.y"
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

  case 374:
#line 4301 "Gmsh.y"
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

  case 375:
#line 4319 "Gmsh.y"
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

  case 376:
#line 4331 "Gmsh.y"
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

  case 377:
#line 4348 "Gmsh.y"
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

  case 378:
#line 4369 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 379:
#line 4374 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 380:
#line 4379 "Gmsh.y"
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

  case 381:
#line 4389 "Gmsh.y"
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

  case 382:
#line 4399 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 383:
#line 4404 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 384:
#line 4413 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 385:
#line 4418 "Gmsh.y"
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

  case 386:
#line 4445 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 387:
#line 4449 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 388:
#line 4453 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 389:
#line 4457 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 390:
#line 4461 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 391:
#line 4468 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 392:
#line 4472 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 393:
#line 4476 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 394:
#line 4480 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 395:
#line 4487 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 396:
#line 4492 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 397:
#line 4499 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 398:
#line 4504 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 399:
#line 4508 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 400:
#line 4513 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 401:
#line 4517 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 402:
#line 4525 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 403:
#line 4536 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 404:
#line 4540 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 405:
#line 4552 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 406:
#line 4560 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 407:
#line 4568 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 408:
#line 4575 "Gmsh.y"
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

  case 409:
#line 4585 "Gmsh.y"
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

  case 410:
#line 4605 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 411:
#line 4609 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 412:
#line 4613 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 413:
#line 4617 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 414:
#line 4621 "Gmsh.y"
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

  case 415:
#line 4650 "Gmsh.y"
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

  case 416:
#line 4679 "Gmsh.y"
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

  case 417:
#line 4708 "Gmsh.y"
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

  case 418:
#line 4737 "Gmsh.y"
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

  case 419:
#line 4747 "Gmsh.y"
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

  case 420:
#line 4757 "Gmsh.y"
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

  case 421:
#line 4770 "Gmsh.y"
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

  case 422:
#line 4782 "Gmsh.y"
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

  case 423:
#line 4794 "Gmsh.y"
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

  case 424:
#line 4813 "Gmsh.y"
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

  case 425:
#line 4834 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 426:
#line 4839 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 427:
#line 4843 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 428:
#line 4847 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 429:
#line 4859 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 430:
#line 4863 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 431:
#line 4875 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 432:
#line 4882 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 433:
#line 4892 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 434:
#line 4896 "Gmsh.y"
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

  case 435:
#line 4911 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 436:
#line 4916 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 437:
#line 4923 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 438:
#line 4927 "Gmsh.y"
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

  case 439:
#line 4940 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 440:
#line 4948 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 441:
#line 4959 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 442:
#line 4963 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 443:
#line 4971 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 444:
#line 4979 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 445:
#line 4987 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 446:
#line 4995 "Gmsh.y"
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

  case 447:
#line 5009 "Gmsh.y"
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

  case 448:
#line 5023 "Gmsh.y"
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

  case 449:
#line 5035 "Gmsh.y"
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

  case 450:
#line 5051 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 451:
#line 5056 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 452:
#line 5060 "Gmsh.y"
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

  case 453:
#line 5080 "Gmsh.y"
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

  case 454:
#line 5102 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 455:
#line 5107 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 10404 "Gmsh.tab.cpp"
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


#line 5110 "Gmsh.y"


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

