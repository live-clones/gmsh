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
#define YYLAST   6594

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  150
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  383
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1362

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
    1587,  1599,  1611,  1623,  1625,  1629,  1632,  1635,  1638,  1642,
    1646,  1650,  1654,  1658,  1662,  1666,  1670,  1674,  1678,  1682,
    1686,  1690,  1694,  1700,  1705,  1710,  1715,  1720,  1725,  1730,
    1735,  1740,  1745,  1750,  1757,  1762,  1767,  1772,  1777,  1782,
    1787,  1794,  1801,  1808,  1813,  1818,  1823,  1828,  1833,  1838,
    1843,  1848,  1853,  1858,  1863,  1870,  1875,  1880,  1885,  1890,
    1895,  1900,  1907,  1914,  1921,  1926,  1928,  1930,  1932,  1934,
    1936,  1938,  1940,  1942,  1948,  1953,  1958,  1961,  1967,  1971,
    1978,  1983,  1991,  1998,  2000,  2003,  2006,  2010,  2014,  2026,
    2036,  2044,  2052,  2054,  2058,  2060,  2062,  2065,  2069,  2074,
    2080,  2082,  2084,  2087,  2091,  2095,  2101,  2106,  2108,  2110,
    2114,  2121,  2123,  2125,  2129,  2133,  2143,  2151,  2153,  2159,
    2163,  2170,  2172,  2176,  2178,  2180,  2184,  2191,  2193,  2195,
    2202,  2207,  2212,  2217
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
      80,     6,    -1,    80,     4,     6,    -1,   114,   140,   229,
     141,     7,   147,   222,   146,   222,   148,     6,    -1,   115,
     140,   229,   141,     7,   147,   222,   146,   222,   148,     6,
      -1,   116,   140,   229,   141,     7,   147,   222,   146,   222,
     148,     6,    -1,   218,    -1,   140,   217,   141,    -1,   131,
     217,    -1,   130,   217,    -1,   135,   217,    -1,   217,   131,
     217,    -1,   217,   130,   217,    -1,   217,   132,   217,    -1,
     217,   133,   217,    -1,   217,   134,   217,    -1,   217,   139,
     217,    -1,   217,   126,   217,    -1,   217,   127,   217,    -1,
     217,   129,   217,    -1,   217,   128,   217,    -1,   217,   125,
     217,    -1,   217,   124,   217,    -1,   217,   123,   217,    -1,
     217,   122,   217,    -1,   217,   121,   217,     8,   217,    -1,
      14,   140,   217,   141,    -1,    15,   140,   217,   141,    -1,
      16,   140,   217,   141,    -1,    17,   140,   217,   141,    -1,
      18,   140,   217,   141,    -1,    19,   140,   217,   141,    -1,
      20,   140,   217,   141,    -1,    21,   140,   217,   141,    -1,
      22,   140,   217,   141,    -1,    24,   140,   217,   141,    -1,
      25,   140,   217,   146,   217,   141,    -1,    26,   140,   217,
     141,    -1,    27,   140,   217,   141,    -1,    28,   140,   217,
     141,    -1,    29,   140,   217,   141,    -1,    30,   140,   217,
     141,    -1,    31,   140,   217,   141,    -1,    32,   140,   217,
     146,   217,   141,    -1,    33,   140,   217,   146,   217,   141,
      -1,    34,   140,   217,   146,   217,   141,    -1,    23,   140,
     217,   141,    -1,    14,   142,   217,   143,    -1,    15,   142,
     217,   143,    -1,    16,   142,   217,   143,    -1,    17,   142,
     217,   143,    -1,    18,   142,   217,   143,    -1,    19,   142,
     217,   143,    -1,    20,   142,   217,   143,    -1,    21,   142,
     217,   143,    -1,    22,   142,   217,   143,    -1,    24,   142,
     217,   143,    -1,    25,   142,   217,   146,   217,   143,    -1,
      26,   142,   217,   143,    -1,    27,   142,   217,   143,    -1,
      28,   142,   217,   143,    -1,    29,   142,   217,   143,    -1,
      30,   142,   217,   143,    -1,    31,   142,   217,   143,    -1,
      32,   142,   217,   146,   217,   143,    -1,    33,   142,   217,
     146,   217,   143,    -1,    34,   142,   217,   146,   217,   143,
      -1,    23,   142,   217,   143,    -1,     3,    -1,     9,    -1,
      10,    -1,    11,    -1,   111,    -1,   112,    -1,   113,    -1,
       4,    -1,     4,   149,   147,   217,   148,    -1,     4,   142,
     217,   143,    -1,   145,     4,   142,   143,    -1,     4,   173,
      -1,     4,   142,   217,   143,   173,    -1,     4,   144,     4,
      -1,     4,   142,   217,   143,   144,     4,    -1,     4,   144,
       4,   173,    -1,     4,   142,   217,   143,   144,     4,   173,
      -1,   110,   140,     5,   146,   217,   141,    -1,   220,    -1,
     131,   219,    -1,   130,   219,    -1,   219,   131,   219,    -1,
     219,   130,   219,    -1,   147,   217,   146,   217,   146,   217,
     146,   217,   146,   217,   148,    -1,   147,   217,   146,   217,
     146,   217,   146,   217,   148,    -1,   147,   217,   146,   217,
     146,   217,   148,    -1,   140,   217,   146,   217,   146,   217,
     141,    -1,   222,    -1,   221,   146,   222,    -1,   217,    -1,
     224,    -1,   147,   148,    -1,   147,   225,   148,    -1,   131,
     147,   225,   148,    -1,   217,   132,   147,   225,   148,    -1,
     222,    -1,     5,    -1,   131,   224,    -1,   217,   132,   224,
      -1,   217,     8,   217,    -1,   217,     8,   217,     8,   217,
      -1,    46,   147,   217,   148,    -1,   183,    -1,   192,    -1,
       4,   142,   143,    -1,     4,   142,   147,   225,   148,   143,
      -1,   217,    -1,   224,    -1,   225,   146,   217,    -1,   225,
     146,   224,    -1,   147,   217,   146,   217,   146,   217,   146,
     217,   148,    -1,   147,   217,   146,   217,   146,   217,   148,
      -1,     4,    -1,     4,   144,    96,   144,     4,    -1,   147,
     228,   148,    -1,     4,   142,   217,   143,   144,    97,    -1,
     226,    -1,   228,   146,   226,    -1,   230,    -1,     4,    -1,
       4,   144,     4,    -1,     4,   142,   217,   143,   144,     4,
      -1,     5,    -1,    42,    -1,    37,   140,   229,   146,   229,
     141,    -1,    38,   140,   229,   141,    -1,    39,   140,   229,
     141,    -1,    36,   140,   229,   141,    -1,    36,   140,   229,
     146,   225,   141,    -1
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
    2242,  2256,  2298,  2315,  2330,  2349,  2361,  2385,  2389,  2396,
    2402,  2407,  2413,  2423,  2440,  2457,  2476,  2495,  2525,  2533,
    2539,  2546,  2550,  2559,  2567,  2575,  2584,  2583,  2596,  2595,
    2608,  2607,  2620,  2619,  2632,  2639,  2646,  2653,  2660,  2667,
    2674,  2681,  2688,  2696,  2695,  2707,  2706,  2718,  2717,  2729,
    2728,  2740,  2739,  2751,  2750,  2762,  2761,  2773,  2772,  2784,
    2783,  2798,  2801,  2807,  2816,  2836,  2859,  2863,  2887,  2890,
    2906,  2909,  2925,  2928,  2941,  2944,  2950,  2953,  2960,  3016,
    3086,  3091,  3158,  3201,  3227,  3250,  3273,  3276,  3285,  3289,
    3306,  3343,  3379,  3419,  3420,  3421,  3422,  3423,  3424,  3425,
    3426,  3427,  3434,  3435,  3436,  3437,  3438,  3439,  3440,  3441,
    3442,  3443,  3444,  3445,  3446,  3447,  3448,  3449,  3450,  3451,
    3452,  3453,  3454,  3455,  3456,  3457,  3458,  3459,  3460,  3461,
    3462,  3463,  3464,  3465,  3467,  3468,  3469,  3470,  3471,  3472,
    3473,  3474,  3475,  3476,  3477,  3478,  3479,  3480,  3481,  3482,
    3483,  3484,  3485,  3486,  3487,  3496,  3497,  3498,  3499,  3500,
    3501,  3502,  3506,  3519,  3531,  3546,  3556,  3566,  3584,  3589,
    3594,  3604,  3614,  3622,  3626,  3630,  3634,  3638,  3645,  3649,
    3653,  3657,  3664,  3669,  3676,  3681,  3685,  3690,  3694,  3702,
    3713,  3717,  3729,  3737,  3745,  3752,  3763,  3783,  3793,  3803,
    3813,  3833,  3838,  3842,  3846,  3858,  3862,  3874,  3881,  3891,
    3895,  3910,  3915,  3922,  3926,  3939,  3947,  3958,  3962,  3970,
    3978,  3992,  4006,  4010
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
      11,    11,    11,     1,     3,     2,     2,     2,     3,     3,
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
     158,     0,   374,     0,   373,     0,     0,     0,     0,   328,
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
       0,   156,     0,     0,     0,     0,     0,   375,     0,     0,
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
       0,     0,     0,     0,   331,     0,    37,     0,     0,     0,
       0,     0,    39,     0,     0,     0,    76,     0,     0,    77,
       0,   372,   139,   140,   141,   142,     0,     0,   360,     0,
      93,   101,   102,   106,     0,     0,   117,     0,     0,   240,
     110,     0,     0,   231,   122,     0,     0,     0,     0,   107,
     229,     0,   125,     0,     0,     0,     0,   341,     0,   340,
       0,     0,   194,     0,     0,   195,     0,     0,   196,     0,
       0,     0,     0,     0,     0,   148,     0,     0,   147,     0,
       0,   143,     0,     0,     0,     0,   366,     0,   175,   174,
       0,     0,     0,   376,     0,     0,     0,    42,     0,     0,
       0,   343,     0,     0,     0,    65,    72,    74,     0,    80,
       0,    27,     0,     0,     0,     0,     0,     0,     0,   111,
      96,   109,   121,   127,     0,   118,    86,    87,   124,   137,
       0,   131,     0,     0,     0,     0,     0,     0,   223,     0,
       0,   137,     0,     0,     0,     0,   134,   133,     0,     0,
       0,     0,    83,    84,     0,     0,     0,     0,    38,     0,
       0,     0,    40,    55,     0,   370,     0,   244,   245,   246,
     247,   114,     0,     0,     0,     0,   339,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   188,
       0,     0,     0,     0,     0,   365,   176,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,   228,   129,
       0,   209,     0,     0,   211,     0,     0,   213,     0,     0,
       0,   224,     0,   184,     0,   137,     0,     0,     0,   105,
      85,   250,   251,   252,     0,    46,     0,    52,     0,     0,
      91,   229,     0,   338,   197,     0,     0,   204,   198,     0,
       0,   206,   199,     0,     0,   208,     0,     0,     0,   190,
       0,   146,     0,     0,     0,     0,     0,     0,     0,   119,
       0,   215,     0,   217,     0,   219,   225,   227,   189,   185,
       0,     0,     0,     0,    43,     0,    50,     0,     0,     0,
     200,     0,     0,   201,     0,     0,   202,     0,     0,   150,
       0,   144,     0,    44,     0,     0,   170,     0,     0,     0,
       0,     0,     0,   191,     0,     0,     0,     0,     0,   210,
       0,   212,     0,   214,     0,   145,    45,    47,     0,    48,
       0,     0,     0,     0,     0,     0,    53,   216,   218,   220,
      49,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    68,   697,    69,    70,   431,  1025,  1031,
     620,   796,  1177,  1322,   621,  1285,  1348,   622,  1324,   623,
     624,   800,   137,   235,    71,   735,  1062,   958,   498,   361,
     362,   363,   364,   330,   301,   302,    74,    75,    76,    77,
      78,    79,   331,   762,  1244,  1300,   575,  1083,  1086,  1089,
    1265,  1269,  1273,  1311,  1314,  1317,   758,   759,  1071,   863,
     732,   550,   583,    81,    82,    83,    84,   348,   140,   373,
     188,   920,   921,   357,   350,   541,   216,   688,   827,   423,
     424
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1118
static const yytype_int16 yypact[] =
{
    3350,    49,    70,  3432, -1118, -1118,  1680,    82,    60,   -42,
      30,   114,   132,   183,  -102,    76,   150,   -51,   159,   188,
     -47,   198,   199,   286,   303,   331,   340,   361,   226,   334,
     275,   239,   256,   371,   290,   326,   -68,   -68,   345,    64,
      69,   439,   443,   378,    11,   181,   460,   495,   509,   513,
     382,   386,   387,    14,    29, -1118,   392, -1118,   529,   396,
   -1118,   542,   553,    20,    25,   401,   474,   475, -1118, -1118,
   -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118,
   -1118, -1118, -1118, -1118, -1118, -1118,    22,   418,   280, -1118,
   -1118, -1118,   276,   283,   291,   320,   325,   336,   344,   362,
     368,   428,   437,   440,   450,   456,   465,   470,   537,   574,
     580,   581,   586,   485,   514,   524,   549, -1118,   622,   555,
   -1118, -1118, -1118, -1118, -1118, -1118, -1118,  3187,  3187,  3187,
   -1118, -1118,  3187,  2732,    95,   671,    36,  3187,   693,   952,
   -1118,   709,   713,  3187,   742, -1118,  3187, -1118, -1118, -1118,
    3187,  3114,  3187,  3187,   585,  3187,  3114,  3187,  3187,   608,
    3114,  3187,  3187,  2103,   636,   655,   645,   649,  1825,  1825,
    1825,   668, -1118, -1118, -1118, -1118,   672,   673,   689,   829,
    2103,   831,   -68,   -68,   -68,  3187,  3187,   -83, -1118,   -50,
     -68,   700,   702,   705,  2975,   151,   -71,   716,   717,  1825,
    2103,   725,     6,   733, -1118,   873, -1118,   750,   738,   753,
     895,  3187,  3187,  3187,   758,  3187,   756,   805,  3187,  3187,
   -1118,  3187,   899, -1118,   900, -1118,   901, -1118,   492,   492,
     492,   766,  3187,   905,   763, -1118, -1118, -1118,   907,  3187,
    3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,
    3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,
    3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,
    3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,
    3187,   492,   492,   492,   492,  3187,   909,   489,   776,   776,
     776,  5342,    53,  3114,  4606,   215,   773,   924,   790,   788,
   -1118,   792,  2834,  1134, -1118, -1118,  3187,  3187,  3187,  3187,
    3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,  3187,
    3187, -1118, -1118,  1337,   -85,  3904,  5363,   425,   789,  3114,
   -1118, -1118,  1161, -1118,   590,  5384,  5405,  3187,  5426,   591,
    5447,  5468,  3187,   594,  5489,  5510,  2242,  1534,  2236,   931,
   -1118,  3187,  3187,  3187,  3187, -1118, -1118,   934,   935,   935,
    3187,   803,   804,   806,   807,  3187,  3187,  3187,   808,   939,
     802,   -56, -1118, -1118,  3930,  3956,   -68,   -68,    36,    36,
     328,  3187,  3187,  3187,  2975,  2975,  3187,  2834,   333, -1118,
    3187,  3187,  3187,  3187,   944,   945,  3187,   947, -1118,  3187,
    3187,   791, -1118,  3114,  3187,  3187, -1118,  5531,  5552,  5573,
     858,  3982, -1118,   812,  2308,  5594,  4629, -1118, -1118,  1154,
   -1118,  1257,   601,   814, -1118,   819,   821,  3187,  4652,    -8,
    3187,     5, -1118,  5615,  4675,  5636,  4698,  5657,  4721,  5678,
    4744,  5699,  4767,  5720,  4790,  5741,  4813,  5762,  4836,  5783,
    4859,  5804,  4882,  5825,  4905,  4008,  4034,  5846,  4928,  5867,
    4951,  5888,  4974,  5909,  4997,  5930,  5020,  5951,  5043,  4060,
    4086,  4112,  4138,  4164,  4190,   148,   817,   823,   824,  1360,
     820,  3187, -1118,  2103,  2103,   598,    80,   280,  3187,   961,
     966,    18,   828, -1118,   -22,   -36,   -46,    63, -1118, -1118,
    2342,   795,  1202,   667,   667,   539,   539,   539,   539,   558,
     558,   776,   776,   776,   776, -1118,    15,  3114,  3187,   968,
    2937,  3187,   776, -1118,  3187,  3114,  3114,   874,   970,   971,
    5972,   972,   882,   975,   976,  5993,   887,   982,   983,  3114,
   -1118,   603,  2381,  3187,  6014,  2585,  6035,  6056,  3187,  2103,
     987,   986,  6077,  3247,  3247,  3247,  3247,  6098,  6119,  6140,
     849, -1118,  2103,   -68,  3187,  3187, -1118, -1118,   847,   848,
    3187,  4216,  4242,  4268,  2727,   -41,   -68,  1575,  6161,  2930,
    6182,  6203,  3187,   991,  3187,  6224, -1118,  5066,  5089, -1118,
     606,  5112,  5135,   993,   994,   997,   854,  3187,  1861,  3187,
    3187, -1118,    24, -1118, -1118,  3187,  1002,  1000,  1001,  1003,
    5158,    46, -1118,  2968, -1118,   869,   871,   865, -1118,  1008,
   -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118,
   -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118,
   -1118, -1118, -1118, -1118, -1118, -1118, -1118,  3187,  3187, -1118,
   -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118,
   -1118,  3187,  3187,  3187,  3187,  3187,  3187, -1118,  3114,   492,
   -1118, -1118, -1118,  3187,  5181,  1010,  1012,   876, -1118,   105,
    3187,  1014,  1017,  1396, -1118,  1018,   884,    14,  1021, -1118,
    3114,  3114,  3114,  3114,  3187, -1118,   897,   492,   174,  4294,
     -68, -1118,  3114,  3040,  2375,   776, -1118,  1161, -1118,   977,
    2103,  2103,  1023,  2103,   701,  2103,  2103,  1024,   974,  2103,
    2103,   610, -1118,  3114,  1603,  1025,  1026,  1027,  1028,  2490,
   -1118, -1118,  1030, -1118,  1035,   902,  6455, -1118,   906,   910,
     912,  1039,  1041,  1043,  1050,   913,   370,  4320,  4346, -1118,
   -1118,  3107,   -68,   -68,   -68,  1049,   911,   916,   -24, -1118,
     375, -1118,   -41,  1053,  1055,  1056,  1057,  6455, -1118,  1625,
     915,  1059,  1060,  1015,  1062,  1063,  2103,  2103,  2103,  1067,
    4372, -1118,  2447,   641,  1083,  1088,  5204, -1118,   946,   948,
     949,  1091,  1090, -1118,  1092, -1118,   960,  3187,  3187,  2103,
     955, -1118,  6245,  5227,  6266,  5250,  6287,  5273,  6308,  5296,
     184,   962,  6329,   506, -1118, -1118,    16,   351,   963,  1098,
    1647, -1118, -1118, -1118,    14,  3187, -1118,   611, -1118,   631,
     635,   638,   642,  6455, -1118,  1100,    48,  3187,    51,   659,
   -1118,  3187,   964,  1054,  1054,  2103,  1102,   967,   969,  1103,
    1109,  2103,   973,  1112,  1116, -1118,   663, -1118,  1119,  2103,
    2103,  2103,  1121,  1120, -1118,  2103,  1122,  1123,  1124,  1126,
    2103,  2103,  2103,   397,  1130,  3187,  3187,  3187,   980,   220,
     243,   271, -1118,  2103,  3187, -1118, -1118,  2975,    -5,  1964,
   -1118,   981,  2520, -1118,  3114, -1118, -1118,   990, -1118, -1118,
    1136,  1138,  1052, -1118,  3187,  3187,  3187, -1118,  1143,  1144,
    1009,  2103,  2103,  2103, -1118,    -8, -1118,  3187,  4398,  4424,
     669, -1118,  3187, -1118, -1118, -1118, -1118, -1118, -1118, -1118,
   -1118, -1118, -1118, -1118,  2103,   280,  3187,  1148,  1151,    18,
   -1118,  1150,  5319,    14, -1118,  1153,  1155,  1157,  1158, -1118,
   -1118,   492,  4450, -1118,  1022,  6455,  3187,   -68,  1162,  1164,
    1165, -1118,  3187,  3187, -1118, -1118,  1166,  3187, -1118, -1118,
   -1118,  1152,  1169,  1170,  1061,  3187, -1118,  1171,  2103,  2103,
    2103,  2103,  1172,  1175,  1176, -1118,  3247,  1040,  3180,  6350,
    2513,    36,   -68,  1177,   -68,  1178,   -68,  1179,   318,  1042,
    6371,  3213,   409, -1118,  1181,  1367,  1184,   -68,  1367,  1185,
     670,  3187, -1118, -1118,  2103,  2652,   579,  6392, -1118,  2798,
    1188,  1047,  1048,  1051, -1118,   221,  6455,  3187,  3187,  2103,
    1065,   674,  6455,  1190,  1192,  1754, -1118,  1203,  1193, -1118,
    1075, -1118, -1118, -1118, -1118, -1118,  1214,  3187, -1118,  3428,
      97, -1118, -1118, -1118,  3456,  3484, -1118,  3512,  1218, -1118,
   -1118,  1174,  1219,  6455, -1118,  1221,  1224,  1225,  1227, -1118,
    1087,  1229, -1118,  1893,  1231,  1232,  1096, -1118,  3187, -1118,
    1101,   414, -1118,  1097,   458, -1118,  1104,   471, -1118,  1105,
    1233,  2103,  1241,  1107,  3187, -1118,  2659,   488, -1118,   491,
     493, -1118,  1269,  3540,  1204,  3187, -1118,  3187, -1118, -1118,
    3114,  2032,  1272, -1118,  2103,  2103,  2103, -1118,  3187,  4476,
    4502, -1118,  2103,  3187,  1273, -1118, -1118, -1118,    14, -1118,
    1200, -1118,  4528,  1293,  1295,  1307,  1309,  1312,  1195, -1118,
   -1118, -1118, -1118, -1118,  2103, -1118, -1118, -1118, -1118,    36,
    2889, -1118,  2975,   -41,  2975,   -41,  2975,   -41, -1118,   675,
    2103, -1118,  3568,   -68,  3114,   -68, -1118, -1118,  3187,  3596,
    3624,   678, -1118, -1118,  1196,  1197,  1198,  1206,  6455,  3187,
    3187,   679,  6455, -1118,  1316, -1118,  3187, -1118, -1118, -1118,
   -1118, -1118,  3187,   682,  1199,  3187, -1118,  3652,   505,   138,
    3680,   515,   147,  3708,   517,   149,  2103,  1317,  1275,  2000,
    1207,   522,   686,   535,  2171, -1118, -1118,  1345,  1350,  1351,
    1352,  3187,  6413,  4554,    31, -1118,  4580,  3736,  1355, -1118,
    3764,  1354,  3187,  1356,  1357,  3187,  1358,  1359,  3187,  1361,
    1213, -1118,  3187, -1118,   -41, -1118,  3114,  1362,  2659, -1118,
   -1118, -1118, -1118, -1118,   714, -1118,  3187, -1118,  2103,  3187,
   -1118, -1118,  1363, -1118, -1118,  1226,  3792, -1118, -1118,  1228,
    3820, -1118, -1118,  1256,  3848, -1118,  1366,  2203,   201,  2139,
     715, -1118,   552,   720,  1368,  1260,  6434,   728,  3876, -1118,
     -41,  1373,   -41,  1374,   -41,  1398, -1118, -1118, -1118, -1118,
     -41,  1402,  3114,  1403, -1118,   492, -1118,  1263,  1405,   261,
   -1118,  1267,   287, -1118,  1268,   289, -1118,  1270,   324, -1118,
     739, -1118,   744, -1118,  1271,  2103, -1118,  1410,   -41,  1413,
     -41,  1417,   -41, -1118,  1418,   492,  1419,   492,   745, -1118,
     329, -1118,   332, -1118,   346, -1118, -1118, -1118,   748, -1118,
    1421,  1422,  1423,  1424,   492,  1428, -1118, -1118, -1118, -1118,
   -1118, -1118
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1118, -1118, -1118, -1118,   599, -1118, -1118, -1118, -1118,   225,
   -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118, -1118,
   -1118, -1118,  -293,    -3, -1118,  -100, -1118,   597,  1439, -1118,
   -1118, -1118, -1118,     3,  -371,  -193, -1118, -1118, -1118, -1118,
   -1118, -1118,  1444, -1118, -1118, -1118, -1118, -1118, -1118, -1118,
   -1118, -1118, -1118, -1118, -1118, -1118,  -719,  -712,   223, -1118,
   -1118,  1093, -1118, -1118, -1118, -1118, -1118,    -6, -1118,   -20,
   -1118, -1117,   561,   -67,   347,  -107,  -667,   510, -1118,  -216,
      -2
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     139,   387,   488,   138,   141,  1181,    73,   568,   569,   614,
     397,   401,   398,   425,   426,   202,   187,   189,   214,   195,
     826,   695,   686,   678,   154,   224,   231,  1193,   159,   159,
     226,   784,   419,   217,   421,   755,   145,  1257,   150,   154,
     299,   756,   757,   888,   334,   151,   886,   376,   377,   339,
     422,   237,   755,   343,   950,     4,   516,   953,   756,   757,
     483,   517,   183,   184,   378,   475,   476,   477,   478,   390,
       5,   755,   185,   196,   376,   377,   391,   756,   757,   186,
     376,   377,   113,   114,   115,   116,   238,   678,   117,   155,
     563,   615,   616,   617,   618,   142,   156,   379,   144,   295,
     160,   692,   358,   359,   155,    35,    36,    37,    38,   817,
     191,   691,   143,   192,    43,   203,   193,    46,   150,   197,
     147,   288,   289,   290,   885,   690,   291,   294,   198,   130,
     131,   303,   394,   123,   124,   125,   126,   323,   148,   300,
     325,  1287,   696,  1003,   326,   332,   335,   336,   399,   338,
     332,   340,   341,   619,   332,   344,   345,   941,   204,   130,
     131,   215,   371,   372,   232,   687,   233,   225,   785,   218,
     380,   234,   227,   484,   388,   696,   886,   146,  1258,   374,
     375,   376,   377,   130,   131,   205,   485,   206,   375,   149,
     792,   296,   297,   680,   183,   184,   577,   123,   124,   125,
     126,   818,   819,   162,   185,   407,   408,   409,  1338,   411,
     693,   194,   414,   415,   755,   416,   152,   130,   131,   598,
     756,   757,   487,   755,   679,   755,   428,   376,   377,   756,
     757,   756,   757,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   168,  1041,   755,   169,   479,
     170,   376,   377,   756,   757,   237,  1233,   332,   176,   667,
     153,   177,   489,   178,   668,  1236,   590,  1239,   389,   157,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   836,   113,   114,   115,   116,
     526,   172,   117,   522,   173,   931,   524,   174,   158,   175,
     526,   530,   123,   124,   125,   126,   535,   755,   161,   162,
     522,   332,   163,   756,   757,   544,   545,   546,   547,  1298,
     376,   377,   130,   131,   552,   164,   566,   567,   935,   557,
     558,   559,  1117,   755,   372,   755,   992,  1118,   993,   756,
     757,   756,   757,   376,   377,   571,   572,   573,   288,   289,
     574,   300,   300,   165,   578,   579,   580,   581,   171,   994,
     585,   995,   166,   587,   588,   794,   179,   332,   591,   592,
     755,   376,   377,   985,   986,   755,   756,   757,   755,  1327,
     698,   756,   757,   167,   756,   757,   239,   996,   240,   997,
     180,   610,   755,   241,   613,   242,   612,   201,   756,   757,
     181,   243,   721,   244,  1199,  1329,  1202,  1331,  1205,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     542,   318,   319,   811,   738,   739,   740,   320,   376,   377,
     245,  1184,   246,   376,   377,   247,  1090,   248,   123,   124,
     125,   126,  1333,   182,   570,   674,   249,  1351,   250,   576,
    1352,   835,   683,   681,   251,   682,   252,   886,   130,   131,
     886,   199,   190,   886,  1353,   200,   422,   237,   333,   208,
     376,   377,   253,   333,   254,   376,   377,   333,   255,   207,
     256,   332,   699,   209,   674,   703,   875,   210,   704,   705,
     707,   887,   211,   934,   936,  1278,   212,   213,   113,   114,
     115,   116,   219,   332,   117,   220,   705,   724,   221,   376,
     377,   228,   729,   746,   376,   377,   222,   736,   736,   736,
     736,   737,   737,   737,   737,  1094,   760,   223,   747,   748,
    1152,   810,   130,   131,   751,   236,   886,   520,   257,   233,
     258,  1309,   136,  1312,   234,  1315,   767,   259,   769,   260,
     261,  1318,   262,   829,   830,   831,   832,  1107,   376,   377,
     263,   780,   264,   782,   783,   839,   265,   886,   266,   786,
     886,   376,   377,   886,  1154,   267,   886,   268,   793,  1340,
     269,  1342,   270,  1344,   229,   230,   856,  1156,   376,   377,
    1080,   376,   377,   376,   377,   281,   130,   131,   886,   285,
     886,   481,   886,   233,  1163,   376,   377,  1164,   234,  1165,
     333,   802,   803,   130,   131,   376,   377,   376,   377,   906,
     792,  1232,   376,   377,   282,   804,   805,   806,   807,   808,
     809,  1235,   332,  1238,   283,   376,   377,   812,  1246,   315,
     316,   317,   318,   319,   820,   298,   523,   271,   320,   272,
     838,  1248,   376,   377,   332,   332,   332,   332,   833,   284,
     317,   318,   319,   523,   333,   286,   332,   320,  1302,   304,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   273,   321,   274,   332,   320,   322,
     275,   277,   276,   278,   349,   337,   279,  1108,   280,   356,
     356,   356,   879,   880,   881,  1046,   526,   526,   527,   532,
     526,   369,   536,   605,   526,   606,   677,   324,   342,   526,
     333,   722,   526,   847,   773,   848,   526,   943,   855,   944,
     356,   395,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   351,   526,  1194,   945,
     320,   526,   907,   946,   526,   353,   947,  1010,   526,   354,
     948,   918,   919,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   352,     7,     8,   526,   320,   954,   360,   526,
     793,   970,   365,   366,   937,  1029,   526,  1030,  1102,   942,
    1123,  1206,  1124,  1207,   526,  1029,  1217,  1224,  1029,   367,
    1228,   952,   526,   368,  1247,   955,   370,   494,    15,    16,
     495,    18,    19,   496,    21,   497,    23,   381,    24,   382,
      26,    27,   383,    29,    30,    31,   392,   393,    33,    34,
    1123,   526,  1284,  1301,   333,   396,   526,  1002,  1303,   988,
     989,   990,   706,   708,  1029,   400,  1307,   998,  1000,   402,
     404,  1001,    50,    51,    52,   526,   333,  1334,   332,   706,
    1335,  1029,  1336,  1350,  1354,   405,  1355,   403,  1015,  1016,
    1017,   406,   410,   412,   413,   417,   418,   420,   427,   429,
     430,  1026,  1024,   432,   480,   320,  1032,   490,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
    1035,   491,   492,  1034,   320,   136,   521,  1050,   543,   589,
     493,   548,   549,   553,   554,   561,   555,   556,   562,   560,
    1049,   582,   584,   586,   596,   607,  1054,  1055,   305,   599,
     608,  1057,   609,   669,   670,   671,   673,   684,  1209,  1063,
     685,   689,  1081,   709,  1084,   700,  1087,   710,   711,   713,
    1073,   714,   715,   716,  1074,  1097,   718,  1099,  1100,   719,
     720,   731,   733,   744,   300,   749,   750,   768,   779,   332,
     776,   777,   332,  1171,   778,  1103,   787,   788,   789,   797,
     790,   798,   799,  1111,   801,   333,   814,  1112,   815,   816,
     821,  1119,  1120,   822,   834,   824,   825,   828,   852,   842,
     845,   851,   858,   859,   860,   861,   864,   333,   333,   333,
     333,  1132,   865,   866,   675,   676,   870,   867,   871,   333,
     872,   868,  1279,   869,   873,   882,   884,  1212,   883,   874,
     889,   890,   894,   891,   892,   895,   896,   897,   898,   899,
     333,   903,  1150,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   908,  1162,  1323,
     522,   320,   909,   911,   915,   912,   913,   914,   916,  1169,
     917,  1170,   922,   932,   332,   939,   949,   938,   961,   964,
     730,   956,  1178,   957,   962,   965,   963,  1182,   968,  1346,
     967,  1349,   969,   745,   971,   975,   976,   991,  1007,   978,
     979,   980,  1198,   981,  1201,   987,  1204,  1011,  1360,  1280,
     499,  1283,  1012,  1211,  1013,  1213,  1197,  1014,  1200,  1018,
    1203,  1019,   300,  1020,  1036,  1037,  1039,  1058,   332,  1042,
    1061,  1043,  1214,  1044,  1045,  1048,     7,     8,  1051,   524,
    1052,  1053,  1056,  1222,  1223,  1059,  1060,  1064,  1069,  1070,
    1226,  1075,  1072,  1082,  1085,  1088,  1227,  1095,  1091,  1230,
    1098,  1101,  1113,  1114,  1115,  1320,  1125,  1116,  1126,  1129,
     494,    15,    16,   495,    18,    19,   496,    21,   497,    23,
    1128,    24,  1122,    26,    27,  1032,    29,    30,    31,  1130,
    1131,    33,    34,  1137,  1138,  1139,  1266,  1140,  1282,  1270,
    1141,  1142,  1274,  1143,  1144,  1145,  1277,  1147,  1148,  1158,
     332,   333,   332,  1149,  1153,    50,    51,    52,  1160,  1151,
    1286,  1155,  1157,  1288,  1161,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     7,
       8,   843,   844,   320,   846,  1166,   849,   850,  1173,  1183,
     853,   854,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   525,   318,   319,   332,  1185,  1168,  1187,
     320,  1188,   603,   494,    15,    16,   495,    18,    19,   496,
      21,   497,    23,  1189,    24,  1190,    26,    27,  1191,    29,
      30,    31,  1225,  1241,    33,    34,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   900,   901,   902,
    1242,   320,  1192,   515,  1218,  1219,  1220,  1229,    50,    51,
      52,  1250,   333,  1221,  1245,   333,  1251,  1252,  1253,  1261,
    1264,  1276,  1267,  1268,  1271,  1272,   672,  1275,  1281,  1289,
      85,   327,  1296,  1290,  1304,  1292,    89,    90,    91,  1310,
    1313,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   823,  1294,  1316,   604,   960,  1305,  1319,  1321,
    1325,  1326,   966,   328,  1328,  1330,  1339,  1332,  1337,  1341,
     972,   973,   974,  1343,  1345,  1347,   977,  1356,  1357,  1358,
    1359,   982,   983,   984,  1361,   951,    35,    36,    37,    38,
      39,   959,    72,   523,   999,    43,  1254,    80,    46,  1038,
    1006,  1262,   551,  1009,     0,     0,     0,   333,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,  1021,  1022,  1023,     0,   320,   119,   120,   121,
     122,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,  1033,     0,   384,  1096,   320,
       0,     0,   129,     0,     0,     0,     0,   386,     0,     0,
       0,   333,   135,     0,   186,   540,     0,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,    85,   327,  1065,
    1066,  1067,  1068,    89,    90,    91,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
       0,     0,     0,     0,     0,  1104,     0,     0,     0,     0,
     328,     0,     0,     0,     0,     0,     0,     7,     8,     0,
    1121,     0,     0,   333,     0,   333,     0,     0,     0,     0,
       0,     0,     0,    35,    36,    37,    38,    39,     0,   857,
       0,     0,    43,     0,     0,    46,     0,     0,     0,     0,
       0,   494,    15,    16,   495,    18,    19,   496,    21,   497,
      23,   893,    24,     0,    26,    27,     0,    29,    30,    31,
       0,     0,    33,    34,   119,   120,   121,   122,     0,   333,
       0,     0,  1159,   940,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   329,    50,    51,    52,   129,
       0,     0,     0,     0,   132,  1174,  1175,  1176,     0,   135,
       0,     0,   540,    85,    86,    87,     0,    88,     0,    89,
      90,    91,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
       0,  1208,   117,   761,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,     0,     0,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
    1127,     0,     0,     0,   320,     0,     0,  1240,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,   118,     0,   320,     0,     0,     0,
     119,   120,   121,   122,     0,     0,     0,   123,   124,   125,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,   128,     0,     0,     0,   129,     0,   130,   131,     0,
     132,     0,   133,     0,   134,   135,     0,   136,    85,   327,
     355,     0,     0,     0,    89,    90,    91,     0,     0,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   328,     0,     7,     8,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,    35,    36,    37,    38,    39,  1146,
       0,     0,     0,    43,     0,     0,    46,   494,    15,    16,
     495,    18,    19,   496,    21,   497,    23,     0,    24,     0,
      26,    27,     0,    29,    30,    31,     0,     0,    33,    34,
       0,     0,     0,     0,     0,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,    51,    52,   127,   346,     0,     0,     0,
     129,     0,     0,     0,     0,   132,     0,    85,   327,  1004,
     135,     0,   347,    89,    90,    91,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   781,
     328,     0,     7,     8,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,    35,    36,    37,    38,    39,  1172,     0,
       0,     0,    43,     0,     0,    46,   494,    15,    16,   495,
      18,    19,   496,    21,   497,    23,     0,    24,     0,    26,
      27,     0,    29,    30,    31,     0,     0,    33,    34,     0,
       0,     0,     0,     0,   119,   120,   121,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    51,    52,   127,   346,     0,     0,     0,   129,
       0,     0,     0,     0,   132,     0,    85,   327,     0,   135,
       0,  1005,    89,    90,    91,     0,     0,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1243,   328,
       0,     7,     8,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,    35,    36,    37,    38,    39,  1249,     0,     0,
       0,    43,     0,     0,    46,   494,    15,    16,   495,    18,
      19,   496,    21,   497,    23,     0,    24,     0,    26,    27,
       0,    29,    30,    31,     0,     0,    33,    34,     0,  1297,
       0,     0,     0,   119,   120,   121,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,    51,    52,   127,   346,     0,     0,     0,   129,     0,
       0,     0,     0,   132,   524,    85,   327,     0,   135,     0,
     347,    89,    90,    91,     0,     0,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1299,   328,     0,
       0,     0,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,    35,    36,    37,    38,    39,   600,     0,     0,     0,
      43,     0,     0,    46,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,     0,     0,     0,     0,     0,     0,
     694,     0,   119,   120,   121,   122,     0,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   542,   318,
     319,     0,   127,   329,     0,   320,     0,   129,     0,     0,
       0,     0,   132,   841,    85,   327,     0,   135,     0,   539,
      89,    90,    91,     0,     0,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   328,     0,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
      35,    36,    37,    38,    39,   905,     0,     0,     0,    43,
       0,     0,    46,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,   120,   121,   122,     0,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,   127,   329,     0,   320,     0,   129,     0,     0,     0,
       0,   132,     0,    85,   327,     0,   135,     0,   723,    89,
      90,    91,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   862,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   328,     0,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,     0,    35,
      36,    37,    38,    39,     0,     0,     0,     0,    43,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
     119,   120,   121,   122,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
     127,   346,   320,     0,     0,   129,     0,     0,     0,  1078,
     132,  1079,    85,   327,     0,   135,     0,  1008,    89,    90,
      91,     0,     0,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   328,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,     0,     0,    35,    36,
      37,    38,    39,   726,     0,    85,   287,    43,     0,     0,
      46,    89,    90,    91,     0,     0,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,   119,
     120,   121,   122,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,   384,
    1096,   320,     0,     0,   129,     0,     0,     0,  1105,   386,
    1106,    85,   287,   237,   135,     0,   186,    89,    90,    91,
       0,     0,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,     0,     0,
     117,     0,   119,   120,   121,   122,     7,     8,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   127,   128,     0,     0,   320,   129,   482,     0,
       0,     0,   132,   564,     0,   292,     0,   135,     0,   293,
     494,    15,    16,   495,    18,    19,   496,    21,   497,    23,
       0,    24,     0,    26,    27,     0,    29,    30,    31,     0,
       0,    33,    34,     0,     0,     0,     0,     0,   119,   120,
     121,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    51,    52,   127,   128,
       0,     0,     0,   129,     0,     0,     0,     0,   132,     0,
      85,   287,     0,   135,     0,  1110,    89,    90,    91,     0,
       0,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,    85,   287,
       0,     0,     0,     0,    89,    90,    91,     0,     0,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
       0,     0,     0,     0,     0,  1195,     0,  1196,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,   120,   121,
     122,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,   127,   128,   320,
       0,     0,   129,     0,     0,     0,     0,   132,   764,     0,
     701,     0,   135,     0,   702,   119,   120,   121,   122,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,   384,   385,   320,     0,     0,
     129,     0,     0,     0,     0,   386,   795,    85,   327,     0,
     135,     0,   186,    89,    90,    91,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     328,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,    35,    36,    37,    38,    39,   840,     0,
      85,   287,    43,     0,     0,    46,    89,    90,    91,     0,
       0,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,     0,   119,   120,   121,   122,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,   127,   329,   320,     0,     0,   129,
      85,   287,   237,     0,   132,   878,    89,    90,    91,   135,
       0,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,   119,   120,   121,
     122,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,   127,   128,   320,
       0,     0,   129,     0,     0,     0,     0,   132,  1076,     0,
       0,     0,   135,     0,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
      -4,     1,   320,     0,    -4,     0,     0,   119,   120,   121,
     122,  1093,    -4,    -4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,     0,
       0,     0,   129,     0,     0,    -4,     0,   132,     0,     0,
      -4,    -4,   135,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,    -4,    -4,     6,     0,     0,     0,
      -4,    -4,    -4,    -4,     7,     8,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,     0,     0,    -4,    -4,    -4,     9,     0,     0,
       0,     0,    10,    11,     0,    12,    13,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,    45,    46,     0,     0,    47,    48,     0,     0,
       0,     0,    49,    50,    51,    52,     0,     0,    53,     0,
      54,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,    65,    66,    67,   306,
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
    1136,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,     0,     0,  1167,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,     0,     0,  1210,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,     0,     0,  1215,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
       0,     0,  1216,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,     0,     0,
    1231,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,     0,     0,  1234,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,     0,     0,  1237,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,     0,     0,  1260,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
       0,     0,  1263,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,     0,     0,
    1291,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,     0,     0,  1293,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,     0,     0,  1295,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,     0,     0,  1308,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
     518,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,   564,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,   565,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,   597,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,   647,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
     648,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,   661,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,   662,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,   663,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,   664,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
     665,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,   666,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,   752,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,   753,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,   754,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
     837,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,   876,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,   877,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,   904,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,  1027,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
    1028,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,  1047,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,  1179,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,  1180,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,  1186,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
    1256,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,  1259,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,   486,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
       0,     0,   602,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,   611,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,     0,     0,   626,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,   628,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,     0,     0,   630,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,   632,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,     0,     0,
     634,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,   636,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,     0,     0,   638,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,   640,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
       0,     0,   642,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,   644,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,     0,     0,   646,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,   650,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,     0,     0,   652,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,   654,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,     0,     0,
     656,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,   658,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,     0,     0,   660,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,   771,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
       0,     0,   772,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,     0,     0,   774,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,     0,     0,   775,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,     0,
       0,   791,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,     0,     0,   813,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,     0,     0,   910,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,     0,     0,
     924,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,     0,     0,   926,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,     0,     0,   928,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,     0,     0,   930,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
       0,     0,  1040,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,   482,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,   519,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,   528,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,   529,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,   531,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,   533,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,   534,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
     537,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,   538,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,   593,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,   594,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,   595,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,   601,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,   625,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,   627,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,   629,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,   631,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
     633,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,   635,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,   637,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,   639,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,   641,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,   643,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,   645,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,   649,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,   651,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,   653,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
     655,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,   657,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,   659,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,   712,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,   717,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,   725,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,   727,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,   728,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,   734,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,   741,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
     742,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,   743,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,   763,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,   765,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,   766,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,   770,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320,     0,   923,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     0,     0,     0,     0,   320,     0,   925,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,   320,     0,   927,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,   320,     0,   929,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,   320,     0,
     933,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,     0,     0,   320,
       0,  1077,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,     0,     0,     0,
     320,     0,  1092,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,     0,     0,     0,
       0,   320,     0,  1109,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,     0,
       0,     0,   320,     0,  1255,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,   320,     0,  1306,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,     0,   320
};

static const yytype_int16 yycheck[] =
{
       6,   194,   295,     6,     6,  1122,     3,   378,   379,     4,
       4,   204,     6,   229,   230,     4,    36,    37,     4,    39,
     687,     6,     4,     7,    75,     5,     4,  1144,    75,    75,
       5,     7,   225,     4,   227,    76,     6,     6,   140,    75,
       4,    82,    83,   762,   151,   147,   758,   130,   131,   156,
       4,     5,    76,   160,     6,     6,   141,     6,    82,    83,
       7,   146,   130,   131,   147,   281,   282,   283,   284,   140,
       0,    76,   140,     4,   130,   131,   147,    82,    83,   147,
     130,   131,    36,    37,    38,    39,    88,     7,    42,   140,
     146,    86,    87,    88,    89,    13,   147,   147,   140,     4,
     147,   147,   169,   170,   140,    69,    70,    71,    72,     4,
      46,   147,    52,    49,    78,   104,    52,    81,   140,    50,
       6,   127,   128,   129,   148,   147,   132,   133,    59,   137,
     138,   137,   199,   117,   118,   119,   120,   143,     6,   136,
     146,  1258,   127,   148,   150,   151,   152,   153,   142,   155,
     156,   157,   158,   148,   160,   161,   162,   824,   147,   137,
     138,   147,   182,   183,   142,   147,   144,   147,   144,   140,
     190,   149,   147,   120,   194,   127,   888,   147,   147,   185,
     186,   130,   131,   137,   138,     4,   293,     6,   194,     6,
     144,    96,    97,   486,   130,   131,   389,   117,   118,   119,
     120,    96,    97,   140,   140,   211,   212,   213,  1325,   215,
     147,   147,   218,   219,    76,   221,   140,   137,   138,   412,
      82,    83,     7,    76,   144,    76,   232,   130,   131,    82,
      83,    82,    83,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,    49,   943,    76,    52,   285,
      54,   130,   131,    82,    83,     5,   148,   293,    49,   141,
     140,    52,   295,    54,   146,   148,   403,   148,   147,   140,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   141,    36,    37,    38,    39,
     146,    46,    42,   329,    49,   141,     8,    52,   140,    54,
     146,   337,   117,   118,   119,   120,   342,    76,   140,   140,
     346,   347,    56,    82,    83,   351,   352,   353,   354,   148,
     130,   131,   137,   138,   360,    52,   376,   377,     7,   365,
     366,   367,   141,    76,   384,    76,   146,   146,   148,    82,
      83,    82,    83,   130,   131,   381,   382,   383,   384,   385,
     386,   378,   379,    52,   390,   391,   392,   393,    54,   146,
     396,   148,    52,   399,   400,   611,   140,   403,   404,   405,
      76,   130,   131,     6,     7,    76,    82,    83,    76,   148,
     517,    82,    83,    52,    82,    83,   140,   146,   142,   148,
      49,   427,    76,   140,   430,   142,   429,    49,    82,    83,
     140,   140,   539,   142,  1153,   148,  1155,   148,  1157,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   669,   554,   555,   556,   139,   130,   131,
     140,  1128,   142,   130,   131,   140,   148,   142,   117,   118,
     119,   120,   148,   147,   146,   481,   140,   148,   142,   146,
     148,   697,   488,   486,   140,   487,   142,  1199,   137,   138,
    1202,    52,   147,  1205,   148,    52,     4,     5,   151,     4,
     130,   131,   140,   156,   142,   130,   131,   160,   140,    49,
     142,   517,   518,     4,   520,   521,   146,     4,   524,   525,
     526,   146,   140,   816,   817,  1244,   140,   140,    36,    37,
      38,    39,   140,   539,    42,     6,   542,   543,   142,   130,
     131,   140,   548,   563,   130,   131,     4,   553,   554,   555,
     556,   553,   554,   555,   556,   146,   576,     4,   564,   565,
     146,   668,   137,   138,   570,   147,  1278,   142,   140,   144,
     142,  1290,   147,  1292,   149,  1294,   582,   140,   584,   142,
     140,  1300,   142,   690,   691,   692,   693,     8,   130,   131,
     140,   597,   142,   599,   600,   702,   140,  1309,   142,   605,
    1312,   130,   131,  1315,   146,   140,  1318,   142,   611,  1328,
     140,  1330,   142,  1332,   140,   140,   723,   146,   130,   131,
     991,   130,   131,   130,   131,   140,   137,   138,  1340,     7,
    1342,   142,  1344,   144,   146,   130,   131,   146,   149,   146,
     293,   647,   648,   137,   138,   130,   131,   130,   131,     8,
     144,   146,   130,   131,   140,   661,   662,   663,   664,   665,
     666,   146,   668,   146,   140,   130,   131,   673,   146,   130,
     131,   132,   133,   134,   680,     4,   329,   140,   139,   142,
     700,   146,   130,   131,   690,   691,   692,   693,   694,   140,
     132,   133,   134,   346,   347,   140,   702,   139,   146,     6,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   140,     6,   142,   723,   139,     6,
     140,   140,   142,   142,   163,   140,   140,   148,   142,   168,
     169,   170,   752,   753,   754,   951,   146,   146,   148,   148,
     146,   180,   148,   142,   146,   144,   148,     5,   140,   146,
     403,   148,   146,    52,   148,    54,   146,   146,   148,   148,
     199,   200,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   140,   146,  1149,   148,
     139,   146,   141,   148,   146,   140,   148,   894,   146,   140,
     148,   797,   798,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   147,    12,    13,   146,   139,   148,   140,   146,
     813,   148,   140,   140,   817,   146,   146,   148,   148,   825,
     146,   146,   148,   148,   146,   146,   148,   148,   146,   140,
     148,   837,   146,     4,   148,   841,     5,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,   147,    57,   147,
      59,    60,   147,    62,    63,    64,   140,   140,    67,    68,
     146,   146,   148,   148,   517,   140,   146,   887,   148,   875,
     876,   877,   525,   526,   146,   142,   148,   883,   884,     6,
     142,   887,    91,    92,    93,   146,   539,   148,   894,   542,
     146,   146,   148,   148,   146,   142,   148,   147,   904,   905,
     906,     6,   144,   147,    99,     6,     6,     6,   142,     4,
     147,   917,   915,     6,     5,   139,   922,   144,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     936,     7,   142,   935,   139,   147,   147,   957,     7,   148,
     148,     7,     7,   140,   140,     6,   140,   140,   146,   141,
     956,     7,     7,     6,    96,   141,   962,   963,     6,   147,
     141,   967,   141,   146,   141,   141,   146,     6,  1161,   975,
       4,   143,   992,    99,   994,     7,   996,     7,     7,     7,
     986,    99,     7,     7,   986,  1005,    99,  1007,  1008,     7,
       7,     4,     6,   144,   991,   148,   148,     6,   144,  1005,
       7,     7,  1008,  1110,     7,  1011,     4,     7,     7,   140,
       7,   140,   147,  1019,     6,   668,     6,  1019,     6,   143,
       6,  1027,  1028,     6,   127,     7,   142,     6,    54,    52,
       7,     7,     7,     7,     7,     7,     6,   690,   691,   692,
     693,  1047,     7,   141,   483,   484,     7,   141,     7,   702,
       7,   141,  1245,   141,     4,     6,   140,  1164,   147,   146,
       7,     6,   147,     7,     7,     6,     6,    52,     6,     6,
     723,     4,  1078,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,     4,  1094,  1305,
    1096,   139,     4,   147,     4,   147,   147,     6,     6,  1105,
     140,  1107,   147,   141,  1110,     7,     6,   144,     6,     6,
     549,   147,  1118,    59,   147,     6,   147,  1123,     6,  1335,
     147,  1337,     6,   562,     5,     4,     6,   147,   147,     7,
       7,     7,  1152,     7,  1154,     5,  1156,   147,  1354,  1246,
       6,  1248,     6,  1163,     6,  1165,  1152,    95,  1154,     6,
    1156,     7,  1149,   144,     6,     4,     6,     5,  1164,     6,
      99,     6,  1168,     6,     6,   143,    12,    13,     6,     8,
       6,     6,     6,  1179,  1180,     6,     6,     6,     6,     4,
    1186,   141,     6,     6,     6,     6,  1192,     6,   146,  1195,
       6,     6,     4,   146,   146,  1302,     6,   146,     6,     6,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       7,    57,   147,    59,    60,  1221,    62,    63,    64,   144,
       6,    67,    68,     5,    50,     6,  1232,     6,  1248,  1235,
       6,     6,  1238,     6,   147,     6,  1242,     6,     6,     6,
    1246,   894,  1248,   147,   147,    91,    92,    93,     7,   148,
    1256,   147,   147,  1259,   147,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    12,
      13,   710,   711,   139,   713,     6,   715,   716,     6,     6,
     719,   720,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,  1302,    97,    94,     6,
     139,     6,   148,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     6,    57,     6,    59,    60,     6,    62,
      63,    64,     6,     6,    67,    68,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   776,   777,   778,
      65,   139,   147,     6,   148,   148,   148,   148,    91,    92,
      93,     6,  1005,   147,   147,  1008,     6,     6,     6,     4,
       6,   148,     6,     6,     6,     6,     6,     6,     6,     6,
       3,     4,     6,   147,     6,   147,     9,    10,    11,     6,
       6,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     6,   147,     6,   148,   845,   147,     6,     6,
     147,     6,   851,    46,   147,   147,     6,   147,   147,     6,
     859,   860,   861,     6,     6,     6,   865,     6,     6,     6,
       6,   870,   871,   872,     6,   836,    69,    70,    71,    72,
      73,   844,     3,  1096,   883,    78,  1221,     3,    81,   939,
     889,  1228,   359,   892,    -1,    -1,    -1,  1110,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   911,   912,   913,    -1,   139,   110,   111,   112,
     113,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   934,    -1,   130,   131,   139,
      -1,    -1,   135,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,  1164,   145,    -1,   147,   148,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,     3,     4,   978,
     979,   980,   981,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,  1014,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
    1029,    -1,    -1,  1246,    -1,  1248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,     6,
      -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     6,    57,    -1,    59,    60,    -1,    62,    63,    64,
      -1,    -1,    67,    68,   110,   111,   112,   113,    -1,  1302,
      -1,    -1,  1091,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    91,    92,    93,   135,
      -1,    -1,    -1,    -1,   140,  1114,  1115,  1116,    -1,   145,
      -1,    -1,   148,     3,     4,     5,    -1,     7,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,  1160,    42,   148,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
       6,    -1,    -1,    -1,   139,    -1,    -1,  1206,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,   104,    -1,   139,    -1,    -1,    -1,
     110,   111,   112,   113,    -1,    -1,    -1,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,   144,   145,    -1,   147,     3,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    12,    13,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    69,    70,    71,    72,    73,     6,
      -1,    -1,    -1,    78,    -1,    -1,    81,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    -1,
      59,    60,    -1,    62,    63,    64,    -1,    -1,    67,    68,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,   130,   131,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    -1,   140,    -1,     3,     4,     5,
     145,    -1,   147,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,
      46,    -1,    12,    13,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    69,    70,    71,    72,    73,     6,    -1,
      -1,    -1,    78,    -1,    -1,    81,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    -1,    59,
      60,    -1,    62,    63,    64,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    92,    93,   130,   131,    -1,    -1,    -1,   135,
      -1,    -1,    -1,    -1,   140,    -1,     3,     4,    -1,   145,
      -1,   147,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,    46,
      -1,    12,    13,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    69,    70,    71,    72,    73,     6,    -1,    -1,
      -1,    78,    -1,    -1,    81,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    -1,    59,    60,
      -1,    62,    63,    64,    -1,    -1,    67,    68,    -1,     6,
      -1,    -1,    -1,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,   130,   131,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,   140,     8,     3,     4,    -1,   145,    -1,
     147,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,    46,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    69,    70,    71,    72,    73,     8,    -1,    -1,    -1,
      78,    -1,    -1,    81,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       8,    -1,   110,   111,   112,   113,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,   130,   131,    -1,   139,    -1,   135,    -1,    -1,
      -1,    -1,   140,     8,     3,     4,    -1,   145,    -1,   147,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      69,    70,    71,    72,    73,     8,    -1,    -1,    -1,    78,
      -1,    -1,    81,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,   130,   131,    -1,   139,    -1,   135,    -1,    -1,    -1,
      -1,   140,    -1,     3,     4,    -1,   145,    -1,   147,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    69,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
     110,   111,   112,   113,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
     130,   131,   139,    -1,    -1,   135,    -1,    -1,    -1,   146,
     140,   148,     3,     4,    -1,   145,    -1,   147,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    69,    70,
      71,    72,    73,   148,    -1,     3,     4,    78,    -1,    -1,
      81,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,   110,
     111,   112,   113,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,   130,
     131,   139,    -1,    -1,   135,    -1,    -1,    -1,   146,   140,
     148,     3,     4,     5,   145,    -1,   147,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    -1,
      42,    -1,   110,   111,   112,   113,    12,    13,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   130,   131,    -1,    -1,   139,   135,   141,    -1,
      -1,    -1,   140,   146,    -1,   143,    -1,   145,    -1,   147,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    -1,    59,    60,    -1,    62,    63,    64,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,   130,   131,
      -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,   140,    -1,
       3,     4,    -1,   145,    -1,   147,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,   130,   131,   139,
      -1,    -1,   135,    -1,    -1,    -1,    -1,   140,   148,    -1,
     143,    -1,   145,    -1,   147,   110,   111,   112,   113,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,   130,   131,   139,    -1,    -1,
     135,    -1,    -1,    -1,    -1,   140,   148,     3,     4,    -1,
     145,    -1,   147,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    69,    70,    71,    72,    73,   148,    -1,
       3,     4,    78,    -1,    -1,    81,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,   110,   111,   112,   113,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,   130,   131,   139,    -1,    -1,   135,
       3,     4,     5,    -1,   140,   148,     9,    10,    11,   145,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,   130,   131,   139,
      -1,    -1,   135,    -1,    -1,    -1,    -1,   140,   148,    -1,
      -1,    -1,   145,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
       0,     1,   139,    -1,     4,    -1,    -1,   110,   111,   112,
     113,   148,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,
      -1,    -1,   135,    -1,    -1,    35,    -1,   140,    -1,    -1,
      40,    41,   145,    43,    44,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    -1,    -1,    84,    85,     4,    -1,    -1,    -1,
      90,    91,    92,    93,    12,    13,    96,    -1,    98,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
      -1,    -1,    -1,    -1,   114,   115,   116,    35,    -1,    -1,
      -1,    -1,    40,    41,    -1,    43,    44,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    -1,    -1,    84,    85,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    -1,    -1,    96,    -1,
      98,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,   114,   115,   116,   121,
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
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   121,   122,   123,   124,   125,
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
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   121,   122,   123,
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
      -1,    -1,    -1,   143,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,   143,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,   143,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,   143,   121,   122,   123,   124,   125,   126,   127,
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
      -1,    -1,   139,    -1,   141,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,   141,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139
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
       6,   142,     4,     4,     5,   147,     5,   147,   140,   140,
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
       6,   185,     4,   229,   230,   229,   229,   142,   217,     4,
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
       8,   141,   143,   148,   148,   142,   144,   141,   141,   141,
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
     217,   148,   217,   217,     7,   144,   217,     4,     7,     7,
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
     143,   147,   147,   147,     6,     4,     6,   140,   217,   217,
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
     144,   222,   222,   222,   173,   158,   217,   146,   146,   146,
     148,   159,   217,   222,   230,   217,     6,     4,   227,     6,
     143,   226,     6,     6,     6,     6,   229,   146,   143,   217,
     219,     6,     6,     6,   217,   217,     6,   217,     5,     6,
       6,    99,   176,   217,     6,   222,   222,   222,   222,     6,
       4,   208,     6,   217,   230,   141,   148,   141,   146,   148,
     184,   219,     6,   197,   219,     6,   198,   219,     6,   199,
     148,   146,   141,   148,   146,     6,   131,   219,     6,   219,
     219,     6,   148,   217,   222,   146,   148,     8,   148,   141,
     147,   217,   230,     4,   146,   146,   146,   141,   146,   217,
     217,   222,   147,   146,   148,     6,     6,     6,     7,     6,
     144,     6,   217,   148,   148,   148,   148,     5,    50,     6,
       6,     6,     6,     6,   147,     6,     6,     6,     6,   147,
     217,   148,   146,   147,   146,   147,   146,   147,     6,   222,
       7,   147,   217,   146,   146,   146,     6,   148,    94,   217,
     217,   225,     6,     6,   222,   222,   222,   162,   217,   146,
     146,   221,   217,     6,   226,    97,   146,     6,     6,     6,
       6,     6,   147,   221,   184,   146,   148,   217,   219,   206,
     217,   219,   206,   217,   219,   206,   146,   148,   222,   185,
     148,   219,   225,   219,   217,   148,   148,   148,   148,   148,
     148,   147,   217,   217,   148,     6,   217,   217,   148,   148,
     217,   148,   146,   148,   148,   146,   148,   148,   146,   148,
     222,     6,    65,   148,   194,   147,   146,   148,   146,     6,
       6,     6,     6,     6,   159,   141,   146,     6,   147,   146,
     148,     4,   208,   148,     6,   200,   217,     6,     6,   201,
     217,     6,     6,   202,   217,     6,   148,   217,   206,   185,
     225,     6,   219,   225,   148,   165,   217,   221,   217,     6,
     147,   148,   147,   148,   147,   148,     6,     6,   148,   148,
     195,   148,   146,   148,     6,   147,   141,   148,   148,   206,
       6,   203,   206,     6,   204,   206,     6,   205,   206,     6,
     225,     6,   163,   229,   168,   147,     6,   148,   147,   148,
     147,   148,   147,   148,   148,   146,   148,   147,   221,     6,
     206,     6,   206,     6,   206,     6,   229,     6,   166,   229,
     148,   148,   148,   148,   146,   148,     6,     6,     6,     6,
     229,     6
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetName"))
	GModel::current()->setName((yyvsp[(2) - (3)].c));
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 162:
#line 2299 "Gmsh.y"
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
#line 2316 "Gmsh.y"
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
#line 2331 "Gmsh.y"
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
#line 2350 "Gmsh.y"
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
#line 2362 "Gmsh.y"
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
#line 2386 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 168:
#line 2390 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the 
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 169:
#line 2397 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 170:
#line 2403 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 171:
#line 2408 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 172:
#line 2414 "Gmsh.y"
    {
       GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 173:
#line 2424 "Gmsh.y"
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
#line 2441 "Gmsh.y"
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
#line 2458 "Gmsh.y"
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
#line 2477 "Gmsh.y"
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
#line 2496 "Gmsh.y"
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
#line 2526 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 179:
#line 2534 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 180:
#line 2540 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 181:
#line 2547 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 182:
#line 2551 "Gmsh.y"
    {
    ;}
    break;

  case 183:
#line 2560 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 184:
#line 2568 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 185:
#line 2576 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 186:
#line 2584 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 187:
#line 2588 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 188:
#line 2596 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 189:
#line 2600 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 190:
#line 2608 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 191:
#line 2612 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 192:
#line 2620 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 193:
#line 2624 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 194:
#line 2633 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 195:
#line 2640 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 196:
#line 2647 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 197:
#line 2654 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 198:
#line 2661 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 199:
#line 2668 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 200:
#line 2675 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 201:
#line 2682 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 202:
#line 2689 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 203:
#line 2696 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 204:
#line 2700 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 205:
#line 2707 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 206:
#line 2711 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 207:
#line 2718 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 208:
#line 2722 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 209:
#line 2729 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 210:
#line 2733 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 211:
#line 2740 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 212:
#line 2744 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 213:
#line 2751 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 214:
#line 2755 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 215:
#line 2762 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 216:
#line 2766 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 217:
#line 2773 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 218:
#line 2777 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 219:
#line 2784 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 220:
#line 2788 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 221:
#line 2799 "Gmsh.y"
    {
    ;}
    break;

  case 222:
#line 2802 "Gmsh.y"
    {
    ;}
    break;

  case 223:
#line 2808 "Gmsh.y"
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
#line 2817 "Gmsh.y"
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
#line 2837 "Gmsh.y"
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
#line 2860 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 227:
#line 2864 "Gmsh.y"
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
#line 2887 "Gmsh.y"
    {
      (yyval.i) = 1; // harmonic
    ;}
    break;

  case 229:
#line 2891 "Gmsh.y"
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
#line 2906 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 231:
#line 2910 "Gmsh.y"
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
#line 2925 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 233:
#line 2929 "Gmsh.y"
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
#line 2941 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 235:
#line 2945 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 236:
#line 2950 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 237:
#line 2954 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 238:
#line 2961 "Gmsh.y"
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
#line 3017 "Gmsh.y"
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
#line 3087 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 241:
#line 3092 "Gmsh.y"
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
#line 3159 "Gmsh.y"
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
#line 3202 "Gmsh.y"
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
#line 3228 "Gmsh.y"
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
#line 3251 "Gmsh.y"
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
#line 3274 "Gmsh.y"
    {
    ;}
    break;

  case 247:
#line 3277 "Gmsh.y"
    {
    ;}
    break;

  case 248:
#line 3286 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 249:
#line 3290 "Gmsh.y"
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
#line 3307 "Gmsh.y"
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
    homology->computeBettiNumbers();
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation.");    
    #endif
    ;}
    break;

  case 251:
#line 3344 "Gmsh.y"
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
#line 3380 "Gmsh.y"
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
#line 3419 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 254:
#line 3420 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 255:
#line 3421 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 256:
#line 3422 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 257:
#line 3423 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 258:
#line 3424 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 259:
#line 3425 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 260:
#line 3426 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 261:
#line 3428 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 262:
#line 3434 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 263:
#line 3435 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 264:
#line 3436 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 265:
#line 3437 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 266:
#line 3438 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 267:
#line 3439 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 268:
#line 3440 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 269:
#line 3441 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 270:
#line 3442 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 271:
#line 3443 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 272:
#line 3444 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 273:
#line 3445 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 274:
#line 3446 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 275:
#line 3447 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 276:
#line 3448 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 277:
#line 3449 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 278:
#line 3450 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 279:
#line 3451 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 280:
#line 3452 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 281:
#line 3453 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 282:
#line 3454 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 283:
#line 3455 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 284:
#line 3456 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 285:
#line 3457 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 286:
#line 3458 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 287:
#line 3459 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 288:
#line 3460 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 289:
#line 3461 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 290:
#line 3462 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 291:
#line 3463 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 292:
#line 3464 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 293:
#line 3465 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 294:
#line 3467 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 295:
#line 3468 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 296:
#line 3469 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 297:
#line 3470 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 298:
#line 3471 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 299:
#line 3472 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 300:
#line 3473 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 301:
#line 3474 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 302:
#line 3475 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 303:
#line 3476 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 304:
#line 3477 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 305:
#line 3478 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 306:
#line 3479 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 307:
#line 3480 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 308:
#line 3481 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 309:
#line 3482 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 310:
#line 3483 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 311:
#line 3484 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 312:
#line 3485 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 313:
#line 3486 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 314:
#line 3487 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 315:
#line 3496 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 316:
#line 3497 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 317:
#line 3498 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 318:
#line 3499 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 319:
#line 3500 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 320:
#line 3501 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 321:
#line 3502 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 322:
#line 3507 "Gmsh.y"
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
#line 3520 "Gmsh.y"
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
#line 3532 "Gmsh.y"
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
#line 3547 "Gmsh.y"
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
#line 3557 "Gmsh.y"
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
#line 3567 "Gmsh.y"
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
#line 3585 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 329:
#line 3590 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 330:
#line 3595 "Gmsh.y"
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
#line 3605 "Gmsh.y"
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
#line 3615 "Gmsh.y"
    { 
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 333:
#line 3623 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 334:
#line 3627 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 335:
#line 3631 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 336:
#line 3635 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 337:
#line 3639 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 338:
#line 3646 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 339:
#line 3650 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 340:
#line 3654 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 341:
#line 3658 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 342:
#line 3665 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 343:
#line 3670 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 344:
#line 3677 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 345:
#line 3682 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 346:
#line 3686 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 347:
#line 3691 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 348:
#line 3695 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 349:
#line 3703 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 350:
#line 3714 "Gmsh.y"
    { 
      (yyval.l) = (yyvsp[(1) - (1)].l); 
    ;}
    break;

  case 351:
#line 3718 "Gmsh.y"
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
#line 3730 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 353:
#line 3738 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 354:
#line 3746 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); 
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 355:
#line 3753 "Gmsh.y"
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
#line 3764 "Gmsh.y"
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

  case 358:
#line 3794 "Gmsh.y"
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
#line 3804 "Gmsh.y"
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
#line 3814 "Gmsh.y"
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
#line 3834 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 362:
#line 3839 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 363:
#line 3843 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 364:
#line 3847 "Gmsh.y"
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
#line 3859 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 366:
#line 3863 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 367:
#line 3875 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 368:
#line 3882 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 369:
#line 3892 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 370:
#line 3896 "Gmsh.y"
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
#line 3911 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 372:
#line 3916 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 373:
#line 3923 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 374:
#line 3927 "Gmsh.y"
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
#line 3940 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 376:
#line 3948 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 377:
#line 3959 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 378:
#line 3963 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 379:
#line 3971 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 380:
#line 3979 "Gmsh.y"
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
#line 3993 "Gmsh.y"
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
#line 4007 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 383:
#line 4011 "Gmsh.y"
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
#line 8633 "Gmsh.tab.cpp"
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


#line 4031 "Gmsh.y"


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

