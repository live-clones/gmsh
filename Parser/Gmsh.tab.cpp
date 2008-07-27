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

// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "Message.h"
#include "MallocUtils.h"
#include "ListUtils.h"
#include "TreeUtils.h"
#include "Numeric.h"
#include "Context.h"
#include "GModel.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "Generator.h"
#include "Draw.h"
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
#if !defined(HAVE_NO_POST)
#include "PView.h"
#include "PViewDataList.h"
#include "PluginManager.h"
#endif

extern Context_T CTX;

// Global parser variables
char gmsh_yyname[256] = "";
int  gmsh_yyerrorstate = 0;
int  gmsh_yyviewindex = 0;
std::map<std::string, std::vector<double> > gmsh_yysymbols;

// Static parser variables (accessible only in this file)
#if !defined(HAVE_NO_POST)
static PViewDataList *ViewData;
#endif
static ExtrudeParams extr;
static gmshSurface *myGmshSurface = 0;
static List_T *ViewValueList = 0;
static double ViewCoord[100];
static int *ViewNumList = 0, ViewCoordIdx = 0;
#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0;
static fpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static char *LoopControlVariablesNameTab[MAX_RECUR_LOOPS];

void yyerror(char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
void FixRelativePath(const char *in, char *out);


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
#line 70 "Gmsh.y"
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
#line 427 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 440 "Gmsh.tab.cpp"

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
#define YYLAST   6253

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  143
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  350
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1241

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
     375,   383,   393,   403,   415,   425,   435,   437,   439,   440,
     446,   454,   463,   470,   478,   486,   494,   504,   512,   522,
     540,   548,   556,   568,   577,   586,   595,   605,   609,   614,
     625,   633,   641,   650,   659,   668,   676,   685,   691,   703,
     709,   719,   724,   734,   739,   741,   743,   744,   747,   754,
     761,   768,   775,   780,   787,   794,   798,   803,   809,   813,
     817,   822,   827,   831,   839,   847,   851,   859,   863,   866,
     869,   885,   888,   895,   904,   913,   924,   926,   929,   931,
     935,   940,   942,   948,   960,   974,   975,   983,   984,   998,
     999,  1015,  1016,  1023,  1032,  1041,  1050,  1063,  1076,  1089,
    1104,  1119,  1134,  1135,  1148,  1149,  1162,  1163,  1176,  1177,
    1194,  1195,  1212,  1213,  1230,  1231,  1250,  1251,  1270,  1271,
    1290,  1292,  1295,  1301,  1309,  1319,  1322,  1332,  1339,  1349,
    1359,  1368,  1378,  1387,  1396,  1403,  1408,  1415,  1426,  1437,
    1448,  1459,  1462,  1464,  1468,  1471,  1474,  1477,  1481,  1485,
    1489,  1493,  1497,  1501,  1505,  1509,  1513,  1517,  1521,  1525,
    1529,  1533,  1539,  1544,  1549,  1554,  1559,  1564,  1569,  1574,
    1579,  1584,  1589,  1596,  1601,  1606,  1611,  1616,  1621,  1626,
    1633,  1640,  1647,  1652,  1657,  1662,  1667,  1672,  1677,  1682,
    1687,  1692,  1697,  1702,  1709,  1714,  1719,  1724,  1729,  1734,
    1739,  1746,  1753,  1760,  1765,  1767,  1769,  1771,  1773,  1775,
    1777,  1779,  1781,  1787,  1792,  1797,  1800,  1806,  1810,  1817,
    1822,  1830,  1837,  1839,  1842,  1845,  1849,  1853,  1865,  1875,
    1883,  1891,  1893,  1897,  1899,  1901,  1904,  1908,  1913,  1919,
    1922,  1926,  1930,  1936,  1941,  1943,  1945,  1949,  1956,  1958,
    1960,  1964,  1968,  1978,  1986,  1988,  1994,  1998,  2005,  2007,
    2011,  2013,  2015,  2017,  2019,  2026,  2031,  2036,  2041,  2048,
    2055
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     144,     0,    -1,   145,    -1,     1,     6,    -1,    -1,   145,
     146,    -1,   149,    -1,   148,    -1,   167,    -1,   170,    -1,
     171,    -1,   174,    -1,   175,    -1,   176,    -1,   179,    -1,
     195,    -1,   196,    -1,   197,    -1,   178,    -1,   177,    -1,
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
     140,   205,   141,     6,    -1,    64,   133,     4,   134,   137,
       4,     7,   198,     6,    -1,    64,   133,     4,   134,   137,
       4,     7,   210,     6,    -1,   198,    -1,   210,    -1,    -1,
      95,    47,   140,   198,   141,    -1,    43,   133,   198,   134,
       7,   200,     6,    -1,    60,    43,   133,   168,   134,     7,
     203,     6,    -1,    52,    53,   203,     7,   198,     6,    -1,
      46,   133,   198,   134,     7,   203,     6,    -1,    50,   133,
     198,   134,     7,   203,     6,    -1,    44,   133,   198,   134,
       7,   203,     6,    -1,    44,   133,   198,   134,     7,   203,
      56,   200,     6,    -1,    45,   133,   198,   134,     7,   203,
       6,    -1,    45,   133,   198,   134,     7,   203,    56,   200,
       6,    -1,    54,   133,   198,   134,     7,   140,   198,   139,
     198,   139,     5,   139,     5,   139,     5,   141,     6,    -1,
      87,   133,   198,   134,     7,   203,     6,    -1,    88,   133,
     198,   134,     7,   203,     6,    -1,    89,   133,   198,   134,
       7,   203,    91,   203,    90,   198,     6,    -1,    46,    71,
     133,   198,   134,     7,   203,     6,    -1,    60,    46,   133,
     168,   134,     7,   203,     6,    -1,    56,    49,   133,   198,
     134,     7,   203,     6,    -1,    57,    49,   133,   198,   134,
       7,   203,   169,     6,    -1,    12,    13,     6,    -1,    13,
      49,   198,     6,    -1,    54,    49,   133,   198,   134,     7,
       5,     5,     5,     6,    -1,    47,   133,   198,   134,     7,
     203,     6,    -1,    48,   133,   198,   134,     7,   203,     6,
      -1,    49,    71,   133,   198,   134,     7,   203,     6,    -1,
      60,    49,   133,   168,   134,     7,   203,     6,    -1,    59,
      51,   133,   198,   134,     7,   203,     6,    -1,    51,   133,
     198,   134,     7,   203,     6,    -1,    60,    51,   133,   168,
     134,     7,   203,     6,    -1,    66,   200,   140,   172,   141,
      -1,    65,   140,   200,   139,   200,   139,   198,   141,   140,
     172,   141,    -1,    67,   200,   140,   172,   141,    -1,    68,
     140,   200,   139,   198,   141,   140,   172,   141,    -1,    70,
     140,   172,   141,    -1,    76,    46,   140,   205,   141,    49,
     140,   198,   141,    -1,    77,   140,   172,   141,    -1,   173,
      -1,   171,    -1,    -1,   173,   170,    -1,   173,    43,   140,
     205,   141,     6,    -1,   173,    46,   140,   205,   141,     6,
      -1,   173,    49,   140,   205,   141,     6,    -1,   173,    51,
     140,   205,   141,     6,    -1,    74,   140,   173,   141,    -1,
      74,   100,   135,   198,   136,     6,    -1,    74,     4,   135,
     198,   136,     6,    -1,    74,     4,     6,    -1,    74,     4,
       4,     6,    -1,    92,   206,   140,   173,   141,    -1,   104,
     209,     6,    -1,   105,   209,     6,    -1,   104,   140,   173,
     141,    -1,   105,   140,   173,   141,    -1,     4,   210,     6,
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
      98,    -1,    69,   200,   140,   173,   141,    -1,    69,   140,
     200,   139,   200,   139,   198,   141,   140,   173,   141,    -1,
      69,   140,   200,   139,   200,   139,   200,   139,   198,   141,
     140,   173,   141,    -1,    -1,    69,   200,   140,   173,   180,
     193,   141,    -1,    -1,    69,   140,   200,   139,   200,   139,
     198,   141,   140,   173,   181,   193,   141,    -1,    -1,    69,
     140,   200,   139,   200,   139,   200,   139,   198,   141,   140,
     173,   182,   193,   141,    -1,    -1,    69,   140,   173,   183,
     193,   141,    -1,    69,    43,   140,   198,   139,   200,   141,
       6,    -1,    69,    46,   140,   198,   139,   200,   141,     6,
      -1,    69,    49,   140,   198,   139,   200,   141,     6,    -1,
      69,    43,   140,   198,   139,   200,   139,   200,   139,   198,
     141,     6,    -1,    69,    46,   140,   198,   139,   200,   139,
     200,   139,   198,   141,     6,    -1,    69,    49,   140,   198,
     139,   200,   139,   200,   139,   198,   141,     6,    -1,    69,
      43,   140,   198,   139,   200,   139,   200,   139,   200,   139,
     198,   141,     6,    -1,    69,    46,   140,   198,   139,   200,
     139,   200,   139,   200,   139,   198,   141,     6,    -1,    69,
      49,   140,   198,   139,   200,   139,   200,   139,   200,   139,
     198,   141,     6,    -1,    -1,    69,    43,   140,   198,   139,
     200,   141,   184,   140,   193,   141,     6,    -1,    -1,    69,
      46,   140,   198,   139,   200,   141,   185,   140,   193,   141,
       6,    -1,    -1,    69,    49,   140,   198,   139,   200,   141,
     186,   140,   193,   141,     6,    -1,    -1,    69,    43,   140,
     198,   139,   200,   139,   200,   139,   198,   141,   187,   140,
     193,   141,     6,    -1,    -1,    69,    46,   140,   198,   139,
     200,   139,   200,   139,   198,   141,   188,   140,   193,   141,
       6,    -1,    -1,    69,    49,   140,   198,   139,   200,   139,
     200,   139,   198,   141,   189,   140,   193,   141,     6,    -1,
      -1,    69,    43,   140,   198,   139,   200,   139,   200,   139,
     200,   139,   198,   141,   190,   140,   193,   141,     6,    -1,
      -1,    69,    46,   140,   198,   139,   200,   139,   200,   139,
     200,   139,   198,   141,   191,   140,   193,   141,     6,    -1,
      -1,    69,    49,   140,   198,   139,   200,   139,   200,   139,
     200,   139,   198,   141,   192,   140,   193,   141,     6,    -1,
     194,    -1,   193,   194,    -1,    78,   140,   198,   141,     6,
      -1,    78,   140,   203,   139,   203,   141,     6,    -1,    78,
     140,   203,   139,   203,   139,   203,   141,     6,    -1,    72,
       6,    -1,    79,   133,   198,   134,     7,   203,    61,   198,
       6,    -1,    58,    46,   203,     7,   198,     6,    -1,    58,
      46,   203,     7,   198,    61,    63,   198,     6,    -1,    58,
      46,   203,     7,   198,    61,    62,   198,     6,    -1,    58,
      49,   140,   198,   141,     7,   203,     6,    -1,    58,    49,
     140,   198,   141,     7,   203,     4,     6,    -1,    55,    49,
     140,   198,   141,     7,   203,     6,    -1,    58,    51,   140,
     198,   141,     7,   203,     6,    -1,    72,    49,   203,     7,
     198,     6,    -1,    72,    49,   203,     6,    -1,    73,    49,
     203,     7,   198,     6,    -1,    43,   140,   205,   141,    95,
      49,   140,   198,   141,     6,    -1,    46,   140,   205,   141,
      95,    49,   140,   198,   141,     6,    -1,    46,   140,   205,
     141,    95,    51,   140,   198,   141,     6,    -1,    49,   140,
     205,   141,    95,    51,   140,   198,   141,     6,    -1,    75,
       6,    -1,   199,    -1,   133,   198,   134,    -1,   124,   198,
      -1,   123,   198,    -1,   128,   198,    -1,   198,   124,   198,
      -1,   198,   123,   198,    -1,   198,   125,   198,    -1,   198,
     126,   198,    -1,   198,   127,   198,    -1,   198,   132,   198,
      -1,   198,   119,   198,    -1,   198,   120,   198,    -1,   198,
     122,   198,    -1,   198,   121,   198,    -1,   198,   118,   198,
      -1,   198,   117,   198,    -1,   198,   116,   198,    -1,   198,
     115,   198,    -1,   198,   114,   198,     8,   198,    -1,    14,
     133,   198,   134,    -1,    15,   133,   198,   134,    -1,    16,
     133,   198,   134,    -1,    17,   133,   198,   134,    -1,    18,
     133,   198,   134,    -1,    19,   133,   198,   134,    -1,    20,
     133,   198,   134,    -1,    21,   133,   198,   134,    -1,    22,
     133,   198,   134,    -1,    24,   133,   198,   134,    -1,    25,
     133,   198,   139,   198,   134,    -1,    26,   133,   198,   134,
      -1,    27,   133,   198,   134,    -1,    28,   133,   198,   134,
      -1,    29,   133,   198,   134,    -1,    30,   133,   198,   134,
      -1,    31,   133,   198,   134,    -1,    32,   133,   198,   139,
     198,   134,    -1,    33,   133,   198,   139,   198,   134,    -1,
      34,   133,   198,   139,   198,   134,    -1,    23,   133,   198,
     134,    -1,    14,   135,   198,   136,    -1,    15,   135,   198,
     136,    -1,    16,   135,   198,   136,    -1,    17,   135,   198,
     136,    -1,    18,   135,   198,   136,    -1,    19,   135,   198,
     136,    -1,    20,   135,   198,   136,    -1,    21,   135,   198,
     136,    -1,    22,   135,   198,   136,    -1,    24,   135,   198,
     136,    -1,    25,   135,   198,   139,   198,   136,    -1,    26,
     135,   198,   136,    -1,    27,   135,   198,   136,    -1,    28,
     135,   198,   136,    -1,    29,   135,   198,   136,    -1,    30,
     135,   198,   136,    -1,    31,   135,   198,   136,    -1,    32,
     135,   198,   139,   198,   136,    -1,    33,   135,   198,   139,
     198,   136,    -1,    34,   135,   198,   139,   198,   136,    -1,
      23,   135,   198,   136,    -1,     3,    -1,     9,    -1,    10,
      -1,    11,    -1,   107,    -1,   108,    -1,   109,    -1,     4,
      -1,     4,   142,   140,   198,   141,    -1,     4,   135,   198,
     136,    -1,   138,     4,   135,   136,    -1,     4,   166,    -1,
       4,   135,   198,   136,   166,    -1,     4,   137,     4,    -1,
       4,   135,   198,   136,   137,     4,    -1,     4,   137,     4,
     166,    -1,     4,   135,   198,   136,   137,     4,   166,    -1,
     106,   133,     5,   139,   198,   134,    -1,   201,    -1,   124,
     200,    -1,   123,   200,    -1,   200,   124,   200,    -1,   200,
     123,   200,    -1,   140,   198,   139,   198,   139,   198,   139,
     198,   139,   198,   141,    -1,   140,   198,   139,   198,   139,
     198,   139,   198,   141,    -1,   140,   198,   139,   198,   139,
     198,   141,    -1,   133,   198,   139,   198,   139,   198,   134,
      -1,   203,    -1,   202,   139,   203,    -1,   198,    -1,   204,
      -1,   140,   141,    -1,   140,   205,   141,    -1,   124,   140,
     205,   141,    -1,   198,   125,   140,   205,   141,    -1,   124,
     204,    -1,   198,   125,   204,    -1,   198,     8,   198,    -1,
     198,     8,   198,     8,   198,    -1,    43,   140,   198,   141,
      -1,   171,    -1,   179,    -1,     4,   135,   136,    -1,     4,
     135,   140,   205,   141,   136,    -1,   198,    -1,   204,    -1,
     205,   139,   198,    -1,   205,   139,   204,    -1,   140,   198,
     139,   198,   139,   198,   139,   198,   141,    -1,   140,   198,
     139,   198,   139,   198,   141,    -1,     4,    -1,     4,   137,
      92,   137,     4,    -1,   140,   208,   141,    -1,     4,   135,
     198,   136,   137,    93,    -1,   206,    -1,   208,   139,   206,
      -1,   210,    -1,     4,    -1,     5,    -1,    42,    -1,    37,
     133,   209,   139,   209,   134,    -1,    38,   133,   209,   134,
      -1,    39,   133,   209,   134,    -1,    36,   133,   209,   134,
      -1,    36,   133,   209,   139,   205,   134,    -1,    36,   133,
       4,   137,     4,   134,    -1,    36,   133,     4,   135,   198,
     136,   137,     4,   134,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   136,   136,   137,   142,   144,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     165,   169,   176,   181,   196,   209,   238,   252,   263,   278,
     283,   284,   285,   286,   287,   291,   293,   298,   300,   306,
     452,   305,   470,   477,   488,   487,   506,   513,   524,   523,
     541,   556,   576,   575,   589,   590,   591,   592,   593,   597,
     598,   605,   627,   654,   694,   703,   711,   719,   731,   738,
     743,   751,   769,   787,   796,   808,   813,   821,   841,   864,
     871,   877,   897,   918,   944,   956,   973,   977,   987,   990,
    1008,  1030,  1046,  1068,  1086,  1104,  1122,  1148,  1166,  1192,
    1212,  1230,  1248,  1274,  1291,  1310,  1328,  1367,  1373,  1379,
    1386,  1411,  1436,  1452,  1472,  1490,  1507,  1528,  1533,  1538,
    1543,  1548,  1559,  1565,  1574,  1575,  1580,  1583,  1587,  1610,
    1633,  1656,  1684,  1693,  1697,  1712,  1733,  1750,  1764,  1770,
    1776,  1785,  1799,  1847,  1865,  1880,  1899,  1911,  1935,  1939,
    1944,  1949,  1961,  1978,  1995,  2014,  2033,  2061,  2069,  2075,
    2082,  2086,  2095,  2103,  2111,  2120,  2119,  2132,  2131,  2144,
    2143,  2156,  2155,  2168,  2175,  2182,  2189,  2196,  2203,  2210,
    2217,  2224,  2232,  2231,  2243,  2242,  2254,  2253,  2265,  2264,
    2276,  2275,  2287,  2286,  2298,  2297,  2309,  2308,  2320,  2319,
    2334,  2337,  2343,  2352,  2372,  2395,  2399,  2423,  2441,  2459,
    2477,  2506,  2541,  2546,  2573,  2587,  2600,  2617,  2623,  2629,
    2632,  2641,  2651,  2652,  2653,  2654,  2655,  2656,  2657,  2658,
    2659,  2666,  2667,  2668,  2669,  2670,  2671,  2672,  2673,  2674,
    2675,  2676,  2677,  2678,  2679,  2680,  2681,  2682,  2683,  2684,
    2685,  2686,  2687,  2688,  2689,  2690,  2691,  2692,  2693,  2694,
    2695,  2696,  2697,  2699,  2700,  2701,  2702,  2703,  2704,  2705,
    2706,  2707,  2708,  2709,  2710,  2711,  2712,  2713,  2714,  2715,
    2716,  2717,  2718,  2719,  2728,  2729,  2730,  2731,  2732,  2733,
    2734,  2738,  2751,  2763,  2778,  2788,  2798,  2816,  2821,  2826,
    2836,  2846,  2854,  2858,  2862,  2866,  2870,  2877,  2881,  2885,
    2889,  2896,  2901,  2908,  2913,  2917,  2922,  2926,  2934,  2945,
    2953,  2961,  2967,  2978,  2998,  3008,  3018,  3028,  3048,  3053,
    3057,  3061,  3073,  3077,  3089,  3096,  3106,  3110,  3125,  3130,
    3137,  3141,  3148,  3152,  3160,  3168,  3182,  3196,  3200,  3219,
    3227
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
  "RuledSurfaceOptions", "Shape", "Transform", "MultipleShape",
  "ListOfShapes", "Delete", "Colorify", "Visibility", "Command", "Loop",
  "Extrude", "@6", "@7", "@8", "@9", "@10", "@11", "@12", "@13", "@14",
  "@15", "@16", "@17", "@18", "ExtrudeParameters", "ExtrudeParameter",
  "Transfinite", "Embedding", "Coherence", "FExpr", "FExpr_Single",
  "VExpr", "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
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
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   171,   171,   171,
     171,   171,   171,   171,   172,   172,   173,   173,   173,   173,
     173,   173,   174,   174,   174,   174,   174,   175,   176,   176,
     176,   176,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   179,   179,   179,   180,   179,   181,   179,   182,
     179,   183,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   184,   179,   185,   179,   186,   179,   187,   179,
     188,   179,   189,   179,   190,   179,   191,   179,   192,   179,
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
       7,     9,     9,    11,     9,     9,     1,     1,     0,     5,
       7,     8,     6,     7,     7,     7,     9,     7,     9,    17,
       7,     7,    11,     8,     8,     8,     9,     3,     4,    10,
       7,     7,     8,     8,     8,     7,     8,     5,    11,     5,
       9,     4,     9,     4,     1,     1,     0,     2,     6,     6,
       6,     6,     4,     6,     6,     3,     4,     5,     3,     3,
       4,     4,     3,     7,     7,     3,     7,     3,     2,     2,
      15,     2,     6,     8,     8,    10,     1,     2,     1,     3,
       4,     1,     5,    11,    13,     0,     7,     0,    13,     0,
      15,     0,     6,     8,     8,     8,    12,    12,    12,    14,
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
     156,     0,   161,     0,     0,   158,     0,     0,     0,     0,
       5,     7,     6,     8,     9,    10,    11,    12,    13,    19,
      18,    14,    15,    16,    17,   284,   291,   342,    54,   285,
     286,   287,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   343,     0,     0,
     288,   289,   290,    58,    57,    56,    55,     0,     0,     0,
      60,    59,     0,     0,     0,     0,     0,     0,     0,   222,
       0,     0,     0,     0,   149,     0,   151,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,     0,     0,     0,     0,     0,   126,     0,   126,
       0,     0,     0,     0,   126,   221,     0,   126,     0,     0,
       0,     0,     0,     0,   334,     0,     0,     0,     0,     0,
     148,     0,     0,   157,   341,   342,   126,     0,   340,   126,
       0,     0,     0,     0,     0,   295,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,   225,   224,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   107,     0,     0,
       0,     0,   291,     0,     0,   324,   325,   328,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   313,     0,   314,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   304,   303,     0,     0,     0,     0,   126,   126,     0,
       0,     0,     0,     0,     0,     0,   171,     0,   126,   125,
       0,   124,     0,     0,     0,   135,     0,     0,     0,     0,
       0,     0,     0,   147,     0,     0,     0,     0,     0,   126,
       0,     0,     0,     0,   159,     0,   138,     0,   139,     0,
       0,   297,     0,     0,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   341,     0,     0,
       0,     0,     0,     0,     0,   223,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,    61,     0,   240,   239,
     238,   237,   233,   234,   236,   235,   228,   227,   229,   230,
     231,   232,   108,     0,     0,     0,     0,     0,     0,   224,
     319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   315,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,     0,     0,     0,     0,     0,     0,     0,
     306,   305,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,   165,   121,   215,     0,
       0,   136,     0,     0,   132,     0,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   160,     0,   140,
     141,     0,   293,   299,     0,    39,     0,     0,     0,    52,
       0,    30,    31,    32,    33,    34,   242,   263,   243,   264,
     244,   265,   245,   266,   246,   267,   247,   268,   248,   269,
     249,   270,   250,   271,   262,   283,   251,   272,     0,     0,
     253,   274,   254,   275,   255,   276,   256,   277,   257,   278,
     258,   279,     0,     0,     0,     0,     0,     0,     0,     0,
     347,     0,     0,   345,   346,    79,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,    73,     0,     0,
       0,     0,   294,     0,    22,    20,     0,     0,     0,     0,
     326,     0,     0,   321,   229,   320,   330,   331,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   316,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   200,     0,   162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,     0,     0,     0,     0,   296,     0,
     292,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     293,    64,    65,     0,     0,     0,     0,     0,    67,    69,
      71,     0,     0,   338,     0,    77,   241,    21,     0,     0,
       0,     0,     0,   323,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   317,     0,
      92,     0,     0,     0,     0,     0,   207,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,     0,     0,
     172,   201,     0,     0,   214,   216,   134,   133,     0,    27,
      28,     0,     0,     0,   335,     0,     0,     0,   152,     0,
       0,   144,   298,   143,     0,     0,     0,     0,   311,     0,
     252,   273,   259,   280,   260,   281,   261,   282,     0,   349,
     348,   344,   301,     0,    54,     0,     0,     0,     0,    62,
       0,     0,     0,   336,    23,    24,     0,     0,    90,     0,
     322,     0,    95,     0,    97,     0,     0,    93,     0,     0,
     110,   111,     0,     0,    94,   115,   318,     0,     0,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,     0,     0,     0,     0,   126,     0,   182,     0,
     184,     0,   186,     0,     0,     0,     0,   313,     0,     0,
       0,     0,   166,     0,   100,   101,     0,     0,     0,     0,
      80,     0,   300,     0,    35,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,    74,     0,     0,    75,     0,
     339,     0,     0,   327,     0,     0,     0,   103,     0,     0,
     112,     0,     0,     0,   212,   105,     0,     0,     0,     0,
       0,   210,   213,   114,    91,   104,   113,   116,     0,     0,
       0,   310,     0,   309,     0,     0,   173,     0,     0,   174,
       0,     0,   175,     0,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,   333,     0,   154,   153,
       0,     0,     0,    40,     0,     0,     0,   312,     0,     0,
       0,     0,    63,    70,    72,     0,    78,     0,    25,     0,
       0,    96,    98,     0,     0,     0,     0,     0,     0,   106,
     209,   208,   211,    84,    85,   126,     0,   120,     0,     0,
       0,     0,     0,     0,   202,     0,     0,   126,     0,   122,
       0,     0,     0,     0,    81,    82,     0,    36,     0,     0,
       0,    38,    53,   350,     0,   337,     0,   217,   218,   219,
     220,   109,     0,     0,     0,     0,   308,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
       0,     0,   332,   155,     0,     0,     0,     0,     0,    76,
       0,     0,     0,   118,     0,   188,     0,     0,   190,     0,
       0,   192,     0,     0,     0,   203,     0,   163,     0,   126,
     102,    83,     0,    44,     0,    50,     0,     0,     0,    89,
     307,   176,     0,     0,   183,   177,     0,     0,   185,   178,
       0,     0,   187,     0,     0,     0,   169,     0,     0,     0,
       0,     0,     0,     0,   194,     0,   196,     0,   198,   204,
     206,   168,   164,     0,    41,     0,    48,     0,     0,     0,
       0,   179,     0,     0,   180,     0,     0,   181,     0,     0,
       0,    42,     0,     0,   150,     0,     0,     0,     0,     0,
       0,     0,   170,     0,     0,     0,     0,     0,   189,     0,
     191,     0,   193,     0,    43,    45,     0,    46,     0,    99,
       0,     0,     0,     0,     0,    51,   195,   197,   199,    47,
      49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    60,   646,    61,    62,   393,   943,   949,
     571,   731,  1076,  1200,   572,  1168,  1226,   573,  1202,   574,
     575,   735,   126,   215,    63,   510,   977,   533,   305,   360,
     361,    66,    67,    68,    69,    70,   306,   708,  1138,  1183,
     534,   997,  1000,  1003,  1152,  1156,  1160,  1192,  1195,  1198,
     704,   705,    72,    73,    74,   323,   129,   341,   171,   847,
     848,   325,   309,   196,   641,   764,   207,   208
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1024
static const yytype_int16 yypact[] =
{
    2786,    25,    19,  2864, -1024, -1024,  2033,    22,    -5,   -71,
      26,    65,    50,   -12,     4,   -32,    63,   123,   -55,   126,
     138,   118,   -39,   130,   258,   288,   248,   269,   676,   226,
     244,   -37,   -37,   254,   504,   299,   317,   349,    20,   428,
     365,   303,   442,   447,   457,   335,   339,   372,    13,     9,
   -1024,   388, -1024,   475,   399, -1024,   536,   539,    10,    17,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024,    21,   408,   554, -1024,
   -1024, -1024,   134,   222,   271,   275,   283,   294,   393,   436,
     444,   450,   466,   503,   508,   538,   570,   609,   624,   628,
     636,   639,   640,   432,   445,   470,   485, -1024,   616,   493,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024,  2245,  2245,  2245,
   -1024, -1024,  2245,  1671,    34,   626,  2245,   649,  1152, -1024,
     659,   672,  2245,   637, -1024,  2245, -1024,  2245,  2082,  2245,
    2245,   523,  2245,  2082,  2245,  2245,   527,  2082,  2245,  2245,
    1324,   533,  2245,   530,   566,   571,  1324,   577,   586,   598,
     631,   635,   657,   673,   803,   -37,   -37,   -37,  2245,  2245,
     -40, -1024,    46,   -37,   681,   682,   685,  1901,   152,   743,
    1324,  1324,    24,   677, -1024, -1024,   707,   743,   694,   728,
     810,  2245,  2245,  2245,   734,  2245,   773,   787,  2245,  2245,
   -1024,  2245,   881, -1024, -1024, -1024, -1024,   890, -1024, -1024,
     908,   781,  2245,   913,   778, -1024, -1024,   914,  2245,  2245,
    2245,  2245,  2245,  2245,  2245,  2245,  2245,  2245,  2245,  2245,
    2245,  2245,  2245,  2245,  2245,  2245,  2245,  2245,  2245,  2245,
    2245,  2245,  2245,  2245,  2245,  2245,  2245,  2245,  2245,  2245,
    2245,  2245,  2245,  2245,  2245,  2245,  2245,  2245,  2245,  2245,
      38,   615,   615,   615,  2245,   917,   532,   791,   791,   791,
    5153,    16,  2082,  4417,   302,   782,   920,   793,  1844, -1024,
   -1024,  2245,  2245,  2245,  2245,  2245,  2245,  2245,  2245,  2245,
    2245,  2245,  2245,  2245,  2245,  2245, -1024, -1024,  2167,   -74,
    3663,  5174,   625,   790,  2082, -1024, -1024,  2556, -1024,   217,
    5195,  5216,  2245,  5237,   348,  5258,  5279,  2245,   371,  5300,
    5321,  1470,  1188,  2575,   924, -1024,  2245,  5342,  2245,  2245,
    2245,   925,  2245,  2245,  2245,  2208,  2208,  2208,  2208,   799,
     -73, -1024, -1024,  3689,  3715,   -37,   -37,   743,   743,   182,
    2245,  2245,  2245,  1901,  1901,  2245,  2930,   188, -1024, -1024,
     794,  2930,    91,   927,   930, -1024,  2245,  2245,   664,  2082,
     797,  2245,  2245, -1024,  5363,  5384,  5405,   847,  3741, -1024,
     800,  2594,  5426,  4440, -1024,   689, -1024,   935, -1024,  2245,
    4463,    82,  2245,     8, -1024,  5447,  4486,  5468,  4509,  5489,
    4532,  5510,  4555,  5531,  4578,  5552,  4601,  5573,  4624,  5594,
    4647,  5615,  4670,  5636,  4693,  5657,  4716,  3767,  3793,  5678,
    4739,  5699,  4762,  5720,  4785,  5741,  4808,  5762,  4831,  5783,
    4854,  3819,  3845,  3871,  3897,  3923,  3949,   563,   -23,   804,
     811,   812,  2186,   813,  2245, -1024,  1324,  1324,   650,   289,
     554,  2245,   943,   946,    14,   815, -1024,  2613,   733,   880,
     660,   660,   711,   711,   711,   711,   405,   405,   791,   791,
     791,   791, -1024,    35,  2082,  2245,   947,  1866,  2245,   791,
   -1024,  2245,  2082,  2082,   858,   949,   950,  5804,   952,   865,
     954,   955,  5825,   868,   957,   958,  2082, -1024,   654,  1602,
    2245,  5846,   960,  2687,  5867,  5888,  2245,  2965,  2993,  5909,
     834,  2293, -1024,   836,   837,   838,   839,   -37,  2245,  2245,
   -1024, -1024,   832,   833,  2245,  3975,  4001,  4027,  3637,    60,
     -31,   -51,   170, -1024,   311,   -37,  1366, -1024, -1024,  2245,
    2245, -1024,  4877,  4900, -1024,   655, -1024,  4923,  4946,   968,
     970,   986,   859,  2245,  1508,  2245,  2245, -1024,    30, -1024,
   -1024,  4969,    68, -1024,  3021, -1024,   876,   877,   874, -1024,
    1009, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,  2245,  2245,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024,  2245,  2245,  2245,  2245,  2245,  2245,  2245,  1013,
   -1024,  2082,   615, -1024, -1024, -1024,  2245,  4992,  1012,  1015,
     883, -1024,    84,  2245,  1020,  1021,  2313, -1024,  1022,   893,
      13,  1024, -1024,  2245, -1024,   911,   615,   -22,  4053,   -37,
   -1024,  2082,  3049,  2638,   791, -1024,  2556, -1024,   983,  1324,
    1324,  1026,  1324,   749,  1324,  1324,  1027,   984,  1324,  1324,
     687, -1024,  2082,  2332,  1031,   900,  1036,  1037,  1040,  2274,
    1041,  1042,  1043,  1044,  1046,  1048,  1050,  1055,   221,  4079,
    4105, -1024, -1024,  3077,   -37,   -37,   -37,  2082,  2082,  2082,
    2082,  1056,   921,   931,   -11, -1024,   370, -1024,   311,  2351,
    2370,  1057,  1059,  1018,  1062,  1063,  1324,  1324,  1324,  1066,
    4131, -1024,  2657,   982,  1067,  1068,  1071,  1069, -1024,  1072,
   -1024,   948,  2245,  2245,  1324,   939, -1024,  5930,  5015,  5951,
    5038,  5972,  5061,  5993,  5084,  5107,   951,   131,   953,  6014,
     430, -1024, -1024,   347,   354,   973,  1073,  2396, -1024, -1024,
   -1024,    13,  2245, -1024,   700, -1024,  2293, -1024,  1077,    52,
    2245,     1,   705, -1024,  2245,   944,    23,    39,  1324,  1080,
     972,   977,  1082,  1084,  1324,   978,  1086,  1113, -1024,   723,
   -1024,  1115,  2245,  1324,  1324,  1324, -1024,   253,  1324,  1324,
    1324,  1324,  1324,  1324,  1324,   494,  2245,  2245,  2245,   981,
     367,   400,   431,   727,   731,   739,   742, -1024,  1324,  2245,
   -1024, -1024,  1901,    -9, -1024, -1024, -1024, -1024,   987, -1024,
   -1024,  1117,  1118,  1038, -1024,  2245,  2245,  2245, -1024,  1124,
    1126, -1024,    82, -1024,  2245,  4157,  4183,   747, -1024,  2245,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,   994, -1024,
   -1024, -1024, -1024,  1324,   554,  2245,  1128,  1131,    14, -1024,
    1130,  5130,    13, -1024, -1024, -1024,   615,  4209, -1024,  1001,
    2293,  2245, -1024,   -37, -1024,   -37,  1132, -1024,  2245,  2245,
   -1024, -1024,  1133,  2245, -1024, -1024, -1024,  1136,  4235,  1138,
    1139,  1047,  2245,  2245,   795,  1140,  1142,  1144,  1146,  1147,
    1151, -1024,  2208,  3105,  6035,  2881,   743,   -37,  1153,   -37,
    1154,   -37,  1156,  1157,  1158,  1159,  1160,   255,  1028,  6056,
    3133,   458, -1024,  2245, -1024, -1024,  1324,  2909,   565,  6077,
   -1024,  1734, -1024,   159,  2293,  2245,  2245,  1324,  1029,   751,
    2293,  1164,  1167,  1176,  2415, -1024,  1177,  1179, -1024,  1049,
   -1024,  1181,  2245, -1024,  3161,    51,    58, -1024,  3189,  3217,
   -1024,  3245,  1178,  2245, -1024, -1024,  1141,  1183,  2435,  2454,
    1184, -1024, -1024, -1024, -1024, -1024, -1024, -1024,  2473,  1187,
    1054, -1024,  2245, -1024,  1060,   465, -1024,  1083,   482, -1024,
    1085,   492, -1024,  1087, -1024, -1024, -1024, -1024,  1194,  1324,
    1217,  1088,  2245,  3273,  1143,  2245, -1024,  2245, -1024, -1024,
    2082,  2492,  1220, -1024,  2245,  4261,  4287, -1024,  1324,  2245,
    1223,  1096, -1024, -1024, -1024,    13, -1024,  1145, -1024,  4313,
    1226, -1024, -1024,  1228,  1229,  1230,  1231,  4339,  1099, -1024,
   -1024, -1024, -1024, -1024, -1024,   743,  2937, -1024,  1901,   311,
    1901,   311,  1901,   311, -1024,   752,  1324, -1024,  3301, -1024,
    2245,  3329,  3357,   756, -1024, -1024,  1101,  2293,  2245,  2245,
     761,  2293, -1024, -1024,  1236, -1024,  2245, -1024, -1024, -1024,
   -1024, -1024,  1238,  2245,  1103,  2245, -1024,  3385,   501,   194,
    3413,   522,   223,  3441,   525,   264,  1324,  1239,  1185,  1772,
    1107,  2518, -1024, -1024,  1242,  2245,  6098,  4365,    28, -1024,
    4391,  1110,  3469, -1024,  3497,  1244,  2245,  1245,  1246,  2245,
    1253,  1254,  2245,  1255,  1121, -1024,  2245, -1024,   311, -1024,
   -1024, -1024,   762, -1024,  2245, -1024,  1324,  2245,  1258, -1024,
   -1024, -1024,  1149,  3525, -1024, -1024,  1161,  3553, -1024, -1024,
    1162,  3581, -1024,  1274,  2537,   314,  1894,  1275,  1163,  6119,
     765,  3609,  1148,   311,  1276,   311,  1277,   311,  1279, -1024,
   -1024, -1024, -1024,   311, -1024,   615, -1024,  1165,  1280,  1286,
     345, -1024,  1166,   358, -1024,  1168,   363, -1024,  1169,   366,
     766, -1024,  1170,  1324, -1024,  1173,  1287,   311,  1292,   311,
    1293,   311, -1024,   615,  1294,   615,   770,  1298, -1024,   384,
   -1024,   397, -1024,   439, -1024, -1024,   771, -1024,  1301, -1024,
    1309,  1311,  1312,   615,  1313, -1024, -1024, -1024, -1024, -1024,
   -1024
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1024, -1024, -1024, -1024,   551, -1024, -1024, -1024, -1024,   207,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024,  -271,     0, -1024,  -127, -1024,  1320,     5,  -186,
    -173, -1024, -1024, -1024, -1024, -1024,  1322, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
    -609,  -677, -1024, -1024, -1024,    -4, -1024,   230, -1024, -1023,
     377,   176,   -65,  -614,   462, -1024,   -59,     3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     210,   370,   128,   451,   356,  1080,   127,   878,    65,   130,
     151,   368,   565,   197,   204,   205,   146,   194,   639,     5,
     146,   204,   205,   446,   182,   211,   763,   821,   364,   882,
     365,     4,   134,   385,  1145,   131,   387,   724,   274,   141,
     141,   644,   437,   205,   132,   884,   103,   104,   105,   106,
     345,   346,   107,   103,   104,   105,   106,  1041,   875,   107,
     473,   701,   133,   701,  1042,   474,   517,   702,   703,   702,
     703,   136,   204,   205,   103,   104,   105,   106,   314,   883,
     107,   217,   318,   345,   346,   147,   166,   167,   754,   699,
     566,   567,   568,   569,   152,   885,   168,   538,   539,   823,
     347,   142,   142,   169,   103,   104,   105,   106,   143,   698,
     107,   620,   769,   267,   268,   269,   621,   483,   270,   273,
     183,   139,   278,  1170,   345,   346,   275,   276,   298,   447,
     820,   300,   932,   301,   307,   310,   311,   140,   313,   307,
     315,   316,   198,   307,   319,   320,   821,   870,   327,   570,
     206,   120,   121,   195,   640,   645,   212,   209,   213,   366,
     184,   522,   523,   214,   343,   344,   135,   725,  1146,   345,
     346,   150,   645,   344,   345,   346,   755,   756,   633,   153,
    1216,   345,   346,   137,   359,   536,   348,   374,   375,   376,
     138,   378,   359,   137,   381,   382,   144,   383,   120,   121,
     697,   438,   439,   440,   441,   727,   554,   448,   390,   513,
     514,   515,   120,   121,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   145,   498,   960,   148,
     442,   170,   172,   481,   178,   860,   701,   218,   307,   219,
     483,   149,   702,   703,   452,   345,   346,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   358,  1023,   156,   701,   631,   157,  1024,   158,
     479,   702,   703,   149,   545,   345,   346,   154,   487,   450,
     700,   345,   346,   492,   308,   902,   903,   479,   307,   308,
     159,   524,   501,   308,   503,   504,   505,   535,   507,   508,
     509,   511,   511,   511,   511,  1127,   701,   155,   512,   512,
     512,   512,   702,   703,   345,   346,   525,   526,   527,   267,
     268,   528,   359,   359,   631,   220,   483,   221,   484,   164,
     806,   864,   542,   543,  1130,   307,   180,   547,   548,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     499,   293,   294,   701,   165,   561,   701,   295,   564,   702,
     703,   563,   702,   703,   173,   340,  1008,   342,   181,   113,
     114,   115,   116,   349,   222,  1133,   223,   357,   224,   647,
     225,   186,   113,   114,   115,   116,   226,   701,   227,   120,
     121,  1084,   821,   702,   703,   821,   632,   228,   821,   229,
     701,   670,   120,   121,   185,   701,   702,   703,   701,   179,
     627,   702,   703,   187,   702,   703,   188,   636,   308,   634,
    1099,   189,  1102,   635,  1105,  1181,   701,   113,   114,   115,
     116,   190,   702,   703,   113,   114,   115,   116,   191,   701,
     307,   648,   192,   627,   652,   702,   703,   653,   654,   656,
     480,   200,   863,   865,   120,   121,  1206,   483,   821,   489,
     345,   346,   307,   345,   346,   654,   673,   480,   308,  1208,
     911,   912,   679,   729,  1210,   193,   917,  1212,   918,   822,
     483,   701,   493,   821,   689,   690,   821,   702,   703,   821,
     693,   199,   821,   345,   346,  1230,   230,   324,   231,  1165,
     292,   293,   294,   331,   201,   709,   710,   295,  1231,   919,
     202,   920,   821,   203,   821,   308,   821,   174,   216,   720,
     175,   722,   723,   176,   345,   346,   747,   362,   363,   205,
     120,   121,   728,   748,  1190,   260,  1193,   727,  1196,   232,
     921,   233,   922,  1017,  1199,   520,   521,   234,   261,   235,
    1232,   345,   346,   236,   342,   237,   772,   768,   345,   346,
     103,   104,   105,   106,   737,   738,   107,  1012,  1219,   238,
    1221,   239,  1223,   262,  1058,   345,   346,   789,   739,   740,
     741,   742,   743,   744,   745,   345,   346,   307,   263,   204,
     205,  1060,   749,   264,   345,   346,   265,   166,   167,   757,
     277,  1062,   813,   814,   815,   816,   240,   168,   241,   766,
    1126,   242,   299,   243,   177,   345,   346,   307,   345,   346,
     308,   103,   104,   105,   106,   279,   312,   107,   655,   657,
     317,  1129,   120,   121,  1132,   296,   326,   444,   307,   213,
     328,   244,   308,   245,   214,   655,     7,     8,   297,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   307,   307,   307,   307,   295,   618,   329,
     619,     7,     8,   246,   330,   247,  1018,   529,    13,    14,
     530,    16,    17,   531,    19,   532,    21,   332,    22,   160,
      24,    25,   161,    27,    28,   162,   333,   163,   845,   846,
     994,   334,   529,    13,    14,   530,    16,    17,   531,    19,
     532,    21,   248,    22,   249,    24,    25,   688,    27,    28,
     728,    45,    46,    47,   866,   120,   121,   250,   871,   251,
     477,   252,   213,   253,   335,   706,   877,   214,   336,   254,
     880,   255,   256,   258,   257,   259,    45,    46,    47,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   898,   483,
     337,   630,   295,   483,   483,   671,   713,   308,   780,   980,
     781,   981,   913,   914,   915,   544,   338,   339,    30,    31,
      32,    33,   367,    35,   927,   929,   373,   961,   930,    40,
      41,   350,   351,   628,   629,   352,   483,   308,   788,   371,
     559,   937,   938,   939,   290,   291,   292,   293,   294,   872,
     944,   873,   942,   295,   483,   950,   879,   369,   308,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   954,   483,   372,   896,   295,   483,   953,   923,  1094,
     483,   377,   924,   308,   308,   308,   308,   964,   483,   771,
     925,   483,   380,   926,   968,   969,   947,   384,   948,   971,
    1029,  1106,  1030,  1107,  1109,   483,   386,  1114,   978,   979,
     947,  1029,  1118,  1167,   947,  1213,  1187,  1214,   988,   947,
    1233,  1228,  1234,   379,   388,   989,   389,   391,   392,   453,
     394,   359,   443,   295,   810,   811,   812,   454,   455,  1013,
     478,   500,   506,   516,   540,   537,   541,  1021,   546,   552,
     555,  1025,  1026,   622,  1022,   623,   624,     7,     8,   637,
     638,   642,   626,   658,   649,  1073,   659,   660,  1039,   662,
     663,   664,   665,   667,   668,   669,  1166,   675,   683,  1047,
     684,   685,   686,   691,   692,   716,   687,   717,   529,    13,
      14,   530,    16,    17,   531,    19,   532,    21,  1056,    22,
     837,    24,    25,   718,    27,    28,   719,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,  1068,   732,
     733,  1071,   295,  1072,   734,   736,   307,   746,   751,   753,
    1077,   752,    45,    46,    47,  1081,   758,   759,   762,   761,
     765,   767,   775,   778,   784,   785,   776,   777,   791,   779,
     792,   782,   783,   793,   794,   786,   787,   795,   798,   799,
     800,   801,   931,   802,  1097,   803,  1100,   804,  1103,   805,
     359,   818,   817,   826,   819,   827,  1111,   828,   829,   830,
     834,   839,   840,   842,  1116,  1117,   560,   841,   843,   849,
     868,   844,  1120,   874,   881,   859,   887,   861,   890,  1122,
     891,  1124,   894,   831,   832,   833,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     867,   950,   888,   965,   295,   966,   838,   889,   893,   895,
     897,   916,  1153,   934,   935,  1157,  1201,   933,  1161,   936,
     940,   951,  1164,   941,   955,   956,   958,   963,   967,   970,
    1169,   972,   976,  1171,   974,   975,   982,   995,   983,   998,
     984,  1001,   985,   986,  1224,   886,  1227,   987,   280,   996,
     999,   892,  1002,  1004,  1005,  1006,  1007,  1009,  1031,  1028,
     899,   900,   901,  1032,  1239,   904,   905,   906,   907,   908,
     909,   910,  1033,  1046,  1035,  1036,  1037,  1038,  1048,  1049,
    1052,    75,   302,  1054,  1055,   928,   308,    79,    80,    81,
    1064,  1057,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,  1059,  1066,  1061,  1075,  1063,  1067,  1082,
    1083,   303,  1087,  1070,  1088,  1089,  1090,  1091,  1085,  1093,
     952,  1115,  1119,  1121,  1123,  1135,  1136,  1139,  1141,  1148,
    1151,  1154,  1155,    30,    31,    32,    33,    34,    35,  1158,
    1159,  1162,  1163,  1172,    40,    41,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
    1179,  1184,  1191,  1194,   295,  1197,  1204,  1189,  1098,  1173,
    1101,  1205,  1104,  1218,   109,   110,   111,   112,  1220,  1222,
    1225,  1175,  1177,  1185,  1229,  1203,  1207,  1235,  1209,  1211,
    1215,   117,   304,  1014,  1217,  1236,   119,  1237,  1238,  1240,
     876,   122,  1142,    64,  1027,    71,   125,    75,   302,   497,
     957,     0,     0,    79,    80,    81,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,  1065,     0,     0,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
      40,    41,     0,     0,     0,     0,     0,     0,     0,   529,
      13,    14,   530,    16,    17,   531,    19,   532,    21,     0,
      22,     0,    24,    25,     0,    27,    28,     0,     0,     0,
     109,   110,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1108,     0,     0,     0,   117,   321,     0,
       0,     0,   119,    45,    46,    47,     0,   122,     0,     0,
       0,     0,   125,     0,   322,     0,     0,     0,     0,     0,
       0,     0,     0,    75,   302,     0,     0,     0,     0,    79,
      80,    81,     0,  1134,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,     0,   707,     0,     0,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,    40,    41,     0,     0,
       0,   529,    13,    14,   530,    16,    17,   531,    19,   532,
      21,     0,    22,     0,    24,    25,     0,    27,    28,     0,
       0,     0,     0,     0,     0,     0,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   117,   304,    45,    46,    47,   119,     0,
       0,     0,     0,   122,     0,    75,   302,     0,   125,     0,
     496,    79,    80,    81,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,   303,     0,     0,     0,   721,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    31,    32,
      33,    34,    35,     0,    75,   266,     0,     0,    40,    41,
      79,    80,    81,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,     0,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,   304,     0,     0,     0,
     119,     0,     0,     0,     0,   122,     0,    75,   266,   205,
     125,     0,   672,    79,    80,    81,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103,   104,   105,   106,     0,     0,   107,   109,   110,   111,
     112,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   118,     0,     0,     0,   119,
       0,     0,     0,     0,   122,     0,     0,   271,     0,   125,
       0,   272,     0,     0,     0,   529,    13,    14,   530,    16,
      17,   531,    19,   532,    21,     0,    22,     0,    24,    25,
       0,    27,    28,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   111,   112,     0,     0,     0,     0,     0,     0,
     456,     0,     0,     0,     0,     0,     0,   117,   118,    45,
      46,    47,   119,     0,     0,     0,     0,   122,     0,    75,
     266,     0,   125,     0,  1020,    79,    80,    81,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,    75,   266,     7,     8,     0,     0,
      79,    80,    81,  1137,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,   529,    13,    14,
     530,    16,    17,   531,    19,   532,    21,     0,    22,     0,
      24,    25,     0,    27,    28,     0,     0,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   109,   110,   111,   112,   295,     0,     0,     0,
       0,    45,    46,    47,     0,     0,     0,     0,     0,   117,
     118,     0,     0,     0,   119,     0,     0,     0,     0,   122,
       0,     0,   650,     0,   125,     0,   651,   109,   110,   111,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   353,   354,     0,     0,     0,   119,
       0,     0,     0,     0,   355,  1182,    75,    76,    77,   125,
      78,   169,    79,    80,    81,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,     0,   103,
     104,   105,   106,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,   302,     0,     0,     0,
       0,    79,    80,    81,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,    30,    31,    32,
      33,    34,    35,     0,     0,     0,   117,   118,    40,    41,
       0,   119,     0,   120,   121,     0,   122,     0,   123,     0,
     124,   125,     0,   472,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     111,   112,   625,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,   304,     0,     0,     0,
     119,    75,   266,   205,     0,   122,     0,    79,    80,    81,
     125,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,     0,   103,   104,   105,   106,    75,   266,
     107,     0,     0,     0,    79,    80,    81,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     796,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   109,   110,   111,   112,   295,   760,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,   118,     0,     0,   797,   119,     0,   790,     0,
       0,   122,     0,     0,     0,     0,   125,     0,     0,     0,
       0,   109,   110,   111,   112,     0,     0,   824,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   118,
       0,     0,     0,   119,     0,     0,   825,     0,   122,     0,
       0,     0,     0,   125,     0,     0,     0,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   869,     0,     0,     0,   295,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,  1034,     0,     0,     0,   295,     0,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,  1050,     0,     0,     0,   295,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
    1051,     0,     0,     0,   295,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,  1053,
       0,     0,     0,   295,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,  1074,     0,
       0,     0,   295,     0,     0,     0,     0,     0,     0,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,  1140,     0,     0,     0,   295,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,  1180,     0,     0,     0,   295,     0,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,   481,     0,     0,   295,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,     0,   481,     0,     0,   295,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,   556,     0,     0,   295,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
       0,   643,     0,     0,   295,     0,     0,     0,     0,     0,
       0,     0,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   774,     0,     0,     0,
     295,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   836,     0,     0,     0,   295,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   482,   293,   294,     0,     0,     0,     0,   295,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     499,   293,   294,     0,     0,     0,     0,   295,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,     0,     0,     0,     0,   295,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,     0,     0,     0,
     295,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,    -4,     1,     0,   295,
      -4,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,    -4,     0,     0,     0,     0,    -4,    -4,   676,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,    -4,     6,     0,
       0,     0,    -4,    -4,    -4,    -4,     7,     8,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,     0,     0,     0,     0,     9,
       0,     0,     0,     0,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,    22,    23,
      24,    25,    26,    27,    28,     0,     0,     0,    29,    30,
      31,    32,    33,    34,    35,     0,    36,    37,    38,    39,
      40,    41,     7,     8,    42,    43,     0,     0,     0,     0,
      44,    45,    46,    47,     0,     0,    48,     0,    49,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,     0,   529,    13,    14,   530,    16,    17,   531,
      19,   532,    21,     0,    22,     0,    24,    25,     0,    27,
      28,     0,     0,     0,     0,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,    45,    46,    47,
     992,     0,   993,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,  1015,     0,
    1016,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,  1095,     0,  1096,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,   680,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,   681,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
       0,     0,   730,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
     773,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,     0,     0,   809,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,   990,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,  1011,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
       0,     0,  1040,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
    1043,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,     0,     0,  1044,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,  1045,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,  1069,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
       0,     0,  1110,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
    1112,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,     0,     0,  1113,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,  1125,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,  1128,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
       0,     0,  1131,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
    1149,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,     0,     0,  1150,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,  1174,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,  1176,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
       0,     0,  1178,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
    1188,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,   445,     0,     0,     0,     0,   518,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,   475,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,   518,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,   519,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
     553,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,   598,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,   599,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,   612,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,   613,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
     614,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,   615,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,   616,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,   617,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,   694,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
     695,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,   696,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,   770,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,   807,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,   808,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
     835,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,   945,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,   946,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,   962,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,   973,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
    1078,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,  1079,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,  1086,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,  1092,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,  1144,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
    1147,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,     0,     0,   449,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,     0,     0,
       0,     0,   295,     0,     0,     0,   558,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,   562,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,     0,     0,     0,     0,   295,     0,
       0,     0,   577,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,   579,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
       0,     0,     0,     0,   295,     0,     0,     0,   581,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,     0,
       0,   583,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,     0,     0,     0,
     295,     0,     0,     0,   585,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,   587,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,     0,     0,     0,     0,   295,     0,     0,     0,
     589,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,     0,     0,   591,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,     0,     0,
       0,     0,   295,     0,     0,     0,   593,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,   595,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,     0,     0,     0,     0,   295,     0,
       0,     0,   597,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,   601,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
       0,     0,     0,     0,   295,     0,     0,     0,   603,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,     0,
       0,   605,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,     0,     0,     0,
     295,     0,     0,     0,   607,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,   609,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,     0,     0,     0,     0,   295,     0,     0,     0,
     611,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,     0,     0,   711,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,     0,     0,
       0,     0,   295,     0,     0,     0,   712,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,     0,     0,   714,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,     0,     0,     0,     0,   295,     0,
       0,     0,   715,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,     0,     0,   726,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
       0,     0,     0,     0,   295,     0,     0,     0,   750,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,     0,
       0,   851,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,     0,     0,     0,
     295,     0,     0,     0,   853,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,     0,     0,   855,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,     0,     0,     0,     0,   295,     0,     0,     0,
     857,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,     0,     0,   858,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,     0,     0,
       0,     0,   295,     0,     0,     0,   959,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,   445,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,     0,     0,     0,     0,   295,     0,   476,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,   485,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,     0,     0,     0,     0,   295,     0,
     486,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,   488,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,     0,     0,     0,
     295,     0,   490,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,   491,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,     0,     0,
       0,     0,   295,     0,   494,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,   495,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
       0,     0,     0,     0,   295,     0,   502,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,   549,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,     0,     0,     0,     0,   295,     0,   550,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,   551,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,     0,     0,     0,     0,   295,     0,
     557,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,   576,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,     0,     0,     0,
     295,     0,   578,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,   580,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,     0,     0,
       0,     0,   295,     0,   582,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,   584,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
       0,     0,     0,     0,   295,     0,   586,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,   588,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,     0,     0,     0,     0,   295,     0,   590,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,   592,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,     0,     0,     0,     0,   295,     0,
     594,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,   596,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,     0,     0,     0,
     295,     0,   600,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,   602,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,     0,     0,
       0,     0,   295,     0,   604,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,   606,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
       0,     0,     0,     0,   295,     0,   608,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,   610,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,     0,     0,     0,     0,   295,     0,   661,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,   666,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,     0,     0,     0,     0,   295,     0,
     674,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,   677,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,     0,     0,     0,
     295,     0,   678,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,   682,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,     0,     0,
       0,     0,   295,     0,   850,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,     0,   295,     0,   852,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
       0,     0,     0,     0,   295,     0,   854,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     0,     0,     0,     0,   295,     0,   856,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,     0,     0,     0,     0,   295,     0,   862,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,     0,   295,     0,   991,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,     0,     0,     0,     0,   295,     0,
    1010,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,     0,   295,
       0,  1019,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,     0,     0,     0,
     295,     0,  1143,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
       0,   295,     0,  1186
};

static const yytype_int16 yycheck[] =
{
      59,   187,     6,   274,   177,  1028,     6,     6,     3,     6,
      49,   184,     4,     4,     4,     5,    71,     4,     4,     0,
      71,     4,     5,     7,     4,     4,   640,   704,     4,     6,
       6,     6,     6,   206,     6,    13,   209,     7,     4,    71,
      71,     6,     4,     5,    49,     6,    36,    37,    38,    39,
     123,   124,    42,    36,    37,    38,    39,     6,     6,    42,
     134,    72,   133,    72,     6,   139,   139,    78,    79,    78,
      79,     6,     4,     5,    36,    37,    38,    39,   143,    56,
      42,    78,   147,   123,   124,   140,   123,   124,     4,   140,
      82,    83,    84,    85,   133,    56,   133,     6,     7,   708,
     140,   133,   133,   140,    36,    37,    38,    39,   140,   140,
      42,   134,   134,   117,   118,   119,   139,   139,   122,   123,
     100,   133,   126,  1146,   123,   124,    92,    93,   132,   113,
     141,   135,   141,   137,   138,   139,   140,   133,   142,   143,
     144,   145,   133,   147,   148,   149,   823,   761,   152,   141,
     140,   130,   131,   140,   140,   120,   135,   140,   137,   135,
     140,   347,   348,   142,   168,   169,   140,   137,   140,   123,
     124,    53,   120,   177,   123,   124,    92,    93,   449,    49,
    1203,   123,   124,   133,   179,   358,   140,   191,   192,   193,
     140,   195,   187,   133,   198,   199,   133,   201,   130,   131,
     140,   260,   261,   262,   263,   137,   379,   272,   212,   336,
     337,   338,   130,   131,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   133,   322,   872,   133,
     264,    31,    32,     8,    34,   134,    72,   133,   272,   135,
     139,   133,    78,    79,   274,   123,   124,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   140,   134,    46,    72,     7,    49,   139,    51,
     304,    78,    79,   133,   369,   123,   124,    49,   312,     7,
     140,   123,   124,   317,   138,    62,    63,   321,   322,   143,
      51,   139,   326,   147,   328,   329,   330,   139,   332,   333,
     334,   335,   336,   337,   338,   141,    72,    49,   335,   336,
     337,   338,    78,    79,   123,   124,   350,   351,   352,   353,
     354,   355,   347,   348,     7,   133,   139,   135,   141,   133,
     139,     7,   366,   367,   141,   369,    49,   371,   372,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    72,   140,   389,    72,   132,   392,    78,
      79,   391,    78,    79,   140,   165,   141,   167,    49,   110,
     111,   112,   113,   173,   133,   141,   135,   177,   133,   474,
     135,    46,   110,   111,   112,   113,   133,    72,   135,   130,
     131,  1035,  1099,    78,    79,  1102,   137,   133,  1105,   135,
      72,   496,   130,   131,     6,    72,    78,    79,    72,   140,
     444,    78,    79,   140,    78,    79,     4,   451,   272,   449,
    1059,     4,  1061,   450,  1063,   141,    72,   110,   111,   112,
     113,     4,    78,    79,   110,   111,   112,   113,   133,    72,
     474,   475,   133,   477,   478,    78,    79,   481,   482,   483,
     304,     6,   753,   754,   130,   131,   141,   139,  1165,   141,
     123,   124,   496,   123,   124,   499,   500,   321,   322,   141,
       6,     7,   506,   562,   141,   133,   139,   141,   141,   139,
     139,    72,   141,  1190,   518,   519,  1193,    78,    79,  1196,
     524,   133,  1199,   123,   124,   141,   133,   150,   135,  1138,
     125,   126,   127,   156,   135,   539,   540,   132,   141,   139,
       4,   141,  1219,     4,  1221,   369,  1223,    43,   140,   553,
      46,   555,   556,    49,   123,   124,   621,   180,   181,     5,
     130,   131,   562,   622,  1173,   133,  1175,   137,  1177,   133,
     139,   135,   141,     8,  1183,   345,   346,   133,   133,   135,
     141,   123,   124,   133,   354,   135,   651,   646,   123,   124,
      36,    37,    38,    39,   598,   599,    42,   139,  1207,   133,
    1209,   135,  1211,   133,   139,   123,   124,   672,   612,   613,
     614,   615,   616,   617,   618,   123,   124,   621,   133,     4,
       5,   139,   626,     7,   123,   124,   133,   123,   124,   633,
       4,   139,   697,   698,   699,   700,   133,   133,   135,   643,
     139,   133,     5,   135,   140,   123,   124,   651,   123,   124,
     474,    36,    37,    38,    39,     6,   133,    42,   482,   483,
     133,   139,   130,   131,   139,     6,   133,   135,   672,   137,
     140,   133,   496,   135,   142,   499,    12,    13,     6,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   697,   698,   699,   700,   132,   135,   133,
     137,    12,    13,   133,   133,   135,   141,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,   140,    54,    43,
      56,    57,    46,    59,    60,    49,   140,    51,   732,   733,
     916,   133,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,   133,    54,   135,    56,    57,   517,    59,    60,
     750,    87,    88,    89,   754,   130,   131,   133,   762,   135,
     135,   133,   137,   135,   133,   535,   770,   142,   133,   133,
     774,   135,   133,   133,   135,   135,    87,    88,    89,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   792,   139,
     133,   141,   132,   139,   139,   141,   141,   621,    49,     4,
      51,     6,   806,   807,   808,   141,   133,     4,    65,    66,
      67,    68,   135,    70,   818,   819,     6,   876,   822,    76,
      77,   140,   140,   446,   447,   140,   139,   651,   141,   135,
     141,   835,   836,   837,   123,   124,   125,   126,   127,   139,
     844,   141,   842,   132,   139,   849,   141,   140,   672,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   865,   139,   135,   141,   132,   139,   864,   141,  1055,
     139,   137,   141,   697,   698,   699,   700,   881,   139,   649,
     141,   139,    95,   141,   888,   889,   139,     6,   141,   893,
     139,   139,   141,   141,  1067,   139,     6,   141,   902,   903,
     139,   139,   141,   141,   139,   139,   141,   141,   912,   139,
     139,   141,   141,   140,     6,   912,   135,     4,   140,   137,
       6,   916,     5,   132,   694,   695,   696,     7,   135,   933,
     140,     7,     7,   134,     7,   141,     6,   941,   141,    92,
     140,   945,   946,   139,   941,   134,   134,    12,    13,     6,
       4,   136,   139,    95,     7,  1020,     7,     7,   962,     7,
      95,     7,     7,    95,     7,     7,  1139,     7,   134,   973,
     134,   134,   134,   141,   141,     7,   137,     7,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,   992,    54,
       8,    56,    57,     7,    59,    60,   137,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,  1012,   133,
     133,  1015,   132,  1017,   140,     6,  1020,     4,     6,   136,
    1024,     6,    87,    88,    89,  1029,     6,     6,   135,     7,
       6,   120,    49,     7,     7,    51,   659,   660,     7,   662,
     140,   664,   665,     7,     7,   668,   669,     7,     7,     7,
       7,     7,   822,     7,  1058,     7,  1060,     7,  1062,     4,
    1055,   140,     6,     6,   133,     6,  1070,    49,     6,     6,
       4,     4,     4,     4,  1078,  1079,   141,     6,     6,   140,
       7,   133,  1086,     6,   140,   134,     6,   134,     6,  1093,
       6,  1095,     6,   716,   717,   718,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     137,  1115,   140,   883,   132,   885,   134,   140,   140,     6,
       5,   140,  1126,     6,     6,  1129,  1185,   140,  1132,    91,
       6,   137,  1136,     7,     6,     4,     6,   136,     6,     6,
    1144,     5,    95,  1147,     6,     6,     6,   917,     6,   919,
       6,   921,     6,     6,  1213,   778,  1215,     6,     6,     6,
       6,   784,     6,     6,     6,     6,     6,   139,     4,   140,
     793,   794,   795,     6,  1233,   798,   799,   800,   801,   802,
     803,   804,     6,     5,     7,     6,   137,     6,    47,     6,
       6,     3,     4,     6,   140,   818,  1020,     9,    10,    11,
       6,   141,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   140,     7,   140,     6,   140,   140,     6,
     134,    43,     6,    90,     6,     6,     6,     6,    93,   140,
     863,   140,     6,     5,   141,     6,    61,   140,     6,   139,
       6,     6,     6,    65,    66,    67,    68,    69,    70,     6,
       6,     6,   141,     5,    76,    77,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       6,     6,     6,     6,   132,     6,     6,   139,  1058,   140,
    1060,     5,  1062,     6,   106,   107,   108,   109,     6,     6,
       6,   140,   140,   140,     6,   140,   140,     6,   140,   140,
     140,   123,   124,   936,   141,     6,   128,     6,     6,     6,
     769,   133,  1115,     3,   947,     3,   138,     3,     4,   141,
     868,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,  1009,    -1,    -1,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    -1,    56,    57,    -1,    59,    60,    -1,    -1,    -1,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1066,    -1,    -1,    -1,   123,   124,    -1,
      -1,    -1,   128,    87,    88,    89,    -1,   133,    -1,    -1,
      -1,    -1,   138,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,  1106,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,   141,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    -1,    56,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,    87,    88,    89,   128,    -1,
      -1,    -1,    -1,   133,    -1,     3,     4,    -1,   138,    -1,
     140,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    70,    -1,     3,     4,    -1,    -1,    76,    77,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,   133,    -1,     3,     4,     5,
     138,    -1,   140,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    42,   106,   107,   108,
     109,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,   136,    -1,   138,
      -1,   140,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    -1,    56,    57,
      -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,    87,
      88,    89,   128,    -1,    -1,    -1,    -1,   133,    -1,     3,
       4,    -1,   138,    -1,   140,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,     3,     4,    12,    13,    -1,    -1,
       9,    10,    11,   141,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    -1,
      56,    57,    -1,    59,    60,    -1,    -1,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   106,   107,   108,   109,   132,    -1,    -1,    -1,
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,   123,
     124,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,   133,
      -1,    -1,   136,    -1,   138,    -1,   140,   106,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,   133,   141,     3,     4,     5,   138,
       7,   140,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,   123,   124,    76,    77,
      -1,   128,    -1,   130,   131,    -1,   133,    -1,   135,    -1,
     137,   138,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,
     108,   109,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,    -1,    -1,    -1,
     128,     3,     4,     5,    -1,   133,    -1,     9,    10,    11,
     138,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,     3,     4,
      42,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       6,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   106,   107,   108,   109,   132,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,    -1,    -1,    61,   128,    -1,     6,    -1,
      -1,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,   106,   107,   108,   109,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
      -1,    -1,    -1,   128,    -1,    -1,     6,    -1,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     6,    -1,    -1,    -1,   132,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     6,    -1,    -1,    -1,   132,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     6,    -1,    -1,    -1,   132,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       6,    -1,    -1,    -1,   132,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     6,
      -1,    -1,    -1,   132,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     6,    -1,
      -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     6,    -1,    -1,    -1,   132,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,     6,    -1,    -1,    -1,   132,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,     8,    -1,    -1,   132,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,     8,    -1,    -1,   132,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,     8,    -1,    -1,   132,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,     8,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     8,    -1,    -1,    -1,
     132,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,     8,    -1,    -1,    -1,   132,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     132,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,     0,     1,    -1,   132,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    35,    -1,    -1,    -1,    -1,    40,    41,   141,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,     4,    -1,
      -1,    -1,    86,    87,    88,    89,    12,    13,    92,    -1,
      94,    -1,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    72,    73,    74,    75,
      76,    77,    12,    13,    80,    81,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    -1,    94,    -1,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    -1,    56,    57,    -1,    59,
      60,    -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    87,    88,    89,
     139,    -1,   141,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
     141,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,   141,   114,
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
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,   134,    -1,    -1,    -1,    -1,   139,   114,   115,   116,
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
      -1,   132,    -1,   134
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
     146,   148,   149,   167,   170,   171,   174,   175,   176,   177,
     178,   179,   195,   196,   197,     3,     4,     5,     7,     9,
      10,    11,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    36,    37,    38,    39,    42,   100,   106,
     107,   108,   109,   110,   111,   112,   113,   123,   124,   128,
     130,   131,   133,   135,   137,   138,   165,   166,   198,   199,
     210,    13,    49,   133,     6,   140,     6,   133,   140,   133,
     133,    71,   133,   140,   133,   133,    71,   140,   133,   133,
      53,    49,   133,    49,    49,    49,    46,    49,    51,    51,
      43,    46,    49,    51,   133,   140,   123,   124,   133,   140,
     200,   201,   200,   140,    43,    46,    49,   140,   200,   140,
      49,    49,     4,   100,   140,     6,    46,   140,     4,     4,
       4,   133,   133,   133,     4,   140,   206,     4,   133,   133,
       6,   135,     4,     4,     4,     5,   140,   209,   210,   140,
     209,     4,   135,   137,   142,   166,   140,   210,   133,   135,
     133,   135,   133,   135,   133,   135,   133,   135,   133,   135,
     133,   135,   133,   135,   133,   135,   133,   135,   133,   135,
     133,   135,   133,   135,   133,   135,   133,   135,   133,   135,
     133,   135,   133,   135,   133,   135,   133,   135,   133,   135,
     133,   133,   133,   133,     7,   133,     4,   198,   198,   198,
     198,   136,   140,   198,     4,    92,    93,     4,   198,     6,
       6,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   132,     6,     6,   198,     5,
     198,   198,     4,    43,   124,   171,   179,   198,   204,   205,
     198,   198,   133,   198,   205,   198,   198,   133,   205,   198,
     198,   124,   140,   198,   203,   204,   133,   198,   140,   133,
     133,   203,   140,   140,   133,   133,   133,   133,   133,     4,
     200,   200,   200,   198,   198,   123,   124,   140,   140,   200,
     140,   140,   140,   123,   124,   133,   173,   200,   140,   171,
     172,   173,   203,   203,     4,     6,   135,   135,   173,   140,
     172,   135,   135,     6,   198,   198,   198,   137,   198,   140,
      95,   198,   198,   198,     6,   173,     6,   173,     6,   135,
     198,     4,   140,   150,     6,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,     4,   209,   209,
     209,   209,   198,     5,   135,   134,     7,   113,   205,   136,
       7,   165,   166,   137,     7,   135,     6,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,     6,   134,   139,   139,   134,   135,   140,   198,
     204,     8,   125,   139,   141,   134,   134,   198,   134,   141,
     134,   134,   198,   141,   134,   134,   140,   141,   205,   125,
       7,   198,   134,   198,   198,   198,     7,   198,   198,   198,
     168,   198,   210,   168,   168,   168,   134,   139,   139,   139,
     200,   200,   172,   172,   139,   198,   198,   198,   198,    43,
      46,    49,    51,   170,   183,   139,   173,   141,     6,     7,
       7,     6,   198,   198,   141,   205,   141,   198,   198,   134,
     134,   134,    92,   139,   173,   140,     8,   134,   136,   141,
     141,   198,   136,   166,   198,     4,    82,    83,    84,    85,
     141,   153,   157,   160,   162,   163,   134,   136,   134,   136,
     134,   136,   134,   136,   134,   136,   134,   136,   134,   136,
     134,   136,   134,   136,   134,   136,   134,   136,   139,   139,
     134,   136,   134,   136,   134,   136,   134,   136,   134,   136,
     134,   136,   139,   139,   139,   139,   139,   139,   135,   137,
     134,   139,   139,   134,   134,     6,   139,   198,   203,   203,
     141,     7,   137,   165,   166,   210,   198,     6,     4,     4,
     140,   207,   136,     8,     6,   120,   147,   205,   198,     7,
     136,   140,   198,   198,   198,   204,   198,   204,    95,     7,
       7,   134,     7,    95,     7,     7,   134,    95,     7,     7,
     205,   141,   140,   198,   134,     7,   141,   134,   134,   198,
     141,   141,   134,   134,   134,   134,   134,   137,   200,   198,
     198,   141,   141,   198,   139,   139,   139,   140,   140,   140,
     140,    72,    78,    79,   193,   194,   200,   141,   180,   198,
     198,   136,   136,   141,   136,   136,     7,     7,     7,   137,
     198,   141,   198,   198,     7,   137,   136,   137,   166,   209,
     141,   154,   133,   133,   140,   164,     6,   198,   198,   198,
     198,   198,   198,   198,   198,   198,     4,   205,   209,   198,
     136,     6,     6,   136,     4,    92,    93,   198,     6,     6,
       6,     7,   135,   206,   208,     6,   198,   120,   209,   134,
     139,   200,   205,   141,     8,    49,   203,   203,     7,   203,
      49,    51,   203,   203,     7,    51,   203,   203,   141,   205,
       6,     7,   140,     7,     7,     7,     6,    61,     7,     7,
       7,     7,     7,     7,     7,     4,   139,   139,   139,   141,
     200,   200,   200,   205,   205,   205,   205,     6,   140,   133,
     141,   194,   139,   193,     6,     6,     6,     6,    49,     6,
       6,   203,   203,   203,     4,   139,     8,     8,   134,     4,
       4,     6,     4,     6,   133,   198,   198,   202,   203,   140,
     134,   136,   134,   136,   134,   136,   134,   136,   136,   134,
     134,   134,   134,   165,     7,   165,   166,   137,     7,     6,
     206,   198,   139,   141,     6,     6,   147,   198,     6,   141,
     198,   140,     6,    56,     6,    56,   203,     6,   140,   140,
       6,     6,   203,   140,     6,     6,   141,     5,   198,   203,
     203,   203,    62,    63,   203,   203,   203,   203,   203,   203,
     203,     6,     7,   198,   198,   198,   140,   139,   141,   139,
     141,   139,   141,   141,   141,   141,   141,   198,   203,   198,
     198,   200,   141,   140,     6,     6,    91,   198,   198,   198,
       6,     7,   166,   151,   198,   139,   139,   139,   141,   152,
     198,   137,   203,   210,   198,     6,     4,   207,     6,   136,
     206,   209,   139,   136,   198,   200,   200,     6,   198,   198,
       6,   198,     5,   139,     6,     6,    95,   169,   198,   198,
       4,     6,     6,     6,     6,     6,     6,     6,   198,   210,
     141,   134,   139,   141,   172,   200,     6,   184,   200,     6,
     185,   200,     6,   186,     6,     6,     6,     6,   141,   139,
     134,   141,   139,   198,   203,   139,   141,     8,   141,   134,
     140,   198,   210,   134,   139,   198,   198,   203,   140,   139,
     141,     4,     6,     6,     6,     7,     6,   137,     6,   198,
     141,     6,     6,   141,   141,   141,     5,   198,    47,     6,
       6,     6,     6,     6,     6,   140,   198,   141,   139,   140,
     139,   140,   139,   140,     6,   203,     7,   140,   198,   141,
      90,   198,   198,   205,     6,     6,   155,   198,   139,   139,
     202,   198,     6,   134,   206,    93,   139,     6,     6,     6,
       6,     6,   139,   140,   172,   139,   141,   198,   200,   193,
     198,   200,   193,   198,   200,   193,   139,   141,   203,   173,
     141,   198,   141,   141,   141,   140,   198,   198,   141,     6,
     198,     5,   198,   141,   198,   141,   139,   141,   141,   139,
     141,   141,   139,   141,   203,     6,    61,   141,   181,   140,
       6,     6,   152,   134,   139,     6,   140,   139,   139,   141,
     141,     6,   187,   198,     6,     6,   188,   198,     6,     6,
     189,   198,     6,   141,   198,   193,   173,   141,   158,   198,
     202,   198,     5,   140,   141,   140,   141,   140,   141,     6,
       6,   141,   141,   182,     6,   140,   134,   141,   141,   139,
     193,     6,   190,   193,     6,   191,   193,     6,   192,   193,
     156,   209,   161,   140,     6,     5,   141,   140,   141,   140,
     141,   140,   141,   139,   141,   140,   202,   141,     6,   193,
       6,   193,     6,   193,   209,     6,   159,   209,   141,     6,
     141,   141,   141,   139,   141,     6,     6,     6,     6,   209,
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
#line 137 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 148 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 149 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 150 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 151 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 152 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 153 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 154 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 155 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 156 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 157 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 158 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 159 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 160 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 161 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 166 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 21:
#line 170 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 22:
#line 177 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 23:
#line 182 "Gmsh.y"
    {
      char tmpstring[1024];
      FixRelativePath((yyvsp[(6) - (7)].c), tmpstring);
      FILE *fp = fopen(tmpstring, (yyvsp[(5) - (7)].c));
      if(!fp){
	yymsg(0, "Unable to open file '%s'", tmpstring);
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
#line 197 "Gmsh.y"
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

  case 25:
#line 210 "Gmsh.y"
    {
      char tmpstring[1024];
      int i = PrintListOfDouble((yyvsp[(3) - (9)].c), (yyvsp[(5) - (9)].l), tmpstring);
      if(i < 0) 
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else{
	char tmpstring2[1024];
	FixRelativePath((yyvsp[(8) - (9)].c), tmpstring2);
	FILE *fp = fopen(tmpstring2, (yyvsp[(7) - (9)].c));
	if(!fp){
	  yymsg(0, "Unable to open file '%s'", tmpstring2);
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
#line 239 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
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

  case 27:
#line 253 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], false);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 28:
#line 264 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], true);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 29:
#line 278 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData = new PViewDataList(true); 
#endif
    ;}
    break;

  case 35:
#line 292 "Gmsh.y"
    { ViewCoord[ViewCoordIdx++] = (yyvsp[(1) - (1)].d); ;}
    break;

  case 36:
#line 294 "Gmsh.y"
    { ViewCoord[ViewCoordIdx++] = (yyvsp[(3) - (3)].d); ;}
    break;

  case 37:
#line 299 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(1) - (1)].d)); ;}
    break;

  case 38:
#line 301 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(3) - (3)].d)); ;}
    break;

  case 39:
#line 306 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
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
	yymsg(0, "Unknown element type '%s'", (yyvsp[(1) - (1)].c));	
	ViewValueList = 0; ViewNumList = 0;
      }
#endif
      ViewCoordIdx = 0;
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 40:
#line 452 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(int j = 0; j < ViewCoordIdx / 3; j++)
	    List_Add(ViewValueList, &ViewCoord[3 * j + i]);
      }
#endif
    ;}
    break;

  case 41:
#line 462 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 42:
#line 471 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(ViewData->T2C, &(yyvsp[(1) - (1)].c)[i]); 
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 43:
#line 478 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(ViewData->T2C, &(yyvsp[(3) - (3)].c)[i]); 
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 44:
#line 488 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      List_Add(ViewData->T2D, &(yyvsp[(3) - (8)].d)); 
      List_Add(ViewData->T2D, &(yyvsp[(5) - (8)].d));
      List_Add(ViewData->T2D, &(yyvsp[(7) - (8)].d)); 
      double d = List_Nbr(ViewData->T2C);
      List_Add(ViewData->T2D, &d); 
#endif
    ;}
    break;

  case 45:
#line 498 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 46:
#line 507 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(ViewData->T3C, &(yyvsp[(1) - (1)].c)[i]); 
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 47:
#line 514 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(ViewData->T3C, &(yyvsp[(3) - (3)].c)[i]); 
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 48:
#line 524 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      List_Add(ViewData->T3D, &(yyvsp[(3) - (10)].d)); List_Add(ViewData->T3D, &(yyvsp[(5) - (10)].d));
      List_Add(ViewData->T3D, &(yyvsp[(7) - (10)].d)); List_Add(ViewData->T3D, &(yyvsp[(9) - (10)].d)); 
      double d = List_Nbr(ViewData->T3C);
      List_Add(ViewData->T3D, &d); 
#endif
    ;}
    break;

  case 49:
#line 533 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 50:
#line 543 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      int type = 
	(ViewData->NbSL || ViewData->NbVL) ? 1 : 
	(ViewData->NbST || ViewData->NbVT) ? 3 : 
	(ViewData->NbSQ || ViewData->NbVQ) ? 4 : 
	(ViewData->NbSS || ViewData->NbVS) ? 6 : 
	(ViewData->NbSI || ViewData->NbVI) ? 9 : 
      	(ViewData->NbSH || ViewData->NbVH) ? 12 : 
	0;
      ViewData->setInterpolationScheme(type, (yyvsp[(3) - (8)].l), (yyvsp[(6) - (8)].l));
#endif
    ;}
    break;

  case 51:
#line 560 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      int type = 
	(ViewData->NbSL || ViewData->NbVL) ? 1 : 
	(ViewData->NbST || ViewData->NbVT) ? 3 : 
	(ViewData->NbSQ || ViewData->NbVQ) ? 4 : 
	(ViewData->NbSS || ViewData->NbVS) ? 6 : 
      	(ViewData->NbSH || ViewData->NbVH) ? 12 : 
	0;
      ViewData->setInterpolationScheme(type, (yyvsp[(3) - (14)].l), (yyvsp[(6) - (14)].l), (yyvsp[(9) - (14)].l), (yyvsp[(12) - (14)].l));
#endif
    ;}
    break;

  case 52:
#line 576 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewValueList = ViewData->Time;
#endif
    ;}
    break;

  case 53:
#line 582 "Gmsh.y"
    {
    ;}
    break;

  case 54:
#line 589 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 55:
#line 590 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 56:
#line 591 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 57:
#line 592 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 58:
#line 593 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 59:
#line 597 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 60:
#line 598 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 61:
#line 606 "Gmsh.y"
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

  case 62:
#line 628 "Gmsh.y"
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
	if(gmsh_yysymbols[(yyvsp[(1) - (7)].c)].size() < index + 1)
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

  case 63:
#line 655 "Gmsh.y"
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
	    if(gmsh_yysymbols[(yyvsp[(1) - (9)].c)].size() < index + 1)
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

  case 64:
#line 695 "Gmsh.y"
    {
      if(gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].clear();
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].push_back(*(double*)List_Pointer((yyvsp[(5) - (6)].l), i));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 65:
#line 704 "Gmsh.y"
    {
      // appends to the list
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].push_back(*(double*)List_Pointer((yyvsp[(5) - (6)].l), i));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 66:
#line 712 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c)); 
      else
	gmsh_yysymbols[(yyvsp[(1) - (3)].c)][0] += (yyvsp[(2) - (3)].i);
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 67:
#line 720 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c)); 
      else{
	int index = (int)(yyvsp[(3) - (6)].d);
	if(gmsh_yysymbols[(yyvsp[(1) - (6)].c)].size() < index + 1)
	  gmsh_yysymbols[(yyvsp[(1) - (6)].c)].resize(index + 1, 0.);
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)][index] += (yyvsp[(5) - (6)].i);
      }
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 68:
#line 732 "Gmsh.y"
    { 
      Msg::Warning("Named string expressions not implemented yet");
    ;}
    break;

  case 69:
#line 739 "Gmsh.y"
    { 
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 70:
#line 744 "Gmsh.y"
    { 
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].c));
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 71:
#line 752 "Gmsh.y"
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

  case 72:
#line 770 "Gmsh.y"
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

  case 73:
#line 788 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 74:
#line 797 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 75:
#line 809 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 76:
#line 814 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 77:
#line 822 "Gmsh.y"
    {
      GmshColorTable *ct = Get_ColorTable(0);
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

  case 78:
#line 842 "Gmsh.y"
    {
      GmshColorTable *ct = Get_ColorTable((int)(yyvsp[(3) - (9)].d));
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

  case 79:
#line 865 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->background_field = (int)(yyvsp[(4) - (5)].d);
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
    ;}
    break;

  case 80:
#line 872 "Gmsh.y"
    {
      if(!GModel::current()->getFields()->new_field((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 81:
#line 878 "Gmsh.y"
    {
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option){
	  try { option->numerical_value((yyvsp[(8) - (9)].d)); }
	  catch(...){
	    yymsg(0, "Cannot assign a numerical value to option '%s' "
		  "in field %i of type '%s'", (yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->get_name());
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->get_name());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (9)].d));
      Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 82:
#line 898 "Gmsh.y"
    {
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option){
	  try { option->string() = (yyvsp[(8) - (9)].c); }
	  catch (...){
	    yymsg(0, "Cannot assign a string value to  option '%s' "
		  "in field %i of type '%s'", (yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->get_name());
	  }
	}
	else 
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'", 
		(yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->get_name());
      }
      else 
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (9)].d));
      Free((yyvsp[(6) - (9)].c));
      Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 83:
#line 919 "Gmsh.y"
    {
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
		(yyvsp[(6) - (11)].c), (int)(yyvsp[(3) - (11)].d), field->get_name());
      }
      else 
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (11)].d));
      Free((yyvsp[(6) - (11)].c));
      List_Delete((yyvsp[(9) - (11)].l));
    ;}
    break;

  case 84:
#line 945 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      try {
	GMSH_PluginManager::instance()->setPluginOption((yyvsp[(3) - (9)].c), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].d)); 
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", (yyvsp[(6) - (9)].c), (yyvsp[(3) - (9)].c));
      }
#endif
      Free((yyvsp[(3) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 85:
#line 957 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      try {
	GMSH_PluginManager::instance()->setPluginOption((yyvsp[(3) - (9)].c), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].c)); 
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", (yyvsp[(6) - (9)].c), (yyvsp[(3) - (9)].c));
      }
#endif
      Free((yyvsp[(3) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 86:
#line 974 "Gmsh.y"
    { 
      (yyval.i) = (int)(yyvsp[(1) - (1)].d); 
    ;}
    break;

  case 87:
#line 978 "Gmsh.y"
    { 
      (yyval.i) = GModel::current()->setPhysicalName
	(std::string((yyvsp[(1) - (1)].c)), ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 88:
#line 987 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 89:
#line 991 "Gmsh.y"
    {
      (yyval.l) = List_Create(4, 4, sizeof(double));
      Vertex *v = FindPoint((int)(yyvsp[(4) - (5)].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[(4) - (5)].d));
      else{
	List_Add((yyval.l), &v->Pos.X);
	List_Add((yyval.l), &v->Pos.Y);
	List_Add((yyval.l), &v->Pos.Z);
      }
    ;}
    break;

  case 90:
#line 1009 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindPoint(num)){
	yymsg(0, "Point %d already exists", num);
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

  case 91:
#line 1031 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT)){
	yymsg(0, "Physical point %d already exists", num);
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

  case 92:
#line 1047 "Gmsh.y"
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

  case 93:
#line 1069 "Gmsh.y"
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

  case 94:
#line 1087 "Gmsh.y"
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

  case 95:
#line 1105 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
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

  case 96:
#line 1123 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (9)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
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

  case 97:
#line 1149 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
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

  case 98:
#line 1167 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (9)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
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

  case 99:
#line 1194 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (17)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
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

  case 100:
#line 1213 "Gmsh.y"
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

  case 101:
#line 1231 "Gmsh.y"
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

  case 102:
#line 1249 "Gmsh.y"
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

  case 103:
#line 1275 "Gmsh.y"
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

  case 104:
#line 1292 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE)){
	yymsg(0, "Physical line %d already exists", num);
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

  case 105:
#line 1311 "Gmsh.y"
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

  case 106:
#line 1329 "Gmsh.y"
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
	  s->RuledSurfaceOptions = (yyvsp[(8) - (9)].l);
	  Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
	}
      }
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type = type;
      (yyval.s).Num = num;
    ;}
    break;

  case 107:
#line 1368 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 108:
#line 1374 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 109:
#line 1380 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 110:
#line 1387 "Gmsh.y"
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

  case 111:
#line 1412 "Gmsh.y"
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

  case 112:
#line 1437 "Gmsh.y"
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

  case 113:
#line 1453 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(0, "Physical surface %d already exists", num);
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

  case 114:
#line 1473 "Gmsh.y"
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

  case 115:
#line 1491 "Gmsh.y"
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

  case 116:
#line 1508 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME)){
	yymsg(0, "Physical volume %d already exists", num);
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

  case 117:
#line 1529 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 118:
#line 1534 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 119:
#line 1539 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 120:
#line 1544 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 121:
#line 1549 "Gmsh.y"
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

  case 122:
#line 1560 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 123:
#line 1566 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      BoundaryShapes((yyvsp[(3) - (4)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 124:
#line 1574 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 125:
#line 1575 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 126:
#line 1580 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 127:
#line 1584 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 128:
#line 1588 "Gmsh.y"
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

  case 129:
#line 1611 "Gmsh.y"
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

  case 130:
#line 1634 "Gmsh.y"
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

  case 131:
#line 1657 "Gmsh.y"
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

  case 132:
#line 1685 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 133:
#line 1694 "Gmsh.y"
    {
      GModel::current()->getFields()->delete_field((int)(yyvsp[(4) - (6)].d));
    ;}
    break;

  case 134:
#line 1698 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
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

  case 135:
#line 1713 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Model") || !strcmp((yyvsp[(2) - (3)].c), "Meshes") || !strcmp((yyvsp[(2) - (3)].c), "All")){
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
      else{
	if(gmsh_yysymbols.count((yyvsp[(2) - (3)].c)))
	  gmsh_yysymbols.erase((yyvsp[(2) - (3)].c));
	else
	  yymsg(0, "Unknown object or expression to delete '%s'", (yyvsp[(2) - (3)].c));
      }
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 136:
#line 1734 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
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

  case 137:
#line 1751 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));      
    ;}
    break;

  case 138:
#line 1765 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 139:
#line 1771 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 140:
#line 1777 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 141:
#line 1786 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 142:
#line 1800 "Gmsh.y"
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
	Msg::StatusBar(2, true, "Reading '%s'", tmpstring);
	ParseFile(tmpstring, 0, 1);
	SetBoundingBox();
	Msg::StatusBar(2, true, "Read '%s'", tmpstring);
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
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 143:
#line 1848 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      if(!strcmp((yyvsp[(1) - (7)].c), "Save") && !strcmp((yyvsp[(2) - (7)].c), "View")){
	int index = (int)(yyvsp[(4) - (7)].d);
	if(index >= 0 && index < (int)PView::list.size()){
	  char tmpstring[1024];
	  FixRelativePath((yyvsp[(6) - (7)].c), tmpstring);
	  PView::list[index]->write(tmpstring, CTX.post.file_format);
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

  case 144:
#line 1866 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      if(!strcmp((yyvsp[(1) - (7)].c), "Background") && !strcmp((yyvsp[(2) - (7)].c), "Mesh")  && !strcmp((yyvsp[(3) - (7)].c), "View")){
	int index = (int)(yyvsp[(5) - (7)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  GModel::current()->getFields()->set_background_mesh(index);
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (7)].c));
#endif
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(2) - (7)].c)); Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 145:
#line 1881 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Sleep")){
	SleepInSeconds((yyvsp[(2) - (3)].d));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Remesh")){
	Msg::Error("Surface remeshing must be reinterfaced");
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Mesh")){
	int lock = CTX.threads_lock;
	CTX.threads_lock = 0;
	GModel::current()->importGEOInternals();
	GModel::current()->mesh((int)(yyvsp[(2) - (3)].d));
	CTX.threads_lock = lock;
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 146:
#line 1900 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
       try {
	 GMSH_PluginManager::instance()->action((yyvsp[(3) - (7)].c), (yyvsp[(6) - (7)].c), 0);
       }
       catch(...) {
	 yymsg(0, "Unknown action '%s' or plugin '%s'", (yyvsp[(6) - (7)].c), (yyvsp[(3) - (7)].c));
       }
#endif
       Free((yyvsp[(3) - (7)].c)); Free((yyvsp[(6) - (7)].c));
     ;}
    break;

  case 147:
#line 1912 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
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
	yymsg(0, "Unknown 'Combine' command");
#endif
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 148:
#line 1936 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 149:
#line 1940 "Gmsh.y"
    {
      CTX.forced_bbox = 0;
      SetBoundingBox();
    ;}
    break;

  case 150:
#line 1945 "Gmsh.y"
    {
      CTX.forced_bbox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 151:
#line 1950 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      Draw();
#endif
    ;}
    break;

  case 152:
#line 1962 "Gmsh.y"
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

  case 153:
#line 1979 "Gmsh.y"
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

  case 154:
#line 1996 "Gmsh.y"
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

  case 155:
#line 2015 "Gmsh.y"
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

  case 156:
#line 2034 "Gmsh.y"
    {
      if(ImbricatedLoop <= 0){
	yymsg(0, "Invalid For/EndFor loop");
	ImbricatedLoop = 0;
      }
      else{
	double x0 = LoopControlVariablesTab[ImbricatedLoop - 1][0];
	double x1 = LoopControlVariablesTab[ImbricatedLoop - 1][1];
	double step = LoopControlVariablesTab[ImbricatedLoop - 1][2];
	int do_next = (step > 0.) ? (x0 + step <= x1) : (x0 + step >= x1);
	if(do_next){
	  LoopControlVariablesTab[ImbricatedLoop - 1][0] +=
	    LoopControlVariablesTab[ImbricatedLoop - 1][2];
	  if(LoopControlVariablesNameTab[ImbricatedLoop - 1]){
	    if(!gmsh_yysymbols.count(LoopControlVariablesNameTab[ImbricatedLoop - 1]))
	      yymsg(0, "Unknown loop variable");
	    else
	      gmsh_yysymbols[LoopControlVariablesNameTab[ImbricatedLoop - 1]][0] +=
		LoopControlVariablesTab[ImbricatedLoop - 1][2];
	  }
	  fsetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop - 1]);
	  gmsh_yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop - 1];
	}
	else
	  ImbricatedLoop--;
      }
    ;}
    break;

  case 157:
#line 2062 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname,
						      gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 158:
#line 2070 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&gmsh_yyin, gmsh_yyname,
						     gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 159:
#line 2076 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname,
						     gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 160:
#line 2083 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 161:
#line 2087 "Gmsh.y"
    {
    ;}
    break;

  case 162:
#line 2096 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 163:
#line 2104 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 164:
#line 2112 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 165:
#line 2120 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 166:
#line 2124 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 167:
#line 2132 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 168:
#line 2136 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 169:
#line 2144 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 170:
#line 2148 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 171:
#line 2156 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 172:
#line 2160 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 173:
#line 2169 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 174:
#line 2176 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 175:
#line 2183 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 176:
#line 2190 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 177:
#line 2197 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 178:
#line 2204 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 179:
#line 2211 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 180:
#line 2218 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 181:
#line 2225 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 182:
#line 2232 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 183:
#line 2236 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 184:
#line 2243 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 185:
#line 2247 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 186:
#line 2254 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 187:
#line 2258 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 188:
#line 2265 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 189:
#line 2269 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 190:
#line 2276 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 191:
#line 2280 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 192:
#line 2287 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 193:
#line 2291 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 194:
#line 2298 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 195:
#line 2302 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 196:
#line 2309 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 197:
#line 2313 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 198:
#line 2320 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 199:
#line 2324 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 200:
#line 2335 "Gmsh.y"
    {
    ;}
    break;

  case 201:
#line 2338 "Gmsh.y"
    {
    ;}
    break;

  case 202:
#line 2344 "Gmsh.y"
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
#line 2353 "Gmsh.y"
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

  case 204:
#line 2373 "Gmsh.y"
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

  case 205:
#line 2396 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 206:
#line 2400 "Gmsh.y"
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

  case 207:
#line 2424 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j);
	if(!c)
	  yymsg(1, "Unknown curve %d", j);
	else{
	  c->Method = MESH_TRANSFINITE;
	  c->nbPointsTransfinite = ((yyvsp[(5) - (6)].d) > 2) ? (int)(yyvsp[(5) - (6)].d) : 2;
	  c->typeTransfinite = sign(d);
	  c->coeffTransfinite = 1.0;
	}
      }
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 208:
#line 2442 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (9)].l), i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j);
	if(!c)
	  yymsg(1, "Unknown curve %d", j);
	else{
	  c->Method = MESH_TRANSFINITE;
	  c->nbPointsTransfinite = ((yyvsp[(5) - (9)].d) > 2) ? (int)(yyvsp[(5) - (9)].d) : 2;
	  c->typeTransfinite = sign(d); // Progresion : code 1 ou -1
	  c->coeffTransfinite = fabs((yyvsp[(8) - (9)].d));
	}
      }
      List_Delete((yyvsp[(3) - (9)].l));
    ;}
    break;

  case 209:
#line 2460 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (9)].l), i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j);
	if(!c)
	  yymsg(1, "Unknown curve %d", j);
	else{
	  c->Method = MESH_TRANSFINITE;
	  c->nbPointsTransfinite = ((yyvsp[(5) - (9)].d) > 2) ? (int)(yyvsp[(5) - (9)].d) : 2;
	  c->typeTransfinite = 2 * sign(d); // Bump : code 2 ou -2
	  c->coeffTransfinite = fabs((yyvsp[(8) - (9)].d));
	}
      }
      List_Delete((yyvsp[(3) - (9)].l));
    ;}
    break;

  case 210:
#line 2478 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(4) - (8)].d));
      if(!s)
	yymsg(1, "Unknown surface %d", (int)(yyvsp[(4) - (8)].d));
      else{
	s->Method = MESH_TRANSFINITE;
	s->Recombine_Dir = -1;
	int k = List_Nbr((yyvsp[(7) - (8)].l));
	if(k != 3 && k != 4){
	  yymsg(0, "Wrong definition of Transfinite Surface %d: "
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
	      yymsg(1, "Unknown point %d", j);
	    else
	      List_Add(s->TrsfPoints, &v);
	  }
	}
      }
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 211:
#line 2507 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(4) - (9)].d));
      if(!s)
	yymsg(1, "Unknown surface %d", (int)(yyvsp[(4) - (9)].d));
      else{
	s->Method = MESH_TRANSFINITE;
	int k = List_Nbr((yyvsp[(7) - (9)].l));
	if(k != 3 && k != 4){
	  yymsg(0, "Wrong definition of Transfinite Surface %d: "
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
	      yymsg(1, "Unknown point %d", j);
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
#line 2542 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 213:
#line 2547 "Gmsh.y"
    {
      Volume *v = FindVolume((int)(yyvsp[(4) - (8)].d));
      if(!v)
	yymsg(1, "Unknown volume %d", (int)(yyvsp[(4) - (8)].d));
      else{
	v->Method = MESH_TRANSFINITE;
	int k = List_Nbr((yyvsp[(7) - (8)].l));
	if(k != 6 && k != 8)
	  yymsg(0, "Wrong definition of Transfinite Volume %d: "
		"%d points instead of 6 or 8" , (int)(yyvsp[(4) - (8)].d), k);
	else{
	  List_Reset(v->TrsfPoints);
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read((yyvsp[(7) - (8)].l), i, &d);
	    int j = (int)fabs(d);
	    Vertex *vert = FindPoint(j);
	    if(!vert)
	      yymsg(1, "Unknown point %d", j);
	    else
	      List_Add(v->TrsfPoints, &vert);
	  }
	}
      }
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 214:
#line 2574 "Gmsh.y"
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
#line 2588 "Gmsh.y"
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
#line 2601 "Gmsh.y"
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
#line 2618 "Gmsh.y"
    { 
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s)
	setSurfaceEmbeddedPoints(s, (yyvsp[(3) - (10)].l));
    ;}
    break;

  case 218:
#line 2624 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s)
	setSurfaceEmbeddedCurves(s, (yyvsp[(3) - (10)].l));
    ;}
    break;

  case 219:
#line 2630 "Gmsh.y"
    {
    ;}
    break;

  case 220:
#line 2633 "Gmsh.y"
    {
    ;}
    break;

  case 221:
#line 2642 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 222:
#line 2651 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 223:
#line 2652 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 224:
#line 2653 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 225:
#line 2654 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 226:
#line 2655 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 227:
#line 2656 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 228:
#line 2657 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 229:
#line 2658 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 230:
#line 2660 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 231:
#line 2666 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 232:
#line 2667 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 233:
#line 2668 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 234:
#line 2669 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 235:
#line 2670 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 236:
#line 2671 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 237:
#line 2672 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 238:
#line 2673 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 239:
#line 2674 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 240:
#line 2675 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 241:
#line 2676 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 242:
#line 2677 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 243:
#line 2678 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 244:
#line 2679 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 245:
#line 2680 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 246:
#line 2681 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 247:
#line 2682 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 248:
#line 2683 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 249:
#line 2684 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 250:
#line 2685 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 251:
#line 2686 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 252:
#line 2687 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 253:
#line 2688 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 254:
#line 2689 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 255:
#line 2690 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 256:
#line 2691 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 257:
#line 2692 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 258:
#line 2693 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 259:
#line 2694 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 260:
#line 2695 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 261:
#line 2696 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 262:
#line 2697 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 263:
#line 2699 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 264:
#line 2700 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 265:
#line 2701 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 266:
#line 2702 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 267:
#line 2703 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 268:
#line 2704 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 269:
#line 2705 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 270:
#line 2706 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 271:
#line 2707 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 272:
#line 2708 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 273:
#line 2709 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 274:
#line 2710 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 275:
#line 2711 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 276:
#line 2712 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 277:
#line 2713 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 278:
#line 2714 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 279:
#line 2715 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 280:
#line 2716 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 281:
#line 2717 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 282:
#line 2718 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 283:
#line 2719 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 284:
#line 2728 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 285:
#line 2729 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 286:
#line 2730 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 287:
#line 2731 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 288:
#line 2732 "Gmsh.y"
    { (yyval.d) = Get_GmshMajorVersion(); ;}
    break;

  case 289:
#line 2733 "Gmsh.y"
    { (yyval.d) = Get_GmshMinorVersion(); ;}
    break;

  case 290:
#line 2734 "Gmsh.y"
    { (yyval.d) = Get_GmshPatchVersion(); ;}
    break;

  case 291:
#line 2739 "Gmsh.y"
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

  case 292:
#line 2752 "Gmsh.y"
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

  case 293:
#line 2764 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
	(yyval.d) = 0.;
      }
      else if(gmsh_yysymbols[(yyvsp[(1) - (4)].c)].size() < index + 1){
	yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (4)].c), index);
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = gmsh_yysymbols[(yyvsp[(1) - (4)].c)][index];
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 294:
#line 2779 "Gmsh.y"
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

  case 295:
#line 2789 "Gmsh.y"
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

  case 296:
#line 2799 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (5)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (5)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (5)].c));
	(yyval.d) = 0.;
      }
      else if(gmsh_yysymbols[(yyvsp[(1) - (5)].c)].size() < index + 1){
	yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (5)].c), index);
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = (gmsh_yysymbols[(yyvsp[(1) - (5)].c)][index] += (yyvsp[(5) - (5)].i));
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 297:
#line 2817 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 298:
#line 2822 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 299:
#line 2827 "Gmsh.y"
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

  case 300:
#line 2837 "Gmsh.y"
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

  case 301:
#line 2847 "Gmsh.y"
    { 
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 302:
#line 2855 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 303:
#line 2859 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 304:
#line 2863 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 305:
#line 2867 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 306:
#line 2871 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 307:
#line 2878 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 308:
#line 2882 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 309:
#line 2886 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 310:
#line 2890 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 311:
#line 2897 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 312:
#line 2902 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 313:
#line 2909 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 314:
#line 2914 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 315:
#line 2918 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 316:
#line 2923 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 317:
#line 2927 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 318:
#line 2935 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 319:
#line 2946 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 320:
#line 2954 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 321:
#line 2962 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 322:
#line 2968 "Gmsh.y"
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

  case 323:
#line 2979 "Gmsh.y"
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

  case 324:
#line 2999 "Gmsh.y"
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
#line 3009 "Gmsh.y"
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
#line 3019 "Gmsh.y"
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

  case 327:
#line 3029 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c));
      else{
	for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	  int index = (int)(*(double*)List_Pointer_Fast((yyvsp[(4) - (6)].l), i));
	  if(gmsh_yysymbols[(yyvsp[(1) - (6)].c)].size() < index + 1)
	    yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (6)].c), index);
	  else
	    List_Add((yyval.l), &gmsh_yysymbols[(yyvsp[(1) - (6)].c)][index]);
	}
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 328:
#line 3049 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 329:
#line 3054 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 330:
#line 3058 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 331:
#line 3062 "Gmsh.y"
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
#line 3074 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 333:
#line 3078 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 334:
#line 3090 "Gmsh.y"
    {
      int flag;
      (yyval.u) = Get_ColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 335:
#line 3097 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 336:
#line 3107 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 337:
#line 3111 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      GmshColorTable *ct = Get_ColorTable((int)(yyvsp[(3) - (6)].d));
      if(!ct)
	yymsg(0, "View[%d] does not exist", (int)(yyvsp[(3) - (6)].d));
      else{
	for(int i = 0; i < ct->size; i++) 
	  List_Add((yyval.l), &ct->table[i]);
      }
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 338:
#line 3126 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 339:
#line 3131 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 340:
#line 3138 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 341:
#line 3142 "Gmsh.y"
    {
      Msg::Warning("Named string expressions not implemented yet");
    ;}
    break;

  case 342:
#line 3149 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 343:
#line 3153 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32*sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 344:
#line 3161 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c))+strlen((yyvsp[(5) - (6)].c))+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 345:
#line 3169 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (4)].c))+1)*sizeof(char));
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

  case 346:
#line 3183 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (4)].c))+1)*sizeof(char));
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

  case 347:
#line 3197 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 348:
#line 3201 "Gmsh.y"
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
	(yyval.c) = (char*)Malloc((strlen(tmpstring)+1)*sizeof(char));
	strcpy((yyval.c), tmpstring);
	Free((yyvsp[(3) - (6)].c));
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 349:
#line 3220 "Gmsh.y"
    { 
      const char *val = "";
      StringOption(GMSH_GET, (yyvsp[(3) - (6)].c), 0, (yyvsp[(5) - (6)].c), val);
      (yyval.c) = (char*)Malloc((strlen(val) + 1) * sizeof(char));
      strcpy((yyval.c), val);
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 350:
#line 3228 "Gmsh.y"
    { 
      const char *val = "";
      StringOption(GMSH_GET, (yyvsp[(3) - (9)].c), (int)(yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].c), val);
      (yyval.c) = (char*)Malloc((strlen(val) + 1) * sizeof(char));
      strcpy((yyval.c), val);
      Free((yyvsp[(3) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 7621 "Gmsh.tab.cpp"
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


#line 3237 "Gmsh.y"


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

void FixRelativePath(const char *in, char *out)
{
  if(in[0] == '/' || in[0] == '\\' || (strlen(in)>2 && in[1] == ':')){
    // do nothing: 'in' is an absolute path
    strcpy(out, in);
  }
  else{
    // append 'in' to the path of the parent file
    strcpy(out, gmsh_yyname);
    int i = strlen(out) - 1 ;
    while(i >= 0 && gmsh_yyname[i] != '/' && gmsh_yyname[i] != '\\') i-- ;
    out[i+1] = '\0';
    strcat(out, in);
  }
}

void yyerror(char *s)
{
  Msg::Error("'%s', line %d : %s (%s)", gmsh_yyname, gmsh_yylineno - 1, s, gmsh_yytext);
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
    Msg::Error("'%s', line %d : %s", gmsh_yyname, gmsh_yylineno - 1, tmp);
    gmsh_yyerrorstate++;
  }
  else
    Msg::Warning("'%s', line %d : %s", gmsh_yyname, gmsh_yylineno - 1, tmp);
}

