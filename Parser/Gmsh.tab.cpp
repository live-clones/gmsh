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
     tCpu = 308,
     tMemory = 309,
     tSyncModel = 310,
     tCreateTopology = 311,
     tCreateTopologyNoHoles = 312,
     tDistanceFunction = 313,
     tDefineConstant = 314,
     tUndefineConstant = 315,
     tPoint = 316,
     tCircle = 317,
     tEllipse = 318,
     tLine = 319,
     tSphere = 320,
     tPolarSphere = 321,
     tSurface = 322,
     tSpline = 323,
     tVolume = 324,
     tCharacteristic = 325,
     tLength = 326,
     tParametric = 327,
     tElliptic = 328,
     tRefineMesh = 329,
     tAdaptMesh = 330,
     tRelocateMesh = 331,
     tPlane = 332,
     tRuled = 333,
     tTransfinite = 334,
     tComplex = 335,
     tPhysical = 336,
     tCompound = 337,
     tPeriodic = 338,
     tUsing = 339,
     tPlugin = 340,
     tDegenerated = 341,
     tRecursive = 342,
     tRotate = 343,
     tTranslate = 344,
     tSymmetry = 345,
     tDilate = 346,
     tExtrude = 347,
     tLevelset = 348,
     tRecombine = 349,
     tSmoother = 350,
     tSplit = 351,
     tDelete = 352,
     tCoherence = 353,
     tIntersect = 354,
     tMeshAlgorithm = 355,
     tReverse = 356,
     tLayers = 357,
     tScaleLast = 358,
     tHole = 359,
     tAlias = 360,
     tAliasWithOptions = 361,
     tCopyOptions = 362,
     tQuadTriAddVerts = 363,
     tQuadTriNoNewVerts = 364,
     tQuadTriSngl = 365,
     tQuadTriDbl = 366,
     tRecombLaterals = 367,
     tTransfQuadTri = 368,
     tText2D = 369,
     tText3D = 370,
     tInterpolationScheme = 371,
     tTime = 372,
     tCombine = 373,
     tBSpline = 374,
     tBezier = 375,
     tNurbs = 376,
     tNurbsOrder = 377,
     tNurbsKnots = 378,
     tColor = 379,
     tColorTable = 380,
     tFor = 381,
     tIn = 382,
     tEndFor = 383,
     tIf = 384,
     tEndIf = 385,
     tExit = 386,
     tAbort = 387,
     tField = 388,
     tReturn = 389,
     tCall = 390,
     tFunction = 391,
     tShow = 392,
     tHide = 393,
     tGetValue = 394,
     tGetEnv = 395,
     tGetString = 396,
     tHomology = 397,
     tCohomology = 398,
     tBetti = 399,
     tSetOrder = 400,
     tGMSH_MAJOR_VERSION = 401,
     tGMSH_MINOR_VERSION = 402,
     tGMSH_PATCH_VERSION = 403,
     tAFFECTDIVIDE = 404,
     tAFFECTTIMES = 405,
     tAFFECTMINUS = 406,
     tAFFECTPLUS = 407,
     tOR = 408,
     tAND = 409,
     tNOTEQUAL = 410,
     tEQUAL = 411,
     tGREATEROREQUAL = 412,
     tLESSOREQUAL = 413,
     UNARYPREC = 414,
     tMINUSMINUS = 415,
     tPLUSPLUS = 416
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
#define tCpu 308
#define tMemory 309
#define tSyncModel 310
#define tCreateTopology 311
#define tCreateTopologyNoHoles 312
#define tDistanceFunction 313
#define tDefineConstant 314
#define tUndefineConstant 315
#define tPoint 316
#define tCircle 317
#define tEllipse 318
#define tLine 319
#define tSphere 320
#define tPolarSphere 321
#define tSurface 322
#define tSpline 323
#define tVolume 324
#define tCharacteristic 325
#define tLength 326
#define tParametric 327
#define tElliptic 328
#define tRefineMesh 329
#define tAdaptMesh 330
#define tRelocateMesh 331
#define tPlane 332
#define tRuled 333
#define tTransfinite 334
#define tComplex 335
#define tPhysical 336
#define tCompound 337
#define tPeriodic 338
#define tUsing 339
#define tPlugin 340
#define tDegenerated 341
#define tRecursive 342
#define tRotate 343
#define tTranslate 344
#define tSymmetry 345
#define tDilate 346
#define tExtrude 347
#define tLevelset 348
#define tRecombine 349
#define tSmoother 350
#define tSplit 351
#define tDelete 352
#define tCoherence 353
#define tIntersect 354
#define tMeshAlgorithm 355
#define tReverse 356
#define tLayers 357
#define tScaleLast 358
#define tHole 359
#define tAlias 360
#define tAliasWithOptions 361
#define tCopyOptions 362
#define tQuadTriAddVerts 363
#define tQuadTriNoNewVerts 364
#define tQuadTriSngl 365
#define tQuadTriDbl 366
#define tRecombLaterals 367
#define tTransfQuadTri 368
#define tText2D 369
#define tText3D 370
#define tInterpolationScheme 371
#define tTime 372
#define tCombine 373
#define tBSpline 374
#define tBezier 375
#define tNurbs 376
#define tNurbsOrder 377
#define tNurbsKnots 378
#define tColor 379
#define tColorTable 380
#define tFor 381
#define tIn 382
#define tEndFor 383
#define tIf 384
#define tEndIf 385
#define tExit 386
#define tAbort 387
#define tField 388
#define tReturn 389
#define tCall 390
#define tFunction 391
#define tShow 392
#define tHide 393
#define tGetValue 394
#define tGetEnv 395
#define tGetString 396
#define tHomology 397
#define tCohomology 398
#define tBetti 399
#define tSetOrder 400
#define tGMSH_MAJOR_VERSION 401
#define tGMSH_MINOR_VERSION 402
#define tGMSH_PATCH_VERSION 403
#define tAFFECTDIVIDE 404
#define tAFFECTTIMES 405
#define tAFFECTMINUS 406
#define tAFFECTPLUS 407
#define tOR 408
#define tAND 409
#define tNOTEQUAL 410
#define tEQUAL 411
#define tGREATEROREQUAL 412
#define tLESSOREQUAL 413
#define UNARYPREC 414
#define tMINUSMINUS 415
#define tPLUSPLUS 416




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
#line 528 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 541 "Gmsh.tab.cpp"

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
#define YYLAST   8679

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  182
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  479
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1665

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   416

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   167,     2,   177,     2,   166,     2,     2,
     172,   173,   164,   162,   178,   163,   176,   165,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     158,     2,   159,   153,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   174,     2,   175,   171,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   179,     2,   180,   181,     2,     2,     2,
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
     145,   146,   147,   148,   149,   150,   151,   152,   154,   155,
     156,   157,   160,   161,   168,   169,   170
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
    2273,  2275,  2280,  2285,  2288,  2294,  2298,  2305,  2310,  2318,
    2325,  2332,  2339,  2344,  2346,  2349,  2352,  2356,  2360,  2372,
    2382,  2390,  2398,  2400,  2404,  2406,  2408,  2411,  2415,  2420,
    2426,  2428,  2430,  2433,  2437,  2441,  2447,  2452,  2455,  2458,
    2461,  2464,  2470,  2476,  2482,  2488,  2490,  2492,  2496,  2500,
    2505,  2512,  2519,  2521,  2523,  2527,  2531,  2541,  2549,  2551,
    2557,  2561,  2568,  2570,  2574,  2576,  2578,  2582,  2589,  2591,
    2593,  2595,  2600,  2607,  2614,  2621,  2626,  2631,  2640,  2645,
    2650,  2655,  2660,  2667,  2674,  2676,  2680,  2686,  2692,  2694
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     183,     0,    -1,   184,    -1,     1,     6,    -1,    -1,   184,
     185,    -1,   188,    -1,   187,    -1,   206,    -1,   220,    -1,
     225,    -1,   229,    -1,   230,    -1,   231,    -1,   234,    -1,
     254,    -1,   255,    -1,   233,    -1,   232,    -1,   228,    -1,
     257,    -1,   159,    -1,   159,   159,    -1,    37,   172,   270,
     173,     6,    -1,    38,   172,   270,   173,     6,    -1,    37,
     172,   270,   173,   186,   270,     6,    -1,    37,   172,   270,
     178,   266,   173,     6,    -1,    38,   172,   270,   178,   266,
     173,     6,    -1,    37,   172,   270,   178,   266,   173,   186,
     270,     6,    -1,     4,   270,   179,   189,   180,     6,    -1,
     105,     4,   174,   258,   175,     6,    -1,   106,     4,   174,
     258,   175,     6,    -1,   107,     4,   174,   258,   178,   258,
     175,     6,    -1,    -1,   189,   192,    -1,   189,   196,    -1,
     189,   199,    -1,   189,   201,    -1,   189,   202,    -1,   258,
      -1,   190,   178,   258,    -1,   258,    -1,   191,   178,   258,
      -1,    -1,    -1,     4,   193,   172,   190,   173,   194,   179,
     191,   180,     6,    -1,   270,    -1,   195,   178,   270,    -1,
      -1,   114,   172,   258,   178,   258,   178,   258,   173,   197,
     179,   195,   180,     6,    -1,   270,    -1,   198,   178,   270,
      -1,    -1,   115,   172,   258,   178,   258,   178,   258,   178,
     258,   173,   200,   179,   198,   180,     6,    -1,   116,   179,
     262,   180,   179,   262,   180,     6,    -1,   116,   179,   262,
     180,   179,   262,   180,   179,   262,   180,   179,   262,   180,
       6,    -1,    -1,   117,   203,   179,   191,   180,     6,    -1,
       7,    -1,   152,    -1,   151,    -1,   150,    -1,   149,    -1,
     170,    -1,   169,    -1,    59,   174,   208,   175,     6,    -1,
      60,   174,   211,   175,     6,    -1,   274,   204,   263,     6,
      -1,     4,   174,   175,   204,   263,     6,    -1,     4,   174,
     258,   175,   204,   258,     6,    -1,     4,   172,   258,   173,
     204,   258,     6,    -1,     4,   174,   179,   266,   180,   175,
     204,   263,     6,    -1,     4,   172,   179,   266,   180,   173,
     204,   263,     6,    -1,   274,   205,     6,    -1,     4,   174,
     258,   175,   205,     6,    -1,   274,     7,   271,     6,    -1,
       4,   176,     4,     7,   271,     6,    -1,     4,   174,   258,
     175,   176,     4,     7,   271,     6,    -1,     4,   176,     4,
     204,   258,     6,    -1,     4,   174,   258,   175,   176,     4,
     204,   258,     6,    -1,     4,   176,     4,   205,     6,    -1,
       4,   174,   258,   175,   176,     4,   205,     6,    -1,     4,
     176,   124,   176,     4,     7,   267,     6,    -1,     4,   174,
     258,   175,   176,   124,   176,     4,     7,   267,     6,    -1,
       4,   176,   125,     7,   268,     6,    -1,     4,   174,   258,
     175,   176,   125,     7,   268,     6,    -1,     4,   133,     7,
     258,     6,    -1,   133,   174,   258,   175,     7,     4,     6,
      -1,   133,   174,   258,   175,   176,     4,     7,   258,     6,
      -1,   133,   174,   258,   175,   176,     4,     7,   271,     6,
      -1,   133,   174,   258,   175,   176,     4,     7,   179,   266,
     180,     6,    -1,   133,   174,   258,   175,   176,     4,     6,
      -1,    85,   172,     4,   173,   176,     4,     7,   258,     6,
      -1,    85,   172,     4,   173,   176,     4,     7,   271,     6,
      -1,    -1,   178,    -1,    -1,   208,   207,   274,    -1,   208,
     207,   274,     7,   258,    -1,    -1,   208,   207,   274,     7,
     179,   258,   209,   213,   180,    -1,   208,   207,   274,     7,
     271,    -1,    -1,   208,   207,   274,     7,   179,   271,   210,
     215,   180,    -1,    -1,   211,   207,   270,    -1,   258,     7,
     271,    -1,   212,   178,   258,     7,   271,    -1,    -1,   213,
     214,    -1,   178,     4,   263,    -1,   178,     4,   179,   212,
     180,    -1,   178,     4,   271,    -1,    -1,   215,   216,    -1,
     178,     4,   258,    -1,   178,     4,   271,    -1,   178,     4,
     179,   272,   180,    -1,   258,    -1,   271,    -1,    -1,   127,
      65,   179,   258,   180,    -1,    -1,    77,   260,    -1,    61,
     172,   258,   173,     7,   260,     6,    -1,    -1,    81,    61,
     221,   172,   217,   173,     7,   263,     6,    -1,    70,    71,
     263,     7,   258,     6,    -1,    64,   172,   258,   173,     7,
     263,     6,    -1,    86,    64,   263,     6,    -1,    68,   172,
     258,   173,     7,   263,     6,    -1,    62,   172,   258,   173,
       7,   263,   219,     6,    -1,    63,   172,   258,   173,     7,
     263,   219,     6,    -1,   119,   172,   258,   173,     7,   263,
       6,    -1,   120,   172,   258,   173,     7,   263,     6,    -1,
     121,   172,   258,   173,     7,   263,   123,   263,   122,   258,
       6,    -1,    64,     4,   172,   258,   173,     7,   263,     6,
      -1,    82,    64,   172,   258,   173,     7,   263,     6,    -1,
      -1,    81,    64,   222,   172,   217,   173,     7,   263,     6,
      -1,    77,    67,   172,   258,   173,     7,   263,     6,    -1,
      78,    67,   172,   258,   173,     7,   263,   218,     6,    -1,
      12,    13,     6,    -1,    13,    67,   258,     6,    -1,    72,
      67,   172,   258,   173,     7,     5,     5,     5,     6,    -1,
      65,   172,   258,   173,     7,   263,     6,    -1,    66,   172,
     258,   173,     7,   263,     6,    -1,    67,     4,   172,   258,
     173,     7,   263,     6,    -1,    82,    67,   172,   258,   173,
       7,   263,     6,    -1,    82,    67,   172,   258,   173,     7,
     263,     4,   179,   262,   180,     6,    -1,    -1,    81,    67,
     223,   172,   217,   173,     7,   263,     6,    -1,    80,    69,
     172,   258,   173,     7,   263,     6,    -1,    69,   172,   258,
     173,     7,   263,     6,    -1,    82,    69,   172,   258,   173,
       7,   263,     6,    -1,    -1,    81,    69,   224,   172,   217,
     173,     7,   263,     6,    -1,    89,   260,   179,   226,   180,
      -1,    88,   179,   260,   178,   260,   178,   258,   180,   179,
     226,   180,    -1,    90,   260,   179,   226,   180,    -1,    91,
     179,   260,   178,   258,   180,   179,   226,   180,    -1,    91,
     179,   260,   178,   260,   180,   179,   226,   180,    -1,     4,
     179,   226,   180,    -1,    99,    64,   179,   266,   180,    67,
     179,   258,   180,    -1,    96,    64,   172,   258,   173,   179,
     266,   180,     6,    -1,   227,    -1,   225,    -1,    -1,   227,
     220,    -1,   227,    61,   179,   266,   180,     6,    -1,   227,
      64,   179,   266,   180,     6,    -1,   227,    67,   179,   266,
     180,     6,    -1,   227,    69,   179,   266,   180,     6,    -1,
      93,    77,   172,   258,   173,     7,   263,     6,    -1,    93,
      61,   172,   258,   173,     7,   179,   262,   180,     6,    -1,
      93,    77,   172,   258,   173,     7,   179,   260,   178,   260,
     178,   266,   180,     6,    -1,    93,    77,   172,   258,   173,
       7,   179,   260,   178,   260,   178,   260,   178,   266,   180,
       6,    -1,    93,    65,   172,   258,   173,     7,   179,   260,
     178,   266,   180,     6,    -1,    93,     4,   172,   258,   173,
       7,   263,     6,    -1,    93,     4,   172,   258,   173,     7,
       5,     6,    -1,    93,     4,   179,   258,   180,     6,    -1,
      93,     4,   172,   258,   173,     7,   179,   260,   178,   260,
     178,   266,   180,     6,    -1,    97,   179,   227,   180,    -1,
      97,   133,   174,   258,   175,     6,    -1,    97,     4,   174,
     258,   175,     6,    -1,    97,     4,     6,    -1,    97,     4,
       4,     6,    -1,   124,   267,   179,   227,   180,    -1,    87,
     124,   267,   179,   227,   180,    -1,   137,     5,     6,    -1,
     138,     5,     6,    -1,   137,   179,   227,   180,    -1,    87,
     137,   179,   227,   180,    -1,   138,   179,   227,   180,    -1,
      87,   138,   179,   227,   180,    -1,     4,   271,     6,    -1,
       4,     4,   174,   258,   175,   270,     6,    -1,     4,     4,
       4,   174,   258,   175,     6,    -1,     4,   258,     6,    -1,
      85,   172,     4,   173,   176,     4,     6,    -1,   118,     4,
       6,    -1,   131,     6,    -1,   132,     6,    -1,    55,     6,
      -1,    48,     6,    -1,    48,   179,   258,   178,   258,   178,
     258,   178,   258,   178,   258,   178,   258,   180,     6,    -1,
      49,     6,    -1,    50,     6,    -1,    56,     6,    -1,    57,
       6,    -1,    74,     6,    -1,    75,   179,   266,   180,   179,
     266,   180,   179,   262,   180,   179,   258,   178,   258,   180,
       6,    -1,   145,   258,     6,    -1,   126,   172,   258,     8,
     258,   173,    -1,   126,   172,   258,     8,   258,     8,   258,
     173,    -1,   126,     4,   127,   179,   258,     8,   258,   180,
      -1,   126,     4,   127,   179,   258,     8,   258,     8,   258,
     180,    -1,   128,    -1,   136,     4,    -1,   134,    -1,   135,
       4,     6,    -1,   129,   172,   258,   173,    -1,   130,    -1,
      92,   260,   179,   227,   180,    -1,    92,   179,   260,   178,
     260,   178,   258,   180,   179,   227,   180,    -1,    92,   179,
     260,   178,   260,   178,   260,   178,   258,   180,   179,   227,
     180,    -1,    -1,    92,   260,   179,   227,   235,   248,   180,
      -1,    -1,    92,   179,   260,   178,   260,   178,   258,   180,
     179,   227,   236,   248,   180,    -1,    -1,    92,   179,   260,
     178,   260,   178,   260,   178,   258,   180,   179,   227,   237,
     248,   180,    -1,    -1,    92,   179,   227,   238,   248,   180,
      -1,    92,    61,   179,   258,   178,   260,   180,     6,    -1,
      92,    64,   179,   258,   178,   260,   180,     6,    -1,    92,
      67,   179,   258,   178,   260,   180,     6,    -1,    92,    61,
     179,   258,   178,   260,   178,   260,   178,   258,   180,     6,
      -1,    92,    64,   179,   258,   178,   260,   178,   260,   178,
     258,   180,     6,    -1,    92,    67,   179,   258,   178,   260,
     178,   260,   178,   258,   180,     6,    -1,    92,    61,   179,
     258,   178,   260,   178,   260,   178,   260,   178,   258,   180,
       6,    -1,    92,    64,   179,   258,   178,   260,   178,   260,
     178,   260,   178,   258,   180,     6,    -1,    92,    67,   179,
     258,   178,   260,   178,   260,   178,   260,   178,   258,   180,
       6,    -1,    -1,    92,    61,   179,   258,   178,   260,   180,
     239,   179,   248,   180,     6,    -1,    -1,    92,    64,   179,
     258,   178,   260,   180,   240,   179,   248,   180,     6,    -1,
      -1,    92,    67,   179,   258,   178,   260,   180,   241,   179,
     248,   180,     6,    -1,    -1,    92,    61,   179,   258,   178,
     260,   178,   260,   178,   258,   180,   242,   179,   248,   180,
       6,    -1,    -1,    92,    64,   179,   258,   178,   260,   178,
     260,   178,   258,   180,   243,   179,   248,   180,     6,    -1,
      -1,    92,    67,   179,   258,   178,   260,   178,   260,   178,
     258,   180,   244,   179,   248,   180,     6,    -1,    -1,    92,
      61,   179,   258,   178,   260,   178,   260,   178,   260,   178,
     258,   180,   245,   179,   248,   180,     6,    -1,    -1,    92,
      64,   179,   258,   178,   260,   178,   260,   178,   260,   178,
     258,   180,   246,   179,   248,   180,     6,    -1,    -1,    92,
      67,   179,   258,   178,   260,   178,   260,   178,   260,   178,
     258,   180,   247,   179,   248,   180,     6,    -1,   249,    -1,
     248,   249,    -1,   102,   179,   258,   180,     6,    -1,   102,
     179,   263,   178,   263,   180,     6,    -1,   102,   179,   263,
     178,   263,   178,   263,   180,     6,    -1,   103,     6,    -1,
      94,     6,    -1,   110,     6,    -1,   110,   112,     6,    -1,
     111,     6,    -1,   111,   112,     6,    -1,   108,     6,    -1,
     108,   112,     6,    -1,   109,     6,    -1,   109,   112,     6,
      -1,   104,   172,   258,   173,     7,   263,    84,   258,     6,
      -1,    84,     4,   174,   258,   175,     6,    -1,    -1,    84,
       4,   258,    -1,    -1,     4,    -1,    -1,     7,   263,    -1,
      -1,     7,   258,    -1,    79,    64,   264,     7,   258,   250,
       6,    -1,    79,    67,   264,   252,   251,     6,    -1,    73,
      67,   179,   258,   180,     7,   263,     6,    -1,    79,    69,
     264,   252,     6,    -1,   113,   264,     6,    -1,   100,    67,
     179,   266,   180,   258,     6,    -1,    94,    67,   264,   253,
       6,    -1,    94,    69,   264,     6,    -1,    95,    67,   263,
       7,   258,     6,    -1,    83,    64,   263,     7,   263,     6,
      -1,    83,    67,   258,   179,   266,   180,     7,   258,   179,
     266,   180,     6,    -1,    61,   179,   266,   180,   127,    67,
     179,   258,   180,     6,    -1,    64,   179,   266,   180,   127,
      67,   179,   258,   180,     6,    -1,    61,   179,   266,   180,
     127,    69,   179,   258,   180,     6,    -1,    64,   179,   266,
     180,   127,    69,   179,   258,   180,     6,    -1,    67,   179,
     266,   180,   127,    69,   179,   258,   180,     6,    -1,   101,
      67,   264,     6,    -1,   101,    64,   264,     6,    -1,    76,
      61,   264,     6,    -1,    76,    64,   264,     6,    -1,    76,
      67,   264,     6,    -1,    98,     6,    -1,    98,     4,     6,
      -1,    98,    61,   179,   266,   180,     6,    -1,   142,    -1,
     143,    -1,   144,    -1,   256,     6,    -1,   256,   179,   263,
     180,     6,    -1,   256,   179,   263,   178,   263,   180,     6,
      -1,   256,   172,   263,   173,   179,   263,   178,   263,   180,
       6,    -1,   259,    -1,   172,   258,   173,    -1,   163,   258,
      -1,   162,   258,    -1,   167,   258,    -1,   258,   163,   258,
      -1,   258,   162,   258,    -1,   258,   164,   258,    -1,   258,
     165,   258,    -1,   258,   166,   258,    -1,   258,   171,   258,
      -1,   258,   158,   258,    -1,   258,   159,   258,    -1,   258,
     161,   258,    -1,   258,   160,   258,    -1,   258,   157,   258,
      -1,   258,   156,   258,    -1,   258,   155,   258,    -1,   258,
     154,   258,    -1,   258,   153,   258,     8,   258,    -1,    14,
     172,   258,   173,    -1,    15,   172,   258,   173,    -1,    16,
     172,   258,   173,    -1,    17,   172,   258,   173,    -1,    18,
     172,   258,   173,    -1,    19,   172,   258,   173,    -1,    20,
     172,   258,   173,    -1,    21,   172,   258,   173,    -1,    22,
     172,   258,   173,    -1,    24,   172,   258,   173,    -1,    25,
     172,   258,   178,   258,   173,    -1,    26,   172,   258,   173,
      -1,    27,   172,   258,   173,    -1,    28,   172,   258,   173,
      -1,    29,   172,   258,   173,    -1,    30,   172,   258,   173,
      -1,    31,   172,   258,   173,    -1,    32,   172,   258,   173,
      -1,    33,   172,   258,   178,   258,   173,    -1,    34,   172,
     258,   178,   258,   173,    -1,    35,   172,   258,   178,   258,
     173,    -1,    23,   172,   258,   173,    -1,    14,   174,   258,
     175,    -1,    15,   174,   258,   175,    -1,    16,   174,   258,
     175,    -1,    17,   174,   258,   175,    -1,    18,   174,   258,
     175,    -1,    19,   174,   258,   175,    -1,    20,   174,   258,
     175,    -1,    21,   174,   258,   175,    -1,    22,   174,   258,
     175,    -1,    24,   174,   258,   175,    -1,    25,   174,   258,
     178,   258,   175,    -1,    26,   174,   258,   175,    -1,    27,
     174,   258,   175,    -1,    28,   174,   258,   175,    -1,    29,
     174,   258,   175,    -1,    30,   174,   258,   175,    -1,    31,
     174,   258,   175,    -1,    32,   174,   258,   175,    -1,    33,
     174,   258,   178,   258,   175,    -1,    34,   174,   258,   178,
     258,   175,    -1,    35,   174,   258,   178,   258,   175,    -1,
      23,   174,   258,   175,    -1,     3,    -1,     9,    -1,    10,
      -1,    11,    -1,   146,    -1,   147,    -1,   148,    -1,    53,
      -1,    54,    -1,   274,    -1,     4,   174,   258,   175,    -1,
     177,     4,   174,   175,    -1,   274,   205,    -1,     4,   174,
     258,   175,   205,    -1,     4,   176,     4,    -1,     4,   174,
     258,   175,   176,     4,    -1,     4,   176,     4,   205,    -1,
       4,   174,   258,   175,   176,     4,   205,    -1,   139,   172,
     270,   178,   258,   173,    -1,    45,   172,   270,   178,   270,
     173,    -1,    46,   172,   270,   178,   270,   173,    -1,    47,
     172,   272,   173,    -1,   261,    -1,   163,   260,    -1,   162,
     260,    -1,   260,   163,   260,    -1,   260,   162,   260,    -1,
     179,   258,   178,   258,   178,   258,   178,   258,   178,   258,
     180,    -1,   179,   258,   178,   258,   178,   258,   178,   258,
     180,    -1,   179,   258,   178,   258,   178,   258,   180,    -1,
     172,   258,   178,   258,   178,   258,   173,    -1,   263,    -1,
     262,   178,   263,    -1,   258,    -1,   265,    -1,   179,   180,
      -1,   179,   266,   180,    -1,   163,   179,   266,   180,    -1,
     258,   164,   179,   266,   180,    -1,   263,    -1,     5,    -1,
     163,   265,    -1,   258,   164,   265,    -1,   258,     8,   258,
      -1,   258,     8,   258,     8,   258,    -1,    61,   179,   258,
     180,    -1,    61,     5,    -1,    64,     5,    -1,    67,     5,
      -1,    69,     5,    -1,    81,    61,   179,   266,   180,    -1,
      81,    64,   179,   266,   180,    -1,    81,    67,   179,   266,
     180,    -1,    81,    69,   179,   266,   180,    -1,   225,    -1,
     234,    -1,     4,   174,   175,    -1,     4,   172,   173,    -1,
      36,   174,     4,   175,    -1,     4,   174,   179,   266,   180,
     175,    -1,     4,   172,   179,   266,   180,   173,    -1,   258,
      -1,   265,    -1,   266,   178,   258,    -1,   266,   178,   265,
      -1,   179,   258,   178,   258,   178,   258,   178,   258,   180,
      -1,   179,   258,   178,   258,   178,   258,   180,    -1,     4,
      -1,     4,   176,   124,   176,     4,    -1,   179,   269,   180,
      -1,     4,   174,   258,   175,   176,   125,    -1,   267,    -1,
     269,   178,   267,    -1,   271,    -1,   274,    -1,     4,   176,
       4,    -1,     4,   174,   258,   175,   176,     4,    -1,     5,
      -1,    51,    -1,    52,    -1,   140,   172,   270,   173,    -1,
     141,   172,   270,   178,   270,   173,    -1,    41,   172,   270,
     178,   270,   173,    -1,    41,   174,   270,   178,   270,   175,
      -1,    42,   172,   270,   173,    -1,    43,   172,   270,   173,
      -1,    44,   172,   270,   178,   270,   178,   270,   173,    -1,
      39,   172,   272,   173,    -1,    39,   174,   272,   175,    -1,
      40,   172,   270,   173,    -1,    40,   174,   270,   175,    -1,
      40,   172,   270,   178,   266,   173,    -1,    40,   174,   270,
     178,   266,   175,    -1,   270,    -1,   272,   178,   270,    -1,
       4,   181,   179,   258,   180,    -1,   273,   181,   179,   258,
     180,    -1,     4,    -1,   273,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   172,   172,   173,   178,   180,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   202,   206,   213,   218,   223,   237,   250,   263,   291,
     305,   318,   331,   350,   355,   356,   357,   358,   359,   363,
     365,   370,   372,   378,   482,   377,   500,   507,   518,   517,
     535,   542,   553,   552,   569,   586,   609,   608,   622,   623,
     624,   625,   626,   630,   631,   637,   639,   641,   703,   733,
     768,   802,   850,   897,   912,   928,   937,   943,   952,   970,
     988,   997,  1009,  1014,  1022,  1042,  1065,  1076,  1084,  1106,
    1129,  1155,  1176,  1188,  1202,  1202,  1204,  1206,  1215,  1225,
    1224,  1236,  1246,  1245,  1259,  1261,  1269,  1275,  1282,  1283,
    1287,  1298,  1313,  1323,  1324,  1329,  1337,  1346,  1364,  1368,
    1379,  1382,  1395,  1398,  1408,  1432,  1431,  1451,  1473,  1491,
    1512,  1530,  1560,  1590,  1608,  1626,  1652,  1670,  1689,  1688,
    1711,  1729,  1768,  1774,  1780,  1787,  1812,  1837,  1854,  1873,
    1908,  1907,  1931,  1949,  1966,  1983,  1982,  2008,  2013,  2018,
    2023,  2028,  2033,  2056,  2062,  2073,  2074,  2079,  2082,  2086,
    2109,  2132,  2155,  2183,  2204,  2230,  2251,  2273,  2293,  2405,
    2424,  2462,  2571,  2580,  2586,  2601,  2629,  2646,  2655,  2669,
    2675,  2681,  2690,  2699,  2708,  2722,  2775,  2792,  2807,  2826,
    2838,  2862,  2866,  2871,  2878,  2884,  2889,  2895,  2903,  2907,
    2911,  2916,  2971,  2984,  3001,  3018,  3039,  3060,  3095,  3103,
    3109,  3116,  3120,  3129,  3137,  3145,  3154,  3153,  3168,  3167,
    3182,  3181,  3196,  3195,  3209,  3216,  3223,  3230,  3237,  3244,
    3251,  3258,  3265,  3273,  3272,  3286,  3285,  3299,  3298,  3312,
    3311,  3325,  3324,  3338,  3337,  3351,  3350,  3364,  3363,  3377,
    3376,  3393,  3396,  3402,  3414,  3434,  3458,  3463,  3467,  3471,
    3475,  3479,  3483,  3487,  3491,  3495,  3499,  3518,  3531,  3534,
    3550,  3553,  3570,  3573,  3579,  3582,  3589,  3645,  3715,  3720,
    3787,  3823,  3831,  3874,  3913,  3933,  3960,  4000,  4023,  4046,
    4050,  4054,  4077,  4116,  4155,  4176,  4197,  4224,  4228,  4238,
    4273,  4274,  4275,  4279,  4285,  4297,  4315,  4343,  4344,  4345,
    4346,  4347,  4348,  4349,  4350,  4351,  4358,  4359,  4360,  4361,
    4362,  4363,  4364,  4365,  4366,  4367,  4368,  4369,  4370,  4371,
    4372,  4373,  4374,  4375,  4376,  4377,  4378,  4379,  4380,  4381,
    4382,  4383,  4384,  4385,  4386,  4387,  4388,  4389,  4390,  4393,
    4394,  4395,  4396,  4397,  4398,  4399,  4400,  4401,  4402,  4403,
    4404,  4405,  4406,  4407,  4408,  4409,  4410,  4411,  4412,  4413,
    4414,  4423,  4424,  4425,  4426,  4427,  4428,  4429,  4430,  4431,
    4435,  4453,  4471,  4483,  4500,  4521,  4526,  4531,  4541,  4551,
    4556,  4565,  4570,  4597,  4601,  4605,  4609,  4613,  4620,  4624,
    4628,  4632,  4639,  4644,  4651,  4656,  4660,  4665,  4669,  4677,
    4688,  4692,  4704,  4712,  4720,  4727,  4737,  4757,  4761,  4765,
    4769,  4773,  4802,  4831,  4860,  4889,  4899,  4909,  4922,  4934,
    4946,  4965,  4986,  4991,  4995,  4999,  5011,  5015,  5027,  5034,
    5044,  5048,  5063,  5068,  5075,  5079,  5092,  5100,  5111,  5115,
    5123,  5129,  5137,  5145,  5154,  5162,  5176,  5190,  5202,  5219,
    5235,  5240,  5244,  5264,  5286,  5291,  5297,  5306,  5319,  5322
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
  "tOnelabAction", "tCpu", "tMemory", "tSyncModel", "tCreateTopology",
  "tCreateTopologyNoHoles", "tDistanceFunction", "tDefineConstant",
  "tUndefineConstant", "tPoint", "tCircle", "tEllipse", "tLine", "tSphere",
  "tPolarSphere", "tSurface", "tSpline", "tVolume", "tCharacteristic",
  "tLength", "tParametric", "tElliptic", "tRefineMesh", "tAdaptMesh",
  "tRelocateMesh", "tPlane", "tRuled", "tTransfinite", "tComplex",
  "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
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
     405,   406,   407,    63,   408,   409,   410,   411,    60,    62,
     412,   413,    43,    45,    42,    47,    37,    33,   414,   415,
     416,    94,    40,    41,    91,    93,    46,    35,    44,   123,
     125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   182,   183,   183,   184,   184,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   186,   186,   187,   187,   187,   187,   187,   187,   188,
     188,   188,   188,   189,   189,   189,   189,   189,   189,   190,
     190,   191,   191,   193,   194,   192,   195,   195,   197,   196,
     198,   198,   200,   199,   201,   201,   203,   202,   204,   204,
     204,   204,   204,   205,   205,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   207,   207,   208,   208,   208,   209,
     208,   208,   210,   208,   211,   211,   212,   212,   213,   213,
     214,   214,   214,   215,   215,   216,   216,   216,   217,   217,
     218,   218,   219,   219,   220,   221,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   222,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     223,   220,   220,   220,   220,   224,   220,   225,   225,   225,
     225,   225,   225,   225,   225,   226,   226,   227,   227,   227,
     227,   227,   227,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   229,   229,   229,   229,   229,   230,   230,   231,
     231,   231,   231,   231,   231,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   234,   234,   234,   235,   234,   236,   234,
     237,   234,   238,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   239,   234,   240,   234,   241,   234,   242,
     234,   243,   234,   244,   234,   245,   234,   246,   234,   247,
     234,   248,   248,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   250,   250,
     251,   251,   252,   252,   253,   253,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   255,   255,   255,
     256,   256,   256,   257,   257,   257,   257,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   260,   260,   260,   260,   260,   261,   261,
     261,   261,   262,   262,   263,   263,   263,   263,   263,   263,
     264,   264,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   266,   266,   266,   266,   267,   267,   267,   267,
     268,   268,   269,   269,   270,   270,   270,   270,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   272,   272,   273,   273,   274,   274
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
       1,     4,     4,     2,     5,     3,     6,     4,     7,     6,
       6,     6,     4,     1,     2,     2,     3,     3,    11,     9,
       7,     7,     1,     3,     1,     1,     2,     3,     4,     5,
       1,     1,     2,     3,     3,     5,     4,     2,     2,     2,
       2,     5,     5,     5,     5,     1,     1,     3,     3,     4,
       6,     6,     1,     1,     3,     3,     9,     7,     1,     5,
       3,     6,     1,     3,     1,     1,     3,     6,     1,     1,
       1,     4,     6,     6,     6,     4,     4,     8,     4,     4,
       4,     4,     6,     6,     1,     3,     5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   478,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   217,     0,
     222,     0,     0,     0,   219,     0,     0,     0,     0,   310,
     311,   312,     0,     5,     7,     6,     8,     9,    10,    19,
      11,    12,    13,    18,    17,    14,    15,    16,     0,    20,
     479,     0,   381,   478,   458,   382,   383,   384,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   459,
     460,   388,   389,     0,     0,     0,     0,   385,   386,   387,
       0,     0,     0,     0,     0,     0,     0,   167,     0,     0,
     317,     0,   454,   390,     0,     0,     0,     0,   204,     0,
     206,   207,   203,   208,   209,    96,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   210,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,   138,   150,   155,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   403,     0,     0,     0,     0,     0,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,     0,   307,     0,     0,     0,     0,     0,
       0,     0,     0,   478,   421,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   435,   436,   414,   420,     0,   415,
     390,     0,     0,     0,     0,   448,     0,     0,     0,     0,
       0,   201,   202,     0,     0,   218,     0,   167,     0,   167,
     478,     0,   313,     0,     0,     0,    58,    62,    61,    60,
      59,    64,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   320,   319,
     321,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   166,     0,   165,     0,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,   195,   393,   142,     0,   478,     0,   454,   455,
       0,     0,    94,    94,     0,     0,   442,   443,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     282,   282,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   167,     0,   405,   404,
       0,     0,     0,     0,   167,   167,     0,     0,     0,     0,
       0,     0,     0,   232,     0,   167,     0,     0,     0,     0,
       0,   284,     0,     0,     0,     0,   185,     0,     0,     0,
     308,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   427,     0,   428,   429,   430,     0,     0,
       0,     0,     0,   319,   422,     0,   416,     0,     0,     0,
     290,   200,     0,     0,     0,     0,     0,   167,     0,     0,
       0,     0,   220,   189,     0,   190,     0,     0,   212,     0,
       0,     0,     0,     0,    73,     0,     0,   395,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     318,    58,     0,     0,     0,    58,     0,     0,     0,     0,
       0,   162,     0,     0,     0,     0,   168,     0,     0,   335,
     334,   333,   332,   328,   329,   331,   330,   323,   322,   324,
     325,   326,   327,     0,   143,     0,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   304,   305,   306,     0,
       0,     0,     0,   280,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   167,     0,     0,
       0,     0,     0,   407,   406,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,     0,     0,     0,     0,     0,
       0,     0,   293,     0,     0,   186,     0,     0,   182,     0,
       0,     0,   303,   302,     0,     0,     0,   438,     0,   437,
       0,     0,   395,     0,     0,     0,     0,     0,     0,     0,
     318,   417,   424,     0,   324,   423,     0,     0,     0,     0,
       0,     0,     0,     0,   221,     0,   191,   193,     0,     0,
       0,     0,    75,    67,     0,   391,   397,   337,   359,   338,
     360,   339,   361,   340,   362,   341,   363,   342,   364,   343,
     365,   344,   366,   345,   367,   358,   380,   346,   368,     0,
       0,   348,   370,   349,   371,   350,   372,   351,   373,   352,
     374,   353,   375,   354,   376,     0,     0,     0,     0,     0,
       0,   468,     0,   469,   470,     0,   471,     0,     0,     0,
     465,   466,     0,     0,     0,   402,    86,     0,   461,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,     0,   392,     0,     0,     0,     0,   476,
       0,    43,     0,     0,     0,    56,     0,    34,    35,    36,
      37,    38,     0,   456,    23,    21,     0,     0,    24,     0,
       0,    65,   478,    97,    66,   105,     0,   444,   445,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,   283,   281,
       0,   289,     0,     0,   118,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,   194,     0,     0,
       0,   157,   159,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   261,     0,
     223,     0,     0,     0,     0,     0,     0,   285,   292,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   391,   439,   426,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,     0,   187,     0,     0,     0,
       0,     0,     0,   314,   477,     0,     0,   394,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   475,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,     0,     0,     0,     0,    74,    76,    78,     0,     0,
     452,     0,    84,     0,     0,     0,     0,   336,     0,     0,
       0,     0,     0,    29,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,   122,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,     0,     0,     0,
       0,     0,     0,     0,   287,     0,     0,     0,     0,     0,
       0,     0,     0,   295,     0,     0,   188,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,     0,   266,     0,
     272,     0,   274,     0,   268,     0,   270,     0,   233,   262,
       0,     0,     0,   180,     0,     0,     0,   294,     0,   184,
     183,   309,     0,     0,    30,    31,     0,     0,     0,     0,
     431,   432,   433,   434,   425,   419,     0,     0,     0,   449,
       0,     0,     0,   213,     0,     0,     0,     0,   197,   396,
     196,   347,   369,   355,   377,   356,   378,   357,   379,   472,
     473,   463,   464,     0,   400,   401,   399,   462,     0,    70,
       0,    58,     0,     0,     0,     0,    69,     0,     0,     0,
     450,     0,     0,     0,     0,     0,     0,     0,     0,   412,
       0,     0,    25,    26,     0,    27,     0,     0,    98,   101,
     124,     0,     0,     0,     0,     0,     0,   128,     0,     0,
     145,   146,     0,     0,   130,   153,     0,     0,     0,     0,
     120,     0,   286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,     0,     0,     0,     0,   167,   167,     0,
     243,     0,   245,     0,   247,     0,   414,     0,     0,   273,
     275,   269,   271,     0,     0,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,     0,   441,   440,   396,
     133,   134,     0,     0,     0,     0,    87,    91,     0,     0,
     315,   398,     0,     0,     0,     0,     0,    81,     0,     0,
      82,     0,   453,   169,   170,   171,   172,     0,    39,     0,
       0,     0,     0,     0,    41,   457,     0,     0,    99,   102,
       0,     0,   123,   131,   132,   136,     0,     0,   147,     0,
       0,   288,     0,   140,     0,     0,   279,   152,     0,     0,
       0,     0,   137,     0,   148,   154,     0,     0,     0,     0,
     411,     0,   410,     0,     0,     0,   234,     0,     0,   235,
       0,     0,   236,     0,     0,     0,     0,     0,     0,     0,
     179,     0,     0,   178,     0,     0,     0,   173,     0,     0,
      32,     0,     0,   447,     0,   215,   214,     0,     0,     0,
       0,   467,    72,    71,    77,    79,     0,    85,     0,    44,
       0,     0,     0,   413,     0,     0,     0,    28,     0,   108,
     113,     0,     0,     0,     0,     0,     0,     0,     0,   141,
     126,   139,   151,   156,     0,     0,    92,    93,   167,     0,
     160,   161,     0,     0,     0,     0,     0,     0,     0,   263,
       0,     0,   167,     0,     0,     0,     0,     0,   164,   163,
       0,     0,     0,     0,    88,    89,     0,     0,   451,     0,
      40,     0,     0,     0,    42,    57,     0,     0,     0,   297,
     299,   298,   300,   301,   144,     0,     0,     0,     0,     0,
       0,   409,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     0,     0,     0,   228,     0,     0,   174,     0,
       0,     0,   446,   216,     0,   316,    83,     0,     0,     0,
       0,     0,     0,   100,   109,     0,   103,   114,     0,     0,
       0,     0,   158,     0,   249,     0,     0,   251,     0,     0,
     253,     0,     0,     0,   264,     0,   224,     0,   167,     0,
       0,     0,   135,    90,     0,    48,     0,    54,     0,     0,
       0,     0,     0,   121,   149,   296,   408,   237,     0,     0,
     244,   238,     0,     0,   246,   239,     0,     0,   248,     0,
       0,     0,   230,     0,   177,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   112,     0,   115,   116,     0,     0,
     255,     0,   257,     0,   259,   265,   276,   229,   225,     0,
       0,     0,     0,    45,     0,    52,     0,     0,     0,   442,
       0,     0,     0,   240,     0,     0,   241,     0,     0,   242,
       0,     0,   181,     0,   175,     0,    46,     0,     0,   205,
       0,   111,     0,   117,     0,     0,     0,     0,     0,     0,
       0,   231,     0,     0,     0,     0,     0,     0,   106,   211,
     250,     0,   252,     0,   254,     0,   176,    47,    49,     0,
      50,     0,     0,     0,     0,     0,     0,     0,    55,   107,
     256,   258,   260,    51,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    83,   876,    84,    85,   643,  1297,  1303,
     867,  1038,  1449,  1615,   868,  1568,  1649,   869,  1617,   870,
     871,  1042,   303,   403,    86,   654,   412,  1399,  1400,   413,
    1598,  1457,  1504,  1458,  1507,   913,  1325,  1204,   626,   443,
     444,   445,   446,   264,   382,   383,    89,    90,    91,    92,
      93,    94,   265,   951,  1527,  1589,   712,  1347,  1350,  1353,
    1548,  1552,  1556,  1604,  1607,  1610,   947,   948,  1073,   910,
     683,   721,    96,    97,    98,    99,   266,   160,   459,   224,
    1188,   267,   268,   269,   517,   277,   853,  1031,   592,   408,
     593,   100,   270
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1244
static const yytype_int16 yypact[] =
{
    4778,    46,    67,  4888, -1244, -1244,    96,    64,   -56,     8,
      35,    25,   205,   210,   214,   265,   268,   111,   115,   -91,
     125,   132,    10,   163,   174,     6,   189,   231,   344,   382,
     397,   428,   327,   488,   438,   480,   536,   444,   223,   606,
     105,   434,   545,   -81,   454,   -70,   -70,   476,   166,   260,
     121,   621,   642,    26,    47,   659,   643,   106,   726,   727,
     746,  2741,   750,   566,   575,   593,    16,    19, -1244,   596,
   -1244,   767,   768,   610, -1244,   783,   787,    20,    21, -1244,
   -1244, -1244,  4243, -1244, -1244, -1244, -1244, -1244, -1244, -1244,
   -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244,    29, -1244,
     619,    97, -1244,     5, -1244, -1244, -1244, -1244,    54,   303,
     321,   340,   358,   446,   504,   537,   583,   616,   623,   627,
     646,   649,   660,   663,   674,   689,   706,   707,   710,   714,
     717,   720,   723,   652,   655,   666,   669,   670,   677, -1244,
   -1244, -1244, -1244,   862,   713,   729,   732, -1244, -1244, -1244,
    4243,  4243,  4243,  3815,  1947,    37,   921,   525,   687,   651,
   -1244,   780,   902,   235,   925,  4243,   404,   404, -1244,  4243,
   -1244, -1244, -1244, -1244, -1244, -1244, -1244,  4243,  4032,  4243,
    4243,   775,  4243,  4032,  4243,  4243,   788,  4032,  4243,  4243,
    2935,   805,   826, -1244,  4032,  2741,  2741,  2741,   834,   837,
    2741,  2741,  2741,   860, -1244, -1244, -1244, -1244,   863,   864,
     890,  2935,  4243,   936,  2935,    16,   847,   895,   -70,   -70,
     -70,  4243,  4243,    13, -1244,    78,   -70,   923,   930,   939,
    3986,    90,   -82,   911,   915,   919,  2741,  2741,  2935,   927,
      28,   792, -1244,   978, -1244,   940,   961,   964,  2741,  2741,
     974,   999,  1021,   322, -1244,  1040,    24,  1090,  1108,  1153,
     407,  3032,  4243,  2313, -1244, -1244,  4451, -1244,  1205, -1244,
     -24,  1212,  4243,  4243,  4243,  1043,  4243,  1041,  1094,  4243,
    4243, -1244, -1244,  4243,  1216, -1244,  1217, -1244,  1219, -1244,
    -110,   859, -1244,  2935,  2935,  1047,   998, -1244, -1244, -1244,
   -1244, -1244, -1244,  2935,  1223,  1057,  4243,  1229,  4243,  4243,
    4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,
    4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,
    4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,
    4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,
    4243,  4243,   404,   404,   404,   404,   404,   404,   404,   404,
     404,   404,   404,   404,  4243,   404,   404,   404,  1065,  1065,
    1065,  4032,  7332,    73,  4032,  6527,   269,  1059,  1230,  1066,
    1062, -1244,  1063,  3582,  4243, -1244,  4243,  4243,  4243,  4243,
    4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,  4243,
    4243, -1244, -1244, -1244, -1244,  1403,   372,  -129, -1244, -1244,
      72,  5773,   169,   218,  7353,  4032,  4511, -1244,   144,  7374,
    7395,  4243,  7416,   722,  7437,  7458,  4243,   725,  7479,  7500,
    1235,  4243,  4243,   734,  1239,  1240,  1243,  4243,  4243,  1246,
    1247,  1247,  4243,  1078,  1093,  1095,  1096,  4243,  4243,  4243,
    1262,  5693,  1097,  1272,  1100, -1244, -1244,   116, -1244, -1244,
    5799,  5825,   -70,   -70,   525,   525,   118,  4243,  4243,  4243,
    3986,  3986,  4243,  3582,   120, -1244,  4243,  4243,  4243,  4243,
    4243,  1274,  1276,  1277,  4243,  1279, -1244,  4243,  4243,   790,
   -1244,  4032,  4032,  4032,  1280,  1283,  4243,  4243,  4243,   154,
    3763,  1286,  1287, -1244,  4243, -1244, -1244, -1244,  1104,  1113,
    1114,  1115,  4032,  1065, -1244,  7521, -1244,   735,  4243,  3129,
   -1244, -1244,  7542,  7563,  7584,  1171,  5851, -1244,  1117,  4530,
    7605,  6550, -1244, -1244,  1064, -1244,  1194,  4243, -1244,  1126,
     738,  4243,  1294,  1295, -1244,  4243,  6573,   271,  7626,  6596,
    7647,  6619,  7668,  6642,  7689,  6665,  7710,  6688,  7731,  6711,
    7752,  6734,  7773,  6757,  7794,  6780,  7815,  6803,  7836,  6826,
    5877,  5903,  7857,  6849,  7878,  6872,  7899,  6895,  7920,  6918,
    7941,  6941,  7962,  6964,  7983,  6987,  5929,  5955,  5981,  6007,
    6033,  6059, -1244,    82,   451,   158,   452,  1124,  1125,  1132,
    1134,  1130,  1131,  1133,   234,  1782,  1139,  1137,  1140,   739,
      73, -1244,  2935,   743,   150,   998,  4243,  1306,  1316,    17,
    1144, -1244,   -76,    15,    18,   114, -1244,  4937,  4550,  1689,
    1761,  1038,  1038,   177,   177,   177,   177,   258,   258,  1065,
    1065,  1065,  1065,    38, -1244,  4243,  1317,    34,  4032,  1323,
    4032,  4243,  1328, -1244,  1318,  1332,   404,  1333,  4032,  4032,
    1196,  1335,  1337,  8004,  1341,  1224,  1342,  1345,  8025,  1227,
    1348,  1353,  4243,  8046,  4965,  1160, -1244, -1244, -1244,  8067,
    8088,  4243,  2935,  1360,  1359,  8109,  4197,  4197,  4197,  4197,
    8130,  8151,  8172,  2935,  4032,  1195, -1244, -1244,  1315,  1992,
     -70,  4243,  4243, -1244, -1244,  1192,  1193,  3986,  6085,  6111,
    6137,  5747,   949,   -70,  3373,  8193,  4993,  8214,  8235,  8256,
    4243,  1369, -1244,  4243,  8277, -1244,  7010,  7033, -1244,   744,
     752,   761, -1244, -1244,  7056,  7079,  6163, -1244,  4032, -1244,
    4032,  7102,   -24,  1211,  5021,  4032,  4032,  4032,  4032,   765,
   -1244, -1244,  4583,  4032,  1065, -1244,  1384,  1387,  1391,  1228,
    4243,  4360,  4243,  4243, -1244,    -2, -1244, -1244,  1220,  2935,
    1394,  5049, -1244, -1244,  7125,    43, -1244, -1244, -1244, -1244,
   -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244,
   -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244,  4243,
    4243, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244,
   -1244, -1244, -1244, -1244, -1244,  4243,  4243,  4243,  4243,  4243,
    4243, -1244,   404, -1244, -1244,  4032, -1244,  4032,   404,   404,
   -1244, -1244,   404,   404,   404, -1244, -1244,  4243, -1244,   404,
    1232,  4243,  1397,  1231,    42,  4243,  1401,  1402,  1869, -1244,
    1404,  1236,    16,  1406, -1244,  4032,  4032,  4032,  4032, -1244,
    4243, -1244,  1242,  1244,  1248, -1244,  1412, -1244, -1244, -1244,
   -1244, -1244,  7148, -1244, -1244,  1263,   404,   238, -1244,   365,
    6189, -1244,  1249,  1414, -1244, -1244,   -70,  4511, -1244,   877,
    2935,  2935,  1416,  2935,   884,  2935,  2935,  1424,  1363,  2935,
    2935,  2079,  1430,  1433,  4032,  1434,  1435,  2499, -1244, -1244,
    1437, -1244,  1439,  1271,  8508, -1244,  1278,  1281,  1282,  1440,
    1445,  1446,  1453,   774,  1456,  4386, -1244, -1244,   232,  6215,
    6241, -1244, -1244,  5077,    76,   -70,   -70,   -70,  1458,  1457,
    1285,  1459,  1298,    32,    44,    53,    56,   431, -1244,   289,
   -1244,   949,  1464,  1474,  1475,  1476,  1477,  8508, -1244,  2098,
    1307,  1479,  1481,  1482,  1422,  4243,  1484,  1485,  4243,   789,
     794,  -101, -1244, -1244,   795,   798,   802,   803, -1244,  4243,
     807,  2935,  2935,  2935,  1488,  6267, -1244,  4610,   326,  1490,
    1492,  2935,  1320, -1244, -1244,  1495,  1494, -1244,  1496,  8298,
    7171,  8319,  7194,  8340,  7217,  8361,  7240, -1244,   486,   524,
    1330,  1329,  1336,  1334,  1338,  8382,  1340,    73,  2283, -1244,
      73,   367,  1339,  1499,  2344, -1244, -1244, -1244,    16,  4243,
   -1244,   811, -1244,   812,   819,   820,   824,  8508,  1344,  4243,
    4243,  2935,  1346, -1244,  1343, -1244,  1502,    39,  1511,  4243,
    3494,    52,  1349,  1350,  1441,  1441,  2935,  1514,  1351,  1352,
    1515,  1517,  2935,  1354,  1518,  1521, -1244,  1527,  2935,   849,
    2935,  2935,  1534,  1533, -1244,  2935,  1535,  1536,  1538,  1539,
    2935,  2935,  2935, -1244,  1542,   544, -1244,  4243,  4243,  4243,
    1361,  1362,  -108,  -102,   -89,  1376, -1244,  2935, -1244,  4243,
   -1244,  1545, -1244,  1547, -1244,  1548, -1244,  1564, -1244, -1244,
    3986,   667,  2838, -1244,  1373,  1392,  3226, -1244,  4032, -1244,
   -1244, -1244,  1398,  2475, -1244, -1244,  7263,  1400,  1405,  1572,
   -1244, -1244, -1244, -1244,  8508, -1244,  1573,  1575,  1460, -1244,
    4243,  4243,  4243, -1244,  1576,   694,  1409,  1578, -1244,   293,
   -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244,
   -1244, -1244, -1244,   404, -1244, -1244, -1244, -1244,  2935, -1244,
    2935,   998,  4243,  1582,  1586,    17, -1244,  1590,  7286,    16,
   -1244,  1591,  1592,  1597,  1598,  4243,  6293,  6319,   866, -1244,
    4243,  1588, -1244, -1244,   404, -1244,  6345,  4197,  8508, -1244,
   -1244,  4243,  4243,   -70,  1600,  1602,  1604, -1244,  4243,  4243,
   -1244, -1244,  1605,  4243, -1244, -1244,  1607,  1608,  1436,  1610,
    1486,  4243, -1244,  1612,  2935,  2935,  2935,  2935,  1613,  1050,
    1615,  4243, -1244,  4197,  5105,  8403,  4639,   525,   525,   -70,
    1617,   -70,  1618,   -70,  1620,  4243,   152,  1449,  8424, -1244,
   -1244, -1244, -1244,  5133,   345, -1244,  1622,  2131,  1623,  2935,
     -70,  2131,  1625,   891,  4243, -1244,  1628, -1244, -1244,   -24,
   -1244, -1244,  2935,  4881,   226,  8445, -1244, -1244,  3546,  2935,
   -1244, -1244,  1463,  1631,  1633,  1634,  2559, -1244,  1635,  1639,
   -1244,  1465, -1244, -1244, -1244, -1244, -1244,   516,  8508,  4243,
    4243,  2935,  1469,   892,  8508, -1244,  1643,  4243,  8508, -1244,
    5161,  5189,   295, -1244, -1244, -1244,  5217,  5245, -1244,  5273,
    1645, -1244,  2935, -1244,  1587,  1651,  8508, -1244,  1652,  1653,
    1654,  1655, -1244,  1472, -1244, -1244,  5720,  3450,  1656,  1487,
   -1244,  4243, -1244,  1489,  1493,   439, -1244,  1497,   445, -1244,
    1498,   487, -1244,  1501,  7309,  1658,  2935,  1661,  1504,  4243,
   -1244,  3323,   499, -1244,   900,   530,   551, -1244,  1659,  5301,
   -1244,  1556,  4243, -1244,  4243, -1244, -1244,  4032,  4145,  1675,
    1505, -1244, -1244, -1244, -1244, -1244,    16, -1244,  1561, -1244,
    4243,  6371,  6397, -1244,  2935,  4243,  1681, -1244,  6423, -1244,
   -1244,  1683,  1684,  1685,  1686,  1687,  1688,   901,  1516, -1244,
   -1244, -1244, -1244, -1244,  2935,  4032, -1244, -1244,   525,  4909,
   -1244, -1244,  3986,   949,  3986,   949,  3986,   949,  1690, -1244,
     904,  2935, -1244,  5329,   -70,  1691,  4032,   -70, -1244, -1244,
    4243,  5357,  5385,   908, -1244, -1244,  1692,  1695, -1244,  1523,
    8508,  4243,  4243,   912,  8508, -1244,  4243,   916,   920, -1244,
   -1244, -1244, -1244, -1244, -1244,  1524,  4243,   934,   957,  1525,
    4243, -1244,  5413,   559,   854,  5441,   571,  1013,  5469,   580,
    1067, -1244,  2935,  1700,  1627,  4422,  1530,   601, -1244,   969,
     620,  4164, -1244, -1244,  1709, -1244, -1244,  4243,  8466,  6449,
      27,  6475,  1715, -1244, -1244,  1716, -1244, -1244,  4243,  5497,
    1718,  1720, -1244,  5525,  1721,  4243,  1722,  1723,  4243,  1729,
    1730,  4243,  1731,  1541, -1244,  4243, -1244,   949, -1244,  4032,
    1733,  3323, -1244, -1244,   975, -1244,  4243, -1244,  2935,  4243,
    2528,  3717,  6501, -1244, -1244, -1244, -1244, -1244,  1543,  5553,
   -1244, -1244,  1570,  5581, -1244, -1244,  1571,  5609, -1244,  1734,
    4391,  1222,  4448,   976, -1244,   712,   979,  1745,  1583,  8487,
     984,  5637,  2313, -1244, -1244,   404,  8508, -1244,  4243,   949,
    1749,   949,  1751,   949,  1758, -1244, -1244, -1244, -1244,   949,
    1759,  4032,  1762, -1244,   404, -1244,  1593,  1764,   987,  4488,
    1002,  5665,  1259, -1244,  1595,  1364, -1244,  1596,  1491, -1244,
    1599,  1650, -1244,  1009, -1244,  1010, -1244,  1601,  2935, -1244,
    4243, -1244,   998, -1244,  1765,  1770,   949,  1775,   949,  1779,
     949, -1244,  1780,   404,  1784,   404,  1032,  4424, -1244, -1244,
   -1244,  1725, -1244,  2105, -1244,  2287, -1244, -1244, -1244,  1037,
   -1244,  1785,   998,  1786,  1787,  1790,   404,  1791, -1244, -1244,
   -1244, -1244, -1244, -1244, -1244
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1244, -1244, -1244, -1244,   754, -1244, -1244, -1244, -1244,   270,
   -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244,
   -1244, -1244,  -349,   -88, -1244,  1389, -1244, -1244, -1244, -1244,
   -1244, -1244, -1244, -1244, -1244,  -555, -1244,   748,  1801, -1244,
   -1244, -1244, -1244,     1,  -457,  -224, -1244, -1244, -1244, -1244,
   -1244, -1244,  1802, -1244, -1244, -1244, -1244, -1244, -1244, -1244,
   -1244, -1244, -1244, -1244, -1244, -1244,  -923,  -849, -1244, -1244,
    1365, -1244, -1244, -1244, -1244, -1244,   248, -1244,    -9, -1244,
   -1243,   817,  1546,  1163,   985,  -200,   632, -1244,    11,    -5,
    -351, -1244,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -458
static const yytype_int16 yytable[] =
{
     101,   162,   594,   163,    88,   989,   473,   705,   706,   305,
     186,   165,   604,   304,   181,   454,  1364,   161,   489,   181,
     275,   851,   186,   278,   612,   286,   288,   616,  1111,   503,
     240,   168,   485,  1537,   486,   292,   223,   225,  1100,   231,
     874,   376,   861,   215,   647,  1193,  1021,   406,   104,   648,
    1102,   243,     4,   244,   462,   463,   216,   217,  1200,  1104,
     462,   463,  1106,   534,   537,   536,   501,     5,   301,   302,
    1239,   158,  1240,   462,   463,  1129,  1241,   164,  1242,  1407,
     611,   177,   130,   131,   132,   133,   134,   135,   178,  1243,
     476,  1244,   219,   220,   139,   140,   177,   477,  1109,   102,
     103,   104,   221,   855,   296,   105,   106,   107,   245,   222,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   916,   917,   918,   130,   131,   132,   133,   134,
     135,   136,   137,   138,  1101,   301,   302,   139,   140,   141,
     142,  1453,   862,   863,   864,   865,  1103,   611,   381,   241,
     518,   377,   378,   409,   409,  1105,  1022,  1023,  1107,   211,
     248,  1467,   212,   249,   990,   462,   463,   407,   410,   306,
     166,   307,   182,   145,   146,   187,   158,   182,   236,   183,
     237,   279,   464,   875,   856,   276,   852,   857,   875,   287,
     289,   293,   487,   504,   169,   242,  1538,   167,   294,   457,
     458,   170,   301,   302,   462,   463,   171,   466,   866,   996,
     172,   474,   297,   298,   299,   300,   308,   227,   309,   143,
     228,   698,   699,   229,  1374,   144,   145,   146,   462,   463,
     462,   463,   147,   148,   149,   649,   297,   298,   299,   300,
     650,   714,   462,   463,   159,   821,  1091,   465,   150,   151,
     822,   841,  1109,   152,   232,   845,   301,   302,   153,   475,
     154,   173,   155,   156,   174,   157,   615,   158,   462,   463,
     462,   463,   462,   463,   204,   175,   189,   205,   617,   176,
     206,   542,   207,   858,   700,  1570,   707,   179,   713,   297,
     298,   299,   300,   761,   180,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   519,   398,   399,   301,
     302,   233,   659,   400,   660,   234,   844,   737,   219,   220,
     291,   824,  1355,   738,  1142,   184,   825,   235,   221,   395,
     396,   397,   398,   399,   652,   230,   185,   653,   400,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   188,   409,   409,   409,   595,   596,   597,   598,   599,
     600,   601,   602,   603,  1171,  1636,   606,   607,   608,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   655,   462,   463,   653,   400,   368,   369,
     370,   372,   375,   189,   301,   302,  1375,   835,   406,   104,
    1087,  1047,   822,   405,  -455,   190,   659,   411,   297,   298,
     299,   300,   397,   398,   399,   414,   416,   419,   420,   400,
     422,   416,   424,   425,   193,   416,   428,   429,   301,   302,
     301,   302,   416,   130,   131,   132,   133,   134,   135,   191,
    -456,   462,   463,   703,   704,   139,   140,   462,   463,   776,
     451,   458,   301,   302,   192,   381,   381,  1110,   508,   460,
     461,   509,  -457,   925,   510,   310,   511,   311,   461,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   312,   499,   313,   500,   400,   501,  1143,
    1474,   157,  1477,   158,  1480,   198,   194,   462,   463,   513,
     515,   416,   314,   203,   315,   938,   297,   298,   299,   300,
     522,   523,   524,  1359,   526,   939,   846,   529,   530,   380,
     316,   531,   317,   940,   941,   942,   301,   302,  1048,   943,
     944,   945,   946,   659,   145,   146,   645,   199,   646,   195,
    1232,  1233,   196,   158,   546,   197,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     200,   462,   463,   201,  1561,   202,   213,   462,   463,   214,
     847,  1108,   605,    44,    45,    46,    47,  1422,   318,   416,
     319,    52,   416,  1424,    55,  1109,   823,   826,  1109,   822,
     827,  1109,   627,   218,   628,   629,   630,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,   462,
     463,   883,  1030,   409,   776,   226,  1602,   385,  1605,  1159,
    1608,   462,   463,   513,   659,  1426,  1611,   885,  1168,   663,
     208,  1170,  1172,   209,   668,   210,   320,  1434,   321,   673,
     674,   915,   915,   915,   915,   679,   680,   997,   238,  1389,
     685,   928,   462,   463,  1390,   690,   691,   692,   934,  1160,
    1277,  1278,   659,  1641,   949,  1643,   239,  1645,  1436,   322,
     247,   323,  1109,   462,   463,   708,   709,   710,   368,   369,
     711,   462,   463,   246,   715,   716,   717,   718,   719,  1437,
     250,   251,   724,   462,   463,   726,   727,  1515,   272,   416,
     416,   416,   462,   463,   734,   735,   736,   273,   741,  1518,
     252,   938,   744,  1109,   271,   324,  1109,   325,  1521,  1109,
     416,   939,  1109,   462,   463,   274,   752,   754,   280,   940,
     941,   942,   409,   281,   282,   943,   944,   945,   946,  1529,
    1343,  1344,   462,   463,   283,   741,   998,   284,   326,   771,
     327,   285,  1109,   774,  1109,   328,  1109,   329,  1531,   330,
     295,   331,     7,     8,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   332,   409,
     333,   334,   400,   335,   358,   409,   409,   359,  1177,   409,
     409,   409,   336,  1007,   337,   338,   409,   339,   360,  1010,
    1011,   361,   362,  1012,  1013,  1014,   340,  1255,   341,   363,
    1016,   622,    20,    21,   623,    23,    24,   624,    26,   625,
      28,   342,    29,   343,   848,   538,   384,    34,    35,   364,
      37,    38,    39,   409,   462,   463,    42,  1051,   344,   346,
     345,   347,   348,   997,   349,   365,   350,  1046,   351,   352,
    1591,   353,   354,   872,   355,   356,   416,   357,   416,   880,
     659,   366,   665,   659,   367,   669,   754,   887,   402,    63,
      64,    65,   659,   659,   675,   751,   769,   659,   770,   840,
     901,   659,   659,   843,   963,   379,  1092,  1093,  1094,   907,
     659,   404,   964,  1173,   914,   914,   914,   914,   938,   659,
     452,   965,   416,   659,  1052,   978,  1053,   421,   939,   929,
     930,  1058,   659,  1059,  1084,   933,   940,   941,   942,   401,
     426,  1469,   943,   944,   945,   946,   488,   659,   957,  1127,
     728,   959,   659,   659,  1128,  1130,   659,   431,  1131,  1292,
     659,   659,  1132,  1133,   490,   659,   416,  1135,   416,  1179,
     659,  1180,  1181,   416,   416,   416,   416,   659,   659,  1182,
    1183,   416,   659,   104,  1184,   432,   437,   430,   985,   438,
     987,   988,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   455,   659,   450,  1218,
     400,   453,   442,   938,  1516,   447,   448,   130,   131,   132,
     133,   134,   135,   939,  1301,  1199,  1302,   999,  1000,   139,
     140,   940,   941,   942,  1333,   483,  1334,   943,   944,   945,
     946,  1281,   449,  1001,  1002,  1003,  1004,  1005,  1006,   659,
    1395,  1368,  1396,   416,   456,   416,     7,     8,  1301,  1301,
    1435,  1465,  1482,   478,  1483,  1015,   659,   479,  1494,  1018,
    1301,   480,  1500,  1024,  1502,   505,  1503,   938,  1505,   484,
    1506,  1254,   467,   416,   416,   416,   416,   939,  1037,   468,
     539,   540,  1301,   506,  1510,   940,   941,   942,   469,   491,
     543,   943,   944,   945,   946,   622,    20,    21,   623,    23,
      24,   624,    26,   625,    28,   659,    29,  1511,   145,   146,
     492,    34,    35,   493,    37,    38,    39,   659,   496,  1530,
      42,   938,   416,  1395,   659,  1567,  1590,   659,   507,  1592,
     409,   939,  1301,   418,  1596,  1620,  1285,  1621,   423,   940,
     941,   942,   427,   497,  1282,   943,   944,   945,   946,   433,
     822,  1281,  1623,    63,    64,    65,  1447,   659,  1633,  1632,
    1634,   409,  1309,  1519,  1312,   498,   391,   392,   393,   394,
     395,   396,   397,   398,   399,  1306,     7,     8,  1485,   400,
    1301,   520,  1651,  1123,   502,  1656,  1126,  1657,   521,   525,
     527,   528,   532,   533,  1600,   535,   541,  1134,  1338,   544,
    1345,   545,  1348,   547,  1351,   618,   400,   619,   381,   381,
     620,   157,   672,   621,   766,   676,   677,  1522,  1362,   678,
     686,  1365,  1366,   681,   682,   622,    20,    21,   623,    23,
      24,   624,    26,   625,    28,   687,    29,   688,   689,   693,
     695,    34,    35,  1379,    37,    38,    39,  1178,   696,   697,
      42,   720,   722,   745,   723,   725,   732,  1186,  1187,   733,
     742,   743,   746,   747,   748,   759,   762,  1196,  1198,   768,
     772,   773,   828,   829,  1562,   830,   938,   831,   832,   833,
     838,   834,   849,    63,    64,    65,   939,   837,   839,   854,
     850,   873,   882,   889,   940,   941,   942,     7,     8,   878,
     943,   944,   945,   946,   881,  1234,  1235,  1236,   884,   904,
     886,   417,   890,   938,   891,  1246,   417,  1248,   893,   895,
     417,   894,   896,   939,   898,   899,   609,   417,  1253,   613,
     900,   940,   941,   942,   909,   911,   416,   943,   944,   945,
     946,   924,   931,   932,   767,   958,   622,    20,    21,   623,
      23,    24,   624,    26,   625,    28,   972,    29,  1273,  1274,
    1275,   981,    34,    35,   982,    37,    38,    39,   983,   991,
     993,    42,  1587,  1019,   984,  1017,  1020,  1025,  1026,   644,
    1029,  1028,  1032,  1473,  1039,  1476,  1040,  1479,  1043,   381,
    1286,  1050,  1045,  1056,   514,  1487,   417,  1041,  1490,   842,
     158,  1062,  1063,  1298,    63,    64,    65,  1067,  1304,  1625,
    1068,  1070,  1071,  1074,  1076,  1308,  1075,  1080,   938,  1310,
    1311,  1077,  1081,  1082,  1078,  1079,  1316,  1317,   939,  1083,
    1085,  1319,  1095,  1096,  1097,  1098,   940,   941,   942,  1326,
    1099,  1112,   943,   944,   945,   946,   729,   730,   731,  1336,
    1113,  1337,  1114,  1115,  1116,  1119,  1118,  1120,  1121,  1122,
    1124,  1125,  1139,  1354,  1144,   926,  1145,   749,  1149,   908,
    1147,  1148,  1150,  1161,  1162,   416,  1175,  1164,  1192,   416,
     922,  1165,  1369,  1167,  1163,  1174,  1185,  1195,  1203,  1191,
    1207,  1210,  1565,  1211,  1214,  1190,  1378,  1215,  1201,  1202,
    1208,  1209,  1216,  1213,   417,  1574,  1577,   417,  1221,  1222,
    1237,  1238,  1224,  1225,  1627,  1226,  1227,  1391,  1392,  1231,
    1245,  1249,  1259,  1250,  1251,  1398,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
    1252,  1260,   409,  1267,   400,   938,  1269,  1264,   514,  1270,
    1268,  1271,  1276,  1272,  1280,   939,   992,  1279,  1287,  1419,
    1288,   409,  1305,   940,   941,   942,  1290,  1293,  1294,   943,
     944,   945,   946,  1295,  1296,  1616,  1313,  1433,  1314,   513,
    1315,  1318,  1320,  1324,  1321,  1322,  1323,  1638,  1327,  1332,
    1441,  1335,  1442,  1346,  1349,   416,  1352,  1356,  1360,  1363,
     409,  1367,   409,   877,  1370,   879,  1381,  1382,  1450,  1383,
    1384,  1388,  1386,  1454,  1647,  1387,  1650,  1659,  1394,  1397,
    1406,  1414,  1408,   409,   417,   417,   417,  1409,  1410,  1411,
    1412,  1413,  1417,   416,  1429,  1438,  1418,  1663,  1431,  1420,
    1472,  1629,  1475,  1421,  1478,   417,  1423,  1425,  1440,   923,
    1427,  1445,   755,  1432,   416,  1446,  1448,  1455,  1491,  1459,
    1460,  1461,  1462,  1463,  1464,  1466,  1481,  1488,  1495,  1498,
    1499,  1496,  1497,  1508,  1501,  1512,  1524,  1054,  1055,  1528,
    1057,  1525,  1060,  1061,  1509,  1533,  1064,  1065,  1513,  1540,
    1541,  1559,  1579,   969,  1544,   970,  1545,  1547,  1550,  1551,
     974,   975,   976,   977,   938,  1554,  1555,  1558,   980,  1564,
    1585,   434,   435,   436,   939,  1304,   439,   440,   441,  1581,
    1583,  1593,   940,   941,   942,  1603,  1542,  1606,   943,   944,
     945,   946,  1594,  1549,  1609,  1612,  1553,  1534,  1614,  1557,
    1619,  1639,  1618,  1560,  1626,  1628,  1640,   416,  1630,   416,
    1635,  1642,   481,   482,  1569,  1644,  1646,  1571,   836,  1576,
    1648,  1658,  1660,  1661,   494,   495,  1662,  1664,  1136,  1137,
    1138,  1194,   656,  1205,    87,    95,   684,  1289,  1146,   938,
    1008,   417,  1009,   417,     0,     0,     0,     0,     0,   939,
    1599,   755,   888,     0,     0,     0,  1601,   940,   941,   942,
    1631,     0,     0,   943,   944,   945,   946,     0,     0,   416,
    1033,  1034,  1035,  1036,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,   417,  1189,     0,
     400,     0,     0,     0,     0,     0,     0,     0,  1637,     0,
       0,     0,     0,  1206,     0,  1027,     0,     0,     0,  1212,
       0,     0,     0,     0,     0,  1217,     0,  1219,  1220,  1069,
       0,     0,  1223,     0,     0,     0,     0,  1228,  1229,  1230,
       0,   417,     0,   417,     0,  1653,     0,     0,   417,   417,
     417,   417,     0,     0,  1247,     0,   417,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,  1258,
       0,     0,   400,  1262,     0,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
     102,   290,     0,   400,     0,     0,   105,   106,   107,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,  1283,     0,  1284,   417,     0,
     417,     0,   136,   137,   138,     0,     0,     0,     0,     0,
     141,   142,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   417,   417,
     417,   417,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,  1328,  1329,  1330,  1331,     0,     0,     0,     0,     0,
       0,     0,     0,   622,    20,    21,   623,    23,    24,   624,
      26,   625,    28,     0,    29,     0,     0,   417,     0,    34,
      35,     0,    37,    38,    39,     0,  1189,     0,    42,     0,
       0,     0,     0,     0,     0,  1066,   144,     0,     0,  1371,
       0,     0,     0,   147,   148,   149,  1380,     0,     0,     0,
       0,     0,     0,  1263,  1117,     0,     0,     0,     0,   150,
     151,    63,    64,    65,   152,     0,     0,     0,  1393,   262,
       0,     0,   373,     0,   156,     0,   374,     0,     0,     0,
       0,     0,     0,     0,   102,   253,     0,     0,     0,  1189,
     105,   106,   107,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   255,     0,     0,
       0,     0,   927,  1430,     0,     0,   136,   137,   138,     0,
       0,     0,     0,     0,   141,   142,     0,     0,     0,   938,
       0,     0,   256,     0,     0,   257,     0,     0,   258,   939,
     259,     0,     0,     0,     0,     0,     0,   940,   941,   942,
       0,  1189,   260,   943,   944,   945,   946,     0,     0,    44,
      45,    46,    47,    48,     0,     0,     0,    52,     0,     0,
      55,  1189,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,  1484,     0,
     400,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
     144,     0,     0,     0,     0,     0,     0,   147,   148,   149,
       0,   417,     0,     0,     0,  1654,     0,     0,     0,  1169,
       0,     0,     0,   470,  1361,     0,     0,     0,   152,  1523,
       0,     0,     0,   472,     0,     0,     0,     0,   156,     0,
     222,   516,     0,     0,     0,     0,   102,   253,     0,     0,
       0,     0,   105,   106,   107,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   255,
    1176,     0,     0,     0,     0,  1189,     0,  1573,   136,   137,
     138,     0,  1443,     0,     0,     0,   141,   142,     0,     0,
       0,   938,     0,     0,   256,     0,     0,   257,     0,     0,
     258,   939,   259,     0,     0,     0,     0,     0,     0,   940,
     941,   942,     0,     0,   260,   943,   944,   945,   946,     0,
    1468,    44,    45,    46,    47,    48,     0,     0,     0,    52,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
     417,  1489,     0,     0,   417,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1189,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,   144,     0,   400,     0,     0,     0,     0,   147,
     148,   149,     0,     0,     0,     0,     0,  1655,     0,     0,
       0,     0,     0,     0,     0,   150,   415,     0,     0,     0,
     152,  1265,     0,     0,     0,   262,     0,     0,     0,     0,
     156,     0,     0,   516,     0,     0,     0,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,  1563,   400,  1566,     0,     0,     0,
       0,     0,     0,     0,   514,     0,     0,     0,     0,     0,
       0,   102,   253,   104,     0,     0,     0,   105,   106,   107,
     417,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   255,  1385,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,  1613,     0,   417,   139,
     140,   141,   142,  1072,     0,     0,     0,     0,     0,   256,
       0,     0,   257,     0,     0,   258,     0,   259,     0,   417,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
       0,     0,     0,     0,     0,     0,    44,    45,    46,    47,
      48,     0,     0,     0,    52,     0,     0,    55,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,   144,   145,   146,
     400,     0,     0,     0,   147,   148,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,   261,   417,     0,   417,   152,     0,     0,     0,     0,
     262,     0,     0,     0,     0,   156,     0,  1572,     0,     0,
       0,     0,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,     0,   417,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   253,   254,     0,     0,     0,
     105,   106,   107,     0,   417,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   255,     0,     0,
       0,     0,     0,     0,     0,     0,   136,   137,   138,     0,
       0,     0,     0,     0,   141,   142,     0,     0,     0,     0,
       0,     0,   256,     0,     0,   257,     0,     0,   258,     0,
     259,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,     0,     0,     0,     0,     0,     0,    44,
      45,    46,    47,    48,     0,     0,     0,    52,     0,     0,
      55,   102,   253,  1256,     0,     0,     0,   105,   106,   107,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   255,     0,     0,     0,     0,     0,
     144,     0,     0,   136,   137,   138,     0,   147,   148,   149,
       0,   141,   142,     0,     0,     0,     0,     0,     0,   256,
       0,     0,   257,   150,   261,   258,     0,   259,   152,     0,
       0,     0,     0,   262,     0,     0,     0,     0,   156,   260,
     263,     0,     0,     0,     0,     0,    44,    45,    46,    47,
      48,     0,     0,     0,    52,     0,     0,    55,   102,   253,
       0,     0,     0,     0,   105,   106,   107,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   255,     0,     0,     0,     0,     0,   144,     0,     0,
     136,   137,   138,     0,   147,   148,   149,     0,   141,   142,
       0,     0,     0,     0,     0,     0,   256,     0,     0,   257,
     150,   261,   258,     0,   259,   152,     0,     0,     0,     0,
     262,     0,     0,     0,     0,   156,   260,  1257,     0,     0,
       0,     0,     0,    44,    45,    46,    47,    48,     0,     0,
       0,    52,     0,     0,    55,   102,   253,     0,     0,     0,
       0,   105,   106,   107,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   255,     0,
       0,     0,     0,     0,   144,     0,     0,   136,   137,   138,
       0,   147,   148,   149,     0,   141,   142,     0,     0,     0,
       0,     0,     0,   256,     0,     0,   257,   150,   261,   258,
       0,   259,   152,     0,     0,     0,     0,   262,     0,     0,
       0,     0,   156,   260,   263,     0,     0,     0,     0,     0,
      44,    45,    46,    47,    48,     0,     0,     0,    52,     0,
       0,    55,   102,   253,     0,     0,     0,     0,   105,   106,
     107,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   255,     0,     0,     0,     0,
       0,   144,     0,     0,   136,   137,   138,     0,   147,   148,
     149,     0,   141,   142,     0,     0,     0,     0,     0,     0,
     256,     0,     0,   257,   150,   415,   258,     0,   259,   152,
       0,     0,     0,     0,   262,     0,     0,     0,     0,   156,
     260,   512,     0,     0,     0,     0,     0,    44,    45,    46,
      47,    48,     0,     0,     0,    52,     0,     0,    55,   102,
     253,     0,     0,     0,     0,   105,   106,   107,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   255,     0,     0,     0,     0,     0,   144,     0,
       0,   136,   137,   138,     0,   147,   148,   149,     0,   141,
     142,     0,     0,     0,     0,     0,     0,   256,     0,     0,
     257,   150,   415,   258,     0,   259,   152,     0,     0,     0,
       0,   262,     0,     0,     0,     0,   156,   260,   753,     0,
       0,     0,     0,     0,    44,    45,    46,    47,    48,     0,
       0,     0,    52,     0,     0,    55,   102,   253,     0,     0,
       0,     0,   105,   106,   107,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   255,
       0,     0,     0,     0,     0,   144,     0,     0,   136,   137,
     138,     0,   147,   148,   149,     0,   141,   142,     0,     0,
       0,     0,     0,     0,   256,     7,     8,   257,   150,   261,
     258,     0,   259,   152,     0,     0,     0,     0,   262,     0,
       0,     0,     0,   156,   260,  1261,     0,     0,     0,     0,
       0,    44,    45,    46,    47,    48,     0,     0,     0,    52,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   622,    20,    21,   623,    23,    24,
     624,    26,   625,    28,     0,    29,     0,     0,     0,     0,
      34,    35,     0,    37,    38,    39,  1416,     0,     0,    42,
       0,     0,   144,     0,     0,     0,     0,     0,     0,   147,
     148,   149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   470,  1361,     0,     0,     0,
     152,     0,    63,    64,    65,   472,     0,   102,   290,   104,
     156,     0,   222,   105,   106,   107,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     0,     0,     0,   139,   140,   141,   142,   102,
     290,   104,     0,   950,     0,   105,   106,   107,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     7,     8,     0,   139,   140,   141,
     142,     0,     0,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,   145,   146,     0,     0,     0,     0,
     147,   148,   149,   622,    20,    21,   623,    23,    24,   624,
      26,   625,    28,     0,    29,     0,   150,   151,     0,    34,
      35,   152,    37,    38,    39,     0,   262,     0,    42,     0,
       0,   156,     0,  1197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   144,   145,   146,     0,     0,
       0,     0,   147,   148,   149,     0,     0,     0,     0,     0,
       0,    63,    64,    65,     0,     0,     0,     0,   150,   151,
       0,     0,     0,   152,     0,     0,     0,     0,   262,     0,
     102,   290,   104,   156,     0,  1377,   105,   106,   107,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,   102,   290,   139,   140,
     141,   142,   105,   106,   107,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   136,   137,
     138,     0,     0,     0,     0,     0,   141,   142,   102,   290,
       0,     0,     0,     0,   105,   106,   107,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     0,     0,     0,     0,     0,   144,   145,   146,     0,
     136,   137,   138,   147,   148,   149,     0,     0,   141,   142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,     0,     0,     0,   152,     0,     0,     0,     0,   262,
       0,     0,     0,     0,   156,     0,  1575,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,   147,
     148,   149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,   151,     0,     0,     0,
     152,     0,     0,     0,     0,   262,     0,     0,   739,     0,
     156,     0,   740,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,     0,
       0,   147,   148,   149,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,   151,     0,
       0,     0,   152,     0,     0,     0,     0,   262,     0,   102,
     290,     0,   156,     0,   371,   105,   106,   107,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,   138,     0,   102,   253,     0,     0,   141,
     142,   105,   106,   107,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   255,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,   138,
       0,     0,     0,     0,     0,   141,   142,     0,     0,     0,
       0,     0,     0,   256,     0,     0,   257,     0,     0,   258,
       0,   259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   260,     0,     0,     0,     0,     0,     0,
      44,    45,    46,    47,    48,   144,     0,     0,    52,     0,
       0,    55,   147,   148,   149,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   470,   471,
       0,  1444,     0,   152,     0,     0,     0,     0,   472,     0,
       0,     0,     0,   156,     0,   222,     0,     0,     0,     0,
    1532,   144,     0,     0,     0,     0,     0,     0,   147,   148,
     149,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   415,     0,     0,     0,   152,
     102,   290,   104,     0,   262,     0,   105,   106,   107,   156,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,   102,   290,   139,   140,
     141,   142,   105,   106,   107,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   136,   137,
     138,     0,     0,     0,     0,     0,   141,   142,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,   144,   145,   146,     0,
       0,     0,     0,   147,   148,   149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,     0,     0,     0,   152,     0,     0,     0,     0,   262,
       0,     0,     7,     8,   156,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,   147,
     148,   149,     0,     0,     0,     0,     0,  1586,     7,     8,
       0,     0,     0,     0,     0,   150,   151,     0,     0,     0,
     152,     0,     0,     0,     0,   262,     0,     0,     0,     0,
     156,   622,    20,    21,   623,    23,    24,   624,    26,   625,
      28,  1652,    29,     0,     7,     8,     0,    34,    35,     0,
      37,    38,    39,     0,     0,     0,    42,   622,    20,    21,
     623,    23,    24,   624,    26,   625,    28,     0,    29,   518,
       7,     8,     0,    34,    35,     0,    37,    38,    39,     0,
       0,     0,    42,     0,     0,     0,     0,     0,     0,    63,
      64,    65,     0,   622,    20,    21,   623,    23,    24,   624,
      26,   625,    28,     0,    29,  1622,   518,     0,     0,    34,
      35,     0,    37,    38,    39,    63,    64,    65,    42,   622,
      20,    21,   623,    23,    24,   624,    26,   625,    28,   518,
      29,     0,     0,     0,     0,    34,    35,     0,    37,    38,
      39,     0,     0,     0,    42,     0,     0,     0,   763,     0,
     986,    63,    64,    65,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   860,     0,
       0,     0,   400,     0,     0,     0,  1086,    63,    64,    65,
       0,     0,     0,     0,     0,     0,     0,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   979,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,  1526,     0,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   519,   398,   399,  1141,     0,
       0,     0,   400,     0,     0,     0,     0,     0,  1588,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   658,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   658,   398,   399,     0,     0,
       0,     0,   400,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,     0,     0,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,    -4,     1,
       0,   400,    -4,     0,     0,     0,     0,     0,     0,     0,
      -4,    -4,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,     0,    -4,    -4,  1341,     0,  1342,
       0,     0,     0,     0,     0,     0,    -4,    -4,    -4,     0,
       0,     0,     0,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,     0,    -4,    -4,    -4,     0,     0,     0,     0,
       0,    -4,     6,     0,     0,     0,    -4,    -4,    -4,    -4,
       7,     8,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,
      -4,    -4,    -4,    -4,     0,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,    13,     0,
       0,     0,     0,    14,    15,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,    58,    59,    60,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,    62,    63,    64,    65,
       0,     0,    66,     0,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      79,    80,    81,    82,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,  1372,
       0,  1373,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,     0,     0,     0,  1470,     0,  1471,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,     0,     0,   859,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,   903,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,     0,     0,   953,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,     0,
       0,   973,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,     0,     0,     0,     0,     0,   994,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,     0,     0,  1090,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,  1339,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,     0,     0,  1358,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,     0,
       0,  1401,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,     0,     0,     0,     0,     0,  1402,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,     0,     0,  1403,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,  1404,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,     0,     0,  1405,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,     0,
       0,  1439,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,     0,     0,     0,     0,     0,  1486,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,     0,     0,  1492,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,  1493,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,     0,     0,  1514,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,     0,
       0,  1517,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,     0,     0,     0,     0,     0,  1520,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,     0,     0,  1543,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,  1546,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,     0,     0,  1580,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,     0,
       0,  1582,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,     0,     0,     0,     0,     0,  1584,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,     0,     0,  1597,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,  1624,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,     0,   694,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,     0,  1415,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
     750,     0,     0,     0,     0,   701,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,   651,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,     0,     0,     0,   701,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,   702,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,   760,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,   799,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,   800,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,     0,     0,     0,   815,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,   816,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,   817,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,   818,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,   819,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,     0,     0,     0,   820,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,   935,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,   936,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,   937,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,   968,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,     0,     0,     0,  1049,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,  1088,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,  1089,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,  1140,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,  1299,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,     0,     0,     0,  1300,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,  1307,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,  1451,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,  1452,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,  1456,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,     0,     0,     0,  1536,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,  1539,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,  1578,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,   614,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,   765,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,   775,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,   778,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,   780,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,   782,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
     784,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,   786,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,   788,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,   790,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,   792,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,   794,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,   796,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,   798,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,   802,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,   804,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
     806,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,   808,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,   810,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,   812,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,   814,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,   961,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,   962,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,   966,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,   967,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,   971,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
     995,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,  1044,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,  1152,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,  1154,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,  1156,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,  1158,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,  1266,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,  1291,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,  1428,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,   610,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,   657,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,   661,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,   662,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,   664,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
     666,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,   667,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,   670,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,   671,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,   750,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,   756,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,   757,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,   758,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,   764,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,   777,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
     779,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,   781,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,   783,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,   785,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,   787,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,   789,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,   791,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,   793,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,   795,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,   797,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
     801,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,   803,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,   805,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,   807,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,   809,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,   811,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,   813,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,   892,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,   897,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,   902,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
     905,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,   906,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,   912,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,   919,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,   920,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,   921,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,   952,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,   954,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,   955,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,   956,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
     960,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,  1151,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,  1153,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,  1155,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,  1157,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,  1166,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,  1340,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,  1357,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,  1376,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,  1535,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
    1595,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400
};

static const yytype_int16 yycheck[] =
{
       3,     6,   353,     6,     3,     7,   230,   464,   465,     4,
       4,    67,   363,   101,     4,   215,  1259,     6,   242,     4,
       4,     4,     4,     4,   373,     5,     5,   376,   951,     5,
       4,     6,     4,     6,     6,     6,    45,    46,     6,    48,
       6,     4,     4,   124,   173,     6,     4,     4,     5,   178,
       6,     4,     6,     6,   162,   163,   137,   138,     6,     6,
     162,   163,     6,   287,   174,   289,   176,     0,   169,   170,
     178,   181,   180,   162,   163,   176,   178,    13,   180,  1322,
       7,   172,    39,    40,    41,    42,    43,    44,   179,   178,
     172,   180,   162,   163,    51,    52,   172,   179,   947,     3,
       4,     5,   172,   179,     7,     9,    10,    11,    61,   179,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,   687,   688,   689,    39,    40,    41,    42,    43,
      44,    45,    46,    47,   112,   169,   170,    51,    52,    53,
      54,  1394,   114,   115,   116,   117,   112,     7,   157,   133,
       8,   124,   125,   166,   167,   112,   124,   125,   112,    64,
      64,  1414,    67,    67,   176,   162,   163,   166,   167,   174,
     172,   176,   172,   140,   141,   179,   181,   172,    67,   179,
      69,   172,   179,   159,   179,   179,   179,   179,   159,   179,
     179,   172,   174,   179,   179,   179,   179,   172,   179,   218,
     219,     6,   169,   170,   162,   163,     6,   226,   180,   176,
       6,   230,   149,   150,   151,   152,   172,    61,   174,   133,
      64,   455,   456,    67,     8,   139,   140,   141,   162,   163,
     162,   163,   146,   147,   148,   173,   149,   150,   151,   152,
     178,   475,   162,   163,     6,   173,   180,   179,   162,   163,
     178,   610,  1111,   167,     4,   614,   169,   170,   172,   179,
     174,     6,   176,   177,     6,   179,     7,   181,   162,   163,
     162,   163,   162,   163,    61,   174,   172,    64,   376,   174,
      67,   296,    69,   179,   178,  1538,   178,   172,   178,   149,
     150,   151,   152,   527,   172,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   169,
     170,    61,   178,   171,   180,    65,   176,   173,   162,   163,
      82,   173,   180,   179,     8,   172,   178,    77,   172,   162,
     163,   164,   165,   166,   175,   179,   172,   178,   171,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   172,   365,   366,   367,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     7,  1618,   365,   366,   367,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   175,   162,   163,   178,   171,   150,   151,
     152,   153,   154,   172,   169,   170,   180,   173,     4,     5,
     178,   173,   178,   165,   179,    71,   178,   169,   149,   150,
     151,   152,   164,   165,   166,   177,   178,   179,   180,   171,
     182,   183,   184,   185,     6,   187,   188,   189,   169,   170,
     169,   170,   194,    39,    40,    41,    42,    43,    44,    67,
     179,   162,   163,   462,   463,    51,    52,   162,   163,   547,
     212,   470,   169,   170,    67,   464,   465,   178,    61,   221,
     222,    64,   179,   697,    67,   172,    69,   174,   230,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   172,   172,   174,   174,   171,   176,   173,
    1423,   179,  1425,   181,  1427,    67,   179,   162,   163,   261,
     262,   263,   172,    69,   174,    84,   149,   150,   151,   152,
     272,   273,   274,   178,   276,    94,   614,   279,   280,     4,
     172,   283,   174,   102,   103,   104,   169,   170,   173,   108,
     109,   110,   111,   178,   140,   141,   174,    67,   176,    61,
       6,     7,    64,   181,   306,    67,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
      64,   162,   163,    67,  1527,    69,   172,   162,   163,    64,
     615,   180,   364,    88,    89,    90,    91,   178,   172,   371,
     174,    96,   374,   178,    99,  1474,   175,   175,  1477,   178,
     178,  1480,   384,   179,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   162,
     163,   654,   852,   656,   742,   179,  1579,     6,  1581,   173,
    1583,   162,   163,   415,   178,   178,  1589,   656,  1017,   421,
      64,  1020,  1021,    67,   426,    69,   172,   178,   174,   431,
     432,   686,   687,   688,   689,   437,   438,   775,    67,   173,
     442,   700,   162,   163,   178,   447,   448,   449,   707,   175,
       6,     7,   178,  1626,   713,  1628,    64,  1630,   178,   172,
      67,   174,  1561,   162,   163,   467,   468,   469,   470,   471,
     472,   162,   163,    64,   476,   477,   478,   479,   480,   178,
       4,     4,   484,   162,   163,   487,   488,   178,   172,   491,
     492,   493,   162,   163,   496,   497,   498,   172,   500,   178,
       4,    84,   504,  1602,     4,   172,  1605,   174,   178,  1608,
     512,    94,  1611,   162,   163,   172,   518,   519,   172,   102,
     103,   104,   775,     6,     6,   108,   109,   110,   111,   178,
    1237,  1238,   162,   163,   174,   537,   775,     4,   172,   541,
     174,     4,  1641,   545,  1643,   172,  1645,   174,   178,   172,
     181,   174,    12,    13,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   172,   822,
     174,   172,   171,   174,   172,   828,   829,   172,  1028,   832,
     833,   834,   172,   822,   174,   172,   839,   174,   172,   828,
     829,   172,   172,   832,   833,   834,   172,   180,   174,   172,
     839,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,   172,    72,   174,   616,     6,   179,    77,    78,     7,
      80,    81,    82,   876,   162,   163,    86,   886,   172,   172,
     174,   174,   172,   971,   174,   172,   172,   876,   174,   172,
     178,   174,   172,   645,   174,   172,   648,   174,   650,   651,
     178,   172,   180,   178,   172,   180,   658,   659,     6,   119,
     120,   121,   178,   178,   180,   180,   178,   178,   180,   180,
     672,   178,   178,   180,   180,     4,   935,   936,   937,   681,
     178,     6,   180,  1021,   686,   687,   688,   689,    84,   178,
       4,   180,   694,   178,    67,   180,    69,   172,    94,   701,
     702,    67,   178,    69,   180,   707,   102,   103,   104,   179,
     172,  1418,   108,   109,   110,   111,   174,   178,   720,   180,
     180,   723,   178,   178,   180,   180,   178,   172,   180,  1179,
     178,   178,   180,   180,     6,   178,   738,   180,   740,   178,
     178,   180,   180,   745,   746,   747,   748,   178,   178,   180,
     180,   753,   178,     5,   180,   179,   172,   190,   760,   172,
     762,   763,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   179,   178,   211,   180,
     171,   214,   172,    84,   180,   172,   172,    39,    40,    41,
      42,    43,    44,    94,   178,  1050,   180,   799,   800,    51,
      52,   102,   103,   104,     4,   238,     6,   108,   109,   110,
     111,  1149,   172,   815,   816,   817,   818,   819,   820,   178,
     178,   180,   180,   825,   179,   827,    12,    13,   178,   178,
     180,   180,   178,   172,   180,   837,   178,   172,   180,   841,
     178,   172,   180,   845,   178,     5,   180,    84,   178,   172,
     180,  1110,   179,   855,   856,   857,   858,    94,   860,   179,
     293,   294,   178,     5,   180,   102,   103,   104,   179,   179,
     303,   108,   109,   110,   111,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,   178,    72,   180,   140,   141,
     179,    77,    78,   179,    80,    81,    82,   178,   174,   180,
      86,    84,   904,   178,   178,   180,   180,   178,     5,   180,
    1163,    94,   178,   178,   180,   178,  1171,   180,   183,   102,
     103,   104,   187,   174,  1163,   108,   109,   110,   111,   194,
     178,  1269,   180,   119,   120,   121,  1386,   178,   178,   180,
     180,  1194,  1197,   180,  1203,   174,   158,   159,   160,   161,
     162,   163,   164,   165,   166,  1194,    12,    13,  1432,   171,
     178,     6,   180,   965,   174,   178,   968,   180,     6,   176,
     179,   127,     6,     6,  1575,     6,   179,   979,  1233,     6,
    1239,   174,  1241,     4,  1243,   176,   171,     7,  1237,  1238,
     174,   179,     7,   180,   180,     6,     6,   180,  1257,     6,
     172,  1260,  1261,     7,     7,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,   172,    72,   172,   172,     7,
     173,    77,    78,  1278,    80,    81,    82,  1029,     6,   179,
      86,     7,     6,   179,     7,     6,     6,  1039,  1040,     6,
       4,     4,   179,   179,   179,   124,   179,  1049,  1050,   173,
       6,     6,   178,   178,  1528,   173,    84,   173,   178,   178,
     173,   178,     6,   119,   120,   121,    94,   178,   178,   175,
       4,     4,     4,   127,   102,   103,   104,    12,    13,     6,
     108,   109,   110,   111,     6,  1087,  1088,  1089,     6,   179,
       7,   178,     7,    84,     7,  1097,   183,  1099,     7,     7,
     187,   127,     7,    94,   127,     7,   371,   194,  1110,   374,
       7,   102,   103,   104,     4,     6,  1118,   108,   109,   110,
     111,   176,   180,   180,   180,     6,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,   175,    72,  1140,  1141,
    1142,     7,    77,    78,     7,    80,    81,    82,     7,   179,
       6,    86,   180,     6,   176,   173,   175,     6,     6,     6,
     174,     7,     6,  1422,   172,  1424,   172,  1426,     6,  1418,
    1172,     7,   159,     7,   261,  1434,   263,   179,  1437,   612,
     181,     7,    69,  1185,   119,   120,   121,     7,  1190,   180,
       7,     7,     7,     6,   173,  1197,     7,     7,    84,  1201,
    1202,   173,     7,     7,   173,   173,  1208,  1209,    94,     6,
       4,  1213,     4,     6,   179,     6,   102,   103,   104,  1221,
     172,     7,   108,   109,   110,   111,   491,   492,   493,  1231,
       6,  1233,     7,     7,     7,     6,   179,     6,     6,    67,
       6,     6,     4,  1245,     4,   180,     4,   512,     4,   682,
     180,     6,     6,   173,   175,  1257,     7,   173,     6,  1261,
     693,   173,  1264,   173,   178,   176,   172,     6,    77,   176,
       6,     6,  1531,     6,     6,   179,  1278,     6,   179,   179,
     179,   179,     5,   179,   371,  1540,  1541,   374,     4,     6,
     179,   179,     7,     7,   180,     7,     7,  1299,  1300,     7,
     174,     6,   179,     6,     6,  1307,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
       6,   179,  1575,   173,   171,    84,     4,   179,   415,     6,
     175,     6,     6,   123,     6,    94,   769,   178,     6,  1341,
       4,  1594,     4,   102,   103,   104,     6,     6,     6,   108,
     109,   110,   111,     6,     6,  1594,     6,  1359,     6,  1361,
       6,     6,     5,   127,     6,   179,     6,  1622,     6,     6,
    1372,     6,  1374,     6,     6,  1377,     6,   178,     6,     6,
    1633,     6,  1635,   648,     6,   650,   173,     6,  1390,     6,
       6,   176,     7,  1395,  1633,     6,  1635,  1652,   179,     6,
       5,   179,    65,  1656,   491,   492,   493,     6,     6,     6,
       6,     6,     6,  1415,     6,     6,   179,  1656,     7,   180,
    1422,   180,  1424,   180,  1426,   512,   179,   179,   122,   694,
     179,     6,   519,   179,  1436,   180,   125,     6,  1440,     6,
       6,     6,     6,     6,     6,   179,     6,     6,     6,  1451,
    1452,     6,   179,   179,  1456,   180,     6,   890,   891,   179,
     893,    84,   895,   896,  1466,     6,   899,   900,  1470,     4,
       4,   180,   179,   738,     6,   740,     6,     6,     6,     6,
     745,   746,   747,   748,    84,     6,     6,     6,   753,     6,
       6,   195,   196,   197,    94,  1497,   200,   201,   202,   179,
     179,     6,   102,   103,   104,     6,  1508,     6,   108,   109,
     110,   111,   179,  1515,     6,     6,  1518,  1497,     6,  1521,
       6,     6,   179,  1525,   179,   179,     6,  1529,   179,  1531,
     179,     6,   236,   237,  1536,     6,     6,  1539,     6,  1541,
       6,     6,     6,     6,   248,   249,     6,     6,   981,   982,
     983,  1047,   413,  1055,     3,     3,   441,  1175,   991,    84,
     825,   648,   827,   650,    -1,    -1,    -1,    -1,    -1,    94,
    1572,   658,   659,    -1,    -1,    -1,  1578,   102,   103,   104,
     180,    -1,    -1,   108,   109,   110,   111,    -1,    -1,  1591,
     855,   856,   857,   858,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,   694,  1041,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1620,    -1,
      -1,    -1,    -1,  1056,    -1,     6,    -1,    -1,    -1,  1062,
      -1,    -1,    -1,    -1,    -1,  1068,    -1,  1070,  1071,   904,
      -1,    -1,  1075,    -1,    -1,    -1,    -1,  1080,  1081,  1082,
      -1,   738,    -1,   740,    -1,   180,    -1,    -1,   745,   746,
     747,   748,    -1,    -1,  1097,    -1,   753,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,  1112,
      -1,    -1,   171,  1116,    -1,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
       3,     4,    -1,   171,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,  1168,    -1,  1170,   825,    -1,
     827,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   855,   856,
     857,   858,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,  1224,  1225,  1226,  1227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    -1,    72,    -1,    -1,   904,    -1,    77,
      78,    -1,    80,    81,    82,    -1,  1259,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,     6,   139,    -1,    -1,  1272,
      -1,    -1,    -1,   146,   147,   148,  1279,    -1,    -1,    -1,
      -1,    -1,    -1,  1118,     6,    -1,    -1,    -1,    -1,   162,
     163,   119,   120,   121,   167,    -1,    -1,    -1,  1301,   172,
      -1,    -1,   175,    -1,   177,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,  1322,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,   180,  1356,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    -1,    84,
      -1,    -1,    61,    -1,    -1,    64,    -1,    -1,    67,    94,
      69,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
      -1,  1394,    81,   108,   109,   110,   111,    -1,    -1,    88,
      89,    90,    91,    92,    -1,    -1,    -1,    96,    -1,    -1,
      99,  1414,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,  1431,    -1,
     171,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,  1118,    -1,    -1,    -1,   180,    -1,    -1,    -1,     6,
      -1,    -1,    -1,   162,   163,    -1,    -1,    -1,   167,  1482,
      -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,   177,    -1,
     179,   180,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       6,    -1,    -1,    -1,    -1,  1538,    -1,  1540,    45,    46,
      47,    -1,  1377,    -1,    -1,    -1,    53,    54,    -1,    -1,
      -1,    84,    -1,    -1,    61,    -1,    -1,    64,    -1,    -1,
      67,    94,    69,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,    -1,    -1,    81,   108,   109,   110,   111,    -1,
    1415,    88,    89,    90,    91,    92,    -1,    -1,    -1,    96,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1257,  1436,    -1,    -1,  1261,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1618,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,   139,    -1,   171,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,
     167,     6,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,   180,    -1,    -1,    -1,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,  1529,   171,  1531,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1361,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
    1377,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     6,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,  1591,    -1,  1415,    51,
      52,    53,    54,    84,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    64,    -1,    -1,    67,    -1,    69,    -1,  1436,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,    -1,    -1,    -1,    96,    -1,    -1,    99,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,   139,   140,   141,
     171,    -1,    -1,    -1,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,  1529,    -1,  1531,   167,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,    -1,   177,    -1,   179,    -1,    -1,
      -1,    -1,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,  1572,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,  1591,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    64,    -1,    -1,    67,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    -1,    -1,    -1,    96,    -1,    -1,
      99,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    45,    46,    47,    -1,   146,   147,   148,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    64,   162,   163,    67,    -1,    69,   167,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,   177,    81,
     179,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,    -1,    -1,    -1,    96,    -1,    -1,    99,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      45,    46,    47,    -1,   146,   147,   148,    -1,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    64,
     162,   163,    67,    -1,    69,   167,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,    -1,   177,    81,   179,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    92,    -1,    -1,
      -1,    96,    -1,    -1,    99,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    45,    46,    47,
      -1,   146,   147,   148,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    64,   162,   163,    67,
      -1,    69,   167,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,    -1,   177,    81,   179,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    96,    -1,
      -1,    99,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    45,    46,    47,    -1,   146,   147,
     148,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    64,   162,   163,    67,    -1,    69,   167,
      -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,   177,
      81,   179,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    45,    46,    47,    -1,   146,   147,   148,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      64,   162,   163,    67,    -1,    69,   167,    -1,    -1,    -1,
      -1,   172,    -1,    -1,    -1,    -1,   177,    81,   179,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,    -1,
      -1,    -1,    96,    -1,    -1,    99,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,    45,    46,
      47,    -1,   146,   147,   148,    -1,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    12,    13,    64,   162,   163,
      67,    -1,    69,   167,    -1,    -1,    -1,    -1,   172,    -1,
      -1,    -1,    -1,   177,    81,   179,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,    92,    -1,    -1,    -1,    96,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    78,    -1,    80,    81,    82,     6,    -1,    -1,    86,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,
     167,    -1,   119,   120,   121,   172,    -1,     3,     4,     5,
     177,    -1,   179,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    51,    52,    53,    54,     3,
       4,     5,    -1,   180,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    12,    13,    -1,    51,    52,    53,
      54,    -1,    -1,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,    -1,    -1,    -1,    -1,
     146,   147,   148,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    -1,    72,    -1,   162,   163,    -1,    77,
      78,   167,    80,    81,    82,    -1,   172,    -1,    86,    -1,
      -1,   177,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,    -1,    -1,
      -1,    -1,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   120,   121,    -1,    -1,    -1,    -1,   162,   163,
      -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,   172,    -1,
       3,     4,     5,   177,    -1,   179,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,     3,     4,    51,    52,
      53,    54,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    53,    54,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,    -1,
      45,    46,    47,   146,   147,   148,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     163,    -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,    -1,   177,    -1,   179,    -1,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,
     167,    -1,    -1,    -1,    -1,   172,    -1,    -1,   175,    -1,
     177,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,    -1,
      -1,    -1,   167,    -1,    -1,    -1,    -1,   172,    -1,     3,
       4,    -1,   177,    -1,   179,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,     3,     4,    -1,    -1,    53,
      54,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    64,    -1,    -1,    67,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    92,   139,    -1,    -1,    96,    -1,
      -1,    99,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
      -1,     6,    -1,   167,    -1,    -1,    -1,    -1,   172,    -1,
      -1,    -1,    -1,   177,    -1,   179,    -1,    -1,    -1,    -1,
       6,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,   167,
       3,     4,     5,    -1,   172,    -1,     9,    10,    11,   177,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,     3,     4,    51,    52,
      53,    54,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    53,    54,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,   171,   139,   140,   141,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     163,    -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    12,    13,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,     6,    12,    13,
      -1,    -1,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,
     167,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,
     177,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     7,    72,    -1,    12,    13,    -1,    77,    78,    -1,
      80,    81,    82,    -1,    -1,    -1,    86,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    -1,    72,     8,
      12,    13,    -1,    77,    78,    -1,    80,    81,    82,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    -1,    72,     7,     8,    -1,    -1,    77,
      78,    -1,    80,    81,    82,   119,   120,   121,    86,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     8,
      72,    -1,    -1,    -1,    -1,    77,    78,    -1,    80,    81,
      82,    -1,    -1,    -1,    86,    -1,    -1,    -1,     8,    -1,
     180,   119,   120,   121,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,     8,    -1,
      -1,    -1,   171,    -1,    -1,    -1,   180,   119,   120,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,     8,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,
      -1,    -1,   180,    -1,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,     8,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,   171,    -1,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,     0,     1,
      -1,   171,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    37,    38,   178,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    56,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,   105,   106,   107,    -1,    -1,    -1,    -1,
      -1,   113,     4,    -1,    -1,    -1,   118,   119,   120,   121,
      12,    13,   124,    -1,   126,    -1,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
     142,   143,   144,   145,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    56,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,   105,   106,   107,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,    -1,   124,    -1,   126,    -1,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
     142,   143,   144,   145,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,   178,
      -1,   180,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,   178,    -1,   180,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
     173,    -1,    -1,    -1,    -1,   178,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,   178,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,   178,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,   178,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,   178,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,   178,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,   178,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,   175,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,
      -1,   175,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,   175,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,   171,    -1,    -1,    -1,   175,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
     175,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,   175,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,   175,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,   175,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,
      -1,   175,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,   175,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,   171,    -1,    -1,    -1,   175,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
     175,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,   175,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,   175,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,   175,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,
      -1,   175,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,   175,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,   171,    -1,    -1,    -1,   175,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
     175,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,   175,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,   175,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,   175,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,
      -1,   175,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,   175,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,   171,    -1,   173,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,   173,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,   171,    -1,   173,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,   173,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,   173,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
     173,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,
      -1,   173,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,   173,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,   171,    -1,   173,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,   173,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,   171,    -1,   173,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,   173,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,   171,    -1,   173,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,   173,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,   173,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
     173,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,
      -1,   173,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,   173,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,   171,    -1,   173,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,   173,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,   171,    -1,   173,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,   173,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,   171,    -1,   173,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,   173,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,   173,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
     173,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,
      -1,   173,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,   173,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,   171,    -1,   173,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,   173,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,   171,    -1,   173,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,   173,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,   171,    -1,   173,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,   173,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,   173,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
     173,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,
      -1,   173,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,   173,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,   171,    -1,   173,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,   173,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,   171,    -1,   173,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,   173,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,   171,    -1,   173,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,   173,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,   173,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
     173,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,
      -1,   173,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
     171,    -1,   173,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,   171,    -1,   173,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,   171,    -1,   173,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,   171,    -1,   173,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,   171,    -1,   173,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,   171,    -1,   173,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,   171,    -1,   173,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,   173,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,   171,    -1,
     173,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,   171
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   183,   184,     6,     0,     4,    12,    13,    37,
      38,    48,    49,    50,    55,    56,    57,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   105,   106,
     107,   113,   118,   119,   120,   121,   124,   126,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   142,
     143,   144,   145,   185,   187,   188,   206,   220,   225,   228,
     229,   230,   231,   232,   233,   234,   254,   255,   256,   257,
     273,   274,     3,     4,     5,     9,    10,    11,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    51,
      52,    53,    54,   133,   139,   140,   141,   146,   147,   148,
     162,   163,   167,   172,   174,   176,   177,   179,   181,   258,
     259,   270,   271,   274,    13,    67,   172,   172,     6,   179,
       6,     6,     6,     6,     6,   174,   174,   172,   179,   172,
     172,     4,   172,   179,   172,   172,     4,   179,   172,   172,
      71,    67,    67,     6,   179,    61,    64,    67,    67,    67,
      64,    67,    69,    69,    61,    64,    67,    69,    64,    67,
      69,    64,    67,   172,    64,   124,   137,   138,   179,   162,
     163,   172,   179,   260,   261,   260,   179,    61,    64,    67,
     179,   260,     4,    61,    65,    77,    67,    69,    67,    64,
       4,   133,   179,     4,     6,    61,    64,    67,    64,    67,
       4,     4,     4,     4,     5,    36,    61,    64,    67,    69,
      81,   163,   172,   179,   225,   234,   258,   263,   264,   265,
     274,     4,   172,   172,   172,     4,   179,   267,     4,   172,
     172,     6,     6,   174,     4,     4,     5,   179,     5,   179,
       4,   258,     6,   172,   179,   181,     7,   149,   150,   151,
     152,   169,   170,   204,   205,     4,   174,   176,   172,   174,
     172,   174,   172,   174,   172,   174,   172,   174,   172,   174,
     172,   174,   172,   174,   172,   174,   172,   174,   172,   174,
     172,   174,   172,   174,   172,   174,   172,   174,   172,   174,
     172,   174,   172,   174,   172,   174,   172,   174,   172,   174,
     172,   174,   172,   174,   172,   174,   172,   174,   172,   172,
     172,   172,   172,   172,     7,   172,   172,   172,   258,   258,
     258,   179,   258,   175,   179,   258,     4,   124,   125,     4,
       4,   225,   226,   227,   179,     6,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     171,   179,     6,   205,     6,   258,     4,   270,   271,   274,
     270,   258,   208,   211,   258,   163,   258,   265,   266,   258,
     258,   172,   258,   266,   258,   258,   172,   266,   258,   258,
     263,   172,   179,   266,   264,   264,   264,   172,   172,   264,
     264,   264,   172,   221,   222,   223,   224,   172,   172,   172,
     263,   258,     4,   263,   267,   179,   179,   260,   260,   260,
     258,   258,   162,   163,   179,   179,   260,   179,   179,   179,
     162,   163,   172,   227,   260,   179,   172,   179,   172,   172,
     172,   264,   264,   263,   172,     4,     6,   174,   174,   227,
       6,   179,   179,   179,   264,   264,   174,   174,   174,   172,
     174,   176,   174,     5,   179,     5,     5,     5,    61,    64,
      67,    69,   179,   258,   265,   258,   180,   266,     8,   164,
       6,     6,   258,   258,   258,   176,   258,   179,   127,   258,
     258,   258,     6,     6,   227,     6,   227,   174,     6,   263,
     263,   179,   271,   263,     6,   174,   258,     4,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   270,   272,   272,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   272,   258,   270,   270,   270,   266,
     173,     7,   204,   266,   175,     7,   204,   205,   176,     7,
     174,   180,    61,    64,    67,    69,   220,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   189,     6,   174,   176,   173,   178,   173,
     178,   178,   175,   178,   207,   175,   207,   173,   164,   178,
     180,   173,   173,   258,   173,   180,   173,   173,   258,   180,
     173,   173,     7,   258,   258,   180,     6,     6,     6,   258,
     258,     7,     7,   252,   252,   258,   172,   172,   172,   172,
     258,   258,   258,     7,   179,   173,     6,   179,   227,   227,
     178,   178,   178,   260,   260,   226,   226,   178,   258,   258,
     258,   258,   238,   178,   227,   258,   258,   258,   258,   258,
       7,   253,     6,     7,   258,     6,   258,   258,   180,   266,
     266,   266,     6,     6,   258,   258,   258,   173,   179,   175,
     179,   258,     4,     4,   258,   179,   179,   179,   179,   266,
     173,   180,   258,   179,   258,   265,   173,   173,   173,   124,
     178,   227,   179,     8,   173,   175,   180,   180,   173,   178,
     180,   258,     6,     6,   258,   175,   205,   173,   175,   173,
     175,   173,   175,   173,   175,   173,   175,   173,   175,   173,
     175,   173,   175,   173,   175,   173,   175,   173,   175,   178,
     178,   173,   175,   173,   175,   173,   175,   173,   175,   173,
     175,   173,   175,   173,   175,   178,   178,   178,   178,   178,
     178,   173,   178,   175,   173,   178,   175,   178,   178,   178,
     173,   173,   178,   178,   178,   173,     6,   178,   173,   178,
     180,   204,   263,   180,   176,   204,   205,   271,   258,     6,
       4,     4,   179,   268,   175,   179,   179,   179,   179,   180,
       8,     4,   114,   115,   116,   117,   180,   192,   196,   199,
     201,   202,   258,     4,     6,   159,   186,   266,     6,   266,
     258,     6,     4,   274,     6,   270,     7,   258,   265,   127,
       7,     7,   173,     7,   127,     7,     7,   173,   127,     7,
       7,   258,   173,   180,   179,   173,   173,   258,   263,     4,
     251,     6,   173,   217,   258,   271,   217,   217,   217,   173,
     173,   173,   263,   266,   176,   227,   180,   180,   260,   258,
     258,   180,   180,   258,   260,   178,   178,   178,    84,    94,
     102,   103,   104,   108,   109,   110,   111,   248,   249,   260,
     180,   235,   173,   180,   173,   173,   173,   258,     6,   258,
     173,   175,   175,   180,   180,   180,   175,   175,   178,   266,
     266,   175,   175,   180,   266,   266,   266,   266,   180,     8,
     266,     7,     7,     7,   176,   258,   180,   258,   258,     7,
     176,   179,   263,     6,   180,   175,   176,   205,   270,   258,
     258,   258,   258,   258,   258,   258,   258,   270,   266,   266,
     270,   270,   270,   270,   270,   258,   270,   173,   258,     6,
     175,     4,   124,   125,   258,     6,     6,     6,     7,   174,
     267,   269,     6,   266,   266,   266,   266,   258,   193,   172,
     172,   179,   203,     6,   175,   159,   270,   173,   173,   178,
       7,   260,    67,    69,   263,   263,     7,   263,    67,    69,
     263,   263,     7,    69,   263,   263,     6,     7,     7,   266,
       7,     7,    84,   250,     6,     7,   173,   173,   173,   173,
       7,     7,     7,     6,   180,     4,   180,   178,   178,   178,
     180,   180,   260,   260,   260,     4,     6,   179,     6,   172,
       6,   112,     6,   112,     6,   112,     6,   112,   180,   249,
     178,   248,     7,     6,     7,     7,     7,     6,   179,     6,
       6,     6,    67,   258,     6,     6,   258,   180,   180,   176,
     180,   180,   180,   180,   258,   180,   263,   263,   263,     4,
     178,     8,     8,   173,     4,     4,   263,   180,     6,     4,
       6,   173,   175,   173,   175,   173,   175,   173,   175,   173,
     175,   173,   175,   178,   173,   173,   173,   173,   204,     6,
     204,     7,   204,   205,   176,     7,     6,   267,   258,   178,
     180,   180,   180,   180,   180,   172,   258,   258,   262,   263,
     179,   176,     6,     6,   186,     6,   258,   179,   258,   271,
       6,   179,   179,    77,   219,   219,   263,     6,   179,   179,
       6,     6,   263,   179,     6,     6,     5,   263,   180,   263,
     263,     4,     6,   263,     7,     7,     7,     7,   263,   263,
     263,     7,     6,     7,   258,   258,   258,   179,   179,   178,
     180,   178,   180,   178,   180,   174,   258,   263,   258,     6,
       6,     6,     6,   258,   260,   180,     5,   179,   263,   179,
     179,   179,   263,   266,   179,     6,   175,   173,   175,     4,
       6,     6,   123,   258,   258,   258,     6,     6,     7,   178,
       6,   205,   270,   263,   263,   271,   258,     6,     4,   268,
       6,   175,   267,     6,     6,     6,     6,   190,   258,   178,
     178,   178,   180,   191,   258,     4,   270,   178,   258,   271,
     258,   258,   260,     6,     6,     6,   258,   258,     6,   258,
       5,     6,   179,     6,   127,   218,   258,     6,   263,   263,
     263,   263,     6,     4,     6,     6,   258,   258,   271,   180,
     173,   178,   180,   226,   226,   260,     6,   239,   260,     6,
     240,   260,     6,   241,   258,   180,   178,   173,   180,   178,
       6,   163,   260,     6,   262,   260,   260,     6,   180,   258,
       6,   263,   178,   180,     8,   180,   173,   179,   258,   271,
     263,   173,     6,     6,     6,     6,     7,     6,   176,   173,
     178,   258,   258,   263,   179,   178,   180,     6,   258,   209,
     210,   180,   180,   180,   180,   180,     5,   262,    65,     6,
       6,     6,     6,     6,   179,   179,     6,     6,   179,   258,
     180,   180,   178,   179,   178,   179,   178,   179,   175,     6,
     263,     7,   179,   258,   178,   180,   178,   178,     6,   180,
     122,   258,   258,   266,     6,     6,   180,   267,   125,   194,
     258,   178,   178,   262,   258,     6,   178,   213,   215,     6,
       6,     6,     6,     6,     6,   180,   179,   262,   266,   226,
     178,   180,   258,   260,   248,   258,   260,   248,   258,   260,
     248,     6,   178,   180,   263,   227,   180,   260,     6,   266,
     260,   258,   180,   180,   180,     6,     6,   179,   258,   258,
     180,   258,   178,   180,   214,   178,   180,   216,   179,   258,
     180,   180,   180,   258,   180,   178,   180,   180,   178,   180,
     180,   178,   180,   263,     6,    84,   180,   236,   179,   178,
     180,   178,     6,     6,   191,   173,   178,     6,   179,   178,
       4,     4,   258,   180,     6,     6,   180,     6,   242,   258,
       6,     6,   243,   258,     6,     6,   244,   258,     6,   180,
     258,   248,   227,   266,     6,   260,   266,   180,   197,   258,
     262,   258,   179,   263,   271,   179,   258,   271,   178,   179,
     180,   179,   180,   179,   180,     6,     6,   180,   180,   237,
     180,   178,   180,     6,   179,   173,   180,   180,   212,   258,
     272,   258,   248,     6,   245,   248,     6,   246,   248,     6,
     247,   248,     6,   266,     6,   195,   270,   200,   179,     6,
     178,   180,     7,   180,   180,   180,   179,   180,   179,   180,
     179,   180,   180,   178,   180,   179,   262,   258,   271,     6,
       6,   248,     6,   248,     6,   248,     6,   270,     6,   198,
     270,   180,     7,   180,   180,   180,   178,   180,     6,   271,
       6,     6,     6,   270,     6
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
#line 173 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 184 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 185 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 186 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 187 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 188 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 189 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 190 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 191 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 192 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 193 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 194 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 195 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 196 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 197 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 198 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 203 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 22:
#line 207 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 23:
#line 214 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 24:
#line 219 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 25:
#line 224 "Gmsh.y"
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
#line 238 "Gmsh.y"
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
#line 251 "Gmsh.y"
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
#line 264 "Gmsh.y"
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
#line 292 "Gmsh.y"
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
#line 306 "Gmsh.y"
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
#line 319 "Gmsh.y"
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
#line 332 "Gmsh.y"
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
#line 350 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 39:
#line 364 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 40:
#line 366 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 41:
#line 371 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 42:
#line 373 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 43:
#line 378 "Gmsh.y"
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
#line 482 "Gmsh.y"
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
#line 492 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 46:
#line 501 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 47:
#line 508 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 48:
#line 518 "Gmsh.y"
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
#line 527 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 50:
#line 536 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 51:
#line 543 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 52:
#line 553 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 53:
#line 561 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 54:
#line 571 "Gmsh.y"
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
#line 590 "Gmsh.y"
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
#line 609 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 57:
#line 615 "Gmsh.y"
    {
    ;}
    break;

  case 58:
#line 622 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 59:
#line 623 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 60:
#line 624 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 61:
#line 625 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 62:
#line 626 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 63:
#line 630 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 64:
#line 631 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 67:
#line 642 "Gmsh.y"
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
#line 704 "Gmsh.y"
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
#line 734 "Gmsh.y"
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
#line 769 "Gmsh.y"
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
#line 803 "Gmsh.y"
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
#line 851 "Gmsh.y"
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
#line 898 "Gmsh.y"
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
#line 913 "Gmsh.y"
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
#line 929 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 76:
#line 938 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 77:
#line 944 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 78:
#line 953 "Gmsh.y"
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
#line 971 "Gmsh.y"
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
#line 989 "Gmsh.y"
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
#line 998 "Gmsh.y"
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
#line 1010 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 83:
#line 1015 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 84:
#line 1023 "Gmsh.y"
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
#line 1043 "Gmsh.y"
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
#line 1066 "Gmsh.y"
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
#line 1077 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
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
#line 1107 "Gmsh.y"
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
#line 1130 "Gmsh.y"
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
#line 1156 "Gmsh.y"
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
#line 1177 "Gmsh.y"
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
#line 1189 "Gmsh.y"
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
#line 1207 "Gmsh.y"
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
#line 1216 "Gmsh.y"
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
#line 1225 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 100:
#line 1227 "Gmsh.y"
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
#line 1237 "Gmsh.y"
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
#line 1246 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 103:
#line 1248 "Gmsh.y"
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
#line 1262 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 106:
#line 1270 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 107:
#line 1276 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 110:
#line 1288 "Gmsh.y"
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
#line 1299 "Gmsh.y"
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
#line 1314 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 115:
#line 1330 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 116:
#line 1338 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 117:
#line 1347 "Gmsh.y"
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
#line 1365 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 119:
#line 1369 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 120:
#line 1379 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 121:
#line 1383 "Gmsh.y"
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
#line 1395 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 123:
#line 1399 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 124:
#line 1409 "Gmsh.y"
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
#line 1432 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 126:
#line 1436 "Gmsh.y"
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
#line 1452 "Gmsh.y"
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
#line 1474 "Gmsh.y"
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
#line 1492 "Gmsh.y"
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
#line 1513 "Gmsh.y"
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
#line 1531 "Gmsh.y"
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
#line 1561 "Gmsh.y"
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
#line 1591 "Gmsh.y"
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
#line 1609 "Gmsh.y"
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
#line 1627 "Gmsh.y"
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
#line 1653 "Gmsh.y"
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
#line 1671 "Gmsh.y"
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
#line 1689 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 139:
#line 1693 "Gmsh.y"
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
#line 1712 "Gmsh.y"
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
#line 1730 "Gmsh.y"
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
#line 1769 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 143:
#line 1775 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 144:
#line 1781 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 145:
#line 1788 "Gmsh.y"
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
#line 1813 "Gmsh.y"
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
#line 1838 "Gmsh.y"
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
#line 1855 "Gmsh.y"
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
#line 1875 "Gmsh.y"
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
#line 1908 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 151:
#line 1912 "Gmsh.y"
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
#line 1932 "Gmsh.y"
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
#line 1950 "Gmsh.y"
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
#line 1967 "Gmsh.y"
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
#line 1983 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 156:
#line 1987 "Gmsh.y"
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
#line 2009 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 158:
#line 2014 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 159:
#line 2019 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 160:
#line 2024 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 161:
#line 2029 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 162:
#line 2034 "Gmsh.y"
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
#line 2057 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 164:
#line 2063 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 165:
#line 2073 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 166:
#line 2074 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 167:
#line 2079 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 168:
#line 2083 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
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
#line 2110 "Gmsh.y"
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
#line 2133 "Gmsh.y"
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
#line 2156 "Gmsh.y"
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
#line 2184 "Gmsh.y"
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
#line 2205 "Gmsh.y"
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
#line 2232 "Gmsh.y"
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
#line 2253 "Gmsh.y"
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
#line 2274 "Gmsh.y"
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
#line 2294 "Gmsh.y"
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
#line 2406 "Gmsh.y"
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
#line 2425 "Gmsh.y"
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
#line 2464 "Gmsh.y"
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
#line 2572 "Gmsh.y"
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
#line 2581 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 184:
#line 2587 "Gmsh.y"
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
#line 2602 "Gmsh.y"
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
#line 2630 "Gmsh.y"
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
#line 2647 "Gmsh.y"
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
#line 2656 "Gmsh.y"
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
#line 2670 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 190:
#line 2676 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 191:
#line 2682 "Gmsh.y"
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
#line 2691 "Gmsh.y"
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
#line 2700 "Gmsh.y"
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
#line 2709 "Gmsh.y"
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
#line 2723 "Gmsh.y"
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
#line 2776 "Gmsh.y"
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
#line 2793 "Gmsh.y"
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
#line 2808 "Gmsh.y"
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
#line 2827 "Gmsh.y"
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
#line 2839 "Gmsh.y"
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
#line 2863 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 202:
#line 2867 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 203:
#line 2872 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 204:
#line 2879 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 205:
#line 2885 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 206:
#line 2890 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 207:
#line 2896 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 208:
#line 2904 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 209:
#line 2908 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 210:
#line 2912 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 211:
#line 2918 "Gmsh.y"
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
#line 2972 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    ;}
    break;

  case 213:
#line 2985 "Gmsh.y"
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
#line 3002 "Gmsh.y"
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
#line 3019 "Gmsh.y"
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
#line 3040 "Gmsh.y"
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
#line 3061 "Gmsh.y"
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
#line 3096 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 219:
#line 3104 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 220:
#line 3110 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 221:
#line 3117 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 222:
#line 3121 "Gmsh.y"
    {
    ;}
    break;

  case 223:
#line 3130 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 224:
#line 3138 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 225:
#line 3146 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 226:
#line 3154 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 227:
#line 3160 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 228:
#line 3168 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 229:
#line 3174 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 230:
#line 3182 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 231:
#line 3188 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 232:
#line 3196 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 233:
#line 3202 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 234:
#line 3210 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 235:
#line 3217 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 236:
#line 3224 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 237:
#line 3231 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 238:
#line 3238 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 239:
#line 3245 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 240:
#line 3252 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 241:
#line 3259 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 242:
#line 3266 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 243:
#line 3273 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 244:
#line 3279 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 245:
#line 3286 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 246:
#line 3292 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 247:
#line 3299 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 248:
#line 3305 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 249:
#line 3312 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 250:
#line 3318 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 251:
#line 3325 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 252:
#line 3331 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 253:
#line 3338 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 254:
#line 3344 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 255:
#line 3351 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 256:
#line 3357 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 257:
#line 3364 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 258:
#line 3370 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 259:
#line 3377 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 260:
#line 3383 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 261:
#line 3394 "Gmsh.y"
    {
    ;}
    break;

  case 262:
#line 3397 "Gmsh.y"
    {
    ;}
    break;

  case 263:
#line 3403 "Gmsh.y"
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
#line 3415 "Gmsh.y"
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
#line 3435 "Gmsh.y"
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
#line 3459 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 267:
#line 3464 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 268:
#line 3468 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 269:
#line 3472 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 270:
#line 3476 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, which has no requirement for the number of extrusion layers and meshes with body-centered vertices.");
    ;}
    break;

  case 271:
#line 3480 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, which has no requirement for the number of extrusion layers and meshes with body-centered vertices.");
    ;}
    break;

  case 272:
#line 3484 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 273:
#line 3488 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 274:
#line 3492 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 275:
#line 3496 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 276:
#line 3500 "Gmsh.y"
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
#line 3519 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 278:
#line 3531 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 279:
#line 3535 "Gmsh.y"
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
#line 3550 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 281:
#line 3554 "Gmsh.y"
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
#line 3570 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 283:
#line 3574 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 284:
#line 3579 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 285:
#line 3583 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 286:
#line 3590 "Gmsh.y"
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
#line 3646 "Gmsh.y"
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
#line 3716 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 289:
#line 3721 "Gmsh.y"
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
#line 3788 "Gmsh.y"
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
#line 3824 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 292:
#line 3832 "Gmsh.y"
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
#line 3875 "Gmsh.y"
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
#line 3914 "Gmsh.y"
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
#line 3934 "Gmsh.y"
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
#line 3962 "Gmsh.y"
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
#line 4001 "Gmsh.y"
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
#line 4024 "Gmsh.y"
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
#line 4047 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    ;}
    break;

  case 300:
#line 4051 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 301:
#line 4055 "Gmsh.y"
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
#line 4078 "Gmsh.y"
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
#line 4117 "Gmsh.y"
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
#line 4156 "Gmsh.y"
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
#line 4177 "Gmsh.y"
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
#line 4198 "Gmsh.y"
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
#line 4225 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 308:
#line 4229 "Gmsh.y"
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
#line 4239 "Gmsh.y"
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
#line 4273 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 311:
#line 4274 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 312:
#line 4275 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 313:
#line 4280 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 314:
#line 4286 "Gmsh.y"
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
#line 4298 "Gmsh.y"
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
#line 4316 "Gmsh.y"
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
#line 4343 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 318:
#line 4344 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 319:
#line 4345 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 320:
#line 4346 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 321:
#line 4347 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 322:
#line 4348 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 323:
#line 4349 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 324:
#line 4350 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 325:
#line 4352 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 326:
#line 4358 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 327:
#line 4359 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 328:
#line 4360 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 329:
#line 4361 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 330:
#line 4362 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 331:
#line 4363 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 332:
#line 4364 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 333:
#line 4365 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 334:
#line 4366 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 335:
#line 4367 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 336:
#line 4368 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 337:
#line 4369 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 338:
#line 4370 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 339:
#line 4371 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 340:
#line 4372 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 341:
#line 4373 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 342:
#line 4374 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 343:
#line 4375 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 344:
#line 4376 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 345:
#line 4377 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 346:
#line 4378 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 347:
#line 4379 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 348:
#line 4380 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 349:
#line 4381 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 350:
#line 4382 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 351:
#line 4383 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 352:
#line 4384 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 353:
#line 4385 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 354:
#line 4386 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 355:
#line 4387 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 356:
#line 4388 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 357:
#line 4389 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 358:
#line 4390 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 359:
#line 4393 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 360:
#line 4394 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 361:
#line 4395 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 362:
#line 4396 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 363:
#line 4397 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 364:
#line 4398 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 365:
#line 4399 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 366:
#line 4400 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 367:
#line 4401 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 368:
#line 4402 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 369:
#line 4403 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 370:
#line 4404 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 371:
#line 4405 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 372:
#line 4406 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 373:
#line 4407 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 374:
#line 4408 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 375:
#line 4409 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 376:
#line 4410 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5);    ;}
    break;

  case 377:
#line 4411 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 378:
#line 4412 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 379:
#line 4413 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 380:
#line 4414 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 381:
#line 4423 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 382:
#line 4424 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 383:
#line 4425 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 384:
#line 4426 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 385:
#line 4427 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 386:
#line 4428 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 387:
#line 4429 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 388:
#line 4430 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 389:
#line 4431 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 390:
#line 4436 "Gmsh.y"
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

  case 391:
#line 4454 "Gmsh.y"
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

  case 392:
#line 4472 "Gmsh.y"
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

  case 393:
#line 4484 "Gmsh.y"
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

  case 394:
#line 4501 "Gmsh.y"
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

  case 395:
#line 4522 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 396:
#line 4527 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 397:
#line 4532 "Gmsh.y"
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

  case 398:
#line 4542 "Gmsh.y"
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

  case 399:
#line 4552 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 400:
#line 4557 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 401:
#line 4566 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 402:
#line 4571 "Gmsh.y"
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

  case 403:
#line 4598 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 404:
#line 4602 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 405:
#line 4606 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 406:
#line 4610 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 407:
#line 4614 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 408:
#line 4621 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 409:
#line 4625 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 410:
#line 4629 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 411:
#line 4633 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 412:
#line 4640 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 413:
#line 4645 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 414:
#line 4652 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 415:
#line 4657 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 416:
#line 4661 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 417:
#line 4666 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 418:
#line 4670 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 419:
#line 4678 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 420:
#line 4689 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 421:
#line 4693 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 422:
#line 4705 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 423:
#line 4713 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 424:
#line 4721 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 425:
#line 4728 "Gmsh.y"
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

  case 426:
#line 4738 "Gmsh.y"
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

  case 427:
#line 4758 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 428:
#line 4762 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 429:
#line 4766 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 430:
#line 4770 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 431:
#line 4774 "Gmsh.y"
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

  case 432:
#line 4803 "Gmsh.y"
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

  case 433:
#line 4832 "Gmsh.y"
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

  case 434:
#line 4861 "Gmsh.y"
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

  case 435:
#line 4890 "Gmsh.y"
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

  case 436:
#line 4900 "Gmsh.y"
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

  case 437:
#line 4910 "Gmsh.y"
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

  case 438:
#line 4923 "Gmsh.y"
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

  case 439:
#line 4935 "Gmsh.y"
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

  case 440:
#line 4947 "Gmsh.y"
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

  case 441:
#line 4966 "Gmsh.y"
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

  case 442:
#line 4987 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 443:
#line 4992 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 444:
#line 4996 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 445:
#line 5000 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 446:
#line 5012 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 447:
#line 5016 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 448:
#line 5028 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 449:
#line 5035 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 450:
#line 5045 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 451:
#line 5049 "Gmsh.y"
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

  case 452:
#line 5064 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 453:
#line 5069 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 454:
#line 5076 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 455:
#line 5080 "Gmsh.y"
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

  case 456:
#line 5093 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 457:
#line 5101 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 458:
#line 5112 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 459:
#line 5116 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 460:
#line 5124 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 461:
#line 5130 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 462:
#line 5138 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 463:
#line 5146 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 464:
#line 5155 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 465:
#line 5163 "Gmsh.y"
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

  case 466:
#line 5177 "Gmsh.y"
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

  case 467:
#line 5191 "Gmsh.y"
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

  case 468:
#line 5203 "Gmsh.y"
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

  case 469:
#line 5220 "Gmsh.y"
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

  case 470:
#line 5236 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 471:
#line 5241 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 472:
#line 5245 "Gmsh.y"
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

  case 473:
#line 5265 "Gmsh.y"
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

  case 474:
#line 5287 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 475:
#line 5292 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 476:
#line 5298 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 477:
#line 5307 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 478:
#line 5320 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 479:
#line 5323 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 10805 "Gmsh.tab.cpp"
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


#line 5327 "Gmsh.y"


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

