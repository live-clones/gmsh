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
     tLoop = 326,
     tRecombine = 327,
     tSmoother = 328,
     tSplit = 329,
     tDelete = 330,
     tCoherence = 331,
     tIntersect = 332,
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
#define tLoop 326
#define tRecombine 327
#define tSmoother 328
#define tSplit 329
#define tDelete 330
#define tCoherence 331
#define tIntersect 332
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
#line 73 "Gmsh.y"
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
#line 430 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 443 "Gmsh.tab.cpp"

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
#define YYLAST   6392

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  143
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  367
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1273

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
     446,   447,   450,   458,   459,   469,   476,   484,   492,   501,
     510,   528,   536,   544,   556,   565,   566,   576,   585,   595,
     599,   604,   615,   623,   631,   640,   641,   651,   660,   673,
     682,   691,   700,   708,   709,   719,   725,   737,   743,   753,
     758,   768,   778,   780,   782,   783,   786,   793,   800,   807,
     814,   819,   826,   833,   837,   842,   848,   852,   856,   861,
     866,   870,   878,   886,   890,   898,   902,   905,   908,   911,
     927,   930,   933,   940,   949,   958,   969,   971,   974,   976,
     980,   985,   987,   993,  1005,  1019,  1020,  1028,  1029,  1043,
    1044,  1060,  1061,  1068,  1077,  1086,  1095,  1108,  1121,  1134,
    1149,  1164,  1179,  1180,  1193,  1194,  1207,  1208,  1221,  1222,
    1239,  1240,  1257,  1258,  1275,  1276,  1295,  1296,  1315,  1316,
    1335,  1337,  1340,  1346,  1354,  1364,  1367,  1377,  1378,  1382,
    1383,  1385,  1386,  1389,  1390,  1393,  1401,  1408,  1417,  1423,
    1429,  1436,  1447,  1458,  1469,  1480,  1483,  1487,  1489,  1493,
    1496,  1499,  1502,  1506,  1510,  1514,  1518,  1522,  1526,  1530,
    1534,  1538,  1542,  1546,  1550,  1554,  1558,  1564,  1569,  1574,
    1579,  1584,  1589,  1594,  1599,  1604,  1609,  1614,  1621,  1626,
    1631,  1636,  1641,  1646,  1651,  1658,  1665,  1672,  1677,  1682,
    1687,  1692,  1697,  1702,  1707,  1712,  1717,  1722,  1727,  1734,
    1739,  1744,  1749,  1754,  1759,  1764,  1771,  1778,  1785,  1790,
    1792,  1794,  1796,  1798,  1800,  1802,  1804,  1806,  1812,  1817,
    1822,  1825,  1831,  1835,  1842,  1847,  1855,  1862,  1864,  1867,
    1870,  1874,  1878,  1890,  1900,  1908,  1916,  1918,  1922,  1924,
    1926,  1929,  1933,  1938,  1944,  1946,  1948,  1951,  1955,  1959,
    1965,  1970,  1972,  1974,  1978,  1985,  1987,  1989,  1993,  1997,
    2007,  2015,  2017,  2023,  2027,  2034,  2036,  2040,  2042,  2044,
    2048,  2055,  2057,  2059,  2066,  2071,  2076,  2081
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     144,     0,    -1,   145,    -1,     1,     6,    -1,    -1,   145,
     146,    -1,   149,    -1,   148,    -1,   167,    -1,   171,    -1,
     176,    -1,   179,    -1,   180,    -1,   181,    -1,   184,    -1,
     204,    -1,   205,    -1,   206,    -1,   183,    -1,   182,    -1,
     120,    -1,   120,   120,    -1,    35,   133,     5,   134,     6,
      -1,    35,   133,     5,   134,   147,   219,     6,    -1,    35,
     133,     5,   139,   215,   134,     6,    -1,    35,   133,     5,
     139,   215,   134,   147,   219,     6,    -1,     4,     5,   140,
     150,   141,     6,    -1,    80,     4,   135,   207,   136,     6,
      -1,    81,     4,   135,   207,   136,     6,    -1,    -1,   150,
     153,    -1,   150,   157,    -1,   150,   160,    -1,   150,   162,
      -1,   150,   163,    -1,   207,    -1,   151,   139,   207,    -1,
     207,    -1,   152,   139,   207,    -1,    -1,    -1,     4,   154,
     133,   151,   134,   155,   140,   152,   141,     6,    -1,   219,
      -1,   156,   139,   219,    -1,    -1,    82,   133,   207,   139,
     207,   139,   207,   134,   158,   140,   156,   141,     6,    -1,
     219,    -1,   159,   139,   219,    -1,    -1,    83,   133,   207,
     139,   207,   139,   207,   139,   207,   134,   161,   140,   159,
     141,     6,    -1,    84,   140,   211,   141,   140,   211,   141,
       6,    -1,    84,   140,   211,   141,   140,   211,   141,   140,
     211,   141,   140,   211,   141,     6,    -1,    -1,    85,   164,
     140,   152,   141,     6,    -1,     7,    -1,   113,    -1,   112,
      -1,   111,    -1,   110,    -1,   131,    -1,   130,    -1,     4,
     165,   207,     6,    -1,     4,   135,   207,   136,   165,   207,
       6,    -1,     4,   135,   140,   215,   141,   136,   165,   212,
       6,    -1,     4,   135,   136,     7,   212,     6,    -1,     4,
     135,   136,   113,   212,     6,    -1,     4,   166,     6,    -1,
       4,   135,   207,   136,   166,     6,    -1,     4,     7,   220,
       6,    -1,     4,   137,     4,     7,   220,     6,    -1,     4,
     135,   207,   136,   137,     4,     7,   220,     6,    -1,     4,
     137,     4,   165,   207,     6,    -1,     4,   135,   207,   136,
     137,     4,   165,   207,     6,    -1,     4,   137,     4,   166,
       6,    -1,     4,   135,   207,   136,   137,     4,   166,     6,
      -1,     4,   137,    92,   137,     4,     7,   216,     6,    -1,
       4,   135,   207,   136,   137,    92,   137,     4,     7,   216,
       6,    -1,     4,   137,    93,     7,   217,     6,    -1,     4,
     135,   207,   136,   137,    93,     7,   217,     6,    -1,     4,
     100,     7,   207,     6,    -1,   100,   135,   207,   136,     7,
       4,     6,    -1,   100,   135,   207,   136,   137,     4,     7,
     207,     6,    -1,   100,   135,   207,   136,   137,     4,     7,
     220,     6,    -1,   100,   135,   207,   136,   137,     4,     7,
     140,   215,   141,     6,    -1,    65,   133,     4,   134,   137,
       4,     7,   207,     6,    -1,    65,   133,     4,   134,   137,
       4,     7,   220,     6,    -1,   207,    -1,   220,    -1,    -1,
      95,    49,   140,   207,   141,    -1,    -1,    58,   209,    -1,
      45,   133,   207,   134,     7,   209,     6,    -1,    -1,    62,
      45,   172,   133,   168,   134,     7,   212,     6,    -1,    54,
      55,   212,     7,   207,     6,    -1,    48,   133,   207,   134,
       7,   212,     6,    -1,    52,   133,   207,   134,     7,   212,
       6,    -1,    46,   133,   207,   134,     7,   212,   170,     6,
      -1,    47,   133,   207,   134,     7,   212,   170,     6,    -1,
      56,   133,   207,   134,     7,   140,   207,   139,   207,   139,
       5,   139,     5,   139,     5,   141,     6,    -1,    87,   133,
     207,   134,     7,   212,     6,    -1,    88,   133,   207,   134,
       7,   212,     6,    -1,    89,   133,   207,   134,     7,   212,
      91,   212,    90,   207,     6,    -1,    48,    71,   133,   207,
     134,     7,   212,     6,    -1,    -1,    62,    48,   173,   133,
     168,   134,     7,   212,     6,    -1,    58,    51,   133,   207,
     134,     7,   212,     6,    -1,    59,    51,   133,   207,   134,
       7,   212,   169,     6,    -1,    12,    13,     6,    -1,    13,
      51,   207,     6,    -1,    56,    51,   133,   207,   134,     7,
       5,     5,     5,     6,    -1,    49,   133,   207,   134,     7,
     212,     6,    -1,    50,   133,   207,   134,     7,   212,     6,
      -1,    51,    71,   133,   207,   134,     7,   212,     6,    -1,
      -1,    62,    51,   174,   133,   168,   134,     7,   212,     6,
      -1,    63,    53,   133,   207,   134,     7,   212,     6,    -1,
      63,    51,   133,   207,   134,     7,   212,     4,   140,   211,
     141,     6,    -1,    63,    51,   133,   207,   134,     7,   212,
       6,    -1,    63,    48,   133,   207,   134,     7,   212,     6,
      -1,    61,    53,   133,   207,   134,     7,   212,     6,    -1,
      53,   133,   207,   134,     7,   212,     6,    -1,    -1,    62,
      53,   175,   133,   168,   134,     7,   212,     6,    -1,    67,
     209,   140,   177,   141,    -1,    66,   140,   209,   139,   209,
     139,   207,   141,   140,   177,   141,    -1,    68,   209,   140,
     177,   141,    -1,    69,   140,   209,   139,   207,   141,   140,
     177,   141,    -1,     4,   140,   177,   141,    -1,    77,    48,
     140,   215,   141,    51,   140,   207,   141,    -1,    74,    48,
     133,   207,   134,   140,   215,   141,     6,    -1,   178,    -1,
     176,    -1,    -1,   178,   171,    -1,   178,    45,   140,   215,
     141,     6,    -1,   178,    48,   140,   215,   141,     6,    -1,
     178,    51,   140,   215,   141,     6,    -1,   178,    53,   140,
     215,   141,     6,    -1,    75,   140,   178,   141,    -1,    75,
     100,   135,   207,   136,     6,    -1,    75,     4,   135,   207,
     136,     6,    -1,    75,     4,     6,    -1,    75,     4,     4,
       6,    -1,    92,   216,   140,   178,   141,    -1,   104,     5,
       6,    -1,   105,     5,     6,    -1,   104,   140,   178,   141,
      -1,   105,   140,   178,   141,    -1,     4,   220,     6,    -1,
       4,     4,   135,   207,   136,   219,     6,    -1,     4,     4,
       4,   135,   207,   136,     6,    -1,     4,   207,     6,    -1,
      65,   133,     4,   134,   137,     4,     6,    -1,    86,     4,
       6,    -1,    99,     6,    -1,    43,     6,    -1,    40,     6,
      -1,    40,   140,   207,   139,   207,   139,   207,   139,   207,
     139,   207,   139,   207,   141,     6,    -1,    41,     6,    -1,
      44,     6,    -1,    94,   133,   207,     8,   207,   134,    -1,
      94,   133,   207,     8,   207,     8,   207,   134,    -1,    94,
       4,    95,   140,   207,     8,   207,   141,    -1,    94,     4,
      95,   140,   207,     8,   207,     8,   207,   141,    -1,    96,
      -1,   103,     4,    -1,   101,    -1,   102,     4,     6,    -1,
      97,   133,   207,   134,    -1,    98,    -1,    70,   209,   140,
     178,   141,    -1,    70,   140,   209,   139,   209,   139,   207,
     141,   140,   178,   141,    -1,    70,   140,   209,   139,   209,
     139,   209,   139,   207,   141,   140,   178,   141,    -1,    -1,
      70,   209,   140,   178,   185,   198,   141,    -1,    -1,    70,
     140,   209,   139,   209,   139,   207,   141,   140,   178,   186,
     198,   141,    -1,    -1,    70,   140,   209,   139,   209,   139,
     209,   139,   207,   141,   140,   178,   187,   198,   141,    -1,
      -1,    70,   140,   178,   188,   198,   141,    -1,    70,    45,
     140,   207,   139,   209,   141,     6,    -1,    70,    48,   140,
     207,   139,   209,   141,     6,    -1,    70,    51,   140,   207,
     139,   209,   141,     6,    -1,    70,    45,   140,   207,   139,
     209,   139,   209,   139,   207,   141,     6,    -1,    70,    48,
     140,   207,   139,   209,   139,   209,   139,   207,   141,     6,
      -1,    70,    51,   140,   207,   139,   209,   139,   209,   139,
     207,   141,     6,    -1,    70,    45,   140,   207,   139,   209,
     139,   209,   139,   209,   139,   207,   141,     6,    -1,    70,
      48,   140,   207,   139,   209,   139,   209,   139,   209,   139,
     207,   141,     6,    -1,    70,    51,   140,   207,   139,   209,
     139,   209,   139,   209,   139,   207,   141,     6,    -1,    -1,
      70,    45,   140,   207,   139,   209,   141,   189,   140,   198,
     141,     6,    -1,    -1,    70,    48,   140,   207,   139,   209,
     141,   190,   140,   198,   141,     6,    -1,    -1,    70,    51,
     140,   207,   139,   209,   141,   191,   140,   198,   141,     6,
      -1,    -1,    70,    45,   140,   207,   139,   209,   139,   209,
     139,   207,   141,   192,   140,   198,   141,     6,    -1,    -1,
      70,    48,   140,   207,   139,   209,   139,   209,   139,   207,
     141,   193,   140,   198,   141,     6,    -1,    -1,    70,    51,
     140,   207,   139,   209,   139,   209,   139,   207,   141,   194,
     140,   198,   141,     6,    -1,    -1,    70,    45,   140,   207,
     139,   209,   139,   209,   139,   209,   139,   207,   141,   195,
     140,   198,   141,     6,    -1,    -1,    70,    48,   140,   207,
     139,   209,   139,   209,   139,   209,   139,   207,   141,   196,
     140,   198,   141,     6,    -1,    -1,    70,    51,   140,   207,
     139,   209,   139,   209,   139,   209,   139,   207,   141,   197,
     140,   198,   141,     6,    -1,   199,    -1,   198,   199,    -1,
      78,   140,   207,   141,     6,    -1,    78,   140,   212,   139,
     212,   141,     6,    -1,    78,   140,   212,   139,   212,   139,
     212,   141,     6,    -1,    72,     6,    -1,    79,   133,   207,
     134,     7,   212,    64,   207,     6,    -1,    -1,    64,     4,
     207,    -1,    -1,     4,    -1,    -1,     7,   212,    -1,    -1,
       7,   207,    -1,    60,    48,   213,     7,   207,   200,     6,
      -1,    60,    51,   213,   202,   201,     6,    -1,    57,    51,
     140,   207,   141,     7,   212,     6,    -1,    60,    53,   213,
     202,     6,    -1,    72,    51,   213,   203,     6,    -1,    73,
      51,   212,     7,   207,     6,    -1,    45,   140,   215,   141,
      95,    51,   140,   207,   141,     6,    -1,    48,   140,   215,
     141,    95,    51,   140,   207,   141,     6,    -1,    48,   140,
     215,   141,    95,    53,   140,   207,   141,     6,    -1,    51,
     140,   215,   141,    95,    53,   140,   207,   141,     6,    -1,
      76,     6,    -1,    76,     4,     6,    -1,   208,    -1,   133,
     207,   134,    -1,   124,   207,    -1,   123,   207,    -1,   128,
     207,    -1,   207,   124,   207,    -1,   207,   123,   207,    -1,
     207,   125,   207,    -1,   207,   126,   207,    -1,   207,   127,
     207,    -1,   207,   132,   207,    -1,   207,   119,   207,    -1,
     207,   120,   207,    -1,   207,   122,   207,    -1,   207,   121,
     207,    -1,   207,   118,   207,    -1,   207,   117,   207,    -1,
     207,   116,   207,    -1,   207,   115,   207,    -1,   207,   114,
     207,     8,   207,    -1,    14,   133,   207,   134,    -1,    15,
     133,   207,   134,    -1,    16,   133,   207,   134,    -1,    17,
     133,   207,   134,    -1,    18,   133,   207,   134,    -1,    19,
     133,   207,   134,    -1,    20,   133,   207,   134,    -1,    21,
     133,   207,   134,    -1,    22,   133,   207,   134,    -1,    24,
     133,   207,   134,    -1,    25,   133,   207,   139,   207,   134,
      -1,    26,   133,   207,   134,    -1,    27,   133,   207,   134,
      -1,    28,   133,   207,   134,    -1,    29,   133,   207,   134,
      -1,    30,   133,   207,   134,    -1,    31,   133,   207,   134,
      -1,    32,   133,   207,   139,   207,   134,    -1,    33,   133,
     207,   139,   207,   134,    -1,    34,   133,   207,   139,   207,
     134,    -1,    23,   133,   207,   134,    -1,    14,   135,   207,
     136,    -1,    15,   135,   207,   136,    -1,    16,   135,   207,
     136,    -1,    17,   135,   207,   136,    -1,    18,   135,   207,
     136,    -1,    19,   135,   207,   136,    -1,    20,   135,   207,
     136,    -1,    21,   135,   207,   136,    -1,    22,   135,   207,
     136,    -1,    24,   135,   207,   136,    -1,    25,   135,   207,
     139,   207,   136,    -1,    26,   135,   207,   136,    -1,    27,
     135,   207,   136,    -1,    28,   135,   207,   136,    -1,    29,
     135,   207,   136,    -1,    30,   135,   207,   136,    -1,    31,
     135,   207,   136,    -1,    32,   135,   207,   139,   207,   136,
      -1,    33,   135,   207,   139,   207,   136,    -1,    34,   135,
     207,   139,   207,   136,    -1,    23,   135,   207,   136,    -1,
       3,    -1,     9,    -1,    10,    -1,    11,    -1,   107,    -1,
     108,    -1,   109,    -1,     4,    -1,     4,   142,   140,   207,
     141,    -1,     4,   135,   207,   136,    -1,   138,     4,   135,
     136,    -1,     4,   166,    -1,     4,   135,   207,   136,   166,
      -1,     4,   137,     4,    -1,     4,   135,   207,   136,   137,
       4,    -1,     4,   137,     4,   166,    -1,     4,   135,   207,
     136,   137,     4,   166,    -1,   106,   133,     5,   139,   207,
     134,    -1,   210,    -1,   124,   209,    -1,   123,   209,    -1,
     209,   124,   209,    -1,   209,   123,   209,    -1,   140,   207,
     139,   207,   139,   207,   139,   207,   139,   207,   141,    -1,
     140,   207,   139,   207,   139,   207,   139,   207,   141,    -1,
     140,   207,   139,   207,   139,   207,   141,    -1,   133,   207,
     139,   207,   139,   207,   134,    -1,   212,    -1,   211,   139,
     212,    -1,   207,    -1,   214,    -1,   140,   141,    -1,   140,
     215,   141,    -1,   124,   140,   215,   141,    -1,   207,   125,
     140,   215,   141,    -1,   212,    -1,     5,    -1,   124,   214,
      -1,   207,   125,   214,    -1,   207,     8,   207,    -1,   207,
       8,   207,     8,   207,    -1,    45,   140,   207,   141,    -1,
     176,    -1,   184,    -1,     4,   135,   136,    -1,     4,   135,
     140,   215,   141,   136,    -1,   207,    -1,   214,    -1,   215,
     139,   207,    -1,   215,   139,   214,    -1,   140,   207,   139,
     207,   139,   207,   139,   207,   141,    -1,   140,   207,   139,
     207,   139,   207,   141,    -1,     4,    -1,     4,   137,    92,
     137,     4,    -1,   140,   218,   141,    -1,     4,   135,   207,
     136,   137,    93,    -1,   216,    -1,   218,   139,   216,    -1,
     220,    -1,     4,    -1,     4,   137,     4,    -1,     4,   135,
     207,   136,   137,     4,    -1,     5,    -1,    42,    -1,    37,
     133,   219,   139,   219,   134,    -1,    38,   133,   219,   134,
      -1,    39,   133,   219,   134,    -1,    36,   133,   219,   134,
      -1,    36,   133,   219,   139,   215,   134,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   141,   141,   142,   147,   149,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     170,   174,   181,   186,   201,   214,   243,   257,   268,   283,
     288,   289,   290,   291,   292,   296,   298,   303,   305,   311,
     415,   310,   433,   440,   451,   450,   468,   475,   486,   485,
     502,   519,   542,   541,   555,   556,   557,   558,   559,   563,
     564,   571,   593,   620,   660,   670,   678,   686,   698,   707,
     713,   722,   740,   758,   767,   779,   784,   792,   812,   835,
     842,   848,   868,   889,   915,   927,   944,   948,   959,   962,
     975,   978,   988,  1012,  1011,  1031,  1053,  1071,  1089,  1119,
    1149,  1169,  1187,  1205,  1231,  1249,  1248,  1271,  1289,  1328,
    1334,  1340,  1347,  1372,  1397,  1414,  1413,  1433,  1450,  1478,
    1495,  1515,  1533,  1551,  1550,  1575,  1580,  1585,  1590,  1595,
    1615,  1621,  1632,  1633,  1638,  1641,  1645,  1668,  1691,  1714,
    1742,  1751,  1755,  1770,  1797,  1814,  1828,  1834,  1840,  1849,
    1863,  1911,  1929,  1944,  1963,  1975,  1999,  2003,  2010,  2016,
    2021,  2027,  2036,  2053,  2070,  2089,  2108,  2136,  2144,  2150,
    2157,  2161,  2170,  2178,  2186,  2195,  2194,  2207,  2206,  2219,
    2218,  2231,  2230,  2243,  2250,  2257,  2264,  2271,  2278,  2285,
    2292,  2299,  2307,  2306,  2318,  2317,  2329,  2328,  2340,  2339,
    2351,  2350,  2362,  2361,  2373,  2372,  2384,  2383,  2395,  2394,
    2409,  2412,  2418,  2427,  2447,  2470,  2474,  2498,  2501,  2517,
    2520,  2533,  2536,  2542,  2545,  2552,  2608,  2678,  2683,  2750,
    2793,  2819,  2842,  2865,  2868,  2877,  2881,  2897,  2898,  2899,
    2900,  2901,  2902,  2903,  2904,  2905,  2912,  2913,  2914,  2915,
    2916,  2917,  2918,  2919,  2920,  2921,  2922,  2923,  2924,  2925,
    2926,  2927,  2928,  2929,  2930,  2931,  2932,  2933,  2934,  2935,
    2936,  2937,  2938,  2939,  2940,  2941,  2942,  2943,  2945,  2946,
    2947,  2948,  2949,  2950,  2951,  2952,  2953,  2954,  2955,  2956,
    2957,  2958,  2959,  2960,  2961,  2962,  2963,  2964,  2965,  2974,
    2975,  2976,  2977,  2978,  2979,  2980,  2984,  2997,  3009,  3024,
    3034,  3044,  3062,  3067,  3072,  3082,  3092,  3100,  3104,  3108,
    3112,  3116,  3123,  3127,  3131,  3135,  3142,  3147,  3154,  3159,
    3163,  3168,  3172,  3180,  3191,  3195,  3207,  3215,  3223,  3230,
    3241,  3261,  3271,  3281,  3291,  3311,  3316,  3320,  3324,  3336,
    3340,  3352,  3359,  3369,  3373,  3388,  3393,  3400,  3404,  3417,
    3425,  3436,  3440,  3448,  3456,  3470,  3484,  3488
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
  "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLoop", "tRecombine",
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tIntersect", "tLayers",
  "tHole", "tAlias", "tAliasWithOptions", "tText2D", "tText3D",
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
  "InSphereCenter", "CircleOptions", "Shape", "@6", "@7", "@8", "@9",
  "Transform", "MultipleShape", "ListOfShapes", "Delete", "Colorify",
  "Visibility", "Command", "Loop", "Extrude", "@10", "@11", "@12", "@13",
  "@14", "@15", "@16", "@17", "@18", "@19", "@20", "@21", "@22",
  "ExtrudeParameters", "ExtrudeParameter", "TransfiniteType",
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
     170,   170,   171,   172,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   173,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   174,   171,   171,   171,   171,
     171,   171,   171,   175,   171,   176,   176,   176,   176,   176,
     176,   176,   177,   177,   178,   178,   178,   178,   178,   178,
     179,   179,   179,   179,   179,   180,   181,   181,   181,   181,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   184,   184,   184,   185,   184,   186,   184,   187,
     184,   188,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   189,   184,   190,   184,   191,   184,   192,   184,
     193,   184,   194,   184,   195,   184,   196,   184,   197,   184,
     198,   198,   199,   199,   199,   199,   199,   200,   200,   201,
     201,   202,   202,   203,   203,   204,   204,   204,   204,   204,
     204,   205,   205,   205,   205,   206,   206,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   209,   209,   209,
     209,   209,   210,   210,   210,   210,   211,   211,   212,   212,
     212,   212,   212,   212,   213,   213,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   215,   215,   215,   215,   216,
     216,   216,   216,   217,   217,   218,   218,   219,   219,   219,
     219,   220,   220,   220,   220,   220,   220,   220
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
       0,     2,     7,     0,     9,     6,     7,     7,     8,     8,
      17,     7,     7,    11,     8,     0,     9,     8,     9,     3,
       4,    10,     7,     7,     8,     0,     9,     8,    12,     8,
       8,     8,     7,     0,     9,     5,    11,     5,     9,     4,
       9,     9,     1,     1,     0,     2,     6,     6,     6,     6,
       4,     6,     6,     3,     4,     5,     3,     3,     4,     4,
       3,     7,     7,     3,     7,     3,     2,     2,     2,    15,
       2,     2,     6,     8,     8,    10,     1,     2,     1,     3,
       4,     1,     5,    11,    13,     0,     7,     0,    13,     0,
      15,     0,     6,     8,     8,     8,    12,    12,    12,    14,
      14,    14,     0,    12,     0,    12,     0,    12,     0,    16,
       0,    16,     0,    16,     0,    18,     0,    18,     0,    18,
       1,     2,     5,     7,     9,     2,     9,     0,     3,     0,
       1,     0,     2,     0,     2,     7,     6,     8,     5,     5,
       6,    10,    10,    10,    10,     2,     3,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     6,     6,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     4,     4,
       2,     5,     3,     6,     4,     7,     6,     1,     2,     2,
       3,     3,    11,     9,     7,     7,     1,     3,     1,     1,
       2,     3,     4,     5,     1,     1,     2,     3,     3,     5,
       4,     1,     1,     3,     6,     1,     1,     3,     3,     9,
       7,     1,     5,     3,     6,     1,     3,     1,     1,     3,
       6,     1,     1,     6,     4,     4,     4,     6
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
       0,     0,   166,     0,   171,     0,     0,   168,     0,     0,
       0,     0,     5,     7,     6,     8,     9,    10,    11,    12,
      13,    19,    18,    14,    15,    16,    17,   299,   306,   361,
      54,   300,   301,   302,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   362,
       0,     0,   303,   304,   305,    58,    57,    56,    55,     0,
       0,     0,    60,    59,     0,     0,     0,     0,   134,     0,
       0,     0,   237,     0,     0,     0,     0,   158,     0,   160,
     157,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,   105,   115,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   317,
       0,     0,     0,     0,     0,   134,     0,     0,     0,     0,
       0,     0,   134,     0,   235,     0,     0,     0,     0,     0,
       0,     0,   351,     0,     0,     0,     0,     0,   156,     0,
       0,   167,     0,   134,     0,   134,     0,     0,     0,     0,
     310,    29,   361,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   306,   240,   239,   241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,     0,   132,     0,    66,
     153,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,   109,     0,     0,
       0,     0,   306,     0,     0,   341,   342,   345,   346,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   328,     0,   329,     0,     0,     0,     0,
       0,   335,   334,     0,   221,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   319,   318,     0,     0,
       0,     0,   134,   134,     0,     0,     0,     0,     0,     0,
       0,   181,     0,   134,   223,     0,     0,     0,   143,     0,
       0,     0,   236,     0,     0,     0,   155,     0,     0,     0,
       0,     0,   134,     0,     0,     0,     0,   169,   146,     0,
     147,     0,     0,     0,   312,     0,     0,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     358,     0,   357,     0,     0,     0,     0,     0,     0,   238,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
     129,     0,     0,     0,     0,   135,    61,     0,   255,   254,
     253,   252,   248,   249,   251,   250,   243,   242,   244,   245,
     246,   247,   110,     0,     0,     0,     0,     0,     0,   239,
     336,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   330,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   321,   320,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,   144,     0,
       0,   140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,     0,   148,   149,     0,   308,   314,
       0,    39,     0,     0,     0,    52,     0,    30,    31,    32,
      33,    34,   257,   278,   258,   279,   259,   280,   260,   281,
     261,   282,   262,   283,   263,   284,   264,   285,   265,   286,
     277,   298,   266,   287,     0,     0,   268,   289,   269,   290,
     270,   291,   271,   292,   272,   293,   273,   294,     0,     0,
       0,     0,     0,     0,     0,     0,   366,     0,     0,   364,
     365,    79,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,    73,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,    22,    20,     0,     0,     0,     0,
     343,     0,     0,   338,   244,   337,   347,   348,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   331,     0,     0,     0,     0,     0,     0,     0,   217,
     222,   220,     0,   228,     0,     0,    86,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,   127,
       0,     0,     0,     0,     0,     0,     0,     0,   210,     0,
     172,     0,   224,   229,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   311,     0,   307,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,     0,     0,     0,   308,    64,    65,     0,     0,
       0,     0,     0,    67,    69,    71,     0,     0,   355,     0,
      77,     0,     0,     0,     0,   256,    21,     0,     0,     0,
       0,     0,   340,     0,     0,    90,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   332,     0,    95,
       0,     0,     0,     0,     0,     0,     0,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   215,     0,     0,   182,   211,     0,
       0,   230,     0,   142,   141,     0,    27,    28,     0,     0,
       0,   352,     0,     0,     0,   162,     0,     0,   152,   313,
     151,     0,     0,     0,     0,   326,     0,   267,   288,   274,
     295,   275,   296,   276,   297,     0,   367,   363,   316,     0,
      54,     0,     0,     0,     0,    62,     0,     0,     0,   353,
       0,     0,     0,     0,    23,    24,     0,     0,    92,     0,
     339,     0,     0,     0,     0,     0,    96,     0,     0,   112,
     113,     0,     0,    97,   122,   333,     0,     0,     0,     0,
      88,     0,   225,     0,     0,     0,     0,     0,     0,     0,
       0,   154,     0,     0,     0,     0,   134,     0,   192,     0,
     194,     0,   196,   328,     0,     0,     0,     0,   176,     0,
       0,   101,   102,     0,     0,     0,     0,    80,     0,   315,
       0,    35,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,    74,     0,     0,    75,     0,   356,   136,   137,
     138,   139,     0,     0,   344,     0,    91,    98,    99,   104,
       0,     0,   114,     0,     0,     0,   227,   107,     0,     0,
     218,   121,     0,     0,     0,     0,   120,     0,   119,   117,
       0,     0,     0,   325,     0,   324,     0,     0,   183,     0,
       0,   184,     0,     0,   185,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   350,     0,   164,   163,     0,
       0,     0,    40,     0,     0,     0,   327,     0,     0,     0,
     360,    63,    70,    72,     0,    78,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,   108,    94,   106,   116,
     124,     0,    84,    85,   134,     0,   128,     0,     0,     0,
       0,     0,     0,   212,     0,     0,   134,     0,   131,   130,
       0,     0,     0,     0,    81,    82,     0,    36,     0,     0,
       0,    38,    53,     0,   354,     0,   231,   232,   233,   234,
     111,     0,     0,     0,     0,     0,   323,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
       0,     0,   349,   165,     0,     0,     0,     0,     0,    76,
       0,     0,     0,     0,   126,     0,   198,     0,     0,   200,
       0,     0,   202,     0,     0,     0,   213,     0,   173,     0,
     134,   103,    83,     0,    44,     0,    50,     0,     0,     0,
      89,   118,   322,   186,     0,     0,   193,   187,     0,     0,
     195,   188,     0,     0,   197,     0,     0,     0,   179,     0,
       0,     0,     0,     0,     0,     0,   204,     0,   206,     0,
     208,   214,   216,   178,   174,     0,    41,     0,    48,     0,
       0,     0,     0,   189,     0,     0,   190,     0,     0,   191,
       0,     0,     0,    42,     0,     0,   159,     0,     0,     0,
       0,     0,     0,     0,   180,     0,     0,     0,     0,     0,
     199,     0,   201,     0,   203,     0,    43,    45,     0,    46,
       0,   100,     0,     0,     0,     0,     0,    51,   205,   207,
     209,    47,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    62,   666,    63,    64,   406,   970,   976,
     587,   756,  1106,  1232,   588,  1200,  1258,   589,  1234,   590,
     591,   760,   129,   220,    65,   705,  1009,   913,   475,   347,
     348,   349,   350,   315,   286,   287,    68,    69,    70,    71,
      72,   316,   731,  1169,  1215,   551,  1029,  1032,  1035,  1184,
    1188,  1192,  1224,  1227,  1230,   727,   728,   826,   702,   528,
     555,    74,    75,    76,   333,   132,   356,   179,   874,   875,
     343,   335,   319,   204,   657,   789,   451,   452
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1050
static const yytype_int16 yypact[] =
{
    2878,    33,    42,  2956, -1050, -1050,  1357,    69,     2,   -70,
      15,    88,   102,   106,   -89,    -7,    27,   -41,    66,    80,
     -47,    83,   142,    61,   -22,   251,   255,   285,    74,   298,
     164,   450,   247,   241,    52,    52,   274,   -23,   360,   377,
     389,     5,   174,   399,   418,   454,   476,   350,   361,   378,
      10,    34, -1050,   408, -1050,   526,   398, -1050,   541,   556,
       0,    18, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,    22,   409,
     542, -1050, -1050, -1050,    49,   130,   138,   223,   344,   374,
     423,   457,   461,   466,   477,   478,   481,   505,   512,   513,
     528,   535,   540,   545,   548,   419,   444,   449,   469, -1050,
     608,   486, -1050, -1050, -1050, -1050, -1050, -1050, -1050,  2301,
    2301,  2301, -1050, -1050,  2301,  1870,    14,   616,    12,  2301,
     623,   615, -1050,   624,   628,  2301,   630, -1050,  2301, -1050,
   -1050, -1050,  2301,  2232,  2301,  2301,   508,  2301,  2232,  2301,
    2301,   516,  2232,  2301,  2301,  1537,   525,  2301,   522,   534,
     544,  1405,  1405,  1405,   551, -1050, -1050, -1050, -1050,   554,
     570,   575,   670,    52,    52,    52,  2301,  2301,   -36, -1050,
      65,    52,   553,   585,   588,  2100,   204,  1405,  1537,   610,
      37,   622, -1050,   743, -1050,   635,   652,   656,   772,  2301,
    2301,  2301,   642,  2301,   646,   700,  2301,  2301, -1050,  2301,
     797, -1050,   824, -1050,   832, -1050,   709,  2301,   841,   766,
   -1050, -1050, -1050,   857,  2301,  2301,  2301,  2301,  2301,  2301,
    2301,  2301,  2301,  2301,  2301,  2301,  2301,  2301,  2301,  2301,
    2301,  2301,  2301,  2301,  2301,  2301,  2301,  2301,  2301,  2301,
    2301,  2301,  2301,  2301,  2301,  2301,  2301,  2301,  2301,  2301,
    2301,  2301,  2301,  2301,  2301,  2301,   480,   480,   480,   480,
    2301,   885,   529,   775,   775,   775,  5189,     8,  2232,  4453,
     207,   773,   912,   786,   782, -1050,   783,  3022,   777, -1050,
   -1050,  2301,  2301,  2301,  2301,  2301,  2301,  2301,  2301,  2301,
    2301,  2301,  2301,  2301,  2301,  2301, -1050, -1050,  1187,   -75,
    3699,  5210,   502,   787,  2232, -1050, -1050,   905, -1050,   549,
    5231,  5252,  2301,  5273,   550,  5294,  5315,  2301,   559,  5336,
    5357,  1669,  1218,  1059,   919, -1050,  2301,  5378,  2301,  2301,
    2301, -1050, -1050,   921,   922,   922,  2301,   798,   799,   800,
     801,  2301,  2301,  2301,   803,   -48, -1050, -1050,  3725,  3751,
      52,    52,    12,    12,   229,  2301,  2301,  2301,  2100,  2100,
    2301,  3022,   302, -1050,   931,   932,  2301,   934, -1050,  2301,
    2301,  1575, -1050,  2232,  2301,  2301, -1050,  5399,  5420,  5441,
     849,  3777, -1050,   802,  2681,  5462,  4476, -1050, -1050,  1707,
   -1050,  1971,  2301,  4499,   184,  2301,    13, -1050,  5483,  4522,
    5504,  4545,  5525,  4568,  5546,  4591,  5567,  4614,  5588,  4637,
    5609,  4660,  5630,  4683,  5651,  4706,  5672,  4729,  5693,  4752,
    3803,  3829,  5714,  4775,  5735,  4798,  5756,  4821,  5777,  4844,
    5798,  4867,  5819,  4890,  3855,  3881,  3907,  3933,  3959,  3985,
     168,   -49, -1050,   804,   810,   816,  2043,   812,  2301, -1050,
    1537,  1537,   560,   170,   542,  2301,   946,   949,    16,   819,
   -1050,   -67,   -31,   -37,   -56, -1050, -1050,  2706,   757,   594,
     728,   728,   330,   330,   330,   330,   268,   268,   775,   775,
     775,   775, -1050,    46,  2232,  2301,   951,  2065,  2301,   775,
   -1050,  2301,  2232,  2232,   861,   952,   953,  5840,   956,   869,
     958,   961,  5861,   874,   964,   966,  2232, -1050,   563,  1801,
    2301,  5882,   968,  2779,  5903,  5924,  2301,  1537,   972,   971,
    5945,  2358,  2358,  2358,  2358,  5966,  5987,  6008,   842,    52,
    2301,  2301, -1050, -1050,   839,   840,  2301,  4011,  4037,  4063,
    3673,   297,    52,  2093,  2301,   977,  2301,  6029, -1050,  4913,
    4936, -1050,   583,  4959,  4982,   978,   979,   983,   847,  2301,
    2400,  2301,  2301, -1050,    28, -1050, -1050,  5005,    32, -1050,
    3057, -1050,   859,   860,   854, -1050,   989, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050,  2301,  2301, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,  2301,  2301,
    2301,  2301,  2301,  2301,  2301,   992, -1050,  2232,   480, -1050,
   -1050, -1050,  2301,  5028,   991,   994,   862, -1050,    41,  2301,
     995,   996,  2464, -1050,   997,   868,    10,   999, -1050,  2232,
    2232,  2232,  2232,  2301, -1050,   886,   480,    -4,  4089,    52,
   -1050,  2232,  3085,  2729,   775, -1050,   905, -1050,   959,  1537,
    1537,  1000,  1537,   697,  1537,  1537,  1004,   960,  1537,  1537,
     614, -1050,  2232,  2487,  1005,   875,  1007,  1009,  1010,  2165,
   -1050, -1050,  1027, -1050,  1028,   902,  6260, -1050,   907,   908,
     910,  1032,  1038,  1039,  1044,   309,  4115,  4141, -1050, -1050,
    3113,    52,    52,    52,  1043,   911,   917,   -17, -1050,   312,
   -1050,   297,  6260, -1050,  2507,   913,  1048,  1049,  1006,  1050,
    1052,  1537,  1537,  1537,  1055,  4167, -1050,  2749,   702,  1058,
    1060,  1062,  1067, -1050,  1066, -1050,   940,  2301,  2301,  1537,
     935, -1050,  6050,  5051,  6071,  5074,  6092,  5097,  6113,  5120,
    5143, -1050,    68,   942,  6134,   467, -1050, -1050,   199,   277,
     937,  1070,  2540, -1050, -1050, -1050,    10,  2301, -1050,   633,
   -1050,   643,   651,   655,   659,  6260, -1050,  1072,    48,  2301,
      50,   660, -1050,  2301,   939,  1022,  1022,  1537,  1076,   948,
     950,  1080,  1083,  1537,   955,  1085,  1086, -1050,   665, -1050,
    1088,  2301,  1537,  1537,  1537,  1092,  1091, -1050,  1537,  1093,
    1094,  1097,  1098,  1537,  1537,  1537,   317,  2301,  2301,  2301,
     967,   -74,   262,   282, -1050,  1537,  2301, -1050, -1050,  2100,
     188, -1050,  2232, -1050, -1050,   973, -1050, -1050,  1100,  1102,
    1008, -1050,  2301,  2301,  2301, -1050,  1105,  1108, -1050,   184,
   -1050,  2301,  4193,  4219,   668, -1050,  2301, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050,   980, -1050, -1050, -1050,  1537,
     542,  2301,  1112,  1116,    16, -1050,  1115,  5166,    10, -1050,
    1119,  1120,  1121,  1122, -1050, -1050,   480,  4245, -1050,   962,
    6260,  2301,    52,  1123,  1124,  1125, -1050,  2301,  2301, -1050,
   -1050,  1126,  2301, -1050, -1050, -1050,  1128,  4271,  1129,  1130,
    1042,  2301, -1050,  1134,  1537,  1537,  1537,  1537,  1135,   750,
    1136, -1050,  2358,  3141,  6155,  2973,    12,    52,  1137,    52,
    1138,    52,  1139,   349,  1011,  6176,  3169,   363, -1050,   669,
    2301, -1050, -1050,  1537,  3001,   644,  6197, -1050,  1933, -1050,
     140,  6260,  2301,  2301,  1537,  1012,   672,  6260,  1142,  1141,
    1143,  2560, -1050,  1127,  1147, -1050,  1018, -1050, -1050, -1050,
   -1050, -1050,  1150,  2301, -1050,  3197,   248, -1050, -1050, -1050,
    3225,  3253, -1050,  3281,  1153,  2301, -1050, -1050,  1099,  1154,
    6260, -1050,  1156,  1157,  1158,  1159, -1050,  1019, -1050, -1050,
    2586,  1160,  1030, -1050,  2301, -1050,  1026,   376, -1050,  1031,
     400, -1050,  1047,   407, -1050,  1056,  1162,  1537,  1182,  1057,
    2301,  1184,  3309,  1109,  2301, -1050,  2301, -1050, -1050,  2232,
    2609,  1186, -1050,  2301,  4297,  4323, -1050,  1537,  2301,  1189,
   -1050, -1050, -1050, -1050,    10, -1050,  1107, -1050,  4349,  1192,
    1195,  1196,  1200,  1201,  4375,  1068, -1050, -1050, -1050, -1050,
   -1050,  1537, -1050, -1050,    12,  3029, -1050,  2100,   297,  2100,
     297,  2100,   297, -1050,   673,  1537, -1050,  3337, -1050, -1050,
    2301,  3365,  3393,   696, -1050, -1050,  1071,  6260,  2301,  2301,
     720,  6260, -1050,  1204, -1050,  2301, -1050, -1050, -1050, -1050,
   -1050,  1207,  2301,   723,  1077,  2301, -1050,  3421,   414,   190,
    3449,   431,   198,  3477,   464,   263,  1537,  1211,  1149,  2456,
    1079,  2629, -1050, -1050,  1214,  2301,  6218,  4401,    21, -1050,
    4427,  1084,  3505,  1219, -1050,  3533,  1224,  2301,  1225,  1247,
    2301,  1248,  1249,  2301,  1250,  1117, -1050,  2301, -1050,   297,
   -1050, -1050, -1050,   727, -1050,  2301, -1050,  1537,  2301,  1252,
   -1050, -1050, -1050, -1050,  1131,  3561, -1050, -1050,  1132,  3589,
   -1050, -1050,  1133,  3617, -1050,  1253,  2662,   271,  2511,  1254,
    1140,  6239,   730,  3645,  1144,   297,  1255,   297,  1256,   297,
    1258, -1050, -1050, -1050, -1050,   297, -1050,   480, -1050,  1151,
    1259,  1261,   276, -1050,  1180,   319, -1050,  1181,   337, -1050,
    1183,   341,   747, -1050,  1188,  1537, -1050,  1148,  1262,   297,
    1263,   297,  1268,   297, -1050,   480,  1269,   480,   776,  1270,
   -1050,   352, -1050,   367, -1050,   371, -1050, -1050,   779, -1050,
    1271, -1050,  1272,  1273,  1275,   480,  1276, -1050, -1050, -1050,
   -1050, -1050, -1050
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1050, -1050, -1050, -1050,   426, -1050, -1050, -1050, -1050,   122,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050,  -273,    -2, -1050,    73, -1050,   484,  1290, -1050,
   -1050, -1050, -1050,     3,  -361,  -182, -1050, -1050, -1050, -1050,
   -1050,  1291, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050,  -648,  -546, -1050, -1050,   954,
   -1050, -1050, -1050, -1050,    -6, -1050,    23, -1050, -1049,   381,
    -115,   286,    35,  -637,   402, -1050,  -256,    40
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     131,   544,   545,   371,   130,   212,    67,   465,  1110,   190,
     381,   453,   454,   455,   202,   460,   284,   581,   280,   788,
     655,   137,   182,   214,   151,   183,   216,  1176,   184,   156,
     146,   399,  1123,   401,   151,   749,   450,   222,   205,     4,
     146,   377,     5,   378,   142,   779,   133,   344,   345,   360,
     361,   143,   664,   135,   905,   724,   908,   178,   180,   493,
     186,   725,   726,   136,   494,   947,   142,   948,   105,   106,
     107,   108,   374,   659,   109,   360,   361,   154,    33,    34,
      35,    36,   134,   850,   662,   636,    40,   360,   361,    43,
     637,   539,   147,   152,   139,   582,   583,   584,   585,   148,
     174,   175,   147,   661,   362,   191,   281,   282,   140,   660,
     176,   157,   141,   273,   274,   275,   155,   185,   276,   279,
     223,   461,   161,   288,   847,   162,   144,   163,  1202,   308,
     798,   285,   310,   780,   781,   503,   311,   317,   320,   321,
     213,   323,   317,   325,   326,   192,   317,   329,   330,   896,
     203,   337,   122,   123,   586,   138,   656,   217,   215,   218,
     145,  1177,   122,   123,   219,   750,   665,   206,   665,   752,
     358,   359,   379,   360,   361,   174,   175,   647,   193,   359,
     194,   848,   224,   324,   225,   176,  1248,   328,   360,   361,
     649,   553,   177,   387,   388,   389,   355,   391,   357,   149,
     394,   395,   886,   396,   364,   363,   647,   503,   372,   165,
     570,   403,   166,   150,   464,   167,   153,   168,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     724,   987,   724,   226,   456,   227,   725,   726,   725,   726,
     724,   228,   317,   229,  1052,   154,   725,   726,   466,  1053,
     115,   116,   117,   118,   890,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     122,   123,   158,   634,   848,   635,   159,   648,   499,   115,
     116,   117,   118,   462,   122,   123,   507,   115,   116,   117,
     118,   512,   754,   941,   942,   499,   317,   360,   361,   958,
     521,  1158,   523,   524,   525,   724,   160,   122,   123,  1161,
     530,   725,   726,   724,   373,   535,   536,   537,   724,   725,
     726,   164,   360,   361,   725,   726,   230,   501,   231,   547,
     548,   549,   273,   274,   550,   285,   285,   518,   546,   724,
     557,   360,   361,   559,   560,   725,   726,   317,   563,   564,
     172,   173,   773,   542,   543,   360,   361,   115,   116,   117,
     118,   724,   357,   302,   303,   304,   577,   725,   726,   580,
     305,   949,   579,   950,  1164,   360,   361,   122,   123,   724,
     797,   187,  1213,   724,   181,   725,   726,  1238,   562,   725,
     726,   951,   196,   952,   724,   360,   361,  1113,   188,   318,
     725,   726,   360,   361,   318,   360,   361,   189,   318,   724,
    1129,   552,  1132,   724,  1135,   725,   726,   195,   837,   725,
     726,   849,   643,   300,   301,   302,   303,   304,   197,   652,
    1240,   650,   305,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   519,   303,   304,   232,  1242,   233,
     198,   305,  1244,   199,   450,   222,   360,   361,   317,   668,
    1036,   643,   672,  1262,   200,   673,   674,   676,   169,   360,
     361,   170,  1040,   171,   651,   889,   891,   234,  1263,   235,
     317,   201,  1264,   674,   693,  1087,   105,   106,   107,   108,
     699,  1197,   109,   360,   361,   706,   706,   706,   706,   667,
     360,   361,   208,   209,   716,   717,   334,   360,   361,  1089,
     720,   207,   342,   342,   342,   210,  1091,   222,   732,   221,
     734,   690,   266,  1157,   360,   361,   236,  1222,   237,  1225,
     211,  1228,   715,   745,   318,   747,   748,  1231,   342,   375,
    1160,   707,   707,   707,   707,   729,   753,   267,   105,   106,
     107,   108,   268,   848,   109,  1026,   848,   360,   361,   848,
     238,  1251,   239,  1253,   240,  1255,   241,   122,   123,   242,
     500,   243,   269,  1163,   752,   708,   709,   710,   762,   763,
     244,   246,   245,   247,   248,   270,   249,   500,   318,   271,
     283,   290,   764,   765,   766,   767,   768,   769,   770,   289,
     306,   317,   122,   123,   307,   309,   774,   497,   250,   218,
     251,   322,   128,   782,   219,   252,   254,   253,   255,   327,
     992,   848,  1046,   317,   317,   317,   317,   795,   336,   122,
     123,   256,   338,   257,   458,   317,   218,   339,   258,   318,
     259,   219,   772,   260,   354,   261,   848,   340,   262,   848,
     263,   264,   848,   265,   346,   848,   317,   351,   503,   503,
     504,   509,   800,   365,   791,   792,   793,   794,   503,   503,
     513,   646,   503,   352,   691,   848,   801,   848,   353,   848,
     864,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   503,  1124,   738,   366,   305,   818,   367,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   376,   841,   842,   843,   305,   809,   382,
     810,   872,   873,   503,  1017,   817,  1018,   380,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   898,   753,   899,   383,   305,   892,   386,   390,
     318,   897,   503,   476,   900,  1047,   392,   384,   675,   677,
     503,   385,   901,   907,   503,   393,   902,   910,   503,   503,
     903,   909,   318,   397,   503,   675,   925,   974,   503,   975,
    1041,  1058,  1136,  1059,  1137,   927,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     398,   943,   944,   945,   305,   503,   865,  1144,   400,   953,
     955,   644,   645,   956,   402,   404,   317,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   964,   965,   966,   974,
     305,  1148,   974,   407,  1153,   971,  1058,   969,  1199,   974,
     977,  1219,   957,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   981,  1245,   959,  1246,   305,
     457,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   995,   405,   305,   700,   305,
     467,  1000,  1001,   501,  1139,   974,  1003,  1260,  1265,   468,
    1266,   469,   128,   318,   470,  1010,   520,   498,   526,   527,
     980,   531,   532,   533,   534,   996,  1020,   538,   554,   556,
     558,   568,   571,   638,   639,   318,   318,   318,   318,   285,
     640,   642,   653,   654,  1042,   658,   678,   318,   669,   679,
     680,  1233,  1050,   682,   683,   684,  1054,  1055,   685,   687,
    1027,   688,  1030,   689,  1033,   695,   701,   703,   318,   714,
     718,   719,  1021,   733,   744,   741,   742,  1068,  1198,  1256,
     743,  1259,   757,   758,   759,   761,   771,   776,   778,  1074,
     777,   783,   784,   787,   786,   790,   796,   807,  1051,  1271,
     804,   813,   820,   814,   822,   821,   823,   824,  1085,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     502,   303,   304,   827,  1097,   828,   829,   305,  1101,   833,
    1102,   830,   831,   317,   832,   834,   835,  1107,   836,   844,
     846,   845,  1111,   852,   853,   854,   856,   855,   857,   861,
     805,   806,   866,   808,   867,   811,   812,   501,   868,   815,
     816,   869,   870,   871,   893,   876,   887,   894,   904,   911,
     912,  1127,   916,  1130,  1103,  1133,   919,   285,   917,   920,
     918,   923,   924,   926,  1141,   922,   931,   932,   994,   963,
     934,   935,  1146,  1147,   936,   937,   961,   946,   962,  1150,
    1128,   967,  1131,   960,  1134,   968,  1152,   978,   982,  1155,
     983,   985,   858,   859,   860,   988,   989,   990,   991,   997,
     998,   999,  1002,  1004,  1064,  1006,  1007,  1008,   318,   977,
    1011,  1016,  1019,  1028,  1031,  1034,  1060,  1061,  1075,  1062,
    1037,  1185,  1057,  1065,  1189,  1066,  1067,  1193,  1073,  1081,
    1076,  1196,  1077,  1078,  1079,  1080,  1083,  1086,  1093,  1201,
    1084,  1088,  1203,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   519,   303,   304,  1090,   915,  1095,
    1098,   305,  1105,   492,   921,  1112,  1092,  1096,  1116,  1100,
    1114,  1117,  1118,   928,   929,   930,  1119,  1120,  1122,   933,
    1149,  1145,  1151,  1167,   938,   939,   940,  1166,  1154,  1170,
    1172,    77,   312,  1179,   906,  1181,   954,    81,    82,    83,
    1183,  1186,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,  1187,  1190,  1191,  1194,  1204,  1195,  1211,
    1216,  1223,  1226,   313,  1229,  1236,  1237,  1173,  1250,  1252,
     979,  1205,  1207,  1209,  1254,  1257,  1261,  1267,  1268,  1269,
    1217,  1270,  1272,  1221,    33,    34,    35,    36,    37,  1249,
     914,  1235,    40,    66,    73,    43,   984,     0,     0,   529,
       0,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,  1012,  1013,  1014,  1015,   305,
    1239,  1241,     0,  1243,   111,   112,   113,   114,  1247,     0,
       0,     0,     0,     0,     0,   318,     0,     0,     0,     0,
       0,   119,   314,     0,  1043,     0,   121,     0,     0,     0,
       0,   124,     0,     0,     0,  1056,   127,     0,     0,   517,
      77,    78,    79,     0,    80,     0,    81,    82,    83,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,   105,   106,   107,   108,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,    77,   312,
     341,     0,     0,     0,    81,    82,    83,     0,  1094,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     313,     0,     0,     0,     0,     0,     0,   110,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,    33,    34,    35,    36,    37,  1138,     0,     0,    40,
     119,   120,    43,     0,     0,   121,     0,   122,   123,     0,
     124,     0,   125,     0,   126,   127,     0,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,   112,   113,   114,     0,     0,  1165,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,   331,
       0,     0,     0,   121,     0,     0,     0,     0,   124,     0,
      77,   312,     0,   127,     0,   332,    81,    82,    83,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   313,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,     0,     0,
       0,    40,     0,     0,    43,     0,     0,     0,     0,     0,
     471,    15,    16,   472,    18,    19,   473,    21,   474,    23,
       0,    24,     0,    26,    27,     0,    29,    30,    31,     0,
       0,     0,     0,   111,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,   331,    47,    48,    49,   121,     0,     0,     0,     0,
     124,     0,    77,   312,     0,   127,     0,   332,    81,    82,
      83,     0,     0,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   313,     0,   561,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,     0,     0,    40,     0,     0,    43,     0,     0,     0,
       0,     0,   471,    15,    16,   472,    18,    19,   473,    21,
     474,    23,     0,    24,     0,    26,    27,     0,    29,    30,
      31,     0,     0,     0,     0,   111,   112,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   314,    47,    48,    49,   121,     0,     0,
       0,     0,   124,     0,    77,   312,     0,   127,     0,   516,
      81,    82,    83,     0,     0,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   313,     0,   575,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,     0,    77,   272,    40,     0,     0,    43,    81,
      82,    83,     0,     0,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,   111,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   314,     0,     0,     0,   121,
       0,     0,     0,     0,   124,     0,    77,   272,   222,   127,
       0,   692,    81,    82,    83,     0,     0,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,   105,
     106,   107,   108,     0,     0,   109,   111,   112,   113,   114,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,   119,   120,     0,     0,     0,   121,     0,
       0,     0,     0,   124,     0,     0,   277,     0,   127,     0,
     278,     0,     0,     0,     0,     0,   471,    15,    16,   472,
      18,    19,   473,    21,   474,    23,     0,    24,     0,    26,
      27,     0,    29,    30,    31,     0,     0,     0,     0,   111,
     112,   113,   114,     0,     0,     0,     0,     0,     0,   641,
       0,     0,     0,     0,     0,     0,   119,   120,    47,    48,
      49,   121,     0,     0,     0,     0,   124,     0,    77,   272,
       0,   127,     0,  1049,    81,    82,    83,     0,     0,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,     0,    77,   272,     7,     8,     0,     0,    81,
      82,    83,   576,     0,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,   471,    15,
      16,   472,    18,    19,   473,    21,   474,    23,     0,    24,
       0,    26,    27,     0,    29,    30,    31,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   111,   112,   113,   114,   305,     0,     0,     0,     0,
      47,    48,    49,     0,     0,     0,     0,     0,   119,   120,
       0,     0,     0,   121,     0,     0,     0,     0,   124,     0,
       0,   670,     0,   127,     0,   671,   111,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   368,   369,     0,     0,     0,   121,   825,
       0,     0,     0,   370,   730,    77,   312,     0,   127,     0,
     177,    81,    82,    83,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   313,     0,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,    33,    34,
      35,    36,    37,     0,    77,   272,    40,     0,     0,    43,
      81,    82,    83,     0,     0,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,   111,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   119,   314,     0,     0,     0,
     121,    77,   272,   222,     0,   124,     0,    81,    82,    83,
     127,     0,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,   106,   107,   108,     0,     0,
     109,     0,     0,     0,     0,     0,     0,   111,   112,   113,
     114,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   120,     0,     0,     0,   121,
       0,     0,     0,     0,   124,     0,     0,     0,     0,   127,
       0,     0,     0,     0,     0,   471,    15,    16,   472,    18,
      19,   473,    21,   474,    23,     0,    24,     0,    26,    27,
       0,    29,    30,    31,   111,   112,   113,   114,     7,     8,
     785,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,   120,     0,     0,     0,   121,    47,    48,    49,
       0,   124,     0,   819,     0,     0,   127,     0,     0,     0,
       0,   471,    15,    16,   472,    18,    19,   473,    21,   474,
      23,     0,    24,   851,    26,    27,     0,    29,    30,    31,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   746,     0,    47,    48,    49,   895,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   471,    15,    16,   472,
      18,    19,   473,    21,   474,    23,  1063,    24,     0,    26,
      27,     0,    29,    30,    31,     0,     0,     0,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,  1082,     0,     0,     0,   305,  1168,    47,    48,
      49,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,  1104,     0,     0,     0,   305,
       0,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,  1171,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1214,     0,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,  1212,     0,
       0,     0,   305,     0,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,     0,   572,
       0,     0,   305,     0,     0,     0,     0,     0,     0,     0,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   663,     0,     0,     0,   305,     0,
       0,     0,     0,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   803,     0,     0,
       0,   305,     0,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   863,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
       0,     0,     0,     0,   305,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,     0,     0,     0,     0,   305,     0,
       0,     0,     0,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,    -4,     1,
       0,   305,    -4,     0,     0,     0,     0,     0,     0,     0,
      -4,    -4,     0,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,    -4,     0,     0,     0,     0,    -4,    -4,
     696,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,
       6,     0,     0,     0,    -4,    -4,    -4,    -4,     7,     8,
      -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     0,     0,     0,     0,
       0,     9,     0,     0,     0,     0,    10,    11,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,     0,    38,    39,
      40,    41,    42,    43,     7,     8,    44,    45,     0,     0,
       0,     0,    46,    47,    48,    49,     0,     0,    50,     0,
      51,     0,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,     0,     0,     0,     0,     0,   471,    15,    16,
     472,    18,    19,   473,    21,   474,    23,     0,    24,     0,
      26,    27,     0,    29,    30,    31,     0,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,     0,     0,    47,
      48,    49,  1024,     0,  1025,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
    1044,     0,  1045,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,  1125,     0,
    1126,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,   755,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,     0,     0,   802,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,     0,     0,   840,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
       0,     0,  1022,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
    1039,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,  1069,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,     0,     0,  1070,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,     0,     0,  1071,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
       0,     0,  1072,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
    1099,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,  1140,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,     0,     0,  1142,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,     0,     0,  1143,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
       0,     0,  1156,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
    1159,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,  1162,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,     0,     0,  1180,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,     0,     0,  1182,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
       0,     0,  1206,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
    1208,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,  1210,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,     0,     0,  1220,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,   459,     0,     0,
       0,     0,   540,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,   495,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,   540,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
     541,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,   569,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,   614,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,   615,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,   628,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
     629,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,   630,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,   631,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,   632,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,   633,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
     721,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,   722,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,   723,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,   799,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,   838,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
     839,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,   862,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,   972,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,   973,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,   993,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
    1005,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,  1108,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,  1109,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,  1115,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,  1121,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
    1175,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,  1178,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,     0,     0,   463,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,     0,     0,     0,     0,   305,     0,
       0,     0,   574,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,     0,     0,   578,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
       0,     0,     0,     0,   305,     0,     0,     0,   593,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,     0,
       0,   595,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,     0,     0,     0,     0,
     305,     0,     0,     0,   597,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,   599,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,     0,     0,     0,     0,   305,     0,     0,     0,
     601,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,     0,     0,   603,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,     0,     0,
       0,     0,   305,     0,     0,     0,   605,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,     0,     0,   607,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,     0,     0,     0,     0,   305,     0,
       0,     0,   609,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,     0,     0,   611,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
       0,     0,     0,     0,   305,     0,     0,     0,   613,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,     0,
       0,   617,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,     0,     0,     0,     0,
     305,     0,     0,     0,   619,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,   621,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,     0,     0,     0,     0,   305,     0,     0,     0,
     623,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,     0,     0,   625,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,     0,     0,
       0,     0,   305,     0,     0,     0,   627,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,     0,     0,   736,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,     0,     0,     0,     0,   305,     0,
       0,     0,   737,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,     0,     0,   739,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
       0,     0,     0,     0,   305,     0,     0,     0,   740,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,     0,
       0,   751,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,     0,     0,     0,     0,
     305,     0,     0,     0,   775,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,     0,     0,   878,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,     0,     0,     0,     0,   305,     0,     0,     0,
     880,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,     0,     0,   882,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,     0,     0,
       0,     0,   305,     0,     0,     0,   884,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,     0,     0,   885,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,     0,     0,     0,     0,   305,     0,
       0,     0,   986,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,   459,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,     0,     0,
       0,     0,   305,     0,   496,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,   505,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
       0,     0,     0,     0,   305,     0,   506,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,   508,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,     0,     0,     0,     0,   305,     0,   510,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,   511,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,     0,     0,     0,     0,   305,     0,
     514,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,   515,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,     0,     0,     0,     0,
     305,     0,   522,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,   565,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,     0,     0,
       0,     0,   305,     0,   566,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,   567,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
       0,     0,     0,     0,   305,     0,   573,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,   592,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,     0,     0,     0,     0,   305,     0,   594,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,   596,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,     0,     0,     0,     0,   305,     0,
     598,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,   600,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,     0,     0,     0,     0,
     305,     0,   602,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,   604,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,     0,     0,
       0,     0,   305,     0,   606,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,   608,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
       0,     0,     0,     0,   305,     0,   610,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,   612,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,     0,     0,     0,     0,   305,     0,   616,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,   618,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,     0,     0,     0,     0,   305,     0,
     620,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,   622,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,     0,     0,     0,     0,
     305,     0,   624,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,   626,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,     0,     0,
       0,     0,   305,     0,   681,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,   686,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
       0,     0,     0,     0,   305,     0,   694,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,   697,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,     0,     0,     0,     0,   305,     0,   698,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,   704,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,     0,     0,     0,     0,   305,     0,
     711,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,   712,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,     0,     0,     0,     0,
     305,     0,   713,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,   735,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,     0,     0,
       0,     0,   305,     0,   877,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   305,     0,   879,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
       0,     0,     0,     0,   305,     0,   881,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,     0,     0,     0,     0,   305,     0,   883,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,     0,     0,     0,     0,   305,     0,   888,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,     0,     0,     0,     0,   305,     0,  1023,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,     0,     0,     0,     0,   305,     0,
    1038,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,     0,     0,     0,     0,   305,
       0,  1048,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,     0,     0,     0,     0,
     305,     0,  1174,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,     0,     0,     0,
       0,   305,     0,  1218,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,     0,     0,
       0,     0,   305
};

static const yytype_int16 yycheck[] =
{
       6,   362,   363,   185,     6,     5,     3,   280,  1057,     4,
     192,   267,   268,   269,     4,     7,     4,     4,     4,   656,
       4,     6,    45,     5,    71,    48,     4,     6,    51,    51,
      71,   213,  1081,   215,    71,     7,     4,     5,     4,     6,
      71,     4,     0,     6,   133,     4,     6,   162,   163,   123,
     124,   140,     6,    51,     6,    72,     6,    34,    35,   134,
      37,    78,    79,   133,   139,   139,   133,   141,    36,    37,
      38,    39,   187,   140,    42,   123,   124,   133,    66,    67,
      68,    69,    13,   731,   140,   134,    74,   123,   124,    77,
     139,   139,   133,   140,     6,    82,    83,    84,    85,   140,
     123,   124,   133,   140,   140,   100,    92,    93,     6,   140,
     133,   133,     6,   119,   120,   121,    55,   140,   124,   125,
      80,   113,    48,   129,   141,    51,   133,    53,  1177,   135,
     134,   128,   138,    92,    93,   139,   142,   143,   144,   145,
     140,   147,   148,   149,   150,   140,   152,   153,   154,   786,
     140,   157,   130,   131,   141,   140,   140,   135,   140,   137,
     133,   140,   130,   131,   142,   137,   120,   133,   120,   137,
     176,   177,   135,   123,   124,   123,   124,     7,     4,   185,
       6,   727,   133,   148,   135,   133,  1235,   152,   123,   124,
     463,   373,   140,   199,   200,   201,   173,   203,   175,   133,
     206,   207,   134,   209,   181,   140,     7,   139,   185,    45,
     392,   217,    48,   133,     7,    51,   133,    53,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
      72,   898,    72,   133,   270,   135,    78,    79,    78,    79,
      72,   133,   278,   135,   134,   133,    78,    79,   280,   139,
     110,   111,   112,   113,     7,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     130,   131,    51,   135,   850,   137,    51,   137,   314,   110,
     111,   112,   113,   278,   130,   131,   322,   110,   111,   112,
     113,   327,   578,     6,     7,   331,   332,   123,   124,   141,
     336,   141,   338,   339,   340,    72,    51,   130,   131,   141,
     346,    78,    79,    72,   140,   351,   352,   353,    72,    78,
      79,    53,   123,   124,    78,    79,   133,     8,   135,   365,
     366,   367,   368,   369,   370,   362,   363,   332,   139,    72,
     376,   123,   124,   379,   380,    78,    79,   383,   384,   385,
     133,   140,   638,   360,   361,   123,   124,   110,   111,   112,
     113,    72,   369,   125,   126,   127,   402,    78,    79,   405,
     132,   139,   404,   141,   141,   123,   124,   130,   131,    72,
     666,    51,   141,    72,   140,    78,    79,   141,   383,    78,
      79,   139,     4,   141,    72,   123,   124,  1064,    51,   143,
      78,    79,   123,   124,   148,   123,   124,    48,   152,    72,
    1088,   139,  1090,    72,  1092,    78,    79,    48,   139,    78,
      79,   139,   458,   123,   124,   125,   126,   127,     4,   465,
     141,   463,   132,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   133,   141,   135,
       4,   132,   141,   133,     4,     5,   123,   124,   494,   495,
     141,   497,   498,   141,   133,   501,   502,   503,    48,   123,
     124,    51,   139,    53,   464,   778,   779,   133,   141,   135,
     516,   133,   141,   519,   520,   139,    36,    37,    38,    39,
     526,  1169,    42,   123,   124,   531,   532,   533,   534,   494,
     123,   124,     6,   135,   540,   541,   155,   123,   124,   139,
     546,   133,   161,   162,   163,     4,   139,     5,   554,   140,
     556,   516,   133,   139,   123,   124,   133,  1205,   135,  1207,
       4,  1209,   539,   569,   278,   571,   572,  1215,   187,   188,
     139,   531,   532,   533,   534,   552,   578,   133,    36,    37,
      38,    39,   133,  1129,    42,   946,  1132,   123,   124,  1135,
     133,  1239,   135,  1241,   133,  1243,   135,   130,   131,   133,
     314,   135,   133,   139,   137,   532,   533,   534,   614,   615,
     133,   133,   135,   135,   133,     7,   135,   331,   332,   133,
       4,     6,   628,   629,   630,   631,   632,   633,   634,     6,
       6,   637,   130,   131,     6,     5,   642,   135,   133,   137,
     135,   133,   140,   649,   142,   133,   133,   135,   135,   133,
     906,  1197,     8,   659,   660,   661,   662,   663,   133,   130,
     131,   133,   140,   135,   135,   671,   137,   133,   133,   383,
     135,   142,   637,   133,     4,   135,  1222,   133,   133,  1225,
     135,   133,  1228,   135,   133,  1231,   692,   133,   139,   139,
     141,   141,   669,   140,   659,   660,   661,   662,   139,   139,
     141,   141,   139,   133,   141,  1251,   671,  1253,   133,  1255,
       8,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   139,  1084,   141,   140,   132,   692,   140,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   133,   721,   722,   723,   132,    51,     6,
      53,   757,   758,   139,     4,   141,     6,   135,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   139,   775,   141,   140,   132,   779,     6,   137,
     494,   787,   139,     6,   141,   141,   140,   135,   502,   503,
     139,   135,   141,   799,   139,    95,   141,   803,   139,   139,
     141,   141,   516,     6,   139,   519,   141,   139,   139,   141,
     141,   139,   139,   141,   141,   821,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       6,   837,   838,   839,   132,   139,   134,   141,     6,   845,
     846,   460,   461,   849,   135,     4,   852,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   862,   863,   864,   139,
     132,   141,   139,     6,   141,   871,   139,   869,   141,   139,
     876,   141,   849,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   891,   139,   852,   141,   132,
       5,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   911,   140,   132,   527,   132,
     137,   917,   918,     8,  1096,   139,   922,   141,   139,     7,
     141,   135,   140,   637,   141,   931,     7,   140,     7,     7,
     890,   133,   133,   133,   133,   912,   942,   134,     7,     7,
       6,    92,   140,   139,   134,   659,   660,   661,   662,   946,
     134,   139,     6,     4,   960,   136,    95,   671,     7,     7,
       7,  1217,   968,     7,    95,     7,   972,   973,     7,    95,
     947,     7,   949,     7,   951,     7,     4,     6,   692,   137,
     141,   141,   942,     6,   137,     7,     7,   993,  1170,  1245,
       7,  1247,   133,   133,   140,     6,     4,     6,   136,  1005,
       6,     6,     6,   135,     7,     6,   120,     7,   968,  1265,
      51,     7,     7,    53,     7,   140,     7,     7,  1024,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,     6,  1040,     7,   134,   132,  1044,     7,
    1046,   134,   134,  1049,   134,     7,     7,  1053,     4,     6,
     133,   140,  1058,   140,     6,     6,     6,    51,     6,     4,
     679,   680,     4,   682,     4,   684,   685,     8,     6,   688,
     689,     4,     6,   133,   137,   140,   134,     7,     6,   140,
      58,  1087,     6,  1089,  1049,  1091,     6,  1084,   140,     6,
     140,     6,     6,     5,  1100,   140,     4,     6,   136,    91,
       7,     7,  1108,  1109,     7,     7,     6,   140,     6,  1115,
    1087,     6,  1089,   140,  1091,     7,  1122,   137,     6,  1125,
       4,     6,   741,   742,   743,     6,     6,     6,     6,     6,
       6,     6,     6,     5,     7,     6,     6,    95,   852,  1145,
       6,     6,     6,     6,     6,     6,     4,     6,    49,     6,
     139,  1157,   140,     6,  1160,   137,     6,  1163,     5,   140,
       6,  1167,     6,     6,     6,     6,     6,   141,     6,  1175,
     140,   140,  1178,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   140,   807,     7,
       6,   132,     6,     6,   813,     6,   140,   140,     6,    90,
      93,     6,     6,   822,   823,   824,     6,     6,   140,   828,
       6,   140,     5,    64,   833,   834,   835,     6,   141,   140,
       6,     3,     4,   139,   798,     6,   845,     9,    10,    11,
       6,     6,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     6,     6,     6,     6,     5,   141,     6,
       6,     6,     6,    45,     6,     6,     5,  1145,     6,     6,
     889,   140,   140,   140,     6,     6,     6,     6,     6,     6,
     140,     6,     6,   139,    66,    67,    68,    69,    70,   141,
     806,   140,    74,     3,     3,    77,   894,    -1,    -1,   345,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   934,   935,   936,   937,   132,
     140,   140,    -1,   140,   106,   107,   108,   109,   140,    -1,
      -1,    -1,    -1,    -1,    -1,  1049,    -1,    -1,    -1,    -1,
      -1,   123,   124,    -1,   963,    -1,   128,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,   974,   138,    -1,    -1,   141,
       3,     4,     5,    -1,     7,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    -1,  1037,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,
      -1,    -1,    -1,   106,   107,   108,   109,   110,   111,   112,
     113,    66,    67,    68,    69,    70,  1095,    -1,    -1,    74,
     123,   124,    77,    -1,    -1,   128,    -1,   130,   131,    -1,
     133,    -1,   135,    -1,   137,   138,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   106,   107,   108,   109,    -1,    -1,  1136,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,   133,    -1,
       3,     4,    -1,   138,    -1,   140,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    -1,    58,    59,    -1,    61,    62,    63,    -1,
      -1,    -1,    -1,   106,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,    87,    88,    89,   128,    -1,    -1,    -1,    -1,
     133,    -1,     3,     4,    -1,   138,    -1,   140,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,   141,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    -1,    58,    59,    -1,    61,    62,
      63,    -1,    -1,    -1,    -1,   106,   107,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,    87,    88,    89,   128,    -1,    -1,
      -1,    -1,   133,    -1,     3,     4,    -1,   138,    -1,   140,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    -1,     3,     4,    74,    -1,    -1,    77,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,   106,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,   133,    -1,     3,     4,     5,   138,
      -1,   140,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    38,    39,    -1,    -1,    42,   106,   107,   108,   109,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,    -1,    -1,    -1,   128,    -1,
      -1,    -1,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    -1,    58,
      59,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,    87,    88,
      89,   128,    -1,    -1,    -1,    -1,   133,    -1,     3,     4,
      -1,   138,    -1,   140,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,     3,     4,    12,    13,    -1,    -1,     9,
      10,    11,   141,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      -1,    58,    59,    -1,    61,    62,    63,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   106,   107,   108,   109,   132,    -1,    -1,    -1,    -1,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,   123,   124,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,   136,    -1,   138,    -1,   140,   106,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,    -1,    -1,    -1,   128,    64,
      -1,    -1,    -1,   133,   141,     3,     4,    -1,   138,    -1,
     140,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    66,    67,
      68,    69,    70,    -1,     3,     4,    74,    -1,    -1,    77,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,    -1,    -1,    -1,
     128,     3,     4,     5,    -1,   133,    -1,     9,    10,    11,
     138,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,
     109,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    -1,    58,    59,
      -1,    61,    62,    63,   106,   107,   108,   109,    12,    13,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,    -1,    -1,    -1,   128,    87,    88,    89,
      -1,   133,    -1,     6,    -1,    -1,   138,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,     6,    58,    59,    -1,    61,    62,    63,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,    -1,    87,    88,    89,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,     6,    56,    -1,    58,
      59,    -1,    61,    62,    63,    -1,    -1,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     6,    -1,    -1,    -1,   132,   141,    87,    88,
      89,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,     6,    -1,    -1,    -1,   132,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,     6,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     6,    -1,
      -1,    -1,   132,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    -1,     8,
      -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     8,    -1,    -1,    -1,   132,    -1,
      -1,    -1,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     8,    -1,    -1,
      -1,   132,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     8,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
      -1,    -1,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,     0,     1,
      -1,   132,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    35,    -1,    -1,    -1,    -1,    40,    41,
     141,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    69,    70,    -1,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
       4,    -1,    -1,    -1,    86,    87,    88,    89,    12,    13,
      92,    -1,    94,    -1,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    70,    -1,    72,    73,
      74,    75,    76,    77,    12,    13,    80,    81,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    -1,    -1,    92,    -1,
      94,    -1,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    -1,
      58,    59,    -1,    61,    62,    63,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    87,
      88,    89,   139,    -1,   141,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
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
      -1,    -1,   132
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   144,   145,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    56,    57,    58,    59,    60,    61,
      62,    63,    65,    66,    67,    68,    69,    70,    72,    73,
      74,    75,    76,    77,    80,    81,    86,    87,    88,    89,
      92,    94,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   146,   148,   149,   167,   171,   176,   179,   180,
     181,   182,   183,   184,   204,   205,   206,     3,     4,     5,
       7,     9,    10,    11,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    36,    37,    38,    39,    42,
     100,   106,   107,   108,   109,   110,   111,   112,   113,   123,
     124,   128,   130,   131,   133,   135,   137,   138,   140,   165,
     166,   207,   208,   220,    13,    51,   133,     6,   140,     6,
       6,     6,   133,   140,   133,   133,    71,   133,   140,   133,
     133,    71,   140,   133,   133,    55,    51,   133,    51,    51,
      51,    48,    51,    53,    53,    45,    48,    51,    53,    48,
      51,    53,   133,   140,   123,   124,   133,   140,   209,   210,
     209,   140,    45,    48,    51,   140,   209,    51,    51,    48,
       4,   100,   140,     4,     6,    48,     4,     4,     4,   133,
     133,   133,     4,   140,   216,     4,   133,   133,     6,   135,
       4,     4,     5,   140,     5,   140,     4,   135,   137,   142,
     166,   140,     5,   220,   133,   135,   133,   135,   133,   135,
     133,   135,   133,   135,   133,   135,   133,   135,   133,   135,
     133,   135,   133,   135,   133,   135,   133,   135,   133,   135,
     133,   135,   133,   135,   133,   135,   133,   135,   133,   135,
     133,   135,   133,   135,   133,   135,   133,   133,   133,   133,
       7,   133,     4,   207,   207,   207,   207,   136,   140,   207,
       4,    92,    93,     4,     4,   176,   177,   178,   207,     6,
       6,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   132,     6,     6,   207,     5,
     207,   207,     4,    45,   124,   176,   184,   207,   214,   215,
     207,   207,   133,   207,   215,   207,   207,   133,   215,   207,
     207,   124,   140,   207,   212,   214,   133,   207,   140,   133,
     133,     5,   212,   213,   213,   213,   133,   172,   173,   174,
     175,   133,   133,   133,     4,   209,   209,   209,   207,   207,
     123,   124,   140,   140,   209,   140,   140,   140,   123,   124,
     133,   178,   209,   140,   213,   212,   133,     4,     6,   135,
     135,   178,     6,   140,   135,   135,     6,   207,   207,   207,
     137,   207,   140,    95,   207,   207,   207,     6,     6,   178,
       6,   178,   135,   207,     4,   140,   150,     6,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
       4,   219,   220,   219,   219,   219,   207,     5,   135,   134,
       7,   113,   215,   136,     7,   165,   166,   137,     7,   135,
     141,    45,    48,    51,    53,   171,     6,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,     6,   134,   139,   139,   134,   135,   140,   207,
     214,     8,   125,   139,   141,   134,   134,   207,   134,   141,
     134,   134,   207,   141,   134,   134,   140,   141,   215,   125,
       7,   207,   134,   207,   207,   207,     7,     7,   202,   202,
     207,   133,   133,   133,   133,   207,   207,   207,   134,   139,
     139,   139,   209,   209,   177,   177,   139,   207,   207,   207,
     207,   188,   139,   178,     7,   203,     7,   207,     6,   207,
     207,   141,   215,   207,   207,   134,   134,   134,    92,   139,
     178,   140,     8,   134,   136,   141,   141,   207,   136,   166,
     207,     4,    82,    83,    84,    85,   141,   153,   157,   160,
     162,   163,   134,   136,   134,   136,   134,   136,   134,   136,
     134,   136,   134,   136,   134,   136,   134,   136,   134,   136,
     134,   136,   134,   136,   139,   139,   134,   136,   134,   136,
     134,   136,   134,   136,   134,   136,   134,   136,   139,   139,
     139,   139,   139,   139,   135,   137,   134,   139,   139,   134,
     134,     6,   139,   207,   212,   212,   141,     7,   137,   165,
     166,   220,   207,     6,     4,     4,   140,   217,   136,   140,
     140,   140,   140,     8,     6,   120,   147,   215,   207,     7,
     136,   140,   207,   207,   207,   214,   207,   214,    95,     7,
       7,   134,     7,    95,     7,     7,   134,    95,     7,     7,
     215,   141,   140,   207,   134,     7,   141,   134,   134,   207,
     212,     4,   201,     6,   134,   168,   207,   220,   168,   168,
     168,   134,   134,   134,   137,   209,   207,   207,   141,   141,
     207,   139,   139,   139,    72,    78,    79,   198,   199,   209,
     141,   185,   207,     6,   207,   134,   136,   136,   141,   136,
     136,     7,     7,     7,   137,   207,   141,   207,   207,     7,
     137,   136,   137,   166,   219,   141,   154,   133,   133,   140,
     164,     6,   207,   207,   207,   207,   207,   207,   207,   207,
     207,     4,   215,   219,   207,   136,     6,     6,   136,     4,
      92,    93,   207,     6,     6,     6,     7,   135,   216,   218,
       6,   215,   215,   215,   215,   207,   120,   219,   134,   139,
     209,   215,   141,     8,    51,   212,   212,     7,   212,    51,
      53,   212,   212,     7,    53,   212,   212,   141,   215,     6,
       7,   140,     7,     7,     7,    64,   200,     6,     7,   134,
     134,   134,   134,     7,     7,     7,     4,   139,   139,   139,
     141,   209,   209,   209,     6,   140,   133,   141,   199,   139,
     198,     6,   140,     6,     6,    51,     6,     6,   212,   212,
     212,     4,   139,     8,     8,   134,     4,     4,     6,     4,
       6,   133,   207,   207,   211,   212,   140,   134,   136,   134,
     136,   134,   136,   134,   136,   136,   134,   134,   134,   165,
       7,   165,   166,   137,     7,     6,   216,   207,   139,   141,
     141,   141,   141,   141,     6,     6,   147,   207,     6,   141,
     207,   140,    58,   170,   170,   212,     6,   140,   140,     6,
       6,   212,   140,     6,     6,   141,     5,   207,   212,   212,
     212,     4,     6,   212,     7,     7,     7,     7,   212,   212,
     212,     6,     7,   207,   207,   207,   140,   139,   141,   139,
     141,   139,   141,   207,   212,   207,   207,   209,   141,   215,
     140,     6,     6,    91,   207,   207,   207,     6,     7,   166,
     151,   207,   139,   139,   139,   141,   152,   207,   137,   212,
     220,   207,     6,     4,   217,     6,   136,   216,     6,     6,
       6,     6,   219,   139,   136,   207,   209,     6,     6,     6,
     207,   207,     6,   207,     5,   139,     6,     6,    95,   169,
     207,     6,   212,   212,   212,   212,     6,     4,     6,     6,
     207,   220,   141,   134,   139,   141,   177,   209,     6,   189,
     209,     6,   190,   209,     6,   191,   141,   139,   134,   141,
     139,   141,   207,   212,   139,   141,     8,   141,   134,   140,
     207,   220,   134,   139,   207,   207,   212,   140,   139,   141,
       4,     6,     6,     6,     7,     6,   137,     6,   207,   141,
     141,   141,   141,     5,   207,    49,     6,     6,     6,     6,
       6,   140,     6,     6,   140,   207,   141,   139,   140,   139,
     140,   139,   140,     6,   212,     7,   140,   207,     6,   141,
      90,   207,   207,   215,     6,     6,   155,   207,   139,   139,
     211,   207,     6,   216,    93,   139,     6,     6,     6,     6,
       6,   139,   140,   211,   177,   139,   141,   207,   209,   198,
     207,   209,   198,   207,   209,   198,   139,   141,   212,   178,
     141,   207,   141,   141,   141,   140,   207,   207,   141,     6,
     207,     5,   207,   141,   141,   207,   141,   139,   141,   141,
     139,   141,   141,   139,   141,   212,     6,    64,   141,   186,
     140,     6,     6,   152,   134,   139,     6,   140,   139,   139,
     141,     6,   141,     6,   192,   207,     6,     6,   193,   207,
       6,     6,   194,   207,     6,   141,   207,   198,   178,   141,
     158,   207,   211,   207,     5,   140,   141,   140,   141,   140,
     141,     6,     6,   141,   141,   187,     6,   140,   134,   141,
     141,   139,   198,     6,   195,   198,     6,   196,   198,     6,
     197,   198,   156,   219,   161,   140,     6,     5,   141,   140,
     141,   140,   141,   140,   141,   139,   141,   140,   211,   141,
       6,   198,     6,   198,     6,   198,   219,     6,   159,   219,
     141,     6,   141,   141,   141,   139,   141,     6,     6,     6,
       6,   219,     6
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
#line 142 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 153 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 154 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 155 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 156 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 157 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 158 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 159 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 160 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 161 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 162 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 163 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 164 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 165 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 166 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 171 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 21:
#line 175 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 22:
#line 182 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 23:
#line 187 "Gmsh.y"
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
#line 202 "Gmsh.y"
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
#line 215 "Gmsh.y"
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
#line 244 "Gmsh.y"
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
#line 258 "Gmsh.y"
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
#line 269 "Gmsh.y"
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
#line 283 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData = new PViewDataList(); 
#endif
    ;}
    break;

  case 35:
#line 297 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 36:
#line 299 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 37:
#line 304 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 38:
#line 306 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 39:
#line 311 "Gmsh.y"
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

  case 40:
#line 415 "Gmsh.y"
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

  case 41:
#line 425 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 42:
#line 434 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 43:
#line 441 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 44:
#line 451 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d)); 
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d)); 
      ViewData->T2D.push_back(ViewData->T2C.size()); 
#endif
    ;}
    break;

  case 45:
#line 460 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 46:
#line 469 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 47:
#line 476 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 48:
#line 486 "Gmsh.y"
    { 
#if !defined(HAVE_NO_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size()); 
#endif
    ;}
    break;

  case 49:
#line 494 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 50:
#line 504 "Gmsh.y"
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

  case 51:
#line 523 "Gmsh.y"
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

  case 52:
#line 542 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 53:
#line 548 "Gmsh.y"
    {
    ;}
    break;

  case 54:
#line 555 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 55:
#line 556 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 56:
#line 557 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 57:
#line 558 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 58:
#line 559 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 59:
#line 563 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 60:
#line 564 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 61:
#line 572 "Gmsh.y"
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
#line 594 "Gmsh.y"
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

  case 63:
#line 621 "Gmsh.y"
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

  case 64:
#line 661 "Gmsh.y"
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
#line 671 "Gmsh.y"
    {
      // appends to the list
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].push_back(*(double*)List_Pointer((yyvsp[(5) - (6)].l), i));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 66:
#line 679 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c)); 
      else
	gmsh_yysymbols[(yyvsp[(1) - (3)].c)][0] += (yyvsp[(2) - (3)].i);
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 67:
#line 687 "Gmsh.y"
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

  case 68:
#line 699 "Gmsh.y"
    { 
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 69:
#line 708 "Gmsh.y"
    { 
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c))
    ;}
    break;

  case 70:
#line 714 "Gmsh.y"
    { 
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c))
    ;}
    break;

  case 71:
#line 723 "Gmsh.y"
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
#line 741 "Gmsh.y"
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
#line 759 "Gmsh.y"
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
#line 768 "Gmsh.y"
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
#line 780 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 76:
#line 785 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 77:
#line 793 "Gmsh.y"
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

  case 78:
#line 813 "Gmsh.y"
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

  case 79:
#line 836 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->background_field = (int)(yyvsp[(4) - (5)].d);
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
    ;}
    break;

  case 80:
#line 843 "Gmsh.y"
    {
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 81:
#line 849 "Gmsh.y"
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

  case 82:
#line 869 "Gmsh.y"
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

  case 83:
#line 890 "Gmsh.y"
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

  case 84:
#line 916 "Gmsh.y"
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

  case 85:
#line 928 "Gmsh.y"
    {
#if !defined(HAVE_NO_POST)
      try {
	PluginManager::instance()->setPluginOption((yyvsp[(3) - (9)].c), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].c)); 
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", (yyvsp[(6) - (9)].c), (yyvsp[(3) - (9)].c));
      }
#endif
      Free((yyvsp[(3) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 86:
#line 945 "Gmsh.y"
    { 
      (yyval.i) = (int)(yyvsp[(1) - (1)].d); 
    ;}
    break;

  case 87:
#line 949 "Gmsh.y"
    { 
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim, 
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 88:
#line 959 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 89:
#line 963 "Gmsh.y"
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

  case 90:
#line 975 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 91:
#line 979 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 92:
#line 989 "Gmsh.y"
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

  case 93:
#line 1012 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 94:
#line 1016 "Gmsh.y"
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

  case 95:
#line 1032 "Gmsh.y"
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

  case 96:
#line 1054 "Gmsh.y"
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

  case 97:
#line 1072 "Gmsh.y"
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

  case 98:
#line 1090 "Gmsh.y"
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

  case 99:
#line 1120 "Gmsh.y"
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

  case 100:
#line 1151 "Gmsh.y"
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

  case 101:
#line 1170 "Gmsh.y"
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
#line 1188 "Gmsh.y"
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
#line 1206 "Gmsh.y"
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
#line 1232 "Gmsh.y"
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
#line 1249 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 106:
#line 1253 "Gmsh.y"
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
#line 1272 "Gmsh.y"
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
#line 1290 "Gmsh.y"
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
#line 1329 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 110:
#line 1335 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 111:
#line 1341 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 112:
#line 1348 "Gmsh.y"
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
#line 1373 "Gmsh.y"
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
#line 1398 "Gmsh.y"
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
#line 1414 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 116:
#line 1418 "Gmsh.y"
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
#line 1434 "Gmsh.y"
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
#line 1452 "Gmsh.y"
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
#line 1479 "Gmsh.y"
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
#line 1496 "Gmsh.y"
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
#line 1516 "Gmsh.y"
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
#line 1534 "Gmsh.y"
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
#line 1551 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 124:
#line 1555 "Gmsh.y"
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
#line 1576 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 126:
#line 1581 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 127:
#line 1586 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 128:
#line 1591 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 129:
#line 1596 "Gmsh.y"
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
#line 1616 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 131:
#line 1622 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 132:
#line 1632 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 133:
#line 1633 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 134:
#line 1638 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 135:
#line 1642 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 136:
#line 1646 "Gmsh.y"
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
#line 1669 "Gmsh.y"
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
#line 1692 "Gmsh.y"
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
#line 1715 "Gmsh.y"
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
#line 1743 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 141:
#line 1752 "Gmsh.y"
    {
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
    ;}
    break;

  case 142:
#line 1756 "Gmsh.y"
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

  case 143:
#line 1771 "Gmsh.y"
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

  case 144:
#line 1798 "Gmsh.y"
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

  case 145:
#line 1815 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));      
    ;}
    break;

  case 146:
#line 1829 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 147:
#line 1835 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 148:
#line 1841 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 149:
#line 1850 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 150:
#line 1864 "Gmsh.y"
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

  case 151:
#line 1912 "Gmsh.y"
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

  case 152:
#line 1930 "Gmsh.y"
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

  case 153:
#line 1945 "Gmsh.y"
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

  case 154:
#line 1964 "Gmsh.y"
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

  case 155:
#line 1976 "Gmsh.y"
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

  case 156:
#line 2000 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 157:
#line 2004 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the 
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 158:
#line 2011 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 159:
#line 2017 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 160:
#line 2022 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      Draw();
#endif
    ;}
    break;

  case 161:
#line 2028 "Gmsh.y"
    {
       GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 162:
#line 2037 "Gmsh.y"
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

  case 163:
#line 2054 "Gmsh.y"
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

  case 164:
#line 2071 "Gmsh.y"
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

  case 165:
#line 2090 "Gmsh.y"
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

  case 166:
#line 2109 "Gmsh.y"
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

  case 167:
#line 2137 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 168:
#line 2145 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 169:
#line 2151 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 170:
#line 2158 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 171:
#line 2162 "Gmsh.y"
    {
    ;}
    break;

  case 172:
#line 2171 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 173:
#line 2179 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 174:
#line 2187 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 175:
#line 2195 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 176:
#line 2199 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 177:
#line 2207 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 178:
#line 2211 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 179:
#line 2219 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 180:
#line 2223 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 181:
#line 2231 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 182:
#line 2235 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 183:
#line 2244 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 184:
#line 2251 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 185:
#line 2258 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 186:
#line 2265 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 187:
#line 2272 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 188:
#line 2279 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 189:
#line 2286 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 190:
#line 2293 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 191:
#line 2300 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 192:
#line 2307 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 193:
#line 2311 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 194:
#line 2318 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 195:
#line 2322 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 196:
#line 2329 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 197:
#line 2333 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 198:
#line 2340 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 199:
#line 2344 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 200:
#line 2351 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 201:
#line 2355 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 202:
#line 2362 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 203:
#line 2366 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 204:
#line 2373 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 205:
#line 2377 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 206:
#line 2384 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 207:
#line 2388 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 208:
#line 2395 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 209:
#line 2399 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 210:
#line 2410 "Gmsh.y"
    {
    ;}
    break;

  case 211:
#line 2413 "Gmsh.y"
    {
    ;}
    break;

  case 212:
#line 2419 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 213:
#line 2428 "Gmsh.y"
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

  case 214:
#line 2448 "Gmsh.y"
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

  case 215:
#line 2471 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 216:
#line 2475 "Gmsh.y"
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

  case 217:
#line 2498 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 218:
#line 2502 "Gmsh.y"
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

  case 219:
#line 2517 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 220:
#line 2521 "Gmsh.y"
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

  case 221:
#line 2533 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 222:
#line 2537 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 223:
#line 2542 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 224:
#line 2546 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 225:
#line 2553 "Gmsh.y"
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

  case 226:
#line 2609 "Gmsh.y"
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

  case 227:
#line 2679 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 228:
#line 2684 "Gmsh.y"
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

  case 229:
#line 2751 "Gmsh.y"
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

  case 230:
#line 2794 "Gmsh.y"
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

  case 231:
#line 2820 "Gmsh.y"
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

  case 232:
#line 2843 "Gmsh.y"
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

  case 233:
#line 2866 "Gmsh.y"
    {
    ;}
    break;

  case 234:
#line 2869 "Gmsh.y"
    {
    ;}
    break;

  case 235:
#line 2878 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 236:
#line 2882 "Gmsh.y"
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

  case 237:
#line 2897 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 238:
#line 2898 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 239:
#line 2899 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 240:
#line 2900 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 241:
#line 2901 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 242:
#line 2902 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 243:
#line 2903 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 244:
#line 2904 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 245:
#line 2906 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 246:
#line 2912 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 247:
#line 2913 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 248:
#line 2914 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 249:
#line 2915 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 250:
#line 2916 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 251:
#line 2917 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 252:
#line 2918 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 253:
#line 2919 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 254:
#line 2920 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 255:
#line 2921 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 256:
#line 2922 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 257:
#line 2923 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 258:
#line 2924 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 259:
#line 2925 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 260:
#line 2926 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 261:
#line 2927 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 262:
#line 2928 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 263:
#line 2929 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 264:
#line 2930 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 265:
#line 2931 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 266:
#line 2932 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 267:
#line 2933 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 268:
#line 2934 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 269:
#line 2935 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 270:
#line 2936 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 271:
#line 2937 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 272:
#line 2938 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 273:
#line 2939 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 274:
#line 2940 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 275:
#line 2941 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 276:
#line 2942 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 277:
#line 2943 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 278:
#line 2945 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 279:
#line 2946 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 280:
#line 2947 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 281:
#line 2948 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 282:
#line 2949 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 283:
#line 2950 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 284:
#line 2951 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 285:
#line 2952 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 286:
#line 2953 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 287:
#line 2954 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 288:
#line 2955 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 289:
#line 2956 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 290:
#line 2957 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 291:
#line 2958 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 292:
#line 2959 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 293:
#line 2960 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 294:
#line 2961 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 295:
#line 2962 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 296:
#line 2963 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 297:
#line 2964 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 298:
#line 2965 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 299:
#line 2974 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 300:
#line 2975 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 301:
#line 2976 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 302:
#line 2977 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 303:
#line 2978 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 304:
#line 2979 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 305:
#line 2980 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 306:
#line 2985 "Gmsh.y"
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

  case 307:
#line 2998 "Gmsh.y"
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

  case 308:
#line 3010 "Gmsh.y"
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

  case 309:
#line 3025 "Gmsh.y"
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

  case 310:
#line 3035 "Gmsh.y"
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

  case 311:
#line 3045 "Gmsh.y"
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

  case 312:
#line 3063 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 313:
#line 3068 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 314:
#line 3073 "Gmsh.y"
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

  case 315:
#line 3083 "Gmsh.y"
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

  case 316:
#line 3093 "Gmsh.y"
    { 
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 317:
#line 3101 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 318:
#line 3105 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 319:
#line 3109 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 320:
#line 3113 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 321:
#line 3117 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 322:
#line 3124 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 323:
#line 3128 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 324:
#line 3132 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 325:
#line 3136 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 326:
#line 3143 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 327:
#line 3148 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 328:
#line 3155 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 329:
#line 3160 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 330:
#line 3164 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 331:
#line 3169 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 332:
#line 3173 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 333:
#line 3181 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 334:
#line 3192 "Gmsh.y"
    { 
      (yyval.l) = (yyvsp[(1) - (1)].l); 
    ;}
    break;

  case 335:
#line 3196 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 336:
#line 3208 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 337:
#line 3216 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 338:
#line 3224 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); 
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 339:
#line 3231 "Gmsh.y"
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

  case 340:
#line 3242 "Gmsh.y"
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

  case 341:
#line 3262 "Gmsh.y"
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

  case 342:
#line 3272 "Gmsh.y"
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

  case 343:
#line 3282 "Gmsh.y"
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

  case 344:
#line 3292 "Gmsh.y"
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

  case 345:
#line 3312 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 346:
#line 3317 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 347:
#line 3321 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 348:
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

  case 349:
#line 3337 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 350:
#line 3341 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 351:
#line 3353 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 352:
#line 3360 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 353:
#line 3370 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 354:
#line 3374 "Gmsh.y"
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

  case 355:
#line 3389 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 356:
#line 3394 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 357:
#line 3401 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 358:
#line 3405 "Gmsh.y"
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

  case 359:
#line 3418 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 360:
#line 3426 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 361:
#line 3437 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 362:
#line 3441 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 363:
#line 3449 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 364:
#line 3457 "Gmsh.y"
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

  case 365:
#line 3471 "Gmsh.y"
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

  case 366:
#line 3485 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 367:
#line 3489 "Gmsh.y"
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
#line 7978 "Gmsh.tab.cpp"
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


#line 3509 "Gmsh.y"


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

