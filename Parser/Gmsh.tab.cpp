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
     tPlane = 324,
     tRuled = 325,
     tTransfinite = 326,
     tComplex = 327,
     tPhysical = 328,
     tCompound = 329,
     tPeriodic = 330,
     tUsing = 331,
     tPlugin = 332,
     tDegenerated = 333,
     tRotate = 334,
     tTranslate = 335,
     tSymmetry = 336,
     tDilate = 337,
     tExtrude = 338,
     tLevelset = 339,
     tRecombine = 340,
     tSmoother = 341,
     tSplit = 342,
     tDelete = 343,
     tCoherence = 344,
     tIntersect = 345,
     tMeshAlgorithm = 346,
     tReverse = 347,
     tLayers = 348,
     tHole = 349,
     tAlias = 350,
     tAliasWithOptions = 351,
     tQuadTriDbl = 352,
     tQuadTriSngl = 353,
     tRecombLaterals = 354,
     tTransfQuadTri = 355,
     tText2D = 356,
     tText3D = 357,
     tInterpolationScheme = 358,
     tTime = 359,
     tCombine = 360,
     tBSpline = 361,
     tBezier = 362,
     tNurbs = 363,
     tNurbsOrder = 364,
     tNurbsKnots = 365,
     tColor = 366,
     tColorTable = 367,
     tFor = 368,
     tIn = 369,
     tEndFor = 370,
     tIf = 371,
     tEndIf = 372,
     tExit = 373,
     tAbort = 374,
     tField = 375,
     tReturn = 376,
     tCall = 377,
     tFunction = 378,
     tShow = 379,
     tHide = 380,
     tGetValue = 381,
     tGetEnv = 382,
     tGetString = 383,
     tHomology = 384,
     tCohomology = 385,
     tBetti = 386,
     tSetOrder = 387,
     tGMSH_MAJOR_VERSION = 388,
     tGMSH_MINOR_VERSION = 389,
     tGMSH_PATCH_VERSION = 390,
     tAFFECTDIVIDE = 391,
     tAFFECTTIMES = 392,
     tAFFECTMINUS = 393,
     tAFFECTPLUS = 394,
     tOR = 395,
     tAND = 396,
     tNOTEQUAL = 397,
     tEQUAL = 398,
     tGREATEROREQUAL = 399,
     tLESSOREQUAL = 400,
     UNARYPREC = 401,
     tMINUSMINUS = 402,
     tPLUSPLUS = 403
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
#define tPlane 324
#define tRuled 325
#define tTransfinite 326
#define tComplex 327
#define tPhysical 328
#define tCompound 329
#define tPeriodic 330
#define tUsing 331
#define tPlugin 332
#define tDegenerated 333
#define tRotate 334
#define tTranslate 335
#define tSymmetry 336
#define tDilate 337
#define tExtrude 338
#define tLevelset 339
#define tRecombine 340
#define tSmoother 341
#define tSplit 342
#define tDelete 343
#define tCoherence 344
#define tIntersect 345
#define tMeshAlgorithm 346
#define tReverse 347
#define tLayers 348
#define tHole 349
#define tAlias 350
#define tAliasWithOptions 351
#define tQuadTriDbl 352
#define tQuadTriSngl 353
#define tRecombLaterals 354
#define tTransfQuadTri 355
#define tText2D 356
#define tText3D 357
#define tInterpolationScheme 358
#define tTime 359
#define tCombine 360
#define tBSpline 361
#define tBezier 362
#define tNurbs 363
#define tNurbsOrder 364
#define tNurbsKnots 365
#define tColor 366
#define tColorTable 367
#define tFor 368
#define tIn 369
#define tEndFor 370
#define tIf 371
#define tEndIf 372
#define tExit 373
#define tAbort 374
#define tField 375
#define tReturn 376
#define tCall 377
#define tFunction 378
#define tShow 379
#define tHide 380
#define tGetValue 381
#define tGetEnv 382
#define tGetString 383
#define tHomology 384
#define tCohomology 385
#define tBetti 386
#define tSetOrder 387
#define tGMSH_MAJOR_VERSION 388
#define tGMSH_MINOR_VERSION 389
#define tGMSH_PATCH_VERSION 390
#define tAFFECTDIVIDE 391
#define tAFFECTTIMES 392
#define tAFFECTMINUS 393
#define tAFFECTPLUS 394
#define tOR 395
#define tAND 396
#define tNOTEQUAL 397
#define tEQUAL 398
#define tGREATEROREQUAL 399
#define tLESSOREQUAL 400
#define UNARYPREC 401
#define tMINUSMINUS 402
#define tPLUSPLUS 403




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
#line 502 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 515 "Gmsh.tab.cpp"

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
#define YYLAST   8189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  453
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1564

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   403

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   154,     2,   164,     2,   153,     2,     2,
     159,   160,   151,   149,   165,   150,   163,   152,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     145,     2,   146,   140,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   161,     2,   162,   158,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   166,     2,   167,   168,     2,     2,     2,
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
     135,   136,   137,   138,   139,   141,   142,   143,   144,   147,
     148,   155,   156,   157
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
    2211,  2219,  2226,  2233,  2240,  2245,  2247,  2250,  2253,  2257,
    2261,  2273,  2283,  2291,  2299,  2301,  2305,  2307,  2309,  2312,
    2316,  2321,  2327,  2329,  2331,  2334,  2338,  2342,  2348,  2353,
    2356,  2359,  2362,  2365,  2371,  2377,  2383,  2389,  2391,  2393,
    2397,  2401,  2406,  2413,  2420,  2422,  2424,  2428,  2432,  2442,
    2450,  2452,  2458,  2462,  2469,  2471,  2475,  2477,  2479,  2483,
    2490,  2492,  2494,  2499,  2506,  2513,  2518,  2523,  2532,  2537,
    2542,  2549,  2556,  2558
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,    -1,     1,     6,    -1,    -1,   171,
     172,    -1,   175,    -1,   174,    -1,   193,    -1,   207,    -1,
     212,    -1,   216,    -1,   217,    -1,   218,    -1,   221,    -1,
     241,    -1,   242,    -1,   220,    -1,   219,    -1,   215,    -1,
     244,    -1,   146,    -1,   146,   146,    -1,    36,   159,     5,
     160,     6,    -1,    37,   159,     5,   160,     6,    -1,    36,
     159,     5,   160,   173,   257,     6,    -1,    36,   159,     5,
     165,   253,   160,     6,    -1,    37,   159,     5,   165,   253,
     160,     6,    -1,    36,   159,     5,   165,   253,   160,   173,
     257,     6,    -1,     4,     5,   166,   176,   167,     6,    -1,
      95,     4,   161,   245,   162,     6,    -1,    96,     4,   161,
     245,   162,     6,    -1,    -1,   176,   179,    -1,   176,   183,
      -1,   176,   186,    -1,   176,   188,    -1,   176,   189,    -1,
     245,    -1,   177,   165,   245,    -1,   245,    -1,   178,   165,
     245,    -1,    -1,    -1,     4,   180,   159,   177,   160,   181,
     166,   178,   167,     6,    -1,   257,    -1,   182,   165,   257,
      -1,    -1,   101,   159,   245,   165,   245,   165,   245,   160,
     184,   166,   182,   167,     6,    -1,   257,    -1,   185,   165,
     257,    -1,    -1,   102,   159,   245,   165,   245,   165,   245,
     165,   245,   160,   187,   166,   185,   167,     6,    -1,   103,
     166,   249,   167,   166,   249,   167,     6,    -1,   103,   166,
     249,   167,   166,   249,   167,   166,   249,   167,   166,   249,
     167,     6,    -1,    -1,   104,   190,   166,   178,   167,     6,
      -1,     7,    -1,   139,    -1,   138,    -1,   137,    -1,   136,
      -1,   157,    -1,   156,    -1,    53,   161,   195,   162,     6,
      -1,    54,   161,   198,   162,     6,    -1,     4,   191,   250,
       6,    -1,     4,   161,   162,   191,   250,     6,    -1,     4,
     161,   245,   162,   191,   245,     6,    -1,     4,   159,   245,
     160,   191,   245,     6,    -1,     4,   161,   166,   253,   167,
     162,   191,   250,     6,    -1,     4,   159,   166,   253,   167,
     160,   191,   250,     6,    -1,     4,   192,     6,    -1,     4,
     161,   245,   162,   192,     6,    -1,     4,     7,   258,     6,
      -1,     4,   163,     4,     7,   258,     6,    -1,     4,   161,
     245,   162,   163,     4,     7,   258,     6,    -1,     4,   163,
       4,   191,   245,     6,    -1,     4,   161,   245,   162,   163,
       4,   191,   245,     6,    -1,     4,   163,     4,   192,     6,
      -1,     4,   161,   245,   162,   163,     4,   192,     6,    -1,
       4,   163,   111,   163,     4,     7,   254,     6,    -1,     4,
     161,   245,   162,   163,   111,   163,     4,     7,   254,     6,
      -1,     4,   163,   112,     7,   255,     6,    -1,     4,   161,
     245,   162,   163,   112,     7,   255,     6,    -1,     4,   120,
       7,   245,     6,    -1,   120,   161,   245,   162,     7,     4,
       6,    -1,   120,   161,   245,   162,   163,     4,     7,   245,
       6,    -1,   120,   161,   245,   162,   163,     4,     7,   258,
       6,    -1,   120,   161,   245,   162,   163,     4,     7,   166,
     253,   167,     6,    -1,   120,   161,   245,   162,   163,     4,
       6,    -1,    77,   159,     4,   160,   163,     4,     7,   245,
       6,    -1,    77,   159,     4,   160,   163,     4,     7,   258,
       6,    -1,    -1,   165,    -1,    -1,   195,   194,     4,    -1,
     195,   194,     4,     7,   245,    -1,    -1,   195,   194,     4,
       7,   166,   245,   196,   200,   167,    -1,   195,   194,     4,
       7,   258,    -1,    -1,   195,   194,     4,     7,   166,   258,
     197,   202,   167,    -1,    -1,   198,   194,   257,    -1,   245,
       7,   258,    -1,   199,   165,   245,     7,   258,    -1,    -1,
     200,   201,    -1,   165,     4,   250,    -1,   165,     4,   166,
     199,   167,    -1,   165,     4,     5,    -1,    -1,   202,   203,
      -1,   165,     4,   245,    -1,   165,     4,     5,    -1,   165,
       4,   166,   259,   167,    -1,   245,    -1,   258,    -1,    -1,
     114,    59,   166,   245,   167,    -1,    -1,    69,   247,    -1,
      55,   159,   245,   160,     7,   247,     6,    -1,    -1,    73,
      55,   208,   159,   204,   160,     7,   250,     6,    -1,    64,
      65,   250,     7,   245,     6,    -1,    58,   159,   245,   160,
       7,   250,     6,    -1,    78,    58,   250,     6,    -1,    62,
     159,   245,   160,     7,   250,     6,    -1,    56,   159,   245,
     160,     7,   250,   206,     6,    -1,    57,   159,   245,   160,
       7,   250,   206,     6,    -1,   106,   159,   245,   160,     7,
     250,     6,    -1,   107,   159,   245,   160,     7,   250,     6,
      -1,   108,   159,   245,   160,     7,   250,   110,   250,   109,
     245,     6,    -1,    58,     4,   159,   245,   160,     7,   250,
       6,    -1,    74,    58,   159,   245,   160,     7,   250,     6,
      -1,    -1,    73,    58,   209,   159,   204,   160,     7,   250,
       6,    -1,    69,    61,   159,   245,   160,     7,   250,     6,
      -1,    70,    61,   159,   245,   160,     7,   250,   205,     6,
      -1,    12,    13,     6,    -1,    13,    61,   245,     6,    -1,
      66,    61,   159,   245,   160,     7,     5,     5,     5,     6,
      -1,    59,   159,   245,   160,     7,   250,     6,    -1,    60,
     159,   245,   160,     7,   250,     6,    -1,    61,     4,   159,
     245,   160,     7,   250,     6,    -1,    74,    61,   159,   245,
     160,     7,   250,     6,    -1,    74,    61,   159,   245,   160,
       7,   250,     4,   166,   249,   167,     6,    -1,    -1,    73,
      61,   210,   159,   204,   160,     7,   250,     6,    -1,    72,
      63,   159,   245,   160,     7,   250,     6,    -1,    63,   159,
     245,   160,     7,   250,     6,    -1,    74,    63,   159,   245,
     160,     7,   250,     6,    -1,    -1,    73,    63,   211,   159,
     204,   160,     7,   250,     6,    -1,    80,   247,   166,   213,
     167,    -1,    79,   166,   247,   165,   247,   165,   245,   167,
     166,   213,   167,    -1,    81,   247,   166,   213,   167,    -1,
      82,   166,   247,   165,   245,   167,   166,   213,   167,    -1,
      82,   166,   247,   165,   247,   167,   166,   213,   167,    -1,
       4,   166,   213,   167,    -1,    90,    58,   166,   253,   167,
      61,   166,   245,   167,    -1,    87,    58,   159,   245,   160,
     166,   253,   167,     6,    -1,   214,    -1,   212,    -1,    -1,
     214,   207,    -1,   214,    55,   166,   253,   167,     6,    -1,
     214,    58,   166,   253,   167,     6,    -1,   214,    61,   166,
     253,   167,     6,    -1,   214,    63,   166,   253,   167,     6,
      -1,    84,    69,   159,   245,   160,     7,   250,     6,    -1,
      84,    55,   159,   245,   160,     7,   166,   249,   167,     6,
      -1,    84,    69,   159,   245,   160,     7,   166,   247,   165,
     247,   165,   253,   167,     6,    -1,    84,    69,   159,   245,
     160,     7,   166,   247,   165,   247,   165,   247,   165,   253,
     167,     6,    -1,    84,    59,   159,   245,   160,     7,   166,
     247,   165,   253,   167,     6,    -1,    84,     4,   159,   245,
     160,     7,   250,     6,    -1,    84,     4,   159,   245,   160,
       7,     5,     6,    -1,    84,     4,   166,   245,   167,     6,
      -1,    84,     4,   159,   245,   160,     7,   166,   247,   165,
     247,   165,   253,   167,     6,    -1,    88,   166,   214,   167,
      -1,    88,   120,   161,   245,   162,     6,    -1,    88,     4,
     161,   245,   162,     6,    -1,    88,     4,     6,    -1,    88,
       4,     4,     6,    -1,   111,   254,   166,   214,   167,    -1,
     124,     5,     6,    -1,   125,     5,     6,    -1,   124,   166,
     214,   167,    -1,   125,   166,   214,   167,    -1,     4,   258,
       6,    -1,     4,     4,   161,   245,   162,   257,     6,    -1,
       4,     4,     4,   161,   245,   162,     6,    -1,     4,   245,
       6,    -1,    77,   159,     4,   160,   163,     4,     6,    -1,
     105,     4,     6,    -1,   118,     6,    -1,   119,     6,    -1,
      49,     6,    -1,    46,     6,    -1,    46,   166,   245,   165,
     245,   165,   245,   165,   245,   165,   245,   165,   245,   167,
       6,    -1,    47,     6,    -1,    50,     6,    -1,    51,     6,
      -1,    68,     6,    -1,   132,   245,     6,    -1,   113,   159,
     245,     8,   245,   160,    -1,   113,   159,   245,     8,   245,
       8,   245,   160,    -1,   113,     4,   114,   166,   245,     8,
     245,   167,    -1,   113,     4,   114,   166,   245,     8,   245,
       8,   245,   167,    -1,   115,    -1,   123,     4,    -1,   121,
      -1,   122,     4,     6,    -1,   116,   159,   245,   160,    -1,
     117,    -1,    83,   247,   166,   214,   167,    -1,    83,   166,
     247,   165,   247,   165,   245,   167,   166,   214,   167,    -1,
      83,   166,   247,   165,   247,   165,   247,   165,   245,   167,
     166,   214,   167,    -1,    -1,    83,   247,   166,   214,   222,
     235,   167,    -1,    -1,    83,   166,   247,   165,   247,   165,
     245,   167,   166,   214,   223,   235,   167,    -1,    -1,    83,
     166,   247,   165,   247,   165,   247,   165,   245,   167,   166,
     214,   224,   235,   167,    -1,    -1,    83,   166,   214,   225,
     235,   167,    -1,    83,    55,   166,   245,   165,   247,   167,
       6,    -1,    83,    58,   166,   245,   165,   247,   167,     6,
      -1,    83,    61,   166,   245,   165,   247,   167,     6,    -1,
      83,    55,   166,   245,   165,   247,   165,   247,   165,   245,
     167,     6,    -1,    83,    58,   166,   245,   165,   247,   165,
     247,   165,   245,   167,     6,    -1,    83,    61,   166,   245,
     165,   247,   165,   247,   165,   245,   167,     6,    -1,    83,
      55,   166,   245,   165,   247,   165,   247,   165,   247,   165,
     245,   167,     6,    -1,    83,    58,   166,   245,   165,   247,
     165,   247,   165,   247,   165,   245,   167,     6,    -1,    83,
      61,   166,   245,   165,   247,   165,   247,   165,   247,   165,
     245,   167,     6,    -1,    -1,    83,    55,   166,   245,   165,
     247,   167,   226,   166,   235,   167,     6,    -1,    -1,    83,
      58,   166,   245,   165,   247,   167,   227,   166,   235,   167,
       6,    -1,    -1,    83,    61,   166,   245,   165,   247,   167,
     228,   166,   235,   167,     6,    -1,    -1,    83,    55,   166,
     245,   165,   247,   165,   247,   165,   245,   167,   229,   166,
     235,   167,     6,    -1,    -1,    83,    58,   166,   245,   165,
     247,   165,   247,   165,   245,   167,   230,   166,   235,   167,
       6,    -1,    -1,    83,    61,   166,   245,   165,   247,   165,
     247,   165,   245,   167,   231,   166,   235,   167,     6,    -1,
      -1,    83,    55,   166,   245,   165,   247,   165,   247,   165,
     247,   165,   245,   167,   232,   166,   235,   167,     6,    -1,
      -1,    83,    58,   166,   245,   165,   247,   165,   247,   165,
     247,   165,   245,   167,   233,   166,   235,   167,     6,    -1,
      -1,    83,    61,   166,   245,   165,   247,   165,   247,   165,
     247,   165,   245,   167,   234,   166,   235,   167,     6,    -1,
     236,    -1,   235,   236,    -1,    93,   166,   245,   167,     6,
      -1,    93,   166,   250,   165,   250,   167,     6,    -1,    93,
     166,   250,   165,   250,   165,   250,   167,     6,    -1,    85,
       6,    -1,    97,     6,    -1,    97,    99,     6,    -1,    98,
       6,    -1,    98,    99,     6,    -1,    94,   159,   245,   160,
       7,   250,    76,   245,     6,    -1,    76,     4,   161,   245,
     162,     6,    -1,    -1,    76,     4,   245,    -1,    -1,     4,
      -1,    -1,     7,   250,    -1,    -1,     7,   245,    -1,    71,
      58,   251,     7,   245,   237,     6,    -1,    71,    61,   251,
     239,   238,     6,    -1,    67,    61,   166,   245,   167,     7,
     250,     6,    -1,    71,    63,   251,   239,     6,    -1,   100,
     251,     6,    -1,    91,    61,   166,   253,   167,   245,     6,
      -1,    85,    61,   251,   240,     6,    -1,    85,    63,   251,
       6,    -1,    86,    61,   250,     7,   245,     6,    -1,    75,
      58,   250,     7,   250,     6,    -1,    75,    61,   245,   166,
     253,   167,     7,   245,   166,   253,   167,     6,    -1,    55,
     166,   253,   167,   114,    61,   166,   245,   167,     6,    -1,
      58,   166,   253,   167,   114,    61,   166,   245,   167,     6,
      -1,    58,   166,   253,   167,   114,    63,   166,   245,   167,
       6,    -1,    61,   166,   253,   167,   114,    63,   166,   245,
     167,     6,    -1,    92,    61,   251,     6,    -1,    92,    58,
     251,     6,    -1,    89,     6,    -1,    89,     4,     6,    -1,
      89,    55,   166,   253,   167,     6,    -1,   129,    -1,   130,
      -1,   131,    -1,   243,     6,    -1,   243,   166,   250,   167,
       6,    -1,   243,   166,   250,   165,   250,   167,     6,    -1,
     243,   159,   250,   160,   166,   250,   165,   250,   167,     6,
      -1,   246,    -1,   159,   245,   160,    -1,   150,   245,    -1,
     149,   245,    -1,   154,   245,    -1,   245,   150,   245,    -1,
     245,   149,   245,    -1,   245,   151,   245,    -1,   245,   152,
     245,    -1,   245,   153,   245,    -1,   245,   158,   245,    -1,
     245,   145,   245,    -1,   245,   146,   245,    -1,   245,   148,
     245,    -1,   245,   147,   245,    -1,   245,   144,   245,    -1,
     245,   143,   245,    -1,   245,   142,   245,    -1,   245,   141,
     245,    -1,   245,   140,   245,     8,   245,    -1,    14,   159,
     245,   160,    -1,    15,   159,   245,   160,    -1,    16,   159,
     245,   160,    -1,    17,   159,   245,   160,    -1,    18,   159,
     245,   160,    -1,    19,   159,   245,   160,    -1,    20,   159,
     245,   160,    -1,    21,   159,   245,   160,    -1,    22,   159,
     245,   160,    -1,    24,   159,   245,   160,    -1,    25,   159,
     245,   165,   245,   160,    -1,    26,   159,   245,   160,    -1,
      27,   159,   245,   160,    -1,    28,   159,   245,   160,    -1,
      29,   159,   245,   160,    -1,    30,   159,   245,   160,    -1,
      31,   159,   245,   160,    -1,    32,   159,   245,   165,   245,
     160,    -1,    33,   159,   245,   165,   245,   160,    -1,    34,
     159,   245,   165,   245,   160,    -1,    23,   159,   245,   160,
      -1,    14,   161,   245,   162,    -1,    15,   161,   245,   162,
      -1,    16,   161,   245,   162,    -1,    17,   161,   245,   162,
      -1,    18,   161,   245,   162,    -1,    19,   161,   245,   162,
      -1,    20,   161,   245,   162,    -1,    21,   161,   245,   162,
      -1,    22,   161,   245,   162,    -1,    24,   161,   245,   162,
      -1,    25,   161,   245,   165,   245,   162,    -1,    26,   161,
     245,   162,    -1,    27,   161,   245,   162,    -1,    28,   161,
     245,   162,    -1,    29,   161,   245,   162,    -1,    30,   161,
     245,   162,    -1,    31,   161,   245,   162,    -1,    32,   161,
     245,   165,   245,   162,    -1,    33,   161,   245,   165,   245,
     162,    -1,    34,   161,   245,   165,   245,   162,    -1,    23,
     161,   245,   162,    -1,     3,    -1,     9,    -1,    10,    -1,
      11,    -1,   133,    -1,   134,    -1,   135,    -1,     4,    -1,
       4,   168,   166,   245,   167,    -1,     4,   161,   245,   162,
      -1,   164,     4,   161,   162,    -1,     4,   192,    -1,     4,
     161,   245,   162,   192,    -1,     4,   163,     4,    -1,     4,
     161,   245,   162,   163,     4,    -1,     4,   163,     4,   192,
      -1,     4,   161,   245,   162,   163,     4,   192,    -1,   126,
     159,   257,   165,   245,   160,    -1,    43,   159,   257,   165,
     257,   160,    -1,    44,   159,   257,   165,   257,   160,    -1,
      45,   159,   259,   160,    -1,   248,    -1,   150,   247,    -1,
     149,   247,    -1,   247,   150,   247,    -1,   247,   149,   247,
      -1,   166,   245,   165,   245,   165,   245,   165,   245,   165,
     245,   167,    -1,   166,   245,   165,   245,   165,   245,   165,
     245,   167,    -1,   166,   245,   165,   245,   165,   245,   167,
      -1,   159,   245,   165,   245,   165,   245,   160,    -1,   250,
      -1,   249,   165,   250,    -1,   245,    -1,   252,    -1,   166,
     167,    -1,   166,   253,   167,    -1,   150,   166,   253,   167,
      -1,   245,   151,   166,   253,   167,    -1,   250,    -1,     5,
      -1,   150,   252,    -1,   245,   151,   252,    -1,   245,     8,
     245,    -1,   245,     8,   245,     8,   245,    -1,    55,   166,
     245,   167,    -1,    55,     5,    -1,    58,     5,    -1,    61,
       5,    -1,    63,     5,    -1,    73,    55,   166,   253,   167,
      -1,    73,    58,   166,   253,   167,    -1,    73,    61,   166,
     253,   167,    -1,    73,    63,   166,   253,   167,    -1,   212,
      -1,   221,    -1,     4,   161,   162,    -1,     4,   159,   160,
      -1,    35,   161,     4,   162,    -1,     4,   161,   166,   253,
     167,   162,    -1,     4,   159,   166,   253,   167,   160,    -1,
     245,    -1,   252,    -1,   253,   165,   245,    -1,   253,   165,
     252,    -1,   166,   245,   165,   245,   165,   245,   165,   245,
     167,    -1,   166,   245,   165,   245,   165,   245,   167,    -1,
       4,    -1,     4,   163,   111,   163,     4,    -1,   166,   256,
     167,    -1,     4,   161,   245,   162,   163,   112,    -1,   254,
      -1,   256,   165,   254,    -1,   258,    -1,     4,    -1,     4,
     163,     4,    -1,     4,   161,   245,   162,   163,     4,    -1,
       5,    -1,    48,    -1,   127,   159,   257,   160,    -1,   128,
     159,   257,   165,   257,   160,    -1,    39,   159,   257,   165,
     257,   160,    -1,    40,   159,   257,   160,    -1,    41,   159,
     257,   160,    -1,    42,   159,   257,   165,   257,   165,   257,
     160,    -1,    38,   159,   257,   160,    -1,    38,   161,   257,
     162,    -1,    38,   159,   257,   165,   253,   160,    -1,    38,
     161,   257,   165,   253,   162,    -1,   257,    -1,   259,   165,
     257,    -1
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
    2110,  2133,  2161,  2182,  2205,  2226,  2248,  2268,  2380,  2399,
    2437,  2546,  2555,  2561,  2576,  2604,  2621,  2635,  2641,  2647,
    2656,  2670,  2715,  2732,  2747,  2766,  2778,  2802,  2806,  2811,
    2818,  2824,  2829,  2835,  2839,  2843,  2848,  2861,  2878,  2895,
    2916,  2937,  2972,  2980,  2986,  2993,  2997,  3006,  3014,  3022,
    3031,  3030,  3044,  3043,  3057,  3056,  3070,  3069,  3082,  3089,
    3096,  3103,  3110,  3117,  3124,  3131,  3138,  3146,  3145,  3158,
    3157,  3170,  3169,  3182,  3181,  3194,  3193,  3206,  3205,  3218,
    3217,  3230,  3229,  3242,  3241,  3257,  3260,  3266,  3278,  3298,
    3321,  3325,  3329,  3333,  3337,  3341,  3360,  3373,  3376,  3392,
    3395,  3408,  3411,  3417,  3420,  3427,  3483,  3553,  3558,  3625,
    3661,  3669,  3712,  3751,  3771,  3798,  3838,  3861,  3884,  3888,
    3911,  3950,  3995,  3999,  4009,  4044,  4045,  4046,  4050,  4056,
    4068,  4086,  4114,  4115,  4116,  4117,  4118,  4119,  4120,  4121,
    4122,  4129,  4130,  4131,  4132,  4133,  4134,  4135,  4136,  4137,
    4138,  4139,  4140,  4141,  4142,  4143,  4144,  4145,  4146,  4147,
    4148,  4149,  4150,  4151,  4152,  4153,  4154,  4155,  4156,  4157,
    4158,  4159,  4160,  4163,  4164,  4165,  4166,  4167,  4168,  4169,
    4170,  4171,  4172,  4173,  4174,  4175,  4176,  4177,  4178,  4179,
    4180,  4181,  4182,  4183,  4192,  4193,  4194,  4195,  4196,  4197,
    4198,  4202,  4223,  4242,  4260,  4272,  4289,  4310,  4315,  4320,
    4330,  4340,  4345,  4354,  4359,  4386,  4390,  4394,  4398,  4402,
    4409,  4413,  4417,  4421,  4428,  4433,  4440,  4445,  4449,  4454,
    4458,  4466,  4477,  4481,  4493,  4501,  4509,  4516,  4526,  4546,
    4550,  4554,  4558,  4562,  4591,  4620,  4649,  4678,  4688,  4698,
    4711,  4723,  4735,  4754,  4775,  4780,  4784,  4788,  4800,  4804,
    4816,  4823,  4833,  4837,  4852,  4857,  4864,  4868,  4881,  4889,
    4900,  4904,  4912,  4920,  4928,  4936,  4950,  4964,  4977,  4982,
    4986,  5006,  5028,  5033
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
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
      63,   395,   396,   397,   398,    60,    62,   399,   400,    43,
      45,    42,    47,    37,    33,   401,   402,   403,    94,    40,
      41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   169,   170,   170,   171,   171,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   173,   173,   174,   174,   174,   174,   174,   174,   175,
     175,   175,   176,   176,   176,   176,   176,   176,   177,   177,
     178,   178,   180,   181,   179,   182,   182,   184,   183,   185,
     185,   187,   186,   188,   188,   190,   189,   191,   191,   191,
     191,   191,   192,   192,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   194,   194,   195,   195,   195,   196,   195,
     195,   197,   195,   198,   198,   199,   199,   200,   200,   201,
     201,   201,   202,   202,   203,   203,   203,   204,   204,   205,
     205,   206,   206,   207,   208,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   209,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   210,
     207,   207,   207,   207,   211,   207,   212,   212,   212,   212,
     212,   212,   212,   212,   213,   213,   214,   214,   214,   214,
     214,   214,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   216,   216,   216,   216,   216,   217,   218,   218,   218,
     218,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   221,   221,   221,
     222,   221,   223,   221,   224,   221,   225,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   226,   221,   227,
     221,   228,   221,   229,   221,   230,   221,   231,   221,   232,
     221,   233,   221,   234,   221,   235,   235,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   237,   237,   238,
     238,   239,   239,   240,   240,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   242,   242,   242,   243,   243,   243,   244,   244,
     244,   244,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   247,   247,   247,   247,   247,
     248,   248,   248,   248,   249,   249,   250,   250,   250,   250,
     250,   250,   251,   251,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   253,   253,   253,   253,   254,   254,
     254,   254,   255,   255,   256,   256,   257,   257,   257,   257,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   259,   259
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
       7,     6,     6,     6,     4,     1,     2,     2,     3,     3,
      11,     9,     7,     7,     1,     3,     1,     1,     2,     3,
       4,     5,     1,     1,     2,     3,     3,     5,     4,     2,
       2,     2,     2,     5,     5,     5,     5,     1,     1,     3,
       3,     4,     6,     6,     1,     1,     3,     3,     9,     7,
       1,     5,     3,     6,     1,     3,     1,     1,     3,     6,
       1,     1,     4,     6,     6,     4,     4,     8,     4,     4,
       6,     6,     1,     3
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
      14,    15,    16,     0,    20,   364,   371,   440,    57,   365,
     366,   367,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   441,     0,     0,     0,     0,   368,   369,   370,    61,
      60,    59,    58,     0,     0,     0,    63,    62,     0,     0,
       0,     0,   166,     0,     0,     0,   302,     0,     0,     0,
       0,     0,   200,     0,   202,   199,   203,   204,    95,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,     0,     0,     0,
       0,     0,     0,   124,   137,   149,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,     0,
     292,     0,     0,     0,     0,     0,     0,     0,   371,   403,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   417,
     418,   396,   402,     0,   397,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,   197,   198,     0,     0,   212,
       0,   166,     0,   166,   371,     0,   298,     0,     0,     0,
       0,     0,     0,   375,    32,   440,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   305,   304,   306,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,   164,     0,    72,
     194,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   191,   141,     0,     0,
       0,     0,    93,    93,     0,     0,   424,   425,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   387,   386,     0,     0,     0,     0,   166,   166,     0,
       0,     0,     0,     0,     0,     0,   226,     0,   166,     0,
       0,     0,     0,     0,   273,     0,     0,     0,     0,   184,
       0,     0,     0,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   409,     0,   410,   411,   412,     0,
       0,     0,     0,     0,   304,   404,     0,   398,     0,     0,
       0,   279,   196,     0,     0,     0,     0,     0,   166,     0,
       0,     0,     0,   214,   187,     0,   188,     0,     0,   206,
       0,     0,     0,     0,   377,     0,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     437,     0,   436,     0,     0,     0,     0,     0,     0,     0,
     452,     0,     0,     0,     0,     0,     0,   303,    57,     0,
       0,     0,    57,     0,     0,     0,     0,     0,   161,     0,
       0,     0,     0,   167,    66,     0,   320,   319,   318,   317,
     313,   314,   316,   315,   308,   307,   309,   310,   311,   312,
     142,     0,     0,     0,     0,     0,     0,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   269,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,     0,     0,
     389,   388,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,     0,     0,     0,     0,     0,     0,     0,   282,
       0,     0,   185,     0,     0,   181,     0,     0,     0,   291,
     290,     0,     0,   420,     0,   419,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   303,   399,   406,     0,   309,
     405,     0,     0,     0,     0,     0,     0,     0,     0,   215,
       0,   189,   190,     0,     0,     0,     0,   373,   379,     0,
      42,     0,     0,     0,    55,     0,    33,    34,    35,    36,
      37,   322,   343,   323,   344,   324,   345,   325,   346,   326,
     347,   327,   348,   328,   349,   329,   350,   330,   351,   342,
     363,   331,   352,     0,     0,   333,   354,   334,   355,   335,
     356,   336,   357,   337,   358,   338,   359,     0,     0,     0,
       0,     0,     0,     0,     0,   448,     0,   449,     0,     0,
     445,   446,     0,     0,     0,   384,     0,    85,     0,   442,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     0,     0,     0,     0,   374,     0,     0,     0,     0,
       0,    23,    21,     0,     0,    24,     0,     0,    64,    96,
      65,   104,     0,   426,   427,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   267,   272,   270,     0,   278,     0,     0,   117,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   156,   158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,   217,
       0,     0,     0,     0,     0,     0,   274,   281,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   373,
     421,   408,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,   186,     0,     0,     0,     0,     0,
       0,   299,     0,     0,   376,     0,   372,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   438,     0,     0,     0,     0,     0,     0,   453,
       0,     0,     0,     0,    67,     0,     0,     0,     0,     0,
      73,    75,    77,     0,     0,   434,     0,    83,     0,     0,
       0,     0,   321,    22,     0,     0,     0,     0,     0,     0,
       0,   121,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,     0,     0,     0,     0,     0,
     276,     0,     0,     0,     0,     0,     0,     0,     0,   284,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,     0,     0,   261,     0,   263,     0,   227,   256,
       0,     0,     0,   179,     0,     0,     0,   283,     0,   183,
     182,   294,     0,     0,    30,    31,     0,     0,   413,   414,
     415,   416,   407,   401,     0,     0,     0,   431,     0,     0,
       0,   207,     0,     0,     0,     0,   193,   378,   192,     0,
       0,     0,     0,   394,     0,   332,   353,   339,   360,   340,
     361,   341,   362,     0,   450,   451,   444,     0,   382,   383,
     381,   443,     0,    69,     0,    57,     0,     0,     0,     0,
      68,     0,     0,     0,   432,     0,     0,     0,     0,    25,
      26,     0,    27,     0,     0,    97,   100,   123,     0,     0,
       0,     0,     0,   127,     0,     0,   144,   145,     0,     0,
     129,   152,     0,     0,     0,   119,     0,   275,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   195,     0,     0,
       0,     0,   166,   166,     0,   237,     0,   239,     0,   241,
       0,   396,     0,     0,   262,   264,     0,     0,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   280,   423,
     422,   132,   133,     0,     0,     0,     0,    86,    90,     0,
       0,   300,   380,     0,    38,     0,     0,     0,     0,     0,
      40,     0,     0,     0,     0,     0,     0,    80,     0,     0,
      81,     0,   435,   168,   169,   170,   171,     0,     0,    98,
     101,     0,   122,   130,   131,   135,     0,     0,   146,     0,
       0,   277,   139,     0,     0,   268,   151,     0,     0,     0,
       0,   136,     0,   147,   153,     0,     0,     0,     0,   393,
       0,   392,     0,     0,     0,   228,     0,     0,   229,     0,
       0,   230,     0,     0,     0,     0,     0,     0,     0,   178,
       0,     0,   177,     0,     0,     0,   172,     0,     0,     0,
       0,   429,     0,   209,   208,     0,     0,     0,     0,    43,
       0,     0,     0,   395,     0,     0,     0,   439,   447,    71,
      70,    76,    78,     0,    84,     0,    28,     0,   107,   112,
       0,     0,     0,     0,     0,     0,   140,   125,   138,   150,
     155,     0,     0,    91,    92,   166,     0,   159,   160,     0,
       0,     0,     0,     0,     0,     0,   257,     0,     0,   166,
       0,     0,     0,     0,     0,   163,   162,     0,     0,     0,
       0,    87,    88,     0,     0,    39,     0,     0,     0,    41,
      56,     0,   433,     0,     0,     0,   286,   287,   288,   289,
     143,     0,     0,     0,     0,     0,   391,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   266,     0,     0,     0,
     222,     0,     0,   173,     0,     0,     0,   428,   210,     0,
     301,     0,     0,     0,     0,    82,     0,     0,    99,   108,
       0,   102,   113,     0,     0,     0,   157,     0,   243,     0,
       0,   245,     0,     0,   247,     0,     0,     0,   258,     0,
     218,     0,   166,     0,     0,     0,   134,    89,     0,    47,
       0,    53,     0,     0,     0,     0,   120,   148,   285,   390,
     231,     0,     0,   238,   232,     0,     0,   240,   233,     0,
       0,   242,     0,     0,     0,   224,     0,   176,     0,     0,
       0,     0,     0,     0,     0,   111,     0,   109,   115,     0,
     114,     0,   249,     0,   251,     0,   253,   259,   265,   223,
     219,     0,     0,     0,     0,    44,     0,    51,     0,     0,
       0,   424,     0,     0,   234,     0,     0,   235,     0,     0,
     236,     0,     0,   180,     0,   174,     0,    45,     0,     0,
     201,     0,   110,     0,   116,     0,     0,     0,     0,     0,
       0,   225,     0,     0,     0,     0,     0,     0,   105,   244,
       0,   246,     0,   248,     0,   175,    46,    48,     0,    49,
       0,     0,     0,     0,     0,     0,     0,    54,   106,   250,
     252,   254,    50,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    78,   813,    79,    80,   506,  1193,  1199,
     726,   927,  1354,  1516,   727,  1471,  1548,   728,  1518,   729,
     730,   931,   153,   283,    81,   608,   382,  1308,  1309,   383,
    1500,  1364,  1409,  1365,  1412,   848,  1234,  1120,   583,   409,
     410,   411,   412,   249,   356,   357,    84,    85,    86,    87,
      88,    89,   250,   880,  1431,  1491,   659,  1256,  1259,  1262,
    1451,  1455,  1459,  1505,  1508,  1511,   876,   877,   999,   845,
     633,   668,    91,    92,    93,    94,   251,   156,   422,   210,
    1072,   252,   253,   254,   478,   261,   804,   966,   560,   552,
     561
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1172
static const yytype_int16 yypact[] =
{
    4439,    61,    87,  4529, -1172, -1172,  2224,     4,    12,   -57,
     -35,    37,   129,   149,   188,   207,    89,   107,    94,   105,
     118,    22,   124,   185,    26,   193,   222,   320,   334,   360,
     404,   375,   381,   432,   333,   560,   507,   -20,   276,   397,
     295,   179,   179,   296,   -10,    58,   103,   415,   412,    16,
      46,   425,   428,    76,   502,   518,  2388,   551,   410,   435,
     436,    29,    51, -1172,   455, -1172,   634,   635,   464, -1172,
     640,   645,    11,    34, -1172, -1172, -1172,  4320, -1172, -1172,
   -1172, -1172, -1172, -1172, -1172, -1172, -1172, -1172, -1172, -1172,
   -1172, -1172, -1172,    43, -1172, -1172,    28,   484,   470, -1172,
   -1172, -1172,   390,   440,   496,   501,   510,   514,   520,   524,
     539,   549,   550,   553,   568,   573,   574,   594,   597,   598,
     601,   614,   618,   621,   497,   500,   504,   527,   528,   533,
     534, -1172,   659,   543,   557,   564, -1172, -1172, -1172, -1172,
   -1172, -1172, -1172,  4320,  4320,  4320, -1172, -1172,  3930,  2170,
      14,   720,   335,  2862,   722,   843, -1172,   744,   755,  4320,
     759,   773, -1172,  4320, -1172, -1172, -1172, -1172, -1172, -1172,
    4320,  4125,  4320,  4320,   629,  4320,  4125,  4320,  4320,   641,
    4125,  4320,  4320,  2862,   652,   657, -1172,   667,   681,  2388,
    2388,  2388,   688, -1172, -1172, -1172, -1172,   689,   715,   718,
    2862,  4320,   877,  2862,   179,   179,   179,  4320,  4320,  -103,
   -1172,   -18,   179,   724,   729,   732,  4088,    81,   114,   723,
     766,   769,  2388,  2388,  2862,   782,     6,   781, -1172,   939,
   -1172,   793,   794,   797,  2388,  2388,   789,   813,   113, -1172,
     817,    35,   949,   994,  1004,   590,  3020,  4320,  1999, -1172,
   -1172,  2142, -1172,   997, -1172,  1007,  4320,  4320,  4320,   853,
    4320,   861,   909,  4320,  4320, -1172, -1172,  4320,  1033, -1172,
    1036, -1172,  1045, -1172,   174,  1163, -1172,  2862,  2862,   894,
    4320,  1056,   913, -1172, -1172, -1172,  1064,  4320,  4320,  4320,
    4320,  4320,  4320,  4320,  4320,  4320,  4320,  4320,  4320,  4320,
    4320,  4320,  4320,  4320,  4320,  4320,  4320,  4320,  4320,  4320,
    4320,  4320,  4320,  4320,  4320,  4320,  4320,  4320,  4320,  4320,
    4320,  4320,  4320,  4320,  4320,  4320,  4320,  4320,  4320,   446,
     446,   446,   446,   446,   446,   446,   446,   446,  4320,   446,
     446,   446,   917,   917,   917,  4125,  6876,    79,  4125,  6117,
      83,   924,  1073,   923,   927, -1172,   930,  4610,  1084, -1172,
   -1172,  4320,  4320,  4320,  4320,  4320,  4320,  4320,  4320,  4320,
    4320,  4320,  4320,  4320,  4320,  4320, -1172, -1172,  1261,  -131,
     -50,  5415,    73,   374,  6897,  4125,  3445, -1172,   349,  6918,
    6939,  4320,  6960,   616,  6981,  7002,  4320,   622,  7023,  7044,
    1099,  4320,  4320,  4320,  4320,  1103,  1107,  1107,  4320,   959,
     961,   962,   965,  4320,  4320,  4320,  1118,  5335,   969,  1122,
      -5, -1172, -1172,  5441,  5467,   179,   179,   335,   335,    84,
    4320,  4320,  4320,  4088,  4088,  4320,  4610,    92, -1172,  4320,
    4320,  4320,  4320,  4320,  1125,  1130,  1131,  4320,  1133, -1172,
    4320,  4320,   772, -1172,  4125,  4125,  4125,  1134,  1135,  4320,
    4320,   224,  3856,  1127, -1172,  4320, -1172, -1172, -1172,   971,
     977,   979,   981,  4125,   917, -1172,  7065, -1172,   626,  4320,
    3178, -1172, -1172,  7086,  7107,  7128,  1037,  5493, -1172,   983,
    3464,  7149,  6140, -1172, -1172,   874, -1172,  1440,  4320, -1172,
     990,   631,  4320,  6163,   -45,  4320,     5, -1172,  7170,  6186,
    7191,  6209,  7212,  6232,  7233,  6255,  7254,  6278,  7275,  6301,
    7296,  6324,  7317,  6347,  7338,  6370,  7359,  6393,  7380,  6416,
    5519,  5545,  7401,  6439,  7422,  6462,  7443,  6485,  7464,  6508,
    7485,  6531,  7506,  6554,  5571,  5597,  5623,  5649,  5675,  5701,
     636,   -27, -1172,   380,   989,   993,   996,   992,   995,   999,
   -1172,   314,  1554,  1002,  1001,  1006,   650,    79, -1172,  2862,
     651,   219,   470,  4320,  1153,  1158,    31,  1011, -1172,   181,
      24,    32,   227, -1172, -1172,  3610,  1314,  2539,  1124,  1124,
     409,   409,   409,   409,   -87,   -87,   917,   917,   917,   917,
   -1172,     7,  4125,  1157,  4125,  4320,  1168, -1172,  1172,  1171,
     446,  1173,  4125,  4125,  1065,  1174,  1175,  7527,  1177,  1071,
    1179,  1182,  7548,  1076,  1184,  1185,  4320,  7569,  4663,  7590,
    7611,  4320,  2862,  1191,  1190,  7632,  4277,  4277,  4277,  4277,
    7653,  7674,  7695,  2862,  4125,  1015, -1172,   179,  4320,  4320,
   -1172, -1172,  1030,  1031,  4088,  5727,  5753,  5779,  5389,   -17,
     179,  1574,  7716,  4691,  7737,  7758,  7779,  4320,  1193, -1172,
    4320,  7800, -1172,  6577,  6600, -1172,   672,   701,   706, -1172,
   -1172,  6623,  6646, -1172,  4125, -1172,  4125,  6669,  1038,  4719,
    4125,  4125,  4125,  4125,   726, -1172, -1172,  4226,  4125,   917,
   -1172,  1195,  1197,  1199,  1044,  4320,  1660,  4320,  4320, -1172,
      30, -1172, -1172,  1042,  2862,  1203,  6692,    80, -1172,  4747,
   -1172,  1051,  1052,  1046, -1172,  1207, -1172, -1172, -1172, -1172,
   -1172, -1172, -1172, -1172, -1172, -1172, -1172, -1172, -1172, -1172,
   -1172, -1172, -1172, -1172, -1172, -1172, -1172, -1172, -1172, -1172,
   -1172, -1172, -1172,  4320,  4320, -1172, -1172, -1172, -1172, -1172,
   -1172, -1172, -1172, -1172, -1172, -1172, -1172,  4320,  4320,  4320,
    4320,  4320,  4320,  4320,  1210, -1172,  4125, -1172,  4125,   446,
   -1172, -1172,   446,   446,   446, -1172,   446, -1172,  4320, -1172,
     446,  1055,  4320,  1212,  1060,    18,  4320,  1217,  1218,  1604,
   -1172,  1219,  1066,    29,  1223, -1172,  4125,  4125,  4125,  4125,
    4320, -1172,  1079,   446,   339, -1172,   355,  5805, -1172,  1225,
   -1172, -1172,   179,  3445, -1172,  1169,  2862,  2862,  1226,  2862,
     838,  2862,  2862,  1227,  1180,  2862,  2862,  1636,  1228,  1229,
    1230,  1231,  4550, -1172, -1172,  1236, -1172,  1237,  1085,  8031,
   -1172,  1086,  1087,  1089,  1243,  1245,  1246,  1248,   737,  1251,
     238,  5831,  5857, -1172, -1172,  4775,  -125,   179,   179,   179,
    1252,  1253,  1091,  1102,    15,    17,   -15, -1172,   242, -1172,
     -17,  1256,  1258,  1272,  1274,  1277,  8031, -1172,  1784,  1119,
    1280,  1281,  1283,  1233,  4320,  1284,  1285,   741,   742,     2,
   -1172, -1172,   745,   746,   752,   753, -1172,  4320,   756,  2862,
    2862,  2862,  1288,  5883, -1172,  4248,   712,  1291,  1292,  2862,
    1150, -1172,  1294,  1297, -1172,  1296, -1172,  1139,  4320,  4320,
    2862,  1152, -1172,  7821,  6715,  7842,  6738,  7863,  6761,  7884,
    6784,  6807, -1172,   364,   447,  1162,  1160,  1166,  1170, -1172,
    7905,  1176,    79,  1846, -1172,    79,   241,  1165,  1316,  2498,
   -1172, -1172, -1172,    29,  4320, -1172,   757, -1172,   784,   788,
     799,   802,  8031, -1172,  1326,     8,  1328,  4320,  3652,    13,
    1178,  1266,  1266,  2862,  1334,  1181,  1183,  1336,  1337,  2862,
    1186,  1340,  1342, -1172,  1345,  2862,  2862,  2862,  1347,  1351,
   -1172,  2862,  1346,  1352,  1353,  1355,  2862,  2862,  2862, -1172,
    1356,   217,  4320,  4320,  4320,  1192,  1198,   -93,    62,   117,
    1204, -1172,  2862,  4320, -1172,  1360, -1172,  1361, -1172, -1172,
    4088,   256,  2546, -1172,  1202,  1205,  3336, -1172,  4125, -1172,
   -1172, -1172,  1206,  2518, -1172, -1172,  1214,  1208, -1172, -1172,
   -1172, -1172,  8031, -1172,  1369,  1371,  1269, -1172,  4320,  4320,
    4320, -1172,  1375,   327,  1220,  1376, -1172,   -45, -1172,  4320,
    5909,  5935,   803, -1172,  4320, -1172, -1172, -1172, -1172, -1172,
   -1172, -1172, -1172,  1221, -1172, -1172, -1172,   446, -1172, -1172,
   -1172, -1172,  2862, -1172,  2862,   470,  4320,  1377,  1382,    31,
   -1172,  1384,  6830,    29, -1172,  1386,  1387,  1388,  1389, -1172,
   -1172,   446, -1172,  5961,  4277,  8031, -1172, -1172,  4320,   179,
    1390,  1394,  1409, -1172,  4320,  4320, -1172, -1172,  1410,  4320,
   -1172, -1172,  1413,  1415,  1416,  1310,  4320, -1172,  1419,  2862,
    2862,  2862,  2862,  1420,   967,  1422,  4320, -1172,  4277,  4803,
    7926,  4579,   335,   335,   179,  1424,   179,  1426,   179,  1428,
    4320,   438,  1270,  7947, -1172, -1172,  4831,   255, -1172,  1430,
    1815,  1431,  2862,   179,  1815,  1433,   812,  4320, -1172, -1172,
   -1172, -1172, -1172,  2862,  4607,   596,  7968, -1172, -1172,  3698,
    2862, -1172, -1172,   368,  8031,  4320,  4320,  2862,  1276,   833,
    8031,  1436,  1287,  1438,  1443,  1462,  2667, -1172,  1463,  1467,
   -1172,  1317, -1172, -1172, -1172, -1172, -1172,  1473,  4320,  8031,
   -1172,  4859,   -96, -1172, -1172, -1172,  4887,  4915, -1172,  4943,
    1476, -1172, -1172,  1425,  1480,  8031, -1172,  1482,  1483,  1484,
    1486, -1172,  1327, -1172, -1172,  5362,  2815,  1488,  1339, -1172,
    4320, -1172,  1341,  1344,   259, -1172,  1349,   269, -1172,  1350,
     294, -1172,  1354,  6853,  1501,  2862,  1514,  1357,  4320, -1172,
    3494,   317, -1172,   837,   342,   348, -1172,  1516,  4971,  1417,
    4320, -1172,  4320, -1172, -1172,  4125,  2834,  1518,  1358, -1172,
    4320,  5987,  6013, -1172,  2862,  4320,  1525, -1172, -1172, -1172,
   -1172, -1172, -1172,    29, -1172,  1421, -1172,  6039, -1172, -1172,
    1526,  1528,  1529,  1530,  1531,  1373, -1172, -1172, -1172, -1172,
   -1172,  2862,  4125, -1172, -1172,   335,  4635, -1172, -1172,  4088,
     -17,  4088,   -17,  4088,   -17,  1534, -1172,   840,  2862, -1172,
    4999,   179,  1535,  4125,   179, -1172, -1172,  4320,  5027,  5055,
     857, -1172, -1172,  1536,  1378,  8031,  4320,  4320,   867,  8031,
   -1172,  1537, -1172,  4320,   870,   873, -1172, -1172, -1172, -1172,
   -1172,  4320,   878,   881,  1383,  4320, -1172,  5083,   352,   371,
    5111,   376,   459,  5139,   443,   628, -1172,  2862,  1545,  1477,
    2039,  1391,   457, -1172,   882,   478,  2983, -1172, -1172,  1546,
   -1172,  4320,  7989,  6065,    38, -1172,  6091,  1550, -1172, -1172,
    1551, -1172, -1172,  5167,  1552,  1553, -1172,  5195,  1556,  4320,
    1558,  1559,  4320,  1560,  1562,  4320,  1564,  1404, -1172,  4320,
   -1172,   -17, -1172,  4125,  1566,  3494, -1172, -1172,   885, -1172,
    4320, -1172,  2862,  4320,  2704,  3893, -1172, -1172, -1172, -1172,
   -1172,  1411,  5223, -1172, -1172,  1412,  5251, -1172, -1172,  1414,
    5279, -1172,  1573,  3131,   716,  2425,   904, -1172,   489,   911,
    1576,  1418,  8010,   933,  5307, -1172,  1999, -1172, -1172,   446,
    8031,   -17,  1577,   -17,  1579,   -17,  1582, -1172, -1172, -1172,
   -1172,   -17,  1583,  4125,  1584, -1172,   446, -1172,  1429,  1590,
     936,  3150,   937,   727, -1172,  1432,   791, -1172,  1434,   921,
   -1172,  1435,   932, -1172,   940, -1172,   944, -1172,  1437,  2862,
   -1172,  4320, -1172,   470, -1172,  1591,   -17,  1593,   -17,  1598,
     -17, -1172,  1599,   446,  1600,   446,   948,  3298, -1172, -1172,
     968, -1172,   988, -1172,   998, -1172, -1172, -1172,   952, -1172,
    1603,   470,  1605,  1606,  1607,   446,  1611, -1172, -1172, -1172,
   -1172, -1172, -1172, -1172
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1172, -1172, -1172, -1172,   581, -1172, -1172, -1172, -1172,   218,
   -1172, -1172, -1172, -1172, -1172, -1172, -1172, -1172, -1172, -1172,
   -1172, -1172,  -339,     1, -1172,  1235, -1172, -1172, -1172, -1172,
   -1172, -1172, -1172, -1172, -1172,    39, -1172,   639,  1619, -1172,
   -1172, -1172, -1172,    -1,  -422,  -213, -1172, -1172, -1172, -1172,
   -1172, -1172,  1620, -1172, -1172, -1172, -1172, -1172, -1172, -1172,
   -1172, -1172, -1172, -1172, -1172, -1172,  -811,  -845, -1172, -1172,
    1232, -1172, -1172, -1172, -1172, -1172,    -2, -1172,    47, -1172,
   -1171,   619,   341,   785,   883,  -776,   525, -1172,  -236,    -6,
     166
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     157,  1273,    83,   436,   155,   652,   653,   154,   569,   720,
     448,   573,   449,   811,  1110,   452,   270,   158,   350,  1117,
     226,  1024,   956,  1026,   425,   426,   174,   965,   174,   601,
     179,  1029,   279,   259,   602,   802,   179,   917,   200,   272,
     464,   201,  1016,   162,  1441,   213,   425,   426,   214,   276,
     229,   215,   230,   425,   426,   262,   425,   426,   495,   870,
     497,   870,   218,   427,   372,   373,   374,     4,   871,  1031,
     871,   375,  1154,   159,  1155,   275,   872,   873,   872,   873,
     874,   875,   874,   875,   550,   285,   568,     5,   209,   211,
     572,   217,   286,   551,   553,   554,   555,   556,   557,   558,
     559,   231,   160,   563,   564,   565,   721,   722,   723,   724,
     603,   146,   147,   219,  1025,   604,  1027,   220,   123,   124,
     125,   126,   127,  1358,   161,   351,   352,   221,   131,   957,
     958,   425,   426,   775,   234,   164,   227,   235,   776,   205,
     206,   342,   343,   344,   425,   426,   346,   349,   428,   207,
    1372,   355,  1028,   812,   812,   165,   216,   378,   146,   147,
     647,   381,   425,   426,   222,   923,   223,   450,   384,   386,
     389,   390,   725,   392,   386,   394,   395,   271,   386,   398,
     399,   175,   228,   175,   146,   147,  1029,  1101,   176,   280,
     807,   281,   180,   918,   166,   260,   282,   803,   808,   417,
     273,   465,   277,   163,  1442,   423,   424,   134,   135,   278,
     263,   425,   426,   167,   424,   139,   140,   141,   142,   139,
     140,   141,   142,  1147,  1148,   661,   568,  1156,   792,  1157,
     425,   426,   796,   425,   426,   606,   146,   147,   607,   146,
     147,   425,   426,   923,   474,   476,   386,   438,  1095,   654,
     168,   420,   421,   170,   483,   484,   485,   660,   487,   429,
     171,   490,   491,   437,   172,   492,   425,   426,   169,   146,
     147,  1473,   461,   439,   462,   706,   281,   173,   503,   152,
     440,   282,  1158,   177,  1159,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,  1212,   205,   206,
     146,   147,   870,  1188,  1189,   498,   562,   281,   207,   354,
     170,   871,   282,   386,   178,   208,   386,   806,  1536,   872,
     873,   574,   181,   874,   875,   139,   140,   141,   142,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   821,   146,   147,   139,   140,   141,
     142,   182,   795,   474,   683,   183,   182,   425,   426,   617,
     684,   425,   426,   809,   622,   184,   192,   146,   147,   627,
     628,   629,   630,  1012,   425,   426,   635,  1030,   425,   426,
     186,   640,   641,   642,    40,    41,    42,    43,   425,   426,
    1268,   185,    48,  1168,  1329,    51,   355,   355,   655,   656,
     657,   342,   343,   658,  1331,   202,   187,   662,   663,   664,
     665,   666,   188,   425,   426,   671,   479,   870,   673,   674,
     550,   285,   386,   386,   386,   203,   871,   681,   682,  1333,
     687,   204,   212,   689,   872,   873,   425,   426,   874,   875,
     225,   386,   650,   651,   785,   285,   224,   697,   699,   786,
     421,   925,  1341,   232,   123,   124,   125,   126,   127,   233,
     189,   425,   426,   190,   131,   191,   687,   425,   426,   975,
     716,   425,   426,   719,   613,   718,   236,  1343,   123,   124,
     125,   126,   127,  1344,   613,   976,   614,  1419,   131,  1379,
     613,  1382,   237,  1385,  1084,   425,   426,  1361,  1289,   613,
     405,   406,   407,  1290,  1029,   870,   609,  1029,  1420,   607,
    1029,  1422,   777,   945,   871,   778,   946,   947,   948,   287,
     949,   288,   872,   873,   951,   255,   874,   875,   370,   371,
     372,   373,   374,   444,   445,   197,   798,   375,   198,   256,
     199,   799,   797,   134,   135,   457,   458,   974,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   480,
     373,   374,   425,   426,   257,   258,   375,   134,   135,   289,
     386,   290,   386,   817,  1282,  1264,   425,   426,  1425,  1085,
     699,   823,   613,  1092,   264,   193,  1094,  1096,   194,  1029,
    1464,   195,  1433,   196,   837,   267,  1423,   425,   426,   842,
     850,   850,   850,   850,   849,   849,   849,   849,   425,   426,
     265,   266,   386,  1435,   268,   469,   861,   862,   470,   269,
     284,   471,   865,   472,  1493,   291,   331,   292,  1029,   332,
     293,  1029,   294,   333,  1029,   886,   338,  1029,   888,   295,
    1503,   296,  1506,   297,  1509,   298,   851,   852,   853,   299,
    1512,   300,   386,   301,   386,   302,   334,   335,   386,   386,
     386,   386,   336,   337,   860,  1029,   386,  1029,   303,  1029,
     304,   866,   339,   913,   870,   915,   916,   878,   305,   307,
     306,   308,   309,   871,   310,  1540,   340,  1542,   924,  1544,
    1060,   872,   873,   341,   353,   874,   875,   311,   359,   312,
    1252,  1253,   313,   315,   314,   316,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     376,   933,   934,   317,   375,   318,   319,   321,   320,   322,
     323,   377,   324,  1283,   379,   935,   936,   937,   938,   939,
     940,   941,   358,   325,   386,   326,   386,   327,   380,   328,
     329,   613,   330,   619,     7,     8,   950,   613,   391,   623,
     953,   613,   870,   696,   959,  1426,   714,   773,   715,   774,
     396,   871,   400,   870,   386,   386,   386,   386,   972,   872,
     873,   401,   871,   874,   875,   613,   613,   791,   794,   416,
     872,   873,   419,   402,   874,   875,   403,   579,    19,    20,
     580,    22,    23,   581,    25,   582,    27,   613,    28,   892,
     404,    31,    32,   446,    34,    35,    36,   408,   413,   360,
      39,  1202,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   613,   870,   893,   979,
     375,   613,  1061,   894,   414,  1217,   871,   415,    58,    59,
      60,   418,   441,  1489,   872,   873,     7,     8,   874,   875,
     430,   613,  1043,   906,  1525,   431,   500,   501,   432,   985,
     924,   986,   613,  1374,  1010,  1052,   613,   613,  1046,  1047,
     613,   613,  1048,  1049,  1017,  1018,  1019,   613,   613,  1050,
    1051,   613,  1103,  1053,  1104,   442,  1070,  1071,   443,   579,
      19,    20,   580,    22,    23,   581,    25,   582,    27,   675,
      28,   447,   451,    31,    32,   453,    34,    35,    36,   613,
     459,  1105,    39,   613,   466,  1106,   387,  1097,  1527,   454,
     455,   387,  1102,   456,   613,   387,  1107,   613,  1197,  1108,
    1198,  1242,  1116,  1243,   460,  1113,  1115,   613,   463,  1277,
      58,    59,    60,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   870,  1295,   467,
    1296,   375,  1197,   481,  1342,  1387,   871,  1388,   870,   468,
    1149,  1150,  1151,   482,   872,   873,   486,   871,   874,   875,
    1161,  1163,   613,   489,  1399,   872,   873,   488,  1166,   874,
     875,   475,  1197,   387,  1404,  1407,   386,  1408,  1410,   493,
    1411,   711,   494,  1197,   870,  1414,   613,   613,  1415,  1434,
    1295,   496,  1470,   871,   388,   502,  1184,  1185,  1186,   393,
     504,   872,   873,   397,   870,   874,   875,  1194,  1192,   613,
     507,  1492,  1200,   871,   870,   375,   613,  1167,  1494,   505,
     576,   872,   873,   871,   577,   874,   875,   575,  1529,  1205,
     584,   872,   873,   152,  1206,   874,   875,   578,  1197,  1531,
    1498,  1521,   786,  1522,  1524,   613,   626,  1532,  1220,  1533,
     631,  1534,  1219,  1197,   632,  1550,  1221,  1555,   636,  1556,
     637,   638,  1226,  1227,   639,   643,  1390,  1229,   646,   645,
     387,   688,   667,   387,  1235,  1552,   669,   690,   670,   672,
     679,   680,  1247,   691,  1245,   692,  1246,   693,   704,   707,
     713,   355,   355,   780,   779,  1553,   781,   782,  1263,   800,
     783,   789,   801,   815,   784,  1554,  1222,   788,   386,   499,
     475,   790,   386,   805,   818,  1278,   819,   820,   859,   825,
     822,   826,   827,  1287,   829,   830,   831,  1286,   793,   832,
     834,   835,   836,  1291,  1292,   844,   846,   863,   864,   887,
     900,  1254,   909,  1257,   910,  1260,   911,   912,   919,   921,
     928,   929,   930,   932,   942,   952,  1307,  1271,   954,  1465,
    1274,  1275,   955,   960,   961,   973,   963,   964,   566,   967,
     980,   570,   978,   983,   989,   994,   995,   996,   997,   387,
     387,   387,  1000,   990,  1001,  1002,  1003,  1004,  1326,  1005,
    1006,   843,  1007,  1008,  1009,  1011,  1020,  1022,   387,  1021,
    1517,  1023,   857,  1032,  1033,   700,  1340,   600,   474,   366,
     367,   368,   369,   370,   371,   372,   373,   374,  1348,  1034,
    1349,  1035,   375,   386,  1036,  1038,  1039,  1040,  1355,  1041,
    1044,  1045,  1057,  1359,  1042,  1062,  1063,  1546,  1069,  1549,
    1066,  1067,  1068,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,  1065,  1074,  1562,
     386,   375,  1086,  1099,   355,  1087,  1088,  1377,  1098,  1380,
    1089,  1383,  1109,   920,  1112,  1119,  1091,   676,   677,   678,
    1123,   386,  1126,  1127,  1118,  1396,  1130,  1124,  1131,  1125,
    1132,  1136,  1129,  1139,  1402,  1403,   694,  1137,  1152,  1140,
    1141,  1406,  1142,  1146,  1153,  1160,  1164,  1165,  1172,  1413,
    1180,  1173,  1177,  1417,  1179,  1181,  1378,  1182,  1381,  1183,
    1384,  1187,  1191,  1207,  1201,  1190,  1208,   387,  1392,   387,
    1210,  1395,  1213,  1214,  1215,  1216,  1223,   700,   824,  1200,
    1224,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,  1225,  1228,  1452,  1230,   375,
    1456,  1231,  1232,  1460,  1233,  1236,  1241,  1463,  1244,   387,
    1255,   386,  1258,   386,  1261,  1265,  1269,  1272,  1472,  1276,
    1297,  1474,  1294,  1480,  1299,   981,   982,  1298,   984,  1300,
     987,   988,     7,     8,   991,   992,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,  1301,   387,
    1303,   387,   375,  1304,  1501,   387,   387,   387,   387,  1306,
    1305,  1314,  1468,   387,  1315,   814,  1316,   816,  1317,  1318,
    1319,   386,  1320,  1321,  1324,   579,    19,    20,   580,    22,
      23,   581,    25,   582,    27,  1325,    28,  1336,  1327,    31,
      32,  1328,    34,    35,    36,  1330,  1332,  1538,    39,  1537,
    1334,  1338,  1345,  1339,  1352,  1353,  1347,   858,  1054,  1055,
    1056,  1360,  1366,  1362,  1367,  1368,  1369,  1370,  1064,  1371,
    1386,  1393,  1400,  1405,  1401,  1558,    58,    59,    60,  1073,
    1416,  1428,  1437,  1429,  1444,  1445,  1111,  1432,  1447,  1448,
     787,   387,  1450,   387,  1453,  1454,  1457,   897,  1458,   898,
    1461,  1462,  1467,   902,   903,   904,   905,  1481,  1483,  1487,
    1485,   908,  1495,  1504,  1496,  1507,     7,     8,  1510,  1513,
    1515,   387,   387,   387,   387,  1519,  1520,  1539,  1526,  1541,
    1528,  1530,  1122,  1535,  1543,  1545,  1547,   712,  1128,  1557,
     962,  1559,  1560,  1561,  1133,  1134,  1135,  1563,   610,  1438,
    1138,  1121,    82,    90,  1209,  1143,  1144,  1145,     0,   579,
      19,    20,   580,    22,    23,   581,    25,   582,    27,   634,
      28,  1162,   993,    31,    32,  1502,    34,    35,    36,     0,
       0,  1171,    39,     0,     0,  1175,     0,     0,     0,   943,
       0,   944,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
      58,    59,    60,     0,     0,     0,     0,     0,     0,   968,
     969,   970,   971,     0,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,     0,     0,
       0,  1203,   375,  1204,     0,   579,    19,    20,   580,    22,
      23,   581,    25,   582,    27,     0,    28,     0,     0,    31,
      32,     0,    34,    35,    36,     0,     0,     0,    39,     0,
       0,   879,     0,     0,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,  1237,  1238,
    1239,  1240,   375,     0,     0,     0,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
    1037,  1073,     0,     0,   375,     0,     0,     0,     0,     0,
       0,     0,  1279,     0,     0,     0,     0,     0,     0,  1288,
       0,     0,     0,     0,     0,     0,  1293,     0,    95,   238,
       0,     0,     0,   387,    99,   100,   101,   914,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     240,     0,  1093,     0,     0,     0,     0,     0,   128,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     241,     0,     0,   242,     0,     0,   243,     0,   244,     0,
       0,     0,     0,     0,  1337,     0,     0,     0,   245,     0,
       0,     0,     0,     0,    40,    41,    42,    43,    44,     0,
       0,     0,    48,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,  1073,     0,     0,     0,     0,     0,     0,
       0,  1176,     0,     0,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,     0,     0,
    1073,   133,   375,     0,     0,     0,     0,     0,   136,   137,
     138,     0,     0,     0,     0,   387,     0,  1389,     0,   387,
       0,     0,     0,     0,   433,  1270,     0,     0,     0,   145,
       0,     0,     0,     0,   435,     0,     0,     0,     0,   151,
       0,   208,   477,     0,     0,     0,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
       0,     0,    95,   238,   375,     0,  1427,     0,    99,   100,
     101,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   240,     0,     0,     0,     0,     0,
       0,     0,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     7,     8,     0,   241,   475,     0,   242,     0,     0,
     243,  1073,   244,  1477,     0,     0,     0,     0,     0,     0,
     387,     0,   245,     0,     0,     0,     0,     0,    40,    41,
      42,    43,    44,     0,     0,     0,    48,     0,     0,    51,
       0,     0,     0,     0,   579,    19,    20,   580,    22,    23,
     581,    25,   582,    27,     0,    28,     0,   387,    31,    32,
       0,    34,    35,    36,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     0,     0,   133,     0,     0,   387,     0,
       0,     0,   136,   137,   138,     0,     0,     0,  1073,     0,
       0,     0,     0,     0,     0,    58,    59,    60,   143,   385,
     479,     0,     0,   145,     0,     0,     0,     0,   247,     0,
       0,     0,     0,   151,     0,     0,   477,     0,  1350,     0,
       0,     0,     0,    95,   274,     0,     0,     0,     0,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,  1373,  1430,     0,     0,     0,
       0,     0,     0,   128,   129,   130,     0,     0,   387,     0,
     387,     0,     0,     0,     0,     0,  1394,    95,    96,    97,
       0,    98,     0,    99,   100,   101,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
       0,   387,   123,   124,   125,   126,   127,   128,   129,   130,
       0,     0,   131,     0,     0,     0,     0,     0,   387,     0,
       0,     0,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   480,   373,   374,   133,     0,     0,     0,
     375,     0,     0,   136,   137,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1466,     0,  1469,   143,
     144,     0,     0,     0,   145,     0,     0,     0,     0,   247,
       0,     0,   347,     0,   151,     0,   348,     0,     0,     0,
       0,     0,     0,     0,   132,     0,     0,     0,     0,     0,
     133,   134,   135,     0,     0,     0,     0,   136,   137,   138,
     139,   140,   141,   142,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   144,     0,  1514,     0,   145,     0,
     146,   147,     0,   148,     0,   149,     0,   150,   151,     0,
     152,    95,   238,   239,     0,     0,     0,    99,   100,   101,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   240,     0,     0,     0,     0,     0,     0,
       0,   128,   129,   130,     0,     0,     0,     7,     8,     0,
       0,     0,     0,   241,     0,     0,   242,     0,     0,   243,
       0,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,     0,     0,     0,     0,     0,    40,    41,    42,
      43,    44,     0,     0,     0,    48,     0,     0,    51,     0,
     579,    19,    20,   580,    22,    23,   581,    25,   582,    27,
       0,    28,     0,     0,    31,    32,     0,    34,    35,    36,
       0,     0,     0,    39,  1100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,     0,     0,     0,     0,     0,
       0,   136,   137,   138,  1178,     0,     0,     0,     0,     0,
       0,    58,    59,    60,     0,     0,     0,   143,   246,     0,
       0,     0,   145,     0,     0,     0,     0,   247,     0,    95,
     238,  1169,   151,     0,   248,    99,   100,   101,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   240,     0,     0,     0,     0,     0,     0,     0,   128,
     129,   130,  1490,     0,     0,     0,     0,     0,     0,     0,
       0,   241,     0,     0,   242,     0,     0,   243,     0,   244,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
       0,     0,     0,     0,     0,    40,    41,    42,    43,    44,
       0,     0,     0,    48,     0,     0,    51,     0,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,     0,     0,     0,   375,     0,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   133,  1302,     0,     0,   375,     0,     0,   136,
     137,   138,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,   143,   246,   375,     0,     0,
     145,     0,     0,     0,     0,   247,     0,    95,   238,  1475,
     151,     0,  1170,    99,   100,   101,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   240,
       0,     0,     0,     0,     0,     0,     0,   128,   129,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
       0,     0,   242,     0,     0,   243,     0,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,     0,     0,
       0,     0,     0,    40,    41,    42,    43,    44,     0,     0,
       0,    48,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,  1323,     0,     0,     0,   375,     0,     0,     0,     0,
     133,     0,     0,     0,     0,     0,     0,   136,   137,   138,
    1351,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   246,     0,     0,     0,   145,     0,
       0,     0,     0,   247,     0,    95,   238,     0,   151,     0,
    1476,    99,   100,   101,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   240,     0,     0,
       0,     0,     0,     0,     0,   128,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,     0,     0,
     242,     0,     0,   243,     0,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,     0,     0,     0,     0,
       0,    40,    41,    42,    43,    44,     0,     0,     0,    48,
       0,     0,    51,     0,     0,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   133,  1436,
       0,     0,   375,     0,     0,   136,   137,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   246,     0,     0,     0,   145,     0,     0,     0,
       0,   247,     0,    95,   238,     0,   151,     0,   248,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   240,     0,     0,     0,     0,
       0,     0,     0,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   245,     0,     0,     0,     0,     0,    40,
      41,    42,    43,    44,     0,     0,     0,    48,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,  1488,     0,     0,
       0,   375,     0,     0,     0,     0,   133,     0,     0,     0,
       0,     0,     0,   136,   137,   138,     0,  1523,   479,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   143,
     385,     0,     0,     0,   145,     0,     0,     0,     0,   247,
       0,    95,   238,     0,   151,     0,   473,    99,   100,   101,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   240,     0,     0,     0,     0,     0,     0,
       0,   128,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   241,     0,     0,   242,     0,     0,   243,
       0,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,     0,     0,     0,     0,     0,    40,    41,    42,
      43,    44,     0,     0,     0,    48,     0,     0,    51,     0,
       0,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   612,   373,   374,   133,  1551,     0,     0,   375,     0,
       0,   136,   137,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   385,     0,
       0,     0,   145,     0,     0,     0,     0,   247,     0,    95,
     238,     0,   151,     0,   698,    99,   100,   101,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   240,     0,     0,     0,     0,     0,     0,     0,   128,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   241,     0,     0,   242,     0,     0,   243,     0,   244,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
       0,     0,     0,     0,     0,    40,    41,    42,    43,    44,
       0,     0,     0,    48,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,   479,     0,     0,   375,     0,     0,     0,
       0,     0,   133,     0,     0,     0,     0,     0,     0,   136,
     137,   138,   708,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   246,     0,     0,     0,
     145,     0,     0,     0,     0,   247,     0,    95,   238,     0,
     151,     0,  1174,    99,   100,   101,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   240,
       0,     0,     0,     0,     0,     0,     0,   128,   129,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
       0,     0,   242,     0,     0,   243,     0,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,     0,     0,
       0,     0,     0,    40,    41,    42,    43,    44,     0,     0,
       0,    48,     0,     0,    51,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   612,   373,   374,     0,
       0,     0,     0,   375,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   810,     0,
     133,     0,   375,     0,     0,     0,     0,   136,   137,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   433,  1270,     0,     0,     0,   145,     0,
       0,     0,     0,   435,     0,    95,   274,   285,   151,     0,
     208,    99,   100,   101,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,     0,     0,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
     131,    95,   274,   285,     0,     0,     0,    99,   100,   101,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,   131,     0,     0,     0,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,     0,     0,   375,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,   134,
     135,     0,     0,     0,     0,   136,   137,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,     0,     0,     0,   145,     0,     0,     0,
       0,   247,     0,     0,     0,     0,   151,     0,  1114,     0,
       0,     0,     0,     0,   133,   134,   135,     0,     0,     0,
       0,   136,   137,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   144,     0,
       0,     0,   145,     0,     0,     0,     0,   247,     0,    95,
     274,     0,   151,     0,  1285,    99,   100,   101,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,     0,    95,   274,  1478,   128,
     129,   130,    99,   100,   101,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,     0,    95,   274,     0,   128,   129,   130,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,   128,   129,   130,     0,     0,     0,     0,
       0,     0,   133,     0,     0,     0,     0,     0,     0,   136,
     137,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   144,     0,     0,     0,
     145,     0,     0,     0,     0,   247,     0,     0,   685,   133,
     151,     0,   686,     0,     0,     0,   136,   137,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,     0,     0,     0,   145,     0,     0,
       0,     0,   247,     0,     0,     0,   133,   151,     0,  1479,
       0,     0,     0,   136,   137,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   143,
     144,     0,     0,     0,   145,     0,     0,     0,     0,   247,
       0,    95,   274,     0,   151,     0,   345,    99,   100,   101,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,     0,    95,   238,
       0,   128,   129,   130,    99,   100,   101,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     240,     0,     0,     0,     0,     0,     0,     0,   128,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     241,     0,     0,   242,     0,     0,   243,     0,   244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,     0,
       0,     0,     0,     0,    40,    41,    42,    43,    44,     0,
       0,     0,    48,     0,   133,    51,     0,     0,     0,     0,
       0,   136,   137,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   907,     0,     0,   433,   434,     0,
       0,     0,   145,     0,     0,     0,     0,   435,     0,     0,
       0,   133,   151,     0,   208,     0,  1059,     0,   136,   137,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   385,     0,     0,     0,   145,
      95,   274,   285,     0,   247,     0,    99,   100,   101,   151,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     0,     0,     0,   123,   124,   125,   126,   127,
     128,   129,   130,    95,   274,   131,     0,     0,     0,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,   128,   129,   130,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
       0,     0,     0,     0,   375,     0,     0,     0,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,   133,   134,   135,   375,     0,     0,     0,
     136,   137,   138,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,     0,     0,
       0,   145,     0,     0,     0,     0,   247,     0,     0,    -4,
       1,   151,     0,    -4,     0,     0,   133,     0,     0,     0,
       0,    -4,    -4,   136,   137,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   143,
     144,     0,     0,     0,   145,    -4,    -4,     0,     0,   247,
       0,     0,     0,     0,   151,    -4,    -4,     0,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     6,    -4,    -4,     0,     0,     0,    -4,
       0,     7,     8,     0,    -4,    -4,    -4,    -4,     0,     0,
      -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     9,    10,     0,    -4,    -4,
      -4,    -4,     0,     0,     0,    11,    12,     0,    13,    14,
      15,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     0,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     7,     8,    54,    55,   998,     0,     0,    56,
       0,     0,     0,     0,    57,    58,    59,    60,     0,     0,
      61,     0,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,   579,    19,    20,   580,    22,
      23,   581,    25,   582,    27,     0,    28,     0,     0,    31,
      32,     0,    34,    35,    36,     0,     0,     0,    39,     0,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,     0,     0,   375,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,     0,
       0,     0,     0,     0,  1250,     0,  1251,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,     0,
       0,     0,  1280,     0,  1281,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,     0,     0,     0,
    1375,     0,  1376,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,     0,     0,     0,     0,     0,     0,     0,
     839,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,     0,     0,     0,   882,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,     0,
       0,     0,     0,     0,     0,     0,   901,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,     0,
       0,     0,     0,     0,   926,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,     0,     0,     0,
       0,     0,  1015,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,     0,     0,     0,     0,     0,     0,     0,
    1248,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,     0,     0,     0,  1267,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,     0,
       0,     0,     0,     0,     0,     0,  1310,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,     0,
       0,     0,     0,     0,  1311,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,     0,     0,     0,
       0,     0,  1312,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,     0,     0,     0,     0,     0,     0,     0,
    1313,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,     0,     0,     0,  1346,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,     0,
       0,     0,     0,     0,     0,     0,  1391,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,     0,
       0,     0,     0,     0,  1397,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,     0,     0,     0,
       0,     0,  1398,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,     0,     0,     0,     0,     0,     0,     0,
    1418,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,     0,     0,     0,  1421,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,     0,
       0,     0,     0,     0,     0,     0,  1424,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,     0,
       0,     0,     0,     0,  1446,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,     0,     0,     0,
       0,     0,  1449,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,     0,     0,     0,     0,     0,     0,     0,
    1482,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,     0,     0,     0,  1484,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,     0,
       0,     0,     0,     0,     0,     0,  1486,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,     0,
       0,     0,     0,     0,  1499,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,     0,     0,     0,
       0,   644,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,     0,     0,     0,     0,
     375,     0,     0,     0,     0,     0,     0,     0,  1322,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,   695,
       0,     0,     0,     0,   648,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,     0,     0,     0,
     605,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,     0,   648,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,     0,
       0,     0,   649,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,     0,     0,     0,     0,     0,   705,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,     0,
       0,     0,     0,     0,   753,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,     0,     0,     0,
     754,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,     0,   767,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,     0,
       0,     0,   768,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,     0,     0,     0,     0,     0,   769,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,     0,
       0,     0,     0,     0,   770,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,     0,     0,     0,
     771,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,     0,   772,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,     0,
       0,     0,   867,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,     0,     0,     0,     0,     0,   868,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,     0,
       0,     0,     0,     0,   869,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,     0,     0,     0,
     977,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,     0,  1013,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,     0,
       0,     0,  1014,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,     0,     0,     0,     0,     0,  1058,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,     0,
       0,     0,     0,     0,  1195,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,     0,     0,     0,
    1196,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,     0,  1218,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,     0,
       0,     0,  1356,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,     0,     0,     0,     0,     0,  1357,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,     0,
       0,     0,     0,     0,  1363,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,     0,     0,     0,
    1440,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,     0,  1443,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,   571,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,     0,     0,   375,     0,
       0,     0,   710,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,     0,     0,   717,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
       0,     0,     0,     0,   375,     0,     0,     0,   732,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,     0,
       0,   734,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,     0,     0,     0,     0,
     375,     0,     0,     0,   736,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,   738,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,     0,     0,     0,   375,     0,     0,     0,
     740,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,     0,     0,   742,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,     0,     0,
       0,     0,   375,     0,     0,     0,   744,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,   746,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,     0,     0,   375,     0,
       0,     0,   748,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,     0,     0,   750,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
       0,     0,     0,     0,   375,     0,     0,     0,   752,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,     0,
       0,   756,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,     0,     0,     0,     0,
     375,     0,     0,     0,   758,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,   760,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,     0,     0,     0,   375,     0,     0,     0,
     762,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,     0,     0,   764,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,     0,     0,
       0,     0,   375,     0,     0,     0,   766,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,   890,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,     0,     0,   375,     0,
       0,     0,   891,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,     0,     0,   895,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
       0,     0,     0,     0,   375,     0,     0,     0,   896,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,     0,
       0,   899,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,     0,     0,     0,     0,
     375,     0,     0,     0,   922,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,     0,     0,  1076,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,     0,     0,     0,   375,     0,     0,     0,
    1078,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,     0,     0,  1080,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,     0,     0,
       0,     0,   375,     0,     0,     0,  1082,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,     0,     0,  1083,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,     0,     0,   375,     0,
       0,     0,  1211,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,     0,     0,  1335,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
       0,     0,     0,     0,   375,     0,   567,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,   611,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,     0,     0,     0,   375,     0,   615,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,   616,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,     0,     0,   375,     0,
     618,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,   620,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,     0,     0,     0,     0,
     375,     0,   621,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,   624,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,     0,     0,
       0,     0,   375,     0,   625,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,   695,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
       0,     0,     0,     0,   375,     0,   701,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,   702,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,     0,     0,     0,   375,     0,   703,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,   709,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,     0,     0,   375,     0,
     731,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,   733,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,     0,     0,     0,     0,
     375,     0,   735,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,   737,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,     0,     0,
       0,     0,   375,     0,   739,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,   741,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
       0,     0,     0,     0,   375,     0,   743,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,   745,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,     0,     0,     0,   375,     0,   747,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,   749,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,     0,     0,   375,     0,
     751,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,   755,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,     0,     0,     0,     0,
     375,     0,   757,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,   759,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,     0,     0,
       0,     0,   375,     0,   761,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,   763,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
       0,     0,     0,     0,   375,     0,   765,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,   828,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,     0,     0,     0,   375,     0,   833,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,   838,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,     0,     0,   375,     0,
     840,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,   841,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,     0,     0,     0,     0,
     375,     0,   847,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,   854,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,     0,     0,
       0,     0,   375,     0,   855,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,   856,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
       0,     0,     0,     0,   375,     0,   881,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,   883,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,     0,     0,     0,   375,     0,   884,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,   885,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,     0,     0,   375,     0,
     889,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375,
       0,  1075,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,     0,     0,     0,     0,
     375,     0,  1077,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,   375,     0,  1079,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,     0,     0,
       0,     0,   375,     0,  1081,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,   375,     0,  1090,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
       0,     0,     0,     0,   375,     0,  1249,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,   375,     0,  1266,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,     0,     0,     0,   375,     0,  1284,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,   375,     0,  1439,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,     0,     0,   375,     0,
    1497,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,   375
};

static const yytype_int16 yycheck[] =
{
       6,  1172,     3,   216,     6,   427,   428,     6,   347,     4,
       4,   350,     6,     6,     6,   228,     5,    13,     4,     6,
       4,     6,     4,     6,   149,   150,     4,   803,     4,   160,
       4,   876,     4,     4,   165,     4,     4,     7,    58,     5,
       5,    61,   167,     6,     6,    55,   149,   150,    58,     6,
       4,    61,     6,   149,   150,     4,   149,   150,   271,    76,
     273,    76,     4,   166,   151,   152,   153,     6,    85,   880,
      85,   158,   165,    61,   167,    77,    93,    94,    93,    94,
      97,    98,    97,    98,     4,     5,     7,     0,    41,    42,
       7,    44,    98,   329,   330,   331,   332,   333,   334,   335,
     336,    55,   159,   339,   340,   341,   101,   102,   103,   104,
     160,   156,   157,    55,    99,   165,    99,    59,    38,    39,
      40,    41,    42,  1294,   159,   111,   112,    69,    48,   111,
     112,   149,   150,   160,    58,     6,   120,    61,   165,   149,
     150,   143,   144,   145,   149,   150,   148,   149,   166,   159,
    1321,   152,   167,   146,   146,     6,   166,   159,   156,   157,
     165,   163,   149,   150,    61,   163,    63,   161,   170,   171,
     172,   173,   167,   175,   176,   177,   178,   166,   180,   181,
     182,   159,   166,   159,   156,   157,  1031,   963,   166,   161,
     166,   163,   166,   163,     6,   166,   168,   166,   166,   201,
     166,   166,   159,   166,   166,   207,   208,   127,   128,   166,
     159,   149,   150,     6,   216,   136,   137,   138,   139,   136,
     137,   138,   139,     6,     7,   438,     7,   165,   567,   167,
     149,   150,   571,   149,   150,   162,   156,   157,   165,   156,
     157,   149,   150,   163,   246,   247,   248,   166,     7,   165,
     161,   204,   205,   159,   256,   257,   258,   165,   260,   212,
     166,   263,   264,   216,   159,   267,   149,   150,   161,   156,
     157,  1442,   159,   159,   161,   488,   163,   159,   280,   166,
     166,   168,   165,   159,   167,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,  1103,   149,   150,
     156,   157,    76,     6,     7,   161,   338,   163,   159,     4,
     159,    85,   168,   345,   159,   166,   348,   166,  1519,    93,
      94,   350,   159,    97,    98,   136,   137,   138,   139,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   610,   156,   157,   136,   137,   138,
     139,   159,   163,   385,   160,    65,   159,   149,   150,   391,
     166,   149,   150,   166,   396,    61,    63,   156,   157,   401,
     402,   403,   404,   165,   149,   150,   408,   165,   149,   150,
       6,   413,   414,   415,    79,    80,    81,    82,   149,   150,
     165,    61,    87,   167,   165,    90,   427,   428,   430,   431,
     432,   433,   434,   435,   165,   159,    61,   439,   440,   441,
     442,   443,    61,   149,   150,   447,     8,    76,   450,   451,
       4,     5,   454,   455,   456,    58,    85,   459,   460,   165,
     462,   166,   166,   465,    93,    94,   149,   150,    97,    98,
      58,   473,   425,   426,   160,     5,    61,   479,   480,   165,
     433,   717,   165,    58,    38,    39,    40,    41,    42,    61,
      58,   149,   150,    61,    48,    63,   498,   149,   150,   160,
     502,   149,   150,   505,   165,   504,     4,   165,    38,    39,
      40,    41,    42,   165,   165,   160,   167,   165,    48,  1330,
     165,  1332,     4,  1334,   160,   149,   150,  1303,   160,   165,
     189,   190,   191,   165,  1379,    76,   162,  1382,   167,   165,
    1385,   165,   162,   779,    85,   165,   782,   783,   784,   159,
     786,   161,    93,    94,   790,     4,    97,    98,   149,   150,
     151,   152,   153,   222,   223,    58,   572,   158,    61,   159,
      63,   573,   571,   127,   128,   234,   235,   813,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   149,   150,   159,   159,   158,   127,   128,   159,
     602,   161,   604,   605,     8,   167,   149,   150,   165,   162,
     612,   613,   165,   952,   159,    55,   955,   956,    58,  1464,
    1431,    61,   165,    63,   626,   161,   167,   149,   150,   631,
     636,   637,   638,   639,   636,   637,   638,   639,   149,   150,
       6,     6,   644,   165,     4,    55,   648,   649,    58,     4,
     166,    61,   654,    63,   165,   159,   159,   161,  1503,   159,
     159,  1506,   161,   159,  1509,   667,     7,  1512,   670,   159,
    1481,   161,  1483,   159,  1485,   161,   637,   638,   639,   159,
    1491,   161,   684,   159,   686,   161,   159,   159,   690,   691,
     692,   693,   159,   159,   647,  1540,   698,  1542,   159,  1544,
     161,   654,   159,   705,    76,   707,   708,   660,   159,   159,
     161,   161,   159,    85,   161,  1526,   159,  1528,   717,  1530,
       8,    93,    94,   159,     4,    97,    98,   159,     6,   161,
    1152,  1153,   159,   159,   161,   161,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
       6,   753,   754,   159,   158,   161,   159,   159,   161,   161,
     159,     6,   161,   167,     5,   767,   768,   769,   770,   771,
     772,   773,   153,   159,   776,   161,   778,   159,     5,   161,
     159,   165,   161,   167,    12,    13,   788,   165,   159,   167,
     792,   165,    76,   167,   796,   167,   165,   161,   167,   163,
     159,    85,   183,    76,   806,   807,   808,   809,   810,    93,
      94,   159,    85,    97,    98,   165,   165,   167,   167,   200,
      93,    94,   203,   166,    97,    98,   159,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   165,    66,   167,
     159,    69,    70,   224,    72,    73,    74,   159,   159,     6,
      78,  1087,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   165,    76,   167,   822,
     158,   165,   160,   167,   159,  1111,    85,   159,   106,   107,
     108,     4,   159,   167,    93,    94,    12,    13,    97,    98,
     166,   165,   894,   167,   167,   166,   277,   278,   166,    61,
     899,    63,   165,  1325,   167,   907,   165,   165,   167,   167,
     165,   165,   167,   167,   867,   868,   869,   165,   165,   167,
     167,   165,   165,   167,   167,   159,   928,   929,   159,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   167,
      66,   159,   161,    69,    70,     6,    72,    73,    74,   165,
     161,   167,    78,   165,     5,   167,   171,   956,   167,   166,
     166,   176,   964,   166,   165,   180,   167,   165,   165,   167,
     167,     4,   978,     6,   161,   977,   978,   165,   161,   167,
     106,   107,   108,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    76,   165,     5,
     167,   158,   165,     6,   167,   165,    85,   167,    76,     5,
    1012,  1013,  1014,     6,    93,    94,   163,    85,    97,    98,
    1022,  1023,   165,   114,   167,    93,    94,   166,  1030,    97,
      98,   246,   165,   248,   167,   165,  1038,   167,   165,     6,
     167,   167,     6,   165,    76,   167,   165,   165,   167,   167,
     165,     6,   167,    85,   171,   161,  1058,  1059,  1060,   176,
       4,    93,    94,   180,    76,    97,    98,  1069,  1067,   165,
       6,   167,  1074,    85,    76,   158,   165,  1030,   167,   166,
       7,    93,    94,    85,   161,    97,    98,   163,   167,  1095,
       6,    93,    94,   166,  1096,    97,    98,   167,   165,   167,
     167,   165,   165,   167,   167,   165,     7,   167,  1114,   165,
       7,   167,  1114,   165,     7,   167,  1118,   165,   159,   167,
     159,   159,  1124,  1125,   159,     7,  1339,  1129,     6,   160,
     345,     4,     7,   348,  1136,   167,     6,   166,     7,     6,
       6,     6,  1148,   166,  1146,   166,  1148,   166,   111,   166,
     160,  1152,  1153,   160,   165,   167,   160,   165,  1160,     6,
     165,   160,     4,     6,   165,   167,  1119,   165,  1170,     6,
     385,   165,  1174,   162,     6,  1177,     4,     6,   163,   114,
       7,     7,     7,  1189,     7,   114,     7,  1189,   569,     7,
     114,     7,     7,  1195,  1196,     4,     6,   167,   167,     6,
     162,  1154,     7,  1156,     7,  1158,     7,   163,   166,     6,
     159,   159,   166,     6,     4,   160,  1218,  1170,     6,  1432,
    1173,  1174,   162,     6,     6,   146,     7,   161,   345,     6,
      61,   348,     7,     7,     7,     7,     7,     7,     7,   454,
     455,   456,     6,    63,     7,   160,   160,   160,  1250,   160,
       7,   632,     7,     7,     6,     4,     4,   166,   473,     6,
    1496,   159,   643,     7,     6,   480,  1268,     6,  1270,   145,
     146,   147,   148,   149,   150,   151,   152,   153,  1280,     7,
    1282,     7,   158,  1285,     7,   166,     6,     6,  1290,     6,
       6,     6,     4,  1295,    61,     4,     4,  1533,   159,  1535,
       6,     4,     6,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   167,   166,  1555,
    1322,   158,   160,     7,  1325,   165,   160,  1329,   163,  1331,
     160,  1333,     6,   714,     6,    69,   160,   454,   455,   456,
       6,  1343,     6,     6,   166,  1347,     6,   166,     6,   166,
       5,     4,   166,     7,  1356,  1357,   473,     6,   166,     7,
       7,  1363,     7,     7,   166,   161,     6,     6,   166,  1371,
     162,   166,   166,  1375,   160,     6,  1329,     6,  1331,   110,
    1333,     6,     6,     6,   163,   165,     4,   602,  1341,   604,
       6,  1344,     6,     6,     6,     6,     6,   612,   613,  1401,
       6,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     6,     6,  1419,     5,   158,
    1422,     6,     6,  1425,   114,     6,     6,  1429,     6,   644,
       6,  1433,     6,  1435,     6,   165,     6,     6,  1440,     6,
       4,  1443,   166,  1445,     6,   826,   827,   160,   829,     6,
     831,   832,    12,    13,   835,   836,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,     6,   684,
       7,   686,   158,     6,  1476,   690,   691,   692,   693,     6,
     163,     5,  1435,   698,    59,   602,     6,   604,     6,     6,
       6,  1493,     6,   166,     6,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   166,    66,     6,   167,    69,
      70,   167,    72,    73,    74,   166,   166,  1523,    78,  1521,
     166,     7,     6,   166,     6,   167,   109,   644,   909,   910,
     911,     6,     6,   112,     6,     6,     6,     6,   919,   166,
       6,     6,     6,     6,   166,  1551,   106,   107,   108,   930,
     167,     6,     6,    76,     4,     4,   975,   166,     6,     6,
       6,   776,     6,   778,     6,     6,     6,   684,     6,   686,
       6,   167,     6,   690,   691,   692,   693,   166,   166,     6,
     166,   698,     6,     6,   166,     6,    12,    13,     6,     6,
       6,   806,   807,   808,   809,   166,     6,     6,   166,     6,
     166,   166,   983,   166,     6,     6,     6,   167,   989,     6,
       6,     6,     6,     6,   995,   996,   997,     6,   383,  1401,
    1001,   982,     3,     3,  1099,  1006,  1007,  1008,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   407,
      66,  1022,     6,    69,    70,  1479,    72,    73,    74,    -1,
      -1,  1032,    78,    -1,    -1,  1036,    -1,    -1,    -1,   776,
      -1,   778,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,   806,
     807,   808,   809,    -1,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,  1092,   158,  1094,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    -1,    -1,    69,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    78,    -1,
      -1,   167,    -1,    -1,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,  1139,  1140,
    1141,  1142,   158,    -1,    -1,    -1,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
       6,  1172,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1183,    -1,    -1,    -1,    -1,    -1,    -1,  1190,
      -1,    -1,    -1,    -1,    -1,    -1,  1197,    -1,     3,     4,
      -1,    -1,    -1,  1038,     9,    10,    11,   167,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,     6,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    58,    -1,    -1,    61,    -1,    63,    -1,
      -1,    -1,    -1,    -1,  1265,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    87,    -1,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1294,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1038,    -1,    -1,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
    1321,   126,   158,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,    -1,    -1,    -1,    -1,  1170,    -1,  1338,    -1,  1174,
      -1,    -1,    -1,    -1,   149,   150,    -1,    -1,    -1,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,   164,
      -1,   166,   167,    -1,    -1,    -1,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,     3,     4,   158,    -1,  1387,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,    55,  1270,    -1,    58,    -1,    -1,
      61,  1442,    63,  1444,    -1,    -1,    -1,    -1,    -1,    -1,
    1285,    -1,    73,    -1,    -1,    -1,    -1,    -1,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    87,    -1,    -1,    90,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    -1,  1322,    69,    70,
      -1,    72,    73,    74,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,  1343,    -1,
      -1,    -1,   133,   134,   135,    -1,    -1,    -1,  1519,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,   108,   149,   150,
       8,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,   164,    -1,    -1,   167,    -1,  1285,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,  1322,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    -1,    -1,  1433,    -1,
    1435,    -1,    -1,    -1,    -1,    -1,  1343,     3,     4,     5,
      -1,     7,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,  1476,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,  1493,    -1,
      -1,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   126,    -1,    -1,    -1,
     158,    -1,    -1,   133,   134,   135,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1433,    -1,  1435,   149,
     150,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,
      -1,    -1,   162,    -1,   164,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,    -1,  1493,    -1,   154,    -1,
     156,   157,    -1,   159,    -1,   161,    -1,   163,   164,    -1,
     166,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    -1,    -1,    -1,    12,    13,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    58,    -1,    -1,    61,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    87,    -1,    -1,    90,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    -1,    -1,    69,    70,    -1,    72,    73,    74,
      -1,    -1,    -1,    78,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,
      -1,   133,   134,   135,     6,    -1,    -1,    -1,    -1,    -1,
      -1,   106,   107,   108,    -1,    -1,    -1,   149,   150,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,    -1,     3,
       4,     5,   164,    -1,   166,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    58,    -1,    -1,    61,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    87,    -1,    -1,    90,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   126,     6,    -1,    -1,   158,    -1,    -1,   133,
     134,   135,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,   149,   150,   158,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,    -1,     3,     4,     5,
     164,    -1,   166,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    58,    -1,    -1,    61,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    87,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     6,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   159,    -1,     3,     4,    -1,   164,    -1,
     166,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      58,    -1,    -1,    61,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    79,    80,    81,    82,    83,    -1,    -1,    -1,    87,
      -1,    -1,    90,    -1,    -1,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   126,     6,
      -1,    -1,   158,    -1,    -1,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,   159,    -1,     3,     4,    -1,   164,    -1,   166,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,    -1,
      -1,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    87,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     6,    -1,    -1,
      -1,   158,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,   133,   134,   135,    -1,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,
      -1,     3,     4,    -1,   164,    -1,   166,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    58,    -1,    -1,    61,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    87,    -1,    -1,    90,    -1,
      -1,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   126,     7,    -1,    -1,   158,    -1,
      -1,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,    -1,     3,
       4,    -1,   164,    -1,   166,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    58,    -1,    -1,    61,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    87,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,     8,    -1,    -1,   158,    -1,    -1,    -1,
      -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,    -1,     3,     4,    -1,
     164,    -1,   166,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    58,    -1,    -1,    61,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    87,    -1,    -1,    90,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,     8,    -1,
     126,    -1,   158,    -1,    -1,    -1,    -1,   133,   134,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   159,    -1,     3,     4,     5,   164,    -1,
     166,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      48,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,    -1,    -1,    -1,    -1,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,   164,    -1,   166,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,    -1,     3,
       4,    -1,   164,    -1,   166,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    43,
      44,    45,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    43,    44,    45,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,    -1,    -1,   162,   126,
     164,    -1,   166,    -1,    -1,    -1,   133,   134,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,    -1,    -1,    -1,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   126,   164,    -1,   166,
      -1,    -1,    -1,   133,   134,   135,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,
      -1,     3,     4,    -1,   164,    -1,   166,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    43,    44,    45,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    58,    -1,    -1,    61,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    87,    -1,   126,    90,    -1,    -1,    -1,    -1,
      -1,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,   149,   150,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   126,   164,    -1,   166,    -1,     8,    -1,   133,   134,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,    -1,    -1,    -1,   154,
       3,     4,     5,    -1,   159,    -1,     9,    10,    11,   164,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,     3,     4,    48,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,   126,   127,   128,   158,    -1,    -1,    -1,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,    -1,    -1,
      -1,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,     0,
       1,   164,    -1,     4,    -1,    -1,   126,    -1,    -1,    -1,
      -1,    12,    13,   133,   134,   135,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,    -1,    -1,    -1,   154,    36,    37,    -1,    -1,   159,
      -1,    -1,    -1,    -1,   164,    46,    47,    -1,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,     4,    95,    96,    -1,    -1,    -1,   100,
      -1,    12,    13,    -1,   105,   106,   107,   108,    -1,    -1,
     111,    -1,   113,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    36,    37,    -1,   129,   130,
     131,   132,    -1,    -1,    -1,    46,    47,    -1,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    12,    13,    95,    96,    76,    -1,    -1,   100,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,    -1,    -1,
     111,    -1,   113,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,   129,   130,
     131,   132,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    -1,    -1,    69,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    78,    -1,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,   165,    -1,   167,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,   165,    -1,   167,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
     165,    -1,   167,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,
      -1,    -1,    -1,    -1,   165,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,   165,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,   165,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,   165,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,   165,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,   165,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,   162,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,
      -1,    -1,   162,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,   162,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,   162,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,   162,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,    -1,    -1,    -1,   162,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,   162,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,
     162,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,   162,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,    -1,    -1,    -1,   162,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,   162,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,
      -1,    -1,   162,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,   162,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,   162,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,   162,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,    -1,    -1,    -1,   162,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,   162,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,
     162,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,   162,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,    -1,    -1,    -1,   162,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,   162,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,
      -1,    -1,   162,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,   162,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,   162,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,   162,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,    -1,    -1,    -1,   162,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,   162,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,
     162,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,   162,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,    -1,    -1,    -1,   162,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,   162,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,
      -1,    -1,   162,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,   162,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,    -1,   160,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,
     160,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,   160,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,    -1,   160,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,   160,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,    -1,   160,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,    -1,   160,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,
     160,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,   160,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,    -1,   160,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,   160,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,    -1,   160,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,    -1,   160,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,
     160,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,   160,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,    -1,   160,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,   160,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,    -1,   160,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,    -1,   160,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,
     160,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,   160,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,    -1,   160,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,   160,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,    -1,   160,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,    -1,   160,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,
     160,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,   160,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,    -1,   160,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,   160,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,    -1,   160,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,    -1,   160,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,
     160,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   170,   171,     6,     0,     4,    12,    13,    36,
      37,    46,    47,    49,    50,    51,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    95,    96,   100,   105,   106,   107,
     108,   111,   113,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   129,   130,   131,   132,   172,   174,
     175,   193,   207,   212,   215,   216,   217,   218,   219,   220,
     221,   241,   242,   243,   244,     3,     4,     5,     7,     9,
      10,    11,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    38,    39,    40,    41,    42,    43,    44,
      45,    48,   120,   126,   127,   128,   133,   134,   135,   136,
     137,   138,   139,   149,   150,   154,   156,   157,   159,   161,
     163,   164,   166,   191,   192,   245,   246,   258,    13,    61,
     159,   159,     6,   166,     6,     6,     6,     6,   161,   161,
     159,   166,   159,   159,     4,   159,   166,   159,   159,     4,
     166,   159,   159,    65,    61,    61,     6,    61,    61,    58,
      61,    63,    63,    55,    58,    61,    63,    58,    61,    63,
      58,    61,   159,    58,   166,   149,   150,   159,   166,   247,
     248,   247,   166,    55,    58,    61,   166,   247,     4,    55,
      59,    69,    61,    63,    61,    58,     4,   120,   166,     4,
       6,    55,    58,    61,    58,    61,     4,     4,     4,     5,
      35,    55,    58,    61,    63,    73,   150,   159,   166,   212,
     221,   245,   250,   251,   252,     4,   159,   159,   159,     4,
     166,   254,     4,   159,   159,     6,     6,   161,     4,     4,
       5,   166,     5,   166,     4,   245,     6,   159,   166,     4,
     161,   163,   168,   192,   166,     5,   258,   159,   161,   159,
     161,   159,   161,   159,   161,   159,   161,   159,   161,   159,
     161,   159,   161,   159,   161,   159,   161,   159,   161,   159,
     161,   159,   161,   159,   161,   159,   161,   159,   161,   159,
     161,   159,   161,   159,   161,   159,   161,   159,   161,   159,
     161,   159,   159,   159,   159,   159,   159,   159,     7,   159,
     159,   159,   245,   245,   245,   166,   245,   162,   166,   245,
       4,   111,   112,     4,     4,   212,   213,   214,   250,     6,
       6,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   158,     6,     6,   245,     5,
       5,   245,   195,   198,   245,   150,   245,   252,   253,   245,
     245,   159,   245,   253,   245,   245,   159,   253,   245,   245,
     250,   159,   166,   159,   159,   251,   251,   251,   159,   208,
     209,   210,   211,   159,   159,   159,   250,   245,     4,   250,
     247,   247,   247,   245,   245,   149,   150,   166,   166,   247,
     166,   166,   166,   149,   150,   159,   214,   247,   166,   159,
     166,   159,   159,   159,   251,   251,   250,   159,     4,     6,
     161,   161,   214,     6,   166,   166,   166,   251,   251,   161,
     161,   159,   161,   161,     5,   166,     5,     5,     5,    55,
      58,    61,    63,   166,   245,   252,   245,   167,   253,     8,
     151,     6,     6,   245,   245,   245,   163,   245,   166,   114,
     245,   245,   245,     6,     6,   214,     6,   214,   161,     6,
     250,   250,   161,   245,     4,   166,   176,     6,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
       4,   257,   258,   257,   257,   257,   257,   257,   257,   257,
     257,   259,   245,   257,   257,   257,   253,   160,     7,   191,
     253,   162,     7,   191,   192,   163,     7,   161,   167,    55,
      58,    61,    63,   207,     6,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
       6,   160,   165,   160,   165,   165,   162,   165,   194,   162,
     194,   160,   151,   165,   167,   160,   160,   245,   160,   167,
     160,   160,   245,   167,   160,   160,     7,   245,   245,   245,
     245,     7,     7,   239,   239,   245,   159,   159,   159,   159,
     245,   245,   245,     7,   166,   160,     6,   165,   165,   165,
     247,   247,   213,   213,   165,   245,   245,   245,   245,   225,
     165,   214,   245,   245,   245,   245,   245,     7,   240,     6,
       7,   245,     6,   245,   245,   167,   253,   253,   253,     6,
       6,   245,   245,   160,   166,   162,   166,   245,     4,   245,
     166,   166,   166,   166,   253,   160,   167,   245,   166,   245,
     252,   160,   160,   160,   111,   165,   214,   166,     8,   160,
     162,   167,   167,   160,   165,   167,   245,   162,   192,   245,
       4,   101,   102,   103,   104,   167,   179,   183,   186,   188,
     189,   160,   162,   160,   162,   160,   162,   160,   162,   160,
     162,   160,   162,   160,   162,   160,   162,   160,   162,   160,
     162,   160,   162,   165,   165,   160,   162,   160,   162,   160,
     162,   160,   162,   160,   162,   160,   162,   165,   165,   165,
     165,   165,   165,   161,   163,   160,   165,   162,   165,   165,
     160,   160,   165,   165,   165,   160,   165,     6,   165,   160,
     165,   167,   191,   250,   167,   163,   191,   192,   258,   245,
       6,     4,     4,   166,   255,   162,   166,   166,   166,   166,
       8,     6,   146,   173,   253,     6,   253,   245,     6,     4,
       6,   257,     7,   245,   252,   114,     7,     7,   160,     7,
     114,     7,     7,   160,   114,     7,     7,   245,   160,   167,
     160,   160,   245,   250,     4,   238,     6,   160,   204,   245,
     258,   204,   204,   204,   160,   160,   160,   250,   253,   163,
     247,   245,   245,   167,   167,   245,   247,   165,   165,   165,
      76,    85,    93,    94,    97,    98,   235,   236,   247,   167,
     222,   160,   167,   160,   160,   160,   245,     6,   245,   160,
     162,   162,   167,   167,   167,   162,   162,   253,   253,   162,
     162,   167,   253,   253,   253,   253,   167,     8,   253,     7,
       7,     7,   163,   245,   167,   245,   245,     7,   163,   166,
     250,     6,   162,   163,   192,   257,   167,   180,   159,   159,
     166,   190,     6,   245,   245,   245,   245,   245,   245,   245,
     245,   245,     4,   253,   253,   257,   257,   257,   257,   257,
     245,   257,   160,   245,     6,   162,     4,   111,   112,   245,
       6,     6,     6,     7,   161,   254,   256,     6,   253,   253,
     253,   253,   245,   146,   257,   160,   160,   165,     7,   247,
      61,   250,   250,     7,   250,    61,    63,   250,   250,     7,
      63,   250,   250,     6,     7,     7,     7,     7,    76,   237,
       6,     7,   160,   160,   160,   160,     7,     7,     7,     6,
     167,     4,   165,   165,   165,   167,   167,   247,   247,   247,
       4,     6,   166,   159,     6,    99,     6,    99,   167,   236,
     165,   235,     7,     6,     7,     7,     7,     6,   166,     6,
       6,     6,    61,   245,     6,     6,   167,   167,   167,   167,
     167,   167,   245,   167,   250,   250,   250,     4,   165,     8,
       8,   160,     4,     4,   250,   167,     6,     4,     6,   159,
     245,   245,   249,   250,   166,   160,   162,   160,   162,   160,
     162,   160,   162,   162,   160,   162,   160,   165,   160,   160,
     160,   160,   191,     6,   191,     7,   191,   192,   163,     7,
       6,   254,   245,   165,   167,   167,   167,   167,   167,     6,
       6,   173,     6,   245,   166,   245,   258,     6,   166,    69,
     206,   206,   250,     6,   166,   166,     6,     6,   250,   166,
       6,     6,     5,   250,   250,   250,     4,     6,   250,     7,
       7,     7,     7,   250,   250,   250,     7,     6,     7,   245,
     245,   245,   166,   166,   165,   167,   165,   167,   165,   167,
     161,   245,   250,   245,     6,     6,   245,   247,   167,     5,
     166,   250,   166,   166,   166,   250,   253,   166,     6,   160,
     162,     6,     6,   110,   245,   245,   245,     6,     6,     7,
     165,     6,   192,   177,   245,   165,   165,   165,   167,   178,
     245,   163,   257,   250,   250,   258,   245,     6,     4,   255,
       6,   162,   254,     6,     6,     6,     6,   257,   165,   245,
     258,   245,   247,     6,     6,     6,   245,   245,     6,   245,
       5,     6,     6,   114,   205,   245,     6,   250,   250,   250,
     250,     6,     4,     6,     6,   245,   245,   258,   167,   160,
     165,   167,   213,   213,   247,     6,   226,   247,     6,   227,
     247,     6,   228,   245,   167,   165,   160,   167,   165,     6,
     150,   247,     6,   249,   247,   247,     6,   167,   245,   250,
     165,   167,     8,   167,   160,   166,   245,   258,   250,   160,
     165,   245,   245,   250,   166,   165,   167,     4,   160,     6,
       6,     6,     6,     7,     6,   163,     6,   245,   196,   197,
     167,   167,   167,   167,     5,    59,     6,     6,     6,     6,
       6,   166,   166,     6,     6,   166,   245,   167,   167,   165,
     166,   165,   166,   165,   166,   162,     6,   250,     7,   166,
     245,   165,   167,   165,   165,     6,   167,   109,   245,   245,
     253,     6,     6,   167,   181,   245,   165,   165,   249,   245,
       6,   254,   112,   165,   200,   202,     6,     6,     6,     6,
       6,   166,   249,   253,   213,   165,   167,   245,   247,   235,
     245,   247,   235,   245,   247,   235,     6,   165,   167,   250,
     214,   167,   247,     6,   253,   247,   245,   167,   167,   167,
       6,   166,   245,   245,   167,     6,   245,   165,   167,   201,
     165,   167,   203,   245,   167,   167,   167,   245,   167,   165,
     167,   167,   165,   167,   167,   165,   167,   250,     6,    76,
     167,   223,   166,   165,   167,   165,     6,     6,   178,   160,
     165,     6,   166,   165,     4,     4,   167,     6,     6,   167,
       6,   229,   245,     6,     6,   230,   245,     6,     6,   231,
     245,     6,   167,   245,   235,   214,   253,     6,   247,   253,
     167,   184,   245,   249,   245,     5,   166,   250,     5,   166,
     245,   166,   167,   166,   167,   166,   167,     6,     6,   167,
     167,   224,   167,   165,   167,     6,   166,   160,   167,   167,
     199,   245,   259,   235,     6,   232,   235,     6,   233,   235,
       6,   234,   235,     6,   253,     6,   182,   257,   187,   166,
       6,   165,   167,     7,   167,   167,   166,   167,   166,   167,
     166,   167,   167,   165,   167,   166,   249,   245,   258,     6,
     235,     6,   235,     6,   235,     6,   257,     6,   185,   257,
     167,     7,   167,   167,   167,   165,   167,     6,   258,     6,
       6,     6,   257,     6
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
#endif
    ;}
    break;

  case 174:
#line 2207 "Gmsh.y"
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
#line 2228 "Gmsh.y"
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
#line 2249 "Gmsh.y"
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
#line 2269 "Gmsh.y"
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
#line 2381 "Gmsh.y"
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
#line 2400 "Gmsh.y"
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
#line 2439 "Gmsh.y"
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
#line 2547 "Gmsh.y"
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
#line 2556 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 183:
#line 2562 "Gmsh.y"
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
#line 2577 "Gmsh.y"
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
#line 2605 "Gmsh.y"
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
#line 2622 "Gmsh.y"
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
#line 2636 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 188:
#line 2642 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 189:
#line 2648 "Gmsh.y"
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
#line 2657 "Gmsh.y"
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
#line 2671 "Gmsh.y"
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
#line 2716 "Gmsh.y"
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
#line 2733 "Gmsh.y"
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
#line 2748 "Gmsh.y"
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
#line 2767 "Gmsh.y"
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
#line 2779 "Gmsh.y"
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
#line 2803 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 198:
#line 2807 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 199:
#line 2812 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 200:
#line 2819 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 201:
#line 2825 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 202:
#line 2830 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 203:
#line 2836 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 204:
#line 2840 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 205:
#line 2844 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 206:
#line 2849 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    ;}
    break;

  case 207:
#line 2862 "Gmsh.y"
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
#line 2879 "Gmsh.y"
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
#line 2896 "Gmsh.y"
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
#line 2917 "Gmsh.y"
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
#line 2938 "Gmsh.y"
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
#line 2973 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 213:
#line 2981 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 214:
#line 2987 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 215:
#line 2994 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 216:
#line 2998 "Gmsh.y"
    {
    ;}
    break;

  case 217:
#line 3007 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 218:
#line 3015 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 219:
#line 3023 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 220:
#line 3031 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 221:
#line 3036 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 222:
#line 3044 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 223:
#line 3049 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 224:
#line 3057 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 225:
#line 3062 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 226:
#line 3070 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 227:
#line 3075 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 228:
#line 3083 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 229:
#line 3090 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 230:
#line 3097 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 231:
#line 3104 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 232:
#line 3111 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 233:
#line 3118 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 234:
#line 3125 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 235:
#line 3132 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 236:
#line 3139 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 237:
#line 3146 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 238:
#line 3151 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 239:
#line 3158 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 240:
#line 3163 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 241:
#line 3170 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 242:
#line 3175 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 243:
#line 3182 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 244:
#line 3187 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 245:
#line 3194 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 246:
#line 3199 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 247:
#line 3206 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 248:
#line 3211 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 249:
#line 3218 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 250:
#line 3223 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 251:
#line 3230 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 252:
#line 3235 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 253:
#line 3242 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 254:
#line 3247 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 255:
#line 3258 "Gmsh.y"
    {
    ;}
    break;

  case 256:
#line 3261 "Gmsh.y"
    {
    ;}
    break;

  case 257:
#line 3267 "Gmsh.y"
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
#line 3279 "Gmsh.y"
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
#line 3299 "Gmsh.y"
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
#line 3322 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 261:
#line 3326 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 262:
#line 3330 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 263:
#line 3334 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 264:
#line 3338 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 265:
#line 3342 "Gmsh.y"
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
#line 3361 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 267:
#line 3373 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 268:
#line 3377 "Gmsh.y"
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
#line 3392 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 270:
#line 3396 "Gmsh.y"
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
#line 3408 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 272:
#line 3412 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 273:
#line 3417 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 274:
#line 3421 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 275:
#line 3428 "Gmsh.y"
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
#line 3484 "Gmsh.y"
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
#line 3554 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 278:
#line 3559 "Gmsh.y"
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
#line 3626 "Gmsh.y"
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
#line 3662 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 281:
#line 3670 "Gmsh.y"
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
#line 3713 "Gmsh.y"
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
#line 3752 "Gmsh.y"
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
#line 3772 "Gmsh.y"
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
#line 3800 "Gmsh.y"
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
#line 3839 "Gmsh.y"
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
#line 3862 "Gmsh.y"
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
#line 3885 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 289:
#line 3889 "Gmsh.y"
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

  case 290:
#line 3912 "Gmsh.y"
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
#line 3951 "Gmsh.y"
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
#line 3996 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 293:
#line 4000 "Gmsh.y"
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
#line 4010 "Gmsh.y"
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
#line 4044 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 296:
#line 4045 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 297:
#line 4046 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 298:
#line 4051 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 299:
#line 4057 "Gmsh.y"
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
#line 4069 "Gmsh.y"
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
#line 4087 "Gmsh.y"
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
#line 4114 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 303:
#line 4115 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 304:
#line 4116 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 305:
#line 4117 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 306:
#line 4118 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 307:
#line 4119 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 308:
#line 4120 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 309:
#line 4121 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 310:
#line 4123 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 311:
#line 4129 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 312:
#line 4130 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 313:
#line 4131 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 314:
#line 4132 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 315:
#line 4133 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 316:
#line 4134 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 317:
#line 4135 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 318:
#line 4136 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 319:
#line 4137 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 320:
#line 4138 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 321:
#line 4139 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 322:
#line 4140 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 323:
#line 4141 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 324:
#line 4142 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 325:
#line 4143 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 326:
#line 4144 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 327:
#line 4145 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 328:
#line 4146 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 329:
#line 4147 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 330:
#line 4148 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 331:
#line 4149 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 332:
#line 4150 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 333:
#line 4151 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 334:
#line 4152 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 335:
#line 4153 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 336:
#line 4154 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 337:
#line 4155 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 338:
#line 4156 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 339:
#line 4157 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 340:
#line 4158 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 341:
#line 4159 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 342:
#line 4160 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 343:
#line 4163 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 344:
#line 4164 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 345:
#line 4165 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 346:
#line 4166 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 347:
#line 4167 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 348:
#line 4168 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 349:
#line 4169 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 350:
#line 4170 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 351:
#line 4171 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 352:
#line 4172 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 353:
#line 4173 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 354:
#line 4174 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 355:
#line 4175 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 356:
#line 4176 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 357:
#line 4177 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 358:
#line 4178 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 359:
#line 4179 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 360:
#line 4180 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 361:
#line 4181 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 362:
#line 4182 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 363:
#line 4183 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 364:
#line 4192 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 365:
#line 4193 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 366:
#line 4194 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 367:
#line 4195 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 368:
#line 4196 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 369:
#line 4197 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 370:
#line 4198 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 371:
#line 4203 "Gmsh.y"
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
#line 4224 "Gmsh.y"
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
#line 4243 "Gmsh.y"
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
#line 4261 "Gmsh.y"
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
#line 4273 "Gmsh.y"
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
#line 4290 "Gmsh.y"
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
#line 4311 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 378:
#line 4316 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 379:
#line 4321 "Gmsh.y"
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
#line 4331 "Gmsh.y"
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
#line 4341 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 382:
#line 4346 "Gmsh.y"
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
#line 4355 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 384:
#line 4360 "Gmsh.y"
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

  case 385:
#line 4387 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 386:
#line 4391 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 387:
#line 4395 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 388:
#line 4399 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 389:
#line 4403 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 390:
#line 4410 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 391:
#line 4414 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 392:
#line 4418 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 393:
#line 4422 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 394:
#line 4429 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 395:
#line 4434 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 396:
#line 4441 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 397:
#line 4446 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 398:
#line 4450 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 399:
#line 4455 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 400:
#line 4459 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 401:
#line 4467 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 402:
#line 4478 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 403:
#line 4482 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 404:
#line 4494 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 405:
#line 4502 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 406:
#line 4510 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 407:
#line 4517 "Gmsh.y"
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

  case 408:
#line 4527 "Gmsh.y"
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

  case 409:
#line 4547 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 410:
#line 4551 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 411:
#line 4555 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 412:
#line 4559 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 413:
#line 4563 "Gmsh.y"
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

  case 414:
#line 4592 "Gmsh.y"
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

  case 415:
#line 4621 "Gmsh.y"
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

  case 416:
#line 4650 "Gmsh.y"
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

  case 417:
#line 4679 "Gmsh.y"
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
#line 4689 "Gmsh.y"
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
#line 4699 "Gmsh.y"
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
#line 4712 "Gmsh.y"
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
#line 4724 "Gmsh.y"
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

  case 422:
#line 4736 "Gmsh.y"
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
#line 4755 "Gmsh.y"
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
#line 4776 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 425:
#line 4781 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 426:
#line 4785 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 427:
#line 4789 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 428:
#line 4801 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 429:
#line 4805 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 430:
#line 4817 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 431:
#line 4824 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 432:
#line 4834 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 433:
#line 4838 "Gmsh.y"
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

  case 434:
#line 4853 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 435:
#line 4858 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 436:
#line 4865 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 437:
#line 4869 "Gmsh.y"
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

  case 438:
#line 4882 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 439:
#line 4890 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 440:
#line 4901 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 441:
#line 4905 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 442:
#line 4913 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 443:
#line 4921 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 444:
#line 4929 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 445:
#line 4937 "Gmsh.y"
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

  case 446:
#line 4951 "Gmsh.y"
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

  case 447:
#line 4965 "Gmsh.y"
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

  case 448:
#line 4978 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 449:
#line 4983 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 450:
#line 4987 "Gmsh.y"
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
#line 5007 "Gmsh.y"
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
#line 5029 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 453:
#line 5034 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 10269 "Gmsh.tab.cpp"
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


#line 5037 "Gmsh.y"


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

