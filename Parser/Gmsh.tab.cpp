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
     tFileExists = 403,
     tGMSH_MAJOR_VERSION = 404,
     tGMSH_MINOR_VERSION = 405,
     tGMSH_PATCH_VERSION = 406,
     tAFFECTDIVIDE = 407,
     tAFFECTTIMES = 408,
     tAFFECTMINUS = 409,
     tAFFECTPLUS = 410,
     tOR = 411,
     tAND = 412,
     tNOTEQUAL = 413,
     tEQUAL = 414,
     tGREATEROREQUAL = 415,
     tLESSOREQUAL = 416,
     UNARYPREC = 417,
     tMINUSMINUS = 418,
     tPLUSPLUS = 419
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
#define tFileExists 403
#define tGMSH_MAJOR_VERSION 404
#define tGMSH_MINOR_VERSION 405
#define tGMSH_PATCH_VERSION 406
#define tAFFECTDIVIDE 407
#define tAFFECTTIMES 408
#define tAFFECTMINUS 409
#define tAFFECTPLUS 410
#define tOR 411
#define tAND 412
#define tNOTEQUAL 413
#define tEQUAL 414
#define tGREATEROREQUAL 415
#define tLESSOREQUAL 416
#define UNARYPREC 417
#define tMINUSMINUS 418
#define tPLUSPLUS 419




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
void assignVariable(const std::string &name, int index, int assignType,
                    double value);
void assignVariables(const std::string &name, List_T *indices, int assignType,
                     List_T *values);
 void incrementVariable(const std::string &name, int index, double value);
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
#line 98 "Gmsh.y"
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
#line 539 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 552 "Gmsh.tab.cpp"

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
#define YYLAST   9130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  185
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  487
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1696

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   419

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   170,     2,   180,     2,   169,     2,     2,
     175,   176,   167,   165,   181,   166,   179,   168,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     161,     2,   162,   156,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   177,     2,   178,   174,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   182,     2,   183,   184,     2,     2,     2,
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
     155,   157,   158,   159,   160,   163,   164,   171,   172,   173
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
     286,   294,   302,   312,   322,   332,   336,   343,   350,   355,
     362,   372,   379,   389,   395,   404,   413,   425,   432,   442,
     448,   456,   466,   476,   488,   496,   506,   516,   517,   519,
     520,   524,   530,   531,   541,   547,   548,   558,   559,   563,
     567,   573,   574,   577,   581,   587,   591,   592,   595,   599,
     603,   609,   611,   613,   614,   620,   621,   624,   632,   633,
     643,   650,   658,   663,   671,   680,   689,   697,   705,   717,
     726,   735,   736,   746,   755,   765,   769,   774,   785,   793,
     801,   810,   819,   832,   833,   843,   852,   860,   869,   870,
     880,   886,   898,   904,   914,   924,   929,   939,   949,   951,
     953,   954,   957,   964,   971,   978,   985,   994,  1005,  1020,
    1037,  1050,  1059,  1068,  1075,  1090,  1095,  1102,  1109,  1113,
    1118,  1124,  1131,  1135,  1139,  1144,  1150,  1155,  1161,  1165,
    1173,  1181,  1185,  1193,  1197,  1200,  1203,  1206,  1209,  1225,
    1228,  1231,  1234,  1237,  1240,  1257,  1261,  1268,  1277,  1286,
    1297,  1299,  1302,  1304,  1308,  1313,  1315,  1321,  1333,  1347,
    1348,  1356,  1357,  1371,  1372,  1388,  1389,  1396,  1405,  1414,
    1423,  1436,  1449,  1462,  1477,  1492,  1507,  1508,  1521,  1522,
    1535,  1536,  1549,  1550,  1567,  1568,  1585,  1586,  1603,  1604,
    1623,  1624,  1643,  1644,  1663,  1665,  1668,  1674,  1682,  1692,
    1695,  1698,  1701,  1705,  1708,  1712,  1715,  1719,  1722,  1726,
    1736,  1743,  1744,  1748,  1749,  1751,  1752,  1755,  1756,  1759,
    1767,  1774,  1783,  1789,  1793,  1801,  1807,  1812,  1819,  1826,
    1839,  1850,  1861,  1872,  1883,  1894,  1899,  1904,  1909,  1914,
    1919,  1922,  1926,  1933,  1935,  1937,  1939,  1942,  1948,  1956,
    1967,  1969,  1973,  1976,  1979,  1982,  1986,  1990,  1994,  1998,
    2002,  2006,  2010,  2014,  2018,  2022,  2026,  2030,  2034,  2038,
    2044,  2049,  2054,  2059,  2064,  2069,  2074,  2079,  2084,  2089,
    2094,  2101,  2106,  2111,  2116,  2121,  2126,  2131,  2136,  2143,
    2150,  2157,  2162,  2167,  2172,  2177,  2182,  2187,  2192,  2197,
    2202,  2207,  2212,  2219,  2224,  2229,  2234,  2239,  2244,  2249,
    2254,  2261,  2268,  2275,  2280,  2282,  2284,  2286,  2288,  2290,
    2292,  2294,  2296,  2298,  2300,  2302,  2307,  2312,  2317,  2322,
    2327,  2330,  2336,  2342,  2346,  2353,  2358,  2366,  2373,  2380,
    2387,  2392,  2394,  2397,  2400,  2404,  2408,  2420,  2430,  2438,
    2446,  2448,  2452,  2454,  2456,  2459,  2463,  2468,  2474,  2476,
    2478,  2481,  2485,  2489,  2495,  2500,  2503,  2506,  2509,  2512,
    2518,  2524,  2530,  2536,  2538,  2540,  2544,  2548,  2553,  2560,
    2567,  2569,  2571,  2575,  2579,  2589,  2597,  2599,  2605,  2609,
    2616,  2618,  2622,  2624,  2626,  2630,  2637,  2639,  2641,  2643,
    2648,  2655,  2662,  2669,  2674,  2679,  2688,  2693,  2698,  2703,
    2708,  2715,  2722,  2724,  2728,  2734,  2740,  2742
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     186,     0,    -1,   187,    -1,     1,     6,    -1,    -1,   187,
     188,    -1,   191,    -1,   190,    -1,   209,    -1,   223,    -1,
     228,    -1,   232,    -1,   233,    -1,   234,    -1,   237,    -1,
     257,    -1,   258,    -1,   236,    -1,   235,    -1,   231,    -1,
     260,    -1,   162,    -1,   162,   162,    -1,    37,   175,   273,
     176,     6,    -1,    38,   175,   273,   176,     6,    -1,    37,
     175,   273,   176,   189,   273,     6,    -1,    37,   175,   273,
     181,   269,   176,     6,    -1,    38,   175,   273,   181,   269,
     176,     6,    -1,    37,   175,   273,   181,   269,   176,   189,
     273,     6,    -1,     4,   273,   182,   192,   183,     6,    -1,
     106,     4,   177,   261,   178,     6,    -1,   107,     4,   177,
     261,   178,     6,    -1,   108,     4,   177,   261,   181,   261,
     178,     6,    -1,    -1,   192,   195,    -1,   192,   199,    -1,
     192,   202,    -1,   192,   204,    -1,   192,   205,    -1,   261,
      -1,   193,   181,   261,    -1,   261,    -1,   194,   181,   261,
      -1,    -1,    -1,     4,   196,   175,   193,   176,   197,   182,
     194,   183,     6,    -1,   273,    -1,   198,   181,   273,    -1,
      -1,   115,   175,   261,   181,   261,   181,   261,   176,   200,
     182,   198,   183,     6,    -1,   273,    -1,   201,   181,   273,
      -1,    -1,   116,   175,   261,   181,   261,   181,   261,   181,
     261,   176,   203,   182,   201,   183,     6,    -1,   117,   182,
     265,   183,   182,   265,   183,     6,    -1,   117,   182,   265,
     183,   182,   265,   183,   182,   265,   183,   182,   265,   183,
       6,    -1,    -1,   118,   206,   182,   194,   183,     6,    -1,
       7,    -1,   155,    -1,   154,    -1,   153,    -1,   152,    -1,
     173,    -1,   172,    -1,    60,   177,   211,   178,     6,    -1,
      61,   177,   214,   178,     6,    -1,   277,   207,   266,     6,
      -1,     4,   177,   178,   207,   266,     6,    -1,     4,   177,
     261,   178,   207,   261,     6,    -1,   276,   177,   261,   178,
     207,   261,     6,    -1,     4,   175,   261,   176,   207,   261,
       6,    -1,     4,   177,   182,   269,   183,   178,   207,   266,
       6,    -1,     4,   175,   182,   269,   183,   176,   207,   266,
       6,    -1,   276,   175,   182,   269,   183,   176,   207,   266,
       6,    -1,   277,   208,     6,    -1,     4,   177,   261,   178,
     208,     6,    -1,   276,   177,   261,   178,   208,     6,    -1,
     277,     7,   274,     6,    -1,     4,   179,     4,     7,   274,
       6,    -1,     4,   177,   261,   178,   179,     4,     7,   274,
       6,    -1,     4,   179,     4,   207,   261,     6,    -1,     4,
     177,   261,   178,   179,     4,   207,   261,     6,    -1,     4,
     179,     4,   208,     6,    -1,     4,   177,   261,   178,   179,
       4,   208,     6,    -1,     4,   179,   125,   179,     4,     7,
     270,     6,    -1,     4,   177,   261,   178,   179,   125,   179,
       4,     7,   270,     6,    -1,     4,   179,   126,     7,   271,
       6,    -1,     4,   177,   261,   178,   179,   126,     7,   271,
       6,    -1,     4,   134,     7,   261,     6,    -1,   134,   177,
     261,   178,     7,     4,     6,    -1,   134,   177,   261,   178,
     179,     4,     7,   261,     6,    -1,   134,   177,   261,   178,
     179,     4,     7,   274,     6,    -1,   134,   177,   261,   178,
     179,     4,     7,   182,   269,   183,     6,    -1,   134,   177,
     261,   178,   179,     4,     6,    -1,    86,   175,     4,   176,
     179,     4,     7,   261,     6,    -1,    86,   175,     4,   176,
     179,     4,     7,   274,     6,    -1,    -1,   181,    -1,    -1,
     211,   210,   277,    -1,   211,   210,   277,     7,   261,    -1,
      -1,   211,   210,   277,     7,   182,   261,   212,   216,   183,
      -1,   211,   210,   277,     7,   274,    -1,    -1,   211,   210,
     277,     7,   182,   274,   213,   218,   183,    -1,    -1,   214,
     210,   273,    -1,   261,     7,   274,    -1,   215,   181,   261,
       7,   274,    -1,    -1,   216,   217,    -1,   181,     4,   266,
      -1,   181,     4,   182,   215,   183,    -1,   181,     4,   274,
      -1,    -1,   218,   219,    -1,   181,     4,   261,    -1,   181,
       4,   274,    -1,   181,     4,   182,   275,   183,    -1,   261,
      -1,   274,    -1,    -1,   128,    66,   182,   261,   183,    -1,
      -1,    78,   263,    -1,    62,   175,   261,   176,     7,   263,
       6,    -1,    -1,    82,    62,   224,   175,   220,   176,     7,
     266,     6,    -1,    71,    72,   266,     7,   261,     6,    -1,
      65,   175,   261,   176,     7,   266,     6,    -1,    87,    65,
     266,     6,    -1,    69,   175,   261,   176,     7,   266,     6,
      -1,    63,   175,   261,   176,     7,   266,   222,     6,    -1,
      64,   175,   261,   176,     7,   266,   222,     6,    -1,   120,
     175,   261,   176,     7,   266,     6,    -1,   121,   175,   261,
     176,     7,   266,     6,    -1,   122,   175,   261,   176,     7,
     266,   124,   266,   123,   261,     6,    -1,    65,     4,   175,
     261,   176,     7,   266,     6,    -1,    83,    65,   175,   261,
     176,     7,   266,     6,    -1,    -1,    82,    65,   225,   175,
     220,   176,     7,   266,     6,    -1,    78,    68,   175,   261,
     176,     7,   266,     6,    -1,    79,    68,   175,   261,   176,
       7,   266,   221,     6,    -1,    12,    13,     6,    -1,    13,
      68,   261,     6,    -1,    73,    68,   175,   261,   176,     7,
       5,     5,     5,     6,    -1,    66,   175,   261,   176,     7,
     266,     6,    -1,    67,   175,   261,   176,     7,   266,     6,
      -1,    68,     4,   175,   261,   176,     7,   266,     6,    -1,
      83,    68,   175,   261,   176,     7,   266,     6,    -1,    83,
      68,   175,   261,   176,     7,   266,     4,   182,   265,   183,
       6,    -1,    -1,    82,    68,   226,   175,   220,   176,     7,
     266,     6,    -1,    81,    70,   175,   261,   176,     7,   266,
       6,    -1,    70,   175,   261,   176,     7,   266,     6,    -1,
      83,    70,   175,   261,   176,     7,   266,     6,    -1,    -1,
      82,    70,   227,   175,   220,   176,     7,   266,     6,    -1,
      90,   263,   182,   229,   183,    -1,    89,   182,   263,   181,
     263,   181,   261,   183,   182,   229,   183,    -1,    91,   263,
     182,   229,   183,    -1,    92,   182,   263,   181,   261,   183,
     182,   229,   183,    -1,    92,   182,   263,   181,   263,   183,
     182,   229,   183,    -1,     4,   182,   229,   183,    -1,   100,
      65,   182,   269,   183,    68,   182,   261,   183,    -1,    97,
      65,   175,   261,   176,   182,   269,   183,     6,    -1,   230,
      -1,   228,    -1,    -1,   230,   223,    -1,   230,    62,   182,
     269,   183,     6,    -1,   230,    65,   182,   269,   183,     6,
      -1,   230,    68,   182,   269,   183,     6,    -1,   230,    70,
     182,   269,   183,     6,    -1,    94,    78,   175,   261,   176,
       7,   266,     6,    -1,    94,    62,   175,   261,   176,     7,
     182,   265,   183,     6,    -1,    94,    78,   175,   261,   176,
       7,   182,   263,   181,   263,   181,   269,   183,     6,    -1,
      94,    78,   175,   261,   176,     7,   182,   263,   181,   263,
     181,   263,   181,   269,   183,     6,    -1,    94,    66,   175,
     261,   176,     7,   182,   263,   181,   269,   183,     6,    -1,
      94,     4,   175,   261,   176,     7,   266,     6,    -1,    94,
       4,   175,   261,   176,     7,     5,     6,    -1,    94,     4,
     182,   261,   183,     6,    -1,    94,     4,   175,   261,   176,
       7,   182,   263,   181,   263,   181,   269,   183,     6,    -1,
      98,   182,   230,   183,    -1,    98,   134,   177,   261,   178,
       6,    -1,    98,     4,   177,   261,   178,     6,    -1,    98,
       4,     6,    -1,    98,     4,     4,     6,    -1,   125,   270,
     182,   230,   183,    -1,    88,   125,   270,   182,   230,   183,
      -1,   138,     5,     6,    -1,   139,     5,     6,    -1,   138,
     182,   230,   183,    -1,    88,   138,   182,   230,   183,    -1,
     139,   182,   230,   183,    -1,    88,   139,   182,   230,   183,
      -1,     4,   274,     6,    -1,     4,     4,   177,   261,   178,
     273,     6,    -1,     4,     4,     4,   177,   261,   178,     6,
      -1,     4,   261,     6,    -1,    86,   175,     4,   176,   179,
       4,     6,    -1,   119,     4,     6,    -1,   132,     6,    -1,
     133,     6,    -1,    53,     6,    -1,    48,     6,    -1,    48,
     182,   261,   181,   261,   181,   261,   181,   261,   181,   261,
     181,   261,   183,     6,    -1,    49,     6,    -1,    50,     6,
      -1,    57,     6,    -1,    58,     6,    -1,    75,     6,    -1,
      76,   182,   269,   183,   182,   269,   183,   182,   265,   183,
     182,   261,   181,   261,   183,     6,    -1,   146,   261,     6,
      -1,   127,   175,   261,     8,   261,   176,    -1,   127,   175,
     261,     8,   261,     8,   261,   176,    -1,   127,     4,   128,
     182,   261,     8,   261,   183,    -1,   127,     4,   128,   182,
     261,     8,   261,     8,   261,   183,    -1,   129,    -1,   137,
       4,    -1,   135,    -1,   136,     4,     6,    -1,   130,   175,
     261,   176,    -1,   131,    -1,    93,   263,   182,   230,   183,
      -1,    93,   182,   263,   181,   263,   181,   261,   183,   182,
     230,   183,    -1,    93,   182,   263,   181,   263,   181,   263,
     181,   261,   183,   182,   230,   183,    -1,    -1,    93,   263,
     182,   230,   238,   251,   183,    -1,    -1,    93,   182,   263,
     181,   263,   181,   261,   183,   182,   230,   239,   251,   183,
      -1,    -1,    93,   182,   263,   181,   263,   181,   263,   181,
     261,   183,   182,   230,   240,   251,   183,    -1,    -1,    93,
     182,   230,   241,   251,   183,    -1,    93,    62,   182,   261,
     181,   263,   183,     6,    -1,    93,    65,   182,   261,   181,
     263,   183,     6,    -1,    93,    68,   182,   261,   181,   263,
     183,     6,    -1,    93,    62,   182,   261,   181,   263,   181,
     263,   181,   261,   183,     6,    -1,    93,    65,   182,   261,
     181,   263,   181,   263,   181,   261,   183,     6,    -1,    93,
      68,   182,   261,   181,   263,   181,   263,   181,   261,   183,
       6,    -1,    93,    62,   182,   261,   181,   263,   181,   263,
     181,   263,   181,   261,   183,     6,    -1,    93,    65,   182,
     261,   181,   263,   181,   263,   181,   263,   181,   261,   183,
       6,    -1,    93,    68,   182,   261,   181,   263,   181,   263,
     181,   263,   181,   261,   183,     6,    -1,    -1,    93,    62,
     182,   261,   181,   263,   183,   242,   182,   251,   183,     6,
      -1,    -1,    93,    65,   182,   261,   181,   263,   183,   243,
     182,   251,   183,     6,    -1,    -1,    93,    68,   182,   261,
     181,   263,   183,   244,   182,   251,   183,     6,    -1,    -1,
      93,    62,   182,   261,   181,   263,   181,   263,   181,   261,
     183,   245,   182,   251,   183,     6,    -1,    -1,    93,    65,
     182,   261,   181,   263,   181,   263,   181,   261,   183,   246,
     182,   251,   183,     6,    -1,    -1,    93,    68,   182,   261,
     181,   263,   181,   263,   181,   261,   183,   247,   182,   251,
     183,     6,    -1,    -1,    93,    62,   182,   261,   181,   263,
     181,   263,   181,   263,   181,   261,   183,   248,   182,   251,
     183,     6,    -1,    -1,    93,    65,   182,   261,   181,   263,
     181,   263,   181,   263,   181,   261,   183,   249,   182,   251,
     183,     6,    -1,    -1,    93,    68,   182,   261,   181,   263,
     181,   263,   181,   263,   181,   261,   183,   250,   182,   251,
     183,     6,    -1,   252,    -1,   251,   252,    -1,   103,   182,
     261,   183,     6,    -1,   103,   182,   266,   181,   266,   183,
       6,    -1,   103,   182,   266,   181,   266,   181,   266,   183,
       6,    -1,   104,     6,    -1,    95,     6,    -1,   111,     6,
      -1,   111,   113,     6,    -1,   112,     6,    -1,   112,   113,
       6,    -1,   109,     6,    -1,   109,   113,     6,    -1,   110,
       6,    -1,   110,   113,     6,    -1,   105,   175,   261,   176,
       7,   266,    85,   261,     6,    -1,    85,     4,   177,   261,
     178,     6,    -1,    -1,    85,     4,   261,    -1,    -1,     4,
      -1,    -1,     7,   266,    -1,    -1,     7,   261,    -1,    80,
      65,   267,     7,   261,   253,     6,    -1,    80,    68,   267,
     255,   254,     6,    -1,    74,    68,   182,   261,   183,     7,
     266,     6,    -1,    80,    70,   267,   255,     6,    -1,   114,
     267,     6,    -1,   101,    68,   182,   269,   183,   261,     6,
      -1,    95,    68,   267,   256,     6,    -1,    95,    70,   267,
       6,    -1,    96,    68,   266,     7,   261,     6,    -1,    84,
      65,   266,     7,   266,     6,    -1,    84,    68,   261,   182,
     269,   183,     7,   261,   182,   269,   183,     6,    -1,    62,
     182,   269,   183,   128,    68,   182,   261,   183,     6,    -1,
      65,   182,   269,   183,   128,    68,   182,   261,   183,     6,
      -1,    62,   182,   269,   183,   128,    70,   182,   261,   183,
       6,    -1,    65,   182,   269,   183,   128,    70,   182,   261,
     183,     6,    -1,    68,   182,   269,   183,   128,    70,   182,
     261,   183,     6,    -1,   102,    68,   267,     6,    -1,   102,
      65,   267,     6,    -1,    77,    62,   267,     6,    -1,    77,
      65,   267,     6,    -1,    77,    68,   267,     6,    -1,    99,
       6,    -1,    99,     4,     6,    -1,    99,    62,   182,   269,
     183,     6,    -1,   143,    -1,   144,    -1,   145,    -1,   259,
       6,    -1,   259,   182,   266,   183,     6,    -1,   259,   182,
     266,   181,   266,   183,     6,    -1,   259,   175,   266,   176,
     182,   266,   181,   266,   183,     6,    -1,   262,    -1,   175,
     261,   176,    -1,   166,   261,    -1,   165,   261,    -1,   170,
     261,    -1,   261,   166,   261,    -1,   261,   165,   261,    -1,
     261,   167,   261,    -1,   261,   168,   261,    -1,   261,   169,
     261,    -1,   261,   174,   261,    -1,   261,   161,   261,    -1,
     261,   162,   261,    -1,   261,   164,   261,    -1,   261,   163,
     261,    -1,   261,   160,   261,    -1,   261,   159,   261,    -1,
     261,   158,   261,    -1,   261,   157,   261,    -1,   261,   156,
     261,     8,   261,    -1,    14,   175,   261,   176,    -1,    15,
     175,   261,   176,    -1,    16,   175,   261,   176,    -1,    17,
     175,   261,   176,    -1,    18,   175,   261,   176,    -1,    19,
     175,   261,   176,    -1,    20,   175,   261,   176,    -1,    21,
     175,   261,   176,    -1,    22,   175,   261,   176,    -1,    24,
     175,   261,   176,    -1,    25,   175,   261,   181,   261,   176,
      -1,    26,   175,   261,   176,    -1,    27,   175,   261,   176,
      -1,    28,   175,   261,   176,    -1,    29,   175,   261,   176,
      -1,    30,   175,   261,   176,    -1,    31,   175,   261,   176,
      -1,    32,   175,   261,   176,    -1,    33,   175,   261,   181,
     261,   176,    -1,    34,   175,   261,   181,   261,   176,    -1,
      35,   175,   261,   181,   261,   176,    -1,    23,   175,   261,
     176,    -1,    14,   177,   261,   178,    -1,    15,   177,   261,
     178,    -1,    16,   177,   261,   178,    -1,    17,   177,   261,
     178,    -1,    18,   177,   261,   178,    -1,    19,   177,   261,
     178,    -1,    20,   177,   261,   178,    -1,    21,   177,   261,
     178,    -1,    22,   177,   261,   178,    -1,    24,   177,   261,
     178,    -1,    25,   177,   261,   181,   261,   178,    -1,    26,
     177,   261,   178,    -1,    27,   177,   261,   178,    -1,    28,
     177,   261,   178,    -1,    29,   177,   261,   178,    -1,    30,
     177,   261,   178,    -1,    31,   177,   261,   178,    -1,    32,
     177,   261,   178,    -1,    33,   177,   261,   181,   261,   178,
      -1,    34,   177,   261,   181,   261,   178,    -1,    35,   177,
     261,   181,   261,   178,    -1,    23,   177,   261,   178,    -1,
       3,    -1,     9,    -1,    10,    -1,    11,    -1,   149,    -1,
     150,    -1,   151,    -1,    54,    -1,    55,    -1,    56,    -1,
     277,    -1,     4,   177,   261,   178,    -1,   276,   177,   261,
     178,    -1,   147,   175,   277,   176,    -1,   148,   175,   274,
     176,    -1,   180,   277,   177,   178,    -1,   277,   208,    -1,
       4,   177,   261,   178,   208,    -1,   276,   177,   261,   178,
     208,    -1,     4,   179,     4,    -1,     4,   177,   261,   178,
     179,     4,    -1,     4,   179,     4,   208,    -1,     4,   177,
     261,   178,   179,     4,   208,    -1,   140,   175,   273,   181,
     261,   176,    -1,    45,   175,   273,   181,   273,   176,    -1,
      46,   175,   273,   181,   273,   176,    -1,    47,   175,   275,
     176,    -1,   264,    -1,   166,   263,    -1,   165,   263,    -1,
     263,   166,   263,    -1,   263,   165,   263,    -1,   182,   261,
     181,   261,   181,   261,   181,   261,   181,   261,   183,    -1,
     182,   261,   181,   261,   181,   261,   181,   261,   183,    -1,
     182,   261,   181,   261,   181,   261,   183,    -1,   175,   261,
     181,   261,   181,   261,   176,    -1,   266,    -1,   265,   181,
     266,    -1,   261,    -1,   268,    -1,   182,   183,    -1,   182,
     269,   183,    -1,   166,   182,   269,   183,    -1,   261,   167,
     182,   269,   183,    -1,   266,    -1,     5,    -1,   166,   268,
      -1,   261,   167,   268,    -1,   261,     8,   261,    -1,   261,
       8,   261,     8,   261,    -1,    62,   182,   261,   183,    -1,
      62,     5,    -1,    65,     5,    -1,    68,     5,    -1,    70,
       5,    -1,    82,    62,   182,   269,   183,    -1,    82,    65,
     182,   269,   183,    -1,    82,    68,   182,   269,   183,    -1,
      82,    70,   182,   269,   183,    -1,   228,    -1,   237,    -1,
       4,   177,   178,    -1,     4,   175,   176,    -1,    36,   177,
       4,   178,    -1,     4,   177,   182,   269,   183,   178,    -1,
       4,   175,   182,   269,   183,   176,    -1,   261,    -1,   268,
      -1,   269,   181,   261,    -1,   269,   181,   268,    -1,   182,
     261,   181,   261,   181,   261,   181,   261,   183,    -1,   182,
     261,   181,   261,   181,   261,   183,    -1,     4,    -1,     4,
     179,   125,   179,     4,    -1,   182,   272,   183,    -1,     4,
     177,   261,   178,   179,   126,    -1,   270,    -1,   272,   181,
     270,    -1,   274,    -1,   277,    -1,     4,   179,     4,    -1,
       4,   177,   261,   178,   179,     4,    -1,     5,    -1,    51,
      -1,    52,    -1,   141,   175,   273,   176,    -1,   142,   175,
     273,   181,   273,   176,    -1,    41,   175,   273,   181,   273,
     176,    -1,    41,   177,   273,   181,   273,   178,    -1,    42,
     175,   273,   176,    -1,    43,   175,   273,   176,    -1,    44,
     175,   273,   181,   273,   181,   273,   176,    -1,    39,   175,
     275,   176,    -1,    39,   177,   275,   178,    -1,    40,   175,
     273,   176,    -1,    40,   177,   273,   178,    -1,    40,   175,
     273,   181,   269,   176,    -1,    40,   177,   273,   181,   269,
     178,    -1,   273,    -1,   275,   181,   273,    -1,     4,   184,
     182,   261,   183,    -1,   276,   184,   182,   261,   183,    -1,
       4,    -1,   276,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   178,   178,   179,   184,   186,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   208,   212,   219,   224,   229,   243,   256,   269,   297,
     311,   324,   337,   356,   361,   362,   363,   364,   365,   369,
     371,   376,   378,   384,   488,   383,   506,   513,   524,   523,
     541,   548,   559,   558,   575,   592,   615,   614,   628,   629,
     630,   631,   632,   636,   637,   644,   645,   646,   707,   736,
     741,   746,   751,   759,   766,   773,   788,   793,   798,   807,
     813,   822,   840,   858,   867,   879,   884,   892,   912,   935,
     946,   954,   976,   999,  1025,  1046,  1058,  1072,  1072,  1074,
    1076,  1085,  1095,  1094,  1106,  1116,  1115,  1129,  1131,  1139,
    1145,  1152,  1153,  1157,  1168,  1183,  1193,  1194,  1199,  1207,
    1216,  1234,  1238,  1249,  1252,  1265,  1268,  1278,  1302,  1301,
    1321,  1343,  1361,  1382,  1400,  1430,  1460,  1478,  1496,  1523,
    1541,  1560,  1559,  1582,  1600,  1639,  1645,  1651,  1658,  1683,
    1708,  1725,  1744,  1779,  1778,  1802,  1820,  1837,  1854,  1853,
    1879,  1884,  1889,  1894,  1899,  1904,  1927,  1933,  1944,  1945,
    1950,  1953,  1957,  1980,  2003,  2026,  2054,  2075,  2101,  2122,
    2144,  2164,  2276,  2295,  2333,  2442,  2451,  2457,  2472,  2500,
    2517,  2526,  2540,  2546,  2552,  2561,  2570,  2579,  2593,  2646,
    2663,  2678,  2697,  2709,  2733,  2737,  2742,  2749,  2755,  2760,
    2766,  2774,  2778,  2782,  2787,  2842,  2855,  2872,  2889,  2910,
    2931,  2966,  2974,  2980,  2987,  2991,  3000,  3008,  3016,  3025,
    3024,  3039,  3038,  3053,  3052,  3067,  3066,  3080,  3087,  3094,
    3101,  3108,  3115,  3122,  3129,  3136,  3144,  3143,  3157,  3156,
    3170,  3169,  3183,  3182,  3196,  3195,  3209,  3208,  3222,  3221,
    3235,  3234,  3248,  3247,  3264,  3267,  3273,  3285,  3305,  3329,
    3333,  3337,  3341,  3345,  3351,  3357,  3361,  3365,  3369,  3373,
    3392,  3405,  3408,  3424,  3427,  3444,  3447,  3453,  3456,  3463,
    3519,  3589,  3594,  3661,  3697,  3705,  3748,  3787,  3807,  3834,
    3874,  3897,  3920,  3924,  3928,  3951,  3990,  4029,  4050,  4071,
    4098,  4102,  4112,  4147,  4148,  4149,  4153,  4159,  4171,  4189,
    4217,  4218,  4219,  4220,  4221,  4222,  4223,  4224,  4225,  4232,
    4233,  4234,  4235,  4236,  4237,  4238,  4239,  4240,  4241,  4242,
    4243,  4244,  4245,  4246,  4247,  4248,  4249,  4250,  4251,  4252,
    4253,  4254,  4255,  4256,  4257,  4258,  4259,  4260,  4261,  4262,
    4263,  4264,  4267,  4268,  4269,  4270,  4271,  4272,  4273,  4274,
    4275,  4276,  4277,  4278,  4279,  4280,  4281,  4282,  4283,  4284,
    4285,  4286,  4287,  4288,  4297,  4298,  4299,  4300,  4301,  4302,
    4303,  4304,  4305,  4306,  4310,  4327,  4345,  4363,  4368,  4374,
    4386,  4403,  4421,  4442,  4447,  4452,  4462,  4472,  4477,  4486,
    4491,  4518,  4522,  4526,  4530,  4534,  4541,  4545,  4549,  4553,
    4560,  4565,  4572,  4577,  4581,  4586,  4590,  4598,  4609,  4613,
    4625,  4633,  4641,  4648,  4658,  4678,  4682,  4686,  4690,  4694,
    4723,  4752,  4781,  4810,  4820,  4830,  4843,  4855,  4867,  4886,
    4907,  4912,  4916,  4920,  4932,  4936,  4948,  4955,  4965,  4969,
    4984,  4989,  4996,  5000,  5013,  5021,  5032,  5036,  5044,  5050,
    5058,  5066,  5075,  5083,  5097,  5111,  5123,  5140,  5156,  5161,
    5165,  5185,  5207,  5212,  5218,  5227,  5240,  5243
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
  "tSetOrder", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
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
     405,   406,   407,   408,   409,   410,    63,   411,   412,   413,
     414,    60,    62,   415,   416,    43,    45,    42,    47,    37,
      33,   417,   418,   419,    94,    40,    41,    91,    93,    46,
      35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   185,   186,   186,   187,   187,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   189,   189,   190,   190,   190,   190,   190,   190,   191,
     191,   191,   191,   192,   192,   192,   192,   192,   192,   193,
     193,   194,   194,   196,   197,   195,   198,   198,   200,   199,
     201,   201,   203,   202,   204,   204,   206,   205,   207,   207,
     207,   207,   207,   208,   208,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   210,   210,   211,
     211,   211,   212,   211,   211,   213,   211,   214,   214,   215,
     215,   216,   216,   217,   217,   217,   218,   218,   219,   219,
     219,   220,   220,   221,   221,   222,   222,   223,   224,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   225,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   226,   223,   223,   223,   223,   227,   223,
     228,   228,   228,   228,   228,   228,   228,   228,   229,   229,
     230,   230,   230,   230,   230,   230,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   232,   232,   232,   232,   232,
     233,   233,   234,   234,   234,   234,   234,   234,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   237,   237,   237,   238,
     237,   239,   237,   240,   237,   241,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   242,   237,   243,   237,
     244,   237,   245,   237,   246,   237,   247,   237,   248,   237,
     249,   237,   250,   237,   251,   251,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   253,   253,   254,   254,   255,   255,   256,   256,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     258,   258,   258,   259,   259,   259,   260,   260,   260,   260,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   263,   263,   263,   263,   263,   264,   264,   264,   264,
     265,   265,   266,   266,   266,   266,   266,   266,   267,   267,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     269,   269,   269,   269,   270,   270,   270,   270,   271,   271,
     272,   272,   273,   273,   273,   273,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   275,   275,   276,   276,   277,   277
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
       7,     7,     9,     9,     9,     3,     6,     6,     4,     6,
       9,     6,     9,     5,     8,     8,    11,     6,     9,     5,
       7,     9,     9,    11,     7,     9,     9,     0,     1,     0,
       3,     5,     0,     9,     5,     0,     9,     0,     3,     3,
       5,     0,     2,     3,     5,     3,     0,     2,     3,     3,
       5,     1,     1,     0,     5,     0,     2,     7,     0,     9,
       6,     7,     4,     7,     8,     8,     7,     7,    11,     8,
       8,     0,     9,     8,     9,     3,     4,    10,     7,     7,
       8,     8,    12,     0,     9,     8,     7,     8,     0,     9,
       5,    11,     5,     9,     9,     4,     9,     9,     1,     1,
       0,     2,     6,     6,     6,     6,     8,    10,    14,    16,
      12,     8,     8,     6,    14,     4,     6,     6,     3,     4,
       5,     6,     3,     3,     4,     5,     4,     5,     3,     7,
       7,     3,     7,     3,     2,     2,     2,     2,    15,     2,
       2,     2,     2,     2,    16,     3,     6,     8,     8,    10,
       1,     2,     1,     3,     4,     1,     5,    11,    13,     0,
       7,     0,    13,     0,    15,     0,     6,     8,     8,     8,
      12,    12,    12,    14,    14,    14,     0,    12,     0,    12,
       0,    12,     0,    16,     0,    16,     0,    16,     0,    18,
       0,    18,     0,    18,     1,     2,     5,     7,     9,     2,
       2,     2,     3,     2,     3,     2,     3,     2,     3,     9,
       6,     0,     3,     0,     1,     0,     2,     0,     2,     7,
       6,     8,     5,     3,     7,     5,     4,     6,     6,    12,
      10,    10,    10,    10,    10,     4,     4,     4,     4,     4,
       2,     3,     6,     1,     1,     1,     2,     5,     7,    10,
       1,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     4,     6,     6,
       6,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       2,     5,     5,     3,     6,     4,     7,     6,     6,     6,
       4,     1,     2,     2,     3,     3,    11,     9,     7,     7,
       1,     3,     1,     1,     2,     3,     4,     5,     1,     1,
       2,     3,     3,     5,     4,     2,     2,     2,     2,     5,
       5,     5,     5,     1,     1,     3,     3,     4,     6,     6,
       1,     1,     3,     3,     9,     7,     1,     5,     3,     6,
       1,     3,     1,     1,     3,     6,     1,     1,     1,     4,
       6,     6,     6,     4,     4,     8,     4,     4,     4,     4,
       6,     6,     1,     3,     5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,     0,
     225,     0,     0,     0,   222,     0,     0,     0,     0,   313,
     314,   315,     0,     5,     7,     6,     8,     9,    10,    19,
      11,    12,    13,    18,    17,    14,    15,    16,     0,    20,
     487,     0,   384,   486,   466,   385,   386,   387,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   467,
     468,   391,   392,   393,     0,     0,     0,     0,     0,     0,
     388,   389,   390,     0,     0,     0,     0,     0,     0,     0,
     170,     0,     0,   320,     0,   462,   487,   394,     0,     0,
       0,     0,   207,     0,   209,   210,   206,   211,   212,    99,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,   141,
     153,   158,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   411,     0,
       0,     0,     0,     0,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   170,     0,   310,     0,
       0,     0,     0,     0,     0,     0,     0,   486,   429,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   443,   444,
     422,   428,     0,   423,   394,     0,     0,     0,     0,   456,
       0,     0,     0,     0,     0,   204,   205,     0,     0,   221,
       0,   170,     0,   170,   486,     0,   316,     0,     0,     0,
       0,     0,    58,    62,    61,    60,    59,    64,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   323,   322,   324,     0,
       0,     0,     0,     0,     0,     0,     0,   486,   487,     0,
       0,   169,     0,   168,     0,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,   198,     0,   400,   145,     0,   486,     0,   462,
     463,     0,     0,    97,    97,     0,     0,   450,   451,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   285,   285,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   170,   170,     0,   413,
     412,     0,     0,     0,     0,   170,   170,     0,     0,     0,
       0,     0,     0,     0,   235,     0,   170,     0,     0,     0,
       0,     0,   287,     0,     0,     0,     0,   188,     0,     0,
       0,   311,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   435,     0,   436,   437,   438,     0,
       0,     0,     0,     0,   322,   430,     0,   424,     0,     0,
       0,   293,   203,     0,     0,     0,     0,     0,   170,     0,
       0,     0,     0,   223,   192,     0,   193,     0,     0,   215,
       0,     0,     0,     0,     0,     0,     0,    75,     0,     0,
     403,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   482,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   321,    58,     0,     0,     0,
      58,     0,     0,     0,     0,     0,   165,     0,     0,     0,
       0,   171,     0,     0,   338,   337,   336,   335,   331,   332,
     334,   333,   326,   325,   327,   328,   329,   330,     0,     0,
     146,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   307,   308,   309,     0,     0,     0,     0,   283,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   132,   170,     0,     0,     0,     0,     0,   415,
     414,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     229,     0,     0,     0,     0,     0,     0,     0,   296,     0,
       0,   189,     0,     0,   185,     0,     0,     0,   306,   305,
       0,     0,     0,   446,     0,   445,     0,     0,   403,     0,
       0,     0,     0,     0,     0,     0,   321,   425,   432,     0,
     327,   431,     0,     0,     0,     0,     0,     0,     0,     0,
     224,     0,   194,   196,     0,     0,     0,     0,     0,     0,
      78,    67,     0,   395,   405,   340,   362,   341,   363,   342,
     364,   343,   365,   344,   366,   345,   367,   346,   368,   347,
     369,   348,   370,   361,   383,   349,   371,     0,     0,   351,
     373,   352,   374,   353,   375,   354,   376,   355,   377,   356,
     378,   357,   379,     0,     0,     0,     0,     0,     0,   476,
       0,   477,   478,     0,   479,     0,     0,     0,   473,   474,
       0,     0,     0,   410,    89,     0,   469,     0,   397,   398,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,     0,     0,     0,   399,     0,     0,     0,     0,   484,
       0,    43,     0,     0,     0,    56,     0,    34,    35,    36,
      37,    38,   396,     0,   464,    23,    21,     0,     0,    24,
       0,     0,    65,   100,    66,   108,     0,   452,   453,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,   286,   284,
       0,   292,     0,     0,   121,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   195,   197,     0,     0,
       0,   160,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
     226,     0,     0,     0,     0,     0,     0,   288,   295,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   395,   447,   434,     0,     0,     0,     0,   426,     0,
       0,     0,     0,     0,     0,     0,   190,     0,     0,     0,
       0,     0,     0,   317,     0,     0,     0,   485,     0,     0,
     401,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     483,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,     0,     0,     0,     0,     0,    76,    79,
      81,     0,     0,   460,     0,    87,     0,     0,     0,     0,
     339,     0,     0,     0,     0,     0,    29,   402,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,   125,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,     0,     0,     0,     0,     0,     0,     0,   290,     0,
       0,     0,     0,     0,     0,     0,     0,   298,     0,     0,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,     0,   269,     0,   275,     0,   277,     0,   271,     0,
     273,     0,   236,   265,     0,     0,     0,   183,     0,     0,
       0,   297,     0,   187,   186,   312,     0,     0,    30,    31,
       0,     0,     0,     0,   439,   440,   441,   442,   433,   427,
       0,     0,     0,   457,     0,     0,     0,   216,     0,     0,
       0,     0,     0,     0,    77,   200,   404,   199,   350,   372,
     358,   380,   359,   381,   360,   382,   480,   481,   471,   472,
       0,   408,   409,   407,   470,     0,    71,     0,    58,     0,
       0,     0,     0,    69,     0,     0,     0,   458,     0,     0,
       0,     0,     0,     0,     0,     0,   420,     0,     0,    25,
      26,     0,    27,     0,     0,   101,   104,   127,     0,     0,
       0,     0,     0,     0,   131,     0,     0,   148,   149,     0,
       0,   133,   156,     0,     0,     0,     0,   123,     0,   289,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
       0,     0,     0,     0,   170,   170,     0,   246,     0,   248,
       0,   250,     0,   422,     0,     0,   276,   278,   272,   274,
       0,     0,   230,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   294,     0,   449,   448,   404,   136,   137,     0,
       0,     0,     0,    90,    94,     0,     0,   318,     0,    70,
     406,     0,     0,     0,     0,     0,    84,     0,     0,    85,
       0,   461,   172,   173,   174,   175,     0,    39,     0,     0,
       0,     0,     0,    41,   465,     0,     0,   102,   105,     0,
       0,   126,   134,   135,   139,     0,     0,   150,     0,     0,
     291,     0,   143,     0,     0,   282,   155,     0,     0,     0,
       0,   140,     0,   151,   157,     0,     0,     0,     0,   419,
       0,   418,     0,     0,     0,   237,     0,     0,   238,     0,
       0,   239,     0,     0,     0,     0,     0,     0,     0,   182,
       0,     0,   181,     0,     0,     0,   176,     0,     0,    32,
       0,     0,   455,     0,   218,   217,     0,     0,     0,     0,
       0,   475,    73,    72,    80,    82,     0,    88,     0,    44,
       0,     0,     0,   421,     0,     0,     0,    28,     0,   111,
     116,     0,     0,     0,     0,     0,     0,     0,     0,   144,
     129,   142,   154,   159,     0,     0,    95,    96,   170,     0,
     163,   164,     0,     0,     0,     0,     0,     0,     0,   266,
       0,     0,   170,     0,     0,     0,     0,     0,   167,   166,
       0,     0,     0,     0,    91,    92,     0,    74,     0,   459,
       0,    40,     0,     0,     0,    42,    57,     0,     0,     0,
     300,   302,   301,   303,   304,   147,     0,     0,     0,     0,
       0,     0,   417,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,     0,     0,     0,   231,     0,     0,   177,
       0,     0,     0,   454,   219,     0,   319,    86,     0,     0,
       0,     0,     0,     0,   103,   112,     0,   106,   117,     0,
       0,     0,     0,   161,     0,   252,     0,     0,   254,     0,
       0,   256,     0,     0,     0,   267,     0,   227,     0,   170,
       0,     0,     0,   138,    93,     0,    48,     0,    54,     0,
       0,     0,     0,     0,   124,   152,   299,   416,   240,     0,
       0,   247,   241,     0,     0,   249,   242,     0,     0,   251,
       0,     0,     0,   233,     0,   180,     0,     0,     0,     0,
       0,     0,     0,     0,   113,   115,     0,   118,   119,     0,
       0,   258,     0,   260,     0,   262,   268,   279,   232,   228,
       0,     0,     0,     0,    45,     0,    52,     0,     0,     0,
     450,     0,     0,     0,   243,     0,     0,   244,     0,     0,
     245,     0,     0,   184,     0,   178,     0,    46,     0,     0,
     208,     0,   114,     0,   120,     0,     0,     0,     0,     0,
       0,     0,   234,     0,     0,     0,     0,     0,     0,   109,
     214,   253,     0,   255,     0,   257,     0,   179,    47,    49,
       0,    50,     0,     0,     0,     0,     0,     0,     0,    55,
     110,   259,   261,   263,    51,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    83,   897,    84,    85,   658,  1326,  1332,
     887,  1061,  1480,  1646,   888,  1599,  1680,   889,  1648,   890,
     891,  1065,   309,   414,    86,   670,   423,  1429,  1430,   424,
    1629,  1488,  1535,  1489,  1538,   933,  1354,  1231,   641,   454,
     455,   456,   457,   268,   392,   393,    89,    90,    91,    92,
      93,    94,   269,   971,  1558,  1620,   728,  1376,  1379,  1382,
    1579,  1583,  1587,  1635,  1638,  1641,   967,   968,  1097,   930,
     699,   737,    96,    97,    98,    99,   270,   163,   470,   228,
    1215,   271,   272,   273,   528,   281,   873,  1054,   605,   419,
     606,   166,   274
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1283
static const yytype_int16 yypact[] =
{
    5153,    32,    82,  5264, -1283, -1283,  1006,    92,    21,   -40,
     -36,    29,   153,   167,   177,   183,   200,     1,    75,  -126,
      86,   115,    16,   145,   179,    20,   197,   210,   185,   276,
     332,   414,    96,   727,   360,   392,   643,   426,   249,   700,
     362,   327,   447,   -63,   344,   -35,   -35,   353,     6,    50,
     127,   478,   493,    12,    49,   497,   500,   413,   593,   600,
     657,  3226,   662,   503,   507,   511,    22,    61, -1283,   517,
   -1283,   647,   689,   524, -1283,   715,   731,    26,    27, -1283,
   -1283, -1283,  4735, -1283, -1283, -1283, -1283, -1283, -1283, -1283,
   -1283, -1283, -1283, -1283, -1283, -1283, -1283, -1283,     2, -1283,
     -48,    91, -1283,     3, -1283, -1283, -1283, -1283,   -58,   175,
     272,   468,   504,   535,   607,   616,   625,   626,   655,   661,
     664,   665,   675,   681,   694,   709,   713,   732,   738,   745,
     746,   749,   767,   567,   570,   577,   585,   597,   601, -1283,
   -1283, -1283, -1283, -1283,   759,   602,   608,   629,   632,   650,
   -1283, -1283, -1283,  4735,  4735,  4735,  4276,  2405,    19,   841,
      18,   571,   248, -1283,   678,   829,   -84,   143,   840,  4735,
    1238,  1238, -1283,  4735, -1283, -1283, -1283, -1283, -1283, -1283,
   -1283,  4735,  4513,  4735,  4735,   682,  4735,  4513,  4735,  4735,
     688,  4513,  4735,  4735,  3424,   693,   692, -1283,  4513,  3226,
    3226,  3226,   703,   704,  3226,  3226,  3226,   710, -1283, -1283,
   -1283, -1283,   714,   720,   726,  3424,  4735,   860,  3424,    22,
     734,   735,   -35,   -35,   -35,  4735,  4735,   -28, -1283,    74,
     -35,   743,   765,   766,  4450,   101,  -118,   780,   805,   812,
    3226,  3226,  3424,   821,    35,   698, -1283,   993, -1283,   822,
     836,   837,  3226,  3226,   866,   878,   882,   649, -1283,   886,
      28,  1074,  1080,  1091,   281,  3523,  4735,  2734, -1283, -1283,
    4478, -1283,  1093, -1283,   113,  1132,  4735,  4735,  4735,   987,
    4735,   988,  1041,  4735,  4735, -1283, -1283,  4735,  1168, -1283,
    1172, -1283,  1191, -1283,   257,   453, -1283,  3424,  3424,  1021,
    4735,  1022,   595, -1283, -1283, -1283, -1283, -1283, -1283,  3424,
    1221,  1051,  4735,  1240,  4735,  4735,  4735,  4735,  4735,  4735,
    4735,  4735,  4735,  4735,  4735,  4735,  4735,  4735,  4735,  4735,
    4735,  4735,  4735,  4735,  4735,  4735,  4735,  4735,  4735,  4735,
    4735,  4735,  4735,  4735,  4735,  4735,  4735,  4735,  4735,  4735,
    4735,  4735,  4735,  4735,  4735,  4735,  4735,  4735,  1238,  1238,
    1238,  1238,  1238,  1238,  1238,  1238,  1238,  1238,  1238,  1238,
    4735,  1238,  1238,  1238,   841,   595,  1075,  1075,  1075,  4513,
    7780,   119,  4513,  6929,   169,  1078,  1255,  1083,  1087,  1095,
    1109, -1283,  1104,  4084,  4735, -1283,  4735,  4735,  4735,  4735,
    4735,  4735,  4735,  4735,  4735,  4735,  4735,  4735,  4735,  4735,
    4735, -1283, -1283,  4735, -1283, -1283,   653,   472,   -11, -1283,
   -1283,    66,  6175,  -111,   340,  7801,  4513,  4640, -1283,   287,
    7822,  7843,  4735,  7864,   670,  7885,  7906,  4735,   762,  7927,
    7948,  1285,  4735,  4735,   770,  1288,  1289,  1290,  4735,  4735,
    1291,  1292,  1292,  4735,  1122,  1125,  1126,  1129,  4735,  4735,
    4735,  1298,  6095,  1130,  1301,  1127, -1283, -1283,   259, -1283,
   -1283,  6201,  6227,   -35,   -35,    18,    18,   296,  4735,  4735,
    4735,  4450,  4450,  4735,  4084,   298, -1283,  4735,  4735,  4735,
    4735,  4735,  1303,  1302,  1306,  4735,  1309, -1283,  4735,  4735,
     474, -1283,  4513,  4513,  4513,  1311,  1312,  4735,  4735,  4735,
    -148,  2975,  1315,  1316, -1283,  4735, -1283, -1283, -1283,  1139,
    1140,  1141,  1142,  4513,  1075, -1283,  7969, -1283,   789,  4735,
    3622, -1283, -1283,  7990,  8011,  8032,  1200,  6253, -1283,  1145,
    4888,  8053,  6952, -1283, -1283,   520, -1283,  2200,  4735, -1283,
    1152,   794,  4513,  6975,  4735,  1325,  1326, -1283,  4735,  6998,
     343,  8074,  7021,  8095,  7044,  8116,  7067,  8137,  7090,  8158,
    7113,  8179,  7136,  8200,  7159,  8221,  7182,  8242,  7205,  8263,
    7228,  8284,  7251,  6279,  6305,  8305,  7274,  8326,  7297,  8347,
    7320,  8368,  7343,  8389,  7366,  8410,  7389,  8431,  7412,  6331,
    6357,  6383,  6409,  6435,  6461, -1283,    89,   370,   103,   389,
    1155,  1156,  1159,  1162,  1158,  1160,  1164,   131,   772,  1165,
    1171,  1169,  1173,  1175,   795,   119, -1283,  3424,   798,    76,
     595,  4735,  1334,  1348,    23,  1178, -1283,   -76,    17,    25,
     -41, -1283,  5339,  4948,  1845,  1047,  1380,  1380,   737,   737,
     737,   737,   339,   339,  1075,  1075,  1075,  1075,     7,  7435,
   -1283,  4735,  1355,    34,  4513,  1356,  4513,  4735,  1359, -1283,
     841,  1363,  1238,  1364,  4513,  4513,  1235,  1369,  1371,  8452,
    1374,  1242,  1375,  1376,  8473,  1256,  1378,  1381,  4735,  8494,
    5367,  1205, -1283, -1283, -1283,  8515,  8536,  4735,  3424,  1386,
    1429,  8557,  4681,  4681,  4681,  4681,  8578,  8599,  8620,  3424,
    4513,  1257, -1283, -1283,  3871,  4771,   -35,  4735,  4735, -1283,
   -1283,  1254,  1258,  4450,  6487,  6513,  6539,  6149,   419,   -35,
    4854,  8641,  5395,  8662,  8683,  8704,  4735,  1432, -1283,  4735,
    8725, -1283,  7458,  7481, -1283,   802,   803,   807, -1283, -1283,
    7504,  7527,  6565, -1283,  4513, -1283,  4513,  7550,   113,  1261,
    5423,  4513,  4513,  4513,  4513,   810, -1283, -1283,  4982,  4513,
    1075, -1283,  1433,  1436,  1437,  1266,  4735,  4882,  4735,  4735,
   -1283,    56, -1283, -1283,  1267,  3424,  1442,   811,   299,  5451,
   -1283, -1283,  7573,   109, -1283, -1283, -1283, -1283, -1283, -1283,
   -1283, -1283, -1283, -1283, -1283, -1283, -1283, -1283, -1283, -1283,
   -1283, -1283, -1283, -1283, -1283, -1283, -1283,  4735,  4735, -1283,
   -1283, -1283, -1283, -1283, -1283, -1283, -1283, -1283, -1283, -1283,
   -1283, -1283, -1283,  4735,  4735,  4735,  4735,  4735,  4735, -1283,
    1238, -1283, -1283,  4513, -1283,  4513,  1238,  1238, -1283, -1283,
    1238,  1238,  1238, -1283, -1283,  4735, -1283,  1238, -1283, -1283,
    1274,  4735,  1445,  1275,    38,  4735,  1448,  1449,   800, -1283,
    1451,  1286,    22,  1458, -1283,  4513,  4513,  4513,  4513, -1283,
    4735, -1283,  1295,  1297,  1283, -1283,  1482, -1283, -1283, -1283,
   -1283, -1283,   113,  7596, -1283, -1283,  1327,  1238,   132, -1283,
     172,  6591, -1283,  1484, -1283, -1283,   -35,  4640, -1283,   927,
    3424,  3424,  1485,  3424,   974,  3424,  3424,  1486,  1424,  3424,
    3424,   908,  1488,  1489,  4513,  1490,  1492,  1816, -1283, -1283,
    1495, -1283,  1497,  1329,  8956, -1283,  1330,  1331,  1332,  1504,
    1505,  1508,  1510,   831,  1513,  4918, -1283, -1283,   301,  6617,
    6643, -1283, -1283,  5479,  -122,   -35,   -35,   -35,  1514,  1515,
    1340,  1517,  1349,    42,    44,    45,    53,    -8, -1283,   329,
   -1283,   419,  1520,  1523,  1524,  1526,  1527,  8956, -1283,   944,
    1368,  1532,  1545,  1546,  1471,  4735,  1547,  1555,  4735,   873,
     897,  -127, -1283, -1283,   903,   907,   910,   911, -1283,  4735,
     914,  3424,  3424,  3424,  1558,  6669, -1283,  5012,   171,  1559,
    1566,  3424,  1388, -1283,  1397,  4735,  1568, -1283,  1571,  1574,
   -1283,  1576,  8746,  7619,  8767,  7642,  8788,  7665,  8809,  7688,
   -1283,   242,   427,  1407,  1409,  1408,  1414,  1415,  8830,  1417,
     119,   967, -1283,   119,   303,  1418,  1587,  1563, -1283, -1283,
   -1283,    22,  4735, -1283,   933, -1283,   934,   956,   961,   962,
    8956,  1423,  4735,  4735,  3424,  1419, -1283, -1283,  1420, -1283,
    1596,    41,  1598,  4735,  3994,    72,  1427,  1428,  1534,  1534,
    3424,  1599,  1431,  1434,  1605,  1608,  3424,  1435,  1609,  1613,
   -1283,  1615,  3424,   968,  3424,  3424,  1619,  1618, -1283,  3424,
    1620,  1623,  1625,  1626,  3424,  3424,  3424, -1283,  1632,   618,
   -1283,  4735,  4735,  4735,  1444,  1459,   -93,    94,   267,  1469,
   -1283,  3424, -1283,  4735, -1283,  1641, -1283,  1643, -1283,  1645,
   -1283,  1646, -1283, -1283,  4450,   334,  3325, -1283,  1472,  1474,
    3721, -1283,  4513, -1283, -1283, -1283,  1476,  1661, -1283, -1283,
    7711,  1483,  1487,  1656, -1283, -1283, -1283, -1283,  8956, -1283,
    1660,  1662,  1538, -1283,  4735,  4735,  4735, -1283,  1663,   624,
    1491,  1664,   119,  1712, -1283, -1283,   591, -1283, -1283, -1283,
   -1283, -1283, -1283, -1283, -1283, -1283, -1283, -1283, -1283, -1283,
    1238, -1283, -1283, -1283, -1283,  3424, -1283,  3424,   595,  4735,
    1665,  1670,    23, -1283,  1669,  7734,    22, -1283,  1672,  1674,
    1676,  1679,  4735,  6695,  6721,   969, -1283,  4735,  1682, -1283,
   -1283,  1238, -1283,  6747,  4681,  8956, -1283, -1283,  4735,  4735,
     -35,  1681,  1684,  1689, -1283,  4735,  4735, -1283, -1283,  1695,
    4735, -1283, -1283,  1671,  1697,  1506,  1698,  1577,  4735, -1283,
    1700,  3424,  3424,  3424,  3424,  1703,  1154,  1705,  4735, -1283,
    4681,  5507,  8851,  5255,    18,    18,   -35,  1706,   -35,  1707,
     -35,  1708,  4735,    58,  1552,  8872, -1283, -1283, -1283, -1283,
    5535,   384, -1283,  1709,  2012,  1728,  3424,   -35,  2012,  1729,
     980,  4735, -1283,  1733, -1283, -1283,   113, -1283, -1283,  3424,
    5283,   135,  8893, -1283, -1283,  4048,  3424, -1283,  3424, -1283,
   -1283,  1564,  1736,  1739,  1741,  1957, -1283,  1742,  1744, -1283,
    1569, -1283, -1283, -1283, -1283, -1283,   293,  8956,  4735,  4735,
    3424,  1575,   981,  8956, -1283,  1747,  4735,  8956, -1283,  5563,
    5591,   506, -1283, -1283, -1283,  5619,  5647, -1283,  5675,  1753,
   -1283,  3424, -1283,  1693,  1758,  8956, -1283,  1760,  1761,  1762,
    1763, -1283,  1591, -1283, -1283,  6122,  2691,  1764,  1593, -1283,
    4735, -1283,  1589,  1594,   394, -1283,  1601,   411, -1283,  1603,
     463, -1283,  1604,  7757,  1770,  3424,  1771,  1606,  4735, -1283,
    3820,   467, -1283,   984,   499,   509, -1283,  1783,  5703, -1283,
    1667,  4735, -1283,  4735, -1283, -1283,  4513,  2786,  1785,  1610,
    1786, -1283, -1283, -1283, -1283, -1283,    22, -1283,  1673, -1283,
    4735,  6773,  6799, -1283,  3424,  4735,  1790, -1283,  6825, -1283,
   -1283,  1791,  1792,  1795,  1796,  1797,  1801,   992,  1627, -1283,
   -1283, -1283, -1283, -1283,  3424,  4513, -1283, -1283,    18,  5311,
   -1283, -1283,  4450,   419,  4450,   419,  4450,   419,  1804, -1283,
     996,  3424, -1283,  5731,   -35,  1805,  4513,   -35, -1283, -1283,
    4735,  5759,  5787,  1001, -1283, -1283,  1806, -1283,  1808, -1283,
    1633,  8956,  4735,  4735,  1008,  8956, -1283,  4735,  1011,  1012,
   -1283, -1283, -1283, -1283, -1283, -1283,  1654,  4735,  1015,  1019,
    1659,  4735, -1283,  5815,   518,   388,  5843,   523,   469,  5871,
     552,   611, -1283,  3424,  1831,  1759,  4946,  1668,   559, -1283,
    1036,   573,  3009, -1283, -1283,  1837, -1283, -1283,  4735,  8914,
    6851,    31,  6877,  1847, -1283, -1283,  1848, -1283, -1283,  4735,
    5899,  1843,  1851, -1283,  5927,  1852,  4735,  1853,  1854,  4735,
    1855,  1856,  4735,  1857,  1699, -1283,  4735, -1283,   419, -1283,
    4513,  1858,  3820, -1283, -1283,  1042, -1283,  4735, -1283,  3424,
    4735,  3039,  4222,  6903, -1283, -1283, -1283, -1283, -1283,  1683,
    5955, -1283, -1283,  1685,  5983, -1283, -1283,  1701,  6011, -1283,
    1878,  3949,   646,  5010,  1043, -1283,   578,  1054,  1879,  1710,
    8935,  1057,  6039,  2734, -1283, -1283,  1238,  8956, -1283,  4735,
     419,  1883,   419,  1884,   419,  1885, -1283, -1283, -1283, -1283,
     419,  1887,  4513,  1890, -1283,  1238, -1283,  1715,  1892,  1058,
    2500,  1064,  6067,   676, -1283,  1718,   788, -1283,  1720,  1263,
   -1283,  1721,  1357, -1283,  1072, -1283,  1073, -1283,  1722,  3424,
   -1283,  4735, -1283,   595, -1283,  1899,  1900,   419,  1901,   419,
    1902,   419, -1283,  1903,  1238,  1910,  1238,  1102,  4177, -1283,
   -1283, -1283,  1533, -1283,  1588, -1283,  1651, -1283, -1283, -1283,
    1105, -1283,  1911,   595,  1912,  1913,  1915,  1238,  1917, -1283,
   -1283, -1283, -1283, -1283, -1283, -1283
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1283, -1283, -1283, -1283,   783, -1283, -1283, -1283, -1283,   396,
   -1283, -1283, -1283, -1283, -1283, -1283, -1283, -1283, -1283, -1283,
   -1283, -1283,  -367,   -95, -1283,  1501, -1283, -1283, -1283, -1283,
   -1283, -1283, -1283, -1283, -1283,  -215, -1283,   847,  1924, -1283,
   -1283, -1283, -1283,     9,  -466,  -233, -1283, -1283, -1283, -1283,
   -1283, -1283,  1925, -1283, -1283, -1283, -1283, -1283, -1283, -1283,
   -1283, -1283, -1283, -1283, -1283, -1283,  -952,  -942, -1283, -1283,
    1477, -1283, -1283, -1283, -1283, -1283,  1077, -1283,    46, -1283,
   -1282,  1590,  -120,   244,  1466,  -217,   728, -1283,    30,    24,
    -354,    15,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -466
static const yytype_int16 yytable[] =
{
     101,   484,   465,   167,  1393,   607,   310,   311,   296,   721,
     722,   881,    88,   500,   627,   617,   244,   631,   100,  1135,
     185,   185,   390,   384,   190,  1133,   279,   871,   753,   190,
     165,   290,   292,   514,   754,   172,   164,  1568,     4,   496,
     895,   497,  1044,   473,   474,   307,   308,  1220,  1124,   181,
    1126,  1128,  1153,   247,   236,   248,   182,   487,   545,  1130,
     547,  1115,   219,  1009,   488,   282,   529,   668,   231,  1437,
     669,   232,   473,   474,   233,   220,   221,   958,  1227,   445,
     446,   447,     5,   626,   450,   451,   452,   959,  1266,   169,
    1267,   227,   229,   413,   235,   960,   961,   962,   302,   181,
     301,   963,   964,   965,   966,   168,   875,    44,    45,    46,
      47,   249,   237,   417,   104,    52,   238,   314,    55,   315,
     492,   493,   882,   883,   884,   885,   626,   299,   239,   300,
     223,   224,   505,   506,   193,   170,   301,   473,   474,   171,
     225,   878,  1484,  1403,   385,   386,   245,   226,   130,   131,
     132,   133,   134,   135,   475,  1125,   389,  1127,  1129,   174,
     139,   140,  1498,  1045,  1046,   663,  1131,   420,   420,   391,
     664,   223,   224,   175,   388,  1132,   630,   297,   179,  1166,
     312,   225,   313,   176,   298,   388,   388,   161,   234,   177,
     886,   186,   186,  1133,   246,   240,   896,   241,   187,   876,
     418,   421,   191,   896,   280,   872,   178,   877,   291,   293,
     515,   173,   498,  1569,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   530,   408,   409,   303,   304,
     305,   306,   410,   714,   715,  1010,   283,   473,   474,   473,
     474,  1384,   665,   303,   304,   305,   306,   666,   307,   308,
     146,   147,   180,   730,   395,   864,   476,   194,   861,   473,
     474,   183,   865,   307,   308,   839,   473,   474,   468,   469,
     840,   303,   304,   305,   306,  1268,   477,  1269,   198,   842,
     485,   307,   308,   486,   843,   307,   308,  1601,  1019,   632,
     184,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   777,   626,   853,  1071,   410,
    1198,   208,   840,   675,   209,   307,   308,   210,  1404,   211,
     188,   303,   304,   305,   306,  -463,   555,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   307,   308,   519,   195,   410,   520,  1167,  1072,   521,
     316,   522,   317,   675,   189,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,  1667,   420,   420,
     420,   622,   192,   388,   388,   388,   388,   388,   388,   388,
     388,   388,   388,   388,   388,   193,   388,   388,   388,   388,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   623,
     196,   619,   620,   621,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,  1186,   958,
     197,  1015,   410,   675,   473,   474,   428,   215,   202,   959,
     216,   428,   473,   474,   548,   428,   512,   960,   961,   962,
     716,   161,   428,   963,   964,   965,   966,   318,  1270,   319,
    1271,   303,   304,   305,   306,   303,   304,   305,   306,   549,
     203,   473,   474,   473,   474,   794,   473,   474,   675,  1419,
     676,   307,   308,   958,  1420,   307,   308,   723,   252,   729,
     945,   253,  1111,   959,   391,   391,     7,     8,   936,   937,
     938,   960,   961,   962,   473,   474,   207,   963,   964,   965,
     966,  1505,   217,  1508,   958,  1511,   407,   408,   409,   525,
    1134,   428,   218,   410,   959,   307,   308,  1282,   671,   719,
     720,   669,   960,   961,   962,  -464,   222,   469,   963,   964,
     965,   966,     7,     8,   866,   230,   637,    20,    21,   638,
      23,    24,   639,    26,   640,    28,   242,    29,   841,   473,
     474,   840,    34,    35,   958,    37,    38,    39,   243,   473,
     474,    42,   250,  1133,   959,  1388,  1133,   844,   251,  1133,
     845,  1547,   960,   961,   962,  1452,   473,   474,   963,   964,
     965,   966,   637,    20,    21,   638,    23,    24,   639,    26,
     640,    28,  1454,    29,    63,    64,    65,   254,    34,    35,
     104,    37,    38,    39,   255,  1187,  1592,    42,   675,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   428,  1259,  1260,   428,   410,   473,   474,
    1304,  1305,   473,   474,   130,   131,   132,   133,   134,   135,
      63,    64,    65,   320,  1456,   321,   139,   140,  1464,   661,
    1133,   662,  1550,   285,   867,  1053,   161,   744,  1633,   660,
    1636,   256,  1639,   794,   473,   474,   275,   903,  1642,   420,
     525,   473,   474,  1195,   473,   474,  1197,  1199,   276,   322,
    1466,   323,   277,   473,   474,   388,   278,   388,   473,   474,
    1467,  1133,   284,  1016,  1133,   286,   958,  1133,  1020,  1546,
    1133,   287,   905,   782,  1549,  1672,   959,  1674,   204,  1676,
     324,   205,   325,   206,   960,   961,   962,   473,   474,   288,
     963,   964,   965,   966,   473,   474,   935,   935,   935,   935,
    1133,   958,  1133,  1552,  1133,   289,   146,   147,   473,   474,
    1560,   959,   364,   473,   474,   365,   428,   428,   428,   960,
     961,   962,   366,   394,  1562,   963,   964,   965,   966,  1622,
     367,   958,   948,   307,   308,   212,   370,   428,   213,   954,
     214,   959,   368,  -465,   771,   969,   369,   371,   854,   960,
     961,   962,   326,   372,   327,   963,   964,   965,   966,   199,
     420,   328,   200,   329,  1553,   201,   428,  1067,  1372,  1373,
     330,   332,   331,   333,   373,  1308,  1050,   374,   388,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,  1021,   510,   375,   511,   410,   512,  1618,
     334,   160,   335,   161,  1204,   412,   336,   420,   337,   338,
     340,   339,   341,   420,   420,   387,   415,   420,   420,   420,
     342,   675,   343,   681,   420,   388,   344,   432,   345,  1656,
     411,   388,   388,   437,   463,   388,   388,   388,   442,   346,
    1030,   347,   388,   958,   443,   499,  1033,  1034,   448,   449,
    1035,  1036,  1037,   959,   348,   453,   349,  1039,   350,   458,
     351,   960,   961,   962,   420,   459,  1020,   963,   964,   965,
     966,   460,   405,   406,   407,   408,   409,   352,   428,   353,
     428,   410,   388,   354,  1090,   355,   466,   467,   771,   908,
     356,   358,   357,   359,   360,   478,   361,  1070,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   362,   675,   363,   685,   410,   479,   480,  1200,
    1141,   675,  1075,   691,   428,   489,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     675,  1658,   767,  1196,   410,   785,   675,   786,   860,   675,
     490,   863,  1500,   675,   675,   983,   984,   491,   675,  1321,
     985,   675,   675,   998,  1014,  1076,   495,  1077,   428,   501,
     428,  1116,  1117,  1118,   502,   428,   428,   428,   428,   102,
     103,   104,   675,   428,  1108,   105,   106,   107,   503,   504,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,  1082,   507,  1083,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   675,   508,  1151,   139,   140,   509,
     141,   142,   143,   513,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   675,   516,
    1152,  1310,   410,   162,   675,   517,  1154,   428,   675,   428,
    1155,   675,   675,  1156,  1157,   675,   518,  1159,  1226,   531,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,  1206,   675,  1207,  1208,   410,   428,
     428,   428,   428,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   675,   532,  1209,
     144,   410,   675,   675,  1210,  1211,   145,   146,   147,   675,
    1330,  1245,  1331,   148,   149,   150,   151,   152,  1362,   295,
    1363,   675,  1425,  1397,  1426,  1330,   536,  1465,   428,   539,
     538,   153,   154,  1330,   543,  1496,   155,  1513,   544,  1514,
    1281,   156,   675,   157,  1525,   158,   159,   420,   160,  1330,
     161,  1531,  1533,  1536,  1534,  1537,  1330,   546,  1541,  1478,
     675,  1310,  1542,   552,   554,   388,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   675,   420,  1561,
    1311,   410,  1314,  1425,   675,  1598,  1621,   557,   558,  1516,
     376,   377,   378,   380,   383,   675,   388,  1623,  1330,  1651,
    1627,  1652,   417,   104,   560,   840,   416,  1654,  1338,   410,
     422,  1335,  1631,   675,  1664,  1663,  1665,   633,   425,   427,
     430,   431,   634,   433,   427,   435,   436,   161,   427,   439,
     440,   301,   635,   391,   391,   427,  1341,   130,   131,   132,
     133,   134,   135,  1330,  1367,  1682,  1687,   636,  1688,   139,
     140,   160,   688,   462,   692,   693,   694,   702,   697,   698,
     703,   704,   471,   472,   705,   709,   711,   712,   738,   713,
     736,   472,  1374,   739,  1377,   741,  1380,   748,   749,   758,
     759,   761,   762,   763,   764,   775,  1593,   778,   784,  1408,
    1391,   790,   791,  1394,  1395,   848,   846,   847,   849,   850,
     869,   851,   524,   526,   427,   852,   855,   856,   958,   858,
     857,   859,   870,   533,   534,   535,   874,   537,   959,   894,
     540,   541,   899,   909,   542,   902,   960,   961,   962,   904,
     914,   906,   963,   964,   965,   966,   910,   553,   911,   146,
     147,   913,   915,   916,   918,   919,   428,   924,   920,   559,
     929,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   931,   944,   951,   978,   992,
    1001,   952,   958,  1002,  1003,  1004,  1660,   618,  1013,  1011,
    1040,  1042,   959,  1043,  1048,  1049,   427,   391,  1051,   427,
     960,   961,   962,  1052,  1055,  1064,   963,   964,   965,   966,
    1062,   642,  1063,   643,   644,   645,   646,   647,   648,   649,
     650,   651,   652,   653,   654,   655,   656,   657,  1066,  1069,
     659,  1074,  1080,  1086,  1087,  1091,  1092,  1094,  1504,  1095,
    1507,  1098,  1510,   524,  1099,  1100,  1101,  1102,  1103,   679,
    1518,  1104,  1105,  1521,   684,  1106,  1107,  1109,  1119,   689,
     690,  1120,  1121,  1122,  1123,   695,   696,  1136,   428,  1137,
     701,  1138,   428,  1139,  1140,   706,   707,   708,  1143,  1146,
    1662,   401,   402,   403,   404,   405,   406,   407,   408,   409,
    1142,  1144,  1145,  1148,   410,   724,   725,   726,   376,   377,
     727,  1149,  1163,  1168,   731,   732,   733,   734,   735,  1203,
    1169,  1171,   740,  1172,  1174,   742,   743,  1175,  1176,   427,
     427,   427,  1177,  1188,   750,   751,   752,  1189,   757,  1190,
    1191,  1192,   760,  1194,  1202,  1605,  1608,  1201,  1212,  1218,
     427,  1217,  1219,   420,  1222,  1234,   768,   770,  1596,  1228,
    1229,  1237,  1230,  1235,  1238,  1241,  1236,  1240,   958,  1242,
    1243,   388,   420,  1248,  1249,   757,  1264,  1251,   959,   427,
    1252,   789,  1253,  1254,   525,   792,   960,   961,   962,  1258,
     388,  1265,   963,   964,   965,   966,  1272,  1276,   429,  1277,
     428,  1278,  1279,   434,  1286,  1647,  1287,   438,  1291,  1294,
    1296,   420,  1299,   420,   444,  1295,  1297,  1292,  1298,  1303,
    1307,  1316,  1306,   958,  1317,  1319,  1349,  1669,  1322,   388,
    1323,   388,  1324,   959,   420,  1325,  1334,  1342,  1351,   428,
    1343,   960,   961,   962,  1678,  1344,  1681,   963,   964,   965,
     966,  1347,   388,  1350,  1352,  1353,  1356,  1690,   868,  1361,
     428,  1364,  1375,  1378,  1381,  1389,  1684,  1694,  1309,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,  1385,  1392,  1396,   958,   410,   893,  1399,
    1411,   427,  1412,   427,   901,  1413,   959,  1414,  1418,  1416,
    1417,   770,   907,  1427,   960,   961,   962,  1424,  1436,  1438,
     963,   964,   965,   966,  1439,   921,  1440,  1441,  1442,  1443,
    1447,  1685,  1450,  1444,   927,  1448,  1459,  1451,  1461,   934,
     934,   934,   934,  1453,   441,  1455,  1457,   427,  1462,  1468,
    1470,  1475,  1477,  1476,   949,   950,  1486,  1490,  1491,  1479,
     953,  1492,  1493,  1494,   428,   461,   428,  1495,   464,  1497,
    1512,  1519,  1526,   977,  1527,  1528,   979,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   427,   494,   427,  1686,   410,  1539,  1555,   427,   427,
     427,   427,  1543,  1564,  1556,   624,   427,   428,   628,  1575,
    1559,  1571,  1572,  1005,  1221,  1007,  1008,  1576,  1578,  1581,
    1582,  1585,  1586,  1589,  1595,  1610,   428,  1612,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,  1590,  1614,  1616,  1624,   410,   550,   551,  1634,
    1637,  1640,  1625,  1643,  1022,  1023,  1645,  1649,  1650,   556,
    1657,  1096,  1659,  1661,  1666,  1670,  1671,  1673,  1675,  1677,
    1024,  1025,  1026,  1027,  1028,  1029,  1679,  1689,  1691,  1692,
     427,  1693,   427,  1695,  1565,   672,  1232,    87,    95,   700,
    1318,     0,  1038,     0,     0,     0,     0,     0,  1041,     0,
       0,     0,  1047,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   427,   427,   427,   427,     0,  1060,     0,     0,
       0,     0,     0,  1415,     0,     0,     0,     0,   745,   746,
     747,     0,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,   765,
     410,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   427,     0,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   102,   257,     0,   787,   410,
       0,   105,   106,   107,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,   138,
       0,     0,  1147,     0,     0,  1150,   141,   142,   143,     0,
       0,     0,     0,     0,   260,     0,  1158,   261,     0,     0,
     262,     0,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1173,     0,   264,     0,     0,     0,     0,     0,
       0,    44,    45,    46,    47,    48,     0,     0,     0,    52,
       0,     0,    55,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,  1205,
     898,   410,   900,     0,     0,     0,     0,     0,     0,  1213,
    1214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1223,  1225,   145,     0,     0,     0,     0,     0,     0,   148,
     149,   150,   151,   152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   943,   481,  1390,     0,
       0,     0,   155,     0,     0,     0,     0,   483,  1261,  1262,
    1263,     0,   159,     0,   226,   527,     0,     0,  1273,     0,
    1275,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1280,     7,     8,     0,     0,     0,   862,     0,   427,
     989,     0,   990,     0,     0,     0,     0,   994,   995,   996,
     997,     0,     0,     0,     0,  1000,     0,     0,     0,     0,
       0,  1300,  1301,  1302,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   637,    20,    21,   638,    23,    24,   639,    26,
     640,    28,     0,    29,     0,     0,  1315,     0,    34,    35,
       0,    37,    38,    39,     0,     0,     0,    42,   928,  1327,
       0,     0,     0,     0,  1333,     0,     0,     0,     0,   942,
       0,  1337,     0,     0,     0,  1339,  1340,     0,     0,  1031,
       0,  1032,  1345,  1346,     0,     0,     0,  1348,     0,     0,
      63,    64,    65,     0,     0,  1355,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1365,     0,  1366,     0,     0,
       0,  1056,  1057,  1058,  1059,     0,     0,     0,     0,  1383,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   427,     0,     0,     0,   427,     0,     0,  1398,     0,
       0,     0,     0,     0,     0,  1012,     0,     0,     0,     0,
       0,     0,  1407,   783,     0,     0,     0,     0,     0,     0,
    1093,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1421,  1422,     0,   102,   294,
       0,     0,     0,  1428,   105,   106,   107,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     0,     0,     0,     0,     0,     0,  1449,     0,     0,
     136,   137,   138,     0,     0,     0,     0,     0,     0,   141,
     142,   143,     0,     0,     0,  1463,     0,   524,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1471,     0,
    1472,     0,     0,   427,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1481,     0,     0,
    1078,  1079,  1485,  1081,     0,  1084,  1085,  1653,   529,  1088,
    1089,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   427,     0,     0,     0,     0,     0,     0,  1503,
       0,  1506,     0,  1509,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   427,     0,   145,     0,  1522,     0,     0,
       0,     0,   148,   149,   150,   151,   152,     0,     0,  1529,
    1530,     0,     0,     0,  1532,     0,     0,     0,     0,     0,
     153,   154,     0,     0,  1540,   155,     0,     0,  1544,     0,
     266,     0,     0,   381,     0,   159,     0,   382,     0,     0,
       0,  1160,  1161,  1162,     0,     0,     0,     0,     0,     0,
       0,  1170,     0,     0,     0,  1333,     0,     0,  1290,     0,
       0,     0,     0,     0,     0,     0,  1573,     0,     0,     0,
       0,     0,     0,  1580,     0,     0,  1584,     0,     0,  1588,
       0,     0,     0,  1591,     0,     0,     0,   427,     0,   427,
       0,     0,     0,     0,  1600,     0,     0,  1602,     0,  1607,
       0,     0,     0,     0,  1216,     0,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   674,   408,   409,
    1233,     0,     0,     0,   410,     0,  1239,     0,     0,     0,
    1630,     0,  1244,     0,  1246,  1247,  1632,     0,     0,  1250,
       0,     0,     0,     0,  1255,  1256,  1257,  1446,     0,   427,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1274,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1285,     0,  1668,     0,
    1289,     0,     0,     0,     0,     0,     0,   102,   257,     0,
       0,     0,     0,   105,   106,   107,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     259,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     137,   138,     0,     0,     0,  1312,     0,  1313,   141,   142,
     143,     0,  1474,     0,     0,     0,   260,     0,     0,   261,
       0,     0,   262,     0,   263,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,     0,     0,     0,
       0,     0,     0,    44,    45,    46,    47,    48,     0,     0,
       0,    52,     0,     0,    55,     0,     0,     0,     0,     0,
       0,  1357,  1358,  1359,  1360,     0,     0,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,     0,
       0,     0,  1473,     0,   145,     0,  1216,     0,     0,     0,
       0,   148,   149,   150,   151,   152,     0,     0,     0,  1400,
       0,     0,     0,     0,     0,     0,  1409,     0,  1410,   153,
     426,     0,     0,     0,   155,     0,     0,     0,     0,   266,
       0,  1499,     0,     0,   159,     0,     0,   527,     0,     0,
    1423,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1520,     0,     0,     0,     0,     0,     0,     0,
       0,  1216,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
     410,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1460,     0,     0,   102,   294,
       0,     0,     0,     0,   105,   106,   107,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     0,     0,     0,  1216,  1563,     0,     0,     0,     0,
     136,   137,   138,     0,     0,     0,  1594,     0,  1597,   141,
     142,   143,     0,     0,  1216,     0,     0,     0,     0,     0,
       0,     0,   102,   257,   104,     0,     0,     0,   105,   106,
     107,  1515,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   259,     0,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,  1644,     0,
     139,   140,     0,   141,   142,   143,     0,     0,     0,     0,
       0,   260,     0,  1554,   261,     0,     0,   262,     0,   263,
       0,     0,     0,     0,     0,   145,     0,     0,     0,     0,
       0,   264,   148,   149,   150,   151,   152,     0,    44,    45,
      46,    47,    48,     0,     0,     0,    52,     0,     0,    55,
     153,   154,     0,     0,     0,   155,     0,     0,     0,     0,
     266,     0,     0,   755,     0,   159,     0,   756,     0,  1216,
       0,  1604,     0,     0,     0,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   145,
     146,   147,     0,   410,     0,     0,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   265,     0,     0,     0,   155,
       0,     0,     0,     0,   266,     0,     0,     0,     0,   159,
       0,  1603,     0,     0,     0,     0,     0,     0,     0,   102,
     257,   258,     0,     0,     0,   105,   106,   107,     0,  1216,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   259,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,   138,     0,     0,     0,     0,     0,     0,
     141,   142,   143,     0,     0,     0,     0,     0,   260,     0,
       0,   261,     0,     0,   262,     0,   263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,     0,     0,     0,     0,    44,    45,    46,    47,    48,
       0,     0,     0,    52,     0,     0,    55,     0,   102,   257,
    1283,     0,     0,     0,   105,   106,   107,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   259,     0,     0,     0,     0,   145,     0,     0,     0,
     136,   137,   138,   148,   149,   150,   151,   152,     0,   141,
     142,   143,     0,     0,     0,     0,     0,   260,     0,     0,
     261,   153,   265,   262,     0,   263,   155,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   159,   264,   267,     0,
       0,     0,     0,     0,    44,    45,    46,    47,    48,     0,
       0,     0,    52,     0,     0,    55,     0,   102,   257,     0,
       0,     0,     0,   105,   106,   107,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     259,     0,     0,     0,     0,   145,     0,     0,     0,   136,
     137,   138,   148,   149,   150,   151,   152,     0,   141,   142,
     143,     0,     0,     0,     0,     0,   260,     0,     0,   261,
     153,   265,   262,     0,   263,   155,     0,     0,     0,     0,
     266,     0,     0,     0,     0,   159,   264,  1284,     0,     0,
       0,     0,     0,    44,    45,    46,    47,    48,     0,     0,
       0,    52,     0,     0,    55,     0,   102,   257,     0,     0,
       0,     0,   105,   106,   107,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   259,
       0,     0,     0,     0,   145,     0,     0,     0,   136,   137,
     138,   148,   149,   150,   151,   152,     0,   141,   142,   143,
       0,     0,     0,     0,     0,   260,     0,     0,   261,   153,
     265,   262,     0,   263,   155,     0,     0,     0,     0,   266,
       0,     0,     0,     0,   159,   264,   267,     0,     0,     0,
       0,     0,    44,    45,    46,    47,    48,     0,     0,     0,
      52,     0,     0,    55,     0,   102,   257,     0,     0,     0,
       0,   105,   106,   107,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   259,     0,
       0,     0,     0,   145,     0,     0,     0,   136,   137,   138,
     148,   149,   150,   151,   152,     0,   141,   142,   143,     0,
       0,     0,     0,     0,   260,     0,     0,   261,   153,   426,
     262,     0,   263,   155,     0,     0,     0,     0,   266,     0,
       0,     0,     0,   159,   264,   523,     0,     0,     0,     0,
       0,    44,    45,    46,    47,    48,     0,     0,     0,    52,
       0,     0,    55,     0,   102,   257,     0,     0,     0,     0,
     105,   106,   107,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   259,     0,     0,
       0,     0,   145,     0,     0,     0,   136,   137,   138,   148,
     149,   150,   151,   152,     0,   141,   142,   143,     0,     0,
       0,     0,     0,   260,     0,     0,   261,   153,   426,   262,
       0,   263,   155,     0,     0,     0,     0,   266,     0,     0,
       0,     0,   159,   264,   769,     0,     0,     0,     0,     0,
      44,    45,    46,    47,    48,     0,     0,     0,    52,     0,
       0,    55,     0,   102,   257,     0,     0,     0,     0,   105,
     106,   107,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   259,     0,     0,     0,
       0,   145,     0,     0,     0,   136,   137,   138,   148,   149,
     150,   151,   152,     0,   141,   142,   143,     0,     0,     0,
       0,     0,   260,     7,     8,   261,   153,   265,   262,     0,
     263,   155,     0,     0,     0,     0,   266,     0,     0,     0,
       0,   159,   264,  1288,     0,     0,     0,     0,     0,    44,
      45,    46,    47,    48,     0,     0,     0,    52,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   637,    20,    21,   638,    23,    24,   639,
      26,   640,    28,     0,    29,     0,     0,     0,     0,    34,
      35,     0,    37,    38,    39,  1617,     0,     0,    42,     0,
     145,     0,     0,     0,     0,     0,     0,   148,   149,   150,
     151,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   481,  1390,     0,     0,     0,
     155,    63,    64,    65,     0,   483,     0,   102,   294,   104,
     159,     0,   226,   105,   106,   107,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     0,     0,     0,   139,   140,     0,   141,   142,
     143,   102,   294,   104,   946,     0,     0,   105,   106,   107,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     7,     8,     0,   139,
     140,     0,   141,   142,   143,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   146,   147,     0,     0,     0,
       0,   148,   149,   150,   151,   152,   637,    20,    21,   638,
      23,    24,   639,    26,   640,    28,     0,    29,     0,   153,
     154,     0,    34,    35,   155,    37,    38,    39,     0,   266,
       0,    42,     0,     0,   159,     0,  1224,     0,     0,     0,
       0,     0,     0,     0,  1683,     0,     0,     0,   145,   146,
     147,     0,     0,     0,     0,   148,   149,   150,   151,   152,
       0,     0,     0,     0,    63,    64,    65,     0,     0,     0,
       0,     0,     0,   153,   154,     0,     0,     0,   155,     0,
       0,     0,     0,   266,     0,   102,   294,   104,   159,     0,
    1406,   105,   106,   107,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
       0,     0,     0,   139,   140,     0,   141,   142,   143,   102,
     294,     0,     0,     0,     0,   105,   106,   107,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,   138,     0,     0,     0,     0,     0,     0,
     141,   142,   143,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   146,   147,     0,     0,     0,     0,   148,
     149,   150,   151,   152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153,   154,     0,
       0,     0,   155,     0,     0,     0,     0,   266,     0,     0,
       0,     0,   159,     0,  1606,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   148,   149,   150,   151,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   153,   154,     0,     0,     0,   155,     0,     0,     0,
       0,   266,     0,   102,   294,     0,   159,     0,   379,   105,
     106,   107,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   529,     0,     0,     0,
       0,     0,     0,     0,     0,   136,   137,   138,     0,     0,
       0,     0,     0,     0,   141,   142,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   102,   257,     0,     0,
       0,     0,   105,   106,   107,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   259,
       0,     0,     0,     0,     0,     0,     0,     0,   136,   137,
     138,     0,     0,     0,     0,     0,     0,   141,   142,   143,
       0,     0,     0,     0,     0,   260,     0,     0,   261,     0,
       0,   262,     0,   263,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,     0,   264,     0,   148,   149,   150,
     151,   152,    44,    45,    46,    47,    48,     0,     0,     0,
      52,     0,     0,    55,     0,   481,   482,     0,     0,     0,
     155,     0,     0,     0,     0,   483,     0,     0,     0,     0,
     159,     0,   226,     0,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   530,   408,   409,   529,     0,
       0,     0,   410,   145,     0,     0,     0,     0,     0,     0,
     148,   149,   150,   151,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   426,
       0,     0,     0,   155,   102,   294,   104,     0,   266,     0,
     105,   106,   107,   159,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     0,     0,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,   139,   140,     0,   141,   142,   143,   102,   294,
       0,     0,     0,     0,   105,   106,   107,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     136,   137,   138,     7,     8,     0,     0,     0,     0,   141,
     142,   143,     0,     0,     0,     0,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   674,   408,   409,
       0,     0,     0,     0,   410,     0,     0,     0,     0,     0,
       0,   145,   146,   147,     0,     0,     0,     0,   148,   149,
     150,   151,   152,   637,    20,    21,   638,    23,    24,   639,
      26,   640,    28,     0,    29,     0,   153,   154,     0,    34,
      35,   155,    37,    38,    39,     0,   266,     0,    42,     0,
       0,   159,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,     0,
       0,     0,   148,   149,   150,   151,   152,     0,     0,     0,
       0,    63,    64,    65,     7,     8,   779,     0,     0,     0,
     153,   154,     0,     0,     0,   155,     0,     0,     0,     0,
     266,     0,     0,     0,     0,   159,   637,    20,    21,   638,
      23,    24,   639,    26,   640,    28,     0,    29,     0,     0,
       7,     8,    34,    35,     0,    37,    38,    39,     0,     0,
       0,    42,     0,     0,   637,    20,    21,   638,    23,    24,
     639,    26,   640,    28,   947,    29,   880,     0,     7,     8,
      34,    35,     0,    37,    38,    39,     0,     0,     0,    42,
       0,     0,     0,     0,    63,    64,    65,     0,     0,     0,
     637,    20,    21,   638,    23,    24,   639,    26,   640,    28,
     999,    29,     0,     0,     0,     0,    34,    35,     0,    37,
      38,    39,    63,    64,    65,    42,     0,     0,   637,    20,
      21,   638,    23,    24,   639,    26,   640,    28,     0,    29,
    1165,     0,     7,     8,    34,    35,     0,    37,    38,    39,
       0,     0,     0,    42,     0,     0,     0,   970,    63,    64,
      65,     0,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,   410,     0,     0,  1006,    63,    64,    65,     0,
       0,     0,   637,    20,    21,   638,    23,    24,   639,    26,
     640,    28,     0,    29,     0,     0,     0,     0,    34,    35,
       0,    37,    38,    39,     0,     0,     0,    42,     0,     0,
       0,  1110,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,   410,     0,     0,     0,     0,     0,     0,  1557,
      63,    64,    65,     0,     0,     0,     0,     0,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,     0,    -4,     1,     0,   410,    -4,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,     0,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,   410,     0,     0,     0,
      -4,    -4,     0,  1619,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,    -4,     0,     0,    -4,     0,     0,     0,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,    -4,     0,     0,     0,     0,     0,    -4,     6,     0,
       0,     0,    -4,    -4,    -4,    -4,     7,     8,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,    -4,
       0,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    12,    13,     0,     0,    14,     0,     0,
       0,    15,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,     0,     0,
      58,    59,    60,     0,     0,     0,     0,     0,    61,     0,
       0,     0,     0,    62,    63,    64,    65,     0,     0,    66,
       0,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    79,    80,    81,
      82,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,     0,     0,     0,  1370,     0,  1371,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,     0,     0,     0,  1401,     0,  1402,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,     0,
       0,     0,  1501,     0,  1502,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,     0,     0,     0,
       0,     0,   879,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,     0,     0,
     923,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,     0,     0,     0,     0,     0,   973,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,     0,     0,     0,     0,     0,   993,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,     0,
       0,     0,     0,     0,  1017,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,     0,     0,     0,
       0,     0,  1114,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,     0,     0,
    1368,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,     0,     0,     0,     0,     0,  1387,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,     0,     0,     0,     0,     0,  1431,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,     0,
       0,     0,     0,     0,  1432,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,     0,     0,     0,
       0,     0,  1433,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,     0,     0,
    1434,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,     0,     0,     0,     0,     0,  1435,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,     0,     0,     0,     0,     0,  1469,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,     0,
       0,     0,     0,     0,  1517,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,     0,     0,     0,
       0,     0,  1523,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,     0,     0,
    1524,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,     0,     0,     0,     0,     0,  1545,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,     0,     0,     0,     0,     0,  1548,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,     0,
       0,     0,     0,     0,  1551,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,     0,     0,     0,
       0,     0,  1574,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,     0,     0,
    1577,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,     0,     0,     0,     0,     0,  1611,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,     0,     0,     0,     0,     0,  1613,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,     0,
       0,     0,     0,     0,  1615,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,     0,     0,     0,
       0,     0,  1628,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,     0,     0,
    1655,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,     0,     0,     0,     0,   710,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,   410,     0,     0,     0,
       0,     0,     0,     0,  1445,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,   766,     0,     0,     0,     0,
     717,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,     0,     0,     0,   667,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,     0,
       0,     0,   717,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,   718,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,     0,     0,     0,   776,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,     0,     0,     0,
     817,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,     0,     0,     0,   818,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,     0,
       0,     0,   833,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,   834,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,     0,     0,     0,   835,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,     0,     0,     0,
     836,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,     0,     0,     0,   837,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,     0,
       0,     0,   838,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,   955,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,     0,     0,     0,   956,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,     0,     0,     0,
     957,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,     0,     0,     0,   988,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,     0,
       0,     0,  1073,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,  1112,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,     0,     0,     0,  1113,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,     0,     0,     0,
    1164,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,     0,     0,     0,  1328,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,     0,
       0,     0,  1329,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,  1336,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,     0,     0,     0,  1482,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,     0,     0,     0,
    1483,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,     0,     0,     0,  1487,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,     0,
       0,     0,  1567,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,  1570,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,     0,     0,     0,  1609,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,   629,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,   410,     0,     0,     0,
     781,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,   788,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,   410,     0,     0,     0,   793,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,   796,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,   410,     0,
       0,     0,   798,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,   800,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
       0,     0,     0,     0,   410,     0,     0,     0,   802,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,   804,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
     410,     0,     0,     0,   806,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,   808,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,   410,     0,     0,     0,
     810,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,   812,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,   410,     0,     0,     0,   814,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,   816,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,   410,     0,
       0,     0,   820,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,   822,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
       0,     0,     0,     0,   410,     0,     0,     0,   824,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,   826,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
     410,     0,     0,     0,   828,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,   830,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,   410,     0,     0,     0,
     832,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,   892,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,   410,     0,     0,     0,   981,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,   982,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,   410,     0,
       0,     0,   986,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,   987,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
       0,     0,     0,     0,   410,     0,     0,     0,   991,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,     0,
       0,  1018,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
     410,     0,     0,     0,  1068,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,     0,     0,  1179,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,   410,     0,     0,     0,
    1181,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,     0,     0,  1183,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,   410,     0,     0,     0,  1185,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,     0,     0,  1293,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,   410,     0,
       0,     0,  1320,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,     0,     0,  1458,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
       0,     0,     0,     0,   410,     0,   625,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,   673,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,   410,     0,   677,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,   678,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,   410,     0,
     680,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,   682,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
     410,     0,   683,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,   686,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,   410,     0,   687,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,   766,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
       0,     0,     0,     0,   410,     0,   772,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,   773,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,   410,     0,   774,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,   780,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,   410,     0,
     795,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,   797,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
     410,     0,   799,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,   801,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,   410,     0,   803,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,   805,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
       0,     0,     0,     0,   410,     0,   807,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,   809,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,   410,     0,   811,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,   813,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,   410,     0,
     815,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,   819,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
     410,     0,   821,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,   823,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,   410,     0,   825,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,   827,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
       0,     0,     0,     0,   410,     0,   829,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,   831,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,   410,     0,   912,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,   917,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,   410,     0,
     922,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,   925,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
     410,     0,   926,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,   932,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,   410,     0,   939,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,   940,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
       0,     0,     0,     0,   410,     0,   941,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,   972,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,   410,     0,   974,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,   975,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,   410,     0,
     976,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,   980,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
     410,     0,  1178,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,   410,     0,  1180,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,   410,     0,  1182,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   410,     0,  1184,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
       0,     0,     0,     0,   410,     0,  1193,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,   410,     0,  1369,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,   410,     0,  1386,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,   410,     0,  1405,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,   410,     0,
    1566,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,   410,
       0,  1626,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
     410
};

static const yytype_int16 yycheck[] =
{
       3,   234,   219,     6,  1286,   359,   101,     4,     6,   475,
     476,     4,     3,   246,   381,   369,     4,   384,     3,   971,
       4,     4,     4,     4,     4,   967,     4,     4,   176,     4,
       6,     5,     5,     5,   182,     6,     6,     6,     6,     4,
       6,     6,     4,   165,   166,   172,   173,     6,     6,   175,
       6,     6,   179,     4,     4,     6,   182,   175,   291,     6,
     293,   183,   125,     7,   182,     4,     8,   178,    62,  1351,
     181,    65,   165,   166,    68,   138,   139,    85,     6,   199,
     200,   201,     0,     7,   204,   205,   206,    95,   181,    68,
     183,    45,    46,   177,    48,   103,   104,   105,     7,   175,
     184,   109,   110,   111,   112,    13,   182,    89,    90,    91,
      92,    62,    62,     4,     5,    97,    66,   175,   100,   177,
     240,   241,   115,   116,   117,   118,     7,   175,    78,   177,
     165,   166,   252,   253,   175,   175,   184,   165,   166,   175,
     175,   182,  1424,     8,   125,   126,   134,   182,    39,    40,
      41,    42,    43,    44,   182,   113,   159,   113,   113,     6,
      51,    52,  1444,   125,   126,   176,   113,   170,   171,   160,
     181,   165,   166,     6,   159,   183,     7,   175,   177,     8,
     177,   175,   179,     6,   182,   170,   171,   184,   182,     6,
     183,   175,   175,  1135,   182,    68,   162,    70,   182,   182,
     170,   171,   182,   162,   182,   182,     6,   182,   182,   182,
     182,   182,   177,   182,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   152,   153,
     154,   155,   174,   466,   467,   179,   175,   165,   166,   165,
     166,   183,   176,   152,   153,   154,   155,   181,   172,   173,
     141,   142,   177,   486,     6,   179,   182,    72,   625,   165,
     166,   175,   629,   172,   173,   176,   165,   166,   222,   223,
     181,   152,   153,   154,   155,   181,   230,   183,   182,   176,
     234,   172,   173,   182,   181,   172,   173,  1569,   179,   384,
     175,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   538,     7,   176,   176,   174,
       7,    62,   181,   181,    65,   172,   173,    68,   183,    70,
     175,   152,   153,   154,   155,   182,   302,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   172,   173,    62,    68,   174,    65,   176,   176,    68,
     175,    70,   177,   181,   175,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,  1649,   371,   372,
     373,   374,   175,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   175,   371,   372,   373,   374,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   375,
      68,   371,   372,   373,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   176,    85,
       6,   788,   174,   181,   165,   166,   182,    65,    68,    95,
      68,   187,   165,   166,   177,   191,   179,   103,   104,   105,
     181,   184,   198,   109,   110,   111,   112,   175,   181,   177,
     183,   152,   153,   154,   155,   152,   153,   154,   155,     6,
      68,   165,   166,   165,   166,   560,   165,   166,   181,   176,
     183,   172,   173,    85,   181,   172,   173,   181,    65,   181,
     713,    68,   181,    95,   475,   476,    12,    13,   703,   704,
     705,   103,   104,   105,   165,   166,    70,   109,   110,   111,
     112,  1453,   175,  1455,    85,  1457,   167,   168,   169,   265,
     181,   267,    65,   174,    95,   172,   173,   183,   178,   473,
     474,   181,   103,   104,   105,   182,   182,   481,   109,   110,
     111,   112,    12,    13,   629,   182,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    68,    73,   178,   165,
     166,   181,    78,    79,    85,    81,    82,    83,    65,   165,
     166,    87,    65,  1505,    95,   181,  1508,   178,    68,  1511,
     181,   183,   103,   104,   105,   181,   165,   166,   109,   110,
     111,   112,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,   181,    73,   120,   121,   122,     4,    78,    79,
       5,    81,    82,    83,     4,   178,  1558,    87,   181,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   379,     6,     7,   382,   174,   165,   166,
       6,     7,   165,   166,    39,    40,    41,    42,    43,    44,
     120,   121,   122,   175,   181,   177,    51,    52,   181,   177,
    1592,   179,   183,     6,   630,   872,   184,   183,  1610,     6,
    1612,     4,  1614,   758,   165,   166,     4,   670,  1620,   672,
     426,   165,   166,  1040,   165,   166,  1043,  1044,   175,   175,
     181,   177,   175,   165,   166,   670,   175,   672,   165,   166,
     181,  1633,   175,   788,  1636,     6,    85,  1639,   793,   181,
    1642,   177,   672,   183,   181,  1657,    95,  1659,    65,  1661,
     175,    68,   177,    70,   103,   104,   105,   165,   166,     4,
     109,   110,   111,   112,   165,   166,   702,   703,   704,   705,
    1672,    85,  1674,   181,  1676,     4,   141,   142,   165,   166,
     181,    95,   175,   165,   166,   175,   502,   503,   504,   103,
     104,   105,   175,   182,   181,   109,   110,   111,   112,   181,
     175,    85,   716,   172,   173,    65,     7,   523,    68,   723,
      70,    95,   175,   182,   530,   729,   175,   175,     6,   103,
     104,   105,   175,   175,   177,   109,   110,   111,   112,    62,
     793,   175,    65,   177,   183,    68,   552,   892,  1264,  1265,
     175,   175,   177,   177,   175,  1172,     6,   175,   793,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   793,   175,   175,   177,   174,   179,   183,
     175,   182,   177,   184,  1051,     6,   175,   840,   177,   175,
     175,   177,   177,   846,   847,     4,     6,   850,   851,   852,
     175,   181,   177,   183,   857,   840,   175,   175,   177,   183,
     182,   846,   847,   175,     4,   850,   851,   852,   175,   175,
     840,   177,   857,    85,   182,   177,   846,   847,   175,   175,
     850,   851,   852,    95,   175,   175,   177,   857,   175,   175,
     177,   103,   104,   105,   897,   175,   991,   109,   110,   111,
     112,   175,   165,   166,   167,   168,   169,   175,   664,   177,
     666,   174,   897,   175,     6,   177,   182,   182,   674,   675,
     175,   175,   177,   177,   175,   182,   177,   897,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   175,   181,   177,   183,   174,   182,   182,  1044,
       6,   181,   906,   183,   710,   175,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     181,   183,   183,     6,   174,   181,   181,   183,   183,   181,
     175,   183,  1448,   181,   181,   183,   183,   175,   181,  1206,
     183,   181,   181,   183,   183,    68,   175,    70,   754,     6,
     756,   955,   956,   957,   182,   761,   762,   763,   764,     3,
       4,     5,   181,   769,   183,     9,    10,    11,   182,   182,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    68,   177,    70,    39,    40,    41,    42,    43,
      44,    45,    46,    47,   181,   177,   183,    51,    52,   177,
      54,    55,    56,   177,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   181,     5,
     183,  1176,   174,     6,   181,     5,   183,   843,   181,   845,
     183,   181,   181,   183,   183,   181,     5,   183,  1074,     6,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   181,   181,   183,   183,   174,   875,
     876,   877,   878,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   181,     6,   183,
     134,   174,   181,   181,   183,   183,   140,   141,   142,   181,
     181,   183,   183,   147,   148,   149,   150,   151,     4,    82,
       6,   181,   181,   183,   183,   181,   179,   183,   924,   128,
     182,   165,   166,   181,     6,   183,   170,   181,     6,   183,
    1134,   175,   181,   177,   183,   179,   180,  1190,   182,   181,
     184,   183,   181,   181,   183,   183,   181,     6,   183,  1416,
     181,  1296,   183,   182,   182,  1190,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   181,  1221,   183,
    1190,   174,  1198,   181,   181,   183,   183,     6,   177,  1462,
     153,   154,   155,   156,   157,   181,  1221,   183,   181,   181,
     183,   183,     4,     5,     4,   181,   169,   183,  1224,   174,
     173,  1221,  1606,   181,   181,   183,   183,   179,   181,   182,
     183,   184,     7,   186,   187,   188,   189,   184,   191,   192,
     193,   184,   177,  1264,  1265,   198,  1230,    39,    40,    41,
      42,    43,    44,   181,  1260,   183,   181,   183,   183,    51,
      52,   182,     7,   216,     6,     6,     6,   175,     7,     7,
     175,   175,   225,   226,   175,     7,   176,     6,     6,   182,
       7,   234,  1266,     7,  1268,     6,  1270,     6,     6,     4,
       4,   182,   182,   182,   182,   125,  1559,   182,   176,  1305,
    1284,     6,     6,  1287,  1288,   176,   181,   181,   176,   181,
       6,   181,   265,   266,   267,   181,   181,   176,    85,   176,
     181,   176,     4,   276,   277,   278,   178,   280,    95,     4,
     283,   284,     6,   128,   287,     6,   103,   104,   105,     6,
     128,     7,   109,   110,   111,   112,     7,   300,     7,   141,
     142,     7,     7,     7,   128,     7,  1142,   182,     7,   312,
       4,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,     6,   179,   183,     6,   178,
       7,   183,    85,     7,     7,   179,   183,   370,     6,   182,
     176,     6,    95,   178,     6,     6,   379,  1448,     7,   382,
     103,   104,   105,   177,     6,   182,   109,   110,   111,   112,
     175,   394,   175,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,     6,   162,
     413,     7,     7,     7,    70,     7,     7,     7,  1452,     7,
    1454,     6,  1456,   426,     7,   176,   176,   176,   176,   432,
    1464,     7,     7,  1467,   437,     7,     6,     4,     4,   442,
     443,     6,   182,     6,   175,   448,   449,     7,  1284,     6,
     453,     7,  1288,     7,     7,   458,   459,   460,     6,    68,
     183,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     182,     6,     6,     6,   174,   478,   479,   480,   481,   482,
     483,     6,     4,     4,   487,   488,   489,   490,   491,     6,
       4,   183,   495,   176,     6,   498,   499,     6,     4,   502,
     503,   504,     6,   176,   507,   508,   509,   178,   511,   181,
     176,   176,   515,   176,     7,  1571,  1572,   179,   175,   179,
     523,   182,     6,  1606,     6,     6,   529,   530,  1562,   182,
     182,     6,    78,   182,     6,     6,   182,   182,    85,     6,
       5,  1606,  1625,     4,     6,   548,   182,     7,    95,   552,
       7,   554,     7,     7,  1390,   558,   103,   104,   105,     7,
    1625,   182,   109,   110,   111,   112,   177,     6,   182,     6,
    1406,     6,     6,   187,   182,  1625,   182,   191,   182,   176,
       4,  1664,   124,  1666,   198,   178,     6,     6,     6,     6,
       6,     6,   181,    85,     4,     6,     5,  1653,     6,  1664,
       6,  1666,     6,    95,  1687,     6,     4,     6,   182,  1445,
       6,   103,   104,   105,  1664,     6,  1666,   109,   110,   111,
     112,     6,  1687,     6,     6,   128,     6,  1683,   631,     6,
    1466,     6,     6,     6,     6,     6,   183,  1687,     6,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   181,     6,     6,    85,   174,   661,     6,
     176,   664,     6,   666,   667,     6,    95,     6,   179,     7,
       6,   674,   675,     6,   103,   104,   105,   182,     5,    66,
     109,   110,   111,   112,     6,   688,     6,     6,     6,     6,
       6,   183,   183,   182,   697,   182,     6,   183,     7,   702,
     703,   704,   705,   182,   194,   182,   182,   710,   182,     6,
     123,     6,     6,   183,   717,   718,     6,     6,     6,   126,
     723,     6,     6,     6,  1560,   215,  1562,     6,   218,   182,
       6,     6,     6,   736,     6,   182,   739,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   754,   242,   756,   183,   174,   182,     6,   761,   762,
     763,   764,   183,     6,    85,   379,   769,  1603,   382,     6,
     182,     4,     4,   776,  1071,   778,   779,     6,     6,     6,
       6,     6,     6,     6,     6,   182,  1622,   182,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   183,   182,     6,     6,   174,   297,   298,     6,
       6,     6,   182,     6,   817,   818,     6,   182,     6,   309,
     182,    85,   182,   182,   182,     6,     6,     6,     6,     6,
     833,   834,   835,   836,   837,   838,     6,     6,     6,     6,
     843,     6,   845,     6,  1528,   424,  1079,     3,     3,   452,
    1202,    -1,   855,    -1,    -1,    -1,    -1,    -1,   861,    -1,
      -1,    -1,   865,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   875,   876,   877,   878,    -1,   880,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,   502,   503,
     504,    -1,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,   523,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   924,    -1,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,     3,     4,    -1,   552,   174,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,   985,    -1,    -1,   988,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    62,    -1,   999,    65,    -1,    -1,
      68,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1015,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    91,    92,    93,    -1,    -1,    -1,    97,
      -1,    -1,   100,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,  1052,
     664,   174,   666,    -1,    -1,    -1,    -1,    -1,    -1,  1062,
    1063,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1073,  1074,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   710,   165,   166,    -1,
      -1,    -1,   170,    -1,    -1,    -1,    -1,   175,  1111,  1112,
    1113,    -1,   180,    -1,   182,   183,    -1,    -1,  1121,    -1,
    1123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1134,    12,    13,    -1,    -1,    -1,   627,    -1,  1142,
     754,    -1,   756,    -1,    -1,    -1,    -1,   761,   762,   763,
     764,    -1,    -1,    -1,    -1,   769,    -1,    -1,    -1,    -1,
      -1,  1164,  1165,  1166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    -1,    73,    -1,    -1,  1199,    -1,    78,    79,
      -1,    81,    82,    83,    -1,    -1,    -1,    87,   698,  1212,
      -1,    -1,    -1,    -1,  1217,    -1,    -1,    -1,    -1,   709,
      -1,  1224,    -1,    -1,    -1,  1228,  1229,    -1,    -1,   843,
      -1,   845,  1235,  1236,    -1,    -1,    -1,  1240,    -1,    -1,
     120,   121,   122,    -1,    -1,  1248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1258,    -1,  1260,    -1,    -1,
      -1,   875,   876,   877,   878,    -1,    -1,    -1,    -1,  1272,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1284,    -1,    -1,    -1,  1288,    -1,    -1,  1291,    -1,
      -1,    -1,    -1,    -1,    -1,   785,    -1,    -1,    -1,    -1,
      -1,    -1,  1305,   183,    -1,    -1,    -1,    -1,    -1,    -1,
     924,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1328,  1329,    -1,     3,     4,
      -1,    -1,    -1,  1336,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,  1370,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    56,    -1,    -1,    -1,  1388,    -1,  1390,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1401,    -1,
    1403,    -1,    -1,  1406,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1420,    -1,    -1,
     910,   911,  1425,   913,    -1,   915,   916,     7,     8,   919,
     920,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1445,    -1,    -1,    -1,    -1,    -1,    -1,  1452,
      -1,  1454,    -1,  1456,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1466,    -1,   140,    -1,  1470,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,  1482,
    1483,    -1,    -1,    -1,  1487,    -1,    -1,    -1,    -1,    -1,
     165,   166,    -1,    -1,  1497,   170,    -1,    -1,  1501,    -1,
     175,    -1,    -1,   178,    -1,   180,    -1,   182,    -1,    -1,
      -1,  1001,  1002,  1003,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1011,    -1,    -1,    -1,  1528,    -1,    -1,  1142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1539,    -1,    -1,    -1,
      -1,    -1,    -1,  1546,    -1,    -1,  1549,    -1,    -1,  1552,
      -1,    -1,    -1,  1556,    -1,    -1,    -1,  1560,    -1,  1562,
      -1,    -1,    -1,    -1,  1567,    -1,    -1,  1570,    -1,  1572,
      -1,    -1,    -1,    -1,  1064,    -1,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
    1080,    -1,    -1,    -1,   174,    -1,  1086,    -1,    -1,    -1,
    1603,    -1,  1092,    -1,  1094,  1095,  1609,    -1,    -1,  1099,
      -1,    -1,    -1,    -1,  1104,  1105,  1106,     6,    -1,  1622,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1136,    -1,  1651,    -1,
    1140,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,    -1,  1195,    -1,  1197,    54,    55,
      56,    -1,     6,    -1,    -1,    -1,    62,    -1,    -1,    65,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    97,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,
      -1,  1251,  1252,  1253,  1254,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,  1406,    -1,   140,    -1,  1286,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,  1299,
      -1,    -1,    -1,    -1,    -1,    -1,  1306,    -1,  1308,   165,
     166,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,   175,
      -1,  1445,    -1,    -1,   180,    -1,    -1,   183,    -1,    -1,
    1330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1351,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1385,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,  1424,     6,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,  1560,    -1,  1562,    54,
      55,    56,    -1,    -1,  1444,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,  1461,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,  1622,    -1,
      51,    52,    -1,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    62,    -1,  1513,    65,    -1,    -1,    68,    -1,    70,
      -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    82,   147,   148,   149,   150,   151,    -1,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
     165,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
     175,    -1,    -1,   178,    -1,   180,    -1,   182,    -1,  1569,
      -1,  1571,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   140,
     141,   142,    -1,   174,    -1,    -1,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   166,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,   180,
      -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,  1649,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    65,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    97,    -1,    -1,   100,    -1,     3,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      45,    46,    47,   147,   148,   149,   150,   151,    -1,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      65,   165,   166,    68,    -1,    70,   170,    -1,    -1,    -1,
      -1,   175,    -1,    -1,    -1,    -1,   180,    82,   182,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    -1,    -1,   100,    -1,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    45,
      46,    47,   147,   148,   149,   150,   151,    -1,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    65,
     165,   166,    68,    -1,    70,   170,    -1,    -1,    -1,    -1,
     175,    -1,    -1,    -1,    -1,   180,    82,   182,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    97,    -1,    -1,   100,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    45,    46,
      47,   147,   148,   149,   150,   151,    -1,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    65,   165,
     166,    68,    -1,    70,   170,    -1,    -1,    -1,    -1,   175,
      -1,    -1,    -1,    -1,   180,    82,   182,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    -1,    -1,    -1,
      97,    -1,    -1,   100,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,    45,    46,    47,
     147,   148,   149,   150,   151,    -1,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    65,   165,   166,
      68,    -1,    70,   170,    -1,    -1,    -1,    -1,   175,    -1,
      -1,    -1,    -1,   180,    82,   182,    -1,    -1,    -1,    -1,
      -1,    89,    90,    91,    92,    93,    -1,    -1,    -1,    97,
      -1,    -1,   100,    -1,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    45,    46,    47,   147,
     148,   149,   150,   151,    -1,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    65,   165,   166,    68,
      -1,    70,   170,    -1,    -1,    -1,    -1,   175,    -1,    -1,
      -1,    -1,   180,    82,   182,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,
      -1,   100,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    45,    46,    47,   147,   148,
     149,   150,   151,    -1,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    62,    12,    13,    65,   165,   166,    68,    -1,
      70,   170,    -1,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,   180,    82,   182,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    -1,    73,    -1,    -1,    -1,    -1,    78,
      79,    -1,    81,    82,    83,     6,    -1,    -1,    87,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   166,    -1,    -1,    -1,
     170,   120,   121,   122,    -1,   175,    -1,     3,     4,     5,
     180,    -1,   182,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    51,    52,    -1,    54,    55,
      56,     3,     4,     5,   183,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    12,    13,    -1,    51,
      52,    -1,    54,    55,    56,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   141,   142,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,   151,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    -1,    73,    -1,   165,
     166,    -1,    78,    79,   170,    81,    82,    83,    -1,   175,
      -1,    87,    -1,    -1,   180,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    -1,    -1,   140,   141,
     142,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,   120,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   165,   166,    -1,    -1,    -1,   170,    -1,
      -1,    -1,    -1,   175,    -1,     3,     4,     5,   180,    -1,
     182,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    51,    52,    -1,    54,    55,    56,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   140,   141,   142,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,    -1,
      -1,    -1,   170,    -1,    -1,    -1,    -1,   175,    -1,    -1,
      -1,    -1,   180,    -1,   182,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   165,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,
      -1,   175,    -1,     3,     4,    -1,   180,    -1,   182,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    65,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    82,    -1,   147,   148,   149,
     150,   151,    89,    90,    91,    92,    93,    -1,    -1,    -1,
      97,    -1,    -1,   100,    -1,   165,   166,    -1,    -1,    -1,
     170,    -1,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,
     180,    -1,   182,    -1,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,     8,    -1,
      -1,    -1,   174,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
      -1,    -1,    -1,   170,     3,     4,     5,    -1,   175,    -1,
       9,    10,    11,   180,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    51,    52,    -1,    54,    55,    56,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    12,    13,    -1,    -1,    -1,    -1,    54,
      55,    56,    -1,    -1,    -1,    -1,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,
      -1,   140,   141,   142,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    -1,    73,    -1,   165,   166,    -1,    78,
      79,   170,    81,    82,    83,    -1,   175,    -1,    87,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   120,   121,   122,    12,    13,     8,    -1,    -1,    -1,
     165,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
     175,    -1,    -1,    -1,    -1,   180,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    -1,    73,    -1,    -1,
      12,    13,    78,    79,    -1,    81,    82,    83,    -1,    -1,
      -1,    87,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,   183,    73,     8,    -1,    12,    13,
      78,    79,    -1,    81,    82,    83,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,   120,   121,   122,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       8,    73,    -1,    -1,    -1,    -1,    78,    79,    -1,    81,
      82,    83,   120,   121,   122,    87,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    -1,    73,
       8,    -1,    12,    13,    78,    79,    -1,    81,    82,    83,
      -1,    -1,    -1,    87,    -1,    -1,    -1,   183,   120,   121,
     122,    -1,    -1,    -1,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,   174,    -1,    -1,   183,   120,   121,   122,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    -1,    73,    -1,    -1,    -1,    -1,    78,    79,
      -1,    81,    82,    83,    -1,    -1,    -1,    87,    -1,    -1,
      -1,   183,    -1,    -1,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,   183,
     120,   121,   122,    -1,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,     0,     1,    -1,   174,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,
      37,    38,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    -1,    53,    -1,    -1,    -1,
      57,    58,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    -1,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,   106,
     107,   108,    -1,    -1,    -1,    -1,    -1,   114,     4,    -1,
      -1,    -1,   119,   120,   121,   122,    12,    13,   125,    -1,
     127,    -1,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,    -1,    -1,    -1,   143,   144,   145,   146,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    53,    -1,    -1,
      -1,    57,    58,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    -1,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,    -1,    -1,   119,   120,   121,   122,    -1,    -1,   125,
      -1,   127,    -1,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    -1,    -1,    -1,   143,   144,   145,
     146,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,   181,    -1,   183,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,   181,    -1,   183,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,   181,    -1,   183,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   183,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   183,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   183,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   183,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   183,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   183,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   183,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   183,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   183,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   183,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   182,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,   176,    -1,    -1,    -1,    -1,
     181,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,   181,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,   181,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,   181,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,   181,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,   181,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,   181,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,   178,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,
     178,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,   178,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,   174,    -1,    -1,    -1,   178,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,   178,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,
      -1,    -1,   178,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,   178,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,   178,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,   178,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
     174,    -1,    -1,    -1,   178,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,   178,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,
     178,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,   178,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,   174,    -1,    -1,    -1,   178,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,   178,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,
      -1,    -1,   178,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,   178,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,   178,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,   178,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
     174,    -1,    -1,    -1,   178,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,   178,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,
     178,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,   178,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,   174,    -1,    -1,    -1,   178,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,   178,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,
      -1,    -1,   178,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,   178,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,   178,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,   178,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
     174,    -1,    -1,    -1,   178,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,   178,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,
     178,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,    -1,   178,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,   174,    -1,    -1,    -1,   178,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,   178,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,
      -1,    -1,   178,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,    -1,    -1,   178,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,   174,    -1,   176,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,   176,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,   174,    -1,   176,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,   176,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,
     176,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,   176,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
     174,    -1,   176,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,   176,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,   174,    -1,   176,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,   176,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,   174,    -1,   176,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,   176,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,   174,    -1,   176,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,   176,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,
     176,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,   176,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
     174,    -1,   176,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,   176,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,   174,    -1,   176,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,   176,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,   174,    -1,   176,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,   176,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,   174,    -1,   176,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,   176,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,
     176,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,   176,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
     174,    -1,   176,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,   176,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,   174,    -1,   176,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,   176,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,   174,    -1,   176,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,   176,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,   174,    -1,   176,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,   176,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,
     176,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,   176,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
     174,    -1,   176,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,   176,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,   174,    -1,   176,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,   176,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,   174,    -1,   176,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,   176,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,   174,    -1,   176,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,   176,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,
     176,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,   176,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
     174,    -1,   176,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,   174,    -1,   176,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,   174,    -1,   176,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,   174,    -1,   176,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,   174,    -1,   176,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,   174,    -1,   176,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,   174,    -1,   176,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,   176,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,
     176,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,   174,
      -1,   176,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
     174
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   186,   187,     6,     0,     4,    12,    13,    37,
      38,    48,    49,    50,    53,    57,    58,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   106,   107,
     108,   114,   119,   120,   121,   122,   125,   127,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   143,
     144,   145,   146,   188,   190,   191,   209,   223,   228,   231,
     232,   233,   234,   235,   236,   237,   257,   258,   259,   260,
     276,   277,     3,     4,     5,     9,    10,    11,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    51,
      52,    54,    55,    56,   134,   140,   141,   142,   147,   148,
     149,   150,   151,   165,   166,   170,   175,   177,   179,   180,
     182,   184,   261,   262,   273,   274,   276,   277,    13,    68,
     175,   175,     6,   182,     6,     6,     6,     6,     6,   177,
     177,   175,   182,   175,   175,     4,   175,   182,   175,   175,
       4,   182,   175,   175,    72,    68,    68,     6,   182,    62,
      65,    68,    68,    68,    65,    68,    70,    70,    62,    65,
      68,    70,    65,    68,    70,    65,    68,   175,    65,   125,
     138,   139,   182,   165,   166,   175,   182,   263,   264,   263,
     182,    62,    65,    68,   182,   263,     4,    62,    66,    78,
      68,    70,    68,    65,     4,   134,   182,     4,     6,    62,
      65,    68,    65,    68,     4,     4,     4,     4,     5,    36,
      62,    65,    68,    70,    82,   166,   175,   182,   228,   237,
     261,   266,   267,   268,   277,     4,   175,   175,   175,     4,
     182,   270,     4,   175,   175,     6,     6,   177,     4,     4,
       5,   182,     5,   182,     4,   261,     6,   175,   182,   175,
     177,   184,     7,   152,   153,   154,   155,   172,   173,   207,
     208,     4,   177,   179,   175,   177,   175,   177,   175,   177,
     175,   177,   175,   177,   175,   177,   175,   177,   175,   177,
     175,   177,   175,   177,   175,   177,   175,   177,   175,   177,
     175,   177,   175,   177,   175,   177,   175,   177,   175,   177,
     175,   177,   175,   177,   175,   177,   175,   177,   175,   177,
     175,   177,   175,   177,   175,   175,   175,   175,   175,   175,
       7,   175,   175,   175,   175,   175,   261,   261,   261,   182,
     261,   178,   182,   261,     4,   125,   126,     4,   276,   277,
       4,   228,   229,   230,   182,     6,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     174,   182,     6,   177,   208,     6,   261,     4,   273,   274,
     277,   273,   261,   211,   214,   261,   166,   261,   268,   269,
     261,   261,   175,   261,   269,   261,   261,   175,   269,   261,
     261,   266,   175,   182,   269,   267,   267,   267,   175,   175,
     267,   267,   267,   175,   224,   225,   226,   227,   175,   175,
     175,   266,   261,     4,   266,   270,   182,   182,   263,   263,
     263,   261,   261,   165,   166,   182,   182,   263,   182,   182,
     182,   165,   166,   175,   230,   263,   182,   175,   182,   175,
     175,   175,   267,   267,   266,   175,     4,     6,   177,   177,
     230,     6,   182,   182,   182,   267,   267,   177,   177,   177,
     175,   177,   179,   177,     5,   182,     5,     5,     5,    62,
      65,    68,    70,   182,   261,   268,   261,   183,   269,     8,
     167,     6,     6,   261,   261,   261,   179,   261,   182,   128,
     261,   261,   261,     6,     6,   230,     6,   230,   177,     6,
     266,   266,   182,   261,   182,   274,   266,     6,   177,   261,
       4,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   273,   275,   275,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   275,   261,   273,
     273,   273,   277,   274,   269,   176,     7,   207,   269,   178,
       7,   207,   208,   179,     7,   177,   183,    62,    65,    68,
      70,   223,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   192,   261,
       6,   177,   179,   176,   181,   176,   181,   181,   178,   181,
     210,   178,   210,   176,   167,   181,   183,   176,   176,   261,
     176,   183,   176,   176,   261,   183,   176,   176,     7,   261,
     261,   183,     6,     6,     6,   261,   261,     7,     7,   255,
     255,   261,   175,   175,   175,   175,   261,   261,   261,     7,
     182,   176,     6,   182,   230,   230,   181,   181,   181,   263,
     263,   229,   229,   181,   261,   261,   261,   261,   241,   181,
     230,   261,   261,   261,   261,   261,     7,   256,     6,     7,
     261,     6,   261,   261,   183,   269,   269,   269,     6,     6,
     261,   261,   261,   176,   182,   178,   182,   261,     4,     4,
     261,   182,   182,   182,   182,   269,   176,   183,   261,   182,
     261,   268,   176,   176,   176,   125,   181,   230,   182,     8,
     176,   178,   183,   183,   176,   181,   183,   269,   178,   261,
       6,     6,   261,   178,   208,   176,   178,   176,   178,   176,
     178,   176,   178,   176,   178,   176,   178,   176,   178,   176,
     178,   176,   178,   176,   178,   176,   178,   181,   181,   176,
     178,   176,   178,   176,   178,   176,   178,   176,   178,   176,
     178,   176,   178,   181,   181,   181,   181,   181,   181,   176,
     181,   178,   176,   181,   178,   181,   181,   181,   176,   176,
     181,   181,   181,   176,     6,   181,   176,   181,   176,   176,
     183,   207,   266,   183,   179,   207,   208,   274,   261,     6,
       4,     4,   182,   271,   178,   182,   182,   182,   182,   183,
       8,     4,   115,   116,   117,   118,   183,   195,   199,   202,
     204,   205,   178,   261,     4,     6,   162,   189,   269,     6,
     269,   261,     6,   277,     6,   273,     7,   261,   268,   128,
       7,     7,   176,     7,   128,     7,     7,   176,   128,     7,
       7,   261,   176,   183,   182,   176,   176,   261,   266,     4,
     254,     6,   176,   220,   261,   274,   220,   220,   220,   176,
     176,   176,   266,   269,   179,   230,   183,   183,   263,   261,
     261,   183,   183,   261,   263,   181,   181,   181,    85,    95,
     103,   104,   105,   109,   110,   111,   112,   251,   252,   263,
     183,   238,   176,   183,   176,   176,   176,   261,     6,   261,
     176,   178,   178,   183,   183,   183,   178,   178,   181,   269,
     269,   178,   178,   183,   269,   269,   269,   269,   183,     8,
     269,     7,     7,     7,   179,   261,   183,   261,   261,     7,
     179,   182,   266,     6,   183,   207,   208,   183,   178,   179,
     208,   273,   261,   261,   261,   261,   261,   261,   261,   261,
     273,   269,   269,   273,   273,   273,   273,   273,   261,   273,
     176,   261,     6,   178,     4,   125,   126,   261,     6,     6,
       6,     7,   177,   270,   272,     6,   269,   269,   269,   269,
     261,   196,   175,   175,   182,   206,     6,   208,   178,   162,
     273,   176,   176,   181,     7,   263,    68,    70,   266,   266,
       7,   266,    68,    70,   266,   266,     7,    70,   266,   266,
       6,     7,     7,   269,     7,     7,    85,   253,     6,     7,
     176,   176,   176,   176,     7,     7,     7,     6,   183,     4,
     183,   181,   181,   181,   183,   183,   263,   263,   263,     4,
       6,   182,     6,   175,     6,   113,     6,   113,     6,   113,
       6,   113,   183,   252,   181,   251,     7,     6,     7,     7,
       7,     6,   182,     6,     6,     6,    68,   261,     6,     6,
     261,   183,   183,   179,   183,   183,   183,   183,   261,   183,
     266,   266,   266,     4,   181,     8,     8,   176,     4,     4,
     266,   183,   176,   261,     6,     6,     4,     6,   176,   178,
     176,   178,   176,   178,   176,   178,   176,   178,   176,   178,
     181,   176,   176,   176,   176,   207,     6,   207,     7,   207,
     208,   179,     7,     6,   270,   261,   181,   183,   183,   183,
     183,   183,   175,   261,   261,   265,   266,   182,   179,     6,
       6,   189,     6,   261,   182,   261,   274,     6,   182,   182,
      78,   222,   222,   266,     6,   182,   182,     6,     6,   266,
     182,     6,     6,     5,   266,   183,   266,   266,     4,     6,
     266,     7,     7,     7,     7,   266,   266,   266,     7,     6,
       7,   261,   261,   261,   182,   182,   181,   183,   181,   183,
     181,   183,   177,   261,   266,   261,     6,     6,     6,     6,
     261,   263,   183,     5,   182,   266,   182,   182,   182,   266,
     269,   182,     6,   178,   176,   178,     4,     6,     6,   124,
     261,   261,   261,     6,     6,     7,   181,     6,   207,     6,
     208,   273,   266,   266,   274,   261,     6,     4,   271,     6,
     178,   270,     6,     6,     6,     6,   193,   261,   181,   181,
     181,   183,   194,   261,     4,   273,   181,   261,   274,   261,
     261,   263,     6,     6,     6,   261,   261,     6,   261,     5,
       6,   182,     6,   128,   221,   261,     6,   266,   266,   266,
     266,     6,     4,     6,     6,   261,   261,   274,   183,   176,
     181,   183,   229,   229,   263,     6,   242,   263,     6,   243,
     263,     6,   244,   261,   183,   181,   176,   183,   181,     6,
     166,   263,     6,   265,   263,   263,     6,   183,   261,     6,
     266,   181,   183,     8,   183,   176,   182,   261,   274,   266,
     266,   176,     6,     6,     6,     6,     7,     6,   179,   176,
     181,   261,   261,   266,   182,   181,   183,     6,   261,   212,
     213,   183,   183,   183,   183,   183,     5,   265,    66,     6,
       6,     6,     6,     6,   182,   182,     6,     6,   182,   261,
     183,   183,   181,   182,   181,   182,   181,   182,   178,     6,
     266,     7,   182,   261,   181,   183,   181,   181,     6,   183,
     123,   261,   261,   269,     6,     6,   183,     6,   270,   126,
     197,   261,   181,   181,   265,   261,     6,   181,   216,   218,
       6,     6,     6,     6,     6,     6,   183,   182,   265,   269,
     229,   181,   183,   261,   263,   251,   261,   263,   251,   261,
     263,   251,     6,   181,   183,   266,   230,   183,   263,     6,
     269,   263,   261,   183,   183,   183,     6,     6,   182,   261,
     261,   183,   261,   181,   183,   217,   181,   183,   219,   182,
     261,   183,   183,   183,   261,   183,   181,   183,   183,   181,
     183,   183,   181,   183,   266,     6,    85,   183,   239,   182,
     181,   183,   181,     6,     6,   194,   176,   181,     6,   182,
     181,     4,     4,   261,   183,     6,     6,   183,     6,   245,
     261,     6,     6,   246,   261,     6,     6,   247,   261,     6,
     183,   261,   251,   230,   269,     6,   263,   269,   183,   200,
     261,   265,   261,   182,   266,   274,   182,   261,   274,   181,
     182,   183,   182,   183,   182,   183,     6,     6,   183,   183,
     240,   183,   181,   183,     6,   182,   176,   183,   183,   215,
     261,   275,   261,   251,     6,   248,   251,     6,   249,   251,
       6,   250,   251,     6,   269,     6,   198,   273,   203,   182,
       6,   181,   183,     7,   183,   183,   183,   182,   183,   182,
     183,   182,   183,   183,   181,   183,   182,   265,   261,   274,
       6,     6,   251,     6,   251,     6,   251,     6,   273,     6,
     201,   273,   183,     7,   183,   183,   183,   181,   183,     6,
     274,     6,     6,     6,   273,     6
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
#line 179 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 190 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 191 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 192 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 193 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 194 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 195 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 196 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 197 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 198 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 199 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 200 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 201 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 202 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 203 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 204 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 209 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 22:
#line 213 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 23:
#line 220 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 24:
#line 225 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 25:
#line 230 "Gmsh.y"
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
#line 244 "Gmsh.y"
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
#line 257 "Gmsh.y"
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
#line 270 "Gmsh.y"
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
#line 298 "Gmsh.y"
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
#line 312 "Gmsh.y"
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
#line 325 "Gmsh.y"
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
#line 338 "Gmsh.y"
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
#line 356 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 39:
#line 370 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 40:
#line 372 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 41:
#line 377 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 42:
#line 379 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 43:
#line 384 "Gmsh.y"
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
#line 488 "Gmsh.y"
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
#line 498 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 46:
#line 507 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 47:
#line 514 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 48:
#line 524 "Gmsh.y"
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
#line 533 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 50:
#line 542 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 51:
#line 549 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 52:
#line 559 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 53:
#line 567 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 54:
#line 577 "Gmsh.y"
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
#line 596 "Gmsh.y"
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
#line 615 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 57:
#line 621 "Gmsh.y"
    {
    ;}
    break;

  case 58:
#line 628 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 59:
#line 629 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 60:
#line 630 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 61:
#line 631 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 62:
#line 632 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 63:
#line 636 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 64:
#line 637 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 67:
#line 647 "Gmsh.y"
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
#line 708 "Gmsh.y"
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
#line 737 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 70:
#line 742 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 71:
#line 747 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 72:
#line 752 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 73:
#line 760 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 74:
#line 767 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 75:
#line 774 "Gmsh.y"
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

  case 76:
#line 789 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 77:
#line 794 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 78:
#line 799 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 79:
#line 808 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 80:
#line 814 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 81:
#line 823 "Gmsh.y"
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

  case 82:
#line 841 "Gmsh.y"
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

  case 83:
#line 859 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 84:
#line 868 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 85:
#line 880 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 86:
#line 885 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 87:
#line 893 "Gmsh.y"
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

  case 88:
#line 913 "Gmsh.y"
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

  case 89:
#line 936 "Gmsh.y"
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

  case 90:
#line 947 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 91:
#line 955 "Gmsh.y"
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

  case 92:
#line 977 "Gmsh.y"
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

  case 93:
#line 1000 "Gmsh.y"
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

  case 94:
#line 1026 "Gmsh.y"
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

  case 95:
#line 1047 "Gmsh.y"
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

  case 96:
#line 1059 "Gmsh.y"
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

  case 100:
#line 1077 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 101:
#line 1086 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 102:
#line 1095 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 103:
#line 1097 "Gmsh.y"
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

  case 104:
#line 1107 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 105:
#line 1116 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 106:
#line 1118 "Gmsh.y"
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

  case 108:
#line 1132 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 109:
#line 1140 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 110:
#line 1146 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 113:
#line 1158 "Gmsh.y"
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

  case 114:
#line 1169 "Gmsh.y"
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

  case 115:
#line 1184 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 118:
#line 1200 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 119:
#line 1208 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 120:
#line 1217 "Gmsh.y"
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

  case 121:
#line 1235 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 122:
#line 1239 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 123:
#line 1249 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 124:
#line 1253 "Gmsh.y"
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

  case 125:
#line 1265 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 126:
#line 1269 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 127:
#line 1279 "Gmsh.y"
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

  case 128:
#line 1302 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 129:
#line 1306 "Gmsh.y"
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

  case 130:
#line 1322 "Gmsh.y"
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

  case 131:
#line 1344 "Gmsh.y"
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

  case 132:
#line 1362 "Gmsh.y"
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

  case 133:
#line 1383 "Gmsh.y"
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

  case 134:
#line 1401 "Gmsh.y"
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

  case 135:
#line 1431 "Gmsh.y"
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

  case 136:
#line 1461 "Gmsh.y"
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

  case 137:
#line 1479 "Gmsh.y"
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

  case 138:
#line 1498 "Gmsh.y"
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

  case 139:
#line 1524 "Gmsh.y"
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

  case 140:
#line 1542 "Gmsh.y"
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

  case 141:
#line 1560 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 142:
#line 1564 "Gmsh.y"
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

  case 143:
#line 1583 "Gmsh.y"
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

  case 144:
#line 1601 "Gmsh.y"
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

  case 145:
#line 1640 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 146:
#line 1646 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 147:
#line 1652 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 148:
#line 1659 "Gmsh.y"
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

  case 149:
#line 1684 "Gmsh.y"
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

  case 150:
#line 1709 "Gmsh.y"
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

  case 151:
#line 1726 "Gmsh.y"
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

  case 152:
#line 1746 "Gmsh.y"
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

  case 153:
#line 1779 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 154:
#line 1783 "Gmsh.y"
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

  case 155:
#line 1803 "Gmsh.y"
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

  case 156:
#line 1821 "Gmsh.y"
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

  case 157:
#line 1838 "Gmsh.y"
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

  case 158:
#line 1854 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 159:
#line 1858 "Gmsh.y"
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

  case 160:
#line 1880 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 161:
#line 1885 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 162:
#line 1890 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 163:
#line 1895 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 164:
#line 1900 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 165:
#line 1905 "Gmsh.y"
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

  case 166:
#line 1928 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 167:
#line 1934 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 168:
#line 1944 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 169:
#line 1945 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 170:
#line 1950 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 171:
#line 1954 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 172:
#line 1958 "Gmsh.y"
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

  case 173:
#line 1981 "Gmsh.y"
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

  case 174:
#line 2004 "Gmsh.y"
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

  case 175:
#line 2027 "Gmsh.y"
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

  case 176:
#line 2055 "Gmsh.y"
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

  case 177:
#line 2076 "Gmsh.y"
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

  case 178:
#line 2103 "Gmsh.y"
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

  case 179:
#line 2124 "Gmsh.y"
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

  case 180:
#line 2145 "Gmsh.y"
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

  case 181:
#line 2165 "Gmsh.y"
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

  case 182:
#line 2277 "Gmsh.y"
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

  case 183:
#line 2296 "Gmsh.y"
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

  case 184:
#line 2335 "Gmsh.y"
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

  case 185:
#line 2443 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 186:
#line 2452 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 187:
#line 2458 "Gmsh.y"
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

  case 188:
#line 2473 "Gmsh.y"
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

  case 189:
#line 2501 "Gmsh.y"
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

  case 190:
#line 2518 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 191:
#line 2527 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 192:
#line 2541 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 193:
#line 2547 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 194:
#line 2553 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 195:
#line 2562 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 196:
#line 2571 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 197:
#line 2580 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 198:
#line 2594 "Gmsh.y"
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

  case 199:
#line 2647 "Gmsh.y"
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

  case 200:
#line 2664 "Gmsh.y"
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

  case 201:
#line 2679 "Gmsh.y"
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

  case 202:
#line 2698 "Gmsh.y"
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

  case 203:
#line 2710 "Gmsh.y"
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

  case 204:
#line 2734 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 205:
#line 2738 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 206:
#line 2743 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 207:
#line 2750 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 208:
#line 2756 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 209:
#line 2761 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 210:
#line 2767 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 211:
#line 2775 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 212:
#line 2779 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 213:
#line 2783 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 214:
#line 2789 "Gmsh.y"
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

  case 215:
#line 2843 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    ;}
    break;

  case 216:
#line 2856 "Gmsh.y"
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

  case 217:
#line 2873 "Gmsh.y"
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

  case 218:
#line 2890 "Gmsh.y"
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

  case 219:
#line 2911 "Gmsh.y"
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

  case 220:
#line 2932 "Gmsh.y"
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

  case 221:
#line 2967 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 222:
#line 2975 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 223:
#line 2981 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 224:
#line 2988 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 225:
#line 2992 "Gmsh.y"
    {
    ;}
    break;

  case 226:
#line 3001 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 227:
#line 3009 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 228:
#line 3017 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 229:
#line 3025 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 230:
#line 3031 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 231:
#line 3039 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 232:
#line 3045 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 233:
#line 3053 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 234:
#line 3059 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 235:
#line 3067 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 236:
#line 3073 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 237:
#line 3081 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 238:
#line 3088 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 239:
#line 3095 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 240:
#line 3102 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 241:
#line 3109 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 242:
#line 3116 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 243:
#line 3123 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 244:
#line 3130 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 245:
#line 3137 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 246:
#line 3144 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 247:
#line 3150 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 248:
#line 3157 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 249:
#line 3163 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 250:
#line 3170 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 251:
#line 3176 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 252:
#line 3183 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 253:
#line 3189 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 254:
#line 3196 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 255:
#line 3202 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 256:
#line 3209 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 257:
#line 3215 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 258:
#line 3222 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 259:
#line 3228 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 260:
#line 3235 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 261:
#line 3241 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 262:
#line 3248 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 263:
#line 3254 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 264:
#line 3265 "Gmsh.y"
    {
    ;}
    break;

  case 265:
#line 3268 "Gmsh.y"
    {
    ;}
    break;

  case 266:
#line 3274 "Gmsh.y"
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

  case 267:
#line 3286 "Gmsh.y"
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

  case 268:
#line 3306 "Gmsh.y"
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

  case 269:
#line 3330 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 270:
#line 3334 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 271:
#line 3338 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 272:
#line 3342 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 273:
#line 3346 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 274:
#line 3352 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 275:
#line 3358 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 276:
#line 3362 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 277:
#line 3366 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 278:
#line 3370 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 279:
#line 3374 "Gmsh.y"
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

  case 280:
#line 3393 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 281:
#line 3405 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 282:
#line 3409 "Gmsh.y"
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

  case 283:
#line 3424 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 284:
#line 3428 "Gmsh.y"
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

  case 285:
#line 3444 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 286:
#line 3448 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 287:
#line 3453 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 288:
#line 3457 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 289:
#line 3464 "Gmsh.y"
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

  case 290:
#line 3520 "Gmsh.y"
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

  case 291:
#line 3590 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 292:
#line 3595 "Gmsh.y"
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

  case 293:
#line 3662 "Gmsh.y"
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

  case 294:
#line 3698 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 295:
#line 3706 "Gmsh.y"
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

  case 296:
#line 3749 "Gmsh.y"
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

  case 297:
#line 3788 "Gmsh.y"
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

  case 298:
#line 3808 "Gmsh.y"
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

  case 299:
#line 3836 "Gmsh.y"
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

  case 300:
#line 3875 "Gmsh.y"
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

  case 301:
#line 3898 "Gmsh.y"
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

  case 302:
#line 3921 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    ;}
    break;

  case 303:
#line 3925 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 304:
#line 3929 "Gmsh.y"
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

  case 305:
#line 3952 "Gmsh.y"
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

  case 306:
#line 3991 "Gmsh.y"
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

  case 307:
#line 4030 "Gmsh.y"
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

  case 308:
#line 4051 "Gmsh.y"
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

  case 309:
#line 4072 "Gmsh.y"
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

  case 310:
#line 4099 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 311:
#line 4103 "Gmsh.y"
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

  case 312:
#line 4113 "Gmsh.y"
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

  case 313:
#line 4147 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 314:
#line 4148 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 315:
#line 4149 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 316:
#line 4154 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 317:
#line 4160 "Gmsh.y"
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

  case 318:
#line 4172 "Gmsh.y"
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

  case 319:
#line 4190 "Gmsh.y"
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

  case 320:
#line 4217 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 321:
#line 4218 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 322:
#line 4219 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 323:
#line 4220 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 324:
#line 4221 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 325:
#line 4222 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 326:
#line 4223 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 327:
#line 4224 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 328:
#line 4226 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 329:
#line 4232 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 330:
#line 4233 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 331:
#line 4234 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 332:
#line 4235 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 333:
#line 4236 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 334:
#line 4237 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 335:
#line 4238 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 336:
#line 4239 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 337:
#line 4240 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 338:
#line 4241 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 339:
#line 4242 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 340:
#line 4243 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 341:
#line 4244 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 342:
#line 4245 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 343:
#line 4246 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 344:
#line 4247 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 345:
#line 4248 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 346:
#line 4249 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 347:
#line 4250 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 348:
#line 4251 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 349:
#line 4252 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 350:
#line 4253 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 351:
#line 4254 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 352:
#line 4255 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 353:
#line 4256 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 354:
#line 4257 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 355:
#line 4258 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 356:
#line 4259 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 357:
#line 4260 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 358:
#line 4261 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 359:
#line 4262 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 360:
#line 4263 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 361:
#line 4264 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 362:
#line 4267 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 363:
#line 4268 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 364:
#line 4269 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 365:
#line 4270 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 366:
#line 4271 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 367:
#line 4272 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 368:
#line 4273 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 369:
#line 4274 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 370:
#line 4275 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 371:
#line 4276 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 372:
#line 4277 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 373:
#line 4278 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 374:
#line 4279 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 375:
#line 4280 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 376:
#line 4281 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 377:
#line 4282 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 378:
#line 4283 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 379:
#line 4284 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5);    ;}
    break;

  case 380:
#line 4285 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 381:
#line 4286 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 382:
#line 4287 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 383:
#line 4288 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 384:
#line 4297 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 385:
#line 4298 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 386:
#line 4299 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 387:
#line 4300 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 388:
#line 4301 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 389:
#line 4302 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 390:
#line 4303 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 391:
#line 4304 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 392:
#line 4305 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 393:
#line 4306 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 394:
#line 4311 "Gmsh.y"
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

  case 395:
#line 4328 "Gmsh.y"
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

  case 396:
#line 4346 "Gmsh.y"
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

  case 397:
#line 4364 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 398:
#line 4369 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 399:
#line 4375 "Gmsh.y"
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

  case 400:
#line 4387 "Gmsh.y"
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

  case 401:
#line 4404 "Gmsh.y"
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

  case 402:
#line 4422 "Gmsh.y"
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

  case 403:
#line 4443 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 404:
#line 4448 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 405:
#line 4453 "Gmsh.y"
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

  case 406:
#line 4463 "Gmsh.y"
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

  case 407:
#line 4473 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 408:
#line 4478 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 409:
#line 4487 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 410:
#line 4492 "Gmsh.y"
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

  case 411:
#line 4519 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 412:
#line 4523 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 413:
#line 4527 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 414:
#line 4531 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 415:
#line 4535 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 416:
#line 4542 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 417:
#line 4546 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 418:
#line 4550 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 419:
#line 4554 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 420:
#line 4561 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 421:
#line 4566 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 422:
#line 4573 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 423:
#line 4578 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 424:
#line 4582 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 425:
#line 4587 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 426:
#line 4591 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 427:
#line 4599 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 428:
#line 4610 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 429:
#line 4614 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 430:
#line 4626 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 431:
#line 4634 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 432:
#line 4642 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 433:
#line 4649 "Gmsh.y"
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

  case 434:
#line 4659 "Gmsh.y"
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

  case 435:
#line 4679 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 436:
#line 4683 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 437:
#line 4687 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 438:
#line 4691 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 439:
#line 4695 "Gmsh.y"
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

  case 440:
#line 4724 "Gmsh.y"
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

  case 441:
#line 4753 "Gmsh.y"
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

  case 442:
#line 4782 "Gmsh.y"
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

  case 443:
#line 4811 "Gmsh.y"
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

  case 444:
#line 4821 "Gmsh.y"
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

  case 445:
#line 4831 "Gmsh.y"
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

  case 446:
#line 4844 "Gmsh.y"
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

  case 447:
#line 4856 "Gmsh.y"
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

  case 448:
#line 4868 "Gmsh.y"
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

  case 449:
#line 4887 "Gmsh.y"
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

  case 450:
#line 4908 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 451:
#line 4913 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 452:
#line 4917 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 453:
#line 4921 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 454:
#line 4933 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 455:
#line 4937 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 456:
#line 4949 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 457:
#line 4956 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 458:
#line 4966 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 459:
#line 4970 "Gmsh.y"
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

  case 460:
#line 4985 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 461:
#line 4990 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 462:
#line 4997 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 463:
#line 5001 "Gmsh.y"
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

  case 464:
#line 5014 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 465:
#line 5022 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 466:
#line 5033 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 467:
#line 5037 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 468:
#line 5045 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 469:
#line 5051 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 470:
#line 5059 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 471:
#line 5067 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 472:
#line 5076 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 473:
#line 5084 "Gmsh.y"
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

  case 474:
#line 5098 "Gmsh.y"
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

  case 475:
#line 5112 "Gmsh.y"
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

  case 476:
#line 5124 "Gmsh.y"
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

  case 477:
#line 5141 "Gmsh.y"
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

  case 478:
#line 5157 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 479:
#line 5162 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 480:
#line 5166 "Gmsh.y"
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

  case 481:
#line 5186 "Gmsh.y"
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

  case 482:
#line 5208 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 483:
#line 5213 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 484:
#line 5219 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 485:
#line 5228 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 486:
#line 5241 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 487:
#line 5244 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 10875 "Gmsh.tab.cpp"
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


#line 5248 "Gmsh.y"


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

