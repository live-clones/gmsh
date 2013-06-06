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
     tSprintf = 293,
     tStrCat = 294,
     tStrPrefix = 295,
     tStrRelative = 296,
     tStrReplace = 297,
     tStrFind = 298,
     tStrCmp = 299,
     tTextAttributes = 300,
     tBoundingBox = 301,
     tDraw = 302,
     tToday = 303,
     tSyncModel = 304,
     tCreateTopology = 305,
     tCreateTopologyNoHoles = 306,
     tDistanceFunction = 307,
     tDefineConstant = 308,
     tUndefineConstant = 309,
     tPoint = 310,
     tCircle = 311,
     tEllipse = 312,
     tLine = 313,
     tSphere = 314,
     tPolarSphere = 315,
     tSurface = 316,
     tSpline = 317,
     tVolume = 318,
     tCharacteristic = 319,
     tLength = 320,
     tParametric = 321,
     tElliptic = 322,
     tRefineMesh = 323,
     tAdaptMesh = 324,
     tPlane = 325,
     tRuled = 326,
     tTransfinite = 327,
     tComplex = 328,
     tPhysical = 329,
     tCompound = 330,
     tPeriodic = 331,
     tUsing = 332,
     tPlugin = 333,
     tDegenerated = 334,
     tRotate = 335,
     tTranslate = 336,
     tSymmetry = 337,
     tDilate = 338,
     tExtrude = 339,
     tLevelset = 340,
     tRecombine = 341,
     tSmoother = 342,
     tSplit = 343,
     tDelete = 344,
     tCoherence = 345,
     tIntersect = 346,
     tMeshAlgorithm = 347,
     tReverse = 348,
     tLayers = 349,
     tHole = 350,
     tAlias = 351,
     tAliasWithOptions = 352,
     tQuadTriDbl = 353,
     tQuadTriSngl = 354,
     tRecombLaterals = 355,
     tTransfQuadTri = 356,
     tText2D = 357,
     tText3D = 358,
     tInterpolationScheme = 359,
     tTime = 360,
     tCombine = 361,
     tBSpline = 362,
     tBezier = 363,
     tNurbs = 364,
     tNurbsOrder = 365,
     tNurbsKnots = 366,
     tColor = 367,
     tColorTable = 368,
     tFor = 369,
     tIn = 370,
     tEndFor = 371,
     tIf = 372,
     tEndIf = 373,
     tExit = 374,
     tAbort = 375,
     tField = 376,
     tReturn = 377,
     tCall = 378,
     tFunction = 379,
     tShow = 380,
     tHide = 381,
     tGetValue = 382,
     tGetEnv = 383,
     tGetString = 384,
     tHomology = 385,
     tCohomology = 386,
     tBetti = 387,
     tSetOrder = 388,
     tGMSH_MAJOR_VERSION = 389,
     tGMSH_MINOR_VERSION = 390,
     tGMSH_PATCH_VERSION = 391,
     tAFFECTDIVIDE = 392,
     tAFFECTTIMES = 393,
     tAFFECTMINUS = 394,
     tAFFECTPLUS = 395,
     tOR = 396,
     tAND = 397,
     tNOTEQUAL = 398,
     tEQUAL = 399,
     tGREATEROREQUAL = 400,
     tLESSOREQUAL = 401,
     UNARYPREC = 402,
     tMINUSMINUS = 403,
     tPLUSPLUS = 404
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
#define tSprintf 293
#define tStrCat 294
#define tStrPrefix 295
#define tStrRelative 296
#define tStrReplace 297
#define tStrFind 298
#define tStrCmp 299
#define tTextAttributes 300
#define tBoundingBox 301
#define tDraw 302
#define tToday 303
#define tSyncModel 304
#define tCreateTopology 305
#define tCreateTopologyNoHoles 306
#define tDistanceFunction 307
#define tDefineConstant 308
#define tUndefineConstant 309
#define tPoint 310
#define tCircle 311
#define tEllipse 312
#define tLine 313
#define tSphere 314
#define tPolarSphere 315
#define tSurface 316
#define tSpline 317
#define tVolume 318
#define tCharacteristic 319
#define tLength 320
#define tParametric 321
#define tElliptic 322
#define tRefineMesh 323
#define tAdaptMesh 324
#define tPlane 325
#define tRuled 326
#define tTransfinite 327
#define tComplex 328
#define tPhysical 329
#define tCompound 330
#define tPeriodic 331
#define tUsing 332
#define tPlugin 333
#define tDegenerated 334
#define tRotate 335
#define tTranslate 336
#define tSymmetry 337
#define tDilate 338
#define tExtrude 339
#define tLevelset 340
#define tRecombine 341
#define tSmoother 342
#define tSplit 343
#define tDelete 344
#define tCoherence 345
#define tIntersect 346
#define tMeshAlgorithm 347
#define tReverse 348
#define tLayers 349
#define tHole 350
#define tAlias 351
#define tAliasWithOptions 352
#define tQuadTriDbl 353
#define tQuadTriSngl 354
#define tRecombLaterals 355
#define tTransfQuadTri 356
#define tText2D 357
#define tText3D 358
#define tInterpolationScheme 359
#define tTime 360
#define tCombine 361
#define tBSpline 362
#define tBezier 363
#define tNurbs 364
#define tNurbsOrder 365
#define tNurbsKnots 366
#define tColor 367
#define tColorTable 368
#define tFor 369
#define tIn 370
#define tEndFor 371
#define tIf 372
#define tEndIf 373
#define tExit 374
#define tAbort 375
#define tField 376
#define tReturn 377
#define tCall 378
#define tFunction 379
#define tShow 380
#define tHide 381
#define tGetValue 382
#define tGetEnv 383
#define tGetString 384
#define tHomology 385
#define tCohomology 386
#define tBetti 387
#define tSetOrder 388
#define tGMSH_MAJOR_VERSION 389
#define tGMSH_MINOR_VERSION 390
#define tGMSH_PATCH_VERSION 391
#define tAFFECTDIVIDE 392
#define tAFFECTTIMES 393
#define tAFFECTMINUS 394
#define tAFFECTPLUS 395
#define tOR 396
#define tAND 397
#define tNOTEQUAL 398
#define tEQUAL 399
#define tGREATEROREQUAL 400
#define tLESSOREQUAL 401
#define UNARYPREC 402
#define tMINUSMINUS 403
#define tPLUSPLUS 404




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
#line 504 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 517 "Gmsh.tab.cpp"

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
#define YYLAST   8248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  170
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  454
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1580

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   404

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   155,     2,   165,     2,   154,     2,     2,
     160,   161,   152,   150,   166,   151,   164,   153,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     146,     2,   147,   141,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   162,     2,   163,   159,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   167,     2,   168,   169,     2,     2,     2,
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
     135,   136,   137,   138,   139,   140,   142,   143,   144,   145,
     148,   149,   156,   157,   158
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
    2554,  2559,  2566,  2573,  2575
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     171,     0,    -1,   172,    -1,     1,     6,    -1,    -1,   172,
     173,    -1,   176,    -1,   175,    -1,   194,    -1,   208,    -1,
     213,    -1,   217,    -1,   218,    -1,   219,    -1,   222,    -1,
     242,    -1,   243,    -1,   221,    -1,   220,    -1,   216,    -1,
     245,    -1,   147,    -1,   147,   147,    -1,    36,   160,     5,
     161,     6,    -1,    37,   160,     5,   161,     6,    -1,    36,
     160,     5,   161,   174,   258,     6,    -1,    36,   160,     5,
     166,   254,   161,     6,    -1,    37,   160,     5,   166,   254,
     161,     6,    -1,    36,   160,     5,   166,   254,   161,   174,
     258,     6,    -1,     4,     5,   167,   177,   168,     6,    -1,
      96,     4,   162,   246,   163,     6,    -1,    97,     4,   162,
     246,   163,     6,    -1,    -1,   177,   180,    -1,   177,   184,
      -1,   177,   187,    -1,   177,   189,    -1,   177,   190,    -1,
     246,    -1,   178,   166,   246,    -1,   246,    -1,   179,   166,
     246,    -1,    -1,    -1,     4,   181,   160,   178,   161,   182,
     167,   179,   168,     6,    -1,   258,    -1,   183,   166,   258,
      -1,    -1,   102,   160,   246,   166,   246,   166,   246,   161,
     185,   167,   183,   168,     6,    -1,   258,    -1,   186,   166,
     258,    -1,    -1,   103,   160,   246,   166,   246,   166,   246,
     166,   246,   161,   188,   167,   186,   168,     6,    -1,   104,
     167,   250,   168,   167,   250,   168,     6,    -1,   104,   167,
     250,   168,   167,   250,   168,   167,   250,   168,   167,   250,
     168,     6,    -1,    -1,   105,   191,   167,   179,   168,     6,
      -1,     7,    -1,   140,    -1,   139,    -1,   138,    -1,   137,
      -1,   158,    -1,   157,    -1,    53,   162,   196,   163,     6,
      -1,    54,   162,   199,   163,     6,    -1,     4,   192,   251,
       6,    -1,     4,   162,   163,   192,   251,     6,    -1,     4,
     162,   246,   163,   192,   246,     6,    -1,     4,   160,   246,
     161,   192,   246,     6,    -1,     4,   162,   167,   254,   168,
     163,   192,   251,     6,    -1,     4,   160,   167,   254,   168,
     161,   192,   251,     6,    -1,     4,   193,     6,    -1,     4,
     162,   246,   163,   193,     6,    -1,     4,     7,   259,     6,
      -1,     4,   164,     4,     7,   259,     6,    -1,     4,   162,
     246,   163,   164,     4,     7,   259,     6,    -1,     4,   164,
       4,   192,   246,     6,    -1,     4,   162,   246,   163,   164,
       4,   192,   246,     6,    -1,     4,   164,     4,   193,     6,
      -1,     4,   162,   246,   163,   164,     4,   193,     6,    -1,
       4,   164,   112,   164,     4,     7,   255,     6,    -1,     4,
     162,   246,   163,   164,   112,   164,     4,     7,   255,     6,
      -1,     4,   164,   113,     7,   256,     6,    -1,     4,   162,
     246,   163,   164,   113,     7,   256,     6,    -1,     4,   121,
       7,   246,     6,    -1,   121,   162,   246,   163,     7,     4,
       6,    -1,   121,   162,   246,   163,   164,     4,     7,   246,
       6,    -1,   121,   162,   246,   163,   164,     4,     7,   259,
       6,    -1,   121,   162,   246,   163,   164,     4,     7,   167,
     254,   168,     6,    -1,   121,   162,   246,   163,   164,     4,
       6,    -1,    78,   160,     4,   161,   164,     4,     7,   246,
       6,    -1,    78,   160,     4,   161,   164,     4,     7,   259,
       6,    -1,    -1,   166,    -1,    -1,   196,   195,     4,    -1,
     196,   195,     4,     7,   246,    -1,    -1,   196,   195,     4,
       7,   167,   246,   197,   201,   168,    -1,   196,   195,     4,
       7,   259,    -1,    -1,   196,   195,     4,     7,   167,   259,
     198,   203,   168,    -1,    -1,   199,   195,   258,    -1,   246,
       7,   259,    -1,   200,   166,   246,     7,   259,    -1,    -1,
     201,   202,    -1,   166,     4,   251,    -1,   166,     4,   167,
     200,   168,    -1,   166,     4,     5,    -1,    -1,   203,   204,
      -1,   166,     4,   246,    -1,   166,     4,     5,    -1,   166,
       4,   167,   260,   168,    -1,   246,    -1,   259,    -1,    -1,
     115,    59,   167,   246,   168,    -1,    -1,    70,   248,    -1,
      55,   160,   246,   161,     7,   248,     6,    -1,    -1,    74,
      55,   209,   160,   205,   161,     7,   251,     6,    -1,    64,
      65,   251,     7,   246,     6,    -1,    58,   160,   246,   161,
       7,   251,     6,    -1,    79,    58,   251,     6,    -1,    62,
     160,   246,   161,     7,   251,     6,    -1,    56,   160,   246,
     161,     7,   251,   207,     6,    -1,    57,   160,   246,   161,
       7,   251,   207,     6,    -1,   107,   160,   246,   161,     7,
     251,     6,    -1,   108,   160,   246,   161,     7,   251,     6,
      -1,   109,   160,   246,   161,     7,   251,   111,   251,   110,
     246,     6,    -1,    58,     4,   160,   246,   161,     7,   251,
       6,    -1,    75,    58,   160,   246,   161,     7,   251,     6,
      -1,    -1,    74,    58,   210,   160,   205,   161,     7,   251,
       6,    -1,    70,    61,   160,   246,   161,     7,   251,     6,
      -1,    71,    61,   160,   246,   161,     7,   251,   206,     6,
      -1,    12,    13,     6,    -1,    13,    61,   246,     6,    -1,
      66,    61,   160,   246,   161,     7,     5,     5,     5,     6,
      -1,    59,   160,   246,   161,     7,   251,     6,    -1,    60,
     160,   246,   161,     7,   251,     6,    -1,    61,     4,   160,
     246,   161,     7,   251,     6,    -1,    75,    61,   160,   246,
     161,     7,   251,     6,    -1,    75,    61,   160,   246,   161,
       7,   251,     4,   167,   250,   168,     6,    -1,    -1,    74,
      61,   211,   160,   205,   161,     7,   251,     6,    -1,    73,
      63,   160,   246,   161,     7,   251,     6,    -1,    63,   160,
     246,   161,     7,   251,     6,    -1,    75,    63,   160,   246,
     161,     7,   251,     6,    -1,    -1,    74,    63,   212,   160,
     205,   161,     7,   251,     6,    -1,    81,   248,   167,   214,
     168,    -1,    80,   167,   248,   166,   248,   166,   246,   168,
     167,   214,   168,    -1,    82,   248,   167,   214,   168,    -1,
      83,   167,   248,   166,   246,   168,   167,   214,   168,    -1,
      83,   167,   248,   166,   248,   168,   167,   214,   168,    -1,
       4,   167,   214,   168,    -1,    91,    58,   167,   254,   168,
      61,   167,   246,   168,    -1,    88,    58,   160,   246,   161,
     167,   254,   168,     6,    -1,   215,    -1,   213,    -1,    -1,
     215,   208,    -1,   215,    55,   167,   254,   168,     6,    -1,
     215,    58,   167,   254,   168,     6,    -1,   215,    61,   167,
     254,   168,     6,    -1,   215,    63,   167,   254,   168,     6,
      -1,    85,    70,   160,   246,   161,     7,   251,     6,    -1,
      85,    55,   160,   246,   161,     7,   167,   250,   168,     6,
      -1,    85,    70,   160,   246,   161,     7,   167,   248,   166,
     248,   166,   254,   168,     6,    -1,    85,    70,   160,   246,
     161,     7,   167,   248,   166,   248,   166,   248,   166,   254,
     168,     6,    -1,    85,    59,   160,   246,   161,     7,   167,
     248,   166,   254,   168,     6,    -1,    85,     4,   160,   246,
     161,     7,   251,     6,    -1,    85,     4,   160,   246,   161,
       7,     5,     6,    -1,    85,     4,   167,   246,   168,     6,
      -1,    85,     4,   160,   246,   161,     7,   167,   248,   166,
     248,   166,   254,   168,     6,    -1,    89,   167,   215,   168,
      -1,    89,   121,   162,   246,   163,     6,    -1,    89,     4,
     162,   246,   163,     6,    -1,    89,     4,     6,    -1,    89,
       4,     4,     6,    -1,   112,   255,   167,   215,   168,    -1,
     125,     5,     6,    -1,   126,     5,     6,    -1,   125,   167,
     215,   168,    -1,   126,   167,   215,   168,    -1,     4,   259,
       6,    -1,     4,     4,   162,   246,   163,   258,     6,    -1,
       4,     4,     4,   162,   246,   163,     6,    -1,     4,   246,
       6,    -1,    78,   160,     4,   161,   164,     4,     6,    -1,
     106,     4,     6,    -1,   119,     6,    -1,   120,     6,    -1,
      49,     6,    -1,    46,     6,    -1,    46,   167,   246,   166,
     246,   166,   246,   166,   246,   166,   246,   166,   246,   168,
       6,    -1,    47,     6,    -1,    50,     6,    -1,    51,     6,
      -1,    68,     6,    -1,    69,   167,   254,   168,   167,   254,
     168,   167,   250,   168,   167,   246,   166,   246,   168,     6,
      -1,   133,   246,     6,    -1,   114,   160,   246,     8,   246,
     161,    -1,   114,   160,   246,     8,   246,     8,   246,   161,
      -1,   114,     4,   115,   167,   246,     8,   246,   168,    -1,
     114,     4,   115,   167,   246,     8,   246,     8,   246,   168,
      -1,   116,    -1,   124,     4,    -1,   122,    -1,   123,     4,
       6,    -1,   117,   160,   246,   161,    -1,   118,    -1,    84,
     248,   167,   215,   168,    -1,    84,   167,   248,   166,   248,
     166,   246,   168,   167,   215,   168,    -1,    84,   167,   248,
     166,   248,   166,   248,   166,   246,   168,   167,   215,   168,
      -1,    -1,    84,   248,   167,   215,   223,   236,   168,    -1,
      -1,    84,   167,   248,   166,   248,   166,   246,   168,   167,
     215,   224,   236,   168,    -1,    -1,    84,   167,   248,   166,
     248,   166,   248,   166,   246,   168,   167,   215,   225,   236,
     168,    -1,    -1,    84,   167,   215,   226,   236,   168,    -1,
      84,    55,   167,   246,   166,   248,   168,     6,    -1,    84,
      58,   167,   246,   166,   248,   168,     6,    -1,    84,    61,
     167,   246,   166,   248,   168,     6,    -1,    84,    55,   167,
     246,   166,   248,   166,   248,   166,   246,   168,     6,    -1,
      84,    58,   167,   246,   166,   248,   166,   248,   166,   246,
     168,     6,    -1,    84,    61,   167,   246,   166,   248,   166,
     248,   166,   246,   168,     6,    -1,    84,    55,   167,   246,
     166,   248,   166,   248,   166,   248,   166,   246,   168,     6,
      -1,    84,    58,   167,   246,   166,   248,   166,   248,   166,
     248,   166,   246,   168,     6,    -1,    84,    61,   167,   246,
     166,   248,   166,   248,   166,   248,   166,   246,   168,     6,
      -1,    -1,    84,    55,   167,   246,   166,   248,   168,   227,
     167,   236,   168,     6,    -1,    -1,    84,    58,   167,   246,
     166,   248,   168,   228,   167,   236,   168,     6,    -1,    -1,
      84,    61,   167,   246,   166,   248,   168,   229,   167,   236,
     168,     6,    -1,    -1,    84,    55,   167,   246,   166,   248,
     166,   248,   166,   246,   168,   230,   167,   236,   168,     6,
      -1,    -1,    84,    58,   167,   246,   166,   248,   166,   248,
     166,   246,   168,   231,   167,   236,   168,     6,    -1,    -1,
      84,    61,   167,   246,   166,   248,   166,   248,   166,   246,
     168,   232,   167,   236,   168,     6,    -1,    -1,    84,    55,
     167,   246,   166,   248,   166,   248,   166,   248,   166,   246,
     168,   233,   167,   236,   168,     6,    -1,    -1,    84,    58,
     167,   246,   166,   248,   166,   248,   166,   248,   166,   246,
     168,   234,   167,   236,   168,     6,    -1,    -1,    84,    61,
     167,   246,   166,   248,   166,   248,   166,   248,   166,   246,
     168,   235,   167,   236,   168,     6,    -1,   237,    -1,   236,
     237,    -1,    94,   167,   246,   168,     6,    -1,    94,   167,
     251,   166,   251,   168,     6,    -1,    94,   167,   251,   166,
     251,   166,   251,   168,     6,    -1,    86,     6,    -1,    98,
       6,    -1,    98,   100,     6,    -1,    99,     6,    -1,    99,
     100,     6,    -1,    95,   160,   246,   161,     7,   251,    77,
     246,     6,    -1,    77,     4,   162,   246,   163,     6,    -1,
      -1,    77,     4,   246,    -1,    -1,     4,    -1,    -1,     7,
     251,    -1,    -1,     7,   246,    -1,    72,    58,   252,     7,
     246,   238,     6,    -1,    72,    61,   252,   240,   239,     6,
      -1,    67,    61,   167,   246,   168,     7,   251,     6,    -1,
      72,    63,   252,   240,     6,    -1,   101,   252,     6,    -1,
      92,    61,   167,   254,   168,   246,     6,    -1,    86,    61,
     252,   241,     6,    -1,    86,    63,   252,     6,    -1,    87,
      61,   251,     7,   246,     6,    -1,    76,    58,   251,     7,
     251,     6,    -1,    76,    61,   246,   167,   254,   168,     7,
     246,   167,   254,   168,     6,    -1,    55,   167,   254,   168,
     115,    61,   167,   246,   168,     6,    -1,    58,   167,   254,
     168,   115,    61,   167,   246,   168,     6,    -1,    58,   167,
     254,   168,   115,    63,   167,   246,   168,     6,    -1,    61,
     167,   254,   168,   115,    63,   167,   246,   168,     6,    -1,
      93,    61,   252,     6,    -1,    93,    58,   252,     6,    -1,
      90,     6,    -1,    90,     4,     6,    -1,    90,    55,   167,
     254,   168,     6,    -1,   130,    -1,   131,    -1,   132,    -1,
     244,     6,    -1,   244,   167,   251,   168,     6,    -1,   244,
     167,   251,   166,   251,   168,     6,    -1,   244,   160,   251,
     161,   167,   251,   166,   251,   168,     6,    -1,   247,    -1,
     160,   246,   161,    -1,   151,   246,    -1,   150,   246,    -1,
     155,   246,    -1,   246,   151,   246,    -1,   246,   150,   246,
      -1,   246,   152,   246,    -1,   246,   153,   246,    -1,   246,
     154,   246,    -1,   246,   159,   246,    -1,   246,   146,   246,
      -1,   246,   147,   246,    -1,   246,   149,   246,    -1,   246,
     148,   246,    -1,   246,   145,   246,    -1,   246,   144,   246,
      -1,   246,   143,   246,    -1,   246,   142,   246,    -1,   246,
     141,   246,     8,   246,    -1,    14,   160,   246,   161,    -1,
      15,   160,   246,   161,    -1,    16,   160,   246,   161,    -1,
      17,   160,   246,   161,    -1,    18,   160,   246,   161,    -1,
      19,   160,   246,   161,    -1,    20,   160,   246,   161,    -1,
      21,   160,   246,   161,    -1,    22,   160,   246,   161,    -1,
      24,   160,   246,   161,    -1,    25,   160,   246,   166,   246,
     161,    -1,    26,   160,   246,   161,    -1,    27,   160,   246,
     161,    -1,    28,   160,   246,   161,    -1,    29,   160,   246,
     161,    -1,    30,   160,   246,   161,    -1,    31,   160,   246,
     161,    -1,    32,   160,   246,   166,   246,   161,    -1,    33,
     160,   246,   166,   246,   161,    -1,    34,   160,   246,   166,
     246,   161,    -1,    23,   160,   246,   161,    -1,    14,   162,
     246,   163,    -1,    15,   162,   246,   163,    -1,    16,   162,
     246,   163,    -1,    17,   162,   246,   163,    -1,    18,   162,
     246,   163,    -1,    19,   162,   246,   163,    -1,    20,   162,
     246,   163,    -1,    21,   162,   246,   163,    -1,    22,   162,
     246,   163,    -1,    24,   162,   246,   163,    -1,    25,   162,
     246,   166,   246,   163,    -1,    26,   162,   246,   163,    -1,
      27,   162,   246,   163,    -1,    28,   162,   246,   163,    -1,
      29,   162,   246,   163,    -1,    30,   162,   246,   163,    -1,
      31,   162,   246,   163,    -1,    32,   162,   246,   166,   246,
     163,    -1,    33,   162,   246,   166,   246,   163,    -1,    34,
     162,   246,   166,   246,   163,    -1,    23,   162,   246,   163,
      -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,   134,
      -1,   135,    -1,   136,    -1,     4,    -1,     4,   169,   167,
     246,   168,    -1,     4,   162,   246,   163,    -1,   165,     4,
     162,   163,    -1,     4,   193,    -1,     4,   162,   246,   163,
     193,    -1,     4,   164,     4,    -1,     4,   162,   246,   163,
     164,     4,    -1,     4,   164,     4,   193,    -1,     4,   162,
     246,   163,   164,     4,   193,    -1,   127,   160,   258,   166,
     246,   161,    -1,    43,   160,   258,   166,   258,   161,    -1,
      44,   160,   258,   166,   258,   161,    -1,    45,   160,   260,
     161,    -1,   249,    -1,   151,   248,    -1,   150,   248,    -1,
     248,   151,   248,    -1,   248,   150,   248,    -1,   167,   246,
     166,   246,   166,   246,   166,   246,   166,   246,   168,    -1,
     167,   246,   166,   246,   166,   246,   166,   246,   168,    -1,
     167,   246,   166,   246,   166,   246,   168,    -1,   160,   246,
     166,   246,   166,   246,   161,    -1,   251,    -1,   250,   166,
     251,    -1,   246,    -1,   253,    -1,   167,   168,    -1,   167,
     254,   168,    -1,   151,   167,   254,   168,    -1,   246,   152,
     167,   254,   168,    -1,   251,    -1,     5,    -1,   151,   253,
      -1,   246,   152,   253,    -1,   246,     8,   246,    -1,   246,
       8,   246,     8,   246,    -1,    55,   167,   246,   168,    -1,
      55,     5,    -1,    58,     5,    -1,    61,     5,    -1,    63,
       5,    -1,    74,    55,   167,   254,   168,    -1,    74,    58,
     167,   254,   168,    -1,    74,    61,   167,   254,   168,    -1,
      74,    63,   167,   254,   168,    -1,   213,    -1,   222,    -1,
       4,   162,   163,    -1,     4,   160,   161,    -1,    35,   162,
       4,   163,    -1,     4,   162,   167,   254,   168,   163,    -1,
       4,   160,   167,   254,   168,   161,    -1,   246,    -1,   253,
      -1,   254,   166,   246,    -1,   254,   166,   253,    -1,   167,
     246,   166,   246,   166,   246,   166,   246,   168,    -1,   167,
     246,   166,   246,   166,   246,   168,    -1,     4,    -1,     4,
     164,   112,   164,     4,    -1,   167,   257,   168,    -1,     4,
     162,   246,   163,   164,   113,    -1,   255,    -1,   257,   166,
     255,    -1,   259,    -1,     4,    -1,     4,   164,     4,    -1,
       4,   162,   246,   163,   164,     4,    -1,     5,    -1,    48,
      -1,   128,   160,   258,   161,    -1,   129,   160,   258,   166,
     258,   161,    -1,    39,   160,   258,   166,   258,   161,    -1,
      40,   160,   258,   161,    -1,    41,   160,   258,   161,    -1,
      42,   160,   258,   166,   258,   166,   258,   161,    -1,    38,
     160,   258,   161,    -1,    38,   162,   258,   163,    -1,    38,
     160,   258,   166,   254,   161,    -1,    38,   162,   258,   166,
     254,   163,    -1,   258,    -1,   260,   166,   258,    -1
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
    4947,  4958,  4962,  4970,  4978,  4986,  4994,  5008,  5022,  5035,
    5040,  5044,  5064,  5086,  5091
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
  "tList", "tPrintf", "tError", "tSprintf", "tStrCat", "tStrPrefix",
  "tStrRelative", "tStrReplace", "tStrFind", "tStrCmp", "tTextAttributes",
  "tBoundingBox", "tDraw", "tToday", "tSyncModel", "tCreateTopology",
  "tCreateTopologyNoHoles", "tDistanceFunction", "tDefineConstant",
  "tUndefineConstant", "tPoint", "tCircle", "tEllipse", "tLine", "tSphere",
  "tPolarSphere", "tSurface", "tSpline", "tVolume", "tCharacteristic",
  "tLength", "tParametric", "tElliptic", "tRefineMesh", "tAdaptMesh",
  "tPlane", "tRuled", "tTransfinite", "tComplex", "tPhysical", "tCompound",
  "tPeriodic", "tUsing", "tPlugin", "tDegenerated", "tRotate",
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
     395,    63,   396,   397,   398,   399,    60,    62,   400,   401,
      43,    45,    42,    47,    37,    33,   402,   403,   404,    94,
      40,    41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   170,   171,   171,   172,   172,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   174,   174,   175,   175,   175,   175,   175,   175,   176,
     176,   176,   177,   177,   177,   177,   177,   177,   178,   178,
     179,   179,   181,   182,   180,   183,   183,   185,   184,   186,
     186,   188,   187,   189,   189,   191,   190,   192,   192,   192,
     192,   192,   193,   193,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   195,   195,   196,   196,   196,   197,   196,
     196,   198,   196,   199,   199,   200,   200,   201,   201,   202,
     202,   202,   203,   203,   204,   204,   204,   205,   205,   206,
     206,   207,   207,   208,   209,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   210,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   211,
     208,   208,   208,   208,   212,   208,   213,   213,   213,   213,
     213,   213,   213,   213,   214,   214,   215,   215,   215,   215,
     215,   215,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   217,   217,   217,   217,   217,   218,   219,   219,   219,
     219,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   222,   222,
     222,   223,   222,   224,   222,   225,   222,   226,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   227,   222,
     228,   222,   229,   222,   230,   222,   231,   222,   232,   222,
     233,   222,   234,   222,   235,   222,   236,   236,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   238,   238,
     239,   239,   240,   240,   241,   241,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   243,   243,   243,   244,   244,   244,   245,
     245,   245,   245,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   248,   248,   248,   248,
     248,   249,   249,   249,   249,   250,   250,   251,   251,   251,
     251,   251,   251,   252,   252,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   254,   254,   254,   254,   255,
     255,   255,   255,   256,   256,   257,   257,   258,   258,   258,
     258,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   260,   260
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
       4,     6,     6,     1,     3
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
       0,     0,   442,     0,     0,     0,     0,   369,   370,   371,
      61,    60,    59,    58,     0,     0,     0,    63,    62,     0,
       0,     0,     0,   166,     0,     0,     0,   303,     0,     0,
       0,     0,     0,   200,     0,   202,   199,   203,   204,    95,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,     0,     0,
       0,     0,     0,     0,     0,   124,   137,   149,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   386,     0,     0,     0,     0,     0,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     166,     0,   293,     0,     0,     0,     0,     0,     0,     0,
     372,   404,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   418,   419,   397,   403,     0,   398,     0,     0,     0,
       0,   431,     0,     0,     0,     0,     0,   197,   198,     0,
       0,   213,     0,   166,     0,   166,   372,     0,   299,     0,
       0,     0,     0,     0,     0,   376,    32,   441,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   306,   305,   307,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,     0,   164,
       0,    72,   194,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,   141,
       0,     0,     0,     0,    93,    93,     0,     0,   425,   426,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
     272,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   388,   387,     0,     0,     0,     0,
     166,   166,     0,     0,     0,     0,     0,     0,     0,   227,
       0,   166,     0,     0,     0,     0,     0,   274,     0,     0,
       0,     0,   184,     0,     0,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   410,     0,   411,
     412,   413,     0,     0,     0,     0,     0,   305,   405,     0,
     399,     0,     0,     0,   280,   196,     0,     0,     0,     0,
       0,   166,     0,     0,     0,     0,   215,   187,     0,   188,
       0,     0,   207,     0,     0,     0,     0,   378,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   438,     0,   437,     0,     0,     0,     0,
       0,     0,     0,   453,     0,     0,     0,     0,     0,     0,
     304,    57,     0,     0,     0,    57,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,   167,    66,     0,   321,
     320,   319,   318,   314,   315,   317,   316,   309,   308,   310,
     311,   312,   313,   142,     0,     0,     0,     0,     0,     0,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,     0,     0,   390,   389,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   221,     0,     0,     0,     0,
       0,     0,     0,   283,     0,     0,   185,     0,     0,   181,
       0,     0,     0,   292,   291,     0,     0,   421,     0,   420,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   304,
     400,   407,     0,   310,   406,     0,     0,     0,     0,     0,
       0,     0,     0,   216,     0,   189,   190,     0,     0,     0,
       0,   374,   380,     0,    42,     0,     0,     0,    55,     0,
      33,    34,    35,    36,    37,   323,   344,   324,   345,   325,
     346,   326,   347,   327,   348,   328,   349,   329,   350,   330,
     351,   331,   352,   343,   364,   332,   353,     0,     0,   334,
     355,   335,   356,   336,   357,   337,   358,   338,   359,   339,
     360,     0,     0,     0,     0,     0,     0,     0,     0,   449,
       0,   450,     0,     0,   446,   447,     0,     0,     0,   385,
       0,    85,     0,   443,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,    23,    21,     0,     0,    24,
       0,     0,    64,    96,    65,   104,     0,   427,   428,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   273,   271,
       0,   279,     0,     0,   117,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,     0,   218,     0,     0,     0,     0,     0,
       0,   275,   282,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   374,   422,   409,     0,     0,     0,
       0,   401,     0,     0,     0,     0,     0,     0,     0,   186,
       0,     0,     0,     0,     0,     0,   300,     0,     0,   377,
       0,   373,     0,     0,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,   454,     0,     0,     0,     0,    67,
       0,     0,     0,     0,     0,    73,    75,    77,     0,     0,
     435,     0,    83,     0,     0,     0,     0,   322,    22,     0,
       0,     0,     0,     0,     0,     0,   121,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,     0,   277,     0,     0,     0,
       0,     0,     0,     0,     0,   285,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   261,     0,     0,
     262,     0,   264,     0,   228,   257,     0,     0,     0,   179,
       0,     0,     0,   284,     0,   183,   182,   295,     0,     0,
      30,    31,     0,     0,   414,   415,   416,   417,   408,   402,
       0,     0,     0,   432,     0,     0,     0,   208,     0,     0,
       0,     0,   193,   379,   192,     0,     0,     0,     0,   395,
       0,   333,   354,   340,   361,   341,   362,   342,   363,     0,
     451,   452,   445,     0,   383,   384,   382,   444,     0,    69,
       0,    57,     0,     0,     0,     0,    68,     0,     0,     0,
     433,     0,     0,     0,     0,    25,    26,     0,    27,     0,
       0,    97,   100,   123,     0,     0,     0,     0,     0,   127,
       0,     0,   144,   145,     0,     0,   129,   152,     0,     0,
       0,     0,   119,     0,   276,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   195,     0,     0,     0,     0,   166,
     166,     0,   238,     0,   240,     0,   242,     0,   397,     0,
       0,   263,   265,     0,     0,   222,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   281,   424,   423,   132,   133,
       0,     0,     0,     0,    86,    90,     0,     0,   301,   381,
       0,    38,     0,     0,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,    80,     0,     0,    81,     0,   436,
     168,   169,   170,   171,     0,     0,    98,   101,     0,   122,
     130,   131,   135,     0,     0,   146,     0,     0,   278,     0,
     139,     0,     0,   269,   151,     0,     0,     0,     0,   136,
       0,   147,   153,     0,     0,     0,     0,   394,     0,   393,
       0,     0,     0,   229,     0,     0,   230,     0,     0,   231,
       0,     0,     0,     0,     0,     0,     0,   178,     0,     0,
     177,     0,     0,     0,   172,     0,     0,     0,     0,   430,
       0,   210,   209,     0,     0,     0,     0,    43,     0,     0,
       0,   396,     0,     0,     0,   440,   448,    71,    70,    76,
      78,     0,    84,     0,    28,     0,   107,   112,     0,     0,
       0,     0,     0,     0,     0,   140,   125,   138,   150,   155,
       0,     0,    91,    92,   166,     0,   159,   160,     0,     0,
       0,     0,     0,     0,     0,   258,     0,     0,   166,     0,
       0,     0,     0,     0,   163,   162,     0,     0,     0,     0,
      87,    88,     0,     0,    39,     0,     0,     0,    41,    56,
       0,   434,     0,     0,     0,   287,   288,   289,   290,   143,
       0,     0,     0,     0,     0,     0,   392,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,     0,     0,     0,
     223,     0,     0,   173,     0,     0,     0,   429,   211,     0,
     302,     0,     0,     0,     0,    82,     0,     0,    99,   108,
       0,   102,   113,     0,     0,     0,     0,   157,     0,   244,
       0,     0,   246,     0,     0,   248,     0,     0,     0,   259,
       0,   219,     0,   166,     0,     0,     0,   134,    89,     0,
      47,     0,    53,     0,     0,     0,     0,     0,   120,   148,
     286,   391,   232,     0,     0,   239,   233,     0,     0,   241,
     234,     0,     0,   243,     0,     0,     0,   225,     0,   176,
       0,     0,     0,     0,     0,     0,     0,   111,     0,   109,
     115,     0,   114,     0,     0,   250,     0,   252,     0,   254,
     260,   266,   224,   220,     0,     0,     0,     0,    44,     0,
      51,     0,     0,     0,   425,     0,     0,     0,   235,     0,
       0,   236,     0,     0,   237,     0,     0,   180,     0,   174,
       0,    45,     0,     0,   201,     0,   110,     0,   116,     0,
       0,     0,     0,     0,     0,     0,   226,     0,     0,     0,
       0,     0,     0,   105,   206,   245,     0,   247,     0,   249,
       0,   175,    46,    48,     0,    49,     0,     0,     0,     0,
       0,     0,     0,    54,   106,   251,   253,   255,    50,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    79,   817,    80,    81,   509,  1200,  1206,
     730,   932,  1363,  1530,   731,  1483,  1564,   732,  1532,   733,
     734,   936,   154,   285,    82,   611,   384,  1316,  1317,   385,
    1513,  1373,  1419,  1374,  1422,   853,  1242,  1126,   586,   412,
     413,   414,   415,   251,   358,   359,    85,    86,    87,    88,
      89,    90,   252,   885,  1442,  1504,   663,  1264,  1267,  1270,
    1463,  1467,  1471,  1519,  1522,  1525,   881,   882,  1005,   850,
     637,   672,    92,    93,    94,    95,   253,   157,   425,   212,
    1078,   254,   255,   256,   481,   263,   808,   971,   563,   555,
     564
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1177
static const yytype_int16 yypact[] =
{
    4499,    54,    55,  4590, -1177, -1177,  2160,    74,   -50,   -86,
     -77,    36,    85,    97,   106,   126,   -41,    51,   115,    65,
      80,    24,    84,    95,    26,   112,   124,   127,    99,   104,
     334,   183,   325,   329,   165,   345,   218,   471,    98,   268,
     339,   306,    92,    92,   333,   -37,    76,   -22,   384,   434,
      28,    69,   446,   450,   225,   511,   563,  2325,   600,   447,
     452,   455,    29,    49, -1177,   462, -1177,   615,   619,   466,
   -1177,   628,   645,    18,    33, -1177, -1177, -1177,  4268, -1177,
   -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177,
   -1177, -1177, -1177, -1177,     1, -1177, -1177,    25,   495,   449,
   -1177, -1177, -1177,  -111,   184,   264,   277,   336,   359,   375,
     419,   456,   514,   542,   587,   598,   601,   605,   606,   617,
     621,   626,   635,   642,   654,   519,   523,   536,   543,   559,
     568,   571, -1177,   733,   584,   590,   591, -1177, -1177, -1177,
   -1177, -1177, -1177, -1177,  4268,  4268,  4268, -1177, -1177,  3876,
    2080,    16,   750,   482,  2802,   776,   902, -1177,   779,   785,
    4268,   757,   771, -1177,  4268, -1177, -1177, -1177, -1177, -1177,
   -1177,  4268,  4072,  4268,  4268,   632,  4268,  4072,  4268,  4268,
     636,  4072,  4268,  4268,  2802,   641,   639, -1177,  4072,   653,
     673,  2325,  2325,  2325,   674, -1177, -1177, -1177, -1177,   680,
     687,   688,  2802,  4268,   847,  2802,    92,    92,    92,  4268,
    4268,  -106, -1177,   -65,    92,   640,   691,   695,  4035,   -14,
     118,   703,   711,   712,  2325,  2325,  2802,   716,    48,   693,
   -1177,   871, -1177,   728,   736,   737,  2325,  2325,   738,   745,
     520, -1177,   764,    35,   913,   925,   938,   278,  2961,  4268,
    1994, -1177, -1177,  3552, -1177,   905, -1177,   933,  4268,  4268,
    4268,   765,  4268,   777,   832,  4268,  4268, -1177, -1177,  4268,
     954, -1177,   973, -1177,   990, -1177,   595,  1088, -1177,  2802,
    2802,   799,  4268,   961,   815, -1177, -1177, -1177,   991,  4268,
    4268,  4268,  4268,  4268,  4268,  4268,  4268,  4268,  4268,  4268,
    4268,  4268,  4268,  4268,  4268,  4268,  4268,  4268,  4268,  4268,
    4268,  4268,  4268,  4268,  4268,  4268,  4268,  4268,  4268,  4268,
    4268,  4268,  4268,  4268,  4268,  4268,  4268,  4268,  4268,  4268,
    4268,   379,   379,   379,   379,   379,   379,   379,   379,   379,
    4268,   379,   379,   379,   841,   841,   841,  4072,  6934,   131,
    4072,  6175,   242,   845,   998,   853,   858, -1177,   862,  4351,
    1034, -1177, -1177,  4268,  4268,  4268,  4268,  4268,  4268,  4268,
    4268,  4268,  4268,  4268,  4268,  4268,  4268,  4268, -1177, -1177,
    1433,   -39,   -21,  5447,   316,   382,  6955,  4072,  4173, -1177,
     386,  6976,  6997,  4268,  7018,   491,  7039,  7060,  4268,   671,
    7081,  7102,  1069,  4268,  4268,   678,  4268,  4268,  1074,  1086,
    1086,  4268,   941,   952,   960,   979,  4268,  4268,  4268,  1091,
    5367,   985,  1141,     0, -1177, -1177,  5473,  5499,    92,    92,
     482,   482,   100,  4268,  4268,  4268,  4035,  4035,  4268,  4351,
     237, -1177,  4268,  4268,  4268,  4268,  4268,  1143,  1142,  1145,
    4268,  1148, -1177,  4268,  4268,   928, -1177,  4072,  4072,  4072,
    1149,  1150,  4268,  4268,  -130,  3802,  1153, -1177,  4268, -1177,
   -1177, -1177,   994,   996,   997,   999,  4072,   841, -1177,  7123,
   -1177,   701,  4268,  3120, -1177, -1177,  7144,  7165,  7186,  1055,
    5525, -1177,  1001,  4196,  7207,  6198, -1177, -1177,  1464, -1177,
    1803,  4268, -1177,  1008,   702,  4268,  6221,   202,  4268,     5,
   -1177,  7228,  6244,  7249,  6267,  7270,  6290,  7291,  6313,  7312,
    6336,  7333,  6359,  7354,  6382,  7375,  6405,  7396,  6428,  7417,
    6451,  7438,  6474,  5551,  5577,  7459,  6497,  7480,  6520,  7501,
    6543,  7522,  6566,  7543,  6589,  7564,  6612,  5603,  5629,  5655,
    5681,  5707,  5733,   734,    56, -1177,   405,  1007,  1013,  1015,
    1011,  1012,  1014, -1177,    70,  1459,  1017,  1020,  1018,   748,
     131, -1177,  2802,   749,    81,   449,  4268,  1179,  1182,    31,
    1024, -1177,   170,    30,    32,   175, -1177, -1177,  4295,  1172,
    1532,   957,   957,   562,   562,   562,   562,   -75,   -75,   841,
     841,   841,   841, -1177,     8,  4072,  1183,  4072,  4268,  1185,
   -1177,  1184,  1186,   379,  1188,  4072,  4072,  1078,  1189,  1190,
    7585,  1191,  1084,  1195,  1197,  7606,  1092,  1199,  1202,  4268,
    7627,  4667,  1044,  7648,  7669,  4268,  2802,  1209,  1208,  7690,
    4225,  4225,  4225,  4225,  7711,  7732,  7753,  2802,  4072,  1051,
   -1177,    92,  4268,  4268, -1177, -1177,  1048,  1050,  4035,  5759,
    5785,  5811,  5421,   312,    92,  1867,  7774,  4695,  7795,  7816,
    7837,  4268,  1214, -1177,  4268,  7858, -1177,  6635,  6658, -1177,
     756,   759,   767, -1177, -1177,  6681,  6704, -1177,  4072, -1177,
    4072,  6727,  1058,  4723,  4072,  4072,  4072,  4072,   770, -1177,
   -1177,  4320,  4072,   841, -1177,  1215,  1218,  1237,  1082,  4268,
    2197,  4268,  4268, -1177,     3, -1177, -1177,  1081,  2802,  1247,
    6750,    77, -1177,  4751, -1177,  1094,  1095,  1096, -1177,  1252,
   -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177,
   -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177,
   -1177, -1177, -1177, -1177, -1177, -1177, -1177,  4268,  4268, -1177,
   -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177,
   -1177,  4268,  4268,  4268,  4268,  4268,  4268,  4268,  1255, -1177,
    4072, -1177,  4072,   379, -1177, -1177,   379,   379,   379, -1177,
     379, -1177,  4268, -1177,   379,  1100,  4268,  1256,  1101,    21,
    4268,  1259,  1260,  1642, -1177,  1261,  1105,    29,  1264, -1177,
    4072,  4072,  4072,  4072,  4268, -1177,  1124,   379,   192, -1177,
     292,  5837, -1177,  1266, -1177, -1177,    92,  4173, -1177,  1216,
    2802,  2802,  1268,  2802,   890,  2802,  2802,  1271,  1219,  2802,
    2802,  1749,  1272,  1274,  4072,  1276,  1277,  4373, -1177, -1177,
    1279, -1177,  1280,  1128,  8089, -1177,  1129,  1131,  1132,  1287,
    1288,  1290,  1292,   786,  1295,   272,  5863,  5889, -1177, -1177,
    4779,  -104,    92,    92,    92,  1299,  1298,  1138,  1152,    11,
      20,   -29, -1177,   296, -1177,   312,  1303,  1321,  1323,  1325,
    1332,  8089, -1177,  1807,  1161,  1335,  1336,  1337,  1283,  4268,
    1339,  1340,   789,   790,   444, -1177, -1177,   798,   802,   803,
     806, -1177,  4268,   807,  2802,  2802,  2802,  1343,  5915, -1177,
    4343,   740,  1344,  1345,  2802,  1187, -1177,  1346,  1349, -1177,
    1350, -1177,  1198,  4268,  4268,  2802,  1192, -1177,  7879,  6773,
    7900,  6796,  7921,  6819,  7942,  6842,  6865, -1177,   378,   409,
    1196,  1194,  1200,  1201, -1177,  7963,  1210,   131,  1841, -1177,
     131,   255,  1205,  1365,  2595, -1177, -1177, -1177,    29,  4268,
   -1177,   810, -1177,   827,   838,   842,   855,  8089, -1177,  1367,
      10,  1368,  4268,  3597,    13,  1211,  1305,  1305,  2802,  1370,
    1213,  1217,  1371,  1375,  2802,  1221,  1376,  1380, -1177,  1385,
    2802,   856,  2802,  2802,  1387,  1389, -1177,  2802,  1386,  1391,
    1394,  1395,  2802,  2802,  2802, -1177,  1396,   371,  4268,  4268,
    4268,  1229,  1238,    61,    64,   181,  1242, -1177,  2802,  4268,
   -1177,  1400, -1177,  1401, -1177, -1177,  4035,   -27,  2484, -1177,
    1241,  1243,  3279, -1177,  4072, -1177, -1177, -1177,  1244,  2615,
   -1177, -1177,  1251,  1250, -1177, -1177, -1177, -1177,  8089, -1177,
    1408,  1409,  1306, -1177,  4268,  4268,  4268, -1177,  1410,   458,
    1253,  1412, -1177,   202, -1177,  4268,  5941,  5967,   873, -1177,
    4268, -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177,  1262,
   -1177, -1177, -1177,   379, -1177, -1177, -1177, -1177,  2802, -1177,
    2802,   449,  4268,  1414,  1423,    31, -1177,  1424,  6888,    29,
   -1177,  1426,  1427,  1429,  1430, -1177, -1177,   379, -1177,  5993,
    4225,  8089, -1177, -1177,  4268,    92,  1431,  1434,  1435, -1177,
    4268,  4268, -1177, -1177,  1437,  4268, -1177, -1177,  1440,  1441,
    1281,  1444,  1314,  4268, -1177,  1445,  2802,  2802,  2802,  2802,
    1447,  1053,  1449,  4268, -1177,  4225,  4807,  7984,  4583,   482,
     482,    92,  1451,    92,  1452,    92,  1453,  4268,   441,  1294,
    8005, -1177, -1177,  4835,   319, -1177,  1455,  1684,  1456,  2802,
      92,  1684,  1461,   892,  4268, -1177, -1177, -1177, -1177, -1177,
    2802,  4611,   677,  8026, -1177, -1177,  3643,  2802, -1177, -1177,
     400,  8089,  4268,  4268,  2802,  1304,   899,  8089,  1442,  1309,
    1468,  1469,  1472,  2765, -1177,  1473,  1475, -1177,  1315, -1177,
   -1177, -1177, -1177, -1177,  1476,  4268,  8089, -1177,  4863,   515,
   -1177, -1177, -1177,  4891,  4919, -1177,  4947,  1478, -1177,  2802,
   -1177,  1425,  1479,  8089, -1177,  1481,  1482,  1483,  1484, -1177,
    1327, -1177, -1177,  5394,  2914,  1486,  1328, -1177,  4268, -1177,
    1329,  1330,   327, -1177,  1333,   344, -1177,  1334,   351, -1177,
    1338,  6911,  1490,  2802,  1492,  1341,  4268, -1177,  3438,   362,
   -1177,   900,   374,   392, -1177,  1496,  4975,  1393,  4268, -1177,
    4268, -1177, -1177,  4072,  2933,  1500,  1342, -1177,  4268,  6019,
    6045, -1177,  2802,  4268,  1501, -1177, -1177, -1177, -1177, -1177,
   -1177,    29, -1177,  1398, -1177,  6071, -1177, -1177,  1503,  1506,
    1507,  1508,  1509,   906,  1351, -1177, -1177, -1177, -1177, -1177,
    2802,  4072, -1177, -1177,   482,  4639, -1177, -1177,  4035,   312,
    4035,   312,  4035,   312,  1510, -1177,   911,  2802, -1177,  5003,
      92,  1511,  4072,    92, -1177, -1177,  4268,  5031,  5059,   914,
   -1177, -1177,  1523,  1369,  8089,  4268,  4268,   918,  8089, -1177,
    1526, -1177,  4268,   919,   923, -1177, -1177, -1177, -1177, -1177,
    1373,  4268,   924,   931,  1374,  4268, -1177,  5087,   460,   257,
    5115,   494,   373,  5143,   497,   428, -1177,  2802,  1535,  1467,
    2362,  1378,   502, -1177,   947,   504,  3083, -1177, -1177,  1540,
   -1177,  4268,  8047,  6097,    37, -1177,  6123,  1546, -1177, -1177,
    1547, -1177, -1177,  4268,  5171,  1548,  1549, -1177,  5199,  1550,
    4268,  1552,  1553,  4268,  1554,  1556,  4268,  1557,  1384, -1177,
    4268, -1177,   312, -1177,  4072,  1558,  3438, -1177, -1177,   951,
   -1177,  4268, -1177,  2802,  4268,  2643,  3839,  6149, -1177, -1177,
   -1177, -1177, -1177,  1399,  5227, -1177, -1177,  1402,  5255, -1177,
   -1177,  1403,  5283, -1177,  1559,  3232,   461,  2521,   955, -1177,
     540,   958,  1561,  1421,  8068,   959,  5311, -1177,  1994, -1177,
   -1177,   379,  8089,  4268,   312,  1583,   312,  1584,   312,  1585,
   -1177, -1177, -1177, -1177,   312,  1587,  4072,  1588, -1177,   379,
   -1177,  1428,  1590,   964,  3251,   968,  5339,   631, -1177,  1448,
     647, -1177,  1450,   755, -1177,  1457,   766, -1177,   969, -1177,
     972, -1177,  1458,  2802, -1177,  4268, -1177,   449, -1177,  1591,
    1592,   312,  1608,   312,  1610,   312, -1177,  1613,   379,  1614,
     379,   976,  3400, -1177, -1177, -1177,   780, -1177,   851, -1177,
     934, -1177, -1177, -1177,   977, -1177,  1616,   449,  1617,  1620,
    1622,   379,  1623, -1177, -1177, -1177, -1177, -1177, -1177, -1177
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1177, -1177, -1177, -1177,   573, -1177, -1177, -1177, -1177,   219,
   -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177, -1177,
   -1177, -1177,  -337,     2, -1177,  1246, -1177, -1177, -1177, -1177,
   -1177, -1177, -1177, -1177, -1177,    96, -1177,   650,  1631, -1177,
   -1177, -1177, -1177,    -1,  -425,  -217, -1177, -1177, -1177, -1177,
   -1177, -1177,  1635, -1177, -1177, -1177, -1177, -1177, -1177, -1177,
   -1177, -1177, -1177, -1177, -1177, -1177,  -823,  -859, -1177, -1177,
    1231, -1177, -1177, -1177, -1177, -1177,    -2, -1177,    47, -1177,
   -1176,   633,   406,   555,   612,  -780,   534, -1177,  -237,    -6,
     151
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     158,   439,    84,  1281,   156,   656,   657,   278,   155,   724,
     922,   160,   572,   455,   815,   576,  1116,  1030,   215,  1123,
     352,   216,  1035,   272,   217,   961,  1032,   970,   175,   281,
     180,   687,   228,   261,   175,   806,   180,   688,   274,   224,
     467,   225,   163,  1452,   428,   429,   428,   429,   875,   289,
     875,   290,   451,   264,   452,     5,   498,   876,   500,   876,
       4,   430,  1037,  1323,  1022,   877,   878,   877,   878,   879,
     880,   879,   880,   231,   161,   232,   277,   374,   375,   376,
     220,   553,   287,   162,   377,   428,   429,   159,   571,   211,
     213,   165,   219,   288,   554,   556,   557,   558,   559,   560,
     561,   562,   431,   166,   566,   567,   568,   725,   726,   727,
     728,  1031,   167,   207,   208,   124,   125,   126,   127,   128,
    1033,   169,   604,   209,   233,   132,  1367,   605,   353,   354,
     218,   221,   168,   962,   963,   222,   428,   429,   571,  1034,
     606,  1175,   344,   345,   346,   607,   223,   348,   351,   229,
     428,   429,   357,   441,  1382,   816,   202,   816,   380,   203,
     185,   279,   383,   428,   429,   186,   651,   923,   280,   386,
     388,   391,   392,   729,   394,   388,   396,   397,  1035,   388,
     400,   401,   147,   148,   176,   273,   388,   282,  1107,   283,
     176,   177,   184,   181,   284,   230,   262,   811,   807,   812,
     275,   420,   468,   164,  1453,   135,   136,   426,   427,   265,
     453,   428,   429,   170,   428,   429,   427,   779,   140,   141,
     142,   143,   780,   191,   665,   173,   192,  1161,   193,  1162,
    1163,   789,  1164,   796,   147,   148,   790,   800,   147,   148,
     174,   928,   207,   208,   178,   799,   477,   479,   388,   575,
     428,   429,   209,   423,   424,   179,   486,   487,   488,   210,
     490,   432,  1101,   493,   494,   440,   658,   495,   140,   141,
     142,   143,   182,   195,   710,   171,   196,  1485,   442,   197,
     506,   198,   172,   236,   183,   443,   237,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,  1219,
     171,   428,   429,   472,   875,   183,   473,   810,   565,   474,
     187,   475,   813,   876,   291,   388,   292,  1165,   388,  1166,
     188,   877,   878,   980,   577,   879,   880,  1551,   616,   147,
     148,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   825,  1154,  1155,   140,
     141,   142,   143,   553,   287,   477,   189,   428,   429,   875,
     190,   620,   140,   141,   142,   143,   625,   205,   876,   147,
     148,   630,   631,   664,   633,   634,   877,   878,   194,   639,
     879,   880,   147,   148,   644,   645,   646,   124,   125,   126,
     127,   128,   428,   429,   293,  1431,   294,   132,   204,   357,
     357,   659,   660,   661,   344,   345,   662,   295,  1018,   296,
     666,   667,   668,   669,   670,   226,   428,   429,   675,   482,
     875,   677,   678,   981,   287,   388,   388,   388,   616,   876,
     685,   686,  1036,   691,  1195,  1196,   693,   877,   878,   428,
     429,   879,   880,   206,   388,   654,   655,   428,   429,   609,
     701,   703,   610,   424,   930,  1276,   356,   124,   125,   126,
     127,   128,   227,  1338,   428,   429,   297,   132,   298,   691,
     214,   428,   429,   720,   234,   875,   723,   135,   136,   722,
    1340,   235,   428,   429,   876,   238,  1389,  1342,  1392,   299,
    1395,   300,   877,   878,   428,   429,   879,   880,  1350,   199,
    1035,  1370,   200,  1035,   201,   301,  1035,   302,   875,  1090,
    1352,  1434,   428,   429,   616,   612,   950,   876,   610,   951,
     952,   953,   616,   954,   617,   877,   878,   956,  1353,   879,
     880,  1297,    41,    42,    43,    44,  1298,   239,   781,   802,
      49,   782,  1091,    52,   803,   616,   801,   135,   136,   303,
     979,   304,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   483,   375,   376,  1437,   408,   409,   410,
     377,   147,   148,   388,   257,   388,   821,   258,   928,  1272,
     428,   429,   259,   703,   827,   260,   305,  1035,   306,  1476,
    1098,   267,   266,  1100,  1102,   268,  1430,   841,   269,  1502,
     447,   448,   270,   847,   855,   855,   855,   855,   854,   854,
     854,   854,   460,   461,   428,   429,   388,   428,   429,   271,
     866,   867,   428,   429,   428,   429,   870,   616,  1035,   622,
    1433,  1035,   286,  1436,  1035,   428,   429,  1035,  1444,   891,
    1446,  1517,   893,  1520,   307,  1523,   308,   147,   148,   333,
     464,  1526,   465,   334,   283,  1290,   388,   153,   388,   284,
     428,   429,   388,   388,   388,   388,   335,  1035,   865,  1035,
     388,  1035,   309,   336,   310,   871,  1506,   918,   875,   920,
     921,   883,   372,   373,   374,   375,   376,   876,  1556,   337,
    1558,   377,  1560,   929,   875,   877,   878,   389,   338,   879,
     880,   339,   389,   876,  1260,  1261,   389,   856,   857,   858,
     340,   877,   878,   389,   341,   879,   880,   311,  1066,   312,
     342,   343,   147,   148,   355,   938,   939,   501,   313,   283,
     314,   315,   381,   316,   284,   317,   319,   318,   320,   940,
     941,   942,   943,   944,   945,   946,   382,   321,   388,   322,
     388,   323,   361,   324,   390,   378,   325,   360,   326,   395,
     955,   379,   393,   399,   958,   327,   398,   328,   964,  1540,
     405,   403,   329,   478,   330,   389,   404,   433,   388,   388,
     388,   388,   977,   406,   331,  1542,   332,   402,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   875,   407,   411,   419,   377,   616,   422,   626,
     416,   876,   388,   875,   616,  1291,   632,   417,   418,   877,
     878,   421,   876,   879,   880,   454,  1209,   875,   434,   449,
     877,   878,   435,   444,   879,   880,   876,   616,   718,   700,
     719,   445,   446,   984,   877,   878,   450,   456,   879,   880,
    1224,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   457,   777,  1049,   778,   377,
     462,  1067,   389,   458,   459,   389,   929,   463,   362,  1384,
    1058,   484,   503,   504,   616,   616,   795,   798,   469,  1023,
    1024,  1025,   616,  1544,   897,   616,   466,   898,   875,   489,
     470,  1076,  1077,   616,  1546,   899,   616,   876,   911,   485,
       7,     8,   478,   471,   491,   877,   878,   492,  1568,   879,
     880,   990,   616,   991,  1016,   616,   616,  1052,  1053,   569,
     496,   505,   573,  1103,   616,   507,  1054,  1108,   616,   616,
    1055,  1056,   616,   616,  1057,  1059,  1109,  1122,  1110,   497,
    1119,  1121,   508,   582,    19,    20,   583,    22,    23,   584,
      25,   585,    27,   616,    28,  1111,   499,   510,    32,    33,
     377,    35,    36,    37,   616,   579,  1112,    40,   616,   578,
    1113,   875,   389,   389,   389,   580,  1156,  1157,  1158,  1569,
     876,   616,   616,  1114,  1140,   153,  1168,  1170,   877,   878,
     581,   389,   879,   880,  1173,    59,    60,    61,   704,  1204,
     587,  1205,   388,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,  1250,   616,  1251,
    1285,   377,  1191,  1192,  1193,  1303,  1204,  1304,  1351,   680,
     681,   682,  1204,  1201,  1380,  1199,   629,  1397,  1207,  1398,
     616,   635,  1409,  1174,  1204,  1417,  1414,  1418,   698,  1420,
    1204,  1421,  1425,   636,   502,  1212,   679,   616,   647,  1426,
    1213,   640,  1570,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   641,   616,  1227,  1445,   377,  1303,  1226,  1482,
     642,   616,  1228,  1505,   616,  1204,  1507,  1511,  1233,  1234,
    1535,  1400,  1536,  1236,   790,   616,  1538,  1547,  1548,   643,
    1549,  1243,  1204,  1571,  1566,  1572,   649,   650,   673,  1255,
     671,  1253,   674,  1254,   676,   683,   684,   692,   357,   357,
     389,   694,   389,   695,   696,  1271,   697,   708,   711,   717,
     704,   828,  1229,   783,   784,   388,   785,   786,   787,   388,
     788,   793,  1286,   792,   794,   804,   805,   809,   823,   819,
    1295,   822,   824,   829,  1294,   826,   830,   831,   833,   834,
    1299,  1300,   835,   389,   836,   797,   839,   838,  1262,   840,
    1265,   844,  1268,   849,   851,   864,   868,   818,   869,   820,
     892,   905,   914,  1315,  1279,   915,  1477,  1282,  1283,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   389,   916,   389,   917,   377,   924,   389,
     389,   389,   389,   926,   933,   934,  1335,   389,   937,   947,
     863,   957,   959,   935,   960,   965,   966,   969,   968,   848,
     972,   978,  1531,   983,  1349,   988,   477,   985,   994,   999,
     862,  1000,   995,  1002,  1003,  1006,  1357,  1007,  1358,  1008,
    1009,   388,  1010,  1011,  1012,  1013,  1364,  1014,  1015,  1017,
     902,  1368,   903,  1026,  1027,  1028,   907,   908,   909,   910,
    1038,  1562,  1029,  1565,   913,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,  1039,  1044,   388,
    1040,   377,  1041,   357,  1578,   389,  1387,   389,  1390,  1042,
    1393,  1045,  1046,  1047,  1048,  1050,  1051,  1063,  1068,  1069,
     388,   925,  1072,  1073,  1406,  1071,  1074,  1092,  1075,  1080,
    1093,  1094,  1095,  1412,  1413,   389,   389,   389,   389,  1104,
    1416,  1097,  1105,  1115,  1118,  1125,  1129,  1132,  1124,  1424,
    1130,  1133,  1136,  1428,  1131,  1388,  1137,  1391,  1135,  1394,
    1138,  1143,   948,  1146,   949,  1144,  1159,  1402,  1147,   389,
    1405,  1148,  1149,  1153,  1167,  1160,  1171,  1172,  1179,  1207,
    1180,  1184,  1186,  1187,  1188,  1189,  1194,  1190,  1198,  1197,
    1214,  1457,   973,   974,   975,   976,  1208,  1215,  1464,  1241,
    1217,  1468,  1220,  1221,  1472,  1222,  1223,  1230,  1475,   603,
    1231,  1232,   388,  1235,   388,  1237,  1305,  1238,  1239,  1484,
    1240,  1244,  1486,  1249,  1492,  1252,  1001,  1263,  1266,  1269,
    1273,  1277,  1280,   986,   987,   791,   989,  1284,   992,   993,
    1306,  1302,   996,   997,  1307,  1308,     7,     8,  1309,  1313,
    1311,  1312,  1314,  1322,  1324,  1325,  1514,  1326,  1327,  1328,
    1329,  1516,  1333,  1480,  1330,  1334,  1345,  1336,  1337,  1347,
    1339,  1341,  1354,  1356,   388,  1343,  1361,  1369,  1348,  1375,
    1362,  1371,  1376,  1377,  1378,  1379,  1396,  1403,  1381,   582,
      19,    20,   583,    22,    23,   584,    25,   585,    27,  1410,
      28,  1553,  1415,  1552,    32,    33,  1411,    35,    36,    37,
    1423,  1439,  1427,    40,  1440,  1443,  1448,  1060,  1061,  1062,
    1455,  1456,  1474,  1117,  1459,  1460,  1462,  1070,  1465,  1466,
    1469,  1574,  1470,  1473,  1479,  1500,  1494,  1508,  1079,  1496,
    1498,    59,    60,    61,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,  1509,  1518,
    1521,  1524,   377,  1527,  1529,  1533,  1534,  1554,  1555,   389,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,  1557,  1541,  1559,  1543,   377,  1561,
    1563,  1128,  1573,  1575,  1545,  1550,  1576,  1134,  1577,  1579,
    1449,   613,   715,  1139,    83,  1141,  1142,  1127,    91,  1216,
    1145,   638,  1515,     0,     0,  1150,  1151,  1152,   967,     0,
       0,     0,     0,     0,     0,     0,  1183,     0,     0,     0,
       0,  1169,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1178,     0,     0,     0,  1182,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,    96,   240,     0,
       0,   377,     0,   100,   101,   102,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   242,
       0,     0,     0,     0,     0,     0,     0,   129,   130,   131,
       0,  1210,   389,  1211,     0,     0,   389,     0,     0,   243,
       0,     0,   244,     0,     0,   245,     0,   246,     0,     0,
       0,     0,     0,     0,     0,   998,     0,     0,   247,     0,
       0,     0,     0,     0,    41,    42,    43,    44,    45,     0,
       0,     0,    49,     0,     0,    52,     0,     0,     0,  1245,
    1246,  1247,  1248,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,     0,     0,     0,
       0,   377,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,  1079,  1043,     0,     7,     8,     0,   137,   138,
     139,     0,     0,  1287,     0,     0,     0,     0,     0,     0,
    1296,     0,     0,   478,   436,  1278,     0,  1301,     0,   146,
       0,     0,     0,     0,   438,     0,     0,  1099,   389,   152,
       0,   210,   480,     0,     0,     0,     0,     0,   582,    19,
      20,   583,    22,    23,   584,    25,   585,    27,     0,    28,
       0,     0,  1079,    32,    33,     0,    35,    36,    37,     7,
       8,     0,    40,     0,     0,     0,   389,     0,     0,     0,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,  1359,  1346,   389,   377,     0,
      59,    60,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   582,    19,    20,   583,    22,    23,   584,    25,
     585,    27,     0,    28,     0,  1079,     0,    32,    33,     0,
      35,    36,    37,  1383,     0,     0,    40,     0,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,  1079,  1404,     0,   377,     0,     0,     0,
       0,   716,     0,     0,    59,    60,    61,     0,     0,     0,
    1399,     0,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,    96,   240,   389,
     377,   389,     0,   100,   101,   102,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   242,
    1438,     0,     0,     0,     0,   884,     0,   129,   130,   131,
       0,     0,     0,   389,     0,     0,     0,     0,     0,   243,
       0,     0,   244,     0,     0,   245,  1478,   246,  1481,     0,
       0,   389,     0,     0,     0,     0,     0,     0,   247,     0,
       0,     0,     0,     0,    41,    42,    43,    44,    45,     0,
       0,     0,    49,    96,   276,    52,  1079,     0,  1489,   100,
     101,   102,     0,     0,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,     0,     0,     0,  1528,     0,
       0,   134,     0,   129,   130,   131,     0,     0,   137,   138,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   387,     0,     0,     0,   146,
       0,     0,     0,     0,   249,     0,     0,     0,     0,   152,
       0,     0,   480,    96,    97,    98,  1079,    99,     0,   100,
     101,   102,     0,     0,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,     0,     0,     0,   124,   125,
     126,   127,   128,   129,   130,   131,     0,   134,   132,     7,
       8,     0,     0,     0,   137,   138,   139,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,   145,     0,     0,     0,   146,     0,     0,     0,     0,
     249,     0,     0,   349,     0,   152,     0,   350,     0,     0,
       0,     0,   582,    19,    20,   583,    22,    23,   584,    25,
     585,    27,     0,    28,     0,     0,     0,    32,    33,     0,
      35,    36,    37,     0,     0,     0,    40,     0,     0,     0,
       0,   133,     0,     0,     0,     0,     0,   134,   135,   136,
       0,     0,     0,     0,   137,   138,   139,   140,   141,   142,
     143,     0,     0,     0,    59,    60,    61,     0,     0,     0,
     144,   145,     0,     0,     0,   146,     0,   147,   148,     0,
     149,     0,   150,     0,   151,   152,     0,   153,    96,   240,
     241,     0,     0,     0,   100,   101,   102,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     242,     0,     0,     0,     0,   919,     0,     0,   129,   130,
     131,     0,     0,     0,     7,     8,     0,     0,     0,     0,
     243,     0,     0,   244,     0,     0,   245,     0,   246,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   247,
       0,     0,     0,     0,     0,    41,    42,    43,    44,    45,
       0,     0,     0,    49,     0,     0,    52,   582,    19,    20,
     583,    22,    23,   584,    25,   585,    27,     0,    28,     0,
       0,     0,    32,    33,     0,    35,    36,    37,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,     0,     0,     0,     0,     0,     0,   137,
     138,   139,     0,     0,     0,     0,     0,     0,     0,    59,
      60,    61,     0,     0,     0,   144,   248,     0,     0,     0,
     146,     0,     0,     0,     0,   249,     0,    96,   240,  1176,
     152,     0,   250,   100,   101,   102,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   242,
       0,     0,     0,     0,     0,     0,     0,   129,   130,   131,
    1441,     0,     0,     7,     8,     0,     0,     0,     0,   243,
       0,     0,   244,     0,     0,   245,     0,   246,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,     0,
       0,     0,     0,     0,    41,    42,    43,    44,    45,     0,
       0,     0,    49,     0,     0,    52,   582,    19,    20,   583,
      22,    23,   584,    25,   585,    27,     0,    28,     0,     0,
       0,    32,    33,     0,    35,    36,    37,     0,     0,     0,
      40,  1106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,     0,     0,     0,     0,     0,     0,   137,   138,
     139,  1185,     0,     0,     0,     0,     0,     0,    59,    60,
      61,     0,     0,     0,   144,   248,     0,     0,     0,   146,
       0,     0,     0,     0,   249,     0,    96,   240,  1487,   152,
       0,  1177,   100,   101,   102,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   242,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   131,  1503,
       0,     0,     0,     0,     0,     0,     0,     0,   243,     0,
       0,   244,     0,     0,   245,     0,   246,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,     0,     0,
       0,     0,     0,    41,    42,    43,    44,    45,     0,     0,
       0,    49,     0,     0,    52,     0,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     134,  1310,     0,     0,   377,     0,     0,   137,   138,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,   248,     0,     0,     0,   146,     0,
       0,     0,     0,   249,     0,    96,   240,     0,   152,     0,
    1488,   100,   101,   102,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   242,     0,     0,
       0,     0,     0,     0,     0,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,     0,     0,
     244,     0,     0,   245,     0,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   247,     0,     0,     0,
       0,     0,    41,    42,    43,    44,    45,     0,     0,     0,
      49,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
    1332,     0,     0,     0,   377,     0,     0,     0,     0,   134,
       0,     0,     0,     0,     0,     0,   137,   138,   139,  1360,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   144,   248,     0,     0,     0,   146,     0,     0,
       0,     0,   249,     0,    96,   240,     0,   152,     0,   250,
     100,   101,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   242,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,     0,     0,   244,
       0,     0,   245,     0,   246,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   247,     0,     0,     0,     0,
       0,    41,    42,    43,    44,    45,     0,     0,     0,    49,
       0,     0,    52,     0,     0,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,     0,
       0,     0,     0,   377,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   134,  1447,
       0,     0,   377,     0,     0,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,   387,     0,     0,     0,   146,     0,     0,     0,
       0,   249,     0,    96,   240,     0,   152,     0,   476,   100,
     101,   102,     0,     0,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   242,     0,     0,     0,     0,
       0,     0,     0,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   243,     0,     0,   244,     0,
       0,   245,     0,   246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,     0,     0,     0,     0,     0,
      41,    42,    43,    44,    45,     0,     0,     0,    49,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,  1501,     0,
       0,     0,   377,     0,     0,     0,     0,   134,     0,     0,
       0,     0,     0,     0,   137,   138,   139,     0,  1537,   482,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,   387,     0,     0,     0,   146,     0,     0,     0,     0,
     249,     0,    96,   240,     0,   152,     0,   702,   100,   101,
     102,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   242,     0,     0,     0,     0,     0,
       0,     0,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   243,     0,     0,   244,     0,     0,
     245,     0,   246,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   247,     0,     0,     0,     0,     0,    41,
      42,    43,    44,    45,     0,     0,     0,    49,     0,     0,
      52,     0,     0,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,     0,     0,     0,
       0,   377,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   615,   375,   376,   134,  1567,     0,     0,
     377,     0,     0,   137,   138,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   144,
     248,     0,     0,     0,   146,     0,     0,     0,     0,   249,
       0,    96,   240,     0,   152,     0,  1181,   100,   101,   102,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   242,     0,     0,     0,     0,     0,     0,
       0,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,     0,     0,   244,     0,     0,   245,
       0,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,     0,     0,     0,     0,     0,    41,    42,
      43,    44,    45,     0,     0,     0,    49,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,     0,     0,     0,     0,   377,
     482,     0,     0,     0,     0,   134,     0,     0,     0,     0,
       0,     0,   137,   138,   139,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   436,  1278,
       0,     0,     0,   146,     0,     0,     0,     0,   438,     0,
      96,   276,   287,   152,     0,   210,   100,   101,   102,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,     0,     0,     0,   124,   125,   126,   127,   128,
     129,   130,   131,     0,     0,   132,    96,   276,   287,     0,
       0,     0,   100,   101,   102,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,     0,     0,
       0,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,   132,     0,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   483,   375,   376,     0,     0,     0,
       0,   377,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,     0,     0,     0,
       0,   137,   138,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   144,   145,     0,
       0,     0,   146,     0,     0,     0,     0,   249,     0,     0,
       0,     0,   152,     0,  1120,     0,     0,     0,     0,     0,
     134,   135,   136,     0,     0,     0,     0,   137,   138,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,   145,     0,     0,     0,   146,     0,
       0,     0,     0,   249,     0,    96,   276,     0,   152,     0,
    1293,   100,   101,   102,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,     0,     0,     0,
       0,     0,    96,   276,  1490,   129,   130,   131,   100,   101,
     102,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,    96,
     276,     0,   129,   130,   131,   100,   101,   102,     0,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,     0,     0,     0,     0,     0,     0,     0,   134,
       0,     0,     0,     0,     0,     0,   137,   138,   139,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   144,   145,     0,     0,     0,   146,     0,     0,
       0,     0,   249,     0,     0,   689,   134,   152,     0,   690,
       0,     0,     0,   137,   138,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   144,
     145,     0,     0,     0,   146,     0,     0,     0,     0,   249,
       0,     0,     0,   134,   152,     0,  1491,     0,     0,     0,
     137,   138,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,   145,     0,     0,
       0,   146,     0,     0,     0,     0,   249,     0,    96,   276,
       0,   152,     0,   347,   100,   101,   102,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
       0,     0,     0,     0,     0,    96,   240,     0,   129,   130,
     131,   100,   101,   102,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   242,     0,     0,
       0,     0,     0,     0,     0,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,     0,     0,
     244,     0,     0,   245,     0,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   247,     0,     0,     0,
       0,     0,    41,    42,    43,    44,    45,     0,     0,     0,
      49,     0,   134,    52,     0,     0,     0,     0,     0,   137,
     138,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   482,     0,     0,     0,   436,   437,     0,     0,     0,
     146,     0,     0,     0,     0,   438,     0,     0,     0,   134,
     152,     0,   210,     0,   712,     0,   137,   138,   139,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   144,   387,     0,     0,     0,   146,    96,   276,
     287,     0,   249,     0,   100,   101,   102,   152,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
       0,     0,     0,   124,   125,   126,   127,   128,   129,   130,
     131,    96,   276,   132,     0,     0,     0,   100,   101,   102,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   814,     0,     0,     0,     0,     0,     0,
       0,   129,   130,   131,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   615,   375,   376,   912,     0,
       0,     0,   377,     0,     0,     0,     0,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,  1065,   134,   135,   136,   377,     0,     0,     0,   137,
     138,   139,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   144,   145,     0,     0,     0,
     146,     0,     0,     0,     0,   249,     0,     0,     0,     0,
     152,     0,     0,     0,     0,   134,     0,     0,     0,     0,
       0,     0,   137,   138,   139,     0,   582,    19,    20,   583,
      22,    23,   584,    25,   585,    27,     0,    28,   144,   145,
       0,    32,    33,   146,    35,    36,    37,     0,   249,     0,
      40,     0,     0,   152,     0,     0,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
    1004,     0,     0,     0,   377,     0,     0,     0,    59,    60,
      61,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,     0,     0,     0,     0,   377,
       0,     0,     0,     0,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,    -4,
       1,     0,   377,    -4,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,     0,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,    -4,    -4,     0,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,     0,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     6,    -4,    -4,     0,     0,     0,
      -4,     0,     7,     8,     0,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     9,    10,     0,    -4,
      -4,    -4,    -4,     0,     0,     0,    11,    12,     0,    13,
      14,    15,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,     0,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,     0,     0,    55,    56,     0,     0,
       0,    57,     0,     0,     0,     0,    58,    59,    60,    61,
       0,     0,    62,     0,    63,     0,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,     0,
      75,    76,    77,    78,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,     0,     0,     0,  1258,
       0,  1259,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,     0,     0,     0,  1288,     0,  1289,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,     0,     0,     0,  1385,     0,  1386,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
       0,     0,     0,     0,     0,   843,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,     0,     0,     0,     0,
       0,     0,     0,   887,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,     0,     0,     0,     0,
       0,   906,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,     0,     0,     0,     0,     0,   931,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,     0,     0,     0,     0,     0,  1021,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
       0,     0,     0,     0,     0,  1256,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,     0,     0,     0,     0,
       0,     0,     0,  1275,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,     0,     0,     0,     0,
       0,  1318,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,     0,     0,     0,     0,     0,  1319,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,     0,     0,     0,     0,     0,  1320,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
       0,     0,     0,     0,     0,  1321,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,     0,     0,     0,     0,
       0,     0,     0,  1355,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,     0,     0,     0,     0,
       0,  1401,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,     0,     0,     0,     0,     0,  1407,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,     0,     0,     0,     0,     0,  1408,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
       0,     0,     0,     0,     0,  1429,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,     0,     0,     0,     0,
       0,     0,     0,  1432,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,     0,     0,     0,     0,
       0,  1435,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,     0,     0,     0,     0,     0,  1458,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,     0,     0,     0,     0,     0,  1461,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
       0,     0,     0,     0,     0,  1495,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,     0,     0,     0,     0,
       0,     0,     0,  1497,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,     0,     0,     0,     0,
       0,  1499,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,     0,     0,     0,     0,     0,  1512,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,     0,     0,     0,     0,     0,  1539,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
       0,     0,     0,     0,   648,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,     0,
       0,     0,     0,   377,     0,     0,     0,     0,     0,     0,
       0,  1331,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,   699,     0,     0,     0,     0,   652,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
       0,     0,     0,   608,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,     0,     0,     0,   652,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,     0,     0,     0,   653,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,     0,     0,     0,     0,
       0,   709,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,     0,     0,     0,   757,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
       0,     0,     0,   758,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,     0,     0,     0,   771,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,     0,     0,     0,   772,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,     0,     0,     0,     0,
       0,   773,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,     0,     0,     0,   774,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
       0,     0,     0,   775,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,     0,     0,     0,   776,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,     0,     0,     0,   872,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,     0,     0,     0,     0,
       0,   873,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,     0,     0,     0,   874,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
       0,     0,     0,   982,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,     0,     0,     0,  1019,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,     0,     0,     0,  1020,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,     0,     0,     0,     0,
       0,  1064,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,     0,     0,     0,  1202,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
       0,     0,     0,  1203,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,     0,     0,     0,  1225,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,     0,     0,     0,  1365,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,     0,     0,     0,     0,
       0,  1366,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,     0,     0,     0,  1372,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
       0,     0,     0,  1451,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,     0,     0,     0,  1454,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,     0,     0,     0,  1493,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,     0,     0,   574,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,     0,     0,     0,     0,   377,     0,     0,
       0,   714,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,   721,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,     0,
       0,     0,     0,   377,     0,     0,     0,   736,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
     738,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,     0,     0,     0,     0,   377,
       0,     0,     0,   740,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,   742,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,     0,     0,     0,     0,   377,     0,     0,     0,   744,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,   746,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,     0,     0,     0,
       0,   377,     0,     0,     0,   748,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,     0,     0,   750,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,     0,     0,     0,     0,   377,     0,     0,
       0,   752,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,   754,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,     0,
       0,     0,     0,   377,     0,     0,     0,   756,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
     760,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,     0,     0,     0,     0,   377,
       0,     0,     0,   762,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,   764,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,     0,     0,     0,     0,   377,     0,     0,     0,   766,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,   768,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,     0,     0,     0,
       0,   377,     0,     0,     0,   770,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,     0,     0,   895,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,     0,     0,     0,     0,   377,     0,     0,
       0,   896,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,   900,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,     0,
       0,     0,     0,   377,     0,     0,     0,   901,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,     0,     0,
     904,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,     0,     0,     0,     0,   377,
       0,     0,     0,   927,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,     0,     0,  1082,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,     0,     0,     0,     0,   377,     0,     0,     0,  1084,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
       0,     0,  1086,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,     0,     0,     0,
       0,   377,     0,     0,     0,  1088,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,     0,     0,  1089,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,     0,     0,     0,     0,   377,     0,     0,
       0,  1218,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,     0,     0,  1344,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,     0,
       0,     0,     0,   377,     0,   570,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,   614,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,     0,     0,     0,     0,   377,     0,   618,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,   619,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,     0,     0,     0,     0,   377,     0,   621,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
     623,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,     0,     0,     0,     0,   377,
       0,   624,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,   627,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,     0,     0,     0,
       0,   377,     0,   628,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,   699,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,     0,
       0,     0,     0,   377,     0,   705,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,   706,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,     0,     0,     0,     0,   377,     0,   707,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,   713,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,     0,     0,     0,     0,   377,     0,   735,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
     737,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,     0,     0,     0,     0,   377,
       0,   739,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,   741,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,     0,     0,     0,
       0,   377,     0,   743,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,   745,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,     0,
       0,     0,     0,   377,     0,   747,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,   749,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,     0,     0,     0,     0,   377,     0,   751,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,   753,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,     0,     0,     0,     0,   377,     0,   755,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
     759,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,     0,     0,     0,     0,   377,
       0,   761,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,   763,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,     0,     0,     0,
       0,   377,     0,   765,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,   767,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,     0,
       0,     0,     0,   377,     0,   769,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,   832,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,     0,     0,     0,     0,   377,     0,   837,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,   842,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,     0,     0,     0,     0,   377,     0,   845,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
     846,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,     0,     0,     0,     0,   377,
       0,   852,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,   859,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,     0,     0,     0,
       0,   377,     0,   860,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,   861,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,     0,
       0,     0,     0,   377,     0,   886,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,   888,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,     0,     0,     0,     0,   377,     0,   889,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,   890,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,     0,     0,     0,     0,   377,     0,   894,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377,     0,
    1081,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,     0,     0,     0,     0,   377,
       0,  1083,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,     0,     0,     0,     0,
     377,     0,  1085,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,     0,     0,     0,
       0,   377,     0,  1087,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,     0,     0,
       0,     0,   377,     0,  1096,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,     0,
       0,     0,     0,   377,     0,  1257,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
       0,     0,     0,     0,   377,     0,  1274,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,     0,     0,     0,     0,   377,     0,  1292,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,     0,     0,     0,     0,   377,     0,  1450,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,     0,     0,     0,     0,   377,     0,  1510,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,     0,     0,     0,     0,   377
};

static const yytype_int16 yycheck[] =
{
       6,   218,     3,  1179,     6,   430,   431,     6,     6,     4,
       7,    61,   349,   230,     6,   352,     6,     6,    55,     6,
       4,    58,   881,     5,    61,     4,     6,   807,     4,     4,
       4,   161,     4,     4,     4,     4,     4,   167,     5,    61,
       5,    63,     6,     6,   150,   151,   150,   151,    77,   160,
      77,   162,     4,     4,     6,     0,   273,    86,   275,    86,
       6,   167,   885,  1239,   168,    94,    95,    94,    95,    98,
      99,    98,    99,     4,   160,     6,    78,   152,   153,   154,
       4,     4,     5,   160,   159,   150,   151,    13,     7,    42,
      43,     6,    45,    99,   331,   332,   333,   334,   335,   336,
     337,   338,   167,     6,   341,   342,   343,   102,   103,   104,
     105,   100,     6,   150,   151,    38,    39,    40,    41,    42,
     100,   162,   161,   160,    55,    48,  1302,   166,   112,   113,
     167,    55,     6,   112,   113,    59,   150,   151,     7,   168,
     161,   168,   144,   145,   146,   166,    70,   149,   150,   121,
     150,   151,   153,   167,  1330,   147,    58,   147,   160,    61,
      61,   160,   164,   150,   151,    61,   166,   164,   167,   171,
     172,   173,   174,   168,   176,   177,   178,   179,  1037,   181,
     182,   183,   157,   158,   160,   167,   188,   162,   968,   164,
     160,   167,    65,   167,   169,   167,   167,   167,   167,   167,
     167,   203,   167,   167,   167,   128,   129,   209,   210,   160,
     162,   150,   151,   162,   150,   151,   218,   161,   137,   138,
     139,   140,   166,    58,   441,   160,    61,   166,    63,   168,
     166,   161,   168,   570,   157,   158,   166,   574,   157,   158,
     160,   164,   150,   151,   160,   164,   248,   249,   250,     7,
     150,   151,   160,   206,   207,   160,   258,   259,   260,   167,
     262,   214,     7,   265,   266,   218,   166,   269,   137,   138,
     139,   140,   160,    55,   491,   160,    58,  1453,   160,    61,
     282,    63,   167,    58,   160,   167,    61,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,  1109,
     160,   150,   151,    55,    77,   160,    58,   167,   340,    61,
       6,    63,   167,    86,   160,   347,   162,   166,   350,   168,
     167,    94,    95,   161,   352,    98,    99,  1533,   166,   157,
     158,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   613,     6,     7,   137,
     138,   139,   140,     4,     5,   387,    61,   150,   151,    77,
      61,   393,   137,   138,   139,   140,   398,    58,    86,   157,
     158,   403,   404,   166,   406,   407,    94,    95,    63,   411,
      98,    99,   157,   158,   416,   417,   418,    38,    39,    40,
      41,    42,   150,   151,   160,   168,   162,    48,   160,   430,
     431,   433,   434,   435,   436,   437,   438,   160,   166,   162,
     442,   443,   444,   445,   446,    61,   150,   151,   450,     8,
      77,   453,   454,   161,     5,   457,   458,   459,   166,    86,
     462,   463,   166,   465,     6,     7,   468,    94,    95,   150,
     151,    98,    99,   167,   476,   428,   429,   150,   151,   163,
     482,   483,   166,   436,   721,   166,     4,    38,    39,    40,
      41,    42,    58,   166,   150,   151,   160,    48,   162,   501,
     167,   150,   151,   505,    58,    77,   508,   128,   129,   507,
     166,    61,   150,   151,    86,     4,  1339,   166,  1341,   160,
    1343,   162,    94,    95,   150,   151,    98,    99,   166,    58,
    1389,  1311,    61,  1392,    63,   160,  1395,   162,    77,   161,
     166,   168,   150,   151,   166,   163,   783,    86,   166,   786,
     787,   788,   166,   790,   168,    94,    95,   794,   166,    98,
      99,   161,    80,    81,    82,    83,   166,     4,   163,   575,
      88,   166,   163,    91,   576,   166,   574,   128,   129,   160,
     817,   162,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   168,   191,   192,   193,
     159,   157,   158,   605,     4,   607,   608,   160,   164,   168,
     150,   151,   160,   615,   616,   160,   160,  1476,   162,  1442,
     957,     6,   160,   960,   961,     6,   166,   629,   162,   168,
     224,   225,     4,   635,   640,   641,   642,   643,   640,   641,
     642,   643,   236,   237,   150,   151,   648,   150,   151,     4,
     652,   653,   150,   151,   150,   151,   658,   166,  1517,   168,
     166,  1520,   167,   166,  1523,   150,   151,  1526,   166,   671,
     166,  1494,   674,  1496,   160,  1498,   162,   157,   158,   160,
     160,  1504,   162,   160,   164,     8,   688,   167,   690,   169,
     150,   151,   694,   695,   696,   697,   160,  1556,   651,  1558,
     702,  1560,   160,   160,   162,   658,   166,   709,    77,   711,
     712,   664,   150,   151,   152,   153,   154,    86,  1541,   160,
    1543,   159,  1545,   721,    77,    94,    95,   172,   160,    98,
      99,   160,   177,    86,  1159,  1160,   181,   641,   642,   643,
       7,    94,    95,   188,   160,    98,    99,   160,     8,   162,
     160,   160,   157,   158,     4,   757,   758,   162,   160,   164,
     162,   160,     5,   162,   169,   160,   160,   162,   162,   771,
     772,   773,   774,   775,   776,   777,     5,   160,   780,   162,
     782,   160,     6,   162,   172,     6,   160,   154,   162,   177,
     792,     6,   160,   181,   796,   160,   160,   162,   800,   168,
     188,   160,   160,   248,   162,   250,   167,   167,   810,   811,
     812,   813,   814,   160,   160,   168,   162,   184,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    77,   160,   160,   202,   159,   166,   205,   168,
     160,    86,   844,    77,   166,   168,   168,   160,   160,    94,
      95,     4,    86,    98,    99,   162,  1093,    77,   167,   226,
      94,    95,   167,   160,    98,    99,    86,   166,   166,   168,
     168,   160,   160,   826,    94,    95,   160,     6,    98,    99,
    1117,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   167,   162,   899,   164,   159,
     162,   161,   347,   167,   167,   350,   904,   162,     6,  1334,
     912,     6,   279,   280,   166,   166,   168,   168,     5,   872,
     873,   874,   166,   168,   168,   166,   162,   168,    77,   164,
       5,   933,   934,   166,   168,   168,   166,    86,   168,     6,
      12,    13,   387,     5,   167,    94,    95,   115,   168,    98,
      99,    61,   166,    63,   168,   166,   166,   168,   168,   347,
       6,   162,   350,   961,   166,     4,   168,   969,   166,   166,
     168,   168,   166,   166,   168,   168,   166,   983,   168,     6,
     982,   983,   167,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   166,    66,   168,     6,     6,    70,    71,
     159,    73,    74,    75,   166,     7,   168,    79,   166,   164,
     168,    77,   457,   458,   459,   162,  1018,  1019,  1020,   168,
      86,   166,   166,   168,   168,   167,  1028,  1029,    94,    95,
     168,   476,    98,    99,  1036,   107,   108,   109,   483,   166,
       6,   168,  1044,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     4,   166,     6,
     168,   159,  1064,  1065,  1066,   166,   166,   168,   168,   457,
     458,   459,   166,  1075,   168,  1073,     7,   166,  1080,   168,
     166,     7,   168,  1036,   166,   166,   168,   168,   476,   166,
     166,   168,   168,     7,     6,  1101,   168,   166,     7,   168,
    1102,   160,   168,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   160,   166,  1120,   168,   159,   166,  1120,   168,
     160,   166,  1124,   168,   166,   166,   168,   168,  1130,  1131,
     166,  1348,   168,  1135,   166,   166,   168,   168,   166,   160,
     168,  1143,   166,   166,   168,   168,   161,     6,     6,  1155,
       7,  1153,     7,  1155,     6,     6,     6,     4,  1159,  1160,
     605,   167,   607,   167,   167,  1167,   167,   112,   167,   161,
     615,   616,  1125,   166,   161,  1177,   161,   166,   166,  1181,
     166,   161,  1184,   166,   166,     6,     4,   163,     4,     6,
    1196,     6,     6,   115,  1196,     7,     7,     7,     7,   115,
    1202,  1203,     7,   648,     7,   572,     7,   115,  1161,     7,
    1163,   167,  1165,     4,     6,   164,   168,   605,   168,   607,
       6,   163,     7,  1225,  1177,     7,  1443,  1180,  1181,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   688,     7,   690,   164,   159,   167,   694,
     695,   696,   697,     6,   160,   160,  1258,   702,     6,     4,
     648,   161,     6,   167,   163,     6,     6,   162,     7,   636,
       6,   147,  1509,     7,  1276,     7,  1278,    61,     7,     7,
     647,     7,    63,     7,     7,     6,  1288,     7,  1290,   161,
     161,  1293,   161,   161,     7,     7,  1298,     7,     6,     4,
     688,  1303,   690,     4,     6,   167,   694,   695,   696,   697,
       7,  1548,   160,  1550,   702,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     6,   167,  1331,
       7,   159,     7,  1334,  1571,   780,  1338,   782,  1340,     7,
    1342,     6,     6,     6,    61,     6,     6,     4,     4,     4,
    1352,   718,     6,     4,  1356,   168,     6,   161,   160,   167,
     166,   161,   161,  1365,  1366,   810,   811,   812,   813,   164,
    1372,   161,     7,     6,     6,    70,     6,     6,   167,  1381,
     167,     6,     6,  1385,   167,  1338,     6,  1340,   167,  1342,
       5,     4,   780,     7,   782,     6,   167,  1350,     7,   844,
    1353,     7,     7,     7,   162,   167,     6,     6,   167,  1411,
     167,   167,   161,   163,     6,     6,     6,   111,     6,   166,
       6,  1423,   810,   811,   812,   813,   164,     4,  1430,   115,
       6,  1433,     6,     6,  1436,     6,     6,     6,  1440,     6,
       6,     6,  1444,     6,  1446,     5,     4,     6,   167,  1451,
       6,     6,  1454,     6,  1456,     6,   844,     6,     6,     6,
     166,     6,     6,   830,   831,     6,   833,     6,   835,   836,
     161,   167,   839,   840,     6,     6,    12,    13,     6,   164,
       7,     6,     6,     5,    59,     6,  1488,     6,     6,     6,
       6,  1493,     6,  1446,   167,   167,     6,   168,   168,     7,
     167,   167,     6,   110,  1506,   167,     6,     6,   167,     6,
     168,   113,     6,     6,     6,     6,     6,     6,   167,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     6,
      66,  1537,     6,  1535,    70,    71,   167,    73,    74,    75,
     167,     6,   168,    79,    77,   167,     6,   914,   915,   916,
       4,     4,   168,   980,     6,     6,     6,   924,     6,     6,
       6,  1567,     6,     6,     6,     6,   167,     6,   935,   167,
     167,   107,   108,   109,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   167,     6,
       6,     6,   159,     6,     6,   167,     6,     6,     6,  1044,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     6,   167,     6,   167,   159,     6,
       6,   988,     6,     6,   167,   167,     6,   994,     6,     6,
    1411,   385,   168,  1000,     3,  1002,  1003,   987,     3,  1105,
    1007,   410,  1491,    -1,    -1,  1012,  1013,  1014,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1044,    -1,    -1,    -1,
      -1,  1028,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1038,    -1,    -1,    -1,  1042,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     3,     4,    -1,
      -1,   159,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      -1,  1098,  1177,  1100,    -1,    -1,  1181,    -1,    -1,    55,
      -1,    -1,    58,    -1,    -1,    61,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,  1146,
    1147,  1148,  1149,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,  1179,     6,    -1,    12,    13,    -1,   134,   135,
     136,    -1,    -1,  1190,    -1,    -1,    -1,    -1,    -1,    -1,
    1197,    -1,    -1,  1278,   150,   151,    -1,  1204,    -1,   155,
      -1,    -1,    -1,    -1,   160,    -1,    -1,     6,  1293,   165,
      -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      -1,    -1,  1239,    70,    71,    -1,    73,    74,    75,    12,
      13,    -1,    79,    -1,    -1,    -1,  1331,    -1,    -1,    -1,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,  1293,  1273,  1352,   159,    -1,
     107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    -1,  1302,    -1,    70,    71,    -1,
      73,    74,    75,  1331,    -1,    -1,    79,    -1,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,  1330,  1352,    -1,   159,    -1,    -1,    -1,
      -1,   168,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
    1347,    -1,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,     3,     4,  1444,
     159,  1446,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    1397,    -1,    -1,    -1,    -1,   168,    -1,    43,    44,    45,
      -1,    -1,    -1,  1488,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    58,    -1,    -1,    61,  1444,    63,  1446,    -1,
      -1,  1506,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    88,     3,     4,    91,  1453,    -1,  1455,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,  1506,    -1,
      -1,   127,    -1,    43,    44,    45,    -1,    -1,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   150,   151,    -1,    -1,    -1,   155,
      -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,   165,
      -1,    -1,   168,     3,     4,     5,  1533,     7,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,   127,    48,    12,
      13,    -1,    -1,    -1,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     150,   151,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,
     160,    -1,    -1,   163,    -1,   165,    -1,   167,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    -1,    -1,    -1,    70,    71,    -1,
      73,    74,    75,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
     150,   151,    -1,    -1,    -1,   155,    -1,   157,   158,    -1,
     160,    -1,   162,    -1,   164,   165,    -1,   167,     3,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,   168,    -1,    -1,    43,    44,
      45,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    58,    -1,    -1,    61,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,
      -1,    -1,    -1,    88,    -1,    -1,    91,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    -1,
      -1,    -1,    70,    71,    -1,    73,    74,    75,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,    -1,    -1,   150,   151,    -1,    -1,    -1,
     155,    -1,    -1,    -1,    -1,   160,    -1,     3,     4,     5,
     165,    -1,   167,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
     168,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    58,    -1,    -1,    61,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    88,    -1,    -1,    91,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    -1,    -1,
      -1,    70,    71,    -1,    73,    74,    75,    -1,    -1,    -1,
      79,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
     136,     6,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,   150,   151,    -1,    -1,    -1,   155,
      -1,    -1,    -1,    -1,   160,    -1,     3,     4,     5,   165,
      -1,   167,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    58,    -1,    -1,    61,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    80,    81,    82,    83,    84,    -1,    -1,
      -1,    88,    -1,    -1,    91,    -1,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     127,     6,    -1,    -1,   159,    -1,    -1,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,    -1,    -1,    -1,   155,    -1,
      -1,    -1,    -1,   160,    -1,     3,     4,    -1,   165,    -1,
     167,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      58,    -1,    -1,    61,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       6,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,
      -1,    -1,   160,    -1,     3,     4,    -1,   165,    -1,   167,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,
      -1,    -1,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    83,    84,    -1,    -1,    -1,    88,
      -1,    -1,    91,    -1,    -1,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,   159,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   127,     6,
      -1,    -1,   159,    -1,    -1,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,    -1,
      -1,   160,    -1,     3,     4,    -1,   165,    -1,   167,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,    -1,
      -1,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,    83,    84,    -1,    -1,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     6,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,   134,   135,   136,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     150,   151,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,
     160,    -1,     3,     4,    -1,   165,    -1,   167,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    58,    -1,    -1,
      61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    80,
      81,    82,    83,    84,    -1,    -1,    -1,    88,    -1,    -1,
      91,    -1,    -1,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,   159,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   127,     7,    -1,    -1,
     159,    -1,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,
     151,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,   160,
      -1,     3,     4,    -1,   165,    -1,   167,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    58,    -1,    -1,    61,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
      82,    83,    84,    -1,    -1,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,
       8,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,
      -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,   160,    -1,
       3,     4,     5,   165,    -1,   167,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    48,     3,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    48,    -1,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,   129,    -1,    -1,    -1,
      -1,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,    -1,
      -1,    -1,   155,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,   165,    -1,   167,    -1,    -1,    -1,    -1,    -1,
     127,   128,   129,    -1,    -1,    -1,    -1,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,    -1,    -1,    -1,   155,    -1,
      -1,    -1,    -1,   160,    -1,     3,     4,    -1,   165,    -1,
     167,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    43,    44,    45,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    43,    44,    45,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,
      -1,    -1,   160,    -1,    -1,   163,   127,   165,    -1,   167,
      -1,    -1,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,
     151,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,   127,   165,    -1,   167,    -1,    -1,    -1,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,   151,    -1,    -1,
      -1,   155,    -1,    -1,    -1,    -1,   160,    -1,     3,     4,
      -1,   165,    -1,   167,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    43,    44,
      45,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      58,    -1,    -1,    61,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      88,    -1,   127,    91,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,   150,   151,    -1,    -1,    -1,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,   127,
     165,    -1,   167,    -1,     8,    -1,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,    -1,    -1,    -1,   155,     3,     4,
       5,    -1,   160,    -1,     9,    10,    11,   165,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,     3,     4,    48,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     8,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     8,   127,   128,   129,   159,    -1,    -1,    -1,   134,
     135,   136,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,    -1,    -1,    -1,
     155,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
     165,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,   150,   151,
      -1,    70,    71,   155,    73,    74,    75,    -1,   160,    -1,
      79,    -1,    -1,   165,    -1,    -1,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      77,    -1,    -1,    -1,   159,    -1,    -1,    -1,   107,   108,
     109,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,     0,
       1,    -1,   159,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,     4,    96,    97,    -1,    -1,    -1,
     101,    -1,    12,    13,    -1,   106,   107,   108,   109,    -1,
      -1,   112,    -1,   114,    -1,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    36,    37,    -1,   130,
     131,   132,   133,    -1,    -1,    -1,    46,    47,    -1,    49,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    -1,    96,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,   106,   107,   108,   109,
      -1,    -1,   112,    -1,   114,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
     130,   131,   132,   133,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,   166,
      -1,   168,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,   168,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,   166,    -1,   168,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   168,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   168,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   168,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   168,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   168,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,   161,    -1,    -1,    -1,    -1,   166,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,   166,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,   166,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,   166,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,   166,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,   166,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   163,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,   163,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,   163,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
     163,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,   163,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   163,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,   163,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,   163,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   163,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,   163,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,   163,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
     163,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,   163,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   163,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,   163,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,   163,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   163,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,   163,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,   163,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
     163,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,   163,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   163,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,   163,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,   163,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   163,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,   163,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,   159,    -1,   161,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,   161,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   159,    -1,   161,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
     161,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,
      -1,   161,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,   161,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,   159,    -1,   161,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,   161,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,   159,    -1,   161,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,   161,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   159,    -1,   161,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
     161,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,
      -1,   161,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,   161,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,   159,    -1,   161,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,   161,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,   159,    -1,   161,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,   161,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   159,    -1,   161,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
     161,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,
      -1,   161,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,   161,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,   159,    -1,   161,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,   161,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,   159,    -1,   161,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,   161,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   159,    -1,   161,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
     161,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,
      -1,   161,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,   161,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,   159,    -1,   161,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,   161,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,   159,    -1,   161,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,   161,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   159,    -1,   161,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
     161,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,
      -1,   161,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,   161,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,   159,    -1,   161,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,   161,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,   159,    -1,   161,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,    -1,   161,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   159,    -1,   161,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   171,   172,     6,     0,     4,    12,    13,    36,
      37,    46,    47,    49,    50,    51,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    96,    97,   101,   106,   107,
     108,   109,   112,   114,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   130,   131,   132,   133,   173,
     175,   176,   194,   208,   213,   216,   217,   218,   219,   220,
     221,   222,   242,   243,   244,   245,     3,     4,     5,     7,
       9,    10,    11,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    38,    39,    40,    41,    42,    43,
      44,    45,    48,   121,   127,   128,   129,   134,   135,   136,
     137,   138,   139,   140,   150,   151,   155,   157,   158,   160,
     162,   164,   165,   167,   192,   193,   246,   247,   259,    13,
      61,   160,   160,     6,   167,     6,     6,     6,     6,   162,
     162,   160,   167,   160,   160,     4,   160,   167,   160,   160,
       4,   167,   160,   160,    65,    61,    61,     6,   167,    61,
      61,    58,    61,    63,    63,    55,    58,    61,    63,    58,
      61,    63,    58,    61,   160,    58,   167,   150,   151,   160,
     167,   248,   249,   248,   167,    55,    58,    61,   167,   248,
       4,    55,    59,    70,    61,    63,    61,    58,     4,   121,
     167,     4,     6,    55,    58,    61,    58,    61,     4,     4,
       4,     5,    35,    55,    58,    61,    63,    74,   151,   160,
     167,   213,   222,   246,   251,   252,   253,     4,   160,   160,
     160,     4,   167,   255,     4,   160,   160,     6,     6,   162,
       4,     4,     5,   167,     5,   167,     4,   246,     6,   160,
     167,     4,   162,   164,   169,   193,   167,     5,   259,   160,
     162,   160,   162,   160,   162,   160,   162,   160,   162,   160,
     162,   160,   162,   160,   162,   160,   162,   160,   162,   160,
     162,   160,   162,   160,   162,   160,   162,   160,   162,   160,
     162,   160,   162,   160,   162,   160,   162,   160,   162,   160,
     162,   160,   162,   160,   160,   160,   160,   160,   160,   160,
       7,   160,   160,   160,   246,   246,   246,   167,   246,   163,
     167,   246,     4,   112,   113,     4,     4,   213,   214,   215,
     251,     6,     6,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   159,     6,     6,
     246,     5,     5,   246,   196,   199,   246,   151,   246,   253,
     254,   246,   246,   160,   246,   254,   246,   246,   160,   254,
     246,   246,   251,   160,   167,   254,   160,   160,   252,   252,
     252,   160,   209,   210,   211,   212,   160,   160,   160,   251,
     246,     4,   251,   248,   248,   248,   246,   246,   150,   151,
     167,   167,   248,   167,   167,   167,   150,   151,   160,   215,
     248,   167,   160,   167,   160,   160,   160,   252,   252,   251,
     160,     4,     6,   162,   162,   215,     6,   167,   167,   167,
     252,   252,   162,   162,   160,   162,   162,     5,   167,     5,
       5,     5,    55,    58,    61,    63,   167,   246,   253,   246,
     168,   254,     8,   152,     6,     6,   246,   246,   246,   164,
     246,   167,   115,   246,   246,   246,     6,     6,   215,     6,
     215,   162,     6,   251,   251,   162,   246,     4,   167,   177,
       6,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,     4,   258,   259,   258,   258,   258,   258,
     258,   258,   258,   258,   260,   246,   258,   258,   258,   254,
     161,     7,   192,   254,   163,     7,   192,   193,   164,     7,
     162,   168,    55,    58,    61,    63,   208,     6,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,     6,   161,   166,   161,   166,   166,   163,
     166,   195,   163,   195,   161,   152,   166,   168,   161,   161,
     246,   161,   168,   161,   161,   246,   168,   161,   161,     7,
     246,   246,   168,   246,   246,     7,     7,   240,   240,   246,
     160,   160,   160,   160,   246,   246,   246,     7,   167,   161,
       6,   166,   166,   166,   248,   248,   214,   214,   166,   246,
     246,   246,   246,   226,   166,   215,   246,   246,   246,   246,
     246,     7,   241,     6,     7,   246,     6,   246,   246,   168,
     254,   254,   254,     6,     6,   246,   246,   161,   167,   163,
     167,   246,     4,   246,   167,   167,   167,   167,   254,   161,
     168,   246,   167,   246,   253,   161,   161,   161,   112,   166,
     215,   167,     8,   161,   163,   168,   168,   161,   166,   168,
     246,   163,   193,   246,     4,   102,   103,   104,   105,   168,
     180,   184,   187,   189,   190,   161,   163,   161,   163,   161,
     163,   161,   163,   161,   163,   161,   163,   161,   163,   161,
     163,   161,   163,   161,   163,   161,   163,   166,   166,   161,
     163,   161,   163,   161,   163,   161,   163,   161,   163,   161,
     163,   166,   166,   166,   166,   166,   166,   162,   164,   161,
     166,   163,   166,   166,   161,   161,   166,   166,   166,   161,
     166,     6,   166,   161,   166,   168,   192,   251,   168,   164,
     192,   193,   259,   246,     6,     4,     4,   167,   256,   163,
     167,   167,   167,   167,     8,     6,   147,   174,   254,     6,
     254,   246,     6,     4,     6,   258,     7,   246,   253,   115,
       7,     7,   161,     7,   115,     7,     7,   161,   115,     7,
       7,   246,   161,   168,   167,   161,   161,   246,   251,     4,
     239,     6,   161,   205,   246,   259,   205,   205,   205,   161,
     161,   161,   251,   254,   164,   248,   246,   246,   168,   168,
     246,   248,   166,   166,   166,    77,    86,    94,    95,    98,
      99,   236,   237,   248,   168,   223,   161,   168,   161,   161,
     161,   246,     6,   246,   161,   163,   163,   168,   168,   168,
     163,   163,   254,   254,   163,   163,   168,   254,   254,   254,
     254,   168,     8,   254,     7,     7,     7,   164,   246,   168,
     246,   246,     7,   164,   167,   251,     6,   163,   164,   193,
     258,   168,   181,   160,   160,   167,   191,     6,   246,   246,
     246,   246,   246,   246,   246,   246,   246,     4,   254,   254,
     258,   258,   258,   258,   258,   246,   258,   161,   246,     6,
     163,     4,   112,   113,   246,     6,     6,     6,     7,   162,
     255,   257,     6,   254,   254,   254,   254,   246,   147,   258,
     161,   161,   166,     7,   248,    61,   251,   251,     7,   251,
      61,    63,   251,   251,     7,    63,   251,   251,     6,     7,
       7,   254,     7,     7,    77,   238,     6,     7,   161,   161,
     161,   161,     7,     7,     7,     6,   168,     4,   166,   166,
     166,   168,   168,   248,   248,   248,     4,     6,   167,   160,
       6,   100,     6,   100,   168,   237,   166,   236,     7,     6,
       7,     7,     7,     6,   167,     6,     6,     6,    61,   246,
       6,     6,   168,   168,   168,   168,   168,   168,   246,   168,
     251,   251,   251,     4,   166,     8,     8,   161,     4,     4,
     251,   168,     6,     4,     6,   160,   246,   246,   250,   251,
     167,   161,   163,   161,   163,   161,   163,   161,   163,   163,
     161,   163,   161,   166,   161,   161,   161,   161,   192,     6,
     192,     7,   192,   193,   164,     7,     6,   255,   246,   166,
     168,   168,   168,   168,   168,     6,     6,   174,     6,   246,
     167,   246,   259,     6,   167,    70,   207,   207,   251,     6,
     167,   167,     6,     6,   251,   167,     6,     6,     5,   251,
     168,   251,   251,     4,     6,   251,     7,     7,     7,     7,
     251,   251,   251,     7,     6,     7,   246,   246,   246,   167,
     167,   166,   168,   166,   168,   166,   168,   162,   246,   251,
     246,     6,     6,   246,   248,   168,     5,   167,   251,   167,
     167,   167,   251,   254,   167,     6,   161,   163,     6,     6,
     111,   246,   246,   246,     6,     6,     7,   166,     6,   193,
     178,   246,   166,   166,   166,   168,   179,   246,   164,   258,
     251,   251,   259,   246,     6,     4,   256,     6,   163,   255,
       6,     6,     6,     6,   258,   166,   246,   259,   246,   248,
       6,     6,     6,   246,   246,     6,   246,     5,     6,   167,
       6,   115,   206,   246,     6,   251,   251,   251,   251,     6,
       4,     6,     6,   246,   246,   259,   168,   161,   166,   168,
     214,   214,   248,     6,   227,   248,     6,   228,   248,     6,
     229,   246,   168,   166,   161,   168,   166,     6,   151,   248,
       6,   250,   248,   248,     6,   168,   246,   251,   166,   168,
       8,   168,   161,   167,   246,   259,   251,   161,   166,   246,
     246,   251,   167,   166,   168,     4,   161,     6,     6,     6,
       6,     7,     6,   164,     6,   246,   197,   198,   168,   168,
     168,   168,     5,   250,    59,     6,     6,     6,     6,     6,
     167,   167,     6,     6,   167,   246,   168,   168,   166,   167,
     166,   167,   166,   167,   163,     6,   251,     7,   167,   246,
     166,   168,   166,   166,     6,   168,   110,   246,   246,   254,
       6,     6,   168,   182,   246,   166,   166,   250,   246,     6,
     255,   113,   166,   201,   203,     6,     6,     6,     6,     6,
     168,   167,   250,   254,   214,   166,   168,   246,   248,   236,
     246,   248,   236,   246,   248,   236,     6,   166,   168,   251,
     215,   168,   248,     6,   254,   248,   246,   168,   168,   168,
       6,   167,   246,   246,   168,     6,   246,   166,   168,   202,
     166,   168,   204,   167,   246,   168,   168,   168,   246,   168,
     166,   168,   168,   166,   168,   168,   166,   168,   251,     6,
      77,   168,   224,   167,   166,   168,   166,     6,     6,   179,
     161,   166,     6,   167,   166,     4,     4,   246,   168,     6,
       6,   168,     6,   230,   246,     6,     6,   231,   246,     6,
       6,   232,   246,     6,   168,   246,   236,   215,   254,     6,
     248,   254,   168,   185,   246,   250,   246,     5,   167,   251,
       5,   167,   246,   166,   167,   168,   167,   168,   167,   168,
       6,     6,   168,   168,   225,   168,   166,   168,     6,   167,
     161,   168,   168,   200,   246,   260,   246,   236,     6,   233,
     236,     6,   234,   236,     6,   235,   236,     6,   254,     6,
     183,   258,   188,   167,     6,   166,   168,     7,   168,   168,
     168,   167,   168,   167,   168,   167,   168,   168,   166,   168,
     167,   250,   246,   259,     6,     6,   236,     6,   236,     6,
     236,     6,   258,     6,   186,   258,   168,     7,   168,   168,
     168,   166,   168,     6,   259,     6,     6,     6,   258,     6
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
      FILE *fp = fopen(tmp.c_str(), (yyvsp[(5) - (7)].c));
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
	FILE *fp = fopen(tmp.c_str(), (yyvsp[(7) - (9)].c));
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
#line 5036 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 450:
#line 5041 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 451:
#line 5045 "Gmsh.y"
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

  case 452:
#line 5065 "Gmsh.y"
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
#line 5087 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 454:
#line 5092 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 10347 "Gmsh.tab.cpp"
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


#line 5095 "Gmsh.y"


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

