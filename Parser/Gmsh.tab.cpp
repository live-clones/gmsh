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
     tLoop = 325,
     tRecombine = 326,
     tSmoother = 327,
     tSplit = 328,
     tDelete = 329,
     tCoherence = 330,
     tIntersect = 331,
     tLayers = 332,
     tHole = 333,
     tAlias = 334,
     tAliasWithOptions = 335,
     tText2D = 336,
     tText3D = 337,
     tInterpolationScheme = 338,
     tTime = 339,
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
     tReturn = 355,
     tCall = 356,
     tFunction = 357,
     tShow = 358,
     tHide = 359,
     tGetValue = 360,
     tGMSH_MAJOR_VERSION = 361,
     tGMSH_MINOR_VERSION = 362,
     tGMSH_PATCH_VERSION = 363,
     tAFFECTDIVIDE = 364,
     tAFFECTTIMES = 365,
     tAFFECTMINUS = 366,
     tAFFECTPLUS = 367,
     tOR = 368,
     tAND = 369,
     tNOTEQUAL = 370,
     tEQUAL = 371,
     tGREATEROREQUAL = 372,
     tLESSOREQUAL = 373,
     UNARYPREC = 374,
     tMINUSMINUS = 375,
     tPLUSPLUS = 376
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
#define tLoop 325
#define tRecombine 326
#define tSmoother 327
#define tSplit 328
#define tDelete 329
#define tCoherence 330
#define tIntersect 331
#define tLayers 332
#define tHole 333
#define tAlias 334
#define tAliasWithOptions 335
#define tText2D 336
#define tText3D 337
#define tInterpolationScheme 338
#define tTime 339
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
#define tReturn 355
#define tCall 356
#define tFunction 357
#define tShow 358
#define tHide 359
#define tGetValue 360
#define tGMSH_MAJOR_VERSION 361
#define tGMSH_MINOR_VERSION 362
#define tGMSH_PATCH_VERSION 363
#define tAFFECTDIVIDE 364
#define tAFFECTTIMES 365
#define tAFFECTMINUS 366
#define tAFFECTPLUS 367
#define tOR 368
#define tAND 369
#define tNOTEQUAL 370
#define tEQUAL 371
#define tGREATEROREQUAL 372
#define tLESSOREQUAL 373
#define UNARYPREC 374
#define tMINUSMINUS 375
#define tPLUSPLUS 376




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
static std::map<std::string, std::string > gmsh_yystringsymbols;
#if !defined(HAVE_NO_POST)
static PViewDataList *ViewData;
#endif
static std::vector<double> ViewCoord;
static List_T *ViewValueList = 0;
static int *ViewNumList = 0;
static ExtrudeParams extr;
static gmshSurface *myGmshSurface = 0;
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
#line 71 "Gmsh.y"
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
#line 426 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 439 "Gmsh.tab.cpp"

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
#define YYLAST   6277

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  142
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  351
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1245

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   376

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   127,     2,   137,     2,   126,     2,     2,
     132,   133,   124,   122,   138,   123,   136,   125,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     118,     2,   119,   113,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   134,     2,   135,   131,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   139,     2,   140,   141,     2,     2,     2,
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
     105,   106,   107,   108,   109,   110,   111,   112,   114,   115,
     116,   117,   120,   121,   128,   129,   130
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
     709,   719,   724,   734,   744,   746,   748,   749,   752,   759,
     766,   773,   780,   785,   792,   799,   803,   808,   814,   818,
     822,   827,   832,   836,   844,   852,   856,   864,   868,   871,
     874,   890,   893,   900,   909,   918,   929,   931,   934,   936,
     940,   945,   947,   953,   965,   979,   980,   988,   989,  1003,
    1004,  1020,  1021,  1028,  1037,  1046,  1055,  1068,  1081,  1094,
    1109,  1124,  1139,  1140,  1153,  1154,  1167,  1168,  1181,  1182,
    1199,  1200,  1217,  1218,  1235,  1236,  1255,  1256,  1275,  1276,
    1295,  1297,  1300,  1306,  1314,  1324,  1327,  1337,  1344,  1354,
    1364,  1373,  1383,  1392,  1401,  1408,  1413,  1420,  1431,  1442,
    1453,  1464,  1467,  1471,  1473,  1477,  1480,  1483,  1486,  1490,
    1494,  1498,  1502,  1506,  1510,  1514,  1518,  1522,  1526,  1530,
    1534,  1538,  1542,  1548,  1553,  1558,  1563,  1568,  1573,  1578,
    1583,  1588,  1593,  1598,  1605,  1610,  1615,  1620,  1625,  1630,
    1635,  1642,  1649,  1656,  1661,  1666,  1671,  1676,  1681,  1686,
    1691,  1696,  1701,  1706,  1711,  1718,  1723,  1728,  1733,  1738,
    1743,  1748,  1755,  1762,  1769,  1774,  1776,  1778,  1780,  1782,
    1784,  1786,  1788,  1790,  1796,  1801,  1806,  1809,  1815,  1819,
    1826,  1831,  1839,  1846,  1848,  1851,  1854,  1858,  1862,  1874,
    1884,  1892,  1900,  1902,  1906,  1908,  1910,  1913,  1917,  1922,
    1928,  1931,  1935,  1939,  1945,  1950,  1952,  1954,  1958,  1965,
    1967,  1969,  1973,  1977,  1987,  1995,  1997,  2003,  2007,  2014,
    2016,  2020,  2022,  2024,  2028,  2035,  2037,  2039,  2046,  2051,
    2056,  2061
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     143,     0,    -1,   144,    -1,     1,     6,    -1,    -1,   144,
     145,    -1,   148,    -1,   147,    -1,   166,    -1,   169,    -1,
     170,    -1,   173,    -1,   174,    -1,   175,    -1,   178,    -1,
     194,    -1,   195,    -1,   196,    -1,   177,    -1,   176,    -1,
     119,    -1,   119,   119,    -1,    35,   132,     5,   133,     6,
      -1,    35,   132,     5,   133,   146,   208,     6,    -1,    35,
     132,     5,   138,   204,   133,     6,    -1,    35,   132,     5,
     138,   204,   133,   146,   208,     6,    -1,     4,     5,   139,
     149,   140,     6,    -1,    79,     4,   134,   197,   135,     6,
      -1,    80,     4,   134,   197,   135,     6,    -1,    -1,   149,
     152,    -1,   149,   156,    -1,   149,   159,    -1,   149,   161,
      -1,   149,   162,    -1,   197,    -1,   150,   138,   197,    -1,
     197,    -1,   151,   138,   197,    -1,    -1,    -1,     4,   153,
     132,   150,   133,   154,   139,   151,   140,     6,    -1,   208,
      -1,   155,   138,   208,    -1,    -1,    81,   132,   197,   138,
     197,   138,   197,   133,   157,   139,   155,   140,     6,    -1,
     208,    -1,   158,   138,   208,    -1,    -1,    82,   132,   197,
     138,   197,   138,   197,   138,   197,   133,   160,   139,   158,
     140,     6,    -1,    83,   139,   201,   140,   139,   201,   140,
       6,    -1,    83,   139,   201,   140,   139,   201,   140,   139,
     201,   140,   139,   201,   140,     6,    -1,    -1,    84,   163,
     139,   151,   140,     6,    -1,     7,    -1,   112,    -1,   111,
      -1,   110,    -1,   109,    -1,   130,    -1,   129,    -1,     4,
     164,   197,     6,    -1,     4,   134,   197,   135,   164,   197,
       6,    -1,     4,   134,   139,   204,   140,   135,   164,   202,
       6,    -1,     4,   134,   135,     7,   202,     6,    -1,     4,
     134,   135,   112,   202,     6,    -1,     4,   165,     6,    -1,
       4,   134,   197,   135,   165,     6,    -1,     4,     7,   209,
       6,    -1,     4,   136,     4,     7,   209,     6,    -1,     4,
     134,   197,   135,   136,     4,     7,   209,     6,    -1,     4,
     136,     4,   164,   197,     6,    -1,     4,   134,   197,   135,
     136,     4,   164,   197,     6,    -1,     4,   136,     4,   165,
       6,    -1,     4,   134,   197,   135,   136,     4,   165,     6,
      -1,     4,   136,    91,   136,     4,     7,   205,     6,    -1,
       4,   134,   197,   135,   136,    91,   136,     4,     7,   205,
       6,    -1,     4,   136,    92,     7,   206,     6,    -1,     4,
     134,   197,   135,   136,    92,     7,   206,     6,    -1,     4,
      99,     7,   197,     6,    -1,    99,   134,   197,   135,     7,
       4,     6,    -1,    99,   134,   197,   135,   136,     4,     7,
     197,     6,    -1,    99,   134,   197,   135,   136,     4,     7,
     209,     6,    -1,    99,   134,   197,   135,   136,     4,     7,
     139,   204,   140,     6,    -1,    64,   132,     4,   133,   136,
       4,     7,   197,     6,    -1,    64,   132,     4,   133,   136,
       4,     7,   209,     6,    -1,   197,    -1,   209,    -1,    -1,
      94,    47,   139,   197,   140,    -1,    43,   132,   197,   133,
       7,   199,     6,    -1,    60,    43,   132,   167,   133,     7,
     202,     6,    -1,    52,    53,   202,     7,   197,     6,    -1,
      46,   132,   197,   133,     7,   202,     6,    -1,    50,   132,
     197,   133,     7,   202,     6,    -1,    44,   132,   197,   133,
       7,   202,     6,    -1,    44,   132,   197,   133,     7,   202,
      56,   199,     6,    -1,    45,   132,   197,   133,     7,   202,
       6,    -1,    45,   132,   197,   133,     7,   202,    56,   199,
       6,    -1,    54,   132,   197,   133,     7,   139,   197,   138,
     197,   138,     5,   138,     5,   138,     5,   140,     6,    -1,
      86,   132,   197,   133,     7,   202,     6,    -1,    87,   132,
     197,   133,     7,   202,     6,    -1,    88,   132,   197,   133,
       7,   202,    90,   202,    89,   197,     6,    -1,    46,    70,
     132,   197,   133,     7,   202,     6,    -1,    60,    46,   132,
     167,   133,     7,   202,     6,    -1,    56,    49,   132,   197,
     133,     7,   202,     6,    -1,    57,    49,   132,   197,   133,
       7,   202,   168,     6,    -1,    12,    13,     6,    -1,    13,
      49,   197,     6,    -1,    54,    49,   132,   197,   133,     7,
       5,     5,     5,     6,    -1,    47,   132,   197,   133,     7,
     202,     6,    -1,    48,   132,   197,   133,     7,   202,     6,
      -1,    49,    70,   132,   197,   133,     7,   202,     6,    -1,
      60,    49,   132,   167,   133,     7,   202,     6,    -1,    59,
      51,   132,   197,   133,     7,   202,     6,    -1,    51,   132,
     197,   133,     7,   202,     6,    -1,    60,    51,   132,   167,
     133,     7,   202,     6,    -1,    66,   199,   139,   171,   140,
      -1,    65,   139,   199,   138,   199,   138,   197,   140,   139,
     171,   140,    -1,    67,   199,   139,   171,   140,    -1,    68,
     139,   199,   138,   197,   140,   139,   171,   140,    -1,     4,
     139,   171,   140,    -1,    76,    46,   139,   204,   140,    49,
     139,   197,   140,    -1,    73,    46,   132,   197,   133,   139,
     204,   140,     6,    -1,   172,    -1,   170,    -1,    -1,   172,
     169,    -1,   172,    43,   139,   204,   140,     6,    -1,   172,
      46,   139,   204,   140,     6,    -1,   172,    49,   139,   204,
     140,     6,    -1,   172,    51,   139,   204,   140,     6,    -1,
      74,   139,   172,   140,    -1,    74,    99,   134,   197,   135,
       6,    -1,    74,     4,   134,   197,   135,     6,    -1,    74,
       4,     6,    -1,    74,     4,     4,     6,    -1,    91,   205,
     139,   172,   140,    -1,   103,   208,     6,    -1,   104,   208,
       6,    -1,   103,   139,   172,   140,    -1,   104,   139,   172,
     140,    -1,     4,   209,     6,    -1,     4,     4,   134,   197,
     135,   208,     6,    -1,     4,     4,     4,   134,   197,   135,
       6,    -1,     4,   197,     6,    -1,    64,   132,     4,   133,
     136,     4,     6,    -1,    85,     4,     6,    -1,    98,     6,
      -1,    40,     6,    -1,    40,   139,   197,   138,   197,   138,
     197,   138,   197,   138,   197,   138,   197,   140,     6,    -1,
      41,     6,    -1,    93,   132,   197,     8,   197,   133,    -1,
      93,   132,   197,     8,   197,     8,   197,   133,    -1,    93,
       4,    94,   139,   197,     8,   197,   140,    -1,    93,     4,
      94,   139,   197,     8,   197,     8,   197,   140,    -1,    95,
      -1,   102,     4,    -1,   100,    -1,   101,     4,     6,    -1,
      96,   132,   197,   133,    -1,    97,    -1,    69,   199,   139,
     172,   140,    -1,    69,   139,   199,   138,   199,   138,   197,
     140,   139,   172,   140,    -1,    69,   139,   199,   138,   199,
     138,   199,   138,   197,   140,   139,   172,   140,    -1,    -1,
      69,   199,   139,   172,   179,   192,   140,    -1,    -1,    69,
     139,   199,   138,   199,   138,   197,   140,   139,   172,   180,
     192,   140,    -1,    -1,    69,   139,   199,   138,   199,   138,
     199,   138,   197,   140,   139,   172,   181,   192,   140,    -1,
      -1,    69,   139,   172,   182,   192,   140,    -1,    69,    43,
     139,   197,   138,   199,   140,     6,    -1,    69,    46,   139,
     197,   138,   199,   140,     6,    -1,    69,    49,   139,   197,
     138,   199,   140,     6,    -1,    69,    43,   139,   197,   138,
     199,   138,   199,   138,   197,   140,     6,    -1,    69,    46,
     139,   197,   138,   199,   138,   199,   138,   197,   140,     6,
      -1,    69,    49,   139,   197,   138,   199,   138,   199,   138,
     197,   140,     6,    -1,    69,    43,   139,   197,   138,   199,
     138,   199,   138,   199,   138,   197,   140,     6,    -1,    69,
      46,   139,   197,   138,   199,   138,   199,   138,   199,   138,
     197,   140,     6,    -1,    69,    49,   139,   197,   138,   199,
     138,   199,   138,   199,   138,   197,   140,     6,    -1,    -1,
      69,    43,   139,   197,   138,   199,   140,   183,   139,   192,
     140,     6,    -1,    -1,    69,    46,   139,   197,   138,   199,
     140,   184,   139,   192,   140,     6,    -1,    -1,    69,    49,
     139,   197,   138,   199,   140,   185,   139,   192,   140,     6,
      -1,    -1,    69,    43,   139,   197,   138,   199,   138,   199,
     138,   197,   140,   186,   139,   192,   140,     6,    -1,    -1,
      69,    46,   139,   197,   138,   199,   138,   199,   138,   197,
     140,   187,   139,   192,   140,     6,    -1,    -1,    69,    49,
     139,   197,   138,   199,   138,   199,   138,   197,   140,   188,
     139,   192,   140,     6,    -1,    -1,    69,    43,   139,   197,
     138,   199,   138,   199,   138,   199,   138,   197,   140,   189,
     139,   192,   140,     6,    -1,    -1,    69,    46,   139,   197,
     138,   199,   138,   199,   138,   199,   138,   197,   140,   190,
     139,   192,   140,     6,    -1,    -1,    69,    49,   139,   197,
     138,   199,   138,   199,   138,   199,   138,   197,   140,   191,
     139,   192,   140,     6,    -1,   193,    -1,   192,   193,    -1,
      77,   139,   197,   140,     6,    -1,    77,   139,   202,   138,
     202,   140,     6,    -1,    77,   139,   202,   138,   202,   138,
     202,   140,     6,    -1,    71,     6,    -1,    78,   132,   197,
     133,     7,   202,    61,   197,     6,    -1,    58,    46,   202,
       7,   197,     6,    -1,    58,    46,   202,     7,   197,    61,
      63,   197,     6,    -1,    58,    46,   202,     7,   197,    61,
      62,   197,     6,    -1,    58,    49,   139,   197,   140,     7,
     202,     6,    -1,    58,    49,   139,   197,   140,     7,   202,
       4,     6,    -1,    55,    49,   139,   197,   140,     7,   202,
       6,    -1,    58,    51,   139,   197,   140,     7,   202,     6,
      -1,    71,    49,   202,     7,   197,     6,    -1,    71,    49,
     202,     6,    -1,    72,    49,   202,     7,   197,     6,    -1,
      43,   139,   204,   140,    94,    49,   139,   197,   140,     6,
      -1,    46,   139,   204,   140,    94,    49,   139,   197,   140,
       6,    -1,    46,   139,   204,   140,    94,    51,   139,   197,
     140,     6,    -1,    49,   139,   204,   140,    94,    51,   139,
     197,   140,     6,    -1,    75,     6,    -1,    75,     4,     6,
      -1,   198,    -1,   132,   197,   133,    -1,   123,   197,    -1,
     122,   197,    -1,   127,   197,    -1,   197,   123,   197,    -1,
     197,   122,   197,    -1,   197,   124,   197,    -1,   197,   125,
     197,    -1,   197,   126,   197,    -1,   197,   131,   197,    -1,
     197,   118,   197,    -1,   197,   119,   197,    -1,   197,   121,
     197,    -1,   197,   120,   197,    -1,   197,   117,   197,    -1,
     197,   116,   197,    -1,   197,   115,   197,    -1,   197,   114,
     197,    -1,   197,   113,   197,     8,   197,    -1,    14,   132,
     197,   133,    -1,    15,   132,   197,   133,    -1,    16,   132,
     197,   133,    -1,    17,   132,   197,   133,    -1,    18,   132,
     197,   133,    -1,    19,   132,   197,   133,    -1,    20,   132,
     197,   133,    -1,    21,   132,   197,   133,    -1,    22,   132,
     197,   133,    -1,    24,   132,   197,   133,    -1,    25,   132,
     197,   138,   197,   133,    -1,    26,   132,   197,   133,    -1,
      27,   132,   197,   133,    -1,    28,   132,   197,   133,    -1,
      29,   132,   197,   133,    -1,    30,   132,   197,   133,    -1,
      31,   132,   197,   133,    -1,    32,   132,   197,   138,   197,
     133,    -1,    33,   132,   197,   138,   197,   133,    -1,    34,
     132,   197,   138,   197,   133,    -1,    23,   132,   197,   133,
      -1,    14,   134,   197,   135,    -1,    15,   134,   197,   135,
      -1,    16,   134,   197,   135,    -1,    17,   134,   197,   135,
      -1,    18,   134,   197,   135,    -1,    19,   134,   197,   135,
      -1,    20,   134,   197,   135,    -1,    21,   134,   197,   135,
      -1,    22,   134,   197,   135,    -1,    24,   134,   197,   135,
      -1,    25,   134,   197,   138,   197,   135,    -1,    26,   134,
     197,   135,    -1,    27,   134,   197,   135,    -1,    28,   134,
     197,   135,    -1,    29,   134,   197,   135,    -1,    30,   134,
     197,   135,    -1,    31,   134,   197,   135,    -1,    32,   134,
     197,   138,   197,   135,    -1,    33,   134,   197,   138,   197,
     135,    -1,    34,   134,   197,   138,   197,   135,    -1,    23,
     134,   197,   135,    -1,     3,    -1,     9,    -1,    10,    -1,
      11,    -1,   106,    -1,   107,    -1,   108,    -1,     4,    -1,
       4,   141,   139,   197,   140,    -1,     4,   134,   197,   135,
      -1,   137,     4,   134,   135,    -1,     4,   165,    -1,     4,
     134,   197,   135,   165,    -1,     4,   136,     4,    -1,     4,
     134,   197,   135,   136,     4,    -1,     4,   136,     4,   165,
      -1,     4,   134,   197,   135,   136,     4,   165,    -1,   105,
     132,     5,   138,   197,   133,    -1,   200,    -1,   123,   199,
      -1,   122,   199,    -1,   199,   123,   199,    -1,   199,   122,
     199,    -1,   139,   197,   138,   197,   138,   197,   138,   197,
     138,   197,   140,    -1,   139,   197,   138,   197,   138,   197,
     138,   197,   140,    -1,   139,   197,   138,   197,   138,   197,
     140,    -1,   132,   197,   138,   197,   138,   197,   133,    -1,
     202,    -1,   201,   138,   202,    -1,   197,    -1,   203,    -1,
     139,   140,    -1,   139,   204,   140,    -1,   123,   139,   204,
     140,    -1,   197,   124,   139,   204,   140,    -1,   123,   203,
      -1,   197,   124,   203,    -1,   197,     8,   197,    -1,   197,
       8,   197,     8,   197,    -1,    43,   139,   197,   140,    -1,
     170,    -1,   178,    -1,     4,   134,   135,    -1,     4,   134,
     139,   204,   140,   135,    -1,   197,    -1,   203,    -1,   204,
     138,   197,    -1,   204,   138,   203,    -1,   139,   197,   138,
     197,   138,   197,   138,   197,   140,    -1,   139,   197,   138,
     197,   138,   197,   140,    -1,     4,    -1,     4,   136,    91,
     136,     4,    -1,   139,   207,   140,    -1,     4,   134,   197,
     135,   136,    92,    -1,   205,    -1,   207,   138,   205,    -1,
     209,    -1,     4,    -1,     4,   136,     4,    -1,     4,   134,
     197,   135,   136,     4,    -1,     5,    -1,    42,    -1,    37,
     132,   208,   138,   208,   133,    -1,    38,   132,   208,   133,
      -1,    39,   132,   208,   133,    -1,    36,   132,   208,   133,
      -1,    36,   132,   208,   138,   204,   133,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   137,   137,   138,   143,   145,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     166,   170,   177,   182,   197,   210,   239,   253,   264,   279,
     284,   285,   286,   287,   288,   292,   294,   299,   301,   307,
     453,   306,   471,   478,   489,   488,   507,   514,   525,   524,
     542,   557,   577,   576,   590,   591,   592,   593,   594,   598,
     599,   606,   628,   655,   695,   705,   713,   721,   733,   742,
     747,   755,   773,   791,   800,   812,   817,   825,   845,   868,
     875,   881,   901,   922,   948,   960,   977,   981,   991,   994,
    1012,  1035,  1051,  1073,  1091,  1109,  1127,  1153,  1171,  1197,
    1217,  1235,  1253,  1279,  1296,  1315,  1333,  1372,  1378,  1384,
    1391,  1416,  1441,  1457,  1477,  1495,  1512,  1533,  1538,  1543,
    1548,  1553,  1573,  1579,  1590,  1591,  1596,  1599,  1603,  1626,
    1649,  1672,  1700,  1709,  1713,  1728,  1749,  1766,  1780,  1786,
    1792,  1801,  1815,  1863,  1881,  1896,  1915,  1927,  1951,  1955,
    1960,  1965,  1977,  1994,  2011,  2030,  2049,  2077,  2085,  2091,
    2098,  2102,  2111,  2119,  2127,  2136,  2135,  2148,  2147,  2160,
    2159,  2172,  2171,  2184,  2191,  2198,  2205,  2212,  2219,  2226,
    2233,  2240,  2248,  2247,  2259,  2258,  2270,  2269,  2281,  2280,
    2292,  2291,  2303,  2302,  2314,  2313,  2325,  2324,  2336,  2335,
    2350,  2353,  2359,  2368,  2388,  2411,  2415,  2439,  2457,  2475,
    2493,  2522,  2557,  2562,  2589,  2603,  2616,  2633,  2639,  2645,
    2648,  2657,  2661,  2677,  2678,  2679,  2680,  2681,  2682,  2683,
    2684,  2685,  2692,  2693,  2694,  2695,  2696,  2697,  2698,  2699,
    2700,  2701,  2702,  2703,  2704,  2705,  2706,  2707,  2708,  2709,
    2710,  2711,  2712,  2713,  2714,  2715,  2716,  2717,  2718,  2719,
    2720,  2721,  2722,  2723,  2725,  2726,  2727,  2728,  2729,  2730,
    2731,  2732,  2733,  2734,  2735,  2736,  2737,  2738,  2739,  2740,
    2741,  2742,  2743,  2744,  2745,  2754,  2755,  2756,  2757,  2758,
    2759,  2760,  2764,  2777,  2789,  2804,  2814,  2824,  2842,  2847,
    2852,  2862,  2872,  2880,  2884,  2888,  2892,  2896,  2903,  2907,
    2911,  2915,  2922,  2927,  2934,  2939,  2943,  2948,  2952,  2960,
    2971,  2979,  2987,  2993,  3004,  3024,  3034,  3044,  3054,  3074,
    3079,  3083,  3087,  3099,  3103,  3115,  3122,  3132,  3136,  3151,
    3156,  3163,  3167,  3180,  3188,  3199,  3203,  3211,  3219,  3233,
    3247,  3251
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
  "tDilate", "tExtrude", "tLoop", "tRecombine", "tSmoother", "tSplit",
  "tDelete", "tCoherence", "tIntersect", "tLayers", "tHole", "tAlias",
  "tAliasWithOptions", "tText2D", "tText3D", "tInterpolationScheme",
  "tTime", "tCombine", "tBSpline", "tBezier", "tNurbs", "tOrder", "tKnots",
  "tColor", "tColorTable", "tFor", "tIn", "tEndFor", "tIf", "tEndIf",
  "tExit", "tField", "tReturn", "tCall", "tFunction", "tShow", "tHide",
  "tGetValue", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION",
  "tGMSH_PATCH_VERSION", "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS",
  "tAFFECTPLUS", "'?'", "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'",
  "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'",
  "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All",
  "GeoFormatItems", "GeoFormatItem", "SendToFile", "Printf", "View",
  "Views", "ElementCoords", "ElementValues", "Element", "@1", "@2",
  "Text2DValues", "Text2D", "@3", "Text3DValues", "Text3D", "@4",
  "InterpolationMatrix", "Time", "@5", "NumericAffectation",
  "NumericIncrement", "Affectation", "PhysicalId", "RuledSurfaceOptions",
  "Shape", "Transform", "MultipleShape", "ListOfShapes", "Delete",
  "Colorify", "Visibility", "Command", "Loop", "Extrude", "@6", "@7", "@8",
  "@9", "@10", "@11", "@12", "@13", "@14", "@15", "@16", "@17", "@18",
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
     365,   366,   367,    63,   368,   369,   370,   371,    60,    62,
     372,   373,    43,    45,    42,    47,    37,    33,   374,   375,
     376,    94,    40,    41,    91,    93,    46,    35,    44,   123,
     125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   142,   143,   143,   144,   144,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     146,   146,   147,   147,   147,   147,   148,   148,   148,   149,
     149,   149,   149,   149,   149,   150,   150,   151,   151,   153,
     154,   152,   155,   155,   157,   156,   158,   158,   160,   159,
     161,   161,   163,   162,   164,   164,   164,   164,   164,   165,
     165,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   167,   167,   168,   168,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   170,   170,   170,
     170,   170,   170,   170,   171,   171,   172,   172,   172,   172,
     172,   172,   173,   173,   173,   173,   173,   174,   175,   175,
     175,   175,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   178,   178,   178,   179,   178,   180,   178,   181,
     178,   182,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   183,   178,   184,   178,   185,   178,   186,   178,
     187,   178,   188,   178,   189,   178,   190,   178,   191,   178,
     192,   192,   193,   193,   193,   193,   193,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   195,   195,   195,
     195,   196,   196,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   199,   199,   199,   199,   199,   200,   200,
     200,   200,   201,   201,   202,   202,   202,   202,   202,   202,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   204,
     204,   204,   204,   205,   205,   205,   205,   206,   206,   207,
     207,   208,   208,   208,   208,   209,   209,   209,   209,   209,
     209,   209
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
       9,     4,     9,     9,     1,     1,     0,     2,     6,     6,
       6,     6,     4,     6,     6,     3,     4,     5,     3,     3,
       4,     4,     3,     7,     7,     3,     7,     3,     2,     2,
      15,     2,     6,     8,     8,    10,     1,     2,     1,     3,
       4,     1,     5,    11,    13,     0,     7,     0,    13,     0,
      15,     0,     6,     8,     8,     8,    12,    12,    12,    14,
      14,    14,     0,    12,     0,    12,     0,    12,     0,    16,
       0,    16,     0,    16,     0,    18,     0,    18,     0,    18,
       1,     2,     5,     7,     9,     2,     9,     6,     9,     9,
       8,     9,     8,     8,     6,     4,     6,    10,    10,    10,
      10,     2,     3,     1,     3,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4,     4,     2,     5,     3,     6,
       4,     7,     6,     1,     2,     2,     3,     3,    11,     9,
       7,     7,     1,     3,     1,     1,     2,     3,     4,     5,
       2,     3,     3,     5,     4,     1,     1,     3,     6,     1,
       1,     3,     3,     9,     7,     1,     5,     3,     6,     1,
       3,     1,     1,     3,     6,     1,     1,     6,     4,     4,
       4,     6
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   156,
       0,   161,     0,     0,   158,     0,     0,     0,     0,     5,
       7,     6,     8,     9,    10,    11,    12,    13,    19,    18,
      14,    15,    16,    17,   285,   292,   345,    54,   286,   287,
     288,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   346,     0,     0,   289,
     290,   291,    58,    57,    56,    55,     0,     0,     0,    60,
      59,     0,     0,     0,     0,   126,     0,     0,     0,   223,
       0,     0,     0,     0,   149,     0,   151,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   303,     0,     0,     0,     0,     0,   126,     0,     0,
       0,     0,     0,     0,   126,     0,   221,     0,     0,     0,
       0,     0,     0,     0,   335,     0,     0,     0,     0,     0,
     148,     0,     0,   157,   342,   345,   126,     0,   341,   126,
       0,     0,     0,     0,     0,   296,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,   226,   225,   227,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
       0,   124,     0,    66,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   107,     0,     0,     0,     0,   292,     0,     0,   325,
     326,   329,   330,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   314,     0,   315,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   305,   304,     0,     0,     0,
       0,   126,   126,     0,     0,     0,     0,     0,     0,     0,
     171,     0,   126,     0,     0,     0,     0,   135,     0,     0,
       0,   222,     0,     0,     0,   147,     0,     0,     0,     0,
       0,   126,     0,     0,     0,     0,   159,     0,     0,     0,
     138,     0,   139,     0,     0,   298,     0,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   224,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,   121,
       0,     0,     0,     0,   127,    61,     0,   241,   240,   239,
     238,   234,   235,   237,   236,   229,   228,   230,   231,   232,
     233,   108,     0,     0,     0,     0,     0,     0,   225,   320,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   316,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,     0,     0,     0,     0,     0,     0,     0,   307,
     306,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   215,     0,     0,     0,   136,     0,     0,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,     0,     0,   343,   140,   141,     0,   294,   300,     0,
      39,     0,     0,     0,    52,     0,    30,    31,    32,    33,
      34,   243,   264,   244,   265,   245,   266,   246,   267,   247,
     268,   248,   269,   249,   270,   250,   271,   251,   272,   263,
     284,   252,   273,     0,     0,   254,   275,   255,   276,   256,
     277,   257,   278,   258,   279,   259,   280,     0,     0,     0,
       0,     0,     0,   350,     0,     0,   348,   349,    79,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
      73,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,    22,    20,     0,     0,     0,     0,   327,     0,     0,
     322,   230,   321,   331,   332,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   317,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   119,
       0,     0,     0,     0,     0,     0,     0,     0,   200,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,     0,     0,
       0,     0,     0,   297,     0,   293,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,    64,    65,     0,     0,     0,     0,
       0,    67,    69,    71,     0,     0,   339,     0,    77,     0,
       0,     0,     0,   242,    21,     0,     0,     0,     0,     0,
     324,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   318,     0,    92,     0,     0,
       0,     0,     0,   207,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,   172,   201,     0,     0,   214,   216,     0,
     134,   133,     0,    27,    28,     0,     0,     0,   336,     0,
       0,     0,   152,     0,     0,     0,   144,   299,   143,     0,
       0,     0,     0,   312,     0,   253,   274,   260,   281,   261,
     282,   262,   283,   351,   347,   302,     0,    54,     0,     0,
       0,     0,    62,     0,     0,     0,   337,     0,     0,     0,
       0,    23,    24,     0,     0,    90,     0,   323,     0,    95,
       0,    97,     0,     0,    93,     0,     0,   110,   111,     0,
       0,    94,   115,   319,     0,     0,     0,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,     0,
       0,     0,     0,   126,     0,   182,     0,   184,     0,   186,
     314,     0,     0,     0,     0,   166,     0,     0,   100,   101,
       0,     0,     0,     0,    80,     0,   344,   301,     0,    35,
       0,     0,     0,     0,     0,    37,     0,     0,     0,    74,
       0,     0,    75,     0,   340,   128,   129,   130,   131,     0,
       0,   328,     0,     0,     0,   103,     0,     0,   112,     0,
       0,     0,   212,   105,     0,     0,     0,     0,     0,   210,
     213,   114,    91,   104,   113,   116,     0,     0,     0,   311,
       0,   310,     0,     0,   173,     0,     0,   174,     0,     0,
     175,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   334,     0,   154,   153,     0,     0,     0,    40,     0,
       0,     0,   313,     0,     0,     0,    63,    70,    72,     0,
      78,     0,    25,     0,     0,    96,    98,     0,     0,     0,
       0,     0,     0,   106,   209,   208,   211,    84,    85,   126,
       0,   120,     0,     0,     0,     0,     0,     0,   202,     0,
       0,   126,     0,   123,   122,     0,     0,     0,     0,    81,
      82,     0,    36,     0,     0,     0,    38,    53,     0,   338,
       0,   217,   218,   219,   220,   109,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,     0,     0,   333,   155,     0,     0,
       0,     0,     0,    76,     0,     0,     0,   118,     0,   188,
       0,     0,   190,     0,     0,   192,     0,     0,     0,   203,
       0,   163,     0,   126,   102,    83,     0,    44,     0,    50,
       0,     0,     0,    89,   308,   176,     0,     0,   183,   177,
       0,     0,   185,   178,     0,     0,   187,     0,     0,     0,
     169,     0,     0,     0,     0,     0,     0,     0,   194,     0,
     196,     0,   198,   204,   206,   168,   164,     0,    41,     0,
      48,     0,     0,     0,     0,   179,     0,     0,   180,     0,
       0,   181,     0,     0,     0,    42,     0,     0,   150,     0,
       0,     0,     0,     0,     0,     0,   170,     0,     0,     0,
       0,     0,   189,     0,   191,     0,   193,     0,    43,    45,
       0,    46,     0,    99,     0,     0,     0,     0,     0,    51,
     195,   197,   199,    47,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    59,   653,    60,    61,   397,   948,   954,
     576,   736,  1081,  1204,   577,  1172,  1230,   578,  1206,   579,
     580,   740,   126,   215,    62,   519,   985,   464,   309,   280,
     281,    65,    66,    67,    68,    69,   310,   711,  1142,  1187,
     538,  1005,  1008,  1011,  1156,  1160,  1164,  1196,  1199,  1202,
     707,   708,    71,    72,    73,   327,   129,   345,   171,   852,
     853,   329,   313,   196,   644,   767,   207,   208
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1030
static const yytype_int16 yypact[] =
{
    2799,    73,    16,  2876, -1030, -1030,  1375,    32,   -22,   -79,
      -1,   110,   125,   -10,    -6,    47,    -2,    45,   -48,    55,
      61,   118,   -39,   131,   134,   211,   447,   220,   219,   165,
     173,   346,   346,   182,   257,   259,   301,   336,    28,    33,
     358,   360,   403,   446,   331,   384,   391,    15,    24, -1030,
     405, -1030,   486,   333, -1030,   496,   537,    13,    25, -1030,
   -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030,
   -1030, -1030, -1030, -1030, -1030,    21,   412,   508, -1030, -1030,
   -1030,   -75,   -40,    74,   143,   229,   289,   308,   383,   434,
     470,   476,   479,   495,   505,   538,   541,   557,   564,   570,
     590,   594,   429,   433,   439,   448, -1030,   591,   488, -1030,
   -1030, -1030, -1030, -1030, -1030, -1030,  2224,  2224,  2224, -1030,
   -1030,  2224,  1853,     8,   624,    30,  2224,   642,  1101, -1030,
     646,   647,  2224,   687, -1030,  2224, -1030,  2224,  2156,  2224,
    2224,   528,  2224,  2156,  2224,  2224,   567,  2156,  2224,  2224,
    1423,   573,  2224,   575,   597,   601,  1423,   611,   621,   615,
     625,   633,   636,   640,   773,   346,   346,   346,  2224,  2224,
     -51, -1030,   -15,   346,   668,   669,   678,  2025,   -11,  1423,
    1423,   662,    36,   686, -1030,   818, -1030,   705,   726,   736,
     865,  2224,  2224,  2224,   748,  2224,   751,   797,  2224,  2224,
   -1030,  2224,   888, -1030,   418, -1030, -1030,   889, -1030, -1030,
     890,   764,  2224,   895,   762, -1030, -1030,   896,  2224,  2224,
    2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,
    2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,
    2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,
    2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,
     490,   490,   490,   490,  2224,   898,   520,   774,   774,   774,
    5138,    51,  2156,  4402,   169,   768,   905,   779,   775, -1030,
     777,  2941,  1649, -1030, -1030,  2224,  2224,  2224,  2224,  2224,
    2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,  2224,
   -1030, -1030,  1968,   -13,  2088,  5159,   622,   776,  2156, -1030,
   -1030,  2571, -1030,   592,  5180,  5201,  2224,  5222,   608,  5243,
    5264,  2224,   626,  5285,  5306,  1554,  1237,  2591,   911, -1030,
    2224,  5327,  2224,  2224,  2224,   912,  2224,  2224,  2224,  2281,
    2281,  2281,  2281,   788,   420, -1030, -1030,  3674,  3700,   346,
     346,    30,    30,   426,  2224,  2224,  2224,  2025,  2025,  2224,
    2941,   437, -1030,    63,   915,  2224,   919, -1030,  2224,  2224,
     942, -1030,  2156,  2224,  2224, -1030,  5348,  5369,  5390,   836,
    3726, -1030,   789,  2610,  5411,  4425, -1030,  2224,   926,  1054,
   -1030,  1279, -1030,  2224,  4448,    31,  2224,     3, -1030,  5432,
    4471,  5453,  4494,  5474,  4517,  5495,  4540,  5516,  4563,  5537,
    4586,  5558,  4609,  5579,  4632,  5600,  4655,  5621,  4678,  5642,
    4701,  3752,  3778,  5663,  4724,  5684,  4747,  5705,  4770,  5726,
    4793,  5747,  4816,  5768,  4839,  3804,  3830,  3856,  3882,  3908,
    3934,   234,   793,   799,   800,  2310,   798,  2224, -1030,  1423,
    1423,   631,   265,   508,  2224,   929,   933,    19,   803, -1030,
     175,   127,   -34,   249, -1030, -1030,  2629,   562,   757,   618,
     618,   540,   540,   540,   540,   582,   582,   774,   774,   774,
     774, -1030,    14,  2156,  2224,   932,  1990,  2224,   774, -1030,
    2224,  2156,  2156,   846,   936,   937,  5789,   938,   852,   944,
     945,  5810,   855,   946,   949,  2156, -1030,   635,  1685,  2224,
    5831,   950,  2701,  5852,  5873,  2224,  2976,  3004,  5894,   825,
    6146, -1030,   826,   827,   828,   830,   346,  2224,  2224, -1030,
   -1030,   822,   823,  2224,  3960,  3986,  4012,  3648,   196,   346,
    1592, -1030,  2224,  2224,  5915, -1030,  4862,  4885, -1030,   655,
    4908,  4931,   957,   961,   962,   834,  2224,  1847,  2224,  2224,
   -1030,    17,  4954, -1030, -1030, -1030,  4977,    39, -1030,  3032,
   -1030,   839,   841,   837, -1030,   968, -1030, -1030, -1030, -1030,
   -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030,
   -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030,
   -1030, -1030, -1030,  2224,  2224, -1030, -1030, -1030, -1030, -1030,
   -1030, -1030, -1030, -1030, -1030, -1030, -1030,  2224,  2224,  2224,
    2224,  2224,  2224, -1030,  2156,   490, -1030, -1030, -1030,  2224,
    5000,   969,   971,   844, -1030,    10,  2224,   976,   977,  2331,
   -1030,   988,   850,    15,   994, -1030,  2156,  2156,  2156,  2156,
    2224, -1030,   884,   490,   253,  4038,   346, -1030,  2156,  3060,
    2648,   774, -1030,  2571, -1030,   955,  1423,  1423,   998,  1423,
     523,  1423,  1423,   999,   956,  1423,  1423,   660, -1030,  2156,
    2351,  1001,   870,  1008,  1009,  1011,   920,  1014,  1016,  1017,
    1018,  1020,  1025,  1040,  1044,   440,  4064,  4090, -1030, -1030,
    3088,   346,   346,   346,  1043,   913,   918,   -30, -1030,   461,
   -1030,   196,  2370,  2389,   914,  1048,  1050,  1006,  1052,  1056,
    1423,  1423,  1423,  1060,  4116, -1030,  2671,  1049,  1064,  1065,
     924,  1067,  1066, -1030,  1068, -1030,   939,  2224,  2224,  1423,
     940, -1030,  5936,  5023,  5957,  5046,  5978,  5069,  5999,  5092,
     286,   943,  6020,   -56, -1030, -1030,   102,   361,   941,  1071,
    2408, -1030, -1030, -1030,    15,  2224, -1030,   661, -1030,   664,
     665,   675,   676,  6146, -1030,  1069,    40,  2224,    50,   683,
   -1030,  2224,   947,    27,    48,  1423,  1077,   951,   953,  1078,
    1079,  1423,   954,  1082,  1083, -1030,   689, -1030,  1090,  2224,
    1423,  1423,  1423, -1030,   531,  1423,  1423,  1423,  1423,  1423,
    1423,  1423,   318,  2224,  2224,  2224,   970,   179,   280,   398,
   -1030,  1423,  2224, -1030, -1030,  2025,   123, -1030, -1030,  2156,
   -1030, -1030,   973, -1030, -1030,  1109,  1111,  1028, -1030,  2224,
    2224,  2224, -1030,  1113,  1114,  1116, -1030,    31, -1030,  2224,
    4142,  4168,   690, -1030,  2224, -1030, -1030, -1030, -1030, -1030,
   -1030, -1030, -1030, -1030, -1030, -1030,  1423,   508,  2224,  1117,
    1118,    19, -1030,  1119,  5115,    15, -1030,  1120,  1122,  1123,
    1126, -1030, -1030,   490,  4194, -1030,   989,  6146,  2224, -1030,
     346, -1030,   346,  1129, -1030,  2224,  2224, -1030, -1030,  1130,
    2224, -1030, -1030, -1030,  1133,  4220,  1137,  1138,  1045,  2224,
    2224,   835,  1140,  1141,  1143,  1144,  1145,  1146, -1030,  2281,
    3116,  6041,  2892,    30,   346,  1147,   346,  1148,   346,  1149,
     312,  1019,  6062,  3144,   467, -1030,   702,  2224, -1030, -1030,
    1423,  2920,   666,  6083, -1030,  1816, -1030, -1030,   381,  6146,
    2224,  2224,  1423,  1021,   707,  6146,  1150,  1152,  2431, -1030,
    1169,  1171, -1030,  1042, -1030, -1030, -1030, -1030, -1030,  1175,
    2224, -1030,  3172,    59,    62, -1030,  3200,  3228, -1030,  3256,
    1178,  2224, -1030, -1030,  1139,  1179,  2452,  2472,  1181, -1030,
   -1030, -1030, -1030, -1030, -1030, -1030,  2491,  1182,  1051, -1030,
    2224, -1030,  1053,   469, -1030,  1057,   474, -1030,  1058,   500,
   -1030,  1059,  1183,  1423,  1177,  1061,  2224,  1185,  3284,  1103,
    2224, -1030,  2224, -1030, -1030,  2156,  2510,  1189, -1030,  2224,
    4246,  4272, -1030,  1423,  2224,  1196, -1030, -1030, -1030,    15,
   -1030,  1112, -1030,  4298,  1197, -1030, -1030,  1199,  1200,  1201,
    1202,  4324,  1070, -1030, -1030, -1030, -1030, -1030, -1030,    30,
    2948, -1030,  2025,   196,  2025,   196,  2025,   196, -1030,   714,
    1423, -1030,  3312, -1030, -1030,  2224,  3340,  3368,   715, -1030,
   -1030,  1072,  6146,  2224,  2224,   718,  6146, -1030,  1206, -1030,
    2224, -1030, -1030, -1030, -1030, -1030,  1208,  2224,  1088,  2224,
   -1030,  3396,   502,   233,  3424,   513,   238,  3452,   519,   271,
    1423,  1223,  1170,  2018,  1091,  2529, -1030, -1030,  1228,  2224,
    6104,  4350,     9, -1030,  4376,  1098,  3480, -1030,  3508,  1232,
    2224,  1233,  1236,  2224,  1238,  1239,  2224,  1243,  1110, -1030,
    2224, -1030,   196, -1030, -1030, -1030,   719, -1030,  2224, -1030,
    1423,  2224,  1267, -1030, -1030, -1030,  1104,  3536, -1030, -1030,
    1134,  3564, -1030, -1030,  1135,  3592, -1030,  1269,  2552,   321,
    2323,  1270,  1142,  6125,   723,  3620,  1151,   196,  1271,   196,
    1272,   196,  1273, -1030, -1030, -1030, -1030,   196, -1030,   490,
   -1030,  1154,  1276,  1278,   335, -1030,  1155,   337, -1030,  1156,
     339, -1030,  1157,   368,   728, -1030,  1158,  1423, -1030,  1159,
    1280,   196,  1282,   196,  1284,   196, -1030,   490,  1292,   490,
     729,  1294, -1030,   370, -1030,   378, -1030,   382, -1030, -1030,
     749, -1030,  1295, -1030,  1301,  1302,  1303,   490,  1305, -1030,
   -1030, -1030, -1030, -1030, -1030
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1030, -1030, -1030, -1030,   509, -1030, -1030, -1030, -1030,   193,
   -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030,
   -1030, -1030,  -253,     2, -1030,   124, -1030,  1281,     6,  -350,
    -171, -1030, -1030, -1030, -1030, -1030,  1311, -1030, -1030, -1030,
   -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030, -1030,
    -680,  -500, -1030, -1030, -1030,    -3, -1030,   309, -1030, -1029,
     -90,   262,   185,  -617,   444, -1030,   -58,     5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     210,   531,   532,   128,  1085,   134,   360,   570,   127,    64,
     151,   130,   274,   370,   757,  1149,     5,   204,   205,   194,
     651,   454,   146,   642,   728,   211,   766,   132,   197,   204,
     205,   826,   182,   889,   278,   389,   146,   185,   391,   186,
     366,   704,   367,   204,   205,   131,   882,   705,   706,   102,
     103,   104,   105,   133,   891,   106,   885,   218,   449,   219,
     328,   102,   103,   104,   105,  1045,   335,   106,  1046,   541,
     542,   349,   350,   119,   120,   102,   103,   104,   105,     4,
     732,   106,   217,   890,   571,   572,   573,   574,   351,   363,
     364,   147,   220,   152,   221,    30,    31,    32,    33,   275,
     276,   758,   759,    37,   892,   648,    40,   349,   350,   634,
     823,   349,   350,   267,   268,   269,   136,   141,   270,   273,
     482,  1174,   139,   282,   352,   483,   140,   183,   362,   302,
     144,   279,   304,   652,   305,   311,   314,   315,   135,   317,
     311,   319,   320,   575,   311,   323,   324,   873,  1150,   331,
     119,   120,   206,   729,   195,   212,   198,   213,   643,   652,
     119,   120,   214,   450,   209,   347,   348,   184,   119,   120,
     368,   150,   349,   350,   348,   732,   453,   145,  1220,   142,
     153,   349,   350,   154,   349,   350,   143,   148,   376,   377,
     378,   540,   380,   149,   704,   383,   384,   141,   385,   636,
     705,   706,   441,   442,   443,   444,   222,   824,   223,   394,
     557,   112,   113,   114,   115,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   137,   964,   142,
     155,   445,   160,   935,   138,   161,   647,   704,   162,   311,
     163,   159,   634,   705,   706,   224,   455,   225,   112,   113,
     114,   115,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   164,   119,   120,
     174,   349,   350,   175,   704,   488,   176,   137,   179,   704,
     705,   706,   165,   496,   646,   705,   706,   924,   501,   925,
     490,   173,   488,   311,   918,   919,   824,   510,   318,   512,
     513,   514,   322,   516,   517,   518,   520,   520,   520,   520,
     170,   172,   704,   178,   521,   521,   521,   521,   705,   706,
     180,   534,   535,   536,   267,   268,   537,   279,   279,   631,
     632,   226,   544,   227,   188,   546,   547,   623,   867,   311,
     550,   551,   624,  1131,   112,   113,   114,   115,  1134,   166,
     167,   149,   181,  1103,   562,  1106,   776,  1109,   649,   168,
     566,   492,   704,   569,   119,   120,   177,   568,   705,   706,
     312,   635,   349,   350,   187,   312,   704,   189,   704,   312,
     704,  1137,   705,   706,   705,   706,   705,   706,   926,   863,
     927,   228,  1088,   229,   492,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   508,   297,   298,   704,
     230,   704,   231,   299,   630,   705,   706,   705,   706,   704,
     190,   639,  1012,   704,   637,   705,   706,   451,   638,   705,
     706,  1185,  1169,   191,   522,   523,   524,   201,   166,   167,
     112,   113,   114,   115,   344,  1210,   346,  1212,   168,  1214,
     311,   655,   353,   630,   659,   169,   361,   660,   661,   663,
     119,   120,   200,   156,   204,   205,   157,  1194,   158,  1197,
     202,  1200,   311,   866,   868,   661,   680,  1203,  1216,   734,
    1234,   507,   686,   205,  1028,   232,   192,   233,  1235,  1029,
     349,   350,  1236,   193,   696,   697,   102,   103,   104,   105,
     700,  1223,   106,  1225,   312,  1227,   928,   199,   929,   712,
     713,   203,   349,   350,   102,   103,   104,   105,   349,   350,
     106,   216,   387,   724,   388,   726,   727,   549,   526,   349,
     350,   260,   349,   350,   533,   261,   234,   751,   235,   733,
     489,   262,   787,  1002,   788,   539,   783,   784,   813,   786,
     263,   789,   790,   349,   350,   793,   794,   489,   312,   349,
     350,   349,   350,   909,   910,   775,   349,   350,   264,   825,
     742,   743,   236,   824,   237,  1016,   824,  1062,   238,   824,
     239,   240,  1064,   241,   744,   745,   746,   747,   748,   749,
     265,   311,   349,   350,   349,   350,   752,   242,   277,   243,
     835,   836,   837,   760,   312,   349,   350,   244,  1066,   245,
    1130,   349,   350,   311,   311,   311,   311,   773,   283,   119,
     120,  1133,   300,   301,   447,   311,   213,  1136,   529,   530,
     316,   214,   294,   295,   296,   297,   298,   346,   654,   824,
     246,   299,   247,   248,  1022,   249,   311,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   250,
     677,   251,   303,   299,   824,   893,   252,   824,   253,   321,
     824,   899,   254,   824,   255,   330,   296,   297,   298,  1098,
     906,   907,   908,   299,   332,   911,   912,   913,   914,   915,
     916,   917,   256,   824,   257,   824,   258,   824,   259,   333,
     492,   931,   493,   334,   850,   851,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   312,   492,   338,   498,   299,
     336,   119,   120,   662,   664,   733,   486,   339,   213,   869,
     337,   125,   874,   214,   492,   340,   502,   312,   341,   492,
     662,   633,   342,   492,   884,   678,   956,   343,   887,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   492,   365,   717,   905,   299,   492,   875,
     795,   876,   492,   492,   877,   878,  1023,   354,   355,   750,
     920,   921,   922,   492,   492,   879,   880,   356,   930,   932,
     369,   492,   933,   886,   371,   969,   311,   492,   952,   903,
     953,   769,   770,   771,   772,   695,   941,   942,   943,   988,
     492,   989,  1017,   779,   372,  1034,   949,  1035,   709,   947,
    1019,   955,  1110,   492,  1111,  1118,   952,  1034,  1122,  1171,
     373,   952,  1032,  1191,   796,   958,  1217,   952,  1218,  1232,
     374,   375,   957,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   379,   972,   312,  1237,   299,  1238,
     381,   382,   976,   977,   386,   390,   392,   979,   393,   395,
    1113,   396,   398,   446,   456,   299,   986,   987,   312,   312,
     312,   312,   457,   458,   125,   487,   996,   459,   509,   515,
     312,   525,   543,  1069,   997,   545,   803,   555,   558,   279,
     563,   625,   626,   627,  1018,   640,   629,   641,   645,   656,
     665,   312,  1026,   666,   667,   669,   670,  1030,  1031,   674,
    1027,   671,   672,   675,     7,     8,   676,   682,   690,   691,
     692,   693,   698,   699,   720,   778,   694,  1043,   721,   722,
     723,   737,  1170,   738,   741,   754,   739,   755,  1051,   756,
    1112,   804,   761,   762,   765,   460,    13,    14,   461,    16,
      17,   462,    19,   463,    21,   764,    22,  1060,    24,    25,
     768,    27,    28,   774,   782,   785,   791,   792,   798,   799,
     817,   818,   819,  1072,   936,   800,   801,  1076,   802,  1077,
    1138,   805,   311,   806,   807,   808,  1082,   809,    44,    45,
      46,  1086,   810,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   811,   812,   820,
     822,   299,   821,   829,   830,   832,   831,   841,   833,  1101,
     845,  1104,   834,  1107,   838,   279,     7,     8,   843,   844,
     847,   849,  1115,   846,   848,   881,   864,   870,   871,   854,
    1120,  1121,   548,   894,   897,   898,   888,  1124,   901,   902,
     895,   312,   896,   900,  1126,   904,  1128,   460,    13,    14,
     461,    16,    17,   462,    19,   463,    21,   284,    22,   923,
      24,    25,   937,    27,    28,   938,   955,   939,   940,   944,
     946,   945,   960,   959,   971,   962,   965,  1157,   966,   967,
    1161,  1205,   968,  1165,   934,   975,   978,  1168,   980,   984,
      44,    45,    46,   982,   983,  1173,   990,   991,  1175,   992,
     993,   994,   995,  1004,  1007,  1010,  1036,  1013,  1037,  1228,
    1033,  1231,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,  1039,  1040,  1041,  1243,
     299,  1042,   842,  1050,  1070,  1053,  1052,  1056,  1058,  1068,
    1059,  1073,  1075,  1061,   564,  1080,  1063,  1065,  1067,   973,
    1071,   974,  1087,  1091,  1089,  1092,  1093,  1094,  1095,  1097,
    1078,  1119,  1123,  1125,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,  1127,  1139,
    1143,  1140,   299,  1003,  1145,  1006,  1152,  1009,  1155,  1158,
      74,   306,  1159,  1177,  1162,  1163,    78,    79,    80,  1166,
    1167,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,  1176,  1179,  1181,  1183,  1188,  1195,  1198,  1201,
     307,  1189,  1208,  1209,    63,   883,  1222,   312,  1224,  1193,
    1226,     7,     8,  1207,  1211,  1213,  1215,  1219,  1229,  1221,
    1233,  1239,    30,    31,    32,    33,    34,  1240,  1241,  1242,
      37,  1244,  1146,    40,    70,   961,     0,     0,     0,     0,
       0,     0,   460,    13,    14,   461,    16,    17,   462,    19,
     463,    21,     0,    22,     0,    24,    25,     0,    27,    28,
       0,     0,   108,   109,   110,   111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
     308,     0,     0,     0,   118,    44,    45,    46,     0,   121,
       0,  1102,     0,  1105,   124,  1108,     0,   506,    74,    75,
      76,     0,    77,     0,    78,    79,    80,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
       0,   102,   103,   104,   105,     0,     0,   106,     0,   565,
       0,     0,     0,     0,     0,     0,    74,   306,     0,     0,
       0,     0,    78,    79,    80,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,   307,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,    30,    31,
      32,    33,    34,     0,     0,     0,    37,   116,   117,    40,
       0,     0,   118,     0,   119,   120,     0,   121,     0,   122,
       0,   123,   124,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,   109,
     110,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   116,   325,     0,     0,     0,
     118,     0,     0,     0,     0,   121,     0,    74,   306,     0,
     124,     0,   326,    78,    79,    80,     0,     0,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,   307,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      31,    32,    33,    34,     0,     0,     0,    37,     0,     0,
      40,     0,     0,     0,     0,   460,    13,    14,   461,    16,
      17,   462,    19,   463,    21,     0,    22,     0,    24,    25,
       0,    27,    28,     0,     0,   465,     0,     0,     0,   108,
     109,   110,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,   308,    44,    45,
      46,   118,     0,     0,     0,     0,   121,     0,    74,   306,
       0,   124,     0,   505,    78,    79,    80,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
       0,     0,     0,     0,     0,     0,     0,     0,   307,     0,
       0,     0,   710,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      30,    31,    32,    33,    34,     0,     0,     0,    37,     0,
       0,    40,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,   109,   110,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   308,     0,
       0,     0,   118,     0,     0,     0,     0,   121,     0,    74,
     266,   205,   124,     0,   679,    78,    79,    80,     0,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,     0,   102,   103,   104,   105,    74,   266,   106,     7,
       8,     0,    78,    79,    80,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,     0,     0,
     460,    13,    14,   461,    16,    17,   462,    19,   463,    21,
       0,    22,     0,    24,    25,     0,    27,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,   109,   110,   111,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    45,    46,     0,     0,   116,   117,
       0,     0,     0,   118,     0,     0,     0,     0,   121,     0,
       0,     0,     0,   124,     0,  1025,     0,     0,   108,   109,
     110,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   481,   116,   117,     0,     0,     0,
     118,     0,     0,     0,     0,   121,     0,   725,   271,     0,
     124,     0,   272,    74,   266,     0,     0,     0,     0,    78,
      79,    80,     0,     0,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,     0,     0,     0,    74,   266,
       7,     8,     0,     0,    78,    79,    80,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
       0,   460,    13,    14,   461,    16,    17,   462,    19,   463,
      21,     0,    22,     0,    24,    25,     0,    27,    28,     0,
       0,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   108,   109,   110,   111,   299,
       0,     0,     0,     0,    44,    45,    46,     0,     0,     0,
       0,     0,   116,   117,     0,     0,     0,   118,     0,     0,
       0,     0,   121,     0,     0,   657,     0,   124,     0,   658,
     108,   109,   110,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   357,   358,     0,
       0,     0,   118,     0,     0,     0,     0,   359,  1141,    74,
     306,     0,   124,     0,   169,    78,    79,    80,     0,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,   307,
       0,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,    30,    31,    32,    33,    34,   484,    74,   266,    37,
       0,     0,    40,    78,    79,    80,     0,     0,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,     0,
       0,   108,   109,   110,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116,   308,
       0,     0,     0,   118,    74,   266,   205,     0,   121,     0,
      78,    79,    80,   124,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   628,   102,   103,   104,
     105,     0,     0,   106,     0,     0,     0,     0,     0,   108,
     109,   110,   111,     0,     0,     7,     8,   763,     0,     0,
       0,     0,     0,     0,     0,     0,   116,   117,     0,     0,
       0,   118,     0,     0,     0,     0,   121,   797,     0,     0,
       0,   124,     0,     0,     0,     0,   460,    13,    14,   461,
      16,    17,   462,    19,   463,    21,   827,    22,     0,    24,
      25,     0,    27,    28,     0,     0,   108,   109,   110,   111,
       0,     0,     0,     0,     0,   828,     0,     0,     0,     0,
       0,     0,     0,   116,   117,     0,     0,     0,   118,    44,
      45,    46,     0,   121,   872,     0,     0,     0,   124,     0,
       0,     0,     0,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,  1038,     0,     0,
       0,   299,     0,     0,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,  1054,     0,
       0,     0,   299,  1186,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,  1055,     0,
       0,     0,   299,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,  1057,     0,     0,
       0,   299,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,  1079,     0,     0,     0,
     299,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,  1144,     0,     0,     0,   299,
       0,     0,     0,     0,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,  1184,     0,
       0,     0,   299,     0,     0,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   490,
       0,     0,     0,   299,     0,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   490,
       0,     0,     0,   299,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   559,     0,
       0,     0,   299,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   650,     0,     0,
       0,   299,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   781,     0,     0,     0,
     299,     0,     0,     0,     0,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   840,
       0,     0,     0,   299,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   491,   297,   298,     0,     0,
       0,     0,   299,     0,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   508,   297,   298,     0,     0,
       0,     0,   299,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,     0,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,    -4,
       1,     0,   299,    -4,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,     0,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,    -4,     0,     0,     0,     0,    -4,
      -4,   683,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,
       6,     0,     0,     0,    -4,    -4,    -4,    -4,     7,     8,
      -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     0,     0,     0,     0,
       0,     9,     0,     0,     0,     0,    10,    11,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,     7,     8,    41,    42,     0,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    47,     0,    48,
       0,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     0,     0,     0,   460,    13,    14,   461,    16,    17,
     462,    19,   463,    21,     0,    22,     0,    24,    25,     0,
      27,    28,     0,     0,     0,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,    44,    45,    46,
    1000,     0,  1001,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,  1020,     0,
    1021,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,     0,     0,     0,  1099,     0,  1100,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,     0,     0,     0,     0,     0,   687,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,     0,     0,   688,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,     0,     0,     0,
       0,     0,   735,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,     0,     0,
     780,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,     0,     0,     0,     0,     0,   816,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,     0,     0,     0,     0,     0,   998,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,     0,     0,  1015,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,     0,     0,     0,
       0,     0,  1044,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,     0,     0,
    1047,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,     0,     0,     0,     0,     0,  1048,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,     0,     0,     0,     0,     0,  1049,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,     0,     0,  1074,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,     0,     0,     0,
       0,     0,  1114,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,     0,     0,
    1116,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,     0,     0,     0,     0,     0,  1117,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,     0,     0,     0,     0,     0,  1129,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,     0,     0,  1132,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,     0,     0,     0,
       0,     0,  1135,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,     0,     0,
    1153,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,     0,     0,     0,     0,     0,  1154,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,     0,     0,     0,     0,     0,  1178,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,     0,     0,  1180,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,     0,     0,     0,
       0,     0,  1182,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,     0,     0,
    1192,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,   448,     0,     0,     0,     0,   527,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,   527,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,   528,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,     0,     0,     0,   556,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,     0,     0,     0,
     603,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,     0,     0,     0,   604,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,   617,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,   618,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,     0,     0,     0,   619,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,     0,     0,     0,
     620,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,     0,     0,     0,   621,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,   622,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,   701,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,     0,     0,     0,   702,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,     0,     0,     0,
     703,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,     0,     0,     0,   777,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,   814,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,   815,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,     0,     0,     0,   839,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,     0,     0,     0,
     950,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,     0,     0,     0,   951,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,   970,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,   981,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,     0,     0,     0,  1083,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,     0,     0,     0,
    1084,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,     0,     0,     0,  1090,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,  1096,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,  1148,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,     0,     0,     0,  1151,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,   452,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
     561,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,   567,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,   582,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,   584,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,   586,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,   588,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,   590,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,   592,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,   594,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,   596,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
     598,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,   600,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,   602,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,   606,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,   608,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,   610,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,   612,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,   614,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,   616,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,   715,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
     716,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,   718,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,   719,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,   730,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,   731,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,   753,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,   856,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,   858,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,   860,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,   862,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
     963,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,   448,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,   485,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,   494,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,   495,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,   497,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,   499,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,   500,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,   503,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,   504,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
     511,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,   552,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,   553,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,   554,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,   560,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,   581,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,   583,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,   585,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,   587,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,   589,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
     591,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,   593,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,   595,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,   597,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,   599,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,   601,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,   605,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,   607,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,   609,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,   611,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
     613,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,   615,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,   668,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,   673,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,   681,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,   684,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,   685,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,   689,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,   714,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,   855,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
     857,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,   859,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,   861,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,   865,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,   999,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,  1014,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,  1024,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,  1147,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,  1190,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299
};

static const yytype_int16 yycheck[] =
{
      58,   351,   352,     6,  1033,     6,   177,     4,     6,     3,
      49,     6,     4,   184,     4,     6,     0,     4,     5,     4,
       6,   274,    70,     4,     7,     4,   643,    49,     4,     4,
       5,   711,     4,     6,     4,   206,    70,     4,   209,     6,
       4,    71,     6,     4,     5,    13,     6,    77,    78,    36,
      37,    38,    39,   132,     6,    42,     6,   132,     7,   134,
     150,    36,    37,    38,    39,     6,   156,    42,     6,     6,
       7,   122,   123,   129,   130,    36,    37,    38,    39,     6,
     136,    42,    77,    56,    81,    82,    83,    84,   139,   179,
     180,   139,   132,   132,   134,    65,    66,    67,    68,    91,
      92,    91,    92,    73,    56,   139,    76,   122,   123,     7,
     140,   122,   123,   116,   117,   118,     6,    70,   121,   122,
     133,  1150,   132,   126,   139,   138,   132,    99,   139,   132,
     132,   125,   135,   119,   137,   138,   139,   140,   139,   142,
     143,   144,   145,   140,   147,   148,   149,   764,   139,   152,
     129,   130,   139,   136,   139,   134,   132,   136,   139,   119,
     129,   130,   141,   112,   139,   168,   169,   139,   129,   130,
     134,    53,   122,   123,   177,   136,     7,   132,  1207,   132,
      49,   122,   123,    49,   122,   123,   139,   132,   191,   192,
     193,   362,   195,   132,    71,   198,   199,    70,   201,   452,
      77,    78,   260,   261,   262,   263,   132,   707,   134,   212,
     381,   109,   110,   111,   112,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   132,   875,   132,
      49,   264,    43,   140,   139,    46,   139,    71,    49,   272,
      51,    51,     7,    77,    78,   132,   274,   134,   109,   110,
     111,   112,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   132,   129,   130,
      43,   122,   123,    46,    71,   308,    49,   132,    49,    71,
      77,    78,   139,   316,   139,    77,    78,   138,   321,   140,
       8,   139,   325,   326,     6,     7,   826,   330,   143,   332,
     333,   334,   147,   336,   337,   338,   339,   340,   341,   342,
      31,    32,    71,    34,   339,   340,   341,   342,    77,    78,
      49,   354,   355,   356,   357,   358,   359,   351,   352,   449,
     450,   132,   365,   134,     4,   368,   369,   133,     7,   372,
     373,   374,   138,   140,   109,   110,   111,   112,   140,   122,
     123,   132,    46,  1063,   387,  1065,   133,  1067,   139,   132,
     393,   138,    71,   396,   129,   130,   139,   395,    77,    78,
     138,   136,   122,   123,    46,   143,    71,     4,    71,   147,
      71,   140,    77,    78,    77,    78,    77,    78,   138,   133,
     140,   132,  1039,   134,   138,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    71,
     132,    71,   134,   131,   447,    77,    78,    77,    78,    71,
       4,   454,   140,    71,   452,    77,    78,   272,   453,    77,
      78,   140,  1142,   132,   340,   341,   342,   134,   122,   123,
     109,   110,   111,   112,   165,   140,   167,   140,   132,   140,
     483,   484,   173,   486,   487,   139,   177,   490,   491,   492,
     129,   130,     6,    46,     4,     5,    49,  1177,    51,  1179,
       4,  1181,   505,   756,   757,   508,   509,  1187,   140,   567,
     140,   326,   515,     5,   133,   132,   132,   134,   140,   138,
     122,   123,   140,   132,   527,   528,    36,    37,    38,    39,
     533,  1211,    42,  1213,   272,  1215,   138,   132,   140,   542,
     543,     4,   122,   123,    36,    37,    38,    39,   122,   123,
      42,   139,   134,   556,   136,   558,   559,   372,   138,   122,
     123,   132,   122,   123,   138,   132,   132,   625,   134,   567,
     308,   132,    49,   923,    51,   138,   666,   667,   138,   669,
     132,   671,   672,   122,   123,   675,   676,   325,   326,   122,
     123,   122,   123,    62,    63,   653,   122,   123,     7,   138,
     603,   604,   132,  1103,   134,   138,  1106,   138,   132,  1109,
     134,   132,   138,   134,   617,   618,   619,   620,   621,   622,
     132,   624,   122,   123,   122,   123,   629,   132,     4,   134,
     720,   721,   722,   636,   372,   122,   123,   132,   138,   134,
     138,   122,   123,   646,   647,   648,   649,   650,     6,   129,
     130,   138,     6,     6,   134,   658,   136,   138,   349,   350,
     132,   141,   122,   123,   124,   125,   126,   358,   483,  1169,
     132,   131,   134,   132,     8,   134,   679,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   132,
     505,   134,     5,   131,  1194,   785,   132,  1197,   134,   132,
    1200,   791,   132,  1203,   134,   132,   124,   125,   126,  1059,
     800,   801,   802,   131,   139,   805,   806,   807,   808,   809,
     810,   811,   132,  1223,   134,  1225,   132,  1227,   134,   132,
     138,   821,   140,   132,   737,   738,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   483,   138,   132,   140,   131,
     139,   129,   130,   491,   492,   753,   134,   132,   136,   757,
     139,   139,   765,   141,   138,   132,   140,   505,   132,   138,
     508,   140,   132,   138,   777,   140,   866,     4,   781,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   138,   132,   140,   799,   131,   138,   138,
     140,   140,   138,   138,   140,   140,   140,   139,   139,   624,
     813,   814,   815,   138,   138,   140,   140,   139,   821,   822,
     134,   138,   825,   140,     6,   883,   829,   138,   138,   140,
     140,   646,   647,   648,   649,   526,   839,   840,   841,     4,
     138,     6,   140,   658,   139,   138,   849,   140,   539,   847,
     940,   854,   138,   138,   140,   140,   138,   138,   140,   140,
     134,   138,   952,   140,   679,   868,   138,   138,   140,   140,
     134,     6,   867,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   136,   888,   624,   138,   131,   140,
     139,    94,   895,   896,     6,     6,     6,   900,   134,     4,
    1071,   139,     6,     5,   136,   131,   909,   910,   646,   647,
     648,   649,     7,   134,   139,   139,   919,   140,     7,     7,
     658,   133,     7,  1013,   919,     6,     6,    91,   139,   923,
       4,   138,   133,   133,   937,     6,   138,     4,   135,     7,
      94,   679,   945,     7,     7,     7,    94,   950,   951,    94,
     945,     7,     7,     7,    12,    13,     7,     7,   133,   133,
     133,   133,   140,   140,     7,   656,   136,   970,     7,     7,
     136,   132,  1143,   132,     6,     6,   139,     6,   981,   135,
    1070,    61,     6,     6,   134,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     7,    54,  1000,    56,    57,
       6,    59,    60,   119,    49,     7,     7,    51,     7,   139,
     701,   702,   703,  1016,   829,     7,     7,  1020,     7,  1022,
    1110,     7,  1025,     7,     7,     7,  1029,     7,    86,    87,
      88,  1034,     7,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     7,     4,     6,
     132,   131,   139,   139,     6,    49,     6,     8,     6,  1062,
     136,  1064,     6,  1066,     4,  1059,    12,    13,     4,     4,
       4,   132,  1075,     6,     6,     6,   133,   136,     7,   139,
    1083,  1084,   140,     6,     6,     6,   139,  1090,     6,     6,
     139,   829,   139,   139,  1097,     5,  1099,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     6,    54,   139,
      56,    57,   139,    59,    60,     6,  1119,     6,    90,     6,
       4,     7,     4,     6,   135,     6,     6,  1130,     6,     6,
    1133,  1189,     6,  1136,   825,     6,     6,  1140,     5,    94,
      86,    87,    88,     6,     6,  1148,     6,     6,  1151,     6,
       6,     6,     6,     6,     6,     6,     6,   138,     6,  1217,
     139,  1219,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     7,     6,   136,  1237,
     131,     6,   133,     5,     7,     6,    47,     6,     6,     6,
     139,     6,    89,   140,   140,     6,   139,   139,   139,   890,
     139,   892,     6,     6,    92,     6,     6,     6,     6,   139,
    1025,   139,     6,     5,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   140,     6,
     139,    61,   131,   924,     6,   926,   138,   928,     6,     6,
       3,     4,     6,   139,     6,     6,     9,    10,    11,     6,
     140,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     5,   139,   139,     6,     6,     6,     6,     6,
      43,   139,     6,     5,     3,   776,     6,  1025,     6,   138,
       6,    12,    13,   139,   139,   139,   139,   139,     6,   140,
       6,     6,    65,    66,    67,    68,    69,     6,     6,     6,
      73,     6,  1119,    76,     3,   871,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    -1,    56,    57,    -1,    59,    60,
      -1,    -1,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,    -1,    -1,    -1,   127,    86,    87,    88,    -1,   132,
      -1,  1062,    -1,  1064,   137,  1066,    -1,   140,     3,     4,
       5,    -1,     7,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    38,    39,    -1,    -1,    42,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,   110,   111,   112,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    73,   122,   123,    76,
      -1,    -1,   127,    -1,   129,   130,    -1,   132,    -1,   134,
      -1,   136,   137,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,    -1,    -1,    -1,
     127,    -1,    -1,    -1,    -1,   132,    -1,     3,     4,    -1,
     137,    -1,   139,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    73,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    -1,    56,    57,
      -1,    59,    60,    -1,    -1,     6,    -1,    -1,    -1,   105,
     106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    86,    87,
      88,   127,    -1,    -1,    -1,    -1,   132,    -1,     3,     4,
      -1,   137,    -1,   139,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    73,    -1,
      -1,    76,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,    -1,   127,    -1,    -1,    -1,    -1,   132,    -1,     3,
       4,     5,   137,    -1,   139,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,     3,     4,    42,    12,
      13,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    -1,    56,    57,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    -1,    -1,   122,   123,
      -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,   132,    -1,
      -1,    -1,    -1,   137,    -1,   139,    -1,    -1,   105,   106,
     107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,   122,   123,    -1,    -1,    -1,
     127,    -1,    -1,    -1,    -1,   132,    -1,   140,   135,    -1,
     137,    -1,   139,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,     3,     4,
      12,    13,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    -1,    56,    57,    -1,    59,    60,    -1,
      -1,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   105,   106,   107,   108,   131,
      -1,    -1,    -1,    -1,    86,    87,    88,    -1,    -1,    -1,
      -1,    -1,   122,   123,    -1,    -1,    -1,   127,    -1,    -1,
      -1,    -1,   132,    -1,    -1,   135,    -1,   137,    -1,   139,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,    -1,   127,    -1,    -1,    -1,    -1,   132,   140,     3,
       4,    -1,   137,    -1,   139,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    65,    66,    67,    68,    69,   138,     3,     4,    73,
      -1,    -1,    76,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,   105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,
      -1,    -1,    -1,   127,     3,     4,     5,    -1,   132,    -1,
       9,    10,    11,   137,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     6,    36,    37,    38,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,    -1,    -1,    12,    13,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,    -1,
      -1,   127,    -1,    -1,    -1,    -1,   132,     6,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     6,    54,    -1,    56,
      57,    -1,    59,    60,    -1,    -1,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,    -1,    -1,    -1,   127,    86,
      87,    88,    -1,   132,     6,    -1,    -1,    -1,   137,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     6,    -1,    -1,
      -1,   131,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     6,    -1,
      -1,    -1,   131,   140,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     6,    -1,
      -1,    -1,   131,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     6,    -1,    -1,
      -1,   131,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     6,    -1,    -1,    -1,
     131,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,     6,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     6,    -1,
      -1,    -1,   131,    -1,    -1,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,     8,
      -1,    -1,    -1,   131,    -1,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,     8,
      -1,    -1,    -1,   131,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     8,    -1,
      -1,    -1,   131,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     8,    -1,    -1,
      -1,   131,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     8,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,     8,
      -1,    -1,    -1,   131,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,   131,    -1,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,   131,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
     131,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,     0,
       1,    -1,   131,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,   131,    -1,    35,    -1,    -1,    -1,    -1,    40,
      41,   140,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    -1,    -1,    79,    80,
       4,    -1,    -1,    -1,    85,    86,    87,    88,    12,    13,
      91,    -1,    93,    -1,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    12,    13,    79,    80,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    -1,    -1,    91,    -1,    93,
      -1,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    -1,    56,    57,    -1,
      59,    60,    -1,    -1,    -1,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    86,    87,    88,
     138,    -1,   140,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   140,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   140,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   140,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   140,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   140,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,   133,    -1,    -1,    -1,    -1,   138,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,   135,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
     135,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,   135,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,   135,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   135,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,   135,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,   135,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   135,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,   135,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,   135,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,   135,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
     135,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,   135,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,   135,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   135,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,   135,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,   135,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   135,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,   135,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,   135,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,   135,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
     135,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,   135,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,   135,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   135,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,   135,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,   135,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   135,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,   135,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,   135,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,   135,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
     135,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,   133,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
     131,    -1,   133,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,   133,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,   131,    -1,   133,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,   133,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,    -1,    -1,    -1,   131,    -1,   133,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,   133,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,    -1,    -1,    -1,   131,    -1,   133,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,   133,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,
     133,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,   133,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
     131,    -1,   133,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,   133,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,   131,    -1,   133,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,   133,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,    -1,    -1,    -1,   131,    -1,   133,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,   133,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,    -1,    -1,    -1,   131,    -1,   133,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,   133,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,
     133,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,   133,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
     131,    -1,   133,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,   133,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,   131,    -1,   133,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,   133,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,    -1,    -1,    -1,   131,    -1,   133,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,   133,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,    -1,    -1,    -1,   131,    -1,   133,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,   133,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,
     133,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,   133,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
     131,    -1,   133,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,   133,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,   131,    -1,   133,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,   133,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,    -1,    -1,    -1,   131,    -1,   133,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,   133,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,    -1,    -1,    -1,   131,    -1,   133,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,   133,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,
     133,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
      -1,   133,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
     131,    -1,   133,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,   133,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,   131,    -1,   133,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,    -1,   133,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,    -1,    -1,    -1,   131,    -1,   133,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,    -1,    -1,    -1,   131,    -1,   133,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,    -1,    -1,    -1,   131,    -1,   133,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,    -1,    -1,    -1,   131
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   143,   144,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    55,    56,    57,    58,    59,    60,    64,
      65,    66,    67,    68,    69,    71,    72,    73,    74,    75,
      76,    79,    80,    85,    86,    87,    88,    91,    93,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   145,
     147,   148,   166,   169,   170,   173,   174,   175,   176,   177,
     178,   194,   195,   196,     3,     4,     5,     7,     9,    10,
      11,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    36,    37,    38,    39,    42,    99,   105,   106,
     107,   108,   109,   110,   111,   112,   122,   123,   127,   129,
     130,   132,   134,   136,   137,   139,   164,   165,   197,   198,
     209,    13,    49,   132,     6,   139,     6,   132,   139,   132,
     132,    70,   132,   139,   132,   132,    70,   139,   132,   132,
      53,    49,   132,    49,    49,    49,    46,    49,    51,    51,
      43,    46,    49,    51,   132,   139,   122,   123,   132,   139,
     199,   200,   199,   139,    43,    46,    49,   139,   199,    49,
      49,    46,     4,    99,   139,     4,     6,    46,     4,     4,
       4,   132,   132,   132,     4,   139,   205,     4,   132,   132,
       6,   134,     4,     4,     4,     5,   139,   208,   209,   139,
     208,     4,   134,   136,   141,   165,   139,   209,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   132,   132,   132,     7,   132,     4,   197,   197,   197,
     197,   135,   139,   197,     4,    91,    92,     4,     4,   170,
     171,   172,   197,     6,     6,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   131,
       6,     6,   197,     5,   197,   197,     4,    43,   123,   170,
     178,   197,   203,   204,   197,   197,   132,   197,   204,   197,
     197,   132,   204,   197,   197,   123,   139,   197,   202,   203,
     132,   197,   139,   132,   132,   202,   139,   139,   132,   132,
     132,   132,   132,     4,   199,   199,   199,   197,   197,   122,
     123,   139,   139,   199,   139,   139,   139,   122,   123,   132,
     172,   199,   139,   202,   202,   132,     4,     6,   134,   134,
     172,     6,   139,   134,   134,     6,   197,   197,   197,   136,
     197,   139,    94,   197,   197,   197,     6,   134,   136,   172,
       6,   172,     6,   134,   197,     4,   139,   149,     6,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   208,   208,   208,   208,   197,     5,   134,   133,     7,
     112,   204,   135,     7,   164,   165,   136,     7,   134,   140,
      43,    46,    49,    51,   169,     6,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,     6,   133,   138,   138,   133,   134,   139,   197,   203,
       8,   124,   138,   140,   133,   133,   197,   133,   140,   133,
     133,   197,   140,   133,   133,   139,   140,   204,   124,     7,
     197,   133,   197,   197,   197,     7,   197,   197,   197,   167,
     197,   209,   167,   167,   167,   133,   138,   138,   138,   199,
     199,   171,   171,   138,   197,   197,   197,   197,   182,   138,
     172,     6,     7,     7,   197,     6,   197,   197,   140,   204,
     197,   197,   133,   133,   133,    91,   138,   172,   139,     8,
     133,   135,   197,     4,   140,   140,   197,   135,   165,   197,
       4,    81,    82,    83,    84,   140,   152,   156,   159,   161,
     162,   133,   135,   133,   135,   133,   135,   133,   135,   133,
     135,   133,   135,   133,   135,   133,   135,   133,   135,   133,
     135,   133,   135,   138,   138,   133,   135,   133,   135,   133,
     135,   133,   135,   133,   135,   133,   135,   138,   138,   138,
     138,   138,   138,   133,   138,   138,   133,   133,     6,   138,
     197,   202,   202,   140,     7,   136,   164,   165,   209,   197,
       6,     4,     4,   139,   206,   135,   139,   139,   139,   139,
       8,     6,   119,   146,   204,   197,     7,   135,   139,   197,
     197,   197,   203,   197,   203,    94,     7,     7,   133,     7,
      94,     7,     7,   133,    94,     7,     7,   204,   140,   139,
     197,   133,     7,   140,   133,   133,   197,   140,   140,   133,
     133,   133,   133,   133,   136,   199,   197,   197,   140,   140,
     197,   138,   138,   138,    71,    77,    78,   192,   193,   199,
     140,   179,   197,   197,   133,   135,   135,   140,   135,   135,
       7,     7,     7,   136,   197,   140,   197,   197,     7,   136,
     135,   135,   136,   165,   208,   140,   153,   132,   132,   139,
     163,     6,   197,   197,   197,   197,   197,   197,   197,   197,
     204,   208,   197,   135,     6,     6,   135,     4,    91,    92,
     197,     6,     6,     6,     7,   134,   205,   207,     6,   204,
     204,   204,   204,   197,   119,   208,   133,   138,   199,   204,
     140,     8,    49,   202,   202,     7,   202,    49,    51,   202,
     202,     7,    51,   202,   202,   140,   204,     6,     7,   139,
       7,     7,     7,     6,    61,     7,     7,     7,     7,     7,
       7,     7,     4,   138,   138,   138,   140,   199,   199,   199,
       6,   139,   132,   140,   193,   138,   192,     6,     6,   139,
       6,     6,    49,     6,     6,   202,   202,   202,     4,   138,
       8,     8,   133,     4,     4,   136,     6,     4,     6,   132,
     197,   197,   201,   202,   139,   133,   135,   133,   135,   133,
     135,   133,   135,   133,   133,   133,   164,     7,   164,   165,
     136,     7,     6,   205,   197,   138,   140,   140,   140,   140,
     140,     6,     6,   146,   197,     6,   140,   197,   139,     6,
      56,     6,    56,   202,     6,   139,   139,     6,     6,   202,
     139,     6,     6,   140,     5,   197,   202,   202,   202,    62,
      63,   202,   202,   202,   202,   202,   202,   202,     6,     7,
     197,   197,   197,   139,   138,   140,   138,   140,   138,   140,
     197,   202,   197,   197,   199,   140,   204,   139,     6,     6,
      90,   197,   197,   197,     6,     7,     4,   165,   150,   197,
     138,   138,   138,   140,   151,   197,   202,   209,   197,     6,
       4,   206,     6,   135,   205,     6,     6,     6,     6,   208,
     138,   135,   197,   199,   199,     6,   197,   197,     6,   197,
       5,   138,     6,     6,    94,   168,   197,   197,     4,     6,
       6,     6,     6,     6,     6,     6,   197,   209,   140,   133,
     138,   140,   171,   199,     6,   183,   199,     6,   184,   199,
       6,   185,   140,   138,   133,   140,   138,   140,   197,   202,
     138,   140,     8,   140,   133,   139,   197,   209,   133,   138,
     197,   197,   202,   139,   138,   140,     6,     6,     6,     7,
       6,   136,     6,   197,   140,     6,     6,   140,   140,   140,
       5,   197,    47,     6,     6,     6,     6,     6,     6,   139,
     197,   140,   138,   139,   138,   139,   138,   139,     6,   202,
       7,   139,   197,     6,   140,    89,   197,   197,   204,     6,
       6,   154,   197,   138,   138,   201,   197,     6,   205,    92,
     138,     6,     6,     6,     6,     6,   138,   139,   171,   138,
     140,   197,   199,   192,   197,   199,   192,   197,   199,   192,
     138,   140,   202,   172,   140,   197,   140,   140,   140,   139,
     197,   197,   140,     6,   197,     5,   197,   140,   197,   140,
     138,   140,   140,   138,   140,   140,   138,   140,   202,     6,
      61,   140,   180,   139,     6,     6,   151,   133,   138,     6,
     139,   138,   138,   140,   140,     6,   186,   197,     6,     6,
     187,   197,     6,     6,   188,   197,     6,   140,   197,   192,
     172,   140,   157,   197,   201,   197,     5,   139,   140,   139,
     140,   139,   140,     6,     6,   140,   140,   181,     6,   139,
     133,   140,   140,   138,   192,     6,   189,   192,     6,   190,
     192,     6,   191,   192,   155,   208,   160,   139,     6,     5,
     140,   139,   140,   139,   140,   139,   140,   138,   140,   139,
     201,   140,     6,   192,     6,   192,     6,   192,   208,     6,
     158,   208,   140,     6,   140,   140,   140,   138,   140,     6,
       6,     6,     6,   208,     6
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
#line 138 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 149 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 150 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 151 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 152 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 153 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 154 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 155 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 156 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 157 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 158 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 159 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 160 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 161 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 162 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 167 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 21:
#line 171 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 22:
#line 178 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 23:
#line 183 "Gmsh.y"
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
#line 198 "Gmsh.y"
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
#line 211 "Gmsh.y"
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
#line 240 "Gmsh.y"
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
#line 254 "Gmsh.y"
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
#line 265 "Gmsh.y"
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
#line 279 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData = new PViewDataList(true); 
#endif
    ;}
    break;

  case 35:
#line 293 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 36:
#line 295 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 37:
#line 300 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(1) - (1)].d)); ;}
    break;

  case 38:
#line 302 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(3) - (3)].d)); ;}
    break;

  case 39:
#line 307 "Gmsh.y"
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
      ViewCoord.clear();
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 40:
#line 453 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(int j = 0; j < ViewCoord.size() / 3; j++) 
	    List_Add(ViewValueList, &ViewCoord[3 * j + i]);
      }
#endif
    ;}
    break;

  case 41:
#line 463 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 42:
#line 472 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(ViewData->T2C, &(yyvsp[(1) - (1)].c)[i]); 
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 43:
#line 479 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(ViewData->T2C, &(yyvsp[(3) - (3)].c)[i]); 
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 44:
#line 489 "Gmsh.y"
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
#line 499 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 46:
#line 508 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(ViewData->T3C, &(yyvsp[(1) - (1)].c)[i]); 
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 47:
#line 515 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(ViewData->T3C, &(yyvsp[(3) - (3)].c)[i]); 
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 48:
#line 525 "Gmsh.y"
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
#line 534 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 50:
#line 544 "Gmsh.y"
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
#line 561 "Gmsh.y"
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
#line 577 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewValueList = ViewData->Time;
#endif
    ;}
    break;

  case 53:
#line 583 "Gmsh.y"
    {
    ;}
    break;

  case 54:
#line 590 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 55:
#line 591 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 56:
#line 592 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 57:
#line 593 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 58:
#line 594 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 59:
#line 598 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 60:
#line 599 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 61:
#line 607 "Gmsh.y"
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
#line 629 "Gmsh.y"
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
#line 656 "Gmsh.y"
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
#line 696 "Gmsh.y"
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

  case 65:
#line 706 "Gmsh.y"
    {
      // appends to the list
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].push_back(*(double*)List_Pointer((yyvsp[(5) - (6)].l), i));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 66:
#line 714 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c)); 
      else
	gmsh_yysymbols[(yyvsp[(1) - (3)].c)][0] += (yyvsp[(2) - (3)].i);
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 67:
#line 722 "Gmsh.y"
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
#line 734 "Gmsh.y"
    { 
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 69:
#line 743 "Gmsh.y"
    { 
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 70:
#line 748 "Gmsh.y"
    { 
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].c));
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 71:
#line 756 "Gmsh.y"
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
#line 774 "Gmsh.y"
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
#line 792 "Gmsh.y"
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
#line 801 "Gmsh.y"
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
#line 813 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 76:
#line 818 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 77:
#line 826 "Gmsh.y"
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
#line 846 "Gmsh.y"
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
#line 869 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->background_field = (int)(yyvsp[(4) - (5)].d);
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
    ;}
    break;

  case 80:
#line 876 "Gmsh.y"
    {
      if(!GModel::current()->getFields()->new_field((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 81:
#line 882 "Gmsh.y"
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
#line 902 "Gmsh.y"
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
#line 923 "Gmsh.y"
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
#line 949 "Gmsh.y"
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
#line 961 "Gmsh.y"
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
#line 978 "Gmsh.y"
    { 
      (yyval.i) = (int)(yyvsp[(1) - (1)].d); 
    ;}
    break;

  case 87:
#line 982 "Gmsh.y"
    { 
      (yyval.i) = GModel::current()->setPhysicalName
	(std::string((yyvsp[(1) - (1)].c)), ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 88:
#line 991 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 89:
#line 995 "Gmsh.y"
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
#line 1013 "Gmsh.y"
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

  case 91:
#line 1036 "Gmsh.y"
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
#line 1052 "Gmsh.y"
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
#line 1074 "Gmsh.y"
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
#line 1092 "Gmsh.y"
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
#line 1110 "Gmsh.y"
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
#line 1128 "Gmsh.y"
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
#line 1154 "Gmsh.y"
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
#line 1172 "Gmsh.y"
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
#line 1199 "Gmsh.y"
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
#line 1218 "Gmsh.y"
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
#line 1236 "Gmsh.y"
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
#line 1254 "Gmsh.y"
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
#line 1280 "Gmsh.y"
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
#line 1297 "Gmsh.y"
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
#line 1316 "Gmsh.y"
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
#line 1334 "Gmsh.y"
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
#line 1373 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 108:
#line 1379 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 109:
#line 1385 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 110:
#line 1392 "Gmsh.y"
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
#line 1417 "Gmsh.y"
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
#line 1442 "Gmsh.y"
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
#line 1458 "Gmsh.y"
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
#line 1478 "Gmsh.y"
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
#line 1496 "Gmsh.y"
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
#line 1513 "Gmsh.y"
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
#line 1534 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 118:
#line 1539 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 119:
#line 1544 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 120:
#line 1549 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 121:
#line 1554 "Gmsh.y"
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

  case 122:
#line 1574 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 123:
#line 1580 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp=ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d),tmp,(yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 124:
#line 1590 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 125:
#line 1591 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 126:
#line 1596 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 127:
#line 1600 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 128:
#line 1604 "Gmsh.y"
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
#line 1627 "Gmsh.y"
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
#line 1650 "Gmsh.y"
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
#line 1673 "Gmsh.y"
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
#line 1701 "Gmsh.y"
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
#line 1710 "Gmsh.y"
    {
      GModel::current()->getFields()->delete_field((int)(yyvsp[(4) - (6)].d));
    ;}
    break;

  case 134:
#line 1714 "Gmsh.y"
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
#line 1729 "Gmsh.y"
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
#line 1750 "Gmsh.y"
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
#line 1767 "Gmsh.y"
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
#line 1781 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 139:
#line 1787 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 140:
#line 1793 "Gmsh.y"
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
#line 1802 "Gmsh.y"
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
#line 1816 "Gmsh.y"
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
#line 1864 "Gmsh.y"
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
#line 1882 "Gmsh.y"
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
#line 1897 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Sleep")){
	SleepInSeconds((yyvsp[(2) - (3)].d));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Remesh")){
	yymsg(0, "Surface remeshing must be reinterfaced");
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
#line 1916 "Gmsh.y"
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
#line 1928 "Gmsh.y"
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
#line 1952 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 149:
#line 1956 "Gmsh.y"
    {
      CTX.forced_bbox = 0;
      SetBoundingBox();
    ;}
    break;

  case 150:
#line 1961 "Gmsh.y"
    {
      CTX.forced_bbox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 151:
#line 1966 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      Draw();
#endif
    ;}
    break;

  case 152:
#line 1978 "Gmsh.y"
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
#line 1995 "Gmsh.y"
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
#line 2012 "Gmsh.y"
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
#line 2031 "Gmsh.y"
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
#line 2050 "Gmsh.y"
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
#line 2078 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname,
						      gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 158:
#line 2086 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&gmsh_yyin, gmsh_yyname,
						     gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 159:
#line 2092 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname,
						     gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 160:
#line 2099 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 161:
#line 2103 "Gmsh.y"
    {
    ;}
    break;

  case 162:
#line 2112 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 163:
#line 2120 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 164:
#line 2128 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 165:
#line 2136 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 166:
#line 2140 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 167:
#line 2148 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 168:
#line 2152 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 169:
#line 2160 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 170:
#line 2164 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 171:
#line 2172 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 172:
#line 2176 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 173:
#line 2185 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 174:
#line 2192 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 175:
#line 2199 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 176:
#line 2206 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 177:
#line 2213 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 178:
#line 2220 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 179:
#line 2227 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 180:
#line 2234 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 181:
#line 2241 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 182:
#line 2248 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 183:
#line 2252 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 184:
#line 2259 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 185:
#line 2263 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 186:
#line 2270 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 187:
#line 2274 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 188:
#line 2281 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 189:
#line 2285 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 190:
#line 2292 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 191:
#line 2296 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 192:
#line 2303 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 193:
#line 2307 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 194:
#line 2314 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 195:
#line 2318 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 196:
#line 2325 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 197:
#line 2329 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 198:
#line 2336 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 199:
#line 2340 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 200:
#line 2351 "Gmsh.y"
    {
    ;}
    break;

  case 201:
#line 2354 "Gmsh.y"
    {
    ;}
    break;

  case 202:
#line 2360 "Gmsh.y"
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
#line 2369 "Gmsh.y"
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
#line 2389 "Gmsh.y"
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
#line 2412 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 206:
#line 2416 "Gmsh.y"
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
#line 2440 "Gmsh.y"
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
#line 2458 "Gmsh.y"
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
#line 2476 "Gmsh.y"
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
#line 2494 "Gmsh.y"
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
#line 2523 "Gmsh.y"
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
#line 2558 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 213:
#line 2563 "Gmsh.y"
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
#line 2590 "Gmsh.y"
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
#line 2604 "Gmsh.y"
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
#line 2617 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	int j = (int)d;
	Surface *s = FindSurface(j);
	if(s) s->TransfiniteSmoothing = (int)(yyvsp[(5) - (6)].d);
      }
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 217:
#line 2634 "Gmsh.y"
    { 
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s)
	setSurfaceEmbeddedPoints(s, (yyvsp[(3) - (10)].l));
    ;}
    break;

  case 218:
#line 2640 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s)
	setSurfaceEmbeddedCurves(s, (yyvsp[(3) - (10)].l));
    ;}
    break;

  case 219:
#line 2646 "Gmsh.y"
    {
    ;}
    break;

  case 220:
#line 2649 "Gmsh.y"
    {
    ;}
    break;

  case 221:
#line 2658 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 222:
#line 2662 "Gmsh.y"
    { 
      if(!strcmp((yyvsp[(2) - (3)].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[(2) - (3)].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX.geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 223:
#line 2677 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 224:
#line 2678 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 225:
#line 2679 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 226:
#line 2680 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 227:
#line 2681 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 228:
#line 2682 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 229:
#line 2683 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 230:
#line 2684 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 231:
#line 2686 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 232:
#line 2692 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 233:
#line 2693 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 234:
#line 2694 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 235:
#line 2695 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 236:
#line 2696 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 237:
#line 2697 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 238:
#line 2698 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 239:
#line 2699 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 240:
#line 2700 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 241:
#line 2701 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 242:
#line 2702 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 243:
#line 2703 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 244:
#line 2704 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 245:
#line 2705 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 246:
#line 2706 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 247:
#line 2707 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 248:
#line 2708 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 249:
#line 2709 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 250:
#line 2710 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 251:
#line 2711 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 252:
#line 2712 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 253:
#line 2713 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 254:
#line 2714 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 255:
#line 2715 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 256:
#line 2716 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 257:
#line 2717 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 258:
#line 2718 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 259:
#line 2719 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 260:
#line 2720 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 261:
#line 2721 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 262:
#line 2722 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 263:
#line 2723 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 264:
#line 2725 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 265:
#line 2726 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 266:
#line 2727 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 267:
#line 2728 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 268:
#line 2729 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 269:
#line 2730 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 270:
#line 2731 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 271:
#line 2732 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 272:
#line 2733 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 273:
#line 2734 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 274:
#line 2735 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 275:
#line 2736 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 276:
#line 2737 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 277:
#line 2738 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 278:
#line 2739 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 279:
#line 2740 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 280:
#line 2741 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 281:
#line 2742 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 282:
#line 2743 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 283:
#line 2744 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 284:
#line 2745 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 285:
#line 2754 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 286:
#line 2755 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 287:
#line 2756 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 288:
#line 2757 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 289:
#line 2758 "Gmsh.y"
    { (yyval.d) = Get_GmshMajorVersion(); ;}
    break;

  case 290:
#line 2759 "Gmsh.y"
    { (yyval.d) = Get_GmshMinorVersion(); ;}
    break;

  case 291:
#line 2760 "Gmsh.y"
    { (yyval.d) = Get_GmshPatchVersion(); ;}
    break;

  case 292:
#line 2765 "Gmsh.y"
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

  case 293:
#line 2778 "Gmsh.y"
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

  case 294:
#line 2790 "Gmsh.y"
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

  case 295:
#line 2805 "Gmsh.y"
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

  case 296:
#line 2815 "Gmsh.y"
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

  case 297:
#line 2825 "Gmsh.y"
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

  case 298:
#line 2843 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 299:
#line 2848 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 300:
#line 2853 "Gmsh.y"
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

  case 301:
#line 2863 "Gmsh.y"
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

  case 302:
#line 2873 "Gmsh.y"
    { 
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 303:
#line 2881 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 304:
#line 2885 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 305:
#line 2889 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 306:
#line 2893 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 307:
#line 2897 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 308:
#line 2904 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 309:
#line 2908 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 310:
#line 2912 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 311:
#line 2916 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 312:
#line 2923 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 313:
#line 2928 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 314:
#line 2935 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 315:
#line 2940 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 316:
#line 2944 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 317:
#line 2949 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 318:
#line 2953 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 319:
#line 2961 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 320:
#line 2972 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 321:
#line 2980 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 322:
#line 2988 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 323:
#line 2994 "Gmsh.y"
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

  case 324:
#line 3005 "Gmsh.y"
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

  case 325:
#line 3025 "Gmsh.y"
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
#line 3035 "Gmsh.y"
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

  case 327:
#line 3045 "Gmsh.y"
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

  case 328:
#line 3055 "Gmsh.y"
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

  case 329:
#line 3075 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 330:
#line 3080 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 331:
#line 3084 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 332:
#line 3088 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 333:
#line 3100 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 334:
#line 3104 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 335:
#line 3116 "Gmsh.y"
    {
      int flag;
      (yyval.u) = Get_ColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 336:
#line 3123 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 337:
#line 3133 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 338:
#line 3137 "Gmsh.y"
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

  case 339:
#line 3152 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 340:
#line 3157 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 341:
#line 3164 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 342:
#line 3168 "Gmsh.y"
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

  case 343:
#line 3181 "Gmsh.y"
    { 
      const char *val = "";
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), val);
      (yyval.c) = (char*)Malloc((strlen(val) + 1) * sizeof(char));
      strcpy((yyval.c), val);
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 344:
#line 3189 "Gmsh.y"
    { 
      const char *val = "";
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), val);
      (yyval.c) = (char*)Malloc((strlen(val) + 1) * sizeof(char));
      strcpy((yyval.c), val);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 345:
#line 3200 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 346:
#line 3204 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 347:
#line 3212 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 348:
#line 3220 "Gmsh.y"
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

  case 349:
#line 3234 "Gmsh.y"
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

  case 350:
#line 3248 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 351:
#line 3252 "Gmsh.y"
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
#line 7661 "Gmsh.tab.cpp"
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


#line 3272 "Gmsh.y"


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

