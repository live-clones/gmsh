/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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

/* Bison version.  */
#define YYBISON_VERSION "2.1"

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
     tCombine = 335,
     tBSpline = 336,
     tBezier = 337,
     tNurbs = 338,
     tOrder = 339,
     tWith = 340,
     tBounds = 341,
     tKnots = 342,
     tColor = 343,
     tColorTable = 344,
     tFor = 345,
     tIn = 346,
     tEndFor = 347,
     tIf = 348,
     tEndIf = 349,
     tExit = 350,
     tReturn = 351,
     tCall = 352,
     tFunction = 353,
     tTrimmed = 354,
     tShow = 355,
     tHide = 356,
     tGetValue = 357,
     tGMSH_MAJOR_VERSION = 358,
     tGMSH_MINOR_VERSION = 359,
     tGMSH_PATCH_VERSION = 360,
     tAFFECTDIVIDE = 361,
     tAFFECTTIMES = 362,
     tAFFECTMINUS = 363,
     tAFFECTPLUS = 364,
     tOR = 365,
     tAND = 366,
     tAPPROXEQUAL = 367,
     tNOTEQUAL = 368,
     tEQUAL = 369,
     tGREATEROREQUAL = 370,
     tLESSOREQUAL = 371,
     tCROSSPRODUCT = 372,
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
#define tCombine 335
#define tBSpline 336
#define tBezier 337
#define tNurbs 338
#define tOrder 339
#define tWith 340
#define tBounds 341
#define tKnots 342
#define tColor 343
#define tColorTable 344
#define tFor 345
#define tIn 346
#define tEndFor 347
#define tIf 348
#define tEndIf 349
#define tExit 350
#define tReturn 351
#define tCall 352
#define tFunction 353
#define tTrimmed 354
#define tShow 355
#define tHide 356
#define tGetValue 357
#define tGMSH_MAJOR_VERSION 358
#define tGMSH_MINOR_VERSION 359
#define tGMSH_PATCH_VERSION 360
#define tAFFECTDIVIDE 361
#define tAFFECTTIMES 362
#define tAFFECTMINUS 363
#define tAFFECTPLUS 364
#define tOR 365
#define tAND 366
#define tAPPROXEQUAL 367
#define tNOTEQUAL 368
#define tEQUAL 369
#define tGREATEROREQUAL 370
#define tLESSOREQUAL 371
#define tCROSSPRODUCT 372
#define UNARYPREC 373
#define tMINUSMINUS 374
#define tPLUSPLUS 375




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// $Id: Gmsh.tab.cpp,v 1.257 2006-02-24 22:07:06 geuzaine Exp $
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
#include "Timer.h"
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

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
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
/* Line 196 of yacc.c.  */
#line 412 "Gmsh.tab.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 424 "Gmsh.tab.cpp"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
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
	  YYSIZE_T yyi;				\
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
#define YYLAST   6005

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  140
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  64
/* YYNRULES -- Number of rules. */
#define YYNRULES  327
/* YYNRULES -- Number of states. */
#define YYNSTATES  1178

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   375

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   126,     2,   136,     2,   124,     2,     2,
     131,   132,   122,   120,   137,   121,   135,   123,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     116,     2,   117,   110,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   133,     2,   134,   130,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   138,     2,   139,     2,     2,     2,     2,
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
     105,   106,   107,   108,   109,   111,   112,   113,   114,   115,
     118,   119,   125,   127,   128,   129
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    46,    54,    61,    70,    71,    74,    77,    80,    83,
      86,    88,    92,    94,    98,    99,   100,   111,   113,   117,
     118,   132,   134,   138,   139,   155,   164,   165,   172,   174,
     176,   178,   180,   182,   184,   186,   191,   199,   209,   216,
     223,   227,   234,   241,   251,   258,   268,   274,   283,   292,
     304,   311,   321,   331,   341,   349,   358,   371,   378,   386,
     394,   402,   412,   420,   430,   448,   456,   464,   476,   485,
     498,   507,   516,   525,   538,   561,   582,   591,   600,   609,
     617,   626,   632,   644,   650,   660,   662,   664,   666,   667,
     670,   677,   684,   691,   698,   703,   710,   717,   724,   729,
     736,   740,   745,   751,   755,   759,   764,   769,   773,   781,
     789,   793,   801,   805,   808,   811,   827,   830,   837,   846,
     855,   866,   868,   871,   873,   877,   882,   884,   890,   902,
     916,   917,   925,   926,   940,   941,   957,   966,   975,   984,
     997,  1010,  1023,  1038,  1053,  1068,  1069,  1082,  1083,  1096,
    1097,  1110,  1111,  1128,  1129,  1146,  1147,  1164,  1165,  1184,
    1185,  1204,  1205,  1224,  1226,  1229,  1239,  1247,  1250,  1257,
    1267,  1277,  1286,  1296,  1305,  1314,  1321,  1326,  1329,  1332,
    1334,  1338,  1341,  1344,  1347,  1351,  1355,  1359,  1363,  1367,
    1371,  1375,  1379,  1383,  1387,  1391,  1395,  1399,  1403,  1409,
    1414,  1419,  1424,  1429,  1434,  1439,  1444,  1449,  1454,  1459,
    1466,  1471,  1476,  1481,  1486,  1491,  1496,  1503,  1510,  1517,
    1522,  1527,  1532,  1537,  1542,  1547,  1552,  1557,  1562,  1567,
    1572,  1579,  1584,  1589,  1594,  1599,  1604,  1609,  1616,  1623,
    1630,  1635,  1637,  1639,  1641,  1643,  1645,  1647,  1649,  1651,
    1656,  1661,  1664,  1670,  1674,  1681,  1686,  1694,  1701,  1703,
    1706,  1709,  1713,  1717,  1729,  1739,  1747,  1755,  1756,  1760,
    1764,  1766,  1770,  1772,  1774,  1777,  1781,  1786,  1790,  1796,
    1801,  1803,  1805,  1807,  1811,  1816,  1823,  1831,  1833,  1835,
    1839,  1843,  1853,  1861,  1863,  1869,  1873,  1880,  1882,  1886,
    1888,  1890,  1897,  1902,  1907,  1912,  1919,  1926
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     141,     0,    -1,   142,    -1,     1,     6,    -1,    -1,   142,
     143,    -1,   145,    -1,   144,    -1,   163,    -1,   164,    -1,
     165,    -1,   168,    -1,   169,    -1,   170,    -1,   171,    -1,
     174,    -1,   189,    -1,   190,    -1,   173,    -1,   172,    -1,
      33,   131,     5,   132,     6,    -1,    33,   131,     5,   137,
     199,   132,     6,    -1,     4,     5,   138,   146,   139,     6,
      -1,     4,     5,     4,   193,   138,   146,   139,     6,    -1,
      -1,   146,   149,    -1,   146,   153,    -1,   146,   156,    -1,
     146,   158,    -1,   146,   159,    -1,   191,    -1,   147,   137,
     191,    -1,   191,    -1,   148,   137,   191,    -1,    -1,    -1,
       4,   150,   131,   147,   132,   151,   138,   148,   139,     6,
      -1,   203,    -1,   152,   137,   203,    -1,    -1,    76,   131,
     191,   137,   191,   137,   191,   132,   154,   138,   152,   139,
       6,    -1,   203,    -1,   155,   137,   203,    -1,    -1,    77,
     131,   191,   137,   191,   137,   191,   137,   191,   132,   157,
     138,   155,   139,     6,    -1,    78,   138,   196,   139,   138,
     196,   139,     6,    -1,    -1,    79,   160,   138,   148,   139,
       6,    -1,     7,    -1,   109,    -1,   108,    -1,   107,    -1,
     106,    -1,   129,    -1,   128,    -1,     4,   161,   191,     6,
      -1,     4,   133,   191,   134,   161,   191,     6,    -1,     4,
     133,   138,   199,   139,   134,   161,   197,     6,    -1,     4,
     133,   134,     7,   197,     6,    -1,     4,   133,   134,   109,
     197,     6,    -1,     4,   162,     6,    -1,     4,   133,   191,
     134,   162,     6,    -1,     4,   135,     4,     7,   203,     6,
      -1,     4,   133,   191,   134,   135,     4,     7,   203,     6,
      -1,     4,   135,     4,   161,   191,     6,    -1,     4,   133,
     191,   134,   135,     4,   161,   191,     6,    -1,     4,   135,
       4,   162,     6,    -1,     4,   133,   191,   134,   135,     4,
     162,     6,    -1,     4,   135,    88,   135,     4,     7,   200,
       6,    -1,     4,   133,   191,   134,   135,    88,   135,     4,
       7,   200,     6,    -1,     4,   135,    89,     7,   201,     6,
      -1,     4,   133,   191,   134,   135,    89,     7,   201,     6,
      -1,    60,   131,     4,   132,   135,     4,     7,   191,     6,
      -1,    60,   131,     4,   132,   135,     4,     7,   203,     6,
      -1,    41,   131,   191,   132,     7,   193,     6,    -1,    56,
      41,   131,   191,   132,     7,   197,     6,    -1,    72,    41,
     197,     7,   138,   191,   137,   191,   137,   191,   139,     6,
      -1,    48,    49,   197,     7,   191,     6,    -1,    44,   131,
     191,   132,     7,   197,     6,    -1,    46,   131,   191,   132,
       7,   197,     6,    -1,    42,   131,   191,   132,     7,   197,
       6,    -1,    42,   131,   191,   132,     7,   197,    52,   193,
       6,    -1,    43,   131,   191,   132,     7,   197,     6,    -1,
      43,   131,   191,   132,     7,   197,    52,   193,     6,    -1,
      50,   131,   191,   132,     7,   138,   191,   137,   191,   137,
       5,   137,     5,   137,     5,   139,     6,    -1,    81,   131,
     191,   132,     7,   197,     6,    -1,    82,   131,   191,   132,
       7,   197,     6,    -1,    83,   131,   191,   132,     7,   197,
      87,   197,    84,   191,     6,    -1,    44,    67,   131,   191,
     132,     7,   197,     6,    -1,    72,    44,   197,     7,   138,
     191,   137,   191,   137,   191,   139,     6,    -1,    56,    44,
     131,   191,   132,     7,   197,     6,    -1,    52,    45,   131,
     191,   132,     7,   197,     6,    -1,    53,    45,   131,   191,
     132,     7,   197,     6,    -1,    99,    45,   131,   191,   132,
       7,   138,   191,   137,   197,   139,     6,    -1,    83,    45,
      85,    86,   131,   191,   132,     7,   195,    87,   138,   197,
     137,   197,   139,    84,   138,   191,   137,   191,   139,     6,
      -1,    83,    45,   131,   191,   132,     7,   195,    87,   138,
     197,   137,   197,   139,    84,   138,   191,   137,   191,   139,
       6,    -1,    45,    67,   131,   191,   132,     7,   197,     6,
      -1,    56,    45,   131,   191,   132,     7,   197,     6,    -1,
      55,    47,   131,   191,   132,     7,   197,     6,    -1,    47,
     131,   191,   132,     7,   197,     6,    -1,    56,    47,   131,
     191,   132,     7,   197,     6,    -1,    62,   193,   138,   166,
     139,    -1,    61,   138,   193,   137,   193,   137,   191,   139,
     138,   166,   139,    -1,    63,   193,   138,   166,   139,    -1,
      64,   138,   193,   137,   191,   139,   138,   166,   139,    -1,
     168,    -1,   167,    -1,   165,    -1,    -1,   167,   164,    -1,
     167,    41,   138,   199,   139,     6,    -1,   167,    44,   138,
     199,   139,     6,    -1,   167,    45,   138,   199,   139,     6,
      -1,   167,    47,   138,   199,   139,     6,    -1,    66,   138,
     167,   139,    -1,    66,     4,   133,   191,   134,     6,    -1,
      74,     4,   133,   191,   134,     6,    -1,    75,     4,   133,
     191,   134,     6,    -1,    69,   138,   167,   139,    -1,    69,
       4,   133,   191,   134,     6,    -1,    69,     4,     6,    -1,
      69,     4,     4,     6,    -1,    88,   200,   138,   167,   139,
      -1,   100,   203,     6,    -1,   101,   203,     6,    -1,   100,
     138,   167,   139,    -1,   101,   138,   167,   139,    -1,     4,
     203,     6,    -1,     4,     4,   133,   191,   134,   203,     6,
      -1,     4,     4,     4,   133,   191,   134,     6,    -1,     4,
     191,     6,    -1,    60,   131,     4,   132,   135,     4,     6,
      -1,    80,     4,     6,    -1,    95,     6,    -1,    38,     6,
      -1,    38,   138,   191,   137,   191,   137,   191,   137,   191,
     137,   191,   137,   191,   139,     6,    -1,    39,     6,    -1,
      90,   131,   191,     8,   191,   132,    -1,    90,   131,   191,
       8,   191,     8,   191,   132,    -1,    90,     4,    91,   138,
     191,     8,   191,   139,    -1,    90,     4,    91,   138,   191,
       8,   191,     8,   191,   139,    -1,    92,    -1,    98,     4,
      -1,    96,    -1,    97,     4,     6,    -1,    93,   131,   191,
     132,    -1,    94,    -1,    65,   193,   138,   167,   139,    -1,
      65,   138,   193,   137,   193,   137,   191,   139,   138,   167,
     139,    -1,    65,   138,   193,   137,   193,   137,   193,   137,
     191,   139,   138,   167,   139,    -1,    -1,    65,   193,   138,
     167,   175,   187,   139,    -1,    -1,    65,   138,   193,   137,
     193,   137,   191,   139,   138,   167,   176,   187,   139,    -1,
      -1,    65,   138,   193,   137,   193,   137,   193,   137,   191,
     139,   138,   167,   177,   187,   139,    -1,    65,    41,   138,
     191,   137,   193,   139,     6,    -1,    65,    44,   138,   191,
     137,   193,   139,     6,    -1,    65,    45,   138,   191,   137,
     193,   139,     6,    -1,    65,    41,   138,   191,   137,   193,
     137,   193,   137,   191,   139,     6,    -1,    65,    44,   138,
     191,   137,   193,   137,   193,   137,   191,   139,     6,    -1,
      65,    45,   138,   191,   137,   193,   137,   193,   137,   191,
     139,     6,    -1,    65,    41,   138,   191,   137,   193,   137,
     193,   137,   193,   137,   191,   139,     6,    -1,    65,    44,
     138,   191,   137,   193,   137,   193,   137,   193,   137,   191,
     139,     6,    -1,    65,    45,   138,   191,   137,   193,   137,
     193,   137,   193,   137,   191,   139,     6,    -1,    -1,    65,
      41,   138,   191,   137,   193,   139,   178,   138,   187,   139,
       6,    -1,    -1,    65,    44,   138,   191,   137,   193,   139,
     179,   138,   187,   139,     6,    -1,    -1,    65,    45,   138,
     191,   137,   193,   139,   180,   138,   187,   139,     6,    -1,
      -1,    65,    41,   138,   191,   137,   193,   137,   193,   137,
     191,   139,   181,   138,   187,   139,     6,    -1,    -1,    65,
      44,   138,   191,   137,   193,   137,   193,   137,   191,   139,
     182,   138,   187,   139,     6,    -1,    -1,    65,    45,   138,
     191,   137,   193,   137,   193,   137,   191,   139,   183,   138,
     187,   139,     6,    -1,    -1,    65,    41,   138,   191,   137,
     193,   137,   193,   137,   193,   137,   191,   139,   184,   138,
     187,   139,     6,    -1,    -1,    65,    44,   138,   191,   137,
     193,   137,   193,   137,   193,   137,   191,   139,   185,   138,
     187,   139,     6,    -1,    -1,    65,    45,   138,   191,   137,
     193,   137,   193,   137,   193,   137,   191,   139,   186,   138,
     187,   139,     6,    -1,   188,    -1,   187,   188,    -1,    73,
     138,   197,   137,   197,   137,   197,   139,     6,    -1,    73,
     138,   197,   137,   197,   139,     6,    -1,    68,     6,    -1,
      54,    44,   197,     7,   191,     6,    -1,    54,    44,   197,
       7,   191,    57,    59,   191,     6,    -1,    54,    44,   197,
       7,   191,    57,    58,   191,     6,    -1,    54,    45,   138,
     191,   139,     7,   197,     6,    -1,    54,    45,   138,   191,
     139,     7,   197,     4,     6,    -1,    51,    45,   138,   191,
     139,     7,   197,     6,    -1,    54,    47,   138,   191,   139,
       7,   197,     6,    -1,    68,    45,   197,     7,   191,     6,
      -1,    68,    45,   197,     6,    -1,    70,     6,    -1,    71,
       6,    -1,   192,    -1,   131,   191,   132,    -1,   121,   191,
      -1,   120,   191,    -1,   126,   191,    -1,   191,   121,   191,
      -1,   191,   120,   191,    -1,   191,   122,   191,    -1,   191,
     123,   191,    -1,   191,   124,   191,    -1,   191,   130,   191,
      -1,   191,   116,   191,    -1,   191,   117,   191,    -1,   191,
     119,   191,    -1,   191,   118,   191,    -1,   191,   115,   191,
      -1,   191,   114,   191,    -1,   191,   112,   191,    -1,   191,
     111,   191,    -1,   191,   110,   191,     8,   191,    -1,    12,
     131,   191,   132,    -1,    13,   131,   191,   132,    -1,    14,
     131,   191,   132,    -1,    15,   131,   191,   132,    -1,    16,
     131,   191,   132,    -1,    17,   131,   191,   132,    -1,    18,
     131,   191,   132,    -1,    19,   131,   191,   132,    -1,    20,
     131,   191,   132,    -1,    22,   131,   191,   132,    -1,    23,
     131,   191,   137,   191,   132,    -1,    24,   131,   191,   132,
      -1,    25,   131,   191,   132,    -1,    26,   131,   191,   132,
      -1,    27,   131,   191,   132,    -1,    28,   131,   191,   132,
      -1,    29,   131,   191,   132,    -1,    30,   131,   191,   137,
     191,   132,    -1,    31,   131,   191,   137,   191,   132,    -1,
      32,   131,   191,   137,   191,   132,    -1,    21,   131,   191,
     132,    -1,    12,   133,   191,   134,    -1,    13,   133,   191,
     134,    -1,    14,   133,   191,   134,    -1,    15,   133,   191,
     134,    -1,    16,   133,   191,   134,    -1,    17,   133,   191,
     134,    -1,    18,   133,   191,   134,    -1,    19,   133,   191,
     134,    -1,    20,   133,   191,   134,    -1,    22,   133,   191,
     134,    -1,    23,   133,   191,   137,   191,   134,    -1,    24,
     133,   191,   134,    -1,    25,   133,   191,   134,    -1,    26,
     133,   191,   134,    -1,    27,   133,   191,   134,    -1,    28,
     133,   191,   134,    -1,    29,   133,   191,   134,    -1,    30,
     133,   191,   137,   191,   134,    -1,    31,   133,   191,   137,
     191,   134,    -1,    32,   133,   191,   137,   191,   134,    -1,
      21,   133,   191,   134,    -1,     3,    -1,     9,    -1,    10,
      -1,    11,    -1,   103,    -1,   104,    -1,   105,    -1,     4,
      -1,     4,   133,   191,   134,    -1,   136,     4,   133,   134,
      -1,     4,   162,    -1,     4,   133,   191,   134,   162,    -1,
       4,   135,     4,    -1,     4,   133,   191,   134,   135,     4,
      -1,     4,   135,     4,   162,    -1,     4,   133,   191,   134,
     135,     4,   162,    -1,   102,   131,     5,   137,   191,   132,
      -1,   194,    -1,   121,   193,    -1,   120,   193,    -1,   193,
     121,   193,    -1,   193,   120,   193,    -1,   138,   191,   137,
     191,   137,   191,   137,   191,   137,   191,   139,    -1,   138,
     191,   137,   191,   137,   191,   137,   191,   139,    -1,   138,
     191,   137,   191,   137,   191,   139,    -1,   131,   191,   137,
     191,   137,   191,   132,    -1,    -1,   138,   196,   139,    -1,
     131,   196,   132,    -1,   197,    -1,   196,   137,   197,    -1,
     191,    -1,   198,    -1,   138,   139,    -1,   138,   199,   139,
      -1,   121,   138,   199,   139,    -1,   191,     8,   191,    -1,
     191,     8,   191,     8,   191,    -1,    41,   138,   191,   139,
      -1,   165,    -1,   168,    -1,   174,    -1,     4,   133,   134,
      -1,   121,     4,   133,   134,    -1,     4,   133,   138,   199,
     139,   134,    -1,   121,     4,   133,   138,   199,   139,   134,
      -1,   191,    -1,   198,    -1,   199,   137,   191,    -1,   199,
     137,   198,    -1,   138,   191,   137,   191,   137,   191,   137,
     191,   139,    -1,   138,   191,   137,   191,   137,   191,   139,
      -1,     4,    -1,     4,   135,    88,   135,     4,    -1,   138,
     202,   139,    -1,     4,   133,   191,   134,   135,    89,    -1,
     200,    -1,   202,   137,   200,    -1,     5,    -1,    40,    -1,
      35,   131,   203,   137,   203,   132,    -1,    36,   131,   203,
     132,    -1,    37,   131,   203,   132,    -1,    34,   131,   203,
     132,    -1,    34,   131,   203,   137,   199,   132,    -1,    34,
     131,     4,   135,     4,   132,    -1,    34,   131,     4,   133,
     191,   134,   135,     4,   132,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   144,   144,   145,   150,   152,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     173,   178,   196,   203,   214,   220,   221,   222,   223,   224,
     228,   230,   235,   237,   243,   433,   242,   461,   466,   475,
     474,   488,   493,   502,   501,   515,   524,   523,   535,   536,
     537,   538,   539,   543,   544,   551,   582,   621,   675,   692,
     710,   721,   740,   754,   771,   797,   824,   838,   855,   869,
     886,   906,   929,   939,   958,   974,   990,  1009,  1028,  1046,
    1064,  1082,  1108,  1126,  1152,  1172,  1196,  1220,  1246,  1263,
    1281,  1300,  1319,  1358,  1383,  1402,  1421,  1437,  1457,  1474,
    1491,  1512,  1517,  1522,  1527,  1535,  1536,  1537,  1542,  1545,
    1549,  1565,  1581,  1597,  1618,  1632,  1638,  1644,  1656,  1665,
    1675,  1689,  1708,  1722,  1730,  1736,  1747,  1761,  1805,  1820,
    1831,  1847,  1857,  1879,  1883,  1888,  1893,  1906,  1921,  1937,
    1963,  1990,  2022,  2029,  2034,  2040,  2044,  2053,  2061,  2069,
    2078,  2077,  2091,  2090,  2104,  2103,  2118,  2125,  2132,  2139,
    2146,  2153,  2160,  2167,  2174,  2182,  2181,  2194,  2193,  2206,
    2205,  2218,  2217,  2230,  2229,  2242,  2241,  2254,  2253,  2266,
    2265,  2278,  2277,  2293,  2296,  2302,  2328,  2352,  2361,  2379,
    2397,  2415,  2444,  2479,  2506,  2533,  2547,  2566,  2570,  2580,
    2581,  2582,  2583,  2584,  2585,  2586,  2587,  2588,  2595,  2596,
    2597,  2598,  2599,  2600,  2601,  2602,  2603,  2604,  2605,  2606,
    2607,  2608,  2609,  2610,  2611,  2612,  2613,  2614,  2615,  2616,
    2617,  2618,  2619,  2620,  2621,  2622,  2623,  2624,  2625,  2626,
    2628,  2629,  2630,  2631,  2632,  2633,  2634,  2635,  2636,  2637,
    2638,  2639,  2640,  2641,  2642,  2643,  2644,  2645,  2646,  2647,
    2648,  2657,  2658,  2659,  2660,  2661,  2662,  2663,  2667,  2680,
    2700,  2714,  2727,  2750,  2768,  2786,  2804,  2822,  2830,  2834,
    2838,  2842,  2846,  2853,  2857,  2861,  2865,  2873,  2875,  2879,
    2886,  2891,  2899,  2904,  2908,  2913,  2917,  2929,  2935,  2946,
    2966,  2976,  2986,  2996,  3013,  3032,  3056,  3085,  3090,  3094,
    3098,  3111,  3115,  3127,  3134,  3156,  3160,  3175,  3180,  3187,
    3191,  3199,  3207,  3221,  3235,  3239,  3258,  3280
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
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
  "tTime", "tCombine", "tBSpline", "tBezier", "tNurbs", "tOrder", "tWith",
  "tBounds", "tKnots", "tColor", "tColorTable", "tFor", "tIn", "tEndFor",
  "tIf", "tEndIf", "tExit", "tReturn", "tCall", "tFunction", "tTrimmed",
  "tShow", "tHide", "tGetValue", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tAFFECTDIVIDE",
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND",
  "tAPPROXEQUAL", "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL",
  "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "tCROSSPRODUCT",
  "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'",
  "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'", "$accept", "All",
  "GeoFormatItems", "GeoFormatItem", "Printf", "View", "Views",
  "ElementCoords", "ElementValues", "Element", "@1", "@2", "Text2DValues",
  "Text2D", "@3", "Text3DValues", "Text3D", "@4", "InterpolationMatrix",
  "Time", "@5", "NumericAffectation", "NumericIncrement", "Affectation",
  "Shape", "Transform", "MultipleShape", "ListOfShapes", "Duplicata",
  "Delete", "Colorify", "Visibility", "Command", "Loop", "Extrude", "@6",
  "@7", "@8", "@9", "@10", "@11", "@12", "@13", "@14", "@15", "@16", "@17",
  "ExtrudeParameters", "ExtrudeParameter", "Transfinite", "Coherence",
  "FExpr", "FExpr_Single", "VExpr", "VExpr_Single", "ListOfListOfDouble",
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
      63,   365,   366,   367,   368,   369,    60,    62,   370,   371,
      43,    45,    42,    47,    37,   372,    33,   373,   374,   375,
      94,    40,    41,    91,    93,    46,    35,    44,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   140,   141,   141,   142,   142,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     144,   144,   145,   145,   146,   146,   146,   146,   146,   146,
     147,   147,   148,   148,   150,   151,   149,   152,   152,   154,
     153,   155,   155,   157,   156,   158,   160,   159,   161,   161,
     161,   161,   161,   162,   162,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   165,   165,   165,   165,   166,   166,   166,   167,   167,
     167,   167,   167,   167,   168,   168,   168,   168,   169,   169,
     169,   169,   170,   171,   171,   171,   171,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   174,   174,   174,
     175,   174,   176,   174,   177,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   178,   174,   179,   174,   180,
     174,   181,   174,   182,   174,   183,   174,   184,   174,   185,
     174,   186,   174,   187,   187,   188,   188,   188,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   190,   190,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   193,   193,
     193,   193,   193,   194,   194,   194,   194,   195,   195,   195,
     196,   196,   197,   197,   197,   197,   197,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   199,   199,   199,
     199,   200,   200,   200,   200,   201,   201,   202,   202,   203,
     203,   203,   203,   203,   203,   203,   203,   203
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     7,     6,     8,     0,     2,     2,     2,     2,     2,
       1,     3,     1,     3,     0,     0,    10,     1,     3,     0,
      13,     1,     3,     0,    15,     8,     0,     6,     1,     1,
       1,     1,     1,     1,     1,     4,     7,     9,     6,     6,
       3,     6,     6,     9,     6,     9,     5,     8,     8,    11,
       6,     9,     9,     9,     7,     8,    12,     6,     7,     7,
       7,     9,     7,     9,    17,     7,     7,    11,     8,    12,
       8,     8,     8,    12,    22,    20,     8,     8,     8,     7,
       8,     5,    11,     5,     9,     1,     1,     1,     0,     2,
       6,     6,     6,     6,     4,     6,     6,     6,     4,     6,
       3,     4,     5,     3,     3,     4,     4,     3,     7,     7,
       3,     7,     3,     2,     2,    15,     2,     6,     8,     8,
      10,     1,     2,     1,     3,     4,     1,     5,    11,    13,
       0,     7,     0,    13,     0,    15,     8,     8,     8,    12,
      12,    12,    14,    14,    14,     0,    12,     0,    12,     0,
      12,     0,    16,     0,    16,     0,    16,     0,    18,     0,
      18,     0,    18,     1,     2,     9,     7,     2,     6,     9,
       9,     8,     9,     8,     8,     6,     4,     2,     2,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     6,     6,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     2,     5,     3,     6,     4,     7,     6,     1,     2,
       2,     3,     3,    11,     9,     7,     7,     0,     3,     3,
       1,     3,     1,     1,     2,     3,     4,     3,     5,     4,
       1,     1,     1,     3,     4,     6,     7,     1,     1,     3,
       3,     9,     7,     1,     5,     3,     6,     1,     3,     1,
       1,     6,     4,     4,     4,     6,     6,     9
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
       0,     0,     0,     0,     0,   141,     0,   146,     0,   143,
       0,     0,     0,     0,     0,     5,     7,     6,     8,     9,
      10,    11,    12,    13,    14,    19,    18,    15,    16,    17,
     261,   268,   319,    48,   262,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   320,     0,   265,   266,   267,    52,    51,    50,
      49,     0,     0,     0,    54,    53,     0,     0,     0,     0,
       0,     0,     0,   199,     0,     0,   134,     0,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,   108,
     197,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   313,     0,     0,     0,     0,     0,   133,     0,   142,
       0,   319,   108,     0,   108,     0,     0,     0,     0,   271,
       0,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
     202,   201,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     268,     0,     0,     0,   300,   301,   302,   292,     0,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   280,   279,     0,     0,     0,     0,
     108,   108,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,   120,     0,     0,     0,     0,
       0,     0,   132,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,   144,     0,     0,   123,     0,   124,
       0,     0,   273,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   200,     0,     0,     0,   307,   308,
       0,     0,    48,     0,     0,     0,     0,     0,    55,     0,
     217,   216,   215,   214,   210,   211,   213,   212,   205,   204,
     206,   207,   208,   209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,     0,   294,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282,
     281,   107,     0,   106,   105,     0,     0,     0,     0,     0,
       0,     0,   150,     0,     0,     0,     0,     0,   114,   109,
     196,     0,   121,     0,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
       0,   125,   126,     0,   269,   275,    24,    34,     0,     0,
       0,    46,     0,    25,    26,    27,    28,    29,   219,   240,
     220,   241,   221,   242,   222,   243,   223,   244,   224,   245,
     225,   246,   226,   247,   227,   248,   239,   260,   228,   249,
       0,     0,   230,   251,   231,   252,   232,   253,   233,   254,
     234,   255,   235,   256,     0,     0,     0,     0,     0,     0,
       0,     0,   324,     0,     0,   322,   323,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
       0,     0,     0,   270,     0,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   303,     0,     0,     0,
       0,   295,   297,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,   103,     0,     0,     0,     0,     0,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
       0,     0,     0,   272,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   269,    58,    59,   309,   310,
       0,     0,     0,     0,     0,    61,    62,    64,     0,     0,
     317,     0,    70,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   299,   304,     0,   296,     0,
      77,     0,     0,     0,     0,   188,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   115,     0,     0,
       0,     0,   195,   119,     0,     0,   116,   117,     0,     0,
       0,   287,     0,   314,     0,     0,     0,   137,     0,   129,
     274,   128,     0,     0,     0,     0,     0,   290,     0,   229,
     250,   236,   257,   237,   258,   238,   259,     0,   326,   325,
     321,   277,     0,    48,     0,     0,     0,     0,    56,     0,
       0,     0,   315,    21,     0,    74,    80,     0,    82,     0,
       0,    78,     0,    79,    99,     0,     0,   298,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,     0,     0,     0,   108,     0,   165,     0,
     167,     0,   169,     0,     0,   187,     0,   151,   184,     0,
       0,     0,     0,     0,     0,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   276,    23,     0,    30,
       0,     0,     0,     0,     0,    32,     0,     0,     0,     0,
      67,     0,     0,    68,     0,   318,     0,     0,     0,    88,
      96,   305,     0,     0,   193,    91,    92,     0,     0,     0,
     191,   194,    98,    75,    90,    97,   100,     0,     0,     0,
     286,     0,   285,     0,     0,   156,     0,     0,   157,     0,
       0,   158,     0,     0,     0,     0,   110,   111,   112,   113,
       0,     0,   287,     0,     0,     0,     0,     0,   312,     0,
     139,   138,     0,    35,     0,     0,     0,   291,     0,     0,
       0,     0,    57,    63,    65,     0,    71,     0,     0,    81,
      83,   306,     0,   190,   189,   192,    72,    73,   108,     0,
     104,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,     0,     0,   289,   288,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,    33,    47,   327,     0,   316,
       0,     0,     0,     0,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   152,     0,     0,     0,     0,     0,
       0,     0,   311,   140,     0,     0,     0,     0,     0,    69,
       0,     0,   102,     0,   171,     0,     0,   173,     0,     0,
     175,     0,     0,   148,     0,   108,     0,     0,     0,     0,
       0,     0,    87,     0,     0,    39,     0,    45,     0,     0,
     283,   159,     0,     0,   166,   160,     0,     0,   168,   161,
       0,     0,   170,     0,   154,     0,   186,    76,    89,     0,
       0,    93,     0,     0,     0,     0,     0,     0,   177,     0,
     179,     0,   181,   153,   149,     0,     0,     0,     0,    36,
       0,    43,     0,     0,     0,   162,     0,     0,   163,     0,
       0,   164,     0,     0,   185,     0,     0,     0,    37,     0,
     135,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,     0,     0,     0,     0,   172,     0,   174,     0,   176,
       0,     0,     0,    38,    40,     0,    41,    84,     0,     0,
       0,     0,     0,     0,     0,   178,   180,   182,     0,     0,
      42,    44,     0,     0,     0,    95,     0,    94
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     2,     3,    55,    56,    57,   364,   878,   884,   533,
     676,  1000,  1127,   534,  1093,  1155,   535,  1129,   536,   537,
     680,   120,   199,    58,   499,   294,   482,   483,   295,    62,
      63,    64,    65,    66,   296,   648,  1054,  1105,   926,   929,
     932,  1072,  1076,  1080,  1116,  1119,  1122,   755,   756,    68,
      69,   297,   123,   314,   157,   870,   786,   787,   299,   420,
     183,   602,   711,   124
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -837
static const short int yypact[] =
{
    2246,    47,    20,  2631,  -837,  -837,  1762,   -62,     4,    66,
     -37,   -28,   -14,   -32,    64,   -11,    34,    88,    56,   139,
     193,   212,   399,   227,   203,   153,   189,   343,   343,   210,
     271,     9,   317,    14,   388,   415,    72,   421,   429,   441,
     320,   337,   -33,    18,    19,  -837,   345,  -837,   476,  -837,
     483,   504,   482,     2,    26,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,    10,    21,  -837,  -837,  -837,  -837,   -86,   177,   206,
     230,   238,   326,   359,   431,   468,   474,   479,   532,   548,
     551,   552,   555,   556,   560,   561,   564,   568,   372,   385,
     390,   417,  -837,   425,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  1975,  1975,  1975,  -837,  -837,  1975,  1366,    30,   553,
    1975,   569,   789,  -837,   587,   562,  -837,  1975,  -837,  1975,
    1975,  1975,   473,  1975,   478,  1975,  1975,  1299,  1975,   459,
     493,   503,  1299,   501,   505,   511,   521,   535,   536,   539,
     610,   343,   343,   343,  1975,  1975,   -43,  -837,   168,   343,
     567,   609,   613,  1602,   226,   541,  -837,  1299,    13,  -837,
    -837,  -837,  1299,  1299,   545,   619,   774,  1975,  1975,   -45,
    1975,   563,  1975,   649,   697,  1975,  1975,  -837,   783,  -837,
     660,  -837,  -837,   786,  -837,   787,   661,  1975,   792,  -837,
     343,  -837,  1975,  1975,  1975,  1975,  1975,  1975,  1975,  1975,
    1975,  1975,  1975,  1975,  1975,  1975,  1975,  1975,  1975,  1975,
    1975,  1975,  1975,  1975,  1975,  1975,  1975,  1975,  1975,  1975,
    1975,  1975,  1975,  1975,  1975,  1975,  1975,  1975,  1975,  1975,
    1975,  1975,  1975,  1975,    39,   470,   470,   470,   795,   526,
     667,   667,   667,  4746,    17,  1811,  4095,   185,   666,   810,
     686,   815,  -837,  -837,  1975,  1975,  1975,  1975,  1975,  1975,
    1975,  1975,  1975,  1975,  1975,  1975,  1975,  1975,  1975,  -837,
      53,  2431,  4769,  4792,  4815,  1975,  4838,  1975,  4861,  4884,
     529,   682,  1632,  1165,  -837,  -837,  -837,  2049,   818,  -837,
    4907,  1975,  1975,  1975,   821,  1975,  1975,  1975,  1975,  1975,
    1975,  1975,   698,   268,  -837,  -837,  3255,  3279,   343,   343,
     574,   574,   333,  1975,  1975,  1975,  1602,  1602,  1975,   381,
    -837,  1975,  2307,   188,   823,  -837,  1975,  2328,   824,   825,
    1975,  1975,  -837,  4930,  4953,   747,  1975,  4976,   746,  3303,
    -837,   699,  2066,  4999,  -837,  1975,  2373,  -837,  2418,  -837,
    1975,  4116,   117,   261,     5,  5022,  4137,  5045,  4158,  5068,
    4179,  5091,  4200,  5114,  4221,  5137,  4242,  5160,  4263,  5183,
    4284,  5206,  4305,  5229,  4326,  5252,  4347,  3327,  3351,  5275,
    4368,  5298,  4389,  5321,  4410,  5344,  4431,  5367,  4452,  5390,
    4473,  3375,  3399,  3423,  3447,  3471,  3495,   461,   141,   702,
     703,   708,   704,  1975,  -837,  1299,  1299,  2005,  2049,  -837,
     565,   147,   470,  1975,   836,   839,    23,   710,  -837,  2083,
    1159,   762,   499,   499,   402,   402,   402,   402,   -65,   -65,
     667,   667,   667,   667,   840,  1811,  1975,   838,   841,   843,
    5413,   844,  5436,   845,   846,  1429,  1975,   540,  1811,  -837,
     585,  1975,  1975,   848,  2683,  5459,  5482,  1975,  2709,  2735,
    5505,  5528,  5551,  5574,  5597,   712,   343,  1975,  1975,  -837,
    -837,  -837,   720,   975,  -837,   721,  1975,  3519,  3543,  3567,
    2320,   343,  2439,  4494,   -67,   -46,   -41,   -51,  -837,  -837,
    -837,  1975,  -837,  4515,  -837,   723,   724,  4536,  4557,   856,
     857,   734,  5620,   859,   732,  1975,  2484,  1975,  1975,  -837,
    5643,  -837,  -837,  4578,   350,  -837,  -837,  -837,   737,   739,
     733,  -837,   867,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    1975,  1975,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  1975,  1975,  1975,  1975,  1975,  1975,
    1975,   884,  -837,  1811,   470,  -837,  -837,  1975,  4599,   883,
     887,  1811,   761,    89,  1975,   888,   890,   850,  -837,   895,
     781,    18,   910,  -837,  1975,  -837,   264,  3591,   343,  1299,
    1299,   911,  1299,   913,  1299,  1299,  -837,  1811,  2761,  1565,
     590,  -837,  2104,   970,   779,   914,   916,   917,   596,   933,
     935,   937,   939,   940,   942,   943,   947,   424,  3615,  3639,
    -837,  -837,  2787,   343,   343,   343,   426,  -837,    60,   946,
    1811,  1811,  1811,  1811,   997,   948,  1975,  1975,   949,   950,
    1299,  1299,  1975,   956,  1299,   974,  3663,  -837,  2121,   692,
     976,   981,   978,  -837,   982,    12,   858,  1975,  1975,  1299,
     853,  -837,  5666,  4620,  5689,  4641,  5712,  4662,  5735,  4683,
    4704,   860,   282,   861,  5758,     6,  -837,  -837,  2049,  -837,
     329,   244,   863,   987,  1030,  -837,  -837,  -837,    18,  1975,
    -837,   591,  -837,  2536,   989,  1975,    42,    48,    50,  1299,
     993,  1299,   994,   995,   594,  -837,  -837,  1811,  -837,  1975,
    -837,  1975,  1299,  1299,  1299,  -837,   354,  1299,  1299,  1299,
    1299,  1299,  1299,  1299,   492,  1975,  1975,  1975,   864,   -69,
     239,   376,  1602,  1000,   870,   -27,  -837,  -837,   595,   599,
     605,   606,  -837,  -837,  3687,  3711,  -837,  -837,  1003,  1004,
    5781,   -23,   925,  -837,  1975,  1975,  1975,  -837,   875,  -837,
     117,  -837,  1008,  1975,  3735,  3759,   623,  -837,  1975,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,   889,  -837,  -837,
    -837,  -837,  1299,   470,  1975,  1020,  1028,    23,  -837,  1027,
    4725,    18,  -837,  -837,  3783,  -837,  -837,   343,  -837,   343,
    1029,  -837,  1031,  -837,  -837,   900,   624,  2536,  3807,  1032,
    1034,  1035,  1975,  1975,   760,  1037,  1038,  1040,  1042,  1043,
    1044,  -837,  1940,  2813,  5804,  2143,   574,   343,  1045,   343,
    1046,   343,  1047,  2839,   439,  -837,  1299,  -837,  -837,  1048,
    1049,  1053,  1055,  1975,  1975,  -837,  -837,  1056,  1299,  1299,
     977,  1299,  2623,   419,  5827,  1975,  -837,  -837,   352,  2536,
    1975,  1975,  1299,   927,   628,  2536,  1063,  1062,  1064,  1093,
    -837,  1066,  1065,  -837,   934,  -837,  1975,    49,    61,  -837,
    -837,  -837,   941,  1975,  -837,  -837,  -837,  1132,  1227,  1072,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  1399,  1073,   945,
    -837,  1975,  -837,   957,   445,  -837,   959,   458,  -837,   960,
     463,  -837,   963,   964,  1975,   958,  -837,  -837,  -837,  -837,
    3831,  3855,   -23,   356,   634,   965,  1021,  1975,  -837,  1975,
    -837,  -837,  3879,  -837,  1975,  3903,  3927,  -837,  1299,  1975,
    1098,   990,  -837,  -837,  -837,    18,  -837,  1036,  3951,  -837,
    -837,  -837,  3975,  -837,  -837,  -837,  -837,  -837,   574,  2653,
    -837,  1602,    60,  1602,    60,  1602,    60,  -837,  2865,  1299,
    1975,  1975,  1023,  -837,  -837,  1299,  1975,  2891,  2917,  1299,
     986,  2536,  1975,  1975,   635,  2536,  -837,  -837,  1120,  -837,
    1975,  1123,   991,  1975,  -837,  2943,   466,    28,  2969,   469,
      36,  2995,   471,   217,  2529,   998,   639,  3021,  3047,  1005,
     992,  2032,  -837,  -837,   996,  1975,  5850,  3999,  1126,  -837,
    4023,  1025,  -837,  3073,  1151,  1975,  1152,  1158,  1975,  1161,
    1164,  1975,  1166,  -837,    60,  -837,  1299,  1167,  1192,  1193,
    1299,  1299,  -837,  1194,   642,  -837,  1975,  -837,  1975,  1196,
    -837,  -837,  1033,  3099,  -837,  -837,  1080,  3125,  -837,  -837,
    1081,  3151,  -837,   258,  2550,  1082,  -837,  -837,  -837,  1083,
    1085,  -837,  1216,  1087,  5873,  3177,  1095,    60,  1228,    60,
    1229,    60,  1230,  -837,  -837,    60,  1231,  1299,  1118,  -837,
     470,  -837,  1232,  1236,   265,  -837,  1107,   302,  -837,  1119,
     327,  -837,  1121,   330,  -837,  1122,  1125,   646,  -837,  1127,
    -837,  1133,  1252,    60,  1254,    60,  1258,    60,  -837,  1182,
    1975,   470,  1278,   470,  1281,  -837,   347,  -837,   355,  -837,
     361,  1150,  4047,  -837,  -837,   647,  -837,  -837,  1284,  1286,
    1287,  1975,  1975,   470,  1288,  -837,  -837,  -837,  4071,  3203,
    -837,  -837,  1975,  1292,  3229,  -837,  1294,  -837
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -837,  -837,  -837,  -837,  -837,  -837,   780,  -837,   270,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -253,    -5,  -837,  1304,     3,  -318,  -164,     8,  -837,
    -837,  -837,  -837,  -837,  1329,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -675,  -740,  -837,
    -837,    -6,  -837,   314,  -837,   391,  -836,    16,  -100,  -285,
    -572,   527,  -837,    -4
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const short int yytable[] =
{
     122,   121,   332,   485,   423,   337,    60,   191,   460,   527,
     126,    61,   179,   165,   196,   858,   527,   334,   168,   335,
       5,   132,   181,   184,   415,   200,   134,   600,   356,   710,
     358,   191,   943,   944,   257,   132,    98,    99,   100,   101,
     345,   753,   102,   407,   191,   202,   754,   203,   815,   193,
     195,   318,   319,     4,   816,   969,   818,   275,   276,   277,
      98,    99,   100,   101,   129,   278,   102,   970,   847,   125,
     848,   650,   128,    98,    99,   100,   101,   318,   319,   102,
     136,   528,   529,   530,   531,   133,   346,   653,   528,   529,
     530,   531,   651,   701,   129,   320,   753,   652,   180,   133,
     817,   754,   819,   130,   753,   250,   251,   252,   868,   754,
     253,   256,   857,   172,   261,   869,   173,   131,   258,   259,
     135,   281,  1004,   282,   283,   284,   416,   286,   753,   288,
     289,   134,   300,   754,   114,   115,   809,   137,   114,   115,
     192,   672,   127,   197,   532,   198,   336,   166,   316,   317,
     185,   782,   169,   298,    73,   419,   182,   317,   304,   201,
     606,   601,   318,   319,   194,   136,   492,  1046,   594,   318,
     319,   343,   344,   620,   347,  1049,   349,   702,   703,   352,
     353,   318,   319,   333,   139,   444,   516,   138,   338,   339,
     445,   361,   422,   419,   500,   501,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   140,   895,
     408,   409,   410,   411,   146,   114,   115,   147,   148,   418,
     149,   803,   424,   107,   108,   109,   110,   141,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   582,   145,   114,   115,   858,   583,   450,
     858,   452,   593,   858,   150,   753,   251,   418,   318,   319,
     754,   107,   108,   109,   110,   464,   465,   466,   692,   468,
     469,   470,   471,   472,   473,   474,   321,  1017,   204,  1020,
     205,  1023,   160,   114,   115,   161,   162,   487,   488,   489,
     250,   251,   490,   481,   481,   493,   753,   151,   484,   484,
     503,   754,   724,   753,   507,   508,    73,   206,   754,   207,
     512,   156,   158,   858,   164,   419,   318,   319,   159,   520,
     107,   108,   109,   110,   523,   191,  1052,   525,   419,   318,
     319,   208,   167,   209,   330,   758,   759,   760,   761,   210,
     753,   211,   114,   115,   858,   754,   849,   858,   850,  1083,
     858,   318,   319,   858,    98,    99,   100,   101,   318,   319,
     102,   152,   153,  1008,   170,   753,   714,  1103,   753,   526,
     754,   591,   154,   754,  1132,   476,   858,   588,   858,   163,
     858,   251,   832,   833,   799,   753,   595,   597,   596,   591,
     754,   171,  1114,   753,  1117,   174,  1120,   949,   754,   753,
    1123,   589,   590,   175,   754,   107,   108,   109,   110,   418,
     607,  1134,   826,   142,   143,   176,   144,   802,   804,   588,
     618,   177,   418,   318,   319,   622,   623,   212,  1146,   213,
    1148,   628,  1150,   152,   153,   313,  1136,   315,   178,  1138,
     486,   638,   639,   322,   154,   191,   186,   329,   114,   115,
     642,   155,   187,   419,   953,   672,  1158,   188,   993,   954,
     214,   699,   215,   882,  1159,   654,   318,   319,   841,   842,
    1160,   318,   319,   244,    98,    99,   100,   101,   189,   666,
     102,   668,   669,   851,   363,   852,   245,   419,   491,   673,
     674,   246,   273,   274,   275,   276,   277,   190,   923,   264,
     265,   266,   278,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   318,   319,   318,   319,   247,   278,
     419,   419,   419,   419,   682,   683,   248,   260,   950,   318,
     319,   745,   216,   752,   217,   318,   319,   280,   684,   685,
     686,   687,   688,   689,   690,   262,   934,   418,   318,   319,
     693,   694,   981,   318,   319,   698,   318,   319,   704,   318,
     319,   318,   319,   279,   580,   983,   581,   301,   713,   218,
     985,   219,   735,  1045,   285,   220,  1048,   221,  1051,   287,
     222,   418,   223,   588,   312,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   302,   717,   718,   419,   720,   278,
     722,   723,   479,   480,   303,    26,    27,    28,    29,   305,
      31,   315,   307,   306,   418,   418,   418,   418,    37,    38,
     764,   765,   308,   736,   114,   115,   770,   114,   115,   413,
    1012,   198,   455,   224,   198,   225,   309,   310,   114,   115,
     311,   784,   785,   619,   331,   198,   768,   769,   340,   226,
     772,   227,   228,   230,   229,   231,   232,   234,   233,   235,
     673,   236,   238,   237,   239,   240,   805,   241,   348,   242,
     776,   243,   591,   810,   592,   323,   264,   265,   266,   814,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   418,   591,   827,   621,   828,   278,   591,   811,   728,
     812,   591,   591,   825,   859,   820,   591,   822,   860,   843,
     844,   845,   591,   591,   861,   862,   853,   324,   829,   830,
     831,   325,   341,   834,   835,   836,   837,   838,   839,   840,
     882,   591,   883,   902,   909,   959,   910,   960,   872,   873,
     874,   882,   882,   994,  1038,   876,  1056,   879,  1057,   959,
     342,  1092,   885,  1141,  1163,  1142,  1164,   350,   351,   354,
     637,   355,   357,   359,   360,   263,   362,   278,   889,   888,
     412,   425,   264,   265,   266,   646,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   426,   887,   427,
     456,   428,   278,  1024,   777,   462,   907,   908,   467,   502,
     475,   505,   506,   511,   514,   585,   917,   517,   918,   584,
     586,   587,   598,   599,   603,   608,   605,   636,   609,   481,
     610,   612,   614,   615,   484,   624,   707,   940,   941,   640,
     641,   656,   657,   660,   661,   662,   664,   665,   677,   952,
     678,   679,   935,   681,   955,   956,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   946,   691,   696,
     968,  1084,   278,   697,   705,   700,   706,   972,   957,   264,
     265,   266,   708,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   709,   979,   712,   731,   719,   278,
     721,   732,   716,   733,   734,   264,   265,   266,   988,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     737,   997,   738,   998,   739,   278,   740,   741,  1001,   742,
     743,   744,   757,  1005,   763,   766,   767,   749,   750,   751,
     264,   265,   266,   771,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,  1015,   730,  1018,   773,  1021,
     278,   481,   780,   778,  1027,  1028,   484,   779,   781,   783,
    1031,   788,   798,   800,   807,   813,  1036,  1037,   806,   821,
     823,   824,   846,   762,  1040,  1026,   855,  1043,   856,   865,
     866,  1030,   871,   875,   877,  1034,   494,    11,    12,   495,
     496,    15,   497,    17,   886,    18,   890,    20,    21,   885,
      23,    24,   891,   893,   901,   899,   808,   900,   904,  1073,
     905,   906,  1077,   911,   912,  1081,   913,    36,   914,   915,
     916,   925,   928,   931,   936,   937,    40,    41,    42,   938,
    1094,   939,  1095,   942,   945,   958,   854,   961,   962,   967,
     963,   966,  1085,   965,    52,   971,  1089,  1090,   975,   977,
     264,   265,   266,   978,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   989,   980,   982,   984,   964,
     278,   986,   987,   995,  1006,   996,  1128,   264,   265,   266,
    1029,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,  1007,  1125,  1035,  1009,  1039,   278,  1041,  1061,
    1042,   897,  1067,   898,  1152,  1063,  1055,  1153,   973,  1156,
     264,   265,   266,  1060,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,  1168,  1169,  1071,  1074,  1170,
     278,   924,  1069,   927,  1075,   930,  1174,  1078,    70,   290,
    1079,  1097,  1082,  1086,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,  1087,  1088,
    1091,  1096,  1126,   264,   265,   266,   291,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,  1099,  1101,
    1107,  1106,  1109,   278,  1108,  1110,    26,    27,    28,    29,
      30,    31,  1113,   974,  1115,  1118,  1121,  1124,  1130,    37,
      38,  1131,   264,   265,   266,  1133,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,  1135,  1145,  1137,
    1147,  1139,   278,  1140,  1149,  1143,  1151,   103,   104,   105,
     106,   266,  1144,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,  1154,   111,   417,  1157,  1161,   278,
    1165,   113,  1166,  1167,  1171,  1016,   116,  1019,  1175,  1022,
    1177,   119,    70,   290,   459,  1064,   675,    59,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    67,   992,   892,     0,     0,   264,   265,   266,
     291,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
      26,    27,    28,    29,    30,    31,     0,     0,     0,    70,
     249,     0,     0,    37,    38,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,     0,
       0,   103,   104,   105,   106,   976,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     292,     0,     0,     0,     0,   113,     0,     0,     0,     0,
     116,     0,    70,   249,     0,   119,     0,   293,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,   112,     0,     0,
       0,     0,   113,     0,     0,     0,     0,   116,     0,     0,
     254,     0,   119,     0,   255,     0,     0,     0,     0,   264,
     265,   266,     0,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,   103,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,     0,   113,     0,     0,     0,     0,
     116,     0,     0,   616,     0,   119,     0,   617,    70,   249,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,     0,    70,   249,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    70,   457,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,     0,     0,   103,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,   112,     0,     0,     0,
       0,   113,     0,     0,     0,     0,   116,     0,     0,   726,
       0,   119,     0,   727,   103,   104,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   326,   327,     0,     0,     0,     0,   113,     0,
       0,     0,     0,   328,   103,   104,   105,   106,   119,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   112,     0,     0,     0,     0,   113,     0,
       0,     0,     0,   116,     0,    70,    71,    72,   119,    73,
     458,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,     0,    98,    99,   100,   101,
       0,     0,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,   290,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
       0,     0,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,   105,   106,   107,   108,
     109,   110,    26,    27,    28,    29,    30,    31,     0,     0,
       0,     0,   111,   112,     0,    37,    38,     0,   113,     0,
     114,   115,     0,   116,     0,   117,     0,   118,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,   417,     0,     0,     0,     0,   113,     0,     0,
       0,     0,   116,    70,   249,   191,     0,   119,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,     0,    98,    99,   100,   101,    70,   249,
     102,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    70,   457,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,  1062,     0,
       0,     0,   103,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   461,     0,     0,
     111,   112,     0,     0,     0,     0,   113,     0,     0,     0,
       0,   116,     0,     0,   518,     0,   119,   103,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   604,     0,     0,     0,   111,   112,     0,     0,     0,
       0,   113,     0,     0,     0,     0,   116,   103,   104,   105,
     106,   119,   729,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,   112,     0,     0,   775,
       0,   113,     0,     0,     0,     0,   116,     0,     0,     0,
       0,   119,   264,   265,   266,     0,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,   264,
     265,   266,   278,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,   264,   265,   266,   278,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,   264,   265,   266,   278,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,   264,   265,   266,     0,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,   264,   265,   266,   278,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,    -4,     1,     0,     0,
      -4,   278,     0,   264,   265,   266,     0,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,    -4,
     921,     0,   922,     0,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
       0,     0,     0,     0,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,   494,    11,
      12,   495,   496,    15,   497,    17,     0,    18,     0,    20,
      21,     0,    23,    24,     0,     0,     0,     0,     0,   494,
      11,    12,   495,   496,    15,   497,    17,     0,    18,    36,
      20,    21,     0,    23,    24,     0,     0,     0,    40,    41,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,    52,     0,     0,    40,
      41,    42,     0,     0,   494,    11,    12,   495,   496,    15,
     497,    17,     0,    18,     0,    20,    21,    52,    23,    24,
     264,   265,   266,     0,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,    36,   498,     0,     0,     0,
     278,     0,   414,     0,    40,    41,    42,   477,     0,   494,
      11,    12,   495,   496,    15,   497,    17,   504,    18,     0,
      20,    21,    52,    23,    24,     0,     0,     0,     0,     0,
     494,    11,    12,   495,   496,    15,   497,    17,     0,    18,
      36,    20,    21,     0,    23,    24,     0,     0,     0,    40,
      41,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,   521,     0,     0,     0,     0,    52,     0,     0,
      40,    41,    42,     0,     0,   494,    11,    12,   495,   496,
      15,   497,    17,     0,    18,     0,    20,    21,    52,    23,
      24,   264,   265,   266,     0,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,    36,   522,     0,     0,
       0,   278,     0,     0,     0,    40,    41,    42,   446,     0,
     494,    11,    12,   495,   496,    15,   497,    17,   647,    18,
       0,    20,    21,    52,    23,    24,     0,     0,     0,     0,
       0,   494,    11,    12,   495,   496,    15,   497,    17,     0,
      18,    36,    20,    21,     0,    23,    24,     0,     0,     0,
      40,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,   667,     0,     0,     0,     0,    52,     0,
       0,    40,    41,    42,     0,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   265,   266,    52,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     7,     0,   278,     0,  1053,     8,
       9,     0,    10,    11,    12,    13,    14,    15,    16,    17,
       0,    18,    19,    20,    21,    22,    23,    24,     0,  1104,
       0,    25,    26,    27,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,     0,    37,    38,     0,     0,     0,
       0,    39,    40,    41,    42,     0,     0,     0,     0,    43,
       0,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,   264,   265,   266,     0,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,     0,
     947,     0,   948,   264,   265,   266,     0,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,     0,
    1013,     0,  1014,   264,   265,   266,     0,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,   264,
     265,   266,   625,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,     0,     0,   264,   265,   266,   629,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,     0,
       0,   264,   265,   266,   630,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,     0,     0,   264,   265,   266,
     725,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,     0,     0,   264,   265,   266,   748,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,   264,
     265,   266,   919,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,     0,     0,   264,   265,   266,   933,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,     0,
       0,   264,   265,   266,  1025,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,     0,     0,   264,   265,   266,
    1032,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,     0,     0,   264,   265,   266,  1033,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,   264,
     265,   266,  1044,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,     0,     0,   264,   265,   266,  1047,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,     0,
       0,   264,   265,   266,  1050,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,     0,     0,   264,   265,   266,
    1058,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,     0,     0,   264,   265,   266,  1059,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,   264,
     265,   266,  1070,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,     0,     0,   264,   265,   266,  1098,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,     0,
       0,   264,   265,   266,  1100,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,     0,     0,   264,   265,   266,
    1102,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,     0,     0,   264,   265,   266,  1112,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,     0,   264,
     265,   266,  1173,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,     0,     0,   264,   265,   266,  1176,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,   264,
     265,   266,   477,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   264,   265,   266,   478,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   264,   265,   266,
     515,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   264,   265,   266,   560,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   264,   265,   266,   561,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,   264,
     265,   266,   574,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   264,   265,   266,   575,   267,   268,   269,
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
       0,     0,     0,   264,   265,   266,   643,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   264,   265,   266,
     644,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   264,   265,   266,   645,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   264,   265,   266,   715,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,   264,
     265,   266,   746,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   264,   265,   266,   747,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   264,   265,   266,
     774,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   264,   265,   266,   863,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   264,   265,   266,   864,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,   264,
     265,   266,   880,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   264,   265,   266,   881,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   264,   265,   266,
     896,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   264,   265,   266,   903,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   264,   265,   266,   990,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,   264,
     265,   266,   991,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   264,   265,   266,   999,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   264,   265,   266,
    1002,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   264,   265,   266,  1003,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   264,   265,   266,  1010,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,     0,     0,   264,
     265,   266,  1011,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   264,   265,   266,  1066,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   264,   265,   266,
    1068,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   264,   265,   266,  1162,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   264,   265,   266,  1172,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,   264,   265,   266,   421,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,   264,   265,   266,
     524,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,   264,   265,
     266,   539,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,   264,
     265,   266,   541,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
     264,   265,   266,   543,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,   264,   265,   266,   545,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,   264,   265,   266,   547,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,   264,   265,   266,   549,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,   264,   265,   266,   551,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,   264,   265,   266,   553,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,   264,   265,   266,   555,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,   264,   265,   266,
     557,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,   264,   265,
     266,   559,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,   264,
     265,   266,   563,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
     264,   265,   266,   565,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,   264,   265,   266,   567,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,   264,   265,   266,   569,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,   264,   265,   266,   571,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,   264,   265,   266,   573,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,   264,   265,   266,   649,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,   264,   265,   266,   655,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,   264,   265,   266,
     658,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,   264,   265,
     266,   659,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,   264,
     265,   266,   671,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
     264,   265,   266,   695,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,   264,   265,   266,   790,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,   264,   265,   266,   792,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,   264,   265,   266,   794,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,   264,   265,   266,   796,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,   264,   265,   266,   797,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,   264,   265,   266,   894,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,     0,   414,   264,
     265,   266,     0,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,   447,   264,   265,   266,     0,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,     0,   448,   264,   265,   266,     0,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,   449,   264,   265,
     266,     0,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,     0,
     451,   264,   265,   266,     0,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,   453,   264,   265,   266,     0,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,     0,   454,   264,   265,   266,
       0,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,   463,
     264,   265,   266,     0,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,     0,   509,   264,   265,   266,     0,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,   510,   264,   265,   266,     0,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,     0,   513,   264,
     265,   266,     0,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,   519,   264,   265,   266,     0,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,     0,   538,   264,   265,   266,     0,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,   540,   264,   265,
     266,     0,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,     0,
     542,   264,   265,   266,     0,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,   544,   264,   265,   266,     0,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,     0,   546,   264,   265,   266,
       0,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,   548,
     264,   265,   266,     0,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,     0,   550,   264,   265,   266,     0,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,   552,   264,   265,   266,     0,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,     0,   554,   264,
     265,   266,     0,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,   556,   264,   265,   266,     0,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,     0,   558,   264,   265,   266,     0,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,   562,   264,   265,
     266,     0,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,     0,
     564,   264,   265,   266,     0,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,   566,   264,   265,   266,     0,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,     0,   568,   264,   265,   266,
       0,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,   570,
     264,   265,   266,     0,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,     0,   572,   264,   265,   266,     0,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,   611,   264,   265,   266,     0,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,     0,   613,   264,
     265,   266,     0,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,   626,   264,   265,   266,     0,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,     0,   627,   264,   265,   266,     0,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,   631,   264,   265,
     266,     0,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,     0,
     632,   264,   265,   266,     0,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,   633,   264,   265,   266,     0,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,     0,   634,   264,   265,   266,
       0,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,   635,
     264,   265,   266,     0,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,     0,   663,   264,   265,   266,     0,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,   670,   264,   265,   266,     0,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,   278,     0,   789,   264,
     265,   266,     0,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
       0,   791,   264,   265,   266,     0,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,     0,   793,   264,   265,   266,     0,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,   278,     0,   795,   264,   265,
     266,     0,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,     0,
     801,   264,   265,   266,     0,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,   278,     0,   867,   264,   265,   266,     0,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,     0,   920,   264,   265,   266,
       0,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,   278,     0,   951,
     264,   265,   266,     0,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
     278,     0,  1065,   264,   265,   266,     0,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,   278,     0,  1111
};

static const short int yycheck[] =
{
       6,     6,   166,   321,   257,   169,     3,     5,   293,     4,
       6,     3,    45,     4,     4,   755,     4,     4,     4,     6,
       0,    67,     4,     4,     7,     4,    67,     4,   192,   601,
     194,     5,   868,   869,     4,    67,    34,    35,    36,    37,
      85,    68,    40,     4,     5,   131,    73,   133,     6,    53,
      54,   120,   121,     6,     6,     6,     6,   122,   123,   124,
      34,    35,    36,    37,   131,   130,    40,     6,   137,   131,
     139,   138,     6,    34,    35,    36,    37,   120,   121,    40,
     131,    76,    77,    78,    79,   131,   131,   138,    76,    77,
      78,    79,   138,     4,   131,   138,    68,   138,   131,   131,
      52,    73,    52,   131,    68,   111,   112,   113,   131,    73,
     116,   117,   139,    41,   120,   138,    44,   131,    88,    89,
     131,   127,   958,   129,   130,   131,   109,   133,    68,   135,
     136,    67,   138,    73,   128,   129,   708,    49,   128,   129,
     138,   135,   138,   133,   139,   135,   133,   138,   154,   155,
     131,   139,   138,   137,     7,   255,   138,   163,   142,   138,
     445,   138,   120,   121,   138,   131,   330,   139,   421,   120,
     121,   177,   178,   458,   180,   139,   182,    88,    89,   185,
     186,   120,   121,   167,    45,   132,   350,   131,   172,   173,
     137,   197,     7,   293,     6,     7,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    45,   811,
     244,   245,   246,   247,    41,   128,   129,    44,    45,   255,
      47,     7,   257,   106,   107,   108,   109,    45,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   132,    47,   128,   129,  1017,   137,   285,
    1020,   287,   135,  1023,   131,    68,   292,   293,   120,   121,
      73,   106,   107,   108,   109,   301,   302,   303,   583,   305,
     306,   307,   308,   309,   310,   311,   138,   982,   131,   984,
     133,   986,    41,   128,   129,    44,    45,   323,   324,   325,
     326,   327,   328,   320,   321,   331,    68,   138,   320,   321,
     336,    73,   617,    68,   340,   341,     7,   131,    73,   133,
     346,    27,    28,  1083,    30,   445,   120,   121,   138,   355,
     106,   107,   108,   109,   360,     5,   139,   362,   458,   120,
     121,   131,    45,   133,   138,   650,   651,   652,   653,   131,
      68,   133,   128,   129,  1114,    73,   137,  1117,   139,  1054,
    1120,   120,   121,  1123,    34,    35,    36,    37,   120,   121,
      40,   120,   121,   965,     6,    68,   132,   139,    68,   138,
      73,   137,   131,    73,   139,   137,  1146,   413,  1148,   138,
    1150,   417,    58,    59,   132,    68,   421,   423,   422,   137,
      73,     6,  1097,    68,  1099,     4,  1101,     8,    73,    68,
    1105,   415,   416,     4,    73,   106,   107,   108,   109,   445,
     446,   139,   727,    44,    45,     4,    47,   700,   701,   455,
     456,   131,   458,   120,   121,   461,   462,   131,  1133,   133,
    1135,   467,  1137,   120,   121,   151,   139,   153,   131,   139,
     137,   477,   478,   159,   131,     5,   131,   163,   128,   129,
     486,   138,     6,   583,   132,   135,   139,     4,   132,   137,
     131,   591,   133,   137,   139,   501,   120,   121,     6,     7,
     139,   120,   121,   131,    34,    35,    36,    37,     4,   515,
      40,   517,   518,   137,   200,   139,   131,   617,   137,   524,
     524,   131,   120,   121,   122,   123,   124,    45,   846,   110,
     111,   112,   130,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   120,   121,   120,   121,   131,   130,
     650,   651,   652,   653,   560,   561,   131,     4,   139,   120,
     121,   137,   131,   137,   133,   120,   121,     5,   574,   575,
     576,   577,   578,   579,   580,     6,   137,   583,   120,   121,
     584,   587,   137,   120,   121,   591,   120,   121,   594,   120,
     121,   120,   121,     6,   133,   137,   135,   138,   604,   131,
     137,   133,     6,   137,   131,   131,   137,   133,   137,   131,
     131,   617,   133,   619,     4,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   131,   609,   610,   727,   612,   130,
     614,   615,   318,   319,   131,    61,    62,    63,    64,   138,
      66,   327,   131,   138,   650,   651,   652,   653,    74,    75,
     656,   657,   131,    57,   128,   129,   662,   128,   129,   133,
     978,   135,   133,   131,   135,   133,   131,   131,   128,   129,
     131,   677,   678,   133,   133,   135,   660,   661,   133,   131,
     664,   133,   131,   131,   133,   133,   131,   131,   133,   133,
     695,   131,   131,   133,   133,   131,   701,   133,   135,   131,
       8,   133,   137,   709,   139,   138,   110,   111,   112,   715,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   727,   137,   729,   139,   731,   130,   137,   137,   139,
     139,   137,   137,   139,   139,   719,   137,   721,   139,   745,
     746,   747,   137,   137,   139,   139,   752,   138,   732,   733,
     734,   138,   133,   737,   738,   739,   740,   741,   742,   743,
     137,   137,   139,   139,     4,   137,     6,   139,   774,   775,
     776,   137,   137,   139,   139,   780,   137,   783,   139,   137,
       6,   139,   788,   137,   137,   139,   139,   138,    91,     6,
     476,   131,     6,     6,   133,     6,     4,   130,   804,   803,
       5,   135,   110,   111,   112,   491,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     7,   802,   133,
     138,     6,   130,   987,   132,     7,   832,   833,     7,     6,
     132,     7,     7,    86,    88,   132,   842,   138,   842,   137,
     132,   137,     6,     4,   134,     7,     6,   135,     7,   846,
       7,     7,     7,     7,   846,     7,     6,   863,   864,   139,
     139,   138,   138,     7,     7,   131,     7,   135,   131,   875,
     131,   138,   856,     6,   880,   881,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   871,     4,     6,
     896,  1055,   130,     6,     6,   134,     6,   903,   882,   110,
     111,   112,     7,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   133,   921,     6,   138,     7,   130,
       7,     7,   608,     7,     7,   110,   111,   112,   934,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       7,   947,     7,   949,     7,   130,     7,     7,   954,     7,
       7,     4,     6,   959,     6,     6,     6,   643,   644,   645,
     110,   111,   112,     7,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   981,     6,   983,     4,   985,
     130,   978,     4,     7,   990,   991,   978,     6,     6,   131,
     996,   138,   132,   132,     7,     6,  1002,  1003,   135,     6,
       6,     6,   138,     6,  1010,   989,     6,  1013,   138,     6,
       6,   995,    87,   138,     6,   999,    41,    42,    43,    44,
      45,    46,    47,    48,   135,    50,     6,    52,    53,  1035,
      55,    56,     4,     6,   134,     6,     6,     6,     6,  1045,
       6,     6,  1048,     6,     6,  1051,     6,    72,     6,     6,
       6,     6,     6,     6,     6,     6,    81,    82,    83,     6,
    1066,     6,  1068,     7,    87,   138,   752,     4,     6,   135,
       6,     6,  1056,     7,    99,   134,  1060,  1061,     6,     6,
     110,   111,   112,   138,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   137,   139,   138,   138,     6,
     130,   138,   138,   138,     6,    84,  1110,   110,   111,   112,
      87,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   132,  1107,   138,    89,     6,   130,     5,   137,
     139,   817,     6,   819,  1140,   139,   138,  1141,     6,  1143,
     110,   111,   112,   138,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,  1161,  1162,     6,     6,  1163,
     130,   847,   137,   849,     6,   851,  1172,     6,     3,     4,
       6,   138,     6,     6,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     6,     6,
       6,     5,    84,   110,   111,   112,    41,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   138,   138,
     137,   139,     6,   130,   139,   138,    61,    62,    63,    64,
      65,    66,   137,     6,     6,     6,     6,     6,     6,    74,
      75,     5,   110,   111,   112,   138,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   138,     6,   138,
       6,   139,   130,   138,     6,   138,    84,   102,   103,   104,
     105,   112,   139,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     6,   120,   121,     6,   138,   130,
       6,   126,     6,     6,     6,   981,   131,   983,     6,   985,
       6,   136,     3,     4,   139,  1035,   526,     3,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     3,   942,   807,    -1,    -1,   110,   111,   112,
      41,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,     3,
       4,    -1,    -1,    74,    75,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,   102,   103,   104,   105,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
     121,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,
     131,    -1,     3,     4,    -1,   136,    -1,   138,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,   121,    -1,    -1,
      -1,    -1,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
     134,    -1,   136,    -1,   138,    -1,    -1,    -1,    -1,   110,
     111,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,   102,   103,   104,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
     121,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,
     131,    -1,    -1,   134,    -1,   136,    -1,   138,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,   102,   103,   104,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,   134,
      -1,   136,    -1,   138,   102,   103,   104,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,
      -1,    -1,    -1,   131,   102,   103,   104,   105,   136,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,
      -1,    -1,    -1,   131,    -1,     3,     4,     5,   136,     7,
     138,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    34,    35,    36,    37,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,   120,   121,    -1,    74,    75,    -1,   126,    -1,
     128,   129,    -1,   131,    -1,   133,    -1,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,    -1,
      -1,    -1,   131,     3,     4,     5,    -1,   136,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    34,    35,    36,    37,     3,     4,
      40,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     6,    -1,
      -1,    -1,   102,   103,   104,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
     120,   121,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,     8,    -1,   136,   102,   103,   104,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,    -1,    -1,    -1,   131,   102,   103,   104,
     105,   136,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,   121,    -1,    -1,     8,
      -1,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,   136,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,   110,
     111,   112,   130,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,   110,   111,   112,   130,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,   110,   111,   112,   130,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,   110,   111,   112,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,   110,   111,   112,   130,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,     1,    -1,    -1,
       4,   130,    -1,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    33,
     137,    -1,   139,    -1,    38,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    -1,
      74,    75,    -1,    -1,    -1,    -1,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    88,    -1,    90,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    72,
      52,    53,    -1,    55,    56,    -1,    -1,    -1,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    81,
      82,    83,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    -1,    52,    53,    99,    55,    56,
     110,   111,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    72,   139,    -1,    -1,    -1,
     130,    -1,   132,    -1,    81,    82,    83,   137,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,   139,    50,    -1,
      52,    53,    99,    55,    56,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      72,    52,    53,    -1,    55,    56,    -1,    -1,    -1,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,   139,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      81,    82,    83,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    -1,    52,    53,    99,    55,
      56,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    72,   139,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    81,    82,    83,   137,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,   139,    50,
      -1,    52,    53,    99,    55,    56,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    72,    52,    53,    -1,    55,    56,    -1,    -1,    -1,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,   139,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    81,    82,    83,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,    99,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    33,    -1,   130,    -1,   139,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,   139,
      -1,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    -1,    74,    75,    -1,    -1,    -1,
      -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    88,
      -1,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
     137,    -1,   139,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
     137,    -1,   139,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   139,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   139,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   139,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     139,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   139,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   139,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   139,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   139,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     139,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   139,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   139,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   139,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   139,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     139,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   139,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   139,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   139,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   139,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     139,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   139,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   139,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   139,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,   110,
     111,   112,   137,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,   110,   111,   112,   137,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,   110,   111,   112,
     137,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,   110,   111,   112,   137,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,   110,   111,   112,   137,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,   110,
     111,   112,   137,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,   110,   111,   112,   137,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,   110,   111,   112,
     137,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,   110,   111,   112,   137,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,   110,   111,   112,   137,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,   110,
     111,   112,   137,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,   110,   111,   112,   137,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,   110,   111,   112,
     137,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,   110,   111,   112,   137,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,   110,   111,   112,   137,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,   110,
     111,   112,   137,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,   110,   111,   112,   137,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,   110,   111,   112,
     137,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,   110,   111,   112,   137,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,   110,   111,   112,   137,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,   110,
     111,   112,   137,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,   110,   111,   112,   137,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,   110,   111,   112,
     137,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,   110,   111,   112,   137,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,   110,   111,   112,   137,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,   110,
     111,   112,   137,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,   110,   111,   112,   137,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,   110,   111,   112,
     137,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,   110,   111,   112,   137,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,   110,   111,   112,   137,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,   110,
     111,   112,   137,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,   110,   111,   112,   137,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,   110,   111,   112,
     137,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,   110,   111,   112,   137,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,   110,   111,   112,   137,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,   110,   111,   112,   134,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,   130,   110,   111,   112,
     134,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   110,   111,
     112,   134,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,   110,
     111,   112,   134,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
     110,   111,   112,   134,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
     130,   110,   111,   112,   134,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,   110,   111,   112,   134,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,    -1,   130,   110,   111,   112,   134,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,   110,   111,   112,   134,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,   130,   110,   111,   112,   134,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,   110,   111,   112,   134,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,   130,   110,   111,   112,
     134,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   110,   111,
     112,   134,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,   110,
     111,   112,   134,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
     110,   111,   112,   134,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
     130,   110,   111,   112,   134,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,   110,   111,   112,   134,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,    -1,   130,   110,   111,   112,   134,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,   110,   111,   112,   134,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,   130,   110,   111,   112,   134,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,   110,   111,   112,   134,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,   130,   110,   111,   112,
     134,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,   110,   111,
     112,   134,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,   110,
     111,   112,   134,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
     110,   111,   112,   134,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
     130,   110,   111,   112,   134,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,   110,   111,   112,   134,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,    -1,   130,   110,   111,   112,   134,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,   110,   111,   112,   134,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,   130,   110,   111,   112,   134,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,   110,   111,   112,   134,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   110,
     111,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,   132,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,    -1,   130,    -1,   132,   110,   111,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   110,   111,
     112,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,
     132,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,   132,   110,   111,   112,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,   130,    -1,   132,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,
     110,   111,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
     130,    -1,   132,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,   132,   110,   111,   112,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   110,
     111,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,   132,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,    -1,   130,    -1,   132,   110,   111,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   110,   111,
     112,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,
     132,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,   132,   110,   111,   112,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,   130,    -1,   132,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,
     110,   111,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
     130,    -1,   132,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,   132,   110,   111,   112,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   110,
     111,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,   132,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,    -1,   130,    -1,   132,   110,   111,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   110,   111,
     112,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,
     132,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,   132,   110,   111,   112,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,   130,    -1,   132,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,
     110,   111,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
     130,    -1,   132,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,   132,   110,   111,   112,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   110,
     111,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,   132,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,    -1,   130,    -1,   132,   110,   111,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   110,   111,
     112,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,
     132,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,   132,   110,   111,   112,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,   130,    -1,   132,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,
     110,   111,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
     130,    -1,   132,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,   132,   110,   111,   112,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   110,
     111,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,   132,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,    -1,   130,    -1,   132,   110,   111,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   110,   111,
     112,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,
     132,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,   130,    -1,   132,   110,   111,   112,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,   130,    -1,   132,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,
     110,   111,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
     130,    -1,   132,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,   130,    -1,   132
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     1,   141,   142,     6,     0,     4,    33,    38,    39,
      41,    42,    43,    44,    45,    46,    47,    48,    50,    51,
      52,    53,    54,    55,    56,    60,    61,    62,    63,    64,
      65,    66,    68,    69,    70,    71,    72,    74,    75,    80,
      81,    82,    83,    88,    90,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   143,   144,   145,   163,   164,
     165,   168,   169,   170,   171,   172,   173,   174,   189,   190,
       3,     4,     5,     7,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    34,    35,
      36,    37,    40,   102,   103,   104,   105,   106,   107,   108,
     109,   120,   121,   126,   128,   129,   131,   133,   135,   136,
     161,   162,   191,   192,   203,   131,     6,   138,     6,   131,
     131,   131,    67,   131,    67,   131,   131,    49,   131,    45,
      45,    45,    44,    45,    47,    47,    41,    44,    45,    47,
     131,   138,   120,   121,   131,   138,   193,   194,   193,   138,
      41,    44,    45,   138,   193,     4,   138,    45,     4,   138,
       6,     6,    41,    44,     4,     4,     4,   131,   131,    45,
     131,     4,   138,   200,     4,   131,   131,     6,     4,     4,
      45,     5,   138,   203,   138,   203,     4,   133,   135,   162,
       4,   138,   131,   133,   131,   133,   131,   133,   131,   133,
     131,   133,   131,   133,   131,   133,   131,   133,   131,   133,
     131,   133,   131,   133,   131,   133,   131,   133,   131,   133,
     131,   133,   131,   133,   131,   133,   131,   133,   131,   133,
     131,   133,   131,   133,   131,   131,   131,   131,   131,     4,
     191,   191,   191,   191,   134,   138,   191,     4,    88,    89,
       4,   191,     6,     6,   110,   111,   112,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   130,     6,
       5,   191,   191,   191,   191,   131,   191,   131,   191,   191,
       4,    41,   121,   138,   165,   168,   174,   191,   197,   198,
     191,   138,   131,   131,   197,   138,   138,   131,   131,   131,
     131,   131,     4,   193,   193,   193,   191,   191,   120,   121,
     138,   138,   193,   138,   138,   138,   120,   121,   131,   193,
     138,   133,   167,   197,     4,     6,   133,   167,   197,   197,
     133,   133,     6,   191,   191,    85,   131,   191,   135,   191,
     138,    91,   191,   191,     6,   131,   167,     6,   167,     6,
     133,   191,     4,   193,   146,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,     4,   203,   203,
     203,   203,     5,   133,   132,     7,   109,   121,   191,   198,
     199,   134,     7,   161,   162,   135,     7,   133,     6,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   132,   137,   137,   132,   132,   132,
     191,   132,   191,   132,   132,   133,   138,     4,   138,   139,
     199,     8,     7,   132,   191,   191,   191,     7,   191,   191,
     191,   191,   191,   191,   191,   132,   137,   137,   137,   193,
     193,   165,   166,   167,   168,   166,   137,   191,   191,   191,
     191,   137,   167,   191,    41,    44,    45,    47,   139,   164,
       6,     7,     6,   191,   139,     7,     7,   191,   191,   132,
     132,    86,   191,   132,    88,   137,   167,   138,     8,   132,
     191,   139,   139,   191,   134,   162,   138,     4,    76,    77,
      78,    79,   139,   149,   153,   156,   158,   159,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   132,   134,   132,   134,   132,   134,
     137,   137,   132,   134,   132,   134,   132,   134,   132,   134,
     132,   134,   132,   134,   137,   137,   137,   137,   137,   137,
     133,   135,   132,   137,   137,   132,   132,   137,   191,   197,
     197,   137,   139,   135,   161,   162,   203,   191,     6,     4,
       4,   138,   201,   134,     8,     6,   199,   191,     7,     7,
       7,   132,     7,   132,     7,     7,   134,   138,   191,   133,
     199,   139,   191,   191,     7,   139,   132,   132,   191,   139,
     139,   132,   132,   132,   132,   132,   135,   193,   191,   191,
     139,   139,   191,   137,   137,   137,   193,   139,   175,   134,
     138,   138,   138,   138,   191,   134,   138,   138,   134,   134,
       7,     7,   131,   132,     7,   135,   191,   139,   191,   191,
     132,   134,   135,   162,   203,   146,   150,   131,   131,   138,
     160,     6,   191,   191,   191,   191,   191,   191,   191,   191,
     191,     4,   199,   203,   191,   134,     6,     6,   191,   198,
     134,     4,    88,    89,   191,     6,     6,     6,     7,   133,
     200,   202,     6,   191,   132,   137,   193,   197,   197,     7,
     197,     7,   197,   197,   199,   139,   134,   138,   139,     8,
       6,   138,     7,     7,     7,     6,    57,     7,     7,     7,
       7,     7,     7,     7,     4,   137,   137,   137,   139,   193,
     193,   193,   137,    68,    73,   187,   188,     6,   199,   199,
     199,   199,     6,     6,   191,   191,     6,     6,   197,   197,
     191,     7,   197,     4,   137,     8,     8,   132,     7,     6,
       4,     6,   139,   131,   191,   191,   196,   197,   138,   132,
     134,   132,   134,   132,   134,   132,   134,   134,   132,   132,
     132,   132,   161,     7,   161,   162,   135,     7,     6,   200,
     191,   137,   139,     6,   191,     6,     6,    52,     6,    52,
     197,     6,   197,     6,     6,   139,   199,   191,   191,   197,
     197,   197,    58,    59,   197,   197,   197,   197,   197,   197,
     197,     6,     7,   191,   191,   191,   138,   137,   139,   137,
     139,   137,   139,   191,   193,     6,   138,   139,   188,   139,
     139,   139,   139,   137,   137,     6,     6,   132,   131,   138,
     195,    87,   191,   191,   191,   138,   162,     6,   147,   191,
     137,   137,   137,   139,   148,   191,   135,   197,   203,   191,
       6,     4,   201,     6,   134,   200,   137,   193,   193,     6,
       6,   134,   139,   137,     6,     6,     6,   191,   191,     4,
       6,     6,     6,     6,     6,     6,     6,   191,   203,   139,
     132,   137,   139,   166,   193,     6,   178,   193,     6,   179,
     193,     6,   180,   139,   137,   197,     6,     6,     6,     6,
     191,   191,     7,   196,   196,    87,   197,   137,   139,     8,
     139,   132,   191,   132,   137,   191,   191,   197,   138,   137,
     139,     4,     6,     6,     6,     7,     6,   135,   191,     6,
       6,   134,   191,     6,     6,     6,     6,     6,   138,   191,
     139,   137,   138,   137,   138,   137,   138,   138,   191,   137,
     137,   137,   195,   132,   139,   138,    84,   191,   191,   137,
     151,   191,   137,   137,   196,   191,     6,   132,   200,    89,
     137,   137,   166,   137,   139,   191,   193,   187,   191,   193,
     187,   191,   193,   187,   167,   139,   197,   191,   191,    87,
     197,   191,   139,   139,   197,   138,   191,   191,   139,     6,
     191,     5,   139,   191,   139,   137,   139,   139,   137,   139,
     139,   137,   139,   139,   176,   138,   137,   139,   139,   139,
     138,   137,     6,   139,   148,   132,   137,     6,   137,   137,
     139,     6,   181,   191,     6,     6,   182,   191,     6,     6,
     183,   191,     6,   187,   167,   197,     6,     6,     6,   197,
     197,     6,   139,   154,   191,   191,     5,   138,   139,   138,
     139,   138,   139,   139,   139,   177,   139,   137,   139,     6,
     138,   132,   139,   137,   187,     6,   184,   187,     6,   185,
     187,     6,   186,   187,     6,   197,    84,   152,   203,   157,
       6,     5,   139,   138,   139,   138,   139,   138,   139,   139,
     138,   137,   139,   138,   139,     6,   187,     6,   187,     6,
     187,    84,   191,   203,     6,   155,   203,     6,   139,   139,
     139,   138,   137,   137,   139,     6,     6,     6,   191,   191,
     203,     6,   137,   139,   191,     6,   139,     6
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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
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
      yysymprint (stderr,					\
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
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
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
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
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
  const char *yys = yystr;

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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



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
    ;
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

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



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
	short int *yyss1 = yyss;
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

  case 30:
#line 229 "Gmsh.y"
    { ViewCoord[ViewCoordIdx] = (yyvsp[0].d); ViewCoordIdx++; ;}
    break;

  case 31:
#line 231 "Gmsh.y"
    { ViewCoord[ViewCoordIdx] = (yyvsp[0].d); ViewCoordIdx++; ;}
    break;

  case 32:
#line 236 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[0].d)); ;}
    break;

  case 33:
#line 238 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &(yyvsp[0].d)); ;}
    break;

  case 34:
#line 243 "Gmsh.y"
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

  case 35:
#line 433 "Gmsh.y"
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

  case 36:
#line 451 "Gmsh.y"
    {
      if(ViewValueList){  
	if((List_Nbr(ViewValueList) - ViewNumListTmp) % (ViewNumComp * ViewNumNodes)) 
	  ViewErrorFlags[ViewElementIdx]++;
	(*ViewNumList)++;
      }
    ;}
    break;

  case 37:
#line 462 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[0].c))+1; i++) List_Add(View->T2C, &(yyvsp[0].c)[i]); 
      Free((yyvsp[0].c));
    ;}
    break;

  case 38:
#line 467 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[0].c))+1; i++) List_Add(View->T2C, &(yyvsp[0].c)[i]); 
      Free((yyvsp[0].c));
    ;}
    break;

  case 39:
#line 475 "Gmsh.y"
    { 
      List_Add(View->T2D, &(yyvsp[-5].d)); List_Add(View->T2D, &(yyvsp[-3].d));
      List_Add(View->T2D, &(yyvsp[-1].d)); 
      double d = List_Nbr(View->T2C);
      List_Add(View->T2D, &d); 
    ;}
    break;

  case 40:
#line 482 "Gmsh.y"
    {
      View->NbT2++;
    ;}
    break;

  case 41:
#line 489 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[0].c))+1; i++) List_Add(View->T3C, &(yyvsp[0].c)[i]); 
      Free((yyvsp[0].c));
    ;}
    break;

  case 42:
#line 494 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen((yyvsp[0].c))+1; i++) List_Add(View->T3C, &(yyvsp[0].c)[i]); 
      Free((yyvsp[0].c));
    ;}
    break;

  case 43:
#line 502 "Gmsh.y"
    { 
      List_Add(View->T3D, &(yyvsp[-7].d)); List_Add(View->T3D, &(yyvsp[-5].d));
      List_Add(View->T3D, &(yyvsp[-3].d)); List_Add(View->T3D, &(yyvsp[-1].d)); 
      double d = List_Nbr(View->T3C);
      List_Add(View->T3D, &d); 
    ;}
    break;

  case 44:
#line 509 "Gmsh.y"
    {
      View->NbT3++;
    ;}
    break;

  case 45:
#line 517 "Gmsh.y"
    {
      View->adaptive = new Adaptive_Post_View(View, (yyvsp[-5].l), (yyvsp[-2].l));
    ;}
    break;

  case 46:
#line 524 "Gmsh.y"
    {
      ViewValueList = View->Time;
    ;}
    break;

  case 47:
#line 528 "Gmsh.y"
    {
    ;}
    break;

  case 48:
#line 535 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 49:
#line 536 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 50:
#line 537 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 51:
#line 538 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 52:
#line 539 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 53:
#line 543 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 54:
#line 544 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 55:
#line 552 "Gmsh.y"
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

  case 56:
#line 583 "Gmsh.y"
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

  case 57:
#line 622 "Gmsh.y"
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

  case 58:
#line 676 "Gmsh.y"
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

  case 59:
#line 693 "Gmsh.y"
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

  case 60:
#line 711 "Gmsh.y"
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

  case 61:
#line 722 "Gmsh.y"
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

  case 62:
#line 741 "Gmsh.y"
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

  case 63:
#line 755 "Gmsh.y"
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

  case 64:
#line 772 "Gmsh.y"
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

  case 65:
#line 798 "Gmsh.y"
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

  case 66:
#line 825 "Gmsh.y"
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

  case 67:
#line 839 "Gmsh.y"
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

  case 68:
#line 856 "Gmsh.y"
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

  case 69:
#line 870 "Gmsh.y"
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

  case 70:
#line 887 "Gmsh.y"
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

  case 71:
#line 907 "Gmsh.y"
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

  case 72:
#line 930 "Gmsh.y"
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

  case 73:
#line 940 "Gmsh.y"
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

  case 74:
#line 959 "Gmsh.y"
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

  case 75:
#line 975 "Gmsh.y"
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

  case 76:
#line 991 "Gmsh.y"
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

  case 77:
#line 1010 "Gmsh.y"
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

  case 78:
#line 1029 "Gmsh.y"
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

  case 79:
#line 1047 "Gmsh.y"
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

  case 80:
#line 1065 "Gmsh.y"
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

  case 81:
#line 1083 "Gmsh.y"
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

  case 82:
#line 1109 "Gmsh.y"
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

  case 83:
#line 1127 "Gmsh.y"
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

  case 84:
#line 1154 "Gmsh.y"
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

  case 85:
#line 1173 "Gmsh.y"
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

  case 86:
#line 1197 "Gmsh.y"
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

  case 87:
#line 1221 "Gmsh.y"
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

  case 88:
#line 1247 "Gmsh.y"
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

  case 89:
#line 1264 "Gmsh.y"
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

  case 90:
#line 1282 "Gmsh.y"
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

  case 91:
#line 1301 "Gmsh.y"
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

  case 92:
#line 1320 "Gmsh.y"
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

  case 93:
#line 1359 "Gmsh.y"
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

  case 94:
#line 1386 "Gmsh.y"
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

  case 95:
#line 1405 "Gmsh.y"
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

  case 96:
#line 1422 "Gmsh.y"
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

  case 97:
#line 1438 "Gmsh.y"
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

  case 98:
#line 1458 "Gmsh.y"
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

  case 99:
#line 1475 "Gmsh.y"
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

  case 100:
#line 1492 "Gmsh.y"
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

  case 101:
#line 1513 "Gmsh.y"
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 102:
#line 1518 "Gmsh.y"
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 103:
#line 1523 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 104:
#line 1528 "Gmsh.y"
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l), 1);
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 105:
#line 1535 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); ;}
    break;

  case 106:
#line 1536 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); ;}
    break;

  case 107:
#line 1537 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); ;}
    break;

  case 108:
#line 1542 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 109:
#line 1546 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    ;}
    break;

  case 110:
#line 1550 "Gmsh.y"
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

  case 111:
#line 1566 "Gmsh.y"
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

  case 112:
#line 1582 "Gmsh.y"
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

  case 113:
#line 1598 "Gmsh.y"
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

  case 114:
#line 1619 "Gmsh.y"
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

  case 115:
#line 1633 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "View")) AliasView((int)(yyvsp[-2].d), 0);
      Free((yyvsp[-4].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 116:
#line 1639 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "View")) AliasView((int)(yyvsp[-2].d), 0);
      Free((yyvsp[-4].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 117:
#line 1645 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "View")) AliasView((int)(yyvsp[-2].d), 1);
      Free((yyvsp[-4].c));
      (yyval.l) = NULL;
    ;}
    break;

  case 118:
#line 1657 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 119:
#line 1666 "Gmsh.y"
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

  case 120:
#line 1676 "Gmsh.y"
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

  case 121:
#line 1690 "Gmsh.y"
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

  case 122:
#line 1709 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u));
      }
      List_Delete((yyvsp[-1].l));      
    ;}
    break;

  case 123:
#line 1723 "Gmsh.y"
    {
      int m = (CTX.visibility_mode == 2) ? VIS_MESH : 
	((CTX.visibility_mode == 1) ? VIS_GEOM : VIS_GEOM|VIS_MESH);
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber((yyvsp[-1].c), i, m);
      Free((yyvsp[-1].c));
    ;}
    break;

  case 124:
#line 1731 "Gmsh.y"
    {
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber((yyvsp[-1].c), i, 0);
      Free((yyvsp[-1].c));
    ;}
    break;

  case 125:
#line 1737 "Gmsh.y"
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

  case 126:
#line 1748 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 127:
#line 1762 "Gmsh.y"
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

  case 128:
#line 1806 "Gmsh.y"
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

  case 129:
#line 1821 "Gmsh.y"
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

  case 130:
#line 1832 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-2].c), "Sleep")){
	SleepMilliSeconds((int)((yyvsp[-1].d) * 1000.));
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

  case 131:
#line 1848 "Gmsh.y"
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

  case 132:
#line 1858 "Gmsh.y"
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

  case 133:
#line 1880 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 134:
#line 1884 "Gmsh.y"
    {
      CTX.forced_bbox = 0;
      SetBoundingBox();
    ;}
    break;

  case 135:
#line 1889 "Gmsh.y"
    {
      CTX.forced_bbox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    ;}
    break;

  case 136:
#line 1894 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      if(!CTX.batch) // we're in interactive mode
	Draw();
#endif
    ;}
    break;

  case 137:
#line 1907 "Gmsh.y"
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

  case 138:
#line 1922 "Gmsh.y"
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

  case 139:
#line 1938 "Gmsh.y"
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

  case 140:
#line 1964 "Gmsh.y"
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

  case 141:
#line 1991 "Gmsh.y"
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

  case 142:
#line 2023 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction((yyvsp[0].c), yyin, yyname, yylineno))
	yymsg(GERROR, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 143:
#line 2030 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin, yyname, yylineno))
	yymsg(GERROR, "Error while exiting function");
    ;}
    break;

  case 144:
#line 2035 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction((yyvsp[-1].c), &yyin, yyname, yylineno))
	yymsg(GERROR, "Unknown function %s", (yyvsp[-1].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 145:
#line 2041 "Gmsh.y"
    {
      if(!(yyvsp[-1].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 146:
#line 2045 "Gmsh.y"
    {
    ;}
    break;

  case 147:
#line 2054 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l), 
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 148:
#line 2062 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l), 
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 149:
#line 2070 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l), 
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    ;}
    break;

  case 150:
#line 2078 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 151:
#line 2083 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l), 
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 152:
#line 2091 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 153:
#line 2096 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l), 
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 154:
#line 2104 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 155:
#line 2109 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l), 
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    ;}
    break;

  case 156:
#line 2119 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d), 
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 157:
#line 2126 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d), 
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 158:
#line 2133 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d), 
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 159:
#line 2140 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d), 
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 160:
#line 2147 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d), 
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 161:
#line 2154 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d), 
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 162:
#line 2161 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d), 
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 163:
#line 2168 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d), 
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 164:
#line 2175 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d), 
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 165:
#line 2182 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 166:
#line 2187 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d), 
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 167:
#line 2194 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 168:
#line 2199 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d), 
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 169:
#line 2206 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 170:
#line 2211 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d), 
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 171:
#line 2218 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 172:
#line 2223 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d), 
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 173:
#line 2230 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 174:
#line 2235 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d), 
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 175:
#line 2242 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 176:
#line 2247 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d), 
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 177:
#line 2254 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 178:
#line 2259 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d), 
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 179:
#line 2266 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 180:
#line 2271 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d), 
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 181:
#line 2278 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 182:
#line 2283 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d), 
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 183:
#line 2294 "Gmsh.y"
    {
    ;}
    break;

  case 184:
#line 2297 "Gmsh.y"
    {
    ;}
    break;

  case 185:
#line 2303 "Gmsh.y"
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

  case 186:
#line 2329 "Gmsh.y"
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

  case 187:
#line 2353 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 188:
#line 2362 "Gmsh.y"
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

  case 189:
#line 2380 "Gmsh.y"
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

  case 190:
#line 2398 "Gmsh.y"
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

  case 191:
#line 2416 "Gmsh.y"
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

  case 192:
#line 2445 "Gmsh.y"
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

  case 193:
#line 2480 "Gmsh.y"
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

  case 194:
#line 2507 "Gmsh.y"
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

  case 195:
#line 2534 "Gmsh.y"
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

  case 196:
#line 2548 "Gmsh.y"
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

  case 197:
#line 2567 "Gmsh.y"
    { 
      ReplaceAllDuplicates(THEM);
    ;}
    break;

  case 198:
#line 2571 "Gmsh.y"
    { 
      IntersectAllSegmentsTogether();
    ;}
    break;

  case 199:
#line 2580 "Gmsh.y"
    { (yyval.d) = (yyvsp[0].d);           ;}
    break;

  case 200:
#line 2581 "Gmsh.y"
    { (yyval.d) = (yyvsp[-1].d);           ;}
    break;

  case 201:
#line 2582 "Gmsh.y"
    { (yyval.d) = -(yyvsp[0].d);          ;}
    break;

  case 202:
#line 2583 "Gmsh.y"
    { (yyval.d) = (yyvsp[0].d);           ;}
    break;

  case 203:
#line 2584 "Gmsh.y"
    { (yyval.d) = !(yyvsp[0].d);          ;}
    break;

  case 204:
#line 2585 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      ;}
    break;

  case 205:
#line 2586 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      ;}
    break;

  case 206:
#line 2587 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      ;}
    break;

  case 207:
#line 2589 "Gmsh.y"
    { 
      if(!(yyvsp[0].d))
	yymsg(GERROR, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);     
    ;}
    break;

  case 208:
#line 2595 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  ;}
    break;

  case 209:
#line 2596 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  ;}
    break;

  case 210:
#line 2597 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      ;}
    break;

  case 211:
#line 2598 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      ;}
    break;

  case 212:
#line 2599 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     ;}
    break;

  case 213:
#line 2600 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     ;}
    break;

  case 214:
#line 2601 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     ;}
    break;

  case 215:
#line 2602 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     ;}
    break;

  case 216:
#line 2603 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     ;}
    break;

  case 217:
#line 2604 "Gmsh.y"
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     ;}
    break;

  case 218:
#line 2605 "Gmsh.y"
    { (yyval.d) = (yyvsp[-4].d)? (yyvsp[-2].d) : (yyvsp[0].d);  ;}
    break;

  case 219:
#line 2606 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[-1].d));      ;}
    break;

  case 220:
#line 2607 "Gmsh.y"
    { (yyval.d) = log((yyvsp[-1].d));      ;}
    break;

  case 221:
#line 2608 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[-1].d));    ;}
    break;

  case 222:
#line 2609 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-1].d));     ;}
    break;

  case 223:
#line 2610 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[-1].d));      ;}
    break;

  case 224:
#line 2611 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[-1].d));     ;}
    break;

  case 225:
#line 2612 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[-1].d));      ;}
    break;

  case 226:
#line 2613 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[-1].d));     ;}
    break;

  case 227:
#line 2614 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[-1].d));      ;}
    break;

  case 228:
#line 2615 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[-1].d));     ;}
    break;

  case 229:
#line 2616 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));;}
    break;

  case 230:
#line 2617 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[-1].d));     ;}
    break;

  case 231:
#line 2618 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[-1].d));     ;}
    break;

  case 232:
#line 2619 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[-1].d));     ;}
    break;

  case 233:
#line 2620 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[-1].d));     ;}
    break;

  case 234:
#line 2621 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[-1].d));    ;}
    break;

  case 235:
#line 2622 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[-1].d));     ;}
    break;

  case 236:
#line 2623 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 237:
#line 2624 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 238:
#line 2625 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-3].d)*(yyvsp[-3].d)+(yyvsp[-1].d)*(yyvsp[-1].d)); ;}
    break;

  case 239:
#line 2626 "Gmsh.y"
    { (yyval.d) = (yyvsp[-1].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 240:
#line 2628 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[-1].d));      ;}
    break;

  case 241:
#line 2629 "Gmsh.y"
    { (yyval.d) = log((yyvsp[-1].d));      ;}
    break;

  case 242:
#line 2630 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[-1].d));    ;}
    break;

  case 243:
#line 2631 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-1].d));     ;}
    break;

  case 244:
#line 2632 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[-1].d));      ;}
    break;

  case 245:
#line 2633 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[-1].d));     ;}
    break;

  case 246:
#line 2634 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[-1].d));      ;}
    break;

  case 247:
#line 2635 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[-1].d));     ;}
    break;

  case 248:
#line 2636 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[-1].d));      ;}
    break;

  case 249:
#line 2637 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[-1].d));     ;}
    break;

  case 250:
#line 2638 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));;}
    break;

  case 251:
#line 2639 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[-1].d));     ;}
    break;

  case 252:
#line 2640 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[-1].d));     ;}
    break;

  case 253:
#line 2641 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[-1].d));     ;}
    break;

  case 254:
#line 2642 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[-1].d));     ;}
    break;

  case 255:
#line 2643 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[-1].d));    ;}
    break;

  case 256:
#line 2644 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[-1].d));     ;}
    break;

  case 257:
#line 2645 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 258:
#line 2646 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); ;}
    break;

  case 259:
#line 2647 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[-3].d)*(yyvsp[-3].d)+(yyvsp[-1].d)*(yyvsp[-1].d)); ;}
    break;

  case 260:
#line 2648 "Gmsh.y"
    { (yyval.d) = (yyvsp[-1].d)*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 261:
#line 2657 "Gmsh.y"
    { (yyval.d) = (yyvsp[0].d); ;}
    break;

  case 262:
#line 2658 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 263:
#line 2659 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->rank(); ;}
    break;

  case 264:
#line 2660 "Gmsh.y"
    { (yyval.d) = ParUtil::Instance()->size(); ;}
    break;

  case 265:
#line 2661 "Gmsh.y"
    { (yyval.d) = GMSH_MAJOR_VERSION; ;}
    break;

  case 266:
#line 2662 "Gmsh.y"
    { (yyval.d) = GMSH_MINOR_VERSION; ;}
    break;

  case 267:
#line 2663 "Gmsh.y"
    { (yyval.d) = GMSH_PATCH_VERSION; ;}
    break;

  case 268:
#line 2668 "Gmsh.y"
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

  case 269:
#line 2681 "Gmsh.y"
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

  case 270:
#line 2701 "Gmsh.y"
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

  case 271:
#line 2715 "Gmsh.y"
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

  case 272:
#line 2728 "Gmsh.y"
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

  case 273:
#line 2751 "Gmsh.y"
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

  case 274:
#line 2769 "Gmsh.y"
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

  case 275:
#line 2787 "Gmsh.y"
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

  case 276:
#line 2805 "Gmsh.y"
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

  case 277:
#line 2823 "Gmsh.y"
    { 
      (yyval.d) = GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    ;}
    break;

  case 278:
#line 2831 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    ;}
    break;

  case 279:
#line 2835 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    ;}
    break;

  case 280:
#line 2839 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    ;}
    break;

  case 281:
#line 2843 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    ;}
    break;

  case 282:
#line 2847 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    ;}
    break;

  case 283:
#line 2854 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    ;}
    break;

  case 284:
#line 2858 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 285:
#line 2862 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 286:
#line 2866 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 287:
#line 2873 "Gmsh.y"
    {
    ;}
    break;

  case 288:
#line 2876 "Gmsh.y"
    {
       (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 289:
#line 2880 "Gmsh.y"
    {
       (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 290:
#line 2887 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    ;}
    break;

  case 291:
#line 2892 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    ;}
    break;

  case 292:
#line 2900 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    ;}
    break;

  case 293:
#line 2905 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[0].l);
    ;}
    break;

  case 294:
#line 2909 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 295:
#line 2914 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 296:
#line 2918 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
      double *pd;
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 297:
#line 2930 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d)); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 298:
#line 2936 "Gmsh.y"
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

  case 299:
#line 2947 "Gmsh.y"
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

  case 300:
#line 2967 "Gmsh.y"
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

  case 301:
#line 2977 "Gmsh.y"
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

  case 302:
#line 2987 "Gmsh.y"
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
#line 2997 "Gmsh.y"
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

  case 304:
#line 3014 "Gmsh.y"
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

  case 305:
#line 3033 "Gmsh.y"
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

  case 306:
#line 3057 "Gmsh.y"
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

  case 307:
#line 3086 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    ;}
    break;

  case 308:
#line 3091 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[0].l);
    ;}
    break;

  case 309:
#line 3095 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    ;}
    break;

  case 310:
#line 3099 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    ;}
    break;

  case 311:
#line 3112 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    ;}
    break;

  case 312:
#line 3116 "Gmsh.y"
    {
      (yyval.u) = CTX.PACK_COLOR((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    ;}
    break;

  case 313:
#line 3128 "Gmsh.y"
    {
      int flag;
      (yyval.u) = Get_ColorForString(ColorString, -1, (yyvsp[0].c), &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    ;}
    break;

  case 314:
#line 3135 "Gmsh.y"
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

  case 315:
#line 3157 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
    ;}
    break;

  case 316:
#line 3161 "Gmsh.y"
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

  case 317:
#line 3176 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    ;}
    break;

  case 318:
#line 3181 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    ;}
    break;

  case 319:
#line 3188 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[0].c);
    ;}
    break;

  case 320:
#line 3192 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32*sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 321:
#line 3200 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-3].c))+strlen((yyvsp[-1].c))+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-3].c));
      strcat((yyval.c), (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    ;}
    break;

  case 322:
#line 3208 "Gmsh.y"
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

  case 323:
#line 3222 "Gmsh.y"
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

  case 324:
#line 3236 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[-1].c);
    ;}
    break;

  case 325:
#line 3240 "Gmsh.y"
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

  case 326:
#line 3259 "Gmsh.y"
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

  case 327:
#line 3281 "Gmsh.y"
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


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 7302 "Gmsh.tab.cpp"

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
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
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
	  int yychecklim = YYLAST - yyn;
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
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
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
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

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
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 3304 "Gmsh.y"


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

