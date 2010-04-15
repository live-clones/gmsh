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
     tUsing = 320,
     tPlugin = 321,
     tDegenerated = 322,
     tOCCShape = 323,
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
#define tUsing 320
#define tPlugin 321
#define tDegenerated 322
#define tOCCShape 323
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
#define YYLAST   6752

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  151
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  384
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1373

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
      40,    42,    44,    46,    49,    55,    63,    71,    81,    88,
      95,   102,   103,   106,   109,   112,   115,   118,   120,   124,
     126,   130,   131,   132,   143,   145,   149,   150,   164,   166,
     170,   171,   187,   196,   211,   212,   219,   221,   223,   225,
     227,   229,   231,   233,   238,   246,   256,   263,   270,   274,
     281,   286,   293,   303,   310,   320,   326,   335,   344,   356,
     363,   373,   379,   387,   397,   407,   419,   429,   439,   441,
     443,   444,   450,   451,   454,   462,   463,   473,   480,   488,
     493,   501,   510,   519,   527,   535,   547,   556,   565,   566,
     576,   585,   595,   599,   604,   615,   623,   631,   640,   650,
     664,   665,   675,   684,   692,   702,   711,   712,   722,   728,
     740,   746,   756,   761,   771,   781,   783,   785,   786,   789,
     796,   803,   810,   817,   826,   841,   858,   871,   880,   889,
     896,   911,   916,   923,   930,   934,   939,   945,   949,   953,
     958,   963,   967,   975,   983,   987,   995,   999,  1002,  1005,
    1008,  1024,  1027,  1030,  1037,  1046,  1055,  1066,  1068,  1071,
    1073,  1077,  1082,  1084,  1090,  1102,  1116,  1117,  1125,  1126,
    1140,  1141,  1157,  1158,  1165,  1174,  1183,  1192,  1205,  1218,
    1231,  1246,  1261,  1276,  1277,  1290,  1291,  1304,  1305,  1318,
    1319,  1336,  1337,  1354,  1355,  1372,  1373,  1392,  1393,  1412,
    1413,  1432,  1434,  1437,  1443,  1451,  1461,  1464,  1474,  1475,
    1477,  1478,  1482,  1483,  1485,  1486,  1489,  1490,  1493,  1501,
    1508,  1517,  1523,  1529,  1536,  1547,  1558,  1569,  1580,  1583,
    1587,  1599,  1611,  1623,  1635,  1637,  1641,  1644,  1647,  1650,
    1654,  1658,  1662,  1666,  1670,  1674,  1678,  1682,  1686,  1690,
    1694,  1698,  1702,  1706,  1712,  1717,  1722,  1727,  1732,  1737,
    1742,  1747,  1752,  1757,  1762,  1769,  1774,  1779,  1784,  1789,
    1794,  1799,  1806,  1813,  1820,  1825,  1830,  1835,  1840,  1845,
    1850,  1855,  1860,  1865,  1870,  1875,  1882,  1887,  1892,  1897,
    1902,  1907,  1912,  1919,  1926,  1933,  1938,  1940,  1942,  1944,
    1946,  1948,  1950,  1952,  1954,  1960,  1965,  1970,  1973,  1979,
    1983,  1990,  1995,  2003,  2010,  2012,  2015,  2018,  2022,  2026,
    2038,  2048,  2056,  2064,  2066,  2070,  2072,  2074,  2077,  2081,
    2086,  2092,  2094,  2096,  2099,  2103,  2107,  2113,  2118,  2120,
    2122,  2126,  2133,  2135,  2137,  2141,  2145,  2155,  2163,  2165,
    2171,  2175,  2182,  2184,  2188,  2190,  2192,  2196,  2203,  2205,
    2207,  2214,  2219,  2224,  2229
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     152,     0,    -1,   153,    -1,     1,     6,    -1,    -1,   153,
     154,    -1,   157,    -1,   156,    -1,   175,    -1,   179,    -1,
     184,    -1,   188,    -1,   189,    -1,   190,    -1,   193,    -1,
     214,    -1,   215,    -1,   216,    -1,   192,    -1,   191,    -1,
     187,    -1,   217,    -1,   128,    -1,   128,   128,    -1,    35,
     141,     5,   142,     6,    -1,    35,   141,     5,   142,   155,
     230,     6,    -1,    35,   141,     5,   147,   226,   142,     6,
      -1,    35,   141,     5,   147,   226,   142,   155,   230,     6,
      -1,     4,     5,   148,   158,   149,     6,    -1,    84,     4,
     143,   218,   144,     6,    -1,    85,     4,   143,   218,   144,
       6,    -1,    -1,   158,   161,    -1,   158,   165,    -1,   158,
     168,    -1,   158,   170,    -1,   158,   171,    -1,   218,    -1,
     159,   147,   218,    -1,   218,    -1,   160,   147,   218,    -1,
      -1,    -1,     4,   162,   141,   159,   142,   163,   148,   160,
     149,     6,    -1,   230,    -1,   164,   147,   230,    -1,    -1,
      86,   141,   218,   147,   218,   147,   218,   142,   166,   148,
     164,   149,     6,    -1,   230,    -1,   167,   147,   230,    -1,
      -1,    87,   141,   218,   147,   218,   147,   218,   147,   218,
     142,   169,   148,   167,   149,     6,    -1,    88,   148,   222,
     149,   148,   222,   149,     6,    -1,    88,   148,   222,   149,
     148,   222,   149,   148,   222,   149,   148,   222,   149,     6,
      -1,    -1,    89,   172,   148,   160,   149,     6,    -1,     7,
      -1,   121,    -1,   120,    -1,   119,    -1,   118,    -1,   139,
      -1,   138,    -1,     4,   173,   218,     6,    -1,     4,   143,
     218,   144,   173,   218,     6,    -1,     4,   143,   148,   226,
     149,   144,   173,   223,     6,    -1,     4,   143,   144,     7,
     223,     6,    -1,     4,   143,   144,   121,   223,     6,    -1,
       4,   174,     6,    -1,     4,   143,   218,   144,   174,     6,
      -1,     4,     7,   231,     6,    -1,     4,   145,     4,     7,
     231,     6,    -1,     4,   143,   218,   144,   145,     4,     7,
     231,     6,    -1,     4,   145,     4,   173,   218,     6,    -1,
       4,   143,   218,   144,   145,     4,   173,   218,     6,    -1,
       4,   145,     4,   174,     6,    -1,     4,   143,   218,   144,
     145,     4,   174,     6,    -1,     4,   145,    96,   145,     4,
       7,   227,     6,    -1,     4,   143,   218,   144,   145,    96,
     145,     4,     7,   227,     6,    -1,     4,   145,    97,     7,
     228,     6,    -1,     4,   143,   218,   144,   145,    97,     7,
     228,     6,    -1,     4,   104,     7,   218,     6,    -1,   104,
     143,   218,   144,     7,     4,     6,    -1,   104,   143,   218,
     144,   145,     4,     7,   218,     6,    -1,   104,   143,   218,
     144,   145,     4,     7,   231,     6,    -1,   104,   143,   218,
     144,   145,     4,     7,   148,   226,   149,     6,    -1,    66,
     141,     4,   142,   145,     4,     7,   218,     6,    -1,    66,
     141,     4,   142,   145,     4,     7,   231,     6,    -1,   218,
      -1,   231,    -1,    -1,    99,    50,   148,   218,   149,    -1,
      -1,    59,   220,    -1,    46,   141,   218,   142,     7,   220,
       6,    -1,    -1,    63,    46,   180,   141,   176,   142,     7,
     223,     6,    -1,    55,    56,   223,     7,   218,     6,    -1,
      49,   141,   218,   142,     7,   223,     6,    -1,    67,    49,
     223,     6,    -1,    53,   141,   218,   142,     7,   223,     6,
      -1,    47,   141,   218,   142,     7,   223,   178,     6,    -1,
      48,   141,   218,   142,     7,   223,   178,     6,    -1,    91,
     141,   218,   142,     7,   223,     6,    -1,    92,   141,   218,
     142,     7,   223,     6,    -1,    93,   141,   218,   142,     7,
     223,    95,   223,    94,   218,     6,    -1,    49,    75,   141,
     218,   142,     7,   223,     6,    -1,    64,    49,   141,   218,
     142,     7,   223,     6,    -1,    -1,    63,    49,   181,   141,
     176,   142,     7,   223,     6,    -1,    59,    52,   141,   218,
     142,     7,   223,     6,    -1,    60,    52,   141,   218,   142,
       7,   223,   177,     6,    -1,    12,    13,     6,    -1,    13,
      52,   218,     6,    -1,    57,    52,   141,   218,   142,     7,
       5,     5,     5,     6,    -1,    50,   141,   218,   142,     7,
     223,     6,    -1,    51,   141,   218,   142,     7,   223,     6,
      -1,    52,    75,   141,   218,   142,     7,   223,     6,    -1,
      64,    52,   141,   218,   142,     7,   223,   209,     6,    -1,
      64,    52,   141,   218,   142,     7,   223,     4,   148,   222,
     149,   209,     6,    -1,    -1,    63,    52,   182,   141,   176,
     142,     7,   223,     6,    -1,    62,    54,   141,   218,   142,
       7,   223,     6,    -1,    54,   141,   218,   142,     7,   223,
       6,    -1,    68,   141,     5,   147,   223,   147,     5,   142,
       6,    -1,    64,    54,   141,   218,   142,     7,   223,     6,
      -1,    -1,    63,    54,   183,   141,   176,   142,     7,   223,
       6,    -1,    70,   220,   148,   185,   149,    -1,    69,   148,
     220,   147,   220,   147,   218,   149,   148,   185,   149,    -1,
      71,   220,   148,   185,   149,    -1,    72,   148,   220,   147,
     218,   149,   148,   185,   149,    -1,     4,   148,   185,   149,
      -1,    81,    49,   148,   226,   149,    52,   148,   218,   149,
      -1,    78,    49,   141,   218,   142,   148,   226,   149,     6,
      -1,   186,    -1,   184,    -1,    -1,   186,   179,    -1,   186,
      46,   148,   226,   149,     6,    -1,   186,    49,   148,   226,
     149,     6,    -1,   186,    52,   148,   226,   149,     6,    -1,
     186,    54,   148,   226,   149,     6,    -1,    74,    59,   141,
     218,   142,     7,   223,     6,    -1,    74,    59,   141,   218,
     142,     7,   148,   220,   147,   220,   147,   226,   149,     6,
      -1,    74,    59,   141,   218,   142,     7,   148,   220,   147,
     220,   147,   220,   147,   226,   149,     6,    -1,    74,    50,
     141,   218,   142,     7,   148,   220,   147,   226,   149,     6,
      -1,    74,     4,   141,   218,   142,     7,   223,     6,    -1,
      74,     4,   141,   218,   142,     7,     5,     6,    -1,    74,
       4,   148,   218,   149,     6,    -1,    74,     4,   141,   218,
     142,     7,   148,   220,   147,   220,   147,   226,   149,     6,
      -1,    79,   148,   186,   149,    -1,    79,   104,   143,   218,
     144,     6,    -1,    79,     4,   143,   218,   144,     6,    -1,
      79,     4,     6,    -1,    79,     4,     4,     6,    -1,    96,
     227,   148,   186,   149,    -1,   108,     5,     6,    -1,   109,
       5,     6,    -1,   108,   148,   186,   149,    -1,   109,   148,
     186,   149,    -1,     4,   231,     6,    -1,     4,     4,   143,
     218,   144,   230,     6,    -1,     4,     4,     4,   143,   218,
     144,     6,    -1,     4,   218,     6,    -1,    66,   141,     4,
     142,   145,     4,     6,    -1,    90,     4,     6,    -1,   103,
       6,    -1,    43,     6,    -1,    40,     6,    -1,    40,   148,
     218,   147,   218,   147,   218,   147,   218,   147,   218,   147,
     218,   149,     6,    -1,    41,     6,    -1,    44,     6,    -1,
      98,   141,   218,     8,   218,   142,    -1,    98,   141,   218,
       8,   218,     8,   218,   142,    -1,    98,     4,    99,   148,
     218,     8,   218,   149,    -1,    98,     4,    99,   148,   218,
       8,   218,     8,   218,   149,    -1,   100,    -1,   107,     4,
      -1,   105,    -1,   106,     4,     6,    -1,   101,   141,   218,
     142,    -1,   102,    -1,    73,   220,   148,   186,   149,    -1,
      73,   148,   220,   147,   220,   147,   218,   149,   148,   186,
     149,    -1,    73,   148,   220,   147,   220,   147,   220,   147,
     218,   149,   148,   186,   149,    -1,    -1,    73,   220,   148,
     186,   194,   207,   149,    -1,    -1,    73,   148,   220,   147,
     220,   147,   218,   149,   148,   186,   195,   207,   149,    -1,
      -1,    73,   148,   220,   147,   220,   147,   220,   147,   218,
     149,   148,   186,   196,   207,   149,    -1,    -1,    73,   148,
     186,   197,   207,   149,    -1,    73,    46,   148,   218,   147,
     220,   149,     6,    -1,    73,    49,   148,   218,   147,   220,
     149,     6,    -1,    73,    52,   148,   218,   147,   220,   149,
       6,    -1,    73,    46,   148,   218,   147,   220,   147,   220,
     147,   218,   149,     6,    -1,    73,    49,   148,   218,   147,
     220,   147,   220,   147,   218,   149,     6,    -1,    73,    52,
     148,   218,   147,   220,   147,   220,   147,   218,   149,     6,
      -1,    73,    46,   148,   218,   147,   220,   147,   220,   147,
     220,   147,   218,   149,     6,    -1,    73,    49,   148,   218,
     147,   220,   147,   220,   147,   220,   147,   218,   149,     6,
      -1,    73,    52,   148,   218,   147,   220,   147,   220,   147,
     220,   147,   218,   149,     6,    -1,    -1,    73,    46,   148,
     218,   147,   220,   149,   198,   148,   207,   149,     6,    -1,
      -1,    73,    49,   148,   218,   147,   220,   149,   199,   148,
     207,   149,     6,    -1,    -1,    73,    52,   148,   218,   147,
     220,   149,   200,   148,   207,   149,     6,    -1,    -1,    73,
      46,   148,   218,   147,   220,   147,   220,   147,   218,   149,
     201,   148,   207,   149,     6,    -1,    -1,    73,    49,   148,
     218,   147,   220,   147,   220,   147,   218,   149,   202,   148,
     207,   149,     6,    -1,    -1,    73,    52,   148,   218,   147,
     220,   147,   220,   147,   218,   149,   203,   148,   207,   149,
       6,    -1,    -1,    73,    46,   148,   218,   147,   220,   147,
     220,   147,   220,   147,   218,   149,   204,   148,   207,   149,
       6,    -1,    -1,    73,    49,   148,   218,   147,   220,   147,
     220,   147,   220,   147,   218,   149,   205,   148,   207,   149,
       6,    -1,    -1,    73,    52,   148,   218,   147,   220,   147,
     220,   147,   220,   147,   218,   149,   206,   148,   207,   149,
       6,    -1,   208,    -1,   207,   208,    -1,    82,   148,   218,
     149,     6,    -1,    82,   148,   223,   147,   223,   149,     6,
      -1,    82,   148,   223,   147,   223,   147,   223,   149,     6,
      -1,    76,     6,    -1,    83,   141,   218,   142,     7,   223,
      65,   218,     6,    -1,    -1,     4,    -1,    -1,    65,     4,
     218,    -1,    -1,     4,    -1,    -1,     7,   223,    -1,    -1,
       7,   218,    -1,    61,    49,   224,     7,   218,   210,     6,
      -1,    61,    52,   224,   212,   211,     6,    -1,    58,    52,
     148,   218,   149,     7,   223,     6,    -1,    61,    54,   224,
     212,     6,    -1,    76,    52,   224,   213,     6,    -1,    77,
      52,   223,     7,   218,     6,    -1,    46,   148,   226,   149,
      99,    52,   148,   218,   149,     6,    -1,    49,   148,   226,
     149,    99,    52,   148,   218,   149,     6,    -1,    49,   148,
     226,   149,    99,    54,   148,   218,   149,     6,    -1,    52,
     148,   226,   149,    99,    54,   148,   218,   149,     6,    -1,
      80,     6,    -1,    80,     4,     6,    -1,   114,   141,   230,
     142,     7,   148,   223,   147,   223,   149,     6,    -1,   115,
     141,   230,   142,     7,   148,   223,   147,   223,   149,     6,
      -1,   116,   141,   230,   142,     7,   148,   223,   147,   223,
     149,     6,    -1,   117,   141,   230,   142,     7,   148,   223,
     147,   223,   149,     6,    -1,   219,    -1,   141,   218,   142,
      -1,   132,   218,    -1,   131,   218,    -1,   136,   218,    -1,
     218,   132,   218,    -1,   218,   131,   218,    -1,   218,   133,
     218,    -1,   218,   134,   218,    -1,   218,   135,   218,    -1,
     218,   140,   218,    -1,   218,   127,   218,    -1,   218,   128,
     218,    -1,   218,   130,   218,    -1,   218,   129,   218,    -1,
     218,   126,   218,    -1,   218,   125,   218,    -1,   218,   124,
     218,    -1,   218,   123,   218,    -1,   218,   122,   218,     8,
     218,    -1,    14,   141,   218,   142,    -1,    15,   141,   218,
     142,    -1,    16,   141,   218,   142,    -1,    17,   141,   218,
     142,    -1,    18,   141,   218,   142,    -1,    19,   141,   218,
     142,    -1,    20,   141,   218,   142,    -1,    21,   141,   218,
     142,    -1,    22,   141,   218,   142,    -1,    24,   141,   218,
     142,    -1,    25,   141,   218,   147,   218,   142,    -1,    26,
     141,   218,   142,    -1,    27,   141,   218,   142,    -1,    28,
     141,   218,   142,    -1,    29,   141,   218,   142,    -1,    30,
     141,   218,   142,    -1,    31,   141,   218,   142,    -1,    32,
     141,   218,   147,   218,   142,    -1,    33,   141,   218,   147,
     218,   142,    -1,    34,   141,   218,   147,   218,   142,    -1,
      23,   141,   218,   142,    -1,    14,   143,   218,   144,    -1,
      15,   143,   218,   144,    -1,    16,   143,   218,   144,    -1,
      17,   143,   218,   144,    -1,    18,   143,   218,   144,    -1,
      19,   143,   218,   144,    -1,    20,   143,   218,   144,    -1,
      21,   143,   218,   144,    -1,    22,   143,   218,   144,    -1,
      24,   143,   218,   144,    -1,    25,   143,   218,   147,   218,
     144,    -1,    26,   143,   218,   144,    -1,    27,   143,   218,
     144,    -1,    28,   143,   218,   144,    -1,    29,   143,   218,
     144,    -1,    30,   143,   218,   144,    -1,    31,   143,   218,
     144,    -1,    32,   143,   218,   147,   218,   144,    -1,    33,
     143,   218,   147,   218,   144,    -1,    34,   143,   218,   147,
     218,   144,    -1,    23,   143,   218,   144,    -1,     3,    -1,
       9,    -1,    10,    -1,    11,    -1,   111,    -1,   112,    -1,
     113,    -1,     4,    -1,     4,   150,   148,   218,   149,    -1,
       4,   143,   218,   144,    -1,   146,     4,   143,   144,    -1,
       4,   174,    -1,     4,   143,   218,   144,   174,    -1,     4,
     145,     4,    -1,     4,   143,   218,   144,   145,     4,    -1,
       4,   145,     4,   174,    -1,     4,   143,   218,   144,   145,
       4,   174,    -1,   110,   141,     5,   147,   218,   142,    -1,
     221,    -1,   132,   220,    -1,   131,   220,    -1,   220,   132,
     220,    -1,   220,   131,   220,    -1,   148,   218,   147,   218,
     147,   218,   147,   218,   147,   218,   149,    -1,   148,   218,
     147,   218,   147,   218,   147,   218,   149,    -1,   148,   218,
     147,   218,   147,   218,   149,    -1,   141,   218,   147,   218,
     147,   218,   142,    -1,   223,    -1,   222,   147,   223,    -1,
     218,    -1,   225,    -1,   148,   149,    -1,   148,   226,   149,
      -1,   132,   148,   226,   149,    -1,   218,   133,   148,   226,
     149,    -1,   223,    -1,     5,    -1,   132,   225,    -1,   218,
     133,   225,    -1,   218,     8,   218,    -1,   218,     8,   218,
       8,   218,    -1,    46,   148,   218,   149,    -1,   184,    -1,
     193,    -1,     4,   143,   144,    -1,     4,   143,   148,   226,
     149,   144,    -1,   218,    -1,   225,    -1,   226,   147,   218,
      -1,   226,   147,   225,    -1,   148,   218,   147,   218,   147,
     218,   147,   218,   149,    -1,   148,   218,   147,   218,   147,
     218,   149,    -1,     4,    -1,     4,   145,    96,   145,     4,
      -1,   148,   229,   149,    -1,     4,   143,   218,   144,   145,
      97,    -1,   227,    -1,   229,   147,   227,    -1,   231,    -1,
       4,    -1,     4,   145,     4,    -1,     4,   143,   218,   144,
     145,     4,    -1,     5,    -1,    42,    -1,    37,   141,   230,
     147,   230,   142,    -1,    38,   141,   230,   142,    -1,    39,
     141,   230,   142,    -1,    36,   141,   230,   142,    -1,    36,
     141,   230,   147,   226,   142,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   156,   156,   157,   162,   164,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   187,   191,   198,   203,   217,   230,   258,   272,
     283,   298,   303,   304,   305,   306,   307,   311,   313,   318,
     320,   326,   430,   325,   448,   455,   466,   465,   483,   490,
     501,   500,   517,   534,   557,   556,   570,   571,   572,   573,
     574,   578,   579,   586,   608,   635,   675,   685,   693,   701,
     713,   722,   728,   737,   755,   773,   782,   794,   799,   807,
     827,   850,   859,   867,   889,   912,   940,   952,   969,   973,
     984,   987,  1000,  1003,  1013,  1037,  1036,  1056,  1078,  1096,
    1118,  1136,  1166,  1196,  1214,  1232,  1258,  1275,  1294,  1293,
    1316,  1334,  1373,  1379,  1385,  1392,  1417,  1442,  1458,  1476,
    1509,  1508,  1532,  1550,  1568,  1581,  1598,  1597,  1623,  1628,
    1633,  1638,  1643,  1663,  1669,  1680,  1681,  1686,  1689,  1693,
    1716,  1739,  1762,  1790,  1811,  1832,  1854,  1874,  1986,  2005,
    2025,  2134,  2143,  2149,  2164,  2192,  2209,  2223,  2229,  2235,
    2244,  2258,  2300,  2317,  2332,  2351,  2363,  2387,  2391,  2398,
    2404,  2409,  2415,  2425,  2442,  2459,  2478,  2497,  2527,  2535,
    2541,  2548,  2552,  2561,  2569,  2577,  2586,  2585,  2598,  2597,
    2610,  2609,  2622,  2621,  2634,  2641,  2648,  2655,  2662,  2669,
    2676,  2683,  2690,  2698,  2697,  2709,  2708,  2720,  2719,  2731,
    2730,  2742,  2741,  2753,  2752,  2764,  2763,  2775,  2774,  2786,
    2785,  2800,  2803,  2809,  2818,  2838,  2861,  2865,  2889,  2892,
    2908,  2911,  2927,  2930,  2943,  2946,  2952,  2955,  2962,  3018,
    3088,  3093,  3160,  3203,  3229,  3252,  3275,  3278,  3287,  3291,
    3308,  3345,  3381,  3416,  3456,  3457,  3458,  3459,  3460,  3461,
    3462,  3463,  3464,  3471,  3472,  3473,  3474,  3475,  3476,  3477,
    3478,  3479,  3480,  3481,  3482,  3483,  3484,  3485,  3486,  3487,
    3488,  3489,  3490,  3491,  3492,  3493,  3494,  3495,  3496,  3497,
    3498,  3499,  3500,  3501,  3502,  3504,  3505,  3506,  3507,  3508,
    3509,  3510,  3511,  3512,  3513,  3514,  3515,  3516,  3517,  3518,
    3519,  3520,  3521,  3522,  3523,  3524,  3533,  3534,  3535,  3536,
    3537,  3538,  3539,  3543,  3556,  3568,  3583,  3593,  3603,  3621,
    3626,  3631,  3641,  3651,  3659,  3663,  3667,  3671,  3675,  3682,
    3686,  3690,  3694,  3701,  3706,  3713,  3718,  3722,  3727,  3731,
    3739,  3750,  3754,  3766,  3774,  3782,  3789,  3800,  3820,  3830,
    3840,  3850,  3870,  3875,  3879,  3883,  3895,  3899,  3911,  3918,
    3928,  3932,  3947,  3952,  3959,  3963,  3976,  3984,  3995,  3999,
    4007,  4015,  4029,  4043,  4047
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
  "tTransfinite", "tComplex", "tPhysical", "tCompound", "tUsing",
  "tPlugin", "tDegenerated", "tOCCShape", "tRotate", "tTranslate",
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
  "RecombineAngle", "Transfinite", "Embedding", "Coherence", "Homology",
  "FExpr", "FExpr_Single", "VExpr", "VExpr_Single",
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
     154,   154,   155,   155,   156,   156,   156,   156,   157,   157,
     157,   158,   158,   158,   158,   158,   158,   159,   159,   160,
     160,   162,   163,   161,   164,   164,   166,   165,   167,   167,
     169,   168,   170,   170,   172,   171,   173,   173,   173,   173,
     173,   174,   174,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   176,   176,
     177,   177,   178,   178,   179,   180,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   181,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     182,   179,   179,   179,   179,   179,   183,   179,   184,   184,
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
     214,   214,   214,   214,   215,   215,   215,   215,   216,   216,
     217,   217,   217,   217,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   220,   220,   220,   220,   220,   221,
     221,   221,   221,   222,   222,   223,   223,   223,   223,   223,
     223,   224,   224,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   226,   226,   226,   226,   227,   227,   227,   227,
     228,   228,   229,   229,   230,   230,   230,   230,   231,   231,
     231,   231,   231,   231,   231
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     5,     7,     7,     9,     6,     6,
       6,     0,     2,     2,     2,     2,     2,     1,     3,     1,
       3,     0,     0,    10,     1,     3,     0,    13,     1,     3,
       0,    15,     8,    14,     0,     6,     1,     1,     1,     1,
       1,     1,     1,     4,     7,     9,     6,     6,     3,     6,
       4,     6,     9,     6,     9,     5,     8,     8,    11,     6,
       9,     5,     7,     9,     9,    11,     9,     9,     1,     1,
       0,     5,     0,     2,     7,     0,     9,     6,     7,     4,
       7,     8,     8,     7,     7,    11,     8,     8,     0,     9,
       8,     9,     3,     4,    10,     7,     7,     8,     9,    13,
       0,     9,     8,     7,     9,     8,     0,     9,     5,    11,
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
       8,     5,     5,     6,    10,    10,    10,    10,     2,     3,
      11,    11,    11,    11,     1,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     4,     2,     5,     3,
       6,     4,     7,     6,     1,     2,     2,     3,     3,    11,
       9,     7,     7,     1,     3,     1,     1,     2,     3,     4,
       5,     1,     1,     2,     3,     3,     5,     4,     1,     1,
       3,     6,     1,     1,     3,     3,     9,     7,     1,     5,
       3,     6,     1,     3,     1,     1,     3,     6,     1,     1,
       6,     4,     4,     4,     6
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
       7,     6,     8,     9,    10,    20,    11,    12,    13,    19,
      18,    14,    15,    16,    17,    21,   316,   323,   378,    56,
     317,   318,   319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   379,     0,
       0,   320,   321,   322,    60,    59,    58,    57,     0,     0,
       0,    62,    61,     0,     0,     0,     0,   137,     0,     0,
       0,   254,     0,     0,     0,     0,   169,     0,   171,   168,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,   108,   120,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   334,
       0,     0,     0,     0,     0,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,   248,     0,     0,
       0,     0,     0,     0,     0,   368,     0,     0,     0,     0,
       0,   167,     0,     0,   178,     0,   137,     0,   137,     0,
       0,     0,     0,     0,     0,     0,     0,   327,    31,   378,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   323,
     257,   256,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,   135,     0,    68,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   161,   112,     0,     0,     0,     0,   323,
       0,     0,   358,   359,   362,   363,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     345,     0,   346,     0,     0,     0,     0,   352,   351,     0,
     234,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   336,   335,     0,     0,     0,     0,
     137,   137,     0,     0,     0,     0,     0,     0,     0,   192,
       0,   137,     0,     0,     0,     0,   236,     0,     0,     0,
     154,     0,     0,     0,   249,     0,     0,     0,   166,     0,
       0,     0,     0,     0,   137,     0,     0,     0,     0,   180,
     157,     0,   158,     0,   375,     0,   374,     0,     0,     0,
       0,     0,   329,     0,     0,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,   132,     0,     0,     0,
       0,   138,    63,     0,   272,   271,   270,   269,   265,   266,
     268,   267,   260,   259,   261,   262,   263,   264,   113,     0,
       0,     0,     0,     0,     0,   256,   353,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   347,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   232,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,   338,
     337,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,     0,     0,     0,     0,     0,     0,     0,     0,   155,
       0,     0,   151,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,     0,   159,   160,     0,     0,
       0,     0,     0,     0,     0,   325,   331,     0,    41,     0,
       0,     0,    54,     0,    32,    33,    34,    35,    36,   274,
     295,   275,   296,   276,   297,   277,   298,   278,   299,   279,
     300,   280,   301,   281,   302,   282,   303,   294,   315,   283,
     304,     0,     0,   285,   306,   286,   307,   287,   308,   288,
     309,   289,   310,   290,   311,     0,     0,     0,     0,     0,
       0,   383,     0,     0,   381,   382,    81,     0,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,   326,     0,     0,     0,     0,     0,    24,
      22,     0,     0,     0,     0,   360,     0,     0,   355,   261,
     354,   364,   365,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   348,     0,     0,     0,
       0,     0,     0,   230,   235,   233,     0,   241,     0,     0,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,   130,     0,     0,     0,     0,     0,
       0,     0,     0,   221,     0,   183,     0,     0,     0,     0,
       0,   237,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,     0,     0,     0,     0,
       0,   376,     0,     0,     0,     0,     0,     0,   328,     0,
     324,     0,     0,     0,     0,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   325,    66,
      67,     0,     0,     0,     0,     0,    69,    71,    73,     0,
       0,   372,     0,    79,     0,     0,     0,     0,   273,    23,
       0,     0,     0,     0,     0,   357,     0,     0,    92,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     349,     0,    97,     0,     0,     0,     0,     0,     0,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   226,     0,     0,
     193,   222,     0,     0,     0,   149,     0,     0,   243,     0,
     153,   152,     0,    29,    30,     0,     0,     0,   369,     0,
       0,     0,   173,     0,     0,     0,     0,     0,     0,     0,
     163,   330,   162,     0,     0,     0,     0,   343,     0,   284,
     305,   291,   312,   292,   313,   293,   314,   384,   380,   333,
       0,    56,     0,     0,     0,     0,    64,     0,     0,     0,
     370,     0,     0,     0,     0,    25,    26,     0,     0,    94,
       0,   356,     0,     0,     0,     0,     0,    98,     0,     0,
     115,   116,     0,     0,   100,   123,   350,     0,     0,     0,
      90,     0,   238,     0,     0,     0,     0,     0,     0,   228,
       0,   165,     0,     0,     0,     0,     0,   137,     0,   203,
       0,   205,     0,   207,   345,     0,     0,     0,     0,   187,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   104,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,   332,     0,    37,     0,     0,     0,     0,     0,    39,
       0,     0,     0,    76,     0,     0,    77,     0,   373,   139,
     140,   141,   142,     0,     0,   361,     0,    93,   101,   102,
     106,     0,     0,   117,     0,     0,   240,   110,     0,     0,
     231,   122,     0,     0,     0,     0,   107,   229,     0,   125,
       0,     0,     0,     0,   342,     0,   341,     0,     0,   194,
       0,     0,   195,     0,     0,   196,     0,     0,     0,     0,
       0,     0,   148,     0,     0,   147,     0,     0,   143,     0,
       0,     0,     0,   367,     0,   175,   174,     0,     0,     0,
     377,     0,     0,     0,     0,    42,     0,     0,     0,   344,
       0,     0,     0,    65,    72,    74,     0,    80,     0,    27,
       0,     0,     0,     0,     0,     0,     0,   111,    96,   109,
     121,   127,     0,   118,    86,    87,   124,   137,     0,   131,
       0,     0,     0,     0,     0,     0,   223,     0,     0,   137,
       0,     0,     0,     0,   134,   133,     0,     0,     0,     0,
      83,    84,     0,     0,     0,     0,     0,    38,     0,     0,
       0,    40,    55,     0,   371,     0,   244,   245,   246,   247,
     114,     0,     0,     0,     0,   340,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   188,     0,
       0,     0,     0,     0,   366,   176,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,   228,   129,
       0,   209,     0,     0,   211,     0,     0,   213,     0,     0,
       0,   224,     0,   184,     0,   137,     0,     0,     0,   105,
      85,   250,   251,   252,   253,     0,    46,     0,    52,     0,
       0,    91,   229,     0,   339,   197,     0,     0,   204,   198,
       0,     0,   206,   199,     0,     0,   208,     0,     0,     0,
     190,     0,   146,     0,     0,     0,     0,     0,     0,     0,
     119,     0,   215,     0,   217,     0,   219,   225,   227,   189,
     185,     0,     0,     0,     0,    43,     0,    50,     0,     0,
       0,   200,     0,     0,   201,     0,     0,   202,     0,     0,
     150,     0,   144,     0,    44,     0,     0,   170,     0,     0,
       0,     0,     0,     0,   191,     0,     0,     0,     0,     0,
     210,     0,   212,     0,   214,     0,   145,    45,    47,     0,
      48,     0,     0,     0,     0,     0,     0,    53,   216,   218,
     220,    49,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    69,   701,    70,    71,   434,  1032,  1038,
     624,   801,  1186,  1333,   625,  1296,  1359,   626,  1335,   627,
     628,   805,   138,   237,    72,   739,  1069,   964,   501,   363,
     364,   365,   366,   332,   303,   304,    75,    76,    77,    78,
      79,    80,   333,   766,  1254,  1311,   578,  1090,  1093,  1096,
    1276,  1280,  1284,  1322,  1325,  1328,   762,   763,  1078,   868,
     736,   553,   586,    82,    83,    84,    85,   350,   141,   375,
     189,   926,   927,   359,   352,   544,   217,   692,   832,   425,
     426
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1108
static const yytype_int16 yypact[] =
{
    3373,    40,    70,  3479, -1108, -1108,  1690,    76,    56,   -49,
       1,   120,   133,   137,   -62,    83,    89,   -47,   138,   146,
     -41,   150,   159,   261,   294,   308,   312,   324,   228,   313,
     604,   247,   232,   336,   262,   246,   274,   274,   256,   278,
      62,   356,   359,   371,    11,    26,   376,   427,   432,   440,
     304,   317,   332,    20,    36, -1108,   335, -1108,   448,   334,
   -1108,   483,   487,    -4,     6,   366,   372,   383,   384, -1108,
   -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108,
   -1108, -1108, -1108, -1108, -1108, -1108, -1108,    22,   342,   495,
   -1108, -1108, -1108,    47,   147,   227,   280,   287,   326,   355,
     433,   439,   473,   514,   540,   544,   552,   553,   558,   577,
     583,   587,   598,   599,   394,   397,   403,   408, -1108,   513,
     419, -1108, -1108, -1108, -1108, -1108, -1108, -1108,  3208,  3208,
    3208, -1108, -1108,  3208,  2749,    14,   562,   214,  3208,   572,
    1166, -1108,   579,   585,  3208,   590, -1108,  3208, -1108, -1108,
   -1108,  3208,  3135,  3208,  3208,   458,  3208,  3135,  3208,  3208,
     459,  3135,  3208,  3208,  2116,   462,   472,   468,   499,  1836,
    1836,  1836,   500, -1108, -1108, -1108, -1108,   507,   524,   528,
     623,  2116,   665,   274,   274,   274,  3208,  3208,   -77, -1108,
     -58,   274,   525,   538,   554,  2995,   -32,   -11,   578,   588,
    1836,  2116,   602,    33,   560, -1108,   750, -1108,   640,   691,
     695,   783,  3208,  3208,  3208,   649,  3208,   658,   708,  3208,
    3208, -1108,  3208,   811, -1108,   816, -1108,   835, -1108,   466,
     466,   466,   466,   714,  3208,   857,   722, -1108, -1108, -1108,
     856,  3208,  3208,  3208,  3208,  3208,  3208,  3208,  3208,  3208,
    3208,  3208,  3208,  3208,  3208,  3208,  3208,  3208,  3208,  3208,
    3208,  3208,  3208,  3208,  3208,  3208,  3208,  3208,  3208,  3208,
    3208,  3208,  3208,  3208,  3208,  3208,  3208,  3208,  3208,  3208,
    3208,  3208,  3208,   466,   466,   466,   466,  3208,   874,   529,
     740,   740,   740,  5499,    65,  3135,  4763,    84,   736,   877,
     742,   751, -1108,   752,  2984,  1193, -1108, -1108,  3208,  3208,
    3208,  3208,  3208,  3208,  3208,  3208,  3208,  3208,  3208,  3208,
    3208,  3208,  3208, -1108, -1108,  1224,  -100,  4061,  5520,   504,
     754,  3135, -1108, -1108,  2496, -1108,   208,  5541,  5562,  3208,
    5583,   576,  5604,  5625,  3208,   608,  5646,  5667,  2256,  1542,
    2530,   893, -1108,  3208,  3208,  3208,  3208, -1108, -1108,   912,
     913,   913,  3208,   782,   797,   801,   803,  3208,  3208,  3208,
     795,   935,   799,   -54, -1108, -1108,  4087,  4113,   274,   274,
     214,   214,    64,  3208,  3208,  3208,  2995,  2995,  3208,  2984,
     187, -1108,  3208,  3208,  3208,  3208,   940,   941,  3208,   943,
   -1108,  3208,  3208,   796, -1108,  3135,  3208,  3208, -1108,  5688,
    5709,  5730,   854,  4139, -1108,   804,  2602,  5751,  4786, -1108,
   -1108,  1164, -1108,  1722,   616,   809, -1108,   812,   813,   815,
    3208,  4809,   -21,  3208,    17, -1108,  5772,  4832,  5793,  4855,
    5814,  4878,  5835,  4901,  5856,  4924,  5877,  4947,  5898,  4970,
    5919,  4993,  5940,  5016,  5961,  5039,  5982,  5062,  4165,  4191,
    6003,  5085,  6024,  5108,  6045,  5131,  6066,  5154,  6087,  5177,
    6108,  5200,  4217,  4243,  4269,  4295,  4321,  4347,   -82,   806,
     817,   818,  1243,   814,  3208, -1108,  2116,  2116,   613,   321,
     495,  3208,   952,   960,    21,   821, -1108,    53,   -46,   -39,
      71, -1108, -1108,  2670,   800,   781,   618,   618,   491,   491,
     491,   491,   542,   542,   740,   740,   740,   740, -1108,    42,
    3135,  3208,   961,  2956,  3208,   740, -1108,  3208,  3135,  3135,
     870,   963,   964,  6129,   965,   875,   966,   970,  6150,   880,
     974,   976,  3135, -1108,   632,  2396,  3208,  6171,  3060,  6192,
    6213,  3208,  2116,   980,   979,  6234,  3269,  3269,  3269,  3269,
    6255,  6276,  6297,   842, -1108,  2116,   274,  3208,  3208, -1108,
   -1108,   839,   840,  3208,  4373,  4399,  4425,  4035,   489,   274,
    1872,  6318,  3201,  6339,  6360,  3208,   986,  3208,  6381, -1108,
    5223,  5246, -1108,   633,  5269,  5292,   988,   989,   990,   853,
    3208,  2012,  3208,  3208, -1108,    34, -1108, -1108,  3208,   995,
     994,   996,   997,   999,  5315,    46, -1108,  3235, -1108,   861,
     866,   862, -1108,  1006, -1108, -1108, -1108, -1108, -1108, -1108,
   -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108,
   -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108,
   -1108,  3208,  3208, -1108, -1108, -1108, -1108, -1108, -1108, -1108,
   -1108, -1108, -1108, -1108, -1108,  3208,  3208,  3208,  3208,  3208,
    3208, -1108,  3135,   466, -1108, -1108, -1108,  3208,  5338,  1007,
    1008,   871, -1108,    23,  3208,  1010,  1011,  1504, -1108,  1013,
     879,    20,  1012, -1108,  3135,  3135,  3135,  3135,  3208, -1108,
     896,   466,   184,  4451,   274, -1108,  3135,  3372,  2742,   740,
   -1108,  2496, -1108,   973,  2116,  2116,  1019,  2116,   732,  2116,
    2116,  1020,   977,  2116,  2116,   638, -1108,  3135,  1615,  1023,
    1025,  1026,  1027,  2988, -1108, -1108,  1029, -1108,  1030,   894,
    6612, -1108,   897,   898,   899,  1031,  1035,  1040,  1047,   905,
     222,  4477,  4503, -1108, -1108,  3475,   274,   274,   274,  1048,
     908,   916,   -24, -1108,   243, -1108,   489,  1046,  1052,  1053,
    1054,  6612, -1108,  1904,   911,  1057,  1059,  1014,  1061,  1062,
    2116,  2116,  2116,  1065,  4529, -1108,  2776,   958,  1066,  1067,
    5361, -1108,   924,   925,   926,   927,  1071,  1074, -1108,  1090,
   -1108,   962,  3208,  3208,  2116,   951, -1108,  6402,  5384,  6423,
    5407,  6444,  5430,  6465,  5453,   190,   959,  6486,   490, -1108,
   -1108,    15,   202,   957,  1097,  2044, -1108, -1108, -1108,    20,
    3208, -1108,   646, -1108,   651,   652,   655,   656,  6612, -1108,
    1099,    50,  3208,    51,   663, -1108,  3208,   968,  1050,  1050,
    2116,  1101,   969,   971,  1104,  1106,  2116,   975,  1107,  1108,
   -1108,   664, -1108,  1113,  2116,  2116,  2116,  1117,  1116, -1108,
    2116,  1120,  1122,  1123,  1124,  2116,  2116,  2116,   186,  1127,
    3208,  3208,  3208,   985,   -51,   -18,    68, -1108,  2116,  3208,
   -1108, -1108,  2995,    -7,  1976, -1108,   987,  2536, -1108,  3135,
   -1108, -1108,   991, -1108, -1108,  1128,  1130,  1042, -1108,  3208,
    3208,  3208, -1108,  1132,  1134,  1000,  2116,  2116,  2116,  2116,
   -1108,   -21, -1108,  3208,  4555,  4581,   667, -1108,  3208, -1108,
   -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108,
    2116,   495,  3208,  1140,  1143,    21, -1108,  1146,  5476,    20,
   -1108,  1149,  1151,  1153,  1155, -1108, -1108,   466,  4607, -1108,
    1005,  6612,  3208,   274,  1156,  1157,  1158, -1108,  3208,  3208,
   -1108, -1108,  1159,  3208, -1108, -1108, -1108,  1162,  1163,  1165,
    1069,  3208, -1108,  1167,  2116,  2116,  2116,  2116,  1168,  1171,
    1172, -1108,  3269,  1037,  3503,  6507,  1764,   214,   274,  1174,
     274,  1175,   274,  1178,   582,  1038,  6528,  3531,   285, -1108,
    1180,  1377,  1181,   274,  1377,  1182,   671,  3208, -1108, -1108,
    2116,  2809,   643,  6549, -1108,  2816,  1186,  1044,  1045,  1049,
    1055, -1108,   197,  6612,  3208,  3208,  2116,  1056,   674,  6612,
    1187,  1188,  2184, -1108,  1190,  1194, -1108,  1058, -1108, -1108,
   -1108, -1108, -1108,  1195,  3208, -1108,  3559,   102, -1108, -1108,
   -1108,  3587,  3615, -1108,  3643,  1201, -1108, -1108,  1170,  1202,
    6612, -1108,  1203,  1216,  1223,  1227, -1108,  1086,  1229, -1108,
    2324,  1231,  1234,  1093, -1108,  3208, -1108,  1094,   316, -1108,
    1096,   325, -1108,  1103,   350, -1108,  1105,  1239,  2116,  1200,
    1110,  3208, -1108,  2676,   352, -1108,   362,   380, -1108,  1241,
    3671,  1160,  3208, -1108,  3208, -1108, -1108,  3135,  2356,  1253,
   -1108,  2116,  2116,  2116,  2116, -1108,  3208,  4633,  4659, -1108,
    2116,  3208,  1254, -1108, -1108, -1108,    20, -1108,  1169, -1108,
    4685,  1256,  1257,  1259,  1261,  1262,  1121, -1108, -1108, -1108,
   -1108, -1108,  2116, -1108, -1108, -1108, -1108,   214,  3128, -1108,
    2995,   489,  2995,   489,  2995,   489, -1108,   678,  2116, -1108,
    3699,   274,  3135,   274, -1108, -1108,  3208,  3727,  3755,   679,
   -1108, -1108,  1125,  1126,  1135,  1136,  1131,  6612,  3208,  3208,
     682,  6612, -1108,  1264, -1108,  3208, -1108, -1108, -1108, -1108,
   -1108,  3208,   683,  1154,  3208, -1108,  3783,   411,   144,  3811,
     416,   149,  3839,   437,   253,  2116,  1265,  1207,  2152,  1133,
     461,   686,   474,  2389, -1108, -1108,  1267,  1270,  1296,  1298,
    1299,  3208,  6570,  4711,    25, -1108,  4737,  3867,  1304, -1108,
    3895,  1303,  3208,  1305,  1306,  3208,  1308,  1323,  3208,  1324,
    1161, -1108,  3208, -1108,   489, -1108,  3135,  1325,  2676, -1108,
   -1108, -1108, -1108, -1108, -1108,   690, -1108,  3208, -1108,  2116,
    3208, -1108, -1108,  1326, -1108, -1108,  1189,  3923, -1108, -1108,
    1191,  3951, -1108, -1108,  1192,  3979, -1108,  1328,  2464,   269,
    2292,   705, -1108,   486,   718,  1329,  1213,  6591,   719,  4007,
   -1108,   489,  1330,   489,  1332,   489,  1335, -1108, -1108, -1108,
   -1108,   489,  1336,  3135,  1356, -1108,   466, -1108,  1236,  1373,
     289, -1108,  1237,   315, -1108,  1242,   331, -1108,  1266,   367,
   -1108,   724, -1108,   743, -1108,  1268,  2116, -1108,  1376,   489,
    1383,   489,  1406,   489, -1108,  1409,   466,  1411,   466,   748,
   -1108,   370, -1108,   379, -1108,   392, -1108, -1108, -1108,   749,
   -1108,  1412,  1414,  1415,  1416,   466,  1418, -1108, -1108, -1108,
   -1108, -1108, -1108
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1108, -1108, -1108, -1108,   584, -1108, -1108, -1108, -1108,   195,
   -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108, -1108,
   -1108, -1108,  -292,    -3, -1108,    80, -1108,   581,  1428, -1108,
   -1108, -1108, -1108,     3,  -367,  -193, -1108, -1108, -1108, -1108,
   -1108, -1108,  1429, -1108, -1108, -1108, -1108, -1108, -1108, -1108,
   -1108, -1108, -1108, -1108, -1108, -1108,  -728,  -719,   196, -1108,
   -1108,  1075, -1108, -1108, -1108, -1108, -1108,    -6, -1108,   -20,
   -1108, -1107,   563,  -103,   349,  -108,  -671,   492, -1108,  -222,
      -2
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     140,   225,   389,   139,   142,   491,    74,   146,   427,   428,
     429,   227,   403,   571,   572,   203,   188,   190,   297,   196,
     831,   618,   682,  1190,   215,   690,   233,   822,   155,   155,
     206,  1268,   207,   421,   160,   423,   160,   399,   893,   400,
     218,   788,   519,   891,   336,  1202,     4,   520,   699,   341,
     424,   239,   759,   345,   378,   379,   956,   959,   760,   761,
     671,   478,   479,   480,   481,   672,   197,   360,   361,   759,
       5,   380,   486,   378,   379,   760,   761,   378,   379,   151,
     378,   379,   114,   115,   116,   117,   152,   240,   118,   143,
     381,   490,   145,   566,   156,   156,   998,   396,   999,   378,
     379,   157,   695,   619,   620,   621,   622,   161,   144,   696,
     298,   299,   198,   378,   379,   204,   391,   131,   132,   823,
     824,   199,   290,   291,   292,   890,   148,   293,   296,  1000,
     392,  1001,   305,   124,   125,   126,   127,   393,   325,   149,
     302,   327,  1009,   150,   226,   328,   334,   337,   338,   147,
     340,   334,   342,   343,   228,   334,   346,   347,   947,   205,
     131,   132,  1298,   373,   374,   234,   623,   235,   216,   691,
     700,   382,   236,  1269,   891,   390,   401,   219,   700,   789,
     376,   377,   378,   379,   131,   132,   487,   488,   241,   377,
     242,   797,   991,   992,   151,   378,   379,   684,   580,   378,
     379,   694,   124,   125,   126,   127,   409,   410,   411,   941,
     413,   573,   163,   416,   417,  1002,   418,  1003,   301,   697,
     759,   601,   131,   132,   153,   759,   760,   761,   431,  1349,
     154,   760,   761,   378,   379,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   169,  1048,   158,
     170,   482,   171,    35,    36,    37,    38,   159,   243,   334,
     244,   162,    43,  1243,   492,    46,   177,   593,  1246,   178,
     163,   179,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   164,   378,   379,
     124,   125,   126,   127,   192,   525,   841,   193,   682,   759,
     194,   529,   937,   533,   579,   760,   761,   529,   538,  1125,
     131,   132,   525,   334,  1126,   759,   165,   547,   548,   549,
     550,   760,   761,   378,   379,   529,   555,   530,   569,   570,
     166,   560,   561,   562,   167,   759,   374,   172,   245,   880,
     246,   760,   761,   180,   378,   379,   168,   574,   575,   576,
     290,   291,   577,   302,   302,   181,   581,   582,   583,   584,
     892,   759,   588,   799,   183,   590,   591,   760,   761,   334,
     594,   595,  1249,   182,   191,   184,   185,   759,   200,   184,
     185,   201,   702,   760,   761,   186,   378,   379,  1309,   186,
     202,   247,   187,   248,   614,   208,   195,   617,   249,   616,
     250,   209,  1101,  1208,   725,  1211,   210,  1214,  1338,   124,
     125,   126,   127,   759,   211,   212,   759,   378,   379,   760,
     761,   816,   760,   761,   221,   759,   378,   379,   213,   131,
     132,   760,   761,  1160,  1340,  1193,   683,   251,   759,   252,
     424,   239,  1162,   214,   760,   761,   220,   222,   678,   840,
    1342,   378,   379,   378,   379,   687,   685,   223,   686,   891,
     238,   224,   891,   378,   379,   891,   253,  1164,   254,  1171,
     239,   335,   114,   115,   116,   117,   335,   229,   118,  1172,
     335,   378,   379,   230,   334,   703,  1344,   678,   707,  1362,
     287,   708,   709,   711,   231,   232,  1289,  1173,  1363,   940,
     942,   114,   115,   116,   117,   283,   334,   118,   284,   709,
     728,  1364,   378,   379,   285,   733,   750,   378,   379,   286,
     740,   740,   740,   740,   741,   741,   741,   741,  1242,   764,
     288,   751,   752,  1245,   815,   759,   300,   755,   378,   379,
     891,   760,   761,  1320,   255,  1323,   256,  1326,   306,   771,
     257,   773,   258,  1329,  1248,   323,   834,   835,   836,   837,
     527,   324,   378,   379,   784,   326,   786,   787,   844,   339,
     344,   891,   790,   353,   891,   378,   379,   891,  1256,   355,
     891,  1351,   798,  1353,   259,  1355,   260,   378,   379,   861,
     354,  1258,   317,   318,   319,   320,   321,   370,   131,   132,
    1087,   322,   891,  1313,   891,   797,   891,   742,   743,   744,
     356,   362,   131,   132,   335,   807,   808,   523,   367,   235,
     173,  1114,   137,   174,   236,   261,   175,   262,   176,   809,
     810,   811,   812,   813,   814,   368,   334,   131,   132,   369,
     372,   817,   484,   383,   235,   319,   320,   321,   825,   236,
     526,   263,   322,   264,   843,   265,   384,   266,   334,   334,
     334,   334,   838,   267,   269,   268,   270,   526,   335,   271,
     334,   272,   385,   402,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   545,   320,   321,   273,   394,
     274,   334,   322,   529,   275,   535,   276,   351,   277,   395,
     278,  1097,   358,   358,   358,  1053,   884,   885,   886,   279,
     281,   280,   282,   398,   371,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   335,   529,   404,   539,   322,   608,
     529,   609,   681,   358,   397,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   529,
     529,   726,   777,   322,   852,   529,   853,   860,   405,   408,
    1203,  1016,  1115,   949,   412,   950,   924,   925,   529,   529,
     951,   952,   529,   529,   953,   954,   414,   415,     7,     8,
     529,   529,   960,   976,  1036,   798,  1037,   419,   529,   943,
    1109,  1131,   420,  1132,   948,  1215,   529,  1216,  1226,  1036,
    1036,  1234,  1238,   529,   406,  1257,   958,  1131,   407,  1295,
     961,   422,   497,    15,    16,   498,    18,    19,   499,    21,
     500,    23,   529,    24,  1312,    26,    27,   430,    29,    30,
      31,   432,   435,    33,    34,   529,  1036,  1314,  1318,   335,
     433,   529,  1008,  1345,   994,   995,   996,   710,   712,   483,
     322,   493,  1004,  1006,   494,   495,  1007,    50,    51,    52,
    1346,   335,  1347,   334,   710,  1036,  1365,  1361,  1366,   137,
     546,   496,   524,  1021,  1022,  1023,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,  1033,  1031,   551,
     552,   322,  1039,   556,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,  1042,   563,   557,  1041,
     322,   564,   558,  1057,   559,   592,   565,   585,   587,   589,
     599,   610,   602,   673,   611,   612,  1056,   613,   688,   674,
     675,   677,  1061,  1062,   689,   693,   911,  1064,   704,   713,
     714,   715,   717,   719,   718,  1070,  1218,   720,  1088,   722,
    1091,   723,  1094,   724,   735,   737,  1080,   748,   753,   754,
    1081,  1104,   772,  1106,  1107,   780,   781,   782,   783,   791,
     302,   792,   802,   793,   794,   334,   795,   803,   334,  1179,
     804,  1110,   806,   819,   820,   821,   826,   827,   833,  1118,
     829,   335,   830,  1119,   839,   847,   850,   856,  1127,  1128,
     863,   857,   864,   865,   866,   869,   871,   870,   875,   872,
     873,   874,   876,   335,   335,   335,   335,   877,  1140,   679,
     680,   878,   879,   894,   887,   335,   888,   889,   895,   899,
     896,   897,  1290,   900,  1221,   901,   902,   903,   904,   908,
     913,   914,   916,   917,   918,   919,   335,   920,   921,  1158,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,  1334,  1170,   922,   525,   322,   928,
     912,   938,   944,   923,   945,   955,  1177,   967,  1178,   963,
     970,   334,   971,   974,   975,   734,   962,   968,   977,   969,
    1187,   981,   982,   973,  1357,  1191,  1360,   984,   749,   985,
     986,   987,   993,   997,  1018,  1013,  1019,  1020,  1024,  1017,
    1207,  1025,  1210,  1371,  1213,  1026,  1043,  1044,  1291,  1055,
    1294,  1220,  1046,  1222,  1206,  1049,  1209,  1050,  1212,  1051,
     302,  1052,  1058,  1059,  1060,  1063,   334,  1065,  1068,  1066,
    1223,  1067,   307,  1071,  1076,  1077,     7,     8,  1079,  1082,
    1089,  1092,  1232,  1233,  1095,  1098,  1102,  1105,  1108,  1236,
    1120,  1121,  1122,  1133,  1134,  1237,  1123,  1136,  1240,   502,
    1137,  1139,  1124,  1138,  1130,  1331,  1145,  1168,  1147,  1148,
     497,    15,    16,   498,    18,    19,   499,    21,   500,    23,
    1146,    24,  1149,    26,    27,  1039,    29,    30,    31,  1150,
     518,    33,    34,  1151,  1152,  1153,  1277,  1155,  1293,  1281,
    1156,  1157,  1285,  1159,  1161,  1166,  1288,  1174,   335,   676,
     334,  1163,   334,  1165,  1176,    50,    51,    52,  1169,  1181,
    1192,  1297,  1196,  1197,  1299,  1198,  1194,  1199,  1200,  1201,
    1235,  1251,  1252,  1260,  1227,  1228,  1261,   848,   849,  1231,
     851,  1255,   854,   855,  1229,  1230,   858,   859,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,  1262,  1239,  1263,  1264,   322,   334,  1272,  1275,
    1287,  1278,  1279,   606,  1282,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,  1283,
    1286,  1292,  1300,   322,  1307,  1315,  1321,  1301,  1324,  1303,
    1305,  1327,  1330,   905,   906,   907,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     335,  1316,  1332,   335,   322,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,  1337,
      86,   329,  1350,   322,  1336,  1339,    90,    91,    92,  1352,
    1341,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,  1354,   966,  1343,  1356,  1348,  1358,  1367,   972,
    1368,  1369,  1370,   330,  1372,   957,  1265,   978,   979,   980,
     965,    73,    81,   983,  1273,     0,   554,  1045,   988,   989,
     990,     0,     0,     0,     0,     0,    35,    36,    37,    38,
      39,  1005,   526,     0,     0,    43,     0,  1012,    46,     0,
    1015,     0,     0,     0,     0,     0,   335,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1027,
    1028,  1029,  1030,     0,     0,     0,     0,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1040,     0,     0,     0,     0,   386,  1103,
     828,     0,     0,   130,     0,     0,     0,     0,   388,     0,
       0,   335,     0,   136,     0,   187,   543,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,   329,  1072,  1073,  1074,
    1075,    90,    91,    92,     0,     0,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,     0,     0,     0,
       0,     0,     0,  1111,     0,     0,     0,     0,   330,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1129,
       0,     0,     0,     0,     0,   335,     0,   335,     0,     0,
       0,    35,    36,    37,    38,    39,     0,     0,     0,     0,
      43,   862,     0,    46,     0,     0,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,     0,     0,     0,     0,     0,
       0,     0,   120,   121,   122,   123,     0,     0,     0,     0,
       0,  1167,   335,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,   331,     0,     0,     0,   130,     0,
       0,     0,     0,   133,  1182,  1183,  1184,  1185,   136,     0,
       0,   543,     0,    86,    87,    88,     0,    89,     0,    90,
      91,    92,     0,     0,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,     0,   114,   115,   116,   117,
       0,  1217,   118,     0,     7,     8,     0,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   497,    15,
      16,   498,    18,    19,   499,    21,   500,    23,  1250,    24,
       0,    26,    27,     0,    29,    30,    31,     0,     0,    33,
      34,     0,     0,     0,   119,     0,     0,     0,     0,     0,
     120,   121,   122,   123,     0,     0,     0,     0,   124,   125,
     126,   127,     0,    50,    51,    52,     0,     0,     0,     0,
       0,   128,   129,     0,     0,     0,   130,     0,   131,   132,
       0,   133,     0,   134,     0,   135,   136,     0,   137,    86,
     329,   357,     0,     0,     0,    90,    91,    92,     0,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   607,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   330,     0,     7,     8,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,    35,    36,    37,    38,    39,
     898,  1085,     0,  1086,    43,     0,     0,    46,   497,    15,
      16,   498,    18,    19,   499,    21,   500,    23,     0,    24,
       0,    26,    27,     0,    29,    30,    31,     0,     0,    33,
      34,     0,     0,     0,     0,     0,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,     0,   128,   348,     0,
       0,     0,   130,     0,     0,     0,     0,   133,     0,    86,
     329,  1010,   136,     0,   349,    90,    91,    92,     0,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   765,   330,     0,     7,     8,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,    35,    36,    37,    38,    39,
     946,     0,     0,     0,    43,     0,     0,    46,   497,    15,
      16,   498,    18,    19,   499,    21,   500,    23,     0,    24,
       0,    26,    27,     0,    29,    30,    31,     0,     0,    33,
      34,     0,     0,     0,     0,     0,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,     0,   128,   348,     0,
       0,     0,   130,     0,     0,     0,     0,   133,     0,    86,
     329,     0,   136,     0,  1011,    90,    91,    92,     0,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   785,   330,     0,     7,     8,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,    35,    36,    37,    38,    39,
    1135,     0,     0,     0,    43,     0,     0,    46,   497,    15,
      16,   498,    18,    19,   499,    21,   500,    23,     0,    24,
       0,    26,    27,     0,    29,    30,    31,     0,     0,    33,
      34,     0,     0,     0,     0,     0,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,     0,   128,   348,     0,
       0,     0,   130,     0,     0,     0,     0,   133,     0,    86,
     329,     0,   136,     0,   349,    90,    91,    92,     0,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1253,   330,     0,     7,     8,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,    35,    36,    37,    38,    39,
    1154,     0,     0,     0,    43,     0,     0,    46,   497,    15,
      16,   498,    18,    19,   499,    21,   500,    23,     0,    24,
       0,    26,    27,     0,    29,    30,    31,     0,     0,    33,
      34,     0,  1180,     0,     0,     0,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,     0,   128,   331,     0,
       0,     0,   130,     0,     0,  1259,     0,   133,     0,    86,
     329,     0,   136,     0,   542,    90,    91,    92,     0,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1310,   330,     0,     0,     0,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,    35,    36,    37,    38,    39,
    1308,     0,     0,     0,    43,     0,     0,    46,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,     0,     0,     0,     0,   322,     0,     0,     0,
       0,     0,     0,     0,   527,     0,   120,   121,   122,   123,
       0,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,   128,   331,   322,
       0,     0,   130,     0,     0,     0,     0,   133,   527,    86,
     329,     0,   136,     0,   727,    90,    91,    92,     0,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   330,     0,     0,     0,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,    35,    36,    37,    38,    39,
     603,     0,     0,     0,    43,     0,     0,    46,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   528,
     320,   321,     0,     0,     0,     0,   322,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,   121,   122,   123,
       0,     0,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   545,   320,   321,     0,   128,   348,     0,
     322,     0,   130,     0,     0,     0,     0,   133,   698,    86,
     329,     0,   136,     0,  1014,    90,    91,    92,     0,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   330,     0,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,     0,     0,
       0,     0,   322,     0,     0,    35,    36,    37,    38,    39,
     846,     0,    86,   289,    43,     0,     0,    46,    90,    91,
      92,     0,     0,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   910,     0,   120,   121,   122,   123,
       0,     0,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,     0,   386,  1103,     0,
     322,     0,   130,     0,     0,     0,     0,   388,     0,    86,
     289,   239,   136,     0,   187,    90,    91,    92,     0,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,   114,   115,   116,   117,     0,     0,   118,   120,
     121,   122,   123,     0,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,     0,     0,
     128,   129,   322,     0,     0,   130,     0,     0,     0,     0,
     133,     0,     0,   294,     0,   136,     0,   295,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,     0,     0,     0,     0,   322,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,   121,   122,   123,
       0,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,   128,   129,   322,
       0,     0,   130,     0,     0,     0,  1112,   133,  1113,    86,
     289,     0,   136,     0,  1117,    90,    91,    92,     0,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     7,     8,    86,   289,
       0,     0,     0,     0,    90,    91,    92,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     497,    15,    16,   498,    18,    19,   499,    21,   500,    23,
       0,    24,     0,    26,    27,     0,    29,    30,    31,     0,
       0,    33,    34,   867,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,   121,   122,   123,
       0,     0,     0,     0,     0,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,   129,     0,
       0,     0,   130,     0,     0,     0,     0,   133,     0,     0,
     705,     0,   136,     0,   706,   120,   121,   122,   123,     0,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,     0,     0,   386,   387,   322,     0,
       0,   130,     0,     0,     0,     0,   388,     0,    86,   329,
       0,   136,     0,   187,    90,    91,    92,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   330,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,     0,     0,     0,     0,
     322,     0,     0,     0,    35,    36,    37,    38,    39,   730,
       0,    86,   289,    43,     0,     0,    46,    90,    91,    92,
       0,     0,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,     0,     0,   120,   121,   122,   123,     0,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,     0,     0,   128,   331,   322,     0,
       0,   130,    86,   289,   239,  1204,   133,  1205,    90,    91,
      92,   136,     0,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     0,   114,   115,   116,   117,     0,
       0,   118,     0,     0,     0,     0,     0,     0,   120,   121,
     122,   123,     0,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,   128,
     129,   322,     0,     0,   130,     0,     0,     0,     0,   133,
     768,     0,     0,     0,   136,     0,     0,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,    -4,     1,   322,     0,    -4,     0,   120,
     121,   122,   123,     0,   800,    -4,    -4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   129,     0,     0,     0,   130,     0,     0,    -4,     0,
     133,     0,     0,    -4,    -4,   136,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,     0,
       0,     0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,
       0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     6,     0,     0,     0,    -4,    -4,    -4,
      -4,     7,     8,     0,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,     0,     0,
       0,     0,   322,     0,     9,     0,     0,     0,     0,    10,
      11,   845,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,    43,    44,    45,
      46,     0,     0,    47,    48,     0,     0,     0,     0,    49,
      50,    51,    52,     0,     0,    53,     0,    54,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
       0,     0,     0,    65,    66,    67,    68,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,     0,     0,     0,
       0,     0,     0,     0,   883,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
       0,     0,  1083,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,     0,     0,
    1100,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,     0,     0,  1141,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,     0,
       0,     0,     0,     0,     0,     0,  1142,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,     0,     0,     0,
       0,     0,     0,     0,  1143,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
       0,     0,  1144,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,     0,     0,
    1175,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,     0,     0,  1219,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,     0,
       0,     0,     0,     0,     0,     0,  1224,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,     0,     0,     0,
       0,     0,     0,     0,  1225,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
       0,     0,  1241,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,     0,     0,
    1244,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,     0,     0,  1247,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,     0,
       0,     0,     0,     0,     0,     0,  1271,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,     0,     0,     0,
       0,     0,     0,     0,  1274,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
       0,     0,  1302,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,     0,     0,
    1304,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,     0,     0,  1306,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,     0,
       0,     0,     0,     0,     0,     0,  1319,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,   485,     0,     0,
       0,     0,   567,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,   521,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,     0,
       0,     0,     0,     0,   567,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
     568,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,   600,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,     0,     0,     0,
       0,     0,   651,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,   652,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,     0,
       0,     0,     0,     0,   665,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
     666,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,   667,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,     0,     0,     0,
       0,     0,   668,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,   669,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,     0,
       0,     0,     0,     0,   670,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
     756,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,   757,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,     0,     0,     0,
       0,     0,   758,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,   842,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,     0,
       0,     0,     0,     0,   881,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
     882,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,   909,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,     0,     0,     0,
       0,     0,  1034,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,  1035,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,     0,
       0,     0,     0,     0,  1054,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
    1188,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,  1189,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,     0,     0,     0,
       0,     0,  1195,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,  1267,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,     0,
       0,     0,     0,     0,  1270,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,     0,     0,   489,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,     0,     0,     0,     0,   322,     0,     0,     0,
     605,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,     0,     0,   615,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,     0,     0,
       0,     0,   322,     0,     0,     0,   630,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,     0,     0,   632,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,     0,     0,     0,     0,   322,     0,
       0,     0,   634,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,     0,     0,   636,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,     0,     0,     0,   638,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,     0,
       0,   640,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,     0,     0,     0,     0,
     322,     0,     0,     0,   642,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,     0,     0,   644,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,     0,     0,     0,     0,   322,     0,     0,     0,
     646,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,     0,     0,   648,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,     0,     0,
       0,     0,   322,     0,     0,     0,   650,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,     0,     0,   654,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,     0,     0,     0,     0,   322,     0,
       0,     0,   656,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,     0,     0,   658,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,     0,     0,     0,   660,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,     0,
       0,   662,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,     0,     0,     0,     0,
     322,     0,     0,     0,   664,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,     0,     0,   775,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,     0,     0,     0,     0,   322,     0,     0,     0,
     776,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,     0,     0,   778,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,     0,     0,
       0,     0,   322,     0,     0,     0,   779,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,     0,     0,   796,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,     0,     0,     0,     0,   322,     0,
       0,     0,   818,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,     0,     0,   915,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,     0,     0,     0,   930,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,     0,
       0,   932,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,     0,     0,     0,     0,
     322,     0,     0,     0,   934,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,     0,     0,   936,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,     0,     0,     0,     0,   322,     0,     0,     0,
    1047,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,   485,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,     0,     0,     0,     0,
     322,     0,   522,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,   531,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,     0,     0,
       0,     0,   322,     0,   532,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,   534,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,     0,   536,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,   537,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,     0,     0,     0,     0,   322,     0,   540,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,   541,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,     0,     0,     0,     0,   322,     0,
     596,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,   597,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,     0,     0,     0,     0,
     322,     0,   598,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,   604,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,     0,     0,
       0,     0,   322,     0,   629,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,   631,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,     0,   633,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,   635,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,     0,     0,     0,     0,   322,     0,   637,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,   639,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,     0,     0,     0,     0,   322,     0,
     641,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,   643,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,     0,     0,     0,     0,
     322,     0,   645,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,   647,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,     0,     0,
       0,     0,   322,     0,   649,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,   653,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,     0,   655,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,   657,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,     0,     0,     0,     0,   322,     0,   659,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,   661,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,     0,     0,     0,     0,   322,     0,
     663,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,   716,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,     0,     0,     0,     0,
     322,     0,   721,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,   729,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,     0,     0,
       0,     0,   322,     0,   731,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,   732,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,     0,   738,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,   745,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,     0,     0,     0,     0,   322,     0,   746,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,   747,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,     0,     0,     0,     0,   322,     0,
     767,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,   769,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,     0,     0,     0,     0,
     322,     0,   770,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,   774,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,     0,     0,
       0,     0,   322,     0,   929,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,   322,     0,   931,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
       0,     0,     0,     0,   322,     0,   933,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,     0,     0,     0,     0,   322,     0,   935,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,     0,     0,     0,     0,   322,     0,   939,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,     0,     0,     0,     0,   322,     0,  1084,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,     0,     0,     0,     0,   322,     0,
    1099,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,     0,     0,     0,     0,   322,
       0,  1116,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,     0,     0,     0,     0,
     322,     0,  1266,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,     0,     0,
       0,   322,     0,  1317,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,     0,     0,
       0,     0,   322
};

static const yytype_int16 yycheck[] =
{
       6,     5,   195,     6,     6,   297,     3,     6,   230,   231,
     232,     5,   205,   380,   381,     4,    36,    37,     4,    39,
     691,     4,     7,  1130,     4,     4,     4,     4,    75,    75,
       4,     6,     6,   226,    75,   228,    75,     4,   766,     6,
       4,     7,   142,   762,   152,  1152,     6,   147,     6,   157,
       4,     5,    76,   161,   131,   132,     6,     6,    82,    83,
     142,   283,   284,   285,   286,   147,     4,   170,   171,    76,
       0,   148,     7,   131,   132,    82,    83,   131,   132,   141,
     131,   132,    36,    37,    38,    39,   148,    89,    42,    13,
     148,     7,   141,   147,   141,   141,   147,   200,   149,   131,
     132,   148,   148,    86,    87,    88,    89,   148,    52,   148,
      96,    97,    50,   131,   132,   104,   148,   138,   139,    96,
      97,    59,   128,   129,   130,   149,     6,   133,   134,   147,
     141,   149,   138,   118,   119,   120,   121,   148,   144,     6,
     137,   147,   149,     6,   148,   151,   152,   153,   154,   148,
     156,   157,   158,   159,   148,   161,   162,   163,   829,   148,
     138,   139,  1269,   183,   184,   143,   149,   145,   148,   148,
     128,   191,   150,   148,   893,   195,   143,   141,   128,   145,
     186,   187,   131,   132,   138,   139,   121,   295,   141,   195,
     143,   145,     6,     7,   141,   131,   132,   489,   391,   131,
     132,   148,   118,   119,   120,   121,   212,   213,   214,     7,
     216,   147,   141,   219,   220,   147,   222,   149,     4,   148,
      76,   414,   138,   139,   141,    76,    82,    83,   234,  1336,
     141,    82,    83,   131,   132,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,    49,   949,   141,
      52,   287,    54,    69,    70,    71,    72,   141,   141,   295,
     143,   141,    78,   149,   297,    81,    49,   405,   149,    52,
     141,    54,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,    56,   131,   132,
     118,   119,   120,   121,    46,   331,   142,    49,     7,    76,
      52,   147,   142,   339,   147,    82,    83,   147,   344,   142,
     138,   139,   348,   349,   147,    76,    52,   353,   354,   355,
     356,    82,    83,   131,   132,   147,   362,   149,   378,   379,
      52,   367,   368,   369,    52,    76,   386,    54,   141,   147,
     143,    82,    83,   141,   131,   132,    52,   383,   384,   385,
     386,   387,   388,   380,   381,    49,   392,   393,   394,   395,
     147,    76,   398,   615,   148,   401,   402,    82,    83,   405,
     406,   407,   149,   141,   148,   131,   132,    76,    52,   131,
     132,    52,   520,    82,    83,   141,   131,   132,   149,   141,
      49,   141,   148,   143,   430,    49,   148,   433,   141,   432,
     143,     4,   147,  1161,   542,  1163,     4,  1165,   149,   118,
     119,   120,   121,    76,     4,   141,    76,   131,   132,    82,
      83,   673,    82,    83,     6,    76,   131,   132,   141,   138,
     139,    82,    83,   147,   149,  1136,   145,   141,    76,   143,
       4,     5,   147,   141,    82,    83,   141,   143,   484,   701,
     149,   131,   132,   131,   132,   491,   489,     4,   490,  1208,
     148,     4,  1211,   131,   132,  1214,   141,   147,   143,   147,
       5,   152,    36,    37,    38,    39,   157,   141,    42,   147,
     161,   131,   132,   141,   520,   521,   149,   523,   524,   149,
       7,   527,   528,   529,   141,   141,  1254,   147,   149,   821,
     822,    36,    37,    38,    39,   141,   542,    42,   141,   545,
     546,   149,   131,   132,   141,   551,   566,   131,   132,   141,
     556,   557,   558,   559,   556,   557,   558,   559,   147,   579,
     141,   567,   568,   147,   672,    76,     4,   573,   131,   132,
    1289,    82,    83,  1301,   141,  1303,   143,  1305,     6,   585,
     141,   587,   143,  1311,   147,     6,   694,   695,   696,   697,
       8,     6,   131,   132,   600,     5,   602,   603,   706,   141,
     141,  1320,   608,   141,  1323,   131,   132,  1326,   147,   141,
    1329,  1339,   615,  1341,   141,  1343,   143,   131,   132,   727,
     148,   147,   131,   132,   133,   134,   135,     4,   138,   139,
     997,   140,  1351,   147,  1353,   145,  1355,   557,   558,   559,
     141,   141,   138,   139,   295,   651,   652,   143,   141,   145,
      46,     8,   148,    49,   150,   141,    52,   143,    54,   665,
     666,   667,   668,   669,   670,   141,   672,   138,   139,   141,
       5,   677,   143,   148,   145,   133,   134,   135,   684,   150,
     331,   141,   140,   143,   704,   141,   148,   143,   694,   695,
     696,   697,   698,   141,   141,   143,   143,   348,   349,   141,
     706,   143,   148,   143,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   141,   141,
     143,   727,   140,   147,   141,   149,   143,   164,   141,   141,
     143,   149,   169,   170,   171,   957,   756,   757,   758,   141,
     141,   143,   143,   141,   181,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   405,   147,     6,   149,   140,   143,
     147,   145,   149,   200,   201,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   147,
     147,   149,   149,   140,    52,   147,    54,   149,   148,     6,
    1157,   899,   149,   147,   145,   149,   802,   803,   147,   147,
     149,   149,   147,   147,   149,   149,   148,    99,    12,    13,
     147,   147,   149,   149,   147,   818,   149,     6,   147,   822,
     149,   147,     6,   149,   830,   147,   147,   149,   149,   147,
     147,   149,   149,   147,   143,   149,   842,   147,   143,   149,
     846,     6,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,   147,    57,   149,    59,    60,   143,    62,    63,
      64,     4,     6,    67,    68,   147,   147,   149,   149,   520,
     148,   147,   892,   149,   880,   881,   882,   528,   529,     5,
     140,   145,   888,   889,     7,   143,   892,    91,    92,    93,
     147,   542,   149,   899,   545,   147,   147,   149,   149,   148,
       7,   149,   148,   909,   910,   911,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   923,   921,     7,
       7,   140,   928,   141,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   942,   142,   141,   941,
     140,     6,   141,   963,   141,   149,   147,     7,     7,     6,
      96,   142,   148,   147,   142,   142,   962,   142,     6,   142,
     142,   147,   968,   969,     4,   144,     8,   973,     7,    99,
       7,     7,     7,     7,    99,   981,  1169,     7,   998,    99,
    1000,     7,  1002,     7,     4,     6,   992,   145,   149,   149,
     992,  1011,     6,  1013,  1014,     7,     7,     7,   145,     4,
     997,     7,   141,     7,     7,  1011,     7,   141,  1014,  1117,
     148,  1017,     6,     6,     6,   144,     6,     6,     6,  1025,
       7,   672,   143,  1025,   128,    52,     7,     7,  1034,  1035,
       7,    54,     7,     7,     7,     6,   142,     7,     7,   142,
     142,   142,     7,   694,   695,   696,   697,     7,  1054,   486,
     487,     4,   147,     7,     6,   706,   148,   141,     6,   148,
       7,     7,  1255,     6,  1172,     6,    52,     6,     6,     4,
       4,     4,   148,   148,   148,   148,   727,     6,     4,  1085,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,  1316,  1101,     6,  1103,   140,   148,
     142,   142,   145,   141,     7,     6,  1112,     6,  1114,    59,
       6,  1117,     6,     6,     6,   552,   148,   148,     5,   148,
    1126,     4,     6,   148,  1346,  1131,  1348,     7,   565,     7,
       7,     7,     5,   148,     6,   148,     6,    95,     6,   148,
    1160,     7,  1162,  1365,  1164,   145,     6,     4,  1256,   144,
    1258,  1171,     6,  1173,  1160,     6,  1162,     6,  1164,     6,
    1157,     6,     6,     6,     6,     6,  1172,     5,    99,     6,
    1176,     6,     6,     6,     6,     4,    12,    13,     6,   142,
       6,     6,  1188,  1189,     6,   147,     6,     6,     6,  1195,
       4,   147,   147,     6,     6,  1201,   147,     7,  1204,     6,
       6,     6,   147,   145,   148,  1313,     5,     7,     6,     6,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      50,    57,     6,    59,    60,  1231,    62,    63,    64,     6,
       6,    67,    68,     6,   148,     6,  1242,     6,  1258,  1245,
       6,   148,  1248,   149,   148,     6,  1252,     6,   899,     6,
    1256,   148,  1258,   148,    94,    91,    92,    93,   148,     6,
       6,  1267,     6,     6,  1270,     6,    97,     6,     6,   148,
       6,     6,    65,     6,   149,   149,     6,   714,   715,   148,
     717,   148,   719,   720,   149,   149,   723,   724,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     6,   149,     6,     6,   140,  1313,     4,     6,
     149,     6,     6,   149,     6,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     6,
       6,     6,     6,   140,     6,     6,     6,   148,     6,   148,
     148,     6,     6,   780,   781,   782,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
    1011,   148,     6,  1014,   140,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     6,
       3,     4,     6,   140,   148,   148,     9,    10,    11,     6,
     148,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     6,   850,   148,     6,   148,     6,     6,   856,
       6,     6,     6,    46,     6,   841,  1231,   864,   865,   866,
     849,     3,     3,   870,  1238,    -1,   361,   945,   875,   876,
     877,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,   888,  1103,    -1,    -1,    78,    -1,   894,    81,    -1,
     897,    -1,    -1,    -1,    -1,    -1,  1117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   916,
     917,   918,   919,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   940,    -1,    -1,    -1,    -1,   131,   132,
       6,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,    -1,
      -1,  1172,    -1,   146,    -1,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,   984,   985,   986,
     987,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,  1020,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1036,
      -1,    -1,    -1,    -1,    -1,  1256,    -1,  1258,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      78,     6,    -1,    81,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,  1098,  1313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,   141,  1121,  1122,  1123,  1124,   146,    -1,
      -1,   149,    -1,     3,     4,     5,    -1,     7,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,  1168,    42,    -1,    12,    13,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,  1215,    57,
      -1,    59,    60,    -1,    62,    63,    64,    -1,    -1,    67,
      68,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,    -1,    -1,    -1,    -1,   118,   119,
     120,   121,    -1,    91,    92,    93,    -1,    -1,    -1,    -1,
      -1,   131,   132,    -1,    -1,    -1,   136,    -1,   138,   139,
      -1,   141,    -1,   143,    -1,   145,   146,    -1,   148,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    12,    13,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    69,    70,    71,    72,    73,
       6,   147,    -1,   149,    78,    -1,    -1,    81,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      -1,    59,    60,    -1,    62,    63,    64,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    -1,   131,   132,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,   141,    -1,     3,
       4,     5,   146,    -1,   148,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,    46,    -1,    12,    13,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    69,    70,    71,    72,    73,
       6,    -1,    -1,    -1,    78,    -1,    -1,    81,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      -1,    59,    60,    -1,    62,    63,    64,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    -1,   131,   132,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,   141,    -1,     3,
       4,    -1,   146,    -1,   148,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,    46,    -1,    12,    13,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    69,    70,    71,    72,    73,
       6,    -1,    -1,    -1,    78,    -1,    -1,    81,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      -1,    59,    60,    -1,    62,    63,    64,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    -1,   131,   132,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,   141,    -1,     3,
       4,    -1,   146,    -1,   148,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,    46,    -1,    12,    13,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    69,    70,    71,    72,    73,
       6,    -1,    -1,    -1,    78,    -1,    -1,    81,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      -1,    59,    60,    -1,    62,    63,    64,    -1,    -1,    67,
      68,    -1,     6,    -1,    -1,    -1,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    -1,   131,   132,    -1,
      -1,    -1,   136,    -1,    -1,     6,    -1,   141,    -1,     3,
       4,    -1,   146,    -1,   148,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,    46,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    69,    70,    71,    72,    73,
       6,    -1,    -1,    -1,    78,    -1,    -1,    81,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,   110,   111,   112,   113,
      -1,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,   131,   132,   140,
      -1,    -1,   136,    -1,    -1,    -1,    -1,   141,     8,     3,
       4,    -1,   146,    -1,   148,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,   140,    69,    70,    71,    72,    73,
       8,    -1,    -1,    -1,    78,    -1,    -1,    81,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,   131,   132,    -1,
     140,    -1,   136,    -1,    -1,    -1,    -1,   141,     8,     3,
       4,    -1,   146,    -1,   148,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    69,    70,    71,    72,    73,
       8,    -1,     3,     4,    78,    -1,    -1,    81,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     8,    -1,   110,   111,   112,   113,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,   131,   132,    -1,
     140,    -1,   136,    -1,    -1,    -1,    -1,   141,    -1,     3,
       4,     5,   146,    -1,   148,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    -1,    42,   110,
     111,   112,   113,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
     131,   132,   140,    -1,    -1,   136,    -1,    -1,    -1,    -1,
     141,    -1,    -1,   144,    -1,   146,    -1,   148,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
      -1,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,   131,   132,   140,
      -1,    -1,   136,    -1,    -1,    -1,   147,   141,   149,     3,
       4,    -1,   146,    -1,   148,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    12,    13,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    -1,    59,    60,    -1,    62,    63,    64,    -1,
      -1,    67,    68,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,   141,    -1,    -1,
     144,    -1,   146,    -1,   148,   110,   111,   112,   113,    -1,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,   131,   132,   140,    -1,
      -1,   136,    -1,    -1,    -1,    -1,   141,    -1,     3,     4,
      -1,   146,    -1,   148,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    69,    70,    71,    72,    73,   149,
      -1,     3,     4,    78,    -1,    -1,    81,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,   110,   111,   112,   113,    -1,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,   131,   132,   140,    -1,
      -1,   136,     3,     4,     5,   147,   141,   149,     9,    10,
      11,   146,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,    -1,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,   131,
     132,   140,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     149,    -1,    -1,    -1,   146,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,     0,     1,   140,    -1,     4,    -1,   110,
     111,   112,   113,    -1,   149,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,    -1,    -1,    -1,   136,    -1,    -1,    35,    -1,
     141,    -1,    -1,    40,    41,   146,    43,    44,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    -1,    -1,    84,    85,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    -1,    -1,    96,
      -1,    98,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     4,    -1,    -1,    -1,   114,   115,   116,
     117,    12,    13,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,    35,    -1,    -1,    -1,    -1,    40,
      41,   149,    43,    44,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    -1,    -1,    96,    -1,    98,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,    -1,
      -1,    -1,    -1,   114,   115,   116,   117,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,   142,    -1,    -1,
      -1,    -1,   147,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   122,   123,   124,   125,   126,
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
      -1,    -1,   140
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   152,   153,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    57,    58,    59,    60,    61,    62,
      63,    64,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    76,    77,    78,    79,    80,    81,    84,    85,    90,
      91,    92,    93,    96,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   114,   115,   116,   117,   154,
     156,   157,   175,   179,   184,   187,   188,   189,   190,   191,
     192,   193,   214,   215,   216,   217,     3,     4,     5,     7,
       9,    10,    11,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    36,    37,    38,    39,    42,   104,
     110,   111,   112,   113,   118,   119,   120,   121,   131,   132,
     136,   138,   139,   141,   143,   145,   146,   148,   173,   174,
     218,   219,   231,    13,    52,   141,     6,   148,     6,     6,
       6,   141,   148,   141,   141,    75,   141,   148,   141,   141,
      75,   148,   141,   141,    56,    52,    52,    52,    52,    49,
      52,    54,    54,    46,    49,    52,    54,    49,    52,    54,
     141,    49,   141,   148,   131,   132,   141,   148,   220,   221,
     220,   148,    46,    49,    52,   148,   220,     4,    50,    59,
      52,    52,    49,     4,   104,   148,     4,     6,    49,     4,
       4,     4,   141,   141,   141,     4,   148,   227,     4,   141,
     141,     6,   143,     4,     4,     5,   148,     5,   148,   141,
     141,   141,   141,     4,   143,   145,   150,   174,   148,     5,
     231,   141,   143,   141,   143,   141,   143,   141,   143,   141,
     143,   141,   143,   141,   143,   141,   143,   141,   143,   141,
     143,   141,   143,   141,   143,   141,   143,   141,   143,   141,
     143,   141,   143,   141,   143,   141,   143,   141,   143,   141,
     143,   141,   143,   141,   141,   141,   141,     7,   141,     4,
     218,   218,   218,   218,   144,   148,   218,     4,    96,    97,
       4,     4,   184,   185,   186,   218,     6,     6,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   140,     6,     6,   218,     5,   218,   218,     4,
      46,   132,   184,   193,   218,   225,   226,   218,   218,   141,
     218,   226,   218,   218,   141,   226,   218,   218,   132,   148,
     218,   223,   225,   141,   148,   141,   141,     5,   223,   224,
     224,   224,   141,   180,   181,   182,   183,   141,   141,   141,
       4,   223,     5,   220,   220,   220,   218,   218,   131,   132,
     148,   148,   220,   148,   148,   148,   131,   132,   141,   186,
     220,   148,   141,   148,   141,   141,   224,   223,   141,     4,
       6,   143,   143,   186,     6,   148,   143,   143,     6,   218,
     218,   218,   145,   218,   148,    99,   218,   218,   218,     6,
       6,   186,     6,   186,     4,   230,   231,   230,   230,   230,
     143,   218,     4,   148,   158,     6,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   230,   230,
     230,   230,   218,     5,   143,   142,     7,   121,   226,   144,
       7,   173,   174,   145,     7,   143,   149,    46,    49,    52,
      54,   179,     6,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,     6,   142,
     147,   147,   142,   143,   148,   218,   225,     8,   133,   147,
     149,   142,   142,   218,   142,   149,   142,   142,   218,   149,
     142,   142,   148,   149,   226,   133,     7,   218,   218,   218,
     218,     7,     7,   212,   212,   218,   141,   141,   141,   141,
     218,   218,   218,   142,     6,   147,   147,   147,   147,   220,
     220,   185,   185,   147,   218,   218,   218,   218,   197,   147,
     186,   218,   218,   218,   218,     7,   213,     7,   218,     6,
     218,   218,   149,   226,   218,   218,   142,   142,   142,    96,
     147,   186,   148,     8,   142,   144,   149,   149,   143,   145,
     142,   142,   142,   142,   218,   144,   174,   218,     4,    86,
      87,    88,    89,   149,   161,   165,   168,   170,   171,   142,
     144,   142,   144,   142,   144,   142,   144,   142,   144,   142,
     144,   142,   144,   142,   144,   142,   144,   142,   144,   142,
     144,   147,   147,   142,   144,   142,   144,   142,   144,   142,
     144,   142,   144,   142,   144,   147,   147,   147,   147,   147,
     147,   142,   147,   147,   142,   142,     6,   147,   218,   223,
     223,   149,     7,   145,   173,   174,   231,   218,     6,     4,
       4,   148,   228,   144,   148,   148,   148,   148,     8,     6,
     128,   155,   226,   218,     7,   144,   148,   218,   218,   218,
     225,   218,   225,    99,     7,     7,   142,     7,    99,     7,
       7,   142,    99,     7,     7,   226,   149,   148,   218,   142,
     149,   142,   142,   218,   223,     4,   211,     6,   142,   176,
     218,   231,   176,   176,   176,   142,   142,   142,   145,   223,
     220,   218,   218,   149,   149,   218,   147,   147,   147,    76,
      82,    83,   207,   208,   220,   149,   194,   142,   149,   142,
     142,   218,     6,   218,   142,   144,   144,   149,   144,   144,
       7,     7,     7,   145,   218,   149,   218,   218,     7,   145,
     218,     4,     7,     7,     7,     7,   144,   145,   174,   230,
     149,   162,   141,   141,   148,   172,     6,   218,   218,   218,
     218,   218,   218,   218,   218,   226,   230,   218,   144,     6,
       6,   144,     4,    96,    97,   218,     6,     6,     6,     7,
     143,   227,   229,     6,   226,   226,   226,   226,   218,   128,
     230,   142,   147,   220,   226,   149,     8,    52,   223,   223,
       7,   223,    52,    54,   223,   223,     7,    54,   223,   223,
     149,   226,     6,     7,     7,     7,     7,    65,   210,     6,
       7,   142,   142,   142,   142,     7,     7,     7,     4,   147,
     147,   147,   147,   149,   220,   220,   220,     6,   148,   141,
     149,   208,   147,   207,     7,     6,     7,     7,     6,   148,
       6,     6,    52,     6,     6,   223,   223,   223,     4,   147,
       8,     8,   142,     4,     4,   144,   148,   148,   148,   148,
       6,     4,     6,   141,   218,   218,   222,   223,   148,   142,
     144,   142,   144,   142,   144,   142,   144,   142,   142,   142,
     173,     7,   173,   174,   145,     7,     6,   227,   218,   147,
     149,   149,   149,   149,   149,     6,     6,   155,   218,     6,
     149,   218,   148,    59,   178,   178,   223,     6,   148,   148,
       6,     6,   223,   148,     6,     6,   149,     5,   223,   223,
     223,     4,     6,   223,     7,     7,     7,     7,   223,   223,
     223,     6,     7,     5,   218,   218,   218,   148,   147,   149,
     147,   149,   147,   149,   218,   223,   218,   218,   220,   149,
       5,   148,   223,   148,   148,   223,   226,   148,     6,     6,
      95,   218,   218,   218,     6,     7,   145,   223,   223,   223,
     223,   174,   159,   218,   147,   147,   147,   149,   160,   218,
     223,   231,   218,     6,     4,   228,     6,   144,   227,     6,
       6,     6,     6,   230,   147,   144,   218,   220,     6,     6,
       6,   218,   218,     6,   218,     5,     6,     6,    99,   177,
     218,     6,   223,   223,   223,   223,     6,     4,   209,     6,
     218,   231,   142,   149,   142,   147,   149,   185,   220,     6,
     198,   220,     6,   199,   220,     6,   200,   149,   147,   142,
     149,   147,     6,   132,   220,     6,   220,   220,     6,   149,
     218,   223,   147,   149,     8,   149,   142,   148,   218,   231,
       4,   147,   147,   147,   147,   142,   147,   218,   218,   223,
     148,   147,   149,     6,     6,     6,     7,     6,   145,     6,
     218,   149,   149,   149,   149,     5,    50,     6,     6,     6,
       6,     6,   148,     6,     6,     6,     6,   148,   218,   149,
     147,   148,   147,   148,   147,   148,     6,   223,     7,   148,
     218,   147,   147,   147,     6,   149,    94,   218,   218,   226,
       6,     6,   223,   223,   223,   223,   163,   218,   147,   147,
     222,   218,     6,   227,    97,   147,     6,     6,     6,     6,
       6,   148,   222,   185,   147,   149,   218,   220,   207,   218,
     220,   207,   218,   220,   207,   147,   149,   223,   186,   149,
     220,   226,   220,   218,   149,   149,   149,   149,   149,   149,
     149,   148,   218,   218,   149,     6,   218,   218,   149,   149,
     218,   149,   147,   149,   149,   147,   149,   149,   147,   149,
     223,     6,    65,   149,   195,   148,   147,   149,   147,     6,
       6,     6,     6,     6,     6,   160,   142,   147,     6,   148,
     147,   149,     4,   209,   149,     6,   201,   218,     6,     6,
     202,   218,     6,     6,   203,   218,     6,   149,   218,   207,
     186,   226,     6,   220,   226,   149,   166,   218,   222,   218,
       6,   148,   149,   148,   149,   148,   149,     6,     6,   149,
     149,   196,   149,   147,   149,     6,   148,   142,   149,   149,
     207,     6,   204,   207,     6,   205,   207,     6,   206,   207,
       6,   226,     6,   164,   230,   169,   148,     6,   149,   148,
     149,   148,   149,   148,   149,   149,   147,   149,   148,   222,
       6,   207,     6,   207,     6,   207,     6,   230,     6,   167,
     230,   149,   149,   149,   149,   147,   149,     6,     6,     6,
       6,   230,     6
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
#line 188 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 23:
#line 192 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 24:
#line 199 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 25:
#line 204 "Gmsh.y"
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
#line 218 "Gmsh.y"
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

  case 27:
#line 231 "Gmsh.y"
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

  case 28:
#line 259 "Gmsh.y"
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

  case 29:
#line 273 "Gmsh.y"
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

  case 30:
#line 284 "Gmsh.y"
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

  case 31:
#line 298 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList(); 
#endif
    ;}
    break;

  case 37:
#line 312 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 38:
#line 314 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 39:
#line 319 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 40:
#line 321 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 41:
#line 326 "Gmsh.y"
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

  case 42:
#line 430 "Gmsh.y"
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

  case 43:
#line 440 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 44:
#line 449 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 45:
#line 456 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 46:
#line 466 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d)); 
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d)); 
      ViewData->T2D.push_back(ViewData->T2C.size()); 
#endif
    ;}
    break;

  case 47:
#line 475 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 48:
#line 484 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 49:
#line 491 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 50:
#line 501 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size()); 
#endif
    ;}
    break;

  case 51:
#line 509 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 52:
#line 519 "Gmsh.y"
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

  case 53:
#line 538 "Gmsh.y"
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

  case 54:
#line 557 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 55:
#line 563 "Gmsh.y"
    {
    ;}
    break;

  case 56:
#line 570 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 57:
#line 571 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 58:
#line 572 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 59:
#line 573 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 60:
#line 574 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 61:
#line 578 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 62:
#line 579 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 63:
#line 587 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	if(!(yyvsp[(2) - (4)].i))
	  gmsh_yysymbols[(yyvsp[(1) - (4)].c)].push_back((yyvsp[(3) - (4)].d));
	else
	  yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
      }
      else{
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

  case 64:
#line 609 "Gmsh.y"
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

  case 65:
#line 636 "Gmsh.y"
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

  case 66:
#line 676 "Gmsh.y"
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

  case 67:
#line 686 "Gmsh.y"
    {
      // appends to the list
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].push_back(*(double*)List_Pointer((yyvsp[(5) - (6)].l), i));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 68:
#line 694 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c)); 
      else
	gmsh_yysymbols[(yyvsp[(1) - (3)].c)][0] += (yyvsp[(2) - (3)].i);
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 69:
#line 702 "Gmsh.y"
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

  case 70:
#line 714 "Gmsh.y"
    { 
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 71:
#line 723 "Gmsh.y"
    { 
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c))
    ;}
    break;

  case 72:
#line 729 "Gmsh.y"
    { 
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c))
    ;}
    break;

  case 73:
#line 738 "Gmsh.y"
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

  case 74:
#line 756 "Gmsh.y"
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

  case 75:
#line 774 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 76:
#line 783 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 77:
#line 795 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 78:
#line 800 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 79:
#line 808 "Gmsh.y"
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

  case 80:
#line 828 "Gmsh.y"
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

  case 81:
#line 851 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->background_field = (int)(yyvsp[(4) - (5)].d);
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
#endif
    ;}
    break;

  case 82:
#line 860 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 83:
#line 868 "Gmsh.y"
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

  case 84:
#line 890 "Gmsh.y"
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

  case 85:
#line 913 "Gmsh.y"
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

  case 86:
#line 941 "Gmsh.y"
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

  case 87:
#line 953 "Gmsh.y"
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

  case 88:
#line 970 "Gmsh.y"
    { 
      (yyval.i) = (int)(yyvsp[(1) - (1)].d); 
    ;}
    break;

  case 89:
#line 974 "Gmsh.y"
    { 
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim, 
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 90:
#line 984 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 91:
#line 988 "Gmsh.y"
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

  case 92:
#line 1000 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 93:
#line 1004 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 94:
#line 1014 "Gmsh.y"
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

  case 95:
#line 1037 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 96:
#line 1041 "Gmsh.y"
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

  case 97:
#line 1057 "Gmsh.y"
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

  case 98:
#line 1079 "Gmsh.y"
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

  case 99:
#line 1097 "Gmsh.y"
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

  case 100:
#line 1119 "Gmsh.y"
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

  case 101:
#line 1137 "Gmsh.y"
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

  case 102:
#line 1167 "Gmsh.y"
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

  case 103:
#line 1197 "Gmsh.y"
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

  case 104:
#line 1215 "Gmsh.y"
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

  case 105:
#line 1233 "Gmsh.y"
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

  case 106:
#line 1259 "Gmsh.y"
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

  case 107:
#line 1276 "Gmsh.y"
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

  case 108:
#line 1294 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 109:
#line 1298 "Gmsh.y"
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

  case 110:
#line 1317 "Gmsh.y"
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

  case 111:
#line 1335 "Gmsh.y"
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

  case 112:
#line 1374 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 113:
#line 1380 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 114:
#line 1386 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 115:
#line 1393 "Gmsh.y"
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

  case 116:
#line 1418 "Gmsh.y"
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

  case 117:
#line 1443 "Gmsh.y"
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

  case 118:
#line 1459 "Gmsh.y"
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

  case 119:
#line 1478 "Gmsh.y"
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

  case 120:
#line 1509 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 121:
#line 1513 "Gmsh.y"
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

  case 122:
#line 1533 "Gmsh.y"
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

  case 123:
#line 1551 "Gmsh.y"
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

  case 124:
#line 1569 "Gmsh.y"
    {
#if defined(HAVE_OCC)
      std::vector<double> data;
      for (int i = 0 ; i < List_Nbr((yyvsp[(5) - (9)].l)); i++){
        double d; List_Read((yyvsp[(5) - (9)].l), i, &d);
        data.push_back(d);
      }
      GModel::current()->addShape((yyvsp[(3) - (9)].c), data, (yyvsp[(7) - (9)].c));
      Free((yyvsp[(3) - (9)].c)); Free((yyvsp[(7) - (9)].c));
      List_Delete((yyvsp[(5) - (9)].l));
#endif
    ;}
    break;

  case 125:
#line 1582 "Gmsh.y"
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
#line 1598 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 127:
#line 1602 "Gmsh.y"
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
#line 1624 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 129:
#line 1629 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 130:
#line 1634 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 131:
#line 1639 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 132:
#line 1644 "Gmsh.y"
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
#line 1664 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 134:
#line 1670 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 135:
#line 1680 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 136:
#line 1681 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 137:
#line 1686 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 138:
#line 1690 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 139:
#line 1694 "Gmsh.y"
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
#line 1717 "Gmsh.y"
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
#line 1740 "Gmsh.y"
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
#line 1763 "Gmsh.y"
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
#line 1791 "Gmsh.y"
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
#line 1813 "Gmsh.y"
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
#line 1834 "Gmsh.y"
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
#line 1855 "Gmsh.y"
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
#line 1875 "Gmsh.y"
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
#line 1987 "Gmsh.y"
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
#line 2006 "Gmsh.y"
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
#line 2027 "Gmsh.y"
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
#line 2135 "Gmsh.y"
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
#line 2144 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 153:
#line 2150 "Gmsh.y"
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
#line 2165 "Gmsh.y"
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
#line 2193 "Gmsh.y"
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
#line 2210 "Gmsh.y"
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
#line 2224 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 158:
#line 2230 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 159:
#line 2236 "Gmsh.y"
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
#line 2245 "Gmsh.y"
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
#line 2259 "Gmsh.y"
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
#line 2301 "Gmsh.y"
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
#line 2318 "Gmsh.y"
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
#line 2333 "Gmsh.y"
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
#line 2352 "Gmsh.y"
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
#line 2364 "Gmsh.y"
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
#line 2388 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 168:
#line 2392 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the 
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 169:
#line 2399 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 170:
#line 2405 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 171:
#line 2410 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 172:
#line 2416 "Gmsh.y"
    {
       GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 173:
#line 2426 "Gmsh.y"
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
#line 2443 "Gmsh.y"
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
#line 2460 "Gmsh.y"
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
#line 2479 "Gmsh.y"
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
#line 2498 "Gmsh.y"
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
#line 2528 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 179:
#line 2536 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 180:
#line 2542 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 181:
#line 2549 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 182:
#line 2553 "Gmsh.y"
    {
    ;}
    break;

  case 183:
#line 2562 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 184:
#line 2570 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 185:
#line 2578 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 186:
#line 2586 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 187:
#line 2590 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 188:
#line 2598 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 189:
#line 2602 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 190:
#line 2610 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 191:
#line 2614 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 192:
#line 2622 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 193:
#line 2626 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 194:
#line 2635 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 195:
#line 2642 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 196:
#line 2649 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 197:
#line 2656 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 198:
#line 2663 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 199:
#line 2670 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 200:
#line 2677 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 201:
#line 2684 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 202:
#line 2691 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 203:
#line 2698 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 204:
#line 2702 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 205:
#line 2709 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 206:
#line 2713 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 207:
#line 2720 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 208:
#line 2724 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 209:
#line 2731 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 210:
#line 2735 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 211:
#line 2742 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 212:
#line 2746 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 213:
#line 2753 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 214:
#line 2757 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 215:
#line 2764 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 216:
#line 2768 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 217:
#line 2775 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 218:
#line 2779 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 219:
#line 2786 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 220:
#line 2790 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 221:
#line 2801 "Gmsh.y"
    {
    ;}
    break;

  case 222:
#line 2804 "Gmsh.y"
    {
    ;}
    break;

  case 223:
#line 2810 "Gmsh.y"
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
#line 2819 "Gmsh.y"
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
#line 2839 "Gmsh.y"
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
#line 2862 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 227:
#line 2866 "Gmsh.y"
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
#line 2889 "Gmsh.y"
    {
      (yyval.i) = 1; // harmonic
    ;}
    break;

  case 229:
#line 2893 "Gmsh.y"
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
#line 2908 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 231:
#line 2912 "Gmsh.y"
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
#line 2927 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 233:
#line 2931 "Gmsh.y"
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
#line 2943 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 235:
#line 2947 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 236:
#line 2952 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 237:
#line 2956 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 238:
#line 2963 "Gmsh.y"
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
#line 3019 "Gmsh.y"
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
#line 3089 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 241:
#line 3094 "Gmsh.y"
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
#line 3161 "Gmsh.y"
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
#line 3204 "Gmsh.y"
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
#line 3230 "Gmsh.y"
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

  case 245:
#line 3253 "Gmsh.y"
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

  case 246:
#line 3276 "Gmsh.y"
    {
    ;}
    break;

  case 247:
#line 3279 "Gmsh.y"
    {
    ;}
    break;

  case 248:
#line 3288 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 249:
#line 3292 "Gmsh.y"
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

  case 250:
#line 3309 "Gmsh.y"
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

  case 251:
#line 3346 "Gmsh.y"
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

  case 252:
#line 3382 "Gmsh.y"
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

  case 253:
#line 3417 "Gmsh.y"
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

  case 254:
#line 3456 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 255:
#line 3457 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 256:
#line 3458 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 257:
#line 3459 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 258:
#line 3460 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 259:
#line 3461 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 260:
#line 3462 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 261:
#line 3463 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 262:
#line 3465 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 263:
#line 3471 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 264:
#line 3472 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 265:
#line 3473 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 266:
#line 3474 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 267:
#line 3475 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 268:
#line 3476 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 269:
#line 3477 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 270:
#line 3478 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 271:
#line 3479 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 272:
#line 3480 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 273:
#line 3481 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 274:
#line 3482 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 275:
#line 3483 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 276:
#line 3484 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 277:
#line 3485 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 278:
#line 3486 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 279:
#line 3487 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 280:
#line 3488 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 281:
#line 3489 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 282:
#line 3490 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 283:
#line 3491 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 284:
#line 3492 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 285:
#line 3493 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 286:
#line 3494 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 287:
#line 3495 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 288:
#line 3496 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 289:
#line 3497 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 290:
#line 3498 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 291:
#line 3499 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 292:
#line 3500 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 293:
#line 3501 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 294:
#line 3502 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 295:
#line 3504 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 296:
#line 3505 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 297:
#line 3506 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 298:
#line 3507 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 299:
#line 3508 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 300:
#line 3509 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 301:
#line 3510 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 302:
#line 3511 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 303:
#line 3512 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 304:
#line 3513 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 305:
#line 3514 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 306:
#line 3515 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 307:
#line 3516 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 308:
#line 3517 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 309:
#line 3518 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 310:
#line 3519 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 311:
#line 3520 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 312:
#line 3521 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 313:
#line 3522 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 314:
#line 3523 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 315:
#line 3524 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 316:
#line 3533 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 317:
#line 3534 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 318:
#line 3535 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 319:
#line 3536 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 320:
#line 3537 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 321:
#line 3538 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 322:
#line 3539 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 323:
#line 3544 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (1)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (1)].c));
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = gmsh_yysymbols[(yyvsp[(1) - (1)].c)][0];
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 324:
#line 3557 "Gmsh.y"
    {
      char tmpstring[1024];
      sprintf(tmpstring, "%s_%d", (yyvsp[(1) - (5)].c), (int)(yyvsp[(4) - (5)].d)) ;
      if(!gmsh_yysymbols.count(tmpstring)){
	yymsg(0, "Unknown variable '%s'", tmpstring);
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = gmsh_yysymbols[tmpstring][0];
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 325:
#line 3569 "Gmsh.y"
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

  case 326:
#line 3584 "Gmsh.y"
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

  case 327:
#line 3594 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (2)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (2)].c));
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = (gmsh_yysymbols[(yyvsp[(1) - (2)].c)][0] += (yyvsp[(2) - (2)].i));
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 328:
#line 3604 "Gmsh.y"
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

  case 329:
#line 3622 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 330:
#line 3627 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 331:
#line 3632 "Gmsh.y"
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

  case 332:
#line 3642 "Gmsh.y"
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

  case 333:
#line 3652 "Gmsh.y"
    { 
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 334:
#line 3660 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 335:
#line 3664 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 336:
#line 3668 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 337:
#line 3672 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 338:
#line 3676 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 339:
#line 3683 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 340:
#line 3687 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 341:
#line 3691 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 342:
#line 3695 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 343:
#line 3702 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 344:
#line 3707 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 345:
#line 3714 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 346:
#line 3719 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 347:
#line 3723 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 348:
#line 3728 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 349:
#line 3732 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 350:
#line 3740 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 351:
#line 3751 "Gmsh.y"
    { 
      (yyval.l) = (yyvsp[(1) - (1)].l); 
    ;}
    break;

  case 352:
#line 3755 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 353:
#line 3767 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 354:
#line 3775 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 355:
#line 3783 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); 
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 356:
#line 3790 "Gmsh.y"
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

  case 357:
#line 3801 "Gmsh.y"
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

  case 358:
#line 3821 "Gmsh.y"
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

  case 359:
#line 3831 "Gmsh.y"
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

  case 360:
#line 3841 "Gmsh.y"
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

  case 361:
#line 3851 "Gmsh.y"
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

  case 362:
#line 3871 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 363:
#line 3876 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 364:
#line 3880 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 365:
#line 3884 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 366:
#line 3896 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 367:
#line 3900 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 368:
#line 3912 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 369:
#line 3919 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 370:
#line 3929 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 371:
#line 3933 "Gmsh.y"
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

  case 372:
#line 3948 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 373:
#line 3953 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 374:
#line 3960 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 375:
#line 3964 "Gmsh.y"
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

  case 376:
#line 3977 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 377:
#line 3985 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 378:
#line 3996 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 379:
#line 4000 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 380:
#line 4008 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 381:
#line 4016 "Gmsh.y"
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

  case 382:
#line 4030 "Gmsh.y"
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

  case 383:
#line 4044 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 384:
#line 4048 "Gmsh.y"
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
#line 8712 "Gmsh.tab.cpp"
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


#line 4068 "Gmsh.y"


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

