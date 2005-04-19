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

// $Id: Gmsh.tab.cpp,v 1.237 2005-04-19 16:03:11 remacle Exp $
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
#define YYLAST   6252

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  183
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  69
/* YYNRULES -- Number of rules. */
#define YYNRULES  367
/* YYNRULES -- Number of states. */
#define YYNSTATES  1504

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
    1618,  1621,  1628,  1638,  1648,  1657,  1666,  1675,  1682,  1687,
    1690,  1693,  1695,  1697,  1699,  1701,  1703,  1705,  1709,  1712,
    1715,  1718,  1722,  1726,  1730,  1734,  1738,  1742,  1746,  1750,
    1754,  1758,  1762,  1766,  1770,  1774,  1780,  1785,  1790,  1795,
    1800,  1805,  1810,  1815,  1820,  1825,  1830,  1837,  1842,  1847,
    1852,  1857,  1862,  1867,  1874,  1881,  1888,  1893,  1898,  1903,
    1908,  1913,  1918,  1923,  1928,  1933,  1938,  1943,  1950,  1955,
    1960,  1965,  1970,  1975,  1980,  1987,  1994,  2001,  2006,  2008,
    2010,  2012,  2014,  2016,  2018,  2020,  2022,  2027,  2032,  2035,
    2041,  2045,  2052,  2057,  2065,  2072,  2074,  2077,  2080,  2084,
    2088,  2100,  2110,  2118,  2126,  2127,  2131,  2133,  2137,  2138,
    2142,  2146,  2148,  2152,  2154,  2156,  2160,  2165,  2169,  2175,
    2180,  2182,  2184,  2186,  2190,  2195,  2202,  2210,  2212,  2214,
    2218,  2222,  2232,  2240,  2242,  2248,  2252,  2259,  2261,  2265,
    2267,  2269,  2276,  2281,  2286,  2291,  2298,  2305
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
     181,   237,   182,     7,   245,     6,    -1,    51,    45,   181,
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
    1818,  1830,  1839,  1849,  1859,  1878,  1892,  1900,  1906,  1917,
    1931,  1975,  1990,  2006,  2016,  2038,  2042,  2046,  2050,  2063,
    2078,  2094,  2120,  2147,  2179,  2186,  2191,  2197,  2201,  2212,
    2228,  2244,  2261,  2260,  2282,  2281,  2303,  2302,  2325,  2348,
    2371,  2395,  2394,  2423,  2422,  2451,  2450,  2481,  2504,  2527,
    2551,  2550,  2579,  2578,  2608,  2607,  2639,  2642,  2648,  2674,
    2698,  2707,  2725,  2743,  2761,  2788,  2814,  2840,  2854,  2873,
    2877,  2887,  2888,  2889,  2890,  2891,  2895,  2896,  2897,  2898,
    2899,  2900,  2901,  2902,  2903,  2910,  2911,  2912,  2913,  2914,
    2915,  2916,  2917,  2918,  2919,  2920,  2921,  2922,  2923,  2924,
    2925,  2926,  2927,  2928,  2929,  2930,  2931,  2932,  2933,  2934,
    2935,  2936,  2937,  2938,  2939,  2940,  2941,  2943,  2944,  2945,
    2946,  2947,  2948,  2949,  2950,  2951,  2952,  2953,  2954,  2955,
    2956,  2957,  2958,  2959,  2960,  2961,  2962,  2963,  2972,  2973,
    2974,  2975,  2976,  2977,  2978,  2982,  2995,  3015,  3029,  3042,
    3065,  3083,  3101,  3119,  3137,  3145,  3149,  3153,  3157,  3161,
    3168,  3172,  3176,  3180,  3188,  3190,  3196,  3199,  3206,  3208,
    3212,  3219,  3224,  3232,  3237,  3241,  3245,  3257,  3263,  3274,
    3294,  3304,  3314,  3326,  3343,  3362,  3386,  3415,  3420,  3424,
    3428,  3441,  3445,  3457,  3464,  3486,  3490,  3505,  3510,  3517,
    3521,  3529,  3537,  3551,  3565,  3569,  3588,  3610
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
     233,   234,   234,   234,   234,   234,   234,   234,   234,   235,
     235,   236,   236,   236,   236,   236,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   239,   239,   239,   239,   239,
     240,   240,   240,   240,   241,   241,   242,   242,   243,   243,
     243,   244,   244,   245,   245,   245,   245,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   247,   247,   247,
     247,   248,   248,   248,   248,   249,   249,   250,   250,   251,
     251,   251,   251,   251,   251,   251,   251,   251
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
       2,     6,     9,     9,     8,     8,     8,     6,     4,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     6,     6,     6,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     2,     5,
       3,     6,     4,     7,     6,     1,     2,     2,     3,     3,
      11,     9,     7,     7,     0,     3,     1,     3,     0,     3,
       3,     1,     3,     1,     1,     3,     4,     3,     5,     4,
       1,     1,     1,     3,     4,     6,     7,     1,     1,     3,
       3,     9,     7,     1,     5,     3,     6,     1,     3,     1,
       1,     6,     4,     4,     4,     6,     6,     9
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
     324,   324,     0,   298,   305,   359,    92,   299,   300,   301,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   360,     0,   302,   303,   304,
      96,    95,    94,    93,     0,     0,     0,    98,    97,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,   176,
       0,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     315,     0,     0,     0,     0,     0,     0,   151,     0,     0,
     151,   229,   230,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   353,     0,     0,     0,     0,     0,   175,     0,
     184,     0,   359,   151,     0,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   308,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   305,   239,   238,   240,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   305,     0,     0,     0,   340,   341,
     342,   333,     0,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   317,   316,
       0,     0,     0,     0,   151,   151,     0,     0,     0,     0,
       0,     0,     0,     0,   163,     0,     0,     0,     0,     0,
       0,   174,     0,     0,     0,     0,     0,     0,     0,   151,
       0,     0,     0,   186,     0,     0,   166,     0,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   326,
       0,     0,     0,     0,     0,   310,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   237,     0,     0,
     347,   348,     0,     0,    92,     0,     0,     0,     0,     0,
      99,     0,   254,   253,   252,   251,   247,   248,   250,   249,
     242,   241,   243,   244,   245,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     319,   318,   150,     0,   149,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   152,   228,     0,
     164,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   187,     0,   168,
     169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   325,     0,     0,    16,     0,   306,   312,    68,    78,
       0,     0,     0,    90,     0,    69,    70,    71,    72,    73,
     256,   277,   257,   278,   258,   279,   259,   280,   260,   281,
     261,   282,   262,   283,   263,   284,   264,   285,   276,   297,
     265,   286,     0,     0,   267,   288,   268,   289,   269,   290,
     270,   291,   271,   292,   272,   293,     0,     0,     0,     0,
       0,     0,     0,     0,   364,     0,     0,   362,   363,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
       0,     0,     0,     0,   307,     0,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   343,     0,     0,
       0,     0,   335,   337,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   327,
       0,   324,     0,   309,     0,     0,     0,     0,     0,     0,
       0,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,   102,   349,   350,     0,
       0,     0,     0,     0,   104,   105,   107,     0,     0,   357,
       0,   113,   255,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   339,   344,     0,   336,     0,   120,
       0,     0,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   158,     0,     0,     0,     0,   227,   162,     0,     0,
     159,   160,     0,     0,     0,   328,     0,   354,     0,     0,
       0,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   231,   232,   233,   234,
     235,     0,     0,     0,     0,     0,     0,     0,    15,     0,
     311,   171,     0,     0,     0,     0,     0,   331,     0,   266,
     287,   273,   294,   274,   295,   275,   296,     0,   366,   365,
     361,   314,     0,    92,     0,     0,     0,     0,   100,     0,
       0,     0,   355,    65,     0,   117,   123,     0,   125,     0,
       0,   121,     0,   122,   142,     0,     0,   338,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,     0,     0,     0,     0,   151,     0,   192,     0,
     201,     0,   210,     0,     0,     0,     0,     0,     0,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     324,   313,    67,     0,    74,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,   110,     0,     0,   111,     0,
     358,     0,     0,     0,   131,   139,   345,     0,     0,   225,
     134,   135,     0,     0,   224,   226,   141,   118,   133,   140,
     143,     0,     0,     0,   323,     0,   322,     0,     0,   189,
       0,     0,   198,     0,     0,   207,     0,   153,   154,   155,
     156,     0,     0,   328,     0,     0,     0,     0,     0,   352,
       0,   181,   180,     0,     0,     0,     0,    18,     0,    27,
       0,    31,     0,    25,     0,     0,    30,     0,    35,    33,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
       0,     0,    47,     0,     0,    79,     0,     0,     0,   332,
       0,     0,     0,     0,   101,   106,   108,     0,   114,     0,
       0,   124,   126,   346,     0,   223,   222,   115,   116,   151,
       0,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   330,   329,     0,     0,     0,     0,     0,     0,   328,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,     0,     0,     0,    77,    91,   367,     0,   356,
       0,     0,     0,     0,   321,     0,     0,     0,     0,     0,
       0,     0,     0,   216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   351,   182,     0,    32,     0,
       0,     0,     0,    22,     0,    28,     0,    34,    23,    36,
       0,    39,     0,    43,    44,     0,     0,    46,     0,     0,
       0,     0,     0,     0,   112,     0,     0,   145,     0,     0,
     194,     0,   220,     0,     0,   217,   203,     0,     0,   212,
       0,     0,     0,     0,     0,     0,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,    89,     0,     0,   320,   190,     0,     0,
       0,   193,   199,     0,     0,   202,   208,     0,     0,   211,
     119,   132,     0,     0,   136,     0,     0,     0,     0,    26,
      29,    37,     0,    38,    45,    40,     0,     0,     0,     0,
       0,     0,     0,   196,     0,     0,   205,     0,   214,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,    87,
       0,     0,     0,   191,     0,     0,     0,   200,     0,     0,
     209,     0,     0,     0,     0,     0,    21,    24,     0,     0,
       0,    81,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   195,     0,     0,   219,   204,     0,   213,
       0,     0,     0,     0,     0,    41,    17,    82,    84,     0,
      85,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   197,   218,   206,   215,     0,     0,     0,     0,
      86,    88,     0,     0,     0,     0,     0,   138,     0,     0,
       0,     0,     0,   137,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    20
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,    16,    17,    18,    19,     4,    69,    70,
      71,   447,  1073,  1079,   645,   816,  1240,  1420,   646,  1378,
    1459,   647,  1422,   648,   649,   820,   143,   253,    72,   577,
     348,   563,   564,   349,    76,    77,    78,    79,    80,   350,
    1120,  1348,  1404,  1123,  1353,  1408,  1126,  1357,  1411,  1262,
    1263,    82,    83,   941,   351,   146,   368,   180,   248,   440,
    1034,   956,   957,   353,   502,   204,   713,   850,   147
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1251
static const short yypact[] =
{
    2449,    39,    64,    38,  2598, -1251, -1251,    90,   107,   116,
     125,   134,   155,     1,    18,    29, -1251, -1251, -1251, -1251,
    1901,    36,    24,   178,    40,    55,   114,   -29,   230,   146,
     150,   289,   172,   319,   337,   344,   457,   350,   702,   251,
     224,   -82,   -82,   258,   465,     9,   397,    10,   430,   439,
     311,   459,   474,   511,   352,   356,   -14,    16,    14, -1251,
     362, -1251,   521, -1251,   542,   552,   512,    12,    23, -1251,
   -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1251,
   -1251, -1251, -1251, -1251,  2478, -1251, -1251, -1251, -1251, -1251,
     386,   386,   556, -1251,   353,    20, -1251, -1251, -1251, -1251,
     -87,   -25,   -21,    54,   140,   156,   259,   314,   345,   361,
     374,   395,   420,   421,   461,   469,   470,   475,   500,   522,
     523,   398,   404,   408,   451, -1251,   452, -1251, -1251, -1251,
   -1251, -1251, -1251, -1251,  2146,  2146,  2146, -1251, -1251,  2146,
     900,    84,   596,  2146,   598,   610, -1251,   614,   624, -1251,
    2146, -1251,  2146,  2146,  2146,   462,  2146,   476,  2146,  2146,
    1454,  2146,   479,   491,   499,  1454,   483,   496,   506,   507,
     510,   535,   539,   697,   -82,   -82,   -82,  2146,  2146,   170,
   -1251,   204,   -82,   533,   537,   540,   583, -1251,  1454,    33,
   -1251, -1251, -1251,  1454,  1454,   586,   590,   742,  2146,  2146,
     -56,  2146,   600,  2146,   615,   688,  2146,  2146, -1251,   789,
   -1251,   625, -1251, -1251,   798, -1251,   826,   661,   666,   670,
     682,   684,   685,   686,   687,   689,   696,   708,   709,   710,
     711,   712,   717,   718,   719,   720,   721,   722,   723,   724,
     726,   727,   728,   731,   732,   734,   763,   857,   759,   765,
     761,  2146,   938, -1251,   -82, -1251,  2146,  2146,  2146,  2146,
    2146,  2146,  2146,  2146,  2146,  2146,  2146,  2146,  2146,  2146,
    2146,  2146,  2146,  2146,  2146,  2146,  2146,  2146,  2146,  2146,
    2146,  2146,  2146,  2146,  2146,  2146,  2146,  2146,  2146,  2146,
    2146,  2146,  2146,  2146,  2146,  2146,  2146,  2146,   372,   313,
     313,   313,   942,   373,   770,   770,   770,  4812,   937,  2078,
    4182,   391,   771,   941,   774,   627, -1251, -1251,  2146,  2146,
    2146,  2146,  2146,  2146,  2146,  2146,  2146,  2146,  2146,  2146,
    2146,  2146,  2146, -1251,  -101,  3150,  4835,  4858,  4881,  2146,
    4904,  2146,  4927,  4950,   446,   772,  1665,  2078, -1251, -1251,
   -1251,   569,   944, -1251,  4973,  2146,  2146,  2146,   948,  2146,
    2146,  2146,  2146,  2146,  2146,  2146,   781,  -113, -1251, -1251,
    3174,  3198,   -82,   -82,   641,   641,   231,  2146,  2146,  2146,
    2146,  2182,    70,   951, -1251,  2146,  2247,   952,   953,  2146,
    2146, -1251,  4996,  5019,   872,  2146,  5042,   873,  3222, -1251,
     782,  1599,  5065, -1251,  2146,  2324, -1251,  2345, -1251,   959,
     960,   961,   962,   963,   964,   965,   967,   970,   971,   972,
     973,   974,   975,   976,   980,   981,   982,   983,   984,   988,
     989,   990,   831,   991,   992,   993,   994,   987,   995, -1251,
     -54,   996,  1000,  1004,  4203,   246,   229,     7,  5088,  4224,
    5111,  4245,  5134,  4266,  5157,  4287,  5180,  4308,  5203,  4329,
    5226,  4350,  5249,  4371,  5272,  4392,  5295,  4413,  5318,  4434,
    3246,  3270,  5341,  4455,  5364,  4476,  5387,  4497,  5410,  4518,
    5433,  4539,  5456,  4560,  3294,  3318,  3342,  3366,  3390,  3414,
     541,   186,   830,   836,   837,   833,  2146, -1251,  1454,  2181,
     569, -1251,   571,   272,   313,  2146,  1008,  1013,    21,   841,
   -1251,  1621,  1267,  1014,   527,   527,   401,   401,   401,   401,
     -19,   -19,   770,   770,   770,   770,  1016,  2078,  2146,  1017,
    1018,  1019,  5479,  1020,  5502,  1021,  1022,  1242,  2146,   456,
    2078,   572,  2146,  2146,  1023,  1339,  5525,  5548,  2146,  2632,
    2658,  5571,  5594,  5617,  5640,  5663,   845,   -82,  2146,  2146,
   -1251, -1251, -1251,   850,  2659, -1251,   851,  2146,  3438,  3462,
    3486,  4581,   -69,   -31,   -44,   -57, -1251, -1251, -1251,  2146,
   -1251,  4602, -1251,   853,   854,  4623,  4644,  1029,  1030,   867,
    5686,  1035,   865,  2146,  2390,  2146,  2146, -1251,  5709, -1251,
   -1251,   864,   866,   868,   870,   871,   874,   877,   878,   879,
     880,   881,   882,   885,   886,   887,   888,   890,   892,   893,
     895,   896,   902,   903,   904,   905,   906,   907,   908,   909,
     910, -1251,  1042,   916, -1251,   927,    35, -1251, -1251, -1251,
     934,   935,   899, -1251,  1046, -1251, -1251, -1251, -1251, -1251,
   -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1251,
   -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1251,
   -1251, -1251,  2146,  2146, -1251, -1251, -1251, -1251, -1251, -1251,
   -1251, -1251, -1251, -1251, -1251, -1251,  2146,  2146,  2146,  2146,
    2146,  2146,  2146,  1049, -1251,  2078,   313, -1251, -1251,  2146,
    4665,  1104,  2078,   936,   292,  2146,  1105,  1108,   648, -1251,
    1109,   943,    16,  1111, -1251,  2146, -1251,   211,  3510,   -82,
    1454,  1454,  1117,  1454,  1129,  1454,  1454, -1251,  2078,  2684,
    1634,   575, -1251,  1726,   714,   956,  1146,  1147,  1148,   426,
    1150,  1152,  1153,  1155,  1156,  1157,  1158,  1162,   236,  3534,
    3558, -1251, -1251,  2710,   -82,   -82,   -82,  1164,  2078,  2078,
    2078,  2078,   939,  1177,  2146,  2146,  1179,  1184,  1454,  1454,
    2146,  1161,  1454,  1187,  3582, -1251,  1864,   448,  1185,  1112,
    2146,  2146,   -82,  1190,  1192,  1031,  1197,  1202,  1454,  1454,
    1203,   -82,  1204,  1205,  1454,  1454,  1206,  1208,  1209,  1210,
    1211,  1454,   546,  1454,  1213,  1212,  1214,  1217,  1218, -1251,
    1219,   386,  1220, -1251,  1221,    17,  1052,  2146,  2146,  1454,
    1047, -1251,  5732,  4686,  5755,  4707,  5778,  4728,  5801,  4749,
    4770,  1054,   240,  1056,  5824,   -70, -1251,   569, -1251,    66,
     490,  1062,  1225,   968, -1251, -1251, -1251,    16,  2146, -1251,
     576, -1251,  1176,  1228,  2146,    60,    26,    28,  1454,  1236,
    1454,  1241,  1243,   636, -1251, -1251,  2078, -1251,  2146, -1251,
    2146,  1454,  1454,  1454, -1251,   394,  1454,  1454,  1454,  1454,
    1454,  1454,  1454,   489,  2146,  2146,  2146,  1067,   -73,   -53,
     208, -1251,   637,   640,   643,   644, -1251, -1251,  3606,  3630,
   -1251, -1251,  1244,  1269,  5847,   -39,  1189, -1251,  2146,  2146,
    2146, -1251,  1096,  1098,  3654,  3678,  -120,  1099,  1106,  1102,
    1110,  1103,  1113,  1114,  1115,  -110,  1116,  1118,  1123,  1119,
    1121,  1122,  1124,  1125,  1128,  1134, -1251, -1251, -1251, -1251,
   -1251,  1130,  1131,  1135,  1136,  1137,  1139,  1138, -1251,  1140,
     246, -1251,  1278,  2146,  3702,  3726,   647, -1251,  2146, -1251,
   -1251, -1251, -1251, -1251, -1251, -1251, -1251,  1145, -1251, -1251,
   -1251, -1251,  1454,   313,  2146,  1283,  1288,    21, -1251,  1297,
    4791,    16, -1251, -1251,  3750, -1251, -1251,   -82, -1251,   -82,
    1319, -1251,  1320, -1251, -1251,  1151,   651,  1176,  3774,  1321,
    1342,  1344,  2146,  2146,  1348,  1360,  1361,  1362,  1363,  1364,
    1366, -1251,  1954,  2736,  5870,  1881,   641,   -82,  1368,   -82,
    1371,   -82,  1373,  1374,  1375,  1379,  1381,  2146,  2146, -1251,
   -1251,  1385,  1454,  1454,  1301,  1454,  2563,   307,  5893,  2146,
    1390,  2146,  1454,  1395,  1399,  1397,  1245,  1401,   546,  1402,
    1406,  2146,  1407,  1414,  1412,  1429,  1417,   546,  2146,  2146,
    2146,  1454,  1431,  1435,   546,  2146,  1436,  1438,  1437,  2146,
     386, -1251, -1251,   271,  1176,  2146,  2146,  1454,  1231,   656,
    1176,  1440,  1442,  1443,   985, -1251,  1444,  1446, -1251,  1264,
   -1251,  2146,    62,   119, -1251, -1251, -1251,  1273,  2146, -1251,
   -1251, -1251,  1198,  1377, -1251, -1251, -1251, -1251, -1251, -1251,
   -1251,  1409,  1447,  1274, -1251,  2146, -1251,  1272,   239, -1251,
    1275,   250, -1251,  1279,   277, -1251,  1280, -1251, -1251, -1251,
   -1251,  3798,  3822,   -39,   274,   659,  1306,  1404,  2146, -1251,
    2146, -1251, -1251,  3846,  1284,  3870,  1309, -1251,  1311, -1251,
    1327, -1251,  1333, -1251,  1329,  5916, -1251,  1330, -1251, -1251,
    1336,  1338,  5939,  3894,  5962,  1334, -1251,  1347,  1349,  3918,
    1343,  1350, -1251,  3942,  1346, -1251,  2146,  3966,  3990, -1251,
    1454,  2146,  1521,  1358, -1251, -1251, -1251,    16, -1251,  1456,
    4014, -1251, -1251, -1251,  4038, -1251, -1251, -1251, -1251,   641,
    2602, -1251,  1697,   409,  1697,   409,  1697,   409,  2146,  2146,
    1459, -1251, -1251,  1454,  2146,  2762,  2788,  1454,  1541,   -39,
     546,  1545,  2146,  1543,   546,  1546,  1548,  1549,  1555,  1559,
    2146,  1571,  1454,  1572,  1574,  2146,  1551,  1575,  2146,  1578,
    1403,  1176,  2146,  2146,   663,  1176, -1251, -1251,  1579, -1251,
    2146,  1581,  1405,  2146, -1251,  1697,  1697,  2146,  2814,   295,
    1582,  1408,   -12, -1251,  2840,   323,    30,  2866,   336,   103,
    2892,  2918,  1410,  1428,  1439, -1251, -1251,  1427, -1251,  1430,
    1433,  1434,  4062, -1251,  1415, -1251,  1441, -1251, -1251, -1251,
    5985, -1251,  1445, -1251, -1251,  6008,  1449, -1251,  6031,  1450,
    2146,  6054,  4086,  1605, -1251,  4110,  1451, -1251,  2944,  3126,
    1609,  2146, -1251,  1454,  1613, -1251,  1614,  2146,  1615,  1616,
    2146,  1620,  1626,  1628,  1454,  1454, -1251,  1630,   546,   546,
     546,   546,  1633,  1635,  1636,   546,  1661,  1664,  1666,  1622,
     667, -1251,  2146, -1251,  2146,  1668, -1251, -1251,  1490,  2970,
    1460, -1251, -1251,  1517,  2996, -1251, -1251,  1518,  3022, -1251,
   -1251, -1251,  1522,  1523, -1251,  1524,  1550,  1528,  1557, -1251,
   -1251, -1251,  1553, -1251, -1251, -1251,  1560,  1735,  1561,  6077,
    3048,  1563,   409,  1738,  1454,   409,  1739,   409,  1740,  1454,
    1663,   546,   546,  1742,  1743,   546,  1746, -1251,   313, -1251,
    1749,  1766,   109, -1251,  1592,   671,   112, -1251,  1596,   219,
   -1251,  1608,  1610,  1612,  1611,  1624, -1251, -1251,  1631,  1632,
     672, -1251,  1629, -1251,  1623,  1784,   409,  1454,  1789,  1790,
     409,  1803,   409,  1728,  2146,   546,  1454,  1808,  1810,   313,
    1811,   313,  1812, -1251,   222,  1637, -1251, -1251,   249, -1251,
     255,  1639,  4134,  1641,  1642, -1251, -1251, -1251, -1251,   675,
   -1251, -1251,  1817,  1818,  1819,  1820,  2146,  2146,   546,  1454,
     313,  1821, -1251, -1251, -1251, -1251,  4158,  3074,  1650,  1652,
   -1251, -1251,  2146,  1827,  1454,   546,  3100, -1251,  1655,  1662,
    1830,  1454,  1832, -1251,  1660, -1251,  1454,  1667,  1454,  1669,
     546,  1670,  1835, -1251
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1251,
   -1251,  1215, -1251,   548, -1251, -1251, -1251, -1251, -1251, -1251,
   -1251, -1251, -1251, -1251, -1251, -1251,  -307,     2, -1251,  1846,
      -1,  -369,  -180,     4, -1251, -1251, -1251, -1251, -1251,  1847,
   -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1251, -1101,
   -1250, -1251, -1251,  -837,   -20, -1251,   180, -1251,   -86, -1251,
   -1091, -1006,   518,  -247,  -332,  -703,   875, -1251,   -66
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -49
static const short yytable[] =
{
     145,   214,   216,    74,   505,   249,   566,   381,    75,   849,
     386,   639,  1315,   186,   189,   541,  1315,   212,   205,  1315,
     202,   639,   144,   157,   254,   711,  1134,  1135,   212,   394,
     149,   200,   986,   405,   988,   407,   155,   383,   155,   384,
     212,     7,  1210,   372,   373,     5,   121,   122,   123,   124,
     372,   373,   125,   372,   373,  1043,  1260,   121,   122,   123,
     124,  1261,   501,   125,     6,  1052,   985,   557,  1191,   121,
     122,   123,   124,    96,   526,   125,   578,   579,   987,   527,
     989,   175,   176,   640,   641,   642,   643,   256,   311,   257,
     372,   373,   177,   640,   641,   642,   643,    84,  1260,   178,
     501,   137,   138,  1261,  1266,   152,  1269,  1017,   812,  1018,
     372,   373,   758,    85,   304,   305,   306,   159,   395,   307,
     310,   631,    86,   315,   761,  1192,   632,  1019,  1279,  1020,
     335,    87,   336,   337,   338,  1032,   340,   760,   342,   343,
      88,   354,  1033,   156,   979,   156,   329,   330,   331,   258,
     759,   259,  1315,   260,   332,   261,  1315,   370,   371,  1315,
     201,    89,     8,     9,    10,    11,    12,    13,    14,    15,
    1314,  1260,   312,   313,  1244,    90,  1261,  1260,   392,   393,
    1260,   396,  1261,   398,   151,  1261,   401,   402,   206,   644,
     187,   190,    91,   213,  1315,   717,   705,   203,  1315,   952,
    1315,   255,   712,    92,   215,   150,   137,   138,   731,   385,
     148,  1152,  1318,   812,   152,   130,   131,   132,   133,   594,
    1161,   179,   181,   372,   373,   372,   373,  1168,   262,   153,
     263,   444,   491,   492,   493,   494,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,  1090,    96,
     501,  1402,   372,   373,  1406,  1321,  1409,  1260,   154,   500,
    1260,  1425,  1261,   501,  1429,  1261,   840,   157,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   506,   264,  1140,   265,  1260,   212,   532,
     158,   534,  1261,  1260,   159,  1444,   305,   500,  1261,  1448,
     266,  1450,   267,   372,   373,   545,   546,   547,   160,   549,
     550,   551,   552,   553,   554,   555,   161,   121,   122,   123,
     124,   374,   193,   125,   367,   194,   369,   568,   569,   570,
     571,   694,   376,   832,   162,   581,   695,   372,   373,   585,
     586,   372,   373,   562,   562,   590,   490,   212,   565,   565,
     841,   842,   163,  1280,   598,   375,   853,  1284,  1021,   164,
    1022,   702,   372,   373,   372,   373,   863,   168,   504,   372,
     373,  1431,   372,   373,  1462,   174,   121,   122,   123,   124,
     638,   567,   125,   372,   373,   969,   884,   137,   138,  1202,
     702,   130,   131,   132,   133,   173,   892,   893,   894,   895,
    1204,  1464,   874,   268,   446,   269,   191,  1465,   707,   182,
     372,   373,   188,   137,   138,   192,  1175,   637,   501,  1211,
     704,  1176,  1002,  1003,  1077,   838,   910,  1206,   372,   373,
     318,   319,   320,   195,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,  1311,   700,  1260,   196,   305,
     332,   501,  1261,   875,  1248,   708,   372,   373,   270,  1141,
     271,  1365,  1366,  1367,  1368,  1011,  1012,   973,  1372,   372,
     373,   165,   166,  1317,   167,   706,   183,   500,   718,   184,
     185,   501,   501,   501,   501,   197,  1320,   700,   729,   272,
     500,   273,   733,   734,   137,   138,   198,   208,   739,   251,
     199,   252,   972,   974,   996,   274,   207,   275,   749,   750,
     130,   131,   132,   133,   137,   138,   209,   753,   276,   496,
     277,   252,   560,   561,  1414,  1415,   210,   211,  1418,   762,
     247,   250,   137,   138,   327,   328,   329,   330,   331,   278,
     814,   279,   298,   774,   332,   776,   777,   542,   299,   318,
     319,   320,   300,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   280,   282,   281,   283,  1453,   332,
     314,   318,   319,   320,   316,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   317,   137,   138,   501,
     333,   332,   537,   911,   252,   301,   302,   137,   138,   334,
     833,  1478,   730,   510,   252,   284,   339,   285,   813,   130,
     131,   132,   133,   286,   288,   287,   289,  1117,  1489,   290,
     341,   291,   822,   823,   846,   936,   937,   938,   939,   940,
     355,   137,   138,  1501,   359,   356,   824,   825,   826,   827,
     828,   829,   830,   357,   292,   500,   293,   360,   352,   834,
     361,   362,   837,   358,   363,   843,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   852,   294,   296,   295,   297,
     332,   366,    40,    41,    42,    43,   382,    45,   500,   364,
     700,   387,   388,   365,   377,    51,    52,   692,   378,   693,
     869,   379,   318,   319,   320,   949,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   748,   500,   500,
     500,   500,   332,   169,   898,   899,   170,   171,   391,   172,
     904,   702,   702,   703,   732,   702,   981,   867,   982,   380,
     914,   915,   389,   318,   319,   320,   390,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   397,   400,
     318,   319,   320,   332,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   403,   399,   954,   955,   404,
     332,   318,   319,   320,   406,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   702,   702,   995,  1023,
     702,   332,  1024,   702,   702,  1025,  1026,  1077,   980,  1078,
    1252,   702,   408,  1097,   984,   409,  1181,   813,  1182,  1077,
     410,  1212,   975,  1077,   411,  1303,   500,  1181,   997,  1377,
     998,  1427,  1439,  1428,  1440,  1470,   412,  1471,   413,   414,
     415,   416,   439,   417,  1013,  1014,  1015,   318,   319,   320,
     418,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   419,   420,   421,   422,   423,   332,  1036,  1037,
    1038,   424,   425,   426,   427,   428,   429,   430,   431,   855,
     432,   433,   434,    93,   303,   435,   436,  1083,   437,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,  1074,   888,   889,   890,   438,  1080,   441,
     442,   443,   445,   332,   498,   896,  1112,   495,   508,   507,
     509,   543,  1071,   538,  1084,   548,   556,   580,   589,   583,
     584,   592,   916,   595,   601,   602,   603,   604,   605,   606,
     607,   925,   608,   624,   978,   609,   610,   611,   612,   613,
     614,   615,  1102,  1103,  1174,   616,   617,   618,   619,   620,
     629,  1186,  1111,   621,   622,   623,   625,   626,   627,   628,
     630,   633,   126,   127,   128,   129,   634,  1131,  1132,   635,
     696,   697,   698,   699,   709,   562,   701,   710,   714,  1143,
     565,  1145,   716,   747,   719,   720,   721,   723,   725,   726,
     735,  1155,   751,   752,   764,   765,   768,   769,  1162,  1163,
    1164,   770,   772,   773,   779,  1169,   780,   809,   781,  1173,
     782,   783,   821,   831,   784,  1177,  1178,   785,   786,   787,
     788,   789,   790,   134,   135,   791,   792,   793,   794,   136,
     795,  1190,   796,   797,   139,   798,   799,   308,  1194,   142,
     819,   309,   800,   801,   802,   803,   804,   805,   806,   807,
     808,   810,   318,   319,   320,  1200,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   811,   817,   818,
     836,   844,   332,   839,   845,   913,   847,   851,  1215,   848,
    1216,   318,   319,   320,   858,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   860,   870,   318,   319,
     320,   332,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   871,   872,   873,  1241,   876,   332,   877,
     878,  1245,   879,   880,   881,   882,   883,  1092,   905,  1093,
     891,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,  1258,   897,  1264,   900,  1267,   332,  1270,  1271,
     901,   907,   912,   917,  1274,   918,   919,  1118,   562,  1121,
     920,  1124,  1282,   565,  1195,   921,   924,   926,   927,   930,
    1290,   931,   932,   933,   934,  1295,   943,   944,  1298,   945,
     946,   947,  1301,  1302,   950,   948,   953,   951,   958,   968,
    1305,   970,   977,  1308,   983,   304,   305,  1309,   856,   857,
     976,   859,   991,   861,   862,    93,   303,   993,  1016,   994,
    1029,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,  1030,  1035,  1039,  1040,  1044,
    1080,  1045,  1046,  1048,  1072,  1047,   902,   903,  1049,  1085,
     906,  1349,  1086,  1054,  1050,  1051,  1053,  1354,  1055,  1056,
    1358,  1057,  1058,  1088,  1059,  1060,   922,   923,  1061,  1062,
    1063,  1064,   928,   929,  1068,  1065,  1066,  1067,  1069,   935,
    1070,   942,  1379,  1081,  1380,  1094,  1095,  1099,  1096,   318,
     319,   320,  1421,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   126,   127,   128,   129,  1100,   332,
    1101,   318,   319,   320,  1104,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,  1105,  1106,  1107,  1108,
    1109,   332,  1110,  1457,  1119,  1460,   990,  1122,   992,  1125,
    1127,  1128,  1259,  1196,  1265,  1129,  1268,  1130,  1136,   999,
    1000,  1001,  1133,  1144,  1004,  1005,  1006,  1007,  1008,  1009,
    1010,  1147,  1148,  1149,  1480,   134,   135,  1151,  1153,  1154,
    1150,   136,  1180,  1156,  1452,  1197,   139,  1157,  1158,   727,
    1160,   142,   320,   728,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,  1159,   369,  1166,  1167,  1170,
     332,  1171,  1189,  1172,  1183,  1326,  1476,  1477,  1184,  1185,
    1193,  1187,  1188,  1198,  1201,  1199,  1203,    93,   344,  1218,
    1205,  1207,  1486,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,  1213,  1214,  1220,
    1082,  1221,   318,   319,   320,   345,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,  1222,  1223,  1224,
    1226,  1227,   332,  1228,  1232,    40,    41,    42,    43,    44,
      45,   736,  1233,  1236,  1234,  1237,  1239,  1246,    51,    52,
     318,   319,   320,  1247,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,  1249,  1272,  1278,  1281,  1283,
     332,  1286,  1285,  1137,  1296,  1287,   126,   127,   128,   129,
    1146,  1288,   318,   319,   320,  1289,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,  1291,  1293,  1165,
    1294,  1297,   332,  1299,  1300,  1304,  1306,  1307,  1312,  1313,
    1332,  1324,   318,   319,   320,  1179,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   596,  1325,  1327,
    1328,  1343,   332,  1329,  1330,  1347,  1333,   134,   346,  1351,
    1352,  1355,  1356,   136,  1337,  1335,  1359,  1376,   139,   715,
    1339,  1345,  1360,   142,  1361,   347,  1364,    93,   303,  1369,
    1384,  1370,  1371,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,  1373,    93,   539,
    1374,  1382,  1375,  1381,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,  1385,  1387,
      93,   303,  1389,  1393,  1391,  1390,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
    1392,  1273,  1394,  1395,   868,  1277,   126,   127,   128,   129,
    1396,  1397,  1398,  1401,  1403,  1407,  1410,  1413,  1416,  1417,
    1292,  1419,   318,   319,   320,  1423,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   126,   127,   128,
     129,  1424,   332,  1426,   318,   319,   320,  1430,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,  1432,
    1443,  1435,  1433,  1434,   332,  1446,  1447,   134,   135,   126,
     127,   128,   129,   136,  1436,  1442,  1437,  1438,   139,  1449,
    1441,   865,  1451,   142,  1455,   866,  1456,  1458,  1461,  1463,
    1466,  1468,  1469,  1472,  1473,  1474,  1475,  1481,   134,   135,
    1484,  1350,  1485,  1487,   136,  1491,  1493,  1492,  1495,   139,
    1496,  1503,  1362,  1363,   142,  1502,   540,  1498,  1340,  1500,
      73,    81,  1087,   815,     0,     0,     0,     0,     0,     0,
    1255,  1256,     0,     0,     0,     0,   136,     0,     0,     0,
       0,  1257,   909,     0,     0,     0,   142,     0,   178,   318,
     319,   320,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,     0,  1405,     0,    93,    94,    95,  1412,    96,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,     0,   121,   122,   123,   124,     0,
       0,   125,     0,     0,     0,  1445,     0,     0,     0,     0,
       0,     0,     0,     0,  1454,     0,     0,    93,   303,   212,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,  1479,   121,   122,
     123,   124,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,  1488,   126,   127,   128,   129,     0,     0,  1494,
       0,     0,     0,     0,  1497,     0,  1499,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,   318,   319,   320,   332,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
     130,   131,   132,   133,   332,     0,   126,   127,   128,   129,
       0,  1115,     0,  1116,   134,   135,     0,     0,     0,     0,
     136,     0,   137,   138,     0,   139,     0,   140,     0,   141,
     142,    93,   344,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,     0,     0,     0,     0,     0,     0,   134,   135,   345,
       0,     0,     0,   136,     0,     0,     0,     0,   139,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,    40,
      41,    42,    43,    44,    45,     0,     0,     0,     0,    93,
     303,     0,    51,    52,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     0,
     126,   127,   128,   129,    93,   539,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   572,    25,    26,   573,   574,    29,   575,
      31,     0,    32,     0,    34,    35,     0,    37,    38,     0,
       0,   134,   499,     0,     0,     0,     0,   136,   126,   127,
     128,   129,   139,     0,    50,     0,     0,   142,     0,     0,
       0,     0,     0,    54,    55,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,     0,   126,   127,   128,   129,     0,   572,    25,
      26,   573,   574,    29,   575,    31,     0,    32,     0,    34,
      35,     0,    37,    38,     0,     0,     0,     0,     0,   134,
     135,     0,     0,     0,     0,   136,     0,     0,     0,    50,
     139,     0,     0,     0,     0,   142,     0,     0,    54,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,    66,     0,     0,     0,
     136,     0,     0,     0,     0,   139,     0,     0,     0,     0,
     142,     0,     0,     0,   576,   572,    25,    26,   573,   574,
      29,   575,    31,     0,    32,     0,    34,    35,     0,    37,
      38,     0,     0,     0,     0,     0,   572,    25,    26,   573,
     574,    29,   575,    31,     0,    32,    50,    34,    35,     0,
      37,    38,     0,     0,     0,    54,    55,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,    66,     0,     0,    54,    55,    56,   582,
       0,   572,    25,    26,   573,   574,    29,   575,    31,     0,
      32,     0,    34,    35,    66,    37,    38,     0,     0,    -5,
       1,     0,    -5,   -48,     0,     0,     0,     0,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    55,    56,     0,     0,     0,     0,     0,     0,
       0,     0,   -48,     0,     0,     0,     0,   -48,   -48,    66,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   599,     0,     0,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,   -48,
     -48,   -48,   217,   -48,   -48,     0,     0,   600,     0,   -48,
     -48,   -48,   -48,     0,     0,     0,     0,   -48,     0,   -48,
       0,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   775,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,     0,     0,     0,   218,   219,   220,     0,     0,     0,
       0,     0,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,    20,     0,     0,     0,     0,     0,     0,     0,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,   241,   242,   243,   244,   245,   246,     0,     0,     0,
       0,    21,     0,     0,     0,     0,    22,    23,     0,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,     0,     0,     0,    39,    40,
      41,    42,    43,    44,    45,     0,    46,    47,    48,    49,
      50,     0,    51,    52,     0,     0,     0,     0,    53,    54,
      55,    56,     0,     0,     0,     0,    57,     0,    58,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     572,    25,    26,   573,   574,    29,   575,    31,     0,    32,
       0,    34,    35,     0,    37,    38,   318,   319,   320,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,    50,     0,     0,     0,     0,   332,     0,     0,     0,
      54,    55,    56,  1138,     0,  1139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   318,   319,   320,    66,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,     0,     0,     0,
       0,     0,  1253,     0,  1254,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,     0,     0,     0,
       0,   318,   319,   320,   740,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,     0,     0,     0,     0,   318,   319,   320,
     741,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,     0,
       0,     0,     0,   318,   319,   320,   864,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,     0,     0,     0,     0,   318,
     319,   320,   887,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,     0,     0,     0,     0,   318,   319,   320,  1113,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,     0,     0,     0,
       0,   318,   319,   320,  1275,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,     0,     0,     0,     0,   318,   319,   320,
    1276,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,     0,
       0,     0,     0,   318,   319,   320,  1310,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,     0,     0,     0,     0,   318,
     319,   320,  1316,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,     0,     0,     0,     0,   318,   319,   320,  1319,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,     0,     0,     0,
       0,   318,   319,   320,  1322,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,     0,     0,     0,     0,   318,   319,   320,
    1323,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,     0,
       0,     0,     0,   318,   319,   320,  1346,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,     0,     0,     0,     0,   318,
     319,   320,  1383,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,     0,     0,     0,     0,   318,   319,   320,  1386,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,     0,     0,     0,
       0,   318,   319,   320,  1388,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,     0,     0,     0,     0,   318,   319,   320,
    1400,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,     0,
       0,     0,     0,   318,   319,   320,  1483,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,     0,     0,     0,     0,   318,
     319,   320,  1490,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,   497,     0,   318,   319,   320,   558,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,     0,     0,   318,   319,   320,
     528,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,     0,
       0,   318,   319,   320,   558,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,     0,     0,   318,   319,   320,   559,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,     0,     0,   318,
     319,   320,   593,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,     0,     0,   318,   319,   320,   672,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,     0,     0,   318,   319,   320,
     673,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,     0,
       0,   318,   319,   320,   686,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,     0,     0,   318,   319,   320,   687,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,     0,     0,   318,
     319,   320,   688,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,     0,     0,   318,   319,   320,   689,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,     0,     0,   318,   319,   320,
     690,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,     0,
       0,   318,   319,   320,   691,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,     0,     0,   318,   319,   320,   754,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,     0,     0,   318,
     319,   320,   755,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,     0,     0,   318,   319,   320,   756,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,     0,     0,   318,   319,   320,
     854,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,     0,
       0,   318,   319,   320,   885,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,     0,     0,   318,   319,   320,   886,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,     0,     0,   318,
     319,   320,   908,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,     0,     0,   318,   319,   320,  1027,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,     0,     0,   318,   319,   320,
    1028,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,     0,
       0,   318,   319,   320,  1041,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,     0,     0,   318,   319,   320,  1042,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,     0,     0,   318,
     319,   320,  1075,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,     0,     0,   318,   319,   320,  1076,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,     0,     0,   318,   319,   320,
    1091,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,     0,
       0,   318,   319,   320,  1098,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,     0,     0,   318,   319,   320,  1208,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,     0,     0,   318,
     319,   320,  1209,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,     0,     0,   318,   319,   320,  1217,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,     0,     0,   318,   319,   320,
    1219,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,     0,
       0,   318,   319,   320,  1230,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,     0,     0,   318,   319,   320,  1235,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,     0,     0,   318,
     319,   320,  1238,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,     0,     0,   318,   319,   320,  1242,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,     0,     0,   318,   319,   320,
    1243,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,     0,
       0,   318,   319,   320,  1250,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,     0,     0,   318,   319,   320,  1251,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,     0,     0,   318,
     319,   320,  1331,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,     0,     0,   318,   319,   320,  1342,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,     0,     0,   318,   319,   320,
    1344,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,     0,
       0,   318,   319,   320,  1467,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,     0,     0,   318,   319,   320,  1482,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,   318,   319,   320,   503,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,   318,   319,   320,
     636,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,   318,   319,
     320,   651,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,   318,
     319,   320,   653,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
     318,   319,   320,   655,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,   318,   319,   320,   657,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,   318,   319,   320,   659,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,   318,   319,   320,   661,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,   318,   319,   320,   663,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,   318,   319,   320,   665,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,   318,   319,   320,   667,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,   318,   319,   320,
     669,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,   318,   319,
     320,   671,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,   318,
     319,   320,   675,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
     318,   319,   320,   677,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,   318,   319,   320,   679,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,   318,   319,   320,   681,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,   318,   319,   320,   683,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,   318,   319,   320,   685,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,   318,   319,   320,   757,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,   318,   319,   320,   763,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,   318,   319,   320,
     766,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,   318,   319,
     320,   767,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,   318,
     319,   320,   835,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
     318,   319,   320,   960,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,   318,   319,   320,   962,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,   318,   319,   320,   964,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,   318,   319,   320,   966,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,   318,   319,   320,   967,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,   318,   319,   320,  1089,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,   497,   318,   319,
     320,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
     529,   318,   319,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,   530,   318,   319,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,   531,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,   533,
     318,   319,   320,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,   535,   318,   319,   320,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,   536,   318,   319,   320,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,   544,   318,
     319,   320,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,   587,   318,   319,   320,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,   588,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,   591,   318,   319,
     320,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
     597,   318,   319,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,   650,   318,   319,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,   652,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,   654,
     318,   319,   320,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,   656,   318,   319,   320,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,   658,   318,   319,   320,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,   660,   318,
     319,   320,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,   662,   318,   319,   320,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,   664,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,   666,   318,   319,
     320,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
     668,   318,   319,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,   670,   318,   319,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,   674,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,   676,
     318,   319,   320,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,   678,   318,   319,   320,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,   680,   318,   319,   320,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,   682,   318,
     319,   320,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,   684,   318,   319,   320,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,   722,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,   724,   318,   319,
     320,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
     737,   318,   319,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,   738,   318,   319,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,   742,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,   743,
     318,   319,   320,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,   744,   318,   319,   320,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,   745,   318,   319,   320,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,   746,   318,
     319,   320,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,   771,   318,   319,   320,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,   778,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,   959,   318,   319,
     320,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
     961,   318,   319,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,   963,   318,   319,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,   965,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,   971,
     318,   319,   320,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,  1031,   318,   319,   320,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,     0,     0,
       0,     0,     0,   332,     0,  1114,   318,   319,   320,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,     0,     0,   332,     0,  1142,   318,
     319,   320,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,     0,     0,     0,     0,   332,
       0,  1225,   318,   319,   320,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   332,     0,  1229,   318,   319,   320,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,     0,     0,   332,     0,  1231,   318,   319,
     320,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,     0,     0,     0,     0,     0,   332,     0,
    1334,   318,   319,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,     0,
       0,   332,     0,  1336,   318,   319,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,   332,     0,  1338,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,     0,     0,   332,     0,  1341,
     318,   319,   320,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,     0,     0,     0,     0,     0,
     332,     0,  1399
};

static const short yycheck[] =
{
      20,    67,    68,     4,   311,    91,   375,   187,     4,   712,
     190,     4,  1262,     4,     4,   347,  1266,     5,     4,  1269,
       4,     4,    20,    67,     4,     4,  1032,  1033,     5,    85,
       6,    45,     6,   213,     6,   215,    67,     4,    67,     6,
       5,     3,  1133,   163,   164,     6,    34,    35,    36,    37,
     163,   164,    40,   163,   164,   175,    68,    34,    35,    36,
      37,    73,   309,    40,     0,   175,     6,   180,     6,    34,
      35,    36,    37,     7,   175,    40,     6,     7,    52,   180,
      52,   163,   164,    76,    77,    78,    79,   174,     4,   176,
     163,   164,   174,    76,    77,    78,    79,     7,    68,   181,
     347,   171,   172,    73,  1205,   174,  1207,   180,   178,   182,
     163,   164,   181,     6,   134,   135,   136,   174,   174,   139,
     140,   175,     6,   143,   181,     6,   180,   180,  1219,   182,
     150,     6,   152,   153,   154,   174,   156,   181,   158,   159,
       6,   161,   181,   174,   847,   174,   165,   166,   167,   174,
     181,   176,  1402,   174,   173,   176,  1406,   177,   178,  1409,
     174,     6,   124,   125,   126,   127,   128,   129,   130,   131,
     182,    68,    88,    89,  1180,   174,    73,    68,   198,   199,
      68,   201,    73,   203,     6,    73,   206,   207,   174,   182,
     181,   181,   174,   181,  1444,   527,   503,   181,  1448,   182,
    1450,   181,   181,   174,   181,   181,   171,   172,   540,   176,
     174,  1048,   182,   178,   174,   149,   150,   151,   152,   399,
    1057,    41,    42,   163,   164,   163,   164,  1064,   174,   174,
     176,   251,   298,   299,   300,   301,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   981,     7,
     527,  1382,   163,   164,  1385,   182,  1387,    68,   174,   309,
      68,   182,    73,   540,   182,    73,     4,    67,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   311,   174,     8,   176,    68,     5,   339,
     174,   341,    73,    68,   174,  1426,   346,   347,    73,  1430,
     174,  1432,   176,   163,   164,   355,   356,   357,    49,   359,
     360,   361,   362,   363,   364,   365,   174,    34,    35,    36,
      37,   181,    41,    40,   174,    44,   176,   377,   378,   379,
     380,   175,   182,   695,    45,   385,   180,   163,   164,   389,
     390,   163,   164,   374,   375,   395,     4,     5,   374,   375,
      88,    89,    45,  1220,   404,   181,   175,  1224,   180,    45,
     182,   180,   163,   164,   163,   164,   728,    47,     7,   163,
     164,   182,   163,   164,   182,   181,    34,    35,    36,    37,
     181,   180,    40,   163,   164,   175,   180,   171,   172,   180,
     180,   149,   150,   151,   152,   174,   758,   759,   760,   761,
     180,   182,     6,   174,   254,   176,     6,   182,   504,   181,
     163,   164,    45,   171,   172,     6,   175,   445,   695,   175,
     178,   180,    58,    59,   180,   702,     8,   180,   163,   164,
     153,   154,   155,     4,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   180,   496,    68,     4,   499,
     173,   728,    73,    57,  1187,   505,   163,   164,   174,   182,
     176,  1328,  1329,  1330,  1331,     6,     7,     7,  1335,   163,
     164,    44,    45,   180,    47,   503,    41,   527,   528,    44,
      45,   758,   759,   760,   761,     4,   180,   537,   538,   174,
     540,   176,   542,   543,   171,   172,   174,     6,   548,   176,
     174,   178,   839,   840,   866,   174,   174,   176,   558,   559,
     149,   150,   151,   152,   171,   172,     4,   567,   174,   176,
     176,   178,   372,   373,  1391,  1392,     4,    45,  1395,   579,
     174,     5,   171,   172,   163,   164,   165,   166,   167,   174,
     636,   176,   174,   593,   173,   595,   596,     8,   174,   153,
     154,   155,   174,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   174,   174,   176,   176,  1435,   173,
       4,   153,   154,   155,     6,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     6,   171,   172,   866,
       6,   173,   176,   175,   178,   174,   174,   171,   172,     5,
     696,  1468,   176,     6,   178,   174,   174,   176,   636,   149,
     150,   151,   152,   174,   174,   176,   176,  1016,  1485,   174,
     174,   176,   672,   673,     6,   109,   110,   111,   112,   113,
     181,   171,   172,  1500,   181,   174,   686,   687,   688,   689,
     690,   691,   692,   174,   174,   695,   176,   181,   160,   699,
     174,   174,   702,   165,   174,   705,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   715,   174,   174,   176,   176,
     173,     4,    61,    62,    63,    64,   188,    66,   728,   174,
     730,   193,   194,   174,   181,    74,    75,   176,   181,   178,
       6,   181,   153,   154,   155,   811,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   557,   758,   759,
     760,   761,   173,    41,   764,   765,    44,    45,     6,    47,
     770,   180,   180,   182,   182,   180,   180,   182,   182,   176,
     780,   781,   176,   153,   154,   155,   176,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   178,    91,
     153,   154,   155,   173,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,     6,   181,   817,   818,   174,
     173,   153,   154,   155,     6,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   180,   180,   182,   182,
     180,   173,   182,   180,   180,   182,   182,   180,   848,   182,
    1199,   180,     6,   182,   854,   174,   180,   835,   182,   180,
     174,   182,   840,   180,   174,   182,   866,   180,   868,   182,
     870,   180,   180,   182,   182,   180,   174,   182,   174,   174,
     174,   174,     5,   174,   884,   885,   886,   153,   154,   155,
     174,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   174,   174,   174,   174,   174,   173,   908,   909,
     910,   174,   174,   174,   174,   174,   174,   174,   174,   719,
     174,   174,   174,     3,     4,   174,   174,   973,   174,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   953,   754,   755,   756,   174,   958,   180,
     175,   180,     4,   173,     7,     6,  1012,     5,     7,   178,
     176,     7,   950,   181,   974,     7,   175,     6,    86,     7,
       7,    88,   782,   181,     5,     5,     5,     5,     5,     5,
       5,   791,     5,   142,     6,     5,     5,     5,     5,     5,
       5,     5,  1002,  1003,  1070,     5,     5,     5,     5,     5,
       3,     6,  1012,     5,     5,     5,     5,     5,     5,     5,
       5,     5,   102,   103,   104,   105,     6,  1027,  1028,     5,
     180,   175,   175,   180,     6,  1016,   498,     4,   177,  1039,
    1016,  1041,     6,   178,     7,     7,     7,     7,     7,     7,
       7,  1051,   182,   182,   181,   181,     7,     7,  1058,  1059,
    1060,   174,     7,   178,   180,  1065,   180,     5,   180,  1069,
     180,   180,     6,     4,   180,  1075,  1076,   180,   180,   180,
     180,   180,   180,   163,   164,   180,   180,   180,   180,   169,
     180,  1091,   180,   180,   174,   180,   180,   177,  1098,   179,
     181,   181,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   175,   153,   154,   155,  1115,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   180,   174,   174,
       6,     6,   173,   177,     6,     3,     7,     6,  1138,   176,
    1140,   153,   154,   155,     7,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     7,   181,   153,   154,
     155,   173,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,     7,     7,     7,  1176,     7,   173,     7,
       7,  1181,     7,     7,     7,     7,     4,   987,     7,   989,
       6,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,  1202,     6,  1204,     6,  1206,   173,  1208,  1209,
       6,     4,     7,     3,  1214,     3,   165,  1017,  1199,  1019,
       3,  1021,  1222,  1199,     6,     3,     3,     3,     3,     3,
    1230,     3,     3,     3,     3,  1235,     3,     5,  1238,     5,
       3,     3,  1242,  1243,     4,     6,   174,     6,   181,   175,
    1250,   175,     7,  1253,     6,  1255,  1256,  1257,   720,   721,
     178,   723,     6,   725,   726,     3,     4,     6,   181,     6,
       6,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     6,    87,   181,   180,   180,
    1300,   175,   180,   180,     6,   175,   768,   769,   175,     6,
     772,  1311,     4,   175,   180,   180,   180,  1317,   175,   180,
    1320,   180,   180,     6,   180,   180,   788,   789,   180,   175,
     180,   180,   794,   795,   175,   180,   180,   180,   180,   801,
     180,   803,  1342,   178,  1344,     6,     6,     6,   177,   153,
     154,   155,  1398,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   102,   103,   104,   105,     6,   173,
       6,   153,   154,   155,     6,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     6,     6,     6,     6,
       6,   173,     6,  1439,     6,  1441,   858,     6,   860,     6,
       6,     6,  1202,     6,  1204,     6,  1206,     6,    87,   871,
     872,   873,     7,     3,   876,   877,   878,   879,   880,   881,
     882,     6,     3,     6,  1470,   163,   164,     6,     6,     3,
     165,   169,   181,     6,  1434,     6,   174,     3,     6,   177,
       3,   179,   155,   181,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,     6,  1256,     6,     3,     3,
     173,     3,   178,     6,     4,     6,  1466,  1467,     6,     6,
     177,     7,     6,     6,   182,   181,   181,     3,     4,   175,
     181,   181,  1482,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,   181,    84,   180,
     972,   180,   153,   154,   155,    41,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   180,   175,   180,
     180,   175,   173,   175,   180,    61,    62,    63,    64,    65,
      66,   182,   175,   180,   175,   175,   180,     6,    74,    75,
     153,   154,   155,   175,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    89,    87,     6,     3,     6,
     173,     3,     6,  1035,     3,     6,   102,   103,   104,   105,
    1042,     6,   153,   154,   155,     6,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,     6,     6,  1061,
       6,     6,   173,     5,   181,     6,     5,   182,     6,   181,
     175,   181,   153,   154,   155,  1077,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,     8,   180,   182,
     180,     6,   173,   180,   180,     6,   175,   163,   164,     6,
       6,     6,     6,   169,   175,   180,     6,     5,   174,     8,
     180,   180,     6,   179,     6,   181,     6,     3,     4,     6,
     180,     6,     6,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     6,     3,     4,
       6,   181,     6,     5,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,   181,   181,
       3,     4,   180,   175,   180,   182,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
     180,  1213,   175,   180,     8,  1217,   102,   103,   104,   105,
     180,     6,   181,   180,     6,     6,     6,    84,     6,     6,
    1232,     5,   153,   154,   155,     6,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   102,   103,   104,
     105,     5,   173,   181,   153,   154,   155,   181,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   181,
       6,   180,   182,   181,   173,     6,     6,   163,   164,   102,
     103,   104,   105,   169,   180,   182,   175,   175,   174,     6,
     181,   177,    84,   179,     6,   181,     6,     6,     6,   182,
     181,   180,   180,     6,     6,     6,     6,     6,   163,   164,
     180,  1313,   180,     6,   169,   180,     6,   175,     6,   174,
     180,     6,  1324,  1325,   179,   175,   181,   180,  1300,   180,
       4,     4,   977,   638,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,
      -1,   174,     8,    -1,    -1,    -1,   179,    -1,   181,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,    -1,  1384,    -1,     3,     4,     5,  1389,     7,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,    37,    -1,
      -1,    40,    -1,    -1,    -1,  1427,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1436,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,  1469,    34,    35,
      36,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1484,   102,   103,   104,   105,    -1,    -1,  1491,
      -1,    -1,    -1,    -1,  1496,    -1,  1498,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,   153,   154,   155,   173,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
     149,   150,   151,   152,   173,    -1,   102,   103,   104,   105,
      -1,   180,    -1,   182,   163,   164,    -1,    -1,    -1,    -1,
     169,    -1,   171,   172,    -1,   174,    -1,   176,    -1,   178,
     179,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,   163,   164,    41,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,   174,    -1,
      -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,     3,
       4,    -1,    74,    75,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
     102,   103,   104,   105,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    -1,    52,    53,    -1,    55,    56,    -1,
      -1,   163,   164,    -1,    -1,    -1,    -1,   169,   102,   103,
     104,   105,   174,    -1,    72,    -1,    -1,   179,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,   102,   103,   104,   105,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    72,
     174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,   164,    99,    -1,    -1,    -1,
     169,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,   182,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    72,    52,    53,    -1,
      55,    56,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    81,    82,    83,   182,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    -1,    52,    53,    99,    55,    56,    -1,    -1,     0,
       1,    -1,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    38,    39,    99,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,   182,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    44,    74,    75,    -1,    -1,   182,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    88,    -1,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   182,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,    -1,
      -1,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    -1,    74,    75,    -1,    -1,    -1,    -1,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    88,    -1,    90,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      -1,    52,    53,    -1,    55,    56,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    72,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      81,    82,    83,   180,    -1,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,   155,    99,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,   180,    -1,   182,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,   153,   154,   155,   182,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,
     182,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    -1,    -1,   153,   154,   155,   182,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,   153,
     154,   155,   182,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,    -1,   153,   154,   155,   182,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,   153,   154,   155,   182,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,
     182,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    -1,    -1,   153,   154,   155,   182,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,   153,
     154,   155,   182,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,    -1,   153,   154,   155,   182,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,   153,   154,   155,   182,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,
     182,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    -1,    -1,   153,   154,   155,   182,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,   153,
     154,   155,   182,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,    -1,   153,   154,   155,   182,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,   153,   154,   155,   182,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,
     182,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    -1,    -1,   153,   154,   155,   182,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,   153,
     154,   155,   182,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,   175,    -1,   153,   154,   155,   180,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,
     180,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   153,   154,   155,   180,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,
     154,   155,   180,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   153,   154,   155,   180,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,
     180,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   153,   154,   155,   180,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,
     154,   155,   180,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   153,   154,   155,   180,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,
     180,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   153,   154,   155,   180,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,
     154,   155,   180,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   153,   154,   155,   180,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,
     180,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   153,   154,   155,   180,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,
     154,   155,   180,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   153,   154,   155,   180,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,
     180,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   153,   154,   155,   180,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,
     154,   155,   180,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   153,   154,   155,   180,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,
     180,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   153,   154,   155,   180,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,
     154,   155,   180,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   153,   154,   155,   180,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,
     180,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   153,   154,   155,   180,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,
     154,   155,   180,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   153,   154,   155,   180,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,
     180,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   153,   154,   155,   180,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   153,
     154,   155,   180,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   153,   154,   155,   180,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   153,   154,   155,
     180,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   153,   154,   155,   180,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   153,   154,   155,   180,   157,
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
      -1,    -1,   173,   153,   154,   155,   177,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,   173,   153,   154,   155,   177,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,   153,   154,   155,   177,   157,
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
     166,   167,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
     173,    -1,   175
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
       6,     6,   237,   237,     6,     6,     6,     6,     6,     6,
       6,   237,   251,   182,   175,   180,   182,   214,   239,     6,
     223,   239,     6,   226,   239,     6,   229,     6,     6,     6,
       6,   237,   237,     7,   244,   244,    87,   245,   180,   182,
       8,   182,   175,   237,     3,   237,   245,     6,     3,     6,
     165,     6,   236,     6,     3,   237,     6,     3,     6,     6,
       3,   236,   237,   237,   237,   245,     6,     3,   236,   237,
       3,     3,     6,   237,   241,   175,   180,   237,   237,   245,
     181,   180,   182,     4,     6,     6,     6,     7,     6,   178,
     237,     6,     6,   177,   237,     6,     6,     6,     6,   181,
     237,   182,   180,   181,   180,   181,   180,   181,   180,   180,
     243,   175,   182,   181,    84,   237,   237,   180,   175,   180,
     180,   180,   180,   175,   180,   175,   180,   175,   175,   175,
     180,   175,   180,   175,   175,   180,   180,   175,   180,   180,
     199,   237,   180,   180,   244,   237,     6,   175,   248,    89,
     180,   180,   214,   180,   182,   163,   164,   174,   237,   239,
      68,    73,   232,   233,   237,   239,   232,   237,   239,   232,
     237,   237,    87,   245,   237,   182,   182,   245,     6,   243,
     236,     3,   237,     6,   236,     6,     3,     6,     6,     6,
     237,     6,   245,     6,     6,   237,     3,     6,   237,     5,
     181,   237,   237,   182,     6,   237,     5,   182,   237,   237,
     182,   180,     6,   181,   182,   233,   182,   180,   182,   182,
     180,   182,   182,   182,   181,   180,     6,   182,   180,   180,
     180,   180,   175,   175,   175,   180,   175,   175,   175,   180,
     196,   175,   180,     6,   180,   180,   182,     6,   224,   237,
     245,     6,     6,   227,   237,     6,     6,   230,   237,     6,
       6,     6,   245,   245,     6,   236,   236,   236,   236,     6,
       6,     6,   236,     6,     6,     6,     5,   182,   202,   237,
     237,     5,   181,   182,   180,   181,   182,   181,   182,   180,
     182,   180,   180,   175,   175,   180,   180,     6,   181,   175,
     182,   180,   232,     6,   225,   245,   232,     6,   228,   232,
       6,   231,   245,    84,   236,   236,     6,     6,   236,     5,
     200,   251,   205,     6,     5,   182,   181,   180,   182,   182,
     181,   182,   181,   182,   181,   180,   180,   175,   175,   180,
     182,   181,   182,     6,   232,   245,     6,     6,   232,     6,
     232,    84,   237,   236,   245,     6,     6,   251,     6,   203,
     251,     6,   182,   182,   182,   182,   181,   180,   180,   180,
     180,   182,     6,     6,     6,     6,   237,   237,   236,   245,
     251,     6,   180,   182,   180,   180,   237,     6,   245,   236,
     182,   180,   175,     6,   245,     6,   180,   245,   180,   245,
     180,   236,   175,     6
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
      else{
	yymsg(GERROR, "Unknown command 'Delete %s'", yyvsp[-1].c);
      }
      Free(yyvsp[-1].c);
    ;}
    break;

  case 164:
#line 1860 "Gmsh.y"
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
#line 1879 "Gmsh.y"
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
#line 1893 "Gmsh.y"
    {
      int m = (CTX.visibility_mode == 2) ? VIS_MESH : 
	((CTX.visibility_mode == 1) ? VIS_GEOM : VIS_GEOM|VIS_MESH);
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber(yyvsp[-1].c, i, m);
      Free(yyvsp[-1].c);
    ;}
    break;

  case 167:
#line 1901 "Gmsh.y"
    {
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber(yyvsp[-1].c, i, 0);
      Free(yyvsp[-1].c);
    ;}
    break;

  case 168:
#line 1907 "Gmsh.y"
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
#line 1918 "Gmsh.y"
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
#line 1932 "Gmsh.y"
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
#line 1976 "Gmsh.y"
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
#line 1991 "Gmsh.y"
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
#line 2007 "Gmsh.y"
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
#line 2017 "Gmsh.y"
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
#line 2039 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 176:
#line 2043 "Gmsh.y"
    {
      SetBoundingBox();
    ;}
    break;

  case 177:
#line 2047 "Gmsh.y"
    {
      SetBoundingBox(yyvsp[-12].d, yyvsp[-10].d, yyvsp[-8].d, yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 178:
#line 2051 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      if(!CTX.batch) // we're in interactive mode
	Draw();
#endif
    ;}
    break;

  case 179:
#line 2064 "Gmsh.y"
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
#line 2079 "Gmsh.y"
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
#line 2095 "Gmsh.y"
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
#line 2121 "Gmsh.y"
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
#line 2148 "Gmsh.y"
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
#line 2180 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction(yyvsp[0].c, yyin, yyname, yylineno))
	yymsg(GERROR, "Redefinition of function %s", yyvsp[0].c);
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 185:
#line 2187 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin, yyname, yylineno))
	yymsg(GERROR, "Error while exiting function");
    ;}
    break;

  case 186:
#line 2192 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction(yyvsp[-1].c, &yyin, yyname, yylineno))
	yymsg(GERROR, "Unknown function %s", yyvsp[-1].c);
      //FIXME: wee leak $2
    ;}
    break;

  case 187:
#line 2198 "Gmsh.y"
    {
      if(!yyvsp[-1].d) skip_until("If", "EndIf");
    ;}
    break;

  case 188:
#line 2202 "Gmsh.y"
    {
    ;}
    break;

  case 189:
#line 2213 "Gmsh.y"
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
#line 2229 "Gmsh.y"
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
#line 2245 "Gmsh.y"
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
#line 2261 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 193:
#line 2266 "Gmsh.y"
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
#line 2282 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 195:
#line 2287 "Gmsh.y"
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
#line 2303 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 197:
#line 2308 "Gmsh.y"
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
#line 2326 "Gmsh.y"
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
#line 2349 "Gmsh.y"
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
#line 2372 "Gmsh.y"
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
#line 2395 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 202:
#line 2400 "Gmsh.y"
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
#line 2423 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 204:
#line 2428 "Gmsh.y"
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
#line 2451 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 206:
#line 2456 "Gmsh.y"
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
#line 2482 "Gmsh.y"
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
#line 2505 "Gmsh.y"
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
#line 2528 "Gmsh.y"
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
#line 2551 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 211:
#line 2556 "Gmsh.y"
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
#line 2579 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 213:
#line 2585 "Gmsh.y"
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
#line 2608 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 215:
#line 2614 "Gmsh.y"
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
#line 2640 "Gmsh.y"
    {
    ;}
    break;

  case 217:
#line 2643 "Gmsh.y"
    {
    ;}
    break;

  case 218:
#line 2649 "Gmsh.y"
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
#line 2675 "Gmsh.y"
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
#line 2699 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 221:
#line 2708 "Gmsh.y"
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
#line 2726 "Gmsh.y"
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
#line 2744 "Gmsh.y"
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
#line 2762 "Gmsh.y"
    {
      Surface *s = FindSurface((int)yyvsp[-4].d, THEM);
      if(!s)
	yymsg(WARNING, "Unknown surface %d", (int)yyvsp[-4].d);
      else{
	s->Method = TRANSFINI;
	int k = List_Nbr(yyvsp[-1].l);
	if(k != 3 && k != 4){
	  yymsg(GERROR, "Wrong definition of Transfinite Surface %d: "
		"%d points instead of 3 or 4" , (int)yyvsp[-4].d, k);
	}
	else{
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
#line 2789 "Gmsh.y"
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

  case 226:
#line 2815 "Gmsh.y"
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

  case 227:
#line 2841 "Gmsh.y"
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

  case 228:
#line 2855 "Gmsh.y"
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

  case 229:
#line 2874 "Gmsh.y"
    { 
      ReplaceAllDuplicates(THEM);
    ;}
    break;

  case 230:
#line 2878 "Gmsh.y"
    { 
      IntersectAllSegmentsTogether();
    ;}
    break;

  case 231:
#line 2887 "Gmsh.y"
    {yyval.i = 1;;}
    break;

  case 232:
#line 2888 "Gmsh.y"
    {yyval.i = 0;;}
    break;

  case 233:
#line 2889 "Gmsh.y"
    {yyval.i = -1;;}
    break;

  case 234:
#line 2890 "Gmsh.y"
    {yyval.i = -1;;}
    break;

  case 235:
#line 2891 "Gmsh.y"
    {yyval.i = -1;;}
    break;

  case 236:
#line 2895 "Gmsh.y"
    { yyval.d = yyvsp[0].d;           ;}
    break;

  case 237:
#line 2896 "Gmsh.y"
    { yyval.d = yyvsp[-1].d;           ;}
    break;

  case 238:
#line 2897 "Gmsh.y"
    { yyval.d = -yyvsp[0].d;          ;}
    break;

  case 239:
#line 2898 "Gmsh.y"
    { yyval.d = yyvsp[0].d;           ;}
    break;

  case 240:
#line 2899 "Gmsh.y"
    { yyval.d = !yyvsp[0].d;          ;}
    break;

  case 241:
#line 2900 "Gmsh.y"
    { yyval.d = yyvsp[-2].d - yyvsp[0].d;      ;}
    break;

  case 242:
#line 2901 "Gmsh.y"
    { yyval.d = yyvsp[-2].d + yyvsp[0].d;      ;}
    break;

  case 243:
#line 2902 "Gmsh.y"
    { yyval.d = yyvsp[-2].d * yyvsp[0].d;      ;}
    break;

  case 244:
#line 2904 "Gmsh.y"
    { 
      if(!yyvsp[0].d)
	yymsg(GERROR, "Division by zero in '%g / %g'", yyvsp[-2].d, yyvsp[0].d);
      else
	yyval.d = yyvsp[-2].d / yyvsp[0].d;     
    ;}
    break;

  case 245:
#line 2910 "Gmsh.y"
    { yyval.d = (int)yyvsp[-2].d % (int)yyvsp[0].d;  ;}
    break;

  case 246:
#line 2911 "Gmsh.y"
    { yyval.d = pow(yyvsp[-2].d, yyvsp[0].d);  ;}
    break;

  case 247:
#line 2912 "Gmsh.y"
    { yyval.d = yyvsp[-2].d < yyvsp[0].d;      ;}
    break;

  case 248:
#line 2913 "Gmsh.y"
    { yyval.d = yyvsp[-2].d > yyvsp[0].d;      ;}
    break;

  case 249:
#line 2914 "Gmsh.y"
    { yyval.d = yyvsp[-2].d <= yyvsp[0].d;     ;}
    break;

  case 250:
#line 2915 "Gmsh.y"
    { yyval.d = yyvsp[-2].d >= yyvsp[0].d;     ;}
    break;

  case 251:
#line 2916 "Gmsh.y"
    { yyval.d = yyvsp[-2].d == yyvsp[0].d;     ;}
    break;

  case 252:
#line 2917 "Gmsh.y"
    { yyval.d = yyvsp[-2].d != yyvsp[0].d;     ;}
    break;

  case 253:
#line 2918 "Gmsh.y"
    { yyval.d = yyvsp[-2].d && yyvsp[0].d;     ;}
    break;

  case 254:
#line 2919 "Gmsh.y"
    { yyval.d = yyvsp[-2].d || yyvsp[0].d;     ;}
    break;

  case 255:
#line 2920 "Gmsh.y"
    { yyval.d = yyvsp[-4].d? yyvsp[-2].d : yyvsp[0].d;  ;}
    break;

  case 256:
#line 2921 "Gmsh.y"
    { yyval.d = exp(yyvsp[-1].d);      ;}
    break;

  case 257:
#line 2922 "Gmsh.y"
    { yyval.d = log(yyvsp[-1].d);      ;}
    break;

  case 258:
#line 2923 "Gmsh.y"
    { yyval.d = log10(yyvsp[-1].d);    ;}
    break;

  case 259:
#line 2924 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-1].d);     ;}
    break;

  case 260:
#line 2925 "Gmsh.y"
    { yyval.d = sin(yyvsp[-1].d);      ;}
    break;

  case 261:
#line 2926 "Gmsh.y"
    { yyval.d = asin(yyvsp[-1].d);     ;}
    break;

  case 262:
#line 2927 "Gmsh.y"
    { yyval.d = cos(yyvsp[-1].d);      ;}
    break;

  case 263:
#line 2928 "Gmsh.y"
    { yyval.d = acos(yyvsp[-1].d);     ;}
    break;

  case 264:
#line 2929 "Gmsh.y"
    { yyval.d = tan(yyvsp[-1].d);      ;}
    break;

  case 265:
#line 2930 "Gmsh.y"
    { yyval.d = atan(yyvsp[-1].d);     ;}
    break;

  case 266:
#line 2931 "Gmsh.y"
    { yyval.d = atan2(yyvsp[-3].d, yyvsp[-1].d);;}
    break;

  case 267:
#line 2932 "Gmsh.y"
    { yyval.d = sinh(yyvsp[-1].d);     ;}
    break;

  case 268:
#line 2933 "Gmsh.y"
    { yyval.d = cosh(yyvsp[-1].d);     ;}
    break;

  case 269:
#line 2934 "Gmsh.y"
    { yyval.d = tanh(yyvsp[-1].d);     ;}
    break;

  case 270:
#line 2935 "Gmsh.y"
    { yyval.d = fabs(yyvsp[-1].d);     ;}
    break;

  case 271:
#line 2936 "Gmsh.y"
    { yyval.d = floor(yyvsp[-1].d);    ;}
    break;

  case 272:
#line 2937 "Gmsh.y"
    { yyval.d = ceil(yyvsp[-1].d);     ;}
    break;

  case 273:
#line 2938 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 274:
#line 2939 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 275:
#line 2940 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-3].d*yyvsp[-3].d+yyvsp[-1].d*yyvsp[-1].d); ;}
    break;

  case 276:
#line 2941 "Gmsh.y"
    { yyval.d = yyvsp[-1].d*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 277:
#line 2943 "Gmsh.y"
    { yyval.d = exp(yyvsp[-1].d);      ;}
    break;

  case 278:
#line 2944 "Gmsh.y"
    { yyval.d = log(yyvsp[-1].d);      ;}
    break;

  case 279:
#line 2945 "Gmsh.y"
    { yyval.d = log10(yyvsp[-1].d);    ;}
    break;

  case 280:
#line 2946 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-1].d);     ;}
    break;

  case 281:
#line 2947 "Gmsh.y"
    { yyval.d = sin(yyvsp[-1].d);      ;}
    break;

  case 282:
#line 2948 "Gmsh.y"
    { yyval.d = asin(yyvsp[-1].d);     ;}
    break;

  case 283:
#line 2949 "Gmsh.y"
    { yyval.d = cos(yyvsp[-1].d);      ;}
    break;

  case 284:
#line 2950 "Gmsh.y"
    { yyval.d = acos(yyvsp[-1].d);     ;}
    break;

  case 285:
#line 2951 "Gmsh.y"
    { yyval.d = tan(yyvsp[-1].d);      ;}
    break;

  case 286:
#line 2952 "Gmsh.y"
    { yyval.d = atan(yyvsp[-1].d);     ;}
    break;

  case 287:
#line 2953 "Gmsh.y"
    { yyval.d = atan2(yyvsp[-3].d, yyvsp[-1].d);;}
    break;

  case 288:
#line 2954 "Gmsh.y"
    { yyval.d = sinh(yyvsp[-1].d);     ;}
    break;

  case 289:
#line 2955 "Gmsh.y"
    { yyval.d = cosh(yyvsp[-1].d);     ;}
    break;

  case 290:
#line 2956 "Gmsh.y"
    { yyval.d = tanh(yyvsp[-1].d);     ;}
    break;

  case 291:
#line 2957 "Gmsh.y"
    { yyval.d = fabs(yyvsp[-1].d);     ;}
    break;

  case 292:
#line 2958 "Gmsh.y"
    { yyval.d = floor(yyvsp[-1].d);    ;}
    break;

  case 293:
#line 2959 "Gmsh.y"
    { yyval.d = ceil(yyvsp[-1].d);     ;}
    break;

  case 294:
#line 2960 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 295:
#line 2961 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 296:
#line 2962 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-3].d*yyvsp[-3].d+yyvsp[-1].d*yyvsp[-1].d); ;}
    break;

  case 297:
#line 2963 "Gmsh.y"
    { yyval.d = yyvsp[-1].d*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 298:
#line 2972 "Gmsh.y"
    { yyval.d = yyvsp[0].d; ;}
    break;

  case 299:
#line 2973 "Gmsh.y"
    { yyval.d = 3.141592653589793; ;}
    break;

  case 300:
#line 2974 "Gmsh.y"
    { yyval.d = ParUtil::Instance()->rank(); ;}
    break;

  case 301:
#line 2975 "Gmsh.y"
    { yyval.d = ParUtil::Instance()->size(); ;}
    break;

  case 302:
#line 2976 "Gmsh.y"
    { yyval.d = GMSH_MAJOR_VERSION; ;}
    break;

  case 303:
#line 2977 "Gmsh.y"
    { yyval.d = GMSH_MINOR_VERSION; ;}
    break;

  case 304:
#line 2978 "Gmsh.y"
    { yyval.d = GMSH_PATCH_VERSION; ;}
    break;

  case 305:
#line 2983 "Gmsh.y"
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

  case 306:
#line 2996 "Gmsh.y"
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

  case 307:
#line 3016 "Gmsh.y"
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

  case 308:
#line 3030 "Gmsh.y"
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

  case 309:
#line 3043 "Gmsh.y"
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

  case 310:
#line 3066 "Gmsh.y"
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

  case 311:
#line 3084 "Gmsh.y"
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

  case 312:
#line 3102 "Gmsh.y"
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

  case 313:
#line 3120 "Gmsh.y"
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

  case 314:
#line 3138 "Gmsh.y"
    { 
      yyval.d = GetValue(yyvsp[-3].c, yyvsp[-1].d);
      Free(yyvsp[-3].c);
    ;}
    break;

  case 315:
#line 3146 "Gmsh.y"
    {
      memcpy(yyval.v, yyvsp[0].v, 5*sizeof(double));
    ;}
    break;

  case 316:
#line 3150 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) yyval.v[i] = -yyvsp[0].v[i];
    ;}
    break;

  case 317:
#line 3154 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) yyval.v[i] = yyvsp[0].v[i];
    ;}
    break;

  case 318:
#line 3158 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) yyval.v[i] = yyvsp[-2].v[i] - yyvsp[0].v[i];
    ;}
    break;

  case 319:
#line 3162 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) yyval.v[i] = yyvsp[-2].v[i] + yyvsp[0].v[i];
    ;}
    break;

  case 320:
#line 3169 "Gmsh.y"
    { 
      yyval.v[0] = yyvsp[-9].d;  yyval.v[1] = yyvsp[-7].d;  yyval.v[2] = yyvsp[-5].d;  yyval.v[3] = yyvsp[-3].d; yyval.v[4] = yyvsp[-1].d;
    ;}
    break;

  case 321:
#line 3173 "Gmsh.y"
    { 
      yyval.v[0] = yyvsp[-7].d;  yyval.v[1] = yyvsp[-5].d;  yyval.v[2] = yyvsp[-3].d;  yyval.v[3] = yyvsp[-1].d; yyval.v[4] = 1.0;
    ;}
    break;

  case 322:
#line 3177 "Gmsh.y"
    {
      yyval.v[0] = yyvsp[-5].d;  yyval.v[1] = yyvsp[-3].d;  yyval.v[2] = yyvsp[-1].d;  yyval.v[3] = 0.0; yyval.v[4] = 1.0;
    ;}
    break;

  case 323:
#line 3181 "Gmsh.y"
    {
      yyval.v[0] = yyvsp[-5].d;  yyval.v[1] = yyvsp[-3].d;  yyval.v[2] = yyvsp[-1].d;  yyval.v[3] = 0.0; yyval.v[4] = 1.0;
    ;}
    break;

  case 324:
#line 3188 "Gmsh.y"
    {
    ;}
    break;

  case 325:
#line 3191 "Gmsh.y"
    {
    ;}
    break;

  case 326:
#line 3197 "Gmsh.y"
    {
    ;}
    break;

  case 327:
#line 3200 "Gmsh.y"
    {
    ;}
    break;

  case 328:
#line 3206 "Gmsh.y"
    {
    ;}
    break;

  case 329:
#line 3209 "Gmsh.y"
    {
       yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 330:
#line 3213 "Gmsh.y"
    {
       yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 331:
#line 3220 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(List_T*));
      List_Add(yyval.l, &(yyvsp[0].l));
    ;}
    break;

  case 332:
#line 3225 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].l));
    ;}
    break;

  case 333:
#line 3233 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(double));
      List_Add(yyval.l, &(yyvsp[0].d));
    ;}
    break;

  case 334:
#line 3238 "Gmsh.y"
    {
      yyval.l = yyvsp[0].l;
    ;}
    break;

  case 335:
#line 3242 "Gmsh.y"
    {
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 336:
#line 3246 "Gmsh.y"
    {
      yyval.l = yyvsp[-1].l;
      double *pd;
      for(int i = 0; i < List_Nbr(yyval.l); i++){
	pd = (double*)List_Pointer(yyval.l, i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 337:
#line 3258 "Gmsh.y"
    { 
      yyval.l = List_Create(2, 1, sizeof(double)); 
      for(double d = yyvsp[-2].d; (yyvsp[-2].d < yyvsp[0].d) ? (d <= yyvsp[0].d) : (d >= yyvsp[0].d); (yyvsp[-2].d < yyvsp[0].d) ? (d += 1.) : (d -= 1.)) 
	List_Add(yyval.l, &d);
    ;}
    break;

  case 338:
#line 3264 "Gmsh.y"
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

  case 339:
#line 3275 "Gmsh.y"
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

  case 340:
#line 3295 "Gmsh.y"
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

  case 341:
#line 3305 "Gmsh.y"
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
#line 3315 "Gmsh.y"
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

  case 343:
#line 3327 "Gmsh.y"
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

  case 344:
#line 3344 "Gmsh.y"
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

  case 345:
#line 3363 "Gmsh.y"
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

  case 346:
#line 3387 "Gmsh.y"
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

  case 347:
#line 3416 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(double));
      List_Add(yyval.l, &(yyvsp[0].d));
    ;}
    break;

  case 348:
#line 3421 "Gmsh.y"
    {
      yyval.l = yyvsp[0].l;
    ;}
    break;

  case 349:
#line 3425 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].d));
    ;}
    break;

  case 350:
#line 3429 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[0].l); i++){
	double d;
	List_Read(yyvsp[0].l, i, &d);
	List_Add(yyval.l, &d);
      }
      List_Delete(yyvsp[0].l);
    ;}
    break;

  case 351:
#line 3442 "Gmsh.y"
    {
      yyval.u = PACK_COLOR((int)yyvsp[-7].d, (int)yyvsp[-5].d, (int)yyvsp[-3].d, (int)yyvsp[-1].d);
    ;}
    break;

  case 352:
#line 3446 "Gmsh.y"
    {
      yyval.u = PACK_COLOR((int)yyvsp[-5].d, (int)yyvsp[-3].d, (int)yyvsp[-1].d, 255);
    ;}
    break;

  case 353:
#line 3458 "Gmsh.y"
    {
      int flag;
      yyval.u = Get_ColorForString(ColorString, -1, yyvsp[0].c, &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", yyvsp[0].c);
      Free(yyvsp[0].c);
    ;}
    break;

  case 354:
#line 3465 "Gmsh.y"
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

  case 355:
#line 3487 "Gmsh.y"
    {
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 356:
#line 3491 "Gmsh.y"
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

  case 357:
#line 3506 "Gmsh.y"
    {
      yyval.l = List_Create(256, 10, sizeof(unsigned int));
      List_Add(yyval.l, &(yyvsp[0].u));
    ;}
    break;

  case 358:
#line 3511 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].u));
    ;}
    break;

  case 359:
#line 3518 "Gmsh.y"
    {
      yyval.c = yyvsp[0].c;
    ;}
    break;

  case 360:
#line 3522 "Gmsh.y"
    {
      yyval.c = (char *)Malloc(32*sizeof(char));
      time_t now;
      time(&now);
      strcpy(yyval.c, ctime(&now));
      yyval.c[strlen(yyval.c) - 1] = '\0';
    ;}
    break;

  case 361:
#line 3530 "Gmsh.y"
    {
      yyval.c = (char *)Malloc((strlen(yyvsp[-3].c)+strlen(yyvsp[-1].c)+1)*sizeof(char));
      strcpy(yyval.c, yyvsp[-3].c);
      strcat(yyval.c, yyvsp[-1].c);
      Free(yyvsp[-3].c);
      Free(yyvsp[-1].c);
    ;}
    break;

  case 362:
#line 3538 "Gmsh.y"
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

  case 363:
#line 3552 "Gmsh.y"
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

  case 364:
#line 3566 "Gmsh.y"
    {
      yyval.c = yyvsp[-1].c;
    ;}
    break;

  case 365:
#line 3570 "Gmsh.y"
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

  case 366:
#line 3589 "Gmsh.y"
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

  case 367:
#line 3611 "Gmsh.y"
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
#line 7862 "Gmsh.tab.cpp"

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


#line 3634 "Gmsh.y"


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

