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

// $Id: Gmsh.tab.cpp,v 1.262 2006-03-15 08:29:06 remacle Exp $
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
#include "Visibility.h"
#include "GmshVersion.h"

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
#line 78 "Gmsh.y"
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
#line 405 "Gmsh.tab.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 213 of yacc.c.  */
#line 417 "Gmsh.tab.cpp"

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
#define YYLAST   6086

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  141
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  65
/* YYNRULES -- Number of rules. */
#define YYNRULES  329
/* YYNRULES -- Number of states. */
#define YYNSTATES  1185

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
       2,     2,     2,   139,     2,   140,     2,     2,     2,     2,
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
      40,    46,    54,    61,    70,    71,    74,    77,    80,    83,
      86,    89,    91,    95,    97,   101,   102,   103,   114,   116,
     120,   121,   135,   137,   141,   142,   158,   167,   168,   175,
     182,   184,   186,   188,   190,   192,   194,   196,   201,   209,
     219,   226,   233,   237,   244,   251,   261,   268,   278,   284,
     293,   302,   314,   321,   331,   341,   351,   359,   368,   381,
     388,   396,   404,   412,   422,   430,   440,   458,   466,   474,
     486,   495,   508,   517,   526,   535,   548,   571,   592,   601,
     610,   619,   627,   636,   642,   654,   660,   670,   672,   674,
     676,   677,   680,   687,   694,   701,   708,   713,   720,   727,
     734,   739,   746,   750,   755,   761,   765,   769,   774,   779,
     783,   791,   799,   803,   811,   815,   818,   821,   837,   840,
     847,   856,   865,   876,   878,   881,   883,   887,   892,   894,
     900,   912,   926,   927,   935,   936,   950,   951,   967,   976,
     985,   994,  1007,  1020,  1033,  1048,  1063,  1078,  1079,  1092,
    1093,  1106,  1107,  1120,  1121,  1138,  1139,  1156,  1157,  1174,
    1175,  1194,  1195,  1214,  1215,  1234,  1236,  1239,  1249,  1257,
    1260,  1267,  1277,  1287,  1296,  1306,  1315,  1324,  1331,  1336,
    1339,  1342,  1344,  1348,  1351,  1354,  1357,  1361,  1365,  1369,
    1373,  1377,  1381,  1385,  1389,  1393,  1397,  1401,  1405,  1409,
    1413,  1419,  1424,  1429,  1434,  1439,  1444,  1449,  1454,  1459,
    1464,  1469,  1476,  1481,  1486,  1491,  1496,  1501,  1506,  1513,
    1520,  1527,  1532,  1537,  1542,  1547,  1552,  1557,  1562,  1567,
    1572,  1577,  1582,  1589,  1594,  1599,  1604,  1609,  1614,  1619,
    1626,  1633,  1640,  1645,  1647,  1649,  1651,  1653,  1655,  1657,
    1659,  1661,  1666,  1671,  1674,  1680,  1684,  1691,  1696,  1704,
    1711,  1713,  1716,  1719,  1723,  1727,  1739,  1749,  1757,  1765,
    1766,  1770,  1774,  1776,  1780,  1782,  1784,  1787,  1791,  1796,
    1800,  1806,  1811,  1813,  1815,  1817,  1821,  1826,  1833,  1841,
    1843,  1845,  1849,  1853,  1863,  1871,  1873,  1879,  1883,  1890,
    1892,  1896,  1898,  1900,  1907,  1912,  1917,  1922,  1929,  1936
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     142,     0,    -1,   143,    -1,     1,     6,    -1,    -1,   143,
     144,    -1,   146,    -1,   145,    -1,   165,    -1,   166,    -1,
     167,    -1,   170,    -1,   171,    -1,   172,    -1,   173,    -1,
     176,    -1,   191,    -1,   192,    -1,   175,    -1,   174,    -1,
      33,   132,     5,   133,     6,    -1,    33,   132,     5,   138,
     201,   133,     6,    -1,     4,     5,   139,   147,   140,     6,
      -1,     4,     5,     4,   195,   139,   147,   140,     6,    -1,
      -1,   147,   150,    -1,   147,   154,    -1,   147,   157,    -1,
     147,   159,    -1,   147,   160,    -1,   147,   162,    -1,   193,
      -1,   148,   138,   193,    -1,   193,    -1,   149,   138,   193,
      -1,    -1,    -1,     4,   151,   132,   148,   133,   152,   139,
     149,   140,     6,    -1,   205,    -1,   153,   138,   205,    -1,
      -1,    76,   132,   193,   138,   193,   138,   193,   133,   155,
     139,   153,   140,     6,    -1,   205,    -1,   156,   138,   205,
      -1,    -1,    77,   132,   193,   138,   193,   138,   193,   138,
     193,   133,   158,   139,   156,   140,     6,    -1,    78,   139,
     198,   140,   139,   198,   140,     6,    -1,    -1,    79,   161,
     139,   149,   140,     6,    -1,    80,   132,   193,   133,   199,
       6,    -1,     7,    -1,   110,    -1,   109,    -1,   108,    -1,
     107,    -1,   130,    -1,   129,    -1,     4,   163,   193,     6,
      -1,     4,   134,   193,   135,   163,   193,     6,    -1,     4,
     134,   139,   201,   140,   135,   163,   199,     6,    -1,     4,
     134,   135,     7,   199,     6,    -1,     4,   134,   135,   110,
     199,     6,    -1,     4,   164,     6,    -1,     4,   134,   193,
     135,   164,     6,    -1,     4,   136,     4,     7,   205,     6,
      -1,     4,   134,   193,   135,   136,     4,     7,   205,     6,
      -1,     4,   136,     4,   163,   193,     6,    -1,     4,   134,
     193,   135,   136,     4,   163,   193,     6,    -1,     4,   136,
       4,   164,     6,    -1,     4,   134,   193,   135,   136,     4,
     164,     6,    -1,     4,   136,    89,   136,     4,     7,   202,
       6,    -1,     4,   134,   193,   135,   136,    89,   136,     4,
       7,   202,     6,    -1,     4,   136,    90,     7,   203,     6,
      -1,     4,   134,   193,   135,   136,    90,     7,   203,     6,
      -1,    60,   132,     4,   133,   136,     4,     7,   193,     6,
      -1,    60,   132,     4,   133,   136,     4,     7,   205,     6,
      -1,    41,   132,   193,   133,     7,   195,     6,    -1,    56,
      41,   132,   193,   133,     7,   199,     6,    -1,    72,    41,
     199,     7,   139,   193,   138,   193,   138,   193,   140,     6,
      -1,    48,    49,   199,     7,   193,     6,    -1,    44,   132,
     193,   133,     7,   199,     6,    -1,    46,   132,   193,   133,
       7,   199,     6,    -1,    42,   132,   193,   133,     7,   199,
       6,    -1,    42,   132,   193,   133,     7,   199,    52,   195,
       6,    -1,    43,   132,   193,   133,     7,   199,     6,    -1,
      43,   132,   193,   133,     7,   199,    52,   195,     6,    -1,
      50,   132,   193,   133,     7,   139,   193,   138,   193,   138,
       5,   138,     5,   138,     5,   140,     6,    -1,    82,   132,
     193,   133,     7,   199,     6,    -1,    83,   132,   193,   133,
       7,   199,     6,    -1,    84,   132,   193,   133,     7,   199,
      88,   199,    85,   193,     6,    -1,    44,    67,   132,   193,
     133,     7,   199,     6,    -1,    72,    44,   199,     7,   139,
     193,   138,   193,   138,   193,   140,     6,    -1,    56,    44,
     132,   193,   133,     7,   199,     6,    -1,    52,    45,   132,
     193,   133,     7,   199,     6,    -1,    53,    45,   132,   193,
     133,     7,   199,     6,    -1,   100,    45,   132,   193,   133,
       7,   139,   193,   138,   199,   140,     6,    -1,    84,    45,
      86,    87,   132,   193,   133,     7,   197,    88,   139,   199,
     138,   199,   140,    85,   139,   193,   138,   193,   140,     6,
      -1,    84,    45,   132,   193,   133,     7,   197,    88,   139,
     199,   138,   199,   140,    85,   139,   193,   138,   193,   140,
       6,    -1,    45,    67,   132,   193,   133,     7,   199,     6,
      -1,    56,    45,   132,   193,   133,     7,   199,     6,    -1,
      55,    47,   132,   193,   133,     7,   199,     6,    -1,    47,
     132,   193,   133,     7,   199,     6,    -1,    56,    47,   132,
     193,   133,     7,   199,     6,    -1,    62,   195,   139,   168,
     140,    -1,    61,   139,   195,   138,   195,   138,   193,   140,
     139,   168,   140,    -1,    63,   195,   139,   168,   140,    -1,
      64,   139,   195,   138,   193,   140,   139,   168,   140,    -1,
     170,    -1,   169,    -1,   167,    -1,    -1,   169,   166,    -1,
     169,    41,   139,   201,   140,     6,    -1,   169,    44,   139,
     201,   140,     6,    -1,   169,    45,   139,   201,   140,     6,
      -1,   169,    47,   139,   201,   140,     6,    -1,    66,   139,
     169,   140,    -1,    66,     4,   134,   193,   135,     6,    -1,
      74,     4,   134,   193,   135,     6,    -1,    75,     4,   134,
     193,   135,     6,    -1,    69,   139,   169,   140,    -1,    69,
       4,   134,   193,   135,     6,    -1,    69,     4,     6,    -1,
      69,     4,     4,     6,    -1,    89,   202,   139,   169,   140,
      -1,   101,   205,     6,    -1,   102,   205,     6,    -1,   101,
     139,   169,   140,    -1,   102,   139,   169,   140,    -1,     4,
     205,     6,    -1,     4,     4,   134,   193,   135,   205,     6,
      -1,     4,     4,     4,   134,   193,   135,     6,    -1,     4,
     193,     6,    -1,    60,   132,     4,   133,   136,     4,     6,
      -1,    81,     4,     6,    -1,    96,     6,    -1,    38,     6,
      -1,    38,   139,   193,   138,   193,   138,   193,   138,   193,
     138,   193,   138,   193,   140,     6,    -1,    39,     6,    -1,
      91,   132,   193,     8,   193,   133,    -1,    91,   132,   193,
       8,   193,     8,   193,   133,    -1,    91,     4,    92,   139,
     193,     8,   193,   140,    -1,    91,     4,    92,   139,   193,
       8,   193,     8,   193,   140,    -1,    93,    -1,    99,     4,
      -1,    97,    -1,    98,     4,     6,    -1,    94,   132,   193,
     133,    -1,    95,    -1,    65,   195,   139,   169,   140,    -1,
      65,   139,   195,   138,   195,   138,   193,   140,   139,   169,
     140,    -1,    65,   139,   195,   138,   195,   138,   195,   138,
     193,   140,   139,   169,   140,    -1,    -1,    65,   195,   139,
     169,   177,   189,   140,    -1,    -1,    65,   139,   195,   138,
     195,   138,   193,   140,   139,   169,   178,   189,   140,    -1,
      -1,    65,   139,   195,   138,   195,   138,   195,   138,   193,
     140,   139,   169,   179,   189,   140,    -1,    65,    41,   139,
     193,   138,   195,   140,     6,    -1,    65,    44,   139,   193,
     138,   195,   140,     6,    -1,    65,    45,   139,   193,   138,
     195,   140,     6,    -1,    65,    41,   139,   193,   138,   195,
     138,   195,   138,   193,   140,     6,    -1,    65,    44,   139,
     193,   138,   195,   138,   195,   138,   193,   140,     6,    -1,
      65,    45,   139,   193,   138,   195,   138,   195,   138,   193,
     140,     6,    -1,    65,    41,   139,   193,   138,   195,   138,
     195,   138,   195,   138,   193,   140,     6,    -1,    65,    44,
     139,   193,   138,   195,   138,   195,   138,   195,   138,   193,
     140,     6,    -1,    65,    45,   139,   193,   138,   195,   138,
     195,   138,   195,   138,   193,   140,     6,    -1,    -1,    65,
      41,   139,   193,   138,   195,   140,   180,   139,   189,   140,
       6,    -1,    -1,    65,    44,   139,   193,   138,   195,   140,
     181,   139,   189,   140,     6,    -1,    -1,    65,    45,   139,
     193,   138,   195,   140,   182,   139,   189,   140,     6,    -1,
      -1,    65,    41,   139,   193,   138,   195,   138,   195,   138,
     193,   140,   183,   139,   189,   140,     6,    -1,    -1,    65,
      44,   139,   193,   138,   195,   138,   195,   138,   193,   140,
     184,   139,   189,   140,     6,    -1,    -1,    65,    45,   139,
     193,   138,   195,   138,   195,   138,   193,   140,   185,   139,
     189,   140,     6,    -1,    -1,    65,    41,   139,   193,   138,
     195,   138,   195,   138,   195,   138,   193,   140,   186,   139,
     189,   140,     6,    -1,    -1,    65,    44,   139,   193,   138,
     195,   138,   195,   138,   195,   138,   193,   140,   187,   139,
     189,   140,     6,    -1,    -1,    65,    45,   139,   193,   138,
     195,   138,   195,   138,   195,   138,   193,   140,   188,   139,
     189,   140,     6,    -1,   190,    -1,   189,   190,    -1,    73,
     139,   199,   138,   199,   138,   199,   140,     6,    -1,    73,
     139,   199,   138,   199,   140,     6,    -1,    68,     6,    -1,
      54,    44,   199,     7,   193,     6,    -1,    54,    44,   199,
       7,   193,    57,    59,   193,     6,    -1,    54,    44,   199,
       7,   193,    57,    58,   193,     6,    -1,    54,    45,   139,
     193,   140,     7,   199,     6,    -1,    54,    45,   139,   193,
     140,     7,   199,     4,     6,    -1,    51,    45,   139,   193,
     140,     7,   199,     6,    -1,    54,    47,   139,   193,   140,
       7,   199,     6,    -1,    68,    45,   199,     7,   193,     6,
      -1,    68,    45,   199,     6,    -1,    70,     6,    -1,    71,
       6,    -1,   194,    -1,   132,   193,   133,    -1,   122,   193,
      -1,   121,   193,    -1,   127,   193,    -1,   193,   122,   193,
      -1,   193,   121,   193,    -1,   193,   123,   193,    -1,   193,
     124,   193,    -1,   193,   125,   193,    -1,   193,   131,   193,
      -1,   193,   117,   193,    -1,   193,   118,   193,    -1,   193,
     120,   193,    -1,   193,   119,   193,    -1,   193,   116,   193,
      -1,   193,   115,   193,    -1,   193,   113,   193,    -1,   193,
     112,   193,    -1,   193,   111,   193,     8,   193,    -1,    12,
     132,   193,   133,    -1,    13,   132,   193,   133,    -1,    14,
     132,   193,   133,    -1,    15,   132,   193,   133,    -1,    16,
     132,   193,   133,    -1,    17,   132,   193,   133,    -1,    18,
     132,   193,   133,    -1,    19,   132,   193,   133,    -1,    20,
     132,   193,   133,    -1,    22,   132,   193,   133,    -1,    23,
     132,   193,   138,   193,   133,    -1,    24,   132,   193,   133,
      -1,    25,   132,   193,   133,    -1,    26,   132,   193,   133,
      -1,    27,   132,   193,   133,    -1,    28,   132,   193,   133,
      -1,    29,   132,   193,   133,    -1,    30,   132,   193,   138,
     193,   133,    -1,    31,   132,   193,   138,   193,   133,    -1,
      32,   132,   193,   138,   193,   133,    -1,    21,   132,   193,
     133,    -1,    12,   134,   193,   135,    -1,    13,   134,   193,
     135,    -1,    14,   134,   193,   135,    -1,    15,   134,   193,
     135,    -1,    16,   134,   193,   135,    -1,    17,   134,   193,
     135,    -1,    18,   134,   193,   135,    -1,    19,   134,   193,
     135,    -1,    20,   134,   193,   135,    -1,    22,   134,   193,
     135,    -1,    23,   134,   193,   138,   193,   135,    -1,    24,
     134,   193,   135,    -1,    25,   134,   193,   135,    -1,    26,
     134,   193,   135,    -1,    27,   134,   193,   135,    -1,    28,
     134,   193,   135,    -1,    29,   134,   193,   135,    -1,    30,
     134,   193,   138,   193,   135,    -1,    31,   134,   193,   138,
     193,   135,    -1,    32,   134,   193,   138,   193,   135,    -1,
      21,   134,   193,   135,    -1,     3,    -1,     9,    -1,    10,
      -1,    11,    -1,   104,    -1,   105,    -1,   106,    -1,     4,
      -1,     4,   134,   193,   135,    -1,   137,     4,   134,   135,
      -1,     4,   164,    -1,     4,   134,   193,   135,   164,    -1,
       4,   136,     4,    -1,     4,   134,   193,   135,   136,     4,
      -1,     4,   136,     4,   164,    -1,     4,   134,   193,   135,
     136,     4,   164,    -1,   103,   132,     5,   138,   193,   133,
      -1,   196,    -1,   122,   195,    -1,   121,   195,    -1,   195,
     122,   195,    -1,   195,   121,   195,    -1,   139,   193,   138,
     193,   138,   193,   138,   193,   138,   193,   140,    -1,   139,
     193,   138,   193,   138,   193,   138,   193,   140,    -1,   139,
     193,   138,   193,   138,   193,   140,    -1,   132,   193,   138,
     193,   138,   193,   133,    -1,    -1,   139,   198,   140,    -1,
     132,   198,   133,    -1,   199,    -1,   198,   138,   199,    -1,
     193,    -1,   200,    -1,   139,   140,    -1,   139,   201,   140,
      -1,   122,   139,   201,   140,    -1,   193,     8,   193,    -1,
     193,     8,   193,     8,   193,    -1,    41,   139,   193,   140,
      -1,   167,    -1,   170,    -1,   176,    -1,     4,   134,   135,
      -1,   122,     4,   134,   135,    -1,     4,   134,   139,   201,
     140,   135,    -1,   122,     4,   134,   139,   201,   140,   135,
      -1,   193,    -1,   200,    -1,   201,   138,   193,    -1,   201,
     138,   200,    -1,   139,   193,   138,   193,   138,   193,   138,
     193,   140,    -1,   139,   193,   138,   193,   138,   193,   140,
      -1,     4,    -1,     4,   136,    89,   136,     4,    -1,   139,
     204,   140,    -1,     4,   134,   193,   135,   136,    90,    -1,
     202,    -1,   204,   138,   202,    -1,     5,    -1,    40,    -1,
      35,   132,   205,   138,   205,   133,    -1,    36,   132,   205,
     133,    -1,    37,   132,   205,   133,    -1,    34,   132,   205,
     133,    -1,    34,   132,   205,   138,   201,   133,    -1,    34,
     132,     4,   136,     4,   133,    -1,    34,   132,     4,   134,
     193,   135,   136,     4,   133,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   144,   144,   145,   150,   152,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     173,   178,   196,   203,   214,   220,   221,   222,   223,   224,
     225,   229,   231,   236,   238,   244,   434,   243,   462,   467,
     476,   475,   489,   494,   503,   502,   516,   525,   524,   533,
     542,   543,   544,   545,   546,   550,   551,   558,   589,   628,
     682,   699,   717,   728,   747,   761,   778,   804,   831,   845,
     862,   876,   893,   913,   936,   946,   965,   981,   997,  1016,
    1035,  1053,  1071,  1089,  1115,  1133,  1159,  1179,  1203,  1227,
    1253,  1270,  1288,  1307,  1326,  1365,  1390,  1409,  1428,  1444,
    1464,  1481,  1498,  1519,  1524,  1529,  1534,  1542,  1543,  1544,
    1549,  1552,  1556,  1572,  1588,  1604,  1625,  1639,  1645,  1651,
    1663,  1672,  1682,  1696,  1715,  1729,  1737,  1743,  1754,  1768,
    1812,  1827,  1838,  1854,  1864,  1886,  1890,  1895,  1900,  1913,
    1928,  1944,  1970,  1997,  2029,  2036,  2041,  2047,  2051,  2060,
    2068,  2076,  2085,  2084,  2098,  2097,  2111,  2110,  2125,  2132,
    2139,  2146,  2153,  2160,  2167,  2174,  2181,  2189,  2188,  2201,
    2200,  2213,  2212,  2225,  2224,  2237,  2236,  2249,  2248,  2261,
    2260,  2273,  2272,  2285,  2284,  2300,  2303,  2309,  2335,  2359,
    2368,  2386,  2404,  2422,  2451,  2486,  2513,  2540,  2554,  2573,
    2577,  2587,  2588,  2589,  2590,  2591,  2592,  2593,  2594,  2595,
    2602,  2603,  2604,  2605,  2606,  2607,  2608,  2609,  2610,  2611,
    2612,  2613,  2614,  2615,  2616,  2617,  2618,  2619,  2620,  2621,
    2622,  2623,  2624,  2625,  2626,  2627,  2628,  2629,  2630,  2631,
    2632,  2633,  2635,  2636,  2637,  2638,  2639,  2640,  2641,  2642,
    2643,  2644,  2645,  2646,  2647,  2648,  2649,  2650,  2651,  2652,
    2653,  2654,  2655,  2664,  2665,  2666,  2667,  2668,  2669,  2670,
    2674,  2687,  2707,  2721,  2734,  2757,  2775,  2793,  2811,  2829,
    2837,  2841,  2845,  2849,  2853,  2860,  2864,  2868,  2872,  2880,
    2882,  2886,  2893,  2898,  2906,  2911,  2915,  2920,  2924,  2936,
    2942,  2953,  2973,  2983,  2993,  3003,  3020,  3039,  3063,  3092,
    3097,  3101,  3105,  3118,  3122,  3134,  3141,  3163,  3167,  3182,
    3187,  3194,  3198,  3206,  3214,  3228,  3242,  3246,  3265,  3287
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
  "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'", "$accept", "All",
  "GeoFormatItems", "GeoFormatItem", "Printf", "View", "Views",
  "ElementCoords", "ElementValues", "Element", "@1", "@2", "Text2DValues",
  "Text2D", "@3", "Text3DValues", "Text3D", "@4", "InterpolationMatrix",
  "Time", "@5", "Grain", "NumericAffectation", "NumericIncrement",
  "Affectation", "Shape", "Transform", "MultipleShape", "ListOfShapes",
  "Duplicata", "Delete", "Colorify", "Visibility", "Command", "Loop",
  "Extrude", "@6", "@7", "@8", "@9", "@10", "@11", "@12", "@13", "@14",
  "@15", "@16", "@17", "ExtrudeParameters", "ExtrudeParameter",
  "Transfinite", "Coherence", "FExpr", "FExpr_Single", "VExpr",
  "VExpr_Single", "ListOfListOfDouble", "RecursiveListOfListOfDouble",
  "ListOfDouble", "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr",
  "ListOfColor", "RecursiveListOfColor", "StringExpr", 0
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
     125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   141,   142,   142,   143,   143,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     145,   145,   146,   146,   147,   147,   147,   147,   147,   147,
     147,   148,   148,   149,   149,   151,   152,   150,   153,   153,
     155,   154,   156,   156,   158,   157,   159,   161,   160,   162,
     163,   163,   163,   163,   163,   164,   164,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   167,   167,   167,   167,   168,   168,   168,
     169,   169,   169,   169,   169,   169,   170,   170,   170,   170,
     171,   171,   171,   171,   172,   173,   173,   173,   173,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   176,
     176,   176,   177,   176,   178,   176,   179,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   180,   176,   181,
     176,   182,   176,   183,   176,   184,   176,   185,   176,   186,
     176,   187,   176,   188,   176,   189,   189,   190,   190,   190,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   192,
     192,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     195,   195,   195,   195,   195,   196,   196,   196,   196,   197,
     197,   197,   198,   198,   199,   199,   199,   199,   199,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   201,
     201,   201,   201,   202,   202,   202,   202,   203,   203,   204,
     204,   205,   205,   205,   205,   205,   205,   205,   205,   205
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     7,     6,     8,     0,     2,     2,     2,     2,     2,
       2,     1,     3,     1,     3,     0,     0,    10,     1,     3,
       0,    13,     1,     3,     0,    15,     8,     0,     6,     6,
       1,     1,     1,     1,     1,     1,     1,     4,     7,     9,
       6,     6,     3,     6,     6,     9,     6,     9,     5,     8,
       8,    11,     6,     9,     9,     9,     7,     8,    12,     6,
       7,     7,     7,     9,     7,     9,    17,     7,     7,    11,
       8,    12,     8,     8,     8,    12,    22,    20,     8,     8,
       8,     7,     8,     5,    11,     5,     9,     1,     1,     1,
       0,     2,     6,     6,     6,     6,     4,     6,     6,     6,
       4,     6,     3,     4,     5,     3,     3,     4,     4,     3,
       7,     7,     3,     7,     3,     2,     2,    15,     2,     6,
       8,     8,    10,     1,     2,     1,     3,     4,     1,     5,
      11,    13,     0,     7,     0,    13,     0,    15,     8,     8,
       8,    12,    12,    12,    14,    14,    14,     0,    12,     0,
      12,     0,    12,     0,    16,     0,    16,     0,    16,     0,
      18,     0,    18,     0,    18,     1,     2,     9,     7,     2,
       6,     9,     9,     8,     9,     8,     8,     6,     4,     2,
       2,     1,     3,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     6,     6,
       6,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     2,     5,     3,     6,     4,     7,     6,
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
       0,     0,     0,     0,     0,   143,     0,   148,     0,   145,
       0,     0,     0,     0,     0,     5,     7,     6,     8,     9,
      10,    11,    12,    13,    14,    19,    18,    15,    16,    17,
     263,   270,   321,    50,   264,   265,   266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   322,     0,   267,   268,   269,    54,    53,    52,
      51,     0,     0,     0,    56,    55,     0,     0,     0,     0,
       0,     0,     0,   201,     0,     0,   136,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,   110,
     199,   200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   315,     0,     0,     0,     0,     0,   135,     0,   144,
       0,   321,   110,     0,   110,     0,     0,     0,     0,   273,
       0,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     204,   203,   205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,     0,     0,     0,   302,   303,   304,   294,     0,   295,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   282,   281,     0,     0,     0,     0,
     110,   110,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,     0,   122,     0,     0,     0,     0,
       0,     0,   134,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,   146,     0,     0,   125,     0,   126,
       0,     0,   275,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,     0,     0,     0,   309,   310,
       0,     0,    50,     0,     0,     0,     0,     0,    57,     0,
     219,   218,   217,   216,   212,   213,   215,   214,   207,   206,
     208,   209,   210,   211,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
     283,   109,     0,   108,   107,     0,     0,     0,     0,     0,
       0,     0,   152,     0,     0,     0,     0,     0,   116,   111,
     198,     0,   123,     0,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
       0,   127,   128,     0,   271,   277,    24,    35,     0,     0,
       0,    47,     0,     0,    25,    26,    27,    28,    29,    30,
     221,   242,   222,   243,   223,   244,   224,   245,   225,   246,
     226,   247,   227,   248,   228,   249,   229,   250,   241,   262,
     230,   251,     0,     0,   232,   253,   233,   254,   234,   255,
     235,   256,   236,   257,   237,   258,     0,     0,     0,     0,
       0,     0,     0,     0,   326,     0,     0,   324,   325,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      68,     0,     0,     0,     0,   272,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   305,     0,
       0,     0,     0,   297,   299,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   105,     0,     0,     0,     0,     0,   149,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
       0,     0,     0,     0,     0,   274,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,    60,
      61,   311,   312,     0,     0,     0,     0,     0,    63,    64,
      66,     0,     0,   319,     0,    72,   220,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   301,   306,
       0,   298,     0,    79,     0,     0,     0,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   185,
     117,     0,     0,     0,     0,   197,   121,     0,     0,   118,
     119,     0,     0,     0,   289,     0,   316,     0,     0,     0,
     139,     0,   131,   276,   130,     0,     0,     0,     0,     0,
     292,     0,     0,   231,   252,   238,   259,   239,   260,   240,
     261,     0,   328,   327,   323,   279,     0,    50,     0,     0,
       0,     0,    58,     0,     0,     0,   317,    21,     0,    76,
      82,     0,    84,     0,     0,    80,     0,    81,   101,     0,
       0,   300,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,     0,     0,     0,     0,
     110,     0,   167,     0,   169,     0,   171,     0,     0,   189,
       0,   153,   186,     0,     0,     0,     0,     0,     0,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,    23,     0,    31,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,     0,    69,     0,     0,    70,     0,
     320,     0,     0,     0,    90,    98,   307,     0,     0,   195,
      93,    94,     0,     0,     0,   193,   196,   100,    77,    92,
      99,   102,     0,     0,     0,   288,     0,   287,     0,     0,
     158,     0,     0,   159,     0,     0,   160,     0,     0,     0,
       0,   112,   113,   114,   115,     0,     0,   289,     0,     0,
       0,     0,     0,   314,     0,   141,   140,     0,    36,     0,
       0,     0,   293,     0,     0,     0,     0,     0,    59,    65,
      67,     0,    73,     0,     0,    83,    85,   308,     0,   192,
     191,   194,    74,    75,   110,     0,   106,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,     0,   291,
     290,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,    34,    48,    49,   329,     0,   318,     0,     0,     0,
       0,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,   313,
     142,     0,     0,     0,     0,     0,    71,     0,     0,   104,
       0,   173,     0,     0,   175,     0,     0,   177,     0,     0,
     150,     0,   110,     0,     0,     0,     0,     0,     0,    89,
       0,     0,    40,     0,    46,     0,     0,   285,   161,     0,
       0,   168,   162,     0,     0,   170,   163,     0,     0,   172,
       0,   156,     0,   188,    78,    91,     0,     0,    95,     0,
       0,     0,     0,     0,     0,   179,     0,   181,     0,   183,
     155,   151,     0,     0,     0,     0,    37,     0,    44,     0,
       0,     0,   164,     0,     0,   165,     0,     0,   166,     0,
       0,   187,     0,     0,     0,    38,     0,   137,     0,     0,
       0,     0,     0,     0,     0,   157,     0,     0,     0,     0,
       0,     0,   174,     0,   176,     0,   178,     0,     0,     0,
      39,    41,     0,    42,    86,     0,     0,     0,     0,     0,
       0,     0,   180,   182,   184,     0,     0,    43,    45,     0,
       0,     0,    97,     0,    96
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     2,     3,    55,    56,    57,   364,   882,   888,   534,
     678,  1006,  1134,   535,  1100,  1162,   536,  1136,   537,   538,
     682,   539,   120,   199,    58,   499,   294,   482,   483,   295,
      62,    63,    64,    65,    66,   296,   650,  1061,  1112,   931,
     934,   937,  1079,  1083,  1087,  1123,  1126,  1129,   758,   759,
      68,    69,   297,   123,   314,   157,   874,   789,   790,   299,
     420,   183,   604,   714,   124
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -849
static const short int yypact[] =
{
    2251,    16,    37,  2648,  -849,  -849,  1763,   -92,     1,    57,
     -59,   -33,   -23,   -39,    72,    15,    24,    79,    28,   122,
     130,   141,    91,   145,   544,   151,   118,   325,   325,   170,
     365,     6,   302,    12,   310,   351,    78,   359,   367,   370,
     256,   260,   -24,    13,    11,  -849,   284,  -849,   390,  -849,
     399,   426,   403,    -2,     7,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,    32,    14,  -849,  -849,  -849,  -849,   142,   150,   160,
     250,   287,   294,   319,   356,   368,   460,   482,   567,   573,
     579,   585,   586,   589,   595,   599,   602,   603,   326,   336,
     352,   357,  -849,   364,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  1978,  1978,  1978,  -849,  -849,  1978,  1364,    27,   488,
    1978,   504,   819,  -849,   508,   528,  -849,  1978,  -849,  1978,
    1978,  1978,   407,  1978,   408,  1978,  1978,  1297,  1978,   411,
     413,   427,  1297,   419,   423,   433,   434,   437,   449,   454,
     574,   325,   325,   325,  1978,  1978,   -64,  -849,   -44,   325,
     483,   484,   493,  1602,   -21,   459,  -849,  1297,    47,  -849,
    -849,  -849,  1297,  1297,   511,   517,   660,  1978,  1978,   -56,
    1978,   533,  1978,   536,   590,  1978,  1978,  -849,   679,  -849,
     566,  -849,  -849,   702,  -849,   716,   591,  1978,   726,  -849,
     325,  -849,  1978,  1978,  1978,  1978,  1978,  1978,  1978,  1978,
    1978,  1978,  1978,  1978,  1978,  1978,  1978,  1978,  1978,  1978,
    1978,  1978,  1978,  1978,  1978,  1978,  1978,  1978,  1978,  1978,
    1978,  1978,  1978,  1978,  1978,  1978,  1978,  1978,  1978,  1978,
    1978,  1978,  1978,  1978,   501,   332,   332,   332,   745,   491,
     620,   620,   620,  4782,     2,  1813,  2656,   181,   619,   749,
     635,   844,  -849,  -849,  1978,  1978,  1978,  1978,  1978,  1978,
    1978,  1978,  1978,  1978,  1978,  1978,  1978,  1978,  1978,  -849,
     -78,  3288,  4805,  4828,  4851,  1978,  4874,  1978,  4897,  4920,
     542,   639,  1632,  1165,  -849,  -849,  -849,  1224,   776,  -849,
    4943,  1978,  1978,  1978,   777,  1978,  1978,  1978,  1978,  1978,
    1978,  1978,   656,   316,  -849,  -849,  3312,  3336,   325,   325,
     593,   593,   353,  1978,  1978,  1978,  1602,  1602,  1978,   360,
    -849,  1978,  2313,   471,   795,  -849,  1978,  2334,   797,   798,
    1978,  1978,  -849,  4966,  4989,   723,  1978,  5012,   737,  3360,
    -849,   693,  2069,  5035,  -849,  1978,  2380,  -849,  2440,  -849,
    1978,  4152,   392,   344,     4,  5058,  4173,  5081,  4194,  5104,
    4215,  5127,  4236,  5150,  4257,  5173,  4278,  5196,  4299,  5219,
    4320,  5242,  4341,  5265,  4362,  5288,  4383,  3384,  3408,  5311,
    4404,  5334,  4425,  5357,  4446,  5380,  4467,  5403,  4488,  5426,
    4509,  3432,  3456,  3480,  3504,  3528,  3552,   179,   106,   710,
     727,   730,   718,  1978,  -849,  1297,  1297,  2008,  1224,  -849,
     600,   305,   332,  1978,   853,   860,    19,   731,  -849,  2086,
     571,   765,   519,   519,   539,   539,   539,   539,   183,   183,
     620,   620,   620,   620,   859,  1813,  1978,   861,   865,   867,
    5449,   868,  5472,   869,   884,  1428,  1978,   580,  1813,  -849,
     607,  1978,  1978,   886,  2326,  5495,  5518,  1978,  2453,  2744,
    5541,  5564,  5587,  5610,  5633,   758,   325,  1978,  1978,  -849,
    -849,  -849,   759,  2710,  -849,   760,  1978,  3576,  3600,  3624,
    3264,   325,  2461,  4530,   -67,   -47,   -48,   -36,  -849,  -849,
    -849,  1978,  -849,  4551,  -849,   728,   762,  4572,  4593,   891,
     897,   773,  5656,   899,   772,  1978,  2507,  1978,  1978,  -849,
    5679,  -849,  -849,  4614,    34,  -849,  -849,  -849,   778,   779,
     770,  -849,   780,   907,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  1978,  1978,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  1978,  1978,  1978,  1978,
    1978,  1978,  1978,   911,  -849,  1813,   332,  -849,  -849,  1978,
    4635,   910,   912,  1813,   782,    52,  1978,   913,   915,   908,
    -849,   916,   788,    13,   918,  -849,  1978,  -849,   115,  3648,
     325,  1297,  1297,   919,  1297,   920,  1297,  1297,  -849,  1813,
    2770,  1565,   608,  -849,  2108,   976,   786,   921,   922,   938,
     675,   940,   942,   944,   945,   947,   963,   964,   968,   386,
    3672,  3696,  -849,  -849,  2796,   325,   325,   325,   394,  -849,
     182,   967,  1813,  1813,  1813,  1813,   999,   970,  1978,  1978,
     971,   972,  1297,  1297,  1978,   973,  1297,   980,  3720,  -849,
    2125,   696,   979,   982,   985,  -849,   987,    10,   842,  1978,
    1978,  1297,   855,  1978,  -849,  5702,  4656,  5725,  4677,  5748,
    4698,  5771,  4719,  4740,   862,   147,   864,  5794,   333,  -849,
    -849,  1224,  -849,   335,   271,   863,   991,  1036,  -849,  -849,
    -849,    13,  1978,  -849,   626,  -849,  5955,   994,  1978,    61,
      42,    46,  1297,   995,  1297,   998,  1000,   627,  -849,  -849,
    1813,  -849,  1978,  -849,  1978,  1297,  1297,  1297,  -849,   467,
    1297,  1297,  1297,  1297,  1297,  1297,  1297,   523,  1978,  1978,
    1978,   870,   -76,   222,   264,  1602,  1001,   871,   -14,  -849,
    -849,   630,   636,   637,   641,  -849,  -849,  3744,  3768,  -849,
    -849,  1002,  1007,  5817,   -19,   927,  -849,  1978,  1978,  1978,
    -849,   877,  -849,   392,  -849,  1011,  1978,  3792,  3816,   684,
    -849,  1978,  5840,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,   898,  -849,  -849,  -849,  -849,  1297,   332,  1978,  1029,
    1033,    19,  -849,  1032,  4761,    13,  -849,  -849,  3840,  -849,
    -849,   325,  -849,   325,  1034,  -849,  1035,  -849,  -849,   909,
     695,  5955,  3864,  1037,  1042,  1044,  1978,  1978,   832,  1045,
    1047,  1048,  1049,  1050,  1051,  -849,  1943,  2822,  5863,  2147,
     593,   325,  1052,   325,  1053,   325,  1054,  2848,   396,  -849,
    1297,  -849,  -849,  1055,  1056,  1057,  1058,  1978,  1978,  -849,
    -849,  1059,  1297,  1297,   977,  1297,  2684,   486,  5886,  1978,
    -849,  -849,   215,  5955,  1978,  1978,  1297,   929,   699,  5955,
    1297,  1066,  1065,  1067,  1130,  -849,  1069,  1068,  -849,   936,
    -849,  1978,    73,   125,  -849,  -849,  -849,   943,  1978,  -849,
    -849,  -849,  1393,  1790,  1075,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  2035,  1076,   951,  -849,  1978,  -849,   946,   406,
    -849,   965,   439,  -849,   966,   442,  -849,   969,   986,  1978,
     988,  -849,  -849,  -849,  -849,  3888,  3912,   -19,   257,   703,
     989,  1017,  1978,  -849,  1978,  -849,  -849,  3936,  -849,  1978,
    3960,  3984,  -849,  1297,  1978,  1077,  1097,   996,  -849,  -849,
    -849,    13,  -849,  1016,  4008,  -849,  -849,  -849,  4032,  -849,
    -849,  -849,  -849,  -849,   593,  2714,  -849,  1602,   182,  1602,
     182,  1602,   182,  -849,  2874,  1297,  1978,  1978,  1021,  -849,
    -849,  1297,  1978,  2900,  2926,  1297,   993,  5955,  1978,  1978,
     706,  5955,  -849,  -849,  -849,  1121,  -849,  1978,  1128,   997,
    1978,  -849,  2952,   446,    -7,  2978,   474,    29,  3004,   497,
     105,  2567,  1003,   707,  3030,  3056,  1004,  1012,  2052,  -849,
    -849,  1005,  1978,  5909,  4056,  1129,  -849,  4080,  1026,  -849,
    3082,  1132,  1978,  1133,  1134,  1978,  1159,  1164,  1978,  1166,
    -849,   182,  -849,  1297,  1192,  1193,  1194,  1297,  1297,  -849,
    1195,   711,  -849,  1978,  -849,  1978,  1197,  -849,  -849,  1064,
    3108,  -849,  -849,  1070,  3134,  -849,  -849,  1071,  3160,  -849,
     225,  2588,  1031,  -849,  -849,  -849,  1074,  1078,  -849,  1198,
    1080,  5932,  3186,  1079,   182,  1199,   182,  1201,   182,  1202,
    -849,  -849,   182,  1208,  1297,  1131,  -849,   332,  -849,  1214,
    1216,   258,  -849,  1083,   259,  -849,  1084,   265,  -849,  1085,
     268,  -849,  1093,  1086,   714,  -849,  1095,  -849,  1096,  1229,
     182,  1231,   182,  1232,   182,  -849,  1171,  1978,   332,  1238,
     332,  1251,  -849,   282,  -849,   283,  -849,   291,  1119,  4104,
    -849,  -849,   717,  -849,  -849,  1253,  1254,  1256,  1978,  1978,
     332,  1257,  -849,  -849,  -849,  4128,  3212,  -849,  -849,  1978,
    1258,  3238,  -849,  1259,  -849
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -849,  -849,  -849,  -849,  -849,  -849,   740,  -849,    92,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -244,    -1,  -849,  1264,     3,  -319,  -165,     8,
    -849,  -849,  -849,  -849,  -849,  1269,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -715,  -654,
    -849,  -849,    -6,  -849,   224,  -849,   327,  -848,    17,  -100,
    -106,  -577,   462,  -849,    -4
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const short int yytable[] =
{
     122,   332,   485,   191,   337,   121,    60,   126,   527,   415,
     165,    61,   191,   423,   527,   184,   168,   181,   200,   134,
     132,   179,     4,   602,   948,   949,   713,   356,   132,   358,
     345,   257,    98,    99,   100,   101,   196,     5,   102,   191,
     125,    98,    99,   100,   101,   318,   319,   102,   820,   193,
     195,   334,   822,   335,   756,   444,   704,   318,   319,   757,
     445,   756,   851,   128,   852,   129,   757,   819,    98,    99,
     100,   101,   652,   129,   102,   320,   346,   318,   319,   975,
     528,   529,   530,   531,   532,   133,   528,   529,   530,   531,
     532,   654,   653,   133,   821,   321,   136,   756,   823,   130,
     318,   319,   757,   655,   862,   250,   251,   252,   180,   131,
     253,   256,   416,   872,   261,  1010,   258,   259,   330,   172,
     873,   281,   173,   282,   283,   284,   861,   286,   137,   288,
     289,   976,   300,  1053,   813,   142,   143,   192,   144,   134,
     127,   705,   706,   185,   533,   166,   194,   135,   316,   317,
     785,   169,   182,   201,   298,   419,   136,   317,   603,   304,
     138,   114,   115,   114,   115,   492,   197,   139,   198,  1056,
     674,   343,   344,   756,   347,   140,   349,   596,   757,   352,
     353,   336,   318,   319,   333,   516,   141,   460,   422,   338,
     339,   361,   145,   419,   318,   319,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   900,   584,
     408,   409,   410,   411,   585,  1059,   318,   319,   717,   418,
     756,   156,   158,   593,   164,   757,   424,   151,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,  1024,   202,  1027,   203,  1030,   807,   450,
     803,   452,   204,   150,   205,   593,   251,   418,   107,   108,
     109,   110,   206,   756,   207,   464,   465,   466,   757,   468,
     469,   470,   471,   472,   473,   474,   275,   276,   277,   159,
     114,   115,    73,   582,   278,   583,   170,   487,   488,   489,
     250,   251,   490,   481,   481,   493,   756,   756,   484,   484,
     503,   757,   757,   756,   507,   508,   756,   191,   757,   608,
     512,   757,    73,   318,   319,   419,  1090,   167,   958,   520,
     756,   756,   622,   959,   523,   757,   757,   171,   419,   756,
     853,   525,   854,   174,   757,  1110,    98,    99,   100,   101,
     862,   175,   102,   862,   176,   313,   862,   315,   107,   108,
     109,   110,   208,   322,   209,   318,   319,   329,   177,  1121,
     999,  1124,   178,  1127,  1015,   886,   187,  1130,  1139,  1141,
     114,   115,   855,   188,   856,  1143,   160,   590,  1145,   161,
     162,   251,   107,   108,   109,   110,   186,   599,   598,   210,
     597,   211,  1165,  1166,   363,  1153,   212,  1155,   213,  1157,
     189,  1167,   591,   592,   114,   115,   862,   318,   319,   418,
     609,   595,   107,   108,   109,   110,   152,   153,   190,   590,
     620,   214,   418,   215,   476,   624,   625,   154,   244,   806,
     808,   630,   114,   115,   155,   318,   319,   862,   245,   674,
     862,   640,   641,   862,   318,   319,   862,   500,   501,   695,
     644,   318,   319,   526,   246,   419,   152,   153,   216,   247,
     217,   486,   260,   702,   954,   656,   248,   154,   491,   862,
     218,   862,   219,   862,   163,   407,   191,   318,   319,   668,
     262,   670,   671,   727,   279,   318,   319,   318,   319,   419,
     676,   114,   115,   675,   748,   836,   837,   318,   319,   845,
     846,   928,   755,   280,   939,    98,    99,   100,   101,   285,
     287,   102,   479,   480,   987,   302,   761,   762,   763,   764,
     301,   315,   419,   419,   419,   419,   685,   686,   305,   303,
     318,   319,   306,   318,   319,   307,   308,   318,   319,   309,
     687,   688,   689,   690,   691,   692,   693,   989,   312,   418,
     991,   310,   696,   697,  1052,   146,   311,   701,   147,   148,
     707,   149,   220,   331,   221,   318,   319,   264,   265,   266,
     716,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,  1055,   418,   222,   590,   223,   278,   318,   319,
     114,   115,   323,   324,   830,   413,   955,   198,   720,   721,
     419,   723,   325,   725,   726,  1058,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   340,   418,   418,   418,   418,
     278,   341,   767,   768,    26,    27,    28,    29,   773,    31,
     273,   274,   275,   276,   277,  1019,   342,    37,    38,   348,
     278,   114,   115,   787,   788,   350,   455,   792,   198,   771,
     772,   738,   351,   775,   266,   354,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   675,   355,   224,
     639,   225,   278,   809,   779,   226,   814,   227,   357,   114,
     115,   228,   818,   229,   621,   648,   198,   230,   232,   231,
     233,   234,   359,   235,   418,   360,   831,   236,   832,   237,
     362,   238,   739,   239,   240,   242,   241,   243,   593,   824,
     594,   826,   847,   848,   849,   593,   593,   623,   731,   857,
     412,   278,   833,   834,   835,   425,   426,   838,   839,   840,
     841,   842,   843,   844,   815,   593,   816,   829,   593,   427,
     863,   876,   877,   878,   593,   593,   864,   865,   456,   593,
     883,   866,   880,   462,   467,   889,   264,   265,   266,   475,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   502,   894,   893,   505,   506,   278,   264,   265,   266,
     511,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   886,   892,   887,   263,   514,   278,  1031,   780,
     912,   913,   517,   593,   719,   907,   914,   964,   915,   965,
     922,   886,   923,  1000,   886,  1063,  1045,  1064,   586,   964,
     428,  1099,  1148,   481,  1149,  1170,   589,  1171,   484,   600,
     587,   945,   946,   588,   601,   607,   605,   658,   610,   752,
     753,   754,   611,   957,   612,   614,   616,   940,   960,   961,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   617,   951,   626,   638,   974,   278,  1091,   662,   642,
     643,   659,   978,   962,   663,   664,   666,   966,   667,   681,
     679,   680,   683,   684,   710,   694,   699,   703,   700,   708,
     985,   709,   712,   711,   715,   734,   722,   724,   735,   736,
     264,   265,   266,   994,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   737,  1003,   740,  1004,   741,
     278,   742,   743,  1007,   744,   264,   265,   266,  1011,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     745,   746,   747,   760,   786,   278,   766,   769,   770,   858,
     774,  1022,   733,  1025,   776,  1028,   781,   481,   782,   783,
    1034,  1035,   484,   784,   791,   802,  1038,   804,   811,   810,
     817,   825,  1043,  1044,   827,   765,   828,   859,   869,   850,
     860,  1047,  1033,   870,  1050,   875,   879,   881,  1037,   264,
     265,   266,  1041,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   891,   895,   889,   896,   898,   278,
     904,   905,   812,   909,   906,   902,  1080,   903,   910,  1084,
     911,   916,  1088,   917,   918,   919,   920,   921,   930,   933,
     936,   941,   942,   943,   944,   950,   947,  1101,   963,  1102,
     967,   968,   973,   969,   972,   929,   971,   932,   977,   935,
    1092,   981,   983,  1012,  1096,  1097,   986,   264,   265,   266,
     984,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,  1002,  1013,   988,   990,  1016,   278,   992,  1036,
     264,   265,   266,  1135,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   993,   995,  1046,  1001,  1014,
     278,  1132,  1042,  1048,  1071,  1074,   970,  1049,  1078,  1081,
    1082,  1159,  1062,  1067,  1160,  1070,  1163,   264,   265,   266,
    1068,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,  1175,  1176,  1076,  1085,  1177,   278,    70,   290,
    1086,  1113,  1089,  1181,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,  1093,  1094,
    1095,  1098,  1103,  1104,  1116,  1122,   291,  1125,  1128,  1106,
    1108,  1023,  1114,  1026,  1131,  1029,  1133,  1120,  1115,  1117,
    1137,  1138,  1140,  1142,  1144,  1147,    26,    27,    28,    29,
      30,    31,   461,  1146,  1150,  1152,  1151,  1154,  1156,    37,
      38,   264,   265,   266,  1161,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,  1158,  1164,  1168,  1172,
    1173,   278,  1174,  1178,  1182,  1184,   677,    59,   103,   104,
     105,   106,    67,   897,   998,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,   417,     0,     0,
       0,     0,   113,     0,     0,     0,     0,   116,     0,     0,
      70,   290,   119,     0,     0,   459,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,   264,   265,   266,   291,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,    26,    27,
      28,    29,    30,    31,     0,     0,     0,    70,   249,     0,
       0,    37,    38,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,     0,     0,   979,
     103,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   292,
       0,     0,     0,     0,   113,     0,     0,     0,     0,   116,
       0,    70,   249,     0,   119,     0,   293,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,   112,     0,     0,     0,
       0,   113,     0,     0,     0,     0,   116,     0,     0,   254,
       0,   119,     0,   255,   264,   265,   266,     0,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,     0,   113,     0,     0,     0,     0,
     116,     0,     0,   618,     0,   119,     0,   619,    70,   249,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,     0,    70,   249,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    70,   457,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,     0,     0,     0,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,   112,     0,     0,
       0,     0,   113,     0,     0,     0,     0,   116,     0,     0,
     729,     0,   119,     0,   730,   103,   104,   105,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   326,   327,     0,     0,     0,     0,   113,
       0,     0,     0,     0,   328,   103,   104,   105,   106,   119,
       0,   155,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,   112,     0,     0,     0,     0,   113,
       0,     0,     0,     0,   116,     0,    70,    71,    72,   119,
      73,   458,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   980,    98,    99,   100,
     101,     0,     0,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,   290,     0,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,    26,    27,    28,    29,    30,    31,
       0,     0,     0,     0,   111,   112,     0,    37,    38,     0,
     113,     0,   114,   115,     0,   116,     0,   117,     0,   118,
     119,   264,   265,   266,     0,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   103,   104,   105,   106,
       0,   278,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   417,     0,     0,     0,     0,
     113,     0,     0,     0,     0,   116,    70,   249,   191,     0,
     119,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,    98,    99,   100,
     101,    70,   249,   102,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    70,   457,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,   982,     0,     0,     0,     0,   103,   104,   105,   106,
       0,     0,     0,     0,     0,     0,     0,     0,  1069,     0,
       0,     0,     0,     0,   111,   112,     0,     0,     0,     0,
     113,     0,     0,     0,     0,   116,     0,   518,     0,     0,
     119,   103,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   606,     0,     0,     0,     0,   111,
     112,     0,     0,     0,     0,   113,     0,     0,     0,     0,
     116,   103,   104,   105,   106,   119,   732,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,     0,     0,   778,     0,   113,     0,     0,     0,     0,
     116,     0,     0,     0,     0,   119,   264,   265,   266,     0,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,   264,   265,   266,   278,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
     264,   265,   266,   278,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,   264,   265,   266,
     278,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,   264,
     265,   266,     0,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,   264,   265,   266,   278,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,    -4,     1,     0,     0,    -4,   278,     0,   264,   265,
     266,     0,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,     0,
       0,     0,     0,     0,    -4,   926,     0,   927,     0,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,     0,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,     0,     0,     0,     0,
      -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,   494,    11,    12,   495,   496,    15,
     497,    17,     0,    18,     0,    20,    21,     0,    23,    24,
       0,     0,     0,     0,     0,   494,    11,    12,   495,   496,
      15,   497,    17,     0,    18,    36,    20,    21,     0,    23,
      24,     0,     0,     0,     0,    40,    41,    42,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,    52,     0,     0,    40,    41,    42,     0,
       0,   494,    11,    12,   495,   496,    15,   497,    17,     0,
      18,     0,    20,    21,    52,    23,    24,   264,   265,   266,
       0,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,    36,   498,     0,     0,     0,   278,     0,     0,
       0,     0,    40,    41,    42,     0,   627,     0,     0,     0,
       0,     0,     0,     0,   504,     0,     0,     0,     0,     0,
      52,   494,    11,    12,   495,   496,    15,   497,    17,     0,
      18,     0,    20,    21,     0,    23,    24,     0,     0,     0,
       0,     0,   494,    11,    12,   495,   496,    15,   497,    17,
       0,    18,    36,    20,    21,     0,    23,    24,     0,     0,
     521,     0,    40,    41,    42,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
      52,     0,     0,    40,    41,    42,     0,     0,   494,    11,
      12,   495,   496,    15,   497,    17,     0,    18,     0,    20,
      21,    52,    23,    24,   264,   265,   266,     0,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,    36,
     522,     0,     0,     0,   278,     0,     0,     0,     0,    40,
      41,    42,     0,   631,     0,     0,     0,     0,     0,     0,
       0,   649,     0,     0,     0,     0,     0,    52,   494,    11,
      12,   495,   496,    15,   497,    17,     0,    18,     0,    20,
      21,     0,    23,    24,     0,     0,     0,     0,     0,   494,
      11,    12,   495,   496,    15,   497,    17,     0,    18,    36,
      20,    21,     0,    23,    24,     0,     0,   669,     0,    40,
      41,    42,     6,     0,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,    52,     0,     0,
      40,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     8,     9,    52,    10,
      11,    12,    13,    14,    15,    16,    17,     0,    18,    19,
      20,    21,    22,    23,    24,     0,     0,  1060,    25,    26,
      27,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,     0,    37,    38,     0,     0,     0,     0,  1111,    39,
      40,    41,    42,     0,     0,     0,     0,    43,     0,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,   494,    11,    12,   495,   496,    15,   497,    17,     0,
      18,     0,    20,    21,     0,    23,    24,   264,   265,   266,
       0,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,    36,     0,     0,     0,     0,   278,     0,     0,
       0,   421,    40,    41,    42,   264,   265,   266,     0,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
      52,     0,     0,     0,     0,   278,     0,     0,     0,     0,
       0,     0,   952,     0,   953,   264,   265,   266,     0,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,     0,
       0,     0,  1020,     0,  1021,   264,   265,   266,     0,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,     0,
       0,   264,   265,   266,   632,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,     0,     0,   264,   265,   266,
     728,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,     0,     0,   264,   265,   266,   751,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,   264,
     265,   266,   924,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,     0,     0,   264,   265,   266,   938,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,     0,
       0,   264,   265,   266,  1032,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,     0,     0,   264,   265,   266,
    1039,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,     0,     0,   264,   265,   266,  1040,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,   264,
     265,   266,  1051,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,     0,     0,   264,   265,   266,  1054,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,     0,
       0,   264,   265,   266,  1057,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,     0,     0,   264,   265,   266,
    1065,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,     0,     0,   264,   265,   266,  1066,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,   264,
     265,   266,  1077,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,     0,     0,   264,   265,   266,  1105,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,     0,
       0,   264,   265,   266,  1107,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,     0,     0,   264,   265,   266,
    1109,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,     0,     0,   264,   265,   266,  1119,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,   264,
     265,   266,  1180,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,     0,     0,   264,   265,   266,  1183,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,   414,     0,   264,
     265,   266,   477,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   264,   265,   266,   446,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   264,   265,   266,
     477,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   264,   265,   266,   478,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   264,   265,   266,   515,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,   264,
     265,   266,   562,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   264,   265,   266,   563,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   264,   265,   266,
     576,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   264,   265,   266,   577,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   264,   265,   266,   578,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,   264,
     265,   266,   579,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   264,   265,   266,   580,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   264,   265,   266,
     581,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   264,   265,   266,   645,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   264,   265,   266,   646,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,   264,
     265,   266,   647,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   264,   265,   266,   718,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   264,   265,   266,
     749,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   264,   265,   266,   750,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   264,   265,   266,   777,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,   264,
     265,   266,   867,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   264,   265,   266,   868,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   264,   265,   266,
     884,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   264,   265,   266,   885,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   264,   265,   266,   901,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,   264,
     265,   266,   908,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   264,   265,   266,   996,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   264,   265,   266,
     997,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   264,   265,   266,  1005,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   264,   265,   266,  1008,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,   264,
     265,   266,  1009,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   264,   265,   266,  1017,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   264,   265,   266,
    1018,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   264,   265,   266,  1073,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   264,   265,   266,  1075,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,   264,
     265,   266,  1169,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   264,   265,   266,  1179,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,   264,   265,   266,   524,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,   264,   265,   266,   541,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,   264,   265,   266,   543,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,   264,   265,   266,
     545,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,   264,   265,
     266,   547,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,   264,
     265,   266,   549,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
     264,   265,   266,   551,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,   264,   265,   266,   553,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,   264,   265,   266,   555,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,   264,   265,   266,   557,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,   264,   265,   266,   559,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,   264,   265,   266,   561,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,   264,   265,   266,   565,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,   264,   265,   266,
     567,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,   264,   265,
     266,   569,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,   264,
     265,   266,   571,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
     264,   265,   266,   573,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,   264,   265,   266,   575,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,   264,   265,   266,   651,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,   264,   265,   266,   657,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,   264,   265,   266,   660,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,   264,   265,   266,   661,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,   264,   265,   266,   673,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,   264,   265,   266,
     698,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,   264,   265,
     266,   794,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,   264,
     265,   266,   796,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
     264,   265,   266,   798,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,   264,   265,   266,   800,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,   264,   265,   266,   801,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,   264,   265,   266,   899,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,   414,   264,   265,   266,     0,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,     0,   447,   264,
     265,   266,     0,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,   448,   264,   265,   266,     0,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,     0,   449,   264,   265,   266,     0,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,   451,   264,   265,
     266,     0,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,     0,
     453,   264,   265,   266,     0,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,   454,   264,   265,   266,     0,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,     0,   463,   264,   265,   266,
       0,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,   509,
     264,   265,   266,     0,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,     0,   510,   264,   265,   266,     0,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,   513,   264,   265,   266,     0,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,     0,   519,   264,
     265,   266,     0,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,   540,   264,   265,   266,     0,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,     0,   542,   264,   265,   266,     0,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,   544,   264,   265,
     266,     0,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,     0,
     546,   264,   265,   266,     0,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,   548,   264,   265,   266,     0,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,     0,   550,   264,   265,   266,
       0,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,   552,
     264,   265,   266,     0,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,     0,   554,   264,   265,   266,     0,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,   556,   264,   265,   266,     0,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,     0,   558,   264,
     265,   266,     0,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,   560,   264,   265,   266,     0,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,     0,   564,   264,   265,   266,     0,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,   566,   264,   265,
     266,     0,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,     0,
     568,   264,   265,   266,     0,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,   570,   264,   265,   266,     0,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,     0,   572,   264,   265,   266,
       0,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,   574,
     264,   265,   266,     0,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,     0,   613,   264,   265,   266,     0,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,   615,   264,   265,   266,     0,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,     0,   628,   264,
     265,   266,     0,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,   629,   264,   265,   266,     0,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,     0,   633,   264,   265,   266,     0,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,   634,   264,   265,
     266,     0,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,     0,
     635,   264,   265,   266,     0,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,   636,   264,   265,   266,     0,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,     0,   637,   264,   265,   266,
       0,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,   665,
     264,   265,   266,     0,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,     0,   672,   264,   265,   266,     0,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,   793,   264,   265,   266,     0,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,     0,   795,   264,
     265,   266,     0,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,   797,   264,   265,   266,     0,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,     0,   799,   264,   265,   266,     0,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,   805,   264,   265,
     266,     0,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,     0,
     871,   264,   265,   266,     0,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,   890,   264,   265,   266,     0,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,     0,   925,   264,   265,   266,
       0,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,   956,
     264,   265,   266,     0,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,     0,  1072,   264,   265,   266,     0,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,  1118,   264,   265,   266,     0,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278
};

static const short int yycheck[] =
{
       6,   166,   321,     5,   169,     6,     3,     6,     4,     7,
       4,     3,     5,   257,     4,     4,     4,     4,     4,    67,
      67,    45,     6,     4,   872,   873,   603,   192,    67,   194,
      86,     4,    34,    35,    36,    37,     4,     0,    40,     5,
     132,    34,    35,    36,    37,   121,   122,    40,     6,    53,
      54,     4,     6,     6,    68,   133,     4,   121,   122,    73,
     138,    68,   138,     6,   140,   132,    73,     6,    34,    35,
      36,    37,   139,   132,    40,   139,   132,   121,   122,     6,
      76,    77,    78,    79,    80,   132,    76,    77,    78,    79,
      80,   139,   139,   132,    52,   139,   132,    68,    52,   132,
     121,   122,    73,   139,   758,   111,   112,   113,   132,   132,
     116,   117,   110,   132,   120,   963,    89,    90,   139,    41,
     139,   127,    44,   129,   130,   131,   140,   133,    49,   135,
     136,     6,   138,   140,   711,    44,    45,   139,    47,    67,
     139,    89,    90,   132,   140,   139,   139,   132,   154,   155,
     140,   139,   139,   139,   137,   255,   132,   163,   139,   142,
     132,   129,   130,   129,   130,   330,   134,    45,   136,   140,
     136,   177,   178,    68,   180,    45,   182,   421,    73,   185,
     186,   134,   121,   122,   167,   350,    45,   293,     7,   172,
     173,   197,    47,   293,   121,   122,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   815,   133,
     244,   245,   246,   247,   138,   140,   121,   122,   133,   255,
      68,    27,    28,   138,    30,    73,   257,   139,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   988,   132,   990,   134,   992,     7,   285,
     133,   287,   132,   132,   134,   138,   292,   293,   107,   108,
     109,   110,   132,    68,   134,   301,   302,   303,    73,   305,
     306,   307,   308,   309,   310,   311,   123,   124,   125,   139,
     129,   130,     7,   134,   131,   136,     6,   323,   324,   325,
     326,   327,   328,   320,   321,   331,    68,    68,   320,   321,
     336,    73,    73,    68,   340,   341,    68,     5,    73,   445,
     346,    73,     7,   121,   122,   445,  1061,    45,   133,   355,
      68,    68,   458,   138,   360,    73,    73,     6,   458,    68,
     138,   362,   140,     4,    73,   140,    34,    35,    36,    37,
    1024,     4,    40,  1027,     4,   151,  1030,   153,   107,   108,
     109,   110,   132,   159,   134,   121,   122,   163,   132,  1104,
     133,  1106,   132,  1108,   971,   138,     6,  1112,   140,   140,
     129,   130,   138,     4,   140,   140,    41,   413,   140,    44,
      45,   417,   107,   108,   109,   110,   132,   423,   422,   132,
     421,   134,   140,   140,   200,  1140,   132,  1142,   134,  1144,
       4,   140,   415,   416,   129,   130,  1090,   121,   122,   445,
     446,   136,   107,   108,   109,   110,   121,   122,    45,   455,
     456,   132,   458,   134,   138,   461,   462,   132,   132,   703,
     704,   467,   129,   130,   139,   121,   122,  1121,   132,   136,
    1124,   477,   478,  1127,   121,   122,  1130,     6,     7,   585,
     486,   121,   122,   139,   132,   585,   121,   122,   132,   132,
     134,   138,     4,   593,     8,   501,   132,   132,   138,  1153,
     132,  1155,   134,  1157,   139,     4,     5,   121,   122,   515,
       6,   517,   518,   619,     6,   121,   122,   121,   122,   619,
     524,   129,   130,   524,   138,    58,    59,   121,   122,     6,
       7,   850,   138,     5,   138,    34,    35,    36,    37,   132,
     132,    40,   318,   319,   138,   132,   652,   653,   654,   655,
     139,   327,   652,   653,   654,   655,   562,   563,   139,   132,
     121,   122,   139,   121,   122,   132,   132,   121,   122,   132,
     576,   577,   578,   579,   580,   581,   582,   138,     4,   585,
     138,   132,   586,   589,   138,    41,   132,   593,    44,    45,
     596,    47,   132,   134,   134,   121,   122,   111,   112,   113,
     606,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   138,   619,   132,   621,   134,   131,   121,   122,
     129,   130,   139,   139,   730,   134,   140,   136,   611,   612,
     730,   614,   139,   616,   617,   138,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   134,   652,   653,   654,   655,
     131,   134,   658,   659,    61,    62,    63,    64,   664,    66,
     121,   122,   123,   124,   125,   984,     6,    74,    75,   136,
     131,   129,   130,   679,   680,   139,   134,   683,   136,   662,
     663,     6,    92,   666,   113,     6,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   698,   132,   132,
     476,   134,   131,   704,     8,   132,   712,   134,     6,   129,
     130,   132,   718,   134,   134,   491,   136,   132,   132,   134,
     134,   132,     6,   134,   730,   134,   732,   132,   734,   134,
       4,   132,    57,   134,   132,   132,   134,   134,   138,   722,
     140,   724,   748,   749,   750,   138,   138,   140,   140,   755,
       5,   131,   735,   736,   737,   136,     7,   740,   741,   742,
     743,   744,   745,   746,   138,   138,   140,   140,   138,   134,
     140,   777,   778,   779,   138,   138,   140,   140,   139,   138,
     786,   140,   783,     7,     7,   791,   111,   112,   113,   133,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,     6,   808,   807,     7,     7,   131,   111,   112,   113,
      87,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   138,   806,   140,     6,    89,   131,   993,   133,
     836,   837,   139,   138,   610,   140,     4,   138,     6,   140,
     846,   138,   846,   140,   138,   138,   140,   140,   138,   138,
       6,   140,   138,   850,   140,   138,   138,   140,   850,     6,
     133,   867,   868,   133,     4,     6,   135,   139,     7,   645,
     646,   647,     7,   879,     7,     7,     7,   860,   884,   885,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,     7,   875,     7,   136,   901,   131,  1062,     7,   140,
     140,   139,   908,   886,     7,   132,     7,   890,   136,   139,
     132,   132,   132,     6,     6,     4,     6,   135,     6,     6,
     926,     6,   134,     7,     6,   139,     7,     7,     7,     7,
     111,   112,   113,   939,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,     7,   952,     7,   954,     7,
     131,     7,     7,   959,     7,   111,   112,   113,   964,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
       7,     7,     4,     6,   132,   131,     6,     6,     6,   755,
       7,   987,     6,   989,     4,   991,     7,   984,     6,     4,
     996,   997,   984,     6,   139,   133,  1002,   133,     7,   136,
       6,     6,  1008,  1009,     6,     6,     6,     6,     6,   139,
     139,  1017,   995,     6,  1020,    88,   139,     6,  1001,   111,
     112,   113,  1005,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   136,     6,  1042,     4,     6,   131,
       6,     6,     6,     6,   135,   821,  1052,   823,     6,  1055,
       6,     6,  1058,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,    88,     7,  1073,   139,  1075,
       4,     6,   136,     6,     6,   851,     7,   853,   135,   855,
    1063,     6,     6,     6,  1067,  1068,   140,   111,   112,   113,
     139,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    85,     6,   139,   139,    90,   131,   139,    88,
     111,   112,   113,  1117,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   139,   138,     6,   139,   133,
     131,  1114,   139,     5,  1042,     6,     6,   140,     6,     6,
       6,  1147,   139,   139,  1148,   140,  1150,   111,   112,   113,
     138,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,  1168,  1169,   138,     6,  1170,   131,     3,     4,
       6,   140,     6,  1179,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     6,     6,
       6,     6,     5,   139,     6,     6,    41,     6,     6,   139,
     139,   987,   138,   989,     6,   991,    85,   138,   140,   139,
       6,     5,   139,   139,   139,   139,    61,    62,    63,    64,
      65,    66,     8,   140,   139,     6,   140,     6,     6,    74,
      75,   111,   112,   113,     6,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    85,     6,   139,     6,
       6,   131,     6,     6,     6,     6,   526,     3,   103,   104,
     105,   106,     3,   811,   947,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,
      -1,    -1,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
       3,     4,   137,    -1,    -1,   140,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,    41,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,     3,     4,    -1,
      -1,    74,    75,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,     6,
     103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
      -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,   132,
      -1,     3,     4,    -1,   137,    -1,   139,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,   135,
      -1,   137,    -1,   139,   111,   112,   113,    -1,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
     132,    -1,    -1,   135,    -1,   137,    -1,   139,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,   103,   104,
     105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,
      -1,    -1,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
     135,    -1,   137,    -1,   139,   103,   104,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,   132,   103,   104,   105,   106,   137,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,   132,    -1,     3,     4,     5,   137,
       7,   139,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     6,    34,    35,    36,
      37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,   121,   122,    -1,    74,    75,    -1,
     127,    -1,   129,   130,    -1,   132,    -1,   134,    -1,   136,
     137,   111,   112,   113,    -1,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   103,   104,   105,   106,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,
     127,    -1,    -1,    -1,    -1,   132,     3,     4,     5,    -1,
     137,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    34,    35,    36,
      37,     3,     4,    40,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     6,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,
     127,    -1,    -1,    -1,    -1,   132,    -1,     8,    -1,    -1,
     137,   103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
     132,   103,   104,   105,   106,   137,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,    -1,    -1,     8,    -1,   127,    -1,    -1,    -1,    -1,
     132,    -1,    -1,    -1,    -1,   137,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,   111,   112,   113,   131,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
     111,   112,   113,   131,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,   111,   112,   113,
     131,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,   111,
     112,   113,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,   111,   112,   113,   131,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,     0,     1,    -1,    -1,     4,   131,    -1,   111,   112,
     113,    -1,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,    -1,    -1,    33,   138,    -1,   140,    -1,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      89,    -1,    91,    -1,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    -1,    52,    53,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    72,    52,    53,    -1,    55,
      56,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,    -1,    82,    83,    84,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    -1,    52,    53,   100,    55,    56,   111,   112,   113,
      -1,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    72,   140,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    82,    83,    84,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
     100,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    72,    52,    53,    -1,    55,    56,    -1,    -1,
     140,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
     100,    -1,    -1,    82,    83,    84,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    -1,    52,
      53,   100,    55,    56,   111,   112,   113,    -1,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    72,
     140,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,   100,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    72,
      52,    53,    -1,    55,    56,    -1,    -1,   140,    -1,    82,
      83,    84,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    38,    39,   100,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,   140,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    -1,    74,    75,    -1,    -1,    -1,    -1,   140,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    89,    -1,    91,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    -1,    52,    53,    -1,    55,    56,   111,   112,   113,
      -1,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    72,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,   135,    82,    83,    84,   111,   112,   113,    -1,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     100,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   111,   112,   113,    -1,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   111,   112,   113,    -1,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   140,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     140,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   140,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   140,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   140,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   140,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     140,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   140,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   140,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   140,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   140,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     140,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   140,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   140,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   140,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   140,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     140,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   140,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   140,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   140,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,   133,    -1,   111,
     112,   113,   138,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,   111,   112,   113,   138,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,   113,
     138,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,   111,   112,   113,   138,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,   111,   112,   113,   138,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,
     112,   113,   138,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,   111,   112,   113,   138,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,   113,
     138,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,   111,   112,   113,   138,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,   111,   112,   113,   138,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,
     112,   113,   138,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,   111,   112,   113,   138,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,   113,
     138,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,   111,   112,   113,   138,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,   111,   112,   113,   138,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,
     112,   113,   138,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,   111,   112,   113,   138,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,   113,
     138,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,   111,   112,   113,   138,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,   111,   112,   113,   138,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,
     112,   113,   138,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,   111,   112,   113,   138,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,   113,
     138,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,   111,   112,   113,   138,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,   111,   112,   113,   138,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,
     112,   113,   138,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,   111,   112,   113,   138,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,   113,
     138,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,   111,   112,   113,   138,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,   111,   112,   113,   138,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,
     112,   113,   138,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,   111,   112,   113,   138,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,   111,   112,   113,
     138,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,   111,   112,   113,   138,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,   111,   112,   113,   138,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   111,
     112,   113,   138,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,   111,   112,   113,   138,   115,   116,   117,
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
      -1,    -1,   131,   111,   112,   113,   135,   115,   116,   117,
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
      -1,    -1,    -1,   131,    -1,   133,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     1,   142,   143,     6,     0,     4,    33,    38,    39,
      41,    42,    43,    44,    45,    46,    47,    48,    50,    51,
      52,    53,    54,    55,    56,    60,    61,    62,    63,    64,
      65,    66,    68,    69,    70,    71,    72,    74,    75,    81,
      82,    83,    84,    89,    91,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   144,   145,   146,   165,   166,
     167,   170,   171,   172,   173,   174,   175,   176,   191,   192,
       3,     4,     5,     7,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    34,    35,
      36,    37,    40,   103,   104,   105,   106,   107,   108,   109,
     110,   121,   122,   127,   129,   130,   132,   134,   136,   137,
     163,   164,   193,   194,   205,   132,     6,   139,     6,   132,
     132,   132,    67,   132,    67,   132,   132,    49,   132,    45,
      45,    45,    44,    45,    47,    47,    41,    44,    45,    47,
     132,   139,   121,   122,   132,   139,   195,   196,   195,   139,
      41,    44,    45,   139,   195,     4,   139,    45,     4,   139,
       6,     6,    41,    44,     4,     4,     4,   132,   132,    45,
     132,     4,   139,   202,     4,   132,   132,     6,     4,     4,
      45,     5,   139,   205,   139,   205,     4,   134,   136,   164,
       4,   139,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   132,   132,   132,   132,     4,
     193,   193,   193,   193,   135,   139,   193,     4,    89,    90,
       4,   193,     6,     6,   111,   112,   113,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   131,     6,
       5,   193,   193,   193,   193,   132,   193,   132,   193,   193,
       4,    41,   122,   139,   167,   170,   176,   193,   199,   200,
     193,   139,   132,   132,   199,   139,   139,   132,   132,   132,
     132,   132,     4,   195,   195,   195,   193,   193,   121,   122,
     139,   139,   195,   139,   139,   139,   121,   122,   132,   195,
     139,   134,   169,   199,     4,     6,   134,   169,   199,   199,
     134,   134,     6,   193,   193,    86,   132,   193,   136,   193,
     139,    92,   193,   193,     6,   132,   169,     6,   169,     6,
     134,   193,     4,   195,   147,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,     4,   205,   205,
     205,   205,     5,   134,   133,     7,   110,   122,   193,   200,
     201,   135,     7,   163,   164,   136,     7,   134,     6,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   133,   138,   138,   133,   133,   133,
     193,   133,   193,   133,   133,   134,   139,     4,   139,   140,
     201,     8,     7,   133,   193,   193,   193,     7,   193,   193,
     193,   193,   193,   193,   193,   133,   138,   138,   138,   195,
     195,   167,   168,   169,   170,   168,   138,   193,   193,   193,
     193,   138,   169,   193,    41,    44,    45,    47,   140,   166,
       6,     7,     6,   193,   140,     7,     7,   193,   193,   133,
     133,    87,   193,   133,    89,   138,   169,   139,     8,   133,
     193,   140,   140,   193,   135,   164,   139,     4,    76,    77,
      78,    79,    80,   140,   150,   154,   157,   159,   160,   162,
     133,   135,   133,   135,   133,   135,   133,   135,   133,   135,
     133,   135,   133,   135,   133,   135,   133,   135,   133,   135,
     133,   135,   138,   138,   133,   135,   133,   135,   133,   135,
     133,   135,   133,   135,   133,   135,   138,   138,   138,   138,
     138,   138,   134,   136,   133,   138,   138,   133,   133,   138,
     193,   199,   199,   138,   140,   136,   163,   164,   205,   193,
       6,     4,     4,   139,   203,   135,     8,     6,   201,   193,
       7,     7,     7,   133,     7,   133,     7,     7,   135,   139,
     193,   134,   201,   140,   193,   193,     7,   140,   133,   133,
     193,   140,   140,   133,   133,   133,   133,   133,   136,   195,
     193,   193,   140,   140,   193,   138,   138,   138,   195,   140,
     177,   135,   139,   139,   139,   139,   193,   135,   139,   139,
     135,   135,     7,     7,   132,   133,     7,   136,   193,   140,
     193,   193,   133,   135,   136,   164,   205,   147,   151,   132,
     132,   139,   161,   132,     6,   193,   193,   193,   193,   193,
     193,   193,   193,   193,     4,   201,   205,   193,   135,     6,
       6,   193,   200,   135,     4,    89,    90,   193,     6,     6,
       6,     7,   134,   202,   204,     6,   193,   133,   138,   195,
     199,   199,     7,   199,     7,   199,   199,   201,   140,   135,
     139,   140,     8,     6,   139,     7,     7,     7,     6,    57,
       7,     7,     7,     7,     7,     7,     7,     4,   138,   138,
     138,   140,   195,   195,   195,   138,    68,    73,   189,   190,
       6,   201,   201,   201,   201,     6,     6,   193,   193,     6,
       6,   199,   199,   193,     7,   199,     4,   138,     8,     8,
     133,     7,     6,     4,     6,   140,   132,   193,   193,   198,
     199,   139,   193,   133,   135,   133,   135,   133,   135,   133,
     135,   135,   133,   133,   133,   133,   163,     7,   163,   164,
     136,     7,     6,   202,   193,   138,   140,     6,   193,     6,
       6,    52,     6,    52,   199,     6,   199,     6,     6,   140,
     201,   193,   193,   199,   199,   199,    58,    59,   199,   199,
     199,   199,   199,   199,   199,     6,     7,   193,   193,   193,
     139,   138,   140,   138,   140,   138,   140,   193,   195,     6,
     139,   140,   190,   140,   140,   140,   140,   138,   138,     6,
       6,   133,   132,   139,   197,    88,   193,   193,   193,   139,
     164,     6,   148,   193,   138,   138,   138,   140,   149,   193,
     133,   136,   199,   205,   193,     6,     4,   203,     6,   135,
     202,   138,   195,   195,     6,     6,   135,   140,   138,     6,
       6,     6,   193,   193,     4,     6,     6,     6,     6,     6,
       6,     6,   193,   205,   140,   133,   138,   140,   168,   195,
       6,   180,   195,     6,   181,   195,     6,   182,   140,   138,
     199,     6,     6,     6,     6,   193,   193,     7,   198,   198,
      88,   199,   138,   140,     8,   140,   133,   193,   133,   138,
     193,   193,   199,   139,   138,   140,   199,     4,     6,     6,
       6,     7,     6,   136,   193,     6,     6,   135,   193,     6,
       6,     6,     6,     6,   139,   193,   140,   138,   139,   138,
     139,   138,   139,   139,   193,   138,   138,   138,   197,   133,
     140,   139,    85,   193,   193,   138,   152,   193,   138,   138,
     198,   193,     6,     6,   133,   202,    90,   138,   138,   168,
     138,   140,   193,   195,   189,   193,   195,   189,   193,   195,
     189,   169,   140,   199,   193,   193,    88,   199,   193,   140,
     140,   199,   139,   193,   193,   140,     6,   193,     5,   140,
     193,   140,   138,   140,   140,   138,   140,   140,   138,   140,
     140,   178,   139,   138,   140,   140,   140,   139,   138,     6,
     140,   149,   133,   138,     6,   138,   138,   140,     6,   183,
     193,     6,     6,   184,   193,     6,     6,   185,   193,     6,
     189,   169,   199,     6,     6,     6,   199,   199,     6,   140,
     155,   193,   193,     5,   139,   140,   139,   140,   139,   140,
     140,   140,   179,   140,   138,   140,     6,   139,   133,   140,
     138,   189,     6,   186,   189,     6,   187,   189,     6,   188,
     189,     6,   199,    85,   153,   205,   158,     6,     5,   140,
     139,   140,   139,   140,   139,   140,   140,   139,   138,   140,
     139,   140,     6,   189,     6,   189,     6,   189,    85,   193,
     205,     6,   156,   205,     6,   140,   140,   140,   139,   138,
     138,   140,     6,     6,     6,   193,   193,   205,     6,   138,
     140,   193,     6,   140,     6
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
#line 145 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 156 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 157 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 158 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 159 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 160 "Gmsh.y"
    { List_Delete((yyvsp[0].l)); return 1; ;}
    break;

  case 11:
#line 161 "Gmsh.y"
    { List_Delete((yyvsp[0].l)); return 1; ;}
    break;

  case 12:
#line 162 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 163 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 164 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 165 "Gmsh.y"
    { List_Delete((yyvsp[0].l)); return 1; ;}
    break;

  case 16:
#line 166 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 167 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 168 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 169 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 174 "Gmsh.y"
    {
      Msg(DIRECT, (yyvsp[-2].c));
      Free((yyvsp[-2].c));
    ;}
    break;

  case 21:
#line 179 "Gmsh.y"
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

  case 22:
#line 197 "Gmsh.y"
    { 
      if(!strcmp((yyvsp[-5].c), "View") && !CheckViewErrorFlags(View)){
	EndView(View, 0, yyname, (yyvsp[-4].c));
      }
      Free((yyvsp[-5].c)); Free((yyvsp[-4].c));
    ;}
    break;

  case 23:
#line 204 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-7].c), "View") && !CheckViewErrorFlags(View)){
	EndView(View, 0, yyname, (yyvsp[-6].c));
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-6].c)); Free((yyvsp[-5].c));
    ;}
    break;

  case 24:
#line 214 "Gmsh.y"
    {
      View = BeginView(1); 
      for(int i = 0; i < VIEW_NB_ELEMENT_TYPES; i++){
	ViewErrorFlags[i] = 0;
      }
    ;}
    break;

  case 31:
#line 230 "Gmsh.y"
    { ViewCoord[ViewCoordIdx] = (yyvsp[0].d); ViewCoordIdx++; ;}
    break;

  case 32:
#line 232 "Gmsh.y"
    { ViewCoord[ViewCoordIdx] = (yyvsp[0].d); ViewCoordIdx++; ;}
    break;

  case 33:
#line 237 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[0].d)); ;}
    break;

  case 34:
#line 239 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[0].d)); ;}
    break;

  case 35:
#line 244 "Gmsh.y"
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

  case 36:
#line 434 "Gmsh.y"
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

  case 37:
#line 452 "Gmsh.y"
    {
      if(ViewValueList){  
	if((List_Nbr(ViewValueList) - ViewNumListTmp) % (ViewNumComp * ViewNumNodes)) 
	  ViewErrorFlags[ViewElementIdx]++;
	(*ViewNumList)++;
      }
    ;}
    break;

  case 38:
#line 463 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[0].c))+1; i++) List_Add(View->T2C, &(yyvsp[0].c)[i]); 
      Free((yyvsp[0].c));
    ;}
    break;

  case 39:
#line 468 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[0].c))+1; i++) List_Add(View->T2C, &(yyvsp[0].c)[i]); 
      Free((yyvsp[0].c));
    ;}
    break;

  case 40:
#line 476 "Gmsh.y"
    { 
      List_Add(View->T2D, &(yyvsp[-5].d)); List_Add(View->T2D, &(yyvsp[-3].d));
      List_Add(View->T2D, &(yyvsp[-1].d)); 
      double d = List_Nbr(View->T2C);
      List_Add(View->T2D, &d); 
    ;}
    break;

  case 41:
#line 483 "Gmsh.y"
    {
      View->NbT2++;
    ;}
    break;

  case 42:
#line 490 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[0].c))+1; i++) List_Add(View->T3C, &(yyvsp[0].c)[i]); 
      Free((yyvsp[0].c));
    ;}
    break;

  case 43:
#line 495 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[0].c))+1; i++) List_Add(View->T3C, &(yyvsp[0].c)[i]); 
      Free((yyvsp[0].c));
    ;}
    break;

  case 44:
#line 503 "Gmsh.y"
    { 
      List_Add(View->T3D, &(yyvsp[-7].d)); List_Add(View->T3D, &(yyvsp[-5].d));
      List_Add(View->T3D, &(yyvsp[-3].d)); List_Add(View->T3D, &(yyvsp[-1].d)); 
      double d = List_Nbr(View->T3C);
      List_Add(View->T3D, &d); 
    ;}
    break;

  case 45:
#line 510 "Gmsh.y"
    {
      View->NbT3++;
    ;}
    break;

  case 46:
#line 518 "Gmsh.y"
    {
      View->adaptive = new Adaptive_Post_View(View, (yyvsp[-5].l), (yyvsp[-2].l));
    ;}
    break;

  case 47:
#line 525 "Gmsh.y"
    {
      ViewValueList = View->Time;
    ;}
    break;

  case 48:
#line 529 "Gmsh.y"
    {
    ;}
    break;

  case 49:
#line 534 "Gmsh.y"
    {
      (*View->Grains) [(int)(yyvsp[-3].d)] = (yyvsp[-1].l);
    ;}
    break;

  case 50:
#line 542 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 51:
#line 543 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 52:
#line 544 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 53:
#line 545 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 54:
#line 546 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 55:
#line 550 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 56:
#line 551 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 57:
#line 559 "Gmsh.y"
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

  case 58:
#line 590 "Gmsh.y"
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

  case 59:
#line 629 "Gmsh.y"
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

  case 60:
#line 683 "Gmsh.y"
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

  case 61:
#line 700 "Gmsh.y"
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

  case 62:
#line 718 "Gmsh.y"
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

  case 63:
#line 729 "Gmsh.y"
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

  case 64:
#line 748 "Gmsh.y"
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

  case 65:
#line 762 "Gmsh.y"
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

  case 66:
#line 779 "Gmsh.y"
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

  case 67:
#line 805 "Gmsh.y"
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

  case 68:
#line 832 "Gmsh.y"
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

  case 69:
#line 846 "Gmsh.y"
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

  case 70:
#line 863 "Gmsh.y"
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

  case 71:
#line 877 "Gmsh.y"
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

  case 72:
#line 894 "Gmsh.y"
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

  case 73:
#line 914 "Gmsh.y"
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

  case 74:
#line 937 "Gmsh.y"
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

  case 75:
#line 947 "Gmsh.y"
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

  case 76:
#line 966 "Gmsh.y"
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

  case 77:
#line 982 "Gmsh.y"
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

  case 78:
#line 998 "Gmsh.y"
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

  case 79:
#line 1017 "Gmsh.y"
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

  case 80:
#line 1036 "Gmsh.y"
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

  case 81:
#line 1054 "Gmsh.y"
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

  case 82:
#line 1072 "Gmsh.y"
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

  case 83:
#line 1090 "Gmsh.y"
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

  case 84:
#line 1116 "Gmsh.y"
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

  case 85:
#line 1134 "Gmsh.y"
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

  case 86:
#line 1161 "Gmsh.y"
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

  case 87:
#line 1180 "Gmsh.y"
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

  case 88:
#line 1204 "Gmsh.y"
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

  case 89:
#line 1228 "Gmsh.y"
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

  case 90:
#line 1254 "Gmsh.y"
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

  case 91:
#line 1271 "Gmsh.y"
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

  case 92:
#line 1289 "Gmsh.y"
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

  case 93:
#line 1308 "Gmsh.y"
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

  case 94:
#line 1327 "Gmsh.y"
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

  case 95:
#line 1366 "Gmsh.y"
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

  case 96:
#line 1393 "Gmsh.y"
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

  case 97:
#line 1412 "Gmsh.y"
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

  case 98:
#line 1429 "Gmsh.y"
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

  case 99:
#line 1445 "Gmsh.y"
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

  case 100:
#line 1465 "Gmsh.y"
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

  case 101:
#line 1482 "Gmsh.y"
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

  case 102:
#line 1499 "Gmsh.y"
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

  case 103:
#line 1520 "Gmsh.y"
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 104:
#line 1525 "Gmsh.y"
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 105:
#line 1530 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 106:
#line 1535 "Gmsh.y"
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 107:
#line 1542 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); ;}
    break;

  case 108:
#line 1543 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); ;}
    break;

  case 109:
#line 1544 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); ;}
    break;

  case 110:
#line 1549 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 111:
#line 1553 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    ;}
    break;

  case 112:
#line 1557 "Gmsh.y"
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

  case 113:
#line 1573 "Gmsh.y"
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

  case 114:
#line 1589 "Gmsh.y"
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

  case 115:
#line 1605 "Gmsh.y"
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

  case 116:
#line 1626 "Gmsh.y"
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

  case 117:
#line 1640 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "View")) AliasView((int)(yyvsp[-2].d), 0);
      Free((yyvsp[-4].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 118:
#line 1646 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "View")) AliasView((int)(yyvsp[-2].d), 0);
      Free((yyvsp[-4].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 119:
#line 1652 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "View")) AliasView((int)(yyvsp[-2].d), 1);
      Free((yyvsp[-4].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 120:
#line 1664 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 121:
#line 1673 "Gmsh.y"
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

  case 122:
#line 1683 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-1].c), "Meshes") || !strcmp((yyvsp[-1].c), "All")){
	Init_Mesh(THEM);
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

  case 123:
#line 1697 "Gmsh.y"
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

  case 124:
#line 1716 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u));
      }
      List_Delete((yyvsp[-1].l));      
    ;}
    break;

  case 125:
#line 1730 "Gmsh.y"
    {
      int m = (CTX.visibility_mode == 2) ? VIS_MESH : 
	((CTX.visibility_mode == 1) ? VIS_GEOM : VIS_GEOM|VIS_MESH);
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber((yyvsp[-1].c), i, m);
      Free((yyvsp[-1].c));
    ;}
    break;

  case 126:
#line 1738 "Gmsh.y"
    {
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber((yyvsp[-1].c), i, 0);
      Free((yyvsp[-1].c));
    ;}
    break;

  case 127:
#line 1744 "Gmsh.y"
    {
      int m = (CTX.visibility_mode == 2) ? VIS_MESH :
	((CTX.visibility_mode == 1) ? VIS_GEOM : VIS_GEOM|VIS_MESH);
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, m);
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 128:
#line 1755 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 129:
#line 1769 "Gmsh.y"
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
	ParseFile(tmpstring, 0, 0, 1);
      }
      else if(!strcmp((yyvsp[-2].c), "Print")){
#if defined(HAVE_FLTK)
	if(!CTX.batch){
	  char tmpstring[1024];
	  FixRelativePath((yyvsp[-1].c), tmpstring);
	  CreateOutputFile(tmpstring, CTX.print.format);
	}
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

  case 130:
#line 1813 "Gmsh.y"
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

  case 131:
#line 1828 "Gmsh.y"
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

  case 132:
#line 1839 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-2].c), "Sleep")){
	SleepInSeconds((yyvsp[-1].d));
      }
      else if(!strcmp((yyvsp[-2].c), "Remesh")){
	ReMesh(THEM);
      }
      else if(!strcmp((yyvsp[-2].c), "Mesh")){
	yymsg(GERROR, "Mesh directives are not (yet) allowed in scripts");
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", (yyvsp[-2].c));
      }
      Free((yyvsp[-2].c));
    ;}
    break;

  case 133:
#line 1855 "Gmsh.y"
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

  case 134:
#line 1865 "Gmsh.y"
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

  case 135:
#line 1887 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 136:
#line 1891 "Gmsh.y"
    {
      CTX.forced_bbox = 0;
      SetBoundingBox();
    ;}
    break;

  case 137:
#line 1896 "Gmsh.y"
    {
      CTX.forced_bbox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    ;}
    break;

  case 138:
#line 1901 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      if(!CTX.batch) // we're in interactive mode
	Draw();
#endif
    ;}
    break;

  case 139:
#line 1914 "Gmsh.y"
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

  case 140:
#line 1929 "Gmsh.y"
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

  case 141:
#line 1945 "Gmsh.y"
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

  case 142:
#line 1971 "Gmsh.y"
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

  case 143:
#line 1998 "Gmsh.y"
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

  case 144:
#line 2030 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction((yyvsp[0].c), yyin, yyname, yylineno))
	yymsg(GERROR, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 145:
#line 2037 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin, yyname, yylineno))
	yymsg(GERROR, "Error while exiting function");
    ;}
    break;

  case 146:
#line 2042 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction((yyvsp[-1].c), &yyin, yyname, yylineno))
	yymsg(GERROR, "Unknown function %s", (yyvsp[-1].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 147:
#line 2048 "Gmsh.y"
    {
      if(!(yyvsp[-1].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 148:
#line 2052 "Gmsh.y"
    {
    ;}
    break;

  case 149:
#line 2061 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l), 
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 150:
#line 2069 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l), 
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 151:
#line 2077 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l), 
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 152:
#line 2085 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 153:
#line 2090 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l), 
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 154:
#line 2098 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 155:
#line 2103 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l), 
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 156:
#line 2111 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 157:
#line 2116 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l), 
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 158:
#line 2126 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d), 
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 159:
#line 2133 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d), 
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 160:
#line 2140 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d), 
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 161:
#line 2147 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d), 
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 162:
#line 2154 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d), 
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 163:
#line 2161 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d), 
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 164:
#line 2168 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d), 
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 165:
#line 2175 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d), 
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 166:
#line 2182 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d), 
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 167:
#line 2189 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 168:
#line 2194 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d), 
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 169:
#line 2201 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 170:
#line 2206 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d), 
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 171:
#line 2213 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 172:
#line 2218 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d), 
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 173:
#line 2225 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 174:
#line 2230 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d), 
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 175:
#line 2237 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 176:
#line 2242 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d), 
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 177:
#line 2249 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 178:
#line 2254 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d), 
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 179:
#line 2261 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 180:
#line 2266 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d), 
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 181:
#line 2273 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 182:
#line 2278 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d), 
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 183:
#line 2285 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 184:
#line 2290 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d), 
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 185:
#line 2301 "Gmsh.y"
    {
    ;}
    break;

  case 186:
#line 2304 "Gmsh.y"
    {
    ;}
    break;

  case 187:
#line 2310 "Gmsh.y"
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

  case 188:
#line 2336 "Gmsh.y"
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

  case 189:
#line 2360 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 190:
#line 2369 "Gmsh.y"
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

  case 191:
#line 2387 "Gmsh.y"
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

  case 192:
#line 2405 "Gmsh.y"
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

  case 193:
#line 2423 "Gmsh.y"
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

  case 194:
#line 2452 "Gmsh.y"
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

  case 195:
#line 2487 "Gmsh.y"
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

  case 196:
#line 2514 "Gmsh.y"
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

  case 197:
#line 2541 "Gmsh.y"
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

  case 198:
#line 2555 "Gmsh.y"
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

  case 199:
#line 2574 "Gmsh.y"
    { 
      ReplaceAllDuplicates(THEM);
    ;}
    break;

  case 200:
#line 2578 "Gmsh.y"
    { 
      IntersectAllSegmentsTogether();
    ;}
    break;

  case 201:
#line 2587 "Gmsh.y"
    { (yyval.d) = (yyvsp[0].d);           ;}
    break;

  case 202:
#line 2588 "Gmsh.y"
    { (yyval.d) = (yyvsp[-1].d);           ;}
    break;

  case 203:
#line 2589 "Gmsh.y"
    { (yyval.d) = -(yyvsp[0].d);          ;}
    break;

  case 204:
#line 2590 "Gmsh.y"
    { (yyval.d) = (yyvsp[0].d);           ;}
    break;

  case 205:
#line 2591 "Gmsh.y"
    { (yyval.d) = !(yyvsp[0].d);          ;}
    break;

  case 206:
#line 2592 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      ;}
    break;

  case 207:
#line 2593 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      ;}
    break;

  case 208:
#line 2594 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      ;}
    break;

  case 209:
#line 2596 "Gmsh.y"
    { 
      if(!(yyvsp[0].d))
	yymsg(GERROR, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);     
    ;}
    break;

  case 210:
#line 2602 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  ;}
    break;

  case 211:
#line 2603 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  ;}
    break;

  case 212:
#line 2604 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      ;}
    break;

  case 213:
#line 2605 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      ;}
    break;

  case 214:
#line 2606 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     ;}
    break;

  case 215:
#line 2607 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     ;}
    break;

  case 216:
#line 2608 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     ;}
    break;

  case 217:
#line 2609 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     ;}
    break;

  case 218:
#line 2610 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     ;}
    break;

  case 219:
#line 2611 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     ;}
    break;

  case 220:
#line 2612 "Gmsh.y"
    { (yyval.d) = (yyvsp[-4].d)? (yyvsp[-2].d) : (yyvsp[0].d);  ;}
    break;

  case 221:
#line 2613 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[-1].d));      ;}
    break;

  case 222:
#line 2614 "Gmsh.y"
    { (yyval.d) = log((yyvsp[-1].d));      ;}
    break;

  case 223:
#line 2615 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[-1].d));    ;}
    break;

  case 224:
#line 2616 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-1].d));     ;}
    break;

  case 225:
#line 2617 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[-1].d));      ;}
    break;

  case 226:
#line 2618 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[-1].d));     ;}
    break;

  case 227:
#line 2619 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[-1].d));      ;}
    break;

  case 228:
#line 2620 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[-1].d));     ;}
    break;

  case 229:
#line 2621 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[-1].d));      ;}
    break;

  case 230:
#line 2622 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[-1].d));     ;}
    break;

  case 231:
#line 2623 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));;}
    break;

  case 232:
#line 2624 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[-1].d));     ;}
    break;

  case 233:
#line 2625 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[-1].d));     ;}
    break;

  case 234:
#line 2626 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[-1].d));     ;}
    break;

  case 235:
#line 2627 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[-1].d));     ;}
    break;

  case 236:
#line 2628 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[-1].d));    ;}
    break;

  case 237:
#line 2629 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[-1].d));     ;}
    break;

  case 238:
#line 2630 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 239:
#line 2631 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 240:
#line 2632 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-3].d)*(yyvsp[-3].d)+(yyvsp[-1].d)*(yyvsp[-1].d)); ;}
    break;

  case 241:
#line 2633 "Gmsh.y"
    { (yyval.d) = (yyvsp[-1].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 242:
#line 2635 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[-1].d));      ;}
    break;

  case 243:
#line 2636 "Gmsh.y"
    { (yyval.d) = log((yyvsp[-1].d));      ;}
    break;

  case 244:
#line 2637 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[-1].d));    ;}
    break;

  case 245:
#line 2638 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-1].d));     ;}
    break;

  case 246:
#line 2639 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[-1].d));      ;}
    break;

  case 247:
#line 2640 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[-1].d));     ;}
    break;

  case 248:
#line 2641 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[-1].d));      ;}
    break;

  case 249:
#line 2642 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[-1].d));     ;}
    break;

  case 250:
#line 2643 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[-1].d));      ;}
    break;

  case 251:
#line 2644 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[-1].d));     ;}
    break;

  case 252:
#line 2645 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));;}
    break;

  case 253:
#line 2646 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[-1].d));     ;}
    break;

  case 254:
#line 2647 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[-1].d));     ;}
    break;

  case 255:
#line 2648 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[-1].d));     ;}
    break;

  case 256:
#line 2649 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[-1].d));     ;}
    break;

  case 257:
#line 2650 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[-1].d));    ;}
    break;

  case 258:
#line 2651 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[-1].d));     ;}
    break;

  case 259:
#line 2652 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 260:
#line 2653 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 261:
#line 2654 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-3].d)*(yyvsp[-3].d)+(yyvsp[-1].d)*(yyvsp[-1].d)); ;}
    break;

  case 262:
#line 2655 "Gmsh.y"
    { (yyval.d) = (yyvsp[-1].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 263:
#line 2664 "Gmsh.y"
    { (yyval.d) = (yyvsp[0].d); ;}
    break;

  case 264:
#line 2665 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 265:
#line 2666 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->rank(); ;}
    break;

  case 266:
#line 2667 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->size(); ;}
    break;

  case 267:
#line 2668 "Gmsh.y"
    { (yyval.d) = GMSH_MAJOR_VERSION; ;}
    break;

  case 268:
#line 2669 "Gmsh.y"
    { (yyval.d) = GMSH_MINOR_VERSION; ;}
    break;

  case 269:
#line 2670 "Gmsh.y"
    { (yyval.d) = GMSH_PATCH_VERSION; ;}
    break;

  case 270:
#line 2675 "Gmsh.y"
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

  case 271:
#line 2688 "Gmsh.y"
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

  case 272:
#line 2708 "Gmsh.y"
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

  case 273:
#line 2722 "Gmsh.y"
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

  case 274:
#line 2735 "Gmsh.y"
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

  case 275:
#line 2758 "Gmsh.y"
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

  case 276:
#line 2776 "Gmsh.y"
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

  case 277:
#line 2794 "Gmsh.y"
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

  case 278:
#line 2812 "Gmsh.y"
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

  case 279:
#line 2830 "Gmsh.y"
    { 
      (yyval.d) = GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    ;}
    break;

  case 280:
#line 2838 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    ;}
    break;

  case 281:
#line 2842 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    ;}
    break;

  case 282:
#line 2846 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    ;}
    break;

  case 283:
#line 2850 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    ;}
    break;

  case 284:
#line 2854 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    ;}
    break;

  case 285:
#line 2861 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    ;}
    break;

  case 286:
#line 2865 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 287:
#line 2869 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 288:
#line 2873 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 289:
#line 2880 "Gmsh.y"
    {
    ;}
    break;

  case 290:
#line 2883 "Gmsh.y"
    {
       (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 291:
#line 2887 "Gmsh.y"
    {
       (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 292:
#line 2894 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    ;}
    break;

  case 293:
#line 2899 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    ;}
    break;

  case 294:
#line 2907 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    ;}
    break;

  case 295:
#line 2912 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[0].l);
    ;}
    break;

  case 296:
#line 2916 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 297:
#line 2921 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 298:
#line 2925 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
      double *pd;
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 299:
#line 2937 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d)); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 300:
#line 2943 "Gmsh.y"
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

  case 301:
#line 2954 "Gmsh.y"
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

  case 302:
#line 2974 "Gmsh.y"
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

  case 303:
#line 2984 "Gmsh.y"
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

  case 304:
#line 2994 "Gmsh.y"
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

  case 305:
#line 3004 "Gmsh.y"
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

  case 306:
#line 3021 "Gmsh.y"
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

  case 307:
#line 3040 "Gmsh.y"
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

  case 308:
#line 3064 "Gmsh.y"
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

  case 309:
#line 3093 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    ;}
    break;

  case 310:
#line 3098 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[0].l);
    ;}
    break;

  case 311:
#line 3102 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    ;}
    break;

  case 312:
#line 3106 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    ;}
    break;

  case 313:
#line 3119 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    ;}
    break;

  case 314:
#line 3123 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    ;}
    break;

  case 315:
#line 3135 "Gmsh.y"
    {
      int flag;
      (yyval.u) = Get_ColorForString(ColorString, -1, (yyvsp[0].c), &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    ;}
    break;

  case 316:
#line 3142 "Gmsh.y"
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

  case 317:
#line 3164 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 318:
#line 3168 "Gmsh.y"
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

  case 319:
#line 3183 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    ;}
    break;

  case 320:
#line 3188 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    ;}
    break;

  case 321:
#line 3195 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[0].c);
    ;}
    break;

  case 322:
#line 3199 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32*sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 323:
#line 3207 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-3].c))+strlen((yyvsp[-1].c))+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-3].c));
      strcat((yyval.c), (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    ;}
    break;

  case 324:
#line 3215 "Gmsh.y"
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

  case 325:
#line 3229 "Gmsh.y"
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

  case 326:
#line 3243 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[-1].c);
    ;}
    break;

  case 327:
#line 3247 "Gmsh.y"
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

  case 328:
#line 3266 "Gmsh.y"
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

  case 329:
#line 3288 "Gmsh.y"
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
#line 7244 "Gmsh.tab.cpp"

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


#line 3311 "Gmsh.y"


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

