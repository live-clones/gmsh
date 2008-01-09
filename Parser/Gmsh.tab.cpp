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
     tPoint = 298,
     tCircle = 299,
     tEllipse = 300,
     tLine = 301,
     tSphere = 302,
     tPolarSphere = 303,
     tSurface = 304,
     tSpline = 305,
     tVolume = 306,
     tCharacteristic = 307,
     tLength = 308,
     tParametric = 309,
     tElliptic = 310,
     tPlane = 311,
     tRuled = 312,
     tTransfinite = 313,
     tComplex = 314,
     tPhysical = 315,
     tUsing = 316,
     tBump = 317,
     tProgression = 318,
     tPlugin = 319,
     tRotate = 320,
     tTranslate = 321,
     tSymmetry = 322,
     tDilate = 323,
     tExtrude = 324,
     tDuplicata = 325,
     tLoop = 326,
     tRecombine = 327,
     tDelete = 328,
     tCoherence = 329,
     tIntersect = 330,
     tBoundary = 331,
     tAttractor = 332,
     tLayers = 333,
     tHole = 334,
     tAlias = 335,
     tAliasWithOptions = 336,
     tText2D = 337,
     tText3D = 338,
     tInterpolationScheme = 339,
     tTime = 340,
     tCombine = 341,
     tBSpline = 342,
     tBezier = 343,
     tNurbs = 344,
     tOrder = 345,
     tKnots = 346,
     tColor = 347,
     tColorTable = 348,
     tFor = 349,
     tIn = 350,
     tEndFor = 351,
     tIf = 352,
     tEndIf = 353,
     tExit = 354,
     tField = 355,
     tThreshold = 356,
     tStructured = 357,
     tLatLon = 358,
     tGrad = 359,
     tPostView = 360,
     tReturn = 361,
     tCall = 362,
     tFunction = 363,
     tShow = 364,
     tHide = 365,
     tGetValue = 366,
     tGMSH_MAJOR_VERSION = 367,
     tGMSH_MINOR_VERSION = 368,
     tGMSH_PATCH_VERSION = 369,
     tAFFECTDIVIDE = 370,
     tAFFECTTIMES = 371,
     tAFFECTMINUS = 372,
     tAFFECTPLUS = 373,
     tOR = 374,
     tAND = 375,
     tNOTEQUAL = 376,
     tEQUAL = 377,
     tGREATEROREQUAL = 378,
     tLESSOREQUAL = 379,
     UNARYPREC = 380,
     tMINUSMINUS = 381,
     tPLUSPLUS = 382
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
#define tPoint 298
#define tCircle 299
#define tEllipse 300
#define tLine 301
#define tSphere 302
#define tPolarSphere 303
#define tSurface 304
#define tSpline 305
#define tVolume 306
#define tCharacteristic 307
#define tLength 308
#define tParametric 309
#define tElliptic 310
#define tPlane 311
#define tRuled 312
#define tTransfinite 313
#define tComplex 314
#define tPhysical 315
#define tUsing 316
#define tBump 317
#define tProgression 318
#define tPlugin 319
#define tRotate 320
#define tTranslate 321
#define tSymmetry 322
#define tDilate 323
#define tExtrude 324
#define tDuplicata 325
#define tLoop 326
#define tRecombine 327
#define tDelete 328
#define tCoherence 329
#define tIntersect 330
#define tBoundary 331
#define tAttractor 332
#define tLayers 333
#define tHole 334
#define tAlias 335
#define tAliasWithOptions 336
#define tText2D 337
#define tText3D 338
#define tInterpolationScheme 339
#define tTime 340
#define tCombine 341
#define tBSpline 342
#define tBezier 343
#define tNurbs 344
#define tOrder 345
#define tKnots 346
#define tColor 347
#define tColorTable 348
#define tFor 349
#define tIn 350
#define tEndFor 351
#define tIf 352
#define tEndIf 353
#define tExit 354
#define tField 355
#define tThreshold 356
#define tStructured 357
#define tLatLon 358
#define tGrad 359
#define tPostView 360
#define tReturn 361
#define tCall 362
#define tFunction 363
#define tShow 364
#define tHide 365
#define tGetValue 366
#define tGMSH_MAJOR_VERSION 367
#define tGMSH_MINOR_VERSION 368
#define tGMSH_PATCH_VERSION 369
#define tAFFECTDIVIDE 370
#define tAFFECTTIMES 371
#define tAFFECTMINUS 372
#define tAFFECTPLUS 373
#define tOR 374
#define tAND 375
#define tNOTEQUAL 376
#define tEQUAL 377
#define tGREATEROREQUAL 378
#define tLESSOREQUAL 379
#define UNARYPREC 380
#define tMINUSMINUS 381
#define tPLUSPLUS 382




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// $Id: Gmsh.tab.cpp,v 1.337 2008-01-09 08:17:12 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <stdarg.h>
#include <time.h>
#include "PluginManager.h"
#include "ParUtil.h"
#include "Gmsh.h"
#include "Numeric.h"
#include "Context.h"
#include "GModel.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "Generator.h"
#include "Draw.h"
#include "PView.h"
#include "PViewDataList.h"
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
#include "Field.h"
#include "BackgroundMesh.h"

Tree_T *Symbol_T = NULL;

extern Context_T CTX;

static ExtrudeParams extr;

static gmshSurface *myGmshSurface = 0;

static PViewDataList *ViewData;
static List_T *ViewValueList;
static double ViewCoord[100];
static int *ViewNumList, ViewCoordIdx;

#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0;
static fpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static char *LoopControlVariablesNameTab[MAX_RECUR_LOOPS];

void yyerror(char *s);
void yymsg(int type, char *fmt, ...);
void skip_until(char *skip, char *until);
int PrintListOfDouble(char *format, List_T *list, char *buffer);


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
#line 76 "Gmsh.y"
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
#line 435 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 448 "Gmsh.tab.cpp"

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
#define YYLAST   6585

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  148
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  353
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1274

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   382

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   133,     2,   143,     2,   132,     2,     2,
     138,   139,   130,   128,   144,   129,   142,   131,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     124,     2,   125,   119,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   140,     2,   141,   137,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   145,     2,   146,   147,     2,     2,     2,
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
     115,   116,   117,   118,   120,   121,   122,   123,   126,   127,
     134,   135,   136
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    45,    51,    59,    67,    77,    84,    91,    98,
      99,   102,   105,   108,   111,   114,   116,   120,   122,   126,
     127,   128,   139,   141,   145,   146,   160,   162,   166,   167,
     183,   192,   207,   208,   215,   217,   219,   221,   223,   225,
     227,   229,   234,   242,   252,   259,   266,   270,   277,   282,
     289,   299,   306,   316,   322,   331,   340,   352,   359,   369,
     379,   389,   391,   393,   401,   410,   420,   429,   438,   447,
     456,   466,   475,   481,   488,   495,   502,   510,   518,   526,
     536,   544,   554,   572,   580,   588,   600,   609,   618,   627,
     636,   640,   645,   656,   664,   672,   681,   690,   699,   707,
     716,   722,   734,   740,   750,   755,   765,   770,   772,   774,
     775,   778,   785,   792,   799,   806,   811,   818,   822,   827,
     833,   837,   841,   846,   851,   855,   863,   871,   875,   883,
     887,   890,   893,   909,   912,   919,   928,   937,   948,   950,
     953,   955,   959,   964,   966,   972,   984,   998,   999,  1007,
    1008,  1022,  1023,  1039,  1040,  1047,  1048,  1059,  1068,  1077,
    1086,  1099,  1112,  1125,  1140,  1155,  1170,  1171,  1184,  1185,
    1198,  1199,  1212,  1213,  1230,  1231,  1248,  1249,  1266,  1267,
    1286,  1287,  1306,  1307,  1326,  1328,  1331,  1337,  1345,  1355,
    1358,  1368,  1375,  1385,  1395,  1404,  1414,  1423,  1432,  1439,
    1444,  1455,  1466,  1477,  1488,  1491,  1493,  1497,  1500,  1503,
    1506,  1510,  1514,  1518,  1522,  1526,  1530,  1534,  1538,  1542,
    1546,  1550,  1554,  1558,  1562,  1568,  1573,  1578,  1583,  1588,
    1593,  1598,  1603,  1608,  1613,  1618,  1625,  1630,  1635,  1640,
    1645,  1650,  1655,  1662,  1669,  1676,  1681,  1686,  1691,  1696,
    1701,  1706,  1711,  1716,  1721,  1726,  1731,  1738,  1743,  1748,
    1753,  1758,  1763,  1768,  1775,  1782,  1789,  1794,  1796,  1798,
    1800,  1802,  1804,  1806,  1808,  1810,  1816,  1821,  1826,  1829,
    1835,  1839,  1846,  1851,  1859,  1866,  1868,  1871,  1874,  1878,
    1882,  1894,  1904,  1912,  1920,  1922,  1926,  1928,  1930,  1933,
    1937,  1942,  1948,  1951,  1955,  1959,  1965,  1970,  1972,  1974,
    1978,  1985,  1987,  1989,  1993,  1997,  2007,  2015,  2017,  2023,
    2027,  2034,  2036,  2040,  2042,  2044,  2046,  2048,  2055,  2060,
    2065,  2070,  2077,  2084
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     149,     0,    -1,   150,    -1,     1,     6,    -1,    -1,   150,
     151,    -1,   154,    -1,   153,    -1,   172,    -1,   174,    -1,
     175,    -1,   178,    -1,   179,    -1,   180,    -1,   183,    -1,
     200,    -1,   201,    -1,   202,    -1,   182,    -1,   181,    -1,
     125,    -1,   125,   125,    -1,    35,   138,     5,   139,     6,
      -1,    35,   138,     5,   139,   152,   214,     6,    -1,    35,
     138,     5,   144,   210,   139,     6,    -1,    35,   138,     5,
     144,   210,   139,   152,   214,     6,    -1,     4,     5,   145,
     155,   146,     6,    -1,    80,     4,   140,   203,   141,     6,
      -1,    81,     4,   140,   203,   141,     6,    -1,    -1,   155,
     158,    -1,   155,   162,    -1,   155,   165,    -1,   155,   167,
      -1,   155,   168,    -1,   203,    -1,   156,   144,   203,    -1,
     203,    -1,   157,   144,   203,    -1,    -1,    -1,     4,   159,
     138,   156,   139,   160,   145,   157,   146,     6,    -1,   214,
      -1,   161,   144,   214,    -1,    -1,    82,   138,   203,   144,
     203,   144,   203,   139,   163,   145,   161,   146,     6,    -1,
     214,    -1,   164,   144,   214,    -1,    -1,    83,   138,   203,
     144,   203,   144,   203,   144,   203,   139,   166,   145,   164,
     146,     6,    -1,    84,   145,   207,   146,   145,   207,   146,
       6,    -1,    84,   145,   207,   146,   145,   207,   146,   145,
     207,   146,   145,   207,   146,     6,    -1,    -1,    85,   169,
     145,   157,   146,     6,    -1,     7,    -1,   118,    -1,   117,
      -1,   116,    -1,   115,    -1,   136,    -1,   135,    -1,     4,
     170,   203,     6,    -1,     4,   140,   203,   141,   170,   203,
       6,    -1,     4,   140,   145,   210,   146,   141,   170,   208,
       6,    -1,     4,   140,   141,     7,   208,     6,    -1,     4,
     140,   141,   118,   208,     6,    -1,     4,   171,     6,    -1,
       4,   140,   203,   141,   171,     6,    -1,     4,     7,   215,
       6,    -1,     4,   142,     4,     7,   215,     6,    -1,     4,
     140,   203,   141,   142,     4,     7,   215,     6,    -1,     4,
     142,     4,   170,   203,     6,    -1,     4,   140,   203,   141,
     142,     4,   170,   203,     6,    -1,     4,   142,     4,   171,
       6,    -1,     4,   140,   203,   141,   142,     4,   171,     6,
      -1,     4,   142,    92,   142,     4,     7,   211,     6,    -1,
       4,   140,   203,   141,   142,    92,   142,     4,     7,   211,
       6,    -1,     4,   142,    93,     7,   212,     6,    -1,     4,
     140,   203,   141,   142,    93,     7,   212,     6,    -1,    64,
     138,     4,   139,   142,     4,     7,   203,     6,    -1,    64,
     138,     4,   139,   142,     4,     7,   215,     6,    -1,   203,
      -1,   215,    -1,    43,   138,   203,   139,     7,   205,     6,
      -1,    60,    43,   138,   173,   139,     7,   208,     6,    -1,
      77,    43,   100,   138,   203,   139,     7,   208,     6,    -1,
     103,   100,   138,   203,   139,     7,   203,     6,    -1,   105,
     100,   138,   203,   139,     7,   203,     6,    -1,   101,   100,
     138,   203,   139,     7,   208,     6,    -1,   108,   100,   138,
     203,   139,     7,     5,     6,    -1,   108,   100,   138,   203,
     139,     7,     5,   208,     6,    -1,   102,   100,   138,   203,
     139,     7,     5,     6,    -1,    52,    53,   100,   208,     6,
      -1,    77,    43,   208,     7,   208,     6,    -1,    77,    46,
     208,     7,   208,     6,    -1,    52,    53,   208,     7,   203,
       6,    -1,    46,   138,   203,   139,     7,   208,     6,    -1,
      50,   138,   203,   139,     7,   208,     6,    -1,    44,   138,
     203,   139,     7,   208,     6,    -1,    44,   138,   203,   139,
       7,   208,    56,   205,     6,    -1,    45,   138,   203,   139,
       7,   208,     6,    -1,    45,   138,   203,   139,     7,   208,
      56,   205,     6,    -1,    54,   138,   203,   139,     7,   145,
     203,   144,   203,   144,     5,   144,     5,   144,     5,   146,
       6,    -1,    87,   138,   203,   139,     7,   208,     6,    -1,
      88,   138,   203,   139,     7,   208,     6,    -1,    89,   138,
     203,   139,     7,   208,    91,   208,    90,   203,     6,    -1,
      46,    71,   138,   203,   139,     7,   208,     6,    -1,    60,
      46,   138,   173,   139,     7,   208,     6,    -1,    56,    49,
     138,   203,   139,     7,   208,     6,    -1,    57,    49,   138,
     203,   139,     7,   208,     6,    -1,    12,    13,     6,    -1,
      13,    49,   203,     6,    -1,    54,    49,   138,   203,   139,
       7,     5,     5,     5,     6,    -1,    47,   138,   203,   139,
       7,   208,     6,    -1,    48,   138,   203,   139,     7,   208,
       6,    -1,    49,    71,   138,   203,   139,     7,   208,     6,
      -1,    60,    49,   138,   173,   139,     7,   208,     6,    -1,
      59,    51,   138,   203,   139,     7,   208,     6,    -1,    51,
     138,   203,   139,     7,   208,     6,    -1,    60,    51,   138,
     173,   139,     7,   208,     6,    -1,    66,   205,   145,   176,
     146,    -1,    65,   145,   205,   144,   205,   144,   203,   146,
     145,   176,   146,    -1,    67,   205,   145,   176,   146,    -1,
      68,   145,   205,   144,   203,   146,   145,   176,   146,    -1,
      70,   145,   176,   146,    -1,    75,    46,   145,   210,   146,
      49,   145,   203,   146,    -1,    76,   145,   176,   146,    -1,
     177,    -1,   175,    -1,    -1,   177,   174,    -1,   177,    43,
     145,   210,   146,     6,    -1,   177,    46,   145,   210,   146,
       6,    -1,   177,    49,   145,   210,   146,     6,    -1,   177,
      51,   145,   210,   146,     6,    -1,    73,   145,   177,   146,
      -1,    73,     4,   140,   203,   141,     6,    -1,    73,     4,
       6,    -1,    73,     4,     4,     6,    -1,    92,   211,   145,
     177,   146,    -1,   109,   214,     6,    -1,   110,   214,     6,
      -1,   109,   145,   177,   146,    -1,   110,   145,   177,   146,
      -1,     4,   215,     6,    -1,     4,     4,   140,   203,   141,
     214,     6,    -1,     4,     4,     4,   140,   203,   141,     6,
      -1,     4,   203,     6,    -1,    64,   138,     4,   139,   142,
       4,     6,    -1,    86,     4,     6,    -1,    99,     6,    -1,
      40,     6,    -1,    40,   145,   203,   144,   203,   144,   203,
     144,   203,   144,   203,   144,   203,   146,     6,    -1,    41,
       6,    -1,    94,   138,   203,     8,   203,   139,    -1,    94,
     138,   203,     8,   203,     8,   203,   139,    -1,    94,     4,
      95,   145,   203,     8,   203,   146,    -1,    94,     4,    95,
     145,   203,     8,   203,     8,   203,   146,    -1,    96,    -1,
     108,     4,    -1,   106,    -1,   107,     4,     6,    -1,    97,
     138,   203,   139,    -1,    98,    -1,    69,   205,   145,   177,
     146,    -1,    69,   145,   205,   144,   205,   144,   203,   146,
     145,   177,   146,    -1,    69,   145,   205,   144,   205,   144,
     205,   144,   203,   146,   145,   177,   146,    -1,    -1,    69,
     205,   145,   177,   184,   198,   146,    -1,    -1,    69,   145,
     205,   144,   205,   144,   203,   146,   145,   177,   185,   198,
     146,    -1,    -1,    69,   145,   205,   144,   205,   144,   205,
     144,   203,   146,   145,   177,   186,   198,   146,    -1,    -1,
      69,   145,   177,   187,   198,   146,    -1,    -1,    69,     4,
     140,   203,   141,   145,   177,   188,   198,   146,    -1,    69,
      43,   145,   203,   144,   205,   146,     6,    -1,    69,    46,
     145,   203,   144,   205,   146,     6,    -1,    69,    49,   145,
     203,   144,   205,   146,     6,    -1,    69,    43,   145,   203,
     144,   205,   144,   205,   144,   203,   146,     6,    -1,    69,
      46,   145,   203,   144,   205,   144,   205,   144,   203,   146,
       6,    -1,    69,    49,   145,   203,   144,   205,   144,   205,
     144,   203,   146,     6,    -1,    69,    43,   145,   203,   144,
     205,   144,   205,   144,   205,   144,   203,   146,     6,    -1,
      69,    46,   145,   203,   144,   205,   144,   205,   144,   205,
     144,   203,   146,     6,    -1,    69,    49,   145,   203,   144,
     205,   144,   205,   144,   205,   144,   203,   146,     6,    -1,
      -1,    69,    43,   145,   203,   144,   205,   146,   189,   145,
     198,   146,     6,    -1,    -1,    69,    46,   145,   203,   144,
     205,   146,   190,   145,   198,   146,     6,    -1,    -1,    69,
      49,   145,   203,   144,   205,   146,   191,   145,   198,   146,
       6,    -1,    -1,    69,    43,   145,   203,   144,   205,   144,
     205,   144,   203,   146,   192,   145,   198,   146,     6,    -1,
      -1,    69,    46,   145,   203,   144,   205,   144,   205,   144,
     203,   146,   193,   145,   198,   146,     6,    -1,    -1,    69,
      49,   145,   203,   144,   205,   144,   205,   144,   203,   146,
     194,   145,   198,   146,     6,    -1,    -1,    69,    43,   145,
     203,   144,   205,   144,   205,   144,   205,   144,   203,   146,
     195,   145,   198,   146,     6,    -1,    -1,    69,    46,   145,
     203,   144,   205,   144,   205,   144,   205,   144,   203,   146,
     196,   145,   198,   146,     6,    -1,    -1,    69,    49,   145,
     203,   144,   205,   144,   205,   144,   205,   144,   203,   146,
     197,   145,   198,   146,     6,    -1,   199,    -1,   198,   199,
      -1,    78,   145,   203,   146,     6,    -1,    78,   145,   208,
     144,   208,   146,     6,    -1,    78,   145,   208,   144,   208,
     144,   208,   146,     6,    -1,    72,     6,    -1,    79,   138,
     203,   139,     7,   208,    61,   203,     6,    -1,    58,    46,
     208,     7,   203,     6,    -1,    58,    46,   208,     7,   203,
      61,    63,   203,     6,    -1,    58,    46,   208,     7,   203,
      61,    62,   203,     6,    -1,    58,    49,   145,   203,   146,
       7,   208,     6,    -1,    58,    49,   145,   203,   146,     7,
     208,     4,     6,    -1,    55,    49,   145,   203,   146,     7,
     208,     6,    -1,    58,    51,   145,   203,   146,     7,   208,
       6,    -1,    72,    49,   208,     7,   203,     6,    -1,    72,
      49,   208,     6,    -1,    43,   145,   210,   146,    95,    49,
     145,   203,   146,     6,    -1,    46,   145,   210,   146,    95,
      49,   145,   203,   146,     6,    -1,    46,   145,   210,   146,
      95,    51,   145,   203,   146,     6,    -1,    49,   145,   210,
     146,    95,    51,   145,   203,   146,     6,    -1,    74,     6,
      -1,   204,    -1,   138,   203,   139,    -1,   129,   203,    -1,
     128,   203,    -1,   133,   203,    -1,   203,   129,   203,    -1,
     203,   128,   203,    -1,   203,   130,   203,    -1,   203,   131,
     203,    -1,   203,   132,   203,    -1,   203,   137,   203,    -1,
     203,   124,   203,    -1,   203,   125,   203,    -1,   203,   127,
     203,    -1,   203,   126,   203,    -1,   203,   123,   203,    -1,
     203,   122,   203,    -1,   203,   121,   203,    -1,   203,   120,
     203,    -1,   203,   119,   203,     8,   203,    -1,    14,   138,
     203,   139,    -1,    15,   138,   203,   139,    -1,    16,   138,
     203,   139,    -1,    17,   138,   203,   139,    -1,    18,   138,
     203,   139,    -1,    19,   138,   203,   139,    -1,    20,   138,
     203,   139,    -1,    21,   138,   203,   139,    -1,    22,   138,
     203,   139,    -1,    24,   138,   203,   139,    -1,    25,   138,
     203,   144,   203,   139,    -1,    26,   138,   203,   139,    -1,
      27,   138,   203,   139,    -1,    28,   138,   203,   139,    -1,
      29,   138,   203,   139,    -1,    30,   138,   203,   139,    -1,
      31,   138,   203,   139,    -1,    32,   138,   203,   144,   203,
     139,    -1,    33,   138,   203,   144,   203,   139,    -1,    34,
     138,   203,   144,   203,   139,    -1,    23,   138,   203,   139,
      -1,    14,   140,   203,   141,    -1,    15,   140,   203,   141,
      -1,    16,   140,   203,   141,    -1,    17,   140,   203,   141,
      -1,    18,   140,   203,   141,    -1,    19,   140,   203,   141,
      -1,    20,   140,   203,   141,    -1,    21,   140,   203,   141,
      -1,    22,   140,   203,   141,    -1,    24,   140,   203,   141,
      -1,    25,   140,   203,   144,   203,   141,    -1,    26,   140,
     203,   141,    -1,    27,   140,   203,   141,    -1,    28,   140,
     203,   141,    -1,    29,   140,   203,   141,    -1,    30,   140,
     203,   141,    -1,    31,   140,   203,   141,    -1,    32,   140,
     203,   144,   203,   141,    -1,    33,   140,   203,   144,   203,
     141,    -1,    34,   140,   203,   144,   203,   141,    -1,    23,
     140,   203,   141,    -1,     3,    -1,     9,    -1,    10,    -1,
      11,    -1,   112,    -1,   113,    -1,   114,    -1,     4,    -1,
       4,   147,   145,   203,   146,    -1,     4,   140,   203,   141,
      -1,   143,     4,   140,   141,    -1,     4,   171,    -1,     4,
     140,   203,   141,   171,    -1,     4,   142,     4,    -1,     4,
     140,   203,   141,   142,     4,    -1,     4,   142,     4,   171,
      -1,     4,   140,   203,   141,   142,     4,   171,    -1,   111,
     138,     5,   144,   203,   139,    -1,   206,    -1,   129,   205,
      -1,   128,   205,    -1,   205,   129,   205,    -1,   205,   128,
     205,    -1,   145,   203,   144,   203,   144,   203,   144,   203,
     144,   203,   146,    -1,   145,   203,   144,   203,   144,   203,
     144,   203,   146,    -1,   145,   203,   144,   203,   144,   203,
     146,    -1,   138,   203,   144,   203,   144,   203,   139,    -1,
     208,    -1,   207,   144,   208,    -1,   203,    -1,   209,    -1,
     145,   146,    -1,   145,   210,   146,    -1,   129,   145,   210,
     146,    -1,   203,   130,   145,   210,   146,    -1,   129,   209,
      -1,   203,   130,   209,    -1,   203,     8,   203,    -1,   203,
       8,   203,     8,   203,    -1,    43,   145,   203,   146,    -1,
     175,    -1,   183,    -1,     4,   140,   141,    -1,     4,   140,
     145,   210,   146,   141,    -1,   203,    -1,   209,    -1,   210,
     144,   203,    -1,   210,   144,   209,    -1,   145,   203,   144,
     203,   144,   203,   144,   203,   146,    -1,   145,   203,   144,
     203,   144,   203,   146,    -1,     4,    -1,     4,   142,    92,
     142,     4,    -1,   145,   213,   146,    -1,     4,   140,   203,
     141,   142,    93,    -1,   211,    -1,   213,   144,   211,    -1,
     215,    -1,     4,    -1,     5,    -1,    42,    -1,    37,   138,
     214,   144,   214,   139,    -1,    38,   138,   214,   139,    -1,
      39,   138,   214,   139,    -1,    36,   138,   214,   139,    -1,
      36,   138,   214,   144,   210,   139,    -1,    36,   138,     4,
     142,     4,   139,    -1,    36,   138,     4,   140,   203,   141,
     142,     4,   139,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   143,   143,   144,   149,   151,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     172,   176,   183,   188,   203,   216,   245,   262,   271,   284,
     287,   288,   289,   290,   291,   295,   297,   302,   304,   310,
     454,   309,   468,   473,   482,   481,   496,   501,   510,   509,
     523,   528,   539,   538,   550,   551,   552,   553,   554,   558,
     559,   566,   597,   636,   690,   707,   725,   736,   753,   760,
     774,   791,   817,   844,   858,   875,   889,   906,   926,   949,
     959,   974,   978,   991,  1013,  1029,  1050,  1057,  1068,  1083,
    1091,  1106,  1113,  1125,  1159,  1195,  1217,  1235,  1253,  1271,
    1297,  1315,  1341,  1361,  1379,  1397,  1423,  1440,  1459,  1477,
    1515,  1519,  1523,  1528,  1550,  1572,  1588,  1608,  1625,  1642,
    1663,  1668,  1673,  1678,  1683,  1694,  1700,  1709,  1710,  1715,
    1718,  1722,  1745,  1768,  1791,  1819,  1828,  1841,  1857,  1872,
    1886,  1892,  1898,  1907,  1921,  1969,  1985,  2001,  2020,  2030,
    2052,  2056,  2061,  2066,  2078,  2093,  2109,  2134,  2160,  2191,
    2198,  2203,  2209,  2213,  2222,  2230,  2238,  2247,  2246,  2259,
    2258,  2271,  2270,  2283,  2282,  2294,  2293,  2309,  2316,  2323,
    2330,  2337,  2344,  2351,  2358,  2365,  2373,  2372,  2384,  2383,
    2395,  2394,  2406,  2405,  2417,  2416,  2428,  2427,  2439,  2438,
    2450,  2449,  2461,  2460,  2475,  2478,  2484,  2493,  2513,  2536,
    2540,  2564,  2582,  2600,  2618,  2647,  2682,  2687,  2714,  2728,
    2747,  2753,  2759,  2762,  2771,  2781,  2782,  2783,  2784,  2785,
    2786,  2787,  2788,  2789,  2796,  2797,  2798,  2799,  2800,  2801,
    2802,  2803,  2804,  2805,  2806,  2807,  2808,  2809,  2810,  2811,
    2812,  2813,  2814,  2815,  2816,  2817,  2818,  2819,  2820,  2821,
    2822,  2823,  2824,  2825,  2826,  2827,  2829,  2830,  2831,  2832,
    2833,  2834,  2835,  2836,  2837,  2838,  2839,  2840,  2841,  2842,
    2843,  2844,  2845,  2846,  2847,  2848,  2849,  2858,  2859,  2860,
    2861,  2862,  2863,  2864,  2868,  2884,  2899,  2919,  2932,  2945,
    2968,  2986,  3004,  3022,  3040,  3048,  3052,  3056,  3060,  3064,
    3071,  3075,  3079,  3083,  3090,  3095,  3103,  3108,  3112,  3117,
    3121,  3129,  3140,  3148,  3156,  3162,  3173,  3193,  3203,  3213,
    3230,  3257,  3262,  3266,  3270,  3283,  3287,  3299,  3306,  3327,
    3331,  3346,  3351,  3358,  3362,  3369,  3373,  3381,  3389,  3403,
    3417,  3421,  3440,  3462
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
  "tBoundingBox", "tDraw", "tToday", "tPoint", "tCircle", "tEllipse",
  "tLine", "tSphere", "tPolarSphere", "tSurface", "tSpline", "tVolume",
  "tCharacteristic", "tLength", "tParametric", "tElliptic", "tPlane",
  "tRuled", "tTransfinite", "tComplex", "tPhysical", "tUsing", "tBump",
  "tProgression", "tPlugin", "tRotate", "tTranslate", "tSymmetry",
  "tDilate", "tExtrude", "tDuplicata", "tLoop", "tRecombine", "tDelete",
  "tCoherence", "tIntersect", "tBoundary", "tAttractor", "tLayers",
  "tHole", "tAlias", "tAliasWithOptions", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tOrder", "tKnots", "tColor", "tColorTable", "tFor", "tIn",
  "tEndFor", "tIf", "tEndIf", "tExit", "tField", "tThreshold",
  "tStructured", "tLatLon", "tGrad", "tPostView", "tReturn", "tCall",
  "tFunction", "tShow", "tHide", "tGetValue", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tAFFECTDIVIDE",
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND",
  "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC", "tMINUSMINUS",
  "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'", "'#'", "','",
  "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems", "GeoFormatItem",
  "SendToFile", "Printf", "View", "Views", "ElementCoords",
  "ElementValues", "Element", "@1", "@2", "Text2DValues", "Text2D", "@3",
  "Text3DValues", "Text3D", "@4", "InterpolationMatrix", "Time", "@5",
  "NumericAffectation", "NumericIncrement", "Affectation", "PhysicalId",
  "Shape", "Transform", "MultipleShape", "ListOfShapes", "Delete",
  "Colorify", "Visibility", "Command", "Loop", "Extrude", "@6", "@7", "@8",
  "@9", "@10", "@11", "@12", "@13", "@14", "@15", "@16", "@17", "@18",
  "@19", "ExtrudeParameters", "ExtrudeParameter", "Transfinite",
  "Embedding", "Coherence", "FExpr", "FExpr_Single", "VExpr",
  "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,    63,
     374,   375,   376,   377,    60,    62,   378,   379,    43,    45,
      42,    47,    37,    33,   380,   381,   382,    94,    40,    41,
      91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   148,   149,   149,   150,   150,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     152,   152,   153,   153,   153,   153,   154,   154,   154,   155,
     155,   155,   155,   155,   155,   156,   156,   157,   157,   159,
     160,   158,   161,   161,   163,   162,   164,   164,   166,   165,
     167,   167,   169,   168,   170,   170,   170,   170,   170,   171,
     171,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   173,   173,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     175,   175,   175,   175,   175,   175,   175,   176,   176,   177,
     177,   177,   177,   177,   177,   178,   178,   178,   178,   179,
     180,   180,   180,   180,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   183,   183,   183,   184,   183,   185,
     183,   186,   183,   187,   183,   188,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   189,   183,   190,   183,
     191,   183,   192,   183,   193,   183,   194,   183,   195,   183,
     196,   183,   197,   183,   198,   198,   199,   199,   199,   199,
     199,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     201,   201,   201,   201,   202,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   205,   205,   205,   205,   205,
     206,   206,   206,   206,   207,   207,   208,   208,   208,   208,
     208,   208,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   210,   210,   210,   210,   211,   211,   211,   211,   212,
     212,   213,   213,   214,   214,   215,   215,   215,   215,   215,
     215,   215,   215,   215
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     5,     7,     7,     9,     6,     6,     6,     0,
       2,     2,     2,     2,     2,     1,     3,     1,     3,     0,
       0,    10,     1,     3,     0,    13,     1,     3,     0,    15,
       8,    14,     0,     6,     1,     1,     1,     1,     1,     1,
       1,     4,     7,     9,     6,     6,     3,     6,     4,     6,
       9,     6,     9,     5,     8,     8,    11,     6,     9,     9,
       9,     1,     1,     7,     8,     9,     8,     8,     8,     8,
       9,     8,     5,     6,     6,     6,     7,     7,     7,     9,
       7,     9,    17,     7,     7,    11,     8,     8,     8,     8,
       3,     4,    10,     7,     7,     8,     8,     8,     7,     8,
       5,    11,     5,     9,     4,     9,     4,     1,     1,     0,
       2,     6,     6,     6,     6,     4,     6,     3,     4,     5,
       3,     3,     4,     4,     3,     7,     7,     3,     7,     3,
       2,     2,    15,     2,     6,     8,     8,    10,     1,     2,
       1,     3,     4,     1,     5,    11,    13,     0,     7,     0,
      13,     0,    15,     0,     6,     0,    10,     8,     8,     8,
      12,    12,    12,    14,    14,    14,     0,    12,     0,    12,
       0,    12,     0,    16,     0,    16,     0,    16,     0,    18,
       0,    18,     0,    18,     1,     2,     5,     7,     9,     2,
       9,     6,     9,     9,     8,     9,     8,     8,     6,     4,
      10,    10,    10,    10,     2,     1,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     4,     2,     5,
       3,     6,     4,     7,     6,     1,     2,     2,     3,     3,
      11,     9,     7,     7,     1,     3,     1,     1,     2,     3,
       4,     5,     2,     3,     3,     5,     4,     1,     1,     3,
       6,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     1,     1,     1,     6,     4,     4,
       4,     6,     6,     9
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
     158,     0,   163,     0,     0,     0,     0,     0,   160,     0,
       0,     0,     0,     5,     7,     6,     8,     9,    10,    11,
      12,    13,    19,    18,    14,    15,    16,    17,   287,   294,
     345,    54,   288,   289,   290,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     346,     0,   291,   292,   293,    58,    57,    56,    55,     0,
       0,     0,    60,    59,     0,     0,     0,     0,     0,     0,
       0,   225,     0,     0,     0,     0,   151,     0,   153,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
     129,     0,   129,     0,     0,   129,   224,     0,   129,     0,
       0,     0,     0,     0,     0,     0,     0,   337,     0,     0,
       0,     0,     0,   150,     0,     0,     0,     0,     0,   159,
       0,   344,   345,   129,     0,   343,   129,     0,     0,     0,
       0,     0,   298,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   294,   228,   227,   229,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    66,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   144,   110,     0,     0,     0,     0,   294,     0,
       0,   327,   328,   331,   332,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     316,     0,   317,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   307,   306,
       0,     0,     0,     0,   129,   129,     0,     0,     0,     0,
       0,     0,     0,     0,   173,     0,   129,   128,     0,   127,
       0,     0,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,     0,     0,   129,     0,
       0,     0,     0,     0,     0,     0,   161,     0,     0,   140,
       0,   141,     0,     0,   300,     0,     0,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     344,     0,     0,     0,     0,     0,     0,   226,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,    61,     0,
     243,   242,   241,   240,   236,   237,   239,   238,   231,   230,
     232,   233,   234,   235,   111,     0,     0,     0,     0,     0,
       0,   227,   322,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    82,     0,     0,     0,     0,
       0,     0,     0,   309,   308,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,     0,
       0,   167,   124,   219,     0,   138,     0,   135,     0,   126,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,     0,     0,     0,     0,     0,   142,
     143,     0,   296,   302,     0,    39,     0,     0,     0,    52,
       0,    30,    31,    32,    33,    34,   245,   266,   246,   267,
     247,   268,   248,   269,   249,   270,   250,   271,   251,   272,
     252,   273,   253,   274,   265,   286,   254,   275,     0,     0,
     256,   277,   257,   278,   258,   279,   259,   280,   260,   281,
     261,   282,     0,     0,     0,     0,     0,     0,     0,     0,
     350,     0,     0,   348,   349,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,    73,     0,     0,     0,
       0,   297,     0,    22,    20,     0,     0,     0,     0,   329,
       0,     0,   324,   232,   323,   333,   334,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,   319,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,     0,   164,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   299,     0,   295,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   296,    64,    65,     0,     0,
       0,     0,     0,    67,    69,    71,     0,     0,   341,     0,
      77,   244,    21,     0,     0,     0,     0,     0,   326,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   320,     0,    95,     0,     0,     0,     0,
       0,   211,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,     0,     0,     0,     0,
       0,     0,     0,   209,     0,     0,   174,   205,     0,     0,
     218,   136,     0,     0,    93,    94,    27,    28,     0,     0,
       0,   338,     0,     0,     0,   154,     0,     0,     0,     0,
       0,   146,   301,   145,     0,     0,     0,     0,   314,     0,
     255,   276,   262,   283,   263,   284,   264,   285,     0,   352,
     351,   347,   304,     0,    54,     0,     0,     0,     0,    62,
       0,     0,     0,   339,    23,    24,     0,     0,    83,     0,
     325,     0,    98,     0,   100,     0,     0,    96,     0,     0,
     113,   114,     0,     0,    97,   118,   321,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,     0,     0,     0,     0,   129,   175,     0,   186,
       0,   188,     0,   190,     0,     0,     0,     0,   316,     0,
       0,     0,     0,   168,     0,     0,   103,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   303,     0,    35,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
      74,     0,     0,    75,     0,   342,     0,     0,   330,     0,
       0,     0,   106,     0,     0,   115,     0,     0,     0,   216,
     108,   109,     0,     0,     0,   214,   217,   117,    84,   107,
     116,   119,     0,     0,     0,   313,     0,   312,     0,     0,
       0,   177,     0,     0,   178,     0,     0,   179,     0,   131,
     132,   133,   134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   336,     0,   156,   155,    88,    91,    86,    87,
      89,     0,    40,     0,     0,     0,   315,     0,     0,     0,
       0,    63,    70,    72,     0,    78,     0,    25,     0,     0,
      99,   101,     0,     0,     0,     0,     0,   213,   212,   215,
      79,    80,   129,     0,   123,     0,     0,     0,     0,     0,
       0,     0,   206,     0,     0,   129,     0,   125,    85,     0,
       0,     0,    90,     0,    36,     0,     0,     0,    38,    53,
     353,     0,   340,     0,   220,   221,   222,   223,   112,     0,
       0,     0,   311,   176,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,     0,     0,   335,
     157,     0,     0,     0,     0,    76,     0,     0,   121,     0,
     192,     0,     0,   194,     0,     0,   196,     0,     0,     0,
     207,     0,   165,     0,   129,   105,     0,    44,     0,    50,
       0,     0,     0,   310,   180,     0,     0,   187,   181,     0,
       0,   189,   182,     0,     0,   191,     0,     0,     0,   171,
       0,     0,     0,     0,     0,     0,     0,   198,     0,   200,
       0,   202,   208,   210,   170,   166,     0,    41,     0,    48,
       0,     0,     0,     0,   183,     0,     0,   184,     0,     0,
     185,     0,     0,     0,    42,     0,     0,   152,     0,     0,
       0,     0,     0,     0,     0,   172,     0,     0,     0,     0,
       0,   193,     0,   195,     0,   197,     0,    43,    45,     0,
      46,     0,   102,     0,     0,     0,     0,     0,    51,   199,
     201,   203,    47,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    63,   665,    64,    65,   406,   978,   984,
     591,   756,  1113,  1233,   592,  1201,  1259,   593,  1235,   594,
     595,   760,   128,   222,    66,   523,   548,   311,   368,   369,
      69,    70,    71,    72,    73,   312,   729,  1173,  1216,   549,
    1029,  1032,  1035,  1038,  1185,  1189,  1193,  1225,  1228,  1231,
     725,   726,    75,    76,    77,   330,   131,   348,   173,   877,
     878,   332,   315,   199,   660,   789,   214,   215
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1058
static const yytype_int16 yypact[] =
{
    3256,    28,    52,  3334, -1058, -1058,  2425,    48,    25,   -47,
      10,    89,   -96,   -33,   -24,   126,    35,    73,   -41,    79,
     132,   110,    -8,   133,   229,   257,   368,   267,   725,   193,
     198,   -65,   -65,   206,   172,   220,   344,    13,   391,   357,
     271,    81,   435,   438,   450,   282,   331,   342,    15,     7,
   -1058,   347, -1058,   483,   401,   404,   407,   417, -1058,   518,
       8,     9,    20, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,    17,
     382,   516, -1058, -1058, -1058,   -68,   -55,    64,   141,   233,
     385,   392,   408,   425,   468,   472,   520,   567,   593,   626,
     648,   649,   655,   675,   678,   683,   399,   402,   422,   436,
   -1058,   445, -1058, -1058, -1058, -1058, -1058, -1058, -1058,  2648,
    2648,  2648, -1058, -1058,  2648,  2145,    19,   532,  2648,   539,
     470, -1058,   572,   611,  2648,   615, -1058,  2648, -1058,  2648,
    2480,  2648,  2648,   498,  2648,  2480,  2648,  2648,   501,  2480,
    2648,  2648,  1378,   524,  2648,   521,   547,   548,  1803,   533,
     564,   576,   583,   586,   594,   632,   716,   -65,   -65,   -65,
    2648,  2648,   -36, -1058,   476,   -65,   612,   628,   633,   652,
    2288,   499,   715,  1803,    22, -1058, -1058,   694,   715,  1528,
    1803,   637,   654,   820,  2648,  2648,  2648,   698,  2648,   710,
     748,  2648,  2648, -1058,   720,   736,   743,   756,   857, -1058,
     757, -1058, -1058, -1058,   897, -1058, -1058,   900,   770,  2648,
     903,   769, -1058, -1058,   912,  2648,  2648,  2648,  2648,  2648,
    2648,  2648,  2648,  2648,  2648,  2648,  2648,  2648,  2648,  2648,
    2648,  2648,  2648,  2648,  2648,  2648,  2648,  2648,  2648,  2648,
    2648,  2648,  2648,  2648,  2648,  2648,  2648,  2648,  2648,  2648,
    2648,  2648,  2648,  2648,  2648,  2648,  2648,   534,   614,   614,
     614,   920,   587,   799,   799,   799,  5335,    11,  2480,  4622,
     265,   796,   933,   801,   887, -1058, -1058,  2648,  2648,  2648,
    2648,  2648,  2648,  2648,  2648,  2648,  2648,  2648,  2648,  2648,
    2648,  2648, -1058, -1058,   906,   -84,  3868,  5356,   625,   797,
    2480, -1058, -1058,  1729, -1058,   537,  5377,  5398,  2648,  5419,
     681,  5440,  5461,  2648,   687,  5482,  5503,  1803,  1940,  1229,
    1866,   936, -1058,  2648,  5524,  2648,  2648,  2648,   939,  2648,
    2648,  2648,  2611,  2611,  2611,  2611,   809,   -29, -1058, -1058,
    3894,  3920,   -65,   -65,   715,   715,   180,  2648,  2648,  2648,
    2648,  2288,  2288,  2648,  3404,   235, -1058, -1058,   804,  3404,
     260,   945, -1058,  2648,  2751,  2480,   806,   815,   947,   948,
    2648,  2648, -1058,  5545,  5566,  5587,   864,  3946, -1058,   812,
    2003,  5608,  2648,  2648,  2648,  2648, -1058,  2648,  2817, -1058,
    2883, -1058,  2648,  4645,   240,  2648,     4, -1058,  5629,  4668,
    5650,  4691,  5671,  4714,  5692,  4737,  5713,  4760,  5734,  4783,
    5755,  4806,  5776,  4829,  5797,  4852,  5818,  4875,  5839,  4898,
    3972,  3998,  5860,  4921,  5881,  4944,  5902,  4967,  5923,  4990,
    5944,  5013,  5965,  5036,  4024,  4050,  4076,  4102,  4128,  4154,
     682,    -4,   814,   823,   840,   836,  2648, -1058,  1803,  1803,
     688,   187,   516,  2648,   977,   981,    16,   846, -1058,  2350,
     569,  1223,   759,   759,   545,   545,   545,   545,   182,   182,
     799,   799,   799,   799, -1058,    31,  2480,  2648,   982,  2214,
    2648,   799, -1058,  2648,  2480,  2480,   893,   983,   984,  5986,
     985,   902,   986,   988,  6007,   904,   991,   993,   995,  2480,
   -1058,   691,  2077,  2648,  6028,   996,  1454,  6049,  6070,  2648,
    2695,  2761,  6091,   863,  6448, -1058,   865,   881,   882,   880,
     -65,  2648,  2648, -1058, -1058,   894,   895,  2648,  5059,  4180,
    4206,  4232,  3842,   -44,   317,   -35,   -32,   942, -1058,   106,
     -65,  2949, -1058, -1058,  2648, -1058,  5082, -1058,   692, -1058,
    2648,  1803,  1803,  5105,  5128,  1032,  1038,  1039,   905,  2648,
    3015,  2648,  2648, -1058,  6112,  6133,  6154,  6175,  6196, -1058,
   -1058,  5151,    39, -1058,  2827, -1058,   911,   913,   907, -1058,
    1047, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,  2648,  2648,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058,  2648,  2648,  2648,  2648,  2648,  2648,  2648,  1050,
   -1058,  2480,   614, -1058, -1058,  2648,  5174,  1049,  1051,   915,
   -1058,    27,  2648,  1052,  1053,  1068, -1058,  1054,   922,    15,
    1057, -1058,  2648, -1058,   941,   614,   130,  4258,   -65, -1058,
    2480,  2893,  2452,   799, -1058,  1729, -1058,  1015,  1803,  1803,
    1060,  1803,   802,  1803,  1803,  1061,  1018,  1803,  1803, -1058,
     708, -1058,  2480,  1156,  1063,   926,  1065,  1066,  1071,   844,
    1073,  1076,  1077,  1080,  1081,  1082,  1084,  1088,   517,  4284,
    4310, -1058, -1058,  2959,   930,   -65,   -65,   -65,  2480,  2480,
    2480,  2480,  1090,   949,   960,   -39, -1058,   519, -1058,   106,
    1196,  1093,  1055,  6217,  1094,  1095,  1096,  1097,  1803,  1803,
    1803,  1101,  4336, -1058,  2577,   680,  1100,  1102,  1103,  1104,
    1107,  1109,  1112, -1058,  1111, -1058,   970,  2648,  2648,  1803,
     973, -1058,  6238,  5197,  6259,  5220,  6280,  5243,  6301,  5266,
    5289,   980,   205,   987,  6322,   336, -1058, -1058,   292,   328,
     979,  1115,  1303, -1058, -1058, -1058,    15,  2648, -1058,   718,
   -1058,  6448, -1058,  1117,    44,  2648,    61,   723, -1058,  2648,
     990,    23,    26,  1803,  1118,   994,   997,  1119,  1121,  1803,
     998,  1123,  1125, -1058,   724, -1058,  1128,  2648,  1803,  1803,
    1803, -1058,   322,  1803,  1803,  1803,  1803,  1803,  1803,  1803,
     444,  2648,  2648,  2648,   999, -1058,   -75,   415,   497,   729,
     733,   734,   754, -1058,  1803,  2648, -1058, -1058,  2288,    24,
   -1058, -1058,  1000,  1133, -1058, -1058, -1058, -1058,  1135,  1140,
    1056, -1058,  2648,  2648,  2648, -1058,  1803,  1144,  2648,  2648,
    1145, -1058,   240, -1058,  2648,  4362,  4388,   755, -1058,  2648,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,  1009, -1058,
   -1058, -1058, -1058,  1803,   516,  2648,  1146,  1149,    16, -1058,
    1148,  5312,    15, -1058, -1058, -1058,   614,  4414, -1058,  1014,
    6448,  2648, -1058,   -65, -1058,   -65,  1151, -1058,  2648,  2648,
   -1058, -1058,  1153,  2648, -1058, -1058, -1058,  1155,  4440,  1157,
    1159,  1160,  2648,  2648,   898,  1161,  1163,  1164,  1165,  1166,
    1167, -1058,  2611,  3025,  6343,  2266,   715,  3404,   -65,  1168,
     -65,  1170,   -65,  1171,  1173,  1174,  1175,  1176,   303,  1041,
    6364,  3091,   526, -1058,  2648,  1803, -1058, -1058,  1803,  3394,
     616,  6385,  1177,  1197,  1338,  1487,  1666, -1058,   222,  6448,
    2648,  2648,  1803,  1064,   767,  6448,  1202,  1204,  1205,  1593,
   -1058,  1201,  1206, -1058,  1072, -1058,  1207,  2648, -1058,  3152,
      84,    91, -1058,  3348,  3450, -1058,  3478,  1210,  2648, -1058,
   -1058, -1058,  1624,  1644,  1213, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058,  1776,  1214,  1083, -1058,  2648, -1058,  1085,   106,
     536, -1058,  1089,   540, -1058,  1091,   543, -1058,  1092, -1058,
   -1058, -1058, -1058,  1224,  1803,  1222,  1120,  2648,  3506,  1235,
    1178,  2648, -1058,  2648, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058,  1260, -1058,  2648,  4466,  4492, -1058,  1803,  2648,  1261,
    1130, -1058, -1058, -1058,    15, -1058,  1142, -1058,  4518,  1264,
   -1058, -1058,  1265,  1267,  1268,  1283,  4544, -1058, -1058, -1058,
   -1058, -1058,   715,  3422, -1058,    54,  2288,   106,  2288,   106,
    2288,   106, -1058,   773,  1803, -1058,  3534, -1058, -1058,  2648,
    3562,  3590, -1058,  1147,  6448,  2648,  2648,   777,  6448, -1058,
   -1058,  1284, -1058,  2648, -1058, -1058, -1058, -1058, -1058,  1295,
    1162,  2648, -1058, -1058,  3618,   575,   204,  3646,   582,   249,
    3674,   584,   290,  1803,  1296,  1240,  3081,  1158,  1903, -1058,
   -1058,  2648,  6406,  4570,    21, -1058,  4596,  1169, -1058,  3702,
    1300,  2648,  1301,  1304,  2648,  1305,  1306,  2648,  1308,  1183,
   -1058,  2648, -1058,   106, -1058, -1058,   778, -1058,  2648, -1058,
    1803,  2648,  1325, -1058, -1058,  1186,  3730, -1058, -1058,  1187,
    3758, -1058, -1058,  1189,  3786, -1058,  1329,  2243,   333,  3147,
    1330,  1192,  6427,   782,  3814,  1194,   106,  1333,   106,  1350,
     106,  1353, -1058, -1058, -1058, -1058,   106, -1058,   614, -1058,
    1216,  1358,  1360,   369, -1058,  1225,   380, -1058,  1226,   395,
   -1058,  1228,   403,   787, -1058,  1231,  1803, -1058,  1232,  1362,
     106,  1363,   106,  1371,   106, -1058,   614,  1373,   614,   788,
    1377, -1058,   416, -1058,   421, -1058,   440, -1058, -1058,   791,
   -1058,  1379, -1058,  1380,  1384,  1385,   614,  1407, -1058, -1058,
   -1058, -1058, -1058, -1058
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1058, -1058, -1058, -1058,   590, -1058, -1058, -1058, -1058,   263,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058,  -265,     0, -1058,   153,  1412,    -2,  -183,  -178,
   -1058, -1058, -1058, -1058, -1058,  1413, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
    -631,  -721, -1058, -1058, -1058,    -3, -1058,    34, -1058, -1057,
     398,   128,    38,  -637,   522, -1058,   -62,     3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     217,    68,   364,   130,   847,   376,   129,   374,   585,   132,
    1117,   200,   209,   211,   212,   463,   136,   184,   458,   197,
     658,   218,   788,   280,   211,   212,   371,  1179,   372,   912,
     148,   779,   914,   722,     4,   398,   148,   663,   400,   723,
     724,   153,   139,   211,   212,   106,   107,   108,   109,   140,
     905,   110,     5,   352,   353,   485,   106,   107,   108,   109,
     486,   133,   110,   168,   169,   172,   174,   908,   181,   948,
     225,   949,   226,   170,   134,   106,   107,   108,   109,   913,
     171,   110,   915,   227,   224,   228,   586,   587,   588,   589,
    1080,   135,   352,   353,   139,   138,   722,  1081,   849,   352,
     353,   718,   723,   724,   149,   141,   151,   846,   210,   354,
     720,   281,   282,   721,   142,   530,   273,   274,   275,   780,
     781,   276,   279,  1203,   189,   284,   722,   190,   847,   459,
     154,   304,   723,   724,   306,   640,   307,   313,   316,   317,
     641,   319,   313,   321,   322,   201,   313,   325,   326,   900,
     590,   334,   122,   123,   213,   137,   664,   219,   185,   220,
     198,   659,   373,   152,   221,   216,  1180,   350,   351,   664,
     963,   535,   536,   146,   122,   123,   176,   351,   722,  1249,
     367,   752,   155,   320,   723,   724,   367,   324,   551,   352,
     353,   383,   384,   385,   650,   387,   652,   143,   390,   391,
    1133,   347,   229,   349,   230,   451,   452,   453,   454,   356,
     570,   147,   352,   353,   365,   177,   403,   150,   178,   352,
     353,   179,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   144,   995,   553,   554,   314,   794,
     151,   145,   462,   314,   495,   313,   722,   314,   156,   231,
     464,   232,   723,   724,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   650,
     168,   169,   115,   116,   117,   118,   157,   491,   352,   353,
     170,   493,   298,   299,   300,   499,   460,   180,   161,   301,
     504,   722,   122,   123,   537,   491,   313,   723,   724,   651,
     514,   166,   516,   517,   518,   894,   520,   521,   522,   524,
     524,   524,   524,   167,   890,   525,   525,   525,   525,   495,
    1162,   175,   367,   367,   538,   539,   540,   541,   273,   274,
     542,  1062,   722,   352,   353,   182,  1063,   511,   723,   724,
     556,   233,   313,   234,   847,   122,   123,   563,   564,   550,
     115,   116,   117,   118,   932,   933,   533,   534,   143,   574,
     575,   576,   577,   183,   578,  1165,   349,   186,  1095,   581,
     122,   123,   584,   187,   583,   722,   314,   115,   116,   117,
     118,   723,   724,   558,   158,   847,   188,   159,   847,   160,
     194,   847,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   512,   299,   300,  1168,  1121,   492,   191,
     301,   722,   192,   115,   116,   117,   118,   723,   724,  1043,
     941,   942,   722,   646,   193,   144,   492,   314,   723,   724,
     655,   653,   719,   122,   123,   654,  1136,   722,  1139,   195,
    1142,   122,   123,   723,   724,   722,   286,   847,   752,  1214,
     196,   723,   724,   313,   667,   202,   646,   671,   722,   203,
     672,   673,   675,   722,   723,   724,   526,   527,   528,   723,
     724,   204,   847,   314,   205,   847,   313,   206,   847,   673,
     693,   847,   722,   893,   895,  1239,   699,   207,   723,   724,
     754,   212,   208,   235,   666,   236,  1241,   223,   709,   710,
     237,   847,   238,   847,   713,   847,   283,   267,   450,   212,
     268,  1243,  1198,   352,   353,   285,   239,   690,   240,  1245,
     331,   730,   106,   107,   108,   109,   338,   733,   110,   950,
     269,   951,  1263,   241,   708,   242,   742,  1264,   744,   745,
     106,   107,   108,   109,   270,  1223,   110,  1226,   302,  1229,
     773,   370,   753,   271,   727,  1232,  1265,   378,   379,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   793,   352,   353,   243,   301,   244,  1252,
     245,  1254,   246,  1256,   314,   762,   763,   303,   211,   212,
     305,   355,   674,   676,  1053,   352,   353,   352,   353,   764,
     765,   766,   767,   768,   769,   770,   318,   314,   313,   323,
     674,   952,   774,   953,   366,   352,   353,   352,   353,   782,
     106,   107,   108,   109,   352,   353,   110,   947,   247,   791,
     248,   831,   333,   848,   352,   353,   335,   313,   352,   353,
    1047,   352,   353,   296,   297,   298,   299,   300,   339,   772,
    1096,   495,   301,   496,  1098,   336,   337,  1100,   864,   313,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   796,   352,   353,   249,   301,   250,   797,   340,
     352,   353,   352,   353,   341,   313,   313,   313,   313,  1161,
     346,   342,   122,   123,   343,   508,  1164,   456,  1167,   220,
     814,   251,   344,   252,   221,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   836,
     837,   838,   357,   301,   875,   876,   839,   840,   841,   842,
     122,   123,  1054,  1028,   253,   489,   254,   220,   162,   314,
     345,   163,   221,   358,   164,   753,   165,   380,   359,   896,
      30,    31,    32,    33,   901,    35,   255,   257,   256,   258,
      39,    40,   907,   259,   381,   260,   910,   360,   314,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   261,   928,   262,   263,   301,   264,   865,
     314,   265,   638,   266,   639,   495,   382,   501,   943,   944,
     945,   495,   495,   505,   649,   495,   495,   691,   732,   375,
     386,   958,   960,   389,   996,   961,   314,   314,   314,   314,
     821,   805,   495,   806,   813,   388,   647,   648,   392,   969,
     970,   971,   902,   396,   903,   974,   975,   495,   495,   909,
     926,   979,   977,   495,   393,   954,   985,   495,   495,   955,
     956,   394,   962,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   989,   468,   395,   397,   301,   988,   495,   982,
     957,   983,  1014,   399,  1015,   822,   401,   404,   999,  1130,
     402,  1068,   484,  1069,   405,  1003,  1004,  1143,   407,  1144,
    1006,   982,  1068,  1154,  1200,   455,   982,  1146,  1220,  1012,
    1013,  1246,   982,  1247,  1261,  1266,   301,  1267,   465,  1022,
     466,   467,   490,   513,   367,  1023,   519,  1000,   529,  1001,
     552,   555,   559,   560,   561,   562,   568,   571,   642,   734,
     735,  1048,   643,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,  1064,  1065,   644,
     645,   301,  1030,   656,  1033,   657,  1036,   661,   677,   668,
     678,   679,   681,   683,  1078,   684,  1199,   682,   687,   686,
     688,   689,   703,   695,   704,  1086,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     705,   706,   707,  1093,   301,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   738,
     711,   712,   210,   301,  1106,   739,   740,   741,  1110,   757,
    1111,   758,   759,   761,   771,   776,   778,   777,   783,   784,
    1114,   786,   787,   790,   800,  1118,   792,   803,   809,   810,
     816,   817,   818,   819,   785,   835,   801,   802,   820,   804,
     823,   807,   808,   824,   825,   811,   812,   826,   827,   828,
     367,   829,   830,  1134,   844,  1137,   843,  1140,   845,   851,
     854,   855,   856,   857,   852,   861,  1148,   866,   874,   867,
     868,   869,  1152,  1153,   870,   871,   872,   873,   879,   889,
    1156,   897,   898,   904,   917,   920,   891,   921,  1159,   924,
    1135,   925,  1138,   927,  1141,   911,   858,   859,   860,   918,
     965,   966,   919,   923,   946,   964,   967,   968,   985,   973,
     976,   986,   990,   991,   993,   998,  1234,  1002,  1186,  1005,
    1007,  1190,   815,  1009,  1194,  1010,  1011,  1016,  1197,  1017,
    1018,  1019,  1020,  1021,  1031,  1202,  1034,  1037,  1204,  1039,
    1040,  1041,  1042,  1056,  1257,  1044,  1260,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   916,   850,  1057,  1272,   301,  1070,   922,  1074,  1067,
    1071,  1072,  1075,  1077,  1076,  1085,   929,   930,   931,  1089,
    1091,   934,   935,   936,   937,   938,   939,   940,  1092,  1104,
    1102,  1094,    78,   308,  1097,  1122,  1099,  1101,    82,    83,
      84,  1108,   959,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   972,  1105,  1112,  1119,  1109,  1120,
    1124,  1125,   309,  1126,  1127,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,  1128,
    1155,   987,  1151,   301,    30,    31,    32,    33,    34,    35,
    1157,  1171,  1170,  1174,    39,    40,  1184,  1187,  1158,   899,
    1188,  1191,  1192,  1182,  1195,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,  1196,
    1205,  1206,  1208,   301,  1210,  1212,  1217,  1218,  1222,  1224,
     111,   112,   113,   114,  1058,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,  1227,   119,   310,  1230,
     301,  1236,   121,  1049,  1237,  1238,  1050,   124,  1251,  1253,
    1240,  1242,   127,  1244,  1061,   510,  1248,  1255,  1250,  1258,
    1066,    78,   308,  1262,   906,  1268,  1269,    82,    83,    84,
    1270,  1271,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,  1273,  1176,    67,    74,     0,     0,     0,
     992,   309,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,  1103,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,    39,    40,     0,     0,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,   327,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,  1059,     0,     0,     0,     0,     0,     0,
       0,     0,  1145,     0,     0,     0,   119,   328,     0,     0,
       0,   121,     0,     0,     0,     0,   124,     0,     0,     0,
       0,   127,     0,   329,     0,     0,     0,     0,     0,     0,
       0,    78,   308,     0,     0,     0,     0,    82,    83,    84,
       0,  1169,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
       0,   309,     0,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,    30,    31,    32,    33,    34,    35,  1073,
     696,     0,     0,    39,    40,     0,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,   377,     0,
    1087,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
    1088,     0,     0,     0,     0,     0,   119,   328,     0,     0,
       0,   121,     0,     0,     0,     0,   124,     0,     0,    78,
     308,   127,  1060,   329,     0,    82,    83,    84,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,     0,     0,     0,     0,     0,   309,
       0,     0,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,    30,    31,    32,    33,    34,    35,   493,     0,     0,
       0,    39,    40,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   111,   112,   113,
     114,   301,  1090,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   328,     0,     0,     0,   121,
       0,     0,     0,     0,   124,     0,    78,   308,     0,   127,
       0,   329,    82,    83,    84,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     0,   309,     0,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   494,
     299,   300,     0,     0,     0,     0,   301,     0,    30,    31,
      32,    33,    34,    35,   493,     0,     0,     0,    39,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,  1175,
       0,     0,     0,   301,   111,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,   328,     0,     0,     0,   121,     0,     0,     0,
       0,   124,     0,    78,   308,     0,   127,     0,   329,    82,
      83,    84,     0,     0,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,   309,     0,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   512,   299,   300,     0,
       0,     0,     0,   301,     0,    30,    31,    32,    33,    34,
      35,   572,     0,     0,     0,    39,    40,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,   310,
       0,     0,     0,   121,     0,     0,     0,     0,   124,     0,
      78,   308,     0,   127,     0,   509,    82,    83,    84,     0,
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
     309,     0,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,    30,    31,    32,    33,    34,    35,    78,   272,
       0,     0,    39,    40,    82,    83,    84,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   119,   310,     0,     0,     0,
     121,     0,     0,     0,     0,   124,     0,    78,   272,     0,
     127,     0,   692,    82,    83,    84,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,  1213,
       0,     0,     0,     0,     0,     0,   111,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,   120,     0,     0,     0,   121,     0,
       0,     0,     0,   124,     0,     0,   277,     0,   127,     0,
     278,    78,   272,     0,     0,     0,     0,    82,    83,    84,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,   111,   112,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   120,     0,     0,     0,   121,     0,     0,
       0,     0,   124,     0,     0,   669,     0,   127,   662,   670,
       0,     0,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   111,
     112,   113,   114,   301,     0,     0,     0,     0,     0,     0,
    1026,     0,  1027,     0,     0,     0,   361,   362,     0,     0,
       0,   121,     0,     0,     0,     0,   363,     0,    78,    79,
      80,   127,    81,   171,    82,    83,    84,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     799,   106,   107,   108,   109,     0,     0,   110,     0,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,    78,   308,     0,     0,   301,     0,    82,
      83,    84,     0,     0,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,   309,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,     0,    30,    31,    32,    33,    34,
      35,     0,     0,   119,   120,    39,    40,     0,   121,     0,
     122,   123,     0,   124,     0,   125,     0,   126,   127,     0,
       0,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   863,     0,     0,     0,   301,
       0,   111,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,   310,
       0,     0,     0,   121,    78,   272,   212,     0,   124,     0,
      82,    83,    84,   127,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,   106,   107,   108,
     109,    78,   272,   110,     0,     0,     0,    82,    83,    84,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,     0,     0,
       0,     0,   111,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
     120,     0,     0,     0,   121,     0,     0,     0,     0,   124,
       0,     0,     0,     0,   127,     0,     0,     0,     0,   111,
     112,   113,   114,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   119,   120,     0,     0,
       0,   121,     0,     0,     0,     0,   124,     0,     0,     0,
       0,   127,     0,     0,   543,    13,    14,   544,    16,    17,
     545,    19,   546,    21,     0,    22,     0,    24,    25,     0,
      27,    28,     0,     0,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,    41,     7,
       8,     0,   301,     0,     0,     0,     0,     0,    45,    46,
      47,   700,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    55,    56,     0,    57,     0,     0,   547,
     543,    13,    14,   544,    16,    17,   545,    19,   546,    21,
       0,    22,     0,    24,    25,     0,    27,    28,     0,     0,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,    41,     7,     8,   557,   301,     0,
       0,     0,     0,     0,    45,    46,    47,   701,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    55,
      56,     0,    57,     0,     0,   547,   543,    13,    14,   544,
      16,    17,   545,    19,   546,    21,     0,    22,     0,    24,
      25,     0,    27,    28,     0,     0,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
      41,     7,     8,   579,   301,     0,     0,     0,     0,     0,
      45,    46,    47,   755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,    55,    56,     0,    57,     0,
       0,   547,   543,    13,    14,   544,    16,    17,   545,    19,
     546,    21,     0,    22,     0,    24,    25,     0,    27,    28,
       0,     0,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    41,     7,     8,   580,
     301,     0,     0,     0,     0,     0,    45,    46,    47,   798,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    55,    56,     0,    57,     0,     0,   547,   543,    13,
      14,   544,    16,    17,   545,    19,   546,    21,     0,    22,
       0,    24,    25,     0,    27,    28,     0,     0,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,    41,     7,     8,   728,   301,     0,     0,     0,
       0,     0,    45,    46,    47,   834,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    55,    56,     0,
      57,     0,     0,   547,   543,    13,    14,   544,    16,    17,
     545,    19,   546,    21,     0,    22,     0,    24,    25,     0,
      27,    28,     0,     0,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,    41,     7,
       8,   743,   301,     0,     0,     0,     0,     0,    45,    46,
      47,  1024,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    55,    56,     0,    57,     0,     0,   547,
     543,    13,    14,   544,    16,    17,   545,    19,   546,    21,
       0,    22,     0,    24,    25,     0,    27,    28,     0,     0,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,    41,     0,     0,  1172,   301,     0,
       0,     0,     0,     0,    45,    46,    47,  1046,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    55,
      56,     0,    57,     0,     0,   547,    -4,     1,     0,     0,
      -4,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,    -4,     0,  1215,     0,     0,    -4,    -4,  1079,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,    -4,     6,     0,
       0,     0,    -4,    -4,    -4,    -4,     7,     8,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     9,
       0,     0,     0,     0,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,    22,    23,
      24,    25,    26,    27,    28,     0,     0,     0,    29,    30,
      31,    32,    33,    34,    35,     0,    36,    37,    38,    39,
      40,    41,     0,     0,    42,    43,     7,     8,     0,     0,
      44,    45,    46,    47,     0,     0,    48,     0,    49,     0,
      50,    51,    52,    53,     0,    54,    55,    56,     0,    57,
      58,    59,    60,    61,    62,     0,     0,   543,    13,    14,
     544,    16,    17,   545,    19,   546,    21,     0,    22,     0,
      24,    25,     0,    27,    28,     0,     0,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,    41,     0,     0,     0,   301,     0,     0,     0,     0,
       0,    45,    46,    47,  1082,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    55,    56,     0,    57,
       0,     0,   547,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,     0,     0,     0,  1051,     0,
    1052,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,     0,     0,     0,     0,     0,  1131,     0,  1132,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,     0,     0,     0,     0,     0,  1083,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,     0,     0,
       0,     0,     0,     0,  1084,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,     0,     0,     0,
       0,     0,  1107,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,     0,     0,     0,     0,     0,
    1147,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,     0,     0,     0,     0,     0,     0,     0,  1149,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,     0,     0,     0,     0,     0,  1150,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,     0,     0,
       0,     0,     0,     0,  1160,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,     0,     0,     0,
       0,     0,  1163,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,     0,     0,     0,     0,     0,
    1166,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,     0,     0,     0,     0,     0,     0,     0,  1183,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,     0,     0,     0,     0,     0,  1207,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,     0,     0,
       0,     0,     0,     0,  1209,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,     0,     0,     0,
       0,     0,  1211,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,     0,     0,     0,     0,     0,
    1221,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,   457,     0,     0,     0,     0,   531,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,     0,     0,
       0,     0,   487,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,     0,     0,     0,   531,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,     0,     0,     0,   532,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,     0,     0,     0,
     569,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,     0,     0,     0,     0,     0,   618,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,     0,     0,
       0,     0,   619,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,     0,     0,     0,   632,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,     0,     0,     0,   633,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,     0,     0,     0,
     634,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,     0,     0,     0,     0,     0,   635,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,     0,     0,
       0,     0,   636,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,     0,     0,     0,   637,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,     0,     0,     0,   715,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,     0,     0,     0,
     716,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,     0,     0,     0,     0,     0,   717,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,     0,     0,
       0,     0,   795,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,     0,     0,     0,   832,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,     0,     0,     0,   833,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,     0,     0,     0,
     862,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,     0,     0,     0,     0,     0,   980,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,     0,     0,
       0,     0,   981,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,     0,     0,     0,   997,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,     0,     0,     0,  1008,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,     0,     0,     0,
    1115,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,     0,     0,     0,     0,     0,  1116,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,     0,     0,
       0,     0,  1123,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,     0,     0,     0,  1129,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,     0,     0,     0,  1178,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,     0,     0,     0,
    1181,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,     0,     0,   461,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,   582,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,     0,   597,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,   599,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,   601,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,   603,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,   605,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,   607,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,   609,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
     611,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,     0,     0,   613,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,   615,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,     0,   617,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,   621,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,   623,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,   625,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,   627,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,   629,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,   631,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
     714,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,     0,     0,   731,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,   736,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,     0,   737,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,   751,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,   775,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,   881,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,   883,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,   885,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,   887,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
     888,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,     0,     0,   994,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,   457,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,   488,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,   497,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,   498,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,   500,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,   502,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
     503,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,   506,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,   507,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,   515,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,   565,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,   566,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,   567,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,   573,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,   596,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,   598,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
     600,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,   602,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,   604,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,   606,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,   608,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,   610,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,   612,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,   614,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,   616,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,   620,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
     622,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,   624,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,   626,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,   628,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,   630,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,   680,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,   685,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,   694,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,   697,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,   698,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
     702,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,   746,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,   747,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,   748,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,   749,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,   750,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,   853,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,   880,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,   882,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,   884,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
     886,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,   892,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,  1025,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,  1045,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,  1055,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,  1177,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,  1219,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301
};

static const yytype_int16 yycheck[] =
{
      62,     3,   180,     6,   725,   188,     6,   185,     4,     6,
    1067,     4,     4,     4,     5,   280,     6,     4,     7,     4,
       4,     4,   659,     4,     4,     5,     4,     6,     6,     6,
      71,     4,     6,    72,     6,   213,    71,     6,   216,    78,
      79,    49,   138,     4,     5,    36,    37,    38,    39,   145,
       6,    42,     0,   128,   129,   139,    36,    37,    38,    39,
     144,    13,    42,   128,   129,    31,    32,     6,    34,   144,
     138,   146,   140,   138,    49,    36,    37,    38,    39,    56,
     145,    42,    56,   138,    81,   140,    82,    83,    84,    85,
       6,   138,   128,   129,   138,     6,    72,     6,   729,   128,
     129,   145,    78,    79,   145,   138,   138,   146,   100,   145,
     145,    92,    93,   145,   138,   144,   119,   120,   121,    92,
      93,   124,   125,  1180,    43,   128,    72,    46,   849,   118,
     138,   134,    78,    79,   137,   139,   139,   140,   141,   142,
     144,   144,   145,   146,   147,   138,   149,   150,   151,   786,
     146,   154,   135,   136,   145,   145,   125,   140,   145,   142,
     145,   145,   140,    53,   147,   145,   145,   170,   171,   125,
     146,   354,   355,   138,   135,   136,     4,   180,    72,  1236,
     182,   142,    49,   145,    78,    79,   188,   149,   366,   128,
     129,   194,   195,   196,     7,   198,   461,    71,   201,   202,
     146,   167,   138,   169,   140,   267,   268,   269,   270,   175,
     388,   138,   128,   129,   180,    43,   219,   138,    46,   128,
     129,    49,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   138,   902,     6,     7,   140,   139,
     138,   145,     7,   145,   144,   278,    72,   149,    49,   138,
     280,   140,    78,    79,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,     7,
     128,   129,   115,   116,   117,   118,    49,   310,   128,   129,
     138,     8,   130,   131,   132,   318,   278,   145,    51,   137,
     323,    72,   135,   136,   144,   328,   329,    78,    79,   142,
     333,   138,   335,   336,   337,     7,   339,   340,   341,   342,
     343,   344,   345,   145,   139,   342,   343,   344,   345,   144,
     146,   145,   354,   355,   357,   358,   359,   360,   361,   362,
     363,   139,    72,   128,   129,   145,   144,   329,    78,    79,
     373,   138,   375,   140,  1095,   135,   136,   380,   381,   144,
     115,   116,   117,   118,    62,    63,   352,   353,    71,   392,
     393,   394,   395,    49,   397,   146,   362,     6,  1029,   402,
     135,   136,   405,    46,   404,    72,   278,   115,   116,   117,
     118,    78,    79,   375,    46,  1136,   145,    49,  1139,    51,
     138,  1142,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   146,  1074,   310,     4,
     137,    72,     4,   115,   116,   117,   118,    78,    79,   146,
       6,     7,    72,   456,     4,   138,   328,   329,    78,    79,
     463,   461,   145,   135,   136,   462,  1097,    72,  1099,   138,
    1101,   135,   136,    78,    79,    72,     6,  1198,   142,   146,
     138,    78,    79,   486,   487,   138,   489,   490,    72,     6,
     493,   494,   495,    72,    78,    79,   343,   344,   345,    78,
      79,   100,  1223,   375,   100,  1226,   509,   100,  1229,   512,
     513,  1232,    72,   778,   779,   146,   519,   100,    78,    79,
     582,     5,     4,   138,   486,   140,   146,   145,   531,   532,
     138,  1252,   140,  1254,   537,  1256,     4,   138,     4,     5,
     138,   146,  1173,   128,   129,     6,   138,   509,   140,   146,
     152,   554,    36,    37,    38,    39,   158,   560,    42,   144,
     138,   146,   146,   138,   530,   140,   569,   146,   571,   572,
      36,    37,    38,    39,   138,  1206,    42,  1208,     6,  1210,
     642,   183,   582,   138,   550,  1216,   146,   189,   190,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   665,   128,   129,   138,   137,   140,  1240,
     138,  1242,   140,  1244,   486,   618,   619,     6,     4,     5,
       5,   145,   494,   495,     8,   128,   129,   128,   129,   632,
     633,   634,   635,   636,   637,   638,   138,   509,   641,   138,
     512,   144,   645,   146,   145,   128,   129,   128,   129,   652,
      36,    37,    38,    39,   128,   129,    42,   835,   138,   662,
     140,   144,   138,   144,   128,   129,   145,   670,   128,   129,
     144,   128,   129,   128,   129,   130,   131,   132,   145,   641,
     144,   144,   137,   146,   144,   138,   138,   144,     8,   692,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   668,   128,   129,   138,   137,   140,   670,   145,
     128,   129,   128,   129,   138,   718,   719,   720,   721,   144,
       4,   138,   135,   136,   138,   327,   144,   140,   144,   142,
     692,   138,   138,   140,   147,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   715,
     716,   717,   140,   137,   757,   758,   718,   719,   720,   721,
     135,   136,   146,   946,   138,   140,   140,   142,    43,   641,
     138,    46,   147,   145,    49,   775,    51,   140,   145,   779,
      65,    66,    67,    68,   787,    70,   138,   138,   140,   140,
      75,    76,   795,   138,   140,   140,   799,   145,   670,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   138,   817,   140,   138,   137,   140,   139,
     692,   138,   140,   140,   142,   144,     6,   146,   831,   832,
     833,   144,   144,   146,   146,   144,   144,   146,   146,   145,
     142,   844,   845,    95,   906,   848,   718,   719,   720,   721,
       6,    49,   144,    51,   146,   145,   458,   459,   138,   862,
     863,   864,   144,     6,   146,   868,   869,   144,   144,   146,
     146,   874,   872,   144,   138,   146,   879,   144,   144,   146,
     146,   138,   848,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   895,     6,   138,   138,   137,   894,   144,   144,
     146,   146,     4,     6,     6,    61,     6,     4,   911,  1092,
     140,   144,     6,   146,   145,   918,   919,   144,     6,   146,
     923,   144,   144,   146,   146,     5,   144,  1105,   146,   932,
     933,   144,   144,   146,   146,   144,   137,   146,   142,   942,
       7,   140,   145,     7,   946,   942,     7,   913,   139,   915,
     146,     6,   146,   138,     7,     7,    92,   145,   144,   561,
     562,   964,   139,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   980,   981,   139,
     144,   137,   948,     6,   950,     4,   952,   141,    95,     7,
       7,     7,     7,     7,   997,     7,  1174,    95,     7,    95,
       7,     6,   139,     7,   139,  1008,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     139,   139,   142,  1026,   137,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,     7,
     146,   146,   100,   137,  1047,     7,     7,   142,  1051,   138,
    1053,   138,   145,     6,     4,     6,   141,     6,     6,     6,
    1063,     7,   140,     6,    49,  1068,   125,     7,     7,    51,
       7,   145,     7,     7,     6,   145,   678,   679,     7,   681,
       7,   683,   684,     7,     7,   687,   688,     7,     7,     7,
    1092,     7,     4,  1096,   145,  1098,     6,  1100,   138,     6,
       6,     6,     6,     6,    49,     4,  1109,     7,   138,     7,
       7,     7,  1115,  1116,     7,     6,     4,     6,   145,   139,
    1123,   142,     7,     6,     6,     6,   139,     6,  1131,     6,
    1096,     6,  1098,     5,  1100,   145,   738,   739,   740,   145,
       7,     6,   145,   145,   145,   145,     6,    91,  1151,     5,
       5,   142,     6,     4,     6,   141,  1218,     6,  1161,     6,
       5,  1164,     6,     6,  1167,     6,     6,     6,  1171,     6,
       6,     6,     6,     6,     6,  1178,     6,     6,  1181,     6,
       6,     6,     6,     6,  1246,   144,  1248,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   803,     6,     6,  1266,   137,     4,   809,     7,   145,
       6,     6,     6,     6,   142,     5,   818,   819,   820,     6,
       6,   823,   824,   825,   826,   827,   828,   829,   145,     7,
       6,   146,     3,     4,   145,    93,   145,   145,     9,    10,
      11,     6,   844,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,   866,   145,     6,     6,    90,   139,
       6,     6,    43,     6,     6,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,     6,
       6,   893,   145,   137,    65,    66,    67,    68,    69,    70,
       5,    61,     6,   145,    75,    76,     6,     6,   146,     6,
       6,     6,     6,   144,     6,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   146,
       5,   145,   145,   137,   145,     6,     6,   145,   144,     6,
     111,   112,   113,   114,     6,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,     6,   128,   129,     6,
     137,   145,   133,   965,     6,     5,   968,   138,     6,     6,
     145,   145,   143,   145,   976,   146,   145,     6,   146,     6,
     982,     3,     4,     6,   794,     6,     6,     9,    10,    11,
       6,     6,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     6,  1151,     3,     3,    -1,    -1,    -1,
     898,    43,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,    -1,  1044,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    75,    76,    -1,    -1,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1104,    -1,    -1,    -1,   128,   129,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,   143,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,  1143,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    65,    66,    67,    68,    69,    70,     6,
     146,    -1,    -1,    75,    76,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,   100,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,     3,
       4,   143,     6,   145,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,    65,    66,    67,    68,    69,    70,     8,    -1,    -1,
      -1,    75,    76,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   111,   112,   113,
     114,   137,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,   133,
      -1,    -1,    -1,    -1,   138,    -1,     3,     4,    -1,   143,
      -1,   145,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,   137,    -1,    65,    66,
      67,    68,    69,    70,     8,    -1,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,     6,
      -1,    -1,    -1,   137,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,   138,    -1,     3,     4,    -1,   143,    -1,   145,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,    65,    66,    67,    68,    69,
      70,     8,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
      -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,   138,    -1,
       3,     4,    -1,   143,    -1,   145,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,    -1,    65,    66,    67,    68,    69,    70,     3,     4,
      -1,    -1,    75,    76,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,   138,    -1,     3,     4,    -1,
     143,    -1,   145,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     6,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,   141,    -1,   143,    -1,
     145,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,   111,   112,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,   141,    -1,   143,     8,   145,
      -1,    -1,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,    -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   111,
     112,   113,   114,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,    -1,   146,    -1,    -1,    -1,   128,   129,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    -1,   138,    -1,     3,     4,
       5,   143,     7,   145,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       8,    36,    37,    38,    39,    -1,    -1,    42,    -1,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,     3,     4,    -1,    -1,   137,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,    65,    66,    67,    68,    69,
      70,    -1,    -1,   128,   129,    75,    76,    -1,   133,    -1,
     135,   136,    -1,   138,    -1,   140,    -1,   142,   143,    -1,
      -1,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,     8,    -1,    -1,    -1,   137,
      -1,   111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
      -1,    -1,    -1,   133,     3,     4,     5,    -1,   138,    -1,
       9,    10,    11,   143,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,     3,     4,    42,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,   143,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    -1,    56,    57,    -1,
      59,    60,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    77,    12,
      13,    -1,   137,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,   103,    -1,   105,    -1,    -1,   108,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    -1,    56,    57,    -1,    59,    60,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    77,    12,    13,   146,   137,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,
     103,    -1,   105,    -1,    -1,   108,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    -1,    56,
      57,    -1,    59,    60,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      77,    12,    13,   146,   137,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,   146,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,   103,    -1,   105,    -1,
      -1,   108,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    -1,    56,    57,    -1,    59,    60,
      -1,    -1,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    77,    12,    13,   146,
     137,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,   146,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,   103,    -1,   105,    -1,    -1,   108,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      -1,    56,    57,    -1,    59,    60,    -1,    -1,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    77,    12,    13,   146,   137,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,   146,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,   103,    -1,
     105,    -1,    -1,   108,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    -1,    56,    57,    -1,
      59,    60,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    77,    12,
      13,   146,   137,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,   103,    -1,   105,    -1,    -1,   108,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    -1,    56,    57,    -1,    59,    60,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    77,    -1,    -1,   146,   137,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,
     103,    -1,   105,    -1,    -1,   108,     0,     1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,    35,    -1,   146,    -1,    -1,    40,    41,   146,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,     4,    -1,
      -1,    -1,    86,    87,    88,    89,    12,    13,    92,    -1,
      94,    -1,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,   105,   106,   107,   108,   109,   110,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    12,    13,    -1,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    -1,    94,    -1,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,   105,
     106,   107,   108,   109,   110,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    -1,
      56,    57,    -1,    59,    60,    -1,    -1,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    77,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    87,    88,    89,   146,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,   103,    -1,   105,
      -1,    -1,   108,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
     146,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,   146,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,   139,    -1,    -1,    -1,    -1,   144,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,   141,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,   137,    -1,    -1,    -1,   141,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,   141,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,
      -1,    -1,   141,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,   141,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,   141,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,   141,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,    -1,    -1,    -1,   141,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,   141,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
     141,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,   141,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,   137,    -1,    -1,    -1,   141,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,   141,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,
      -1,    -1,   141,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,   141,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,   141,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,   141,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,    -1,    -1,    -1,   141,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,   141,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
     141,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,   141,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,   137,    -1,    -1,    -1,   141,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,   141,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,
      -1,    -1,   141,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,   141,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,   141,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,   141,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,    -1,    -1,    -1,   141,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,   141,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
     141,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,   141,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,   137,    -1,   139,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,   139,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,   137,    -1,   139,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,   139,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,   137,    -1,   139,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,   139,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,
     139,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,   139,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,    -1,   139,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,   139,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,   137,    -1,   139,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,   139,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,   137,    -1,   139,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,   139,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,   137,    -1,   139,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,   139,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,
     139,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,   139,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,    -1,   139,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,   139,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,   137,    -1,   139,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,   139,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,   137,    -1,   139,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,   139,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,   137,    -1,   139,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,   139,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,
     139,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,   139,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,    -1,   139,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,   139,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,   137,    -1,   139,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,   139,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,   137,    -1,   139,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,   139,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,   137,    -1,   139,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,   139,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,
     139,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,   139,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,    -1,   139,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,   139,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,   137,    -1,   139,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,   139,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,   137,    -1,   139,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,   139,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,   137,    -1,   139,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,   139,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,
     139,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,   139,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,    -1,   139,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,   139,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,   137,    -1,   139,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    -1,   139,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,   137,    -1,   139,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,   137
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   149,   150,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    55,    56,    57,    58,    59,    60,    64,
      65,    66,    67,    68,    69,    70,    72,    73,    74,    75,
      76,    77,    80,    81,    86,    87,    88,    89,    92,    94,
      96,    97,    98,    99,   101,   102,   103,   105,   106,   107,
     108,   109,   110,   151,   153,   154,   172,   174,   175,   178,
     179,   180,   181,   182,   183,   200,   201,   202,     3,     4,
       5,     7,     9,    10,    11,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    36,    37,    38,    39,
      42,   111,   112,   113,   114,   115,   116,   117,   118,   128,
     129,   133,   135,   136,   138,   140,   142,   143,   170,   171,
     203,   204,   215,    13,    49,   138,     6,   145,     6,   138,
     145,   138,   138,    71,   138,   145,   138,   138,    71,   145,
     138,   138,    53,    49,   138,    49,    49,    49,    46,    49,
      51,    51,    43,    46,    49,    51,   138,   145,   128,   129,
     138,   145,   205,   206,   205,   145,     4,    43,    46,    49,
     145,   205,   145,    49,     4,   145,     6,    46,   145,    43,
      46,     4,     4,     4,   138,   138,   138,     4,   145,   211,
       4,   138,   138,     6,   100,   100,   100,   100,     4,     4,
     100,     4,     5,   145,   214,   215,   145,   214,     4,   140,
     142,   147,   171,   145,   215,   138,   140,   138,   140,   138,
     140,   138,   140,   138,   140,   138,   140,   138,   140,   138,
     140,   138,   140,   138,   140,   138,   140,   138,   140,   138,
     140,   138,   140,   138,   140,   138,   140,   138,   140,   138,
     140,   138,   140,   138,   140,   138,   140,   138,   138,   138,
     138,   138,     4,   203,   203,   203,   203,   141,   145,   203,
       4,    92,    93,     4,   203,     6,     6,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   137,     6,     6,   203,     5,   203,   203,     4,    43,
     129,   175,   183,   203,   209,   210,   203,   203,   138,   203,
     210,   203,   203,   138,   210,   203,   203,   100,   129,   145,
     203,   208,   209,   138,   203,   145,   138,   138,   208,   145,
     145,   138,   138,   138,   138,   138,     4,   205,   205,   205,
     203,   203,   128,   129,   145,   145,   205,   140,   145,   145,
     145,   128,   129,   138,   177,   205,   145,   175,   176,   177,
     208,     4,     6,   140,   177,   145,   176,   100,   208,   208,
     140,   140,     6,   203,   203,   203,   142,   203,   145,    95,
     203,   203,   138,   138,   138,   138,     6,   138,   177,     6,
     177,     6,   140,   203,     4,   145,   155,     6,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
       4,   214,   214,   214,   214,     5,   140,   139,     7,   118,
     210,   141,     7,   170,   171,   142,     7,   140,     6,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,     6,   139,   144,   144,   139,   140,
     145,   203,   209,     8,   130,   144,   146,   139,   139,   203,
     139,   146,   139,   139,   203,   146,   139,   139,   208,   145,
     146,   210,   130,     7,   203,   139,   203,   203,   203,     7,
     203,   203,   203,   173,   203,   215,   173,   173,   173,   139,
     144,   144,   144,   205,   205,   176,   176,   144,   203,   203,
     203,   203,   203,    43,    46,    49,    51,   108,   174,   187,
     144,   177,   146,     6,     7,     6,   203,   146,   210,   146,
     138,     7,     7,   203,   203,   139,   139,   139,    92,   144,
     177,   145,     8,   139,   203,   203,   203,   203,   203,   146,
     146,   203,   141,   171,   203,     4,    82,    83,    84,    85,
     146,   158,   162,   165,   167,   168,   139,   141,   139,   141,
     139,   141,   139,   141,   139,   141,   139,   141,   139,   141,
     139,   141,   139,   141,   139,   141,   139,   141,   144,   144,
     139,   141,   139,   141,   139,   141,   139,   141,   139,   141,
     139,   141,   144,   144,   144,   144,   144,   144,   140,   142,
     139,   144,   144,   139,   139,   144,   203,   208,   208,   146,
       7,   142,   170,   171,   215,   203,     6,     4,     4,   145,
     212,   141,     8,     6,   125,   152,   210,   203,     7,   141,
     145,   203,   203,   203,   209,   203,   209,    95,     7,     7,
     139,     7,    95,     7,     7,   139,    95,     7,     7,     6,
     210,   146,   145,   203,   139,     7,   146,   139,   139,   203,
     146,   146,   139,   139,   139,   139,   139,   142,   205,   203,
     203,   146,   146,   203,   141,   144,   144,   144,   145,   145,
     145,   145,    72,    78,    79,   198,   199,   205,   146,   184,
     203,   141,   146,   203,   208,   208,   141,   141,     7,     7,
       7,   142,   203,   146,   203,   203,   139,   139,   139,   139,
     139,   141,   142,   171,   214,   146,   159,   138,   138,   145,
     169,     6,   203,   203,   203,   203,   203,   203,   203,   203,
     203,     4,   210,   214,   203,   141,     6,     6,   141,     4,
      92,    93,   203,     6,     6,     6,     7,   140,   211,   213,
       6,   203,   125,   214,   139,   144,   205,   210,   146,     8,
      49,   208,   208,     7,   208,    49,    51,   208,   208,     7,
      51,   208,   208,   146,   210,     6,     7,   145,     7,     7,
       7,     6,    61,     7,     7,     7,     7,     7,     7,     7,
       4,   144,   144,   144,   146,   145,   205,   205,   205,   210,
     210,   210,   210,     6,   145,   138,   146,   199,   144,   198,
       6,     6,    49,   139,     6,     6,     6,     6,   208,   208,
     208,     4,   144,     8,     8,   139,     7,     7,     7,     7,
       7,     6,     4,     6,   138,   203,   203,   207,   208,   145,
     139,   141,   139,   141,   139,   141,   139,   141,   141,   139,
     139,   139,   139,   170,     7,   170,   171,   142,     7,     6,
     211,   203,   144,   146,     6,     6,   152,   203,     6,   146,
     203,   145,     6,    56,     6,    56,   208,     6,   145,   145,
       6,     6,   208,   145,     6,     6,   146,     5,   203,   208,
     208,   208,    62,    63,   208,   208,   208,   208,   208,   208,
     208,     6,     7,   203,   203,   203,   145,   177,   144,   146,
     144,   146,   144,   146,   146,   146,   146,   146,   203,   208,
     203,   203,   205,   146,   145,     7,     6,     6,    91,   203,
     203,   203,   208,     5,   203,   203,     5,   171,   156,   203,
     144,   144,   144,   146,   157,   203,   142,   208,   215,   203,
       6,     4,   212,     6,   141,   211,   214,   144,   141,   203,
     205,   205,     6,   203,   203,     6,   203,     5,   144,     6,
       6,     6,   203,   203,     4,     6,     6,     6,     6,     6,
       6,     6,   203,   215,   146,   139,   144,   146,   176,   188,
     205,     6,   189,   205,     6,   190,   205,     6,   191,     6,
       6,     6,     6,   146,   144,   139,   146,   144,   203,   208,
     208,   144,   146,     8,   146,   139,     6,     6,     6,     6,
       6,   208,   139,   144,   203,   203,   208,   145,   144,   146,
       4,     6,     6,     6,     7,     6,   142,     6,   203,   146,
       6,     6,   146,   146,   146,     5,   203,     6,     6,     6,
       6,     6,   145,   203,   146,   198,   144,   145,   144,   145,
     144,   145,     6,   208,     7,   145,   203,   146,     6,    90,
     203,   203,     6,   160,   203,   144,   144,   207,   203,     6,
     139,   211,    93,   144,     6,     6,     6,     6,     6,   144,
     176,   144,   146,   146,   203,   205,   198,   203,   205,   198,
     203,   205,   198,   144,   146,   208,   177,   146,   203,   146,
     146,   145,   203,   203,   146,     6,   203,     5,   146,   203,
     146,   144,   146,   146,   144,   146,   146,   144,   146,   208,
       6,    61,   146,   185,   145,     6,   157,   139,   144,     6,
     145,   144,   144,   146,     6,   192,   203,     6,     6,   193,
     203,     6,     6,   194,   203,     6,   146,   203,   198,   177,
     146,   163,   203,   207,   203,     5,   145,   146,   145,   146,
     145,   146,     6,     6,   146,   146,   186,     6,   145,   139,
     146,   146,   144,   198,     6,   195,   198,     6,   196,   198,
       6,   197,   198,   161,   214,   166,   145,     6,     5,   146,
     145,   146,   145,   146,   145,   146,   144,   146,   145,   207,
     146,     6,   198,     6,   198,     6,   198,   214,     6,   164,
     214,   146,     6,   146,   146,   146,   144,   146,     6,     6,
       6,     6,   214,     6
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
#line 144 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 155 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 156 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 157 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 158 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 159 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 160 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 161 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 162 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 163 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 164 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 165 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 166 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 167 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 168 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 173 "Gmsh.y"
    {
      (yyval.c) = "w";
    ;}
    break;

  case 21:
#line 177 "Gmsh.y"
    {
      (yyval.c) = "a";
    ;}
    break;

  case 22:
#line 184 "Gmsh.y"
    {
      Msg(DIRECT, (yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 23:
#line 189 "Gmsh.y"
    {
      char tmpstring[1024];
      FixRelativePath((yyvsp[(6) - (7)].c), tmpstring);
      FILE *fp = fopen(tmpstring, (yyvsp[(5) - (7)].c));
      if(!fp){
	yymsg(GERROR, "Unable to open file '%s'", tmpstring);
      }
      else{
	fprintf(fp, "%s\n", (yyvsp[(3) - (7)].c));
	fclose(fp);
      }
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 24:
#line 204 "Gmsh.y"
    {
      char tmpstring[1024];
      int i = PrintListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0) 
	yymsg(GERROR, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(GERROR, "%d extra argument%s in Printf", i, (i>1)?"s":"");
      else
	Msg(DIRECT, tmpstring);
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 25:
#line 217 "Gmsh.y"
    {
      char tmpstring[1024];
      int i = PrintListOfDouble((yyvsp[(3) - (9)].c), (yyvsp[(5) - (9)].l), tmpstring);
      if(i < 0) 
	yymsg(GERROR, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(GERROR, "%d extra argument%s in Printf", i, (i>1)?"s":"");
      else{
	char tmpstring2[1024];
	FixRelativePath((yyvsp[(8) - (9)].c), tmpstring2);
	FILE *fp = fopen(tmpstring2, (yyvsp[(7) - (9)].c));
	if(!fp){
	  yymsg(GERROR, "Unable to open file '%s'", tmpstring2);
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

  case 26:
#line 246 "Gmsh.y"
    { 
      if(!strcmp((yyvsp[(1) - (6)].c), "View") && ViewData->finalize()){
	ViewData->setName((yyvsp[(2) - (6)].c));
	ViewData->setFileName(yyname);
	ViewData->setFileIndex(yyviewindex++);
	if(ViewData->adaptive){
	  ViewData->adaptive->setGlobalResolutionLevel
	    (ViewData, PViewOptions::reference.MaxRecursionLevel);
	  ViewData->adaptive->setTolerance(PViewOptions::reference.TargetError);
	}
	new PView(ViewData);
      }
      else
	delete ViewData;
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 27:
#line 263 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < PView::list.size())
	  new PView(PView::list[index], false);
      }
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 28:
#line 272 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < PView::list.size())
	  new PView(PView::list[index], true);
      }
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 29:
#line 284 "Gmsh.y"
    {
      ViewData = new PViewDataList(true); 
    ;}
    break;

  case 35:
#line 296 "Gmsh.y"
    { ViewCoord[ViewCoordIdx++] = (yyvsp[(1) - (1)].d); ;}
    break;

  case 36:
#line 298 "Gmsh.y"
    { ViewCoord[ViewCoordIdx++] = (yyvsp[(3) - (3)].d); ;}
    break;

  case 37:
#line 303 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(1) - (1)].d)); ;}
    break;

  case 38:
#line 305 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(3) - (3)].d)); ;}
    break;

  case 39:
#line 310 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "SP")){
	ViewValueList = ViewData->SP; ViewNumList = &ViewData->NbSP;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VP")){
	ViewValueList = ViewData->VP; ViewNumList = &ViewData->NbVP;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TP")){
	ViewValueList = ViewData->TP; ViewNumList = &ViewData->NbTP;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SL")){
	ViewValueList = ViewData->SL; ViewNumList = &ViewData->NbSL;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VL")){
	ViewValueList = ViewData->VL; ViewNumList = &ViewData->NbVL;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TL")){
	ViewValueList = ViewData->TL; ViewNumList = &ViewData->NbTL;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "ST")){
	ViewValueList = ViewData->ST; ViewNumList = &ViewData->NbST;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VT")){
	ViewValueList = ViewData->VT; ViewNumList = &ViewData->NbVT;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TT")){
	ViewValueList = ViewData->TT; ViewNumList = &ViewData->NbTT;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SQ")){
	ViewValueList = ViewData->SQ; ViewNumList = &ViewData->NbSQ;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VQ")){
	ViewValueList = ViewData->VQ; ViewNumList = &ViewData->NbVQ;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TQ")){
	ViewValueList = ViewData->TQ; ViewNumList = &ViewData->NbTQ;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SS")){
	ViewValueList = ViewData->SS; ViewNumList = &ViewData->NbSS;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VS")){
	ViewValueList = ViewData->VS; ViewNumList = &ViewData->NbVS;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TS")){
	ViewValueList = ViewData->TS; ViewNumList = &ViewData->NbTS;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SH")){
	ViewValueList = ViewData->SH; ViewNumList = &ViewData->NbSH;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VH")){
	ViewValueList = ViewData->VH; ViewNumList = &ViewData->NbVH;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TH")){
	ViewValueList = ViewData->TH; ViewNumList = &ViewData->NbTH;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SI")){
	ViewValueList = ViewData->SI; ViewNumList = &ViewData->NbSI;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VI")){
	ViewValueList = ViewData->VI; ViewNumList = &ViewData->NbVI;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TI")){
	ViewValueList = ViewData->TI; ViewNumList = &ViewData->NbTI;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SY")){
	ViewValueList = ViewData->SY; ViewNumList = &ViewData->NbSY;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VY")){
	ViewValueList = ViewData->VY; ViewNumList = &ViewData->NbVY;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TY")){
	ViewValueList = ViewData->TY; ViewNumList = &ViewData->NbTY;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SL2")){
	ViewValueList = ViewData->SL2; ViewNumList = &ViewData->NbSL2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VL2")){
	ViewValueList = ViewData->VL2; ViewNumList = &ViewData->NbVL2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TL2")){
	ViewValueList = ViewData->TL2; ViewNumList = &ViewData->NbTL2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "ST2")){
	ViewValueList = ViewData->ST2; ViewNumList = &ViewData->NbST2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VT2")){
	ViewValueList = ViewData->VT2; ViewNumList = &ViewData->NbVT2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TT2")){
	ViewValueList = ViewData->TT2; ViewNumList = &ViewData->NbTT2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SQ2")){
	ViewValueList = ViewData->SQ2; ViewNumList = &ViewData->NbSQ2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VQ2")){
	ViewValueList = ViewData->VQ2; ViewNumList = &ViewData->NbVQ2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TQ2")){
	ViewValueList = ViewData->TQ2; ViewNumList = &ViewData->NbTQ2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SS2")){
	ViewValueList = ViewData->SS2; ViewNumList = &ViewData->NbSS2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VS2")){
	ViewValueList = ViewData->VS2; ViewNumList = &ViewData->NbVS2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TS2")){
	ViewValueList = ViewData->TS2; ViewNumList = &ViewData->NbTS2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SH2")){
	ViewValueList = ViewData->SH2; ViewNumList = &ViewData->NbSH2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VH2")){
	ViewValueList = ViewData->VH2; ViewNumList = &ViewData->NbVH2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TH2")){
	ViewValueList = ViewData->TH2; ViewNumList = &ViewData->NbTH2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SI2")){
	ViewValueList = ViewData->SI2; ViewNumList = &ViewData->NbSI2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VI2")){
	ViewValueList = ViewData->VI2; ViewNumList = &ViewData->NbVI2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TI2")){
	ViewValueList = ViewData->TI2; ViewNumList = &ViewData->NbTI2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SY2")){
	ViewValueList = ViewData->SY2; ViewNumList = &ViewData->NbSY2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VY2")){
	ViewValueList = ViewData->VY2; ViewNumList = &ViewData->NbVY2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TY2")){
	ViewValueList = ViewData->TY2; ViewNumList = &ViewData->NbTY2;
      }
      else{
	yymsg(GERROR, "Unknown element type '%s'", (yyvsp[(1) - (1)].c));	
	ViewValueList = 0; ViewNumList = 0;
      }
      Free((yyvsp[(1) - (1)].c));
      ViewCoordIdx = 0;
    ;}
    break;

  case 40:
#line 454 "Gmsh.y"
    {
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(int j = 0; j < ViewCoordIdx / 3; j++)
	    List_Add(ViewValueList, &ViewCoord[3 * j + i]);
      }
    ;}
    break;

  case 41:
#line 462 "Gmsh.y"
    {
      if(ViewValueList) (*ViewNumList)++;
    ;}
    break;

  case 42:
#line 469 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(ViewData->T2C, &(yyvsp[(1) - (1)].c)[i]); 
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 43:
#line 474 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(ViewData->T2C, &(yyvsp[(3) - (3)].c)[i]); 
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 44:
#line 482 "Gmsh.y"
    { 
      List_Add(ViewData->T2D, &(yyvsp[(3) - (8)].d)); 
      List_Add(ViewData->T2D, &(yyvsp[(5) - (8)].d));
      List_Add(ViewData->T2D, &(yyvsp[(7) - (8)].d)); 
      double d = List_Nbr(ViewData->T2C);
      List_Add(ViewData->T2D, &d); 
    ;}
    break;

  case 45:
#line 490 "Gmsh.y"
    {
      ViewData->NbT2++;
    ;}
    break;

  case 46:
#line 497 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(ViewData->T3C, &(yyvsp[(1) - (1)].c)[i]); 
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 47:
#line 502 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(ViewData->T3C, &(yyvsp[(3) - (3)].c)[i]); 
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 48:
#line 510 "Gmsh.y"
    { 
      List_Add(ViewData->T3D, &(yyvsp[(3) - (10)].d)); List_Add(ViewData->T3D, &(yyvsp[(5) - (10)].d));
      List_Add(ViewData->T3D, &(yyvsp[(7) - (10)].d)); List_Add(ViewData->T3D, &(yyvsp[(9) - (10)].d)); 
      double d = List_Nbr(ViewData->T3C);
      List_Add(ViewData->T3D, &d); 
    ;}
    break;

  case 49:
#line 517 "Gmsh.y"
    {
      ViewData->NbT3++;
    ;}
    break;

  case 50:
#line 525 "Gmsh.y"
    {
      ViewData->adaptive = new Adaptive_Post_View(ViewData, (yyvsp[(3) - (8)].l), (yyvsp[(6) - (8)].l));
    ;}
    break;

  case 51:
#line 532 "Gmsh.y"
    {
      ViewData->adaptive = new Adaptive_Post_View(ViewData, (yyvsp[(3) - (14)].l), (yyvsp[(6) - (14)].l), (yyvsp[(9) - (14)].l), (yyvsp[(12) - (14)].l));
    ;}
    break;

  case 52:
#line 539 "Gmsh.y"
    {
      ViewValueList = ViewData->Time;
    ;}
    break;

  case 53:
#line 543 "Gmsh.y"
    {
    ;}
    break;

  case 54:
#line 550 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 55:
#line 551 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 56:
#line 552 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 57:
#line 553 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 58:
#line 554 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 59:
#line 558 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 60:
#line 559 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 61:
#line 567 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(1) - (4)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	if(!(yyvsp[(2) - (4)].i)){
	  TheSymbol.val = List_Create(1, 1, sizeof(double));
	  List_Put(TheSymbol.val, 0, &(yyvsp[(3) - (4)].d));
	  Tree_Add(Symbol_T, &TheSymbol);
	}
	else{
	  yymsg(GERROR, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
	  Free((yyvsp[(1) - (4)].c));
	}
      }
      else{
	double *pd = (double*)List_Pointer_Fast(pSymbol->val, 0); 
	switch((yyvsp[(2) - (4)].i)){
	case 0 : *pd = (yyvsp[(3) - (4)].d); break;
	case 1 : *pd += (yyvsp[(3) - (4)].d); break;
	case 2 : *pd -= (yyvsp[(3) - (4)].d); break;
	case 3 : *pd *= (yyvsp[(3) - (4)].d); break;
	case 4 : 
	  if((yyvsp[(3) - (4)].d)) *pd /= (yyvsp[(3) - (4)].d); 
	  else yymsg(GERROR, "Division by zero in '%s /= %g'", (yyvsp[(1) - (4)].c), (yyvsp[(3) - (4)].d));
	  break;
	}
	Free((yyvsp[(1) - (4)].c));
      }
    ;}
    break;

  case 62:
#line 598 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(1) - (7)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	if(!(yyvsp[(5) - (7)].i)){
	  TheSymbol.val = List_Create(5, 5, sizeof(double));
	  List_Put(TheSymbol.val, (int)(yyvsp[(3) - (7)].d), &(yyvsp[(6) - (7)].d));
	  Tree_Add(Symbol_T, &TheSymbol);
	}
	else{
	  yymsg(GERROR, "Unknown variable '%s'", (yyvsp[(1) - (7)].c));
	  Free((yyvsp[(1) - (7)].c));
	}
      }
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)(yyvsp[(3) - (7)].d)))){
	  switch((yyvsp[(5) - (7)].i)){
	  case 0 : *pd = (yyvsp[(6) - (7)].d); break;
	  case 1 : *pd += (yyvsp[(6) - (7)].d); break;
	  case 2 : *pd -= (yyvsp[(6) - (7)].d); break;
	  case 3 : *pd *= (yyvsp[(6) - (7)].d); break;
	  case 4 : 
	    if((yyvsp[(6) - (7)].d)) *pd /= (yyvsp[(6) - (7)].d); 
	    else yymsg(GERROR, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].d));
	    break;
	  }
	}
	else{
	  if(!(yyvsp[(5) - (7)].i))
	    List_Put(pSymbol->val, (int)(yyvsp[(3) - (7)].d), &(yyvsp[(6) - (7)].d));
	  else
	    yymsg(GERROR, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d));
	}
	Free((yyvsp[(1) - (7)].c));
      }
    ;}
    break;

  case 63:
#line 637 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (9)].l)) != List_Nbr((yyvsp[(8) - (9)].l))){
	yymsg(GERROR, "Incompatible array dimensions in affectation");
	Free((yyvsp[(1) - (9)].c));
      }
      else{
	Symbol TheSymbol;
	TheSymbol.Name = (yyvsp[(1) - (9)].c);
	Symbol *pSymbol;
	if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	  if(!(yyvsp[(7) - (9)].i)){
	    TheSymbol.val = List_Create(5, 5, sizeof(double));
	    for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
	      List_Put(TheSymbol.val, (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i)),
		       (double*)List_Pointer((yyvsp[(8) - (9)].l), i));
	    }
	    Tree_Add(Symbol_T, &TheSymbol);
	  }
	  else{
	    yymsg(GERROR, "Unknown variable '%s'", (yyvsp[(1) - (9)].c));
	    Free((yyvsp[(1) - (9)].c));
	  }
	}
	else{
	  for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
	    int j = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
	    double d = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
	    double *pd;
	    if((pd = (double*)List_Pointer_Test(pSymbol->val, j))){
	      switch((yyvsp[(7) - (9)].i)){
	      case 0 : *pd = d; break;
	      case 1 : *pd += d; break;
	      case 2 : *pd -= d; break;
	      case 3 : *pd *= d; break;
	      case 4 : 
		if((yyvsp[(8) - (9)].l)) *pd /= d; 
		else yymsg(GERROR, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (9)].c), j, d);
		break;
	      }
	    }
	    else{
	      if(!(yyvsp[(7) - (9)].i))
		List_Put(pSymbol->val, j, &d);
	      else
		yymsg(GERROR, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (9)].c), j);	  
	    }
	  }
	  Free((yyvsp[(1) - (9)].c));
	}
      }
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 64:
#line 691 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(1) - (6)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(5, 5, sizeof(double));
	List_Copy((yyvsp[(5) - (6)].l), TheSymbol.val);
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	List_Reset(pSymbol->val);
	List_Copy((yyvsp[(5) - (6)].l), pSymbol->val);
	Free((yyvsp[(1) - (6)].c));
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 65:
#line 708 "Gmsh.y"
    {
      // appends to the list
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(1) - (6)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(5, 5, sizeof(double));
	List_Copy((yyvsp[(5) - (6)].l), TheSymbol.val);
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
	  List_Add(pSymbol->val, List_Pointer((yyvsp[(5) - (6)].l), i));
	Free((yyvsp[(1) - (6)].c));
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 66:
#line 726 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(1) - (3)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol)))
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[(1) - (3)].c)); 
      else
	*(double*)List_Pointer_Fast(pSymbol->val, 0) += (yyvsp[(2) - (3)].i);
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 67:
#line 737 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(1) - (6)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol)))
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[(1) - (6)].c)); 
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)(yyvsp[(3) - (6)].d))))
	  *pd += (yyvsp[(5) - (6)].i);
	else
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d));
      }
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 68:
#line 754 "Gmsh.y"
    { 
      Msg(WARNING, "Named string expressions not implemented yet");
    ;}
    break;

  case 69:
#line 761 "Gmsh.y"
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory((yyvsp[(1) - (6)].c))))
	yymsg(GERROR, "Unknown string option class '%s'", (yyvsp[(1) - (6)].c));
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption((yyvsp[(3) - (6)].c), pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s.%s'", (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c));
	else
	  pStrOpt(0, GMSH_SET|GMSH_GUI, (yyvsp[(5) - (6)].c));
      }
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); //FIXME: somtimes leak $5
    ;}
    break;

  case 70:
#line 775 "Gmsh.y"
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory((yyvsp[(1) - (9)].c))))
	yymsg(GERROR, "Unknown string option class '%s'", (yyvsp[(1) - (9)].c));
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption((yyvsp[(6) - (9)].c), pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s[%d].%s'", (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c));
	else
	  pStrOpt((int)(yyvsp[(3) - (9)].d), GMSH_SET|GMSH_GUI, (yyvsp[(8) - (9)].c));
      }
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); //FIXME: somtimes leak $8
    ;}
    break;

  case 71:
#line 792 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[(1) - (6)].c))))
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[(1) - (6)].c));
      else{
	if(!(pNumOpt = (double (*) (int, int, double))Get_NumberOption((yyvsp[(3) - (6)].c), pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c));
	else{
	  double d = 0;
	  switch((yyvsp[(4) - (6)].i)){
	  case 0 : d = (yyvsp[(5) - (6)].d); break;
	  case 1 : d = pNumOpt(0, GMSH_GET, 0) + (yyvsp[(5) - (6)].d); break;
	  case 2 : d = pNumOpt(0, GMSH_GET, 0) - (yyvsp[(5) - (6)].d); break;
	  case 3 : d = pNumOpt(0, GMSH_GET, 0) * (yyvsp[(5) - (6)].d); break;
	  case 4 : 
	    if((yyvsp[(5) - (6)].d)) d = pNumOpt(0, GMSH_GET, 0) / (yyvsp[(5) - (6)].d); 
	    else yymsg(GERROR, "Division by zero in '%s.%s /= %g'", (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
	    break;
	  }
	  pNumOpt(0, GMSH_SET|GMSH_GUI, d);
	}
      }
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 72:
#line 818 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[(1) - (9)].c))))
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[(1) - (9)].c));
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption((yyvsp[(6) - (9)].c), pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c));
	else{
	  double d = 0;
	  switch((yyvsp[(7) - (9)].i)){
	  case 0 : d = (yyvsp[(8) - (9)].d); break;
	  case 1 : d = pNumOpt((int)(yyvsp[(3) - (9)].d), GMSH_GET, 0) + (yyvsp[(8) - (9)].d); break;
	  case 2 : d = pNumOpt((int)(yyvsp[(3) - (9)].d), GMSH_GET, 0) - (yyvsp[(8) - (9)].d); break;
	  case 3 : d = pNumOpt((int)(yyvsp[(3) - (9)].d), GMSH_GET, 0) * (yyvsp[(8) - (9)].d); break;
	  case 4 : 
	    if((yyvsp[(8) - (9)].d)) d = pNumOpt((int)(yyvsp[(3) - (9)].d), GMSH_GET, 0) / (yyvsp[(8) - (9)].d);
	    else yymsg(GERROR, "Division by zero in '%s[%d].%s /= %g'", 
		       (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].d));
	    break;
	  }
	  pNumOpt((int)(yyvsp[(3) - (9)].d), GMSH_SET|GMSH_GUI, d);
	}
      }
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 73:
#line 845 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[(1) - (5)].c))))
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[(1) - (5)].c));
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption((yyvsp[(3) - (5)].c), pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
	else
	  pNumOpt(0, GMSH_SET|GMSH_GUI, pNumOpt(0, GMSH_GET, 0)+(yyvsp[(4) - (5)].i));
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 74:
#line 859 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[(1) - (8)].c))))
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[(1) - (8)].c));
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption((yyvsp[(6) - (8)].c), pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c));
	else
	  pNumOpt((int)(yyvsp[(3) - (8)].d), GMSH_SET|GMSH_GUI, pNumOpt((int)(yyvsp[(3) - (8)].d), GMSH_GET, 0)+(yyvsp[(7) - (8)].i));
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 75:
#line 876 "Gmsh.y"
    {
      unsigned int (*pColOpt)(int num, int action, unsigned int value);
      StringXColor *pColCat;
      if(!(pColCat = Get_ColorOptionCategory((yyvsp[(1) - (8)].c))))
	yymsg(GERROR, "Unknown color option class '%s'", (yyvsp[(1) - (8)].c));
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption((yyvsp[(5) - (8)].c), pColCat)))
	  yymsg(GERROR, "Unknown color option '%s.Color.%s'", (yyvsp[(1) - (8)].c), (yyvsp[(5) - (8)].c));
	else
	  pColOpt(0, GMSH_SET|GMSH_GUI, (yyvsp[(7) - (8)].u));
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 76:
#line 890 "Gmsh.y"
    {
      unsigned int (*pColOpt)(int num, int action, unsigned int value);
      StringXColor *pColCat;
      if(!(pColCat = Get_ColorOptionCategory((yyvsp[(1) - (11)].c))))
	yymsg(GERROR, "Unknown color option class '%s'", (yyvsp[(1) - (11)].c));
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption((yyvsp[(8) - (11)].c), pColCat)))
	  yymsg(GERROR, "Unknown color option '%s[%d].Color.%s'", (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c));
	else
	  pColOpt((int)(yyvsp[(3) - (11)].d), GMSH_SET|GMSH_GUI, (yyvsp[(10) - (11)].u));
      }
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 77:
#line 907 "Gmsh.y"
    {
      GmshColorTable *ct = Get_ColorTable(0);
      if(!ct)
	yymsg(GERROR, "View[%d] does not exist", 0);
      else{
	ct->size = List_Nbr((yyvsp[(5) - (6)].l));
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(GERROR, "Too many (%d>%d) colors in View[%d].ColorTable", 
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

  case 78:
#line 927 "Gmsh.y"
    {
      GmshColorTable *ct = Get_ColorTable((int)(yyvsp[(3) - (9)].d));
      if(!ct)
	yymsg(GERROR, "View[%d] does not exist", (int)(yyvsp[(3) - (9)].d));
      else{
	ct->size = List_Nbr((yyvsp[(8) - (9)].l));
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(GERROR, "Too many (%d>%d) colors in View[%d].ColorTable", 
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

  case 79:
#line 950 "Gmsh.y"
    {
      try {
	GMSH_PluginManager::instance()->setPluginOption((yyvsp[(3) - (9)].c), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].d)); 
      }
      catch (...) {
	yymsg(GERROR, "Unknown option '%s' or plugin '%s'", (yyvsp[(6) - (9)].c), (yyvsp[(3) - (9)].c));
      }
      Free((yyvsp[(3) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 80:
#line 960 "Gmsh.y"
    {
      try {
	GMSH_PluginManager::instance()->setPluginOption((yyvsp[(3) - (9)].c), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].c)); 
      }
      catch (...) {
	yymsg(GERROR, "Unknown option '%s' or plugin '%s'", (yyvsp[(6) - (9)].c), (yyvsp[(3) - (9)].c));
      }
      Free((yyvsp[(3) - (9)].c)); Free((yyvsp[(6) - (9)].c)); // FIXME: sometimes leak $8
    ;}
    break;

  case 81:
#line 975 "Gmsh.y"
    { 
      (yyval.i) = (int)(yyvsp[(1) - (1)].d); 
    ;}
    break;

  case 82:
#line 979 "Gmsh.y"
    { 
      (yyval.i) = GModel::current()->setPhysicalName
	(std::string((yyvsp[(1) - (1)].c)), ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 83:
#line 992 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindPoint(num)){
	yymsg(GERROR, "Point %d already exists", num);
      }
      else{
	double x = CTX.geom.scaling_factor * (yyvsp[(6) - (7)].v)[0];
	double y = CTX.geom.scaling_factor * (yyvsp[(6) - (7)].v)[1];
	double z = CTX.geom.scaling_factor * (yyvsp[(6) - (7)].v)[2];
	double lc = CTX.geom.scaling_factor * (yyvsp[(6) - (7)].v)[3];
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

  case 84:
#line 1014 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT)){
	yymsg(GERROR, "Physical point %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 85:
#line 1030 "Gmsh.y"
    {
      AttractorField *att = new AttractorField();
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (9)].l)); i++){
        double d;
        List_Read((yyvsp[(8) - (9)].l), i, &d);
        Vertex *v = FindPoint((int)d); 
        if(v)
          att->addPoint(v->Pos.X, v->Pos.Y, v->Pos.Z);
        else{
          GVertex *gv = GModel::current()->vertexByTag((int)d);
          if(gv) 
            att->addPoint(gv->x(), gv->y(), gv->z());
        }
      }
      att->buildFastSearchStructures();
      fields.insert(att, (int)(yyvsp[(5) - (9)].d));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 86:
#line 1051 "Gmsh.y"
    {
      fields.insert(new LatLonField(fields.get((int)(yyvsp[(7) - (8)].d))), (int)(yyvsp[(4) - (8)].d));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 87:
#line 1058 "Gmsh.y"
    {
      int index = (int)(yyvsp[(7) - (8)].d);
      if(index >= 0 && index < PView::list.size()) 
        fields.insert(new PostViewField(PView::list[index]), (int)(yyvsp[(4) - (8)].d));
      else
        yymsg(GERROR, "Field %i error, view %i does not exist", (int)(yyvsp[(4) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 88:
#line 1069 "Gmsh.y"
    {
      double pars[] = {0, CTX.lc/10, CTX.lc, CTX.lc/100, CTX.lc/20};
      for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
	if(i > 4)
	  yymsg(GERROR, "Too many parameters for Thresold Field (max=5)");
	else
	  List_Read((yyvsp[(7) - (8)].l), i, &pars[i]);
      }
      fields.insert(new ThresholdField(fields.get((int)pars[0]), pars[1], 
				       pars[2], pars[3], pars[4]), (int)(yyvsp[(4) - (8)].d));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 89:
#line 1084 "Gmsh.y"
    {
      std::list<Field*> *flist = new std::list<Field*>;
      fields.insert(new FunctionField(flist,(yyvsp[(7) - (8)].c)), (int)(yyvsp[(4) - (8)].d));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 90:
#line 1092 "Gmsh.y"
    {
      std::list<Field*> *flist = new std::list<Field*>;
      flist->resize(0);
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (9)].l)); i++){
	double id;
	List_Read((yyvsp[(8) - (9)].l), i, &id);
	Field *pfield = fields.get((int)id);
	if(pfield) flist->push_front(pfield);
      }
      fields.insert(new FunctionField(flist,(yyvsp[(7) - (9)].c)), (int)(yyvsp[(4) - (9)].d));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 91:
#line 1107 "Gmsh.y"
    {
      fields.insert(new StructuredField((yyvsp[(7) - (8)].c)), (int)(yyvsp[(4) - (8)].d));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 92:
#line 1114 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	double id;
	List_Read((yyvsp[(4) - (5)].l), i, &id);
        BGMAddField(fields.get((int)id));
      }
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 93:
#line 1126 "Gmsh.y"
    {
      double pars[] = { CTX.lc/10, CTX.lc/100., CTX.lc/20, 1, 3 };
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	if(i > 4) 
	  yymsg(GERROR, "Too many paramaters for attractor line (max = 5)");	  
	else
	  List_Read((yyvsp[(5) - (6)].l), i, &pars[i]);
      }
      // treshold attractor: first parameter is the treshold, next two
      // are the in and out size fields, last is transition factor
      AttractorField *attractor = new AttractorField();
      fields.insert(attractor);
      Field *threshold = new ThresholdField(attractor, pars[0], pars[0] * pars[4], 
					    pars[1], pars[2]);
      fields.insert(threshold);
      BGMAddField(threshold);
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	Vertex *v = FindPoint((int)d); 
	if(v)
	  attractor->addPoint(v->Pos.X, v->Pos.Y, v->Pos.Z);
	else{
	  GVertex *gv = GModel::current()->vertexByTag((int)d);
	  if(gv) 
	    attractor->addPoint(gv->x(), gv->y(), gv->z());
	}
      }
      attractor->buildFastSearchStructures();
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 94:
#line 1160 "Gmsh.y"
    {
      double pars[] = { CTX.lc/10, CTX.lc/100., CTX.lc/20, 10, 3 };
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	if(i > 4) 
	  yymsg(GERROR, "Too many paramaters for attractor line (max = 5)");	  
	else
	  List_Read((yyvsp[(5) - (6)].l), i, &pars[i]);
      }
      // treshold attractor: first parameter is the treshold, next two
      // are the in and out size fields, last is transition factor
      AttractorField *att = new AttractorField();
      fields.insert(att);
      Field *threshold = new ThresholdField(att, pars[0], pars[0] * pars[4],
					    pars[1], pars[2]);
      fields.insert(threshold);
      BGMAddField(threshold);
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	Curve *c = FindCurve((int)d); 
	if(c){
	  att->addCurve(c, (int)pars[3]);
	}
	else{
	  GEdge *ge = GModel::current()->edgeByTag((int)d);
	  if(ge){
	    att->addGEdge(ge, (int)pars[3]);
	  }
	}
      }
      att->buildFastSearchStructures();
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 95:
#line 1196 "Gmsh.y"
    {      
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	Vertex *v = FindPoint((int)d); 	 
	if(v)
	  v->lc = (yyvsp[(5) - (6)].d);
	else{
	  GVertex *gv = GModel::current()->vertexByTag((int)d);
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

  case 96:
#line 1218 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
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

  case 97:
#line 1236 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
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

  case 98:
#line 1254 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    ;}
    break;

  case 99:
#line 1272 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (9)].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (9)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
	c->Circle.n[0] = (yyvsp[(8) - (9)].v)[0];
	c->Circle.n[1] = (yyvsp[(8) - (9)].v)[1];
	c->Circle.n[2] = (yyvsp[(8) - (9)].v)[2];
	End_Curve(c);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	Curve *rc = CreateReversedCurve(c);
	rc->Circle.n[0] = (yyvsp[(8) - (9)].v)[0];
	rc->Circle.n[1] = (yyvsp[(8) - (9)].v)[1];
	rc->Circle.n[2] = (yyvsp[(8) - (9)].v)[2];
	End_Curve(rc);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (9)].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    ;}
    break;

  case 100:
#line 1298 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    ;}
    break;

  case 101:
#line 1316 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (9)].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (9)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
	c->Circle.n[0] = (yyvsp[(8) - (9)].v)[0];
	c->Circle.n[1] = (yyvsp[(8) - (9)].v)[1];
	c->Circle.n[2] = (yyvsp[(8) - (9)].v)[2];
	End_Curve(c);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	Curve *rc = CreateReversedCurve(c);
	rc->Circle.n[0] = (yyvsp[(8) - (9)].v)[0];
	rc->Circle.n[1] = (yyvsp[(8) - (9)].v)[1];
	rc->Circle.n[2] = (yyvsp[(8) - (9)].v)[2];
	End_Curve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (9)].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    ;}
    break;

  case 102:
#line 1343 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (17)].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	Curve *c = Create_Curve(num, MSH_SEGM_PARAMETRIC, 2, NULL, NULL,
				-1, -1, (yyvsp[(7) - (17)].d), (yyvsp[(9) - (17)].d));
	strcpy(c->functu, (yyvsp[(11) - (17)].c));
	strcpy(c->functv, (yyvsp[(13) - (17)].c));
	strcpy(c->functw, (yyvsp[(15) - (17)].c));
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
      }
      Free((yyvsp[(11) - (17)].c)); Free((yyvsp[(13) - (17)].c)); Free((yyvsp[(15) - (17)].c));
      (yyval.s).Type = MSH_SEGM_PARAMETRIC;
      (yyval.s).Num = num;
    ;}
    break;

  case 103:
#line 1362 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
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
#line 1380 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
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
#line 1398 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (11)].d);
      if(List_Nbr((yyvsp[(6) - (11)].l)) + (int)(yyvsp[(10) - (11)].d) + 1 != List_Nbr((yyvsp[(8) - (11)].l))){
	yymsg(GERROR, "Wrong definition of Nurbs Curve %d: "
	      "got %d knots, need N + D + 1 = %d + %d + 1 = %d",
	      (int)(yyvsp[(3) - (11)].d), List_Nbr((yyvsp[(8) - (11)].l)), List_Nbr((yyvsp[(6) - (11)].l)), (int)(yyvsp[(10) - (11)].d), List_Nbr((yyvsp[(6) - (11)].l)) + (int)(yyvsp[(10) - (11)].d) + 1);
      }
      else{
	if(FindCurve(num)){
	  yymsg(GERROR, "Curve %d already exists", num);
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
#line 1424 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindEdgeLoop(num)){
	yymsg(GERROR, "Line loop %d already exists", num);
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
#line 1441 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE)){
	yymsg(GERROR, "Physical line %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 108:
#line 1460 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurface(num)){
	yymsg(GERROR, "Surface %d already exists", num);
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

  case 109:
#line 1478 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d), type = 0;
      if(FindSurface(num)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	double d;
	List_Read((yyvsp[(7) - (8)].l), 0, &d);
	EdgeLoop *el = FindEdgeLoop((int)fabs(d));
	if(!el){
	  yymsg(GERROR, "Unknown line loop %d", (int)d);
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
	    yymsg(GERROR, "Wrong definition of Ruled Surface %d: "
		  "%d borders instead of 3 or 4", num, j);
	    type = MSH_SURF_PLAN;
	  }
	  Surface *s = Create_Surface(num, type);
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	  setSurfaceGeneratrices(s, temp);
	  List_Delete(temp);
	  End_Surface(s);
	  Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
	}
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = type;
      (yyval.s).Num = num;
    ;}
    break;

  case 110:
#line 1516 "Gmsh.y"
    {
      myGmshSurface = 0;
    ;}
    break;

  case 111:
#line 1520 "Gmsh.y"
    {
      myGmshSurface = gmshSurface :: surfaceByTag ( (int) (yyvsp[(3) - (4)].d));
    ;}
    break;

  case 112:
#line 1524 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d), type = 0;
      myGmshSurface = gmshParametricSurface::NewParametricSurface ((int)(yyvsp[(4) - (10)].d),(yyvsp[(7) - (10)].c),(yyvsp[(8) - (10)].c),(yyvsp[(9) - (10)].c));
    ;}
    break;

  case 113:
#line 1529 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d), type = 0;
      if (List_Nbr((yyvsp[(6) - (7)].l)) != 2){
	yymsg(GERROR, "Sphere %d has to be defined using 2 points (center + "
	      "any point) and not %d", num, List_Nbr((yyvsp[(6) - (7)].l)));
      }
      else{
	double p1,p2;
	List_Read((yyvsp[(6) - (7)].l), 0, &p1);
	List_Read((yyvsp[(6) - (7)].l), 1, &p2);
	Vertex *v1 = FindPoint((int)p1);
	Vertex *v2 = FindPoint((int)p2);
	if(!v1) yymsg(GERROR, "Sphere %d : unknown point %d", num, (int)p1);
	if(!v2) yymsg(GERROR, "Sphere %d : unknown point %d", num, (int)p2);
	myGmshSurface = gmshSphere::NewSphere
	  (num, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
	   sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
		(v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
		(v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
      }      
    ;}
    break;

  case 114:
#line 1551 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d), type = 0;
      if (List_Nbr((yyvsp[(6) - (7)].l)) != 2){
	yymsg(GERROR, "PolarSphere %d has to be defined using 2 points (center + "
	      "any point) and not %d", num, List_Nbr((yyvsp[(6) - (7)].l)));
      }
      else{
	double p1,p2;
	List_Read((yyvsp[(6) - (7)].l), 0, &p1);
	List_Read((yyvsp[(6) - (7)].l), 1, &p2);
	Vertex *v1 = FindPoint((int)p1);
	Vertex *v2 = FindPoint((int)p2);
	if(!v1) yymsg(GERROR, "PolarSphere %d : unknown point %d", num, (int)p1);
	if(!v2) yymsg(GERROR, "PolarSphere %d : unknown point %d", num, (int)p2);
	myGmshSurface = gmshPolarSphere::NewPolarSphere
	  (num, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
	   sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
		(v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
		(v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
      }      
    ;}
    break;

  case 115:
#line 1573 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurfaceLoop(num)){
	yymsg(GERROR, "Surface loop %d already exists", num);
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

  case 116:
#line 1589 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(GERROR, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    ;}
    break;

  case 117:
#line 1609 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindVolume(num)){
	yymsg(GERROR, "Volume %d already exists", num);
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

  case 118:
#line 1626 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindVolume(num)){
	yymsg(GERROR, "Volume %d already exists", num);
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

  case 119:
#line 1643 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME)){
	yymsg(GERROR, "Physical volume %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 120:
#line 1664 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 121:
#line 1669 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 122:
#line 1674 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 123:
#line 1679 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 124:
#line 1684 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	CopyShape(TheShape.Type, TheShape.Num, &TheShape.Num);
	List_Add((yyval.l), &TheShape);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 125:
#line 1695 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 126:
#line 1701 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      BoundaryShapes((yyvsp[(3) - (4)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 127:
#line 1709 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 128:
#line 1710 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 129:
#line 1715 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 130:
#line 1719 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 131:
#line 1723 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Vertex *v = FindPoint(TheShape.Num);
	if(v){
	  TheShape.Type = MSH_POINT;
	  List_Add((yyval.l), &TheShape);
	}
	else{
	  GVertex *gv = GModel::current()->vertexByTag(TheShape.Num);
	  if(gv){
	    TheShape.Type = MSH_POINT_FROM_GMODEL;
	    List_Add((yyval.l), &TheShape);
	  }
	  else
	    yymsg(WARNING, "Unknown point %d", TheShape.Num);
	}
      }
    ;}
    break;

  case 132:
#line 1746 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Curve *c = FindCurve(TheShape.Num);
	if(c){
	  TheShape.Type = c->Typ;
	  List_Add((yyval.l), &TheShape);
	}
	else{
	  GEdge *ge = GModel::current()->edgeByTag(TheShape.Num);
	  if(ge){
	    TheShape.Type = MSH_SEGM_FROM_GMODEL;
	    List_Add((yyval.l), &TheShape);
	  }
	  else
	    yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	}
      }
    ;}
    break;

  case 133:
#line 1769 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Surface *s = FindSurface(TheShape.Num);
	if(s){
	  TheShape.Type = s->Typ;
	  List_Add((yyval.l), &TheShape);
	}
	else{
	  GFace *gf = GModel::current()->faceByTag(TheShape.Num);
	  if(gf){
	    TheShape.Type = MSH_SURF_FROM_GMODEL;
	    List_Add((yyval.l), &TheShape);
	  }
	  else
	    yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	}
      }
    ;}
    break;

  case 134:
#line 1792 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Volume *v = FindVolume(TheShape.Num);
	if(v){
	  TheShape.Type = v->Typ;
	  List_Add((yyval.l), &TheShape);
	}
	else{
	  GRegion *gr = GModel::current()->regionByTag(TheShape.Num);
	  if(gr){
	    TheShape.Type = MSH_VOLUME_FROM_GMODEL;
	    List_Add((yyval.l), &TheShape);
	  }
	  else
	    yymsg(WARNING, "Unknown volume %d", TheShape.Num);
	}
      }
    ;}
    break;

  case 135:
#line 1820 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 136:
#line 1829 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < PView::list.size())
	  delete PView::list[index];
	else
	  yymsg(GERROR, "Unknown view %d", index);
      }
      else
	yymsg(GERROR, "Unknown command 'Delete %s'", (yyvsp[(2) - (6)].c));
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 137:
#line 1842 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Meshes") || !strcmp((yyvsp[(2) - (3)].c), "All")){
	GModel::current()->destroy();
	GModel::current()->getGEOInternals()->destroy();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Physicals")){
	List_Action(GModel::current()->getGEOInternals()->PhysicalGroups, 
		    Free_PhysicalGroup);
	List_Reset(GModel::current()->getGEOInternals()->PhysicalGroups);
	GModel::current()->deletePhysicalGroups();
      }
      else
	yymsg(GERROR, "Unknown command 'Delete %s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 138:
#line 1858 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (4)].c), "Empty") && !strcmp((yyvsp[(3) - (4)].c), "Views")){
	for(int i = PView::list.size() - 1; i >= 0; i--)
	  if(PView::list[i]->getData()->empty()) delete PView::list[i];
      }
      else
	yymsg(GERROR, "Unknown command 'Delete %s %s'", (yyvsp[(2) - (4)].c), (yyvsp[(3) - (4)].c));
      Free((yyvsp[(2) - (4)].c)); Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 139:
#line 1873 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));      
    ;}
    break;

  case 140:
#line 1887 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 141:
#line 1893 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 142:
#line 1899 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 143:
#line 1908 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 144:
#line 1922 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Include")){
	char tmpstring[1024];
	FixRelativePath((yyvsp[(2) - (3)].c), tmpstring);
	// Warning: we *don't* close included files (to allow user
	// functions in these files). If you need to include many many
	// files and don't have functions in the files, use "Merge"
	// instead: some OSes limit the number of files a process can
	// open simultaneously. The right solution would be of course
	// to modify FunctionManager to reopen the files instead of
	// using the FILE pointer, but hey, I'm lazy...
	Msg(STATUS2, "Reading '%s'", tmpstring);
	ParseFile(tmpstring, 0, 1);
	SetBoundingBox();
	Msg(STATUS2, "Read '%s'", tmpstring);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Print")){
#if defined(HAVE_FLTK)
	// make sure we have the latest data from GEO_Internals in GModel
	// (fixes bug where we would have no geometry in the picture if
	// the print command is in the same file as the geometry)
	GModel::current()->importGEOInternals();
	char tmpstring[1024];
	FixRelativePath((yyvsp[(2) - (3)].c), tmpstring);
	CreateOutputFile(tmpstring, CTX.print.format);
#endif
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Save")){
#if defined(HAVE_FLTK)
	GModel::current()->importGEOInternals();
	char tmpstring[1024];
	FixRelativePath((yyvsp[(2) - (3)].c), tmpstring);
	CreateOutputFile(tmpstring, CTX.mesh.format);
#endif
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Merge") || !strcmp((yyvsp[(1) - (3)].c), "MergeWithBoundingBox")){
	// MergeWithBoundingBox is deprecated
	char tmpstring[1024];
	FixRelativePath((yyvsp[(2) - (3)].c), tmpstring);
	MergeFile(tmpstring, 1);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "System"))
	SystemCall((yyvsp[(2) - (3)].c));
      else
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 145:
#line 1970 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (7)].c), "Save") && !strcmp((yyvsp[(2) - (7)].c), "View")){
	int index = (int)(yyvsp[(4) - (7)].d);
	if(index >= 0 && index < PView::list.size()){
	  char tmpstring[1024];
	  FixRelativePath((yyvsp[(6) - (7)].c), tmpstring);
	  PView::list[index]->write(tmpstring, CTX.post.file_format);
	}
	else
	  yymsg(GERROR, "Unknown view %d", index);
      }
      else
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[(1) - (7)].c));
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(2) - (7)].c)); Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 146:
#line 1986 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (7)].c), "Background") && !strcmp((yyvsp[(2) - (7)].c), "Mesh")  && !strcmp((yyvsp[(3) - (7)].c), "View")){
	int index = (int)(yyvsp[(5) - (7)].d);
	if(index >= 0 && index < PView::list.size()){
	  Field *field = new PostViewField(PView::list[index]);
	  fields.insert(field);
	  BGMAddField(field);
	}
	else
	  yymsg(GERROR, "Unknown view %d", index);
      }
      else
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[(1) - (7)].c));
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(2) - (7)].c)); Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 147:
#line 2002 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Sleep")){
	SleepInSeconds((yyvsp[(2) - (3)].d));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Remesh")){
	Msg(GERROR, "Surface ReMeshing must be reinterfaced");
	//	ReMesh();
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Mesh")){
	yymsg(GERROR, "Mesh directives are not (yet) allowed in scripts");
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Status")){
	yymsg(GERROR, "Mesh directives are not (yet) allowed in scripts");
      }
      else
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 148:
#line 2021 "Gmsh.y"
    {
       try {
	 GMSH_PluginManager::instance()->action((yyvsp[(3) - (7)].c), (yyvsp[(6) - (7)].c), 0);
       }
       catch(...) {
	 yymsg(GERROR, "Unknown action '%s' or plugin '%s'", (yyvsp[(6) - (7)].c), (yyvsp[(3) - (7)].c));
       }
       Free((yyvsp[(3) - (7)].c)); Free((yyvsp[(6) - (7)].c));
     ;}
    break;

  case 149:
#line 2031 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "ElementsFromAllViews"))
	PView::combine(false, 1, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "ElementsFromVisibleViews"))
	PView::combine(false, 0, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "ElementsByViewName"))
	PView::combine(false, 2, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsFromAllViews"))
	PView::combine(true, 1, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsFromVisibleViews"))
	PView::combine(true, 0, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsByViewName"))
	PView::combine(true, 2, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "Views"))
	PView::combine(false, 1, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeSteps"))
	PView::combine(true, 2, CTX.post.combine_remove_orig);
      else
	yymsg(GERROR, "Unknown 'Combine' command");
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 150:
#line 2053 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 151:
#line 2057 "Gmsh.y"
    {
      CTX.forced_bbox = 0;
      SetBoundingBox();
    ;}
    break;

  case 152:
#line 2062 "Gmsh.y"
    {
      CTX.forced_bbox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 153:
#line 2067 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      Draw();
#endif
    ;}
    break;

  case 154:
#line 2079 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if((yyvsp[(3) - (6)].d) > (yyvsp[(5) - (6)].d)) skip_until("For", "EndFor");
    ;}
    break;

  case 155:
#line 2094 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if(((yyvsp[(7) - (8)].d) > 0. && (yyvsp[(3) - (8)].d) > (yyvsp[(5) - (8)].d)) || ((yyvsp[(7) - (8)].d) < 0. && (yyvsp[(3) - (8)].d) < (yyvsp[(5) - (8)].d)))
	skip_until("For", "EndFor");
    ;}
    break;

  case 156:
#line 2110 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (8)].c);
      Symbol TheSymbol;      
      TheSymbol.Name = (yyvsp[(2) - (8)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(1, 1, sizeof(double));
	List_Put(TheSymbol.val, 0, &(yyvsp[(5) - (8)].d));
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else
	List_Write(pSymbol->val, 0, &(yyvsp[(5) - (8)].d));
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if((yyvsp[(5) - (8)].d) > (yyvsp[(7) - (8)].d)) skip_until("For", "EndFor");
    ;}
    break;

  case 157:
#line 2135 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(9) - (10)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (10)].c);
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(2) - (10)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(1, 1, sizeof(double));
	List_Put(TheSymbol.val, 0, &(yyvsp[(5) - (10)].d));
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else
	List_Write(pSymbol->val, 0, &(yyvsp[(5) - (10)].d));
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if(((yyvsp[(9) - (10)].d) > 0. && (yyvsp[(5) - (10)].d) > (yyvsp[(7) - (10)].d)) || ((yyvsp[(9) - (10)].d) < 0. && (yyvsp[(5) - (10)].d) < (yyvsp[(7) - (10)].d)))
	skip_until("For", "EndFor");
    ;}
    break;

  case 158:
#line 2161 "Gmsh.y"
    {
      if(ImbricatedLoop <= 0){
	yymsg(GERROR, "Invalid For/EndFor loop");
	ImbricatedLoop = 0;
      }
      else{
	double x0 = LoopControlVariablesTab[ImbricatedLoop-1][0];
	double x1 = LoopControlVariablesTab[ImbricatedLoop-1][1];
	double step = LoopControlVariablesTab[ImbricatedLoop-1][2];
	int do_next = (step > 0.) ? (x0+step <= x1) : (x0+step >= x1);
	if(do_next){
	  LoopControlVariablesTab[ImbricatedLoop-1][0] +=
	    LoopControlVariablesTab[ImbricatedLoop-1][2];
	  if(LoopControlVariablesNameTab[ImbricatedLoop-1]){
	    Symbol TheSymbol;
	    TheSymbol.Name = LoopControlVariablesNameTab[ImbricatedLoop-1];
	    Symbol *pSymbol;
	    if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol)))
	      yymsg(GERROR, "Unknown loop variable");
	    else
	      *(double*)List_Pointer_Fast(pSymbol->val, 0) += 
		LoopControlVariablesTab[ImbricatedLoop-1][2];
	  }
	  fsetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop-1]);
	  yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop-1];
	}
	else
	  ImbricatedLoop--;
      }
    ;}
    break;

  case 159:
#line 2192 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction((yyvsp[(2) - (2)].c), yyin, yyname, yylineno))
	yymsg(GERROR, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 160:
#line 2199 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin, yyname, yylineno))
	yymsg(GERROR, "Error while exiting function");
    ;}
    break;

  case 161:
#line 2204 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction((yyvsp[(2) - (3)].c), &yyin, yyname, yylineno))
	yymsg(GERROR, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 162:
#line 2210 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 163:
#line 2214 "Gmsh.y"
    {
    ;}
    break;

  case 164:
#line 2223 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 165:
#line 2231 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 166:
#line 2239 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 167:
#line 2247 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 168:
#line 2251 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 169:
#line 2259 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 170:
#line 2263 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 171:
#line 2271 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 172:
#line 2275 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 173:
#line 2283 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 174:
#line 2287 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 175:
#line 2294 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 176:
#line 2298 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      extr.mesh.ViewIndex = (int)(yyvsp[(4) - (10)].d);
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(7) - (10)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      extr.mesh.ViewIndex = -1;
      Free((yyvsp[(2) - (10)].c));
      List_Delete((yyvsp[(7) - (10)].l));
    ;}
    break;

  case 177:
#line 2310 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 178:
#line 2317 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 179:
#line 2324 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 180:
#line 2331 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 181:
#line 2338 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 182:
#line 2345 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 183:
#line 2352 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 184:
#line 2359 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 185:
#line 2366 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 186:
#line 2373 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 187:
#line 2377 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 188:
#line 2384 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 189:
#line 2388 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 190:
#line 2395 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 191:
#line 2399 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 192:
#line 2406 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 193:
#line 2410 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 194:
#line 2417 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 195:
#line 2421 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 196:
#line 2428 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 197:
#line 2432 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 198:
#line 2439 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 199:
#line 2443 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 200:
#line 2450 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 201:
#line 2454 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 202:
#line 2461 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 203:
#line 2465 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 204:
#line 2476 "Gmsh.y"
    {
    ;}
    break;

  case 205:
#line 2479 "Gmsh.y"
    {
    ;}
    break;

  case 206:
#line 2485 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 207:
#line 2494 "Gmsh.y"
    {
      double d;
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[(3) - (7)].l));
      if(List_Nbr((yyvsp[(3) - (7)].l)) == List_Nbr((yyvsp[(5) - (7)].l))){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr((yyvsp[(3) - (7)].l)); i++){
	  List_Read((yyvsp[(3) - (7)].l), i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read((yyvsp[(5) - (7)].l), i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else
	yymsg(GERROR, "Wrong layer definition {%d, %d}", List_Nbr((yyvsp[(3) - (7)].l)), List_Nbr((yyvsp[(5) - (7)].l)));
      List_Delete((yyvsp[(3) - (7)].l));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 208:
#line 2514 "Gmsh.y"
    {
      yymsg(GERROR, "Explicit region numbers in layers are deprecated");
      double d;
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[(3) - (9)].l));
      if(List_Nbr((yyvsp[(3) - (9)].l)) == List_Nbr((yyvsp[(5) - (9)].l)) && List_Nbr((yyvsp[(3) - (9)].l)) == List_Nbr((yyvsp[(7) - (9)].l))){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
	  List_Read((yyvsp[(3) - (9)].l), i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read((yyvsp[(7) - (9)].l), i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else
	yymsg(GERROR, "Wrong layer definition {%d, %d, %d}", List_Nbr((yyvsp[(3) - (9)].l)), 
	      List_Nbr((yyvsp[(5) - (9)].l)), List_Nbr((yyvsp[(7) - (9)].l)));
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(5) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 209:
#line 2537 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 210:
#line 2541 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (9)].d);
      if(FindSurface(num)){
	yymsg(GERROR, "Surface %d already exists", num);
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

  case 211:
#line 2565 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = ((yyvsp[(5) - (6)].d)>2)?(int)(yyvsp[(5) - (6)].d):2;
	  c->ipar[1] = sign(d);
	  c->dpar[0] = 1.0;
	}
      }
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 212:
#line 2583 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (9)].l), i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = ((yyvsp[(5) - (9)].d)>2)?(int)(yyvsp[(5) - (9)].d):2;
	  c->ipar[1] = sign(d); /* Progresion : code 1 ou -1 */
	  c->dpar[0] = fabs((yyvsp[(8) - (9)].d));
	}
      }
      List_Delete((yyvsp[(3) - (9)].l));
    ;}
    break;

  case 213:
#line 2601 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (9)].l), i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = ((yyvsp[(5) - (9)].d)>2)?(int)(yyvsp[(5) - (9)].d):2;
	  c->ipar[1] = 2*sign(d); /* Bump : code 2 ou -2 */
	  c->dpar[0] = fabs((yyvsp[(8) - (9)].d));
	}
      }
      List_Delete((yyvsp[(3) - (9)].l));
    ;}
    break;

  case 214:
#line 2619 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(4) - (8)].d));
      if(!s)
	yymsg(WARNING, "Unknown surface %d", (int)(yyvsp[(4) - (8)].d));
      else{
	s->Method = TRANSFINI;
	s->Recombine_Dir = -1;
	int k = List_Nbr((yyvsp[(7) - (8)].l));
	if(k != 3 && k != 4){
	  yymsg(GERROR, "Wrong definition of Transfinite Surface %d: "
		"%d points instead of 3 or 4" , (int)(yyvsp[(4) - (8)].d), k);
	}
	else{
	  List_Reset(s->TrsfPoints);
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read((yyvsp[(7) - (8)].l), i, &d);
	    int j = (int)fabs(d);
	    Vertex *v = FindPoint(j);
	    if(!v)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(s->TrsfPoints, &v);
	  }
	}
      }
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 215:
#line 2648 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(4) - (9)].d));
      if(!s)
	yymsg(WARNING, "Unknown surface %d", (int)(yyvsp[(4) - (9)].d));
      else{
	s->Method = TRANSFINI;
	int k = List_Nbr((yyvsp[(7) - (9)].l));
	if(k != 3 && k != 4){
	  yymsg(GERROR, "Wrong definition of Transfinite Surface %d: "
		"%d points instead of 3 or 4" , (int)(yyvsp[(4) - (9)].d), k);
	}
	else{
	  List_Reset(s->TrsfPoints);
	  if (!strcmp((yyvsp[(8) - (9)].c), "Right"))
	    s->Recombine_Dir = 1;
	  else if (!strcmp((yyvsp[(8) - (9)].c), "Left"))
	    s->Recombine_Dir = -1;
	  else
	    s->Recombine_Dir = 0;
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read((yyvsp[(7) - (9)].l), i, &d);
	    int j = (int)fabs(d);
	    Vertex *v = FindPoint(j);
	    if(!v)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(s->TrsfPoints, &v);
	  }
	}
      }
      List_Delete((yyvsp[(7) - (9)].l));
      Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 216:
#line 2683 "Gmsh.y"
    {
      yymsg(WARNING, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 217:
#line 2688 "Gmsh.y"
    {
      Volume *v = FindVolume((int)(yyvsp[(4) - (8)].d));
      if(!v)
	yymsg(WARNING, "Unknown volume %d", (int)(yyvsp[(4) - (8)].d));
      else{
	v->Method = TRANSFINI;
	int k = List_Nbr((yyvsp[(7) - (8)].l));
	if(k != 6 && k != 8)
	  yymsg(GERROR, "Wrong definition of Transfinite Volume %d: "
		"%d points instead of 6 or 8" , (int)(yyvsp[(4) - (8)].d), k);
	else{
	  List_Reset(v->TrsfPoints);
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read((yyvsp[(7) - (8)].l), i, &d);
	    int j = (int)fabs(d);
	    Vertex *vert = FindPoint(j);
	    if(!vert)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(v->TrsfPoints, &vert);
	  }
	}
      }
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 218:
#line 2715 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	int j = (int)d;
	Surface *s = FindSurface(j);
	if(s){
	  s->Recombine = 1;
	  s->RecombineAngle = ((yyvsp[(5) - (6)].d) > 0 && (yyvsp[(5) - (6)].d) < 90) ? (yyvsp[(5) - (6)].d) : 90;
	}
      }
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 219:
#line 2729 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (4)].l), i, &d);
	int j = (int)d;
        Surface *s = FindSurface(j);
	if(s){
	  s->Recombine = 1;
        }
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 220:
#line 2748 "Gmsh.y"
    { 
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s)
	setSurfaceEmbeddedPoints(s, (yyvsp[(3) - (10)].l));
    ;}
    break;

  case 221:
#line 2754 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s)
	setSurfaceEmbeddedCurves(s, (yyvsp[(3) - (10)].l));
    ;}
    break;

  case 222:
#line 2760 "Gmsh.y"
    {
    ;}
    break;

  case 223:
#line 2763 "Gmsh.y"
    {
    ;}
    break;

  case 224:
#line 2772 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 225:
#line 2781 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 226:
#line 2782 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 227:
#line 2783 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 228:
#line 2784 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 229:
#line 2785 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 230:
#line 2786 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 231:
#line 2787 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 232:
#line 2788 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 233:
#line 2790 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(GERROR, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 234:
#line 2796 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 235:
#line 2797 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 236:
#line 2798 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 237:
#line 2799 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 238:
#line 2800 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 239:
#line 2801 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 240:
#line 2802 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 241:
#line 2803 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 242:
#line 2804 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 243:
#line 2805 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 244:
#line 2806 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d)? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d);  ;}
    break;

  case 245:
#line 2807 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 246:
#line 2808 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 247:
#line 2809 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 248:
#line 2810 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 249:
#line 2811 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 250:
#line 2812 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 251:
#line 2813 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 252:
#line 2814 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 253:
#line 2815 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 254:
#line 2816 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 255:
#line 2817 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 256:
#line 2818 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 257:
#line 2819 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 258:
#line 2820 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 259:
#line 2821 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 260:
#line 2822 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 261:
#line 2823 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 262:
#line 2824 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 263:
#line 2825 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 264:
#line 2826 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d)*(yyvsp[(3) - (6)].d)+(yyvsp[(5) - (6)].d)*(yyvsp[(5) - (6)].d)); ;}
    break;

  case 265:
#line 2827 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 266:
#line 2829 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 267:
#line 2830 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 268:
#line 2831 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 269:
#line 2832 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 270:
#line 2833 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 271:
#line 2834 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 272:
#line 2835 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 273:
#line 2836 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 274:
#line 2837 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 275:
#line 2838 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 276:
#line 2839 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 277:
#line 2840 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 278:
#line 2841 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 279:
#line 2842 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 280:
#line 2843 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 281:
#line 2844 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 282:
#line 2845 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 283:
#line 2846 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 284:
#line 2847 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 285:
#line 2848 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d)*(yyvsp[(3) - (6)].d)+(yyvsp[(5) - (6)].d)*(yyvsp[(5) - (6)].d)); ;}
    break;

  case 286:
#line 2849 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 287:
#line 2858 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 288:
#line 2859 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 289:
#line 2860 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->rank(); ;}
    break;

  case 290:
#line 2861 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->size(); ;}
    break;

  case 291:
#line 2862 "Gmsh.y"
    { (yyval.d) = Get_GmshMajorVersion(); ;}
    break;

  case 292:
#line 2863 "Gmsh.y"
    { (yyval.d) = Get_GmshMinorVersion(); ;}
    break;

  case 293:
#line 2864 "Gmsh.y"
    { (yyval.d) = Get_GmshPatchVersion(); ;}
    break;

  case 294:
#line 2869 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(1) - (1)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[(1) - (1)].c));
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = *(double*)List_Pointer_Fast(pSymbol->val, 0);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 295:
#line 2885 "Gmsh.y"
    {
      char tmpstring[1024];
      sprintf(tmpstring, "%s_%d", (yyvsp[(1) - (5)].c), (int)(yyvsp[(4) - (5)].d)) ;
      Symbol TheSymbol;
      TheSymbol.Name = tmpstring;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", tmpstring);
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = *(double*)List_Pointer_Fast(pSymbol->val, 0);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 296:
#line 2900 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(1) - (4)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
	(yyval.d) = 0.;
      }
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)(yyvsp[(3) - (4)].d))))
	  (yyval.d) = *pd;
	else{
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (4)].c), (int)(yyvsp[(3) - (4)].d));
	  (yyval.d) = 0.;
	}
      }
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 297:
#line 2920 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(2) - (4)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[(2) - (4)].c));
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = List_Nbr(pSymbol->val);
      Free((yyvsp[(2) - (4)].c));
    ;}
    break;

  case 298:
#line 2933 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(1) - (2)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[(1) - (2)].c));
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = (*(double*)List_Pointer_Fast(pSymbol->val, 0) += (yyvsp[(2) - (2)].i));
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 299:
#line 2946 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(1) - (5)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[(1) - (5)].c));
	(yyval.d) = 0.;
      }
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)(yyvsp[(3) - (5)].d))))
	  (yyval.d) = (*pd += (yyvsp[(5) - (5)].i));
	else{
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (5)].c), (int)(yyvsp[(3) - (5)].d));
	  (yyval.d) = 0.;
	}
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 300:
#line 2969 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[(1) - (3)].c)))){
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[(1) - (3)].c));
	(yyval.d) = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption((yyvsp[(3) - (3)].c), pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
	  (yyval.d) = 0.;
	}
	else
	  (yyval.d) = pNumOpt(0, GMSH_GET, 0);
      }
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 301:
#line 2987 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[(1) - (6)].c)))){
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[(1) - (6)].c));
	(yyval.d) = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption((yyvsp[(6) - (6)].c), pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c));
	  (yyval.d) = 0.;
	}
	else
	  (yyval.d) = pNumOpt((int)(yyvsp[(3) - (6)].d), GMSH_GET, 0);
      }
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 302:
#line 3005 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[(1) - (4)].c)))){
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[(1) - (4)].c));
	(yyval.d) = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption((yyvsp[(3) - (4)].c), pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", (yyvsp[(1) - (4)].c), (yyvsp[(3) - (4)].c));
	  (yyval.d) = 0.;
	}
	else
	  (yyval.d) = pNumOpt(0, GMSH_SET|GMSH_GUI, pNumOpt(0, GMSH_GET, 0)+(yyvsp[(4) - (4)].i));
      }
      Free((yyvsp[(1) - (4)].c)); Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 303:
#line 3023 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[(1) - (7)].c)))){
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[(1) - (7)].c));
	(yyval.d) = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption((yyvsp[(6) - (7)].c), pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", (yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
	  (yyval.d) = 0.;
	}
	else
	  (yyval.d) = pNumOpt((int)(yyvsp[(3) - (7)].d), GMSH_SET|GMSH_GUI, pNumOpt((int)(yyvsp[(3) - (7)].d), GMSH_GET, 0)+(yyvsp[(7) - (7)].i));
      }
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 304:
#line 3041 "Gmsh.y"
    { 
      (yyval.d) = GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 305:
#line 3049 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 306:
#line 3053 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 307:
#line 3057 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 308:
#line 3061 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 309:
#line 3065 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 310:
#line 3072 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 311:
#line 3076 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 312:
#line 3080 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 313:
#line 3084 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 314:
#line 3091 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 315:
#line 3096 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 316:
#line 3104 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 317:
#line 3109 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 318:
#line 3113 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 319:
#line 3118 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 320:
#line 3122 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 321:
#line 3130 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 322:
#line 3141 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 323:
#line 3149 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 324:
#line 3157 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 325:
#line 3163 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      if(!(yyvsp[(5) - (5)].d) || ((yyvsp[(1) - (5)].d) < (yyvsp[(3) - (5)].d) && (yyvsp[(5) - (5)].d) < 0) || ((yyvsp[(1) - (5)].d) > (yyvsp[(3) - (5)].d) && (yyvsp[(5) - (5)].d) > 0)){
        yymsg(GERROR, "Wrong increment in '%g:%g:%g'", (yyvsp[(1) - (5)].d), (yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].d));
	List_Add((yyval.l), &((yyvsp[(1) - (5)].d)));
      }
      else
	for(double d = (yyvsp[(1) - (5)].d); ((yyvsp[(5) - (5)].d) > 0) ? (d <= (yyvsp[(3) - (5)].d)) : (d >= (yyvsp[(3) - (5)].d)); d += (yyvsp[(5) - (5)].d))
	  List_Add((yyval.l), &d);
   ;}
    break;

  case 326:
#line 3174 "Gmsh.y"
    {
      // Returns the coordinates of a point and fills a list with it.
      // This allows to ensure e.g. that relative point positions are
      // always conserved
      Vertex *v = FindPoint((int)(yyvsp[(3) - (4)].d));
      (yyval.l) = List_Create(3, 1, sizeof(double));      
      if(!v) {
	yymsg(GERROR, "Unknown point '%d'", (int)(yyvsp[(3) - (4)].d));
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

  case 327:
#line 3194 "Gmsh.y"
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

  case 328:
#line 3204 "Gmsh.y"
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

  case 329:
#line 3214 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(1) - (3)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[(1) - (3)].c));
	double d = 0.0;
	List_Add((yyval.l), &d);
      }
      else{
	for(int i = 0; i < List_Nbr(pSymbol->val); i++)
	  List_Add((yyval.l), (double*)List_Pointer_Fast(pSymbol->val, i));
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 330:
#line 3231 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(1) - (6)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[(1) - (6)].c));
	double d = 0.0;
	List_Add((yyval.l), &d);
      }
      else{
	for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	  int j = (int)(*(double*)List_Pointer_Fast((yyvsp[(4) - (6)].l), i));
	  double *pd;
	  if((pd = (double*)List_Pointer_Test(pSymbol->val, j)))
	    List_Add((yyval.l), pd);
	  else
	    yymsg(GERROR, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (6)].c), j);	  
	}
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 331:
#line 3258 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 332:
#line 3263 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 333:
#line 3267 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 334:
#line 3271 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 335:
#line 3284 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 336:
#line 3288 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 337:
#line 3300 "Gmsh.y"
    {
      int flag;
      (yyval.u) = Get_ColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 338:
#line 3307 "Gmsh.y"
    {
      unsigned int (*pColOpt)(int num, int action, unsigned int value);
      StringXColor *pColCat;
      if(!(pColCat = Get_ColorOptionCategory((yyvsp[(1) - (5)].c)))){
	yymsg(GERROR, "Unknown color option class '%s'", (yyvsp[(1) - (5)].c));
	(yyval.u) = 0;
      }
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption((yyvsp[(5) - (5)].c), pColCat))){
	  yymsg(GERROR, "Unknown color option '%s.Color.%s'", (yyvsp[(1) - (5)].c), (yyvsp[(5) - (5)].c));
	  (yyval.u) = 0;
	}
	else
	  (yyval.u) = pColOpt(0, GMSH_GET, 0);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 339:
#line 3328 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 340:
#line 3332 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      GmshColorTable *ct = Get_ColorTable((int)(yyvsp[(3) - (6)].d));
      if(!ct)
	yymsg(GERROR, "View[%d] does not exist", (int)(yyvsp[(3) - (6)].d));
      else{
	for(int i = 0; i < ct->size; i++) 
	  List_Add((yyval.l), &ct->table[i]);
      }
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 341:
#line 3347 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 342:
#line 3352 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 343:
#line 3359 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 344:
#line 3363 "Gmsh.y"
    {
      Msg(WARNING, "Named string expressions not implemented yet");
    ;}
    break;

  case 345:
#line 3370 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 346:
#line 3374 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32*sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 347:
#line 3382 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c))+strlen((yyvsp[(5) - (6)].c))+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 348:
#line 3390 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (4)].c))+1)*sizeof(char));
      int i;
      for(i = strlen((yyvsp[(3) - (4)].c))-1; i >= 0; i--){
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

  case 349:
#line 3404 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (4)].c))+1)*sizeof(char));
      int i;
      for(i = strlen((yyvsp[(3) - (4)].c))-1; i >= 0; i--){
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

  case 350:
#line 3418 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 351:
#line 3422 "Gmsh.y"
    {
      char tmpstring[1024];
      int i = PrintListOfDouble((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].l), tmpstring);
      if(i < 0){
	yymsg(GERROR, "Too few arguments in Sprintf");
	(yyval.c) = (yyvsp[(3) - (6)].c);
      }
      else if(i > 0){
	yymsg(GERROR, "%d extra argument%s in Sprintf", i, (i>1)?"s":"");
	(yyval.c) = (yyvsp[(3) - (6)].c);
      }
      else{
	(yyval.c) = (char*)Malloc((strlen(tmpstring)+1)*sizeof(char));
	strcpy((yyval.c), tmpstring);
	Free((yyvsp[(3) - (6)].c));
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 352:
#line 3441 "Gmsh.y"
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory((yyvsp[(3) - (6)].c)))){
	yymsg(GERROR, "Unknown string option class '%s'", (yyvsp[(3) - (6)].c));
	(yyval.c) = (char*)Malloc(sizeof(char));
	(yyval.c)[0] = '\0';
      }
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption((yyvsp[(5) - (6)].c), pStrCat))){
	  yymsg(GERROR, "Unknown string option '%s.%s'", (yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
	  (yyval.c) = (char*)Malloc(sizeof(char));
	  (yyval.c)[0] = '\0';
	}
	else{
	  char *str = pStrOpt(0, GMSH_GET, NULL);
	  (yyval.c) = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy((yyval.c), str);
	}
      }
    ;}
    break;

  case 353:
#line 3463 "Gmsh.y"
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory((yyvsp[(3) - (9)].c)))){
	yymsg(GERROR, "Unknown string option class '%s'", (yyvsp[(3) - (9)].c));
	(yyval.c) = (char*)Malloc(sizeof(char));
	(yyval.c)[0] = '\0';
      }
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption((yyvsp[(8) - (9)].c), pStrCat))){
	  yymsg(GERROR, "Unknown string option '%s[%d].%s'", (yyvsp[(3) - (9)].c), (int)(yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].c));
	  (yyval.c) = (char*)Malloc(sizeof(char));
	  (yyval.c)[0] = '\0';
	}
	else{
	  char *str = pStrOpt((int)(yyvsp[(5) - (9)].d), GMSH_GET, NULL);
	  (yyval.c) = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy((yyval.c), str);
	}
      }
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 7961 "Gmsh.tab.cpp"
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


#line 3486 "Gmsh.y"


void DeleteSymbol(void *a, void *b){
  Symbol *s = (Symbol*)a;
  Free(s->Name);
  List_Delete(s->val);
}

int CompareSymbols (const void *a, const void *b){
  return(strcmp(((Symbol*)a)->Name, ((Symbol*)b)->Name));
}

void InitSymbols(void){
  if(Symbol_T){
    Tree_Action(Symbol_T, DeleteSymbol);
    Tree_Delete(Symbol_T);
  }
  Symbol_T = Tree_Create(sizeof(Symbol), CompareSymbols);
}

int PrintListOfDouble(char *format, List_T *list, char *buffer){
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

void yyerror(char *s){
  Msg(GERROR, "'%s', line %d : %s (%s)", yyname, yylineno-1, s, yytext);
  yyerrorstate++;
}

void yymsg(int type, char *fmt, ...){
  va_list args;
  char tmp[1024];

  va_start (args, fmt);
  vsprintf (tmp, fmt, args);
  va_end (args);

  Msg(type, "'%s', line %d : %s", yyname, yylineno-1, tmp);

  if(type == GERROR) yyerrorstate++;
}

