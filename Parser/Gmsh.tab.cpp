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
     tTextAttributes = 299,
     tBoundingBox = 300,
     tDraw = 301,
     tToday = 302,
     tSyncModel = 303,
     tCreateTopology = 304,
     tCreateTopologyNoHoles = 305,
     tDistanceFunction = 306,
     tDefineConstant = 307,
     tUndefineConstant = 308,
     tPoint = 309,
     tCircle = 310,
     tEllipse = 311,
     tLine = 312,
     tSphere = 313,
     tPolarSphere = 314,
     tSurface = 315,
     tSpline = 316,
     tVolume = 317,
     tCharacteristic = 318,
     tLength = 319,
     tParametric = 320,
     tElliptic = 321,
     tRefineMesh = 322,
     tPlane = 323,
     tRuled = 324,
     tTransfinite = 325,
     tComplex = 326,
     tPhysical = 327,
     tCompound = 328,
     tPeriodic = 329,
     tUsing = 330,
     tPlugin = 331,
     tDegenerated = 332,
     tRotate = 333,
     tTranslate = 334,
     tSymmetry = 335,
     tDilate = 336,
     tExtrude = 337,
     tLevelset = 338,
     tRecombine = 339,
     tSmoother = 340,
     tSplit = 341,
     tDelete = 342,
     tCoherence = 343,
     tIntersect = 344,
     tMeshAlgorithm = 345,
     tReverse = 346,
     tLayers = 347,
     tHole = 348,
     tAlias = 349,
     tAliasWithOptions = 350,
     tQuadTriDbl = 351,
     tQuadTriSngl = 352,
     tRecombLaterals = 353,
     tTransfQuadTri = 354,
     tText2D = 355,
     tText3D = 356,
     tInterpolationScheme = 357,
     tTime = 358,
     tCombine = 359,
     tBSpline = 360,
     tBezier = 361,
     tNurbs = 362,
     tNurbsOrder = 363,
     tNurbsKnots = 364,
     tColor = 365,
     tColorTable = 366,
     tFor = 367,
     tIn = 368,
     tEndFor = 369,
     tIf = 370,
     tEndIf = 371,
     tExit = 372,
     tAbort = 373,
     tField = 374,
     tReturn = 375,
     tCall = 376,
     tFunction = 377,
     tShow = 378,
     tHide = 379,
     tGetValue = 380,
     tGetEnv = 381,
     tGetString = 382,
     tHomology = 383,
     tCohomology = 384,
     tBetti = 385,
     tSetOrder = 386,
     tGMSH_MAJOR_VERSION = 387,
     tGMSH_MINOR_VERSION = 388,
     tGMSH_PATCH_VERSION = 389,
     tAFFECTDIVIDE = 390,
     tAFFECTTIMES = 391,
     tAFFECTMINUS = 392,
     tAFFECTPLUS = 393,
     tOR = 394,
     tAND = 395,
     tNOTEQUAL = 396,
     tEQUAL = 397,
     tGREATEROREQUAL = 398,
     tLESSOREQUAL = 399,
     UNARYPREC = 400,
     tMINUSMINUS = 401,
     tPLUSPLUS = 402
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
#define tTextAttributes 299
#define tBoundingBox 300
#define tDraw 301
#define tToday 302
#define tSyncModel 303
#define tCreateTopology 304
#define tCreateTopologyNoHoles 305
#define tDistanceFunction 306
#define tDefineConstant 307
#define tUndefineConstant 308
#define tPoint 309
#define tCircle 310
#define tEllipse 311
#define tLine 312
#define tSphere 313
#define tPolarSphere 314
#define tSurface 315
#define tSpline 316
#define tVolume 317
#define tCharacteristic 318
#define tLength 319
#define tParametric 320
#define tElliptic 321
#define tRefineMesh 322
#define tPlane 323
#define tRuled 324
#define tTransfinite 325
#define tComplex 326
#define tPhysical 327
#define tCompound 328
#define tPeriodic 329
#define tUsing 330
#define tPlugin 331
#define tDegenerated 332
#define tRotate 333
#define tTranslate 334
#define tSymmetry 335
#define tDilate 336
#define tExtrude 337
#define tLevelset 338
#define tRecombine 339
#define tSmoother 340
#define tSplit 341
#define tDelete 342
#define tCoherence 343
#define tIntersect 344
#define tMeshAlgorithm 345
#define tReverse 346
#define tLayers 347
#define tHole 348
#define tAlias 349
#define tAliasWithOptions 350
#define tQuadTriDbl 351
#define tQuadTriSngl 352
#define tRecombLaterals 353
#define tTransfQuadTri 354
#define tText2D 355
#define tText3D 356
#define tInterpolationScheme 357
#define tTime 358
#define tCombine 359
#define tBSpline 360
#define tBezier 361
#define tNurbs 362
#define tNurbsOrder 363
#define tNurbsKnots 364
#define tColor 365
#define tColorTable 366
#define tFor 367
#define tIn 368
#define tEndFor 369
#define tIf 370
#define tEndIf 371
#define tExit 372
#define tAbort 373
#define tField 374
#define tReturn 375
#define tCall 376
#define tFunction 377
#define tShow 378
#define tHide 379
#define tGetValue 380
#define tGetEnv 381
#define tGetString 382
#define tHomology 383
#define tCohomology 384
#define tBetti 385
#define tSetOrder 386
#define tGMSH_MAJOR_VERSION 387
#define tGMSH_MINOR_VERSION 388
#define tGMSH_PATCH_VERSION 389
#define tAFFECTDIVIDE 390
#define tAFFECTTIMES 391
#define tAFFECTMINUS 392
#define tAFFECTPLUS 393
#define tOR 394
#define tAND 395
#define tNOTEQUAL 396
#define tEQUAL 397
#define tGREATEROREQUAL 398
#define tLESSOREQUAL 399
#define UNARYPREC 400
#define tMINUSMINUS 401
#define tPLUSPLUS 402




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
#line 500 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 513 "Gmsh.tab.cpp"

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
#define YYLAST   8010

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  168
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  452
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1558

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   402

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   153,     2,   163,     2,   152,     2,     2,
     158,   159,   150,   148,   164,   149,   162,   151,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     144,     2,   145,   139,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   160,     2,   161,   157,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   165,     2,   166,   167,     2,     2,     2,
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
     135,   136,   137,   138,   140,   141,   142,   143,   146,   147,
     154,   155,   156
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
    1153,  1156,  1172,  1175,  1178,  1181,  1184,  1188,  1195,  1204,
    1213,  1224,  1226,  1229,  1231,  1235,  1240,  1242,  1248,  1260,
    1274,  1275,  1283,  1284,  1298,  1299,  1315,  1316,  1323,  1332,
    1341,  1350,  1363,  1376,  1389,  1404,  1419,  1434,  1435,  1448,
    1449,  1462,  1463,  1476,  1477,  1494,  1495,  1512,  1513,  1530,
    1531,  1550,  1551,  1570,  1571,  1590,  1592,  1595,  1601,  1609,
    1619,  1622,  1625,  1629,  1632,  1636,  1646,  1653,  1654,  1658,
    1659,  1661,  1662,  1665,  1666,  1669,  1677,  1684,  1693,  1699,
    1703,  1711,  1717,  1722,  1729,  1736,  1749,  1760,  1771,  1782,
    1793,  1798,  1803,  1806,  1810,  1817,  1819,  1821,  1823,  1826,
    1832,  1840,  1851,  1853,  1857,  1860,  1863,  1866,  1870,  1874,
    1878,  1882,  1886,  1890,  1894,  1898,  1902,  1906,  1910,  1914,
    1918,  1922,  1928,  1933,  1938,  1943,  1948,  1953,  1958,  1963,
    1968,  1973,  1978,  1985,  1990,  1995,  2000,  2005,  2010,  2015,
    2022,  2029,  2036,  2041,  2046,  2051,  2056,  2061,  2066,  2071,
    2076,  2081,  2086,  2091,  2098,  2103,  2108,  2113,  2118,  2123,
    2128,  2135,  2142,  2149,  2154,  2156,  2158,  2160,  2162,  2164,
    2166,  2168,  2170,  2176,  2181,  2186,  2189,  2195,  2199,  2206,
    2211,  2219,  2226,  2233,  2238,  2240,  2243,  2246,  2250,  2254,
    2266,  2276,  2284,  2292,  2294,  2298,  2300,  2302,  2305,  2309,
    2314,  2320,  2322,  2324,  2327,  2331,  2335,  2341,  2346,  2349,
    2352,  2355,  2358,  2364,  2370,  2376,  2382,  2384,  2386,  2390,
    2394,  2399,  2406,  2413,  2415,  2417,  2421,  2425,  2435,  2443,
    2445,  2451,  2455,  2462,  2464,  2468,  2470,  2472,  2476,  2483,
    2485,  2487,  2492,  2499,  2506,  2511,  2516,  2525,  2530,  2535,
    2542,  2549,  2551
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     169,     0,    -1,   170,    -1,     1,     6,    -1,    -1,   170,
     171,    -1,   174,    -1,   173,    -1,   192,    -1,   206,    -1,
     211,    -1,   215,    -1,   216,    -1,   217,    -1,   220,    -1,
     240,    -1,   241,    -1,   219,    -1,   218,    -1,   214,    -1,
     243,    -1,   145,    -1,   145,   145,    -1,    36,   158,     5,
     159,     6,    -1,    37,   158,     5,   159,     6,    -1,    36,
     158,     5,   159,   172,   256,     6,    -1,    36,   158,     5,
     164,   252,   159,     6,    -1,    37,   158,     5,   164,   252,
     159,     6,    -1,    36,   158,     5,   164,   252,   159,   172,
     256,     6,    -1,     4,     5,   165,   175,   166,     6,    -1,
      94,     4,   160,   244,   161,     6,    -1,    95,     4,   160,
     244,   161,     6,    -1,    -1,   175,   178,    -1,   175,   182,
      -1,   175,   185,    -1,   175,   187,    -1,   175,   188,    -1,
     244,    -1,   176,   164,   244,    -1,   244,    -1,   177,   164,
     244,    -1,    -1,    -1,     4,   179,   158,   176,   159,   180,
     165,   177,   166,     6,    -1,   256,    -1,   181,   164,   256,
      -1,    -1,   100,   158,   244,   164,   244,   164,   244,   159,
     183,   165,   181,   166,     6,    -1,   256,    -1,   184,   164,
     256,    -1,    -1,   101,   158,   244,   164,   244,   164,   244,
     164,   244,   159,   186,   165,   184,   166,     6,    -1,   102,
     165,   248,   166,   165,   248,   166,     6,    -1,   102,   165,
     248,   166,   165,   248,   166,   165,   248,   166,   165,   248,
     166,     6,    -1,    -1,   103,   189,   165,   177,   166,     6,
      -1,     7,    -1,   138,    -1,   137,    -1,   136,    -1,   135,
      -1,   156,    -1,   155,    -1,    52,   160,   194,   161,     6,
      -1,    53,   160,   197,   161,     6,    -1,     4,   190,   249,
       6,    -1,     4,   160,   161,   190,   249,     6,    -1,     4,
     160,   244,   161,   190,   244,     6,    -1,     4,   158,   244,
     159,   190,   244,     6,    -1,     4,   160,   165,   252,   166,
     161,   190,   249,     6,    -1,     4,   158,   165,   252,   166,
     159,   190,   249,     6,    -1,     4,   191,     6,    -1,     4,
     160,   244,   161,   191,     6,    -1,     4,     7,   257,     6,
      -1,     4,   162,     4,     7,   257,     6,    -1,     4,   160,
     244,   161,   162,     4,     7,   257,     6,    -1,     4,   162,
       4,   190,   244,     6,    -1,     4,   160,   244,   161,   162,
       4,   190,   244,     6,    -1,     4,   162,     4,   191,     6,
      -1,     4,   160,   244,   161,   162,     4,   191,     6,    -1,
       4,   162,   110,   162,     4,     7,   253,     6,    -1,     4,
     160,   244,   161,   162,   110,   162,     4,     7,   253,     6,
      -1,     4,   162,   111,     7,   254,     6,    -1,     4,   160,
     244,   161,   162,   111,     7,   254,     6,    -1,     4,   119,
       7,   244,     6,    -1,   119,   160,   244,   161,     7,     4,
       6,    -1,   119,   160,   244,   161,   162,     4,     7,   244,
       6,    -1,   119,   160,   244,   161,   162,     4,     7,   257,
       6,    -1,   119,   160,   244,   161,   162,     4,     7,   165,
     252,   166,     6,    -1,   119,   160,   244,   161,   162,     4,
       6,    -1,    76,   158,     4,   159,   162,     4,     7,   244,
       6,    -1,    76,   158,     4,   159,   162,     4,     7,   257,
       6,    -1,    -1,   164,    -1,    -1,   194,   193,     4,    -1,
     194,   193,     4,     7,   244,    -1,    -1,   194,   193,     4,
       7,   165,   244,   195,   199,   166,    -1,   194,   193,     4,
       7,   257,    -1,    -1,   194,   193,     4,     7,   165,   257,
     196,   201,   166,    -1,    -1,   197,   193,   256,    -1,   244,
       7,   257,    -1,   198,   164,   244,     7,   257,    -1,    -1,
     199,   200,    -1,   164,     4,   249,    -1,   164,     4,   165,
     198,   166,    -1,   164,     4,     5,    -1,    -1,   201,   202,
      -1,   164,     4,   244,    -1,   164,     4,     5,    -1,   164,
       4,   165,   258,   166,    -1,   244,    -1,   257,    -1,    -1,
     113,    58,   165,   244,   166,    -1,    -1,    68,   246,    -1,
      54,   158,   244,   159,     7,   246,     6,    -1,    -1,    72,
      54,   207,   158,   203,   159,     7,   249,     6,    -1,    63,
      64,   249,     7,   244,     6,    -1,    57,   158,   244,   159,
       7,   249,     6,    -1,    77,    57,   249,     6,    -1,    61,
     158,   244,   159,     7,   249,     6,    -1,    55,   158,   244,
     159,     7,   249,   205,     6,    -1,    56,   158,   244,   159,
       7,   249,   205,     6,    -1,   105,   158,   244,   159,     7,
     249,     6,    -1,   106,   158,   244,   159,     7,   249,     6,
      -1,   107,   158,   244,   159,     7,   249,   109,   249,   108,
     244,     6,    -1,    57,     4,   158,   244,   159,     7,   249,
       6,    -1,    73,    57,   158,   244,   159,     7,   249,     6,
      -1,    -1,    72,    57,   208,   158,   203,   159,     7,   249,
       6,    -1,    68,    60,   158,   244,   159,     7,   249,     6,
      -1,    69,    60,   158,   244,   159,     7,   249,   204,     6,
      -1,    12,    13,     6,    -1,    13,    60,   244,     6,    -1,
      65,    60,   158,   244,   159,     7,     5,     5,     5,     6,
      -1,    58,   158,   244,   159,     7,   249,     6,    -1,    59,
     158,   244,   159,     7,   249,     6,    -1,    60,     4,   158,
     244,   159,     7,   249,     6,    -1,    73,    60,   158,   244,
     159,     7,   249,     6,    -1,    73,    60,   158,   244,   159,
       7,   249,     4,   165,   248,   166,     6,    -1,    -1,    72,
      60,   209,   158,   203,   159,     7,   249,     6,    -1,    71,
      62,   158,   244,   159,     7,   249,     6,    -1,    62,   158,
     244,   159,     7,   249,     6,    -1,    73,    62,   158,   244,
     159,     7,   249,     6,    -1,    -1,    72,    62,   210,   158,
     203,   159,     7,   249,     6,    -1,    79,   246,   165,   212,
     166,    -1,    78,   165,   246,   164,   246,   164,   244,   166,
     165,   212,   166,    -1,    80,   246,   165,   212,   166,    -1,
      81,   165,   246,   164,   244,   166,   165,   212,   166,    -1,
      81,   165,   246,   164,   246,   166,   165,   212,   166,    -1,
       4,   165,   212,   166,    -1,    89,    57,   165,   252,   166,
      60,   165,   244,   166,    -1,    86,    57,   158,   244,   159,
     165,   252,   166,     6,    -1,   213,    -1,   211,    -1,    -1,
     213,   206,    -1,   213,    54,   165,   252,   166,     6,    -1,
     213,    57,   165,   252,   166,     6,    -1,   213,    60,   165,
     252,   166,     6,    -1,   213,    62,   165,   252,   166,     6,
      -1,    83,    68,   158,   244,   159,     7,   249,     6,    -1,
      83,    54,   158,   244,   159,     7,   165,   248,   166,     6,
      -1,    83,    68,   158,   244,   159,     7,   165,   246,   164,
     246,   164,   252,   166,     6,    -1,    83,    68,   158,   244,
     159,     7,   165,   246,   164,   246,   164,   246,   164,   252,
     166,     6,    -1,    83,    58,   158,   244,   159,     7,   165,
     246,   164,   252,   166,     6,    -1,    83,     4,   158,   244,
     159,     7,   249,     6,    -1,    83,     4,   158,   244,   159,
       7,     5,     6,    -1,    83,     4,   165,   244,   166,     6,
      -1,    83,     4,   158,   244,   159,     7,   165,   246,   164,
     246,   164,   252,   166,     6,    -1,    87,   165,   213,   166,
      -1,    87,   119,   160,   244,   161,     6,    -1,    87,     4,
     160,   244,   161,     6,    -1,    87,     4,     6,    -1,    87,
       4,     4,     6,    -1,   110,   253,   165,   213,   166,    -1,
     123,     5,     6,    -1,   124,     5,     6,    -1,   123,   165,
     213,   166,    -1,   124,   165,   213,   166,    -1,     4,   257,
       6,    -1,     4,     4,   160,   244,   161,   256,     6,    -1,
       4,     4,     4,   160,   244,   161,     6,    -1,     4,   244,
       6,    -1,    76,   158,     4,   159,   162,     4,     6,    -1,
     104,     4,     6,    -1,   117,     6,    -1,   118,     6,    -1,
      48,     6,    -1,    45,     6,    -1,    45,   165,   244,   164,
     244,   164,   244,   164,   244,   164,   244,   164,   244,   166,
       6,    -1,    46,     6,    -1,    49,     6,    -1,    50,     6,
      -1,    67,     6,    -1,   131,   244,     6,    -1,   112,   158,
     244,     8,   244,   159,    -1,   112,   158,   244,     8,   244,
       8,   244,   159,    -1,   112,     4,   113,   165,   244,     8,
     244,   166,    -1,   112,     4,   113,   165,   244,     8,   244,
       8,   244,   166,    -1,   114,    -1,   122,     4,    -1,   120,
      -1,   121,     4,     6,    -1,   115,   158,   244,   159,    -1,
     116,    -1,    82,   246,   165,   213,   166,    -1,    82,   165,
     246,   164,   246,   164,   244,   166,   165,   213,   166,    -1,
      82,   165,   246,   164,   246,   164,   246,   164,   244,   166,
     165,   213,   166,    -1,    -1,    82,   246,   165,   213,   221,
     234,   166,    -1,    -1,    82,   165,   246,   164,   246,   164,
     244,   166,   165,   213,   222,   234,   166,    -1,    -1,    82,
     165,   246,   164,   246,   164,   246,   164,   244,   166,   165,
     213,   223,   234,   166,    -1,    -1,    82,   165,   213,   224,
     234,   166,    -1,    82,    54,   165,   244,   164,   246,   166,
       6,    -1,    82,    57,   165,   244,   164,   246,   166,     6,
      -1,    82,    60,   165,   244,   164,   246,   166,     6,    -1,
      82,    54,   165,   244,   164,   246,   164,   246,   164,   244,
     166,     6,    -1,    82,    57,   165,   244,   164,   246,   164,
     246,   164,   244,   166,     6,    -1,    82,    60,   165,   244,
     164,   246,   164,   246,   164,   244,   166,     6,    -1,    82,
      54,   165,   244,   164,   246,   164,   246,   164,   246,   164,
     244,   166,     6,    -1,    82,    57,   165,   244,   164,   246,
     164,   246,   164,   246,   164,   244,   166,     6,    -1,    82,
      60,   165,   244,   164,   246,   164,   246,   164,   246,   164,
     244,   166,     6,    -1,    -1,    82,    54,   165,   244,   164,
     246,   166,   225,   165,   234,   166,     6,    -1,    -1,    82,
      57,   165,   244,   164,   246,   166,   226,   165,   234,   166,
       6,    -1,    -1,    82,    60,   165,   244,   164,   246,   166,
     227,   165,   234,   166,     6,    -1,    -1,    82,    54,   165,
     244,   164,   246,   164,   246,   164,   244,   166,   228,   165,
     234,   166,     6,    -1,    -1,    82,    57,   165,   244,   164,
     246,   164,   246,   164,   244,   166,   229,   165,   234,   166,
       6,    -1,    -1,    82,    60,   165,   244,   164,   246,   164,
     246,   164,   244,   166,   230,   165,   234,   166,     6,    -1,
      -1,    82,    54,   165,   244,   164,   246,   164,   246,   164,
     246,   164,   244,   166,   231,   165,   234,   166,     6,    -1,
      -1,    82,    57,   165,   244,   164,   246,   164,   246,   164,
     246,   164,   244,   166,   232,   165,   234,   166,     6,    -1,
      -1,    82,    60,   165,   244,   164,   246,   164,   246,   164,
     246,   164,   244,   166,   233,   165,   234,   166,     6,    -1,
     235,    -1,   234,   235,    -1,    92,   165,   244,   166,     6,
      -1,    92,   165,   249,   164,   249,   166,     6,    -1,    92,
     165,   249,   164,   249,   164,   249,   166,     6,    -1,    84,
       6,    -1,    96,     6,    -1,    96,    98,     6,    -1,    97,
       6,    -1,    97,    98,     6,    -1,    93,   158,   244,   159,
       7,   249,    75,   244,     6,    -1,    75,     4,   160,   244,
     161,     6,    -1,    -1,    75,     4,   244,    -1,    -1,     4,
      -1,    -1,     7,   249,    -1,    -1,     7,   244,    -1,    70,
      57,   250,     7,   244,   236,     6,    -1,    70,    60,   250,
     238,   237,     6,    -1,    66,    60,   165,   244,   166,     7,
     249,     6,    -1,    70,    62,   250,   238,     6,    -1,    99,
     250,     6,    -1,    90,    60,   165,   252,   166,   244,     6,
      -1,    84,    60,   250,   239,     6,    -1,    84,    62,   250,
       6,    -1,    85,    60,   249,     7,   244,     6,    -1,    74,
      57,   249,     7,   249,     6,    -1,    74,    60,   244,   165,
     252,   166,     7,   244,   165,   252,   166,     6,    -1,    54,
     165,   252,   166,   113,    60,   165,   244,   166,     6,    -1,
      57,   165,   252,   166,   113,    60,   165,   244,   166,     6,
      -1,    57,   165,   252,   166,   113,    62,   165,   244,   166,
       6,    -1,    60,   165,   252,   166,   113,    62,   165,   244,
     166,     6,    -1,    91,    60,   250,     6,    -1,    91,    57,
     250,     6,    -1,    88,     6,    -1,    88,     4,     6,    -1,
      88,    54,   165,   252,   166,     6,    -1,   128,    -1,   129,
      -1,   130,    -1,   242,     6,    -1,   242,   165,   249,   166,
       6,    -1,   242,   165,   249,   164,   249,   166,     6,    -1,
     242,   158,   249,   159,   165,   249,   164,   249,   166,     6,
      -1,   245,    -1,   158,   244,   159,    -1,   149,   244,    -1,
     148,   244,    -1,   153,   244,    -1,   244,   149,   244,    -1,
     244,   148,   244,    -1,   244,   150,   244,    -1,   244,   151,
     244,    -1,   244,   152,   244,    -1,   244,   157,   244,    -1,
     244,   144,   244,    -1,   244,   145,   244,    -1,   244,   147,
     244,    -1,   244,   146,   244,    -1,   244,   143,   244,    -1,
     244,   142,   244,    -1,   244,   141,   244,    -1,   244,   140,
     244,    -1,   244,   139,   244,     8,   244,    -1,    14,   158,
     244,   159,    -1,    15,   158,   244,   159,    -1,    16,   158,
     244,   159,    -1,    17,   158,   244,   159,    -1,    18,   158,
     244,   159,    -1,    19,   158,   244,   159,    -1,    20,   158,
     244,   159,    -1,    21,   158,   244,   159,    -1,    22,   158,
     244,   159,    -1,    24,   158,   244,   159,    -1,    25,   158,
     244,   164,   244,   159,    -1,    26,   158,   244,   159,    -1,
      27,   158,   244,   159,    -1,    28,   158,   244,   159,    -1,
      29,   158,   244,   159,    -1,    30,   158,   244,   159,    -1,
      31,   158,   244,   159,    -1,    32,   158,   244,   164,   244,
     159,    -1,    33,   158,   244,   164,   244,   159,    -1,    34,
     158,   244,   164,   244,   159,    -1,    23,   158,   244,   159,
      -1,    14,   160,   244,   161,    -1,    15,   160,   244,   161,
      -1,    16,   160,   244,   161,    -1,    17,   160,   244,   161,
      -1,    18,   160,   244,   161,    -1,    19,   160,   244,   161,
      -1,    20,   160,   244,   161,    -1,    21,   160,   244,   161,
      -1,    22,   160,   244,   161,    -1,    24,   160,   244,   161,
      -1,    25,   160,   244,   164,   244,   161,    -1,    26,   160,
     244,   161,    -1,    27,   160,   244,   161,    -1,    28,   160,
     244,   161,    -1,    29,   160,   244,   161,    -1,    30,   160,
     244,   161,    -1,    31,   160,   244,   161,    -1,    32,   160,
     244,   164,   244,   161,    -1,    33,   160,   244,   164,   244,
     161,    -1,    34,   160,   244,   164,   244,   161,    -1,    23,
     160,   244,   161,    -1,     3,    -1,     9,    -1,    10,    -1,
      11,    -1,   132,    -1,   133,    -1,   134,    -1,     4,    -1,
       4,   167,   165,   244,   166,    -1,     4,   160,   244,   161,
      -1,   163,     4,   160,   161,    -1,     4,   191,    -1,     4,
     160,   244,   161,   191,    -1,     4,   162,     4,    -1,     4,
     160,   244,   161,   162,     4,    -1,     4,   162,     4,   191,
      -1,     4,   160,   244,   161,   162,     4,   191,    -1,   125,
     158,   256,   164,   244,   159,    -1,    43,   158,   256,   164,
     256,   159,    -1,    44,   158,   258,   159,    -1,   247,    -1,
     149,   246,    -1,   148,   246,    -1,   246,   149,   246,    -1,
     246,   148,   246,    -1,   165,   244,   164,   244,   164,   244,
     164,   244,   164,   244,   166,    -1,   165,   244,   164,   244,
     164,   244,   164,   244,   166,    -1,   165,   244,   164,   244,
     164,   244,   166,    -1,   158,   244,   164,   244,   164,   244,
     159,    -1,   249,    -1,   248,   164,   249,    -1,   244,    -1,
     251,    -1,   165,   166,    -1,   165,   252,   166,    -1,   149,
     165,   252,   166,    -1,   244,   150,   165,   252,   166,    -1,
     249,    -1,     5,    -1,   149,   251,    -1,   244,   150,   251,
      -1,   244,     8,   244,    -1,   244,     8,   244,     8,   244,
      -1,    54,   165,   244,   166,    -1,    54,     5,    -1,    57,
       5,    -1,    60,     5,    -1,    62,     5,    -1,    72,    54,
     165,   252,   166,    -1,    72,    57,   165,   252,   166,    -1,
      72,    60,   165,   252,   166,    -1,    72,    62,   165,   252,
     166,    -1,   211,    -1,   220,    -1,     4,   160,   161,    -1,
       4,   158,   159,    -1,    35,   160,     4,   161,    -1,     4,
     160,   165,   252,   166,   161,    -1,     4,   158,   165,   252,
     166,   159,    -1,   244,    -1,   251,    -1,   252,   164,   244,
      -1,   252,   164,   251,    -1,   165,   244,   164,   244,   164,
     244,   164,   244,   166,    -1,   165,   244,   164,   244,   164,
     244,   166,    -1,     4,    -1,     4,   162,   110,   162,     4,
      -1,   165,   255,   166,    -1,     4,   160,   244,   161,   162,
     111,    -1,   253,    -1,   255,   164,   253,    -1,   257,    -1,
       4,    -1,     4,   162,     4,    -1,     4,   160,   244,   161,
     162,     4,    -1,     5,    -1,    47,    -1,   126,   158,   256,
     159,    -1,   127,   158,   256,   164,   256,   159,    -1,    39,
     158,   256,   164,   256,   159,    -1,    40,   158,   256,   159,
      -1,    41,   158,   256,   159,    -1,    42,   158,   256,   164,
     256,   164,   256,   159,    -1,    38,   158,   256,   159,    -1,
      38,   160,   256,   161,    -1,    38,   158,   256,   164,   252,
     159,    -1,    38,   160,   256,   164,   252,   161,    -1,   256,
      -1,   258,   164,   256,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   167,   167,   168,   173,   175,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   197,   201,   208,   213,   218,   232,   245,   258,   286,
     300,   311,   326,   331,   332,   333,   334,   335,   339,   341,
     346,   348,   354,   458,   353,   476,   483,   494,   493,   511,
     518,   529,   528,   545,   562,   585,   584,   598,   599,   600,
     601,   602,   606,   607,   613,   615,   617,   679,   709,   744,
     778,   826,   873,   888,   904,   913,   919,   928,   946,   964,
     973,   985,   990,   998,  1018,  1041,  1052,  1060,  1082,  1105,
    1131,  1152,  1164,  1178,  1178,  1180,  1182,  1193,  1205,  1204,
    1216,  1228,  1227,  1241,  1243,  1251,  1257,  1264,  1265,  1269,
    1280,  1295,  1305,  1306,  1311,  1319,  1328,  1346,  1350,  1361,
    1364,  1377,  1380,  1390,  1414,  1413,  1433,  1455,  1473,  1494,
    1512,  1542,  1572,  1590,  1608,  1634,  1652,  1671,  1670,  1693,
    1711,  1750,  1756,  1762,  1769,  1794,  1819,  1836,  1853,  1885,
    1884,  1908,  1926,  1943,  1960,  1959,  1985,  1990,  1995,  2000,
    2005,  2010,  2033,  2039,  2050,  2051,  2056,  2059,  2063,  2086,
    2109,  2132,  2160,  2181,  2204,  2225,  2247,  2267,  2379,  2398,
    2436,  2545,  2554,  2560,  2575,  2603,  2620,  2634,  2640,  2646,
    2655,  2669,  2714,  2731,  2746,  2765,  2777,  2801,  2805,  2810,
    2817,  2823,  2828,  2834,  2838,  2842,  2847,  2860,  2877,  2894,
    2915,  2936,  2971,  2979,  2985,  2992,  2996,  3005,  3013,  3021,
    3030,  3029,  3043,  3042,  3056,  3055,  3069,  3068,  3081,  3088,
    3095,  3102,  3109,  3116,  3123,  3130,  3137,  3145,  3144,  3157,
    3156,  3169,  3168,  3181,  3180,  3193,  3192,  3205,  3204,  3217,
    3216,  3229,  3228,  3241,  3240,  3256,  3259,  3265,  3277,  3297,
    3320,  3324,  3328,  3332,  3336,  3340,  3359,  3372,  3375,  3391,
    3394,  3407,  3410,  3416,  3419,  3426,  3482,  3552,  3557,  3624,
    3660,  3668,  3711,  3750,  3770,  3797,  3837,  3860,  3883,  3887,
    3891,  3930,  3975,  3979,  3989,  4024,  4025,  4026,  4030,  4036,
    4048,  4066,  4094,  4095,  4096,  4097,  4098,  4099,  4100,  4101,
    4102,  4109,  4110,  4111,  4112,  4113,  4114,  4115,  4116,  4117,
    4118,  4119,  4120,  4121,  4122,  4123,  4124,  4125,  4126,  4127,
    4128,  4129,  4130,  4131,  4132,  4133,  4134,  4135,  4136,  4137,
    4138,  4139,  4140,  4143,  4144,  4145,  4146,  4147,  4148,  4149,
    4150,  4151,  4152,  4153,  4154,  4155,  4156,  4157,  4158,  4159,
    4160,  4161,  4162,  4163,  4172,  4173,  4174,  4175,  4176,  4177,
    4178,  4182,  4203,  4222,  4240,  4252,  4269,  4290,  4295,  4300,
    4310,  4320,  4325,  4334,  4361,  4365,  4369,  4373,  4377,  4384,
    4388,  4392,  4396,  4403,  4408,  4415,  4420,  4424,  4429,  4433,
    4441,  4452,  4456,  4468,  4476,  4484,  4491,  4501,  4521,  4525,
    4529,  4533,  4537,  4566,  4595,  4624,  4653,  4663,  4673,  4686,
    4698,  4710,  4729,  4750,  4755,  4759,  4763,  4775,  4779,  4791,
    4798,  4808,  4812,  4827,  4832,  4839,  4843,  4856,  4864,  4875,
    4879,  4887,  4895,  4903,  4911,  4925,  4939,  4952,  4957,  4961,
    4981,  5003,  5008
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
  "tStrRelative", "tStrReplace", "tStrFind", "tTextAttributes",
  "tBoundingBox", "tDraw", "tToday", "tSyncModel", "tCreateTopology",
  "tCreateTopologyNoHoles", "tDistanceFunction", "tDefineConstant",
  "tUndefineConstant", "tPoint", "tCircle", "tEllipse", "tLine", "tSphere",
  "tPolarSphere", "tSurface", "tSpline", "tVolume", "tCharacteristic",
  "tLength", "tParametric", "tElliptic", "tRefineMesh", "tPlane", "tRuled",
  "tTransfinite", "tComplex", "tPhysical", "tCompound", "tPeriodic",
  "tUsing", "tPlugin", "tDegenerated", "tRotate", "tTranslate",
  "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tRecombine",
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tIntersect",
  "tMeshAlgorithm", "tReverse", "tLayers", "tHole", "tAlias",
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
     385,   386,   387,   388,   389,   390,   391,   392,   393,    63,
     394,   395,   396,   397,    60,    62,   398,   399,    43,    45,
      42,    47,    37,    33,   400,   401,   402,    94,    40,    41,
      91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   168,   169,   169,   170,   170,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   172,   172,   173,   173,   173,   173,   173,   173,   174,
     174,   174,   175,   175,   175,   175,   175,   175,   176,   176,
     177,   177,   179,   180,   178,   181,   181,   183,   182,   184,
     184,   186,   185,   187,   187,   189,   188,   190,   190,   190,
     190,   190,   191,   191,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   193,   193,   194,   194,   194,   195,   194,
     194,   196,   194,   197,   197,   198,   198,   199,   199,   200,
     200,   200,   201,   201,   202,   202,   202,   203,   203,   204,
     204,   205,   205,   206,   207,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   208,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   209,
     206,   206,   206,   206,   210,   206,   211,   211,   211,   211,
     211,   211,   211,   211,   212,   212,   213,   213,   213,   213,
     213,   213,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   215,   215,   215,   215,   215,   216,   217,   217,   217,
     217,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   220,   220,   220,
     221,   220,   222,   220,   223,   220,   224,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   225,   220,   226,
     220,   227,   220,   228,   220,   229,   220,   230,   220,   231,
     220,   232,   220,   233,   220,   234,   234,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   236,   236,   237,
     237,   238,   238,   239,   239,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   241,   241,   241,   242,   242,   242,   243,   243,
     243,   243,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   246,   246,   246,   246,   246,   247,
     247,   247,   247,   248,   248,   249,   249,   249,   249,   249,
     249,   250,   250,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   252,   252,   252,   252,   253,   253,   253,
     253,   254,   254,   255,   255,   256,   256,   256,   256,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   258,   258
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
       2,    15,     2,     2,     2,     2,     3,     6,     8,     8,
      10,     1,     2,     1,     3,     4,     1,     5,    11,    13,
       0,     7,     0,    13,     0,    15,     0,     6,     8,     8,
       8,    12,    12,    12,    14,    14,    14,     0,    12,     0,
      12,     0,    12,     0,    16,     0,    16,     0,    16,     0,
      18,     0,    18,     0,    18,     1,     2,     5,     7,     9,
       2,     2,     3,     2,     3,     9,     6,     0,     3,     0,
       1,     0,     2,     0,     2,     7,     6,     8,     5,     3,
       7,     5,     4,     6,     6,    12,    10,    10,    10,    10,
       4,     4,     2,     3,     6,     1,     1,     1,     2,     5,
       7,    10,     1,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     4,     2,     5,     3,     6,     4,
       7,     6,     6,     4,     1,     2,     2,     3,     3,    11,
       9,     7,     7,     1,     3,     1,     1,     2,     3,     4,
       5,     1,     1,     2,     3,     3,     5,     4,     2,     2,
       2,     2,     5,     5,     5,     5,     1,     1,     3,     3,
       4,     6,     6,     1,     1,     3,     3,     9,     7,     1,
       5,     3,     6,     1,     3,     1,     1,     3,     6,     1,
       1,     4,     6,     6,     4,     4,     8,     4,     4,     6,
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
       0,     0,     0,   211,     0,   216,     0,     0,     0,   213,
       0,     0,     0,     0,   295,   296,   297,     0,     5,     7,
       6,     8,     9,    10,    19,    11,    12,    13,    18,    17,
      14,    15,    16,     0,    20,   364,   371,   439,    57,   365,
     366,   367,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     440,     0,     0,     0,     0,   368,   369,   370,    61,    60,
      59,    58,     0,     0,     0,    63,    62,     0,     0,     0,
       0,   166,     0,     0,     0,   302,     0,     0,     0,     0,
       0,   200,     0,   202,   199,   203,   204,    95,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,     0,     0,
       0,     0,   124,   137,   149,   154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   384,
       0,     0,     0,     0,     0,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   166,     0,   292,
       0,     0,     0,     0,     0,     0,     0,   371,   402,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   416,   417,
     395,   401,     0,   396,     0,     0,     0,     0,   429,     0,
       0,     0,     0,     0,   197,   198,     0,     0,   212,     0,
     166,     0,   166,   371,     0,   298,     0,     0,     0,     0,
       0,     0,   375,    32,   439,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     305,   304,   306,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,   164,     0,    72,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,   141,     0,     0,     0,     0,
      93,    93,     0,     0,   423,   424,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,   271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   386,
     385,     0,     0,     0,     0,   166,   166,     0,     0,     0,
       0,     0,     0,     0,   226,     0,   166,     0,     0,     0,
       0,     0,   273,     0,     0,     0,     0,   184,     0,     0,
       0,   293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   408,     0,   409,   410,   411,     0,     0,     0,
       0,     0,   304,   403,     0,   397,     0,     0,     0,   279,
     196,     0,     0,     0,     0,     0,   166,     0,     0,     0,
       0,   214,   187,     0,   188,     0,     0,   206,     0,     0,
       0,     0,   377,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   436,     0,
     435,     0,     0,     0,     0,     0,     0,   451,     0,     0,
       0,     0,     0,     0,   303,    57,     0,     0,     0,    57,
       0,     0,     0,     0,     0,   161,     0,     0,     0,     0,
     167,    66,     0,   320,   319,   318,   317,   313,   314,   316,
     315,   308,   307,   309,   310,   311,   312,   142,     0,     0,
       0,     0,     0,     0,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     269,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,   388,   387,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,     0,
       0,     0,     0,     0,     0,     0,   282,     0,     0,   185,
       0,     0,   181,     0,     0,     0,   291,   290,     0,     0,
     419,     0,   418,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   303,   398,   405,     0,   309,   404,     0,     0,
       0,     0,     0,     0,     0,     0,   215,     0,   189,   190,
       0,     0,     0,     0,   373,   379,     0,    42,     0,     0,
       0,    55,     0,    33,    34,    35,    36,    37,   322,   343,
     323,   344,   324,   345,   325,   346,   326,   347,   327,   348,
     328,   349,   329,   350,   330,   351,   342,   363,   331,   352,
       0,     0,   333,   354,   334,   355,   335,   356,   336,   357,
     337,   358,   338,   359,     0,     0,     0,     0,     0,     0,
       0,     0,   447,     0,   448,     0,     0,   444,   445,     0,
       0,   383,     0,    85,     0,   441,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,   374,     0,     0,     0,     0,     0,    23,    21,     0,
       0,    24,     0,     0,    64,    96,    65,   104,     0,   425,
     426,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   267,   272,
     270,     0,   278,     0,     0,   117,   118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   156,
     158,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,     0,   217,     0,     0,     0,     0,
       0,     0,   274,   281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   373,   420,   407,     0,     0,
       0,     0,   399,     0,     0,     0,     0,     0,     0,     0,
     186,     0,     0,     0,     0,     0,     0,   299,     0,     0,
     376,     0,   372,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   437,     0,
       0,     0,     0,     0,   452,     0,     0,     0,     0,    67,
       0,     0,     0,     0,     0,    73,    75,    77,     0,     0,
     433,     0,    83,     0,     0,     0,     0,   321,    22,     0,
       0,     0,     0,     0,     0,     0,   121,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,   276,     0,     0,     0,     0,
       0,     0,     0,     0,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   260,     0,     0,   261,
       0,   263,     0,   227,   256,     0,     0,     0,   179,     0,
       0,     0,   283,     0,   183,   182,   294,     0,     0,    30,
      31,     0,     0,   412,   413,   414,   415,   406,   400,     0,
       0,     0,   430,     0,     0,     0,   207,     0,     0,     0,
       0,   193,   378,   192,     0,     0,     0,     0,   393,     0,
     332,   353,   339,   360,   340,   361,   341,   362,     0,   449,
     450,   443,     0,   382,   381,   442,     0,    69,     0,    57,
       0,     0,     0,     0,    68,     0,     0,     0,   431,     0,
       0,     0,     0,    25,    26,     0,    27,     0,     0,    97,
     100,   123,     0,     0,     0,     0,     0,   127,     0,     0,
     144,   145,     0,     0,   129,   152,     0,     0,     0,   119,
       0,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   195,     0,     0,     0,     0,   166,   166,     0,   237,
       0,   239,     0,   241,     0,   395,     0,     0,   262,   264,
       0,     0,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   422,   421,   132,   133,     0,     0,     0,
       0,    86,    90,     0,     0,   300,   380,     0,    38,     0,
       0,     0,     0,     0,    40,     0,     0,     0,     0,     0,
       0,    80,     0,     0,    81,     0,   434,   168,   169,   170,
     171,     0,     0,    98,   101,     0,   122,   130,   131,   135,
       0,     0,   146,     0,     0,   277,   139,     0,     0,   268,
     151,     0,     0,     0,     0,   136,     0,   147,   153,     0,
       0,     0,     0,   392,     0,   391,     0,     0,     0,   228,
       0,     0,   229,     0,     0,   230,     0,     0,     0,     0,
       0,     0,     0,   178,     0,     0,   177,     0,     0,     0,
     172,     0,     0,     0,     0,   428,     0,   209,   208,     0,
       0,     0,     0,    43,     0,     0,     0,   394,     0,     0,
       0,   438,   446,    71,    70,    76,    78,     0,    84,     0,
      28,     0,   107,   112,     0,     0,     0,     0,     0,     0,
     140,   125,   138,   150,   155,     0,     0,    91,    92,   166,
       0,   159,   160,     0,     0,     0,     0,     0,     0,     0,
     257,     0,     0,   166,     0,     0,     0,     0,     0,   163,
     162,     0,     0,     0,     0,    87,    88,     0,     0,    39,
       0,     0,     0,    41,    56,     0,   432,     0,     0,     0,
     286,   287,   288,   289,   143,     0,     0,     0,     0,     0,
     390,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     266,     0,     0,     0,   222,     0,     0,   173,     0,     0,
       0,   427,   210,     0,   301,     0,     0,     0,     0,    82,
       0,     0,    99,   108,     0,   102,   113,     0,     0,     0,
     157,     0,   243,     0,     0,   245,     0,     0,   247,     0,
       0,     0,   258,     0,   218,     0,   166,     0,     0,     0,
     134,    89,     0,    47,     0,    53,     0,     0,     0,     0,
     120,   148,   285,   389,   231,     0,     0,   238,   232,     0,
       0,   240,   233,     0,     0,   242,     0,     0,     0,   224,
       0,   176,     0,     0,     0,     0,     0,     0,     0,   111,
       0,   109,   115,     0,   114,     0,   249,     0,   251,     0,
     253,   259,   265,   223,   219,     0,     0,     0,     0,    44,
       0,    51,     0,     0,     0,   423,     0,     0,   234,     0,
       0,   235,     0,     0,   236,     0,     0,   180,     0,   174,
       0,    45,     0,     0,   201,     0,   110,     0,   116,     0,
       0,     0,     0,     0,     0,   225,     0,     0,     0,     0,
       0,     0,   105,   244,     0,   246,     0,   248,     0,   175,
      46,    48,     0,    49,     0,     0,     0,     0,     0,     0,
       0,    54,   106,   250,   252,   254,    50,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    78,   809,    79,    80,   504,  1187,  1193,
     723,   923,  1348,  1510,   724,  1465,  1542,   725,  1512,   726,
     727,   927,   152,   282,    81,   605,   380,  1302,  1303,   381,
    1494,  1358,  1403,  1359,  1406,   844,  1228,  1114,   580,   407,
     408,   409,   410,   248,   354,   355,    84,    85,    86,    87,
      88,    89,   249,   876,  1425,  1485,   656,  1250,  1253,  1256,
    1445,  1449,  1453,  1499,  1502,  1505,   872,   873,   994,   841,
     630,   665,    91,    92,    93,    94,   250,   155,   420,   209,
    1067,   251,   252,   253,   476,   260,   800,   961,   557,   550,
     558
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1164
static const yytype_int16 yypact[] =
{
    4291,    90,    21,  4380, -1164, -1164,  2023,   134,    97,    48,
      56,    36,   228,   235,   246,   253,   123,   186,  -125,   113,
     195,     6,   217,   254,    16,   276,   287,   385,   400,   433,
     494,   444,   447,   218,   457,   294,   553,   -19,   371,   495,
     388,   -43,   -43,   396,   -32,    22,   130,   531,   544,    15,
      67,   555,   532,    70,   621,   634,  2186,   638,   448,   487,
     493,    20,     4, -1164,   502, -1164,   640,   651,   506, -1164,
     666,   703,    11,    32, -1164, -1164, -1164,  4005, -1164, -1164,
   -1164, -1164, -1164, -1164, -1164, -1164, -1164, -1164, -1164, -1164,
   -1164, -1164, -1164,    42, -1164, -1164,    27,   509,   476, -1164,
   -1164, -1164,   168,   224,   230,   261,   353,   414,   464,   520,
     524,   537,   551,   552,   579,   592,   596,   599,   616,   620,
     625,   629,   633,   637,   548,   558,   559,   563,   567,   571,
   -1164,   706,   572,   576,   589, -1164, -1164, -1164, -1164, -1164,
   -1164, -1164,  4005,  4005,  4005, -1164, -1164,  3728,   826,     9,
     729,    23,  2657,   747,   438, -1164,   754,   763,  4005,   756,
     765, -1164,  4005, -1164, -1164, -1164, -1164, -1164, -1164,  4005,
    3921,  4005,  4005,   617,  4005,  3921,  4005,  4005,   626,  3921,
    4005,  4005,  2657,   630,   627, -1164,   641,   648,  2186,  2186,
    2186,   649, -1164, -1164, -1164, -1164,   676,   680,   681,  2657,
    4005,   794,  2657,   -43,   -43,   -43,  4005,  4005,  -103, -1164,
     -11,   -43,   663,   721,   722,  3764,    91,   -30,   709,   735,
     739,  2186,  2186,  2657,   740,    43,   730, -1164,   898, -1164,
     744,   759,   769,  2186,  2186,   745,   760,   114, -1164,   768,
      34,   932,   933,   941,   329,  2814,  4005,  1757, -1164, -1164,
    3100, -1164,   944, -1164,   963,  4005,  4005,  4005,   803,  4005,
     807,   860,  4005,  4005, -1164, -1164,  4005,   976, -1164,   979,
   -1164,   984, -1164,   404,   670, -1164,  2657,  2657,   837,  4005,
     973,   835, -1164, -1164, -1164,   998,  4005,  4005,  4005,  4005,
    4005,  4005,  4005,  4005,  4005,  4005,  4005,  4005,  4005,  4005,
    4005,  4005,  4005,  4005,  4005,  4005,  4005,  4005,  4005,  4005,
    4005,  4005,  4005,  4005,  4005,  4005,  4005,  4005,  4005,  4005,
    4005,  4005,  4005,  4005,  4005,  4005,  4005,  4005,   338,   338,
     338,   338,   338,   338,   338,   338,  4005,   338,   338,   338,
     861,   861,   861,  3921,  6698,   201,  3921,  5939,   111,   859,
    1018,   869,   865, -1164,   880,  4460,  1041, -1164, -1164,  4005,
    4005,  4005,  4005,  4005,  4005,  4005,  4005,  4005,  4005,  4005,
    4005,  4005,  4005,  4005, -1164, -1164,  1159,   -87,   104,  5237,
    -111,   191,  6719,  3921,  3246, -1164,   366,  6740,  6761,  4005,
    6782,   432,  6803,  6824,  4005,   535,  6845,  6866,  1050,  4005,
    4005,  4005,  4005,  1051,  1058,  1058,  4005,   913,   917,   922,
     931,  4005,  4005,  4005,  1072,  5157,   952,  1094,   181, -1164,
   -1164,  5263,  5289,   -43,   -43,    23,    23,   183,  4005,  4005,
    4005,  3764,  3764,  4005,  4460,   284, -1164,  4005,  4005,  4005,
    4005,  4005,  1096,  1109,  1112,  4005,  1121, -1164,  4005,  4005,
    1036, -1164,  3921,  3921,  3921,  1128,  1133,  4005,  4005,   -10,
    3529,  1140, -1164,  4005, -1164, -1164, -1164,   991,   992,   999,
    1002,  3921,   861, -1164,  6887, -1164,   659,  4005,  2971, -1164,
   -1164,  6908,  6929,  6950,  1063,  5315, -1164,  1003,  4032,  6971,
    5962, -1164, -1164,  1387, -1164,  1460,  4005, -1164,  1015,   660,
    4005,  5985,   -48,  4005,    -3, -1164,  6992,  6008,  7013,  6031,
    7034,  6054,  7055,  6077,  7076,  6100,  7097,  6123,  7118,  6146,
    7139,  6169,  7160,  6192,  7181,  6215,  7202,  6238,  5341,  5367,
    7223,  6261,  7244,  6284,  7265,  6307,  7286,  6330,  7307,  6353,
    7328,  6376,  5393,  5419,  5445,  5471,  5497,  5523,   701,   176,
   -1164,   259,  1016,  1033,  1034,  1030,  1040, -1164,   304,  1555,
    1042,  1039,  1043,   698,   201, -1164,  2657,   702,    74,   476,
    4005,  1194,  1201,    30,  1047, -1164,   -26,    28,    31,    -7,
   -1164, -1164,  4099,  1536,  1784,  1505,  1505,   594,   594,   594,
     594,   251,   251,   861,   861,   861,   861, -1164,     3,  3921,
    1203,  3921,  4005,  1206, -1164,  1209,  1211,   338,  1212,  3921,
    3921,  1105,  1213,  1214,  7349,  1216,  1111,  1218,  1219,  7370,
    1114,  1221,  1222,  4005,  7391,  4485,  7412,  7433,  4005,  2657,
    1227,  1228,  7454,  4072,  4072,  4072,  4072,  7475,  7496,  7517,
    2657,  3921,  1071, -1164,   -43,  4005,  4005, -1164, -1164,  1069,
    1074,  3764,  5549,  5575,  5601,  5211,   -14,   -43,  1795,  7538,
    4513,  7559,  7580,  7601,  4005,  1235, -1164,  4005,  7622, -1164,
    6399,  6422, -1164,   749,   750,   755, -1164, -1164,  6445,  6468,
   -1164,  3921, -1164,  3921,  6491,  1085,  4541,  3921,  3921,  3921,
    3921,   767, -1164, -1164,  4118,  3921,   861, -1164,  1241,  1242,
    1243,  1089,  4005,  2059,  4005,  4005, -1164,    29, -1164, -1164,
    1092,  2657,  1248,  6514,   449, -1164,  4569, -1164,  1100,  1101,
    1098, -1164,  1255, -1164, -1164, -1164, -1164, -1164, -1164, -1164,
   -1164, -1164, -1164, -1164, -1164, -1164, -1164, -1164, -1164, -1164,
   -1164, -1164, -1164, -1164, -1164, -1164, -1164, -1164, -1164, -1164,
    4005,  4005, -1164, -1164, -1164, -1164, -1164, -1164, -1164, -1164,
   -1164, -1164, -1164, -1164,  4005,  4005,  4005,  4005,  4005,  4005,
    4005,  1262, -1164,  3921, -1164,  3921,   338, -1164, -1164,   338,
     338, -1164,   338, -1164,  4005, -1164,   338,  1117,  4005,  1264,
    1110,    13,  4005,  1267,  1273,  1803, -1164,  1271,  1120,    20,
    1275, -1164,  3921,  3921,  3921,  3921,  4005, -1164,  1139,   338,
     313, -1164,   333,  5627, -1164,  1279, -1164, -1164,   -43,  3246,
   -1164,  1233,  2657,  2657,  1281,  2657,   881,  2657,  2657,  1287,
    1234,  2657,  2657,  1856,  1288,  1305,  1306,  1308,  4401, -1164,
   -1164,  1311, -1164,  1313,  1167,  7853, -1164,  1168,  1170,  1171,
    1324,  1325,  1326,  1328,   778,  1338,   293,  5653,  5679, -1164,
   -1164,  4597,   -55,   -43,   -43,   -43,  1339,  1340,  1179,  1187,
      12,    38,   575, -1164,   318, -1164,   -14,  1343,  1351,  1352,
    1353,  1354,  7853, -1164,  1934,  1193,  1356,  1360,  1365,  1316,
    4005,  1367,  1374,   783,   789,   260, -1164, -1164,   790,   797,
     798,   802, -1164,  4005,   814,  2657,  2657,  2657,  1382,  5705,
   -1164,  4137,   732,  1385,  1386,  2657,  1225, -1164,  1388,  1391,
   -1164,  1390, -1164,  1239,  4005,  4005,  2657,  1236, -1164,  7643,
    6537,  7664,  6560,  7685,  6583,  7706,  6606,  6629, -1164,   369,
     298,  1249,  1238,  1250, -1164,  7727,  1253,   201,  1953, -1164,
     201,   258,  1230,  1396,  2451, -1164, -1164, -1164,    20,  4005,
   -1164,   817, -1164,   822,   828,   829,   832,  7853, -1164,  1392,
       8,  1407,  4005,  3442,    89,  1251,  1347,  1347,  2657,  1412,
    1254,  1257,  1414,  1417,  2657,  1259,  1420,  1422, -1164,  1424,
    2657,  2657,  2657,  1426,  1425, -1164,  2657,  1427,  1429,  1432,
    1433,  2657,  2657,  2657, -1164,  1444,   159,  4005,  4005,  4005,
    1268,  1289,   -97,   -35,    -5,  1293, -1164,  2657,  4005, -1164,
    1451, -1164,  1459, -1164, -1164,  3764,   639,  2343, -1164,  1301,
    1302,  3128, -1164,  3921, -1164, -1164, -1164,  1309,  2472, -1164,
   -1164,  1318,  1314, -1164, -1164, -1164, -1164,  7853, -1164,  1464,
    1474,  1372, -1164,  4005,  4005,  4005, -1164,  1477,   467,  1320,
    1483, -1164,   -48, -1164,  4005,  5731,  5757,   844, -1164,  4005,
   -1164, -1164, -1164, -1164, -1164, -1164, -1164, -1164,  1333, -1164,
   -1164, -1164,   338, -1164, -1164, -1164,  2657, -1164,  2657,   476,
    4005,  1492,  1495,    30, -1164,  1496,  6652,    20, -1164,  1497,
    1498,  1499,  1500, -1164, -1164,   338, -1164,  5783,  4072,  7853,
   -1164, -1164,  4005,   -43,  1501,  1502,  1503, -1164,  4005,  4005,
   -1164, -1164,  1504,  4005, -1164, -1164,  1507,  1518,  1520,  1423,
    4005, -1164,  1521,  2657,  2657,  2657,  2657,  1524,  1007,  1529,
    4005, -1164,  4072,  4625,  7748,  4166,    23,    23,   -43,  1532,
     -43,  1535,   -43,  1537,  4005,    76,  1378,  7769, -1164, -1164,
    4653,   331, -1164,  1538,  1586,  1539,  2657,   -43,  1586,  1543,
     848,  4005, -1164, -1164, -1164, -1164, -1164,  2657,  4429,   399,
    7790, -1164, -1164,  3487,  2657, -1164, -1164,   403,  7853,  4005,
    4005,  2657,  1389,   853,  7853,  1546,  1397,  1545,  1549,  1556,
    2620, -1164,  1557,  1562, -1164,  1401, -1164, -1164, -1164, -1164,
   -1164,  1563,  4005,  7853, -1164,  4681,   337, -1164, -1164, -1164,
    4709,  4737, -1164,  4765,  1566, -1164, -1164,  1514,  1568,  7853,
   -1164,  1569,  1570,  1571,  1572, -1164,  1415, -1164, -1164,  5184,
    2767,  1573,  1416, -1164,  4005, -1164,  1418,  1419,   335, -1164,
    1421,   361, -1164,  1428,   372, -1164,  1434,  6675,  1582,  2657,
    1584,  1457,  4005, -1164,  3285,   406, -1164,   858,   409,   445,
   -1164,  1588,  4793,  1484,  4005, -1164,  4005, -1164, -1164,  3921,
    2786,  1592,  1458, -1164,  4005,  5809,  5835, -1164,  2657,  4005,
    1617, -1164, -1164, -1164, -1164, -1164, -1164,    20, -1164,  1516,
   -1164,  5861, -1164, -1164,  1619,  1622,  1625,  1626,  1627,  1469,
   -1164, -1164, -1164, -1164, -1164,  2657,  3921, -1164, -1164,    23,
    4457, -1164, -1164,  3764,   -14,  3764,   -14,  3764,   -14,  1630,
   -1164,   862,  2657, -1164,  4821,   -43,  1631,  3921,   -43, -1164,
   -1164,  4005,  4849,  4877,   895, -1164, -1164,  1632,  1476,  7853,
    4005,  4005,   900,  7853, -1164,  1633, -1164,  4005,   904,   910,
   -1164, -1164, -1164, -1164, -1164,  4005,   920,   921,  1479,  4005,
   -1164,  4905,   471,   810,  4933,   488,   833,  4961,   492,   843,
   -1164,  2657,  1641,  1585,  2222,  1494,   499, -1164,   948,   505,
    2934, -1164, -1164,  1655, -1164,  4005,  7811,  5887,    37, -1164,
    5913,  1659, -1164, -1164,  1665, -1164, -1164,  4989,  1664,  1667,
   -1164,  5017,  1668,  4005,  1670,  1702,  4005,  1703,  1704,  4005,
    1708,  1550, -1164,  4005, -1164,   -14, -1164,  3921,  1709,  3285,
   -1164, -1164,   954, -1164,  4005, -1164,  2657,  4005,  2500,  3692,
   -1164, -1164, -1164, -1164, -1164,  1506,  5045, -1164, -1164,  1558,
    5073, -1164, -1164,  1559,  5101, -1164,  1715,  3081,   985,  2379,
     959, -1164,   541,   960,  1719,  1561,  7832,   966,  5129, -1164,
    1757, -1164, -1164,   338,  7853,   -14,  1721,   -14,  1722,   -14,
    1723, -1164, -1164, -1164, -1164,   -14,  1724,  3921,  1725, -1164,
     338, -1164,  1567,  1730,   967,  1823,   971,  1079, -1164,  1576,
    1086, -1164,  1577,  1172, -1164,  1578,  1244, -1164,   983, -1164,
     989, -1164,  1580,  2657, -1164,  4005, -1164,   476, -1164,  1731,
     -14,  1732,   -14,  1740,   -14, -1164,  1742,   338,  1744,   338,
    1020,   893, -1164, -1164,  1272, -1164,  1394, -1164,  1404, -1164,
   -1164, -1164,  1025, -1164,  1747,   476,  1748,  1749,  1750,   338,
    1751, -1164, -1164, -1164, -1164, -1164, -1164, -1164
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1164, -1164, -1164, -1164,   788, -1164, -1164, -1164, -1164,   364,
   -1164, -1164, -1164, -1164, -1164, -1164, -1164, -1164, -1164, -1164,
   -1164, -1164,  -333,     1, -1164,  1381, -1164, -1164, -1164, -1164,
   -1164, -1164, -1164, -1164, -1164,  -549, -1164,   786,  1761, -1164,
   -1164, -1164, -1164,    -1,  -420,  -204, -1164, -1164, -1164, -1164,
   -1164, -1164,  1762, -1164, -1164, -1164, -1164, -1164, -1164, -1164,
   -1164, -1164, -1164, -1164, -1164, -1164,  -802,  -842, -1164, -1164,
    1364, -1164, -1164, -1164, -1164, -1164,    -2, -1164,    47, -1164,
   -1163,   556,   184,   549,   602,  -770,   677, -1164,  -274,    -6,
     320
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     156,   717,    83,  1267,   154,   649,   650,   153,   261,   807,
     173,   434,   566,   348,  1104,   570,   269,   951,  1019,   225,
     178,     5,   212,   450,   258,   213,   217,   352,   214,   960,
    1024,   278,   173,   169,   798,   178,   913,   271,   199,   462,
     170,   200,   161,  1435,  1021,   423,   424,   446,   275,   447,
     603,   423,   424,   604,   549,   551,   552,   553,   554,   555,
     556,   866,   425,   560,   561,   562,   493,  1148,   495,  1149,
     867,   228,   598,   229,  1026,   274,   218,   599,   868,   869,
     219,   565,   870,   871,   477,   847,   848,   849,   208,   210,
     220,   216,   285,   423,   424,  1111,     4,   718,   719,   720,
     721,    40,    41,    42,    43,   204,   205,   145,   146,    48,
    1020,  1011,    51,   423,   424,   206,   204,   205,   569,   349,
     350,   230,   207,   952,   953,  1352,   206,   233,   437,  1150,
     234,  1151,   169,   215,   226,   438,  1022,   423,   424,   802,
     340,   341,   342,   423,   424,   344,   347,   157,   808,   680,
     353,   181,  1366,   808,   426,   681,   376,   158,   805,  1152,
     379,  1153,   262,   722,   174,  1141,  1142,   382,   384,   387,
     388,   175,   390,   384,   392,   393,   270,   384,   396,   397,
     227,   179,   145,   146,  1024,   259,   174,   279,  1095,   280,
     221,   914,   222,   803,   281,   799,   804,   272,   415,   463,
     276,   162,  1436,   448,   421,   422,   159,   277,   565,   138,
     139,   140,   141,   422,   160,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   478,   371,   372,   145,
     146,   788,   658,   373,   163,   792,   791,   423,   424,   423,
     424,   164,  1258,   472,   474,   384,   138,   139,   140,   141,
     418,   419,   165,   481,   482,   483,   436,   485,   427,   166,
     488,   489,   435,   600,   490,  1089,   145,   146,   601,   145,
     146,   171,   459,  1467,   460,   188,   280,   501,   189,   151,
     190,   281,   703,   167,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   286,  1206,   287,   423,
     424,   423,   424,   817,   559,   772,   138,   139,   140,   141,
     773,   384,   548,   284,   384,   644,   168,   651,   192,   571,
    1530,   193,   606,   172,   194,   604,   195,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   403,   404,   405,   176,   123,   124,   125,   126,
     127,   472,   288,   467,   289,   130,   468,   614,   290,   469,
     291,   470,   619,   138,   139,   140,   141,   624,   625,   626,
     627,   370,   371,   372,   632,   442,   443,  1276,   373,   637,
     638,   639,   177,   145,   146,   145,   146,   455,   456,   292,
     774,   293,   919,   775,   353,   353,   652,   653,   654,   340,
     341,   655,   423,   424,   180,   659,   660,   661,   662,   663,
     921,   423,   424,   668,   358,   181,   670,   671,   657,   182,
     384,   384,   384,   548,   284,   678,   679,  1007,   684,  1080,
     183,   686,   610,   781,   133,   134,   423,   424,   782,   384,
     647,   648,   970,  1182,  1183,   694,   696,   610,   419,   423,
     424,   284,  1025,   423,   424,   423,   424,   123,   124,   125,
     126,   127,   971,   184,   684,  1262,   130,   610,   713,  1323,
     185,   716,   941,   715,   186,   942,   943,   187,   944,   423,
     424,   294,   946,   295,   123,   124,   125,   126,   127,   191,
     423,   424,  1373,   130,  1376,  1325,  1379,  1355,  1079,   201,
     610,  1024,   611,   610,  1024,   969,  1327,  1024,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   202,   203,   423,   424,   373,   423,   424,   145,
     146,   211,  1283,   794,   496,  1277,   280,  1284,   795,   793,
    1335,   281,   296,  1337,   297,   133,   134,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   223,   232,   423,   424,   373,   610,   384,   616,   384,
     813,   224,   133,   134,   145,   146,   255,   696,   819,  1338,
     196,   919,   231,   197,  1086,   198,  1024,  1088,  1090,   423,
     424,   833,   298,  1458,   299,   235,   838,   846,   846,   846,
     846,   845,   845,   845,   845,  1413,   423,   424,   236,   384,
     423,   424,   254,   857,   858,   256,   264,   423,   424,   861,
     866,   257,  1416,   423,   424,  1024,  1419,   265,  1024,   867,
     263,  1024,   882,  1427,  1024,   884,   266,   868,   869,  1429,
     267,   870,   871,  1497,   283,  1500,   497,  1503,   300,   384,
     301,   384,   302,  1506,   303,   384,   384,   384,   384,   423,
     424,   856,  1024,   384,  1024,   304,  1024,   305,   862,   610,
     909,   620,   911,   912,   874,  1487,   330,   268,   356,   306,
     308,   307,   309,   336,   866,   920,   331,   332,  1534,   385,
    1536,   333,  1538,   867,   385,   334,  1246,  1247,   385,   335,
     337,   868,   869,   351,   338,   870,   871,   310,   398,   311,
    1055,  1023,   368,   369,   370,   371,   372,   339,   929,   930,
     312,   373,   313,   357,   314,   414,   315,   316,   417,   317,
     374,   377,   931,   932,   933,   934,   935,   936,   937,   375,
     378,   384,   386,   384,   318,   389,   319,   391,   320,   444,
     321,   395,   945,   322,   394,   323,   948,   324,   399,   325,
     954,   326,   400,   327,   473,   328,   385,   329,   416,   401,
     384,   384,   384,   384,   967,  1162,   402,   406,  1196,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   610,   711,   693,   712,   373,   428,    95,
     273,  1211,   498,   499,   411,    99,   100,   101,   412,   413,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   770,   610,   771,   787,   974,   610,   439,   790,   128,
     129,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   866,   429,   430,  1038,   373,
     449,  1056,   385,   440,   867,   385,   920,   441,   445,  1368,
    1545,  1047,   868,   869,   451,   457,   870,   871,   866,   452,
    1012,  1013,  1014,   610,   610,   888,   889,   867,   866,   610,
     458,   890,  1065,  1066,   453,   868,   869,   867,   461,   870,
     871,   610,   473,   902,   454,   868,   869,   464,   465,   870,
     871,   980,   610,   981,  1005,   563,   466,   610,   567,  1041,
     479,   132,  1091,   610,   610,  1042,  1043,  1096,   135,   136,
     137,   610,   610,  1044,  1045,   484,   610,  1110,  1046,   480,
    1107,  1109,   486,   487,   142,   143,  1414,   502,   610,   144,
    1048,  1097,   491,  1098,   246,   492,   610,   345,  1099,   150,
     494,   346,   610,   610,  1100,  1101,   610,   500,  1102,  1417,
     503,   385,   385,   385,   505,  1143,  1144,  1145,  1191,  1420,
    1192,  1236,   610,  1237,  1271,  1155,  1157,  1289,   373,  1290,
     385,   572,  1191,  1160,  1336,   573,  1381,   697,  1382,   574,
     151,   384,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   575,   581,     7,     8,
     373,  1178,  1179,  1180,   673,   674,   675,   623,   628,   610,
     866,  1393,  1188,  1186,  1191,   629,  1398,  1194,  1401,   867,
    1402,   633,  1161,   691,  1404,   634,  1405,   868,   869,   640,
     635,   870,   871,  1199,  1191,   610,  1408,  1409,  1200,   636,
     576,    19,    20,   577,    22,    23,   578,    25,   579,    27,
     643,    28,  1214,   664,    31,    32,  1213,    34,    35,    36,
    1215,   642,   610,    39,  1428,   666,  1220,  1221,  1289,   667,
    1464,  1223,   789,   610,   610,  1486,  1488,   669,  1229,  1384,
    1191,  1515,  1492,  1516,   676,   782,  1241,  1518,  1239,   677,
    1240,    58,    59,    60,   685,   353,   353,   610,   385,  1526,
     385,  1483,  1257,  1527,   866,  1528,   687,   688,   697,   820,
    1216,   866,   384,   867,   689,   597,   384,   690,   704,  1272,
     867,   868,   869,   701,   710,   870,   871,  1281,   868,   869,
     776,  1280,   870,   871,  1191,   839,  1544,  1285,  1286,  1549,
     385,  1550,   777,   778,   779,  1248,   853,  1251,   785,  1254,
     796,   810,   672,   812,   780,   797,   784,   786,   801,   811,
    1301,  1265,   814,   815,  1268,  1269,  1511,   816,   821,   818,
     822,   823,  1459,   825,   826,   827,   828,   830,   831,   832,
     385,   840,   385,   855,   842,   859,   385,   385,   385,   385,
     860,   883,  1320,   854,   385,  1519,   896,   866,   905,   906,
     907,   908,  1521,  1540,   917,  1543,   867,   915,   924,   925,
    1334,   928,   472,   926,   868,   869,   938,   916,   870,   871,
     949,   950,  1342,   955,  1343,  1556,   947,   384,   958,   956,
     959,   962,  1349,   893,   968,   894,   973,  1353,   978,   898,
     899,   900,   901,   975,   984,   989,   985,   904,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   990,   991,   384,   992,   373,   995,   353,   866,
     996,  1371,   385,  1374,   385,  1377,   997,   998,   867,   999,
    1000,  1001,  1002,  1003,  1004,   384,   868,   869,  1523,  1390,
     870,   871,  1006,  1015,  1017,  1018,  1016,   866,  1396,  1397,
    1027,   385,   385,   385,   385,  1400,   867,  1028,  1033,  1029,
    1030,  1031,  1034,  1407,   868,   869,  1035,  1411,   870,   871,
    1372,  1036,  1375,  1039,  1378,   939,  1037,   940,   976,   977,
    1040,   979,  1386,   982,   983,  1389,  1052,   986,   987,  1057,
    1058,  1060,  1092,  1194,  1061,  1062,  1063,  1064,  1103,     7,
       8,  1069,  1082,  1093,   963,   964,   965,   966,  1081,  1083,
    1525,  1446,  1085,  1106,  1450,  1113,  1112,  1454,  1117,  1118,
    1120,  1457,  1119,  1121,  1123,   384,  1124,   384,  1125,  1126,
    1130,  1131,  1466,  1146,  1133,  1468,  1134,  1474,  1546,  1135,
    1136,   576,    19,    20,   577,    22,    23,   578,    25,   579,
      27,  1140,    28,  1154,  1147,    31,    32,  1158,    34,    35,
      36,  1049,  1050,  1051,    39,  1159,  1166,  1167,  1495,   866,
    1175,  1059,     7,     8,  1171,  1174,  1462,  1173,   867,   866,
    1176,  1177,  1068,  1181,  1184,   384,   868,   869,   867,  1185,
     870,   871,    58,    59,    60,  1195,   868,   869,  1201,  1202,
     870,   871,  1204,  1207,  1208,  1209,  1210,  1217,  1218,  1219,
    1222,  1532,  1224,  1531,   576,    19,    20,   577,    22,    23,
     578,    25,   579,    27,  1225,    28,  1226,  1230,    31,    32,
    1235,    34,    35,    36,  1116,  1238,  1227,    39,  1249,  1552,
    1122,  1252,  1259,  1255,  1263,  1266,  1127,  1128,  1129,  1270,
    1291,  1293,  1132,   708,  1288,  1294,  1292,  1137,  1138,  1139,
    1547,   783,  1295,  1299,  1297,    58,    59,    60,  1298,  1300,
    1548,  1308,  1309,  1156,  1310,  1311,  1312,  1313,  1314,  1318,
    1315,  1319,   385,  1165,  1321,  1322,  1324,  1169,  1330,    95,
     237,  1332,  1341,  1326,  1339,    99,   100,   101,  1346,  1328,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   239,  1333,  1354,  1347,  1360,   709,  1356,  1361,   128,
     129,  1362,  1363,  1364,  1365,  1170,  1380,  1387,  1394,  1399,
     240,  1395,  1197,   241,  1198,  1410,   242,  1422,   243,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   244,  1426,
    1423,  1431,   373,  1438,    40,    41,    42,    43,    44,  1439,
    1441,  1475,    48,  1442,  1444,    51,  1447,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,  1231,
    1232,  1233,  1234,   373,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,  1448,  1451,
    1452,   132,   373,   385,  1455,  1461,  1456,   385,   135,   136,
     137,  1481,  1068,  1477,  1479,  1489,  1490,  1498,  1501,  1504,
    1507,  1509,  1513,  1273,   431,  1264,  1514,  1533,  1535,   144,
    1282,  1520,  1522,  1524,   433,  1529,  1537,  1287,  1539,   150,
    1541,   207,   475,  1551,  1553,  1554,  1555,  1557,  1105,  1432,
      95,   237,   607,  1115,    82,    90,    99,   100,   101,   631,
    1203,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   239,  1496,     0,     0,     0,     0,     0,     0,
     128,   129,     0,     0,     0,     0,     0,     7,     8,   957,
       0,   240,     0,   473,   241,  1331,     0,   242,     0,   243,
       0,     0,     0,     0,     0,     0,     0,     0,   385,   244,
    1517,   477,     0,     0,     0,    40,    41,    42,    43,    44,
       0,     0,     0,    48,  1068,     0,    51,     0,     0,   576,
      19,    20,   577,    22,    23,   578,    25,   579,    27,     0,
      28,     0,   988,    31,    32,   385,    34,    35,    36,     0,
       0,  1068,    39,     0,     0,     0,     0,     0,     0,     0,
       0,  1344,   132,     0,     0,     0,   385,     0,  1383,   135,
     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,     0,     0,   142,   383,     0,     0,     0,
     144,     0,     0,     0,     0,   246,     0,     0,  1367,     0,
     150,     0,     0,   475,     0,     0,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,  1421,     0,  1388,
    1032,   373,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,  1087,
     373,   875,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   609,   371,   372,   385,     0,   385,     0,
     373,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1068,     0,  1471,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,     0,
       0,     0,     0,   373,     0,     0,     0,     0,     0,   385,
       0,     0,     0,     0,     0,     0,    95,    96,    97,  1460,
      98,  1463,    99,   100,   101,     0,   385,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,   123,   124,   125,   126,   127,   128,   129,     0,  1068,
     130,     7,     8,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,     0,     0,  1508,
       0,   373,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,   576,    19,    20,   577,    22,    23,   578,
      25,   579,    27,     0,    28,     0,     0,    31,    32,     0,
      34,    35,    36,     0,     0,     0,    39,     0,     0,     0,
       0,     0,   131,     0,     0,     0,     0,     0,   132,   133,
     134,     0,     0,     0,     0,   135,   136,   137,   138,   139,
     140,   141,     0,     0,    58,    59,    60,     0,     0,     0,
       0,   142,   143,     0,     0,     0,   144,     0,   145,   146,
       0,   147,     0,   148,     0,   149,   150,     0,   151,    95,
     237,   238,     0,     0,     0,    99,   100,   101,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   239,     0,     0,     0,   910,     0,     0,     0,   128,
     129,     0,     0,     0,     7,     8,     0,     0,     0,     0,
     240,     0,     0,   241,     0,     0,   242,     0,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,     0,
       0,     0,     0,     0,    40,    41,    42,    43,    44,     0,
       0,     0,    48,     0,     0,    51,   576,    19,    20,   577,
      22,    23,   578,    25,   579,    27,     0,    28,     0,     0,
      31,    32,     0,    34,    35,    36,     0,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   132,     0,     0,     0,     0,     0,     0,   135,   136,
     137,     0,     0,     0,     0,     0,     0,    58,    59,    60,
       0,     0,     0,     0,   142,   245,     0,     0,     0,   144,
       0,     0,     0,     0,   246,     0,    95,   237,  1163,   150,
       0,   247,    99,   100,   101,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   239,     0,
       0,     0,     0,     0,     0,     0,   128,   129,  1424,     0,
       0,     7,     8,     0,     0,     0,     0,   240,     0,     0,
     241,     0,     0,   242,     0,   243,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,     0,     0,     0,     0,
       0,    40,    41,    42,    43,    44,     0,     0,     0,    48,
       0,     0,    51,   576,    19,    20,   577,    22,    23,   578,
      25,   579,    27,     0,    28,     0,     0,    31,    32,     0,
      34,    35,    36,     0,     0,     0,    39,  1094,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,     0,
       0,     0,     0,     0,     0,   135,   136,   137,  1172,     0,
       0,     0,     0,     0,    58,    59,    60,     0,     0,     0,
       0,   142,   245,     0,     0,     0,   144,     0,     0,     0,
       0,   246,     0,    95,   237,  1469,   150,     0,  1164,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   239,     0,     0,     0,     0,
       0,     0,     0,   128,   129,  1484,     0,     0,     0,     0,
       0,     0,     0,     0,   240,     0,     0,   241,     0,     0,
     242,     0,   243,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,     0,     0,     0,     0,     0,    40,    41,
      42,    43,    44,     0,     0,     0,    48,     0,     0,    51,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   132,  1296,     0,     0,   373,
       0,     0,   135,   136,   137,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   245,
       0,     0,     0,   144,     0,     0,     0,     0,   246,     0,
      95,   237,     0,   150,     0,  1470,    99,   100,   101,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   239,     0,     0,     0,     0,     0,     0,     0,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,     0,     0,   241,     0,     0,   242,     0,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
       0,     0,     0,     0,     0,    40,    41,    42,    43,    44,
       0,     0,     0,    48,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,  1317,     0,     0,     0,   373,     0,     0,
       0,     0,   132,     0,     0,     0,     0,     0,     0,   135,
     136,   137,  1345,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   245,     0,     0,     0,
     144,     0,     0,     0,     0,   246,     0,    95,   237,     0,
     150,     0,   247,    99,   100,   101,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   239,
       0,     0,     0,     0,     0,     0,     0,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,     0,
       0,   241,     0,     0,   242,     0,   243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,     0,     0,     0,
       0,     0,    40,    41,    42,    43,    44,     0,     0,     0,
      48,     0,     0,    51,     0,     0,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   132,
    1430,     0,     0,   373,     0,     0,   135,   136,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   383,     0,     0,     0,   144,     0,     0,
       0,     0,   246,     0,    95,   237,     0,   150,     0,   471,
      99,   100,   101,     0,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   239,     0,     0,     0,
       0,     0,     0,     0,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,     0,     0,   241,     0,
       0,   242,     0,   243,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,     0,     0,     0,     0,     0,    40,
      41,    42,    43,    44,     0,     0,     0,    48,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,  1482,     0,     0,
       0,   373,     0,     0,     0,     0,   132,     0,     0,     0,
       0,     0,     0,   135,   136,   137,     0,     0,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
     383,     0,     0,     0,   144,     0,     0,     0,     0,   246,
       0,    95,   237,     0,   150,     0,   695,    99,   100,   101,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   239,     0,     0,     0,     0,     0,     0,
       0,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,     0,   241,     0,     0,   242,     0,
     243,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,     0,     0,     0,     0,     0,    40,    41,    42,    43,
      44,     0,     0,     0,    48,     0,     0,    51,     0,     0,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     478,   371,   372,   132,   477,     0,     0,   373,     0,     0,
     135,   136,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   245,     0,     0,
       0,   144,     0,     0,     0,     0,   246,     0,    95,   237,
       0,   150,     0,  1168,    99,   100,   101,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     239,     0,     0,     0,     0,     0,     0,     0,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
       0,     0,   241,     0,     0,   242,     0,   243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,     0,     0,
       0,     0,     0,    40,    41,    42,    43,    44,     0,     0,
       0,    48,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   609,   371,   372,     0,
       0,     0,     0,   373,     0,     0,     0,     0,     0,     0,
     132,     0,     0,     0,     0,     0,     0,   135,   136,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   431,  1264,     0,     0,     0,   144,     0,
       0,     0,     0,   433,     0,    95,   273,   284,   150,     0,
     207,    99,   100,   101,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,     0,     0,
     123,   124,   125,   126,   127,   128,   129,     0,     0,   130,
      95,   273,   284,     0,     0,     0,    99,   100,   101,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     0,     0,     0,   123,   124,   125,   126,   127,
     128,   129,    95,   273,   130,     0,     0,     0,    99,   100,
     101,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,     0,     0,   132,   133,   134,
       0,     0,   128,   129,   135,   136,   137,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,     0,     0,     0,   144,     0,     0,     0,     0,
     246,     0,     0,     0,     0,   150,     0,  1108,     0,     0,
       0,     0,   132,   133,   134,     0,     0,     0,     0,   135,
     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   143,     0,     0,     0,
     144,     0,     0,     0,     0,   246,     0,     0,     0,     0,
     150,     0,  1279,     0,   132,     0,     0,     0,     0,     0,
       0,   135,   136,   137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,   143,     0,
       0,     0,   144,     0,     0,     0,     0,   246,     0,     0,
     682,     0,   150,     0,   683,    95,   273,  1472,     0,     0,
       0,    99,   100,   101,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,     0,     0,
       0,    95,   273,     0,     0,   128,   129,    99,   100,   101,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,    95,   273,     0,
       0,   128,   129,    99,   100,   101,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,   132,     0,     0,
       0,     0,     0,     0,   135,   136,   137,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,     0,     0,     0,   144,     0,     0,     0,     0,
     246,     0,     0,   132,     0,   150,     0,  1473,     0,     0,
     135,   136,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,     0,     0,
       0,   144,     0,     0,     0,     0,   246,     0,     0,   132,
       0,   150,     0,   343,     0,     0,   135,   136,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   431,   432,     0,     0,     0,   144,     0,     0,
       0,     0,   433,     0,    95,   237,     0,   150,     0,   207,
      99,   100,   101,     0,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   239,     0,     0,     0,
       0,     0,     0,     0,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,     0,     0,   241,     0,
       0,   242,     0,   243,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,     0,     0,     0,     0,     0,    40,
      41,    42,    43,    44,     0,     0,     0,    48,    95,   273,
      51,     0,     0,     0,    99,   100,   101,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     705,     0,     0,     0,     0,     0,   132,     0,   128,   129,
       0,     0,     0,   135,   136,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
     383,     0,     0,     0,   144,    95,   273,   284,     0,   246,
       0,    99,   100,   101,   150,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   806,     0,     0,
     123,   124,   125,   126,   127,   128,   129,     0,     0,   130,
       0,     0,     0,     0,     0,     0,   903,     0,     0,     0,
     132,     0,     0,     0,     0,     0,     0,   135,   136,   137,
       0,     0,     0,     0,     0,  1054,     0,     0,     0,     0,
       0,     0,     0,   142,   143,     0,     0,     0,   144,     0,
       0,     0,     0,   246,     0,     0,     0,     0,   150,     0,
       0,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,     0,     0,     0,     0,   373,
       0,     0,     0,     0,     0,     0,     0,   132,   133,   134,
       0,     0,     0,     0,   135,   136,   137,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,     0,     0,     0,   144,     0,     0,     0,     0,
     246,     0,     0,     0,     0,   150,     0,     0,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,     0,     0,     0,     0,   373,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,    -4,     1,     0,   373,    -4,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,     0,
       0,     0,     0,   373,     0,     0,     0,    -4,    -4,     0,
    1244,     0,  1245,     0,     0,     0,    -4,    -4,     0,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     6,    -4,    -4,     0,     0,     0,
      -4,     0,     7,     8,     0,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     9,    10,     0,    -4,
      -4,    -4,    -4,     0,     0,    11,    12,     0,    13,    14,
      15,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     0,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     7,     8,    54,    55,   993,     0,     0,    56,
       0,     0,     0,     0,    57,    58,    59,    60,     0,     0,
      61,     0,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,     0,    74,    75,
      76,    77,     0,     0,   576,    19,    20,   577,    22,    23,
     578,    25,   579,    27,     0,    28,     0,     0,    31,    32,
       0,    34,    35,    36,     0,     0,     0,    39,     0,     0,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,     0,     0,     0,     0,    58,    59,    60,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
       0,     0,     0,  1274,     0,  1275,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,     0,     0,
       0,  1369,     0,  1370,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,     0,     0,
       0,   835,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,     0,     0,     0,     0,     0,     0,   878,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,     0,     0,     0,     0,     0,     0,   897,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
       0,     0,     0,     0,     0,   922,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,     0,     0,
       0,     0,     0,  1010,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,     0,     0,
       0,  1242,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,     0,     0,     0,     0,     0,     0,  1261,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,     0,     0,     0,     0,     0,     0,  1304,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
       0,     0,     0,     0,     0,  1305,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,     0,     0,
       0,     0,     0,  1306,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,     0,     0,
       0,  1307,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,     0,     0,     0,     0,     0,     0,  1340,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,     0,     0,     0,     0,     0,     0,  1385,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
       0,     0,     0,     0,     0,  1391,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,     0,     0,
       0,     0,     0,  1392,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,     0,     0,
       0,  1412,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,     0,     0,     0,     0,     0,     0,  1415,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,     0,     0,     0,     0,     0,     0,  1418,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
       0,     0,     0,     0,     0,  1440,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,     0,     0,
       0,     0,     0,  1443,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,     0,     0,
       0,  1476,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,     0,     0,     0,     0,     0,     0,  1478,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,     0,     0,     0,     0,     0,     0,  1480,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
       0,     0,     0,     0,     0,  1493,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,     0,     0,
       0,     0,   641,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,     0,     0,     0,
       0,   373,     0,     0,     0,     0,     0,     0,     0,  1316,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
     692,     0,     0,     0,     0,   645,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,     0,     0,
       0,   602,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,     0,     0,     0,     0,   645,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
       0,     0,     0,   646,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,     0,   702,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,     0,     0,     0,     0,   750,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,     0,     0,
       0,   751,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,     0,     0,     0,     0,   764,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
       0,     0,     0,   765,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,     0,   766,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,     0,     0,     0,     0,   767,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,     0,     0,
       0,   768,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,     0,     0,     0,     0,   769,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
       0,     0,     0,   863,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,     0,   864,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,     0,     0,     0,     0,   865,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,     0,     0,
       0,   972,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,     0,     0,     0,     0,  1008,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
       0,     0,     0,  1009,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,     0,  1053,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,     0,     0,     0,     0,  1189,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,     0,     0,
       0,  1190,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,     0,     0,     0,     0,  1212,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
       0,     0,     0,  1350,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,     0,  1351,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,     0,     0,     0,     0,  1357,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,     0,     0,
       0,  1434,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,     0,     0,     0,     0,  1437,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
     568,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,     0,     0,     0,     0,   373,
       0,     0,     0,   707,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,     0,     0,   714,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,     0,     0,     0,     0,   373,     0,     0,     0,   729,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,     0,   731,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,     0,     0,     0,
       0,   373,     0,     0,     0,   733,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,   735,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,     0,     0,     0,     0,   373,     0,     0,
       0,   737,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,     0,   739,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,     0,
       0,     0,     0,   373,     0,     0,     0,   741,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
     743,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,     0,     0,     0,     0,   373,
       0,     0,     0,   745,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,     0,     0,   747,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,     0,     0,     0,     0,   373,     0,     0,     0,   749,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,     0,   753,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,     0,     0,     0,
       0,   373,     0,     0,     0,   755,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,   757,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,     0,     0,     0,     0,   373,     0,     0,
       0,   759,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,     0,   761,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,     0,
       0,     0,     0,   373,     0,     0,     0,   763,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
     886,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,     0,     0,     0,     0,   373,
       0,     0,     0,   887,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,     0,     0,   891,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,     0,     0,     0,     0,   373,     0,     0,     0,   892,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
       0,     0,   895,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,     0,     0,     0,
       0,   373,     0,     0,     0,   918,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,     0,     0,  1071,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,     0,     0,     0,     0,   373,     0,     0,
       0,  1073,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,     0,     0,  1075,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,     0,
       0,     0,     0,   373,     0,     0,     0,  1077,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,     0,     0,
    1078,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,     0,     0,     0,     0,   373,
       0,     0,     0,  1205,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,     0,     0,  1329,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,     0,     0,     0,     0,   373,     0,   564,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,   608,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,     0,     0,     0,     0,   373,     0,   612,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
     613,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,     0,     0,     0,     0,   373,
       0,   615,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,   617,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,     0,     0,     0,
       0,   373,     0,   618,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,   621,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,     0,
       0,     0,     0,   373,     0,   622,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,   692,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,     0,     0,     0,     0,   373,     0,   698,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,   699,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,     0,     0,     0,     0,   373,     0,   700,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
     706,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,     0,     0,     0,     0,   373,
       0,   728,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,   730,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,     0,     0,     0,
       0,   373,     0,   732,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,   734,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,     0,
       0,     0,     0,   373,     0,   736,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,   738,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,     0,     0,     0,     0,   373,     0,   740,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,   742,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,     0,     0,     0,     0,   373,     0,   744,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
     746,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,     0,     0,     0,     0,   373,
       0,   748,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,   752,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,     0,     0,     0,
       0,   373,     0,   754,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,   756,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,     0,
       0,     0,     0,   373,     0,   758,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,   760,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,     0,     0,     0,     0,   373,     0,   762,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,   824,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,     0,     0,     0,     0,   373,     0,   829,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
     834,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,     0,     0,     0,     0,   373,
       0,   836,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,   837,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,     0,     0,     0,
       0,   373,     0,   843,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,   850,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,     0,
       0,     0,     0,   373,     0,   851,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,   852,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,     0,     0,     0,     0,   373,     0,   877,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,   879,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,     0,     0,     0,     0,   373,     0,   880,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
     881,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,     0,     0,     0,     0,   373,
       0,   885,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373,     0,  1070,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,     0,     0,     0,
       0,   373,     0,  1072,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,     0,     0,
       0,     0,   373,     0,  1074,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,     0,
       0,     0,     0,   373,     0,  1076,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,     0,   373,     0,  1084,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,     0,     0,     0,     0,   373,     0,  1243,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,     0,     0,     0,     0,   373,     0,  1260,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,     0,     0,     0,     0,   373,     0,  1278,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,     0,     0,     0,     0,   373,     0,
    1433,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,     0,     0,     0,     0,   373,
       0,  1491,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     0,     0,     0,     0,
     373
};

static const yytype_int16 yycheck[] =
{
       6,     4,     3,  1166,     6,   425,   426,     6,     4,     6,
       4,   215,   345,     4,     6,   348,     5,     4,     6,     4,
       4,     0,    54,   227,     4,    57,     4,     4,    60,   799,
     872,     4,     4,   158,     4,     4,     7,     5,    57,     5,
     165,    60,     6,     6,     6,   148,   149,     4,     6,     6,
     161,   148,   149,   164,   328,   329,   330,   331,   332,   333,
     334,    75,   165,   337,   338,   339,   270,   164,   272,   166,
      84,     4,   159,     6,   876,    77,    54,   164,    92,    93,
      58,     7,    96,    97,     8,   634,   635,   636,    41,    42,
      68,    44,    98,   148,   149,     6,     6,   100,   101,   102,
     103,    78,    79,    80,    81,   148,   149,   155,   156,    86,
      98,   166,    89,   148,   149,   158,   148,   149,     7,   110,
     111,    54,   165,   110,   111,  1288,   158,    57,   158,   164,
      60,   166,   158,   165,   119,   165,    98,   148,   149,   165,
     142,   143,   144,   148,   149,   147,   148,    13,   145,   159,
     151,   158,  1315,   145,   165,   165,   158,    60,   165,   164,
     162,   166,   158,   166,   158,     6,     7,   169,   170,   171,
     172,   165,   174,   175,   176,   177,   165,   179,   180,   181,
     165,   165,   155,   156,  1026,   165,   158,   160,   958,   162,
      60,   162,    62,   165,   167,   165,   165,   165,   200,   165,
     158,   165,   165,   160,   206,   207,   158,   165,     7,   135,
     136,   137,   138,   215,   158,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   155,
     156,   564,   436,   157,     6,   568,   162,   148,   149,   148,
     149,     6,   166,   245,   246,   247,   135,   136,   137,   138,
     203,   204,     6,   255,   256,   257,   165,   259,   211,     6,
     262,   263,   215,   159,   266,     7,   155,   156,   164,   155,
     156,   158,   158,  1436,   160,    57,   162,   279,    60,   165,
      62,   167,   486,   160,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   158,  1097,   160,   148,
     149,   148,   149,   607,   336,   159,   135,   136,   137,   138,
     164,   343,     4,     5,   346,   164,   160,   164,    54,   348,
    1513,    57,   161,   158,    60,   164,    62,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   188,   189,   190,   158,    38,    39,    40,    41,
      42,   383,   158,    54,   160,    47,    57,   389,   158,    60,
     160,    62,   394,   135,   136,   137,   138,   399,   400,   401,
     402,   150,   151,   152,   406,   221,   222,     8,   157,   411,
     412,   413,   158,   155,   156,   155,   156,   233,   234,   158,
     161,   160,   162,   164,   425,   426,   428,   429,   430,   431,
     432,   433,   148,   149,   158,   437,   438,   439,   440,   441,
     714,   148,   149,   445,     6,   158,   448,   449,   164,    64,
     452,   453,   454,     4,     5,   457,   458,   164,   460,   161,
      60,   463,   164,   159,   126,   127,   148,   149,   164,   471,
     423,   424,   159,     6,     7,   477,   478,   164,   431,   148,
     149,     5,   164,   148,   149,   148,   149,    38,    39,    40,
      41,    42,   159,    60,   496,   164,    47,   164,   500,   164,
       6,   503,   776,   502,    60,   779,   780,    60,   782,   148,
     149,   158,   786,   160,    38,    39,    40,    41,    42,    62,
     148,   149,  1324,    47,  1326,   164,  1328,  1297,   159,   158,
     164,  1373,   166,   164,  1376,   809,   164,  1379,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    57,   165,   148,   149,   157,   148,   149,   155,
     156,   165,   159,   569,   160,   166,   162,   164,   570,   568,
     164,   167,   158,   164,   160,   126,   127,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    60,    60,   148,   149,   157,   164,   599,   166,   601,
     602,    57,   126,   127,   155,   156,   158,   609,   610,   164,
      57,   162,    57,    60,   947,    62,  1458,   950,   951,   148,
     149,   623,   158,  1425,   160,     4,   628,   633,   634,   635,
     636,   633,   634,   635,   636,   164,   148,   149,     4,   641,
     148,   149,     4,   645,   646,   158,     6,   148,   149,   651,
      75,   158,   164,   148,   149,  1497,   164,     6,  1500,    84,
     158,  1503,   664,   164,  1506,   667,   160,    92,    93,   164,
       4,    96,    97,  1475,   165,  1477,     6,  1479,   158,   681,
     160,   683,   158,  1485,   160,   687,   688,   689,   690,   148,
     149,   644,  1534,   695,  1536,   158,  1538,   160,   651,   164,
     702,   166,   704,   705,   657,   164,   158,     4,   152,   158,
     158,   160,   160,     7,    75,   714,   158,   158,  1520,   170,
    1522,   158,  1524,    84,   175,   158,  1146,  1147,   179,   158,
     158,    92,    93,     4,   158,    96,    97,   158,   182,   160,
       8,   166,   148,   149,   150,   151,   152,   158,   750,   751,
     158,   157,   160,     6,   158,   199,   160,   158,   202,   160,
       6,     5,   764,   765,   766,   767,   768,   769,   770,     6,
       5,   773,   170,   775,   158,   158,   160,   175,   158,   223,
     160,   179,   784,   158,   158,   160,   788,   158,   158,   160,
     792,   158,   165,   160,   245,   158,   247,   160,     4,   158,
     802,   803,   804,   805,   806,   166,   158,   158,  1082,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   164,   164,   166,   166,   157,   165,     3,
       4,  1105,   276,   277,   158,     9,    10,    11,   158,   158,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   160,   164,   162,   166,   818,   164,   158,   166,    43,
      44,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    75,   165,   165,   890,   157,
     160,   159,   343,   158,    84,   346,   895,   158,   158,  1319,
       7,   903,    92,    93,     6,   160,    96,    97,    75,   165,
     863,   864,   865,   164,   164,   166,   166,    84,    75,   164,
     160,   166,   924,   925,   165,    92,    93,    84,   160,    96,
      97,   164,   383,   166,   165,    92,    93,     5,     5,    96,
      97,    60,   164,    62,   166,   343,     5,   164,   346,   166,
       6,   125,   951,   164,   164,   166,   166,   959,   132,   133,
     134,   164,   164,   166,   166,   162,   164,   973,   166,     6,
     972,   973,   165,   113,   148,   149,   166,     4,   164,   153,
     166,   164,     6,   166,   158,     6,   164,   161,   166,   163,
       6,   165,   164,   164,   166,   166,   164,   160,   166,   166,
     165,   452,   453,   454,     6,  1007,  1008,  1009,   164,   166,
     166,     4,   164,     6,   166,  1017,  1018,   164,   157,   166,
     471,   162,   164,  1025,   166,     7,   164,   478,   166,   160,
     165,  1033,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   166,     6,    12,    13,
     157,  1053,  1054,  1055,   452,   453,   454,     7,     7,   164,
      75,   166,  1064,  1062,   164,     7,   166,  1069,   164,    84,
     166,   158,  1025,   471,   164,   158,   166,    92,    93,     7,
     158,    96,    97,  1089,   164,   164,   166,   166,  1090,   158,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       6,    65,  1108,     7,    68,    69,  1108,    71,    72,    73,
    1112,   159,   164,    77,   166,     6,  1118,  1119,   164,     7,
     166,  1123,   566,   164,   164,   166,   166,     6,  1130,  1333,
     164,   164,   166,   166,     6,   164,  1142,   166,  1140,     6,
    1142,   105,   106,   107,     4,  1146,  1147,   164,   599,   166,
     601,   166,  1154,   164,    75,   166,   165,   165,   609,   610,
    1113,    75,  1164,    84,   165,     6,  1168,   165,   165,  1171,
      84,    92,    93,   110,   159,    96,    97,  1183,    92,    93,
     164,  1183,    96,    97,   164,   629,   166,  1189,  1190,   164,
     641,   166,   159,   159,   164,  1148,   640,  1150,   159,  1152,
       6,   599,   166,   601,   164,     4,   164,   164,   161,     6,
    1212,  1164,     6,     4,  1167,  1168,  1490,     6,   113,     7,
       7,     7,  1426,     7,   113,     7,     7,   113,     7,     7,
     681,     4,   683,   162,     6,   166,   687,   688,   689,   690,
     166,     6,  1244,   641,   695,   166,   161,    75,     7,     7,
       7,   162,   166,  1527,     6,  1529,    84,   165,   158,   158,
    1262,     6,  1264,   165,    92,    93,     4,   711,    96,    97,
       6,   161,  1274,     6,  1276,  1549,   159,  1279,     7,     6,
     160,     6,  1284,   681,   145,   683,     7,  1289,     7,   687,
     688,   689,   690,    60,     7,     7,    62,   695,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     7,     7,  1316,     7,   157,     6,  1319,    75,
       7,  1323,   773,  1325,   775,  1327,   159,   159,    84,   159,
     159,     7,     7,     7,     6,  1337,    92,    93,   166,  1341,
      96,    97,     4,     4,   165,   158,     6,    75,  1350,  1351,
       7,   802,   803,   804,   805,  1357,    84,     6,   165,     7,
       7,     7,     6,  1365,    92,    93,     6,  1369,    96,    97,
    1323,     6,  1325,     6,  1327,   773,    60,   775,   822,   823,
       6,   825,  1335,   827,   828,  1338,     4,   831,   832,     4,
       4,   166,   162,  1395,     6,     4,     6,   158,     6,    12,
      13,   165,   164,     7,   802,   803,   804,   805,   159,   159,
     166,  1413,   159,     6,  1416,    68,   165,  1419,     6,   165,
       6,  1423,   165,     6,   165,  1427,     6,  1429,     6,     5,
       4,     6,  1434,   165,     7,  1437,     7,  1439,   166,     7,
       7,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     7,    65,   160,   165,    68,    69,     6,    71,    72,
      73,   905,   906,   907,    77,     6,   165,   165,  1470,    75,
       6,   915,    12,    13,   165,   161,  1429,   159,    84,    75,
       6,   109,   926,     6,   164,  1487,    92,    93,    84,     6,
      96,    97,   105,   106,   107,   162,    92,    93,     6,     4,
      96,    97,     6,     6,     6,     6,     6,     6,     6,     6,
       6,  1517,     5,  1515,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     6,    65,     6,     6,    68,    69,
       6,    71,    72,    73,   978,     6,   113,    77,     6,  1545,
     984,     6,   164,     6,     6,     6,   990,   991,   992,     6,
       4,     6,   996,   166,   165,     6,   159,  1001,  1002,  1003,
     166,     6,     6,   162,     7,   105,   106,   107,     6,     6,
     166,     5,    58,  1017,     6,     6,     6,     6,     6,     6,
     165,   165,  1033,  1027,   166,   166,   165,  1031,     6,     3,
       4,     7,   108,   165,     6,     9,    10,    11,     6,   165,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,   165,     6,   166,     6,   166,   111,     6,    43,
      44,     6,     6,     6,   165,  1033,     6,     6,     6,     6,
      54,   165,  1086,    57,  1088,   166,    60,     6,    62,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    72,   165,
      75,     6,   157,     4,    78,    79,    80,    81,    82,     4,
       6,   165,    86,     6,     6,    89,     6,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,  1133,
    1134,  1135,  1136,   157,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     6,     6,
       6,   125,   157,  1164,     6,     6,   166,  1168,   132,   133,
     134,     6,  1166,   165,   165,     6,   165,     6,     6,     6,
       6,     6,   165,  1177,   148,   149,     6,     6,     6,   153,
    1184,   165,   165,   165,   158,   165,     6,  1191,     6,   163,
       6,   165,   166,     6,     6,     6,     6,     6,   970,  1395,
       3,     4,   381,   977,     3,     3,     9,    10,    11,   405,
    1093,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,  1473,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    12,    13,     6,
      -1,    54,    -1,  1264,    57,  1259,    -1,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1279,    72,
       7,     8,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      -1,    -1,    -1,    86,  1288,    -1,    89,    -1,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    -1,     6,    68,    69,  1316,    71,    72,    73,    -1,
      -1,  1315,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1279,   125,    -1,    -1,    -1,  1337,    -1,  1332,   132,
     133,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,    -1,    -1,   148,   149,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,  1316,    -1,
     163,    -1,    -1,   166,    -1,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,  1381,    -1,  1337,
       6,   157,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,     6,
     157,   166,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,  1427,    -1,  1429,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1436,    -1,  1438,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,  1470,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,  1427,
       7,  1429,     9,    10,    11,    -1,  1487,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    -1,  1513,
      47,    12,    13,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,  1487,
      -1,   157,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    -1,    -1,    68,    69,    -1,
      71,    72,    73,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,
     137,   138,    -1,    -1,   105,   106,   107,    -1,    -1,    -1,
      -1,   148,   149,    -1,    -1,    -1,   153,    -1,   155,   156,
      -1,   158,    -1,   160,    -1,   162,   163,    -1,   165,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,   166,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    57,    -1,    -1,    60,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    -1,
      -1,    -1,    86,    -1,    -1,    89,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    -1,    -1,
      68,    69,    -1,    71,    72,    73,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
     134,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
      -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,   153,
      -1,    -1,    -1,    -1,   158,    -1,     3,     4,     5,   163,
      -1,   165,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,   166,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      57,    -1,    -1,    60,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    -1,    -1,    -1,    86,
      -1,    -1,    89,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    -1,    -1,    68,    69,    -1,
      71,    72,    73,    -1,    -1,    -1,    77,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,     6,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,    -1,
      -1,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,   158,    -1,     3,     4,     5,   163,    -1,   165,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    -1,    -1,
      60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    -1,    -1,    -1,    86,    -1,    -1,    89,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   125,     6,    -1,    -1,   157,
      -1,    -1,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
      -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,   158,    -1,
       3,     4,    -1,   163,    -1,   165,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    57,    -1,    -1,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     6,    -1,    -1,    -1,   157,    -1,    -1,
      -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,   134,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,   158,    -1,     3,     4,    -1,
     163,    -1,   165,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    57,    -1,    -1,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   125,
       6,    -1,    -1,   157,    -1,    -1,   132,   133,   134,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,
      -1,    -1,   158,    -1,     3,     4,    -1,   163,    -1,   165,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    -1,
      -1,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    -1,    -1,    -1,    86,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     6,    -1,    -1,
      -1,   157,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,   158,
      -1,     3,     4,    -1,   163,    -1,   165,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    57,    -1,    -1,    60,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   125,     8,    -1,    -1,   157,    -1,    -1,
     132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,    -1,
      -1,   153,    -1,    -1,    -1,    -1,   158,    -1,     3,     4,
      -1,   163,    -1,   165,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    57,    -1,    -1,    60,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    -1,    -1,
      -1,    86,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,
     125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,   158,    -1,     3,     4,     5,   163,    -1,
     165,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,     3,     4,    47,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,   125,   126,   127,
      -1,    -1,    43,    44,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,
     158,    -1,    -1,    -1,    -1,   163,    -1,   165,    -1,    -1,
      -1,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
     133,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
     163,    -1,   165,    -1,   125,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
     161,    -1,   163,    -1,   165,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    43,    44,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,    43,    44,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,
      -1,    -1,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,
     158,    -1,    -1,   125,    -1,   163,    -1,   165,    -1,    -1,
     132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,    -1,
      -1,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,   125,
      -1,   163,    -1,   165,    -1,    -1,   132,   133,   134,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,
      -1,    -1,   158,    -1,     3,     4,    -1,   163,    -1,   165,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    -1,
      -1,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    -1,    -1,    -1,    86,     3,     4,
      89,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       8,    -1,    -1,    -1,    -1,    -1,   125,    -1,    43,    44,
      -1,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,    -1,    -1,    -1,   153,     3,     4,     5,    -1,   158,
      -1,     9,    10,    11,   163,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     8,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
     125,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,     0,     1,    -1,   157,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,    36,    37,    -1,
     164,    -1,   166,    -1,    -1,    -1,    45,    46,    -1,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,     4,    94,    95,    -1,    -1,    -1,
      99,    -1,    12,    13,    -1,   104,   105,   106,   107,    -1,
      -1,   110,    -1,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    36,    37,    -1,   128,
     129,   130,   131,    -1,    -1,    45,    46,    -1,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    12,    13,    94,    95,    75,    -1,    -1,    99,
      -1,    -1,    -1,    -1,   104,   105,   106,   107,    -1,    -1,
     110,    -1,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,   128,   129,
     130,   131,    -1,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    -1,    -1,    68,    69,
      -1,    71,    72,    73,    -1,    -1,    -1,    77,    -1,    -1,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,    -1,    -1,    -1,   105,   106,   107,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
      -1,    -1,    -1,   164,    -1,   166,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,   164,    -1,   166,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
     159,    -1,    -1,    -1,    -1,   164,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,   164,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
      -1,    -1,    -1,   164,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,   164,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,   164,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
      -1,    -1,    -1,   164,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,   164,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,   164,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
      -1,    -1,    -1,   164,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,   164,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,   164,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
      -1,    -1,    -1,   164,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,   164,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,   164,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
      -1,    -1,    -1,   164,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,   164,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,   164,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
     161,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,   161,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,   161,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,   161,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,   161,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,
      -1,   161,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,   161,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,   161,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
     161,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,   161,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,   161,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,   161,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,   161,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,
      -1,   161,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,   161,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,   161,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
     161,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,   161,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,   161,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,   161,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,   161,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,
      -1,   161,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,   161,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,   161,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
     161,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,   161,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,   161,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,    -1,   159,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,   159,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,   159,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
     159,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
      -1,   159,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,   159,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,    -1,   159,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,   159,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,    -1,   159,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,   159,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,    -1,   159,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,   159,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,   159,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
     159,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
      -1,   159,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,   159,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,    -1,   159,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,   159,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,    -1,   159,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,   159,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,    -1,   159,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,   159,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,   159,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
     159,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
      -1,   159,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,   159,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,    -1,   159,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,   159,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,    -1,   159,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,   159,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,    -1,   159,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,   159,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,   159,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
     159,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
      -1,   159,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,   159,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,    -1,   159,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,   159,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,    -1,   159,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,   159,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,    -1,   159,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,   159,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,   159,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
     159,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
      -1,   159,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,    -1,   159,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,    -1,   159,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,    -1,   159,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,    -1,   159,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,    -1,   159,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,    -1,   159,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,    -1,   159,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,   159,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,
     159,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
      -1,   159,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   169,   170,     6,     0,     4,    12,    13,    36,
      37,    45,    46,    48,    49,    50,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    94,    95,    99,   104,   105,   106,
     107,   110,   112,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   128,   129,   130,   131,   171,   173,
     174,   192,   206,   211,   214,   215,   216,   217,   218,   219,
     220,   240,   241,   242,   243,     3,     4,     5,     7,     9,
      10,    11,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    38,    39,    40,    41,    42,    43,    44,
      47,   119,   125,   126,   127,   132,   133,   134,   135,   136,
     137,   138,   148,   149,   153,   155,   156,   158,   160,   162,
     163,   165,   190,   191,   244,   245,   257,    13,    60,   158,
     158,     6,   165,     6,     6,     6,     6,   160,   160,   158,
     165,   158,   158,     4,   158,   165,   158,   158,     4,   165,
     158,   158,    64,    60,    60,     6,    60,    60,    57,    60,
      62,    62,    54,    57,    60,    62,    57,    60,    62,    57,
      60,   158,    57,   165,   148,   149,   158,   165,   246,   247,
     246,   165,    54,    57,    60,   165,   246,     4,    54,    58,
      68,    60,    62,    60,    57,     4,   119,   165,     4,     6,
      54,    57,    60,    57,    60,     4,     4,     4,     5,    35,
      54,    57,    60,    62,    72,   149,   158,   165,   211,   220,
     244,   249,   250,   251,     4,   158,   158,   158,     4,   165,
     253,     4,   158,   158,     6,     6,   160,     4,     4,     5,
     165,     5,   165,     4,   244,     6,   158,   165,     4,   160,
     162,   167,   191,   165,     5,   257,   158,   160,   158,   160,
     158,   160,   158,   160,   158,   160,   158,   160,   158,   160,
     158,   160,   158,   160,   158,   160,   158,   160,   158,   160,
     158,   160,   158,   160,   158,   160,   158,   160,   158,   160,
     158,   160,   158,   160,   158,   160,   158,   160,   158,   160,
     158,   158,   158,   158,   158,   158,     7,   158,   158,   158,
     244,   244,   244,   165,   244,   161,   165,   244,     4,   110,
     111,     4,     4,   211,   212,   213,   249,     6,     6,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   157,     6,     6,   244,     5,     5,   244,
     194,   197,   244,   149,   244,   251,   252,   244,   244,   158,
     244,   252,   244,   244,   158,   252,   244,   244,   249,   158,
     165,   158,   158,   250,   250,   250,   158,   207,   208,   209,
     210,   158,   158,   158,   249,   244,     4,   249,   246,   246,
     246,   244,   244,   148,   149,   165,   165,   246,   165,   165,
     165,   148,   149,   158,   213,   246,   165,   158,   165,   158,
     158,   158,   250,   250,   249,   158,     4,     6,   160,   160,
     213,     6,   165,   165,   165,   250,   250,   160,   160,   158,
     160,   160,     5,   165,     5,     5,     5,    54,    57,    60,
      62,   165,   244,   251,   244,   166,   252,     8,   150,     6,
       6,   244,   244,   244,   162,   244,   165,   113,   244,   244,
     244,     6,     6,   213,     6,   213,   160,     6,   249,   249,
     160,   244,     4,   165,   175,     6,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,     4,   256,
     257,   256,   256,   256,   256,   256,   256,   256,   258,   244,
     256,   256,   256,   252,   159,     7,   190,   252,   161,     7,
     190,   191,   162,     7,   160,   166,    54,    57,    60,    62,
     206,     6,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,     6,   159,   164,
     159,   164,   164,   161,   164,   193,   161,   193,   159,   150,
     164,   166,   159,   159,   244,   159,   166,   159,   159,   244,
     166,   159,   159,     7,   244,   244,   244,   244,     7,     7,
     238,   238,   244,   158,   158,   158,   158,   244,   244,   244,
       7,   165,   159,     6,   164,   164,   164,   246,   246,   212,
     212,   164,   244,   244,   244,   244,   224,   164,   213,   244,
     244,   244,   244,   244,     7,   239,     6,     7,   244,     6,
     244,   244,   166,   252,   252,   252,     6,     6,   244,   244,
     159,   165,   161,   165,   244,     4,   244,   165,   165,   165,
     165,   252,   159,   166,   244,   165,   244,   251,   159,   159,
     159,   110,   164,   213,   165,     8,   159,   161,   166,   166,
     159,   164,   166,   244,   161,   191,   244,     4,   100,   101,
     102,   103,   166,   178,   182,   185,   187,   188,   159,   161,
     159,   161,   159,   161,   159,   161,   159,   161,   159,   161,
     159,   161,   159,   161,   159,   161,   159,   161,   159,   161,
     164,   164,   159,   161,   159,   161,   159,   161,   159,   161,
     159,   161,   159,   161,   164,   164,   164,   164,   164,   164,
     160,   162,   159,   164,   161,   164,   164,   159,   159,   164,
     164,   159,   164,     6,   164,   159,   164,   166,   190,   249,
     166,   162,   190,   191,   257,   244,     6,     4,     4,   165,
     254,   161,   165,   165,   165,   165,     8,     6,   145,   172,
     252,     6,   252,   244,     6,     4,     6,   256,     7,   244,
     251,   113,     7,     7,   159,     7,   113,     7,     7,   159,
     113,     7,     7,   244,   159,   166,   159,   159,   244,   249,
       4,   237,     6,   159,   203,   244,   257,   203,   203,   203,
     159,   159,   159,   249,   252,   162,   246,   244,   244,   166,
     166,   244,   246,   164,   164,   164,    75,    84,    92,    93,
      96,    97,   234,   235,   246,   166,   221,   159,   166,   159,
     159,   159,   244,     6,   244,   159,   161,   161,   166,   166,
     166,   161,   161,   252,   252,   161,   161,   166,   252,   252,
     252,   252,   166,     8,   252,     7,     7,     7,   162,   244,
     166,   244,   244,     7,   162,   165,   249,     6,   161,   162,
     191,   256,   166,   179,   158,   158,   165,   189,     6,   244,
     244,   244,   244,   244,   244,   244,   244,   244,     4,   252,
     252,   256,   256,   256,   256,   244,   256,   159,   244,     6,
     161,     4,   110,   111,   244,     6,     6,     6,     7,   160,
     253,   255,     6,   252,   252,   252,   252,   244,   145,   256,
     159,   159,   164,     7,   246,    60,   249,   249,     7,   249,
      60,    62,   249,   249,     7,    62,   249,   249,     6,     7,
       7,     7,     7,    75,   236,     6,     7,   159,   159,   159,
     159,     7,     7,     7,     6,   166,     4,   164,   164,   164,
     166,   166,   246,   246,   246,     4,     6,   165,   158,     6,
      98,     6,    98,   166,   235,   164,   234,     7,     6,     7,
       7,     7,     6,   165,     6,     6,     6,    60,   244,     6,
       6,   166,   166,   166,   166,   166,   166,   244,   166,   249,
     249,   249,     4,   164,     8,     8,   159,     4,     4,   249,
     166,     6,     4,     6,   158,   244,   244,   248,   249,   165,
     159,   161,   159,   161,   159,   161,   159,   161,   161,   159,
     161,   159,   164,   159,   159,   159,   190,     6,   190,     7,
     190,   191,   162,     7,     6,   253,   244,   164,   166,   166,
     166,   166,   166,     6,     6,   172,     6,   244,   165,   244,
     257,     6,   165,    68,   205,   205,   249,     6,   165,   165,
       6,     6,   249,   165,     6,     6,     5,   249,   249,   249,
       4,     6,   249,     7,     7,     7,     7,   249,   249,   249,
       7,     6,     7,   244,   244,   244,   165,   165,   164,   166,
     164,   166,   164,   166,   160,   244,   249,   244,     6,     6,
     244,   246,   166,     5,   165,   249,   165,   165,   165,   249,
     252,   165,     6,   159,   161,     6,     6,   109,   244,   244,
     244,     6,     6,     7,   164,     6,   191,   176,   244,   164,
     164,   164,   166,   177,   244,   162,   256,   249,   249,   257,
     244,     6,     4,   254,     6,   161,   253,     6,     6,     6,
       6,   256,   164,   244,   257,   244,   246,     6,     6,     6,
     244,   244,     6,   244,     5,     6,     6,   113,   204,   244,
       6,   249,   249,   249,   249,     6,     4,     6,     6,   244,
     244,   257,   166,   159,   164,   166,   212,   212,   246,     6,
     225,   246,     6,   226,   246,     6,   227,   244,   166,   164,
     159,   166,   164,     6,   149,   246,     6,   248,   246,   246,
       6,   166,   244,   249,   164,   166,     8,   166,   159,   165,
     244,   257,   249,   159,   164,   244,   244,   249,   165,   164,
     166,     4,   159,     6,     6,     6,     6,     7,     6,   162,
       6,   244,   195,   196,   166,   166,   166,   166,     5,    58,
       6,     6,     6,     6,     6,   165,   165,     6,     6,   165,
     244,   166,   166,   164,   165,   164,   165,   164,   165,   161,
       6,   249,     7,   165,   244,   164,   166,   164,   164,     6,
     166,   108,   244,   244,   252,     6,     6,   166,   180,   244,
     164,   164,   248,   244,     6,   253,   111,   164,   199,   201,
       6,     6,     6,     6,     6,   165,   248,   252,   212,   164,
     166,   244,   246,   234,   244,   246,   234,   244,   246,   234,
       6,   164,   166,   249,   213,   166,   246,     6,   252,   246,
     244,   166,   166,   166,     6,   165,   244,   244,   166,     6,
     244,   164,   166,   200,   164,   166,   202,   244,   166,   166,
     166,   244,   166,   164,   166,   166,   164,   166,   166,   164,
     166,   249,     6,    75,   166,   222,   165,   164,   166,   164,
       6,     6,   177,   159,   164,     6,   165,   164,     4,     4,
     166,     6,     6,   166,     6,   228,   244,     6,     6,   229,
     244,     6,     6,   230,   244,     6,   166,   244,   234,   213,
     252,     6,   246,   252,   166,   183,   244,   248,   244,     5,
     165,   249,     5,   165,   244,   165,   166,   165,   166,   165,
     166,     6,     6,   166,   166,   223,   166,   164,   166,     6,
     165,   159,   166,   166,   198,   244,   258,   234,     6,   231,
     234,     6,   232,   234,     6,   233,   234,     6,   252,     6,
     181,   256,   186,   165,     6,   164,   166,     7,   166,   166,
     165,   166,   165,   166,   165,   166,   166,   164,   166,   165,
     248,   244,   257,     6,   234,     6,   234,     6,   234,     6,
     256,     6,   184,   256,   166,     7,   166,   166,   166,   164,
     166,     6,   257,     6,     6,     6,   256,     6
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
#line 168 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 179 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 180 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 181 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 182 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 183 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 184 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 185 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 186 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 187 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 188 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 189 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 190 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 191 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 192 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 193 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 198 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 22:
#line 202 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 23:
#line 209 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 24:
#line 214 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 25:
#line 219 "Gmsh.y"
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
#line 233 "Gmsh.y"
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
#line 246 "Gmsh.y"
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
#line 259 "Gmsh.y"
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
#line 287 "Gmsh.y"
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
#line 301 "Gmsh.y"
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
#line 312 "Gmsh.y"
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
#line 326 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 38:
#line 340 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 39:
#line 342 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 40:
#line 347 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:
#line 349 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:
#line 354 "Gmsh.y"
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
#line 458 "Gmsh.y"
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
#line 468 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 45:
#line 477 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 46:
#line 484 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 47:
#line 494 "Gmsh.y"
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
#line 503 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 49:
#line 512 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 50:
#line 519 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 51:
#line 529 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 52:
#line 537 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 53:
#line 547 "Gmsh.y"
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
#line 566 "Gmsh.y"
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
#line 585 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 56:
#line 591 "Gmsh.y"
    {
    ;}
    break;

  case 57:
#line 598 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 58:
#line 599 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 59:
#line 600 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 60:
#line 601 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 61:
#line 602 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 62:
#line 606 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 63:
#line 607 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 66:
#line 618 "Gmsh.y"
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
#line 680 "Gmsh.y"
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
#line 710 "Gmsh.y"
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
#line 745 "Gmsh.y"
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
#line 779 "Gmsh.y"
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
#line 827 "Gmsh.y"
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
#line 874 "Gmsh.y"
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
#line 889 "Gmsh.y"
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
#line 905 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 75:
#line 914 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 76:
#line 920 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 77:
#line 929 "Gmsh.y"
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
#line 947 "Gmsh.y"
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
#line 965 "Gmsh.y"
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
#line 974 "Gmsh.y"
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
#line 986 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 82:
#line 991 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 83:
#line 999 "Gmsh.y"
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
#line 1019 "Gmsh.y"
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
#line 1042 "Gmsh.y"
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
#line 1053 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 87:
#line 1061 "Gmsh.y"
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
#line 1083 "Gmsh.y"
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
#line 1106 "Gmsh.y"
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
#line 1132 "Gmsh.y"
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
#line 1153 "Gmsh.y"
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
#line 1165 "Gmsh.y"
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
#line 1183 "Gmsh.y"
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
#line 1194 "Gmsh.y"
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
#line 1205 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 99:
#line 1207 "Gmsh.y"
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
#line 1217 "Gmsh.y"
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
#line 1228 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 102:
#line 1230 "Gmsh.y"
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
#line 1244 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 105:
#line 1252 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 106:
#line 1258 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 109:
#line 1270 "Gmsh.y"
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
#line 1281 "Gmsh.y"
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
#line 1296 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 114:
#line 1312 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 115:
#line 1320 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 116:
#line 1329 "Gmsh.y"
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
#line 1347 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 118:
#line 1351 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 119:
#line 1361 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 120:
#line 1365 "Gmsh.y"
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
#line 1377 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 122:
#line 1381 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 123:
#line 1391 "Gmsh.y"
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
#line 1414 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 125:
#line 1418 "Gmsh.y"
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
#line 1434 "Gmsh.y"
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
#line 1456 "Gmsh.y"
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
#line 1474 "Gmsh.y"
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
#line 1495 "Gmsh.y"
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
#line 1513 "Gmsh.y"
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
#line 1543 "Gmsh.y"
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
#line 1573 "Gmsh.y"
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
#line 1591 "Gmsh.y"
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
#line 1609 "Gmsh.y"
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
#line 1635 "Gmsh.y"
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
#line 1653 "Gmsh.y"
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
#line 1671 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 138:
#line 1675 "Gmsh.y"
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
#line 1694 "Gmsh.y"
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
#line 1712 "Gmsh.y"
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
#line 1751 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 142:
#line 1757 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 143:
#line 1763 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 144:
#line 1770 "Gmsh.y"
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
#line 1795 "Gmsh.y"
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
#line 1820 "Gmsh.y"
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
#line 1837 "Gmsh.y"
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
#line 1855 "Gmsh.y"
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
#line 1885 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 150:
#line 1889 "Gmsh.y"
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
#line 1909 "Gmsh.y"
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
#line 1927 "Gmsh.y"
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
#line 1944 "Gmsh.y"
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
#line 1960 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 155:
#line 1964 "Gmsh.y"
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
#line 1986 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 157:
#line 1991 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 158:
#line 1996 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 159:
#line 2001 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 160:
#line 2006 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 161:
#line 2011 "Gmsh.y"
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
#line 2034 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 163:
#line 2040 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 164:
#line 2050 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 165:
#line 2051 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 166:
#line 2056 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 167:
#line 2060 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 168:
#line 2064 "Gmsh.y"
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
#line 2087 "Gmsh.y"
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
#line 2110 "Gmsh.y"
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
#line 2133 "Gmsh.y"
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
#line 2161 "Gmsh.y"
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
#line 2182 "Gmsh.y"
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
#endif
    ;}
    break;

  case 174:
#line 2206 "Gmsh.y"
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
#line 2227 "Gmsh.y"
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
#line 2248 "Gmsh.y"
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
#line 2268 "Gmsh.y"
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
#line 2380 "Gmsh.y"
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
#line 2399 "Gmsh.y"
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
#line 2438 "Gmsh.y"
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
#line 2546 "Gmsh.y"
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
#line 2555 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 183:
#line 2561 "Gmsh.y"
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
#line 2576 "Gmsh.y"
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
#line 2604 "Gmsh.y"
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
#line 2621 "Gmsh.y"
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
#line 2635 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 188:
#line 2641 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 189:
#line 2647 "Gmsh.y"
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
#line 2656 "Gmsh.y"
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
#line 2670 "Gmsh.y"
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
#line 2715 "Gmsh.y"
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
#line 2732 "Gmsh.y"
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
#line 2747 "Gmsh.y"
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
#line 2766 "Gmsh.y"
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
#line 2778 "Gmsh.y"
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
#line 2802 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 198:
#line 2806 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 199:
#line 2811 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 200:
#line 2818 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 201:
#line 2824 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 202:
#line 2829 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 203:
#line 2835 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 204:
#line 2839 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 205:
#line 2843 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 206:
#line 2848 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    ;}
    break;

  case 207:
#line 2861 "Gmsh.y"
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

  case 208:
#line 2878 "Gmsh.y"
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

  case 209:
#line 2895 "Gmsh.y"
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

  case 210:
#line 2916 "Gmsh.y"
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

  case 211:
#line 2937 "Gmsh.y"
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

  case 212:
#line 2972 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 213:
#line 2980 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 214:
#line 2986 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 215:
#line 2993 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 216:
#line 2997 "Gmsh.y"
    {
    ;}
    break;

  case 217:
#line 3006 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 218:
#line 3014 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 219:
#line 3022 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 220:
#line 3030 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 221:
#line 3035 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 222:
#line 3043 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 223:
#line 3048 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 224:
#line 3056 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 225:
#line 3061 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 226:
#line 3069 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 227:
#line 3074 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 228:
#line 3082 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 229:
#line 3089 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 230:
#line 3096 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 231:
#line 3103 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 232:
#line 3110 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 233:
#line 3117 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 234:
#line 3124 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 235:
#line 3131 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 236:
#line 3138 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 237:
#line 3145 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 238:
#line 3150 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 239:
#line 3157 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 240:
#line 3162 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 241:
#line 3169 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 242:
#line 3174 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 243:
#line 3181 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 244:
#line 3186 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 245:
#line 3193 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 246:
#line 3198 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 247:
#line 3205 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 248:
#line 3210 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 249:
#line 3217 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 250:
#line 3222 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 251:
#line 3229 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 252:
#line 3234 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 253:
#line 3241 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 254:
#line 3246 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 255:
#line 3257 "Gmsh.y"
    {
    ;}
    break;

  case 256:
#line 3260 "Gmsh.y"
    {
    ;}
    break;

  case 257:
#line 3266 "Gmsh.y"
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

  case 258:
#line 3278 "Gmsh.y"
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

  case 259:
#line 3298 "Gmsh.y"
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

  case 260:
#line 3321 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 261:
#line 3325 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 262:
#line 3329 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 263:
#line 3333 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 264:
#line 3337 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 265:
#line 3341 "Gmsh.y"
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

  case 266:
#line 3360 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 267:
#line 3372 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 268:
#line 3376 "Gmsh.y"
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

  case 269:
#line 3391 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 270:
#line 3395 "Gmsh.y"
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

  case 271:
#line 3407 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 272:
#line 3411 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 273:
#line 3416 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 274:
#line 3420 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 275:
#line 3427 "Gmsh.y"
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

  case 276:
#line 3483 "Gmsh.y"
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

  case 277:
#line 3553 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 278:
#line 3558 "Gmsh.y"
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

  case 279:
#line 3625 "Gmsh.y"
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

  case 280:
#line 3661 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 281:
#line 3669 "Gmsh.y"
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

  case 282:
#line 3712 "Gmsh.y"
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

  case 283:
#line 3751 "Gmsh.y"
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

  case 284:
#line 3771 "Gmsh.y"
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

  case 285:
#line 3799 "Gmsh.y"
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

  case 286:
#line 3838 "Gmsh.y"
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

  case 287:
#line 3861 "Gmsh.y"
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

  case 288:
#line 3884 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 289:
#line 3888 "Gmsh.y"
    {
      Msg::Error("Surface in Volume not implemented yet");
    ;}
    break;

  case 290:
#line 3892 "Gmsh.y"
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

  case 291:
#line 3931 "Gmsh.y"
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

  case 292:
#line 3976 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 293:
#line 3980 "Gmsh.y"
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

  case 294:
#line 3990 "Gmsh.y"
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

  case 295:
#line 4024 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 296:
#line 4025 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 297:
#line 4026 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 298:
#line 4031 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 299:
#line 4037 "Gmsh.y"
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

  case 300:
#line 4049 "Gmsh.y"
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

  case 301:
#line 4067 "Gmsh.y"
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

  case 302:
#line 4094 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 303:
#line 4095 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 304:
#line 4096 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 305:
#line 4097 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 306:
#line 4098 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 307:
#line 4099 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 308:
#line 4100 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 309:
#line 4101 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 310:
#line 4103 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 311:
#line 4109 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 312:
#line 4110 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 313:
#line 4111 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 314:
#line 4112 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 315:
#line 4113 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 316:
#line 4114 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 317:
#line 4115 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 318:
#line 4116 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 319:
#line 4117 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 320:
#line 4118 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 321:
#line 4119 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 322:
#line 4120 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 323:
#line 4121 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 324:
#line 4122 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 325:
#line 4123 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 326:
#line 4124 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 327:
#line 4125 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 328:
#line 4126 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 329:
#line 4127 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 330:
#line 4128 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 331:
#line 4129 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 332:
#line 4130 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 333:
#line 4131 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 334:
#line 4132 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 335:
#line 4133 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 336:
#line 4134 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 337:
#line 4135 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 338:
#line 4136 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 339:
#line 4137 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 340:
#line 4138 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 341:
#line 4139 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 342:
#line 4140 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 343:
#line 4143 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 344:
#line 4144 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 345:
#line 4145 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 346:
#line 4146 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 347:
#line 4147 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 348:
#line 4148 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 349:
#line 4149 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 350:
#line 4150 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 351:
#line 4151 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 352:
#line 4152 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 353:
#line 4153 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 354:
#line 4154 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 355:
#line 4155 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 356:
#line 4156 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 357:
#line 4157 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 358:
#line 4158 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 359:
#line 4159 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 360:
#line 4160 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 361:
#line 4161 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 362:
#line 4162 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 363:
#line 4163 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 364:
#line 4172 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 365:
#line 4173 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 366:
#line 4174 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 367:
#line 4175 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 368:
#line 4176 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 369:
#line 4177 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 370:
#line 4178 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 371:
#line 4183 "Gmsh.y"
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

  case 372:
#line 4204 "Gmsh.y"
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

  case 373:
#line 4223 "Gmsh.y"
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

  case 374:
#line 4241 "Gmsh.y"
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

  case 375:
#line 4253 "Gmsh.y"
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

  case 376:
#line 4270 "Gmsh.y"
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

  case 377:
#line 4291 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 378:
#line 4296 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 379:
#line 4301 "Gmsh.y"
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

  case 380:
#line 4311 "Gmsh.y"
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

  case 381:
#line 4321 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 382:
#line 4326 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 383:
#line 4335 "Gmsh.y"
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

  case 384:
#line 4362 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 385:
#line 4366 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 386:
#line 4370 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 387:
#line 4374 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 388:
#line 4378 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 389:
#line 4385 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 390:
#line 4389 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 391:
#line 4393 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 392:
#line 4397 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 393:
#line 4404 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 394:
#line 4409 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 395:
#line 4416 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 396:
#line 4421 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 397:
#line 4425 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 398:
#line 4430 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 399:
#line 4434 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 400:
#line 4442 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 401:
#line 4453 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 402:
#line 4457 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 403:
#line 4469 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 404:
#line 4477 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 405:
#line 4485 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 406:
#line 4492 "Gmsh.y"
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

  case 407:
#line 4502 "Gmsh.y"
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

  case 408:
#line 4522 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 409:
#line 4526 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 410:
#line 4530 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 411:
#line 4534 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 412:
#line 4538 "Gmsh.y"
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

  case 413:
#line 4567 "Gmsh.y"
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

  case 414:
#line 4596 "Gmsh.y"
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

  case 415:
#line 4625 "Gmsh.y"
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

  case 416:
#line 4654 "Gmsh.y"
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

  case 417:
#line 4664 "Gmsh.y"
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

  case 418:
#line 4674 "Gmsh.y"
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

  case 419:
#line 4687 "Gmsh.y"
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

  case 420:
#line 4699 "Gmsh.y"
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

  case 421:
#line 4711 "Gmsh.y"
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

  case 422:
#line 4730 "Gmsh.y"
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

  case 423:
#line 4751 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 424:
#line 4756 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 425:
#line 4760 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 426:
#line 4764 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 427:
#line 4776 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 428:
#line 4780 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 429:
#line 4792 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 430:
#line 4799 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 431:
#line 4809 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 432:
#line 4813 "Gmsh.y"
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

  case 433:
#line 4828 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 434:
#line 4833 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 435:
#line 4840 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 436:
#line 4844 "Gmsh.y"
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

  case 437:
#line 4857 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 438:
#line 4865 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 439:
#line 4876 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 440:
#line 4880 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 441:
#line 4888 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 442:
#line 4896 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 443:
#line 4904 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 444:
#line 4912 "Gmsh.y"
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

  case 445:
#line 4926 "Gmsh.y"
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

  case 446:
#line 4940 "Gmsh.y"
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

  case 447:
#line 4953 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 448:
#line 4958 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 449:
#line 4962 "Gmsh.y"
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

  case 450:
#line 4982 "Gmsh.y"
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

  case 451:
#line 5004 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 452:
#line 5009 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 10202 "Gmsh.tab.cpp"
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


#line 5012 "Gmsh.y"


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

