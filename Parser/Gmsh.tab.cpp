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
     tReturn = 359,
     tCall = 360,
     tFunction = 361,
     tShow = 362,
     tHide = 363,
     tGetValue = 364,
     tGMSH_MAJOR_VERSION = 365,
     tGMSH_MINOR_VERSION = 366,
     tGMSH_PATCH_VERSION = 367,
     tAFFECTDIVIDE = 368,
     tAFFECTTIMES = 369,
     tAFFECTMINUS = 370,
     tAFFECTPLUS = 371,
     tOR = 372,
     tAND = 373,
     tNOTEQUAL = 374,
     tEQUAL = 375,
     tGREATEROREQUAL = 376,
     tLESSOREQUAL = 377,
     UNARYPREC = 378,
     tMINUSMINUS = 379,
     tPLUSPLUS = 380
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
#define tReturn 359
#define tCall 360
#define tFunction 361
#define tShow 362
#define tHide 363
#define tGetValue 364
#define tGMSH_MAJOR_VERSION 365
#define tGMSH_MINOR_VERSION 366
#define tGMSH_PATCH_VERSION 367
#define tAFFECTDIVIDE 368
#define tAFFECTTIMES 369
#define tAFFECTMINUS 370
#define tAFFECTPLUS 371
#define tOR 372
#define tAND 373
#define tNOTEQUAL 374
#define tEQUAL 375
#define tGREATEROREQUAL 376
#define tLESSOREQUAL 377
#define UNARYPREC 378
#define tMINUSMINUS 379
#define tPLUSPLUS 380




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// $Id: Gmsh.tab.cpp,v 1.317 2007-04-16 11:46:27 remacle Exp $
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
#line 434 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 447 "Gmsh.tab.cpp"

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
#define YYLAST   6655

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  146
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  355
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1265

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   380

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   131,     2,   141,     2,   130,     2,     2,
     136,   137,   128,   126,   142,   127,   140,   129,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     122,     2,   123,   117,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   138,     2,   139,   135,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   143,     2,   144,   145,     2,     2,     2,
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
     115,   116,   118,   119,   120,   121,   124,   125,   132,   133,
     134
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
     446,   455,   461,   468,   475,   482,   490,   498,   506,   516,
     524,   534,   552,   560,   568,   580,   589,   598,   607,   616,
     620,   625,   636,   644,   652,   661,   670,   679,   687,   696,
     702,   714,   720,   730,   732,   734,   736,   737,   740,   747,
     754,   761,   768,   773,   780,   787,   794,   799,   806,   810,
     815,   821,   825,   829,   834,   839,   843,   851,   859,   863,
     871,   875,   878,   881,   897,   900,   907,   916,   925,   936,
     938,   941,   943,   947,   952,   954,   960,   972,   986,   987,
     995,   996,  1010,  1011,  1027,  1028,  1035,  1036,  1047,  1056,
    1065,  1074,  1087,  1100,  1113,  1128,  1143,  1158,  1159,  1172,
    1173,  1186,  1187,  1200,  1201,  1218,  1219,  1236,  1237,  1254,
    1255,  1274,  1275,  1294,  1295,  1314,  1316,  1319,  1325,  1333,
    1343,  1346,  1356,  1363,  1373,  1383,  1392,  1402,  1411,  1420,
    1427,  1432,  1443,  1454,  1465,  1476,  1479,  1481,  1485,  1488,
    1491,  1494,  1498,  1502,  1506,  1510,  1514,  1518,  1522,  1526,
    1530,  1534,  1538,  1542,  1546,  1550,  1556,  1561,  1566,  1571,
    1576,  1581,  1586,  1591,  1596,  1601,  1606,  1613,  1618,  1623,
    1628,  1633,  1638,  1643,  1650,  1657,  1664,  1669,  1674,  1679,
    1684,  1689,  1694,  1699,  1704,  1709,  1714,  1719,  1726,  1731,
    1736,  1741,  1746,  1751,  1756,  1763,  1770,  1777,  1782,  1784,
    1786,  1788,  1790,  1792,  1794,  1796,  1798,  1804,  1809,  1814,
    1817,  1823,  1827,  1834,  1839,  1847,  1854,  1856,  1859,  1862,
    1866,  1870,  1882,  1892,  1900,  1908,  1910,  1914,  1916,  1918,
    1921,  1925,  1930,  1936,  1939,  1943,  1947,  1953,  1958,  1960,
    1962,  1964,  1968,  1975,  1977,  1979,  1983,  1987,  1997,  2005,
    2007,  2013,  2017,  2024,  2026,  2030,  2032,  2034,  2036,  2038,
    2045,  2050,  2055,  2060,  2067,  2074
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     147,     0,    -1,   148,    -1,     1,     6,    -1,    -1,   148,
     149,    -1,   152,    -1,   151,    -1,   171,    -1,   173,    -1,
     174,    -1,   177,    -1,   178,    -1,   179,    -1,   180,    -1,
     183,    -1,   200,    -1,   201,    -1,   202,    -1,   182,    -1,
     181,    -1,   123,    -1,   123,   123,    -1,    35,   136,     5,
     137,     6,    -1,    35,   136,     5,   137,   150,   214,     6,
      -1,    35,   136,     5,   142,   210,   137,     6,    -1,    35,
     136,     5,   142,   210,   137,   150,   214,     6,    -1,     4,
       5,   143,   153,   144,     6,    -1,     4,     5,     4,   205,
     143,   153,   144,     6,    -1,    -1,   153,   156,    -1,   153,
     160,    -1,   153,   163,    -1,   153,   165,    -1,   153,   166,
      -1,   153,   168,    -1,   203,    -1,   154,   142,   203,    -1,
     203,    -1,   155,   142,   203,    -1,    -1,    -1,     4,   157,
     136,   154,   137,   158,   143,   155,   144,     6,    -1,   214,
      -1,   159,   142,   214,    -1,    -1,    80,   136,   203,   142,
     203,   142,   203,   137,   161,   143,   159,   144,     6,    -1,
     214,    -1,   162,   142,   214,    -1,    -1,    81,   136,   203,
     142,   203,   142,   203,   142,   203,   137,   164,   143,   162,
     144,     6,    -1,    82,   143,   207,   144,   143,   207,   144,
       6,    -1,    82,   143,   207,   144,   143,   207,   144,   143,
     207,   144,   143,   207,   144,     6,    -1,    -1,    83,   167,
     143,   155,   144,     6,    -1,    84,   136,   203,   137,   208,
       6,    -1,     7,    -1,   116,    -1,   115,    -1,   114,    -1,
     113,    -1,   134,    -1,   133,    -1,     4,   169,   203,     6,
      -1,     4,   138,   203,   139,   169,   203,     6,    -1,     4,
     138,   143,   210,   144,   139,   169,   208,     6,    -1,     4,
     138,   139,     7,   208,     6,    -1,     4,   138,   139,   116,
     208,     6,    -1,     4,   170,     6,    -1,     4,   138,   203,
     139,   170,     6,    -1,     4,     7,   215,     6,    -1,     4,
     140,     4,     7,   215,     6,    -1,     4,   138,   203,   139,
     140,     4,     7,   215,     6,    -1,     4,   140,     4,   169,
     203,     6,    -1,     4,   138,   203,   139,   140,     4,   169,
     203,     6,    -1,     4,   140,     4,   170,     6,    -1,     4,
     138,   203,   139,   140,     4,   170,     6,    -1,     4,   140,
      91,   140,     4,     7,   211,     6,    -1,     4,   138,   203,
     139,   140,    91,   140,     4,     7,   211,     6,    -1,     4,
     140,    92,     7,   212,     6,    -1,     4,   138,   203,   139,
     140,    92,     7,   212,     6,    -1,    64,   136,     4,   137,
     140,     4,     7,   203,     6,    -1,    64,   136,     4,   137,
     140,     4,     7,   215,     6,    -1,   203,    -1,   215,    -1,
      43,   136,   203,   137,     7,   205,     6,    -1,    60,    43,
     136,   172,   137,     7,   208,     6,    -1,    75,    43,    99,
     136,   203,   137,     7,   208,     6,    -1,   100,    99,   136,
     203,   137,     7,   208,     6,    -1,   106,    99,   136,   203,
     137,     7,     5,   208,     6,    -1,   101,    99,   136,   203,
     137,     7,     5,     6,    -1,    52,    53,    99,   208,     6,
      -1,    75,    43,   208,     7,   208,     6,    -1,    75,    46,
     208,     7,   208,     6,    -1,    52,    53,   208,     7,   203,
       6,    -1,    46,   136,   203,   137,     7,   208,     6,    -1,
      50,   136,   203,   137,     7,   208,     6,    -1,    44,   136,
     203,   137,     7,   208,     6,    -1,    44,   136,   203,   137,
       7,   208,    56,   205,     6,    -1,    45,   136,   203,   137,
       7,   208,     6,    -1,    45,   136,   203,   137,     7,   208,
      56,   205,     6,    -1,    54,   136,   203,   137,     7,   143,
     203,   142,   203,   142,     5,   142,     5,   142,     5,   144,
       6,    -1,    86,   136,   203,   137,     7,   208,     6,    -1,
      87,   136,   203,   137,     7,   208,     6,    -1,    88,   136,
     203,   137,     7,   208,    90,   208,    89,   203,     6,    -1,
      46,    71,   136,   203,   137,     7,   208,     6,    -1,    60,
      46,   136,   172,   137,     7,   208,     6,    -1,    56,    49,
     136,   203,   137,     7,   208,     6,    -1,    57,    49,   136,
     203,   137,     7,   208,     6,    -1,    12,    13,     6,    -1,
      13,    49,   203,     6,    -1,    54,    49,   136,   203,   137,
       7,     5,     5,     5,     6,    -1,    47,   136,   203,   137,
       7,   208,     6,    -1,    48,   136,   203,   137,     7,   208,
       6,    -1,    49,    71,   136,   203,   137,     7,   208,     6,
      -1,    60,    49,   136,   172,   137,     7,   208,     6,    -1,
      59,    51,   136,   203,   137,     7,   208,     6,    -1,    51,
     136,   203,   137,     7,   208,     6,    -1,    60,    51,   136,
     172,   137,     7,   208,     6,    -1,    66,   205,   143,   175,
     144,    -1,    65,   143,   205,   142,   205,   142,   203,   144,
     143,   175,   144,    -1,    67,   205,   143,   175,   144,    -1,
      68,   143,   205,   142,   203,   144,   143,   175,   144,    -1,
     177,    -1,   176,    -1,   174,    -1,    -1,   176,   173,    -1,
     176,    43,   143,   210,   144,     6,    -1,   176,    46,   143,
     210,   144,     6,    -1,   176,    49,   143,   210,   144,     6,
      -1,   176,    51,   143,   210,   144,     6,    -1,    70,   143,
     176,   144,    -1,    70,     4,   138,   203,   139,     6,    -1,
      78,     4,   138,   203,   139,     6,    -1,    79,     4,   138,
     203,   139,     6,    -1,    73,   143,   176,   144,    -1,    73,
       4,   138,   203,   139,     6,    -1,    73,     4,     6,    -1,
      73,     4,     4,     6,    -1,    91,   211,   143,   176,   144,
      -1,   107,   214,     6,    -1,   108,   214,     6,    -1,   107,
     143,   176,   144,    -1,   108,   143,   176,   144,    -1,     4,
     215,     6,    -1,     4,     4,   138,   203,   139,   214,     6,
      -1,     4,     4,     4,   138,   203,   139,     6,    -1,     4,
     203,     6,    -1,    64,   136,     4,   137,   140,     4,     6,
      -1,    85,     4,     6,    -1,    98,     6,    -1,    40,     6,
      -1,    40,   143,   203,   142,   203,   142,   203,   142,   203,
     142,   203,   142,   203,   144,     6,    -1,    41,     6,    -1,
      93,   136,   203,     8,   203,   137,    -1,    93,   136,   203,
       8,   203,     8,   203,   137,    -1,    93,     4,    94,   143,
     203,     8,   203,   144,    -1,    93,     4,    94,   143,   203,
       8,   203,     8,   203,   144,    -1,    95,    -1,   106,     4,
      -1,   104,    -1,   105,     4,     6,    -1,    96,   136,   203,
     137,    -1,    97,    -1,    69,   205,   143,   176,   144,    -1,
      69,   143,   205,   142,   205,   142,   203,   144,   143,   176,
     144,    -1,    69,   143,   205,   142,   205,   142,   205,   142,
     203,   144,   143,   176,   144,    -1,    -1,    69,   205,   143,
     176,   184,   198,   144,    -1,    -1,    69,   143,   205,   142,
     205,   142,   203,   144,   143,   176,   185,   198,   144,    -1,
      -1,    69,   143,   205,   142,   205,   142,   205,   142,   203,
     144,   143,   176,   186,   198,   144,    -1,    -1,    69,   143,
     176,   187,   198,   144,    -1,    -1,    69,     4,   138,   203,
     139,   143,   176,   188,   198,   144,    -1,    69,    43,   143,
     203,   142,   205,   144,     6,    -1,    69,    46,   143,   203,
     142,   205,   144,     6,    -1,    69,    49,   143,   203,   142,
     205,   144,     6,    -1,    69,    43,   143,   203,   142,   205,
     142,   205,   142,   203,   144,     6,    -1,    69,    46,   143,
     203,   142,   205,   142,   205,   142,   203,   144,     6,    -1,
      69,    49,   143,   203,   142,   205,   142,   205,   142,   203,
     144,     6,    -1,    69,    43,   143,   203,   142,   205,   142,
     205,   142,   205,   142,   203,   144,     6,    -1,    69,    46,
     143,   203,   142,   205,   142,   205,   142,   205,   142,   203,
     144,     6,    -1,    69,    49,   143,   203,   142,   205,   142,
     205,   142,   205,   142,   203,   144,     6,    -1,    -1,    69,
      43,   143,   203,   142,   205,   144,   189,   143,   198,   144,
       6,    -1,    -1,    69,    46,   143,   203,   142,   205,   144,
     190,   143,   198,   144,     6,    -1,    -1,    69,    49,   143,
     203,   142,   205,   144,   191,   143,   198,   144,     6,    -1,
      -1,    69,    43,   143,   203,   142,   205,   142,   205,   142,
     203,   144,   192,   143,   198,   144,     6,    -1,    -1,    69,
      46,   143,   203,   142,   205,   142,   205,   142,   203,   144,
     193,   143,   198,   144,     6,    -1,    -1,    69,    49,   143,
     203,   142,   205,   142,   205,   142,   203,   144,   194,   143,
     198,   144,     6,    -1,    -1,    69,    43,   143,   203,   142,
     205,   142,   205,   142,   205,   142,   203,   144,   195,   143,
     198,   144,     6,    -1,    -1,    69,    46,   143,   203,   142,
     205,   142,   205,   142,   205,   142,   203,   144,   196,   143,
     198,   144,     6,    -1,    -1,    69,    49,   143,   203,   142,
     205,   142,   205,   142,   205,   142,   203,   144,   197,   143,
     198,   144,     6,    -1,   199,    -1,   198,   199,    -1,    76,
     143,   203,   144,     6,    -1,    76,   143,   208,   142,   208,
     144,     6,    -1,    76,   143,   208,   142,   208,   142,   208,
     144,     6,    -1,    72,     6,    -1,    77,   136,   203,   137,
       7,   208,    61,   203,     6,    -1,    58,    46,   208,     7,
     203,     6,    -1,    58,    46,   208,     7,   203,    61,    63,
     203,     6,    -1,    58,    46,   208,     7,   203,    61,    62,
     203,     6,    -1,    58,    49,   143,   203,   144,     7,   208,
       6,    -1,    58,    49,   143,   203,   144,     7,   208,     4,
       6,    -1,    55,    49,   143,   203,   144,     7,   208,     6,
      -1,    58,    51,   143,   203,   144,     7,   208,     6,    -1,
      72,    49,   208,     7,   203,     6,    -1,    72,    49,   208,
       6,    -1,    43,   143,   210,   144,    94,    49,   143,   203,
     144,     6,    -1,    46,   143,   210,   144,    94,    49,   143,
     203,   144,     6,    -1,    46,   143,   210,   144,    94,    51,
     143,   203,   144,     6,    -1,    49,   143,   210,   144,    94,
      51,   143,   203,   144,     6,    -1,    74,     6,    -1,   204,
      -1,   136,   203,   137,    -1,   127,   203,    -1,   126,   203,
      -1,   131,   203,    -1,   203,   127,   203,    -1,   203,   126,
     203,    -1,   203,   128,   203,    -1,   203,   129,   203,    -1,
     203,   130,   203,    -1,   203,   135,   203,    -1,   203,   122,
     203,    -1,   203,   123,   203,    -1,   203,   125,   203,    -1,
     203,   124,   203,    -1,   203,   121,   203,    -1,   203,   120,
     203,    -1,   203,   119,   203,    -1,   203,   118,   203,    -1,
     203,   117,   203,     8,   203,    -1,    14,   136,   203,   137,
      -1,    15,   136,   203,   137,    -1,    16,   136,   203,   137,
      -1,    17,   136,   203,   137,    -1,    18,   136,   203,   137,
      -1,    19,   136,   203,   137,    -1,    20,   136,   203,   137,
      -1,    21,   136,   203,   137,    -1,    22,   136,   203,   137,
      -1,    24,   136,   203,   137,    -1,    25,   136,   203,   142,
     203,   137,    -1,    26,   136,   203,   137,    -1,    27,   136,
     203,   137,    -1,    28,   136,   203,   137,    -1,    29,   136,
     203,   137,    -1,    30,   136,   203,   137,    -1,    31,   136,
     203,   137,    -1,    32,   136,   203,   142,   203,   137,    -1,
      33,   136,   203,   142,   203,   137,    -1,    34,   136,   203,
     142,   203,   137,    -1,    23,   136,   203,   137,    -1,    14,
     138,   203,   139,    -1,    15,   138,   203,   139,    -1,    16,
     138,   203,   139,    -1,    17,   138,   203,   139,    -1,    18,
     138,   203,   139,    -1,    19,   138,   203,   139,    -1,    20,
     138,   203,   139,    -1,    21,   138,   203,   139,    -1,    22,
     138,   203,   139,    -1,    24,   138,   203,   139,    -1,    25,
     138,   203,   142,   203,   139,    -1,    26,   138,   203,   139,
      -1,    27,   138,   203,   139,    -1,    28,   138,   203,   139,
      -1,    29,   138,   203,   139,    -1,    30,   138,   203,   139,
      -1,    31,   138,   203,   139,    -1,    32,   138,   203,   142,
     203,   139,    -1,    33,   138,   203,   142,   203,   139,    -1,
      34,   138,   203,   142,   203,   139,    -1,    23,   138,   203,
     139,    -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,
     110,    -1,   111,    -1,   112,    -1,     4,    -1,     4,   145,
     143,   203,   144,    -1,     4,   138,   203,   139,    -1,   141,
       4,   138,   139,    -1,     4,   170,    -1,     4,   138,   203,
     139,   170,    -1,     4,   140,     4,    -1,     4,   138,   203,
     139,   140,     4,    -1,     4,   140,     4,   170,    -1,     4,
     138,   203,   139,   140,     4,   170,    -1,   109,   136,     5,
     142,   203,   137,    -1,   206,    -1,   127,   205,    -1,   126,
     205,    -1,   205,   127,   205,    -1,   205,   126,   205,    -1,
     143,   203,   142,   203,   142,   203,   142,   203,   142,   203,
     144,    -1,   143,   203,   142,   203,   142,   203,   142,   203,
     144,    -1,   143,   203,   142,   203,   142,   203,   144,    -1,
     136,   203,   142,   203,   142,   203,   137,    -1,   208,    -1,
     207,   142,   208,    -1,   203,    -1,   209,    -1,   143,   144,
      -1,   143,   210,   144,    -1,   127,   143,   210,   144,    -1,
     203,   128,   143,   210,   144,    -1,   127,   209,    -1,   203,
     128,   209,    -1,   203,     8,   203,    -1,   203,     8,   203,
       8,   203,    -1,    43,   143,   203,   144,    -1,   174,    -1,
     177,    -1,   183,    -1,     4,   138,   139,    -1,     4,   138,
     143,   210,   144,   139,    -1,   203,    -1,   209,    -1,   210,
     142,   203,    -1,   210,   142,   209,    -1,   143,   203,   142,
     203,   142,   203,   142,   203,   144,    -1,   143,   203,   142,
     203,   142,   203,   144,    -1,     4,    -1,     4,   140,    91,
     140,     4,    -1,   143,   213,   144,    -1,     4,   138,   203,
     139,   140,    92,    -1,   211,    -1,   213,   142,   211,    -1,
     215,    -1,     4,    -1,     5,    -1,    42,    -1,    37,   136,
     214,   142,   214,   137,    -1,    38,   136,   214,   137,    -1,
      39,   136,   214,   137,    -1,    36,   136,   214,   137,    -1,
      36,   136,   214,   142,   210,   137,    -1,    36,   136,     4,
     140,     4,   137,    -1,    36,   136,     4,   138,   203,   139,
     140,     4,   137,    -1
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
     979,  1002,  1012,  1027,  1031,  1043,  1065,  1082,  1099,  1109,
    1120,  1123,  1131,  1164,  1200,  1222,  1240,  1258,  1276,  1302,
    1320,  1346,  1366,  1390,  1414,  1440,  1457,  1476,  1494,  1533,
    1538,  1543,  1549,  1571,  1593,  1609,  1629,  1646,  1663,  1684,
    1689,  1694,  1699,  1707,  1708,  1709,  1714,  1717,  1721,  1744,
    1767,  1790,  1818,  1830,  1836,  1842,  1854,  1863,  1873,  1889,
    1908,  1922,  1928,  1934,  1943,  1957,  2007,  2022,  2037,  2057,
    2067,  2089,  2093,  2098,  2103,  2115,  2130,  2146,  2172,  2199,
    2231,  2238,  2243,  2249,  2253,  2262,  2270,  2278,  2287,  2286,
    2299,  2298,  2311,  2310,  2323,  2322,  2334,  2333,  2349,  2356,
    2363,  2370,  2377,  2384,  2391,  2398,  2405,  2413,  2412,  2424,
    2423,  2435,  2434,  2446,  2445,  2457,  2456,  2468,  2467,  2479,
    2478,  2490,  2489,  2501,  2500,  2515,  2518,  2524,  2533,  2555,
    2579,  2583,  2607,  2625,  2643,  2661,  2690,  2725,  2730,  2757,
    2771,  2790,  2796,  2802,  2805,  2814,  2824,  2825,  2826,  2827,
    2828,  2829,  2830,  2831,  2832,  2839,  2840,  2841,  2842,  2843,
    2844,  2845,  2846,  2847,  2848,  2849,  2850,  2851,  2852,  2853,
    2854,  2855,  2856,  2857,  2858,  2859,  2860,  2861,  2862,  2863,
    2864,  2865,  2866,  2867,  2868,  2869,  2870,  2872,  2873,  2874,
    2875,  2876,  2877,  2878,  2879,  2880,  2881,  2882,  2883,  2884,
    2885,  2886,  2887,  2888,  2889,  2890,  2891,  2892,  2901,  2902,
    2903,  2904,  2905,  2906,  2907,  2911,  2927,  2942,  2962,  2976,
    2989,  3012,  3030,  3048,  3066,  3084,  3092,  3096,  3100,  3104,
    3108,  3115,  3119,  3123,  3127,  3134,  3139,  3147,  3152,  3156,
    3161,  3165,  3173,  3184,  3192,  3200,  3206,  3217,  3237,  3247,
    3257,  3267,  3284,  3311,  3316,  3320,  3324,  3337,  3341,  3353,
    3360,  3382,  3386,  3401,  3406,  3413,  3417,  3424,  3428,  3436,
    3444,  3458,  3472,  3476,  3495,  3517
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
  "tGrad", "tReturn", "tCall", "tFunction", "tShow", "tHide", "tGetValue",
  "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION",
  "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'",
  "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL",
  "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC",
  "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'",
  "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems",
  "GeoFormatItem", "SendToFile", "Printf", "View", "Views",
  "ElementCoords", "ElementValues", "Element", "@1", "@2", "Text2DValues",
  "Text2D", "@3", "Text3DValues", "Text3D", "@4", "InterpolationMatrix",
  "Time", "@5", "Grain", "NumericAffectation", "NumericIncrement",
  "Affectation", "PhysicalId", "Shape", "Transform", "MultipleShape",
  "ListOfShapes", "Duplicata", "Delete", "Colorify", "Visibility",
  "Command", "Loop", "Extrude", "@6", "@7", "@8", "@9", "@10", "@11",
  "@12", "@13", "@14", "@15", "@16", "@17", "@18", "@19",
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
     365,   366,   367,   368,   369,   370,   371,    63,   372,   373,
     374,   375,    60,    62,   376,   377,    43,    45,    42,    47,
      37,    33,   378,   379,   380,    94,    40,    41,    91,    93,
      46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   146,   147,   147,   148,   148,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   150,   150,   151,   151,   151,   151,   152,   152,   153,
     153,   153,   153,   153,   153,   153,   154,   154,   155,   155,
     157,   158,   156,   159,   159,   161,   160,   162,   162,   164,
     163,   165,   165,   167,   166,   168,   169,   169,   169,   169,
     169,   170,   170,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   172,   172,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   174,
     174,   174,   174,   175,   175,   175,   176,   176,   176,   176,
     176,   176,   177,   177,   177,   177,   178,   178,   178,   178,
     179,   180,   180,   180,   180,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   183,   183,   183,   184,   183,
     185,   183,   186,   183,   187,   183,   188,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   189,   183,   190,
     183,   191,   183,   192,   183,   193,   183,   194,   183,   195,
     183,   196,   183,   197,   183,   198,   198,   199,   199,   199,
     199,   199,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   201,   201,   201,   201,   202,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   205,   205,   205,   205,
     205,   206,   206,   206,   206,   207,   207,   208,   208,   208,
     208,   208,   208,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   210,   210,   210,   210,   211,   211,   211,
     211,   212,   212,   213,   213,   214,   214,   215,   215,   215,
     215,   215,   215,   215,   215,   215
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
       9,     9,     9,     1,     1,     7,     8,     9,     8,     9,
       8,     5,     6,     6,     6,     7,     7,     7,     9,     7,
       9,    17,     7,     7,    11,     8,     8,     8,     8,     3,
       4,    10,     7,     7,     8,     8,     8,     7,     8,     5,
      11,     5,     9,     1,     1,     1,     0,     2,     6,     6,
       6,     6,     4,     6,     6,     6,     4,     6,     3,     4,
       5,     3,     3,     4,     4,     3,     7,     7,     3,     7,
       3,     2,     2,    15,     2,     6,     8,     8,    10,     1,
       2,     1,     3,     4,     1,     5,    11,    13,     0,     7,
       0,    13,     0,    15,     0,     6,     0,    10,     8,     8,
       8,    12,    12,    12,    14,    14,    14,     0,    12,     0,
      12,     0,    12,     0,    16,     0,    16,     0,    16,     0,
      18,     0,    18,     0,    18,     1,     2,     5,     7,     9,
       2,     9,     6,     9,     9,     8,     9,     8,     8,     6,
       4,    10,    10,    10,    10,     2,     1,     3,     2,     2,
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
       1,     3,     6,     1,     1,     3,     3,     9,     7,     1,
       5,     3,     6,     1,     3,     1,     1,     1,     1,     6,
       4,     4,     4,     6,     6,     9
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
       0,     0,     0,     0,     0,     0,     0,     0,   159,     0,
     164,     0,     0,     0,   161,     0,     0,     0,     0,     5,
       7,     6,     8,     9,    10,    11,    12,    13,    14,    20,
      19,    15,    16,    17,    18,   288,   295,   347,    56,   289,
     290,   291,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   348,     0,   292,
     293,   294,    60,    59,    58,    57,     0,     0,     0,    62,
      61,     0,     0,     0,     0,     0,     0,     0,   226,     0,
       0,     0,     0,   152,     0,   154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     306,     0,     0,     0,     0,     0,     0,   126,     0,     0,
     126,     0,     0,   126,   225,     0,     0,     0,     0,     0,
       0,     0,     0,   339,     0,     0,     0,     0,     0,   151,
       0,     0,     0,   160,     0,   346,   347,   126,     0,   345,
     126,     0,     0,     0,     0,     0,   299,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,   229,   228,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      68,   148,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,   109,     0,
       0,     0,     0,   295,     0,     0,   328,   329,   330,   333,
     334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   317,     0,   318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   308,   307,     0,     0,     0,     0,
     126,   126,     0,     0,     0,     0,     0,     0,     0,     0,
     174,     0,   126,     0,     0,     0,     0,   138,     0,     0,
       0,     0,     0,     0,     0,   150,     0,     0,     0,     0,
       0,   126,     0,     0,     0,     0,     0,   162,     0,     0,
     141,     0,   142,     0,     0,   301,     0,     0,     0,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   346,     0,     0,     0,     0,     0,     0,   227,
       0,     0,     0,     0,    56,     0,     0,     0,     0,     0,
      63,     0,   244,   243,   242,   241,   237,   238,   240,   239,
     232,   231,   233,   234,   235,   236,   110,     0,     0,     0,
       0,     0,     0,   228,   323,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,     0,     0,
       0,     0,     0,     0,     0,   310,   309,   125,     0,   124,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,   168,     0,   132,   220,
       0,   139,     0,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,     0,     0,
       0,   143,   144,     0,   297,   303,     0,    29,    40,     0,
       0,     0,    53,     0,     0,    30,    31,    32,    33,    34,
      35,   246,   267,   247,   268,   248,   269,   249,   270,   250,
     271,   251,   272,   252,   273,   253,   274,   254,   275,   266,
     287,   255,   276,     0,     0,   257,   278,   258,   279,   259,
     280,   260,   281,   261,   282,   262,   283,     0,     0,     0,
       0,     0,     0,     0,     0,   352,     0,     0,   350,   351,
       0,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,    75,     0,     0,     0,     0,   298,     0,    23,    21,
       0,     0,     0,     0,   331,     0,     0,   325,   233,   324,
     335,   336,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,   320,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   119,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,     0,   165,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   140,     0,
       0,     0,     0,     0,     0,     0,   300,     0,   296,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     297,    66,    67,     0,     0,     0,     0,     0,    69,    71,
      73,     0,     0,   343,     0,    79,   245,    22,     0,     0,
       0,     0,     0,   327,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   321,     0,
      94,     0,     0,     0,     0,     0,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,     0,     0,     0,     0,     0,     0,     0,   210,     0,
       0,   175,   206,     0,     0,   133,   219,   137,     0,    92,
      93,   134,   135,     0,     0,     0,   340,     0,     0,     0,
     155,     0,     0,     0,   147,   302,   146,     0,     0,     0,
       0,     0,   315,     0,     0,   256,   277,   263,   284,   264,
     285,   265,   286,     0,   354,   353,   349,   305,     0,    56,
       0,     0,     0,     0,    64,     0,     0,     0,   341,    24,
      25,     0,     0,    85,     0,   326,     0,    97,     0,    99,
       0,     0,    95,     0,     0,   112,   113,     0,     0,    96,
     117,   322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
       0,   126,   176,     0,   187,     0,   189,     0,   191,     0,
       0,     0,     0,   317,     0,     0,     0,     0,   169,     0,
     102,   103,     0,     0,     0,     0,     0,     0,     0,   304,
      28,     0,    36,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,    76,     0,     0,    77,     0,   344,
       0,     0,   332,     0,     0,     0,   105,     0,     0,   114,
       0,     0,     0,   217,   107,   108,     0,     0,     0,   215,
     218,   116,    86,   106,   115,   118,     0,     0,     0,   314,
       0,   313,     0,     0,     0,   178,     0,     0,   179,     0,
       0,   180,     0,   128,   129,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,   338,     0,   157,   156,    88,
      90,     0,    41,     0,     0,     0,   316,     0,     0,     0,
       0,     0,    65,    72,    74,     0,    80,     0,    26,     0,
       0,    98,   100,     0,     0,     0,     0,     0,   214,   213,
     216,    81,    82,   126,     0,   122,     0,     0,     0,     0,
       0,     0,     0,   207,     0,     0,   126,     0,    87,     0,
       0,     0,    89,     0,    37,     0,     0,     0,    39,    54,
      55,   355,     0,   342,     0,   221,   222,   223,   224,   111,
       0,     0,     0,   312,   177,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   170,     0,     0,
     337,   158,     0,     0,     0,     0,    78,     0,     0,   120,
       0,   193,     0,     0,   195,     0,     0,   197,     0,     0,
       0,   208,     0,   166,     0,   126,   104,     0,    45,     0,
      51,     0,     0,     0,   311,   181,     0,     0,   188,   182,
       0,     0,   190,   183,     0,     0,   192,     0,     0,     0,
     172,     0,     0,     0,     0,     0,     0,     0,   199,     0,
     201,     0,   203,   209,   211,   171,   167,     0,    42,     0,
      49,     0,     0,     0,     0,   184,     0,     0,   185,     0,
       0,   186,     0,     0,     0,    43,     0,     0,   153,     0,
       0,     0,     0,     0,     0,     0,   173,     0,     0,     0,
       0,     0,   194,     0,   196,     0,   198,     0,    44,    46,
       0,    47,     0,   101,     0,     0,     0,     0,     0,    52,
     200,   202,   204,    48,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    59,   660,    60,    61,   398,   971,   977,
     585,   750,  1103,  1224,   586,  1192,  1250,   587,  1226,   588,
     589,   754,   590,   125,   216,    62,   515,   543,   306,   528,
     529,   307,    66,    67,    68,    69,    70,   308,   724,  1164,
    1207,   544,  1023,  1026,  1029,  1032,  1176,  1180,  1184,  1216,
    1219,  1222,   720,   721,    72,    73,    74,   326,   128,   344,
     170,   871,   872,   328,   311,   195,   655,   784,   208,   209
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1054
static const yytype_int16 yypact[] =
{
    3072,    59,    69,  3149, -1054, -1054,  2271,    73,    54,   -42,
      25,   100,   169,   -12,     4,   -41,    44,    76,   -62,   157,
     163,    96,   -28,   154,   221,   253,   508,   260,    29,   206,
     203,   -72,   -72,   222,    30,     2,   327,    15,   367,    13,
     375,   378,   398,   269,   285,   291,    18,    40, -1054,   303,
   -1054,   442,   352,   380, -1054,   448,    20,    10,    24, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054,    14,    21,   381, -1054,
   -1054, -1054,   -54,   -29,   172,   226,   299,   333,   376,   387,
     396,   412,   428,   446,   468,   469,   498,   541,   577,   578,
     594,   605,   606,   347,   379,   401,   406, -1054,   420, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054,  2481,  2481,  2481, -1054,
   -1054,  2481,  2031,    23,   484,  2481,   497,  1134, -1054,   501,
     565,  2481,   571, -1054,  2481, -1054,  2481,  2410,  2481,  2481,
     457,  2481,  2410,  2481,  2481,   460,  2410,  2481,  2481,  1420,
     465,  2481,   467,   478,   482,  1690,   486,   522,   505,   521,
     525,   536,   558,   694,   -72,   -72,   -72,  2481,  2481,   -22,
   -1054,    70,   -72,   566,   556,   562,   588,  2236,   132,   625,
   -1054,  1690,    33, -1054, -1054,  1555,  1690,   626,   634,   739,
    2481,  2481,  2481,   635,  2481,   640,   684,  2481,  2481, -1054,
     643,   656,   787, -1054,   682, -1054, -1054, -1054,   813, -1054,
   -1054,   827,   698,  2481,   837,   699, -1054,   -72, -1054,   844,
    2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,
    2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,
    2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,
    2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,
    2481,  2481,   607,   664,   664,   664,   872,   636,   748,   748,
     748,  5428,    67,  2410,  3161,   371,   744,   879,   749,  1191,
   -1054, -1054,  2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,
    2481,  2481,  2481,  2481,  2481,  2481,  2481, -1054, -1054,  1347,
    -101,  3961,  5449,   675,   746,  2410, -1054, -1054, -1054,  1483,
   -1054,   609,  5470,  5491,  2481,  5512,   610,  5533,  5554,  2481,
     617,  5575,  5596,  1690,  1825,  1264,  1618,   884, -1054,  2481,
    5617,  2481,  2481,  2481,   885,  2481,  2481,  2481,  2539,  2539,
    2539,  2539,   756,   305, -1054, -1054,  3987,  4013,   -72,   -72,
     670,   670,   413,  2481,  2481,  2481,  2481,  2236,  2236,  2481,
    3217,   436, -1054,  2481,  2585,   315,   888, -1054,  2481,  2649,
     759,   889,   890,  2481,  2481, -1054,  5638,  5659,  5680,   807,
    4039, -1054,   757,  1753,  5701,  2481,  2481, -1054,  2481,  2671,
   -1054,  2735, -1054,  2481,  4715,   261,  2481,   218,     7, -1054,
    5722,  4738,  5743,  4761,  5764,  4784,  5785,  4807,  5806,  4830,
    5827,  4853,  5848,  4876,  5869,  4899,  5890,  4922,  5911,  4945,
    5932,  4968,  4065,  4091,  5953,  4991,  5974,  5014,  5995,  5037,
    6016,  5060,  6037,  5083,  6058,  5106,  4117,  4143,  4169,  4195,
    4221,  4247,   622,   -92,   760,   762,   766,   763,  2481, -1054,
    1690,  1690,   629,   300,   381,  2481,   898,   902,    22,   768,
   -1054,  1888,   676,   598,   702,   702,   557,   557,   557,   557,
     137,   137,   748,   748,   748,   748, -1054,    27,  2410,  2481,
     903,  2095,  2481,   748, -1054,  2481,  2410,  2410,   817,   905,
     907,  6079,   908,   822,   910,   911,  6100,   825,   913,   914,
     918,  2410, -1054,   638,  1960,  2481,  6121,   919,  3291,  6142,
    6163,  2481,  3319,  3347,  6184,   788,  6520, -1054,   790,   791,
     793,   794,   -72,  2481,  2481, -1054, -1054, -1054,   789,  3217,
   -1054,   795,  2481,  5129,  4273,  4299,  4325,  3935,   180,    39,
     -18,   254,   832, -1054,   561,   -72,  2757,  5152, -1054, -1054,
    2481, -1054,  5175, -1054,  2481,  1690,  1690,  5198,  5221,   930,
     931,   933,   801,  2481,  2821,  2481,  2481, -1054,  6205,  6226,
    6247, -1054, -1054,  5244,   259, -1054,  3375, -1054, -1054,   806,
     811,   800, -1054,   812,   943, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054,  2481,  2481, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054,  2481,  2481,  2481,
    2481,  2481,  2481,  2481,   947, -1054,  2410,   664, -1054, -1054,
    2481,  5267,   946,   961,   831, -1054,    31,  2481,   966,   967,
    1383, -1054,   968,   838,    18,   971, -1054,  2481, -1054,   851,
     664,    -7,  4351,   -72, -1054,  2410,  3403,  2851,   748, -1054,
    1483, -1054,   929,  1690,  1690,   972,  1690,   735,  1690,  1690,
     974,   934,  1690,  1690, -1054,   646, -1054,  2410,  1518,   980,
     845,   982,   983,   984,   337,   985,   986,   987,   988,   989,
    1006,  1007,  1012,   461,  4377,  4403, -1054, -1054,  3431,   875,
     -72,   -72,   -72,  2410,  2410,  2410,  2410,  1013,   877,   886,
     185, -1054,   471, -1054,   561,  1015,  1653,  1017,  6268,  1018,
    1019,  1021,  1022,  1690,  1690,  1690,  1025,  4429, -1054,  2975,
    1112,  1023,  1024,  1026,  1028,  1031, -1054,  1032, -1054,    16,
     896,  2481,  2481,  1690,   894,  2481, -1054,  6289,  5290,  6310,
    5313,  6331,  5336,  6352,  5359,  5382,   906,   134,   909,  6373,
     514, -1054, -1054,    86,   377,   900,  1035,  1788, -1054, -1054,
   -1054,    18,  2481, -1054,   668, -1054,  6520, -1054,  1038,    32,
    2481,     1,   672, -1054,  2481,   904,    36,    45,  1690,  1039,
     912,   915,  1043,  1044,  1690,   916,  1045,  1046, -1054,   703,
   -1054,  1049,  2481,  1690,  1690,  1690, -1054,   432,  1690,  1690,
    1690,  1690,  1690,  1690,  1690,   683,  2481,  2481,  2481,   917,
   -1054,   -59,   245,   382,   704,   707,   713,   714, -1054,  1690,
    2481, -1054, -1054,  2236,   197, -1054, -1054, -1054,  1050, -1054,
   -1054, -1054, -1054,  1055,  1058,   976, -1054,  2481,  2481,  2481,
   -1054,  1690,  1051,  1064, -1054,   261, -1054,  1067,  2481,  4455,
    4481,   717, -1054,  2481,  6394, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054,   935, -1054, -1054, -1054, -1054,  1690,   381,
    2481,  1068,  1066,    22, -1054,  1070,  5405,    18, -1054, -1054,
   -1054,   664,  4507, -1054,   938,  6520,  2481, -1054,   -72, -1054,
     -72,  1072, -1054,  2481,  2481, -1054, -1054,  1073,  2481, -1054,
   -1054, -1054,  1075,  4533,  1077,  1079,  1081,  2481,  2481,   856,
    1083,  1084,  1085,  1087,  1089,  1090, -1054,  2539,  3459,  6415,
    3207,   670,  3217,   -72,  1091,   -72,  1092,   -72,  1093,  1096,
    1097,  1098,  1099,   836,   939,  6436,  3487,   473, -1054,  1690,
   -1054, -1054,  1690,  3235,   882,  6457,  1100,  1101,  1690, -1054,
   -1054,   267,  6520,  2481,  2481,  1690,   965,   722,  6520,  1690,
    1106,  1105,  1107,  2060, -1054,  1109,  1108, -1054,   978, -1054,
    1113,  2481, -1054,  3515,    51,    64, -1054,  3543,  3571, -1054,
    3599,  1116,  2481, -1054, -1054, -1054,  2197,  2337,  1119, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054,  2898,  1120,   969, -1054,
    2481, -1054,   990,   561,   490, -1054,   992,   524, -1054,   993,
     529, -1054,   995, -1054, -1054, -1054, -1054,  1121,  1690,  1122,
     996,  2481,  1124,  1042,  2481, -1054,  2481, -1054, -1054, -1054,
   -1054,  1126, -1054,  2481,  4559,  4585, -1054,  1690,  2481,  1127,
    1135,   991, -1054, -1054, -1054,    18, -1054,  1052, -1054,  4611,
    1136, -1054, -1054,  1137,  1139,  1140,  1142,  4637, -1054, -1054,
   -1054, -1054, -1054,   670,  3263, -1054,   241,  2236,   561,  2236,
     561,  2236,   561, -1054,   723,  1690, -1054,  3627, -1054,  2481,
    3655,  3683, -1054,  1009,  6520,  2481,  2481,   727,  6520, -1054,
   -1054, -1054,  1143, -1054,  2481, -1054, -1054, -1054, -1054, -1054,
    1149,  1011,  2481, -1054, -1054,  3711,   532,   298,  3739,   549,
     324,  3767,   554,   331,  1690,  1150,  1102,  2843,  1016,  2917,
   -1054, -1054,  2481,  6478,  4663,    26, -1054,  4689,  1020, -1054,
    3795,  1152,  2481,  1154,  1155,  2481,  1159,  1160,  2481,  1162,
    1027, -1054,  2481, -1054,   561, -1054, -1054,   728, -1054,  2481,
   -1054,  1690,  2481,  1164, -1054, -1054,  1029,  3823, -1054, -1054,
    1030,  3851, -1054, -1054,  1033,  3879, -1054,  1168,  2936,   334,
    2907,  1169,  1034,  6499,   731,  3907,  1036,   561,  1177,   561,
    1178,   561,  1179, -1054, -1054, -1054, -1054,   561, -1054,   664,
   -1054,  1047,  1180,  1165,   353, -1054,  1048,   369, -1054,  1053,
     445, -1054,  1057,   475,   732, -1054,  1062,  1690, -1054,  1054,
    1182,   561,  1183,   561,  1186,   561, -1054,   664,  1188,   664,
     736,  1189, -1054,   496, -1054,   509, -1054,   518, -1054, -1054,
     737, -1054,  1195, -1054,  1200,  1208,  1210,   664,  1212, -1054,
   -1054, -1054, -1054, -1054, -1054
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1054, -1054, -1054, -1054,   431, -1054, -1054,   644, -1054,    80,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054,  -272,    17, -1054,  -130,  1220,     5,  -349,
    -167,     9, -1054, -1054, -1054, -1054, -1054,  1221, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054,  -666,  -550, -1054, -1054, -1054,    -5, -1054,   272,
   -1054, -1053,   389,    42,    52,  -637,   332, -1054,   -58,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     211,   127,   531,   455,  1107,   129,   179,   903,    64,   145,
     360,   578,    65,   364,   205,   206,   369,   783,   212,   182,
     578,   150,   193,   126,   203,   217,   653,   275,   205,   206,
     140,   133,  1170,   658,   173,   774,   477,   366,   900,   367,
     389,   478,   907,   391,   196,   635,   103,   104,   105,   106,
     636,   909,   107,   145,   165,   166,   185,  1071,   844,   186,
     103,   104,   105,   106,   167,     4,   107,   348,   349,     5,
    1072,   168,   159,   174,   450,   160,   175,   219,   161,   176,
     162,   146,   220,   943,   221,   944,   130,   579,   580,   581,
     582,   583,   908,   645,   132,   141,   579,   580,   581,   582,
     583,   910,   142,   131,   348,   349,   135,   222,   151,   223,
     140,   268,   269,   270,   276,   277,   271,   274,  1194,   204,
     279,   350,   775,   776,   138,   715,   299,   348,   349,   301,
     789,   302,   309,   312,   313,   487,   315,   309,   317,   318,
     139,   309,   321,   322,   895,   180,   330,   119,   120,   149,
     659,   584,   213,   207,   214,   659,   165,   166,   183,   215,
     867,   194,   346,   347,   218,   654,   167,   210,   134,  1171,
     842,   368,   347,   177,  1240,   141,   197,   348,   349,   310,
     143,   647,   714,   451,   310,   376,   377,   378,   310,   380,
     348,   349,   383,   384,   316,   546,   348,   349,   320,   112,
     113,   114,   115,   152,   443,   444,   445,   446,   394,   518,
     519,   520,   144,   351,   564,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   717,   348,   349,
     989,   718,   719,   205,   206,   293,   294,   295,   309,   717,
     153,   885,   296,   718,   719,   362,   487,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   456,   147,   842,   103,   104,   105,   106,   148,
     483,   107,   154,   169,   171,   136,   178,   645,   224,   491,
     225,   158,   137,   717,   496,   310,   136,   718,   719,   483,
     309,   549,   550,   713,   506,   452,   508,   509,   510,   841,
     512,   513,   514,   516,   516,   516,   516,   517,   517,   517,
     517,   958,   163,   816,   348,   349,   164,   484,   533,   534,
     535,   536,   268,   269,   537,   527,   527,  1086,   547,   530,
     530,   577,   226,   552,   227,   172,   484,   310,   557,   558,
     717,   348,   349,   184,   718,   719,   181,   503,   454,   187,
     568,   569,   188,   570,   889,  1124,   206,   945,   573,   946,
     148,   576,   119,   120,   119,   120,   717,   716,   817,   745,
     718,   719,   189,   717,  1052,   190,   717,   718,   719,  1053,
     718,   719,   575,   112,   113,   114,   115,   103,   104,   105,
     106,   191,  1127,   107,  1130,   717,  1133,   192,  1112,   718,
     719,   348,   349,   119,   120,   228,   343,   229,   345,   198,
     646,   717,  1153,   641,   352,   718,   719,   522,   199,   361,
     650,   200,   202,   649,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,  1156,   230,
     648,   231,   296,   309,   662,  1159,   641,   666,  1205,   201,
     667,   668,   670,   262,   112,   113,   114,   115,   278,   397,
     112,   113,   114,   115,   927,   928,   309,  1230,  1189,   668,
     688,   888,   890,   280,   119,   120,   694,   297,   348,   349,
     119,   120,   232,  1232,   233,   263,   747,   717,   704,   705,
     310,   718,   719,   234,   947,   235,   948,   708,   669,   671,
     661,  1214,   236,  1217,   237,  1220,   842,   264,   327,   348,
     349,  1223,   265,   310,   334,   726,   669,   717,   238,   728,
     239,   718,   719,   685,   155,   532,   266,   156,   737,   157,
     739,   740,   348,   349,   240,  1243,   241,  1245,   717,  1247,
     365,   298,   718,   719,   371,   372,   300,   842,   545,   768,
     842,   717,   242,   842,   243,   718,   719,   348,   349,  1234,
     717,   746,  1022,   314,   718,   719,   319,   348,   349,   348,
     349,   329,   788,   826,   244,   246,   245,   247,   757,   758,
     331,   442,   206,   843,   332,  1041,   348,   349,   333,  1236,
     525,   526,   759,   760,   761,   762,   763,   764,   765,   335,
     345,   309,  1087,   717,   248,   769,   249,   718,   719,   842,
    1254,   337,   777,   103,   104,   105,   106,   119,   120,   107,
     348,   349,   786,  1255,   745,   348,   349,   338,   348,   349,
     309,   339,  1256,   942,   842,   336,  1089,   842,   205,   206,
     842,  1091,   340,   842,  1152,   348,   349,   250,   310,   251,
     348,   349,   309,   291,   292,   293,   294,   295,   767,   936,
     937,  1155,   296,   842,   341,   842,  1158,   842,   342,   354,
     103,   104,   105,   106,   353,   355,   107,   310,   309,   309,
     309,   309,   500,   252,   254,   253,   255,   792,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   310,
     256,   356,   257,   296,  1121,    30,    31,    32,    33,   809,
      35,   258,   260,   259,   261,   375,   869,   870,    40,    41,
     874,   487,   487,   488,   493,   310,   310,   310,   310,   487,
     633,   497,   634,   363,   373,   834,   835,   836,   837,   119,
     120,   487,   374,   644,   448,   379,   214,   896,   382,   385,
     487,   215,   686,   381,   800,   902,   801,   746,   487,   905,
     808,   891,   386,   387,   703,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   923,   119,   120,
     897,   296,   898,   481,   487,   214,   904,   722,   388,   390,
     215,   938,   939,   940,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   392,   953,   955,   393,   296,   956,   642,
     643,   395,   396,   990,   485,   487,   487,   921,   949,   487,
     399,   950,   963,   964,   965,   487,   487,   951,   952,   975,
    1008,   976,  1009,   972,  1058,  1134,  1059,  1135,   978,   975,
    1058,  1145,  1191,   975,  1237,  1211,  1238,   447,   975,  1257,
    1252,  1258,   969,   296,   457,   983,   458,   459,   982,   482,
    1046,   505,   511,   521,   551,   554,   555,   556,   562,   638,
     565,   993,   637,   639,   651,   640,   652,   656,   997,   998,
     663,   672,   673,  1000,   674,   676,   677,   678,   679,   681,
     682,   683,  1006,  1007,   684,   698,   690,   699,   700,  1137,
     701,   204,  1016,   706,   702,   791,  1017,   733,   734,   707,
     735,   736,   751,   753,   729,   730,   527,   752,   755,   756,
     530,   766,   771,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   504,   294,   295,   772,  1054,  1055,
     773,   296,   778,   779,   787,   781,   782,   785,   795,   798,
    1037,   804,   831,   832,   833,   805,  1069,   811,   812,   813,
     814,   815,   818,   819,   820,   821,   822,  1077,  1190,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   823,   824,  1084,   825,   296,   830,   838,
     839,   845,   840,   847,   849,   850,  1047,   851,   852,   856,
     861,   862,   868,   863,   864,   865,  1097,   873,   866,  1100,
     892,  1101,   893,   884,   899,   912,   886,   906,  1104,   915,
     916,   919,   920,  1108,   922,   913,   967,   959,   914,   918,
     941,   960,   796,   797,   961,   799,   962,   802,   803,   968,
     985,   806,   807,   970,   984,   980,   987,   992,   996,   999,
    1001,  1038,  1125,  1003,  1128,  1004,  1131,  1005,   527,  1010,
    1011,  1012,   530,  1013,  1139,  1014,  1015,  1025,  1028,  1031,
    1143,  1144,  1033,  1034,  1035,  1036,  1049,  1050,  1057,  1147,
    1061,  1062,  1083,  1063,  1066,   957,  1065,  1150,  1067,  1068,
     859,  1076,   853,   854,   855,  1080,  1082,  1093,  1111,  1095,
    1098,  1099,  1102,  1109,  1085,  1088,  1090,   978,  1092,  1096,
     281,  1110,  1115,  1116,  1113,  1117,  1118,  1177,  1119,  1146,
    1181,  1225,  1142,  1185,  1148,  1149,  1161,  1188,  1175,  1165,
    1178,  1179,  1173,  1162,  1193,  1182,  1183,  1195,  1186,  1196,
    1229,  1187,  1197,  1199,  1203,  1208,  1201,  1209,  1213,  1248,
     994,  1251,   995,  1215,  1218,  1221,  1228,   911,  1242,  1244,
    1227,  1231,  1246,   917,  1249,  1253,  1233,   460,  1241,  1263,
    1235,  1259,   924,   925,   926,  1239,  1260,   929,   930,   931,
     932,   933,   934,   935,  1261,  1024,  1262,  1027,  1264,  1030,
     901,   749,  1167,    63,    71,   986,     0,     0,   954,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,   860,
     966,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,    75,   303,   296,
       0,     0,     0,    79,    80,    81,     0,   981,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,   304,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,     0,     0,     0,  1042,     0,
       0,  1043,     0,   476,     0,     0,     0,  1051,     0,  1126,
       0,  1129,     0,  1132,  1056,     0,     0,     0,  1060,     0,
       0,     0,     0,   108,   109,   110,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   780,
     116,   305,     0,     0,     0,   118,     0,     0,     0,     0,
     121,     0,     0,     0,     0,   124,     0,     0,   502,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,   303,     0,     0,  1094,     0,    79,
      80,    81,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,   304,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,  1136,    30,    31,    32,    33,    34,
      35,   485,     0,     0,     0,     0,     0,     0,    40,    41,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,   323,
       0,     0,     0,  1160,   810,     0,     0,     0,     0,   108,
     109,   110,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,   324,     0,     0,
       0,   118,     0,     0,     0,     0,   121,     0,    75,   303,
       0,   124,     0,   325,    79,    80,    81,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,   304,     0,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   486,   294,   295,     0,     0,     0,     0,   296,     0,
      30,    31,    32,    33,    34,    35,   485,     0,     0,     0,
       0,     0,     0,    40,    41,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,   370,     0,     0,     0,     0,   846,
       0,     0,     0,     0,   108,   109,   110,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   324,     0,     0,     0,   118,     0,     0,     0,
       0,   121,     0,    75,   303,     0,   124,     0,   325,    79,
      80,    81,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,   304,     0,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   504,   294,   295,     0,
       0,     0,     0,   296,     0,    30,    31,    32,    33,    34,
      35,   566,     0,     0,     0,     0,     0,     0,    40,    41,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,   894,     0,     0,     0,     0,   108,
     109,   110,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,   324,     0,     0,
       0,   118,     0,     0,     0,     0,   121,     0,    75,   303,
       0,   124,     0,   325,    79,    80,    81,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,   304,     0,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
      30,    31,    32,    33,    34,    35,   657,     0,     0,     0,
       0,     0,     0,    40,    41,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   109,   110,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   305,     0,     0,     0,   118,     0,     0,     0,
       0,   121,     0,    75,   303,     0,   124,     0,   501,    79,
      80,    81,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,   304,     0,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,    30,    31,    32,    33,    34,
      35,     0,     0,     0,    75,   267,     0,     0,    40,    41,
      79,    80,    81,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,  1064,     0,     0,   108,
     109,   110,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,   305,     0,     0,
       0,   118,     0,     0,     0,     0,   121,     0,    75,   267,
       0,   124,     0,   687,    79,    80,    81,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,   109,   110,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   117,     0,
       0,     0,   118,     0,     0,     0,     0,   121,     0,     0,
     272,     0,   124,     0,   273,     0,     0,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,     0,  1078,   108,   109,   110,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   117,     0,     0,     0,   118,     0,     0,     0,
       0,   121,     0,     0,   664,     0,   124,     0,   665,    75,
     267,     0,     0,     0,     0,    79,    80,    81,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,    75,    76,    77,     0,    78,     0,
      79,    80,    81,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,   103,   104,   105,
     106,     0,     0,   107,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1079,     0,   108,   109,   110,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   357,   358,     0,     0,     0,   118,     0,     0,
       0,     0,   359,     0,     0,     0,     0,   124,     0,   168,
     108,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   117,     0,
       0,     0,   118,     0,   119,   120,     0,   121,     0,   122,
       0,   123,   124,    75,   303,     0,     0,     0,     0,    79,
      80,    81,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,   304,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,    30,    31,    32,    33,    34,
      35,     0,     0,     0,    75,   267,     0,     0,    40,    41,
      79,    80,    81,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   108,
     109,   110,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,   305,     0,     0,
       0,   118,    75,   267,   206,     0,   121,     0,    79,    80,
      81,   124,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,   103,   104,   105,   106,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
     108,   109,   110,   111,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   117,     0,
       0,     0,   118,     0,     0,     0,     0,   121,     0,     0,
       0,     0,   124,     0,     0,     0,     0,     0,   538,    13,
      14,   539,    16,    17,   540,    19,   541,    21,     0,    22,
       0,    24,    25,     0,    27,    28,     0,     0,   108,   109,
     110,   111,     0,     0,     0,     0,     0,     0,     0,     0,
      39,     7,     8,     0,     0,   116,   117,     0,     0,     0,
     118,    43,    44,    45,     0,   121,     0,     0,     0,     0,
     124,     0,     0,     7,     8,    52,    53,     0,     0,     0,
       0,   542,   538,    13,    14,   539,    16,    17,   540,    19,
     541,    21,     0,    22,     0,    24,    25,     0,    27,    28,
       0,     0,     0,     0,   538,    13,    14,   539,    16,    17,
     540,    19,   541,    21,    39,    22,     0,    24,    25,   548,
      27,    28,     0,     0,     0,    43,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     7,     8,    52,
      53,     0,     0,     0,     0,   542,     0,    43,    44,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,    52,    53,     0,     0,     0,     0,   542,   538,    13,
      14,   539,    16,    17,   540,    19,   541,    21,     0,    22,
       0,    24,    25,   553,    27,    28,     0,     0,     0,     0,
     538,    13,    14,   539,    16,    17,   540,    19,   541,    21,
      39,    22,     0,    24,    25,   571,    27,    28,     0,     0,
       0,    43,    44,    45,     0,     0,     0,     0,     0,     0,
       0,     0,    39,     7,     8,    52,    53,     0,     0,     0,
       0,   542,     0,    43,    44,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,    52,    53,   794,
       0,     0,     0,   542,   538,    13,    14,   539,    16,    17,
     540,    19,   541,    21,     0,    22,     0,    24,    25,   572,
      27,    28,     0,     0,     0,     0,   538,    13,    14,   539,
      16,    17,   540,    19,   541,    21,    39,    22,     0,    24,
      25,   723,    27,    28,  1081,     0,     0,    43,    44,    45,
       0,     0,     0,     0,     0,     0,     0,     0,    39,     7,
       8,    52,    53,  1166,     0,     0,     0,   542,     0,    43,
      44,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1204,    52,    53,     0,     0,     0,     0,   542,
     538,    13,    14,   539,    16,    17,   540,    19,   541,    21,
       0,    22,     0,    24,    25,   738,    27,    28,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,    39,   858,     0,     0,   296,  1163,     0,     0,
       0,     0,     0,    43,    44,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,     0,
       0,     0,     0,   542,     0,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,  1206,   296,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,    -4,     1,     0,     0,    -4,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,     0,     0,     0,     0,
       0,     0,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,    -4,     0,     0,
     296,     0,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,     0,     0,
      -4,    -4,     0,     6,     0,     0,     0,    -4,    -4,    -4,
      -4,     7,     8,    -4,     0,    -4,     0,    -4,    -4,    -4,
      -4,     0,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,
      -4,     0,     0,     0,     9,     0,     0,     0,     0,    10,
      11,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,    22,    23,    24,    25,    26,    27,    28,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
       0,    36,    37,    38,    39,     0,     0,    40,    41,     7,
       8,     0,     0,     0,    42,    43,    44,    45,     0,     0,
      46,     0,    47,     0,    48,    49,    50,    51,     0,    52,
      53,     0,     0,    54,    55,    56,    57,    58,     0,     0,
     538,    13,    14,   539,    16,    17,   540,    19,   541,    21,
       0,    22,     0,    24,    25,     0,    27,    28,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,    39,     0,     0,     0,   296,     0,     0,     0,
     453,     0,     0,    43,    44,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,     0,
       0,     0,     0,   542,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,  1020,
       0,  1021,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,     0,  1044,     0,  1045,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,  1122,     0,  1123,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
       0,     0,     0,     0,     0,   691,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,     0,     0,   695,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,   696,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,     0,     0,     0,   748,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,   793,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
       0,     0,     0,     0,     0,   829,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,     0,     0,  1018,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,  1040,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,     0,     0,     0,  1070,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,  1073,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
       0,     0,     0,     0,     0,  1074,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,     0,     0,  1075,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,  1138,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,     0,     0,     0,  1140,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,  1141,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
       0,     0,     0,     0,     0,  1151,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,     0,     0,  1154,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,  1157,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,     0,     0,     0,  1174,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,  1198,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
       0,     0,     0,     0,     0,  1200,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,     0,     0,  1202,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,  1212,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,   449,     0,     0,     0,     0,   523,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
       0,     0,     0,   479,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,   523,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,   524,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,   563,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,     0,   613,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
       0,     0,     0,   614,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,   627,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,   628,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,   629,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,     0,   630,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
       0,     0,     0,   631,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,   632,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,   710,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,   711,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,     0,   712,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
       0,     0,     0,   790,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,   827,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,   828,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,   857,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,     0,   973,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
       0,     0,     0,   974,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,   991,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,  1002,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,  1105,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,     0,  1106,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
       0,     0,     0,  1114,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,  1120,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,  1169,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,  1172,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,   574,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,   592,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
     594,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,   596,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,   598,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,   600,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,   602,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,   604,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,   606,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,   608,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,   610,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,   612,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
     616,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,   618,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,   620,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,   622,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,   624,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,   626,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,   709,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,   725,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,   727,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,   731,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
     732,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,   744,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,   770,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,   876,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,   878,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,   880,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,   882,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,   883,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,   988,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,   449,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,   480,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,   489,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,   490,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,   492,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
     494,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,   495,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,   498,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,   499,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,   507,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,   559,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,   560,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,   561,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,   567,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,   591,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
     593,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,   595,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,   597,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,   599,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,   601,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,   603,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,   605,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,   607,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,   609,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,   611,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
     615,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,   617,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,   619,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,   621,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,   623,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,   625,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,   675,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,   680,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,   689,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,   692,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
     693,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,   697,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,   741,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,   742,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,   743,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,   848,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,   875,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,   877,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,   879,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,   881,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
     887,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,   979,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,  1019,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,  1039,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,  1048,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,  1168,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,  1210,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296
};

static const yytype_int16 yycheck[] =
{
      58,     6,   351,   275,  1057,     6,     4,     6,     3,    71,
     177,     4,     3,   180,     4,     5,   183,   654,     4,     4,
       4,    49,     4,     6,     4,     4,     4,     4,     4,     5,
      71,     6,     6,     6,     4,     4,   137,     4,     6,     6,
     207,   142,     6,   210,     4,   137,    36,    37,    38,    39,
     142,     6,    42,    71,   126,   127,    43,     6,   724,    46,
      36,    37,    38,    39,   136,     6,    42,   126,   127,     0,
       6,   143,    43,    43,     7,    46,    46,    78,    49,    49,
      51,   143,   136,   142,   138,   144,    13,    80,    81,    82,
      83,    84,    56,     7,   136,   136,    80,    81,    82,    83,
      84,    56,   143,    49,   126,   127,     6,   136,   136,   138,
      71,   116,   117,   118,    91,    92,   121,   122,  1171,    99,
     125,   143,    91,    92,   136,   143,   131,   126,   127,   134,
     137,   136,   137,   138,   139,   142,   141,   142,   143,   144,
     136,   146,   147,   148,   781,   143,   151,   133,   134,    53,
     123,   144,   138,   143,   140,   123,   126,   127,   143,   145,
     144,   143,   167,   168,   143,   143,   136,   143,   143,   143,
     720,   138,   177,   143,  1227,   136,   136,   126,   127,   137,
     136,   453,   143,   116,   142,   190,   191,   192,   146,   194,
     126,   127,   197,   198,   142,   362,   126,   127,   146,   113,
     114,   115,   116,    49,   262,   263,   264,   265,   213,   339,
     340,   341,   136,   143,   381,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,    72,   126,   127,
     897,    76,    77,     4,     5,   128,   129,   130,   273,    72,
      49,   137,   135,    76,    77,   143,   142,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   275,   136,   844,    36,    37,    38,    39,   136,
     305,    42,    49,    31,    32,   136,    34,     7,   136,   314,
     138,    51,   143,    72,   319,   273,   136,    76,    77,   324,
     325,     6,     7,   143,   329,   273,   331,   332,   333,   144,
     335,   336,   337,   338,   339,   340,   341,   338,   339,   340,
     341,   144,   136,     6,   126,   127,   143,   305,   353,   354,
     355,   356,   357,   358,   359,   350,   351,  1023,   363,   350,
     351,   143,   136,   368,   138,   143,   324,   325,   373,   374,
      72,   126,   127,     6,    76,    77,    49,   325,     7,     4,
     385,   386,     4,   388,     7,   144,     5,   142,   393,   144,
     136,   396,   133,   134,   133,   134,    72,   143,    61,   140,
      76,    77,     4,    72,   137,   136,    72,    76,    77,   142,
      76,    77,   395,   113,   114,   115,   116,    36,    37,    38,
      39,   136,  1088,    42,  1090,    72,  1092,   136,  1065,    76,
      77,   126,   127,   133,   134,   136,   164,   138,   166,   136,
     140,    72,   144,   448,   172,    76,    77,   142,     6,   177,
     455,    99,     4,   454,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   144,   136,
     453,   138,   135,   478,   479,   144,   481,   482,   144,    99,
     485,   486,   487,   136,   113,   114,   115,   116,     4,   217,
     113,   114,   115,   116,    62,    63,   501,   144,  1164,   504,
     505,   773,   774,     6,   133,   134,   511,     6,   126,   127,
     133,   134,   136,   144,   138,   136,   574,    72,   523,   524,
     478,    76,    77,   136,   142,   138,   144,   532,   486,   487,
     478,  1197,   136,  1199,   138,  1201,  1086,   136,   149,   126,
     127,  1207,   136,   501,   155,   550,   504,    72,   136,   554,
     138,    76,    77,   501,    46,   142,   136,    49,   563,    51,
     565,   566,   126,   127,   136,  1231,   138,  1233,    72,  1235,
     181,     6,    76,    77,   185,   186,     5,  1127,   142,   637,
    1130,    72,   136,  1133,   138,    76,    77,   126,   127,   144,
      72,   574,   941,   136,    76,    77,   136,   126,   127,   126,
     127,   136,   660,   142,   136,   136,   138,   138,   613,   614,
     143,     4,     5,   142,   136,   142,   126,   127,   136,   144,
     348,   349,   627,   628,   629,   630,   631,   632,   633,   143,
     358,   636,   142,    72,   136,   640,   138,    76,    77,  1189,
     144,   136,   647,    36,    37,    38,    39,   133,   134,    42,
     126,   127,   657,   144,   140,   126,   127,   136,   126,   127,
     665,   136,   144,   830,  1214,   143,   142,  1217,     4,     5,
    1220,   142,   136,  1223,   142,   126,   127,   136,   636,   138,
     126,   127,   687,   126,   127,   128,   129,   130,   636,     6,
       7,   142,   135,  1243,   136,  1245,   142,  1247,     4,   143,
      36,    37,    38,    39,   138,   143,    42,   665,   713,   714,
     715,   716,   323,   136,   136,   138,   138,   665,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   687,
     136,   143,   138,   135,  1083,    65,    66,    67,    68,   687,
      70,   136,   136,   138,   138,     6,   751,   752,    78,    79,
     755,   142,   142,   144,   144,   713,   714,   715,   716,   142,
     138,   144,   140,   138,   138,   713,   714,   715,   716,   133,
     134,   142,   138,   144,   138,   140,   140,   782,    94,   136,
     142,   145,   144,   143,    49,   790,    51,   770,   142,   794,
     144,   774,   136,     6,   522,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   812,   133,   134,
     142,   135,   144,   138,   142,   140,   144,   545,   136,     6,
     145,   826,   827,   828,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     6,   839,   840,   138,   135,   843,   450,
     451,     4,   143,   901,     8,   142,   142,   144,   144,   142,
       6,   144,   857,   858,   859,   142,   142,   144,   144,   142,
       4,   144,     6,   868,   142,   142,   144,   144,   873,   142,
     142,   144,   144,   142,   142,   144,   144,     5,   142,   142,
     144,   144,   865,   135,   140,   890,     7,   138,   889,   143,
       8,     7,     7,   137,     6,   136,     7,     7,    91,   137,
     143,   906,   142,   137,     6,   142,     4,   139,   913,   914,
       7,    94,     7,   918,     7,     7,    94,     7,     7,    94,
       7,     7,   927,   928,     6,   137,     7,   137,   137,  1096,
     137,    99,   937,   144,   140,   663,   937,     7,     7,   144,
       7,   140,   136,   143,   555,   556,   941,   136,   136,     6,
     941,     4,     6,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     6,   973,   974,
     139,   135,     6,     6,   123,     7,   138,     6,    49,     7,
     144,     7,   710,   711,   712,    51,   991,     7,   143,     7,
       7,     7,     7,     7,     7,     7,     7,  1002,  1165,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     7,     7,  1020,     4,   135,   143,     6,
     143,     6,   136,     6,     6,     6,   144,     6,     6,     4,
       7,     7,   136,     7,     6,     4,  1041,   143,     6,  1044,
     140,  1046,     7,   137,     6,     6,   137,   143,  1053,     6,
       6,     6,     6,  1058,     5,   143,     5,     7,   143,   143,
     143,     6,   673,   674,     6,   676,    90,   678,   679,     5,
       4,   682,   683,     6,     6,   140,     6,   139,     6,     6,
       5,   142,  1087,     6,  1089,     6,  1091,     6,  1083,     6,
       6,     6,  1083,     6,  1099,     6,     6,     6,     6,     6,
    1105,  1106,     6,     6,     6,     6,     6,     6,   143,  1114,
       4,     6,   143,     6,     6,   843,     7,  1122,   140,     6,
       8,     5,   733,   734,   735,     6,     6,     6,   137,     7,
       6,    89,     6,     6,   144,   143,   143,  1142,   143,   143,
       6,     6,     6,     6,    92,     6,     6,  1152,     6,     6,
    1155,  1209,   143,  1158,     5,   144,     6,  1162,     6,   143,
       6,     6,   142,    61,  1169,     6,     6,  1172,     6,     5,
       5,   144,   143,   143,     6,     6,   143,   143,   142,  1237,
     908,  1239,   910,     6,     6,     6,     6,   798,     6,     6,
     143,   143,     6,   804,     6,     6,   143,     6,   144,  1257,
     143,     6,   813,   814,   815,   143,     6,   818,   819,   820,
     821,   822,   823,   824,     6,   943,     6,   945,     6,   947,
     789,   577,  1142,     3,     3,   893,    -1,    -1,   839,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,   137,
     861,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,     3,     4,   135,
      -1,    -1,    -1,     9,    10,    11,    -1,   888,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    -1,    -1,    -1,    -1,   959,    -1,
      -1,   962,    -1,     6,    -1,    -1,    -1,   968,    -1,  1087,
      -1,  1089,    -1,  1091,   975,    -1,    -1,    -1,   979,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
     126,   127,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,   141,    -1,    -1,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,  1038,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,  1095,    65,    66,    67,    68,    69,
      70,     8,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    99,
      -1,    -1,    -1,  1134,     6,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,   136,    -1,     3,     4,
      -1,   141,    -1,   143,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      65,    66,    67,    68,    69,    70,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,    99,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,   136,    -1,     3,     4,    -1,   141,    -1,   143,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,    65,    66,    67,    68,    69,
      70,     8,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,   136,    -1,     3,     4,
      -1,   141,    -1,   143,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      65,    66,    67,    68,    69,    70,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,   136,    -1,     3,     4,    -1,   141,    -1,   143,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,     3,     4,    -1,    -1,    78,    79,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     6,    -1,    -1,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,   136,    -1,     3,     4,
      -1,   141,    -1,   143,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,
     139,    -1,   141,    -1,   143,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,   136,    -1,    -1,   139,    -1,   141,    -1,   143,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    -1,    -1,    42,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,   109,   110,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,   141,    -1,   143,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,   131,    -1,   133,   134,    -1,   136,    -1,   138,
      -1,   140,   141,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,     3,     4,    -1,    -1,    78,    79,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,   131,     3,     4,     5,    -1,   136,    -1,     9,    10,
      11,   141,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,    -1,    -1,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,   136,    -1,    -1,
      -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      -1,    56,    57,    -1,    59,    60,    -1,    -1,   109,   110,
     111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    12,    13,    -1,    -1,   126,   127,    -1,    -1,    -1,
     131,    86,    87,    88,    -1,   136,    -1,    -1,    -1,    -1,
     141,    -1,    -1,    12,    13,   100,   101,    -1,    -1,    -1,
      -1,   106,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    -1,    56,    57,    -1,    59,    60,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    75,    54,    -1,    56,    57,   144,
      59,    60,    -1,    -1,    -1,    86,    87,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    12,    13,   100,
     101,    -1,    -1,    -1,    -1,   106,    -1,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,   100,   101,    -1,    -1,    -1,    -1,   106,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      -1,    56,    57,   144,    59,    60,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      75,    54,    -1,    56,    57,   144,    59,    60,    -1,    -1,
      -1,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    12,    13,   100,   101,    -1,    -1,    -1,
      -1,   106,    -1,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,   100,   101,     8,
      -1,    -1,    -1,   106,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    -1,    56,    57,   144,
      59,    60,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    75,    54,    -1,    56,
      57,   144,    59,    60,     6,    -1,    -1,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    12,
      13,   100,   101,     6,    -1,    -1,    -1,   106,    -1,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,   100,   101,    -1,    -1,    -1,    -1,   106,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    -1,    56,    57,   144,    59,    60,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    75,     8,    -1,    -1,   135,   144,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,
      -1,    -1,    -1,   106,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,   144,   135,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,   135,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    35,    -1,    -1,
     135,    -1,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    72,    73,    74,    75,    -1,    -1,
      78,    79,    -1,     4,    -1,    -1,    -1,    85,    86,    87,
      88,    12,    13,    91,    -1,    93,    -1,    95,    96,    97,
      98,    -1,   100,   101,    -1,    -1,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    74,    75,    -1,    -1,    78,    79,    12,
      13,    -1,    -1,    -1,    85,    86,    87,    88,    -1,    -1,
      91,    -1,    93,    -1,    95,    96,    97,    98,    -1,   100,
     101,    -1,    -1,   104,   105,   106,   107,   108,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    -1,    56,    57,    -1,    59,    60,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    75,    -1,    -1,    -1,   135,    -1,    -1,    -1,
     139,    -1,    -1,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,
      -1,    -1,    -1,   106,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
      -1,   144,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,   144,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,   144,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,   137,    -1,    -1,    -1,    -1,   142,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    -1,    -1,    -1,   142,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    -1,    -1,    -1,   142,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    -1,    -1,    -1,   142,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    -1,    -1,    -1,   142,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    -1,    -1,    -1,   142,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,   139,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    -1,   139,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
     139,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,   139,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,   139,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,   139,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,   139,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,   139,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,   139,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,
      -1,   139,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,   139,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    -1,   139,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
     139,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,   139,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,   139,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,   139,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,   139,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,   139,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,   139,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,
      -1,   139,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,   139,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    -1,   139,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,
     139,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,   139,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,   139,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,   139,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,   139,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,   139,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,   139,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,
      -1,   139,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,   139,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,   137,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,   137,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,   135,    -1,   137,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,   137,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,   137,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
     137,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,
      -1,   137,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,   137,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,   135,    -1,   137,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,   137,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,   137,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,   137,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,   135,    -1,   137,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,   137,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,   137,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
     137,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,
      -1,   137,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,   137,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,   135,    -1,   137,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,   137,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,   137,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,   137,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,   135,    -1,   137,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,   137,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,   137,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
     137,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,
      -1,   137,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,   137,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,   135,    -1,   137,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,   137,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,   137,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,   137,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,   135,    -1,   137,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,   137,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,   137,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
     137,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,
      -1,   137,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,   137,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,   135,    -1,   137,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,   137,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,   137,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,   137,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,   135,    -1,   137,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,   137,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,   137,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
     137,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,
      -1,   137,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,   137,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,   135,    -1,   137,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,   137,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,   137,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,   137,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,   135
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   147,   148,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    55,    56,    57,    58,    59,    60,    64,
      65,    66,    67,    68,    69,    70,    72,    73,    74,    75,
      78,    79,    85,    86,    87,    88,    91,    93,    95,    96,
      97,    98,   100,   101,   104,   105,   106,   107,   108,   149,
     151,   152,   171,   173,   174,   177,   178,   179,   180,   181,
     182,   183,   200,   201,   202,     3,     4,     5,     7,     9,
      10,    11,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    36,    37,    38,    39,    42,   109,   110,
     111,   112,   113,   114,   115,   116,   126,   127,   131,   133,
     134,   136,   138,   140,   141,   169,   170,   203,   204,   215,
      13,    49,   136,     6,   143,     6,   136,   143,   136,   136,
      71,   136,   143,   136,   136,    71,   143,   136,   136,    53,
      49,   136,    49,    49,    49,    46,    49,    51,    51,    43,
      46,    49,    51,   136,   143,   126,   127,   136,   143,   205,
     206,   205,   143,     4,    43,    46,    49,   143,   205,     4,
     143,    49,     4,   143,     6,    43,    46,     4,     4,     4,
     136,   136,   136,     4,   143,   211,     4,   136,   136,     6,
      99,    99,     4,     4,    99,     4,     5,   143,   214,   215,
     143,   214,     4,   138,   140,   145,   170,     4,   143,   215,
     136,   138,   136,   138,   136,   138,   136,   138,   136,   138,
     136,   138,   136,   138,   136,   138,   136,   138,   136,   138,
     136,   138,   136,   138,   136,   138,   136,   138,   136,   138,
     136,   138,   136,   138,   136,   138,   136,   138,   136,   138,
     136,   138,   136,   136,   136,   136,   136,     4,   203,   203,
     203,   203,   139,   143,   203,     4,    91,    92,     4,   203,
       6,     6,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   135,     6,     6,   203,
       5,   203,   203,     4,    43,   127,   174,   177,   183,   203,
     209,   210,   203,   203,   136,   203,   210,   203,   203,   136,
     210,   203,   203,    99,   127,   143,   203,   208,   209,   136,
     203,   143,   136,   136,   208,   143,   143,   136,   136,   136,
     136,   136,     4,   205,   205,   205,   203,   203,   126,   127,
     143,   143,   205,   138,   143,   143,   143,   126,   127,   136,
     176,   205,   143,   138,   176,   208,     4,     6,   138,   176,
      99,   208,   208,   138,   138,     6,   203,   203,   203,   140,
     203,   143,    94,   203,   203,   136,   136,     6,   136,   176,
       6,   176,     6,   138,   203,     4,   143,   205,   153,     6,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,     4,   214,   214,   214,   214,     5,   138,   137,
       7,   116,   210,   139,     7,   169,   170,   140,     7,   138,
       6,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,     6,   137,   142,   142,
     137,   138,   143,   203,   209,     8,   128,   142,   144,   137,
     137,   203,   137,   144,   137,   137,   203,   144,   137,   137,
     208,   143,   144,   210,   128,     7,   203,   137,   203,   203,
     203,     7,   203,   203,   203,   172,   203,   215,   172,   172,
     172,   137,   142,   142,   142,   205,   205,   174,   175,   176,
     177,   175,   142,   203,   203,   203,   203,   203,    43,    46,
      49,    51,   106,   173,   187,   142,   176,   203,   144,     6,
       7,     6,   203,   144,   136,     7,     7,   203,   203,   137,
     137,   137,    91,   142,   176,   143,     8,   137,   203,   203,
     203,   144,   144,   203,   139,   170,   203,   143,     4,    80,
      81,    82,    83,    84,   144,   156,   160,   163,   165,   166,
     168,   137,   139,   137,   139,   137,   139,   137,   139,   137,
     139,   137,   139,   137,   139,   137,   139,   137,   139,   137,
     139,   137,   139,   142,   142,   137,   139,   137,   139,   137,
     139,   137,   139,   137,   139,   137,   139,   142,   142,   142,
     142,   142,   142,   138,   140,   137,   142,   142,   137,   137,
     142,   203,   208,   208,   144,     7,   140,   169,   170,   215,
     203,     6,     4,     4,   143,   212,   139,     8,     6,   123,
     150,   210,   203,     7,   139,   143,   203,   203,   203,   209,
     203,   209,    94,     7,     7,   137,     7,    94,     7,     7,
     137,    94,     7,     7,     6,   210,   144,   143,   203,   137,
       7,   144,   137,   137,   203,   144,   144,   137,   137,   137,
     137,   137,   140,   205,   203,   203,   144,   144,   203,   139,
     142,   142,   142,   143,   143,   143,   143,    72,    76,    77,
     198,   199,   205,   144,   184,   139,   203,   139,   203,   208,
     208,   139,   139,     7,     7,     7,   140,   203,   144,   203,
     203,   137,   137,   137,   139,   140,   170,   214,   144,   153,
     157,   136,   136,   143,   167,   136,     6,   203,   203,   203,
     203,   203,   203,   203,   203,   203,     4,   210,   214,   203,
     139,     6,     6,   139,     4,    91,    92,   203,     6,     6,
       6,     7,   138,   211,   213,     6,   203,   123,   214,   137,
     142,   205,   210,   144,     8,    49,   208,   208,     7,   208,
      49,    51,   208,   208,     7,    51,   208,   208,   144,   210,
       6,     7,   143,     7,     7,     7,     6,    61,     7,     7,
       7,     7,     7,     7,     7,     4,   142,   142,   142,   144,
     143,   205,   205,   205,   210,   210,   210,   210,     6,   143,
     136,   144,   199,   142,   198,     6,     6,     6,   137,     6,
       6,     6,     6,   208,   208,   208,     4,   142,     8,     8,
     137,     7,     7,     7,     6,     4,     6,   144,   136,   203,
     203,   207,   208,   143,   203,   137,   139,   137,   139,   137,
     139,   137,   139,   139,   137,   137,   137,   137,   169,     7,
     169,   170,   140,     7,     6,   211,   203,   142,   144,     6,
       6,   150,   203,     6,   144,   203,   143,     6,    56,     6,
      56,   208,     6,   143,   143,     6,     6,   208,   143,     6,
       6,   144,     5,   203,   208,   208,   208,    62,    63,   208,
     208,   208,   208,   208,   208,   208,     6,     7,   203,   203,
     203,   143,   176,   142,   144,   142,   144,   142,   144,   144,
     144,   144,   144,   203,   208,   203,   203,   205,   144,     7,
       6,     6,    90,   203,   203,   203,   208,     5,     5,   170,
       6,   154,   203,   142,   142,   142,   144,   155,   203,   137,
     140,   208,   215,   203,     6,     4,   212,     6,   139,   211,
     214,   142,   139,   203,   205,   205,     6,   203,   203,     6,
     203,     5,   142,     6,     6,     6,   203,   203,     4,     6,
       6,     6,     6,     6,     6,     6,   203,   215,   144,   137,
     142,   144,   175,   188,   205,     6,   189,   205,     6,   190,
     205,     6,   191,     6,     6,     6,     6,   144,   142,   137,
     144,   142,   208,   208,   142,   144,     8,   144,   137,     6,
       6,   208,   137,   142,   203,   203,   208,   143,   142,   144,
     208,     4,     6,     6,     6,     7,     6,   140,     6,   203,
     144,     6,     6,   144,   144,   144,     5,   203,     6,     6,
       6,     6,     6,   143,   203,   144,   198,   142,   143,   142,
     143,   142,   143,     6,   208,     7,   143,   203,     6,    89,
     203,   203,     6,   158,   203,   142,   142,   207,   203,     6,
       6,   137,   211,    92,   142,     6,     6,     6,     6,     6,
     142,   175,   142,   144,   144,   203,   205,   198,   203,   205,
     198,   203,   205,   198,   142,   144,   208,   176,   144,   203,
     144,   144,   143,   203,   203,   144,     6,   203,     5,   144,
     203,   144,   142,   144,   144,   142,   144,   144,   142,   144,
     208,     6,    61,   144,   185,   143,     6,   155,   137,   142,
       6,   143,   142,   142,   144,     6,   192,   203,     6,     6,
     193,   203,     6,     6,   194,   203,     6,   144,   203,   198,
     176,   144,   161,   203,   207,   203,     5,   143,   144,   143,
     144,   143,   144,     6,     6,   144,   144,   186,     6,   143,
     137,   144,   144,   142,   198,     6,   195,   198,     6,   196,
     198,     6,   197,   198,   159,   214,   164,   143,     6,     5,
     144,   143,   144,   143,   144,   143,   144,   142,   144,   143,
     207,   144,     6,   198,     6,   198,     6,   198,   214,     6,
     162,   214,   144,     6,   144,   144,   144,   142,   144,     6,
       6,     6,     6,   214,     6
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
      fields.insert(att,(int)(yyvsp[(5) - (9)].d));
    ;}
    break;

  case 88:
#line 1099 "Gmsh.y"
    {
    double pars[]={0,CTX.lc/10,CTX.lc,CTX.lc/100,CTX.lc/20};
    for (int i=0;i<List_Nbr((yyvsp[(7) - (8)].l));i++){
      if(i>4)
        yymsg(GERROR,"Too many parameters for Thresold Field (max=5)");
      else
        List_Read((yyvsp[(7) - (8)].l),i,&pars[i]);
    }
    fields.insert(new ThresholdField(fields.get((int)pars[0]),pars[1],pars[2],pars[3],pars[4]),(int)(yyvsp[(4) - (8)].d));
  ;}
    break;

  case 89:
#line 1109 "Gmsh.y"
    {
		std::list<Field*> *flist=new std::list<Field*>;
		flist->resize(0);
		for(int i = 0; i < List_Nbr((yyvsp[(8) - (9)].l)); i++){
			double id;
			List_Read((yyvsp[(8) - (9)].l), i, &id);
      Field *pfield=fields.get((int)id);
			if(pfield)flist->push_front(pfield);
		}
    fields.insert(new FunctionField(flist,(yyvsp[(7) - (9)].c)),(int)(yyvsp[(4) - (9)].d));
  ;}
    break;

  case 90:
#line 1120 "Gmsh.y"
    {
      fields.insert(new StructuredField((yyvsp[(7) - (8)].c)),(int)(yyvsp[(4) - (8)].d));
 		;}
    break;

  case 91:
#line 1123 "Gmsh.y"
    {
 			for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
 				double id;
 				List_Read((yyvsp[(4) - (5)].l), i, &id);
        BGMAddField(fields.get((int)id));
 			}
 		;}
    break;

  case 92:
#line 1132 "Gmsh.y"
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
      AttractorField *attractor= new AttractorField();
      fields.insert(attractor);
      Field *threshold=new ThresholdField(attractor,pars[0],pars[0]*pars[4],pars[1],pars[2]);
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

  case 93:
#line 1165 "Gmsh.y"
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
      Field *threshold=new ThresholdField(att,pars[0],pars[0]*pars[4],pars[1],pars[2]);
      fields.insert(threshold);
      BGMAddField(threshold);
      //tresholdAttractor::New(pars[0], pars[1], pars[2], pars[4]);
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

  case 94:
#line 1201 "Gmsh.y"
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

  case 95:
#line 1223 "Gmsh.y"
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

  case 96:
#line 1241 "Gmsh.y"
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

  case 97:
#line 1259 "Gmsh.y"
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

  case 98:
#line 1277 "Gmsh.y"
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

  case 99:
#line 1303 "Gmsh.y"
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

  case 100:
#line 1321 "Gmsh.y"
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

  case 101:
#line 1348 "Gmsh.y"
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

  case 102:
#line 1367 "Gmsh.y"
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

  case 103:
#line 1391 "Gmsh.y"
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

  case 104:
#line 1415 "Gmsh.y"
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

  case 105:
#line 1441 "Gmsh.y"
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

  case 106:
#line 1458 "Gmsh.y"
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

  case 107:
#line 1477 "Gmsh.y"
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

  case 108:
#line 1495 "Gmsh.y"
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

  case 109:
#line 1534 "Gmsh.y"
    {
    myGmshSurface = 0;
  ;}
    break;

  case 110:
#line 1539 "Gmsh.y"
    {
    myGmshSurface = gmshSurface :: surfaceByTag ( (int) (yyvsp[(3) - (4)].d));
  ;}
    break;

  case 111:
#line 1544 "Gmsh.y"
    {
    int num = (int)(yyvsp[(4) - (10)].d), type = 0;
    myGmshSurface = gmshParametricSurface::NewParametricSurface ((int)(yyvsp[(4) - (10)].d),(yyvsp[(7) - (10)].c),(yyvsp[(8) - (10)].c),(yyvsp[(9) - (10)].c));
  ;}
    break;

  case 112:
#line 1550 "Gmsh.y"
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

  case 113:
#line 1572 "Gmsh.y"
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

  case 114:
#line 1594 "Gmsh.y"
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

  case 115:
#line 1610 "Gmsh.y"
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

  case 116:
#line 1630 "Gmsh.y"
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

  case 117:
#line 1647 "Gmsh.y"
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

  case 118:
#line 1664 "Gmsh.y"
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

  case 119:
#line 1685 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 120:
#line 1690 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 121:
#line 1695 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 122:
#line 1700 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 123:
#line 1707 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 124:
#line 1708 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 125:
#line 1709 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 126:
#line 1714 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 127:
#line 1718 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 128:
#line 1722 "Gmsh.y"
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

  case 129:
#line 1745 "Gmsh.y"
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

  case 130:
#line 1768 "Gmsh.y"
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

  case 131:
#line 1791 "Gmsh.y"
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

  case 132:
#line 1819 "Gmsh.y"
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

  case 133:
#line 1831 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "View")) AliasView((int)(yyvsp[(4) - (6)].d), 0);
      Free((yyvsp[(2) - (6)].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 134:
#line 1837 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "View")) AliasView((int)(yyvsp[(4) - (6)].d), 0);
      Free((yyvsp[(2) - (6)].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 135:
#line 1843 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "View")) AliasView((int)(yyvsp[(4) - (6)].d), 1);
      Free((yyvsp[(2) - (6)].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 136:
#line 1855 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 137:
#line 1864 "Gmsh.y"
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

  case 138:
#line 1874 "Gmsh.y"
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

  case 139:
#line 1890 "Gmsh.y"
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

  case 140:
#line 1909 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));      
    ;}
    break;

  case 141:
#line 1923 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 142:
#line 1929 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 143:
#line 1935 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 144:
#line 1944 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 145:
#line 1958 "Gmsh.y"
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

  case 146:
#line 2008 "Gmsh.y"
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

  case 147:
#line 2023 "Gmsh.y"
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

  case 148:
#line 2038 "Gmsh.y"
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

  case 149:
#line 2058 "Gmsh.y"
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

  case 150:
#line 2068 "Gmsh.y"
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

  case 151:
#line 2090 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 152:
#line 2094 "Gmsh.y"
    {
      CTX.forced_bbox = 0;
      SetBoundingBox();
    ;}
    break;

  case 153:
#line 2099 "Gmsh.y"
    {
      CTX.forced_bbox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 154:
#line 2104 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      Draw();
#endif
    ;}
    break;

  case 155:
#line 2116 "Gmsh.y"
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

  case 156:
#line 2131 "Gmsh.y"
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

  case 157:
#line 2147 "Gmsh.y"
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

  case 158:
#line 2173 "Gmsh.y"
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

  case 159:
#line 2200 "Gmsh.y"
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

  case 160:
#line 2232 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction((yyvsp[(2) - (2)].c), yyin, yyname, yylineno))
	yymsg(GERROR, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 161:
#line 2239 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin, yyname, yylineno))
	yymsg(GERROR, "Error while exiting function");
    ;}
    break;

  case 162:
#line 2244 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction((yyvsp[(2) - (3)].c), &yyin, yyname, yylineno))
	yymsg(GERROR, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 163:
#line 2250 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 164:
#line 2254 "Gmsh.y"
    {
    ;}
    break;

  case 165:
#line 2263 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 166:
#line 2271 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 167:
#line 2279 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 168:
#line 2287 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 169:
#line 2291 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 170:
#line 2299 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 171:
#line 2303 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 172:
#line 2311 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 173:
#line 2315 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 174:
#line 2323 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 175:
#line 2327 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 176:
#line 2334 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 177:
#line 2338 "Gmsh.y"
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

  case 178:
#line 2350 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 179:
#line 2357 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 180:
#line 2364 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 181:
#line 2371 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 182:
#line 2378 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 183:
#line 2385 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 184:
#line 2392 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 185:
#line 2399 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 186:
#line 2406 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 187:
#line 2413 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 188:
#line 2417 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 189:
#line 2424 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 190:
#line 2428 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 191:
#line 2435 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 192:
#line 2439 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 193:
#line 2446 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 194:
#line 2450 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 195:
#line 2457 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 196:
#line 2461 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 197:
#line 2468 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 198:
#line 2472 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 199:
#line 2479 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 200:
#line 2483 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 201:
#line 2490 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 202:
#line 2494 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 203:
#line 2501 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 204:
#line 2505 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 205:
#line 2516 "Gmsh.y"
    {
    ;}
    break;

  case 206:
#line 2519 "Gmsh.y"
    {
    ;}
    break;

  case 207:
#line 2525 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 208:
#line 2534 "Gmsh.y"
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

  case 209:
#line 2556 "Gmsh.y"
    {
      yymsg(WARNING, "Explicit region numbers in layers are deprecated");
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

  case 210:
#line 2580 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 211:
#line 2584 "Gmsh.y"
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

  case 212:
#line 2608 "Gmsh.y"
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

  case 213:
#line 2626 "Gmsh.y"
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

  case 214:
#line 2644 "Gmsh.y"
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

  case 215:
#line 2662 "Gmsh.y"
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

  case 216:
#line 2691 "Gmsh.y"
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

  case 217:
#line 2726 "Gmsh.y"
    {
      yymsg(WARNING, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 218:
#line 2731 "Gmsh.y"
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

  case 219:
#line 2758 "Gmsh.y"
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

  case 220:
#line 2772 "Gmsh.y"
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

  case 221:
#line 2791 "Gmsh.y"
    { 
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s)
	setSurfaceEmbeddedPoints(s, (yyvsp[(3) - (10)].l));
    ;}
    break;

  case 222:
#line 2797 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s)
	setSurfaceEmbeddedCurves(s, (yyvsp[(3) - (10)].l));
    ;}
    break;

  case 223:
#line 2803 "Gmsh.y"
    {
    ;}
    break;

  case 224:
#line 2806 "Gmsh.y"
    {
    ;}
    break;

  case 225:
#line 2815 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 226:
#line 2824 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 227:
#line 2825 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 228:
#line 2826 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 229:
#line 2827 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 230:
#line 2828 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 231:
#line 2829 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 232:
#line 2830 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 233:
#line 2831 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 234:
#line 2833 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(GERROR, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 235:
#line 2839 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 236:
#line 2840 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 237:
#line 2841 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 238:
#line 2842 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 239:
#line 2843 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 240:
#line 2844 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 241:
#line 2845 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 242:
#line 2846 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 243:
#line 2847 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 244:
#line 2848 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 245:
#line 2849 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d)? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d);  ;}
    break;

  case 246:
#line 2850 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 247:
#line 2851 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 248:
#line 2852 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 249:
#line 2853 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 250:
#line 2854 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 251:
#line 2855 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 252:
#line 2856 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 253:
#line 2857 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 254:
#line 2858 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 255:
#line 2859 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 256:
#line 2860 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 257:
#line 2861 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 258:
#line 2862 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 259:
#line 2863 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 260:
#line 2864 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 261:
#line 2865 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 262:
#line 2866 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 263:
#line 2867 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 264:
#line 2868 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 265:
#line 2869 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d)*(yyvsp[(3) - (6)].d)+(yyvsp[(5) - (6)].d)*(yyvsp[(5) - (6)].d)); ;}
    break;

  case 266:
#line 2870 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 267:
#line 2872 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 268:
#line 2873 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 269:
#line 2874 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 270:
#line 2875 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 271:
#line 2876 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 272:
#line 2877 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 273:
#line 2878 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 274:
#line 2879 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 275:
#line 2880 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 276:
#line 2881 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 277:
#line 2882 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 278:
#line 2883 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 279:
#line 2884 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 280:
#line 2885 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 281:
#line 2886 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 282:
#line 2887 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 283:
#line 2888 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 284:
#line 2889 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 285:
#line 2890 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 286:
#line 2891 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d)*(yyvsp[(3) - (6)].d)+(yyvsp[(5) - (6)].d)*(yyvsp[(5) - (6)].d)); ;}
    break;

  case 287:
#line 2892 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 288:
#line 2901 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 289:
#line 2902 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 290:
#line 2903 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->rank(); ;}
    break;

  case 291:
#line 2904 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->size(); ;}
    break;

  case 292:
#line 2905 "Gmsh.y"
    { (yyval.d) = Get_GmshMajorVersion(); ;}
    break;

  case 293:
#line 2906 "Gmsh.y"
    { (yyval.d) = Get_GmshMinorVersion(); ;}
    break;

  case 294:
#line 2907 "Gmsh.y"
    { (yyval.d) = Get_GmshPatchVersion(); ;}
    break;

  case 295:
#line 2912 "Gmsh.y"
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
#line 2928 "Gmsh.y"
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
#line 2943 "Gmsh.y"
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
#line 2963 "Gmsh.y"
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

  case 299:
#line 2977 "Gmsh.y"
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
#line 2990 "Gmsh.y"
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
#line 3013 "Gmsh.y"
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
#line 3031 "Gmsh.y"
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
#line 3049 "Gmsh.y"
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
#line 3067 "Gmsh.y"
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
#line 3085 "Gmsh.y"
    { 
      (yyval.d) = GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 306:
#line 3093 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 307:
#line 3097 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 308:
#line 3101 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 309:
#line 3105 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 310:
#line 3109 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 311:
#line 3116 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 312:
#line 3120 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 313:
#line 3124 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 314:
#line 3128 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 315:
#line 3135 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 316:
#line 3140 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 317:
#line 3148 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 318:
#line 3153 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 319:
#line 3157 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 320:
#line 3162 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 321:
#line 3166 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 322:
#line 3174 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 323:
#line 3185 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 324:
#line 3193 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 325:
#line 3201 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 326:
#line 3207 "Gmsh.y"
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
#line 3218 "Gmsh.y"
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

  case 328:
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

  case 329:
#line 3248 "Gmsh.y"
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
#line 3258 "Gmsh.y"
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
#line 3268 "Gmsh.y"
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

  case 332:
#line 3285 "Gmsh.y"
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

  case 333:
#line 3312 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 334:
#line 3317 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 335:
#line 3321 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 336:
#line 3325 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 337:
#line 3338 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 338:
#line 3342 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 339:
#line 3354 "Gmsh.y"
    {
      int flag;
      (yyval.u) = Get_ColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 340:
#line 3361 "Gmsh.y"
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

  case 341:
#line 3383 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 342:
#line 3387 "Gmsh.y"
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

  case 343:
#line 3402 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 344:
#line 3407 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 345:
#line 3414 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 346:
#line 3418 "Gmsh.y"
    {
      Msg(WARNING, "Named string expressions not implemented yet");
    ;}
    break;

  case 347:
#line 3425 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 348:
#line 3429 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32*sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 349:
#line 3437 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c))+strlen((yyvsp[(5) - (6)].c))+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 350:
#line 3445 "Gmsh.y"
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

  case 351:
#line 3459 "Gmsh.y"
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

  case 352:
#line 3473 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 353:
#line 3477 "Gmsh.y"
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

  case 354:
#line 3496 "Gmsh.y"
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

  case 355:
#line 3518 "Gmsh.y"
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
#line 8016 "Gmsh.tab.cpp"
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


#line 3541 "Gmsh.y"


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

