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
     tSmoother = 328,
     tDelete = 329,
     tCoherence = 330,
     tIntersect = 331,
     tBoundary = 332,
     tAttractor = 333,
     tLayers = 334,
     tHole = 335,
     tAlias = 336,
     tAliasWithOptions = 337,
     tText2D = 338,
     tText3D = 339,
     tInterpolationScheme = 340,
     tTime = 341,
     tCombine = 342,
     tBSpline = 343,
     tBezier = 344,
     tNurbs = 345,
     tOrder = 346,
     tKnots = 347,
     tColor = 348,
     tColorTable = 349,
     tFor = 350,
     tIn = 351,
     tEndFor = 352,
     tIf = 353,
     tEndIf = 354,
     tExit = 355,
     tField = 356,
     tThreshold = 357,
     tStructured = 358,
     tLatLon = 359,
     tGrad = 360,
     tPostView = 361,
     tReturn = 362,
     tCall = 363,
     tFunction = 364,
     tShow = 365,
     tHide = 366,
     tGetValue = 367,
     tGMSH_MAJOR_VERSION = 368,
     tGMSH_MINOR_VERSION = 369,
     tGMSH_PATCH_VERSION = 370,
     tAFFECTDIVIDE = 371,
     tAFFECTTIMES = 372,
     tAFFECTMINUS = 373,
     tAFFECTPLUS = 374,
     tOR = 375,
     tAND = 376,
     tNOTEQUAL = 377,
     tEQUAL = 378,
     tGREATEROREQUAL = 379,
     tLESSOREQUAL = 380,
     UNARYPREC = 381,
     tMINUSMINUS = 382,
     tPLUSPLUS = 383
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
#define tSmoother 328
#define tDelete 329
#define tCoherence 330
#define tIntersect 331
#define tBoundary 332
#define tAttractor 333
#define tLayers 334
#define tHole 335
#define tAlias 336
#define tAliasWithOptions 337
#define tText2D 338
#define tText3D 339
#define tInterpolationScheme 340
#define tTime 341
#define tCombine 342
#define tBSpline 343
#define tBezier 344
#define tNurbs 345
#define tOrder 346
#define tKnots 347
#define tColor 348
#define tColorTable 349
#define tFor 350
#define tIn 351
#define tEndFor 352
#define tIf 353
#define tEndIf 354
#define tExit 355
#define tField 356
#define tThreshold 357
#define tStructured 358
#define tLatLon 359
#define tGrad 360
#define tPostView 361
#define tReturn 362
#define tCall 363
#define tFunction 364
#define tShow 365
#define tHide 366
#define tGetValue 367
#define tGMSH_MAJOR_VERSION 368
#define tGMSH_MINOR_VERSION 369
#define tGMSH_PATCH_VERSION 370
#define tAFFECTDIVIDE 371
#define tAFFECTTIMES 372
#define tAFFECTMINUS 373
#define tAFFECTPLUS 374
#define tOR 375
#define tAND 376
#define tNOTEQUAL 377
#define tEQUAL 378
#define tGREATEROREQUAL 379
#define tLESSOREQUAL 380
#define UNARYPREC 381
#define tMINUSMINUS 382
#define tPLUSPLUS 383




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// $Id: Gmsh.tab.cpp,v 1.345 2008-02-08 18:46:48 geuzaine Exp $
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
#include "Message.h"
#include "Malloc.h"
#include "Tools.h"
#include "PluginManager.h"
#include "ParUtil.h"
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
#line 78 "Gmsh.y"
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
#line 447 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 460 "Gmsh.tab.cpp"

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
#define YYLAST   6691

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  149
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  354
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1280

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   383

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   134,     2,   144,     2,   133,     2,     2,
     139,   140,   131,   129,   145,   130,   143,   132,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     125,     2,   126,   120,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   141,     2,   142,   138,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   146,     2,   147,   148,     2,     2,     2,
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
     115,   116,   117,   118,   119,   121,   122,   123,   124,   127,
     128,   135,   136,   137
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
    1444,  1451,  1462,  1473,  1484,  1495,  1498,  1500,  1504,  1507,
    1510,  1513,  1517,  1521,  1525,  1529,  1533,  1537,  1541,  1545,
    1549,  1553,  1557,  1561,  1565,  1569,  1575,  1580,  1585,  1590,
    1595,  1600,  1605,  1610,  1615,  1620,  1625,  1632,  1637,  1642,
    1647,  1652,  1657,  1662,  1669,  1676,  1683,  1688,  1693,  1698,
    1703,  1708,  1713,  1718,  1723,  1728,  1733,  1738,  1745,  1750,
    1755,  1760,  1765,  1770,  1775,  1782,  1789,  1796,  1801,  1803,
    1805,  1807,  1809,  1811,  1813,  1815,  1817,  1823,  1828,  1833,
    1836,  1842,  1846,  1853,  1858,  1866,  1873,  1875,  1878,  1881,
    1885,  1889,  1901,  1911,  1919,  1927,  1929,  1933,  1935,  1937,
    1940,  1944,  1949,  1955,  1958,  1962,  1966,  1972,  1977,  1979,
    1981,  1985,  1992,  1994,  1996,  2000,  2004,  2014,  2022,  2024,
    2030,  2034,  2041,  2043,  2047,  2049,  2051,  2053,  2055,  2062,
    2067,  2072,  2077,  2084,  2091
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     150,     0,    -1,   151,    -1,     1,     6,    -1,    -1,   151,
     152,    -1,   155,    -1,   154,    -1,   173,    -1,   175,    -1,
     176,    -1,   179,    -1,   180,    -1,   181,    -1,   184,    -1,
     201,    -1,   202,    -1,   203,    -1,   183,    -1,   182,    -1,
     126,    -1,   126,   126,    -1,    35,   139,     5,   140,     6,
      -1,    35,   139,     5,   140,   153,   215,     6,    -1,    35,
     139,     5,   145,   211,   140,     6,    -1,    35,   139,     5,
     145,   211,   140,   153,   215,     6,    -1,     4,     5,   146,
     156,   147,     6,    -1,    81,     4,   141,   204,   142,     6,
      -1,    82,     4,   141,   204,   142,     6,    -1,    -1,   156,
     159,    -1,   156,   163,    -1,   156,   166,    -1,   156,   168,
      -1,   156,   169,    -1,   204,    -1,   157,   145,   204,    -1,
     204,    -1,   158,   145,   204,    -1,    -1,    -1,     4,   160,
     139,   157,   140,   161,   146,   158,   147,     6,    -1,   215,
      -1,   162,   145,   215,    -1,    -1,    83,   139,   204,   145,
     204,   145,   204,   140,   164,   146,   162,   147,     6,    -1,
     215,    -1,   165,   145,   215,    -1,    -1,    84,   139,   204,
     145,   204,   145,   204,   145,   204,   140,   167,   146,   165,
     147,     6,    -1,    85,   146,   208,   147,   146,   208,   147,
       6,    -1,    85,   146,   208,   147,   146,   208,   147,   146,
     208,   147,   146,   208,   147,     6,    -1,    -1,    86,   170,
     146,   158,   147,     6,    -1,     7,    -1,   119,    -1,   118,
      -1,   117,    -1,   116,    -1,   137,    -1,   136,    -1,     4,
     171,   204,     6,    -1,     4,   141,   204,   142,   171,   204,
       6,    -1,     4,   141,   146,   211,   147,   142,   171,   209,
       6,    -1,     4,   141,   142,     7,   209,     6,    -1,     4,
     141,   142,   119,   209,     6,    -1,     4,   172,     6,    -1,
       4,   141,   204,   142,   172,     6,    -1,     4,     7,   216,
       6,    -1,     4,   143,     4,     7,   216,     6,    -1,     4,
     141,   204,   142,   143,     4,     7,   216,     6,    -1,     4,
     143,     4,   171,   204,     6,    -1,     4,   141,   204,   142,
     143,     4,   171,   204,     6,    -1,     4,   143,     4,   172,
       6,    -1,     4,   141,   204,   142,   143,     4,   172,     6,
      -1,     4,   143,    93,   143,     4,     7,   212,     6,    -1,
       4,   141,   204,   142,   143,    93,   143,     4,     7,   212,
       6,    -1,     4,   143,    94,     7,   213,     6,    -1,     4,
     141,   204,   142,   143,    94,     7,   213,     6,    -1,    64,
     139,     4,   140,   143,     4,     7,   204,     6,    -1,    64,
     139,     4,   140,   143,     4,     7,   216,     6,    -1,   204,
      -1,   216,    -1,    43,   139,   204,   140,     7,   206,     6,
      -1,    60,    43,   139,   174,   140,     7,   209,     6,    -1,
      78,    43,   101,   139,   204,   140,     7,   209,     6,    -1,
     104,   101,   139,   204,   140,     7,   204,     6,    -1,   106,
     101,   139,   204,   140,     7,   204,     6,    -1,   102,   101,
     139,   204,   140,     7,   209,     6,    -1,   109,   101,   139,
     204,   140,     7,     5,     6,    -1,   109,   101,   139,   204,
     140,     7,     5,   209,     6,    -1,   103,   101,   139,   204,
     140,     7,     5,     6,    -1,    52,    53,   101,   209,     6,
      -1,    78,    43,   209,     7,   209,     6,    -1,    78,    46,
     209,     7,   209,     6,    -1,    52,    53,   209,     7,   204,
       6,    -1,    46,   139,   204,   140,     7,   209,     6,    -1,
      50,   139,   204,   140,     7,   209,     6,    -1,    44,   139,
     204,   140,     7,   209,     6,    -1,    44,   139,   204,   140,
       7,   209,    56,   206,     6,    -1,    45,   139,   204,   140,
       7,   209,     6,    -1,    45,   139,   204,   140,     7,   209,
      56,   206,     6,    -1,    54,   139,   204,   140,     7,   146,
     204,   145,   204,   145,     5,   145,     5,   145,     5,   147,
       6,    -1,    88,   139,   204,   140,     7,   209,     6,    -1,
      89,   139,   204,   140,     7,   209,     6,    -1,    90,   139,
     204,   140,     7,   209,    92,   209,    91,   204,     6,    -1,
      46,    71,   139,   204,   140,     7,   209,     6,    -1,    60,
      46,   139,   174,   140,     7,   209,     6,    -1,    56,    49,
     139,   204,   140,     7,   209,     6,    -1,    57,    49,   139,
     204,   140,     7,   209,     6,    -1,    12,    13,     6,    -1,
      13,    49,   204,     6,    -1,    54,    49,   139,   204,   140,
       7,     5,     5,     5,     6,    -1,    47,   139,   204,   140,
       7,   209,     6,    -1,    48,   139,   204,   140,     7,   209,
       6,    -1,    49,    71,   139,   204,   140,     7,   209,     6,
      -1,    60,    49,   139,   174,   140,     7,   209,     6,    -1,
      59,    51,   139,   204,   140,     7,   209,     6,    -1,    51,
     139,   204,   140,     7,   209,     6,    -1,    60,    51,   139,
     174,   140,     7,   209,     6,    -1,    66,   206,   146,   177,
     147,    -1,    65,   146,   206,   145,   206,   145,   204,   147,
     146,   177,   147,    -1,    67,   206,   146,   177,   147,    -1,
      68,   146,   206,   145,   204,   147,   146,   177,   147,    -1,
      70,   146,   177,   147,    -1,    76,    46,   146,   211,   147,
      49,   146,   204,   147,    -1,    77,   146,   177,   147,    -1,
     178,    -1,   176,    -1,    -1,   178,   175,    -1,   178,    43,
     146,   211,   147,     6,    -1,   178,    46,   146,   211,   147,
       6,    -1,   178,    49,   146,   211,   147,     6,    -1,   178,
      51,   146,   211,   147,     6,    -1,    74,   146,   178,   147,
      -1,    74,     4,   141,   204,   142,     6,    -1,    74,     4,
       6,    -1,    74,     4,     4,     6,    -1,    93,   212,   146,
     178,   147,    -1,   110,   215,     6,    -1,   111,   215,     6,
      -1,   110,   146,   178,   147,    -1,   111,   146,   178,   147,
      -1,     4,   216,     6,    -1,     4,     4,   141,   204,   142,
     215,     6,    -1,     4,     4,     4,   141,   204,   142,     6,
      -1,     4,   204,     6,    -1,    64,   139,     4,   140,   143,
       4,     6,    -1,    87,     4,     6,    -1,   100,     6,    -1,
      40,     6,    -1,    40,   146,   204,   145,   204,   145,   204,
     145,   204,   145,   204,   145,   204,   147,     6,    -1,    41,
       6,    -1,    95,   139,   204,     8,   204,   140,    -1,    95,
     139,   204,     8,   204,     8,   204,   140,    -1,    95,     4,
      96,   146,   204,     8,   204,   147,    -1,    95,     4,    96,
     146,   204,     8,   204,     8,   204,   147,    -1,    97,    -1,
     109,     4,    -1,   107,    -1,   108,     4,     6,    -1,    98,
     139,   204,   140,    -1,    99,    -1,    69,   206,   146,   178,
     147,    -1,    69,   146,   206,   145,   206,   145,   204,   147,
     146,   178,   147,    -1,    69,   146,   206,   145,   206,   145,
     206,   145,   204,   147,   146,   178,   147,    -1,    -1,    69,
     206,   146,   178,   185,   199,   147,    -1,    -1,    69,   146,
     206,   145,   206,   145,   204,   147,   146,   178,   186,   199,
     147,    -1,    -1,    69,   146,   206,   145,   206,   145,   206,
     145,   204,   147,   146,   178,   187,   199,   147,    -1,    -1,
      69,   146,   178,   188,   199,   147,    -1,    -1,    69,     4,
     141,   204,   142,   146,   178,   189,   199,   147,    -1,    69,
      43,   146,   204,   145,   206,   147,     6,    -1,    69,    46,
     146,   204,   145,   206,   147,     6,    -1,    69,    49,   146,
     204,   145,   206,   147,     6,    -1,    69,    43,   146,   204,
     145,   206,   145,   206,   145,   204,   147,     6,    -1,    69,
      46,   146,   204,   145,   206,   145,   206,   145,   204,   147,
       6,    -1,    69,    49,   146,   204,   145,   206,   145,   206,
     145,   204,   147,     6,    -1,    69,    43,   146,   204,   145,
     206,   145,   206,   145,   206,   145,   204,   147,     6,    -1,
      69,    46,   146,   204,   145,   206,   145,   206,   145,   206,
     145,   204,   147,     6,    -1,    69,    49,   146,   204,   145,
     206,   145,   206,   145,   206,   145,   204,   147,     6,    -1,
      -1,    69,    43,   146,   204,   145,   206,   147,   190,   146,
     199,   147,     6,    -1,    -1,    69,    46,   146,   204,   145,
     206,   147,   191,   146,   199,   147,     6,    -1,    -1,    69,
      49,   146,   204,   145,   206,   147,   192,   146,   199,   147,
       6,    -1,    -1,    69,    43,   146,   204,   145,   206,   145,
     206,   145,   204,   147,   193,   146,   199,   147,     6,    -1,
      -1,    69,    46,   146,   204,   145,   206,   145,   206,   145,
     204,   147,   194,   146,   199,   147,     6,    -1,    -1,    69,
      49,   146,   204,   145,   206,   145,   206,   145,   204,   147,
     195,   146,   199,   147,     6,    -1,    -1,    69,    43,   146,
     204,   145,   206,   145,   206,   145,   206,   145,   204,   147,
     196,   146,   199,   147,     6,    -1,    -1,    69,    46,   146,
     204,   145,   206,   145,   206,   145,   206,   145,   204,   147,
     197,   146,   199,   147,     6,    -1,    -1,    69,    49,   146,
     204,   145,   206,   145,   206,   145,   206,   145,   204,   147,
     198,   146,   199,   147,     6,    -1,   200,    -1,   199,   200,
      -1,    79,   146,   204,   147,     6,    -1,    79,   146,   209,
     145,   209,   147,     6,    -1,    79,   146,   209,   145,   209,
     145,   209,   147,     6,    -1,    72,     6,    -1,    80,   139,
     204,   140,     7,   209,    61,   204,     6,    -1,    58,    46,
     209,     7,   204,     6,    -1,    58,    46,   209,     7,   204,
      61,    63,   204,     6,    -1,    58,    46,   209,     7,   204,
      61,    62,   204,     6,    -1,    58,    49,   146,   204,   147,
       7,   209,     6,    -1,    58,    49,   146,   204,   147,     7,
     209,     4,     6,    -1,    55,    49,   146,   204,   147,     7,
     209,     6,    -1,    58,    51,   146,   204,   147,     7,   209,
       6,    -1,    72,    49,   209,     7,   204,     6,    -1,    72,
      49,   209,     6,    -1,    73,    49,   209,     7,   204,     6,
      -1,    43,   146,   211,   147,    96,    49,   146,   204,   147,
       6,    -1,    46,   146,   211,   147,    96,    49,   146,   204,
     147,     6,    -1,    46,   146,   211,   147,    96,    51,   146,
     204,   147,     6,    -1,    49,   146,   211,   147,    96,    51,
     146,   204,   147,     6,    -1,    75,     6,    -1,   205,    -1,
     139,   204,   140,    -1,   130,   204,    -1,   129,   204,    -1,
     134,   204,    -1,   204,   130,   204,    -1,   204,   129,   204,
      -1,   204,   131,   204,    -1,   204,   132,   204,    -1,   204,
     133,   204,    -1,   204,   138,   204,    -1,   204,   125,   204,
      -1,   204,   126,   204,    -1,   204,   128,   204,    -1,   204,
     127,   204,    -1,   204,   124,   204,    -1,   204,   123,   204,
      -1,   204,   122,   204,    -1,   204,   121,   204,    -1,   204,
     120,   204,     8,   204,    -1,    14,   139,   204,   140,    -1,
      15,   139,   204,   140,    -1,    16,   139,   204,   140,    -1,
      17,   139,   204,   140,    -1,    18,   139,   204,   140,    -1,
      19,   139,   204,   140,    -1,    20,   139,   204,   140,    -1,
      21,   139,   204,   140,    -1,    22,   139,   204,   140,    -1,
      24,   139,   204,   140,    -1,    25,   139,   204,   145,   204,
     140,    -1,    26,   139,   204,   140,    -1,    27,   139,   204,
     140,    -1,    28,   139,   204,   140,    -1,    29,   139,   204,
     140,    -1,    30,   139,   204,   140,    -1,    31,   139,   204,
     140,    -1,    32,   139,   204,   145,   204,   140,    -1,    33,
     139,   204,   145,   204,   140,    -1,    34,   139,   204,   145,
     204,   140,    -1,    23,   139,   204,   140,    -1,    14,   141,
     204,   142,    -1,    15,   141,   204,   142,    -1,    16,   141,
     204,   142,    -1,    17,   141,   204,   142,    -1,    18,   141,
     204,   142,    -1,    19,   141,   204,   142,    -1,    20,   141,
     204,   142,    -1,    21,   141,   204,   142,    -1,    22,   141,
     204,   142,    -1,    24,   141,   204,   142,    -1,    25,   141,
     204,   145,   204,   142,    -1,    26,   141,   204,   142,    -1,
      27,   141,   204,   142,    -1,    28,   141,   204,   142,    -1,
      29,   141,   204,   142,    -1,    30,   141,   204,   142,    -1,
      31,   141,   204,   142,    -1,    32,   141,   204,   145,   204,
     142,    -1,    33,   141,   204,   145,   204,   142,    -1,    34,
     141,   204,   145,   204,   142,    -1,    23,   141,   204,   142,
      -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,   113,
      -1,   114,    -1,   115,    -1,     4,    -1,     4,   148,   146,
     204,   147,    -1,     4,   141,   204,   142,    -1,   144,     4,
     141,   142,    -1,     4,   172,    -1,     4,   141,   204,   142,
     172,    -1,     4,   143,     4,    -1,     4,   141,   204,   142,
     143,     4,    -1,     4,   143,     4,   172,    -1,     4,   141,
     204,   142,   143,     4,   172,    -1,   112,   139,     5,   145,
     204,   140,    -1,   207,    -1,   130,   206,    -1,   129,   206,
      -1,   206,   130,   206,    -1,   206,   129,   206,    -1,   146,
     204,   145,   204,   145,   204,   145,   204,   145,   204,   147,
      -1,   146,   204,   145,   204,   145,   204,   145,   204,   147,
      -1,   146,   204,   145,   204,   145,   204,   147,    -1,   139,
     204,   145,   204,   145,   204,   140,    -1,   209,    -1,   208,
     145,   209,    -1,   204,    -1,   210,    -1,   146,   147,    -1,
     146,   211,   147,    -1,   130,   146,   211,   147,    -1,   204,
     131,   146,   211,   147,    -1,   130,   210,    -1,   204,   131,
     210,    -1,   204,     8,   204,    -1,   204,     8,   204,     8,
     204,    -1,    43,   146,   204,   147,    -1,   176,    -1,   184,
      -1,     4,   141,   142,    -1,     4,   141,   146,   211,   147,
     142,    -1,   204,    -1,   210,    -1,   211,   145,   204,    -1,
     211,   145,   210,    -1,   146,   204,   145,   204,   145,   204,
     145,   204,   147,    -1,   146,   204,   145,   204,   145,   204,
     147,    -1,     4,    -1,     4,   143,    93,   143,     4,    -1,
     146,   214,   147,    -1,     4,   141,   204,   142,   143,    94,
      -1,   212,    -1,   214,   145,   212,    -1,   216,    -1,     4,
      -1,     5,    -1,    42,    -1,    37,   139,   215,   145,   215,
     140,    -1,    38,   139,   215,   140,    -1,    39,   139,   215,
     140,    -1,    36,   139,   215,   140,    -1,    36,   139,   215,
     145,   211,   140,    -1,    36,   139,     4,   143,     4,   140,
      -1,    36,   139,     4,   141,   204,   142,   143,     4,   140,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   145,   145,   146,   151,   153,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     174,   178,   185,   190,   205,   218,   247,   264,   273,   286,
     289,   290,   291,   292,   293,   297,   299,   304,   306,   312,
     456,   311,   470,   475,   484,   483,   498,   503,   512,   511,
     525,   530,   541,   540,   552,   553,   554,   555,   556,   560,
     561,   568,   599,   638,   692,   709,   727,   738,   755,   762,
     776,   793,   819,   846,   860,   877,   892,   910,   930,   953,
     963,   978,   982,   995,  1017,  1033,  1054,  1061,  1072,  1087,
    1095,  1110,  1117,  1129,  1163,  1199,  1221,  1239,  1257,  1275,
    1301,  1319,  1345,  1365,  1383,  1401,  1427,  1444,  1463,  1481,
    1519,  1525,  1531,  1538,  1562,  1586,  1602,  1622,  1639,  1656,
    1677,  1682,  1687,  1692,  1697,  1708,  1714,  1723,  1724,  1729,
    1732,  1736,  1759,  1782,  1805,  1833,  1842,  1855,  1871,  1886,
    1900,  1906,  1912,  1921,  1935,  1983,  1999,  2015,  2034,  2044,
    2066,  2070,  2075,  2080,  2092,  2109,  2126,  2153,  2180,  2211,
    2219,  2225,  2232,  2236,  2245,  2253,  2261,  2270,  2269,  2282,
    2281,  2294,  2293,  2306,  2305,  2317,  2316,  2332,  2339,  2346,
    2353,  2360,  2367,  2374,  2381,  2388,  2396,  2395,  2407,  2406,
    2418,  2417,  2429,  2428,  2440,  2439,  2451,  2450,  2462,  2461,
    2473,  2472,  2484,  2483,  2498,  2501,  2507,  2516,  2536,  2559,
    2563,  2587,  2605,  2623,  2641,  2670,  2705,  2710,  2737,  2751,
    2764,  2781,  2787,  2793,  2796,  2805,  2815,  2816,  2817,  2818,
    2819,  2820,  2821,  2822,  2823,  2830,  2831,  2832,  2833,  2834,
    2835,  2836,  2837,  2838,  2839,  2840,  2841,  2842,  2843,  2844,
    2845,  2846,  2847,  2848,  2849,  2850,  2851,  2852,  2853,  2854,
    2855,  2856,  2857,  2858,  2859,  2860,  2861,  2863,  2864,  2865,
    2866,  2867,  2868,  2869,  2870,  2871,  2872,  2873,  2874,  2875,
    2876,  2877,  2878,  2879,  2880,  2881,  2882,  2883,  2892,  2893,
    2894,  2895,  2896,  2897,  2898,  2902,  2918,  2933,  2953,  2966,
    2979,  3002,  3020,  3038,  3056,  3074,  3082,  3086,  3090,  3094,
    3098,  3105,  3109,  3113,  3117,  3124,  3129,  3137,  3142,  3146,
    3151,  3155,  3163,  3174,  3182,  3190,  3196,  3207,  3227,  3237,
    3247,  3264,  3291,  3296,  3300,  3304,  3317,  3321,  3333,  3340,
    3361,  3365,  3380,  3385,  3392,  3396,  3403,  3407,  3415,  3423,
    3437,  3451,  3455,  3474,  3496
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
  "tDilate", "tExtrude", "tDuplicata", "tLoop", "tRecombine", "tSmoother",
  "tDelete", "tCoherence", "tIntersect", "tBoundary", "tAttractor",
  "tLayers", "tHole", "tAlias", "tAliasWithOptions", "tText2D", "tText3D",
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
      63,   375,   376,   377,   378,    60,    62,   379,   380,    43,
      45,    42,    47,    37,    33,   381,   382,   383,    94,    40,
      41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   149,   150,   150,   151,   151,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     153,   153,   154,   154,   154,   154,   155,   155,   155,   156,
     156,   156,   156,   156,   156,   157,   157,   158,   158,   160,
     161,   159,   162,   162,   164,   163,   165,   165,   167,   166,
     168,   168,   170,   169,   171,   171,   171,   171,   171,   172,
     172,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   174,   174,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     176,   176,   176,   176,   176,   176,   176,   177,   177,   178,
     178,   178,   178,   178,   178,   179,   179,   179,   179,   180,
     181,   181,   181,   181,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   184,   184,   184,   185,   184,   186,
     184,   187,   184,   188,   184,   189,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   190,   184,   191,   184,
     192,   184,   193,   184,   194,   184,   195,   184,   196,   184,
     197,   184,   198,   184,   199,   199,   200,   200,   200,   200,
     200,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   202,   202,   202,   202,   203,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   206,   206,   206,   206,
     206,   207,   207,   207,   207,   208,   208,   209,   209,   209,
     209,   209,   209,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   211,   211,   211,   211,   212,   212,   212,   212,
     213,   213,   214,   214,   215,   215,   216,   216,   216,   216,
     216,   216,   216,   216,   216
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
       6,    10,    10,    10,    10,     2,     1,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     6,     6,     6,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     4,     2,
       5,     3,     6,     4,     7,     6,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     1,     3,     1,     1,     2,
       3,     4,     5,     2,     3,     3,     5,     4,     1,     1,
       3,     6,     1,     1,     3,     3,     9,     7,     1,     5,
       3,     6,     1,     3,     1,     1,     1,     1,     6,     4,
       4,     4,     6,     6,     9
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
       0,   158,     0,   163,     0,     0,     0,     0,     0,   160,
       0,     0,     0,     0,     5,     7,     6,     8,     9,    10,
      11,    12,    13,    19,    18,    14,    15,    16,    17,   288,
     295,   346,    54,   289,   290,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   347,     0,   292,   293,   294,    58,    57,    56,    55,
       0,     0,     0,    60,    59,     0,     0,     0,     0,     0,
       0,     0,   226,     0,     0,     0,     0,   151,     0,   153,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   306,     0,     0,     0,     0,     0,
       0,   129,     0,   129,     0,     0,     0,   129,   225,     0,
     129,     0,     0,     0,     0,     0,     0,     0,     0,   338,
       0,     0,     0,     0,     0,   150,     0,     0,     0,     0,
       0,   159,     0,   345,   346,   129,     0,   344,   129,     0,
       0,     0,     0,     0,   299,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,   229,   228,   230,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   110,     0,     0,     0,     0,
     295,     0,     0,   328,   329,   332,   333,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   317,     0,   318,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     308,   307,     0,     0,     0,     0,   129,   129,     0,     0,
       0,     0,     0,     0,     0,     0,   173,     0,   129,   128,
       0,   127,     0,     0,     0,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,     0,
       0,   129,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,   140,     0,   141,     0,     0,   301,     0,     0,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   345,     0,     0,     0,     0,     0,     0,
     227,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,    61,     0,   244,   243,   242,   241,   237,   238,   240,
     239,   232,   231,   233,   234,   235,   236,   111,     0,     0,
       0,     0,     0,     0,   228,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    82,     0,
       0,     0,     0,     0,     0,     0,   310,   309,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,     0,     0,   167,   124,   219,     0,     0,   138,
       0,   135,     0,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   162,     0,     0,
       0,     0,     0,   142,   143,     0,   297,   303,     0,    39,
       0,     0,     0,    52,     0,    30,    31,    32,    33,    34,
     246,   267,   247,   268,   248,   269,   249,   270,   250,   271,
     251,   272,   252,   273,   253,   274,   254,   275,   266,   287,
     255,   276,     0,     0,   257,   278,   258,   279,   259,   280,
     260,   281,   261,   282,   262,   283,     0,     0,     0,     0,
       0,     0,     0,     0,   351,     0,     0,   349,   350,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
      73,     0,     0,     0,     0,   298,     0,    22,    20,     0,
       0,     0,     0,   330,     0,     0,   325,   233,   324,   334,
     335,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,   320,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     204,     0,   164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   300,     0,
     296,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     297,    64,    65,     0,     0,     0,     0,     0,    67,    69,
      71,     0,     0,   342,     0,    77,   245,    21,     0,     0,
       0,     0,     0,   327,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   321,     0,
      95,     0,     0,     0,     0,     0,   211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,     0,     0,     0,     0,     0,   209,     0,
       0,   174,   205,     0,     0,   218,   220,   136,     0,     0,
      93,    94,    27,    28,     0,     0,     0,   339,     0,     0,
       0,   154,     0,     0,     0,     0,     0,   146,   302,   145,
       0,     0,     0,     0,   315,     0,   256,   277,   263,   284,
     264,   285,   265,   286,     0,   353,   352,   348,   305,     0,
      54,     0,     0,     0,     0,    62,     0,     0,     0,   340,
      23,    24,     0,     0,    83,     0,   326,     0,    98,     0,
     100,     0,     0,    96,     0,     0,   113,   114,     0,     0,
      97,   118,   322,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,     0,
       0,     0,   129,   175,     0,   186,     0,   188,     0,   190,
       0,     0,     0,     0,   317,     0,     0,     0,     0,   168,
       0,     0,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   304,     0,    35,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,    74,     0,     0,    75,
       0,   343,     0,     0,   331,     0,     0,     0,   106,     0,
       0,   115,     0,     0,     0,   216,   108,   109,     0,     0,
       0,   214,   217,   117,    84,   107,   116,   119,     0,     0,
       0,   314,     0,   313,     0,     0,     0,   177,     0,     0,
     178,     0,     0,   179,     0,   131,   132,   133,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   337,     0,
     156,   155,    88,    91,    86,    87,    89,     0,    40,     0,
       0,     0,   316,     0,     0,     0,     0,    63,    70,    72,
       0,    78,     0,    25,     0,     0,    99,   101,     0,     0,
       0,     0,     0,   213,   212,   215,    79,    80,   129,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   206,     0,
       0,   129,     0,   125,    85,     0,     0,     0,    90,     0,
      36,     0,     0,     0,    38,    53,   354,     0,   341,     0,
     221,   222,   223,   224,   112,     0,     0,     0,   312,   176,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,     0,     0,   336,   157,     0,     0,     0,
       0,    76,     0,     0,   121,     0,   192,     0,     0,   194,
       0,     0,   196,     0,     0,     0,   207,     0,   165,     0,
     129,   105,     0,    44,     0,    50,     0,     0,     0,   311,
     180,     0,     0,   187,   181,     0,     0,   189,   182,     0,
       0,   191,     0,     0,     0,   171,     0,     0,     0,     0,
       0,     0,     0,   198,     0,   200,     0,   202,   208,   210,
     170,   166,     0,    41,     0,    48,     0,     0,     0,     0,
     183,     0,     0,   184,     0,     0,   185,     0,     0,     0,
      42,     0,     0,   152,     0,     0,     0,     0,     0,     0,
       0,   172,     0,     0,     0,     0,     0,   193,     0,   195,
       0,   197,     0,    43,    45,     0,    46,     0,   102,     0,
       0,     0,     0,     0,    51,   199,   201,   203,    47,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    64,   669,    65,    66,   409,   984,   990,
     595,   761,  1119,  1239,   596,  1207,  1265,   597,  1241,   598,
     599,   765,   129,   224,    67,   526,   551,   313,   370,   371,
      70,    71,    72,    73,    74,   314,   733,  1179,  1222,   552,
    1035,  1038,  1041,  1044,  1191,  1195,  1199,  1231,  1234,  1237,
     729,   730,    76,    77,    78,   332,   132,   350,   174,   883,
     884,   334,   317,   201,   664,   794,   216,   217
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1068
static const yytype_int16 yypact[] =
{
    3203,    70,   109,  3282, -1068, -1068,  2341,   126,    95,    16,
      26,   180,   -94,   127,   137,   -45,   166,   169,   -46,   173,
     179,   161,   -12,   274,   286,   304,   336,   310,   638,   209,
     240,   -57,   -57,   258,    31,   264,   334,   362,    13,   410,
     371,   288,    -3,   416,   439,   449,   324,   329,   333,    18,
      14, -1068,   350, -1068,   469,   385,   394,   395,   400, -1068,
     498,    17,    11,    25, -1068, -1068, -1068, -1068, -1068, -1068,
   -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068,
      15,   360,   560, -1068, -1068, -1068,   -53,   165,   231,   282,
     299,   342,   379,   383,   489,   502,   533,   553,   556,   562,
     571,   574,   592,   620,   621,   647,   651,   386,   389,   392,
     397, -1068,   412, -1068, -1068, -1068, -1068, -1068, -1068, -1068,
    2615,  2615,  2615, -1068, -1068,  2615,  2128,    20,   554,  2615,
     563,   962, -1068,   567,   579,  2615,   587, -1068,  2615, -1068,
    2615,  2483,  2615,  2615,   461,  2615,  2483,  2615,  2615,   464,
    2483,  2615,  2615,  1360,   486,  2615,   496,   511,   515,  1783,
     516,   517,   529,   534,   543,   546,   557,   635,   -57,   -57,
     -57,  2615,  2615,   -71, -1068,   -18,   -57,   558,   561,   575,
     591,  2272,    51,   759,  1783,  1783,     8, -1068, -1068,   606,
     759,  1506,  1783,   573,   622,   774,  2615,  2615,  2615,   640,
    2615,   652,   697,  2615,  2615, -1068,   655,   676,   695,   703,
     816, -1068,   707, -1068, -1068, -1068,   841, -1068, -1068,   844,
     731,  2615,   858,   739, -1068, -1068,   861,  2615,  2615,  2615,
    2615,  2615,  2615,  2615,  2615,  2615,  2615,  2615,  2615,  2615,
    2615,  2615,  2615,  2615,  2615,  2615,  2615,  2615,  2615,  2615,
    2615,  2615,  2615,  2615,  2615,  2615,  2615,  2615,  2615,  2615,
    2615,  2615,  2615,  2615,  2615,  2615,  2615,  2615,  2615,   577,
     641,   641,   641,   873,   568,   756,   756,   756,  5459,     3,
    2483,  2738,   361,   754,   891,   763,  1284, -1068, -1068,  2615,
    2615,  2615,  2615,  2615,  2615,  2615,  2615,  2615,  2615,  2615,
    2615,  2615,  2615,  2615, -1068, -1068,  1432,   -89,  4015,  5480,
     648,   770,  2483, -1068, -1068,  1708, -1068,   132,  5501,  5522,
    2615,  5543,   632,  5564,  5585,  2615,   669,  5606,  5627,  1783,
    1921,  1218,  1846,   907, -1068,  2615,  5648,  2615,  2615,  2615,
     910,  2615,  2615,  2615,  2552,  2552,  2552,  2552,   778,   -22,
   -1068, -1068,  4041,  4067,   -57,   -57,   759,   759,   138,  2615,
    2615,  2615,  2615,  2272,  2272,  2615,  3353,   221, -1068, -1068,
     775,  3353,   194,   914,   917, -1068,  2615,   972,  2483,   779,
     786,   920,   921,  2615,  2615, -1068,  5669,  5690,  5711,   838,
    4093, -1068,   789,  1984,  5732,  2615,  2615,  2615,  2615, -1068,
    2615,  2658, -1068,  2725, -1068,  2615,  4769,    84,  2615,     7,
   -1068,  5753,  4792,  5774,  4815,  5795,  4838,  5816,  4861,  5837,
    4884,  5858,  4907,  5879,  4930,  5900,  4953,  5921,  4976,  5942,
    4999,  5963,  5022,  4119,  4145,  5984,  5045,  6005,  5068,  6026,
    5091,  6047,  5114,  6068,  5137,  6089,  5160,  4171,  4197,  4223,
    4249,  4275,  4301,   678,   -35,   787,   796,   798,   794,  2615,
   -1068,  1783,  1783,   683,   314,   560,  2615,   934,   937,    19,
     800, -1068,  3029,   913,   643,   597,   597,   140,   140,   140,
     140,   -34,   -34,   756,   756,   756,   756, -1068,    36,  2483,
    2615,   938,  2197,  2615,   756, -1068,  2615,  2483,  2483,   848,
     939,   941,  6110,   942,   854,   944,   945,  6131,   860,   947,
     950,   953,  2483, -1068,   692,  2059,  2615,  6152,   954,  3098,
    6173,  6194,  2615,  3297,  3399,  6215,   820,  2989, -1068,   822,
     823,   824,   826,   -57,  2615,  2615, -1068, -1068,   819,   825,
    2615,  5183,  4327,  4353,  4379,  1183,   -68,   -44,   -43,   164,
     866, -1068,   482,   -57,  2795, -1068, -1068,  2615,  2615, -1068,
    5206, -1068,   693, -1068,  2615,  1783,  1783,  5229,  5252,   963,
     964,   966,   831,  2615,  2862,  2615,  2615, -1068,  6236,  6257,
    6278,  6299,  6320, -1068, -1068,  5275,   376, -1068,  3427, -1068,
     836,   837,   832, -1068,   971, -1068, -1068, -1068, -1068, -1068,
   -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068,
   -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068,
   -1068, -1068,  2615,  2615, -1068, -1068, -1068, -1068, -1068, -1068,
   -1068, -1068, -1068, -1068, -1068, -1068,  2615,  2615,  2615,  2615,
    2615,  2615,  2615,   975, -1068,  2483,   641, -1068, -1068,  2615,
    5298,   974,   977,   845, -1068,    32,  2615,   980,   983,  1464,
   -1068,   984,   852,    18,   988, -1068,  2615, -1068,   869,   641,
     -11,  4405,   -57, -1068,  2483,  3455,  3049,   756, -1068,  1708,
   -1068,   948,  1783,  1783,   989,  1783,   792,  1783,  1783,   992,
     949,  1783,  1783, -1068,   706, -1068,  2483,  1571,   994,   856,
     996,   997,   998,  1142,  1000,  1001,  1003,  1004,  1005,  1006,
    1007,  1021,   279,  4431,  4457, -1068, -1068,  3483,   884,   -57,
     -57,   -57,  2483,  2483,  2483,  2483,  1041,   903,   916,   -41,
   -1068,   326, -1068,   482,  1603,  1623,  1047,  1008,  6341,  1050,
    1052,  1053,  1057,  1783,  1783,  1783,  1061,  4483, -1068,  3068,
     680,  1059,  1060,  1063,  1064,  1065,  1062,  1069, -1068,  1071,
   -1068,   940,  2615,  2615,  1783,   952, -1068,  6362,  5321,  6383,
    5344,  6404,  5367,  6425,  5390,  5413,   956,   182,   965,  6446,
      75, -1068, -1068,   183,   458,   959,  1073,  1756, -1068, -1068,
   -1068,    18,  2615, -1068,   709, -1068,  2989, -1068,  1097,    48,
    2615,     2,   710, -1068,  2615,   960,    28,    40,  1783,  1101,
     967,   968,  1102,  1103,  1783,   969,  1105,  1106, -1068,   713,
   -1068,  1113,  2615,  1783,  1783,  1783, -1068,   302,  1783,  1783,
    1783,  1783,  1783,  1783,  1783,   390,  2615,  2615,  2615,   976,
   -1068,   -60,    58,   184,   714,   721,   726,   732, -1068,  1783,
    2615, -1068, -1068,  2272,   202, -1068, -1068, -1068,   979,  1114,
   -1068, -1068, -1068, -1068,  1117,  1120,  1028, -1068,  2615,  2615,
    2615, -1068,  1783,  1122,  2615,  2615,  1123, -1068,    84, -1068,
    2615,  4509,  4535,   736, -1068,  2615, -1068, -1068, -1068, -1068,
   -1068, -1068, -1068, -1068,   986, -1068, -1068, -1068, -1068,  1783,
     560,  2615,  1124,  1127,    19, -1068,  1128,  5436,    18, -1068,
   -1068, -1068,   641,  4561, -1068,   991,  2989,  2615, -1068,   -57,
   -1068,   -57,  1129, -1068,  2615,  2615, -1068, -1068,  1131,  2615,
   -1068, -1068, -1068,  1134,  4587,  1135,  1136,  1137,  2615,  2615,
     878,  1138,  1139,  1140,  1141,  1143,  1148, -1068,  2552,  3511,
    6467,  2530,   759,  3353,   -57,  1151,   -57,  1152,   -57,  1157,
    1158,  1160,  1161,  1163,   417,  1025,  6488,  3539,   337, -1068,
    2615,  1783, -1068, -1068,  1783,  3343,   618,  6509,  1165,  1167,
    1884,  2301,  1645, -1068,   207,  2989,  2615,  2615,  1783,  1029,
     741,  2989,  1170,  1171,  1172,  2407, -1068,  1169,  1174, -1068,
    1038, -1068,  1177,  2615, -1068,  3567,    49,    54, -1068,  3595,
    3623, -1068,  3651,  1179,  2615, -1068, -1068, -1068,  2666,  2803,
    1180, -1068, -1068, -1068, -1068, -1068, -1068, -1068,  2875,  1181,
    1039, -1068,  2615, -1068,  1043,   482,   370, -1068,  1042,   475,
   -1068,  1046,   479, -1068,  1048, -1068, -1068, -1068, -1068,  1187,
    1783,  1188,  1051,  2615,  3679,  1190,  1107,  2615, -1068,  2615,
   -1068, -1068, -1068, -1068, -1068, -1068, -1068,  1193, -1068,  2615,
    4613,  4639, -1068,  1783,  2615,  1194,  1066, -1068, -1068, -1068,
      18, -1068,  1108, -1068,  4665,  1195, -1068, -1068,  1198,  1199,
    1201,  1202,  4691, -1068, -1068, -1068, -1068, -1068,   759,  3371,
   -1068,   237,  2272,   482,  2272,   482,  2272,   482, -1068,   744,
    1783, -1068,  3707, -1068, -1068,  2615,  3735,  3763, -1068,  1068,
    2989,  2615,  2615,   745,  2989, -1068, -1068,  1204, -1068,  2615,
   -1068, -1068, -1068, -1068, -1068,  1210,  1070,  2615, -1068, -1068,
    3791,   493,   295,  3819,   519,   297,  3847,   541,   322,  1783,
    1212,  1155,  2932,  1074,  2940, -1068, -1068,  2615,  6530,  4717,
      27, -1068,  4743,  1078, -1068,  3875,  1213,  2615,  1219,  1220,
    2615,  1224,  1225,  2615,  1247,  1077, -1068,  2615, -1068,   482,
   -1068, -1068,   748, -1068,  2615, -1068,  1783,  2615,  1249, -1068,
   -1068,  1109,  3903, -1068, -1068,  1110,  3931, -1068, -1068,  1111,
    3959, -1068,  1252,  3009,   327,  2999,  1253,  1132,  6551,   760,
    3987,  1115,   482,  1271,   482,  1273,   482,  1275, -1068, -1068,
   -1068, -1068,   482, -1068,   641, -1068,  1173,  1283,  1313,   347,
   -1068,  1176,   356, -1068,  1178,   367, -1068,  1189,   369,   761,
   -1068,  1191,  1783, -1068,  1182,  1314,   482,  1319,   482,  1320,
     482, -1068,   641,  1321,   641,   764,  1328, -1068,   380, -1068,
     454, -1068,   500, -1068, -1068,   768, -1068,  1330, -1068,  1332,
    1333,  1335,   641,  1336, -1068, -1068, -1068, -1068, -1068, -1068
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1068, -1068, -1068, -1068,   544, -1068, -1068, -1068, -1068,   187,
   -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068,
   -1068, -1068,  -279,    -2, -1068,   265,  1342,     6,  -188,  -174,
   -1068, -1068, -1068, -1068, -1068,  1343, -1068, -1068, -1068, -1068,
   -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068,
    -514,  -672, -1068, -1068, -1068,    -5, -1068,    34, -1068, -1067,
     468,   178,   -67,  -643,   445, -1068,   -63,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     219,   131,   379,   466,   130,   133,  1123,   366,   914,    69,
     461,   589,   374,   377,   375,   213,   214,   186,   202,   220,
     793,   211,   199,   662,   282,   149,   144,   144,   149,   213,
     214,   726,   137,  1185,   918,   177,   784,   154,   727,   728,
     191,   401,   667,   192,   403,   140,   920,   107,   108,   109,
     110,   488,   141,   111,   911,  1086,   489,   852,   354,   355,
    1087,   107,   108,   109,   110,   173,   175,   111,   182,   354,
     355,   140,   169,   170,   178,   356,     4,   179,   722,   322,
     180,   226,   171,   326,   919,   954,   227,   955,   228,   172,
     590,   591,   592,   593,   145,   145,   921,   300,   301,   302,
     150,   146,   723,   724,   303,   644,   851,   354,   355,     5,
     645,   354,   355,   283,   284,   275,   276,   277,   212,  1209,
     278,   281,   462,   533,   286,   785,   786,   155,   357,   799,
     306,   354,   355,   308,   498,   309,   315,   318,   319,   134,
     321,   315,   323,   324,   135,   315,   327,   328,   906,   376,
     336,   123,   124,   203,   594,   136,   221,   215,   222,   187,
     169,   170,   668,   223,   200,   663,   352,   353,   538,   539,
     171,   218,   138,  1186,   668,  1255,   353,   181,   354,   355,
     354,   355,   852,   354,   355,   656,   139,   354,   355,   369,
     654,   386,   387,   388,   554,   390,   369,   368,   393,   394,
     556,   557,   349,   956,   351,   957,   454,   455,   456,   457,
     358,   123,   124,   463,   153,   367,   406,   574,   757,   854,
     123,   124,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   514,  1001,   142,   354,   355,   298,
     299,   300,   301,   302,   726,   315,   143,   498,   303,   499,
     467,   727,   728,   540,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   116,
     117,   118,   119,   152,   229,   147,   230,   494,   148,   726,
     725,   562,   151,   354,   355,   502,   727,   728,   152,   316,
     507,   654,   896,   156,   316,   494,   315,   498,   316,   958,
     517,   959,   519,   520,   521,   157,   523,   524,   525,   527,
     527,   527,   527,   528,   528,   528,   528,  1068,   167,   969,
     354,   355,  1069,   158,   541,   542,   543,   544,   275,   276,
     545,   162,   369,   369,   938,   939,   553,   726,   465,   726,
     231,   560,   232,   315,   727,   728,   727,   728,   567,   568,
     213,   214,   159,   184,  1139,   160,   168,   161,   536,   537,
     578,   579,   580,   581,   726,   582,   947,   948,   351,   726,
     585,   727,   728,   588,   176,   587,   727,   728,   354,   355,
     183,   185,   107,   108,   109,   110,   188,   189,   111,   726,
     193,   233,   670,   234,   836,   496,   727,   728,   726,   852,
     116,   117,   118,   119,   190,   727,   728,  1127,   235,   726,
     236,   726,  1168,   194,  1171,   694,   727,   728,   727,   728,
     123,   124,   726,   195,   650,   354,   355,   655,   316,   727,
     728,   659,   657,   196,   658,   900,   354,   355,   197,  1174,
     852,   853,   198,   852,  1220,   205,   852,   116,   117,   118,
     119,   237,  1053,   238,   315,   671,   206,   650,   675,   204,
     495,   676,   677,   679,  1245,   207,   208,   123,   124,   354,
     355,   209,   210,  1247,   899,   901,   225,   315,   495,   316,
     677,   697,   123,   124,  1249,  1102,  1251,   703,   239,   757,
     240,  1101,   241,   759,   242,   269,   726,  1269,   270,   713,
     714,   271,   852,   727,   728,   717,   272,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   515,   301,
     302,   273,   734,   735,   726,   303,   316,   852,   285,   738,
     852,   727,   728,   852,  1049,   214,   852,   712,   747,   287,
     749,   750,   726,   304,   116,   117,   118,   119,   777,   727,
     728,   453,   214,   778,   758,   305,   852,   731,   852,  1142,
     852,  1145,   307,  1148,   123,   124,   107,   108,   109,   110,
     320,  1270,   111,   325,   354,   355,   798,   802,   354,   355,
     529,   530,   531,   107,   108,   109,   110,   767,   768,   111,
    1104,   333,   354,   355,  1106,   335,  1059,   340,   243,   819,
     244,   769,   770,   771,   772,   773,   774,   775,  1167,   348,
     315,   245,   337,   246,   779,   213,   214,  1271,   354,   355,
     338,   787,   372,   373,   339,   844,   845,   846,   847,   381,
     382,   796,   341,   342,  1170,  1204,   953,   316,   343,   315,
     354,   355,   247,   344,   248,   678,   680,   107,   108,   109,
     110,   163,   345,   111,   164,   346,  1173,   165,   870,   166,
     316,   315,   249,   678,   250,   251,   347,   252,  1229,   359,
    1232,   253,  1235,   254,   123,   124,   801,   360,  1238,   459,
     255,   222,   256,   257,   383,   258,   223,   315,   315,   315,
     315,   361,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   259,  1258,   260,  1260,   303,  1262,   362,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   378,   841,   842,   843,   303,   881,   882,   261,
     263,   262,   264,   384,  1034,  1060,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   498,   758,   504,
     385,   303,   902,   389,   123,   124,   265,   907,   266,   492,
     267,   222,   268,   392,   395,   913,   223,   511,   391,   916,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   498,   396,   508,   934,   303,   642,
     871,   643,   399,   316,    30,    31,    32,    33,   498,    35,
     653,   949,   950,   951,   397,    40,    41,   498,   498,   695,
     737,   810,   398,   811,   964,   966,   400,   402,   967,  1002,
     404,   498,   316,   818,   908,   498,   909,   915,   498,   498,
     932,   960,   407,   975,   976,   977,   498,   410,   961,   980,
     981,   498,   405,   962,   316,   985,   983,   498,   458,   963,
     991,   988,  1020,   989,  1021,   408,  1074,   968,  1075,  1149,
     988,  1150,  1160,  1074,   303,  1206,   995,   468,   469,   994,
     316,   316,   316,   316,   470,   988,  1252,  1226,  1253,   988,
    1136,  1267,  1005,  1272,   516,  1273,   493,   522,   532,  1009,
    1010,   558,   555,   559,  1012,   564,   563,   565,   566,   651,
     652,   572,   646,  1018,  1019,   575,   647,  1152,   648,   649,
     660,   661,   665,  1028,   681,   672,   682,  1029,   683,   685,
     686,   687,   688,  1006,   691,  1007,   690,   692,   369,   693,
     707,   699,   708,   709,   710,  1054,   715,   212,   288,   711,
     743,   744,   716,   745,   746,   762,   763,   766,   764,   776,
     781,  1070,  1071,   782,     7,     8,   788,   783,  1036,   789,
    1039,   791,  1042,   792,   795,   797,   808,   805,  1084,   814,
     815,   821,   822,   823,   824,   825,  1205,   828,   829,  1092,
     830,   831,   832,   833,   834,   546,    13,    14,   547,    16,
      17,   548,    19,   549,    21,   835,    22,  1099,    24,    25,
     840,    27,    28,   739,   740,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   848,  1112,   849,
      42,   303,  1116,   857,  1117,   850,   860,   858,   861,   862,
      46,    47,    48,   863,  1120,   867,   872,   873,   877,  1124,
     874,   875,   876,   878,    55,    56,    57,   879,    58,   880,
     904,   550,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   895,  1140,   885,  1143,
     303,  1146,   903,   910,   369,   897,   917,   923,   926,   927,
    1154,   930,   931,   924,   925,   929,  1158,  1159,   933,   561,
     974,   971,   952,   972,  1162,   970,   973,   979,   982,   992,
     996,   997,  1165,  1004,   999,  1008,  1141,  1011,  1144,  1013,
    1147,  1015,  1016,  1017,  1022,  1023,  1024,  1025,   826,  1026,
     806,   807,   991,   809,  1027,   812,   813,  1037,  1040,   816,
     817,  1240,  1192,  1043,  1045,  1196,  1046,  1047,  1200,  1048,
    1050,  1062,  1203,  1063,  1076,  1073,  1080,  1077,  1078,  1208,
    1081,  1082,  1210,  1083,  1091,  1098,  1095,  1097,  1103,  1263,
    1100,  1266,  1105,  1108,  1107,  1110,  1114,  1111,  1115,  1118,
    1125,  1130,  1128,   827,  1131,  1132,  1126,  1133,  1134,  1278,
    1161,   864,   865,   866,  1157,  1163,  1177,  1164,  1176,  1190,
    1180,    79,   310,  1188,  1202,  1193,  1194,    83,    84,    85,
    1197,  1198,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,  1201,  1211,  1212,  1214,  1216,  1218,  1223,
    1228,   311,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   922,  1230,  1224,  1233,
     303,  1236,   928,    30,    31,    32,    33,    34,    35,  1243,
     471,   935,   936,   937,    40,    41,   940,   941,   942,   943,
     944,   945,   946,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   965,  1244,  1242,
    1257,   303,  1246,   460,  1248,  1259,  1261,  1264,   534,  1256,
     112,   113,   114,   115,  1268,  1250,  1274,  1254,  1275,  1276,
     978,  1277,  1279,   912,  1182,    68,    75,   120,   312,   998,
       0,     0,   122,     0,     0,     0,     0,   125,     0,     0,
       0,     0,   128,    79,   310,   513,     0,   993,     0,    83,
      84,    85,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,     0,   311,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,     0,     0,
       0,     0,   303,     0,     0,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,    40,    41,   487,  1055,
       0,     0,  1056,     0,     0,     0,     0,     0,     0,     0,
    1067,     0,     0,     0,     0,     0,  1072,     0,     0,     0,
       0,   329,     0,     0,     0,     0,     0,     0,     0,     0,
     790,     0,   112,   113,   114,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
     330,     0,     0,     0,   122,     0,     0,     0,     0,   125,
       0,     0,     0,     0,   128,     0,   331,     0,     0,    79,
     310,     0,     0,     0,     0,    83,    84,    85,  1109,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,   311,
       0,     0,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,     0,     0,     0,     0,
     303,    30,    31,    32,    33,    34,    35,   820,  1151,     0,
       0,     0,    40,    41,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,     0,     0,
       0,     0,   303,     0,     0,     0,     0,   380,     0,   855,
       0,     0,     0,     0,     0,     0,     0,  1175,   112,   113,
     114,   115,     0,     0,     0,     0,     0,     0,     0,   856,
       0,     0,     0,     0,     0,   120,   330,     0,     0,     0,
     122,     0,     0,     0,     0,   125,     0,     0,    79,   310,
     128,  1066,   331,     0,    83,    84,    85,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,     0,     0,     0,     0,     0,   311,     0,
       0,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
      30,    31,    32,    33,    34,    35,   496,     0,     0,     0,
       0,    40,    41,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   112,   113,   114,
     115,   303,   905,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,   330,     0,     0,     0,   122,
       0,     0,     0,     0,   125,     0,    79,   310,     0,   128,
       0,   331,    83,    84,    85,     0,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,   311,     0,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   497,
     301,   302,     0,     0,     0,     0,   303,     0,    30,    31,
      32,    33,    34,    35,   496,     0,     0,     0,     0,    40,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
    1064,     0,     0,     0,   303,   112,   113,   114,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   120,   330,     0,     0,     0,   122,     0,     0,
       0,     0,   125,     0,    79,   310,     0,   128,     0,   331,
      83,    84,    85,     0,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,   311,     0,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   515,   301,   302,
       0,     0,     0,     0,   303,     0,    30,    31,    32,    33,
      34,    35,   576,     0,     0,     0,     0,    40,    41,     0,
       0,     0,     0,     0,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,     0,     0,
       0,     0,   303,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,   113,   114,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   312,     0,     0,     0,   122,     0,     0,     0,     0,
     125,     0,    79,   310,     0,   128,     0,   512,    83,    84,
      85,     0,     0,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,   311,     0,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,     0,     0,
       0,     0,   303,     0,    30,    31,    32,    33,    34,    35,
       0,    79,   274,     0,     0,    40,    41,    83,    84,    85,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,     0,     0,     0,     0,
       0,   112,   113,   114,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   120,   312,
       0,     0,     0,   122,     0,     0,     0,     0,   125,     0,
      79,   274,     0,   128,     0,   696,    83,    84,    85,     0,
       0,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   113,   114,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,   121,     0,
       0,     0,   122,     0,     0,     0,     0,   125,     0,     0,
     279,     0,   128,     0,   280,    79,   274,     0,     0,     0,
       0,    83,    84,    85,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,  1065,     0,   112,
     113,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,   121,     0,     0,
       0,   122,     0,     0,     0,     0,   125,     0,     0,   673,
       0,   128,     0,   674,    79,    80,    81,     0,    82,     0,
      83,    84,    85,     0,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,   107,   108,   109,
     110,     0,     0,   111,   112,   113,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   363,   364,     0,     0,     0,   122,     0,     0,     0,
       0,   365,     0,  1079,     0,     0,   128,     0,   172,     0,
       0,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   121,     0,     0,     0,   122,     0,   123,   124,     0,
     125,     0,   126,     0,   127,   128,    79,   310,     0,     0,
       0,     0,    83,    84,    85,     0,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,   311,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,    30,    31,
      32,    33,    34,    35,     0,    79,   274,   214,     0,    40,
      41,    83,    84,    85,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,   107,   108,
     109,   110,     0,     0,   111,   112,   113,   114,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   120,   312,     0,     0,     0,   122,    79,   274,
       0,     0,   125,     0,    83,    84,    85,   128,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   112,   113,   114,   115,   303,     0,
       7,     8,  1093,     0,     0,  1032,     0,  1033,     0,     0,
       0,   120,   121,     0,     0,     0,   122,     0,     0,     0,
       0,   125,     0,     0,     0,     0,   128,     0,     0,     0,
       0,   546,    13,    14,   547,    16,    17,   548,    19,   549,
      21,     0,    22,     0,    24,    25,     0,    27,    28,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   114,
     115,     0,     0,     0,     0,     0,    42,     7,     8,     0,
       0,     0,     0,     0,   120,   121,    46,    47,    48,   122,
       0,     0,     0,     0,   125,     0,     0,     0,     0,   128,
      55,    56,    57,     0,    58,     0,     0,   550,   546,    13,
      14,   547,    16,    17,   548,    19,   549,    21,     0,    22,
       0,    24,    25,     0,    27,    28,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
       0,     0,     0,    42,   303,   583,     0,     7,     8,  1094,
       0,     0,     0,    46,    47,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,    57,
       0,    58,     0,     0,   550,     0,     0,     0,   546,    13,
      14,   547,    16,    17,   548,    19,   549,    21,     0,    22,
       0,    24,    25,     0,    27,    28,     0,     0,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   584,    42,     7,     8,   303,     0,     0,     0,
     464,  1096,     0,    46,    47,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,    57,
       0,    58,     0,     0,   550,   546,    13,    14,   547,    16,
      17,   548,    19,   549,    21,     0,    22,     0,    24,    25,
       0,    27,    28,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
      42,   303,   732,     0,     7,     8,  1181,     0,     0,     0,
      46,    47,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    56,    57,     0,    58,     0,
       0,   550,     0,     0,     0,   546,    13,    14,   547,    16,
      17,   548,    19,   549,    21,     0,    22,     0,    24,    25,
       0,    27,    28,     0,     0,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   748,
      42,     7,     8,   303,     0,  1219,     0,     0,     0,     0,
      46,    47,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    56,    57,   666,    58,     0,
       0,   550,   546,    13,    14,   547,    16,    17,   548,    19,
     549,    21,     0,    22,     0,    24,    25,   804,    27,    28,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,     0,     0,   869,    42,   303,  1178,
       0,     0,     0,     0,     0,     0,     0,    46,    47,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,    57,     0,    58,     0,     0,   550,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,  1221,   303,     0,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,     0,    -4,     1,     0,   303,    -4,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,     0,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,     0,     0,     0,     0,   303,     0,    -4,     0,
       0,     0,     0,    -4,    -4,   700,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,    -4,    -4,     6,     0,     0,     0,
      -4,    -4,    -4,    -4,     7,     8,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     9,     0,     0,
       0,     0,    10,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,    34,    35,     0,    36,    37,    38,    39,    40,    41,
      42,     0,     0,    43,    44,     7,     8,     0,     0,    45,
      46,    47,    48,     0,     0,    49,     0,    50,     0,    51,
      52,    53,    54,     0,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,     0,     0,   546,    13,    14,   547,
      16,    17,   548,    19,   549,    21,     0,    22,     0,    24,
      25,     0,    27,    28,     0,     0,     0,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    42,     0,     0,     0,   303,     0,     0,     0,     0,
       0,    46,    47,    48,   704,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,    57,     0,    58,
       0,     0,   550,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,     0,     0,     0,     0,     0,  1057,     0,
    1058,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,  1137,     0,  1138,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,     0,     0,   705,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,     0,     0,     0,   760,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
       0,     0,   803,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,     0,     0,     0,     0,     0,     0,     0,
     839,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,     0,     0,  1030,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,     0,     0,  1052,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,     0,     0,     0,  1085,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
       0,     0,  1088,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,     0,     0,     0,     0,     0,     0,     0,
    1089,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,     0,     0,  1090,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,     0,     0,  1113,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,     0,     0,     0,  1153,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
       0,     0,  1155,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,     0,     0,     0,     0,     0,     0,     0,
    1156,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,     0,     0,  1166,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,     0,     0,  1169,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,     0,     0,     0,  1172,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
       0,     0,  1189,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,     0,     0,     0,     0,     0,     0,     0,
    1213,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,     0,     0,  1215,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,     0,     0,  1217,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,     0,     0,     0,  1227,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
     490,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,   534,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,     0,   535,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,     0,     0,     0,     0,     0,   573,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,   622,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
     623,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,   636,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,     0,   637,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,     0,     0,     0,     0,     0,   638,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,   639,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
     640,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,   641,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,     0,   719,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,     0,     0,     0,     0,     0,   720,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,   721,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
     800,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,   837,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,     0,   838,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,     0,     0,     0,     0,     0,   868,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,   986,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
     987,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,  1003,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,     0,  1014,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,     0,     0,     0,     0,     0,  1121,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,  1122,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
    1129,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,  1135,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,     0,  1184,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,     0,     0,     0,     0,     0,  1187,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,     0,
       0,   586,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,     0,     0,     0,     0,
     303,     0,     0,     0,   601,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,     0,     0,   603,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,     0,     0,     0,     0,   303,     0,     0,     0,
     605,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,   607,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,     0,     0,
       0,     0,   303,     0,     0,     0,   609,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,     0,   611,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,     0,     0,     0,     0,   303,     0,
       0,     0,   613,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,     0,     0,   615,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
       0,     0,     0,     0,   303,     0,     0,     0,   617,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,     0,
       0,   619,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,     0,     0,     0,     0,
     303,     0,     0,     0,   621,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,     0,     0,   625,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,     0,     0,     0,     0,   303,     0,     0,     0,
     627,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,   629,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,     0,     0,
       0,     0,   303,     0,     0,     0,   631,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,     0,   633,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,     0,     0,     0,     0,   303,     0,
       0,     0,   635,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,     0,     0,   718,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
       0,     0,     0,     0,   303,     0,     0,     0,   736,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,     0,
       0,   741,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,     0,     0,     0,     0,
     303,     0,     0,     0,   742,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,     0,     0,   756,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,     0,     0,     0,     0,   303,     0,     0,     0,
     780,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,     0,     0,   887,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,     0,     0,
       0,     0,   303,     0,     0,     0,   889,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,     0,     0,   891,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,     0,     0,     0,     0,   303,     0,
       0,     0,   893,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,     0,     0,   894,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
       0,     0,     0,     0,   303,     0,     0,     0,  1000,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,   460,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,     0,     0,     0,     0,   303,     0,
     491,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,   500,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,     0,     0,     0,     0,
     303,     0,   501,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,   503,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,     0,     0,
       0,     0,   303,     0,   505,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,   506,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
       0,     0,     0,     0,   303,     0,   509,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,   510,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,     0,     0,     0,     0,   303,     0,   518,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,   569,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,     0,     0,     0,     0,   303,     0,
     570,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,   571,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,     0,     0,     0,     0,
     303,     0,   577,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,   600,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,     0,     0,
       0,     0,   303,     0,   602,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,   604,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
       0,     0,     0,     0,   303,     0,   606,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,   608,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,     0,     0,     0,     0,   303,     0,   610,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,   612,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,     0,     0,     0,     0,   303,     0,
     614,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,   616,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,     0,     0,     0,     0,
     303,     0,   618,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,   620,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,     0,     0,
       0,     0,   303,     0,   624,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,   626,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
       0,     0,     0,     0,   303,     0,   628,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,   630,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,     0,     0,     0,     0,   303,     0,   632,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,   634,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,     0,     0,     0,     0,   303,     0,
     684,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,   689,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,     0,     0,     0,     0,
     303,     0,   698,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,   701,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,     0,     0,
       0,     0,   303,     0,   702,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,   706,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
       0,     0,     0,     0,   303,     0,   751,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,   752,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,     0,     0,     0,     0,   303,     0,   753,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,   754,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,     0,     0,     0,     0,   303,     0,
     755,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,   859,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,     0,     0,     0,     0,
     303,     0,   886,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,   303,     0,   888,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,     0,     0,
       0,     0,   303,     0,   890,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,     0,     0,   303,     0,   892,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
       0,     0,     0,     0,   303,     0,   898,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,     0,     0,     0,     0,   303,     0,  1031,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,     0,     0,     0,     0,   303,     0,  1051,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,     0,     0,     0,     0,   303,     0,  1061,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,     0,     0,     0,     0,   303,     0,
    1183,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,     0,     0,   303,
       0,  1225
};

static const yytype_int16 yycheck[] =
{
      63,     6,   190,   282,     6,     6,  1073,   181,     6,     3,
       7,     4,     4,   187,     6,     4,     5,     4,     4,     4,
     663,     4,     4,     4,     4,    71,    71,    71,    71,     4,
       5,    72,     6,     6,     6,     4,     4,    49,    79,    80,
      43,   215,     6,    46,   218,   139,     6,    36,    37,    38,
      39,   140,   146,    42,     6,     6,   145,   729,   129,   130,
       6,    36,    37,    38,    39,    31,    32,    42,    34,   129,
     130,   139,   129,   130,    43,   146,     6,    46,   146,   146,
      49,    82,   139,   150,    56,   145,   139,   147,   141,   146,
      83,    84,    85,    86,   139,   139,    56,   131,   132,   133,
     146,   146,   146,   146,   138,   140,   147,   129,   130,     0,
     145,   129,   130,    93,    94,   120,   121,   122,   101,  1186,
     125,   126,   119,   145,   129,    93,    94,   139,   146,   140,
     135,   129,   130,   138,   145,   140,   141,   142,   143,    13,
     145,   146,   147,   148,    49,   150,   151,   152,   791,   141,
     155,   136,   137,   139,   147,   139,   141,   146,   143,   146,
     129,   130,   126,   148,   146,   146,   171,   172,   356,   357,
     139,   146,   146,   146,   126,  1242,   181,   146,   129,   130,
     129,   130,   854,   129,   130,   464,     6,   129,   130,   183,
       7,   196,   197,   198,   368,   200,   190,   146,   203,   204,
       6,     7,   168,   145,   170,   147,   269,   270,   271,   272,
     176,   136,   137,   280,    53,   181,   221,   391,   143,   733,
     136,   137,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   331,   908,   139,   129,   130,   129,
     130,   131,   132,   133,    72,   280,   139,   145,   138,   147,
     282,    79,    80,   145,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   116,
     117,   118,   119,   139,   139,   139,   141,   312,   139,    72,
     146,   378,   139,   129,   130,   320,    79,    80,   139,   141,
     325,     7,   140,    49,   146,   330,   331,   145,   150,   145,
     335,   147,   337,   338,   339,    49,   341,   342,   343,   344,
     345,   346,   347,   344,   345,   346,   347,   140,   139,   147,
     129,   130,   145,    49,   359,   360,   361,   362,   363,   364,
     365,    51,   356,   357,    62,    63,   145,    72,     7,    72,
     139,   376,   141,   378,    79,    80,    79,    80,   383,   384,
       4,     5,    46,    49,   147,    49,   146,    51,   354,   355,
     395,   396,   397,   398,    72,   400,     6,     7,   364,    72,
     405,    79,    80,   408,   146,   407,    79,    80,   129,   130,
     146,    49,    36,    37,    38,    39,     6,    46,    42,    72,
       4,   139,   489,   141,   145,     8,    79,    80,    72,  1101,
     116,   117,   118,   119,   146,    79,    80,  1080,   139,    72,
     141,    72,   147,     4,   147,   512,    79,    80,    79,    80,
     136,   137,    72,     4,   459,   129,   130,   143,   280,    79,
      80,   466,   464,   139,   465,     7,   129,   130,   139,   147,
    1142,   145,   139,  1145,   147,     6,  1148,   116,   117,   118,
     119,   139,   145,   141,   489,   490,   101,   492,   493,   139,
     312,   496,   497,   498,   147,   101,   101,   136,   137,   129,
     130,   101,     4,   147,   783,   784,   146,   512,   330,   331,
     515,   516,   136,   137,   147,   145,   147,   522,   139,   143,
     141,  1035,   139,   586,   141,   139,    72,   147,   139,   534,
     535,   139,  1204,    79,    80,   540,   139,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   139,   557,   558,    72,   138,   378,  1229,     4,   564,
    1232,    79,    80,  1235,   147,     5,  1238,   533,   573,     6,
     575,   576,    72,     6,   116,   117,   118,   119,   645,    79,
      80,     4,     5,   646,   586,     6,  1258,   553,  1260,  1103,
    1262,  1105,     5,  1107,   136,   137,    36,    37,    38,    39,
     139,   147,    42,   139,   129,   130,   669,   674,   129,   130,
     345,   346,   347,    36,    37,    38,    39,   622,   623,    42,
     145,   153,   129,   130,   145,   139,     8,   159,   139,   696,
     141,   636,   637,   638,   639,   640,   641,   642,   145,     4,
     645,   139,   146,   141,   649,     4,     5,   147,   129,   130,
     139,   656,   184,   185,   139,   722,   723,   724,   725,   191,
     192,   666,   146,   146,   145,  1179,   840,   489,   139,   674,
     129,   130,   139,   139,   141,   497,   498,    36,    37,    38,
      39,    43,   139,    42,    46,   139,   145,    49,     8,    51,
     512,   696,   139,   515,   141,   139,   139,   141,  1212,   141,
    1214,   139,  1216,   141,   136,   137,   672,   146,  1222,   141,
     139,   143,   141,   139,   141,   141,   148,   722,   723,   724,
     725,   146,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   139,  1246,   141,  1248,   138,  1250,   146,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   146,   719,   720,   721,   138,   762,   763,   139,
     139,   141,   141,   141,   952,   147,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   145,   780,   147,
       6,   138,   784,   143,   136,   137,   139,   792,   141,   141,
     139,   143,   141,    96,   139,   800,   148,   329,   146,   804,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   145,   139,   147,   822,   138,   141,
     140,   143,     6,   645,    65,    66,    67,    68,   145,    70,
     147,   836,   837,   838,   139,    76,    77,   145,   145,   147,
     147,    49,   139,    51,   849,   850,   139,     6,   853,   912,
       6,   145,   674,   147,   145,   145,   147,   147,   145,   145,
     147,   147,     4,   868,   869,   870,   145,     6,   147,   874,
     875,   145,   141,   147,   696,   880,   878,   145,     5,   147,
     885,   145,     4,   147,     6,   146,   145,   853,   147,   145,
     145,   147,   147,   145,   138,   147,   901,   143,     7,   900,
     722,   723,   724,   725,   141,   145,   145,   147,   147,   145,
    1098,   147,   917,   145,     7,   147,   146,     7,   140,   924,
     925,     7,   147,     6,   929,   139,   147,     7,     7,   461,
     462,    93,   145,   938,   939,   146,   140,  1111,   140,   145,
       6,     4,   142,   948,    96,     7,     7,   948,     7,     7,
      96,     7,     7,   919,     7,   921,    96,     7,   952,     6,
     140,     7,   140,   140,   140,   970,   147,   101,     6,   143,
       7,     7,   147,     7,   143,   139,   139,     6,   146,     4,
       6,   986,   987,     6,    12,    13,     6,   142,   954,     6,
     956,     7,   958,   141,     6,   126,     7,    49,  1003,     7,
      51,     7,   146,     7,     7,     7,  1180,     7,     7,  1014,
       7,     7,     7,     7,     7,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     4,    54,  1032,    56,    57,
     146,    59,    60,   565,   566,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,     6,  1053,   146,
      78,   138,  1057,     6,  1059,   139,     6,    49,     6,     6,
      88,    89,    90,     6,  1069,     4,     7,     7,     6,  1074,
       7,     7,     7,     4,   102,   103,   104,     6,   106,   139,
       7,   109,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   140,  1102,   146,  1104,
     138,  1106,   143,     6,  1098,   140,   146,     6,     6,     6,
    1115,     6,     6,   146,   146,   146,  1121,  1122,     5,   147,
      92,     7,   146,     6,  1129,   146,     6,     5,     5,   143,
       6,     4,  1137,   142,     6,     6,  1102,     6,  1104,     5,
    1106,     6,     6,     6,     6,     6,     6,     6,     6,     6,
     682,   683,  1157,   685,     6,   687,   688,     6,     6,   691,
     692,  1224,  1167,     6,     6,  1170,     6,     6,  1173,     6,
     145,     6,  1177,     6,     4,   146,     7,     6,     6,  1184,
       6,   143,  1187,     6,     5,   146,     6,     6,   146,  1252,
     147,  1254,   146,     6,   146,     7,     6,   146,    91,     6,
       6,     6,    94,    61,     6,     6,   140,     6,     6,  1272,
       6,   743,   744,   745,   146,     5,    61,   147,     6,     6,
     146,     3,     4,   145,   147,     6,     6,     9,    10,    11,
       6,     6,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     6,     5,   146,   146,   146,     6,     6,
     145,    43,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   808,     6,   146,     6,
     138,     6,   814,    65,    66,    67,    68,    69,    70,     6,
       6,   823,   824,   825,    76,    77,   828,   829,   830,   831,
     832,   833,   834,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   849,     5,   146,
       6,   138,   146,   140,   146,     6,     6,     6,   145,   147,
     112,   113,   114,   115,     6,   146,     6,   146,     6,     6,
     872,     6,     6,   799,  1157,     3,     3,   129,   130,   904,
      -1,    -1,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,   144,     3,     4,   147,    -1,   899,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    76,    77,     6,   971,
      -1,    -1,   974,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     982,    -1,    -1,    -1,    -1,    -1,   988,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,   144,    -1,   146,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,  1050,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    65,    66,    67,    68,    69,    70,     6,  1110,    -1,
      -1,    -1,    76,    77,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,   101,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1149,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,    -1,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,     3,     4,
     144,     6,   146,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      65,    66,    67,    68,    69,    70,     8,    -1,    -1,    -1,
      -1,    76,    77,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   112,   113,   114,
     115,   138,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,    -1,    -1,    -1,   134,
      -1,    -1,    -1,    -1,   139,    -1,     3,     4,    -1,   144,
      -1,   146,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,   138,    -1,    65,    66,
      67,    68,    69,    70,     8,    -1,    -1,    -1,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
       6,    -1,    -1,    -1,   138,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,    -1,    -1,    -1,   134,    -1,    -1,
      -1,    -1,   139,    -1,     3,     4,    -1,   144,    -1,   146,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,    65,    66,    67,    68,
      69,    70,     8,    -1,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,
     139,    -1,     3,     4,    -1,   144,    -1,   146,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,    65,    66,    67,    68,    69,    70,
      -1,     3,     4,    -1,    -1,    76,    77,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
      -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,   139,    -1,
       3,     4,    -1,   144,    -1,   146,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,
      -1,    -1,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     142,    -1,   144,    -1,   146,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     6,    -1,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,
      -1,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,
      -1,   144,    -1,   146,     3,     4,     5,    -1,     7,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    -1,    -1,    42,   112,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,    -1,    -1,    -1,   134,    -1,    -1,    -1,
      -1,   139,    -1,     6,    -1,    -1,   144,    -1,   146,    -1,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,    -1,    -1,    -1,   134,    -1,   136,   137,    -1,
     139,    -1,   141,    -1,   143,   144,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    65,    66,
      67,    68,    69,    70,    -1,     3,     4,     5,    -1,    76,
      77,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    -1,    42,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,    -1,    -1,    -1,   134,     3,     4,
      -1,    -1,   139,    -1,     9,    10,    11,   144,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   112,   113,   114,   115,   138,    -1,
      12,    13,     6,    -1,    -1,   145,    -1,   147,    -1,    -1,
      -1,   129,   130,    -1,    -1,    -1,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    -1,    56,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    78,    12,    13,    -1,
      -1,    -1,    -1,    -1,   129,   130,    88,    89,    90,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,   144,
     102,   103,   104,    -1,   106,    -1,    -1,   109,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      -1,    56,    57,    -1,    59,    60,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    78,   138,   147,    -1,    12,    13,     6,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
      -1,   106,    -1,    -1,   109,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      -1,    56,    57,    -1,    59,    60,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   147,    78,    12,    13,   138,    -1,    -1,    -1,
     142,     6,    -1,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
      -1,   106,    -1,    -1,   109,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    -1,    56,    57,
      -1,    59,    60,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      78,   138,   147,    -1,    12,    13,     6,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,   104,    -1,   106,    -1,
      -1,   109,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    -1,    56,    57,
      -1,    59,    60,    -1,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   147,
      78,    12,    13,   138,    -1,     6,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,   104,     8,   106,    -1,
      -1,   109,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    -1,    56,    57,     8,    59,    60,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,     8,    78,   138,   147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,    -1,   106,    -1,    -1,   109,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,   147,   138,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,     0,     1,    -1,   138,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,   138,    -1,    35,    -1,
      -1,    -1,    -1,    40,    41,   147,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    72,    73,    74,    75,    76,
      77,    78,    -1,    -1,    81,    82,     4,    -1,    -1,    -1,
      87,    88,    89,    90,    12,    13,    93,    -1,    95,    -1,
      97,    98,    99,   100,    -1,   102,   103,   104,    -1,   106,
     107,   108,   109,   110,   111,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    -1,    -1,    81,    82,    12,    13,    -1,    -1,    87,
      88,    89,    90,    -1,    -1,    93,    -1,    95,    -1,    97,
      98,    99,   100,    -1,   102,   103,   104,    -1,   106,   107,
     108,   109,   110,   111,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    -1,    56,
      57,    -1,    59,    60,    -1,    -1,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    78,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,   104,    -1,   106,
      -1,    -1,   109,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,
     147,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,   147,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,   142,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,   142,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,   142,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
     142,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,   142,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,   142,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,   142,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,
      -1,    -1,   142,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,   142,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,   142,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,   142,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,   142,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,   142,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
     142,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,   142,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,   142,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,   142,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,
      -1,    -1,   142,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,   142,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,   142,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,   142,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,   142,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,   142,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
     142,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,   142,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,   142,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,   142,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,
      -1,    -1,   142,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,   142,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,   142,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,   140,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,
     140,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,   140,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    -1,   140,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,   140,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,   140,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,   140,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,   140,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,   140,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,   138,    -1,   140,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,   140,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,
     140,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,   140,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    -1,   140,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,   140,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,   140,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,   140,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,   140,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,   140,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,   138,    -1,   140,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,   140,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,
     140,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,   140,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    -1,   140,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,   140,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,   140,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,   140,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,   140,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,   140,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,   138,    -1,   140,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,   140,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,
     140,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,   140,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    -1,   140,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,   140,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,   140,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,   140,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,   140,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,   140,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,   138,    -1,   140,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,   140,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,
     140,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,   140,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    -1,   140,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,   140,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,   140,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,   140,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,   140,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,   140,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,   138,    -1,   140,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,   140,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,
     140,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,   140
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   150,   151,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    55,    56,    57,    58,    59,    60,    64,
      65,    66,    67,    68,    69,    70,    72,    73,    74,    75,
      76,    77,    78,    81,    82,    87,    88,    89,    90,    93,
      95,    97,    98,    99,   100,   102,   103,   104,   106,   107,
     108,   109,   110,   111,   152,   154,   155,   173,   175,   176,
     179,   180,   181,   182,   183,   184,   201,   202,   203,     3,
       4,     5,     7,     9,    10,    11,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    36,    37,    38,
      39,    42,   112,   113,   114,   115,   116,   117,   118,   119,
     129,   130,   134,   136,   137,   139,   141,   143,   144,   171,
     172,   204,   205,   216,    13,    49,   139,     6,   146,     6,
     139,   146,   139,   139,    71,   139,   146,   139,   139,    71,
     146,   139,   139,    53,    49,   139,    49,    49,    49,    46,
      49,    51,    51,    43,    46,    49,    51,   139,   146,   129,
     130,   139,   146,   206,   207,   206,   146,     4,    43,    46,
      49,   146,   206,   146,    49,    49,     4,   146,     6,    46,
     146,    43,    46,     4,     4,     4,   139,   139,   139,     4,
     146,   212,     4,   139,   139,     6,   101,   101,   101,   101,
       4,     4,   101,     4,     5,   146,   215,   216,   146,   215,
       4,   141,   143,   148,   172,   146,   216,   139,   141,   139,
     141,   139,   141,   139,   141,   139,   141,   139,   141,   139,
     141,   139,   141,   139,   141,   139,   141,   139,   141,   139,
     141,   139,   141,   139,   141,   139,   141,   139,   141,   139,
     141,   139,   141,   139,   141,   139,   141,   139,   141,   139,
     139,   139,   139,   139,     4,   204,   204,   204,   204,   142,
     146,   204,     4,    93,    94,     4,   204,     6,     6,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   138,     6,     6,   204,     5,   204,   204,
       4,    43,   130,   176,   184,   204,   210,   211,   204,   204,
     139,   204,   211,   204,   204,   139,   211,   204,   204,   101,
     130,   146,   204,   209,   210,   139,   204,   146,   139,   139,
     209,   146,   146,   139,   139,   139,   139,   139,     4,   206,
     206,   206,   204,   204,   129,   130,   146,   146,   206,   141,
     146,   146,   146,   129,   130,   139,   178,   206,   146,   176,
     177,   178,   209,   209,     4,     6,   141,   178,   146,   177,
     101,   209,   209,   141,   141,     6,   204,   204,   204,   143,
     204,   146,    96,   204,   204,   139,   139,   139,   139,     6,
     139,   178,     6,   178,     6,   141,   204,     4,   146,   156,
       6,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,     4,   215,   215,   215,   215,     5,   141,
     140,     7,   119,   211,   142,     7,   171,   172,   143,     7,
     141,     6,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,     6,   140,   145,
     145,   140,   141,   146,   204,   210,     8,   131,   145,   147,
     140,   140,   204,   140,   147,   140,   140,   204,   147,   140,
     140,   209,   146,   147,   211,   131,     7,   204,   140,   204,
     204,   204,     7,   204,   204,   204,   174,   204,   216,   174,
     174,   174,   140,   145,   145,   145,   206,   206,   177,   177,
     145,   204,   204,   204,   204,   204,    43,    46,    49,    51,
     109,   175,   188,   145,   178,   147,     6,     7,     7,     6,
     204,   147,   211,   147,   139,     7,     7,   204,   204,   140,
     140,   140,    93,   145,   178,   146,     8,   140,   204,   204,
     204,   204,   204,   147,   147,   204,   142,   172,   204,     4,
      83,    84,    85,    86,   147,   159,   163,   166,   168,   169,
     140,   142,   140,   142,   140,   142,   140,   142,   140,   142,
     140,   142,   140,   142,   140,   142,   140,   142,   140,   142,
     140,   142,   145,   145,   140,   142,   140,   142,   140,   142,
     140,   142,   140,   142,   140,   142,   145,   145,   145,   145,
     145,   145,   141,   143,   140,   145,   145,   140,   140,   145,
     204,   209,   209,   147,     7,   143,   171,   172,   216,   204,
       6,     4,     4,   146,   213,   142,     8,     6,   126,   153,
     211,   204,     7,   142,   146,   204,   204,   204,   210,   204,
     210,    96,     7,     7,   140,     7,    96,     7,     7,   140,
      96,     7,     7,     6,   211,   147,   146,   204,   140,     7,
     147,   140,   140,   204,   147,   147,   140,   140,   140,   140,
     140,   143,   206,   204,   204,   147,   147,   204,   142,   145,
     145,   145,   146,   146,   146,   146,    72,    79,    80,   199,
     200,   206,   147,   185,   204,   204,   142,   147,   204,   209,
     209,   142,   142,     7,     7,     7,   143,   204,   147,   204,
     204,   140,   140,   140,   140,   140,   142,   143,   172,   215,
     147,   160,   139,   139,   146,   170,     6,   204,   204,   204,
     204,   204,   204,   204,   204,   204,     4,   211,   215,   204,
     142,     6,     6,   142,     4,    93,    94,   204,     6,     6,
       6,     7,   141,   212,   214,     6,   204,   126,   215,   140,
     145,   206,   211,   147,     8,    49,   209,   209,     7,   209,
      49,    51,   209,   209,     7,    51,   209,   209,   147,   211,
       6,     7,   146,     7,     7,     7,     6,    61,     7,     7,
       7,     7,     7,     7,     7,     4,   145,   145,   145,   147,
     146,   206,   206,   206,   211,   211,   211,   211,     6,   146,
     139,   147,   200,   145,   199,     6,     6,     6,    49,   140,
       6,     6,     6,     6,   209,   209,   209,     4,   145,     8,
       8,   140,     7,     7,     7,     7,     7,     6,     4,     6,
     139,   204,   204,   208,   209,   146,   140,   142,   140,   142,
     140,   142,   140,   142,   142,   140,   140,   140,   140,   171,
       7,   171,   172,   143,     7,     6,   212,   204,   145,   147,
       6,     6,   153,   204,     6,   147,   204,   146,     6,    56,
       6,    56,   209,     6,   146,   146,     6,     6,   209,   146,
       6,     6,   147,     5,   204,   209,   209,   209,    62,    63,
     209,   209,   209,   209,   209,   209,   209,     6,     7,   204,
     204,   204,   146,   178,   145,   147,   145,   147,   145,   147,
     147,   147,   147,   147,   204,   209,   204,   204,   206,   147,
     146,     7,     6,     6,    92,   204,   204,   204,   209,     5,
     204,   204,     5,   172,   157,   204,   145,   145,   145,   147,
     158,   204,   143,   209,   216,   204,     6,     4,   213,     6,
     142,   212,   215,   145,   142,   204,   206,   206,     6,   204,
     204,     6,   204,     5,   145,     6,     6,     6,   204,   204,
       4,     6,     6,     6,     6,     6,     6,     6,   204,   216,
     147,   140,   145,   147,   177,   189,   206,     6,   190,   206,
       6,   191,   206,     6,   192,     6,     6,     6,     6,   147,
     145,   140,   147,   145,   204,   209,   209,   145,   147,     8,
     147,   140,     6,     6,     6,     6,     6,   209,   140,   145,
     204,   204,   209,   146,   145,   147,     4,     6,     6,     6,
       7,     6,   143,     6,   204,   147,     6,     6,   147,   147,
     147,     5,   204,     6,     6,     6,     6,     6,   146,   204,
     147,   199,   145,   146,   145,   146,   145,   146,     6,   209,
       7,   146,   204,   147,     6,    91,   204,   204,     6,   161,
     204,   145,   145,   208,   204,     6,   140,   212,    94,   145,
       6,     6,     6,     6,     6,   145,   177,   145,   147,   147,
     204,   206,   199,   204,   206,   199,   204,   206,   199,   145,
     147,   209,   178,   147,   204,   147,   147,   146,   204,   204,
     147,     6,   204,     5,   147,   204,   147,   145,   147,   147,
     145,   147,   147,   145,   147,   209,     6,    61,   147,   186,
     146,     6,   158,   140,   145,     6,   146,   145,   145,   147,
       6,   193,   204,     6,     6,   194,   204,     6,     6,   195,
     204,     6,   147,   204,   199,   178,   147,   164,   204,   208,
     204,     5,   146,   147,   146,   147,   146,   147,     6,     6,
     147,   147,   187,     6,   146,   140,   147,   147,   145,   199,
       6,   196,   199,     6,   197,   199,     6,   198,   199,   162,
     215,   167,   146,     6,     5,   147,   146,   147,   146,   147,
     146,   147,   145,   147,   146,   208,   147,     6,   199,     6,
     199,     6,   199,   215,     6,   165,   215,   147,     6,   147,
     147,   147,   145,   147,     6,     6,     6,     6,   215,     6
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
#line 146 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 157 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 158 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 159 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 160 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 161 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 162 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 163 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 164 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 165 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 166 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 167 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 168 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 169 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 170 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 175 "Gmsh.y"
    {
      (yyval.c) = "w";
    ;}
    break;

  case 21:
#line 179 "Gmsh.y"
    {
      (yyval.c) = "a";
    ;}
    break;

  case 22:
#line 186 "Gmsh.y"
    {
      Msg(DIRECT, (yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 23:
#line 191 "Gmsh.y"
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
#line 206 "Gmsh.y"
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
#line 219 "Gmsh.y"
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
#line 248 "Gmsh.y"
    { 
      if(!strcmp((yyvsp[(1) - (6)].c), "View") && ViewData->finalize()){
	ViewData->setName((yyvsp[(2) - (6)].c));
	ViewData->setFileName(gmsh_yyname);
	ViewData->setFileIndex(gmsh_yyviewindex++);
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
#line 265 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], false);
      }
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 28:
#line 274 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], true);
      }
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 29:
#line 286 "Gmsh.y"
    {
      ViewData = new PViewDataList(true); 
    ;}
    break;

  case 35:
#line 298 "Gmsh.y"
    { ViewCoord[ViewCoordIdx++] = (yyvsp[(1) - (1)].d); ;}
    break;

  case 36:
#line 300 "Gmsh.y"
    { ViewCoord[ViewCoordIdx++] = (yyvsp[(3) - (3)].d); ;}
    break;

  case 37:
#line 305 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(1) - (1)].d)); ;}
    break;

  case 38:
#line 307 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(3) - (3)].d)); ;}
    break;

  case 39:
#line 312 "Gmsh.y"
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
#line 456 "Gmsh.y"
    {
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(int j = 0; j < ViewCoordIdx / 3; j++)
	    List_Add(ViewValueList, &ViewCoord[3 * j + i]);
      }
    ;}
    break;

  case 41:
#line 464 "Gmsh.y"
    {
      if(ViewValueList) (*ViewNumList)++;
    ;}
    break;

  case 42:
#line 471 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(ViewData->T2C, &(yyvsp[(1) - (1)].c)[i]); 
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 43:
#line 476 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(ViewData->T2C, &(yyvsp[(3) - (3)].c)[i]); 
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 44:
#line 484 "Gmsh.y"
    { 
      List_Add(ViewData->T2D, &(yyvsp[(3) - (8)].d)); 
      List_Add(ViewData->T2D, &(yyvsp[(5) - (8)].d));
      List_Add(ViewData->T2D, &(yyvsp[(7) - (8)].d)); 
      double d = List_Nbr(ViewData->T2C);
      List_Add(ViewData->T2D, &d); 
    ;}
    break;

  case 45:
#line 492 "Gmsh.y"
    {
      ViewData->NbT2++;
    ;}
    break;

  case 46:
#line 499 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(ViewData->T3C, &(yyvsp[(1) - (1)].c)[i]); 
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 47:
#line 504 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(ViewData->T3C, &(yyvsp[(3) - (3)].c)[i]); 
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 48:
#line 512 "Gmsh.y"
    { 
      List_Add(ViewData->T3D, &(yyvsp[(3) - (10)].d)); List_Add(ViewData->T3D, &(yyvsp[(5) - (10)].d));
      List_Add(ViewData->T3D, &(yyvsp[(7) - (10)].d)); List_Add(ViewData->T3D, &(yyvsp[(9) - (10)].d)); 
      double d = List_Nbr(ViewData->T3C);
      List_Add(ViewData->T3D, &d); 
    ;}
    break;

  case 49:
#line 519 "Gmsh.y"
    {
      ViewData->NbT3++;
    ;}
    break;

  case 50:
#line 527 "Gmsh.y"
    {
      ViewData->adaptive = new Adaptive_Post_View(ViewData, (yyvsp[(3) - (8)].l), (yyvsp[(6) - (8)].l));
    ;}
    break;

  case 51:
#line 534 "Gmsh.y"
    {
      ViewData->adaptive = new Adaptive_Post_View(ViewData, (yyvsp[(3) - (14)].l), (yyvsp[(6) - (14)].l), (yyvsp[(9) - (14)].l), (yyvsp[(12) - (14)].l));
    ;}
    break;

  case 52:
#line 541 "Gmsh.y"
    {
      ViewValueList = ViewData->Time;
    ;}
    break;

  case 53:
#line 545 "Gmsh.y"
    {
    ;}
    break;

  case 54:
#line 552 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 55:
#line 553 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 56:
#line 554 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 57:
#line 555 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 58:
#line 556 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 59:
#line 560 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 60:
#line 561 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 61:
#line 569 "Gmsh.y"
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
#line 600 "Gmsh.y"
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
#line 639 "Gmsh.y"
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
#line 693 "Gmsh.y"
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
#line 710 "Gmsh.y"
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
#line 728 "Gmsh.y"
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
#line 739 "Gmsh.y"
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
#line 756 "Gmsh.y"
    { 
      Msg(WARNING, "Named string expressions not implemented yet");
    ;}
    break;

  case 69:
#line 763 "Gmsh.y"
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
#line 777 "Gmsh.y"
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
#line 794 "Gmsh.y"
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
#line 820 "Gmsh.y"
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
#line 847 "Gmsh.y"
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
#line 861 "Gmsh.y"
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
#line 878 "Gmsh.y"
    {
      unsigned int (*pColOpt)(int num, int action, unsigned int value);
      StringXColor *pColCat;
      if(!(pColCat = Get_ColorOptionCategory((yyvsp[(1) - (8)].c))))
	yymsg(GERROR, "Unknown color option class '%s'", (yyvsp[(1) - (8)].c));
      else{
	if(!(pColOpt = (unsigned int (*) (int, int, unsigned int))
	     Get_ColorOption((yyvsp[(5) - (8)].c), pColCat)))
	  yymsg(GERROR, "Unknown color option '%s.Color.%s'", (yyvsp[(1) - (8)].c), (yyvsp[(5) - (8)].c));
	else
	  pColOpt(0, GMSH_SET|GMSH_GUI, (yyvsp[(7) - (8)].u));
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 76:
#line 893 "Gmsh.y"
    {
      unsigned int (*pColOpt)(int num, int action, unsigned int value);
      StringXColor *pColCat;
      if(!(pColCat = Get_ColorOptionCategory((yyvsp[(1) - (11)].c))))
	yymsg(GERROR, "Unknown color option class '%s'", (yyvsp[(1) - (11)].c));
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))
	     Get_ColorOption((yyvsp[(8) - (11)].c), pColCat)))
	  yymsg(GERROR, "Unknown color option '%s[%d].Color.%s'", (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c));
	else
	  pColOpt((int)(yyvsp[(3) - (11)].d), GMSH_SET|GMSH_GUI, (yyvsp[(10) - (11)].u));
      }
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 77:
#line 911 "Gmsh.y"
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
#line 931 "Gmsh.y"
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
#line 954 "Gmsh.y"
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
#line 964 "Gmsh.y"
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
#line 979 "Gmsh.y"
    { 
      (yyval.i) = (int)(yyvsp[(1) - (1)].d); 
    ;}
    break;

  case 82:
#line 983 "Gmsh.y"
    { 
      (yyval.i) = GModel::current()->setPhysicalName
	(std::string((yyvsp[(1) - (1)].c)), ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 83:
#line 996 "Gmsh.y"
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
#line 1018 "Gmsh.y"
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
#line 1034 "Gmsh.y"
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
#line 1055 "Gmsh.y"
    {
      fields.insert(new LatLonField(fields.get((int)(yyvsp[(7) - (8)].d))), (int)(yyvsp[(4) - (8)].d));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 87:
#line 1062 "Gmsh.y"
    {
      int index = (int)(yyvsp[(7) - (8)].d);
      if(index >= 0 && index < (int)PView::list.size()) 
        fields.insert(new PostViewField(PView::list[index]), (int)(yyvsp[(4) - (8)].d));
      else
        yymsg(GERROR, "Field %i error, view %i does not exist", (int)(yyvsp[(4) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 88:
#line 1073 "Gmsh.y"
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
#line 1088 "Gmsh.y"
    {
      std::list<Field*> *flist = new std::list<Field*>;
      fields.insert(new FunctionField(flist,(yyvsp[(7) - (8)].c)), (int)(yyvsp[(4) - (8)].d));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 90:
#line 1096 "Gmsh.y"
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
#line 1111 "Gmsh.y"
    {
      fields.insert(new StructuredField((yyvsp[(7) - (8)].c)), (int)(yyvsp[(4) - (8)].d));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 92:
#line 1118 "Gmsh.y"
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
#line 1130 "Gmsh.y"
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
#line 1164 "Gmsh.y"
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
#line 1200 "Gmsh.y"
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
#line 1222 "Gmsh.y"
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
#line 1240 "Gmsh.y"
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
#line 1258 "Gmsh.y"
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
#line 1276 "Gmsh.y"
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
#line 1302 "Gmsh.y"
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
#line 1320 "Gmsh.y"
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
#line 1347 "Gmsh.y"
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
#line 1366 "Gmsh.y"
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
#line 1384 "Gmsh.y"
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
#line 1402 "Gmsh.y"
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
#line 1428 "Gmsh.y"
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
#line 1445 "Gmsh.y"
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
#line 1464 "Gmsh.y"
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
#line 1482 "Gmsh.y"
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
#line 1520 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 111:
#line 1526 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::surfaceByTag((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 112:
#line 1532 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 113:
#line 1539 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
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
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 114:
#line 1563 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
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
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 115:
#line 1587 "Gmsh.y"
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
#line 1603 "Gmsh.y"
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
#line 1623 "Gmsh.y"
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
#line 1640 "Gmsh.y"
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
#line 1657 "Gmsh.y"
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
#line 1678 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 121:
#line 1683 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 122:
#line 1688 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 123:
#line 1693 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 124:
#line 1698 "Gmsh.y"
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
#line 1709 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 126:
#line 1715 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      BoundaryShapes((yyvsp[(3) - (4)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 127:
#line 1723 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 128:
#line 1724 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 129:
#line 1729 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 130:
#line 1733 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 131:
#line 1737 "Gmsh.y"
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
#line 1760 "Gmsh.y"
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
#line 1783 "Gmsh.y"
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
#line 1806 "Gmsh.y"
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
#line 1834 "Gmsh.y"
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
#line 1843 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
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
#line 1856 "Gmsh.y"
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
#line 1872 "Gmsh.y"
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
#line 1887 "Gmsh.y"
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
#line 1901 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 141:
#line 1907 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 142:
#line 1913 "Gmsh.y"
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
#line 1922 "Gmsh.y"
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
#line 1936 "Gmsh.y"
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
#line 1984 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (7)].c), "Save") && !strcmp((yyvsp[(2) - (7)].c), "View")){
	int index = (int)(yyvsp[(4) - (7)].d);
	if(index >= 0 && index < (int)PView::list.size()){
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
#line 2000 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (7)].c), "Background") && !strcmp((yyvsp[(2) - (7)].c), "Mesh")  && !strcmp((yyvsp[(3) - (7)].c), "View")){
	int index = (int)(yyvsp[(5) - (7)].d);
	if(index >= 0 && index < (int)PView::list.size()){
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
#line 2016 "Gmsh.y"
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
#line 2035 "Gmsh.y"
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
#line 2045 "Gmsh.y"
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
#line 2067 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 151:
#line 2071 "Gmsh.y"
    {
      CTX.forced_bbox = 0;
      SetBoundingBox();
    ;}
    break;

  case 152:
#line 2076 "Gmsh.y"
    {
      CTX.forced_bbox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 153:
#line 2081 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      Draw();
#endif
    ;}
    break;

  case 154:
#line 2093 "Gmsh.y"
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
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
    ;}
    break;

  case 155:
#line 2110 "Gmsh.y"
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
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
    ;}
    break;

  case 156:
#line 2127 "Gmsh.y"
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
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[(5) - (8)].d) > (yyvsp[(7) - (8)].d)) 
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
    ;}
    break;

  case 157:
#line 2154 "Gmsh.y"
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
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[(9) - (10)].d) > 0. && (yyvsp[(5) - (10)].d) > (yyvsp[(7) - (10)].d)) || ((yyvsp[(9) - (10)].d) < 0. && (yyvsp[(5) - (10)].d) < (yyvsp[(7) - (10)].d)))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
    ;}
    break;

  case 158:
#line 2181 "Gmsh.y"
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
	  fsetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop-1]);
	  gmsh_yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop-1];
	}
	else
	  ImbricatedLoop--;
      }
    ;}
    break;

  case 159:
#line 2212 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname,
						      gmsh_yylineno))
	yymsg(GERROR, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 160:
#line 2220 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&gmsh_yyin, gmsh_yyname,
						     gmsh_yylineno))
	yymsg(GERROR, "Error while exiting function");
    ;}
    break;

  case 161:
#line 2226 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname,
						     gmsh_yylineno))
	yymsg(GERROR, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 162:
#line 2233 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 163:
#line 2237 "Gmsh.y"
    {
    ;}
    break;

  case 164:
#line 2246 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 165:
#line 2254 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 166:
#line 2262 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 167:
#line 2270 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 168:
#line 2274 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 169:
#line 2282 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 170:
#line 2286 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 171:
#line 2294 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 172:
#line 2298 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 173:
#line 2306 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 174:
#line 2310 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 175:
#line 2317 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 176:
#line 2321 "Gmsh.y"
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
#line 2333 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 178:
#line 2340 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 179:
#line 2347 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 180:
#line 2354 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 181:
#line 2361 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 182:
#line 2368 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 183:
#line 2375 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 184:
#line 2382 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 185:
#line 2389 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 186:
#line 2396 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 187:
#line 2400 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 188:
#line 2407 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 189:
#line 2411 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 190:
#line 2418 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 191:
#line 2422 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 192:
#line 2429 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 193:
#line 2433 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 194:
#line 2440 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 195:
#line 2444 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 196:
#line 2451 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 197:
#line 2455 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 198:
#line 2462 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 199:
#line 2466 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 200:
#line 2473 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 201:
#line 2477 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 202:
#line 2484 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 203:
#line 2488 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 204:
#line 2499 "Gmsh.y"
    {
    ;}
    break;

  case 205:
#line 2502 "Gmsh.y"
    {
    ;}
    break;

  case 206:
#line 2508 "Gmsh.y"
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
#line 2517 "Gmsh.y"
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
#line 2537 "Gmsh.y"
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
#line 2560 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 210:
#line 2564 "Gmsh.y"
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
#line 2588 "Gmsh.y"
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
	  c->nbPointsTransfinite = ((yyvsp[(5) - (6)].d) > 2) ? (int)(yyvsp[(5) - (6)].d) : 2;
	  c->typeTransfinite = sign(d);
	  c->coeffTransfinite = 1.0;
	}
      }
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 212:
#line 2606 "Gmsh.y"
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
	  c->nbPointsTransfinite = ((yyvsp[(5) - (9)].d) > 2) ? (int)(yyvsp[(5) - (9)].d) : 2;
	  c->typeTransfinite = sign(d); // Progresion : code 1 ou -1
	  c->coeffTransfinite = fabs((yyvsp[(8) - (9)].d));
	}
      }
      List_Delete((yyvsp[(3) - (9)].l));
    ;}
    break;

  case 213:
#line 2624 "Gmsh.y"
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
	  c->nbPointsTransfinite = ((yyvsp[(5) - (9)].d) > 2) ? (int)(yyvsp[(5) - (9)].d) : 2;
	  c->typeTransfinite = 2 * sign(d); // Bump : code 2 ou -2
	  c->coeffTransfinite = fabs((yyvsp[(8) - (9)].d));
	}
      }
      List_Delete((yyvsp[(3) - (9)].l));
    ;}
    break;

  case 214:
#line 2642 "Gmsh.y"
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
#line 2671 "Gmsh.y"
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
#line 2706 "Gmsh.y"
    {
      yymsg(WARNING, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 217:
#line 2711 "Gmsh.y"
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
#line 2738 "Gmsh.y"
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
#line 2752 "Gmsh.y"
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
#line 2765 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	int j = (int)d;
	Surface *s = FindSurface(j);
	if(s) s->TransfiniteSmoothing = (yyvsp[(5) - (6)].d);
      }
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 221:
#line 2782 "Gmsh.y"
    { 
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s)
	setSurfaceEmbeddedPoints(s, (yyvsp[(3) - (10)].l));
    ;}
    break;

  case 222:
#line 2788 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s)
	setSurfaceEmbeddedCurves(s, (yyvsp[(3) - (10)].l));
    ;}
    break;

  case 223:
#line 2794 "Gmsh.y"
    {
    ;}
    break;

  case 224:
#line 2797 "Gmsh.y"
    {
    ;}
    break;

  case 225:
#line 2806 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 226:
#line 2815 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 227:
#line 2816 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 228:
#line 2817 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 229:
#line 2818 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 230:
#line 2819 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 231:
#line 2820 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 232:
#line 2821 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 233:
#line 2822 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 234:
#line 2824 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(GERROR, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 235:
#line 2830 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 236:
#line 2831 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 237:
#line 2832 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 238:
#line 2833 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 239:
#line 2834 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 240:
#line 2835 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 241:
#line 2836 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 242:
#line 2837 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 243:
#line 2838 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 244:
#line 2839 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 245:
#line 2840 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d)? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d);  ;}
    break;

  case 246:
#line 2841 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 247:
#line 2842 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 248:
#line 2843 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 249:
#line 2844 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 250:
#line 2845 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 251:
#line 2846 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 252:
#line 2847 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 253:
#line 2848 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 254:
#line 2849 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 255:
#line 2850 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 256:
#line 2851 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 257:
#line 2852 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 258:
#line 2853 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 259:
#line 2854 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 260:
#line 2855 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 261:
#line 2856 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 262:
#line 2857 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 263:
#line 2858 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 264:
#line 2859 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 265:
#line 2860 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d)*(yyvsp[(3) - (6)].d)+(yyvsp[(5) - (6)].d)*(yyvsp[(5) - (6)].d)); ;}
    break;

  case 266:
#line 2861 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 267:
#line 2863 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 268:
#line 2864 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 269:
#line 2865 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 270:
#line 2866 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 271:
#line 2867 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 272:
#line 2868 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 273:
#line 2869 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 274:
#line 2870 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 275:
#line 2871 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 276:
#line 2872 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 277:
#line 2873 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 278:
#line 2874 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 279:
#line 2875 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 280:
#line 2876 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 281:
#line 2877 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 282:
#line 2878 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 283:
#line 2879 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 284:
#line 2880 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 285:
#line 2881 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 286:
#line 2882 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d)*(yyvsp[(3) - (6)].d)+(yyvsp[(5) - (6)].d)*(yyvsp[(5) - (6)].d)); ;}
    break;

  case 287:
#line 2883 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 288:
#line 2892 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 289:
#line 2893 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 290:
#line 2894 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->rank(); ;}
    break;

  case 291:
#line 2895 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->size(); ;}
    break;

  case 292:
#line 2896 "Gmsh.y"
    { (yyval.d) = Get_GmshMajorVersion(); ;}
    break;

  case 293:
#line 2897 "Gmsh.y"
    { (yyval.d) = Get_GmshMinorVersion(); ;}
    break;

  case 294:
#line 2898 "Gmsh.y"
    { (yyval.d) = Get_GmshPatchVersion(); ;}
    break;

  case 295:
#line 2903 "Gmsh.y"
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

  case 296:
#line 2919 "Gmsh.y"
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

  case 297:
#line 2934 "Gmsh.y"
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

  case 298:
#line 2954 "Gmsh.y"
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

  case 299:
#line 2967 "Gmsh.y"
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

  case 300:
#line 2980 "Gmsh.y"
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

  case 301:
#line 3003 "Gmsh.y"
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

  case 302:
#line 3021 "Gmsh.y"
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

  case 303:
#line 3039 "Gmsh.y"
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

  case 304:
#line 3057 "Gmsh.y"
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

  case 305:
#line 3075 "Gmsh.y"
    { 
      (yyval.d) = GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 306:
#line 3083 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 307:
#line 3087 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 308:
#line 3091 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 309:
#line 3095 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 310:
#line 3099 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 311:
#line 3106 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 312:
#line 3110 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 313:
#line 3114 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 314:
#line 3118 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 315:
#line 3125 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 316:
#line 3130 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 317:
#line 3138 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 318:
#line 3143 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 319:
#line 3147 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 320:
#line 3152 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 321:
#line 3156 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 322:
#line 3164 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 323:
#line 3175 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 324:
#line 3183 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 325:
#line 3191 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 326:
#line 3197 "Gmsh.y"
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

  case 327:
#line 3208 "Gmsh.y"
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

  case 328:
#line 3228 "Gmsh.y"
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
#line 3238 "Gmsh.y"
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

  case 330:
#line 3248 "Gmsh.y"
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

  case 331:
#line 3265 "Gmsh.y"
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

  case 332:
#line 3292 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 333:
#line 3297 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 334:
#line 3301 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 335:
#line 3305 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 336:
#line 3318 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 337:
#line 3322 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 338:
#line 3334 "Gmsh.y"
    {
      int flag;
      (yyval.u) = Get_ColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 339:
#line 3341 "Gmsh.y"
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

  case 340:
#line 3362 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 341:
#line 3366 "Gmsh.y"
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

  case 342:
#line 3381 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 343:
#line 3386 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 344:
#line 3393 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 345:
#line 3397 "Gmsh.y"
    {
      Msg(WARNING, "Named string expressions not implemented yet");
    ;}
    break;

  case 346:
#line 3404 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 347:
#line 3408 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32*sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 348:
#line 3416 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c))+strlen((yyvsp[(5) - (6)].c))+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 349:
#line 3424 "Gmsh.y"
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

  case 350:
#line 3438 "Gmsh.y"
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

  case 351:
#line 3452 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 352:
#line 3456 "Gmsh.y"
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

  case 353:
#line 3475 "Gmsh.y"
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

  case 354:
#line 3497 "Gmsh.y"
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
#line 8031 "Gmsh.tab.cpp"
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


#line 3520 "Gmsh.y"


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
  Msg(GERROR, "'%s', line %d : %s (%s)", gmsh_yyname, gmsh_yylineno - 1, s, gmsh_yytext);
  gmsh_yyerrorstate++;
}

void yymsg(int type, char *fmt, ...){
  va_list args;
  char tmp[1024];

  va_start (args, fmt);
  vsprintf (tmp, fmt, args);
  va_end (args);

  Msg(type, "'%s', line %d : %s", gmsh_yyname, gmsh_yylineno - 1, tmp);

  if(type == GERROR) gmsh_yyerrorstate++;
}

