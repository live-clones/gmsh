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
     tAFFECTDIVIDE = 372,
     tAFFECTTIMES = 373,
     tAFFECTMINUS = 374,
     tAFFECTPLUS = 375,
     tOR = 376,
     tAND = 377,
     tNOTEQUAL = 378,
     tEQUAL = 379,
     tGREATEROREQUAL = 380,
     tLESSOREQUAL = 381,
     UNARYPREC = 382,
     tMINUSMINUS = 383,
     tPLUSPLUS = 384
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
#define tAFFECTDIVIDE 372
#define tAFFECTTIMES 373
#define tAFFECTMINUS 374
#define tAFFECTPLUS 375
#define tOR 376
#define tAND 377
#define tNOTEQUAL 378
#define tEQUAL 379
#define tGREATEROREQUAL 380
#define tLESSOREQUAL 381
#define UNARYPREC 382
#define tMINUSMINUS 383
#define tPLUSPLUS 384




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
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
#line 456 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 469 "Gmsh.tab.cpp"

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
#define YYLAST   6642

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  150
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  383
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1358

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   384

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   135,     2,   145,     2,   134,     2,     2,
     140,   141,   132,   130,   146,   131,   144,   133,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     126,     2,   127,   121,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   142,     2,   143,   139,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   147,     2,   148,   149,     2,     2,     2,
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
     115,   116,   117,   118,   119,   120,   122,   123,   124,   125,
     128,   129,   136,   137,   138
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
    1587,  1595,  1607,  1619,  1621,  1625,  1628,  1631,  1634,  1638,
    1642,  1646,  1650,  1654,  1658,  1662,  1666,  1670,  1674,  1678,
    1682,  1686,  1690,  1696,  1701,  1706,  1711,  1716,  1721,  1726,
    1731,  1736,  1741,  1746,  1753,  1758,  1763,  1768,  1773,  1778,
    1783,  1790,  1797,  1804,  1809,  1814,  1819,  1824,  1829,  1834,
    1839,  1844,  1849,  1854,  1859,  1866,  1871,  1876,  1881,  1886,
    1891,  1896,  1903,  1910,  1917,  1922,  1924,  1926,  1928,  1930,
    1932,  1934,  1936,  1938,  1944,  1949,  1954,  1957,  1963,  1967,
    1974,  1979,  1987,  1994,  1996,  1999,  2002,  2006,  2010,  2022,
    2032,  2040,  2048,  2050,  2054,  2056,  2058,  2061,  2065,  2070,
    2076,  2078,  2080,  2083,  2087,  2091,  2097,  2102,  2104,  2106,
    2110,  2117,  2119,  2121,  2125,  2129,  2139,  2147,  2149,  2155,
    2159,  2166,  2168,  2172,  2174,  2176,  2180,  2187,  2189,  2191,
    2198,  2203,  2208,  2213
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     151,     0,    -1,   152,    -1,     1,     6,    -1,    -1,   152,
     153,    -1,   156,    -1,   155,    -1,   174,    -1,   178,    -1,
     183,    -1,   187,    -1,   188,    -1,   189,    -1,   192,    -1,
     213,    -1,   214,    -1,   215,    -1,   191,    -1,   190,    -1,
     186,    -1,   216,    -1,   127,    -1,   127,   127,    -1,    35,
     140,     5,   141,     6,    -1,    35,   140,     5,   141,   154,
     229,     6,    -1,    35,   140,     5,   146,   225,   141,     6,
      -1,    35,   140,     5,   146,   225,   141,   154,   229,     6,
      -1,     4,     5,   147,   157,   148,     6,    -1,    84,     4,
     142,   217,   143,     6,    -1,    85,     4,   142,   217,   143,
       6,    -1,    -1,   157,   160,    -1,   157,   164,    -1,   157,
     167,    -1,   157,   169,    -1,   157,   170,    -1,   217,    -1,
     158,   146,   217,    -1,   217,    -1,   159,   146,   217,    -1,
      -1,    -1,     4,   161,   140,   158,   141,   162,   147,   159,
     148,     6,    -1,   229,    -1,   163,   146,   229,    -1,    -1,
      86,   140,   217,   146,   217,   146,   217,   141,   165,   147,
     163,   148,     6,    -1,   229,    -1,   166,   146,   229,    -1,
      -1,    87,   140,   217,   146,   217,   146,   217,   146,   217,
     141,   168,   147,   166,   148,     6,    -1,    88,   147,   221,
     148,   147,   221,   148,     6,    -1,    88,   147,   221,   148,
     147,   221,   148,   147,   221,   148,   147,   221,   148,     6,
      -1,    -1,    89,   171,   147,   159,   148,     6,    -1,     7,
      -1,   120,    -1,   119,    -1,   118,    -1,   117,    -1,   138,
      -1,   137,    -1,     4,   172,   217,     6,    -1,     4,   142,
     217,   143,   172,   217,     6,    -1,     4,   142,   147,   225,
     148,   143,   172,   222,     6,    -1,     4,   142,   143,     7,
     222,     6,    -1,     4,   142,   143,   120,   222,     6,    -1,
       4,   173,     6,    -1,     4,   142,   217,   143,   173,     6,
      -1,     4,     7,   230,     6,    -1,     4,   144,     4,     7,
     230,     6,    -1,     4,   142,   217,   143,   144,     4,     7,
     230,     6,    -1,     4,   144,     4,   172,   217,     6,    -1,
       4,   142,   217,   143,   144,     4,   172,   217,     6,    -1,
       4,   144,     4,   173,     6,    -1,     4,   142,   217,   143,
     144,     4,   173,     6,    -1,     4,   144,    96,   144,     4,
       7,   226,     6,    -1,     4,   142,   217,   143,   144,    96,
     144,     4,     7,   226,     6,    -1,     4,   144,    97,     7,
     227,     6,    -1,     4,   142,   217,   143,   144,    97,     7,
     227,     6,    -1,     4,   104,     7,   217,     6,    -1,   104,
     142,   217,   143,     7,     4,     6,    -1,   104,   142,   217,
     143,   144,     4,     7,   217,     6,    -1,   104,   142,   217,
     143,   144,     4,     7,   230,     6,    -1,   104,   142,   217,
     143,   144,     4,     7,   147,   225,   148,     6,    -1,    66,
     140,     4,   141,   144,     4,     7,   217,     6,    -1,    66,
     140,     4,   141,   144,     4,     7,   230,     6,    -1,   217,
      -1,   230,    -1,    -1,    99,    50,   147,   217,   148,    -1,
      -1,    59,   219,    -1,    46,   140,   217,   141,     7,   219,
       6,    -1,    -1,    63,    46,   179,   140,   175,   141,     7,
     222,     6,    -1,    55,    56,   222,     7,   217,     6,    -1,
      49,   140,   217,   141,     7,   222,     6,    -1,    67,    49,
     222,     6,    -1,    53,   140,   217,   141,     7,   222,     6,
      -1,    47,   140,   217,   141,     7,   222,   177,     6,    -1,
      48,   140,   217,   141,     7,   222,   177,     6,    -1,    91,
     140,   217,   141,     7,   222,     6,    -1,    92,   140,   217,
     141,     7,   222,     6,    -1,    93,   140,   217,   141,     7,
     222,    95,   222,    94,   217,     6,    -1,    49,    75,   140,
     217,   141,     7,   222,     6,    -1,    64,    49,   140,   217,
     141,     7,   222,     6,    -1,    -1,    63,    49,   180,   140,
     175,   141,     7,   222,     6,    -1,    59,    52,   140,   217,
     141,     7,   222,     6,    -1,    60,    52,   140,   217,   141,
       7,   222,   176,     6,    -1,    12,    13,     6,    -1,    13,
      52,   217,     6,    -1,    57,    52,   140,   217,   141,     7,
       5,     5,     5,     6,    -1,    50,   140,   217,   141,     7,
     222,     6,    -1,    51,   140,   217,   141,     7,   222,     6,
      -1,    52,    75,   140,   217,   141,     7,   222,     6,    -1,
      64,    52,   140,   217,   141,     7,   222,   208,     6,    -1,
      64,    52,   140,   217,   141,     7,   222,     4,   147,   221,
     148,   208,     6,    -1,    -1,    63,    52,   181,   140,   175,
     141,     7,   222,     6,    -1,    62,    54,   140,   217,   141,
       7,   222,     6,    -1,    54,   140,   217,   141,     7,   222,
       6,    -1,    68,   140,     5,   146,   222,   146,     5,   141,
       6,    -1,    64,    54,   140,   217,   141,     7,   222,     6,
      -1,    -1,    63,    54,   182,   140,   175,   141,     7,   222,
       6,    -1,    70,   219,   147,   184,   148,    -1,    69,   147,
     219,   146,   219,   146,   217,   148,   147,   184,   148,    -1,
      71,   219,   147,   184,   148,    -1,    72,   147,   219,   146,
     217,   148,   147,   184,   148,    -1,     4,   147,   184,   148,
      -1,    81,    49,   147,   225,   148,    52,   147,   217,   148,
      -1,    78,    49,   140,   217,   141,   147,   225,   148,     6,
      -1,   185,    -1,   183,    -1,    -1,   185,   178,    -1,   185,
      46,   147,   225,   148,     6,    -1,   185,    49,   147,   225,
     148,     6,    -1,   185,    52,   147,   225,   148,     6,    -1,
     185,    54,   147,   225,   148,     6,    -1,    74,    59,   140,
     217,   141,     7,   222,     6,    -1,    74,    59,   140,   217,
     141,     7,   147,   219,   146,   219,   146,   225,   148,     6,
      -1,    74,    59,   140,   217,   141,     7,   147,   219,   146,
     219,   146,   219,   146,   225,   148,     6,    -1,    74,    50,
     140,   217,   141,     7,   147,   219,   146,   225,   148,     6,
      -1,    74,     4,   140,   217,   141,     7,   222,     6,    -1,
      74,     4,   140,   217,   141,     7,     5,     6,    -1,    74,
       4,   147,   217,   148,     6,    -1,    74,     4,   140,   217,
     141,     7,   147,   219,   146,   219,   146,   225,   148,     6,
      -1,    79,   147,   185,   148,    -1,    79,   104,   142,   217,
     143,     6,    -1,    79,     4,   142,   217,   143,     6,    -1,
      79,     4,     6,    -1,    79,     4,     4,     6,    -1,    96,
     226,   147,   185,   148,    -1,   108,     5,     6,    -1,   109,
       5,     6,    -1,   108,   147,   185,   148,    -1,   109,   147,
     185,   148,    -1,     4,   230,     6,    -1,     4,     4,   142,
     217,   143,   229,     6,    -1,     4,     4,     4,   142,   217,
     143,     6,    -1,     4,   217,     6,    -1,    66,   140,     4,
     141,   144,     4,     6,    -1,    90,     4,     6,    -1,   103,
       6,    -1,    43,     6,    -1,    40,     6,    -1,    40,   147,
     217,   146,   217,   146,   217,   146,   217,   146,   217,   146,
     217,   148,     6,    -1,    41,     6,    -1,    44,     6,    -1,
      98,   140,   217,     8,   217,   141,    -1,    98,   140,   217,
       8,   217,     8,   217,   141,    -1,    98,     4,    99,   147,
     217,     8,   217,   148,    -1,    98,     4,    99,   147,   217,
       8,   217,     8,   217,   148,    -1,   100,    -1,   107,     4,
      -1,   105,    -1,   106,     4,     6,    -1,   101,   140,   217,
     141,    -1,   102,    -1,    73,   219,   147,   185,   148,    -1,
      73,   147,   219,   146,   219,   146,   217,   148,   147,   185,
     148,    -1,    73,   147,   219,   146,   219,   146,   219,   146,
     217,   148,   147,   185,   148,    -1,    -1,    73,   219,   147,
     185,   193,   206,   148,    -1,    -1,    73,   147,   219,   146,
     219,   146,   217,   148,   147,   185,   194,   206,   148,    -1,
      -1,    73,   147,   219,   146,   219,   146,   219,   146,   217,
     148,   147,   185,   195,   206,   148,    -1,    -1,    73,   147,
     185,   196,   206,   148,    -1,    73,    46,   147,   217,   146,
     219,   148,     6,    -1,    73,    49,   147,   217,   146,   219,
     148,     6,    -1,    73,    52,   147,   217,   146,   219,   148,
       6,    -1,    73,    46,   147,   217,   146,   219,   146,   219,
     146,   217,   148,     6,    -1,    73,    49,   147,   217,   146,
     219,   146,   219,   146,   217,   148,     6,    -1,    73,    52,
     147,   217,   146,   219,   146,   219,   146,   217,   148,     6,
      -1,    73,    46,   147,   217,   146,   219,   146,   219,   146,
     219,   146,   217,   148,     6,    -1,    73,    49,   147,   217,
     146,   219,   146,   219,   146,   219,   146,   217,   148,     6,
      -1,    73,    52,   147,   217,   146,   219,   146,   219,   146,
     219,   146,   217,   148,     6,    -1,    -1,    73,    46,   147,
     217,   146,   219,   148,   197,   147,   206,   148,     6,    -1,
      -1,    73,    49,   147,   217,   146,   219,   148,   198,   147,
     206,   148,     6,    -1,    -1,    73,    52,   147,   217,   146,
     219,   148,   199,   147,   206,   148,     6,    -1,    -1,    73,
      46,   147,   217,   146,   219,   146,   219,   146,   217,   148,
     200,   147,   206,   148,     6,    -1,    -1,    73,    49,   147,
     217,   146,   219,   146,   219,   146,   217,   148,   201,   147,
     206,   148,     6,    -1,    -1,    73,    52,   147,   217,   146,
     219,   146,   219,   146,   217,   148,   202,   147,   206,   148,
       6,    -1,    -1,    73,    46,   147,   217,   146,   219,   146,
     219,   146,   219,   146,   217,   148,   203,   147,   206,   148,
       6,    -1,    -1,    73,    49,   147,   217,   146,   219,   146,
     219,   146,   219,   146,   217,   148,   204,   147,   206,   148,
       6,    -1,    -1,    73,    52,   147,   217,   146,   219,   146,
     219,   146,   219,   146,   217,   148,   205,   147,   206,   148,
       6,    -1,   207,    -1,   206,   207,    -1,    82,   147,   217,
     148,     6,    -1,    82,   147,   222,   146,   222,   148,     6,
      -1,    82,   147,   222,   146,   222,   146,   222,   148,     6,
      -1,    76,     6,    -1,    83,   140,   217,   141,     7,   222,
      65,   217,     6,    -1,    -1,     4,    -1,    -1,    65,     4,
     217,    -1,    -1,     4,    -1,    -1,     7,   222,    -1,    -1,
       7,   217,    -1,    61,    49,   223,     7,   217,   209,     6,
      -1,    61,    52,   223,   211,   210,     6,    -1,    58,    52,
     147,   217,   148,     7,   222,     6,    -1,    61,    54,   223,
     211,     6,    -1,    76,    52,   223,   212,     6,    -1,    77,
      52,   222,     7,   217,     6,    -1,    46,   147,   225,   148,
      99,    52,   147,   217,   148,     6,    -1,    49,   147,   225,
     148,    99,    52,   147,   217,   148,     6,    -1,    49,   147,
     225,   148,    99,    54,   147,   217,   148,     6,    -1,    52,
     147,   225,   148,    99,    54,   147,   217,   148,     6,    -1,
      80,     6,    -1,    80,     4,     6,    -1,   114,   147,   222,
     146,   222,   148,     6,    -1,   115,   140,   229,   141,     7,
     147,   222,   146,   222,   148,     6,    -1,   116,   140,   229,
     141,     7,   147,   222,   146,   222,   148,     6,    -1,   218,
      -1,   140,   217,   141,    -1,   131,   217,    -1,   130,   217,
      -1,   135,   217,    -1,   217,   131,   217,    -1,   217,   130,
     217,    -1,   217,   132,   217,    -1,   217,   133,   217,    -1,
     217,   134,   217,    -1,   217,   139,   217,    -1,   217,   126,
     217,    -1,   217,   127,   217,    -1,   217,   129,   217,    -1,
     217,   128,   217,    -1,   217,   125,   217,    -1,   217,   124,
     217,    -1,   217,   123,   217,    -1,   217,   122,   217,    -1,
     217,   121,   217,     8,   217,    -1,    14,   140,   217,   141,
      -1,    15,   140,   217,   141,    -1,    16,   140,   217,   141,
      -1,    17,   140,   217,   141,    -1,    18,   140,   217,   141,
      -1,    19,   140,   217,   141,    -1,    20,   140,   217,   141,
      -1,    21,   140,   217,   141,    -1,    22,   140,   217,   141,
      -1,    24,   140,   217,   141,    -1,    25,   140,   217,   146,
     217,   141,    -1,    26,   140,   217,   141,    -1,    27,   140,
     217,   141,    -1,    28,   140,   217,   141,    -1,    29,   140,
     217,   141,    -1,    30,   140,   217,   141,    -1,    31,   140,
     217,   141,    -1,    32,   140,   217,   146,   217,   141,    -1,
      33,   140,   217,   146,   217,   141,    -1,    34,   140,   217,
     146,   217,   141,    -1,    23,   140,   217,   141,    -1,    14,
     142,   217,   143,    -1,    15,   142,   217,   143,    -1,    16,
     142,   217,   143,    -1,    17,   142,   217,   143,    -1,    18,
     142,   217,   143,    -1,    19,   142,   217,   143,    -1,    20,
     142,   217,   143,    -1,    21,   142,   217,   143,    -1,    22,
     142,   217,   143,    -1,    24,   142,   217,   143,    -1,    25,
     142,   217,   146,   217,   143,    -1,    26,   142,   217,   143,
      -1,    27,   142,   217,   143,    -1,    28,   142,   217,   143,
      -1,    29,   142,   217,   143,    -1,    30,   142,   217,   143,
      -1,    31,   142,   217,   143,    -1,    32,   142,   217,   146,
     217,   143,    -1,    33,   142,   217,   146,   217,   143,    -1,
      34,   142,   217,   146,   217,   143,    -1,    23,   142,   217,
     143,    -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,
     111,    -1,   112,    -1,   113,    -1,     4,    -1,     4,   149,
     147,   217,   148,    -1,     4,   142,   217,   143,    -1,   145,
       4,   142,   143,    -1,     4,   173,    -1,     4,   142,   217,
     143,   173,    -1,     4,   144,     4,    -1,     4,   142,   217,
     143,   144,     4,    -1,     4,   144,     4,   173,    -1,     4,
     142,   217,   143,   144,     4,   173,    -1,   110,   140,     5,
     146,   217,   141,    -1,   220,    -1,   131,   219,    -1,   130,
     219,    -1,   219,   131,   219,    -1,   219,   130,   219,    -1,
     147,   217,   146,   217,   146,   217,   146,   217,   146,   217,
     148,    -1,   147,   217,   146,   217,   146,   217,   146,   217,
     148,    -1,   147,   217,   146,   217,   146,   217,   148,    -1,
     140,   217,   146,   217,   146,   217,   141,    -1,   222,    -1,
     221,   146,   222,    -1,   217,    -1,   224,    -1,   147,   148,
      -1,   147,   225,   148,    -1,   131,   147,   225,   148,    -1,
     217,   132,   147,   225,   148,    -1,   222,    -1,     5,    -1,
     131,   224,    -1,   217,   132,   224,    -1,   217,     8,   217,
      -1,   217,     8,   217,     8,   217,    -1,    46,   147,   217,
     148,    -1,   183,    -1,   192,    -1,     4,   142,   143,    -1,
       4,   142,   147,   225,   148,   143,    -1,   217,    -1,   224,
      -1,   225,   146,   217,    -1,   225,   146,   224,    -1,   147,
     217,   146,   217,   146,   217,   146,   217,   148,    -1,   147,
     217,   146,   217,   146,   217,   148,    -1,     4,    -1,     4,
     144,    96,   144,     4,    -1,   147,   228,   148,    -1,     4,
     142,   217,   143,   144,    97,    -1,   226,    -1,   228,   146,
     226,    -1,   230,    -1,     4,    -1,     4,   144,     4,    -1,
       4,   142,   217,   143,   144,     4,    -1,     5,    -1,    42,
      -1,    37,   140,   229,   146,   229,   141,    -1,    38,   140,
     229,   141,    -1,    39,   140,   229,   141,    -1,    36,   140,
     229,   141,    -1,    36,   140,   229,   146,   225,   141,    -1
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
    1118,  1136,  1166,  1196,  1214,  1232,  1258,  1275,  1292,  1291,
    1314,  1332,  1371,  1377,  1383,  1390,  1415,  1440,  1456,  1474,
    1507,  1506,  1530,  1548,  1566,  1579,  1596,  1595,  1621,  1626,
    1631,  1636,  1641,  1661,  1667,  1678,  1679,  1684,  1687,  1691,
    1714,  1737,  1760,  1788,  1809,  1830,  1852,  1872,  1984,  2003,
    2023,  2132,  2141,  2147,  2162,  2190,  2207,  2221,  2227,  2233,
    2242,  2256,  2296,  2313,  2328,  2347,  2359,  2383,  2387,  2394,
    2400,  2405,  2411,  2421,  2438,  2455,  2474,  2493,  2523,  2531,
    2537,  2544,  2548,  2557,  2565,  2573,  2582,  2581,  2594,  2593,
    2606,  2605,  2618,  2617,  2630,  2637,  2644,  2651,  2658,  2665,
    2672,  2679,  2686,  2694,  2693,  2705,  2704,  2716,  2715,  2727,
    2726,  2738,  2737,  2749,  2748,  2760,  2759,  2771,  2770,  2782,
    2781,  2796,  2799,  2805,  2814,  2834,  2857,  2861,  2885,  2888,
    2904,  2907,  2923,  2926,  2939,  2942,  2948,  2951,  2958,  3014,
    3084,  3089,  3156,  3199,  3225,  3248,  3271,  3274,  3283,  3287,
    3304,  3337,  3371,  3409,  3410,  3411,  3412,  3413,  3414,  3415,
    3416,  3417,  3424,  3425,  3426,  3427,  3428,  3429,  3430,  3431,
    3432,  3433,  3434,  3435,  3436,  3437,  3438,  3439,  3440,  3441,
    3442,  3443,  3444,  3445,  3446,  3447,  3448,  3449,  3450,  3451,
    3452,  3453,  3454,  3455,  3457,  3458,  3459,  3460,  3461,  3462,
    3463,  3464,  3465,  3466,  3467,  3468,  3469,  3470,  3471,  3472,
    3473,  3474,  3475,  3476,  3477,  3486,  3487,  3488,  3489,  3490,
    3491,  3492,  3496,  3509,  3521,  3536,  3546,  3556,  3574,  3579,
    3584,  3594,  3604,  3612,  3616,  3620,  3624,  3628,  3635,  3639,
    3643,  3647,  3654,  3659,  3666,  3671,  3675,  3680,  3684,  3692,
    3703,  3707,  3719,  3727,  3735,  3742,  3753,  3773,  3783,  3793,
    3803,  3823,  3828,  3832,  3836,  3848,  3852,  3864,  3871,  3881,
    3885,  3900,  3905,  3912,  3916,  3929,  3937,  3948,  3952,  3960,
    3968,  3982,  3996,  4000
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
  "tHomCut", "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS",
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
     375,    63,   376,   377,   378,   379,    60,    62,   380,   381,
      43,    45,    42,    47,    37,    33,   382,   383,   384,    94,
      40,    41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   150,   151,   151,   152,   152,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   154,   154,   155,   155,   155,   155,   156,   156,
     156,   157,   157,   157,   157,   157,   157,   158,   158,   159,
     159,   161,   162,   160,   163,   163,   165,   164,   166,   166,
     168,   167,   169,   169,   171,   170,   172,   172,   172,   172,
     172,   173,   173,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   175,   175,
     176,   176,   177,   177,   178,   179,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   180,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     181,   178,   178,   178,   178,   178,   182,   178,   183,   183,
     183,   183,   183,   183,   183,   184,   184,   185,   185,   185,
     185,   185,   185,   186,   186,   186,   186,   186,   186,   186,
     186,   187,   187,   187,   187,   187,   188,   189,   189,   189,
     189,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   192,   192,   192,   193,   192,   194,   192,
     195,   192,   196,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   197,   192,   198,   192,   199,   192,   200,
     192,   201,   192,   202,   192,   203,   192,   204,   192,   205,
     192,   206,   206,   207,   207,   207,   207,   207,   208,   208,
     209,   209,   210,   210,   211,   211,   212,   212,   213,   213,
     213,   213,   213,   213,   214,   214,   214,   214,   215,   215,
     216,   216,   216,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   219,   219,   219,   219,   219,   220,   220,
     220,   220,   221,   221,   222,   222,   222,   222,   222,   222,
     223,   223,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   225,   225,   225,   225,   226,   226,   226,   226,   227,
     227,   228,   228,   229,   229,   229,   229,   230,   230,   230,
     230,   230,   230,   230
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
       7,    11,    11,     1,     3,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4,     4,     2,     5,     3,     6,
       4,     7,     6,     1,     2,     2,     3,     3,    11,     9,
       7,     7,     1,     3,     1,     1,     2,     3,     4,     5,
       1,     1,     2,     3,     3,     5,     4,     1,     1,     3,
       6,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     1,     3,     6,     1,     1,     6,
       4,     4,     4,     6
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
     179,     0,     0,     0,     0,     0,     0,     0,     5,     7,
       6,     8,     9,    10,    20,    11,    12,    13,    19,    18,
      14,    15,    16,    17,    21,   315,   322,   377,    56,   316,
     317,   318,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   378,     0,     0,
     319,   320,   321,    60,    59,    58,    57,     0,     0,     0,
      62,    61,     0,     0,     0,     0,   137,     0,     0,     0,
     253,     0,     0,     0,     0,   169,     0,   171,   168,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,   108,   120,   126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   333,     0,
       0,     0,     0,     0,   137,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,     0,   248,     0,     0,     0,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
     167,     0,     0,   178,     0,   137,     0,   137,     0,     0,
       0,     0,     0,     0,     0,   326,    31,   377,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   322,   256,   255,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     136,     0,   135,     0,    68,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,   112,     0,     0,     0,     0,   322,     0,     0,
     357,   358,   361,   362,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   344,     0,
     345,     0,     0,     0,     0,   351,   350,     0,   234,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   335,   334,     0,     0,     0,     0,   137,   137,
       0,     0,     0,     0,     0,     0,     0,   192,     0,   137,
       0,     0,     0,     0,   236,     0,     0,     0,   154,     0,
       0,     0,   249,     0,     0,     0,   166,     0,     0,     0,
       0,     0,   137,     0,     0,     0,     0,   180,   157,     0,
     158,     0,     0,   374,     0,   373,     0,     0,     0,   328,
       0,     0,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,   132,     0,     0,     0,     0,   138,    63,
       0,   271,   270,   269,   268,   264,   265,   267,   266,   259,
     258,   260,   261,   262,   263,   113,     0,     0,     0,     0,
       0,     0,   255,   352,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     346,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,     0,     0,   337,   336,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   186,     0,     0,
       0,     0,     0,     0,     0,     0,   155,     0,     0,   151,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,     0,   159,   160,     0,     0,     0,     0,     0,
       0,   324,   330,     0,    41,     0,     0,     0,    54,     0,
      32,    33,    34,    35,    36,   273,   294,   274,   295,   275,
     296,   276,   297,   277,   298,   278,   299,   279,   300,   280,
     301,   281,   302,   293,   314,   282,   303,     0,     0,   284,
     305,   285,   306,   286,   307,   287,   308,   288,   309,   289,
     310,     0,     0,     0,     0,     0,     0,   382,     0,     0,
     380,   381,    81,     0,     0,     0,     0,     0,    56,     0,
       0,     0,     0,     0,    75,     0,     0,     0,     0,   325,
       0,     0,     0,     0,     0,    24,    22,     0,     0,     0,
       0,   359,     0,     0,   354,   260,   353,   363,   364,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   347,     0,     0,     0,     0,     0,     0,   230,
     235,   233,     0,   241,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
     130,     0,     0,     0,     0,     0,     0,     0,     0,   221,
       0,   183,     0,     0,     0,     0,     0,   237,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,     0,     0,     0,     0,     0,     0,   375,     0,
       0,     0,     0,   327,     0,   323,     0,     0,     0,     0,
       0,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   324,    66,    67,     0,     0,     0,     0,
       0,    69,    71,    73,     0,     0,   371,     0,    79,     0,
       0,     0,     0,   272,    23,     0,     0,     0,     0,     0,
     356,     0,     0,    92,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   348,     0,    97,     0,     0,
       0,     0,     0,     0,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   226,     0,     0,   193,   222,     0,     0,     0,
     149,     0,     0,   243,     0,   153,   152,     0,    29,    30,
       0,     0,     0,   368,     0,     0,     0,   173,     0,     0,
       0,     0,     0,     0,   163,   329,   162,     0,     0,     0,
       0,   342,     0,   283,   304,   290,   311,   291,   312,   292,
     313,   383,   379,   332,     0,    56,     0,     0,     0,     0,
      64,     0,     0,     0,   369,     0,     0,     0,     0,    25,
      26,     0,     0,    94,     0,   355,     0,     0,     0,     0,
       0,    98,     0,     0,   115,   116,     0,     0,   100,   123,
     349,     0,     0,     0,    90,     0,   238,     0,     0,     0,
       0,     0,     0,   228,     0,   165,     0,     0,     0,     0,
       0,   137,     0,   203,     0,   205,     0,   207,   344,     0,
       0,     0,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,     0,     0,     0,     0,    82,     0,
     250,     0,     0,     0,   331,     0,    37,     0,     0,     0,
       0,     0,    39,     0,     0,     0,    76,     0,     0,    77,
       0,   372,   139,   140,   141,   142,     0,     0,   360,     0,
      93,   101,   102,   106,     0,     0,   117,     0,     0,   240,
     110,     0,     0,   231,   122,     0,     0,     0,     0,   107,
     229,     0,   125,     0,     0,     0,     0,   341,     0,   340,
       0,     0,   194,     0,     0,   195,     0,     0,   196,     0,
       0,     0,     0,     0,     0,   148,     0,     0,   147,     0,
       0,   143,     0,     0,     0,     0,   366,     0,   175,   174,
       0,     0,     0,   376,     0,     0,    42,     0,     0,     0,
     343,     0,     0,     0,    65,    72,    74,     0,    80,     0,
      27,     0,     0,     0,     0,     0,     0,     0,   111,    96,
     109,   121,   127,     0,   118,    86,    87,   124,   137,     0,
     131,     0,     0,     0,     0,     0,     0,   223,     0,     0,
     137,     0,     0,     0,     0,   134,   133,     0,     0,     0,
       0,    83,    84,     0,     0,     0,    38,     0,     0,     0,
      40,    55,     0,   370,     0,   244,   245,   246,   247,   114,
       0,     0,     0,     0,   339,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   188,     0,     0,
       0,     0,     0,   365,   176,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,   228,   129,     0,   209,     0,
       0,   211,     0,     0,   213,     0,     0,     0,   224,     0,
     184,     0,   137,     0,     0,     0,   105,    85,   251,   252,
       0,    46,     0,    52,     0,     0,    91,   229,     0,   338,
     197,     0,     0,   204,   198,     0,     0,   206,   199,     0,
       0,   208,     0,     0,     0,   190,     0,   146,     0,     0,
       0,     0,     0,     0,     0,   119,     0,   215,     0,   217,
       0,   219,   225,   227,   189,   185,     0,     0,     0,     0,
      43,     0,    50,     0,     0,     0,   200,     0,     0,   201,
       0,     0,   202,     0,     0,   150,     0,   144,     0,    44,
       0,     0,   170,     0,     0,     0,     0,     0,     0,   191,
       0,     0,     0,     0,     0,   210,     0,   212,     0,   214,
       0,   145,    45,    47,     0,    48,     0,     0,     0,     0,
       0,     0,    53,   216,   218,   220,    49,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    68,   697,    69,    70,   431,  1025,  1031,
     620,   796,  1175,  1318,   621,  1281,  1344,   622,  1320,   623,
     624,   800,   137,   235,    71,   735,  1062,   958,   498,   361,
     362,   363,   364,   330,   301,   302,    74,    75,    76,    77,
      78,    79,   331,   762,  1241,  1296,   575,  1083,  1086,  1089,
    1261,  1265,  1269,  1307,  1310,  1313,   758,   759,  1071,   863,
     732,   550,   583,    81,    82,    83,    84,   348,   140,   373,
     188,   920,   921,   357,   350,   541,   216,   688,   827,   424,
     425
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1114
static const yytype_int16 yypact[] =
{
    3316,    35,    28,  3398, -1114, -1114,  1736,    63,    47,   -60,
       1,    79,    97,   108,  -104,    -4,    41,   -61,    53,    64,
     -46,    84,    88,    61,   116,   247,   263,   270,    76,   289,
     689,   143,   222,   316,   252,   227,   296,   296,   253,   415,
     271,   381,   396,   395,    11,   345,   400,   450,   451,   458,
     323,   331,   332,    18,    29, -1114,   336, -1114,   489,   339,
   -1114,   505,   509,    26,    30,   379,   387,   390, -1114, -1114,
   -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114,
   -1114, -1114, -1114, -1114, -1114, -1114,    22,   388,    33, -1114,
   -1114, -1114,   351,   358,   368,   399,   437,   447,   482,   508,
     511,   533,   537,   549,   550,   553,   569,   576,   587,   588,
     597,   600,   622,   394,   412,   417,   420, -1114,   544,   443,
   -1114, -1114, -1114, -1114, -1114, -1114, -1114,  3153,  3153,  3153,
   -1114, -1114,  3153,  2698,     9,   536,    38,  3153,   557,   929,
   -1114,   593,   598,  3153,   606, -1114,  3153, -1114, -1114, -1114,
    3153,  3080,  3153,  3153,   499,  3153,  3080,  3153,  3153,   514,
    3080,  3153,  3153,  2069,   521,   518,   529,   530,  1791,  1791,
    1791,   542, -1114, -1114, -1114, -1114,   570,   581,   596,   718,
    2069,   741,   296,   296,   296,  3153,  3153,   -69, -1114,   208,
     296,   624,   625,   643,  2941,   241,   -96,   607,   674,  1791,
    2069,   692,    19,   687, -1114,   830, -1114,   690,   712,   737,
     852,  3153,  3153,  3153,   715,  3153,   729,   784,  3153,  3153,
   -1114,  3153,   881, -1114,   903, -1114,   932, -1114,  2069,   441,
     441,   797,  3153,   936,   795, -1114, -1114, -1114,   937,  3153,
    3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,
    3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,
    3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,
    3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,
    3153,   441,   441,   441,   441,  3153,   939,   582,   806,   806,
     806,  5390,    52,  3080,  4654,   215,   802,   941,   807,   804,
   -1114,   805,  2930,  1146, -1114, -1114,  3153,  3153,  3153,  3153,
    3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,  3153,
    3153, -1114, -1114,  1180,    -3,  3952,  5411,   534,   808,  3080,
   -1114, -1114,  1785, -1114,   434,  5432,  5453,  3153,  5474,   617,
    5495,  5516,  3153,   621,  5537,  5558,  2208,  1576,  2276,   945,
   -1114,  3153,  3153,  3153,  3153, -1114, -1114,   947,   951,   951,
    3153,   820,   822,   823,   824,  3153,  3153,  3153,   825,   959,
     827,   -35, -1114, -1114,  3978,  4004,   296,   296,    38,    38,
     198,  3153,  3153,  3153,  2941,  2941,  3153,  2930,   343, -1114,
    3153,  3153,  3153,  3153,   961,   963,  3153,   965, -1114,  3153,
    3153,   793, -1114,  3080,  3153,  3153, -1114,  5579,  5600,  5621,
     879,  4030, -1114,   831,  2415,  5642,  4677, -1114, -1114,  1143,
   -1114,  1966,   833,   626,   836, -1114,   845,  3153,  4700,   153,
    3153,     5, -1114,  5663,  4723,  5684,  4746,  5705,  4769,  5726,
    4792,  5747,  4815,  5768,  4838,  5789,  4861,  5810,  4884,  5831,
    4907,  5852,  4930,  5873,  4953,  4056,  4082,  5894,  4976,  5915,
    4999,  5936,  5022,  5957,  5045,  5978,  5068,  5999,  5091,  4108,
    4134,  4160,  4186,  4212,  4238,   136,   843,   849,   850,  1203,
     846,  3153, -1114,  2069,  2069,   647,    83,    33,  3153,   989,
     992,    20,   854, -1114,   -82,   -27,   -23,   -43, -1114, -1114,
    2552,   794,   573,   763,   763,   513,   513,   513,   513,   234,
     234,   806,   806,   806,   806, -1114,     6,  3080,  3153,   993,
    2903,  3153,   806, -1114,  3153,  3080,  3080,   902,   996,   997,
    6020,   999,   908,  1001,  1002,  6041,   911,  1004,  1005,  3080,
   -1114,   651,  2347,  3153,  6062,  2934,  6083,  6104,  3153,  2069,
    1011,  1010,  6125,  3213,  3213,  3213,  3213,  6146,  6167,  6188,
     873, -1114,  2069,   296,  3153,  3153, -1114, -1114,   870,   871,
    3153,  4264,  4290,  4316,  3926,   313,   296,  2105,  6209,  3006,
    6230,  6251,  3153,  1014,  3153,  6272, -1114,  5114,  5137, -1114,
     652,  5160,  5183,  1016,  1017,  1018,   882,  3153,  2244,  3153,
    3153, -1114,    32, -1114, -1114,  2069,  3153,  1026,  1025,  1027,
    5206,    45, -1114,  3073, -1114,   893,   895,   889, -1114,  1031,
   -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114,
   -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114,
   -1114, -1114, -1114, -1114, -1114, -1114, -1114,  3153,  3153, -1114,
   -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114,
   -1114,  3153,  3153,  3153,  3153,  3153,  3153, -1114,  3080,   441,
   -1114, -1114, -1114,  3153,  5229,  1032,  1033,   897, -1114,    94,
    3153,  1036,  1037,  1344, -1114,  1038,   904,    18,  1041, -1114,
    3080,  3080,  3080,  3080,  3153, -1114,   917,   441,   148,  4342,
     296, -1114,  3080,  3146,  2619,   806, -1114,  1785, -1114,  1012,
    2069,  2069,  1058,  2069,   749,  2069,  2069,  1059,   994,  2069,
    2069,   656, -1114,  3080,  1380,  1060,  1062,  1063,  1064,  1766,
   -1114, -1114,  1068, -1114,  1069,   934,  6503, -1114,   938,   940,
     942,  1070,  1071,  1075,  1080,   943,   355,  4368,  4394, -1114,
   -1114,  3179,   296,   296,   296,  1079,   944,   946,   -36, -1114,
     375, -1114,   313,  1085,  1081,  1086,  1088,  6503, -1114,  1419,
     949,  1091,  1092,  1048,  1096,  1100,  2069,  2069,  2069,  1104,
    4420, -1114,  2691,   655,  1105,  1106,   964,  5252, -1114,   966,
     967,  1109,  1113, -1114,  1112, -1114,   979,  3153,  3153,  2069,
     973, -1114,  6293,  5275,  6314,  5298,  6335,  5321,  6356,  5344,
     196,   980,  6377,   180, -1114, -1114,    67,   320,   981,  1116,
    1439, -1114, -1114, -1114,    18,  3153, -1114,   661, -1114,   664,
     667,   672,   675,  6503, -1114,  1118,    15,  3153,     4,   676,
   -1114,  3153,   982,  1067,  1067,  2069,  1121,   983,   985,  1122,
    1128,  2069,   990,  1130,  1132, -1114,   679, -1114,  1134,  2069,
    2069,  2069,  1136,  1135, -1114,  2069,  1139,  1141,  1147,  1151,
    2069,  2069,  2069,   411,  1138,  3153,  3153,  3153,  1006,    68,
     150,   322, -1114,  2069,  3153, -1114, -1114,  2941,   -19,  1930,
   -1114,  1019,  2486, -1114,  3080, -1114, -1114,  1020, -1114, -1114,
    1153,  1157,  1073, -1114,  3153,  3153,  3153, -1114,  1158,  1162,
    1159,  1029,  2069,  2069, -1114,   153, -1114,  3153,  4446,  4472,
     680, -1114,  3153, -1114, -1114, -1114, -1114, -1114, -1114, -1114,
   -1114, -1114, -1114, -1114,  2069,    33,  3153,  1164,  1170,    20,
   -1114,  1169,  5367,    18, -1114,  1171,  1173,  1174,  1175, -1114,
   -1114,   441,  4498, -1114,  1039,  6503,  3153,   296,  1177,  1182,
    1193, -1114,  3153,  3153, -1114, -1114,  1195,  3153, -1114, -1114,
   -1114,  1199,  1202,  1207,  1077,  3153, -1114,  1208,  2069,  2069,
    2069,  2069,  1210,  1213,  1212, -1114,  3213,  1078,  3394,  6398,
    2725,    38,   296,  1214,   296,  1215,   296,  1216,   280,  1082,
    6419,  3422,   386, -1114,  1218,  1351,  1221,   296,  1351,  1224,
     703,  3153, -1114, -1114,  2069,  2757,   627,  6440, -1114,  2764,
   -1114,  1227,  1094,  1095, -1114,   274,  6503,  3153,  3153,  2069,
    1097,   716,  6503,  1226,  1232,  1551, -1114,  1235,  1237, -1114,
    1101, -1114, -1114, -1114, -1114, -1114,  1241,  3153, -1114,  3450,
     299, -1114, -1114, -1114,  3478,  3506, -1114,  3534,  1243, -1114,
   -1114,  1200,  1245,  6503, -1114,  1246,  1247,  1248,  1251, -1114,
    1115,  1253, -1114,  1658,  1257,  1260,  1137, -1114,  3153, -1114,
    1133,   392, -1114,  1140,   398, -1114,  1142,   423, -1114,  1148,
    1276,  2069,  1279,  1150,  3153, -1114,  2625,   440, -1114,   442,
     444, -1114,  1277,  3562,  1194,  3153, -1114,  3153, -1114, -1114,
    3080,  1859,  1284, -1114,  2069,  2069, -1114,  3153,  4524,  4550,
   -1114,  2069,  3153,  1287, -1114, -1114, -1114,    18, -1114,  1197,
   -1114,  4576,  1292,  1294,  1309,  1310,  1311,  1191, -1114, -1114,
   -1114, -1114, -1114,  2069, -1114, -1114, -1114, -1114,    38,  2878,
   -1114,  2941,   313,  2941,   313,  2941,   313, -1114,   717,  2069,
   -1114,  3590,   296,  3080,   296, -1114, -1114,  3153,  3618,  3646,
     720, -1114, -1114,  1172,  1192,  1196,  6503,  3153,  3153,   726,
    6503, -1114,  1312, -1114,  3153, -1114, -1114, -1114, -1114, -1114,
    3153,   727,  1198,  3153, -1114,  3674,   466,   -16,  3702,   472,
     135,  3730,   475,   147,  2069,  1333,  1280,  2383,  1201,   483,
     734,   485,  1998, -1114, -1114,  1335,  1338,  1341,  3153,  6461,
    4602,    31, -1114,  4628,  3758,  1345, -1114,  3786,  1346,  3153,
    1347,  1350,  3153,  1352,  1353,  3153,  1357,  1209, -1114,  3153,
   -1114,   313, -1114,  3080,  1358,  2625, -1114, -1114, -1114, -1114,
     755, -1114,  3153, -1114,  2069,  3153, -1114, -1114,  1382, -1114,
   -1114,  1204,  3814, -1114, -1114,  1242,  3842, -1114, -1114,  1244,
    3870, -1114,  1386,  2137,   149,  2522,   758, -1114,   503,   759,
    1387,  1252,  6482,   762,  3898, -1114,   313,  1388,   313,  1389,
     313,  1392, -1114, -1114, -1114, -1114,   313,  1394,  3080,  1396,
   -1114,   441, -1114,  1256,  1401,   202, -1114,  1261,   210, -1114,
    1262,   243, -1114,  1264,   287, -1114,   766, -1114,   767, -1114,
    1265,  2069, -1114,  1407,   313,  1408,   313,  1412,   313, -1114,
    1413,   441,  1420,   441,   783, -1114,   340, -1114,   349, -1114,
     383, -1114, -1114, -1114,   786, -1114,  1421,  1424,  1425,  1427,
     441,  1429, -1114, -1114, -1114, -1114, -1114, -1114
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1114, -1114, -1114, -1114,   602, -1114, -1114, -1114, -1114,   218,
   -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114, -1114,
   -1114, -1114,  -292,    21, -1114,   -52, -1114,   595,  1437, -1114,
   -1114, -1114, -1114,     3,  -374,  -193, -1114, -1114, -1114, -1114,
   -1114, -1114,  1438, -1114, -1114, -1114, -1114, -1114, -1114, -1114,
   -1114, -1114, -1114, -1114, -1114, -1114,  -660,  -713,   217, -1114,
   -1114,  1084, -1114, -1114, -1114, -1114, -1114,    -6, -1114,   -20,
   -1114, -1113,   545,   -81,   291,   -83,  -667,   507, -1114,  -228,
      12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     139,   387,   426,   488,   568,   569,    73,   145,  1179,   614,
     953,   401,   695,   295,   154,   202,   187,   189,   141,   195,
     826,   950,   214,   397,   686,   398,   231,   138,     5,   159,
    1191,   224,   419,   217,   421,   226,   150,  1253,   237,   784,
     755,     4,   299,   151,   390,   886,   756,   757,   154,   423,
     237,   391,   159,   475,   476,   477,   478,   755,   150,   483,
     755,   376,   377,   756,   757,   690,   756,   757,   334,   113,
     114,   115,   116,   339,   678,   117,   142,   343,   378,   155,
     144,   113,   114,   115,   116,   147,   156,   117,   358,   359,
     678,   615,   616,   617,   618,   376,   377,   162,   817,   143,
     238,   160,   888,   148,   693,   296,   297,    35,    36,    37,
      38,   563,   885,   155,   149,   203,    43,   163,   394,    46,
     691,   288,   289,   290,   692,   168,   291,   294,   169,  1003,
     170,   303,  1230,   696,   376,   377,   152,   323,   516,   300,
     325,  1283,   696,   517,   326,   332,   335,   336,   146,   338,
     332,   340,   341,   619,   332,   344,   345,   941,   204,   130,
     131,   399,   371,   372,   232,   215,   233,   687,   164,   218,
     380,   234,   484,   225,   388,   886,   785,   227,  1254,   374,
     375,   153,   130,   131,   123,   124,   125,   126,   375,   792,
     818,   819,   176,   157,   680,   177,   577,   178,   376,   377,
     123,   124,   125,   126,   158,   407,   408,   409,  1334,   411,
     485,   755,   414,   415,   992,   416,   993,   756,   757,   598,
     130,   131,   487,   755,   161,   755,   428,   679,   162,   756,
     757,   756,   757,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   196,  1041,   667,   755,   479,
     376,   377,   668,  1233,   756,   757,   755,   332,   524,   836,
     130,   131,   756,   757,   526,  1236,   994,  1294,   995,   165,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   166,   489,   130,   131,   755,
     590,   197,   167,   522,   792,   756,   757,   935,   376,   377,
     198,   530,   123,   124,   125,   126,   535,   931,   376,   377,
     522,   332,   526,   171,   570,   544,   545,   546,   547,   205,
    1323,   206,   130,   131,   552,   379,   566,   567,  1325,   557,
     558,   559,   179,   755,   372,   180,   317,   318,   319,   756,
     757,   376,   377,   320,   182,   571,   572,   573,   288,   289,
     574,   300,   300,   794,   578,   579,   580,   581,   389,   755,
     585,  1327,   181,   587,   588,   756,   757,   332,   591,   592,
     190,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   542,   318,   319,  1116,   755,   985,   986,   320,
    1117,   610,   756,   757,   613,   755,   183,   184,  1090,   376,
     377,   756,   757,   199,   698,  1329,   185,   123,   124,   125,
     126,   811,   333,   186,   201,   423,   237,   333,   200,   207,
     612,   333,   376,   377,   208,   209,   721,   130,   131,   755,
    1182,   191,   210,   211,   192,   756,   757,   193,   996,   835,
     997,   212,   213,   376,   377,   674,   219,   113,   114,   115,
     116,   221,   683,   117,   886,   376,   377,   886,  1347,   576,
     886,   239,  1197,   240,  1200,   220,  1203,  1348,   241,   682,
     242,   875,   738,   739,   740,   376,   377,   681,   243,   222,
     244,   332,   699,   223,   674,   703,   376,   377,   704,   705,
     707,   887,   376,   377,   934,   936,   228,   229,   376,   377,
     230,  1349,  1094,   332,   281,   236,   705,   724,  1151,   245,
     298,   246,   729,   746,  1153,   183,   184,   736,   736,   736,
     736,   285,   282,   376,   377,   185,   760,   283,   747,   748,
     284,   886,   194,   304,   751,   737,   737,   737,   737,  1155,
     376,   377,   376,   377,   376,   377,   767,   247,   769,   248,
     526,  1274,   527,   286,   333,   810,  1162,   249,  1163,   250,
    1164,   780,   886,   782,   783,   886,   376,   377,   886,   321,
     787,   886,   376,   377,   322,   376,   377,   829,   830,   831,
     832,   324,  1229,   376,   377,   376,   377,  1080,  1232,   839,
     523,  1235,   251,   886,   252,   886,  1305,   886,  1308,  1243,
    1311,  1245,   793,   376,   377,  1107,  1314,   523,   333,   337,
     856,   802,   803,   315,   316,   317,   318,   319,   253,  1298,
     254,   255,   320,   256,   342,   804,   805,   806,   807,   808,
     809,   351,   332,   906,  1336,   352,  1338,   812,  1340,   353,
     354,   130,   131,   257,   820,   258,   520,   259,   233,   260,
     838,   136,   360,   234,   332,   332,   332,   332,   833,   261,
     263,   262,   264,   265,   333,   266,   332,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   349,   267,
     365,   268,   320,   356,   356,   356,   269,   332,   270,   130,
     131,   366,   368,  1046,   481,   369,   233,   271,   273,   272,
     274,   234,   879,   880,   881,   172,   367,   275,   173,   276,
     277,   174,   278,   175,   356,   395,   370,   392,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   279,   526,   280,   532,   320,   526,   606,   536,
     607,   381,   382,   422,  1192,  1108,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     383,   918,   919,   526,   320,   677,   907,   526,   526,   722,
     773,   847,   526,   848,   855,     7,     8,   943,   333,   944,
     526,  1010,   945,   526,   393,   946,   706,   708,   526,   942,
     947,   526,   526,   948,   954,   526,  1029,   970,  1030,   400,
     333,   952,   396,   706,   793,   955,   402,   403,   937,   494,
      15,    16,   495,    18,    19,   496,    21,   497,    23,   526,
      24,  1102,    26,    27,   404,    29,    30,    31,   406,   410,
      33,    34,  1122,  1204,  1123,  1205,   526,  1002,  1215,   988,
     989,   990,  1029,  1029,  1221,  1225,   412,   998,  1000,   405,
     526,  1001,  1244,   413,    50,    51,    52,   417,   332,   311,
     312,   313,   314,   315,   316,   317,   318,   319,  1015,  1016,
    1017,  1122,   320,  1280,   526,   526,  1297,  1299,  1029,   418,
    1303,  1026,   526,  1331,  1330,  1332,  1032,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,  1029,
    1035,  1346,  1350,   320,  1351,   305,  1024,  1050,   420,   427,
     429,   589,   430,   432,   480,   320,   490,  1034,   491,   492,
    1049,   136,   543,   493,   548,   521,  1054,  1055,   549,   333,
     553,  1057,   554,   555,   556,   561,   560,  1207,   582,  1063,
     584,   586,  1081,   562,  1084,   596,  1087,   608,   599,   605,
    1073,   333,   333,   333,   333,  1097,   609,  1099,  1100,   669,
     670,   671,   673,   333,   300,   684,   685,   689,  1074,   332,
     700,   709,   332,   710,   711,  1103,   713,   714,   715,   716,
     718,   719,   720,  1111,   333,   731,   733,   744,   749,   750,
     768,  1118,  1119,   776,   777,   778,   779,  1170,   675,   676,
     788,  1112,   789,   797,   790,   798,   799,   801,   814,   815,
     816,  1131,   821,   822,   834,   824,   825,   828,   852,  1275,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   842,   845,   851,   858,   320,   859,
     860,   861,  1149,  1319,   864,   866,   865,   870,   871,   867,
    1210,   868,   872,   869,   873,   882,   884,   890,  1161,   874,
     522,   883,   889,   891,   730,   892,   894,   895,   896,  1168,
     897,  1169,   898,  1342,   332,  1345,   899,   745,   903,   908,
     909,  1176,   910,   912,   913,   914,  1180,   915,   916,   917,
     922,   932,  1356,   939,   949,   938,   957,   961,   964,   956,
     962,  1196,   963,  1199,   965,  1202,   968,   967,   969,   971,
     975,   976,  1209,   987,  1211,  1195,   978,  1198,   979,  1201,
     786,   300,   499,   991,   980,     7,     8,   332,   981,  1012,
    1276,  1212,  1279,  1013,  1018,  1020,  1007,  1011,  1014,  1019,
    1036,  1219,  1220,  1021,  1037,  1039,  1061,  1042,  1223,  1043,
    1044,  1045,  1048,  1051,  1224,   333,   515,  1227,  1052,   494,
      15,    16,   495,    18,    19,   496,    21,   497,    23,  1053,
      24,  1056,    26,    27,  1058,    29,    30,    31,  1059,   672,
      33,    34,  1032,  1060,  1064,  1316,  1069,  1070,  1072,  1075,
    1082,  1085,  1088,  1262,  1095,  1278,  1266,  1098,  1091,  1270,
    1101,  1113,  1124,  1273,    50,    51,    52,   332,  1125,   332,
    1114,  1115,  1127,  1128,  1121,  1129,  1282,  1130,  1136,  1284,
    1137,  1138,  1139,  1140,  1141,   843,   844,  1142,   846,  1144,
     849,   850,  1143,  1146,   853,   854,  1147,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,  1150,  1157,  1165,  1148,   320,  1159,  1152,  1167,  1154,
    1172,   603,   332,  1181,  1183,  1156,   333,  1160,  1185,   333,
    1186,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,  1187,  1188,  1189,  1222,   320,
    1216,   900,   901,   902,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,  1190,  1238,
    1217,  1247,   320,  1218,  1248,  1239,  1226,  1249,  1242,  1257,
     823,  1286,  1260,  1263,    85,   327,  1264,  1272,  1267,  1268,
      89,    90,    91,  1271,  1277,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   857,   523,  1285,  1288,
     960,  1290,  1292,  1300,  1306,  1309,   966,   328,  1312,  1301,
    1315,   333,  1317,  1321,   972,   973,   974,  1322,  1324,  1326,
     977,  1328,  1333,  1335,  1337,   982,   983,   984,  1339,  1341,
      35,    36,    37,    38,    39,   893,  1343,  1352,   999,    43,
    1353,  1354,    46,  1355,  1006,  1357,  1250,  1009,   951,   959,
      72,    80,  1258,   551,     0,   940,  1038,     0,     0,     0,
       0,     0,     0,     0,   333,     0,     0,  1022,  1023,     0,
       0,   119,   120,   121,   122,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,  1033,
       0,   384,  1096,   320,     0,     0,   129,     0,     0,     0,
       0,   386,     0,     0,     0,     0,   135,     0,   186,   540,
       0,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,  1065,  1066,  1067,  1068,     0,     0,     0,
       0,     0,     0,     0,   333,     0,   333,     0,     0,     0,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,  1126,   320,  1104,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,  1120,     0,     0,     0,   320,    85,
     327,     0,     0,     0,     0,    89,    90,    91,     0,   333,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   328,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1158,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    36,    37,    38,    39,
       0,     0,     0,     0,    43,     0,     0,    46,     0,  1173,
    1174,     0,     0,     0,  1145,     0,     0,     0,     0,     0,
       0,     0,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   119,   120,   121,   122,
     320,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1206,     0,   127,   329,     0,     0,
       0,   129,     0,     0,     0,     0,   132,     0,     0,     0,
       0,   135,     0,     0,   540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,     0,    88,     0,    89,    90,    91,     0,  1237,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,     0,     0,   117,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   524,    85,   327,   355,   320,     0,     0,
      89,    90,    91,     0,     0,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,     0,     0,     0,
       0,   862,     0,     0,     0,     0,     0,   328,     0,     0,
     118,     0,     0,     0,     0,     0,   119,   120,   121,   122,
       0,     0,     0,   123,   124,   125,   126,     0,     0,     0,
      35,    36,    37,    38,    39,  1171,   127,   128,     0,    43,
       0,   129,    46,   130,   131,     0,   132,     0,   133,     0,
     134,   135,     0,   136,     0,     0,     0,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   119,   120,   121,   122,   320,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   525,   318,   319,
       0,   127,   346,     0,   320,     0,   129,     0,     0,     0,
       0,   132,     0,    85,   327,  1004,   135,     0,   347,    89,
      90,    91,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   328,     0,     7,     8,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,    35,
      36,    37,    38,    39,  1246,     0,     0,     0,    43,     0,
       0,    46,   494,    15,    16,   495,    18,    19,   496,    21,
     497,    23,     0,    24,     0,    26,    27,     0,    29,    30,
      31,     0,     0,    33,    34,     0,     0,     0,     0,     0,
     119,   120,   121,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    52,
     127,   346,     0,     0,     0,   129,     0,     0,     0,     0,
     132,     0,    85,   327,     0,   135,     0,  1005,    89,    90,
      91,     0,     0,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   604,   328,     0,     7,     8,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,    35,    36,
      37,    38,    39,  1293,     0,     0,     0,    43,     0,     0,
      46,   494,    15,    16,   495,    18,    19,   496,    21,   497,
      23,     0,    24,     0,    26,    27,     0,    29,    30,    31,
       0,     0,    33,    34,     0,     0,     0,     0,     0,   119,
     120,   121,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,   127,
     346,     0,     0,     0,   129,     0,     0,     0,     0,   132,
       0,    85,   327,     0,   135,     0,   347,    89,    90,    91,
       0,     0,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   761,   328,     0,     7,     8,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,    35,    36,    37,
      38,    39,     0,     0,   524,     0,    43,     0,     0,    46,
     494,    15,    16,   495,    18,    19,   496,    21,   497,    23,
       0,    24,     0,    26,    27,     0,    29,    30,    31,     0,
       0,    33,    34,     0,     0,     0,     0,     0,   119,   120,
     121,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    51,    52,   127,   329,
       0,     0,     0,   129,     0,     0,     0,     0,   132,     0,
      85,   327,     0,   135,     0,   539,    89,    90,    91,     0,
       0,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   781,   328,     0,     7,     8,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   542,   318,
     319,     0,     0,     0,     0,   320,    35,    36,    37,    38,
      39,     0,     0,   600,     0,    43,     0,     0,    46,   494,
      15,    16,   495,    18,    19,   496,    21,   497,    23,     0,
      24,     0,    26,    27,     0,    29,    30,    31,     0,     0,
      33,    34,     0,     0,     0,     0,     0,   119,   120,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,    52,   127,   329,     0,
       0,     0,   129,     0,     0,     0,     0,   132,     0,    85,
     327,     0,   135,     0,   723,    89,    90,    91,     0,     0,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1240,   328,     0,     7,     8,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,    35,    36,    37,    38,    39,
     694,     0,     0,     0,    43,     0,     0,    46,   494,    15,
      16,   495,    18,    19,   496,    21,   497,    23,     0,    24,
       0,    26,    27,     0,    29,    30,    31,     0,     0,    33,
      34,     0,     0,     0,     0,     0,   119,   120,   121,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,   127,   346,     0,     0,
       0,   129,     0,     0,     0,     0,   132,   841,    85,   327,
       0,   135,     0,  1008,    89,    90,    91,     0,     0,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1295,   328,     0,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,    35,    36,    37,    38,    39,   905,
       0,    85,   287,    43,     0,     0,    46,    89,    90,    91,
       0,     0,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,     0,   119,   120,   121,   122,     0,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,   384,  1096,     0,   320,     0,
     129,     0,     0,     0,     0,   386,     0,    85,   287,   237,
     135,     0,   186,    89,    90,    91,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     113,   114,   115,   116,     0,     0,   117,     0,   119,   120,
     121,   122,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,   127,   128,
     320,     0,     0,   129,     0,     0,     0,     0,   132,     0,
       0,   292,     0,   135,     0,   293,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,     0,     0,     0,     0,
       0,  1078,     0,  1079,   119,   120,   121,   122,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,   127,   128,   320,     0,     0,   129,
       0,     0,     0,  1105,   132,  1106,    85,   287,     0,   135,
       0,  1110,    89,    90,    91,     0,     0,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,     0,
       0,     0,     7,     8,    85,   287,     0,     0,     0,     0,
      89,    90,    91,     0,     0,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   494,    15,    16,   495,
      18,    19,   496,    21,   497,    23,     0,    24,     0,    26,
      27,     0,    29,    30,    31,     0,     0,    33,    34,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   119,   120,   121,   122,   320,     0,     0,
       0,    50,    51,    52,  1193,     0,  1194,     0,     0,     0,
       0,     0,     0,   127,   128,     0,     0,     0,   129,     0,
       0,     0,     0,   132,     0,     0,   701,     0,   135,     0,
     702,   119,   120,   121,   122,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,   384,   385,   320,     0,     0,   129,     0,     0,     0,
       0,   386,   726,    85,   327,     0,   135,     0,   186,    89,
      90,    91,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   328,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,    35,
      36,    37,    38,    39,   764,     0,    85,   287,    43,     0,
       0,    46,    89,    90,    91,     0,     0,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,     0,
     119,   120,   121,   122,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
     127,   329,   320,     0,     0,   129,    85,   287,   237,     0,
     132,   795,    89,    90,    91,   135,     0,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,   119,   120,   121,   122,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,   127,   128,   320,     0,     0,   129,     0,
       0,     0,     0,   132,   840,     0,     0,     0,   135,     0,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,    -4,     1,   320,     0,
      -4,     0,     0,   119,   120,   121,   122,   878,    -4,    -4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,   128,     0,     0,     0,   129,     0,
       0,    -4,     0,   132,     0,     0,    -4,    -4,   135,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
      -4,    -4,     6,     0,     0,     0,    -4,    -4,    -4,    -4,
       7,     8,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,     0,
      -4,    -4,    -4,     9,     0,     0,     0,     0,    10,    11,
       0,    12,    13,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,    45,    46,
       0,     0,    47,    48,     0,     0,     0,     0,    49,    50,
      51,    52,     0,     0,    53,     0,    54,     0,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,    65,    66,    67,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
       0,     0,  1076,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,     0,     0,
    1093,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,     0,     0,  1132,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,     0,     0,  1133,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,     0,     0,  1134,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
       0,     0,  1135,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,     0,     0,
    1166,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,     0,     0,  1208,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,     0,     0,  1213,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,     0,     0,  1214,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
       0,     0,  1228,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,     0,     0,
    1231,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,     0,     0,  1234,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,     0,     0,  1256,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,     0,     0,  1259,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
       0,     0,  1287,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,     0,     0,
    1289,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,     0,     0,  1291,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,     0,     0,  1304,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,   482,     0,     0,
       0,     0,   564,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,   518,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,   564,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
     565,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,   597,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,   647,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,   648,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,   661,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
     662,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,   663,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,   664,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,   665,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,   666,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
     752,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,   753,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,   754,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,   837,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,   876,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
     877,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,   904,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,  1027,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,  1028,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,  1047,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
    1177,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,  1178,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,  1184,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,  1252,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,  1255,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,   486,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,     0,     0,
     602,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,   611,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,     0,     0,   626,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,   628,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
       0,     0,   630,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,   632,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,     0,     0,   634,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,   636,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,     0,     0,   638,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,   640,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,     0,     0,
     642,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,   644,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,     0,     0,   646,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,   650,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
       0,     0,   652,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,   654,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,     0,     0,   656,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,   658,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,     0,     0,   660,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,   771,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,     0,     0,
     772,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,   774,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,     0,     0,   775,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,   791,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
       0,     0,   813,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,   911,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,     0,     0,   924,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,   926,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,     0,     0,   928,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,   930,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,     0,     0,
    1040,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,   482,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,   519,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,   528,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,   529,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,   531,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,   533,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,   534,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,   537,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,   538,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
     593,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,   594,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,   595,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,   601,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,   625,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,   627,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,   629,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,   631,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,   633,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,   635,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
     637,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,   639,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,   641,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,   643,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,   645,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,   649,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,   651,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,   653,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,   655,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,   657,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
     659,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,   712,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,   717,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,   725,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,   727,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,   728,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,   734,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,   741,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,   742,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,   743,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
     763,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,   765,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,   766,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,   770,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,   923,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,   925,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,   927,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,   929,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,   933,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,  1077,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
    1092,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,  1109,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,  1251,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,  1302,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320
};

static const yytype_int16 yycheck[] =
{
       6,   194,   230,   295,   378,   379,     3,     6,  1121,     4,
       6,   204,     6,     4,    75,     4,    36,    37,     6,    39,
     687,     6,     4,     4,     4,     6,     4,     6,     0,    75,
    1143,     5,   225,     4,   227,     5,   140,     6,     5,     7,
      76,     6,     4,   147,   140,   758,    82,    83,    75,     4,
       5,   147,    75,   281,   282,   283,   284,    76,   140,     7,
      76,   130,   131,    82,    83,   147,    82,    83,   151,    36,
      37,    38,    39,   156,     7,    42,    13,   160,   147,   140,
     140,    36,    37,    38,    39,     6,   147,    42,   169,   170,
       7,    86,    87,    88,    89,   130,   131,   140,     4,    52,
      88,   147,   762,     6,   147,    96,    97,    69,    70,    71,
      72,   146,   148,   140,     6,   104,    78,    56,   199,    81,
     147,   127,   128,   129,   147,    49,   132,   133,    52,   148,
      54,   137,   148,   127,   130,   131,   140,   143,   141,   136,
     146,  1254,   127,   146,   150,   151,   152,   153,   147,   155,
     156,   157,   158,   148,   160,   161,   162,   824,   147,   137,
     138,   142,   182,   183,   142,   147,   144,   147,    52,   140,
     190,   149,   120,   147,   194,   888,   144,   147,   147,   185,
     186,   140,   137,   138,   117,   118,   119,   120,   194,   144,
      96,    97,    49,   140,   486,    52,   389,    54,   130,   131,
     117,   118,   119,   120,   140,   211,   212,   213,  1321,   215,
     293,    76,   218,   219,   146,   221,   148,    82,    83,   412,
     137,   138,     7,    76,   140,    76,   232,   144,   140,    82,
      83,    82,    83,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,     4,   943,   141,    76,   285,
     130,   131,   146,   148,    82,    83,    76,   293,     8,   141,
     137,   138,    82,    83,   146,   148,   146,   148,   148,    52,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,    52,   295,   137,   138,    76,
     403,    50,    52,   329,   144,    82,    83,     7,   130,   131,
      59,   337,   117,   118,   119,   120,   342,   141,   130,   131,
     346,   347,   146,    54,   146,   351,   352,   353,   354,     4,
     148,     6,   137,   138,   360,   147,   376,   377,   148,   365,
     366,   367,   140,    76,   384,    49,   132,   133,   134,    82,
      83,   130,   131,   139,   147,   381,   382,   383,   384,   385,
     386,   378,   379,   611,   390,   391,   392,   393,   147,    76,
     396,   148,   140,   399,   400,    82,    83,   403,   404,   405,
     147,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   141,    76,     6,     7,   139,
     146,   427,    82,    83,   430,    76,   130,   131,   148,   130,
     131,    82,    83,    52,   517,   148,   140,   117,   118,   119,
     120,   669,   151,   147,    49,     4,     5,   156,    52,    49,
     429,   160,   130,   131,     4,     4,   539,   137,   138,    76,
    1127,    46,     4,   140,    49,    82,    83,    52,   146,   697,
     148,   140,   140,   130,   131,   481,   140,    36,    37,    38,
      39,   142,   488,    42,  1197,   130,   131,  1200,   148,   146,
    1203,   140,  1152,   142,  1154,     6,  1156,   148,   140,   487,
     142,   146,   554,   555,   556,   130,   131,   486,   140,     4,
     142,   517,   518,     4,   520,   521,   130,   131,   524,   525,
     526,   146,   130,   131,   816,   817,   147,   140,   130,   131,
     140,   148,   146,   539,   140,   147,   542,   543,   146,   140,
       4,   142,   548,   563,   146,   130,   131,   553,   554,   555,
     556,     7,   140,   130,   131,   140,   576,   140,   564,   565,
     140,  1274,   147,     6,   570,   553,   554,   555,   556,   146,
     130,   131,   130,   131,   130,   131,   582,   140,   584,   142,
     146,  1241,   148,   140,   293,   668,   146,   140,   146,   142,
     146,   597,  1305,   599,   600,  1308,   130,   131,  1311,     6,
     606,  1314,   130,   131,     6,   130,   131,   690,   691,   692,
     693,     5,   146,   130,   131,   130,   131,   991,   146,   702,
     329,   146,   140,  1336,   142,  1338,  1286,  1340,  1288,   146,
    1290,   146,   611,   130,   131,     8,  1296,   346,   347,   140,
     723,   647,   648,   130,   131,   132,   133,   134,   140,   146,
     142,   140,   139,   142,   140,   661,   662,   663,   664,   665,
     666,   140,   668,     8,  1324,   147,  1326,   673,  1328,   140,
     140,   137,   138,   140,   680,   142,   142,   140,   144,   142,
     700,   147,   140,   149,   690,   691,   692,   693,   694,   140,
     140,   142,   142,   140,   403,   142,   702,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   163,   140,
     140,   142,   139,   168,   169,   170,   140,   723,   142,   137,
     138,   140,     4,   951,   142,   180,   144,   140,   140,   142,
     142,   149,   752,   753,   754,    46,   140,   140,    49,   142,
     140,    52,   142,    54,   199,   200,     5,   140,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   140,   146,   142,   148,   139,   146,   142,   148,
     144,   147,   147,   228,  1148,   148,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     147,   797,   798,   146,   139,   148,   141,   146,   146,   148,
     148,    52,   146,    54,   148,    12,    13,   146,   517,   148,
     146,   894,   148,   146,   140,   148,   525,   526,   146,   825,
     148,   146,   146,   148,   148,   146,   146,   148,   148,   142,
     539,   837,   140,   542,   813,   841,     6,   147,   817,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,   146,
      57,   148,    59,    60,   142,    62,    63,    64,     6,   144,
      67,    68,   146,   146,   148,   148,   146,   887,   148,   875,
     876,   877,   146,   146,   148,   148,   147,   883,   884,   142,
     146,   887,   148,    99,    91,    92,    93,     6,   894,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   904,   905,
     906,   146,   139,   148,   146,   146,   148,   148,   146,     6,
     148,   917,   146,   146,   148,   148,   922,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   146,
     936,   148,   146,   139,   148,     6,   915,   957,     6,   142,
       4,   148,   147,     6,     5,   139,   144,   935,     7,   142,
     956,   147,     7,   148,     7,   147,   962,   963,     7,   668,
     140,   967,   140,   140,   140,     6,   141,  1160,     7,   975,
       7,     6,   992,   146,   994,    96,   996,   141,   147,   146,
     986,   690,   691,   692,   693,  1005,   141,  1007,  1008,   146,
     141,   141,   146,   702,   991,     6,     4,   143,   986,  1005,
       7,    99,  1008,     7,     7,  1011,     7,    99,     7,     7,
      99,     7,     7,  1019,   723,     4,     6,   144,   148,   148,
       6,  1027,  1028,     7,     7,     7,   144,  1110,   483,   484,
       4,  1019,     7,   140,     7,   140,   147,     6,     6,     6,
     143,  1047,     6,     6,   127,     7,   142,     6,    54,  1242,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    52,     7,     7,     7,   139,     7,
       7,     7,  1078,  1301,     6,   141,     7,     7,     7,   141,
    1163,   141,     7,   141,     4,     6,   140,     6,  1094,   146,
    1096,   147,     7,     7,   549,     7,   147,     6,     6,  1105,
      52,  1107,     6,  1331,  1110,  1333,     6,   562,     4,     4,
       4,  1117,   148,   147,   147,     6,  1122,     4,     6,   140,
     147,   141,  1350,     7,     6,   144,    59,     6,     6,   147,
     147,  1151,   147,  1153,     6,  1155,     6,   147,     6,     5,
       4,     6,  1162,     5,  1164,  1151,     7,  1153,     7,  1155,
     605,  1148,     6,   147,     7,    12,    13,  1163,     7,     6,
    1243,  1167,  1245,     6,     6,     6,   147,   147,    95,     7,
       6,  1177,  1178,   144,     4,     6,    99,     6,  1184,     6,
       6,     6,   143,     6,  1190,   894,     6,  1193,     6,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     6,
      57,     6,    59,    60,     5,    62,    63,    64,     6,     6,
      67,    68,  1218,     6,     6,  1298,     6,     4,     6,   141,
       6,     6,     6,  1229,     6,  1245,  1232,     6,   146,  1235,
       6,     4,     6,  1239,    91,    92,    93,  1243,     6,  1245,
     146,   146,     7,     6,   147,   144,  1252,     6,     5,  1255,
      50,     6,     6,     6,     6,   710,   711,     6,   713,     6,
     715,   716,   147,     6,   719,   720,     6,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   148,     6,     6,   147,   139,     7,   147,    94,   147,
       6,   148,  1298,     6,    97,   147,  1005,   147,     6,  1008,
       6,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,     6,     6,     6,     6,   139,
     148,   776,   777,   778,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   147,     6,
     148,     6,   139,   147,     6,    65,   148,     6,   147,     4,
       6,   147,     6,     6,     3,     4,     6,   148,     6,     6,
       9,    10,    11,     6,     6,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     6,  1096,     6,   147,
     845,   147,     6,     6,     6,     6,   851,    46,     6,   147,
       6,  1110,     6,   147,   859,   860,   861,     6,   147,   147,
     865,   147,   147,     6,     6,   870,   871,   872,     6,     6,
      69,    70,    71,    72,    73,     6,     6,     6,   883,    78,
       6,     6,    81,     6,   889,     6,  1218,   892,   836,   844,
       3,     3,  1225,   359,    -1,     6,   939,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1163,    -1,    -1,   912,   913,    -1,
      -1,   110,   111,   112,   113,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   934,
      -1,   130,   131,   139,    -1,    -1,   135,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,   145,    -1,   147,   148,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,   978,   979,   980,   981,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1243,    -1,  1245,    -1,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,     6,   139,  1014,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,  1029,    -1,    -1,    -1,   139,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,  1298,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1091,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,  1114,
    1115,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   110,   111,   112,   113,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1159,    -1,   130,   131,    -1,    -1,
      -1,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,   145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,    -1,     9,    10,    11,    -1,  1204,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    -1,    42,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,     8,     3,     4,     5,   139,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
      -1,    -1,    -1,   117,   118,   119,   120,    -1,    -1,    -1,
      69,    70,    71,    72,    73,     6,   130,   131,    -1,    78,
      -1,   135,    81,   137,   138,    -1,   140,    -1,   142,    -1,
     144,   145,    -1,   147,    -1,    -1,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   110,   111,   112,   113,   139,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,   130,   131,    -1,   139,    -1,   135,    -1,    -1,    -1,
      -1,   140,    -1,     3,     4,     5,   145,    -1,   147,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    12,    13,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    69,
      70,    71,    72,    73,     6,    -1,    -1,    -1,    78,    -1,
      -1,    81,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    -1,    59,    60,    -1,    62,    63,
      64,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
     130,   131,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,
     140,    -1,     3,     4,    -1,   145,    -1,   147,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,    46,    -1,    12,    13,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    69,    70,
      71,    72,    73,     6,    -1,    -1,    -1,    78,    -1,    -1,
      81,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    -1,    59,    60,    -1,    62,    63,    64,
      -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,   130,
     131,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,   140,
      -1,     3,     4,    -1,   145,    -1,   147,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,    46,    -1,    12,    13,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    69,    70,    71,
      72,    73,    -1,    -1,     8,    -1,    78,    -1,    -1,    81,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    -1,    59,    60,    -1,    62,    63,    64,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,   130,   131,
      -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,   140,    -1,
       3,     4,    -1,   145,    -1,   147,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,    46,    -1,    12,    13,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    69,    70,    71,    72,
      73,    -1,    -1,     8,    -1,    78,    -1,    -1,    81,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    -1,    59,    60,    -1,    62,    63,    64,    -1,    -1,
      67,    68,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,   130,   131,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,   140,    -1,     3,
       4,    -1,   145,    -1,   147,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   148,    46,    -1,    12,    13,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    69,    70,    71,    72,    73,
       8,    -1,    -1,    -1,    78,    -1,    -1,    81,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      -1,    59,    60,    -1,    62,    63,    64,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,   130,   131,    -1,    -1,
      -1,   135,    -1,    -1,    -1,    -1,   140,     8,     3,     4,
      -1,   145,    -1,   147,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,    46,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    69,    70,    71,    72,    73,     8,
      -1,     3,     4,    78,    -1,    -1,    81,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,   110,   111,   112,   113,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,   130,   131,    -1,   139,    -1,
     135,    -1,    -1,    -1,    -1,   140,    -1,     3,     4,     5,
     145,    -1,   147,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    42,    -1,   110,   111,
     112,   113,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,   130,   131,
     139,    -1,    -1,   135,    -1,    -1,    -1,    -1,   140,    -1,
      -1,   143,    -1,   145,    -1,   147,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,    -1,   148,   110,   111,   112,   113,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,   130,   131,   139,    -1,    -1,   135,
      -1,    -1,    -1,   146,   140,   148,     3,     4,    -1,   145,
      -1,   147,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    12,    13,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    -1,    59,
      60,    -1,    62,    63,    64,    -1,    -1,    67,    68,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   110,   111,   112,   113,   139,    -1,    -1,
      -1,    91,    92,    93,   146,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,   140,    -1,    -1,   143,    -1,   145,    -1,
     147,   110,   111,   112,   113,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,   130,   131,   139,    -1,    -1,   135,    -1,    -1,    -1,
      -1,   140,   148,     3,     4,    -1,   145,    -1,   147,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    69,
      70,    71,    72,    73,   148,    -1,     3,     4,    78,    -1,
      -1,    81,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
     110,   111,   112,   113,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
     130,   131,   139,    -1,    -1,   135,     3,     4,     5,    -1,
     140,   148,     9,    10,    11,   145,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,   130,   131,   139,    -1,    -1,   135,    -1,
      -1,    -1,    -1,   140,   148,    -1,    -1,    -1,   145,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,     0,     1,   139,    -1,
       4,    -1,    -1,   110,   111,   112,   113,   148,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,    -1,    -1,    -1,   135,    -1,
      -1,    35,    -1,   140,    -1,    -1,    40,    41,   145,    43,
      44,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    85,     4,    -1,    -1,    -1,    90,    91,    92,    93,
      12,    13,    96,    -1,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,
     114,   115,   116,    35,    -1,    -1,    -1,    -1,    40,    41,
      -1,    43,    44,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,    -1,    -1,    96,    -1,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,   114,   115,   116,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,   141,    -1,    -1,
      -1,    -1,   146,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,   143,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
     143,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,   143,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,   143,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,   143,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,   143,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,   143,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,   143,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,   143,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,   143,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,   143,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
     143,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,   143,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,   143,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,   143,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,   143,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,   143,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,   143,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,   143,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,   143,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,   143,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
     143,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,   143,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,   143,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,   143,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,   143,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,   143,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,   143,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,   143,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,   143,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,   143,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
     143,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,   141,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,   141,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,   141,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,   141,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,   141,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,   141,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,   141,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,   141,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,   141,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
     141,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,   141,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,   141,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,   141,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,   141,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,   141,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,   141,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,   141,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,   141,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,   141,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
     141,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,   141,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,   141,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,   141,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,   141,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,   141,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,   141,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,   141,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,   141,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,   141,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
     141,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,   141,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,   141,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,   141,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,   141,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,   141,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,   141,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,   141,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,   141,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,   141,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
     141,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,   141,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,   141,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,   141,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,   141,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,   141,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,   141,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,   141,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,   141,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,   141,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
     141,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,   141,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,   141,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,   141,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   151,   152,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    57,    58,    59,    60,    61,    62,
      63,    64,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    76,    77,    78,    79,    80,    81,    84,    85,    90,
      91,    92,    93,    96,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   114,   115,   116,   153,   155,
     156,   174,   178,   183,   186,   187,   188,   189,   190,   191,
     192,   213,   214,   215,   216,     3,     4,     5,     7,     9,
      10,    11,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    36,    37,    38,    39,    42,   104,   110,
     111,   112,   113,   117,   118,   119,   120,   130,   131,   135,
     137,   138,   140,   142,   144,   145,   147,   172,   173,   217,
     218,   230,    13,    52,   140,     6,   147,     6,     6,     6,
     140,   147,   140,   140,    75,   140,   147,   140,   140,    75,
     147,   140,   140,    56,    52,    52,    52,    52,    49,    52,
      54,    54,    46,    49,    52,    54,    49,    52,    54,   140,
      49,   140,   147,   130,   131,   140,   147,   219,   220,   219,
     147,    46,    49,    52,   147,   219,     4,    50,    59,    52,
      52,    49,     4,   104,   147,     4,     6,    49,     4,     4,
       4,   140,   140,   140,     4,   147,   226,     4,   140,   140,
       6,   142,     4,     4,     5,   147,     5,   147,   147,   140,
     140,     4,   142,   144,   149,   173,   147,     5,   230,   140,
     142,   140,   142,   140,   142,   140,   142,   140,   142,   140,
     142,   140,   142,   140,   142,   140,   142,   140,   142,   140,
     142,   140,   142,   140,   142,   140,   142,   140,   142,   140,
     142,   140,   142,   140,   142,   140,   142,   140,   142,   140,
     142,   140,   140,   140,   140,     7,   140,     4,   217,   217,
     217,   217,   143,   147,   217,     4,    96,    97,     4,     4,
     183,   184,   185,   217,     6,     6,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     139,     6,     6,   217,     5,   217,   217,     4,    46,   131,
     183,   192,   217,   224,   225,   217,   217,   140,   217,   225,
     217,   217,   140,   225,   217,   217,   131,   147,   217,   222,
     224,   140,   147,   140,   140,     5,   222,   223,   223,   223,
     140,   179,   180,   181,   182,   140,   140,   140,     4,   222,
       5,   219,   219,   219,   217,   217,   130,   131,   147,   147,
     219,   147,   147,   147,   130,   131,   140,   185,   219,   147,
     140,   147,   140,   140,   223,   222,   140,     4,     6,   142,
     142,   185,     6,   147,   142,   142,     6,   217,   217,   217,
     144,   217,   147,    99,   217,   217,   217,     6,     6,   185,
       6,   185,   222,     4,   229,   230,   229,   142,   217,     4,
     147,   157,     6,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   229,   229,   229,   229,   217,
       5,   142,   141,     7,   120,   225,   143,     7,   172,   173,
     144,     7,   142,   148,    46,    49,    52,    54,   178,     6,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,     6,   141,   146,   146,   141,
     142,   147,   217,   224,     8,   132,   146,   148,   141,   141,
     217,   141,   148,   141,   141,   217,   148,   141,   141,   147,
     148,   225,   132,     7,   217,   217,   217,   217,     7,     7,
     211,   211,   217,   140,   140,   140,   140,   217,   217,   217,
     141,     6,   146,   146,   146,   146,   219,   219,   184,   184,
     146,   217,   217,   217,   217,   196,   146,   185,   217,   217,
     217,   217,     7,   212,     7,   217,     6,   217,   217,   148,
     225,   217,   217,   141,   141,   141,    96,   146,   185,   147,
       8,   141,   143,   148,   148,   146,   142,   144,   141,   141,
     217,   143,   173,   217,     4,    86,    87,    88,    89,   148,
     160,   164,   167,   169,   170,   141,   143,   141,   143,   141,
     143,   141,   143,   141,   143,   141,   143,   141,   143,   141,
     143,   141,   143,   141,   143,   141,   143,   146,   146,   141,
     143,   141,   143,   141,   143,   141,   143,   141,   143,   141,
     143,   146,   146,   146,   146,   146,   146,   141,   146,   146,
     141,   141,     6,   146,   217,   222,   222,   148,     7,   144,
     172,   173,   230,   217,     6,     4,     4,   147,   227,   143,
     147,   147,   147,   147,     8,     6,   127,   154,   225,   217,
       7,   143,   147,   217,   217,   217,   224,   217,   224,    99,
       7,     7,   141,     7,    99,     7,     7,   141,    99,     7,
       7,   225,   148,   147,   217,   141,   148,   141,   141,   217,
     222,     4,   210,     6,   141,   175,   217,   230,   175,   175,
     175,   141,   141,   141,   144,   222,   219,   217,   217,   148,
     148,   217,   146,   146,   146,    76,    82,    83,   206,   207,
     219,   148,   193,   141,   148,   141,   141,   217,     6,   217,
     141,   143,   143,   148,   143,   143,     7,     7,     7,   144,
     217,   148,   217,   217,     7,   144,   222,   217,     4,     7,
       7,   143,   144,   173,   229,   148,   161,   140,   140,   147,
     171,     6,   217,   217,   217,   217,   217,   217,   217,   217,
     225,   229,   217,   143,     6,     6,   143,     4,    96,    97,
     217,     6,     6,     6,     7,   142,   226,   228,     6,   225,
     225,   225,   225,   217,   127,   229,   141,   146,   219,   225,
     148,     8,    52,   222,   222,     7,   222,    52,    54,   222,
     222,     7,    54,   222,   222,   148,   225,     6,     7,     7,
       7,     7,    65,   209,     6,     7,   141,   141,   141,   141,
       7,     7,     7,     4,   146,   146,   146,   146,   148,   219,
     219,   219,     6,   147,   140,   148,   207,   146,   206,     7,
       6,     7,     7,     6,   147,     6,     6,    52,     6,     6,
     222,   222,   222,     4,   146,     8,     8,   141,     4,     4,
     148,   143,   147,   147,     6,     4,     6,   140,   217,   217,
     221,   222,   147,   141,   143,   141,   143,   141,   143,   141,
     143,   141,   141,   141,   172,     7,   172,   173,   144,     7,
       6,   226,   217,   146,   148,   148,   148,   148,   148,     6,
       6,   154,   217,     6,   148,   217,   147,    59,   177,   177,
     222,     6,   147,   147,     6,     6,   222,   147,     6,     6,
     148,     5,   222,   222,   222,     4,     6,   222,     7,     7,
       7,     7,   222,   222,   222,     6,     7,     5,   217,   217,
     217,   147,   146,   148,   146,   148,   146,   148,   217,   222,
     217,   217,   219,   148,     5,   147,   222,   147,   147,   222,
     225,   147,     6,     6,    95,   217,   217,   217,     6,     7,
       6,   144,   222,   222,   173,   158,   217,   146,   146,   146,
     148,   159,   217,   222,   230,   217,     6,     4,   227,     6,
     143,   226,     6,     6,     6,     6,   229,   146,   143,   217,
     219,     6,     6,     6,   217,   217,     6,   217,     5,     6,
       6,    99,   176,   217,     6,   222,   222,   222,   222,     6,
       4,   208,     6,   217,   230,   141,   148,   141,   146,   148,
     184,   219,     6,   197,   219,     6,   198,   219,     6,   199,
     148,   146,   141,   148,   146,     6,   131,   219,     6,   219,
     219,     6,   148,   217,   222,   146,   148,     8,   148,   141,
     147,   217,   230,     4,   146,   146,   141,   146,   217,   217,
     222,   147,   146,   148,     6,     6,     6,     7,     6,   144,
       6,   217,   148,   148,   148,   148,     5,    50,     6,     6,
       6,     6,     6,   147,     6,     6,     6,     6,   147,   217,
     148,   146,   147,   146,   147,   146,   147,     6,   222,     7,
     147,   217,   146,   146,   146,     6,   148,    94,   217,   217,
     225,     6,     6,   222,   222,   162,   217,   146,   146,   221,
     217,     6,   226,    97,   146,     6,     6,     6,     6,     6,
     147,   221,   184,   146,   148,   217,   219,   206,   217,   219,
     206,   217,   219,   206,   146,   148,   222,   185,   148,   219,
     225,   219,   217,   148,   148,   148,   148,   148,   147,   217,
     217,   148,     6,   217,   217,   148,   148,   217,   148,   146,
     148,   148,   146,   148,   148,   146,   148,   222,     6,    65,
     148,   194,   147,   146,   148,   146,     6,     6,     6,     6,
     159,   141,   146,     6,   147,   146,   148,     4,   208,   148,
       6,   200,   217,     6,     6,   201,   217,     6,     6,   202,
     217,     6,   148,   217,   206,   185,   225,     6,   219,   225,
     148,   165,   217,   221,   217,     6,   147,   148,   147,   148,
     147,   148,     6,     6,   148,   148,   195,   148,   146,   148,
       6,   147,   141,   148,   148,   206,     6,   203,   206,     6,
     204,   206,     6,   205,   206,     6,   225,     6,   163,   229,
     168,   147,     6,   148,   147,   148,   147,   148,   147,   148,
     148,   146,   148,   147,   221,     6,   206,     6,   206,     6,
     206,     6,   229,     6,   166,   229,   148,   148,   148,   148,
     146,   148,     6,     6,     6,     6,   229,     6
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
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SEGM_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 108:
#line 1292 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 109:
#line 1296 "Gmsh.y"
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
#line 1315 "Gmsh.y"
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
#line 1333 "Gmsh.y"
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
#line 1372 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 113:
#line 1378 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 114:
#line 1384 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 115:
#line 1391 "Gmsh.y"
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
#line 1416 "Gmsh.y"
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
#line 1441 "Gmsh.y"
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
#line 1457 "Gmsh.y"
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
#line 1476 "Gmsh.y"
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
#line 1507 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 121:
#line 1511 "Gmsh.y"
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
#line 1531 "Gmsh.y"
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
#line 1549 "Gmsh.y"
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
#line 1567 "Gmsh.y"
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
#line 1580 "Gmsh.y"
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
#line 1596 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 127:
#line 1600 "Gmsh.y"
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
#line 1622 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 129:
#line 1627 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 130:
#line 1632 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 131:
#line 1637 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 132:
#line 1642 "Gmsh.y"
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
#line 1662 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 134:
#line 1668 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 135:
#line 1678 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 136:
#line 1679 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 137:
#line 1684 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 138:
#line 1688 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 139:
#line 1692 "Gmsh.y"
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
#line 1715 "Gmsh.y"
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
#line 1738 "Gmsh.y"
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
#line 1761 "Gmsh.y"
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
#line 1789 "Gmsh.y"
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
#line 1811 "Gmsh.y"
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
#line 1832 "Gmsh.y"
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
#line 1853 "Gmsh.y"
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
#line 1873 "Gmsh.y"
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
#line 1985 "Gmsh.y"
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
#line 2004 "Gmsh.y"
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
#line 2025 "Gmsh.y"
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
#line 2133 "Gmsh.y"
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
#line 2142 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 153:
#line 2148 "Gmsh.y"
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
#line 2163 "Gmsh.y"
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
#line 2191 "Gmsh.y"
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
#line 2208 "Gmsh.y"
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
#line 2222 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 158:
#line 2228 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 159:
#line 2234 "Gmsh.y"
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
#line 2243 "Gmsh.y"
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
#line 2257 "Gmsh.y"
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
	Msg::StatusBar(2, true, "Read '%s'", tmp.c_str());
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
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 162:
#line 2297 "Gmsh.y"
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
#line 2314 "Gmsh.y"
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
#line 2329 "Gmsh.y"
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
#line 2348 "Gmsh.y"
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
#line 2360 "Gmsh.y"
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
#line 2384 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 168:
#line 2388 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the 
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 169:
#line 2395 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 170:
#line 2401 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 171:
#line 2406 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 172:
#line 2412 "Gmsh.y"
    {
       GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 173:
#line 2422 "Gmsh.y"
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
#line 2439 "Gmsh.y"
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
#line 2456 "Gmsh.y"
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
#line 2475 "Gmsh.y"
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
#line 2494 "Gmsh.y"
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
#line 2524 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 179:
#line 2532 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 180:
#line 2538 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 181:
#line 2545 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 182:
#line 2549 "Gmsh.y"
    {
    ;}
    break;

  case 183:
#line 2558 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 184:
#line 2566 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 185:
#line 2574 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 186:
#line 2582 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 187:
#line 2586 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 188:
#line 2594 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 189:
#line 2598 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 190:
#line 2606 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 191:
#line 2610 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 192:
#line 2618 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 193:
#line 2622 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 194:
#line 2631 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 195:
#line 2638 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 196:
#line 2645 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 197:
#line 2652 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 198:
#line 2659 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 199:
#line 2666 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 200:
#line 2673 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 201:
#line 2680 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 202:
#line 2687 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 203:
#line 2694 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 204:
#line 2698 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 205:
#line 2705 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 206:
#line 2709 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 207:
#line 2716 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 208:
#line 2720 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 209:
#line 2727 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 210:
#line 2731 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 211:
#line 2738 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 212:
#line 2742 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 213:
#line 2749 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 214:
#line 2753 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 215:
#line 2760 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 216:
#line 2764 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 217:
#line 2771 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 218:
#line 2775 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 219:
#line 2782 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 220:
#line 2786 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 221:
#line 2797 "Gmsh.y"
    {
    ;}
    break;

  case 222:
#line 2800 "Gmsh.y"
    {
    ;}
    break;

  case 223:
#line 2806 "Gmsh.y"
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
#line 2815 "Gmsh.y"
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
#line 2835 "Gmsh.y"
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
#line 2858 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 227:
#line 2862 "Gmsh.y"
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
#line 2885 "Gmsh.y"
    {
      (yyval.i) = 1; // harmonic
    ;}
    break;

  case 229:
#line 2889 "Gmsh.y"
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
#line 2904 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 231:
#line 2908 "Gmsh.y"
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
#line 2923 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 233:
#line 2927 "Gmsh.y"
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
#line 2939 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 235:
#line 2943 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 236:
#line 2948 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 237:
#line 2952 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 238:
#line 2959 "Gmsh.y"
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
#line 3015 "Gmsh.y"
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
#line 3085 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 241:
#line 3090 "Gmsh.y"
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
#line 3157 "Gmsh.y"
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
#line 3200 "Gmsh.y"
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
#line 3226 "Gmsh.y"
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
#line 3249 "Gmsh.y"
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
#line 3272 "Gmsh.y"
    {
    ;}
    break;

  case 247:
#line 3275 "Gmsh.y"
    {
    ;}
    break;

  case 248:
#line 3284 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 249:
#line 3288 "Gmsh.y"
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
#line 3305 "Gmsh.y"
    {
    
    List_T *temp = ListOfDouble2ListOfInt((yyvsp[(3) - (7)].l));
    std::vector<int> domain;
    
    for (int i = 0; i < List_Nbr(temp); i++){
      int item = 0;
      List_Read(temp, i, &item);
      domain.push_back(item);
    }
    List_Delete((yyvsp[(3) - (7)].l));
    List_Delete(temp);
    
    List_T *temp2 = ListOfDouble2ListOfInt((yyvsp[(5) - (7)].l));
    std::vector<int> subdomain;
    for (int i = 0; i < List_Nbr(temp2); i++){
      int item = 0;
      List_Read(temp2, i, &item);
      subdomain.push_back(item);
    }
    List_Delete((yyvsp[(5) - (7)].l));
    List_Delete(temp2);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->computeBettiNumbers();
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation.");    
    #endif
    ;}
    break;

  case 251:
#line 3338 "Gmsh.y"
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
    
    std::string fileName = (yyvsp[(3) - (11)].c);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->findGenerators(fileName);  
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation.");
    #endif
    ;}
    break;

  case 252:
#line 3372 "Gmsh.y"
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
    
    std::string fileName = (yyvsp[(3) - (11)].c);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->findDualGenerators(fileName);
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation.");
    #endif
    ;}
    break;

  case 253:
#line 3409 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 254:
#line 3410 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 255:
#line 3411 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 256:
#line 3412 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 257:
#line 3413 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 258:
#line 3414 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 259:
#line 3415 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 260:
#line 3416 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 261:
#line 3418 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 262:
#line 3424 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 263:
#line 3425 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 264:
#line 3426 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 265:
#line 3427 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 266:
#line 3428 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 267:
#line 3429 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 268:
#line 3430 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 269:
#line 3431 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 270:
#line 3432 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 271:
#line 3433 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 272:
#line 3434 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 273:
#line 3435 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 274:
#line 3436 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 275:
#line 3437 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 276:
#line 3438 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 277:
#line 3439 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 278:
#line 3440 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 279:
#line 3441 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 280:
#line 3442 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 281:
#line 3443 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 282:
#line 3444 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 283:
#line 3445 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 284:
#line 3446 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 285:
#line 3447 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 286:
#line 3448 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 287:
#line 3449 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 288:
#line 3450 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 289:
#line 3451 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 290:
#line 3452 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 291:
#line 3453 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 292:
#line 3454 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 293:
#line 3455 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 294:
#line 3457 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 295:
#line 3458 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 296:
#line 3459 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 297:
#line 3460 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 298:
#line 3461 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 299:
#line 3462 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 300:
#line 3463 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 301:
#line 3464 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 302:
#line 3465 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 303:
#line 3466 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 304:
#line 3467 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 305:
#line 3468 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 306:
#line 3469 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 307:
#line 3470 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 308:
#line 3471 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 309:
#line 3472 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 310:
#line 3473 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 311:
#line 3474 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 312:
#line 3475 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 313:
#line 3476 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 314:
#line 3477 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 315:
#line 3486 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 316:
#line 3487 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 317:
#line 3488 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 318:
#line 3489 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 319:
#line 3490 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 320:
#line 3491 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 321:
#line 3492 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 322:
#line 3497 "Gmsh.y"
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

  case 323:
#line 3510 "Gmsh.y"
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

  case 324:
#line 3522 "Gmsh.y"
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

  case 325:
#line 3537 "Gmsh.y"
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

  case 326:
#line 3547 "Gmsh.y"
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

  case 327:
#line 3557 "Gmsh.y"
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

  case 328:
#line 3575 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 329:
#line 3580 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 330:
#line 3585 "Gmsh.y"
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

  case 331:
#line 3595 "Gmsh.y"
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

  case 332:
#line 3605 "Gmsh.y"
    { 
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 333:
#line 3613 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 334:
#line 3617 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 335:
#line 3621 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 336:
#line 3625 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 337:
#line 3629 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 338:
#line 3636 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 339:
#line 3640 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 340:
#line 3644 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 341:
#line 3648 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 342:
#line 3655 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 343:
#line 3660 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 344:
#line 3667 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 345:
#line 3672 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 346:
#line 3676 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 347:
#line 3681 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 348:
#line 3685 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 349:
#line 3693 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 350:
#line 3704 "Gmsh.y"
    { 
      (yyval.l) = (yyvsp[(1) - (1)].l); 
    ;}
    break;

  case 351:
#line 3708 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 352:
#line 3720 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 353:
#line 3728 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 354:
#line 3736 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); 
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 355:
#line 3743 "Gmsh.y"
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

  case 356:
#line 3754 "Gmsh.y"
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

  case 357:
#line 3774 "Gmsh.y"
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

  case 358:
#line 3784 "Gmsh.y"
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
#line 3794 "Gmsh.y"
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

  case 360:
#line 3804 "Gmsh.y"
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

  case 361:
#line 3824 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 362:
#line 3829 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 363:
#line 3833 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 364:
#line 3837 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 365:
#line 3849 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 366:
#line 3853 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 367:
#line 3865 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 368:
#line 3872 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 369:
#line 3882 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 370:
#line 3886 "Gmsh.y"
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

  case 371:
#line 3901 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 372:
#line 3906 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 373:
#line 3913 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 374:
#line 3917 "Gmsh.y"
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

  case 375:
#line 3930 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 376:
#line 3938 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 377:
#line 3949 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 378:
#line 3953 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 379:
#line 3961 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 380:
#line 3969 "Gmsh.y"
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

  case 381:
#line 3983 "Gmsh.y"
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

  case 382:
#line 3997 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 383:
#line 4001 "Gmsh.y"
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
#line 8629 "Gmsh.tab.cpp"
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


#line 4021 "Gmsh.y"


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

