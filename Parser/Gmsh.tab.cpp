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
     tCompound = 316,
     tUsing = 317,
     tPlugin = 318,
     tRotate = 319,
     tTranslate = 320,
     tSymmetry = 321,
     tDilate = 322,
     tExtrude = 323,
     tLoop = 324,
     tRecombine = 325,
     tSmoother = 326,
     tSplit = 327,
     tDelete = 328,
     tCoherence = 329,
     tIntersect = 330,
     tLayers = 331,
     tHole = 332,
     tAlias = 333,
     tAliasWithOptions = 334,
     tText2D = 335,
     tText3D = 336,
     tInterpolationScheme = 337,
     tTime = 338,
     tCombine = 339,
     tBSpline = 340,
     tBezier = 341,
     tNurbs = 342,
     tOrder = 343,
     tKnots = 344,
     tColor = 345,
     tColorTable = 346,
     tFor = 347,
     tIn = 348,
     tEndFor = 349,
     tIf = 350,
     tEndIf = 351,
     tExit = 352,
     tField = 353,
     tReturn = 354,
     tCall = 355,
     tFunction = 356,
     tShow = 357,
     tHide = 358,
     tGetValue = 359,
     tGMSH_MAJOR_VERSION = 360,
     tGMSH_MINOR_VERSION = 361,
     tGMSH_PATCH_VERSION = 362,
     tAFFECTDIVIDE = 363,
     tAFFECTTIMES = 364,
     tAFFECTMINUS = 365,
     tAFFECTPLUS = 366,
     tOR = 367,
     tAND = 368,
     tNOTEQUAL = 369,
     tEQUAL = 370,
     tGREATEROREQUAL = 371,
     tLESSOREQUAL = 372,
     UNARYPREC = 373,
     tMINUSMINUS = 374,
     tPLUSPLUS = 375
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
#define tCompound 316
#define tUsing 317
#define tPlugin 318
#define tRotate 319
#define tTranslate 320
#define tSymmetry 321
#define tDilate 322
#define tExtrude 323
#define tLoop 324
#define tRecombine 325
#define tSmoother 326
#define tSplit 327
#define tDelete 328
#define tCoherence 329
#define tIntersect 330
#define tLayers 331
#define tHole 332
#define tAlias 333
#define tAliasWithOptions 334
#define tText2D 335
#define tText3D 336
#define tInterpolationScheme 337
#define tTime 338
#define tCombine 339
#define tBSpline 340
#define tBezier 341
#define tNurbs 342
#define tOrder 343
#define tKnots 344
#define tColor 345
#define tColorTable 346
#define tFor 347
#define tIn 348
#define tEndFor 349
#define tIf 350
#define tEndIf 351
#define tExit 352
#define tField 353
#define tReturn 354
#define tCall 355
#define tFunction 356
#define tShow 357
#define tHide 358
#define tGetValue 359
#define tGMSH_MAJOR_VERSION 360
#define tGMSH_MINOR_VERSION 361
#define tGMSH_PATCH_VERSION 362
#define tAFFECTDIVIDE 363
#define tAFFECTTIMES 364
#define tAFFECTMINUS 365
#define tAFFECTPLUS 366
#define tOR 367
#define tAND 368
#define tNOTEQUAL 369
#define tEQUAL 370
#define tGREATEROREQUAL 371
#define tLESSOREQUAL 372
#define UNARYPREC 373
#define tMINUSMINUS 374
#define tPLUSPLUS 375




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "GmshMessage.h"
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
#line 424 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 437 "Gmsh.tab.cpp"

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
#define YYLAST   6139

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  141
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  356
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1251

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   375

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   126,     2,   136,     2,   125,     2,     2,
     131,   132,   123,   121,   137,   122,   135,   124,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     117,     2,   118,   112,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   133,     2,   134,   130,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   138,     2,   139,   140,     2,     2,     2,
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
     105,   106,   107,   108,   109,   110,   111,   113,   114,   115,
     116,   119,   120,   127,   128,   129
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
     446,   447,   450,   458,   467,   474,   482,   490,   499,   508,
     526,   534,   542,   554,   563,   572,   581,   591,   595,   600,
     611,   619,   627,   636,   645,   658,   667,   675,   684,   690,
     702,   708,   718,   723,   733,   743,   745,   747,   748,   751,
     758,   765,   772,   779,   784,   791,   798,   802,   807,   813,
     817,   821,   826,   831,   835,   843,   851,   855,   863,   867,
     870,   873,   889,   892,   899,   908,   917,   928,   930,   933,
     935,   939,   944,   946,   952,   964,   978,   979,   987,   988,
    1002,  1003,  1019,  1020,  1027,  1036,  1045,  1054,  1067,  1080,
    1093,  1108,  1123,  1138,  1139,  1152,  1153,  1166,  1167,  1180,
    1181,  1198,  1199,  1216,  1217,  1234,  1235,  1254,  1255,  1274,
    1275,  1294,  1296,  1299,  1305,  1313,  1323,  1326,  1336,  1337,
    1341,  1342,  1344,  1345,  1348,  1349,  1352,  1360,  1367,  1376,
    1385,  1391,  1398,  1409,  1420,  1431,  1442,  1445,  1449,  1451,
    1455,  1458,  1461,  1464,  1468,  1472,  1476,  1480,  1484,  1488,
    1492,  1496,  1500,  1504,  1508,  1512,  1516,  1520,  1526,  1531,
    1536,  1541,  1546,  1551,  1556,  1561,  1566,  1571,  1576,  1583,
    1588,  1593,  1598,  1603,  1608,  1613,  1620,  1627,  1634,  1639,
    1644,  1649,  1654,  1659,  1664,  1669,  1674,  1679,  1684,  1689,
    1696,  1701,  1706,  1711,  1716,  1721,  1726,  1733,  1740,  1747,
    1752,  1754,  1756,  1758,  1760,  1762,  1764,  1766,  1768,  1774,
    1779,  1784,  1787,  1793,  1797,  1804,  1809,  1817,  1824,  1826,
    1829,  1832,  1836,  1840,  1852,  1862,  1870,  1878,  1880,  1884,
    1886,  1888,  1891,  1895,  1900,  1906,  1909,  1913,  1917,  1923,
    1928,  1930,  1932,  1936,  1943,  1945,  1947,  1951,  1955,  1965,
    1973,  1975,  1981,  1985,  1992,  1994,  1998,  2000,  2002,  2006,
    2013,  2015,  2017,  2024,  2029,  2034,  2039
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     142,     0,    -1,   143,    -1,     1,     6,    -1,    -1,   143,
     144,    -1,   147,    -1,   146,    -1,   165,    -1,   169,    -1,
     170,    -1,   173,    -1,   174,    -1,   175,    -1,   178,    -1,
     198,    -1,   199,    -1,   200,    -1,   177,    -1,   176,    -1,
     118,    -1,   118,   118,    -1,    35,   131,     5,   132,     6,
      -1,    35,   131,     5,   132,   145,   212,     6,    -1,    35,
     131,     5,   137,   208,   132,     6,    -1,    35,   131,     5,
     137,   208,   132,   145,   212,     6,    -1,     4,     5,   138,
     148,   139,     6,    -1,    78,     4,   133,   201,   134,     6,
      -1,    79,     4,   133,   201,   134,     6,    -1,    -1,   148,
     151,    -1,   148,   155,    -1,   148,   158,    -1,   148,   160,
      -1,   148,   161,    -1,   201,    -1,   149,   137,   201,    -1,
     201,    -1,   150,   137,   201,    -1,    -1,    -1,     4,   152,
     131,   149,   132,   153,   138,   150,   139,     6,    -1,   212,
      -1,   154,   137,   212,    -1,    -1,    80,   131,   201,   137,
     201,   137,   201,   132,   156,   138,   154,   139,     6,    -1,
     212,    -1,   157,   137,   212,    -1,    -1,    81,   131,   201,
     137,   201,   137,   201,   137,   201,   132,   159,   138,   157,
     139,     6,    -1,    82,   138,   205,   139,   138,   205,   139,
       6,    -1,    82,   138,   205,   139,   138,   205,   139,   138,
     205,   139,   138,   205,   139,     6,    -1,    -1,    83,   162,
     138,   150,   139,     6,    -1,     7,    -1,   111,    -1,   110,
      -1,   109,    -1,   108,    -1,   129,    -1,   128,    -1,     4,
     163,   201,     6,    -1,     4,   133,   201,   134,   163,   201,
       6,    -1,     4,   133,   138,   208,   139,   134,   163,   206,
       6,    -1,     4,   133,   134,     7,   206,     6,    -1,     4,
     133,   134,   111,   206,     6,    -1,     4,   164,     6,    -1,
       4,   133,   201,   134,   164,     6,    -1,     4,     7,   213,
       6,    -1,     4,   135,     4,     7,   213,     6,    -1,     4,
     133,   201,   134,   135,     4,     7,   213,     6,    -1,     4,
     135,     4,   163,   201,     6,    -1,     4,   133,   201,   134,
     135,     4,   163,   201,     6,    -1,     4,   135,     4,   164,
       6,    -1,     4,   133,   201,   134,   135,     4,   164,     6,
      -1,     4,   135,    90,   135,     4,     7,   209,     6,    -1,
       4,   133,   201,   134,   135,    90,   135,     4,     7,   209,
       6,    -1,     4,   135,    91,     7,   210,     6,    -1,     4,
     133,   201,   134,   135,    91,     7,   210,     6,    -1,     4,
      98,     7,   201,     6,    -1,    98,   133,   201,   134,     7,
       4,     6,    -1,    98,   133,   201,   134,   135,     4,     7,
     201,     6,    -1,    98,   133,   201,   134,   135,     4,     7,
     213,     6,    -1,    98,   133,   201,   134,   135,     4,     7,
     138,   208,   139,     6,    -1,    63,   131,     4,   132,   135,
       4,     7,   201,     6,    -1,    63,   131,     4,   132,   135,
       4,     7,   213,     6,    -1,   201,    -1,   213,    -1,    -1,
      93,    47,   138,   201,   139,    -1,    -1,    56,   203,    -1,
      43,   131,   201,   132,     7,   203,     6,    -1,    60,    43,
     131,   166,   132,     7,   206,     6,    -1,    52,    53,   206,
       7,   201,     6,    -1,    46,   131,   201,   132,     7,   206,
       6,    -1,    50,   131,   201,   132,     7,   206,     6,    -1,
      44,   131,   201,   132,     7,   206,   168,     6,    -1,    45,
     131,   201,   132,     7,   206,   168,     6,    -1,    54,   131,
     201,   132,     7,   138,   201,   137,   201,   137,     5,   137,
       5,   137,     5,   139,     6,    -1,    85,   131,   201,   132,
       7,   206,     6,    -1,    86,   131,   201,   132,     7,   206,
       6,    -1,    87,   131,   201,   132,     7,   206,    89,   206,
      88,   201,     6,    -1,    46,    69,   131,   201,   132,     7,
     206,     6,    -1,    60,    46,   131,   166,   132,     7,   206,
       6,    -1,    56,    49,   131,   201,   132,     7,   206,     6,
      -1,    57,    49,   131,   201,   132,     7,   206,   167,     6,
      -1,    12,    13,     6,    -1,    13,    49,   201,     6,    -1,
      54,    49,   131,   201,   132,     7,     5,     5,     5,     6,
      -1,    47,   131,   201,   132,     7,   206,     6,    -1,    48,
     131,   201,   132,     7,   206,     6,    -1,    49,    69,   131,
     201,   132,     7,   206,     6,    -1,    60,    49,   131,   166,
     132,     7,   206,     6,    -1,    61,    49,   131,   201,   132,
       7,   206,     4,   138,   205,   139,     6,    -1,    59,    51,
     131,   201,   132,     7,   206,     6,    -1,    51,   131,   201,
     132,     7,   206,     6,    -1,    60,    51,   131,   166,   132,
       7,   206,     6,    -1,    65,   203,   138,   171,   139,    -1,
      64,   138,   203,   137,   203,   137,   201,   139,   138,   171,
     139,    -1,    66,   203,   138,   171,   139,    -1,    67,   138,
     203,   137,   201,   139,   138,   171,   139,    -1,     4,   138,
     171,   139,    -1,    75,    46,   138,   208,   139,    49,   138,
     201,   139,    -1,    72,    46,   131,   201,   132,   138,   208,
     139,     6,    -1,   172,    -1,   170,    -1,    -1,   172,   169,
      -1,   172,    43,   138,   208,   139,     6,    -1,   172,    46,
     138,   208,   139,     6,    -1,   172,    49,   138,   208,   139,
       6,    -1,   172,    51,   138,   208,   139,     6,    -1,    73,
     138,   172,   139,    -1,    73,    98,   133,   201,   134,     6,
      -1,    73,     4,   133,   201,   134,     6,    -1,    73,     4,
       6,    -1,    73,     4,     4,     6,    -1,    90,   209,   138,
     172,   139,    -1,   102,   212,     6,    -1,   103,   212,     6,
      -1,   102,   138,   172,   139,    -1,   103,   138,   172,   139,
      -1,     4,   213,     6,    -1,     4,     4,   133,   201,   134,
     212,     6,    -1,     4,     4,     4,   133,   201,   134,     6,
      -1,     4,   201,     6,    -1,    63,   131,     4,   132,   135,
       4,     6,    -1,    84,     4,     6,    -1,    97,     6,    -1,
      40,     6,    -1,    40,   138,   201,   137,   201,   137,   201,
     137,   201,   137,   201,   137,   201,   139,     6,    -1,    41,
       6,    -1,    92,   131,   201,     8,   201,   132,    -1,    92,
     131,   201,     8,   201,     8,   201,   132,    -1,    92,     4,
      93,   138,   201,     8,   201,   139,    -1,    92,     4,    93,
     138,   201,     8,   201,     8,   201,   139,    -1,    94,    -1,
     101,     4,    -1,    99,    -1,   100,     4,     6,    -1,    95,
     131,   201,   132,    -1,    96,    -1,    68,   203,   138,   172,
     139,    -1,    68,   138,   203,   137,   203,   137,   201,   139,
     138,   172,   139,    -1,    68,   138,   203,   137,   203,   137,
     203,   137,   201,   139,   138,   172,   139,    -1,    -1,    68,
     203,   138,   172,   179,   192,   139,    -1,    -1,    68,   138,
     203,   137,   203,   137,   201,   139,   138,   172,   180,   192,
     139,    -1,    -1,    68,   138,   203,   137,   203,   137,   203,
     137,   201,   139,   138,   172,   181,   192,   139,    -1,    -1,
      68,   138,   172,   182,   192,   139,    -1,    68,    43,   138,
     201,   137,   203,   139,     6,    -1,    68,    46,   138,   201,
     137,   203,   139,     6,    -1,    68,    49,   138,   201,   137,
     203,   139,     6,    -1,    68,    43,   138,   201,   137,   203,
     137,   203,   137,   201,   139,     6,    -1,    68,    46,   138,
     201,   137,   203,   137,   203,   137,   201,   139,     6,    -1,
      68,    49,   138,   201,   137,   203,   137,   203,   137,   201,
     139,     6,    -1,    68,    43,   138,   201,   137,   203,   137,
     203,   137,   203,   137,   201,   139,     6,    -1,    68,    46,
     138,   201,   137,   203,   137,   203,   137,   203,   137,   201,
     139,     6,    -1,    68,    49,   138,   201,   137,   203,   137,
     203,   137,   203,   137,   201,   139,     6,    -1,    -1,    68,
      43,   138,   201,   137,   203,   139,   183,   138,   192,   139,
       6,    -1,    -1,    68,    46,   138,   201,   137,   203,   139,
     184,   138,   192,   139,     6,    -1,    -1,    68,    49,   138,
     201,   137,   203,   139,   185,   138,   192,   139,     6,    -1,
      -1,    68,    43,   138,   201,   137,   203,   137,   203,   137,
     201,   139,   186,   138,   192,   139,     6,    -1,    -1,    68,
      46,   138,   201,   137,   203,   137,   203,   137,   201,   139,
     187,   138,   192,   139,     6,    -1,    -1,    68,    49,   138,
     201,   137,   203,   137,   203,   137,   201,   139,   188,   138,
     192,   139,     6,    -1,    -1,    68,    43,   138,   201,   137,
     203,   137,   203,   137,   203,   137,   201,   139,   189,   138,
     192,   139,     6,    -1,    -1,    68,    46,   138,   201,   137,
     203,   137,   203,   137,   203,   137,   201,   139,   190,   138,
     192,   139,     6,    -1,    -1,    68,    49,   138,   201,   137,
     203,   137,   203,   137,   203,   137,   201,   139,   191,   138,
     192,   139,     6,    -1,   193,    -1,   192,   193,    -1,    76,
     138,   201,   139,     6,    -1,    76,   138,   206,   137,   206,
     139,     6,    -1,    76,   138,   206,   137,   206,   137,   206,
     139,     6,    -1,    70,     6,    -1,    77,   131,   201,   132,
       7,   206,    62,   201,     6,    -1,    -1,    62,     4,   201,
      -1,    -1,     4,    -1,    -1,     7,   206,    -1,    -1,     7,
     201,    -1,    58,    46,   206,     7,   201,   194,     6,    -1,
      58,    49,   206,   196,   195,     6,    -1,    55,    49,   138,
     201,   139,     7,   206,     6,    -1,    58,    51,   138,   201,
     139,     7,   206,     6,    -1,    70,    49,   206,   197,     6,
      -1,    71,    49,   206,     7,   201,     6,    -1,    43,   138,
     208,   139,    93,    49,   138,   201,   139,     6,    -1,    46,
     138,   208,   139,    93,    49,   138,   201,   139,     6,    -1,
      46,   138,   208,   139,    93,    51,   138,   201,   139,     6,
      -1,    49,   138,   208,   139,    93,    51,   138,   201,   139,
       6,    -1,    74,     6,    -1,    74,     4,     6,    -1,   202,
      -1,   131,   201,   132,    -1,   122,   201,    -1,   121,   201,
      -1,   126,   201,    -1,   201,   122,   201,    -1,   201,   121,
     201,    -1,   201,   123,   201,    -1,   201,   124,   201,    -1,
     201,   125,   201,    -1,   201,   130,   201,    -1,   201,   117,
     201,    -1,   201,   118,   201,    -1,   201,   120,   201,    -1,
     201,   119,   201,    -1,   201,   116,   201,    -1,   201,   115,
     201,    -1,   201,   114,   201,    -1,   201,   113,   201,    -1,
     201,   112,   201,     8,   201,    -1,    14,   131,   201,   132,
      -1,    15,   131,   201,   132,    -1,    16,   131,   201,   132,
      -1,    17,   131,   201,   132,    -1,    18,   131,   201,   132,
      -1,    19,   131,   201,   132,    -1,    20,   131,   201,   132,
      -1,    21,   131,   201,   132,    -1,    22,   131,   201,   132,
      -1,    24,   131,   201,   132,    -1,    25,   131,   201,   137,
     201,   132,    -1,    26,   131,   201,   132,    -1,    27,   131,
     201,   132,    -1,    28,   131,   201,   132,    -1,    29,   131,
     201,   132,    -1,    30,   131,   201,   132,    -1,    31,   131,
     201,   132,    -1,    32,   131,   201,   137,   201,   132,    -1,
      33,   131,   201,   137,   201,   132,    -1,    34,   131,   201,
     137,   201,   132,    -1,    23,   131,   201,   132,    -1,    14,
     133,   201,   134,    -1,    15,   133,   201,   134,    -1,    16,
     133,   201,   134,    -1,    17,   133,   201,   134,    -1,    18,
     133,   201,   134,    -1,    19,   133,   201,   134,    -1,    20,
     133,   201,   134,    -1,    21,   133,   201,   134,    -1,    22,
     133,   201,   134,    -1,    24,   133,   201,   134,    -1,    25,
     133,   201,   137,   201,   134,    -1,    26,   133,   201,   134,
      -1,    27,   133,   201,   134,    -1,    28,   133,   201,   134,
      -1,    29,   133,   201,   134,    -1,    30,   133,   201,   134,
      -1,    31,   133,   201,   134,    -1,    32,   133,   201,   137,
     201,   134,    -1,    33,   133,   201,   137,   201,   134,    -1,
      34,   133,   201,   137,   201,   134,    -1,    23,   133,   201,
     134,    -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,
     105,    -1,   106,    -1,   107,    -1,     4,    -1,     4,   140,
     138,   201,   139,    -1,     4,   133,   201,   134,    -1,   136,
       4,   133,   134,    -1,     4,   164,    -1,     4,   133,   201,
     134,   164,    -1,     4,   135,     4,    -1,     4,   133,   201,
     134,   135,     4,    -1,     4,   135,     4,   164,    -1,     4,
     133,   201,   134,   135,     4,   164,    -1,   104,   131,     5,
     137,   201,   132,    -1,   204,    -1,   122,   203,    -1,   121,
     203,    -1,   203,   122,   203,    -1,   203,   121,   203,    -1,
     138,   201,   137,   201,   137,   201,   137,   201,   137,   201,
     139,    -1,   138,   201,   137,   201,   137,   201,   137,   201,
     139,    -1,   138,   201,   137,   201,   137,   201,   139,    -1,
     131,   201,   137,   201,   137,   201,   132,    -1,   206,    -1,
     205,   137,   206,    -1,   201,    -1,   207,    -1,   138,   139,
      -1,   138,   208,   139,    -1,   122,   138,   208,   139,    -1,
     201,   123,   138,   208,   139,    -1,   122,   207,    -1,   201,
     123,   207,    -1,   201,     8,   201,    -1,   201,     8,   201,
       8,   201,    -1,    43,   138,   201,   139,    -1,   170,    -1,
     178,    -1,     4,   133,   134,    -1,     4,   133,   138,   208,
     139,   134,    -1,   201,    -1,   207,    -1,   208,   137,   201,
      -1,   208,   137,   207,    -1,   138,   201,   137,   201,   137,
     201,   137,   201,   139,    -1,   138,   201,   137,   201,   137,
     201,   139,    -1,     4,    -1,     4,   135,    90,   135,     4,
      -1,   138,   211,   139,    -1,     4,   133,   201,   134,   135,
      91,    -1,   209,    -1,   211,   137,   209,    -1,   213,    -1,
       4,    -1,     4,   135,     4,    -1,     4,   133,   201,   134,
     135,     4,    -1,     5,    -1,    42,    -1,    37,   131,   212,
     137,   212,   132,    -1,    38,   131,   212,   132,    -1,    39,
     131,   212,   132,    -1,    36,   131,   212,   132,    -1,    36,
     131,   212,   137,   208,   132,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   139,   139,   140,   145,   147,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     168,   172,   179,   184,   199,   212,   241,   255,   266,   281,
     286,   287,   288,   289,   290,   294,   296,   301,   303,   309,
     455,   308,   473,   480,   491,   490,   509,   516,   527,   526,
     544,   559,   579,   578,   592,   593,   594,   595,   596,   600,
     601,   608,   630,   657,   697,   707,   715,   723,   735,   744,
     749,   757,   775,   793,   802,   814,   819,   827,   847,   870,
     877,   883,   903,   924,   950,   962,   979,   983,   993,   996,
    1011,  1014,  1024,  1047,  1063,  1085,  1103,  1121,  1151,  1181,
    1201,  1219,  1237,  1263,  1280,  1299,  1317,  1356,  1362,  1368,
    1375,  1400,  1425,  1441,  1458,  1489,  1507,  1524,  1545,  1550,
    1555,  1560,  1565,  1585,  1591,  1602,  1603,  1608,  1611,  1615,
    1638,  1661,  1684,  1712,  1721,  1725,  1740,  1761,  1778,  1792,
    1798,  1804,  1813,  1827,  1875,  1893,  1908,  1927,  1939,  1963,
    1967,  1972,  1977,  1989,  2006,  2023,  2042,  2061,  2089,  2097,
    2103,  2110,  2114,  2123,  2131,  2139,  2148,  2147,  2160,  2159,
    2172,  2171,  2184,  2183,  2196,  2203,  2210,  2217,  2224,  2231,
    2238,  2245,  2252,  2260,  2259,  2271,  2270,  2282,  2281,  2293,
    2292,  2304,  2303,  2315,  2314,  2326,  2325,  2337,  2336,  2348,
    2347,  2362,  2365,  2371,  2380,  2400,  2423,  2427,  2451,  2454,
    2470,  2473,  2486,  2489,  2495,  2498,  2505,  2534,  2582,  2587,
    2629,  2651,  2677,  2700,  2723,  2726,  2735,  2739,  2755,  2756,
    2757,  2758,  2759,  2760,  2761,  2762,  2763,  2770,  2771,  2772,
    2773,  2774,  2775,  2776,  2777,  2778,  2779,  2780,  2781,  2782,
    2783,  2784,  2785,  2786,  2787,  2788,  2789,  2790,  2791,  2792,
    2793,  2794,  2795,  2796,  2797,  2798,  2799,  2800,  2801,  2803,
    2804,  2805,  2806,  2807,  2808,  2809,  2810,  2811,  2812,  2813,
    2814,  2815,  2816,  2817,  2818,  2819,  2820,  2821,  2822,  2823,
    2832,  2833,  2834,  2835,  2836,  2837,  2838,  2842,  2855,  2867,
    2882,  2892,  2902,  2920,  2925,  2930,  2940,  2950,  2958,  2962,
    2966,  2970,  2974,  2981,  2985,  2989,  2993,  3000,  3005,  3012,
    3017,  3021,  3026,  3030,  3038,  3049,  3057,  3065,  3072,  3083,
    3103,  3113,  3123,  3133,  3153,  3158,  3162,  3166,  3178,  3182,
    3194,  3201,  3211,  3215,  3230,  3235,  3242,  3246,  3259,  3267,
    3278,  3282,  3290,  3298,  3312,  3326,  3330
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
  "tRuled", "tTransfinite", "tComplex", "tPhysical", "tCompound", "tUsing",
  "tPlugin", "tRotate", "tTranslate", "tSymmetry", "tDilate", "tExtrude",
  "tLoop", "tRecombine", "tSmoother", "tSplit", "tDelete", "tCoherence",
  "tIntersect", "tLayers", "tHole", "tAlias", "tAliasWithOptions",
  "tText2D", "tText3D", "tInterpolationScheme", "tTime", "tCombine",
  "tBSpline", "tBezier", "tNurbs", "tOrder", "tKnots", "tColor",
  "tColorTable", "tFor", "tIn", "tEndFor", "tIf", "tEndIf", "tExit",
  "tField", "tReturn", "tCall", "tFunction", "tShow", "tHide", "tGetValue",
  "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION",
  "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'",
  "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL",
  "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC",
  "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'",
  "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems",
  "GeoFormatItem", "SendToFile", "Printf", "View", "Views",
  "ElementCoords", "ElementValues", "Element", "@1", "@2", "Text2DValues",
  "Text2D", "@3", "Text3DValues", "Text3D", "@4", "InterpolationMatrix",
  "Time", "@5", "NumericAffectation", "NumericIncrement", "Affectation",
  "PhysicalId", "RuledSurfaceOptions", "CircleOptions", "Shape",
  "Transform", "MultipleShape", "ListOfShapes", "Delete", "Colorify",
  "Visibility", "Command", "Loop", "Extrude", "@6", "@7", "@8", "@9",
  "@10", "@11", "@12", "@13", "@14", "@15", "@16", "@17", "@18",
  "ExtrudeParameters", "ExtrudeParameter", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
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
     365,   366,    63,   367,   368,   369,   370,    60,    62,   371,
     372,    43,    45,    42,    47,    37,    33,   373,   374,   375,
      94,    40,    41,    91,    93,    46,    35,    44,   123,   125,
     126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   141,   142,   142,   143,   143,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     145,   145,   146,   146,   146,   146,   147,   147,   147,   148,
     148,   148,   148,   148,   148,   149,   149,   150,   150,   152,
     153,   151,   154,   154,   156,   155,   157,   157,   159,   158,
     160,   160,   162,   161,   163,   163,   163,   163,   163,   164,
     164,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   166,   166,   167,   167,
     168,   168,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   170,   170,
     170,   170,   170,   170,   170,   171,   171,   172,   172,   172,
     172,   172,   172,   173,   173,   173,   173,   173,   174,   175,
     175,   175,   175,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   178,   178,   178,   179,   178,   180,   178,
     181,   178,   182,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   183,   178,   184,   178,   185,   178,   186,
     178,   187,   178,   188,   178,   189,   178,   190,   178,   191,
     178,   192,   192,   193,   193,   193,   193,   193,   194,   194,
     195,   195,   196,   196,   197,   197,   198,   198,   198,   198,
     198,   198,   199,   199,   199,   199,   200,   200,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   203,   203,
     203,   203,   203,   204,   204,   204,   204,   205,   205,   206,
     206,   206,   206,   206,   206,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   208,   208,   208,   208,   209,   209,
     209,   209,   210,   210,   211,   211,   212,   212,   212,   212,
     213,   213,   213,   213,   213,   213,   213
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
       0,     2,     7,     8,     6,     7,     7,     8,     8,    17,
       7,     7,    11,     8,     8,     8,     9,     3,     4,    10,
       7,     7,     8,     8,    12,     8,     7,     8,     5,    11,
       5,     9,     4,     9,     9,     1,     1,     0,     2,     6,
       6,     6,     6,     4,     6,     6,     3,     4,     5,     3,
       3,     4,     4,     3,     7,     7,     3,     7,     3,     2,
       2,    15,     2,     6,     8,     8,    10,     1,     2,     1,
       3,     4,     1,     5,    11,    13,     0,     7,     0,    13,
       0,    15,     0,     6,     8,     8,     8,    12,    12,    12,
      14,    14,    14,     0,    12,     0,    12,     0,    12,     0,
      16,     0,    16,     0,    16,     0,    18,     0,    18,     0,
      18,     1,     2,     5,     7,     9,     2,     9,     0,     3,
       0,     1,     0,     2,     0,     2,     7,     6,     8,     8,
       5,     6,    10,    10,    10,    10,     2,     3,     1,     3,
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
       1,     1,     3,     6,     1,     1,     3,     3,     9,     7,
       1,     5,     3,     6,     1,     3,     1,     1,     3,     6,
       1,     1,     6,     4,     4,     4,     6
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
     157,     0,   162,     0,     0,   159,     0,     0,     0,     0,
       5,     7,     6,     8,     9,    10,    11,    12,    13,    19,
      18,    14,    15,    16,    17,   290,   297,   350,    54,   291,
     292,   293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   351,     0,     0,
     294,   295,   296,    58,    57,    56,    55,     0,     0,     0,
      60,    59,     0,     0,     0,     0,   127,     0,     0,     0,
     228,     0,     0,     0,     0,   150,     0,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   308,     0,     0,     0,     0,     0,   127,
       0,     0,     0,     0,     0,     0,   127,     0,   226,     0,
       0,     0,     0,     0,     0,     0,   340,     0,     0,     0,
       0,     0,   149,     0,     0,   158,   347,   350,   127,     0,
     346,   127,     0,     0,     0,     0,     0,   301,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   297,   231,
     230,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,     0,   125,     0,    66,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   107,     0,     0,     0,     0,   297,     0,
       0,   330,   331,   334,   335,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
       0,   320,     0,     0,     0,     0,     0,     0,   212,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   310,   309,
       0,     0,     0,     0,   127,   127,     0,     0,     0,     0,
       0,     0,     0,   172,     0,   127,   214,     0,     0,     0,
     136,     0,     0,     0,   227,     0,     0,     0,   148,     0,
       0,     0,     0,     0,   127,     0,     0,     0,     0,   160,
       0,     0,     0,   139,     0,   140,     0,     0,   303,     0,
       0,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   229,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,   122,     0,     0,     0,     0,   128,    61,     0,
     246,   245,   244,   243,   239,   240,   242,   241,   234,   233,
     235,   236,   237,   238,   108,     0,     0,     0,     0,     0,
       0,   230,   325,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   321,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     210,     0,     0,     0,    86,    87,     0,     0,     0,     0,
       0,     0,     0,     0,   312,   311,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   166,     0,     0,     0,     0,
     137,     0,     0,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,     0,     0,   348,   141,
     142,     0,   299,   305,     0,    39,     0,     0,     0,    52,
       0,    30,    31,    32,    33,    34,   248,   269,   249,   270,
     250,   271,   251,   272,   252,   273,   253,   274,   254,   275,
     255,   276,   256,   277,   268,   289,   257,   278,     0,     0,
     259,   280,   260,   281,   261,   282,   262,   283,   263,   284,
     264,   285,     0,     0,     0,     0,     0,     0,   355,     0,
       0,   353,   354,    79,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,    73,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,    22,    20,     0,     0,
       0,     0,   332,     0,     0,   327,   235,   326,   336,   337,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
       0,   208,   213,   211,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,   120,     0,     0,
       0,     0,     0,     0,     0,     0,   201,     0,   163,     0,
     215,   220,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,     0,
       0,     0,   302,     0,   298,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   299,    64,    65,     0,     0,     0,     0,     0,
      67,    69,    71,     0,     0,   344,     0,    77,     0,     0,
       0,     0,   247,    21,     0,     0,     0,     0,     0,   329,
       0,     0,    90,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   323,     0,    94,     0,     0,     0,
       0,     0,     0,     0,   217,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     206,     0,     0,   173,   202,     0,     0,   221,     0,   135,
     134,     0,    27,    28,     0,     0,     0,   341,     0,     0,
       0,   153,     0,     0,     0,   145,   304,   144,     0,     0,
       0,     0,   317,     0,   258,   279,   265,   286,   266,   287,
     267,   288,   356,   352,   307,     0,    54,     0,     0,     0,
       0,    62,     0,     0,     0,   342,     0,     0,     0,     0,
      23,    24,     0,     0,    92,     0,   328,     0,     0,     0,
       0,     0,    95,     0,     0,   110,   111,     0,     0,    96,
     116,   324,     0,     0,     0,     0,    88,     0,   216,     0,
       0,     0,     0,     0,     0,     0,   147,     0,     0,     0,
       0,   127,     0,   183,     0,   185,     0,   187,   319,     0,
       0,     0,     0,   167,     0,     0,   100,   101,     0,     0,
       0,     0,    80,     0,   349,   306,     0,    35,     0,     0,
       0,     0,     0,    37,     0,     0,     0,    74,     0,     0,
      75,     0,   345,   129,   130,   131,   132,     0,     0,   333,
       0,    91,    97,    98,   103,     0,     0,   112,     0,     0,
       0,   218,   105,     0,     0,   209,   219,   115,    93,   104,
     113,   117,     0,     0,     0,     0,   316,     0,   315,     0,
       0,   174,     0,     0,   175,     0,     0,   176,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   339,     0,
     155,   154,     0,     0,     0,    40,     0,     0,     0,   318,
       0,     0,     0,    63,    70,    72,     0,    78,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
      84,    85,   127,     0,   121,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   127,     0,   124,   123,     0,     0,
       0,     0,    81,    82,     0,    36,     0,     0,     0,    38,
      53,     0,   343,     0,   222,   223,   224,   225,   109,     0,
       0,     0,     0,     0,   314,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   168,     0,     0,
     338,   156,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,   119,     0,   189,     0,     0,   191,     0,     0,
     193,     0,     0,     0,   204,     0,   164,     0,   127,   102,
      83,     0,    44,     0,    50,     0,     0,     0,    89,   114,
     313,   177,     0,     0,   184,   178,     0,     0,   186,   179,
       0,     0,   188,     0,     0,     0,   170,     0,     0,     0,
       0,     0,     0,     0,   195,     0,   197,     0,   199,   205,
     207,   169,   165,     0,    41,     0,    48,     0,     0,     0,
       0,   180,     0,     0,   181,     0,     0,   182,     0,     0,
       0,    42,     0,     0,   151,     0,     0,     0,     0,     0,
       0,     0,   171,     0,     0,     0,     0,     0,   190,     0,
     192,     0,   194,     0,    43,    45,     0,    46,     0,    99,
       0,     0,     0,     0,     0,    51,   196,   198,   200,    47,
      49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    60,   658,    61,    62,   400,   956,   962,
     581,   745,  1084,  1210,   582,  1178,  1236,   583,  1212,   584,
     585,   749,   127,   217,    63,   523,   994,   899,   467,   311,
     282,   283,    66,    67,    68,    69,    70,   312,   719,  1147,
    1193,   543,  1012,  1015,  1018,  1162,  1166,  1170,  1202,  1205,
    1208,   715,   716,   813,   694,   520,   547,    72,    73,    74,
     329,   130,   348,   173,   861,   862,   331,   315,   198,   649,
     776,   209,   210
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1036
static const yytype_int16 yypact[] =
{
    2645,    70,    29,  2721, -1036, -1036,  1308,    74,   -24,   -41,
      -5,   106,   -80,    -9,    40,   -53,    67,    71,   -36,    78,
     144,    90,   -42,   111,   230,   233,   276,   249,   256,   254,
     186,   195,   323,   323,   223,   272,   329,   330,   342,    23,
      35,   382,   417,   443,   447,   341,   345,   346,    15,     7,
   -1036,   353, -1036,   463,   376, -1036,   511,   517,    10,    69,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036,    22,   388,   619, -1036,
   -1036, -1036,   -77,    54,   128,   145,   180,   258,   267,   294,
     405,   422,   425,   434,   439,   512,   521,   529,   601,   602,
     645,   648,   665,   396,   399,   400,   409, -1036,   545,   416,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036,  2151,  2151,  2151,
   -1036, -1036,  2151,  1783,    19,   557,   340,  2151,   560,   693,
   -1036,   577,   582,  2151,   584, -1036,  2151, -1036,  2151,  2084,
    2151,  2151,   461,  2151,  2084,  2151,  2151,   467,  2084,  2151,
    2151,  1356,   471,  2151,   465,   480,   481,  1356,  1356,   477,
     505,   515,   532,   533,   542,   543,   638,   323,   323,   323,
    2151,  2151,   143, -1036,   357,   323,   550,   555,   556,  1954,
     379,  1356,  1356,   566,    36,   570, -1036,   700, -1036,   571,
     579,   580,   718,  2151,  2151,  2151,   612,  2151,   598,   644,
    2151,  2151, -1036,  2151,   742, -1036,   668, -1036, -1036,   774,
   -1036, -1036,   791,   642,  2151,   785,   662, -1036, -1036,   819,
    2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,
    2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,
    2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,
    2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,
    2151,  2151,   596,   596,   596,   596,  2151,   821,   655,   713,
     713,   713,  4980,    14,  2084,  4244,   485,   694,   841,   720,
     722, -1036,   725,  2785,   928, -1036, -1036,  2151,  2151,  2151,
    2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,  2151,
    2151,  2151, -1036, -1036,  1549,   -87,  3490,  5001,   567,   734,
    2084, -1036, -1036,   993, -1036,   685,  5022,  5043,  2151,  5064,
     698,  5085,  5106,  2151,   699,  5127,  5148,  1486,  1171,  2433,
     861, -1036,  2151,  5169,  2151,  2151,  2151,   867,   871,  2151,
    2151,   735,   735,   735,   735,  2151,   747,   -78, -1036, -1036,
    3516,  3542,   323,   323,   340,   340,   -21,  2151,  2151,  2151,
    1954,  1954,  2151,  2785,    58, -1036,   888,   891,  2151,   876,
   -1036,  2151,  2151,  1204, -1036,  2084,  2151,  2151, -1036,  5190,
    5211,  5232,   812,  3568, -1036,   780,  2452,  5253,  4267, -1036,
    2151,   907,  1519, -1036,  1777, -1036,  2151,  4290,   -49,  2151,
      13, -1036,  5274,  4313,  5295,  4336,  5316,  4359,  5337,  4382,
    5358,  4405,  5379,  4428,  5400,  4451,  5421,  4474,  5442,  4497,
    5463,  4520,  5484,  4543,  3594,  3620,  5505,  4566,  5526,  4589,
    5547,  4612,  5568,  4635,  5589,  4658,  5610,  4681,  3646,  3672,
    3698,  3724,  3750,  3776,   172,   792,   815,   824,  1580,   795,
    2151, -1036,  1356,  1356,   710,   273,   619,  2151,   922,   954,
      16,   839, -1036,   -69,   -14,   -35,   -54, -1036, -1036,  2480,
    1104,  1038,   767,   767,   593,   593,   593,   593,   669,   669,
     713,   713,   713,   713, -1036,    12,  2084,  2151,   971,  1919,
    2151,   713, -1036,  2151,  2084,  2084,   887,   974,   975,  5631,
     977,   892,   995,   997,  5652,   913,  1000,  1001,  2084, -1036,
     726,  1616,  2151,  5673,  1002,  2548,  5694,  5715,  2151,  1356,
    1006,  2820,  5736,   879,  6009, -1036,   880,   881,   883,  5757,
     882,   323,  2151,  2151, -1036, -1036,   877,   890,  2151,  3802,
    3828,  3854,  3464,   107,   323,  1947,  2151,  1012,  2151,  5778,
   -1036,  4704,  4727, -1036,   730,  4750,  4773,  1013,  1014,  1015,
     895,  2151,  2180,  2151,  2151, -1036,    21,  4796, -1036, -1036,
   -1036,  4819,   338, -1036,  2848, -1036,   896,   900,   897, -1036,
    1020, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,  2151,  2151,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036,  2151,  2151,  2151,  2151,  2151,  2151, -1036,  2084,
     596, -1036, -1036, -1036,  2151,  4842,  1027,  1028,   902, -1036,
      68,  2151,  1032,  1048,  1897, -1036,  1050,   926,    15,  1049,
   -1036,  2084,  2084,  2084,  2084,  2151, -1036,   942,   596,   277,
    3880,   323, -1036,  2084,  2876,  2499,   713, -1036,   993, -1036,
    1017,  1356,  1356,  1055,  1356,   781,  1356,  1356,  1057,  1018,
    1356,  1356,   738, -1036,  2084,  2242,  1061,   933,  1065,  1069,
    1071,  2016, -1036, -1036,  1073,  1074,  1077,  1078,  1079,  1080,
    1081,  1083,  1076,   228,  3906,  3932, -1036, -1036,  2904,   323,
     323,   323,  1085,   955,   961,   -40, -1036,   328, -1036,   107,
    6009, -1036,  2277,   956,  1089,  1091,  1051,  1092,  1095,  1356,
    1356,  1356,  1098,  3958, -1036,  2518,   847,  1099,  1100,   985,
    1115,  1118, -1036,  1119, -1036,   996,  2151,  2151,  1356,   986,
   -1036,  5799,  4865,  5820,  4888,  5841,  4911,  5862,  4934,   279,
     994,  5883,   -31, -1036, -1036,   163,   498,   998,  1121,  2296,
   -1036, -1036, -1036,    15,  2151, -1036,   757, -1036,   766,   769,
     770,   773,  6009, -1036,  1123,    47,  2151,     6,   777, -1036,
    2151,   992,  1082,  1082,  1356,  1126,  1004,  1005,  1129,  1133,
    1356,  1007,  1134,  1138, -1036,   778, -1036,  1141,  2151,  1356,
    1356,  1356,  1143,  1142, -1036,  1356,  1356,  1356,  1356,  1356,
    1356,  1356,   206,  2151,  2151,  2151,  1029,   -56,   -51,   248,
   -1036,  1356,  2151, -1036, -1036,  1954,   -13, -1036,  2084, -1036,
   -1036,  1031, -1036, -1036,  1144,  1145,  1084, -1036,  2151,  2151,
    2151, -1036,  1159,  1163,  1167, -1036,   -49, -1036,  2151,  3984,
    4010,   782, -1036,  2151, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036,  1356,   619,  2151,  1166,  1172,
      16, -1036,  1173,  4957,    15, -1036,  1177,  1201,  1203,  1205,
   -1036, -1036,   596,  4036, -1036,  1043,  6009,  2151,   323,  1206,
    1207,  1209, -1036,  2151,  2151, -1036, -1036,  1224,  2151, -1036,
   -1036, -1036,  1226,  4062,  1227,  1234,  1139,  2151, -1036,  1235,
    1236,  1238,  1239,  1251,  1253,  1174, -1036,   735,  2932,  5904,
    2736,   340,   323,  1256,   323,  1260,   323,  1261,   318,  1131,
    5925,  2960,   375, -1036,   783,  2151, -1036, -1036,  1356,  2764,
     875,  5946, -1036,  1746, -1036, -1036,   374,  6009,  2151,  2151,
    1356,  1132,   787,  6009,  1263,  1265,  2315, -1036,  1266,  1268,
   -1036,  1137, -1036, -1036, -1036, -1036, -1036,  1273,  2151, -1036,
    2988,   147, -1036, -1036, -1036,  3016,  3044, -1036,  3072,  1275,
    2151, -1036, -1036,  1237,  1276,  6009, -1036, -1036, -1036, -1036,
   -1036, -1036,  1147,  2334,  1277,  1148, -1036,  2151, -1036,  1149,
     442, -1036,  1156,   507, -1036,  1157,   544, -1036,  1158,  1281,
    1356,  1274,  1160,  2151,  1293,  3100,  1212,  2151, -1036,  2151,
   -1036, -1036,  2084,  2362,  1295, -1036,  2151,  4088,  4114, -1036,
    1356,  2151,  1297, -1036, -1036, -1036,    15, -1036,  1213, -1036,
    4140,  1299,  1300,  1302,  1303,  1310,  4166,  1176, -1036,  1356,
   -1036, -1036,   340,  2792, -1036,  1954,   107,  1954,   107,  1954,
     107, -1036,   788,  1356, -1036,  3128, -1036, -1036,  2151,  3156,
    3184,   796, -1036, -1036,  1182,  6009,  2151,  2151,   800,  6009,
   -1036,  1315, -1036,  2151, -1036, -1036, -1036, -1036, -1036,  1343,
    2151,   801,  1210,  2151, -1036,  3212,   547,   124,  3240,   549,
     138,  3268,   561,   190,  1356,  1345,  1290,  2247,  1215,  2381,
   -1036, -1036,  1348,  2151,  5967,  4192,    26, -1036,  4218,  1218,
    3296,  1350, -1036,  3324,  1351,  2151,  1352,  1355,  2151,  1357,
    1358,  2151,  1362,  1223, -1036,  2151, -1036,   107, -1036, -1036,
   -1036,   805, -1036,  2151, -1036,  1356,  2151,  1364, -1036, -1036,
   -1036, -1036,  1254,  3352, -1036, -1036,  1255,  3380, -1036, -1036,
    1257,  3408, -1036,  1385,  2400,   320,  2266,  1388,  1258,  5988,
     806,  3436,  1264,   107,  1391,   107,  1392,   107,  1394, -1036,
   -1036, -1036, -1036,   107, -1036,   596, -1036,  1267,  1396,  1398,
     386, -1036,  1269,   394, -1036,  1270,   398, -1036,  1271,   411,
     809, -1036,  1272,  1356, -1036,  1286,  1405,   107,  1420,   107,
    1421,   107, -1036,   596,  1426,   596,   813,  1427, -1036,   446,
   -1036,   492, -1036,   540, -1036, -1036,   814, -1036,  1429, -1036,
    1432,  1434,  1436,   596,  1439, -1036, -1036, -1036, -1036, -1036,
   -1036
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1036, -1036, -1036, -1036,   663, -1036, -1036, -1036, -1036,   281,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036,  -267,    25, -1036,    75, -1036,   654,  1446,     5,
    -351,  -173, -1036, -1036, -1036, -1036, -1036,  1447, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036,  -644,  -655, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
      -4, -1036,   141, -1036, -1035,   -90,    24,    38,  -626,   572,
   -1036,   -59,     4
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     212,   135,   129,   536,   537,  1088,   363,   152,    65,   457,
     131,   199,   894,   373,   206,   207,   142,   575,   656,   196,
     647,   452,   775,   276,  1101,   133,   213,   184,   737,     5,
     712,   128,  1154,   147,   147,   392,   713,   714,   394,   187,
     369,   188,   370,   352,   353,   485,   103,   104,   105,   106,
     486,   138,   107,   891,   220,   142,   221,   712,   139,   531,
     834,   330,   138,   713,   714,   352,   353,   337,   338,   651,
     352,   353,   766,   206,   207,   836,     4,   150,   143,   120,
     121,   932,   219,   933,   654,   144,   934,   132,   935,   153,
     134,   366,   367,   576,   577,   578,   579,   120,   121,   833,
     352,   353,   148,   653,   741,   103,   104,   105,   106,   277,
     278,   107,   137,   269,   270,   271,   538,   143,   272,   275,
    1180,   185,   140,   284,   652,   453,   943,   352,   353,   304,
     657,   281,   306,   136,   307,   313,   316,   317,   200,   319,
     313,   321,   322,   151,   313,   325,   326,   882,   208,   333,
     120,   121,   580,   197,   648,   214,   738,   215,   767,   768,
     154,   186,   216,   314,  1155,   657,   350,   351,   314,   371,
     639,   141,   314,   172,   174,   351,   180,   712,  1226,   352,
     353,   834,   320,   713,   714,   222,   324,   223,   641,   379,
     380,   381,   545,   383,   712,   544,   386,   387,   145,   388,
     713,   714,   146,   444,   445,   446,   447,   211,   712,   149,
     397,   562,   926,   927,   713,   714,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   972,   224,
     712,   225,   448,  1136,   352,   353,   713,   714,   352,   353,
     313,   113,   114,   115,   116,   150,   226,  1139,   227,   155,
     639,   354,   156,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   314,   161,
     160,   458,   162,   165,   628,   163,   491,   164,   347,   629,
     349,   228,   454,   229,   499,   176,   356,   166,   177,   504,
     364,   178,   157,   491,   313,   158,   493,   159,   513,  1142,
     515,   516,   517,   167,   492,   521,   522,   524,   524,   524,
     524,   529,   206,   207,   280,   525,   525,   525,   525,   352,
     353,   492,   314,   539,   540,   541,   269,   270,   542,   281,
     281,   175,   636,   637,   549,   823,   510,   551,   552,   352,
     353,   313,   555,   556,   103,   104,   105,   106,   181,   182,
     107,   113,   114,   115,   116,   936,   567,   937,   183,   230,
     712,   231,   571,   168,   169,   574,   713,   714,   232,   314,
     233,   120,   121,   170,    31,    32,    33,    34,   640,   785,
     179,   872,    38,   554,   495,    41,   495,   526,   527,   528,
    1091,   190,  1107,   573,  1110,   234,  1113,   235,   189,   692,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   511,   299,   300,   168,   169,   635,   191,   301,   352,
     353,   192,   834,   644,   170,   834,   712,  1019,   834,  1191,
     643,   171,   713,   714,   712,   835,   120,   121,   712,   202,
     713,   714,   193,   741,   713,   714,   194,   195,   352,   353,
     642,   712,   313,   660,   201,   635,   664,   713,   714,   665,
     666,   668,   456,   534,   535,   355,   352,   353,   875,   877,
     352,   353,   349,  1175,   313,   876,  1035,   666,   685,   203,
     314,  1036,  1023,   743,   691,   204,   712,   365,   667,   669,
     834,   205,   713,   714,   659,  1216,   218,   262,   704,   705,
     263,   264,   314,  1218,   708,   667,   236,  1220,   237,  1200,
     265,  1203,   720,  1206,   722,   834,   682,   267,   834,  1209,
    1222,   834,   266,   238,   834,   239,   240,   733,   241,   735,
     736,   279,   712,   352,   353,   242,   285,   243,   713,   714,
     244,   760,   245,  1229,   834,  1231,   834,  1233,   834,  1065,
    1009,   792,   793,   302,   795,  1240,   798,   799,   303,   305,
     802,   803,   318,   113,   114,   115,   116,   742,   323,   784,
     206,   207,   332,   334,   751,   752,   113,   114,   115,   116,
     712,   335,   336,   120,   121,   339,   713,   714,   753,   754,
     755,   756,   757,   758,   207,   313,   120,   121,   352,   353,
     761,  1241,   103,   104,   105,   106,   340,   769,   107,   844,
     845,   846,   346,   246,  1067,   247,   341,   313,   313,   313,
     313,   782,   248,   314,   249,   103,   104,   105,   106,   313,
     250,   107,   251,   342,   343,   352,   353,   759,   352,   353,
     352,   353,   703,   344,   345,   314,   314,   314,   314,  1242,
     313,  1069,   352,   353,  1135,   717,  1138,   314,   357,   778,
     779,   780,   781,   358,   359,   120,   121,   368,  1141,   286,
     489,   788,   215,   372,   901,   126,   374,   216,   314,   375,
     907,  1102,   376,   377,   296,   297,   298,   299,   300,   914,
     915,   916,   805,   301,   378,   919,   920,   921,   922,   923,
     924,   925,   252,   254,   253,   255,   384,   385,    75,   268,
     207,   939,   859,   860,    79,    80,    81,   382,   389,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     883,   103,   104,   105,   106,   396,   256,   107,   257,   258,
     393,   259,   893,   120,   121,   964,   896,   742,   450,   398,
     215,   878,   298,   299,   300,   216,   260,   395,   261,   301,
     399,   390,   787,   391,   913,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   928,
     929,   930,   495,   301,   496,   401,   449,   938,   940,   459,
     796,   941,   797,   977,   313,   495,   495,   501,   505,   109,
     110,   111,   112,   301,   949,   950,   951,   495,   460,   638,
     827,   828,   829,   461,   957,   850,   117,   118,  1026,   963,
     126,   119,   314,   495,   462,   683,   122,   495,   512,   726,
    1039,   125,   490,   966,   518,   495,   944,   804,   519,   530,
     965,   955,   550,  1029,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   980,   884,   546,   885,   301,   548,   985,
     986,  1117,   560,   495,   988,   886,   495,   495,   887,   888,
     495,   568,   889,   995,   495,   495,   895,   911,   563,   960,
     495,   961,  1024,  1003,  1041,  1114,  1042,  1115,   645,   630,
    1072,  1004,   634,   495,   468,  1122,   281,   960,   960,  1126,
    1131,  1025,  1041,   960,  1177,  1197,  1223,   631,  1224,  1033,
     960,  1243,  1238,  1244,  1037,  1038,   632,  1034,   646,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   650,  1050,  1176,   942,   301,   661,   851,
     670,   671,   672,  1116,   674,   675,  1056,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   493,   676,  1063,   677,   301,   679,   680,   681,   687,
     693,   697,   698,   699,  1030,   700,   706,   702,   721,  1075,
     729,   730,   731,  1079,  1143,  1080,   750,   746,   313,   707,
     732,   747,  1085,   763,   764,   748,   765,  1089,   770,   981,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   771,   777,   314,   773,   301,   774,
     783,  1105,   794,  1108,   800,  1111,   791,   281,   807,   801,
    1081,   808,   809,  1010,  1119,  1013,   810,  1016,   811,   814,
     822,   815,  1124,  1125,   816,   817,   818,   819,   820,  1128,
     821,   830,   832,   831,   838,   839,  1130,   840,   842,  1133,
     841,   843,   847,   852,   853,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   494,   299,   300,   963,
     854,   855,   856,   301,   863,   857,   873,   858,   880,   890,
     897,  1163,   902,   879,  1167,   905,  1211,  1171,   898,   906,
     909,  1174,   903,   904,   910,   908,   912,   917,   918,  1179,
     946,   947,  1181,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,  1234,   952,  1237,   931,   301,   945,
     953,   954,   967,   948,    75,   308,   968,   979,  1002,   970,
      79,    80,    81,   973,  1249,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,  1106,   974,  1109,   975,
    1112,   976,   982,   983,   309,   984,     7,     8,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     987,   989,   993,   991,   301,    31,    32,    33,    34,    35,
     992,   996,   997,    38,   998,   999,    41,   463,    13,    14,
     464,    16,    17,   465,    19,   466,    21,  1000,    22,  1001,
      24,    25,  1011,    27,    28,    29,  1014,  1017,  1020,  1043,
    1040,  1044,  1048,  1046,  1047,   109,   110,   111,   112,  1049,
    1055,  1073,  1058,  1061,  1057,  1059,  1062,  1071,  1064,    45,
      46,    47,   117,   310,  1066,  1068,  1070,   119,  1074,  1076,
    1078,  1083,   122,  1090,  1092,  1094,  1095,   125,  1096,  1097,
     509,    75,    76,    77,  1100,    78,  1098,    79,    80,    81,
    1123,  1127,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   553,   103,   104,   105,   106,  1129,  1132,
     107,  1144,  1145,  1148,  1150,  1157,  1159,  1161,  1164,    75,
     308,  1165,  1173,  1168,  1169,    79,    80,    81,  1172,  1182,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,  1189,  1183,  1185,  1194,  1187,  1195,  1201,  1204,   309,
    1207,  1199,  1214,  1215,  1151,  1213,   108,  1217,  1219,  1221,
    1225,  1228,   109,   110,   111,   112,   113,   114,   115,   116,
      31,    32,    33,    34,    35,  1227,  1230,  1232,    38,   117,
     118,    41,  1235,  1239,   119,  1245,   120,   121,  1246,   122,
    1247,   123,  1248,   124,   125,  1250,   126,   900,   892,    64,
      71,     0,   969,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   327,     0,
       0,     0,   119,     0,     0,     0,     0,   122,     0,    75,
     308,     0,   125,     0,   328,    79,    80,    81,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,   309,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,    34,    35,   484,     0,     0,    38,     0,
       0,    41,   463,    13,    14,   464,    16,    17,   465,    19,
     466,    21,     0,    22,     0,    24,    25,     0,    27,    28,
      29,     0,     0,     0,     0,     0,   633,     0,     0,     0,
     109,   110,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,    46,    47,   117,   310,     0,
       0,     0,   119,     0,     0,     0,     0,   122,     0,    75,
     308,     0,   125,     0,   508,    79,    80,    81,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,   569,   309,
       0,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
      31,    32,    33,    34,    35,     0,     0,     0,    38,     0,
       0,    41,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   310,     0,
       0,     0,   119,     0,     0,     0,     0,   122,     0,    75,
     268,   207,   125,     0,   684,    79,    80,    81,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,   103,   104,   105,   106,    75,   268,   107,     7,
       8,     0,    79,    80,    81,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,     0,     0,
     463,    13,    14,   464,    16,    17,   465,    19,   466,    21,
       0,    22,     0,    24,    25,     0,    27,    28,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,    45,    46,    47,     0,     0,   117,   118,     0,
       0,     0,   119,     0,     0,     0,     0,   122,     0,     0,
       0,     0,   125,     0,  1032,     0,     0,   109,   110,   111,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   772,   117,   118,     0,     0,     0,   119,
       0,     0,     0,     0,   122,     0,   570,   273,     0,   125,
       0,   274,    75,   268,     0,     0,     0,     0,    79,    80,
      81,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,    75,   268,     7,
       8,     0,     0,    79,    80,    81,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     463,    13,    14,   464,    16,    17,   465,    19,   466,    21,
       0,    22,     0,    24,    25,     0,    27,    28,    29,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   109,   110,   111,   112,   301,     0,     0,
       0,     0,    45,    46,    47,     0,     0,     0,     0,     0,
     117,   118,     0,     0,     0,   119,     0,     0,     0,     0,
     122,     0,     0,   662,     0,   125,     0,   663,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   360,   361,     0,   812,     0,
     119,     0,     0,     0,     0,   362,   718,    75,   308,     0,
     125,     0,   171,    79,    80,    81,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,   309,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,    31,    32,
      33,    34,    35,     0,    75,   268,    38,     0,     0,    41,
      79,    80,    81,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,     0,   109,   110,
     111,   112,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,   310,     0,     0,     0,
     119,     0,     0,     0,     0,   122,     0,     0,     0,     0,
     125,     0,     0,   463,    13,    14,   464,    16,    17,   465,
      19,   466,    21,     0,    22,     0,    24,    25,     0,    27,
      28,    29,     0,     0,     0,     0,     0,     0,   806,     0,
       0,     0,     0,     0,     0,   109,   110,   111,   112,     7,
       8,     0,     0,     0,     0,    45,    46,    47,     0,     0,
       0,     0,   117,   118,     0,     0,     0,   119,     7,     8,
       0,     0,   122,   837,     0,     0,     0,   125,     0,     0,
     463,    13,    14,   464,    16,    17,   465,    19,   466,    21,
       0,    22,   881,    24,    25,     0,    27,    28,    29,   463,
      13,    14,   464,    16,    17,   465,    19,   466,    21,   734,
      22,  1045,    24,    25,     0,    27,    28,    29,     0,     0,
       0,     0,    45,    46,    47,     0,     0,     0,     0,     0,
    1060,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,    46,    47,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,  1082,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1146,  1149,     0,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,  1192,  1190,   301,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   493,     0,     0,     0,   301,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     564,     0,     0,     0,   301,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   655,     0,
       0,     0,   301,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   790,     0,     0,
       0,   301,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   849,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   511,   299,   300,     0,
       0,     0,     0,   301,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,    -4,     1,     0,   301,    -4,
       0,     0,     0,     0,     0,     0,     0,    -4,    -4,     0,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
      -4,     0,     0,     0,     0,    -4,    -4,   688,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,    -4,    -4,     6,     0,     0,     0,    -4,
      -4,    -4,    -4,     7,     8,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     0,     0,     0,     0,     0,     9,     0,     0,     0,
       0,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,    22,    23,    24,    25,    26,
      27,    28,    29,     0,    30,    31,    32,    33,    34,    35,
       0,    36,    37,    38,    39,    40,    41,     7,     8,    42,
      43,     0,     0,     0,     0,    44,    45,    46,    47,     0,
       0,    48,     0,    49,     0,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,     0,   463,    13,
      14,   464,    16,    17,   465,    19,   466,    21,     0,    22,
       0,    24,    25,     0,    27,    28,    29,     0,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
      45,    46,    47,  1007,     0,  1008,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,     0,     0,
       0,  1027,     0,  1028,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,  1103,
       0,  1104,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,     0,     0,   695,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,     0,     0,     0,     0,     0,   744,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,     0,     0,   789,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,     0,     0,
       0,     0,     0,   826,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,     0,
       0,  1005,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,     0,     0,  1022,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,     0,     0,     0,     0,     0,  1051,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,     0,     0,  1052,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,     0,     0,
       0,     0,     0,  1053,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,     0,
       0,  1054,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,     0,     0,  1077,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,     0,     0,     0,     0,     0,  1118,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,     0,     0,  1120,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,     0,     0,
       0,     0,     0,  1121,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,     0,
       0,  1134,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,     0,     0,  1137,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,     0,     0,     0,     0,     0,  1140,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,     0,     0,  1158,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,     0,     0,
       0,     0,     0,  1160,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,     0,
       0,  1184,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,     0,     0,  1186,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,     0,     0,     0,     0,     0,  1188,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,     0,     0,  1198,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,   451,     0,     0,     0,
       0,   532,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,   487,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,   532,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,   533,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,     0,     0,     0,   561,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,     0,     0,
       0,   608,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,   609,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,   622,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,   623,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,     0,     0,     0,   624,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,     0,     0,
       0,   625,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,   626,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,   627,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,   709,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,     0,     0,     0,   710,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,     0,     0,
       0,   711,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,   786,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,   824,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,   825,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,     0,     0,     0,   848,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,     0,     0,
       0,   958,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,   959,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,   978,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,   990,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,     0,     0,     0,  1086,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,     0,     0,
       0,  1087,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,  1093,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,  1099,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,  1153,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,     0,     0,     0,  1156,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,   455,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,   566,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,   572,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,   587,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
     589,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,     0,     0,   591,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,   593,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,     0,   595,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,   597,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,   599,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,   601,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,   603,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,   605,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,   607,   287,   288,
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
       0,     0,   619,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,   621,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,   724,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,   725,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,     0,     0,   727,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,     0,     0,   728,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,     0,     0,
     739,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,     0,     0,   740,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,     0,     0,   762,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,     0,     0,   865,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
       0,     0,   867,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,     0,     0,   869,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,     0,     0,   871,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,     0,
       0,   971,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,   451,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,   488,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,   497,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,   498,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,   500,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,   502,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,   503,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,   506,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
     507,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,   514,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,   557,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,   558,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,   559,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,   565,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,   586,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,   588,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,   590,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,   592,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
     594,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,   596,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,   598,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,   600,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,   602,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,   604,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,   606,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,   610,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,   612,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,   614,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
     616,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,   618,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,   620,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,   673,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,   678,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,   686,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,   689,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,   690,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,   696,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,   701,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
     723,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301,
       0,   864,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,     0,     0,
     301,     0,   866,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,     0,     0,     0,
       0,   301,     0,   868,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,     0,     0,
       0,     0,   301,     0,   870,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,     0,
       0,     0,     0,   301,     0,   874,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,   301,     0,  1006,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,     0,     0,     0,     0,   301,     0,  1021,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,   301,     0,  1031,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,   301,     0,  1152,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,   301,     0,
    1196,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,     0,     0,   301
};

static const yytype_int16 yycheck[] =
{
      59,     6,     6,   354,   355,  1040,   179,    49,     3,   276,
       6,     4,     6,   186,     4,     5,    69,     4,     6,     4,
       4,     7,   648,     4,  1059,    49,     4,     4,     7,     0,
      70,     6,     6,    69,    69,   208,    76,    77,   211,     4,
       4,     6,     6,   121,   122,   132,    36,    37,    38,    39,
     137,   131,    42,     6,   131,    69,   133,    70,   138,   137,
     715,   151,   131,    76,    77,   121,   122,   157,   158,   138,
     121,   122,     4,     4,     5,   719,     6,   131,   131,   128,
     129,   137,    78,   139,   138,   138,   137,    13,   139,   131,
     131,   181,   182,    80,    81,    82,    83,   128,   129,   139,
     121,   122,   138,   138,   135,    36,    37,    38,    39,    90,
      91,    42,     6,   117,   118,   119,   137,   131,   122,   123,
    1155,    98,   131,   127,   138,   111,   139,   121,   122,   133,
     118,   126,   136,   138,   138,   139,   140,   141,   131,   143,
     144,   145,   146,    53,   148,   149,   150,   773,   138,   153,
     128,   129,   139,   138,   138,   133,   135,   135,    90,    91,
      49,   138,   140,   139,   138,   118,   170,   171,   144,   133,
       7,   131,   148,    32,    33,   179,    35,    70,  1213,   121,
     122,   836,   144,    76,    77,   131,   148,   133,   455,   193,
     194,   195,   365,   197,    70,   137,   200,   201,   131,   203,
      76,    77,   131,   262,   263,   264,   265,   138,    70,   131,
     214,   384,     6,     7,    76,    77,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   884,   131,
      70,   133,   266,   139,   121,   122,    76,    77,   121,   122,
     274,   108,   109,   110,   111,   131,   131,   139,   133,    49,
       7,   138,    49,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   274,    43,
      51,   276,    46,    49,   132,    49,   310,    51,   167,   137,
     169,   131,   274,   133,   318,    43,   175,   131,    46,   323,
     179,    49,    46,   327,   328,    49,     8,    51,   332,   139,
     334,   335,   336,   138,   310,   339,   340,   341,   342,   343,
     344,   345,     4,     5,     4,   341,   342,   343,   344,   121,
     122,   327,   328,   357,   358,   359,   360,   361,   362,   354,
     355,   138,   452,   453,   368,   137,   328,   371,   372,   121,
     122,   375,   376,   377,    36,    37,    38,    39,    49,    49,
      42,   108,   109,   110,   111,   137,   390,   139,    46,   131,
      70,   133,   396,   121,   122,   399,    76,    77,   131,   375,
     133,   128,   129,   131,    64,    65,    66,    67,   135,   132,
     138,   132,    72,   375,   137,    75,   137,   342,   343,   344,
    1046,     4,  1066,   398,  1068,   131,  1070,   133,    46,   519,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   121,   122,   450,     4,   130,   121,
     122,     4,  1107,   457,   131,  1110,    70,   139,  1113,   139,
     456,   138,    76,    77,    70,   137,   128,   129,    70,     6,
      76,    77,   131,   135,    76,    77,   131,   131,   121,   122,
     455,    70,   486,   487,   131,   489,   490,    76,    77,   493,
     494,   495,     7,   352,   353,   138,   121,   122,   765,   766,
     121,   122,   361,  1147,   508,     7,   132,   511,   512,   133,
     486,   137,   137,   572,   518,     4,    70,   138,   494,   495,
    1175,     4,    76,    77,   486,   139,   138,   131,   532,   533,
     131,   131,   508,   139,   538,   511,   131,   139,   133,  1183,
     131,  1185,   546,  1187,   548,  1200,   508,   131,  1203,  1193,
     139,  1206,     7,   131,  1209,   133,   131,   561,   133,   563,
     564,     4,    70,   121,   122,   131,     6,   133,    76,    77,
     131,   630,   133,  1217,  1229,  1219,  1231,  1221,  1233,   137,
     931,   671,   672,     6,   674,   139,   676,   677,     6,     5,
     680,   681,   131,   108,   109,   110,   111,   572,   131,   658,
       4,     5,   131,   138,   608,   609,   108,   109,   110,   111,
      70,   131,   131,   128,   129,   138,    76,    77,   622,   623,
     624,   625,   626,   627,     5,   629,   128,   129,   121,   122,
     634,   139,    36,    37,    38,    39,   131,   641,    42,   729,
     730,   731,     4,   131,   137,   133,   131,   651,   652,   653,
     654,   655,   131,   629,   133,    36,    37,    38,    39,   663,
     131,    42,   133,   131,   131,   121,   122,   629,   121,   122,
     121,   122,   531,   131,   131,   651,   652,   653,   654,   139,
     684,   137,   121,   122,   137,   544,   137,   663,   138,   651,
     652,   653,   654,   138,   138,   128,   129,   131,   137,     6,
     133,   663,   135,   133,   794,   138,     6,   140,   684,   138,
     800,  1062,   133,   133,   121,   122,   123,   124,   125,   809,
     810,   811,   684,   130,     6,   815,   816,   817,   818,   819,
     820,   821,   131,   131,   133,   133,   138,    93,     3,     4,
       5,   831,   746,   747,     9,    10,    11,   135,     6,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
     774,    36,    37,    38,    39,   133,   131,    42,   133,   131,
       6,   133,   786,   128,   129,   875,   790,   762,   133,     4,
     135,   766,   123,   124,   125,   140,   131,     6,   133,   130,
     138,   133,   661,   135,   808,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   823,
     824,   825,   137,   130,   139,     6,     5,   831,   832,   135,
      49,   835,    51,   892,   838,   137,   137,   139,   139,   104,
     105,   106,   107,   130,   848,   849,   850,   137,     7,   139,
     709,   710,   711,   133,   858,     8,   121,   122,   948,   863,
     138,   126,   838,   137,   139,   139,   131,   137,     7,   139,
     960,   136,   138,   877,     7,   137,   838,   139,     7,   132,
     876,   856,     6,     8,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   897,   137,     7,   139,   130,     7,   903,
     904,  1074,    90,   137,   908,   139,   137,   137,   139,   139,
     137,     4,   139,   917,   137,   137,   139,   139,   138,   137,
     137,   139,   139,   927,   137,   137,   139,   139,     6,   137,
    1020,   927,   137,   137,     6,   139,   931,   137,   137,   139,
     139,   945,   137,   137,   139,   139,   137,   132,   139,   953,
     137,   137,   139,   139,   958,   959,   132,   953,     4,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   134,   978,  1148,   835,   130,     7,   132,
      93,     7,     7,  1073,     7,    93,   990,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,     8,     7,  1007,     7,   130,    93,     7,     7,     7,
       4,   132,   132,   132,   139,   132,   139,   135,     6,  1023,
       7,     7,     7,  1027,  1114,  1029,     6,   131,  1032,   139,
     135,   131,  1036,     6,     6,   138,   134,  1041,     6,   898,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,     6,     6,  1032,     7,   130,   133,
     118,  1065,     7,  1067,     7,  1069,    49,  1062,     7,    51,
    1032,   138,     7,   932,  1078,   934,     7,   936,     7,     6,
       4,     7,  1086,  1087,     7,     7,     7,     7,     7,  1093,
       7,     6,   131,   138,   138,     6,  1100,     6,     6,  1103,
      49,     6,     4,     4,     4,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,  1123,
     135,     6,     4,   130,   138,     6,   132,   131,     7,     6,
     138,  1135,     6,   135,  1138,     6,  1195,  1141,    56,     6,
       6,  1145,   138,   138,     6,   138,     5,     4,     6,  1153,
       6,     6,  1156,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,  1223,     6,  1225,   138,   130,   138,
       7,     4,     6,    89,     3,     4,     4,   134,     4,     6,
       9,    10,    11,     6,  1243,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,  1065,     6,  1067,     6,
    1069,     6,     6,     6,    43,     6,    12,    13,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
       6,     5,    93,     6,   130,    64,    65,    66,    67,    68,
       6,     6,     6,    72,     6,     6,    75,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     6,    54,     6,
      56,    57,     6,    59,    60,    61,     6,     6,   137,     6,
     138,     6,   135,     7,     6,   104,   105,   106,   107,     6,
       5,     7,     6,     6,    47,   138,   138,     6,   139,    85,
      86,    87,   121,   122,   138,   138,   138,   126,   138,     6,
      88,     6,   131,     6,    91,     6,     6,   136,     6,     6,
     139,     3,     4,     5,   138,     7,     6,     9,    10,    11,
     138,     6,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   139,    36,    37,    38,    39,     5,   139,
      42,     6,    62,   138,     6,   137,     6,     6,     6,     3,
       4,     6,   139,     6,     6,     9,    10,    11,     6,     5,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     6,   138,   138,     6,   138,   138,     6,     6,    43,
       6,   137,     6,     5,  1123,   138,    98,   138,   138,   138,
     138,     6,   104,   105,   106,   107,   108,   109,   110,   111,
      64,    65,    66,    67,    68,   139,     6,     6,    72,   121,
     122,    75,     6,     6,   126,     6,   128,   129,     6,   131,
       6,   133,     6,   135,   136,     6,   138,   793,   785,     3,
       3,    -1,   880,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,
      -1,    -1,   126,    -1,    -1,    -1,    -1,   131,    -1,     3,
       4,    -1,   136,    -1,   138,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    67,    68,     6,    -1,    -1,    72,    -1,
      -1,    75,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    -1,    56,    57,    -1,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
     104,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,   121,   122,    -1,
      -1,    -1,   126,    -1,    -1,    -1,    -1,   131,    -1,     3,
       4,    -1,   136,    -1,   138,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    43,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    72,    -1,
      -1,    75,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,
      -1,    -1,   126,    -1,    -1,    -1,    -1,   131,    -1,     3,
       4,     5,   136,    -1,   138,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,     3,     4,    42,    12,
      13,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    -1,    56,    57,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    -1,    -1,   121,   122,    -1,
      -1,    -1,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,   136,    -1,   138,    -1,    -1,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,   121,   122,    -1,    -1,    -1,   126,
      -1,    -1,    -1,    -1,   131,    -1,   139,   134,    -1,   136,
      -1,   138,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,     3,     4,    12,
      13,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    -1,    56,    57,    -1,    59,    60,    61,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   104,   105,   106,   107,   130,    -1,    -1,
      -1,    -1,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
     121,   122,    -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,
     131,    -1,    -1,   134,    -1,   136,    -1,   138,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    62,    -1,
     126,    -1,    -1,    -1,    -1,   131,   139,     3,     4,    -1,
     136,    -1,   138,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    64,    65,
      66,    67,    68,    -1,     3,     4,    72,    -1,    -1,    75,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,   104,   105,
     106,   107,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    -1,    56,    57,    -1,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,    12,
      13,    -1,    -1,    -1,    -1,    85,    86,    87,    -1,    -1,
      -1,    -1,   121,   122,    -1,    -1,    -1,   126,    12,    13,
      -1,    -1,   131,     6,    -1,    -1,    -1,   136,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,     6,    56,    57,    -1,    59,    60,    61,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,   139,
      54,     6,    56,    57,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,     6,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,     6,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,   139,     6,   130,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,     8,    -1,    -1,    -1,   130,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
       8,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,     8,    -1,
      -1,    -1,   130,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,     8,    -1,    -1,
      -1,   130,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     8,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,   130,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,     0,     1,    -1,   130,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      35,    -1,    -1,    -1,    -1,    40,    41,   139,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    -1,    -1,    78,    79,     4,    -1,    -1,    -1,    84,
      85,    86,    87,    12,    13,    90,    -1,    92,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    40,    41,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    12,    13,    78,
      79,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    -1,
      -1,    90,    -1,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      -1,    56,    57,    -1,    59,    60,    61,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      85,    86,    87,   137,    -1,   139,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,   139,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,   139,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,   132,    -1,    -1,    -1,
      -1,   137,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,   134,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,   134,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,   134,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,   134,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
     134,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,   134,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,   134,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,   134,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,   134,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,   134,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,   134,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,   134,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,   134,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,   134,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
     134,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,   134,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,   134,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,   134,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,   134,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,   134,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,   134,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,   134,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,   134,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,   134,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
     134,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,   134,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,   134,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,   134,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,   134,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,   134,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,   134,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,   134,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,   132,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,   130,    -1,   132,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,   132,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,   130,    -1,   132,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,   132,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,   130,    -1,   132,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,   132,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,   132,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
     132,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,
      -1,   132,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,   132,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,   130,    -1,   132,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,   132,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,   130,    -1,   132,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,   132,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,   130,    -1,   132,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,   132,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,   132,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
     132,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,
      -1,   132,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,   132,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,   130,    -1,   132,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,   132,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,   130,    -1,   132,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,   132,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,   130,    -1,   132,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,   132,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,   132,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
     132,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,
      -1,   132,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,   132,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,   130,    -1,   132,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,   132,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,   130,    -1,   132,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,   132,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,   130,    -1,   132,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,   132,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,   132,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
     132,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,
      -1,   132,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
     130,    -1,   132,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,   130,    -1,   132,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,   130,    -1,   132,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,   130,    -1,   132,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,   132,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,   130,    -1,   132,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,   130,    -1,   132,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,   132,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,   130,    -1,
     132,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,   130
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   142,   143,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    55,    56,    57,    58,    59,    60,    61,
      63,    64,    65,    66,    67,    68,    70,    71,    72,    73,
      74,    75,    78,    79,    84,    85,    86,    87,    90,    92,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     144,   146,   147,   165,   169,   170,   173,   174,   175,   176,
     177,   178,   198,   199,   200,     3,     4,     5,     7,     9,
      10,    11,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    36,    37,    38,    39,    42,    98,   104,
     105,   106,   107,   108,   109,   110,   111,   121,   122,   126,
     128,   129,   131,   133,   135,   136,   138,   163,   164,   201,
     202,   213,    13,    49,   131,     6,   138,     6,   131,   138,
     131,   131,    69,   131,   138,   131,   131,    69,   138,   131,
     131,    53,    49,   131,    49,    49,    49,    46,    49,    51,
      51,    43,    46,    49,    51,    49,   131,   138,   121,   122,
     131,   138,   203,   204,   203,   138,    43,    46,    49,   138,
     203,    49,    49,    46,     4,    98,   138,     4,     6,    46,
       4,     4,     4,   131,   131,   131,     4,   138,   209,     4,
     131,   131,     6,   133,     4,     4,     4,     5,   138,   212,
     213,   138,   212,     4,   133,   135,   140,   164,   138,   213,
     131,   133,   131,   133,   131,   133,   131,   133,   131,   133,
     131,   133,   131,   133,   131,   133,   131,   133,   131,   133,
     131,   133,   131,   133,   131,   133,   131,   133,   131,   133,
     131,   133,   131,   133,   131,   133,   131,   133,   131,   133,
     131,   133,   131,   131,   131,   131,     7,   131,     4,   201,
     201,   201,   201,   134,   138,   201,     4,    90,    91,     4,
       4,   170,   171,   172,   201,     6,     6,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   130,     6,     6,   201,     5,   201,   201,     4,    43,
     122,   170,   178,   201,   207,   208,   201,   201,   131,   201,
     208,   201,   201,   131,   208,   201,   201,   122,   138,   201,
     206,   207,   131,   201,   138,   131,   131,   206,   206,   138,
     131,   131,   131,   131,   131,   131,     4,   203,   203,   203,
     201,   201,   121,   122,   138,   138,   203,   138,   138,   138,
     121,   122,   131,   172,   203,   138,   206,   206,   131,     4,
       6,   133,   133,   172,     6,   138,   133,   133,     6,   201,
     201,   201,   135,   201,   138,    93,   201,   201,   201,     6,
     133,   135,   172,     6,   172,     6,   133,   201,     4,   138,
     148,     6,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   212,   212,   212,   212,   201,     5,
     133,   132,     7,   111,   208,   134,     7,   163,   164,   135,
       7,   133,   139,    43,    46,    49,    51,   169,     6,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,     6,   132,   137,   137,   132,   133,
     138,   201,   207,     8,   123,   137,   139,   132,   132,   201,
     132,   139,   132,   132,   201,   139,   132,   132,   138,   139,
     208,   123,     7,   201,   132,   201,   201,   201,     7,     7,
     196,   201,   201,   166,   201,   213,   166,   166,   166,   201,
     132,   137,   137,   137,   203,   203,   171,   171,   137,   201,
     201,   201,   201,   182,   137,   172,     7,   197,     7,   201,
       6,   201,   201,   139,   208,   201,   201,   132,   132,   132,
      90,   137,   172,   138,     8,   132,   134,   201,     4,   139,
     139,   201,   134,   164,   201,     4,    80,    81,    82,    83,
     139,   151,   155,   158,   160,   161,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   137,   137,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   137,   137,   137,   137,   137,   137,   132,   137,
     137,   132,   132,     6,   137,   201,   206,   206,   139,     7,
     135,   163,   164,   213,   201,     6,     4,     4,   138,   210,
     134,   138,   138,   138,   138,     8,     6,   118,   145,   208,
     201,     7,   134,   138,   201,   201,   201,   207,   201,   207,
      93,     7,     7,   132,     7,    93,     7,     7,   132,    93,
       7,     7,   208,   139,   138,   201,   132,     7,   139,   132,
     132,   201,   206,     4,   195,   139,   132,   132,   132,   132,
     132,   132,   135,   203,   201,   201,   139,   139,   201,   137,
     137,   137,    70,    76,    77,   192,   193,   203,   139,   179,
     201,     6,   201,   132,   134,   134,   139,   134,   134,     7,
       7,     7,   135,   201,   139,   201,   201,     7,   135,   134,
     134,   135,   164,   212,   139,   152,   131,   131,   138,   162,
       6,   201,   201,   201,   201,   201,   201,   201,   201,   208,
     212,   201,   134,     6,     6,   134,     4,    90,    91,   201,
       6,     6,     6,     7,   133,   209,   211,     6,   208,   208,
     208,   208,   201,   118,   212,   132,   137,   203,   208,   139,
       8,    49,   206,   206,     7,   206,    49,    51,   206,   206,
       7,    51,   206,   206,   139,   208,     6,     7,   138,     7,
       7,     7,    62,   194,     6,     7,     7,     7,     7,     7,
       7,     7,     4,   137,   137,   137,   139,   203,   203,   203,
       6,   138,   131,   139,   193,   137,   192,     6,   138,     6,
       6,    49,     6,     6,   206,   206,   206,     4,   137,     8,
       8,   132,     4,     4,   135,     6,     4,     6,   131,   201,
     201,   205,   206,   138,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   132,   132,   163,     7,   163,   164,   135,
       7,     6,   209,   201,   137,   139,   139,   139,   139,   139,
       6,     6,   145,   201,     6,   139,   201,   138,    56,   168,
     168,   206,     6,   138,   138,     6,     6,   206,   138,     6,
       6,   139,     5,   201,   206,   206,   206,     4,     6,   206,
     206,   206,   206,   206,   206,   206,     6,     7,   201,   201,
     201,   138,   137,   139,   137,   139,   137,   139,   201,   206,
     201,   201,   203,   139,   208,   138,     6,     6,    89,   201,
     201,   201,     6,     7,     4,   164,   149,   201,   137,   137,
     137,   139,   150,   201,   206,   213,   201,     6,     4,   210,
       6,   134,   209,     6,     6,     6,     6,   212,   137,   134,
     201,   203,     6,     6,     6,   201,   201,     6,   201,     5,
     137,     6,     6,    93,   167,   201,     6,     6,     6,     6,
       6,     6,     4,   201,   213,   139,   132,   137,   139,   171,
     203,     6,   183,   203,     6,   184,   203,     6,   185,   139,
     137,   132,   139,   137,   139,   201,   206,   137,   139,     8,
     139,   132,   138,   201,   213,   132,   137,   201,   201,   206,
     138,   137,   139,     6,     6,     6,     7,     6,   135,     6,
     201,   139,   139,   139,   139,     5,   201,    47,     6,   138,
       6,     6,   138,   201,   139,   137,   138,   137,   138,   137,
     138,     6,   206,     7,   138,   201,     6,   139,    88,   201,
     201,   208,     6,     6,   153,   201,   137,   137,   205,   201,
       6,   209,    91,   137,     6,     6,     6,     6,     6,   137,
     138,   205,   171,   137,   139,   201,   203,   192,   201,   203,
     192,   201,   203,   192,   137,   139,   206,   172,   139,   201,
     139,   139,   139,   138,   201,   201,   139,     6,   201,     5,
     201,   139,   139,   201,   139,   137,   139,   139,   137,   139,
     139,   137,   139,   206,     6,    62,   139,   180,   138,     6,
       6,   150,   132,   137,     6,   138,   137,   137,   139,     6,
     139,     6,   186,   201,     6,     6,   187,   201,     6,     6,
     188,   201,     6,   139,   201,   192,   172,   139,   156,   201,
     205,   201,     5,   138,   139,   138,   139,   138,   139,     6,
       6,   139,   139,   181,     6,   138,   132,   139,   139,   137,
     192,     6,   189,   192,     6,   190,   192,     6,   191,   192,
     154,   212,   159,   138,     6,     5,   139,   138,   139,   138,
     139,   138,   139,   137,   139,   138,   205,   139,     6,   192,
       6,   192,     6,   192,   212,     6,   157,   212,   139,     6,
     139,   139,   139,   137,   139,     6,     6,     6,     6,   212,
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
#line 140 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 151 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 152 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 153 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 154 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 155 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 156 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 157 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 158 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 159 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 160 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 161 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 162 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 163 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 164 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 169 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 21:
#line 173 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 22:
#line 180 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 23:
#line 185 "Gmsh.y"
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
#line 200 "Gmsh.y"
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
#line 213 "Gmsh.y"
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
#line 242 "Gmsh.y"
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
#line 256 "Gmsh.y"
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
#line 267 "Gmsh.y"
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
#line 281 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData = new PViewDataList(true); 
#endif
    ;}
    break;

  case 35:
#line 295 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 36:
#line 297 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 37:
#line 302 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(1) - (1)].d)); ;}
    break;

  case 38:
#line 304 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(3) - (3)].d)); ;}
    break;

  case 39:
#line 309 "Gmsh.y"
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
#line 455 "Gmsh.y"
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
#line 465 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 42:
#line 474 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(ViewData->T2C, &(yyvsp[(1) - (1)].c)[i]); 
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 43:
#line 481 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(ViewData->T2C, &(yyvsp[(3) - (3)].c)[i]); 
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 44:
#line 491 "Gmsh.y"
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
#line 501 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 46:
#line 510 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(ViewData->T3C, &(yyvsp[(1) - (1)].c)[i]); 
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 47:
#line 517 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(ViewData->T3C, &(yyvsp[(3) - (3)].c)[i]); 
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 48:
#line 527 "Gmsh.y"
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
#line 536 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 50:
#line 546 "Gmsh.y"
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
#line 563 "Gmsh.y"
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
#line 579 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewValueList = ViewData->Time;
#endif
    ;}
    break;

  case 53:
#line 585 "Gmsh.y"
    {
    ;}
    break;

  case 54:
#line 592 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 55:
#line 593 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 56:
#line 594 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 57:
#line 595 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 58:
#line 596 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 59:
#line 600 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 60:
#line 601 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 61:
#line 609 "Gmsh.y"
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
#line 631 "Gmsh.y"
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
#line 658 "Gmsh.y"
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
#line 698 "Gmsh.y"
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
#line 708 "Gmsh.y"
    {
      // appends to the list
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].push_back(*(double*)List_Pointer((yyvsp[(5) - (6)].l), i));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 66:
#line 716 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c)); 
      else
	gmsh_yysymbols[(yyvsp[(1) - (3)].c)][0] += (yyvsp[(2) - (3)].i);
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 67:
#line 724 "Gmsh.y"
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
#line 736 "Gmsh.y"
    { 
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 69:
#line 745 "Gmsh.y"
    { 
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 70:
#line 750 "Gmsh.y"
    { 
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].c));
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 71:
#line 758 "Gmsh.y"
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
#line 776 "Gmsh.y"
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
#line 794 "Gmsh.y"
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
#line 803 "Gmsh.y"
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
#line 815 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 76:
#line 820 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 77:
#line 828 "Gmsh.y"
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
#line 848 "Gmsh.y"
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
#line 871 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->background_field = (int)(yyvsp[(4) - (5)].d);
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
    ;}
    break;

  case 80:
#line 878 "Gmsh.y"
    {
      if(!GModel::current()->getFields()->new_field((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 81:
#line 884 "Gmsh.y"
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
#line 904 "Gmsh.y"
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
#line 925 "Gmsh.y"
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
#line 951 "Gmsh.y"
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
#line 963 "Gmsh.y"
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
#line 980 "Gmsh.y"
    { 
      (yyval.i) = (int)(yyvsp[(1) - (1)].d); 
    ;}
    break;

  case 87:
#line 984 "Gmsh.y"
    { 
      (yyval.i) = GModel::current()->setPhysicalName
	(std::string((yyvsp[(1) - (1)].c)), ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 88:
#line 993 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 89:
#line 997 "Gmsh.y"
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
#line 1011 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 91:
#line 1015 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 92:
#line 1025 "Gmsh.y"
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

  case 93:
#line 1048 "Gmsh.y"
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

  case 94:
#line 1064 "Gmsh.y"
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

  case 95:
#line 1086 "Gmsh.y"
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

  case 96:
#line 1104 "Gmsh.y"
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

  case 97:
#line 1122 "Gmsh.y"
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

  case 98:
#line 1152 "Gmsh.y"
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

  case 99:
#line 1183 "Gmsh.y"
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
#line 1202 "Gmsh.y"
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
#line 1220 "Gmsh.y"
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
#line 1238 "Gmsh.y"
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
#line 1264 "Gmsh.y"
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
#line 1281 "Gmsh.y"
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
#line 1300 "Gmsh.y"
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
#line 1318 "Gmsh.y"
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
#line 1357 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 108:
#line 1363 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 109:
#line 1369 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 110:
#line 1376 "Gmsh.y"
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
#line 1401 "Gmsh.y"
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
#line 1426 "Gmsh.y"
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
#line 1442 "Gmsh.y"
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
#line 1459 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (12)].d);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (12)].l));
	List_T *S[4] = {0,0,0,0};
	for (int i=0;i<List_Nbr((yyvsp[(10) - (12)].l));i++){
	  List_T *ll;
	  List_Read((yyvsp[(10) - (12)].l),i,&ll);
	  S[i] = ListOfDouble2ListOfInt(ll);
	}
	
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp, S);
	List_Delete(temp);
	for (int i=0;i<List_Nbr((yyvsp[(10) - (12)].l));i++)
	  List_Delete(S[i]);
	
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (12)].l));
      Free((yyvsp[(8) - (12)].c));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    ;}
    break;

  case 115:
#line 1490 "Gmsh.y"
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

  case 116:
#line 1508 "Gmsh.y"
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

  case 117:
#line 1525 "Gmsh.y"
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

  case 118:
#line 1546 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 119:
#line 1551 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 120:
#line 1556 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 121:
#line 1561 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 122:
#line 1566 "Gmsh.y"
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

  case 123:
#line 1586 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 124:
#line 1592 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp=ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d),tmp,(yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 125:
#line 1602 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 126:
#line 1603 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 127:
#line 1608 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 128:
#line 1612 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 129:
#line 1616 "Gmsh.y"
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

  case 130:
#line 1639 "Gmsh.y"
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

  case 131:
#line 1662 "Gmsh.y"
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

  case 132:
#line 1685 "Gmsh.y"
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

  case 133:
#line 1713 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 134:
#line 1722 "Gmsh.y"
    {
      GModel::current()->getFields()->delete_field((int)(yyvsp[(4) - (6)].d));
    ;}
    break;

  case 135:
#line 1726 "Gmsh.y"
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

  case 136:
#line 1741 "Gmsh.y"
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

  case 137:
#line 1762 "Gmsh.y"
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

  case 138:
#line 1779 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));      
    ;}
    break;

  case 139:
#line 1793 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 140:
#line 1799 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 141:
#line 1805 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 142:
#line 1814 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 143:
#line 1828 "Gmsh.y"
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

  case 144:
#line 1876 "Gmsh.y"
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

  case 145:
#line 1894 "Gmsh.y"
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

  case 146:
#line 1909 "Gmsh.y"
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

  case 147:
#line 1928 "Gmsh.y"
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

  case 148:
#line 1940 "Gmsh.y"
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

  case 149:
#line 1964 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 150:
#line 1968 "Gmsh.y"
    {
      CTX.forced_bbox = 0;
      SetBoundingBox();
    ;}
    break;

  case 151:
#line 1973 "Gmsh.y"
    {
      CTX.forced_bbox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 152:
#line 1978 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      Draw();
#endif
    ;}
    break;

  case 153:
#line 1990 "Gmsh.y"
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

  case 154:
#line 2007 "Gmsh.y"
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

  case 155:
#line 2024 "Gmsh.y"
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

  case 156:
#line 2043 "Gmsh.y"
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

  case 157:
#line 2062 "Gmsh.y"
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

  case 158:
#line 2090 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname,
						      gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 159:
#line 2098 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&gmsh_yyin, gmsh_yyname,
						     gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 160:
#line 2104 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname,
						     gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 161:
#line 2111 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 162:
#line 2115 "Gmsh.y"
    {
    ;}
    break;

  case 163:
#line 2124 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 164:
#line 2132 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 165:
#line 2140 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 166:
#line 2148 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 167:
#line 2152 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 168:
#line 2160 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 169:
#line 2164 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 170:
#line 2172 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 171:
#line 2176 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 172:
#line 2184 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 173:
#line 2188 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 174:
#line 2197 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 175:
#line 2204 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 176:
#line 2211 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 177:
#line 2218 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 178:
#line 2225 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 179:
#line 2232 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 180:
#line 2239 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 181:
#line 2246 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 182:
#line 2253 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 183:
#line 2260 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 184:
#line 2264 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 185:
#line 2271 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 186:
#line 2275 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 187:
#line 2282 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 188:
#line 2286 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 189:
#line 2293 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 190:
#line 2297 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 191:
#line 2304 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 192:
#line 2308 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 193:
#line 2315 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 194:
#line 2319 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 195:
#line 2326 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 196:
#line 2330 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 197:
#line 2337 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 198:
#line 2341 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 199:
#line 2348 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 200:
#line 2352 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 201:
#line 2363 "Gmsh.y"
    {
    ;}
    break;

  case 202:
#line 2366 "Gmsh.y"
    {
    ;}
    break;

  case 203:
#line 2372 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 204:
#line 2381 "Gmsh.y"
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

  case 205:
#line 2401 "Gmsh.y"
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

  case 206:
#line 2424 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 207:
#line 2428 "Gmsh.y"
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

  case 208:
#line 2451 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 209:
#line 2455 "Gmsh.y"
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

  case 210:
#line 2470 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 211:
#line 2474 "Gmsh.y"
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

  case 212:
#line 2486 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 213:
#line 2490 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 214:
#line 2495 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 215:
#line 2499 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 216:
#line 2506 "Gmsh.y"
    {
      int type = (int)(yyvsp[(6) - (7)].v)[0];
      double coef = fabs((yyvsp[(6) - (7)].v)[1]);
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (7)].l), i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j);
	if(c){
	  c->Method = MESH_TRANSFINITE;
	  c->nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
	  c->typeTransfinite = type * sign(d);
	  c->coeffTransfinite = coef;
	}
        else{
	  GEdge *ge = GModel::current()->getEdgeByTag(j);
          if(ge){
            ge->meshAttributes.Method = MESH_TRANSFINITE;
            ge->meshAttributes.nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
            ge->meshAttributes.typeTransfinite = type * sign(d);
            ge->meshAttributes.coeffTransfinite = coef;
          }
          else
	    yymsg(0, "Unknown line %d", j);
        }
      }
      List_Delete((yyvsp[(3) - (7)].l));
    ;}
    break;

  case 217:
#line 2535 "Gmsh.y"
    {
      int k = List_Nbr((yyvsp[(4) - (6)].l));
      if(k != 0 && k != 3 && k != 4){
        yymsg(0, "Wrong definition of Transfinite Surface: 0, 3 or 4 points needed");
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
      }
      List_Delete((yyvsp[(3) - (6)].l));
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 218:
#line 2583 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 219:
#line 2588 "Gmsh.y"
    {
      int k = List_Nbr((yyvsp[(7) - (8)].l));
      if(k != 6 && k != 8){
        yymsg(0, "Wrong definition of Transfinite Volume %d: "
              "%d points instead of 6 or 8" , (int)(yyvsp[(4) - (8)].d), k);
      }
      else{
        Volume *v = FindVolume((int)(yyvsp[(4) - (8)].d));
        if(v){
          v->Method = MESH_TRANSFINITE;
	  List_Reset(v->TrsfPoints);
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read((yyvsp[(7) - (8)].l), i, &d);
	    Vertex *vert = FindPoint((int)fabs(d));
	    if(vert)
	      List_Add(v->TrsfPoints, &vert);
	    else
	      yymsg(0, "Unknown point %d", (int)fabs(d));
	  }
	}
        else{
	  GRegion *gr = GModel::current()->getRegionByTag((int)(yyvsp[(4) - (8)].d));
          if(gr){
            gr->meshAttributes.Method = MESH_TRANSFINITE;
            for(int i = 0; i < k; i++){
              double d;
              List_Read((yyvsp[(7) - (8)].l), i, &d);
              GVertex *gv = GModel::current()->getVertexByTag((int)fabs(d));
              if(gv)
                gr->meshAttributes.corners.push_back(gv);
              else
                yymsg(0, "Unknown point %d", (int)fabs(d));
            }
          }
          else
            yymsg(0, "Unknown volume %d", (int)(yyvsp[(4) - (8)].d));
        }
      }
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 220:
#line 2630 "Gmsh.y"
    {
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
    ;}
    break;

  case 221:
#line 2652 "Gmsh.y"
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

  case 222:
#line 2678 "Gmsh.y"
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

  case 223:
#line 2701 "Gmsh.y"
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

  case 224:
#line 2724 "Gmsh.y"
    {
    ;}
    break;

  case 225:
#line 2727 "Gmsh.y"
    {
    ;}
    break;

  case 226:
#line 2736 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 227:
#line 2740 "Gmsh.y"
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

  case 228:
#line 2755 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 229:
#line 2756 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 230:
#line 2757 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 231:
#line 2758 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 232:
#line 2759 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 233:
#line 2760 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 234:
#line 2761 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 235:
#line 2762 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 236:
#line 2764 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 237:
#line 2770 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 238:
#line 2771 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 239:
#line 2772 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 240:
#line 2773 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 241:
#line 2774 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 242:
#line 2775 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 243:
#line 2776 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 244:
#line 2777 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 245:
#line 2778 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 246:
#line 2779 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 247:
#line 2780 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 248:
#line 2781 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 249:
#line 2782 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 250:
#line 2783 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 251:
#line 2784 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 252:
#line 2785 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 253:
#line 2786 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 254:
#line 2787 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 255:
#line 2788 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 256:
#line 2789 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 257:
#line 2790 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 258:
#line 2791 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 259:
#line 2792 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 260:
#line 2793 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 261:
#line 2794 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 262:
#line 2795 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 263:
#line 2796 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 264:
#line 2797 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 265:
#line 2798 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 266:
#line 2799 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 267:
#line 2800 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 268:
#line 2801 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 269:
#line 2803 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 270:
#line 2804 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 271:
#line 2805 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 272:
#line 2806 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 273:
#line 2807 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 274:
#line 2808 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 275:
#line 2809 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 276:
#line 2810 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 277:
#line 2811 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 278:
#line 2812 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 279:
#line 2813 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 280:
#line 2814 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 281:
#line 2815 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 282:
#line 2816 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 283:
#line 2817 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 284:
#line 2818 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 285:
#line 2819 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 286:
#line 2820 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 287:
#line 2821 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 288:
#line 2822 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 289:
#line 2823 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 290:
#line 2832 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 291:
#line 2833 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 292:
#line 2834 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 293:
#line 2835 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 294:
#line 2836 "Gmsh.y"
    { (yyval.d) = Get_GmshMajorVersion(); ;}
    break;

  case 295:
#line 2837 "Gmsh.y"
    { (yyval.d) = Get_GmshMinorVersion(); ;}
    break;

  case 296:
#line 2838 "Gmsh.y"
    { (yyval.d) = Get_GmshPatchVersion(); ;}
    break;

  case 297:
#line 2843 "Gmsh.y"
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

  case 298:
#line 2856 "Gmsh.y"
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

  case 299:
#line 2868 "Gmsh.y"
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

  case 300:
#line 2883 "Gmsh.y"
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

  case 301:
#line 2893 "Gmsh.y"
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

  case 302:
#line 2903 "Gmsh.y"
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

  case 303:
#line 2921 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 304:
#line 2926 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 305:
#line 2931 "Gmsh.y"
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

  case 306:
#line 2941 "Gmsh.y"
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

  case 307:
#line 2951 "Gmsh.y"
    { 
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 308:
#line 2959 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 309:
#line 2963 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 310:
#line 2967 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 311:
#line 2971 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 312:
#line 2975 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 313:
#line 2982 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 314:
#line 2986 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 315:
#line 2990 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 316:
#line 2994 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 317:
#line 3001 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 318:
#line 3006 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 319:
#line 3013 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 320:
#line 3018 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 321:
#line 3022 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 322:
#line 3027 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 323:
#line 3031 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 324:
#line 3039 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 325:
#line 3050 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 326:
#line 3058 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 327:
#line 3066 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); 
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 328:
#line 3073 "Gmsh.y"
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

  case 329:
#line 3084 "Gmsh.y"
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

  case 330:
#line 3104 "Gmsh.y"
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
#line 3114 "Gmsh.y"
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
#line 3124 "Gmsh.y"
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

  case 333:
#line 3134 "Gmsh.y"
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

  case 334:
#line 3154 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 335:
#line 3159 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 336:
#line 3163 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 337:
#line 3167 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 338:
#line 3179 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 339:
#line 3183 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 340:
#line 3195 "Gmsh.y"
    {
      int flag;
      (yyval.u) = Get_ColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 341:
#line 3202 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 342:
#line 3212 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 343:
#line 3216 "Gmsh.y"
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

  case 344:
#line 3231 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 345:
#line 3236 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 346:
#line 3243 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 347:
#line 3247 "Gmsh.y"
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

  case 348:
#line 3260 "Gmsh.y"
    { 
      const char *val = "";
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), val);
      (yyval.c) = (char*)Malloc((strlen(val) + 1) * sizeof(char));
      strcpy((yyval.c), val);
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 349:
#line 3268 "Gmsh.y"
    { 
      const char *val = "";
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), val);
      (yyval.c) = (char*)Malloc((strlen(val) + 1) * sizeof(char));
      strcpy((yyval.c), val);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 350:
#line 3279 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 351:
#line 3283 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 352:
#line 3291 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 353:
#line 3299 "Gmsh.y"
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

  case 354:
#line 3313 "Gmsh.y"
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

  case 355:
#line 3327 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 356:
#line 3331 "Gmsh.y"
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
#line 7717 "Gmsh.tab.cpp"
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


#line 3351 "Gmsh.y"


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

