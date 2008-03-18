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
     tReturn = 356,
     tCall = 357,
     tFunction = 358,
     tShow = 359,
     tHide = 360,
     tGetValue = 361,
     tGMSH_MAJOR_VERSION = 362,
     tGMSH_MINOR_VERSION = 363,
     tGMSH_PATCH_VERSION = 364,
     tAFFECTDIVIDE = 365,
     tAFFECTTIMES = 366,
     tAFFECTMINUS = 367,
     tAFFECTPLUS = 368,
     tOR = 369,
     tAND = 370,
     tNOTEQUAL = 371,
     tEQUAL = 372,
     tGREATEROREQUAL = 373,
     tLESSOREQUAL = 374,
     UNARYPREC = 375,
     tMINUSMINUS = 376,
     tPLUSPLUS = 377
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
#define tReturn 356
#define tCall 357
#define tFunction 358
#define tShow 359
#define tHide 360
#define tGetValue 361
#define tGMSH_MAJOR_VERSION 362
#define tGMSH_MINOR_VERSION 363
#define tGMSH_PATCH_VERSION 364
#define tAFFECTDIVIDE 365
#define tAFFECTTIMES 366
#define tAFFECTMINUS 367
#define tAFFECTPLUS 368
#define tOR 369
#define tAND 370
#define tNOTEQUAL 371
#define tEQUAL 372
#define tGREATEROREQUAL 373
#define tLESSOREQUAL 374
#define UNARYPREC 375
#define tMINUSMINUS 376
#define tPLUSPLUS 377




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// $Id: Gmsh.tab.cpp,v 1.351 2008-03-18 11:33:04 remacle Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

#include <string.h>
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
void yymsg(int type, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
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
#define YYLAST   6361

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  143
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  350
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1242

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   377

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   128,     2,   138,     2,   127,     2,     2,
     133,   134,   125,   123,   139,   124,   137,   126,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     119,     2,   120,   114,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   135,     2,   136,   132,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   140,     2,   141,   142,     2,     2,     2,
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
     105,   106,   107,   108,   109,   110,   111,   112,   113,   115,
     116,   117,   118,   121,   122,   129,   130,   131
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
     375,   383,   393,   403,   413,   423,   433,   435,   437,   445,
     454,   461,   469,   477,   485,   495,   503,   513,   531,   539,
     547,   559,   568,   577,   586,   595,   599,   604,   615,   623,
     631,   640,   649,   658,   666,   675,   681,   693,   699,   709,
     714,   724,   729,   731,   733,   734,   737,   744,   751,   758,
     765,   770,   777,   784,   788,   793,   799,   803,   807,   812,
     817,   821,   829,   837,   841,   849,   853,   856,   859,   875,
     878,   885,   894,   903,   914,   916,   919,   921,   925,   930,
     932,   938,   950,   964,   965,   973,   974,   988,   989,  1005,
    1006,  1013,  1014,  1025,  1034,  1043,  1052,  1065,  1078,  1091,
    1106,  1121,  1136,  1137,  1150,  1151,  1164,  1165,  1178,  1179,
    1196,  1197,  1214,  1215,  1232,  1233,  1252,  1253,  1272,  1273,
    1292,  1294,  1297,  1303,  1311,  1321,  1324,  1334,  1341,  1351,
    1361,  1370,  1380,  1389,  1398,  1405,  1410,  1417,  1428,  1439,
    1450,  1461,  1464,  1466,  1470,  1473,  1476,  1479,  1483,  1487,
    1491,  1495,  1499,  1503,  1507,  1511,  1515,  1519,  1523,  1527,
    1531,  1535,  1541,  1546,  1551,  1556,  1561,  1566,  1571,  1576,
    1581,  1586,  1591,  1598,  1603,  1608,  1613,  1618,  1623,  1628,
    1635,  1642,  1649,  1654,  1659,  1664,  1669,  1674,  1679,  1684,
    1689,  1694,  1699,  1704,  1711,  1716,  1721,  1726,  1731,  1736,
    1741,  1748,  1755,  1762,  1767,  1769,  1771,  1773,  1775,  1777,
    1779,  1781,  1783,  1789,  1794,  1799,  1802,  1808,  1812,  1819,
    1824,  1832,  1839,  1841,  1844,  1847,  1851,  1855,  1867,  1877,
    1885,  1893,  1895,  1899,  1901,  1903,  1906,  1910,  1915,  1921,
    1924,  1928,  1932,  1938,  1943,  1945,  1947,  1951,  1958,  1960,
    1962,  1966,  1970,  1980,  1988,  1990,  1996,  2000,  2007,  2009,
    2013,  2015,  2017,  2019,  2021,  2028,  2033,  2038,  2043,  2050,
    2057
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     144,     0,    -1,   145,    -1,     1,     6,    -1,    -1,   145,
     146,    -1,   149,    -1,   148,    -1,   167,    -1,   169,    -1,
     170,    -1,   173,    -1,   174,    -1,   175,    -1,   178,    -1,
     195,    -1,   196,    -1,   197,    -1,   177,    -1,   176,    -1,
     120,    -1,   120,   120,    -1,    35,   133,     5,   134,     6,
      -1,    35,   133,     5,   134,   147,   209,     6,    -1,    35,
     133,     5,   139,   205,   134,     6,    -1,    35,   133,     5,
     139,   205,   134,   147,   209,     6,    -1,     4,     5,   140,
     150,   141,     6,    -1,    80,     4,   135,   198,   136,     6,
      -1,    81,     4,   135,   198,   136,     6,    -1,    -1,   150,
     153,    -1,   150,   157,    -1,   150,   160,    -1,   150,   162,
      -1,   150,   163,    -1,   198,    -1,   151,   139,   198,    -1,
     198,    -1,   152,   139,   198,    -1,    -1,    -1,     4,   154,
     133,   151,   134,   155,   140,   152,   141,     6,    -1,   209,
      -1,   156,   139,   209,    -1,    -1,    82,   133,   198,   139,
     198,   139,   198,   134,   158,   140,   156,   141,     6,    -1,
     209,    -1,   159,   139,   209,    -1,    -1,    83,   133,   198,
     139,   198,   139,   198,   139,   198,   134,   161,   140,   159,
     141,     6,    -1,    84,   140,   202,   141,   140,   202,   141,
       6,    -1,    84,   140,   202,   141,   140,   202,   141,   140,
     202,   141,   140,   202,   141,     6,    -1,    -1,    85,   164,
     140,   152,   141,     6,    -1,     7,    -1,   113,    -1,   112,
      -1,   111,    -1,   110,    -1,   131,    -1,   130,    -1,     4,
     165,   198,     6,    -1,     4,   135,   198,   136,   165,   198,
       6,    -1,     4,   135,   140,   205,   141,   136,   165,   203,
       6,    -1,     4,   135,   136,     7,   203,     6,    -1,     4,
     135,   136,   113,   203,     6,    -1,     4,   166,     6,    -1,
       4,   135,   198,   136,   166,     6,    -1,     4,     7,   210,
       6,    -1,     4,   137,     4,     7,   210,     6,    -1,     4,
     135,   198,   136,   137,     4,     7,   210,     6,    -1,     4,
     137,     4,   165,   198,     6,    -1,     4,   135,   198,   136,
     137,     4,   165,   198,     6,    -1,     4,   137,     4,   166,
       6,    -1,     4,   135,   198,   136,   137,     4,   166,     6,
      -1,     4,   137,    92,   137,     4,     7,   206,     6,    -1,
       4,   135,   198,   136,   137,    92,   137,     4,     7,   206,
       6,    -1,     4,   137,    93,     7,   207,     6,    -1,     4,
     135,   198,   136,   137,    93,     7,   207,     6,    -1,     4,
     100,     7,   198,     6,    -1,   100,   135,   198,   136,     7,
       4,     6,    -1,   100,   135,   198,   136,   137,     4,     7,
     198,     6,    -1,   100,   135,   198,   136,   137,     4,     7,
     210,     6,    -1,   100,   135,   198,   136,   137,     4,     7,
     203,     6,    -1,    64,   133,     4,   134,   137,     4,     7,
     198,     6,    -1,    64,   133,     4,   134,   137,     4,     7,
     210,     6,    -1,   198,    -1,   210,    -1,    43,   133,   198,
     134,     7,   200,     6,    -1,    60,    43,   133,   168,   134,
       7,   203,     6,    -1,    52,    53,   203,     7,   198,     6,
      -1,    46,   133,   198,   134,     7,   203,     6,    -1,    50,
     133,   198,   134,     7,   203,     6,    -1,    44,   133,   198,
     134,     7,   203,     6,    -1,    44,   133,   198,   134,     7,
     203,    56,   200,     6,    -1,    45,   133,   198,   134,     7,
     203,     6,    -1,    45,   133,   198,   134,     7,   203,    56,
     200,     6,    -1,    54,   133,   198,   134,     7,   140,   198,
     139,   198,   139,     5,   139,     5,   139,     5,   141,     6,
      -1,    87,   133,   198,   134,     7,   203,     6,    -1,    88,
     133,   198,   134,     7,   203,     6,    -1,    89,   133,   198,
     134,     7,   203,    91,   203,    90,   198,     6,    -1,    46,
      71,   133,   198,   134,     7,   203,     6,    -1,    60,    46,
     133,   168,   134,     7,   203,     6,    -1,    56,    49,   133,
     198,   134,     7,   203,     6,    -1,    57,    49,   133,   198,
     134,     7,   203,     6,    -1,    12,    13,     6,    -1,    13,
      49,   198,     6,    -1,    54,    49,   133,   198,   134,     7,
       5,     5,     5,     6,    -1,    47,   133,   198,   134,     7,
     203,     6,    -1,    48,   133,   198,   134,     7,   203,     6,
      -1,    49,    71,   133,   198,   134,     7,   203,     6,    -1,
      60,    49,   133,   168,   134,     7,   203,     6,    -1,    59,
      51,   133,   198,   134,     7,   203,     6,    -1,    51,   133,
     198,   134,     7,   203,     6,    -1,    60,    51,   133,   168,
     134,     7,   203,     6,    -1,    66,   200,   140,   171,   141,
      -1,    65,   140,   200,   139,   200,   139,   198,   141,   140,
     171,   141,    -1,    67,   200,   140,   171,   141,    -1,    68,
     140,   200,   139,   198,   141,   140,   171,   141,    -1,    70,
     140,   171,   141,    -1,    76,    46,   140,   205,   141,    49,
     140,   198,   141,    -1,    77,   140,   171,   141,    -1,   172,
      -1,   170,    -1,    -1,   172,   169,    -1,   172,    43,   140,
     205,   141,     6,    -1,   172,    46,   140,   205,   141,     6,
      -1,   172,    49,   140,   205,   141,     6,    -1,   172,    51,
     140,   205,   141,     6,    -1,    74,   140,   172,   141,    -1,
      74,   100,   135,   198,   136,     6,    -1,    74,     4,   135,
     198,   136,     6,    -1,    74,     4,     6,    -1,    74,     4,
       4,     6,    -1,    92,   206,   140,   172,   141,    -1,   104,
     209,     6,    -1,   105,   209,     6,    -1,   104,   140,   172,
     141,    -1,   105,   140,   172,   141,    -1,     4,   210,     6,
      -1,     4,     4,   135,   198,   136,   209,     6,    -1,     4,
       4,     4,   135,   198,   136,     6,    -1,     4,   198,     6,
      -1,    64,   133,     4,   134,   137,     4,     6,    -1,    86,
       4,     6,    -1,    99,     6,    -1,    40,     6,    -1,    40,
     140,   198,   139,   198,   139,   198,   139,   198,   139,   198,
     139,   198,   141,     6,    -1,    41,     6,    -1,    94,   133,
     198,     8,   198,   134,    -1,    94,   133,   198,     8,   198,
       8,   198,   134,    -1,    94,     4,    95,   140,   198,     8,
     198,   141,    -1,    94,     4,    95,   140,   198,     8,   198,
       8,   198,   141,    -1,    96,    -1,   103,     4,    -1,   101,
      -1,   102,     4,     6,    -1,    97,   133,   198,   134,    -1,
      98,    -1,    69,   200,   140,   172,   141,    -1,    69,   140,
     200,   139,   200,   139,   198,   141,   140,   172,   141,    -1,
      69,   140,   200,   139,   200,   139,   200,   139,   198,   141,
     140,   172,   141,    -1,    -1,    69,   200,   140,   172,   179,
     193,   141,    -1,    -1,    69,   140,   200,   139,   200,   139,
     198,   141,   140,   172,   180,   193,   141,    -1,    -1,    69,
     140,   200,   139,   200,   139,   200,   139,   198,   141,   140,
     172,   181,   193,   141,    -1,    -1,    69,   140,   172,   182,
     193,   141,    -1,    -1,    69,     4,   135,   198,   136,   140,
     172,   183,   193,   141,    -1,    69,    43,   140,   198,   139,
     200,   141,     6,    -1,    69,    46,   140,   198,   139,   200,
     141,     6,    -1,    69,    49,   140,   198,   139,   200,   141,
       6,    -1,    69,    43,   140,   198,   139,   200,   139,   200,
     139,   198,   141,     6,    -1,    69,    46,   140,   198,   139,
     200,   139,   200,   139,   198,   141,     6,    -1,    69,    49,
     140,   198,   139,   200,   139,   200,   139,   198,   141,     6,
      -1,    69,    43,   140,   198,   139,   200,   139,   200,   139,
     200,   139,   198,   141,     6,    -1,    69,    46,   140,   198,
     139,   200,   139,   200,   139,   200,   139,   198,   141,     6,
      -1,    69,    49,   140,   198,   139,   200,   139,   200,   139,
     200,   139,   198,   141,     6,    -1,    -1,    69,    43,   140,
     198,   139,   200,   141,   184,   140,   193,   141,     6,    -1,
      -1,    69,    46,   140,   198,   139,   200,   141,   185,   140,
     193,   141,     6,    -1,    -1,    69,    49,   140,   198,   139,
     200,   141,   186,   140,   193,   141,     6,    -1,    -1,    69,
      43,   140,   198,   139,   200,   139,   200,   139,   198,   141,
     187,   140,   193,   141,     6,    -1,    -1,    69,    46,   140,
     198,   139,   200,   139,   200,   139,   198,   141,   188,   140,
     193,   141,     6,    -1,    -1,    69,    49,   140,   198,   139,
     200,   139,   200,   139,   198,   141,   189,   140,   193,   141,
       6,    -1,    -1,    69,    43,   140,   198,   139,   200,   139,
     200,   139,   200,   139,   198,   141,   190,   140,   193,   141,
       6,    -1,    -1,    69,    46,   140,   198,   139,   200,   139,
     200,   139,   200,   139,   198,   141,   191,   140,   193,   141,
       6,    -1,    -1,    69,    49,   140,   198,   139,   200,   139,
     200,   139,   200,   139,   198,   141,   192,   140,   193,   141,
       6,    -1,   194,    -1,   193,   194,    -1,    78,   140,   198,
     141,     6,    -1,    78,   140,   203,   139,   203,   141,     6,
      -1,    78,   140,   203,   139,   203,   139,   203,   141,     6,
      -1,    72,     6,    -1,    79,   133,   198,   134,     7,   203,
      61,   198,     6,    -1,    58,    46,   203,     7,   198,     6,
      -1,    58,    46,   203,     7,   198,    61,    63,   198,     6,
      -1,    58,    46,   203,     7,   198,    61,    62,   198,     6,
      -1,    58,    49,   140,   198,   141,     7,   203,     6,    -1,
      58,    49,   140,   198,   141,     7,   203,     4,     6,    -1,
      55,    49,   140,   198,   141,     7,   203,     6,    -1,    58,
      51,   140,   198,   141,     7,   203,     6,    -1,    72,    49,
     203,     7,   198,     6,    -1,    72,    49,   203,     6,    -1,
      73,    49,   203,     7,   198,     6,    -1,    43,   140,   205,
     141,    95,    49,   140,   198,   141,     6,    -1,    46,   140,
     205,   141,    95,    49,   140,   198,   141,     6,    -1,    46,
     140,   205,   141,    95,    51,   140,   198,   141,     6,    -1,
      49,   140,   205,   141,    95,    51,   140,   198,   141,     6,
      -1,    75,     6,    -1,   199,    -1,   133,   198,   134,    -1,
     124,   198,    -1,   123,   198,    -1,   128,   198,    -1,   198,
     124,   198,    -1,   198,   123,   198,    -1,   198,   125,   198,
      -1,   198,   126,   198,    -1,   198,   127,   198,    -1,   198,
     132,   198,    -1,   198,   119,   198,    -1,   198,   120,   198,
      -1,   198,   122,   198,    -1,   198,   121,   198,    -1,   198,
     118,   198,    -1,   198,   117,   198,    -1,   198,   116,   198,
      -1,   198,   115,   198,    -1,   198,   114,   198,     8,   198,
      -1,    14,   133,   198,   134,    -1,    15,   133,   198,   134,
      -1,    16,   133,   198,   134,    -1,    17,   133,   198,   134,
      -1,    18,   133,   198,   134,    -1,    19,   133,   198,   134,
      -1,    20,   133,   198,   134,    -1,    21,   133,   198,   134,
      -1,    22,   133,   198,   134,    -1,    24,   133,   198,   134,
      -1,    25,   133,   198,   139,   198,   134,    -1,    26,   133,
     198,   134,    -1,    27,   133,   198,   134,    -1,    28,   133,
     198,   134,    -1,    29,   133,   198,   134,    -1,    30,   133,
     198,   134,    -1,    31,   133,   198,   134,    -1,    32,   133,
     198,   139,   198,   134,    -1,    33,   133,   198,   139,   198,
     134,    -1,    34,   133,   198,   139,   198,   134,    -1,    23,
     133,   198,   134,    -1,    14,   135,   198,   136,    -1,    15,
     135,   198,   136,    -1,    16,   135,   198,   136,    -1,    17,
     135,   198,   136,    -1,    18,   135,   198,   136,    -1,    19,
     135,   198,   136,    -1,    20,   135,   198,   136,    -1,    21,
     135,   198,   136,    -1,    22,   135,   198,   136,    -1,    24,
     135,   198,   136,    -1,    25,   135,   198,   139,   198,   136,
      -1,    26,   135,   198,   136,    -1,    27,   135,   198,   136,
      -1,    28,   135,   198,   136,    -1,    29,   135,   198,   136,
      -1,    30,   135,   198,   136,    -1,    31,   135,   198,   136,
      -1,    32,   135,   198,   139,   198,   136,    -1,    33,   135,
     198,   139,   198,   136,    -1,    34,   135,   198,   139,   198,
     136,    -1,    23,   135,   198,   136,    -1,     3,    -1,     9,
      -1,    10,    -1,    11,    -1,   107,    -1,   108,    -1,   109,
      -1,     4,    -1,     4,   142,   140,   198,   141,    -1,     4,
     135,   198,   136,    -1,   138,     4,   135,   136,    -1,     4,
     166,    -1,     4,   135,   198,   136,   166,    -1,     4,   137,
       4,    -1,     4,   135,   198,   136,   137,     4,    -1,     4,
     137,     4,   166,    -1,     4,   135,   198,   136,   137,     4,
     166,    -1,   106,   133,     5,   139,   198,   134,    -1,   201,
      -1,   124,   200,    -1,   123,   200,    -1,   200,   124,   200,
      -1,   200,   123,   200,    -1,   140,   198,   139,   198,   139,
     198,   139,   198,   139,   198,   141,    -1,   140,   198,   139,
     198,   139,   198,   139,   198,   141,    -1,   140,   198,   139,
     198,   139,   198,   141,    -1,   133,   198,   139,   198,   139,
     198,   134,    -1,   203,    -1,   202,   139,   203,    -1,   198,
      -1,   204,    -1,   140,   141,    -1,   140,   205,   141,    -1,
     124,   140,   205,   141,    -1,   198,   125,   140,   205,   141,
      -1,   124,   204,    -1,   198,   125,   204,    -1,   198,     8,
     198,    -1,   198,     8,   198,     8,   198,    -1,    43,   140,
     198,   141,    -1,   170,    -1,   178,    -1,     4,   135,   136,
      -1,     4,   135,   140,   205,   141,   136,    -1,   198,    -1,
     204,    -1,   205,   139,   198,    -1,   205,   139,   204,    -1,
     140,   198,   139,   198,   139,   198,   139,   198,   141,    -1,
     140,   198,   139,   198,   139,   198,   141,    -1,     4,    -1,
       4,   137,    92,   137,     4,    -1,   140,   208,   141,    -1,
       4,   135,   198,   136,   137,    93,    -1,   206,    -1,   208,
     139,   206,    -1,   210,    -1,     4,    -1,     5,    -1,    42,
      -1,    37,   133,   209,   139,   209,   134,    -1,    38,   133,
     209,   134,    -1,    39,   133,   209,   134,    -1,    36,   133,
     209,   134,    -1,    36,   133,   209,   139,   205,   134,    -1,
      36,   133,     4,   137,     4,   134,    -1,    36,   133,     4,
     135,   198,   136,   137,     4,   134,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   146,   146,   147,   152,   154,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     175,   179,   186,   191,   206,   219,   248,   265,   274,   287,
     290,   291,   292,   293,   294,   298,   300,   305,   307,   313,
     457,   312,   471,   476,   485,   484,   499,   504,   513,   512,
     526,   531,   542,   541,   553,   554,   555,   556,   557,   561,
     562,   569,   600,   639,   693,   710,   728,   739,   756,   763,
     778,   796,   822,   849,   863,   880,   895,   913,   933,   953,
     961,   966,   980,   993,  1011,  1021,  1036,  1040,  1053,  1075,
    1091,  1113,  1131,  1149,  1167,  1193,  1211,  1237,  1257,  1275,
    1293,  1319,  1336,  1355,  1373,  1411,  1417,  1423,  1430,  1454,
    1478,  1494,  1514,  1531,  1548,  1569,  1574,  1579,  1584,  1589,
    1600,  1606,  1615,  1616,  1621,  1624,  1628,  1651,  1674,  1697,
    1725,  1734,  1737,  1750,  1766,  1781,  1795,  1801,  1807,  1816,
    1830,  1878,  1894,  1908,  1927,  1937,  1959,  1963,  1968,  1973,
    1985,  2002,  2019,  2046,  2073,  2104,  2112,  2118,  2125,  2129,
    2138,  2146,  2154,  2163,  2162,  2175,  2174,  2187,  2186,  2199,
    2198,  2210,  2209,  2225,  2232,  2239,  2246,  2253,  2260,  2267,
    2274,  2281,  2289,  2288,  2300,  2299,  2311,  2310,  2322,  2321,
    2333,  2332,  2344,  2343,  2355,  2354,  2366,  2365,  2377,  2376,
    2391,  2394,  2400,  2409,  2429,  2452,  2456,  2480,  2498,  2516,
    2534,  2563,  2598,  2603,  2630,  2644,  2657,  2674,  2680,  2686,
    2689,  2698,  2708,  2709,  2710,  2711,  2712,  2713,  2714,  2715,
    2716,  2723,  2724,  2725,  2726,  2727,  2728,  2729,  2730,  2731,
    2732,  2733,  2734,  2735,  2736,  2737,  2738,  2739,  2740,  2741,
    2742,  2743,  2744,  2745,  2746,  2747,  2748,  2749,  2750,  2751,
    2752,  2753,  2754,  2756,  2757,  2758,  2759,  2760,  2761,  2762,
    2763,  2764,  2765,  2766,  2767,  2768,  2769,  2770,  2771,  2772,
    2773,  2774,  2775,  2776,  2785,  2786,  2787,  2788,  2789,  2790,
    2791,  2795,  2811,  2826,  2846,  2859,  2872,  2895,  2913,  2931,
    2949,  2967,  2975,  2979,  2983,  2987,  2991,  2998,  3002,  3006,
    3010,  3017,  3022,  3030,  3035,  3039,  3044,  3048,  3056,  3067,
    3075,  3083,  3089,  3100,  3120,  3130,  3140,  3157,  3184,  3189,
    3193,  3197,  3210,  3214,  3226,  3233,  3254,  3258,  3273,  3278,
    3285,  3289,  3296,  3300,  3308,  3316,  3330,  3344,  3348,  3367,
    3390
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
  "tDelete", "tCoherence", "tIntersect", "tBoundary", "tLayers", "tHole",
  "tAlias", "tAliasWithOptions", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tOrder", "tKnots", "tColor", "tColorTable", "tFor", "tIn",
  "tEndFor", "tIf", "tEndIf", "tExit", "tField", "tReturn", "tCall",
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
     365,   366,   367,   368,    63,   369,   370,   371,   372,    60,
      62,   373,   374,    43,    45,    42,    47,    37,    33,   375,
     376,   377,    94,    40,    41,    91,    93,    46,    35,    44,
     123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   143,   144,   144,   145,   145,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     147,   147,   148,   148,   148,   148,   149,   149,   149,   150,
     150,   150,   150,   150,   150,   151,   151,   152,   152,   154,
     155,   153,   156,   156,   158,   157,   159,   159,   161,   160,
     162,   162,   164,   163,   165,   165,   165,   165,   165,   166,
     166,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   168,   168,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   170,   170,   170,   170,   170,
     170,   170,   171,   171,   172,   172,   172,   172,   172,   172,
     173,   173,   173,   173,   173,   174,   175,   175,   175,   175,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     178,   178,   178,   179,   178,   180,   178,   181,   178,   182,
     178,   183,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   184,   178,   185,   178,   186,   178,   187,   178,
     188,   178,   189,   178,   190,   178,   191,   178,   192,   178,
     193,   193,   194,   194,   194,   194,   194,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   196,   196,   196,
     196,   197,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   200,   200,   200,   200,   200,   201,   201,   201,
     201,   202,   202,   203,   203,   203,   203,   203,   203,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   205,   205,
     205,   205,   206,   206,   206,   206,   207,   207,   208,   208,
     209,   209,   210,   210,   210,   210,   210,   210,   210,   210,
     210
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
       9,     6,     9,     5,     8,     8,    11,     6,     9,     5,
       7,     9,     9,     9,     9,     9,     1,     1,     7,     8,
       6,     7,     7,     7,     9,     7,     9,    17,     7,     7,
      11,     8,     8,     8,     8,     3,     4,    10,     7,     7,
       8,     8,     8,     7,     8,     5,    11,     5,     9,     4,
       9,     4,     1,     1,     0,     2,     6,     6,     6,     6,
       4,     6,     6,     3,     4,     5,     3,     3,     4,     4,
       3,     7,     7,     3,     7,     3,     2,     2,    15,     2,
       6,     8,     8,    10,     1,     2,     1,     3,     4,     1,
       5,    11,    13,     0,     7,     0,    13,     0,    15,     0,
       6,     0,    10,     8,     8,     8,    12,    12,    12,    14,
      14,    14,     0,    12,     0,    12,     0,    12,     0,    16,
       0,    16,     0,    16,     0,    18,     0,    18,     0,    18,
       1,     2,     5,     7,     9,     2,     9,     6,     9,     9,
       8,     9,     8,     8,     6,     4,     6,    10,    10,    10,
      10,     2,     1,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     4,     2,     5,     3,     6,     4,
       7,     6,     1,     2,     2,     3,     3,    11,     9,     7,
       7,     1,     3,     1,     1,     2,     3,     4,     5,     2,
       3,     3,     5,     4,     1,     1,     3,     6,     1,     1,
       3,     3,     9,     7,     1,     5,     3,     6,     1,     3,
       1,     1,     1,     1,     6,     4,     4,     4,     6,     6,
       9
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
     154,     0,   159,     0,     0,   156,     0,     0,     0,     0,
       5,     7,     6,     8,     9,    10,    11,    12,    13,    19,
      18,    14,    15,    16,    17,   284,   291,   342,    54,   285,
     286,   287,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   343,     0,     0,
     288,   289,   290,    58,    57,    56,    55,     0,     0,     0,
      60,    59,     0,     0,     0,     0,     0,     0,     0,   222,
       0,     0,     0,     0,   147,     0,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,     0,     0,     0,     0,     0,     0,   124,     0,
     124,     0,     0,     0,     0,   124,   221,     0,   124,     0,
       0,     0,     0,     0,     0,   334,     0,     0,     0,     0,
       0,   146,     0,     0,   155,   341,   342,   124,     0,   340,
     124,     0,     0,     0,     0,     0,   295,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,   225,   224,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,   105,     0,
       0,     0,     0,   291,     0,     0,   324,   325,   328,   329,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   313,     0,   314,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   304,   303,     0,     0,     0,     0,   124,   124,
       0,     0,     0,     0,     0,     0,     0,     0,   169,     0,
     124,   123,     0,   122,     0,     0,     0,   133,     0,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,     0,
       0,   124,     0,     0,     0,     0,   157,     0,   136,     0,
     137,     0,     0,   297,     0,     0,    68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   341,
       0,     0,     0,     0,     0,     0,     0,   223,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,    61,     0,
     240,   239,   238,   237,   233,   234,   236,   235,   228,   227,
     229,   230,   231,   232,   106,     0,     0,     0,     0,     0,
       0,   224,   319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   315,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,     0,     0,     0,     0,     0,
       0,     0,   306,   305,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,     0,     0,   163,
     119,   215,     0,     0,   134,     0,     0,   130,     0,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     158,     0,   138,   139,     0,   293,   299,     0,    39,     0,
       0,     0,    52,     0,    30,    31,    32,    33,    34,   242,
     263,   243,   264,   244,   265,   245,   266,   246,   267,   247,
     268,   248,   269,   249,   270,   250,   271,   262,   283,   251,
     272,     0,     0,   253,   274,   254,   275,   255,   276,   256,
     277,   257,   278,   258,   279,     0,     0,     0,     0,     0,
       0,     0,     0,   347,     0,     0,   345,   346,    79,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
      73,     0,     0,     0,     0,   294,     0,    22,    20,     0,
       0,     0,     0,   326,     0,     0,   321,   229,   320,   330,
     331,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   316,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
       0,   160,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   135,     0,     0,     0,     0,
       0,     0,   296,     0,   292,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   293,    64,    65,     0,     0,     0,
       0,     0,    67,    69,    71,     0,     0,   338,     0,    77,
     241,    21,     0,     0,     0,     0,     0,   323,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   317,     0,    90,     0,     0,     0,     0,     0,
     207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,     0,     0,     0,     0,     0,
       0,     0,   205,     0,     0,   170,   201,     0,     0,   214,
     216,   132,   131,     0,    27,    28,     0,     0,     0,   335,
       0,     0,     0,   150,     0,     0,   142,   298,   141,     0,
       0,     0,     0,   311,     0,   252,   273,   259,   280,   260,
     281,   261,   282,     0,   349,   348,   344,   301,     0,    54,
       0,     0,     0,     0,    62,     0,     0,     0,   336,    23,
      24,     0,     0,    88,     0,   322,     0,    93,     0,    95,
       0,     0,    91,     0,     0,   108,   109,     0,     0,    92,
     113,   318,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,   124,   171,     0,   182,     0,   184,     0,   186,     0,
       0,     0,     0,   313,     0,     0,     0,     0,   164,     0,
      98,    99,     0,     0,     0,     0,    80,     0,   300,     0,
      35,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,    74,     0,     0,    75,     0,   339,     0,     0,   327,
       0,     0,     0,   101,     0,     0,   110,     0,     0,     0,
     212,   103,   104,     0,     0,     0,   210,   213,   112,    89,
     102,   111,   114,     0,     0,     0,   310,     0,   309,     0,
       0,     0,   173,     0,     0,   174,     0,     0,   175,     0,
     126,   127,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,   333,     0,   152,   151,     0,     0,     0,    40,
       0,     0,     0,   312,     0,     0,     0,     0,    63,    70,
      72,     0,    78,     0,    25,     0,     0,    94,    96,     0,
       0,     0,     0,     0,   209,   208,   211,    84,    85,   124,
       0,   118,     0,     0,     0,     0,     0,     0,     0,   202,
       0,     0,   124,     0,   120,     0,     0,     0,    81,    83,
      82,     0,    36,     0,     0,     0,    38,    53,   350,     0,
     337,     0,   217,   218,   219,   220,   107,     0,     0,     0,
     308,   172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,     0,     0,   332,   153,     0,
       0,     0,     0,    76,     0,     0,   116,     0,   188,     0,
       0,   190,     0,     0,   192,     0,     0,     0,   203,     0,
     161,     0,   124,   100,     0,    44,     0,    50,     0,     0,
       0,   307,   176,     0,     0,   183,   177,     0,     0,   185,
     178,     0,     0,   187,     0,     0,     0,   167,     0,     0,
       0,     0,     0,     0,     0,   194,     0,   196,     0,   198,
     204,   206,   166,   162,     0,    41,     0,    48,     0,     0,
       0,     0,   179,     0,     0,   180,     0,     0,   181,     0,
       0,     0,    42,     0,     0,   148,     0,     0,     0,     0,
       0,     0,     0,   168,     0,     0,     0,     0,     0,   189,
       0,   191,     0,   193,     0,    43,    45,     0,    46,     0,
      97,     0,     0,     0,     0,     0,    51,   195,   197,   199,
      47,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    60,   649,    61,    62,   395,   949,   955,
     574,   735,  1081,  1201,   575,  1169,  1227,   576,  1203,   577,
     578,   739,   126,   216,    63,   512,   536,   306,   362,   363,
      66,    67,    68,    69,    70,   307,   712,  1141,  1184,   537,
    1000,  1003,  1006,  1009,  1153,  1157,  1161,  1193,  1196,  1199,
     708,   709,    72,    73,    74,   324,   129,   342,   171,   852,
     853,   326,   310,   197,   644,   768,   208,   209
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1029
static const yytype_int16 yypact[] =
{
    2852,    30,    42,  2930, -1029, -1029,  2002,    75,    67,    -7,
      20,   124,   -74,    38,    51,   -46,    77,    81,   -42,   142,
     160,   122,   -28,   138,   253,   256,   502,   265,    78,   204,
     231,   -38,   -38,   249,    33,   261,   313,   353,    23,   414,
     359,   291,   456,   470,   481,   363,   366,   369,    14,     9,
   -1029,   382, -1029,   486,   392, -1029,   528,   532,    12,    19,
   -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029,
   -1029, -1029, -1029, -1029, -1029, -1029,    16,   391,   599, -1029,
   -1029, -1029,   -55,    64,   189,   225,   323,   335,   442,   448,
     458,   489,   519,   540,   551,   559,   568,   569,   573,   595,
     604,   608,   609,   411,   416,   425,   432, -1029,   555,   455,
   -1029, -1029, -1029, -1029, -1029, -1029, -1029,  2207,  2207,  2207,
   -1029, -1029,  2207,  1766,    11,   597,  2207,   601,  1933, -1029,
     612,   617,  2207,   621, -1029,  2207, -1029,  2207,  2138,  2207,
    2207,   498,  2207,  2138,  2207,  2207,   514,  2138,  2207,  2207,
    1433,   515,  2207,   513,   525,   534,  1433,   530,   543,   541,
     547,   558,   562,   563,   683,   -38,   -38,   -38,  2207,  2207,
     -51, -1029,   -23,   -38,   553,   570,   577,   580,  1967,   175,
     748,  1433,  1433,    37,   592, -1029, -1029,   610,   748,   616,
     620,   753,  2207,  2207,  2207,   628,  2207,   664,   677,  2207,
    2207, -1029,  2207,   784, -1029, -1029, -1029, -1029,   803, -1029,
   -1029,   811,   686,  2207,   826,   694, -1029, -1029,   829,  2207,
    2207,  2207,  2207,  2207,  2207,  2207,  2207,  2207,  2207,  2207,
    2207,  2207,  2207,  2207,  2207,  2207,  2207,  2207,  2207,  2207,
    2207,  2207,  2207,  2207,  2207,  2207,  2207,  2207,  2207,  2207,
    2207,  2207,  2207,  2207,  2207,  2207,  2207,  2207,  2207,  2207,
    2207,   710,   790,   790,   790,  2207,   839,   581,   738,   738,
     738,  5242,    55,  2138,  4483,   333,   734,   869,   752,  2311,
   -1029, -1029,  2207,  2207,  2207,  2207,  2207,  2207,  2207,  2207,
    2207,  2207,  2207,  2207,  2207,  2207,  2207, -1029, -1029,  2338,
     129,  3729,  5263,   594,   762,  2138, -1029, -1029,  2069, -1029,
      72,  5284,  5305,  2207,  5326,   227,  5347,  5368,  2207,   354,
    5389,  5410,  1565,  1162,  2653,   873, -1029,  2207,  5431,  2207,
    2207,  2207,   881,  2207,  2207,  2207,  2264,  2264,  2264,  2264,
     758,   197, -1029, -1029,  3755,  3781,   -38,   -38,   748,   748,
     298,  2207,  2207,  2207,  2207,  1967,  1967,  2207,  2996,   328,
   -1029, -1029,   759,  2996,    61,   898,   900, -1029,  2207,  2207,
     953,  2138,   766,  2207,  2207, -1029,  5452,  5473,  5494,   816,
    3807, -1029,   769,  2675,  5515,  4506, -1029,  1339, -1029,  1471,
   -1029,  2207,  4529,   264,  2207,     8, -1029,  5536,  4552,  5557,
    4575,  5578,  4598,  5599,  4621,  5620,  4644,  5641,  4667,  5662,
    4690,  5683,  4713,  5704,  4736,  5725,  4759,  5746,  4782,  3833,
    3859,  5767,  4805,  5788,  4828,  5809,  4851,  5830,  4874,  5851,
    4897,  5872,  4920,  3885,  3911,  3937,  3963,  3989,  4015,   459,
     133,   771,   777,   780,  2358,   776,  2207, -1029,  1433,  1433,
     429,   266,   599,  2207,   910,   913,    15,   782, -1029,  2702,
     985,   836,   732,   732,   716,   716,   716,   716,   303,   303,
     738,   738,   738,   738, -1029,    59,  2138,  2207,   912,  1829,
    2207,   738, -1029,  2207,  2138,  2138,   825,   914,   921,  5893,
     923,   837,   924,   926,  5914,   841,   927,   930,  2138, -1029,
     615,  1697,  2207,  5935,   935,  3031,  5956,  5977,  2207,  3059,
    3087,  5998,   810,  6229, -1029,   812,   815,   817,   808,   -38,
    2207,  2207, -1029, -1029,   809,   830,  2207,  4943,  4041,  4067,
    4093,  3703,   -63,    -8,   -41,   131, -1029,   -34,   -38,  1603,
   -1029, -1029,  2207,  2207, -1029,  4966,  4989, -1029,   619, -1029,
    5012,  5035,   963,   965,   966,   853,  2207,  1867,  2207,  2207,
   -1029,     0, -1029, -1029,  5058,    70, -1029,  3115, -1029,   858,
     875,   834, -1029,   986, -1029, -1029, -1029, -1029, -1029, -1029,
   -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029,
   -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029,
   -1029,  2207,  2207, -1029, -1029, -1029, -1029, -1029, -1029, -1029,
   -1029, -1029, -1029, -1029, -1029,  2207,  2207,  2207,  2207,  2207,
    2207,  2207,   991, -1029,  2138,   790, -1029, -1029, -1029,  2207,
    5081,  1000,  1005,   879, -1029,    18,  2207,  1010,  1012,  2390,
   -1029,  1013,   886,    14,  1016, -1029,  2207, -1029,   903,   790,
     169,  4119,   -38, -1029,  2138,  3143,  2722,   738, -1029,  2069,
   -1029,   975,  1433,  1433,  1018,  1433,   712,  1433,  1433,  1020,
     977,  1433,  1433,   632, -1029,  2138,  2409,  1022,   890,  1025,
    1026,  1027,   862,  1028,  1029,  1030,  1031,  1032,  1036,  1037,
    1041,   330,  4145,  4171, -1029, -1029,  3171,   906,   -38,   -38,
     -38,  2138,  2138,  2138,  2138,  1042,   907,   916,   187, -1029,
     395, -1029,   -34,  2433,  2460,  1044,  1045,  1003,  1048,  1049,
    1433,  1433,  1433,  1052,  4197, -1029,  2754,  1092,  1053,  1054,
    1056,  1060, -1029,  1061, -1029,   933,  2207,  2207,  1433,   920,
   -1029,  6019,  5104,  6040,  5127,  6061,  5150,  6082,  5173,  5196,
     934,   178,   936,  6103,   -84, -1029, -1029,   184,   378,   932,
    1065,  2480, -1029, -1029, -1029,    14,  2207, -1029,   650, -1029,
    6229, -1029,  1067,    63,  2207,    46,   657, -1029,  2207,   937,
      25,    28,  1433,  1068,   938,   941,  1069,  1070,  1433,   942,
    1077,  1078, -1029,   658, -1029,  1080,  2207,  1433,  1433,  1433,
   -1029,    34,  1433,  1433,  1433,  1433,  1433,  1433,  1433,   441,
    2207,  2207,  2207,   946, -1029,   222,   233,   259,   662,   671,
     692,   708, -1029,  1433,  2207, -1029, -1029,  1967,   198, -1029,
   -1029, -1029, -1029,   948, -1029, -1029,  1083,  1084,  1001, -1029,
    2207,  2207,  2207, -1029,  1085,  1086, -1029,   264, -1029,  2207,
    4223,  4249,   721, -1029,  2207, -1029, -1029, -1029, -1029, -1029,
   -1029, -1029, -1029,   959, -1029, -1029, -1029, -1029,  1433,   599,
    2207,  1091,  1094,    15, -1029,  1093,  5219,    14, -1029, -1029,
   -1029,   790,  4275, -1029,   982,  6229,  2207, -1029,   -38, -1029,
     -38,  1107, -1029,  2207,  2207, -1029, -1029,  1113,  2207, -1029,
   -1029, -1029,  1115,  4301,  1116,  1117,  1118,  2207,  2207,   859,
    1120,  1123,  1124,  1127,  1130,  1131, -1029,  2264,  3199,  6124,
    2947,   748,  2996,   -38,  1132,   -38,  1133,   -38,  1134,  1135,
    1137,  1138,  1140,   292,  1008,  6145,  3227,   422, -1029,  2207,
   -1029, -1029,  1433,  2975,   661,  6166, -1029,  1301, -1029,   247,
    6229,  2207,  2207,  1433,   981,   728,  6229,  1144,  1146,  1148,
    2512, -1029,  1143,  1150, -1029,  1021, -1029,  1153,  2207, -1029,
    3255,    54,    58, -1029,  3283,  3311, -1029,  3339,  1155,  2207,
   -1029, -1029, -1029,  2531,  2555,  1156, -1029, -1029, -1029, -1029,
   -1029, -1029, -1029,  2582,  1157,  1024, -1029,  2207, -1029,  1033,
     -34,   461, -1029,  1057,   463, -1029,  1058,   506, -1029,  1059,
   -1029, -1029, -1029, -1029,  1161,  1433,  1154,  1062,  2207,  3367,
    1079,  2207, -1029,  2207, -1029, -1029,  1126,  1164,  1194, -1029,
    2207,  4327,  4353, -1029,  1433,  2207,  1195,  1034, -1029, -1029,
   -1029,    14, -1029,  1110, -1029,  4379,  1198, -1029, -1029,  1214,
    1215,  1216,  1217,  4405, -1029, -1029, -1029, -1029, -1029,   748,
    3003, -1029,   232,  1967,   -34,  1967,   -34,  1967,   -34, -1029,
     736,  1433, -1029,  3395, -1029,  2207,  3423,  3451, -1029, -1029,
   -1029,  1095,  6229,  2207,  2207,   740,  6229, -1029, -1029,  1219,
   -1029,  2207, -1029, -1029, -1029, -1029, -1029,  1228,  1096,  2207,
   -1029, -1029,  3479,   510,   360,  3507,   520,   362,  3535,   554,
     383,  1433,  1230,  1173,  2306,  1114,  2602, -1029, -1029,  2207,
    6187,  4431,    27, -1029,  4457,  1121, -1029,  3563,  1249,  2207,
    1250,  1251,  2207,  1253,  1255,  2207,  1256,  1122, -1029,  2207,
   -1029,   -34, -1029, -1029,   744, -1029,  2207, -1029,  1433,  2207,
    1259, -1029, -1029,  1125,  3591, -1029, -1029,  1136,  3619, -1029,
   -1029,  1139,  3647, -1029,  1260,  2634,   387,  2362,  1261,  1141,
    6208,   745,  3675,  1145,   -34,  1266,   -34,  1267,   -34,  1268,
   -1029, -1029, -1029, -1029,   -34, -1029,   790, -1029,  1142,  1269,
    1272,   399, -1029,  1147,   433, -1029,  1152,   435, -1029,  1158,
     478,   754, -1029,  1159,  1433, -1029,  1160,  1274,   -34,  1277,
     -34,  1282,   -34, -1029,   790,  1288,   790,   757,  1290, -1029,
     527, -1029,   531, -1029,   549, -1029, -1029,   760, -1029,  1291,
   -1029,  1296,  1302,  1303,   790,  1307, -1029, -1029, -1029, -1029,
   -1029, -1029
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1029, -1029, -1029, -1029,   505, -1029, -1029, -1029, -1029,   188,
   -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029,
   -1029, -1029,  -271,    -1, -1029,   145,  1311,     6,  -187,  -175,
   -1029, -1029, -1029, -1029, -1029,  1333, -1029, -1029, -1029, -1029,
   -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029, -1029,
    -641,  -515, -1029, -1029, -1029,    -4, -1029,   226, -1029, -1028,
    -142,   237,    65,  -615,   468, -1029,   -59,     5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     211,   372,   128,   358,   453,   127,  1085,   728,   325,    65,
     370,   130,   568,   198,   332,   275,   205,   206,   195,   642,
     212,   151,   758,   205,   206,   141,   134,   183,   767,   146,
     146,   887,   387,  1147,   889,   389,     4,   174,   705,   364,
     365,   366,     5,   367,   706,   707,   120,   121,   103,   104,
     105,   106,   883,   731,   107,   103,   104,   105,   106,   137,
    1047,   107,   448,   141,  1048,   647,   138,   541,   542,   880,
     137,   828,   346,   347,   205,   206,   175,   701,   219,   176,
     220,   888,   177,   218,   890,   166,   167,   142,   131,   348,
     569,   570,   571,   572,   143,   168,   907,   908,   147,   703,
     346,   347,   169,   276,   277,   152,   103,   104,   105,   106,
     759,   760,   107,   268,   269,   270,   132,   349,   271,   274,
    1171,   160,   279,   184,   161,   142,   133,   162,   299,   163,
     136,   301,   702,   302,   308,   311,   312,   729,   314,   308,
     316,   317,   199,   308,   320,   321,   120,   121,   328,   573,
     875,   213,   207,   214,   196,   643,   166,   167,   215,   210,
     135,   524,   525,   185,   344,   345,   168,  1148,   449,   346,
     347,   139,   368,   178,   345,   150,  1217,   346,   347,   648,
     636,   346,   347,   648,   140,   539,   361,   153,   376,   377,
     378,   634,   380,   826,   361,   383,   384,   221,   385,   222,
     120,   121,   440,   441,   442,   443,   557,   731,   315,   392,
     144,   485,   319,   486,   145,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   170,   172,   705,
     179,   444,   966,   475,   149,   706,   707,   623,   476,   308,
     705,   704,   624,   634,   454,   148,   706,   707,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   149,   113,   114,   115,   116,   346,   347,
     483,   481,   154,   773,   705,   155,   631,   632,   485,   489,
     706,   707,   865,   826,   494,   360,   159,   485,   481,   308,
     346,   347,   223,   503,   224,   505,   506,   507,   825,   509,
     510,   511,   513,   513,   513,   513,   519,   164,   450,   938,
     452,   514,   514,   514,   514,   346,   347,   527,   528,   529,
     530,   268,   269,   531,   361,   361,   346,   347,   225,  1062,
     226,   923,   181,   924,   545,   546,   485,   308,   491,   550,
     551,   165,   925,  1101,   926,   309,   113,   114,   115,   116,
     309,  1029,   346,   347,   309,   869,  1030,   564,   500,   173,
     567,   341,   566,   343,   120,   121,   120,   121,   927,   350,
     928,   180,   182,   635,   359,   187,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   501,   294,   295,
     186,   346,   347,  1104,   296,  1107,  1089,  1110,   293,   294,
     295,   188,   705,  1014,   705,   296,   548,   526,   706,   707,
     706,   707,   630,   113,   114,   115,   116,   916,   917,   639,
     637,   346,   347,   346,   347,   705,   227,   638,   228,   705,
     189,   706,   707,   120,   121,   706,   707,   538,   229,   810,
     230,   705,   308,   651,   190,   630,   655,   706,   707,   656,
     657,   659,   515,   516,   517,   191,   868,   870,   113,   114,
     115,   116,   201,   485,   308,   495,   192,   657,   676,   193,
    1166,  1130,   194,  1133,   682,   705,   733,   705,   120,   121,
     309,   706,   707,   706,   707,   200,   692,   693,   346,   347,
     780,   781,   696,   783,  1136,   786,   787,   202,  1182,   790,
     791,   217,   203,  1191,   827,  1194,   204,  1197,   713,   714,
    1207,   650,   482,  1200,   261,   346,   347,   826,   156,   262,
     705,   157,   724,   158,   726,   727,   706,   707,   263,   482,
     309,  1018,   265,   673,   732,   264,   752,  1220,   485,  1222,
     633,  1224,   522,   523,  1209,   231,  1211,   232,   836,   837,
     838,   233,   343,   234,   346,   347,   346,   347,   266,   826,
     772,   235,   826,   236,   621,   826,   622,   741,   742,   705,
    1063,   278,  1065,   705,   206,   706,   707,   280,   309,   706,
     707,   743,   744,   745,   746,   747,   748,   749,   297,  1213,
     308,   705,   237,   298,   238,   753,   300,   706,   707,   346,
     347,   313,   761,   346,   347,   103,   104,   105,   106,   922,
     891,   107,   770,   346,   347,  1067,   897,   318,   327,  1129,
     308,   826,   239,   329,   240,   904,   905,   906,   330,  1132,
     909,   910,   911,   912,   913,   914,   915,   331,  1231,  1023,
     333,   308,  1232,   241,   335,   242,   826,   346,   347,   826,
     336,   934,   826,   334,   243,   826,   244,   340,   351,   751,
    1233,   337,   245,  1135,   246,   338,   339,   308,   308,   308,
     308,   247,   249,   248,   250,   826,   251,   826,   252,   826,
     352,   120,   121,   309,   439,   206,   446,   353,   214,   776,
     354,   658,   660,   215,   120,   121,   958,   369,   253,   479,
     254,   214,   850,   851,   999,   309,   215,   255,   658,   256,
     793,   257,   259,   258,   260,   691,   103,   104,   105,   106,
     371,   373,   107,   732,   485,   374,   674,   871,   485,   375,
     717,   784,   876,   785,   710,   379,   818,   819,   820,   821,
     882,   485,   382,   792,   885,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   877,
     386,   878,   903,   296,   205,   206,   485,   485,   884,   901,
    1020,   485,  1024,   929,   381,  1027,   918,   919,   920,   388,
     485,  1033,   930,    30,    31,    32,    33,   390,    35,   933,
     935,   391,   967,   936,    40,    41,   103,   104,   105,   106,
     393,   485,   107,   931,   394,   396,   943,   944,   945,   291,
     292,   293,   294,   295,   445,   950,   948,   485,   296,   932,
     956,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     953,   309,   954,   985,   296,   986,   960,  1035,   800,  1036,
     296,   455,  1098,  1070,   959,  1111,   456,  1112,   775,   953,
     502,  1122,   970,  1035,   953,  1168,  1188,   457,   508,   974,
     975,   309,   518,  1214,   977,  1215,   953,  1114,  1229,  1234,
     540,  1235,   480,   983,   984,   543,   544,   549,   555,   558,
     625,   626,   309,   993,   627,   629,   640,   641,   645,   652,
     661,   662,   994,   801,   815,   816,   817,   361,   663,  1113,
     665,   667,   666,   668,   671,  1019,   670,   672,   309,   309,
     309,   309,   678,  1026,   686,   690,   687,  1031,  1032,   688,
     694,   689,  1028,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,  1045,     7,     8,  1167,   296,  1137,
     720,   695,   721,   722,   738,  1053,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     723,   736,   740,  1060,   296,   750,   532,    13,    14,   533,
      16,    17,   534,    19,   535,    21,   755,    22,   737,    24,
      25,   756,    27,    28,  1073,   757,   762,  1076,   763,  1077,
     765,   766,   769,   771,   779,   782,  1082,   788,   789,   795,
     796,  1086,   797,   798,   799,   802,   803,   804,   805,   806,
      45,    46,    47,   807,   808,   809,   814,   823,   822,   824,
     831,   832,   833,   937,   834,   835,   839,   844,   845,  1102,
     854,  1105,   846,  1108,   847,   361,   849,   848,   864,   872,
     866,  1116,   873,   879,   892,   895,   896,   886,   893,  1120,
    1121,   894,   898,   899,   900,   902,   921,  1124,   939,   940,
     941,   946,   942,   947,   547,  1127,   957,   961,   962,   964,
     842,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   973,   971,   956,   972,   296,   969,   976,
     978,  1034,   980,   981,   982,  1154,   987,  1202,  1158,   988,
     989,  1162,  1078,   990,   483,  1165,   991,   992,  1002,  1005,
    1008,  1010,  1170,  1011,  1012,  1172,  1013,  1015,  1037,  1001,
    1041,  1004,  1038,  1007,  1039,  1225,  1042,  1228,  1043,  1044,
    1052,  1071,  1056,  1058,  1059,    75,   303,  1069,  1088,  1075,
    1079,    79,    80,    81,  1061,  1240,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,  1064,  1066,  1068,
    1080,  1087,  1072,  1090,  1092,   304,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
    1093,  1094,  1095,  1096,   296,  1123,   843,    30,    31,    32,
      33,    34,    35,  1125,  1139,  1119,  1138,  1126,    40,    41,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   501,   294,   295,  1142,  1152,  1155,  1156,   296,  1159,
    1150,  1160,  1163,  1164,  1173,  1174,  1180,  1185,   109,   110,
     111,   112,  1192,  1195,  1198,  1205,  1176,  1206,   881,  1178,
    1219,  1186,  1204,  1221,  1190,   117,   305,  1208,  1223,  1103,
     119,  1106,  1210,  1109,  1226,   122,  1230,  1236,  1212,  1216,
     125,  1218,  1237,   499,    75,   303,   206,  1144,  1238,  1239,
      79,    80,    81,  1241,    64,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    71,   103,   104,   105,
     106,   963,     0,   107,   304,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,    40,    41,     0,
       0,     0,   532,    13,    14,   533,    16,    17,   534,    19,
     535,    21,     0,    22,     0,    24,    25,     0,    27,    28,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   111,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   322,    45,    46,    47,   119,
       0,     0,     0,     0,   122,     0,    75,   303,     0,   125,
       0,   323,    79,    80,    81,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,   304,     0,     0,     0,
     562,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,    40,
      41,     0,     0,     0,   532,    13,    14,   533,    16,    17,
     534,    19,   535,    21,     0,    22,     0,    24,    25,     0,
      27,    28,     0,     0,     0,     0,     0,     0,     0,   109,
     110,   111,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,   322,    45,    46,
      47,   119,     0,     0,     0,     0,   122,     0,    75,   303,
       0,   125,     0,   323,    79,    80,    81,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,   304,     0,
       0,     0,   563,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      30,    31,    32,    33,    34,    35,     0,     0,     0,     0,
       0,    40,    41,     0,     0,     0,   532,    13,    14,   533,
      16,    17,   534,    19,   535,    21,     0,    22,     0,    24,
      25,     0,    27,    28,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   305,
      45,    46,    47,   119,     0,     0,     0,     0,   122,     0,
      75,   303,     0,   125,     0,   498,    79,    80,    81,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
     304,     0,     0,     0,   711,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,    31,    32,    33,    34,    35,     0,    75,
     267,     0,     0,    40,    41,    79,    80,    81,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,   305,     0,     0,     0,   119,     0,     0,     0,     0,
     122,     0,    75,   267,     0,   125,     0,   675,    79,    80,
      81,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   111,   112,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,   117,
     118,     0,     0,     0,   119,     0,     0,     0,     0,   122,
       0,     0,   272,     0,   125,     0,   273,     0,     0,     0,
     532,    13,    14,   533,    16,    17,   534,    19,   535,    21,
       0,    22,     0,    24,    25,     0,    27,    28,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   111,   112,   281,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,   118,    45,    46,    47,   119,     0,     0,
       0,     0,   122,     0,     0,   653,     0,   125,     0,   654,
      75,   267,     0,     0,     0,     0,    79,    80,    81,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,    75,    76,    77,   725,    78,
       0,    79,    80,    81,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     0,   103,   104,
     105,   106,     0,     0,   107,     0,     0,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,     0,   109,   110,   111,   112,   483,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     355,   356,     0,     0,     0,   119,     0,     0,     0,     0,
     357,     0,   108,     0,     0,   125,     0,   169,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,   118,     0,     0,     0,
     119,     0,   120,   121,     0,   122,     0,   123,     0,   124,
     125,    75,   303,     0,     0,     0,     0,    79,    80,    81,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,   304,     0,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   484,   294,   295,     0,     0,     0,
       0,   296,     0,    30,    31,    32,    33,    34,    35,     0,
      75,   267,     0,     0,    40,    41,    79,    80,    81,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,   109,   110,   111,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,   305,     0,     0,     0,   119,    75,   267,   206,
       0,   122,     0,    79,    80,    81,   125,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103,   104,   105,   106,     0,     0,   107,     0,     0,     0,
       0,     0,     0,   109,   110,   111,   112,   458,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,   118,     0,     0,     0,   119,     0,     0,     0,     0,
     122,     0,     0,     0,   474,   125,     0,     0,     0,   532,
      13,    14,   533,    16,    17,   534,    19,   535,    21,     0,
      22,     0,    24,    25,   628,    27,    28,     0,     0,     0,
     109,   110,   111,   112,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   118,     0,
       0,     0,   119,    45,    46,    47,   764,   122,     0,     0,
       0,     0,   125,     0,     0,   532,    13,    14,   533,    16,
      17,   534,    19,   535,    21,   794,    22,     0,    24,    25,
       0,    27,    28,     0,     0,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   829,
       0,     0,     0,   296,     0,     0,     0,  1140,     0,    45,
      46,    47,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   830,     0,     0,     0,
     296,     0,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   874,     0,     0,     0,
     296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1183,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,  1040,     0,
       0,     0,   296,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,  1054,     0,     0,
       0,   296,     0,     0,     0,     0,     0,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,  1055,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,     0,     0,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,  1057,     0,
       0,     0,   296,     0,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,  1143,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
    1181,     0,     0,     0,   296,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,   483,     0,   296,     0,     0,     0,     0,     0,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   559,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,     0,     0,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     646,     0,     0,     0,   296,     0,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     778,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   841,     0,     0,     0,   296,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   501,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,     0,     0,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,    -4,     1,   296,     0,    -4,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,     0,     0,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,    -4,     0,     0,
       0,     0,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,    -4,    -4,     6,     0,     0,     0,    -4,    -4,
      -4,    -4,     7,     8,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,    34,
      35,     0,    36,    37,    38,    39,    40,    41,     7,     8,
      42,    43,     0,     0,     0,     0,    44,    45,    46,    47,
       0,     0,    48,     0,    49,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,     0,   532,
      13,    14,   533,    16,    17,   534,    19,   535,    21,     0,
      22,     0,    24,    25,     0,    27,    28,     0,     0,     0,
       0,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,    45,    46,    47,   997,     0,   998,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,  1021,     0,  1022,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,  1099,     0,  1100,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,   679,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
     683,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,   684,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,     0,     0,   734,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,     0,     0,   777,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,   813,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
     995,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,  1017,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,     0,     0,  1046,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,     0,     0,  1049,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,  1050,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
    1051,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,  1074,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,     0,     0,  1115,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,     0,     0,  1117,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,  1118,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
    1128,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,  1131,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,     0,     0,  1134,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,     0,     0,  1151,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,  1175,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
    1177,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,  1179,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,     0,     0,  1189,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,   447,     0,     0,
       0,     0,   520,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,   477,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,   520,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
     521,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,   556,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,   601,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,   602,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,   615,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
     616,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,   617,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,   618,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,   619,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,   620,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
     698,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,   699,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,   700,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,   774,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,   811,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
     812,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,   840,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,   951,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,   952,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,   968,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
     979,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,  1083,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,  1084,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,  1091,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,  1097,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
    1146,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,  1149,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,   451,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,   561,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,   565,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,   580,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,   582,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,   584,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,   586,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
     588,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,   590,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,   592,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,   594,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,   596,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,   598,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,   600,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,   604,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,   606,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,   608,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
     610,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,   612,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,   614,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,   697,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,   715,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,   716,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,     0,     0,   718,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,     0,
       0,   719,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,     0,     0,   730,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,     0,     0,   754,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,     0,     0,
     856,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,     0,     0,   858,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,     0,     0,   860,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,     0,     0,   862,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
       0,     0,   863,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,     0,     0,   965,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,   447,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,   478,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,   487,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,   488,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
     490,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,   492,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,   493,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,   496,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,   497,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,   504,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,   552,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,   553,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,   554,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,   560,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
     579,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,   581,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,   583,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,   585,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,   587,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,   589,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,   591,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,   593,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,   595,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,   597,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
     599,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,   603,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,   605,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,   607,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,   609,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,   611,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,   613,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,   664,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,   669,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,   677,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
     680,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,   681,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,   685,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296,     0,   855,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,     0,     0,
       0,     0,   296,     0,   857,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,   296,     0,   859,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       0,     0,     0,     0,   296,     0,   861,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     0,     0,     0,     0,   296,     0,   867,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,     0,     0,     0,     0,   296,     0,   996,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,     0,     0,   296,     0,  1016,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,     0,     0,     0,     0,   296,     0,
    1025,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   296,
       0,  1145,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,     0,     0,     0,     0,
     296,     0,  1187,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,     0,     0,     0,
       0,   296
};

static const yytype_int16 yycheck[] =
{
      59,   188,     6,   178,   275,     6,  1034,     7,   150,     3,
     185,     6,     4,     4,   156,     4,     4,     5,     4,     4,
       4,    49,     4,     4,     5,    71,     6,     4,   643,    71,
      71,     6,   207,     6,     6,   210,     6,     4,    72,   181,
     182,     4,     0,     6,    78,    79,   130,   131,    36,    37,
      38,    39,     6,   137,    42,    36,    37,    38,    39,   133,
       6,    42,     7,    71,     6,     6,   140,     6,     7,     6,
     133,   712,   123,   124,     4,     5,    43,   140,   133,    46,
     135,    56,    49,    78,    56,   123,   124,   133,    13,   140,
      82,    83,    84,    85,   140,   133,    62,    63,   140,   140,
     123,   124,   140,    92,    93,   133,    36,    37,    38,    39,
      92,    93,    42,   117,   118,   119,    49,   140,   122,   123,
    1148,    43,   126,   100,    46,   133,   133,    49,   132,    51,
       6,   135,   140,   137,   138,   139,   140,   137,   142,   143,
     144,   145,   133,   147,   148,   149,   130,   131,   152,   141,
     765,   135,   140,   137,   140,   140,   123,   124,   142,   140,
     140,   348,   349,   140,   168,   169,   133,   140,   113,   123,
     124,   133,   135,   140,   178,    53,  1204,   123,   124,   120,
     451,   123,   124,   120,   133,   360,   180,    49,   192,   193,
     194,     7,   196,   708,   188,   199,   200,   133,   202,   135,
     130,   131,   261,   262,   263,   264,   381,   137,   143,   213,
     133,   139,   147,   141,   133,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    31,    32,    72,
      34,   265,   877,   134,   133,    78,    79,   134,   139,   273,
      72,   140,   139,     7,   275,   133,    78,    79,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   133,   110,   111,   112,   113,   123,   124,
       8,   305,    49,   134,    72,    49,   448,   449,   139,   313,
      78,    79,   134,   828,   318,   140,    51,   139,   322,   323,
     123,   124,   133,   327,   135,   329,   330,   331,   141,   333,
     334,   335,   336,   337,   338,   339,   139,   133,   273,   141,
       7,   336,   337,   338,   339,   123,   124,   351,   352,   353,
     354,   355,   356,   357,   348,   349,   123,   124,   133,  1000,
     135,   139,    49,   141,   368,   369,   139,   371,   141,   373,
     374,   140,   139,   141,   141,   138,   110,   111,   112,   113,
     143,   134,   123,   124,   147,     7,   139,   391,   323,   140,
     394,   165,   393,   167,   130,   131,   130,   131,   139,   173,
     141,   140,    49,   137,   178,    46,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       6,   123,   124,  1064,   132,  1066,  1041,  1068,   125,   126,
     127,   140,    72,   141,    72,   132,   371,   139,    78,    79,
      78,    79,   446,   110,   111,   112,   113,     6,     7,   453,
     451,   123,   124,   123,   124,    72,   133,   452,   135,    72,
       4,    78,    79,   130,   131,    78,    79,   139,   133,   139,
     135,    72,   476,   477,     4,   479,   480,    78,    79,   483,
     484,   485,   337,   338,   339,     4,   757,   758,   110,   111,
     112,   113,     6,   139,   498,   141,   133,   501,   502,   133,
    1141,   141,   133,   141,   508,    72,   565,    72,   130,   131,
     273,    78,    79,    78,    79,   133,   520,   521,   123,   124,
     662,   663,   526,   665,   141,   667,   668,   135,   141,   671,
     672,   140,     4,  1174,   139,  1176,     4,  1178,   542,   543,
     141,   476,   305,  1184,   133,   123,   124,  1062,    46,   133,
      72,    49,   556,    51,   558,   559,    78,    79,   133,   322,
     323,   139,     7,   498,   565,   133,   625,  1208,   139,  1210,
     141,  1212,   346,   347,   141,   133,   141,   135,   720,   721,
     722,   133,   356,   135,   123,   124,   123,   124,   133,  1104,
     649,   133,  1107,   135,   135,  1110,   137,   601,   602,    72,
     139,     4,   139,    72,     5,    78,    79,     6,   371,    78,
      79,   615,   616,   617,   618,   619,   620,   621,     6,   141,
     624,    72,   133,     6,   135,   629,     5,    78,    79,   123,
     124,   133,   636,   123,   124,    36,    37,    38,    39,   814,
     782,    42,   646,   123,   124,   139,   788,   133,   133,   139,
     654,  1166,   133,   140,   135,   797,   798,   799,   133,   139,
     802,   803,   804,   805,   806,   807,   808,   133,   141,     8,
     140,   675,   141,   133,   133,   135,  1191,   123,   124,  1194,
     133,   823,  1197,   140,   133,  1200,   135,     4,   135,   624,
     141,   133,   133,   139,   135,   133,   133,   701,   702,   703,
     704,   133,   133,   135,   135,  1220,   133,  1222,   135,  1224,
     140,   130,   131,   476,     4,     5,   135,   140,   137,   654,
     140,   484,   485,   142,   130,   131,   868,   135,   133,   135,
     135,   137,   736,   737,   921,   498,   142,   133,   501,   135,
     675,   133,   133,   135,   135,   519,    36,    37,    38,    39,
     140,   135,    42,   754,   139,   135,   141,   758,   139,     6,
     141,    49,   766,    51,   538,   137,   701,   702,   703,   704,
     774,   139,    95,   141,   778,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   139,
       6,   141,   796,   132,     4,     5,   139,   139,   141,   141,
     942,   139,   141,   141,   140,   947,   810,   811,   812,     6,
     139,   953,   141,    65,    66,    67,    68,     6,    70,   823,
     824,   135,   881,   827,    76,    77,    36,    37,    38,    39,
       4,   139,    42,   141,   140,     6,   840,   841,   842,   123,
     124,   125,   126,   127,     5,   849,   847,   139,   132,   141,
     854,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     139,   624,   141,     4,   132,     6,   870,   139,     6,   141,
     132,   137,  1059,  1015,   869,   139,     7,   141,   652,   139,
       7,   141,   886,   139,   139,   141,   141,   135,     7,   893,
     894,   654,   134,   139,   898,   141,   139,  1072,   141,   139,
     141,   141,   140,   907,   908,     7,     6,   141,    92,   140,
     139,   134,   675,   917,   134,   139,     6,     4,   136,     7,
      95,     7,   917,    61,   698,   699,   700,   921,     7,  1071,
       7,     7,    95,     7,     7,   939,    95,     7,   701,   702,
     703,   704,     7,   947,   134,   137,   134,   951,   952,   134,
     141,   134,   947,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   968,    12,    13,  1142,   132,  1111,
       7,   141,     7,     7,   140,   979,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     137,   133,     6,   997,   132,     4,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     6,    54,   133,    56,
      57,     6,    59,    60,  1018,   136,     6,  1021,     6,  1023,
       7,   135,     6,   120,    49,     7,  1030,     7,    51,     7,
     140,  1035,     7,     7,     7,     7,     7,     7,     7,     7,
      87,    88,    89,     7,     7,     4,   140,   140,     6,   133,
       6,     6,    49,   827,     6,     6,     4,     4,     4,  1063,
     140,  1065,     6,  1067,     4,  1059,   133,     6,   134,   137,
     134,  1075,     7,     6,     6,     6,     6,   140,   140,  1083,
    1084,   140,   140,     6,     6,     5,   140,  1091,   140,     6,
       6,     6,    91,     7,   141,  1099,   137,     6,     4,     6,
       8,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,     6,   888,  1119,   890,   132,   136,     6,
       5,   140,     6,     6,     6,  1129,     6,  1186,  1132,     6,
       6,  1135,     6,     6,     8,  1139,     6,     6,     6,     6,
       6,     6,  1146,     6,     6,  1149,     6,   139,     4,   923,
       7,   925,     6,   927,     6,  1214,     6,  1216,   137,     6,
       5,     7,     6,     6,   140,     3,     4,     6,   134,    90,
       6,     9,    10,    11,   141,  1234,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,   140,   140,   140,
       6,     6,   140,    93,     6,    43,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       6,     6,     6,     6,   132,     6,   134,    65,    66,    67,
      68,    69,    70,     5,    61,   140,     6,   141,    76,    77,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   140,     6,     6,     6,   132,     6,
     139,     6,     6,   141,     5,   140,     6,     6,   106,   107,
     108,   109,     6,     6,     6,     6,   140,     5,   773,   140,
       6,   140,   140,     6,   139,   123,   124,   140,     6,  1063,
     128,  1065,   140,  1067,     6,   133,     6,     6,   140,   140,
     138,   141,     6,   141,     3,     4,     5,  1119,     6,     6,
       9,    10,    11,     6,     3,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     3,    36,    37,    38,
      39,   873,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    -1,    56,    57,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,    87,    88,    89,   128,
      -1,    -1,    -1,    -1,   133,    -1,     3,     4,    -1,   138,
      -1,   140,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
     141,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    76,
      77,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    -1,    56,    57,    -1,
      59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,    87,    88,
      89,   128,    -1,    -1,    -1,    -1,   133,    -1,     3,     4,
      -1,   138,    -1,   140,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,   141,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    76,    77,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    -1,    56,
      57,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   106,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
      87,    88,    89,   128,    -1,    -1,    -1,    -1,   133,    -1,
       3,     4,    -1,   138,    -1,   140,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    68,    69,    70,    -1,     3,
       4,    -1,    -1,    76,    77,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,   106,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,
     133,    -1,     3,     4,    -1,   138,    -1,   140,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   106,   107,   108,   109,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    -1,    56,    57,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,   108,   109,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,    87,    88,    89,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,   140,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,     3,     4,     5,   141,     7,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,   107,   108,   109,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,
     133,    -1,   100,    -1,    -1,   138,    -1,   140,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,    -1,    -1,    -1,
     128,    -1,   130,   131,    -1,   133,    -1,   135,    -1,   137,
     138,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    65,    66,    67,    68,    69,    70,    -1,
       3,     4,    -1,    -1,    76,    77,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,    -1,    -1,    -1,   128,     3,     4,     5,
      -1,   133,    -1,     9,    10,    11,   138,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,   106,   107,   108,   109,     6,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,     6,   138,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    -1,    56,    57,     6,    59,    60,    -1,    -1,    -1,
     106,   107,   108,   109,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,    -1,
      -1,    -1,   128,    87,    88,    89,     6,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     6,    54,    -1,    56,    57,
      -1,    59,    60,    -1,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     6,
      -1,    -1,    -1,   132,    -1,    -1,    -1,   141,    -1,    87,
      88,    89,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     6,    -1,    -1,    -1,
     132,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     6,    -1,    -1,    -1,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     6,    -1,
      -1,    -1,   132,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     6,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     6,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     6,    -1,
      -1,    -1,   132,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     6,    -1,
      -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       6,    -1,    -1,    -1,   132,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,     8,    -1,   132,    -1,    -1,    -1,    -1,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,     8,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       8,    -1,    -1,    -1,   132,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       8,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     8,    -1,    -1,    -1,   132,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,    -1,     0,     1,   132,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    35,    -1,    -1,
      -1,    -1,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,     4,    -1,    -1,    -1,    86,    87,
      88,    89,    12,    13,    92,    -1,    94,    -1,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      40,    41,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    72,    73,    74,    75,    76,    77,    12,    13,
      80,    81,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      -1,    -1,    92,    -1,    94,    -1,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    -1,    56,    57,    -1,    59,    60,    -1,    -1,    -1,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    87,    88,    89,   139,    -1,   141,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    -1,   141,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    -1,   141,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,   134,    -1,    -1,
      -1,    -1,   139,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,   136,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
      -1,    -1,   136,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,   136,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,   136,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,   136,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     132,    -1,    -1,    -1,   136,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,   136,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,
     136,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,   136,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    -1,    -1,
      -1,    -1,   132,    -1,    -1,    -1,   136,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,   136,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
      -1,    -1,   136,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,   136,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,   136,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,   136,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     132,    -1,    -1,    -1,   136,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,   136,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,
     136,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,   136,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    -1,    -1,
      -1,    -1,   132,    -1,    -1,    -1,   136,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,   136,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
      -1,    -1,   136,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,   136,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,   136,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,   136,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     132,    -1,    -1,    -1,   136,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,   136,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,
     136,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,   136,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    -1,    -1,
      -1,    -1,   132,    -1,    -1,    -1,   136,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,   136,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
      -1,    -1,   136,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,   136,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,   134,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,   134,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    -1,   134,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,   134,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
     134,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,   134,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     132,    -1,   134,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,   134,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    -1,    -1,
      -1,    -1,   132,    -1,   134,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,   134,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,   134,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,   134,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    -1,   134,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,   134,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
     134,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,   134,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     132,    -1,   134,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,   134,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    -1,    -1,
      -1,    -1,   132,    -1,   134,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,   134,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,   134,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,   134,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    -1,   134,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,   134,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
     134,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,   134,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     132,    -1,   134,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,   134,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    -1,    -1,
      -1,    -1,   132,    -1,   134,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,   134,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,   134,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,   134,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    -1,   134,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,   134,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
     134,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,   134,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     132,    -1,   134,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,   134,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    -1,    -1,
      -1,    -1,   132,    -1,   134,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,   134,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,   134,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,   134,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    -1,   134,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,   134,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
     134,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,   134,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     132,    -1,   134,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   144,   145,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    55,    56,    57,    58,    59,    60,    64,
      65,    66,    67,    68,    69,    70,    72,    73,    74,    75,
      76,    77,    80,    81,    86,    87,    88,    89,    92,    94,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     146,   148,   149,   167,   169,   170,   173,   174,   175,   176,
     177,   178,   195,   196,   197,     3,     4,     5,     7,     9,
      10,    11,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    36,    37,    38,    39,    42,   100,   106,
     107,   108,   109,   110,   111,   112,   113,   123,   124,   128,
     130,   131,   133,   135,   137,   138,   165,   166,   198,   199,
     210,    13,    49,   133,     6,   140,     6,   133,   140,   133,
     133,    71,   133,   140,   133,   133,    71,   140,   133,   133,
      53,    49,   133,    49,    49,    49,    46,    49,    51,    51,
      43,    46,    49,    51,   133,   140,   123,   124,   133,   140,
     200,   201,   200,   140,     4,    43,    46,    49,   140,   200,
     140,    49,    49,     4,   100,   140,     6,    46,   140,     4,
       4,     4,   133,   133,   133,     4,   140,   206,     4,   133,
     133,     6,   135,     4,     4,     4,     5,   140,   209,   210,
     140,   209,     4,   135,   137,   142,   166,   140,   210,   133,
     135,   133,   135,   133,   135,   133,   135,   133,   135,   133,
     135,   133,   135,   133,   135,   133,   135,   133,   135,   133,
     135,   133,   135,   133,   135,   133,   135,   133,   135,   133,
     135,   133,   135,   133,   135,   133,   135,   133,   135,   133,
     135,   133,   133,   133,   133,     7,   133,     4,   198,   198,
     198,   198,   136,   140,   198,     4,    92,    93,     4,   198,
       6,     6,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   132,     6,     6,   198,
       5,   198,   198,     4,    43,   124,   170,   178,   198,   204,
     205,   198,   198,   133,   198,   205,   198,   198,   133,   205,
     198,   198,   124,   140,   198,   203,   204,   133,   198,   140,
     133,   133,   203,   140,   140,   133,   133,   133,   133,   133,
       4,   200,   200,   200,   198,   198,   123,   124,   140,   140,
     200,   135,   140,   140,   140,   123,   124,   133,   172,   200,
     140,   170,   171,   172,   203,   203,     4,     6,   135,   135,
     172,   140,   171,   135,   135,     6,   198,   198,   198,   137,
     198,   140,    95,   198,   198,   198,     6,   172,     6,   172,
       6,   135,   198,     4,   140,   150,     6,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,     4,
     209,   209,   209,   209,   198,     5,   135,   134,     7,   113,
     205,   136,     7,   165,   166,   137,     7,   135,     6,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,     6,   134,   139,   139,   134,   135,
     140,   198,   204,     8,   125,   139,   141,   134,   134,   198,
     134,   141,   134,   134,   198,   141,   134,   134,   140,   141,
     205,   125,     7,   198,   134,   198,   198,   198,     7,   198,
     198,   198,   168,   198,   210,   168,   168,   168,   134,   139,
     139,   139,   200,   200,   171,   171,   139,   198,   198,   198,
     198,   198,    43,    46,    49,    51,   169,   182,   139,   172,
     141,     6,     7,     7,     6,   198,   198,   141,   205,   141,
     198,   198,   134,   134,   134,    92,   139,   172,   140,     8,
     134,   136,   141,   141,   198,   136,   166,   198,     4,    82,
      83,    84,    85,   141,   153,   157,   160,   162,   163,   134,
     136,   134,   136,   134,   136,   134,   136,   134,   136,   134,
     136,   134,   136,   134,   136,   134,   136,   134,   136,   134,
     136,   139,   139,   134,   136,   134,   136,   134,   136,   134,
     136,   134,   136,   134,   136,   139,   139,   139,   139,   139,
     139,   135,   137,   134,   139,   139,   134,   134,     6,   139,
     198,   203,   203,   141,     7,   137,   165,   166,   210,   198,
       6,     4,     4,   140,   207,   136,     8,     6,   120,   147,
     205,   198,     7,   136,   140,   198,   198,   198,   204,   198,
     204,    95,     7,     7,   134,     7,    95,     7,     7,   134,
      95,     7,     7,   205,   141,   140,   198,   134,     7,   141,
     134,   134,   198,   141,   141,   134,   134,   134,   134,   134,
     137,   200,   198,   198,   141,   141,   198,   136,   139,   139,
     139,   140,   140,   140,   140,    72,    78,    79,   193,   194,
     200,   141,   179,   198,   198,   136,   136,   141,   136,   136,
       7,     7,     7,   137,   198,   141,   198,   198,     7,   137,
     136,   137,   166,   209,   141,   154,   133,   133,   140,   164,
       6,   198,   198,   198,   198,   198,   198,   198,   198,   198,
       4,   205,   209,   198,   136,     6,     6,   136,     4,    92,
      93,   198,     6,     6,     6,     7,   135,   206,   208,     6,
     198,   120,   209,   134,   139,   200,   205,   141,     8,    49,
     203,   203,     7,   203,    49,    51,   203,   203,     7,    51,
     203,   203,   141,   205,     6,     7,   140,     7,     7,     7,
       6,    61,     7,     7,     7,     7,     7,     7,     7,     4,
     139,   139,   139,   141,   140,   200,   200,   200,   205,   205,
     205,   205,     6,   140,   133,   141,   194,   139,   193,     6,
       6,     6,     6,    49,     6,     6,   203,   203,   203,     4,
     139,     8,     8,   134,     4,     4,     6,     4,     6,   133,
     198,   198,   202,   203,   140,   134,   136,   134,   136,   134,
     136,   134,   136,   136,   134,   134,   134,   134,   165,     7,
     165,   166,   137,     7,     6,   206,   198,   139,   141,     6,
       6,   147,   198,     6,   141,   198,   140,     6,    56,     6,
      56,   203,     6,   140,   140,     6,     6,   203,   140,     6,
       6,   141,     5,   198,   203,   203,   203,    62,    63,   203,
     203,   203,   203,   203,   203,   203,     6,     7,   198,   198,
     198,   140,   172,   139,   141,   139,   141,   139,   141,   141,
     141,   141,   141,   198,   203,   198,   198,   200,   141,   140,
       6,     6,    91,   198,   198,   198,     6,     7,   166,   151,
     198,   139,   139,   139,   141,   152,   198,   137,   203,   210,
     198,     6,     4,   207,     6,   136,   206,   209,   139,   136,
     198,   200,   200,     6,   198,   198,     6,   198,     5,   139,
       6,     6,     6,   198,   198,     4,     6,     6,     6,     6,
       6,     6,     6,   198,   210,   141,   134,   139,   141,   171,
     183,   200,     6,   184,   200,     6,   185,   200,     6,   186,
       6,     6,     6,     6,   141,   139,   134,   141,   139,   198,
     203,   139,   141,     8,   141,   134,   198,   203,   210,   134,
     139,   198,   198,   203,   140,   139,   141,     4,     6,     6,
       6,     7,     6,   137,     6,   198,   141,     6,     6,   141,
     141,   141,     5,   198,     6,     6,     6,     6,     6,   140,
     198,   141,   193,   139,   140,   139,   140,   139,   140,     6,
     203,     7,   140,   198,   141,    90,   198,   198,     6,     6,
       6,   155,   198,   139,   139,   202,   198,     6,   134,   206,
      93,   139,     6,     6,     6,     6,     6,   139,   171,   139,
     141,   141,   198,   200,   193,   198,   200,   193,   198,   200,
     193,   139,   141,   203,   172,   141,   198,   141,   141,   140,
     198,   198,   141,     6,   198,     5,   141,   198,   141,   139,
     141,   141,   139,   141,   141,   139,   141,   203,     6,    61,
     141,   180,   140,     6,   152,   134,   139,     6,   140,   139,
     139,   141,     6,   187,   198,     6,     6,   188,   198,     6,
       6,   189,   198,     6,   141,   198,   193,   172,   141,   158,
     198,   202,   198,     5,   140,   141,   140,   141,   140,   141,
       6,     6,   141,   141,   181,     6,   140,   134,   141,   141,
     139,   193,     6,   190,   193,     6,   191,   193,     6,   192,
     193,   156,   209,   161,   140,     6,     5,   141,   140,   141,
     140,   141,   140,   141,   139,   141,   140,   202,   141,     6,
     193,     6,   193,     6,   193,   209,     6,   159,   209,   141,
       6,   141,   141,   141,   139,   141,     6,     6,     6,     6,
     209,     6
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
    { return 1; ;}
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
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 167 "Gmsh.y"
    { return 1; ;}
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
#line 176 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 21:
#line 180 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 22:
#line 187 "Gmsh.y"
    {
      Msg(DIRECT, (yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 23:
#line 192 "Gmsh.y"
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
#line 207 "Gmsh.y"
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
#line 220 "Gmsh.y"
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
#line 249 "Gmsh.y"
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
#line 266 "Gmsh.y"
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
#line 275 "Gmsh.y"
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
#line 287 "Gmsh.y"
    {
      ViewData = new PViewDataList(true); 
    ;}
    break;

  case 35:
#line 299 "Gmsh.y"
    { ViewCoord[ViewCoordIdx++] = (yyvsp[(1) - (1)].d); ;}
    break;

  case 36:
#line 301 "Gmsh.y"
    { ViewCoord[ViewCoordIdx++] = (yyvsp[(3) - (3)].d); ;}
    break;

  case 37:
#line 306 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(1) - (1)].d)); ;}
    break;

  case 38:
#line 308 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(3) - (3)].d)); ;}
    break;

  case 39:
#line 313 "Gmsh.y"
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
#line 457 "Gmsh.y"
    {
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(int j = 0; j < ViewCoordIdx / 3; j++)
	    List_Add(ViewValueList, &ViewCoord[3 * j + i]);
      }
    ;}
    break;

  case 41:
#line 465 "Gmsh.y"
    {
      if(ViewValueList) (*ViewNumList)++;
    ;}
    break;

  case 42:
#line 472 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(ViewData->T2C, &(yyvsp[(1) - (1)].c)[i]); 
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 43:
#line 477 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(ViewData->T2C, &(yyvsp[(3) - (3)].c)[i]); 
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 44:
#line 485 "Gmsh.y"
    { 
      List_Add(ViewData->T2D, &(yyvsp[(3) - (8)].d)); 
      List_Add(ViewData->T2D, &(yyvsp[(5) - (8)].d));
      List_Add(ViewData->T2D, &(yyvsp[(7) - (8)].d)); 
      double d = List_Nbr(ViewData->T2C);
      List_Add(ViewData->T2D, &d); 
    ;}
    break;

  case 45:
#line 493 "Gmsh.y"
    {
      ViewData->NbT2++;
    ;}
    break;

  case 46:
#line 500 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(ViewData->T3C, &(yyvsp[(1) - (1)].c)[i]); 
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 47:
#line 505 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(ViewData->T3C, &(yyvsp[(3) - (3)].c)[i]); 
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 48:
#line 513 "Gmsh.y"
    { 
      List_Add(ViewData->T3D, &(yyvsp[(3) - (10)].d)); List_Add(ViewData->T3D, &(yyvsp[(5) - (10)].d));
      List_Add(ViewData->T3D, &(yyvsp[(7) - (10)].d)); List_Add(ViewData->T3D, &(yyvsp[(9) - (10)].d)); 
      double d = List_Nbr(ViewData->T3C);
      List_Add(ViewData->T3D, &d); 
    ;}
    break;

  case 49:
#line 520 "Gmsh.y"
    {
      ViewData->NbT3++;
    ;}
    break;

  case 50:
#line 528 "Gmsh.y"
    {
      ViewData->adaptive = new Adaptive_Post_View(ViewData, (yyvsp[(3) - (8)].l), (yyvsp[(6) - (8)].l));
    ;}
    break;

  case 51:
#line 535 "Gmsh.y"
    {
      ViewData->adaptive = new Adaptive_Post_View(ViewData, (yyvsp[(3) - (14)].l), (yyvsp[(6) - (14)].l), (yyvsp[(9) - (14)].l), (yyvsp[(12) - (14)].l));
    ;}
    break;

  case 52:
#line 542 "Gmsh.y"
    {
      ViewValueList = ViewData->Time;
    ;}
    break;

  case 53:
#line 546 "Gmsh.y"
    {
    ;}
    break;

  case 54:
#line 553 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 55:
#line 554 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 56:
#line 555 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 57:
#line 556 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 58:
#line 557 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 59:
#line 561 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 60:
#line 562 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 61:
#line 570 "Gmsh.y"
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
#line 601 "Gmsh.y"
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
#line 640 "Gmsh.y"
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
#line 694 "Gmsh.y"
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
#line 711 "Gmsh.y"
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
#line 729 "Gmsh.y"
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
#line 740 "Gmsh.y"
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
#line 757 "Gmsh.y"
    { 
      Msg(WARNING, "Named string expressions not implemented yet");
    ;}
    break;

  case 69:
#line 764 "Gmsh.y"
    { 
      const char* (*pStrOpt)(int num, int action, const char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory((yyvsp[(1) - (6)].c))))
	yymsg(GERROR, "Unknown string option class '%s'", (yyvsp[(1) - (6)].c));
      else{
	if(!(pStrOpt = (const char *(*) (int, int, const char *))
	     Get_StringOption((yyvsp[(3) - (6)].c), pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s.%s'", (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c));
	else
	  pStrOpt(0, GMSH_SET|GMSH_GUI, (yyvsp[(5) - (6)].c));
      }
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); //FIXME: somtimes leak $5
    ;}
    break;

  case 70:
#line 779 "Gmsh.y"
    { 
      const char* (*pStrOpt)(int num, int action, const char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory((yyvsp[(1) - (9)].c))))
	yymsg(GERROR, "Unknown string option class '%s'", (yyvsp[(1) - (9)].c));
      else{
	if(!(pStrOpt = (const char *(*) (int, int, const char *))
	     Get_StringOption((yyvsp[(6) - (9)].c), pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s[%d].%s'", (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c));
	else
	  pStrOpt((int)(yyvsp[(3) - (9)].d), GMSH_SET|GMSH_GUI, (yyvsp[(8) - (9)].c));
      }
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); //FIXME: somtimes leak $8
    ;}
    break;

  case 71:
#line 797 "Gmsh.y"
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
#line 823 "Gmsh.y"
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
#line 850 "Gmsh.y"
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
#line 864 "Gmsh.y"
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
#line 881 "Gmsh.y"
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
#line 896 "Gmsh.y"
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
#line 914 "Gmsh.y"
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
#line 934 "Gmsh.y"
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
		if(!strcmp((yyvsp[(1) - (5)].c),"Background")){
			GModel::current()->fields.background_field=(int)(yyvsp[(4) - (5)].d);
		}else{
			yymsg(GERROR, "Unknown command %s Field.",(yyvsp[(1) - (5)].c));
		}
	;}
    break;

  case 80:
#line 962 "Gmsh.y"
    {
		if(!GModel::current()->fields.new_field((int)(yyvsp[(3) - (7)].d),(yyvsp[(6) - (7)].c)))
				yymsg(GERROR, "Cannot create field %i of type '%s'.", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
	;}
    break;

  case 81:
#line 967 "Gmsh.y"
    {
		Field *field=GModel::current()->fields.get((int)(yyvsp[(3) - (9)].d));
		if(field){
			FieldOption *option=field->options[(yyvsp[(6) - (9)].c)];
			if(option){
				try {option->numerical_value((yyvsp[(8) - (9)].d));}
				catch(...){
					yymsg(GERROR, "Cannot assign a numerical value to  option '%s' in field %i of type '%s'", (yyvsp[(6) - (9)].c),(int)(yyvsp[(3) - (9)].d),field->get_name());
				}
			}else yymsg(GERROR, "Unknown option '%s' in field %i of type '%s'", (yyvsp[(6) - (9)].c),(int)(yyvsp[(3) - (9)].d),field->get_name());
		}else yymsg(GERROR, "No field with id %i",(int)(yyvsp[(3) - (9)].d));
			
	;}
    break;

  case 82:
#line 981 "Gmsh.y"
    {
		Field *field=GModel::current()->fields.get((int)(yyvsp[(3) - (9)].d));
		if(field){
			FieldOption *option=field->options[(yyvsp[(6) - (9)].c)];
			if(option){
				try {option->string()=(yyvsp[(8) - (9)].c);}
				catch (...){
					yymsg(GERROR, "Cannot assign a string value to  option '%s' in field %i of type '%s'", (yyvsp[(6) - (9)].c),(int)(yyvsp[(3) - (9)].d),field->get_name());
				}
			}else yymsg(GERROR, "Unknown option '%s' in field %i of type '%s'", (yyvsp[(6) - (9)].c),(int)(yyvsp[(3) - (9)].d),field->get_name());
		}else yymsg(GERROR, "No field with id %i",(int)(yyvsp[(3) - (9)].d));
	;}
    break;

  case 83:
#line 994 "Gmsh.y"
    {
		Field *field=GModel::current()->fields.get((int)(yyvsp[(3) - (9)].d));
		if(field){
			FieldOption *option=field->options[(yyvsp[(6) - (9)].c)];
			if(option){
				std::list<int> &vl=option->list();
				vl.clear();
				for(int i=0;i<List_Nbr((yyvsp[(8) - (9)].l));i++){
					double id;
					List_Read((yyvsp[(8) - (9)].l),i,&id);
					vl.push_back(id);
				}
			}else yymsg(GERROR, "Unknown option '%s' in field %i of type '%s'", (yyvsp[(6) - (9)].c),(int)(yyvsp[(3) - (9)].d),field->get_name());
		}else yymsg(GERROR, "No field with id %i",(int)(yyvsp[(3) - (9)].d));
	;}
    break;

  case 84:
#line 1012 "Gmsh.y"
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

  case 85:
#line 1022 "Gmsh.y"
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

  case 86:
#line 1037 "Gmsh.y"
    { 
      (yyval.i) = (int)(yyvsp[(1) - (1)].d); 
    ;}
    break;

  case 87:
#line 1041 "Gmsh.y"
    { 
      (yyval.i) = GModel::current()->setPhysicalName
	(std::string((yyvsp[(1) - (1)].c)), ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 88:
#line 1054 "Gmsh.y"
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

  case 89:
#line 1076 "Gmsh.y"
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

  case 90:
#line 1092 "Gmsh.y"
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

  case 91:
#line 1114 "Gmsh.y"
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

  case 92:
#line 1132 "Gmsh.y"
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

  case 93:
#line 1150 "Gmsh.y"
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

  case 94:
#line 1168 "Gmsh.y"
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

  case 95:
#line 1194 "Gmsh.y"
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

  case 96:
#line 1212 "Gmsh.y"
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

  case 97:
#line 1239 "Gmsh.y"
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

  case 98:
#line 1258 "Gmsh.y"
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

  case 99:
#line 1276 "Gmsh.y"
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

  case 100:
#line 1294 "Gmsh.y"
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

  case 101:
#line 1320 "Gmsh.y"
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

  case 102:
#line 1337 "Gmsh.y"
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

  case 103:
#line 1356 "Gmsh.y"
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

  case 104:
#line 1374 "Gmsh.y"
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

  case 105:
#line 1412 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 106:
#line 1418 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 107:
#line 1424 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 108:
#line 1431 "Gmsh.y"
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

  case 109:
#line 1455 "Gmsh.y"
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

  case 110:
#line 1479 "Gmsh.y"
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

  case 111:
#line 1495 "Gmsh.y"
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

  case 112:
#line 1515 "Gmsh.y"
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

  case 113:
#line 1532 "Gmsh.y"
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

  case 114:
#line 1549 "Gmsh.y"
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

  case 115:
#line 1570 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 116:
#line 1575 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 117:
#line 1580 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 118:
#line 1585 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 119:
#line 1590 "Gmsh.y"
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

  case 120:
#line 1601 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 121:
#line 1607 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      BoundaryShapes((yyvsp[(3) - (4)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 122:
#line 1615 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 123:
#line 1616 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 124:
#line 1621 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 125:
#line 1625 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 126:
#line 1629 "Gmsh.y"
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
	  GVertex *gv = GModel::current()->getVertexByTag(TheShape.Num);
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

  case 127:
#line 1652 "Gmsh.y"
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
	  GEdge *ge = GModel::current()->getEdgeByTag(TheShape.Num);
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

  case 128:
#line 1675 "Gmsh.y"
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
	  GFace *gf = GModel::current()->getFaceByTag(TheShape.Num);
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

  case 129:
#line 1698 "Gmsh.y"
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
	  GRegion *gr = GModel::current()->getRegionByTag(TheShape.Num);
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

  case 130:
#line 1726 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 131:
#line 1734 "Gmsh.y"
    {
		GModel::current()->fields.delete_field((int)(yyvsp[(4) - (6)].d));
	;}
    break;

  case 132:
#line 1738 "Gmsh.y"
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

  case 133:
#line 1751 "Gmsh.y"
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

  case 134:
#line 1767 "Gmsh.y"
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

  case 135:
#line 1782 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));      
    ;}
    break;

  case 136:
#line 1796 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 137:
#line 1802 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 138:
#line 1808 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 139:
#line 1817 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 140:
#line 1831 "Gmsh.y"
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

  case 141:
#line 1879 "Gmsh.y"
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

  case 142:
#line 1895 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (7)].c), "Background") && !strcmp((yyvsp[(2) - (7)].c), "Mesh")  && !strcmp((yyvsp[(3) - (7)].c), "View")){
	int index = (int)(yyvsp[(5) - (7)].d);
	if(index >= 0 && index < (int)PView::list.size()){
	  GModel::current()->fields.set_background_mesh(index);
	}
	else
	  yymsg(GERROR, "Unknown view %d", index);
      }
      else
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[(1) - (7)].c));
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(2) - (7)].c)); Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 143:
#line 1909 "Gmsh.y"
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

  case 144:
#line 1928 "Gmsh.y"
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

  case 145:
#line 1938 "Gmsh.y"
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

  case 146:
#line 1960 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 147:
#line 1964 "Gmsh.y"
    {
      CTX.forced_bbox = 0;
      SetBoundingBox();
    ;}
    break;

  case 148:
#line 1969 "Gmsh.y"
    {
      CTX.forced_bbox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 149:
#line 1974 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      Draw();
#endif
    ;}
    break;

  case 150:
#line 1986 "Gmsh.y"
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

  case 151:
#line 2003 "Gmsh.y"
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

  case 152:
#line 2020 "Gmsh.y"
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

  case 153:
#line 2047 "Gmsh.y"
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

  case 154:
#line 2074 "Gmsh.y"
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

  case 155:
#line 2105 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname,
						      gmsh_yylineno))
	yymsg(GERROR, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 156:
#line 2113 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&gmsh_yyin, gmsh_yyname,
						     gmsh_yylineno))
	yymsg(GERROR, "Error while exiting function");
    ;}
    break;

  case 157:
#line 2119 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname,
						     gmsh_yylineno))
	yymsg(GERROR, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 158:
#line 2126 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 159:
#line 2130 "Gmsh.y"
    {
    ;}
    break;

  case 160:
#line 2139 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 161:
#line 2147 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 162:
#line 2155 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 163:
#line 2163 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 164:
#line 2167 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 165:
#line 2175 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 166:
#line 2179 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 167:
#line 2187 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 168:
#line 2191 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 169:
#line 2199 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 170:
#line 2203 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 171:
#line 2210 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 172:
#line 2214 "Gmsh.y"
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

  case 173:
#line 2226 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 174:
#line 2233 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 175:
#line 2240 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 176:
#line 2247 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 177:
#line 2254 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 178:
#line 2261 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 179:
#line 2268 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 180:
#line 2275 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 181:
#line 2282 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 182:
#line 2289 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 183:
#line 2293 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 184:
#line 2300 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 185:
#line 2304 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 186:
#line 2311 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 187:
#line 2315 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 188:
#line 2322 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 189:
#line 2326 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 190:
#line 2333 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 191:
#line 2337 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 192:
#line 2344 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 193:
#line 2348 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 194:
#line 2355 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 195:
#line 2359 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 196:
#line 2366 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 197:
#line 2370 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 198:
#line 2377 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 199:
#line 2381 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 200:
#line 2392 "Gmsh.y"
    {
    ;}
    break;

  case 201:
#line 2395 "Gmsh.y"
    {
    ;}
    break;

  case 202:
#line 2401 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 203:
#line 2410 "Gmsh.y"
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

  case 204:
#line 2430 "Gmsh.y"
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

  case 205:
#line 2453 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 206:
#line 2457 "Gmsh.y"
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

  case 207:
#line 2481 "Gmsh.y"
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

  case 208:
#line 2499 "Gmsh.y"
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

  case 209:
#line 2517 "Gmsh.y"
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

  case 210:
#line 2535 "Gmsh.y"
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

  case 211:
#line 2564 "Gmsh.y"
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

  case 212:
#line 2599 "Gmsh.y"
    {
      yymsg(WARNING, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 213:
#line 2604 "Gmsh.y"
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

  case 214:
#line 2631 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	int j = (int)d;
	Surface *s = FindSurface(j);
	if(s){
	  s->Recombine = 1;
	  s->RecombineAngle = (yyvsp[(5) - (6)].d);
	}
      }
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 215:
#line 2645 "Gmsh.y"
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

  case 216:
#line 2658 "Gmsh.y"
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

  case 217:
#line 2675 "Gmsh.y"
    { 
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s)
	setSurfaceEmbeddedPoints(s, (yyvsp[(3) - (10)].l));
    ;}
    break;

  case 218:
#line 2681 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s)
	setSurfaceEmbeddedCurves(s, (yyvsp[(3) - (10)].l));
    ;}
    break;

  case 219:
#line 2687 "Gmsh.y"
    {
    ;}
    break;

  case 220:
#line 2690 "Gmsh.y"
    {
    ;}
    break;

  case 221:
#line 2699 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 222:
#line 2708 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 223:
#line 2709 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 224:
#line 2710 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 225:
#line 2711 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 226:
#line 2712 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 227:
#line 2713 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 228:
#line 2714 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 229:
#line 2715 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 230:
#line 2717 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(GERROR, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 231:
#line 2723 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 232:
#line 2724 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 233:
#line 2725 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 234:
#line 2726 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 235:
#line 2727 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 236:
#line 2728 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 237:
#line 2729 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 238:
#line 2730 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 239:
#line 2731 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 240:
#line 2732 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 241:
#line 2733 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d)? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d);  ;}
    break;

  case 242:
#line 2734 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 243:
#line 2735 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 244:
#line 2736 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 245:
#line 2737 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 246:
#line 2738 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 247:
#line 2739 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 248:
#line 2740 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 249:
#line 2741 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 250:
#line 2742 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 251:
#line 2743 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 252:
#line 2744 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 253:
#line 2745 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 254:
#line 2746 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 255:
#line 2747 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 256:
#line 2748 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 257:
#line 2749 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 258:
#line 2750 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 259:
#line 2751 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 260:
#line 2752 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 261:
#line 2753 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d)*(yyvsp[(3) - (6)].d)+(yyvsp[(5) - (6)].d)*(yyvsp[(5) - (6)].d)); ;}
    break;

  case 262:
#line 2754 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 263:
#line 2756 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 264:
#line 2757 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 265:
#line 2758 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 266:
#line 2759 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 267:
#line 2760 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 268:
#line 2761 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 269:
#line 2762 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 270:
#line 2763 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 271:
#line 2764 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 272:
#line 2765 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 273:
#line 2766 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 274:
#line 2767 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 275:
#line 2768 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 276:
#line 2769 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 277:
#line 2770 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 278:
#line 2771 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 279:
#line 2772 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 280:
#line 2773 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 281:
#line 2774 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 282:
#line 2775 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d)*(yyvsp[(3) - (6)].d)+(yyvsp[(5) - (6)].d)*(yyvsp[(5) - (6)].d)); ;}
    break;

  case 283:
#line 2776 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 284:
#line 2785 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 285:
#line 2786 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 286:
#line 2787 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->rank(); ;}
    break;

  case 287:
#line 2788 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->size(); ;}
    break;

  case 288:
#line 2789 "Gmsh.y"
    { (yyval.d) = Get_GmshMajorVersion(); ;}
    break;

  case 289:
#line 2790 "Gmsh.y"
    { (yyval.d) = Get_GmshMinorVersion(); ;}
    break;

  case 290:
#line 2791 "Gmsh.y"
    { (yyval.d) = Get_GmshPatchVersion(); ;}
    break;

  case 291:
#line 2796 "Gmsh.y"
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

  case 292:
#line 2812 "Gmsh.y"
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

  case 293:
#line 2827 "Gmsh.y"
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

  case 294:
#line 2847 "Gmsh.y"
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

  case 295:
#line 2860 "Gmsh.y"
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

  case 296:
#line 2873 "Gmsh.y"
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

  case 297:
#line 2896 "Gmsh.y"
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

  case 298:
#line 2914 "Gmsh.y"
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

  case 299:
#line 2932 "Gmsh.y"
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

  case 300:
#line 2950 "Gmsh.y"
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

  case 301:
#line 2968 "Gmsh.y"
    { 
      (yyval.d) = GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 302:
#line 2976 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 303:
#line 2980 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 304:
#line 2984 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 305:
#line 2988 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 306:
#line 2992 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 307:
#line 2999 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 308:
#line 3003 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 309:
#line 3007 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 310:
#line 3011 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 311:
#line 3018 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 312:
#line 3023 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 313:
#line 3031 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 314:
#line 3036 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 315:
#line 3040 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 316:
#line 3045 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 317:
#line 3049 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 318:
#line 3057 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 319:
#line 3068 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 320:
#line 3076 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 321:
#line 3084 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 322:
#line 3090 "Gmsh.y"
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

  case 323:
#line 3101 "Gmsh.y"
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

  case 324:
#line 3121 "Gmsh.y"
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

  case 325:
#line 3131 "Gmsh.y"
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

  case 326:
#line 3141 "Gmsh.y"
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

  case 327:
#line 3158 "Gmsh.y"
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

  case 328:
#line 3185 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 329:
#line 3190 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 330:
#line 3194 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 331:
#line 3198 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 332:
#line 3211 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 333:
#line 3215 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 334:
#line 3227 "Gmsh.y"
    {
      int flag;
      (yyval.u) = Get_ColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 335:
#line 3234 "Gmsh.y"
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

  case 336:
#line 3255 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 337:
#line 3259 "Gmsh.y"
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

  case 338:
#line 3274 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 339:
#line 3279 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 340:
#line 3286 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 341:
#line 3290 "Gmsh.y"
    {
      Msg(WARNING, "Named string expressions not implemented yet");
    ;}
    break;

  case 342:
#line 3297 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 343:
#line 3301 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32*sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 344:
#line 3309 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c))+strlen((yyvsp[(5) - (6)].c))+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 345:
#line 3317 "Gmsh.y"
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

  case 346:
#line 3331 "Gmsh.y"
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

  case 347:
#line 3345 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 348:
#line 3349 "Gmsh.y"
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

  case 349:
#line 3368 "Gmsh.y"
    { 
      const char* (*pStrOpt)(int num, int action, const char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory((yyvsp[(3) - (6)].c)))){
	yymsg(GERROR, "Unknown string option class '%s'", (yyvsp[(3) - (6)].c));
	(yyval.c) = (char*)Malloc(sizeof(char));
	(yyval.c)[0] = '\0';
      }
      else{
	if(!(pStrOpt = (const char *(*) (int, int, const char *))
	     Get_StringOption((yyvsp[(5) - (6)].c), pStrCat))){
	  yymsg(GERROR, "Unknown string option '%s.%s'", (yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
	  (yyval.c) = (char*)Malloc(sizeof(char));
	  (yyval.c)[0] = '\0';
	}
	else{
	  const char *str = pStrOpt(0, GMSH_GET, NULL);
	  (yyval.c) = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy((yyval.c), str);
	}
      }
    ;}
    break;

  case 350:
#line 3391 "Gmsh.y"
    { 
      const char* (*pStrOpt)(int num, int action, const char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory((yyvsp[(3) - (9)].c)))){
	yymsg(GERROR, "Unknown string option class '%s'", (yyvsp[(3) - (9)].c));
	(yyval.c) = (char*)Malloc(sizeof(char));
	(yyval.c)[0] = '\0';
      }
      else{
	if(!(pStrOpt = (const char *(*) (int, int, const char *))
	     Get_StringOption((yyvsp[(8) - (9)].c), pStrCat))){
	  yymsg(GERROR, "Unknown string option '%s[%d].%s'", (yyvsp[(3) - (9)].c), (int)(yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].c));
	  (yyval.c) = (char*)Malloc(sizeof(char));
	  (yyval.c)[0] = '\0';
	}
	else{
	  const char *str = pStrOpt((int)(yyvsp[(5) - (9)].d), GMSH_GET, NULL);
	  (yyval.c) = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy((yyval.c), str);
	}
      }
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 7824 "Gmsh.tab.cpp"
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


#line 3415 "Gmsh.y"


void DeleteSymbol(void *a, void *b)
{
  Symbol *s = (Symbol*)a;
  Free(s->Name);
  List_Delete(s->val);
}

int CompareSymbols (const void *a, const void *b)
{
  return(strcmp(((Symbol*)a)->Name, ((Symbol*)b)->Name));
}

void InitSymbols()
{
  if(Symbol_T){
    Tree_Action(Symbol_T, DeleteSymbol);
    Tree_Delete(Symbol_T);
  }
  Symbol_T = Tree_Create(sizeof(Symbol), CompareSymbols);
}

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

void yyerror(char *s)
{
  Msg(GERROR, "'%s', line %d : %s (%s)", gmsh_yyname, gmsh_yylineno - 1, s, gmsh_yytext);
  gmsh_yyerrorstate++;
}

void yymsg(int type, const char *fmt, ...)
{
  va_list args;
  char tmp[1024];

  va_start (args, fmt);
  vsprintf (tmp, fmt, args);
  va_end (args);

  Msg(type, "'%s', line %d : %s", gmsh_yyname, gmsh_yylineno - 1, tmp);

  if(type == GERROR) gmsh_yyerrorstate++;
}

