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
     tAttractor = 330,
     tLayers = 331,
     tHole = 332,
     tAlias = 333,
     tAliasWithOptions = 334,
     tText2D = 335,
     tText3D = 336,
     tInterpolationScheme = 337,
     tTime = 338,
     tGrain = 339,
     tCombine = 340,
     tBSpline = 341,
     tBezier = 342,
     tNurbs = 343,
     tOrder = 344,
     tKnots = 345,
     tColor = 346,
     tColorTable = 347,
     tFor = 348,
     tIn = 349,
     tEndFor = 350,
     tIf = 351,
     tEndIf = 352,
     tExit = 353,
     tField = 354,
     tThreshold = 355,
     tStructured = 356,
     tLatLon = 357,
     tGrad = 358,
     tPostView = 359,
     tReturn = 360,
     tCall = 361,
     tFunction = 362,
     tShow = 363,
     tHide = 364,
     tGetValue = 365,
     tGMSH_MAJOR_VERSION = 366,
     tGMSH_MINOR_VERSION = 367,
     tGMSH_PATCH_VERSION = 368,
     tAFFECTDIVIDE = 369,
     tAFFECTTIMES = 370,
     tAFFECTMINUS = 371,
     tAFFECTPLUS = 372,
     tOR = 373,
     tAND = 374,
     tNOTEQUAL = 375,
     tEQUAL = 376,
     tGREATEROREQUAL = 377,
     tLESSOREQUAL = 378,
     UNARYPREC = 379,
     tMINUSMINUS = 380,
     tPLUSPLUS = 381
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
#define tAttractor 330
#define tLayers 331
#define tHole 332
#define tAlias 333
#define tAliasWithOptions 334
#define tText2D 335
#define tText3D 336
#define tInterpolationScheme 337
#define tTime 338
#define tGrain 339
#define tCombine 340
#define tBSpline 341
#define tBezier 342
#define tNurbs 343
#define tOrder 344
#define tKnots 345
#define tColor 346
#define tColorTable 347
#define tFor 348
#define tIn 349
#define tEndFor 350
#define tIf 351
#define tEndIf 352
#define tExit 353
#define tField 354
#define tThreshold 355
#define tStructured 356
#define tLatLon 357
#define tGrad 358
#define tPostView 359
#define tReturn 360
#define tCall 361
#define tFunction 362
#define tShow 363
#define tHide 364
#define tGetValue 365
#define tGMSH_MAJOR_VERSION 366
#define tGMSH_MINOR_VERSION 367
#define tGMSH_PATCH_VERSION 368
#define tAFFECTDIVIDE 369
#define tAFFECTTIMES 370
#define tAFFECTMINUS 371
#define tAFFECTPLUS 372
#define tOR 373
#define tAND 374
#define tNOTEQUAL 375
#define tEQUAL 376
#define tGREATEROREQUAL 377
#define tLESSOREQUAL 378
#define UNARYPREC 379
#define tMINUSMINUS 380
#define tPLUSPLUS 381




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// $Id: Gmsh.tab.cpp,v 1.321 2007-05-24 13:58:00 remacle Exp $
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
#include "Views.h"
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
extern Mesh *THEM;
extern GModel *GMODEL;

static ExtrudeParams extr;

static Post_View *View;
static List_T *ViewValueList;
static double ViewCoord[100];
static int *ViewNumList, ViewNumNodes, ViewNumComp, ViewNumListTmp;
static int ViewCoordIdx, ViewElementIdx;
static int ViewErrorFlags[VIEW_NB_ELEMENT_TYPES];

#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0;
static gmshSurface *myGmshSurface = 0;
static fpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static char *LoopControlVariablesNameTab[MAX_RECUR_LOOPS];

void yyerror(char *s);
void yymsg(int type, char *fmt, ...);
void skip_until(char *skip, char *until);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
int CheckViewErrorFlags(Post_View *v);


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
#line 79 "Gmsh.y"
{
  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
}
/* Line 187 of yacc.c.  */
#line 436 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 449 "Gmsh.tab.cpp"

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
# if YYENABLE_NLS
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
#define YYLAST   6735

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  147
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  357
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1281

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   381

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   132,     2,   142,     2,   131,     2,     2,
     137,   138,   129,   127,   143,   128,   141,   130,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     123,     2,   124,   118,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   139,     2,   140,   136,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   144,     2,   145,   146,     2,     2,     2,
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
     115,   116,   117,   119,   120,   121,   122,   125,   126,   133,
     134,   135
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    47,    53,    61,    69,    79,    86,    95,
      96,    99,   102,   105,   108,   111,   114,   116,   120,   122,
     126,   127,   128,   139,   141,   145,   146,   160,   162,   166,
     167,   183,   192,   207,   208,   215,   222,   224,   226,   228,
     230,   232,   234,   236,   241,   249,   259,   266,   273,   277,
     284,   289,   296,   306,   313,   323,   329,   338,   347,   359,
     366,   376,   386,   396,   398,   400,   408,   417,   427,   436,
     445,   454,   464,   473,   479,   486,   493,   500,   508,   516,
     524,   534,   542,   552,   570,   578,   586,   598,   607,   616,
     625,   634,   638,   643,   654,   662,   670,   679,   688,   697,
     705,   714,   720,   732,   738,   748,   750,   752,   754,   755,
     758,   765,   772,   779,   786,   791,   798,   805,   812,   817,
     824,   828,   833,   839,   843,   847,   852,   857,   861,   869,
     877,   881,   889,   893,   896,   899,   915,   918,   925,   934,
     943,   954,   956,   959,   961,   965,   970,   972,   978,   990,
    1004,  1005,  1013,  1014,  1028,  1029,  1045,  1046,  1053,  1054,
    1065,  1074,  1083,  1092,  1105,  1118,  1131,  1146,  1161,  1176,
    1177,  1190,  1191,  1204,  1205,  1218,  1219,  1236,  1237,  1254,
    1255,  1272,  1273,  1292,  1293,  1312,  1313,  1332,  1334,  1337,
    1343,  1351,  1361,  1364,  1374,  1381,  1391,  1401,  1410,  1420,
    1429,  1438,  1445,  1450,  1461,  1472,  1483,  1494,  1497,  1499,
    1503,  1506,  1509,  1512,  1516,  1520,  1524,  1528,  1532,  1536,
    1540,  1544,  1548,  1552,  1556,  1560,  1564,  1568,  1574,  1579,
    1584,  1589,  1594,  1599,  1604,  1609,  1614,  1619,  1624,  1631,
    1636,  1641,  1646,  1651,  1656,  1661,  1668,  1675,  1682,  1687,
    1692,  1697,  1702,  1707,  1712,  1717,  1722,  1727,  1732,  1737,
    1744,  1749,  1754,  1759,  1764,  1769,  1774,  1781,  1788,  1795,
    1800,  1802,  1804,  1806,  1808,  1810,  1812,  1814,  1816,  1822,
    1827,  1832,  1835,  1841,  1845,  1852,  1857,  1865,  1872,  1874,
    1877,  1880,  1884,  1888,  1900,  1910,  1918,  1926,  1928,  1932,
    1934,  1936,  1939,  1943,  1948,  1954,  1957,  1961,  1965,  1971,
    1976,  1978,  1980,  1982,  1986,  1993,  1995,  1997,  2001,  2005,
    2015,  2023,  2025,  2031,  2035,  2042,  2044,  2048,  2050,  2052,
    2054,  2056,  2063,  2068,  2073,  2078,  2085,  2092
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     148,     0,    -1,   149,    -1,     1,     6,    -1,    -1,   149,
     150,    -1,   153,    -1,   152,    -1,   172,    -1,   174,    -1,
     175,    -1,   178,    -1,   179,    -1,   180,    -1,   181,    -1,
     184,    -1,   201,    -1,   202,    -1,   203,    -1,   183,    -1,
     182,    -1,   124,    -1,   124,   124,    -1,    35,   137,     5,
     138,     6,    -1,    35,   137,     5,   138,   151,   215,     6,
      -1,    35,   137,     5,   143,   211,   138,     6,    -1,    35,
     137,     5,   143,   211,   138,   151,   215,     6,    -1,     4,
       5,   144,   154,   145,     6,    -1,     4,     5,     4,   206,
     144,   154,   145,     6,    -1,    -1,   154,   157,    -1,   154,
     161,    -1,   154,   164,    -1,   154,   166,    -1,   154,   167,
      -1,   154,   169,    -1,   204,    -1,   155,   143,   204,    -1,
     204,    -1,   156,   143,   204,    -1,    -1,    -1,     4,   158,
     137,   155,   138,   159,   144,   156,   145,     6,    -1,   215,
      -1,   160,   143,   215,    -1,    -1,    80,   137,   204,   143,
     204,   143,   204,   138,   162,   144,   160,   145,     6,    -1,
     215,    -1,   163,   143,   215,    -1,    -1,    81,   137,   204,
     143,   204,   143,   204,   143,   204,   138,   165,   144,   163,
     145,     6,    -1,    82,   144,   208,   145,   144,   208,   145,
       6,    -1,    82,   144,   208,   145,   144,   208,   145,   144,
     208,   145,   144,   208,   145,     6,    -1,    -1,    83,   168,
     144,   156,   145,     6,    -1,    84,   137,   204,   138,   209,
       6,    -1,     7,    -1,   117,    -1,   116,    -1,   115,    -1,
     114,    -1,   135,    -1,   134,    -1,     4,   170,   204,     6,
      -1,     4,   139,   204,   140,   170,   204,     6,    -1,     4,
     139,   144,   211,   145,   140,   170,   209,     6,    -1,     4,
     139,   140,     7,   209,     6,    -1,     4,   139,   140,   117,
     209,     6,    -1,     4,   171,     6,    -1,     4,   139,   204,
     140,   171,     6,    -1,     4,     7,   216,     6,    -1,     4,
     141,     4,     7,   216,     6,    -1,     4,   139,   204,   140,
     141,     4,     7,   216,     6,    -1,     4,   141,     4,   170,
     204,     6,    -1,     4,   139,   204,   140,   141,     4,   170,
     204,     6,    -1,     4,   141,     4,   171,     6,    -1,     4,
     139,   204,   140,   141,     4,   171,     6,    -1,     4,   141,
      91,   141,     4,     7,   212,     6,    -1,     4,   139,   204,
     140,   141,    91,   141,     4,     7,   212,     6,    -1,     4,
     141,    92,     7,   213,     6,    -1,     4,   139,   204,   140,
     141,    92,     7,   213,     6,    -1,    64,   137,     4,   138,
     141,     4,     7,   204,     6,    -1,    64,   137,     4,   138,
     141,     4,     7,   216,     6,    -1,   204,    -1,   216,    -1,
      43,   137,   204,   138,     7,   206,     6,    -1,    60,    43,
     137,   173,   138,     7,   209,     6,    -1,    75,    43,    99,
     137,   204,   138,     7,   209,     6,    -1,   102,    99,   137,
     204,   138,     7,   204,     6,    -1,   104,    99,   137,   204,
     138,     7,   204,     6,    -1,   100,    99,   137,   204,   138,
       7,   209,     6,    -1,   107,    99,   137,   204,   138,     7,
       5,   209,     6,    -1,   101,    99,   137,   204,   138,     7,
       5,     6,    -1,    52,    53,    99,   209,     6,    -1,    75,
      43,   209,     7,   209,     6,    -1,    75,    46,   209,     7,
     209,     6,    -1,    52,    53,   209,     7,   204,     6,    -1,
      46,   137,   204,   138,     7,   209,     6,    -1,    50,   137,
     204,   138,     7,   209,     6,    -1,    44,   137,   204,   138,
       7,   209,     6,    -1,    44,   137,   204,   138,     7,   209,
      56,   206,     6,    -1,    45,   137,   204,   138,     7,   209,
       6,    -1,    45,   137,   204,   138,     7,   209,    56,   206,
       6,    -1,    54,   137,   204,   138,     7,   144,   204,   143,
     204,   143,     5,   143,     5,   143,     5,   145,     6,    -1,
      86,   137,   204,   138,     7,   209,     6,    -1,    87,   137,
     204,   138,     7,   209,     6,    -1,    88,   137,   204,   138,
       7,   209,    90,   209,    89,   204,     6,    -1,    46,    71,
     137,   204,   138,     7,   209,     6,    -1,    60,    46,   137,
     173,   138,     7,   209,     6,    -1,    56,    49,   137,   204,
     138,     7,   209,     6,    -1,    57,    49,   137,   204,   138,
       7,   209,     6,    -1,    12,    13,     6,    -1,    13,    49,
     204,     6,    -1,    54,    49,   137,   204,   138,     7,     5,
       5,     5,     6,    -1,    47,   137,   204,   138,     7,   209,
       6,    -1,    48,   137,   204,   138,     7,   209,     6,    -1,
      49,    71,   137,   204,   138,     7,   209,     6,    -1,    60,
      49,   137,   173,   138,     7,   209,     6,    -1,    59,    51,
     137,   204,   138,     7,   209,     6,    -1,    51,   137,   204,
     138,     7,   209,     6,    -1,    60,    51,   137,   173,   138,
       7,   209,     6,    -1,    66,   206,   144,   176,   145,    -1,
      65,   144,   206,   143,   206,   143,   204,   145,   144,   176,
     145,    -1,    67,   206,   144,   176,   145,    -1,    68,   144,
     206,   143,   204,   145,   144,   176,   145,    -1,   178,    -1,
     177,    -1,   175,    -1,    -1,   177,   174,    -1,   177,    43,
     144,   211,   145,     6,    -1,   177,    46,   144,   211,   145,
       6,    -1,   177,    49,   144,   211,   145,     6,    -1,   177,
      51,   144,   211,   145,     6,    -1,    70,   144,   177,   145,
      -1,    70,     4,   139,   204,   140,     6,    -1,    78,     4,
     139,   204,   140,     6,    -1,    79,     4,   139,   204,   140,
       6,    -1,    73,   144,   177,   145,    -1,    73,     4,   139,
     204,   140,     6,    -1,    73,     4,     6,    -1,    73,     4,
       4,     6,    -1,    91,   212,   144,   177,   145,    -1,   108,
     215,     6,    -1,   109,   215,     6,    -1,   108,   144,   177,
     145,    -1,   109,   144,   177,   145,    -1,     4,   216,     6,
      -1,     4,     4,   139,   204,   140,   215,     6,    -1,     4,
       4,     4,   139,   204,   140,     6,    -1,     4,   204,     6,
      -1,    64,   137,     4,   138,   141,     4,     6,    -1,    85,
       4,     6,    -1,    98,     6,    -1,    40,     6,    -1,    40,
     144,   204,   143,   204,   143,   204,   143,   204,   143,   204,
     143,   204,   145,     6,    -1,    41,     6,    -1,    93,   137,
     204,     8,   204,   138,    -1,    93,   137,   204,     8,   204,
       8,   204,   138,    -1,    93,     4,    94,   144,   204,     8,
     204,   145,    -1,    93,     4,    94,   144,   204,     8,   204,
       8,   204,   145,    -1,    95,    -1,   107,     4,    -1,   105,
      -1,   106,     4,     6,    -1,    96,   137,   204,   138,    -1,
      97,    -1,    69,   206,   144,   177,   145,    -1,    69,   144,
     206,   143,   206,   143,   204,   145,   144,   177,   145,    -1,
      69,   144,   206,   143,   206,   143,   206,   143,   204,   145,
     144,   177,   145,    -1,    -1,    69,   206,   144,   177,   185,
     199,   145,    -1,    -1,    69,   144,   206,   143,   206,   143,
     204,   145,   144,   177,   186,   199,   145,    -1,    -1,    69,
     144,   206,   143,   206,   143,   206,   143,   204,   145,   144,
     177,   187,   199,   145,    -1,    -1,    69,   144,   177,   188,
     199,   145,    -1,    -1,    69,     4,   139,   204,   140,   144,
     177,   189,   199,   145,    -1,    69,    43,   144,   204,   143,
     206,   145,     6,    -1,    69,    46,   144,   204,   143,   206,
     145,     6,    -1,    69,    49,   144,   204,   143,   206,   145,
       6,    -1,    69,    43,   144,   204,   143,   206,   143,   206,
     143,   204,   145,     6,    -1,    69,    46,   144,   204,   143,
     206,   143,   206,   143,   204,   145,     6,    -1,    69,    49,
     144,   204,   143,   206,   143,   206,   143,   204,   145,     6,
      -1,    69,    43,   144,   204,   143,   206,   143,   206,   143,
     206,   143,   204,   145,     6,    -1,    69,    46,   144,   204,
     143,   206,   143,   206,   143,   206,   143,   204,   145,     6,
      -1,    69,    49,   144,   204,   143,   206,   143,   206,   143,
     206,   143,   204,   145,     6,    -1,    -1,    69,    43,   144,
     204,   143,   206,   145,   190,   144,   199,   145,     6,    -1,
      -1,    69,    46,   144,   204,   143,   206,   145,   191,   144,
     199,   145,     6,    -1,    -1,    69,    49,   144,   204,   143,
     206,   145,   192,   144,   199,   145,     6,    -1,    -1,    69,
      43,   144,   204,   143,   206,   143,   206,   143,   204,   145,
     193,   144,   199,   145,     6,    -1,    -1,    69,    46,   144,
     204,   143,   206,   143,   206,   143,   204,   145,   194,   144,
     199,   145,     6,    -1,    -1,    69,    49,   144,   204,   143,
     206,   143,   206,   143,   204,   145,   195,   144,   199,   145,
       6,    -1,    -1,    69,    43,   144,   204,   143,   206,   143,
     206,   143,   206,   143,   204,   145,   196,   144,   199,   145,
       6,    -1,    -1,    69,    46,   144,   204,   143,   206,   143,
     206,   143,   206,   143,   204,   145,   197,   144,   199,   145,
       6,    -1,    -1,    69,    49,   144,   204,   143,   206,   143,
     206,   143,   206,   143,   204,   145,   198,   144,   199,   145,
       6,    -1,   200,    -1,   199,   200,    -1,    76,   144,   204,
     145,     6,    -1,    76,   144,   209,   143,   209,   145,     6,
      -1,    76,   144,   209,   143,   209,   143,   209,   145,     6,
      -1,    72,     6,    -1,    77,   137,   204,   138,     7,   209,
      61,   204,     6,    -1,    58,    46,   209,     7,   204,     6,
      -1,    58,    46,   209,     7,   204,    61,    63,   204,     6,
      -1,    58,    46,   209,     7,   204,    61,    62,   204,     6,
      -1,    58,    49,   144,   204,   145,     7,   209,     6,    -1,
      58,    49,   144,   204,   145,     7,   209,     4,     6,    -1,
      55,    49,   144,   204,   145,     7,   209,     6,    -1,    58,
      51,   144,   204,   145,     7,   209,     6,    -1,    72,    49,
     209,     7,   204,     6,    -1,    72,    49,   209,     6,    -1,
      43,   144,   211,   145,    94,    49,   144,   204,   145,     6,
      -1,    46,   144,   211,   145,    94,    49,   144,   204,   145,
       6,    -1,    46,   144,   211,   145,    94,    51,   144,   204,
     145,     6,    -1,    49,   144,   211,   145,    94,    51,   144,
     204,   145,     6,    -1,    74,     6,    -1,   205,    -1,   137,
     204,   138,    -1,   128,   204,    -1,   127,   204,    -1,   132,
     204,    -1,   204,   128,   204,    -1,   204,   127,   204,    -1,
     204,   129,   204,    -1,   204,   130,   204,    -1,   204,   131,
     204,    -1,   204,   136,   204,    -1,   204,   123,   204,    -1,
     204,   124,   204,    -1,   204,   126,   204,    -1,   204,   125,
     204,    -1,   204,   122,   204,    -1,   204,   121,   204,    -1,
     204,   120,   204,    -1,   204,   119,   204,    -1,   204,   118,
     204,     8,   204,    -1,    14,   137,   204,   138,    -1,    15,
     137,   204,   138,    -1,    16,   137,   204,   138,    -1,    17,
     137,   204,   138,    -1,    18,   137,   204,   138,    -1,    19,
     137,   204,   138,    -1,    20,   137,   204,   138,    -1,    21,
     137,   204,   138,    -1,    22,   137,   204,   138,    -1,    24,
     137,   204,   138,    -1,    25,   137,   204,   143,   204,   138,
      -1,    26,   137,   204,   138,    -1,    27,   137,   204,   138,
      -1,    28,   137,   204,   138,    -1,    29,   137,   204,   138,
      -1,    30,   137,   204,   138,    -1,    31,   137,   204,   138,
      -1,    32,   137,   204,   143,   204,   138,    -1,    33,   137,
     204,   143,   204,   138,    -1,    34,   137,   204,   143,   204,
     138,    -1,    23,   137,   204,   138,    -1,    14,   139,   204,
     140,    -1,    15,   139,   204,   140,    -1,    16,   139,   204,
     140,    -1,    17,   139,   204,   140,    -1,    18,   139,   204,
     140,    -1,    19,   139,   204,   140,    -1,    20,   139,   204,
     140,    -1,    21,   139,   204,   140,    -1,    22,   139,   204,
     140,    -1,    24,   139,   204,   140,    -1,    25,   139,   204,
     143,   204,   140,    -1,    26,   139,   204,   140,    -1,    27,
     139,   204,   140,    -1,    28,   139,   204,   140,    -1,    29,
     139,   204,   140,    -1,    30,   139,   204,   140,    -1,    31,
     139,   204,   140,    -1,    32,   139,   204,   143,   204,   140,
      -1,    33,   139,   204,   143,   204,   140,    -1,    34,   139,
     204,   143,   204,   140,    -1,    23,   139,   204,   140,    -1,
       3,    -1,     9,    -1,    10,    -1,    11,    -1,   111,    -1,
     112,    -1,   113,    -1,     4,    -1,     4,   146,   144,   204,
     145,    -1,     4,   139,   204,   140,    -1,   142,     4,   139,
     140,    -1,     4,   171,    -1,     4,   139,   204,   140,   171,
      -1,     4,   141,     4,    -1,     4,   139,   204,   140,   141,
       4,    -1,     4,   141,     4,   171,    -1,     4,   139,   204,
     140,   141,     4,   171,    -1,   110,   137,     5,   143,   204,
     138,    -1,   207,    -1,   128,   206,    -1,   127,   206,    -1,
     206,   128,   206,    -1,   206,   127,   206,    -1,   144,   204,
     143,   204,   143,   204,   143,   204,   143,   204,   145,    -1,
     144,   204,   143,   204,   143,   204,   143,   204,   145,    -1,
     144,   204,   143,   204,   143,   204,   145,    -1,   137,   204,
     143,   204,   143,   204,   138,    -1,   209,    -1,   208,   143,
     209,    -1,   204,    -1,   210,    -1,   144,   145,    -1,   144,
     211,   145,    -1,   128,   144,   211,   145,    -1,   204,   129,
     144,   211,   145,    -1,   128,   210,    -1,   204,   129,   210,
      -1,   204,     8,   204,    -1,   204,     8,   204,     8,   204,
      -1,    43,   144,   204,   145,    -1,   175,    -1,   178,    -1,
     184,    -1,     4,   139,   140,    -1,     4,   139,   144,   211,
     145,   140,    -1,   204,    -1,   210,    -1,   211,   143,   204,
      -1,   211,   143,   210,    -1,   144,   204,   143,   204,   143,
     204,   143,   204,   145,    -1,   144,   204,   143,   204,   143,
     204,   145,    -1,     4,    -1,     4,   141,    91,   141,     4,
      -1,   144,   214,   145,    -1,     4,   139,   204,   140,   141,
      92,    -1,   212,    -1,   214,   143,   212,    -1,   216,    -1,
       4,    -1,     5,    -1,    42,    -1,    37,   137,   215,   143,
     215,   138,    -1,    38,   137,   215,   138,    -1,    39,   137,
     215,   138,    -1,    36,   137,   215,   138,    -1,    36,   137,
     215,   143,   211,   138,    -1,    36,   137,     4,   141,     4,
     138,    -1,    36,   137,     4,   139,   204,   140,   141,     4,
     138,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   146,   146,   147,   152,   154,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   176,   180,   187,   192,   207,   220,   249,   256,   267,
     273,   274,   275,   276,   277,   278,   282,   284,   289,   291,
     297,   487,   296,   515,   520,   529,   528,   542,   547,   556,
     555,   569,   575,   586,   585,   594,   603,   604,   605,   606,
     607,   611,   612,   619,   650,   689,   743,   760,   778,   789,
     806,   813,   827,   844,   870,   897,   911,   928,   942,   959,
     979,  1002,  1012,  1027,  1031,  1043,  1065,  1081,  1102,  1105,
    1112,  1127,  1142,  1149,  1161,  1195,  1231,  1253,  1271,  1289,
    1307,  1333,  1351,  1377,  1397,  1421,  1445,  1471,  1488,  1507,
    1525,  1563,  1567,  1571,  1576,  1598,  1620,  1636,  1656,  1673,
    1690,  1711,  1716,  1721,  1726,  1734,  1735,  1736,  1741,  1744,
    1748,  1771,  1794,  1817,  1845,  1857,  1863,  1869,  1881,  1890,
    1900,  1916,  1935,  1949,  1955,  1961,  1970,  1984,  2034,  2049,
    2064,  2084,  2094,  2116,  2120,  2125,  2130,  2142,  2157,  2173,
    2199,  2226,  2258,  2265,  2270,  2276,  2280,  2289,  2297,  2305,
    2314,  2313,  2326,  2325,  2338,  2337,  2350,  2349,  2361,  2360,
    2376,  2383,  2390,  2397,  2404,  2411,  2418,  2425,  2432,  2440,
    2439,  2451,  2450,  2462,  2461,  2473,  2472,  2484,  2483,  2495,
    2494,  2506,  2505,  2517,  2516,  2528,  2527,  2542,  2545,  2551,
    2560,  2582,  2606,  2610,  2634,  2652,  2670,  2688,  2717,  2752,
    2757,  2784,  2798,  2817,  2823,  2829,  2832,  2841,  2851,  2852,
    2853,  2854,  2855,  2856,  2857,  2858,  2859,  2866,  2867,  2868,
    2869,  2870,  2871,  2872,  2873,  2874,  2875,  2876,  2877,  2878,
    2879,  2880,  2881,  2882,  2883,  2884,  2885,  2886,  2887,  2888,
    2889,  2890,  2891,  2892,  2893,  2894,  2895,  2896,  2897,  2899,
    2900,  2901,  2902,  2903,  2904,  2905,  2906,  2907,  2908,  2909,
    2910,  2911,  2912,  2913,  2914,  2915,  2916,  2917,  2918,  2919,
    2928,  2929,  2930,  2931,  2932,  2933,  2934,  2938,  2954,  2969,
    2989,  3003,  3016,  3039,  3057,  3075,  3093,  3111,  3119,  3123,
    3127,  3131,  3135,  3142,  3146,  3150,  3154,  3161,  3166,  3174,
    3179,  3183,  3188,  3192,  3200,  3211,  3219,  3227,  3233,  3244,
    3264,  3274,  3284,  3294,  3311,  3338,  3343,  3347,  3351,  3364,
    3368,  3380,  3387,  3409,  3413,  3428,  3433,  3440,  3444,  3451,
    3455,  3463,  3471,  3485,  3499,  3503,  3522,  3544
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
  "tCoherence", "tAttractor", "tLayers", "tHole", "tAlias",
  "tAliasWithOptions", "tText2D", "tText3D", "tInterpolationScheme",
  "tTime", "tGrain", "tCombine", "tBSpline", "tBezier", "tNurbs", "tOrder",
  "tKnots", "tColor", "tColorTable", "tFor", "tIn", "tEndFor", "tIf",
  "tEndIf", "tExit", "tField", "tThreshold", "tStructured", "tLatLon",
  "tGrad", "tPostView", "tReturn", "tCall", "tFunction", "tShow", "tHide",
  "tGetValue", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION",
  "tGMSH_PATCH_VERSION", "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS",
  "tAFFECTPLUS", "'?'", "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'",
  "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'",
  "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All",
  "GeoFormatItems", "GeoFormatItem", "SendToFile", "Printf", "View",
  "Views", "ElementCoords", "ElementValues", "Element", "@1", "@2",
  "Text2DValues", "Text2D", "@3", "Text3DValues", "Text3D", "@4",
  "InterpolationMatrix", "Time", "@5", "Grain", "NumericAffectation",
  "NumericIncrement", "Affectation", "PhysicalId", "Shape", "Transform",
  "MultipleShape", "ListOfShapes", "Duplicata", "Delete", "Colorify",
  "Visibility", "Command", "Loop", "Extrude", "@6", "@7", "@8", "@9",
  "@10", "@11", "@12", "@13", "@14", "@15", "@16", "@17", "@18", "@19",
  "ExtrudeParameters", "ExtrudeParameter", "Transfinite", "Embedding",
  "Coherence", "FExpr", "FExpr_Single", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "FExpr_Multi",
  "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
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
     365,   366,   367,   368,   369,   370,   371,   372,    63,   373,
     374,   375,   376,    60,    62,   377,   378,    43,    45,    42,
      47,    37,    33,   379,   380,   381,    94,    40,    41,    91,
      93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   147,   148,   148,   149,   149,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   151,   151,   152,   152,   152,   152,   153,   153,   154,
     154,   154,   154,   154,   154,   154,   155,   155,   156,   156,
     158,   159,   157,   160,   160,   162,   161,   163,   163,   165,
     164,   166,   166,   168,   167,   169,   170,   170,   170,   170,
     170,   171,   171,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   173,   173,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   175,   175,   175,   175,   176,   176,   176,   177,   177,
     177,   177,   177,   177,   178,   178,   178,   178,   179,   179,
     179,   179,   180,   181,   181,   181,   181,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   184,   184,   184,
     185,   184,   186,   184,   187,   184,   188,   184,   189,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   190,
     184,   191,   184,   192,   184,   193,   184,   194,   184,   195,
     184,   196,   184,   197,   184,   198,   184,   199,   199,   200,
     200,   200,   200,   200,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   202,   202,   202,   202,   203,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   206,   206,
     206,   206,   206,   207,   207,   207,   207,   208,   208,   209,
     209,   209,   209,   209,   209,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   211,   211,   211,   211,   212,
     212,   212,   212,   213,   213,   214,   214,   215,   215,   216,
     216,   216,   216,   216,   216,   216,   216,   216
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     7,     7,     9,     6,     8,     0,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     3,
       0,     0,    10,     1,     3,     0,    13,     1,     3,     0,
      15,     8,    14,     0,     6,     6,     1,     1,     1,     1,
       1,     1,     1,     4,     7,     9,     6,     6,     3,     6,
       4,     6,     9,     6,     9,     5,     8,     8,    11,     6,
       9,     9,     9,     1,     1,     7,     8,     9,     8,     8,
       8,     9,     8,     5,     6,     6,     6,     7,     7,     7,
       9,     7,     9,    17,     7,     7,    11,     8,     8,     8,
       8,     3,     4,    10,     7,     7,     8,     8,     8,     7,
       8,     5,    11,     5,     9,     1,     1,     1,     0,     2,
       6,     6,     6,     6,     4,     6,     6,     6,     4,     6,
       3,     4,     5,     3,     3,     4,     4,     3,     7,     7,
       3,     7,     3,     2,     2,    15,     2,     6,     8,     8,
      10,     1,     2,     1,     3,     4,     1,     5,    11,    13,
       0,     7,     0,    13,     0,    15,     0,     6,     0,    10,
       8,     8,     8,    12,    12,    12,    14,    14,    14,     0,
      12,     0,    12,     0,    12,     0,    16,     0,    16,     0,
      16,     0,    18,     0,    18,     0,    18,     1,     2,     5,
       7,     9,     2,     9,     6,     9,     9,     8,     9,     8,
       8,     6,     4,    10,    10,    10,    10,     2,     1,     3,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     6,     6,     6,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     4,
       4,     2,     5,     3,     6,     4,     7,     6,     1,     2,
       2,     3,     3,    11,     9,     7,     7,     1,     3,     1,
       1,     2,     3,     4,     5,     2,     3,     3,     5,     4,
       1,     1,     1,     3,     6,     1,     1,     3,     3,     9,
       7,     1,     5,     3,     6,     1,     3,     1,     1,     1,
       1,     6,     4,     4,     4,     6,     6,     9
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
       0,     0,     0,     0,     0,     0,     0,     0,   161,     0,
     166,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     5,     7,     6,     8,     9,    10,    11,    12,    13,
      14,    20,    19,    15,    16,    17,    18,   290,   297,   349,
      56,   291,   292,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   350,
       0,   294,   295,   296,    60,    59,    58,    57,     0,     0,
       0,    62,    61,     0,     0,     0,     0,     0,     0,     0,
     228,     0,     0,     0,     0,   154,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   308,     0,     0,     0,     0,     0,     0,   128,
       0,     0,   128,     0,     0,   128,   227,     0,     0,     0,
       0,     0,     0,     0,     0,   341,     0,     0,     0,     0,
       0,   153,     0,     0,     0,     0,     0,   162,     0,   348,
     349,   128,     0,   347,   128,     0,     0,     0,     0,     0,
     301,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   297,   231,   230,   232,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,   111,     0,     0,     0,     0,   297,     0,     0,
     330,   331,   332,   335,   336,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     319,     0,   320,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   310,   309,
       0,     0,     0,     0,   128,   128,     0,     0,     0,     0,
       0,     0,     0,     0,   176,     0,   128,     0,     0,     0,
       0,   140,     0,     0,     0,     0,     0,     0,     0,   152,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,   164,     0,     0,   143,     0,   144,     0,
       0,   303,     0,     0,     0,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   348,     0,
       0,     0,     0,     0,     0,   229,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,    63,     0,   246,   245,
     244,   243,   239,   240,   242,   241,   234,   233,   235,   236,
     237,   238,   112,     0,     0,     0,     0,     0,     0,   230,
     325,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   321,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,     0,     0,     0,     0,     0,     0,
       0,   312,   311,   127,     0,   126,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,   170,     0,   134,   222,     0,   141,     0,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,     0,     0,     0,     0,   145,
     146,     0,   299,   305,     0,    29,    40,     0,     0,     0,
      53,     0,     0,    30,    31,    32,    33,    34,    35,   248,
     269,   249,   270,   250,   271,   251,   272,   252,   273,   253,
     274,   254,   275,   255,   276,   256,   277,   268,   289,   257,
     278,     0,     0,   259,   280,   260,   281,   261,   282,   262,
     283,   263,   284,   264,   285,     0,     0,     0,     0,     0,
       0,     0,     0,   354,     0,     0,   352,   353,     0,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,    75,
       0,     0,     0,     0,   300,     0,    23,    21,     0,     0,
       0,     0,   333,     0,     0,   327,   235,   326,   337,   338,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,   322,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
       0,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   302,     0,   298,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     299,    66,    67,     0,     0,     0,     0,     0,    69,    71,
      73,     0,     0,   345,     0,    79,   247,    22,     0,     0,
       0,     0,     0,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   323,     0,
      96,     0,     0,     0,     0,     0,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,     0,     0,   212,     0,
       0,   177,   208,     0,     0,   135,   221,   139,     0,    94,
      95,   136,   137,     0,     0,     0,   342,     0,     0,     0,
     157,     0,     0,     0,     0,     0,   149,   304,   148,     0,
       0,     0,     0,     0,   317,     0,     0,   258,   279,   265,
     286,   266,   287,   267,   288,     0,   356,   355,   351,   307,
       0,    56,     0,     0,     0,     0,    64,     0,     0,     0,
     343,    24,    25,     0,     0,    85,     0,   328,     0,    99,
       0,   101,     0,     0,    97,     0,     0,   114,   115,     0,
       0,    98,   119,   324,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,     0,
       0,     0,     0,   128,   178,     0,   189,     0,   191,     0,
     193,     0,     0,     0,     0,   319,     0,     0,     0,     0,
     171,     0,   104,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   306,    28,     0,    36,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,    76,     0,
       0,    77,     0,   346,     0,     0,   334,     0,     0,     0,
     107,     0,     0,   116,     0,     0,     0,   219,   109,   110,
       0,     0,     0,   217,   220,   118,    86,   108,   117,   120,
       0,     0,     0,   316,     0,   315,     0,     0,     0,   180,
       0,     0,   181,     0,     0,   182,     0,   130,   131,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,   340,
       0,   159,   158,    90,    92,    88,    89,     0,    41,     0,
       0,     0,   318,     0,     0,     0,     0,     0,    65,    72,
      74,     0,    80,     0,    26,     0,     0,   100,   102,     0,
       0,     0,     0,     0,   216,   215,   218,    81,    82,   128,
       0,   124,     0,     0,     0,     0,     0,     0,     0,   209,
       0,     0,   128,     0,    87,     0,     0,     0,    91,     0,
      37,     0,     0,     0,    39,    54,    55,   357,     0,   344,
       0,   223,   224,   225,   226,   113,     0,     0,     0,   314,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   172,     0,     0,   339,   160,     0,     0,
       0,     0,    78,     0,     0,   122,     0,   195,     0,     0,
     197,     0,     0,   199,     0,     0,     0,   210,     0,   168,
       0,   128,   106,     0,    45,     0,    51,     0,     0,     0,
     313,   183,     0,     0,   190,   184,     0,     0,   192,   185,
       0,     0,   194,     0,     0,     0,   174,     0,     0,     0,
       0,     0,     0,     0,   201,     0,   203,     0,   205,   211,
     213,   173,   169,     0,    42,     0,    49,     0,     0,     0,
       0,   186,     0,     0,   187,     0,     0,   188,     0,     0,
       0,    43,     0,     0,   155,     0,     0,     0,     0,     0,
       0,     0,   175,     0,     0,     0,     0,     0,   196,     0,
     198,     0,   200,     0,    44,    46,     0,    47,     0,   103,
       0,     0,     0,     0,     0,    52,   202,   204,   206,    48,
      50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    61,   668,    62,    63,   404,   985,   991,
     593,   760,  1119,  1240,   594,  1208,  1266,   595,  1242,   596,
     597,   764,   598,   127,   220,    64,   521,   549,   310,   534,
     535,   311,    68,    69,    70,    71,    72,   312,   732,  1180,
    1223,   550,  1037,  1040,  1043,  1046,  1192,  1196,  1200,  1232,
    1235,  1238,   728,   729,    74,    75,    76,   330,   130,   348,
     172,   883,   884,   332,   315,   197,   663,   794,   212,   213
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1068
static const yytype_int16 yypact[] =
{
    3165,    37,    47,  3242, -1068, -1068,  2261,    12,    21,   -53,
      -2,    74,    36,    55,    65,   -39,   160,   185,   -20,   188,
     192,    46,   -16,   104,   161,   292,   330,   352,   627,   280,
     287,   -52,   -52,   323,   373,    11,   375,    18,   454,   253,
     467,   473,   477,   347,   354,   362,    19,    20, -1068,   372,
   -1068,   514,   430,   437,   451,   460, -1068,   536,    27,    16,
      23, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068,
   -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068,    15,    22,
      35, -1068, -1068, -1068,   140,   169,   205,   320,   329,   339,
     405,   409,   426,   440,   464,   487,   503,   525,   535,   546,
     550,   570,   573,   603,   610,   416,   433,   439,   443, -1068,
     465, -1068, -1068, -1068, -1068, -1068, -1068, -1068,  2472,  2472,
    2472, -1068, -1068,  2472,  2019,   112,   615,  2472,   622,  1165,
   -1068,   631,   635,  2472,   609, -1068,  2472, -1068,  2472,  2401,
    2472,  2472,   483,  2472,  2401,  2472,  2472,   507,  2401,  2472,
    2472,  1384,   512,  2472,   515,   528,   529,  1676,   531,   544,
     563,   576,   577,   583,   595,   700,   -52,   -52,   -52,  2472,
    2472,   189, -1068,   222,   -52,   597,   600,   611,   618,  2226,
     247,   602, -1068,  1676,    31, -1068, -1068,  1540,  1676,   638,
     654,   742,  2472,  2472,  2472,   644,  2472,   656,   703,  2472,
    2472, -1068,   693,   705,   706,   709,   809, -1068,   710, -1068,
   -1068, -1068,   823, -1068, -1068,   843,   711,  2472,   847,   708,
   -1068,   -52, -1068,   849,  2472,  2472,  2472,  2472,  2472,  2472,
    2472,  2472,  2472,  2472,  2472,  2472,  2472,  2472,  2472,  2472,
    2472,  2472,  2472,  2472,  2472,  2472,  2472,  2472,  2472,  2472,
    2472,  2472,  2472,  2472,  2472,  2472,  2472,  2472,  2472,  2472,
    2472,  2472,  2472,  2472,  2472,  2472,   397,   557,   557,   557,
     851,   560,   721,   721,   721,  5465,    29,  2401,  3253,   291,
     717,   854,   726,  1310, -1068, -1068,  2472,  2472,  2472,  2472,
    2472,  2472,  2472,  2472,  2472,  2472,  2472,  2472,  2472,  2472,
    2472, -1068, -1068,  1348,   -97,  3998,  5486,   604,   722,  2401,
   -1068, -1068, -1068,  1411, -1068,   278,  5507,  5528,  2472,  5549,
     387,  5570,  5591,  2472,   608,  5612,  5633,  1676,  1812,  1239,
    1603,   860, -1068,  2472,  5654,  2472,  2472,  2472,   863,  2472,
    2472,  2472,  2531,  2531,  2531,  2531,   733,   388, -1068, -1068,
    4024,  4050,   -52,   -52,   614,   614,   429,  2472,  2472,  2472,
    2472,  2226,  2226,  2472,  3310,   441, -1068,  2472,   947,    60,
     866, -1068,  2472,  2574,   736,   867,   870,  2472,  2472, -1068,
    5675,  5696,  5717,   787,  4076, -1068,   735,  1739,  5738,  2472,
    2472,  2472,  2472, -1068,  2472,  2639, -1068,  2704, -1068,  2472,
    4752,   180,  2472,   255,     7, -1068,  5759,  4775,  5780,  4798,
    5801,  4821,  5822,  4844,  5843,  4867,  5864,  4890,  5885,  4913,
    5906,  4936,  5927,  4959,  5948,  4982,  5969,  5005,  4102,  4128,
    5990,  5028,  6011,  5051,  6032,  5074,  6053,  5097,  6074,  5120,
    6095,  5143,  4154,  4180,  4206,  4232,  4258,  4284,   613,   -57,
     752,   758,   760,   757,  2472, -1068,  1676,  1676,   616,   186,
      35,  2472,   896,   899,    25,   765, -1068,  1875,  1200,  1217,
     598,   598,   367,   367,   367,   367,   567,   567,   721,   721,
     721,   721, -1068,     1,  2401,  2472,   900,  2084,  2472,   721,
   -1068,  2472,  2401,  2401,   816,   904,   905,  6116,   907,   821,
     909,   910,  6137,   824,   912,   915,   917,  2401, -1068,   624,
    1948,  2472,  6158,   919,  1467,  6179,  6200,  2472,  3062,  3384,
    6221,   768,  6599, -1068,   786,   789,   790,   788,   -52,  2472,
    2472, -1068, -1068, -1068,   785,  3310, -1068,   791,  2472,  5166,
    4310,  4336,  4362,  3972,    38,    -7,    52,   136,   832, -1068,
     141,   -52,  2769,  5189, -1068, -1068,  2472, -1068,  5212, -1068,
    2472,  1676,  1676,  5235,  5258,   925,   926,   930,   797,  2472,
    2834,  2472,  2472, -1068,  6242,  6263,  6284,  6305,  6326, -1068,
   -1068,  5281,    64, -1068,  3412, -1068, -1068,   802,   803,   798,
   -1068,   804,   939, -1068, -1068, -1068, -1068, -1068, -1068, -1068,
   -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068,
   -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068,
   -1068,  2472,  2472, -1068, -1068, -1068, -1068, -1068, -1068, -1068,
   -1068, -1068, -1068, -1068, -1068,  2472,  2472,  2472,  2472,  2472,
    2472,  2472,   942, -1068,  2401,   557, -1068, -1068,  2472,  5304,
     941,   945,   813, -1068,   123,  2472,   948,   949,  1502, -1068,
     950,   817,    19,   955, -1068,  2472, -1068,   839,   557,   133,
    4388,   -52, -1068,  2401,  3440,  3011,   721, -1068,  1411, -1068,
     931,  1676,  1676,   974,  1676,   719,  1676,  1676,   978,   935,
    1676,  1676, -1068,   629, -1068,  2401,  1638,   980,   844,   982,
     995,   998,   848,  1001,  1002,  1003,  1006,  1007,  1008,  1009,
    1013,   461,  4414,  4440, -1068, -1068,  3468,   874,   -52,   -52,
     -52,  2401,  2401,  2401,  2401,  1014,   875,   884,   -38, -1068,
     470, -1068,   141,  1017,  1774,  1018,  6347,  1019,  1020,  1021,
    1022,  1676,  1676,  1676,  1026,  4466, -1068,  3032,  1078,  1024,
    1025,  1029,  1030,  1031,  1033,  1036, -1068,  1035, -1068,    13,
     906,  2472,  2472,  1676,   898,  2472, -1068,  6368,  5327,  6389,
    5350,  6410,  5373,  6431,  5396,  5419,   908,   252,   914,  6452,
     279, -1068, -1068,   152,   358,   903,  1038,  2048, -1068, -1068,
   -1068,    19,  2472, -1068,   630, -1068,  6599, -1068,  1050,     8,
    2472,    44,   633, -1068,  2472,   913,    73,   145,  1676,  1052,
     916,   918,  1053,  1055,  1676,   921,  1057,  1060, -1068,   637,
   -1068,  1062,  2472,  1676,  1676,  1676, -1068,   306,  1676,  1676,
    1676,  1676,  1676,  1676,  1676,   599,  2472,  2472,  2472,   924,
   -1068,   284,   319,   400,   641,   645,   646,   649, -1068,  1676,
    2472, -1068, -1068,  2226,   -28, -1068, -1068, -1068,  1063, -1068,
   -1068, -1068, -1068,  1065,  1066,   983, -1068,  2472,  2472,  2472,
   -1068,  1676,  1069,  2472,  2472,  1070, -1068,   180, -1068,  1071,
    2472,  4492,  4518,   653, -1068,  2472,  6473, -1068, -1068, -1068,
   -1068, -1068, -1068, -1068, -1068,   937, -1068, -1068, -1068, -1068,
    1676,    35,  2472,  1073,  1072,    25, -1068,  1074,  5442,    19,
   -1068, -1068, -1068,   557,  4544, -1068,   951,  6599,  2472, -1068,
     -52, -1068,   -52,  1075, -1068,  2472,  2472, -1068, -1068,  1076,
    2472, -1068, -1068, -1068,  1083,  4570,  1089,  1090,  1091,  2472,
    2472,   812,  1093,  1095,  1097,  1099,  1100,  1101, -1068,  2531,
    3496,  6494,  3300,   614,  3310,   -52,  1103,   -52,  1105,   -52,
    1106,  1107,  1108,  1109,  1112,   683,   976,  6515,  3524,   482,
   -1068,  1676, -1068, -1068,  1676,  3328,   763,  6536,  1114,  1115,
    2186,  2327,  1676, -1068, -1068,   272,  6599,  2472,  2472,  1676,
     979,   677,  6599,  1676,  1118,  1120,  1121,  2582, -1068,  1117,
    1122, -1068,   988, -1068,  1124,  2472, -1068,  3552,    51,    57,
   -1068,  3580,  3608, -1068,  3636,  1126,  2472, -1068, -1068, -1068,
    2647,  2842,  1128, -1068, -1068, -1068, -1068, -1068, -1068, -1068,
    2907,  1129,   992, -1068,  2472, -1068,   987,   141,   484, -1068,
     993,   495, -1068,   994,   518, -1068,   996, -1068, -1068, -1068,
   -1068,  1133,  1676,  1134,   999,  2472,  1136,  1058,  2472, -1068,
    2472, -1068, -1068, -1068, -1068, -1068, -1068,  1142, -1068,  2472,
    4596,  4622, -1068,  1676,  2472,  1143,  1145,  1016, -1068, -1068,
   -1068,    19, -1068,  1064, -1068,  4648,  1149, -1068, -1068,  1151,
    1152,  1153,  1154,  4674, -1068, -1068, -1068, -1068, -1068,   614,
    3356, -1068,    32,  2226,   141,  2226,   141,  2226,   141, -1068,
     678,  1676, -1068,  3664, -1068,  2472,  3692,  3720, -1068,  1023,
    6599,  2472,  2472,   681,  6599, -1068, -1068, -1068,  1155, -1068,
    2472, -1068, -1068, -1068, -1068, -1068,  1157,  1027,  2472, -1068,
   -1068,  3748,   520,   198,  3776,   524,   233,  3804,   526,   235,
    1676,  1158,  1113,  2899,  1032,  2969, -1068, -1068,  2472,  6557,
    4700,    24, -1068,  4726,  1034, -1068,  3832,  1162,  2472,  1164,
    1169,  2472,  1172,  1173,  2472,  1175,  1037, -1068,  2472, -1068,
     141, -1068, -1068,   682, -1068,  2472, -1068,  1676,  2472,  1179,
   -1068, -1068,  1042,  3860, -1068, -1068,  1044,  3888, -1068, -1068,
    1046,  3916, -1068,  1185,  2992,   316,  2964,  1186,  1068,  6578,
     691,  3944,  1051,   141,  1204,   141,  1209,   141,  1212, -1068,
   -1068, -1068, -1068,   141, -1068,   557, -1068,  1077,  1213,  1215,
     366, -1068,  1079,   368, -1068,  1080,   376, -1068,  1081,   378,
     692, -1068,  1085,  1676, -1068,  1094,  1216,   141,  1224,   141,
    1232,   141, -1068,   557,  1234,   557,   695,  1235, -1068,   393,
   -1068,   413, -1068,   442, -1068, -1068,   696, -1068,  1238, -1068,
    1240,  1241,  1245,   557,  1269, -1068, -1068, -1068, -1068, -1068,
   -1068
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1068, -1068, -1068, -1068,   446, -1068, -1068,   694, -1068,   118,
   -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068,
   -1068, -1068, -1068,  -276,    -1, -1068,  -233,  1274,     5,  -353,
    -169,     9, -1068, -1068, -1068, -1068, -1068,  1275, -1068, -1068,
   -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068, -1068,
   -1068, -1068,  -676,  -528, -1068, -1068, -1068,    -5, -1068,   230,
   -1068, -1067,   403,    42,   -66,  -644,   392, -1068,   -60,     3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     215,   129,   537,   461,   135,   128,  1123,   666,    66,   131,
     364,   586,    67,   368,   912,   181,   373,   586,   793,   216,
     209,   210,   184,   195,   198,   132,   221,   209,   210,   661,
    1186,   207,   142,   152,   725,   370,   456,   371,   726,   727,
     210,   483,   395,     4,   725,   397,   484,     5,   726,   727,
     915,   147,   105,   106,   107,   108,   854,  1087,   109,   105,
     106,   107,   108,  1088,   142,   109,   555,   556,   209,   210,
     133,   105,   106,   107,   108,   167,   168,   109,   320,   919,
     137,   643,   324,   223,   134,   169,   644,   587,   588,   589,
     590,   591,   170,   587,   588,   589,   590,   591,   143,   151,
     105,   106,   107,   108,   725,   144,   109,   851,   726,   727,
     524,   525,   526,   272,   273,   274,   279,   970,   275,   278,
    1210,   153,   283,   147,   148,   667,   208,   784,   303,   920,
     143,   305,   667,   306,   313,   316,   317,   722,   319,   313,
     321,   322,   136,   313,   325,   326,   457,   907,   334,   121,
     122,   921,   592,   154,   217,   182,   218,   199,   879,   653,
     211,   219,   185,   196,   350,   351,   222,   214,  1187,   662,
     372,   352,   353,   138,   351,   138,  1256,  1140,   352,   353,
     139,   314,   721,   655,   352,   353,   314,   380,   381,   382,
     314,   384,   140,   653,   387,   388,   723,   552,   121,   122,
     852,   922,   141,   280,   281,   755,   449,   450,   451,   452,
     155,   458,   400,   725,   785,   786,   570,   726,   727,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   171,   173,   509,   180,  1003,   114,   115,   116,   117,
     725,   799,   313,   150,   726,   727,   493,   224,   462,   225,
     724,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   187,   145,   460,   188,
     114,   115,   116,   117,   489,   725,   226,   725,   227,   726,
     727,   726,   727,   497,   121,   122,   352,   353,   502,   314,
     121,   122,   146,   489,   313,   149,   852,   654,   512,   150,
     514,   515,   516,   354,   518,   519,   520,   522,   522,   522,
     522,   156,   228,  1169,   229,   523,   523,   523,   523,   352,
     353,   490,   539,   540,   541,   542,   272,   273,   543,   533,
     533,  1102,   553,   536,   536,   901,   355,   558,   939,   940,
     490,   314,   563,   564,   352,   353,   157,   175,  1172,   158,
    1175,   159,   352,   353,   574,   575,   576,   577,   725,   578,
     897,   366,   726,   727,   581,   493,   347,   584,   349,   585,
     583,   448,   210,   160,   356,   114,   115,   116,   117,   365,
    1068,   352,   353,   121,   122,  1069,   176,   165,   669,   177,
     755,   493,   178,   494,   183,   121,   122,   955,  1143,   956,
    1146,   166,  1149,   105,   106,   107,   108,  1128,   725,   109,
     725,   693,   726,   727,   726,   727,   352,   353,   725,   649,
     725,   403,   726,   727,   726,   727,   658,   230,   656,   231,
     186,  1221,   957,   657,   958,   725,   232,   174,   233,   726,
     727,   189,   114,   115,   116,   117,   234,   190,   235,   313,
     670,   191,   649,   674,   192,   725,   675,   676,   678,   726,
     727,   193,   121,   122,   295,   296,   297,   298,   299,   194,
     167,   168,   313,   300,  1205,   676,   696,   900,   902,   200,
     169,  1246,   702,  1248,   725,   352,   353,   179,   726,   727,
     201,  1250,   757,  1252,   712,   713,   314,   352,   353,   202,
     493,   528,   499,   716,   677,   679,   203,  1230,  1270,  1233,
     206,  1236,   236,   959,   237,   960,   238,  1239,   239,   314,
     204,   734,   677,   266,   331,   736,   352,   353,  1271,   205,
     338,   209,   210,   240,   745,   241,   747,   748,   352,   353,
     267,  1259,   538,  1261,   852,  1263,   268,   242,   777,   243,
     269,   756,   531,   532,   551,   778,   369,  1272,   352,   353,
     375,   376,   349,   105,   106,   107,   108,   352,   353,   109,
    1036,   244,   270,   245,   836,   948,   949,   802,   798,   352,
     353,   352,   353,   853,   304,   852,   767,   768,   852,   282,
     318,   852,   352,   353,   246,  1055,   247,  1103,   284,   819,
     769,   770,   771,   772,   773,   774,   775,   301,  1105,   313,
     248,   302,   249,   779,   323,   352,   353,   352,   353,   333,
     787,   352,   353,   352,   353,   844,   845,   846,   847,   335,
     796,  1107,   250,  1168,   251,   336,   337,  1171,   313,  1174,
     161,   954,   252,   162,   253,   339,   163,   852,   164,    30,
      31,    32,    33,   254,    35,   255,   314,   256,   340,   257,
     313,   491,    40,    41,   121,   122,   297,   298,   299,   454,
     341,   218,   852,   300,   346,   852,   219,   258,   852,   259,
     260,   852,   261,   342,   343,   314,   313,   313,   313,   313,
     344,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     506,   852,   345,   852,   300,   852,   357,   314,   121,   122,
     262,   367,   263,   487,   358,   218,  1137,   264,   379,   265,
     219,   493,   641,   503,   642,   359,   881,   882,   711,   493,
     886,   652,   360,   314,   314,   314,   314,   493,   810,   694,
     811,  1060,   493,   909,   818,   910,   493,   377,   916,   756,
     493,   730,   933,   903,   493,   383,   961,   908,   493,   493,
     962,   963,   493,   378,   964,   914,   989,   386,   990,   917,
     385,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   510,   298,   299,   393,  1022,   935,  1023,   300,
    1074,  1150,  1075,  1151,   989,  1074,  1161,  1207,  1051,   396,
     389,   950,   951,   952,   989,  1253,  1227,  1254,   989,  1273,
    1268,  1274,   390,   391,   965,   967,   392,   394,   968,   398,
     399,   401,   402,  1004,   826,   405,   453,   300,   463,   650,
     651,   464,   975,   976,   977,   465,   488,   511,   980,   981,
     517,   527,   557,   560,   561,   986,   983,   562,   568,   571,
     992,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   645,   646,   997,   647,   300,
     648,   801,   659,   660,   996,   664,   706,   671,  1061,   827,
     680,   681,   682,  1007,   684,   685,   686,   687,   689,   690,
    1011,  1012,   691,   692,   707,  1014,   698,   708,   709,   710,
     714,   208,   741,   742,  1020,  1021,   715,   743,   744,   761,
     762,   765,   763,  1153,  1030,   766,   776,   781,   841,   842,
     843,   782,  1031,   783,   788,   789,   792,   791,   533,     7,
       8,   795,   536,   797,   737,   738,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     805,   808,  1070,  1071,   300,   814,   815,   821,   822,   823,
     544,    13,    14,   545,    16,    17,   546,    19,   547,    21,
    1085,    22,   824,    24,    25,   825,    27,    28,   828,   829,
     830,  1093,  1206,   831,   832,   833,   834,   835,   840,   849,
     848,   850,    39,   855,   857,   859,   860,   861,   862,  1100,
     866,   871,   872,    43,    44,    45,   873,   874,   875,   876,
     877,   878,   885,   880,   904,   905,   896,    52,    53,    54,
    1113,    55,   898,  1116,   548,  1117,   911,   918,   924,   927,
     925,   928,   926,   931,  1120,   930,   932,   934,   953,  1124,
     971,   972,   973,   974,   979,   982,   999,   984,   994,   998,
    1001,  1010,  1013,   969,   806,   807,   869,   809,  1015,   812,
     813,  1006,   554,   816,   817,  1017,  1018,  1019,  1141,  1024,
    1144,  1025,  1147,  1026,   533,  1027,  1028,  1029,   536,  1039,
    1155,  1042,  1045,  1047,  1048,  1049,  1159,  1160,  1050,  1052,
    1063,  1064,  1077,  1073,  1081,  1163,  1078,  1079,  1082,  1083,
    1084,  1092,  1101,  1166,  1096,  1098,  1099,  1104,  1106,  1109,
    1108,  1111,  1114,  1112,   863,   864,   865,  1115,  1118,  1125,
    1008,  1126,  1009,   992,  1127,  1131,  1129,  1132,  1133,  1134,
    1135,  1162,  1164,  1193,  1177,  1241,  1197,  1158,  1191,  1201,
    1194,   285,  1165,  1204,  1178,  1195,  1181,  1189,  1198,  1199,
    1209,  1202,  1203,  1211,  1212,  1038,  1213,  1041,  1215,  1044,
    1217,  1219,  1224,  1264,  1229,  1267,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
    1231,   923,  1225,  1279,   300,  1234,   870,   929,  1237,  1244,
    1245,  1243,  1258,  1247,  1249,  1251,   936,   937,   938,  1255,
    1260,   941,   942,   943,   944,   945,   946,   947,  1262,  1257,
    1265,  1269,    77,   307,  1275,   913,  1276,  1277,    81,    82,
      83,  1278,   966,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   978,  1280,  1183,    65,    73,   759,
       0,     0,   308,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,  1000,     0,     0,
       0,   300,     0,   995,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,   466,    40,    41,     0,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,  1142,     0,  1145,   300,  1148,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   110,
     111,   112,   113,   300,   482,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,   309,     0,     0,
       0,   120,     0,     0,  1056,     0,   123,  1057,     0,     0,
       0,   126,     0,     0,   508,  1067,     0,    77,   307,     0,
       0,     0,  1072,    81,    82,    83,  1076,     0,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   491,
       0,     0,     0,     0,     0,     0,     0,   308,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,    30,
      31,    32,    33,    34,    35,  1110,     0,     0,     0,     0,
       0,     0,    40,    41,     0,     0,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,   327,   300,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,   111,   112,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   790,     0,
       0,   118,   328,     0,  1152,     0,   120,     0,     0,     0,
       0,   123,     0,     0,     0,     0,   126,     0,   329,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     492,   298,   299,    77,   307,     0,     0,   300,     0,    81,
      82,    83,     0,  1176,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,   308,     0,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,     0,
       0,     0,     0,   300,     0,    30,    31,    32,    33,    34,
      35,   491,   699,     0,     0,     0,     0,     0,    40,    41,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,   374,
       0,     0,     0,     0,   820,     0,     0,     0,     0,     0,
     110,   111,   112,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,   328,     0,
       0,     0,   120,     0,     0,     0,     0,   123,     0,    77,
     307,     0,   126,     0,   329,    81,    82,    83,     0,     0,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,   308,
       0,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   510,   298,   299,     0,     0,     0,     0,   300,
       0,    30,    31,    32,    33,    34,    35,   572,     0,     0,
       0,     0,     0,     0,    40,    41,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
     856,     0,     0,     0,     0,     0,   110,   111,   112,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   118,   328,     0,     0,     0,   120,     0,
       0,     0,     0,   123,     0,    77,   307,     0,   126,     0,
     329,    81,    82,    83,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,   308,     0,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,     0,     0,     0,     0,   300,     0,    30,    31,    32,
      33,    34,    35,   665,     0,     0,     0,     0,     0,     0,
      40,    41,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   111,   112,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     309,     0,     0,     0,   120,     0,     0,     0,     0,   123,
       0,    77,   307,     0,   126,     0,   507,    81,    82,    83,
       0,     0,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,   308,     0,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,     0,     0,     0,
       0,   300,     0,    30,    31,    32,    33,    34,    35,     0,
       0,     0,    77,   271,     0,     0,    40,    41,    81,    82,
      83,     0,     0,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   906,     0,     0,     0,   110,   111,
     112,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,   309,     0,     0,     0,
     120,     0,     0,     0,     0,   123,     0,    77,   271,     0,
     126,     0,   695,    81,    82,    83,     0,     0,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   112,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,   119,     0,     0,
       0,   120,     0,     0,     0,     0,   123,     0,     0,   276,
       0,   126,     0,   277,     0,     0,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,     0,  1065,     0,   110,   111,   112,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,   119,     0,     0,     0,   120,     0,     0,     0,
       0,   123,     0,     0,   672,     0,   126,     0,   673,    77,
     271,     0,     0,     0,     0,    81,    82,    83,     0,     0,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,    77,    78,    79,     0,    80,     0,
      81,    82,    83,     0,     0,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,   106,   107,
     108,     0,     0,   109,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1066,     0,     0,   110,   111,   112,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   361,   362,     0,     0,     0,   120,     0,
       0,     0,     0,   363,     0,     0,     0,     0,   126,     0,
     170,   110,   111,   112,   113,   114,   115,   116,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,   119,
       0,     0,     0,   120,     0,   121,   122,     0,   123,     0,
     124,     0,   125,   126,    77,   307,     0,     0,     0,     0,
      81,    82,    83,     0,     0,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,     0,     0,
       0,     0,     0,     0,   308,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,     0,
       0,     0,     0,   300,     0,     0,    30,    31,    32,    33,
      34,    35,     0,     0,     0,    77,   271,     0,     0,    40,
      41,    81,    82,    83,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,     0,     0,
       0,   110,   111,   112,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,   309,
       0,     0,     0,   120,    77,   271,   210,     0,   123,     0,
      81,    82,    83,   126,     0,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,   106,   107,
     108,     0,     0,   109,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   111,   112,   113,     7,     8,  1080,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,     0,     0,     0,   120,     0,     0,     0,     0,   123,
       0,     0,     0,     0,   126,     0,     0,   544,    13,    14,
     545,    16,    17,   546,    19,   547,    21,     0,    22,     0,
      24,    25,     0,    27,    28,     0,     0,     0,     0,     0,
       0,   110,   111,   112,   113,     0,     0,     0,     0,    39,
       0,     7,     8,  1094,     0,     0,     0,     0,   118,   119,
      43,    44,    45,   120,     0,     0,     0,     0,   123,     0,
       0,     0,     0,   126,    52,    53,    54,     0,    55,     0,
       0,   548,   544,    13,    14,   545,    16,    17,   546,    19,
     547,    21,     0,    22,     0,    24,    25,     0,    27,    28,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,    39,     0,     7,     8,   300,   559,
       0,     0,     0,     0,     0,    43,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,     0,    55,     0,     0,   548,   544,    13,    14,
     545,    16,    17,   546,    19,   547,    21,     0,    22,     0,
      24,    25,     0,    27,    28,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,    39,
       0,     7,     8,   300,   579,     0,     0,     0,     0,     0,
      43,    44,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,     0,    55,     0,
       0,   548,   544,    13,    14,   545,    16,    17,   546,    19,
     547,    21,     0,    22,     0,    24,    25,     0,    27,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,     7,     8,  1095,   580,
       0,     0,     0,     0,     0,    43,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,     0,    55,     0,     0,   548,   544,    13,    14,
     545,    16,    17,   546,    19,   547,    21,     0,    22,     0,
      24,    25,     0,    27,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,     7,     8,  1097,   731,     0,     0,     0,     0,     0,
      43,    44,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,     0,    55,     0,
       0,   548,   544,    13,    14,   545,    16,    17,   546,    19,
     547,    21,     0,    22,     0,    24,    25,     0,    27,    28,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,    39,  1182,     7,     8,   300,   746,
       0,     0,     0,     0,     0,    43,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1220,    52,
      53,    54,     0,    55,     0,     0,   548,   544,    13,    14,
     545,    16,    17,   546,    19,   547,    21,     0,    22,   804,
      24,    25,     0,    27,    28,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,    39,
     868,     0,     0,   300,  1179,     0,     0,     0,     0,     0,
      43,    44,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,     0,    55,     0,
       0,   548,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,     0,     0,     0,     0,   300,     0,     0,     0,  1222,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,     0,     0,     0,     0,   300,     0,     0,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,    -4,     1,     0,   300,    -4,
       0,     0,     0,     0,     0,     0,     0,    -4,    -4,     0,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
      -4,     0,     0,     0,     0,    -4,    -4,   703,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,     0,     0,    -4,    -4,     0,     6,     0,     0,     0,
      -4,    -4,    -4,    -4,     7,     8,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     9,     0,     0,
       0,     0,    10,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,    34,    35,     0,    36,    37,    38,    39,     0,     0,
      40,    41,     7,     8,     0,     0,     0,    42,    43,    44,
      45,     0,     0,    46,     0,    47,     0,    48,    49,    50,
      51,     0,    52,    53,    54,     0,    55,    56,    57,    58,
      59,    60,     0,   544,    13,    14,   545,    16,    17,   546,
      19,   547,    21,     0,    22,     0,    24,    25,     0,    27,
      28,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    39,     0,     0,     0,   300,
       0,     0,     0,   459,     0,     0,    43,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    53,    54,     0,    55,     0,     0,   548,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,  1034,     0,  1035,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,  1058,     0,  1059,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,  1138,
       0,  1139,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,     0,     0,     0,   704,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
       0,     0,     0,     0,     0,     0,     0,   758,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,     0,     0,   803,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,     0,     0,   839,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,     0,
       0,  1032,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,     0,     0,     0,  1054,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
       0,     0,     0,     0,     0,     0,     0,  1086,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,     0,     0,  1089,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,     0,     0,  1090,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,     0,
       0,  1091,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,     0,     0,     0,  1154,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
       0,     0,     0,     0,     0,     0,     0,  1156,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,     0,     0,  1157,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,     0,     0,  1167,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,     0,
       0,  1170,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,     0,     0,     0,  1173,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
       0,     0,     0,     0,     0,     0,     0,  1190,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,     0,     0,  1214,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,     0,     0,  1216,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,     0,
       0,  1218,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,     0,     0,     0,  1228,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
     455,     0,     0,     0,     0,   529,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,   485,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,     0,   529,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,   530,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,   569,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
       0,     0,     0,     0,     0,   621,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,   622,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,     0,   635,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,   636,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,   637,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
       0,     0,     0,     0,     0,   638,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,   639,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,     0,   640,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,   718,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,   719,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
       0,     0,     0,     0,     0,   720,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,   800,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,     0,   837,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,   838,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,   867,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
       0,     0,     0,     0,     0,   987,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,   988,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,     0,  1005,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,  1016,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,  1121,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
       0,     0,     0,     0,     0,  1122,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,  1130,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,     0,  1136,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,  1185,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,  1188,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
       0,     0,   582,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,     0,     0,     0,
       0,   300,     0,     0,     0,   600,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,   602,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,     0,     0,     0,     0,   300,     0,     0,
       0,   604,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,   606,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,     0,
       0,     0,     0,   300,     0,     0,     0,   608,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,     0,
     610,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,     0,     0,     0,     0,   300,
       0,     0,     0,   612,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,   614,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,     0,     0,     0,     0,   300,     0,     0,     0,   616,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
       0,     0,   618,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,     0,     0,     0,
       0,   300,     0,     0,     0,   620,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,   624,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,     0,     0,     0,     0,   300,     0,     0,
       0,   626,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,   628,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,     0,
       0,     0,     0,   300,     0,     0,     0,   630,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,     0,
     632,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,     0,     0,     0,     0,   300,
       0,     0,     0,   634,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,   717,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,     0,     0,     0,     0,   300,     0,     0,     0,   733,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
       0,     0,   735,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,     0,     0,     0,
       0,   300,     0,     0,     0,   739,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,     0,     0,   740,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,     0,     0,     0,     0,   300,     0,     0,
       0,   754,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,     0,     0,   780,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,     0,
       0,     0,     0,   300,     0,     0,     0,   888,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,     0,     0,
     890,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,     0,     0,     0,     0,   300,
       0,     0,     0,   892,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,     0,     0,   894,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,     0,     0,     0,     0,   300,     0,     0,     0,   895,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
       0,     0,  1002,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,     0,     0,     0,
       0,   300,     0,   455,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,   486,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,     0,
       0,     0,     0,   300,     0,   495,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,   496,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,     0,     0,     0,     0,   300,     0,   498,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,   500,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,     0,     0,     0,     0,   300,     0,   501,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
     504,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,     0,     0,     0,     0,   300,
       0,   505,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,   513,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,     0,     0,     0,
       0,   300,     0,   565,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,   566,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,     0,
       0,     0,     0,   300,     0,   567,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,   573,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,     0,     0,     0,     0,   300,     0,   599,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,   601,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,     0,     0,     0,     0,   300,     0,   603,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
     605,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,     0,     0,     0,     0,   300,
       0,   607,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,   609,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,     0,     0,     0,
       0,   300,     0,   611,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,   613,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,     0,
       0,     0,     0,   300,     0,   615,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,   617,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,     0,     0,     0,     0,   300,     0,   619,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,   623,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,     0,     0,     0,     0,   300,     0,   625,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
     627,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,     0,     0,     0,     0,   300,
       0,   629,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,   631,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,     0,     0,     0,
       0,   300,     0,   633,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,   683,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,     0,
       0,     0,     0,   300,     0,   688,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,   697,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,     0,     0,     0,     0,   300,     0,   700,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,   701,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,     0,     0,     0,     0,   300,     0,   705,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
     749,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,     0,     0,     0,     0,   300,
       0,   750,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,   751,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,     0,     0,     0,
       0,   300,     0,   752,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,   753,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,     0,
       0,     0,     0,   300,     0,   858,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,   887,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,     0,     0,     0,     0,   300,     0,   889,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,   300,     0,   891,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,     0,     0,     0,     0,   300,     0,   893,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,   300,     0,
     899,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,     0,     0,     0,     0,   300,
       0,   993,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,     0,     0,     0,     0,
     300,     0,  1033,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,     0,     0,     0,
       0,   300,     0,  1053,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,   300,     0,  1062,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,     0,
       0,     0,     0,   300,     0,  1184,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,  1226,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,     0,     0,     0,     0,   300
};

static const yytype_int16 yycheck[] =
{
      60,     6,   355,   279,     6,     6,  1073,     6,     3,     6,
     179,     4,     3,   182,     6,     4,   185,     4,   662,     4,
       4,     5,     4,     4,     4,    13,     4,     4,     5,     4,
       6,     4,    71,    49,    72,     4,     7,     6,    76,    77,
       5,   138,   211,     6,    72,   214,   143,     0,    76,    77,
       6,    71,    36,    37,    38,    39,   732,     6,    42,    36,
      37,    38,    39,     6,    71,    42,     6,     7,     4,     5,
      49,    36,    37,    38,    39,   127,   128,    42,   144,     6,
       6,   138,   148,    80,   137,   137,   143,    80,    81,    82,
      83,    84,   144,    80,    81,    82,    83,    84,   137,    53,
      36,    37,    38,    39,    72,   144,    42,   145,    76,    77,
     343,   344,   345,   118,   119,   120,     4,   145,   123,   124,
    1187,   137,   127,    71,   144,   124,    99,     4,   133,    56,
     137,   136,   124,   138,   139,   140,   141,   144,   143,   144,
     145,   146,   144,   148,   149,   150,   117,   791,   153,   134,
     135,     6,   145,    49,   139,   144,   141,   137,   145,     7,
     144,   146,   144,   144,   169,   170,   144,   144,   144,   144,
     139,   127,   128,   137,   179,   137,  1243,   145,   127,   128,
     144,   139,   144,   459,   127,   128,   144,   192,   193,   194,
     148,   196,   137,     7,   199,   200,   144,   366,   134,   135,
     728,    56,   137,    91,    92,   141,   266,   267,   268,   269,
      49,   277,   217,    72,    91,    92,   385,    76,    77,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    31,    32,   329,    34,   909,   114,   115,   116,   117,
      72,   138,   277,   137,    76,    77,   143,   137,   279,   139,
     144,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    43,   137,     7,    46,
     114,   115,   116,   117,   309,    72,   137,    72,   139,    76,
      77,    76,    77,   318,   134,   135,   127,   128,   323,   277,
     134,   135,   137,   328,   329,   137,   854,   141,   333,   137,
     335,   336,   337,   144,   339,   340,   341,   342,   343,   344,
     345,    49,   137,   145,   139,   342,   343,   344,   345,   127,
     128,   309,   357,   358,   359,   360,   361,   362,   363,   354,
     355,  1037,   367,   354,   355,     7,   144,   372,    62,    63,
     328,   329,   377,   378,   127,   128,    46,     4,   145,    49,
     145,    51,   127,   128,   389,   390,   391,   392,    72,   394,
     138,   144,    76,    77,   399,   143,   166,   402,   168,   144,
     401,     4,     5,    51,   174,   114,   115,   116,   117,   179,
     138,   127,   128,   134,   135,   143,    43,   137,   484,    46,
     141,   143,    49,   145,    49,   134,   135,   143,  1104,   145,
    1106,   144,  1108,    36,    37,    38,    39,  1081,    72,    42,
      72,   507,    76,    77,    76,    77,   127,   128,    72,   454,
      72,   221,    76,    77,    76,    77,   461,   137,   459,   139,
       6,   145,   143,   460,   145,    72,   137,   144,   139,    76,
      77,     4,   114,   115,   116,   117,   137,     4,   139,   484,
     485,     4,   487,   488,   137,    72,   491,   492,   493,    76,
      77,   137,   134,   135,   127,   128,   129,   130,   131,   137,
     127,   128,   507,   136,  1180,   510,   511,   783,   784,   137,
     137,   145,   517,   145,    72,   127,   128,   144,    76,    77,
       6,   145,   582,   145,   529,   530,   484,   127,   128,    99,
     143,   143,   145,   538,   492,   493,    99,  1213,   145,  1215,
       4,  1217,   137,   143,   139,   145,   137,  1223,   139,   507,
      99,   556,   510,   137,   151,   560,   127,   128,   145,    99,
     157,     4,     5,   137,   569,   139,   571,   572,   127,   128,
     137,  1247,   143,  1249,  1102,  1251,   137,   137,   644,   139,
     137,   582,   352,   353,   143,   645,   183,   145,   127,   128,
     187,   188,   362,    36,    37,    38,    39,   127,   128,    42,
     953,   137,   137,   139,   143,     6,     7,   673,   668,   127,
     128,   127,   128,   143,     5,  1143,   621,   622,  1146,     4,
     137,  1149,   127,   128,   137,   143,   139,   143,     6,   695,
     635,   636,   637,   638,   639,   640,   641,     6,   143,   644,
     137,     6,   139,   648,   137,   127,   128,   127,   128,   137,
     655,   127,   128,   127,   128,   721,   722,   723,   724,   144,
     665,   143,   137,   143,   139,   137,   137,   143,   673,   143,
      43,   840,   137,    46,   139,   144,    49,  1205,    51,    65,
      66,    67,    68,   137,    70,   139,   644,   137,   144,   139,
     695,     8,    78,    79,   134,   135,   129,   130,   131,   139,
     137,   141,  1230,   136,     4,  1233,   146,   137,  1236,   139,
     137,  1239,   139,   137,   137,   673,   721,   722,   723,   724,
     137,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     327,  1259,   137,  1261,   136,  1263,   139,   695,   134,   135,
     137,   139,   139,   139,   144,   141,  1099,   137,     6,   139,
     146,   143,   139,   145,   141,   144,   761,   762,   528,   143,
     765,   145,   144,   721,   722,   723,   724,   143,    49,   145,
      51,     8,   143,   143,   145,   145,   143,   139,   145,   780,
     143,   551,   145,   784,   143,   141,   145,   792,   143,   143,
     145,   145,   143,   139,   145,   800,   143,    94,   145,   804,
     144,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     6,     4,   822,     6,   136,
     143,   143,   145,   145,   143,   143,   145,   145,   145,     6,
     137,   836,   837,   838,   143,   143,   145,   145,   143,   143,
     145,   145,   137,   137,   849,   850,   137,   137,   853,     6,
     139,     4,   144,   913,     6,     6,     5,   136,   141,   456,
     457,     7,   867,   868,   869,   139,   144,     7,   873,   874,
       7,   138,     6,   137,     7,   880,   877,     7,    91,   144,
     885,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   143,   138,   902,   138,   136,
     143,   671,     6,     4,   901,   140,   138,     7,   145,    61,
      94,     7,     7,   918,     7,    94,     7,     7,    94,     7,
     925,   926,     7,     6,   138,   930,     7,   138,   138,   141,
     145,    99,     7,     7,   939,   940,   145,     7,   141,   137,
     137,   137,   144,  1112,   949,     6,     4,     6,   718,   719,
     720,     6,   949,   140,     6,     6,   139,     7,   953,    12,
      13,     6,   953,   124,   561,   562,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      49,     7,   987,   988,   136,     7,    51,     7,   144,     7,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    1005,    54,     7,    56,    57,     7,    59,    60,     7,     7,
       7,  1016,  1181,     7,     7,     7,     7,     4,   144,   144,
       6,   137,    75,     6,     6,     6,     6,     6,     6,  1034,
       4,     7,     7,    86,    87,    88,     7,     7,     7,     6,
       4,     6,   144,   137,   141,     7,   138,   100,   101,   102,
    1055,   104,   138,  1058,   107,  1060,     6,   144,     6,     6,
     144,     6,   144,     6,  1069,   144,     6,     5,   144,  1074,
       7,     6,     6,    90,     5,     5,     4,     6,   141,     6,
       6,     6,     6,   853,   681,   682,     8,   684,     5,   686,
     687,   140,   145,   690,   691,     6,     6,     6,  1103,     6,
    1105,     6,  1107,     6,  1099,     6,     6,     6,  1099,     6,
    1115,     6,     6,     6,     6,     6,  1121,  1122,     6,   143,
       6,     6,     4,   144,     7,  1130,     6,     6,     6,   141,
       6,     5,   145,  1138,     6,     6,   144,   144,   144,     6,
     144,     7,     6,   144,   741,   742,   743,    89,     6,     6,
     920,     6,   922,  1158,   138,     6,    92,     6,     6,     6,
       6,     6,     5,  1168,     6,  1225,  1171,   144,     6,  1174,
       6,     6,   145,  1178,    61,     6,   144,   143,     6,     6,
    1185,     6,   145,  1188,     5,   955,   144,   957,   144,   959,
     144,     6,     6,  1253,   143,  1255,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
       6,   808,   144,  1273,   136,     6,   138,   814,     6,     6,
       5,   144,     6,   144,   144,   144,   823,   824,   825,   144,
       6,   828,   829,   830,   831,   832,   833,   834,     6,   145,
       6,     6,     3,     4,     6,   799,     6,     6,     9,    10,
      11,     6,   849,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,   871,     6,  1158,     3,     3,   585,
      -1,    -1,    43,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   905,    -1,    -1,
      -1,   136,    -1,   900,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    78,    79,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,  1103,    -1,  1105,   136,  1107,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   110,
     111,   112,   113,   136,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,    -1,
      -1,   132,    -1,    -1,   971,    -1,   137,   974,    -1,    -1,
      -1,   142,    -1,    -1,   145,   982,    -1,     3,     4,    -1,
      -1,    -1,   989,     9,    10,    11,   993,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    65,
      66,    67,    68,    69,    70,  1052,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    99,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,   127,   128,    -1,  1111,    -1,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,   142,    -1,   144,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,     3,     4,    -1,    -1,   136,    -1,     9,
      10,    11,    -1,  1150,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,   136,    -1,    65,    66,    67,    68,    69,
      70,     8,   145,    -1,    -1,    -1,    -1,    -1,    78,    79,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    99,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,
      -1,    -1,   132,    -1,    -1,    -1,    -1,   137,    -1,     3,
       4,    -1,   142,    -1,   144,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,
      -1,    65,    66,    67,    68,    69,    70,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,    -1,    -1,    -1,   132,    -1,
      -1,    -1,    -1,   137,    -1,     3,     4,    -1,   142,    -1,
     144,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,   136,    -1,    65,    66,    67,
      68,    69,    70,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,   137,
      -1,     3,     4,    -1,   142,    -1,   144,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,   136,    -1,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,     3,     4,    -1,    -1,    78,    79,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     6,    -1,    -1,    -1,   110,   111,
     112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,    -1,    -1,    -1,
     132,    -1,    -1,    -1,    -1,   137,    -1,     3,     4,    -1,
     142,    -1,   144,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,   140,
      -1,   142,    -1,   144,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,   110,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,    -1,    -1,    -1,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,   140,    -1,   142,    -1,   144,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    -1,    -1,    42,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,    -1,    -1,    -1,   132,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,   142,    -1,
     144,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
      -1,    -1,    -1,   132,    -1,   134,   135,    -1,   137,    -1,
     139,    -1,   141,   142,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,   136,    -1,    -1,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,     3,     4,    -1,    -1,    78,
      79,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
      -1,    -1,    -1,   132,     3,     4,     5,    -1,   137,    -1,
       9,    10,    11,   142,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,    12,    13,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    -1,
      56,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,    75,
      -1,    12,    13,     6,    -1,    -1,    -1,    -1,   127,   128,
      86,    87,    88,   132,    -1,    -1,    -1,    -1,   137,    -1,
      -1,    -1,    -1,   142,   100,   101,   102,    -1,   104,    -1,
      -1,   107,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    -1,    56,    57,    -1,    59,    60,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    75,    -1,    12,    13,   136,   145,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,   102,    -1,   104,    -1,    -1,   107,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    -1,
      56,    57,    -1,    59,    60,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    75,
      -1,    12,    13,   136,   145,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,   102,    -1,   104,    -1,
      -1,   107,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    -1,    56,    57,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    12,    13,     6,   145,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,   102,    -1,   104,    -1,    -1,   107,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    -1,
      56,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    12,    13,     6,   145,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,   102,    -1,   104,    -1,
      -1,   107,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    -1,    56,    57,    -1,    59,    60,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    75,     6,    12,    13,   136,   145,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,   100,
     101,   102,    -1,   104,    -1,    -1,   107,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,     8,
      56,    57,    -1,    59,    60,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    75,
       8,    -1,    -1,   136,   145,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,   102,    -1,   104,    -1,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,   145,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,     0,     1,    -1,   136,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      35,    -1,    -1,    -1,    -1,    40,    41,   145,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    72,    73,    74,
      75,    -1,    -1,    78,    79,    -1,     4,    -1,    -1,    -1,
      85,    86,    87,    88,    12,    13,    91,    -1,    93,    -1,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,   104,
     105,   106,   107,   108,   109,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    72,    73,    74,    75,    -1,    -1,
      78,    79,    12,    13,    -1,    -1,    -1,    85,    86,    87,
      88,    -1,    -1,    91,    -1,    93,    -1,    95,    96,    97,
      98,    -1,   100,   101,   102,    -1,   104,   105,   106,   107,
     108,   109,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    -1,    56,    57,    -1,    59,
      60,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    75,    -1,    -1,    -1,   136,
      -1,    -1,    -1,   140,    -1,    -1,    86,    87,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,   102,    -1,   104,    -1,    -1,   107,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,    -1,   145,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,   145,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,   145,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
     138,    -1,    -1,    -1,    -1,   143,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,   140,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,   136,    -1,    -1,    -1,   140,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,   140,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,
      -1,   140,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,   140,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,   136,    -1,    -1,    -1,   140,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
     140,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,   140,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,   140,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,   140,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,   140,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,   136,    -1,    -1,    -1,   140,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,   140,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,
      -1,   140,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,   140,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,   136,    -1,    -1,    -1,   140,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
     140,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,   140,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,   140,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,   140,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,   140,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,   136,    -1,    -1,    -1,   140,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,   140,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,
      -1,   140,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,   140,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,   136,    -1,    -1,    -1,   140,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
     140,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,   140,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,   140,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,   140,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,   140,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,   136,    -1,   138,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,   138,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,   136,    -1,   138,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,   138,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,   136,    -1,   138,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,   138,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,   138,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
     138,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,
      -1,   138,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,   138,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,   136,    -1,   138,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,   138,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,   136,    -1,   138,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,   138,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,   136,    -1,   138,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,   138,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,   138,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
     138,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,
      -1,   138,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,   138,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,   136,    -1,   138,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,   138,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,   136,    -1,   138,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,   138,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,   136,    -1,   138,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,   138,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,   138,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
     138,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,
      -1,   138,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,   138,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,   136,    -1,   138,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,   138,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,   136,    -1,   138,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,   138,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,   136,    -1,   138,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,   138,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,   138,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
     138,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,
      -1,   138,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,   138,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,   136,    -1,   138,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,   138,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,   136,    -1,   138,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,   138,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,   136,    -1,   138,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,   136,    -1,   138,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,   138,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,    -1,
     138,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,   136,
      -1,   138,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
     136,    -1,   138,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,   136,    -1,   138,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,   136,    -1,   138,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,   136,    -1,   138,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,   136,    -1,   138,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,   136
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   148,   149,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    55,    56,    57,    58,    59,    60,    64,
      65,    66,    67,    68,    69,    70,    72,    73,    74,    75,
      78,    79,    85,    86,    87,    88,    91,    93,    95,    96,
      97,    98,   100,   101,   102,   104,   105,   106,   107,   108,
     109,   150,   152,   153,   172,   174,   175,   178,   179,   180,
     181,   182,   183,   184,   201,   202,   203,     3,     4,     5,
       7,     9,    10,    11,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    36,    37,    38,    39,    42,
     110,   111,   112,   113,   114,   115,   116,   117,   127,   128,
     132,   134,   135,   137,   139,   141,   142,   170,   171,   204,
     205,   216,    13,    49,   137,     6,   144,     6,   137,   144,
     137,   137,    71,   137,   144,   137,   137,    71,   144,   137,
     137,    53,    49,   137,    49,    49,    49,    46,    49,    51,
      51,    43,    46,    49,    51,   137,   144,   127,   128,   137,
     144,   206,   207,   206,   144,     4,    43,    46,    49,   144,
     206,     4,   144,    49,     4,   144,     6,    43,    46,     4,
       4,     4,   137,   137,   137,     4,   144,   212,     4,   137,
     137,     6,    99,    99,    99,    99,     4,     4,    99,     4,
       5,   144,   215,   216,   144,   215,     4,   139,   141,   146,
     171,     4,   144,   216,   137,   139,   137,   139,   137,   139,
     137,   139,   137,   139,   137,   139,   137,   139,   137,   139,
     137,   139,   137,   139,   137,   139,   137,   139,   137,   139,
     137,   139,   137,   139,   137,   139,   137,   139,   137,   139,
     137,   139,   137,   139,   137,   139,   137,   137,   137,   137,
     137,     4,   204,   204,   204,   204,   140,   144,   204,     4,
      91,    92,     4,   204,     6,     6,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     136,     6,     6,   204,     5,   204,   204,     4,    43,   128,
     175,   178,   184,   204,   210,   211,   204,   204,   137,   204,
     211,   204,   204,   137,   211,   204,   204,    99,   128,   144,
     204,   209,   210,   137,   204,   144,   137,   137,   209,   144,
     144,   137,   137,   137,   137,   137,     4,   206,   206,   206,
     204,   204,   127,   128,   144,   144,   206,   139,   144,   144,
     144,   127,   128,   137,   177,   206,   144,   139,   177,   209,
       4,     6,   139,   177,    99,   209,   209,   139,   139,     6,
     204,   204,   204,   141,   204,   144,    94,   204,   204,   137,
     137,   137,   137,     6,   137,   177,     6,   177,     6,   139,
     204,     4,   144,   206,   154,     6,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,     4,   215,
     215,   215,   215,     5,   139,   138,     7,   117,   211,   140,
       7,   170,   171,   141,     7,   139,     6,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,     6,   138,   143,   143,   138,   139,   144,   204,
     210,     8,   129,   143,   145,   138,   138,   204,   138,   145,
     138,   138,   204,   145,   138,   138,   209,   144,   145,   211,
     129,     7,   204,   138,   204,   204,   204,     7,   204,   204,
     204,   173,   204,   216,   173,   173,   173,   138,   143,   143,
     143,   206,   206,   175,   176,   177,   178,   176,   143,   204,
     204,   204,   204,   204,    43,    46,    49,    51,   107,   174,
     188,   143,   177,   204,   145,     6,     7,     6,   204,   145,
     137,     7,     7,   204,   204,   138,   138,   138,    91,   143,
     177,   144,     8,   138,   204,   204,   204,   204,   204,   145,
     145,   204,   140,   171,   204,   144,     4,    80,    81,    82,
      83,    84,   145,   157,   161,   164,   166,   167,   169,   138,
     140,   138,   140,   138,   140,   138,   140,   138,   140,   138,
     140,   138,   140,   138,   140,   138,   140,   138,   140,   138,
     140,   143,   143,   138,   140,   138,   140,   138,   140,   138,
     140,   138,   140,   138,   140,   143,   143,   143,   143,   143,
     143,   139,   141,   138,   143,   143,   138,   138,   143,   204,
     209,   209,   145,     7,   141,   170,   171,   216,   204,     6,
       4,     4,   144,   213,   140,     8,     6,   124,   151,   211,
     204,     7,   140,   144,   204,   204,   204,   210,   204,   210,
      94,     7,     7,   138,     7,    94,     7,     7,   138,    94,
       7,     7,     6,   211,   145,   144,   204,   138,     7,   145,
     138,   138,   204,   145,   145,   138,   138,   138,   138,   138,
     141,   206,   204,   204,   145,   145,   204,   140,   143,   143,
     143,   144,   144,   144,   144,    72,    76,    77,   199,   200,
     206,   145,   185,   140,   204,   140,   204,   209,   209,   140,
     140,     7,     7,     7,   141,   204,   145,   204,   204,   138,
     138,   138,   138,   138,   140,   141,   171,   215,   145,   154,
     158,   137,   137,   144,   168,   137,     6,   204,   204,   204,
     204,   204,   204,   204,   204,   204,     4,   211,   215,   204,
     140,     6,     6,   140,     4,    91,    92,   204,     6,     6,
       6,     7,   139,   212,   214,     6,   204,   124,   215,   138,
     143,   206,   211,   145,     8,    49,   209,   209,     7,   209,
      49,    51,   209,   209,     7,    51,   209,   209,   145,   211,
       6,     7,   144,     7,     7,     7,     6,    61,     7,     7,
       7,     7,     7,     7,     7,     4,   143,   143,   143,   145,
     144,   206,   206,   206,   211,   211,   211,   211,     6,   144,
     137,   145,   200,   143,   199,     6,     6,     6,   138,     6,
       6,     6,     6,   209,   209,   209,     4,   143,     8,     8,
     138,     7,     7,     7,     7,     7,     6,     4,     6,   145,
     137,   204,   204,   208,   209,   144,   204,   138,   140,   138,
     140,   138,   140,   138,   140,   140,   138,   138,   138,   138,
     170,     7,   170,   171,   141,     7,     6,   212,   204,   143,
     145,     6,     6,   151,   204,     6,   145,   204,   144,     6,
      56,     6,    56,   209,     6,   144,   144,     6,     6,   209,
     144,     6,     6,   145,     5,   204,   209,   209,   209,    62,
      63,   209,   209,   209,   209,   209,   209,   209,     6,     7,
     204,   204,   204,   144,   177,   143,   145,   143,   145,   143,
     145,   145,   145,   145,   145,   204,   209,   204,   204,   206,
     145,     7,     6,     6,    90,   204,   204,   204,   209,     5,
     204,   204,     5,   171,     6,   155,   204,   143,   143,   143,
     145,   156,   204,   138,   141,   209,   216,   204,     6,     4,
     213,     6,   140,   212,   215,   143,   140,   204,   206,   206,
       6,   204,   204,     6,   204,     5,   143,     6,     6,     6,
     204,   204,     4,     6,     6,     6,     6,     6,     6,     6,
     204,   216,   145,   138,   143,   145,   176,   189,   206,     6,
     190,   206,     6,   191,   206,     6,   192,     6,     6,     6,
       6,   145,   143,   138,   145,   143,   209,   209,   143,   145,
       8,   145,   138,     6,     6,     6,     6,   209,   138,   143,
     204,   204,   209,   144,   143,   145,   209,     4,     6,     6,
       6,     7,     6,   141,     6,   204,   145,     6,     6,   145,
     145,   145,     5,   204,     6,     6,     6,     6,     6,   144,
     204,   145,   199,   143,   144,   143,   144,   143,   144,     6,
     209,     7,   144,   204,     6,    89,   204,   204,     6,   159,
     204,   143,   143,   208,   204,     6,     6,   138,   212,    92,
     143,     6,     6,     6,     6,     6,   143,   176,   143,   145,
     145,   204,   206,   199,   204,   206,   199,   204,   206,   199,
     143,   145,   209,   177,   145,   204,   145,   145,   144,   204,
     204,   145,     6,   204,     5,   145,   204,   145,   143,   145,
     145,   143,   145,   145,   143,   145,   209,     6,    61,   145,
     186,   144,     6,   156,   138,   143,     6,   144,   143,   143,
     145,     6,   193,   204,     6,     6,   194,   204,     6,     6,
     195,   204,     6,   145,   204,   199,   177,   145,   162,   204,
     208,   204,     5,   144,   145,   144,   145,   144,   145,     6,
       6,   145,   145,   187,     6,   144,   138,   145,   145,   143,
     199,     6,   196,   199,     6,   197,   199,     6,   198,   199,
     160,   215,   165,   144,     6,     5,   145,   144,   145,   144,
     145,   144,   145,   143,   145,   144,   208,   145,     6,   199,
       6,   199,     6,   199,   215,     6,   163,   215,   145,     6,
     145,   145,   145,   143,   145,     6,     6,     6,     6,   215,
       6
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
# if YYLTYPE_IS_TRIVIAL
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
#line 147 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 158 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 159 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 160 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 161 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 162 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 163 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 164 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 165 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 166 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 167 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 16:
#line 168 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 169 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 170 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 171 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 172 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 177 "Gmsh.y"
    {
      (yyval.c) = "w";
    ;}
    break;

  case 22:
#line 181 "Gmsh.y"
    {
      (yyval.c) = "a";
    ;}
    break;

  case 23:
#line 188 "Gmsh.y"
    {
      Msg(DIRECT, (yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 24:
#line 193 "Gmsh.y"
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

  case 25:
#line 208 "Gmsh.y"
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

  case 26:
#line 221 "Gmsh.y"
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

  case 27:
#line 250 "Gmsh.y"
    { 
      if(!strcmp((yyvsp[(1) - (6)].c), "View") && !CheckViewErrorFlags(View)){
	EndView(View, 0, yyname, (yyvsp[(2) - (6)].c));
      }
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 28:
#line 257 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (8)].c), "View") && !CheckViewErrorFlags(View)){
	EndView(View, 0, yyname, (yyvsp[(2) - (8)].c));
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(2) - (8)].c)); Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 29:
#line 267 "Gmsh.y"
    {
      View = BeginView(1); 
      for(int i = 0; i < VIEW_NB_ELEMENT_TYPES; i++){
	ViewErrorFlags[i] = 0;
      }
    ;}
    break;

  case 36:
#line 283 "Gmsh.y"
    { ViewCoord[ViewCoordIdx] = (yyvsp[(1) - (1)].d); ViewCoordIdx++; ;}
    break;

  case 37:
#line 285 "Gmsh.y"
    { ViewCoord[ViewCoordIdx] = (yyvsp[(3) - (3)].d); ViewCoordIdx++; ;}
    break;

  case 38:
#line 290 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(1) - (1)].d)); ;}
    break;

  case 39:
#line 292 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(3) - (3)].d)); ;}
    break;

  case 40:
#line 297 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "SP")){
	ViewElementIdx = 0; ViewNumNodes = 1; ViewNumComp = 1;
	ViewValueList = View->SP; ViewNumList = &View->NbSP;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VP")){
	ViewElementIdx = 1; ViewNumNodes = 1; ViewNumComp = 3;
	ViewValueList = View->VP; ViewNumList = &View->NbVP;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TP")){
	ViewElementIdx = 2; ViewNumNodes = 1; ViewNumComp = 9;
	ViewValueList = View->TP; ViewNumList = &View->NbTP;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SL")){
	ViewElementIdx = 3; ViewNumNodes = 2; ViewNumComp = 1;
	ViewValueList = View->SL; ViewNumList = &View->NbSL;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VL")){
	ViewElementIdx = 4; ViewNumNodes = 2; ViewNumComp = 3;
	ViewValueList = View->VL; ViewNumList = &View->NbVL;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TL")){
	ViewElementIdx = 5; ViewNumNodes = 2; ViewNumComp = 9;
	ViewValueList = View->TL; ViewNumList = &View->NbTL;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "ST")){
	ViewElementIdx = 6; ViewNumNodes = 3; ViewNumComp = 1;
	ViewValueList = View->ST; ViewNumList = &View->NbST;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VT")){
	ViewElementIdx = 7; ViewNumNodes = 3; ViewNumComp = 3;
	ViewValueList = View->VT; ViewNumList = &View->NbVT;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TT")){
	ViewElementIdx = 8; ViewNumNodes = 3; ViewNumComp = 9;
	ViewValueList = View->TT; ViewNumList = &View->NbTT;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SQ")){
	ViewElementIdx = 9; ViewNumNodes = 4; ViewNumComp = 1;
	ViewValueList = View->SQ; ViewNumList = &View->NbSQ;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VQ")){
	ViewElementIdx = 10; ViewNumNodes = 4; ViewNumComp = 3;
	ViewValueList = View->VQ; ViewNumList = &View->NbVQ;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TQ")){
	ViewElementIdx = 11; ViewNumNodes = 4; ViewNumComp = 9;
	ViewValueList = View->TQ; ViewNumList = &View->NbTQ;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SS")){
	ViewElementIdx = 12; ViewNumNodes = 4; ViewNumComp = 1;
	ViewValueList = View->SS; ViewNumList = &View->NbSS;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VS")){
	ViewElementIdx = 13; ViewNumNodes = 4; ViewNumComp = 3;
	ViewValueList = View->VS; ViewNumList = &View->NbVS;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TS")){
	ViewElementIdx = 14; ViewNumNodes = 4; ViewNumComp = 9;
	ViewValueList = View->TS; ViewNumList = &View->NbTS;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SH")){
	ViewElementIdx = 15; ViewNumNodes = 8; ViewNumComp = 1;
	ViewValueList = View->SH; ViewNumList = &View->NbSH;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VH")){
	ViewElementIdx = 16; ViewNumNodes = 8; ViewNumComp = 3;
	ViewValueList = View->VH; ViewNumList = &View->NbVH;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TH")){
	ViewElementIdx = 17; ViewNumNodes = 8; ViewNumComp = 9;
	ViewValueList = View->TH; ViewNumList = &View->NbTH;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SI")){
	ViewElementIdx = 18; ViewNumNodes = 6; ViewNumComp = 1;
	ViewValueList = View->SI; ViewNumList = &View->NbSI;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VI")){
	ViewElementIdx = 19; ViewNumNodes = 6; ViewNumComp = 3;
	ViewValueList = View->VI; ViewNumList = &View->NbVI;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TI")){
	ViewElementIdx = 20; ViewNumNodes = 6; ViewNumComp = 9;
	ViewValueList = View->TI; ViewNumList = &View->NbTI;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SY")){
	ViewElementIdx = 21; ViewNumNodes = 5; ViewNumComp = 1;
	ViewValueList = View->SY; ViewNumList = &View->NbSY;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VY")){
	ViewElementIdx = 22; ViewNumNodes = 5; ViewNumComp = 3;
	ViewValueList = View->VY; ViewNumList = &View->NbVY;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TY")){
	ViewElementIdx = 23; ViewNumNodes = 5; ViewNumComp = 9;
	ViewValueList = View->TY; ViewNumList = &View->NbTY;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SL2")){
	ViewElementIdx = 3; ViewNumNodes = 3; ViewNumComp = 1;
	ViewValueList = View->SL2; ViewNumList = &View->NbSL2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VL2")){
	ViewElementIdx = 4; ViewNumNodes = 3; ViewNumComp = 3;
	ViewValueList = View->VL2; ViewNumList = &View->NbVL2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TL2")){
	ViewElementIdx = 5; ViewNumNodes = 3; ViewNumComp = 9;
	ViewValueList = View->TL2; ViewNumList = &View->NbTL2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "ST2")){
	ViewElementIdx = 6; ViewNumNodes = 6; ViewNumComp = 1;
	ViewValueList = View->ST2; ViewNumList = &View->NbST2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VT2")){
	ViewElementIdx = 7; ViewNumNodes = 6; ViewNumComp = 3;
	ViewValueList = View->VT2; ViewNumList = &View->NbVT2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TT2")){
	ViewElementIdx = 8; ViewNumNodes = 6; ViewNumComp = 9;
	ViewValueList = View->TT2; ViewNumList = &View->NbTT2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SQ2")){
	ViewElementIdx = 9; ViewNumNodes = 9; ViewNumComp = 1;
	ViewValueList = View->SQ2; ViewNumList = &View->NbSQ2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VQ2")){
	ViewElementIdx = 10; ViewNumNodes = 9; ViewNumComp = 3;
	ViewValueList = View->VQ2; ViewNumList = &View->NbVQ2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TQ2")){
	ViewElementIdx = 11; ViewNumNodes = 9; ViewNumComp = 9;
	ViewValueList = View->TQ2; ViewNumList = &View->NbTQ2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SS2")){
	ViewElementIdx = 12; ViewNumNodes = 10; ViewNumComp = 1;
	ViewValueList = View->SS2; ViewNumList = &View->NbSS2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VS2")){
	ViewElementIdx = 13; ViewNumNodes = 10; ViewNumComp = 3;
	ViewValueList = View->VS2; ViewNumList = &View->NbVS2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TS2")){
	ViewElementIdx = 14; ViewNumNodes = 10; ViewNumComp = 9;
	ViewValueList = View->TS2; ViewNumList = &View->NbTS2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SH2")){
	ViewElementIdx = 15; ViewNumNodes = 27; ViewNumComp = 1;
	ViewValueList = View->SH2; ViewNumList = &View->NbSH2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VH2")){
	ViewElementIdx = 16; ViewNumNodes = 27; ViewNumComp = 3;
	ViewValueList = View->VH2; ViewNumList = &View->NbVH2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TH2")){
	ViewElementIdx = 17; ViewNumNodes = 27; ViewNumComp = 9;
	ViewValueList = View->TH2; ViewNumList = &View->NbTH2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SI2")){
	ViewElementIdx = 18; ViewNumNodes = 18; ViewNumComp = 1;
	ViewValueList = View->SI2; ViewNumList = &View->NbSI2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VI2")){
	ViewElementIdx = 19; ViewNumNodes = 18; ViewNumComp = 3;
	ViewValueList = View->VI2; ViewNumList = &View->NbVI2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TI2")){
	ViewElementIdx = 20; ViewNumNodes = 18; ViewNumComp = 9;
	ViewValueList = View->TI2; ViewNumList = &View->NbTI2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "SY2")){
	ViewElementIdx = 21; ViewNumNodes = 14; ViewNumComp = 1;
	ViewValueList = View->SY2; ViewNumList = &View->NbSY2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "VY2")){
	ViewElementIdx = 22; ViewNumNodes = 14; ViewNumComp = 3;
	ViewValueList = View->VY2; ViewNumList = &View->NbVY2;
      }
      else if(!strcmp((yyvsp[(1) - (1)].c), "TY2")){
	ViewElementIdx = 23; ViewNumNodes = 14; ViewNumComp = 9;
	ViewValueList = View->TY2; ViewNumList = &View->NbTY2;
      }
      else{
	yymsg(GERROR, "Unknown element type '%s'", (yyvsp[(1) - (1)].c));	
	ViewElementIdx = -1; ViewNumNodes = 0; ViewNumComp = 0;
	ViewValueList = NULL; ViewNumList = NULL;
      }
      Free((yyvsp[(1) - (1)].c));
      ViewCoordIdx = 0;
    ;}
    break;

  case 41:
#line 487 "Gmsh.y"
    {
      if(ViewValueList){
	if(ViewCoordIdx != 3 * ViewNumNodes){
	  yymsg(GERROR, "Wrong number of node coordinates (%d != %d)", 
		ViewCoordIdx, 3 * ViewNumNodes);
	  double d = 0;
	  for(int i = 0; i < 3 * ViewNumNodes; i++)
	    List_Add(ViewValueList, &d);
	}
	else{
	  for(int i = 0; i < 3; i++)
	    for(int j = 0; j < ViewNumNodes; j++)
	      List_Add(ViewValueList, &ViewCoord[3*j+i]);
	}
	ViewNumListTmp = List_Nbr(ViewValueList);
      }
    ;}
    break;

  case 42:
#line 505 "Gmsh.y"
    {
      if(ViewValueList){  
	if((List_Nbr(ViewValueList) - ViewNumListTmp) % (ViewNumComp * ViewNumNodes)) 
	  ViewErrorFlags[ViewElementIdx]++;
	(*ViewNumList)++;
      }
    ;}
    break;

  case 43:
#line 516 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(View->T2C, &(yyvsp[(1) - (1)].c)[i]); 
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 44:
#line 521 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(View->T2C, &(yyvsp[(3) - (3)].c)[i]); 
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 45:
#line 529 "Gmsh.y"
    { 
      List_Add(View->T2D, &(yyvsp[(3) - (8)].d)); List_Add(View->T2D, &(yyvsp[(5) - (8)].d));
      List_Add(View->T2D, &(yyvsp[(7) - (8)].d)); 
      double d = List_Nbr(View->T2C);
      List_Add(View->T2D, &d); 
    ;}
    break;

  case 46:
#line 536 "Gmsh.y"
    {
      View->NbT2++;
    ;}
    break;

  case 47:
#line 543 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(View->T3C, &(yyvsp[(1) - (1)].c)[i]); 
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 48:
#line 548 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(View->T3C, &(yyvsp[(3) - (3)].c)[i]); 
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 49:
#line 556 "Gmsh.y"
    { 
      List_Add(View->T3D, &(yyvsp[(3) - (10)].d)); List_Add(View->T3D, &(yyvsp[(5) - (10)].d));
      List_Add(View->T3D, &(yyvsp[(7) - (10)].d)); List_Add(View->T3D, &(yyvsp[(9) - (10)].d)); 
      double d = List_Nbr(View->T3C);
      List_Add(View->T3D, &d); 
    ;}
    break;

  case 50:
#line 563 "Gmsh.y"
    {
      View->NbT3++;
    ;}
    break;

  case 51:
#line 571 "Gmsh.y"
    {
      View->adaptive = new Adaptive_Post_View(View, (yyvsp[(3) - (8)].l), (yyvsp[(6) - (8)].l));
    ;}
    break;

  case 52:
#line 579 "Gmsh.y"
    {
      View->adaptive = new Adaptive_Post_View(View, (yyvsp[(3) - (14)].l), (yyvsp[(6) - (14)].l), (yyvsp[(9) - (14)].l), (yyvsp[(12) - (14)].l));
    ;}
    break;

  case 53:
#line 586 "Gmsh.y"
    {
      ViewValueList = View->Time;
    ;}
    break;

  case 54:
#line 590 "Gmsh.y"
    {
    ;}
    break;

  case 55:
#line 595 "Gmsh.y"
    {
      (*View->Grains) [(int)(yyvsp[(3) - (6)].d)] = (yyvsp[(5) - (6)].l);
    ;}
    break;

  case 56:
#line 603 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 57:
#line 604 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 58:
#line 605 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 59:
#line 606 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 60:
#line 607 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 61:
#line 611 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 62:
#line 612 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 63:
#line 620 "Gmsh.y"
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

  case 64:
#line 651 "Gmsh.y"
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

  case 65:
#line 690 "Gmsh.y"
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

  case 66:
#line 744 "Gmsh.y"
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

  case 67:
#line 761 "Gmsh.y"
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

  case 68:
#line 779 "Gmsh.y"
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

  case 69:
#line 790 "Gmsh.y"
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

  case 70:
#line 807 "Gmsh.y"
    { 
      Msg(WARNING, "Named string expressions not implemented yet");
    ;}
    break;

  case 71:
#line 814 "Gmsh.y"
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

  case 72:
#line 828 "Gmsh.y"
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

  case 73:
#line 845 "Gmsh.y"
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

  case 74:
#line 871 "Gmsh.y"
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

  case 75:
#line 898 "Gmsh.y"
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

  case 76:
#line 912 "Gmsh.y"
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

  case 77:
#line 929 "Gmsh.y"
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

  case 78:
#line 943 "Gmsh.y"
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

  case 79:
#line 960 "Gmsh.y"
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

  case 80:
#line 980 "Gmsh.y"
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

  case 81:
#line 1003 "Gmsh.y"
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

  case 82:
#line 1013 "Gmsh.y"
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

  case 83:
#line 1028 "Gmsh.y"
    { 
      (yyval.i) = (int)(yyvsp[(1) - (1)].d); 
    ;}
    break;

  case 84:
#line 1032 "Gmsh.y"
    { 
      (yyval.i) = GMODEL->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), ++THEM->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 85:
#line 1044 "Gmsh.y"
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
	Tree_Add(THEM->Points, &v);
	AddToTemporaryBoundingBox(v->Pos.X, v->Pos.Y, v->Pos.Z);
      }
      (yyval.s).Type = MSH_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 86:
#line 1066 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT)){
	yymsg(GERROR, "Physical point %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 87:
#line 1082 "Gmsh.y"
    {
      AttractorField *att = new AttractorField();
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (9)].l)); i++){
        double d;
        List_Read((yyvsp[(8) - (9)].l), i, &d);
        Vertex *v = FindPoint((int)d); 
        if(v)
          att->addPoint(v->Pos.X, v->Pos.Y, v->Pos.Z);
        else{
          GVertex *gv = GMODEL->vertexByTag((int)d);
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

  case 88:
#line 1102 "Gmsh.y"
    {
      fields.insert(new LatLonField(fields.get((int)(yyvsp[(7) - (8)].d))),(int)(yyvsp[(4) - (8)].d));
    ;}
    break;

  case 89:
#line 1105 "Gmsh.y"
    {
      Post_View **vv = (Post_View **)List_Pointer_Test(CTX.post.list, (int)(yyvsp[(7) - (8)].d));
      if(vv) 
        fields.insert(new PostViewField(*vv),(int)(yyvsp[(4) - (8)].d));
      else
        yymsg(GERROR, "Field %i error, view %i does not exist",(int)(yyvsp[(4) - (8)].d),(int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 90:
#line 1113 "Gmsh.y"
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

  case 91:
#line 1128 "Gmsh.y"
    {
      std::list<Field*> *flist = new std::list<Field*>;
      flist->resize(0);
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (9)].l)); i++){
	double id;
	List_Read((yyvsp[(8) - (9)].l), i, &id);
	Field *pfield = fields.get((int)id);
	if(pfield)flist->push_front(pfield);
      }
      fields.insert(new FunctionField(flist,(yyvsp[(7) - (9)].c)),(int)(yyvsp[(4) - (9)].d));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 92:
#line 1143 "Gmsh.y"
    {
      fields.insert(new StructuredField((yyvsp[(7) - (8)].c)), (int)(yyvsp[(4) - (8)].d));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 93:
#line 1150 "Gmsh.y"
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

  case 94:
#line 1162 "Gmsh.y"
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
	  GVertex *gv = GMODEL->vertexByTag((int)d);
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

  case 95:
#line 1196 "Gmsh.y"
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
	  GEdge *ge = GMODEL->edgeByTag((int)d);
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

  case 96:
#line 1232 "Gmsh.y"
    {      
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	Vertex *v = FindPoint((int)d); 	 
	if(v)
	  v->lc = (yyvsp[(5) - (6)].d);
	else{
	  GVertex *gv = GMODEL->vertexByTag((int)d);
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

  case 97:
#line 1254 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 98:
#line 1272 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_SPLN, 3, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_SPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 99:
#line 1290 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    ;}
    break;

  case 100:
#line 1308 "Gmsh.y"
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
	Tree_Add(THEM->Curves, &c);
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

  case 101:
#line 1334 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    ;}
    break;

  case 102:
#line 1352 "Gmsh.y"
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
	Tree_Add(THEM->Curves, &c);
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

  case 103:
#line 1379 "Gmsh.y"
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
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(c);
      }
      Free((yyvsp[(11) - (17)].c)); Free((yyvsp[(13) - (17)].c)); Free((yyvsp[(15) - (17)].c));
      (yyval.s).Type = MSH_SEGM_PARAMETRIC;
      (yyval.s).Num = num;
    ;}
    break;

  case 104:
#line 1398 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(List_Nbr((yyvsp[(6) - (7)].l)) < 4){
	yymsg(GERROR, "Too few control points for BSpline %d (%d < 4)", num,
	      List_Nbr((yyvsp[(6) - (7)].l)));
      }
      else{
	if(FindCurve(num)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	  Curve *c = Create_Curve(num, MSH_SEGM_BSPLN, 2, temp, NULL,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(c);
	  List_Delete(temp);
	}
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 105:
#line 1422 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(List_Nbr((yyvsp[(6) - (7)].l)) < 4){
	yymsg(GERROR, "Too few control points for Bezier curve %d (%d < 4)", num,
	      List_Nbr((yyvsp[(6) - (7)].l)));
      }
      else{
	if(FindCurve(num)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	  Curve *c = Create_Curve(num, MSH_SEGM_BEZIER, 2, temp, NULL,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(c);
	  List_Delete(temp);
	}
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BEZIER;
      (yyval.s).Num = num;
    ;}
    break;

  case 106:
#line 1446 "Gmsh.y"
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
	  Tree_Add(THEM->Curves, &c);
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
#line 1472 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindEdgeLoop(num)){
	yymsg(GERROR, "Line loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	sortEdgesInLoop(num, temp);
	EdgeLoop *l = Create_EdgeLoop(num, temp);
	Tree_Add(THEM->EdgeLoops, &l);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 108:
#line 1489 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE)){
	yymsg(GERROR, "Physical line %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 109:
#line 1508 "Gmsh.y"
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
	Tree_Add(THEM->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 110:
#line 1526 "Gmsh.y"
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
	  Tree_Add(THEM->Surfaces, &s);
	}
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = type;
      (yyval.s).Num = num;
    ;}
    break;

  case 111:
#line 1564 "Gmsh.y"
    {
      myGmshSurface = 0;
    ;}
    break;

  case 112:
#line 1568 "Gmsh.y"
    {
      myGmshSurface = gmshSurface :: surfaceByTag ( (int) (yyvsp[(3) - (4)].d));
    ;}
    break;

  case 113:
#line 1572 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d), type = 0;
      myGmshSurface = gmshParametricSurface::NewParametricSurface ((int)(yyvsp[(4) - (10)].d),(yyvsp[(7) - (10)].c),(yyvsp[(8) - (10)].c),(yyvsp[(9) - (10)].c));
    ;}
    break;

  case 114:
#line 1577 "Gmsh.y"
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

  case 115:
#line 1599 "Gmsh.y"
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

  case 116:
#line 1621 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurfaceLoop(num)){
	yymsg(GERROR, "Surface loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	SurfaceLoop *l = Create_SurfaceLoop(num, temp);
	Tree_Add(THEM->SurfaceLoops, &l);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 117:
#line 1637 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(GERROR, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    ;}
    break;

  case 118:
#line 1657 "Gmsh.y"
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
	Tree_Add(THEM->Volumes, &v);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 119:
#line 1674 "Gmsh.y"
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
	Tree_Add(THEM->Volumes, &v);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 120:
#line 1691 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME)){
	yymsg(GERROR, "Physical volume %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 121:
#line 1712 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 122:
#line 1717 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 123:
#line 1722 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 124:
#line 1727 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 125:
#line 1734 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 126:
#line 1735 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 127:
#line 1736 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 128:
#line 1741 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 129:
#line 1745 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 130:
#line 1749 "Gmsh.y"
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
	  GVertex *gv = GMODEL->vertexByTag(TheShape.Num);
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

  case 131:
#line 1772 "Gmsh.y"
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
	  GEdge *ge = GMODEL->edgeByTag(TheShape.Num);
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

  case 132:
#line 1795 "Gmsh.y"
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
	  GFace *gf = GMODEL->faceByTag(TheShape.Num);
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

  case 133:
#line 1818 "Gmsh.y"
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
	  GRegion *gr = GMODEL->regionByTag(TheShape.Num);
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

  case 134:
#line 1846 "Gmsh.y"
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

  case 135:
#line 1858 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "View")) AliasView((int)(yyvsp[(4) - (6)].d), 0);
      Free((yyvsp[(2) - (6)].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 136:
#line 1864 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "View")) AliasView((int)(yyvsp[(4) - (6)].d), 0);
      Free((yyvsp[(2) - (6)].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 137:
#line 1870 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "View")) AliasView((int)(yyvsp[(4) - (6)].d), 1);
      Free((yyvsp[(2) - (6)].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 138:
#line 1882 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 139:
#line 1891 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	RemoveViewByIndex((int)(yyvsp[(4) - (6)].d));
      }
      else{
	yymsg(GERROR, "Unknown command 'Delete %s'", (yyvsp[(2) - (6)].c));
      }
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 140:
#line 1901 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Meshes") || !strcmp((yyvsp[(2) - (3)].c), "All")){
	GMODEL->destroy();
	THEM->destroy();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Physicals")){
	List_Action(THEM->PhysicalGroups, Free_PhysicalGroup);
	List_Reset(THEM->PhysicalGroups);
	GMODEL->deletePhysicalGroups();
      }
      else{
	yymsg(GERROR, "Unknown command 'Delete %s'", (yyvsp[(2) - (3)].c));
      }
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 141:
#line 1917 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (4)].c), "Empty") && !strcmp((yyvsp[(3) - (4)].c), "Views")){
	for(int i = List_Nbr(CTX.post.list) - 1; i >= 0; i--){
	  Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, i);
	  if(v->empty())
	    RemoveViewByIndex(i);
	}
      }
      else{
	yymsg(GERROR, "Unknown command 'Delete %s %s'", (yyvsp[(2) - (4)].c), (yyvsp[(3) - (4)].c));
      }
      Free((yyvsp[(2) - (4)].c)); Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 142:
#line 1936 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));      
    ;}
    break;

  case 143:
#line 1950 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 144:
#line 1956 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 145:
#line 1962 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 146:
#line 1971 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 147:
#line 1985 "Gmsh.y"
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
	// make sure we have the latest data from THEM in GModel
	// (fixes bug where we would have no geometry in the picture if
	// the print command is in the same file as the geometry)
	GMODEL->importTHEM();
	char tmpstring[1024];
	FixRelativePath((yyvsp[(2) - (3)].c), tmpstring);
	CreateOutputFile(tmpstring, CTX.print.format);
#endif
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Save")){
#if defined(HAVE_FLTK)
	GMODEL->importTHEM();
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "System")){
	SystemCall((yyvsp[(2) - (3)].c));
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 148:
#line 2035 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (7)].c), "Save") && !strcmp((yyvsp[(2) - (7)].c), "View")){
	Post_View **vv = (Post_View **)List_Pointer_Test(CTX.post.list, (int)(yyvsp[(4) - (7)].d));
	if(vv){
	  char tmpstring[1024];
	  FixRelativePath((yyvsp[(6) - (7)].c), tmpstring);
	  WriteView(*vv, tmpstring, CTX.post.file_format, 0);
	}
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[(1) - (7)].c));
      }
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(2) - (7)].c)); Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 149:
#line 2050 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (7)].c), "Background") && !strcmp((yyvsp[(2) - (7)].c), "Mesh")  && !strcmp((yyvsp[(3) - (7)].c), "View")){
	Post_View **vv = (Post_View **)List_Pointer_Test(CTX.post.list, (int)(yyvsp[(5) - (7)].d));
	if(vv) {
    Field *field=new PostViewField(*vv);
    fields.insert(field);
    BGMAddField(field);
  }
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[(1) - (7)].c));
      }
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(2) - (7)].c)); Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 150:
#line 2065 "Gmsh.y"
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
      else{
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 151:
#line 2085 "Gmsh.y"
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

  case 152:
#line 2095 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "ElementsFromAllViews"))
	CombineViews(0, 1, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "ElementsFromVisibleViews"))
	CombineViews(0, 0, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "ElementsByViewName"))
	CombineViews(0, 2, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsFromAllViews"))
	CombineViews(1, 1, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsFromVisibleViews"))
	CombineViews(1, 0, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsByViewName"))
	CombineViews(1, 2, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "Views"))
	CombineViews(0, 1, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeSteps"))
	CombineViews(1, 2, CTX.post.combine_remove_orig);
      else
	yymsg(GERROR, "Unknown 'Combine' command");
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 153:
#line 2117 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 154:
#line 2121 "Gmsh.y"
    {
      CTX.forced_bbox = 0;
      SetBoundingBox();
    ;}
    break;

  case 155:
#line 2126 "Gmsh.y"
    {
      CTX.forced_bbox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 156:
#line 2131 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      Draw();
#endif
    ;}
    break;

  case 157:
#line 2143 "Gmsh.y"
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

  case 158:
#line 2158 "Gmsh.y"
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

  case 159:
#line 2174 "Gmsh.y"
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
      else{
	List_Write(pSymbol->val, 0, &(yyvsp[(5) - (8)].d));
      }
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

  case 160:
#line 2200 "Gmsh.y"
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
      else{
	List_Write(pSymbol->val, 0, &(yyvsp[(5) - (10)].d));
      }
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

  case 161:
#line 2227 "Gmsh.y"
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
	else{
	  ImbricatedLoop--;
	}
      }
    ;}
    break;

  case 162:
#line 2259 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction((yyvsp[(2) - (2)].c), yyin, yyname, yylineno))
	yymsg(GERROR, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 163:
#line 2266 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin, yyname, yylineno))
	yymsg(GERROR, "Error while exiting function");
    ;}
    break;

  case 164:
#line 2271 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction((yyvsp[(2) - (3)].c), &yyin, yyname, yylineno))
	yymsg(GERROR, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 165:
#line 2277 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 166:
#line 2281 "Gmsh.y"
    {
    ;}
    break;

  case 167:
#line 2290 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 168:
#line 2298 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 169:
#line 2306 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 170:
#line 2314 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 171:
#line 2318 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 172:
#line 2326 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 173:
#line 2330 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 174:
#line 2338 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 175:
#line 2342 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 176:
#line 2350 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 177:
#line 2354 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 178:
#line 2361 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 179:
#line 2365 "Gmsh.y"
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

  case 180:
#line 2377 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 181:
#line 2384 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 182:
#line 2391 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 183:
#line 2398 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 184:
#line 2405 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 185:
#line 2412 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 186:
#line 2419 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 187:
#line 2426 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 188:
#line 2433 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 189:
#line 2440 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 190:
#line 2444 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 191:
#line 2451 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 192:
#line 2455 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 193:
#line 2462 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 194:
#line 2466 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 195:
#line 2473 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 196:
#line 2477 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 197:
#line 2484 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 198:
#line 2488 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 199:
#line 2495 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 200:
#line 2499 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 201:
#line 2506 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 202:
#line 2510 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 203:
#line 2517 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 204:
#line 2521 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 205:
#line 2528 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 206:
#line 2532 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 207:
#line 2543 "Gmsh.y"
    {
    ;}
    break;

  case 208:
#line 2546 "Gmsh.y"
    {
    ;}
    break;

  case 209:
#line 2552 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 210:
#line 2561 "Gmsh.y"
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
      else{
	yymsg(GERROR, "Wrong layer definition {%d, %d}", 
	      List_Nbr((yyvsp[(3) - (7)].l)), List_Nbr((yyvsp[(5) - (7)].l)));
      }
      List_Delete((yyvsp[(3) - (7)].l));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 211:
#line 2583 "Gmsh.y"
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
      else{
	yymsg(GERROR, "Wrong layer definition {%d, %d, %d}", 
	      List_Nbr((yyvsp[(3) - (9)].l)), List_Nbr((yyvsp[(5) - (9)].l)), List_Nbr((yyvsp[(7) - (9)].l)));
      }
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(5) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 212:
#line 2607 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 213:
#line 2611 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (9)].d);
      if(FindSurface(num)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
	Tree_Add(THEM->Surfaces, &s);
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

  case 214:
#line 2635 "Gmsh.y"
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

  case 215:
#line 2653 "Gmsh.y"
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

  case 216:
#line 2671 "Gmsh.y"
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

  case 217:
#line 2689 "Gmsh.y"
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

  case 218:
#line 2718 "Gmsh.y"
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

  case 219:
#line 2753 "Gmsh.y"
    {
      yymsg(WARNING, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 220:
#line 2758 "Gmsh.y"
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

  case 221:
#line 2785 "Gmsh.y"
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

  case 222:
#line 2799 "Gmsh.y"
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

  case 223:
#line 2818 "Gmsh.y"
    { 
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s)
	setSurfaceEmbeddedPoints(s, (yyvsp[(3) - (10)].l));
    ;}
    break;

  case 224:
#line 2824 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s)
	setSurfaceEmbeddedCurves(s, (yyvsp[(3) - (10)].l));
    ;}
    break;

  case 225:
#line 2830 "Gmsh.y"
    {
    ;}
    break;

  case 226:
#line 2833 "Gmsh.y"
    {
    ;}
    break;

  case 227:
#line 2842 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 228:
#line 2851 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 229:
#line 2852 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 230:
#line 2853 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 231:
#line 2854 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 232:
#line 2855 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 233:
#line 2856 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 234:
#line 2857 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 235:
#line 2858 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 236:
#line 2860 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(GERROR, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 237:
#line 2866 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 238:
#line 2867 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 239:
#line 2868 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 240:
#line 2869 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 241:
#line 2870 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 242:
#line 2871 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 243:
#line 2872 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 244:
#line 2873 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 245:
#line 2874 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 246:
#line 2875 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 247:
#line 2876 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d)? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d);  ;}
    break;

  case 248:
#line 2877 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 249:
#line 2878 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 250:
#line 2879 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 251:
#line 2880 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 252:
#line 2881 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 253:
#line 2882 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 254:
#line 2883 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 255:
#line 2884 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 256:
#line 2885 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 257:
#line 2886 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 258:
#line 2887 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 259:
#line 2888 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 260:
#line 2889 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 261:
#line 2890 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 262:
#line 2891 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 263:
#line 2892 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 264:
#line 2893 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 265:
#line 2894 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 266:
#line 2895 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 267:
#line 2896 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d)*(yyvsp[(3) - (6)].d)+(yyvsp[(5) - (6)].d)*(yyvsp[(5) - (6)].d)); ;}
    break;

  case 268:
#line 2897 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 269:
#line 2899 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 270:
#line 2900 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 271:
#line 2901 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 272:
#line 2902 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 273:
#line 2903 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 274:
#line 2904 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 275:
#line 2905 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 276:
#line 2906 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 277:
#line 2907 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 278:
#line 2908 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 279:
#line 2909 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 280:
#line 2910 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 281:
#line 2911 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 282:
#line 2912 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 283:
#line 2913 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 284:
#line 2914 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 285:
#line 2915 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 286:
#line 2916 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 287:
#line 2917 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 288:
#line 2918 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d)*(yyvsp[(3) - (6)].d)+(yyvsp[(5) - (6)].d)*(yyvsp[(5) - (6)].d)); ;}
    break;

  case 289:
#line 2919 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 290:
#line 2928 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 291:
#line 2929 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 292:
#line 2930 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->rank(); ;}
    break;

  case 293:
#line 2931 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->size(); ;}
    break;

  case 294:
#line 2932 "Gmsh.y"
    { (yyval.d) = Get_GmshMajorVersion(); ;}
    break;

  case 295:
#line 2933 "Gmsh.y"
    { (yyval.d) = Get_GmshMinorVersion(); ;}
    break;

  case 296:
#line 2934 "Gmsh.y"
    { (yyval.d) = Get_GmshPatchVersion(); ;}
    break;

  case 297:
#line 2939 "Gmsh.y"
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

  case 298:
#line 2955 "Gmsh.y"
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

  case 299:
#line 2970 "Gmsh.y"
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

  case 300:
#line 2990 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[(2) - (4)].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[(2) - (4)].c));
	(yyval.d) = 0.;
      }
      else{
	(yyval.d) = List_Nbr(pSymbol->val);
      }
      Free((yyvsp[(2) - (4)].c));
    ;}
    break;

  case 301:
#line 3004 "Gmsh.y"
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

  case 302:
#line 3017 "Gmsh.y"
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

  case 303:
#line 3040 "Gmsh.y"
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

  case 304:
#line 3058 "Gmsh.y"
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

  case 305:
#line 3076 "Gmsh.y"
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

  case 306:
#line 3094 "Gmsh.y"
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

  case 307:
#line 3112 "Gmsh.y"
    { 
      (yyval.d) = GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 308:
#line 3120 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 309:
#line 3124 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 310:
#line 3128 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 311:
#line 3132 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 312:
#line 3136 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 313:
#line 3143 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 314:
#line 3147 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 315:
#line 3151 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 316:
#line 3155 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 317:
#line 3162 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 318:
#line 3167 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 319:
#line 3175 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 320:
#line 3180 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 321:
#line 3184 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 322:
#line 3189 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 323:
#line 3193 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 324:
#line 3201 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 325:
#line 3212 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 326:
#line 3220 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 327:
#line 3228 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 328:
#line 3234 "Gmsh.y"
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

  case 329:
#line 3245 "Gmsh.y"
    {
      // Returns the coordinates of a point and fills a list with it.
      // This allows to ensure e.g. that relative point positions are
      // always conserved
      Vertex *v = FindPoint((int)(yyvsp[(3) - (4)].d));
      (yyval.l) = List_Create(3, 1, sizeof(double));      
      if(!v) {
	yymsg(GERROR, "Unknown point '%d'", (int) (yyvsp[(3) - (4)].d));
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

  case 330:
#line 3265 "Gmsh.y"
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

  case 331:
#line 3275 "Gmsh.y"
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

  case 332:
#line 3285 "Gmsh.y"
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

  case 333:
#line 3295 "Gmsh.y"
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

  case 334:
#line 3312 "Gmsh.y"
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

  case 335:
#line 3339 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 336:
#line 3344 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 337:
#line 3348 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 338:
#line 3352 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 339:
#line 3365 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 340:
#line 3369 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 341:
#line 3381 "Gmsh.y"
    {
      int flag;
      (yyval.u) = Get_ColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 342:
#line 3388 "Gmsh.y"
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
	else{
	  (yyval.u) = pColOpt(0, GMSH_GET, 0);
	}
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 343:
#line 3410 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 344:
#line 3414 "Gmsh.y"
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

  case 345:
#line 3429 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 346:
#line 3434 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 347:
#line 3441 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 348:
#line 3445 "Gmsh.y"
    {
      Msg(WARNING, "Named string expressions not implemented yet");
    ;}
    break;

  case 349:
#line 3452 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 350:
#line 3456 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32*sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 351:
#line 3464 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c))+strlen((yyvsp[(5) - (6)].c))+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 352:
#line 3472 "Gmsh.y"
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

  case 353:
#line 3486 "Gmsh.y"
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

  case 354:
#line 3500 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 355:
#line 3504 "Gmsh.y"
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

  case 356:
#line 3523 "Gmsh.y"
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

  case 357:
#line 3545 "Gmsh.y"
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
#line 8077 "Gmsh.tab.cpp"
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


#line 3568 "Gmsh.y"


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
    else{
      return List_Nbr(list)-i;
    }
  }
  if(j != (int)strlen(format))
    return -1;
  return 0;
}

int CheckViewErrorFlags(Post_View *v){
  if(View->adaptive) return 0; // hope for the best :-)

  char *name[8] = { "point", "line", "triangle", "quadrangle", 
		    "tetrahedron", "hexahedron", "prism", "pyramid" };
  char *type[3] = { "scalar", "vector", "tensor" };

  if(8 * 3 != VIEW_NB_ELEMENT_TYPES){
    Msg(GERROR, "Please upgrade CheckViewErrorFlags!");
    return 0;
  }
  
  for(int i = 0; i < VIEW_NB_ELEMENT_TYPES; i++)
    if(ViewErrorFlags[i])
      Msg(GERROR, "%d %s %s%s in View[%d] contain%s a wrong number of values",
	  ViewErrorFlags[i], type[i%3], name[i/3], (ViewErrorFlags[i] > 1) ? "s" : "",
	  v->Index, (ViewErrorFlags[i] > 1) ? "" : "s");
  
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

