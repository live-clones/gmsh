/* A Bison parser, made by GNU Bison 1.875b.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

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
     tBoundingBox = 292,
     tDraw = 293,
     tPoint = 294,
     tCircle = 295,
     tEllipse = 296,
     tLine = 297,
     tSurface = 298,
     tSpline = 299,
     tVolume = 300,
     tCharacteristic = 301,
     tLength = 302,
     tParametric = 303,
     tElliptic = 304,
     tPlane = 305,
     tRuled = 306,
     tTriangulation = 307,
     tTransfinite = 308,
     tComplex = 309,
     tPhysical = 310,
     tUsing = 311,
     tBump = 312,
     tProgression = 313,
     tPlugin = 314,
     tRotate = 315,
     tTranslate = 316,
     tSymmetry = 317,
     tDilate = 318,
     tExtrude = 319,
     tDuplicata = 320,
     tLoop = 321,
     tRecombine = 322,
     tDelete = 323,
     tCoherence = 324,
     tIntersect = 325,
     tAttractor = 326,
     tLayers = 327,
     tScalarPoint = 328,
     tVectorPoint = 329,
     tTensorPoint = 330,
     tScalarLine = 331,
     tVectorLine = 332,
     tTensorLine = 333,
     tScalarTriangle = 334,
     tVectorTriangle = 335,
     tTensorTriangle = 336,
     tScalarQuadrangle = 337,
     tVectorQuadrangle = 338,
     tTensorQuadrangle = 339,
     tScalarTetrahedron = 340,
     tVectorTetrahedron = 341,
     tTensorTetrahedron = 342,
     tScalarHexahedron = 343,
     tVectorHexahedron = 344,
     tTensorHexahedron = 345,
     tScalarPrism = 346,
     tVectorPrism = 347,
     tTensorPrism = 348,
     tScalarPyramid = 349,
     tVectorPyramid = 350,
     tTensorPyramid = 351,
     tText2D = 352,
     tText3D = 353,
     tInterpolationScheme = 354,
     tCombine = 355,
     tBSpline = 356,
     tBezier = 357,
     tNurbs = 358,
     tOrder = 359,
     tWith = 360,
     tBounds = 361,
     tKnots = 362,
     tColor = 363,
     tColorTable = 364,
     tFor = 365,
     tIn = 366,
     tEndFor = 367,
     tIf = 368,
     tEndIf = 369,
     tExit = 370,
     tReturn = 371,
     tCall = 372,
     tFunction = 373,
     tTrimmed = 374,
     tShow = 375,
     tHide = 376,
     tB_SPLINE_SURFACE_WITH_KNOTS = 377,
     tB_SPLINE_CURVE_WITH_KNOTS = 378,
     tCARTESIAN_POINT = 379,
     tTRUE = 380,
     tFALSE = 381,
     tUNSPECIFIED = 382,
     tU = 383,
     tV = 384,
     tEDGE_CURVE = 385,
     tVERTEX_POINT = 386,
     tORIENTED_EDGE = 387,
     tPLANE = 388,
     tFACE_OUTER_BOUND = 389,
     tEDGE_LOOP = 390,
     tADVANCED_FACE = 391,
     tVECTOR = 392,
     tDIRECTION = 393,
     tAXIS2_PLACEMENT_3D = 394,
     tISO = 395,
     tENDISO = 396,
     tENDSEC = 397,
     tDATA = 398,
     tHEADER = 399,
     tFILE_DESCRIPTION = 400,
     tFILE_SCHEMA = 401,
     tFILE_NAME = 402,
     tMANIFOLD_SOLID_BREP = 403,
     tCLOSED_SHELL = 404,
     tADVANCED_BREP_SHAPE_REPRESENTATION = 405,
     tFACE_BOUND = 406,
     tCYLINDRICAL_SURFACE = 407,
     tCONICAL_SURFACE = 408,
     tCIRCLE = 409,
     tTRIMMED_CURVE = 410,
     tGEOMETRIC_SET = 411,
     tCOMPOSITE_CURVE_SEGMENT = 412,
     tCONTINUOUS = 413,
     tCOMPOSITE_CURVE = 414,
     tTOROIDAL_SURFACE = 415,
     tPRODUCT_DEFINITION = 416,
     tPRODUCT_DEFINITION_SHAPE = 417,
     tSHAPE_DEFINITION_REPRESENTATION = 418,
     tELLIPSE = 419,
     tSolid = 420,
     tEndSolid = 421,
     tVertex = 422,
     tFacet = 423,
     tNormal = 424,
     tOuter = 425,
     tLoopSTL = 426,
     tEndLoop = 427,
     tEndFacet = 428,
     tAFFECTDIVIDE = 429,
     tAFFECTTIMES = 430,
     tAFFECTMINUS = 431,
     tAFFECTPLUS = 432,
     tOR = 433,
     tAND = 434,
     tAPPROXEQUAL = 435,
     tNOTEQUAL = 436,
     tEQUAL = 437,
     tGREATEROREQUAL = 438,
     tLESSOREQUAL = 439,
     tCROSSPRODUCT = 440,
     UNARYPREC = 441,
     tMINUSMINUS = 442,
     tPLUSPLUS = 443
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
#define tBoundingBox 292
#define tDraw 293
#define tPoint 294
#define tCircle 295
#define tEllipse 296
#define tLine 297
#define tSurface 298
#define tSpline 299
#define tVolume 300
#define tCharacteristic 301
#define tLength 302
#define tParametric 303
#define tElliptic 304
#define tPlane 305
#define tRuled 306
#define tTriangulation 307
#define tTransfinite 308
#define tComplex 309
#define tPhysical 310
#define tUsing 311
#define tBump 312
#define tProgression 313
#define tPlugin 314
#define tRotate 315
#define tTranslate 316
#define tSymmetry 317
#define tDilate 318
#define tExtrude 319
#define tDuplicata 320
#define tLoop 321
#define tRecombine 322
#define tDelete 323
#define tCoherence 324
#define tIntersect 325
#define tAttractor 326
#define tLayers 327
#define tScalarPoint 328
#define tVectorPoint 329
#define tTensorPoint 330
#define tScalarLine 331
#define tVectorLine 332
#define tTensorLine 333
#define tScalarTriangle 334
#define tVectorTriangle 335
#define tTensorTriangle 336
#define tScalarQuadrangle 337
#define tVectorQuadrangle 338
#define tTensorQuadrangle 339
#define tScalarTetrahedron 340
#define tVectorTetrahedron 341
#define tTensorTetrahedron 342
#define tScalarHexahedron 343
#define tVectorHexahedron 344
#define tTensorHexahedron 345
#define tScalarPrism 346
#define tVectorPrism 347
#define tTensorPrism 348
#define tScalarPyramid 349
#define tVectorPyramid 350
#define tTensorPyramid 351
#define tText2D 352
#define tText3D 353
#define tInterpolationScheme 354
#define tCombine 355
#define tBSpline 356
#define tBezier 357
#define tNurbs 358
#define tOrder 359
#define tWith 360
#define tBounds 361
#define tKnots 362
#define tColor 363
#define tColorTable 364
#define tFor 365
#define tIn 366
#define tEndFor 367
#define tIf 368
#define tEndIf 369
#define tExit 370
#define tReturn 371
#define tCall 372
#define tFunction 373
#define tTrimmed 374
#define tShow 375
#define tHide 376
#define tB_SPLINE_SURFACE_WITH_KNOTS 377
#define tB_SPLINE_CURVE_WITH_KNOTS 378
#define tCARTESIAN_POINT 379
#define tTRUE 380
#define tFALSE 381
#define tUNSPECIFIED 382
#define tU 383
#define tV 384
#define tEDGE_CURVE 385
#define tVERTEX_POINT 386
#define tORIENTED_EDGE 387
#define tPLANE 388
#define tFACE_OUTER_BOUND 389
#define tEDGE_LOOP 390
#define tADVANCED_FACE 391
#define tVECTOR 392
#define tDIRECTION 393
#define tAXIS2_PLACEMENT_3D 394
#define tISO 395
#define tENDISO 396
#define tENDSEC 397
#define tDATA 398
#define tHEADER 399
#define tFILE_DESCRIPTION 400
#define tFILE_SCHEMA 401
#define tFILE_NAME 402
#define tMANIFOLD_SOLID_BREP 403
#define tCLOSED_SHELL 404
#define tADVANCED_BREP_SHAPE_REPRESENTATION 405
#define tFACE_BOUND 406
#define tCYLINDRICAL_SURFACE 407
#define tCONICAL_SURFACE 408
#define tCIRCLE 409
#define tTRIMMED_CURVE 410
#define tGEOMETRIC_SET 411
#define tCOMPOSITE_CURVE_SEGMENT 412
#define tCONTINUOUS 413
#define tCOMPOSITE_CURVE 414
#define tTOROIDAL_SURFACE 415
#define tPRODUCT_DEFINITION 416
#define tPRODUCT_DEFINITION_SHAPE 417
#define tSHAPE_DEFINITION_REPRESENTATION 418
#define tELLIPSE 419
#define tSolid 420
#define tEndSolid 421
#define tVertex 422
#define tFacet 423
#define tNormal 424
#define tOuter 425
#define tLoopSTL 426
#define tEndLoop 427
#define tEndFacet 428
#define tAFFECTDIVIDE 429
#define tAFFECTTIMES 430
#define tAFFECTMINUS 431
#define tAFFECTPLUS 432
#define tOR 433
#define tAND 434
#define tAPPROXEQUAL 435
#define tNOTEQUAL 436
#define tEQUAL 437
#define tGREATEROREQUAL 438
#define tLESSOREQUAL 439
#define tCROSSPRODUCT 440
#define UNARYPREC 441
#define tMINUSMINUS 442
#define tPLUSPLUS 443




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// $Id: Gmsh.tab.cpp,v 1.207 2004-11-09 16:27:50 remacle Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
#include "STL.h"
#include "Visibility.h"

// FIXME: most tSTRING and tBIGSTRING are leaked: Free() them!

Tree_T *Symbol_T = NULL;

extern Context_T CTX;
extern Mesh *THEM;

static Surface *STL_Surf;
static ExtrudeParams extr;
static Post_View *View;
static int ntmp;

#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0;
static fpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static char *LoopControlVariablesNameTab[MAX_RECUR_LOOPS];

#if defined(HAVE_FLTK)
void UpdateViewsInGUI();
#endif

void yyerror (char *s);
void yymsg (int type, char *fmt, ...);
void skip_until (char *skip, char *until);
int PrintListOfDouble (char *format, List_T *list, char *buffer);


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
#line 540 "Gmsh.tab.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 552 "Gmsh.tab.cpp"

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   13968

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  208
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  137
/* YYNRULES -- Number of rules. */
#define YYNRULES  477
/* YYNRULES -- Number of states. */
#define YYNSTATES  2360

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   443

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   194,     2,   204,     2,   192,     2,     2,
     199,   200,   190,   188,   205,   189,   203,   191,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     184,     2,   185,   178,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   201,     2,   202,   198,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   206,     2,   207,     2,     2,     2,     2,
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
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   179,   180,   181,   182,   183,   186,   187,
     193,   195,   196,   197
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    14,    17,    18,
      21,    23,    45,    47,    48,    51,    53,    55,    57,    60,
      63,    66,    69,    72,    80,    86,   104,   114,   138,   170,
     186,   198,   210,   226,   236,   250,   260,   272,   286,   296,
     306,   318,   328,   340,   350,   362,   376,   390,   402,   416,
     434,   444,   456,   468,   482,   494,   504,   505,   508,   510,
     512,   514,   516,   518,   520,   522,   524,   526,   528,   530,
     532,   534,   536,   542,   550,   557,   566,   567,   570,   573,
     576,   579,   582,   585,   588,   591,   594,   597,   600,   603,
     606,   609,   612,   615,   618,   621,   624,   627,   630,   633,
     636,   639,   642,   645,   648,   650,   654,   655,   669,   671,
     675,   676,   690,   692,   696,   697,   711,   713,   717,   718,
     738,   740,   744,   745,   765,   767,   771,   772,   792,   794,
     798,   799,   825,   827,   831,   832,   858,   860,   864,   865,
     891,   893,   897,   898,   930,   932,   936,   937,   969,   971,
     975,   976,  1008,  1010,  1014,  1015,  1047,  1049,  1053,  1054,
    1086,  1088,  1092,  1093,  1125,  1127,  1131,  1132,  1188,  1190,
    1194,  1195,  1251,  1253,  1257,  1258,  1314,  1316,  1320,  1321,
    1365,  1367,  1371,  1372,  1416,  1418,  1422,  1423,  1467,  1469,
    1473,  1474,  1512,  1514,  1518,  1519,  1557,  1559,  1563,  1564,
    1602,  1604,  1608,  1609,  1623,  1625,  1629,  1630,  1646,  1651,
    1653,  1655,  1657,  1659,  1661,  1663,  1665,  1670,  1678,  1688,
    1695,  1699,  1706,  1713,  1723,  1730,  1740,  1746,  1755,  1764,
    1776,  1783,  1793,  1803,  1813,  1821,  1830,  1843,  1850,  1858,
    1866,  1874,  1884,  1892,  1902,  1920,  1928,  1936,  1948,  1957,
    1970,  1979,  1988,  1997,  2010,  2025,  2040,  2063,  2084,  2093,
    2102,  2111,  2119,  2128,  2134,  2146,  2152,  2162,  2164,  2166,
    2168,  2169,  2172,  2179,  2186,  2193,  2200,  2205,  2212,  2217,
    2224,  2228,  2234,  2238,  2242,  2247,  2252,  2256,  2264,  2268,
    2276,  2280,  2283,  2286,  2302,  2305,  2312,  2321,  2330,  2341,
    2343,  2346,  2348,  2352,  2357,  2359,  2368,  2381,  2396,  2397,
    2410,  2411,  2428,  2429,  2448,  2457,  2470,  2485,  2486,  2499,
    2500,  2517,  2518,  2537,  2546,  2559,  2574,  2575,  2588,  2589,
    2606,  2607,  2626,  2628,  2631,  2641,  2649,  2652,  2659,  2669,
    2679,  2688,  2697,  2706,  2713,  2718,  2721,  2724,  2726,  2728,
    2730,  2732,  2734,  2736,  2740,  2743,  2746,  2749,  2753,  2757,
    2761,  2765,  2769,  2773,  2777,  2781,  2785,  2789,  2793,  2797,
    2801,  2805,  2811,  2816,  2821,  2826,  2831,  2836,  2841,  2846,
    2851,  2856,  2861,  2868,  2873,  2878,  2883,  2888,  2893,  2898,
    2905,  2912,  2919,  2924,  2929,  2934,  2939,  2944,  2949,  2954,
    2959,  2964,  2969,  2974,  2981,  2986,  2991,  2996,  3001,  3006,
    3011,  3018,  3025,  3032,  3037,  3039,  3041,  3043,  3045,  3047,
    3052,  3057,  3060,  3066,  3070,  3077,  3082,  3090,  3092,  3095,
    3098,  3102,  3106,  3118,  3128,  3136,  3144,  3145,  3149,  3151,
    3155,  3156,  3160,  3164,  3166,  3170,  3172,  3174,  3178,  3183,
    3187,  3193,  3198,  3200,  3202,  3204,  3208,  3213,  3220,  3228,
    3230,  3232,  3236,  3240,  3250,  3258,  3260,  3266,  3270,  3277,
    3279,  3283,  3285,  3292,  3297,  3302,  3309,  3316
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     209,     0,    -1,   213,    -1,   211,    -1,   218,    -1,     1,
       6,    -1,     3,    -1,   189,     3,    -1,    -1,   211,   212,
      -1,   165,    -1,   168,   169,   210,   210,   210,   170,   171,
     167,   210,   210,   210,   167,   210,   210,   210,   167,   210,
     210,   210,   172,   173,    -1,   166,    -1,    -1,   213,   214,
      -1,   215,    -1,   217,    -1,   216,    -1,   140,     6,    -1,
     141,     6,    -1,   143,     6,    -1,   142,     6,    -1,   144,
       6,    -1,   145,   199,   334,   205,     5,   200,     6,    -1,
     146,   199,   334,   200,     6,    -1,   147,   199,     5,   205,
       5,   205,   334,   205,   334,   205,     5,   205,     5,   205,
       5,   200,     6,    -1,     3,     7,   124,   199,     5,   205,
     332,   200,     6,    -1,     3,     7,   123,   199,     5,   205,
     330,   205,   338,   205,   329,   205,   329,   205,   329,   205,
     338,   205,   338,   205,   329,   200,     6,    -1,     3,     7,
     122,   199,     5,   205,   330,   205,   330,   205,   336,   205,
     329,   205,   329,   205,   329,   205,   329,   205,   338,   205,
     338,   205,   338,   205,   338,   205,   329,   200,     6,    -1,
       3,     7,   130,   199,     5,   205,     3,   205,     3,   205,
       3,   205,   329,   200,     6,    -1,     3,     7,   134,   199,
       5,   205,     3,   205,   329,   200,     6,    -1,     3,     7,
     151,   199,     5,   205,     3,   205,   329,   200,     6,    -1,
       3,     7,   132,   199,     5,   205,   190,   205,   190,   205,
     330,   205,   329,   200,     6,    -1,     3,     7,   135,   199,
       5,   205,   338,   200,     6,    -1,     3,     7,   136,   199,
       5,   205,   338,   205,     3,   205,   329,   200,     6,    -1,
       3,     7,   131,   199,     5,   205,     3,   200,     6,    -1,
       3,     7,   137,   199,     5,   205,     3,   205,   330,   200,
       6,    -1,     3,     7,   139,   199,     5,   205,     3,   205,
       3,   205,     3,   200,     6,    -1,     3,     7,   138,   199,
       5,   205,   332,   200,     6,    -1,     3,     7,   133,   199,
       5,   205,     3,   200,     6,    -1,     3,     7,    42,   199,
       5,   205,     3,   205,     3,   200,     6,    -1,     3,     7,
     149,   199,     5,   205,   338,   200,     6,    -1,     3,     7,
     150,   199,     5,   205,   338,   205,     3,   200,     6,    -1,
       3,     7,   148,   199,     5,   205,     3,   200,     6,    -1,
       3,     7,   152,   199,     5,   205,     3,   205,   330,   200,
       6,    -1,     3,     7,   153,   199,     5,   205,     3,   205,
     330,   205,   330,   200,     6,    -1,     3,     7,   160,   199,
       5,   205,     3,   205,   330,   205,   330,   200,     6,    -1,
       3,     7,   154,   199,     5,   205,     3,   205,   330,   200,
       6,    -1,     3,     7,   164,   199,     5,   205,     3,   205,
     330,   205,   330,   200,     6,    -1,     3,     7,   155,   199,
       5,   205,     3,   205,   338,   205,   338,   205,   329,   205,
     329,   200,     6,    -1,     3,     7,   156,   199,     5,   205,
     338,   200,     6,    -1,     3,     7,   157,   199,   158,   205,
     329,   205,     3,   200,     6,    -1,     3,     7,   159,   199,
       5,   205,   338,   205,   329,   200,     6,    -1,     3,     7,
     161,   199,     5,   205,     5,   205,     3,   205,     3,   200,
       6,    -1,     3,     7,   162,   199,     5,   205,     5,   205,
       3,   200,     6,    -1,     3,     7,   163,   199,     3,   205,
       3,   200,     6,    -1,    -1,   218,   219,    -1,   221,    -1,
     220,    -1,   304,    -1,   305,    -1,   306,    -1,   309,    -1,
     310,    -1,   311,    -1,   312,    -1,   315,    -1,   327,    -1,
     328,    -1,   314,    -1,   313,    -1,    33,   199,     5,   200,
       6,    -1,    33,   199,     5,   205,   340,   200,     6,    -1,
       4,     5,   206,   222,   207,     6,    -1,     4,     5,     4,
     332,   206,   222,   207,     6,    -1,    -1,   222,   224,    -1,
     222,   227,    -1,   222,   230,    -1,   222,   233,    -1,   222,
     236,    -1,   222,   239,    -1,   222,   242,    -1,   222,   245,
      -1,   222,   248,    -1,   222,   251,    -1,   222,   254,    -1,
     222,   257,    -1,   222,   260,    -1,   222,   263,    -1,   222,
     266,    -1,   222,   269,    -1,   222,   272,    -1,   222,   275,
      -1,   222,   278,    -1,   222,   281,    -1,   222,   284,    -1,
     222,   287,    -1,   222,   290,    -1,   222,   293,    -1,   222,
     296,    -1,   222,   299,    -1,   222,   301,    -1,   330,    -1,
     223,   205,   330,    -1,    -1,    73,   199,   330,   205,   330,
     205,   330,   200,   225,   206,   223,   207,     6,    -1,   330,
      -1,   226,   205,   330,    -1,    -1,    74,   199,   330,   205,
     330,   205,   330,   200,   228,   206,   226,   207,     6,    -1,
     330,    -1,   229,   205,   330,    -1,    -1,    75,   199,   330,
     205,   330,   205,   330,   200,   231,   206,   229,   207,     6,
      -1,   330,    -1,   232,   205,   330,    -1,    -1,    76,   199,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   200,   234,   206,   232,   207,     6,    -1,   330,    -1,
     235,   205,   330,    -1,    -1,    77,   199,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   200,   237,
     206,   235,   207,     6,    -1,   330,    -1,   238,   205,   330,
      -1,    -1,    78,   199,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   200,   240,   206,   238,   207,
       6,    -1,   330,    -1,   241,   205,   330,    -1,    -1,    79,
     199,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   200,   243,
     206,   241,   207,     6,    -1,   330,    -1,   244,   205,   330,
      -1,    -1,    80,   199,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   200,   246,   206,   244,   207,     6,    -1,   330,    -1,
     247,   205,   330,    -1,    -1,    81,   199,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   200,   249,   206,   247,   207,     6,
      -1,   330,    -1,   250,   205,   330,    -1,    -1,    82,   199,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   200,   252,   206,   250,   207,     6,    -1,
     330,    -1,   253,   205,   330,    -1,    -1,    83,   199,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   200,   255,   206,   253,   207,     6,    -1,   330,
      -1,   256,   205,   330,    -1,    -1,    84,   199,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   200,   258,   206,   256,   207,     6,    -1,   330,    -1,
     259,   205,   330,    -1,    -1,    85,   199,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     200,   261,   206,   259,   207,     6,    -1,   330,    -1,   262,
     205,   330,    -1,    -1,    86,   199,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   200,
     264,   206,   262,   207,     6,    -1,   330,    -1,   265,   205,
     330,    -1,    -1,    87,   199,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   200,   267,
     206,   265,   207,     6,    -1,   330,    -1,   268,   205,   330,
      -1,    -1,    88,   199,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   200,   270,   206,   268,   207,     6,    -1,   330,    -1,
     271,   205,   330,    -1,    -1,    89,   199,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   200,   273,   206,   271,   207,     6,
      -1,   330,    -1,   274,   205,   330,    -1,    -1,    90,   199,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   200,   276,   206,
     274,   207,     6,    -1,   330,    -1,   277,   205,   330,    -1,
      -1,    91,   199,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   200,   279,
     206,   277,   207,     6,    -1,   330,    -1,   280,   205,   330,
      -1,    -1,    92,   199,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   200,
     282,   206,   280,   207,     6,    -1,   330,    -1,   283,   205,
     330,    -1,    -1,    93,   199,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     200,   285,   206,   283,   207,     6,    -1,   330,    -1,   286,
     205,   330,    -1,    -1,    94,   199,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   200,   288,   206,   286,   207,
       6,    -1,   330,    -1,   289,   205,   330,    -1,    -1,    95,
     199,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     200,   291,   206,   289,   207,     6,    -1,   330,    -1,   292,
     205,   330,    -1,    -1,    96,   199,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   205,   330,   200,   294,   206,   292,   207,
       6,    -1,   344,    -1,   295,   205,   344,    -1,    -1,    97,
     199,   330,   205,   330,   205,   330,   200,   297,   206,   295,
     207,     6,    -1,   344,    -1,   298,   205,   344,    -1,    -1,
      98,   199,   330,   205,   330,   205,   330,   205,   330,   200,
     300,   206,   298,   207,     6,    -1,    99,   336,   336,     6,
      -1,     7,    -1,   177,    -1,   176,    -1,   175,    -1,   174,
      -1,   197,    -1,   196,    -1,     4,   302,   330,     6,    -1,
       4,   201,   330,   202,   302,   330,     6,    -1,     4,   201,
     206,   340,   207,   202,   302,   338,     6,    -1,     4,   201,
     202,     7,   338,     6,    -1,     4,   303,     6,    -1,     4,
     201,   330,   202,   303,     6,    -1,     4,   203,     4,     7,
     344,     6,    -1,     4,   201,   330,   202,   203,     4,     7,
     344,     6,    -1,     4,   203,     4,   302,   330,     6,    -1,
       4,   201,   330,   202,   203,     4,   302,   330,     6,    -1,
       4,   203,     4,   303,     6,    -1,     4,   201,   330,   202,
     203,     4,   303,     6,    -1,     4,   203,   108,   203,     4,
       7,   341,     6,    -1,     4,   201,   330,   202,   203,   108,
     203,     4,     7,   341,     6,    -1,     4,   203,   109,     7,
     342,     6,    -1,     4,   201,   330,   202,   203,   109,     7,
     342,     6,    -1,    59,   199,     4,   200,   203,     4,     7,
     330,     6,    -1,    59,   199,     4,   200,   203,     4,     7,
     344,     6,    -1,    39,   199,   330,   200,     7,   332,     6,
      -1,    55,    39,   199,   330,   200,     7,   338,     6,    -1,
      71,    39,   338,     7,   206,   330,   205,   330,   205,   330,
     207,     6,    -1,    46,    47,   338,     7,   330,     6,    -1,
      42,   199,   330,   200,     7,   338,     6,    -1,    44,   199,
     330,   200,     7,   338,     6,    -1,    40,   199,   330,   200,
       7,   338,     6,    -1,    40,   199,   330,   200,     7,   338,
      50,   332,     6,    -1,    41,   199,   330,   200,     7,   338,
       6,    -1,    41,   199,   330,   200,     7,   338,    50,   332,
       6,    -1,    48,   199,   330,   200,     7,   206,   330,   205,
     330,   205,     5,   205,     5,   205,     5,   207,     6,    -1,
     101,   199,   330,   200,     7,   338,     6,    -1,   102,   199,
     330,   200,     7,   338,     6,    -1,   103,   199,   330,   200,
       7,   338,   107,   338,   104,   330,     6,    -1,    42,    66,
     199,   330,   200,     7,   338,     6,    -1,    71,    42,   338,
       7,   206,   330,   205,   330,   205,   330,   207,     6,    -1,
      55,    42,   199,   330,   200,     7,   338,     6,    -1,    50,
      43,   199,   330,   200,     7,   338,     6,    -1,    51,    43,
     199,   330,   200,     7,   338,     6,    -1,   119,    43,   199,
     330,   200,     7,   206,   330,   205,   338,   207,     6,    -1,
      52,    43,   206,   330,   207,     7,   199,   330,   205,   330,
     200,   338,   338,     6,    -1,    52,    43,   199,   330,   200,
       7,   199,   330,   205,   330,   200,   338,   338,     6,    -1,
     103,    43,   105,   106,   199,   330,   200,     7,   336,   107,
     206,   338,   205,   338,   207,   104,   206,   330,   205,   330,
     207,     6,    -1,   103,    43,   199,   330,   200,     7,   336,
     107,   206,   338,   205,   338,   207,   104,   206,   330,   205,
     330,   207,     6,    -1,    43,    66,   199,   330,   200,     7,
     338,     6,    -1,    55,    43,   199,   330,   200,     7,   338,
       6,    -1,    54,    45,   199,   330,   200,     7,   338,     6,
      -1,    45,   199,   330,   200,     7,   338,     6,    -1,    55,
      45,   199,   330,   200,     7,   338,     6,    -1,    61,   332,
     206,   307,   207,    -1,    60,   206,   332,   205,   332,   205,
     330,   207,   206,   307,   207,    -1,    62,   332,   206,   307,
     207,    -1,    63,   206,   332,   205,   330,   207,   206,   307,
     207,    -1,   309,    -1,   308,    -1,   306,    -1,    -1,   308,
     305,    -1,   308,    39,   206,   340,   207,     6,    -1,   308,
      42,   206,   340,   207,     6,    -1,   308,    43,   206,   340,
     207,     6,    -1,   308,    45,   206,   340,   207,     6,    -1,
      65,   206,   308,   207,    -1,    65,     4,   201,   330,   202,
       6,    -1,    68,   206,   308,   207,    -1,    68,     4,   201,
     330,   202,     6,    -1,    68,     4,     6,    -1,   108,   341,
     206,   308,   207,    -1,   120,   344,     6,    -1,   121,   344,
       6,    -1,   120,   206,   308,   207,    -1,   121,   206,   308,
     207,    -1,     4,   344,     6,    -1,     4,     4,   201,   330,
     202,   344,     6,    -1,     4,   330,     6,    -1,    59,   199,
       4,   200,   203,     4,     6,    -1,   100,     4,     6,    -1,
     115,     6,    -1,    37,     6,    -1,    37,   206,   330,   205,
     330,   205,   330,   205,   330,   205,   330,   205,   330,   207,
       6,    -1,    38,     6,    -1,   110,   199,   330,     8,   330,
     200,    -1,   110,   199,   330,     8,   330,     8,   330,   200,
      -1,   110,     4,   111,   206,   330,     8,   330,   207,    -1,
     110,     4,   111,   206,   330,     8,   330,     8,   330,   207,
      -1,   112,    -1,   118,     4,    -1,   116,    -1,   117,     4,
       6,    -1,   113,   199,   330,   200,    -1,   114,    -1,    64,
      39,   206,   330,   205,   332,   207,     6,    -1,    64,    39,
     206,   330,   205,   332,   205,   332,   205,   330,   207,     6,
      -1,    64,    39,   206,   330,   205,   332,   205,   332,   205,
     332,   205,   330,   207,     6,    -1,    -1,    64,    39,   206,
     330,   205,   332,   207,   316,   206,   325,   207,     6,    -1,
      -1,    64,    39,   206,   330,   205,   332,   205,   332,   205,
     330,   207,   317,   206,   325,   207,     6,    -1,    -1,    64,
      39,   206,   330,   205,   332,   205,   332,   205,   332,   205,
     330,   207,   318,   206,   325,   207,     6,    -1,    64,    42,
     206,   330,   205,   332,   207,     6,    -1,    64,    42,   206,
     330,   205,   332,   205,   332,   205,   330,   207,     6,    -1,
      64,    42,   206,   330,   205,   332,   205,   332,   205,   332,
     205,   330,   207,     6,    -1,    -1,    64,    42,   206,   330,
     205,   332,   207,   319,   206,   325,   207,     6,    -1,    -1,
      64,    42,   206,   330,   205,   332,   205,   332,   205,   330,
     207,   320,   206,   325,   207,     6,    -1,    -1,    64,    42,
     206,   330,   205,   332,   205,   332,   205,   332,   205,   330,
     207,   321,   206,   325,   207,     6,    -1,    64,    43,   206,
     330,   205,   332,   207,     6,    -1,    64,    43,   206,   330,
     205,   332,   205,   332,   205,   330,   207,     6,    -1,    64,
      43,   206,   330,   205,   332,   205,   332,   205,   332,   205,
     330,   207,     6,    -1,    -1,    64,    43,   206,   330,   205,
     332,   207,   322,   206,   325,   207,     6,    -1,    -1,    64,
      43,   206,   330,   205,   332,   205,   332,   205,   330,   207,
     323,   206,   325,   207,     6,    -1,    -1,    64,    43,   206,
     330,   205,   332,   205,   332,   205,   332,   205,   330,   207,
     324,   206,   325,   207,     6,    -1,   326,    -1,   325,   326,
      -1,    72,   206,   338,   205,   338,   205,   338,   207,     6,
      -1,    72,   206,   338,   205,   338,   207,     6,    -1,    67,
       6,    -1,    53,    42,   338,     7,   330,     6,    -1,    53,
      42,   338,     7,   330,    56,    58,   330,     6,    -1,    53,
      42,   338,     7,   330,    56,    57,   330,     6,    -1,    53,
      43,   206,   330,   207,     7,   338,     6,    -1,    49,    43,
     206,   330,   207,     7,   338,     6,    -1,    53,    45,   206,
     330,   207,     7,   338,     6,    -1,    67,    43,   338,     7,
     330,     6,    -1,    67,    43,   338,     6,    -1,    69,     6,
      -1,    70,     6,    -1,   125,    -1,   126,    -1,   127,    -1,
     128,    -1,   129,    -1,   331,    -1,   199,   330,   200,    -1,
     189,   330,    -1,   188,   330,    -1,   194,   330,    -1,   330,
     189,   330,    -1,   330,   188,   330,    -1,   330,   190,   330,
      -1,   330,   191,   330,    -1,   330,   192,   330,    -1,   330,
     198,   330,    -1,   330,   184,   330,    -1,   330,   185,   330,
      -1,   330,   187,   330,    -1,   330,   186,   330,    -1,   330,
     183,   330,    -1,   330,   182,   330,    -1,   330,   180,   330,
      -1,   330,   179,   330,    -1,   330,   178,   330,     8,   330,
      -1,    12,   199,   330,   200,    -1,    13,   199,   330,   200,
      -1,    14,   199,   330,   200,    -1,    15,   199,   330,   200,
      -1,    16,   199,   330,   200,    -1,    17,   199,   330,   200,
      -1,    18,   199,   330,   200,    -1,    19,   199,   330,   200,
      -1,    20,   199,   330,   200,    -1,    22,   199,   330,   200,
      -1,    23,   199,   330,   205,   330,   200,    -1,    24,   199,
     330,   200,    -1,    25,   199,   330,   200,    -1,    26,   199,
     330,   200,    -1,    27,   199,   330,   200,    -1,    28,   199,
     330,   200,    -1,    29,   199,   330,   200,    -1,    30,   199,
     330,   205,   330,   200,    -1,    31,   199,   330,   205,   330,
     200,    -1,    32,   199,   330,   205,   330,   200,    -1,    21,
     199,   330,   200,    -1,    12,   201,   330,   202,    -1,    13,
     201,   330,   202,    -1,    14,   201,   330,   202,    -1,    15,
     201,   330,   202,    -1,    16,   201,   330,   202,    -1,    17,
     201,   330,   202,    -1,    18,   201,   330,   202,    -1,    19,
     201,   330,   202,    -1,    20,   201,   330,   202,    -1,    22,
     201,   330,   202,    -1,    23,   201,   330,   205,   330,   202,
      -1,    24,   201,   330,   202,    -1,    25,   201,   330,   202,
      -1,    26,   201,   330,   202,    -1,    27,   201,   330,   202,
      -1,    28,   201,   330,   202,    -1,    29,   201,   330,   202,
      -1,    30,   201,   330,   205,   330,   202,    -1,    31,   201,
     330,   205,   330,   202,    -1,    32,   201,   330,   205,   330,
     202,    -1,    21,   201,   330,   202,    -1,     3,    -1,     9,
      -1,    10,    -1,    11,    -1,     4,    -1,     4,   201,   330,
     202,    -1,   204,     4,   201,   202,    -1,     4,   303,    -1,
       4,   201,   330,   202,   303,    -1,     4,   203,     4,    -1,
       4,   201,   330,   202,   203,     4,    -1,     4,   203,     4,
     303,    -1,     4,   201,   330,   202,   203,     4,   303,    -1,
     333,    -1,   189,   332,    -1,   188,   332,    -1,   332,   189,
     332,    -1,   332,   188,   332,    -1,   206,   330,   205,   330,
     205,   330,   205,   330,   205,   330,   207,    -1,   206,   330,
     205,   330,   205,   330,   205,   330,   207,    -1,   206,   330,
     205,   330,   205,   330,   207,    -1,   199,   330,   205,   330,
     205,   330,   200,    -1,    -1,   199,   335,   200,    -1,     5,
      -1,   335,   205,     5,    -1,    -1,   206,   337,   207,    -1,
     199,   337,   200,    -1,   338,    -1,   337,   205,   338,    -1,
     330,    -1,   339,    -1,   206,   340,   207,    -1,   189,   206,
     340,   207,    -1,   330,     8,   330,    -1,   330,     8,   330,
       8,   330,    -1,    39,   206,   330,   207,    -1,   306,    -1,
     309,    -1,   315,    -1,     4,   201,   202,    -1,   189,     4,
     201,   202,    -1,     4,   201,   206,   340,   207,   202,    -1,
     189,     4,   201,   206,   340,   207,   202,    -1,   330,    -1,
     339,    -1,   340,   205,   330,    -1,   340,   205,   339,    -1,
     206,   330,   205,   330,   205,   330,   205,   330,   207,    -1,
     206,   330,   205,   330,   205,   330,   207,    -1,     4,    -1,
       4,   203,   108,   203,     4,    -1,   206,   343,   207,    -1,
       4,   201,   330,   202,   203,   109,    -1,   341,    -1,   343,
     205,   341,    -1,     5,    -1,    35,   199,   344,   205,   344,
     200,    -1,    36,   199,   344,   200,    -1,    34,   199,   344,
     200,    -1,    34,   199,   344,   205,   340,   200,    -1,    34,
     199,     4,   203,     4,   200,    -1,    34,   199,     4,   201,
     330,   202,   203,     4,   200,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   166,   166,   167,   168,   169,   175,   176,   179,   181,
     185,   192,   206,   223,   225,   229,   230,   231,   235,   240,
     245,   246,   247,   251,   254,   257,   264,   268,   274,   282,
     287,   291,   297,   302,   306,   311,   315,   318,   323,   327,
     331,   335,   340,   344,   347,   351,   355,   359,   363,   367,
     371,   374,   378,   381,   385,   388,   395,   397,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   418,   422,   439,   443,   451,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   484,   486,   492,   491,   503,   505,
     511,   510,   526,   528,   534,   533,   549,   551,   558,   556,
     574,   576,   583,   581,   599,   601,   608,   606,   624,   626,
     634,   631,   653,   655,   663,   660,   682,   684,   692,   689,
     711,   713,   722,   718,   741,   743,   752,   748,   771,   773,
     782,   778,   801,   803,   812,   808,   831,   833,   842,   838,
     861,   863,   872,   868,   891,   893,   906,   898,   931,   933,
     946,   938,   971,   973,   986,   978,  1011,  1013,  1024,  1018,
    1046,  1048,  1059,  1053,  1081,  1083,  1094,  1088,  1116,  1118,
    1128,  1123,  1150,  1152,  1162,  1157,  1184,  1186,  1196,  1191,
    1218,  1223,  1232,  1231,  1245,  1250,  1259,  1258,  1272,  1281,
    1282,  1283,  1284,  1285,  1289,  1290,  1297,  1325,  1361,  1410,
    1426,  1436,  1454,  1467,  1483,  1508,  1534,  1547,  1563,  1576,
    1592,  1611,  1633,  1642,  1660,  1676,  1692,  1711,  1730,  1748,
    1766,  1784,  1810,  1828,  1854,  1873,  1897,  1921,  1947,  1964,
    1982,  2001,  2020,  2059,  2084,  2106,  2122,  2141,  2160,  2176,
    2195,  2212,  2229,  2250,  2255,  2260,  2265,  2273,  2274,  2275,
    2280,  2283,  2287,  2303,  2319,  2335,  2356,  2369,  2380,  2389,
    2399,  2409,  2423,  2430,  2435,  2446,  2460,  2503,  2517,  2532,
    2541,  2551,  2555,  2559,  2563,  2576,  2590,  2604,  2629,  2654,
    2681,  2687,  2692,  2697,  2701,  2712,  2728,  2744,  2761,  2760,
    2782,  2781,  2803,  2802,  2825,  2848,  2871,  2895,  2894,  2923,
    2922,  2951,  2950,  2981,  3004,  3027,  3051,  3050,  3079,  3078,
    3108,  3107,  3139,  3142,  3148,  3174,  3198,  3207,  3225,  3243,
    3261,  3288,  3314,  3340,  3354,  3373,  3377,  3387,  3388,  3389,
    3390,  3391,  3395,  3396,  3397,  3398,  3399,  3400,  3401,  3402,
    3403,  3410,  3411,  3412,  3413,  3414,  3415,  3416,  3417,  3418,
    3419,  3420,  3421,  3422,  3423,  3424,  3425,  3426,  3427,  3428,
    3429,  3430,  3431,  3432,  3433,  3434,  3435,  3436,  3437,  3438,
    3439,  3440,  3441,  3443,  3444,  3445,  3446,  3447,  3448,  3449,
    3450,  3451,  3452,  3453,  3454,  3455,  3456,  3457,  3458,  3459,
    3460,  3461,  3462,  3463,  3472,  3473,  3474,  3475,  3479,  3491,
    3510,  3523,  3535,  3557,  3574,  3591,  3608,  3628,  3632,  3636,
    3640,  3644,  3651,  3655,  3659,  3663,  3671,  3673,  3679,  3682,
    3689,  3691,  3695,  3702,  3707,  3715,  3720,  3724,  3728,  3740,
    3746,  3757,  3777,  3787,  3797,  3809,  3825,  3843,  3866,  3894,
    3899,  3903,  3907,  3920,  3924,  3936,  3942,  3963,  3967,  3981,
    3986,  3993,  3997,  4005,  4019,  4023,  4042,  4058
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
  "tStrPrefix", "tBoundingBox", "tDraw", "tPoint", "tCircle", "tEllipse", 
  "tLine", "tSurface", "tSpline", "tVolume", "tCharacteristic", "tLength", 
  "tParametric", "tElliptic", "tPlane", "tRuled", "tTriangulation", 
  "tTransfinite", "tComplex", "tPhysical", "tUsing", "tBump", 
  "tProgression", "tPlugin", "tRotate", "tTranslate", "tSymmetry", 
  "tDilate", "tExtrude", "tDuplicata", "tLoop", "tRecombine", "tDelete", 
  "tCoherence", "tIntersect", "tAttractor", "tLayers", "tScalarPoint", 
  "tVectorPoint", "tTensorPoint", "tScalarLine", "tVectorLine", 
  "tTensorLine", "tScalarTriangle", "tVectorTriangle", "tTensorTriangle", 
  "tScalarQuadrangle", "tVectorQuadrangle", "tTensorQuadrangle", 
  "tScalarTetrahedron", "tVectorTetrahedron", "tTensorTetrahedron", 
  "tScalarHexahedron", "tVectorHexahedron", "tTensorHexahedron", 
  "tScalarPrism", "tVectorPrism", "tTensorPrism", "tScalarPyramid", 
  "tVectorPyramid", "tTensorPyramid", "tText2D", "tText3D", 
  "tInterpolationScheme", "tCombine", "tBSpline", "tBezier", "tNurbs", 
  "tOrder", "tWith", "tBounds", "tKnots", "tColor", "tColorTable", "tFor", 
  "tIn", "tEndFor", "tIf", "tEndIf", "tExit", "tReturn", "tCall", 
  "tFunction", "tTrimmed", "tShow", "tHide", 
  "tB_SPLINE_SURFACE_WITH_KNOTS", "tB_SPLINE_CURVE_WITH_KNOTS", 
  "tCARTESIAN_POINT", "tTRUE", "tFALSE", "tUNSPECIFIED", "tU", "tV", 
  "tEDGE_CURVE", "tVERTEX_POINT", "tORIENTED_EDGE", "tPLANE", 
  "tFACE_OUTER_BOUND", "tEDGE_LOOP", "tADVANCED_FACE", "tVECTOR", 
  "tDIRECTION", "tAXIS2_PLACEMENT_3D", "tISO", "tENDISO", "tENDSEC", 
  "tDATA", "tHEADER", "tFILE_DESCRIPTION", "tFILE_SCHEMA", "tFILE_NAME", 
  "tMANIFOLD_SOLID_BREP", "tCLOSED_SHELL", 
  "tADVANCED_BREP_SHAPE_REPRESENTATION", "tFACE_BOUND", 
  "tCYLINDRICAL_SURFACE", "tCONICAL_SURFACE", "tCIRCLE", "tTRIMMED_CURVE", 
  "tGEOMETRIC_SET", "tCOMPOSITE_CURVE_SEGMENT", "tCONTINUOUS", 
  "tCOMPOSITE_CURVE", "tTOROIDAL_SURFACE", "tPRODUCT_DEFINITION", 
  "tPRODUCT_DEFINITION_SHAPE", "tSHAPE_DEFINITION_REPRESENTATION", 
  "tELLIPSE", "tSolid", "tEndSolid", "tVertex", "tFacet", "tNormal", 
  "tOuter", "tLoopSTL", "tEndLoop", "tEndFacet", "tAFFECTDIVIDE", 
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND", 
  "tAPPROXEQUAL", "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", 
  "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "tCROSSPRODUCT", 
  "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'", 
  "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'", "$accept", "All", 
  "SignedDouble", "StlFormatItems", "StlFormatItem", "StepFormatItems", 
  "StepFormatItem", "StepSpecial", "StepHeaderItem", "StepDataItem", 
  "GeoFormatItems", "GeoFormatItem", "Printf", "View", "Views", 
  "ScalarPointValues", "ScalarPoint", "@1", "VectorPointValues", 
  "VectorPoint", "@2", "TensorPointValues", "TensorPoint", "@3", 
  "ScalarLineValues", "ScalarLine", "@4", "VectorLineValues", 
  "VectorLine", "@5", "TensorLineValues", "TensorLine", "@6", 
  "ScalarTriangleValues", "ScalarTriangle", "@7", "VectorTriangleValues", 
  "VectorTriangle", "@8", "TensorTriangleValues", "TensorTriangle", "@9", 
  "ScalarQuadrangleValues", "ScalarQuadrangle", "@10", 
  "VectorQuadrangleValues", "VectorQuadrangle", "@11", 
  "TensorQuadrangleValues", "TensorQuadrangle", "@12", 
  "ScalarTetrahedronValues", "ScalarTetrahedron", "@13", 
  "VectorTetrahedronValues", "VectorTetrahedron", "@14", 
  "TensorTetrahedronValues", "TensorTetrahedron", "@15", 
  "ScalarHexahedronValues", "ScalarHexahedron", "@16", 
  "VectorHexahedronValues", "VectorHexahedron", "@17", 
  "TensorHexahedronValues", "TensorHexahedron", "@18", 
  "ScalarPrismValues", "ScalarPrism", "@19", "VectorPrismValues", 
  "VectorPrism", "@20", "TensorPrismValues", "TensorPrism", "@21", 
  "ScalarPyramidValues", "ScalarPyramid", "@22", "VectorPyramidValues", 
  "VectorPyramid", "@23", "TensorPyramidValues", "TensorPyramid", "@24", 
  "Text2DValues", "Text2D", "@25", "Text3DValues", "Text3D", "@26", 
  "InterpolationMatrix", "NumericAffectation", "NumericIncrement", 
  "Affectation", "Shape", "Transform", "MultipleShape", "ListOfShapes", 
  "Duplicata", "Delete", "Colorify", "Visibility", "Command", "Loop", 
  "Extrude", "@27", "@28", "@29", "@30", "@31", "@32", "@33", "@34", 
  "@35", "ExtrudeParameters", "ExtrudeParameter", "Transfinite", 
  "Coherence", "BoolExpr", "FExpr", "FExpr_Single", "VExpr", 
  "VExpr_Single", "ListOfStrings", "RecursiveListOfStrings", 
  "ListOfListOfDouble", "RecursiveListOfListOfDouble", "ListOfDouble", 
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor", 
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
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,    63,   433,
     434,   435,   436,   437,    60,    62,   438,   439,    43,    45,
      42,    47,    37,   440,    33,   441,   442,   443,    94,    40,
      41,    91,    93,    46,    35,    44,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   208,   209,   209,   209,   209,   210,   210,   211,   211,
     212,   212,   212,   213,   213,   214,   214,   214,   215,   215,
     215,   215,   215,   216,   216,   216,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   218,   218,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   220,   220,   221,   221,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   223,   223,   225,   224,   226,   226,
     228,   227,   229,   229,   231,   230,   232,   232,   234,   233,
     235,   235,   237,   236,   238,   238,   240,   239,   241,   241,
     243,   242,   244,   244,   246,   245,   247,   247,   249,   248,
     250,   250,   252,   251,   253,   253,   255,   254,   256,   256,
     258,   257,   259,   259,   261,   260,   262,   262,   264,   263,
     265,   265,   267,   266,   268,   268,   270,   269,   271,   271,
     273,   272,   274,   274,   276,   275,   277,   277,   279,   278,
     280,   280,   282,   281,   283,   283,   285,   284,   286,   286,
     288,   287,   289,   289,   291,   290,   292,   292,   294,   293,
     295,   295,   297,   296,   298,   298,   300,   299,   301,   302,
     302,   302,   302,   302,   303,   303,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   306,   306,   306,   306,   307,   307,   307,
     308,   308,   308,   308,   308,   308,   309,   309,   310,   310,
     310,   311,   312,   312,   312,   312,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   315,   315,   315,   316,   315,
     317,   315,   318,   315,   315,   315,   315,   319,   315,   320,
     315,   321,   315,   315,   315,   315,   322,   315,   323,   315,
     324,   315,   325,   325,   326,   326,   326,   327,   327,   327,
     327,   327,   327,   327,   327,   328,   328,   329,   329,   329,
     329,   329,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   332,   332,   332,
     332,   332,   333,   333,   333,   333,   334,   334,   335,   335,
     336,   336,   336,   337,   337,   338,   338,   338,   338,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   340,
     340,   340,   340,   341,   341,   341,   341,   342,   342,   343,
     343,   344,   344,   344,   344,   344,   344,   344
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     1,     2,     1,     2,     0,     2,
       1,    21,     1,     0,     2,     1,     1,     1,     2,     2,
       2,     2,     2,     7,     5,    17,     9,    23,    31,    15,
      11,    11,    15,     9,    13,     9,    11,    13,     9,     9,
      11,     9,    11,     9,    11,    13,    13,    11,    13,    17,
       9,    11,    11,    13,    11,     9,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     7,     6,     8,     0,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     3,     0,    13,     1,     3,
       0,    13,     1,     3,     0,    13,     1,     3,     0,    19,
       1,     3,     0,    19,     1,     3,     0,    19,     1,     3,
       0,    25,     1,     3,     0,    25,     1,     3,     0,    25,
       1,     3,     0,    31,     1,     3,     0,    31,     1,     3,
       0,    31,     1,     3,     0,    31,     1,     3,     0,    31,
       1,     3,     0,    31,     1,     3,     0,    55,     1,     3,
       0,    55,     1,     3,     0,    55,     1,     3,     0,    43,
       1,     3,     0,    43,     1,     3,     0,    43,     1,     3,
       0,    37,     1,     3,     0,    37,     1,     3,     0,    37,
       1,     3,     0,    13,     1,     3,     0,    15,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     7,     9,     6,
       3,     6,     6,     9,     6,     9,     5,     8,     8,    11,
       6,     9,     9,     9,     7,     8,    12,     6,     7,     7,
       7,     9,     7,     9,    17,     7,     7,    11,     8,    12,
       8,     8,     8,    12,    14,    14,    22,    20,     8,     8,
       8,     7,     8,     5,    11,     5,     9,     1,     1,     1,
       0,     2,     6,     6,     6,     6,     4,     6,     4,     6,
       3,     5,     3,     3,     4,     4,     3,     7,     3,     7,
       3,     2,     2,    15,     2,     6,     8,     8,    10,     1,
       2,     1,     3,     4,     1,     8,    12,    14,     0,    12,
       0,    16,     0,    18,     8,    12,    14,     0,    12,     0,
      16,     0,    18,     8,    12,    14,     0,    12,     0,    16,
       0,    18,     1,     2,     9,     7,     2,     6,     9,     9,
       8,     8,     8,     6,     4,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     1,     1,     1,     1,     1,     4,
       4,     2,     5,     3,     6,     4,     7,     1,     2,     2,
       3,     3,    11,     9,     7,     7,     0,     3,     1,     3,
       0,     3,     3,     1,     3,     1,     1,     3,     4,     3,
       5,     4,     1,     1,     1,     3,     4,     6,     7,     1,
       1,     3,     3,     9,     7,     1,     5,     3,     6,     1,
       3,     1,     6,     4,     4,     6,     6,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,     0,     0,     3,     2,     4,     5,     1,    10,    12,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    15,    17,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   299,     0,   304,     0,   301,     0,     0,
       0,     0,     0,    57,    59,    58,    60,    61,    62,    63,
      64,    65,    66,    71,    70,    67,    68,    69,     0,     0,
      18,    19,    21,    20,    22,   436,   436,     0,   414,   418,
     471,   209,   415,   416,   417,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   213,
     212,   211,   210,     0,     0,     0,   215,   214,     0,     0,
       0,     0,     0,     0,     0,   352,     0,     0,   292,     0,
     294,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     427,     0,     0,     0,     0,     0,     0,   270,     0,     0,
     270,   345,   346,     0,     0,     0,     0,     0,     0,     0,
     465,     0,     0,     0,     0,     0,   291,     0,   300,     0,
     471,   270,     0,   270,     0,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   421,     0,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   418,   355,   354,   356,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   288,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   418,     0,     0,     0,   452,   453,   454,
     445,     0,   446,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   429,
     428,     0,     0,     0,     0,   270,   270,     0,     0,     0,
       0,     0,     0,     0,   280,     0,     0,     0,     0,   290,
       0,     0,     0,     0,     0,     0,     0,   270,     0,     0,
       0,   302,     0,     0,   282,     0,   283,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   438,
       0,     0,     0,     0,     0,   423,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   353,     0,     0,   459,   460,
       0,     0,   209,     0,     0,     0,     0,     0,   216,     0,
     370,   369,   368,   367,   363,   364,   366,   365,   358,   357,
     359,   360,   361,   362,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     431,   430,   269,     0,   268,   267,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   276,   271,   344,     0,
       0,   278,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   303,     0,   284,   285,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   437,
       0,     0,    24,     0,   419,   425,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   440,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   372,   393,   373,   394,   374,   395,   375,   396,
     376,   397,   377,   398,   378,   399,   379,   400,   380,   401,
     392,   413,   381,   402,     0,     0,   383,   404,   384,   405,
     385,   406,   386,   407,   387,   408,   388,   409,     0,     0,
       0,     0,     0,     0,     0,     0,   474,     0,     0,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   226,
       0,     0,     0,     0,   420,     0,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   455,     0,     0,
       0,     0,   447,   449,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   263,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     439,     0,   436,     0,   422,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   440,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   419,
     219,   461,   462,     0,     0,     0,     0,     0,   221,   222,
     224,     0,     0,   469,     0,   230,   371,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   451,   456,
       0,   448,     0,   237,     0,     0,     0,     0,     0,     0,
     337,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,     0,     0,
       0,     0,   343,   279,     0,     0,     0,     0,     0,   440,
       0,   466,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   347,   348,   349,   350,   351,     0,     0,     0,     0,
       0,     0,     0,    23,     0,   424,   287,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   443,     0,     0,   382,   403,
     389,   410,   390,   411,   391,   412,     0,   476,   475,   472,
       0,   209,     0,     0,     0,     0,   217,     0,     0,     0,
     467,    73,     0,   234,   240,     0,   242,     0,     0,   238,
       0,   239,   261,     0,     0,   450,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   289,     0,     0,     0,     0,   270,     0,   308,     0,
     317,     0,   326,     0,     0,     0,     0,     0,     0,   245,
     246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   436,
     426,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   442,     0,
     441,   208,     0,     0,     0,     0,   227,     0,     0,   228,
       0,   470,     0,     0,     0,   248,   258,   457,     0,     0,
     341,   251,   252,     0,     0,     0,     0,   340,   342,   260,
     235,   250,   259,   262,     0,     0,     0,   435,     0,   434,
       0,     0,   305,     0,     0,   314,     0,     0,   323,     0,
     272,   273,   274,   275,     0,     0,   440,     0,     0,     0,
     464,     0,   297,   296,     0,     0,     0,     0,     0,    26,
       0,    35,     0,    39,     0,    33,     0,     0,    38,     0,
      43,    41,     0,     0,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   444,     0,   218,   223,   225,     0,   231,
       0,     0,   241,   243,   458,     0,     0,     0,   339,   338,
     232,   233,   270,     0,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   440,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   477,     0,
     468,     0,     0,     0,     0,     0,     0,   433,     0,     0,
       0,     0,     0,     0,     0,     0,   332,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   463,   298,
       0,     0,    40,     0,     0,     0,     0,    30,     0,    36,
       0,    42,    31,    44,     0,    47,     0,    51,    52,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     229,     0,     0,     0,     0,   264,     0,     0,   310,     0,
     336,     0,     0,   333,   319,     0,     0,   328,     0,     0,
       0,     0,     0,     0,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     110,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,     0,     0,     0,     0,   432,
     306,     0,     0,     0,   309,   315,     0,     0,   318,   324,
       0,     0,   327,   236,   249,     0,     0,   253,     0,     0,
       0,     0,     0,    34,    37,    45,     0,    46,    53,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   312,     0,     0,   321,     0,   330,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   206,     0,     0,   255,   254,     0,   307,     0,
       0,     0,   316,     0,     0,   325,     0,     0,     0,     0,
       0,     0,    29,    32,     0,     0,     0,   104,     0,   108,
       0,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   200,     0,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   311,     0,     0,   335,   320,     0,
     329,     0,     0,     0,     0,     0,     0,    49,    25,   105,
     107,   109,   111,   113,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,   203,     0,   204,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,   122,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   313,   334,   322,   331,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,   207,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   257,    11,     0,     0,     0,   116,     0,   120,
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,     0,    27,
     117,   119,   121,   123,   125,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   134,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,   132,     0,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   131,   133,   135,
     137,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   146,
     150,   154,   158,   162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   140,     0,   144,     0,   148,
       0,   152,     0,   156,     0,   160,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   143,   145,   147,
     149,   151,   153,   155,   157,   159,   161,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,   194,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,     0,   192,     0,   196,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   189,   191,   193,   195,   197,   199,
       0,     0,     0,   178,   182,   186,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,     0,   180,     0,   184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     179,   181,   183,   185,   187,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,   170,   174,     0,     0,     0,     0,
       0,     0,     0,   164,     0,   168,     0,   172,     0,     0,
       0,     0,     0,     0,   165,   167,   169,   171,   173,   175
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,   217,     3,    11,     4,    21,    22,    23,    24,
       5,    73,    74,    75,   447,  1676,   665,  1581,  1678,   666,
    1582,  1680,   667,  1583,  1896,   668,  1842,  1898,   669,  1843,
    1900,   670,  1844,  2032,   671,  1994,  2034,   672,  1995,  2036,
     673,  1996,  2144,   674,  2114,  2146,   675,  2115,  2148,   676,
    2116,  2150,   677,  2117,  2152,   678,  2118,  2154,   679,  2119,
    2342,   680,  2336,  2344,   681,  2337,  2346,   682,  2338,  2291,
     683,  2279,  2293,   684,  2280,  2295,   685,  2281,  2240,   686,
    2222,  2242,   687,  2223,  2244,   688,  2224,  1703,   689,  1605,
    1798,   690,  1705,   691,   142,   254,    76,   577,   347,   563,
     564,   348,    80,    81,    82,    83,    84,   349,  1233,  1551,
    1659,  1236,  1556,  1663,  1239,  1560,  1666,  1415,  1416,    86,
      87,  1006,   350,   145,   369,   180,   249,   440,   885,  1044,
    1045,   352,   500,   202,   753,   914,   146
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1378
static const short yypact[] =
{
    2760,    42,    34,   276,   273,  3239, -1378, -1378, -1378, -1378,
    -107, -1378,   122,    64,   134,   169,   210,   285,    12,    87,
     135, -1378, -1378, -1378, -1378,  2357,   145,    69,   312,   148,
     159,   163,   -37,   243,   168,   207,   277,   246,   358,   407,
     425,   443,   476,   453,   283,   263,   293,   -88,   -88,   314,
     360,     9,   466,    15,   544,   551,   156,   528,   336,   341,
     -13,    16,    18, -1378,   350, -1378,   560, -1378,   570,   574,
     556,    22,    68, -1378, -1378, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378,    23,  3069,
   -1378, -1378, -1378, -1378, -1378,   401,   401,   661, -1378,  -114,
      17, -1378, -1378, -1378, -1378,  -155,  -115,   115,   158,   196,
     280,   303,   329,   342,   376,   396,   397,   417,   445,   463,
     464,   496,   497,   500,   501,   512,   413,   420,   470, -1378,
   -1378, -1378, -1378,  2493,  2493,  2493, -1378, -1378,  2493,   992,
      39,   666,  2493,   682,   469, -1378,   685,   689, -1378,  2493,
   -1378,  2493,  2493,  2493,   511,  2493,   527,  2493,  2493,   611,
    2493,   557,   533,   536,   -62,   611,   558,   573,   561,   581,
     584,   591,   595,   769,   -88,   -88,   -88,  2493,  2493,   -83,
   -1378,   -67,   -88,   592,   610,   624,   555, -1378,   611,    19,
   -1378, -1378, -1378,   611,   611,   797,  2493,  2493,   -65,  2493,
     628,  2493,   659,   770,  2493,  2493, -1378,   879, -1378,   690,
   -1378, -1378,   906, -1378,   918, -1378,   925,    23,   734,   746,
     747,   753,   754,   755,   756,   757,   758,   759,   760,   776,
     777,   778,   779,   783,   784,   785,   786,   787,   788,   789,
     790,   791,   793,   794,   798,   799,   801,   826,   946,   821,
     781,   822,  2493,  1024, -1378,   -88, -1378,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,    63,
      56,    56,   311,   831,   831,   831,  1296,  1023,  2391, 11342,
     174,   828,  1028,   833,   712, -1378, -1378,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493, -1378,  -141,  3710,  2249, 11930, 11953,  2493, 11976,
    2493, 11999, 12022,   328,   830,  1627,  2391, -1378, -1378, -1378,
     872,  1031, -1378, 12045,  2493,  2493,  2493,  2493,  2493,  1032,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,   840,     5, -1378,
   -1378,  3734,  3758,   -88,   -88,   529,   529,   202,  2493,  2493,
    2493,  2493,  2625,   109, -1378,  2493,  2794,  1034,  1035, -1378,
   12068, 12091,   937,  2493, 12114,   939,  3782, -1378,   839,  1828,
   12137, -1378,  2493,  2890, -1378,  2925, -1378, -1378,    23,  1043,
    1044,  1048,  1066,  1067,  1068,  1069,  1070,  1074,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1089,
    1090,  1091,   940,  1092,  1094,  1095,  1096,  1100,  1102, -1378,
    -120,  1103,  1104,  1107, 11363,    11,   -28,  2990, 12160, 11384,
   12183, 11405, 12206, 11426, 12229, 11447, 12252, 11468, 12275, 11489,
   12298, 11510, 12321, 11531, 12344, 11552, 12367, 11573, 12390, 11594,
    3806,  3830, 12413, 11615, 12436, 11636, 12459, 11657, 12482, 11678,
   12505, 11699, 12528, 11720,  3854,  3878,  3902,  3926,  3950,  3974,
     513,   -93,   904,   913,  2493, -1378,   611,  2588,   872, -1378,
     356,   189,    56,  2493,  1108,  1112,    20,   915, -1378,  1941,
     731,   495,   419,   419,   381,   381,   381,   381,   354,   354,
     831,   831,   831,   831,  1113,  2391,  2493,  1111,  1114,  1118,
   12551,  1120, 12574,  1121,  1123,  1218,  2493,   359,  2391,   514,
    2493,  2493,  1124,  2386, 12597, 12620, 12643,  3062,  2493,  3210,
    3242, 12666, 12689, 12712, 12735, 12758,   917,   -88,  2493,  2493,
   -1378, -1378, -1378,   927,  3272, -1378,   928,  2493,  3998,  4022,
    4046, 11741,   -57,   -43,   -15,   113, -1378, -1378, -1378,  2493,
   11762, -1378,   926,   930,  1156,  1157,   966, 12781,  1159,   964,
    2493,  2991,  2493,  2493, -1378, 12804, -1378, -1378,   998,   965,
     967,   968,   969,   970,   971,   973,   974,   977,   978,   980,
     982,   983,   984,   985,   987,   988,   990,   994,   995,   996,
     997,   999,  1003,  1018,  1049,  1050,  1051,  1093,  1106, -1378,
    1164,  1053, -1378,  1110,   149, -1378, -1378,   972,  1087,  1101,
    1119,  1122,  1125,  1126,  1127,  1128,  1129,  1132,  1134,  1135,
    1136,  1137,  1139,  1140,  1141,  1142,  1144,  1145,  1147,  1175,
    1176,  1180,  1181,   182,  1191, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378,  2493,  2493, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  1277, -1378,  2391,    56, -1378,
   11783,  1276,  2391,  1097,    49,  2493,  1299,  1301,   752, -1378,
    1302,  1185,    16,  1307, -1378,  2493, -1378,   -50,  4070,   -88,
     611,   611,  1312,   611,  1315,   611,   611, -1378,  2391,  3268,
    1248,   517, -1378,  2451,   782,  1117,  1375,  1380,  1381,  1385,
    1397,   305,  1398,  1401,  1403,  1404,  1406,  1408,  1412,  1410,
     205,  4094,  4118, -1378, -1378,  3294,   -88,   -88,   -88,  1415,
    2391,  2391,  2391,  2391,  1027,  1417,  2493,  2493,   611,   611,
    2493,  1418,   611,  1422,  4142, -1378,  2520,   684,  1420,  1257,
    1426,  2493,  2493,   -88,  1427,  1428,  1242,  1430,  1431,   611,
     611,  1432,   -88,  1435,  1437,   611,   611,  1438,  1440,  1441,
    1442,  1443,   611,   455,   611,  1445,  1444,  1446,  1450,  1452,
   -1378,  1451,   401,  1454, -1378,  1453,  3060,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,   611,   611,   182, -1378, 12827, 11804, 12850,
   11825, 12873, 11846, 12896, 11867, 11888,  1256,   -41,  1260,   -30,
   -1378,   872, -1378,    28,   362,  1258,  1455,  1105, -1378, -1378,
   -1378,    16,  2493, -1378,   518, -1378, 13770,  1457,  2493,    25,
      26,    31,   611,  1459,   611,  1460,  1461,   522, -1378, -1378,
    2391, -1378,  2493, -1378,  2493,   611,   611,   611,  1269,  1270,
   -1378,   380,   611,   611,   611,   611,   611,   611,   611,   467,
    2493,  2493,  2493,  1265,  -111,   -69,   191, -1378,   526,   531,
     534,   535, -1378, -1378,  4166,  4190,  1466,  1471, 12919,   182,
    1383, -1378,  2493,  2493,  2493, -1378,  1286,  1326,  1290,  4214,
    4238,   282,  1313,  1324,  1331,  1337,  1333,  1339,  1335,  1356,
     317,  1357,  1342,  1344,  1358,  1359,  1362,  1363,  1364,  1365,
    1371, -1378, -1378, -1378, -1378, -1378,  1368,  1369,  1370,  1372,
    1373,  1376,  1374, -1378,  1377,    11, -1378,  1574,  4262,  4286,
    4310,  4334,  4358,  4382,  4406,  4430,  4454,  4478,  4502,  4526,
    4550,  4574,  4598,  4622,  4646,  4670,  4694,  4718,  4742,  4766,
    4790,  4814,  4838,  4862,   -35, -1378,   539,  1577, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378,  1382, -1378, -1378, -1378,
     611,    56,  2493,  1578,  1583,    20, -1378,  1582, 11909,    16,
   -1378, -1378,  4886, -1378, -1378,   -88, -1378,   -88,  1584, -1378,
    1585, -1378, -1378,  1390,   542, 13770,  4910,  1587,  1588,  1590,
    2493,  2493,  2493,  2493,  1591,  1592,  1593,  1620,  1621,  1622,
    1623, -1378,  2459,  3320, 12942,  1211,   529,   -88,  1626,   -88,
    1628,   -88,  1654,  1658,  1670,  1671,  1673,  2493,  2493, -1378,
   -1378,  1676,  1526,   611,  2551,   269, 12965,  2493,    23,  1681,
    2493,   611,  1679,  1683,  1682,  1497,  1684,   455,  1685,  1686,
    2493,  1687,  1691,  1689,  1690,  1694,   455,  2493,  2493,  2493,
     611,  1693,  1698,   455,  2493,  1700,  1722,  1720,  2493,   401,
   -1378, -1378,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493, -1378,   611,
   -1378, -1378,  1723,  1724,  1725,  1367, -1378,  1721,  1729, -1378,
    1544, -1378,  2493,    30,   119, -1378, -1378, -1378,  1527,  2493,
   -1378, -1378, -1378,  4934,  4958,  1483,  1554, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378,  1580,  1742,  1543, -1378,  2493, -1378,
    1546,   216, -1378,  1545,   220, -1378,  1548,   223, -1378,  1549,
   -1378, -1378, -1378, -1378,  4982,  5006,   182,  1550,  1653,  2493,
   -1378,  2493, -1378, -1378,  5030,    23,  1573,  5054,  1569, -1378,
    1570, -1378,  1571, -1378,  1579, -1378,  1572, 12988, -1378,  1581,
   -1378, -1378,  1606,  1607, 13011,  5078, 13034,  1603, -1378,  1609,
    1610,  5102,  1608,  1611, -1378,  5126,  1612,  5150,  5174,  5198,
    5222,  5246,  5270,  5294,  5318,  5342,  5366,  5390,  5414,  5438,
    5462,  5486,  5510,  5534,  5558,  5582,  5606,  5630,  5654,  5678,
    5702,  5726,  5750, -1378,  1614, -1378, -1378, -1378,    16, -1378,
    1674,  5774, -1378, -1378, -1378,  5798,  2493,  2493, -1378, -1378,
   -1378, -1378,   529,  2982, -1378,  1863,   125,  1863,   125,  1863,
     125,  2493,  2493,  1675,   611,  2493,  3346,  3372,   611,    23,
    1778,   182,   455,  1782,  2493,  1781,   455,  1806,  1815,  1813,
    1814,  1816,  2493,  1817,   611,  1818,  1819,  2493,  1824,  1822,
    2493,  1825,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493, -1378,  1823,
   -1378,  2493,  1827, 13057, 13080,  1630,  2493, -1378,  1863,  1863,
    2493,  3398,   234,  1829,  1632,   -39, -1378,  3424,   238,   -20,
    3450,   241,   -18,  3476,  3502,  1633,  1629,  1744, -1378, -1378,
    1634,  1677, -1378,  1637,  1638,  1663,  5822, -1378,  1669, -1378,
    1696, -1378, -1378, -1378, 13103, -1378,  1665, -1378, -1378, 13126,
    1697, -1378, 13149,  1666, 13172, 13195, 13218,  5846,  5870,  5894,
    5918,  5942,  5966,  5990,  6014,  6038,  6062,  6086,  6110,  6134,
    6158,  6182,  6206,  6230,  6254,  6278,  6302,  6326, 13241,  6350,
   -1378,  6374,  1732,   611,   611, -1378,  3528,  1343,  1893,  2493,
   -1378,   611,  1895, -1378,  1919,  2493,  1932,  1933,  2493,  1934,
    1935,  1937,   611,   611, -1378,  1938,    23,   455,   455,   455,
     455,  1939,  1940,  1942,   455,  1944,  1945,  1946,  1963, -1378,
   -1378, -1378,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493, -1378,  2493,  2493,  1964,   611,   611, -1378,
   -1378,  1741,  3554,  1765, -1378, -1378,  1766,  3580, -1378, -1378,
    1767,  3606, -1378, -1378, -1378,  1769,  1764, -1378,    23,  1770,
    1771,  1777,  1779, -1378, -1378, -1378,  1773, -1378, -1378, -1378,
    1775,  1776,  1780,  1803,  6398,  6422,  6446,  6470,  6494,  6518,
    6542,  6566,  6590,  6614,  6638,  6662,  6686,  6710,  6734,  6758,
    6782,  6806,  6830,  6854,  6878,  1821, 13264,  3632,  1820,  1975,
    1977,   125,  1978,   611,   125,  1979,   125,  1981,   611,  1917,
      23,   455,   455,  2016,  2017,   455,  2019,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,    56, -1378,  2022,  2025, -1378, -1378,   -17, -1378,  1826,
     543,    -7, -1378,  1844,    -1, -1378,  1847,  1848,  1850,  1867,
    1849,  1853, -1378, -1378,  1859,  1860,   546, 13770,   547, 13770,
     550, 13770,  6902,  6926,  6950,  6974,  6998,  7022,  7046,  7070,
    7094,  7118,  7142,  7166,  7190,  7214,  7238,  7262,  7286,  7310,
    7334,  7358,  7382,   554, -1378,  1855, -1378,  1856,  2058,   125,
     611,  2059,  2060,   125,  2062,   125,  1966,  2493,    23,   455,
     611,  2065,  2066,  2493,  2067,  2493,  2068,  2493,  2069,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
      56,  2070,    56,  2071, -1378,     2,  1871, -1378, -1378,    74,
   -1378,   110,  1882,  7406,    23,  1884,  1885, -1378, -1378, 13770,
   -1378, 13770, -1378, 13770, -1378, 13287, 13310, 13333,  7430,  7454,
    7478,  7502,  7526,  7550,  7574,  7598,  7622,  7646,  7670,  7694,
    7718,  7742,  7766,  7790,  7814,  7838, -1378, -1378,   563, -1378,
   -1378,  2085,  2086,  2087,  2088,  2493,  2493,    23,   455,   611,
   -1378, -1378, -1378,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,    56,  2089, -1378, -1378, -1378, -1378,  7862,  3658,  1924,
    1892,  1894,  1896,  1897,  1916,  7886,  7910,  7934,  7958,  7982,
    8006,  8030,  8054,  8078,  8102,  8126,  8150,  8174,  8198,  8222,
    8246,  8270,  8294, -1378, -1378,  2493,  2092,  1927,   611,   455,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  3684, -1378, -1378,  1929,  1901,   564, 13770,   567, 13770,
     579, 13770,  8318,  8342,  8366,  8390,  8414,  8438,  8462,  8486,
    8510,  8534,  8558,  8582,  8606,  8630,  8654,  8678,  8702,  8726,
    2129,   611,  2130,  2493,  2131,  2493,  2132,  2493,  2135,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493, -1378,  1956, -1378,
   13770, -1378, 13770, -1378, 13770, -1378, 13356, 13379, 13402,  8750,
    8774,  8798,  8822,  8846,  8870,  8894,  8918,  8942,  8966,  8990,
    9014,  9038,  9062,  9086,   611, -1378, -1378, -1378,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  1957,  1943,  1958,  1959,  9110,  9134,  9158,
    9182,  9206,  9230,  9254,  9278,  9302,  9326,  9350,  9374,  9398,
    9422,  9446,   611,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  1961,   582, 13770,   586, 13770,   597, 13770,  9470,  9494,
    9518,  9542,  9566,  9590,  9614,  9638,  9662,  9686,  9710,  9734,
    9758,  9782,  9806,   455,  2493,  2137,  2493,  2139,  2493,  2141,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  1951, 13770, -1378, 13770, -1378,
   13770, -1378, 13425, 13448, 13471, 13494, 13517, 13540,  9830,  9854,
    9878,  9902,  9926,  9950,  9974,  9998, 10022,  2157, -1378, -1378,
   -1378, -1378, -1378, -1378,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493, -1378,  1965,  1968,  1969,  1970,  1971,  1972,
   10046, 10070, 10094, 10118, 10142, 10166, 10190, 10214, 10238,  2493,
    2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,   601, 13770,   602, 13770,   606, 13770,
     607, 13770,   613, 13770,   614, 13770, 10262, 10286, 10310, 10334,
   10358, 10382, 10406, 10430, 10454,  2493,  2163,  2493,  2173,  2493,
    2174,  2493,  2175,  2493,  2182,  2493,  2183,  2493,  2493,  2493,
    2493,  2493,  2493,  2493,  2493,  2493, 13770, -1378, 13770, -1378,
   13770, -1378, 13770, -1378, 13770, -1378, 13770, -1378, 10478, 10502,
   10526, 10550, 10574, 10598, 13563, 13586, 13609,  2493,  2493,  2493,
    2493,  2493,  2493, -1378, -1378, -1378, 10622, 10646, 10670, 10694,
   10718, 10742,  1984,  1985,  1986,  2493,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2493, 10766, 10790, 10814, 10838, 10862, 10886,
     617, 13770,   618, 13770,   621, 13770,  2493,  2493,  2493,  2493,
    2493,  2493,  2493,  2187,  2493,  2188,  2493,  2189, 10910, 10934,
   10958, 13632, 13655, 13678, 13770, -1378, 13770, -1378, 13770, -1378,
    2493,  2493,  2493, -1378, -1378, -1378, 10982, 11006, 11030,  1990,
    1991,  1992,  2493,  2493,  2493,  2493,  2493,  2493, 11054, 11078,
   11102,   622, 13770,   653, 13770,   654, 13770,  2493,  2493,  2493,
    2493,  2193,  2493,  2203,  2493,  2204, 11126, 11150, 11174, 13770,
   -1378, 13770, -1378, 13770, -1378,  2493,  2493,  2493, 11198, 11222,
   11246,  2493,  2493,  2493, 11270, 11294, 11318,  2493,  2493,  2493,
   13701, 13724, 13747, -1378, -1378, -1378,  2005,  2006,  2007,  2493,
    2493,  2493,   672, 13770,   681, 13770,   701, 13770,  2493,  2208,
    2493,  2211,  2493,  2212, 13770, -1378, 13770, -1378, 13770, -1378
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -1378, -1378,  -129, -1378, -1378, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378,  1594, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1378,
   -1378, -1378, -1378, -1378,  -302,   -21, -1378,  2215,    -2,  -369,
    -172,     0, -1378, -1378, -1378, -1378, -1378,  2223, -1378, -1378,
   -1378, -1378, -1378, -1378, -1378, -1378, -1378, -1326, -1377, -1378,
   -1378, -1074,   -25, -1378,   -31, -1378,   -90, -1378,  -874,  1348,
    1407,  -215,  -337,  -742,  1168, -1378,   -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -57
static const short yytable[] =
{
     144,   212,   214,    78,   143,    79,   250,   566,   503,   539,
     913,  1047,  1419,   186,  1422,   382,   179,   181,   386,   189,
     200,   255,   203,   154,   751,   384,   215,   210,  1413,   154,
     198,  1073,  1074,  1414,     7,   101,  1322,  1076,  1493,   403,
     392,   405,  1493,   310,   257,  1493,   258,  1413,     6,  1413,
    1413,   156,  1414,   904,  1414,  1414,   126,   127,   128,   524,
    1413,   210,    88,  1264,   525,  1414,  1413,   490,   210,  1413,
      90,  1414,  1273,   210,  1414,   148,  1075,   373,   374,  1280,
     629,  1077,   136,   137,   259,   630,   260,   252,   408,   253,
     126,   127,   128,   499,  1107,  1122,  1108,   126,   127,   128,
     175,   176,   126,   127,   128,   373,   374,   736,   303,   304,
     305,   177,   737,   306,   309,   578,   579,   314,   178,   373,
     374,   373,   374,   375,   334,  1323,   335,   336,   337,    89,
     339,   499,   341,   342,   393,   353,  1109,   357,  1110,   376,
      91,  1413,   151,   368,   358,   370,  1414,   311,   312,   800,
     917,   377,   371,   372,   210,   742,   155,   905,   906,  1058,
     373,   374,   155,   801,   742,  1188,   136,   137,  1492,  1067,
    1189,   390,   391,   853,   394,    92,   396,  1413,   636,   399,
     400,   502,  1414,   126,   127,   128,   199,  1496,   757,  1499,
    1708,   802,  1413,   373,   374,   193,   101,  1414,   194,   745,
    1712,   771,   129,   130,   131,   132,  1714,   136,   137,  1801,
     557,    95,   216,   373,   374,   187,    93,   204,   373,   374,
     385,   190,   201,   256,   446,   591,   752,   444,   211,   491,
     492,   493,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   213,   149,    12,  1251,  1434,   598,
    1493,  1803,  1438,   498,  1493,  1657,    96,  1493,  1661,   504,
    1664,    94,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   373,   374,   156,
     499,   940,   158,   530,   261,   532,   262,  1804,   150,   803,
     304,   498,   169,   499,   159,   170,   171,  1201,   172,   543,
     544,   545,   546,   547,    97,   549,   550,   551,   552,   553,
     554,   555,   560,   561,   147,   136,   137,   151,   129,   130,
     131,   132,   853,   568,   569,   570,   571,   263,   152,   264,
     580,   941,   153,   129,   130,   131,   132,   157,   587,  1061,
     136,   137,  1343,   562,   562,   565,   565,   595,  1493,   373,
     374,   883,  1493,  1755,  1493,   136,   137,  1759,   884,  1761,
     373,   374,   744,   373,   374,   265,  1111,   266,  1112,   183,
     897,   161,   184,   185,   373,   374,   158,   567,   373,   374,
     950,   373,   374,    13,    14,    15,    16,    17,    18,    19,
      20,  1335,   373,   374,   635,  1337,   373,   374,  1339,   373,
     374,   927,   747,  1569,  1570,  1571,  1572,  1092,  1093,  1489,
    1576,     8,     9,  1495,    10,   160,  1498,   317,   318,   319,
     162,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   173,   958,   959,   960,   961,   331,   163,   740,
     373,   374,   304,  1101,  1102,   316,  1252,  1433,   748,   267,
     746,   268,  1132,   317,   318,   319,   164,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   168,   174,
     498,   758,   269,   331,   270,   373,   374,   136,   137,   188,
     740,   769,   494,   498,   253,   773,   774,  1141,   165,   166,
     182,   167,   499,   781,   136,   137,   790,   902,   271,   535,
     272,   253,   195,   791,   792,   196,   129,   130,   131,   132,
     197,   273,   795,   274,   328,   329,   330,  1670,  1671,   205,
     191,  1674,   331,   499,   804,   136,   137,   192,   136,   137,
     770,   742,   253,   743,   855,   814,   206,   816,   817,   326,
     327,   328,   329,   330,   207,   275,  1399,   276,   208,   331,
    1001,  1002,  1003,  1004,  1005,   499,   499,   499,   499,    46,
      47,    48,    49,  1084,    51,   277,   279,   278,   280,   209,
     248,  1060,  1062,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   299,   854,    98,   343,   281,   331,   282,   300,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   283,  1765,   284,   317,   318,   319,
     344,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   285,   287,   286,   288,   251,   331,   898,   301,
     313,    46,    47,    48,    49,    50,    51,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   315,   887,
     888,   332,   974,   331,   333,   289,   291,   290,   292,   293,
     295,   294,   296,   889,   890,   891,   892,   893,   894,   895,
     338,   297,   498,   298,   734,   499,   735,   901,   508,   742,
     907,   772,   742,  1069,   931,  1070,   340,   742,   919,  1083,
     916,   742,   355,  1113,  1840,   356,   742,  1230,  1114,   742,
     742,  1115,  1116,   498,  1189,   740,  1190,   742,  1710,  1208,
    1711,  1723,  1725,  1724,  1726,  1727,   381,  1728,   910,  1750,
     362,  1751,  1014,   354,   360,   954,   955,   956,  1831,  1923,
    1832,  1924,  1925,   367,  1926,   498,   498,   498,   498,   361,
     363,   964,   965,   364,  1927,   968,  1928,  2054,   933,  2055,
     365,  2056,   981,  2057,   366,  1895,   979,   980,   378,   133,
     345,   990,  2058,   389,  2059,   135,  2165,  2167,  2166,  2168,
     138,  2169,  2171,  2170,  2172,   141,   379,   346,  2173,  2175,
    2174,  2176,  2252,  2254,  2253,  2255,  2256,  2300,  2257,  2301,
     380,   395,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  2302,  2304,
    2303,  2305,   317,   318,   319,   397,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,  2348,   854,  2349,
     540,   398,   331,  1063,   975,   401,  2350,  1068,  2351,   402,
     317,   318,   319,  1072,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   498,  2352,  1085,  2353,  1086,
     331,   319,   404,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   406,  1103,  1104,  1105,   407,   331,
     317,   318,   319,   409,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   410,   411,  1124,  1125,  1126,
     331,   439,   412,   413,   414,   415,   416,   417,   418,   419,
     317,   318,   319,  1405,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   420,   421,   422,   423,  2075,
     331,   442,   424,   425,   426,   427,   428,   429,   430,   431,
     432,  1194,   433,   434,  1160,    98,   302,   435,   436,  1255,
     437,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   438,   441,   443,   445,   331,
     496,   505,  1225,   962,   507,   506,   536,  1195,   541,   548,
     556,   582,   583,   586,  1203,   592,  1204,   589,   599,   600,
     317,   318,   319,   601,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,  1213,  1214,  1215,  1216,  1286,
     331,   602,   603,   604,   605,   606,  1231,  1224,  1234,   607,
    1237,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,  1244,  1245,   619,   620,   621,   623,   622,   624,
     625,   626,  1254,   627,   562,  1257,   565,   628,   631,   738,
     632,  1066,   633,   739,   749,  1267,   750,   754,   759,   756,
     789,   760,  1274,  1275,  1276,   761,  1349,   763,   765,  1281,
     766,   775,   806,  1285,   793,   794,   807,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,
    1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,
    1310,  1311,  1312,   808,   809,   810,   812,   813,   819,   850,
     820,   857,   821,   822,   823,   824,   825,  1321,   826,   827,
     133,   134,   828,   829,  1325,   830,   135,   831,   832,   833,
     834,   138,   835,   836,   307,   837,   141,   886,   308,   838,
     839,   840,   841,  1333,   842,   317,   318,   319,   843,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
    1431,    98,   302,   844,  1346,   331,  1347,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    98,   302,   851,   845,   846,   847,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   896,   900,   317,   318,   319,   858,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   848,   903,
     859,  1403,  1404,   331,  1412,   908,  1418,   909,  1421,   911,
    1411,   849,  1417,   915,  1420,   852,  1423,  1424,   860,   922,
    1427,   861,   924,   934,   862,   863,   864,   865,   866,  1436,
     562,   867,   565,   868,   869,   870,   871,  1444,   872,   873,
     874,   875,  1449,   876,   877,  1452,   878,  1454,  1455,  1456,
    1457,  1458,  1459,  1460,  1461,  1462,  1463,  1464,  1465,  1466,
    1467,  1468,  1469,  1470,  1471,  1472,  1473,  1474,  1475,  1476,
    1477,  1478,  1479,  1317,   879,   880,  1481,  1568,   370,   881,
     882,  1486,   935,   303,   304,  1487,   912,   936,   937,   317,
     318,   319,   938,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   939,   942,   133,   134,   943,   331,
     944,   945,   135,   946,   949,   947,  1228,   138,  1229,   948,
     767,   957,   141,   963,   768,   969,   971,   976,   977,   978,
     982,   983,   984,   985,   986,   989,   133,   134,   991,  1620,
     992,   995,   135,   996,   997,   998,   999,   138,  1008,  1009,
     929,  1010,   141,  1011,   930,  1012,  1057,  1013,  1015,  1016,
    1059,  1064,  1065,  1071,  1552,  1079,  1081,  1082,  1090,  1091,
    1557,  1106,  1119,  1561,   317,   318,   319,  1120,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,  1328,
    1123,  1669,  1127,  1128,   331,  1129,   495,  1584,  1585,  1586,
    1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,  1596,
    1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,  1133,  1606,
    1607,   317,   318,   319,  1134,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,  1135,  1136,  1137,  1138,
    1139,   331,  1143,   495,  1144,   317,   318,   319,   558,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
    1329,  1140,  1142,  1145,  1146,   331,   351,  1147,  1148,  1149,
    1150,  1151,   359,  1152,  1153,  1154,  1157,  1155,  1156,  1158,
    1161,  1704,  1159,  1191,  1196,  1192,  1330,  1197,  1199,  1764,
    1205,  1206,  1207,  1210,  1211,   383,  1212,  1217,  1218,  1219,
     387,   388,  1677,  1679,  1681,  1682,  1683,  1684,  1685,  1686,
    1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,  1695,  1696,
    1697,  1698,  1699,  1700,  1701,  1702,  1220,  1221,  1222,  1223,
      98,   537,  1232,  1247,  1235,  1807,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
    1238,   317,   318,   319,  1240,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,  1241,  1242,  1839,  1243,
    1796,   331,  1799,  1246,  1256,  1259,  1260,  1262,  1261,  1266,
    1263,  1265,  1763,  1268,  1269,  1270,  1271,  1272,  1769,  1278,
    1771,  1279,  1773,  1282,  1775,  1776,  1777,  1778,  1779,  1780,
    1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,
    1791,  1792,  1793,  1794,  1795,  1283,  1284,  1314,  1318,  1324,
    1315,  1316,   317,   318,   319,  1319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,  1320,  1331,  1332,
    1504,  1336,   331,  1334,  1338,  1340,  1344,  1345,   317,   318,
     319,  1863,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,  1350,  1352,  1353,  1354,  1356,   331,  1355,
    1837,  1838,  1425,  1400,  1432,  1435,  1358,  1437,  1845,  1846,
    1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,
    1857,  1858,  1859,  1860,  1861,  1862,  1359,  1360,  1364,  1365,
    1366,  1369,  1439,  1368,  1398,   133,   134,  1371,  1440,  1441,
    1442,   135,  1443,  1445,  1447,  1448,   138,  1450,  1451,  1480,
    1453,   141,  1482,   538,  1503,  1490,   593,  1485,  1491,  1502,
    1891,  1505,  1507,  1508,  1506,  1897,  1899,  1901,  1902,  1903,
    1904,  1905,  1906,  1907,  1908,  1909,  1910,  1911,  1912,  1913,
    1914,  1915,  1916,  1917,  1918,  1919,    98,   302,  1509,  1511,
    1514,  1518,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,  1512,  1516,  1950,  1550,
    1952,  1554,  1954,   741,  1956,  1957,  1958,  1959,  1960,  1961,
    1962,  1963,  1964,  1965,  1966,  1967,  1968,  1969,  1970,  1971,
    1972,  1973,   317,   318,   319,  1555,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,  1546,  1558,  1559,
    1562,  1563,   331,  1564,  1567,  1573,  1574,  1611,  1575,   755,
    1577,  1578,  1579,  1997,  1998,  1999,  2000,  2001,  2002,  2003,
    2004,  2005,  2006,  2007,  2008,  2009,  2010,  2011,  1580,  1608,
    1613,  1619,  1614,  1616,  1618,  1621,  1622,  1623,  1625,  1624,
    1626,  1655,  1627,  1656,  1658,  1662,  1628,  1665,  2033,  2035,
    2037,  2038,  2039,  2040,  2041,  2042,  2043,  2044,  2045,  2046,
    2047,  2048,  2049,  2050,  2051,  2052,   317,   318,   319,  1629,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,  1668,  1672,  1673,  1675,  1654,   331,  1651,  1706,  2076,
    1707,  2078,  1709,  2080,  1718,  2082,  2083,  2084,  2085,  2086,
    2087,  2088,  2089,  2090,  2091,  2092,  2093,  2094,  2095,  2096,
    1713,  1408,  1409,  1715,  1719,  1716,  1717,   135,  1720,  1721,
    1722,  1752,  1410,  1753,  1754,  1757,  1758,   141,  1760,   178,
    1762,  1767,  1768,  1770,  1772,  1774,  1797,  1800,  1802,  2120,
    2121,  2122,  2123,  2124,  2125,  2126,  2127,  2128,  1805,  1808,
    1809,  1833,  1834,  1835,  1836,  1864,  1867,  1868,  1892,  1869,
    1893,  1922,  1870,  1871,  2145,  2147,  2149,  2151,  2153,  2155,
    2156,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,   317,
     318,   319,  1872,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,  1921,  1947,  1949,  1951,  1953,   331,
    2186,  1955,  2188,  2077,  2190,  2079,  2192,  2081,  2194,  2013,
    2196,  2097,  2198,  2199,  2200,  2201,  2202,  2203,  2204,  2205,
    2206,  1974,  2012,  2113,  2014,  2015,  2053,   920,   921,  2187,
     923,  2129,   925,   926,  2130,  2131,  2132,  2133,  2134,  2189,
    2191,  2193,  2216,  2217,  2218,  2219,  2220,  2221,  2195,  2197,
    2231,  2232,  2233,  2265,  2267,  2269,  2285,  2286,  2287,  2310,
    2234,  2235,  2236,  2237,  2238,  2239,  2241,  2243,  2245,  2312,
    2314,  2339,  2340,  2341,  2355,   966,   967,  2357,  2359,   970,
      77,  2258,  2259,  2260,  2261,  2262,  2263,  2264,    85,  2266,
     856,  2268,  1046,  1198,     0,     0,   987,   988,     0,     0,
       0,     0,   993,   994,     0,  2276,  2277,  2278,     0,  1000,
       0,  1007,     0,     0,     0,     0,     0,  2288,  2289,  2290,
    2292,  2294,  2296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2306,  2307,  2308,  2309,     0,  2311,     0,  2313,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2318,  2319,  2320,     0,     0,     0,  2324,  2325,  2326,     0,
       0,     0,  2330,  2331,  2332,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2343,  2345,  2347,     0,     0,     0,
       0,     0,     0,  2354,     0,  2356,     0,  2358,     0,  1078,
       0,  1080,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1087,  1088,  1089,     0,     0,     0,     0,  1094,
    1095,  1096,  1097,  1098,  1099,  1100,     0,     0,     0,     0,
      98,    99,   100,     0,   101,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,   127,   128,    98,   343,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,     0,     0,     0,   317,   318,   319,
     344,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,   527,
       0,    46,    47,    48,    49,    50,    51,     0,     0,   932,
       0,     0,    98,   302,   210,     0,     0,  1193,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,   127,   128,    98,   302,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     0,     0,   973,     0,
    1248,   129,   130,   131,   132,     0,     0,     0,  1258,     0,
       0,     0,     0,     0,     0,   133,   134,     0,     0,     0,
       0,   135,     0,   136,   137,     0,   138,  1277,   139,     0,
     140,   141,     0,     0,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   133,
     497,     0,     0,     0,   331,   135,     0,     0,     0,     0,
     138,    98,   537,   776,     0,   141,  1313,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,     0,     0,     0,     0,     0,     0,     0,     0,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,   133,   134,   331,
       0,     0,     0,   135,     0,     0,     0,     0,   138,     0,
       0,     0,     0,   141,   572,    30,    31,   573,   574,    34,
     575,    36,     0,    37,     0,    39,    40,    41,     0,    43,
      44,   133,   134,     0,     0,     0,     0,   135,     0,     0,
       0,     0,   138,     0,     0,     0,    56,   141,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,    70,     0,     0,     0,     0,   331,
       0,  1426,     0,     0,     0,  1430,  1249,     0,  1250,     0,
      -8,     1,     0,   -13,   -56,     0,     0,     0,     0,     0,
       0,  1446,     0,     0,     0,     0,   133,   134,     0,     0,
       0,     0,   135,     0,     0,     0,     0,   138,     0,     0,
       0,     0,   141,   -56,     0,     0,     0,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,     0,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,     0,     0,     0,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,     0,   -56,   -56,   -56,
     -56,   -56,   576,   572,    30,    31,   573,   574,    34,   575,
      36,     0,    37,     0,    39,    40,    41,     0,    43,    44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -56,   -56,   -56,   -56,     0,    56,     0,     0,   -56,     0,
     -56,     0,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,     0,     0,     0,     0,     0,     0,     0,     0,
    1547,  1548,     0,     0,     0,    58,    59,    60,  1553,     0,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,     0,  1565,
    1566,     0,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -8,    -8,     0,    -8,   572,
      30,    31,   573,   574,    34,   575,    36,     0,    37,     0,
      39,    40,    41,     0,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,  1609,  1610,     0,     0,     0,     0,
       0,    56,     0,     0,   572,    30,    31,   573,   574,    34,
     575,    36,     0,    37,     0,    39,    40,    41,     0,    43,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,     0,     0,    56,     0,     0,     0,
       0,   581,     0,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1660,     0,     0,     0,     0,  1667,    58,    59,    60,     0,
     572,    30,    31,   573,   574,    34,   575,    36,     0,    37,
       0,    39,    40,    41,    70,    43,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
       0,     0,    58,    59,    60,     0,     0,   596,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,   218,     0,     0,     0,     0,     0,  1756,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1766,     0,     0,
       0,     0,   597,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,     0,     0,     0,  1406,     0,  1407,
       0,   219,   220,   221,     0,     0,     0,   664,   815,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,     0,
       0,     0,     0,     0,     0,     0,  1841,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   242,   243,
     244,   245,   246,   247,     0,     0,     0,     0,     0,     0,
     317,   318,   319,    25,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,     0,     0,     0,  1017,     0,   780,
       0,     0,    26,     0,     0,  1894,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,    37,    38,    39,
      40,    41,    42,    43,    44,     0,     0,     0,    45,    46,
      47,    48,    49,    50,    51,     0,    52,    53,    54,    55,
      56,   572,    30,    31,   573,   574,    34,   575,    36,     0,
      37,     0,    39,    40,    41,     0,    43,    44,  1948,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      58,    59,    60,    56,     0,     0,     0,    61,     0,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,     0,     0,     0,     0,
       0,  1993,     0,     0,     0,     0,     0,     0,   317,   318,
     319,    70,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,     0,     0,     0,   782,     0,  2031,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,     0,     0,   317,   318,   319,   783,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
       0,     0,   317,   318,   319,   928,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,   317,   318,
     319,   953,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,   317,   318,   319,  1226,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
     317,   318,   319,  1428,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,     0,     0,   317,   318,   319,  1429,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
       0,     0,   317,   318,   319,  1488,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,   317,   318,
     319,  1494,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,   317,   318,   319,  1497,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
     317,   318,   319,  1500,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,     0,     0,   317,   318,   319,  1501,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
       0,     0,   317,   318,   319,  1549,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,   317,   318,
     319,  1612,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,   317,   318,   319,  1615,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
     317,   318,   319,  1617,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,     0,     0,   317,   318,   319,  1653,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
       0,     0,   317,   318,   319,  1866,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,   317,   318,
     319,  1920,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,   526,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,   558,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,   559,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,   590,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,   714,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,   715,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,   728,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,   729,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,   730,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,   731,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,   732,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,   733,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,   796,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,   797,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,   798,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,   918,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,   951,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,   952,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,   972,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1117,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1118,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1130,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1131,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1162,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1163,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1164,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1165,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1166,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1167,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1168,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1169,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1170,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1171,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1172,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1173,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1174,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1175,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1176,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1177,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1178,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1179,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1180,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1181,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1182,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1183,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1184,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1185,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1186,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1187,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1202,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1209,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1326,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1327,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1341,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1342,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1348,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1351,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1362,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1367,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1370,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1372,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1373,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1374,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1375,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1376,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1377,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1378,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1379,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1380,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1381,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1382,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1383,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1384,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1385,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1386,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1387,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1388,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1389,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1390,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1391,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1392,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1393,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1394,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1395,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1396,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1397,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1401,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1402,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1510,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1522,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1523,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1524,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1525,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1526,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1527,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1528,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1529,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1530,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1531,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1532,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1533,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1534,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1535,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1536,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1537,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1538,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1539,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1540,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1541,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1542,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1544,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1545,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1630,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1631,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1632,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1633,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1634,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1635,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1636,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1637,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1638,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1639,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1640,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1641,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1642,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1643,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1644,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1645,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1646,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1647,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1648,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1649,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1650,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1729,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1730,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1731,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1732,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1733,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1734,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1735,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1736,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1737,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1738,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1739,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1740,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1741,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1742,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1743,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1744,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1745,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1746,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1747,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1748,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1749,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1806,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1813,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1814,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1815,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1816,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1817,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1818,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1819,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1820,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1821,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1822,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1823,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1824,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1825,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1826,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1827,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1828,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1829,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1830,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1865,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1873,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1874,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1875,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1876,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1877,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1878,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1879,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1880,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1881,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1882,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1883,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1884,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1885,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1886,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1887,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1888,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1889,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1890,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1929,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1930,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1931,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1932,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1933,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1934,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1935,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1936,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1937,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1938,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1939,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1940,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1941,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1942,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1943,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1944,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1945,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1946,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1978,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1979,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1980,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1981,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1982,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1983,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1984,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1985,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1986,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1987,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1988,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1989,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1990,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1991,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1992,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2016,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2017,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2018,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2019,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2020,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2021,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2022,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2023,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2024,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2025,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2026,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2027,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2028,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2029,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2030,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2060,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2061,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2062,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2063,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2064,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2065,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2066,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2067,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2068,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2069,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2070,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2071,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2072,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2073,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2074,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2104,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2105,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2106,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2107,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2108,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2109,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2110,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2111,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2112,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2135,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2136,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2137,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2138,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2139,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2140,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2141,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2142,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2143,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2177,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2178,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2179,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2180,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2181,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2182,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2183,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2184,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2185,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2207,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2208,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2209,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2210,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2211,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2212,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2225,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2226,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2227,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2228,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2229,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2230,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2246,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2247,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2248,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2249,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2250,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2251,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2270,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2271,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2272,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2282,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2283,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2284,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2297,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2298,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2299,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2315,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2316,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2317,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2321,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2322,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2323,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2327,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2328,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2329,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,   317,   318,   319,   501,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,   317,   318,   319,   634,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,   317,   318,   319,   693,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,   317,   318,   319,   695,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,   317,   318,   319,   697,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,   317,   318,   319,   699,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,   317,   318,   319,
     701,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,   317,   318,
     319,   703,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,   317,
     318,   319,   705,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
     317,   318,   319,   707,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,   317,   318,   319,   709,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,   317,   318,   319,   711,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,   317,   318,   319,   713,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,   317,   318,   319,   717,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,   317,   318,   319,   719,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,   317,   318,   319,   721,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,   317,   318,   319,
     723,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,   317,   318,
     319,   725,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,   317,
     318,   319,   727,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
     317,   318,   319,   799,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,   317,   318,   319,   805,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,   317,   318,   319,   899,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,   317,   318,   319,  1049,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,   317,   318,   319,  1051,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,   317,   318,   319,  1053,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,   317,   318,   319,  1055,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,   317,   318,   319,
    1056,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,   317,   318,
     319,  1200,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
     528,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,   529,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,   531,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,   533,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,   534,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,   542,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,   584,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,   585,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,   588,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,   594,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
     692,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,   694,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,   696,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,   698,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,   700,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,   702,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,   704,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,   706,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,   708,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,   710,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
     712,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,   716,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,   718,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,   720,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,   722,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,   724,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,   726,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,   762,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,   764,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,   777,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
     778,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,   779,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,   784,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,   785,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,   786,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,   787,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,   788,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,   811,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,   818,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,  1048,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
    1050,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,  1052,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,  1054,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,  1121,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,  1227,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,  1253,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,  1357,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,  1361,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,  1363,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,  1483,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
    1484,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,  1513,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,  1515,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,  1517,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,  1519,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,  1520,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,  1521,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,  1543,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,  1652,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,  1810,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
    1811,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,  1812,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,  1975,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,  1976,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,  1977,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,  2098,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,  2099,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,  2100,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,  2101,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,  2102,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
    2103,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,  2213,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,  2214,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,  2215,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,  2273,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,  2274,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,  2275,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,  2333,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,  2334,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,  2335,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331
};

static const short yycheck[] =
{
      25,    71,    72,     5,    25,     5,    96,   376,   310,   346,
     752,   885,  1338,     4,  1340,   187,    47,    48,   190,     4,
       4,     4,     4,    66,     4,     6,     3,     5,    67,    66,
      43,     6,     6,    72,     0,     7,     6,     6,  1415,   211,
     105,   213,  1419,     4,   199,  1422,   201,    67,     6,    67,
      67,    66,    72,     4,    72,    72,    34,    35,    36,   200,
      67,     5,   169,  1137,   205,    72,    67,     4,     5,    67,
       6,    72,  1146,     5,    72,     6,    50,   188,   189,  1153,
     200,    50,   196,   197,   199,   205,   201,   201,   217,   203,
      34,    35,    36,   308,   205,   969,   207,    34,    35,    36,
     188,   189,    34,    35,    36,   188,   189,   200,   133,   134,
     135,   199,   205,   138,   139,     6,     7,   142,   206,   188,
     189,   188,   189,   206,   149,     6,   151,   152,   153,     7,
     155,   346,   157,   158,   199,   160,   205,   199,   207,   206,
       6,    67,   199,   174,   206,   176,    72,   108,   109,   206,
     200,   182,   177,   178,     5,   205,   199,   108,   109,   200,
     188,   189,   199,   206,   205,   200,   196,   197,   207,   911,
     205,   196,   197,   203,   199,     6,   201,    67,   206,   204,
     205,     7,    72,    34,    35,    36,   199,   207,   525,   207,
     207,   206,    67,   188,   189,    39,     7,    72,    42,   501,
     207,   538,   174,   175,   176,   177,   207,   196,   197,   207,
     205,   199,   189,   188,   189,   206,     6,   199,   188,   189,
     201,   206,   206,   206,   255,   397,   206,   252,   206,   299,
     300,   301,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   206,   206,     3,     8,  1352,   408,
    1657,   207,  1356,   308,  1661,  1611,   199,  1664,  1614,   310,
    1616,     6,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   188,   189,    66,
     525,     6,   199,   338,   199,   340,   201,   207,     6,   206,
     345,   346,    39,   538,    47,    42,    43,  1069,    45,   354,
     355,   356,   357,   358,   199,   360,   361,   362,   363,   364,
     365,   366,   373,   374,   199,   196,   197,   199,   174,   175,
     176,   177,   203,   378,   379,   380,   381,   199,   199,   201,
     385,    56,   199,   174,   175,   176,   177,   199,   393,     7,
     196,   197,  1246,   375,   376,   375,   376,   402,  1755,   188,
     189,   199,  1759,  1709,  1761,   196,   197,  1713,   206,  1715,
     188,   189,   203,   188,   189,   199,   205,   201,   207,    39,
     737,    43,    42,    43,   188,   189,   199,   205,   188,   189,
     205,   188,   189,   140,   141,   142,   143,   144,   145,   146,
     147,   205,   188,   189,   445,   205,   188,   189,   205,   188,
     189,   768,   502,  1507,  1508,  1509,  1510,    57,    58,   205,
    1514,   165,   166,   205,   168,   199,   205,   178,   179,   180,
      43,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   199,   800,   801,   802,   803,   198,    43,   494,
     188,   189,   497,     6,     7,     6,   207,  1351,   503,   199,
     501,   201,   200,   178,   179,   180,    43,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    45,   206,
     525,   526,   199,   198,   201,   188,   189,   196,   197,    43,
     535,   536,   201,   538,   203,   540,   541,   200,    42,    43,
     206,    45,   737,   548,   196,   197,   557,   742,   199,   201,
     201,   203,     4,   558,   559,   199,   174,   175,   176,   177,
     199,   199,   567,   201,   190,   191,   192,  1621,  1622,   199,
       6,  1625,   198,   768,   579,   196,   197,     6,   196,   197,
     201,   205,   203,   207,   634,   590,     6,   592,   593,   188,
     189,   190,   191,   192,     4,   199,  1318,   201,     4,   198,
     125,   126,   127,   128,   129,   800,   801,   802,   803,    60,
      61,    62,    63,   930,    65,   199,   199,   201,   201,    43,
     199,   903,   904,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   199,   634,     3,     4,   199,   198,   201,   199,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,   199,  1719,   201,   178,   179,   180,
      39,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   199,   199,   201,   201,     5,   198,   738,   199,
       4,    60,    61,    62,    63,    64,    65,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     6,   714,
     715,     6,     8,   198,     5,   199,   199,   201,   201,   199,
     199,   201,   201,   728,   729,   730,   731,   732,   733,   734,
     199,   199,   737,   201,   201,   930,   203,   742,     6,   205,
     745,   207,   205,   205,   207,   207,   199,   205,   759,   207,
     755,   205,   199,   207,  1808,   199,   205,  1106,   207,   205,
     205,   207,   207,   768,   205,   770,   207,   205,   205,   207,
     207,   205,   205,   207,   207,   205,   201,   207,     6,   205,
     199,   207,   852,   206,   206,   796,   797,   798,   205,   205,
     207,   207,   205,     4,   207,   800,   801,   802,   803,   206,
     199,   806,   807,   199,   205,   810,   207,   205,     6,   207,
     199,   205,   823,   207,   199,  1869,   821,   822,   206,   188,
     189,   832,   205,     6,   207,   194,   205,   205,   207,   207,
     199,   205,   205,   207,   207,   204,   206,   206,   205,   205,
     207,   207,   205,   205,   207,   207,   205,   205,   207,   207,
     206,   203,   857,   858,   859,   860,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,   871,   872,   873,   874,
     875,   876,   877,   878,   879,   880,   881,   882,   205,   205,
     207,   207,   178,   179,   180,   206,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   205,   899,   207,
       8,   111,   198,   904,   200,     6,   205,   912,   207,   199,
     178,   179,   180,   918,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   930,   205,   932,   207,   934,
     198,   180,     6,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     6,   950,   951,   952,     3,   198,
     178,   179,   180,   199,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   199,   199,   972,   973,   974,
     198,     5,   199,   199,   199,   199,   199,   199,   199,   199,
     178,   179,   180,  1332,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   199,   199,   199,   199,  2053,
     198,   200,   199,   199,   199,   199,   199,   199,   199,   199,
     199,  1061,   199,   199,  1015,     3,     4,   199,   199,  1128,
     199,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   199,   205,   205,     4,   198,
       7,   203,  1102,     6,   201,     7,   206,  1062,     7,     7,
     200,     7,     7,   106,  1075,   206,  1077,   108,     5,     5,
     178,   179,   180,     5,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,  1090,  1091,  1092,  1093,  1159,
     198,     5,     5,     5,     5,     5,  1107,  1102,  1109,     5,
    1111,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,  1117,  1118,     5,     5,     5,     5,   158,     5,
       5,     5,  1127,     3,  1106,  1130,  1106,     5,     5,   205,
       6,     6,     5,   200,     6,  1140,     4,   202,     7,     6,
     203,     7,  1147,  1148,  1149,     7,  1255,     7,     7,  1154,
       7,     7,   206,  1158,   207,   207,   206,  1162,  1163,  1164,
    1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,     7,     7,   199,     7,   203,   170,     5,
     205,   199,   205,   205,   205,   205,   205,  1202,   205,   205,
     188,   189,   205,   205,  1209,   205,   194,   205,   205,   205,
     205,   199,   205,   205,   202,   205,   204,     6,   206,   205,
     205,   205,   205,  1228,   205,   178,   179,   180,   205,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
    1349,     3,     4,   205,  1249,   198,  1251,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     3,     4,   200,   205,   205,   205,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     4,     6,   178,   179,   180,   199,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   205,   202,
     199,  1326,  1327,   198,  1335,     6,  1337,     6,  1339,     7,
    1335,   205,  1337,     6,  1339,   205,  1341,  1342,   199,     7,
    1345,   199,     7,   206,   199,   199,   199,   199,   199,  1354,
    1332,   199,  1332,   199,   199,   199,   199,  1362,   199,   199,
     199,   199,  1367,   199,   199,  1370,   199,  1372,  1373,  1374,
    1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,
    1395,  1396,  1397,     6,   199,   199,  1401,  1506,  1409,   199,
     199,  1406,     7,  1408,  1409,  1410,   201,     7,     7,   178,
     179,   180,     7,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     7,     7,   188,   189,     7,   198,
       7,     7,   194,     7,     4,     7,   205,   199,   207,     7,
     202,     6,   204,     6,   206,     7,     4,     7,   171,     3,
       3,     3,   190,     3,     3,     3,   188,   189,     3,  1568,
       3,     3,   194,     3,     3,     3,     3,   199,     3,     5,
     202,     5,   204,     3,   206,     3,   200,     6,     4,     6,
     200,   203,     7,     6,  1489,     6,     6,     6,   199,   199,
    1495,   206,     6,  1498,   178,   179,   180,     6,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     6,
     107,  1620,   206,   167,   198,   205,   200,  1522,  1523,  1524,
    1525,  1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,
    1535,  1536,  1537,  1538,  1539,  1540,  1541,  1542,   205,  1544,
    1545,   178,   179,   180,   200,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   205,   200,   205,   200,
     205,   198,   200,   200,   200,   178,   179,   180,   205,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       6,   205,   205,   205,   205,   198,   159,   205,   205,   205,
     205,   200,   165,   205,   205,   205,   200,   205,   205,   205,
       6,  1651,   205,     6,     6,   203,     6,     4,     6,  1718,
       6,     6,   202,     6,     6,   188,     6,     6,     6,     6,
     193,   194,  1627,  1628,  1629,  1630,  1631,  1632,  1633,  1634,
    1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,
    1645,  1646,  1647,  1648,  1649,  1650,     6,     6,     6,     6,
       3,     4,     6,   107,     6,  1764,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       6,   178,   179,   180,     6,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     6,     6,  1807,     6,
    1750,   198,  1752,     7,     3,     6,     3,   190,     6,     3,
       6,     6,  1717,     6,     3,     6,     6,     3,  1723,     6,
    1725,     3,  1727,     3,  1729,  1730,  1731,  1732,  1733,  1734,
    1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,
    1745,  1746,  1747,  1748,  1749,     3,     6,     4,     7,   202,
       6,     6,   178,   179,   180,     6,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   203,     6,   206,
       6,   206,   198,   207,   206,   206,   206,   104,   178,   179,
     180,  1831,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   200,   205,   205,   205,   205,   198,   200,
    1805,  1806,   107,   109,     6,     3,   205,     6,  1813,  1814,
    1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,  1823,  1824,
    1825,  1826,  1827,  1828,  1829,  1830,   200,   200,   205,   200,
     200,   200,     6,   205,   200,   188,   189,   205,     3,     6,
       6,   194,     6,     6,     6,     6,   199,     3,     6,     6,
       5,   204,     5,   206,   205,     6,     8,   207,   206,   206,
    1865,   207,   205,   205,   167,  1870,  1871,  1872,  1873,  1874,
    1875,  1876,  1877,  1878,  1879,  1880,  1881,  1882,  1883,  1884,
    1885,  1886,  1887,  1888,  1889,  1890,     3,     4,   205,   200,
     205,   205,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,   200,   200,  1923,     6,
    1925,     6,  1927,   496,  1929,  1930,  1931,  1932,  1933,  1934,
    1935,  1936,  1937,  1938,  1939,  1940,  1941,  1942,  1943,  1944,
    1945,  1946,   178,   179,   180,     6,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   205,     6,     6,
       6,     6,   198,     6,     6,     6,     6,   206,     6,     8,
       6,     6,     6,  1978,  1979,  1980,  1981,  1982,  1983,  1984,
    1985,  1986,  1987,  1988,  1989,  1990,  1991,  1992,     5,     5,
     205,   207,   206,   206,   205,   205,   205,   200,   205,   200,
     205,     6,   206,     6,     6,     6,   206,     6,  2013,  2014,
    2015,  2016,  2017,  2018,  2019,  2020,  2021,  2022,  2023,  2024,
    2025,  2026,  2027,  2028,  2029,  2030,   178,   179,   180,   206,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   104,     6,     6,     5,   205,   198,   206,     6,  2054,
       5,  2056,   206,  2058,   167,  2060,  2061,  2062,  2063,  2064,
    2065,  2066,  2067,  2068,  2069,  2070,  2071,  2072,  2073,  2074,
     206,   188,   189,   206,   205,   207,   206,   194,   205,   200,
     200,   206,   199,   207,     6,     6,     6,   204,     6,   206,
     104,     6,     6,     6,     6,     6,     6,     6,   207,  2104,
    2105,  2106,  2107,  2108,  2109,  2110,  2111,  2112,   206,   205,
     205,     6,     6,     6,     6,     6,   172,   205,     6,   205,
     173,   200,   206,   206,  2129,  2130,  2131,  2132,  2133,  2134,
    2135,  2136,  2137,  2138,  2139,  2140,  2141,  2142,  2143,   178,
     179,   180,   206,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   205,     6,     6,     6,     6,   198,
    2165,     6,  2167,     6,  2169,     6,  2171,     6,  2173,   206,
    2175,   200,  2177,  2178,  2179,  2180,  2181,  2182,  2183,  2184,
    2185,   205,   205,     6,   206,   206,   205,   760,   761,     6,
     763,   206,   765,   766,   206,   206,   206,   206,   206,     6,
       6,     6,  2207,  2208,  2209,  2210,  2211,  2212,     6,     6,
     206,   206,   206,     6,     6,     6,   206,   206,   206,     6,
    2225,  2226,  2227,  2228,  2229,  2230,  2231,  2232,  2233,     6,
       6,   206,   206,   206,     6,   808,   809,     6,     6,   812,
       5,  2246,  2247,  2248,  2249,  2250,  2251,  2252,     5,  2254,
     636,  2256,   884,  1065,    -1,    -1,   829,   830,    -1,    -1,
      -1,    -1,   835,   836,    -1,  2270,  2271,  2272,    -1,   842,
      -1,   844,    -1,    -1,    -1,    -1,    -1,  2282,  2283,  2284,
    2285,  2286,  2287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2297,  2298,  2299,  2300,    -1,  2302,    -1,  2304,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2315,  2316,  2317,    -1,    -1,    -1,  2321,  2322,  2323,    -1,
      -1,    -1,  2327,  2328,  2329,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2339,  2340,  2341,    -1,    -1,    -1,
      -1,    -1,    -1,  2348,    -1,  2350,    -1,  2352,    -1,   922,
      -1,   924,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   935,   936,   937,    -1,    -1,    -1,    -1,   942,
     943,   944,   945,   946,   947,   948,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    35,    36,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,   178,   179,   180,
      39,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
      -1,    60,    61,    62,    63,    64,    65,    -1,    -1,     8,
      -1,    -1,     3,     4,     5,    -1,    -1,  1060,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    36,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,     8,    -1,
    1123,   174,   175,   176,   177,    -1,    -1,    -1,  1131,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   189,    -1,    -1,    -1,
      -1,   194,    -1,   196,   197,    -1,   199,  1150,   201,    -1,
     203,   204,    -1,    -1,   178,   179,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   188,
     189,    -1,    -1,    -1,   198,   194,    -1,    -1,    -1,    -1,
     199,     3,     4,   207,    -1,   204,  1189,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     179,   180,    -1,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,   188,   189,   198,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,   204,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    -1,    50,    51,    52,    -1,    54,
      55,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    71,   204,   178,   179,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,   103,   178,
     179,   180,    -1,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   119,    -1,    -1,    -1,    -1,   198,
      -1,  1344,    -1,    -1,    -1,  1348,   205,    -1,   207,    -1,
       0,     1,    -1,     3,     4,    -1,    -1,    -1,    -1,    -1,
      -1,  1364,    -1,    -1,    -1,    -1,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,
      -1,    -1,   204,    33,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,   207,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    -1,    50,    51,    52,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,   102,   103,    -1,    71,    -1,    -1,   108,    -1,
     110,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1483,  1484,    -1,    -1,    -1,   101,   102,   103,  1491,    -1,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,  1502,
    1503,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   166,    -1,   168,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    -1,
      50,    51,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1547,  1548,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    -1,    50,    51,    52,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,   103,    -1,    -1,    71,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1613,    -1,    -1,    -1,    -1,  1618,   101,   102,   103,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      -1,    50,    51,    52,   119,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,   101,   102,   103,    -1,    -1,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    42,    -1,    -1,    -1,    -1,    -1,  1710,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1720,    -1,    -1,
      -1,    -1,   207,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     178,   179,   180,    -1,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,   207,
      -1,   122,   123,   124,    -1,    -1,    -1,   207,   207,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1809,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    -1,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,     4,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,   207,
      -1,    -1,    33,    -1,    -1,  1868,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    -1,    50,    51,    52,    -1,    54,    55,  1921,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,   102,   103,    71,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,  1974,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,   119,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,  2012,
     178,   179,   180,    -1,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,   207,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,   178,   179,   180,   207,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,   207,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,   178,   179,   180,   207,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,   207,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,   207,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,   178,   179,   180,   207,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,   207,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,   178,   179,   180,   207,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,   207,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,   207,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,   178,   179,   180,   207,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,   207,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,   178,   179,   180,   207,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,   207,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,   207,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,   178,   179,   180,   207,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,   207,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   178,   179,   180,   205,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   178,   179,   180,   205,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     178,   179,   180,   205,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,   178,   179,   180,   202,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,
      -1,   198,   178,   179,   180,   202,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,   178,   179,   180,   202,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,   198,   178,   179,   180,   202,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,   178,   179,   180,   202,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,   198,   178,   179,   180,   202,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,   178,   179,   180,
     202,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,   178,   179,
     180,   202,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,   178,
     179,   180,   202,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
     178,   179,   180,   202,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,   178,   179,   180,   202,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,
      -1,   198,   178,   179,   180,   202,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,   178,   179,   180,   202,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,   198,   178,   179,   180,   202,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,   178,   179,   180,   202,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,   198,   178,   179,   180,   202,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,   178,   179,   180,
     202,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,   178,   179,
     180,   202,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,   178,
     179,   180,   202,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
     178,   179,   180,   202,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,   178,   179,   180,   202,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,
      -1,   198,   178,   179,   180,   202,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,   178,   179,   180,   202,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,   198,   178,   179,   180,   202,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,   178,   179,   180,   202,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,   198,   178,   179,   180,   202,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,   178,   179,   180,
     202,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,   178,   179,
     180,   202,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   178,   179,   180,    -1,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   178,   179,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,
      -1,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     178,   179,   180,    -1,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   178,   179,   180,    -1,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,
     179,   180,    -1,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   178,   179,   180,    -1,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   178,   179,   180,    -1,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   178,   179,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,
      -1,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     178,   179,   180,    -1,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   178,   179,   180,    -1,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,
     179,   180,    -1,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   178,   179,   180,    -1,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   178,   179,   180,    -1,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   178,   179,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,
      -1,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     178,   179,   180,    -1,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   178,   179,   180,    -1,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,
     179,   180,    -1,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   178,   179,   180,    -1,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   178,   179,   180,    -1,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   178,   179,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,
      -1,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     178,   179,   180,    -1,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   178,   179,   180,    -1,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,
     179,   180,    -1,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   178,   179,   180,    -1,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   178,   179,   180,    -1,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   178,   179,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,
      -1,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     178,   179,   180,    -1,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   178,   179,   180,    -1,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,
     179,   180,    -1,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   178,   179,   180,    -1,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   178,   179,   180,    -1,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   178,   179,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,
      -1,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     178,   179,   180,    -1,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   178,   179,   180,    -1,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,
     179,   180,    -1,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   178,   179,   180,    -1,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   178,   179,   180,    -1,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   178,   179,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,
      -1,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     178,   179,   180,    -1,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   178,   179,   180,    -1,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,
     179,   180,    -1,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   178,   179,   180,    -1,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   178,   179,   180,    -1,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   178,   179,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,
      -1,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     178,   179,   180,    -1,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   178,   179,   180,    -1,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,
     179,   180,    -1,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   178,   179,   180,    -1,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   178,   179,   180,    -1,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   178,   179,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,     1,   209,   211,   213,   218,     6,     0,   165,   166,
     168,   212,     3,   140,   141,   142,   143,   144,   145,   146,
     147,   214,   215,   216,   217,     4,    33,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    48,    49,    50,
      51,    52,    53,    54,    55,    59,    60,    61,    62,    63,
      64,    65,    67,    68,    69,    70,    71,   100,   101,   102,
     103,   108,   110,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   219,   220,   221,   304,   305,   306,   309,
     310,   311,   312,   313,   314,   315,   327,   328,   169,     7,
       6,     6,     6,     6,     6,   199,   199,   199,     3,     4,
       5,     7,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    34,    35,    36,   174,
     175,   176,   177,   188,   189,   194,   196,   197,   199,   201,
     203,   204,   302,   303,   330,   331,   344,   199,     6,   206,
       6,   199,   199,   199,    66,   199,    66,   199,   199,    47,
     199,    43,    43,    43,    43,    42,    43,    45,    45,    39,
      42,    43,    45,   199,   206,   188,   189,   199,   206,   332,
     333,   332,   206,    39,    42,    43,     4,   206,    43,     4,
     206,     6,     6,    39,    42,     4,   199,   199,    43,   199,
       4,   206,   341,     4,   199,   199,     6,     4,     4,    43,
       5,   206,   344,   206,   344,     3,   189,   210,    42,   122,
     123,   124,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   159,   160,   161,   162,   163,   164,   199,   334,
     334,     5,   201,   203,   303,     4,   206,   199,   201,   199,
     201,   199,   201,   199,   201,   199,   201,   199,   201,   199,
     201,   199,   201,   199,   201,   199,   201,   199,   201,   199,
     201,   199,   201,   199,   201,   199,   201,   199,   201,   199,
     201,   199,   201,   199,   201,   199,   201,   199,   201,   199,
     199,   199,     4,   330,   330,   330,   330,   202,   206,   330,
       4,   108,   109,     4,   330,     6,     6,   178,   179,   180,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   198,     6,     5,   330,   330,   330,   330,   199,   330,
     199,   330,   330,     4,    39,   189,   206,   306,   309,   315,
     330,   338,   339,   330,   206,   199,   199,   199,   206,   338,
     206,   206,   199,   199,   199,   199,   199,     4,   332,   332,
     332,   330,   330,   188,   189,   206,   206,   332,   206,   206,
     206,   201,   308,   338,     6,   201,   308,   338,   338,     6,
     330,   330,   105,   199,   330,   203,   330,   206,   111,   330,
     330,     6,   199,   308,     6,   308,     6,     3,   210,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,     5,
     335,   205,   200,   205,   330,     4,   332,   222,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
       4,   344,   344,   344,   201,   200,     7,   189,   330,   339,
     340,   202,     7,   302,   303,   203,     7,   201,     6,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   200,   205,   205,   200,   200,   200,
     330,   200,   330,   200,   200,   201,   206,     4,   206,   340,
       8,     7,   200,   330,   330,   330,   330,   330,     7,   330,
     330,   330,   330,   330,   330,   330,   200,   205,   205,   205,
     332,   332,   306,   307,   308,   309,   307,   205,   330,   330,
     330,   330,    39,    42,    43,    45,   207,   305,     6,     7,
     330,   207,     7,     7,   200,   200,   106,   330,   200,   108,
     205,   308,   206,     8,   200,   330,   207,   207,   210,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,   158,     5,     5,     5,     5,     3,     5,   200,
     205,     5,     6,     5,   202,   303,   206,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   207,   224,   227,   230,   233,   236,
     239,   242,   245,   248,   251,   254,   257,   260,   263,   266,
     269,   272,   275,   278,   281,   284,   287,   290,   293,   296,
     299,   301,   200,   202,   200,   202,   200,   202,   200,   202,
     200,   202,   200,   202,   200,   202,   200,   202,   200,   202,
     200,   202,   200,   202,   205,   205,   200,   202,   200,   202,
     200,   202,   200,   202,   200,   202,   200,   202,   205,   205,
     205,   205,   205,   205,   201,   203,   200,   205,   205,   200,
     330,   338,   205,   207,   203,   302,   303,   344,   330,     6,
       4,     4,   206,   342,   202,     8,     6,   340,   330,     7,
       7,     7,   200,     7,   200,     7,     7,   202,   206,   330,
     201,   340,   207,   330,   330,     7,   207,   200,   200,   200,
     207,   330,   207,   207,   200,   200,   200,   200,   200,   203,
     332,   330,   330,   207,   207,   330,   205,   205,   205,   202,
     206,   206,   206,   206,   330,   202,   206,   206,     7,     7,
     199,   200,     7,   203,   330,   207,   330,   330,   200,   170,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
       5,   200,   205,   203,   303,   344,   222,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   206,   336,     6,   330,   330,   330,
     330,   330,   330,   330,   330,   330,     4,   340,   344,   202,
       6,   330,   339,   202,     4,   108,   109,   330,     6,     6,
       6,     7,   201,   341,   343,     6,   330,   200,   205,   332,
     338,   338,     7,   338,     7,   338,   338,   340,   207,   202,
     206,   207,     8,     6,   206,     7,     7,     7,     7,     7,
       6,    56,     7,     7,     7,     7,     7,     7,     7,     4,
     205,   205,   205,   207,   332,   332,   332,     6,   340,   340,
     340,   340,     6,     6,   330,   330,   338,   338,   330,     7,
     338,     4,   205,     8,     8,   200,     7,   171,     3,   330,
     330,   332,     3,     3,   190,     3,     3,   338,   338,     3,
     332,     3,     3,   338,   338,     3,     3,     3,     3,     3,
     338,   125,   126,   127,   128,   129,   329,   338,     3,     5,
       5,     3,     3,     6,   334,     4,     6,   207,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   337,   338,   337,   336,   200,   202,
     200,   202,   200,   202,   200,   202,   202,   200,   200,   200,
     302,     7,   302,   303,   203,     7,     6,   341,   330,   205,
     207,     6,   330,     6,     6,    50,     6,    50,   338,     6,
     338,     6,     6,   207,   340,   330,   330,   338,   338,   338,
     199,   199,    57,    58,   338,   338,   338,   338,   338,   338,
     338,     6,     7,   330,   330,   330,   206,   205,   207,   205,
     207,   205,   207,   207,   207,   207,   207,   205,   205,     6,
       6,   200,   336,   107,   330,   330,   330,   206,   167,   205,
     205,   205,   200,   205,   200,   205,   200,   205,   200,   205,
     205,   200,   205,   200,   200,   205,   205,   205,   205,   205,
     205,   200,   205,   205,   205,   205,   205,   200,   205,   205,
     303,     6,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   200,   205,
     207,     6,   203,   338,   344,   330,     6,     4,   342,     6,
     202,   341,   205,   332,   332,     6,     6,   202,   207,   205,
       6,     6,     6,   330,   330,   330,   330,     6,     6,     6,
       6,     6,     6,     6,   330,   344,   207,   200,   205,   207,
     307,   332,     6,   316,   332,     6,   319,   332,     6,   322,
       6,     6,     6,     6,   330,   330,     7,   107,   338,   205,
     207,     8,   207,   200,   330,   210,     3,   330,   338,     6,
       3,     6,   190,     6,   329,     6,     3,   330,     6,     3,
       6,     6,     3,   329,   330,   330,   330,   338,     6,     3,
     329,   330,     3,     3,     6,   330,   334,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   338,     4,     6,     6,     6,     7,     6,
     203,   330,     6,     6,   202,   330,   205,   205,     6,     6,
       6,     6,   206,   330,   207,   205,   206,   205,   206,   205,
     206,   205,   205,   336,   206,   104,   330,   330,   205,   210,
     200,   205,   205,   205,   205,   200,   205,   200,   205,   200,
     200,   200,   205,   200,   205,   200,   200,   205,   205,   200,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   200,   341,
     109,   205,   205,   330,   330,   307,   205,   207,   188,   189,
     199,   330,   332,    67,    72,   325,   326,   330,   332,   325,
     330,   332,   325,   330,   330,   107,   338,   330,   207,   207,
     338,   210,     6,   336,   329,     3,   330,     6,   329,     6,
       3,     6,     6,     6,   330,     6,   338,     6,     6,   330,
       3,     6,   330,     5,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
       6,   330,     5,   200,   200,   207,   330,   330,   207,   205,
       6,   206,   207,   326,   207,   205,   207,   207,   205,   207,
     207,   207,   206,   205,     6,   207,   167,   205,   205,   205,
     205,   200,   200,   200,   205,   200,   200,   200,   205,   200,
     200,   200,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   200,   205,   205,   205,   338,   338,   207,
       6,   317,   330,   338,     6,     6,   320,   330,     6,     6,
     323,   330,     6,     6,     6,   338,   338,     6,   210,   329,
     329,   329,   329,     6,     6,     6,   329,     6,     6,     6,
       5,   225,   228,   231,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   297,   330,   330,     5,   338,
     338,   206,   207,   205,   206,   207,   206,   207,   205,   207,
     210,   205,   205,   200,   200,   205,   205,   206,   206,   206,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   206,   200,   207,   205,     6,     6,   325,     6,   318,
     338,   325,     6,   321,   325,     6,   324,   338,   104,   210,
     329,   329,     6,     6,   329,     5,   223,   330,   226,   330,
     229,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   295,   344,   300,     6,     5,   207,   206,
     205,   207,   207,   206,   207,   206,   207,   206,   167,   205,
     205,   200,   200,   205,   207,   205,   207,   205,   207,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   207,   206,   207,     6,   325,   338,     6,     6,   325,
       6,   325,   104,   330,   210,   329,   338,     6,     6,   330,
       6,   330,     6,   330,     6,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   344,     6,   298,   344,
       6,   207,   207,   207,   207,   206,   205,   210,   205,   205,
     200,   200,   200,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   207,     6,     6,     6,     6,   330,   330,   210,
     329,   338,   234,   237,   240,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   344,     6,   205,   207,   172,   205,   205,
     206,   206,   206,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   330,     6,   173,   338,   329,   232,   330,   235,   330,
     238,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     207,   205,   200,   205,   207,   205,   207,   205,   207,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,     6,   338,     6,
     330,     6,   330,     6,   330,     6,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   205,   200,   200,   200,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   338,   243,   246,   249,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   205,   206,   206,   206,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   338,   241,   330,   244,   330,   247,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   205,   205,   207,   205,   207,   205,   207,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   329,   330,     6,   330,     6,
     330,     6,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   200,   200,   200,
     200,   200,   200,   200,   205,   205,   205,   205,   205,   205,
     205,   205,   205,     6,   252,   255,   258,   261,   264,   267,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   206,
     206,   206,   206,   206,   206,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   250,   330,   253,   330,   256,   330,
     259,   330,   262,   330,   265,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   205,   207,   205,   207,   205,
     207,   205,   207,   205,   207,   205,   207,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   330,     6,   330,     6,
     330,     6,   330,     6,   330,     6,   330,     6,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   205,   205,   205,
     205,   205,   205,   200,   200,   200,   330,   330,   330,   330,
     330,   330,   288,   291,   294,   205,   205,   205,   205,   205,
     205,   206,   206,   206,   330,   330,   330,   330,   330,   330,
     286,   330,   289,   330,   292,   330,   205,   205,   205,   205,
     205,   205,   205,   207,   205,   207,   205,   207,   330,   330,
     330,   330,   330,   330,   330,     6,   330,     6,   330,     6,
     205,   205,   205,   200,   200,   200,   330,   330,   330,   279,
     282,   285,   205,   205,   205,   206,   206,   206,   330,   330,
     330,   277,   330,   280,   330,   283,   330,   205,   205,   205,
     205,   207,   205,   207,   205,   207,   330,   330,   330,   330,
       6,   330,     6,   330,     6,   205,   205,   205,   330,   330,
     330,   205,   205,   205,   330,   330,   330,   205,   205,   205,
     330,   330,   330,   200,   200,   200,   270,   273,   276,   206,
     206,   206,   268,   330,   271,   330,   274,   330,   205,   207,
     205,   207,   205,   207,   330,     6,   330,     6,   330,     6
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
        case 5:
#line 169 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 175 "Gmsh.y"
    { yyval.d = yyvsp[0].d; ;}
    break;

  case 7:
#line 176 "Gmsh.y"
    { yyval.d = -yyvsp[0].d; ;}
    break;

  case 10:
#line 186 "Gmsh.y"
    {
      yymsg(INFO, "Reading STL solid");
      STL_Surf = Create_Surface(NEWSURFACE(), MSH_SURF_STL);
      STL_Surf->STL = new STL_Data;
      return 1;
    ;}
    break;

  case 11:
#line 200 "Gmsh.y"
    {
      STL_Surf->STL->Add_Facet(yyvsp[-12].d, yyvsp[-11].d, yyvsp[-10].d,
			       yyvsp[-8].d, yyvsp[-7].d, yyvsp[-6].d,
			       yyvsp[-4].d, yyvsp[-3].d, yyvsp[-2].d, CTX.geom.stl_create_elementary);
      return 1;
    ;}
    break;

  case 12:
#line 207 "Gmsh.y"
    {
      if(CTX.geom.stl_create_elementary){
	STL_Surf->STL->ReplaceDuplicate();
	if(CTX.geom.stl_create_physical)
	  STL_Surf->STL->CreatePhysicalSurface();
      }
      else{
	Tree_Add(THEM->Surfaces, &STL_Surf);
      }
      yymsg(INFO, "Read STL solid");
      return 1;
    ;}
    break;

  case 15:
#line 229 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 230 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 231 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 236 "Gmsh.y"
    {
      yymsg(INFO, "Reading Step Iso-10303-21 data");
      Create_Step_Solid_BRep();
    ;}
    break;

  case 19:
#line 241 "Gmsh.y"
    {
      Resolve_BREP ();
      yymsg(INFO, "Read Step Iso-10303-21 data");
    ;}
    break;

  case 23:
#line 252 "Gmsh.y"
    {
    ;}
    break;

  case 24:
#line 255 "Gmsh.y"
    {
    ;}
    break;

  case 25:
#line 259 "Gmsh.y"
    {
   ;}
    break;

  case 26:
#line 265 "Gmsh.y"
    {
        Add_Cartesian_Point((int)yyvsp[-8].d, yyvsp[-4].c, yyvsp[-2].v[0], yyvsp[-2].v[1], yyvsp[-2].v[2]);
    ;}
    break;

  case 27:
#line 271 "Gmsh.y"
    {
       Add_BSpline_Curve_With_Knots ((int)yyvsp[-22].d, yyvsp[-18].c, (int) yyvsp[-16].d, yyvsp[-14].l,	yyvsp[-6].l, yyvsp[-4].l, 0., 1.);
    ;}
    break;

  case 28:
#line 278 "Gmsh.y"
    {
      Add_BSpline_Surface_With_Knots ((int)yyvsp[-30].d, yyvsp[-26].c, (int) yyvsp[-24].d, (int) yyvsp[-22].d, yyvsp[-20].l, yyvsp[-10].l,
				      yyvsp[-8].l, yyvsp[-6].l, yyvsp[-4].l, 0., 1., 0., 1. );
    ;}
    break;

  case 29:
#line 284 "Gmsh.y"
    {
      Add_Edge_Curve ((int)yyvsp[-14].d, yyvsp[-10].c , (int)yyvsp[-8].d , (int)yyvsp[-6].d, (int)yyvsp[-4].d);
    ;}
    break;

  case 30:
#line 288 "Gmsh.y"
    {
      Add_Face_Outer_Bound((int)yyvsp[-10].d, yyvsp[-6].c, (int)yyvsp[-4].d, yyvsp[-2].i, 1);
    ;}
    break;

  case 31:
#line 292 "Gmsh.y"
    {
      // check the norm! Face_Bound : hole outside surface!
      yymsg(INFO, "Found a face bound");
      Add_Face_Outer_Bound((int)yyvsp[-10].d, yyvsp[-6].c, (int)yyvsp[-4].d, yyvsp[-2].i, 0);
    ;}
    break;

  case 32:
#line 299 "Gmsh.y"
    {
      Add_Oriented_Edge((int)yyvsp[-14].d, yyvsp[-10].c, (int)yyvsp[-4].d, yyvsp[-2].i);
    ;}
    break;

  case 33:
#line 303 "Gmsh.y"
    {
      Add_Edge_Loop((int)yyvsp[-8].d, yyvsp[-4].c, yyvsp[-2].l);
    ;}
    break;

  case 34:
#line 308 "Gmsh.y"
    {
      Add_Advanced_Face((int)yyvsp[-12].d, yyvsp[-8].c, yyvsp[-6].l, (int)yyvsp[-4].d, yyvsp[-2].i);
    ;}
    break;

  case 35:
#line 312 "Gmsh.y"
    {
      Add_Vertex_Point((int)yyvsp[-8].d, yyvsp[-4].c, (int)yyvsp[-2].d);
    ;}
    break;

  case 36:
#line 316 "Gmsh.y"
    {
    ;}
    break;

  case 37:
#line 320 "Gmsh.y"
    {
      Add_Axis2_Placement3D  ((int)yyvsp[-12].d, (int)yyvsp[-4].d, (int)yyvsp[-2].d, (int)yyvsp[-6].d);
    ;}
    break;

  case 38:
#line 324 "Gmsh.y"
    {
      Add_Direction((int)yyvsp[-8].d , yyvsp[-4].c, yyvsp[-2].v[0], yyvsp[-2].v[1], yyvsp[-2].v[2]);
    ;}
    break;

  case 39:
#line 328 "Gmsh.y"
    {
      Add_Plane((int)yyvsp[-8].d, yyvsp[-4].c, (int)yyvsp[-2].d);
    ;}
    break;

  case 40:
#line 332 "Gmsh.y"
    {
      Add_Line ((int)yyvsp[-10].d, yyvsp[-6].c , (int) yyvsp[-4].d, (int)yyvsp[-2].d);
    ;}
    break;

  case 41:
#line 336 "Gmsh.y"
    {
      yymsg(INFO, "Found a closed shell");
      Add_Closed_Shell((int)yyvsp[-8].d, yyvsp[-4].c , yyvsp[-2].l);
    ;}
    break;

  case 42:
#line 342 "Gmsh.y"
    {
    ;}
    break;

  case 43:
#line 345 "Gmsh.y"
    {
    ;}
    break;

  case 44:
#line 348 "Gmsh.y"
    {
      Add_Cylinder ((int)yyvsp[-10].d, yyvsp[-6].c , (int)yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 45:
#line 352 "Gmsh.y"
    {
      Add_Cone ((int)yyvsp[-12].d, yyvsp[-8].c , (int)yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 46:
#line 356 "Gmsh.y"
    {
      Add_Torus ((int)yyvsp[-12].d, yyvsp[-8].c , (int)yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 47:
#line 360 "Gmsh.y"
    {
      Add_Circle((int) yyvsp[-10].d, yyvsp[-6].c, (int) yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 48:
#line 364 "Gmsh.y"
    {
      Add_Ellipse((int) yyvsp[-12].d, yyvsp[-8].c, (int) yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 49:
#line 369 "Gmsh.y"
    {
    ;}
    break;

  case 50:
#line 372 "Gmsh.y"
    {
    ;}
    break;

  case 51:
#line 376 "Gmsh.y"
    {
    ;}
    break;

  case 52:
#line 379 "Gmsh.y"
    {
    ;}
    break;

  case 53:
#line 383 "Gmsh.y"
    {
    ;}
    break;

  case 54:
#line 386 "Gmsh.y"
    {
    ;}
    break;

  case 55:
#line 389 "Gmsh.y"
    {
    ;}
    break;

  case 58:
#line 401 "Gmsh.y"
    { return 1; ;}
    break;

  case 59:
#line 402 "Gmsh.y"
    { return 1; ;}
    break;

  case 60:
#line 403 "Gmsh.y"
    { return 1; ;}
    break;

  case 61:
#line 404 "Gmsh.y"
    { return 1; ;}
    break;

  case 62:
#line 405 "Gmsh.y"
    { List_Delete(yyvsp[0].l); return 1; ;}
    break;

  case 63:
#line 406 "Gmsh.y"
    { List_Delete(yyvsp[0].l); return 1; ;}
    break;

  case 64:
#line 407 "Gmsh.y"
    { return 1; ;}
    break;

  case 65:
#line 408 "Gmsh.y"
    { return 1; ;}
    break;

  case 66:
#line 409 "Gmsh.y"
    { return 1; ;}
    break;

  case 67:
#line 410 "Gmsh.y"
    { List_Delete(yyvsp[0].l); return 1; ;}
    break;

  case 68:
#line 411 "Gmsh.y"
    { return 1; ;}
    break;

  case 69:
#line 412 "Gmsh.y"
    { return 1; ;}
    break;

  case 70:
#line 413 "Gmsh.y"
    { return 1; ;}
    break;

  case 71:
#line 414 "Gmsh.y"
    { return 1; ;}
    break;

  case 72:
#line 419 "Gmsh.y"
    {
      Msg(DIRECT, yyvsp[-2].c);
    ;}
    break;

  case 73:
#line 423 "Gmsh.y"
    {
      char tmpstring[1024];
      int i = PrintListOfDouble(yyvsp[-4].c, yyvsp[-2].l, tmpstring);
      if(i < 0) 
	yymsg(GERROR, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(GERROR, "%d extra argument%s in Printf", i, (i>1)?"s":"");
      else
	Msg(DIRECT, tmpstring);
      List_Delete(yyvsp[-2].l);
    ;}
    break;

  case 74:
#line 440 "Gmsh.y"
    { 
      if(!strcmp(yyvsp[-5].c, "View")) EndView(View, 1, yyname, yyvsp[-4].c); 
    ;}
    break;

  case 75:
#line 444 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-7].c, "View")) EndView(View, 1, yyname, yyvsp[-6].c);
    ;}
    break;

  case 76:
#line 451 "Gmsh.y"
    {
      View = BeginView(1); 
    ;}
    break;

  case 104:
#line 485 "Gmsh.y"
    { List_Add(View->SP, &yyvsp[0].d); ;}
    break;

  case 105:
#line 487 "Gmsh.y"
    { List_Add(View->SP, &yyvsp[0].d); ;}
    break;

  case 106:
#line 492 "Gmsh.y"
    { 
      List_Add(View->SP, &yyvsp[-5].d); List_Add(View->SP, &yyvsp[-3].d);
      List_Add(View->SP, &yyvsp[-1].d);      
    ;}
    break;

  case 107:
#line 497 "Gmsh.y"
    {
      View->NbSP++;
    ;}
    break;

  case 108:
#line 504 "Gmsh.y"
    { List_Add(View->VP, &yyvsp[0].d); ;}
    break;

  case 109:
#line 506 "Gmsh.y"
    { List_Add(View->VP, &yyvsp[0].d); ;}
    break;

  case 110:
#line 511 "Gmsh.y"
    { 
      List_Add(View->VP, &yyvsp[-5].d); List_Add(View->VP, &yyvsp[-3].d);
      List_Add(View->VP, &yyvsp[-1].d); 
      ntmp = List_Nbr(View->VP);
    ;}
    break;

  case 111:
#line 517 "Gmsh.y"
    {
      if((List_Nbr(View->VP) - ntmp) % 3)
	yymsg(GERROR, "Wrong number of values for vector point "
	      "(%d is not a multiple of 3)", List_Nbr(View->VP) - ntmp);
      View->NbVP++;
    ;}
    break;

  case 112:
#line 527 "Gmsh.y"
    { List_Add(View->TP, &yyvsp[0].d); ;}
    break;

  case 113:
#line 529 "Gmsh.y"
    { List_Add(View->TP, &yyvsp[0].d); ;}
    break;

  case 114:
#line 534 "Gmsh.y"
    { 
      List_Add(View->TP, &yyvsp[-5].d); List_Add(View->TP, &yyvsp[-3].d);
      List_Add(View->TP, &yyvsp[-1].d);
      ntmp = List_Nbr(View->TP);
    ;}
    break;

  case 115:
#line 540 "Gmsh.y"
    {
      if((List_Nbr(View->TP) - ntmp) % 9)
	yymsg(GERROR, "Wrong number of values for tensor point "
	      "(%d is not a multiple of 9)", List_Nbr(View->TP) - ntmp);
      View->NbTP++;
    ;}
    break;

  case 116:
#line 550 "Gmsh.y"
    { List_Add(View->SL, &yyvsp[0].d); ;}
    break;

  case 117:
#line 552 "Gmsh.y"
    { List_Add(View->SL, &yyvsp[0].d); ;}
    break;

  case 118:
#line 558 "Gmsh.y"
    { 
      List_Add(View->SL, &yyvsp[-11].d); List_Add(View->SL, &yyvsp[-5].d);
      List_Add(View->SL, &yyvsp[-9].d); List_Add(View->SL, &yyvsp[-3].d);
      List_Add(View->SL, &yyvsp[-7].d); List_Add(View->SL, &yyvsp[-1].d);
      ntmp = List_Nbr(View->SL);
    ;}
    break;

  case 119:
#line 565 "Gmsh.y"
    {
      if((List_Nbr(View->SL) - ntmp) % 2)
	yymsg(GERROR, "Wrong number of values for scalar line "
	      "(%d is not a multiple of 2)", List_Nbr(View->SL) - ntmp);
      View->NbSL++;
    ;}
    break;

  case 120:
#line 575 "Gmsh.y"
    { List_Add(View->VL, &yyvsp[0].d); ;}
    break;

  case 121:
#line 577 "Gmsh.y"
    { List_Add(View->VL, &yyvsp[0].d); ;}
    break;

  case 122:
#line 583 "Gmsh.y"
    { 
      List_Add(View->VL, &yyvsp[-11].d); List_Add(View->VL, &yyvsp[-5].d);
      List_Add(View->VL, &yyvsp[-9].d); List_Add(View->VL, &yyvsp[-3].d);
      List_Add(View->VL, &yyvsp[-7].d); List_Add(View->VL, &yyvsp[-1].d);
      ntmp = List_Nbr(View->VL);
    ;}
    break;

  case 123:
#line 590 "Gmsh.y"
    {
      if((List_Nbr(View->VL) - ntmp) % 6)
	yymsg(GERROR, "Wrong number of values for vector line "
	      "(%d is not a multiple of 6)", List_Nbr(View->VL) - ntmp);
      View->NbVL++;
    ;}
    break;

  case 124:
#line 600 "Gmsh.y"
    { List_Add(View->TL, &yyvsp[0].d); ;}
    break;

  case 125:
#line 602 "Gmsh.y"
    { List_Add(View->TL, &yyvsp[0].d); ;}
    break;

  case 126:
#line 608 "Gmsh.y"
    { 
      List_Add(View->TL, &yyvsp[-11].d); List_Add(View->TL, &yyvsp[-5].d);
      List_Add(View->TL, &yyvsp[-9].d); List_Add(View->TL, &yyvsp[-3].d);
      List_Add(View->TL, &yyvsp[-7].d); List_Add(View->TL, &yyvsp[-1].d);
      ntmp = List_Nbr(View->TL);
    ;}
    break;

  case 127:
#line 615 "Gmsh.y"
    {
      if((List_Nbr(View->TL) - ntmp) % 18)
	yymsg(GERROR, "Wrong number of values for tensor line "
	      "(%d is not a multiple of 18)", List_Nbr(View->TL) - ntmp);
      View->NbTL++;
    ;}
    break;

  case 128:
#line 625 "Gmsh.y"
    { List_Add(View->ST, &yyvsp[0].d); ;}
    break;

  case 129:
#line 627 "Gmsh.y"
    { List_Add(View->ST, &yyvsp[0].d); ;}
    break;

  case 130:
#line 634 "Gmsh.y"
    { 
      List_Add(View->ST, &yyvsp[-17].d); List_Add(View->ST, &yyvsp[-11].d);
      List_Add(View->ST, &yyvsp[-5].d);
      List_Add(View->ST, &yyvsp[-15].d); List_Add(View->ST, &yyvsp[-9].d);
      List_Add(View->ST, &yyvsp[-3].d);
      List_Add(View->ST, &yyvsp[-13].d); List_Add(View->ST, &yyvsp[-7].d);
      List_Add(View->ST, &yyvsp[-1].d);
      ntmp = List_Nbr(View->ST);
    ;}
    break;

  case 131:
#line 644 "Gmsh.y"
    {
//     if((List_Nbr(View->ST) - ntmp) % 3)
//	yymsg(GERROR, "Wrong number of values for scalar triangle "
//	      "(%d is not a multiple of 3)", List_Nbr(View->ST) - ntmp);
      View->NbST++;
    ;}
    break;

  case 132:
#line 654 "Gmsh.y"
    { List_Add(View->VT, &yyvsp[0].d); ;}
    break;

  case 133:
#line 656 "Gmsh.y"
    { List_Add(View->VT, &yyvsp[0].d); ;}
    break;

  case 134:
#line 663 "Gmsh.y"
    { 
      List_Add(View->VT, &yyvsp[-17].d); List_Add(View->VT, &yyvsp[-11].d);
      List_Add(View->VT, &yyvsp[-5].d);
      List_Add(View->VT, &yyvsp[-15].d); List_Add(View->VT, &yyvsp[-9].d);
      List_Add(View->VT, &yyvsp[-3].d);
      List_Add(View->VT, &yyvsp[-13].d); List_Add(View->VT, &yyvsp[-7].d);
      List_Add(View->VT, &yyvsp[-1].d);
      ntmp = List_Nbr(View->VT);
    ;}
    break;

  case 135:
#line 673 "Gmsh.y"
    {
      if((List_Nbr(View->VT) - ntmp) % 9)
	yymsg(GERROR, "Wrong number of values for vector triangle "
	      "(%d is not a multiple of 9)", List_Nbr(View->VT) - ntmp);
      View->NbVT++;
    ;}
    break;

  case 136:
#line 683 "Gmsh.y"
    { List_Add(View->TT, &yyvsp[0].d); ;}
    break;

  case 137:
#line 685 "Gmsh.y"
    { List_Add(View->TT, &yyvsp[0].d); ;}
    break;

  case 138:
#line 692 "Gmsh.y"
    { 
      List_Add(View->TT, &yyvsp[-17].d); List_Add(View->TT, &yyvsp[-11].d);
      List_Add(View->TT, &yyvsp[-5].d);
      List_Add(View->TT, &yyvsp[-15].d); List_Add(View->TT, &yyvsp[-9].d);
      List_Add(View->TT, &yyvsp[-3].d);
      List_Add(View->TT, &yyvsp[-13].d); List_Add(View->TT, &yyvsp[-7].d);
      List_Add(View->TT, &yyvsp[-1].d);
      ntmp = List_Nbr(View->TT);
    ;}
    break;

  case 139:
#line 702 "Gmsh.y"
    {
      if((List_Nbr(View->TT) - ntmp) % 27)
	yymsg(GERROR, "Wrong number of values for tensor triangle "
	      "(%d is not a multiple of 27)", List_Nbr(View->TT) - ntmp);
      View->NbTT++;
    ;}
    break;

  case 140:
#line 712 "Gmsh.y"
    { List_Add(View->SQ, &yyvsp[0].d); ;}
    break;

  case 141:
#line 714 "Gmsh.y"
    { List_Add(View->SQ, &yyvsp[0].d); ;}
    break;

  case 142:
#line 722 "Gmsh.y"
    { 
      List_Add(View->SQ, &yyvsp[-23].d);  List_Add(View->SQ, &yyvsp[-17].d);
      List_Add(View->SQ, &yyvsp[-11].d); List_Add(View->SQ, &yyvsp[-5].d);
      List_Add(View->SQ, &yyvsp[-21].d);  List_Add(View->SQ, &yyvsp[-15].d);
      List_Add(View->SQ, &yyvsp[-9].d); List_Add(View->SQ, &yyvsp[-3].d);
      List_Add(View->SQ, &yyvsp[-19].d);  List_Add(View->SQ, &yyvsp[-13].d);
      List_Add(View->SQ, &yyvsp[-7].d); List_Add(View->SQ, &yyvsp[-1].d);
      ntmp = List_Nbr(View->SQ);
    ;}
    break;

  case 143:
#line 732 "Gmsh.y"
    {
      if((List_Nbr(View->SQ) - ntmp) % 4)
	yymsg(GERROR, "Wrong number of values for scalar quadrangle "
	      "(%d is not a multiple of 4)", List_Nbr(View->SQ) - ntmp);
      View->NbSQ++;
    ;}
    break;

  case 144:
#line 742 "Gmsh.y"
    { List_Add(View->VQ, &yyvsp[0].d); ;}
    break;

  case 145:
#line 744 "Gmsh.y"
    { List_Add(View->VQ, &yyvsp[0].d); ;}
    break;

  case 146:
#line 752 "Gmsh.y"
    { 
      List_Add(View->VQ, &yyvsp[-23].d);  List_Add(View->VQ, &yyvsp[-17].d);
      List_Add(View->VQ, &yyvsp[-11].d); List_Add(View->VQ, &yyvsp[-5].d);
      List_Add(View->VQ, &yyvsp[-21].d);  List_Add(View->VQ, &yyvsp[-15].d);
      List_Add(View->VQ, &yyvsp[-9].d); List_Add(View->VQ, &yyvsp[-3].d);
      List_Add(View->VQ, &yyvsp[-19].d);  List_Add(View->VQ, &yyvsp[-13].d);
      List_Add(View->VQ, &yyvsp[-7].d); List_Add(View->VQ, &yyvsp[-1].d);
      ntmp = List_Nbr(View->VQ);
    ;}
    break;

  case 147:
#line 762 "Gmsh.y"
    {
      if((List_Nbr(View->VQ) - ntmp) % 12)
	yymsg(GERROR, "Wrong number of values for vector quadrangle "
	      "(%d is not a multiple of 12)", List_Nbr(View->VQ) - ntmp);
      View->NbVQ++;
    ;}
    break;

  case 148:
#line 772 "Gmsh.y"
    { List_Add(View->TQ, &yyvsp[0].d); ;}
    break;

  case 149:
#line 774 "Gmsh.y"
    { List_Add(View->TQ, &yyvsp[0].d); ;}
    break;

  case 150:
#line 782 "Gmsh.y"
    { 
      List_Add(View->TQ, &yyvsp[-23].d);  List_Add(View->TQ, &yyvsp[-17].d);
      List_Add(View->TQ, &yyvsp[-11].d); List_Add(View->TQ, &yyvsp[-5].d);
      List_Add(View->TQ, &yyvsp[-21].d);  List_Add(View->TQ, &yyvsp[-15].d);
      List_Add(View->TQ, &yyvsp[-9].d); List_Add(View->TQ, &yyvsp[-3].d);
      List_Add(View->TQ, &yyvsp[-19].d);  List_Add(View->TQ, &yyvsp[-13].d);
      List_Add(View->TQ, &yyvsp[-7].d); List_Add(View->TQ, &yyvsp[-1].d);
      ntmp = List_Nbr(View->TQ);
    ;}
    break;

  case 151:
#line 792 "Gmsh.y"
    {
      if((List_Nbr(View->TQ) - ntmp) % 36)
	yymsg(GERROR, "Wrong number of values for tensor quadrangle "
	      "(%d is not a multiple of 36)", List_Nbr(View->TQ) - ntmp);
      View->NbTQ++;
    ;}
    break;

  case 152:
#line 802 "Gmsh.y"
    { List_Add(View->SS, &yyvsp[0].d); ;}
    break;

  case 153:
#line 804 "Gmsh.y"
    { List_Add(View->SS, &yyvsp[0].d); ;}
    break;

  case 154:
#line 812 "Gmsh.y"
    { 
      List_Add(View->SS, &yyvsp[-23].d);  List_Add(View->SS, &yyvsp[-17].d);
      List_Add(View->SS, &yyvsp[-11].d); List_Add(View->SS, &yyvsp[-5].d);
      List_Add(View->SS, &yyvsp[-21].d);  List_Add(View->SS, &yyvsp[-15].d);
      List_Add(View->SS, &yyvsp[-9].d); List_Add(View->SS, &yyvsp[-3].d);
      List_Add(View->SS, &yyvsp[-19].d);  List_Add(View->SS, &yyvsp[-13].d);
      List_Add(View->SS, &yyvsp[-7].d); List_Add(View->SS, &yyvsp[-1].d);
      ntmp = List_Nbr(View->SS);
    ;}
    break;

  case 155:
#line 822 "Gmsh.y"
    {
      if((List_Nbr(View->SS) - ntmp) % 4)
	yymsg(GERROR, "Wrong number of values for scalar tetrahedron "
	      "(%d is not a multiple of 4)", List_Nbr(View->SS) - ntmp);
      View->NbSS++;
    ;}
    break;

  case 156:
#line 832 "Gmsh.y"
    { List_Add(View->VS, &yyvsp[0].d); ;}
    break;

  case 157:
#line 834 "Gmsh.y"
    { List_Add(View->VS, &yyvsp[0].d); ;}
    break;

  case 158:
#line 842 "Gmsh.y"
    { 
      List_Add(View->VS, &yyvsp[-23].d);  List_Add(View->VS, &yyvsp[-17].d);
      List_Add(View->VS, &yyvsp[-11].d); List_Add(View->VS, &yyvsp[-5].d);
      List_Add(View->VS, &yyvsp[-21].d);  List_Add(View->VS, &yyvsp[-15].d);
      List_Add(View->VS, &yyvsp[-9].d); List_Add(View->VS, &yyvsp[-3].d);
      List_Add(View->VS, &yyvsp[-19].d);  List_Add(View->VS, &yyvsp[-13].d);
      List_Add(View->VS, &yyvsp[-7].d); List_Add(View->VS, &yyvsp[-1].d);
      ntmp = List_Nbr(View->VS);
    ;}
    break;

  case 159:
#line 852 "Gmsh.y"
    {
      if((List_Nbr(View->VS) - ntmp) % 12)
	yymsg(GERROR, "Wrong number of values for vector tetrahedron "
	      "(%d is not a multiple of 12)", List_Nbr(View->VS) - ntmp);
      View->NbVS++;
    ;}
    break;

  case 160:
#line 862 "Gmsh.y"
    { List_Add(View->TS, &yyvsp[0].d); ;}
    break;

  case 161:
#line 864 "Gmsh.y"
    { List_Add(View->TS, &yyvsp[0].d); ;}
    break;

  case 162:
#line 872 "Gmsh.y"
    { 
      List_Add(View->TS, &yyvsp[-23].d);  List_Add(View->TS, &yyvsp[-17].d);
      List_Add(View->TS, &yyvsp[-11].d); List_Add(View->TS, &yyvsp[-5].d);
      List_Add(View->TS, &yyvsp[-21].d);  List_Add(View->TS, &yyvsp[-15].d);
      List_Add(View->TS, &yyvsp[-9].d); List_Add(View->TS, &yyvsp[-3].d);
      List_Add(View->TS, &yyvsp[-19].d);  List_Add(View->TS, &yyvsp[-13].d);
      List_Add(View->TS, &yyvsp[-7].d); List_Add(View->TS, &yyvsp[-1].d);
      ntmp = List_Nbr(View->TS);
    ;}
    break;

  case 163:
#line 882 "Gmsh.y"
    {
      if((List_Nbr(View->TS) - ntmp) % 36)
	yymsg(GERROR, "Wrong number of values for tensor tetrahedron "
	      "(%d is not a multiple of 36)", List_Nbr(View->TS) - ntmp);
      View->NbTS++;
    ;}
    break;

  case 164:
#line 892 "Gmsh.y"
    { List_Add(View->SH, &yyvsp[0].d); ;}
    break;

  case 165:
#line 894 "Gmsh.y"
    { List_Add(View->SH, &yyvsp[0].d); ;}
    break;

  case 166:
#line 906 "Gmsh.y"
    { 
      List_Add(View->SH, &yyvsp[-47].d);  List_Add(View->SH, &yyvsp[-41].d);
      List_Add(View->SH, &yyvsp[-35].d); List_Add(View->SH, &yyvsp[-29].d);
      List_Add(View->SH, &yyvsp[-23].d); List_Add(View->SH, &yyvsp[-17].d);
      List_Add(View->SH, &yyvsp[-11].d); List_Add(View->SH, &yyvsp[-5].d);
      List_Add(View->SH, &yyvsp[-45].d);  List_Add(View->SH, &yyvsp[-39].d);
      List_Add(View->SH, &yyvsp[-33].d); List_Add(View->SH, &yyvsp[-27].d);
      List_Add(View->SH, &yyvsp[-21].d); List_Add(View->SH, &yyvsp[-15].d);
      List_Add(View->SH, &yyvsp[-9].d); List_Add(View->SH, &yyvsp[-3].d);
      List_Add(View->SH, &yyvsp[-43].d);  List_Add(View->SH, &yyvsp[-37].d);
      List_Add(View->SH, &yyvsp[-31].d); List_Add(View->SH, &yyvsp[-25].d);
      List_Add(View->SH, &yyvsp[-19].d); List_Add(View->SH, &yyvsp[-13].d);
      List_Add(View->SH, &yyvsp[-7].d); List_Add(View->SH, &yyvsp[-1].d);
      ntmp = List_Nbr(View->SH);
    ;}
    break;

  case 167:
#line 922 "Gmsh.y"
    {
      if((List_Nbr(View->SH) - ntmp) % 8)
	yymsg(GERROR, "Wrong number of values for scalar hexahedron "
	      "(%d is not a multiple of 8)", List_Nbr(View->SH) - ntmp);
      View->NbSH++;
    ;}
    break;

  case 168:
#line 932 "Gmsh.y"
    { List_Add(View->VH, &yyvsp[0].d); ;}
    break;

  case 169:
#line 934 "Gmsh.y"
    { List_Add(View->VH, &yyvsp[0].d); ;}
    break;

  case 170:
#line 946 "Gmsh.y"
    { 
      List_Add(View->VH, &yyvsp[-47].d);  List_Add(View->VH, &yyvsp[-41].d);
      List_Add(View->VH, &yyvsp[-35].d); List_Add(View->VH, &yyvsp[-29].d);
      List_Add(View->VH, &yyvsp[-23].d); List_Add(View->VH, &yyvsp[-17].d);
      List_Add(View->VH, &yyvsp[-11].d); List_Add(View->VH, &yyvsp[-5].d);
      List_Add(View->VH, &yyvsp[-45].d);  List_Add(View->VH, &yyvsp[-39].d);
      List_Add(View->VH, &yyvsp[-33].d); List_Add(View->VH, &yyvsp[-27].d);
      List_Add(View->VH, &yyvsp[-21].d); List_Add(View->VH, &yyvsp[-15].d);
      List_Add(View->VH, &yyvsp[-9].d); List_Add(View->VH, &yyvsp[-3].d);
      List_Add(View->VH, &yyvsp[-43].d);  List_Add(View->VH, &yyvsp[-37].d);
      List_Add(View->VH, &yyvsp[-31].d); List_Add(View->VH, &yyvsp[-25].d);
      List_Add(View->VH, &yyvsp[-19].d); List_Add(View->VH, &yyvsp[-13].d);
      List_Add(View->VH, &yyvsp[-7].d); List_Add(View->VH, &yyvsp[-1].d);
      ntmp = List_Nbr(View->VH);
    ;}
    break;

  case 171:
#line 962 "Gmsh.y"
    {
      if((List_Nbr(View->VH) - ntmp) % 24)
	yymsg(GERROR, "Wrong number of values for vector hexahedron "
	      "(%d is not a multiple of 24)", List_Nbr(View->VH) - ntmp);
      View->NbVH++;
    ;}
    break;

  case 172:
#line 972 "Gmsh.y"
    { List_Add(View->TH, &yyvsp[0].d); ;}
    break;

  case 173:
#line 974 "Gmsh.y"
    { List_Add(View->TH, &yyvsp[0].d); ;}
    break;

  case 174:
#line 986 "Gmsh.y"
    { 
      List_Add(View->TH, &yyvsp[-47].d);  List_Add(View->TH, &yyvsp[-41].d);
      List_Add(View->TH, &yyvsp[-35].d); List_Add(View->TH, &yyvsp[-29].d);
      List_Add(View->TH, &yyvsp[-23].d); List_Add(View->TH, &yyvsp[-17].d);
      List_Add(View->TH, &yyvsp[-11].d); List_Add(View->TH, &yyvsp[-5].d);
      List_Add(View->TH, &yyvsp[-45].d);  List_Add(View->TH, &yyvsp[-39].d);
      List_Add(View->TH, &yyvsp[-33].d); List_Add(View->TH, &yyvsp[-27].d);
      List_Add(View->TH, &yyvsp[-21].d); List_Add(View->TH, &yyvsp[-15].d);
      List_Add(View->TH, &yyvsp[-9].d); List_Add(View->TH, &yyvsp[-3].d);
      List_Add(View->TH, &yyvsp[-43].d);  List_Add(View->TH, &yyvsp[-37].d);
      List_Add(View->TH, &yyvsp[-31].d); List_Add(View->TH, &yyvsp[-25].d);
      List_Add(View->TH, &yyvsp[-19].d); List_Add(View->TH, &yyvsp[-13].d);
      List_Add(View->TH, &yyvsp[-7].d); List_Add(View->TH, &yyvsp[-1].d);
      ntmp = List_Nbr(View->TH);
    ;}
    break;

  case 175:
#line 1002 "Gmsh.y"
    {
      if((List_Nbr(View->TH) - ntmp) % 72)
	yymsg(GERROR, "Wrong number of values for tensor hexahedron "
	      "(%d is not a multiple of 72)", List_Nbr(View->TH) - ntmp);
      View->NbTH++;
    ;}
    break;

  case 176:
#line 1012 "Gmsh.y"
    { List_Add(View->SI, &yyvsp[0].d); ;}
    break;

  case 177:
#line 1014 "Gmsh.y"
    { List_Add(View->SI, &yyvsp[0].d); ;}
    break;

  case 178:
#line 1024 "Gmsh.y"
    { 
      List_Add(View->SI, &yyvsp[-35].d);  List_Add(View->SI, &yyvsp[-29].d);
      List_Add(View->SI, &yyvsp[-23].d); List_Add(View->SI, &yyvsp[-17].d);
      List_Add(View->SI, &yyvsp[-11].d); List_Add(View->SI, &yyvsp[-5].d);
      List_Add(View->SI, &yyvsp[-33].d);  List_Add(View->SI, &yyvsp[-27].d);
      List_Add(View->SI, &yyvsp[-21].d); List_Add(View->SI, &yyvsp[-15].d);
      List_Add(View->SI, &yyvsp[-9].d); List_Add(View->SI, &yyvsp[-3].d);
      List_Add(View->SI, &yyvsp[-31].d);  List_Add(View->SI, &yyvsp[-25].d);
      List_Add(View->SI, &yyvsp[-19].d); List_Add(View->SI, &yyvsp[-13].d);
      List_Add(View->SI, &yyvsp[-7].d); List_Add(View->SI, &yyvsp[-1].d);
      ntmp = List_Nbr(View->SI);
    ;}
    break;

  case 179:
#line 1037 "Gmsh.y"
    {
      if((List_Nbr(View->SI) - ntmp) % 6)
	yymsg(GERROR, "Wrong number of values for scalar prism "
	      "(%d is not a multiple of 6)", List_Nbr(View->SI) - ntmp);
      View->NbSI++;
    ;}
    break;

  case 180:
#line 1047 "Gmsh.y"
    { List_Add(View->VI, &yyvsp[0].d); ;}
    break;

  case 181:
#line 1049 "Gmsh.y"
    { List_Add(View->VI, &yyvsp[0].d); ;}
    break;

  case 182:
#line 1059 "Gmsh.y"
    { 
      List_Add(View->VI, &yyvsp[-35].d);  List_Add(View->VI, &yyvsp[-29].d);
      List_Add(View->VI, &yyvsp[-23].d); List_Add(View->VI, &yyvsp[-17].d);
      List_Add(View->VI, &yyvsp[-11].d); List_Add(View->VI, &yyvsp[-5].d);
      List_Add(View->VI, &yyvsp[-33].d);  List_Add(View->VI, &yyvsp[-27].d);
      List_Add(View->VI, &yyvsp[-21].d); List_Add(View->VI, &yyvsp[-15].d);
      List_Add(View->VI, &yyvsp[-9].d); List_Add(View->VI, &yyvsp[-3].d);
      List_Add(View->VI, &yyvsp[-31].d);  List_Add(View->VI, &yyvsp[-25].d);
      List_Add(View->VI, &yyvsp[-19].d); List_Add(View->VI, &yyvsp[-13].d);
      List_Add(View->VI, &yyvsp[-7].d); List_Add(View->VI, &yyvsp[-1].d);
      ntmp = List_Nbr(View->VI);
    ;}
    break;

  case 183:
#line 1072 "Gmsh.y"
    {
      if((List_Nbr(View->VI) - ntmp) % 18)
	yymsg(GERROR, "Wrong number of values for vector prism "
	      "(%d is not a multiple of 18)", List_Nbr(View->VI) - ntmp);
      View->NbVI++;
    ;}
    break;

  case 184:
#line 1082 "Gmsh.y"
    { List_Add(View->TI, &yyvsp[0].d); ;}
    break;

  case 185:
#line 1084 "Gmsh.y"
    { List_Add(View->TI, &yyvsp[0].d); ;}
    break;

  case 186:
#line 1094 "Gmsh.y"
    { 
      List_Add(View->TI, &yyvsp[-35].d);  List_Add(View->TI, &yyvsp[-29].d);
      List_Add(View->TI, &yyvsp[-23].d); List_Add(View->TI, &yyvsp[-17].d);
      List_Add(View->TI, &yyvsp[-11].d); List_Add(View->TI, &yyvsp[-5].d);
      List_Add(View->TI, &yyvsp[-33].d);  List_Add(View->TI, &yyvsp[-27].d);
      List_Add(View->TI, &yyvsp[-21].d); List_Add(View->TI, &yyvsp[-15].d);
      List_Add(View->TI, &yyvsp[-9].d); List_Add(View->TI, &yyvsp[-3].d);
      List_Add(View->TI, &yyvsp[-31].d);  List_Add(View->TI, &yyvsp[-25].d);
      List_Add(View->TI, &yyvsp[-19].d); List_Add(View->TI, &yyvsp[-13].d);
      List_Add(View->TI, &yyvsp[-7].d); List_Add(View->TI, &yyvsp[-1].d);
      ntmp = List_Nbr(View->TI);
    ;}
    break;

  case 187:
#line 1107 "Gmsh.y"
    {
      if((List_Nbr(View->TI) - ntmp) % 54)
	yymsg(GERROR, "Wrong number of values for tensor prism "
	      "(%d is not a multiple of 54)", List_Nbr(View->TI) - ntmp);
      View->NbTI++;
    ;}
    break;

  case 188:
#line 1117 "Gmsh.y"
    { List_Add(View->SY, &yyvsp[0].d); ;}
    break;

  case 189:
#line 1119 "Gmsh.y"
    { List_Add(View->SY, &yyvsp[0].d); ;}
    break;

  case 190:
#line 1128 "Gmsh.y"
    { 
      List_Add(View->SY, &yyvsp[-29].d);  List_Add(View->SY, &yyvsp[-23].d);
      List_Add(View->SY, &yyvsp[-17].d); List_Add(View->SY, &yyvsp[-11].d);
      List_Add(View->SY, &yyvsp[-5].d);
      List_Add(View->SY, &yyvsp[-27].d);  List_Add(View->SY, &yyvsp[-21].d);
      List_Add(View->SY, &yyvsp[-15].d); List_Add(View->SY, &yyvsp[-9].d);
      List_Add(View->SY, &yyvsp[-3].d);
      List_Add(View->SY, &yyvsp[-25].d);  List_Add(View->SY, &yyvsp[-19].d);
      List_Add(View->SY, &yyvsp[-13].d); List_Add(View->SY, &yyvsp[-7].d);
      List_Add(View->SY, &yyvsp[-1].d);
      ntmp = List_Nbr(View->SY);
    ;}
    break;

  case 191:
#line 1141 "Gmsh.y"
    {
      if((List_Nbr(View->SY) - ntmp) % 5)
	yymsg(GERROR, "Wrong number of values for scalar pyramid "
	      "(%d is not a multiple of 5)", List_Nbr(View->SY) - ntmp);
      View->NbSY++;
    ;}
    break;

  case 192:
#line 1151 "Gmsh.y"
    { List_Add(View->VY, &yyvsp[0].d); ;}
    break;

  case 193:
#line 1153 "Gmsh.y"
    { List_Add(View->VY, &yyvsp[0].d); ;}
    break;

  case 194:
#line 1162 "Gmsh.y"
    { 
      List_Add(View->VY, &yyvsp[-29].d);  List_Add(View->VY, &yyvsp[-23].d);
      List_Add(View->VY, &yyvsp[-17].d); List_Add(View->VY, &yyvsp[-11].d);
      List_Add(View->VY, &yyvsp[-5].d);
      List_Add(View->VY, &yyvsp[-27].d);  List_Add(View->VY, &yyvsp[-21].d);
      List_Add(View->VY, &yyvsp[-15].d); List_Add(View->VY, &yyvsp[-9].d);
      List_Add(View->VY, &yyvsp[-3].d);
      List_Add(View->VY, &yyvsp[-25].d);  List_Add(View->VY, &yyvsp[-19].d);
      List_Add(View->VY, &yyvsp[-13].d); List_Add(View->VY, &yyvsp[-7].d);
      List_Add(View->VY, &yyvsp[-1].d);
      ntmp = List_Nbr(View->VY);
    ;}
    break;

  case 195:
#line 1175 "Gmsh.y"
    {
      if((List_Nbr(View->VY) - ntmp) % 15)
	yymsg(GERROR, "Wrong number of values for vector pyramid "
	      "(%d is not a multiple of 15)", List_Nbr(View->VY) - ntmp);
      View->NbVY++;
    ;}
    break;

  case 196:
#line 1185 "Gmsh.y"
    { List_Add(View->TY, &yyvsp[0].d); ;}
    break;

  case 197:
#line 1187 "Gmsh.y"
    { List_Add(View->TY, &yyvsp[0].d); ;}
    break;

  case 198:
#line 1196 "Gmsh.y"
    { 
      List_Add(View->TY, &yyvsp[-29].d);  List_Add(View->TY, &yyvsp[-23].d);
      List_Add(View->TY, &yyvsp[-17].d); List_Add(View->TY, &yyvsp[-11].d);
      List_Add(View->TY, &yyvsp[-5].d);
      List_Add(View->TY, &yyvsp[-27].d);  List_Add(View->TY, &yyvsp[-21].d);
      List_Add(View->TY, &yyvsp[-15].d); List_Add(View->TY, &yyvsp[-9].d);
      List_Add(View->TY, &yyvsp[-3].d);
      List_Add(View->TY, &yyvsp[-25].d);  List_Add(View->TY, &yyvsp[-19].d);
      List_Add(View->TY, &yyvsp[-13].d); List_Add(View->TY, &yyvsp[-7].d);
      List_Add(View->TY, &yyvsp[-1].d);
      ntmp = List_Nbr(View->TY);
    ;}
    break;

  case 199:
#line 1209 "Gmsh.y"
    {
      if((List_Nbr(View->TY) - ntmp) % 45)
	yymsg(GERROR, "Wrong number of values for tensor pyramid "
	      "(%d is not a multiple of 45)", List_Nbr(View->TY) - ntmp);
      View->NbTY++;
    ;}
    break;

  case 200:
#line 1219 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T2C, &yyvsp[0].c[i]); 
      Free(yyvsp[0].c);
    ;}
    break;

  case 201:
#line 1224 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T2C, &yyvsp[0].c[i]); 
      Free(yyvsp[0].c);
    ;}
    break;

  case 202:
#line 1232 "Gmsh.y"
    { 
      List_Add(View->T2D, &yyvsp[-5].d); List_Add(View->T2D, &yyvsp[-3].d);
      List_Add(View->T2D, &yyvsp[-1].d); 
      double d = List_Nbr(View->T2C);
      List_Add(View->T2D, &d); 
    ;}
    break;

  case 203:
#line 1239 "Gmsh.y"
    {
      View->NbT2++;
    ;}
    break;

  case 204:
#line 1246 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T3C, &yyvsp[0].c[i]); 
      Free(yyvsp[0].c);
    ;}
    break;

  case 205:
#line 1251 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T3C, &yyvsp[0].c[i]); 
      Free(yyvsp[0].c);
    ;}
    break;

  case 206:
#line 1259 "Gmsh.y"
    { 
      List_Add(View->T3D, &yyvsp[-7].d); List_Add(View->T3D, &yyvsp[-5].d);
      List_Add(View->T3D, &yyvsp[-3].d); List_Add(View->T3D, &yyvsp[-1].d); 
      double d = List_Nbr(View->T3C);
      List_Add(View->T3D, &d); 
    ;}
    break;

  case 207:
#line 1266 "Gmsh.y"
    {
      View->NbT3++;
    ;}
    break;

  case 208:
#line 1273 "Gmsh.y"
    {
      View -> adaptive = new Adaptive_Post_View ( View , yyvsp[-2].l , yyvsp[-1].l);
    ;}
    break;

  case 209:
#line 1281 "Gmsh.y"
    { yyval.i = 0; ;}
    break;

  case 210:
#line 1282 "Gmsh.y"
    { yyval.i = 1; ;}
    break;

  case 211:
#line 1283 "Gmsh.y"
    { yyval.i = 2; ;}
    break;

  case 212:
#line 1284 "Gmsh.y"
    { yyval.i = 3; ;}
    break;

  case 213:
#line 1285 "Gmsh.y"
    { yyval.i = 4; ;}
    break;

  case 214:
#line 1289 "Gmsh.y"
    { yyval.i = 1; ;}
    break;

  case 215:
#line 1290 "Gmsh.y"
    { yyval.i = -1; ;}
    break;

  case 216:
#line 1298 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-3].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(1, 1, sizeof(double));
	if(!yyvsp[-2].i){
	  List_Put(TheSymbol.val, 0, &yyvsp[-1].d);
	  Tree_Add(Symbol_T, &TheSymbol);
	}
	else
	  yymsg(GERROR, "Unknown variable '%s'", yyvsp[-3].c);
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
      }
    ;}
    break;

  case 217:
#line 1326 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-6].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(5, 5, sizeof(double));
	if(!yyvsp[-2].i){
	  List_Put(TheSymbol.val, (int)yyvsp[-4].d, &yyvsp[-1].d);
	  Tree_Add(Symbol_T, &TheSymbol);
	}
	else
	  yymsg(GERROR, "Unknown variable '%s'", yyvsp[-6].c);
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
      }
    ;}
    break;

  case 218:
#line 1362 "Gmsh.y"
    {
      if(List_Nbr(yyvsp[-5].l) != List_Nbr(yyvsp[-1].l))
	yymsg(GERROR, "Incompatible array dimensions in affectation");
      else{
	Symbol TheSymbol;
	TheSymbol.Name = yyvsp[-8].c;
	Symbol *pSymbol;
	if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	  TheSymbol.val = List_Create(5, 5, sizeof(double));
	  if(!yyvsp[-2].i){
	    for(int i = 0; i < List_Nbr(yyvsp[-5].l); i++){
	      List_Put(TheSymbol.val, (int)(*(double*)List_Pointer(yyvsp[-5].l, i)),
		       (double*)List_Pointer(yyvsp[-1].l, i));
	    }
	    Tree_Add(Symbol_T, &TheSymbol);
	  }
	  else
	    yymsg(GERROR, "Unknown variable '%s'", yyvsp[-8].c);
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
	}
      }
      List_Delete(yyvsp[-5].l);
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 219:
#line 1411 "Gmsh.y"
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
      }
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 220:
#line 1427 "Gmsh.y"
    {
      Symbol TheSymbol;
      TheSymbol.Name = yyvsp[-2].c;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol)))
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-2].c); 
      else
	*(double*)List_Pointer_Fast(pSymbol->val, 0) += yyvsp[-1].i; 
    ;}
    break;

  case 221:
#line 1437 "Gmsh.y"
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
    ;}
    break;

  case 222:
#line 1455 "Gmsh.y"
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
    ;}
    break;

  case 223:
#line 1468 "Gmsh.y"
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
    ;}
    break;

  case 224:
#line 1484 "Gmsh.y"
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
    ;}
    break;

  case 225:
#line 1509 "Gmsh.y"
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
    ;}
    break;

  case 226:
#line 1535 "Gmsh.y"
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
    ;}
    break;

  case 227:
#line 1548 "Gmsh.y"
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
    ;}
    break;

  case 228:
#line 1564 "Gmsh.y"
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
    ;}
    break;

  case 229:
#line 1577 "Gmsh.y"
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
    ;}
    break;

  case 230:
#line 1593 "Gmsh.y"
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
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 231:
#line 1612 "Gmsh.y"
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
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 232:
#line 1634 "Gmsh.y"
    {
      try {
	GMSH_PluginManager::instance()->setPluginOption(yyvsp[-6].c, yyvsp[-3].c, yyvsp[-1].d); 
      }
      catch (...) {
	yymsg(GERROR, "Unknown option '%s' or plugin '%s'", yyvsp[-3].c, yyvsp[-6].c);
      }
    ;}
    break;

  case 233:
#line 1643 "Gmsh.y"
    {
      try {
	GMSH_PluginManager::instance()->setPluginOption(yyvsp[-6].c, yyvsp[-3].c, yyvsp[-1].c); 
      }
      catch (...) {
	yymsg(GERROR, "Unknown option '%s' or plugin '%s'", yyvsp[-3].c, yyvsp[-6].c);
      }
    ;}
    break;

  case 234:
#line 1661 "Gmsh.y"
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

  case 235:
#line 1677 "Gmsh.y"
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

  case 236:
#line 1693 "Gmsh.y"
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

  case 237:
#line 1712 "Gmsh.y"
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

  case 238:
#line 1731 "Gmsh.y"
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

  case 239:
#line 1749 "Gmsh.y"
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

  case 240:
#line 1767 "Gmsh.y"
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

  case 241:
#line 1785 "Gmsh.y"
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

  case 242:
#line 1811 "Gmsh.y"
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

  case 243:
#line 1829 "Gmsh.y"
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

  case 244:
#line 1856 "Gmsh.y"
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
      yyval.s.Type = MSH_SEGM_PARAMETRIC;
      yyval.s.Num = num;
    ;}
    break;

  case 245:
#line 1874 "Gmsh.y"
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

  case 246:
#line 1898 "Gmsh.y"
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

  case 247:
#line 1922 "Gmsh.y"
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

  case 248:
#line 1948 "Gmsh.y"
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

  case 249:
#line 1965 "Gmsh.y"
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

  case 250:
#line 1983 "Gmsh.y"
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

  case 251:
#line 2002 "Gmsh.y"
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

  case 252:
#line 2021 "Gmsh.y"
    {
      int num = (int)yyvsp[-4].d, type = 0;
      if(FindSurface(num, THEM)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	double d;
	List_Read(yyvsp[-1].l, 0, &d);
	EdgeLoop *el = FindEdgeLoop((int)d, THEM);
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

  case 253:
#line 2060 "Gmsh.y"
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

  case 254:
#line 2086 "Gmsh.y"
    {
      int num = (int)yyvsp[-10].d, type = 0;
      Surface *s = FindSurface(num, THEM);
      if(!s) {
	yymsg(GERROR, "Unknown surface %d", num);
      }
      else{
	// FIXME: parameters not used; undocumented
	POLY_rep *rep = new POLY_rep(yyvsp[-2].l, yyvsp[-1].l);
	s->thePolyRep = rep;
	type = s->Typ;
      }
      //FIXME: do you copy the data?
      //List_Delete($12);
      //List_Delete($13);
      yyval.s.Type = type;
      yyval.s.Num = (int)yyvsp[-10].d;
    ;}
    break;

  case 255:
#line 2108 "Gmsh.y"
    {
      int num = (int)yyvsp[-10].d, type = 0;
      Surface *s = FindSurface(num, THEM);
      if(!s) {
	yymsg(GERROR, "Unknown surface %d", num);
      }
      else{
	POLY_rep *rep = new POLY_rep(yyvsp[-2].l, yyvsp[-1].l);
	s->thePolyRep = rep;
	type = s->Typ;
      }
      yyval.s.Type = type;
      yyval.s.Num = (int)yyvsp[-10].d;
    ;}
    break;

  case 256:
#line 2125 "Gmsh.y"
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

  case 257:
#line 2144 "Gmsh.y"
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

  case 258:
#line 2161 "Gmsh.y"
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

  case 259:
#line 2177 "Gmsh.y"
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

  case 260:
#line 2196 "Gmsh.y"
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

  case 261:
#line 2213 "Gmsh.y"
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

  case 262:
#line 2230 "Gmsh.y"
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

  case 263:
#line 2251 "Gmsh.y"
    {
      TranslateShapes(yyvsp[-3].v[0], yyvsp[-3].v[1], yyvsp[-3].v[2], yyvsp[-1].l, 1);
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 264:
#line 2256 "Gmsh.y"
    {
      RotateShapes(yyvsp[-8].v[0], yyvsp[-8].v[1], yyvsp[-8].v[2], yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2], yyvsp[-4].d, yyvsp[-1].l, 1);
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 265:
#line 2261 "Gmsh.y"
    {
      SymmetryShapes(yyvsp[-3].v[0], yyvsp[-3].v[1], yyvsp[-3].v[2], yyvsp[-3].v[3], yyvsp[-1].l, 1);
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 266:
#line 2266 "Gmsh.y"
    {
      DilatShapes(yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2], yyvsp[-4].d, yyvsp[-1].l, 1);
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 267:
#line 2273 "Gmsh.y"
    { yyval.l = yyvsp[0].l; ;}
    break;

  case 268:
#line 2274 "Gmsh.y"
    { yyval.l = yyvsp[0].l; ;}
    break;

  case 269:
#line 2275 "Gmsh.y"
    { yyval.l = yyvsp[0].l; ;}
    break;

  case 270:
#line 2280 "Gmsh.y"
    {
      yyval.l = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 271:
#line 2284 "Gmsh.y"
    {
      List_Add(yyval.l, &yyvsp[0].s);
    ;}
    break;

  case 272:
#line 2288 "Gmsh.y"
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

  case 273:
#line 2304 "Gmsh.y"
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

  case 274:
#line 2320 "Gmsh.y"
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

  case 275:
#line 2336 "Gmsh.y"
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

  case 276:
#line 2357 "Gmsh.y"
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

  case 277:
#line 2370 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-4].c, "View")) DuplicateView((int)yyvsp[-2].d, 0);
      yyval.l = NULL;
    ;}
    break;

  case 278:
#line 2381 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-1].l); i++){
	Shape TheShape;
	List_Read(yyvsp[-1].l, i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 279:
#line 2390 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-4].c, "View")){
	RemoveViewByIndex((int)yyvsp[-2].d);
#if defined(HAVE_FLTK)
	if(!CTX.batch)
	  UpdateViewsInGUI();
#endif
      }
    ;}
    break;

  case 280:
#line 2400 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-1].c, "Meshes") || !strcmp(yyvsp[-1].c, "All"))
	Init_Mesh(THEM);
    ;}
    break;

  case 281:
#line 2410 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-1].l); i++){
	Shape TheShape;
	List_Read(yyvsp[-1].l, i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, yyvsp[-3].u);
      }
      List_Delete(yyvsp[-1].l);      
    ;}
    break;

  case 282:
#line 2424 "Gmsh.y"
    {
      int m = (CTX.visibility_mode == 2) ? VIS_MESH : 
	((CTX.visibility_mode == 1) ? VIS_GEOM : VIS_GEOM|VIS_MESH);
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber(yyvsp[-1].c, i, m);
    ;}
    break;

  case 283:
#line 2431 "Gmsh.y"
    {
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber(yyvsp[-1].c, i, 0);
    ;}
    break;

  case 284:
#line 2436 "Gmsh.y"
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

  case 285:
#line 2447 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[-1].l); i++){
	Shape TheShape;
	List_Read(yyvsp[-1].l, i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete(yyvsp[-1].l);
    ;}
    break;

  case 286:
#line 2461 "Gmsh.y"
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
    ;}
    break;

  case 287:
#line 2504 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-6].c, "Save") && !strcmp(yyvsp[-5].c, "View")){
	Post_View *v = (Post_View *)List_Pointer_Test(CTX.post.list, (int)yyvsp[-3].d);
	if(v){
	  char tmpstring[1024];
	  FixRelativePath(yyvsp[-1].c, tmpstring);
	  WriteView(v, tmpstring, CTX.post.file_format, 0);
	}
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", yyvsp[-6].c);
      }
    ;}
    break;

  case 288:
#line 2518 "Gmsh.y"
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
    ;}
    break;

  case 289:
#line 2533 "Gmsh.y"
    {
      try {
	GMSH_PluginManager::instance()->action(yyvsp[-4].c, yyvsp[-1].c, 0);
      }
      catch(...) {
	yymsg(GERROR, "Unknown action '%s' or plugin '%s'", yyvsp[-1].c, yyvsp[-4].c);
      }
   ;}
    break;

  case 290:
#line 2542 "Gmsh.y"
    {
      // for backward compatibility
      if(!strcmp(yyvsp[-1].c, "Views"))
	CombineViews(0, 1, CTX.post.combine_remove_orig);
      else if(!strcmp(yyvsp[-1].c, "TimeSteps"))
	CombineViews(1, 2, CTX.post.combine_remove_orig);
      else
	yymsg(GERROR, "Unknown 'Combine' command");
    ;}
    break;

  case 291:
#line 2552 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 292:
#line 2556 "Gmsh.y"
    {
      SetBoundingBox();
    ;}
    break;

  case 293:
#line 2560 "Gmsh.y"
    {
      SetBoundingBox(yyvsp[-12].d, yyvsp[-10].d, yyvsp[-8].d, yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 294:
#line 2564 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      if(!CTX.batch) // we're in interactive mode
	Draw();
#endif
    ;}
    break;

  case 295:
#line 2577 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = yyvsp[-3].d;
      LoopControlVariablesTab[ImbricatedLoop][1] = yyvsp[-1].d;
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
    ;}
    break;

  case 296:
#line 2591 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = yyvsp[-5].d;
      LoopControlVariablesTab[ImbricatedLoop][1] = yyvsp[-3].d;
      LoopControlVariablesTab[ImbricatedLoop][2] = yyvsp[-1].d;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
    ;}
    break;

  case 297:
#line 2605 "Gmsh.y"
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
    ;}
    break;

  case 298:
#line 2630 "Gmsh.y"
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
    ;}
    break;

  case 299:
#line 2655 "Gmsh.y"
    {
      if(LoopControlVariablesTab[ImbricatedLoop-1][1] >  
	 LoopControlVariablesTab[ImbricatedLoop-1][0]){
	LoopControlVariablesTab[ImbricatedLoop-1][0] +=
	  LoopControlVariablesTab[ImbricatedLoop-1][2];
	if(strlen(LoopControlVariablesNameTab[ImbricatedLoop-1])){
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
	if(ImbricatedLoop < 0){
	  yymsg(GERROR, "Problem with imbricated loops");
	  ImbricatedLoop = 0;
	}
      }
    ;}
    break;

  case 300:
#line 2682 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction(yyvsp[0].c, yyin, yyname, yylineno))
	yymsg(GERROR, "Redefinition of function %s", yyvsp[0].c);
      skip_until(NULL, "Return");
    ;}
    break;

  case 301:
#line 2688 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin, yyname, yylineno))
	yymsg(GERROR, "Error while exiting function");
    ;}
    break;

  case 302:
#line 2693 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction(yyvsp[-1].c, &yyin, yyname, yylineno))
	yymsg(GERROR, "Unknown function %s", yyvsp[-1].c);
    ;}
    break;

  case 303:
#line 2698 "Gmsh.y"
    {
      if(!yyvsp[-1].d) skip_until("If", "EndIf");
    ;}
    break;

  case 304:
#line 2702 "Gmsh.y"
    {
    ;}
    break;

  case 305:
#line 2713 "Gmsh.y"
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

  case 306:
#line 2729 "Gmsh.y"
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

  case 307:
#line 2745 "Gmsh.y"
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

  case 308:
#line 2761 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 309:
#line 2766 "Gmsh.y"
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

  case 310:
#line 2782 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 311:
#line 2787 "Gmsh.y"
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

  case 312:
#line 2803 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 313:
#line 2808 "Gmsh.y"
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

  case 314:
#line 2826 "Gmsh.y"
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

  case 315:
#line 2849 "Gmsh.y"
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

  case 316:
#line 2872 "Gmsh.y"
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

  case 317:
#line 2895 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 318:
#line 2900 "Gmsh.y"
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

  case 319:
#line 2923 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 320:
#line 2928 "Gmsh.y"
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

  case 321:
#line 2951 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 322:
#line 2956 "Gmsh.y"
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

  case 323:
#line 2982 "Gmsh.y"
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

  case 324:
#line 3005 "Gmsh.y"
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

  case 325:
#line 3028 "Gmsh.y"
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

  case 326:
#line 3051 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 327:
#line 3056 "Gmsh.y"
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

  case 328:
#line 3079 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 329:
#line 3085 "Gmsh.y"
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

  case 330:
#line 3108 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 331:
#line 3114 "Gmsh.y"
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

  case 332:
#line 3140 "Gmsh.y"
    {
    ;}
    break;

  case 333:
#line 3143 "Gmsh.y"
    {
    ;}
    break;

  case 334:
#line 3149 "Gmsh.y"
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

  case 335:
#line 3175 "Gmsh.y"
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

  case 336:
#line 3199 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 337:
#line 3208 "Gmsh.y"
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

  case 338:
#line 3226 "Gmsh.y"
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

  case 339:
#line 3244 "Gmsh.y"
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

  case 340:
#line 3262 "Gmsh.y"
    {
      Surface *s = FindSurface((int)yyvsp[-4].d, THEM);
      if(!s)
	yymsg(WARNING, "Unknown surface %d", (int)yyvsp[-4].d);
      else{
	s->Method = TRANSFINI;
	int k = List_Nbr(yyvsp[-1].l);
	if(k != 3 && k != 4){
	  yymsg(GERROR, "Wrong definition of Transfinite Surface %d: "
		"%d points instead of 3 or 4" , yyvsp[-4].d, k);
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

  case 341:
#line 3289 "Gmsh.y"
    {
      Surface *s = FindSurface((int)yyvsp[-4].d, THEM);
      if(!s)
	yymsg(WARNING, "Unknown surface %d", (int)yyvsp[-4].d);
      else{
        s->Method = ELLIPTIC;
        int k = List_Nbr(yyvsp[-1].l);
        if(k != 4)
	  yymsg(GERROR, "Wrong definition of Elliptic Surface %d: "
		"%d points instead of 4" , yyvsp[-4].d, k);
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

  case 342:
#line 3315 "Gmsh.y"
    {
      Volume *v = FindVolume((int)yyvsp[-4].d, THEM);
      if(!v)
	yymsg(WARNING, "Unknown volume %d", (int)yyvsp[-4].d);
      else{
	v->Method = TRANSFINI;
	int k = List_Nbr(yyvsp[-1].l);
	if(k != 6 && k != 8)
	  yymsg(GERROR, "Wrong definition of Transfinite Volume %d: "
		"%d points instead of 6 or 8" , yyvsp[-4].d, k);
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

  case 343:
#line 3341 "Gmsh.y"
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

  case 344:
#line 3355 "Gmsh.y"
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

  case 345:
#line 3374 "Gmsh.y"
    { 
      ReplaceAllDuplicates(THEM);
    ;}
    break;

  case 346:
#line 3378 "Gmsh.y"
    { 
      IntersectAllSegmentsTogether();
    ;}
    break;

  case 347:
#line 3387 "Gmsh.y"
    {yyval.i = 1;;}
    break;

  case 348:
#line 3388 "Gmsh.y"
    {yyval.i = 0;;}
    break;

  case 349:
#line 3389 "Gmsh.y"
    {yyval.i = -1;;}
    break;

  case 350:
#line 3390 "Gmsh.y"
    {yyval.i = -1;;}
    break;

  case 351:
#line 3391 "Gmsh.y"
    {yyval.i = -1;;}
    break;

  case 352:
#line 3395 "Gmsh.y"
    { yyval.d = yyvsp[0].d;           ;}
    break;

  case 353:
#line 3396 "Gmsh.y"
    { yyval.d = yyvsp[-1].d;           ;}
    break;

  case 354:
#line 3397 "Gmsh.y"
    { yyval.d = -yyvsp[0].d;          ;}
    break;

  case 355:
#line 3398 "Gmsh.y"
    { yyval.d = yyvsp[0].d;           ;}
    break;

  case 356:
#line 3399 "Gmsh.y"
    { yyval.d = !yyvsp[0].d;          ;}
    break;

  case 357:
#line 3400 "Gmsh.y"
    { yyval.d = yyvsp[-2].d - yyvsp[0].d;      ;}
    break;

  case 358:
#line 3401 "Gmsh.y"
    { yyval.d = yyvsp[-2].d + yyvsp[0].d;      ;}
    break;

  case 359:
#line 3402 "Gmsh.y"
    { yyval.d = yyvsp[-2].d * yyvsp[0].d;      ;}
    break;

  case 360:
#line 3404 "Gmsh.y"
    { 
      if(!yyvsp[0].d)
	yymsg(GERROR, "Division by zero in '%g / %g'", yyvsp[-2].d, yyvsp[0].d);
      else
	yyval.d = yyvsp[-2].d / yyvsp[0].d;     
    ;}
    break;

  case 361:
#line 3410 "Gmsh.y"
    { yyval.d = (int)yyvsp[-2].d % (int)yyvsp[0].d;  ;}
    break;

  case 362:
#line 3411 "Gmsh.y"
    { yyval.d = pow(yyvsp[-2].d, yyvsp[0].d);  ;}
    break;

  case 363:
#line 3412 "Gmsh.y"
    { yyval.d = yyvsp[-2].d < yyvsp[0].d;      ;}
    break;

  case 364:
#line 3413 "Gmsh.y"
    { yyval.d = yyvsp[-2].d > yyvsp[0].d;      ;}
    break;

  case 365:
#line 3414 "Gmsh.y"
    { yyval.d = yyvsp[-2].d <= yyvsp[0].d;     ;}
    break;

  case 366:
#line 3415 "Gmsh.y"
    { yyval.d = yyvsp[-2].d >= yyvsp[0].d;     ;}
    break;

  case 367:
#line 3416 "Gmsh.y"
    { yyval.d = yyvsp[-2].d == yyvsp[0].d;     ;}
    break;

  case 368:
#line 3417 "Gmsh.y"
    { yyval.d = yyvsp[-2].d != yyvsp[0].d;     ;}
    break;

  case 369:
#line 3418 "Gmsh.y"
    { yyval.d = yyvsp[-2].d && yyvsp[0].d;     ;}
    break;

  case 370:
#line 3419 "Gmsh.y"
    { yyval.d = yyvsp[-2].d || yyvsp[0].d;     ;}
    break;

  case 371:
#line 3420 "Gmsh.y"
    { yyval.d = yyvsp[-4].d? yyvsp[-2].d : yyvsp[0].d;  ;}
    break;

  case 372:
#line 3421 "Gmsh.y"
    { yyval.d = exp(yyvsp[-1].d);      ;}
    break;

  case 373:
#line 3422 "Gmsh.y"
    { yyval.d = log(yyvsp[-1].d);      ;}
    break;

  case 374:
#line 3423 "Gmsh.y"
    { yyval.d = log10(yyvsp[-1].d);    ;}
    break;

  case 375:
#line 3424 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-1].d);     ;}
    break;

  case 376:
#line 3425 "Gmsh.y"
    { yyval.d = sin(yyvsp[-1].d);      ;}
    break;

  case 377:
#line 3426 "Gmsh.y"
    { yyval.d = asin(yyvsp[-1].d);     ;}
    break;

  case 378:
#line 3427 "Gmsh.y"
    { yyval.d = cos(yyvsp[-1].d);      ;}
    break;

  case 379:
#line 3428 "Gmsh.y"
    { yyval.d = acos(yyvsp[-1].d);     ;}
    break;

  case 380:
#line 3429 "Gmsh.y"
    { yyval.d = tan(yyvsp[-1].d);      ;}
    break;

  case 381:
#line 3430 "Gmsh.y"
    { yyval.d = atan(yyvsp[-1].d);     ;}
    break;

  case 382:
#line 3431 "Gmsh.y"
    { yyval.d = atan2(yyvsp[-3].d, yyvsp[-1].d);;}
    break;

  case 383:
#line 3432 "Gmsh.y"
    { yyval.d = sinh(yyvsp[-1].d);     ;}
    break;

  case 384:
#line 3433 "Gmsh.y"
    { yyval.d = cosh(yyvsp[-1].d);     ;}
    break;

  case 385:
#line 3434 "Gmsh.y"
    { yyval.d = tanh(yyvsp[-1].d);     ;}
    break;

  case 386:
#line 3435 "Gmsh.y"
    { yyval.d = fabs(yyvsp[-1].d);     ;}
    break;

  case 387:
#line 3436 "Gmsh.y"
    { yyval.d = floor(yyvsp[-1].d);    ;}
    break;

  case 388:
#line 3437 "Gmsh.y"
    { yyval.d = ceil(yyvsp[-1].d);     ;}
    break;

  case 389:
#line 3438 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 390:
#line 3439 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 391:
#line 3440 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-3].d*yyvsp[-3].d+yyvsp[-1].d*yyvsp[-1].d); ;}
    break;

  case 392:
#line 3441 "Gmsh.y"
    { yyval.d = yyvsp[-1].d*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 393:
#line 3443 "Gmsh.y"
    { yyval.d = exp(yyvsp[-1].d);      ;}
    break;

  case 394:
#line 3444 "Gmsh.y"
    { yyval.d = log(yyvsp[-1].d);      ;}
    break;

  case 395:
#line 3445 "Gmsh.y"
    { yyval.d = log10(yyvsp[-1].d);    ;}
    break;

  case 396:
#line 3446 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-1].d);     ;}
    break;

  case 397:
#line 3447 "Gmsh.y"
    { yyval.d = sin(yyvsp[-1].d);      ;}
    break;

  case 398:
#line 3448 "Gmsh.y"
    { yyval.d = asin(yyvsp[-1].d);     ;}
    break;

  case 399:
#line 3449 "Gmsh.y"
    { yyval.d = cos(yyvsp[-1].d);      ;}
    break;

  case 400:
#line 3450 "Gmsh.y"
    { yyval.d = acos(yyvsp[-1].d);     ;}
    break;

  case 401:
#line 3451 "Gmsh.y"
    { yyval.d = tan(yyvsp[-1].d);      ;}
    break;

  case 402:
#line 3452 "Gmsh.y"
    { yyval.d = atan(yyvsp[-1].d);     ;}
    break;

  case 403:
#line 3453 "Gmsh.y"
    { yyval.d = atan2(yyvsp[-3].d, yyvsp[-1].d);;}
    break;

  case 404:
#line 3454 "Gmsh.y"
    { yyval.d = sinh(yyvsp[-1].d);     ;}
    break;

  case 405:
#line 3455 "Gmsh.y"
    { yyval.d = cosh(yyvsp[-1].d);     ;}
    break;

  case 406:
#line 3456 "Gmsh.y"
    { yyval.d = tanh(yyvsp[-1].d);     ;}
    break;

  case 407:
#line 3457 "Gmsh.y"
    { yyval.d = fabs(yyvsp[-1].d);     ;}
    break;

  case 408:
#line 3458 "Gmsh.y"
    { yyval.d = floor(yyvsp[-1].d);    ;}
    break;

  case 409:
#line 3459 "Gmsh.y"
    { yyval.d = ceil(yyvsp[-1].d);     ;}
    break;

  case 410:
#line 3460 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 411:
#line 3461 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 412:
#line 3462 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-3].d*yyvsp[-3].d+yyvsp[-1].d*yyvsp[-1].d); ;}
    break;

  case 413:
#line 3463 "Gmsh.y"
    { yyval.d = yyvsp[-1].d*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 414:
#line 3472 "Gmsh.y"
    { yyval.d = yyvsp[0].d; ;}
    break;

  case 415:
#line 3473 "Gmsh.y"
    { yyval.d = 3.141592653589793; ;}
    break;

  case 416:
#line 3474 "Gmsh.y"
    { yyval.d = ParUtil::Instance()->rank(); ;}
    break;

  case 417:
#line 3475 "Gmsh.y"
    { yyval.d = ParUtil::Instance()->size(); ;}
    break;

  case 418:
#line 3480 "Gmsh.y"
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
    ;}
    break;

  case 419:
#line 3492 "Gmsh.y"
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
    ;}
    break;

  case 420:
#line 3511 "Gmsh.y"
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
    ;}
    break;

  case 421:
#line 3524 "Gmsh.y"
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
    ;}
    break;

  case 422:
#line 3536 "Gmsh.y"
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
    ;}
    break;

  case 423:
#line 3558 "Gmsh.y"
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
    ;}
    break;

  case 424:
#line 3575 "Gmsh.y"
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
    ;}
    break;

  case 425:
#line 3592 "Gmsh.y"
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
    ;}
    break;

  case 426:
#line 3609 "Gmsh.y"
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
    ;}
    break;

  case 427:
#line 3629 "Gmsh.y"
    {
      memcpy(yyval.v, yyvsp[0].v, 5*sizeof(double));
    ;}
    break;

  case 428:
#line 3633 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) yyval.v[i] = -yyvsp[0].v[i];
    ;}
    break;

  case 429:
#line 3637 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) yyval.v[i] = yyvsp[0].v[i];
    ;}
    break;

  case 430:
#line 3641 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) yyval.v[i] = yyvsp[-2].v[i] - yyvsp[0].v[i];
    ;}
    break;

  case 431:
#line 3645 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) yyval.v[i] = yyvsp[-2].v[i] + yyvsp[0].v[i];
    ;}
    break;

  case 432:
#line 3652 "Gmsh.y"
    { 
      yyval.v[0] = yyvsp[-9].d;  yyval.v[1] = yyvsp[-7].d;  yyval.v[2] = yyvsp[-5].d;  yyval.v[3] = yyvsp[-3].d; yyval.v[4] = yyvsp[-1].d;
    ;}
    break;

  case 433:
#line 3656 "Gmsh.y"
    { 
      yyval.v[0] = yyvsp[-7].d;  yyval.v[1] = yyvsp[-5].d;  yyval.v[2] = yyvsp[-3].d;  yyval.v[3] = yyvsp[-1].d; yyval.v[4] = 1.0;
    ;}
    break;

  case 434:
#line 3660 "Gmsh.y"
    {
      yyval.v[0] = yyvsp[-5].d;  yyval.v[1] = yyvsp[-3].d;  yyval.v[2] = yyvsp[-1].d;  yyval.v[3] = 0.0; yyval.v[4] = 1.0;
    ;}
    break;

  case 435:
#line 3664 "Gmsh.y"
    {
      yyval.v[0] = yyvsp[-5].d;  yyval.v[1] = yyvsp[-3].d;  yyval.v[2] = yyvsp[-1].d;  yyval.v[3] = 0.0; yyval.v[4] = 1.0;
    ;}
    break;

  case 436:
#line 3671 "Gmsh.y"
    {
    ;}
    break;

  case 437:
#line 3674 "Gmsh.y"
    {
    ;}
    break;

  case 438:
#line 3680 "Gmsh.y"
    {
    ;}
    break;

  case 439:
#line 3683 "Gmsh.y"
    {
    ;}
    break;

  case 440:
#line 3689 "Gmsh.y"
    {
    ;}
    break;

  case 441:
#line 3692 "Gmsh.y"
    {
       yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 442:
#line 3696 "Gmsh.y"
    {
       yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 443:
#line 3703 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(List_T*));
      List_Add(yyval.l, &(yyvsp[0].l));
    ;}
    break;

  case 444:
#line 3708 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].l));
    ;}
    break;

  case 445:
#line 3716 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(double));
      List_Add(yyval.l, &(yyvsp[0].d));
    ;}
    break;

  case 446:
#line 3721 "Gmsh.y"
    {
      yyval.l = yyvsp[0].l;
    ;}
    break;

  case 447:
#line 3725 "Gmsh.y"
    {
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 448:
#line 3729 "Gmsh.y"
    {
      yyval.l = yyvsp[-1].l;
      double *pd;
      for(int i = 0; i < List_Nbr(yyval.l); i++){
	pd = (double*)List_Pointer(yyval.l, i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 449:
#line 3741 "Gmsh.y"
    { 
      yyval.l = List_Create(2, 1, sizeof(double)); 
      for(double d = yyvsp[-2].d; (yyvsp[-2].d < yyvsp[0].d) ? (d <= yyvsp[0].d) : (d >= yyvsp[0].d); (yyvsp[-2].d < yyvsp[0].d) ? (d += 1.) : (d -= 1.)) 
	List_Add(yyval.l, &d);
    ;}
    break;

  case 450:
#line 3747 "Gmsh.y"
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

  case 451:
#line 3758 "Gmsh.y"
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

  case 452:
#line 3778 "Gmsh.y"
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

  case 453:
#line 3788 "Gmsh.y"
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

  case 454:
#line 3798 "Gmsh.y"
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

  case 455:
#line 3810 "Gmsh.y"
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
    ;}
    break;

  case 456:
#line 3826 "Gmsh.y"
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
    ;}
    break;

  case 457:
#line 3844 "Gmsh.y"
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
      List_Delete(yyvsp[-2].l);
    ;}
    break;

  case 458:
#line 3867 "Gmsh.y"
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
      List_Delete(yyvsp[-2].l);
    ;}
    break;

  case 459:
#line 3895 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(double));
      List_Add(yyval.l, &(yyvsp[0].d));
    ;}
    break;

  case 460:
#line 3900 "Gmsh.y"
    {
      yyval.l = yyvsp[0].l;
    ;}
    break;

  case 461:
#line 3904 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].d));
    ;}
    break;

  case 462:
#line 3908 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr(yyvsp[0].l); i++){
	double d;
	List_Read(yyvsp[0].l, i, &d);
	List_Add(yyval.l, &d);
      }
      List_Delete(yyvsp[0].l);
    ;}
    break;

  case 463:
#line 3921 "Gmsh.y"
    {
      yyval.u = PACK_COLOR((int)yyvsp[-7].d, (int)yyvsp[-5].d, (int)yyvsp[-3].d, (int)yyvsp[-1].d);
    ;}
    break;

  case 464:
#line 3925 "Gmsh.y"
    {
      yyval.u = PACK_COLOR((int)yyvsp[-5].d, (int)yyvsp[-3].d, (int)yyvsp[-1].d, 255);
    ;}
    break;

  case 465:
#line 3937 "Gmsh.y"
    {
      int flag;
      yyval.u = Get_ColorForString(ColorString, -1, yyvsp[0].c, &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", yyvsp[0].c);
    ;}
    break;

  case 466:
#line 3943 "Gmsh.y"
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
    ;}
    break;

  case 467:
#line 3964 "Gmsh.y"
    {
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 468:
#line 3968 "Gmsh.y"
    {
      yyval.l = List_Create(256, 10, sizeof(unsigned int));
      GmshColorTable *ct = Get_ColorTable((int)yyvsp[-3].d);
      if(!ct)
	yymsg(GERROR, "View[%d] does not exist", (int)yyvsp[-3].d);
      else{
	for(int i = 0; i < ct->size; i++) 
	  List_Add(yyval.l, &ct->table[i]);
      }
    ;}
    break;

  case 469:
#line 3982 "Gmsh.y"
    {
      yyval.l = List_Create(256, 10, sizeof(unsigned int));
      List_Add(yyval.l, &(yyvsp[0].u));
    ;}
    break;

  case 470:
#line 3987 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].u));
    ;}
    break;

  case 471:
#line 3994 "Gmsh.y"
    {
      yyval.c = yyvsp[0].c;
    ;}
    break;

  case 472:
#line 3998 "Gmsh.y"
    {
      yyval.c = (char *)Malloc((strlen(yyvsp[-3].c)+strlen(yyvsp[-1].c)+1)*sizeof(char));
      strcpy(yyval.c, yyvsp[-3].c);  
      strcat(yyval.c, yyvsp[-1].c);
      Free(yyvsp[-3].c);
      Free(yyvsp[-1].c);
    ;}
    break;

  case 473:
#line 4006 "Gmsh.y"
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

  case 474:
#line 4020 "Gmsh.y"
    {
      yyval.c = yyvsp[-1].c;
    ;}
    break;

  case 475:
#line 4024 "Gmsh.y"
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

  case 476:
#line 4043 "Gmsh.y"
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory(yyvsp[-3].c)))
	yymsg(GERROR, "Unknown string option class '%s'", yyvsp[-3].c);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption(yyvsp[-1].c, pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s.%s'", yyvsp[-3].c, yyvsp[-1].c);
	else{
	  char *str = pStrOpt(0, GMSH_GET, NULL);
	  yyval.c = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy(yyval.c, str);
	}
      }
    ;}
    break;

  case 477:
#line 4059 "Gmsh.y"
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory(yyvsp[-6].c)))
	yymsg(GERROR, "Unknown string option class '%s'", yyvsp[-6].c);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption(yyvsp[-1].c, pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s[%d].%s'", yyvsp[-6].c, (int)yyvsp[-4].d, yyvsp[-1].c);
	else{
	  char *str = pStrOpt((int)yyvsp[-4].d, GMSH_GET, NULL);
	  yyval.c = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy(yyval.c, str);
	}
      }
    ;}
    break;


    }

/* Line 999 of yacc.c.  */
#line 10342 "Gmsh.tab.cpp"

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
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
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


#line 4076 "Gmsh.y"


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

