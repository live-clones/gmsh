/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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
     tB_SPLINE_SURFACE_WITH_KNOTS = 361,
     tB_SPLINE_CURVE_WITH_KNOTS = 362,
     tCARTESIAN_POINT = 363,
     tTRUE = 364,
     tFALSE = 365,
     tUNSPECIFIED = 366,
     tU = 367,
     tV = 368,
     tEDGE_CURVE = 369,
     tVERTEX_POINT = 370,
     tORIENTED_EDGE = 371,
     tPLANE = 372,
     tFACE_OUTER_BOUND = 373,
     tEDGE_LOOP = 374,
     tADVANCED_FACE = 375,
     tVECTOR = 376,
     tDIRECTION = 377,
     tAXIS2_PLACEMENT_3D = 378,
     tISO = 379,
     tENDISO = 380,
     tENDSEC = 381,
     tDATA = 382,
     tHEADER = 383,
     tFILE_DESCRIPTION = 384,
     tFILE_SCHEMA = 385,
     tFILE_NAME = 386,
     tMANIFOLD_SOLID_BREP = 387,
     tCLOSED_SHELL = 388,
     tADVANCED_BREP_SHAPE_REPRESENTATION = 389,
     tFACE_BOUND = 390,
     tCYLINDRICAL_SURFACE = 391,
     tCONICAL_SURFACE = 392,
     tCIRCLE = 393,
     tTRIMMED_CURVE = 394,
     tGEOMETRIC_SET = 395,
     tCOMPOSITE_CURVE_SEGMENT = 396,
     tCONTINUOUS = 397,
     tCOMPOSITE_CURVE = 398,
     tTOROIDAL_SURFACE = 399,
     tPRODUCT_DEFINITION = 400,
     tPRODUCT_DEFINITION_SHAPE = 401,
     tSHAPE_DEFINITION_REPRESENTATION = 402,
     tELLIPSE = 403,
     tAFFECTDIVIDE = 404,
     tAFFECTTIMES = 405,
     tAFFECTMINUS = 406,
     tAFFECTPLUS = 407,
     tOR = 408,
     tAND = 409,
     tAPPROXEQUAL = 410,
     tNOTEQUAL = 411,
     tEQUAL = 412,
     tGREATEROREQUAL = 413,
     tLESSOREQUAL = 414,
     tCROSSPRODUCT = 415,
     UNARYPREC = 416,
     tMINUSMINUS = 417,
     tPLUSPLUS = 418
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
#define tB_SPLINE_SURFACE_WITH_KNOTS 361
#define tB_SPLINE_CURVE_WITH_KNOTS 362
#define tCARTESIAN_POINT 363
#define tTRUE 364
#define tFALSE 365
#define tUNSPECIFIED 366
#define tU 367
#define tV 368
#define tEDGE_CURVE 369
#define tVERTEX_POINT 370
#define tORIENTED_EDGE 371
#define tPLANE 372
#define tFACE_OUTER_BOUND 373
#define tEDGE_LOOP 374
#define tADVANCED_FACE 375
#define tVECTOR 376
#define tDIRECTION 377
#define tAXIS2_PLACEMENT_3D 378
#define tISO 379
#define tENDISO 380
#define tENDSEC 381
#define tDATA 382
#define tHEADER 383
#define tFILE_DESCRIPTION 384
#define tFILE_SCHEMA 385
#define tFILE_NAME 386
#define tMANIFOLD_SOLID_BREP 387
#define tCLOSED_SHELL 388
#define tADVANCED_BREP_SHAPE_REPRESENTATION 389
#define tFACE_BOUND 390
#define tCYLINDRICAL_SURFACE 391
#define tCONICAL_SURFACE 392
#define tCIRCLE 393
#define tTRIMMED_CURVE 394
#define tGEOMETRIC_SET 395
#define tCOMPOSITE_CURVE_SEGMENT 396
#define tCONTINUOUS 397
#define tCOMPOSITE_CURVE 398
#define tTOROIDAL_SURFACE 399
#define tPRODUCT_DEFINITION 400
#define tPRODUCT_DEFINITION_SHAPE 401
#define tSHAPE_DEFINITION_REPRESENTATION 402
#define tELLIPSE 403
#define tAFFECTDIVIDE 404
#define tAFFECTTIMES 405
#define tAFFECTMINUS 406
#define tAFFECTPLUS 407
#define tOR 408
#define tAND 409
#define tAPPROXEQUAL 410
#define tNOTEQUAL 411
#define tEQUAL 412
#define tGREATEROREQUAL 413
#define tLESSOREQUAL 414
#define tCROSSPRODUCT 415
#define UNARYPREC 416
#define tMINUSMINUS 417
#define tPLUSPLUS 418




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// $Id: Gmsh.tab.cpp,v 1.240 2005-07-14 14:28:15 remacle Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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
#include "StepGeomDatabase.h"
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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 79 "Gmsh.y"
typedef union YYSTYPE {
  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 489 "Gmsh.tab.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 501 "Gmsh.tab.cpp"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
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
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
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
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6269

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  183
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  69
/* YYNRULES -- Number of rules. */
#define YYNRULES  368
/* YYNRULES -- Number of states. */
#define YYNSTATES  1506

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   418

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   169,     2,   179,     2,   167,     2,     2,
     174,   175,   165,   163,   180,   164,   178,   166,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     159,     2,   160,   153,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   176,     2,   177,   173,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   181,     2,   182,     2,     2,     2,     2,
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
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   154,   155,
     156,   157,   158,   161,   162,   168,   170,   171,   172
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    11,    14,    16,    18,
      20,    23,    26,    29,    32,    35,    43,    49,    67,    77,
     101,   133,   149,   161,   173,   189,   199,   213,   223,   235,
     249,   259,   269,   281,   291,   303,   313,   325,   339,   353,
     365,   379,   397,   407,   419,   431,   445,   457,   467,   468,
     471,   473,   475,   477,   479,   481,   483,   485,   487,   489,
     491,   493,   495,   497,   499,   505,   513,   520,   529,   530,
     533,   536,   539,   542,   545,   547,   551,   553,   557,   558,
     559,   570,   572,   576,   577,   591,   593,   597,   598,   614,
     623,   624,   631,   633,   635,   637,   639,   641,   643,   645,
     650,   658,   668,   675,   679,   686,   693,   703,   710,   720,
     726,   735,   744,   756,   763,   773,   783,   793,   801,   810,
     823,   830,   838,   846,   854,   864,   872,   882,   900,   908,
     916,   928,   937,   950,   959,   968,   977,   990,  1013,  1034,
    1043,  1052,  1061,  1069,  1078,  1084,  1096,  1102,  1112,  1114,
    1116,  1118,  1119,  1122,  1129,  1136,  1143,  1150,  1155,  1162,
    1169,  1176,  1181,  1188,  1192,  1197,  1203,  1207,  1211,  1216,
    1221,  1225,  1233,  1237,  1245,  1249,  1252,  1255,  1271,  1274,
    1281,  1290,  1299,  1310,  1312,  1315,  1317,  1321,  1326,  1328,
    1337,  1350,  1365,  1366,  1379,  1380,  1397,  1398,  1417,  1426,
    1439,  1454,  1455,  1468,  1469,  1486,  1487,  1506,  1515,  1528,
    1543,  1544,  1557,  1558,  1575,  1576,  1595,  1597,  1600,  1610,
    1618,  1621,  1628,  1638,  1648,  1657,  1667,  1676,  1685,  1692,
    1697,  1700,  1703,  1705,  1707,  1709,  1711,  1713,  1715,  1719,
    1722,  1725,  1728,  1732,  1736,  1740,  1744,  1748,  1752,  1756,
    1760,  1764,  1768,  1772,  1776,  1780,  1784,  1790,  1795,  1800,
    1805,  1810,  1815,  1820,  1825,  1830,  1835,  1840,  1847,  1852,
    1857,  1862,  1867,  1872,  1877,  1884,  1891,  1898,  1903,  1908,
    1913,  1918,  1923,  1928,  1933,  1938,  1943,  1948,  1953,  1960,
    1965,  1970,  1975,  1980,  1985,  1990,  1997,  2004,  2011,  2016,
    2018,  2020,  2022,  2024,  2026,  2028,  2030,  2032,  2037,  2042,
    2045,  2051,  2055,  2062,  2067,  2075,  2082,  2084,  2087,  2090,
    2094,  2098,  2110,  2120,  2128,  2136,  2137,  2141,  2143,  2147,
    2148,  2152,  2156,  2158,  2162,  2164,  2166,  2170,  2175,  2179,
    2185,  2190,  2192,  2194,  2196,  2200,  2205,  2212,  2220,  2222,
    2224,  2228,  2232,  2242,  2250,  2252,  2258,  2262,  2269,  2271,
    2275,  2277,  2279,  2286,  2291,  2296,  2301,  2308,  2315
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     184,     0,    -1,   185,    -1,   190,    -1,     1,     6,    -1,
      -1,   185,   186,    -1,   187,    -1,   189,    -1,   188,    -1,
     124,     6,    -1,   125,     6,    -1,   127,     6,    -1,   126,
       6,    -1,   128,     6,    -1,   129,   174,   241,   180,     5,
     175,     6,    -1,   130,   174,   241,   175,     6,    -1,   131,
     174,     5,   180,     5,   180,   241,   180,   241,   180,     5,
     180,     5,   180,     5,   175,     6,    -1,     3,     7,   108,
     174,     5,   180,   239,   175,     6,    -1,     3,     7,   107,
     174,     5,   180,   237,   180,   245,   180,   236,   180,   236,
     180,   236,   180,   245,   180,   245,   180,   236,   175,     6,
      -1,     3,     7,   106,   174,     5,   180,   237,   180,   237,
     180,   243,   180,   236,   180,   236,   180,   236,   180,   236,
     180,   245,   180,   245,   180,   245,   180,   245,   180,   236,
     175,     6,    -1,     3,     7,   114,   174,     5,   180,     3,
     180,     3,   180,     3,   180,   236,   175,     6,    -1,     3,
       7,   118,   174,     5,   180,     3,   180,   236,   175,     6,
      -1,     3,     7,   135,   174,     5,   180,     3,   180,   236,
     175,     6,    -1,     3,     7,   116,   174,     5,   180,   165,
     180,   165,   180,   237,   180,   236,   175,     6,    -1,     3,
       7,   119,   174,     5,   180,   245,   175,     6,    -1,     3,
       7,   120,   174,     5,   180,   245,   180,     3,   180,   236,
     175,     6,    -1,     3,     7,   115,   174,     5,   180,     3,
     175,     6,    -1,     3,     7,   121,   174,     5,   180,     3,
     180,   237,   175,     6,    -1,     3,     7,   123,   174,     5,
     180,     3,   180,     3,   180,     3,   175,     6,    -1,     3,
       7,   122,   174,     5,   180,   239,   175,     6,    -1,     3,
       7,   117,   174,     5,   180,     3,   175,     6,    -1,     3,
       7,    44,   174,     5,   180,     3,   180,     3,   175,     6,
      -1,     3,     7,   133,   174,     5,   180,   245,   175,     6,
      -1,     3,     7,   134,   174,     5,   180,   245,   180,     3,
     175,     6,    -1,     3,     7,   132,   174,     5,   180,     3,
     175,     6,    -1,     3,     7,   136,   174,     5,   180,     3,
     180,   237,   175,     6,    -1,     3,     7,   137,   174,     5,
     180,     3,   180,   237,   180,   237,   175,     6,    -1,     3,
       7,   144,   174,     5,   180,     3,   180,   237,   180,   237,
     175,     6,    -1,     3,     7,   138,   174,     5,   180,     3,
     180,   237,   175,     6,    -1,     3,     7,   148,   174,     5,
     180,     3,   180,   237,   180,   237,   175,     6,    -1,     3,
       7,   139,   174,     5,   180,     3,   180,   245,   180,   245,
     180,   236,   180,   236,   175,     6,    -1,     3,     7,   140,
     174,     5,   180,   245,   175,     6,    -1,     3,     7,   141,
     174,   142,   180,   236,   180,     3,   175,     6,    -1,     3,
       7,   143,   174,     5,   180,   245,   180,   236,   175,     6,
      -1,     3,     7,   145,   174,     5,   180,     5,   180,     3,
     180,     3,   175,     6,    -1,     3,     7,   146,   174,     5,
     180,     5,   180,     3,   175,     6,    -1,     3,     7,   147,
     174,     3,   180,     3,   175,     6,    -1,    -1,   190,   191,
      -1,   193,    -1,   192,    -1,   211,    -1,   212,    -1,   213,
      -1,   216,    -1,   217,    -1,   218,    -1,   219,    -1,   222,
      -1,   234,    -1,   235,    -1,   221,    -1,   220,    -1,    33,
     174,     5,   175,     6,    -1,    33,   174,     5,   180,   247,
     175,     6,    -1,     4,     5,   181,   194,   182,     6,    -1,
       4,     5,     4,   239,   181,   194,   182,     6,    -1,    -1,
     194,   197,    -1,   194,   201,    -1,   194,   204,    -1,   194,
     206,    -1,   194,   207,    -1,   237,    -1,   195,   180,   237,
      -1,   237,    -1,   196,   180,   237,    -1,    -1,    -1,     4,
     198,   174,   195,   175,   199,   181,   196,   182,     6,    -1,
     251,    -1,   200,   180,   251,    -1,    -1,    76,   174,   237,
     180,   237,   180,   237,   175,   202,   181,   200,   182,     6,
      -1,   251,    -1,   203,   180,   251,    -1,    -1,    77,   174,
     237,   180,   237,   180,   237,   180,   237,   175,   205,   181,
     203,   182,     6,    -1,    78,   181,   244,   182,   181,   244,
     182,     6,    -1,    -1,    79,   208,   181,   196,   182,     6,
      -1,     7,    -1,   152,    -1,   151,    -1,   150,    -1,   149,
      -1,   172,    -1,   171,    -1,     4,   209,   237,     6,    -1,
       4,   176,   237,   177,   209,   237,     6,    -1,     4,   176,
     181,   247,   182,   177,   209,   245,     6,    -1,     4,   176,
     177,     7,   245,     6,    -1,     4,   210,     6,    -1,     4,
     176,   237,   177,   210,     6,    -1,     4,   178,     4,     7,
     251,     6,    -1,     4,   176,   237,   177,   178,     4,     7,
     251,     6,    -1,     4,   178,     4,   209,   237,     6,    -1,
       4,   176,   237,   177,   178,     4,   209,   237,     6,    -1,
       4,   178,     4,   210,     6,    -1,     4,   176,   237,   177,
     178,     4,   210,     6,    -1,     4,   178,    88,   178,     4,
       7,   248,     6,    -1,     4,   176,   237,   177,   178,    88,
     178,     4,     7,   248,     6,    -1,     4,   178,    89,     7,
     249,     6,    -1,     4,   176,   237,   177,   178,    89,     7,
     249,     6,    -1,    60,   174,     4,   175,   178,     4,     7,
     237,     6,    -1,    60,   174,     4,   175,   178,     4,     7,
     251,     6,    -1,    41,   174,   237,   175,     7,   239,     6,
      -1,    56,    41,   174,   237,   175,     7,   245,     6,    -1,
      72,    41,   245,     7,   181,   237,   180,   237,   180,   237,
     182,     6,    -1,    48,    49,   245,     7,   237,     6,    -1,
      44,   174,   237,   175,     7,   245,     6,    -1,    46,   174,
     237,   175,     7,   245,     6,    -1,    42,   174,   237,   175,
       7,   245,     6,    -1,    42,   174,   237,   175,     7,   245,
      52,   239,     6,    -1,    43,   174,   237,   175,     7,   245,
       6,    -1,    43,   174,   237,   175,     7,   245,    52,   239,
       6,    -1,    50,   174,   237,   175,     7,   181,   237,   180,
     237,   180,     5,   180,     5,   180,     5,   182,     6,    -1,
      81,   174,   237,   175,     7,   245,     6,    -1,    82,   174,
     237,   175,     7,   245,     6,    -1,    83,   174,   237,   175,
       7,   245,    87,   245,    84,   237,     6,    -1,    44,    67,
     174,   237,   175,     7,   245,     6,    -1,    72,    44,   245,
       7,   181,   237,   180,   237,   180,   237,   182,     6,    -1,
      56,    44,   174,   237,   175,     7,   245,     6,    -1,    52,
      45,   174,   237,   175,     7,   245,     6,    -1,    53,    45,
     174,   237,   175,     7,   245,     6,    -1,    99,    45,   174,
     237,   175,     7,   181,   237,   180,   245,   182,     6,    -1,
      83,    45,    85,    86,   174,   237,   175,     7,   243,    87,
     181,   245,   180,   245,   182,    84,   181,   237,   180,   237,
     182,     6,    -1,    83,    45,   174,   237,   175,     7,   243,
      87,   181,   245,   180,   245,   182,    84,   181,   237,   180,
     237,   182,     6,    -1,    45,    67,   174,   237,   175,     7,
     245,     6,    -1,    56,    45,   174,   237,   175,     7,   245,
       6,    -1,    55,    47,   174,   237,   175,     7,   245,     6,
      -1,    47,   174,   237,   175,     7,   245,     6,    -1,    56,
      47,   174,   237,   175,     7,   245,     6,    -1,    62,   239,
     181,   214,   182,    -1,    61,   181,   239,   180,   239,   180,
     237,   182,   181,   214,   182,    -1,    63,   239,   181,   214,
     182,    -1,    64,   181,   239,   180,   237,   182,   181,   214,
     182,    -1,   216,    -1,   215,    -1,   213,    -1,    -1,   215,
     212,    -1,   215,    41,   181,   247,   182,     6,    -1,   215,
      44,   181,   247,   182,     6,    -1,   215,    45,   181,   247,
     182,     6,    -1,   215,    47,   181,   247,   182,     6,    -1,
      66,   181,   215,   182,    -1,    66,     4,   176,   237,   177,
       6,    -1,    74,     4,   176,   237,   177,     6,    -1,    75,
       4,   176,   237,   177,     6,    -1,    69,   181,   215,   182,
      -1,    69,     4,   176,   237,   177,     6,    -1,    69,     4,
       6,    -1,    69,     4,     4,     6,    -1,    88,   248,   181,
     215,   182,    -1,   100,   251,     6,    -1,   101,   251,     6,
      -1,   100,   181,   215,   182,    -1,   101,   181,   215,   182,
      -1,     4,   251,     6,    -1,     4,     4,   176,   237,   177,
     251,     6,    -1,     4,   237,     6,    -1,    60,   174,     4,
     175,   178,     4,     6,    -1,    80,     4,     6,    -1,    95,
       6,    -1,    38,     6,    -1,    38,   181,   237,   180,   237,
     180,   237,   180,   237,   180,   237,   180,   237,   182,     6,
      -1,    39,     6,    -1,    90,   174,   237,     8,   237,   175,
      -1,    90,   174,   237,     8,   237,     8,   237,   175,    -1,
      90,     4,    91,   181,   237,     8,   237,   182,    -1,    90,
       4,    91,   181,   237,     8,   237,     8,   237,   182,    -1,
      92,    -1,    98,     4,    -1,    96,    -1,    97,     4,     6,
      -1,    93,   174,   237,   175,    -1,    94,    -1,    65,    41,
     181,   237,   180,   239,   182,     6,    -1,    65,    41,   181,
     237,   180,   239,   180,   239,   180,   237,   182,     6,    -1,
      65,    41,   181,   237,   180,   239,   180,   239,   180,   239,
     180,   237,   182,     6,    -1,    -1,    65,    41,   181,   237,
     180,   239,   182,   223,   181,   232,   182,     6,    -1,    -1,
      65,    41,   181,   237,   180,   239,   180,   239,   180,   237,
     182,   224,   181,   232,   182,     6,    -1,    -1,    65,    41,
     181,   237,   180,   239,   180,   239,   180,   239,   180,   237,
     182,   225,   181,   232,   182,     6,    -1,    65,    44,   181,
     237,   180,   239,   182,     6,    -1,    65,    44,   181,   237,
     180,   239,   180,   239,   180,   237,   182,     6,    -1,    65,
      44,   181,   237,   180,   239,   180,   239,   180,   239,   180,
     237,   182,     6,    -1,    -1,    65,    44,   181,   237,   180,
     239,   182,   226,   181,   232,   182,     6,    -1,    -1,    65,
      44,   181,   237,   180,   239,   180,   239,   180,   237,   182,
     227,   181,   232,   182,     6,    -1,    -1,    65,    44,   181,
     237,   180,   239,   180,   239,   180,   239,   180,   237,   182,
     228,   181,   232,   182,     6,    -1,    65,    45,   181,   237,
     180,   239,   182,     6,    -1,    65,    45,   181,   237,   180,
     239,   180,   239,   180,   237,   182,     6,    -1,    65,    45,
     181,   237,   180,   239,   180,   239,   180,   239,   180,   237,
     182,     6,    -1,    -1,    65,    45,   181,   237,   180,   239,
     182,   229,   181,   232,   182,     6,    -1,    -1,    65,    45,
     181,   237,   180,   239,   180,   239,   180,   237,   182,   230,
     181,   232,   182,     6,    -1,    -1,    65,    45,   181,   237,
     180,   239,   180,   239,   180,   239,   180,   237,   182,   231,
     181,   232,   182,     6,    -1,   233,    -1,   232,   233,    -1,
      73,   181,   245,   180,   245,   180,   245,   182,     6,    -1,
      73,   181,   245,   180,   245,   182,     6,    -1,    68,     6,
      -1,    54,    44,   245,     7,   237,     6,    -1,    54,    44,
     245,     7,   237,    57,    59,   237,     6,    -1,    54,    44,
     245,     7,   237,    57,    58,   237,     6,    -1,    54,    45,
     181,   237,   182,     7,   245,     6,    -1,    54,    45,   181,
     237,   182,     7,   245,     4,     6,    -1,    51,    45,   181,
     237,   182,     7,   245,     6,    -1,    54,    47,   181,   237,
     182,     7,   245,     6,    -1,    68,    45,   245,     7,   237,
       6,    -1,    68,    45,   245,     6,    -1,    70,     6,    -1,
      71,     6,    -1,   109,    -1,   110,    -1,   111,    -1,   112,
      -1,   113,    -1,   238,    -1,   174,   237,   175,    -1,   164,
     237,    -1,   163,   237,    -1,   169,   237,    -1,   237,   164,
     237,    -1,   237,   163,   237,    -1,   237,   165,   237,    -1,
     237,   166,   237,    -1,   237,   167,   237,    -1,   237,   173,
     237,    -1,   237,   159,   237,    -1,   237,   160,   237,    -1,
     237,   162,   237,    -1,   237,   161,   237,    -1,   237,   158,
     237,    -1,   237,   157,   237,    -1,   237,   155,   237,    -1,
     237,   154,   237,    -1,   237,   153,   237,     8,   237,    -1,
      12,   174,   237,   175,    -1,    13,   174,   237,   175,    -1,
      14,   174,   237,   175,    -1,    15,   174,   237,   175,    -1,
      16,   174,   237,   175,    -1,    17,   174,   237,   175,    -1,
      18,   174,   237,   175,    -1,    19,   174,   237,   175,    -1,
      20,   174,   237,   175,    -1,    22,   174,   237,   175,    -1,
      23,   174,   237,   180,   237,   175,    -1,    24,   174,   237,
     175,    -1,    25,   174,   237,   175,    -1,    26,   174,   237,
     175,    -1,    27,   174,   237,   175,    -1,    28,   174,   237,
     175,    -1,    29,   174,   237,   175,    -1,    30,   174,   237,
     180,   237,   175,    -1,    31,   174,   237,   180,   237,   175,
      -1,    32,   174,   237,   180,   237,   175,    -1,    21,   174,
     237,   175,    -1,    12,   176,   237,   177,    -1,    13,   176,
     237,   177,    -1,    14,   176,   237,   177,    -1,    15,   176,
     237,   177,    -1,    16,   176,   237,   177,    -1,    17,   176,
     237,   177,    -1,    18,   176,   237,   177,    -1,    19,   176,
     237,   177,    -1,    20,   176,   237,   177,    -1,    22,   176,
     237,   177,    -1,    23,   176,   237,   180,   237,   177,    -1,
      24,   176,   237,   177,    -1,    25,   176,   237,   177,    -1,
      26,   176,   237,   177,    -1,    27,   176,   237,   177,    -1,
      28,   176,   237,   177,    -1,    29,   176,   237,   177,    -1,
      30,   176,   237,   180,   237,   177,    -1,    31,   176,   237,
     180,   237,   177,    -1,    32,   176,   237,   180,   237,   177,
      -1,    21,   176,   237,   177,    -1,     3,    -1,     9,    -1,
      10,    -1,    11,    -1,   103,    -1,   104,    -1,   105,    -1,
       4,    -1,     4,   176,   237,   177,    -1,   179,     4,   176,
     177,    -1,     4,   210,    -1,     4,   176,   237,   177,   210,
      -1,     4,   178,     4,    -1,     4,   176,   237,   177,   178,
       4,    -1,     4,   178,     4,   210,    -1,     4,   176,   237,
     177,   178,     4,   210,    -1,   102,   174,     5,   180,   237,
     175,    -1,   240,    -1,   164,   239,    -1,   163,   239,    -1,
     239,   164,   239,    -1,   239,   163,   239,    -1,   181,   237,
     180,   237,   180,   237,   180,   237,   180,   237,   182,    -1,
     181,   237,   180,   237,   180,   237,   180,   237,   182,    -1,
     181,   237,   180,   237,   180,   237,   182,    -1,   174,   237,
     180,   237,   180,   237,   175,    -1,    -1,   174,   242,   175,
      -1,     5,    -1,   242,   180,     5,    -1,    -1,   181,   244,
     182,    -1,   174,   244,   175,    -1,   245,    -1,   244,   180,
     245,    -1,   237,    -1,   246,    -1,   181,   247,   182,    -1,
     164,   181,   247,   182,    -1,   237,     8,   237,    -1,   237,
       8,   237,     8,   237,    -1,    41,   181,   237,   182,    -1,
     213,    -1,   216,    -1,   222,    -1,     4,   176,   177,    -1,
     164,     4,   176,   177,    -1,     4,   176,   181,   247,   182,
     177,    -1,   164,     4,   176,   181,   247,   182,   177,    -1,
     237,    -1,   246,    -1,   247,   180,   237,    -1,   247,   180,
     246,    -1,   181,   237,   180,   237,   180,   237,   180,   237,
     182,    -1,   181,   237,   180,   237,   180,   237,   182,    -1,
       4,    -1,     4,   178,    88,   178,     4,    -1,   181,   250,
     182,    -1,     4,   176,   237,   177,   178,    89,    -1,   248,
      -1,   250,   180,   248,    -1,     5,    -1,    40,    -1,    35,
     174,   251,   180,   251,   175,    -1,    36,   174,   251,   175,
      -1,    37,   174,   251,   175,    -1,    34,   174,   251,   175,
      -1,    34,   174,   251,   180,   247,   175,    -1,    34,   174,
       4,   178,     4,   175,    -1,    34,   174,     4,   176,   237,
     177,   178,     4,   175,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   158,   158,   159,   160,   170,   172,   176,   177,   178,
     182,   187,   192,   193,   194,   198,   201,   204,   211,   215,
     221,   229,   234,   238,   244,   249,   253,   258,   262,   265,
     270,   274,   278,   282,   287,   291,   294,   298,   302,   306,
     310,   314,   318,   321,   325,   328,   332,   335,   342,   344,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   365,   370,   388,   395,   406,   412,
     413,   414,   415,   416,   420,   422,   427,   429,   435,   625,
     434,   653,   658,   667,   666,   680,   685,   694,   693,   707,
     716,   715,   727,   728,   729,   730,   731,   735,   736,   743,
     774,   813,   867,   884,   895,   914,   928,   945,   971,   998,
    1012,  1029,  1043,  1060,  1080,  1103,  1113,  1132,  1148,  1164,
    1183,  1202,  1220,  1238,  1256,  1282,  1300,  1326,  1346,  1370,
    1394,  1420,  1437,  1455,  1474,  1493,  1532,  1557,  1576,  1595,
    1611,  1631,  1648,  1665,  1686,  1691,  1696,  1701,  1709,  1710,
    1711,  1716,  1719,  1723,  1739,  1755,  1771,  1792,  1806,  1812,
    1818,  1830,  1839,  1849,  1863,  1882,  1896,  1904,  1910,  1921,
    1935,  1979,  1994,  2010,  2020,  2042,  2046,  2050,  2054,  2067,
    2082,  2098,  2124,  2151,  2183,  2190,  2195,  2201,  2205,  2216,
    2232,  2248,  2265,  2264,  2286,  2285,  2307,  2306,  2329,  2352,
    2375,  2399,  2398,  2427,  2426,  2455,  2454,  2485,  2508,  2531,
    2555,  2554,  2583,  2582,  2612,  2611,  2643,  2646,  2652,  2678,
    2702,  2711,  2729,  2747,  2765,  2794,  2829,  2856,  2883,  2897,
    2916,  2920,  2930,  2931,  2932,  2933,  2934,  2938,  2939,  2940,
    2941,  2942,  2943,  2944,  2945,  2946,  2953,  2954,  2955,  2956,
    2957,  2958,  2959,  2960,  2961,  2962,  2963,  2964,  2965,  2966,
    2967,  2968,  2969,  2970,  2971,  2972,  2973,  2974,  2975,  2976,
    2977,  2978,  2979,  2980,  2981,  2982,  2983,  2984,  2986,  2987,
    2988,  2989,  2990,  2991,  2992,  2993,  2994,  2995,  2996,  2997,
    2998,  2999,  3000,  3001,  3002,  3003,  3004,  3005,  3006,  3015,
    3016,  3017,  3018,  3019,  3020,  3021,  3025,  3038,  3058,  3072,
    3085,  3108,  3126,  3144,  3162,  3180,  3188,  3192,  3196,  3200,
    3204,  3211,  3215,  3219,  3223,  3231,  3233,  3239,  3242,  3249,
    3251,  3255,  3262,  3267,  3275,  3280,  3284,  3288,  3300,  3306,
    3317,  3337,  3347,  3357,  3369,  3386,  3405,  3429,  3458,  3463,
    3467,  3471,  3484,  3488,  3500,  3507,  3529,  3533,  3548,  3553,
    3560,  3564,  3572,  3580,  3594,  3608,  3612,  3631,  3653
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
  "tAtan", "tAtan2", "tSinh", "tCosh", "tTanh", "tFabs", "tFloor", 
  "tCeil", "tFmod", "tModulo", "tHypot", "tPrintf", "tSprintf", "tStrCat", 
  "tStrPrefix", "tStrRelative", "tBoundingBox", "tDraw", "tToday", 
  "tPoint", "tCircle", "tEllipse", "tLine", "tSurface", "tSpline", 
  "tVolume", "tCharacteristic", "tLength", "tParametric", "tElliptic", 
  "tPlane", "tRuled", "tTransfinite", "tComplex", "tPhysical", "tUsing", 
  "tBump", "tProgression", "tPlugin", "tRotate", "tTranslate", 
  "tSymmetry", "tDilate", "tExtrude", "tDuplicata", "tLoop", "tRecombine", 
  "tDelete", "tCoherence", "tIntersect", "tAttractor", "tLayers", 
  "tAlias", "tAliasWithOptions", "tText2D", "tText3D", 
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier", 
  "tNurbs", "tOrder", "tWith", "tBounds", "tKnots", "tColor", 
  "tColorTable", "tFor", "tIn", "tEndFor", "tIf", "tEndIf", "tExit", 
  "tReturn", "tCall", "tFunction", "tTrimmed", "tShow", "tHide", 
  "tGetValue", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION", 
  "tGMSH_PATCH_VERSION", "tB_SPLINE_SURFACE_WITH_KNOTS", 
  "tB_SPLINE_CURVE_WITH_KNOTS", "tCARTESIAN_POINT", "tTRUE", "tFALSE", 
  "tUNSPECIFIED", "tU", "tV", "tEDGE_CURVE", "tVERTEX_POINT", 
  "tORIENTED_EDGE", "tPLANE", "tFACE_OUTER_BOUND", "tEDGE_LOOP", 
  "tADVANCED_FACE", "tVECTOR", "tDIRECTION", "tAXIS2_PLACEMENT_3D", 
  "tISO", "tENDISO", "tENDSEC", "tDATA", "tHEADER", "tFILE_DESCRIPTION", 
  "tFILE_SCHEMA", "tFILE_NAME", "tMANIFOLD_SOLID_BREP", "tCLOSED_SHELL", 
  "tADVANCED_BREP_SHAPE_REPRESENTATION", "tFACE_BOUND", 
  "tCYLINDRICAL_SURFACE", "tCONICAL_SURFACE", "tCIRCLE", "tTRIMMED_CURVE", 
  "tGEOMETRIC_SET", "tCOMPOSITE_CURVE_SEGMENT", "tCONTINUOUS", 
  "tCOMPOSITE_CURVE", "tTOROIDAL_SURFACE", "tPRODUCT_DEFINITION", 
  "tPRODUCT_DEFINITION_SHAPE", "tSHAPE_DEFINITION_REPRESENTATION", 
  "tELLIPSE", "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS", 
  "tAFFECTPLUS", "'?'", "tOR", "tAND", "tAPPROXEQUAL", "tNOTEQUAL", 
  "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'", 
  "'*'", "'/'", "'%'", "tCROSSPRODUCT", "'!'", "UNARYPREC", "tMINUSMINUS", 
  "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'", "'#'", "','", 
  "'{'", "'}'", "$accept", "All", "StepFormatItems", "StepFormatItem", 
  "StepSpecial", "StepHeaderItem", "StepDataItem", "GeoFormatItems", 
  "GeoFormatItem", "Printf", "View", "Views", "ElementCoords", 
  "ElementValues", "Element", "@1", "@2", "Text2DValues", "Text2D", "@3", 
  "Text3DValues", "Text3D", "@4", "InterpolationMatrix", "Time", "@5", 
  "NumericAffectation", "NumericIncrement", "Affectation", "Shape", 
  "Transform", "MultipleShape", "ListOfShapes", "Duplicata", "Delete", 
  "Colorify", "Visibility", "Command", "Loop", "Extrude", "@6", "@7", 
  "@8", "@9", "@10", "@11", "@12", "@13", "@14", "ExtrudeParameters", 
  "ExtrudeParameter", "Transfinite", "Coherence", "BoolExpr", "FExpr", 
  "FExpr_Single", "VExpr", "VExpr_Single", "ListOfStrings", 
  "RecursiveListOfStrings", "ListOfListOfDouble", 
  "RecursiveListOfListOfDouble", "ListOfDouble", "FExpr_Multi", 
  "RecursiveListOfDouble", "ColorExpr", "ListOfColor", 
  "RecursiveListOfColor", "StringExpr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,    63,   408,   409,   410,   411,   412,    60,
      62,   413,   414,    43,    45,    42,    47,    37,   415,    33,
     416,   417,   418,    94,    40,    41,    91,    93,    46,    35,
      44,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   183,   184,   184,   184,   185,   185,   186,   186,   186,
     187,   187,   187,   187,   187,   188,   188,   188,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   190,   190,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   192,   192,   193,   193,   194,   194,
     194,   194,   194,   194,   195,   195,   196,   196,   198,   199,
     197,   200,   200,   202,   201,   203,   203,   205,   204,   206,
     208,   207,   209,   209,   209,   209,   209,   210,   210,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   213,   213,   213,   213,   214,   214,
     214,   215,   215,   215,   215,   215,   215,   216,   216,   216,
     216,   217,   217,   217,   217,   218,   219,   219,   219,   219,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   222,
     222,   222,   223,   222,   224,   222,   225,   222,   222,   222,
     222,   226,   222,   227,   222,   228,   222,   222,   222,   222,
     229,   222,   230,   222,   231,   222,   232,   232,   233,   233,
     233,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     235,   235,   236,   236,   236,   236,   236,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   239,   239,   239,   239,
     239,   240,   240,   240,   240,   241,   241,   242,   242,   243,
     243,   243,   244,   244,   245,   245,   245,   245,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   247,   247,
     247,   247,   248,   248,   248,   248,   249,   249,   250,   250,
     251,   251,   251,   251,   251,   251,   251,   251,   251
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     2,     0,     2,     1,     1,     1,
       2,     2,     2,     2,     2,     7,     5,    17,     9,    23,
      31,    15,    11,    11,    15,     9,    13,     9,    11,    13,
       9,     9,    11,     9,    11,     9,    11,    13,    13,    11,
      13,    17,     9,    11,    11,    13,    11,     9,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     7,     6,     8,     0,     2,
       2,     2,     2,     2,     1,     3,     1,     3,     0,     0,
      10,     1,     3,     0,    13,     1,     3,     0,    15,     8,
       0,     6,     1,     1,     1,     1,     1,     1,     1,     4,
       7,     9,     6,     3,     6,     6,     9,     6,     9,     5,
       8,     8,    11,     6,     9,     9,     9,     7,     8,    12,
       6,     7,     7,     7,     9,     7,     9,    17,     7,     7,
      11,     8,    12,     8,     8,     8,    12,    22,    20,     8,
       8,     8,     7,     8,     5,    11,     5,     9,     1,     1,
       1,     0,     2,     6,     6,     6,     6,     4,     6,     6,
       6,     4,     6,     3,     4,     5,     3,     3,     4,     4,
       3,     7,     3,     7,     3,     2,     2,    15,     2,     6,
       8,     8,    10,     1,     2,     1,     3,     4,     1,     8,
      12,    14,     0,    12,     0,    16,     0,    18,     8,    12,
      14,     0,    12,     0,    16,     0,    18,     8,    12,    14,
       0,    12,     0,    16,     0,    18,     1,     2,     9,     7,
       2,     6,     9,     9,     8,     9,     8,     8,     6,     4,
       2,     2,     1,     1,     1,     1,     1,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     6,     6,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     2,
       5,     3,     6,     4,     7,     6,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     0,     3,     1,     3,     0,
       3,     3,     1,     3,     1,     1,     3,     4,     3,     5,
       4,     1,     1,     1,     3,     4,     6,     7,     1,     1,
       3,     3,     9,     7,     1,     5,     3,     6,     1,     3,
       1,     1,     6,     4,     4,     4,     6,     6,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,     0,     0,     2,     3,     4,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     9,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
       0,   188,     0,   185,     0,     0,     0,     0,     0,    49,
      51,    50,    52,    53,    54,    55,    56,    57,    58,    63,
      62,    59,    60,    61,     0,    10,    11,    13,    12,    14,
     325,   325,     0,   299,   306,   360,    92,   300,   301,   302,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   361,     0,   303,   304,   305,
      96,    95,    94,    93,     0,     0,     0,    98,    97,     0,
       0,     0,     0,     0,     0,     0,   237,     0,     0,   176,
       0,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     316,     0,     0,     0,     0,     0,     0,   151,     0,     0,
     151,   230,   231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   354,     0,     0,     0,     0,     0,   175,     0,
     184,     0,   360,   151,     0,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   309,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   306,   240,   239,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   306,     0,     0,     0,   341,   342,
     343,   334,     0,   335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   318,   317,
       0,     0,     0,     0,   151,   151,     0,     0,     0,     0,
       0,     0,     0,     0,   163,     0,     0,     0,     0,     0,
       0,   174,     0,     0,     0,     0,     0,     0,     0,   151,
       0,     0,     0,   186,     0,     0,   166,     0,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   327,
       0,     0,     0,     0,     0,   311,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     0,     0,
     348,   349,     0,     0,    92,     0,     0,     0,     0,     0,
      99,     0,   255,   254,   253,   252,   248,   249,   251,   250,
     243,   242,   244,   245,   246,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     320,   319,   150,     0,   149,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   152,   229,     0,
     164,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   187,     0,   168,
     169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   326,     0,     0,    16,     0,   307,   313,    68,    78,
       0,     0,     0,    90,     0,    69,    70,    71,    72,    73,
     257,   278,   258,   279,   259,   280,   260,   281,   261,   282,
     262,   283,   263,   284,   264,   285,   265,   286,   277,   298,
     266,   287,     0,     0,   268,   289,   269,   290,   270,   291,
     271,   292,   272,   293,   273,   294,     0,     0,     0,     0,
       0,     0,     0,     0,   365,     0,     0,   363,   364,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
       0,     0,     0,     0,   308,     0,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   344,     0,     0,
       0,     0,   336,   338,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   328,
       0,   325,     0,   310,     0,     0,     0,     0,     0,     0,
       0,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   307,   102,   350,   351,     0,
       0,     0,     0,     0,   104,   105,   107,     0,     0,   358,
       0,   113,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   340,   345,     0,   337,     0,   120,
       0,     0,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   158,     0,     0,     0,     0,   228,   162,     0,     0,
     159,   160,     0,     0,     0,   329,     0,   355,     0,     0,
       0,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   232,   233,   234,   235,
     236,     0,     0,     0,     0,     0,     0,     0,    15,     0,
     312,   171,     0,     0,     0,     0,     0,   332,     0,   267,
     288,   274,   295,   275,   296,   276,   297,     0,   367,   366,
     362,   315,     0,    92,     0,     0,     0,     0,   100,     0,
       0,     0,   356,    65,     0,   117,   123,     0,   125,     0,
       0,   121,     0,   122,   142,     0,     0,   339,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,     0,     0,     0,     0,   151,     0,   192,     0,
     201,     0,   210,     0,     0,     0,     0,     0,     0,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     325,   314,    67,     0,    74,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,   110,     0,     0,   111,     0,
     359,     0,     0,     0,   131,   139,   346,     0,     0,   226,
     134,   135,     0,     0,     0,   224,   227,   141,   118,   133,
     140,   143,     0,     0,     0,   324,     0,   323,     0,     0,
     189,     0,     0,   198,     0,     0,   207,     0,   153,   154,
     155,   156,     0,     0,   329,     0,     0,     0,     0,     0,
     353,     0,   181,   180,     0,     0,     0,     0,    18,     0,
      27,     0,    31,     0,    25,     0,     0,    30,     0,    35,
      33,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,     0,     0,    47,     0,     0,    79,     0,     0,     0,
     333,     0,     0,     0,     0,   101,   106,   108,     0,   114,
       0,     0,   124,   126,   347,     0,   223,   222,   225,   115,
     116,   151,     0,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,   330,     0,     0,     0,     0,     0,
       0,   329,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,     0,     0,     0,    77,    91,   368,
       0,   357,     0,     0,     0,     0,   322,     0,     0,     0,
       0,     0,     0,     0,     0,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   352,   182,     0,
      32,     0,     0,     0,     0,    22,     0,    28,     0,    34,
      23,    36,     0,    39,     0,    43,    44,     0,     0,    46,
       0,     0,     0,     0,     0,     0,   112,     0,     0,   145,
       0,     0,   194,     0,   220,     0,     0,   217,   203,     0,
       0,   212,     0,     0,     0,     0,     0,     0,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,     0,    89,     0,     0,   321,   190,
       0,     0,     0,   193,   199,     0,     0,   202,   208,     0,
       0,   211,   119,   132,     0,     0,   136,     0,     0,     0,
       0,    26,    29,    37,     0,    38,    45,    40,     0,     0,
       0,     0,     0,     0,     0,   196,     0,     0,   205,     0,
     214,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,    87,     0,     0,     0,   191,     0,     0,     0,   200,
       0,     0,   209,     0,     0,     0,     0,     0,    21,    24,
       0,     0,     0,    81,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   195,     0,     0,   219,   204,
       0,   213,     0,     0,     0,     0,     0,    41,    17,    82,
      84,     0,    85,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   197,   218,   206,   215,     0,     0,
       0,     0,    86,    88,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,     0,   137,     0,    19,     0,     0,
       0,     0,     0,     0,     0,    20
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,    16,    17,    18,    19,     4,    69,    70,
      71,   447,  1073,  1079,   645,   816,  1242,  1422,   646,  1380,
    1461,   647,  1424,   648,   649,   820,   143,   253,    72,   577,
     348,   563,   564,   349,    76,    77,    78,    79,    80,   350,
    1121,  1350,  1406,  1124,  1355,  1410,  1127,  1359,  1413,  1264,
    1265,    82,    83,   941,   351,   146,   368,   180,   248,   440,
    1034,   956,   957,   353,   502,   204,   713,   850,   147
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1250
static const short yypact[] =
{
    2410,    38,    75,   223,  2559, -1250, -1250,    89,   100,   125,
     137,   167,   207,    43,    55,   104, -1250, -1250, -1250, -1250,
    1785,   122,     3,   317,   155,   158,   172,   -32,   297,   194,
     221,   373,   300,   441,   448,   459,   513,   468,   553,   342,
     340,   -18,   -18,   371,   490,    14,   520,    17,   565,   582,
     108,   551,   609,   618,   438,   442,   -13,    21,    25, -1250,
     452, -1250,   644, -1250,   669,   673,   642,    15,    28, -1250,
   -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250,
   -1250, -1250, -1250, -1250,  2439, -1250, -1250, -1250, -1250, -1250,
     544,   544,   717, -1250,   294,    23, -1250, -1250, -1250, -1250,
     -64,    54,   146,   287,   325,   350,   398,   433,   445,   449,
     475,   481,   484,   485,   488,   489,   500,   504,   507,   510,
     514,   563,   575,   589,   593, -1250,   594, -1250, -1250, -1250,
   -1250, -1250, -1250, -1250,  1888,  1888,  1888, -1250, -1250,  1888,
     387,    39,   792,  1888,   737,   648, -1250,   793,   795, -1250,
    1888, -1250,  1888,  1888,  1888,   630,  1888,   652,  1888,  1888,
     948,  1888,   649,   657,   658,   948,   654,   655,   663,   664,
     665,   666,   667,   813,   -18,   -18,   -18,  1888,  1888,   -83,
   -1250,   -77,   -18,   661,   662,   668,   671, -1250,   948,    34,
   -1250, -1250, -1250,   948,   948,   675,   676,   838,  1888,  1888,
     -49,  1888,   677,  1888,   672,   754,  1888,  1888, -1250,   848,
   -1250,   682, -1250, -1250,   851, -1250,   852,   685,   686,   687,
     688,   689,   696,   708,   709,   710,   711,   712,   721,   750,
     751,   752,   753,   757,   761,   762,   763,   765,   766,   767,
     768,   769,   770,   771,   773,   774,   775,   886,   748,   755,
     776,  1888,   946, -1250,   -18, -1250,  1888,  1888,  1888,  1888,
    1888,  1888,  1888,  1888,  1888,  1888,  1888,  1888,  1888,  1888,
    1888,  1888,  1888,  1888,  1888,  1888,  1888,  1888,  1888,  1888,
    1888,  1888,  1888,  1888,  1888,  1888,  1888,  1888,  1888,  1888,
    1888,  1888,  1888,  1888,  1888,  1888,  1888,  1888,   549,   130,
     130,   130,   950,   391,   780,   780,   780,  4829,   974,  1820,
    4199,   281,   807,   979,   811,   714, -1250, -1250,  1888,  1888,
    1888,  1888,  1888,  1888,  1888,  1888,  1888,  1888,  1888,  1888,
    1888,  1888,  1888, -1250,  -106,  3167,  4852,  4875,  4898,  1888,
    4921,  1888,  4944,  4967,   430,   809,  1500,  1820, -1250, -1250,
   -1250,   739,   981, -1250,  4990,  1888,  1888,  1888,   984,  1888,
    1888,  1888,  1888,  1888,  1888,  1888,   818,   -63, -1250, -1250,
    3191,  3215,   -18,   -18,   529,   529,   151,  1888,  1888,  1888,
    1888,  2199,   349,   990, -1250,  1888,  2220,   991,   994,  1888,
    1888, -1250,  5013,  5036,   916,  1888,  5059,   915,  3239, -1250,
     823,  1945,  5082, -1250,  1888,  2265, -1250,  2286, -1250,  1000,
    1001,  1012,  1015,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
    1027,  1028,  1029,  1030,  1031,  1032,  1036,  1039,  1042,  1043,
    1049,  1052,   917,  1053,  1055,  1056,  1059,  1062,  1061, -1250,
     191,  1067,  1068,  1071,  4220,   -50,   -10,     6,  5105,  4241,
    5128,  4262,  5151,  4283,  5174,  4304,  5197,  4325,  5220,  4346,
    5243,  4367,  5266,  4388,  5289,  4409,  5312,  4430,  5335,  4451,
    3263,  3287,  5358,  4472,  5381,  4493,  5404,  4514,  5427,  4535,
    5450,  4556,  5473,  4577,  3311,  3335,  3359,  3383,  3407,  3431,
     106,   203,   887,   898,   907,   914,  1888, -1250,   948,  2060,
     739, -1250,   268,    40,   130,  1888,  1089,  1093,    24,   921,
   -1250,  1972,  1198,   569,   592,   592,   414,   414,   414,   414,
     375,   375,   780,   780,   780,   780,  1094,  1820,  1888,  1095,
    1096,  1097,  5496,  1101,  5519,  1102,  1103,  1240,  1888,   439,
    1820,   293,  1888,  1888,  1106,  2623,  5542,  5565,  1888,  2649,
    2675,  5588,  5611,  5634,  5657,  5680,   923,   -18,  1888,  1888,
   -1250, -1250, -1250,   932,  2620, -1250,   933,  1888,  3455,  3479,
    3503,  4598,  -121,   -37,   -33,   116, -1250, -1250, -1250,  1888,
   -1250,  4619, -1250,   935,   937,  4640,  4661,  1113,  1116,   951,
    5703,  1117,   952,  1888,  2345,  1888,  1888, -1250,  5726, -1250,
   -1250,   955,   956,   957,   958,   959,   960,   961,   963,   964,
     968,   969,   978,   980,   986,   998,   999,  1002,  1005,  1007,
    1009,  1013,  1014,  1017,  1018,  1026,  1033,  1034,  1035,  1038,
    1041, -1250,  1121,   953, -1250,  1046,    36, -1250, -1250, -1250,
     985,   987,  1011, -1250,  1125, -1250, -1250, -1250, -1250, -1250,
   -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250,
   -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250,
   -1250, -1250,  1888,  1888, -1250, -1250, -1250, -1250, -1250, -1250,
   -1250, -1250, -1250, -1250, -1250, -1250,  1888,  1888,  1888,  1888,
    1888,  1888,  1888,  1176, -1250,  1820,   130, -1250, -1250,  1888,
    4682,  1175,  1820,  1045,    62,  1888,  1189,  1193,   756, -1250,
    1194,  1040,    21,  1196, -1250,  1888, -1250,   248,  3527,   -18,
     948,   948,  1200,   948,  1201,   948,   948, -1250,  1820,  2701,
    1370,   509, -1250,  2022,   926,  1047,  1202,  1203,  1204,   539,
    1212,  1216,  1220,  1222,  1223,  1224,  1226,  1230,   153,  3551,
    3575, -1250, -1250,  2727,   -18,   -18,   -18,  1199,  1820,  1820,
    1820,  1820,  1010,  1234,  1888,  1888,  1235,  1236,   948,   948,
    1888,  1229,   948,  1241,  3599, -1250,  2039,   616,  1266,  1244,
    1888,  1888,   -18,  1245,  1271,  1111,  1274,  1275,   948,   948,
    1276,   -18,  1277,  1278,   948,   948,  1280,  1281,  1282,  1283,
    1284,   948,   533,   948,  1285,  1286,  1287,  1291,  1292, -1250,
    1290,   544,  1293, -1250,  1294,    12,  1115,  1888,  1888,   948,
    1109, -1250,  5749,  4703,  5772,  4724,  5795,  4745,  5818,  4766,
    4787,  1123,   260,  1126,  5841,   115, -1250,   739, -1250,    70,
     306,  1127,  1296,  1269, -1250, -1250, -1250,    21,  1888, -1250,
     527, -1250,  2359,  1298,  1888,    11,    42,    50,   948,  1300,
     948,  1301,  1302,   531, -1250, -1250,  1820, -1250,  1888, -1250,
    1888,   948,   948,   948, -1250,   330,   948,   948,   948,   948,
     948,   948,   948,   537,  1888,  1888,  1888,  1129,   -85,   -71,
     -56, -1250,   534,   535,   566,   584, -1250, -1250,  3623,  3647,
   -1250, -1250,  1305,  1306,  5864,   144,  1227, -1250,  1888,  1888,
    1888, -1250,  1132,  1135,  3671,  3695,  -118,  1137,  1143,  1139,
    1145,  1141,  1147,  1148,  1149,   296,  1150,  1152,  1156,  1153,
    1157,  1159,  1161,  1166,  1167,  1173, -1250, -1250, -1250, -1250,
   -1250,  1169,  1170,  1172,  1174,  1186,  1192,  1225, -1250,  1228,
     -50, -1250,  1317,  1888,  3719,  3743,   604, -1250,  1888, -1250,
   -1250, -1250, -1250, -1250, -1250, -1250, -1250,  1154, -1250, -1250,
   -1250, -1250,   948,   130,  1888,  1319,  1332,    24, -1250,  1363,
    4808,    21, -1250, -1250,  3767, -1250, -1250,   -18, -1250,   -18,
    1372, -1250,  1401, -1250, -1250,  1233,   605,  2359,  3791,  1405,
    1406,  1409,  1888,  1888,   715,  1412,  1414,  1419,  1431,  1432,
    1433, -1250,  1992,  2753,  5887,  2524,   529,   -18,  1434,   -18,
    1435,   -18,  1437,  1438,  1439,  1440,  1441,  1888,  1888, -1250,
   -1250,  1369,   948,   948,  1364,   948,  2563,   474,  5910,  1888,
    1447,  1888,   948,  1446,  1450,  1448,  1295,  1449,   533,  1451,
    1453,  1888,  1452,  1456,  1455,  1457,  1459,   533,  1888,  1888,
    1888,   948,  1460,  1462,   533,  1888,  1464,  1465,  1463,  1888,
     544, -1250, -1250,   261,  2359,  1888,  1888,   948,  1289,   608,
    2359,  1467,  1470,  1471,  1407, -1250,  1472,  1474, -1250,  1303,
   -1250,  1888,    52,    61, -1250, -1250, -1250,  1307,  1888, -1250,
   -1250, -1250,  1529,  1569,  1476, -1250, -1250, -1250, -1250, -1250,
   -1250, -1250,  1705,  1477,  1297, -1250,  1888, -1250,  1304,   199,
   -1250,  1309,   257, -1250,  1310,   320, -1250,  1311, -1250, -1250,
   -1250, -1250,  3815,  3839,   144,   271,   612,  1313,  1403,  1888,
   -1250,  1888, -1250, -1250,  3863,  1320,  3887,  1308, -1250,  1316,
   -1250,  1318, -1250,  1322, -1250,  1321,  5933, -1250,  1325, -1250,
   -1250,  1324,  1327,  5956,  3911,  5979,  1326, -1250,  1361,  1362,
    3935,  1358,  1365, -1250,  3959,  1366, -1250,  1888,  3983,  4007,
   -1250,   948,  1888,  1479,  1367, -1250, -1250, -1250,    21, -1250,
    1411,  4031, -1250, -1250, -1250,  4055, -1250, -1250, -1250, -1250,
   -1250,   529,  2593, -1250,  1612,   396,  1612,   396,  1612,   396,
    1888,  1888,  1420, -1250, -1250,   948,  1888,  2779,  2805,   948,
    1535,   144,   533,  1540,  1888,  1539,   533,  1542,  1547,  1546,
    1548,  1550,  1888,  1552,   948,  1557,  1570,  1888,  1574,  1572,
    1888,  1576,  1398,  2359,  1888,  1888,   613,  2359, -1250, -1250,
    1577, -1250,  1888,  1579,  1371,  1888, -1250,  1612,  1612,  1888,
    2831,   334,  1580,  1404,   -42, -1250,  2857,   339,   -14,  2883,
     366,    45,  2909,  2935,  1410,  1402,  1812, -1250, -1250,  1408,
   -1250,  1413,  1415,  1416,  4079, -1250,  1417, -1250,  1422, -1250,
   -1250, -1250,  6002, -1250,  1418, -1250, -1250,  6025,  1424, -1250,
    6048,  1426,  1888,  6071,  4103,  1581, -1250,  4127,  1427, -1250,
    2961,  3143,  1582,  1888, -1250,   948,  1588, -1250,  1602,  1888,
    1604,  1605,  1888,  1606,  1607,  1608,   948,   948, -1250,  1611,
     533,   533,   533,   533,  1613,  1614,  1639,   533,  1640,  1641,
    1642,  1644,   636, -1250,  1888, -1250,  1888,  1645, -1250, -1250,
    1473,  2987,  1475, -1250, -1250,  1478,  3013, -1250, -1250,  1480,
    3039, -1250, -1250, -1250,  1482,  1436, -1250,  1486,  1487,  1481,
    1483, -1250, -1250, -1250,  1488, -1250, -1250, -1250,  1490,  1646,
    1491,  6094,  3065,  1493,   396,  1647,   948,   396,  1651,   396,
    1665,   948,  1567,   533,   533,  1669,  1670,   533,  1672, -1250,
     130, -1250,  1674,  1673,   109, -1250,  1504,   640,   112, -1250,
    1516,   299, -1250,  1517,  1518,  1520,  1519,  1524, -1250, -1250,
    1530,  1531,   643, -1250,  1526, -1250,  1527,  1702,   396,   948,
    1704,  1707,   396,  1712,   396,  1635,  1888,   533,   948,  1714,
    1715,   130,  1719,   130,  1731, -1250,   312,  1556, -1250, -1250,
     313, -1250,   314,  1558,  4151,  1560,  1561, -1250, -1250, -1250,
   -1250,   647, -1250, -1250,  1737,  1738,  1740,  1741,  1888,  1888,
     533,   948,   130,  1742, -1250, -1250, -1250, -1250,  4175,  3091,
    1571,  1573, -1250, -1250,  1888,  1743,   948,   533,  3117, -1250,
    1575,  1583,  1744,   948,  1746, -1250,  1584, -1250,   948,  1585,
     948,  1586,   533,  1587,  1748, -1250
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250,
   -1250,  1118, -1250,   455, -1250, -1250, -1250, -1250, -1250, -1250,
   -1250, -1250, -1250, -1250, -1250, -1250,  -303,   -16, -1250,  1755,
      -1,  -368,  -176,     2, -1250, -1250, -1250, -1250, -1250,  1757,
   -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1104,
   -1249, -1250, -1250,  -888,   -20, -1250,   351, -1250,   -86, -1250,
   -1092, -1009,   274,  -248,  -334,  -700,   786, -1250,   -66
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -49
static const short yytable[] =
{
     145,   214,   216,    74,   144,   249,    75,   566,   505,   149,
     639,   381,   849,   541,   386,  1317,   639,   985,   186,  1317,
     212,   189,  1317,  1135,  1136,   202,  1262,   254,   711,   205,
     155,  1263,   200,   212,   157,   155,   394,   405,   383,   407,
     384,   212,  1212,   311,     5,   372,   373,    96,   986,   121,
     122,   123,   124,   152,  1262,   125,   988,  1043,  1192,  1263,
     758,   501,   121,   122,   123,   124,   840,  1193,   125,   526,
     121,   122,   123,   124,   527,     6,   125,    96,   372,   373,
     372,   373,   640,   641,   642,   643,   372,   373,   640,   641,
     642,   643,   372,   373,   987,  1017,    84,  1018,   374,   501,
     372,   373,   989,  1268,   375,  1271,    85,   372,   373,  1019,
     256,  1020,   257,  1262,   304,   305,   306,   557,  1263,   307,
     310,   137,   138,   315,  1021,   395,  1022,   312,   313,  1281,
     335,    86,   336,   337,   338,   212,   340,   156,   342,   343,
    1316,   354,   156,    87,   759,   175,   176,   979,   760,   193,
     841,   842,   194,   372,   373,  1317,   177,   370,   371,  1317,
    1153,   201,  1317,   178,   121,   122,   123,   124,  1320,  1162,
     125,   638,  1246,    88,   372,   373,  1169,  1262,   392,   393,
    1262,   396,  1263,   398,   150,  1263,   401,   402,   644,   130,
     131,   132,   133,   717,   952,   187,   213,  1317,   190,   206,
     705,  1317,   203,  1317,   255,   712,   731,   137,   138,   215,
     385,   137,   138,    89,   812,   372,   373,    90,   704,   130,
     131,   132,   133,   594,   372,   373,     7,  1323,   258,    91,
     259,   444,   491,   492,   493,   494,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,    92,   501,
    1404,  1090,   692,  1408,   693,  1411,   137,   138,   504,   500,
     159,  1427,   501,   812,  1431,   506,   148,   761,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   973,   372,   373,   372,   373,  1032,   532,
     260,   534,   261,   151,  1446,  1033,   305,   500,  1450,   152,
    1452,   567,   153,   884,  1282,   545,   546,   547,  1286,   549,
     550,   551,   552,   553,   554,   555,   154,     8,     9,    10,
      11,    12,    13,    14,    15,   578,   579,   568,   569,   570,
     571,   832,   372,   373,   157,   581,   631,  1262,   158,   585,
     586,   632,  1263,   562,   562,   590,   565,   565,   694,  1204,
    1262,  1262,  1262,   695,   598,  1263,  1263,  1263,  1002,  1003,
      93,   303,   179,   181,   863,   159,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     372,   373,   160,   853,   892,   893,   894,   895,   702,   637,
     130,   131,   132,   133,   352,   969,  1176,  1206,   707,   358,
     702,  1177,  1367,  1368,  1369,  1370,  1213,   501,   702,  1374,
     703,  1077,   137,   138,   838,   130,   131,   132,   133,   372,
     373,   262,   382,   263,  1262,   137,   138,   387,   388,  1263,
     251,  1052,   252,   702,   161,   732,   700,   137,   138,   305,
     501,  1433,  1141,   372,   373,   708,   162,   706,  1250,   126,
     127,   128,   129,   163,  1464,  1466,  1467,   372,   373,   264,
    1208,   265,   372,   373,   164,  1416,  1417,   500,   718,  1420,
     501,   501,   501,   501,  1313,   168,   173,   700,   729,  1319,
     500,   174,   733,   734,   266,   367,   267,   369,   739,   372,
     373,   183,   996,   376,   184,   185,   972,   974,   749,   750,
     329,   330,   331,  1011,  1012,   874,  1322,   753,   332,  1455,
     134,   135,   182,   490,   212,   195,   136,   165,   166,   762,
     167,   139,   137,   138,   308,   188,   142,   496,   309,   252,
     814,   191,   268,   774,   269,   776,   777,   327,   328,   329,
     330,   331,  1480,   121,   122,   123,   124,   332,   192,   125,
      40,    41,    42,    43,   169,    45,   875,   170,   171,  1491,
     172,   137,   138,    51,    52,   446,   537,   270,   252,   271,
     137,   138,   198,   196,  1503,   730,   199,   252,   501,   272,
     813,   273,   197,   274,   910,   275,   207,   318,   319,   320,
     833,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   936,   937,   938,   939,   940,   332,  1118,   276,
     208,   277,   822,   823,   317,   278,  1142,   279,   280,   282,
     281,   283,   284,   286,   285,   287,   824,   825,   826,   827,
     828,   829,   830,   209,   288,   500,   289,   210,   290,   834,
     291,   292,   837,   293,   294,   843,   295,   211,   296,   702,
     297,   867,   318,   319,   320,   852,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   981,   500,   982,
     700,   702,   332,   995,   702,   702,  1023,  1024,   247,  1104,
     510,  1105,   250,   560,   561,   949,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   298,   500,   500,
     500,   500,   332,   316,   898,   899,   702,   542,  1025,   299,
     904,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     914,   915,   846,   300,   702,   332,  1026,   301,   302,   318,
     319,   320,   701,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,  1077,   702,  1078,  1097,  1182,   332,
    1183,   911,  1077,  1077,  1214,  1305,   314,   954,   955,   333,
     334,   318,   319,   320,   339,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,  1182,   366,  1379,   813,
    1429,   332,  1430,  1441,   975,  1442,   341,  1472,   980,  1473,
     355,   356,   357,  1254,   984,   359,   360,   361,   362,   363,
     364,   365,   377,   378,   391,   400,   500,   380,   997,   379,
     998,   389,   390,   399,   403,   397,   404,   406,   408,   409,
     410,   411,   412,   413,  1013,  1014,  1015,   318,   319,   320,
     414,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   415,   416,   417,   418,   419,   332,  1036,  1037,
    1038,   439,   318,   319,   320,   420,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,  1083,   748,   318,
     319,   320,   332,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   421,   422,   423,   424,   441,   332,
     442,   425,   869,  1074,  1071,   426,   427,   428,  1080,   429,
     430,   431,   432,   433,   434,   435,  1113,   436,   437,   438,
     445,    93,   344,   332,  1084,   495,   443,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   498,  1102,  1103,  1175,   507,   508,   509,   543,   345,
     538,   548,  1112,   556,   856,   857,   580,   859,   583,   861,
     862,   584,   589,   592,   595,   601,   602,  1132,  1133,    40,
      41,    42,    43,    44,    45,   562,   896,   603,   565,  1144,
     604,  1146,    51,    52,   605,   606,   607,   608,   609,   610,
     611,  1156,   612,   613,   614,   615,   616,   617,  1163,  1164,
    1165,   618,   902,   903,   619,  1170,   906,   620,   621,  1174,
     126,   127,   128,   129,   622,  1178,  1179,   623,   625,   624,
     626,   627,   922,   923,   628,   629,   630,   696,   928,   929,
     855,  1191,   633,   697,   634,   935,   635,   942,  1195,   318,
     319,   320,   698,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   699,   709,  1202,   710,   714,   332,
     716,   747,   719,   720,   721,   888,   889,   890,   723,   725,
     726,   134,   346,   735,   751,   752,   764,   136,   765,  1217,
     768,  1218,   139,   769,   772,   770,   809,   142,   810,   347,
     773,   821,   990,   916,   992,   779,   780,   781,   782,   783,
     784,   785,   925,   786,   787,   999,  1000,  1001,   788,   789,
    1004,  1005,  1006,  1007,  1008,  1009,  1010,  1243,   790,   817,
     791,   818,  1247,   318,   319,   320,   792,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   793,   794,
     831,   836,   795,   332,  1260,   796,  1266,   797,  1269,   798,
    1272,  1273,   819,   799,   800,   844,  1276,   801,   802,   845,
     562,   847,   851,   565,  1284,   891,   803,   858,   860,   871,
     872,   873,  1292,   804,   805,   806,   848,  1297,   807,   876,
    1300,   808,   839,   877,  1303,  1304,   811,   878,   870,   879,
     880,   881,  1307,   882,   883,  1310,   905,   304,   305,  1311,
     897,   900,   901,    93,   303,   907,  1082,   913,   917,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   912,   918,   978,   919,   920,   921,   924,
     926,   927,  1080,   930,   931,   932,   933,   934,   943,   953,
     958,   944,   945,  1351,   946,   947,   948,   950,   968,  1356,
     951,   970,  1360,   977,   983,   976,   991,   993,   994,  1138,
    1016,  1029,  1030,  1039,  1035,  1040,  1147,  1044,  1045,  1046,
    1047,  1048,  1049,  1072,  1381,  1085,  1382,  1054,  1050,  1051,
    1053,  1055,  1081,  1056,  1423,  1166,  1086,  1057,  1092,  1058,
    1093,  1059,   126,   127,   128,   129,  1060,  1061,  1062,  1063,
    1064,  1180,  1065,   320,  1066,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,  1067,  1068,  1119,  1088,
    1122,   332,  1125,    93,   303,  1459,  1134,  1462,  1094,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   134,   135,  1069,  1482,  1095,  1070,   136,
    1096,  1099,  1100,  1187,   139,  1101,  1454,   727,  1106,   142,
    1107,   728,   318,   319,   320,  1108,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,  1109,  1110,  1111,
    1120,  1123,   332,  1126,  1128,  1129,  1130,  1131,  1478,  1479,
    1145,  1137,  1148,  1149,  1150,  1152,  1155,  1154,  1157,  1158,
    1151,  1159,  1161,  1160,  1488,  1168,  1167,  1171,  1172,  1173,
    1181,  1184,   126,   127,   128,   129,  1185,  1186,  1201,  1188,
    1189,  1190,  1198,  1200,  1194,  1248,  1203,  1216,  1222,  1275,
    1205,  1207,  1209,  1279,  1215,  1220,  1223,  1225,  1224,  1229,
    1251,  1226,  1230,    93,   539,  1228,  1234,  1274,  1294,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   134,   135,  1196,  1235,  1236,  1238,   136,
    1239,  1280,  1249,  1283,   139,  1285,  1241,   865,  1287,   142,
    1288,   866,  1289,  1309,  1290,  1261,  1291,  1267,  1293,  1270,
     318,   319,   320,  1295,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,  1197,  1296,  1298,  1299,  1302,
     332,  1301,  1327,  1306,  1308,  1315,  1314,  1345,  1349,  1352,
    1329,  1326,  1334,  1330,  1353,  1331,  1332,  1335,  1337,  1339,
    1364,  1365,   126,   127,   128,   129,  1341,  1347,  1354,   369,
    1357,  1358,  1361,  1362,  1363,    93,   303,  1366,  1392,  1371,
    1372,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,  1373,  1375,  1376,  1377,  1378,
    1383,  1415,  1399,  1405,  1384,  1386,  1395,  1409,  1396,  1387,
    1407,  1389,  1391,   134,   135,  1414,  1393,  1394,  1397,   136,
    1398,  1412,  1400,  1403,   139,  1418,  1419,  1421,  1426,   142,
    1425,   540,   318,   319,   320,  1428,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,  1432,  1434,  1437,
    1435,  1436,   332,  1447,  1438,  1439,  1440,  1443,  1445,  1444,
    1448,  1199,  1456,  1449,   126,   127,   128,   129,  1451,  1453,
    1457,  1458,   318,   319,   320,  1460,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,  1463,  1465,  1468,
    1470,  1471,   332,  1474,  1475,  1481,  1476,  1477,  1483,  1489,
    1495,  1486,  1497,  1487,  1505,  1493,   815,  1342,  1494,    73,
    1490,    81,  1504,  1087,  1498,  1500,  1502,  1496,     0,     0,
       0,     0,  1499,     0,  1501,  1257,  1258,     0,     0,     0,
       0,   136,     0,     0,     0,     0,  1259,     0,    93,    94,
      95,   142,    96,   178,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,  1328,   121,
     122,   123,   124,    93,   344,   125,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,   318,   319,
     320,   345,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,    40,    41,    42,    43,    44,    45,   126,   127,   128,
     129,    93,   303,     0,    51,    52,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,     0,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   131,   132,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
       0,     0,     0,   596,   136,     0,   137,   138,     0,   139,
       0,   140,     0,   141,   142,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     715,     0,     0,   134,   499,   332,     0,     0,     0,   136,
     126,   127,   128,   129,   139,    93,   303,   212,     0,   142,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,     0,   121,   122,   123,   124,
     868,     0,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   909,     0,     0,
       0,   134,   135,     0,     0,     0,     0,   136,     0,     0,
       0,     0,   139,    93,   539,     0,     0,   142,     0,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,   126,   127,   128,   129,   318,   319,
     320,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,     0,     0,     0,     0,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   135,     0,     0,     0,
       0,   136,   126,   127,   128,   129,   139,     0,     0,     0,
       0,   142,     0,     0,     0,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,   318,   319,   320,   332,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,     0,     0,     0,     0,   136,
       0,     0,     0,     0,   139,     0,     0,     0,     0,   142,
     572,    25,    26,   573,   574,    29,   575,    31,     0,    32,
       0,    34,    35,     0,    37,    38,     0,     0,     0,     0,
       0,   572,    25,    26,   573,   574,    29,   575,    31,     0,
      32,    50,    34,    35,     0,    37,    38,     0,     0,     0,
      54,    55,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,    66,     0,
       0,    54,    55,    56,     0,     0,   572,    25,    26,   573,
     574,    29,   575,    31,     0,    32,     0,    34,    35,    66,
      37,    38,     0,     0,     0,     0,     0,   572,    25,    26,
     573,   574,    29,   575,    31,     0,    32,    50,    34,    35,
       0,    37,    38,     0,     0,     0,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,    66,     0,     0,    54,    55,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   576,     0,     0,     0,    66,   572,    25,    26,   573,
     574,    29,   575,    31,     0,    32,     0,    34,    35,     0,
      37,    38,   582,     0,     0,     0,     0,     0,     0,     0,
      -5,     1,     0,    -5,   -48,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -48,    66,     0,     0,   599,   -48,   -48,
       0,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,     0,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,     0,   600,     0,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,
     -48,   -48,   -48,   217,   -48,   -48,     0,     0,     0,     0,
     -48,   -48,   -48,   -48,     0,     0,     0,     0,   -48,     0,
     -48,     0,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   318,   319,   320,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   775,     0,     0,
       0,     0,   332,     0,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,     0,     0,     0,   218,   219,   220,     0,     0,
       0,     0,     0,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,    20,     0,     0,     0,     0,     0,     0,
       0,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,   242,   243,   244,   245,   246,     0,     0,
       0,     0,    21,     0,     0,     0,     0,    22,    23,     0,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,     0,     0,     0,    39,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
      49,    50,     0,    51,    52,     0,     0,     0,     0,    53,
      54,    55,    56,     0,     0,     0,     0,    57,     0,    58,
       0,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   572,    25,    26,   573,   574,    29,   575,    31,     0,
      32,     0,    34,    35,     0,    37,    38,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,    50,     0,     0,     0,     0,   332,     0,     0,
       0,    54,    55,    56,  1116,     0,  1117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   318,   319,   320,    66,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,     0,     0,
       0,     0,     0,  1139,     0,  1140,   318,   319,   320,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,     0,     0,
       0,     0,     0,  1255,     0,  1256,   318,   319,   320,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,     0,     0,
       0,     0,   318,   319,   320,   736,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,     0,     0,     0,     0,   318,   319,
     320,   740,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,     0,     0,     0,   318,   319,   320,   741,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,     0,     0,     0,     0,
     318,   319,   320,   864,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,     0,     0,     0,     0,   318,   319,   320,   887,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,     0,     0,
       0,     0,   318,   319,   320,  1114,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,     0,     0,     0,     0,   318,   319,
     320,  1277,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,     0,     0,     0,   318,   319,   320,  1278,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,     0,     0,     0,     0,
     318,   319,   320,  1312,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,     0,     0,     0,     0,   318,   319,   320,  1318,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,     0,     0,
       0,     0,   318,   319,   320,  1321,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,     0,     0,     0,     0,   318,   319,
     320,  1324,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,     0,     0,     0,   318,   319,   320,  1325,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,     0,     0,     0,     0,
     318,   319,   320,  1348,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,     0,     0,     0,     0,   318,   319,   320,  1385,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,     0,     0,
       0,     0,   318,   319,   320,  1388,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,     0,     0,     0,     0,   318,   319,
     320,  1390,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,     0,     0,     0,   318,   319,   320,  1402,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,     0,     0,     0,     0,
     318,   319,   320,  1485,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,     0,     0,     0,     0,   318,   319,   320,  1492,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,   497,     0,
     318,   319,   320,   558,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,     0,     0,   318,   319,   320,   528,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,     0,     0,   318,   319,
     320,   558,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,     0,   318,   319,   320,   559,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,     0,     0,   318,   319,   320,   593,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,     0,     0,
     318,   319,   320,   672,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,     0,     0,   318,   319,   320,   673,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,     0,     0,   318,   319,
     320,   686,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,     0,   318,   319,   320,   687,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,     0,     0,   318,   319,   320,   688,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,     0,     0,
     318,   319,   320,   689,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,     0,     0,   318,   319,   320,   690,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,     0,     0,   318,   319,
     320,   691,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,     0,   318,   319,   320,   754,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,     0,     0,   318,   319,   320,   755,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,     0,     0,
     318,   319,   320,   756,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,     0,     0,   318,   319,   320,   854,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,     0,     0,   318,   319,
     320,   885,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,     0,   318,   319,   320,   886,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,     0,     0,   318,   319,   320,   908,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,     0,     0,
     318,   319,   320,  1027,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,     0,     0,   318,   319,   320,  1028,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,     0,     0,   318,   319,
     320,  1041,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,     0,   318,   319,   320,  1042,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,     0,     0,   318,   319,   320,  1075,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,     0,     0,
     318,   319,   320,  1076,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,     0,     0,   318,   319,   320,  1091,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,     0,     0,   318,   319,
     320,  1098,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,     0,   318,   319,   320,  1210,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,     0,     0,   318,   319,   320,  1211,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,     0,     0,
     318,   319,   320,  1219,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,     0,     0,   318,   319,   320,  1221,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,     0,     0,   318,   319,
     320,  1232,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,     0,   318,   319,   320,  1237,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,     0,     0,   318,   319,   320,  1240,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,     0,     0,
     318,   319,   320,  1244,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,     0,     0,   318,   319,   320,  1245,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,     0,     0,   318,   319,
     320,  1252,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,     0,   318,   319,   320,  1253,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,     0,     0,   318,   319,   320,  1333,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,     0,     0,
     318,   319,   320,  1344,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,     0,     0,   318,   319,   320,  1346,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,     0,     0,   318,   319,
     320,  1469,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
       0,     0,   318,   319,   320,  1484,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,   318,   319,   320,   503,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,   318,   319,   320,   636,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,   318,   319,   320,   651,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,   318,   319,   320,   653,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,   318,   319,   320,
     655,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,   318,   319,
     320,   657,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,   318,
     319,   320,   659,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
     318,   319,   320,   661,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,   318,   319,   320,   663,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,   318,   319,   320,   665,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,   318,   319,   320,   667,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,   318,   319,   320,   669,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,   318,   319,   320,   671,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,   318,   319,   320,   675,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,   318,   319,   320,
     677,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,   318,   319,
     320,   679,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,   318,
     319,   320,   681,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
     318,   319,   320,   683,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,   318,   319,   320,   685,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,   318,   319,   320,   757,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,   318,   319,   320,   763,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,   318,   319,   320,   766,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,   318,   319,   320,   767,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,   318,   319,   320,   835,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,   318,   319,   320,
     960,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,   318,   319,
     320,   962,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,   318,
     319,   320,   964,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
     318,   319,   320,   966,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,   318,   319,   320,   967,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,   318,   319,   320,  1089,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,   497,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,   529,   318,   319,
     320,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
     530,   318,   319,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,   531,   318,   319,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,   533,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,   535,
     318,   319,   320,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,   536,   318,   319,   320,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,   544,   318,   319,   320,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,   587,   318,
     319,   320,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,   588,   318,   319,   320,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,   591,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,   597,   318,   319,
     320,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
     650,   318,   319,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,   652,   318,   319,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,   654,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,   656,
     318,   319,   320,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,   658,   318,   319,   320,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,   660,   318,   319,   320,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,   662,   318,
     319,   320,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,   664,   318,   319,   320,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,   666,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,   668,   318,   319,
     320,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
     670,   318,   319,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,   674,   318,   319,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,   676,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,   678,
     318,   319,   320,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,   680,   318,   319,   320,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,   682,   318,   319,   320,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,   684,   318,
     319,   320,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,   722,   318,   319,   320,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,   724,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,   737,   318,   319,
     320,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
     738,   318,   319,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,   742,   318,   319,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,   743,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,   744,
     318,   319,   320,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,   745,   318,   319,   320,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,   746,   318,   319,   320,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,   771,   318,
     319,   320,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,   778,   318,   319,   320,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,   959,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,   961,   318,   319,
     320,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
     963,   318,   319,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,   965,   318,   319,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,   971,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,  1031,
     318,   319,   320,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,  1115,   318,   319,   320,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,  1143,   318,   319,   320,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,  1227,   318,
     319,   320,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,  1231,   318,   319,   320,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,  1233,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,  1336,   318,   319,
     320,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
    1338,   318,   319,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,  1340,   318,   319,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,  1343,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,  1401
};

static const short yycheck[] =
{
      20,    67,    68,     4,    20,    91,     4,   375,   311,     6,
       4,   187,   712,   347,   190,  1264,     4,     6,     4,  1268,
       5,     4,  1271,  1032,  1033,     4,    68,     4,     4,     4,
      67,    73,    45,     5,    67,    67,    85,   213,     4,   215,
       6,     5,  1134,     4,     6,   163,   164,     7,     6,    34,
      35,    36,    37,   174,    68,    40,     6,   175,     6,    73,
     181,   309,    34,    35,    36,    37,     4,     6,    40,   175,
      34,    35,    36,    37,   180,     0,    40,     7,   163,   164,
     163,   164,    76,    77,    78,    79,   163,   164,    76,    77,
      78,    79,   163,   164,    52,   180,     7,   182,   181,   347,
     163,   164,    52,  1207,   181,  1209,     6,   163,   164,   180,
     174,   182,   176,    68,   134,   135,   136,   180,    73,   139,
     140,   171,   172,   143,   180,   174,   182,    88,    89,  1221,
     150,     6,   152,   153,   154,     5,   156,   174,   158,   159,
     182,   161,   174,     6,   181,   163,   164,   847,   181,    41,
      88,    89,    44,   163,   164,  1404,   174,   177,   178,  1408,
    1048,   174,  1411,   181,    34,    35,    36,    37,   182,  1057,
      40,   181,  1181,     6,   163,   164,  1064,    68,   198,   199,
      68,   201,    73,   203,   181,    73,   206,   207,   182,   149,
     150,   151,   152,   527,   182,   181,   181,  1446,   181,   174,
     503,  1450,   181,  1452,   181,   181,   540,   171,   172,   181,
     176,   171,   172,     6,   178,   163,   164,   174,   178,   149,
     150,   151,   152,   399,   163,   164,     3,   182,   174,   174,
     176,   251,   298,   299,   300,   301,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   174,   527,
    1384,   981,   176,  1387,   178,  1389,   171,   172,     7,   309,
     174,   182,   540,   178,   182,   311,   174,   181,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,     7,   163,   164,   163,   164,   174,   339,
     174,   341,   176,     6,  1428,   181,   346,   347,  1432,   174,
    1434,   180,   174,   180,  1222,   355,   356,   357,  1226,   359,
     360,   361,   362,   363,   364,   365,   174,   124,   125,   126,
     127,   128,   129,   130,   131,     6,     7,   377,   378,   379,
     380,   695,   163,   164,    67,   385,   175,    68,   174,   389,
     390,   180,    73,   374,   375,   395,   374,   375,   175,   180,
      68,    68,    68,   180,   404,    73,    73,    73,    58,    59,
       3,     4,    41,    42,   728,   174,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
     163,   164,    49,   175,   758,   759,   760,   761,   180,   445,
     149,   150,   151,   152,   160,   175,   175,   180,   504,   165,
     180,   180,  1330,  1331,  1332,  1333,   175,   695,   180,  1337,
     182,   180,   171,   172,   702,   149,   150,   151,   152,   163,
     164,   174,   188,   176,    68,   171,   172,   193,   194,    73,
     176,   175,   178,   180,   174,   182,   496,   171,   172,   499,
     728,   182,     8,   163,   164,   505,    45,   503,  1188,   102,
     103,   104,   105,    45,   182,   182,   182,   163,   164,   174,
     180,   176,   163,   164,    45,  1393,  1394,   527,   528,  1397,
     758,   759,   760,   761,   180,    47,   174,   537,   538,   180,
     540,   181,   542,   543,   174,   174,   176,   176,   548,   163,
     164,    41,   866,   182,    44,    45,   839,   840,   558,   559,
     165,   166,   167,     6,     7,     6,   180,   567,   173,  1437,
     163,   164,   181,     4,     5,     4,   169,    44,    45,   579,
      47,   174,   171,   172,   177,    45,   179,   176,   181,   178,
     636,     6,   174,   593,   176,   595,   596,   163,   164,   165,
     166,   167,  1470,    34,    35,    36,    37,   173,     6,    40,
      61,    62,    63,    64,    41,    66,    57,    44,    45,  1487,
      47,   171,   172,    74,    75,   254,   176,   174,   178,   176,
     171,   172,   174,     4,  1502,   176,   174,   178,   866,   174,
     636,   176,     4,   174,     8,   176,   174,   153,   154,   155,
     696,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   109,   110,   111,   112,   113,   173,  1016,   174,
       6,   176,   672,   673,     6,   174,   182,   176,   174,   174,
     176,   176,   174,   174,   176,   176,   686,   687,   688,   689,
     690,   691,   692,     4,   174,   695,   176,     4,   174,   699,
     176,   174,   702,   176,   174,   705,   176,    45,   174,   180,
     176,   182,   153,   154,   155,   715,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   180,   728,   182,
     730,   180,   173,   182,   180,   180,   182,   182,   174,     4,
       6,     6,     5,   372,   373,   811,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   174,   758,   759,
     760,   761,   173,     6,   764,   765,   180,     8,   182,   174,
     770,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     780,   781,     6,   174,   180,   173,   182,   174,   174,   153,
     154,   155,   498,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   180,   180,   182,   182,   180,   173,
     182,   175,   180,   180,   182,   182,     4,   817,   818,     6,
       5,   153,   154,   155,   174,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   180,     4,   182,   835,
     180,   173,   182,   180,   840,   182,   174,   180,   848,   182,
     181,   174,   174,  1201,   854,   181,   181,   174,   174,   174,
     174,   174,   181,   181,     6,    91,   866,   176,   868,   181,
     870,   176,   176,   181,     6,   178,   174,     6,     6,   174,
     174,   174,   174,   174,   884,   885,   886,   153,   154,   155,
     174,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   174,   174,   174,   174,   174,   173,   908,   909,
     910,     5,   153,   154,   155,   174,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   973,   557,   153,
     154,   155,   173,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   174,   174,   174,   174,   180,   173,
     175,   174,     6,   953,   950,   174,   174,   174,   958,   174,
     174,   174,   174,   174,   174,   174,  1012,   174,   174,   174,
       4,     3,     4,   173,   974,     5,   180,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     7,  1002,  1003,  1070,   178,     7,   176,     7,    41,
     181,     7,  1012,   175,   720,   721,     6,   723,     7,   725,
     726,     7,    86,    88,   181,     5,     5,  1027,  1028,    61,
      62,    63,    64,    65,    66,  1016,     6,     5,  1016,  1039,
       5,  1041,    74,    75,     5,     5,     5,     5,     5,     5,
       5,  1051,     5,     5,     5,     5,     5,     5,  1058,  1059,
    1060,     5,   768,   769,     5,  1065,   772,     5,     5,  1069,
     102,   103,   104,   105,     5,  1075,  1076,     5,     5,   142,
       5,     5,   788,   789,     5,     3,     5,   180,   794,   795,
     719,  1091,     5,   175,     6,   801,     5,   803,  1098,   153,
     154,   155,   175,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   180,     6,  1116,     4,   177,   173,
       6,   178,     7,     7,     7,   754,   755,   756,     7,     7,
       7,   163,   164,     7,   182,   182,   181,   169,   181,  1139,
       7,  1141,   174,     7,     7,   174,     5,   179,   175,   181,
     178,     6,   858,   782,   860,   180,   180,   180,   180,   180,
     180,   180,   791,   180,   180,   871,   872,   873,   180,   180,
     876,   877,   878,   879,   880,   881,   882,  1177,   180,   174,
     180,   174,  1182,   153,   154,   155,   180,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   180,   180,
       4,     6,   180,   173,  1204,   180,  1206,   180,  1208,   180,
    1210,  1211,   181,   180,   180,     6,  1216,   180,   180,     6,
    1201,     7,     6,  1201,  1224,     6,   180,     7,     7,     7,
       7,     7,  1232,   180,   180,   180,   176,  1237,   180,     7,
    1240,   180,   177,     7,  1244,  1245,   180,     7,   181,     7,
       7,     7,  1252,     7,     4,  1255,     7,  1257,  1258,  1259,
       6,     6,     6,     3,     4,     4,   972,     3,     3,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,     7,     3,     6,   165,     3,     3,     3,
       3,     3,  1302,     3,     3,     3,     3,     3,     3,   174,
     181,     5,     5,  1313,     3,     3,     6,     4,   175,  1319,
       6,   175,  1322,     7,     6,   178,     6,     6,     6,  1035,
     181,     6,     6,   181,    87,   180,  1042,   180,   175,   180,
     175,   180,   175,     6,  1344,     6,  1346,   175,   180,   180,
     180,   175,   178,   180,  1400,  1061,     4,   180,   987,   180,
     989,   180,   102,   103,   104,   105,   180,   180,   175,   180,
     180,  1077,   180,   155,   180,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   180,   175,  1017,     6,
    1019,   173,  1021,     3,     4,  1441,     7,  1443,     6,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   163,   164,   180,  1472,     6,   180,   169,
     177,     6,     6,     6,   174,     6,  1436,   177,     6,   179,
       6,   181,   153,   154,   155,     6,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,     6,     6,     6,
       6,     6,   173,     6,     6,     6,     6,     6,  1468,  1469,
       3,    87,     6,     3,     6,     6,     3,     6,     6,     3,
     165,     6,     3,     6,  1484,     3,     6,     3,     3,     6,
     181,     4,   102,   103,   104,   105,     6,     6,   181,     7,
       6,   178,     6,     6,   177,     6,   182,    84,   180,  1215,
     181,   181,   181,  1219,   181,   175,   180,   175,   180,   175,
      89,   180,   175,     3,     4,   180,   180,    87,  1234,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   163,   164,     6,   175,   175,   180,   169,
     175,     6,   175,     3,   174,     6,   180,   177,     6,   179,
       3,   181,     6,   182,     6,  1204,     6,  1206,     6,  1208,
     153,   154,   155,     6,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,     6,     6,     3,     6,   181,
     173,     5,   180,     6,     5,   181,     6,     6,     6,  1315,
     182,   181,   175,   180,     6,   180,   180,   175,   180,   175,
    1326,  1327,   102,   103,   104,   105,   180,   180,     6,  1258,
       6,     6,     6,     6,     6,     3,     4,     6,   182,     6,
       6,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     6,     6,     6,     6,     5,
       5,    84,     6,     6,   181,   180,   175,     6,   175,   181,
    1386,   181,   180,   163,   164,  1391,   180,   180,   180,   169,
     180,     6,   181,   180,   174,     6,     6,     5,     5,   179,
       6,   181,   153,   154,   155,   181,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   181,   181,   180,
     182,   181,   173,  1429,   180,   175,   175,   181,     6,   182,
       6,     6,  1438,     6,   102,   103,   104,   105,     6,    84,
       6,     6,   153,   154,   155,     6,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,     6,   182,   181,
     180,   180,   173,     6,     6,  1471,     6,     6,     6,     6,
       6,   180,     6,   180,     6,   180,   638,  1302,   175,     4,
    1486,     4,   175,   977,   180,   180,   180,  1493,    -1,    -1,
      -1,    -1,  1498,    -1,  1500,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,   174,    -1,     3,     4,
       5,   179,     7,   181,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     6,    34,
      35,    36,    37,     3,     4,    40,    -1,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,   153,   154,
     155,    41,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    61,    62,    63,    64,    65,    66,   102,   103,   104,
     105,     3,     4,    -1,    74,    75,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,   102,   103,   104,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   164,
      -1,    -1,    -1,     8,   169,    -1,   171,   172,    -1,   174,
      -1,   176,    -1,   178,   179,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       8,    -1,    -1,   163,   164,   173,    -1,    -1,    -1,   169,
     102,   103,   104,   105,   174,     3,     4,     5,    -1,   179,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    34,    35,    36,    37,
       8,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,   174,     3,     4,    -1,    -1,   179,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,   102,   103,   104,   105,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   164,    -1,    -1,    -1,
      -1,   169,   102,   103,   104,   105,   174,    -1,    -1,    -1,
      -1,   179,    -1,    -1,    -1,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,   153,   154,   155,   173,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,   179,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      -1,    52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    72,    52,    53,    -1,    55,    56,    -1,    -1,    -1,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    81,    82,    83,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    -1,    52,    53,    99,
      55,    56,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    72,    52,    53,
      -1,    55,    56,    -1,    -1,    -1,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,    -1,    -1,    -1,    99,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    -1,    52,    53,    -1,
      55,    56,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,     3,     4,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    99,    -1,    -1,   182,    38,    39,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    -1,   182,    -1,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    44,    74,    75,    -1,    -1,    -1,    -1,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    88,    -1,
      90,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   182,    -1,    -1,
      -1,    -1,   173,    -1,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    -1,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    -1,    74,    75,    -1,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    88,    -1,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    -1,    52,    53,    -1,    55,    56,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    72,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    81,    82,    83,   180,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,    99,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,   180,    -1,   182,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,   180,    -1,   182,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,   153,   154,   155,   182,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,   153,   154,
     155,   182,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,   153,   154,   155,   182,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
     153,   154,   155,   182,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,   182,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,   153,   154,   155,   182,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,   153,   154,
     155,   182,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,   153,   154,   155,   182,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
     153,   154,   155,   182,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,   182,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,   153,   154,   155,   182,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,   153,   154,
     155,   182,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,   153,   154,   155,   182,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
     153,   154,   155,   182,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,   182,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,   153,   154,   155,   182,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,   153,   154,
     155,   182,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,   153,   154,   155,   182,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
     153,   154,   155,   182,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,   182,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,    -1,
     153,   154,   155,   180,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   153,   154,   155,   180,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,
     155,   180,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,   153,   154,   155,   180,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     153,   154,   155,   180,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   153,   154,   155,   180,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,
     155,   180,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,   153,   154,   155,   180,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     153,   154,   155,   180,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   153,   154,   155,   180,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,
     155,   180,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,   153,   154,   155,   180,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     153,   154,   155,   180,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   153,   154,   155,   180,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,
     155,   180,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,   153,   154,   155,   180,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     153,   154,   155,   180,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   153,   154,   155,   180,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,
     155,   180,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,   153,   154,   155,   180,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     153,   154,   155,   180,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   153,   154,   155,   180,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,
     155,   180,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,   153,   154,   155,   180,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     153,   154,   155,   180,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   153,   154,   155,   180,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,
     155,   180,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,   153,   154,   155,   180,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     153,   154,   155,   180,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   153,   154,   155,   180,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,
     155,   180,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,   153,   154,   155,   180,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     153,   154,   155,   180,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   153,   154,   155,   180,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,
     155,   180,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,   153,   154,   155,   180,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,   153,   154,   155,   177,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,   153,   154,   155,   177,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,   153,   154,   155,   177,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,   153,   154,   155,   177,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,   153,   154,   155,
     177,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,   153,   154,
     155,   177,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,   153,
     154,   155,   177,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
     153,   154,   155,   177,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,   153,   154,   155,   177,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,   153,   154,   155,   177,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,   153,   154,   155,   177,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,   153,   154,   155,   177,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,   153,   154,   155,   177,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,   153,   154,   155,   177,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,   153,   154,   155,
     177,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,   153,   154,
     155,   177,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,   153,
     154,   155,   177,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
     153,   154,   155,   177,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,   153,   154,   155,   177,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,   153,   154,   155,   177,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,   153,   154,   155,   177,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,   153,   154,   155,   177,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,   153,   154,   155,   177,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,   153,   154,   155,   177,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,   153,   154,   155,
     177,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,   153,   154,
     155,   177,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,   153,
     154,   155,   177,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
     153,   154,   155,   177,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,   153,   154,   155,   177,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,   153,   154,   155,   177,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,   175,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
     175,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,   175,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,   175,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,   175,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,   175,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,   175,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,   175,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
     175,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,   175,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,   175,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,   175,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,   175,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,   175,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,   175,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
     175,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,   175,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,   175,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,   175,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,   175,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,   175,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,   175,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
     175,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,   175,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,   175,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,   175,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,   175,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,   175,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,   175,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
     175,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,   175,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,   175,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,   175,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,   175,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,   175,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,    -1,   175,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,
     175,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,   175,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,    -1,   175,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     1,   184,   185,   190,     6,     0,     3,   124,   125,
     126,   127,   128,   129,   130,   131,   186,   187,   188,   189,
       4,    33,    38,    39,    41,    42,    43,    44,    45,    46,
      47,    48,    50,    51,    52,    53,    54,    55,    56,    60,
      61,    62,    63,    64,    65,    66,    68,    69,    70,    71,
      72,    74,    75,    80,    81,    82,    83,    88,    90,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   191,
     192,   193,   211,   212,   213,   216,   217,   218,   219,   220,
     221,   222,   234,   235,     7,     6,     6,     6,     6,     6,
     174,   174,   174,     3,     4,     5,     7,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    34,    35,    36,    37,    40,   102,   103,   104,   105,
     149,   150,   151,   152,   163,   164,   169,   171,   172,   174,
     176,   178,   179,   209,   210,   237,   238,   251,   174,     6,
     181,     6,   174,   174,   174,    67,   174,    67,   174,   174,
      49,   174,    45,    45,    45,    44,    45,    47,    47,    41,
      44,    45,    47,   174,   181,   163,   164,   174,   181,   239,
     240,   239,   181,    41,    44,    45,     4,   181,    45,     4,
     181,     6,     6,    41,    44,     4,     4,     4,   174,   174,
      45,   174,     4,   181,   248,     4,   174,   174,     6,     4,
       4,    45,     5,   181,   251,   181,   251,    44,   106,   107,
     108,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   143,   144,   145,   146,   147,   148,   174,   241,   241,
       5,   176,   178,   210,     4,   181,   174,   176,   174,   176,
     174,   176,   174,   176,   174,   176,   174,   176,   174,   176,
     174,   176,   174,   176,   174,   176,   174,   176,   174,   176,
     174,   176,   174,   176,   174,   176,   174,   176,   174,   176,
     174,   176,   174,   176,   174,   176,   174,   176,   174,   174,
     174,   174,   174,     4,   237,   237,   237,   237,   177,   181,
     237,     4,    88,    89,     4,   237,     6,     6,   153,   154,
     155,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   173,     6,     5,   237,   237,   237,   237,   174,
     237,   174,   237,   237,     4,    41,   164,   181,   213,   216,
     222,   237,   245,   246,   237,   181,   174,   174,   245,   181,
     181,   174,   174,   174,   174,   174,     4,   239,   239,   239,
     237,   237,   163,   164,   181,   181,   239,   181,   181,   181,
     176,   215,   245,     4,     6,   176,   215,   245,   245,   176,
     176,     6,   237,   237,    85,   174,   237,   178,   237,   181,
      91,   237,   237,     6,   174,   215,     6,   215,     6,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,     5,
     242,   180,   175,   180,   237,     4,   239,   194,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
       4,   251,   251,   251,   251,     5,   176,   175,     7,   164,
     237,   246,   247,   177,     7,   209,   210,   178,     7,   176,
       6,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   175,   180,   180,   175,
     175,   175,   237,   175,   237,   175,   175,   176,   181,     4,
     181,   247,     8,     7,   175,   237,   237,   237,     7,   237,
     237,   237,   237,   237,   237,   237,   175,   180,   180,   180,
     239,   239,   213,   214,   215,   216,   214,   180,   237,   237,
     237,   237,    41,    44,    45,    47,   182,   212,     6,     7,
       6,   237,   182,     7,     7,   237,   237,   175,   175,    86,
     237,   175,    88,   180,   215,   181,     8,   175,   237,   182,
     182,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,   142,     5,     5,     5,     5,     3,
       5,   175,   180,     5,     6,     5,   177,   210,   181,     4,
      76,    77,    78,    79,   182,   197,   201,   204,   206,   207,
     175,   177,   175,   177,   175,   177,   175,   177,   175,   177,
     175,   177,   175,   177,   175,   177,   175,   177,   175,   177,
     175,   177,   180,   180,   175,   177,   175,   177,   175,   177,
     175,   177,   175,   177,   175,   177,   180,   180,   180,   180,
     180,   180,   176,   178,   175,   180,   180,   175,   175,   180,
     237,   245,   180,   182,   178,   209,   210,   251,   237,     6,
       4,     4,   181,   249,   177,     8,     6,   247,   237,     7,
       7,     7,   175,     7,   175,     7,     7,   177,   181,   237,
     176,   247,   182,   237,   237,     7,   182,   175,   175,   237,
     182,   182,   175,   175,   175,   175,   175,   178,   239,   237,
     237,   182,   182,   237,   180,   180,   180,   177,   181,   181,
     181,   181,   237,   177,   181,   181,   177,   177,     7,     7,
     174,   175,     7,   178,   237,   182,   237,   237,   175,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,     5,
     175,   180,   178,   210,   251,   194,   198,   174,   174,   181,
     208,     6,   237,   237,   237,   237,   237,   237,   237,   237,
     237,     4,   247,   251,   237,   177,     6,   237,   246,   177,
       4,    88,    89,   237,     6,     6,     6,     7,   176,   248,
     250,     6,   237,   175,   180,   239,   245,   245,     7,   245,
       7,   245,   245,   247,   182,   177,   181,   182,     8,     6,
     181,     7,     7,     7,     6,    57,     7,     7,     7,     7,
       7,     7,     7,     4,   180,   180,   180,   182,   239,   239,
     239,     6,   247,   247,   247,   247,     6,     6,   237,   237,
       6,     6,   245,   245,   237,     7,   245,     4,   180,     8,
       8,   175,     7,     3,   237,   237,   239,     3,     3,   165,
       3,     3,   245,   245,     3,   239,     3,     3,   245,   245,
       3,     3,     3,     3,     3,   245,   109,   110,   111,   112,
     113,   236,   245,     3,     5,     5,     3,     3,     6,   241,
       4,     6,   182,   174,   237,   237,   244,   245,   181,   175,
     177,   175,   177,   175,   177,   175,   177,   177,   175,   175,
     175,   175,   209,     7,   209,   210,   178,     7,     6,   248,
     237,   180,   182,     6,   237,     6,     6,    52,     6,    52,
     245,     6,   245,     6,     6,   182,   247,   237,   237,   245,
     245,   245,    58,    59,   245,   245,   245,   245,   245,   245,
     245,     6,     7,   237,   237,   237,   181,   180,   182,   180,
     182,   180,   182,   182,   182,   182,   182,   180,   180,     6,
       6,   175,   174,   181,   243,    87,   237,   237,   237,   181,
     180,   180,   180,   175,   180,   175,   180,   175,   180,   175,
     180,   180,   175,   180,   175,   175,   180,   180,   180,   180,
     180,   180,   175,   180,   180,   180,   180,   180,   175,   180,
     180,   210,     6,   195,   237,   180,   180,   180,   182,   196,
     237,   178,   245,   251,   237,     6,     4,   249,     6,   177,
     248,   180,   239,   239,     6,     6,   177,   182,   180,     6,
       6,     6,   237,   237,     4,     6,     6,     6,     6,     6,
       6,     6,   237,   251,   182,   175,   180,   182,   214,   239,
       6,   223,   239,     6,   226,   239,     6,   229,     6,     6,
       6,     6,   237,   237,     7,   244,   244,    87,   245,   180,
     182,     8,   182,   175,   237,     3,   237,   245,     6,     3,
       6,   165,     6,   236,     6,     3,   237,     6,     3,     6,
       6,     3,   236,   237,   237,   237,   245,     6,     3,   236,
     237,     3,     3,     6,   237,   241,   175,   180,   237,   237,
     245,   181,   180,   182,     4,     6,     6,     6,     7,     6,
     178,   237,     6,     6,   177,   237,     6,     6,     6,     6,
       6,   181,   237,   182,   180,   181,   180,   181,   180,   181,
     180,   180,   243,   175,   182,   181,    84,   237,   237,   180,
     175,   180,   180,   180,   180,   175,   180,   175,   180,   175,
     175,   175,   180,   175,   180,   175,   175,   180,   180,   175,
     180,   180,   199,   237,   180,   180,   244,   237,     6,   175,
     248,    89,   180,   180,   214,   180,   182,   163,   164,   174,
     237,   239,    68,    73,   232,   233,   237,   239,   232,   237,
     239,   232,   237,   237,    87,   245,   237,   182,   182,   245,
       6,   243,   236,     3,   237,     6,   236,     6,     3,     6,
       6,     6,   237,     6,   245,     6,     6,   237,     3,     6,
     237,     5,   181,   237,   237,   182,     6,   237,     5,   182,
     237,   237,   182,   180,     6,   181,   182,   233,   182,   180,
     182,   182,   180,   182,   182,   182,   181,   180,     6,   182,
     180,   180,   180,   180,   175,   175,   175,   180,   175,   175,
     175,   180,   196,   175,   180,     6,   180,   180,   182,     6,
     224,   237,   245,     6,     6,   227,   237,     6,     6,   230,
     237,     6,     6,     6,   245,   245,     6,   236,   236,   236,
     236,     6,     6,     6,   236,     6,     6,     6,     5,   182,
     202,   237,   237,     5,   181,   182,   180,   181,   182,   181,
     182,   180,   182,   180,   180,   175,   175,   180,   180,     6,
     181,   175,   182,   180,   232,     6,   225,   245,   232,     6,
     228,   232,     6,   231,   245,    84,   236,   236,     6,     6,
     236,     5,   200,   251,   205,     6,     5,   182,   181,   180,
     182,   182,   181,   182,   181,   182,   181,   180,   180,   175,
     175,   180,   182,   181,   182,     6,   232,   245,     6,     6,
     232,     6,   232,    84,   237,   236,   245,     6,     6,   251,
       6,   203,   251,     6,   182,   182,   182,   182,   181,   180,
     180,   180,   180,   182,     6,     6,     6,     6,   237,   237,
     236,   245,   251,     6,   180,   182,   180,   180,   237,     6,
     245,   236,   182,   180,   175,     6,   245,     6,   180,   245,
     180,   245,   180,   236,   175,     6
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
#define YYERROR		goto yyerrlab1

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

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
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

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
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
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
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
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

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
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

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
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
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
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

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
	short *yyss1 = yyss;


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
	short *yyss1 = yyss;
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
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

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
        case 4:
#line 160 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 7:
#line 176 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 177 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 178 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 183 "Gmsh.y"
    {
      yymsg(INFO, "Reading Step Iso-10303-21 data");
      Create_Step_Solid_BRep();
    ;}
    break;

  case 11:
#line 188 "Gmsh.y"
    {
      Resolve_BREP ();
      yymsg(INFO, "Read Step Iso-10303-21 data");
    ;}
    break;

  case 15:
#line 199 "Gmsh.y"
    {
    ;}
    break;

  case 16:
#line 202 "Gmsh.y"
    {
    ;}
    break;

  case 17:
#line 206 "Gmsh.y"
    {
    ;}
    break;

  case 18:
#line 212 "Gmsh.y"
    {
      Add_Cartesian_Point((int)yyvsp[-8].d, yyvsp[-4].c, yyvsp[-2].v[0], yyvsp[-2].v[1], yyvsp[-2].v[2]);
    ;}
    break;

  case 19:
#line 218 "Gmsh.y"
    {
      Add_BSpline_Curve_With_Knots ((int)yyvsp[-22].d, yyvsp[-18].c, (int) yyvsp[-16].d, yyvsp[-14].l,	yyvsp[-6].l, yyvsp[-4].l, 0., 1.);
    ;}
    break;

  case 20:
#line 225 "Gmsh.y"
    {
      Add_BSpline_Surface_With_Knots ((int)yyvsp[-30].d, yyvsp[-26].c, (int) yyvsp[-24].d, (int) yyvsp[-22].d, yyvsp[-20].l, yyvsp[-10].l,
				      yyvsp[-8].l, yyvsp[-6].l, yyvsp[-4].l, 0., 1., 0., 1. );
    ;}
    break;

  case 21:
#line 231 "Gmsh.y"
    {
      Add_Edge_Curve ((int)yyvsp[-14].d, yyvsp[-10].c , (int)yyvsp[-8].d , (int)yyvsp[-6].d, (int)yyvsp[-4].d);
    ;}
    break;

  case 22:
#line 235 "Gmsh.y"
    {
      Add_Face_Outer_Bound((int)yyvsp[-10].d, yyvsp[-6].c, (int)yyvsp[-4].d, yyvsp[-2].i, 1);
    ;}
    break;

  case 23:
#line 239 "Gmsh.y"
    {
      // check the norm! Face_Bound : hole outside surface!
      yymsg(INFO, "Found a face bound");
      Add_Face_Outer_Bound((int)yyvsp[-10].d, yyvsp[-6].c, (int)yyvsp[-4].d, yyvsp[-2].i, 0);
    ;}
    break;

  case 24:
#line 246 "Gmsh.y"
    {
      Add_Oriented_Edge((int)yyvsp[-14].d, yyvsp[-10].c, (int)yyvsp[-4].d, yyvsp[-2].i);
    ;}
    break;

  case 25:
#line 250 "Gmsh.y"
    {
      Add_Edge_Loop((int)yyvsp[-8].d, yyvsp[-4].c, yyvsp[-2].l);
    ;}
    break;

  case 26:
#line 255 "Gmsh.y"
    {
      Add_Advanced_Face((int)yyvsp[-12].d, yyvsp[-8].c, yyvsp[-6].l, (int)yyvsp[-4].d, yyvsp[-2].i);
    ;}
    break;

  case 27:
#line 259 "Gmsh.y"
    {
      Add_Vertex_Point((int)yyvsp[-8].d, yyvsp[-4].c, (int)yyvsp[-2].d);
    ;}
    break;

  case 28:
#line 263 "Gmsh.y"
    {
    ;}
    break;

  case 29:
#line 267 "Gmsh.y"
    {
      Add_Axis2_Placement3D  ((int)yyvsp[-12].d, (int)yyvsp[-4].d, (int)yyvsp[-2].d, (int)yyvsp[-6].d);
    ;}
    break;

  case 30:
#line 271 "Gmsh.y"
    {
      Add_Direction((int)yyvsp[-8].d , yyvsp[-4].c, yyvsp[-2].v[0], yyvsp[-2].v[1], yyvsp[-2].v[2]);
    ;}
    break;

  case 31:
#line 275 "Gmsh.y"
    {
      Add_Plane((int)yyvsp[-8].d, yyvsp[-4].c, (int)yyvsp[-2].d);
    ;}
    break;

  case 32:
#line 279 "Gmsh.y"
    {
      Add_Line ((int)yyvsp[-10].d, yyvsp[-6].c , (int) yyvsp[-4].d, (int)yyvsp[-2].d);
    ;}
    break;

  case 33:
#line 283 "Gmsh.y"
    {
      yymsg(INFO, "Found a closed shell");
      Add_Closed_Shell((int)yyvsp[-8].d, yyvsp[-4].c , yyvsp[-2].l);
    ;}
    break;

  case 34:
#line 289 "Gmsh.y"
    {
    ;}
    break;

  case 35:
#line 292 "Gmsh.y"
    {
    ;}
    break;

  case 36:
#line 295 "Gmsh.y"
    {
      Add_Cylinder ((int)yyvsp[-10].d, yyvsp[-6].c , (int)yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 37:
#line 299 "Gmsh.y"
    {
      Add_Cone ((int)yyvsp[-12].d, yyvsp[-8].c , (int)yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 38:
#line 303 "Gmsh.y"
    {
      Add_Torus ((int)yyvsp[-12].d, yyvsp[-8].c , (int)yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 39:
#line 307 "Gmsh.y"
    {
      Add_Circle((int) yyvsp[-10].d, yyvsp[-6].c, (int) yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 40:
#line 311 "Gmsh.y"
    {
      Add_Ellipse((int) yyvsp[-12].d, yyvsp[-8].c, (int) yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 41:
#line 316 "Gmsh.y"
    {
    ;}
    break;

  case 42:
#line 319 "Gmsh.y"
    {
    ;}
    break;

  case 43:
#line 323 "Gmsh.y"
    {
    ;}
    break;

  case 44:
#line 326 "Gmsh.y"
    {
    ;}
    break;

  case 45:
#line 330 "Gmsh.y"
    {
    ;}
    break;

  case 46:
#line 333 "Gmsh.y"
    {
    ;}
    break;

  case 47:
#line 336 "Gmsh.y"
    {
    ;}
    break;

  case 50:
#line 348 "Gmsh.y"
    { return 1; ;}
    break;

  case 51:
#line 349 "Gmsh.y"
    { return 1; ;}
    break;

  case 52:
#line 350 "Gmsh.y"
    { return 1; ;}
    break;

  case 53:
#line 351 "Gmsh.y"
    { return 1; ;}
    break;

  case 54:
#line 352 "Gmsh.y"
    { List_Delete(yyvsp[0].l); return 1; ;}
    break;

  case 55:
#line 353 "Gmsh.y"
    { List_Delete(yyvsp[0].l); return 1; ;}
    break;

  case 56:
#line 354 "Gmsh.y"
    { return 1; ;}
    break;

  case 57:
#line 355 "Gmsh.y"
    { return 1; ;}
    break;

  case 58:
#line 356 "Gmsh.y"
    { return 1; ;}
    break;

  case 59:
#line 357 "Gmsh.y"
    { List_Delete(yyvsp[0].l); return 1; ;}
    break;

  case 60:
#line 358 "Gmsh.y"
    { return 1; ;}
    break;

  case 61:
#line 359 "Gmsh.y"
    { return 1; ;}
    break;

  case 62:
#line 360 "Gmsh.y"
    { return 1; ;}
    break;

  case 63:
#line 361 "Gmsh.y"
    { return 1; ;}
    break;

  case 64:
#line 366 "Gmsh.y"
    {
      Msg(DIRECT, yyvsp[-2].c);
      Free(yyvsp[-2].c);
    ;}
    break;

  case 65:
#line 371 "Gmsh.y"
    {
      char tmpstring[1024];
      int i = PrintListOfDouble(yyvsp[-4].c, yyvsp[-2].l, tmpstring);
      if(i < 0) 
	yymsg(GERROR, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(GERROR, "%d extra argument%s in Printf", i, (i>1)?"s":"");
      else
	Msg(DIRECT, tmpstring);
      Free(yyvsp[-4].c);
      List_Delete(yyvsp[-2].l);
    ;}
    break;

  case 66:
#line 389 "Gmsh.y"
    { 
      if(!strcmp(yyvsp[-5].c, "View") && !CheckViewErrorFlags(View)){
	EndView(View, 0, yyname, yyvsp[-4].c);
      }
      Free(yyvsp[-5].c); Free(yyvsp[-4].c);
    ;}
    break;

  case 67:
#line 396 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-7].c, "View") && !CheckViewErrorFlags(View)){
	EndView(View, 0, yyname, yyvsp[-6].c);
      }
      Free(yyvsp[-7].c); Free(yyvsp[-6].c); Free(yyvsp[-5].c);
    ;}
    break;

  case 68:
#line 406 "Gmsh.y"
    {
      View = BeginView(1); 
      for(int i = 0; i < VIEW_NB_ELEMENT_TYPES; i++){
	ViewErrorFlags[i] = 0;
      }
    ;}
    break;

  case 74:
#line 421 "Gmsh.y"
    { ViewCoord[ViewCoordIdx] = yyvsp[0].d; ViewCoordIdx++; ;}
    break;

  case 75:
#line 423 "Gmsh.y"
    { ViewCoord[ViewCoordIdx] = yyvsp[0].d; ViewCoordIdx++; ;}
    break;

  case 76:
#line 428 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &yyvsp[0].d); ;}
    break;

  case 77:
#line 430 "Gmsh.y"
    { if(ViewValueList) List_Add(ViewValueList, &yyvsp[0].d); ;}
    break;

  case 78:
#line 435 "Gmsh.y"
    {
      if(!strcmp(yyvsp[0].c, "SP")){
	ViewElementIdx = 0; ViewNumNodes = 1; ViewNumComp = 1;
	ViewValueList = View->SP; ViewNumList = &View->NbSP;
      }
      else if(!strcmp(yyvsp[0].c, "VP")){
	ViewElementIdx = 1; ViewNumNodes = 1; ViewNumComp = 3;
	ViewValueList = View->VP; ViewNumList = &View->NbVP;
      }
      else if(!strcmp(yyvsp[0].c, "TP")){
	ViewElementIdx = 2; ViewNumNodes = 1; ViewNumComp = 9;
	ViewValueList = View->TP; ViewNumList = &View->NbTP;
      }
      else if(!strcmp(yyvsp[0].c, "SL")){
	ViewElementIdx = 3; ViewNumNodes = 2; ViewNumComp = 1;
	ViewValueList = View->SL; ViewNumList = &View->NbSL;
      }
      else if(!strcmp(yyvsp[0].c, "VL")){
	ViewElementIdx = 4; ViewNumNodes = 2; ViewNumComp = 3;
	ViewValueList = View->VL; ViewNumList = &View->NbVL;
      }
      else if(!strcmp(yyvsp[0].c, "TL")){
	ViewElementIdx = 5; ViewNumNodes = 2; ViewNumComp = 9;
	ViewValueList = View->TL; ViewNumList = &View->NbTL;
      }
      else if(!strcmp(yyvsp[0].c, "ST")){
	ViewElementIdx = 6; ViewNumNodes = 3; ViewNumComp = 1;
	ViewValueList = View->ST; ViewNumList = &View->NbST;
      }
      else if(!strcmp(yyvsp[0].c, "VT")){
	ViewElementIdx = 7; ViewNumNodes = 3; ViewNumComp = 3;
	ViewValueList = View->VT; ViewNumList = &View->NbVT;
      }
      else if(!strcmp(yyvsp[0].c, "TT")){
	ViewElementIdx = 8; ViewNumNodes = 3; ViewNumComp = 9;
	ViewValueList = View->TT; ViewNumList = &View->NbTT;
      }
      else if(!strcmp(yyvsp[0].c, "SQ")){
	ViewElementIdx = 9; ViewNumNodes = 4; ViewNumComp = 1;
	ViewValueList = View->SQ; ViewNumList = &View->NbSQ;
      }
      else if(!strcmp(yyvsp[0].c, "VQ")){
	ViewElementIdx = 10; ViewNumNodes = 4; ViewNumComp = 3;
	ViewValueList = View->VQ; ViewNumList = &View->NbVQ;
      }
      else if(!strcmp(yyvsp[0].c, "TQ")){
	ViewElementIdx = 11; ViewNumNodes = 4; ViewNumComp = 9;
	ViewValueList = View->TQ; ViewNumList = &View->NbTQ;
      }
      else if(!strcmp(yyvsp[0].c, "SS")){
	ViewElementIdx = 12; ViewNumNodes = 4; ViewNumComp = 1;
	ViewValueList = View->SS; ViewNumList = &View->NbSS;
      }
      else if(!strcmp(yyvsp[0].c, "VS")){
	ViewElementIdx = 13; ViewNumNodes = 4; ViewNumComp = 3;
	ViewValueList = View->VS; ViewNumList = &View->NbVS;
      }
      else if(!strcmp(yyvsp[0].c, "TS")){
	ViewElementIdx = 14; ViewNumNodes = 4; ViewNumComp = 9;
	ViewValueList = View->TS; ViewNumList = &View->NbTS;
      }
      else if(!strcmp(yyvsp[0].c, "SH")){
	ViewElementIdx = 15; ViewNumNodes = 8; ViewNumComp = 1;
	ViewValueList = View->SH; ViewNumList = &View->NbSH;
      }
      else if(!strcmp(yyvsp[0].c, "VH")){
	ViewElementIdx = 16; ViewNumNodes = 8; ViewNumComp = 3;
	ViewValueList = View->VH; ViewNumList = &View->NbVH;
      }
      else if(!strcmp(yyvsp[0].c, "TH")){
	ViewElementIdx = 17; ViewNumNodes = 8; ViewNumComp = 9;
	ViewValueList = View->TH; ViewNumList = &View->NbTH;
      }
      else if(!strcmp(yyvsp[0].c, "SI")){
	ViewElementIdx = 18; ViewNumNodes = 6; ViewNumComp = 1;
	ViewValueList = View->SI; ViewNumList = &View->NbSI;
      }
      else if(!strcmp(yyvsp[0].c, "VI")){
	ViewElementIdx = 19; ViewNumNodes = 6; ViewNumComp = 3;
	ViewValueList = View->VI; ViewNumList = &View->NbVI;
      }
      else if(!strcmp(yyvsp[0].c, "TI")){
	ViewElementIdx = 20; ViewNumNodes = 6; ViewNumComp = 9;
	ViewValueList = View->TI; ViewNumList = &View->NbTI;
      }
      else if(!strcmp(yyvsp[0].c, "SY")){
	ViewElementIdx = 21; ViewNumNodes = 5; ViewNumComp = 1;
	ViewValueList = View->SY; ViewNumList = &View->NbSY;
      }
      else if(!strcmp(yyvsp[0].c, "VY")){
	ViewElementIdx = 22; ViewNumNodes = 5; ViewNumComp = 3;
	ViewValueList = View->VY; ViewNumList = &View->NbVY;
      }
      else if(!strcmp(yyvsp[0].c, "TY")){
	ViewElementIdx = 23; ViewNumNodes = 5; ViewNumComp = 9;
	ViewValueList = View->TY; ViewNumList = &View->NbTY;
      }
      else if(!strcmp(yyvsp[0].c, "SL2")){
	ViewElementIdx = 3; ViewNumNodes = 3; ViewNumComp = 1;
	ViewValueList = View->SL2; ViewNumList = &View->NbSL2;
      }
      else if(!strcmp(yyvsp[0].c, "VL2")){
	ViewElementIdx = 4; ViewNumNodes = 3; ViewNumComp = 3;
	ViewValueList = View->VL2; ViewNumList = &View->NbVL2;
      }
      else if(!strcmp(yyvsp[0].c, "TL2")){
	ViewElementIdx = 5; ViewNumNodes = 3; ViewNumComp = 9;
	ViewValueList = View->TL2; ViewNumList = &View->NbTL2;
      }
      else if(!strcmp(yyvsp[0].c, "ST2")){
	ViewElementIdx = 6; ViewNumNodes = 6; ViewNumComp = 1;
	ViewValueList = View->ST2; ViewNumList = &View->NbST2;
      }
      else if(!strcmp(yyvsp[0].c, "VT2")){
	ViewElementIdx = 7; ViewNumNodes = 6; ViewNumComp = 3;
	ViewValueList = View->VT2; ViewNumList = &View->NbVT2;
      }
      else if(!strcmp(yyvsp[0].c, "TT2")){
	ViewElementIdx = 8; ViewNumNodes = 6; ViewNumComp = 9;
	ViewValueList = View->TT2; ViewNumList = &View->NbTT2;
      }
      else if(!strcmp(yyvsp[0].c, "SQ2")){
	ViewElementIdx = 9; ViewNumNodes = 9; ViewNumComp = 1;
	ViewValueList = View->SQ2; ViewNumList = &View->NbSQ2;
      }
      else if(!strcmp(yyvsp[0].c, "VQ2")){
	ViewElementIdx = 10; ViewNumNodes = 9; ViewNumComp = 3;
	ViewValueList = View->VQ2; ViewNumList = &View->NbVQ2;
      }
      else if(!strcmp(yyvsp[0].c, "TQ2")){
	ViewElementIdx = 11; ViewNumNodes = 9; ViewNumComp = 9;
	ViewValueList = View->TQ2; ViewNumList = &View->NbTQ2;
      }
      else if(!strcmp(yyvsp[0].c, "SS2")){
	ViewElementIdx = 12; ViewNumNodes = 10; ViewNumComp = 1;
	ViewValueList = View->SS2; ViewNumList = &View->NbSS2;
      }
      else if(!strcmp(yyvsp[0].c, "VS2")){
	ViewElementIdx = 13; ViewNumNodes = 10; ViewNumComp = 3;
	ViewValueList = View->VS2; ViewNumList = &View->NbVS2;
      }
      else if(!strcmp(yyvsp[0].c, "TS2")){
	ViewElementIdx = 14; ViewNumNodes = 10; ViewNumComp = 9;
	ViewValueList = View->TS2; ViewNumList = &View->NbTS2;
      }
      else if(!strcmp(yyvsp[0].c, "SH2")){
	ViewElementIdx = 15; ViewNumNodes = 27; ViewNumComp = 1;
	ViewValueList = View->SH2; ViewNumList = &View->NbSH2;
      }
      else if(!strcmp(yyvsp[0].c, "VH2")){
	ViewElementIdx = 16; ViewNumNodes = 27; ViewNumComp = 3;
	ViewValueList = View->VH2; ViewNumList = &View->NbVH2;
      }
      else if(!strcmp(yyvsp[0].c, "TH2")){
	ViewElementIdx = 17; ViewNumNodes = 27; ViewNumComp = 9;
	ViewValueList = View->TH2; ViewNumList = &View->NbTH2;
      }
      else if(!strcmp(yyvsp[0].c, "SI2")){
	ViewElementIdx = 18; ViewNumNodes = 18; ViewNumComp = 1;
	ViewValueList = View->SI2; ViewNumList = &View->NbSI2;
      }
      else if(!strcmp(yyvsp[0].c, "VI2")){
	ViewElementIdx = 19; ViewNumNodes = 18; ViewNumComp = 3;
	ViewValueList = View->VI2; ViewNumList = &View->NbVI2;
      }
      else if(!strcmp(yyvsp[0].c, "TI2")){
	ViewElementIdx = 20; ViewNumNodes = 18; ViewNumComp = 9;
	ViewValueList = View->TI2; ViewNumList = &View->NbTI2;
      }
      else if(!strcmp(yyvsp[0].c, "SY2")){
	ViewElementIdx = 21; ViewNumNodes = 14; ViewNumComp = 1;
	ViewValueList = View->SY2; ViewNumList = &View->NbSY2;
      }
      else if(!strcmp(yyvsp[0].c, "VY2")){
	ViewElementIdx = 22; ViewNumNodes = 14; ViewNumComp = 3;
	ViewValueList = View->VY2; ViewNumList = &View->NbVY2;
      }
      else if(!strcmp(yyvsp[0].c, "TY2")){
	ViewElementIdx = 23; ViewNumNodes = 14; ViewNumComp = 9;
	ViewValueList = View->TY2; ViewNumList = &View->NbTY2;
      }
      else{
	yymsg(GERROR, "Unknown element type '%s'", yyvsp[0].c);	
	ViewElementIdx = -1; ViewNumNodes = 0; ViewNumComp = 0;
	ViewValueList = NULL; ViewNumList = NULL;
      }
      Free(yyvsp[0].c);
      ViewCoordIdx = 0;
    ;}
    break;

  case 79:
#line 625 "Gmsh.y"
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

  case 80:
#line 643 "Gmsh.y"
    {
      if(ViewValueList){  
	if((List_Nbr(ViewValueList) - ViewNumListTmp) % (ViewNumComp * ViewNumNodes)) 
	  ViewErrorFlags[ViewElementIdx]++;
	(*ViewNumList)++;
      }
    ;}
    break;

  case 81:
#line 654 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T2C, &yyvsp[0].c[i]); 
      Free(yyvsp[0].c);
    ;}
    break;

  case 82:
#line 659 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T2C, &yyvsp[0].c[i]); 
      Free(yyvsp[0].c);
    ;}
    break;

  case 83:
#line 667 "Gmsh.y"
    { 
      List_Add(View->T2D, &yyvsp[-5].d); List_Add(View->T2D, &yyvsp[-3].d);
      List_Add(View->T2D, &yyvsp[-1].d); 
      double d = List_Nbr(View->T2C);
      List_Add(View->T2D, &d); 
    ;}
    break;

  case 84:
#line 674 "Gmsh.y"
    {
      View->NbT2++;
    ;}
    break;

  case 85:
#line 681 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T3C, &yyvsp[0].c[i]); 
      Free(yyvsp[0].c);
    ;}
    break;

  case 86:
#line 686 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T3C, &yyvsp[0].c[i]); 
      Free(yyvsp[0].c);
    ;}
    break;

  case 87:
#line 694 "Gmsh.y"
    { 
      List_Add(View->T3D, &yyvsp[-7].d); List_Add(View->T3D, &yyvsp[-5].d);
      List_Add(View->T3D, &yyvsp[-3].d); List_Add(View->T3D, &yyvsp[-1].d); 
      double d = List_Nbr(View->T3C);
      List_Add(View->T3D, &d); 
    ;}
    break;

  case 88:
#line 701 "Gmsh.y"
    {
      View->NbT3++;
    ;}
    break;

  case 89:
#line 709 "Gmsh.y"
    {
      View->adaptive = new Adaptive_Post_View(View, yyvsp[-5].l, yyvsp[-2].l);
    ;}
    break;

  case 90:
#line 716 "Gmsh.y"
    {
      ViewValueList = View->Time;
    ;}
    break;

  case 91:
#line 720 "Gmsh.y"
    {
    ;}
    break;

  case 92:
#line 727 "Gmsh.y"
    { yyval.i = 0; ;}
    break;

  case 93:
#line 728 "Gmsh.y"
    { yyval.i = 1; ;}
    break;

  case 94:
#line 729 "Gmsh.y"
    { yyval.i = 2; ;}
    break;

  case 95:
#line 730 "Gmsh.y"
    { yyval.i = 3; ;}
    break;

  case 96:
#line 731 "Gmsh.y"
    { yyval.i = 4; ;}
    break;

  case 97:
#line 735 "Gmsh.y"
    { yyval.i = 1; ;}
    break;

  case 98:
#line 736 "Gmsh.y"
    { yyval.i = -1; ;}
    break;

  case 99:
#line 744 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-3].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	if(!yyvsp[-2].i){
	  TheSymbol.val = List_Create(1, 1, sizeof(double));
	  List_Put(TheSymbol.val, 0, &yyvsp[-1].d);
	  Tree_Add(Symbol_T, &TheSymbol);
	}
	else{
	  yymsg(GERROR, "Unknown variable '%s'", yyvsp[-3].c);
	  Free(yyvsp[-3].c);
	}
      }
      else{
	double *pd = (double*)List_Pointer_Fast(pSymbol->val, 0); 
	switch(yyvsp[-2].i){
	case 0 : *pd = yyvsp[-1].d; break;
	case 1 : *pd += yyvsp[-1].d; break;
	case 2 : *pd -= yyvsp[-1].d; break;
	case 3 : *pd *= yyvsp[-1].d; break;
	case 4 : 
	  if(yyvsp[-1].d) *pd /= yyvsp[-1].d; 
	  else yymsg(GERROR, "Division by zero in '%s /= %g'", yyvsp[-3].c, yyvsp[-1].d);
	  break;
	}
	Free(yyvsp[-3].c);
      }
    ;}
    break;

  case 100:
#line 775 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-6].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	if(!yyvsp[-2].i){
	  TheSymbol.val = List_Create(5, 5, sizeof(double));
	  List_Put(TheSymbol.val, (int)yyvsp[-4].d, &yyvsp[-1].d);
	  Tree_Add(Symbol_T, &TheSymbol);
	}
	else{
	  yymsg(GERROR, "Unknown variable '%s'", yyvsp[-6].c);
	  Free(yyvsp[-6].c);
	}
      }
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)yyvsp[-4].d))){
	  switch(yyvsp[-2].i){
	  case 0 : *pd = yyvsp[-1].d; break;
	  case 1 : *pd += yyvsp[-1].d; break;
	  case 2 : *pd -= yyvsp[-1].d; break;
	  case 3 : *pd *= yyvsp[-1].d; break;
	  case 4 : 
	    if(yyvsp[-1].d) *pd /= yyvsp[-1].d; 
	    else yymsg(GERROR, "Division by zero in '%s[%d] /= %g'", yyvsp[-6].c, (int)yyvsp[-4].d, yyvsp[-1].d);
	    break;
	  }
	}
	else{
	  if(!yyvsp[-2].i)
	    List_Put(pSymbol->val, (int)yyvsp[-4].d, &yyvsp[-1].d);
	  else
	    yymsg(GERROR, "Uninitialized variable '%s[%d]'", yyvsp[-6].c, (int)yyvsp[-4].d);
	}
	Free(yyvsp[-6].c);
      }
    ;}
    break;

  case 101:
#line 814 "Gmsh.y"
    {
      if(List_Nbr(yyvsp[-5].l) != List_Nbr(yyvsp[-1].l)){
	yymsg(GERROR, "Incompatible array dimensions in affectation");
	Free(yyvsp[-8].c);
      }
      else{
	Symbol TheSymbol;
	TheSymbol.Name = yyvsp[-8].c;
	Symbol *pSymbol;
	if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	  if(!yyvsp[-2].i){
	    TheSymbol.val = List_Create(5, 5, sizeof(double));
	    for(int i = 0; i < List_Nbr(yyvsp[-5].l); i++){
	      List_Put(TheSymbol.val, (int)(*(double*)List_Pointer(yyvsp[-5].l, i)),
		       (double*)List_Pointer(yyvsp[-1].l, i));
	    }
	    Tree_Add(Symbol_T, &TheSymbol);
	  }
	  else{
	    yymsg(GERROR, "Unknown variable '%s'", yyvsp[-8].c);
	    Free(yyvsp[-8].c);
	  }
	}
	else{
	  for(int i = 0; i < List_Nbr(yyvsp[-5].l); i++){
	    int j = (int)(*(double*)List_Pointer(yyvsp[-5].l, i));
	    double d = *(double*)List_Pointer(yyvsp[-1].l, i);
	    double *pd;
	    if((pd = (double*)List_Pointer_Test(pSymbol->val, j))){
	      switch(yyvsp[-2].i){
	      case 0 : *pd = d; break;
	      case 1 : *pd += d; break;
	      case 2 : *pd -= d; break;
	      case 3 : *pd *= d; break;
	      case 4 : 
		if(yyvsp[-1].l) *pd /= d; 
		else yymsg(GERROR, "Division by zero in '%s[%d] /= %g'", yyvsp[-8].c, j, d);
		break;
	      }
	    }
	    else{
	      if(!yyvsp[-2].i)
		List_Put(pSymbol->val, j, &d);
	      else
		yymsg(GERROR, "Uninitialized variable '%s[%d]'", yyvsp[-8].c, j);	  
	    }
	  }
	  Free(yyvsp[-8].c);
	}
      }
      List_Delete(yyvsp[-5].l);
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 102:
#line 868 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-5].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(5, 5, sizeof(double));
	List_Copy(yyvsp[-1].l, TheSymbol.val);
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	List_Reset(pSymbol->val);
	List_Copy(yyvsp[-1].l, pSymbol->val);
	Free(yyvsp[-5].c);
      }
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 103:
#line 885 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-2].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol)))
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-2].c); 
      else
	*(double*)List_Pointer_Fast(pSymbol->val, 0) += yyvsp[-1].i;
      Free(yyvsp[-2].c);
    ;}
    break;

  case 104:
#line 896 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-5].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol)))
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-5].c); 
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)yyvsp[-3].d)))
	  *pd += yyvsp[-1].i;
	else
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", yyvsp[-5].c, (int)yyvsp[-3].d);
      }
      Free(yyvsp[-5].c);
    ;}
    break;

  case 105:
#line 915 "Gmsh.y"
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory(yyvsp[-5].c)))
	yymsg(GERROR, "Unknown string option class '%s'", yyvsp[-5].c);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption(yyvsp[-3].c, pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s.%s'", yyvsp[-5].c, yyvsp[-3].c);
	else
	  pStrOpt(0, GMSH_SET|GMSH_GUI, yyvsp[-1].c);
      }
      Free(yyvsp[-5].c); Free(yyvsp[-3].c); //FIXME: somtimes leak $5
    ;}
    break;

  case 106:
#line 929 "Gmsh.y"
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory(yyvsp[-8].c)))
	yymsg(GERROR, "Unknown string option class '%s'", yyvsp[-8].c);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption(yyvsp[-3].c, pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s[%d].%s'", yyvsp[-8].c, (int)yyvsp[-6].d, yyvsp[-3].c);
	else
	  pStrOpt((int)yyvsp[-6].d, GMSH_SET|GMSH_GUI, yyvsp[-1].c);
      }
      Free(yyvsp[-8].c); Free(yyvsp[-3].c); //FIXME: somtimes leak $8
    ;}
    break;

  case 107:
#line 946 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-5].c)))
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-5].c);
      else{
	if(!(pNumOpt = (double (*) (int, int, double))Get_NumberOption(yyvsp[-3].c, pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", yyvsp[-5].c, yyvsp[-3].c);
	else{
	  double d = 0;
	  switch(yyvsp[-2].i){
	  case 0 : d = yyvsp[-1].d; break;
	  case 1 : d = pNumOpt(0, GMSH_GET, 0) + yyvsp[-1].d; break;
	  case 2 : d = pNumOpt(0, GMSH_GET, 0) - yyvsp[-1].d; break;
	  case 3 : d = pNumOpt(0, GMSH_GET, 0) * yyvsp[-1].d; break;
	  case 4 : 
	    if(yyvsp[-1].d) d = pNumOpt(0, GMSH_GET, 0) / yyvsp[-1].d; 
	    else yymsg(GERROR, "Division by zero in '%s.%s /= %g'", yyvsp[-5].c, yyvsp[-3].c, yyvsp[-1].d);
	    break;
	  }
	  pNumOpt(0, GMSH_SET|GMSH_GUI, d);
	}
      }
      Free(yyvsp[-5].c); Free(yyvsp[-3].c);
    ;}
    break;

  case 108:
#line 972 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-8].c)))
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-8].c);
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption(yyvsp[-3].c, pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", yyvsp[-8].c, (int)yyvsp[-6].d, yyvsp[-3].c);
	else{
	  double d = 0;
	  switch(yyvsp[-2].i){
	  case 0 : d = yyvsp[-1].d; break;
	  case 1 : d = pNumOpt((int)yyvsp[-6].d, GMSH_GET, 0) + yyvsp[-1].d; break;
	  case 2 : d = pNumOpt((int)yyvsp[-6].d, GMSH_GET, 0) - yyvsp[-1].d; break;
	  case 3 : d = pNumOpt((int)yyvsp[-6].d, GMSH_GET, 0) * yyvsp[-1].d; break;
	  case 4 : 
	    if(yyvsp[-1].d) d = pNumOpt((int)yyvsp[-6].d, GMSH_GET, 0) / yyvsp[-1].d;
	    else yymsg(GERROR, "Division by zero in '%s[%d].%s /= %g'", 
		       yyvsp[-8].c, (int)yyvsp[-6].d, yyvsp[-3].c, yyvsp[-1].d);
	    break;
	  }
	  pNumOpt((int)yyvsp[-6].d, GMSH_SET|GMSH_GUI, d);
	}
      }
      Free(yyvsp[-8].c); Free(yyvsp[-3].c);
    ;}
    break;

  case 109:
#line 999 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-4].c)))
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-4].c);
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption(yyvsp[-2].c, pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", yyvsp[-4].c, yyvsp[-2].c);
	else
	  pNumOpt(0, GMSH_SET|GMSH_GUI, pNumOpt(0, GMSH_GET, 0)+yyvsp[-1].i);
      }
      Free(yyvsp[-4].c); Free(yyvsp[-2].c);
    ;}
    break;

  case 110:
#line 1013 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-7].c)))
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-7].c);
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption(yyvsp[-2].c, pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", yyvsp[-7].c, (int)yyvsp[-5].d, yyvsp[-2].c);
	else
	  pNumOpt((int)yyvsp[-5].d, GMSH_SET|GMSH_GUI, pNumOpt((int)yyvsp[-5].d, GMSH_GET, 0)+yyvsp[-1].i);
      }
      Free(yyvsp[-7].c); Free(yyvsp[-2].c);
    ;}
    break;

  case 111:
#line 1030 "Gmsh.y"
    {
      unsigned int (*pColOpt)(int num, int action, unsigned int value);
      StringXColor *pColCat;
      if(!(pColCat = Get_ColorOptionCategory(yyvsp[-7].c)))
	yymsg(GERROR, "Unknown color option class '%s'", yyvsp[-7].c);
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption(yyvsp[-3].c, pColCat)))
	  yymsg(GERROR, "Unknown color option '%s.Color.%s'", yyvsp[-7].c, yyvsp[-3].c);
	else
	  pColOpt(0, GMSH_SET|GMSH_GUI, yyvsp[-1].u);
      }
      Free(yyvsp[-7].c); Free(yyvsp[-3].c);
    ;}
    break;

  case 112:
#line 1044 "Gmsh.y"
    {
      unsigned int (*pColOpt)(int num, int action, unsigned int value);
      StringXColor *pColCat;
      if(!(pColCat = Get_ColorOptionCategory(yyvsp[-10].c)))
	yymsg(GERROR, "Unknown color option class '%s'", yyvsp[-10].c);
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption(yyvsp[-3].c, pColCat)))
	  yymsg(GERROR, "Unknown color option '%s[%d].Color.%s'", yyvsp[-10].c, (int)yyvsp[-8].d, yyvsp[-3].c);
	else
	  pColOpt((int)yyvsp[-8].d, GMSH_SET|GMSH_GUI, yyvsp[-1].u);
      }
      Free(yyvsp[-10].c); Free(yyvsp[-3].c);
    ;}
    break;

  case 113:
#line 1061 "Gmsh.y"
    {
      GmshColorTable *ct = Get_ColorTable(0);
      if(!ct)
	yymsg(GERROR, "View[%d] does not exist", 0);
      else{
	ct->size = List_Nbr(yyvsp[-1].l);
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(GERROR, "Too many (%d>%d) colors in View[%d].ColorTable", 
		ct->size, COLORTABLE_NBMAX_COLOR, 0);
	else
	  for(int i = 0; i < ct->size; i++) List_Read(yyvsp[-1].l, i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free(yyvsp[-5].c);
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 114:
#line 1081 "Gmsh.y"
    {
      GmshColorTable *ct = Get_ColorTable((int)yyvsp[-6].d);
      if(!ct)
	yymsg(GERROR, "View[%d] does not exist", (int)yyvsp[-6].d);
      else{
	ct->size = List_Nbr(yyvsp[-1].l);
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(GERROR, "Too many (%d>%d) colors in View[%d].ColorTable", 
		   ct->size, COLORTABLE_NBMAX_COLOR, (int)yyvsp[-6].d);
	else
	  for(int i = 0; i < ct->size; i++) List_Read(yyvsp[-1].l, i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free(yyvsp[-8].c);
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 115:
#line 1104 "Gmsh.y"
    {
      try {
	GMSH_PluginManager::instance()->setPluginOption(yyvsp[-6].c, yyvsp[-3].c, yyvsp[-1].d); 
      }
      catch (...) {
	yymsg(GERROR, "Unknown option '%s' or plugin '%s'", yyvsp[-3].c, yyvsp[-6].c);
      }
      Free(yyvsp[-6].c); Free(yyvsp[-3].c);
    ;}
    break;

  case 116:
#line 1114 "Gmsh.y"
    {
      try {
	GMSH_PluginManager::instance()->setPluginOption(yyvsp[-6].c, yyvsp[-3].c, yyvsp[-1].c); 
      }
      catch (...) {
	yymsg(GERROR, "Unknown option '%s' or plugin '%s'", yyvsp[-3].c, yyvsp[-6].c);
      }
      Free(yyvsp[-6].c); Free(yyvsp[-3].c); // FIXME: sometimes leak $8
    ;}
    break;

  case 117:
#line 1133 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(FindPoint(num, THEM)){
	yymsg(GERROR, "Point %d already exists", num);
      }
      else{
	Vertex *v = Create_Vertex(num, CTX.geom.scaling_factor * yyvsp[-1].v[0],
				  CTX.geom.scaling_factor * yyvsp[-1].v[1],
				  CTX.geom.scaling_factor * yyvsp[-1].v[2],
				  CTX.geom.scaling_factor * yyvsp[-1].v[3], 1.0);
	Tree_Add(THEM->Points, &v);
      }
      yyval.s.Type = MSH_POINT;
      yyval.s.Num = num;
    ;}
    break;

  case 118:
#line 1149 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT, THEM)){
	yymsg(GERROR, "Physical point %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_PHYSICAL_POINT;
      yyval.s.Num = num;
    ;}
    break;

  case 119:
#line 1165 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-9].l); i++){
	double p;
      	List_Read(yyvsp[-9].l, i, &p);
        Vertex *v = FindPoint((int)p, THEM);
        if(!v)
	  yymsg(WARNING, "Unknown point %d", (int)p);
	else{
	  Attractor *a = Create_Attractor(List_Nbr(THEM->Metric->Attractors)+1,
					  yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d, v, NULL, NULL);
	  List_Add(THEM->Metric->Attractors, &a);
        }
      }
      List_Delete(yyvsp[-9].l);
      // dummy values
      yyval.s.Type = 0;
      yyval.s.Num = 0;
    ;}
    break;

  case 120:
#line 1184 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-3].l); i++){
	double d;
	List_Read(yyvsp[-3].l, i, &d);
	Vertex *v = FindPoint((int)d, THEM);
	if(!v)
	  yymsg(WARNING, "Unknown point %d", (int)d);
	else
	  v->lc = yyvsp[-1].d;
      }
      List_Delete(yyvsp[-3].l);
      // dummy values
      yyval.s.Type = 0;
      yyval.s.Num = 0;
    ;}
    break;

  case 121:
#line 1203 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
	List_Delete(temp);
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_SEGM_LINE;
      yyval.s.Num = num;
    ;}
    break;

  case 122:
#line 1221 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	Curve *c = Create_Curve(num, MSH_SEGM_SPLN, 3, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
	List_Delete(temp);
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_SEGM_SPLN;
      yyval.s.Num = num;
    ;}
    break;

  case 123:
#line 1239 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
	List_Delete(temp);
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_SEGM_CIRC;
      yyval.s.Num = num;
    ;}
    break;

  case 124:
#line 1257 "Gmsh.y"
    {
      int num = (int)yyvsp[-6].d;
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-3].l);
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
	c->Circle.n[0] = yyvsp[-1].v[0];
	c->Circle.n[1] = yyvsp[-1].v[1];
	c->Circle.n[2] = yyvsp[-1].v[2];
	End_Curve(c);
	Tree_Add(THEM->Curves, &c);
	Curve *rc = CreateReversedCurve(THEM, c);
	rc->Circle.n[0] = yyvsp[-1].v[0];
	rc->Circle.n[1] = yyvsp[-1].v[1];
	rc->Circle.n[2] = yyvsp[-1].v[2];
	End_Curve(rc);
	List_Delete(temp);
      }
      List_Delete(yyvsp[-3].l);
      yyval.s.Type = MSH_SEGM_CIRC;
      yyval.s.Num = num;
    ;}
    break;

  case 125:
#line 1283 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
	List_Delete(temp);
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_SEGM_ELLI;
      yyval.s.Num = num;
    ;}
    break;

  case 126:
#line 1301 "Gmsh.y"
    {
      int num = (int)yyvsp[-6].d;
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-3].l);
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
	c->Circle.n[0] = yyvsp[-1].v[0];
	c->Circle.n[1] = yyvsp[-1].v[1];
	c->Circle.n[2] = yyvsp[-1].v[2];
	End_Curve(c);
	Tree_Add(THEM->Curves, &c);
	Curve *rc = CreateReversedCurve(THEM, c);
	rc->Circle.n[0] = yyvsp[-1].v[0];
	rc->Circle.n[1] = yyvsp[-1].v[1];
	rc->Circle.n[2] = yyvsp[-1].v[2];
	End_Curve(c);
	List_Delete(temp);
      }
      List_Delete(yyvsp[-3].l);
      yyval.s.Type = MSH_SEGM_ELLI;
      yyval.s.Num = num;
    ;}
    break;

  case 127:
#line 1328 "Gmsh.y"
    {
      int num = (int)yyvsp[-14].d;
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	Curve *c = Create_Curve(num, MSH_SEGM_PARAMETRIC, 2, NULL, NULL,
				-1, -1, yyvsp[-10].d, yyvsp[-8].d);
	strcpy(c->functu, yyvsp[-6].c);
	strcpy(c->functv, yyvsp[-4].c);
	strcpy(c->functw, yyvsp[-2].c);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
      }
      Free(yyvsp[-6].c); Free(yyvsp[-4].c); Free(yyvsp[-2].c);
      yyval.s.Type = MSH_SEGM_PARAMETRIC;
      yyval.s.Num = num;
    ;}
    break;

  case 128:
#line 1347 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(List_Nbr(yyvsp[-1].l) < 4){
	yymsg(GERROR, "Too few control points for BSpline %d (%d < 4)", num,
	      List_Nbr(yyvsp[-1].l));
      }
      else{
	if(FindCurve(num, THEM)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	  Curve *c = Create_Curve(num, MSH_SEGM_BSPLN, 2, temp, NULL,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(THEM, c);
	  List_Delete(temp);
	}
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_SEGM_BSPLN;
      yyval.s.Num = num;
    ;}
    break;

  case 129:
#line 1371 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(List_Nbr(yyvsp[-1].l) < 4){
	yymsg(GERROR, "Too few control points for Bezier curve %d (%d < 4)", num,
	      List_Nbr(yyvsp[-1].l));
      }
      else{
	if(FindCurve(num, THEM)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	  Curve *c = Create_Curve(num, MSH_SEGM_BEZIER, 2, temp, NULL,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(THEM, c);
	  List_Delete(temp);
	}
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_SEGM_BEZIER;
      yyval.s.Num = num;
    ;}
    break;

  case 130:
#line 1395 "Gmsh.y"
    {
      int num = (int)yyvsp[-8].d;
      if(List_Nbr(yyvsp[-5].l) + (int)yyvsp[-1].d + 1 != List_Nbr(yyvsp[-3].l)){
	yymsg(GERROR, "Wrong definition of Nurbs Curve %d: "
	      "got %d knots, need N + D + 1 = %d + %d + 1 = %d",
	      (int)yyvsp[-8].d, List_Nbr(yyvsp[-3].l), List_Nbr(yyvsp[-5].l), (int)yyvsp[-1].d, List_Nbr(yyvsp[-5].l) + (int)yyvsp[-1].d + 1);
      }
      else{
	if(FindCurve(num, THEM)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt(yyvsp[-5].l);
	  Curve *c = Create_Curve(num, MSH_SEGM_NURBS, (int)yyvsp[-1].d, temp, yyvsp[-3].l,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(THEM, c);
	  List_Delete(temp);
	}
      }
      List_Delete(yyvsp[-5].l);
      List_Delete(yyvsp[-3].l);
      yyval.s.Type = MSH_SEGM_NURBS;
      yyval.s.Num = num;
    ;}
    break;

  case 131:
#line 1421 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(FindEdgeLoop(num, THEM)){
	yymsg(GERROR, "Line loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	sortEdgesInLoop(num, temp);
	EdgeLoop *l = Create_EdgeLoop(num, temp);
	Tree_Add(THEM->EdgeLoops, &l);
	List_Delete(temp);
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_SEGM_LOOP;
      yyval.s.Num = num;
    ;}
    break;

  case 132:
#line 1438 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-9].l); i++){
	double p;
      	List_Read(yyvsp[-9].l, i, &p);
	Curve *c = FindCurve((int)p, THEM);
        if(!c)
	  yymsg(WARNING, "Unknown curve %d", (int)p);
	else{
	  Attractor *a = Create_Attractor(List_Nbr(THEM->Metric->Attractors)+1,
					  yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d, NULL, c, NULL);
	  List_Add(THEM->Metric->Attractors, &a);
        }
      }
      // dummy values
      yyval.s.Type = 0;
      yyval.s.Num = 0;
    ;}
    break;

  case 133:
#line 1456 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE, THEM)){
	yymsg(GERROR, "Physical line %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_PHYSICAL_LINE;
      yyval.s.Num = num;
    ;}
    break;

  case 134:
#line 1475 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(FindSurface(num, THEM)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_PLAN);
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	setSurfaceGeneratrices(s, temp);
	List_Delete(temp);
	s->Support = s;
	End_Surface(s);
	Tree_Add(THEM->Surfaces, &s);
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_SURF_PLAN;
      yyval.s.Num = num;
    ;}
    break;

  case 135:
#line 1494 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d, type = 0;
      if(FindSurface(num, THEM)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	double d;
	List_Read(yyvsp[-1].l, 0, &d);
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
	  List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	  setSurfaceGeneratrices(s, temp);
	  List_Delete(temp);
	  s->Support = s;
	  End_Surface(s);
	  Tree_Add(THEM->Surfaces, &s);
	}
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = type;
      yyval.s.Num = num;
    ;}
    break;

  case 136:
#line 1533 "Gmsh.y"
    {
      int num = (int)yyvsp[-8].d;
      Surface *support = FindSurface((int)yyvsp[-4].d, THEM);
      if(!support){
	yymsg(GERROR, "Unknown support surface %d", (int)yyvsp[-4].d);
      }
      else{
	if(FindSurface(num, THEM)){
	  yymsg(GERROR, "Surface %d already exists", num);
	}
	else{
	  Surface *s = Create_Surface(num, MSH_SURF_TRIMMED);
	  List_T *temp = ListOfDouble2ListOfInt(yyvsp[-2].l);
	  setSurfaceGeneratrices(s, temp);
	  List_Delete(temp);
	  s->Support = support;
	  End_Surface(s);
	  Tree_Add(THEM->Surfaces, &s);
	}
      }
      List_Delete(yyvsp[-2].l);
      yyval.s.Type = MSH_SURF_TRIMMED;
      yyval.s.Num = num;
    ;}
    break;

  case 137:
#line 1560 "Gmsh.y"
    {
      int num = (int)yyvsp[-16].d;
      if(FindSurface(num, THEM)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	CreateNurbsSurface(num, (int)yyvsp[-4].d, (int)yyvsp[-2].d, yyvsp[-13].l, yyvsp[-10].l, yyvsp[-8].l);
      }
      for(int i = 0; i < List_Nbr(yyvsp[-13].l); i++)
	List_Delete((List_T*)List_Pointer(yyvsp[-13].l, i));
      List_Delete(yyvsp[-13].l);
      List_Delete(yyvsp[-10].l);
      List_Delete(yyvsp[-8].l);
      yyval.s.Type = MSH_SURF_NURBS;
      yyval.s.Num = num;
    ;}
    break;

  case 138:
#line 1579 "Gmsh.y"
    {
      int num = (int)yyvsp[-16].d;
      if(FindSurface(num, THEM)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	CreateNurbsSurfaceSupport(num, (int)yyvsp[-4].d, (int)yyvsp[-2].d, yyvsp[-13].l, yyvsp[-10].l, yyvsp[-8].l);
      }
      for(int i = 0; i < List_Nbr(yyvsp[-13].l); i++)
	List_Delete((List_T*)List_Pointer(yyvsp[-13].l, i));
      List_Delete(yyvsp[-13].l);
      List_Delete(yyvsp[-10].l);
      List_Delete(yyvsp[-8].l);
      yyval.s.Type = MSH_SURF_NURBS;
      yyval.s.Num = num;
    ;}
    break;

  case 139:
#line 1596 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(FindSurfaceLoop(num, THEM)){
	yymsg(GERROR, "Surface loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	SurfaceLoop *l = Create_SurfaceLoop(num, temp);
	Tree_Add(THEM->SurfaceLoops, &l);
	List_Delete(temp);
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_SURF_LOOP;
      yyval.s.Num = num;
    ;}
    break;

  case 140:
#line 1612 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE, THEM)){
	yymsg(GERROR, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_PHYSICAL_SURFACE;
      yyval.s.Num = num;
    ;}
    break;

  case 141:
#line 1632 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(FindVolume(num, THEM)){
	yymsg(GERROR, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(THEM->Volumes, &v);
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_VOLUME;
      yyval.s.Num = num;
    ;}
    break;

  case 142:
#line 1649 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(FindVolume(num, THEM)){
	yymsg(GERROR, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(THEM->Volumes, &v);
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_VOLUME;
      yyval.s.Num = num;
    ;}
    break;

  case 143:
#line 1666 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME, THEM)){
	yymsg(GERROR, "Physical volume %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt(yyvsp[-1].l);
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete(yyvsp[-1].l);
      yyval.s.Type = MSH_PHYSICAL_VOLUME;
      yyval.s.Num = num;
    ;}
    break;

  case 144:
#line 1687 "Gmsh.y"
    {
      TranslateShapes(yyvsp[-3].v[0], yyvsp[-3].v[1], yyvsp[-3].v[2], yyvsp[-1].l, 1);
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 145:
#line 1692 "Gmsh.y"
    {
      RotateShapes(yyvsp[-8].v[0], yyvsp[-8].v[1], yyvsp[-8].v[2], yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2], yyvsp[-4].d, yyvsp[-1].l, 1);
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 146:
#line 1697 "Gmsh.y"
    {
      SymmetryShapes(yyvsp[-3].v[0], yyvsp[-3].v[1], yyvsp[-3].v[2], yyvsp[-3].v[3], yyvsp[-1].l, 1);
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 147:
#line 1702 "Gmsh.y"
    {
      DilatShapes(yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2], yyvsp[-4].d, yyvsp[-1].l, 1);
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 148:
#line 1709 "Gmsh.y"
    { yyval.l = yyvsp[0].l; ;}
    break;

  case 149:
#line 1710 "Gmsh.y"
    { yyval.l = yyvsp[0].l; ;}
    break;

  case 150:
#line 1711 "Gmsh.y"
    { yyval.l = yyvsp[0].l; ;}
    break;

  case 151:
#line 1716 "Gmsh.y"
    {
      yyval.l = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 152:
#line 1720 "Gmsh.y"
    {
      List_Add(yyval.l, &yyvsp[0].s);
    ;}
    break;

  case 153:
#line 1724 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-2].l); i++){
	double d;
	List_Read(yyvsp[-2].l, i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Vertex *v = FindPoint(TheShape.Num, THEM);
	if(!v)
	  yymsg(WARNING, "Unknown point %d", TheShape.Num);
	else{
	  TheShape.Type = MSH_POINT;
	  List_Add(yyval.l, &TheShape);
	}
      }
    ;}
    break;

  case 154:
#line 1740 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-2].l); i++){
	double d;
	List_Read(yyvsp[-2].l, i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Curve *c = FindCurve(TheShape.Num, THEM);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	else{
	  TheShape.Type = c->Typ;
	  List_Add(yyval.l, &TheShape);
	}
      }
    ;}
    break;

  case 155:
#line 1756 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-2].l); i++){
	double d;
	List_Read(yyvsp[-2].l, i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Surface *s = FindSurface(TheShape.Num, THEM);
	if(!s)
	  yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	else{
	  TheShape.Type = s->Typ;
	  List_Add(yyval.l, &TheShape);
	}
      }
    ;}
    break;

  case 156:
#line 1772 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-2].l); i++){
	double d;
	List_Read(yyvsp[-2].l, i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Volume *v = FindVolume(TheShape.Num, THEM);
	if(!v)
	  yymsg(WARNING, "Unknown volume %d", TheShape.Num);
	else{
	  TheShape.Type = v->Typ;
	  List_Add(yyval.l, &TheShape);
	}
      }
    ;}
    break;

  case 157:
#line 1793 "Gmsh.y"
    {
      yyval.l = List_Create(3, 3, sizeof(Shape));
      for(int i = 0; i < List_Nbr(yyvsp[-1].l); i++){
	Shape TheShape;
	List_Read(yyvsp[-1].l, i, &TheShape);
	int j;
	CopyShape(TheShape.Type, TheShape.Num, &j);
	TheShape.Num = j;
	List_Add(yyval.l, &TheShape);
      }
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 158:
#line 1807 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-4].c, "View")) AliasView((int)yyvsp[-2].d, 0);
      Free(yyvsp[-4].c);
      yyval.l = NULL;
    ;}
    break;

  case 159:
#line 1813 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-4].c, "View")) AliasView((int)yyvsp[-2].d, 0);
      Free(yyvsp[-4].c);
      yyval.l = NULL;
    ;}
    break;

  case 160:
#line 1819 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-4].c, "View")) AliasView((int)yyvsp[-2].d, 1);
      Free(yyvsp[-4].c);
      yyval.l = NULL;
    ;}
    break;

  case 161:
#line 1831 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-1].l); i++){
	Shape TheShape;
	List_Read(yyvsp[-1].l, i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 162:
#line 1840 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-4].c, "View")){
	RemoveViewByIndex((int)yyvsp[-2].d);
      }
      else{
	yymsg(GERROR, "Unknown command 'Delete %s'", yyvsp[-4].c);
      }
      Free(yyvsp[-4].c);
    ;}
    break;

  case 163:
#line 1850 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-1].c, "Meshes") || !strcmp(yyvsp[-1].c, "All")){
	Init_Mesh(THEM);
      }
      else if(!strcmp(yyvsp[-1].c, "Physicals")){
	List_Action(THEM->PhysicalGroups, Free_PhysicalGroup);
	List_Reset(THEM->PhysicalGroups);
      }
      else{
	yymsg(GERROR, "Unknown command 'Delete %s'", yyvsp[-1].c);
      }
      Free(yyvsp[-1].c);
    ;}
    break;

  case 164:
#line 1864 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-2].c, "Empty") && !strcmp(yyvsp[-1].c, "Views")){
	for(int i = List_Nbr(CTX.post.list) - 1; i >= 0; i--){
	  Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, i);
	  if(v->empty())
	    RemoveViewByIndex(i);
	}
      }
      else{
	yymsg(GERROR, "Unknown command 'Delete %s %s'", yyvsp[-2].c, yyvsp[-1].c);
      }
      Free(yyvsp[-2].c); Free(yyvsp[-1].c);
    ;}
    break;

  case 165:
#line 1883 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-1].l); i++){
	Shape TheShape;
	List_Read(yyvsp[-1].l, i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, yyvsp[-3].u);
      }
      List_Delete(yyvsp[-1].l);      
    ;}
    break;

  case 166:
#line 1897 "Gmsh.y"
    {
      int m = (CTX.visibility_mode == 2) ? VIS_MESH : 
	((CTX.visibility_mode == 1) ? VIS_GEOM : VIS_GEOM|VIS_MESH);
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber(yyvsp[-1].c, i, m);
      Free(yyvsp[-1].c);
    ;}
    break;

  case 167:
#line 1905 "Gmsh.y"
    {
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber(yyvsp[-1].c, i, 0);
      Free(yyvsp[-1].c);
    ;}
    break;

  case 168:
#line 1911 "Gmsh.y"
    {
      int m = (CTX.visibility_mode == 2) ? VIS_MESH :
	((CTX.visibility_mode == 1) ? VIS_GEOM : VIS_GEOM|VIS_MESH);
      for(int i = 0; i < List_Nbr(yyvsp[-1].l); i++){
	Shape TheShape;
	List_Read(yyvsp[-1].l, i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, m);
      }
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 169:
#line 1922 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-1].l); i++){
	Shape TheShape;
	List_Read(yyvsp[-1].l, i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 170:
#line 1936 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-2].c, "Include")){
	char tmpstring[1024];
	FixRelativePath(yyvsp[-1].c, tmpstring);
	// Warning: we *don't* close included files (to allow user
	// functions in these files). If you need to include many many
	// files and don't have functions in the files, use "Merge"
	// instead: some OSes limit the number of files a process can
	// open simultaneously. The right solution would be of course
	// to modify FunctionManager to reopen the files instead of
	// using the FILE pointer, but hey, I'm lazy...
	ParseFile(tmpstring, 0, 0, 1);
      }
      else if(!strcmp(yyvsp[-2].c, "Print")){
#if defined(HAVE_FLTK)
	if(!CTX.batch){
	  char tmpstring[1024];
	  FixRelativePath(yyvsp[-1].c, tmpstring);
	  CreateOutputFile(tmpstring, CTX.print.format);
	}
#endif
      }
      else if(!strcmp(yyvsp[-2].c, "Save")){
#if defined(HAVE_FLTK)
	char tmpstring[1024];
	FixRelativePath(yyvsp[-1].c, tmpstring);
	CreateOutputFile(tmpstring, CTX.mesh.format);
#endif
      }
      else if(!strcmp(yyvsp[-2].c, "Merge") || !strcmp(yyvsp[-2].c, "MergeWithBoundingBox")){
	// MergeWithBoundingBox is deprecated
	char tmpstring[1024];
	FixRelativePath(yyvsp[-1].c, tmpstring);
	MergeProblem(tmpstring, 1);
      }
      else if(!strcmp(yyvsp[-2].c, "System")){
	SystemCall(yyvsp[-1].c);
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", yyvsp[-2].c);
      }
      Free(yyvsp[-2].c); Free(yyvsp[-1].c);
    ;}
    break;

  case 171:
#line 1980 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-6].c, "Save") && !strcmp(yyvsp[-5].c, "View")){
	Post_View **vv = (Post_View **)List_Pointer_Test(CTX.post.list, (int)yyvsp[-3].d);
	if(vv){
	  char tmpstring[1024];
	  FixRelativePath(yyvsp[-1].c, tmpstring);
	  WriteView(*vv, tmpstring, CTX.post.file_format, 0);
	}
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", yyvsp[-6].c);
      }
      Free(yyvsp[-6].c); Free(yyvsp[-5].c); Free(yyvsp[-1].c);
    ;}
    break;

  case 172:
#line 1995 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-2].c, "Sleep")){
	long sleep_time = GetTime();
	while(1){
	  if(GetTime() - sleep_time > (long)(yyvsp[-1].d*1.e6)) break;
	}
      }
      else if(!strcmp(yyvsp[-2].c, "Mesh")){
	yymsg(GERROR, "Mesh directives are not (yet) allowed in scripts");
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", yyvsp[-2].c);
      }
      Free(yyvsp[-2].c);
    ;}
    break;

  case 173:
#line 2011 "Gmsh.y"
    {
       try {
	 GMSH_PluginManager::instance()->action(yyvsp[-4].c, yyvsp[-1].c, 0);
       }
       catch(...) {
	 yymsg(GERROR, "Unknown action '%s' or plugin '%s'", yyvsp[-1].c, yyvsp[-4].c);
       }
       Free(yyvsp[-4].c); Free(yyvsp[-1].c);
     ;}
    break;

  case 174:
#line 2021 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-1].c, "ElementsFromAllViews"))
	CombineViews(0, 1, CTX.post.combine_remove_orig);
      else if(!strcmp(yyvsp[-1].c, "ElementsFromVisibleViews"))
	CombineViews(0, 0, CTX.post.combine_remove_orig);
      else if(!strcmp(yyvsp[-1].c, "ElementsByViewName"))
	CombineViews(0, 2, CTX.post.combine_remove_orig);
      else if(!strcmp(yyvsp[-1].c, "TimeStepsFromAllViews"))
	CombineViews(1, 1, CTX.post.combine_remove_orig);
      else if(!strcmp(yyvsp[-1].c, "TimeStepsFromVisibleViews"))
	CombineViews(1, 0, CTX.post.combine_remove_orig);
      else if(!strcmp(yyvsp[-1].c, "TimeStepsByViewName"))
	CombineViews(1, 2, CTX.post.combine_remove_orig);
      else if(!strcmp(yyvsp[-1].c, "Views"))
	CombineViews(0, 1, CTX.post.combine_remove_orig);
      else if(!strcmp(yyvsp[-1].c, "TimeSteps"))
	CombineViews(1, 2, CTX.post.combine_remove_orig);
      else
	yymsg(GERROR, "Unknown 'Combine' command");
      Free(yyvsp[-1].c);
    ;}
    break;

  case 175:
#line 2043 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 176:
#line 2047 "Gmsh.y"
    {
      SetBoundingBox();
    ;}
    break;

  case 177:
#line 2051 "Gmsh.y"
    {
      SetBoundingBox(yyvsp[-12].d, yyvsp[-10].d, yyvsp[-8].d, yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 178:
#line 2055 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      if(!CTX.batch) // we're in interactive mode
	Draw();
#endif
    ;}
    break;

  case 179:
#line 2068 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = yyvsp[-3].d;
      LoopControlVariablesTab[ImbricatedLoop][1] = yyvsp[-1].d;
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if(yyvsp[-3].d > yyvsp[-1].d) skip_until("For", "EndFor");
    ;}
    break;

  case 180:
#line 2083 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = yyvsp[-5].d;
      LoopControlVariablesTab[ImbricatedLoop][1] = yyvsp[-3].d;
      LoopControlVariablesTab[ImbricatedLoop][2] = yyvsp[-1].d;
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if((yyvsp[-1].d > 0. && yyvsp[-5].d > yyvsp[-3].d) || (yyvsp[-1].d < 0. && yyvsp[-5].d < yyvsp[-3].d))
	skip_until("For", "EndFor");
    ;}
    break;

  case 181:
#line 2099 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = yyvsp[-3].d;
      LoopControlVariablesTab[ImbricatedLoop][1] = yyvsp[-1].d;
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = yyvsp[-6].c;
      Symbol TheSymbol;      
      TheSymbol.Name = yyvsp[-6].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(1, 1, sizeof(double));
	List_Put(TheSymbol.val, 0, &yyvsp[-3].d);
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	List_Write(pSymbol->val, 0, &yyvsp[-3].d);
      }
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if(yyvsp[-3].d > yyvsp[-1].d) skip_until("For", "EndFor");
    ;}
    break;

  case 182:
#line 2125 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = yyvsp[-5].d;
      LoopControlVariablesTab[ImbricatedLoop][1] = yyvsp[-3].d;
      LoopControlVariablesTab[ImbricatedLoop][2] = yyvsp[-1].d;
      LoopControlVariablesNameTab[ImbricatedLoop] = yyvsp[-8].c;
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-8].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(1, 1, sizeof(double));
	List_Put(TheSymbol.val, 0, &yyvsp[-5].d);
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	List_Write(pSymbol->val, 0, &yyvsp[-5].d);
      }
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if((yyvsp[-1].d > 0. && yyvsp[-5].d > yyvsp[-3].d) || (yyvsp[-1].d < 0. && yyvsp[-5].d < yyvsp[-3].d))
	skip_until("For", "EndFor");
    ;}
    break;

  case 183:
#line 2152 "Gmsh.y"
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

  case 184:
#line 2184 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction(yyvsp[0].c, yyin, yyname, yylineno))
	yymsg(GERROR, "Redefinition of function %s", yyvsp[0].c);
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 185:
#line 2191 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin, yyname, yylineno))
	yymsg(GERROR, "Error while exiting function");
    ;}
    break;

  case 186:
#line 2196 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction(yyvsp[-1].c, &yyin, yyname, yylineno))
	yymsg(GERROR, "Unknown function %s", yyvsp[-1].c);
      //FIXME: wee leak $2
    ;}
    break;

  case 187:
#line 2202 "Gmsh.y"
    {
      if(!yyvsp[-1].d) skip_until("If", "EndIf");
    ;}
    break;

  case 188:
#line 2206 "Gmsh.y"
    {
    ;}
    break;

  case 189:
#line 2217 "Gmsh.y"
    {
      Curve *pc, *prc;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudePoint(TRANSLATE, (int)yyvsp[-4].d, yyvsp[-2].v[0], yyvsp[-2].v[1], yyvsp[-2].v[2],
					  0., 0., 0., 0., 0., 0., 0.,
					  &pc, &prc, 1, NULL);
      TheShape.Type = MSH_POINT;
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(pc){
	TheShape.Num = pc->Num;
	TheShape.Type = pc->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 190:
#line 2233 "Gmsh.y"
    {
      Curve *pc, *prc;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudePoint(ROTATE, (int)yyvsp[-8].d, 0., 0., 0.,
					  yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2], yyvsp[-4].v[0], yyvsp[-4].v[1], yyvsp[-4].v[2], yyvsp[-2].d,
					  &pc, &prc, 1, NULL);
      TheShape.Type = MSH_POINT;
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(pc){
	TheShape.Num = pc->Num;
	TheShape.Type = pc->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 191:
#line 2249 "Gmsh.y"
    {
      Curve *pc, *prc;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudePoint(TRANSLATE_ROTATE, (int)yyvsp[-10].d, yyvsp[-8].v[0], yyvsp[-8].v[1], yyvsp[-8].v[2],
					  yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2], yyvsp[-4].v[0], yyvsp[-4].v[1], yyvsp[-4].v[2], yyvsp[-2].d,
					  &pc, &prc, 1, NULL);
      TheShape.Type = MSH_POINT;
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(pc){
	TheShape.Num = pc->Num;
	TheShape.Type = pc->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 192:
#line 2265 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 193:
#line 2270 "Gmsh.y"
    {
      Curve *pc, *prc;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudePoint(TRANSLATE, (int)yyvsp[-8].d, yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2],
					  0., 0., 0., 0., 0., 0., 0.,
					  &pc, &prc, 1, &extr);
      TheShape.Type = MSH_POINT;
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(pc){
	TheShape.Num = pc->Num;
	TheShape.Type = pc->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 194:
#line 2286 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 195:
#line 2291 "Gmsh.y"
    {
      Curve *pc, *prc;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudePoint(ROTATE, (int)yyvsp[-12].d, 0., 0., 0.,
					  yyvsp[-10].v[0], yyvsp[-10].v[1], yyvsp[-10].v[2], yyvsp[-8].v[0], yyvsp[-8].v[1], yyvsp[-8].v[2], yyvsp[-6].d,
					  &pc, &prc, 1, &extr);
      TheShape.Type = MSH_POINT;
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(pc){
	TheShape.Num = pc->Num;
	TheShape.Type = pc->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 196:
#line 2307 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 197:
#line 2312 "Gmsh.y"
    {
      Curve *pc, *prc;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudePoint(TRANSLATE_ROTATE, (int)yyvsp[-14].d, yyvsp[-12].v[0], yyvsp[-12].v[1], yyvsp[-12].v[2],
					  yyvsp[-10].v[0], yyvsp[-10].v[1], yyvsp[-10].v[2], yyvsp[-8].v[0], yyvsp[-8].v[1], yyvsp[-8].v[2], yyvsp[-6].d,
					  &pc, &prc, 1, &extr);
      TheShape.Type = MSH_POINT;
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(pc){
	TheShape.Num = pc->Num;
	TheShape.Type = pc->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 198:
#line 2330 "Gmsh.y"
    {
      Surface *ps;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeCurve(TRANSLATE, (int)yyvsp[-4].d, yyvsp[-2].v[0], yyvsp[-2].v[1], yyvsp[-2].v[2],
					  0., 0., 0., 0., 0., 0., 0., 
					  &ps, 1, NULL);
      Curve *c = FindCurve(TheShape.Num, THEM);
      if(!c){
	//yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(ps){
	TheShape.Num = ps->Num;
	TheShape.Type = ps->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 199:
#line 2353 "Gmsh.y"
    {
      Surface *ps;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeCurve(ROTATE, (int)yyvsp[-8].d, 0., 0., 0.,
					  yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2], yyvsp[-4].v[0], yyvsp[-4].v[1], yyvsp[-4].v[2], yyvsp[-2].d, 
					  &ps, 1, NULL);
      Curve *c = FindCurve(TheShape.Num, THEM);
      if(!c){
	//yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(ps){
	TheShape.Num = ps->Num;
	TheShape.Type = ps->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 200:
#line 2376 "Gmsh.y"
    {
      Surface *ps;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeCurve(TRANSLATE_ROTATE, (int)yyvsp[-10].d, yyvsp[-8].v[0], yyvsp[-8].v[1], yyvsp[-8].v[2],
					  yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2], yyvsp[-4].v[0], yyvsp[-4].v[1], yyvsp[-4].v[2], yyvsp[-2].d, 
					  &ps, 1, NULL);
      Curve *c = FindCurve(TheShape.Num, THEM);
      if(!c){
	//yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(ps){
	TheShape.Num = ps->Num;
	TheShape.Type = ps->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 201:
#line 2399 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 202:
#line 2404 "Gmsh.y"
    {
      Surface *ps;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeCurve(TRANSLATE, (int)yyvsp[-8].d, yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2],
					  0., 0., 0., 0., 0., 0., 0., 
					  &ps, 1, &extr);
      Curve *c = FindCurve(TheShape.Num, THEM);
      if(!c){
	//yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(ps){
	TheShape.Num = ps->Num;
	TheShape.Type = ps->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 203:
#line 2427 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 204:
#line 2432 "Gmsh.y"
    {
      Surface *ps;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeCurve(ROTATE, (int)yyvsp[-12].d, 0., 0., 0.,
					  yyvsp[-10].v[0], yyvsp[-10].v[1], yyvsp[-10].v[2], yyvsp[-8].v[0], yyvsp[-8].v[1], yyvsp[-8].v[2], yyvsp[-6].d, 
					  &ps, 1, &extr);
      Curve *c = FindCurve(TheShape.Num, THEM);
      if(!c){
	//yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(ps){
	TheShape.Num = ps->Num;
	TheShape.Type = ps->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 205:
#line 2455 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 206:
#line 2460 "Gmsh.y"
    {
      Surface *ps;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeCurve(TRANSLATE_ROTATE, (int)yyvsp[-14].d, yyvsp[-12].v[0], yyvsp[-12].v[1], yyvsp[-12].v[2],
					  yyvsp[-10].v[0], yyvsp[-10].v[1], yyvsp[-10].v[2], yyvsp[-8].v[0], yyvsp[-8].v[1], yyvsp[-8].v[2], yyvsp[-6].d, 
					  &ps, 1, &extr);
      Curve *c = FindCurve(TheShape.Num, THEM);
      if(!c){
	//yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(ps){
	TheShape.Num = ps->Num;
	TheShape.Type = ps->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 207:
#line 2486 "Gmsh.y"
    {
      Volume *pv;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(TRANSLATE, (int)yyvsp[-4].d, yyvsp[-2].v[0], yyvsp[-2].v[1], yyvsp[-2].v[2],
					    0., 0., 0., 0., 0., 0., 0., 
					    &pv, NULL);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(pv){
	TheShape.Num = pv->Num;
	TheShape.Type = pv->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 208:
#line 2509 "Gmsh.y"
    {
      Volume *pv;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(ROTATE, (int)yyvsp[-8].d, 0., 0., 0.,
					    yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2], yyvsp[-4].v[0], yyvsp[-4].v[1], yyvsp[-4].v[2], yyvsp[-2].d,
					    &pv, NULL);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(pv){
	TheShape.Num = pv->Num;
	TheShape.Type = pv->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 209:
#line 2532 "Gmsh.y"
    {
      Volume *pv;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(TRANSLATE_ROTATE, (int)yyvsp[-10].d, yyvsp[-8].v[0], yyvsp[-8].v[1], yyvsp[-8].v[2],
					    yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2], yyvsp[-4].v[0], yyvsp[-4].v[1], yyvsp[-4].v[2], yyvsp[-2].d,
					    &pv, NULL);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(pv){
	TheShape.Num = pv->Num;
	TheShape.Type = pv->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 210:
#line 2555 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 211:
#line 2560 "Gmsh.y"
    {
      Volume *pv;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(TRANSLATE, (int)yyvsp[-8].d, yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2],
					    0., 0., 0., 0., 0., 0., 0., 
					    &pv, &extr);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(pv){
	TheShape.Num = pv->Num;
	TheShape.Type = pv->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 212:
#line 2583 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 213:
#line 2589 "Gmsh.y"
    {
      Volume *pv;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(ROTATE, (int)yyvsp[-12].d, 0., 0., 0.,
					    yyvsp[-10].v[0], yyvsp[-10].v[1], yyvsp[-10].v[2], yyvsp[-8].v[0], yyvsp[-8].v[1], yyvsp[-8].v[2], yyvsp[-6].d, 
					    &pv, &extr);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(pv){
	TheShape.Num = pv->Num;
	TheShape.Type = pv->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 214:
#line 2612 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 215:
#line 2618 "Gmsh.y"
    {
      Volume *pv;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(TRANSLATE_ROTATE, (int)yyvsp[-14].d, yyvsp[-12].v[0], yyvsp[-12].v[1], yyvsp[-12].v[2],
					    yyvsp[-10].v[0], yyvsp[-10].v[1], yyvsp[-10].v[2], yyvsp[-8].v[0], yyvsp[-8].v[1], yyvsp[-8].v[2], yyvsp[-6].d,
					    &pv, &extr);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      yyval.l = List_Create(2, 1, sizeof(Shape));
      List_Add(yyval.l, &TheShape);
      if(pv){
	TheShape.Num = pv->Num;
	TheShape.Type = pv->Typ;
	List_Add(yyval.l, &TheShape);
      }
    ;}
    break;

  case 216:
#line 2644 "Gmsh.y"
    {
    ;}
    break;

  case 217:
#line 2647 "Gmsh.y"
    {
    ;}
    break;

  case 218:
#line 2653 "Gmsh.y"
    {
      double d;
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr(yyvsp[-6].l);
      if(List_Nbr(yyvsp[-6].l) == List_Nbr(yyvsp[-4].l) && List_Nbr(yyvsp[-6].l) == List_Nbr(yyvsp[-2].l)){
	extr.mesh.NbElmLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.ZonLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.hLayer = (double*)Malloc(extr.mesh.NbLayer*sizeof(double));
	for(int i = 0; i < List_Nbr(yyvsp[-6].l); i++){
	  List_Read(yyvsp[-6].l, i, &d);
	  extr.mesh.NbElmLayer[i] = (d>0)?(int)d:1;
	  List_Read(yyvsp[-4].l, i, &d);
	  extr.mesh.ZonLayer[i] = (int)d;
	  List_Read(yyvsp[-2].l, i, &d);
	  extr.mesh.hLayer[i] = d;
	}
      }
      else{
	yymsg(GERROR, "Wrong layer definition {%d, %d, %d}", 
	      List_Nbr(yyvsp[-6].l), List_Nbr(yyvsp[-4].l), List_Nbr(yyvsp[-2].l));
      }
      List_Delete(yyvsp[-6].l);
      List_Delete(yyvsp[-4].l);
      List_Delete(yyvsp[-2].l);
    ;}
    break;

  case 219:
#line 2679 "Gmsh.y"
    {
      double d;
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr(yyvsp[-4].l);
      if(List_Nbr(yyvsp[-4].l) == List_Nbr(yyvsp[-2].l)){
	extr.mesh.NbElmLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.ZonLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.hLayer = (double*)Malloc(extr.mesh.NbLayer*sizeof(double));
	for(int i = 0; i < List_Nbr(yyvsp[-4].l); i++){
	  List_Read(yyvsp[-4].l, i, &d);
	  extr.mesh.NbElmLayer[i] = (d>0)?(int)d:1;
	  extr.mesh.ZonLayer[i] = 0;
	  List_Read(yyvsp[-2].l, i, &d);
	  extr.mesh.hLayer[i] = d;
	}
      }
      else{
	yymsg(GERROR, "Wrong layer definition {%d, %d}", 
	      List_Nbr(yyvsp[-4].l), List_Nbr(yyvsp[-2].l));
      }
      List_Delete(yyvsp[-4].l);
      List_Delete(yyvsp[-2].l);
    ;}
    break;

  case 220:
#line 2703 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 221:
#line 2712 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-3].l); i++){
	double d;
	List_Read(yyvsp[-3].l, i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j, THEM);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = (yyvsp[-1].d>2)?(int)yyvsp[-1].d:2;
	  c->ipar[1] = sign(d);
	  c->dpar[0] = 1.0;
	}
      }
      List_Delete(yyvsp[-3].l);
    ;}
    break;

  case 222:
#line 2730 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-6].l); i++){
	double d;
	List_Read(yyvsp[-6].l, i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j, THEM);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = (yyvsp[-4].d>2)?(int)yyvsp[-4].d:2;
	  c->ipar[1] = sign(d); /* Progresion : code 1 ou -1 */
	  c->dpar[0] = fabs(yyvsp[-1].d);
	}
      }
      List_Delete(yyvsp[-6].l);
    ;}
    break;

  case 223:
#line 2748 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-6].l); i++){
	double d;
	List_Read(yyvsp[-6].l, i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j, THEM);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = (yyvsp[-4].d>2)?(int)yyvsp[-4].d:2;
	  c->ipar[1] = 2*sign(d); /* Bump : code 2 ou -2 */
	  c->dpar[0] = fabs(yyvsp[-1].d);
	}
      }
      List_Delete(yyvsp[-6].l);
    ;}
    break;

  case 224:
#line 2766 "Gmsh.y"
    {
      Surface *s = FindSurface((int)yyvsp[-4].d, THEM);
      if(!s)
	yymsg(WARNING, "Unknown surface %d", (int)yyvsp[-4].d);
      else{
	s->Method = TRANSFINI;
	s->Recombine_Dir = -1;
	int k = List_Nbr(yyvsp[-1].l);
	if(k != 3 && k != 4){
	  yymsg(GERROR, "Wrong definition of Transfinite Surface %d: "
		"%d points instead of 3 or 4" , (int)yyvsp[-4].d, k);
	}
	else{
	  List_Reset(s->TrsfPoints);
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read(yyvsp[-1].l, i, &d);
	    int j = (int)fabs(d);
	    Vertex *v = FindPoint(j, THEM);
	    if(!v)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(s->TrsfPoints, &v);
	  }
	}
      }
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 225:
#line 2795 "Gmsh.y"
    {
      Surface *s = FindSurface((int)yyvsp[-5].d, THEM);
      if(!s)
	yymsg(WARNING, "Unknown surface %d", (int)yyvsp[-5].d);
      else{
	s->Method = TRANSFINI;
	int k = List_Nbr(yyvsp[-2].l);
	if(k != 3 && k != 4){
	  yymsg(GERROR, "Wrong definition of Transfinite Surface %d: "
		"%d points instead of 3 or 4" , (int)yyvsp[-5].d, k);
	}
	else{
	  List_Reset(s->TrsfPoints);
	  if (!strcmp(yyvsp[-1].c,"Right"))
	    s->Recombine_Dir = 1;
	  else if (!strcmp(yyvsp[-1].c,"Left"))
	    s->Recombine_Dir = -1;
	  else
	    s->Recombine_Dir = 0;

	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read(yyvsp[-2].l, i, &d);
	    int j = (int)fabs(d);
	    Vertex *v = FindPoint(j, THEM);
	    if(!v)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(s->TrsfPoints, &v);
	  }
	}
      }
      List_Delete(yyvsp[-2].l);
    ;}
    break;

  case 226:
#line 2830 "Gmsh.y"
    {
      Surface *s = FindSurface((int)yyvsp[-4].d, THEM);
      if(!s)
	yymsg(WARNING, "Unknown surface %d", (int)yyvsp[-4].d);
      else{
        s->Method = ELLIPTIC;
        int k = List_Nbr(yyvsp[-1].l);
        if(k != 4)
	  yymsg(GERROR, "Wrong definition of Elliptic Surface %d: "
		"%d points instead of 4" , (int)yyvsp[-4].d, k);
        else{
	  List_Reset(s->TrsfPoints);
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read(yyvsp[-1].l, i, &d);
	    int j = (int)fabs(d);
	    Vertex *v = FindPoint(j, THEM);
	    if(!v)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(s->TrsfPoints, &v);
	  }
	}
      }
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 227:
#line 2857 "Gmsh.y"
    {
      Volume *v = FindVolume((int)yyvsp[-4].d, THEM);
      if(!v)
	yymsg(WARNING, "Unknown volume %d", (int)yyvsp[-4].d);
      else{
	v->Method = TRANSFINI;
	int k = List_Nbr(yyvsp[-1].l);
	if(k != 6 && k != 8)
	  yymsg(GERROR, "Wrong definition of Transfinite Volume %d: "
		"%d points instead of 6 or 8" , (int)yyvsp[-4].d, k);
	else{
	  List_Reset(v->TrsfPoints);
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read(yyvsp[-1].l, i, &d);
	    int j = (int)fabs(d);
	    Vertex *vert = FindPoint(j, THEM);
	    if(!vert)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(v->TrsfPoints, &vert);
	  }
	}
      }
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 228:
#line 2884 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-3].l); i++){
	double d;
	List_Read(yyvsp[-3].l, i, &d);
	int j = (int)d;
	Surface *s = FindSurface(j, THEM);
	if(s){
	  s->Recombine = 1;
	  s->RecombineAngle = (yyvsp[-1].d > 0 && yyvsp[-1].d < 90) ? yyvsp[-1].d : 90;
	}
      }
      List_Delete(yyvsp[-3].l);
    ;}
    break;

  case 229:
#line 2898 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-1].l); i++){
	double d;
	List_Read(yyvsp[-1].l, i, &d);
	int j = (int)d;
        Surface *s = FindSurface(j, THEM);
	if(s){
	  s->Recombine = 1;
        }
      }
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 230:
#line 2917 "Gmsh.y"
    { 
      ReplaceAllDuplicates(THEM);
    ;}
    break;

  case 231:
#line 2921 "Gmsh.y"
    { 
      IntersectAllSegmentsTogether();
    ;}
    break;

  case 232:
#line 2930 "Gmsh.y"
    {yyval.i = 1;;}
    break;

  case 233:
#line 2931 "Gmsh.y"
    {yyval.i = 0;;}
    break;

  case 234:
#line 2932 "Gmsh.y"
    {yyval.i = -1;;}
    break;

  case 235:
#line 2933 "Gmsh.y"
    {yyval.i = -1;;}
    break;

  case 236:
#line 2934 "Gmsh.y"
    {yyval.i = -1;;}
    break;

  case 237:
#line 2938 "Gmsh.y"
    { yyval.d = yyvsp[0].d;           ;}
    break;

  case 238:
#line 2939 "Gmsh.y"
    { yyval.d = yyvsp[-1].d;           ;}
    break;

  case 239:
#line 2940 "Gmsh.y"
    { yyval.d = -yyvsp[0].d;          ;}
    break;

  case 240:
#line 2941 "Gmsh.y"
    { yyval.d = yyvsp[0].d;           ;}
    break;

  case 241:
#line 2942 "Gmsh.y"
    { yyval.d = !yyvsp[0].d;          ;}
    break;

  case 242:
#line 2943 "Gmsh.y"
    { yyval.d = yyvsp[-2].d - yyvsp[0].d;      ;}
    break;

  case 243:
#line 2944 "Gmsh.y"
    { yyval.d = yyvsp[-2].d + yyvsp[0].d;      ;}
    break;

  case 244:
#line 2945 "Gmsh.y"
    { yyval.d = yyvsp[-2].d * yyvsp[0].d;      ;}
    break;

  case 245:
#line 2947 "Gmsh.y"
    { 
      if(!yyvsp[0].d)
	yymsg(GERROR, "Division by zero in '%g / %g'", yyvsp[-2].d, yyvsp[0].d);
      else
	yyval.d = yyvsp[-2].d / yyvsp[0].d;     
    ;}
    break;

  case 246:
#line 2953 "Gmsh.y"
    { yyval.d = (int)yyvsp[-2].d % (int)yyvsp[0].d;  ;}
    break;

  case 247:
#line 2954 "Gmsh.y"
    { yyval.d = pow(yyvsp[-2].d, yyvsp[0].d);  ;}
    break;

  case 248:
#line 2955 "Gmsh.y"
    { yyval.d = yyvsp[-2].d < yyvsp[0].d;      ;}
    break;

  case 249:
#line 2956 "Gmsh.y"
    { yyval.d = yyvsp[-2].d > yyvsp[0].d;      ;}
    break;

  case 250:
#line 2957 "Gmsh.y"
    { yyval.d = yyvsp[-2].d <= yyvsp[0].d;     ;}
    break;

  case 251:
#line 2958 "Gmsh.y"
    { yyval.d = yyvsp[-2].d >= yyvsp[0].d;     ;}
    break;

  case 252:
#line 2959 "Gmsh.y"
    { yyval.d = yyvsp[-2].d == yyvsp[0].d;     ;}
    break;

  case 253:
#line 2960 "Gmsh.y"
    { yyval.d = yyvsp[-2].d != yyvsp[0].d;     ;}
    break;

  case 254:
#line 2961 "Gmsh.y"
    { yyval.d = yyvsp[-2].d && yyvsp[0].d;     ;}
    break;

  case 255:
#line 2962 "Gmsh.y"
    { yyval.d = yyvsp[-2].d || yyvsp[0].d;     ;}
    break;

  case 256:
#line 2963 "Gmsh.y"
    { yyval.d = yyvsp[-4].d? yyvsp[-2].d : yyvsp[0].d;  ;}
    break;

  case 257:
#line 2964 "Gmsh.y"
    { yyval.d = exp(yyvsp[-1].d);      ;}
    break;

  case 258:
#line 2965 "Gmsh.y"
    { yyval.d = log(yyvsp[-1].d);      ;}
    break;

  case 259:
#line 2966 "Gmsh.y"
    { yyval.d = log10(yyvsp[-1].d);    ;}
    break;

  case 260:
#line 2967 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-1].d);     ;}
    break;

  case 261:
#line 2968 "Gmsh.y"
    { yyval.d = sin(yyvsp[-1].d);      ;}
    break;

  case 262:
#line 2969 "Gmsh.y"
    { yyval.d = asin(yyvsp[-1].d);     ;}
    break;

  case 263:
#line 2970 "Gmsh.y"
    { yyval.d = cos(yyvsp[-1].d);      ;}
    break;

  case 264:
#line 2971 "Gmsh.y"
    { yyval.d = acos(yyvsp[-1].d);     ;}
    break;

  case 265:
#line 2972 "Gmsh.y"
    { yyval.d = tan(yyvsp[-1].d);      ;}
    break;

  case 266:
#line 2973 "Gmsh.y"
    { yyval.d = atan(yyvsp[-1].d);     ;}
    break;

  case 267:
#line 2974 "Gmsh.y"
    { yyval.d = atan2(yyvsp[-3].d, yyvsp[-1].d);;}
    break;

  case 268:
#line 2975 "Gmsh.y"
    { yyval.d = sinh(yyvsp[-1].d);     ;}
    break;

  case 269:
#line 2976 "Gmsh.y"
    { yyval.d = cosh(yyvsp[-1].d);     ;}
    break;

  case 270:
#line 2977 "Gmsh.y"
    { yyval.d = tanh(yyvsp[-1].d);     ;}
    break;

  case 271:
#line 2978 "Gmsh.y"
    { yyval.d = fabs(yyvsp[-1].d);     ;}
    break;

  case 272:
#line 2979 "Gmsh.y"
    { yyval.d = floor(yyvsp[-1].d);    ;}
    break;

  case 273:
#line 2980 "Gmsh.y"
    { yyval.d = ceil(yyvsp[-1].d);     ;}
    break;

  case 274:
#line 2981 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 275:
#line 2982 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 276:
#line 2983 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-3].d*yyvsp[-3].d+yyvsp[-1].d*yyvsp[-1].d); ;}
    break;

  case 277:
#line 2984 "Gmsh.y"
    { yyval.d = yyvsp[-1].d*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 278:
#line 2986 "Gmsh.y"
    { yyval.d = exp(yyvsp[-1].d);      ;}
    break;

  case 279:
#line 2987 "Gmsh.y"
    { yyval.d = log(yyvsp[-1].d);      ;}
    break;

  case 280:
#line 2988 "Gmsh.y"
    { yyval.d = log10(yyvsp[-1].d);    ;}
    break;

  case 281:
#line 2989 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-1].d);     ;}
    break;

  case 282:
#line 2990 "Gmsh.y"
    { yyval.d = sin(yyvsp[-1].d);      ;}
    break;

  case 283:
#line 2991 "Gmsh.y"
    { yyval.d = asin(yyvsp[-1].d);     ;}
    break;

  case 284:
#line 2992 "Gmsh.y"
    { yyval.d = cos(yyvsp[-1].d);      ;}
    break;

  case 285:
#line 2993 "Gmsh.y"
    { yyval.d = acos(yyvsp[-1].d);     ;}
    break;

  case 286:
#line 2994 "Gmsh.y"
    { yyval.d = tan(yyvsp[-1].d);      ;}
    break;

  case 287:
#line 2995 "Gmsh.y"
    { yyval.d = atan(yyvsp[-1].d);     ;}
    break;

  case 288:
#line 2996 "Gmsh.y"
    { yyval.d = atan2(yyvsp[-3].d, yyvsp[-1].d);;}
    break;

  case 289:
#line 2997 "Gmsh.y"
    { yyval.d = sinh(yyvsp[-1].d);     ;}
    break;

  case 290:
#line 2998 "Gmsh.y"
    { yyval.d = cosh(yyvsp[-1].d);     ;}
    break;

  case 291:
#line 2999 "Gmsh.y"
    { yyval.d = tanh(yyvsp[-1].d);     ;}
    break;

  case 292:
#line 3000 "Gmsh.y"
    { yyval.d = fabs(yyvsp[-1].d);     ;}
    break;

  case 293:
#line 3001 "Gmsh.y"
    { yyval.d = floor(yyvsp[-1].d);    ;}
    break;

  case 294:
#line 3002 "Gmsh.y"
    { yyval.d = ceil(yyvsp[-1].d);     ;}
    break;

  case 295:
#line 3003 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 296:
#line 3004 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 297:
#line 3005 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-3].d*yyvsp[-3].d+yyvsp[-1].d*yyvsp[-1].d); ;}
    break;

  case 298:
#line 3006 "Gmsh.y"
    { yyval.d = yyvsp[-1].d*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 299:
#line 3015 "Gmsh.y"
    { yyval.d = yyvsp[0].d; ;}
    break;

  case 300:
#line 3016 "Gmsh.y"
    { yyval.d = 3.141592653589793; ;}
    break;

  case 301:
#line 3017 "Gmsh.y"
    { yyval.d = ParUtil::Instance()->rank(); ;}
    break;

  case 302:
#line 3018 "Gmsh.y"
    { yyval.d = ParUtil::Instance()->size(); ;}
    break;

  case 303:
#line 3019 "Gmsh.y"
    { yyval.d = GMSH_MAJOR_VERSION; ;}
    break;

  case 304:
#line 3020 "Gmsh.y"
    { yyval.d = GMSH_MINOR_VERSION; ;}
    break;

  case 305:
#line 3021 "Gmsh.y"
    { yyval.d = GMSH_PATCH_VERSION; ;}
    break;

  case 306:
#line 3026 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[0].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[0].c);
	yyval.d = 0.;
      }
      else
	yyval.d = *(double*)List_Pointer_Fast(pSymbol->val, 0);
      Free(yyvsp[0].c);
    ;}
    break;

  case 307:
#line 3039 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-3].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-3].c);
	yyval.d = 0.;
      }
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)yyvsp[-1].d)))
	  yyval.d = *pd;
	else{
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", yyvsp[-3].c, (int)yyvsp[-1].d);
	  yyval.d = 0.;
	}
      }
      Free(yyvsp[-3].c);
    ;}
    break;

  case 308:
#line 3059 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-2].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-2].c);
	yyval.d = 0.;
      }
      else{
	yyval.d = List_Nbr(pSymbol->val);
      }
      Free(yyvsp[-2].c);
    ;}
    break;

  case 309:
#line 3073 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-1].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-1].c);
	yyval.d = 0.;
      }
      else
	yyval.d = (*(double*)List_Pointer_Fast(pSymbol->val, 0) += yyvsp[0].i);
      Free(yyvsp[-1].c);
    ;}
    break;

  case 310:
#line 3086 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-4].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-4].c);
	yyval.d = 0.;
      }
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)yyvsp[-2].d)))
	  yyval.d = (*pd += yyvsp[0].i);
	else{
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", yyvsp[-4].c, (int)yyvsp[-2].d);
	  yyval.d = 0.;
	}
      }
      Free(yyvsp[-4].c);
    ;}
    break;

  case 311:
#line 3109 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-2].c))){
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-2].c);
	yyval.d = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption(yyvsp[0].c, pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", yyvsp[-2].c, yyvsp[0].c);
	  yyval.d = 0.;
	}
	else
	  yyval.d = pNumOpt(0, GMSH_GET, 0);
      }
      Free(yyvsp[-2].c); Free(yyvsp[0].c);
    ;}
    break;

  case 312:
#line 3127 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-5].c))){
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-5].c);
	yyval.d = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption(yyvsp[0].c, pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", yyvsp[-5].c, (int)yyvsp[-3].d, yyvsp[0].c);
	  yyval.d = 0.;
	}
	else
	  yyval.d = pNumOpt((int)yyvsp[-3].d, GMSH_GET, 0);
      }
      Free(yyvsp[-5].c); Free(yyvsp[0].c);
    ;}
    break;

  case 313:
#line 3145 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-3].c))){
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-3].c);
	yyval.d = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption(yyvsp[-1].c, pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", yyvsp[-3].c, yyvsp[-1].c);
	  yyval.d = 0.;
	}
	else
	  yyval.d = pNumOpt(0, GMSH_SET|GMSH_GUI, pNumOpt(0, GMSH_GET, 0)+yyvsp[0].i);
      }
      Free(yyvsp[-3].c); Free(yyvsp[-1].c);
    ;}
    break;

  case 314:
#line 3163 "Gmsh.y"
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-6].c))){
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-6].c);
	yyval.d = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption(yyvsp[-1].c, pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", yyvsp[-6].c, (int)yyvsp[-4].d, yyvsp[-1].c);
	  yyval.d = 0.;
	}
	else
	  yyval.d = pNumOpt((int)yyvsp[-4].d, GMSH_SET|GMSH_GUI, pNumOpt((int)yyvsp[-4].d, GMSH_GET, 0)+yyvsp[0].i);
      }
      Free(yyvsp[-6].c); Free(yyvsp[-1].c);
    ;}
    break;

  case 315:
#line 3181 "Gmsh.y"
    { 
      yyval.d = GetValue(yyvsp[-3].c, yyvsp[-1].d);
      Free(yyvsp[-3].c);
    ;}
    break;

  case 316:
#line 3189 "Gmsh.y"
    {
      memcpy(yyval.v, yyvsp[0].v, 5*sizeof(double));
    ;}
    break;

  case 317:
#line 3193 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) yyval.v[i] = -yyvsp[0].v[i];
    ;}
    break;

  case 318:
#line 3197 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) yyval.v[i] = yyvsp[0].v[i];
    ;}
    break;

  case 319:
#line 3201 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) yyval.v[i] = yyvsp[-2].v[i] - yyvsp[0].v[i];
    ;}
    break;

  case 320:
#line 3205 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) yyval.v[i] = yyvsp[-2].v[i] + yyvsp[0].v[i];
    ;}
    break;

  case 321:
#line 3212 "Gmsh.y"
    { 
      yyval.v[0] = yyvsp[-9].d;  yyval.v[1] = yyvsp[-7].d;  yyval.v[2] = yyvsp[-5].d;  yyval.v[3] = yyvsp[-3].d; yyval.v[4] = yyvsp[-1].d;
    ;}
    break;

  case 322:
#line 3216 "Gmsh.y"
    { 
      yyval.v[0] = yyvsp[-7].d;  yyval.v[1] = yyvsp[-5].d;  yyval.v[2] = yyvsp[-3].d;  yyval.v[3] = yyvsp[-1].d; yyval.v[4] = 1.0;
    ;}
    break;

  case 323:
#line 3220 "Gmsh.y"
    {
      yyval.v[0] = yyvsp[-5].d;  yyval.v[1] = yyvsp[-3].d;  yyval.v[2] = yyvsp[-1].d;  yyval.v[3] = 0.0; yyval.v[4] = 1.0;
    ;}
    break;

  case 324:
#line 3224 "Gmsh.y"
    {
      yyval.v[0] = yyvsp[-5].d;  yyval.v[1] = yyvsp[-3].d;  yyval.v[2] = yyvsp[-1].d;  yyval.v[3] = 0.0; yyval.v[4] = 1.0;
    ;}
    break;

  case 325:
#line 3231 "Gmsh.y"
    {
    ;}
    break;

  case 326:
#line 3234 "Gmsh.y"
    {
    ;}
    break;

  case 327:
#line 3240 "Gmsh.y"
    {
    ;}
    break;

  case 328:
#line 3243 "Gmsh.y"
    {
    ;}
    break;

  case 329:
#line 3249 "Gmsh.y"
    {
    ;}
    break;

  case 330:
#line 3252 "Gmsh.y"
    {
       yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 331:
#line 3256 "Gmsh.y"
    {
       yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 332:
#line 3263 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(List_T*));
      List_Add(yyval.l, &(yyvsp[0].l));
    ;}
    break;

  case 333:
#line 3268 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].l));
    ;}
    break;

  case 334:
#line 3276 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(double));
      List_Add(yyval.l, &(yyvsp[0].d));
    ;}
    break;

  case 335:
#line 3281 "Gmsh.y"
    {
      yyval.l = yyvsp[0].l;
    ;}
    break;

  case 336:
#line 3285 "Gmsh.y"
    {
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 337:
#line 3289 "Gmsh.y"
    {
      yyval.l = yyvsp[-1].l;
      double *pd;
      for(int i = 0; i < List_Nbr(yyval.l); i++){
	pd = (double*)List_Pointer(yyval.l, i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 338:
#line 3301 "Gmsh.y"
    { 
      yyval.l = List_Create(2, 1, sizeof(double)); 
      for(double d = yyvsp[-2].d; (yyvsp[-2].d < yyvsp[0].d) ? (d <= yyvsp[0].d) : (d >= yyvsp[0].d); (yyvsp[-2].d < yyvsp[0].d) ? (d += 1.) : (d -= 1.)) 
	List_Add(yyval.l, &d);
    ;}
    break;

  case 339:
#line 3307 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(double)); 
      if(!yyvsp[0].d || (yyvsp[-4].d < yyvsp[-2].d && yyvsp[0].d < 0) || (yyvsp[-4].d > yyvsp[-2].d && yyvsp[0].d > 0)){
        yymsg(GERROR, "Wrong increment in '%g:%g:%g'", yyvsp[-4].d, yyvsp[-2].d, yyvsp[0].d);
	List_Add(yyval.l, &(yyvsp[-4].d));
      }
      else
	for(double d = yyvsp[-4].d; (yyvsp[0].d > 0) ? (d <= yyvsp[-2].d) : (d >= yyvsp[-2].d); d += yyvsp[0].d)
	  List_Add(yyval.l, &d);
   ;}
    break;

  case 340:
#line 3318 "Gmsh.y"
    {
      // Returns the coordinates of a point and fills a list with it.
      // This allows to ensure e.g. that relative point positions are
      // always conserved
      Vertex *v = FindPoint((int)yyvsp[-1].d, THEM);
      yyval.l = List_Create(3, 1, sizeof(double));      
      if(!v) {
	yymsg(GERROR, "Unknown point '%d'", (int) yyvsp[-1].d);
	double d = 0.0;
	List_Add(yyval.l, &d);
	List_Add(yyval.l, &d);
	List_Add(yyval.l, &d);
      }
      else{
	List_Add(yyval.l, &v->Pos.X);
	List_Add(yyval.l, &v->Pos.Y);
	List_Add(yyval.l, &v->Pos.Z);
      }
    ;}
    break;

  case 341:
#line 3338 "Gmsh.y"
    {
      yyval.l = List_Create(List_Nbr(yyvsp[0].l), 1, sizeof(double));
      for(int i = 0; i < List_Nbr(yyvsp[0].l); i++){
	Shape *s = (Shape*) List_Pointer(yyvsp[0].l, i);
	double d = s->Num;
	List_Add(yyval.l, &d);
      }
      List_Delete(yyvsp[0].l);
    ;}
    break;

  case 342:
#line 3348 "Gmsh.y"
    {
      yyval.l = List_Create(List_Nbr(yyvsp[0].l), 1, sizeof(double));
      for(int i = 0; i < List_Nbr(yyvsp[0].l); i++){
	Shape *s = (Shape*) List_Pointer(yyvsp[0].l, i);
	double d = s->Num;
	List_Add(yyval.l, &d);
      }
      List_Delete(yyvsp[0].l);
    ;}
    break;

  case 343:
#line 3358 "Gmsh.y"
    {
      // FIXME: The syntax for this is ugly: we get double semi-colons
      // at the end of the line
      yyval.l = List_Create(List_Nbr(yyvsp[0].l), 1, sizeof(double));
      for(int i = 0; i < List_Nbr(yyvsp[0].l); i++){
	Shape *s = (Shape*) List_Pointer(yyvsp[0].l, i);
	double d = s->Num;
	List_Add(yyval.l, &d);
      }
      List_Delete(yyvsp[0].l);
    ;}
    break;

  case 344:
#line 3370 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(double));
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-2].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-2].c);
	double d = 0.0;
	List_Add(yyval.l, &d);
      }
      else{
	for(int i = 0; i < List_Nbr(pSymbol->val); i++)
	  List_Add(yyval.l, (double*)List_Pointer_Fast(pSymbol->val, i));
      }
      Free(yyvsp[-2].c);
    ;}
    break;

  case 345:
#line 3387 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(double));
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-2].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-2].c);
	double d = 0.0;
	List_Add(yyval.l, &d);
      }
      else{
	for(int i = 0; i < List_Nbr(pSymbol->val); i++){
	  double d = - *(double*)List_Pointer_Fast(pSymbol->val, i);
	  List_Add(yyval.l, &d);
	}
      }
      Free(yyvsp[-2].c);
    ;}
    break;

  case 346:
#line 3406 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(double));
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-5].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-5].c);
	double d = 0.0;
	List_Add(yyval.l, &d);
      }
      else{
	for(int i = 0; i < List_Nbr(yyvsp[-2].l); i++){
	  int j = (int)(*(double*)List_Pointer_Fast(yyvsp[-2].l, i));
	  double *pd;
	  if((pd = (double*)List_Pointer_Test(pSymbol->val, j)))
	    List_Add(yyval.l, pd);
	  else
	    yymsg(GERROR, "Uninitialized variable '%s[%d]'", yyvsp[-5].c, j);	  
	}
      }
      Free(yyvsp[-5].c);
      List_Delete(yyvsp[-2].l);
    ;}
    break;

  case 347:
#line 3430 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(double));
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-5].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-5].c);
	double d = 0.0;
	List_Add(yyval.l, &d);
      }
      else{
	for(int i = 0; i < List_Nbr(yyvsp[-2].l); i++){
	  int j = (int)(*(double*)List_Pointer_Fast(yyvsp[-2].l, i));
	  double *pd;
	  if((pd = (double*)List_Pointer_Test(pSymbol->val, j))){
	    double d = - *pd;
	    List_Add(yyval.l, &d);
	  }
	  else
	    yymsg(GERROR, "Uninitialized variable '%s[%d]'", yyvsp[-5].c, j);	  
	}
      }
      Free(yyvsp[-5].c);
      List_Delete(yyvsp[-2].l);
    ;}
    break;

  case 348:
#line 3459 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(double));
      List_Add(yyval.l, &(yyvsp[0].d));
    ;}
    break;

  case 349:
#line 3464 "Gmsh.y"
    {
      yyval.l = yyvsp[0].l;
    ;}
    break;

  case 350:
#line 3468 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].d));
    ;}
    break;

  case 351:
#line 3472 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[0].l); i++){
	double d;
	List_Read(yyvsp[0].l, i, &d);
	List_Add(yyval.l, &d);
      }
      List_Delete(yyvsp[0].l);
    ;}
    break;

  case 352:
#line 3485 "Gmsh.y"
    {
      yyval.u = PACK_COLOR((int)yyvsp[-7].d, (int)yyvsp[-5].d, (int)yyvsp[-3].d, (int)yyvsp[-1].d);
    ;}
    break;

  case 353:
#line 3489 "Gmsh.y"
    {
      yyval.u = PACK_COLOR((int)yyvsp[-5].d, (int)yyvsp[-3].d, (int)yyvsp[-1].d, 255);
    ;}
    break;

  case 354:
#line 3501 "Gmsh.y"
    {
      int flag;
      yyval.u = Get_ColorForString(ColorString, -1, yyvsp[0].c, &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", yyvsp[0].c);
      Free(yyvsp[0].c);
    ;}
    break;

  case 355:
#line 3508 "Gmsh.y"
    {
      unsigned int (*pColOpt)(int num, int action, unsigned int value);
      StringXColor *pColCat;
      if(!(pColCat = Get_ColorOptionCategory(yyvsp[-4].c))){
	yymsg(GERROR, "Unknown color option class '%s'", yyvsp[-4].c);
	yyval.u = 0;
      }
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption(yyvsp[0].c, pColCat))){
	  yymsg(GERROR, "Unknown color option '%s.Color.%s'", yyvsp[-4].c, yyvsp[0].c);
	  yyval.u = 0;
	}
	else{
	  yyval.u = pColOpt(0, GMSH_GET, 0);
	}
      }
      Free(yyvsp[-4].c); Free(yyvsp[0].c);
    ;}
    break;

  case 356:
#line 3530 "Gmsh.y"
    {
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 357:
#line 3534 "Gmsh.y"
    {
      yyval.l = List_Create(256, 10, sizeof(unsigned int));
      GmshColorTable *ct = Get_ColorTable((int)yyvsp[-3].d);
      if(!ct)
	yymsg(GERROR, "View[%d] does not exist", (int)yyvsp[-3].d);
      else{
	for(int i = 0; i < ct->size; i++) 
	  List_Add(yyval.l, &ct->table[i]);
      }
      Free(yyvsp[-5].c);
    ;}
    break;

  case 358:
#line 3549 "Gmsh.y"
    {
      yyval.l = List_Create(256, 10, sizeof(unsigned int));
      List_Add(yyval.l, &(yyvsp[0].u));
    ;}
    break;

  case 359:
#line 3554 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].u));
    ;}
    break;

  case 360:
#line 3561 "Gmsh.y"
    {
      yyval.c = yyvsp[0].c;
    ;}
    break;

  case 361:
#line 3565 "Gmsh.y"
    {
      yyval.c = (char *)Malloc(32*sizeof(char));
      time_t now;
      time(&now);
      strcpy(yyval.c, ctime(&now));
      yyval.c[strlen(yyval.c) - 1] = '\0';
    ;}
    break;

  case 362:
#line 3573 "Gmsh.y"
    {
      yyval.c = (char *)Malloc((strlen(yyvsp[-3].c)+strlen(yyvsp[-1].c)+1)*sizeof(char));
      strcpy(yyval.c, yyvsp[-3].c);
      strcat(yyval.c, yyvsp[-1].c);
      Free(yyvsp[-3].c);
      Free(yyvsp[-1].c);
    ;}
    break;

  case 363:
#line 3581 "Gmsh.y"
    {
      yyval.c = (char *)Malloc((strlen(yyvsp[-1].c)+1)*sizeof(char));
      int i;
      for(i = strlen(yyvsp[-1].c)-1; i >= 0; i--){
	if(yyvsp[-1].c[i] == '.'){
	  strncpy(yyval.c, yyvsp[-1].c, i);
	  yyval.c[i]='\0';
	  break;
	}
      }
      if(i <= 0) strcpy(yyval.c, yyvsp[-1].c);
      Free(yyvsp[-1].c);
    ;}
    break;

  case 364:
#line 3595 "Gmsh.y"
    {
      yyval.c = (char *)Malloc((strlen(yyvsp[-1].c)+1)*sizeof(char));
      int i;
      for(i = strlen(yyvsp[-1].c)-1; i >= 0; i--){
	if(yyvsp[-1].c[i] == '/' || yyvsp[-1].c[i] == '\\')
	  break;
      }
      if(i <= 0)
	strcpy(yyval.c, yyvsp[-1].c);
      else
	strcpy(yyval.c, &yyvsp[-1].c[i+1]);
      Free(yyvsp[-1].c);
    ;}
    break;

  case 365:
#line 3609 "Gmsh.y"
    {
      yyval.c = yyvsp[-1].c;
    ;}
    break;

  case 366:
#line 3613 "Gmsh.y"
    {
      char tmpstring[1024];
      int i = PrintListOfDouble(yyvsp[-3].c, yyvsp[-1].l, tmpstring);
      if(i < 0){
	yymsg(GERROR, "Too few arguments in Sprintf");
	yyval.c = yyvsp[-3].c;
      }
      else if(i > 0){
	yymsg(GERROR, "%d extra argument%s in Sprintf", i, (i>1)?"s":"");
	yyval.c = yyvsp[-3].c;
      }
      else{
	yyval.c = (char*)Malloc((strlen(tmpstring)+1)*sizeof(char));
	strcpy(yyval.c, tmpstring);
	Free(yyvsp[-3].c);
      }
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 367:
#line 3632 "Gmsh.y"
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory(yyvsp[-3].c))){
	yymsg(GERROR, "Unknown string option class '%s'", yyvsp[-3].c);
	yyval.c = (char*)Malloc(sizeof(char));
	yyval.c[0] = '\0';
      }
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption(yyvsp[-1].c, pStrCat))){
	  yymsg(GERROR, "Unknown string option '%s.%s'", yyvsp[-3].c, yyvsp[-1].c);
	  yyval.c = (char*)Malloc(sizeof(char));
	  yyval.c[0] = '\0';
	}
	else{
	  char *str = pStrOpt(0, GMSH_GET, NULL);
	  yyval.c = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy(yyval.c, str);
	}
      }
    ;}
    break;

  case 368:
#line 3654 "Gmsh.y"
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory(yyvsp[-6].c))){
	yymsg(GERROR, "Unknown string option class '%s'", yyvsp[-6].c);
	yyval.c = (char*)Malloc(sizeof(char));
	yyval.c[0] = '\0';
      }
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption(yyvsp[-1].c, pStrCat))){
	  yymsg(GERROR, "Unknown string option '%s[%d].%s'", yyvsp[-6].c, (int)yyvsp[-4].d, yyvsp[-1].c);
	  yyval.c = (char*)Malloc(sizeof(char));
	  yyval.c[0] = '\0';
	}
	else{
	  char *str = pStrOpt((int)yyvsp[-4].d, GMSH_GET, NULL);
	  yyval.c = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy(yyval.c, str);
	}
      }
    ;}
    break;


    }

/* Line 991 of yacc.c.  */
#line 7911 "Gmsh.tab.cpp"

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
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
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
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__) \
    && !defined __cplusplus
  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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


#line 3677 "Gmsh.y"


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

