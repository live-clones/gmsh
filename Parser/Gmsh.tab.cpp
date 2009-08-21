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
     tPoint = 300,
     tCircle = 301,
     tEllipse = 302,
     tLine = 303,
     tSphere = 304,
     tPolarSphere = 305,
     tSurface = 306,
     tSpline = 307,
     tVolume = 308,
     tCharacteristic = 309,
     tLength = 310,
     tParametric = 311,
     tElliptic = 312,
     tPlane = 313,
     tRuled = 314,
     tTransfinite = 315,
     tComplex = 316,
     tPhysical = 317,
     tCompound = 318,
     tUsing = 319,
     tPlugin = 320,
     tRotate = 321,
     tTranslate = 322,
     tSymmetry = 323,
     tDilate = 324,
     tExtrude = 325,
     tLevelset = 326,
     tLoop = 327,
     tRecombine = 328,
     tSmoother = 329,
     tSplit = 330,
     tDelete = 331,
     tCoherence = 332,
     tIntersect = 333,
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
     tReturn = 357,
     tCall = 358,
     tFunction = 359,
     tShow = 360,
     tHide = 361,
     tGetValue = 362,
     tGMSH_MAJOR_VERSION = 363,
     tGMSH_MINOR_VERSION = 364,
     tGMSH_PATCH_VERSION = 365,
     tAFFECTDIVIDE = 366,
     tAFFECTTIMES = 367,
     tAFFECTMINUS = 368,
     tAFFECTPLUS = 369,
     tOR = 370,
     tAND = 371,
     tNOTEQUAL = 372,
     tEQUAL = 373,
     tGREATEROREQUAL = 374,
     tLESSOREQUAL = 375,
     UNARYPREC = 376,
     tMINUSMINUS = 377,
     tPLUSPLUS = 378
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
#define tPoint 300
#define tCircle 301
#define tEllipse 302
#define tLine 303
#define tSphere 304
#define tPolarSphere 305
#define tSurface 306
#define tSpline 307
#define tVolume 308
#define tCharacteristic 309
#define tLength 310
#define tParametric 311
#define tElliptic 312
#define tPlane 313
#define tRuled 314
#define tTransfinite 315
#define tComplex 316
#define tPhysical 317
#define tCompound 318
#define tUsing 319
#define tPlugin 320
#define tRotate 321
#define tTranslate 322
#define tSymmetry 323
#define tDilate 324
#define tExtrude 325
#define tLevelset 326
#define tLoop 327
#define tRecombine 328
#define tSmoother 329
#define tSplit 330
#define tDelete 331
#define tCoherence 332
#define tIntersect 333
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
#define tReturn 357
#define tCall 358
#define tFunction 359
#define tShow 360
#define tHide 361
#define tGetValue 362
#define tGMSH_MAJOR_VERSION 363
#define tGMSH_MINOR_VERSION 364
#define tGMSH_PATCH_VERSION 365
#define tAFFECTDIVIDE 366
#define tAFFECTTIMES 367
#define tAFFECTMINUS 368
#define tAFFECTPLUS 369
#define tOR 370
#define tAND 371
#define tNOTEQUAL 372
#define tEQUAL 373
#define tGREATEROREQUAL 374
#define tLESSOREQUAL 375
#define UNARYPREC 376
#define tMINUSMINUS 377
#define tPLUSPLUS 378




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GmshMatrix.h"
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
#include "gmshLevelset.h"
#include "Field.h"
#include "BackgroundMesh.h"
#if !defined(HAVE_NO_POST)
#include "PView.h"
#include "PViewDataList.h"
#include "PluginManager.h"
#endif

// Global parser variables
std::string gmsh_yyname;
int gmsh_yyerrorstate = 0;
int gmsh_yyviewindex = 0;
std::map<std::string, std::vector<double> > gmsh_yysymbols;

// Static parser variables (accessible only in this file)
static std::map<std::string, std::string > gmsh_yystringsymbols;
#if !defined(HAVE_NO_POST)
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
static char *LoopControlVariablesNameTab[MAX_RECUR_LOOPS];

void yyerror(char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
gmshMatrix<double> ListOfListOfDouble2Matrix(List_T *list);
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
#line 74 "Gmsh.y"
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
#line 433 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 446 "Gmsh.tab.cpp"

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
#define YYLAST   6877

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  144
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  375
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1312

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   378

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   129,     2,   139,     2,   128,     2,     2,
     134,   135,   126,   124,   140,   125,   138,   127,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     120,     2,   121,   115,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   136,     2,   137,   133,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   141,     2,   142,   143,     2,     2,     2,
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
     116,   117,   118,   119,   122,   123,   130,   131,   132
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    47,    53,    61,    69,    79,    86,    93,
     100,   101,   104,   107,   110,   113,   116,   118,   122,   124,
     128,   129,   130,   141,   143,   147,   148,   162,   164,   168,
     169,   185,   194,   209,   210,   217,   219,   221,   223,   225,
     227,   229,   231,   236,   244,   254,   261,   268,   272,   279,
     284,   291,   301,   308,   318,   324,   333,   342,   354,   361,
     371,   377,   385,   395,   405,   417,   427,   437,   439,   441,
     442,   448,   449,   452,   460,   461,   471,   478,   486,   494,
     503,   512,   520,   528,   540,   549,   550,   560,   569,   579,
     583,   588,   599,   607,   615,   624,   625,   635,   644,   657,
     666,   675,   684,   692,   693,   703,   709,   721,   727,   737,
     742,   752,   762,   764,   766,   767,   770,   777,   784,   791,
     798,   807,   822,   839,   852,   861,   870,   877,   892,   897,
     904,   911,   915,   920,   926,   930,   934,   939,   944,   948,
     956,   964,   968,   976,   980,   983,   986,   989,  1005,  1008,
    1011,  1018,  1027,  1036,  1047,  1049,  1052,  1054,  1058,  1063,
    1065,  1071,  1083,  1097,  1098,  1106,  1107,  1121,  1122,  1138,
    1139,  1146,  1155,  1164,  1173,  1186,  1199,  1212,  1227,  1242,
    1257,  1258,  1271,  1272,  1285,  1286,  1299,  1300,  1317,  1318,
    1335,  1336,  1353,  1354,  1373,  1374,  1393,  1394,  1413,  1415,
    1418,  1424,  1432,  1442,  1445,  1455,  1456,  1460,  1461,  1463,
    1464,  1467,  1468,  1471,  1479,  1486,  1495,  1501,  1507,  1514,
    1525,  1536,  1547,  1558,  1561,  1565,  1567,  1571,  1574,  1577,
    1580,  1584,  1588,  1592,  1596,  1600,  1604,  1608,  1612,  1616,
    1620,  1624,  1628,  1632,  1636,  1642,  1647,  1652,  1657,  1662,
    1667,  1672,  1677,  1682,  1687,  1692,  1699,  1704,  1709,  1714,
    1719,  1724,  1729,  1736,  1743,  1750,  1755,  1760,  1765,  1770,
    1775,  1780,  1785,  1790,  1795,  1800,  1805,  1812,  1817,  1822,
    1827,  1832,  1837,  1842,  1849,  1856,  1863,  1868,  1870,  1872,
    1874,  1876,  1878,  1880,  1882,  1884,  1890,  1895,  1900,  1903,
    1909,  1913,  1920,  1925,  1933,  1940,  1942,  1945,  1948,  1952,
    1956,  1968,  1978,  1986,  1994,  1996,  2000,  2002,  2004,  2007,
    2011,  2016,  2022,  2024,  2026,  2029,  2033,  2037,  2043,  2048,
    2050,  2052,  2056,  2063,  2065,  2067,  2071,  2075,  2085,  2093,
    2095,  2101,  2105,  2112,  2114,  2118,  2120,  2122,  2126,  2133,
    2135,  2137,  2144,  2149,  2154,  2159
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     145,     0,    -1,   146,    -1,     1,     6,    -1,    -1,   146,
     147,    -1,   150,    -1,   149,    -1,   168,    -1,   172,    -1,
     177,    -1,   181,    -1,   182,    -1,   183,    -1,   186,    -1,
     206,    -1,   207,    -1,   208,    -1,   185,    -1,   184,    -1,
     180,    -1,   121,    -1,   121,   121,    -1,    35,   134,     5,
     135,     6,    -1,    35,   134,     5,   135,   148,   221,     6,
      -1,    35,   134,     5,   140,   217,   135,     6,    -1,    35,
     134,     5,   140,   217,   135,   148,   221,     6,    -1,     4,
       5,   141,   151,   142,     6,    -1,    81,     4,   136,   209,
     137,     6,    -1,    82,     4,   136,   209,   137,     6,    -1,
      -1,   151,   154,    -1,   151,   158,    -1,   151,   161,    -1,
     151,   163,    -1,   151,   164,    -1,   209,    -1,   152,   140,
     209,    -1,   209,    -1,   153,   140,   209,    -1,    -1,    -1,
       4,   155,   134,   152,   135,   156,   141,   153,   142,     6,
      -1,   221,    -1,   157,   140,   221,    -1,    -1,    83,   134,
     209,   140,   209,   140,   209,   135,   159,   141,   157,   142,
       6,    -1,   221,    -1,   160,   140,   221,    -1,    -1,    84,
     134,   209,   140,   209,   140,   209,   140,   209,   135,   162,
     141,   160,   142,     6,    -1,    85,   141,   213,   142,   141,
     213,   142,     6,    -1,    85,   141,   213,   142,   141,   213,
     142,   141,   213,   142,   141,   213,   142,     6,    -1,    -1,
      86,   165,   141,   153,   142,     6,    -1,     7,    -1,   114,
      -1,   113,    -1,   112,    -1,   111,    -1,   132,    -1,   131,
      -1,     4,   166,   209,     6,    -1,     4,   136,   209,   137,
     166,   209,     6,    -1,     4,   136,   141,   217,   142,   137,
     166,   214,     6,    -1,     4,   136,   137,     7,   214,     6,
      -1,     4,   136,   137,   114,   214,     6,    -1,     4,   167,
       6,    -1,     4,   136,   209,   137,   167,     6,    -1,     4,
       7,   222,     6,    -1,     4,   138,     4,     7,   222,     6,
      -1,     4,   136,   209,   137,   138,     4,     7,   222,     6,
      -1,     4,   138,     4,   166,   209,     6,    -1,     4,   136,
     209,   137,   138,     4,   166,   209,     6,    -1,     4,   138,
       4,   167,     6,    -1,     4,   136,   209,   137,   138,     4,
     167,     6,    -1,     4,   138,    93,   138,     4,     7,   218,
       6,    -1,     4,   136,   209,   137,   138,    93,   138,     4,
       7,   218,     6,    -1,     4,   138,    94,     7,   219,     6,
      -1,     4,   136,   209,   137,   138,    94,     7,   219,     6,
      -1,     4,   101,     7,   209,     6,    -1,   101,   136,   209,
     137,     7,     4,     6,    -1,   101,   136,   209,   137,   138,
       4,     7,   209,     6,    -1,   101,   136,   209,   137,   138,
       4,     7,   222,     6,    -1,   101,   136,   209,   137,   138,
       4,     7,   141,   217,   142,     6,    -1,    65,   134,     4,
     135,   138,     4,     7,   209,     6,    -1,    65,   134,     4,
     135,   138,     4,     7,   222,     6,    -1,   209,    -1,   222,
      -1,    -1,    96,    49,   141,   209,   142,    -1,    -1,    58,
     211,    -1,    45,   134,   209,   135,     7,   211,     6,    -1,
      -1,    62,    45,   173,   134,   169,   135,     7,   214,     6,
      -1,    54,    55,   214,     7,   209,     6,    -1,    48,   134,
     209,   135,     7,   214,     6,    -1,    52,   134,   209,   135,
       7,   214,     6,    -1,    46,   134,   209,   135,     7,   214,
     171,     6,    -1,    47,   134,   209,   135,     7,   214,   171,
       6,    -1,    88,   134,   209,   135,     7,   214,     6,    -1,
      89,   134,   209,   135,     7,   214,     6,    -1,    90,   134,
     209,   135,     7,   214,    92,   214,    91,   209,     6,    -1,
      48,    72,   134,   209,   135,     7,   214,     6,    -1,    -1,
      62,    48,   174,   134,   169,   135,     7,   214,     6,    -1,
      58,    51,   134,   209,   135,     7,   214,     6,    -1,    59,
      51,   134,   209,   135,     7,   214,   170,     6,    -1,    12,
      13,     6,    -1,    13,    51,   209,     6,    -1,    56,    51,
     134,   209,   135,     7,     5,     5,     5,     6,    -1,    49,
     134,   209,   135,     7,   214,     6,    -1,    50,   134,   209,
     135,     7,   214,     6,    -1,    51,    72,   134,   209,   135,
       7,   214,     6,    -1,    -1,    62,    51,   175,   134,   169,
     135,     7,   214,     6,    -1,    63,    53,   134,   209,   135,
       7,   214,     6,    -1,    63,    51,   134,   209,   135,     7,
     214,     4,   141,   213,   142,     6,    -1,    63,    51,   134,
     209,   135,     7,   214,     6,    -1,    63,    48,   134,   209,
     135,     7,   214,     6,    -1,    61,    53,   134,   209,   135,
       7,   214,     6,    -1,    53,   134,   209,   135,     7,   214,
       6,    -1,    -1,    62,    53,   176,   134,   169,   135,     7,
     214,     6,    -1,    67,   211,   141,   178,   142,    -1,    66,
     141,   211,   140,   211,   140,   209,   142,   141,   178,   142,
      -1,    68,   211,   141,   178,   142,    -1,    69,   141,   211,
     140,   209,   142,   141,   178,   142,    -1,     4,   141,   178,
     142,    -1,    78,    48,   141,   217,   142,    51,   141,   209,
     142,    -1,    75,    48,   134,   209,   135,   141,   217,   142,
       6,    -1,   179,    -1,   177,    -1,    -1,   179,   172,    -1,
     179,    45,   141,   217,   142,     6,    -1,   179,    48,   141,
     217,   142,     6,    -1,   179,    51,   141,   217,   142,     6,
      -1,   179,    53,   141,   217,   142,     6,    -1,    71,    58,
     134,   209,   135,     7,   214,     6,    -1,    71,    58,   134,
     209,   135,     7,   141,   211,   140,   211,   140,   217,   142,
       6,    -1,    71,    58,   134,   209,   135,     7,   141,   211,
     140,   211,   140,   211,   140,   217,   142,     6,    -1,    71,
      49,   134,   209,   135,     7,   141,   211,   140,   217,   142,
       6,    -1,    71,     4,   134,   209,   135,     7,   214,     6,
      -1,    71,     4,   134,   209,   135,     7,     5,     6,    -1,
      71,     4,   141,   209,   142,     6,    -1,    71,     4,   134,
     209,   135,     7,   141,   211,   140,   211,   140,   217,   142,
       6,    -1,    76,   141,   179,   142,    -1,    76,   101,   136,
     209,   137,     6,    -1,    76,     4,   136,   209,   137,     6,
      -1,    76,     4,     6,    -1,    76,     4,     4,     6,    -1,
      93,   218,   141,   179,   142,    -1,   105,     5,     6,    -1,
     106,     5,     6,    -1,   105,   141,   179,   142,    -1,   106,
     141,   179,   142,    -1,     4,   222,     6,    -1,     4,     4,
     136,   209,   137,   221,     6,    -1,     4,     4,     4,   136,
     209,   137,     6,    -1,     4,   209,     6,    -1,    65,   134,
       4,   135,   138,     4,     6,    -1,    87,     4,     6,    -1,
     100,     6,    -1,    43,     6,    -1,    40,     6,    -1,    40,
     141,   209,   140,   209,   140,   209,   140,   209,   140,   209,
     140,   209,   142,     6,    -1,    41,     6,    -1,    44,     6,
      -1,    95,   134,   209,     8,   209,   135,    -1,    95,   134,
     209,     8,   209,     8,   209,   135,    -1,    95,     4,    96,
     141,   209,     8,   209,   142,    -1,    95,     4,    96,   141,
     209,     8,   209,     8,   209,   142,    -1,    97,    -1,   104,
       4,    -1,   102,    -1,   103,     4,     6,    -1,    98,   134,
     209,   135,    -1,    99,    -1,    70,   211,   141,   179,   142,
      -1,    70,   141,   211,   140,   211,   140,   209,   142,   141,
     179,   142,    -1,    70,   141,   211,   140,   211,   140,   211,
     140,   209,   142,   141,   179,   142,    -1,    -1,    70,   211,
     141,   179,   187,   200,   142,    -1,    -1,    70,   141,   211,
     140,   211,   140,   209,   142,   141,   179,   188,   200,   142,
      -1,    -1,    70,   141,   211,   140,   211,   140,   211,   140,
     209,   142,   141,   179,   189,   200,   142,    -1,    -1,    70,
     141,   179,   190,   200,   142,    -1,    70,    45,   141,   209,
     140,   211,   142,     6,    -1,    70,    48,   141,   209,   140,
     211,   142,     6,    -1,    70,    51,   141,   209,   140,   211,
     142,     6,    -1,    70,    45,   141,   209,   140,   211,   140,
     211,   140,   209,   142,     6,    -1,    70,    48,   141,   209,
     140,   211,   140,   211,   140,   209,   142,     6,    -1,    70,
      51,   141,   209,   140,   211,   140,   211,   140,   209,   142,
       6,    -1,    70,    45,   141,   209,   140,   211,   140,   211,
     140,   211,   140,   209,   142,     6,    -1,    70,    48,   141,
     209,   140,   211,   140,   211,   140,   211,   140,   209,   142,
       6,    -1,    70,    51,   141,   209,   140,   211,   140,   211,
     140,   211,   140,   209,   142,     6,    -1,    -1,    70,    45,
     141,   209,   140,   211,   142,   191,   141,   200,   142,     6,
      -1,    -1,    70,    48,   141,   209,   140,   211,   142,   192,
     141,   200,   142,     6,    -1,    -1,    70,    51,   141,   209,
     140,   211,   142,   193,   141,   200,   142,     6,    -1,    -1,
      70,    45,   141,   209,   140,   211,   140,   211,   140,   209,
     142,   194,   141,   200,   142,     6,    -1,    -1,    70,    48,
     141,   209,   140,   211,   140,   211,   140,   209,   142,   195,
     141,   200,   142,     6,    -1,    -1,    70,    51,   141,   209,
     140,   211,   140,   211,   140,   209,   142,   196,   141,   200,
     142,     6,    -1,    -1,    70,    45,   141,   209,   140,   211,
     140,   211,   140,   211,   140,   209,   142,   197,   141,   200,
     142,     6,    -1,    -1,    70,    48,   141,   209,   140,   211,
     140,   211,   140,   211,   140,   209,   142,   198,   141,   200,
     142,     6,    -1,    -1,    70,    51,   141,   209,   140,   211,
     140,   211,   140,   211,   140,   209,   142,   199,   141,   200,
     142,     6,    -1,   201,    -1,   200,   201,    -1,    79,   141,
     209,   142,     6,    -1,    79,   141,   214,   140,   214,   142,
       6,    -1,    79,   141,   214,   140,   214,   140,   214,   142,
       6,    -1,    73,     6,    -1,    80,   134,   209,   135,     7,
     214,    64,   209,     6,    -1,    -1,    64,     4,   209,    -1,
      -1,     4,    -1,    -1,     7,   214,    -1,    -1,     7,   209,
      -1,    60,    48,   215,     7,   209,   202,     6,    -1,    60,
      51,   215,   204,   203,     6,    -1,    57,    51,   141,   209,
     142,     7,   214,     6,    -1,    60,    53,   215,   204,     6,
      -1,    73,    51,   215,   205,     6,    -1,    74,    51,   214,
       7,   209,     6,    -1,    45,   141,   217,   142,    96,    51,
     141,   209,   142,     6,    -1,    48,   141,   217,   142,    96,
      51,   141,   209,   142,     6,    -1,    48,   141,   217,   142,
      96,    53,   141,   209,   142,     6,    -1,    51,   141,   217,
     142,    96,    53,   141,   209,   142,     6,    -1,    77,     6,
      -1,    77,     4,     6,    -1,   210,    -1,   134,   209,   135,
      -1,   125,   209,    -1,   124,   209,    -1,   129,   209,    -1,
     209,   125,   209,    -1,   209,   124,   209,    -1,   209,   126,
     209,    -1,   209,   127,   209,    -1,   209,   128,   209,    -1,
     209,   133,   209,    -1,   209,   120,   209,    -1,   209,   121,
     209,    -1,   209,   123,   209,    -1,   209,   122,   209,    -1,
     209,   119,   209,    -1,   209,   118,   209,    -1,   209,   117,
     209,    -1,   209,   116,   209,    -1,   209,   115,   209,     8,
     209,    -1,    14,   134,   209,   135,    -1,    15,   134,   209,
     135,    -1,    16,   134,   209,   135,    -1,    17,   134,   209,
     135,    -1,    18,   134,   209,   135,    -1,    19,   134,   209,
     135,    -1,    20,   134,   209,   135,    -1,    21,   134,   209,
     135,    -1,    22,   134,   209,   135,    -1,    24,   134,   209,
     135,    -1,    25,   134,   209,   140,   209,   135,    -1,    26,
     134,   209,   135,    -1,    27,   134,   209,   135,    -1,    28,
     134,   209,   135,    -1,    29,   134,   209,   135,    -1,    30,
     134,   209,   135,    -1,    31,   134,   209,   135,    -1,    32,
     134,   209,   140,   209,   135,    -1,    33,   134,   209,   140,
     209,   135,    -1,    34,   134,   209,   140,   209,   135,    -1,
      23,   134,   209,   135,    -1,    14,   136,   209,   137,    -1,
      15,   136,   209,   137,    -1,    16,   136,   209,   137,    -1,
      17,   136,   209,   137,    -1,    18,   136,   209,   137,    -1,
      19,   136,   209,   137,    -1,    20,   136,   209,   137,    -1,
      21,   136,   209,   137,    -1,    22,   136,   209,   137,    -1,
      24,   136,   209,   137,    -1,    25,   136,   209,   140,   209,
     137,    -1,    26,   136,   209,   137,    -1,    27,   136,   209,
     137,    -1,    28,   136,   209,   137,    -1,    29,   136,   209,
     137,    -1,    30,   136,   209,   137,    -1,    31,   136,   209,
     137,    -1,    32,   136,   209,   140,   209,   137,    -1,    33,
     136,   209,   140,   209,   137,    -1,    34,   136,   209,   140,
     209,   137,    -1,    23,   136,   209,   137,    -1,     3,    -1,
       9,    -1,    10,    -1,    11,    -1,   108,    -1,   109,    -1,
     110,    -1,     4,    -1,     4,   143,   141,   209,   142,    -1,
       4,   136,   209,   137,    -1,   139,     4,   136,   137,    -1,
       4,   167,    -1,     4,   136,   209,   137,   167,    -1,     4,
     138,     4,    -1,     4,   136,   209,   137,   138,     4,    -1,
       4,   138,     4,   167,    -1,     4,   136,   209,   137,   138,
       4,   167,    -1,   107,   134,     5,   140,   209,   135,    -1,
     212,    -1,   125,   211,    -1,   124,   211,    -1,   211,   125,
     211,    -1,   211,   124,   211,    -1,   141,   209,   140,   209,
     140,   209,   140,   209,   140,   209,   142,    -1,   141,   209,
     140,   209,   140,   209,   140,   209,   142,    -1,   141,   209,
     140,   209,   140,   209,   142,    -1,   134,   209,   140,   209,
     140,   209,   135,    -1,   214,    -1,   213,   140,   214,    -1,
     209,    -1,   216,    -1,   141,   142,    -1,   141,   217,   142,
      -1,   125,   141,   217,   142,    -1,   209,   126,   141,   217,
     142,    -1,   214,    -1,     5,    -1,   125,   216,    -1,   209,
     126,   216,    -1,   209,     8,   209,    -1,   209,     8,   209,
       8,   209,    -1,    45,   141,   209,   142,    -1,   177,    -1,
     186,    -1,     4,   136,   137,    -1,     4,   136,   141,   217,
     142,   137,    -1,   209,    -1,   216,    -1,   217,   140,   209,
      -1,   217,   140,   216,    -1,   141,   209,   140,   209,   140,
     209,   140,   209,   142,    -1,   141,   209,   140,   209,   140,
     209,   142,    -1,     4,    -1,     4,   138,    93,   138,     4,
      -1,   141,   220,   142,    -1,     4,   136,   209,   137,   138,
      94,    -1,   218,    -1,   220,   140,   218,    -1,   222,    -1,
       4,    -1,     4,   138,     4,    -1,     4,   136,   209,   137,
     138,     4,    -1,     5,    -1,    42,    -1,    37,   134,   221,
     140,   221,   135,    -1,    38,   134,   221,   135,    -1,    39,
     134,   221,   135,    -1,    36,   134,   221,   135,    -1,    36,
     134,   221,   140,   217,   135,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   142,   142,   143,   148,   150,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   172,   176,   183,   188,   203,   216,   245,   259,   270,
     285,   290,   291,   292,   293,   294,   298,   300,   305,   307,
     313,   417,   312,   435,   442,   453,   452,   470,   477,   488,
     487,   504,   521,   544,   543,   557,   558,   559,   560,   561,
     565,   566,   573,   595,   622,   662,   672,   680,   688,   700,
     709,   715,   724,   742,   760,   769,   781,   786,   794,   814,
     837,   844,   850,   870,   891,   917,   929,   946,   950,   961,
     964,   977,   980,   990,  1014,  1013,  1033,  1055,  1073,  1091,
    1121,  1151,  1169,  1187,  1213,  1231,  1230,  1253,  1271,  1310,
    1316,  1322,  1329,  1354,  1379,  1396,  1395,  1415,  1432,  1460,
    1477,  1497,  1515,  1533,  1532,  1557,  1562,  1567,  1572,  1577,
    1597,  1603,  1614,  1615,  1620,  1623,  1627,  1650,  1673,  1696,
    1724,  1745,  1766,  1788,  1808,  1888,  1907,  1921,  2030,  2039,
    2043,  2058,  2085,  2102,  2116,  2122,  2128,  2137,  2151,  2199,
    2217,  2232,  2251,  2263,  2287,  2291,  2298,  2304,  2309,  2315,
    2324,  2341,  2358,  2377,  2396,  2424,  2432,  2438,  2445,  2449,
    2458,  2466,  2474,  2483,  2482,  2495,  2494,  2507,  2506,  2519,
    2518,  2531,  2538,  2545,  2552,  2559,  2566,  2573,  2580,  2587,
    2595,  2594,  2606,  2605,  2617,  2616,  2628,  2627,  2639,  2638,
    2650,  2649,  2661,  2660,  2672,  2671,  2683,  2682,  2697,  2700,
    2706,  2715,  2735,  2758,  2762,  2786,  2789,  2805,  2808,  2821,
    2824,  2830,  2833,  2840,  2896,  2966,  2971,  3038,  3081,  3107,
    3130,  3153,  3156,  3165,  3169,  3185,  3186,  3187,  3188,  3189,
    3190,  3191,  3192,  3193,  3200,  3201,  3202,  3203,  3204,  3205,
    3206,  3207,  3208,  3209,  3210,  3211,  3212,  3213,  3214,  3215,
    3216,  3217,  3218,  3219,  3220,  3221,  3222,  3223,  3224,  3225,
    3226,  3227,  3228,  3229,  3230,  3231,  3233,  3234,  3235,  3236,
    3237,  3238,  3239,  3240,  3241,  3242,  3243,  3244,  3245,  3246,
    3247,  3248,  3249,  3250,  3251,  3252,  3253,  3262,  3263,  3264,
    3265,  3266,  3267,  3268,  3272,  3285,  3297,  3312,  3322,  3332,
    3350,  3355,  3360,  3370,  3380,  3388,  3392,  3396,  3400,  3404,
    3411,  3415,  3419,  3423,  3430,  3435,  3442,  3447,  3451,  3456,
    3460,  3468,  3479,  3483,  3495,  3503,  3511,  3518,  3529,  3549,
    3559,  3569,  3579,  3599,  3604,  3608,  3612,  3624,  3628,  3640,
    3647,  3657,  3661,  3676,  3681,  3688,  3692,  3705,  3713,  3724,
    3728,  3736,  3744,  3758,  3772,  3776
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
  "tPoint", "tCircle", "tEllipse", "tLine", "tSphere", "tPolarSphere",
  "tSurface", "tSpline", "tVolume", "tCharacteristic", "tLength",
  "tParametric", "tElliptic", "tPlane", "tRuled", "tTransfinite",
  "tComplex", "tPhysical", "tCompound", "tUsing", "tPlugin", "tRotate",
  "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tLoop",
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
  "PhysicalId", "InSphereCenter", "CircleOptions", "Shape", "@6", "@7",
  "@8", "@9", "Transform", "MultipleShape", "ListOfShapes", "LevelSet",
  "Delete", "Colorify", "Visibility", "Command", "Loop", "Extrude", "@10",
  "@11", "@12", "@13", "@14", "@15", "@16", "@17", "@18", "@19", "@20",
  "@21", "@22", "ExtrudeParameters", "ExtrudeParameter", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "Transfinite", "Embedding", "Coherence", "FExpr", "FExpr_Single",
  "VExpr", "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
  "ListOfDoubleOrAll", "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr",
  "ListOfColor", "RecursiveListOfColor", "StringExprVar", "StringExpr", 0
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
     365,   366,   367,   368,   369,    63,   370,   371,   372,   373,
      60,    62,   374,   375,    43,    45,    42,    47,    37,    33,
     376,   377,   378,    94,    40,    41,    91,    93,    46,    35,
      44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   144,   145,   145,   146,   146,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   148,   148,   149,   149,   149,   149,   150,   150,   150,
     151,   151,   151,   151,   151,   151,   152,   152,   153,   153,
     155,   156,   154,   157,   157,   159,   158,   160,   160,   162,
     161,   163,   163,   165,   164,   166,   166,   166,   166,   166,
     167,   167,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   169,   169,   170,
     170,   171,   171,   172,   173,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   174,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   175,   172,   172,   172,   172,
     172,   172,   172,   176,   172,   177,   177,   177,   177,   177,
     177,   177,   178,   178,   179,   179,   179,   179,   179,   179,
     180,   180,   180,   180,   180,   180,   180,   180,   181,   181,
     181,   181,   181,   182,   183,   183,   183,   183,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     186,   186,   186,   187,   186,   188,   186,   189,   186,   190,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     191,   186,   192,   186,   193,   186,   194,   186,   195,   186,
     196,   186,   197,   186,   198,   186,   199,   186,   200,   200,
     201,   201,   201,   201,   201,   202,   202,   203,   203,   204,
     204,   205,   205,   206,   206,   206,   206,   206,   206,   207,
     207,   207,   207,   208,   208,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   211,   211,   211,   211,   211,
     212,   212,   212,   212,   213,   213,   214,   214,   214,   214,
     214,   214,   215,   215,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   217,   217,   217,   217,   218,   218,   218,
     218,   219,   219,   220,   220,   221,   221,   221,   221,   222,
     222,   222,   222,   222,   222,   222
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     7,     7,     9,     6,     6,     6,
       0,     2,     2,     2,     2,     2,     1,     3,     1,     3,
       0,     0,    10,     1,     3,     0,    13,     1,     3,     0,
      15,     8,    14,     0,     6,     1,     1,     1,     1,     1,
       1,     1,     4,     7,     9,     6,     6,     3,     6,     4,
       6,     9,     6,     9,     5,     8,     8,    11,     6,     9,
       5,     7,     9,     9,    11,     9,     9,     1,     1,     0,
       5,     0,     2,     7,     0,     9,     6,     7,     7,     8,
       8,     7,     7,    11,     8,     0,     9,     8,     9,     3,
       4,    10,     7,     7,     8,     0,     9,     8,    12,     8,
       8,     8,     7,     0,     9,     5,    11,     5,     9,     4,
       9,     9,     1,     1,     0,     2,     6,     6,     6,     6,
       8,    14,    16,    12,     8,     8,     6,    14,     4,     6,
       6,     3,     4,     5,     3,     3,     4,     4,     3,     7,
       7,     3,     7,     3,     2,     2,     2,    15,     2,     2,
       6,     8,     8,    10,     1,     2,     1,     3,     4,     1,
       5,    11,    13,     0,     7,     0,    13,     0,    15,     0,
       6,     8,     8,     8,    12,    12,    12,    14,    14,    14,
       0,    12,     0,    12,     0,    12,     0,    16,     0,    16,
       0,    16,     0,    18,     0,    18,     0,    18,     1,     2,
       5,     7,     9,     2,     9,     0,     3,     0,     1,     0,
       2,     0,     2,     7,     6,     8,     5,     5,     6,    10,
      10,    10,    10,     2,     3,     1,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     4,     2,     5,
       3,     6,     4,     7,     6,     1,     2,     2,     3,     3,
      11,     9,     7,     7,     1,     3,     1,     1,     2,     3,
       4,     5,     1,     1,     2,     3,     3,     5,     4,     1,
       1,     3,     6,     1,     1,     3,     3,     9,     7,     1,
       5,     3,     6,     1,     3,     1,     1,     3,     6,     1,
       1,     6,     4,     4,     4,     6
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
       0,     0,     0,   174,     0,   179,     0,     0,   176,     0,
       0,     0,     0,     5,     7,     6,     8,     9,    10,    20,
      11,    12,    13,    19,    18,    14,    15,    16,    17,   307,
     314,   369,    55,   308,   309,   310,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   370,     0,     0,   311,   312,   313,    59,    58,    57,
      56,     0,     0,     0,    61,    60,     0,     0,     0,     0,
     134,     0,     0,     0,   245,     0,     0,     0,     0,   166,
       0,   168,   165,   169,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,   105,   115,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     325,     0,     0,     0,     0,     0,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,     0,   243,     0,
       0,     0,     0,     0,     0,     0,   359,     0,     0,     0,
       0,     0,   164,     0,     0,   175,     0,   134,     0,   134,
       0,     0,     0,     0,   318,    30,   369,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,   248,   247,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   133,
       0,   132,     0,    67,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     158,   109,     0,     0,     0,     0,   314,     0,     0,   349,
     350,   353,   354,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   336,     0,   337,
       0,     0,     0,     0,   343,   342,     0,   229,   229,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   327,
     326,     0,     0,     0,     0,   134,   134,     0,     0,     0,
       0,     0,     0,     0,   189,     0,   134,     0,     0,     0,
       0,   231,     0,     0,     0,   151,     0,     0,     0,   244,
       0,     0,     0,   163,     0,     0,     0,     0,     0,   134,
       0,     0,     0,     0,   177,   154,     0,   155,     0,     0,
       0,   320,     0,     0,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   366,     0,   365,
       0,     0,     0,     0,     0,     0,   246,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,   129,     0,     0,
       0,     0,   135,    62,     0,   263,   262,   261,   260,   256,
     257,   259,   258,   251,   250,   252,   253,   254,   255,   110,
       0,     0,     0,     0,     0,     0,   247,   344,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   338,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   329,   328,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
       0,   148,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   178,     0,   156,   157,     0,   316,   322,
       0,    40,     0,     0,     0,    53,     0,    31,    32,    33,
      34,    35,   265,   286,   266,   287,   267,   288,   268,   289,
     269,   290,   270,   291,   271,   292,   272,   293,   273,   294,
     285,   306,   274,   295,     0,     0,   276,   297,   277,   298,
     278,   299,   279,   300,   280,   301,   281,   302,     0,     0,
       0,     0,     0,     0,     0,     0,   374,     0,     0,   372,
     373,    80,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,   317,     0,
       0,     0,     0,     0,    23,    21,     0,     0,     0,     0,
     351,     0,     0,   346,   252,   345,   355,   356,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   339,     0,     0,     0,     0,     0,     0,   225,   230,
     228,     0,   236,     0,     0,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,   127,     0,
       0,     0,     0,     0,     0,     0,     0,   218,     0,   180,
       0,     0,     0,     0,     0,   232,   237,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   153,
       0,     0,     0,     0,     0,     0,   319,     0,   315,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   367,     0,     0,     0,   316,    65,
      66,     0,     0,     0,     0,     0,    68,    70,    72,     0,
       0,   363,     0,    78,     0,     0,     0,     0,   264,    22,
       0,     0,     0,     0,     0,   348,     0,     0,    91,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     340,     0,    96,     0,     0,     0,     0,     0,     0,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   223,     0,     0,   190,
     219,     0,     0,     0,   146,     0,     0,   238,     0,   150,
     149,     0,    28,    29,     0,     0,     0,   360,     0,     0,
       0,   170,     0,     0,   160,   321,   159,     0,     0,     0,
       0,   334,     0,   275,   296,   282,   303,   283,   304,   284,
     305,     0,   375,   371,   324,     0,    55,     0,     0,     0,
       0,    63,     0,     0,     0,   361,     0,     0,     0,     0,
      24,    25,     0,     0,    93,     0,   347,     0,     0,     0,
       0,     0,    97,     0,     0,   112,   113,     0,     0,    98,
     122,   341,     0,     0,     0,    89,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,   162,     0,     0,     0,
       0,   134,     0,   200,     0,   202,     0,   204,   336,     0,
       0,     0,     0,   184,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   102,     0,     0,     0,     0,    81,     0,
     323,     0,    36,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,    75,     0,     0,    76,     0,   364,   136,
     137,   138,   139,     0,     0,   352,     0,    92,    99,   100,
     104,     0,     0,   114,     0,     0,   235,   107,     0,     0,
     226,   121,     0,     0,     0,     0,   120,     0,   119,   117,
       0,     0,     0,   333,     0,   332,     0,     0,   191,     0,
       0,   192,     0,     0,   193,     0,     0,     0,     0,     0,
       0,   145,     0,     0,   144,     0,     0,   140,     0,     0,
       0,     0,   358,     0,   172,   171,     0,     0,     0,    41,
       0,     0,     0,   335,     0,     0,     0,   368,    64,    71,
      73,     0,    79,     0,    26,     0,     0,     0,     0,     0,
       0,     0,   108,    95,   106,   116,   124,     0,    85,    86,
     134,     0,   128,     0,     0,     0,     0,     0,     0,   220,
       0,     0,   134,     0,     0,     0,     0,   131,   130,     0,
       0,     0,     0,    82,    83,     0,    37,     0,     0,     0,
      39,    54,     0,   362,     0,   239,   240,   241,   242,   111,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   185,     0,     0,
       0,     0,     0,   357,   173,     0,     0,     0,     0,     0,
      77,     0,     0,     0,   126,     0,   206,     0,     0,   208,
       0,     0,   210,     0,     0,     0,   221,     0,   181,     0,
     134,     0,     0,     0,   103,    84,     0,    45,     0,    51,
       0,     0,    90,   118,   330,   194,     0,     0,   201,   195,
       0,     0,   203,   196,     0,     0,   205,     0,     0,     0,
     187,     0,   143,     0,     0,     0,     0,     0,     0,     0,
       0,   212,     0,   214,     0,   216,   222,   224,   186,   182,
       0,     0,     0,     0,    42,     0,    49,     0,     0,     0,
     197,     0,     0,   198,     0,     0,   199,     0,     0,   147,
       0,   141,     0,    43,     0,     0,   167,     0,     0,     0,
       0,     0,     0,   188,     0,     0,     0,     0,     0,   207,
       0,   209,     0,   211,     0,   142,    44,    46,     0,    47,
       0,     0,     0,     0,     0,     0,    52,   213,   215,   217,
      48,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    63,   676,    64,    65,   413,   991,   997,
     597,   769,  1135,  1272,   598,  1236,  1298,   599,  1274,   600,
     601,   773,   131,   224,    66,   714,  1029,   929,   482,   350,
     351,   352,   353,   319,   290,   291,    69,    70,    71,    72,
      73,    74,   320,   740,  1199,  1250,   557,  1049,  1052,  1055,
    1216,  1220,  1224,  1261,  1264,  1267,   736,   737,   838,   711,
     534,   565,    76,    77,    78,   337,   134,   360,   180,   890,
     891,   346,   339,   525,   208,   667,   802,   458,   459
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1083
static const yytype_int16 yypact[] =
{
    3368,    70,     4,  3447, -1083, -1083,  1630,     2,   -10,   -47,
       6,   131,   194,   203,    72,   130,   144,   -50,   227,   244,
     -43,   253,   254,   296,   305,   347,   358,   359,   226,   344,
     607,   235,   298,   295,   -66,   -66,   323,   141,    48,   407,
     417,   426,    13,    47,   435,   461,   480,   493,   366,   367,
     390,    16,    41, -1083,   401, -1083,   510,   383, -1083,   532,
     539,    18,    19, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
      38,   424,   316, -1083, -1083, -1083,   -46,    84,    85,   343,
     374,   378,   379,   391,   413,   457,   477,   486,   513,   514,
     535,   564,   575,   576,   623,   650,   654,   421,   432,   437,
     452, -1083,   580,   460, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083,  3071,  3071,  3071, -1083, -1083,  3071,  2637,    10,   591,
     385,  3071,   594,   698, -1083,   611,   615,  3071,   649, -1083,
    3071, -1083, -1083, -1083,  3071,  3001,  3071,  3071,   494,  3071,
    3001,  3071,  3071,   527,  3001,  3071,  3071,  2035,   534,   533,
     558,   565,  1769,  1769,  1769,   600, -1083, -1083, -1083, -1083,
     610,   633,   645,   669,   -66,   -66,   -66,  3071,  3071,   -55,
   -1083,   -17,   -66,   552,   606,   614,  2868,   190,   170,   653,
     658,  1769,  2035,   674,    32,   646, -1083,   746, -1083,   642,
     676,   691,   843,  3071,  3071,  3071,   712,  3071,   713,   757,
    3071,  3071, -1083,  3071,   854, -1083,   873, -1083,   874, -1083,
     748,  3071,   899,   765, -1083, -1083, -1083,   924,  3071,  3071,
    3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,
    3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,
    3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,
    3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,
      43,    43,    43,    43,  3071,   933,   559,   827,   827,   827,
    5631,    42,  3001,  4895,   195,   823,   955,   828,   822, -1083,
     824,  3514,  1034, -1083, -1083,  3071,  3071,  3071,  3071,  3071,
    3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,  3071,
   -1083, -1083,  1296,   -35,  2932,  5652,   264,   826,  3001, -1083,
   -1083,  3098, -1083,   -41,  5673,  5694,  3071,  5715,   291,  5736,
    5757,  3071,   485,  5778,  5799,  2168,  1488,  3155,   958, -1083,
    3071,  3071,  3071,  3071, -1083, -1083,   961,   963,   963,  3071,
     837,   839,   840,   842,  3071,  3071,  3071,   844,   220, -1083,
   -1083,  4219,  4245,   -66,   -66,   385,   385,   310,  3071,  3071,
    3071,  2868,  2868,  3071,  3514,   317, -1083,  3071,  3071,  3071,
    3071,   970,   971,  3071,   974, -1083,  3071,  3071,  1040, -1083,
    3001,  3071,  3071, -1083,  5820,  5841,  5862,   888,  4271, -1083,
     841,  3174,  5883,  4918, -1083, -1083,  1232, -1083,  1531,  3071,
    4941,   -13,  3071,     9, -1083,  5904,  4964,  5925,  4987,  5946,
    5010,  5967,  5033,  5988,  5056,  6009,  5079,  6030,  5102,  6051,
    5125,  6072,  5148,  6093,  5171,  6114,  5194,  4297,  4323,  6135,
    5217,  6156,  5240,  6177,  5263,  6198,  5286,  6219,  5309,  6240,
    5332,  4349,  4375,  4401,  4427,  4453,  4479,   655,    55, -1083,
     845,   849,   856,  1356,   852,  3071, -1083,  2035,  2035,   660,
      -2,   316,  3071,   983,   989,    17,   857, -1083,   258,   -45,
     -28,   304, -1083, -1083,  3193,   791,   714,   648,   648,   671,
     671,   671,   671,   242,   242,   827,   827,   827,   827, -1083,
      44,  3001,  3071,   988,  2833,  3071,   827, -1083,  3071,  3001,
    3001,   900,   991,   992,  6261,   993,   905,   995,   996,  6282,
     908,   998,  1000,  3001, -1083,   661,  2301,  3071,  6303,  3268,
    6324,  6345,  3071,  2035,  1005,  1004,  6366,  3128,  3128,  3128,
    3128,  6387,  6408,  6429,   875,   -66,  3071,  3071, -1083, -1083,
     876,   877,  3071,  4505,  4531,  4557,  4193,   -16,   -66,  1807,
    6450,  3549,  6471,  6492,  3071,  1008,  3071,  6513, -1083,  5355,
    5378, -1083,   665,  5401,  5424,  1009,  1010,  1014,   885,  3071,
    1940,  3071,  3071, -1083,    26, -1083, -1083,  5447,    35, -1083,
    3577, -1083,   890,   891,   886, -1083,  1022, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083,  3071,  3071, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,  3071,  3071,
    3071,  3071,  3071,  3071,  3071,  1026, -1083,  3001,    43, -1083,
   -1083, -1083,  3071,  5470,  1025,  1028,   895, -1083,    33,  3071,
    1029,  1031,  1559, -1083,  1035,   907,    16,  1038, -1083,  3001,
    3001,  3001,  3001,  3071, -1083,   920,    43,   178,  4583,   -66,
   -1083,  3001,  3605,  3219,   827, -1083,  3098, -1083,   994,  2035,
    2035,  1039,  2035,   758,  2035,  2035,  1041,   997,  2035,  2035,
     706, -1083,  3001,  1594,  1042,  1044,  1048,  1050,   598, -1083,
   -1083,  1052, -1083,  1054,   912,  6744, -1083,   928,   931,   934,
    1061,  1064,  1065,  1055,   346,  4609,  4635, -1083, -1083,  3633,
     -66,   -66,   -66,  1072,   939,   947,   -19, -1083,   348, -1083,
     -16,  1076,  1089,  1090,  1093,  6744, -1083,  2265,   964,  1098,
    1100,  1057,  1104,  1106,  2035,  2035,  2035,  1109,  4661, -1083,
    3238,   772,  1110,  1111,  1112,  1113, -1083,  1115, -1083,   982,
    3071,  3071,  2035,   981, -1083,  6534,  5493,  6555,  5516,  6576,
    5539,  6597,  5562,  5585, -1083,   184,   990,  6618,    79, -1083,
   -1083,    71,   315,   986,  1119,  2366, -1083, -1083, -1083,    16,
    3071, -1083,   716, -1083,   717,   721,   724,   725,  6744, -1083,
    1121,    56,  3071,    37,   728, -1083,  3071,   999,  1078,  1078,
    2035,  1131,  1001,  1002,  1133,  1135,  2035,  1007,  1139,  1140,
   -1083,   729, -1083,  1158,  2035,  2035,  2035,  1160,  1159, -1083,
    2035,  1161,  1162,  1164,  1165,  2035,  2035,  2035,   181,  3071,
    3071,  3071,  1032,    54,   145,   217, -1083,  2035,  3071, -1083,
   -1083,  2868,   237,  1902, -1083,  1033,  2434, -1083,  3001, -1083,
   -1083,  1036, -1083, -1083,  1169,  1170,  1074, -1083,  3071,  3071,
    3071, -1083,  1172,  1173, -1083,   -13, -1083,  3071,  4687,  4713,
     735, -1083,  3071, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083,  1047, -1083, -1083, -1083,  2035,   316,  3071,  1180,  1175,
      17, -1083,  1182,  5608,    16, -1083,  1183,  1184,  1186,  1187,
   -1083, -1083,    43,  4739, -1083,  1059,  6744,  3071,   -66,  1188,
    1192,  1193, -1083,  3071,  3071, -1083, -1083,  1194,  3071, -1083,
   -1083, -1083,  1196,  1197,  1198,  1114,  3071, -1083,  1200,  2035,
    2035,  2035,  2035,  1201,   872,  1202, -1083,  3128,  3661,  6639,
    3465,   385,   -66,  1203,   -66,  1206,   -66,  1208,   297,  1077,
    6660,  3689,   365, -1083,  1210,  1327,  1212,   -66,  1327,  1213,
     743,  3071, -1083, -1083,  2035,  3493,   561,  6681, -1083,  2700,
   -1083,   193,  6744,  3071,  3071,  2035,  1079,   762,  6744,  1217,
    1219,  1220,  2398, -1083,  1216,  1221, -1083,  1091, -1083, -1083,
   -1083, -1083, -1083,  1222,  3071, -1083,  3717,   222, -1083, -1083,
   -1083,  3745,  3773, -1083,  3801,  1225, -1083, -1083,  1191,  1226,
    6744, -1083,  1229,  1231,  1235,  1241, -1083,  1107, -1083, -1083,
    2499,  1243,  1116, -1083,  3071, -1083,  1108,   382, -1083,  1117,
     474, -1083,  1122,   491, -1083,  1123,  1245,  2035,  1224,  1124,
    3071, -1083,  2567,   499, -1083,   505,   608, -1083,  1246,  3829,
    1163,  3071, -1083,  3071, -1083, -1083,  3001,  2666,  1247, -1083,
    3071,  4765,  4791, -1083,  2035,  3071,  1249, -1083, -1083, -1083,
   -1083,    16, -1083,  1166, -1083,  4817,  1250,  1256,  1260,  1261,
    1262,  1128, -1083, -1083, -1083, -1083, -1083,  2035, -1083, -1083,
     385,  3521, -1083,  2868,   -16,  2868,   -16,  2868,   -16, -1083,
     780,  2035, -1083,  3857,   -66,  3001,   -66, -1083, -1083,  3071,
    3885,  3913,   783, -1083, -1083,  1129,  6744,  3071,  3071,   789,
    6744, -1083,  1265, -1083,  3071, -1083, -1083, -1083, -1083, -1083,
    3071,   793,  1130,  3071, -1083,  3941,   613,   259,  3969,   616,
     376,  3997,   618,   402,  2035,  1267,  1211,  2073,  1146,   621,
     794,   626,  2789, -1083, -1083,  1268,  3071,  6702,  4843,    12,
   -1083,  4869,  4025,  1270, -1083,  4053,  1283,  3071,  1286,  1290,
    3071,  1291,  1297,  3071,  1298,  1167, -1083,  3071, -1083,   -16,
   -1083,  3001,  1299,  2567, -1083, -1083,   799, -1083,  3071, -1083,
    2035,  3071, -1083, -1083, -1083, -1083,  1171,  4081, -1083, -1083,
    1174,  4109, -1083, -1083,  1176,  4137, -1083,  1300,  2811,   412,
    2206,   802, -1083,   638,   803,  1301,  1177,  6723,   807,  4165,
     -16,  1302,   -16,  1305,   -16,  1307, -1083, -1083, -1083, -1083,
     -16,  1308,  3001,  1310, -1083,    43, -1083,  1178,  1317,   414,
   -1083,  1185,   450, -1083,  1199,   484, -1083,  1227,   509, -1083,
     808, -1083,   812, -1083,  1228,  2035, -1083,  1318,   -16,  1319,
     -16,  1321,   -16, -1083,  1322,    43,  1323,    43,   813, -1083,
     517, -1083,   528, -1083,   530, -1083, -1083, -1083,   816, -1083,
    1326,  1328,  1329,  1333,    43,  1357, -1083, -1083, -1083, -1083,
   -1083, -1083
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1083, -1083, -1083, -1083,   522, -1083, -1083, -1083, -1083,   189,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083,  -254,    -3, -1083,  -473, -1083,   547,  1364, -1083,
   -1083, -1083, -1083,    25,  -356,  -185, -1083, -1083, -1083, -1083,
   -1083, -1083,  1368, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083,  -638,  -720, -1083, -1083,
    1027, -1083, -1083, -1083, -1083,    -6, -1083,    98, -1083, -1082,
     544,  -108,    58,  -119,  -647,   463, -1083,  -265,    40
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     133,   374,  1139,   132,     5,   657,   460,   461,   462,   550,
     551,   388,   139,   591,   284,   136,   860,   194,  1209,   801,
     206,   665,   148,   216,   218,  1151,   323,   148,    68,   153,
     472,   328,   406,   762,   408,   332,   384,   792,   385,   457,
     226,   137,   220,   924,   153,   209,   135,   457,   226,   467,
     674,   197,   188,   198,   733,   347,   348,   733,   175,   176,
     734,   735,   921,   734,   735,   717,   718,   719,   177,   363,
     364,   107,   108,   109,   110,   178,     4,   111,   657,   107,
     108,   109,   110,   381,   149,   111,   365,   138,   228,   149,
     229,   150,   592,   593,   594,   595,   670,   189,   154,   510,
     500,   511,   862,   285,   286,   501,   190,   363,   364,   117,
     118,   119,   120,   671,   195,   277,   278,   279,   124,   125,
     280,   283,   227,   859,   366,   292,   793,   794,  1238,   124,
     125,   312,   179,   181,   314,   187,   658,   141,   315,   321,
     324,   325,   860,   327,   321,   329,   330,   140,   321,   333,
     334,   596,   912,  1210,   196,   289,   468,   207,   666,   217,
     219,   363,   364,   469,   763,   675,   124,   125,   386,   124,
     125,   361,   362,   765,   221,   210,   222,   675,   363,   364,
     362,   223,   117,   118,   119,   120,   183,   956,   957,   184,
     646,   559,   185,  1288,   962,   647,   963,   394,   395,   396,
     142,   398,   471,   322,   401,   402,   144,   403,   322,   143,
     124,   125,   322,   145,   580,   410,   659,   765,   230,   232,
     231,   233,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   146,   175,   176,  1008,   463,   363,
     364,   572,   358,   359,   162,   177,   321,   163,   147,   164,
     367,   473,   186,   170,   375,   964,   171,   965,   172,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   377,   508,   117,   118,   119,   120,
     733,   378,   506,   811,   363,   364,   734,   735,   510,   902,
     514,   226,   906,   767,   510,   519,   124,   125,  1079,   506,
     321,   376,   733,  1080,   528,   529,   530,   531,   734,   735,
     322,   363,   364,   536,   363,   364,   363,   364,   541,   542,
     543,   157,   107,   108,   109,   110,   158,   966,   111,   967,
     545,   151,   553,   554,   555,   277,   278,   556,   306,   307,
     308,   560,   561,   562,   563,   309,   507,   567,   152,   973,
     569,   570,   677,   786,   321,   573,   574,   155,   156,   288,
     289,   289,   144,   507,   322,   124,   125,   165,   159,   669,
     504,  1188,   222,   587,   700,   130,   590,   223,   589,   160,
     161,   810,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   526,   307,   308,   117,   118,   119,   120,
     309,   510,   173,   516,   363,   364,   174,   860,   156,  1056,
     860,   363,   364,   860,  1142,   672,   124,   125,   322,   733,
     552,    33,    34,    35,    36,   734,   735,   558,   191,   653,
      41,   548,   549,    44,   182,   200,   662,   660,   192,   359,
     363,   364,   363,   364,   193,   733,  1157,   234,  1160,   235,
    1163,   734,   735,   199,   201,   733,   849,   733,   861,   363,
     364,   734,   735,   734,   735,   321,   678,   202,   653,   682,
     203,   204,   683,   684,   686,  1060,   363,   364,   236,   860,
     237,   661,   238,   240,   239,   241,   212,   321,  1191,   213,
     684,   703,  1113,   733,   205,   242,   708,   243,   785,   734,
     735,   715,   715,   715,   715,   211,   214,   905,   907,   860,
     725,   726,   860,   215,  1194,   860,   729,   244,   860,   245,
     804,   805,   806,   807,  1248,   270,  1277,   733,   745,   322,
     747,  1229,   814,   734,   735,   225,   271,   685,   687,  1073,
     860,   272,   860,   758,   860,   760,   761,   716,   716,   716,
     716,   322,   733,   831,   685,   766,   273,   274,   734,   735,
     733,   246,  1279,   247,   275,   287,   734,   735,   363,   364,
     293,   733,  1259,   733,  1262,  1046,  1265,   734,   735,   734,
     735,   248,  1268,   249,  1115,   363,   364,   310,   775,   776,
     250,   311,   251,   363,   364,   510,  1281,   520,   326,   363,
     364,  1117,   777,   778,   779,   780,   781,   782,   783,  1124,
    1290,   321,  1292,   724,  1294,  1125,   787,   252,   254,   253,
     255,  1283,   166,   795,   313,   167,   738,  1013,   168,  1301,
     169,   331,   837,   321,   321,   321,   321,   808,   340,   256,
    1302,   257,  1303,   357,   341,   321,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     124,   125,   342,   368,   309,   465,   321,   222,   258,   343,
     259,   338,   223,  1074,   294,   322,   345,   345,   345,   260,
     262,   261,   263,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   322,   322,   322,
     322,   309,   363,   364,   349,   345,   382,   363,   364,   322,
     363,   364,   363,   364,   354,   363,   364,   369,  1126,   980,
     363,   364,   389,  1187,  1152,   370,  1190,   264,  1193,   265,
     322,  1201,   363,   364,   888,   889,  1203,   355,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   813,  1252,   356,
     880,   309,   387,   390,   266,   766,   267,   379,   268,   908,
     269,   644,   380,   645,   913,   304,   305,   306,   307,   308,
     510,   510,   656,   701,   309,   510,   923,   751,   383,   822,
     926,   823,   391,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   392,   853,   854,
     855,   309,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   958,   959,   960,   510,   309,   830,   393,
     397,   968,   970,   400,   399,   971,   914,   510,   915,   916,
     404,   510,   321,   917,   510,   510,   918,   919,   510,   510,
     925,   941,   985,   986,   987,   995,  1037,   996,  1038,   405,
     407,   992,   990,   510,   409,  1068,   998,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,  1002,  1085,   411,  1086,   309,   412,   881,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
    1164,  1016,  1165,   510,   309,  1175,   322,  1021,  1022,   995,
     414,  1179,  1024,   995,   510,  1183,  1202,  1167,   464,  1085,
    1030,  1235,   510,   510,  1251,  1253,  1001,   995,   510,  1257,
    1284,  1040,  1285,   995,  1286,  1300,  1304,  1132,  1305,   972,
     309,   474,   475,   130,   476,   527,   477,   505,   532,   321,
     533,   537,   321,   538,   539,  1069,   540,   564,   566,   544,
     568,   578,   581,  1077,   649,   648,   289,  1081,  1082,   663,
    1273,   650,   652,   664,   668,   679,   688,  1041,   689,   690,
     692,   693,   694,   695,   697,   698,  1170,   699,  1095,   710,
     712,   654,   655,   723,   746,  1230,   754,   755,   727,   728,
    1296,   756,  1299,   757,   770,   771,  1017,   772,   774,  1078,
     784,   789,   791,   322,   790,   796,   322,   797,  1111,  1310,
     483,   809,   799,   800,   803,   817,   820,   841,   826,   833,
     827,   834,     7,     8,  1123,   835,   506,   836,   839,   848,
    1047,   840,  1050,   842,  1053,  1130,   843,  1131,   845,   844,
     321,   846,   847,  1063,  1136,  1065,  1066,   709,   856,  1140,
     857,   858,  1231,   863,  1234,   478,    15,    16,   479,    18,
      19,   480,    21,   481,    23,   864,    24,   865,    26,    27,
     866,    29,    30,    31,   869,   868,   870,  1155,   871,  1158,
     872,  1161,   873,   877,   882,   883,   887,   885,   884,   321,
     507,   886,   892,  1172,   909,   903,   910,   920,    48,    49,
      50,  1177,  1178,  1270,   322,   289,   928,   932,  1181,   935,
     927,   936,   933,   934,  1182,   939,   940,  1185,   938,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   942,   946,   947,   984,   309,   949,   950,
     998,   951,   952,   961,   977,   982,   983,   981,   988,  1004,
     989,  1217,   571,   322,  1221,   999,  1003,  1225,  1006,  1009,
    1010,  1228,  1011,  1012,  1018,   321,  1015,   321,  1019,  1020,
    1023,  1025,  1237,  1026,  1027,  1239,  1031,  1036,  1039,  1048,
    1028,  1156,  1051,  1159,  1054,  1162,  1061,  1057,  1064,  1067,
    1084,  1087,  1169,  1091,  1171,  1088,  1089,  1092,  1094,  1093,
    1100,  1121,  1102,   818,   819,  1103,   821,  1104,   824,   825,
    1101,  1105,   828,   829,     7,     8,   321,  1106,  1107,  1109,
    1112,  1119,  1127,  1134,  1129,  1141,  1145,  1110,  1114,   322,
    1143,   322,  1146,  1116,  1118,  1122,  1147,  1148,  1149,  1150,
    1176,  1180,  1184,  1196,  1205,  1197,  1213,   478,    15,    16,
     479,    18,    19,   480,    21,   481,    23,  1200,    24,  1215,
      26,    27,  1218,    29,    30,    31,  1219,  1222,   874,   875,
     876,  1233,   499,  1223,  1226,  1232,  1246,  1254,  1260,  1227,
     322,  1263,  1240,  1266,  1269,  1242,  1271,  1244,  1255,  1275,
      48,    49,    50,  1276,  1289,  1291,  1278,  1293,  1295,  1297,
      79,   316,  1306,   922,  1307,  1308,    83,    84,    85,  1309,
    1280,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   651,  1311,   931,  1206,   930,    67,  1282,  1287,
     937,    75,   317,  1005,   585,   535,     0,     0,   943,   944,
     945,     0,     0,     0,   948,     0,     0,     0,     0,   953,
     954,   955,     0,    33,    34,    35,    36,    37,     0,     0,
       0,   969,    41,     0,     0,    44,     0,   976,     0,     0,
     979,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,     0,     0,     0,     0,   309,
       0,     0,     0,     0,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1000,
       0,   371,  1062,     0,     0,     0,   123,     0,     0,     0,
       0,   373,     0,     0,     0,     0,   129,     0,   178,   524,
       0,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,     0,     0,     0,     0,   309,
       0,    79,   316,  1032,  1033,  1034,  1035,    83,    84,    85,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,     0,     0,  1070,     0,
       0,     0,     0,   317,     0,     0,     0,     0,     0,  1083,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    34,    35,    36,    37,     0,
       0,     0,     0,    41,     0,   798,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   478,    15,    16,   479,
      18,    19,   480,    21,   481,    23,     0,    24,     0,    26,
      27,     0,    29,    30,    31,   113,   114,   115,   116,     0,
     832,  1120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,   318,     0,     0,     0,   123,     0,    48,
      49,    50,   126,     0,     0,     0,     0,   129,     0,     0,
     524,     0,     0,    79,    80,    81,     0,    82,     0,    83,
      84,    85,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,  1166,   107,   108,   109,   110,
       0,     0,   111,   586,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1195,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,     0,     0,     0,     0,   309,     0,     0,
       0,   112,     0,     0,     0,     0,     0,   113,   114,   115,
     116,   117,   118,   119,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   122,     0,     0,     0,   123,
       0,   124,   125,     0,   126,     0,   127,     0,   128,   129,
       0,   130,    79,   316,   344,     0,     0,     0,    83,    84,
      85,     0,     0,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   317,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,     0,     0,     0,    41,     0,     0,    44,     0,     0,
       0,     0,   478,    15,    16,   479,    18,    19,   480,    21,
     481,    23,     0,    24,     0,    26,    27,     0,    29,    30,
      31,     0,     0,     0,     0,     0,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,   335,    48,    49,    50,   123,     0,
       0,     0,     0,   126,     0,    79,   316,   974,   129,     0,
     336,    83,    84,    85,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   317,     0,   739,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,    34,
      35,    36,    37,     0,     0,     0,     0,    41,     0,     0,
      44,     0,     0,     0,     0,   478,    15,    16,   479,    18,
      19,   480,    21,   481,    23,     0,    24,     0,    26,    27,
       0,    29,    30,    31,     0,     0,     0,     0,     0,   113,
     114,   115,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,   335,    48,    49,
      50,   123,     0,     0,     0,     0,   126,     0,    79,   316,
       0,   129,     0,   975,    83,    84,    85,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     317,     0,   759,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,     0,     0,     0,     0,
      41,     0,     0,    44,     0,     0,     0,     0,   478,    15,
      16,   479,    18,    19,   480,    21,   481,    23,     0,    24,
       0,    26,    27,     0,    29,    30,    31,     0,     0,     0,
       0,     0,   113,   114,   115,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
     335,    48,    49,    50,   123,     0,     0,     0,     0,   126,
       0,    79,   316,     0,   129,     0,   336,    83,    84,    85,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   317,     0,  1198,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    34,    35,    36,    37,     0,
       0,     0,     0,    41,     0,     0,    44,     0,     0,     0,
       0,   478,    15,    16,   479,    18,    19,   480,    21,   481,
      23,     0,    24,     0,    26,    27,     0,    29,    30,    31,
       0,   867,     0,     0,     0,   113,   114,   115,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,   318,    48,    49,    50,   123,     0,     0,
       0,     0,   126,     0,    79,   316,     0,   129,     0,   523,
      83,    84,    85,     0,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   317,     0,  1249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,   911,     0,     0,     0,    41,     0,     0,    44,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,  1090,     0,     0,     0,   113,   114,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   318,     0,     0,     0,
     123,     0,     0,     0,     0,   126,     0,    79,   316,     0,
     129,     0,   702,    83,    84,    85,     0,     0,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   317,
       0,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,     0,     0,     0,     0,   309,
      33,    34,    35,    36,    37,  1108,     0,     0,     0,    41,
       0,     0,    44,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,     0,     0,     0,
       0,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,   114,   115,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,   335,
       0,     0,     0,   123,     0,     0,     0,     0,   126,     0,
      79,   316,     0,   129,     0,   978,    83,    84,    85,     0,
       0,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   317,     0,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,    33,    34,    35,    36,    37,     0,     0,
      79,   276,    41,     0,     0,    44,    83,    84,    85,     0,
       0,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,  1133,     0,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   371,  1062,     0,     0,     0,   123,     0,     0,     0,
       0,   373,     0,    79,   276,   226,   129,     0,   178,    83,
      84,    85,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   107,   108,   109,   110,
       0,     0,   111,     0,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,   122,     0,     0,     0,   123,     0,     0,     0,
       0,   126,     0,     0,   281,     0,   129,     0,   282,     0,
       0,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,  1204,     0,     0,     0,   309,
       0,     0,     0,     0,     0,     0,     0,   113,   114,   115,
     116,     0,     0,     0,     0,     0,     0,  1247,     0,     0,
       0,     0,     0,     0,   121,   122,     0,     0,     0,   123,
       0,     0,     0,     0,   126,     0,    79,   276,     0,   129,
       0,  1076,    83,    84,    85,     0,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,    79,   276,     0,     0,     0,     0,    83,    84,    85,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     113,   114,   115,   116,   309,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,   122,     0,
       0,     0,   123,     0,     0,     0,     0,   126,     0,     0,
     680,     0,   129,     0,   681,   113,   114,   115,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   371,   372,     0,     0,     0,   123,     0,     0,
       0,     0,   373,     0,    79,   316,     0,   129,     0,   178,
      83,    84,    85,     0,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   317,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,     0,     0,     0,     0,   309,     0,    33,    34,    35,
      36,    37,   502,     0,    79,   276,    41,     0,     0,    44,
      83,    84,    85,     0,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   508,     0,   113,   114,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   318,     0,     0,     0,
     123,    79,   276,   226,     0,   126,     0,    83,    84,    85,
     129,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   508,   107,   108,   109,   110,     0,     0,
     111,     0,     0,     0,     0,     0,     0,     0,   113,   114,
     115,   116,   582,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   122,     0,     0,     0,
     123,   673,     0,     0,     0,   126,     0,     0,     0,     0,
     129,     0,     0,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   509,   307,   308,   816,     0,     0,
       0,   309,     0,     0,     0,   113,   114,   115,   116,     0,
       0,     0,     0,     0,     0,     0,   879,     0,     0,     0,
       0,     0,   121,   122,     0,     0,     0,   123,     0,     0,
       0,     0,   126,     0,     0,     0,     0,   129,     0,     0,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   526,   307,   308,     0,     0,     0,     0,   309,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,     0,     0,     0,     0,   309,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,     0,    -4,     1,
       0,   309,    -4,     0,     0,     0,     0,     0,     0,     0,
      -4,    -4,     0,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,     0,     0,     0,
       0,   309,     0,    -4,     0,     0,     0,     0,    -4,    -4,
     705,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,
      -4,     6,     0,     0,     0,    -4,    -4,    -4,    -4,     7,
       8,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     0,     0,     0,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,     0,
      39,    40,    41,    42,    43,    44,     7,     8,    45,    46,
       0,     0,     0,     0,    47,    48,    49,    50,     0,     0,
      51,     0,    52,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,     0,     0,     0,     0,   478,
      15,    16,   479,    18,    19,   480,    21,   481,    23,     0,
      24,     0,    26,    27,     0,    29,    30,    31,     0,     0,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,    48,    49,    50,  1044,     0,  1045,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,  1071,     0,  1072,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,  1153,     0,  1154,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,   742,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,     0,     0,   768,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,     0,     0,   815,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,     0,   852,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,     0,     0,  1042,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,  1059,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,     0,     0,  1096,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,     0,     0,  1097,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,     0,  1098,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,     0,     0,  1099,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,  1128,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,     0,     0,  1168,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,     0,     0,  1173,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,     0,  1174,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,     0,     0,  1186,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,  1189,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,     0,     0,  1192,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,     0,     0,  1212,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,     0,  1214,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,     0,     0,  1241,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,  1243,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,     0,     0,  1245,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,     0,     0,  1258,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,   466,     0,
       0,     0,     0,   546,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,   546,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,   547,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,   579,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,   624,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,   625,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,   638,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,   639,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,   640,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,   641,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,   642,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,   643,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,   730,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,   731,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,   732,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,   812,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,   850,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,   851,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,   878,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,   993,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,   994,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,  1014,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,  1137,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,  1138,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,  1144,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,  1208,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,  1211,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,   470,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,     0,     0,     0,
       0,   309,     0,     0,     0,   584,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,     0,     0,   588,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,     0,     0,     0,     0,   309,     0,     0,
       0,   603,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,     0,     0,   605,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,     0,
       0,     0,     0,   309,     0,     0,     0,   607,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,     0,     0,
     609,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,     0,     0,     0,     0,   309,
       0,     0,     0,   611,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,   613,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,     0,     0,     0,     0,   309,     0,     0,     0,   615,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,   617,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,     0,     0,     0,
       0,   309,     0,     0,     0,   619,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,     0,     0,   621,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,     0,     0,     0,     0,   309,     0,     0,
       0,   623,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,     0,     0,   627,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,     0,
       0,     0,     0,   309,     0,     0,     0,   629,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,     0,     0,
     631,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,     0,     0,     0,     0,   309,
       0,     0,     0,   633,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,   635,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,     0,     0,     0,     0,   309,     0,     0,     0,   637,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,   749,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,     0,     0,     0,
       0,   309,     0,     0,     0,   750,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,     0,     0,   752,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,     0,     0,     0,     0,   309,     0,     0,
       0,   753,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,     0,     0,   764,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,     0,
       0,     0,     0,   309,     0,     0,     0,   788,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,     0,     0,
     894,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,     0,     0,     0,     0,   309,
       0,     0,     0,   896,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,     0,     0,   898,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,     0,     0,     0,     0,   309,     0,     0,     0,   900,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
       0,     0,   901,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,     0,     0,     0,
       0,   309,     0,     0,     0,  1007,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,   466,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,     0,     0,     0,     0,   309,     0,   503,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,   512,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,     0,     0,     0,     0,   309,     0,   513,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
     515,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,     0,     0,     0,     0,   309,
       0,   517,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,   518,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,     0,     0,     0,
       0,   309,     0,   521,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,   522,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,     0,
       0,     0,     0,   309,     0,   575,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,   576,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,     0,     0,     0,     0,   309,     0,   577,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,   583,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,     0,     0,     0,     0,   309,     0,   602,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
     604,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,     0,     0,     0,     0,   309,
       0,   606,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,   608,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,     0,     0,     0,
       0,   309,     0,   610,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,   612,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,     0,
       0,     0,     0,   309,     0,   614,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,   616,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,     0,     0,     0,     0,   309,     0,   618,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,   620,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,     0,     0,     0,     0,   309,     0,   622,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
     626,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,     0,     0,     0,     0,   309,
       0,   628,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,   630,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,     0,     0,     0,
       0,   309,     0,   632,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,   634,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,     0,
       0,     0,     0,   309,     0,   636,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,   691,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,     0,     0,     0,     0,   309,     0,   696,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,   704,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,     0,     0,     0,     0,   309,     0,   706,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
     707,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,     0,     0,     0,     0,   309,
       0,   713,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,   720,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,     0,     0,     0,
       0,   309,     0,   721,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,   722,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,     0,
       0,     0,     0,   309,     0,   741,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,   743,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,     0,     0,     0,     0,   309,     0,   744,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,   748,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,     0,     0,     0,     0,   309,     0,   893,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,     0,     0,     0,   309,     0,
     895,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,     0,     0,     0,     0,   309,
       0,   897,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,     0,     0,     0,
     309,     0,   899,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,     0,     0,     0,
       0,   309,     0,   904,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,     0,
       0,     0,   309,     0,  1043,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,     0,
       0,     0,     0,   309,     0,  1058,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,     0,     0,     0,   309,     0,  1075,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,     0,     0,     0,     0,   309,     0,  1207,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,     0,     0,     0,   309,     0,  1256,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,     0,     0,     0,     0,   309
};

static const yytype_int16 yycheck[] =
{
       6,   186,  1084,     6,     0,     7,   271,   272,   273,   365,
     366,   196,     6,     4,     4,    13,   736,     4,     6,   666,
       4,     4,    72,     5,     5,  1107,   145,    72,     3,    72,
     284,   150,   217,     7,   219,   154,     4,     4,     6,     4,
       5,    51,     4,     6,    72,     4,     6,     4,     5,     7,
       6,     4,     4,     6,    73,   163,   164,    73,   124,   125,
      79,    80,     6,    79,    80,   538,   539,   540,   134,   124,
     125,    36,    37,    38,    39,   141,     6,    42,     7,    36,
      37,    38,    39,   191,   134,    42,   141,   134,   134,   134,
     136,   141,    83,    84,    85,    86,   141,    49,   141,   140,
     135,   142,   740,    93,    94,   140,    58,   124,   125,   111,
     112,   113,   114,   141,   101,   121,   122,   123,   131,   132,
     126,   127,    82,   142,   141,   131,    93,    94,  1210,   131,
     132,   137,    34,    35,   140,    37,   138,     6,   144,   145,
     146,   147,   862,   149,   150,   151,   152,   141,   154,   155,
     156,   142,   799,   141,   141,   130,   114,   141,   141,   141,
     141,   124,   125,   282,   138,   121,   131,   132,   136,   131,
     132,   177,   178,   138,   136,   134,   138,   121,   124,   125,
     186,   143,   111,   112,   113,   114,    45,     6,     7,    48,
     135,   376,    51,  1275,   140,   140,   142,   203,   204,   205,
       6,   207,     7,   145,   210,   211,   134,   213,   150,     6,
     131,   132,   154,   141,   399,   221,   470,   138,   134,   134,
     136,   136,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   134,   124,   125,   914,   274,   124,
     125,   390,   174,   175,    48,   134,   282,    51,   134,    53,
     182,   284,   141,    48,   186,   140,    51,   142,    53,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   134,     8,   111,   112,   113,   114,
      73,   141,   318,   135,   124,   125,    79,    80,   140,   135,
     326,     5,     7,   588,   140,   331,   131,   132,   135,   335,
     336,   141,    73,   140,   340,   341,   342,   343,    79,    80,
     282,   124,   125,   349,   124,   125,   124,   125,   354,   355,
     356,    55,    36,    37,    38,    39,    51,   140,    42,   142,
     140,   134,   368,   369,   370,   371,   372,   373,   126,   127,
     128,   377,   378,   379,   380,   133,   318,   383,   134,   142,
     386,   387,   501,   648,   390,   391,   392,   134,   134,     4,
     365,   366,   134,   335,   336,   131,   132,    53,    51,   141,
     136,   142,   138,   409,   523,   141,   412,   143,   411,    51,
      51,   676,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   111,   112,   113,   114,
     133,   140,   134,   142,   124,   125,   141,  1157,   134,   142,
    1160,   124,   125,  1163,  1091,   141,   131,   132,   390,    73,
     140,    66,    67,    68,    69,    79,    80,   140,    51,   465,
      75,   363,   364,    78,   141,     4,   472,   470,    51,   371,
     124,   125,   124,   125,    48,    73,  1114,   134,  1116,   136,
    1118,    79,    80,    48,     4,    73,   140,    73,   140,   124,
     125,    79,    80,    79,    80,   501,   502,     4,   504,   505,
     134,   134,   508,   509,   510,   140,   124,   125,   134,  1229,
     136,   471,   134,   134,   136,   136,     6,   523,   142,   136,
     526,   527,   140,    73,   134,   134,   532,   136,   647,    79,
      80,   537,   538,   539,   540,   134,     4,   791,   792,  1259,
     546,   547,  1262,     4,   142,  1265,   552,   134,  1268,   136,
     669,   670,   671,   672,   142,   134,   142,    73,   564,   501,
     566,  1199,   681,    79,    80,   141,   134,   509,   510,     8,
    1290,   134,  1292,   579,  1294,   581,   582,   537,   538,   539,
     540,   523,    73,   702,   526,   588,   134,     7,    79,    80,
      73,   134,   142,   136,   134,     4,    79,    80,   124,   125,
       6,    73,  1240,    73,  1242,   961,  1244,    79,    80,    79,
      80,   134,  1250,   136,   140,   124,   125,     6,   624,   625,
     134,     6,   136,   124,   125,   140,   142,   142,   134,   124,
     125,   140,   638,   639,   640,   641,   642,   643,   644,   140,
    1278,   647,  1280,   545,  1282,   140,   652,   134,   134,   136,
     136,   142,    45,   659,     5,    48,   558,   922,    51,   142,
      53,   134,    64,   669,   670,   671,   672,   673,   134,   134,
     142,   136,   142,     4,   141,   681,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     131,   132,   134,   141,   133,   136,   702,   138,   134,   134,
     136,   157,   143,   142,     6,   647,   162,   163,   164,   134,
     134,   136,   136,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   669,   670,   671,
     672,   133,   124,   125,   134,   191,   192,   124,   125,   681,
     124,   125,   124,   125,   134,   124,   125,   141,   140,   868,
     124,   125,     6,   140,  1110,   141,   140,   134,   140,   136,
     702,   140,   124,   125,   770,   771,   140,   134,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   679,   140,   134,
       8,   133,   136,   141,   134,   788,   136,   134,   134,   792,
     136,   136,   134,   138,   800,   124,   125,   126,   127,   128,
     140,   140,   142,   142,   133,   140,   812,   142,   134,    51,
     816,    53,   136,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   136,   730,   731,
     732,   133,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   849,   850,   851,   140,   133,   142,     6,
     138,   857,   858,    96,   141,   861,   140,   140,   142,   142,
       6,   140,   868,   142,   140,   140,   142,   142,   140,   140,
     142,   142,   878,   879,   880,   140,     4,   142,     6,     6,
       6,   887,   885,   140,   136,   142,   892,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   907,   140,     4,   142,   133,   141,   135,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     140,   927,   142,   140,   133,   142,   868,   933,   934,   140,
       6,   142,   938,   140,   140,   142,   142,  1122,     5,   140,
     946,   142,   140,   140,   142,   142,   906,   140,   140,   142,
     142,   957,   140,   140,   142,   142,   140,  1076,   142,   861,
     133,   138,     7,   141,   136,     7,   142,   141,     7,   975,
       7,   134,   978,   134,   134,   981,   134,     7,     7,   135,
       6,    93,   141,   989,   135,   140,   961,   993,   994,     6,
    1255,   135,   140,     4,   137,     7,    96,   957,     7,     7,
       7,    96,     7,     7,    96,     7,  1125,     7,  1014,     4,
       6,   467,   468,   138,     6,  1200,     7,     7,   142,   142,
    1285,     7,  1287,   138,   134,   134,   928,   141,     6,   989,
       4,     6,   137,   975,     6,     6,   978,     6,  1044,  1304,
       6,   121,     7,   136,     6,    51,     7,   135,     7,     7,
      53,     7,    12,    13,  1060,     7,  1062,     7,     6,     4,
     962,     7,   964,   135,   966,  1071,   135,  1073,     7,   135,
    1076,     7,     7,   975,  1080,   977,   978,   533,     6,  1085,
     141,   134,  1201,     7,  1203,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     6,    56,     7,    58,    59,
       7,    61,    62,    63,     6,   141,     6,  1113,    51,  1115,
       6,  1117,     6,     4,     4,     4,   134,     4,     6,  1125,
    1062,     6,   141,  1129,   138,   135,     7,     6,    88,    89,
      90,  1137,  1138,  1252,  1076,  1110,    58,     6,  1144,     6,
     141,     6,   141,   141,  1150,     6,     6,  1153,   141,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,     5,     4,     6,    92,   133,     7,     7,
    1176,     7,     7,   141,   141,     6,     6,   141,     6,     4,
       7,  1187,   142,  1125,  1190,   138,     6,  1193,     6,     6,
       6,  1197,     6,     6,     6,  1201,   137,  1203,     6,     6,
       6,     5,  1208,     6,     6,  1211,     6,     6,     6,     6,
      96,  1113,     6,  1115,     6,  1117,     6,   140,     6,     6,
     141,     4,  1124,     7,  1126,     6,     6,     6,     6,   138,
       5,     7,     6,   689,   690,     6,   692,     6,   694,   695,
      49,     6,   698,   699,    12,    13,  1252,     6,   141,     6,
     142,     6,     6,     6,    91,     6,     6,   141,   141,  1201,
      94,  1203,     6,   141,   141,   141,     6,     6,     6,   141,
     141,     6,   142,     6,     6,    64,     6,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,   141,    56,     6,
      58,    59,     6,    61,    62,    63,     6,     6,   754,   755,
     756,  1203,     6,     6,     6,     6,     6,     6,     6,   142,
    1252,     6,   141,     6,     6,   141,     6,   141,   141,   141,
      88,    89,    90,     6,     6,     6,   141,     6,     6,     6,
       3,     4,     6,   811,     6,     6,     9,    10,    11,     6,
     141,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     6,     6,   820,  1176,   819,     3,   141,   141,
     826,     3,    45,   910,   142,   348,    -1,    -1,   834,   835,
     836,    -1,    -1,    -1,   840,    -1,    -1,    -1,    -1,   845,
     846,   847,    -1,    66,    67,    68,    69,    70,    -1,    -1,
      -1,   857,    75,    -1,    -1,    78,    -1,   863,    -1,    -1,
     866,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,    -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   905,
      -1,   124,   125,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,   134,    -1,    -1,    -1,    -1,   139,    -1,   141,   142,
      -1,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,     3,     4,   949,   950,   951,   952,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,   984,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,   995,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    75,    -1,     6,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    -1,    58,
      59,    -1,    61,    62,    63,   107,   108,   109,   110,    -1,
       6,  1057,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,    -1,    -1,    -1,   129,    -1,    88,
      89,    90,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     142,    -1,    -1,     3,     4,     5,    -1,     7,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,  1121,    36,    37,    38,    39,
      -1,    -1,    42,   142,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1164,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,   129,
      -1,   131,   132,    -1,   134,    -1,   136,    -1,   138,   139,
      -1,   141,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    -1,    58,    59,    -1,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,    88,    89,    90,   129,    -1,
      -1,    -1,    -1,   134,    -1,     3,     4,     5,   139,    -1,
     141,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,   142,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,    88,    89,
      90,   129,    -1,    -1,    -1,    -1,   134,    -1,     3,     4,
      -1,   139,    -1,   141,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,   142,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      -1,    58,    59,    -1,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,    88,    89,    90,   129,    -1,    -1,    -1,    -1,   134,
      -1,     3,     4,    -1,   139,    -1,   141,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,   142,    -1,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    -1,    58,    59,    -1,    61,    62,    63,
      -1,     6,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,    88,    89,    90,   129,    -1,    -1,
      -1,    -1,   134,    -1,     3,     4,    -1,   139,    -1,   141,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,     6,    -1,    -1,    -1,    75,    -1,    -1,    78,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,   107,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,   134,    -1,     3,     4,    -1,
     139,    -1,   141,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      66,    67,    68,    69,    70,     6,    -1,    -1,    -1,    75,
      -1,    -1,    78,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,   134,    -1,
       3,     4,    -1,   139,    -1,   141,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    66,    67,    68,    69,    70,    -1,    -1,
       3,     4,    75,    -1,    -1,    78,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     6,    -1,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,   134,    -1,     3,     4,     5,   139,    -1,   141,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    -1,    42,    -1,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,   134,    -1,    -1,   137,    -1,   139,    -1,   141,    -1,
      -1,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,     6,    -1,    -1,    -1,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,   134,    -1,     3,     4,    -1,   139,
      -1,   141,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     107,   108,   109,   110,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,   134,    -1,    -1,
     137,    -1,   139,    -1,   141,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,   134,    -1,     3,     4,    -1,   139,    -1,   141,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,   133,    -1,    66,    67,    68,
      69,    70,   140,    -1,     3,     4,    75,    -1,    -1,    78,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     8,    -1,   107,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,
     129,     3,     4,     5,    -1,   134,    -1,     9,    10,    11,
     139,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     8,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,   110,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,
     129,     8,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,     8,    -1,    -1,
      -1,   133,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,   124,   125,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,     0,     1,
      -1,   133,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,    35,    -1,    -1,    -1,    -1,    40,    41,
     142,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    73,    74,    75,    76,    77,    78,    -1,    -1,    81,
      82,     4,    -1,    -1,    -1,    87,    88,    89,    90,    12,
      13,    93,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    40,    41,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    69,    70,    71,    -1,
      73,    74,    75,    76,    77,    78,    12,    13,    81,    82,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    -1,    -1,
      93,    -1,    95,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    -1,    58,    59,    -1,    61,    62,    63,    -1,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    88,    89,    90,   140,    -1,   142,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,   140,    -1,   142,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,   140,    -1,   142,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,   135,    -1,
      -1,    -1,    -1,   140,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,   140,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,   140,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,   140,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,   140,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,   140,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,   140,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,   140,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,   140,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,   140,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,   140,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,   137,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,   137,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,   137,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,   137,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,   137,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,    -1,   133,    -1,    -1,    -1,   137,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
     137,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,    -1,    -1,   137,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,   137,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,   137,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,   137,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,   137,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,   137,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,   137,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,   137,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,    -1,   133,    -1,    -1,    -1,   137,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
     137,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,    -1,    -1,   137,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,   137,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,   137,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,   137,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,   137,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,   137,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,   137,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,   137,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,    -1,   133,    -1,    -1,    -1,   137,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
     137,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,    -1,    -1,   137,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,   137,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,   137,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,   137,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,   137,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,   135,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,   133,    -1,   135,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,   135,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,   135,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
     135,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,   135,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,   135,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,   135,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,   135,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,    -1,   133,    -1,   135,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,   135,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,   133,    -1,   135,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,   135,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,   135,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
     135,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,   135,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,   135,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,   135,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,   135,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,    -1,   133,    -1,   135,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,   135,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,   133,    -1,   135,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,   135,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,   135,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
     135,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,   135,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,   135,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,   135,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,   135,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,    -1,   133,    -1,   135,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,   135,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,   133,    -1,   135,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,   135,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,   135,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
     135,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,   135,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,   135,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,   135,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,   135,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,    -1,   133,    -1,   135,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,   135,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,   133,    -1,   135,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,   135,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,   135,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
     135,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,   135,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,   135,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,   135,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,   135,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,    -1,   133,    -1,   135,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,   135,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,   133,    -1,   135,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,   135,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   145,   146,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    56,    57,    58,    59,    60,    61,
      62,    63,    65,    66,    67,    68,    69,    70,    71,    73,
      74,    75,    76,    77,    78,    81,    82,    87,    88,    89,
      90,    93,    95,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   147,   149,   150,   168,   172,   177,   180,
     181,   182,   183,   184,   185,   186,   206,   207,   208,     3,
       4,     5,     7,     9,    10,    11,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    36,    37,    38,
      39,    42,   101,   107,   108,   109,   110,   111,   112,   113,
     114,   124,   125,   129,   131,   132,   134,   136,   138,   139,
     141,   166,   167,   209,   210,   222,    13,    51,   134,     6,
     141,     6,     6,     6,   134,   141,   134,   134,    72,   134,
     141,   134,   134,    72,   141,   134,   134,    55,    51,    51,
      51,    51,    48,    51,    53,    53,    45,    48,    51,    53,
      48,    51,    53,   134,   141,   124,   125,   134,   141,   211,
     212,   211,   141,    45,    48,    51,   141,   211,     4,    49,
      58,    51,    51,    48,     4,   101,   141,     4,     6,    48,
       4,     4,     4,   134,   134,   134,     4,   141,   218,     4,
     134,   134,     6,   136,     4,     4,     5,   141,     5,   141,
       4,   136,   138,   143,   167,   141,     5,   222,   134,   136,
     134,   136,   134,   136,   134,   136,   134,   136,   134,   136,
     134,   136,   134,   136,   134,   136,   134,   136,   134,   136,
     134,   136,   134,   136,   134,   136,   134,   136,   134,   136,
     134,   136,   134,   136,   134,   136,   134,   136,   134,   136,
     134,   134,   134,   134,     7,   134,     4,   209,   209,   209,
     209,   137,   141,   209,     4,    93,    94,     4,     4,   177,
     178,   179,   209,     6,     6,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   133,
       6,     6,   209,     5,   209,   209,     4,    45,   125,   177,
     186,   209,   216,   217,   209,   209,   134,   209,   217,   209,
     209,   134,   217,   209,   209,   125,   141,   209,   214,   216,
     134,   141,   134,   134,     5,   214,   215,   215,   215,   134,
     173,   174,   175,   176,   134,   134,   134,     4,   211,   211,
     211,   209,   209,   124,   125,   141,   141,   211,   141,   141,
     141,   124,   125,   134,   179,   211,   141,   134,   141,   134,
     134,   215,   214,   134,     4,     6,   136,   136,   179,     6,
     141,   136,   136,     6,   209,   209,   209,   138,   209,   141,
      96,   209,   209,   209,     6,     6,   179,     6,   179,   136,
     209,     4,   141,   151,     6,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,     4,   221,   222,
     221,   221,   221,   209,     5,   136,   135,     7,   114,   217,
     137,     7,   166,   167,   138,     7,   136,   142,    45,    48,
      51,    53,   172,     6,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,     6,
     135,   140,   140,   135,   136,   141,   209,   216,     8,   126,
     140,   142,   135,   135,   209,   135,   142,   135,   135,   209,
     142,   135,   135,   141,   142,   217,   126,     7,   209,   209,
     209,   209,     7,     7,   204,   204,   209,   134,   134,   134,
     134,   209,   209,   209,   135,   140,   140,   140,   211,   211,
     178,   178,   140,   209,   209,   209,   209,   190,   140,   179,
     209,   209,   209,   209,     7,   205,     7,   209,     6,   209,
     209,   142,   217,   209,   209,   135,   135,   135,    93,   140,
     179,   141,     8,   135,   137,   142,   142,   209,   137,   167,
     209,     4,    83,    84,    85,    86,   142,   154,   158,   161,
     163,   164,   135,   137,   135,   137,   135,   137,   135,   137,
     135,   137,   135,   137,   135,   137,   135,   137,   135,   137,
     135,   137,   135,   137,   140,   140,   135,   137,   135,   137,
     135,   137,   135,   137,   135,   137,   135,   137,   140,   140,
     140,   140,   140,   140,   136,   138,   135,   140,   140,   135,
     135,     6,   140,   209,   214,   214,   142,     7,   138,   166,
     167,   222,   209,     6,     4,     4,   141,   219,   137,   141,
     141,   141,   141,     8,     6,   121,   148,   217,   209,     7,
     137,   141,   209,   209,   209,   216,   209,   216,    96,     7,
       7,   135,     7,    96,     7,     7,   135,    96,     7,     7,
     217,   142,   141,   209,   135,   142,   135,   135,   209,   214,
       4,   203,     6,   135,   169,   209,   222,   169,   169,   169,
     135,   135,   135,   138,   211,   209,   209,   142,   142,   209,
     140,   140,   140,    73,    79,    80,   200,   201,   211,   142,
     187,   135,   142,   135,   135,   209,     6,   209,   135,   137,
     137,   142,   137,   137,     7,     7,     7,   138,   209,   142,
     209,   209,     7,   138,   137,   138,   167,   221,   142,   155,
     134,   134,   141,   165,     6,   209,   209,   209,   209,   209,
     209,   209,   209,   209,     4,   217,   221,   209,   137,     6,
       6,   137,     4,    93,    94,   209,     6,     6,     6,     7,
     136,   218,   220,     6,   217,   217,   217,   217,   209,   121,
     221,   135,   140,   211,   217,   142,     8,    51,   214,   214,
       7,   214,    51,    53,   214,   214,     7,    53,   214,   214,
     142,   217,     6,     7,     7,     7,     7,    64,   202,     6,
       7,   135,   135,   135,   135,     7,     7,     7,     4,   140,
     140,   140,   142,   211,   211,   211,     6,   141,   134,   142,
     201,   140,   200,     7,     6,     7,     7,     6,   141,     6,
       6,    51,     6,     6,   214,   214,   214,     4,   140,     8,
       8,   135,     4,     4,     6,     4,     6,   134,   209,   209,
     213,   214,   141,   135,   137,   135,   137,   135,   137,   135,
     137,   137,   135,   135,   135,   166,     7,   166,   167,   138,
       7,     6,   218,   209,   140,   142,   142,   142,   142,   142,
       6,     6,   148,   209,     6,   142,   209,   141,    58,   171,
     171,   214,     6,   141,   141,     6,     6,   214,   141,     6,
       6,   142,     5,   214,   214,   214,     4,     6,   214,     7,
       7,     7,     7,   214,   214,   214,     6,     7,   209,   209,
     209,   141,   140,   142,   140,   142,   140,   142,   209,   214,
     209,   209,   211,   142,     5,   141,   214,   141,   141,   214,
     217,   141,     6,     6,    92,   209,   209,   209,     6,     7,
     167,   152,   209,   140,   140,   140,   142,   153,   209,   138,
     214,   222,   209,     6,     4,   219,     6,   137,   218,     6,
       6,     6,     6,   221,   140,   137,   209,   211,     6,     6,
       6,   209,   209,     6,   209,     5,     6,     6,    96,   170,
     209,     6,   214,   214,   214,   214,     6,     4,     6,     6,
     209,   222,   142,   135,   140,   142,   178,   211,     6,   191,
     211,     6,   192,   211,     6,   193,   142,   140,   135,   142,
     140,     6,   125,   211,     6,   211,   211,     6,   142,   209,
     214,   140,   142,     8,   142,   135,   141,   209,   222,   135,
     140,   209,   209,   214,   141,   140,   142,     4,     6,     6,
       6,     7,     6,   138,     6,   209,   142,   142,   142,   142,
       5,    49,     6,     6,     6,     6,     6,   141,     6,     6,
     141,   209,   142,   140,   141,   140,   141,   140,   141,     6,
     214,     7,   141,   209,   140,   140,   140,     6,   142,    91,
     209,   209,   217,     6,     6,   156,   209,   140,   140,   213,
     209,     6,   218,    94,   140,     6,     6,     6,     6,     6,
     141,   213,   178,   140,   142,   209,   211,   200,   209,   211,
     200,   209,   211,   200,   140,   142,   214,   179,   142,   211,
     217,   211,   209,   142,   142,   142,   141,   209,   209,   142,
       6,   209,   209,   142,   142,   209,   142,   140,   142,   142,
     140,   142,   142,   140,   142,   214,     6,    64,   142,   188,
     141,   140,   142,   140,     6,     6,   153,   135,   140,     6,
     141,   140,   142,     6,   142,     6,   194,   209,     6,     6,
     195,   209,     6,     6,   196,   209,     6,   142,   209,   200,
     179,   217,     6,   211,   217,   142,   159,   209,   213,   209,
     141,   142,   141,   142,   141,   142,     6,     6,   142,   142,
     189,   142,   140,   142,     6,   141,   135,   142,   142,   200,
       6,   197,   200,     6,   198,   200,     6,   199,   200,     6,
     217,     6,   157,   221,   162,   141,     6,   142,   141,   142,
     141,   142,   141,   142,   142,   140,   142,   141,   213,     6,
     200,     6,   200,     6,   200,     6,   221,     6,   160,   221,
     142,   142,   142,   142,   140,   142,     6,     6,     6,     6,
     221,     6
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
#line 143 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 154 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 155 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 156 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 157 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 158 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 159 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 160 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 161 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 162 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 163 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 164 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 165 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 166 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 167 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 168 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 173 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 22:
#line 177 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 23:
#line 184 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 24:
#line 189 "Gmsh.y"
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

  case 25:
#line 204 "Gmsh.y"
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

  case 26:
#line 217 "Gmsh.y"
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

  case 27:
#line 246 "Gmsh.y"
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

  case 28:
#line 260 "Gmsh.y"
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

  case 29:
#line 271 "Gmsh.y"
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

  case 30:
#line 285 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData = new PViewDataList(); 
#endif
    ;}
    break;

  case 36:
#line 299 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 37:
#line 301 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 38:
#line 306 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 39:
#line 308 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 40:
#line 313 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
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

  case 41:
#line 417 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++) 
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    ;}
    break;

  case 42:
#line 427 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 43:
#line 436 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 44:
#line 443 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 45:
#line 453 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d)); 
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d)); 
      ViewData->T2D.push_back(ViewData->T2C.size()); 
#endif
    ;}
    break;

  case 46:
#line 462 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 47:
#line 471 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 48:
#line 478 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 49:
#line 488 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size()); 
#endif
    ;}
    break;

  case 50:
#line 496 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 51:
#line 506 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
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

  case 52:
#line 525 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
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

  case 53:
#line 544 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 54:
#line 550 "Gmsh.y"
    {
    ;}
    break;

  case 55:
#line 557 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 56:
#line 558 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 57:
#line 559 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 58:
#line 560 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 59:
#line 561 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 60:
#line 565 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 61:
#line 566 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 62:
#line 574 "Gmsh.y"
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

  case 63:
#line 596 "Gmsh.y"
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

  case 64:
#line 623 "Gmsh.y"
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

  case 65:
#line 663 "Gmsh.y"
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

  case 66:
#line 673 "Gmsh.y"
    {
      // appends to the list
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].push_back(*(double*)List_Pointer((yyvsp[(5) - (6)].l), i));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 67:
#line 681 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c)); 
      else
	gmsh_yysymbols[(yyvsp[(1) - (3)].c)][0] += (yyvsp[(2) - (3)].i);
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 68:
#line 689 "Gmsh.y"
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

  case 69:
#line 701 "Gmsh.y"
    { 
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 70:
#line 710 "Gmsh.y"
    { 
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c))
    ;}
    break;

  case 71:
#line 716 "Gmsh.y"
    { 
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c))
    ;}
    break;

  case 72:
#line 725 "Gmsh.y"
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

  case 73:
#line 743 "Gmsh.y"
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

  case 74:
#line 761 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 75:
#line 770 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 76:
#line 782 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 77:
#line 787 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 78:
#line 795 "Gmsh.y"
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

  case 79:
#line 815 "Gmsh.y"
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

  case 80:
#line 838 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->background_field = (int)(yyvsp[(4) - (5)].d);
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
    ;}
    break;

  case 81:
#line 845 "Gmsh.y"
    {
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 82:
#line 851 "Gmsh.y"
    {
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
      Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 83:
#line 871 "Gmsh.y"
    {
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
      Free((yyvsp[(6) - (9)].c));
      Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 84:
#line 892 "Gmsh.y"
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
		(yyvsp[(6) - (11)].c), (int)(yyvsp[(3) - (11)].d), field->getName());
      }
      else 
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (11)].d));
      Free((yyvsp[(6) - (11)].c));
      List_Delete((yyvsp[(9) - (11)].l));
    ;}
    break;

  case 85:
#line 918 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
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

  case 86:
#line 930 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
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

  case 87:
#line 947 "Gmsh.y"
    { 
      (yyval.i) = (int)(yyvsp[(1) - (1)].d); 
    ;}
    break;

  case 88:
#line 951 "Gmsh.y"
    { 
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim, 
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 89:
#line 961 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 90:
#line 965 "Gmsh.y"
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

  case 91:
#line 977 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 92:
#line 981 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 93:
#line 991 "Gmsh.y"
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

  case 94:
#line 1014 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 95:
#line 1018 "Gmsh.y"
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

  case 96:
#line 1034 "Gmsh.y"
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

  case 97:
#line 1056 "Gmsh.y"
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

  case 98:
#line 1074 "Gmsh.y"
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

  case 99:
#line 1092 "Gmsh.y"
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

  case 100:
#line 1122 "Gmsh.y"
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

  case 101:
#line 1152 "Gmsh.y"
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

  case 102:
#line 1170 "Gmsh.y"
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

  case 103:
#line 1188 "Gmsh.y"
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

  case 104:
#line 1214 "Gmsh.y"
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

  case 105:
#line 1231 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 106:
#line 1235 "Gmsh.y"
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

  case 107:
#line 1254 "Gmsh.y"
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

  case 108:
#line 1272 "Gmsh.y"
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

  case 109:
#line 1311 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 110:
#line 1317 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 111:
#line 1323 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 112:
#line 1330 "Gmsh.y"
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

  case 113:
#line 1355 "Gmsh.y"
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

  case 114:
#line 1380 "Gmsh.y"
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

  case 115:
#line 1396 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 116:
#line 1400 "Gmsh.y"
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

  case 117:
#line 1416 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME)){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	List_T *S[4] = {temp, 0, 0, 0};
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp, S);
	List_Delete(temp);
        List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 118:
#line 1434 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (12)].d);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (12)].l));
	List_T *S[4] = {0, 0, 0, 0};
	for (int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++){
	  List_T *ll;
	  List_Read((yyvsp[(10) - (12)].l), i, &ll);
	  S[i] = ListOfDouble2ListOfInt(ll);
          List_Delete(ll);
	}
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp, S);
	List_Delete(temp);
	for (int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++)
	  List_Delete(S[i]);
        List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (12)].l));
      List_Delete((yyvsp[(10) - (12)].l));
      Free((yyvsp[(8) - (12)].c));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    ;}
    break;

  case 119:
#line 1461 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	List_T *S[4] = {0, 0, 0, 0};
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp, S);
	List_Delete(temp);
        List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    ;}
    break;

  case 120:
#line 1478 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE)){
	yymsg(0, "Physical line %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	List_T *S[4] = {temp, 0, 0, 0};
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp, S);
	List_Delete(temp);
        List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 121:
#line 1498 "Gmsh.y"
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

  case 122:
#line 1516 "Gmsh.y"
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

  case 123:
#line 1533 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 124:
#line 1537 "Gmsh.y"
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

  case 125:
#line 1558 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 126:
#line 1563 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 127:
#line 1568 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 128:
#line 1573 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 129:
#line 1578 "Gmsh.y"
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

  case 130:
#line 1598 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 131:
#line 1604 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 132:
#line 1614 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 133:
#line 1615 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 134:
#line 1620 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 135:
#line 1624 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 136:
#line 1628 "Gmsh.y"
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

  case 137:
#line 1651 "Gmsh.y"
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

  case 138:
#line 1674 "Gmsh.y"
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

  case 139:
#line 1697 "Gmsh.y"
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

  case 140:
#line 1725 "Gmsh.y"
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

  case 141:
#line 1747 "Gmsh.y"
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

  case 142:
#line 1768 "Gmsh.y"
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

  case 143:
#line 1789 "Gmsh.y"
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

  case 144:
#line 1809 "Gmsh.y"
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
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (8)].d));
      Free((yyvsp[(2) - (8)].c));
#endif
    ;}
    break;

  case 145:
#line 1889 "Gmsh.y"
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

  case 146:
#line 1908 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (6)].c), "CutMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        GM->buildCutGModel(FindLevelSet(t)->ls);
        GM->setVisibility(0);
      }
      else
        yymsg(0, "Wrong levelset definition");
      Free((yyvsp[(2) - (6)].c));
#endif
    ;}
    break;

  case 147:
#line 1923 "Gmsh.y"
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

  case 148:
#line 2031 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 149:
#line 2040 "Gmsh.y"
    {
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
    ;}
    break;

  case 150:
#line 2044 "Gmsh.y"
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

  case 151:
#line 2059 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Meshes") || !strcmp((yyvsp[(2) - (3)].c), "All")){
        for(unsigned int i = 0; i < GModel::list.size(); i++){
          GModel::list[i]->destroy();
          GModel::list[i]->getGEOInternals()->destroy();
        }
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
      else{
	if(gmsh_yysymbols.count((yyvsp[(2) - (3)].c)))
	  gmsh_yysymbols.erase((yyvsp[(2) - (3)].c));
	else
	  yymsg(0, "Unknown object or expression to delete '%s'", (yyvsp[(2) - (3)].c));
      }
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 152:
#line 2086 "Gmsh.y"
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

  case 153:
#line 2103 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));      
    ;}
    break;

  case 154:
#line 2117 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 155:
#line 2123 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 156:
#line 2129 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 157:
#line 2138 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 158:
#line 2152 "Gmsh.y"
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
	ParseFile(tmpstring, false, true);
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
	CreateOutputFile(tmpstring, CTX::instance()->print.format);
#endif
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Save")){
#if defined(HAVE_FLTK)
	GModel::current()->importGEOInternals();
	char tmpstring[1024];
	FixRelativePath((yyvsp[(2) - (3)].c), tmpstring);
	CreateOutputFile(tmpstring, CTX::instance()->mesh.format);
#endif
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Merge") || !strcmp((yyvsp[(1) - (3)].c), "MergeWithBoundingBox")){
	// MergeWithBoundingBox is deprecated
	char tmpstring[1024];
	FixRelativePath((yyvsp[(2) - (3)].c), tmpstring);
	MergeFile(tmpstring, true);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "System"))
	SystemCall((yyvsp[(2) - (3)].c));
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 159:
#line 2200 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      if(!strcmp((yyvsp[(1) - (7)].c), "Save") && !strcmp((yyvsp[(2) - (7)].c), "View")){
	int index = (int)(yyvsp[(4) - (7)].d);
	if(index >= 0 && index < (int)PView::list.size()){
	  char tmpstring[1024];
	  FixRelativePath((yyvsp[(6) - (7)].c), tmpstring);
	  PView::list[index]->write(tmpstring, CTX::instance()->post.fileFormat);
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

  case 160:
#line 2218 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
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

  case 161:
#line 2233 "Gmsh.y"
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

  case 162:
#line 2252 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
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

  case 163:
#line 2264 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
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

  case 164:
#line 2288 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 165:
#line 2292 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the 
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 166:
#line 2299 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 167:
#line 2305 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 168:
#line 2310 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      Draw();
#endif
    ;}
    break;

  case 169:
#line 2316 "Gmsh.y"
    {
       GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 170:
#line 2325 "Gmsh.y"
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

  case 171:
#line 2342 "Gmsh.y"
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

  case 172:
#line 2359 "Gmsh.y"
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

  case 173:
#line 2378 "Gmsh.y"
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

  case 174:
#line 2397 "Gmsh.y"
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

  case 175:
#line 2425 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 176:
#line 2433 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 177:
#line 2439 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 178:
#line 2446 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 179:
#line 2450 "Gmsh.y"
    {
    ;}
    break;

  case 180:
#line 2459 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 181:
#line 2467 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 182:
#line 2475 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 183:
#line 2483 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 184:
#line 2487 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 185:
#line 2495 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 186:
#line 2499 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 187:
#line 2507 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 188:
#line 2511 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 189:
#line 2519 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 190:
#line 2523 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 191:
#line 2532 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 192:
#line 2539 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 193:
#line 2546 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 194:
#line 2553 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 195:
#line 2560 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 196:
#line 2567 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 197:
#line 2574 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 198:
#line 2581 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 199:
#line 2588 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 200:
#line 2595 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 201:
#line 2599 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 202:
#line 2606 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 203:
#line 2610 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 204:
#line 2617 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 205:
#line 2621 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 206:
#line 2628 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 207:
#line 2632 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 208:
#line 2639 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 209:
#line 2643 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 210:
#line 2650 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 211:
#line 2654 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 212:
#line 2661 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 213:
#line 2665 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 214:
#line 2672 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 215:
#line 2676 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 216:
#line 2683 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 217:
#line 2687 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 218:
#line 2698 "Gmsh.y"
    {
    ;}
    break;

  case 219:
#line 2701 "Gmsh.y"
    {
    ;}
    break;

  case 220:
#line 2707 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 221:
#line 2716 "Gmsh.y"
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

  case 222:
#line 2736 "Gmsh.y"
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

  case 223:
#line 2759 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 224:
#line 2763 "Gmsh.y"
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

  case 225:
#line 2786 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 226:
#line 2790 "Gmsh.y"
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

  case 227:
#line 2805 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 228:
#line 2809 "Gmsh.y"
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

  case 229:
#line 2821 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 230:
#line 2825 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 231:
#line 2830 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 232:
#line 2834 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 233:
#line 2841 "Gmsh.y"
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

  case 234:
#line 2897 "Gmsh.y"
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

  case 235:
#line 2967 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 236:
#line 2972 "Gmsh.y"
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

  case 237:
#line 3039 "Gmsh.y"
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

  case 238:
#line 3082 "Gmsh.y"
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

  case 239:
#line 3108 "Gmsh.y"
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

  case 240:
#line 3131 "Gmsh.y"
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

  case 241:
#line 3154 "Gmsh.y"
    {
    ;}
    break;

  case 242:
#line 3157 "Gmsh.y"
    {
    ;}
    break;

  case 243:
#line 3166 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 244:
#line 3170 "Gmsh.y"
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

  case 245:
#line 3185 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 246:
#line 3186 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 247:
#line 3187 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 248:
#line 3188 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 249:
#line 3189 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 250:
#line 3190 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 251:
#line 3191 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 252:
#line 3192 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 253:
#line 3194 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 254:
#line 3200 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 255:
#line 3201 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 256:
#line 3202 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 257:
#line 3203 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 258:
#line 3204 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 259:
#line 3205 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 260:
#line 3206 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 261:
#line 3207 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 262:
#line 3208 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 263:
#line 3209 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 264:
#line 3210 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 265:
#line 3211 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 266:
#line 3212 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 267:
#line 3213 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 268:
#line 3214 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 269:
#line 3215 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 270:
#line 3216 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 271:
#line 3217 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 272:
#line 3218 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 273:
#line 3219 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 274:
#line 3220 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 275:
#line 3221 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 276:
#line 3222 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 277:
#line 3223 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 278:
#line 3224 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 279:
#line 3225 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 280:
#line 3226 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 281:
#line 3227 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 282:
#line 3228 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 283:
#line 3229 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 284:
#line 3230 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 285:
#line 3231 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 286:
#line 3233 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 287:
#line 3234 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 288:
#line 3235 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 289:
#line 3236 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 290:
#line 3237 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 291:
#line 3238 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 292:
#line 3239 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 293:
#line 3240 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 294:
#line 3241 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 295:
#line 3242 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 296:
#line 3243 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 297:
#line 3244 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 298:
#line 3245 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 299:
#line 3246 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 300:
#line 3247 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 301:
#line 3248 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 302:
#line 3249 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 303:
#line 3250 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 304:
#line 3251 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 305:
#line 3252 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 306:
#line 3253 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 307:
#line 3262 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 308:
#line 3263 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 309:
#line 3264 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 310:
#line 3265 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 311:
#line 3266 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 312:
#line 3267 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 313:
#line 3268 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 314:
#line 3273 "Gmsh.y"
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

  case 315:
#line 3286 "Gmsh.y"
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

  case 316:
#line 3298 "Gmsh.y"
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

  case 317:
#line 3313 "Gmsh.y"
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

  case 318:
#line 3323 "Gmsh.y"
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

  case 319:
#line 3333 "Gmsh.y"
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

  case 320:
#line 3351 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 321:
#line 3356 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 322:
#line 3361 "Gmsh.y"
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

  case 323:
#line 3371 "Gmsh.y"
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

  case 324:
#line 3381 "Gmsh.y"
    { 
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 325:
#line 3389 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 326:
#line 3393 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 327:
#line 3397 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 328:
#line 3401 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 329:
#line 3405 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 330:
#line 3412 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 331:
#line 3416 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 332:
#line 3420 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 333:
#line 3424 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 334:
#line 3431 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 335:
#line 3436 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 336:
#line 3443 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 337:
#line 3448 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 338:
#line 3452 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 339:
#line 3457 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 340:
#line 3461 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 341:
#line 3469 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 342:
#line 3480 "Gmsh.y"
    { 
      (yyval.l) = (yyvsp[(1) - (1)].l); 
    ;}
    break;

  case 343:
#line 3484 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 344:
#line 3496 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 345:
#line 3504 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 346:
#line 3512 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); 
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 347:
#line 3519 "Gmsh.y"
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

  case 348:
#line 3530 "Gmsh.y"
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

  case 349:
#line 3550 "Gmsh.y"
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

  case 350:
#line 3560 "Gmsh.y"
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

  case 351:
#line 3570 "Gmsh.y"
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

  case 352:
#line 3580 "Gmsh.y"
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

  case 353:
#line 3600 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 354:
#line 3605 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 355:
#line 3609 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 356:
#line 3613 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 357:
#line 3625 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 358:
#line 3629 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 359:
#line 3641 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 360:
#line 3648 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 361:
#line 3658 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 362:
#line 3662 "Gmsh.y"
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

  case 363:
#line 3677 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 364:
#line 3682 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 365:
#line 3689 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 366:
#line 3693 "Gmsh.y"
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

  case 367:
#line 3706 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 368:
#line 3714 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 369:
#line 3725 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 370:
#line 3729 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 371:
#line 3737 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 372:
#line 3745 "Gmsh.y"
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

  case 373:
#line 3759 "Gmsh.y"
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

  case 374:
#line 3773 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 375:
#line 3777 "Gmsh.y"
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
#line 8406 "Gmsh.tab.cpp"
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


#line 3797 "Gmsh.y"


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

gmshMatrix<double> ListOfListOfDouble2Matrix(List_T *list)
{
  int M = List_Nbr(list);
  int N = 0;
  for(int i = 0; i < M; i++){
    List_T *line = *(List_T**)List_Pointer_Fast(list, i);
    N = std::max(N, List_Nbr(line));
  }
  gmshMatrix<double> mat(M, N);
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

void FixRelativePath(const char *in, char *out)
{
  if(in[0] == '/' || in[0] == '\\' || (strlen(in)>2 && in[1] == ':')){
    // do nothing: 'in' is an absolute path
    strcpy(out, in);
  }
  else{
    // append 'in' to the path of the parent file
    strcpy(out, gmsh_yyname.c_str());
    int i = strlen(out) - 1 ;
    while(i >= 0 && gmsh_yyname.c_str()[i] != '/' && 
          gmsh_yyname.c_str()[i] != '\\') i-- ;
    out[i+1] = '\0';
    strcat(out, in);
  }
}

void yyerror(char *s)
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

