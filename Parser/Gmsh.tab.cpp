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

// $Id: Gmsh.tab.cpp,v 1.286 2006-11-29 16:57:01 remacle Exp $
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
#include "GeoUtils.h"
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
#define YYLAST   6476

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  142
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  68
/* YYNRULES -- Number of rules. */
#define YYNRULES  341
/* YYNRULES -- Number of states. */
#define YYNSTATES  1224

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
     366,   376,   378,   380,   388,   397,   410,   417,   425,   433,
     441,   451,   459,   469,   487,   495,   503,   515,   524,   537,
     546,   555,   564,   577,   600,   621,   630,   639,   648,   656,
     665,   671,   683,   689,   699,   701,   703,   705,   706,   709,
     716,   723,   730,   737,   742,   749,   756,   763,   768,   775,
     779,   784,   790,   794,   798,   803,   808,   812,   820,   828,
     832,   840,   844,   847,   850,   866,   869,   876,   885,   894,
     905,   907,   910,   912,   916,   921,   923,   929,   941,   955,
     956,   964,   965,   979,   980,   996,  1005,  1014,  1023,  1036,
    1049,  1062,  1077,  1092,  1107,  1108,  1121,  1122,  1135,  1136,
    1149,  1150,  1167,  1168,  1185,  1186,  1203,  1204,  1223,  1224,
    1243,  1244,  1263,  1265,  1268,  1278,  1286,  1289,  1296,  1306,
    1316,  1325,  1335,  1344,  1353,  1360,  1365,  1372,  1379,  1386,
    1393,  1396,  1399,  1401,  1405,  1408,  1411,  1414,  1418,  1422,
    1426,  1430,  1434,  1438,  1442,  1446,  1450,  1454,  1458,  1462,
    1466,  1470,  1476,  1481,  1486,  1491,  1496,  1501,  1506,  1511,
    1516,  1521,  1526,  1533,  1538,  1543,  1548,  1553,  1558,  1563,
    1570,  1577,  1584,  1589,  1594,  1599,  1604,  1609,  1614,  1619,
    1624,  1629,  1634,  1639,  1646,  1651,  1656,  1661,  1666,  1671,
    1676,  1683,  1690,  1697,  1702,  1704,  1706,  1708,  1710,  1712,
    1714,  1716,  1718,  1724,  1729,  1734,  1737,  1743,  1747,  1754,
    1759,  1767,  1774,  1776,  1779,  1782,  1786,  1790,  1802,  1812,
    1820,  1828,  1829,  1833,  1837,  1839,  1843,  1845,  1847,  1850,
    1854,  1859,  1863,  1869,  1874,  1876,  1878,  1880,  1884,  1889,
    1896,  1904,  1906,  1908,  1912,  1916,  1926,  1934,  1936,  1942,
    1946,  1953,  1955,  1959,  1961,  1963,  1970,  1975,  1980,  1985,
    1992,  1999
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     143,     0,    -1,   144,    -1,     1,     6,    -1,    -1,   144,
     145,    -1,   148,    -1,   147,    -1,   167,    -1,   169,    -1,
     170,    -1,   173,    -1,   174,    -1,   175,    -1,   176,    -1,
     179,    -1,   194,    -1,   195,    -1,   196,    -1,   178,    -1,
     177,    -1,   118,    -1,   118,   118,    -1,    33,   132,     5,
     133,     6,    -1,    33,   132,     5,   133,   146,   209,     6,
      -1,    33,   132,     5,   138,   205,   133,     6,    -1,    33,
     132,     5,   138,   205,   133,   146,   209,     6,    -1,     4,
       5,   139,   149,   140,     6,    -1,     4,     5,     4,   199,
     139,   149,   140,     6,    -1,    -1,   149,   152,    -1,   149,
     156,    -1,   149,   159,    -1,   149,   161,    -1,   149,   162,
      -1,   149,   164,    -1,   197,    -1,   150,   138,   197,    -1,
     197,    -1,   151,   138,   197,    -1,    -1,    -1,     4,   153,
     132,   150,   133,   154,   139,   151,   140,     6,    -1,   209,
      -1,   155,   138,   209,    -1,    -1,    76,   132,   197,   138,
     197,   138,   197,   133,   157,   139,   155,   140,     6,    -1,
     209,    -1,   158,   138,   209,    -1,    -1,    77,   132,   197,
     138,   197,   138,   197,   138,   197,   133,   160,   139,   158,
     140,     6,    -1,    78,   139,   202,   140,   139,   202,   140,
       6,    -1,    -1,    79,   163,   139,   151,   140,     6,    -1,
      80,   132,   197,   133,   203,     6,    -1,     7,    -1,   110,
      -1,   109,    -1,   108,    -1,   107,    -1,   130,    -1,   129,
      -1,     4,   165,   197,     6,    -1,     4,   134,   197,   135,
     165,   197,     6,    -1,     4,   134,   139,   205,   140,   135,
     165,   203,     6,    -1,     4,   134,   135,     7,   203,     6,
      -1,     4,   134,   135,   110,   203,     6,    -1,     4,   166,
       6,    -1,     4,   134,   197,   135,   166,     6,    -1,     4,
     136,     4,     7,   209,     6,    -1,     4,   134,   197,   135,
     136,     4,     7,   209,     6,    -1,     4,   136,     4,   165,
     197,     6,    -1,     4,   134,   197,   135,   136,     4,   165,
     197,     6,    -1,     4,   136,     4,   166,     6,    -1,     4,
     134,   197,   135,   136,     4,   166,     6,    -1,     4,   136,
      89,   136,     4,     7,   206,     6,    -1,     4,   134,   197,
     135,   136,    89,   136,     4,     7,   206,     6,    -1,     4,
     136,    90,     7,   207,     6,    -1,     4,   134,   197,   135,
     136,    90,     7,   207,     6,    -1,    60,   132,     4,   133,
     136,     4,     7,   197,     6,    -1,    60,   132,     4,   133,
     136,     4,     7,   209,     6,    -1,   197,    -1,   209,    -1,
      41,   132,   197,   133,     7,   199,     6,    -1,    56,    41,
     132,   168,   133,     7,   203,     6,    -1,    72,    41,   203,
       7,   139,   197,   138,   197,   138,   197,   140,     6,    -1,
      48,    49,   203,     7,   197,     6,    -1,    44,   132,   197,
     133,     7,   203,     6,    -1,    46,   132,   197,   133,     7,
     203,     6,    -1,    42,   132,   197,   133,     7,   203,     6,
      -1,    42,   132,   197,   133,     7,   203,    52,   199,     6,
      -1,    43,   132,   197,   133,     7,   203,     6,    -1,    43,
     132,   197,   133,     7,   203,    52,   199,     6,    -1,    50,
     132,   197,   133,     7,   139,   197,   138,   197,   138,     5,
     138,     5,   138,     5,   140,     6,    -1,    82,   132,   197,
     133,     7,   203,     6,    -1,    83,   132,   197,   133,     7,
     203,     6,    -1,    84,   132,   197,   133,     7,   203,    88,
     203,    85,   197,     6,    -1,    44,    67,   132,   197,   133,
       7,   203,     6,    -1,    72,    44,   203,     7,   139,   197,
     138,   197,   138,   197,   140,     6,    -1,    56,    44,   132,
     168,   133,     7,   203,     6,    -1,    52,    45,   132,   197,
     133,     7,   203,     6,    -1,    53,    45,   132,   197,   133,
       7,   203,     6,    -1,   100,    45,   132,   197,   133,     7,
     139,   197,   138,   203,   140,     6,    -1,    84,    45,    86,
      87,   132,   197,   133,     7,   201,    88,   139,   203,   138,
     203,   140,    85,   139,   197,   138,   197,   140,     6,    -1,
      84,    45,   132,   197,   133,     7,   201,    88,   139,   203,
     138,   203,   140,    85,   139,   197,   138,   197,   140,     6,
      -1,    45,    67,   132,   197,   133,     7,   203,     6,    -1,
      56,    45,   132,   168,   133,     7,   203,     6,    -1,    55,
      47,   132,   197,   133,     7,   203,     6,    -1,    47,   132,
     197,   133,     7,   203,     6,    -1,    56,    47,   132,   168,
     133,     7,   203,     6,    -1,    62,   199,   139,   171,   140,
      -1,    61,   139,   199,   138,   199,   138,   197,   140,   139,
     171,   140,    -1,    63,   199,   139,   171,   140,    -1,    64,
     139,   199,   138,   197,   140,   139,   171,   140,    -1,   173,
      -1,   172,    -1,   170,    -1,    -1,   172,   169,    -1,   172,
      41,   139,   205,   140,     6,    -1,   172,    44,   139,   205,
     140,     6,    -1,   172,    45,   139,   205,   140,     6,    -1,
     172,    47,   139,   205,   140,     6,    -1,    66,   139,   172,
     140,    -1,    66,     4,   134,   197,   135,     6,    -1,    74,
       4,   134,   197,   135,     6,    -1,    75,     4,   134,   197,
     135,     6,    -1,    69,   139,   172,   140,    -1,    69,     4,
     134,   197,   135,     6,    -1,    69,     4,     6,    -1,    69,
       4,     4,     6,    -1,    89,   206,   139,   172,   140,    -1,
     101,   209,     6,    -1,   102,   209,     6,    -1,   101,   139,
     172,   140,    -1,   102,   139,   172,   140,    -1,     4,   209,
       6,    -1,     4,     4,   134,   197,   135,   209,     6,    -1,
       4,     4,     4,   134,   197,   135,     6,    -1,     4,   197,
       6,    -1,    60,   132,     4,   133,   136,     4,     6,    -1,
      81,     4,     6,    -1,    96,     6,    -1,    38,     6,    -1,
      38,   139,   197,   138,   197,   138,   197,   138,   197,   138,
     197,   138,   197,   140,     6,    -1,    39,     6,    -1,    91,
     132,   197,     8,   197,   133,    -1,    91,   132,   197,     8,
     197,     8,   197,   133,    -1,    91,     4,    92,   139,   197,
       8,   197,   140,    -1,    91,     4,    92,   139,   197,     8,
     197,     8,   197,   140,    -1,    93,    -1,    99,     4,    -1,
      97,    -1,    98,     4,     6,    -1,    94,   132,   197,   133,
      -1,    95,    -1,    65,   199,   139,   172,   140,    -1,    65,
     139,   199,   138,   199,   138,   197,   140,   139,   172,   140,
      -1,    65,   139,   199,   138,   199,   138,   199,   138,   197,
     140,   139,   172,   140,    -1,    -1,    65,   199,   139,   172,
     180,   192,   140,    -1,    -1,    65,   139,   199,   138,   199,
     138,   197,   140,   139,   172,   181,   192,   140,    -1,    -1,
      65,   139,   199,   138,   199,   138,   199,   138,   197,   140,
     139,   172,   182,   192,   140,    -1,    65,    41,   139,   197,
     138,   199,   140,     6,    -1,    65,    44,   139,   197,   138,
     199,   140,     6,    -1,    65,    45,   139,   197,   138,   199,
     140,     6,    -1,    65,    41,   139,   197,   138,   199,   138,
     199,   138,   197,   140,     6,    -1,    65,    44,   139,   197,
     138,   199,   138,   199,   138,   197,   140,     6,    -1,    65,
      45,   139,   197,   138,   199,   138,   199,   138,   197,   140,
       6,    -1,    65,    41,   139,   197,   138,   199,   138,   199,
     138,   199,   138,   197,   140,     6,    -1,    65,    44,   139,
     197,   138,   199,   138,   199,   138,   199,   138,   197,   140,
       6,    -1,    65,    45,   139,   197,   138,   199,   138,   199,
     138,   199,   138,   197,   140,     6,    -1,    -1,    65,    41,
     139,   197,   138,   199,   140,   183,   139,   192,   140,     6,
      -1,    -1,    65,    44,   139,   197,   138,   199,   140,   184,
     139,   192,   140,     6,    -1,    -1,    65,    45,   139,   197,
     138,   199,   140,   185,   139,   192,   140,     6,    -1,    -1,
      65,    41,   139,   197,   138,   199,   138,   199,   138,   197,
     140,   186,   139,   192,   140,     6,    -1,    -1,    65,    44,
     139,   197,   138,   199,   138,   199,   138,   197,   140,   187,
     139,   192,   140,     6,    -1,    -1,    65,    45,   139,   197,
     138,   199,   138,   199,   138,   197,   140,   188,   139,   192,
     140,     6,    -1,    -1,    65,    41,   139,   197,   138,   199,
     138,   199,   138,   199,   138,   197,   140,   189,   139,   192,
     140,     6,    -1,    -1,    65,    44,   139,   197,   138,   199,
     138,   199,   138,   199,   138,   197,   140,   190,   139,   192,
     140,     6,    -1,    -1,    65,    45,   139,   197,   138,   199,
     138,   199,   138,   199,   138,   197,   140,   191,   139,   192,
     140,     6,    -1,   193,    -1,   192,   193,    -1,    73,   139,
     203,   138,   203,   138,   203,   140,     6,    -1,    73,   139,
     203,   138,   203,   140,     6,    -1,    68,     6,    -1,    54,
      44,   203,     7,   197,     6,    -1,    54,    44,   203,     7,
     197,    57,    59,   197,     6,    -1,    54,    44,   203,     7,
     197,    57,    58,   197,     6,    -1,    54,    45,   139,   197,
     140,     7,   203,     6,    -1,    54,    45,   139,   197,   140,
       7,   203,     4,     6,    -1,    51,    45,   139,   197,   140,
       7,   203,     6,    -1,    54,    47,   139,   197,   140,     7,
     203,     6,    -1,    68,    45,   203,     7,   197,     6,    -1,
      68,    45,   203,     6,    -1,    41,   203,    92,    45,   197,
       6,    -1,    44,   203,    92,    45,   197,     6,    -1,    44,
     203,    92,    47,   197,     6,    -1,    45,   203,    92,    47,
     197,     6,    -1,    70,     6,    -1,    71,     6,    -1,   198,
      -1,   132,   197,   133,    -1,   122,   197,    -1,   121,   197,
      -1,   127,   197,    -1,   197,   122,   197,    -1,   197,   121,
     197,    -1,   197,   123,   197,    -1,   197,   124,   197,    -1,
     197,   125,   197,    -1,   197,   131,   197,    -1,   197,   117,
     197,    -1,   197,   118,   197,    -1,   197,   120,   197,    -1,
     197,   119,   197,    -1,   197,   116,   197,    -1,   197,   115,
     197,    -1,   197,   113,   197,    -1,   197,   112,   197,    -1,
     197,   111,   197,     8,   197,    -1,    12,   132,   197,   133,
      -1,    13,   132,   197,   133,    -1,    14,   132,   197,   133,
      -1,    15,   132,   197,   133,    -1,    16,   132,   197,   133,
      -1,    17,   132,   197,   133,    -1,    18,   132,   197,   133,
      -1,    19,   132,   197,   133,    -1,    20,   132,   197,   133,
      -1,    22,   132,   197,   133,    -1,    23,   132,   197,   138,
     197,   133,    -1,    24,   132,   197,   133,    -1,    25,   132,
     197,   133,    -1,    26,   132,   197,   133,    -1,    27,   132,
     197,   133,    -1,    28,   132,   197,   133,    -1,    29,   132,
     197,   133,    -1,    30,   132,   197,   138,   197,   133,    -1,
      31,   132,   197,   138,   197,   133,    -1,    32,   132,   197,
     138,   197,   133,    -1,    21,   132,   197,   133,    -1,    12,
     134,   197,   135,    -1,    13,   134,   197,   135,    -1,    14,
     134,   197,   135,    -1,    15,   134,   197,   135,    -1,    16,
     134,   197,   135,    -1,    17,   134,   197,   135,    -1,    18,
     134,   197,   135,    -1,    19,   134,   197,   135,    -1,    20,
     134,   197,   135,    -1,    22,   134,   197,   135,    -1,    23,
     134,   197,   138,   197,   135,    -1,    24,   134,   197,   135,
      -1,    25,   134,   197,   135,    -1,    26,   134,   197,   135,
      -1,    27,   134,   197,   135,    -1,    28,   134,   197,   135,
      -1,    29,   134,   197,   135,    -1,    30,   134,   197,   138,
     197,   135,    -1,    31,   134,   197,   138,   197,   135,    -1,
      32,   134,   197,   138,   197,   135,    -1,    21,   134,   197,
     135,    -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,
     104,    -1,   105,    -1,   106,    -1,     4,    -1,     4,   141,
     139,   197,   140,    -1,     4,   134,   197,   135,    -1,   137,
       4,   134,   135,    -1,     4,   166,    -1,     4,   134,   197,
     135,   166,    -1,     4,   136,     4,    -1,     4,   134,   197,
     135,   136,     4,    -1,     4,   136,     4,   166,    -1,     4,
     134,   197,   135,   136,     4,   166,    -1,   103,   132,     5,
     138,   197,   133,    -1,   200,    -1,   122,   199,    -1,   121,
     199,    -1,   199,   122,   199,    -1,   199,   121,   199,    -1,
     139,   197,   138,   197,   138,   197,   138,   197,   138,   197,
     140,    -1,   139,   197,   138,   197,   138,   197,   138,   197,
     140,    -1,   139,   197,   138,   197,   138,   197,   140,    -1,
     132,   197,   138,   197,   138,   197,   133,    -1,    -1,   139,
     202,   140,    -1,   132,   202,   133,    -1,   203,    -1,   202,
     138,   203,    -1,   197,    -1,   204,    -1,   139,   140,    -1,
     139,   205,   140,    -1,   122,   139,   205,   140,    -1,   197,
       8,   197,    -1,   197,     8,   197,     8,   197,    -1,    41,
     139,   197,   140,    -1,   170,    -1,   173,    -1,   179,    -1,
       4,   134,   135,    -1,   122,     4,   134,   135,    -1,     4,
     134,   139,   205,   140,   135,    -1,   122,     4,   134,   139,
     205,   140,   135,    -1,   197,    -1,   204,    -1,   205,   138,
     197,    -1,   205,   138,   204,    -1,   139,   197,   138,   197,
     138,   197,   138,   197,   140,    -1,   139,   197,   138,   197,
     138,   197,   140,    -1,     4,    -1,     4,   136,    89,   136,
       4,    -1,   139,   208,   140,    -1,     4,   134,   197,   135,
     136,    90,    -1,   206,    -1,   208,   138,   206,    -1,     5,
      -1,    40,    -1,    35,   132,   209,   138,   209,   133,    -1,
      36,   132,   209,   133,    -1,    37,   132,   209,   133,    -1,
      34,   132,   209,   133,    -1,    34,   132,   209,   138,   205,
     133,    -1,    34,   132,     4,   136,     4,   133,    -1,    34,
     132,     4,   134,   197,   135,   136,     4,   133,    -1
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
     995,  1010,  1014,  1025,  1041,  1057,  1064,  1083,  1101,  1119,
    1137,  1163,  1181,  1207,  1227,  1251,  1275,  1301,  1318,  1325,
    1344,  1363,  1402,  1427,  1446,  1465,  1481,  1501,  1518,  1535,
    1556,  1561,  1566,  1571,  1579,  1580,  1581,  1586,  1589,  1593,
    1609,  1625,  1641,  1662,  1676,  1682,  1688,  1700,  1709,  1719,
    1734,  1753,  1767,  1773,  1779,  1788,  1802,  1847,  1862,  1873,
    1893,  1903,  1925,  1929,  1934,  1939,  1951,  1966,  1982,  2008,
    2035,  2067,  2074,  2079,  2085,  2089,  2098,  2106,  2114,  2123,
    2122,  2136,  2135,  2149,  2148,  2163,  2170,  2177,  2184,  2191,
    2198,  2205,  2212,  2219,  2227,  2226,  2239,  2238,  2251,  2250,
    2263,  2262,  2275,  2274,  2287,  2286,  2299,  2298,  2311,  2310,
    2323,  2322,  2338,  2341,  2347,  2371,  2393,  2402,  2420,  2438,
    2456,  2485,  2520,  2525,  2552,  2566,  2585,  2591,  2597,  2600,
    2607,  2611,  2621,  2622,  2623,  2624,  2625,  2626,  2627,  2628,
    2629,  2636,  2637,  2638,  2639,  2640,  2641,  2642,  2643,  2644,
    2645,  2646,  2647,  2648,  2649,  2650,  2651,  2652,  2653,  2654,
    2655,  2656,  2657,  2658,  2659,  2660,  2661,  2662,  2663,  2664,
    2665,  2666,  2667,  2669,  2670,  2671,  2672,  2673,  2674,  2675,
    2676,  2677,  2678,  2679,  2680,  2681,  2682,  2683,  2684,  2685,
    2686,  2687,  2688,  2689,  2698,  2699,  2700,  2701,  2702,  2703,
    2704,  2708,  2724,  2739,  2759,  2773,  2786,  2809,  2827,  2845,
    2863,  2881,  2889,  2893,  2897,  2901,  2905,  2912,  2916,  2920,
    2924,  2932,  2934,  2938,  2945,  2950,  2958,  2963,  2967,  2972,
    2976,  2988,  2994,  3005,  3025,  3035,  3045,  3055,  3072,  3091,
    3115,  3144,  3149,  3153,  3157,  3170,  3174,  3186,  3193,  3215,
    3219,  3234,  3239,  3246,  3250,  3258,  3266,  3280,  3294,  3298,
    3317,  3339
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
  "NumericIncrement", "Affectation", "PhysicalId", "Shape", "Transform",
  "MultipleShape", "ListOfShapes", "Duplicata", "Delete", "Colorify",
  "Visibility", "Command", "Loop", "Extrude", "@6", "@7", "@8", "@9",
  "@10", "@11", "@12", "@13", "@14", "@15", "@16", "@17",
  "ExtrudeParameters", "ExtrudeParameter", "Transfinite", "Embedding",
  "Coherence", "FExpr", "FExpr_Single", "VExpr", "VExpr_Single",
  "ListOfListOfDouble", "RecursiveListOfListOfDouble", "ListOfDouble",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
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
     167,   168,   168,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     170,   170,   170,   170,   171,   171,   171,   172,   172,   172,
     172,   172,   172,   173,   173,   173,   173,   174,   174,   174,
     174,   175,   176,   176,   176,   176,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   179,   179,   179,   180,
     179,   181,   179,   182,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   183,   179,   184,   179,   185,   179,
     186,   179,   187,   179,   188,   179,   189,   179,   190,   179,
     191,   179,   192,   192,   193,   193,   193,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   195,   195,   195,   195,
     196,   196,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   199,   199,   199,   199,   199,   200,   200,   200,
     200,   201,   201,   201,   202,   202,   203,   203,   203,   203,
     203,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   205,   205,   205,   205,   206,   206,   206,   206,   207,
     207,   208,   208,   209,   209,   209,   209,   209,   209,   209,
     209,   209
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
       9,     1,     1,     7,     8,    12,     6,     7,     7,     7,
       9,     7,     9,    17,     7,     7,    11,     8,    12,     8,
       8,     8,    12,    22,    20,     8,     8,     8,     7,     8,
       5,    11,     5,     9,     1,     1,     1,     0,     2,     6,
       6,     6,     6,     4,     6,     6,     6,     4,     6,     3,
       4,     5,     3,     3,     4,     4,     3,     7,     7,     3,
       7,     3,     2,     2,    15,     2,     6,     8,     8,    10,
       1,     2,     1,     3,     4,     1,     5,    11,    13,     0,
       7,     0,    13,     0,    15,     8,     8,     8,    12,    12,
      12,    14,    14,    14,     0,    12,     0,    12,     0,    12,
       0,    16,     0,    16,     0,    16,     0,    18,     0,    18,
       0,    18,     1,     2,     9,     7,     2,     6,     9,     9,
       8,     9,     8,     8,     6,     4,     6,     6,     6,     6,
       2,     2,     1,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     4,     2,     5,     3,     6,     4,
       7,     6,     1,     2,     2,     3,     3,    11,     9,     7,
       7,     0,     3,     3,     1,     3,     1,     1,     2,     3,
       4,     3,     5,     4,     1,     1,     1,     3,     4,     6,
       7,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     1,     6,     4,     4,     4,     6,
       6,     9
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
       0,     0,     0,     0,     0,   150,     0,   155,     0,   152,
       0,     0,     0,     0,     0,     5,     7,     6,     8,     9,
      10,    11,    12,    13,    14,    20,    19,    15,    16,    17,
      18,   274,   281,   333,    55,   275,   276,   277,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   334,     0,   278,   279,   280,    59,    58,
      57,    56,     0,     0,     0,    61,    60,     0,     0,     0,
       0,     0,     0,     0,   212,     0,     0,   143,     0,   145,
     281,     0,     0,     0,     0,   314,   315,   316,   306,     0,
     307,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     292,     0,     0,     0,     0,     0,     0,     0,     0,   117,
       0,     0,   117,   210,   211,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   327,     0,     0,     0,     0,     0,
     142,     0,   151,     0,   333,   117,     0,   117,     0,     0,
       0,     0,     0,   285,     0,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   281,   215,   214,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   136,     0,     0,     0,     0,   281,     0,
       0,     0,   308,   321,   322,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   294,   293,     0,     0,     0,     0,   117,   117,
       0,     0,     0,     0,     0,     0,     0,     0,   117,     0,
       0,     0,     0,   129,     0,     0,     0,     0,     0,     0,
     141,     0,     0,     0,     0,     0,     0,     0,   117,     0,
       0,     0,   153,     0,     0,   132,     0,   133,     0,     0,
     287,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,    62,     0,   230,   229,   228,   227,
     223,   224,   226,   225,   218,   217,   219,   220,   221,   222,
       0,     0,     0,   317,     0,     0,     0,     0,     0,   213,
       0,   309,   311,     0,     0,     0,     0,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    82,     0,     0,     0,     0,
       0,     0,     0,   296,   295,   116,     0,   115,   114,     0,
       0,     0,     0,     0,     0,     0,   159,     0,     0,     0,
       0,     0,   123,   118,   205,     0,   130,     0,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   154,     0,   134,   135,     0,   283,   289,
       0,    29,    40,     0,     0,     0,    52,     0,     0,    30,
      31,    32,    33,    34,    35,   232,   253,   233,   254,   234,
     255,   235,   256,   236,   257,   237,   258,   238,   259,   239,
     260,   240,   261,   252,   273,   241,   262,     0,     0,   243,
     264,   244,   265,   245,   266,   246,   267,   247,   268,   248,
     269,     0,     0,     0,     0,     0,     0,     0,     0,   338,
       0,     0,   336,   337,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,     0,     0,     0,   284,     0,
      23,    21,     0,     0,     0,     0,   283,   313,   318,     0,
     310,     0,   323,   324,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   112,     0,     0,     0,     0,     0,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,     0,     0,     0,     0,     0,   286,     0,
     282,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,     0,     0,     0,     0,     0,    68,
      69,    71,     0,     0,   331,     0,    77,   231,    22,     0,
       0,     0,     0,     0,     0,   312,   206,     0,     0,     0,
       0,   207,   208,     0,   209,     0,     0,    86,     0,     0,
       0,     0,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   192,   124,     0,     0,     0,     0,     0,
       0,   204,   128,     0,     0,   125,   126,     0,     0,     0,
     301,     0,   328,     0,     0,     0,   146,     0,   138,   288,
     137,     0,     0,     0,     0,     0,   304,     0,     0,   242,
     263,   249,   270,   250,   271,   251,   272,     0,   340,   339,
     335,   291,     0,    55,     0,     0,     0,     0,    63,     0,
       0,     0,   329,    24,    25,     0,     0,   319,     0,    83,
      89,     0,    91,     0,     0,    87,     0,    88,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,     0,     0,     0,     0,   117,     0,   174,
       0,   176,     0,   178,     0,     0,   196,     0,   160,   193,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
      28,     0,    36,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,    74,     0,     0,    75,     0,   332,
       0,     0,   320,     0,     0,    97,   105,     0,   202,   100,
     101,     0,     0,     0,   200,   203,   107,    84,    99,   106,
     109,     0,     0,     0,   300,     0,   299,     0,     0,   165,
       0,     0,   166,     0,     0,   167,     0,     0,     0,     0,
     119,   120,   121,   122,     0,     0,   301,     0,     0,     0,
       0,     0,   326,     0,   148,   147,     0,    41,     0,     0,
       0,   305,     0,     0,     0,     0,     0,    64,    70,    72,
       0,    78,     0,    26,     0,    90,    92,     0,   199,   198,
     201,    79,    80,   117,     0,   113,     0,     0,     0,     0,
       0,     0,   117,     0,     0,     0,     0,     0,   303,   302,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
      39,    53,    54,   341,     0,   330,     0,     0,     0,     0,
     298,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,     0,     0,     0,     0,     0,     0,     0,   325,   149,
       0,     0,     0,     0,     0,    76,     0,     0,   111,     0,
     180,     0,     0,   182,     0,     0,   184,     0,     0,   157,
       0,   117,     0,     0,     0,     0,     0,     0,    96,     0,
       0,    45,     0,    51,     0,     0,   297,   168,     0,     0,
     175,   169,     0,     0,   177,   170,     0,     0,   179,     0,
     163,     0,   195,    85,    98,     0,     0,   102,     0,     0,
       0,     0,     0,     0,   186,     0,   188,     0,   190,   162,
     158,     0,     0,     0,     0,    42,     0,    49,     0,     0,
       0,   171,     0,     0,   172,     0,     0,   173,     0,     0,
     194,     0,     0,     0,    43,     0,   144,     0,     0,     0,
       0,     0,     0,     0,   164,     0,     0,     0,     0,     0,
       0,   181,     0,   183,     0,   185,     0,     0,     0,    44,
      46,     0,    47,    93,     0,     0,     0,     0,     0,     0,
       0,   187,   189,   191,     0,     0,    48,    50,     0,     0,
       0,   104,     0,   103
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     2,     3,    55,   632,    56,    57,   383,   921,   927,
     559,   712,  1045,  1173,   560,  1139,  1201,   561,  1175,   562,
     563,   716,   564,   121,   213,    58,   493,   523,   135,   506,
     507,   136,    62,    63,    64,    65,    66,   137,   681,  1100,
    1151,   970,   973,   976,  1118,  1122,  1126,  1162,  1165,  1168,
     792,   793,    68,    69,    70,   138,   124,   332,   170,   913,
     825,   826,   140,   305,   196,   627,   745,   495
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -870
static const short int yypact[] =
{
    2706,    41,    57,  3103,  -870,  -870,  2225,  -108,    20,    77,
    1628,   -39,   -23,  1342,  1497,     2,    36,    56,    74,   137,
     207,   213,   496,   224,   377,   136,   155,   167,   167,   238,
     355,     9,   281,    10,   379,   391,     4,   433,   449,   455,
     330,   333,   -28,    11,    28,  -870,   337,  -870,   468,  -870,
     489,   501,   440,    18,    25,  -870,  -870,  -870,  -870,  -870,
    -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,
    -870,  -870,    17,    15,  -870,  -870,  -870,  -870,   -63,   178,
     279,   308,   347,   369,   397,   413,   459,   482,   483,   498,
     503,   510,   627,   632,   633,   638,   647,   648,   678,   374,
     388,   394,   410,  -870,   453,  -870,  -870,  -870,  -870,  -870,
    -870,  -870,  2405,  2405,  2405,  -870,  -870,  2405,  1826,   106,
     561,  2405,   563,   604,  -870,   573,   589,  -870,  2405,  -870,
     495,   470,  2064,  2405,  1210,  -870,  -870,  -870,   680,   526,
    -870,  2405,  2405,   494,  2405,   529,   511,   535,  2405,  2405,
    1759,  2405,   530,   542,   543,  1759,   544,   545,   557,   558,
     577,   578,   598,   691,   167,   167,   167,  2405,  2405,   -54,
    -870,   -22,   167,   574,   595,   605,  2094,   -19,   621,  -870,
    1759,    31,  -870,  -870,  -870,  1759,  1759,   622,   637,   778,
    2405,  2405,   -68,  2405,   649,  2405,   635,   696,  2405,  2405,
    -870,   783,  -870,   662,  -870,  -870,   800,  -870,   808,   685,
    2405,   818,   687,  -870,   167,  -870,  2405,  2405,  2405,  2405,
    2405,  2405,  2405,  2405,  2405,  2405,  2405,  2405,  2405,  2405,
    2405,  2405,  2405,  2405,  2405,  2405,  2405,  2405,  2405,  2405,
    2405,  2405,  2405,  2405,  2405,  2405,  2405,  2405,  2405,  2405,
    2405,  2405,  2405,  2405,  2405,  2405,  2405,  2405,   487,   368,
     368,   368,   836,   602,   714,   714,   714,  1424,    65,  2275,
    3111,   280,   723,   855,   731,   858,  -870,  -870,  2405,  2405,
    2405,  2405,  2405,  2405,  2405,  2405,  2405,  2405,  2405,  2405,
    2405,  2405,  2405,  -870,   -94,  3747,  1890,  2405,   740,  2275,
    5241,  2435,  -870,   680,  -870,   675,  2405,   821,  5264,  5287,
    2405,  5310,   773,  2405,   825,  5333,  5356,   868,  5379,  2405,
    2405,  2405,   871,  2405,  2405,  2405,   636,   636,   636,   636,
     755,   260,  -870,  -870,  3771,  3795,   167,   167,   786,   786,
     378,  2405,  2405,  2405,  2094,  2094,  2405,   387,  -870,  2405,
    2768,    73,   904,  -870,  2405,  2789,   907,   917,  2405,  2405,
    -870,  5402,  5425,   824,  2405,  5448,   837,  3819,  -870,   789,
    2541,  5471,  -870,  2405,  2835,  -870,  2895,  -870,  2405,  4611,
     168,  2405,   376,    -3,  5494,  4632,  5517,  4653,  5540,  4674,
    5563,  4695,  5586,  4716,  5609,  4737,  5632,  4758,  5655,  4779,
    5678,  4800,  5701,  4821,  5724,  4842,  3843,  3867,  5747,  4863,
    5770,  4884,  5793,  4905,  5816,  4926,  5839,  4947,  5862,  4968,
    3891,  3915,  3939,  3963,  3987,  4011,   706,   127,   791,   797,
     798,   794,  2405,  -870,  1759,  1759,   733,    71,   368,  2405,
     927,   930,    16,   801,  -870,  2558,   979,   894,   629,   629,
     732,   732,   732,   732,   447,   447,   714,   714,   714,   714,
       6,  2275,  2405,  -870,  2275,  4989,  1555,  2027,   742,   931,
    2275,  -870,  2580,  2405,   932,   933,  5885,   935,  2405,  2405,
    5908,  2405,   936,   937,  2405,   938,  1686,  5931,  5954,  2405,
    2781,  2908,  5977,   804,  6345,  -870,   813,   814,   815,   819,
     167,  2405,  2405,  -870,  -870,  -870,   809,  3165,  -870,   810,
    2405,  4035,  4059,  4083,  3723,   167,  2916,  5010,   -69,   -45,
     -58,   -14,  -870,  -870,  -870,  2405,  -870,  5031,  -870,   817,
     822,  5052,  5073,   947,   950,   826,  6000,   953,   827,  2405,
    2962,  2405,  2405,  -870,  6023,  -870,  -870,  5094,    61,  -870,
    3229,  -870,  -870,   830,   832,   828,  -870,   833,   960,  -870,
    -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,
    -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,
    -870,  -870,  -870,  -870,  -870,  -870,  -870,  2405,  2405,  -870,
    -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,
    -870,  2405,  2405,  2405,  2405,  2405,  2405,  2405,   964,  -870,
    2275,   368,  -870,  -870,  2405,   978,   980,   853,   119,  2405,
     984,   985,  1175,  -870,   986,   860,    11,   989,  -870,  2405,
    -870,   878,   368,   221,  4107,   745,    47,  -870,  -870,  2275,
    -870,   167,   680,  -870,  2405,  1311,  1759,  1759,   993,  1759,
    1371,  1462,   995,  1593,  1759,  1759,  1855,   864,   997,   998,
    1001,   712,  1014,  1016,  1020,  1021,  1025,  1026,  1027,  1032,
     390,  4131,  4155,  -870,  -870,  3255,   167,   167,   167,   392,
    -870,   256,  1031,  2405,  2275,  2405,  2275,  2275,  2275,  2252,
    1033,  2405,  2405,  1034,  1037,  1759,  1759,  2405,  1038,  1759,
    1040,  4179,  -870,  2601,   581,  1039,  1043,  1048,  -870,  1049,
    -870,    12,   906,  2405,  2405,  1759,   915,  2405,  -870,  6046,
    5115,  6069,  5136,  6092,  5157,  6115,  5178,  5199,   923,   236,
     924,  6138,  -870,  -870,    22,   285,   922,  1052,  2360,  -870,
    -870,  -870,    11,  2405,  -870,   746,  -870,  6345,  -870,  1054,
      21,  2405,   926,   749,    19,  6345,  -870,    30,    32,  1759,
    1056,  -870,  -870,  1759,  -870,  1057,  1059,  -870,  2405,  1759,
    1759,  1759,  -870,   297,  1759,  1759,  1759,  1759,  1759,  1759,
    1759,   400,  2405,  2405,  2405,   928,   187,   298,   328,  2094,
    1060,   929,   -27,  -870,  -870,  6161,   753,  6184,   754,   758,
     759,  -870,  -870,  4203,  4227,  -870,  -870,  1063,  1064,  6207,
      24,   983,  -870,  2405,  2405,  2405,  -870,   934,  -870,   168,
    -870,  1066,  2405,  4251,  4275,   764,  -870,  2405,  6230,  -870,
    -870,  -870,  -870,  -870,  -870,  -870,  -870,   940,  -870,  -870,
    -870,  -870,  1759,   368,  2405,  1068,  1073,    16,  -870,  1072,
    5220,    11,  -870,  -870,  -870,   368,  4299,  -870,   944,  -870,
    -870,   167,  -870,   167,  1074,  -870,  1075,  -870,  -870,  4323,
    1076,  1077,  1078,  2405,  2405,   840,  1080,  1081,  1083,  1084,
    1087,  1099,  -870,   636,  3281,  6253,  3139,   786,   167,  1101,
     167,  1103,   167,  1106,  3307,   396,  -870,  1759,  -870,  -870,
     931,  1107,   935,  1108,  1110,  1111,  2405,  2405,  -870,  -870,
    1112,  1759,  1759,  1030,  1759,  3169,   437,  6276,  2405,  -870,
    -870,   246,  6345,  2405,  2405,  1759,   981,   765,  6345,  1759,
    1120,  1119,  1127,  2381,  -870,  1128,  1131,  -870,  1003,  -870,
    1134,  2405,  -870,    45,    50,  -870,  -870,  2405,  -870,  -870,
    -870,  2462,  2483,  1135,  -870,  -870,  -870,  -870,  -870,  -870,
    -870,  2507,  1136,  1004,  -870,  2405,  -870,   994,   442,  -870,
    1005,   445,  -870,  1006,   452,  -870,  1007,  1008,  2405,  1010,
    -870,  -870,  -870,  -870,  4347,  4371,    24,   253,   768,  1011,
    1069,  2405,  -870,  2405,  -870,  -870,  4395,  -870,  2405,  4419,
    4443,  -870,  1759,  2405,  1143,  1145,  1022,  -870,  -870,  -870,
      11,  -870,  1067,  -870,  4467,  -870,  -870,  4491,  -870,  -870,
    -870,  -870,  -870,   786,  3199,  -870,  2094,   256,  2094,   256,
    2094,   256,  -870,  3333,  1759,  2405,  2405,  1065,  -870,  -870,
    1759,  2405,  3359,  3385,  1759,  1017,  6345,  2405,  2405,   769,
    6345,  -870,  -870,  -870,  1152,  -870,  2405,  1154,  1024,  2405,
    -870,  3411,   454,    46,  3437,   481,    48,  3463,   484,   130,
    3022,  1023,   775,  3489,  3515,  1029,  1028,  2524,  -870,  -870,
    1035,  2405,  6299,  4515,  1155,  -870,  4539,  1036,  -870,  3541,
    1163,  2405,  1164,  1165,  2405,  1166,  1167,  2405,  1170,  -870,
     256,  -870,  1759,  1171,  1172,  1173,  1759,  1759,  -870,  1176,
     781,  -870,  2405,  -870,  2405,  1179,  -870,  -870,  1047,  3567,
    -870,  -870,  1050,  3593,  -870,  -870,  1051,  3619,  -870,   191,
    3043,  1053,  -870,  -870,  -870,  1058,  1055,  -870,  1181,  1061,
    6322,  3645,  1070,   256,  1182,   256,  1185,   256,  1186,  -870,
    -870,   256,  1191,  1759,  1113,  -870,   368,  -870,  1193,  1198,
     193,  -870,  1071,   194,  -870,  1079,   228,  -870,  1104,   243,
    -870,  1105,  1109,   782,  -870,  1114,  -870,  1115,  1200,   256,
    1201,   256,  1203,   256,  -870,  1126,  2405,   368,  1209,   368,
    1211,  -870,   276,  -870,   277,  -870,   303,  1117,  4563,  -870,
    -870,   785,  -870,  -870,  1238,  1240,  1241,  2405,  2405,   368,
    1244,  -870,  -870,  -870,  4587,  3671,  -870,  -870,  2405,  1246,
    3697,  -870,  1248,  -870
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -870,  -870,  -870,  -870,   466,  -870,  -870,   609,  -870,   123,
    -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,
    -870,  -870,  -870,  -264,    -2,  -870,   103,  1254,     3,  -336,
    -174,     8,  -870,  -870,  -870,  -870,  -870,  1255,  -870,  -870,
    -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,  -870,
    -699,  -706,  -870,  -870,  -870,    -6,  -870,   275,  -870,   273,
    -869,   352,  -100,  -259,  -598,   414,  -870,    -4
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const short int yytable[] =
{
     123,   552,   125,   509,   122,   350,    60,   439,   355,   146,
     436,    61,   630,   178,   181,   194,   552,   192,   363,   214,
     625,   209,   143,   204,   126,   859,   127,   854,   744,    74,
     204,   374,   197,   376,   304,   352,   860,   353,   862,   460,
     468,   790,   987,   988,   461,   185,   791,     4,   186,   206,
     208,  1015,    99,   100,   101,   102,  1016,     5,   103,    99,
     100,   101,   102,   683,   364,   103,   204,   336,   337,   216,
     684,   217,   434,   553,   554,   555,   556,   557,    74,   524,
     525,   687,   861,   129,   863,   338,   899,   685,   553,   554,
     555,   556,   557,   141,   686,    99,   100,   101,   102,   336,
     337,   103,   336,   337,   193,   150,   264,   265,   266,   142,
     271,   267,   270,   898,   790,   275,   790,   339,   149,   791,
     348,   791,   295,   735,   631,   688,   265,   300,   303,   108,
     109,   110,   111,  1049,   148,   308,   309,   558,   311,   631,
     336,   337,   315,   316,   849,   318,   115,   116,   179,   182,
     195,   210,   821,   211,   215,   626,   911,   205,   212,   128,
     198,   334,   335,   912,   207,   354,   336,   337,   149,   304,
     335,   336,   337,   619,   516,   435,   115,   116,   108,   109,
     110,   111,   152,   707,   361,   362,  1092,   365,  1095,   367,
     115,   116,   370,   371,   540,   272,   273,   707,   790,   304,
     115,   116,   633,   791,   379,   635,   151,   618,   736,   737,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   153,   939,   427,   428,   429,   430,   154,   790,
     609,   790,   790,   303,   791,   610,   791,   791,   163,   440,
    1098,   158,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   438,   165,   166,
     465,   466,   843,   303,   164,   265,   790,   115,   116,   167,
     472,   791,   169,   171,   476,   177,   168,   480,   336,   337,
     218,   790,   219,   486,   487,   488,   791,   490,   491,   492,
     494,   494,   494,   494,   790,   888,   180,   889,  1063,   791,
    1066,  1149,  1069,  1178,  1180,   511,   512,   513,   264,   265,
     514,   505,   505,   517,   790,   790,   508,   508,   527,   791,
     791,   729,   531,   532,   750,   873,   874,   899,   536,   470,
     899,   304,   139,   899,   304,   145,   147,   544,  1182,   839,
     643,   790,   547,   204,   470,   550,   791,   172,   549,   997,
     753,   336,   337,  1184,   998,   183,  1038,   108,   109,   110,
     111,   925,   108,   109,   110,   111,   173,   184,   500,   174,
     175,  1129,    99,   100,   101,   102,   882,   883,   103,   115,
     116,   220,  1054,   221,   115,   116,  1204,  1205,   159,   336,
     337,   160,   161,   899,   162,   796,   465,   798,   799,   800,
     496,   497,   498,   622,   621,   620,   890,   187,   891,   331,
     222,   333,   223,  1206,  1160,   993,  1163,   340,  1166,   336,
     337,   347,  1169,   188,   899,   303,   634,   899,   303,   189,
     899,   465,   190,   899,   642,   191,   892,   645,   893,   199,
     842,   844,   650,   651,   200,   653,   165,   166,   656,   224,
    1192,   225,  1194,   661,  1196,   203,   899,   167,   899,   382,
     899,   426,   204,   201,   176,   671,   672,   336,   337,   336,
     337,   226,   317,   227,   675,   202,   258,   322,   336,   337,
     304,   336,   337,   336,   337,   551,   510,   336,   337,   689,
     259,    99,   100,   101,   102,   515,   260,   103,   782,   228,
     789,   229,   351,   701,   978,   703,   704,   356,   357,   304,
     155,   156,   261,   157,   709,   230,   708,   231,   278,   279,
     280,   967,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   336,   337,   274,   336,   337,   292,   276,
     289,   290,   291,   336,   337,   336,   337,   994,   292,   293,
    1026,   719,   720,  1028,   304,   262,   304,   304,   304,   815,
    1030,   232,  1091,   233,   294,   721,   722,   723,   724,   725,
     726,   727,   336,   337,   303,   336,   337,   730,   731,   297,
     277,   503,   504,   738,   234,   236,   235,   237,   307,  1094,
     333,   312,  1097,   747,   115,   116,   310,   314,   749,   296,
     238,   211,   239,   303,   708,   240,   212,   241,   755,    71,
     263,   204,   242,   313,   243,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,   319,
      99,   100,   101,   102,   320,   321,   103,   795,   303,   797,
     303,   303,   303,   323,   324,   803,   804,  1058,   306,   325,
     326,   809,   278,   279,   280,   330,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   823,   824,   327,
     328,   828,   292,   341,   816,   278,   279,   280,   772,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     329,   115,   116,   845,   342,   292,   432,   850,   211,   104,
     105,   106,   107,   212,   343,   856,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   349,   358,   112,   113,   244,
     292,   245,   869,   114,   246,   248,   247,   249,   117,   773,
     250,   359,   251,   120,   368,   670,   884,   885,   886,   252,
     254,   253,   255,   894,   360,   366,   615,   616,   369,   372,
     679,   278,   279,   280,   373,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   375,   915,   916,   917,
     256,   292,   257,   470,   377,   471,   922,   919,   478,   378,
     479,   928,   380,   278,   279,   280,   381,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   933,   932,
     607,   431,   608,   292,   953,   292,   954,    26,    27,    28,
      29,   940,    31,   287,   288,   289,   290,   291,  1070,   441,
      37,    38,   442,   292,   444,   443,   473,   951,   952,   115,
     116,   470,   481,   617,   467,   484,   211,   961,   489,   962,
     470,   212,   640,   470,   851,   752,   852,   470,   499,   858,
     505,   470,   470,   901,   903,   508,   470,   470,   904,   905,
     984,   985,   925,  1003,   926,  1004,   925,   925,  1039,  1084,
     526,   535,   996,  1102,   529,  1103,   754,   999,  1000,  1003,
    1187,  1138,  1188,  1209,   530,  1210,   538,  1130,   541,   611,
     612,   613,   614,   623,   624,  1014,   628,   665,   641,   646,
     647,  1017,   649,   654,   655,   657,   666,   667,   668,   673,
     674,   786,   787,   788,   695,   669,   691,   696,   697,  1024,
     699,   692,   713,   700,   714,   717,   718,   715,   728,   278,
     279,   280,  1033,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   732,  1042,   733,  1043,   734,   292,
     739,   740,  1046,   742,   743,   746,   748,  1050,   757,   758,
     759,   760,   763,   768,   769,   770,   765,   766,   771,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
    1061,   774,  1064,   775,  1067,   292,   505,   776,   777,  1073,
    1074,   508,   778,   779,   780,  1077,   781,   794,   822,   802,
     805,  1082,  1083,   806,   812,   810,   817,   807,   808,   818,
    1086,   811,   819,  1089,   827,   820,   838,   840,   846,   847,
     853,   857,   865,   867,   895,   868,   896,   887,   897,   908,
     909,   914,   920,   918,   934,   928,   930,   935,   937,   942,
     945,   946,   948,   949,   950,  1119,   955,   956,  1123,   957,
     958,  1127,   280,   959,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   960,  1140,   969,  1141,   972,
     292,   864,   975,   980,   981,   866,   982,   983,   989,   986,
    1002,   870,   871,   872,  1006,  1007,   875,   876,   877,   878,
     879,   880,   881,  1008,  1025,  1010,   943,  1011,   944,  1012,
    1013,  1020,  1022,  1023,  1027,  1029,  1031,  1032,  1034,  1051,
    1040,  1052,  1174,  1075,  1041,  1053,  1081,  1055,  1085,  1087,
     711,  1113,  1101,   968,  1088,   971,  1107,   974,  1106,  1117,
    1120,  1121,  1124,  1125,  1115,  1109,  1128,  1132,  1133,  1134,
    1198,   741,  1137,  1199,  1142,  1202,  1143,  1155,  1161,  1145,
    1147,  1164,  1167,  1152,   931,  1154,  1153,  1170,  1172,  1176,
    1156,  1214,  1215,  1177,  1110,  1216,  1191,  1193,  1159,  1195,
    1179,  1197,  1220,    71,   130,  1200,   855,  1203,  1181,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,  1183,  1211,  1185,  1212,  1213,  1186,   979,
    1217,   131,  1221,  1189,  1223,  1190,  1207,    59,    67,  1037,
       0,   936,     0,     0,     0,     0,   990,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,  1001,     0,     0,
       0,  1005,     0,     0,    37,    38,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,  1062,     0,  1065,     0,  1068,   292,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   756,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,   301,     0,     0,     0,     0,   114,     0,     0,
       0,     0,   117,     0,     0,    71,   130,   120,     0,     0,
     302,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,     0,   761,     0,     0,
       0,     0,     0,   131,     0,     0,  1072,     0,     0,     0,
       0,     0,  1076,     0,     0,     0,  1080,     0,     0,     0,
       0,     0,     0,    26,    27,    28,    29,    30,    31,   143,
       0,     0,     0,     0,     0,     0,    37,    38,     0,     0,
       0,     0,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,   104,   105,   106,   107,     0,
       0,     0,     0,     0,  1131,     0,     0,     0,  1135,  1136,
       0,     0,     0,   112,   132,     0,     0,     0,   762,   114,
       0,     0,     0,     0,   144,     0,     0,     0,     0,   120,
       0,   134,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
      71,   130,   292,     0,     0,  1171,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,   278,   279,   280,   131,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,     0,   433,    26,    27,
      28,    29,    30,    31,   146,     0,     0,     0,     0,     0,
       0,    37,    38,   278,   279,   280,     0,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,     0,     0,     0,     0,     0,   764,
     104,   105,   106,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,   132,
       0,     0,     0,     0,   114,     0,     0,     0,     0,   117,
       0,    71,   130,     0,   120,     0,   134,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,     0,     0,     0,     0,   278,   279,   280,   131,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,    26,
      27,    28,    29,    30,    31,   637,     0,     0,     0,     0,
       0,     0,    37,    38,   278,   279,   280,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
     132,     0,     0,     0,     0,   114,     0,     0,     0,     0,
     133,     0,    71,   130,     0,   120,     0,   134,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,   278,   279,   280,
     131,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,     0,     0,
      26,    27,    28,    29,    30,    31,   658,     0,     0,    71,
     263,     0,     0,    37,    38,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
       0,   767,   104,   105,   106,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   132,     0,     0,     0,     0,   114,     0,     0,     0,
       0,   117,     0,    71,   263,     0,   120,     0,   134,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   113,     0,
       0,     0,     0,   114,     0,     0,     0,     0,   117,     0,
       0,   268,     0,   120,     0,   269,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,   113,     0,     0,     0,     0,   114,     0,     0,
       0,     0,   117,     0,     0,   463,     0,   120,     0,   464,
      71,   263,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,     0,    71,   298,     0,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    71,   263,     0,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,     0,     0,
     104,   105,   106,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,   113,
       0,     0,     0,     0,   114,     0,     0,     0,     0,   117,
       0,     0,   638,     0,   120,     0,   639,   104,   105,   106,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   112,   113,     0,     0,     0,
       0,   114,     0,     0,     0,     0,   117,   104,   105,   106,
     107,   120,     0,   299,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   344,   345,     0,     0,     0,
       0,   114,     0,     0,     0,     0,   346,     0,    71,    72,
      73,   120,    74,   168,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   801,    99,
     100,   101,   102,     0,     0,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,   130,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,    26,    27,    28,    29,
      30,    31,     0,     0,     0,     0,   112,   113,     0,    37,
      38,     0,   114,     0,   115,   116,     0,   117,     0,   118,
       0,   119,   120,   278,   279,   280,   848,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   104,   105,
     106,   107,     0,   292,     0,     0,     0,  1009,     0,     0,
       0,     0,     0,     0,     0,     0,   112,   301,     0,     0,
       0,     0,   114,     0,     0,     0,     0,   117,    71,   263,
       0,     0,   120,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    71,   298,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,  1018,     0,
       0,   278,   279,   280,     0,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,  1019,
       0,   292,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,   104,   105,
     106,   107,   292,  1021,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,   113,     0,     0,
    1108,     0,   114,     0,     0,     0,     0,   117,   104,   105,
     106,   107,   120,     0,     0,     0,     0,     0,     0,   542,
       0,     0,     0,     0,     0,     0,   112,   113,     0,     0,
       0,     0,   114,     0,     0,     0,   629,   117,     0,     0,
       0,     0,   120,   278,   279,   280,     0,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   644,     0,
       0,     0,     0,   292,   278,   279,   280,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   814,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,     0,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,   278,   279,   280,   292,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,   278,   279,   280,   292,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,   278,
     279,   280,   292,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
       0,   278,   279,   280,     0,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,    -4,     1,     0,     0,
      -4,   292,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,     0,     0,    -4,
       0,     0,     0,     0,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,     0,     0,     0,     0,     0,    -4,    -4,    -4,
      -4,     0,     0,     0,     0,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,   518,
      11,    12,   519,   520,    15,   521,    17,     0,    18,     0,
      20,    21,     0,    23,    24,     0,     0,     0,     0,     0,
     518,    11,    12,   519,   520,    15,   521,    17,     0,    18,
      36,    20,    21,     0,    23,    24,     0,     0,     0,     0,
      40,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,    52,     0,
       0,    40,    41,    42,     0,     0,   518,    11,    12,   519,
     520,    15,   521,    17,     0,    18,     0,    20,    21,    52,
      23,    24,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    36,   522,     0,
       0,     0,   292,     0,     0,     0,     0,    40,    41,    42,
       0,   662,     0,     0,     0,     0,     0,     0,     0,   528,
       0,     0,     0,     0,     0,    52,   518,    11,    12,   519,
     520,    15,   521,    17,     0,    18,     0,    20,    21,     0,
      23,    24,     0,     0,     0,     0,     0,   518,    11,    12,
     519,   520,    15,   521,    17,     0,    18,    36,    20,    21,
       0,    23,    24,     0,     0,   545,     0,    40,    41,    42,
       0,     0,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,    52,     0,     0,    40,    41,
      42,     0,     0,   518,    11,    12,   519,   520,    15,   521,
      17,     0,    18,     0,    20,    21,    52,    23,    24,   278,
     279,   280,     0,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,    36,   546,     0,     0,     0,   292,
       0,     0,     0,     0,    40,    41,    42,     0,   663,     0,
       0,     0,     0,     0,     0,     0,   680,     0,     0,     0,
       0,     0,    52,   518,    11,    12,   519,   520,    15,   521,
      17,     0,    18,     0,    20,    21,     0,    23,    24,     0,
       0,     0,     0,     0,   518,    11,    12,   519,   520,    15,
     521,    17,     0,    18,    36,    20,    21,     0,    23,    24,
       0,     0,   702,     0,    40,    41,    42,     6,     0,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,    52,     0,     0,    40,    41,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       0,     8,     9,    52,    10,    11,    12,    13,    14,    15,
      16,    17,     0,    18,    19,    20,    21,    22,    23,    24,
       0,     0,  1099,    25,    26,    27,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,     0,    37,    38,     0,
       0,     0,     0,  1150,    39,    40,    41,    42,     0,     0,
       0,     0,    43,     0,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,   518,    11,    12,   519,
     520,    15,   521,    17,     0,    18,     0,    20,    21,     0,
      23,    24,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    36,     0,     0,
       0,     0,   292,     0,     0,     0,   437,    40,    41,    42,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,    52,     0,     0,     0,     0,
     292,     0,     0,     0,     0,     0,     0,   965,     0,   966,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,     0,     0,     0,   991,     0,   992,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,     0,     0,     0,  1059,     0,  1060,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,     0,     0,   278,   279,   280,   710,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,   278,   279,   280,   785,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,     0,   278,   279,
     280,   963,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,     0,     0,   278,   279,   280,   977,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,     0,
     278,   279,   280,  1071,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,     0,     0,   278,   279,   280,  1078,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,   278,   279,   280,  1079,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,     0,   278,   279,
     280,  1090,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,     0,     0,   278,   279,   280,  1093,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,     0,
     278,   279,   280,  1096,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,     0,     0,   278,   279,   280,  1104,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,   278,   279,   280,  1105,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,     0,   278,   279,
     280,  1116,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,     0,     0,   278,   279,   280,  1144,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,     0,
     278,   279,   280,  1146,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,     0,     0,   278,   279,   280,  1148,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,   278,   279,   280,  1158,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,     0,   278,   279,
     280,  1219,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,     0,     0,   278,   279,   280,  1222,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,   433,     0,   278,   279,
     280,   501,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,   462,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   278,   279,   280,   501,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
     278,   279,   280,   502,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,   278,   279,   280,   539,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,   587,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,   588,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   278,   279,   280,   601,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
     278,   279,   280,   602,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,   278,   279,   280,   603,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,   604,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,   605,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   278,   279,   280,   606,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
     278,   279,   280,   676,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,   278,   279,   280,   677,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,   678,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,   751,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   278,   279,   280,   783,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
     278,   279,   280,   784,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,   278,   279,   280,   813,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,   906,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,   907,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   278,   279,   280,   923,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
     278,   279,   280,   924,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,   278,   279,   280,   941,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,   947,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,  1035,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   278,   279,   280,  1036,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
     278,   279,   280,  1044,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,   278,   279,   280,  1047,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,  1048,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,  1056,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   278,   279,   280,  1057,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
     278,   279,   280,  1112,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,   278,   279,   280,  1114,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   278,   279,
     280,  1208,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   278,   279,   280,  1218,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,   278,   279,   280,   548,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,   278,   279,   280,   566,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,   278,   279,   280,   568,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,   278,   279,   280,   570,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,   278,   279,   280,
     572,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,   278,   279,
     280,   574,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,   278,
     279,   280,   576,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
     278,   279,   280,   578,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,   278,   279,   280,   580,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,   278,   279,   280,   582,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,   278,   279,   280,   584,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,   278,   279,   280,   586,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,   278,   279,   280,   590,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,   278,   279,   280,   592,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,   278,   279,   280,
     594,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,   278,   279,
     280,   596,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,   278,
     279,   280,   598,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
     278,   279,   280,   600,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,   278,   279,   280,   636,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,   278,   279,   280,   682,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,   278,   279,   280,   690,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,   278,   279,   280,   693,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,   278,   279,   280,   694,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,   278,   279,   280,   706,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,   278,   279,   280,
     830,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,   278,   279,
     280,   832,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,   278,
     279,   280,   834,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
     278,   279,   280,   836,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,   278,   279,   280,   837,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,   278,   279,   280,   938,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,   469,   278,   279,   280,     0,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,     0,   474,   278,   279,
     280,     0,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
     475,   278,   279,   280,     0,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,     0,   477,   278,   279,   280,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,   482,   278,   279,   280,
       0,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,     0,   483,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,   485,   278,   279,   280,     0,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,     0,   533,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,   534,   278,
     279,   280,     0,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
       0,   537,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,   543,   278,   279,   280,     0,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,     0,   565,   278,   279,
     280,     0,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
     567,   278,   279,   280,     0,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,     0,   569,   278,   279,   280,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,   571,   278,   279,   280,
       0,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,     0,   573,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,   575,   278,   279,   280,     0,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,     0,   577,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,   579,   278,
     279,   280,     0,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
       0,   581,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,   583,   278,   279,   280,     0,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,     0,   585,   278,   279,
     280,     0,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
     589,   278,   279,   280,     0,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,     0,   591,   278,   279,   280,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,   593,   278,   279,   280,
       0,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,     0,   595,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,   597,   278,   279,   280,     0,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,     0,   599,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,   648,   278,
     279,   280,     0,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
       0,   652,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,   659,   278,   279,   280,     0,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,     0,   660,   278,   279,
     280,     0,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
     664,   278,   279,   280,     0,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,     0,   698,   278,   279,   280,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,   705,   278,   279,   280,
       0,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,     0,   829,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,   831,   278,   279,   280,     0,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,     0,   833,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292,     0,   835,   278,
     279,   280,     0,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   292,
       0,   841,   278,   279,   280,     0,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   292,     0,   900,   278,   279,   280,     0,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   292,     0,   902,   278,   279,
     280,     0,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,   292,     0,
     910,   278,   279,   280,     0,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   292,     0,   929,   278,   279,   280,     0,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   292,     0,   964,   278,   279,   280,
       0,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   292,     0,   995,
     278,   279,   280,     0,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     292,     0,  1111,   278,   279,   280,     0,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,     0,  1157,   278,   279,   280,     0,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   292
};

static const short int yycheck[] =
{
       6,     4,     6,   339,     6,   179,     3,   271,   182,    67,
     269,     3,     6,     4,     4,     4,     4,    45,    86,     4,
       4,     4,    67,     5,   132,     6,     6,     6,   626,     7,
       5,   205,     4,   207,   134,     4,     6,     6,     6,   133,
     299,    68,   911,   912,   138,    41,    73,     6,    44,    53,
      54,     6,    34,    35,    36,    37,     6,     0,    40,    34,
      35,    36,    37,   132,   132,    40,     5,   121,   122,   132,
     139,   134,     7,    76,    77,    78,    79,    80,     7,     6,
       7,   139,    52,     6,    52,   139,   792,   132,    76,    77,
      78,    79,    80,   132,   139,    34,    35,    36,    37,   121,
     122,    40,   121,   122,   132,    49,   112,   113,   114,   132,
       4,   117,   118,   140,    68,   121,    68,   139,   132,    73,
     139,    73,   128,     4,   118,   139,   132,   133,   134,   107,
     108,   109,   110,  1002,   132,   141,   142,   140,   144,   118,
     121,   122,   148,   149,   742,   151,   129,   130,   139,   139,
     139,   134,   140,   136,   139,   139,   132,   139,   141,   139,
     132,   167,   168,   139,   139,   134,   121,   122,   132,   269,
     176,   121,   122,   437,   348,   110,   129,   130,   107,   108,
     109,   110,    45,   136,   190,   191,   140,   193,   140,   195,
     129,   130,   198,   199,   368,    89,    90,   136,    68,   299,
     129,   130,   461,    73,   210,   464,   132,   136,    89,    90,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    45,   851,   258,   259,   260,   261,    45,    68,
     133,    68,    68,   269,    73,   138,    73,    73,   132,   271,
     140,    47,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,     7,   121,   122,
     296,   297,     7,   299,   139,   301,    68,   129,   130,   132,
     306,    73,    27,    28,   310,    30,   139,   313,   121,   122,
     132,    68,   134,   319,   320,   321,    73,   323,   324,   325,
     326,   327,   328,   329,    68,   138,    45,   140,  1027,    73,
    1029,   140,  1031,   140,   140,   341,   342,   343,   344,   345,
     346,   338,   339,   349,    68,    68,   338,   339,   354,    73,
      73,   610,   358,   359,   133,    58,    59,  1063,   364,   138,
    1066,   461,    10,  1069,   464,    13,    14,   373,   140,   133,
     470,    68,   378,     5,   138,   381,    73,   139,   380,   133,
     639,   121,   122,   140,   138,     6,   133,   107,   108,   109,
     110,   138,   107,   108,   109,   110,    41,     6,   138,    44,
      45,  1100,    34,    35,    36,    37,     6,     7,    40,   129,
     130,   132,  1010,   134,   129,   130,   140,   140,    41,   121,
     122,    44,    45,  1129,    47,   684,   432,   686,   687,   688,
     327,   328,   329,   439,   438,   437,   138,     4,   140,   164,
     132,   166,   134,   140,  1143,     8,  1145,   172,  1147,   121,
     122,   176,  1151,     4,  1160,   461,   462,  1163,   464,     4,
    1166,   467,   132,  1169,   470,   132,   138,   473,   140,   132,
     734,   735,   478,   479,     6,   481,   121,   122,   484,   132,
    1179,   134,  1181,   489,  1183,    45,  1192,   132,  1194,   214,
    1196,     4,     5,     4,   139,   501,   502,   121,   122,   121,
     122,   132,   150,   134,   510,     4,   132,   155,   121,   122,
     610,   121,   122,   121,   122,   139,   138,   121,   122,   525,
     132,    34,    35,    36,    37,   138,   132,    40,   138,   132,
     138,   134,   180,   539,   138,   541,   542,   185,   186,   639,
      44,    45,   132,    47,   548,   132,   548,   134,   111,   112,
     113,   887,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   121,   122,     4,   121,   122,   131,     6,
     123,   124,   125,   121,   122,   121,   122,   140,   131,     6,
     138,   587,   588,   138,   684,   132,   686,   687,   688,     8,
     138,   132,   138,   134,     5,   601,   602,   603,   604,   605,
     606,   607,   121,   122,   610,   121,   122,   611,   614,   139,
       6,   336,   337,   619,   132,   132,   134,   134,    92,   138,
     345,    92,   138,   629,   129,   130,   132,    92,   632,   134,
     132,   136,   134,   639,   636,   132,   141,   134,   644,     3,
       4,     5,   132,   132,   134,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   139,
      34,    35,    36,    37,   132,   132,    40,   683,   684,   685,
     686,   687,   688,   139,   139,   691,   692,  1023,     8,   132,
     132,   697,   111,   112,   113,     4,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   713,   714,   132,
     132,   717,   131,   139,   133,   111,   112,   113,     6,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     132,   129,   130,   735,   139,   131,   134,   743,   136,   103,
     104,   105,   106,   141,   139,   751,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   134,   134,   121,   122,   132,
     131,   134,   768,   127,   132,   132,   134,   134,   132,    57,
     132,   134,   134,   137,   139,   500,   782,   783,   784,   132,
     132,   134,   134,   789,     6,   136,   434,   435,    92,     6,
     515,   111,   112,   113,   132,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     6,   813,   814,   815,
     132,   131,   134,   138,     6,   140,   822,   819,    45,   134,
      47,   827,     4,   111,   112,   113,   139,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   844,   843,
     134,     5,   136,   131,     4,   131,     6,    61,    62,    63,
      64,   855,    66,   121,   122,   123,   124,   125,  1032,   136,
      74,    75,     7,   131,     6,   134,    45,   873,   874,   129,
     130,   138,    47,   140,   134,     7,   136,   883,     7,   883,
     138,   141,   140,   138,   138,   140,   140,   138,   133,   140,
     887,   138,   138,   140,   140,   887,   138,   138,   140,   140,
     906,   907,   138,   138,   140,   140,   138,   138,   140,   140,
       6,    87,   918,   138,     7,   140,   641,   923,   924,   138,
     138,   140,   140,   138,     7,   140,    89,  1101,   139,   138,
     133,   133,   138,     6,     4,   941,   135,   133,     7,     7,
       7,   947,     7,     7,     7,     7,   133,   133,   133,   140,
     140,   676,   677,   678,     7,   136,   139,     7,   132,   965,
       7,   139,   132,   136,   132,   132,     6,   139,     4,   111,
     112,   113,   978,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,     6,   991,     6,   993,   135,   131,
       6,     6,   998,     7,   134,     6,   118,  1003,   646,   647,
       7,   649,     7,   139,     7,     7,   654,   655,     7,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
    1026,     7,  1028,     7,  1030,   131,  1023,     7,     7,  1035,
    1036,  1023,     7,     7,     7,  1041,     4,     6,   132,     6,
       6,  1047,  1048,     6,     4,     7,     7,   695,   696,     6,
    1056,   699,     4,  1059,   139,     6,   133,   133,   136,     7,
       6,   135,     6,     6,   789,     6,     6,   139,   139,     6,
       6,    88,     6,   139,     6,  1081,   136,     4,     6,   135,
       6,     6,     6,     6,     6,  1091,     6,     6,  1094,     6,
       6,  1097,   113,     6,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,     6,  1112,     6,  1114,     6,
     131,   759,     6,     6,     6,   763,     6,     6,    88,     7,
     139,   769,   770,   771,     4,     6,   774,   775,   776,   777,
     778,   779,   780,     6,   140,     7,   861,     6,   863,   136,
       6,     6,     6,   139,   139,   139,   139,   139,   138,     6,
     139,     6,  1156,    88,    85,   133,   139,    90,     6,     5,
     551,     6,   139,   888,   140,   890,   138,   892,   139,     6,
       6,     6,     6,     6,   138,   140,     6,     6,     6,     6,
    1186,     6,     6,  1187,     5,  1189,   139,     6,     6,   139,
     139,     6,     6,   140,   842,   140,   138,     6,    85,     6,
     139,  1207,  1208,     5,  1081,  1209,     6,     6,   138,     6,
     139,    85,  1218,     3,     4,     6,   750,     6,   139,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   139,     6,   140,     6,     6,   139,   897,
       6,    41,     6,   139,     6,   140,   139,     3,     3,   986,
      -1,   847,    -1,    -1,    -1,    -1,   914,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    66,   925,    -1,    -1,
      -1,   929,    -1,    -1,    74,    75,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,  1026,    -1,  1028,    -1,  1030,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,    -1,
      -1,    -1,   132,    -1,    -1,     3,     4,   137,    -1,    -1,
     140,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    -1,  1034,    -1,    -1,    -1,
      -1,    -1,  1040,    -1,    -1,    -1,  1044,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    -1,   111,   112,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,   103,   104,   105,   106,    -1,
      -1,    -1,    -1,    -1,  1102,    -1,    -1,    -1,  1106,  1107,
      -1,    -1,    -1,   121,   122,    -1,    -1,    -1,     6,   127,
      -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,   137,
      -1,   139,   111,   112,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
       3,     4,   131,    -1,    -1,  1153,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,    41,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,   133,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    75,   111,   112,   113,    -1,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,     6,
     103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
      -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,   132,
      -1,     3,     4,    -1,   137,    -1,   139,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,    41,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    61,
      62,    63,    64,    65,    66,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,   111,   112,   113,    -1,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
     132,    -1,     3,     4,    -1,   137,    -1,   139,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
      41,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      61,    62,    63,    64,    65,    66,   140,    -1,    -1,     3,
       4,    -1,    -1,    74,    75,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,     6,   103,   104,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      -1,   132,    -1,     3,     4,    -1,   137,    -1,   139,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,   132,    -1,
      -1,   135,    -1,   137,    -1,   139,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,    -1,
      -1,    -1,   132,    -1,    -1,   135,    -1,   137,    -1,   139,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
     103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
      -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,   135,    -1,   137,    -1,   139,   103,   104,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,   127,    -1,    -1,    -1,    -1,   132,   103,   104,   105,
     106,   137,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,   127,    -1,    -1,    -1,    -1,   132,    -1,     3,     4,
       5,   137,     7,   139,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     6,    34,
      35,    36,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,   121,   122,    -1,    74,
      75,    -1,   127,    -1,   129,   130,    -1,   132,    -1,   134,
      -1,   136,   137,   111,   112,   113,     6,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   103,   104,
     105,   106,    -1,   131,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,
      -1,    -1,   127,    -1,    -1,    -1,    -1,   132,     3,     4,
      -1,    -1,   137,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     6,    -1,
      -1,   111,   112,   113,    -1,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,     6,
      -1,   131,   111,   112,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,   103,   104,
     105,   106,   131,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,
       6,    -1,   127,    -1,    -1,    -1,    -1,   132,   103,   104,
     105,   106,   137,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,
      -1,    -1,   127,    -1,    -1,    -1,     8,   132,    -1,    -1,
      -1,    -1,   137,   111,   112,   113,    -1,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,     8,    -1,
      -1,    -1,    -1,   131,   111,   112,   113,    -1,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,     8,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,
     113,    -1,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,   111,   112,   113,   131,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,   111,   112,   113,   131,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,   111,
     112,   113,   131,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,   111,   112,   113,    -1,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     0,     1,    -1,    -1,
       4,   131,   111,   112,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    38,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    -1,
      74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    89,    -1,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      72,    52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,
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
      55,    56,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    72,    52,    53,
      -1,    55,    56,    -1,    -1,   140,    -1,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,    82,    83,
      84,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    -1,    52,    53,   100,    55,    56,   111,
     112,   113,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    72,   140,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    82,    83,    84,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,   100,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    -1,    52,    53,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    72,    52,    53,    -1,    55,    56,
      -1,    -1,   140,    -1,    82,    83,    84,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,   100,    -1,    -1,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    38,    39,   100,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,   140,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    -1,    74,    75,    -1,
      -1,    -1,    -1,   140,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    89,    -1,    91,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    -1,    52,    53,    -1,
      55,    56,   111,   112,   113,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    72,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,   135,    82,    83,    84,
     111,   112,   113,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   100,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,
     111,   112,   113,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,
     111,   112,   113,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,
     111,   112,   113,    -1,   115,   116,   117,   118,   119,   120,
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
      -1,    -1,    -1,    -1,   131,    -1,   133,    -1,   111,   112,
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
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,   111,   112,   113,   138,   115,   116,   117,   118,
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
      -1,    -1,    -1,   131,    -1,   133,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131
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
      98,    99,   100,   101,   102,   145,   147,   148,   167,   169,
     170,   173,   174,   175,   176,   177,   178,   179,   194,   195,
     196,     3,     4,     5,     7,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    34,
      35,    36,    37,    40,   103,   104,   105,   106,   107,   108,
     109,   110,   121,   122,   127,   129,   130,   132,   134,   136,
     137,   165,   166,   197,   198,   209,   132,     6,   139,     6,
       4,    41,   122,   132,   139,   170,   173,   179,   197,   203,
     204,   132,   132,    67,   132,   203,    67,   203,   132,   132,
      49,   132,    45,    45,    45,    44,    45,    47,    47,    41,
      44,    45,    47,   132,   139,   121,   122,   132,   139,   199,
     200,   199,   139,    41,    44,    45,   139,   199,     4,   139,
      45,     4,   139,     6,     6,    41,    44,     4,     4,     4,
     132,   132,    45,   132,     4,   139,   206,     4,   132,   132,
       6,     4,     4,    45,     5,   139,   209,   139,   209,     4,
     134,   136,   141,   166,     4,   139,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   132,
     132,   132,   132,     4,   197,   197,   197,   197,   135,   139,
     197,     4,    89,    90,     4,   197,     6,     6,   111,   112,
     113,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   131,     6,     5,   197,   134,   139,     4,   139,
     197,   122,   140,   197,   204,   205,     8,    92,   197,   197,
     132,   197,    92,   132,    92,   197,   197,   203,   197,   139,
     132,   132,   203,   139,   139,   132,   132,   132,   132,   132,
       4,   199,   199,   199,   197,   197,   121,   122,   139,   139,
     199,   139,   139,   139,   121,   122,   132,   199,   139,   134,
     172,   203,     4,     6,   134,   172,   203,   203,   134,   134,
       6,   197,   197,    86,   132,   197,   136,   197,   139,    92,
     197,   197,     6,   132,   172,     6,   172,     6,   134,   197,
       4,   139,   199,   149,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,     4,   209,   209,   209,
     209,     5,   134,   133,     7,   110,   205,   135,     7,   165,
     166,   136,     7,   134,     6,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     133,   138,   138,   135,   139,   197,   197,   134,   205,   133,
     138,   140,   197,    45,   133,   133,   197,   133,    45,    47,
     197,    47,   133,   133,     7,   133,   197,   197,   197,     7,
     197,   197,   197,   168,   197,   209,   168,   168,   168,   133,
     138,   138,   138,   199,   199,   170,   171,   172,   173,   171,
     138,   197,   197,   197,   197,   138,   172,   197,    41,    44,
      45,    47,   140,   169,     6,     7,     6,   197,   140,     7,
       7,   197,   197,   133,   133,    87,   197,   133,    89,   138,
     172,   139,     8,   133,   197,   140,   140,   197,   135,   166,
     197,   139,     4,    76,    77,    78,    79,    80,   140,   152,
     156,   159,   161,   162,   164,   133,   135,   133,   135,   133,
     135,   133,   135,   133,   135,   133,   135,   133,   135,   133,
     135,   133,   135,   133,   135,   133,   135,   138,   138,   133,
     135,   133,   135,   133,   135,   133,   135,   133,   135,   133,
     135,   138,   138,   138,   138,   138,   138,   134,   136,   133,
     138,   138,   133,   133,   138,   203,   203,   140,   136,   165,
     166,   209,   197,     6,     4,     4,   139,   207,   135,     8,
       6,   118,   146,   205,   197,   205,   135,   140,   135,   139,
     140,     7,   197,   204,     8,   197,     7,     7,   133,     7,
     197,   197,   133,   197,     7,     7,   197,     7,   140,   133,
     133,   197,   140,   140,   133,   133,   133,   133,   133,   136,
     199,   197,   197,   140,   140,   197,   138,   138,   138,   199,
     140,   180,   135,   132,   139,   132,   139,   139,   139,   197,
     135,   139,   139,   135,   135,     7,     7,   132,   133,     7,
     136,   197,   140,   197,   197,   133,   135,   136,   166,   209,
     140,   149,   153,   132,   132,   139,   163,   132,     6,   197,
     197,   197,   197,   197,   197,   197,   197,   197,     4,   205,
     209,   197,     6,     6,   135,     4,    89,    90,   197,     6,
       6,     6,     7,   134,   206,   208,     6,   197,   118,   209,
     133,   138,   140,   205,   199,   197,     6,   203,   203,     7,
     203,     6,     6,     7,     6,   203,   203,     6,   139,     7,
       7,     7,     6,    57,     7,     7,     7,     7,     7,     7,
       7,     4,   138,   138,   138,   140,   199,   199,   199,   138,
      68,    73,   192,   193,     6,   197,   205,   197,   205,   205,
     205,     6,     6,   197,   197,     6,     6,   203,   203,   197,
       7,   203,     4,   138,     8,     8,   133,     7,     6,     4,
       6,   140,   132,   197,   197,   202,   203,   139,   197,   133,
     135,   133,   135,   133,   135,   133,   135,   135,   133,   133,
     133,   133,   165,     7,   165,   166,   136,     7,     6,   206,
     197,   138,   140,     6,     6,   146,   197,   135,   140,     6,
       6,    52,     6,    52,   203,     6,   203,     6,     6,   197,
     203,   203,   203,    58,    59,   203,   203,   203,   203,   203,
     203,   203,     6,     7,   197,   197,   197,   139,   138,   140,
     138,   140,   138,   140,   197,   199,     6,   139,   140,   193,
     133,   140,   133,   140,   140,   140,   138,   138,     6,     6,
     133,   132,   139,   201,    88,   197,   197,   197,   139,   166,
       6,   150,   197,   138,   138,   138,   140,   151,   197,   133,
     136,   203,   209,   197,     6,     4,   207,     6,   135,   206,
     209,   138,   135,   199,   199,     6,     6,   138,     6,     6,
       6,   197,   197,     4,     6,     6,     6,     6,     6,     6,
       6,   197,   209,   140,   133,   138,   140,   171,   199,     6,
     183,   199,     6,   184,   199,     6,   185,   140,   138,   203,
       6,     6,     6,     6,   197,   197,     7,   202,   202,    88,
     203,   138,   140,     8,   140,   133,   197,   133,   138,   197,
     197,   203,   139,   138,   140,   203,     4,     6,     6,     6,
       7,     6,   136,     6,   197,     6,     6,   197,     6,     6,
       6,     6,     6,   139,   197,   140,   138,   139,   138,   139,
     138,   139,   139,   197,   138,   138,   138,   201,   133,   140,
     139,    85,   197,   197,   138,   154,   197,   138,   138,   202,
     197,     6,     6,   133,   206,    90,   138,   138,   171,   138,
     140,   197,   199,   192,   197,   199,   192,   197,   199,   192,
     172,   140,   203,   197,   197,    88,   203,   197,   140,   140,
     203,   139,   197,   197,   140,     6,   197,     5,   140,   197,
     140,   138,   140,   140,   138,   140,   140,   138,   140,   140,
     181,   139,   138,   140,   140,   140,   139,   138,     6,   140,
     151,   133,   138,     6,   138,   138,   140,     6,   186,   197,
       6,     6,   187,   197,     6,     6,   188,   197,     6,   192,
     172,   203,     6,     6,     6,   203,   203,     6,   140,   157,
     197,   197,     5,   139,   140,   139,   140,   139,   140,   140,
     140,   182,   140,   138,   140,     6,   139,   133,   140,   138,
     192,     6,   189,   192,     6,   190,   192,     6,   191,   192,
       6,   203,    85,   155,   209,   160,     6,     5,   140,   139,
     140,   139,   140,   139,   140,   140,   139,   138,   140,   139,
     140,     6,   192,     6,   192,     6,   192,    85,   197,   209,
       6,   158,   209,     6,   140,   140,   140,   139,   138,   138,
     140,     6,     6,     6,   197,   197,   209,     6,   138,   140,
     197,     6,   140,     6
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
#line 1011 "Gmsh.y"
    { 
      (yyval.i) = (yyvsp[0].d); 
    ;}
    break;

  case 82:
#line 1015 "Gmsh.y"
    { 
      (yyval.i) = GMODEL->setPhysicalName(std::string((yyvsp[0].c)), ++THEM->MaxPhysicalNum);
      Free((yyvsp[0].c));
    ;}
    break;

  case 83:
#line 1026 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindPoint(num)){
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

  case 84:
#line 1042 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT)){
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

  case 85:
#line 1058 "Gmsh.y"
    {
      yymsg(GERROR, "Attractors are deprecated");
      List_Delete((yyvsp[-9].l));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 86:
#line 1065 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
	double d;
	List_Read((yyvsp[-3].l), i, &d);
	Vertex *v = FindPoint((int)d);
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

  case 87:
#line 1084 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 88:
#line 1102 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	Curve *c = Create_Curve(num, MSH_SEGM_SPLN, 3, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_SPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 89:
#line 1120 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    ;}
    break;

  case 90:
#line 1138 "Gmsh.y"
    {
      int num = (int)(yyvsp[-6].d);
      if(FindCurve(num)){
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
	Curve *rc = CreateReversedCurve(c);
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

  case 91:
#line 1164 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    ;}
    break;

  case 92:
#line 1182 "Gmsh.y"
    {
      int num = (int)(yyvsp[-6].d);
      if(FindCurve(num)){
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
	Curve *rc = CreateReversedCurve(c);
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

  case 93:
#line 1209 "Gmsh.y"
    {
      int num = (int)(yyvsp[-14].d);
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	Curve *c = Create_Curve(num, MSH_SEGM_PARAMETRIC, 2, NULL, NULL,
				-1, -1, (yyvsp[-10].d), (yyvsp[-8].d));
	strcpy(c->functu, (yyvsp[-6].c));
	strcpy(c->functv, (yyvsp[-4].c));
	strcpy(c->functw, (yyvsp[-2].c));
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(c);
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
      (yyval.s).Type = MSH_SEGM_PARAMETRIC;
      (yyval.s).Num = num;
    ;}
    break;

  case 94:
#line 1228 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(List_Nbr((yyvsp[-1].l)) < 4){
	yymsg(GERROR, "Too few control points for BSpline %d (%d < 4)", num,
	      List_Nbr((yyvsp[-1].l)));
      }
      else{
	if(FindCurve(num)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	  Curve *c = Create_Curve(num, MSH_SEGM_BSPLN, 2, temp, NULL,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(c);
	  List_Delete(temp);
	}
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 95:
#line 1252 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(List_Nbr((yyvsp[-1].l)) < 4){
	yymsg(GERROR, "Too few control points for Bezier curve %d (%d < 4)", num,
	      List_Nbr((yyvsp[-1].l)));
      }
      else{
	if(FindCurve(num)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	  Curve *c = Create_Curve(num, MSH_SEGM_BEZIER, 2, temp, NULL,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(c);
	  List_Delete(temp);
	}
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_BEZIER;
      (yyval.s).Num = num;
    ;}
    break;

  case 96:
#line 1276 "Gmsh.y"
    {
      int num = (int)(yyvsp[-8].d);
      if(List_Nbr((yyvsp[-5].l)) + (int)(yyvsp[-1].d) + 1 != List_Nbr((yyvsp[-3].l))){
	yymsg(GERROR, "Wrong definition of Nurbs Curve %d: "
	      "got %d knots, need N + D + 1 = %d + %d + 1 = %d",
	      (int)(yyvsp[-8].d), List_Nbr((yyvsp[-3].l)), List_Nbr((yyvsp[-5].l)), (int)(yyvsp[-1].d), List_Nbr((yyvsp[-5].l)) + (int)(yyvsp[-1].d) + 1);
      }
      else{
	if(FindCurve(num)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[-5].l));
	  Curve *c = Create_Curve(num, MSH_SEGM_NURBS, (int)(yyvsp[-1].d), temp, (yyvsp[-3].l),
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(c);
	  List_Delete(temp);
	}
      }
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-3].l));
      (yyval.s).Type = MSH_SEGM_NURBS;
      (yyval.s).Num = num;
    ;}
    break;

  case 97:
#line 1302 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindEdgeLoop(num)){
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

  case 98:
#line 1319 "Gmsh.y"
    {
      yymsg(GERROR, "Attractors are deprecated");
      List_Delete((yyvsp[-9].l));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 99:
#line 1326 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE)){
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

  case 100:
#line 1345 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindSurface(num)){
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

  case 101:
#line 1364 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d), type = 0;
      if(FindSurface(num)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	double d;
	List_Read((yyvsp[-1].l), 0, &d);
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

  case 102:
#line 1403 "Gmsh.y"
    {
      int num = (int)(yyvsp[-8].d);
      Surface *support = FindSurface((int)(yyvsp[-4].d));
      if(!support){
	yymsg(GERROR, "Unknown support surface %d", (int)(yyvsp[-4].d));
      }
      else{
	if(FindSurface(num)){
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

  case 103:
#line 1430 "Gmsh.y"
    {
      int num = (int)(yyvsp[-16].d);
      if(FindSurface(num)){
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

  case 104:
#line 1449 "Gmsh.y"
    {
      int num = (int)(yyvsp[-16].d);
      if(FindSurface(num)){
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

  case 105:
#line 1466 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindSurfaceLoop(num)){
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

  case 106:
#line 1482 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
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

  case 107:
#line 1502 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindVolume(num)){
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

  case 108:
#line 1519 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      if(FindVolume(num)){
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

  case 109:
#line 1536 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME)){
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

  case 110:
#line 1557 "Gmsh.y"
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 111:
#line 1562 "Gmsh.y"
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 112:
#line 1567 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 113:
#line 1572 "Gmsh.y"
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 114:
#line 1579 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); ;}
    break;

  case 115:
#line 1580 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); ;}
    break;

  case 116:
#line 1581 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); ;}
    break;

  case 117:
#line 1586 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 118:
#line 1590 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    ;}
    break;

  case 119:
#line 1594 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	double d;
	List_Read((yyvsp[-2].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Vertex *v = FindPoint(TheShape.Num);
	if(!v)
	  yymsg(WARNING, "Unknown point %d", TheShape.Num);
	else{
	  TheShape.Type = MSH_POINT;
	  List_Add((yyval.l), &TheShape);
	}
      }
    ;}
    break;

  case 120:
#line 1610 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	double d;
	List_Read((yyvsp[-2].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Curve *c = FindCurve(TheShape.Num);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	else{
	  TheShape.Type = c->Typ;
	  List_Add((yyval.l), &TheShape);
	}
      }
    ;}
    break;

  case 121:
#line 1626 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	double d;
	List_Read((yyvsp[-2].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Surface *s = FindSurface(TheShape.Num);
	if(!s)
	  yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	else{
	  TheShape.Type = s->Typ;
	  List_Add((yyval.l), &TheShape);
	}
      }
    ;}
    break;

  case 122:
#line 1642 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	double d;
	List_Read((yyvsp[-2].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Volume *v = FindVolume(TheShape.Num);
	if(!v)
	  yymsg(WARNING, "Unknown volume %d", TheShape.Num);
	else{
	  TheShape.Type = v->Typ;
	  List_Add((yyval.l), &TheShape);
	}
      }
    ;}
    break;

  case 123:
#line 1663 "Gmsh.y"
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

  case 124:
#line 1677 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "View")) AliasView((int)(yyvsp[-2].d), 0);
      Free((yyvsp[-4].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 125:
#line 1683 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "View")) AliasView((int)(yyvsp[-2].d), 0);
      Free((yyvsp[-4].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 126:
#line 1689 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "View")) AliasView((int)(yyvsp[-2].d), 1);
      Free((yyvsp[-4].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 127:
#line 1701 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 128:
#line 1710 "Gmsh.y"
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

  case 129:
#line 1720 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-1].c), "Meshes") || !strcmp((yyvsp[-1].c), "All")){
	GMODEL->destroy();
	THEM->destroy();
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

  case 130:
#line 1735 "Gmsh.y"
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

  case 131:
#line 1754 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u));
      }
      List_Delete((yyvsp[-1].l));      
    ;}
    break;

  case 132:
#line 1768 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1);
      Free((yyvsp[-1].c));
    ;}
    break;

  case 133:
#line 1774 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0);
      Free((yyvsp[-1].c));
    ;}
    break;

  case 134:
#line 1780 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 135:
#line 1789 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 136:
#line 1803 "Gmsh.y"
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

  case 137:
#line 1848 "Gmsh.y"
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

  case 138:
#line 1863 "Gmsh.y"
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

  case 139:
#line 1874 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-2].c), "Sleep")){
	SleepInSeconds((yyvsp[-1].d));
      }
      else if(!strcmp((yyvsp[-2].c), "Remesh")){
	Msg(GERROR, "Surface ReMeshing must be reinterfaced");
	//	ReMesh();
      }
      else if(!strcmp((yyvsp[-2].c), "Mesh")){
	yymsg(GERROR, "Mesh directives are not (yet) allowed in scripts");
      }
      else if(!strcmp((yyvsp[-2].c), "Status")){
	yymsg(GERROR, "Mesh directives are not (yet) allowed in scripts");
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[-2].c));
      }
      Free((yyvsp[-2].c));
    ;}
    break;

  case 140:
#line 1894 "Gmsh.y"
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

  case 141:
#line 1904 "Gmsh.y"
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

  case 142:
#line 1926 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 143:
#line 1930 "Gmsh.y"
    {
      CTX.forced_bbox = 0;
      SetBoundingBox();
    ;}
    break;

  case 144:
#line 1935 "Gmsh.y"
    {
      CTX.forced_bbox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    ;}
    break;

  case 145:
#line 1940 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      Draw();
#endif
    ;}
    break;

  case 146:
#line 1952 "Gmsh.y"
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

  case 147:
#line 1967 "Gmsh.y"
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

  case 148:
#line 1983 "Gmsh.y"
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

  case 149:
#line 2009 "Gmsh.y"
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

  case 150:
#line 2036 "Gmsh.y"
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

  case 151:
#line 2068 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction((yyvsp[0].c), yyin, yyname, yylineno))
	yymsg(GERROR, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 152:
#line 2075 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin, yyname, yylineno))
	yymsg(GERROR, "Error while exiting function");
    ;}
    break;

  case 153:
#line 2080 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction((yyvsp[-1].c), &yyin, yyname, yylineno))
	yymsg(GERROR, "Unknown function %s", (yyvsp[-1].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 154:
#line 2086 "Gmsh.y"
    {
      if(!(yyvsp[-1].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 155:
#line 2090 "Gmsh.y"
    {
    ;}
    break;

  case 156:
#line 2099 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l), 
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 157:
#line 2107 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l), 
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 158:
#line 2115 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l), 
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 159:
#line 2123 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 160:
#line 2128 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l), 
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 161:
#line 2136 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 162:
#line 2141 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l), 
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 163:
#line 2149 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 164:
#line 2154 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l), 
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 165:
#line 2164 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d), 
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 166:
#line 2171 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d), 
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 167:
#line 2178 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d), 
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 168:
#line 2185 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d), 
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 169:
#line 2192 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d), 
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 170:
#line 2199 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d), 
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 171:
#line 2206 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d), 
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 172:
#line 2213 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d), 
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 173:
#line 2220 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d), 
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 174:
#line 2227 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 175:
#line 2232 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d), 
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 176:
#line 2239 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 177:
#line 2244 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d), 
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 178:
#line 2251 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 179:
#line 2256 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d), 
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 180:
#line 2263 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 181:
#line 2268 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d), 
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 182:
#line 2275 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 183:
#line 2280 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d), 
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 184:
#line 2287 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 185:
#line 2292 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d), 
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 186:
#line 2299 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 187:
#line 2304 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d), 
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 188:
#line 2311 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 189:
#line 2316 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d), 
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 190:
#line 2323 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 191:
#line 2328 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d), 
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 192:
#line 2339 "Gmsh.y"
    {
    ;}
    break;

  case 193:
#line 2342 "Gmsh.y"
    {
    ;}
    break;

  case 194:
#line 2348 "Gmsh.y"
    {
      yymsg(WARNING, "Explicit region numbers in layers are deprecated");
      double d;
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[-6].l));
      if(List_Nbr((yyvsp[-6].l)) == List_Nbr((yyvsp[-4].l)) && List_Nbr((yyvsp[-6].l)) == List_Nbr((yyvsp[-2].l))){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr((yyvsp[-6].l)); i++){
	  List_Read((yyvsp[-6].l), i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read((yyvsp[-2].l), i, &d);
	  extr.mesh.hLayer.push_back(d);
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

  case 195:
#line 2372 "Gmsh.y"
    {
      double d;
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[-4].l));
      if(List_Nbr((yyvsp[-4].l)) == List_Nbr((yyvsp[-2].l))){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	  List_Read((yyvsp[-4].l), i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read((yyvsp[-2].l), i, &d);
	  extr.mesh.hLayer.push_back(d);
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

  case 196:
#line 2394 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 197:
#line 2403 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
	double d;
	List_Read((yyvsp[-3].l), i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j);
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

  case 198:
#line 2421 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-6].l)); i++){
	double d;
	List_Read((yyvsp[-6].l), i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j);
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

  case 199:
#line 2439 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-6].l)); i++){
	double d;
	List_Read((yyvsp[-6].l), i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j);
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

  case 200:
#line 2457 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[-4].d));
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
	    Vertex *v = FindPoint(j);
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
#line 2486 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[-5].d));
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
	    Vertex *v = FindPoint(j);
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

  case 202:
#line 2521 "Gmsh.y"
    {
      yymsg(GERROR, "Elliptic Surface is deprecated: use smoothed Transfinite instead");
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 203:
#line 2526 "Gmsh.y"
    {
      Volume *v = FindVolume((int)(yyvsp[-4].d));
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
	    Vertex *vert = FindPoint(j);
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

  case 204:
#line 2553 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
	double d;
	List_Read((yyvsp[-3].l), i, &d);
	int j = (int)d;
	Surface *s = FindSurface(j);
	if(s){
	  s->Recombine = 1;
	  s->RecombineAngle = ((yyvsp[-1].d) > 0 && (yyvsp[-1].d) < 90) ? (yyvsp[-1].d) : 90;
	}
      }
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 205:
#line 2567 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	double d;
	List_Read((yyvsp[-1].l), i, &d);
	int j = (int)d;
        Surface *s = FindSurface(j);
	if(s){
	  s->Recombine = 1;
        }
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 206:
#line 2586 "Gmsh.y"
    { 
      Surface *s = FindSurface((int)(yyvsp[-1].d));
      if(s)
	setSurfaceEmbeddedPoints(s, (yyvsp[-4].l));
    ;}
    break;

  case 207:
#line 2592 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[-1].d));
      if(s)
	setSurfaceEmbeddedCurves(s, (yyvsp[-4].l));
    ;}
    break;

  case 208:
#line 2598 "Gmsh.y"
    {
    ;}
    break;

  case 209:
#line 2601 "Gmsh.y"
    {
    ;}
    break;

  case 210:
#line 2608 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 211:
#line 2612 "Gmsh.y"
    { 
      yymsg(GERROR, "Intersect is deprecated");
    ;}
    break;

  case 212:
#line 2621 "Gmsh.y"
    { (yyval.d) = (yyvsp[0].d);           ;}
    break;

  case 213:
#line 2622 "Gmsh.y"
    { (yyval.d) = (yyvsp[-1].d);           ;}
    break;

  case 214:
#line 2623 "Gmsh.y"
    { (yyval.d) = -(yyvsp[0].d);          ;}
    break;

  case 215:
#line 2624 "Gmsh.y"
    { (yyval.d) = (yyvsp[0].d);           ;}
    break;

  case 216:
#line 2625 "Gmsh.y"
    { (yyval.d) = !(yyvsp[0].d);          ;}
    break;

  case 217:
#line 2626 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      ;}
    break;

  case 218:
#line 2627 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      ;}
    break;

  case 219:
#line 2628 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      ;}
    break;

  case 220:
#line 2630 "Gmsh.y"
    { 
      if(!(yyvsp[0].d))
	yymsg(GERROR, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);     
    ;}
    break;

  case 221:
#line 2636 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  ;}
    break;

  case 222:
#line 2637 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  ;}
    break;

  case 223:
#line 2638 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      ;}
    break;

  case 224:
#line 2639 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      ;}
    break;

  case 225:
#line 2640 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     ;}
    break;

  case 226:
#line 2641 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     ;}
    break;

  case 227:
#line 2642 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     ;}
    break;

  case 228:
#line 2643 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     ;}
    break;

  case 229:
#line 2644 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     ;}
    break;

  case 230:
#line 2645 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     ;}
    break;

  case 231:
#line 2646 "Gmsh.y"
    { (yyval.d) = (yyvsp[-4].d)? (yyvsp[-2].d) : (yyvsp[0].d);  ;}
    break;

  case 232:
#line 2647 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[-1].d));      ;}
    break;

  case 233:
#line 2648 "Gmsh.y"
    { (yyval.d) = log((yyvsp[-1].d));      ;}
    break;

  case 234:
#line 2649 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[-1].d));    ;}
    break;

  case 235:
#line 2650 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-1].d));     ;}
    break;

  case 236:
#line 2651 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[-1].d));      ;}
    break;

  case 237:
#line 2652 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[-1].d));     ;}
    break;

  case 238:
#line 2653 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[-1].d));      ;}
    break;

  case 239:
#line 2654 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[-1].d));     ;}
    break;

  case 240:
#line 2655 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[-1].d));      ;}
    break;

  case 241:
#line 2656 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[-1].d));     ;}
    break;

  case 242:
#line 2657 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));;}
    break;

  case 243:
#line 2658 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[-1].d));     ;}
    break;

  case 244:
#line 2659 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[-1].d));     ;}
    break;

  case 245:
#line 2660 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[-1].d));     ;}
    break;

  case 246:
#line 2661 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[-1].d));     ;}
    break;

  case 247:
#line 2662 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[-1].d));    ;}
    break;

  case 248:
#line 2663 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[-1].d));     ;}
    break;

  case 249:
#line 2664 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 250:
#line 2665 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 251:
#line 2666 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-3].d)*(yyvsp[-3].d)+(yyvsp[-1].d)*(yyvsp[-1].d)); ;}
    break;

  case 252:
#line 2667 "Gmsh.y"
    { (yyval.d) = (yyvsp[-1].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 253:
#line 2669 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[-1].d));      ;}
    break;

  case 254:
#line 2670 "Gmsh.y"
    { (yyval.d) = log((yyvsp[-1].d));      ;}
    break;

  case 255:
#line 2671 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[-1].d));    ;}
    break;

  case 256:
#line 2672 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-1].d));     ;}
    break;

  case 257:
#line 2673 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[-1].d));      ;}
    break;

  case 258:
#line 2674 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[-1].d));     ;}
    break;

  case 259:
#line 2675 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[-1].d));      ;}
    break;

  case 260:
#line 2676 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[-1].d));     ;}
    break;

  case 261:
#line 2677 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[-1].d));      ;}
    break;

  case 262:
#line 2678 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[-1].d));     ;}
    break;

  case 263:
#line 2679 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));;}
    break;

  case 264:
#line 2680 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[-1].d));     ;}
    break;

  case 265:
#line 2681 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[-1].d));     ;}
    break;

  case 266:
#line 2682 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[-1].d));     ;}
    break;

  case 267:
#line 2683 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[-1].d));     ;}
    break;

  case 268:
#line 2684 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[-1].d));    ;}
    break;

  case 269:
#line 2685 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[-1].d));     ;}
    break;

  case 270:
#line 2686 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 271:
#line 2687 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 272:
#line 2688 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-3].d)*(yyvsp[-3].d)+(yyvsp[-1].d)*(yyvsp[-1].d)); ;}
    break;

  case 273:
#line 2689 "Gmsh.y"
    { (yyval.d) = (yyvsp[-1].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 274:
#line 2698 "Gmsh.y"
    { (yyval.d) = (yyvsp[0].d); ;}
    break;

  case 275:
#line 2699 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 276:
#line 2700 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->rank(); ;}
    break;

  case 277:
#line 2701 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->size(); ;}
    break;

  case 278:
#line 2702 "Gmsh.y"
    { (yyval.d) = Get_GmshMajorVersion(); ;}
    break;

  case 279:
#line 2703 "Gmsh.y"
    { (yyval.d) = Get_GmshMinorVersion(); ;}
    break;

  case 280:
#line 2704 "Gmsh.y"
    { (yyval.d) = Get_GmshPatchVersion(); ;}
    break;

  case 281:
#line 2709 "Gmsh.y"
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

  case 282:
#line 2725 "Gmsh.y"
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

  case 283:
#line 2740 "Gmsh.y"
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

  case 284:
#line 2760 "Gmsh.y"
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

  case 285:
#line 2774 "Gmsh.y"
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

  case 286:
#line 2787 "Gmsh.y"
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

  case 287:
#line 2810 "Gmsh.y"
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

  case 288:
#line 2828 "Gmsh.y"
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

  case 289:
#line 2846 "Gmsh.y"
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

  case 290:
#line 2864 "Gmsh.y"
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

  case 291:
#line 2882 "Gmsh.y"
    { 
      (yyval.d) = GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    ;}
    break;

  case 292:
#line 2890 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    ;}
    break;

  case 293:
#line 2894 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    ;}
    break;

  case 294:
#line 2898 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    ;}
    break;

  case 295:
#line 2902 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    ;}
    break;

  case 296:
#line 2906 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    ;}
    break;

  case 297:
#line 2913 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    ;}
    break;

  case 298:
#line 2917 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 299:
#line 2921 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 300:
#line 2925 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 301:
#line 2932 "Gmsh.y"
    {
    ;}
    break;

  case 302:
#line 2935 "Gmsh.y"
    {
       (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 303:
#line 2939 "Gmsh.y"
    {
       (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 304:
#line 2946 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    ;}
    break;

  case 305:
#line 2951 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    ;}
    break;

  case 306:
#line 2959 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    ;}
    break;

  case 307:
#line 2964 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[0].l);
    ;}
    break;

  case 308:
#line 2968 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 309:
#line 2973 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 310:
#line 2977 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
      double *pd;
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 311:
#line 2989 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d)); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 312:
#line 2995 "Gmsh.y"
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

  case 313:
#line 3006 "Gmsh.y"
    {
      // Returns the coordinates of a point and fills a list with it.
      // This allows to ensure e.g. that relative point positions are
      // always conserved
      Vertex *v = FindPoint((int)(yyvsp[-1].d));
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

  case 314:
#line 3026 "Gmsh.y"
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
#line 3036 "Gmsh.y"
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

  case 316:
#line 3046 "Gmsh.y"
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

  case 317:
#line 3056 "Gmsh.y"
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

  case 318:
#line 3073 "Gmsh.y"
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

  case 319:
#line 3092 "Gmsh.y"
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

  case 320:
#line 3116 "Gmsh.y"
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

  case 321:
#line 3145 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    ;}
    break;

  case 322:
#line 3150 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[0].l);
    ;}
    break;

  case 323:
#line 3154 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    ;}
    break;

  case 324:
#line 3158 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    ;}
    break;

  case 325:
#line 3171 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    ;}
    break;

  case 326:
#line 3175 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    ;}
    break;

  case 327:
#line 3187 "Gmsh.y"
    {
      int flag;
      (yyval.u) = Get_ColorForString(ColorString, -1, (yyvsp[0].c), &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    ;}
    break;

  case 328:
#line 3194 "Gmsh.y"
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

  case 329:
#line 3216 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 330:
#line 3220 "Gmsh.y"
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

  case 331:
#line 3235 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    ;}
    break;

  case 332:
#line 3240 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    ;}
    break;

  case 333:
#line 3247 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[0].c);
    ;}
    break;

  case 334:
#line 3251 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32*sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 335:
#line 3259 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-3].c))+strlen((yyvsp[-1].c))+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-3].c));
      strcat((yyval.c), (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    ;}
    break;

  case 336:
#line 3267 "Gmsh.y"
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

  case 337:
#line 3281 "Gmsh.y"
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

  case 338:
#line 3295 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[-1].c);
    ;}
    break;

  case 339:
#line 3299 "Gmsh.y"
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

  case 340:
#line 3318 "Gmsh.y"
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

  case 341:
#line 3340 "Gmsh.y"
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
#line 7426 "Gmsh.tab.cpp"

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


#line 3363 "Gmsh.y"


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

