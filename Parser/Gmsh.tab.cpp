/* A Bison parser, made by GNU Bison 2.0.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

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
     tExp = 267,
     tLog = 268,
     tLog10 = 269,
     tSqrt = 270,
     tSin = 271,
     tAsin = 272,
     tCos = 273,
     tAcos = 274,
     tTan = 275,
     tRand = 276,
     tAtan = 277,
     tAtan2 = 278,
     tSinh = 279,
     tCosh = 280,
     tTanh = 281,
     tFabs = 282,
     tFloor = 283,
     tCeil = 284,
     tFmod = 285,
     tModulo = 286,
     tHypot = 287,
     tPrintf = 288,
     tSprintf = 289,
     tStrCat = 290,
     tStrPrefix = 291,
     tStrRelative = 292,
     tBoundingBox = 293,
     tDraw = 294,
     tToday = 295,
     tPoint = 296,
     tCircle = 297,
     tEllipse = 298,
     tLine = 299,
     tSurface = 300,
     tSpline = 301,
     tVolume = 302,
     tCharacteristic = 303,
     tLength = 304,
     tParametric = 305,
     tElliptic = 306,
     tPlane = 307,
     tRuled = 308,
     tTransfinite = 309,
     tComplex = 310,
     tPhysical = 311,
     tUsing = 312,
     tBump = 313,
     tProgression = 314,
     tPlugin = 315,
     tRotate = 316,
     tTranslate = 317,
     tSymmetry = 318,
     tDilate = 319,
     tExtrude = 320,
     tDuplicata = 321,
     tLoop = 322,
     tRecombine = 323,
     tDelete = 324,
     tCoherence = 325,
     tIntersect = 326,
     tAttractor = 327,
     tLayers = 328,
     tAlias = 329,
     tAliasWithOptions = 330,
     tText2D = 331,
     tText3D = 332,
     tInterpolationScheme = 333,
     tTime = 334,
     tGrain = 335,
     tCombine = 336,
     tBSpline = 337,
     tBezier = 338,
     tNurbs = 339,
     tOrder = 340,
     tWith = 341,
     tBounds = 342,
     tKnots = 343,
     tColor = 344,
     tColorTable = 345,
     tFor = 346,
     tIn = 347,
     tEndFor = 348,
     tIf = 349,
     tEndIf = 350,
     tExit = 351,
     tReturn = 352,
     tCall = 353,
     tFunction = 354,
     tTrimmed = 355,
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
     tAPPROXEQUAL = 368,
     tNOTEQUAL = 369,
     tEQUAL = 370,
     tGREATEROREQUAL = 371,
     tLESSOREQUAL = 372,
     tCROSSPRODUCT = 373,
     UNARYPREC = 374,
     tMINUSMINUS = 375,
     tPLUSPLUS = 376
   };
#endif
#define tDOUBLE 258
#define tSTRING 259
#define tBIGSTR 260
#define tEND 261
#define tAFFECT 262
#define tDOTS 263
#define tPi 264
#define tMPI_Rank 265
#define tMPI_Size 266
#define tExp 267
#define tLog 268
#define tLog10 269
#define tSqrt 270
#define tSin 271
#define tAsin 272
#define tCos 273
#define tAcos 274
#define tTan 275
#define tRand 276
#define tAtan 277
#define tAtan2 278
#define tSinh 279
#define tCosh 280
#define tTanh 281
#define tFabs 282
#define tFloor 283
#define tCeil 284
#define tFmod 285
#define tModulo 286
#define tHypot 287
#define tPrintf 288
#define tSprintf 289
#define tStrCat 290
#define tStrPrefix 291
#define tStrRelative 292
#define tBoundingBox 293
#define tDraw 294
#define tToday 295
#define tPoint 296
#define tCircle 297
#define tEllipse 298
#define tLine 299
#define tSurface 300
#define tSpline 301
#define tVolume 302
#define tCharacteristic 303
#define tLength 304
#define tParametric 305
#define tElliptic 306
#define tPlane 307
#define tRuled 308
#define tTransfinite 309
#define tComplex 310
#define tPhysical 311
#define tUsing 312
#define tBump 313
#define tProgression 314
#define tPlugin 315
#define tRotate 316
#define tTranslate 317
#define tSymmetry 318
#define tDilate 319
#define tExtrude 320
#define tDuplicata 321
#define tLoop 322
#define tRecombine 323
#define tDelete 324
#define tCoherence 325
#define tIntersect 326
#define tAttractor 327
#define tLayers 328
#define tAlias 329
#define tAliasWithOptions 330
#define tText2D 331
#define tText3D 332
#define tInterpolationScheme 333
#define tTime 334
#define tGrain 335
#define tCombine 336
#define tBSpline 337
#define tBezier 338
#define tNurbs 339
#define tOrder 340
#define tWith 341
#define tBounds 342
#define tKnots 343
#define tColor 344
#define tColorTable 345
#define tFor 346
#define tIn 347
#define tEndFor 348
#define tIf 349
#define tEndIf 350
#define tExit 351
#define tReturn 352
#define tCall 353
#define tFunction 354
#define tTrimmed 355
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
#define tAPPROXEQUAL 368
#define tNOTEQUAL 369
#define tEQUAL 370
#define tGREATEROREQUAL 371
#define tLESSOREQUAL 372
#define tCROSSPRODUCT 373
#define UNARYPREC 374
#define tMINUSMINUS 375
#define tPLUSPLUS 376




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// $Id: Gmsh.tab.cpp,v 1.273 2006-08-19 08:26:47 remacle Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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
#include "Geo.h"
#include "GeoUtils.h"
#include "Nurbs.h"
#include "CAD.h"
#include "Mesh.h"
#include "Draw.h"
#include "Create.h"
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

Tree_T *Symbol_T = NULL;

extern Context_T CTX;
extern Mesh *THEM;

static ExtrudeParams extr;

static Post_View *View;
static List_T *ViewValueList;
static double ViewCoord[100];
static int *ViewNumList, ViewNumNodes, ViewNumComp, ViewNumListTmp;
static int ViewCoordIdx, ViewElementIdx;
static int ViewErrorFlags[VIEW_NB_ELEMENT_TYPES];

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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 76 "Gmsh.y"
typedef union YYSTYPE {
  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
} YYSTYPE;
/* Line 190 of yacc.c.  */
#line 403 "Gmsh.tab.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 213 of yacc.c.  */
#line 415 "Gmsh.tab.cpp"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6543

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  142
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  67
/* YYNRULES -- Number of rules. */
#define YYNRULES  339
/* YYNRULES -- Number of states. */
#define YYNSTATES  1222

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   376

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   127,     2,   137,     2,   125,     2,     2,
     132,   133,   123,   121,   138,   122,   136,   124,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     117,     2,   118,   111,     2,     2,     2,     2,     2,     2,
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
     105,   106,   107,   108,   109,   110,   112,   113,   114,   115,
     116,   119,   120,   126,   128,   129,   130
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    47,    53,    61,    69,    79,    86,    95,
      96,    99,   102,   105,   108,   111,   114,   116,   120,   122,
     126,   127,   128,   139,   141,   145,   146,   160,   162,   166,
     167,   183,   192,   193,   200,   207,   209,   211,   213,   215,
     217,   219,   221,   226,   234,   244,   251,   258,   262,   269,
     276,   286,   293,   303,   309,   318,   327,   339,   346,   356,
     366,   376,   384,   393,   406,   413,   421,   429,   437,   447,
     455,   465,   483,   491,   499,   511,   520,   533,   542,   551,
     560,   573,   596,   617,   626,   635,   644,   652,   661,   667,
     679,   685,   695,   697,   699,   701,   702,   705,   712,   719,
     726,   733,   738,   745,   752,   759,   764,   771,   775,   780,
     786,   790,   794,   799,   804,   808,   816,   824,   828,   836,
     840,   843,   846,   862,   865,   872,   881,   890,   901,   903,
     906,   908,   912,   917,   919,   925,   937,   951,   952,   960,
     961,   975,   976,   992,  1001,  1010,  1019,  1032,  1045,  1058,
    1073,  1088,  1103,  1104,  1117,  1118,  1131,  1132,  1145,  1146,
    1163,  1164,  1181,  1182,  1199,  1200,  1219,  1220,  1239,  1240,
    1259,  1261,  1264,  1274,  1282,  1285,  1292,  1302,  1312,  1321,
    1331,  1340,  1349,  1356,  1361,  1368,  1375,  1382,  1389,  1392,
    1395,  1397,  1401,  1404,  1407,  1410,  1414,  1418,  1422,  1426,
    1430,  1434,  1438,  1442,  1446,  1450,  1454,  1458,  1462,  1466,
    1472,  1477,  1482,  1487,  1492,  1497,  1502,  1507,  1512,  1517,
    1522,  1529,  1534,  1539,  1544,  1549,  1554,  1559,  1566,  1573,
    1580,  1585,  1590,  1595,  1600,  1605,  1610,  1615,  1620,  1625,
    1630,  1635,  1642,  1647,  1652,  1657,  1662,  1667,  1672,  1679,
    1686,  1693,  1698,  1700,  1702,  1704,  1706,  1708,  1710,  1712,
    1714,  1720,  1725,  1730,  1733,  1739,  1743,  1750,  1755,  1763,
    1770,  1772,  1775,  1778,  1782,  1786,  1798,  1808,  1816,  1824,
    1825,  1829,  1833,  1835,  1839,  1841,  1843,  1846,  1850,  1855,
    1859,  1865,  1870,  1872,  1874,  1876,  1880,  1885,  1892,  1900,
    1902,  1904,  1908,  1912,  1922,  1930,  1932,  1938,  1942,  1949,
    1951,  1955,  1957,  1959,  1966,  1971,  1976,  1981,  1988,  1995
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     143,     0,    -1,   144,    -1,     1,     6,    -1,    -1,   144,
     145,    -1,   148,    -1,   147,    -1,   167,    -1,   168,    -1,
     169,    -1,   172,    -1,   173,    -1,   174,    -1,   175,    -1,
     178,    -1,   193,    -1,   194,    -1,   195,    -1,   177,    -1,
     176,    -1,   118,    -1,   118,   118,    -1,    33,   132,     5,
     133,     6,    -1,    33,   132,     5,   133,   146,   208,     6,
      -1,    33,   132,     5,   138,   204,   133,     6,    -1,    33,
     132,     5,   138,   204,   133,   146,   208,     6,    -1,     4,
       5,   139,   149,   140,     6,    -1,     4,     5,     4,   198,
     139,   149,   140,     6,    -1,    -1,   149,   152,    -1,   149,
     156,    -1,   149,   159,    -1,   149,   161,    -1,   149,   162,
      -1,   149,   164,    -1,   196,    -1,   150,   138,   196,    -1,
     196,    -1,   151,   138,   196,    -1,    -1,    -1,     4,   153,
     132,   150,   133,   154,   139,   151,   140,     6,    -1,   208,
      -1,   155,   138,   208,    -1,    -1,    76,   132,   196,   138,
     196,   138,   196,   133,   157,   139,   155,   140,     6,    -1,
     208,    -1,   158,   138,   208,    -1,    -1,    77,   132,   196,
     138,   196,   138,   196,   138,   196,   133,   160,   139,   158,
     140,     6,    -1,    78,   139,   201,   140,   139,   201,   140,
       6,    -1,    -1,    79,   163,   139,   151,   140,     6,    -1,
      80,   132,   196,   133,   202,     6,    -1,     7,    -1,   110,
      -1,   109,    -1,   108,    -1,   107,    -1,   130,    -1,   129,
      -1,     4,   165,   196,     6,    -1,     4,   134,   196,   135,
     165,   196,     6,    -1,     4,   134,   139,   204,   140,   135,
     165,   202,     6,    -1,     4,   134,   135,     7,   202,     6,
      -1,     4,   134,   135,   110,   202,     6,    -1,     4,   166,
       6,    -1,     4,   134,   196,   135,   166,     6,    -1,     4,
     136,     4,     7,   208,     6,    -1,     4,   134,   196,   135,
     136,     4,     7,   208,     6,    -1,     4,   136,     4,   165,
     196,     6,    -1,     4,   134,   196,   135,   136,     4,   165,
     196,     6,    -1,     4,   136,     4,   166,     6,    -1,     4,
     134,   196,   135,   136,     4,   166,     6,    -1,     4,   136,
      89,   136,     4,     7,   205,     6,    -1,     4,   134,   196,
     135,   136,    89,   136,     4,     7,   205,     6,    -1,     4,
     136,    90,     7,   206,     6,    -1,     4,   134,   196,   135,
     136,    90,     7,   206,     6,    -1,    60,   132,     4,   133,
     136,     4,     7,   196,     6,    -1,    60,   132,     4,   133,
     136,     4,     7,   208,     6,    -1,    41,   132,   196,   133,
       7,   198,     6,    -1,    56,    41,   132,   196,   133,     7,
     202,     6,    -1,    72,    41,   202,     7,   139,   196,   138,
     196,   138,   196,   140,     6,    -1,    48,    49,   202,     7,
     196,     6,    -1,    44,   132,   196,   133,     7,   202,     6,
      -1,    46,   132,   196,   133,     7,   202,     6,    -1,    42,
     132,   196,   133,     7,   202,     6,    -1,    42,   132,   196,
     133,     7,   202,    52,   198,     6,    -1,    43,   132,   196,
     133,     7,   202,     6,    -1,    43,   132,   196,   133,     7,
     202,    52,   198,     6,    -1,    50,   132,   196,   133,     7,
     139,   196,   138,   196,   138,     5,   138,     5,   138,     5,
     140,     6,    -1,    82,   132,   196,   133,     7,   202,     6,
      -1,    83,   132,   196,   133,     7,   202,     6,    -1,    84,
     132,   196,   133,     7,   202,    88,   202,    85,   196,     6,
      -1,    44,    67,   132,   196,   133,     7,   202,     6,    -1,
      72,    44,   202,     7,   139,   196,   138,   196,   138,   196,
     140,     6,    -1,    56,    44,   132,   196,   133,     7,   202,
       6,    -1,    52,    45,   132,   196,   133,     7,   202,     6,
      -1,    53,    45,   132,   196,   133,     7,   202,     6,    -1,
     100,    45,   132,   196,   133,     7,   139,   196,   138,   202,
     140,     6,    -1,    84,    45,    86,    87,   132,   196,   133,
       7,   200,    88,   139,   202,   138,   202,   140,    85,   139,
     196,   138,   196,   140,     6,    -1,    84,    45,   132,   196,
     133,     7,   200,    88,   139,   202,   138,   202,   140,    85,
     139,   196,   138,   196,   140,     6,    -1,    45,    67,   132,
     196,   133,     7,   202,     6,    -1,    56,    45,   132,   196,
     133,     7,   202,     6,    -1,    55,    47,   132,   196,   133,
       7,   202,     6,    -1,    47,   132,   196,   133,     7,   202,
       6,    -1,    56,    47,   132,   196,   133,     7,   202,     6,
      -1,    62,   198,   139,   170,   140,    -1,    61,   139,   198,
     138,   198,   138,   196,   140,   139,   170,   140,    -1,    63,
     198,   139,   170,   140,    -1,    64,   139,   198,   138,   196,
     140,   139,   170,   140,    -1,   172,    -1,   171,    -1,   169,
      -1,    -1,   171,   168,    -1,   171,    41,   139,   204,   140,
       6,    -1,   171,    44,   139,   204,   140,     6,    -1,   171,
      45,   139,   204,   140,     6,    -1,   171,    47,   139,   204,
     140,     6,    -1,    66,   139,   171,   140,    -1,    66,     4,
     134,   196,   135,     6,    -1,    74,     4,   134,   196,   135,
       6,    -1,    75,     4,   134,   196,   135,     6,    -1,    69,
     139,   171,   140,    -1,    69,     4,   134,   196,   135,     6,
      -1,    69,     4,     6,    -1,    69,     4,     4,     6,    -1,
      89,   205,   139,   171,   140,    -1,   101,   208,     6,    -1,
     102,   208,     6,    -1,   101,   139,   171,   140,    -1,   102,
     139,   171,   140,    -1,     4,   208,     6,    -1,     4,     4,
     134,   196,   135,   208,     6,    -1,     4,     4,     4,   134,
     196,   135,     6,    -1,     4,   196,     6,    -1,    60,   132,
       4,   133,   136,     4,     6,    -1,    81,     4,     6,    -1,
      96,     6,    -1,    38,     6,    -1,    38,   139,   196,   138,
     196,   138,   196,   138,   196,   138,   196,   138,   196,   140,
       6,    -1,    39,     6,    -1,    91,   132,   196,     8,   196,
     133,    -1,    91,   132,   196,     8,   196,     8,   196,   133,
      -1,    91,     4,    92,   139,   196,     8,   196,   140,    -1,
      91,     4,    92,   139,   196,     8,   196,     8,   196,   140,
      -1,    93,    -1,    99,     4,    -1,    97,    -1,    98,     4,
       6,    -1,    94,   132,   196,   133,    -1,    95,    -1,    65,
     198,   139,   171,   140,    -1,    65,   139,   198,   138,   198,
     138,   196,   140,   139,   171,   140,    -1,    65,   139,   198,
     138,   198,   138,   198,   138,   196,   140,   139,   171,   140,
      -1,    -1,    65,   198,   139,   171,   179,   191,   140,    -1,
      -1,    65,   139,   198,   138,   198,   138,   196,   140,   139,
     171,   180,   191,   140,    -1,    -1,    65,   139,   198,   138,
     198,   138,   198,   138,   196,   140,   139,   171,   181,   191,
     140,    -1,    65,    41,   139,   196,   138,   198,   140,     6,
      -1,    65,    44,   139,   196,   138,   198,   140,     6,    -1,
      65,    45,   139,   196,   138,   198,   140,     6,    -1,    65,
      41,   139,   196,   138,   198,   138,   198,   138,   196,   140,
       6,    -1,    65,    44,   139,   196,   138,   198,   138,   198,
     138,   196,   140,     6,    -1,    65,    45,   139,   196,   138,
     198,   138,   198,   138,   196,   140,     6,    -1,    65,    41,
     139,   196,   138,   198,   138,   198,   138,   198,   138,   196,
     140,     6,    -1,    65,    44,   139,   196,   138,   198,   138,
     198,   138,   198,   138,   196,   140,     6,    -1,    65,    45,
     139,   196,   138,   198,   138,   198,   138,   198,   138,   196,
     140,     6,    -1,    -1,    65,    41,   139,   196,   138,   198,
     140,   182,   139,   191,   140,     6,    -1,    -1,    65,    44,
     139,   196,   138,   198,   140,   183,   139,   191,   140,     6,
      -1,    -1,    65,    45,   139,   196,   138,   198,   140,   184,
     139,   191,   140,     6,    -1,    -1,    65,    41,   139,   196,
     138,   198,   138,   198,   138,   196,   140,   185,   139,   191,
     140,     6,    -1,    -1,    65,    44,   139,   196,   138,   198,
     138,   198,   138,   196,   140,   186,   139,   191,   140,     6,
      -1,    -1,    65,    45,   139,   196,   138,   198,   138,   198,
     138,   196,   140,   187,   139,   191,   140,     6,    -1,    -1,
      65,    41,   139,   196,   138,   198,   138,   198,   138,   198,
     138,   196,   140,   188,   139,   191,   140,     6,    -1,    -1,
      65,    44,   139,   196,   138,   198,   138,   198,   138,   198,
     138,   196,   140,   189,   139,   191,   140,     6,    -1,    -1,
      65,    45,   139,   196,   138,   198,   138,   198,   138,   198,
     138,   196,   140,   190,   139,   191,   140,     6,    -1,   192,
      -1,   191,   192,    -1,    73,   139,   202,   138,   202,   138,
     202,   140,     6,    -1,    73,   139,   202,   138,   202,   140,
       6,    -1,    68,     6,    -1,    54,    44,   202,     7,   196,
       6,    -1,    54,    44,   202,     7,   196,    57,    59,   196,
       6,    -1,    54,    44,   202,     7,   196,    57,    58,   196,
       6,    -1,    54,    45,   139,   196,   140,     7,   202,     6,
      -1,    54,    45,   139,   196,   140,     7,   202,     4,     6,
      -1,    51,    45,   139,   196,   140,     7,   202,     6,    -1,
      54,    47,   139,   196,   140,     7,   202,     6,    -1,    68,
      45,   202,     7,   196,     6,    -1,    68,    45,   202,     6,
      -1,    41,   202,    92,    45,   196,     6,    -1,    44,   202,
      92,    45,   196,     6,    -1,    44,   202,    92,    47,   196,
       6,    -1,    45,   202,    92,    47,   196,     6,    -1,    70,
       6,    -1,    71,     6,    -1,   197,    -1,   132,   196,   133,
      -1,   122,   196,    -1,   121,   196,    -1,   127,   196,    -1,
     196,   122,   196,    -1,   196,   121,   196,    -1,   196,   123,
     196,    -1,   196,   124,   196,    -1,   196,   125,   196,    -1,
     196,   131,   196,    -1,   196,   117,   196,    -1,   196,   118,
     196,    -1,   196,   120,   196,    -1,   196,   119,   196,    -1,
     196,   116,   196,    -1,   196,   115,   196,    -1,   196,   113,
     196,    -1,   196,   112,   196,    -1,   196,   111,   196,     8,
     196,    -1,    12,   132,   196,   133,    -1,    13,   132,   196,
     133,    -1,    14,   132,   196,   133,    -1,    15,   132,   196,
     133,    -1,    16,   132,   196,   133,    -1,    17,   132,   196,
     133,    -1,    18,   132,   196,   133,    -1,    19,   132,   196,
     133,    -1,    20,   132,   196,   133,    -1,    22,   132,   196,
     133,    -1,    23,   132,   196,   138,   196,   133,    -1,    24,
     132,   196,   133,    -1,    25,   132,   196,   133,    -1,    26,
     132,   196,   133,    -1,    27,   132,   196,   133,    -1,    28,
     132,   196,   133,    -1,    29,   132,   196,   133,    -1,    30,
     132,   196,   138,   196,   133,    -1,    31,   132,   196,   138,
     196,   133,    -1,    32,   132,   196,   138,   196,   133,    -1,
      21,   132,   196,   133,    -1,    12,   134,   196,   135,    -1,
      13,   134,   196,   135,    -1,    14,   134,   196,   135,    -1,
      15,   134,   196,   135,    -1,    16,   134,   196,   135,    -1,
      17,   134,   196,   135,    -1,    18,   134,   196,   135,    -1,
      19,   134,   196,   135,    -1,    20,   134,   196,   135,    -1,
      22,   134,   196,   135,    -1,    23,   134,   196,   138,   196,
     135,    -1,    24,   134,   196,   135,    -1,    25,   134,   196,
     135,    -1,    26,   134,   196,   135,    -1,    27,   134,   196,
     135,    -1,    28,   134,   196,   135,    -1,    29,   134,   196,
     135,    -1,    30,   134,   196,   138,   196,   135,    -1,    31,
     134,   196,   138,   196,   135,    -1,    32,   134,   196,   138,
     196,   135,    -1,    21,   134,   196,   135,    -1,     3,    -1,
       9,    -1,    10,    -1,    11,    -1,   104,    -1,   105,    -1,
     106,    -1,     4,    -1,     4,   141,   139,   196,   140,    -1,
       4,   134,   196,   135,    -1,   137,     4,   134,   135,    -1,
       4,   166,    -1,     4,   134,   196,   135,   166,    -1,     4,
     136,     4,    -1,     4,   134,   196,   135,   136,     4,    -1,
       4,   136,     4,   166,    -1,     4,   134,   196,   135,   136,
       4,   166,    -1,   103,   132,     5,   138,   196,   133,    -1,
     199,    -1,   122,   198,    -1,   121,   198,    -1,   198,   122,
     198,    -1,   198,   121,   198,    -1,   139,   196,   138,   196,
     138,   196,   138,   196,   138,   196,   140,    -1,   139,   196,
     138,   196,   138,   196,   138,   196,   140,    -1,   139,   196,
     138,   196,   138,   196,   140,    -1,   132,   196,   138,   196,
     138,   196,   133,    -1,    -1,   139,   201,   140,    -1,   132,
     201,   133,    -1,   202,    -1,   201,   138,   202,    -1,   196,
      -1,   203,    -1,   139,   140,    -1,   139,   204,   140,    -1,
     122,   139,   204,   140,    -1,   196,     8,   196,    -1,   196,
       8,   196,     8,   196,    -1,    41,   139,   196,   140,    -1,
     169,    -1,   172,    -1,   178,    -1,     4,   134,   135,    -1,
     122,     4,   134,   135,    -1,     4,   134,   139,   204,   140,
     135,    -1,   122,     4,   134,   139,   204,   140,   135,    -1,
     196,    -1,   203,    -1,   204,   138,   196,    -1,   204,   138,
     203,    -1,   139,   196,   138,   196,   138,   196,   138,   196,
     140,    -1,   139,   196,   138,   196,   138,   196,   140,    -1,
       4,    -1,     4,   136,    89,   136,     4,    -1,   139,   207,
     140,    -1,     4,   134,   196,   135,   136,    90,    -1,   205,
      -1,   207,   138,   205,    -1,     5,    -1,    40,    -1,    35,
     132,   208,   138,   208,   133,    -1,    36,   132,   208,   133,
      -1,    37,   132,   208,   133,    -1,    34,   132,   208,   133,
      -1,    34,   132,   208,   138,   204,   133,    -1,    34,   132,
       4,   136,     4,   133,    -1,    34,   132,     4,   134,   196,
     135,   136,     4,   133,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   142,   142,   143,   148,   150,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   172,   176,   183,   188,   203,   216,   245,   252,   263,
     269,   270,   271,   272,   273,   274,   278,   280,   285,   287,
     293,   483,   292,   511,   516,   525,   524,   538,   543,   552,
     551,   565,   574,   573,   582,   591,   592,   593,   594,   595,
     599,   600,   607,   638,   677,   731,   748,   766,   777,   796,
     810,   827,   853,   880,   894,   911,   925,   942,   962,   985,
     995,  1014,  1030,  1046,  1065,  1084,  1102,  1120,  1138,  1164,
    1182,  1208,  1228,  1252,  1276,  1302,  1319,  1337,  1356,  1375,
    1414,  1439,  1458,  1477,  1493,  1513,  1530,  1547,  1568,  1573,
    1578,  1583,  1591,  1592,  1593,  1598,  1601,  1605,  1621,  1637,
    1653,  1674,  1688,  1694,  1700,  1712,  1721,  1731,  1745,  1764,
    1778,  1784,  1790,  1799,  1813,  1858,  1873,  1884,  1903,  1913,
    1935,  1939,  1944,  1949,  1961,  1976,  1992,  2018,  2045,  2077,
    2084,  2089,  2095,  2099,  2108,  2116,  2124,  2133,  2132,  2146,
    2145,  2159,  2158,  2173,  2180,  2187,  2194,  2201,  2208,  2215,
    2222,  2229,  2237,  2236,  2249,  2248,  2261,  2260,  2273,  2272,
    2285,  2284,  2297,  2296,  2309,  2308,  2321,  2320,  2333,  2332,
    2348,  2351,  2357,  2383,  2407,  2416,  2434,  2452,  2470,  2499,
    2534,  2561,  2588,  2602,  2621,  2627,  2633,  2636,  2643,  2647,
    2657,  2658,  2659,  2660,  2661,  2662,  2663,  2664,  2665,  2672,
    2673,  2674,  2675,  2676,  2677,  2678,  2679,  2680,  2681,  2682,
    2683,  2684,  2685,  2686,  2687,  2688,  2689,  2690,  2691,  2692,
    2693,  2694,  2695,  2696,  2697,  2698,  2699,  2700,  2701,  2702,
    2703,  2705,  2706,  2707,  2708,  2709,  2710,  2711,  2712,  2713,
    2714,  2715,  2716,  2717,  2718,  2719,  2720,  2721,  2722,  2723,
    2724,  2725,  2734,  2735,  2736,  2737,  2738,  2739,  2740,  2744,
    2760,  2775,  2795,  2809,  2822,  2845,  2863,  2881,  2899,  2917,
    2925,  2929,  2933,  2937,  2941,  2948,  2952,  2956,  2960,  2968,
    2970,  2974,  2981,  2986,  2994,  2999,  3003,  3008,  3012,  3024,
    3030,  3041,  3061,  3071,  3081,  3091,  3108,  3127,  3151,  3180,
    3185,  3189,  3193,  3206,  3210,  3222,  3229,  3251,  3255,  3270,
    3275,  3282,  3286,  3294,  3302,  3316,  3330,  3334,  3353,  3375
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tDOUBLE", "tSTRING", "tBIGSTR", "tEND",
  "tAFFECT", "tDOTS", "tPi", "tMPI_Rank", "tMPI_Size", "tExp", "tLog",
  "tLog10", "tSqrt", "tSin", "tAsin", "tCos", "tAcos", "tTan", "tRand",
  "tAtan", "tAtan2", "tSinh", "tCosh", "tTanh", "tFabs", "tFloor", "tCeil",
  "tFmod", "tModulo", "tHypot", "tPrintf", "tSprintf", "tStrCat",
  "tStrPrefix", "tStrRelative", "tBoundingBox", "tDraw", "tToday",
  "tPoint", "tCircle", "tEllipse", "tLine", "tSurface", "tSpline",
  "tVolume", "tCharacteristic", "tLength", "tParametric", "tElliptic",
  "tPlane", "tRuled", "tTransfinite", "tComplex", "tPhysical", "tUsing",
  "tBump", "tProgression", "tPlugin", "tRotate", "tTranslate", "tSymmetry",
  "tDilate", "tExtrude", "tDuplicata", "tLoop", "tRecombine", "tDelete",
  "tCoherence", "tIntersect", "tAttractor", "tLayers", "tAlias",
  "tAliasWithOptions", "tText2D", "tText3D", "tInterpolationScheme",
  "tTime", "tGrain", "tCombine", "tBSpline", "tBezier", "tNurbs", "tOrder",
  "tWith", "tBounds", "tKnots", "tColor", "tColorTable", "tFor", "tIn",
  "tEndFor", "tIf", "tEndIf", "tExit", "tReturn", "tCall", "tFunction",
  "tTrimmed", "tShow", "tHide", "tGetValue", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tAFFECTDIVIDE",
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND",
  "tAPPROXEQUAL", "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL",
  "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "tCROSSPRODUCT",
  "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'",
  "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All",
  "GeoFormatItems", "GeoFormatItem", "SendToFile", "Printf", "View",
  "Views", "ElementCoords", "ElementValues", "Element", "@1", "@2",
  "Text2DValues", "Text2D", "@3", "Text3DValues", "Text3D", "@4",
  "InterpolationMatrix", "Time", "@5", "Grain", "NumericAffectation",
  "NumericIncrement", "Affectation", "Shape", "Transform", "MultipleShape",
  "ListOfShapes", "Duplicata", "Delete", "Colorify", "Visibility",
  "Command", "Loop", "Extrude", "@6", "@7", "@8", "@9", "@10", "@11",
  "@12", "@13", "@14", "@15", "@16", "@17", "ExtrudeParameters",
  "ExtrudeParameter", "Transfinite", "Embedding", "Coherence", "FExpr",
  "FExpr_Single", "VExpr", "VExpr_Single", "ListOfListOfDouble",
  "RecursiveListOfListOfDouble", "ListOfDouble", "FExpr_Multi",
  "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExpr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
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
     365,    63,   366,   367,   368,   369,   370,    60,    62,   371,
     372,    43,    45,    42,    47,    37,   373,    33,   374,   375,
     376,    94,    40,    41,    91,    93,    46,    35,    44,   123,
     125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   142,   143,   143,   144,   144,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   146,   146,   147,   147,   147,   147,   148,   148,   149,
     149,   149,   149,   149,   149,   149,   150,   150,   151,   151,
     153,   154,   152,   155,   155,   157,   156,   158,   158,   160,
     159,   161,   163,   162,   164,   165,   165,   165,   165,   165,
     166,   166,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   169,   169,
     169,   169,   170,   170,   170,   171,   171,   171,   171,   171,
     171,   172,   172,   172,   172,   173,   173,   173,   173,   174,
     175,   175,   175,   175,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   178,   178,   178,   179,   178,   180,
     178,   181,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   182,   178,   183,   178,   184,   178,   185,   178,
     186,   178,   187,   178,   188,   178,   189,   178,   190,   178,
     191,   191,   192,   192,   192,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   194,   194,   194,   194,   195,   195,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     198,   198,   198,   198,   198,   199,   199,   199,   199,   200,
     200,   200,   201,   201,   202,   202,   202,   202,   202,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   204,
     204,   204,   204,   205,   205,   205,   205,   206,   206,   207,
     207,   208,   208,   208,   208,   208,   208,   208,   208,   208
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     7,     7,     9,     6,     8,     0,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     3,
       0,     0,    10,     1,     3,     0,    13,     1,     3,     0,
      15,     8,     0,     6,     6,     1,     1,     1,     1,     1,
       1,     1,     4,     7,     9,     6,     6,     3,     6,     6,
       9,     6,     9,     5,     8,     8,    11,     6,     9,     9,
       9,     7,     8,    12,     6,     7,     7,     7,     9,     7,
       9,    17,     7,     7,    11,     8,    12,     8,     8,     8,
      12,    22,    20,     8,     8,     8,     7,     8,     5,    11,
       5,     9,     1,     1,     1,     0,     2,     6,     6,     6,
       6,     4,     6,     6,     6,     4,     6,     3,     4,     5,
       3,     3,     4,     4,     3,     7,     7,     3,     7,     3,
       2,     2,    15,     2,     6,     8,     8,    10,     1,     2,
       1,     3,     4,     1,     5,    11,    13,     0,     7,     0,
      13,     0,    15,     8,     8,     8,    12,    12,    12,    14,
      14,    14,     0,    12,     0,    12,     0,    12,     0,    16,
       0,    16,     0,    16,     0,    18,     0,    18,     0,    18,
       1,     2,     9,     7,     2,     6,     9,     9,     8,     9,
       8,     8,     6,     4,     6,     6,     6,     6,     2,     2,
       1,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     6,     6,
       6,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     4,     2,     5,     3,     6,     4,     7,     6,
       1,     2,     2,     3,     3,    11,     9,     7,     7,     0,
       3,     3,     1,     3,     1,     1,     2,     3,     4,     3,
       5,     4,     1,     1,     1,     3,     4,     6,     7,     1,
       1,     3,     3,     9,     7,     1,     5,     3,     6,     1,
       3,     1,     1,     6,     4,     4,     4,     6,     6,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       0,     0,     0,     2,     3,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,   153,     0,   150,
       0,     0,     0,     0,     0,     5,     7,     6,     8,     9,
      10,    11,    12,    13,    14,    20,    19,    15,    16,    17,
      18,   272,   279,   331,    55,   273,   274,   275,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   332,     0,   276,   277,   278,    59,    58,
      57,    56,     0,     0,     0,    61,    60,     0,     0,     0,
       0,     0,     0,     0,   210,     0,     0,   141,     0,   143,
     279,     0,     0,     0,     0,   312,   313,   314,   304,     0,
     305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     290,     0,     0,     0,     0,     0,     0,     0,     0,   115,
       0,     0,   115,   208,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   325,     0,     0,     0,     0,     0,
     140,     0,   149,     0,   331,   115,     0,   115,     0,     0,
       0,     0,     0,   283,     0,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,   213,   212,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,     0,     0,     0,     0,   279,     0,
       0,     0,   306,   319,   320,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   292,   291,     0,     0,     0,     0,   115,   115,
       0,     0,     0,     0,     0,     0,     0,     0,   115,     0,
       0,     0,     0,   127,     0,     0,     0,     0,     0,     0,
     139,     0,     0,     0,     0,     0,     0,     0,   115,     0,
       0,     0,   151,     0,     0,   130,     0,   131,     0,     0,
     285,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   211,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,    62,     0,   228,   227,   226,   225,
     221,   222,   224,   223,   216,   215,   217,   218,   219,   220,
       0,     0,     0,   315,     0,     0,     0,     0,     0,   211,
       0,   307,   309,     0,     0,     0,     0,   211,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   294,   293,   114,     0,   113,   112,     0,     0,     0,
       0,     0,     0,     0,   157,     0,     0,     0,     0,     0,
     121,   116,   203,     0,   128,     0,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   152,     0,   132,   133,     0,   281,   287,     0,    29,
      40,     0,     0,     0,    52,     0,     0,    30,    31,    32,
      33,    34,    35,   230,   251,   231,   252,   232,   253,   233,
     254,   234,   255,   235,   256,   236,   257,   237,   258,   238,
     259,   250,   271,   239,   260,     0,     0,   241,   262,   242,
     263,   243,   264,   244,   265,   245,   266,   246,   267,     0,
       0,     0,     0,     0,     0,     0,     0,   336,     0,     0,
     334,   335,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,     0,     0,     0,     0,   282,     0,    23,    21,
       0,     0,     0,     0,   281,   311,   316,     0,   308,     0,
     321,   322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,   110,     0,     0,     0,     0,     0,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,     0,     0,     0,   284,     0,   280,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,     0,     0,     0,     0,     0,    68,    69,    71,
       0,     0,   329,     0,    77,   229,    22,     0,     0,     0,
       0,     0,     0,   310,   204,     0,     0,     0,     0,   205,
     206,     0,   207,     0,     0,    84,     0,     0,     0,     0,
     195,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   190,   122,     0,     0,     0,     0,     0,     0,   202,
     126,     0,     0,   123,   124,     0,     0,     0,   299,     0,
     326,     0,     0,     0,   144,     0,   136,   286,   135,     0,
       0,     0,     0,     0,   302,     0,     0,   240,   261,   247,
     268,   248,   269,   249,   270,     0,   338,   337,   333,   289,
       0,    55,     0,     0,     0,     0,    63,     0,     0,     0,
     327,    24,    25,     0,     0,   317,     0,    81,    87,     0,
      89,     0,     0,    85,     0,    86,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,   115,     0,   172,     0,   174,
       0,   176,     0,     0,   194,     0,   158,   191,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   288,    28,     0,
      36,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,    74,     0,     0,    75,     0,   330,     0,     0,
     318,     0,     0,    95,   103,     0,   200,    98,    99,     0,
       0,     0,   198,   201,   105,    82,    97,   104,   107,     0,
       0,     0,   298,     0,   297,     0,     0,   163,     0,     0,
     164,     0,     0,   165,     0,     0,     0,     0,   117,   118,
     119,   120,     0,     0,   299,     0,     0,     0,     0,     0,
     324,     0,   146,   145,     0,    41,     0,     0,     0,   303,
       0,     0,     0,     0,     0,    64,    70,    72,     0,    78,
       0,    26,     0,    88,    90,     0,   197,   196,   199,    79,
      80,   115,     0,   111,     0,     0,     0,     0,     0,     0,
     115,     0,     0,     0,     0,     0,   301,   300,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,    39,    53,
      54,   339,     0,   328,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   159,     0,
       0,     0,     0,     0,     0,     0,   323,   147,     0,     0,
       0,     0,     0,    76,     0,     0,   109,     0,   178,     0,
       0,   180,     0,     0,   182,     0,     0,   155,     0,   115,
       0,     0,     0,     0,     0,     0,    94,     0,     0,    45,
       0,    51,     0,     0,   295,   166,     0,     0,   173,   167,
       0,     0,   175,   168,     0,     0,   177,     0,   161,     0,
     193,    83,    96,     0,     0,   100,     0,     0,     0,     0,
       0,     0,   184,     0,   186,     0,   188,   160,   156,     0,
       0,     0,     0,    42,     0,    49,     0,     0,     0,   169,
       0,     0,   170,     0,     0,   171,     0,     0,   192,     0,
       0,     0,    43,     0,   142,     0,     0,     0,     0,     0,
       0,     0,   162,     0,     0,     0,     0,     0,     0,   179,
       0,   181,     0,   183,     0,     0,     0,    44,    46,     0,
      47,    91,     0,     0,     0,     0,     0,     0,     0,   185,
     187,   189,     0,     0,    48,    50,     0,     0,     0,   102,
       0,   101
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     2,     3,    55,   630,    56,    57,   383,   919,   925,
     557,   710,  1043,  1171,   558,  1137,  1199,   559,  1173,   560,
     561,   714,   562,   121,   213,    58,   521,   135,   504,   505,
     136,    62,    63,    64,    65,    66,   137,   679,  1098,  1149,
     968,   971,   974,  1116,  1120,  1124,  1160,  1163,  1166,   790,
     791,    68,    69,    70,   138,   124,   332,   170,   911,   823,
     824,   140,   305,   196,   625,   743,   125
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -901
static const short int yypact[] =
{
    2779,    15,    47,  3155,  -901,  -901,  2208,   -69,    -2,    75,
    1611,   -22,   -18,  1349,  1480,     0,    37,    99,    54,   154,
     157,   207,   585,   222,   529,   164,   163,   261,   261,   177,
     320,    11,   289,    16,   345,   356,    89,   372,   375,   380,
     263,   274,   -29,    18,    -1,  -901,   280,  -901,   419,  -901,
     387,   432,   383,    24,    33,  -901,  -901,  -901,  -901,  -901,
    -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,
    -901,  -901,    10,    20,  -901,  -901,  -901,  -901,   136,   192,
     269,   313,   350,   386,   403,   409,   475,   491,   516,   537,
     538,   553,   554,   570,   594,   595,   602,   605,   610,   307,
     333,   339,   344,  -901,   363,  -901,  -901,  -901,  -901,  -901,
    -901,  -901,  2423,  2423,  2423,  -901,  -901,  2423,  1809,    27,
     497,  2423,   498,   522,  -901,   505,   533,  -901,  2423,  -901,
     431,   413,  2047,  2423,  1203,  -901,  -901,  -901,   543,   479,
    -901,  2423,  2423,   434,  2423,   490,   446,   494,  2423,  2423,
    1742,  2423,   452,   482,   496,  1742,   510,   518,   541,   582,
     606,   609,   624,   768,   261,   261,   261,  2423,  2423,   -82,
    -901,   -77,   261,   634,   656,   669,  2077,   -68,   484,  -901,
    1742,    13,  -901,  -901,  -901,  1742,  1742,   645,   687,   806,
    2423,  2423,   -52,  2423,   703,  2423,   728,   755,  2423,  2423,
    -901,   862,  -901,   737,  -901,  -901,   867,  -901,   868,   742,
    2423,   874,   740,  -901,   261,  -901,  2423,  2423,  2423,  2423,
    2423,  2423,  2423,  2423,  2423,  2423,  2423,  2423,  2423,  2423,
    2423,  2423,  2423,  2423,  2423,  2423,  2423,  2423,  2423,  2423,
    2423,  2423,  2423,  2423,  2423,  2423,  2423,  2423,  2423,  2423,
    2423,  2423,  2423,  2423,  2423,  2423,  2423,  2423,   352,   463,
     463,   463,   875,   483,   751,   751,   751,  1407,    19,  2258,
     856,    71,   747,   877,   752,   825,  -901,  -901,  2423,  2423,
    2423,  2423,  2423,  2423,  2423,  2423,  2423,  2423,  2423,  2423,
    2423,  2423,  2423,  -901,   -90,  3743,  1873,  2423,   486,  2258,
    5216,  2453,  -901,   543,  -901,   385,  2423,   840,  5239,  5262,
    2423,  5285,   111,  2423,   842,  5308,  5331,   883,  5354,  2423,
    2423,  2423,   884,  2423,  2423,  2423,  2423,  2423,  2423,  2423,
     759,   322,  -901,  -901,  3767,  3791,   261,   261,   526,   526,
     348,  2423,  2423,  2423,  2077,  2077,  2423,   358,  -901,  2423,
     741,   675,   888,  -901,  2423,  2841,   889,   890,  2423,  2423,
    -901,  5377,  5400,   808,  2423,  5423,   811,  3815,  -901,   762,
    2598,  5446,  -901,  2423,  2862,  -901,  2908,  -901,  2423,  3163,
     -34,  2423,    43,     9,  5469,  4607,  5492,  4628,  5515,  4649,
    5538,  4670,  5561,  4691,  5584,  4712,  5607,  4733,  5630,  4754,
    5653,  4775,  5676,  4796,  5699,  4817,  3839,  3863,  5722,  4838,
    5745,  4859,  5768,  4880,  5791,  4901,  5814,  4922,  5837,  4943,
    3887,  3911,  3935,  3959,  3983,  4007,   574,    50,   764,   770,
     771,   767,  2423,  -901,  1742,  1742,   608,    67,   463,  2423,
     903,   907,    21,   777,  -901,  2615,   947,   576,   977,   977,
     679,   679,   679,   679,   -48,   -48,   751,   751,   751,   751,
       1,  2258,  2423,  -901,  2258,  4964,  1130,  2010,   611,   906,
    2258,  -901,  2636,  2423,   910,   911,  5860,   912,  2423,  2423,
    5883,  2423,   913,   914,  2423,   916,  1538,  5906,  5929,  2423,
    1669,  2854,  5952,  5975,  5998,  6021,  6044,   778,   261,  2423,
    2423,  -901,  -901,  -901,   784,  3217,  -901,   785,  2423,  4031,
    4055,  4079,  3719,   261,  2968,  4985,   -14,   -35,   -40,     2,
    -901,  -901,  -901,  2423,  -901,  5006,  -901,   787,   788,  5027,
    5048,   921,   922,   798,  6067,   924,   796,  2423,  2989,  2423,
    2423,  -901,  6090,  -901,  -901,  5069,   293,  -901,  2981,  -901,
    -901,   802,   803,   812,  -901,   820,   948,  -901,  -901,  -901,
    -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,
    -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,
    -901,  -901,  -901,  -901,  -901,  2423,  2423,  -901,  -901,  -901,
    -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,  2423,
    2423,  2423,  2423,  2423,  2423,  2423,   949,  -901,  2258,   463,
    -901,  -901,  2423,   952,   953,   826,    31,  2423,   954,   956,
     881,  -901,   957,   821,    18,   959,  -901,  2423,  -901,   845,
     463,   133,  4103,   614,   474,  -901,  -901,  2258,  -901,   261,
     543,  -901,  2423,  1036,  1742,  1742,   975,  1742,  1314,  1445,
     979,  1576,  1742,  1742,  1838,   827,   981,   982,  1000,   646,
    1003,  1006,  1007,  1008,  1014,  1016,  1018,   980,   370,  4127,
    4151,  -901,  -901,  3251,   261,   261,   261,   384,  -901,   221,
    1020,  2423,  2258,  2423,  2258,  2258,  2258,  2235,  1024,  2423,
    2423,  1025,  1026,  1742,  1742,  2423,  1027,  1742,  1031,  4175,
    -901,  2653,   739,  1029,  1032,  1033,  -901,  1035,  -901,    14,
     915,  2423,  2423,  1742,   904,  2423,  -901,  6113,  5090,  6136,
    5111,  6159,  5132,  6182,  5153,  5174,   917,   170,   919,  6205,
    -901,  -901,    98,   202,   908,  1038,  2480,  -901,  -901,  -901,
      18,  2423,  -901,   615,  -901,  6412,  -901,  1040,     6,  2423,
     918,   640,    73,  6412,  -901,    46,    49,  1742,  1043,  -901,
    -901,  1742,  -901,  1048,  1049,  -901,  2423,  1742,  1742,  1742,
    -901,   296,  1742,  1742,  1742,  1742,  1742,  1742,  1742,   726,
    2423,  2423,  2423,   920,   -56,   297,   310,  2077,  1050,   935,
     -31,  -901,  -901,  6228,   652,  6251,   671,   677,   678,  -901,
    -901,  4199,  4223,  -901,  -901,  1069,  1070,  6274,    34,   989,
    -901,  2423,  2423,  2423,  -901,   940,  -901,   -34,  -901,  1074,
    2423,  4247,  4271,   682,  -901,  2423,  6297,  -901,  -901,  -901,
    -901,  -901,  -901,  -901,  -901,   945,  -901,  -901,  -901,  -901,
    1742,   463,  2423,  1076,  1080,    21,  -901,  1079,  5195,    18,
    -901,  -901,  -901,   463,  4295,  -901,   955,  -901,  -901,   261,
    -901,   261,  1081,  -901,  1082,  -901,  -901,  4319,  1086,  1097,
    1099,  2423,  2423,   822,  1101,  1103,  1104,  1105,  1106,  1107,
    -901,  2388,  3277,  6320,  2675,   526,   261,  1108,   261,  1109,
     261,  1110,  3303,   388,  -901,  1742,  -901,  -901,   906,  1111,
     912,  1113,  1117,  1118,  2423,  2423,  -901,  -901,  1119,  1742,
    1742,  1039,  1742,  3191,   600,  6343,  2423,  -901,  -901,   212,
    6412,  2423,  2423,  1742,   990,   689,  6412,  1742,  1124,  1128,
    1129,  2497,  -901,  1123,  1137,  -901,  1009,  -901,  1138,  2423,
    -901,   184,   259,  -901,  -901,  2423,  -901,  -901,  -901,  2518,
    2535,  1140,  -901,  -901,  -901,  -901,  -901,  -901,  -901,  2556,
    1156,  1030,  -901,  2423,  -901,  1023,   391,  -901,  1034,   394,
    -901,  1037,   418,  -901,  1041,  1045,  2423,  1028,  -901,  -901,
    -901,  -901,  4343,  4367,    34,   235,   692,  1046,  1083,  2423,
    -901,  2423,  -901,  -901,  4391,  -901,  2423,  4415,  4439,  -901,
    1742,  2423,  1158,  1159,  1042,  -901,  -901,  -901,    18,  -901,
    1084,  -901,  4463,  -901,  -901,  4487,  -901,  -901,  -901,  -901,
    -901,   526,  3221,  -901,  2077,   221,  2077,   221,  2077,   221,
    -901,  3329,  1742,  2423,  2423,  1089,  -901,  -901,  1742,  2423,
    3355,  3381,  1742,  1047,  6412,  2423,  2423,   695,  6412,  -901,
    -901,  -901,  1164,  -901,  2423,  1166,  1051,  2423,  -901,  3407,
     424,   -27,  3433,   426,   -17,  3459,   437,   185,  3035,  1053,
     700,  3485,  3511,  1054,  1044,  2573,  -901,  -901,  1055,  2423,
    6366,  4511,  1173,  -901,  4535,  1052,  -901,  3537,  1181,  2423,
    1182,  1183,  2423,  1188,  1190,  2423,  1191,  -901,   221,  -901,
    1742,  1192,  1195,  1196,  1742,  1742,  -901,  1199,   704,  -901,
    2423,  -901,  2423,  1167,  -901,  -901,  1072,  3563,  -901,  -901,
    1098,  3589,  -901,  -901,  1100,  3615,  -901,   219,  3095,  1068,
    -901,  -901,  -901,  1071,  1096,  -901,  1232,  1132,  6389,  3641,
    1102,   221,  1251,   221,  1256,   221,  1257,  -901,  -901,   221,
    1266,  1742,  1189,  -901,   463,  -901,  1267,  1270,   276,  -901,
    1141,   298,  -901,  1142,   317,  -901,  1143,   326,  -901,  1139,
    1144,   705,  -901,  1145,  -901,  1146,  1279,   221,  1282,   221,
    1283,   221,  -901,  1205,  2423,   463,  1286,   463,  1287,  -901,
     334,  -901,   337,  -901,   341,  1155,  4559,  -901,  -901,   708,
    -901,  -901,  1289,  1290,  1291,  2423,  2423,   463,  1292,  -901,
    -901,  -901,  4583,  3667,  -901,  -901,  2423,  1293,  3693,  -901,
    1294,  -901
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -901,  -901,  -901,  -901,   555,  -901,  -901,   753,  -901,   225,
    -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,
    -901,  -901,  -901,  -270,    17,  -901,  1298,     3,  -331,  -177,
       8,  -901,  -901,  -901,  -901,  -901,  1302,  -901,  -901,  -901,
    -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,  -901,  -728,
    -637,  -901,  -901,  -901,    -6,  -901,   232,  -901,   327,  -900,
     364,  -101,  -197,  -588,   465,  -901,    -4
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const short int yytable[] =
{
     123,   439,   350,   197,   127,   355,    60,   628,   507,   985,
     986,    61,   852,   550,   209,   178,   192,   352,   550,   353,
     181,     4,   194,   122,   214,   623,   434,   146,   374,   204,
     376,   271,   143,   304,   363,   733,   742,   788,   204,   336,
     337,   788,   789,   460,   336,   337,   789,     5,   461,   206,
     208,   788,   858,   336,   337,   860,   789,   338,    99,   100,
     101,   102,   339,   126,   103,   336,   337,    99,   100,   101,
     102,   348,   436,   103,    74,   289,   290,   291,   438,   857,
     364,   129,   886,   292,   887,   551,   552,   553,   554,   555,
     551,   552,   553,   554,   555,   115,   116,   683,   859,   685,
    1047,   861,   468,   193,   684,    74,   264,   265,   266,   896,
     141,   267,   270,  1090,   142,   275,   272,   273,   681,   629,
     734,   735,   295,  1093,   629,   682,   265,   300,   303,   435,
     185,   198,   148,   186,   149,   308,   309,   128,   311,   115,
     116,   686,   315,   316,   210,   318,   211,   354,   150,   556,
     179,   212,   847,   897,   819,   182,   478,   195,   479,   215,
     624,   334,   335,   205,   336,   337,   909,   617,   304,   149,
     335,   514,   207,   910,   108,   109,   110,   111,   108,   109,
     110,   111,   549,   607,   361,   362,   151,   365,   608,   367,
    1013,   538,   370,   371,   336,   337,   115,   116,   304,   152,
     115,   116,   153,   616,   379,   108,   109,   110,   111,   841,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   154,   788,   427,   428,   429,   430,   789,   169,
     171,   937,   177,   303,   631,  1014,   748,   633,   216,   158,
     217,   470,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   788,   440,   788,
     465,   466,   789,   303,   789,   265,   163,  1061,   204,  1064,
     472,  1067,   164,   837,   476,   336,   337,   480,   470,   108,
     109,   110,   111,   486,   487,   488,   172,   490,   491,   492,
     493,   494,   495,   496,   218,  1096,   219,    99,   100,   101,
     102,   115,   116,   103,   180,   509,   510,   511,   264,   265,
     512,   503,   503,   515,   788,   995,   506,   506,   525,   789,
     996,   183,   529,   530,   871,   872,   426,   204,   534,  1147,
     304,   173,   184,   304,   174,   175,   788,   542,  1036,   641,
    1127,   789,   545,   923,   139,   548,   187,   145,   147,   188,
     336,   337,   165,   166,   189,   788,    99,   100,   101,   102,
     789,   201,   103,   167,   788,   190,   331,   547,   333,   789,
     168,   220,   788,   221,   340,   788,   191,   789,   347,   788,
     789,   727,   199,  1158,   789,  1161,  1176,  1164,   336,   337,
    1052,  1167,   115,   116,   897,   200,   465,   897,   203,   705,
     897,   336,   337,   620,   619,   888,   202,   889,  1178,   258,
     751,   165,   166,   336,   337,   222,   382,   223,   890,  1190,
     891,  1192,   167,  1194,   618,   303,   632,  1180,   303,   176,
     498,   465,   840,   842,   640,   259,  1182,   643,   204,   336,
     337,   260,   648,   649,  1202,   651,   261,  1203,   654,   336,
     337,  1204,   224,   659,   225,   794,   508,   796,   797,   798,
     897,   336,   337,   669,   670,   262,   513,    99,   100,   101,
     102,   274,   673,   103,   276,   336,   337,   304,   780,   336,
     337,   293,   336,   337,   317,   336,   337,   687,   226,   322,
     227,   897,   787,   470,   897,   471,   976,   897,   277,  1024,
     897,   699,  1026,   701,   702,   228,   304,   229,   294,   336,
     337,   230,   707,   231,   351,   336,   337,   336,   337,   356,
     357,   306,   297,   897,   965,   897,  1028,   897,   336,   337,
     115,   116,  1089,   706,  1092,   296,   310,   211,   501,   502,
     159,   307,   212,   160,   161,  1095,   162,   333,   313,   717,
     718,   304,   312,   304,   304,   304,   314,    26,    27,    28,
      29,   319,    31,   719,   720,   721,   722,   723,   724,   725,
      37,    38,   303,   115,   116,   728,   729,   232,   991,   233,
     705,   736,   115,   116,   320,   115,   116,   432,   349,   211,
     467,   745,   211,   234,   212,   235,   747,   212,   321,   155,
     156,   303,   157,   278,   279,   280,   753,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   236,   323,
     237,   706,   770,   292,   278,   279,   280,   324,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   238,
     240,   239,   241,   325,   292,   793,   303,   795,   303,   303,
     303,   522,   523,   801,   802,   242,   244,   243,   245,   807,
    1056,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   246,   771,   247,   821,   822,   292,   605,   826,
     606,   278,   279,   280,   326,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   248,   250,   249,   251,
     668,   292,   880,   881,   252,   848,   253,   254,   327,   255,
     992,   328,   256,   854,   257,   677,   470,   813,   615,   470,
     843,   638,   470,   849,   750,   850,   329,   278,   279,   280,
     867,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   330,   341,   882,   883,   884,   292,   470,   358,
     856,   892,   516,    11,    12,   517,   518,    15,   519,    17,
     470,    18,   899,    20,    21,   342,    23,    24,   613,   614,
     287,   288,   289,   290,   291,   913,   914,   915,   343,   470,
     292,   901,   360,    36,   920,   470,   470,   902,   903,   926,
     923,   359,   924,    40,    41,    42,   951,  1001,   952,  1002,
     923,   444,  1037,   923,   917,  1082,   931,   930,  1100,   366,
    1101,    52,  1001,  1185,  1136,  1186,  1207,   369,  1208,   938,
     278,   279,   280,  1068,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   949,   950,   368,   372,   373,
     292,   752,   814,   375,   377,   959,   378,   960,   380,   381,
     431,   520,   292,   441,   442,   473,   443,   739,   503,   481,
     484,   489,   497,   506,   524,   533,   527,   528,   982,   983,
     536,   539,   609,   610,   611,   612,   784,   785,   786,   621,
     994,   622,   626,   639,   667,   997,   998,   644,   645,   647,
     652,   653,  1128,   655,   671,   672,   689,   690,   693,   694,
     695,   697,   698,  1012,   711,   712,   278,   279,   280,  1015,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   713,   715,   726,   716,   741,   292,  1022,   730,   731,
     737,   732,   738,   746,   740,   744,   766,   278,   279,   280,
    1031,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   757,  1040,   779,  1041,   761,   292,   767,   768,
    1044,   437,   278,   279,   280,  1048,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   769,   755,   756,
     772,   758,   292,   773,   774,   775,   763,   764,  1059,   893,
    1062,   776,  1065,   777,   503,   778,   792,  1071,  1072,   506,
     800,   803,   804,  1075,   808,   810,   815,   817,   816,  1080,
    1081,   818,   754,   825,   844,   845,   851,   820,  1084,   863,
     836,  1087,   838,   855,   865,   866,   894,   805,   806,   885,
     280,   809,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   926,   895,   906,   907,   912,   292,   916,
     918,   928,   932,  1117,   933,   935,  1121,   943,   944,  1125,
     940,   941,   946,   942,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   947,  1138,   948,  1139,   953,   292,   954,
     955,   956,   957,   958,   967,   970,   973,   978,   966,   979,
     969,   862,   972,   980,   981,   864,   984,   987,  1004,  1000,
    1008,   868,   869,   870,  1005,  1006,   873,   874,   875,   876,
     877,   878,   879,  1009,  1011,  1010,  1018,   278,   279,   280,
    1172,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,  1020,  1023,  1049,  1050,  1032,   292,  1039,  1021,
    1083,  1085,  1140,  1025,  1053,  1051,  1027,  1073,  1196,  1111,
    1029,  1197,  1105,  1200,  1030,  1038,  1079,  1115,  1118,  1119,
    1113,  1086,  1099,  1104,  1122,  1107,  1123,  1126,  1130,  1212,
    1213,  1131,  1132,  1214,   929,  1135,    71,   130,  1150,  1151,
    1218,  1141,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,  1152,  1143,  1153,  1145,
    1157,   278,   279,   280,   131,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,  1060,  1159,  1063,   977,
    1066,   292,  1162,  1165,    26,    27,    28,    29,    30,    31,
     635,  1154,  1168,  1174,  1170,  1175,   988,    37,    38,  1183,
    1177,  1179,  1181,  1184,  1187,  1189,  1188,   999,  1191,  1193,
    1195,  1003,  1198,  1201,  1205,  1209,  1210,  1211,  1215,  1219,
    1221,    59,   709,   853,  1108,    67,   104,   105,   106,   107,
     934,  1035,     0,     0,     0,     0,     0,     0,     0,     0,
     759,     0,     0,     0,   112,   301,     0,     0,     0,     0,
     114,     0,     0,     0,     0,   117,     0,     0,     0,     0,
     120,     0,     0,   302,     0,     0,     0,     0,     0,     0,
       0,     0,    71,   130,     0,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
     131,     0,     0,     0,     0,     0,  1070,     0,     0,     0,
       0,     0,  1074,     0,     0,     0,  1078,     0,     0,     0,
      26,    27,    28,    29,    30,    31,   143,     0,     0,     0,
       0,     0,     0,    37,    38,   278,   279,   280,     0,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,     0,     0,     0,     0,
       0,   760,   104,   105,   106,   107,     0,     0,     0,     0,
       0,     0,     0,     0,  1129,     0,     0,     0,  1133,  1134,
     112,   132,     0,     0,     0,     0,   114,     0,     0,     0,
       0,   144,     0,    71,   130,     0,   120,     0,   134,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,     0,  1169,     0,     0,   278,   279,
     280,   131,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
     433,    26,    27,    28,    29,    30,    31,   146,     0,     0,
       0,     0,     0,     0,    37,    38,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,   762,   104,   105,   106,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,   132,     0,     0,     0,     0,   114,     0,     0,
       0,     0,   117,     0,    71,   130,     0,   120,     0,   134,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,   278,
     279,   280,   131,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
       0,     0,    26,    27,    28,    29,    30,    31,   656,     0,
       0,     0,     0,     0,     0,    37,    38,   278,   279,   280,
       0,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,   132,     0,     0,     0,     0,   114,     0,
       0,     0,     0,   133,     0,    71,   130,     0,   120,     0,
     134,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
     278,   279,   280,   131,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,    26,    27,    28,    29,    30,    31,   660,
       0,     0,    71,   263,     0,     0,    37,    38,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,     0,     0,   765,   104,   105,   106,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,   132,     0,     0,     0,     0,   114,
       0,     0,     0,     0,   117,     0,    71,   263,     0,   120,
       0,   134,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   113,     0,     0,     0,     0,   114,     0,     0,     0,
       0,   117,     0,     0,   268,     0,   120,     0,   269,   278,
     279,   280,     0,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,   113,     0,     0,     0,     0,
     114,     0,     0,     0,     0,   117,     0,     0,   463,     0,
     120,     0,   464,    71,   263,     0,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,     0,
      71,   298,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      71,   263,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,     0,     0,   104,   105,   106,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,   113,     0,     0,     0,     0,   114,     0,     0,
       0,     0,   117,     0,     0,   636,     0,   120,     0,   637,
     104,   105,   106,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,   113,
       0,     0,     0,     0,   114,     0,     0,     0,     0,   117,
     104,   105,   106,   107,   120,     0,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   344,   345,
       0,     0,     0,     0,   114,     0,     0,     0,     0,   346,
       0,    71,    72,    73,   120,    74,   168,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,   799,    99,   100,   101,   102,     0,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    71,   130,     0,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,    26,
      27,    28,    29,    30,    31,     0,     0,     0,     0,   112,
     113,     0,    37,    38,     0,   114,     0,   115,   116,     0,
     117,     0,   118,     0,   119,   120,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   104,   105,   106,   107,     0,   292,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
     301,     0,     0,     0,     0,   114,     0,     0,     0,     0,
     117,    71,   263,   204,     0,   120,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,    99,   100,   101,   102,    71,   263,   103,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    71,   298,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,   846,     0,     0,     0,
       0,   104,   105,   106,   107,     0,     0,     0,     0,     0,
       0,     0,     0,  1007,     0,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,   114,     0,     0,     0,     0,
     117,     0,     0,     0,  1016,   120,   104,   105,   106,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1017,     0,     0,   112,   113,     0,     0,     0,     0,
     114,     0,     0,     0,     0,   117,   104,   105,   106,   107,
     120,     0,  1019,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,   113,     0,     0,     0,  1106,
     114,     0,     0,     0,     0,   117,     0,     0,     0,     0,
     120,   278,   279,   280,     0,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   540,     0,   278,   279,
     280,   292,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   627,     0,     0,     0,     0,   292,   278,
     279,   280,     0,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   642,     0,   278,   279,   280,   292,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   812,     0,     0,     0,     0,   292,   278,   279,   280,
       0,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,   278,   279,   280,   292,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,   278,
     279,   280,     0,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,   278,   279,   280,   292,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,   278,   279,   280,
       0,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,   278,   279,   280,   292,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,    -4,
       1,     0,     0,    -4,   292,     0,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,    -4,   963,     0,   964,     0,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,     0,     0,     0,     0,     0,
      -4,    -4,    -4,    -4,     0,     0,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,   516,    11,    12,   517,   518,    15,   519,    17,
       0,    18,     0,    20,    21,     0,    23,    24,     0,     0,
       0,     0,     0,   516,    11,    12,   517,   518,    15,   519,
      17,     0,    18,    36,    20,    21,     0,    23,    24,     0,
       0,     0,     0,    40,    41,    42,     0,     0,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,    52,     0,     0,    40,    41,    42,     0,     0,   516,
      11,    12,   517,   518,    15,   519,    17,     0,    18,     0,
      20,    21,    52,    23,    24,   278,   279,   280,     0,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
      36,   526,     0,     0,     0,   292,     0,     0,     0,     0,
      40,    41,    42,     0,   661,     0,     0,     0,     0,     0,
       0,     0,   543,     0,     0,     0,     0,     0,    52,   516,
      11,    12,   517,   518,    15,   519,    17,     0,    18,     0,
      20,    21,     0,    23,    24,     0,     0,     0,     0,     0,
     516,    11,    12,   517,   518,    15,   519,    17,     0,    18,
      36,    20,    21,     0,    23,    24,     0,     0,   544,     0,
      40,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,    52,     0,
       0,    40,    41,    42,     0,     0,   516,    11,    12,   517,
     518,    15,   519,    17,     0,    18,     0,    20,    21,    52,
      23,    24,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    36,   678,     0,
       0,     0,   292,     0,     0,     0,     0,    40,    41,    42,
       0,   708,     0,     0,     0,     0,     0,     0,     0,   700,
       0,     0,     0,     0,     0,    52,   516,    11,    12,   517,
     518,    15,   519,    17,     0,    18,     0,    20,    21,     0,
      23,    24,     0,     0,     0,     0,     0,     0,     0,     6,
       0,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,  1097,     0,    40,    41,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     0,     0,     8,     9,    52,    10,    11,    12,    13,
      14,    15,    16,    17,     0,    18,    19,    20,    21,    22,
      23,    24,     0,     0,     0,    25,    26,    27,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,     0,    37,
      38,     0,     0,     0,     0,  1148,    39,    40,    41,    42,
       0,     0,     0,     0,    43,     0,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,   516,    11,
      12,   517,   518,    15,   519,    17,     0,    18,     0,    20,
      21,     0,    23,    24,   278,   279,   280,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,    36,
       0,     0,     0,     0,   292,     0,     0,     0,   546,    40,
      41,    42,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    52,     0,     0,
       0,     0,   292,     0,     0,     0,     0,     0,     0,   989,
       0,   990,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,     0,     0,  1057,
       0,  1058,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,     0,   278,   279,
     280,   783,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,     0,     0,   278,   279,   280,   961,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,     0,
     278,   279,   280,   975,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,     0,     0,   278,   279,   280,  1069,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,   278,   279,   280,  1076,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,     0,   278,   279,
     280,  1077,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,     0,     0,   278,   279,   280,  1088,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,     0,
     278,   279,   280,  1091,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,     0,     0,   278,   279,   280,  1094,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,   278,   279,   280,  1102,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,     0,   278,   279,
     280,  1103,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,     0,     0,   278,   279,   280,  1114,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,     0,
     278,   279,   280,  1142,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,     0,     0,   278,   279,   280,  1144,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,   278,   279,   280,  1146,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,     0,   278,   279,
     280,  1156,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,     0,     0,   278,   279,   280,  1217,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,     0,
     278,   279,   280,  1220,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,   433,     0,   278,   279,   280,   499,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,   462,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,   499,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   278,   279,   280,   500,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
     278,   279,   280,   537,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,   278,   279,   280,   585,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,   586,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,   599,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   278,   279,   280,   600,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
     278,   279,   280,   601,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,   278,   279,   280,   602,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,   603,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,   604,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   278,   279,   280,   674,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
     278,   279,   280,   675,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,   278,   279,   280,   676,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,   749,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,   781,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   278,   279,   280,   782,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
     278,   279,   280,   811,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,   278,   279,   280,   904,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,   905,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,   921,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   278,   279,   280,   922,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
     278,   279,   280,   939,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,   278,   279,   280,   945,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,  1033,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,  1034,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   278,   279,   280,  1042,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
     278,   279,   280,  1045,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,   278,   279,   280,  1046,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,  1054,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,  1055,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   278,   279,   280,  1110,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
     278,   279,   280,  1112,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,   278,   279,   280,  1206,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,  1216,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,   278,
     279,   280,   564,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
     278,   279,   280,   566,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,   278,   279,   280,   568,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,   278,   279,   280,   570,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,   278,   279,   280,   572,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,   278,   279,   280,   574,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,   278,   279,   280,   576,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,   278,   279,   280,   578,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,   278,   279,   280,
     580,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,   278,   279,
     280,   582,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,   278,
     279,   280,   584,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
     278,   279,   280,   588,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,   278,   279,   280,   590,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,   278,   279,   280,   592,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,   278,   279,   280,   594,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,   278,   279,   280,   596,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,   278,   279,   280,   598,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,   278,   279,   280,   634,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,   278,   279,   280,
     680,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,   278,   279,
     280,   688,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,   278,
     279,   280,   691,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
     278,   279,   280,   692,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,   278,   279,   280,   704,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,   278,   279,   280,   828,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,   278,   279,   280,   830,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,   278,   279,   280,   832,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,   278,   279,   280,   834,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,   278,   279,   280,   835,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,   278,   279,   280,
     936,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,     0,   469,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,   474,   278,   279,   280,     0,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,     0,   475,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,   477,   278,
     279,   280,     0,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
       0,   482,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,   483,   278,   279,   280,     0,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,     0,   485,   278,   279,
     280,     0,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
     531,   278,   279,   280,     0,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,     0,   532,   278,   279,   280,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,   535,   278,   279,   280,
       0,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,     0,   541,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,   563,   278,   279,   280,     0,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,     0,   565,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,   567,   278,
     279,   280,     0,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
       0,   569,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,   571,   278,   279,   280,     0,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,     0,   573,   278,   279,
     280,     0,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
     575,   278,   279,   280,     0,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,     0,   577,   278,   279,   280,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,   579,   278,   279,   280,
       0,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,     0,   581,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,   583,   278,   279,   280,     0,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,     0,   587,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,   589,   278,
     279,   280,     0,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
       0,   591,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,   593,   278,   279,   280,     0,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,     0,   595,   278,   279,
     280,     0,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
     597,   278,   279,   280,     0,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,     0,   646,   278,   279,   280,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,   650,   278,   279,   280,
       0,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,     0,   657,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,   658,   278,   279,   280,     0,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,     0,   662,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,   663,   278,
     279,   280,     0,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
       0,   664,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,   665,   278,   279,   280,     0,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,     0,   666,   278,   279,
     280,     0,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
     696,   278,   279,   280,     0,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,     0,   703,   278,   279,   280,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,   827,   278,   279,   280,
       0,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,     0,   829,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,   831,   278,   279,   280,     0,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,     0,   833,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,   839,   278,
     279,   280,     0,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
       0,   898,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,   900,   278,   279,   280,     0,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,     0,   908,   278,   279,
     280,     0,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
     927,   278,   279,   280,     0,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,     0,   962,   278,   279,   280,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,   993,   278,   279,   280,
       0,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,     0,  1109,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,  1155,   278,   279,   280,     0,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292
};

static const short int yycheck[] =
{
       6,   271,   179,     4,     6,   182,     3,     6,   339,   909,
     910,     3,     6,     4,     4,     4,    45,     4,     4,     6,
       4,     6,     4,     6,     4,     4,     7,    67,   205,     5,
     207,     4,    67,   134,    86,     4,   624,    68,     5,   121,
     122,    68,    73,   133,   121,   122,    73,     0,   138,    53,
      54,    68,     6,   121,   122,     6,    73,   139,    34,    35,
      36,    37,   139,   132,    40,   121,   122,    34,    35,    36,
      37,   139,   269,    40,     7,   123,   124,   125,     7,     6,
     132,     6,   138,   131,   140,    76,    77,    78,    79,    80,
      76,    77,    78,    79,    80,   129,   130,   132,    52,   139,
    1000,    52,   299,   132,   139,     7,   112,   113,   114,   140,
     132,   117,   118,   140,   132,   121,    89,    90,   132,   118,
      89,    90,   128,   140,   118,   139,   132,   133,   134,   110,
      41,   132,   132,    44,   132,   141,   142,   139,   144,   129,
     130,   139,   148,   149,   134,   151,   136,   134,    49,   140,
     139,   141,   740,   790,   140,   139,    45,   139,    47,   139,
     139,   167,   168,   139,   121,   122,   132,   437,   269,   132,
     176,   348,   139,   139,   107,   108,   109,   110,   107,   108,
     109,   110,   139,   133,   190,   191,   132,   193,   138,   195,
       6,   368,   198,   199,   121,   122,   129,   130,   299,    45,
     129,   130,    45,   136,   210,   107,   108,   109,   110,     7,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    45,    68,   258,   259,   260,   261,    73,    27,
      28,   849,    30,   269,   461,     6,   133,   464,   132,    47,
     134,   138,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,    68,   271,    68,
     296,   297,    73,   299,    73,   301,   132,  1025,     5,  1027,
     306,  1029,   139,   133,   310,   121,   122,   313,   138,   107,
     108,   109,   110,   319,   320,   321,   139,   323,   324,   325,
     326,   327,   328,   329,   132,   140,   134,    34,    35,    36,
      37,   129,   130,    40,    45,   341,   342,   343,   344,   345,
     346,   338,   339,   349,    68,   133,   338,   339,   354,    73,
     138,     6,   358,   359,    58,    59,     4,     5,   364,   140,
     461,    41,     6,   464,    44,    45,    68,   373,   133,   470,
    1098,    73,   378,   138,    10,   381,     4,    13,    14,     4,
     121,   122,   121,   122,     4,    68,    34,    35,    36,    37,
      73,     4,    40,   132,    68,   132,   164,   380,   166,    73,
     139,   132,    68,   134,   172,    68,   132,    73,   176,    68,
      73,   608,   132,  1141,    73,  1143,   140,  1145,   121,   122,
    1008,  1149,   129,   130,  1061,     6,   432,  1064,    45,   136,
    1067,   121,   122,   439,   438,   138,     4,   140,   140,   132,
     637,   121,   122,   121,   122,   132,   214,   134,   138,  1177,
     140,  1179,   132,  1181,   437,   461,   462,   140,   464,   139,
     138,   467,   732,   733,   470,   132,   140,   473,     5,   121,
     122,   132,   478,   479,   140,   481,   132,   140,   484,   121,
     122,   140,   132,   489,   134,   682,   138,   684,   685,   686,
    1127,   121,   122,   499,   500,   132,   138,    34,    35,    36,
      37,     4,   508,    40,     6,   121,   122,   608,   138,   121,
     122,     6,   121,   122,   150,   121,   122,   523,   132,   155,
     134,  1158,   138,   138,  1161,   140,   138,  1164,     6,   138,
    1167,   537,   138,   539,   540,   132,   637,   134,     5,   121,
     122,   132,   546,   134,   180,   121,   122,   121,   122,   185,
     186,     8,   139,  1190,   885,  1192,   138,  1194,   121,   122,
     129,   130,   138,   546,   138,   134,   132,   136,   336,   337,
      41,    92,   141,    44,    45,   138,    47,   345,   132,   585,
     586,   682,    92,   684,   685,   686,    92,    61,    62,    63,
      64,   139,    66,   599,   600,   601,   602,   603,   604,   605,
      74,    75,   608,   129,   130,   609,   612,   132,     8,   134,
     136,   617,   129,   130,   132,   129,   130,   134,   134,   136,
     134,   627,   136,   132,   141,   134,   630,   141,   132,    44,
      45,   637,    47,   111,   112,   113,   642,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   132,   139,
     134,   634,     6,   131,   111,   112,   113,   139,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   132,
     132,   134,   134,   132,   131,   681,   682,   683,   684,   685,
     686,     6,     7,   689,   690,   132,   132,   134,   134,   695,
    1021,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   132,    57,   134,   711,   712,   131,   134,   715,
     136,   111,   112,   113,   132,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   132,   132,   134,   134,
     498,   131,     6,     7,   132,   741,   134,   132,   132,   134,
     140,   132,   132,   749,   134,   513,   138,     8,   140,   138,
     733,   140,   138,   138,   140,   140,   132,   111,   112,   113,
     766,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,     4,   139,   780,   781,   782,   131,   138,   134,
     140,   787,    41,    42,    43,    44,    45,    46,    47,    48,
     138,    50,   140,    52,    53,   139,    55,    56,   434,   435,
     121,   122,   123,   124,   125,   811,   812,   813,   139,   138,
     131,   140,     6,    72,   820,   138,   138,   140,   140,   825,
     138,   134,   140,    82,    83,    84,     4,   138,     6,   140,
     138,     6,   140,   138,   817,   140,   842,   841,   138,   136,
     140,   100,   138,   138,   140,   140,   138,    92,   140,   853,
     111,   112,   113,  1030,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   871,   872,   139,     6,   132,
     131,   639,   133,     6,     6,   881,   134,   881,     4,   139,
       5,   140,   131,   136,     7,    45,   134,     6,   885,    47,
       7,     7,   133,   885,     6,    87,     7,     7,   904,   905,
      89,   139,   138,   133,   133,   138,   674,   675,   676,     6,
     916,     4,   135,     7,   136,   921,   922,     7,     7,     7,
       7,     7,  1099,     7,   140,   140,   139,   139,     7,     7,
     132,     7,   136,   939,   132,   132,   111,   112,   113,   945,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   139,   132,     4,     6,   134,   131,   963,     6,     6,
       6,   135,     6,   118,     7,     6,   139,   111,   112,   113,
     976,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,     7,   989,     4,   991,     7,   131,     7,     7,
     996,   135,   111,   112,   113,  1001,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,     7,   644,   645,
       7,   647,   131,     7,     7,     7,   652,   653,  1024,   787,
    1026,     7,  1028,     7,  1021,     7,     6,  1033,  1034,  1021,
       6,     6,     6,  1039,     7,     4,     7,     4,     6,  1045,
    1046,     6,     6,   139,   136,     7,     6,   132,  1054,     6,
     133,  1057,   133,   135,     6,     6,     6,   693,   694,   139,
     113,   697,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,  1079,   139,     6,     6,    88,   131,   139,
       6,   136,     6,  1089,     4,     6,  1092,     6,     6,  1095,
     135,   859,     6,   861,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     6,  1110,     6,  1112,     6,   131,     6,
       6,     6,     6,     6,     6,     6,     6,     6,   886,     6,
     888,   757,   890,     6,     6,   761,     7,    88,     4,   139,
       7,   767,   768,   769,     6,     6,   772,   773,   774,   775,
     776,   777,   778,     6,     6,   136,     6,   111,   112,   113,
    1154,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,     6,   140,     6,     6,   138,   131,    85,   139,
       6,     5,     5,   139,    90,   133,   139,    88,  1184,     6,
     139,  1185,   138,  1187,   139,   139,   139,     6,     6,     6,
     138,   140,   139,   139,     6,   140,     6,     6,     6,  1205,
    1206,     6,     6,  1207,   840,     6,     3,     4,   140,   138,
    1216,   139,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,   140,   139,     6,   139,
     138,   111,   112,   113,    41,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,  1024,     6,  1026,   895,
    1028,   131,     6,     6,    61,    62,    63,    64,    65,    66,
     140,   139,     6,     6,    85,     5,   912,    74,    75,   140,
     139,   139,   139,   139,   139,     6,   140,   923,     6,     6,
      85,   927,     6,     6,   139,     6,     6,     6,     6,     6,
       6,     3,   549,   748,  1079,     3,   103,   104,   105,   106,
     845,   984,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
     137,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,  1032,    -1,    -1,    -1,
      -1,    -1,  1038,    -1,    -1,    -1,  1042,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,   111,   112,   113,    -1,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,     6,   103,   104,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1100,    -1,    -1,    -1,  1104,  1105,
     121,   122,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      -1,   132,    -1,     3,     4,    -1,   137,    -1,   139,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,  1151,    -1,    -1,   111,   112,
     113,    41,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
     133,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,     6,   103,   104,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,    -1,
      -1,    -1,   132,    -1,     3,     4,    -1,   137,    -1,   139,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,    41,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    61,    62,    63,    64,    65,    66,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,   111,   112,   113,
      -1,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,
      -1,    -1,    -1,   132,    -1,     3,     4,    -1,   137,    -1,
     139,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,    41,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    61,    62,    63,    64,    65,    66,   140,
      -1,    -1,     3,     4,    -1,    -1,    74,    75,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,     6,   103,   104,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,   132,    -1,     3,     4,    -1,   137,
      -1,   139,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,   103,   104,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,   135,    -1,   137,    -1,   139,   111,
     112,   113,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,   135,    -1,
     137,    -1,   139,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,   103,   104,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,    -1,
      -1,    -1,   132,    -1,    -1,   135,    -1,   137,    -1,   139,
     103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
      -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,   132,
     103,   104,   105,   106,   137,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
      -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,   132,
      -1,     3,     4,     5,   137,     7,   139,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     6,    34,    35,    36,    37,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,   121,
     122,    -1,    74,    75,    -1,   127,    -1,   129,   130,    -1,
     132,    -1,   134,    -1,   136,   137,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   103,   104,   105,   106,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
     132,     3,     4,     5,    -1,   137,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    35,    36,    37,     3,     4,    40,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     6,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
     132,    -1,    -1,    -1,     6,   137,   103,   104,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,
     127,    -1,    -1,    -1,    -1,   132,   103,   104,   105,   106,
     137,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,     6,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
     137,   111,   112,   113,    -1,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     8,    -1,   111,   112,
     113,   131,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     8,    -1,    -1,    -1,    -1,   131,   111,
     112,   113,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,     8,    -1,   111,   112,   113,   131,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,     8,    -1,    -1,    -1,    -1,   131,   111,   112,   113,
      -1,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,   111,   112,   113,   131,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,   111,
     112,   113,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,   111,   112,   113,   131,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,   111,   112,   113,
      -1,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,   111,   112,   113,   131,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,     0,
       1,    -1,    -1,     4,   131,    -1,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    33,   138,    -1,   140,    -1,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    89,    -1,
      91,    -1,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    72,    52,    53,    -1,    55,    56,    -1,
      -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,   100,    -1,    -1,    82,    83,    84,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    -1,
      52,    53,   100,    55,    56,   111,   112,   113,    -1,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      72,   140,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      82,    83,    84,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,   100,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      72,    52,    53,    -1,    55,    56,    -1,    -1,   140,    -1,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,
      -1,    82,    83,    84,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    -1,    52,    53,   100,
      55,    56,   111,   112,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    72,   140,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,   100,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   140,    -1,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    38,    39,   100,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    -1,    74,
      75,    -1,    -1,    -1,    -1,   140,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    89,    -1,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    -1,    52,
      53,    -1,    55,    56,   111,   112,   113,    -1,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    72,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   135,    82,
      83,    84,   111,   112,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   100,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,   140,   111,   112,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,   140,   111,   112,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   140,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   140,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   140,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   140,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   140,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   140,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   140,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   140,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   140,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   140,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   140,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   140,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   140,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   140,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   140,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   140,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   140,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   140,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,   133,    -1,   111,   112,   113,   138,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,
     113,   138,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,   111,   112,   113,   138,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,   111,   112,   113,   138,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
     111,   112,   113,   138,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,   111,   112,   113,   138,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,
     113,   138,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,   111,   112,   113,   138,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,   111,   112,   113,   138,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
     111,   112,   113,   138,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,   111,   112,   113,   138,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,
     113,   138,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,   111,   112,   113,   138,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,   111,   112,   113,   138,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
     111,   112,   113,   138,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,   111,   112,   113,   138,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,
     113,   138,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,   111,   112,   113,   138,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,   111,   112,   113,   138,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
     111,   112,   113,   138,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,   111,   112,   113,   138,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,
     113,   138,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,   111,   112,   113,   138,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,   111,   112,   113,   138,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
     111,   112,   113,   138,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,   111,   112,   113,   138,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,
     113,   138,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,   111,   112,   113,   138,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,   111,   112,   113,   138,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
     111,   112,   113,   138,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,   111,   112,   113,   138,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,
     113,   138,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,   111,   112,   113,   138,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,   111,   112,   113,   138,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
     111,   112,   113,   138,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,   111,   112,   113,   138,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,
     113,   138,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,   111,
     112,   113,   135,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
     111,   112,   113,   135,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,   111,   112,   113,   135,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,   111,   112,   113,   135,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,   111,   112,   113,   135,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,   111,   112,   113,   135,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,   111,   112,   113,   135,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,   111,   112,   113,   135,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,   111,   112,   113,
     135,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,   111,   112,
     113,   135,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,   111,
     112,   113,   135,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
     111,   112,   113,   135,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,   111,   112,   113,   135,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,   111,   112,   113,   135,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,   111,   112,   113,   135,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,   111,   112,   113,   135,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,   111,   112,   113,   135,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,   111,   112,   113,   135,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,   111,   112,   113,
     135,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,   111,   112,
     113,   135,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,   111,
     112,   113,   135,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
     111,   112,   113,   135,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,   111,   112,   113,   135,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,   111,   112,   113,   135,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,   111,   112,   113,   135,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,   111,   112,   113,   135,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,   111,   112,   113,   135,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,   111,   112,   113,   135,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,   111,   112,   113,
     135,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,
     111,   112,   113,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,   133,   111,   112,   113,    -1,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,   133,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   111,
     112,   113,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,   133,   111,   112,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,   133,   111,   112,   113,    -1,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   111,   112,
     113,    -1,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
     133,   111,   112,   113,    -1,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,   133,   111,   112,   113,    -1,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,   133,   111,   112,   113,
      -1,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,
     111,   112,   113,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,   133,   111,   112,   113,    -1,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,   133,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   111,
     112,   113,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,   133,   111,   112,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,   133,   111,   112,   113,    -1,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   111,   112,
     113,    -1,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
     133,   111,   112,   113,    -1,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,   133,   111,   112,   113,    -1,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,   133,   111,   112,   113,
      -1,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,
     111,   112,   113,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,   133,   111,   112,   113,    -1,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,   133,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   111,
     112,   113,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,   133,   111,   112,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,   133,   111,   112,   113,    -1,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   111,   112,
     113,    -1,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
     133,   111,   112,   113,    -1,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,   133,   111,   112,   113,    -1,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,   133,   111,   112,   113,
      -1,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,
     111,   112,   113,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,   133,   111,   112,   113,    -1,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,   133,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   111,
     112,   113,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,   133,   111,   112,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,   133,   111,   112,   113,    -1,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   111,   112,
     113,    -1,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
     133,   111,   112,   113,    -1,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,   133,   111,   112,   113,    -1,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,   133,   111,   112,   113,
      -1,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,
     111,   112,   113,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,   133,   111,   112,   113,    -1,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,   133,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   111,
     112,   113,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,   133,   111,   112,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,   133,   111,   112,   113,    -1,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   111,   112,
     113,    -1,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
     133,   111,   112,   113,    -1,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,   133,   111,   112,   113,    -1,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,   133,   111,   112,   113,
      -1,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,
     111,   112,   113,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,   133,   111,   112,   113,    -1,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     1,   143,   144,     6,     0,     4,    33,    38,    39,
      41,    42,    43,    44,    45,    46,    47,    48,    50,    51,
      52,    53,    54,    55,    56,    60,    61,    62,    63,    64,
      65,    66,    68,    69,    70,    71,    72,    74,    75,    81,
      82,    83,    84,    89,    91,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   145,   147,   148,   167,   168,
     169,   172,   173,   174,   175,   176,   177,   178,   193,   194,
     195,     3,     4,     5,     7,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    34,
      35,    36,    37,    40,   103,   104,   105,   106,   107,   108,
     109,   110,   121,   122,   127,   129,   130,   132,   134,   136,
     137,   165,   166,   196,   197,   208,   132,     6,   139,     6,
       4,    41,   122,   132,   139,   169,   172,   178,   196,   202,
     203,   132,   132,    67,   132,   202,    67,   202,   132,   132,
      49,   132,    45,    45,    45,    44,    45,    47,    47,    41,
      44,    45,    47,   132,   139,   121,   122,   132,   139,   198,
     199,   198,   139,    41,    44,    45,   139,   198,     4,   139,
      45,     4,   139,     6,     6,    41,    44,     4,     4,     4,
     132,   132,    45,   132,     4,   139,   205,     4,   132,   132,
       6,     4,     4,    45,     5,   139,   208,   139,   208,     4,
     134,   136,   141,   166,     4,   139,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   132,
     132,   132,   132,     4,   196,   196,   196,   196,   135,   139,
     196,     4,    89,    90,     4,   196,     6,     6,   111,   112,
     113,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   131,     6,     5,   196,   134,   139,     4,   139,
     196,   122,   140,   196,   203,   204,     8,    92,   196,   196,
     132,   196,    92,   132,    92,   196,   196,   202,   196,   139,
     132,   132,   202,   139,   139,   132,   132,   132,   132,   132,
       4,   198,   198,   198,   196,   196,   121,   122,   139,   139,
     198,   139,   139,   139,   121,   122,   132,   198,   139,   134,
     171,   202,     4,     6,   134,   171,   202,   202,   134,   134,
       6,   196,   196,    86,   132,   196,   136,   196,   139,    92,
     196,   196,     6,   132,   171,     6,   171,     6,   134,   196,
       4,   139,   198,   149,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,     4,   208,   208,   208,
     208,     5,   134,   133,     7,   110,   204,   135,     7,   165,
     166,   136,     7,   134,     6,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     133,   138,   138,   135,   139,   196,   196,   134,   204,   133,
     138,   140,   196,    45,   133,   133,   196,   133,    45,    47,
     196,    47,   133,   133,     7,   133,   196,   196,   196,     7,
     196,   196,   196,   196,   196,   196,   196,   133,   138,   138,
     138,   198,   198,   169,   170,   171,   172,   170,   138,   196,
     196,   196,   196,   138,   171,   196,    41,    44,    45,    47,
     140,   168,     6,     7,     6,   196,   140,     7,     7,   196,
     196,   133,   133,    87,   196,   133,    89,   138,   171,   139,
       8,   133,   196,   140,   140,   196,   135,   166,   196,   139,
       4,    76,    77,    78,    79,    80,   140,   152,   156,   159,
     161,   162,   164,   133,   135,   133,   135,   133,   135,   133,
     135,   133,   135,   133,   135,   133,   135,   133,   135,   133,
     135,   133,   135,   133,   135,   138,   138,   133,   135,   133,
     135,   133,   135,   133,   135,   133,   135,   133,   135,   138,
     138,   138,   138,   138,   138,   134,   136,   133,   138,   138,
     133,   133,   138,   202,   202,   140,   136,   165,   166,   208,
     196,     6,     4,     4,   139,   206,   135,     8,     6,   118,
     146,   204,   196,   204,   135,   140,   135,   139,   140,     7,
     196,   203,     8,   196,     7,     7,   133,     7,   196,   196,
     133,   196,     7,     7,   196,     7,   140,   133,   133,   196,
     140,   140,   133,   133,   133,   133,   133,   136,   198,   196,
     196,   140,   140,   196,   138,   138,   138,   198,   140,   179,
     135,   132,   139,   132,   139,   139,   139,   196,   135,   139,
     139,   135,   135,     7,     7,   132,   133,     7,   136,   196,
     140,   196,   196,   133,   135,   136,   166,   208,   140,   149,
     153,   132,   132,   139,   163,   132,     6,   196,   196,   196,
     196,   196,   196,   196,   196,   196,     4,   204,   208,   196,
       6,     6,   135,     4,    89,    90,   196,     6,     6,     6,
       7,   134,   205,   207,     6,   196,   118,   208,   133,   138,
     140,   204,   198,   196,     6,   202,   202,     7,   202,     6,
       6,     7,     6,   202,   202,     6,   139,     7,     7,     7,
       6,    57,     7,     7,     7,     7,     7,     7,     7,     4,
     138,   138,   138,   140,   198,   198,   198,   138,    68,    73,
     191,   192,     6,   196,   204,   196,   204,   204,   204,     6,
       6,   196,   196,     6,     6,   202,   202,   196,     7,   202,
       4,   138,     8,     8,   133,     7,     6,     4,     6,   140,
     132,   196,   196,   201,   202,   139,   196,   133,   135,   133,
     135,   133,   135,   133,   135,   135,   133,   133,   133,   133,
     165,     7,   165,   166,   136,     7,     6,   205,   196,   138,
     140,     6,     6,   146,   196,   135,   140,     6,     6,    52,
       6,    52,   202,     6,   202,     6,     6,   196,   202,   202,
     202,    58,    59,   202,   202,   202,   202,   202,   202,   202,
       6,     7,   196,   196,   196,   139,   138,   140,   138,   140,
     138,   140,   196,   198,     6,   139,   140,   192,   133,   140,
     133,   140,   140,   140,   138,   138,     6,     6,   133,   132,
     139,   200,    88,   196,   196,   196,   139,   166,     6,   150,
     196,   138,   138,   138,   140,   151,   196,   133,   136,   202,
     208,   196,     6,     4,   206,     6,   135,   205,   208,   138,
     135,   198,   198,     6,     6,   138,     6,     6,     6,   196,
     196,     4,     6,     6,     6,     6,     6,     6,     6,   196,
     208,   140,   133,   138,   140,   170,   198,     6,   182,   198,
       6,   183,   198,     6,   184,   140,   138,   202,     6,     6,
       6,     6,   196,   196,     7,   201,   201,    88,   202,   138,
     140,     8,   140,   133,   196,   133,   138,   196,   196,   202,
     139,   138,   140,   202,     4,     6,     6,     6,     7,     6,
     136,     6,   196,     6,     6,   196,     6,     6,     6,     6,
       6,   139,   196,   140,   138,   139,   138,   139,   138,   139,
     139,   196,   138,   138,   138,   200,   133,   140,   139,    85,
     196,   196,   138,   154,   196,   138,   138,   201,   196,     6,
       6,   133,   205,    90,   138,   138,   170,   138,   140,   196,
     198,   191,   196,   198,   191,   196,   198,   191,   171,   140,
     202,   196,   196,    88,   202,   196,   140,   140,   202,   139,
     196,   196,   140,     6,   196,     5,   140,   196,   140,   138,
     140,   140,   138,   140,   140,   138,   140,   140,   180,   139,
     138,   140,   140,   140,   139,   138,     6,   140,   151,   133,
     138,     6,   138,   138,   140,     6,   185,   196,     6,     6,
     186,   196,     6,     6,   187,   196,     6,   191,   171,   202,
       6,     6,     6,   202,   202,     6,   140,   157,   196,   196,
       5,   139,   140,   139,   140,   139,   140,   140,   140,   181,
     140,   138,   140,     6,   139,   133,   140,   138,   191,     6,
     188,   191,     6,   189,   191,     6,   190,   191,     6,   202,
      85,   155,   208,   160,     6,     5,   140,   139,   140,   139,
     140,   139,   140,   140,   139,   138,   140,   139,   140,     6,
     191,     6,   191,     6,   191,    85,   196,   208,     6,   158,
     208,     6,   140,   140,   140,   139,   138,   138,   140,     6,
       6,     6,   196,   196,   208,     6,   138,   140,   196,     6,
     140,     6
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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


  yyvsp[0] = yylval;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

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

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
    { List_Delete((yyvsp[0].l)); return 1; ;}
    break;

  case 11:
#line 159 "Gmsh.y"
    { List_Delete((yyvsp[0].l)); return 1; ;}
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
    { return 1; ;}
    break;

  case 15:
#line 163 "Gmsh.y"
    { List_Delete((yyvsp[0].l)); return 1; ;}
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
      (yyval.c) = "w";
    ;}
    break;

  case 22:
#line 177 "Gmsh.y"
    {
      (yyval.c) = "a";
    ;}
    break;

  case 23:
#line 184 "Gmsh.y"
    {
      Msg(DIRECT, (yyvsp[-2].c));
      Free((yyvsp[-2].c));
    ;}
    break;

  case 24:
#line 189 "Gmsh.y"
    {
      char tmpstring[1024];
      FixRelativePath((yyvsp[-1].c), tmpstring);
      FILE *fp = fopen(tmpstring, (yyvsp[-2].c));
      if(!fp){
	yymsg(GERROR, "Unable to open file '%s'", tmpstring);
      }
      else{
	fprintf(fp, "%s\n", (yyvsp[-4].c));
	fclose(fp);
      }
      Free((yyvsp[-4].c));
      Free((yyvsp[-1].c));
    ;}
    break;

  case 25:
#line 204 "Gmsh.y"
    {
      char tmpstring[1024];
      int i = PrintListOfDouble((yyvsp[-4].c), (yyvsp[-2].l), tmpstring);
      if(i < 0) 
	yymsg(GERROR, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(GERROR, "%d extra argument%s in Printf", i, (i>1)?"s":"");
      else
	Msg(DIRECT, tmpstring);
      Free((yyvsp[-4].c));
      List_Delete((yyvsp[-2].l));
    ;}
    break;

  case 26:
#line 217 "Gmsh.y"
    {
      char tmpstring[1024];
      int i = PrintListOfDouble((yyvsp[-6].c), (yyvsp[-4].l), tmpstring);
      if(i < 0) 
	yymsg(GERROR, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(GERROR, "%d extra argument%s in Printf", i, (i>1)?"s":"");
      else{
	char tmpstring2[1024];
	FixRelativePath((yyvsp[-1].c), tmpstring2);
	FILE *fp = fopen(tmpstring2, (yyvsp[-2].c));
	if(!fp){
	  yymsg(GERROR, "Unable to open file '%s'", tmpstring2);
	}
	else{
	  fprintf(fp, "%s\n", tmpstring);
	  fclose(fp);
	}
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-1].c));
      List_Delete((yyvsp[-4].l));
    ;}
    break;

  case 27:
#line 246 "Gmsh.y"
    { 
      if(!strcmp((yyvsp[-5].c), "View") && !CheckViewErrorFlags(View)){
	EndView(View, 0, yyname, (yyvsp[-4].c));
      }
      Free((yyvsp[-5].c)); Free((yyvsp[-4].c));
    ;}
    break;

  case 28:
#line 253 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-7].c), "View") && !CheckViewErrorFlags(View)){
	EndView(View, 0, yyname, (yyvsp[-6].c));
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-6].c)); Free((yyvsp[-5].c));
    ;}
    break;

  case 29:
#line 263 "Gmsh.y"
    {
      View = BeginView(1); 
      for(int i = 0; i < VIEW_NB_ELEMENT_TYPES; i++){
	ViewErrorFlags[i] = 0;
      }
    ;}
    break;

  case 36:
#line 279 "Gmsh.y"
    { ViewCoord[ViewCoordIdx] = (yyvsp[0].d); ViewCoordIdx++; ;}
    break;

  case 37:
#line 281 "Gmsh.y"
    { ViewCoord[ViewCoordIdx] = (yyvsp[0].d); ViewCoordIdx++; ;}
    break;

  case 38:
#line 286 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[0].d)); ;}
    break;

  case 39:
#line 288 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[0].d)); ;}
    break;

  case 40:
#line 293 "Gmsh.y"
    {
      if(!strcmp((yyvsp[0].c), "SP")){
	ViewElementIdx = 0; ViewNumNodes = 1; ViewNumComp = 1;
	ViewValueList = View->SP; ViewNumList = &View->NbSP;
      }
      else if(!strcmp((yyvsp[0].c), "VP")){
	ViewElementIdx = 1; ViewNumNodes = 1; ViewNumComp = 3;
	ViewValueList = View->VP; ViewNumList = &View->NbVP;
      }
      else if(!strcmp((yyvsp[0].c), "TP")){
	ViewElementIdx = 2; ViewNumNodes = 1; ViewNumComp = 9;
	ViewValueList = View->TP; ViewNumList = &View->NbTP;
      }
      else if(!strcmp((yyvsp[0].c), "SL")){
	ViewElementIdx = 3; ViewNumNodes = 2; ViewNumComp = 1;
	ViewValueList = View->SL; ViewNumList = &View->NbSL;
      }
      else if(!strcmp((yyvsp[0].c), "VL")){
	ViewElementIdx = 4; ViewNumNodes = 2; ViewNumComp = 3;
	ViewValueList = View->VL; ViewNumList = &View->NbVL;
      }
      else if(!strcmp((yyvsp[0].c), "TL")){
	ViewElementIdx = 5; ViewNumNodes = 2; ViewNumComp = 9;
	ViewValueList = View->TL; ViewNumList = &View->NbTL;
      }
      else if(!strcmp((yyvsp[0].c), "ST")){
	ViewElementIdx = 6; ViewNumNodes = 3; ViewNumComp = 1;
	ViewValueList = View->ST; ViewNumList = &View->NbST;
      }
      else if(!strcmp((yyvsp[0].c), "VT")){
	ViewElementIdx = 7; ViewNumNodes = 3; ViewNumComp = 3;
	ViewValueList = View->VT; ViewNumList = &View->NbVT;
      }
      else if(!strcmp((yyvsp[0].c), "TT")){
	ViewElementIdx = 8; ViewNumNodes = 3; ViewNumComp = 9;
	ViewValueList = View->TT; ViewNumList = &View->NbTT;
      }
      else if(!strcmp((yyvsp[0].c), "SQ")){
	ViewElementIdx = 9; ViewNumNodes = 4; ViewNumComp = 1;
	ViewValueList = View->SQ; ViewNumList = &View->NbSQ;
      }
      else if(!strcmp((yyvsp[0].c), "VQ")){
	ViewElementIdx = 10; ViewNumNodes = 4; ViewNumComp = 3;
	ViewValueList = View->VQ; ViewNumList = &View->NbVQ;
      }
      else if(!strcmp((yyvsp[0].c), "TQ")){
	ViewElementIdx = 11; ViewNumNodes = 4; ViewNumComp = 9;
	ViewValueList = View->TQ; ViewNumList = &View->NbTQ;
      }
      else if(!strcmp((yyvsp[0].c), "SS")){
	ViewElementIdx = 12; ViewNumNodes = 4; ViewNumComp = 1;
	ViewValueList = View->SS; ViewNumList = &View->NbSS;
      }
      else if(!strcmp((yyvsp[0].c), "VS")){
	ViewElementIdx = 13; ViewNumNodes = 4; ViewNumComp = 3;
	ViewValueList = View->VS; ViewNumList = &View->NbVS;
      }
      else if(!strcmp((yyvsp[0].c), "TS")){
	ViewElementIdx = 14; ViewNumNodes = 4; ViewNumComp = 9;
	ViewValueList = View->TS; ViewNumList = &View->NbTS;
      }
      else if(!strcmp((yyvsp[0].c), "SH")){
	ViewElementIdx = 15; ViewNumNodes = 8; ViewNumComp = 1;
	ViewValueList = View->SH; ViewNumList = &View->NbSH;
      }
      else if(!strcmp((yyvsp[0].c), "VH")){
	ViewElementIdx = 16; ViewNumNodes = 8; ViewNumComp = 3;
	ViewValueList = View->VH; ViewNumList = &View->NbVH;
      }
      else if(!strcmp((yyvsp[0].c), "TH")){
	ViewElementIdx = 17; ViewNumNodes = 8; ViewNumComp = 9;
	ViewValueList = View->TH; ViewNumList = &View->NbTH;
      }
      else if(!strcmp((yyvsp[0].c), "SI")){
	ViewElementIdx = 18; ViewNumNodes = 6; ViewNumComp = 1;
	ViewValueList = View->SI; ViewNumList = &View->NbSI;
      }
      else if(!strcmp((yyvsp[0].c), "VI")){
	ViewElementIdx = 19; ViewNumNodes = 6; ViewNumComp = 3;
	ViewValueList = View->VI; ViewNumList = &View->NbVI;
      }
      else if(!strcmp((yyvsp[0].c), "TI")){
	ViewElementIdx = 20; ViewNumNodes = 6; ViewNumComp = 9;
	ViewValueList = View->TI; ViewNumList = &View->NbTI;
      }
      else if(!strcmp((yyvsp[0].c), "SY")){
	ViewElementIdx = 21; ViewNumNodes = 5; ViewNumComp = 1;
	ViewValueList = View->SY; ViewNumList = &View->NbSY;
      }
      else if(!strcmp((yyvsp[0].c), "VY")){
	ViewElementIdx = 22; ViewNumNodes = 5; ViewNumComp = 3;
	ViewValueList = View->VY; ViewNumList = &View->NbVY;
      }
      else if(!strcmp((yyvsp[0].c), "TY")){
	ViewElementIdx = 23; ViewNumNodes = 5; ViewNumComp = 9;
	ViewValueList = View->TY; ViewNumList = &View->NbTY;
      }
      else if(!strcmp((yyvsp[0].c), "SL2")){
	ViewElementIdx = 3; ViewNumNodes = 3; ViewNumComp = 1;
	ViewValueList = View->SL2; ViewNumList = &View->NbSL2;
      }
      else if(!strcmp((yyvsp[0].c), "VL2")){
	ViewElementIdx = 4; ViewNumNodes = 3; ViewNumComp = 3;
	ViewValueList = View->VL2; ViewNumList = &View->NbVL2;
      }
      else if(!strcmp((yyvsp[0].c), "TL2")){
	ViewElementIdx = 5; ViewNumNodes = 3; ViewNumComp = 9;
	ViewValueList = View->TL2; ViewNumList = &View->NbTL2;
      }
      else if(!strcmp((yyvsp[0].c), "ST2")){
	ViewElementIdx = 6; ViewNumNodes = 6; ViewNumComp = 1;
	ViewValueList = View->ST2; ViewNumList = &View->NbST2;
      }
      else if(!strcmp((yyvsp[0].c), "VT2")){
	ViewElementIdx = 7; ViewNumNodes = 6; ViewNumComp = 3;
	ViewValueList = View->VT2; ViewNumList = &View->NbVT2;
      }
      else if(!strcmp((yyvsp[0].c), "TT2")){
	ViewElementIdx = 8; ViewNumNodes = 6; ViewNumComp = 9;
	ViewValueList = View->TT2; ViewNumList = &View->NbTT2;
      }
      else if(!strcmp((yyvsp[0].c), "SQ2")){
	ViewElementIdx = 9; ViewNumNodes = 9; ViewNumComp = 1;
	ViewValueList = View->SQ2; ViewNumList = &View->NbSQ2;
      }
      else if(!strcmp((yyvsp[0].c), "VQ2")){
	ViewElementIdx = 10; ViewNumNodes = 9; ViewNumComp = 3;
	ViewValueList = View->VQ2; ViewNumList = &View->NbVQ2;
      }
      else if(!strcmp((yyvsp[0].c), "TQ2")){
	ViewElementIdx = 11; ViewNumNodes = 9; ViewNumComp = 9;
	ViewValueList = View->TQ2; ViewNumList = &View->NbTQ2;
      }
      else if(!strcmp((yyvsp[0].c), "SS2")){
	ViewElementIdx = 12; ViewNumNodes = 10; ViewNumComp = 1;
	ViewValueList = View->SS2; ViewNumList = &View->NbSS2;
      }
      else if(!strcmp((yyvsp[0].c), "VS2")){
	ViewElementIdx = 13; ViewNumNodes = 10; ViewNumComp = 3;
	ViewValueList = View->VS2; ViewNumList = &View->NbVS2;
      }
      else if(!strcmp((yyvsp[0].c), "TS2")){
	ViewElementIdx = 14; ViewNumNodes = 10; ViewNumComp = 9;
	ViewValueList = View->TS2; ViewNumList = &View->NbTS2;
      }
      else if(!strcmp((yyvsp[0].c), "SH2")){
	ViewElementIdx = 15; ViewNumNodes = 27; ViewNumComp = 1;
	ViewValueList = View->SH2; ViewNumList = &View->NbSH2;
      }
      else if(!strcmp((yyvsp[0].c), "VH2")){
	ViewElementIdx = 16; ViewNumNodes = 27; ViewNumComp = 3;
	ViewValueList = View->VH2; ViewNumList = &View->NbVH2;
      }
      else if(!strcmp((yyvsp[0].c), "TH2")){
	ViewElementIdx = 17; ViewNumNodes = 27; ViewNumComp = 9;
	ViewValueList = View->TH2; ViewNumList = &View->NbTH2;
      }
      else if(!strcmp((yyvsp[0].c), "SI2")){
	ViewElementIdx = 18; ViewNumNodes = 18; ViewNumComp = 1;
	ViewValueList = View->SI2; ViewNumList = &View->NbSI2;
      }
      else if(!strcmp((yyvsp[0].c), "VI2")){
	ViewElementIdx = 19; ViewNumNodes = 18; ViewNumComp = 3;
	ViewValueList = View->VI2; ViewNumList = &View->NbVI2;
      }
      else if(!strcmp((yyvsp[0].c), "TI2")){
	ViewElementIdx = 20; ViewNumNodes = 18; ViewNumComp = 9;
	ViewValueList = View->TI2; ViewNumList = &View->NbTI2;
      }
      else if(!strcmp((yyvsp[0].c), "SY2")){
	ViewElementIdx = 21; ViewNumNodes = 14; ViewNumComp = 1;
	ViewValueList = View->SY2; ViewNumList = &View->NbSY2;
      }
      else if(!strcmp((yyvsp[0].c), "VY2")){
	ViewElementIdx = 22; ViewNumNodes = 14; ViewNumComp = 3;
	ViewValueList = View->VY2; ViewNumList = &View->NbVY2;
      }
      else if(!strcmp((yyvsp[0].c), "TY2")){
	ViewElementIdx = 23; ViewNumNodes = 14; ViewNumComp = 9;
	ViewValueList = View->TY2; ViewNumList = &View->NbTY2;
      }
      else{
	yymsg(GERROR, "Unknown element type '%s'", (yyvsp[0].c));	
	ViewElementIdx = -1; ViewNumNodes = 0; ViewNumComp = 0;
	ViewValueList = NULL; ViewNumList = NULL;
      }
      Free((yyvsp[0].c));
      ViewCoordIdx = 0;
    ;}
    break;

  case 41:
#line 483 "Gmsh.y"
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
#line 501 "Gmsh.y"
    {
      if(ViewValueList){  
	if((List_Nbr(ViewValueList) - ViewNumListTmp) % (ViewNumComp * ViewNumNodes)) 
	  ViewErrorFlags[ViewElementIdx]++;
	(*ViewNumList)++;
      }
    ;}
    break;

  case 43:
#line 512 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[0].c))+1; i++) List_Add(View->T2C, &(yyvsp[0].c)[i]); 
      Free((yyvsp[0].c));
    ;}
    break;

  case 44:
#line 517 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[0].c))+1; i++) List_Add(View->T2C, &(yyvsp[0].c)[i]); 
      Free((yyvsp[0].c));
    ;}
    break;

  case 45:
#line 525 "Gmsh.y"
    { 
      List_Add(View->T2D, &(yyvsp[-5].d)); List_Add(View->T2D, &(yyvsp[-3].d));
      List_Add(View->T2D, &(yyvsp[-1].d)); 
      double d = List_Nbr(View->T2C);
      List_Add(View->T2D, &d); 
    ;}
    break;

  case 46:
#line 532 "Gmsh.y"
    {
      View->NbT2++;
    ;}
    break;

  case 47:
#line 539 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[0].c))+1; i++) List_Add(View->T3C, &(yyvsp[0].c)[i]); 
      Free((yyvsp[0].c));
    ;}
    break;

  case 48:
#line 544 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[0].c))+1; i++) List_Add(View->T3C, &(yyvsp[0].c)[i]); 
      Free((yyvsp[0].c));
    ;}
    break;

  case 49:
#line 552 "Gmsh.y"
    { 
      List_Add(View->T3D, &(yyvsp[-7].d)); List_Add(View->T3D, &(yyvsp[-5].d));
      List_Add(View->T3D, &(yyvsp[-3].d)); List_Add(View->T3D, &(yyvsp[-1].d)); 
      double d = List_Nbr(View->T3C);
      List_Add(View->T3D, &d); 
    ;}
    break;

  case 50:
#line 559 "Gmsh.y"
    {
      View->NbT3++;
    ;}
    break;

  case 51:
#line 567 "Gmsh.y"
    {
      View->adaptive = new Adaptive_Post_View(View, (yyvsp[-5].l), (yyvsp[-2].l));
    ;}
    break;

  case 52:
#line 574 "Gmsh.y"
    {
      ViewValueList = View->Time;
    ;}
    break;

  case 53:
#line 578 "Gmsh.y"
    {
    ;}
    break;

  case 54:
#line 583 "Gmsh.y"
    {
      (*View->Grains) [(int)(yyvsp[-3].d)] = (yyvsp[-1].l);
    ;}
    break;

  case 55:
#line 591 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 56:
#line 592 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 57:
#line 593 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 58:
#line 594 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 59:
#line 595 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 60:
#line 599 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 61:
#line 600 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 62:
#line 608 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-3].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	if(!(yyvsp[-2].i)){
	  TheSymbol.val = List_Create(1, 1, sizeof(double));
	  List_Put(TheSymbol.val, 0, &(yyvsp[-1].d));
	  Tree_Add(Symbol_T, &TheSymbol);
	}
	else{
	  yymsg(GERROR, "Unknown variable '%s'", (yyvsp[-3].c));
	  Free((yyvsp[-3].c));
	}
      }
      else{
	double *pd = (double*)List_Pointer_Fast(pSymbol->val, 0); 
	switch((yyvsp[-2].i)){
	case 0 : *pd = (yyvsp[-1].d); break;
	case 1 : *pd += (yyvsp[-1].d); break;
	case 2 : *pd -= (yyvsp[-1].d); break;
	case 3 : *pd *= (yyvsp[-1].d); break;
	case 4 : 
	  if((yyvsp[-1].d)) *pd /= (yyvsp[-1].d); 
	  else yymsg(GERROR, "Division by zero in '%s /= %g'", (yyvsp[-3].c), (yyvsp[-1].d));
	  break;
	}
	Free((yyvsp[-3].c));
      }
    ;}
    break;

  case 63:
#line 639 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-6].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	if(!(yyvsp[-2].i)){
	  TheSymbol.val = List_Create(5, 5, sizeof(double));
	  List_Put(TheSymbol.val, (int)(yyvsp[-4].d), &(yyvsp[-1].d));
	  Tree_Add(Symbol_T, &TheSymbol);
	}
	else{
	  yymsg(GERROR, "Unknown variable '%s'", (yyvsp[-6].c));
	  Free((yyvsp[-6].c));
	}
      }
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)(yyvsp[-4].d)))){
	  switch((yyvsp[-2].i)){
	  case 0 : *pd = (yyvsp[-1].d); break;
	  case 1 : *pd += (yyvsp[-1].d); break;
	  case 2 : *pd -= (yyvsp[-1].d); break;
	  case 3 : *pd *= (yyvsp[-1].d); break;
	  case 4 : 
	    if((yyvsp[-1].d)) *pd /= (yyvsp[-1].d); 
	    else yymsg(GERROR, "Division by zero in '%s[%d] /= %g'", (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].d));
	    break;
	  }
	}
	else{
	  if(!(yyvsp[-2].i))
	    List_Put(pSymbol->val, (int)(yyvsp[-4].d), &(yyvsp[-1].d));
	  else
	    yymsg(GERROR, "Uninitialized variable '%s[%d]'", (yyvsp[-6].c), (int)(yyvsp[-4].d));
	}
	Free((yyvsp[-6].c));
      }
    ;}
    break;

  case 64:
#line 678 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-5].l)) != List_Nbr((yyvsp[-1].l))){
	yymsg(GERROR, "Incompatible array dimensions in affectation");
	Free((yyvsp[-8].c));
      }
      else{
	Symbol TheSymbol;
	TheSymbol.Name = (yyvsp[-8].c);
	Symbol *pSymbol;
	if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	  if(!(yyvsp[-2].i)){
	    TheSymbol.val = List_Create(5, 5, sizeof(double));
	    for(int i = 0; i < List_Nbr((yyvsp[-5].l)); i++){
	      List_Put(TheSymbol.val, (int)(*(double*)List_Pointer((yyvsp[-5].l), i)),
		       (double*)List_Pointer((yyvsp[-1].l), i));
	    }
	    Tree_Add(Symbol_T, &TheSymbol);
	  }
	  else{
	    yymsg(GERROR, "Unknown variable '%s'", (yyvsp[-8].c));
	    Free((yyvsp[-8].c));
	  }
	}
	else{
	  for(int i = 0; i < List_Nbr((yyvsp[-5].l)); i++){
	    int j = (int)(*(double*)List_Pointer((yyvsp[-5].l), i));
	    double d = *(double*)List_Pointer((yyvsp[-1].l), i);
	    double *pd;
	    if((pd = (double*)List_Pointer_Test(pSymbol->val, j))){
	      switch((yyvsp[-2].i)){
	      case 0 : *pd = d; break;
	      case 1 : *pd += d; break;
	      case 2 : *pd -= d; break;
	      case 3 : *pd *= d; break;
	      case 4 : 
		if((yyvsp[-1].l)) *pd /= d; 
		else yymsg(GERROR, "Division by zero in '%s[%d] /= %g'", (yyvsp[-8].c), j, d);
		break;
	      }
	    }
	    else{
	      if(!(yyvsp[-2].i))
		List_Put(pSymbol->val, j, &d);
	      else
		yymsg(GERROR, "Uninitialized variable '%s[%d]'", (yyvsp[-8].c), j);	  
	    }
	  }
	  Free((yyvsp[-8].c));
	}
      }
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 65:
#line 732 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-5].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(5, 5, sizeof(double));
	List_Copy((yyvsp[-1].l), TheSymbol.val);
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	List_Reset(pSymbol->val);
	List_Copy((yyvsp[-1].l), pSymbol->val);
	Free((yyvsp[-5].c));
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 66:
#line 749 "Gmsh.y"
    {
      // appends to the list
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-5].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(5, 5, sizeof(double));
	List_Copy((yyvsp[-1].l), TheSymbol.val);
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
	  List_Add(pSymbol->val, List_Pointer((yyvsp[-1].l), i));
	Free((yyvsp[-5].c));
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 67:
#line 767 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-2].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol)))
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[-2].c)); 
      else
	*(double*)List_Pointer_Fast(pSymbol->val, 0) += (yyvsp[-1].i);
      Free((yyvsp[-2].c));
    ;}
    break;

  case 68:
#line 778 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-5].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol)))
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[-5].c)); 
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)(yyvsp[-3].d))))
	  *pd += (yyvsp[-1].i);
	else
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", (yyvsp[-5].c), (int)(yyvsp[-3].d));
      }
      Free((yyvsp[-5].c));
    ;}
    break;

  case 69:
#line 797 "Gmsh.y"
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory((yyvsp[-5].c))))
	yymsg(GERROR, "Unknown string option class '%s'", (yyvsp[-5].c));
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption((yyvsp[-3].c), pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s.%s'", (yyvsp[-5].c), (yyvsp[-3].c));
	else
	  pStrOpt(0, GMSH_SET|GMSH_GUI, (yyvsp[-1].c));
      }
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); //FIXME: somtimes leak $5
    ;}
    break;

  case 70:
#line 811 "Gmsh.y"
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory((yyvsp[-8].c))))
	yymsg(GERROR, "Unknown string option class '%s'", (yyvsp[-8].c));
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption((yyvsp[-3].c), pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s[%d].%s'", (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c));
	else
	  pStrOpt((int)(yyvsp[-6].d), GMSH_SET|GMSH_GUI, (yyvsp[-1].c));
      }
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); //FIXME: somtimes leak $8
    ;}
    break;

  case 71:
#line 828 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[-5].c))))
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[-5].c));
      else{
	if(!(pNumOpt = (double (*) (int, int, double))Get_NumberOption((yyvsp[-3].c), pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", (yyvsp[-5].c), (yyvsp[-3].c));
	else{
	  double d = 0;
	  switch((yyvsp[-2].i)){
	  case 0 : d = (yyvsp[-1].d); break;
	  case 1 : d = pNumOpt(0, GMSH_GET, 0) + (yyvsp[-1].d); break;
	  case 2 : d = pNumOpt(0, GMSH_GET, 0) - (yyvsp[-1].d); break;
	  case 3 : d = pNumOpt(0, GMSH_GET, 0) * (yyvsp[-1].d); break;
	  case 4 : 
	    if((yyvsp[-1].d)) d = pNumOpt(0, GMSH_GET, 0) / (yyvsp[-1].d); 
	    else yymsg(GERROR, "Division by zero in '%s.%s /= %g'", (yyvsp[-5].c), (yyvsp[-3].c), (yyvsp[-1].d));
	    break;
	  }
	  pNumOpt(0, GMSH_SET|GMSH_GUI, d);
	}
      }
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c));
    ;}
    break;

  case 72:
#line 854 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[-8].c))))
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[-8].c));
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption((yyvsp[-3].c), pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c));
	else{
	  double d = 0;
	  switch((yyvsp[-2].i)){
	  case 0 : d = (yyvsp[-1].d); break;
	  case 1 : d = pNumOpt((int)(yyvsp[-6].d), GMSH_GET, 0) + (yyvsp[-1].d); break;
	  case 2 : d = pNumOpt((int)(yyvsp[-6].d), GMSH_GET, 0) - (yyvsp[-1].d); break;
	  case 3 : d = pNumOpt((int)(yyvsp[-6].d), GMSH_GET, 0) * (yyvsp[-1].d); break;
	  case 4 : 
	    if((yyvsp[-1].d)) d = pNumOpt((int)(yyvsp[-6].d), GMSH_GET, 0) / (yyvsp[-1].d);
	    else yymsg(GERROR, "Division by zero in '%s[%d].%s /= %g'", 
		       (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), (yyvsp[-1].d));
	    break;
	  }
	  pNumOpt((int)(yyvsp[-6].d), GMSH_SET|GMSH_GUI, d);
	}
      }
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c));
    ;}
    break;

  case 73:
#line 881 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[-4].c))))
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[-4].c));
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption((yyvsp[-2].c), pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", (yyvsp[-4].c), (yyvsp[-2].c));
	else
	  pNumOpt(0, GMSH_SET|GMSH_GUI, pNumOpt(0, GMSH_GET, 0)+(yyvsp[-1].i));
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    ;}
    break;

  case 74:
#line 895 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[-7].c))))
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[-7].c));
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption((yyvsp[-2].c), pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c));
	else
	  pNumOpt((int)(yyvsp[-5].d), GMSH_SET|GMSH_GUI, pNumOpt((int)(yyvsp[-5].d), GMSH_GET, 0)+(yyvsp[-1].i));
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    ;}
    break;

  case 75:
#line 912 "Gmsh.y"
    {
      unsigned int (*pColOpt)(int num, int action, unsigned int value);
      StringXColor *pColCat;
      if(!(pColCat = Get_ColorOptionCategory((yyvsp[-7].c))))
	yymsg(GERROR, "Unknown color option class '%s'", (yyvsp[-7].c));
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption((yyvsp[-3].c), pColCat)))
	  yymsg(GERROR, "Unknown color option '%s.Color.%s'", (yyvsp[-7].c), (yyvsp[-3].c));
	else
	  pColOpt(0, GMSH_SET|GMSH_GUI, (yyvsp[-1].u));
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    ;}
    break;

  case 76:
#line 926 "Gmsh.y"
    {
      unsigned int (*pColOpt)(int num, int action, unsigned int value);
      StringXColor *pColCat;
      if(!(pColCat = Get_ColorOptionCategory((yyvsp[-10].c))))
	yymsg(GERROR, "Unknown color option class '%s'", (yyvsp[-10].c));
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption((yyvsp[-3].c), pColCat)))
	  yymsg(GERROR, "Unknown color option '%s[%d].Color.%s'", (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c));
	else
	  pColOpt((int)(yyvsp[-8].d), GMSH_SET|GMSH_GUI, (yyvsp[-1].u));
      }
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    ;}
    break;

  case 77:
#line 943 "Gmsh.y"
    {
      GmshColorTable *ct = Get_ColorTable(0);
      if(!ct)
	yymsg(GERROR, "View[%d] does not exist", 0);
      else{
	ct->size = List_Nbr((yyvsp[-1].l));
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(GERROR, "Too many (%d>%d) colors in View[%d].ColorTable", 
		ct->size, COLORTABLE_NBMAX_COLOR, 0);
	else
	  for(int i = 0; i < ct->size; i++) List_Read((yyvsp[-1].l), i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free((yyvsp[-5].c));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 78:
#line 963 "Gmsh.y"
    {
      GmshColorTable *ct = Get_ColorTable((int)(yyvsp[-6].d));
      if(!ct)
	yymsg(GERROR, "View[%d] does not exist", (int)(yyvsp[-6].d));
      else{
	ct->size = List_Nbr((yyvsp[-1].l));
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(GERROR, "Too many (%d>%d) colors in View[%d].ColorTable", 
		   ct->size, COLORTABLE_NBMAX_COLOR, (int)(yyvsp[-6].d));
	else
	  for(int i = 0; i < ct->size; i++) List_Read((yyvsp[-1].l), i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 79:
#line 986 "Gmsh.y"
    {
      try {
	GMSH_PluginManager::instance()->setPluginOption((yyvsp[-6].c), (yyvsp[-3].c), (yyvsp[-1].d)); 
      }
      catch (...) {
	yymsg(GERROR, "Unknown option '%s' or plugin '%s'", (yyvsp[-3].c), (yyvsp[-6].c));
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-3].c));
    ;}
    break;

  case 80:
#line 996 "Gmsh.y"
    {
      try {
	GMSH_PluginManager::instance()->setPluginOption((yyvsp[-6].c), (yyvsp[-3].c), (yyvsp[-1].c)); 
      }
      catch (...) {
	yymsg(GERROR, "Unknown option '%s' or plugin '%s'", (yyvsp[-3].c), (yyvsp[-6].c));
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-3].c)); // FIXME: sometimes leak $8
    ;}
    break;

  case 81:
#line 1015 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindPoint(num, THEM)){
	yymsg(GERROR, "Point %d already exists", num);
      }
      else{
	Vertex *v = Create_Vertex(num, CTX.geom.scaling_factor * (yyvsp[-1].v)[0],
				  CTX.geom.scaling_factor * (yyvsp[-1].v)[1],
				  CTX.geom.scaling_factor * (yyvsp[-1].v)[2],
				  CTX.geom.scaling_factor * (yyvsp[-1].v)[3], 1.0);
	Tree_Add(THEM->Points, &v);
      }
      (yyval.s).Type = MSH_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 82:
#line 1031 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT, THEM)){
	yymsg(GERROR, "Physical point %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 83:
#line 1047 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-9].l)); i++){
	double p;
      	List_Read((yyvsp[-9].l), i, &p);
        Vertex *v = FindPoint((int)p, THEM);
        if(!v)
	  yymsg(WARNING, "Unknown point %d", (int)p);
	else{
	  Attractor *a = Create_Attractor(List_Nbr(THEM->Metric->Attractors)+1,
					  (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d), v, NULL, NULL);
	  List_Add(THEM->Metric->Attractors, &a);
        }
      }
      List_Delete((yyvsp[-9].l));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 84:
#line 1066 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
	double d;
	List_Read((yyvsp[-3].l), i, &d);
	Vertex *v = FindPoint((int)d, THEM);
	if(!v)
	  yymsg(WARNING, "Unknown point %d", (int)d);
	else
	  v->lc = (yyvsp[-1].d);
      }
      List_Delete((yyvsp[-3].l));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 85:
#line 1085 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 86:
#line 1103 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	Curve *c = Create_Curve(num, MSH_SEGM_SPLN, 3, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_SPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 87:
#line 1121 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    ;}
    break;

  case 88:
#line 1139 "Gmsh.y"
    {
      int num = (int)(yyvsp[-6].d);
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-3].l));
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
	c->Circle.n[0] = (yyvsp[-1].v)[0];
	c->Circle.n[1] = (yyvsp[-1].v)[1];
	c->Circle.n[2] = (yyvsp[-1].v)[2];
	End_Curve(c);
	Tree_Add(THEM->Curves, &c);
	Curve *rc = CreateReversedCurve(THEM, c);
	rc->Circle.n[0] = (yyvsp[-1].v)[0];
	rc->Circle.n[1] = (yyvsp[-1].v)[1];
	rc->Circle.n[2] = (yyvsp[-1].v)[2];
	End_Curve(rc);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-3].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    ;}
    break;

  case 89:
#line 1165 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    ;}
    break;

  case 90:
#line 1183 "Gmsh.y"
    {
      int num = (int)(yyvsp[-6].d);
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-3].l));
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
	c->Circle.n[0] = (yyvsp[-1].v)[0];
	c->Circle.n[1] = (yyvsp[-1].v)[1];
	c->Circle.n[2] = (yyvsp[-1].v)[2];
	End_Curve(c);
	Tree_Add(THEM->Curves, &c);
	Curve *rc = CreateReversedCurve(THEM, c);
	rc->Circle.n[0] = (yyvsp[-1].v)[0];
	rc->Circle.n[1] = (yyvsp[-1].v)[1];
	rc->Circle.n[2] = (yyvsp[-1].v)[2];
	End_Curve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-3].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    ;}
    break;

  case 91:
#line 1210 "Gmsh.y"
    {
      int num = (int)(yyvsp[-14].d);
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	Curve *c = Create_Curve(num, MSH_SEGM_PARAMETRIC, 2, NULL, NULL,
				-1, -1, (yyvsp[-10].d), (yyvsp[-8].d));
	strcpy(c->functu, (yyvsp[-6].c));
	strcpy(c->functv, (yyvsp[-4].c));
	strcpy(c->functw, (yyvsp[-2].c));
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
      (yyval.s).Type = MSH_SEGM_PARAMETRIC;
      (yyval.s).Num = num;
    ;}
    break;

  case 92:
#line 1229 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(List_Nbr((yyvsp[-1].l)) < 4){
	yymsg(GERROR, "Too few control points for BSpline %d (%d < 4)", num,
	      List_Nbr((yyvsp[-1].l)));
      }
      else{
	if(FindCurve(num, THEM)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	  Curve *c = Create_Curve(num, MSH_SEGM_BSPLN, 2, temp, NULL,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(THEM, c);
	  List_Delete(temp);
	}
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 93:
#line 1253 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(List_Nbr((yyvsp[-1].l)) < 4){
	yymsg(GERROR, "Too few control points for Bezier curve %d (%d < 4)", num,
	      List_Nbr((yyvsp[-1].l)));
      }
      else{
	if(FindCurve(num, THEM)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	  Curve *c = Create_Curve(num, MSH_SEGM_BEZIER, 2, temp, NULL,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(THEM, c);
	  List_Delete(temp);
	}
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_BEZIER;
      (yyval.s).Num = num;
    ;}
    break;

  case 94:
#line 1277 "Gmsh.y"
    {
      int num = (int)(yyvsp[-8].d);
      if(List_Nbr((yyvsp[-5].l)) + (int)(yyvsp[-1].d) + 1 != List_Nbr((yyvsp[-3].l))){
	yymsg(GERROR, "Wrong definition of Nurbs Curve %d: "
	      "got %d knots, need N + D + 1 = %d + %d + 1 = %d",
	      (int)(yyvsp[-8].d), List_Nbr((yyvsp[-3].l)), List_Nbr((yyvsp[-5].l)), (int)(yyvsp[-1].d), List_Nbr((yyvsp[-5].l)) + (int)(yyvsp[-1].d) + 1);
      }
      else{
	if(FindCurve(num, THEM)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[-5].l));
	  Curve *c = Create_Curve(num, MSH_SEGM_NURBS, (int)(yyvsp[-1].d), temp, (yyvsp[-3].l),
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(THEM, c);
	  List_Delete(temp);
	}
      }
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-3].l));
      (yyval.s).Type = MSH_SEGM_NURBS;
      (yyval.s).Num = num;
    ;}
    break;

  case 95:
#line 1303 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindEdgeLoop(num, THEM)){
	yymsg(GERROR, "Line loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	sortEdgesInLoop(num, temp);
	EdgeLoop *l = Create_EdgeLoop(num, temp);
	Tree_Add(THEM->EdgeLoops, &l);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 96:
#line 1320 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-9].l)); i++){
	double p;
      	List_Read((yyvsp[-9].l), i, &p);
	Curve *c = FindCurve((int)p, THEM);
        if(!c)
	  yymsg(WARNING, "Unknown curve %d", (int)p);
	else{
	  Attractor *a = Create_Attractor(List_Nbr(THEM->Metric->Attractors)+1,
					  (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d), NULL, c, NULL);
	  List_Add(THEM->Metric->Attractors, &a);
        }
      }
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 97:
#line 1338 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE, THEM)){
	yymsg(GERROR, "Physical line %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 98:
#line 1357 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindSurface(num, THEM)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_PLAN);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	setSurfaceGeneratrices(s, temp);
	List_Delete(temp);
	s->Support = s;
	End_Surface(s);
	Tree_Add(THEM->Surfaces, &s);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 99:
#line 1376 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d), type = 0;
      if(FindSurface(num, THEM)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	double d;
	List_Read((yyvsp[-1].l), 0, &d);
	EdgeLoop *el = FindEdgeLoop((int)fabs(d), THEM);
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
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	  setSurfaceGeneratrices(s, temp);
	  List_Delete(temp);
	  s->Support = s;
	  End_Surface(s);
	  Tree_Add(THEM->Surfaces, &s);
	}
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = type;
      (yyval.s).Num = num;
    ;}
    break;

  case 100:
#line 1415 "Gmsh.y"
    {
      int num = (int)(yyvsp[-8].d);
      Surface *support = FindSurface((int)(yyvsp[-4].d), THEM);
      if(!support){
	yymsg(GERROR, "Unknown support surface %d", (int)(yyvsp[-4].d));
      }
      else{
	if(FindSurface(num, THEM)){
	  yymsg(GERROR, "Surface %d already exists", num);
	}
	else{
	  Surface *s = Create_Surface(num, MSH_SURF_TRIMMED);
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[-2].l));
	  setSurfaceGeneratrices(s, temp);
	  List_Delete(temp);
	  s->Support = support;
	  End_Surface(s);
	  Tree_Add(THEM->Surfaces, &s);
	}
      }
      List_Delete((yyvsp[-2].l));
      (yyval.s).Type = MSH_SURF_TRIMMED;
      (yyval.s).Num = num;
    ;}
    break;

  case 101:
#line 1442 "Gmsh.y"
    {
      int num = (int)(yyvsp[-16].d);
      if(FindSurface(num, THEM)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	CreateNurbsSurface(num, (int)(yyvsp[-4].d), (int)(yyvsp[-2].d), (yyvsp[-13].l), (yyvsp[-10].l), (yyvsp[-8].l));
      }
      for(int i = 0; i < List_Nbr((yyvsp[-13].l)); i++)
	List_Delete((List_T*)List_Pointer((yyvsp[-13].l), i));
      List_Delete((yyvsp[-13].l));
      List_Delete((yyvsp[-10].l));
      List_Delete((yyvsp[-8].l));
      (yyval.s).Type = MSH_SURF_NURBS;
      (yyval.s).Num = num;
    ;}
    break;

  case 102:
#line 1461 "Gmsh.y"
    {
      int num = (int)(yyvsp[-16].d);
      if(FindSurface(num, THEM)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	CreateNurbsSurfaceSupport(num, (int)(yyvsp[-4].d), (int)(yyvsp[-2].d), (yyvsp[-13].l), (yyvsp[-10].l), (yyvsp[-8].l));
      }
      for(int i = 0; i < List_Nbr((yyvsp[-13].l)); i++)
	List_Delete((List_T*)List_Pointer((yyvsp[-13].l), i));
      List_Delete((yyvsp[-13].l));
      List_Delete((yyvsp[-10].l));
      List_Delete((yyvsp[-8].l));
      (yyval.s).Type = MSH_SURF_NURBS;
      (yyval.s).Num = num;
    ;}
    break;

  case 103:
#line 1478 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindSurfaceLoop(num, THEM)){
	yymsg(GERROR, "Surface loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	SurfaceLoop *l = Create_SurfaceLoop(num, temp);
	Tree_Add(THEM->SurfaceLoops, &l);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 104:
#line 1494 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE, THEM)){
	yymsg(GERROR, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    ;}
    break;

  case 105:
#line 1514 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindVolume(num, THEM)){
	yymsg(GERROR, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(THEM->Volumes, &v);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 106:
#line 1531 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindVolume(num, THEM)){
	yymsg(GERROR, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(THEM->Volumes, &v);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 107:
#line 1548 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME, THEM)){
	yymsg(GERROR, "Physical volume %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 108:
#line 1569 "Gmsh.y"
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 109:
#line 1574 "Gmsh.y"
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 110:
#line 1579 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 111:
#line 1584 "Gmsh.y"
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 112:
#line 1591 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); ;}
    break;

  case 113:
#line 1592 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); ;}
    break;

  case 114:
#line 1593 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); ;}
    break;

  case 115:
#line 1598 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 116:
#line 1602 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    ;}
    break;

  case 117:
#line 1606 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	double d;
	List_Read((yyvsp[-2].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Vertex *v = FindPoint(TheShape.Num, THEM);
	if(!v)
	  yymsg(WARNING, "Unknown point %d", TheShape.Num);
	else{
	  TheShape.Type = MSH_POINT;
	  List_Add((yyval.l), &TheShape);
	}
      }
    ;}
    break;

  case 118:
#line 1622 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	double d;
	List_Read((yyvsp[-2].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Curve *c = FindCurve(TheShape.Num, THEM);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	else{
	  TheShape.Type = c->Typ;
	  List_Add((yyval.l), &TheShape);
	}
      }
    ;}
    break;

  case 119:
#line 1638 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	double d;
	List_Read((yyvsp[-2].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Surface *s = FindSurface(TheShape.Num, THEM);
	if(!s)
	  yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	else{
	  TheShape.Type = s->Typ;
	  List_Add((yyval.l), &TheShape);
	}
      }
    ;}
    break;

  case 120:
#line 1654 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	double d;
	List_Read((yyvsp[-2].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Volume *v = FindVolume(TheShape.Num, THEM);
	if(!v)
	  yymsg(WARNING, "Unknown volume %d", TheShape.Num);
	else{
	  TheShape.Type = v->Typ;
	  List_Add((yyval.l), &TheShape);
	}
      }
    ;}
    break;

  case 121:
#line 1675 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	int j;
	CopyShape(TheShape.Type, TheShape.Num, &j);
	TheShape.Num = j;
	List_Add((yyval.l), &TheShape);
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 122:
#line 1689 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "View")) AliasView((int)(yyvsp[-2].d), 0);
      Free((yyvsp[-4].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 123:
#line 1695 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "View")) AliasView((int)(yyvsp[-2].d), 0);
      Free((yyvsp[-4].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 124:
#line 1701 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "View")) AliasView((int)(yyvsp[-2].d), 1);
      Free((yyvsp[-4].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 125:
#line 1713 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 126:
#line 1722 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "View")){
	RemoveViewByIndex((int)(yyvsp[-2].d));
      }
      else{
	yymsg(GERROR, "Unknown command 'Delete %s'", (yyvsp[-4].c));
      }
      Free((yyvsp[-4].c));
    ;}
    break;

  case 127:
#line 1732 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-1].c), "Meshes") || !strcmp((yyvsp[-1].c), "All")){
	Init_Mesh();
      }
      else if(!strcmp((yyvsp[-1].c), "Physicals")){
	List_Action(THEM->PhysicalGroups, Free_PhysicalGroup);
	List_Reset(THEM->PhysicalGroups);
      }
      else{
	yymsg(GERROR, "Unknown command 'Delete %s'", (yyvsp[-1].c));
      }
      Free((yyvsp[-1].c));
    ;}
    break;

  case 128:
#line 1746 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-2].c), "Empty") && !strcmp((yyvsp[-1].c), "Views")){
	for(int i = List_Nbr(CTX.post.list) - 1; i >= 0; i--){
	  Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, i);
	  if(v->empty())
	    RemoveViewByIndex(i);
	}
      }
      else{
	yymsg(GERROR, "Unknown command 'Delete %s %s'", (yyvsp[-2].c), (yyvsp[-1].c));
      }
      Free((yyvsp[-2].c)); Free((yyvsp[-1].c));
    ;}
    break;

  case 129:
#line 1765 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u));
      }
      List_Delete((yyvsp[-1].l));      
    ;}
    break;

  case 130:
#line 1779 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1);
      Free((yyvsp[-1].c));
    ;}
    break;

  case 131:
#line 1785 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0);
      Free((yyvsp[-1].c));
    ;}
    break;

  case 132:
#line 1791 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 133:
#line 1800 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 134:
#line 1814 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-2].c), "Include")){
	char tmpstring[1024];
	FixRelativePath((yyvsp[-1].c), tmpstring);
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
      else if(!strcmp((yyvsp[-2].c), "Print")){
#if defined(HAVE_FLTK)
	char tmpstring[1024];
	FixRelativePath((yyvsp[-1].c), tmpstring);
	CreateOutputFile(tmpstring, CTX.print.format);
#endif
      }
      else if(!strcmp((yyvsp[-2].c), "Save")){
#if defined(HAVE_FLTK)
	char tmpstring[1024];
	FixRelativePath((yyvsp[-1].c), tmpstring);
	CreateOutputFile(tmpstring, CTX.mesh.format);
#endif
      }
      else if(!strcmp((yyvsp[-2].c), "Merge") || !strcmp((yyvsp[-2].c), "MergeWithBoundingBox")){
	// MergeWithBoundingBox is deprecated
	char tmpstring[1024];
	FixRelativePath((yyvsp[-1].c), tmpstring);
	MergeProblem(tmpstring, 1);
      }
      else if(!strcmp((yyvsp[-2].c), "System")){
	SystemCall((yyvsp[-1].c));
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[-2].c));
      }
      Free((yyvsp[-2].c)); Free((yyvsp[-1].c));
    ;}
    break;

  case 135:
#line 1859 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-6].c), "Save") && !strcmp((yyvsp[-5].c), "View")){
	Post_View **vv = (Post_View **)List_Pointer_Test(CTX.post.list, (int)(yyvsp[-3].d));
	if(vv){
	  char tmpstring[1024];
	  FixRelativePath((yyvsp[-1].c), tmpstring);
	  WriteView(*vv, tmpstring, CTX.post.file_format, 0);
	}
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[-6].c));
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-5].c)); Free((yyvsp[-1].c));
    ;}
    break;

  case 136:
#line 1874 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-6].c), "Background") && !strcmp((yyvsp[-5].c), "Mesh")  && !strcmp((yyvsp[-4].c), "View")){
	Post_View **vv = (Post_View **)List_Pointer_Test(CTX.post.list, (int)(yyvsp[-2].d));
	if(vv) BGMWithView(*vv);
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[-6].c));
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-5].c)); Free((yyvsp[-4].c));
    ;}
    break;

  case 137:
#line 1885 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-2].c), "Sleep")){
	SleepInSeconds((yyvsp[-1].d));
      }
      else if(!strcmp((yyvsp[-2].c), "Remesh")){
	ReMesh();
      }
      else if(!strcmp((yyvsp[-2].c), "Mesh")){
	yymsg(GERROR, "Mesh directives are not (yet) allowed in scripts");
      }
      else if(!strcmp((yyvsp[-2].c), "Status")){
	THEM->status = (int)(yyvsp[-1].d);
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[-2].c));
      }
      Free((yyvsp[-2].c));
    ;}
    break;

  case 138:
#line 1904 "Gmsh.y"
    {
       try {
	 GMSH_PluginManager::instance()->action((yyvsp[-4].c), (yyvsp[-1].c), 0);
       }
       catch(...) {
	 yymsg(GERROR, "Unknown action '%s' or plugin '%s'", (yyvsp[-1].c), (yyvsp[-4].c));
       }
       Free((yyvsp[-4].c)); Free((yyvsp[-1].c));
     ;}
    break;

  case 139:
#line 1914 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-1].c), "ElementsFromAllViews"))
	CombineViews(0, 1, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[-1].c), "ElementsFromVisibleViews"))
	CombineViews(0, 0, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[-1].c), "ElementsByViewName"))
	CombineViews(0, 2, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[-1].c), "TimeStepsFromAllViews"))
	CombineViews(1, 1, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[-1].c), "TimeStepsFromVisibleViews"))
	CombineViews(1, 0, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[-1].c), "TimeStepsByViewName"))
	CombineViews(1, 2, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[-1].c), "Views"))
	CombineViews(0, 1, CTX.post.combine_remove_orig);
      else if(!strcmp((yyvsp[-1].c), "TimeSteps"))
	CombineViews(1, 2, CTX.post.combine_remove_orig);
      else
	yymsg(GERROR, "Unknown 'Combine' command");
      Free((yyvsp[-1].c));
    ;}
    break;

  case 140:
#line 1936 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 141:
#line 1940 "Gmsh.y"
    {
      CTX.forced_bbox = 0;
      SetBoundingBox();
    ;}
    break;

  case 142:
#line 1945 "Gmsh.y"
    {
      CTX.forced_bbox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    ;}
    break;

  case 143:
#line 1950 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      Draw();
#endif
    ;}
    break;

  case 144:
#line 1962 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-1].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if((yyvsp[-3].d) > (yyvsp[-1].d)) skip_until("For", "EndFor");
    ;}
    break;

  case 145:
#line 1977 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-5].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[-1].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if(((yyvsp[-1].d) > 0. && (yyvsp[-5].d) > (yyvsp[-3].d)) || ((yyvsp[-1].d) < 0. && (yyvsp[-5].d) < (yyvsp[-3].d)))
	skip_until("For", "EndFor");
    ;}
    break;

  case 146:
#line 1993 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-1].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[-6].c);
      Symbol TheSymbol;      
      TheSymbol.Name = (yyvsp[-6].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(1, 1, sizeof(double));
	List_Put(TheSymbol.val, 0, &(yyvsp[-3].d));
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	List_Write(pSymbol->val, 0, &(yyvsp[-3].d));
      }
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if((yyvsp[-3].d) > (yyvsp[-1].d)) skip_until("For", "EndFor");
    ;}
    break;

  case 147:
#line 2019 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-5].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[-1].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[-8].c);
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-8].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(1, 1, sizeof(double));
	List_Put(TheSymbol.val, 0, &(yyvsp[-5].d));
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	List_Write(pSymbol->val, 0, &(yyvsp[-5].d));
      }
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if(((yyvsp[-1].d) > 0. && (yyvsp[-5].d) > (yyvsp[-3].d)) || ((yyvsp[-1].d) < 0. && (yyvsp[-5].d) < (yyvsp[-3].d)))
	skip_until("For", "EndFor");
    ;}
    break;

  case 148:
#line 2046 "Gmsh.y"
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

  case 149:
#line 2078 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction((yyvsp[0].c), yyin, yyname, yylineno))
	yymsg(GERROR, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 150:
#line 2085 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin, yyname, yylineno))
	yymsg(GERROR, "Error while exiting function");
    ;}
    break;

  case 151:
#line 2090 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction((yyvsp[-1].c), &yyin, yyname, yylineno))
	yymsg(GERROR, "Unknown function %s", (yyvsp[-1].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 152:
#line 2096 "Gmsh.y"
    {
      if(!(yyvsp[-1].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 153:
#line 2100 "Gmsh.y"
    {
    ;}
    break;

  case 154:
#line 2109 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l), 
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 155:
#line 2117 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l), 
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 156:
#line 2125 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l), 
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 157:
#line 2133 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 158:
#line 2138 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l), 
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 159:
#line 2146 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 160:
#line 2151 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l), 
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 161:
#line 2159 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 162:
#line 2164 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l), 
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 163:
#line 2174 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d), 
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 164:
#line 2181 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d), 
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 165:
#line 2188 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d), 
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 166:
#line 2195 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d), 
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 167:
#line 2202 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d), 
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 168:
#line 2209 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d), 
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 169:
#line 2216 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d), 
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 170:
#line 2223 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d), 
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 171:
#line 2230 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d), 
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 172:
#line 2237 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 173:
#line 2242 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d), 
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 174:
#line 2249 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 175:
#line 2254 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d), 
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 176:
#line 2261 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 177:
#line 2266 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d), 
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 178:
#line 2273 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 179:
#line 2278 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d), 
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 180:
#line 2285 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 181:
#line 2290 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d), 
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 182:
#line 2297 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 183:
#line 2302 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d), 
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 184:
#line 2309 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 185:
#line 2314 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d), 
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 186:
#line 2321 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 187:
#line 2326 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d), 
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 188:
#line 2333 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 189:
#line 2338 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d), 
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 190:
#line 2349 "Gmsh.y"
    {
    ;}
    break;

  case 191:
#line 2352 "Gmsh.y"
    {
    ;}
    break;

  case 192:
#line 2358 "Gmsh.y"
    {
      double d;
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[-6].l));
      if(List_Nbr((yyvsp[-6].l)) == List_Nbr((yyvsp[-4].l)) && List_Nbr((yyvsp[-6].l)) == List_Nbr((yyvsp[-2].l))){
	extr.mesh.NbElmLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.ZonLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.hLayer = (double*)Malloc(extr.mesh.NbLayer*sizeof(double));
	for(int i = 0; i < List_Nbr((yyvsp[-6].l)); i++){
	  List_Read((yyvsp[-6].l), i, &d);
	  extr.mesh.NbElmLayer[i] = (d>0)?(int)d:1;
	  List_Read((yyvsp[-4].l), i, &d);
	  extr.mesh.ZonLayer[i] = (int)d;
	  List_Read((yyvsp[-2].l), i, &d);
	  extr.mesh.hLayer[i] = d;
	}
      }
      else{
	yymsg(GERROR, "Wrong layer definition {%d, %d, %d}", 
	      List_Nbr((yyvsp[-6].l)), List_Nbr((yyvsp[-4].l)), List_Nbr((yyvsp[-2].l)));
      }
      List_Delete((yyvsp[-6].l));
      List_Delete((yyvsp[-4].l));
      List_Delete((yyvsp[-2].l));
    ;}
    break;

  case 193:
#line 2384 "Gmsh.y"
    {
      double d;
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[-4].l));
      if(List_Nbr((yyvsp[-4].l)) == List_Nbr((yyvsp[-2].l))){
	extr.mesh.NbElmLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.ZonLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.hLayer = (double*)Malloc(extr.mesh.NbLayer*sizeof(double));
	for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	  List_Read((yyvsp[-4].l), i, &d);
	  extr.mesh.NbElmLayer[i] = (d>0)?(int)d:1;
	  extr.mesh.ZonLayer[i] = 0;
	  List_Read((yyvsp[-2].l), i, &d);
	  extr.mesh.hLayer[i] = d;
	}
      }
      else{
	yymsg(GERROR, "Wrong layer definition {%d, %d}", 
	      List_Nbr((yyvsp[-4].l)), List_Nbr((yyvsp[-2].l)));
      }
      List_Delete((yyvsp[-4].l));
      List_Delete((yyvsp[-2].l));
    ;}
    break;

  case 194:
#line 2408 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 195:
#line 2417 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
	double d;
	List_Read((yyvsp[-3].l), i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j, THEM);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = ((yyvsp[-1].d)>2)?(int)(yyvsp[-1].d):2;
	  c->ipar[1] = sign(d);
	  c->dpar[0] = 1.0;
	}
      }
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 196:
#line 2435 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-6].l)); i++){
	double d;
	List_Read((yyvsp[-6].l), i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j, THEM);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = ((yyvsp[-4].d)>2)?(int)(yyvsp[-4].d):2;
	  c->ipar[1] = sign(d); /* Progresion : code 1 ou -1 */
	  c->dpar[0] = fabs((yyvsp[-1].d));
	}
      }
      List_Delete((yyvsp[-6].l));
    ;}
    break;

  case 197:
#line 2453 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-6].l)); i++){
	double d;
	List_Read((yyvsp[-6].l), i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j, THEM);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = ((yyvsp[-4].d)>2)?(int)(yyvsp[-4].d):2;
	  c->ipar[1] = 2*sign(d); /* Bump : code 2 ou -2 */
	  c->dpar[0] = fabs((yyvsp[-1].d));
	}
      }
      List_Delete((yyvsp[-6].l));
    ;}
    break;

  case 198:
#line 2471 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[-4].d), THEM);
      if(!s)
	yymsg(WARNING, "Unknown surface %d", (int)(yyvsp[-4].d));
      else{
	s->Method = TRANSFINI;
	s->Recombine_Dir = 1;
	int k = List_Nbr((yyvsp[-1].l));
	if(k != 3 && k != 4){
	  yymsg(GERROR, "Wrong definition of Transfinite Surface %d: "
		"%d points instead of 3 or 4" , (int)(yyvsp[-4].d), k);
	}
	else{
	  List_Reset(s->TrsfPoints);
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read((yyvsp[-1].l), i, &d);
	    int j = (int)fabs(d);
	    Vertex *v = FindPoint(j, THEM);
	    if(!v)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(s->TrsfPoints, &v);
	  }
	}
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 199:
#line 2500 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[-5].d), THEM);
      if(!s)
	yymsg(WARNING, "Unknown surface %d", (int)(yyvsp[-5].d));
      else{
	s->Method = TRANSFINI;
	int k = List_Nbr((yyvsp[-2].l));
	if(k != 3 && k != 4){
	  yymsg(GERROR, "Wrong definition of Transfinite Surface %d: "
		"%d points instead of 3 or 4" , (int)(yyvsp[-5].d), k);
	}
	else{
	  List_Reset(s->TrsfPoints);
	  if (!strcmp((yyvsp[-1].c), "Right"))
	    s->Recombine_Dir = 1;
	  else if (!strcmp((yyvsp[-1].c), "Left"))
	    s->Recombine_Dir = -1;
	  else
	    s->Recombine_Dir = 0;
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read((yyvsp[-2].l), i, &d);
	    int j = (int)fabs(d);
	    Vertex *v = FindPoint(j, THEM);
	    if(!v)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(s->TrsfPoints, &v);
	  }
	}
      }
      List_Delete((yyvsp[-2].l));
      Free((yyvsp[-1].c));
    ;}
    break;

  case 200:
#line 2535 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[-4].d), THEM);
      if(!s)
	yymsg(WARNING, "Unknown surface %d", (int)(yyvsp[-4].d));
      else{
        s->Method = ELLIPTIC;
        int k = List_Nbr((yyvsp[-1].l));
        if(k != 4)
	  yymsg(GERROR, "Wrong definition of Elliptic Surface %d: "
		"%d points instead of 4" , (int)(yyvsp[-4].d), k);
        else{
	  List_Reset(s->TrsfPoints);
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read((yyvsp[-1].l), i, &d);
	    int j = (int)fabs(d);
	    Vertex *v = FindPoint(j, THEM);
	    if(!v)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(s->TrsfPoints, &v);
	  }
	}
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 201:
#line 2562 "Gmsh.y"
    {
      Volume *v = FindVolume((int)(yyvsp[-4].d), THEM);
      if(!v)
	yymsg(WARNING, "Unknown volume %d", (int)(yyvsp[-4].d));
      else{
	v->Method = TRANSFINI;
	int k = List_Nbr((yyvsp[-1].l));
	if(k != 6 && k != 8)
	  yymsg(GERROR, "Wrong definition of Transfinite Volume %d: "
		"%d points instead of 6 or 8" , (int)(yyvsp[-4].d), k);
	else{
	  List_Reset(v->TrsfPoints);
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read((yyvsp[-1].l), i, &d);
	    int j = (int)fabs(d);
	    Vertex *vert = FindPoint(j, THEM);
	    if(!vert)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(v->TrsfPoints, &vert);
	  }
	}
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 202:
#line 2589 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
	double d;
	List_Read((yyvsp[-3].l), i, &d);
	int j = (int)d;
	Surface *s = FindSurface(j, THEM);
	if(s){
	  s->Recombine = 1;
	  s->RecombineAngle = ((yyvsp[-1].d) > 0 && (yyvsp[-1].d) < 90) ? (yyvsp[-1].d) : 90;
	}
      }
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 203:
#line 2603 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	double d;
	List_Read((yyvsp[-1].l), i, &d);
	int j = (int)d;
        Surface *s = FindSurface(j, THEM);
	if(s){
	  s->Recombine = 1;
        }
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 204:
#line 2622 "Gmsh.y"
    { 
      Surface *s = FindSurface((int)(yyvsp[-1].d), THEM);
      if(s)
	setSurfaceEmbeddedPoints(s, (yyvsp[-4].l));
    ;}
    break;

  case 205:
#line 2628 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[-1].d), THEM);
      if(s)
	setSurfaceEmbeddedCurves(s, (yyvsp[-4].l));
    ;}
    break;

  case 206:
#line 2634 "Gmsh.y"
    {
    ;}
    break;

  case 207:
#line 2637 "Gmsh.y"
    {
    ;}
    break;

  case 208:
#line 2644 "Gmsh.y"
    { 
      ReplaceAllDuplicates(THEM);
    ;}
    break;

  case 209:
#line 2648 "Gmsh.y"
    { 
      IntersectAllSegmentsTogether();
    ;}
    break;

  case 210:
#line 2657 "Gmsh.y"
    { (yyval.d) = (yyvsp[0].d);           ;}
    break;

  case 211:
#line 2658 "Gmsh.y"
    { (yyval.d) = (yyvsp[-1].d);           ;}
    break;

  case 212:
#line 2659 "Gmsh.y"
    { (yyval.d) = -(yyvsp[0].d);          ;}
    break;

  case 213:
#line 2660 "Gmsh.y"
    { (yyval.d) = (yyvsp[0].d);           ;}
    break;

  case 214:
#line 2661 "Gmsh.y"
    { (yyval.d) = !(yyvsp[0].d);          ;}
    break;

  case 215:
#line 2662 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      ;}
    break;

  case 216:
#line 2663 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      ;}
    break;

  case 217:
#line 2664 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      ;}
    break;

  case 218:
#line 2666 "Gmsh.y"
    { 
      if(!(yyvsp[0].d))
	yymsg(GERROR, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);     
    ;}
    break;

  case 219:
#line 2672 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  ;}
    break;

  case 220:
#line 2673 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  ;}
    break;

  case 221:
#line 2674 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      ;}
    break;

  case 222:
#line 2675 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      ;}
    break;

  case 223:
#line 2676 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     ;}
    break;

  case 224:
#line 2677 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     ;}
    break;

  case 225:
#line 2678 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     ;}
    break;

  case 226:
#line 2679 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     ;}
    break;

  case 227:
#line 2680 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     ;}
    break;

  case 228:
#line 2681 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     ;}
    break;

  case 229:
#line 2682 "Gmsh.y"
    { (yyval.d) = (yyvsp[-4].d)? (yyvsp[-2].d) : (yyvsp[0].d);  ;}
    break;

  case 230:
#line 2683 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[-1].d));      ;}
    break;

  case 231:
#line 2684 "Gmsh.y"
    { (yyval.d) = log((yyvsp[-1].d));      ;}
    break;

  case 232:
#line 2685 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[-1].d));    ;}
    break;

  case 233:
#line 2686 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-1].d));     ;}
    break;

  case 234:
#line 2687 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[-1].d));      ;}
    break;

  case 235:
#line 2688 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[-1].d));     ;}
    break;

  case 236:
#line 2689 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[-1].d));      ;}
    break;

  case 237:
#line 2690 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[-1].d));     ;}
    break;

  case 238:
#line 2691 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[-1].d));      ;}
    break;

  case 239:
#line 2692 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[-1].d));     ;}
    break;

  case 240:
#line 2693 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));;}
    break;

  case 241:
#line 2694 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[-1].d));     ;}
    break;

  case 242:
#line 2695 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[-1].d));     ;}
    break;

  case 243:
#line 2696 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[-1].d));     ;}
    break;

  case 244:
#line 2697 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[-1].d));     ;}
    break;

  case 245:
#line 2698 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[-1].d));    ;}
    break;

  case 246:
#line 2699 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[-1].d));     ;}
    break;

  case 247:
#line 2700 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 248:
#line 2701 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 249:
#line 2702 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-3].d)*(yyvsp[-3].d)+(yyvsp[-1].d)*(yyvsp[-1].d)); ;}
    break;

  case 250:
#line 2703 "Gmsh.y"
    { (yyval.d) = (yyvsp[-1].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 251:
#line 2705 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[-1].d));      ;}
    break;

  case 252:
#line 2706 "Gmsh.y"
    { (yyval.d) = log((yyvsp[-1].d));      ;}
    break;

  case 253:
#line 2707 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[-1].d));    ;}
    break;

  case 254:
#line 2708 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-1].d));     ;}
    break;

  case 255:
#line 2709 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[-1].d));      ;}
    break;

  case 256:
#line 2710 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[-1].d));     ;}
    break;

  case 257:
#line 2711 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[-1].d));      ;}
    break;

  case 258:
#line 2712 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[-1].d));     ;}
    break;

  case 259:
#line 2713 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[-1].d));      ;}
    break;

  case 260:
#line 2714 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[-1].d));     ;}
    break;

  case 261:
#line 2715 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));;}
    break;

  case 262:
#line 2716 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[-1].d));     ;}
    break;

  case 263:
#line 2717 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[-1].d));     ;}
    break;

  case 264:
#line 2718 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[-1].d));     ;}
    break;

  case 265:
#line 2719 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[-1].d));     ;}
    break;

  case 266:
#line 2720 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[-1].d));    ;}
    break;

  case 267:
#line 2721 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[-1].d));     ;}
    break;

  case 268:
#line 2722 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 269:
#line 2723 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 270:
#line 2724 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-3].d)*(yyvsp[-3].d)+(yyvsp[-1].d)*(yyvsp[-1].d)); ;}
    break;

  case 271:
#line 2725 "Gmsh.y"
    { (yyval.d) = (yyvsp[-1].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 272:
#line 2734 "Gmsh.y"
    { (yyval.d) = (yyvsp[0].d); ;}
    break;

  case 273:
#line 2735 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 274:
#line 2736 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->rank(); ;}
    break;

  case 275:
#line 2737 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->size(); ;}
    break;

  case 276:
#line 2738 "Gmsh.y"
    { (yyval.d) = Get_GmshMajorVersion(); ;}
    break;

  case 277:
#line 2739 "Gmsh.y"
    { (yyval.d) = Get_GmshMinorVersion(); ;}
    break;

  case 278:
#line 2740 "Gmsh.y"
    { (yyval.d) = Get_GmshPatchVersion(); ;}
    break;

  case 279:
#line 2745 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[0].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[0].c));
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = *(double*)List_Pointer_Fast(pSymbol->val, 0);
      Free((yyvsp[0].c));
    ;}
    break;

  case 280:
#line 2761 "Gmsh.y"
    {
      char tmpstring[1024];
      sprintf(tmpstring, "%s_%d", (yyvsp[-4].c), (int)(yyvsp[-1].d)) ;
      Symbol TheSymbol;
      TheSymbol.Name = tmpstring;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", tmpstring);
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = *(double*)List_Pointer_Fast(pSymbol->val, 0);
      Free((yyvsp[-4].c));
    ;}
    break;

  case 281:
#line 2776 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-3].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[-3].c));
	(yyval.d) = 0.;
      }
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)(yyvsp[-1].d))))
	  (yyval.d) = *pd;
	else{
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", (yyvsp[-3].c), (int)(yyvsp[-1].d));
	  (yyval.d) = 0.;
	}
      }
      Free((yyvsp[-3].c));
    ;}
    break;

  case 282:
#line 2796 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-2].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[-2].c));
	(yyval.d) = 0.;
      }
      else{
	(yyval.d) = List_Nbr(pSymbol->val);
      }
      Free((yyvsp[-2].c));
    ;}
    break;

  case 283:
#line 2810 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-1].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[-1].c));
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = (*(double*)List_Pointer_Fast(pSymbol->val, 0) += (yyvsp[0].i));
      Free((yyvsp[-1].c));
    ;}
    break;

  case 284:
#line 2823 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-4].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[-4].c));
	(yyval.d) = 0.;
      }
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)(yyvsp[-2].d))))
	  (yyval.d) = (*pd += (yyvsp[0].i));
	else{
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", (yyvsp[-4].c), (int)(yyvsp[-2].d));
	  (yyval.d) = 0.;
	}
      }
      Free((yyvsp[-4].c));
    ;}
    break;

  case 285:
#line 2846 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[-2].c)))){
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[-2].c));
	(yyval.d) = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption((yyvsp[0].c), pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", (yyvsp[-2].c), (yyvsp[0].c));
	  (yyval.d) = 0.;
	}
	else
	  (yyval.d) = pNumOpt(0, GMSH_GET, 0);
      }
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    ;}
    break;

  case 286:
#line 2864 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[-5].c)))){
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[-5].c));
	(yyval.d) = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption((yyvsp[0].c), pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c));
	  (yyval.d) = 0.;
	}
	else
	  (yyval.d) = pNumOpt((int)(yyvsp[-3].d), GMSH_GET, 0);
      }
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    ;}
    break;

  case 287:
#line 2882 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[-3].c)))){
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[-3].c));
	(yyval.d) = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption((yyvsp[-1].c), pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", (yyvsp[-3].c), (yyvsp[-1].c));
	  (yyval.d) = 0.;
	}
	else
	  (yyval.d) = pNumOpt(0, GMSH_SET|GMSH_GUI, pNumOpt(0, GMSH_GET, 0)+(yyvsp[0].i));
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    ;}
    break;

  case 288:
#line 2900 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory((yyvsp[-6].c)))){
	yymsg(GERROR, "Unknown numeric option class '%s'", (yyvsp[-6].c));
	(yyval.d) = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption((yyvsp[-1].c), pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c));
	  (yyval.d) = 0.;
	}
	else
	  (yyval.d) = pNumOpt((int)(yyvsp[-4].d), GMSH_SET|GMSH_GUI, pNumOpt((int)(yyvsp[-4].d), GMSH_GET, 0)+(yyvsp[0].i));
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    ;}
    break;

  case 289:
#line 2918 "Gmsh.y"
    { 
      (yyval.d) = GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    ;}
    break;

  case 290:
#line 2926 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    ;}
    break;

  case 291:
#line 2930 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    ;}
    break;

  case 292:
#line 2934 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    ;}
    break;

  case 293:
#line 2938 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    ;}
    break;

  case 294:
#line 2942 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    ;}
    break;

  case 295:
#line 2949 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    ;}
    break;

  case 296:
#line 2953 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 297:
#line 2957 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 298:
#line 2961 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 299:
#line 2968 "Gmsh.y"
    {
    ;}
    break;

  case 300:
#line 2971 "Gmsh.y"
    {
       (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 301:
#line 2975 "Gmsh.y"
    {
       (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 302:
#line 2982 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    ;}
    break;

  case 303:
#line 2987 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    ;}
    break;

  case 304:
#line 2995 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    ;}
    break;

  case 305:
#line 3000 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[0].l);
    ;}
    break;

  case 306:
#line 3004 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 307:
#line 3009 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 308:
#line 3013 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
      double *pd;
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 309:
#line 3025 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d)); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 310:
#line 3031 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      if(!(yyvsp[0].d) || ((yyvsp[-4].d) < (yyvsp[-2].d) && (yyvsp[0].d) < 0) || ((yyvsp[-4].d) > (yyvsp[-2].d) && (yyvsp[0].d) > 0)){
        yymsg(GERROR, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
	List_Add((yyval.l), &((yyvsp[-4].d)));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   ;}
    break;

  case 311:
#line 3042 "Gmsh.y"
    {
      // Returns the coordinates of a point and fills a list with it.
      // This allows to ensure e.g. that relative point positions are
      // always conserved
      Vertex *v = FindPoint((int)(yyvsp[-1].d), THEM);
      (yyval.l) = List_Create(3, 1, sizeof(double));      
      if(!v) {
	yymsg(GERROR, "Unknown point '%d'", (int) (yyvsp[-1].d));
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

  case 312:
#line 3062 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    ;}
    break;

  case 313:
#line 3072 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    ;}
    break;

  case 314:
#line 3082 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    ;}
    break;

  case 315:
#line 3092 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-2].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[-2].c));
	double d = 0.0;
	List_Add((yyval.l), &d);
      }
      else{
	for(int i = 0; i < List_Nbr(pSymbol->val); i++)
	  List_Add((yyval.l), (double*)List_Pointer_Fast(pSymbol->val, i));
      }
      Free((yyvsp[-2].c));
    ;}
    break;

  case 316:
#line 3109 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-2].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[-2].c));
	double d = 0.0;
	List_Add((yyval.l), &d);
      }
      else{
	for(int i = 0; i < List_Nbr(pSymbol->val); i++){
	  double d = - *(double*)List_Pointer_Fast(pSymbol->val, i);
	  List_Add((yyval.l), &d);
	}
      }
      Free((yyvsp[-2].c));
    ;}
    break;

  case 317:
#line 3128 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-5].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[-5].c));
	double d = 0.0;
	List_Add((yyval.l), &d);
      }
      else{
	for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	  int j = (int)(*(double*)List_Pointer_Fast((yyvsp[-2].l), i));
	  double *pd;
	  if((pd = (double*)List_Pointer_Test(pSymbol->val, j)))
	    List_Add((yyval.l), pd);
	  else
	    yymsg(GERROR, "Uninitialized variable '%s[%d]'", (yyvsp[-5].c), j);	  
	}
      }
      Free((yyvsp[-5].c));
      List_Delete((yyvsp[-2].l));
    ;}
    break;

  case 318:
#line 3152 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      Symbol TheSymbol;
      TheSymbol.Name = (yyvsp[-5].c);
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", (yyvsp[-5].c));
	double d = 0.0;
	List_Add((yyval.l), &d);
      }
      else{
	for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	  int j = (int)(*(double*)List_Pointer_Fast((yyvsp[-2].l), i));
	  double *pd;
	  if((pd = (double*)List_Pointer_Test(pSymbol->val, j))){
	    double d = - *pd;
	    List_Add((yyval.l), &d);
	  }
	  else
	    yymsg(GERROR, "Uninitialized variable '%s[%d]'", (yyvsp[-5].c), j);	  
	}
      }
      Free((yyvsp[-5].c));
      List_Delete((yyvsp[-2].l));
    ;}
    break;

  case 319:
#line 3181 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    ;}
    break;

  case 320:
#line 3186 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[0].l);
    ;}
    break;

  case 321:
#line 3190 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    ;}
    break;

  case 322:
#line 3194 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    ;}
    break;

  case 323:
#line 3207 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    ;}
    break;

  case 324:
#line 3211 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    ;}
    break;

  case 325:
#line 3223 "Gmsh.y"
    {
      int flag;
      (yyval.u) = Get_ColorForString(ColorString, -1, (yyvsp[0].c), &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    ;}
    break;

  case 326:
#line 3230 "Gmsh.y"
    {
      unsigned int (*pColOpt)(int num, int action, unsigned int value);
      StringXColor *pColCat;
      if(!(pColCat = Get_ColorOptionCategory((yyvsp[-4].c)))){
	yymsg(GERROR, "Unknown color option class '%s'", (yyvsp[-4].c));
	(yyval.u) = 0;
      }
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption((yyvsp[0].c), pColCat))){
	  yymsg(GERROR, "Unknown color option '%s.Color.%s'", (yyvsp[-4].c), (yyvsp[0].c));
	  (yyval.u) = 0;
	}
	else{
	  (yyval.u) = pColOpt(0, GMSH_GET, 0);
	}
      }
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    ;}
    break;

  case 327:
#line 3252 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 328:
#line 3256 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      GmshColorTable *ct = Get_ColorTable((int)(yyvsp[-3].d));
      if(!ct)
	yymsg(GERROR, "View[%d] does not exist", (int)(yyvsp[-3].d));
      else{
	for(int i = 0; i < ct->size; i++) 
	  List_Add((yyval.l), &ct->table[i]);
      }
      Free((yyvsp[-5].c));
    ;}
    break;

  case 329:
#line 3271 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    ;}
    break;

  case 330:
#line 3276 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    ;}
    break;

  case 331:
#line 3283 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[0].c);
    ;}
    break;

  case 332:
#line 3287 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32*sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 333:
#line 3295 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-3].c))+strlen((yyvsp[-1].c))+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-3].c));
      strcat((yyval.c), (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    ;}
    break;

  case 334:
#line 3303 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-1].c))+1)*sizeof(char));
      int i;
      for(i = strlen((yyvsp[-1].c))-1; i >= 0; i--){
	if((yyvsp[-1].c)[i] == '.'){
	  strncpy((yyval.c), (yyvsp[-1].c), i);
	  (yyval.c)[i]='\0';
	  break;
	}
      }
      if(i <= 0) strcpy((yyval.c), (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    ;}
    break;

  case 335:
#line 3317 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-1].c))+1)*sizeof(char));
      int i;
      for(i = strlen((yyvsp[-1].c))-1; i >= 0; i--){
	if((yyvsp[-1].c)[i] == '/' || (yyvsp[-1].c)[i] == '\\')
	  break;
      }
      if(i <= 0)
	strcpy((yyval.c), (yyvsp[-1].c));
      else
	strcpy((yyval.c), &(yyvsp[-1].c)[i+1]);
      Free((yyvsp[-1].c));
    ;}
    break;

  case 336:
#line 3331 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[-1].c);
    ;}
    break;

  case 337:
#line 3335 "Gmsh.y"
    {
      char tmpstring[1024];
      int i = PrintListOfDouble((yyvsp[-3].c), (yyvsp[-1].l), tmpstring);
      if(i < 0){
	yymsg(GERROR, "Too few arguments in Sprintf");
	(yyval.c) = (yyvsp[-3].c);
      }
      else if(i > 0){
	yymsg(GERROR, "%d extra argument%s in Sprintf", i, (i>1)?"s":"");
	(yyval.c) = (yyvsp[-3].c);
      }
      else{
	(yyval.c) = (char*)Malloc((strlen(tmpstring)+1)*sizeof(char));
	strcpy((yyval.c), tmpstring);
	Free((yyvsp[-3].c));
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 338:
#line 3354 "Gmsh.y"
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory((yyvsp[-3].c)))){
	yymsg(GERROR, "Unknown string option class '%s'", (yyvsp[-3].c));
	(yyval.c) = (char*)Malloc(sizeof(char));
	(yyval.c)[0] = '\0';
      }
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption((yyvsp[-1].c), pStrCat))){
	  yymsg(GERROR, "Unknown string option '%s.%s'", (yyvsp[-3].c), (yyvsp[-1].c));
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

  case 339:
#line 3376 "Gmsh.y"
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory((yyvsp[-6].c)))){
	yymsg(GERROR, "Unknown string option class '%s'", (yyvsp[-6].c));
	(yyval.c) = (char*)Malloc(sizeof(char));
	(yyval.c)[0] = '\0';
      }
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption((yyvsp[-1].c), pStrCat))){
	  yymsg(GERROR, "Unknown string option '%s[%d].%s'", (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c));
	  (yyval.c) = (char*)Malloc(sizeof(char));
	  (yyval.c)[0] = '\0';
	}
	else{
	  char *str = pStrOpt((int)(yyvsp[-4].d), GMSH_GET, NULL);
	  (yyval.c) = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy((yyval.c), str);
	}
      }
    ;}
    break;


    }

/* Line 1037 of yacc.c.  */
#line 7468 "Gmsh.tab.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {

		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 yydestruct ("Error: popping",
                             yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
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

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

yyvsp -= yylen;
  yyssp -= yylen;
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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
  yydestruct ("Error: discarding lookahead",
              yytoken, &yylval);
  yychar = YYEMPTY;
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 3399 "Gmsh.y"


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

