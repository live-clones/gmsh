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
     tPlugin = 317,
     tRotate = 318,
     tTranslate = 319,
     tSymmetry = 320,
     tDilate = 321,
     tExtrude = 322,
     tLoop = 323,
     tRecombine = 324,
     tSmoother = 325,
     tSplit = 326,
     tDelete = 327,
     tCoherence = 328,
     tIntersect = 329,
     tLayers = 330,
     tHole = 331,
     tAlias = 332,
     tAliasWithOptions = 333,
     tText2D = 334,
     tText3D = 335,
     tInterpolationScheme = 336,
     tTime = 337,
     tCombine = 338,
     tBSpline = 339,
     tBezier = 340,
     tNurbs = 341,
     tOrder = 342,
     tKnots = 343,
     tColor = 344,
     tColorTable = 345,
     tFor = 346,
     tIn = 347,
     tEndFor = 348,
     tIf = 349,
     tEndIf = 350,
     tExit = 351,
     tField = 352,
     tReturn = 353,
     tCall = 354,
     tFunction = 355,
     tShow = 356,
     tHide = 357,
     tGetValue = 358,
     tGMSH_MAJOR_VERSION = 359,
     tGMSH_MINOR_VERSION = 360,
     tGMSH_PATCH_VERSION = 361,
     tAFFECTDIVIDE = 362,
     tAFFECTTIMES = 363,
     tAFFECTMINUS = 364,
     tAFFECTPLUS = 365,
     tOR = 366,
     tAND = 367,
     tNOTEQUAL = 368,
     tEQUAL = 369,
     tGREATEROREQUAL = 370,
     tLESSOREQUAL = 371,
     UNARYPREC = 372,
     tMINUSMINUS = 373,
     tPLUSPLUS = 374
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
#define tPlugin 317
#define tRotate 318
#define tTranslate 319
#define tSymmetry 320
#define tDilate 321
#define tExtrude 322
#define tLoop 323
#define tRecombine 324
#define tSmoother 325
#define tSplit 326
#define tDelete 327
#define tCoherence 328
#define tIntersect 329
#define tLayers 330
#define tHole 331
#define tAlias 332
#define tAliasWithOptions 333
#define tText2D 334
#define tText3D 335
#define tInterpolationScheme 336
#define tTime 337
#define tCombine 338
#define tBSpline 339
#define tBezier 340
#define tNurbs 341
#define tOrder 342
#define tKnots 343
#define tColor 344
#define tColorTable 345
#define tFor 346
#define tIn 347
#define tEndFor 348
#define tIf 349
#define tEndIf 350
#define tExit 351
#define tField 352
#define tReturn 353
#define tCall 354
#define tFunction 355
#define tShow 356
#define tHide 357
#define tGetValue 358
#define tGMSH_MAJOR_VERSION 359
#define tGMSH_MINOR_VERSION 360
#define tGMSH_PATCH_VERSION 361
#define tAFFECTDIVIDE 362
#define tAFFECTTIMES 363
#define tAFFECTMINUS 364
#define tAFFECTPLUS 365
#define tOR 366
#define tAND 367
#define tNOTEQUAL 368
#define tEQUAL 369
#define tGREATEROREQUAL 370
#define tLESSOREQUAL 371
#define UNARYPREC 372
#define tMINUSMINUS 373
#define tPLUSPLUS 374




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
#line 422 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 435 "Gmsh.tab.cpp"

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
#define YYLAST   6302

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  140
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  352
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1242

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   374

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   125,     2,   135,     2,   124,     2,     2,
     130,   131,   122,   120,   136,   121,   134,   123,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     116,     2,   117,   111,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   132,     2,   133,   129,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   137,     2,   138,   139,     2,     2,     2,
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
     105,   106,   107,   108,   109,   110,   112,   113,   114,   115,
     118,   119,   126,   127,   128
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
    1295,  1297,  1300,  1306,  1314,  1324,  1327,  1337,  1338,  1342,
    1343,  1345,  1353,  1363,  1372,  1381,  1388,  1393,  1400,  1411,
    1422,  1433,  1444,  1447,  1451,  1453,  1457,  1460,  1463,  1466,
    1470,  1474,  1478,  1482,  1486,  1490,  1494,  1498,  1502,  1506,
    1510,  1514,  1518,  1522,  1528,  1533,  1538,  1543,  1548,  1553,
    1558,  1563,  1568,  1573,  1578,  1585,  1590,  1595,  1600,  1605,
    1610,  1615,  1622,  1629,  1636,  1641,  1646,  1651,  1656,  1661,
    1666,  1671,  1676,  1681,  1686,  1691,  1698,  1703,  1708,  1713,
    1718,  1723,  1728,  1735,  1742,  1749,  1754,  1756,  1758,  1760,
    1762,  1764,  1766,  1768,  1770,  1776,  1781,  1786,  1789,  1795,
    1799,  1806,  1811,  1819,  1826,  1828,  1831,  1834,  1838,  1842,
    1854,  1864,  1872,  1880,  1882,  1886,  1888,  1890,  1893,  1897,
    1902,  1908,  1911,  1915,  1919,  1925,  1930,  1932,  1934,  1938,
    1945,  1947,  1949,  1953,  1957,  1967,  1975,  1977,  1983,  1987,
    1994,  1996,  2000,  2002,  2004,  2008,  2015,  2017,  2019,  2026,
    2031,  2036,  2041
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     141,     0,    -1,   142,    -1,     1,     6,    -1,    -1,   142,
     143,    -1,   146,    -1,   145,    -1,   164,    -1,   167,    -1,
     168,    -1,   171,    -1,   172,    -1,   173,    -1,   176,    -1,
     194,    -1,   195,    -1,   196,    -1,   175,    -1,   174,    -1,
     117,    -1,   117,   117,    -1,    35,   130,     5,   131,     6,
      -1,    35,   130,     5,   131,   144,   208,     6,    -1,    35,
     130,     5,   136,   204,   131,     6,    -1,    35,   130,     5,
     136,   204,   131,   144,   208,     6,    -1,     4,     5,   137,
     147,   138,     6,    -1,    77,     4,   132,   197,   133,     6,
      -1,    78,     4,   132,   197,   133,     6,    -1,    -1,   147,
     150,    -1,   147,   154,    -1,   147,   157,    -1,   147,   159,
      -1,   147,   160,    -1,   197,    -1,   148,   136,   197,    -1,
     197,    -1,   149,   136,   197,    -1,    -1,    -1,     4,   151,
     130,   148,   131,   152,   137,   149,   138,     6,    -1,   208,
      -1,   153,   136,   208,    -1,    -1,    79,   130,   197,   136,
     197,   136,   197,   131,   155,   137,   153,   138,     6,    -1,
     208,    -1,   156,   136,   208,    -1,    -1,    80,   130,   197,
     136,   197,   136,   197,   136,   197,   131,   158,   137,   156,
     138,     6,    -1,    81,   137,   201,   138,   137,   201,   138,
       6,    -1,    81,   137,   201,   138,   137,   201,   138,   137,
     201,   138,   137,   201,   138,     6,    -1,    -1,    82,   161,
     137,   149,   138,     6,    -1,     7,    -1,   110,    -1,   109,
      -1,   108,    -1,   107,    -1,   128,    -1,   127,    -1,     4,
     162,   197,     6,    -1,     4,   132,   197,   133,   162,   197,
       6,    -1,     4,   132,   137,   204,   138,   133,   162,   202,
       6,    -1,     4,   132,   133,     7,   202,     6,    -1,     4,
     132,   133,   110,   202,     6,    -1,     4,   163,     6,    -1,
       4,   132,   197,   133,   163,     6,    -1,     4,     7,   209,
       6,    -1,     4,   134,     4,     7,   209,     6,    -1,     4,
     132,   197,   133,   134,     4,     7,   209,     6,    -1,     4,
     134,     4,   162,   197,     6,    -1,     4,   132,   197,   133,
     134,     4,   162,   197,     6,    -1,     4,   134,     4,   163,
       6,    -1,     4,   132,   197,   133,   134,     4,   163,     6,
      -1,     4,   134,    89,   134,     4,     7,   205,     6,    -1,
       4,   132,   197,   133,   134,    89,   134,     4,     7,   205,
       6,    -1,     4,   134,    90,     7,   206,     6,    -1,     4,
     132,   197,   133,   134,    90,     7,   206,     6,    -1,     4,
      97,     7,   197,     6,    -1,    97,   132,   197,   133,     7,
       4,     6,    -1,    97,   132,   197,   133,   134,     4,     7,
     197,     6,    -1,    97,   132,   197,   133,   134,     4,     7,
     209,     6,    -1,    97,   132,   197,   133,   134,     4,     7,
     137,   204,   138,     6,    -1,    62,   130,     4,   131,   134,
       4,     7,   197,     6,    -1,    62,   130,     4,   131,   134,
       4,     7,   209,     6,    -1,   197,    -1,   209,    -1,    -1,
      92,    47,   137,   197,   138,    -1,    43,   130,   197,   131,
       7,   199,     6,    -1,    60,    43,   130,   165,   131,     7,
     202,     6,    -1,    52,    53,   202,     7,   197,     6,    -1,
      46,   130,   197,   131,     7,   202,     6,    -1,    50,   130,
     197,   131,     7,   202,     6,    -1,    44,   130,   197,   131,
       7,   202,     6,    -1,    44,   130,   197,   131,     7,   202,
      56,   199,     6,    -1,    45,   130,   197,   131,     7,   202,
       6,    -1,    45,   130,   197,   131,     7,   202,    56,   199,
       6,    -1,    54,   130,   197,   131,     7,   137,   197,   136,
     197,   136,     5,   136,     5,   136,     5,   138,     6,    -1,
      84,   130,   197,   131,     7,   202,     6,    -1,    85,   130,
     197,   131,     7,   202,     6,    -1,    86,   130,   197,   131,
       7,   202,    88,   202,    87,   197,     6,    -1,    46,    68,
     130,   197,   131,     7,   202,     6,    -1,    60,    46,   130,
     165,   131,     7,   202,     6,    -1,    56,    49,   130,   197,
     131,     7,   202,     6,    -1,    57,    49,   130,   197,   131,
       7,   202,   166,     6,    -1,    12,    13,     6,    -1,    13,
      49,   197,     6,    -1,    54,    49,   130,   197,   131,     7,
       5,     5,     5,     6,    -1,    47,   130,   197,   131,     7,
     202,     6,    -1,    48,   130,   197,   131,     7,   202,     6,
      -1,    49,    68,   130,   197,   131,     7,   202,     6,    -1,
      60,    49,   130,   165,   131,     7,   202,     6,    -1,    59,
      51,   130,   197,   131,     7,   202,     6,    -1,    51,   130,
     197,   131,     7,   202,     6,    -1,    60,    51,   130,   165,
     131,     7,   202,     6,    -1,    64,   199,   137,   169,   138,
      -1,    63,   137,   199,   136,   199,   136,   197,   138,   137,
     169,   138,    -1,    65,   199,   137,   169,   138,    -1,    66,
     137,   199,   136,   197,   138,   137,   169,   138,    -1,     4,
     137,   169,   138,    -1,    74,    46,   137,   204,   138,    49,
     137,   197,   138,    -1,    71,    46,   130,   197,   131,   137,
     204,   138,     6,    -1,   170,    -1,   168,    -1,    -1,   170,
     167,    -1,   170,    43,   137,   204,   138,     6,    -1,   170,
      46,   137,   204,   138,     6,    -1,   170,    49,   137,   204,
     138,     6,    -1,   170,    51,   137,   204,   138,     6,    -1,
      72,   137,   170,   138,    -1,    72,    97,   132,   197,   133,
       6,    -1,    72,     4,   132,   197,   133,     6,    -1,    72,
       4,     6,    -1,    72,     4,     4,     6,    -1,    89,   205,
     137,   170,   138,    -1,   101,   208,     6,    -1,   102,   208,
       6,    -1,   101,   137,   170,   138,    -1,   102,   137,   170,
     138,    -1,     4,   209,     6,    -1,     4,     4,   132,   197,
     133,   208,     6,    -1,     4,     4,     4,   132,   197,   133,
       6,    -1,     4,   197,     6,    -1,    62,   130,     4,   131,
     134,     4,     6,    -1,    83,     4,     6,    -1,    96,     6,
      -1,    40,     6,    -1,    40,   137,   197,   136,   197,   136,
     197,   136,   197,   136,   197,   136,   197,   138,     6,    -1,
      41,     6,    -1,    91,   130,   197,     8,   197,   131,    -1,
      91,   130,   197,     8,   197,     8,   197,   131,    -1,    91,
       4,    92,   137,   197,     8,   197,   138,    -1,    91,     4,
      92,   137,   197,     8,   197,     8,   197,   138,    -1,    93,
      -1,   100,     4,    -1,    98,    -1,    99,     4,     6,    -1,
      94,   130,   197,   131,    -1,    95,    -1,    67,   199,   137,
     170,   138,    -1,    67,   137,   199,   136,   199,   136,   197,
     138,   137,   170,   138,    -1,    67,   137,   199,   136,   199,
     136,   199,   136,   197,   138,   137,   170,   138,    -1,    -1,
      67,   199,   137,   170,   177,   190,   138,    -1,    -1,    67,
     137,   199,   136,   199,   136,   197,   138,   137,   170,   178,
     190,   138,    -1,    -1,    67,   137,   199,   136,   199,   136,
     199,   136,   197,   138,   137,   170,   179,   190,   138,    -1,
      -1,    67,   137,   170,   180,   190,   138,    -1,    67,    43,
     137,   197,   136,   199,   138,     6,    -1,    67,    46,   137,
     197,   136,   199,   138,     6,    -1,    67,    49,   137,   197,
     136,   199,   138,     6,    -1,    67,    43,   137,   197,   136,
     199,   136,   199,   136,   197,   138,     6,    -1,    67,    46,
     137,   197,   136,   199,   136,   199,   136,   197,   138,     6,
      -1,    67,    49,   137,   197,   136,   199,   136,   199,   136,
     197,   138,     6,    -1,    67,    43,   137,   197,   136,   199,
     136,   199,   136,   199,   136,   197,   138,     6,    -1,    67,
      46,   137,   197,   136,   199,   136,   199,   136,   199,   136,
     197,   138,     6,    -1,    67,    49,   137,   197,   136,   199,
     136,   199,   136,   199,   136,   197,   138,     6,    -1,    -1,
      67,    43,   137,   197,   136,   199,   138,   181,   137,   190,
     138,     6,    -1,    -1,    67,    46,   137,   197,   136,   199,
     138,   182,   137,   190,   138,     6,    -1,    -1,    67,    49,
     137,   197,   136,   199,   138,   183,   137,   190,   138,     6,
      -1,    -1,    67,    43,   137,   197,   136,   199,   136,   199,
     136,   197,   138,   184,   137,   190,   138,     6,    -1,    -1,
      67,    46,   137,   197,   136,   199,   136,   199,   136,   197,
     138,   185,   137,   190,   138,     6,    -1,    -1,    67,    49,
     137,   197,   136,   199,   136,   199,   136,   197,   138,   186,
     137,   190,   138,     6,    -1,    -1,    67,    43,   137,   197,
     136,   199,   136,   199,   136,   199,   136,   197,   138,   187,
     137,   190,   138,     6,    -1,    -1,    67,    46,   137,   197,
     136,   199,   136,   199,   136,   199,   136,   197,   138,   188,
     137,   190,   138,     6,    -1,    -1,    67,    49,   137,   197,
     136,   199,   136,   199,   136,   199,   136,   197,   138,   189,
     137,   190,   138,     6,    -1,   191,    -1,   190,   191,    -1,
      75,   137,   197,   138,     6,    -1,    75,   137,   202,   136,
     202,   138,     6,    -1,    75,   137,   202,   136,   202,   136,
     202,   138,     6,    -1,    69,     6,    -1,    76,   130,   197,
     131,     7,   202,    61,   197,     6,    -1,    -1,    61,     4,
     197,    -1,    -1,     4,    -1,    58,    46,   202,     7,   197,
     192,     6,    -1,    58,    49,   137,   197,   138,     7,   202,
     193,     6,    -1,    55,    49,   137,   197,   138,     7,   202,
       6,    -1,    58,    51,   137,   197,   138,     7,   202,     6,
      -1,    69,    49,   202,     7,   197,     6,    -1,    69,    49,
     202,     6,    -1,    70,    49,   202,     7,   197,     6,    -1,
      43,   137,   204,   138,    92,    49,   137,   197,   138,     6,
      -1,    46,   137,   204,   138,    92,    49,   137,   197,   138,
       6,    -1,    46,   137,   204,   138,    92,    51,   137,   197,
     138,     6,    -1,    49,   137,   204,   138,    92,    51,   137,
     197,   138,     6,    -1,    73,     6,    -1,    73,     4,     6,
      -1,   198,    -1,   130,   197,   131,    -1,   121,   197,    -1,
     120,   197,    -1,   125,   197,    -1,   197,   121,   197,    -1,
     197,   120,   197,    -1,   197,   122,   197,    -1,   197,   123,
     197,    -1,   197,   124,   197,    -1,   197,   129,   197,    -1,
     197,   116,   197,    -1,   197,   117,   197,    -1,   197,   119,
     197,    -1,   197,   118,   197,    -1,   197,   115,   197,    -1,
     197,   114,   197,    -1,   197,   113,   197,    -1,   197,   112,
     197,    -1,   197,   111,   197,     8,   197,    -1,    14,   130,
     197,   131,    -1,    15,   130,   197,   131,    -1,    16,   130,
     197,   131,    -1,    17,   130,   197,   131,    -1,    18,   130,
     197,   131,    -1,    19,   130,   197,   131,    -1,    20,   130,
     197,   131,    -1,    21,   130,   197,   131,    -1,    22,   130,
     197,   131,    -1,    24,   130,   197,   131,    -1,    25,   130,
     197,   136,   197,   131,    -1,    26,   130,   197,   131,    -1,
      27,   130,   197,   131,    -1,    28,   130,   197,   131,    -1,
      29,   130,   197,   131,    -1,    30,   130,   197,   131,    -1,
      31,   130,   197,   131,    -1,    32,   130,   197,   136,   197,
     131,    -1,    33,   130,   197,   136,   197,   131,    -1,    34,
     130,   197,   136,   197,   131,    -1,    23,   130,   197,   131,
      -1,    14,   132,   197,   133,    -1,    15,   132,   197,   133,
      -1,    16,   132,   197,   133,    -1,    17,   132,   197,   133,
      -1,    18,   132,   197,   133,    -1,    19,   132,   197,   133,
      -1,    20,   132,   197,   133,    -1,    21,   132,   197,   133,
      -1,    22,   132,   197,   133,    -1,    24,   132,   197,   133,
      -1,    25,   132,   197,   136,   197,   133,    -1,    26,   132,
     197,   133,    -1,    27,   132,   197,   133,    -1,    28,   132,
     197,   133,    -1,    29,   132,   197,   133,    -1,    30,   132,
     197,   133,    -1,    31,   132,   197,   133,    -1,    32,   132,
     197,   136,   197,   133,    -1,    33,   132,   197,   136,   197,
     133,    -1,    34,   132,   197,   136,   197,   133,    -1,    23,
     132,   197,   133,    -1,     3,    -1,     9,    -1,    10,    -1,
      11,    -1,   104,    -1,   105,    -1,   106,    -1,     4,    -1,
       4,   139,   137,   197,   138,    -1,     4,   132,   197,   133,
      -1,   135,     4,   132,   133,    -1,     4,   163,    -1,     4,
     132,   197,   133,   163,    -1,     4,   134,     4,    -1,     4,
     132,   197,   133,   134,     4,    -1,     4,   134,     4,   163,
      -1,     4,   132,   197,   133,   134,     4,   163,    -1,   103,
     130,     5,   136,   197,   131,    -1,   200,    -1,   121,   199,
      -1,   120,   199,    -1,   199,   121,   199,    -1,   199,   120,
     199,    -1,   137,   197,   136,   197,   136,   197,   136,   197,
     136,   197,   138,    -1,   137,   197,   136,   197,   136,   197,
     136,   197,   138,    -1,   137,   197,   136,   197,   136,   197,
     138,    -1,   130,   197,   136,   197,   136,   197,   131,    -1,
     202,    -1,   201,   136,   202,    -1,   197,    -1,   203,    -1,
     137,   138,    -1,   137,   204,   138,    -1,   121,   137,   204,
     138,    -1,   197,   122,   137,   204,   138,    -1,   121,   203,
      -1,   197,   122,   203,    -1,   197,     8,   197,    -1,   197,
       8,   197,     8,   197,    -1,    43,   137,   197,   138,    -1,
     168,    -1,   176,    -1,     4,   132,   133,    -1,     4,   132,
     137,   204,   138,   133,    -1,   197,    -1,   203,    -1,   204,
     136,   197,    -1,   204,   136,   203,    -1,   137,   197,   136,
     197,   136,   197,   136,   197,   138,    -1,   137,   197,   136,
     197,   136,   197,   138,    -1,     4,    -1,     4,   134,    89,
     134,     4,    -1,   137,   207,   138,    -1,     4,   132,   197,
     133,   134,    90,    -1,   205,    -1,   207,   136,   205,    -1,
     209,    -1,     4,    -1,     4,   134,     4,    -1,     4,   132,
     197,   133,   134,     4,    -1,     5,    -1,    42,    -1,    37,
     130,   208,   136,   208,   131,    -1,    38,   130,   208,   131,
      -1,    39,   130,   208,   131,    -1,    36,   130,   208,   131,
      -1,    36,   130,   208,   136,   204,   131,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   138,   138,   139,   144,   146,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     167,   171,   178,   183,   198,   211,   240,   254,   265,   280,
     285,   286,   287,   288,   289,   293,   295,   300,   302,   308,
     454,   307,   472,   479,   490,   489,   508,   515,   526,   525,
     543,   558,   578,   577,   591,   592,   593,   594,   595,   599,
     600,   607,   629,   656,   696,   706,   714,   722,   734,   743,
     748,   756,   774,   792,   801,   813,   818,   826,   846,   869,
     876,   882,   902,   923,   949,   961,   978,   982,   992,   995,
    1013,  1036,  1052,  1074,  1092,  1110,  1128,  1154,  1172,  1198,
    1218,  1236,  1254,  1280,  1297,  1316,  1334,  1373,  1379,  1385,
    1392,  1417,  1442,  1458,  1478,  1496,  1513,  1534,  1539,  1544,
    1549,  1554,  1574,  1580,  1591,  1592,  1597,  1600,  1604,  1627,
    1650,  1673,  1701,  1710,  1714,  1729,  1750,  1767,  1781,  1787,
    1793,  1802,  1816,  1864,  1882,  1897,  1916,  1928,  1952,  1956,
    1961,  1966,  1978,  1995,  2012,  2031,  2050,  2078,  2086,  2092,
    2099,  2103,  2112,  2120,  2128,  2137,  2136,  2149,  2148,  2161,
    2160,  2173,  2172,  2185,  2192,  2199,  2206,  2213,  2220,  2227,
    2234,  2241,  2249,  2248,  2260,  2259,  2271,  2270,  2282,  2281,
    2293,  2292,  2304,  2303,  2315,  2314,  2326,  2325,  2337,  2336,
    2351,  2354,  2360,  2369,  2389,  2412,  2416,  2440,  2443,  2459,
    2462,  2475,  2504,  2548,  2553,  2595,  2618,  2638,  2664,  2687,
    2710,  2713,  2722,  2726,  2742,  2743,  2744,  2745,  2746,  2747,
    2748,  2749,  2750,  2757,  2758,  2759,  2760,  2761,  2762,  2763,
    2764,  2765,  2766,  2767,  2768,  2769,  2770,  2771,  2772,  2773,
    2774,  2775,  2776,  2777,  2778,  2779,  2780,  2781,  2782,  2783,
    2784,  2785,  2786,  2787,  2788,  2790,  2791,  2792,  2793,  2794,
    2795,  2796,  2797,  2798,  2799,  2800,  2801,  2802,  2803,  2804,
    2805,  2806,  2807,  2808,  2809,  2810,  2819,  2820,  2821,  2822,
    2823,  2824,  2825,  2829,  2842,  2854,  2869,  2879,  2889,  2907,
    2912,  2917,  2927,  2937,  2945,  2949,  2953,  2957,  2961,  2968,
    2972,  2976,  2980,  2987,  2992,  2999,  3004,  3008,  3013,  3017,
    3025,  3036,  3044,  3052,  3058,  3069,  3089,  3099,  3109,  3119,
    3139,  3144,  3148,  3152,  3164,  3168,  3180,  3187,  3197,  3201,
    3216,  3221,  3228,  3232,  3245,  3253,  3264,  3268,  3276,  3284,
    3298,  3312,  3316
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
  "tRuled", "tTransfinite", "tComplex", "tPhysical", "tUsing", "tPlugin",
  "tRotate", "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLoop",
  "tRecombine", "tSmoother", "tSplit", "tDelete", "tCoherence",
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
  "PhysicalId", "RuledSurfaceOptions", "Shape", "Transform",
  "MultipleShape", "ListOfShapes", "Delete", "Colorify", "Visibility",
  "Command", "Loop", "Extrude", "@6", "@7", "@8", "@9", "@10", "@11",
  "@12", "@13", "@14", "@15", "@16", "@17", "@18", "ExtrudeParameters",
  "ExtrudeParameter", "TransfiniteType", "TransfiniteArrangement",
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
     365,    63,   366,   367,   368,   369,    60,    62,   370,   371,
      43,    45,    42,    47,    37,    33,   372,   373,   374,    94,
      40,    41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   140,   141,   141,   142,   142,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     144,   144,   145,   145,   145,   145,   146,   146,   146,   147,
     147,   147,   147,   147,   147,   148,   148,   149,   149,   151,
     152,   150,   153,   153,   155,   154,   156,   156,   158,   157,
     159,   159,   161,   160,   162,   162,   162,   162,   162,   163,
     163,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   165,   165,   166,   166,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   168,   168,   168,
     168,   168,   168,   168,   169,   169,   170,   170,   170,   170,
     170,   170,   171,   171,   171,   171,   171,   172,   173,   173,
     173,   173,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   176,   176,   176,   177,   176,   178,   176,   179,
     176,   180,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   181,   176,   182,   176,   183,   176,   184,   176,
     185,   176,   186,   176,   187,   176,   188,   176,   189,   176,
     190,   190,   191,   191,   191,   191,   191,   192,   192,   193,
     193,   194,   194,   194,   194,   194,   194,   194,   195,   195,
     195,   195,   196,   196,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   199,   199,   199,   199,   199,   200,
     200,   200,   200,   201,   201,   202,   202,   202,   202,   202,
     202,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     204,   204,   204,   204,   205,   205,   205,   205,   206,   206,
     207,   207,   208,   208,   208,   208,   209,   209,   209,   209,
     209,   209,   209
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
       1,     2,     5,     7,     9,     2,     9,     0,     3,     0,
       1,     7,     9,     8,     8,     6,     4,     6,    10,    10,
      10,    10,     2,     3,     1,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     4,     2,     5,     3,
       6,     4,     7,     6,     1,     2,     2,     3,     3,    11,
       9,     7,     7,     1,     3,     1,     1,     2,     3,     4,
       5,     2,     3,     3,     5,     4,     1,     1,     3,     6,
       1,     1,     3,     3,     9,     7,     1,     5,     3,     6,
       1,     3,     1,     1,     3,     6,     1,     1,     6,     4,
       4,     4,     6
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
      14,    15,    16,    17,   286,   293,   346,    54,   287,   288,
     289,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   347,     0,     0,   290,
     291,   292,    58,    57,    56,    55,     0,     0,     0,    60,
      59,     0,     0,     0,     0,   126,     0,     0,     0,   224,
       0,     0,     0,     0,   149,     0,   151,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   304,     0,     0,     0,     0,     0,   126,     0,     0,
       0,     0,     0,     0,   126,     0,   222,     0,     0,     0,
       0,     0,     0,     0,   336,     0,     0,     0,     0,     0,
     148,     0,     0,   157,   343,   346,   126,     0,   342,   126,
       0,     0,     0,     0,     0,   297,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,   227,   226,   228,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
       0,   124,     0,    66,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   107,     0,     0,     0,     0,   293,     0,     0,   326,
     327,   330,   331,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   315,     0,   316,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,   305,     0,     0,     0,
       0,   126,   126,     0,     0,     0,     0,     0,     0,     0,
     171,     0,   126,     0,     0,     0,     0,   135,     0,     0,
       0,   223,     0,     0,     0,   147,     0,     0,     0,     0,
       0,   126,     0,     0,     0,     0,   159,     0,     0,     0,
     138,     0,   139,     0,     0,   299,     0,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,   121,
       0,     0,     0,     0,   127,    61,     0,   242,   241,   240,
     239,   235,   236,   238,   237,   230,   229,   231,   232,   233,
     234,   108,     0,     0,     0,     0,     0,     0,   226,   321,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   317,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,     0,     0,     0,     0,     0,     0,     0,   308,
     307,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   216,     0,     0,     0,   136,     0,     0,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,     0,     0,   344,   140,   141,     0,   295,   301,     0,
      39,     0,     0,     0,    52,     0,    30,    31,    32,    33,
      34,   244,   265,   245,   266,   246,   267,   247,   268,   248,
     269,   249,   270,   250,   271,   251,   272,   252,   273,   264,
     285,   253,   274,     0,     0,   255,   276,   256,   277,   257,
     278,   258,   279,   259,   280,   260,   281,     0,     0,     0,
       0,     0,     0,   351,     0,     0,   349,   350,    79,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
      73,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,    22,    20,     0,     0,     0,     0,   328,     0,     0,
     323,   231,   322,   332,   333,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   318,     0,
       0,     0,     0,     0,     0,     0,   207,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   119,
       0,     0,     0,     0,     0,     0,     0,     0,   200,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,     0,     0,
       0,     0,     0,   298,     0,   294,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,    64,    65,     0,     0,     0,     0,
       0,    67,    69,    71,     0,     0,   340,     0,    77,     0,
       0,     0,     0,   243,    21,     0,     0,     0,     0,     0,
     325,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   319,     0,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,   172,   201,     0,     0,   215,   217,     0,
     134,   133,     0,    27,    28,     0,     0,     0,   337,     0,
       0,     0,   152,     0,     0,     0,   144,   300,   143,     0,
       0,     0,     0,   313,     0,   254,   275,   261,   282,   262,
     283,   263,   284,   352,   348,   303,     0,    54,     0,     0,
       0,     0,    62,     0,     0,     0,   338,     0,     0,     0,
       0,    23,    24,     0,     0,    90,     0,   324,     0,    95,
       0,    97,     0,     0,    93,     0,     0,   110,   111,     0,
       0,    94,   115,   320,     0,     0,     0,     0,    88,     0,
     211,   209,     0,     0,     0,     0,     0,     0,   146,     0,
       0,     0,     0,   126,     0,   182,     0,   184,     0,   186,
     315,     0,     0,     0,     0,   166,     0,     0,   100,   101,
       0,     0,     0,     0,    80,     0,   345,   302,     0,    35,
       0,     0,     0,     0,     0,    37,     0,     0,     0,    74,
       0,     0,    75,     0,   341,   128,   129,   130,   131,     0,
       0,   329,     0,     0,     0,   103,     0,     0,   112,     0,
       0,     0,   213,   105,     0,     0,   208,   210,     0,   214,
     114,    91,   104,   113,   116,     0,     0,     0,   312,     0,
     311,     0,     0,   173,     0,     0,   174,     0,     0,   175,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     335,     0,   154,   153,     0,     0,     0,    40,     0,     0,
       0,   314,     0,     0,     0,    63,    70,    72,     0,    78,
       0,    25,     0,     0,    96,    98,     0,     0,     0,     0,
       0,     0,   106,   212,    84,    85,   126,     0,   120,     0,
       0,     0,     0,     0,     0,   202,     0,     0,   126,     0,
     123,   122,     0,     0,     0,     0,    81,    82,     0,    36,
       0,     0,     0,    38,    53,     0,   339,     0,   218,   219,
     220,   221,   109,     0,     0,     0,     0,   310,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,     0,     0,   334,   155,     0,     0,     0,     0,     0,
      76,     0,     0,     0,   118,     0,   188,     0,     0,   190,
       0,     0,   192,     0,     0,     0,   203,     0,   163,     0,
     126,   102,    83,     0,    44,     0,    50,     0,     0,     0,
      89,   309,   176,     0,     0,   183,   177,     0,     0,   185,
     178,     0,     0,   187,     0,     0,     0,   169,     0,     0,
       0,     0,     0,     0,     0,   194,     0,   196,     0,   198,
     204,   206,   168,   164,     0,    41,     0,    48,     0,     0,
       0,     0,   179,     0,     0,   180,     0,     0,   181,     0,
       0,     0,    42,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,   170,     0,     0,     0,     0,     0,   189,
       0,   191,     0,   193,     0,    43,    45,     0,    46,     0,
      99,     0,     0,     0,     0,     0,    51,   195,   197,   199,
      47,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    59,   653,    60,    61,   397,   948,   954,
     576,   736,  1078,  1201,   577,  1169,  1227,   578,  1203,   579,
     580,   740,   126,   215,    62,   519,   985,   464,   309,   280,
     281,    65,    66,    67,    68,    69,   310,   711,  1139,  1184,
     538,  1004,  1007,  1010,  1153,  1157,  1161,  1193,  1196,  1199,
     707,   708,   804,   988,    71,    72,    73,   327,   129,   345,
     171,   852,   853,   329,   313,   196,   644,   767,   207,   208
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1032
static const yytype_int16 yypact[] =
{
    2804,    40,    33,  2879, -1032, -1032,  1424,    43,   -39,   -71,
      16,   102,   -55,    -8,     0,   -34,     3,    64,   -38,    67,
      80,   115,   -25,    77,   165,   210,   162,   211,   661,   186,
     191,   -72,   -72,   222,   266,   301,   318,   333,    27,    89,
     351,   394,   412,   433,   255,   320,   326,    19,    13, -1032,
     331, -1032,   465,   350, -1032,   497,   510,    15,    24, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032,    23,   385,   593, -1032, -1032,
   -1032,   143,   262,   277,   306,   315,   342,   346,   368,   381,
     396,   415,   427,   504,   508,   555,   567,   568,   583,   597,
     618,   635,   397,   402,   405,   408, -1032,   539,   419, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032,  2355,  2355,  2355, -1032,
   -1032,  2355,  1990,     8,   556,    46,  2355,   572,  1103, -1032,
     579,   580,  2355,   559, -1032,  2355, -1032,  2355,  2289,  2355,
    2355,   466,  2355,  2289,  2355,  2355,   469,  2289,  2355,  2355,
    1566,   480,  2355,   483,   495,   512,  1566,   513,   517,   544,
     547,   561,   573,   576,   698,   -72,   -72,   -72,  2355,  2355,
     -50, -1032,   187,   -72,   577,   591,   595,  2160,   227,  1566,
    1566,   621,    35,   509, -1032,   766, -1032,   617,   632,   641,
     770,  2355,  2355,  2355,   664,  2355,   671,   688,  2355,  2355,
   -1032,  2355,   795, -1032,   636, -1032, -1032,   803, -1032, -1032,
     811,   692,  2355,   816,   697, -1032, -1032,   829,  2355,  2355,
    2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,
    2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,
    2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,
    2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,
     644,   644,   644,   644,  2355,   839,   438,   734,   734,   734,
    5165,    11,  2289,  4429,   273,   736,   872,   759,   771, -1032,
     742,  2942,  1379, -1032, -1032,  2355,  2355,  2355,  2355,  2355,
    2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,  2355,
   -1032, -1032,  1757,   -89,  3675,  5186,   140,   772,  2289, -1032,
   -1032,  2580, -1032,   633,  5207,  5228,  2355,  5249,   639,  5270,
    5291,  2355,   643,  5312,  5333,  1695,  1288,  2599,   888, -1032,
    2355,  5354,  2355,  2355,  2355,   895,  2355,  2355,  2355,  2412,
    2412,  2412,  2412,   779,   -48, -1032, -1032,  3701,  3727,   -72,
     -72,    46,    46,    51,  2355,  2355,  2355,  2160,  2160,  2355,
    2942,   181, -1032,   488,   904,  2355,   906, -1032,  2355,  2355,
     743, -1032,  2289,  2355,  2355, -1032,  5375,  5396,  5417,   824,
    3753, -1032,   777,  2620,  5438,  4452, -1032,  2355,   911,   938,
   -1032,  1051, -1032,  2355,  4475,   218,  2355,    10, -1032,  5459,
    4498,  5480,  4521,  5501,  4544,  5522,  4567,  5543,  4590,  5564,
    4613,  5585,  4636,  5606,  4659,  5627,  4682,  5648,  4705,  5669,
    4728,  3779,  3805,  5690,  4751,  5711,  4774,  5732,  4797,  5753,
    4820,  5774,  4843,  5795,  4866,  3831,  3857,  3883,  3909,  3935,
    3961,   -62,   781,   787,   788,  1788,   789,  2355, -1032,  1566,
    1566,   646,    73,   593,  2355,   917,   920,    21,   793, -1032,
     141,   -30,   -33,   195, -1032, -1032,  2639,   623,   738,   602,
     602,   637,   637,   637,   637,    62,    62,   734,   734,   734,
     734, -1032,    37,  2289,  2355,   921,  2125,  2355,   734, -1032,
    2355,  2289,  2289,   835,   923,   924,  5816,   925,   841,   928,
     929,  5837,   845,   931,   932,  2289, -1032,   647,  1824,  2355,
    5858,   933,  2708,  5879,  5900,  2355,  2977,  3005,  5921,   810,
    6173, -1032,   812,   813,   814,   815,   -72,  2355,  2355, -1032,
   -1032,   817,   818,  2355,  3987,  4013,  4039,  3649,   245,   -72,
    1152, -1032,  2355,  2355,  5942, -1032,  4889,  4912, -1032,   668,
    4935,  4958,   945,   946,   947,   823,  2355,  1330,  2355,  2355,
   -1032,     4,  4981, -1032, -1032, -1032,  5004,   261, -1032,  3033,
   -1032,   830,   831,   822, -1032,   956, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032,  2355,  2355, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032,  2355,  2355,  2355,
    2355,  2355,  2355, -1032,  2289,   644, -1032, -1032, -1032,  2355,
    5027,   957,   958,   832, -1032,    12,  2355,   960,   962,  1914,
   -1032,   963,   837,    19,   966, -1032,  2289,  2289,  2289,  2289,
    2355, -1032,   856,   644,   -52,  4065,   -72, -1032,  2289,  3061,
    2659,   734, -1032,  2580, -1032,   926,  1566,  1566,   967,  1566,
     756,  1566,  1566,   969,   940,  1566,  1566,   677, -1032,  2289,
    2085,   970,   842,   973,   986,   993,  2222,   994,   995,   996,
     997,   998,   999,  1000,  1004,   322,  4091,  4117, -1032, -1032,
    3089,   -72,   -72,   -72,  1003,   873,   881,   188, -1032,   371,
   -1032,   245,  2384,  2441,   876,  1008,  1009,   968,  1013,  1014,
    1566,  1566,  1566,  1022,  4143, -1032,  2678,  1358,  1023,  1024,
     897,  1026,  1025, -1032,  1027, -1032,   905,  2355,  2355,  1566,
     899, -1032,  5963,  5050,  5984,  5073,  6005,  5096,  6026,  5119,
     145,   903,  6047,   336, -1032, -1032,    69,   434,   907,  1030,
    2460, -1032, -1032, -1032,    19,  2355, -1032,   678, -1032,   685,
     694,   695,   703,  6173, -1032,  1032,    58,  2355,     7,   704,
   -1032,  2355,   902,    30,    38,  1566,  1034,   910,   912,  1036,
    1037,  1566,   913,  1042,  1045, -1032,   709, -1032,  1047,  2355,
    1566,  1566,  1566,  1049,  1053,  1566,  1566,  1566,  1566,  1566,
    1566,  1566,   511,  2355,  2355,  2355,   918,   -53,   240,   468,
   -1032,  1566,  2355, -1032, -1032,  2160,   235, -1032, -1032,  2289,
   -1032, -1032,   930, -1032, -1032,  1055,  1059,   978, -1032,  2355,
    2355,  2355, -1032,  1062,  1050,  1066, -1032,   218, -1032,  2355,
    4169,  4195,   712, -1032,  2355, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032,  1566,   593,  2355,  1065,
    1068,    21, -1032,  1067,  5142,    19, -1032,  1069,  1073,  1074,
    1075, -1032, -1032,   644,  4221, -1032,   941,  6173,  2355, -1032,
     -72, -1032,   -72,  1076, -1032,  2355,  2355, -1032, -1032,  1077,
    2355, -1032, -1032, -1032,  1080,  4247,  1081,  1082,  1012,  2355,
   -1032,  1085,  1084,  1086,  1100,  1106,  1108,  1109, -1032,  2412,
    3117,  6068,  2893,    46,   -72,  1110,   -72,  1111,   -72,  1112,
     311,   950,  6089,  3145,   416, -1032,   728,  2355, -1032, -1032,
    1566,  2921,   546,  6110, -1032,  1953, -1032, -1032,   213,  6173,
    2355,  2355,  1566,   982,   739,  6173,  1114,  1115,  2480, -1032,
    1116,  1119, -1032,   988, -1032, -1032, -1032, -1032, -1032,  1120,
    2355, -1032,  3173,    39,    49, -1032,  3201,  3229, -1032,  3257,
    1124,  2355, -1032, -1032,  1093,  1125,  6173, -1032,  1126, -1032,
   -1032, -1032, -1032, -1032, -1032,  2503,  1127,  1015, -1032,  2355,
   -1032,  1011,   491, -1032,  1016,   503, -1032,  1017,   552, -1032,
    1018,  1140,  1566,  1143,  1020,  2355,  1145,  3285,  1072,  2355,
   -1032,  2355, -1032, -1032,  2289,  2522,  1154, -1032,  2355,  4273,
    4299, -1032,  1566,  2355,  1155, -1032, -1032, -1032,    19, -1032,
    1079, -1032,  4325,  1156, -1032, -1032,  1157,  1160,  1161,  1164,
    4351,  1035, -1032, -1032, -1032, -1032,    46,  2949, -1032,  2160,
     245,  2160,   245,  2160,   245, -1032,   740,  1566, -1032,  3313,
   -1032, -1032,  2355,  3341,  3369,   748, -1032, -1032,  1038,  6173,
    2355,  2355,   751,  6173, -1032,  1165, -1032,  2355, -1032, -1032,
   -1032, -1032, -1032,  1168,  2355,  1039,  2355, -1032,  3397,   558,
     335,  3425,   569,   337,  3453,   575,   339,  1566,  1172,  1113,
    1598,  1043,  2542, -1032, -1032,  1173,  2355,  6131,  4377,    26,
   -1032,  4403,  1046,  3481, -1032,  3509,  1175,  2355,  1177,  1178,
    2355,  1179,  1180,  2355,  1181,  1052, -1032,  2355, -1032,   245,
   -1032, -1032, -1032,   752, -1032,  2355, -1032,  1566,  2355,  1183,
   -1032, -1032, -1032,  1054,  3537, -1032, -1032,  1070,  3565, -1032,
   -1032,  1091,  3593, -1032,  1199,  2561,   377,  1727,  1204,  1092,
    6152,   758,  3621,  1094,   245,  1207,   245,  1225,   245,  1228,
   -1032, -1032, -1032, -1032,   245, -1032,   644, -1032,  1102,  1234,
    1236,   391, -1032,  1105,   393, -1032,  1107,   410, -1032,  1117,
     499,   762, -1032,  1118,  1566, -1032,  1121,  1237,   245,  1239,
     245,  1240,   245, -1032,   644,  1241,   644,   765,  1242, -1032,
     515, -1032,   518, -1032,   533, -1032, -1032,   769, -1032,  1244,
   -1032,  1245,  1246,  1247,   644,  1250, -1032, -1032, -1032, -1032,
   -1032, -1032
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1032, -1032, -1032, -1032,   482, -1032, -1032, -1032, -1032,   144,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032,  -253,    -4, -1032,    78, -1032,  1258,     6,  -347,
    -169, -1032, -1032, -1032, -1032, -1032,  1259, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
    -605,  -701, -1032, -1032, -1032, -1032, -1032,    -3, -1032,   343,
   -1032, -1031,   472,   225,   -66,  -617,   395, -1032,   -58,     1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     210,  1082,   127,   128,   531,   532,   824,   130,   360,    64,
     132,   728,   274,   885,   570,   370,   757,   197,   449,   204,
     205,   454,   134,   194,   151,   642,   766,   211,   204,   205,
     146,   182,  1146,     5,   141,   146,   889,   389,   141,   366,
     391,   367,   482,   651,   891,  1044,     4,   483,   166,   167,
     278,   102,   103,   104,   105,  1045,   131,   106,   168,   133,
     102,   103,   104,   105,   882,   169,   106,   349,   350,   623,
     349,   350,   349,   350,   624,   137,   634,   318,   217,   776,
     634,   322,   138,   924,   492,   925,   890,   351,   526,   571,
     572,   573,   574,   185,   892,   186,   142,   275,   276,   147,
     142,   758,   759,   143,   648,   152,   826,   647,   136,    30,
      31,    32,    33,   267,   268,   269,  1171,    37,   270,   273,
      40,   450,   139,   282,   183,   824,   153,   349,   350,   302,
     140,   279,   304,   144,   305,   311,   314,   315,   729,   317,
     311,   319,   320,   198,   311,   323,   324,   873,   575,   331,
     119,   120,   206,   135,   652,   212,   195,   213,   643,   349,
     350,   209,   214,  1147,   184,   347,   348,   368,   150,   349,
     350,   349,   350,  1217,   348,   652,   112,   113,   114,   115,
     112,   113,   114,   115,   296,   297,   298,   533,   376,   377,
     378,   299,   380,   540,   145,   383,   384,   148,   385,   636,
     119,   120,   441,   442,   443,   444,   451,   635,   156,   394,
     149,   157,   557,   158,   154,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   704,   964,   155,
     507,   445,   159,   705,   706,   204,   205,   119,   120,   311,
     455,   137,   486,   218,   213,   219,   863,   125,   646,   214,
     453,   492,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   102,   103,   104,
     105,   349,   350,   106,   704,   488,   549,   349,   350,   174,
     705,   706,   175,   496,   704,   176,   164,   539,   501,   490,
     705,   706,   488,   311,   352,   149,   823,   510,   165,   512,
     513,   514,   649,   516,   517,   518,   520,   520,   520,   520,
     521,   521,   521,   521,  1027,   119,   120,   349,   350,  1028,
     179,   534,   535,   536,   267,   268,   537,   279,   279,   173,
     349,   350,   544,   312,   362,   546,   547,   180,   312,   311,
     550,   551,   312,   935,   170,   172,   926,   178,   927,   181,
     112,   113,   114,   115,   562,   191,   166,   167,   119,   120,
     566,   568,   220,   569,   221,   732,   168,   187,   188,   824,
     119,   120,   824,   177,   704,   824,   704,   222,   704,   223,
     705,   706,   705,   706,   705,   706,   189,   654,   522,   523,
     524,  1085,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   508,   297,   298,   224,   190,   225,   677,
     299,   867,   349,   350,   630,   226,   704,   227,   637,  1011,
     192,   639,   705,   706,   638,  1100,   193,  1103,   813,  1106,
     704,   199,   704,   119,   120,   824,   705,   706,   705,   706,
     732,   200,   228,  1128,   229,  1131,   230,  1134,   231,   704,
     311,   655,   201,   630,   659,   705,   706,   660,   661,   663,
     824,   349,   350,   824,   541,   542,   824,   312,   232,   824,
     233,   202,   311,   866,   868,   661,   680,   825,   344,   734,
     346,   234,   686,   235,   203,  1182,   353,   918,   919,   824,
     361,   824,   216,   824,   696,   697,   236,   260,   237,  1207,
     700,  1209,   261,   489,  1166,   262,   349,   350,   263,   712,
     713,   112,   113,   114,   115,   238,   264,   239,  1211,   265,
     489,   312,  1015,   724,  1021,   726,   727,   240,   750,   241,
     277,   119,   120,   733,   303,   119,   120,   751,   704,  1191,
     447,  1194,   213,  1197,   705,   706,  1001,   214,   283,  1200,
     769,   770,   771,   772,   704,   300,   301,   704,   349,   350,
     705,   706,   779,   705,   706,   775,   316,   312,   205,   321,
     742,   743,   704,  1220,   928,  1222,   929,  1224,   705,   706,
     330,   349,   350,   796,   744,   745,   746,   747,   748,   749,
     332,   311,   328,   349,   350,   333,   752,  1059,   335,   102,
     103,   104,   105,   760,   242,   106,   243,  1213,   244,  1061,
     245,   369,   334,   311,   311,   311,   311,   773,   204,   205,
     336,   363,   364,  1231,   337,   311,  1232,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,  1233,   349,   350,   338,   299,   311,   339,   349,   350,
     102,   103,   104,   105,  1022,   246,   106,   247,  1063,   349,
     350,   340,   529,   530,  1127,   349,   350,   248,   250,   249,
     251,   346,   343,   341,   160,  1130,   342,   161,   312,  1095,
     162,  1133,   163,   252,   354,   253,   662,   664,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   254,   355,   255,
     312,   299,   356,   662,   850,   851,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   256,   733,
     257,   365,   299,   869,   372,     7,     8,   294,   295,   296,
     297,   298,   874,   936,   373,   258,   299,   259,   387,   492,
     388,   493,   371,   374,   884,   492,   375,   498,   887,   492,
     382,   502,   492,   492,   633,   678,   460,    13,    14,   461,
      16,    17,   462,    19,   463,    21,   905,    22,   379,    24,
      25,   386,    27,    28,   492,   787,   717,   788,   381,   390,
     920,   921,   922,   492,   875,   795,   876,   392,   930,   932,
     395,   492,   933,   877,   393,   969,   311,    44,    45,    46,
     492,   492,   878,   879,   396,   398,   941,   942,   943,   492,
     492,   880,   886,   947,   446,   492,   949,   903,   952,   312,
     953,   955,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   492,   958,  1016,   299,   957,   695,
     456,   312,   312,   312,   312,  1033,  1107,  1034,  1108,   457,
     459,   548,   709,   312,   492,   972,  1115,   952,  1033,  1119,
    1168,   458,   976,   977,   952,   509,  1188,   979,  1214,  1110,
    1215,   952,   515,  1229,   312,  1234,   986,  1235,   125,   487,
     525,   543,   545,   555,   558,   563,   995,   625,   626,   627,
     996,   631,   632,   640,   641,   629,   645,   665,   656,   279,
     666,   667,   669,   670,  1017,   671,   672,   674,   675,   676,
     682,   690,  1025,   691,   692,   693,  1026,  1029,  1030,   694,
       7,     8,   720,   721,   722,   698,   699,   723,  1075,   739,
     737,   738,   741,   754,   755,   756,   761,  1042,   762,   765,
     764,  1167,   768,   774,   785,   782,   791,   798,  1050,   799,
     800,   460,    13,    14,   461,    16,    17,   462,    19,   463,
      21,   792,    22,   801,    24,    25,  1057,    27,    28,   778,
     802,   805,   806,   807,   808,   809,   810,   811,   812,   820,
     821,   822,  1069,   829,   830,   831,  1073,   832,  1074,   833,
     834,   311,    44,    45,    46,  1079,   838,   843,   844,   847,
    1083,   845,   846,   848,   864,   849,   854,   871,   881,   888,
     894,   870,   897,   898,   817,   818,   819,   895,   901,   896,
     900,   902,   904,   909,   312,   923,  1098,   945,  1101,   910,
    1104,   938,   279,     7,     8,   939,   940,   937,   944,  1112,
     946,   959,   960,   962,   971,   965,   564,  1117,  1118,   966,
     967,   968,   975,   978,  1121,   980,  1012,   982,   983,   987,
     989,  1123,   990,  1125,   460,    13,    14,   461,    16,    17,
     462,    19,   463,    21,   984,    22,   991,    24,    25,   284,
      27,    28,   992,   955,   993,   994,  1003,  1006,  1009,  1032,
    1035,  1036,  1040,  1038,  1154,  1039,  1041,  1158,  1202,  1049,
    1162,  1052,  1053,  1055,  1165,    44,    45,    46,   783,   784,
    1051,   786,  1170,   789,   790,  1172,  1065,   793,   794,  1058,
    1067,  1070,  1056,  1060,  1062,  1064,  1225,  1068,  1228,  1072,
    1077,  1084,  1088,  1089,     7,     8,  1090,  1091,   934,  1086,
    1092,  1120,  1094,  1122,  1137,  1116,  1240,  1124,  1136,  1142,
    1140,  1152,  1149,  1155,  1156,  1159,  1160,  1163,  1173,   565,
    1164,  1174,   835,   836,   837,   460,    13,    14,   461,    16,
      17,   462,    19,   463,    21,  1180,    22,  1176,    24,    25,
    1185,    27,    28,  1192,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,  1178,  1186,
    1190,  1195,   299,   973,  1198,   974,    44,    45,    46,  1204,
    1205,  1206,  1208,  1219,  1210,  1221,  1223,  1226,  1230,   312,
    1236,  1237,  1238,  1239,  1212,  1216,  1241,   893,   883,  1218,
    1143,    63,    70,   899,     0,     0,   961,  1002,     0,  1005,
       0,  1008,   906,   907,   908,     0,     0,   911,   912,   913,
     914,   915,   916,   917,     0,     0,     0,     0,     0,     0,
     710,    74,   306,   931,     0,     0,     0,    78,    79,    80,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,   307,     0,     0,     0,     0,     0,     0,   956,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,    30,    31,    32,    33,    34,     0,     0,     0,    37,
       0,     0,    40,     0,     0,     0,   841,     0,     0,     0,
       0,     0,     0,   460,    13,    14,   461,    16,    17,   462,
      19,   463,    21,     0,    22,   465,    24,    25,     0,    27,
      28,   108,   109,   110,   111,     0,     0,     0,     0,     0,
       0,     0,  1099,     0,  1102,     0,  1105,     0,   116,   308,
       0,     0,  1018,   118,    44,    45,    46,     0,   121,     0,
       0,     0,     0,   124,  1031,     0,   506,    74,    75,    76,
       0,    77,     0,    78,    79,    80,     0,     0,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,     0,
     102,   103,   104,   105,     0,     0,   106,     0,   725,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,  1066,     0,     0,   299,     0,   842,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,  1109,
       0,     0,     0,     0,   116,   117,     0,     0,     0,   118,
       0,   119,   120,     0,   121,     0,   122,     0,   123,   124,
       0,   125,     0,     0,     0,     0,     0,     0,     0,    74,
     306,     0,     0,     0,     0,    78,    79,    80,     0,  1135,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,   307,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      31,    32,    33,    34,     0,     0,     0,    37,     0,     0,
      40,   460,    13,    14,   461,    16,    17,   462,    19,   463,
      21,     0,    22,     0,    24,    25,     0,    27,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     109,   110,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,    45,    46,     0,   116,   325,     0,     0,
       0,   118,     0,     0,     0,     0,   121,     0,    74,   306,
       0,   124,     0,   326,    78,    79,    80,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
       0,     0,     0,     0,     0,     0,  1138,     0,   307,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    31,
      32,    33,    34,   481,     0,     0,    37,     0,     0,    40,
     460,    13,    14,   461,    16,    17,   462,    19,   463,    21,
       0,    22,     0,    24,    25,     0,    27,    28,     0,     0,
       0,     0,     0,     0,   628,     0,     0,     0,   108,   109,
     110,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,    45,    46,     0,   116,   308,     0,     0,     0,
     118,     0,     0,     0,     0,   121,     0,    74,   306,     0,
     124,     0,   505,    78,    79,    80,     0,     0,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,     0,
       0,     0,     0,     0,     0,  1183,     0,   307,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,    30,    31,    32,
      33,    34,     0,     0,     0,    37,     0,     0,    40,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
     763,     0,     0,     0,     0,     0,     0,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,   308,     0,     0,     0,   118,
       0,     0,     0,     0,   121,     0,    74,   266,   205,   124,
       0,   679,    78,    79,    80,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,     0,   102,
     103,   104,   105,    74,   266,   106,     0,     0,     0,    78,
      79,    80,     0,     0,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,   109,   110,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,   117,     0,     0,     0,   118,     0,
       0,     0,     0,   121,     0,     0,     0,     0,   124,     0,
    1024,   797,     0,   108,   109,   110,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,   117,     0,     0,     0,   118,     0,     0,     0,     0,
     121,     0,     0,   271,     0,   124,     0,   272,    74,   266,
       0,     0,     0,     0,    78,    79,    80,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
       0,     0,     0,    74,   266,     0,     0,     0,     0,    78,
      79,    80,     0,     0,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,     0,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,   109,
     110,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   116,   117,     0,     0,     0,
     118,     0,     0,     0,     0,   121,     0,     0,   657,     0,
     124,     0,   658,   108,   109,   110,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     357,   358,     0,   803,     0,   118,     0,     0,     0,     0,
     359,     0,    74,   306,     0,   124,     0,   169,    78,    79,
      80,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,   307,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,    30,    31,    32,    33,    34,     0,    74,   266,
      37,     0,     0,    40,    78,    79,    80,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     827,     0,   108,   109,   110,   111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
     308,     0,     0,     0,   118,    74,   266,   205,     0,   121,
       0,    78,    79,    80,   124,     0,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   828,   102,   103,
     104,   105,     0,     0,   106,     0,     0,     0,   108,   109,
     110,   111,     0,     0,     0,     0,   872,     0,     0,     0,
       0,     0,     0,     0,     0,   116,   117,     0,     0,     0,
     118,     0,     0,     0,     0,   121,  1037,     0,     0,     0,
     124,     0,     0,     0,     0,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,  1054,
       0,     0,     0,   299,     0,   108,   109,   110,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1076,     0,
       0,     0,   116,   117,     0,     0,     0,   118,     0,     0,
       0,     0,   121,     0,     0,     0,     0,   124,  1141,     0,
       0,     0,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,  1181,     0,     0,
     299,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,   490,   299,
       0,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,   490,     0,   299,
       0,     0,     0,     0,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   559,     0,
       0,     0,   299,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   650,     0,     0,
       0,   299,     0,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   781,     0,     0,
       0,   299,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   840,     0,     0,     0,
     299,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   491,   297,   298,     0,     0,     0,     0,   299,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   508,   297,   298,     0,     0,     0,     0,   299,     0,
       0,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,    -4,     1,     0,   299,    -4,     0,
       0,     0,     0,     0,     0,     0,    -4,    -4,     0,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,    -4,
       0,     0,     0,     0,    -4,    -4,   683,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,    -4,    -4,     6,     0,     0,     0,    -4,    -4,    -4,
      -4,     7,     8,    -4,     0,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,
       0,     0,     0,     0,     9,     0,     0,     0,     0,    10,
      11,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,     7,     8,    41,    42,     0,     0,
       0,     0,    43,    44,    45,    46,     0,     0,    47,     0,
      48,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,     0,     0,     0,   460,    13,    14,   461,    16,
      17,   462,    19,   463,    21,     0,    22,     0,    24,    25,
       0,    27,    28,     0,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,    44,    45,    46,   999,
       0,  1000,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,  1019,     0,  1020,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,  1096,     0,  1097,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,     0,     0,   687,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,     0,     0,   688,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,     0,     0,     0,     0,
       0,   735,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,     0,     0,   780,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,     0,     0,   816,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,     0,     0,   997,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,     0,     0,  1014,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,     0,     0,     0,     0,
       0,  1043,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,     0,     0,  1046,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,     0,     0,  1047,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,     0,     0,  1048,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,     0,     0,  1071,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,     0,     0,     0,     0,
       0,  1111,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,     0,     0,  1113,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,     0,     0,  1114,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,     0,     0,  1126,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,     0,     0,  1129,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,     0,     0,     0,     0,
       0,  1132,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,     0,     0,  1150,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,     0,     0,  1151,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,     0,     0,  1175,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,     0,     0,  1177,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,     0,     0,     0,     0,
       0,  1179,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,     0,     0,  1189,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
     448,     0,     0,     0,     0,   527,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,   484,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,   527,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,   528,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,     0,     0,     0,   556,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,   603,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,   604,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,   617,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,   618,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,     0,     0,     0,   619,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,   620,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,   621,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,   622,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,   701,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,     0,     0,     0,   702,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,   703,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,   777,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,   814,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,   815,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,     0,     0,     0,   839,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,   950,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,   951,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,   970,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,   981,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,     0,     0,     0,  1080,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,  1081,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,  1087,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,  1093,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,  1145,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,     0,     0,     0,  1148,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,   452,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,   561,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,   567,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,   582,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,   584,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,   586,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
     588,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,   590,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,   592,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,   594,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,   596,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,   598,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,   600,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,   602,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,   606,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,   608,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
     610,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,   612,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,   614,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,   616,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,   715,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,   716,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,     0,     0,   718,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,     0,
       0,   719,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,     0,     0,   730,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,     0,     0,   731,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,     0,     0,
     753,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,     0,     0,   856,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,     0,     0,   858,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,     0,     0,   860,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
       0,     0,   862,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,     0,     0,   963,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,   448,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,   485,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,   494,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,   495,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
     497,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,   499,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,   500,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,   503,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,   504,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,   511,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,   552,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,   553,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,   554,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,   560,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
     581,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,   583,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,   585,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,   587,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,   589,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,   591,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,   593,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,   595,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,   597,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,   599,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
     601,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,   605,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,   607,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,   609,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,   611,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,   613,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,   615,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,   668,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,   673,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,   681,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
     684,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,   685,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,   689,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,   714,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299,     0,   855,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   299,     0,   857,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   299,     0,   859,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     0,     0,     0,     0,   299,     0,   861,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,     0,     0,     0,   299,     0,   865,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   299,     0,   998,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   299,     0,
    1013,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   299,
       0,  1023,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     299,     0,  1144,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   299,     0,  1187,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   299
};

static const yytype_int16 yycheck[] =
{
      58,  1032,     6,     6,   351,   352,   707,     6,   177,     3,
      49,     7,     4,     6,     4,   184,     4,     4,     7,     4,
       5,   274,     6,     4,    49,     4,   643,     4,     4,     5,
      68,     4,     6,     0,    68,    68,     6,   206,    68,     4,
     209,     6,   131,     6,     6,     6,     6,   136,   120,   121,
       4,    36,    37,    38,    39,     6,    13,    42,   130,   130,
      36,    37,    38,    39,     6,   137,    42,   120,   121,   131,
     120,   121,   120,   121,   136,   130,     7,   143,    77,   131,
       7,   147,   137,   136,   136,   138,    56,   137,   136,    79,
      80,    81,    82,     4,    56,     6,   130,    89,    90,   137,
     130,    89,    90,   137,   137,   130,   711,   137,     6,    63,
      64,    65,    66,   116,   117,   118,  1147,    71,   121,   122,
      74,   110,   130,   126,    97,   826,    49,   120,   121,   132,
     130,   125,   135,   130,   137,   138,   139,   140,   134,   142,
     143,   144,   145,   130,   147,   148,   149,   764,   138,   152,
     127,   128,   137,   137,   117,   132,   137,   134,   137,   120,
     121,   137,   139,   137,   137,   168,   169,   132,    53,   120,
     121,   120,   121,  1204,   177,   117,   107,   108,   109,   110,
     107,   108,   109,   110,   122,   123,   124,   136,   191,   192,
     193,   129,   195,   362,   130,   198,   199,   130,   201,   452,
     127,   128,   260,   261,   262,   263,   272,   134,    46,   212,
     130,    49,   381,    51,    49,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    69,   875,    49,
     326,   264,    51,    75,    76,     4,     5,   127,   128,   272,
     274,   130,   132,   130,   134,   132,   131,   137,   137,   139,
       7,   136,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,    36,    37,    38,
      39,   120,   121,    42,    69,   308,   372,   120,   121,    43,
      75,    76,    46,   316,    69,    49,   130,   136,   321,     8,
      75,    76,   325,   326,   137,   130,   138,   330,   137,   332,
     333,   334,   137,   336,   337,   338,   339,   340,   341,   342,
     339,   340,   341,   342,   131,   127,   128,   120,   121,   136,
      49,   354,   355,   356,   357,   358,   359,   351,   352,   137,
     120,   121,   365,   138,   137,   368,   369,    49,   143,   372,
     373,   374,   147,   138,    31,    32,   136,    34,   138,    46,
     107,   108,   109,   110,   387,   130,   120,   121,   127,   128,
     393,   395,   130,   396,   132,   134,   130,    46,     4,  1100,
     127,   128,  1103,   137,    69,  1106,    69,   130,    69,   132,
      75,    76,    75,    76,    75,    76,     4,   483,   340,   341,
     342,  1038,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   130,     4,   132,   505,
     129,     7,   120,   121,   447,   130,    69,   132,   452,   138,
     130,   454,    75,    76,   453,  1060,   130,  1062,   136,  1064,
      69,   130,    69,   127,   128,  1166,    75,    76,    75,    76,
     134,     6,   130,   138,   132,   138,   130,   138,   132,    69,
     483,   484,   132,   486,   487,    75,    76,   490,   491,   492,
    1191,   120,   121,  1194,     6,     7,  1197,   272,   130,  1200,
     132,     4,   505,   756,   757,   508,   509,   136,   165,   567,
     167,   130,   515,   132,     4,   138,   173,     6,     7,  1220,
     177,  1222,   137,  1224,   527,   528,   130,   130,   132,   138,
     533,   138,   130,   308,  1139,   130,   120,   121,   130,   542,
     543,   107,   108,   109,   110,   130,     7,   132,   138,   130,
     325,   326,   136,   556,     8,   558,   559,   130,   624,   132,
       4,   127,   128,   567,     5,   127,   128,   625,    69,  1174,
     132,  1176,   134,  1178,    75,    76,   923,   139,     6,  1184,
     646,   647,   648,   649,    69,     6,     6,    69,   120,   121,
      75,    76,   658,    75,    76,   653,   130,   372,     5,   130,
     603,   604,    69,  1208,   136,  1210,   138,  1212,    75,    76,
     130,   120,   121,   679,   617,   618,   619,   620,   621,   622,
     137,   624,   150,   120,   121,   130,   629,   136,   156,    36,
      37,    38,    39,   636,   130,    42,   132,   138,   130,   136,
     132,   132,   130,   646,   647,   648,   649,   650,     4,     5,
     137,   179,   180,   138,   137,   658,   138,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   138,   120,   121,   130,   129,   679,   130,   120,   121,
      36,    37,    38,    39,   138,   130,    42,   132,   136,   120,
     121,   130,   349,   350,   136,   120,   121,   130,   130,   132,
     132,   358,     4,   130,    43,   136,   130,    46,   483,  1056,
      49,   136,    51,   130,   137,   132,   491,   492,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   130,   137,   132,
     505,   129,   137,   508,   737,   738,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   130,   753,
     132,   130,   129,   757,   137,    12,    13,   120,   121,   122,
     123,   124,   765,   829,   132,   130,   129,   132,   132,   136,
     134,   138,     6,   132,   777,   136,     6,   138,   781,   136,
      92,   138,   136,   136,   138,   138,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,   799,    54,   134,    56,
      57,     6,    59,    60,   136,    49,   138,    51,   137,     6,
     813,   814,   815,   136,   136,   138,   138,     6,   821,   822,
       4,   136,   825,   138,   132,   883,   829,    84,    85,    86,
     136,   136,   138,   138,   137,     6,   839,   840,   841,   136,
     136,   138,   138,   847,     5,   136,   849,   138,   136,   624,
     138,   854,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   129,   136,   868,   138,   129,   867,   526,
     134,   646,   647,   648,   649,   136,   136,   138,   138,     7,
     138,   138,   539,   658,   136,   888,   138,   136,   136,   138,
     138,   132,   895,   896,   136,     7,   138,   900,   136,  1068,
     138,   136,     7,   138,   679,   136,   909,   138,   137,   137,
     131,     7,     6,    89,   137,     4,   919,   136,   131,   131,
     919,   449,   450,     6,     4,   136,   133,    92,     7,   923,
       7,     7,     7,    92,   937,     7,     7,    92,     7,     7,
       7,   131,   945,   131,   131,   131,   945,   950,   951,   134,
      12,    13,     7,     7,     7,   138,   138,   134,  1024,   137,
     130,   130,     6,     6,     6,   133,     6,   970,     6,   132,
       7,  1140,     6,   117,     7,    49,     7,     7,   981,   137,
       7,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    51,    54,     7,    56,    57,   999,    59,    60,   656,
       7,     7,     7,     7,     7,     7,     7,     7,     4,     6,
     137,   130,  1015,   137,     6,     6,  1019,    49,  1021,     6,
       6,  1024,    84,    85,    86,  1028,     4,     4,     4,     4,
    1033,   134,     6,     6,   131,   130,   137,     7,     6,   137,
       6,   134,     6,     6,   701,   702,   703,   137,     6,   137,
     137,     6,     5,     4,   829,   137,  1059,     7,  1061,     6,
    1063,     6,  1056,    12,    13,     6,    88,   137,     6,  1072,
       4,     6,     4,     6,   133,     6,   138,  1080,  1081,     6,
       6,     6,     6,     6,  1087,     5,   136,     6,     6,     4,
       6,  1094,     6,  1096,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    92,    54,     6,    56,    57,     6,
      59,    60,     6,  1116,     6,     6,     6,     6,     6,   137,
       6,     6,   134,     7,  1127,     6,     6,  1130,  1186,     5,
    1133,     6,     6,     6,  1137,    84,    85,    86,   666,   667,
      47,   669,  1145,   671,   672,  1148,     6,   675,   676,   138,
       7,     6,   137,   137,   137,   137,  1214,   137,  1216,    87,
       6,     6,     6,     6,    12,    13,     6,     6,   825,    90,
       6,     6,   137,     5,    61,   137,  1234,   138,     6,     6,
     137,     6,   136,     6,     6,     6,     6,     6,     5,   138,
     138,   137,   720,   721,   722,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     6,    54,   137,    56,    57,
       6,    59,    60,     6,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   137,   137,
     136,     6,   129,   890,     6,   892,    84,    85,    86,   137,
       6,     5,   137,     6,   137,     6,     6,     6,     6,  1024,
       6,     6,     6,     6,   137,   137,     6,   785,   776,   138,
    1116,     3,     3,   791,    -1,    -1,   871,   924,    -1,   926,
      -1,   928,   800,   801,   802,    -1,    -1,   805,   806,   807,
     808,   809,   810,   811,    -1,    -1,    -1,    -1,    -1,    -1,
     138,     3,     4,   821,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,   866,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,     6,    56,    57,    -1,    59,
      60,   103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1059,    -1,  1061,    -1,  1063,    -1,   120,   121,
      -1,    -1,   940,   125,    84,    85,    86,    -1,   130,    -1,
      -1,    -1,    -1,   135,   952,    -1,   138,     3,     4,     5,
      -1,     7,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    42,    -1,   138,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,  1012,    -1,    -1,   129,    -1,   131,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,  1067,
      -1,    -1,    -1,    -1,   120,   121,    -1,    -1,    -1,   125,
      -1,   127,   128,    -1,   130,    -1,   132,    -1,   134,   135,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,  1107,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    71,    -1,    -1,
      74,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    -1,    56,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    86,    -1,   120,   121,    -1,    -1,
      -1,   125,    -1,    -1,    -1,    -1,   130,    -1,     3,     4,
      -1,   135,    -1,   137,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,    43,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,     6,    -1,    -1,    71,    -1,    -1,    74,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    -1,    56,    57,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,   103,   104,
     105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    -1,   120,   121,    -1,    -1,    -1,
     125,    -1,    -1,    -1,    -1,   130,    -1,     3,     4,    -1,
     135,    -1,   137,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,    43,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    -1,    -1,    74,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   120,   121,    -1,    -1,    -1,   125,
      -1,    -1,    -1,    -1,   130,    -1,     3,     4,     5,   135,
      -1,   137,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    38,    39,     3,     4,    42,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   120,   121,    -1,    -1,    -1,   125,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,   135,    -1,
     137,     6,    -1,   103,   104,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,   121,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,
     130,    -1,    -1,   133,    -1,   135,    -1,   137,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,   121,    -1,    -1,    -1,
     125,    -1,    -1,    -1,    -1,   130,    -1,    -1,   133,    -1,
     135,    -1,   137,   103,   104,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,   121,    -1,    61,    -1,   125,    -1,    -1,    -1,    -1,
     130,    -1,     3,     4,    -1,   135,    -1,   137,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    63,    64,    65,    66,    67,    -1,     3,     4,
      71,    -1,    -1,    74,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       6,    -1,   103,   104,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
     121,    -1,    -1,    -1,   125,     3,     4,     5,    -1,   130,
      -1,     9,    10,    11,   135,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     6,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,    -1,   103,   104,
     105,   106,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,   121,    -1,    -1,    -1,
     125,    -1,    -1,    -1,    -1,   130,     6,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     6,
      -1,    -1,    -1,   129,    -1,   103,   104,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,   120,   121,    -1,    -1,    -1,   125,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,   135,     6,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,     6,    -1,    -1,
     129,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,     8,   129,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,     8,    -1,   129,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     8,    -1,
      -1,    -1,   129,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     8,    -1,    -1,
      -1,   129,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     8,    -1,    -1,
      -1,   129,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     8,    -1,    -1,    -1,
     129,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,     0,     1,    -1,   129,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,    35,
      -1,    -1,    -1,    -1,    40,    41,   138,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    -1,
      -1,    77,    78,     4,    -1,    -1,    -1,    83,    84,    85,
      86,    12,    13,    89,    -1,    91,    -1,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    12,    13,    77,    78,    -1,    -1,
      -1,    -1,    83,    84,    85,    86,    -1,    -1,    89,    -1,
      91,    -1,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    -1,    56,    57,
      -1,    59,    60,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    84,    85,    86,   136,
      -1,   138,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
     131,    -1,    -1,    -1,    -1,   136,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,   136,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,   136,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,   136,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,   136,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,   136,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,   136,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,   133,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,   133,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,   133,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,   133,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,   133,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,   133,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
     133,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,   133,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,   133,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,   133,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,   133,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,   133,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,   133,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,   133,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,   133,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,   133,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
     133,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,   133,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,   133,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,   133,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,   133,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,   133,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,   133,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,   133,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,   133,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,   133,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
     133,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,   133,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,   133,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,   133,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,   133,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,   133,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,   131,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,   131,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,   131,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,   131,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
     131,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,   131,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,   131,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,   131,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,   131,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,   131,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,   131,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,   131,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,   131,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,   131,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
     131,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,   131,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,   131,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,   131,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,   131,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,   131,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,   131,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,   131,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,   131,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,   131,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
     131,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,   131,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,   131,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,   131,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,   131,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,   131,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,   131,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,   131,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,   131,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,   131,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
     131,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,   131,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,   131,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,   131,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,   131,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,   131,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,   131,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,   131,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,   131,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,   131,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
     131,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,   131,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,   131,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,   131,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   141,   142,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    55,    56,    57,    58,    59,    60,    62,
      63,    64,    65,    66,    67,    69,    70,    71,    72,    73,
      74,    77,    78,    83,    84,    85,    86,    89,    91,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   143,
     145,   146,   164,   167,   168,   171,   172,   173,   174,   175,
     176,   194,   195,   196,     3,     4,     5,     7,     9,    10,
      11,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    36,    37,    38,    39,    42,    97,   103,   104,
     105,   106,   107,   108,   109,   110,   120,   121,   125,   127,
     128,   130,   132,   134,   135,   137,   162,   163,   197,   198,
     209,    13,    49,   130,     6,   137,     6,   130,   137,   130,
     130,    68,   130,   137,   130,   130,    68,   137,   130,   130,
      53,    49,   130,    49,    49,    49,    46,    49,    51,    51,
      43,    46,    49,    51,   130,   137,   120,   121,   130,   137,
     199,   200,   199,   137,    43,    46,    49,   137,   199,    49,
      49,    46,     4,    97,   137,     4,     6,    46,     4,     4,
       4,   130,   130,   130,     4,   137,   205,     4,   130,   130,
       6,   132,     4,     4,     4,     5,   137,   208,   209,   137,
     208,     4,   132,   134,   139,   163,   137,   209,   130,   132,
     130,   132,   130,   132,   130,   132,   130,   132,   130,   132,
     130,   132,   130,   132,   130,   132,   130,   132,   130,   132,
     130,   132,   130,   132,   130,   132,   130,   132,   130,   132,
     130,   132,   130,   132,   130,   132,   130,   132,   130,   132,
     130,   130,   130,   130,     7,   130,     4,   197,   197,   197,
     197,   133,   137,   197,     4,    89,    90,     4,     4,   168,
     169,   170,   197,     6,     6,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   129,
       6,     6,   197,     5,   197,   197,     4,    43,   121,   168,
     176,   197,   203,   204,   197,   197,   130,   197,   204,   197,
     197,   130,   204,   197,   197,   121,   137,   197,   202,   203,
     130,   197,   137,   130,   130,   202,   137,   137,   130,   130,
     130,   130,   130,     4,   199,   199,   199,   197,   197,   120,
     121,   137,   137,   199,   137,   137,   137,   120,   121,   130,
     170,   199,   137,   202,   202,   130,     4,     6,   132,   132,
     170,     6,   137,   132,   132,     6,   197,   197,   197,   134,
     197,   137,    92,   197,   197,   197,     6,   132,   134,   170,
       6,   170,     6,   132,   197,     4,   137,   147,     6,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   208,   208,   208,   208,   197,     5,   132,   131,     7,
     110,   204,   133,     7,   162,   163,   134,     7,   132,   138,
      43,    46,    49,    51,   167,     6,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,     6,   131,   136,   136,   131,   132,   137,   197,   203,
       8,   122,   136,   138,   131,   131,   197,   131,   138,   131,
     131,   197,   138,   131,   131,   137,   138,   204,   122,     7,
     197,   131,   197,   197,   197,     7,   197,   197,   197,   165,
     197,   209,   165,   165,   165,   131,   136,   136,   136,   199,
     199,   169,   169,   136,   197,   197,   197,   197,   180,   136,
     170,     6,     7,     7,   197,     6,   197,   197,   138,   204,
     197,   197,   131,   131,   131,    89,   136,   170,   137,     8,
     131,   133,   197,     4,   138,   138,   197,   133,   163,   197,
       4,    79,    80,    81,    82,   138,   150,   154,   157,   159,
     160,   131,   133,   131,   133,   131,   133,   131,   133,   131,
     133,   131,   133,   131,   133,   131,   133,   131,   133,   131,
     133,   131,   133,   136,   136,   131,   133,   131,   133,   131,
     133,   131,   133,   131,   133,   131,   133,   136,   136,   136,
     136,   136,   136,   131,   136,   136,   131,   131,     6,   136,
     197,   202,   202,   138,     7,   134,   162,   163,   209,   197,
       6,     4,     4,   137,   206,   133,   137,   137,   137,   137,
       8,     6,   117,   144,   204,   197,     7,   133,   137,   197,
     197,   197,   203,   197,   203,    92,     7,     7,   131,     7,
      92,     7,     7,   131,    92,     7,     7,   204,   138,   137,
     197,   131,     7,   138,   131,   131,   197,   138,   138,   131,
     131,   131,   131,   131,   134,   199,   197,   197,   138,   138,
     197,   136,   136,   136,    69,    75,    76,   190,   191,   199,
     138,   177,   197,   197,   131,   133,   133,   138,   133,   133,
       7,     7,     7,   134,   197,   138,   197,   197,     7,   134,
     133,   133,   134,   163,   208,   138,   151,   130,   130,   137,
     161,     6,   197,   197,   197,   197,   197,   197,   197,   197,
     204,   208,   197,   133,     6,     6,   133,     4,    89,    90,
     197,     6,     6,     6,     7,   132,   205,   207,     6,   204,
     204,   204,   204,   197,   117,   208,   131,   136,   199,   204,
     138,     8,    49,   202,   202,     7,   202,    49,    51,   202,
     202,     7,    51,   202,   202,   138,   204,     6,     7,   137,
       7,     7,     7,    61,   192,     7,     7,     7,     7,     7,
       7,     7,     4,   136,   136,   136,   138,   199,   199,   199,
       6,   137,   130,   138,   191,   136,   190,     6,     6,   137,
       6,     6,    49,     6,     6,   202,   202,   202,     4,   136,
       8,     8,   131,     4,     4,   134,     6,     4,     6,   130,
     197,   197,   201,   202,   137,   131,   133,   131,   133,   131,
     133,   131,   133,   131,   131,   131,   162,     7,   162,   163,
     134,     7,     6,   205,   197,   136,   138,   138,   138,   138,
     138,     6,     6,   144,   197,     6,   138,   197,   137,     6,
      56,     6,    56,   202,     6,   137,   137,     6,     6,   202,
     137,     6,     6,   138,     5,   197,   202,   202,   202,     4,
       6,   202,   202,   202,   202,   202,   202,   202,     6,     7,
     197,   197,   197,   137,   136,   138,   136,   138,   136,   138,
     197,   202,   197,   197,   199,   138,   204,   137,     6,     6,
      88,   197,   197,   197,     6,     7,     4,   163,   148,   197,
     136,   136,   136,   138,   149,   197,   202,   209,   197,     6,
       4,   206,     6,   133,   205,     6,     6,     6,     6,   208,
     136,   133,   197,   199,   199,     6,   197,   197,     6,   197,
       5,   136,     6,     6,    92,   166,   197,     4,   193,     6,
       6,     6,     6,     6,     6,   197,   209,   138,   131,   136,
     138,   169,   199,     6,   181,   199,     6,   182,   199,     6,
     183,   138,   136,   131,   138,   136,   138,   197,   202,   136,
     138,     8,   138,   131,   137,   197,   209,   131,   136,   197,
     197,   202,   137,   136,   138,     6,     6,     6,     7,     6,
     134,     6,   197,   138,     6,     6,   138,   138,   138,     5,
     197,    47,     6,     6,     6,     6,   137,   197,   138,   136,
     137,   136,   137,   136,   137,     6,   202,     7,   137,   197,
       6,   138,    87,   197,   197,   204,     6,     6,   152,   197,
     136,   136,   201,   197,     6,   205,    90,   136,     6,     6,
       6,     6,     6,   136,   137,   169,   136,   138,   197,   199,
     190,   197,   199,   190,   197,   199,   190,   136,   138,   202,
     170,   138,   197,   138,   138,   138,   137,   197,   197,   138,
       6,   197,     5,   197,   138,   197,   138,   136,   138,   138,
     136,   138,   138,   136,   138,   202,     6,    61,   138,   178,
     137,     6,     6,   149,   131,   136,     6,   137,   136,   136,
     138,   138,     6,   184,   197,     6,     6,   185,   197,     6,
       6,   186,   197,     6,   138,   197,   190,   170,   138,   155,
     197,   201,   197,     5,   137,   138,   137,   138,   137,   138,
       6,     6,   138,   138,   179,     6,   137,   131,   138,   138,
     136,   190,     6,   187,   190,     6,   188,   190,     6,   189,
     190,   153,   208,   158,   137,     6,     5,   138,   137,   138,
     137,   138,   137,   138,   136,   138,   137,   201,   138,     6,
     190,     6,   190,     6,   190,   208,     6,   156,   208,   138,
       6,   138,   138,   138,   136,   138,     6,     6,     6,     6,
     208,     6
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
#line 139 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 150 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 151 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 152 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 153 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 154 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 155 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 156 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 157 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 158 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 159 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 160 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 161 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 162 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 163 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 168 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 21:
#line 172 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 22:
#line 179 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 23:
#line 184 "Gmsh.y"
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
#line 199 "Gmsh.y"
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
#line 212 "Gmsh.y"
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
#line 241 "Gmsh.y"
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
#line 255 "Gmsh.y"
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
#line 266 "Gmsh.y"
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
#line 280 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData = new PViewDataList(true); 
#endif
    ;}
    break;

  case 35:
#line 294 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 36:
#line 296 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 37:
#line 301 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(1) - (1)].d)); ;}
    break;

  case 38:
#line 303 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[(3) - (3)].d)); ;}
    break;

  case 39:
#line 308 "Gmsh.y"
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
#line 454 "Gmsh.y"
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
#line 464 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 42:
#line 473 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(ViewData->T2C, &(yyvsp[(1) - (1)].c)[i]); 
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 43:
#line 480 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(ViewData->T2C, &(yyvsp[(3) - (3)].c)[i]); 
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 44:
#line 490 "Gmsh.y"
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
#line 500 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 46:
#line 509 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c))+1; i++) List_Add(ViewData->T3C, &(yyvsp[(1) - (1)].c)[i]); 
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 47:
#line 516 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c))+1; i++) List_Add(ViewData->T3C, &(yyvsp[(3) - (3)].c)[i]); 
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 48:
#line 526 "Gmsh.y"
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
#line 535 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 50:
#line 545 "Gmsh.y"
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
#line 562 "Gmsh.y"
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
#line 578 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewValueList = ViewData->Time;
#endif
    ;}
    break;

  case 53:
#line 584 "Gmsh.y"
    {
    ;}
    break;

  case 54:
#line 591 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 55:
#line 592 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 56:
#line 593 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 57:
#line 594 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 58:
#line 595 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 59:
#line 599 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 60:
#line 600 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 61:
#line 608 "Gmsh.y"
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
#line 630 "Gmsh.y"
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
#line 657 "Gmsh.y"
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
#line 697 "Gmsh.y"
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
#line 707 "Gmsh.y"
    {
      // appends to the list
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].push_back(*(double*)List_Pointer((yyvsp[(5) - (6)].l), i));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 66:
#line 715 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c)); 
      else
	gmsh_yysymbols[(yyvsp[(1) - (3)].c)][0] += (yyvsp[(2) - (3)].i);
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 67:
#line 723 "Gmsh.y"
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
#line 735 "Gmsh.y"
    { 
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 69:
#line 744 "Gmsh.y"
    { 
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 70:
#line 749 "Gmsh.y"
    { 
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].c));
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 71:
#line 757 "Gmsh.y"
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
#line 775 "Gmsh.y"
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
#line 793 "Gmsh.y"
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
#line 802 "Gmsh.y"
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
#line 814 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 76:
#line 819 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 77:
#line 827 "Gmsh.y"
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
#line 847 "Gmsh.y"
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
#line 870 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->background_field = (int)(yyvsp[(4) - (5)].d);
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
    ;}
    break;

  case 80:
#line 877 "Gmsh.y"
    {
      if(!GModel::current()->getFields()->new_field((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 81:
#line 883 "Gmsh.y"
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
#line 903 "Gmsh.y"
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
#line 924 "Gmsh.y"
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
#line 950 "Gmsh.y"
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
#line 962 "Gmsh.y"
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
#line 979 "Gmsh.y"
    { 
      (yyval.i) = (int)(yyvsp[(1) - (1)].d); 
    ;}
    break;

  case 87:
#line 983 "Gmsh.y"
    { 
      (yyval.i) = GModel::current()->setPhysicalName
	(std::string((yyvsp[(1) - (1)].c)), ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 88:
#line 992 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 89:
#line 996 "Gmsh.y"
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
#line 1014 "Gmsh.y"
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
#line 1037 "Gmsh.y"
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
#line 1053 "Gmsh.y"
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
#line 1075 "Gmsh.y"
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
#line 1093 "Gmsh.y"
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
#line 1111 "Gmsh.y"
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
#line 1129 "Gmsh.y"
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
#line 1155 "Gmsh.y"
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
#line 1173 "Gmsh.y"
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
#line 1200 "Gmsh.y"
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
#line 1219 "Gmsh.y"
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
#line 1237 "Gmsh.y"
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
#line 1255 "Gmsh.y"
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
#line 1281 "Gmsh.y"
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
#line 1298 "Gmsh.y"
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
#line 1317 "Gmsh.y"
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
#line 1335 "Gmsh.y"
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
#line 1374 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 108:
#line 1380 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 109:
#line 1386 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 110:
#line 1393 "Gmsh.y"
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
#line 1418 "Gmsh.y"
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
#line 1443 "Gmsh.y"
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
#line 1459 "Gmsh.y"
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
#line 1479 "Gmsh.y"
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
#line 1497 "Gmsh.y"
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
#line 1514 "Gmsh.y"
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
#line 1535 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 118:
#line 1540 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 119:
#line 1545 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 120:
#line 1550 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 121:
#line 1555 "Gmsh.y"
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
#line 1575 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 123:
#line 1581 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp=ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d),tmp,(yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 124:
#line 1591 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 125:
#line 1592 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 126:
#line 1597 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 127:
#line 1601 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 128:
#line 1605 "Gmsh.y"
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
#line 1628 "Gmsh.y"
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
#line 1651 "Gmsh.y"
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
#line 1674 "Gmsh.y"
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
#line 1702 "Gmsh.y"
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
#line 1711 "Gmsh.y"
    {
      GModel::current()->getFields()->delete_field((int)(yyvsp[(4) - (6)].d));
    ;}
    break;

  case 134:
#line 1715 "Gmsh.y"
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
#line 1730 "Gmsh.y"
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
#line 1751 "Gmsh.y"
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
#line 1768 "Gmsh.y"
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
#line 1782 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 139:
#line 1788 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 140:
#line 1794 "Gmsh.y"
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
#line 1803 "Gmsh.y"
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
#line 1817 "Gmsh.y"
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
#line 1865 "Gmsh.y"
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
#line 1883 "Gmsh.y"
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
#line 1898 "Gmsh.y"
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
#line 1917 "Gmsh.y"
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
#line 1929 "Gmsh.y"
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
#line 1953 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 149:
#line 1957 "Gmsh.y"
    {
      CTX.forced_bbox = 0;
      SetBoundingBox();
    ;}
    break;

  case 150:
#line 1962 "Gmsh.y"
    {
      CTX.forced_bbox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 151:
#line 1967 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      Draw();
#endif
    ;}
    break;

  case 152:
#line 1979 "Gmsh.y"
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
#line 1996 "Gmsh.y"
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
#line 2013 "Gmsh.y"
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
#line 2032 "Gmsh.y"
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
#line 2051 "Gmsh.y"
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
#line 2079 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname,
						      gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 158:
#line 2087 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&gmsh_yyin, gmsh_yyname,
						     gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 159:
#line 2093 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname,
						     gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 160:
#line 2100 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 161:
#line 2104 "Gmsh.y"
    {
    ;}
    break;

  case 162:
#line 2113 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 163:
#line 2121 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 164:
#line 2129 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 165:
#line 2137 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 166:
#line 2141 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 167:
#line 2149 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 168:
#line 2153 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 169:
#line 2161 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 170:
#line 2165 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 171:
#line 2173 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 172:
#line 2177 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 173:
#line 2186 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 174:
#line 2193 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 175:
#line 2200 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 176:
#line 2207 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 177:
#line 2214 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 178:
#line 2221 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 179:
#line 2228 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 180:
#line 2235 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 181:
#line 2242 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 182:
#line 2249 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 183:
#line 2253 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 184:
#line 2260 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 185:
#line 2264 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 186:
#line 2271 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 187:
#line 2275 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 188:
#line 2282 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 189:
#line 2286 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 190:
#line 2293 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 191:
#line 2297 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 192:
#line 2304 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 193:
#line 2308 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 194:
#line 2315 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 195:
#line 2319 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 196:
#line 2326 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 197:
#line 2330 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 198:
#line 2337 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 199:
#line 2341 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 200:
#line 2352 "Gmsh.y"
    {
    ;}
    break;

  case 201:
#line 2355 "Gmsh.y"
    {
    ;}
    break;

  case 202:
#line 2361 "Gmsh.y"
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
#line 2370 "Gmsh.y"
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
#line 2390 "Gmsh.y"
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
#line 2413 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 206:
#line 2417 "Gmsh.y"
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
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 208:
#line 2444 "Gmsh.y"
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

  case 209:
#line 2459 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 210:
#line 2463 "Gmsh.y"
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

  case 211:
#line 2476 "Gmsh.y"
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
            ge->meshAttributes.typeTransfinite = sign(d);
            ge->meshAttributes.coeffTransfinite = 1.;
          }
          else
	    yymsg(0, "Unknown line %d", j);
        }
      }
      List_Delete((yyvsp[(3) - (7)].l));
    ;}
    break;

  case 212:
#line 2505 "Gmsh.y"
    {
      int k = List_Nbr((yyvsp[(7) - (9)].l));
      if(k != 3 && k != 4){
        yymsg(0, "Wrong definition of Transfinite Surface %d: "
              "%d points instead of 3 or 4" , (int)(yyvsp[(4) - (9)].d), k);
      }
      else{
        Surface *s = FindSurface((int)(yyvsp[(4) - (9)].d));
        if(s){
          s->Method = MESH_TRANSFINITE;
          s->Recombine_Dir = (yyvsp[(8) - (9)].i);
	  List_Reset(s->TrsfPoints);
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read((yyvsp[(7) - (9)].l), i, &d);
	    Vertex *v = FindPoint((int)fabs(d));
	    if(v)
	      List_Add(s->TrsfPoints, &v);
	    else
	      yymsg(0, "Unknown point %d", (int)fabs(d));
	  }
	}
        else{
	  GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[(4) - (9)].d));
          if(gf){
            gf->meshAttributes.Method = MESH_TRANSFINITE;
            gf->meshAttributes.transfiniteArrangement = (yyvsp[(8) - (9)].i);
            for(int i = 0; i < k; i++){
              double d;
              List_Read((yyvsp[(7) - (9)].l), i, &d);
              GVertex *gv = GModel::current()->getVertexByTag((int)fabs(d));
              if(gv)
                gf->meshAttributes.corners.push_back(gv);
              else
                yymsg(0, "Unknown point %d", (int)fabs(d));
            }
          }
          else
	    yymsg(0, "Unknown surface %d", (int)(yyvsp[(4) - (9)].d));
        }
      }
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 213:
#line 2549 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 214:
#line 2554 "Gmsh.y"
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

  case 215:
#line 2596 "Gmsh.y"
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
        else{
	  GFace *gf = GModel::current()->getFaceByTag(j);
	  if(gf){
            gf->meshAttributes.recombine = 1;
            gf->meshAttributes.recombineAngle = (yyvsp[(5) - (6)].d);
	  }
          else
	    yymsg(1, "Unknown surface %d", j);
	}
      }
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 216:
#line 2619 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (4)].l), i, &d);
	int j = (int)d;
        Surface *s = FindSurface(j);
	if(s){
	  s->Recombine = 1;
        }
        else{
	  GFace *gf = GModel::current()->getFaceByTag(j);
	  if(gf)
            gf->meshAttributes.recombine = 1;
          else
	    yymsg(1, "Unknown surface %d", j);
        }
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 217:
#line 2639 "Gmsh.y"
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

  case 218:
#line 2665 "Gmsh.y"
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

  case 219:
#line 2688 "Gmsh.y"
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

  case 220:
#line 2711 "Gmsh.y"
    {
    ;}
    break;

  case 221:
#line 2714 "Gmsh.y"
    {
    ;}
    break;

  case 222:
#line 2723 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 223:
#line 2727 "Gmsh.y"
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

  case 224:
#line 2742 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 225:
#line 2743 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 226:
#line 2744 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 227:
#line 2745 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 228:
#line 2746 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 229:
#line 2747 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 230:
#line 2748 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 231:
#line 2749 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 232:
#line 2751 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 233:
#line 2757 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 234:
#line 2758 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 235:
#line 2759 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 236:
#line 2760 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 237:
#line 2761 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 238:
#line 2762 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 239:
#line 2763 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 240:
#line 2764 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 241:
#line 2765 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 242:
#line 2766 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 243:
#line 2767 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 244:
#line 2768 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 245:
#line 2769 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 246:
#line 2770 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 247:
#line 2771 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 248:
#line 2772 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 249:
#line 2773 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 250:
#line 2774 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 251:
#line 2775 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 252:
#line 2776 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 253:
#line 2777 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 254:
#line 2778 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 255:
#line 2779 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 256:
#line 2780 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 257:
#line 2781 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 258:
#line 2782 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 259:
#line 2783 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 260:
#line 2784 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 261:
#line 2785 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 262:
#line 2786 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 263:
#line 2787 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 264:
#line 2788 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 265:
#line 2790 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 266:
#line 2791 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 267:
#line 2792 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 268:
#line 2793 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 269:
#line 2794 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 270:
#line 2795 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 271:
#line 2796 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 272:
#line 2797 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 273:
#line 2798 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 274:
#line 2799 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 275:
#line 2800 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 276:
#line 2801 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 277:
#line 2802 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 278:
#line 2803 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 279:
#line 2804 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 280:
#line 2805 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 281:
#line 2806 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 282:
#line 2807 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 283:
#line 2808 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 284:
#line 2809 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 285:
#line 2810 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 286:
#line 2819 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 287:
#line 2820 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 288:
#line 2821 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 289:
#line 2822 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 290:
#line 2823 "Gmsh.y"
    { (yyval.d) = Get_GmshMajorVersion(); ;}
    break;

  case 291:
#line 2824 "Gmsh.y"
    { (yyval.d) = Get_GmshMinorVersion(); ;}
    break;

  case 292:
#line 2825 "Gmsh.y"
    { (yyval.d) = Get_GmshPatchVersion(); ;}
    break;

  case 293:
#line 2830 "Gmsh.y"
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

  case 294:
#line 2843 "Gmsh.y"
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

  case 295:
#line 2855 "Gmsh.y"
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

  case 296:
#line 2870 "Gmsh.y"
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

  case 297:
#line 2880 "Gmsh.y"
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

  case 298:
#line 2890 "Gmsh.y"
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

  case 299:
#line 2908 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 300:
#line 2913 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 301:
#line 2918 "Gmsh.y"
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

  case 302:
#line 2928 "Gmsh.y"
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

  case 303:
#line 2938 "Gmsh.y"
    { 
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 304:
#line 2946 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 305:
#line 2950 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 306:
#line 2954 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 307:
#line 2958 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 308:
#line 2962 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 309:
#line 2969 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 310:
#line 2973 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 311:
#line 2977 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 312:
#line 2981 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 313:
#line 2988 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 314:
#line 2993 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 315:
#line 3000 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 316:
#line 3005 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 317:
#line 3009 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 318:
#line 3014 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 319:
#line 3018 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 320:
#line 3026 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 321:
#line 3037 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 322:
#line 3045 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 323:
#line 3053 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 324:
#line 3059 "Gmsh.y"
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

  case 325:
#line 3070 "Gmsh.y"
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

  case 326:
#line 3090 "Gmsh.y"
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
#line 3100 "Gmsh.y"
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
#line 3110 "Gmsh.y"
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

  case 329:
#line 3120 "Gmsh.y"
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

  case 330:
#line 3140 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 331:
#line 3145 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 332:
#line 3149 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 333:
#line 3153 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 334:
#line 3165 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 335:
#line 3169 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 336:
#line 3181 "Gmsh.y"
    {
      int flag;
      (yyval.u) = Get_ColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 337:
#line 3188 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 338:
#line 3198 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 339:
#line 3202 "Gmsh.y"
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

  case 340:
#line 3217 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 341:
#line 3222 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 342:
#line 3229 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 343:
#line 3233 "Gmsh.y"
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

  case 344:
#line 3246 "Gmsh.y"
    { 
      const char *val = "";
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), val);
      (yyval.c) = (char*)Malloc((strlen(val) + 1) * sizeof(char));
      strcpy((yyval.c), val);
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 345:
#line 3254 "Gmsh.y"
    { 
      const char *val = "";
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), val);
      (yyval.c) = (char*)Malloc((strlen(val) + 1) * sizeof(char));
      strcpy((yyval.c), val);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 346:
#line 3265 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 347:
#line 3269 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 348:
#line 3277 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 349:
#line 3285 "Gmsh.y"
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

  case 350:
#line 3299 "Gmsh.y"
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

  case 351:
#line 3313 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 352:
#line 3317 "Gmsh.y"
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
#line 7723 "Gmsh.tab.cpp"
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


#line 3337 "Gmsh.y"


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

