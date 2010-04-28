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
     tPrintf = 290,
     tSprintf = 291,
     tStrCat = 292,
     tStrPrefix = 293,
     tStrRelative = 294,
     tBoundingBox = 295,
     tDraw = 296,
     tToday = 297,
     tSyncModel = 298,
     tCreateTopology = 299,
     tDistanceFunction = 300,
     tPoint = 301,
     tCircle = 302,
     tEllipse = 303,
     tLine = 304,
     tSphere = 305,
     tPolarSphere = 306,
     tSurface = 307,
     tSpline = 308,
     tVolume = 309,
     tCharacteristic = 310,
     tLength = 311,
     tParametric = 312,
     tElliptic = 313,
     tPlane = 314,
     tRuled = 315,
     tTransfinite = 316,
     tComplex = 317,
     tPhysical = 318,
     tCompound = 319,
     tPeriodic = 320,
     tUsing = 321,
     tPlugin = 322,
     tDegenerated = 323,
     tRotate = 324,
     tTranslate = 325,
     tSymmetry = 326,
     tDilate = 327,
     tExtrude = 328,
     tLevelset = 329,
     tLoop = 330,
     tRecombine = 331,
     tSmoother = 332,
     tSplit = 333,
     tDelete = 334,
     tCoherence = 335,
     tIntersect = 336,
     tLayers = 337,
     tHole = 338,
     tAlias = 339,
     tAliasWithOptions = 340,
     tText2D = 341,
     tText3D = 342,
     tInterpolationScheme = 343,
     tTime = 344,
     tCombine = 345,
     tBSpline = 346,
     tBezier = 347,
     tNurbs = 348,
     tNurbsOrder = 349,
     tNurbsKnots = 350,
     tColor = 351,
     tColorTable = 352,
     tFor = 353,
     tIn = 354,
     tEndFor = 355,
     tIf = 356,
     tEndIf = 357,
     tExit = 358,
     tField = 359,
     tReturn = 360,
     tCall = 361,
     tFunction = 362,
     tShow = 363,
     tHide = 364,
     tGetValue = 365,
     tGMSH_MAJOR_VERSION = 366,
     tGMSH_MINOR_VERSION = 367,
     tGMSH_PATCH_VERSION = 368,
     tHomRank = 369,
     tHomGen = 370,
     tHomCut = 371,
     tHomSeq = 372,
     tAFFECTDIVIDE = 373,
     tAFFECTTIMES = 374,
     tAFFECTMINUS = 375,
     tAFFECTPLUS = 376,
     tOR = 377,
     tAND = 378,
     tNOTEQUAL = 379,
     tEQUAL = 380,
     tGREATEROREQUAL = 381,
     tLESSOREQUAL = 382,
     UNARYPREC = 383,
     tMINUSMINUS = 384,
     tPLUSPLUS = 385
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
#define tPrintf 290
#define tSprintf 291
#define tStrCat 292
#define tStrPrefix 293
#define tStrRelative 294
#define tBoundingBox 295
#define tDraw 296
#define tToday 297
#define tSyncModel 298
#define tCreateTopology 299
#define tDistanceFunction 300
#define tPoint 301
#define tCircle 302
#define tEllipse 303
#define tLine 304
#define tSphere 305
#define tPolarSphere 306
#define tSurface 307
#define tSpline 308
#define tVolume 309
#define tCharacteristic 310
#define tLength 311
#define tParametric 312
#define tElliptic 313
#define tPlane 314
#define tRuled 315
#define tTransfinite 316
#define tComplex 317
#define tPhysical 318
#define tCompound 319
#define tPeriodic 320
#define tUsing 321
#define tPlugin 322
#define tDegenerated 323
#define tRotate 324
#define tTranslate 325
#define tSymmetry 326
#define tDilate 327
#define tExtrude 328
#define tLevelset 329
#define tLoop 330
#define tRecombine 331
#define tSmoother 332
#define tSplit 333
#define tDelete 334
#define tCoherence 335
#define tIntersect 336
#define tLayers 337
#define tHole 338
#define tAlias 339
#define tAliasWithOptions 340
#define tText2D 341
#define tText3D 342
#define tInterpolationScheme 343
#define tTime 344
#define tCombine 345
#define tBSpline 346
#define tBezier 347
#define tNurbs 348
#define tNurbsOrder 349
#define tNurbsKnots 350
#define tColor 351
#define tColorTable 352
#define tFor 353
#define tIn 354
#define tEndFor 355
#define tIf 356
#define tEndIf 357
#define tExit 358
#define tField 359
#define tReturn 360
#define tCall 361
#define tFunction 362
#define tShow 363
#define tHide 364
#define tGetValue 365
#define tGMSH_MAJOR_VERSION 366
#define tGMSH_MINOR_VERSION 367
#define tGMSH_PATCH_VERSION 368
#define tHomRank 369
#define tHomGen 370
#define tHomCut 371
#define tHomSeq 372
#define tAFFECTDIVIDE 373
#define tAFFECTTIMES 374
#define tAFFECTMINUS 375
#define tAFFECTPLUS 376
#define tOR 377
#define tAND 378
#define tNOTEQUAL 379
#define tEQUAL 380
#define tGREATEROREQUAL 381
#define tLESSOREQUAL 382
#define UNARYPREC 383
#define tMINUSMINUS 384
#define tPLUSPLUS 385




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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
#include "Colors.h"
#include "Parser.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "FunctionManager.h"
#include "ColorTable.h"
#include "OS.h"
#include "CreateFile.h"
#include "gmshSurface.h"
#include "gmshLevelset.h"

#if defined(HAVE_MESH)
#include "Generator.h"
#include "Field.h"
#include "BackgroundMesh.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewDataList.h"
#include "PluginManager.h"
#endif

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

#if defined(HAVE_KBIPACK)
#include "Homology.h"
#endif

// Global parser variables
std::string gmsh_yyname;
int gmsh_yyerrorstate = 0;
int gmsh_yyviewindex = 0;
std::map<std::string, std::vector<double> > gmsh_yysymbols;

// Static parser variables (accessible only in this file)
static std::map<std::string, std::string > gmsh_yystringsymbols;
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

void yyerror(const char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list);


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
#line 85 "Gmsh.y"
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
#line 458 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 471 "Gmsh.tab.cpp"

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
#define YYLAST   6738

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  151
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  386
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1376

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   385

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   136,     2,   146,     2,   135,     2,     2,
     141,   142,   133,   131,   147,   132,   145,   134,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     127,     2,   128,   122,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   143,     2,   144,   140,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   148,     2,   149,   150,     2,     2,     2,
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
     115,   116,   117,   118,   119,   120,   121,   123,   124,   125,
     126,   129,   130,   137,   138,   139
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    48,    51,    57,    65,    73,    83,
      90,    97,   104,   105,   108,   111,   114,   117,   120,   122,
     126,   128,   132,   133,   134,   145,   147,   151,   152,   166,
     168,   172,   173,   189,   198,   213,   214,   221,   223,   225,
     227,   229,   231,   233,   235,   240,   248,   258,   265,   272,
     276,   283,   288,   295,   305,   312,   322,   328,   337,   346,
     358,   365,   375,   381,   389,   399,   409,   421,   431,   441,
     443,   445,   446,   452,   453,   456,   464,   465,   475,   482,
     490,   495,   503,   512,   521,   529,   537,   549,   558,   567,
     568,   578,   587,   597,   601,   606,   617,   625,   633,   642,
     652,   666,   667,   677,   686,   694,   703,   704,   714,   720,
     732,   738,   748,   753,   763,   773,   775,   777,   778,   781,
     788,   795,   802,   809,   818,   833,   850,   863,   872,   881,
     888,   903,   908,   915,   922,   926,   931,   937,   941,   945,
     950,   955,   959,   967,   975,   979,   987,   991,   994,   997,
    1000,  1016,  1019,  1022,  1029,  1038,  1047,  1058,  1060,  1063,
    1065,  1069,  1074,  1076,  1082,  1094,  1108,  1109,  1117,  1118,
    1132,  1133,  1149,  1150,  1157,  1166,  1175,  1184,  1197,  1210,
    1223,  1238,  1253,  1268,  1269,  1282,  1283,  1296,  1297,  1310,
    1311,  1328,  1329,  1346,  1347,  1364,  1365,  1384,  1385,  1404,
    1405,  1424,  1426,  1429,  1435,  1443,  1453,  1456,  1466,  1467,
    1469,  1470,  1474,  1475,  1477,  1478,  1481,  1482,  1485,  1493,
    1500,  1509,  1515,  1521,  1528,  1535,  1542,  1553,  1564,  1575,
    1586,  1589,  1593,  1605,  1617,  1629,  1641,  1643,  1647,  1650,
    1653,  1656,  1660,  1664,  1668,  1672,  1676,  1680,  1684,  1688,
    1692,  1696,  1700,  1704,  1708,  1712,  1718,  1723,  1728,  1733,
    1738,  1743,  1748,  1753,  1758,  1763,  1768,  1775,  1780,  1785,
    1790,  1795,  1800,  1805,  1812,  1819,  1826,  1831,  1836,  1841,
    1846,  1851,  1856,  1861,  1866,  1871,  1876,  1881,  1888,  1893,
    1898,  1903,  1908,  1913,  1918,  1925,  1932,  1939,  1944,  1946,
    1948,  1950,  1952,  1954,  1956,  1958,  1960,  1966,  1971,  1976,
    1979,  1985,  1989,  1996,  2001,  2009,  2016,  2018,  2021,  2024,
    2028,  2032,  2044,  2054,  2062,  2070,  2072,  2076,  2078,  2080,
    2083,  2087,  2092,  2098,  2100,  2102,  2105,  2109,  2113,  2119,
    2124,  2126,  2128,  2132,  2139,  2141,  2143,  2147,  2151,  2161,
    2169,  2171,  2177,  2181,  2188,  2190,  2194,  2196,  2198,  2202,
    2209,  2211,  2213,  2220,  2225,  2230,  2235
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     152,     0,    -1,   153,    -1,     1,     6,    -1,    -1,   153,
     154,    -1,   157,    -1,   156,    -1,   175,    -1,   179,    -1,
     184,    -1,   188,    -1,   189,    -1,   190,    -1,   193,    -1,
     214,    -1,   215,    -1,   216,    -1,   217,    -1,   192,    -1,
     191,    -1,   187,    -1,   218,    -1,   128,    -1,   128,   128,
      -1,    35,   141,     5,   142,     6,    -1,    35,   141,     5,
     142,   155,   231,     6,    -1,    35,   141,     5,   147,   227,
     142,     6,    -1,    35,   141,     5,   147,   227,   142,   155,
     231,     6,    -1,     4,     5,   148,   158,   149,     6,    -1,
      84,     4,   143,   219,   144,     6,    -1,    85,     4,   143,
     219,   144,     6,    -1,    -1,   158,   161,    -1,   158,   165,
      -1,   158,   168,    -1,   158,   170,    -1,   158,   171,    -1,
     219,    -1,   159,   147,   219,    -1,   219,    -1,   160,   147,
     219,    -1,    -1,    -1,     4,   162,   141,   159,   142,   163,
     148,   160,   149,     6,    -1,   231,    -1,   164,   147,   231,
      -1,    -1,    86,   141,   219,   147,   219,   147,   219,   142,
     166,   148,   164,   149,     6,    -1,   231,    -1,   167,   147,
     231,    -1,    -1,    87,   141,   219,   147,   219,   147,   219,
     147,   219,   142,   169,   148,   167,   149,     6,    -1,    88,
     148,   223,   149,   148,   223,   149,     6,    -1,    88,   148,
     223,   149,   148,   223,   149,   148,   223,   149,   148,   223,
     149,     6,    -1,    -1,    89,   172,   148,   160,   149,     6,
      -1,     7,    -1,   121,    -1,   120,    -1,   119,    -1,   118,
      -1,   139,    -1,   138,    -1,     4,   173,   219,     6,    -1,
       4,   143,   219,   144,   173,   219,     6,    -1,     4,   143,
     148,   227,   149,   144,   173,   224,     6,    -1,     4,   143,
     144,     7,   224,     6,    -1,     4,   143,   144,   121,   224,
       6,    -1,     4,   174,     6,    -1,     4,   143,   219,   144,
     174,     6,    -1,     4,     7,   232,     6,    -1,     4,   145,
       4,     7,   232,     6,    -1,     4,   143,   219,   144,   145,
       4,     7,   232,     6,    -1,     4,   145,     4,   173,   219,
       6,    -1,     4,   143,   219,   144,   145,     4,   173,   219,
       6,    -1,     4,   145,     4,   174,     6,    -1,     4,   143,
     219,   144,   145,     4,   174,     6,    -1,     4,   145,    96,
     145,     4,     7,   228,     6,    -1,     4,   143,   219,   144,
     145,    96,   145,     4,     7,   228,     6,    -1,     4,   145,
      97,     7,   229,     6,    -1,     4,   143,   219,   144,   145,
      97,     7,   229,     6,    -1,     4,   104,     7,   219,     6,
      -1,   104,   143,   219,   144,     7,     4,     6,    -1,   104,
     143,   219,   144,   145,     4,     7,   219,     6,    -1,   104,
     143,   219,   144,   145,     4,     7,   232,     6,    -1,   104,
     143,   219,   144,   145,     4,     7,   148,   227,   149,     6,
      -1,    67,   141,     4,   142,   145,     4,     7,   219,     6,
      -1,    67,   141,     4,   142,   145,     4,     7,   232,     6,
      -1,   219,    -1,   232,    -1,    -1,    99,    50,   148,   219,
     149,    -1,    -1,    59,   221,    -1,    46,   141,   219,   142,
       7,   221,     6,    -1,    -1,    63,    46,   180,   141,   176,
     142,     7,   224,     6,    -1,    55,    56,   224,     7,   219,
       6,    -1,    49,   141,   219,   142,     7,   224,     6,    -1,
      68,    49,   224,     6,    -1,    53,   141,   219,   142,     7,
     224,     6,    -1,    47,   141,   219,   142,     7,   224,   178,
       6,    -1,    48,   141,   219,   142,     7,   224,   178,     6,
      -1,    91,   141,   219,   142,     7,   224,     6,    -1,    92,
     141,   219,   142,     7,   224,     6,    -1,    93,   141,   219,
     142,     7,   224,    95,   224,    94,   219,     6,    -1,    49,
      75,   141,   219,   142,     7,   224,     6,    -1,    64,    49,
     141,   219,   142,     7,   224,     6,    -1,    -1,    63,    49,
     181,   141,   176,   142,     7,   224,     6,    -1,    59,    52,
     141,   219,   142,     7,   224,     6,    -1,    60,    52,   141,
     219,   142,     7,   224,   177,     6,    -1,    12,    13,     6,
      -1,    13,    52,   219,     6,    -1,    57,    52,   141,   219,
     142,     7,     5,     5,     5,     6,    -1,    50,   141,   219,
     142,     7,   224,     6,    -1,    51,   141,   219,   142,     7,
     224,     6,    -1,    52,    75,   141,   219,   142,     7,   224,
       6,    -1,    64,    52,   141,   219,   142,     7,   224,   209,
       6,    -1,    64,    52,   141,   219,   142,     7,   224,     4,
     148,   223,   149,   209,     6,    -1,    -1,    63,    52,   182,
     141,   176,   142,     7,   224,     6,    -1,    62,    54,   141,
     219,   142,     7,   224,     6,    -1,    54,   141,   219,   142,
       7,   224,     6,    -1,    64,    54,   141,   219,   142,     7,
     224,     6,    -1,    -1,    63,    54,   183,   141,   176,   142,
       7,   224,     6,    -1,    70,   221,   148,   185,   149,    -1,
      69,   148,   221,   147,   221,   147,   219,   149,   148,   185,
     149,    -1,    71,   221,   148,   185,   149,    -1,    72,   148,
     221,   147,   219,   149,   148,   185,   149,    -1,     4,   148,
     185,   149,    -1,    81,    49,   148,   227,   149,    52,   148,
     219,   149,    -1,    78,    49,   141,   219,   142,   148,   227,
     149,     6,    -1,   186,    -1,   184,    -1,    -1,   186,   179,
      -1,   186,    46,   148,   227,   149,     6,    -1,   186,    49,
     148,   227,   149,     6,    -1,   186,    52,   148,   227,   149,
       6,    -1,   186,    54,   148,   227,   149,     6,    -1,    74,
      59,   141,   219,   142,     7,   224,     6,    -1,    74,    59,
     141,   219,   142,     7,   148,   221,   147,   221,   147,   227,
     149,     6,    -1,    74,    59,   141,   219,   142,     7,   148,
     221,   147,   221,   147,   221,   147,   227,   149,     6,    -1,
      74,    50,   141,   219,   142,     7,   148,   221,   147,   227,
     149,     6,    -1,    74,     4,   141,   219,   142,     7,   224,
       6,    -1,    74,     4,   141,   219,   142,     7,     5,     6,
      -1,    74,     4,   148,   219,   149,     6,    -1,    74,     4,
     141,   219,   142,     7,   148,   221,   147,   221,   147,   227,
     149,     6,    -1,    79,   148,   186,   149,    -1,    79,   104,
     143,   219,   144,     6,    -1,    79,     4,   143,   219,   144,
       6,    -1,    79,     4,     6,    -1,    79,     4,     4,     6,
      -1,    96,   228,   148,   186,   149,    -1,   108,     5,     6,
      -1,   109,     5,     6,    -1,   108,   148,   186,   149,    -1,
     109,   148,   186,   149,    -1,     4,   232,     6,    -1,     4,
       4,   143,   219,   144,   231,     6,    -1,     4,     4,     4,
     143,   219,   144,     6,    -1,     4,   219,     6,    -1,    67,
     141,     4,   142,   145,     4,     6,    -1,    90,     4,     6,
      -1,   103,     6,    -1,    43,     6,    -1,    40,     6,    -1,
      40,   148,   219,   147,   219,   147,   219,   147,   219,   147,
     219,   147,   219,   149,     6,    -1,    41,     6,    -1,    44,
       6,    -1,    98,   141,   219,     8,   219,   142,    -1,    98,
     141,   219,     8,   219,     8,   219,   142,    -1,    98,     4,
      99,   148,   219,     8,   219,   149,    -1,    98,     4,    99,
     148,   219,     8,   219,     8,   219,   149,    -1,   100,    -1,
     107,     4,    -1,   105,    -1,   106,     4,     6,    -1,   101,
     141,   219,   142,    -1,   102,    -1,    73,   221,   148,   186,
     149,    -1,    73,   148,   221,   147,   221,   147,   219,   149,
     148,   186,   149,    -1,    73,   148,   221,   147,   221,   147,
     221,   147,   219,   149,   148,   186,   149,    -1,    -1,    73,
     221,   148,   186,   194,   207,   149,    -1,    -1,    73,   148,
     221,   147,   221,   147,   219,   149,   148,   186,   195,   207,
     149,    -1,    -1,    73,   148,   221,   147,   221,   147,   221,
     147,   219,   149,   148,   186,   196,   207,   149,    -1,    -1,
      73,   148,   186,   197,   207,   149,    -1,    73,    46,   148,
     219,   147,   221,   149,     6,    -1,    73,    49,   148,   219,
     147,   221,   149,     6,    -1,    73,    52,   148,   219,   147,
     221,   149,     6,    -1,    73,    46,   148,   219,   147,   221,
     147,   221,   147,   219,   149,     6,    -1,    73,    49,   148,
     219,   147,   221,   147,   221,   147,   219,   149,     6,    -1,
      73,    52,   148,   219,   147,   221,   147,   221,   147,   219,
     149,     6,    -1,    73,    46,   148,   219,   147,   221,   147,
     221,   147,   221,   147,   219,   149,     6,    -1,    73,    49,
     148,   219,   147,   221,   147,   221,   147,   221,   147,   219,
     149,     6,    -1,    73,    52,   148,   219,   147,   221,   147,
     221,   147,   221,   147,   219,   149,     6,    -1,    -1,    73,
      46,   148,   219,   147,   221,   149,   198,   148,   207,   149,
       6,    -1,    -1,    73,    49,   148,   219,   147,   221,   149,
     199,   148,   207,   149,     6,    -1,    -1,    73,    52,   148,
     219,   147,   221,   149,   200,   148,   207,   149,     6,    -1,
      -1,    73,    46,   148,   219,   147,   221,   147,   221,   147,
     219,   149,   201,   148,   207,   149,     6,    -1,    -1,    73,
      49,   148,   219,   147,   221,   147,   221,   147,   219,   149,
     202,   148,   207,   149,     6,    -1,    -1,    73,    52,   148,
     219,   147,   221,   147,   221,   147,   219,   149,   203,   148,
     207,   149,     6,    -1,    -1,    73,    46,   148,   219,   147,
     221,   147,   221,   147,   221,   147,   219,   149,   204,   148,
     207,   149,     6,    -1,    -1,    73,    49,   148,   219,   147,
     221,   147,   221,   147,   221,   147,   219,   149,   205,   148,
     207,   149,     6,    -1,    -1,    73,    52,   148,   219,   147,
     221,   147,   221,   147,   221,   147,   219,   149,   206,   148,
     207,   149,     6,    -1,   208,    -1,   207,   208,    -1,    82,
     148,   219,   149,     6,    -1,    82,   148,   224,   147,   224,
     149,     6,    -1,    82,   148,   224,   147,   224,   147,   224,
     149,     6,    -1,    76,     6,    -1,    83,   141,   219,   142,
       7,   224,    66,   219,     6,    -1,    -1,     4,    -1,    -1,
      66,     4,   219,    -1,    -1,     4,    -1,    -1,     7,   224,
      -1,    -1,     7,   219,    -1,    61,    49,   225,     7,   219,
     210,     6,    -1,    61,    52,   225,   212,   211,     6,    -1,
      58,    52,   148,   219,   149,     7,   224,     6,    -1,    61,
      54,   225,   212,     6,    -1,    76,    52,   225,   213,     6,
      -1,    77,    52,   224,     7,   219,     6,    -1,    65,    49,
     224,     7,   224,     6,    -1,    65,    52,   224,     7,   224,
       6,    -1,    46,   148,   227,   149,    99,    52,   148,   219,
     149,     6,    -1,    49,   148,   227,   149,    99,    52,   148,
     219,   149,     6,    -1,    49,   148,   227,   149,    99,    54,
     148,   219,   149,     6,    -1,    52,   148,   227,   149,    99,
      54,   148,   219,   149,     6,    -1,    80,     6,    -1,    80,
       4,     6,    -1,   114,   141,   231,   142,     7,   148,   224,
     147,   224,   149,     6,    -1,   115,   141,   231,   142,     7,
     148,   224,   147,   224,   149,     6,    -1,   116,   141,   231,
     142,     7,   148,   224,   147,   224,   149,     6,    -1,   117,
     141,   231,   142,     7,   148,   224,   147,   224,   149,     6,
      -1,   220,    -1,   141,   219,   142,    -1,   132,   219,    -1,
     131,   219,    -1,   136,   219,    -1,   219,   132,   219,    -1,
     219,   131,   219,    -1,   219,   133,   219,    -1,   219,   134,
     219,    -1,   219,   135,   219,    -1,   219,   140,   219,    -1,
     219,   127,   219,    -1,   219,   128,   219,    -1,   219,   130,
     219,    -1,   219,   129,   219,    -1,   219,   126,   219,    -1,
     219,   125,   219,    -1,   219,   124,   219,    -1,   219,   123,
     219,    -1,   219,   122,   219,     8,   219,    -1,    14,   141,
     219,   142,    -1,    15,   141,   219,   142,    -1,    16,   141,
     219,   142,    -1,    17,   141,   219,   142,    -1,    18,   141,
     219,   142,    -1,    19,   141,   219,   142,    -1,    20,   141,
     219,   142,    -1,    21,   141,   219,   142,    -1,    22,   141,
     219,   142,    -1,    24,   141,   219,   142,    -1,    25,   141,
     219,   147,   219,   142,    -1,    26,   141,   219,   142,    -1,
      27,   141,   219,   142,    -1,    28,   141,   219,   142,    -1,
      29,   141,   219,   142,    -1,    30,   141,   219,   142,    -1,
      31,   141,   219,   142,    -1,    32,   141,   219,   147,   219,
     142,    -1,    33,   141,   219,   147,   219,   142,    -1,    34,
     141,   219,   147,   219,   142,    -1,    23,   141,   219,   142,
      -1,    14,   143,   219,   144,    -1,    15,   143,   219,   144,
      -1,    16,   143,   219,   144,    -1,    17,   143,   219,   144,
      -1,    18,   143,   219,   144,    -1,    19,   143,   219,   144,
      -1,    20,   143,   219,   144,    -1,    21,   143,   219,   144,
      -1,    22,   143,   219,   144,    -1,    24,   143,   219,   144,
      -1,    25,   143,   219,   147,   219,   144,    -1,    26,   143,
     219,   144,    -1,    27,   143,   219,   144,    -1,    28,   143,
     219,   144,    -1,    29,   143,   219,   144,    -1,    30,   143,
     219,   144,    -1,    31,   143,   219,   144,    -1,    32,   143,
     219,   147,   219,   144,    -1,    33,   143,   219,   147,   219,
     144,    -1,    34,   143,   219,   147,   219,   144,    -1,    23,
     143,   219,   144,    -1,     3,    -1,     9,    -1,    10,    -1,
      11,    -1,   111,    -1,   112,    -1,   113,    -1,     4,    -1,
       4,   150,   148,   219,   149,    -1,     4,   143,   219,   144,
      -1,   146,     4,   143,   144,    -1,     4,   174,    -1,     4,
     143,   219,   144,   174,    -1,     4,   145,     4,    -1,     4,
     143,   219,   144,   145,     4,    -1,     4,   145,     4,   174,
      -1,     4,   143,   219,   144,   145,     4,   174,    -1,   110,
     141,     5,   147,   219,   142,    -1,   222,    -1,   132,   221,
      -1,   131,   221,    -1,   221,   132,   221,    -1,   221,   131,
     221,    -1,   148,   219,   147,   219,   147,   219,   147,   219,
     147,   219,   149,    -1,   148,   219,   147,   219,   147,   219,
     147,   219,   149,    -1,   148,   219,   147,   219,   147,   219,
     149,    -1,   141,   219,   147,   219,   147,   219,   142,    -1,
     224,    -1,   223,   147,   224,    -1,   219,    -1,   226,    -1,
     148,   149,    -1,   148,   227,   149,    -1,   132,   148,   227,
     149,    -1,   219,   133,   148,   227,   149,    -1,   224,    -1,
       5,    -1,   132,   226,    -1,   219,   133,   226,    -1,   219,
       8,   219,    -1,   219,     8,   219,     8,   219,    -1,    46,
     148,   219,   149,    -1,   184,    -1,   193,    -1,     4,   143,
     144,    -1,     4,   143,   148,   227,   149,   144,    -1,   219,
      -1,   226,    -1,   227,   147,   219,    -1,   227,   147,   226,
      -1,   148,   219,   147,   219,   147,   219,   147,   219,   149,
      -1,   148,   219,   147,   219,   147,   219,   149,    -1,     4,
      -1,     4,   145,    96,   145,     4,    -1,   148,   230,   149,
      -1,     4,   143,   219,   144,   145,    97,    -1,   228,    -1,
     230,   147,   228,    -1,   232,    -1,     4,    -1,     4,   145,
       4,    -1,     4,   143,   219,   144,   145,     4,    -1,     5,
      -1,    42,    -1,    37,   141,   231,   147,   231,   142,    -1,
      38,   141,   231,   142,    -1,    39,   141,   231,   142,    -1,
      36,   141,   231,   142,    -1,    36,   141,   231,   147,   227,
     142,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   156,   156,   157,   162,   164,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   188,   192,   199,   204,   218,   231,   259,
     273,   284,   299,   304,   305,   306,   307,   308,   312,   314,
     319,   321,   327,   431,   326,   449,   456,   467,   466,   484,
     491,   502,   501,   518,   535,   558,   557,   571,   572,   573,
     574,   575,   579,   580,   587,   613,   640,   680,   690,   698,
     710,   722,   731,   737,   746,   764,   782,   791,   803,   808,
     816,   836,   859,   868,   876,   898,   921,   949,   961,   978,
     982,   993,   996,  1009,  1012,  1022,  1046,  1045,  1065,  1087,
    1105,  1127,  1145,  1175,  1205,  1223,  1241,  1267,  1284,  1303,
    1302,  1325,  1343,  1382,  1388,  1394,  1401,  1426,  1451,  1467,
    1485,  1518,  1517,  1541,  1559,  1576,  1593,  1592,  1618,  1623,
    1628,  1633,  1638,  1658,  1664,  1675,  1676,  1681,  1684,  1688,
    1711,  1734,  1757,  1785,  1806,  1827,  1849,  1869,  1981,  2000,
    2020,  2129,  2138,  2144,  2159,  2187,  2204,  2218,  2224,  2230,
    2239,  2253,  2295,  2312,  2327,  2346,  2358,  2382,  2386,  2393,
    2399,  2404,  2410,  2420,  2437,  2454,  2473,  2492,  2522,  2530,
    2536,  2543,  2547,  2556,  2564,  2572,  2581,  2580,  2593,  2592,
    2605,  2604,  2617,  2616,  2629,  2636,  2643,  2650,  2657,  2664,
    2671,  2678,  2685,  2693,  2692,  2704,  2703,  2715,  2714,  2726,
    2725,  2737,  2736,  2748,  2747,  2759,  2758,  2770,  2769,  2781,
    2780,  2795,  2798,  2804,  2813,  2833,  2856,  2860,  2884,  2887,
    2903,  2906,  2922,  2925,  2938,  2941,  2947,  2950,  2957,  3013,
    3083,  3088,  3155,  3198,  3222,  3248,  3280,  3303,  3326,  3329,
    3338,  3342,  3359,  3396,  3432,  3467,  3507,  3508,  3509,  3510,
    3511,  3512,  3513,  3514,  3515,  3522,  3523,  3524,  3525,  3526,
    3527,  3528,  3529,  3530,  3531,  3532,  3533,  3534,  3535,  3536,
    3537,  3538,  3539,  3540,  3541,  3542,  3543,  3544,  3545,  3546,
    3547,  3548,  3549,  3550,  3551,  3552,  3553,  3555,  3556,  3557,
    3558,  3559,  3560,  3561,  3562,  3563,  3564,  3565,  3566,  3567,
    3568,  3569,  3570,  3571,  3572,  3573,  3574,  3575,  3584,  3585,
    3586,  3587,  3588,  3589,  3590,  3594,  3613,  3631,  3646,  3656,
    3672,  3690,  3695,  3700,  3710,  3720,  3728,  3732,  3736,  3740,
    3744,  3751,  3755,  3759,  3763,  3770,  3775,  3782,  3787,  3791,
    3796,  3800,  3808,  3819,  3823,  3835,  3843,  3851,  3858,  3869,
    3889,  3899,  3909,  3919,  3939,  3944,  3948,  3952,  3964,  3968,
    3980,  3987,  3997,  4001,  4016,  4021,  4028,  4032,  4045,  4053,
    4064,  4068,  4076,  4084,  4098,  4112,  4116
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
  "tPrintf", "tSprintf", "tStrCat", "tStrPrefix", "tStrRelative",
  "tBoundingBox", "tDraw", "tToday", "tSyncModel", "tCreateTopology",
  "tDistanceFunction", "tPoint", "tCircle", "tEllipse", "tLine", "tSphere",
  "tPolarSphere", "tSurface", "tSpline", "tVolume", "tCharacteristic",
  "tLength", "tParametric", "tElliptic", "tPlane", "tRuled",
  "tTransfinite", "tComplex", "tPhysical", "tCompound", "tPeriodic",
  "tUsing", "tPlugin", "tDegenerated", "tRotate", "tTranslate",
  "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tLoop", "tRecombine",
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tIntersect", "tLayers",
  "tHole", "tAlias", "tAliasWithOptions", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tEndIf", "tExit", "tField", "tReturn", "tCall",
  "tFunction", "tShow", "tHide", "tGetValue", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tHomRank", "tHomGen",
  "tHomCut", "tHomSeq", "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS",
  "tAFFECTPLUS", "'?'", "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'",
  "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'",
  "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All",
  "GeoFormatItems", "GeoFormatItem", "SendToFile", "Printf", "View",
  "Views", "ElementCoords", "ElementValues", "Element", "@1", "@2",
  "Text2DValues", "Text2D", "@3", "Text3DValues", "Text3D", "@4",
  "InterpolationMatrix", "Time", "@5", "NumericAffectation",
  "NumericIncrement", "Affectation", "PhysicalId", "InSphereCenter",
  "CircleOptions", "Shape", "@6", "@7", "@8", "@9", "Transform",
  "MultipleShape", "ListOfShapes", "LevelSet", "Delete", "Colorify",
  "Visibility", "Command", "Loop", "Extrude", "@10", "@11", "@12", "@13",
  "@14", "@15", "@16", "@17", "@18", "@19", "@20", "@21", "@22",
  "ExtrudeParameters", "ExtrudeParameter", "CompoundMap",
  "TransfiniteType", "TransfiniteArrangement", "TransfiniteCorners",
  "RecombineAngle", "Transfinite", "Periodic", "Embedding", "Coherence",
  "Homology", "FExpr", "FExpr_Single", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", 0
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
     375,   376,    63,   377,   378,   379,   380,    60,    62,   381,
     382,    43,    45,    42,    47,    37,    33,   383,   384,   385,
      94,    40,    41,    91,    93,    46,    35,    44,   123,   125,
     126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   151,   152,   152,   153,   153,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   155,   155,   156,   156,   156,   156,   157,
     157,   157,   158,   158,   158,   158,   158,   158,   159,   159,
     160,   160,   162,   163,   161,   164,   164,   166,   165,   167,
     167,   169,   168,   170,   170,   172,   171,   173,   173,   173,
     173,   173,   174,   174,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   176,
     176,   177,   177,   178,   178,   179,   180,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   181,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   182,   179,   179,   179,   179,   183,   179,   184,   184,
     184,   184,   184,   184,   184,   185,   185,   186,   186,   186,
     186,   186,   186,   187,   187,   187,   187,   187,   187,   187,
     187,   188,   188,   188,   188,   188,   189,   190,   190,   190,
     190,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   193,   193,   193,   194,   193,   195,   193,
     196,   193,   197,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   198,   193,   199,   193,   200,   193,   201,
     193,   202,   193,   203,   193,   204,   193,   205,   193,   206,
     193,   207,   207,   208,   208,   208,   208,   208,   209,   209,
     210,   210,   211,   211,   212,   212,   213,   213,   214,   214,
     214,   214,   214,   214,   215,   215,   216,   216,   216,   216,
     217,   217,   218,   218,   218,   218,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   221,   221,   221,   221,
     221,   222,   222,   222,   222,   223,   223,   224,   224,   224,
     224,   224,   224,   225,   225,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   227,   227,   227,   227,   228,   228,
     228,   228,   229,   229,   230,   230,   231,   231,   231,   231,
     232,   232,   232,   232,   232,   232,   232
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     7,     7,     9,     6,
       6,     6,     0,     2,     2,     2,     2,     2,     1,     3,
       1,     3,     0,     0,    10,     1,     3,     0,    13,     1,
       3,     0,    15,     8,    14,     0,     6,     1,     1,     1,
       1,     1,     1,     1,     4,     7,     9,     6,     6,     3,
       6,     4,     6,     9,     6,     9,     5,     8,     8,    11,
       6,     9,     5,     7,     9,     9,    11,     9,     9,     1,
       1,     0,     5,     0,     2,     7,     0,     9,     6,     7,
       4,     7,     8,     8,     7,     7,    11,     8,     8,     0,
       9,     8,     9,     3,     4,    10,     7,     7,     8,     9,
      13,     0,     9,     8,     7,     8,     0,     9,     5,    11,
       5,     9,     4,     9,     9,     1,     1,     0,     2,     6,
       6,     6,     6,     8,    14,    16,    12,     8,     8,     6,
      14,     4,     6,     6,     3,     4,     5,     3,     3,     4,
       4,     3,     7,     7,     3,     7,     3,     2,     2,     2,
      15,     2,     2,     6,     8,     8,    10,     1,     2,     1,
       3,     4,     1,     5,    11,    13,     0,     7,     0,    13,
       0,    15,     0,     6,     8,     8,     8,    12,    12,    12,
      14,    14,    14,     0,    12,     0,    12,     0,    12,     0,
      16,     0,    16,     0,    16,     0,    18,     0,    18,     0,
      18,     1,     2,     5,     7,     9,     2,     9,     0,     1,
       0,     3,     0,     1,     0,     2,     0,     2,     7,     6,
       8,     5,     5,     6,     6,     6,    10,    10,    10,    10,
       2,     3,    11,    11,    11,    11,     1,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     6,     6,     6,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     4,     2,
       5,     3,     6,     4,     7,     6,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     1,     3,     1,     1,     2,
       3,     4,     5,     1,     1,     2,     3,     3,     5,     4,
       1,     1,     3,     6,     1,     1,     3,     3,     9,     7,
       1,     5,     3,     6,     1,     3,     1,     1,     3,     6,
       1,     1,     6,     4,     4,     4,     6
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
       0,     0,     0,     0,     0,   177,     0,   182,     0,     0,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       7,     6,     8,     9,    10,    21,    11,    12,    13,    20,
      19,    14,    15,    16,    17,    18,    22,   318,   325,   380,
      57,   319,   320,   321,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   381,
       0,     0,   322,   323,   324,    61,    60,    59,    58,     0,
       0,     0,    63,    62,     0,     0,     0,     0,   137,     0,
       0,     0,   256,     0,     0,     0,     0,   169,     0,   171,
     168,   172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,   109,   121,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,     0,     0,     0,     0,     0,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,   250,
       0,     0,     0,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,   167,     0,     0,   178,     0,   137,     0,
     137,     0,     0,     0,     0,     0,     0,     0,     0,   329,
      32,   380,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   325,   259,   258,   260,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,     0,   135,     0,    69,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,   113,     0,     0,     0,
       0,   325,     0,     0,   360,   361,   364,   365,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   347,     0,   348,     0,     0,     0,     0,   354,
     353,     0,   234,   234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   338,   337,     0,
       0,     0,     0,   137,   137,     0,     0,     0,     0,     0,
       0,     0,   192,     0,   137,     0,     0,     0,     0,   236,
       0,     0,     0,   154,     0,     0,     0,   251,     0,     0,
       0,   166,     0,     0,     0,     0,     0,   137,     0,     0,
       0,     0,   180,   157,     0,   158,     0,   377,     0,   376,
       0,     0,     0,     0,     0,   331,     0,     0,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   257,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,   132,
       0,     0,     0,     0,   138,    64,     0,   274,   273,   272,
     271,   267,   268,   270,   269,   262,   261,   263,   264,   265,
     266,   114,     0,     0,     0,     0,     0,     0,   258,   355,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   349,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
       0,     0,     0,   340,   339,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   186,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,     0,   151,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,     0,
     159,   160,     0,     0,     0,     0,     0,     0,     0,   327,
     333,     0,    42,     0,     0,     0,    55,     0,    33,    34,
      35,    36,    37,   276,   297,   277,   298,   278,   299,   279,
     300,   280,   301,   281,   302,   282,   303,   283,   304,   284,
     305,   296,   317,   285,   306,     0,     0,   287,   308,   288,
     309,   289,   310,   290,   311,   291,   312,   292,   313,     0,
       0,     0,     0,     0,     0,   385,     0,     0,   383,   384,
      82,     0,     0,     0,     0,     0,    57,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,   328,     0,     0,
       0,     0,     0,    25,    23,     0,     0,     0,     0,   362,
       0,     0,   357,   263,   356,   366,   367,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     350,     0,     0,     0,     0,     0,     0,   230,   235,   233,
       0,   241,     0,     0,    89,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,   130,
       0,     0,     0,     0,     0,     0,     0,     0,   221,     0,
     183,     0,     0,     0,     0,     0,   237,   242,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,     0,     0,     0,     0,     0,   378,     0,     0,     0,
       0,     0,     0,   330,     0,   326,     0,     0,     0,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   327,    67,    68,     0,     0,     0,     0,
       0,    70,    72,    74,     0,     0,   374,     0,    80,     0,
       0,     0,     0,   275,    24,     0,     0,     0,     0,     0,
     359,     0,     0,    93,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   351,     0,    98,     0,     0,
       0,     0,     0,     0,   239,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   245,     0,     0,     0,     0,     0,
       0,     0,     0,   226,     0,     0,   193,   222,     0,     0,
       0,   149,     0,     0,   243,     0,   153,   152,     0,    30,
      31,     0,     0,     0,   371,     0,     0,     0,   173,     0,
       0,     0,     0,     0,     0,     0,   163,   332,   162,     0,
       0,     0,     0,   345,     0,   286,   307,   293,   314,   294,
     315,   295,   316,   386,   382,   335,     0,    57,     0,     0,
       0,     0,    65,     0,     0,     0,   372,     0,     0,     0,
       0,    26,    27,     0,     0,    95,     0,   358,     0,     0,
       0,     0,     0,    99,     0,     0,   116,   117,     0,     0,
     101,   124,   352,     0,     0,     0,    91,     0,   238,     0,
       0,     0,     0,     0,     0,   228,     0,   165,     0,     0,
       0,     0,   137,     0,   203,     0,   205,     0,   207,   347,
       0,     0,     0,     0,   187,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,   334,     0,    38,     0,
       0,     0,     0,     0,    40,     0,     0,     0,    77,     0,
       0,    78,     0,   375,   139,   140,   141,   142,     0,     0,
     363,     0,    94,   102,   103,   107,     0,     0,   118,     0,
       0,   240,   111,     0,     0,   231,   123,     0,     0,     0,
       0,   108,   229,     0,   125,     0,     0,     0,   344,     0,
     343,     0,     0,   194,     0,     0,   195,     0,     0,   196,
       0,     0,     0,     0,     0,     0,   148,     0,     0,   147,
       0,     0,   143,     0,     0,     0,     0,   369,     0,   175,
     174,     0,     0,     0,   379,     0,     0,     0,     0,    43,
       0,     0,     0,   346,     0,     0,     0,    66,    73,    75,
       0,    81,     0,    28,     0,     0,     0,     0,     0,     0,
       0,   112,    97,   110,   122,   127,     0,   119,    87,    88,
     137,     0,   131,     0,     0,     0,     0,     0,     0,   223,
       0,     0,   137,     0,     0,     0,     0,   134,   133,     0,
       0,     0,     0,    84,    85,     0,     0,     0,     0,     0,
      39,     0,     0,     0,    41,    56,     0,   373,     0,   246,
     247,   248,   249,   115,     0,     0,     0,     0,   342,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,     0,     0,     0,     0,     0,   368,   176,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       0,   228,   129,     0,   209,     0,     0,   211,     0,     0,
     213,     0,     0,     0,   224,     0,   184,     0,   137,     0,
       0,     0,   106,    86,   252,   253,   254,   255,     0,    47,
       0,    53,     0,     0,    92,   229,     0,   341,   197,     0,
       0,   204,   198,     0,     0,   206,   199,     0,     0,   208,
       0,     0,     0,   190,     0,   146,     0,     0,     0,     0,
       0,     0,     0,   120,     0,   215,     0,   217,     0,   219,
     225,   227,   189,   185,     0,     0,     0,     0,    44,     0,
      51,     0,     0,     0,   200,     0,     0,   201,     0,     0,
     202,     0,     0,   150,     0,   144,     0,    45,     0,     0,
     170,     0,     0,     0,     0,     0,     0,   191,     0,     0,
       0,     0,     0,   210,     0,   212,     0,   214,     0,   145,
      46,    48,     0,    49,     0,     0,     0,     0,     0,     0,
      54,   216,   218,   220,    50,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    69,   705,    70,    71,   437,  1037,  1043,
     628,   806,  1189,  1336,   629,  1299,  1362,   630,  1338,   631,
     632,   810,   139,   239,    72,   743,  1074,   970,   504,   365,
     366,   367,   368,   334,   305,   306,    75,    76,    77,    78,
      79,    80,   335,   771,  1257,  1314,   582,  1094,  1097,  1100,
    1279,  1283,  1287,  1325,  1328,  1331,   767,   768,  1083,   873,
     740,   556,   590,    82,    83,    84,    85,    86,   352,   142,
     378,   191,   932,   933,   361,   354,   547,   219,   696,   837,
     428,   429
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1118
static const yytype_int16 yypact[] =
{
    3266,    62,     9,  3372, -1118, -1118,  1673,    45,    29,     2,
      27,   113,   154,   196,   -41,    73,    82,   -33,   138,   139,
     -31,   149,   159,   147,   165,   242,   281,   282,   382,   305,
     438,   462,    85,   235,   344,   218,   188,   188,   246,   325,
     278,   345,   348,   357,    22,    58,   363,   422,   428,   433,
     309,   313,   319,    19,    39, -1118,   341, -1118,   440,   310,
   -1118,   468,   481,    26,    30,   353,   354,   378,   390, -1118,
   -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118,
   -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118,    23,   384,
     383, -1118, -1118, -1118,   212,   226,   272,   333,   386,   387,
     420,   477,   511,   515,   519,   528,   533,   536,   537,   557,
     570,   573,   580,   593,   602,   399,   400,   410,   431, -1118,
     482,   435, -1118, -1118, -1118, -1118, -1118, -1118, -1118,   839,
     839,   839, -1118, -1118,   839,  2642,    15,   578,    32,   839,
     581,  1528, -1118,   596,   632,   839,   600, -1118,   839, -1118,
   -1118, -1118,   839,  3028,   839,   839,   506,   839,  3028,   839,
     839,   507,  3028,   839,   839,  2009,   510,   543,   540,   561,
    1729,  1729,  1729,   562, -1118, -1118, -1118, -1118,   569,   574,
     579,  2009,  2009,   722,  2009,   188,   188,   188,   839,   839,
      53, -1118,   225,   188,   582,   587,   590,  2888,   292,   -32,
     586,   606,  1729,  2009,   612,    34,   631, -1118,   774, -1118,
     648,   657,   671,   811,   839,   839,   839,   681,   839,   684,
     740,   839,   839, -1118,   839,   834, -1118,   841, -1118,   845,
   -1118,   508,   508,   508,   508,   709,   839,   871,   730, -1118,
   -1118, -1118,   873,   839,   839,   839,   839,   839,   839,   839,
     839,   839,   839,   839,   839,   839,   839,   839,   839,   839,
     839,   839,   839,   839,   839,   839,   839,   839,   839,   839,
     839,   839,   839,   839,   839,   839,   839,   839,   839,   839,
     839,   839,   839,   839,   839,   508,   508,   508,   508,   839,
     882,   594,   750,   750,   750,  5504,    60,  3028,  4768,   204,
     776,   919,   791,   781, -1118,   787,  3190,  1722, -1118, -1118,
     839,   839,   839,   839,   839,   839,   839,   839,   839,   839,
     839,   839,   839,   839,   839, -1118, -1118,  1797,   -53,  4066,
    5525,   680,   789,  3028, -1118, -1118,  2703, -1118,   599,  5546,
    5567,   839,  5588,   605,  5609,  5630,   839,   622,  5651,  5672,
    2149,  1496,  2801,   931, -1118,   839,   839,   839,   839, -1118,
   -1118,   932,   933,   933,   839,   800,   802,   803,   805,   839,
     839,   839,   940,   946,   812,   950,   -52, -1118, -1118,  4092,
    4118,   188,   188,    32,    32,   199,   839,   839,   839,  2888,
    2888,   839,  3190,   317, -1118,   839,   839,   839,   839,   951,
     952,   839,   954, -1118,   839,   839,  1167, -1118,  3028,   839,
     839, -1118,  5693,  5714,  5735,   861,  4144, -1118,   813,  2843,
    5756,  4791, -1118, -1118,  1231, -1118,  1532,   627,   821, -1118,
     822,   824,   825,   839,  4814,  -109,   839,    10, -1118,  5777,
    4837,  5798,  4860,  5819,  4883,  5840,  4906,  5861,  4929,  5882,
    4952,  5903,  4975,  5924,  4998,  5945,  5021,  5966,  5044,  5987,
    5067,  4170,  4196,  6008,  5090,  6029,  5113,  6050,  5136,  6071,
    5159,  6092,  5182,  6113,  5205,  4222,  4248,  4274,  4300,  4326,
    4352,   151,   827,   830,   835,  1937,   831,   839, -1118,  2009,
    2009,   628,    86,   383,   839,   973,   979,    21,   847, -1118,
      51,    -3,   -30,   144, -1118, -1118,  2881,   502,   659,   676,
     676,   476,   476,   476,   476,   444,   444,   750,   750,   750,
     750, -1118,     7,  3028,   839,   986,  2849,   839,   750, -1118,
     839,  3028,  3028,   895,   993,   994,  6134,   995,   904,   997,
     999,  6155,   908,  1001,  1002,  3028, -1118,   629,  2289,   839,
    6176,  3265,  6197,  6218,   839,  2009,  1007,  1006,  6239,  3162,
    3162,  3162,  3162,  6260,  6281,  6302,  2009,  2009,   870, -1118,
     188,   839,   839, -1118, -1118,   868,   869,   839,  4378,  4404,
    4430,  4040,   -26,   188,  1905,  6323,  3396,  6344,  6365,   839,
    1013,   839,  6386, -1118,  5228,  5251, -1118,   634,  5274,  5297,
    1014,  1015,  1016,   880,   839,  2045,   839,   839, -1118,     5,
   -1118, -1118,   839,  1022,  1020,  1023,  1024,  1025,  5320,    48,
   -1118,  3424, -1118,   888,   894,   906, -1118,  1046, -1118, -1118,
   -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118,
   -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118,
   -1118, -1118, -1118, -1118, -1118,   839,   839, -1118, -1118, -1118,
   -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118,   839,
     839,   839,   839,   839,   839, -1118,  3028,   508, -1118, -1118,
   -1118,   839,  5343,  1049,  1051,   914, -1118,    24,   839,  1053,
    1054,  2077, -1118,  1056,   918,    19,  1058, -1118,  3028,  3028,
    3028,  3028,   839, -1118,   938,   508,   179,  4456,   188, -1118,
    3028,  3452,  2955,   750, -1118,  2703, -1118,  1032,  2009,  2009,
    1060,  2009,   743,  2009,  2009,  1078,  1034,  2009,  2009,   666,
   -1118,  3028,  2217,  1079,  1083,  1084,  1085,   375, -1118, -1118,
    1087, -1118,  1088,   955,  1703, -1118,   956,   958,   961,  1089,
    1097,  1098,  1100,  1102,  1090,   336,  4482,  4508, -1118, -1118,
    3480,   188,   188,   188,  1103,   963,   975,   -35, -1118,   339,
   -1118,   -26,  1110,  1112,  1113,  1114,  1703, -1118,  2357,   971,
    1116,  1117,  1073,  1120,  1121,  2009,  2009,  2009,  1124,  4534,
   -1118,  2988,   947,  1126,  1127,  5366, -1118,   984,   985,   987,
     988,  1128,  1134, -1118,  1135, -1118,  1004,   839,   839,  2009,
     992, -1118,  6407,  5389,  6428,  5412,  6449,  5435,  6470,  5458,
     228,  1005,  6491,    89, -1118, -1118,    76,   290,   998,  1141,
    2389, -1118, -1118, -1118,    19,   839, -1118,   675, -1118,   686,
     689,   697,   727,  1703, -1118,  1143,    43,   839,    -1,   736,
   -1118,   839,  1003,  1091,  1091,  2009,  1152,  1012,  1017,  1156,
    1158,  2009,  1018,  1161,  1162, -1118,   737, -1118,  1165,  2009,
    2009,  2009,  1168,  1169, -1118,  2009,  1164,  1170,  1171,  1174,
    2009,  2009,  2009, -1118, -1118,    99,   839,   839,   839,  1026,
     286,   312,   331, -1118,  2009,   839, -1118, -1118,  2888,   -22,
    1869, -1118,  1028,  2429, -1118,  3028, -1118, -1118,  1035, -1118,
   -1118,  1176,  1178,  1092, -1118,   839,   839,   839, -1118,  1182,
    1183,  1044,  2009,  2009,  2009,  2009, -1118,  -109, -1118,   839,
    4560,  4586,   744, -1118,   839, -1118, -1118, -1118, -1118, -1118,
   -1118, -1118, -1118, -1118, -1118, -1118,  2009,   383,   839,  1185,
    1189,    21, -1118,  1190,  5481,    19, -1118,  1191,  1193,  1194,
    1196, -1118, -1118,   508,  4612, -1118,  1059,  1703,   839,   188,
    1198,  1199,  1200, -1118,   839,   839, -1118, -1118,  1201,   839,
   -1118, -1118, -1118,  1203,  1204,  1205,  1096,   839, -1118,  1206,
    2009,  2009,  2009,  2009,  1217,  1221,  1226, -1118,  3162,  3508,
    6512,  3021,    32,   188,  1227,   188,  1228,   188,  1230,   633,
    1094,  6533,  3536,   391, -1118,  1232,  1342,  1240,   188,  1342,
    1241,   747,   839, -1118, -1118,  2009,  3083,   916,  6554, -1118,
    2709,  1233,  1101,  1104,  1105,  1107, -1118,   254,  1703,   839,
     839,  2009,  1108,   748,  1703,  1244,  1251,  2422, -1118,  1254,
    1256, -1118,  1118, -1118, -1118, -1118, -1118, -1118,  1263,   839,
   -1118,  3564,    57, -1118, -1118, -1118,  3592,  3620, -1118,  3648,
    1267, -1118, -1118,  1223,  1270,  1703, -1118,  1281,  1283,  1286,
    1290, -1118,  1149,  1292, -1118,  2497,  1294,  1153, -1118,   839,
   -1118,  1154,   405, -1118,  1159,   443, -1118,  1163,   449, -1118,
    1166,  1296,  2009,  1297,  1172,   839, -1118,  2569,   457, -1118,
     512,   514, -1118,  1300,  3676,  1215,   839, -1118,   839, -1118,
   -1118,  3028,  2562,  1306, -1118,  2009,  2009,  2009,  2009, -1118,
     839,  4638,  4664, -1118,  2009,   839,  1307, -1118, -1118, -1118,
      19, -1118,  1218, -1118,  4690,  1311,  1312,  1313,  1315,  1319,
    1179, -1118, -1118, -1118, -1118, -1118,  2009, -1118, -1118, -1118,
      32,  3368, -1118,  2888,   -26,  2888,   -26,  2888,   -26, -1118,
     751,  2009, -1118,  3704,   188,  3028,   188, -1118, -1118,   839,
    3732,  3760,   754, -1118, -1118,  1177,  1180,  1181,  1186,  1188,
    1703,   839,   839,   755,  1703, -1118,  1322, -1118,   839, -1118,
   -1118, -1118, -1118, -1118,   839,   758,  1192,   839, -1118,  3788,
     541,   -17,  3816,   552,   -13,  3844,   554,    -5,  2009,  1325,
    1271,  2185,  1195,   558,   759,   575,  2637, -1118, -1118,  1332,
    1333,  1334,  1336,  1338,   839,  6575,  4716,    31, -1118,  4742,
    3872,  1343, -1118,  3900,  1344,   839,  1348,  1349,   839,  1371,
    1372,   839,  1373,  1234, -1118,   839, -1118,   -26, -1118,  3028,
    1375,  2569, -1118, -1118, -1118, -1118, -1118, -1118,   765, -1118,
     839, -1118,  2009,   839, -1118, -1118,  1376, -1118, -1118,  1236,
    3928, -1118, -1118,  1237,  3956, -1118, -1118,  1238,  3984, -1118,
    1381,  2671,   137,  2325,   766, -1118,   577,   769,  1383,  1242,
    6596,   770,  4012, -1118,   -26,  1385,   -26,  1386,   -26,  1387,
   -1118, -1118, -1118, -1118,   -26,  1388,  3028,  1389, -1118,   508,
   -1118,  1249,  1392,   150, -1118,  1252,   153, -1118,  1253,   205,
   -1118,  1255,   213, -1118,   773, -1118,   778, -1118,  1257,  2009,
   -1118,  1393,   -26,  1398,   -26,  1400,   -26, -1118,  1401,   508,
    1403,   508,   783, -1118,   256, -1118,   265, -1118,   296, -1118,
   -1118, -1118,   786, -1118,  1413,  1415,  1418,  1419,   508,  1420,
   -1118, -1118, -1118, -1118, -1118, -1118
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1118, -1118, -1118, -1118,   503, -1118, -1118, -1118, -1118,   114,
   -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118,
   -1118, -1118,  -292,     4, -1118,    52, -1118,   576,  1428, -1118,
   -1118, -1118, -1118,     3,  -381,  -196, -1118, -1118, -1118, -1118,
   -1118, -1118,  1429, -1118, -1118, -1118, -1118, -1118, -1118, -1118,
   -1118, -1118, -1118, -1118, -1118, -1118,  -689,  -759,   192, -1118,
   -1118,  1071, -1118, -1118, -1118, -1118, -1118, -1118,    -6, -1118,
     -21, -1118, -1117,   547,   -80,   289,  -107,  -671,   484, -1118,
    -212,    -2
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     141,   392,   575,   576,   143,   965,    74,   494,   897,     5,
     140,   406,   793,   703,   622,   190,   192,  1193,   198,   299,
     430,   431,   432,   217,   836,   694,   205,   235,   827,   132,
     133,   227,   424,   147,   426,   229,   303,  1271,   402,  1205,
     403,   764,   156,   220,   161,   161,   338,   765,   766,   962,
     764,   343,   427,   241,   764,   347,   765,   766,   144,   764,
     765,   766,   208,   764,   209,   765,   766,   489,     4,   765,
     766,   764,   156,   481,   482,   483,   484,   765,   766,   381,
     382,   145,   899,   686,   115,   116,   117,   118,   242,   522,
     119,   362,   363,   686,   523,   570,   623,   624,   625,   626,
     152,    35,    36,    37,    38,   997,   998,   153,   157,   395,
      43,   300,   301,    46,   896,   158,   396,   162,   700,   149,
     828,   829,   399,   292,   293,   294,   206,  1014,   295,   298,
     381,   382,  1246,   307,   181,   704,  1249,   182,   157,   327,
     897,   304,   329,   146,  1252,   699,   330,   336,   339,   340,
     794,   342,   336,   344,   345,  1301,   336,   348,   349,   627,
     150,   132,   133,   953,   376,   377,   236,   218,   237,   695,
     207,   704,   385,   238,   228,   148,   393,   404,   230,  1272,
     221,   490,   379,   380,   381,   382,   132,   133,   381,   382,
     491,   380,   152,   802,   125,   126,   127,   128,   584,   698,
     688,   383,   151,   165,   125,   126,   127,   128,   412,   413,
     414,   493,   416,   764,   154,   419,   420,   166,   421,   765,
     766,   605,  1352,   155,   132,   133,   764,   132,   133,   764,
     434,   687,   765,   766,   802,   765,   766,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   159,
     160,   764,   199,   485,  1053,   164,  1312,   765,   766,   764,
     163,   336,   701,   675,   167,   765,   766,   947,   676,  1341,
     164,   597,  1343,   495,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   186,
     187,   846,   125,   126,   127,   128,   532,   528,   200,   188,
     381,   382,   764,   168,   169,   536,   189,   201,   765,   766,
     541,   764,   132,   133,   528,   336,   577,   765,   766,   550,
     551,   552,   553,   243,  1345,   244,   381,   382,   558,   173,
     573,   574,  1347,   563,   564,   565,   185,   245,   377,   246,
     943,   194,   764,   384,   195,   532,   183,   196,   765,   766,
     578,   579,   580,   292,   293,   581,   304,   304,   241,   585,
     586,   587,   588,   184,   193,   592,  1129,   202,   594,   595,
     203,  1130,   336,   598,   599,  1365,   204,   804,   125,   126,
     127,   128,   210,   247,  1366,   248,   706,   381,   382,   115,
     116,   117,   118,   381,   382,   119,   211,   618,   132,   133,
     621,   170,   212,  1003,   171,  1004,   172,   213,   729,   620,
     394,   872,   337,   381,   382,  1367,   223,   337,   381,   382,
     214,   337,   897,   224,   215,   897,   186,   187,   897,  1005,
     216,  1006,   381,   382,   583,   821,   188,   381,   382,  1196,
     381,   382,   225,   197,   249,  1211,   250,  1214,  1007,  1217,
    1008,   682,   222,   886,   174,   226,   898,   175,   691,   289,
     176,   690,   177,   845,   231,   232,   689,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   178,   427,   241,   179,   324,   180,   336,   707,   233,
     682,   711,   381,   382,   712,   713,   715,   251,   253,   252,
     254,   234,   240,   897,   946,   948,   381,   382,  1105,   336,
     285,   286,   713,   732,   115,   116,   117,   118,   737,   755,
     119,   287,  1163,   744,   744,   744,   744,   745,   745,   745,
     745,   255,   769,   256,   897,   756,   757,   897,  1292,   820,
     897,   760,   288,   897,   381,   382,   290,   321,   322,   323,
     381,   382,   302,   776,   324,   778,   337,   308,   381,   382,
    1165,   839,   840,   841,   842,   897,  1167,   897,   789,   897,
     791,   792,   325,   849,  1174,   328,   795,   319,   320,   321,
     322,   323,   746,   747,   748,  1323,   324,  1326,   257,  1329,
     258,  1091,   529,   803,   866,  1332,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   326,   529,
     337,   530,   324,   381,   382,   381,   382,   341,   346,   812,
     813,   355,   259,  1354,   260,  1356,   261,  1358,   262,  1175,
     263,  1176,   264,   814,   815,   816,   817,   818,   819,   265,
     336,   266,   381,   382,   267,   822,   268,   269,   271,   270,
     272,   357,   830,   381,   382,   381,   382,   848,  1245,   381,
     382,   356,   336,   336,   336,   336,   843,   337,   273,  1248,
     274,  1251,   358,   364,   336,  1259,   381,   382,   381,   382,
     369,   275,   353,   276,   277,   370,   278,   360,   360,   360,
     371,   279,  1261,   280,  1316,   336,   374,   397,   372,   373,
     386,   375,   132,   133,   281,   387,   282,   487,   388,   237,
     890,   891,   892,   283,   238,   284,   532,   398,   533,   360,
     400,  1058,   532,   401,   538,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   548,   322,   323,   532,
     612,   542,   613,   324,   405,   532,   532,   685,   730,  1206,
     407,   532,  1101,   782,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   857,   408,   858,  1021,   324,
     409,   930,   931,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   337,   532,   410,   865,   324,   411,   132,   133,
     714,   716,   955,   526,   956,   237,   415,   803,   138,   954,
     238,   949,   417,   532,   337,   957,   532,   714,   958,   418,
     422,   964,    87,   291,   532,   967,   959,   423,    91,    92,
      93,   425,   433,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   532,   435,   960,  1013,   436,   438,
     999,  1000,  1001,   532,   532,   966,   982,   486,  1009,  1011,
     324,  1041,  1012,  1042,   532,  1135,  1113,  1136,  1218,   336,
    1219,   532,  1041,  1229,  1237,  1041,   532,  1241,  1260,  1026,
    1027,  1028,  1135,   532,  1298,  1315,   532,  1041,  1317,  1321,
     532,   496,  1348,  1038,  1118,  1349,   497,  1350,  1044,   138,
    1041,  1036,  1364,  1368,   498,  1369,   499,   527,   549,   554,
     555,   559,  1047,   560,   561,  1046,   562,   566,  1062,   121,
     122,   123,   124,   567,   568,   917,   569,   603,   589,   591,
     593,   606,  1061,   614,   615,   337,   616,   617,  1066,  1067,
     129,   130,   678,  1069,   677,   131,  1221,   679,   681,   692,
     134,  1075,  1092,   693,  1095,   137,  1098,   337,   337,   337,
     337,   697,  1085,   708,   717,  1108,  1086,  1110,  1111,   337,
     718,   719,   721,   722,   723,   304,   724,   726,   727,   728,
     336,   739,   741,   336,  1182,   754,  1114,   758,   759,   777,
     337,   785,   786,   787,  1122,   788,   796,   797,  1123,   807,
     798,   799,   800,  1131,  1132,   808,   683,   684,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   811,  1144,   809,   824,   324,   825,   826,   831,
     832,   835,  1293,   834,   838,  1119,   844,   855,  1224,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,  1161,   852,   861,   868,   324,   862,   918,
     869,   870,   871,   874,   885,   875,   880,   876,   877,  1173,
     878,   528,   738,   879,   881,   882,   883,  1337,   884,   893,
    1180,   894,  1181,   752,   753,   336,   895,   900,   901,   905,
     902,   903,   906,   907,  1190,   908,   909,   910,   914,  1194,
     919,   920,   922,   923,   926,   924,   925,  1360,   927,  1363,
     934,   928,  1210,   950,  1213,   929,  1216,   944,   951,   961,
     969,   968,  1294,  1223,  1297,  1225,  1374,  1209,   973,  1212,
     974,  1215,   976,   304,   977,   975,   979,   980,   981,   336,
     983,   990,   987,  1226,  1002,   988,  1018,   991,   992,     7,
       8,   993,  1023,  1022,  1024,  1235,  1236,  1025,  1029,  1031,
    1030,  1048,  1239,  1049,   337,  1073,  1051,  1054,  1240,  1055,
    1056,  1243,  1057,  1060,  1063,  1064,  1065,  1068,  1070,  1334,
    1071,  1072,  1076,   500,    15,    16,   501,    18,    19,   502,
      21,   503,    23,  1081,    24,  1082,    26,    27,  1044,    29,
      30,    31,  1084,  1093,  1096,    34,  1099,  1124,  1106,  1280,
    1296,  1102,  1284,     7,     8,  1288,  1109,  1112,  1125,  1291,
    1137,  1126,  1127,   336,  1128,   336,  1134,  1138,    50,    51,
      52,  1140,  1141,  1142,  1300,   853,   854,  1302,   856,  1143,
     859,   860,  1149,  1150,   863,   864,  1151,   500,    15,    16,
     501,    18,    19,   502,    21,   503,    23,  1152,    24,  1153,
      26,    27,  1154,    29,    30,    31,  1155,  1156,  1157,    34,
    1159,  1160,  1169,  1162,  1171,   337,  1177,  1164,   337,  1179,
     336,  1166,  1184,  1195,  1168,  1197,   596,  1199,  1200,  1201,
    1172,  1202,    50,    51,    52,  1203,  1230,  1204,  1238,  1231,
    1232,  1254,   911,   912,   913,  1233,  1234,  1255,  1263,  1264,
    1265,  1242,  1266,  1258,  1267,    87,   331,  1275,  1268,   963,
    1278,    91,    92,    93,  1281,  1282,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,  1285,  1286,  1289,
     610,  1295,  1303,  1290,  1304,  1306,  1308,  1310,   332,  1318,
    1319,  1324,  1327,  1330,  1333,  1335,   529,  1339,  1340,  1353,
    1342,  1344,   972,  1346,  1355,  1351,  1357,  1359,   978,  1361,
     337,    35,    36,    37,    38,    39,   984,   985,   986,  1370,
      43,  1371,   989,    46,  1372,  1373,  1375,   994,   995,   996,
     971,    73,    81,  1276,   557,  1050,     0,     0,     0,     0,
       0,  1010,     0,     0,     0,     0,     0,  1017,     0,     0,
    1020,     0,   121,   122,   123,   124,     0,     0,     0,     0,
       0,     0,     0,     0,   337,     0,     0,     0,     0,  1032,
    1033,  1034,  1035,   389,  1107,     0,     0,     0,   131,     0,
       0,     0,     0,   391,     0,     0,     0,     0,   137,     0,
     189,   546,     0,  1045,     0,     0,     0,     0,     0,    87,
     331,     0,     0,     0,     0,    91,    92,    93,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,     0,   309,     0,     0,  1077,  1078,  1079,
    1080,     0,   332,     0,     7,     8,     0,     0,   337,     0,
     337,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    36,    37,    38,    39,
       0,     0,  1115,     0,    43,     0,     0,    46,   500,    15,
      16,   501,    18,    19,   502,    21,   503,    23,  1133,    24,
       0,    26,    27,     0,    29,    30,    31,     0,     0,     0,
      34,     0,     0,     0,     0,   337,   121,   122,   123,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,     0,   129,   333,     0,
       0,     0,   131,     0,     0,     0,     0,   134,     0,     0,
       0,     0,   137,     0,     0,   546,     0,     0,     0,  1170,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,  1185,  1186,  1187,  1188,    87,    88,    89,     0,
      90,   611,    91,    92,    93,     0,     0,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,     0,   115,
     116,   117,   118,     0,     0,   119,     0,     0,  1220,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   505,     0,
       0,     0,    87,   331,   359,     0,     0,     0,    91,    92,
      93,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,  1253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   332,     0,   120,     0,     0,
       0,     0,     0,   121,   122,   123,   124,     0,     0,     0,
       0,   125,   126,   127,   128,     0,     0,     0,    35,    36,
      37,    38,    39,   521,   129,   130,     0,    43,     0,   131,
      46,   132,   133,     0,   134,     0,   135,     0,   136,   137,
       0,   138,     0,     0,     0,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   121,
     122,   123,   124,   324,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
     129,   350,   324,     0,     0,   131,     0,     0,     0,     0,
     134,     0,    87,   331,  1015,   137,     0,   351,    91,    92,
      93,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   332,     0,     7,     8,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,     0,     0,     0,     0,   324,    35,    36,
      37,    38,    39,   680,     0,     0,     0,    43,     0,     0,
      46,   500,    15,    16,   501,    18,    19,   502,    21,   503,
      23,     0,    24,     0,    26,    27,     0,    29,    30,    31,
       0,     0,     0,    34,     0,     0,     0,     0,     0,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,     0,
     129,   350,     0,     0,     0,   131,     0,     0,     0,     0,
     134,     0,    87,   331,     0,   137,     0,  1016,    91,    92,
      93,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   770,   332,     0,     7,     8,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,     0,     0,     0,     0,   324,    35,    36,
      37,    38,    39,   833,     0,     0,     0,    43,     0,     0,
      46,   500,    15,    16,   501,    18,    19,   502,    21,   503,
      23,     0,    24,     0,    26,    27,     0,    29,    30,    31,
       0,     0,     0,    34,     0,     0,     0,     0,     0,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,     0,
     129,   350,     0,     0,     0,   131,     0,     0,     0,     0,
     134,     0,    87,   331,     0,   137,     0,   351,    91,    92,
      93,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   790,   332,     0,     7,     8,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,     0,     0,     0,     0,   324,    35,    36,
      37,    38,    39,   867,     0,     0,     0,    43,     0,     0,
      46,   500,    15,    16,   501,    18,    19,   502,    21,   503,
      23,     0,    24,     0,    26,    27,     0,    29,    30,    31,
       0,     0,     0,    34,     0,     0,     0,     0,     0,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,     0,
     129,   333,     0,     0,     0,   131,     0,     0,     0,     0,
     134,     0,    87,   331,     0,   137,     0,   545,    91,    92,
      93,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1256,   332,     0,     7,     8,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,     0,     0,     0,     0,   324,    35,    36,
      37,    38,    39,   904,     0,     0,     0,    43,     0,     0,
      46,   500,    15,    16,   501,    18,    19,   502,    21,   503,
      23,     0,    24,     0,    26,    27,     0,    29,    30,    31,
       0,     0,     0,    34,     0,   952,     0,     0,     0,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,     0,
     129,   333,     0,     0,     0,   131,     0,     0,  1139,     0,
     134,     0,    87,   331,     0,   137,     0,   731,    91,    92,
      93,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1313,   332,     0,     0,     0,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,     0,     0,     0,     0,   324,    35,    36,
      37,    38,    39,  1158,     0,     0,     0,    43,     0,     0,
      46,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,     0,     0,     0,     0,   324,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
     122,   123,   124,     0,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
     129,   350,   324,     0,     0,   131,     0,     0,  1183,     0,
     134,     0,    87,   331,     0,   137,     0,  1019,    91,    92,
      93,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   332,     0,     0,     0,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,     0,     0,     0,     0,   324,    35,    36,
      37,    38,    39,  1262,     0,    87,   291,    43,     0,     0,
      46,    91,    92,    93,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,  1311,     0,   121,
     122,   123,   124,     0,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
     389,  1107,   324,     0,     0,   131,     0,     0,     0,     0,
     391,   530,    87,   291,   241,   137,     0,   189,    91,    92,
      93,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,   115,   116,   117,   118,     0,
       0,   119,   121,   122,   123,   124,     0,     0,     0,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   129,   130,     0,     0,   324,   131,     0,
       0,     0,     0,   134,     0,     0,   296,     0,   137,     0,
     297,     0,     0,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,     0,     0,   530,
       0,   324,     0,     0,     0,     0,     0,     0,     0,   121,
     122,   123,   124,     0,     0,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   531,   322,   323,     0,
     129,   130,     0,   324,     0,   131,     0,     0,     0,     0,
     134,   607,    87,   291,     0,   137,     0,  1121,    91,    92,
      93,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,     0,   702,
       0,    87,   291,     0,     0,     0,     0,    91,    92,    93,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   548,   322,   323,     0,     0,     0,
       0,   324,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
     122,   123,   124,   851,     0,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,     0,
     129,   130,     0,   324,     0,   131,     0,     0,     0,     0,
     134,     0,     0,   709,     0,   137,   916,   710,   121,   122,
     123,   124,     0,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,     0,     0,   389,
     390,   324,     0,     0,   131,     0,     0,     0,     0,   391,
       0,    87,   331,     0,   137,     0,   189,    91,    92,    93,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   332,     0,     0,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,     0,     0,     0,     0,   324,     0,    35,    36,    37,
      38,    39,     0,     0,     0,     0,    43,     0,     0,    46,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,   122,
     123,   124,     0,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,     0,     0,   129,
     333,   324,     0,     0,   131,    87,   291,   241,  1089,   134,
    1090,    91,    92,    93,   137,     0,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,     0,   115,   116,
     117,   118,     7,     8,   119,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,     0,
       0,     0,     0,   324,     0,     0,     0,     0,     0,     0,
    1116,     0,  1117,     0,     0,     0,   500,    15,    16,   501,
      18,    19,   502,    21,   503,    23,     0,    24,     0,    26,
      27,     0,    29,    30,    31,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,     0,    -4,     1,     0,     0,
      -4,     0,   121,   122,   123,   124,     0,     0,    -4,    -4,
       0,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,   130,     0,     0,     0,   131,     0,
       0,    -4,     0,   134,     0,     0,    -4,    -4,   137,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
      -4,    -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     6,     0,     0,     0,
      -4,    -4,    -4,    -4,     7,     8,     0,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,     0,     0,     0,     0,   324,     0,     9,     0,     0,
       0,     0,    10,    11,   734,    12,    13,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,    45,    46,     0,     0,    47,    48,     0,     0,
       0,     0,    49,    50,    51,    52,     0,     0,    53,     0,
      54,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,    65,    66,    67,    68,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,  1207,     0,  1208,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,     0,     0,   773,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,     0,     0,   805,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,     0,
       0,   850,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,     0,     0,     0,     0,     0,     0,     0,   889,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,  1087,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,     0,     0,  1104,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,     0,     0,  1145,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,     0,
       0,  1146,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,     0,     0,     0,     0,     0,     0,     0,  1147,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,  1148,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,     0,     0,  1178,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,     0,     0,  1222,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,     0,
       0,  1227,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,     0,     0,     0,     0,     0,     0,     0,  1228,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,  1244,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,     0,     0,  1247,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,     0,     0,  1250,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,     0,
       0,  1274,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,     0,     0,     0,     0,     0,     0,     0,  1277,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,  1305,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,     0,     0,  1307,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,     0,     0,  1309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,     0,
       0,  1322,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,   488,     0,     0,     0,     0,   571,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,   524,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,   571,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,   572,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,   604,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,     0,     0,     0,     0,     0,   655,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,   656,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,   669,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,   670,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,   671,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,     0,     0,     0,     0,     0,   672,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,   673,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,   674,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,   761,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,   762,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,     0,     0,     0,     0,     0,   763,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,   847,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,   887,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,   888,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,   915,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,     0,     0,     0,     0,     0,  1039,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,  1040,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,  1059,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,  1191,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,  1192,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,     0,     0,     0,     0,     0,  1198,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,  1270,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,  1273,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,   492,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,     0,     0,     0,
       0,   324,     0,     0,     0,   609,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,     0,     0,   619,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,     0,     0,     0,     0,   324,     0,     0,
       0,   634,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,     0,     0,   636,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,     0,
       0,     0,     0,   324,     0,     0,     0,   638,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,     0,     0,
     640,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,     0,     0,     0,     0,   324,
       0,     0,     0,   642,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,     0,     0,   644,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,     0,     0,     0,     0,   324,     0,     0,     0,   646,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,   648,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,     0,     0,     0,
       0,   324,     0,     0,     0,   650,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,     0,     0,   652,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,     0,     0,     0,     0,   324,     0,     0,
       0,   654,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,     0,     0,   658,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,     0,
       0,     0,     0,   324,     0,     0,     0,   660,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,     0,     0,
     662,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,     0,     0,     0,     0,   324,
       0,     0,     0,   664,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,     0,     0,   666,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,     0,     0,     0,     0,   324,     0,     0,     0,   668,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,   780,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,     0,     0,     0,
       0,   324,     0,     0,     0,   781,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,     0,     0,   783,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,     0,     0,     0,     0,   324,     0,     0,
       0,   784,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,     0,     0,   801,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,     0,
       0,     0,     0,   324,     0,     0,     0,   823,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,     0,     0,
     921,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,     0,     0,     0,     0,   324,
       0,     0,     0,   936,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,     0,     0,   938,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,     0,     0,     0,     0,   324,     0,     0,     0,   940,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
       0,     0,   942,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,     0,     0,     0,
       0,   324,     0,     0,     0,  1052,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,   488,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,     0,     0,     0,     0,   324,     0,   525,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,   534,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,     0,     0,     0,     0,   324,     0,   535,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
     537,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,     0,     0,     0,     0,   324,
       0,   539,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,   540,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,     0,     0,     0,
       0,   324,     0,   543,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,   544,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,     0,
       0,     0,     0,   324,     0,   600,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,   601,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,     0,     0,     0,     0,   324,     0,   602,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,   608,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,     0,     0,     0,     0,   324,     0,   633,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
     635,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,     0,     0,     0,     0,   324,
       0,   637,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,   639,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,     0,     0,     0,
       0,   324,     0,   641,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,   643,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,     0,
       0,     0,     0,   324,     0,   645,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,   647,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,     0,     0,     0,     0,   324,     0,   649,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,   651,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,     0,     0,     0,     0,   324,     0,   653,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
     657,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,     0,     0,     0,     0,   324,
       0,   659,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,   661,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,     0,     0,     0,
       0,   324,     0,   663,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,   665,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,     0,
       0,     0,     0,   324,     0,   667,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,   720,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,     0,     0,     0,     0,   324,     0,   725,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,   733,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,     0,     0,     0,     0,   324,     0,   735,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
     736,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,     0,     0,     0,     0,   324,
       0,   742,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,   749,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,     0,     0,     0,
       0,   324,     0,   750,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,   751,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,     0,
       0,     0,     0,   324,     0,   772,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,   774,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,     0,     0,     0,     0,   324,     0,   775,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,   779,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,     0,     0,     0,     0,   324,     0,   935,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,     0,     0,     0,     0,   324,     0,
     937,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,     0,     0,     0,     0,   324,
       0,   939,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,     0,     0,     0,     0,
     324,     0,   941,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,     0,     0,     0,
       0,   324,     0,   945,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,     0,     0,
       0,     0,   324,     0,  1088,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,     0,
       0,     0,     0,   324,     0,  1103,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
       0,     0,     0,     0,   324,     0,  1120,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,     0,     0,     0,     0,   324,     0,  1269,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,     0,     0,     0,     0,   324,     0,  1320
};

static const yytype_int16 yycheck[] =
{
       6,   197,   383,   384,     6,     6,     3,   299,   767,     0,
       6,   207,     7,     6,     4,    36,    37,  1134,    39,     4,
     232,   233,   234,     4,   695,     4,     4,     4,     4,   138,
     139,     5,   228,     6,   230,     5,     4,     6,     4,  1156,
       6,    76,    75,     4,    75,    75,   153,    82,    83,     6,
      76,   158,     4,     5,    76,   162,    82,    83,    13,    76,
      82,    83,     4,    76,     6,    82,    83,     7,     6,    82,
      83,    76,    75,   285,   286,   287,   288,    82,    83,   131,
     132,    52,   771,     7,    36,    37,    38,    39,    90,   142,
      42,   171,   172,     7,   147,   147,    86,    87,    88,    89,
     141,    69,    70,    71,    72,     6,     7,   148,   141,   141,
      78,    96,    97,    81,   149,   148,   148,   148,   148,     6,
      96,    97,   202,   129,   130,   131,   104,   149,   134,   135,
     131,   132,   149,   139,    49,   128,   149,    52,   141,   145,
     899,   138,   148,   141,   149,   148,   152,   153,   154,   155,
     145,   157,   158,   159,   160,  1272,   162,   163,   164,   149,
       6,   138,   139,   834,   185,   186,   143,   148,   145,   148,
     148,   128,   193,   150,   148,   148,   197,   143,   148,   148,
     141,   121,   188,   189,   131,   132,   138,   139,   131,   132,
     297,   197,   141,   145,   118,   119,   120,   121,   394,   148,
     492,   148,     6,    56,   118,   119,   120,   121,   214,   215,
     216,     7,   218,    76,   141,   221,   222,    52,   224,    82,
      83,   417,  1339,   141,   138,   139,    76,   138,   139,    76,
     236,   145,    82,    83,   145,    82,    83,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   141,
     141,    76,     4,   289,   955,   141,   149,    82,    83,    76,
     141,   297,   148,   142,    52,    82,    83,     7,   147,   149,
     141,   408,   149,   299,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   131,
     132,   142,   118,   119,   120,   121,   147,   333,    50,   141,
     131,   132,    76,    52,    52,   341,   148,    59,    82,    83,
     346,    76,   138,   139,   350,   351,   147,    82,    83,   355,
     356,   357,   358,   141,   149,   143,   131,   132,   364,    54,
     381,   382,   149,   369,   370,   371,   148,   141,   389,   143,
     142,    46,    76,   148,    49,   147,   141,    52,    82,    83,
     386,   387,   388,   389,   390,   391,   383,   384,     5,   395,
     396,   397,   398,    49,   148,   401,   142,    52,   404,   405,
      52,   147,   408,   409,   410,   149,    49,   619,   118,   119,
     120,   121,    49,   141,   149,   143,   523,   131,   132,    36,
      37,    38,    39,   131,   132,    42,     4,   433,   138,   139,
     436,    49,     4,   147,    52,   149,    54,     4,   545,   435,
     148,    66,   153,   131,   132,   149,     6,   158,   131,   132,
     141,   162,  1211,   143,   141,  1214,   131,   132,  1217,   147,
     141,   149,   131,   132,   147,   677,   141,   131,   132,  1140,
     131,   132,     4,   148,   141,  1164,   143,  1166,   147,  1168,
     149,   487,   141,   147,    46,     4,   147,    49,   494,     7,
      52,   493,    54,   705,   141,   141,   492,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    49,     4,     5,    52,   140,    54,   523,   524,   141,
     526,   527,   131,   132,   530,   531,   532,   141,   141,   143,
     143,   141,   148,  1292,   826,   827,   131,   132,   147,   545,
     141,   141,   548,   549,    36,    37,    38,    39,   554,   570,
      42,   141,   147,   559,   560,   561,   562,   559,   560,   561,
     562,   141,   583,   143,  1323,   571,   572,  1326,  1257,   676,
    1329,   577,   141,  1332,   131,   132,   141,   133,   134,   135,
     131,   132,     4,   589,   140,   591,   297,     6,   131,   132,
     147,   698,   699,   700,   701,  1354,   147,  1356,   604,  1358,
     606,   607,     6,   710,   147,     5,   612,   131,   132,   133,
     134,   135,   560,   561,   562,  1304,   140,  1306,   141,  1308,
     143,  1002,   333,   619,   731,  1314,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     6,   350,
     351,     8,   140,   131,   132,   131,   132,   141,   141,   655,
     656,   141,   141,  1342,   143,  1344,   141,  1346,   143,   147,
     141,   147,   143,   669,   670,   671,   672,   673,   674,   141,
     676,   143,   131,   132,   141,   681,   143,   141,   141,   143,
     143,   141,   688,   131,   132,   131,   132,   708,   147,   131,
     132,   148,   698,   699,   700,   701,   702,   408,   141,   147,
     143,   147,   141,   141,   710,   147,   131,   132,   131,   132,
     141,   141,   165,   143,   141,   141,   143,   170,   171,   172,
     141,   141,   147,   143,   147,   731,     4,   141,   181,   182,
     148,   184,   138,   139,   141,   148,   143,   143,   148,   145,
     761,   762,   763,   141,   150,   143,   147,   141,   149,   202,
     203,   963,   147,   141,   149,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   147,
     143,   149,   145,   140,   143,   147,   147,   149,   149,  1160,
       6,   147,   149,   149,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    52,   148,    54,   905,   140,
     143,   807,   808,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   523,   147,   143,   149,   140,     6,   138,   139,
     531,   532,   147,   143,   149,   145,   145,   823,   148,   835,
     150,   827,   148,   147,   545,   149,   147,   548,   149,    99,
       6,   847,     3,     4,   147,   851,   149,     6,     9,    10,
      11,     6,   143,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,   147,     4,   149,   898,   148,     6,
     886,   887,   888,   147,   147,   149,   149,     5,   894,   895,
     140,   147,   898,   149,   147,   147,   149,   149,   147,   905,
     149,   147,   147,   149,   149,   147,   147,   149,   149,   915,
     916,   917,   147,   147,   149,   149,   147,   147,   149,   149,
     147,   145,   149,   929,     8,   147,     7,   149,   934,   148,
     147,   927,   149,   147,   143,   149,   149,   148,     7,     7,
       7,   141,   948,   141,   141,   947,   141,     7,   969,   110,
     111,   112,   113,     7,   142,     8,     6,    96,     7,     7,
       6,   148,   968,   142,   142,   676,   142,   142,   974,   975,
     131,   132,   142,   979,   147,   136,  1172,   142,   147,     6,
     141,   987,  1003,     4,  1005,   146,  1007,   698,   699,   700,
     701,   144,   998,     7,    99,  1016,   998,  1018,  1019,   710,
       7,     7,     7,    99,     7,  1002,     7,    99,     7,     7,
    1016,     4,     6,  1019,  1121,   145,  1022,   149,   149,     6,
     731,     7,     7,     7,  1030,   145,     4,     7,  1030,   141,
       7,     7,     7,  1039,  1040,   141,   489,   490,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     6,  1059,   148,     6,   140,     6,   144,     6,
       6,   143,  1258,     7,     6,   149,   128,     7,  1175,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,  1089,    52,     7,     7,   140,    54,   142,
       7,     7,     7,     6,     4,     7,     7,   142,   142,  1105,
     142,  1107,   555,   142,     7,     7,     6,  1319,     6,     6,
    1116,   148,  1118,   566,   567,  1121,   141,     7,     6,   148,
       7,     7,     6,     6,  1130,    52,     6,     6,     4,  1135,
       4,     4,   148,   148,     6,   148,   148,  1349,     4,  1351,
     148,     6,  1163,   145,  1165,   141,  1167,   142,     7,     6,
      59,   148,  1259,  1174,  1261,  1176,  1368,  1163,     6,  1165,
     148,  1167,     6,  1160,     6,   148,   148,     6,     6,  1175,
       5,     7,     4,  1179,   148,     6,   148,     7,     7,    12,
      13,     7,     6,   148,     6,  1191,  1192,    95,     6,   145,
       7,     6,  1198,     4,   905,    99,     6,     6,  1204,     6,
       6,  1207,     6,   144,     6,     6,     6,     6,     5,  1316,
       6,     6,     6,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     6,    57,     4,    59,    60,  1234,    62,
      63,    64,     6,     6,     6,    68,     6,     4,     6,  1245,
    1261,   147,  1248,    12,    13,  1251,     6,     6,   147,  1255,
       6,   147,   147,  1259,   147,  1261,   148,     6,    91,    92,
      93,     7,     6,   145,  1270,   718,   719,  1273,   721,     6,
     723,   724,     5,    50,   727,   728,     6,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     6,    57,     6,
      59,    60,     6,    62,    63,    64,     6,   148,     6,    68,
       6,   148,     6,   149,     7,  1016,     6,   148,  1019,    94,
    1316,   148,     6,     6,   148,    97,   149,     6,     6,     6,
     148,     6,    91,    92,    93,     6,   149,   148,     6,   149,
     149,     6,   785,   786,   787,   149,   148,    66,     6,     6,
       6,   149,     6,   148,     6,     3,     4,     4,  1234,   846,
       6,     9,    10,    11,     6,     6,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     6,     6,     6,
     149,     6,     6,   149,   148,   148,   148,     6,    46,     6,
     148,     6,     6,     6,     6,     6,  1107,   148,     6,     6,
     148,   148,   855,   148,     6,   148,     6,     6,   861,     6,
    1121,    69,    70,    71,    72,    73,   869,   870,   871,     6,
      78,     6,   875,    81,     6,     6,     6,   880,   881,   882,
     854,     3,     3,  1241,   363,   951,    -1,    -1,    -1,    -1,
      -1,   894,    -1,    -1,    -1,    -1,    -1,   900,    -1,    -1,
     903,    -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1175,    -1,    -1,    -1,    -1,   922,
     923,   924,   925,   131,   132,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,   146,    -1,
     148,   149,    -1,   946,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,     6,    -1,    -1,   990,   991,   992,
     993,    -1,    46,    -1,    12,    13,    -1,    -1,  1259,    -1,
    1261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      -1,    -1,  1025,    -1,    78,    -1,    -1,    81,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,  1041,    57,
      -1,    59,    60,    -1,    62,    63,    64,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,  1316,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    -1,   131,   132,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,   141,    -1,    -1,
      -1,    -1,   146,    -1,    -1,   149,    -1,    -1,    -1,  1102,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,  1125,  1126,  1127,  1128,     3,     4,     5,    -1,
       7,   149,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,  1171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,  1218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,   104,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,    -1,    -1,    69,    70,
      71,    72,    73,     6,   131,   132,    -1,    78,    -1,   136,
      81,   138,   139,    -1,   141,    -1,   143,    -1,   145,   146,
      -1,   148,    -1,    -1,    -1,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   110,
     111,   112,   113,   140,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
     131,   132,   140,    -1,    -1,   136,    -1,    -1,    -1,    -1,
     141,    -1,     3,     4,     5,   146,    -1,   148,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    12,    13,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    69,    70,
      71,    72,    73,     6,    -1,    -1,    -1,    78,    -1,    -1,
      81,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    -1,    59,    60,    -1,    62,    63,    64,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    -1,
     131,   132,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,
     141,    -1,     3,     4,    -1,   146,    -1,   148,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    46,    -1,    12,    13,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    69,    70,
      71,    72,    73,     6,    -1,    -1,    -1,    78,    -1,    -1,
      81,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    -1,    59,    60,    -1,    62,    63,    64,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    -1,
     131,   132,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,
     141,    -1,     3,     4,    -1,   146,    -1,   148,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    46,    -1,    12,    13,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    69,    70,
      71,    72,    73,     6,    -1,    -1,    -1,    78,    -1,    -1,
      81,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    -1,    59,    60,    -1,    62,    63,    64,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    -1,
     131,   132,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,
     141,    -1,     3,     4,    -1,   146,    -1,   148,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    46,    -1,    12,    13,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    69,    70,
      71,    72,    73,     6,    -1,    -1,    -1,    78,    -1,    -1,
      81,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    -1,    59,    60,    -1,    62,    63,    64,
      -1,    -1,    -1,    68,    -1,     6,    -1,    -1,    -1,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    -1,
     131,   132,    -1,    -1,    -1,   136,    -1,    -1,     6,    -1,
     141,    -1,     3,     4,    -1,   146,    -1,   148,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    46,    -1,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    69,    70,
      71,    72,    73,     6,    -1,    -1,    -1,    78,    -1,    -1,
      81,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
     131,   132,   140,    -1,    -1,   136,    -1,    -1,     6,    -1,
     141,    -1,     3,     4,    -1,   146,    -1,   148,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    69,    70,
      71,    72,    73,     6,    -1,     3,     4,    78,    -1,    -1,
      81,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     6,    -1,   110,
     111,   112,   113,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
     131,   132,   140,    -1,    -1,   136,    -1,    -1,    -1,    -1,
     141,     8,     3,     4,     5,   146,    -1,   148,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,    -1,
      -1,    42,   110,   111,   112,   113,    -1,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   131,   132,    -1,    -1,   140,   136,    -1,
      -1,    -1,    -1,   141,    -1,    -1,   144,    -1,   146,    -1,
     148,    -1,    -1,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,     8,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,    -1,    -1,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
     131,   132,    -1,   140,    -1,   136,    -1,    -1,    -1,    -1,
     141,     8,     3,     4,    -1,   146,    -1,   148,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,     8,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,     8,    -1,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
     131,   132,    -1,   140,    -1,   136,    -1,    -1,    -1,    -1,
     141,    -1,    -1,   144,    -1,   146,     8,   148,   110,   111,
     112,   113,    -1,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,   131,
     132,   140,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
      -1,     3,     4,    -1,   146,    -1,   148,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    69,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    78,    -1,    -1,    81,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,    -1,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,   131,
     132,   140,    -1,    -1,   136,     3,     4,     5,   147,   141,
     149,     9,    10,    11,   146,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    12,    13,    42,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,    -1,   149,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    -1,    59,
      60,    -1,    62,    63,    64,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,
       4,    -1,   110,   111,   112,   113,    -1,    -1,    12,    13,
      -1,    91,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,    -1,    -1,    -1,   136,    -1,
      -1,    35,    -1,   141,    -1,    -1,    40,    41,   146,    43,
      44,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    85,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      -1,    -1,    96,    -1,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     4,    -1,    -1,    -1,
     114,   115,   116,   117,    12,    13,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    35,    -1,    -1,
      -1,    -1,    40,    41,   149,    43,    44,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    -1,    -1,    84,    85,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    -1,    -1,    96,    -1,
      98,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,   114,   115,   116,   117,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,    -1,   149,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,   142,    -1,    -1,    -1,    -1,   147,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,   144,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,   144,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,   144,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,   144,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,   144,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
     144,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,   144,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,   144,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,   144,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,   144,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,   144,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,   144,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,   144,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,   144,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
     144,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,   144,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,   144,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,   144,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,   144,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,   144,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,   144,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,   144,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,   144,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
     144,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,   144,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,   144,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,   144,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,   144,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,   142,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,   142,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,   142,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,   142,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
     142,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,   142,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,   142,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,   142,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,   142,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,   142,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,   142,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,   142,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,   142,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,   142,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
     142,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,   142,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,   142,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,   142,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,   142,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,   142,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,   142,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,   142,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,   142,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,   142,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
     142,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,   142,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,   142,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,   142,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,   142,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,   142,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,   142,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,   142,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,   142,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,   142,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
     142,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,   142,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,   142,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,   142,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,   142,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,   142,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,   142,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,   142,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,   142,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,   142,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,
     142,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,   142,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,   142,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,   142,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,   142,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,   142,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,   142,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,   142,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,   142
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   152,   153,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    67,    68,    69,    70,    71,    72,    73,
      74,    76,    77,    78,    79,    80,    81,    84,    85,    90,
      91,    92,    93,    96,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   114,   115,   116,   117,   154,
     156,   157,   175,   179,   184,   187,   188,   189,   190,   191,
     192,   193,   214,   215,   216,   217,   218,     3,     4,     5,
       7,     9,    10,    11,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    36,    37,    38,    39,    42,
     104,   110,   111,   112,   113,   118,   119,   120,   121,   131,
     132,   136,   138,   139,   141,   143,   145,   146,   148,   173,
     174,   219,   220,   232,    13,    52,   141,     6,   148,     6,
       6,     6,   141,   148,   141,   141,    75,   141,   148,   141,
     141,    75,   148,   141,   141,    56,    52,    52,    52,    52,
      49,    52,    54,    54,    46,    49,    52,    54,    49,    52,
      54,    49,    52,   141,    49,   148,   131,   132,   141,   148,
     221,   222,   221,   148,    46,    49,    52,   148,   221,     4,
      50,    59,    52,    52,    49,     4,   104,   148,     4,     6,
      49,     4,     4,     4,   141,   141,   141,     4,   148,   228,
       4,   141,   141,     6,   143,     4,     4,     5,   148,     5,
     148,   141,   141,   141,   141,     4,   143,   145,   150,   174,
     148,     5,   232,   141,   143,   141,   143,   141,   143,   141,
     143,   141,   143,   141,   143,   141,   143,   141,   143,   141,
     143,   141,   143,   141,   143,   141,   143,   141,   143,   141,
     143,   141,   143,   141,   143,   141,   143,   141,   143,   141,
     143,   141,   143,   141,   143,   141,   141,   141,   141,     7,
     141,     4,   219,   219,   219,   219,   144,   148,   219,     4,
      96,    97,     4,     4,   184,   185,   186,   219,     6,     6,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   140,     6,     6,   219,     5,   219,
     219,     4,    46,   132,   184,   193,   219,   226,   227,   219,
     219,   141,   219,   227,   219,   219,   141,   227,   219,   219,
     132,   148,   219,   224,   226,   141,   148,   141,   141,     5,
     224,   225,   225,   225,   141,   180,   181,   182,   183,   141,
     141,   141,   224,   224,     4,   224,   221,   221,   221,   219,
     219,   131,   132,   148,   148,   221,   148,   148,   148,   131,
     132,   141,   186,   221,   148,   141,   148,   141,   141,   225,
     224,   141,     4,     6,   143,   143,   186,     6,   148,   143,
     143,     6,   219,   219,   219,   145,   219,   148,    99,   219,
     219,   219,     6,     6,   186,     6,   186,     4,   231,   232,
     231,   231,   231,   143,   219,     4,   148,   158,     6,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   231,   231,   231,   231,   219,     5,   143,   142,     7,
     121,   227,   144,     7,   173,   174,   145,     7,   143,   149,
      46,    49,    52,    54,   179,     6,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,     6,   142,   147,   147,   142,   143,   148,   219,   226,
       8,   133,   147,   149,   142,   142,   219,   142,   149,   142,
     142,   219,   149,   142,   142,   148,   149,   227,   133,     7,
     219,   219,   219,   219,     7,     7,   212,   212,   219,   141,
     141,   141,   141,   219,   219,   219,     7,     7,   142,     6,
     147,   147,   147,   221,   221,   185,   185,   147,   219,   219,
     219,   219,   197,   147,   186,   219,   219,   219,   219,     7,
     213,     7,   219,     6,   219,   219,   149,   227,   219,   219,
     142,   142,   142,    96,   147,   186,   148,     8,   142,   144,
     149,   149,   143,   145,   142,   142,   142,   142,   219,   144,
     174,   219,     4,    86,    87,    88,    89,   149,   161,   165,
     168,   170,   171,   142,   144,   142,   144,   142,   144,   142,
     144,   142,   144,   142,   144,   142,   144,   142,   144,   142,
     144,   142,   144,   142,   144,   147,   147,   142,   144,   142,
     144,   142,   144,   142,   144,   142,   144,   142,   144,   147,
     147,   147,   147,   147,   147,   142,   147,   147,   142,   142,
       6,   147,   219,   224,   224,   149,     7,   145,   173,   174,
     232,   219,     6,     4,     4,   148,   229,   144,   148,   148,
     148,   148,     8,     6,   128,   155,   227,   219,     7,   144,
     148,   219,   219,   219,   226,   219,   226,    99,     7,     7,
     142,     7,    99,     7,     7,   142,    99,     7,     7,   227,
     149,   148,   219,   142,   149,   142,   142,   219,   224,     4,
     211,     6,   142,   176,   219,   232,   176,   176,   176,   142,
     142,   142,   224,   224,   145,   221,   219,   219,   149,   149,
     219,   147,   147,   147,    76,    82,    83,   207,   208,   221,
     149,   194,   142,   149,   142,   142,   219,     6,   219,   142,
     144,   144,   149,   144,   144,     7,     7,     7,   145,   219,
     149,   219,   219,     7,   145,   219,     4,     7,     7,     7,
       7,   144,   145,   174,   231,   149,   162,   141,   141,   148,
     172,     6,   219,   219,   219,   219,   219,   219,   219,   219,
     227,   231,   219,   144,     6,     6,   144,     4,    96,    97,
     219,     6,     6,     6,     7,   143,   228,   230,     6,   227,
     227,   227,   227,   219,   128,   231,   142,   147,   221,   227,
     149,     8,    52,   224,   224,     7,   224,    52,    54,   224,
     224,     7,    54,   224,   224,   149,   227,     6,     7,     7,
       7,     7,    66,   210,     6,     7,   142,   142,   142,   142,
       7,     7,     7,     6,     6,     4,   147,   147,   147,   149,
     221,   221,   221,     6,   148,   141,   149,   208,   147,   207,
       7,     6,     7,     7,     6,   148,     6,     6,    52,     6,
       6,   224,   224,   224,     4,   147,     8,     8,   142,     4,
       4,   144,   148,   148,   148,   148,     6,     4,     6,   141,
     219,   219,   223,   224,   148,   142,   144,   142,   144,   142,
     144,   142,   144,   142,   142,   142,   173,     7,   173,   174,
     145,     7,     6,   228,   219,   147,   149,   149,   149,   149,
     149,     6,     6,   155,   219,     6,   149,   219,   148,    59,
     178,   178,   224,     6,   148,   148,     6,     6,   224,   148,
       6,     6,   149,     5,   224,   224,   224,     4,     6,   224,
       7,     7,     7,     7,   224,   224,   224,     6,     7,   219,
     219,   219,   148,   147,   149,   147,   149,   147,   149,   219,
     224,   219,   219,   221,   149,     5,   148,   224,   148,   148,
     224,   227,   148,     6,     6,    95,   219,   219,   219,     6,
       7,   145,   224,   224,   224,   224,   174,   159,   219,   147,
     147,   147,   149,   160,   219,   224,   232,   219,     6,     4,
     229,     6,   144,   228,     6,     6,     6,     6,   231,   147,
     144,   219,   221,     6,     6,     6,   219,   219,     6,   219,
       5,     6,     6,    99,   177,   219,     6,   224,   224,   224,
     224,     6,     4,   209,     6,   219,   232,   149,   142,   147,
     149,   185,   221,     6,   198,   221,     6,   199,   221,     6,
     200,   149,   147,   142,   149,   147,     6,   132,   221,     6,
     221,   221,     6,   149,   219,   224,   147,   149,     8,   149,
     142,   148,   219,   232,     4,   147,   147,   147,   147,   142,
     147,   219,   219,   224,   148,   147,   149,     6,     6,     6,
       7,     6,   145,     6,   219,   149,   149,   149,   149,     5,
      50,     6,     6,     6,     6,     6,   148,     6,     6,     6,
     148,   219,   149,   147,   148,   147,   148,   147,   148,     6,
     224,     7,   148,   219,   147,   147,   147,     6,   149,    94,
     219,   219,   227,     6,     6,   224,   224,   224,   224,   163,
     219,   147,   147,   223,   219,     6,   228,    97,   147,     6,
       6,     6,     6,     6,   148,   223,   185,   147,   149,   219,
     221,   207,   219,   221,   207,   219,   221,   207,   147,   149,
     224,   186,   149,   221,   227,   221,   219,   149,   149,   149,
     149,   149,   149,   149,   148,   219,   219,   149,     6,   219,
     219,   149,   149,   219,   149,   147,   149,   149,   147,   149,
     149,   147,   149,   224,     6,    66,   149,   195,   148,   147,
     149,   147,     6,     6,     6,     6,     6,     6,   160,   142,
     147,     6,   148,   147,   149,     4,   209,   149,     6,   201,
     219,     6,     6,   202,   219,     6,     6,   203,   219,     6,
     149,   219,   207,   186,   227,     6,   221,   227,   149,   166,
     219,   223,   219,     6,   148,   149,   148,   149,   148,   149,
       6,     6,   149,   149,   196,   149,   147,   149,     6,   148,
     142,   149,   149,   207,     6,   204,   207,     6,   205,   207,
       6,   206,   207,     6,   227,     6,   164,   231,   169,   148,
       6,   149,   148,   149,   148,   149,   148,   149,   149,   147,
     149,   148,   223,     6,   207,     6,   207,     6,   207,     6,
     231,     6,   167,   231,   149,   149,   149,   149,   147,   149,
       6,     6,     6,     6,   231,     6
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
#line 157 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 168 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 169 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 170 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 171 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 172 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 173 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 174 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 175 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 176 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 177 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 178 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 179 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 180 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 181 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 182 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 183 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 184 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 189 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 24:
#line 193 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 25:
#line 200 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 26:
#line 205 "Gmsh.y"
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

  case 27:
#line 219 "Gmsh.y"
    {
      char tmpstring[1024];
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
#line 232 "Gmsh.y"
    {
      char tmpstring[1024];
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
#line 260 "Gmsh.y"
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
#line 274 "Gmsh.y"
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
#line 285 "Gmsh.y"
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
#line 299 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList(); 
#endif
    ;}
    break;

  case 38:
#line 313 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 39:
#line 315 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 40:
#line 320 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:
#line 322 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:
#line 327 "Gmsh.y"
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
#line 431 "Gmsh.y"
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
#line 441 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 45:
#line 450 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 46:
#line 457 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 47:
#line 467 "Gmsh.y"
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
#line 476 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 49:
#line 485 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 50:
#line 492 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 51:
#line 502 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size()); 
#endif
    ;}
    break;

  case 52:
#line 510 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 53:
#line 520 "Gmsh.y"
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
#line 539 "Gmsh.y"
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
#line 558 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 56:
#line 564 "Gmsh.y"
    {
    ;}
    break;

  case 57:
#line 571 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 58:
#line 572 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 59:
#line 573 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 60:
#line 574 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 61:
#line 575 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 62:
#line 579 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 63:
#line 580 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 64:
#line 588 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	if(!(yyvsp[(2) - (4)].i))
	  gmsh_yysymbols[(yyvsp[(1) - (4)].c)].push_back((yyvsp[(3) - (4)].d));
	else
	  yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
      }
      else{
        if(gmsh_yysymbols[(yyvsp[(1) - (4)].c)].empty()){
          if((yyvsp[(2) - (4)].i)) yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (4)].c));
          gmsh_yysymbols[(yyvsp[(1) - (4)].c)].resize(1, 0.);
        }
	switch((yyvsp[(2) - (4)].i)){
	case 0 : gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] = (yyvsp[(3) - (4)].d); break;
	case 1 : gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] += (yyvsp[(3) - (4)].d); break;
	case 2 : gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] -= (yyvsp[(3) - (4)].d); break;
	case 3 : gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] *= (yyvsp[(3) - (4)].d); break;
	case 4 : 
	  if((yyvsp[(3) - (4)].d)) gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] /= (yyvsp[(3) - (4)].d); 
	  else yymsg(0, "Division by zero in '%s /= %g'", (yyvsp[(1) - (4)].c), (yyvsp[(3) - (4)].d));
	  break;
	}
      }
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 65:
#line 614 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (7)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (7)].c))){
	if(!(yyvsp[(5) - (7)].i)){
	  gmsh_yysymbols[(yyvsp[(1) - (7)].c)].resize(index + 1, 0.);
	  gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] = (yyvsp[(6) - (7)].d);
	}
	else
	  yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (7)].c));
      }
      else{
	if((int)gmsh_yysymbols[(yyvsp[(1) - (7)].c)].size() < index + 1)
	  gmsh_yysymbols[(yyvsp[(1) - (7)].c)].resize(index + 1, 0.);
	switch((yyvsp[(5) - (7)].i)){
	case 0 : gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] = (yyvsp[(6) - (7)].d); break;
	case 1 : gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] += (yyvsp[(6) - (7)].d); break;
	case 2 : gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] -= (yyvsp[(6) - (7)].d); break;
	case 3 : gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] *= (yyvsp[(6) - (7)].d); break;
	case 4 : 
	  if((yyvsp[(6) - (7)].d)) gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] /= (yyvsp[(6) - (7)].d); 
	  else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (7)].c), index, (yyvsp[(6) - (7)].d));
	  break;
	}
      }
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 66:
#line 641 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (9)].l)) != List_Nbr((yyvsp[(8) - (9)].l))){
	yymsg(0, "Incompatible array dimensions in affectation");
      }
      else{
	if(!gmsh_yysymbols.count((yyvsp[(1) - (9)].c))){
	  if(!(yyvsp[(7) - (9)].i)){
	    for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
	      int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
	      gmsh_yysymbols[(yyvsp[(1) - (9)].c)].resize(index + 1, 0.);
	      gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
	    }
	  }
	  else
	    yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (9)].c));
	}
	else{
	  for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
	    int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
	    double d = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
	    if((int)gmsh_yysymbols[(yyvsp[(1) - (9)].c)].size() < index + 1)
	      gmsh_yysymbols[(yyvsp[(1) - (9)].c)].resize(index + 1, 0.);
	    switch((yyvsp[(7) - (9)].i)){
	    case 0 : gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] = d; break;
	    case 1 : gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] += d; break;
	    case 2 : gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] -= d; break;
	    case 3 : gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] *= d; break;
	    case 4 : 
	      if((yyvsp[(8) - (9)].l)) gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] /= d; 
	      else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (9)].c), index, d);
	      break;
	    }
	  }
	}
      }
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 67:
#line 681 "Gmsh.y"
    {
      if(gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].clear();
      gmsh_yysymbols[(yyvsp[(1) - (6)].c)] = std::vector<double>();
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
        gmsh_yysymbols[(yyvsp[(1) - (6)].c)].push_back(*(double*)List_Pointer((yyvsp[(5) - (6)].l), i));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 68:
#line 691 "Gmsh.y"
    {
      // appends to the list
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].push_back(*(double*)List_Pointer((yyvsp[(5) - (6)].l), i));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 69:
#line 699 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c)); 
      else{
        if(gmsh_yysymbols[(yyvsp[(1) - (3)].c)].empty())
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (3)].c));
        else
          gmsh_yysymbols[(yyvsp[(1) - (3)].c)][0] += (yyvsp[(2) - (3)].i);
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 70:
#line 711 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c)); 
      else{
	int index = (int)(yyvsp[(3) - (6)].d);
	if((int)gmsh_yysymbols[(yyvsp[(1) - (6)].c)].size() < index + 1)
	  gmsh_yysymbols[(yyvsp[(1) - (6)].c)].resize(index + 1, 0.);
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)][index] += (yyvsp[(5) - (6)].i);
      }
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 71:
#line 723 "Gmsh.y"
    { 
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 72:
#line 732 "Gmsh.y"
    { 
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c))
    ;}
    break;

  case 73:
#line 738 "Gmsh.y"
    { 
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c))
    ;}
    break;

  case 74:
#line 747 "Gmsh.y"
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

  case 75:
#line 765 "Gmsh.y"
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

  case 76:
#line 783 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 77:
#line 792 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 78:
#line 804 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 79:
#line 809 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 80:
#line 817 "Gmsh.y"
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

  case 81:
#line 837 "Gmsh.y"
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

  case 82:
#line 860 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->background_field = (int)(yyvsp[(4) - (5)].d);
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
#endif
    ;}
    break;

  case 83:
#line 869 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 84:
#line 877 "Gmsh.y"
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

  case 85:
#line 899 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option){
	  try { option->string() = (yyvsp[(8) - (9)].c); }
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

  case 86:
#line 922 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (11)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (11)].c)];
	if(option){
	  std::list<int> &vl = option->list();
	  vl.clear();
	  for(int i = 0; i < List_Nbr((yyvsp[(9) - (11)].l)); i++){
	    double id;
	    List_Read((yyvsp[(9) - (11)].l), i, &id);
	    vl.push_back((int)id);
	  }
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

  case 87:
#line 950 "Gmsh.y"
    {
#if defined(HAVE_POST)
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

  case 88:
#line 962 "Gmsh.y"
    {
#if defined(HAVE_POST)
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

  case 89:
#line 979 "Gmsh.y"
    { 
      (yyval.i) = (int)(yyvsp[(1) - (1)].d); 
    ;}
    break;

  case 90:
#line 983 "Gmsh.y"
    { 
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim, 
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 91:
#line 993 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 92:
#line 997 "Gmsh.y"
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

  case 93:
#line 1009 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 94:
#line 1013 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 95:
#line 1023 "Gmsh.y"
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

  case 96:
#line 1046 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 97:
#line 1050 "Gmsh.y"
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

  case 98:
#line 1066 "Gmsh.y"
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

  case 99:
#line 1088 "Gmsh.y"
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

  case 100:
#line 1106 "Gmsh.y"
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

  case 101:
#line 1128 "Gmsh.y"
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

  case 102:
#line 1146 "Gmsh.y"
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

  case 103:
#line 1176 "Gmsh.y"
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

  case 104:
#line 1206 "Gmsh.y"
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

  case 105:
#line 1224 "Gmsh.y"
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

  case 106:
#line 1242 "Gmsh.y"
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

  case 107:
#line 1268 "Gmsh.y"
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
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 108:
#line 1285 "Gmsh.y"
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

  case 109:
#line 1303 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 110:
#line 1307 "Gmsh.y"
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

  case 111:
#line 1326 "Gmsh.y"
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

  case 112:
#line 1344 "Gmsh.y"
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

  case 113:
#line 1383 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 114:
#line 1389 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 115:
#line 1395 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 116:
#line 1402 "Gmsh.y"
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

  case 117:
#line 1427 "Gmsh.y"
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

  case 118:
#line 1452 "Gmsh.y"
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
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 119:
#line 1468 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (9)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_COMPOUND);
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
          s->compound.push_back((int)*(double*)List_Pointer((yyvsp[(7) - (9)].l), i));
	  s->TypeOfMapping = (yyvsp[(8) - (9)].i);
	}
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 120:
#line 1487 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (13)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
        Surface *s = Create_Surface(num, MSH_SURF_COMPOUND);
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (13)].l)); i++)
          s->compound.push_back((int)*(double*)List_Pointer((yyvsp[(7) - (13)].l), i));
	for (int i = 0; i < List_Nbr((yyvsp[(10) - (13)].l)); i++){
          if(i > 3){
            yymsg(0, "Too many boundary specifiers in compound surface");
            break;
          }
	  List_T *l = *(List_T**)List_Pointer((yyvsp[(10) - (13)].l), i);
          for (int j = 0; j < List_Nbr(l); j++){
            s->compoundBoundary[i].push_back((int)*(double*)List_Pointer(l, j));
	    s->TypeOfMapping = (yyvsp[(12) - (13)].i);
	  }
	}
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (13)].l));
      for (int i = 0; i < List_Nbr((yyvsp[(10) - (13)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(10) - (13)].l), i));
      List_Delete((yyvsp[(10) - (13)].l));
      Free((yyvsp[(8) - (13)].c));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 121:
#line 1518 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 122:
#line 1522 "Gmsh.y"
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

  case 123:
#line 1542 "Gmsh.y"
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

  case 124:
#line 1560 "Gmsh.y"
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

  case 125:
#line 1577 "Gmsh.y"
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

  case 126:
#line 1593 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 127:
#line 1597 "Gmsh.y"
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

  case 128:
#line 1619 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 129:
#line 1624 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 130:
#line 1629 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 131:
#line 1634 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 132:
#line 1639 "Gmsh.y"
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
        BoundaryShapes((yyvsp[(3) - (4)].l), (yyval.l));
      }
      else{
        yymsg(0, "Unknown command on multiple shapes: '%s'", (yyvsp[(1) - (4)].c));
      }
      Free((yyvsp[(1) - (4)].c));
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 133:
#line 1659 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 134:
#line 1665 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 135:
#line 1675 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 136:
#line 1676 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 137:
#line 1681 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 138:
#line 1685 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 139:
#line 1689 "Gmsh.y"
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

  case 140:
#line 1712 "Gmsh.y"
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

  case 141:
#line 1735 "Gmsh.y"
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

  case 142:
#line 1758 "Gmsh.y"
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

  case 143:
#line 1786 "Gmsh.y"
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

  case 144:
#line 1808 "Gmsh.y"
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

  case 145:
#line 1829 "Gmsh.y"
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

  case 146:
#line 1850 "Gmsh.y"
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

  case 147:
#line 1870 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (8)].c), "Union")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<const gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Union %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetUnion(vl);
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
          std::vector<const gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Intersection %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetIntersection(vl);
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
          std::vector<const gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Cut %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetCut(vl);
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
          std::vector<const gLevelset *> vl;
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

  case 148:
#line 1982 "Gmsh.y"
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

  case 149:
#line 2001 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (6)].c), "CutMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        GM->buildCutGModel(FindLevelSet(t)->ls);
        GM->setVisibility(0);
      }
      else if(!strcmp((yyvsp[(2) - (6)].c), "SplitMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        GM->buildCutGModel(FindLevelSet(t)->ls, false);
        GM->setVisibility(0);
      }
      else
        yymsg(0, "Wrong levelset definition");
      Free((yyvsp[(2) - (6)].c));
#endif
    ;}
    break;

  case 150:
#line 2022 "Gmsh.y"
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

  case 151:
#line 2130 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 152:
#line 2139 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 153:
#line 2145 "Gmsh.y"
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

  case 154:
#line 2160 "Gmsh.y"
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

  case 155:
#line 2188 "Gmsh.y"
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

  case 156:
#line 2205 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));      
    ;}
    break;

  case 157:
#line 2219 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 158:
#line 2225 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 159:
#line 2231 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 160:
#line 2240 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 161:
#line 2254 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Include")){
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	// Warning: we *don't* close included files (to allow user
	// functions in these files). If you need to include many many
	// files and don't have functions in the files, use "Merge"
	// instead: some OSes limit the number of files a process can
	// open simultaneously. The right solution would be of course
	// to modify FunctionManager to reopen the files instead of
	// using the FILE pointer, but hey, I'm lazy...
	Msg::StatusBar(2, true, "Reading '%s'", tmp.c_str());
	ParseFile(tmp, false, true);
	SetBoundingBox();
	Msg::StatusBar(2, true, "Done reading '%s'", tmp.c_str());
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Print")){
	// make sure we have the latest data from GEO_Internals in GModel
	// (fixes bug where we would have no geometry in the picture if
	// the print command is in the same file as the geometry)
	GModel::current()->importGEOInternals();
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->print.format);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Save")){
	GModel::current()->importGEOInternals();
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->mesh.format);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Merge") || !strcmp((yyvsp[(1) - (3)].c), "MergeWithBoundingBox")){
	// MergeWithBoundingBox is deprecated
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	MergeFile(tmp, true);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "System"))
	SystemCall((yyvsp[(2) - (3)].c));
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetName"))
	GModel::current()->setName((yyvsp[(2) - (3)].c));
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 162:
#line 2296 "Gmsh.y"
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

  case 163:
#line 2313 "Gmsh.y"
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

  case 164:
#line 2328 "Gmsh.y"
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

  case 165:
#line 2347 "Gmsh.y"
    {
#if defined(HAVE_POST)
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

  case 166:
#line 2359 "Gmsh.y"
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

  case 167:
#line 2383 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 168:
#line 2387 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the 
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 169:
#line 2394 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 170:
#line 2400 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 171:
#line 2405 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 172:
#line 2411 "Gmsh.y"
    {
       GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 173:
#line 2421 "Gmsh.y"
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

  case 174:
#line 2438 "Gmsh.y"
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

  case 175:
#line 2455 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (8)].c);
      gmsh_yysymbols[(yyvsp[(2) - (8)].c)].resize(1);
      gmsh_yysymbols[(yyvsp[(2) - (8)].c)][0] = (yyvsp[(5) - (8)].d);
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

  case 176:
#line 2474 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(9) - (10)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (10)].c);
      gmsh_yysymbols[(yyvsp[(2) - (10)].c)].resize(1);
      gmsh_yysymbols[(yyvsp[(2) - (10)].c)][0] = (yyvsp[(5) - (10)].d);
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

  case 177:
#line 2493 "Gmsh.y"
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
            yymsg(0, "Unknown loop variable");
          else{
            gmsh_yysymbols[name][0] += step;
            LoopControlVariablesTab[ImbricatedLoop - 1][0] = gmsh_yysymbols[name][0];
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

  case 178:
#line 2523 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 179:
#line 2531 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 180:
#line 2537 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 181:
#line 2544 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 182:
#line 2548 "Gmsh.y"
    {
    ;}
    break;

  case 183:
#line 2557 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 184:
#line 2565 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 185:
#line 2573 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 186:
#line 2581 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 187:
#line 2585 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 188:
#line 2593 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 189:
#line 2597 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 190:
#line 2605 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 191:
#line 2609 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 192:
#line 2617 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 193:
#line 2621 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 194:
#line 2630 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 195:
#line 2637 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 196:
#line 2644 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 197:
#line 2651 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 198:
#line 2658 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 199:
#line 2665 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 200:
#line 2672 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 201:
#line 2679 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 202:
#line 2686 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 203:
#line 2693 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 204:
#line 2697 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 205:
#line 2704 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 206:
#line 2708 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 207:
#line 2715 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 208:
#line 2719 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 209:
#line 2726 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 210:
#line 2730 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 211:
#line 2737 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 212:
#line 2741 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 213:
#line 2748 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 214:
#line 2752 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 215:
#line 2759 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 216:
#line 2763 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 217:
#line 2770 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 218:
#line 2774 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 219:
#line 2781 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 220:
#line 2785 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 221:
#line 2796 "Gmsh.y"
    {
    ;}
    break;

  case 222:
#line 2799 "Gmsh.y"
    {
    ;}
    break;

  case 223:
#line 2805 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 224:
#line 2814 "Gmsh.y"
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

  case 225:
#line 2834 "Gmsh.y"
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

  case 226:
#line 2857 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 227:
#line 2861 "Gmsh.y"
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

  case 228:
#line 2884 "Gmsh.y"
    {
      (yyval.i) = 1; // harmonic
    ;}
    break;

  case 229:
#line 2888 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "Harmonic"))
        (yyval.i) = 1;
      else if(!strcmp((yyvsp[(1) - (1)].c), "Conformal"))
        (yyval.i) = -1;
      else if(!strcmp((yyvsp[(1) - (1)].c), "Harmonic_NoSplit"))
        (yyval.i) = 2;
      else if(!strcmp((yyvsp[(1) - (1)].c), "Conformal_NoSplit"))
        (yyval.i) = -2;
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 230:
#line 2903 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 231:
#line 2907 "Gmsh.y"
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

  case 232:
#line 2922 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 233:
#line 2926 "Gmsh.y"
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

  case 234:
#line 2938 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 235:
#line 2942 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 236:
#line 2947 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 237:
#line 2951 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 238:
#line 2958 "Gmsh.y"
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
            (*it)->meshAttributes.Method = MESH_TRANSFINITE;
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
                ge->meshAttributes.Method = MESH_TRANSFINITE;
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

  case 239:
#line 3014 "Gmsh.y"
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
              (*it)->meshAttributes.Method = MESH_TRANSFINITE;
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
                gf->meshAttributes.Method = MESH_TRANSFINITE;
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

  case 240:
#line 3084 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 241:
#line 3089 "Gmsh.y"
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
              (*it)->meshAttributes.Method = MESH_TRANSFINITE;
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
                gr->meshAttributes.Method = MESH_TRANSFINITE;
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

  case 242:
#line 3156 "Gmsh.y"
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

  case 243:
#line 3199 "Gmsh.y"
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

  case 244:
#line 3223 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(3) - (6)].l)) != List_Nbr((yyvsp[(5) - (6)].l))){
	yymsg(0, "Periodic Line : the number of masters (%d) is not equal to the number of slaves(%d)", List_Nbr((yyvsp[(3) - (6)].l)),List_Nbr((yyvsp[(5) - (6)].l)));
      }

      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d_master,d_slave;
	List_Read((yyvsp[(3) - (6)].l), i, &d_master);
	List_Read((yyvsp[(5) - (6)].l), i, &d_slave);
	int j_master = (int)d_master;
	int j_slave  = (int)d_slave;
	Curve *c_slave = FindCurve(abs(j_slave));
	if(c_slave){
	  //	  printf("c_slave %d c_master = %d\n",j_slave,j_master);
	  c_slave->meshMaster = j_master;	  
	}
	else{
	  GEdge *ge = GModel::current()->getEdgeByTag(abs(j_slave));
	  if(ge)ge->setMeshMaster (j_master);
	  else yymsg(0, "Unknown line %d", j_slave);
	}
      }
      List_Delete((yyvsp[(3) - (6)].l));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 245:
#line 3249 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(3) - (6)].l)) != List_Nbr((yyvsp[(5) - (6)].l))){
	yymsg(0, "Periodic Surface : the number of masters (%d) is not equal to the number of slaves(%d)", List_Nbr((yyvsp[(3) - (6)].l)),List_Nbr((yyvsp[(5) - (6)].l)));
      }

      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d_master,d_slave;
	List_Read((yyvsp[(3) - (6)].l), i, &d_master);
	List_Read((yyvsp[(5) - (6)].l), i, &d_slave);
	int j_master = (int)d_master;
	int j_slave  = (int)d_slave;
	Surface *s_slave = FindSurface(abs(j_slave));
	if(s_slave){
	  s_slave->meshMaster = j_master;
	}
	else{
	  GFace *gf = GModel::current()->getFaceByTag(abs(j_slave));
	  if(gf) gf->setMeshMaster (j_master);
	  else yymsg(0, "Unknown line %d", j_slave);
	}
      }
      List_Delete((yyvsp[(3) - (6)].l));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 246:
#line 3281 "Gmsh.y"
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

  case 247:
#line 3304 "Gmsh.y"
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

  case 248:
#line 3327 "Gmsh.y"
    {
    ;}
    break;

  case 249:
#line 3330 "Gmsh.y"
    {
    ;}
    break;

  case 250:
#line 3339 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 251:
#line 3343 "Gmsh.y"
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

  case 252:
#line 3360 "Gmsh.y"
    {
    
    List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (11)].l));
    std::vector<int> domain;
    
    for (int i = 0; i < List_Nbr(temp); i++){
      int item = 0;
      List_Read(temp, i, &item);
      domain.push_back(item);
    }
    List_Delete((yyvsp[(7) - (11)].l));
    List_Delete(temp);
    
    List_T *temp2 = ListOfDouble2ListOfInt((yyvsp[(9) - (11)].l));
    std::vector<int> subdomain;
    for (int i = 0; i < List_Nbr(temp2); i++){
      int item = 0;
      List_Read(temp2, i, &item);
      subdomain.push_back(item);
    }
    List_Delete((yyvsp[(9) - (11)].l));
    List_Delete(temp2);
    
    std::string fileName = "";
    fileName = (yyvsp[(3) - (11)].c);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->setFileName(fileName);
    homology->computeRanks();
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation.");    
    #endif
    ;}
    break;

  case 253:
#line 3397 "Gmsh.y"
    {
    List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (11)].l));
    std::vector<int> domain;
    
    for (int i = 0; i < List_Nbr(temp); i++){
      int item = 0;
      List_Read(temp, i, &item);
      domain.push_back(item);
    }
    List_Delete((yyvsp[(7) - (11)].l));
    List_Delete(temp);
    
    List_T *temp2 = ListOfDouble2ListOfInt((yyvsp[(9) - (11)].l));
    std::vector<int> subdomain;
    for (int i = 0; i < List_Nbr(temp2); i++){
      int item = 0;
      List_Read(temp2, i, &item);
      subdomain.push_back(item);
    }
    List_Delete((yyvsp[(9) - (11)].l));
    List_Delete(temp2);
    
    std::string fileName = "";
    fileName = (yyvsp[(3) - (11)].c);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->setFileName(fileName);
    homology->findGenerators();  
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation.");
    #endif
    ;}
    break;

  case 254:
#line 3433 "Gmsh.y"
    {
    List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (11)].l));
    std::vector<int> domain;
    
    for (int i = 0; i < List_Nbr(temp); i++){
      int item = 0;
      List_Read(temp, i, &item);
      domain.push_back(item);
    }
    List_Delete((yyvsp[(7) - (11)].l));
    List_Delete(temp);
    
    List_T *temp2 = ListOfDouble2ListOfInt((yyvsp[(9) - (11)].l));
    std::vector<int> subdomain;
    for (int i = 0; i < List_Nbr(temp2); i++){
      int item = 0;
      List_Read(temp2, i, &item);
      subdomain.push_back(item);
    }
    List_Delete((yyvsp[(9) - (11)].l));
    List_Delete(temp2);
    
    std::string fileName = "";
    fileName = (yyvsp[(3) - (11)].c);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->setFileName(fileName);
    homology->findDualGenerators();
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation.");
    #endif
    ;}
    break;

  case 255:
#line 3468 "Gmsh.y"
    {
    List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (11)].l));
    std::vector<int> domain;
    
    for (int i = 0; i < List_Nbr(temp); i++){
      int item = 0;
      List_Read(temp, i, &item);
      domain.push_back(item);
    }
    List_Delete((yyvsp[(7) - (11)].l));
    List_Delete(temp);
    
    List_T *temp2 = ListOfDouble2ListOfInt((yyvsp[(9) - (11)].l));
    std::vector<int> subdomain;
    for (int i = 0; i < List_Nbr(temp2); i++){
      int item = 0;
      List_Read(temp2, i, &item);
      subdomain.push_back(item);
    }
    List_Delete((yyvsp[(9) - (11)].l));
    List_Delete(temp2);
    
    std::string fileName = "";
    fileName = (yyvsp[(3) - (11)].c);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->setFileName(fileName);
    homology->findHomSequence();
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation.");
    #endif
    ;}
    break;

  case 256:
#line 3507 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 257:
#line 3508 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 258:
#line 3509 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 259:
#line 3510 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 260:
#line 3511 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 261:
#line 3512 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 262:
#line 3513 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 263:
#line 3514 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 264:
#line 3516 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 265:
#line 3522 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 266:
#line 3523 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 267:
#line 3524 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 268:
#line 3525 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 269:
#line 3526 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 270:
#line 3527 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 271:
#line 3528 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 272:
#line 3529 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 273:
#line 3530 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 274:
#line 3531 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 275:
#line 3532 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 276:
#line 3533 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 277:
#line 3534 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 278:
#line 3535 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 279:
#line 3536 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 280:
#line 3537 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 281:
#line 3538 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 282:
#line 3539 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 283:
#line 3540 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 284:
#line 3541 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 285:
#line 3542 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 286:
#line 3543 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 287:
#line 3544 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 288:
#line 3545 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 289:
#line 3546 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 290:
#line 3547 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 291:
#line 3548 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 292:
#line 3549 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 293:
#line 3550 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 294:
#line 3551 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 295:
#line 3552 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 296:
#line 3553 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 297:
#line 3555 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 298:
#line 3556 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 299:
#line 3557 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 300:
#line 3558 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 301:
#line 3559 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 302:
#line 3560 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 303:
#line 3561 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 304:
#line 3562 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 305:
#line 3563 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 306:
#line 3564 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 307:
#line 3565 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 308:
#line 3566 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 309:
#line 3567 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 310:
#line 3568 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 311:
#line 3569 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 312:
#line 3570 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 313:
#line 3571 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 314:
#line 3572 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 315:
#line 3573 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 316:
#line 3574 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 317:
#line 3575 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 318:
#line 3584 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 319:
#line 3585 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 320:
#line 3586 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 321:
#line 3587 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 322:
#line 3588 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 323:
#line 3589 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 324:
#line 3590 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 325:
#line 3595 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (1)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (1)].c));
	(yyval.d) = 0.;
      }
      else{
        if(gmsh_yysymbols[(yyvsp[(1) - (1)].c)].empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (1)].c));
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = gmsh_yysymbols[(yyvsp[(1) - (1)].c)][0];
      }
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 326:
#line 3614 "Gmsh.y"
    {
      char tmpstring[1024];
      sprintf(tmpstring, "%s_%d", (yyvsp[(1) - (5)].c), (int)(yyvsp[(4) - (5)].d)) ;
      if(!gmsh_yysymbols.count(tmpstring)){
	yymsg(0, "Unknown variable '%s'", tmpstring);
	(yyval.d) = 0.;
      }
      else{
        if(gmsh_yysymbols[tmpstring].empty()){
          yymsg(0, "Uninitialized variable '%s'", tmpstring);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = gmsh_yysymbols[tmpstring][0];
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 327:
#line 3632 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
	(yyval.d) = 0.;
      }
      else if((int)gmsh_yysymbols[(yyvsp[(1) - (4)].c)].size() < index + 1){
	yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (4)].c), index);
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = gmsh_yysymbols[(yyvsp[(1) - (4)].c)][index];
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 328:
#line 3647 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(2) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(2) - (4)].c));
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = gmsh_yysymbols[(yyvsp[(2) - (4)].c)].size();
      Free((yyvsp[(2) - (4)].c));
    ;}
    break;

  case 329:
#line 3657 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (2)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (2)].c));
	(yyval.d) = 0.;
      }
      else{
        if(gmsh_yysymbols[(yyvsp[(1) - (2)].c)].empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (2)].c));
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (gmsh_yysymbols[(yyvsp[(1) - (2)].c)][0] += (yyvsp[(2) - (2)].i));
      }
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 330:
#line 3673 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (5)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (5)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (5)].c));
	(yyval.d) = 0.;
      }
      else if((int)gmsh_yysymbols[(yyvsp[(1) - (5)].c)].size() < index + 1){
	yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (5)].c), index);
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = (gmsh_yysymbols[(yyvsp[(1) - (5)].c)][index] += (yyvsp[(5) - (5)].i));
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 331:
#line 3691 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 332:
#line 3696 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 333:
#line 3701 "Gmsh.y"
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

  case 334:
#line 3711 "Gmsh.y"
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

  case 335:
#line 3721 "Gmsh.y"
    { 
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 336:
#line 3729 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 337:
#line 3733 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 338:
#line 3737 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 339:
#line 3741 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 340:
#line 3745 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 341:
#line 3752 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 342:
#line 3756 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 343:
#line 3760 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 344:
#line 3764 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 345:
#line 3771 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 346:
#line 3776 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 347:
#line 3783 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 348:
#line 3788 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 349:
#line 3792 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 350:
#line 3797 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 351:
#line 3801 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 352:
#line 3809 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 353:
#line 3820 "Gmsh.y"
    { 
      (yyval.l) = (yyvsp[(1) - (1)].l); 
    ;}
    break;

  case 354:
#line 3824 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 355:
#line 3836 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 356:
#line 3844 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 357:
#line 3852 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); 
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 358:
#line 3859 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      if(!(yyvsp[(5) - (5)].d) || ((yyvsp[(1) - (5)].d) < (yyvsp[(3) - (5)].d) && (yyvsp[(5) - (5)].d) < 0) || ((yyvsp[(1) - (5)].d) > (yyvsp[(3) - (5)].d) && (yyvsp[(5) - (5)].d) > 0)){
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[(1) - (5)].d), (yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].d));
	List_Add((yyval.l), &((yyvsp[(1) - (5)].d)));
      }
      else
	for(double d = (yyvsp[(1) - (5)].d); ((yyvsp[(5) - (5)].d) > 0) ? (d <= (yyvsp[(3) - (5)].d)) : (d >= (yyvsp[(3) - (5)].d)); d += (yyvsp[(5) - (5)].d))
	  List_Add((yyval.l), &d);
   ;}
    break;

  case 359:
#line 3870 "Gmsh.y"
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

  case 360:
#line 3890 "Gmsh.y"
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

  case 361:
#line 3900 "Gmsh.y"
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

  case 362:
#line 3910 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c));
      else
	for(unsigned int i = 0; i < gmsh_yysymbols[(yyvsp[(1) - (3)].c)].size(); i++)
	  List_Add((yyval.l), &gmsh_yysymbols[(yyvsp[(1) - (3)].c)][i]);
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 363:
#line 3920 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c));
      else{
	for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	  int index = (int)(*(double*)List_Pointer_Fast((yyvsp[(4) - (6)].l), i));
	  if((int)gmsh_yysymbols[(yyvsp[(1) - (6)].c)].size() < index + 1)
	    yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (6)].c), index);
	  else
	    List_Add((yyval.l), &gmsh_yysymbols[(yyvsp[(1) - (6)].c)][index]);
	}
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 364:
#line 3940 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 365:
#line 3945 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 366:
#line 3949 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 367:
#line 3953 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 368:
#line 3965 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 369:
#line 3969 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 370:
#line 3981 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 371:
#line 3988 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 372:
#line 3998 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 373:
#line 4002 "Gmsh.y"
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

  case 374:
#line 4017 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 375:
#line 4022 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 376:
#line 4029 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 377:
#line 4033 "Gmsh.y"
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

  case 378:
#line 4046 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 379:
#line 4054 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 380:
#line 4065 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 381:
#line 4069 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 382:
#line 4077 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 383:
#line 4085 "Gmsh.y"
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

  case 384:
#line 4099 "Gmsh.y"
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

  case 385:
#line 4113 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 386:
#line 4117 "Gmsh.y"
    {
      char tmpstring[1024];
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


/* Line 1267 of yacc.c.  */
#line 8781 "Gmsh.tab.cpp"
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


#line 4137 "Gmsh.y"


int PrintListOfDouble(char *format, List_T *list, char *buffer)
{
  int j, k;
  char tmp1[256], tmp2[256];

  j = 0;
  buffer[j] = '\0';

  while(j < (int)strlen(format) && format[j] != '%') j++;
  strncpy(buffer, format, j); 
  buffer[j]='\0'; 
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
      return List_Nbr(list)-i;
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

